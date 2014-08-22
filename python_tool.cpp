#include <Python.h>
#include "pin.H"
#include "./python_pin.h"
#include <strings.h>
#include <stdlib.h>
#include <dlfcn.h>

void add_hook(PyObject*** hooks, PyObject* new_hook) {
    PyObject** hooks_list = *hooks;
    if (hooks_list == NULL) {
        hooks_list = (PyObject**) malloc(sizeof(PyObject*)*2);
        hooks_list[0] = new_hook;
        hooks_list[1] = NULL;
    } else {
        int hook_count;
        for(hook_count=0; hooks_list[hook_count]; hook_count++);
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

PyObject* Python_PIN_GetSyscallArgument(PyObject* self, PyObject* args) {
    PyObject* context;
    PyObject* std;
    PyObject* number;
    PyArg_ParseTuple(args, "O|O|O", &context, &std, &number);

    return Py_BuildValue("I", PIN_GetSyscallArgument((CONTEXT*) *(CONTEXT**)PyInt_AsLong(context), (SYSCALL_STANDARD) *(SYSCALL_STANDARD*)PyInt_AsLong(std), (int) PyInt_AsLong(number)));
}

PyObject* Python_PIN_GetSyscallReturn(PyObject* self, PyObject* args) {
    PyObject* context;
    PyObject* std;
    PyArg_ParseTuple(args, "O|O", &context, &std);

    return Py_BuildValue("I", PIN_GetSyscallReturn((CONTEXT*) *(CONTEXT**)PyInt_AsLong(context), (SYSCALL_STANDARD) *(SYSCALL_STANDARD*)PyInt_AsLong(std)));
}

PyObject* Python_PIN_GetSyscallNumber(PyObject* self, PyObject* args) {
    PyObject* context;
    PyObject* std;
    PyArg_ParseTuple(args, "O|O", &context, &std);

    return Py_BuildValue("I", PIN_GetSyscallNumber((CONTEXT*) *(CONTEXT**)PyInt_AsLong(context), (SYSCALL_STANDARD) *(SYSCALL_STANDARD*)PyInt_AsLong(std)));
}

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
        printf("Failed to load pintool:\n");
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

void trace_syscall_exit(THREADID threadIndex, CONTEXT *ctxt, SYSCALL_STANDARD std, VOID *v) {
    PyObject* arguments = PyTuple_New(2);
    PyTuple_SetItem(arguments, 0, PyInt_FromLong((long int)&ctxt));
    PyTuple_SetItem(arguments, 1, PyInt_FromLong((long int)&std));

    for (int i=0; hooks_syscall_entry[i]; i++) {
        if (PyObject_CallObject(hooks_syscall_exit[i], arguments) == NULL) {
            PyErr_Print();
            exit(1);
        }
    }
}

void trace_syscall_entry(THREADID threadIndex, CONTEXT *ctxt, SYSCALL_STANDARD std, VOID *v) {
    PyObject* arguments = PyTuple_New(2);
    PyTuple_SetItem(arguments, 0, PyInt_FromLong((long int)&ctxt));
    PyTuple_SetItem(arguments, 1, PyInt_FromLong((long int)&std));

    for (int i=0; hooks_syscall_entry[i]; i++) {
        if (PyObject_CallObject(hooks_syscall_entry[i], arguments) == NULL) {
            PyErr_Print();
            exit(1);
        }
    }
}

