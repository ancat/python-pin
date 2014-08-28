import pin

def load(img):
    if pin.IMG_IsMainExecutable(img):
        print "Main executable loaded %s at %s" % (pin.IMG_Name(img), hex(pin.IMG_StartAddress(img)))
    else:
        print "Loaded %s at %s" % (pin.IMG_Name(img), hex(pin.IMG_StartAddress(img)))

def unload(img):
    print "Unloaded %s" % (pin.IMG_Name(img))

pin.IMG_AddInstrumentFunction(load)
pin.IMG_AddUnloadFunction(unload)
