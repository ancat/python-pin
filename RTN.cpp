#include </usr/include/python2.7/Python.h>
#include "pin.H"

PyObject* Python_RTN_InsertCall(PyObject* self, PyObject* args) {
    /*PyObject* rtn;
    PyObject* callback;
    PyObject* action;
    PyObject* num_arguments;*/

    return Py_BuildValue("O", Py_True);
}

PyObject* Python_RTN_Name(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("s", RTN_Name(*(RTN*) ins).c_str());
}

/* VERIFIED */
PyObject* Python_RTN_Address(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "L",&trace);
    return Py_BuildValue("L", RTN_Address(*(RTN*)trace));
}

/*AUTO GENERATED SKELETONS*/
PyObject* Python_RTN_Valid(PyObject* self, PyObject* args) {
    	PyObject* trace;
    	PyArg_ParseTuple(args, "L",&trace);
    	return Py_BuildValue("L", RTN_Valid(*(RTN*)trace));
}
PyObject* Python_RTN_Id(PyObject* self, PyObject* args) {
    	PyObject* trace;
    	PyArg_ParseTuple(args, "L",&trace);
    	return Py_BuildValue("L", RTN_Id(*(RTN*)trace));
}
PyObject* Python_RTN_Range(PyObject* self, PyObject* args) {
    	PyObject* trace;
    	PyArg_ParseTuple(args, "L",&trace);
    	return Py_BuildValue("L", RTN_Range(*(RTN*)trace));
}
PyObject* Python_RTN_Size(PyObject* self, PyObject* args) {
    	PyObject* trace;
    	PyArg_ParseTuple(args, "L",&trace);
    	return Py_BuildValue("L", RTN_Size(*(RTN*)trace));
}
PyObject* Python_RTN_IsDynamic(PyObject* self, PyObject* args) {
    	PyObject* trace;
    	PyArg_ParseTuple(args, "L",&trace);
    	return Py_BuildValue("L", RTN_IsDynamic(*(RTN*)trace));
}
PyObject* Python_RTN_IsSafeForProbedInsertion(PyObject* self, PyObject* args) {
    	PyObject* trace;
    	PyArg_ParseTuple(args, "L",&trace);
    	return Py_BuildValue("L", RTN_IsSafeForProbedInsertion(*(RTN*)trace));
}
PyObject* Python_RTN_IsSafeForProbedReplacement(PyObject* self, PyObject* args) {
    	PyObject* trace;
    	PyArg_ParseTuple(args, "L",&trace);
    	return Py_BuildValue("L", RTN_IsSafeForProbedReplacement(*(RTN*)trace));
}

PyObject* Python_RTN_FindNameByAddress(PyObject* self, PyObject* args) {
    PyObject* addr;
    PyArg_ParseTuple(args, "L", &addr);
    return Py_BuildValue("s", RTN_FindNameByAddress(*(ADDRINT*) addr).c_str());
}

PyObject* Python_RTN_Open(PyObject* self, PyObject* args) {
    PyObject* addr;
    PyArg_ParseTuple(args, "L", &addr);
    RTN_Open(*(RTN*) addr);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_RTN_Close(PyObject* self, PyObject* args) {
    PyObject* addr;
    PyArg_ParseTuple(args, "L", &addr);
    RTN_Close(*(RTN*) addr);
    return Py_BuildValue("O", Py_True);
}


/*NEED TO IMPLEMENT INS FIRST */
PyObject* Python_RTN_InsHead(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O", &trace);
    INS *need  = (INS*) malloc(sizeof(INS));

    *need = RTN_InsHead(*(RTN*) PyInt_AsLong(trace));
    return Py_BuildValue("L", need); 
}

PyObject* Python_RTN_InsTail(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O", &trace);
    INS *need  = (INS*) malloc(sizeof(INS));

    *need = RTN_InsTail(*(RTN*) PyInt_AsLong(trace));
    return Py_BuildValue("L", need); 
}
PyObject* Python_RTN_NumIns(PyObject* self, PyObject* args) {
    	PyObject* trace;
    	PyArg_ParseTuple(args, "L",&trace);
    	return Py_BuildValue("L", RTN_NumIns(*(RTN*)trace));
}