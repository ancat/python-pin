#include </usr/include/python2.7/Python.h>
#include "pin.H"
#include "INS.h"


/**** INS REPRESENTATION FUNCTIONS *****/
/*AUTO GENERATED SKELETONS*/
PyObject* Python_INS_Category(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("s", INS_Disassemble(*(INS*) ins).c_str());
}
PyObject* Python_INS_Extension(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_Extension(*(INS*) ins));
}
/*NEED TO VERIFY */
PyObject* Python_INS_MemoryOperandSize(PyObject* self, PyObject* args){
    PyObject* ins, *index;
    PyArg_ParseTuple(args, "O|L", &ins, &index);

    return Py_BuildValue("L", INS_MemoryOperandSize(*(INS*) ins, *(UINT32*) index));
}

/*bulk*/
PyObject* Python_INS_MemoryWriteSize(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_MemoryWriteSize(*(INS*) ins));
}

PyObject* Python_INS_GetPredicate(PyObject* self, PyObject* args){
   PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("s", INS_Disassemble(*(INS*) ins).c_str());
}

PyObject* Python_INS_MemoryReadSize(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_MemoryReadSize(*(INS*) ins));
}

PyObject* Python_INS_IsMemoryRead(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsMemoryRead(*(INS*) ins));
}
PyObject* Python_INS_IsMemoryWrite(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsMemoryWrite(*(INS*) ins));
}
PyObject* Python_INS_HasMemoryRead2(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_HasMemoryRead2(*(INS*) ins));
}

PyObject* Python_INS_HasFallThrough(PyObject* self, PyObject* args){
  PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_HasFallThrough(*(INS*) ins));
}

PyObject* Python_INS_IsLea(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsLea(*(INS*) ins));
}
PyObject* Python_INS_IsNop(PyObject* self, PyObject* args){
   PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsNop(*(INS*) ins));
}

PyObject* Python_OPCODE_StringShort(PyObject* self, PyObject* args){
   PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("s", OPCODE_StringShort(*(UINT32*) ins).c_str());
}
PyObject* Python_INS_Mnemonic(PyObject* self, PyObject* args){
   PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("s", INS_Mnemonic(*(INS*) ins).c_str());
}
PyObject* Python_INS_IsBranch(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsBranch(*(INS*) ins));
}
PyObject* Python_INS_IsDirectBranch(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsDirectBranch(*(INS*) ins));
}
PyObject* Python_INS_IsDirectCall(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsDirectCall(*(INS*) ins));
}
PyObject* Python_INS_IsDirectBranchOrCall(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsDirectBranchOrCall(*(INS*) ins));
}
PyObject* Python_INS_IsBranchOrCall(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsBranchOrCall(*(INS*) ins));
}
PyObject* Python_INS_Stutters(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_Stutters(*(INS*) ins));
}
PyObject* Python_INS_IsCall(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsCall(*(INS*) ins));
}
PyObject* Python_INS_IsProcedureCall(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsProcedureCall(*(INS*) ins));
}
PyObject* Python_INS_IsRet(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsRet(*(INS*) ins));
}
PyObject* Python_INS_IsSysret(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsSysret(*(INS*) ins));
}
PyObject* Python_INS_IsPrefetch(PyObject* self, PyObject* args){
   PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsPrefetch(*(INS*) ins));
}
PyObject* Python_INS_IsAtomicUpdate(PyObject* self, PyObject* args){
   PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsAtomicUpdate(*(INS*) ins));
}
PyObject* Python_INS_IsIndirectBranchOrCall(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsIndirectBranchOrCall(*(INS*) ins));
}

PyObject* Python_INS_RegR(PyObject* self, PyObject* args){
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_RegR(*(INS*) ins, *(UINT32*) uint_));
}
PyObject* Python_INS_RegW(PyObject* self, PyObject* args){
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_RegR(*(INS*) ins, *(UINT32*) uint_));
}
/*VERIFIED*/ /*Slightly sketchy reevaluate this one*/
PyObject* Python_INS_Opcode(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_Opcode(*(INS*) ins));
}


PyObject* Python_INS_MaxNumRRegs(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_MaxNumRRegs(*(INS*) ins));
}

PyObject* Python_INS_MaxNumWRegs(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_MaxNumWRegs(*(INS*) ins));
}
/*end bulk*/

/* NEED REG CLASS */
PyObject* Python_INS_RegRContain(PyObject* self, PyObject* args){
   PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("s", INS_Disassemble(*(INS*) ins).c_str());
}
PyObject* Python_INS_RegWContain(PyObject* self, PyObject* args){
   PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("s", INS_Disassemble(*(INS*) ins).c_str());
}
/******/

PyObject* Python_INS_IsStackRead(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsStackRead(*(INS*) ins));
}
PyObject* Python_INS_IsStackWrite(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsStackWrite(*(INS*) ins));
}
PyObject* Python_INS_IsIpRelRead(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsIpRelRead(*(INS*) ins));
}
PyObject* Python_INS_IsIpRelWrite(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsIpRelWrite(*(INS*) ins));
}
PyObject* Python_INS_IsPredicated(PyObject* self, PyObject* args){
     PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsPredicated(*(INS*) ins));
}
PyObject* Python_INS_IsOriginal(PyObject* self, PyObject* args){
     PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsOriginal(*(INS*) ins));
}
/* VERIFIED */
PyObject* Python_INS_Disassemble(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("s", INS_Disassemble(*(INS*) ins).c_str());
}
/* BULK MADE NOT VERIFIED BUT SHOULD WORK */
PyObject* Python_INS_MemoryOperandCount(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("L", INS_MemoryOperandCount(*(INS*) ins));
}
PyObject* Python_INS_OperandIsAddressGenerator(PyObject* self, PyObject* args){
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandIsAddressGenerator(*(INS*) ins, *(UINT32*) uint_));
}

PyObject* Python_INS_MemoryOperandIsRead(PyObject* self, PyObject* args){
      PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_MemoryOperandIsRead(*(INS*) ins, *(UINT32*) uint_));
}
PyObject* Python_INS_MemoryOperandIsWritten(PyObject* self, PyObject* args){
      PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_MemoryOperandIsWritten(*(INS*) ins, *(UINT32*) uint_));
}
PyObject* Python_INS_IsSyscall(PyObject* self, PyObject* args){
   PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsSyscall(*(INS*) ins));
}

PyObject* Python_INS_SyscallStd(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "O", &ins);
    return Py_BuildValue("L", INS_SyscallStd(*(INS*) ins));
}

/*END BULK */

/*NEED RTN IMPLEMENT FIRST*/
PyObject* Python_INS_Rtn(PyObject* self, PyObject* args){
   PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("s", INS_Disassemble(*(INS*) ins).c_str());
}

/* VERIFIED */
PyObject* Python_INS_Next(PyObject* self, PyObject* args){
    PyObject* trace;
    PyArg_ParseTuple(args, "O", &trace);
    INS *need  =(INS*) malloc(sizeof(INS));

    *need = INS_Next(*(INS*) PyInt_AsLong(trace));
    return Py_BuildValue("L", need);
}

/*VERIFIED*/
PyObject* Python_INS_Prev(PyObject* self, PyObject* args){
    PyObject* trace;
    PyArg_ParseTuple(args, "O", &trace);
    INS *need  =(INS*) malloc(sizeof(INS));

    *need = INS_Next(*(INS*) PyInt_AsLong(trace));
    return Py_BuildValue("L", need);
}

/* VERIFIED */
PyObject* Python_INS_Valid(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_Valid(*(INS*) ins));
}

/*VERIFIED*/
PyObject* Python_INS_Address(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_Address(*(INS*) ins));
}
/*VERIFIED*/
PyObject* Python_INS_Size(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_Size(*(INS*) ins));
}

/*THIS MAY BE MADE UP */
PyObject* Python_INS_DirectBranchOrCallTargetAddress(PyObject* self, PyObject* args){
   PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("s", INS_Disassemble(*(INS*) ins).c_str());
}
/*Verified*/
PyObject* Python_INS_NextAddress(PyObject* self, PyObject* args){  PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_NextAddress(*(INS*) ins));
}

/*AUTO GENERATED INSPECTION API*/
    PyObject* Python_INS_EffectiveAddressWidth(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_EffectiveAddressWidth(*(INS*) ins));
}
    PyObject* Python_INS_IsSysenter(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsSysenter(*(INS*) ins));
}
    PyObject* Python_INS_IsXbegin(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsXbegin(*(INS*) ins));
}
    PyObject* Python_INS_IsXend(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsXend(*(INS*) ins));
}
    PyObject* Python_INS_IsHalt(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsHalt(*(INS*) ins));
}
    PyObject* Python_INS_IsPcMaterialization(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsPcMaterialization(*(INS*) ins));
}
    PyObject* Python_INS_IsFarCall(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsFarCall(*(INS*) ins));
}
    PyObject* Python_INS_IsFarJump(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsFarJump(*(INS*) ins));
}
    PyObject* Python_INS_IsDirectFarJump(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsDirectFarJump(*(INS*) ins));
}
    PyObject* Python_INS_IsVgather(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsVgather(*(INS*) ins));
}
    PyObject* Python_INS_IsVscatter(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsVscatter(*(INS*) ins));
}
    PyObject* Python_INS_HasMemoryVector(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_HasMemoryVector(*(INS*) ins));
}
    PyObject* Python_INS_IsInterrupt(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsInterrupt(*(INS*) ins));
}
    PyObject* Python_INS_IsFarRet(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsFarRet(*(INS*) ins));
}
    PyObject* Python_INS_IsSub(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsSub(*(INS*) ins));
}
    PyObject* Python_INS_IsMov(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsMov(*(INS*) ins));
}
    PyObject* Python_INS_IsMovFullRegRegSame(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsMovFullRegRegSame(*(INS*) ins));
}
    PyObject* Python_INS_IsRDTSC(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsRDTSC(*(INS*) ins));
}
    PyObject* Python_INS_IsMaskMov(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsMaskMov(*(INS*) ins));
}
    PyObject* Python_INS_IsMaskedJump(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsMaskedJump(*(INS*) ins));
}
    PyObject* Python_INS_RepCountRegister(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_RepCountRegister(*(INS*) ins));
}
    PyObject* Python_INS_SegmentRegPrefix(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_SegmentRegPrefix(*(INS*) ins));
}
    PyObject* Python_INS_SegPrefixIsMemoryRead(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_SegPrefixIsMemoryRead(*(INS*) ins));
}
    PyObject* Python_INS_SegPrefixIsMemoryWrite(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_SegPrefixIsMemoryWrite(*(INS*) ins));
}
    PyObject* Python_INS_AddressSizePrefix(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_AddressSizePrefix(*(INS*) ins));
}
    PyObject* Python_INS_BranchNotTakenPrefix(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_BranchNotTakenPrefix(*(INS*) ins));
}
    PyObject* Python_INS_BranchTakenPrefix(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_BranchTakenPrefix(*(INS*) ins));
}
    PyObject* Python_INS_LockPrefix(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_LockPrefix(*(INS*) ins));
}
    PyObject* Python_INS_OperandSizePrefix(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_OperandSizePrefix(*(INS*) ins));
}
    PyObject* Python_INS_RepPrefix(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_RepPrefix(*(INS*) ins));
}
    PyObject* Python_INS_RepnePrefix(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_RepnePrefix(*(INS*) ins));
}
    PyObject* Python_INS_SegmentPrefix(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_SegmentPrefix(*(INS*) ins));
}
    PyObject* Python_INS_IsXchg(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsXchg(*(INS*) ins));
}
    PyObject* Python_INS_IsStringop(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsStringop(*(INS*) ins));
}
    PyObject* Python_INS_IsIRet(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsIRet(*(INS*) ins));
}
    PyObject* Python_INS_HasRealRep(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_HasRealRep(*(INS*) ins));
}
    PyObject* Python_INS_MemoryDisplacement(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_MemoryDisplacement(*(INS*) ins));
}
    PyObject* Python_INS_MemoryBaseReg(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_MemoryBaseReg(*(INS*) ins));
}
    PyObject* Python_INS_MemoryIndexReg(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_MemoryIndexReg(*(INS*) ins));
}
    PyObject* Python_INS_MemoryScale(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_MemoryScale(*(INS*) ins));
}
    PyObject* Python_INS_OperandCount(PyObject* self, PyObject* args){
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_OperandCount(*(INS*) ins));
}

/*AUTO GENERATED SKELETONS*/
    PyObject* Python_INS_OperandNameId(PyObject* self, PyObject* args){
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandNameId(*(INS*) ins, *(UINT32*) uint_));
    }
    PyObject* Python_INS_OperandIsMemory(PyObject* self, PyObject* args){
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandIsMemory(*(INS*) ins, *(UINT32*) uint_));
    }
    PyObject* Python_INS_OperandMemoryBaseReg(PyObject* self, PyObject* args){
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandMemoryBaseReg(*(INS*) ins, *(UINT32*) uint_));
    }
    PyObject* Python_INS_OperandMemoryIndexReg(PyObject* self, PyObject* args){
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandMemoryIndexReg(*(INS*) ins, *(UINT32*) uint_));
    }
    PyObject* Python_INS_OperandMemorySegmentReg(PyObject* self, PyObject* args){
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandMemorySegmentReg(*(INS*) ins, *(UINT32*) uint_));
    }
    PyObject* Python_INS_OperandMemoryScale(PyObject* self, PyObject* args){
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandMemoryScale(*(INS*) ins, *(UINT32*) uint_));
    }
    PyObject* Python_INS_OperandMemoryDisplacement(PyObject* self, PyObject* args){
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandMemoryDisplacement(*(INS*) ins, *(UINT32*) uint_));
    }
    PyObject* Python_INS_OperandIsFixedMemop(PyObject* self, PyObject* args){
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandIsFixedMemop(*(INS*) ins, *(UINT32*) uint_));
    }
    PyObject* Python_INS_OperandIsBranchDisplacement(PyObject* self, PyObject* args){
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandIsBranchDisplacement(*(INS*) ins, *(UINT32*) uint_));
    }
    PyObject* Python_INS_OperandIsReg(PyObject* self, PyObject* args){
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandIsReg(*(INS*) ins, *(UINT32*) uint_));
    }
    PyObject* Python_INS_OperandReg(PyObject* self, PyObject* args){
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandReg(*(INS*) ins, *(UINT32*) uint_));
    }
    PyObject* Python_INS_OperandIsImmediate(PyObject* self, PyObject* args){
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandIsImmediate(*(INS*) ins, *(UINT32*) uint_));
    }
    PyObject* Python_INS_OperandImmediate(PyObject* self, PyObject* args){
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandImmediate(*(INS*) ins, *(UINT32*) uint_));
    }
    PyObject* Python_INS_OperandIsImplicit(PyObject* self, PyObject* args){
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandIsImplicit(*(INS*) ins, *(UINT32*) uint_));
    }
    PyObject* Python_INS_OperandWidth(PyObject* self, PyObject* args){
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandWidth(*(INS*) ins, *(UINT32*) uint_));
    }
    PyObject* Python_INS_OperandRead(PyObject* self, PyObject* args){
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandRead(*(INS*) ins, *(UINT32*) uint_));
    }
    PyObject* Python_INS_OperandWritten(PyObject* self, PyObject* args){
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandWritten(*(INS*) ins, *(UINT32*) uint_));
    }
    PyObject* Python_INS_OperandReadOnly(PyObject* self, PyObject* args){
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandReadOnly(*(INS*) ins, *(UINT32*) uint_));
    }
    PyObject* Python_INS_OperandWrittenOnly(PyObject* self, PyObject* args){
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandWrittenOnly(*(INS*) ins, *(UINT32*) uint_));
    }
    PyObject* Python_INS_OperandReadAndWritten(PyObject* self, PyObject* args){
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandReadAndWritten(*(INS*) ins, *(UINT32*) uint_));
    }
    PyObject* Python_INS_MemoryOperandIndexToOperandIndex(PyObject* self, PyObject* args){
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_MemoryOperandIndexToOperandIndex(*(INS*) ins, *(UINT32*) uint_));
    }
