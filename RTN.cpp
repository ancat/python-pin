#include </usr/include/python2.7/Python.h>
#include "pin.H"
#include "RTN.h"

PyObject* Python_RTN_InsertCall(PyObject* self, PyObject* args) {
    return Py_BuildValue("O", Py_False);
}

PyObject* Python_RTN_Next(PyObject* self, PyObject* args) {
    PyObject* x;
    PyArg_ParseTuple(args, "L", &x);
    RTN x_object = *(RTN*) x;
    RTN* rtn_return = (RTN*) malloc(sizeof(RTN));
    *rtn_return = RTN_Next(x_object);
    return Py_BuildValue("L", rtn_return);
}

PyObject* Python_RTN_Prev(PyObject* self, PyObject* args) {
    PyObject* x;
    PyArg_ParseTuple(args, "L", &x);
    RTN x_object = *(RTN*) x;
    RTN* rtn_return = (RTN*) malloc(sizeof(RTN));
    *rtn_return = RTN_Prev(x_object);
    return Py_BuildValue("L", rtn_return);
}

PyObject* Python_RTN_Invalid(PyObject* self, PyObject* args) {

    RTN* rtn_return = (RTN*) malloc(sizeof(RTN));
    *rtn_return = RTN_Invalid();
    return Py_BuildValue("L", rtn_return);
}

PyObject* Python_RTN_Valid(PyObject* self, PyObject* args) {
    PyObject* x;
    PyArg_ParseTuple(args, "L", &x);
    RTN x_object = *(RTN*) x;
    if (RTN_Valid(x_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_RTN_Name(PyObject* self, PyObject* args) {
    PyObject* x;
    PyArg_ParseTuple(args, "L", &x);
    RTN x_object = *(RTN*) x;
    return Py_BuildValue("s", RTN_Name(x_object).c_str());
}

PyObject* Python_RTN_Sym(PyObject* self, PyObject* args) {
    PyObject* x;
    PyArg_ParseTuple(args, "L", &x);
    RTN x_object = *(RTN*) x;
    SYM* sym_return = (SYM*) malloc(sizeof(SYM));
    *sym_return = RTN_Sym(x_object);
    return Py_BuildValue("L", sym_return);
}

PyObject* Python_RTN_Id(PyObject* self, PyObject* args) {
    PyObject* x;
    PyArg_ParseTuple(args, "L", &x);
    RTN x_object = *(RTN*) x;
    return Py_BuildValue("L", RTN_Id(x_object));
}

PyObject* Python_RTN_Range(PyObject* self, PyObject* args) {
    PyObject* rtn;
    PyArg_ParseTuple(args, "L", &rtn);
    RTN rtn_object = *(RTN*) rtn;
    return Py_BuildValue("L", RTN_Range(rtn_object));
}

PyObject* Python_RTN_Size(PyObject* self, PyObject* args) {
    PyObject* rtn;
    PyArg_ParseTuple(args, "L", &rtn);
    RTN rtn_object = *(RTN*) rtn;
    return Py_BuildValue("L", RTN_Size(rtn_object));
}

PyObject* Python_RTN_FindNameByAddress(PyObject* self, PyObject* args) {
    PyObject* address;
    PyArg_ParseTuple(args, "L", &address);
    ADDRINT address_object = (ADDRINT) address;
    return Py_BuildValue("s", RTN_FindNameByAddress(address_object).c_str());
}

PyObject* Python_RTN_FindByAddress(PyObject* self, PyObject* args) {
    PyObject* address;
    PyArg_ParseTuple(args, "L", &address);
    ADDRINT address_object = (ADDRINT) address;
    RTN* rtn_return = (RTN*) malloc(sizeof(RTN));
    *rtn_return = RTN_FindByAddress(address_object);
    return Py_BuildValue("L", rtn_return);
}

PyObject* Python_RTN_FindByName(PyObject* self, PyObject* args) {
    PyObject* img;
    PyObject* name;
    PyArg_ParseTuple(args, "L|O", &img, &name);
    IMG img_object = *(IMG*) img;
    char* name_object = PyString_AsString(name);
    RTN* rtn_return = (RTN*) malloc(sizeof(RTN));
    *rtn_return = RTN_FindByName(img_object, name_object);
    return Py_BuildValue("L", rtn_return);
}

PyObject* Python_RTN_Open(PyObject* self, PyObject* args) {
    PyObject* rtn;
    PyArg_ParseTuple(args, "L", &rtn);
    RTN rtn_object = *(RTN*) rtn;
    RTN_Open(rtn_object);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_RTN_Close(PyObject* self, PyObject* args) {
    PyObject* rtn;
    PyArg_ParseTuple(args, "L", &rtn);
    RTN rtn_object = *(RTN*) rtn;
    RTN_Close(rtn_object);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_RTN_InsHead(PyObject* self, PyObject* args) {
    PyObject* rtn;
    PyArg_ParseTuple(args, "L", &rtn);
    RTN rtn_object = *(RTN*) rtn;
    INS* ins_return = (INS*) malloc(sizeof(INS));
    *ins_return = RTN_InsHead(rtn_object);
    return Py_BuildValue("L", ins_return);
}

PyObject* Python_RTN_InsHeadOnly(PyObject* self, PyObject* args) {
    PyObject* rtn;
    PyArg_ParseTuple(args, "L", &rtn);
    RTN rtn_object = *(RTN*) rtn;
    INS* ins_return = (INS*) malloc(sizeof(INS));
    *ins_return = RTN_InsHeadOnly(rtn_object);
    return Py_BuildValue("L", ins_return);
}

PyObject* Python_RTN_InsTail(PyObject* self, PyObject* args) {
    PyObject* rtn;
    PyArg_ParseTuple(args, "L", &rtn);
    RTN rtn_object = *(RTN*) rtn;
    INS* ins_return = (INS*) malloc(sizeof(INS));
    *ins_return = RTN_InsTail(rtn_object);
    return Py_BuildValue("L", ins_return);
}

PyObject* Python_RTN_NumIns(PyObject* self, PyObject* args) {
    PyObject* rtn;
    PyArg_ParseTuple(args, "L", &rtn);
    RTN rtn_object = *(RTN*) rtn;
    return Py_BuildValue("L", RTN_NumIns(rtn_object));
}

PyObject* Python_RTN_Address(PyObject* self, PyObject* args) {
    PyObject* rtn;
    PyArg_ParseTuple(args, "L", &rtn);
    RTN rtn_object = *(RTN*) rtn;
    return Py_BuildValue("L", RTN_Address(rtn_object));
}

PyObject* Python_RTN_CreateAt(PyObject* self, PyObject* args) {
    PyObject* address;
    PyObject* name;
    PyArg_ParseTuple(args, "L|s", &address, &name);
    ADDRINT address_object = (ADDRINT) address;
    char* name_object = PyString_AsString(name);
    RTN* rtn_return = (RTN*) malloc(sizeof(RTN));
    *rtn_return = RTN_CreateAt(address_object, name_object);
    return Py_BuildValue("L", rtn_return);
}

PyObject* Python_RTN_IsDynamic(PyObject* self, PyObject* args) {
    PyObject* rtn;
    PyArg_ParseTuple(args, "L", &rtn);
    RTN rtn_object = *(RTN*) rtn;
    if (RTN_IsDynamic(rtn_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_RTN_IsSafeForProbedInsertion(PyObject* self, PyObject* args) {
    PyObject* rtn;
    PyArg_ParseTuple(args, "L", &rtn);
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
    PyArg_ParseTuple(args, "L|L", &rtn, &mode);
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
    PyArg_ParseTuple(args, "L", &rtn);
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
    PyArg_ParseTuple(args, "L|L", &rtn, &mode);
    RTN rtn_object = *(RTN*) rtn;
    PROBE_MODE mode_object = *(PROBE_MODE*) mode;
    if (RTN_IsSafeForProbedReplacementEx(rtn_object, mode_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

