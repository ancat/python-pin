#include </usr/include/python2.7/Python.h>
#include "pin.H"
#include "TRACE.h"

/********* TRACE STUFF ****************/

/* VERIFIED */
PyObject* Python_TRACE_Address(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);
    //EACH LONG IS LIKE A DEREFERENCE SO FIRST IS AN ADDRESS TO THE ACTUAL VALUE SECOND IS THE VALUE
    return Py_BuildValue("L", Py_BuildValue("L", TRACE_Address((TRACE)PyInt_AsLong(trace))));
}

/* VERIFIED */
PyObject* Python_TRACE_Original(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);

    return Py_BuildValue("L", TRACE_Original((TRACE)PyInt_AsLong(trace)));
}

/* VERIFIED */
PyObject* Python_TRACE_BblHead(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);
    BBL *need  = (BBL*) malloc(sizeof(BBL));

    *need = TRACE_BblHead(*(TRACE*) PyInt_AsLong(trace));
    return Py_BuildValue("L", need);
}

/* VERIFIED */
PyObject* Python_TRACE_BblTail(PyObject* self, PyObject* args) {
   PyObject* trace;
   PyArg_ParseTuple(args, "O",&trace);
   BBL *need  = (BBL*) malloc(sizeof(BBL));

   *need = TRACE_BblTail(*(TRACE*) PyInt_AsLong(trace));
   return Py_BuildValue("L", need);
}

/* VERIFIED */
PyObject* Python_TRACE_Size(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O", &trace);

    return Py_BuildValue("L", TRACE_Size(*(TRACE*)PyInt_AsLong(trace)));
}

/* NEEDS TESTING IN RTN CLASS*/
PyObject* Python_TRACE_Rtn(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);
    RTN *rtn  = (RTN*) malloc(sizeof(RTN));

    *rtn =  TRACE_Rtn(*(TRACE*)PyInt_AsLong(trace));
    return Py_BuildValue("L", rtn);
}

/* VERIFIED */
PyObject* Python_TRACE_NumBbl(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);

     return Py_BuildValue("L", TRACE_NumBbl(*(TRACE*)PyInt_AsLong(trace)));
}

/* VERIFIED */
PyObject* Python_TRACE_NumIns(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);

    return Py_BuildValue("L", TRACE_NumIns(*(TRACE*)PyInt_AsLong(trace)));
}

/* VERIFIED */
PyObject* Python_TRACE_StubSize(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);
	return Py_BuildValue("L", TRACE_StubSize(*(TRACE*)PyInt_AsLong(trace)));
}

/* NVERIFIED */
PyObject* Python_TRACE_HasFallThrough(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);

    return Py_BuildValue("L", TRACE_HasFallThrough(*(TRACE*)PyInt_AsLong(trace)));
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

/* NOT WORKING */
PyObject* Python_BBL_MoveAllAttributes(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);
    return Py_BuildValue("O", Py_True); 
}

/* VERIFIED */
PyObject* Python_BBL_NumIns(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "L",&trace);
    return Py_BuildValue("L", BBL_NumIns(*(BBL*)trace)); 
}

/* VERIFIED */
PyObject* Python_BBL_HasFallThrough(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "L",&trace);
    return Py_BuildValue("L", BBL_HasFallThrough(*(BBL*)trace)); 
}

/*NEED TO IMPLEMENT INS FIRST */
PyObject* Python_BBL_InsHead(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);
    return Py_BuildValue("O", Py_True); 
}
/* NOT WORKING */
PyObject* Python_BBL_InsTail(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);
    return Py_BuildValue("O", Py_True); 
}

/* NOT WORKING */
PyObject* Python_BBL_Next(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);
    return Py_BuildValue("O", Py_True); 
}

/* NOT WORKING */
PyObject* Python_BBL_Prev(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "O",&trace);//BBL_INVALID() 
    return Py_BuildValue("O", Py_True);//BBL_IN); 
}

/* VERIFIED */
PyObject* Python_BBL_Valid(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "L",&trace);
    return Py_BuildValue("L", BBL_Valid(*(BBL*)trace));
}

/* VERIFIED */
PyObject* Python_BBL_Original(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "L",&trace);
    return Py_BuildValue("L", BBL_Original(*(BBL*)trace));
}

/* VERIFIED */
PyObject* Python_BBL_Address(PyObject* self, PyObject* args) {
    PyObject* trace;
    PyArg_ParseTuple(args, "L",&trace);
    return Py_BuildValue("L", BBL_Address(*(BBL*)trace));
}

/* VERIFIED */
PyObject* Python_BBL_Size(PyObject* self, PyObject* args) {
    PyObject* trace;
     PyArg_ParseTuple(args, "L",&trace);
    return Py_BuildValue("L", BBL_Size(*(BBL*)trace));
}

/* NOT IMPLEMENTED  */
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
