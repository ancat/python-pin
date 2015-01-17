import pin, os

logs = {}
def image_load(img):
    rtn = pin.RTN_FindByName(img, "read")
    if pin.RTN_Valid(rtn):
        print "[-] read hooked"
        pin.RTN_Open(rtn)
        pin.RTN_InsertCall(pin.IPOINT_BEFORE, "read", rtn, 3, read_pre)
        pin.RTN_InsertCall(pin.IPOINT_AFTER, "read", rtn, 3, read_post)
        pin.RTN_Close(rtn)

    rtn = pin.RTN_FindByName(img, "write")
    if pin.RTN_Valid(rtn):
        print "[-] write hooked"
        pin.RTN_Open(rtn)
        pin.RTN_InsertCall(pin.IPOINT_BEFORE, "write", rtn, 3, write_pre)
        pin.RTN_Close(rtn)


last_read_addr = 0
last_read_size = 0
last_fd = 0

everything_ever = open('everything.txt', 'w')

def read_pre(data):
    global last_read_addr, last_read_size, last_fd
    last_fd = data['arg_0']
    last_read_addr = data['arg_1']
    last_read_size = data['arg_2']

def read_post(data):
    global last_read_addr, last_read_size, last_fd, everything_ever
    if last_fd not in logs:
        logs[last_fd] = open('outputs/fd_%d_%d.txt'%(os.getpid(), last_fd), 'w')
    if last_fd in logs:
        read_data = str(pin.get_bytes(last_read_addr, last_read_size))
        read_data = read_data[:read_data.index('\x00')]
        logs[last_fd].write("%s"%(read_data))
        everything_ever.write("%s"%(read_data))

def write_pre(data):
    global everything_ever
    if data['arg_0'] not in logs:
        logs[data['arg_0']] = open('outputs/fd_%d_%d.txt'%(os.getpid(), data['arg_0']), 'w')
    if data['arg_0'] in logs:
        write_data = str(pin.get_bytes(data['arg_1'], data['arg_2']))
        logs[data['arg_0']].write("%s"%(write_data))
        everything_ever.write("%s"%(write_data))

pin.IMG_AddInstrumentFunction(image_load)
