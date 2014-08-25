#include </usr/include/python2.7/Python.h>
#include "pin.H"
#include "TRACE.h"

PyObject* Python_TRACE_Address(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);

    return Py_BuildValue("O", Py_BuildValue("L", TRACE_Address((TRACE)PyInt_AsLong(trace))));
}

PyObject* Python_TRACE_BblHead(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);

    TRACE* temp = (TRACE*) PyInt_AsLong(trace);
    return Py_BuildValue("L", TRACE_BblHead(*temp));
}

// PyObject* Python_BBL_Address(PyObject* self, PyObject* args) {
//     PyObject* bbl;
//     PyArg_ParseTuple(args, "O",&bbl);

//     BBL* temp = (BBL*) PyInt_AsLong(bbl);
//     return Py_BuildValue("L", BBL_Address(*temp));
// }

// PyObject* Python_BBL_NumIns(PyObject* self, PyObject* args) {
//     PyObject* bbl;
//     PyArg_ParseTuple(args, "O",&bbl);

//     return Py_BuildValue("L", Py_BuildValue("L", BBL_NumIns(PyInt_AsLong(bbl))));
// }