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
    PyObject* rtn;
    PyArg_ParseTuple(args, "O", &rtn);

    RTN* temp_rtn = (RTN*) PyInt_AsLong(rtn);
    return Py_BuildValue("s", RTN_Name(*temp_rtn).c_str());
}




