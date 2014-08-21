#include <Python.h>
#include "pin.H"
#include <strings.h>
#include <stdlib.h>
#include <dlfcn.h>

PyObject* module;
PyObject** hooks_syscall_entry = NULL;
PyObject** hooks_syscall_exit = NULL;
void trace_syscall_entry(THREADID threadIndex, CONTEXT *ctxt, SYSCALL_STANDARD std, VOID *v);
void trace_syscall_exit(THREADID threadIndex, CONTEXT *ctxt, SYSCALL_STANDARD std, VOID* v);

void add_hook(PyObject*** hooks, PyObject* new_hook) {
    PyObject** hooks_list = *hooks;
    if (hooks_list == NULL) {
        hooks_list = (PyObject**) malloc(sizeof(PyObject*)*2);
        hooks_list[0] = new_hook;
        hooks_list[1] = NULL;
    } else {
        int hook_count;
        for(hook_count=0; hooks_list[hook_count]; hook_count++);
        printf("Hooks: %d\n", hook_count);
        hooks_list = (PyObject**) realloc(hooks_list, sizeof(PyObject*)*(hook_count+2));
        hooks_list[hook_count] = new_hook;
        hooks_list[hook_count+1] = NULL;
    }

    *hooks = hooks_list;
}

PyObject* Python_PIN_AddSyscallExitFunction(PyObject* self, PyObject* args) {
    PyObject* callback = (PyObject*) malloc(sizeof(PyObject));
    PyArg_ParseTuple(args, "O", &callback);

    if (!PyCallable_Check(callback)) {
        return Py_BuildValue("O", Py_False);
    }

    add_hook(&hooks_syscall_exit, callback);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_PIN_AddSyscallEntryFunction(PyObject* self, PyObject* args) {
    PyObject* callback = (PyObject*) malloc(sizeof(PyObject));
    PyArg_ParseTuple(args, "O", &callback);

    if (!PyCallable_Check(callback)) {
        return Py_BuildValue("O", Py_False);
    }

    add_hook(&hooks_syscall_entry, callback);
    return Py_BuildValue("O", Py_True);
}

static PyMethodDef methods[] = {
    {"AddSyscallEntryFunction",
        Python_PIN_AddSyscallEntryFunction,
        METH_VARARGS,
        "Register a notification function that is called immediately before execution of a system call."},
    {"AddSyscallExitFunction",
        Python_PIN_AddSyscallExitFunction,
        METH_VARARGS,
        "Register a notification function that is called immediately after execution of a system call."},
    {NULL, NULL, 0, NULL}
};

int main(int argc, char** argv) {
    Py_Initialize();
    PyRun_SimpleString("import sys; sys.path.append('.')\n");
    if (PIN_Init(argc, argv)) {
        printf("Failed to initialize pin.\n");
        exit(1);
    }

    Py_InitModule("pin", methods);
    module = PyImport_ImportModule("lel");
    if (module == NULL) {
        printf("Failed to import :{\n");
        PyErr_Print();
        exit(1);
    }

    if (hooks_syscall_entry) {
        PIN_AddSyscallEntryFunction(trace_syscall_entry, 0);
    }

    if (hooks_syscall_exit) {
        PIN_AddSyscallEntryFunction(trace_syscall_exit, 0);
    }

    PIN_StartProgram();

    Py_Finalize();
    printf("done.\n");
    return 0;
}

void trace_syscall_entry(THREADID threadIndex, CONTEXT *ctxt, SYSCALL_STANDARD std, VOID *v) {
    PyObject* syscall_num = PyInt_FromLong(PIN_GetSyscallNumber(ctxt, std));
    PyObject* syscall_args = PyTuple_New(4);
    PyTuple_SetItem(syscall_args, 0, PyInt_FromLong(PIN_GetSyscallArgument(ctxt, std, 0)));
    PyTuple_SetItem(syscall_args, 1, PyInt_FromLong(PIN_GetSyscallArgument(ctxt, std, 1)));
    PyTuple_SetItem(syscall_args, 2, PyInt_FromLong(PIN_GetSyscallArgument(ctxt, std, 2)));
    PyTuple_SetItem(syscall_args, 3, PyInt_FromLong(PIN_GetSyscallArgument(ctxt, std, 3)));

    PyObject* arguments = PyTuple_New(2);
    PyTuple_SetItem(arguments, 0, syscall_num);
    PyTuple_SetItem(arguments, 1, syscall_args);

    for (int i=0; hooks_syscall_entry[i]; i++) {
        if (PyObject_CallObject(hooks_syscall_entry[i], arguments) == NULL) {
            PyErr_Print();
            exit(1);
        }
    }
}

void trace_syscall_exit(THREADID threadIndex, CONTEXT *ctxt, SYSCALL_STANDARD std, VOID* v) {
    PyObject* return_value = PyInt_FromLong(PIN_GetSyscallReturn(ctxt, std));

    PyObject* arguments = PyTuple_New(1);
    PyTuple_SetItem(arguments, 0, return_value);

    for (int i=0; hooks_syscall_exit[i]; i++) {
        if (PyObject_CallObject(hooks_syscall_exit[i], arguments) == NULL) {
            PyErr_Print();
            exit(1);
        }
    }
}

