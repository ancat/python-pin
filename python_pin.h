PyObject* module;
PyObject** hooks_syscall_entry = NULL;
PyObject** hooks_syscall_exit = NULL;
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
        "Not sure yet"},
    {"GetSyscallArgument",
        Python_PIN_GetSyscallArgument,
        METH_VARARGS,
        "Not sure yet"},
    {"GetSyscallReturn",
        Python_PIN_GetSyscallReturn,
        METH_VARARGS,
        "Not sure yet"},
    {NULL, NULL, 0, NULL}
};
