import sys, pin
unistd = open("/usr/include/x86_64-linux-gnu/asm/unistd_64.h").read().split("\n")
syscalls = []
for line in unistd:
    if "define __NR" in line:
        parts = line.split(" ")
        syscalls.append(parts[1].replace("__NR_",""))

def trace_syscall_exit(ctxt, std):
    return_value = hex(pin.GetSyscallReturn(ctxt, std))
    sys.stdout.write(" = %s\n" % return_value)

def debug_entry(ctxt, std):
    global syscalls
    syscall_function = syscalls[pin.GetSyscallNumber(ctxt, std)]
    syscall_args = [hex(pin.GetSyscallArgument(ctxt, std, x)) for x in range(4)]
    sys.stdout.write("%s(%s)" % (syscall_function, ', '.join(syscall_args)))

pin.AddSyscallEntryFunction(debug_entry)
pin.AddSyscallExitFunction(trace_syscall_exit)

#TRACE TEST 
# def trace_syscall_exit(trace_addr):
# 	# Gets the base of the program trace
# 	# ctxt = pin.TRACE_BblTail(trace_addr)
# 	# Gets first basic block in the trace
# 	# sys.stdout.write("Basic Block @ %x\n" % (ctxt))#pin.bbl_addr(ctxt))
# 	sys.stdout.write("Basic Block @ %x\n" % pin.TRACE_NumIns(trace_addr))
# 	return

# pin.TRACE_AddInstrumentFunction(trace_syscall_exit)
