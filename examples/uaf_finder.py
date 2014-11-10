import pin, sys

debug = True
allocations = []
last_allocated_size = 0
log_file = open('uaf.txt', 'w')

def add_allocation(address, size):
    for allocation in allocations:
        if allocation['address'] == address:
            allocation['size'] = size
            allocation['in_use'] = True
            return

    allocations.append({"address":address, "size":size, "in_use": True})

def mark_free(address):
    global allocations
    for allocation in allocations:
        if allocation['address'] == address:
            allocation['in_use'] = False

def a_heap_thing(address):
    global allocations
    for allocation in allocations:
        if address in range(allocation['address'], allocation['address']+allocation['size']):
            return allocation

    return None

def in_use(address):
    global allocations
    for allocation in allocations:
        if allocation['address'] == address and allocation['in_use']:
            return True

    return False

def malloc_before(name, size):
    global last_allocated_size
    last_allocated_size = size

def malloc_after(name, address):
    global last_allocated_size
    if last_allocated_size == 0:
        return

    add_allocation(address, last_allocated_size)

def free(name, address):
    mark_free(address)

def handle_reads(ins_info):
    global log_file
    heap_read_addr = ins_info['MEM_OP0']
    h = a_heap_thing(heap_read_addr)
    if h and not h['in_use']:
        print "Reading a freed object"

    return

def ins_test(ins):
    if pin.INS_IsMov(ins) and pin.INS_IsMemoryRead(ins):
        pin.INS_InsertCall(pin.IPOINT_BEFORE, ins, handle_reads)

def image_load(img):
    rtn = pin.RTN_FindByName(img, "malloc")
    if pin.RTN_Valid(rtn):
        pin.RTN_Open(rtn)
        pin.RTN_InsertCall(pin.IPOINT_BEFORE, "malloc", rtn, 1, malloc_before)
        pin.RTN_InsertCall(pin.IPOINT_AFTER, "malloc", rtn, 1, malloc_after)
        pin.RTN_Close(rtn)

    rtn = pin.RTN_FindByName(img, "free")
    if pin.RTN_Valid(rtn):
        pin.RTN_Open(rtn)
        pin.RTN_InsertCall(pin.IPOINT_BEFORE, "malloc", rtn, 1, free)
        pin.RTN_Close(rtn)

def exiting():
    global allocations
    print allocations

pin.IMG_AddInstrumentFunction(image_load)
pin.INS_AddInstrumentFunction(ins_test)
pin.AddFiniFunction(exiting)

