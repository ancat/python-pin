import sys, pin
unistd = open("/usr/include/asm/unistd_64.h").read().split("\n")
syscalls = []
for line in unistd:
    if "define __NR" in line:
        parts = line.split(" ")
        syscalls.append(parts[1].replace("__NR_",""))

def trace_syscall_entry(number, arguments):
    global syscalls
    sys.stdout.write("%s(%s)"%(syscalls[number],','.join([str(hex(x)) for x in arguments])));

def trace_syscall_exit(ret):
    sys.stdout.write(" = 0x%x\n"%ret)

pin.AddSyscallEntryFunction(trace_syscall_entry)
pin.AddSyscallExitFunction(trace_syscall_exit)

