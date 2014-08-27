#include </usr/include/python2.7/Python.h>
#include "pin.H"
#include "INS.h"


/**** INS REPRESENTATION FUNCTIONS *****/
/*AUTO GENERATED SKELETONS*/
PyObject* Python_INS_Category(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_Extension(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_MemoryOperandSize(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_MemoryWriteSize(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_GetPredicate(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_MemoryReadSize(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_IsMemoryRead(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_IsMemoryWrite(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_HasMemoryRead2(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_HasFallThrough(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_IsLea(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_IsNop(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_OPCODE_StringShort(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_Mnemonic(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_IsBranch(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_IsDirectBranch(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_IsDirectCall(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_IsDirectBranchOrCall(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_IsBranchOrCall(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_Stutters(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_IsCall(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_IsProcedureCall(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_IsRet(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_IsSysret(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_IsPrefetch(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_IsAtomicUpdate(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_IsIndirectBranchOrCall(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_RegR(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_RegW(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_Opcode(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_CATEGORY_StringShort(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_EXTENSION_StringShort(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_MaxNumRRe(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_MaxNumWRe(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_RegRContain(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_RegWContain(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_IsStackRead (PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_IsStackWrite (PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_IsIpRelRead(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_IsIpRelWrite (PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_IsPredicated(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_IsOriginal(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_Disassemble(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_MemoryOperandCount(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_OperandIsAddressGenerator(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_MemoryOperandIsRead(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_MemoryOperandIsWritten(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_IsSyscall (PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_SyscallStd(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_Rtn(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_Next(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_Prev(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_Invalid (PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_Valid(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_Address(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_Size(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_DirectBranchOrCallTargetAddress(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
PyObject* Python_INS_NextAddress(PyObject* self, PyObject* args){   PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("O", Py_True);
}
