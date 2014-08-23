PyObject* module;
PyObject** hooks_syscall_entry = NULL;
PyObject** hooks_syscall_exit = NULL;
void initialize_pin_module();
void hard_trace_syscall_entry(THREADID threadIndex, CONTEXT *ctxt, SYSCALL_STANDARD std, VOID *v);
void trace_syscall_entry(THREADID threadIndex, CONTEXT *ctxt, SYSCALL_STANDARD std, VOID *v);
void trace_syscall_exit(THREADID threadIndex, CONTEXT *ctxt, SYSCALL_STANDARD std, VOID* v);
PyObject* Python_PIN_AddSyscallExitFunction(PyObject* self, PyObject* args);
PyObject* Python_PIN_AddSyscallEntryFunction(PyObject* self, PyObject* args);
PyObject* Python_PIN_GetSyscallReturn(PyObject* self, PyObject* args);
PyObject* Python_PIN_GetSyscallArgument(PyObject* self, PyObject* args);
PyObject* Python_PIN_SetSyscallArgument(PyObject* self, PyObject* args);
PyObject* Python_PIN_GetSyscallNumber(PyObject* self, PyObject* args);
PyObject* Python_PIN_SetSyscallNumber(PyObject* self, PyObject* args);
PyObject* PrintString(PyObject* self, PyObject* args);

static PyMethodDef methods[] = {
    {"AddSyscallEntryFunction",
        Python_PIN_AddSyscallEntryFunction,
        METH_VARARGS,
        "Register a notification function that is called immediately before execution of a system call."},
    {"AddSyscallExitFunction",
        Python_PIN_AddSyscallExitFunction,
        METH_VARARGS,
        "Register a notification function that is called immediately after execution of a system call."},
    {"GetSyscallNumber",
        Python_PIN_GetSyscallNumber,
        METH_VARARGS,
        "Get the number (ID) of the system call to be executed in the specified context."},
    {"GetSyscallArgument",
        Python_PIN_GetSyscallArgument,
        METH_VARARGS,
        "Get the value of the argument of the system call to be executed in the specified context."},
    {"GetSyscallReturn",
        Python_PIN_GetSyscallReturn,
        METH_VARARGS,
        "Get the return value of the system call which has just returned with the specified context."},
    {"SetSyscallArgument",
        Python_PIN_SetSyscallArgument,
        METH_VARARGS,
        "Set the given value for the argument of the system call to be executed in the specified context."},
    {"SetSyscallNumber",
        Python_PIN_SetSyscallNumber,
        METH_VARARGS,
        "Set the number (ID) of the system call to be executed in the specified context."},
    {NULL, NULL, 0, NULL}
};
