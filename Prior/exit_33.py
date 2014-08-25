# If anything ever tries to read anything, turn it into an exit(33) syscall
import pin

def exit_33(ctxt, std):
    if pin.GetSyscallNumber(ctxt, std) == 1:
        pin.SetSyscallNumber(ctxt, std, 60);
        pin.SetSyscallArgument(ctxt, std, 0, 33)

pin.AddSyscallEntryFunction(exit_33)

