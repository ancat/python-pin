#include </usr/include/python2.7/Python.h>
#include "pin.H"
#include "RTN.h"

void RTN_IPOINT_AFTER(char* name, PyObject* callback, long int return_value) {
    PyObject* arguments = PyTuple_New(2);
    PyTuple_SetItem(arguments, 0, PyString_FromString(name));
    PyTuple_SetItem(arguments, 1, PyInt_FromLong(return_value));

    PyObject_CallObject(callback, arguments);
}

void RTN_IPOINT_BEFORE(char* name, int num_args, PyObject* callback, long int arg0, long int arg1, long int arg2, long int arg3, long int arg4, long int arg5, long int arg6, long int arg7, long int arg8, long int arg9, long int arg10) {
    PyObject* arguments = PyTuple_New(num_args+1);
    PyTuple_SetItem(arguments, 0, PyString_FromString(name));
    long int args[11];
    args[0] = arg0;
    args[1] = arg1;
    args[2] = arg2;
    args[3] = arg3;
    args[4] = arg4;
    args[5] = arg5;
    args[6] = arg6;
    args[7] = arg7;
    args[8] = arg8;
    args[9] = arg9;
    args[10] = arg10;

    for (int i=0; i < num_args; i++) {
        PyTuple_SetItem(arguments, i+1, PyInt_FromLong(args[i]));
    }

    PyObject_CallObject(callback, arguments);
}

PyObject* Python_RTN_InsertCall(PyObject* self, PyObject* args) {
    PyObject* num_args;
    PyObject* function_name;
    PyObject* rtn;
    PyObject* callable;
    PyObject* ipoint;

    PyArg_ParseTuple(args, "k|O|k|k|O", &ipoint, &function_name, &rtn, &num_args, &callable);
    if (!PyCallable_Check(callable) || (long int) num_args > 10 || (long int) num_args < 0) {
        return Py_BuildValue("O", Py_False);
    }

    RTN rtn_object = *(RTN*) rtn;
    if ((long int) ipoint == IPOINT_AFTER) {
        RTN_InsertCall(rtn_object, IPOINT_AFTER, (AFUNPTR) RTN_IPOINT_AFTER,
            IARG_ADDRINT, PyString_AsString(function_name),
            IARG_PTR, callable,
            IARG_FUNCRET_EXITPOINT_VALUE, IARG_END);
    } else if ((long int) ipoint == IPOINT_BEFORE) {
        RTN_InsertCall(rtn_object, IPOINT_BEFORE, (AFUNPTR) RTN_IPOINT_BEFORE,
            IARG_ADDRINT, PyString_AsString(function_name),
            IARG_ADDRINT, num_args,
            IARG_PTR, callable,
            IARG_FUNCARG_ENTRYPOINT_VALUE, 0,
            IARG_FUNCARG_ENTRYPOINT_VALUE, 1,
            IARG_FUNCARG_ENTRYPOINT_VALUE, 2,
            IARG_FUNCARG_ENTRYPOINT_VALUE, 3,
            IARG_FUNCARG_ENTRYPOINT_VALUE, 4,
            IARG_FUNCARG_ENTRYPOINT_VALUE, 5,
            IARG_FUNCARG_ENTRYPOINT_VALUE, 6,
            IARG_FUNCARG_ENTRYPOINT_VALUE, 7,
            IARG_FUNCARG_ENTRYPOINT_VALUE, 8,
            IARG_FUNCARG_ENTRYPOINT_VALUE, 9,
            IARG_FUNCARG_ENTRYPOINT_VALUE, 10,
            IARG_END);
    } else {
        return Py_BuildValue("O", Py_False);
    }

    return Py_BuildValue("O", Py_True);
/*
    for (int i=0; i < PyTuple_Size(args); i++) {
        cur = PyTuple_GetItem(args, i);
        if (PyString_Check(cur)) {
            printf("[str] %s\n", PyString_AsString(cur));
        } else if (PyInt_Check(cur)) {
            printf("[int] %ld\n", PyInt_AsLong(cur));
        }
    }

    return Py_BuildValue("O", Py_False);*/
}

PyObject* Python_RTN_Next(PyObject* self, PyObject* args) {
    PyObject* x;
    PyArg_ParseTuple(args, "k", &x);
    RTN x_object = *(RTN*) x;
    RTN* rtn_return = (RTN*) malloc(sizeof(RTN));
    *rtn_return = RTN_Next(x_object);
    return Py_BuildValue("k", rtn_return);
}

PyObject* Python_RTN_Prev(PyObject* self, PyObject* args) {
    PyObject* x;
    PyArg_ParseTuple(args, "k", &x);
    RTN x_object = *(RTN*) x;
    RTN* rtn_return = (RTN*) malloc(sizeof(RTN));
    *rtn_return = RTN_Prev(x_object);
    return Py_BuildValue("k", rtn_return);
}

PyObject* Python_RTN_Invalid(PyObject* self, PyObject* args) {
    RTN* rtn_return = (RTN*) malloc(sizeof(RTN));
    *rtn_return = RTN_Invalid();
    return Py_BuildValue("k", rtn_return);
}

PyObject* Python_RTN_Valid(PyObject* self, PyObject* args) {
    PyObject* x;
    PyArg_ParseTuple(args, "k", &x);
    RTN x_object = *(RTN*) x;
    if (RTN_Valid(x_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_RTN_Name(PyObject* self, PyObject* args) {
    PyObject* x;
    PyArg_ParseTuple(args, "k", &x);
    RTN x_object = *(RTN*) x;
    return Py_BuildValue("s", RTN_Name(x_object).c_str());
}

PyObject* Python_RTN_Sym(PyObject* self, PyObject* args) {
    PyObject* x;
    PyArg_ParseTuple(args, "k", &x);
    RTN x_object = *(RTN*) x;
    SYM* sym_return = (SYM*) malloc(sizeof(SYM));
    *sym_return = RTN_Sym(x_object);
    return Py_BuildValue("k", sym_return);
}

PyObject* Python_RTN_Id(PyObject* self, PyObject* args) {
    PyObject* x;
    PyArg_ParseTuple(args, "k", &x);
    RTN x_object = *(RTN*) x;
    return Py_BuildValue("k", RTN_Id(x_object));
}

PyObject* Python_RTN_Range(PyObject* self, PyObject* args) {
    PyObject* rtn;
    PyArg_ParseTuple(args, "k", &rtn);
    RTN rtn_object = *(RTN*) rtn;
    return Py_BuildValue("k", RTN_Range(rtn_object));
}

PyObject* Python_RTN_Size(PyObject* self, PyObject* args) {
    PyObject* rtn;
    PyArg_ParseTuple(args, "k", &rtn);
    RTN rtn_object = *(RTN*) rtn;
    return Py_BuildValue("k", RTN_Size(rtn_object));
}

PyObject* Python_RTN_FindNameByAddress(PyObject* self, PyObject* args) {
    PyObject* address;
    PyArg_ParseTuple(args, "k", &address);
    ADDRINT address_object = (ADDRINT) address;
    return Py_BuildValue("s", RTN_FindNameByAddress(address_object).c_str());
}

PyObject* Python_RTN_FindByAddress(PyObject* self, PyObject* args) {
    PyObject* address;
    PyArg_ParseTuple(args, "k", &address);
    ADDRINT address_object = (ADDRINT) address;
    RTN* rtn_return = (RTN*) malloc(sizeof(RTN));
    *rtn_return = RTN_FindByAddress(address_object);
    return Py_BuildValue("k", rtn_return);
}

PyObject* Python_RTN_FindByName(PyObject* self, PyObject* args) {
    PyObject* img;
    PyObject* name;
    PyArg_ParseTuple(args, "k|O", &img, &name);
    IMG img_object = *(IMG*) img;
    char* name_object = PyString_AsString(name);
    RTN* rtn_return = (RTN*) malloc(sizeof(RTN));
    *rtn_return = RTN_FindByName(img_object, name_object);
    return Py_BuildValue("k", rtn_return);
}

PyObject* Python_RTN_Open(PyObject* self, PyObject* args) {
    PyObject* rtn;
    PyArg_ParseTuple(args, "k", &rtn);
    RTN rtn_object = *(RTN*) rtn;
    RTN_Open(rtn_object);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_RTN_Close(PyObject* self, PyObject* args) {
    PyObject* rtn;
    PyArg_ParseTuple(args, "k", &rtn);
    RTN rtn_object = *(RTN*) rtn;
    RTN_Close(rtn_object);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_RTN_InsHead(PyObject* self, PyObject* args) {
    PyObject* rtn;
    PyArg_ParseTuple(args, "k", &rtn);
    RTN rtn_object = *(RTN*) rtn;
    INS* ins_return = (INS*) malloc(sizeof(INS));
    *ins_return = RTN_InsHead(rtn_object);
    return Py_BuildValue("k", ins_return);
}

PyObject* Python_RTN_InsHeadOnly(PyObject* self, PyObject* args) {
    PyObject* rtn;
    PyArg_ParseTuple(args, "k", &rtn);
    RTN rtn_object = *(RTN*) rtn;
    INS* ins_return = (INS*) malloc(sizeof(INS));
    *ins_return = RTN_InsHeadOnly(rtn_object);
    return Py_BuildValue("k", ins_return);
}

PyObject* Python_RTN_InsTail(PyObject* self, PyObject* args) {
    PyObject* rtn;
    PyArg_ParseTuple(args, "k", &rtn);
    RTN rtn_object = *(RTN*) rtn;
    INS* ins_return = (INS*) malloc(sizeof(INS));
    *ins_return = RTN_InsTail(rtn_object);
    return Py_BuildValue("k", ins_return);
}

PyObject* Python_RTN_NumIns(PyObject* self, PyObject* args) {
    PyObject* rtn;
    PyArg_ParseTuple(args, "k", &rtn);
    RTN rtn_object = *(RTN*) rtn;
    return Py_BuildValue("k", RTN_NumIns(rtn_object));
}

PyObject* Python_RTN_Address(PyObject* self, PyObject* args) {
    PyObject* rtn;
    PyArg_ParseTuple(args, "k", &rtn);
    RTN rtn_object = *(RTN*) rtn;
    return Py_BuildValue("k", RTN_Address(rtn_object));
}

PyObject* Python_RTN_CreateAt(PyObject* self, PyObject* args) {
    PyObject* address;
    PyObject* name;
    PyArg_ParseTuple(args, "k|s", &address, &name);
    ADDRINT address_object = (ADDRINT) address;
    char* name_object = PyString_AsString(name);
    RTN* rtn_return = (RTN*) malloc(sizeof(RTN));
    *rtn_return = RTN_CreateAt(address_object, name_object);
    return Py_BuildValue("k", rtn_return);
}

PyObject* Python_RTN_IsDynamic(PyObject* self, PyObject* args) {
    PyObject* rtn;
    PyArg_ParseTuple(args, "k", &rtn);
    RTN rtn_object = *(RTN*) rtn;
    if (RTN_IsDynamic(rtn_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_RTN_IsSafeForProbedInsertion(PyObject* self, PyObject* args) {
    PyObject* rtn;
    PyArg_ParseTuple(args, "k", &rtn);
    RTN rtn_object = *(RTN*) rtn;
    if (RTN_IsSafeForProbedInsertion(rtn_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_RTN_IsSafeForProbedInsertionEx(PyObject* self, PyObject* args) {
    PyObject* rtn;
    PyObject* mode;
    PyArg_ParseTuple(args, "k|k", &rtn, &mode);
    RTN rtn_object = *(RTN*) rtn;
    PROBE_MODE mode_object = *(PROBE_MODE*) mode;
    if (RTN_IsSafeForProbedInsertionEx(rtn_object, mode_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_RTN_IsSafeForProbedReplacement(PyObject* self, PyObject* args) {
    PyObject* rtn;
    PyArg_ParseTuple(args, "k", &rtn);
    RTN rtn_object = *(RTN*) rtn;
    if (RTN_IsSafeForProbedReplacement(rtn_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_RTN_IsSafeForProbedReplacementEx(PyObject* self, PyObject* args) {
    PyObject* rtn;
    PyObject* mode;
    PyArg_ParseTuple(args, "k|k", &rtn, &mode);
    RTN rtn_object = *(RTN*) rtn;
    PROBE_MODE mode_object = *(PROBE_MODE*) mode;
    if (RTN_IsSafeForProbedReplacementEx(rtn_object, mode_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

