/*
    Everything up to Python_INS_RepCountRegister is implemented
*/

#include </usr/include/python2.7/Python.h>
#include "pin.H"
#include "INS.h"

/**** INS REPRESENTATION FUNCTIONS *****/
/*AUTO GENERATED SKELETONS*/
PyObject* Python_INS_Category(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_Category(*(INS*) ins));
}

PyObject* Python_INS_Extension(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    return Py_BuildValue("L", INS_Extension(ins_object));
}

/*NEED TO VERIFY */
PyObject* Python_INS_MemoryOperandSize(PyObject* self, PyObject* args) {
    PyObject* ins, *index;
    PyArg_ParseTuple(args, "O|L", &ins, &index);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    return Py_BuildValue("L", INS_MemoryOperandSize(ins_object, (UINT32) PyInt_AsLong(index)));
}

/*bulk*/
PyObject* Python_INS_MemoryWriteSize(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    return Py_BuildValue("L", INS_MemoryWriteSize(ins_object));
}

PyObject* Python_INS_GetPredicate(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);
    PREDICATE* predicate = (PREDICATE*) malloc(sizeof(PREDICATE));

    *predicate = INS_GetPredicate(ins_object);
    return Py_BuildValue("L", predicate);
}

PyObject* Python_INS_MemoryReadSize(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    return Py_BuildValue("L", INS_MemoryReadSize(ins_object));
}

PyObject* Python_INS_IsMemoryRead(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    return Py_BuildValue("L", INS_IsMemoryRead(ins_object));
}

PyObject* Python_INS_IsMemoryWrite(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    return Py_BuildValue("L", INS_IsMemoryWrite(ins_object));
}

PyObject* Python_INS_HasMemoryRead2(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    return Py_BuildValue("L", INS_HasMemoryRead2(ins_object));
}

PyObject* Python_INS_HasFallThrough(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    return Py_BuildValue("L", INS_HasFallThrough(ins_object));
}

PyObject* Python_INS_IsLea(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    return Py_BuildValue("L", INS_IsLea(ins_object));
}

PyObject* Python_INS_IsNop(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    return Py_BuildValue("L", INS_IsNop(ins_object));
}

PyObject* Python_OPCODE_StringShort(PyObject* self, PyObject* args) {
    PyObject* opcode;
    PyArg_ParseTuple(args, "L", &opcode);
    UINT32 opcode_object = (UINT32) PyInt_AsLong(opcode);

    return Py_BuildValue("s", OPCODE_StringShort(opcode_object).c_str());
}

PyObject* Python_INS_Mnemonic(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    return Py_BuildValue("s", INS_Mnemonic(ins_object).c_str());
}

PyObject* Python_INS_IsBranch(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsBranch(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsDirectBranch(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsDirectBranch(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsDirectCall(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsDirectCall(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsDirectBranchOrCall(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsDirectBranchOrCall(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsBranchOrCall(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsBranchOrCall(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_Stutters(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_Stutters(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsCall(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsCall(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsProcedureCall(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsProcedureCall(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsRet(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsRet(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsSysret(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsSysret(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsPrefetch(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsPrefetch(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsAtomicUpdate(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsAtomicUpdate(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsIndirectBranchOrCall(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsIndirectBranchOrCall(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

/* FIXME */
PyObject* Python_INS_RegR(PyObject* self, PyObject* args) {
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_RegR(*(INS*) ins, *(UINT32*) uint_));
}

PyObject* Python_INS_RegW(PyObject* self, PyObject* args) {
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_RegR(*(INS*) ins, *(UINT32*) uint_));
}

/*VERIFIED*/ /*Slightly sketchy reevaluate this one*/
PyObject* Python_INS_Opcode(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_Opcode(*(INS*) ins));
}

PyObject* Python_INS_MaxNumRRegs(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_MaxNumRRegs(*(INS*) ins));
}

PyObject* Python_INS_MaxNumWRegs(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_MaxNumWRegs(*(INS*) ins));
}
/*end bulk/FIXME*/

/* NEED REG CLASS */
PyObject* Python_INS_RegRContain(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyObject* reg;
    PyArg_ParseTuple(args, "L|L", &ins, &reg);
    INS ins_object = *(INS*) PyInt_AsLong(ins);
    REG reg_object = *(REG*) PyInt_AsLong(reg);

    if (INS_RegRContain(ins_object, reg_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_RegWContain(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyObject* reg;
    PyArg_ParseTuple(args, "L|L", &ins, &reg);
    INS ins_object = *(INS*) PyInt_AsLong(ins);
    REG reg_object = *(REG*) PyInt_AsLong(reg);

    if (INS_RegWContain(ins_object, reg_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}
/******/

PyObject* Python_INS_IsStackRead(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsStackRead(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsStackWrite(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsStackWrite(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsIpRelRead(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsIpRelRead(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsIpRelWrite(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsIpRelWrite(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsPredicated(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsPredicated(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsOriginal(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsOriginal(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

/* VERIFIED */
PyObject* Python_INS_Disassemble(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    return Py_BuildValue("s", INS_Disassemble(ins_object).c_str());
}

/* BULK MADE NOT VERIFIED BUT SHOULD WORK */
PyObject* Python_INS_MemoryOperandCount(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    return Py_BuildValue("L", INS_MemoryOperandCount(ins_object));
}

PyObject* Python_INS_OperandIsAddressGenerator(PyObject* self, PyObject* args) {
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    INS ins_object = *(INS*) PyInt_AsLong(ins);
    UINT32 uint_object = (UINT32) PyInt_AsLong(uint_);

    if (INS_OperandIsAddressGenerator(ins_object, uint_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_MemoryOperandIsRead(PyObject* self, PyObject* args) {
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    INS ins_object = *(INS*) PyInt_AsLong(ins);
    UINT32 uint_object = (UINT32) PyInt_AsLong(uint_);

    if (INS_MemoryOperandIsRead(ins_object, uint_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_MemoryOperandIsWritten(PyObject* self, PyObject* args) {
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    INS ins_object = *(INS*) PyInt_AsLong(ins);
    UINT32 uint_object = (UINT32) PyInt_AsLong(uint_);

    if (INS_MemoryOperandIsWritten(ins_object, uint_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsSyscall(PyObject* self, PyObject* args) {
   PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsSyscall(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_SyscallStd(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    return Py_BuildValue("L", INS_SyscallStd(ins_object));
}

/*END BULK */

/*NEED RTN IMPLEMENT FIRST*/
PyObject* Python_INS_Rtn(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);
    RTN* rtn = (RTN*) malloc(sizeof(RTN));
    *rtn = INS_Rtn(ins_object);

    return Py_BuildValue("L", rtn);
}

/* VERIFIED */
PyObject* Python_INS_Next(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);
    INS* ins_next = (INS*) malloc(sizeof(INS));
    *ins_next = INS_Next(ins_object);

    return Py_BuildValue("L", ins_next);
}

/*VERIFIED*/
PyObject* Python_INS_Prev(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);
    INS* ins_prev = (INS*) malloc(sizeof(INS));
    *ins_prev = INS_Prev(ins_object);

    return Py_BuildValue("L", ins_prev);
}

/* VERIFIED */
PyObject* Python_INS_Valid(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_Valid(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

/*VERIFIED*/
PyObject* Python_INS_Address(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    return Py_BuildValue("L", INS_Address(ins_object));
}

/*VERIFIED*/
PyObject* Python_INS_Size(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    return Py_BuildValue("L", INS_Size(ins_object));
}

/*THIS MAY BE MADE UP */
PyObject* Python_INS_DirectBranchOrCallTargetAddress(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    return Py_BuildValue("L", INS_DirectBranchOrCallTargetAddress(ins_object));
}

/*Verified*/
PyObject* Python_INS_NextAddress(PyObject* self, PyObject* args) {  PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    return Py_BuildValue("L", INS_NextAddress(ins_object));
}

/*AUTO GENERATED INSPECTION API*/
PyObject* Python_INS_EffectiveAddressWidth(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    return Py_BuildValue("L", INS_EffectiveAddressWidth(ins_object));
}

PyObject* Python_INS_IsSysenter(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsSysenter(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsXbegin(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsXbegin(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsXend(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsXend(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsHalt(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsHalt(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsPcMaterialization(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsPcMaterialization(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsFarCall(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsFarCall(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsFarJump(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsFarCall(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsDirectFarJump(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsDirectFarJump(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsVgather(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsVgather(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsVscatter(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsVscatter(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_HasMemoryVector(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_HasMemoryVector(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsInterrupt(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsInterrupt(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsFarRet(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsFarRet(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsSub(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsSub(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsMov(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsMov(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsMovFullRegRegSame(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsMovFullRegRegSame(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
    return Py_BuildValue("L", INS_IsMovFullRegRegSame(*(INS*) ins));
}

PyObject* Python_INS_IsRDTSC(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsRDTSC(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsMaskMov(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsMaskMov(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsMaskedJump(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) PyInt_AsLong(ins);

    if (INS_IsMaskedJump(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_RepCountRegister(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_RepCountRegister(*(INS*) ins));
}

PyObject* Python_INS_SegmentRegPrefix(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_SegmentRegPrefix(*(INS*) ins));
}

PyObject* Python_INS_SegPrefixIsMemoryRead(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_SegPrefixIsMemoryRead(*(INS*) ins));
}

PyObject* Python_INS_SegPrefixIsMemoryWrite(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_SegPrefixIsMemoryWrite(*(INS*) ins));
}

PyObject* Python_INS_AddressSizePrefix(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_AddressSizePrefix(*(INS*) ins));
}

PyObject* Python_INS_BranchNotTakenPrefix(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_BranchNotTakenPrefix(*(INS*) ins));
}

PyObject* Python_INS_BranchTakenPrefix(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_BranchTakenPrefix(*(INS*) ins));
}

PyObject* Python_INS_LockPrefix(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_LockPrefix(*(INS*) ins));
}

PyObject* Python_INS_OperandSizePrefix(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_OperandSizePrefix(*(INS*) ins));
}

PyObject* Python_INS_RepPrefix(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_RepPrefix(*(INS*) ins));
}

PyObject* Python_INS_RepnePrefix(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_RepnePrefix(*(INS*) ins));
}

PyObject* Python_INS_SegmentPrefix(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_SegmentPrefix(*(INS*) ins));
}

PyObject* Python_INS_IsXchg(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsXchg(*(INS*) ins));
}

PyObject* Python_INS_IsStringop(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsStringop(*(INS*) ins));
}

PyObject* Python_INS_IsIRet(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_IsIRet(*(INS*) ins));
}

PyObject* Python_INS_HasRealRep(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_HasRealRep(*(INS*) ins));
}

PyObject* Python_INS_MemoryDisplacement(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_MemoryDisplacement(*(INS*) ins));
}

PyObject* Python_INS_MemoryBaseReg(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_MemoryBaseReg(*(INS*) ins));
}

PyObject* Python_INS_MemoryIndexReg(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_MemoryIndexReg(*(INS*) ins));
}

PyObject* Python_INS_MemoryScale(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_MemoryScale(*(INS*) ins));
}

PyObject* Python_INS_OperandCount(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    return Py_BuildValue("L", INS_OperandCount(*(INS*) ins));
}

/*AUTO GENERATED SKELETONS*/
PyObject* Python_INS_OperandNameId(PyObject* self, PyObject* args) {
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandNameId(*(INS*) ins, *(UINT32*) uint_));
}

PyObject* Python_INS_OperandIsMemory(PyObject* self, PyObject* args) {
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandIsMemory(*(INS*) ins, *(UINT32*) uint_));
}

PyObject* Python_INS_OperandMemoryBaseReg(PyObject* self, PyObject* args) {
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandMemoryBaseReg(*(INS*) ins, *(UINT32*) uint_));
}

PyObject* Python_INS_OperandMemoryIndexReg(PyObject* self, PyObject* args) {
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandMemoryIndexReg(*(INS*) ins, *(UINT32*) uint_));
}

PyObject* Python_INS_OperandMemorySegmentReg(PyObject* self, PyObject* args) {
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandMemorySegmentReg(*(INS*) ins, *(UINT32*) uint_));
}

PyObject* Python_INS_OperandMemoryScale(PyObject* self, PyObject* args) {
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandMemoryScale(*(INS*) ins, *(UINT32*) uint_));
}

PyObject* Python_INS_OperandMemoryDisplacement(PyObject* self, PyObject* args) {
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandMemoryDisplacement(*(INS*) ins, *(UINT32*) uint_));
}

PyObject* Python_INS_OperandIsFixedMemop(PyObject* self, PyObject* args) {
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandIsFixedMemop(*(INS*) ins, *(UINT32*) uint_));
}

PyObject* Python_INS_OperandIsBranchDisplacement(PyObject* self, PyObject* args) {
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandIsBranchDisplacement(*(INS*) ins, *(UINT32*) uint_));
}

PyObject* Python_INS_OperandIsReg(PyObject* self, PyObject* args) {
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandIsReg(*(INS*) ins, *(UINT32*) uint_));
}

PyObject* Python_INS_OperandReg(PyObject* self, PyObject* args) {
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandReg(*(INS*) ins, *(UINT32*) uint_));
}

PyObject* Python_INS_OperandIsImmediate(PyObject* self, PyObject* args) {
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandIsImmediate(*(INS*) ins, *(UINT32*) uint_));
}

PyObject* Python_INS_OperandImmediate(PyObject* self, PyObject* args) {
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandImmediate(*(INS*) ins, *(UINT32*) uint_));
}

PyObject* Python_INS_OperandIsImplicit(PyObject* self, PyObject* args) {
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandIsImplicit(*(INS*) ins, *(UINT32*) uint_));
}

PyObject* Python_INS_OperandWidth(PyObject* self, PyObject* args) {
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandWidth(*(INS*) ins, *(UINT32*) uint_));
}

PyObject* Python_INS_OperandRead(PyObject* self, PyObject* args) {
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandRead(*(INS*) ins, *(UINT32*) uint_));
}

PyObject* Python_INS_OperandWritten(PyObject* self, PyObject* args) {
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandWritten(*(INS*) ins, *(UINT32*) uint_));
}

PyObject* Python_INS_OperandReadOnly(PyObject* self, PyObject* args) {
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandReadOnly(*(INS*) ins, *(UINT32*) uint_));
}

PyObject* Python_INS_OperandWrittenOnly(PyObject* self, PyObject* args) {
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandWrittenOnly(*(INS*) ins, *(UINT32*) uint_));
}

PyObject* Python_INS_OperandReadAndWritten(PyObject* self, PyObject* args) {
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_OperandReadAndWritten(*(INS*) ins, *(UINT32*) uint_));
}

PyObject* Python_INS_MemoryOperandIndexToOperandIndex(PyObject* self, PyObject* args) {
    PyObject* ins, *uint_;
    PyArg_ParseTuple(args, "L|L", &ins, &uint_);
    return Py_BuildValue("L", INS_MemoryOperandIndexToOperandIndex(*(INS*) ins, *(UINT32*) uint_));
}
