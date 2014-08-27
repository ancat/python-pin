#include <Python.h>
//#include </usr/include/python2.7/Python.h>
#include "pin.H"
#include "IMG.h"
#include "RTN.h"
#include "SYS.h"
#include "TRACE.h"
#include "./python_pin.h"
#include <strings.h>
#include <stdlib.h>


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


PyObject* Python_TRACE_AddInstrumentFunction(PyObject* self, PyObject* args) {
    PyObject* callback;
    PyObject* v;
    PyArg_ParseTuple(args, "O|O", &callback, &v);

    if (!PyCallable_Check(callback)) {
        return Py_BuildValue("O", Py_False);
    }

    add_hook(&hooks_trace_instrument, callback);
    return Py_BuildValue("O", Py_True);
} 

PyObject* Python_IMG_AddInstrumentFunction(PyObject* self, PyObject* args) {
    PyObject* callback;
    PyObject* v;
    PyArg_ParseTuple(args, "O|O", &callback, &v);

    if (!PyCallable_Check(callback)) {
        return Py_BuildValue("O", Py_False);
    }

    add_hook(&hooks_img_load, callback);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_AddUnloadFunction(PyObject* self, PyObject* args) {
    PyObject* callback;
    PyObject* v;
    PyArg_ParseTuple(args, "O|O", &callback, &v);

    if (!PyCallable_Check(callback)) {
        return Py_BuildValue("O", Py_False);
    }

    add_hook(&hooks_img_unload, callback);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_RTN_AddInstrumentFunction(PyObject* self, PyObject* args) {
    PyObject* callback = (PyObject*) malloc(sizeof(PyObject));
    PyArg_ParseTuple(args, "O", &callback);

    if (!PyCallable_Check(callback)) {
        return Py_BuildValue("O", Py_False);
    }

    add_hook(&hooks_instrument_function, callback);
    return Py_BuildValue("O", Py_True);
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


KNOB<string> KnobPythonModule(KNOB_MODE_WRITEONCE, "pintool", "m", "", "the python pintool to import");
int main(int argc, char** argv) {
    Py_Initialize();
    PyRun_SimpleString("import sys; sys.path.append('.')\n");
    if (PIN_Init(argc, argv)) {
        printf("Failed to initialize pin.\n");
        exit(1);
    }

    PyObject* pin_module = Py_InitModule("pin", methods);
    if (pin_module == NULL) {
        printf("Failed to initialize internal pin module\n");
        PyErr_Print();
        exit(1);
    }

    PyModule_AddIntConstant(pin_module, "IPOINT_BEFORE", IPOINT_BEFORE);
    PyModule_AddIntConstant(pin_module, "IPOINT_AFTER", IPOINT_AFTER);

    const char* filename = KnobPythonModule.Value().c_str();
    FILE* tool = fopen(filename, "r");
    if (tool == NULL) {
        perror("fopen");
        exit(1);
    }

    PyRun_SimpleFile(tool, filename);
    fclose(tool);

    if (hooks_syscall_entry) {
        PIN_AddSyscallEntryFunction(SyscallEntry, 0);
    }

    if (hooks_syscall_exit) {
        PIN_AddSyscallEntryFunction(SyscallExit, 0);
    }

    if (hooks_instrument_function) {
        RTN_AddInstrumentFunction(InstrumentFunction, 0);
    }

    if (hooks_img_load) {
        IMG_AddInstrumentFunction(ImageLoad, 0);
    }

    if (hooks_img_unload) {
        IMG_AddUnloadFunction(ImageUnload, 0);
    }

    if (hooks_trace_instrument) {
        TRACE_AddInstrumentFunction(Trace, 0);
    }

    PIN_StartProgram();

    Py_Finalize();
    return 0;
}

void Trace(TRACE trace, VOID *v){
    PyObject* arguments = PyTuple_New(1);
    PyTuple_SetItem(arguments, 0, PyInt_FromLong((long int)&trace));

    for (int i=0; hooks_trace_instrument[i]; i++) {
        if (PyObject_CallObject(hooks_trace_instrument[i], arguments) == NULL) {
            PyErr_Print();
            exit(1);
        }
    }
    return;
}

void InstrumentFunction(RTN rtn, VOID *v) {
    PyObject* arguments = PyTuple_New(1);
    PyTuple_SetItem(arguments, 0, PyInt_FromLong((long int)&rtn));

    for (int i=0; hooks_instrument_function[i]; i++) {
        if (PyObject_CallObject(hooks_instrument_function[i], arguments) == NULL) {
            PyErr_Print();
            exit(1);
        }
    }
}

void SyscallExit(THREADID threadIndex, CONTEXT *ctxt, SYSCALL_STANDARD std, VOID *v) {
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

void SyscallEntry(THREADID threadIndex, CONTEXT *ctxt, SYSCALL_STANDARD std, VOID *v) {
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

void ImageLoad(IMG img, VOID *v) {
    PyObject* arguments = PyTuple_New(1);
    PyTuple_SetItem(arguments, 0, PyInt_FromLong((long int)&img));

    for (int i=0; hooks_img_load[i]; i++) {
        if (PyObject_CallObject(hooks_img_load[i], arguments) == NULL) {
            PyErr_Print();
            exit(1);
        }
    }
}

void ImageUnload(IMG img, VOID* v) {
    PyObject* arguments = PyTuple_New(1);
    PyTuple_SetItem(arguments, 0, PyInt_FromLong((long int)&img));

    for (int i=0; hooks_img_unload[i]; i++) {
        if (PyObject_CallObject(hooks_img_unload[i], arguments) == NULL) {
            PyErr_Print();
            exit(1);
        }
    }
}
