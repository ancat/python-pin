#include </usr/include/python2.7/Python.h>
#include "pin.H"
#include "TRACE.h"

/********* TRACE STUFF ****************/

/* NEEDS MORE TESTING Compare with output from standard pin */
PyObject* Python_TRACE_Address(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);

    return Py_BuildValue("O", Py_BuildValue("L", TRACE_Address((TRACE)PyInt_AsLong(trace))));
}

/* NEEDS MORE TESTING Compare with output from standard pin */
PyObject* Python_TRACE_Original(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);

    return Py_BuildValue("L", TRACE_Original((TRACE)PyInt_AsLong(trace)));
}

/* NEEDS MORE TESTING Compare with output from standard pin */
PyObject* Python_TRACE_BblHead(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);

    TRACE* temp = (TRACE*) PyInt_AsLong(trace);
    return Py_BuildValue("L", TRACE_BblHead(*temp));
}

/* NEEDS MORE TESTING Compare with output from standard pin */
PyObject* Python_TRACE_BblTail(PyObject* self, PyObject* args) {
   PyObject* trace;
   PyArg_ParseTuple(args, "O",&trace);

   TRACE* temp = (TRACE*) PyInt_AsLong(trace);
   return Py_BuildValue("L", TRACE_BblTail(*temp));
}

/* NEEDS MORE TESTING Compare with output from standard pin */
PyObject* Python_TRACE_Size(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);
    return Py_BuildValue("L", Py_BuildValue("L", TRACE_Size((TRACE)PyInt_AsLong(trace))));
}

/* NEEDS MORE TESTING Compare with output from standard pin */
PyObject* Python_TRACE_Rtn(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);

    return Py_BuildValue("L", TRACE_Rtn((TRACE)PyInt_AsLong(trace)));
}

/* NEEDS MORE TESTING Compare with output from standard pin ***** DEFINETLY NOT ACCURATE*/
PyObject* Python_TRACE_NumBbl(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);

     return Py_BuildValue("L", TRACE_NumBbl((TRACE)PyInt_AsLong(trace)));
}

/* NEEDS MORE TESTING Compare with output from standard pin ***** DEFINETLY NOT ACCURATE*/
PyObject* Python_TRACE_NumIns(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);

    return Py_BuildValue("L", TRACE_NumIns((TRACE)PyInt_AsLong(trace)));
}

/*NOT WORKING*/
PyObject* Python_TRACE_StubSize(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);
	return Py_BuildValue("O", Py_True);//"L", Py_BuildValue("L", TRACE_StubSize((TRACE)PyInt_AsLong(trace))));
}

/* NOT WORKING */
PyObject* Python_TRACE_HasFallThrough(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);

    return Py_BuildValue("L", Py_True);
}


/* Need to figure these 3 out */
PyObject* Python_TRACE_InsertIfCall(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);
    return Py_BuildValue("O", Py_True); 
}

PyObject* Python_TRACE_InsertThenCall(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);

    return Py_BuildValue("O", Py_True); //Py_BuildValue("L", TRACE_Address((TRACE)PyInt_AsLong(trace))));
}

PyObject* Python_TRACE_InsertCall(PyObject* self, PyObject* args){
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);

    return Py_BuildValue("O", Py_True); //Py_BuildValue("L", TRACE_Address((TRACE)PyInt_AsLong(trace))));
}

/************ BBL STUFF ******************/

/*ONLY SKELETONS HERE ATM */
PyObject* Python_BBL_MoveAllAttributes(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);
    return Py_BuildValue("O", Py_True); 
}

PyObject* Python_BBL_NumIns(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);
    return Py_BuildValue("O", Py_True); 
}

PyObject* Python_BBL_InsHead(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);
    return Py_BuildValue("O", Py_True); 
}

PyObject* Python_BBL_InsTail(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);
    return Py_BuildValue("O", Py_True); 
}

PyObject* Python_BBL_Next(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);
    return Py_BuildValue("O", Py_True); 
}

PyObject* Python_BBL_Prev(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);
    return Py_BuildValue("O", Py_True); 
}

PyObject* Python_BBL_Valid(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);
    return Py_BuildValue("O", Py_True); 
}

PyObject* Python_BBL_Original(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);
    return Py_BuildValue("O", Py_True); 
}

PyObject* Python_BBL_Address(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);
    return Py_BuildValue("O", Py_True); 
}

PyObject* Python_BBL_Size(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);
    return Py_BuildValue("O", Py_True); 
}

PyObject* Python_BBL_InsertCall(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);
    return Py_BuildValue("O", Py_True); 
}

PyObject* Python_BBL_InsertIfCall(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);
    return Py_BuildValue("O", Py_True); 
}

PyObject* Python_BBL_InsertThenCall(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);
    return Py_BuildValue("O", Py_True); 
}
PyObject* Python_BBL_HasFallThrough(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);
    return Py_BuildValue("O", Py_True); 
}