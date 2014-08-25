#include <Python.h>
#include "pin.H"
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

PyObject* Python_RTN_InsertCall(PyObject* self, PyObject* args) {
    /*PyObject* rtn;
    PyObject* callback;
    PyObject* action;
    PyObject* num_arguments;*/

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

PyObject* Python_RTN_Name(PyObject* self, PyObject* args) {
    PyObject* rtn;
    PyArg_ParseTuple(args, "O", &rtn);

    RTN* temp_rtn = (RTN*) PyInt_AsLong(rtn);
    return Py_BuildValue("s", RTN_Name(*temp_rtn).c_str());
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

    return Py_BuildValue("L", PIN_GetSyscallArgument((CONTEXT*) *(CONTEXT**)PyInt_AsLong(context), (SYSCALL_STANDARD) *(SYSCALL_STANDARD*)PyInt_AsLong(std), (int) PyInt_AsLong(number)));
}

PyObject* Python_PIN_GetSyscallReturn(PyObject* self, PyObject* args) {
    PyObject* context;
    PyObject* std;
    PyArg_ParseTuple(args, "O|O", &context, &std);

    return Py_BuildValue("L", PIN_GetSyscallReturn((CONTEXT*) *(CONTEXT**)PyInt_AsLong(context), (SYSCALL_STANDARD) *(SYSCALL_STANDARD*)PyInt_AsLong(std)));
}

PyObject* Python_PIN_GetSyscallNumber(PyObject* self, PyObject* args) {
    PyObject* context;
    PyObject* std;
    PyArg_ParseTuple(args, "O|O", &context, &std);

    return Py_BuildValue("L", PIN_GetSyscallNumber((CONTEXT*) *(CONTEXT**)PyInt_AsLong(context), (SYSCALL_STANDARD) *(SYSCALL_STANDARD*)PyInt_AsLong(std)));
}

PyObject* Python_PIN_SetSyscallArgument(PyObject* self, PyObject* args) {
    PyObject* context;
    PyObject* std;
    PyObject* number;
    PyObject* value;
    PyArg_ParseTuple(args, "O|O|O|O", &context, &std, &number, &value);

    PIN_SetSyscallArgument((CONTEXT*) *(CONTEXT**)PyInt_AsLong(context), (SYSCALL_STANDARD) *(SYSCALL_STANDARD*)PyInt_AsLong(std), (int) PyInt_AsLong(number), (ADDRINT) PyInt_AsLong(value));
    return Py_BuildValue("O", Py_None);
}

PyObject* Python_PIN_SetSyscallNumber(PyObject* self, PyObject* args) {
    PyObject* context;
    PyObject* std;
    PyObject* value;
    PyArg_ParseTuple(args, "O|O|O", &context, &std, &value);

    PIN_SetSyscallNumber((CONTEXT*) *(CONTEXT**)PyInt_AsLong(context), (SYSCALL_STANDARD) *(SYSCALL_STANDARD*)PyInt_AsLong(std), (ADDRINT) PyInt_AsLong(value));
    return Py_BuildValue("O", Py_None);
}

// ------------------- auto generated
PyObject* Python_IMG_Next(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    // IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_Prev(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    // IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_Invalid(PyObject* self, PyObject* args) {
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_Valid(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    // IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_SecHead(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    // IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_SecTail(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    // IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_RegsymHead(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    // IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_Entry(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    // IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_Name(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("s", IMG_Name(img_object).c_str());
}

PyObject* Python_IMG_Gp(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    // IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_LoadOffset(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    // IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_LowAddress(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    // IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_HighAddress(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    // IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_StartAddress(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    // IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_SizeMapped(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    // IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_Type(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    // IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_IsMainExecutable(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    // IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_Id(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    // IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_FindImgById(PyObject* self, PyObject* args) {
    PyObject* id;
    PyArg_ParseTuple(args, "O", &id);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_FindByAddress(PyObject* self, PyObject* args) {
    PyObject* address;
    PyArg_ParseTuple(args, "O", &address);
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

PyObject* Python_IMG_Open(PyObject* self, PyObject* args) {
    PyObject* filename;
    PyArg_ParseTuple(args, "O", &filename);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_Close(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    // IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_APP_ImgHead(PyObject* self, PyObject* args) {
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_APP_ImgTail(PyObject* self, PyObject* args) {
    return Py_BuildValue("O", Py_True);
}

// ------------------- auto generated

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

    module = PyImport_ImportModule("lel");
    if (module == NULL) {
        printf("Failed to load pintool:\n");
        PyErr_Print();
        exit(1);
    }

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

    PIN_StartProgram();

    Py_Finalize();
    return 0;
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
