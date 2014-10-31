import sys, pin
total = 0
info = file("instruc", "w")

#map the text segment of an executable
def map(ins_addr):
	x = pin.INS_Address(ins_addr)
	if x < 0x904b794:
		info.write("%d\n" % (x))


pin.INS_AddInstrumentFunction(map)
