import pin, sys

debug = True
allocations = []
last_allocated_size = 0
hit = 1
real = 0
guard_size = 32
new_size = 0
log_file = open('uaf.txt', 'w')
canary = 0x4141414141414141

def malloc_before(everything):
    global last_allocated_size
    last_allocated_size = everything['arg_0']
    # print "MALLOCING: " + hex(everything['arg_0'])
    new_size = guard_size*2+last_allocated_size
    pin.set_pointer(everything['reg_gdi'], pin.get_pointer(everything['reg_gdi'])+guard_size*2)

def malloc_after(everything):
    global last_allocated_size
    address = everything['return']
    # print "MALLOC " + hex((pin.get_pointer(everything['reg_gax'])))
    pin.set_pointer((pin.get_pointer(everything['reg_gax'])), canary)
    pin.set_pointer(pin.get_pointer(everything['reg_gax'])+8, canary)
    pin.set_pointer(pin.get_pointer(everything['reg_gax'])+16, canary)
    pin.set_pointer(pin.get_pointer(everything['reg_gax'])+24, canary)
    pin.set_pointer((pin.get_pointer(everything['reg_gax'])+last_allocated_size+32), canary)
    pin.set_pointer(pin.get_pointer(everything['reg_gax'])+8+last_allocated_size+32, canary)
    pin.set_pointer(pin.get_pointer(everything['reg_gax'])+16+last_allocated_size+32, canary)
    pin.set_pointer(pin.get_pointer(everything['reg_gax'])+24+last_allocated_size+32, canary)

    pin.set_pointer(everything['reg_gax'], pin.get_pointer(everything['reg_gax'])+32)
    
    # print "POST MALLOC"
    # print "gax:%x;gbx:%x;gcx:%x;gdx:%x"%(everything['reg_gax'], everything['reg_gbx'], everything['reg_gcx'], everything['reg_gdx'])

def free(everything):
    print "FREEING: " + hex(everything['arg_0'])
    pin.set_pointer(everything['reg_gdi'], 0)
    # mark_free(everything['arg_0'])

def realloc_before(everything):
    global last_allocated_size
    global hit, real
    if hit == 1:
        hit = 0
    else:
        print "realloc before"
        name = hex(pin.get_pointer(everything["reg_gdi"]))
        size = hex(pin.get_pointer(everything["reg_gsi"]))
        print name
        print size
        if(size == 0):
            pin.set_pointer(everything['reg_gdi'], 0)
            pin.set_pointer(everything['reg_gsi'], 0)
        elif(name == 0):
            return
        else:
            print "HITTING "
            last_allocated_size = everything['arg_1']
            pin.set_pointer(everything['reg_gsi'], pin.get_pointer(everything['reg_gsi'])+guard_size*2)
            pin.set_pointer(everything['reg_gdi'], pin.get_pointer(everything['reg_gdi'])-guard_size)
            real = 1
        hit = 1




def realloc_after(everything):
    global real
    if real == 1:
        print "realloc after"
        pin.set_pointer((pin.get_pointer(everything['reg_gax'])), canary)
        pin.set_pointer(pin.get_pointer(everything['reg_gax'])+8, canary)
        pin.set_pointer(pin.get_pointer(everything['reg_gax'])+16, canary)
        pin.set_pointer(pin.get_pointer(everything['reg_gax'])+24, canary)
        pin.set_pointer((pin.get_pointer(everything['reg_gax'])+last_allocated_size+32), canary)
        pin.set_pointer(pin.get_pointer(everything['reg_gax'])+8+last_allocated_size+32, canary)
        pin.set_pointer(pin.get_pointer(everything['reg_gax'])+16+last_allocated_size+32, canary)
        pin.set_pointer(pin.get_pointer(everything['reg_gax'])+24+last_allocated_size+32, canary)
        pin.set_pointer(everything['reg_gax'], pin.get_pointer(everything['reg_gax'])+32)
    real = 0

def handle_write(ins_info):
    heap_read_addr = ins_info['MEM_OP0']
    # print "UAF located at 0x%x [%s]" % (heap_read_addr, ins_info['mnemonic'])
    #x = pin.set_pointer(pin.get_pointer(heap_read_addr), 0)
######
# NEED to dereference heap write and compare it to the canary value here
# this is what is needed in C++
# *(ADDRINT*)memOp == canary || *(ADDRINT*)memOp == canary2
#####
def ins_test(ins):
    if pin.INS_IsMemoryWrite(ins):
        pin.INS_InsertCall(pin.IPOINT_BEFORE, ins, handle_write)

def image_load(img):
    rtn = pin.RTN_FindByName(img, "realloc")
    if pin.RTN_Valid(rtn):
        pin.RTN_Open(rtn)
        pin.RTN_InsertCall(pin.IPOINT_BEFORE, "realloc", rtn, 3, realloc_before)
        pin.RTN_InsertCall(pin.IPOINT_AFTER, "realloc", rtn, 3, realloc_after)
        pin.RTN_Close(rtn)

    rtn = pin.RTN_FindByName(img, "malloc")
    if pin.RTN_Valid(rtn):
        pin.RTN_Open(rtn)
        pin.RTN_InsertCall(pin.IPOINT_BEFORE, "malloc", rtn, 1, malloc_before)
        pin.RTN_InsertCall(pin.IPOINT_AFTER, "malloc", rtn, 1, malloc_after)
        pin.RTN_Close(rtn)

    rtn = pin.RTN_FindByName(img, "free")
    if pin.RTN_Valid(rtn):
        pin.RTN_Open(rtn)
        pin.RTN_InsertCall(pin.IPOINT_BEFORE, "free", rtn, 1, free)
        pin.RTN_Close(rtn)

def exiting():
    global allocations

pin.IMG_AddInstrumentFunction(image_load)
pin.INS_AddInstrumentFunction(ins_test)
pin.AddFiniFunction(exiting)