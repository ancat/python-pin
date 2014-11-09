#include </usr/include/python2.7/Python.h>
#include "pin.H"
#include "INS.h"

PyObject* Python_INS_InsertCall(PyObject* self, PyObject* args) {
    return NULL;
}

PyObject* Python_INS_Category(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    return Py_BuildValue("L", INS_Category(ins_object));
}

PyObject* Python_INS_Extension(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    return Py_BuildValue("L", INS_Extension(ins_object));
}

PyObject* Python_INS_MemoryOperandSize(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyObject* memoryop;
    PyArg_ParseTuple(args, "L|O", &ins, &memoryop);
    INS ins_object = *(INS*) ins;
    UINT32 memoryop_object = (UINT32) PyInt_AsLong(memoryop);
    return Py_BuildValue("L", INS_MemoryOperandSize(ins_object, memoryop_object));
}

PyObject* Python_INS_MemoryWriteSize(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    return Py_BuildValue("L", INS_MemoryWriteSize(ins_object));
}

PyObject* Python_INS_GetPredicate(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    return Py_BuildValue("L", INS_GetPredicate(ins_object));
}

PyObject* Python_INS_MemoryReadSize(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    return Py_BuildValue("L", INS_MemoryReadSize(ins_object));
}

PyObject* Python_INS_IsMemoryRead(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsMemoryRead(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsMemoryWrite(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsMemoryWrite(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_HasMemoryRead2(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_HasMemoryRead2(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_HasFallThrough(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_HasFallThrough(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsLea(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsLea(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsNop(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsNop(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_OPCODE_StringShort(PyObject* self, PyObject* args) {
    PyObject* opcode;
    PyArg_ParseTuple(args, "O", &opcode);
    UINT32 opcode_object = (UINT32) PyInt_AsLong(opcode);
    return Py_BuildValue("s", OPCODE_StringShort(opcode_object).c_str());
}

PyObject* Python_INS_Mnemonic(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    return Py_BuildValue("s", INS_Mnemonic(ins_object).c_str());
}

PyObject* Python_INS_IsBranch(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsBranch(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsDirectBranch(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsDirectBranch(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsDirectCall(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsDirectCall(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsDirectBranchOrCall(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsDirectBranchOrCall(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsBranchOrCall(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsBranchOrCall(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_Stutters(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_Stutters(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsCall(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsCall(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsProcedureCall(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsProcedureCall(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsRet(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsRet(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsSysret(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsSysret(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsPrefetch(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsPrefetch(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsAtomicUpdate(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsAtomicUpdate(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsIndirectBranchOrCall(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsIndirectBranchOrCall(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_RegR(PyObject* self, PyObject* args) {
    PyObject* x;
    PyObject* k;
    PyArg_ParseTuple(args, "L|O", &x, &k);
    INS x_object = *(INS*) x;
    UINT32 k_object = (UINT32) PyInt_AsLong(k);
    REG* reg_return = (REG*) malloc(sizeof(REG));
    *reg_return = INS_RegR(x_object, k_object);
    return Py_BuildValue("L", reg_return);
}

PyObject* Python_INS_RegW(PyObject* self, PyObject* args) {
    PyObject* x;
    PyObject* k;
    PyArg_ParseTuple(args, "L|O", &x, &k);
    INS x_object = *(INS*) x;
    UINT32 k_object = (UINT32) PyInt_AsLong(k);
    REG* reg_return = (REG*) malloc(sizeof(REG));
    *reg_return = INS_RegW(x_object, k_object);
    return Py_BuildValue("L", reg_return);
}

PyObject* Python_INS_Opcode(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    OPCODE* opcode_return = (OPCODE*) malloc(sizeof(OPCODE));
    *opcode_return = INS_Opcode(ins_object);
    return Py_BuildValue("L", opcode_return);
}

PyObject* Python_CATEGORY_StringShort(PyObject* self, PyObject* args) {
    PyObject* num;
    PyArg_ParseTuple(args, "O", &num);
    UINT32 num_object = (UINT32) PyInt_AsLong(num);
    return Py_BuildValue("s", CATEGORY_StringShort(num_object).c_str());
}

PyObject* Python_EXTENSION_StringShort(PyObject* self, PyObject* args) {
    PyObject* num;
    PyArg_ParseTuple(args, "O", &num);
    UINT32 num_object = (UINT32) PyInt_AsLong(num);
    return Py_BuildValue("s", EXTENSION_StringShort(num_object).c_str());
}

PyObject* Python_INS_MaxNumRRegs(PyObject* self, PyObject* args) {
    PyObject* x;
    PyArg_ParseTuple(args, "L", &x);
    INS x_object = *(INS*) x;
    return Py_BuildValue("L", INS_MaxNumRRegs(x_object));
}

PyObject* Python_INS_MaxNumWRegs(PyObject* self, PyObject* args) {
    PyObject* x;
    PyArg_ParseTuple(args, "L", &x);
    INS x_object = *(INS*) x;
    return Py_BuildValue("L", INS_MaxNumWRegs(x_object));
}

PyObject* Python_INS_RegRContain(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyObject* reg;
    PyArg_ParseTuple(args, "L|L", &ins, &reg);
    INS ins_object = *(INS*) ins;
    REG reg_object = *(REG*) reg;
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
    INS ins_object = *(INS*) ins;
    REG reg_object = *(REG*) reg;
    if (INS_RegWContain(ins_object, reg_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsStackRead(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsStackRead(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsStackWrite(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsStackWrite(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsIpRelRead(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsIpRelRead(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsIpRelWrite(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsIpRelWrite(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsPredicated(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsPredicated(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsOriginal(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsOriginal(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_Disassemble(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    return Py_BuildValue("s", INS_Disassemble(ins_object).c_str());
}

PyObject* Python_INS_MemoryOperandCount(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    return Py_BuildValue("L", INS_MemoryOperandCount(ins_object));
}

PyObject* Python_INS_OperandIsAddressGenerator(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyObject* n;
    PyArg_ParseTuple(args, "L|O", &ins, &n);
    INS ins_object = *(INS*) ins;
    UINT32 n_object = (UINT32) PyInt_AsLong(n);
    if (INS_OperandIsAddressGenerator(ins_object, n_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_MemoryOperandIsRead(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyObject* memopidx;
    PyArg_ParseTuple(args, "L|O", &ins, &memopidx);
    INS ins_object = *(INS*) ins;
    UINT32 memopidx_object = (UINT32) PyInt_AsLong(memopidx);
    if (INS_MemoryOperandIsRead(ins_object, memopidx_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_MemoryOperandIsWritten(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyObject* memopidx;
    PyArg_ParseTuple(args, "L|O", &ins, &memopidx);
    INS ins_object = *(INS*) ins;
    UINT32 memopidx_object = (UINT32) PyInt_AsLong(memopidx);
    if (INS_MemoryOperandIsWritten(ins_object, memopidx_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsSyscall(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsSyscall(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_SyscallStd(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    return Py_BuildValue("L", INS_SyscallStd(ins_object));
}

PyObject* Python_INS_Rtn(PyObject* self, PyObject* args) {
    PyObject* x;
    PyArg_ParseTuple(args, "L", &x);
    INS x_object = *(INS*) x;
    RTN* rtn_return = (RTN*) malloc(sizeof(RTN));
    *rtn_return = INS_Rtn(x_object);
    return Py_BuildValue("L", rtn_return);
}

PyObject* Python_INS_Next(PyObject* self, PyObject* args) {
    PyObject* x;
    PyArg_ParseTuple(args, "L", &x);
    INS x_object = *(INS*) x;
    INS* ins_return = (INS*) malloc(sizeof(INS));
    *ins_return = INS_Next(x_object);
    return Py_BuildValue("L", ins_return);
}

PyObject* Python_INS_Prev(PyObject* self, PyObject* args) {
    PyObject* x;
    PyArg_ParseTuple(args, "L", &x);
    INS x_object = *(INS*) x;
    INS* ins_return = (INS*) malloc(sizeof(INS));
    *ins_return = INS_Prev(x_object);
    return Py_BuildValue("L", ins_return);
}

PyObject* Python_INS_Invalid(PyObject* self, PyObject* args) {

    INS* ins_return = (INS*) malloc(sizeof(INS));
    *ins_return = INS_Invalid();
    return Py_BuildValue("L", ins_return);
}

PyObject* Python_INS_Valid(PyObject* self, PyObject* args) {
    PyObject* x;
    PyArg_ParseTuple(args, "L", &x);
    INS x_object = *(INS*) x;
    if (INS_Valid(x_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_Address(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    return Py_BuildValue("L", INS_Address(ins_object));
}

PyObject* Python_INS_Size(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    return Py_BuildValue("L", INS_Size(ins_object));
}

PyObject* Python_INS_DirectBranchOrCallTargetAddress(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    return Py_BuildValue("L", INS_DirectBranchOrCallTargetAddress(ins_object));
}

PyObject* Python_INS_NextAddress(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    return Py_BuildValue("L", INS_NextAddress(ins_object));
}

PyObject* Python_INS_EffectiveAddressWidth(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    return Py_BuildValue("L", INS_EffectiveAddressWidth(ins_object));
}

PyObject* Python_INS_IsSysenter(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsSysenter(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsXbegin(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsXbegin(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsXend(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsXend(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsHalt(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsHalt(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsPcMaterialization(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsPcMaterialization(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsFarCall(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsFarCall(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsFarJump(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsFarJump(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsDirectFarJump(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsDirectFarJump(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsVgather(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsVgather(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsVscatter(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsVscatter(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_HasMemoryVector(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_HasMemoryVector(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsInterrupt(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsInterrupt(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsFarRet(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsFarRet(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsSub(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsSub(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsMov(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsMov(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsMovFullRegRegSame(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsMovFullRegRegSame(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsRDTSC(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsRDTSC(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsMaskMov(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsMaskMov(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsMaskedJump(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsMaskedJump(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_RepCountRegister(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    REG* reg_return = (REG*) malloc(sizeof(REG));
    *reg_return = INS_RepCountRegister(ins_object);
    return Py_BuildValue("L", reg_return);
}

PyObject* Python_INS_SegmentRegPrefix(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    REG* reg_return = (REG*) malloc(sizeof(REG));
    *reg_return = INS_SegmentRegPrefix(ins_object);
    return Py_BuildValue("L", reg_return);
}

PyObject* Python_INS_SegPrefixIsMemoryRead(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_SegPrefixIsMemoryRead(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_SegPrefixIsMemoryWrite(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_SegPrefixIsMemoryWrite(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_AddressSizePrefix(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_AddressSizePrefix(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_BranchNotTakenPrefix(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_BranchNotTakenPrefix(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_BranchTakenPrefix(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_BranchTakenPrefix(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_LockPrefix(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_LockPrefix(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_OperandSizePrefix(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_OperandSizePrefix(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_RepPrefix(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_RepPrefix(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_RepnePrefix(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_RepnePrefix(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_SegmentPrefix(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_SegmentPrefix(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsXchg(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsXchg(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsStringop(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsStringop(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_IsIRet(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_IsIRet(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_FullRegRContain(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyObject* reg;
    PyArg_ParseTuple(args, "L|L", &ins, &reg);
    INS ins_object = *(INS*) ins;
    REG reg_object = *(REG*) reg;
    if (INS_FullRegRContain(ins_object, reg_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_FullRegWContain(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyObject* reg;
    PyArg_ParseTuple(args, "L|L", &ins, &reg);
    INS ins_object = *(INS*) ins;
    REG reg_object = *(REG*) reg;
    if (INS_FullRegWContain(ins_object, reg_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_HasRealRep(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    if (INS_HasRealRep(ins_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_MemoryDisplacement(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    return Py_BuildValue("L", INS_MemoryDisplacement(ins_object));
}

PyObject* Python_INS_MemoryBaseReg(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    REG* reg_return = (REG*) malloc(sizeof(REG));
    *reg_return = INS_MemoryBaseReg(ins_object);
    return Py_BuildValue("L", reg_return);
}

PyObject* Python_INS_MemoryIndexReg(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    REG* reg_return = (REG*) malloc(sizeof(REG));
    *reg_return = INS_MemoryIndexReg(ins_object);
    return Py_BuildValue("L", reg_return);
}

PyObject* Python_INS_MemoryScale(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    return Py_BuildValue("L", INS_MemoryScale(ins_object));
}

PyObject* Python_INS_ChangeReg(PyObject* self, PyObject* args) {
    return Py_BuildValue("O", Py_False);
}

PyObject* Python_INS_OperandCount(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyArg_ParseTuple(args, "L", &ins);
    INS ins_object = *(INS*) ins;
    return Py_BuildValue("L", INS_OperandCount(ins_object));
}

PyObject* Python_INS_OperandNameId(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyObject* n;
    PyArg_ParseTuple(args, "L|O", &ins, &n);
    INS ins_object = *(INS*) ins;
    UINT32 n_object = (UINT32) PyInt_AsLong(n);
    return Py_BuildValue("L", INS_OperandNameId(ins_object, n_object));
}

PyObject* Python_INS_OperandIsMemory(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyObject* n;
    PyArg_ParseTuple(args, "L|O", &ins, &n);
    INS ins_object = *(INS*) ins;
    UINT32 n_object = (UINT32) PyInt_AsLong(n);
    if (INS_OperandIsMemory(ins_object, n_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_OperandMemoryBaseReg(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyObject* n;
    PyArg_ParseTuple(args, "L|O", &ins, &n);
    INS ins_object = *(INS*) ins;
    UINT32 n_object = (UINT32) PyInt_AsLong(n);
    REG* reg_return = (REG*) malloc(sizeof(REG));
    *reg_return = INS_OperandMemoryBaseReg(ins_object, n_object);
    return Py_BuildValue("L", reg_return);
}

PyObject* Python_INS_OperandMemoryIndexReg(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyObject* n;
    PyArg_ParseTuple(args, "L|O", &ins, &n);
    INS ins_object = *(INS*) ins;
    UINT32 n_object = (UINT32) PyInt_AsLong(n);
    REG* reg_return = (REG*) malloc(sizeof(REG));
    *reg_return = INS_OperandMemoryIndexReg(ins_object, n_object);
    return Py_BuildValue("L", reg_return);
}

PyObject* Python_INS_OperandMemorySegmentReg(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyObject* n;
    PyArg_ParseTuple(args, "L|O", &ins, &n);
    INS ins_object = *(INS*) ins;
    UINT32 n_object = (UINT32) PyInt_AsLong(n);
    REG* reg_return = (REG*) malloc(sizeof(REG));
    *reg_return = INS_OperandMemorySegmentReg(ins_object, n_object);
    return Py_BuildValue("L", reg_return);
}

PyObject* Python_INS_OperandMemoryScale(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyObject* n;
    PyArg_ParseTuple(args, "L|O", &ins, &n);
    INS ins_object = *(INS*) ins;
    UINT32 n_object = (UINT32) PyInt_AsLong(n);
    return Py_BuildValue("L", INS_OperandMemoryScale(ins_object, n_object));
}

PyObject* Python_INS_OperandMemoryDisplacement(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyObject* n;
    PyArg_ParseTuple(args, "L|O", &ins, &n);
    INS ins_object = *(INS*) ins;
    UINT32 n_object = (UINT32) PyInt_AsLong(n);
    return Py_BuildValue("L", INS_OperandMemoryDisplacement(ins_object, n_object));
}

PyObject* Python_INS_OperandIsFixedMemop(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyObject* n;
    PyArg_ParseTuple(args, "L|O", &ins, &n);
    INS ins_object = *(INS*) ins;
    UINT32 n_object = (UINT32) PyInt_AsLong(n);
    if (INS_OperandIsFixedMemop(ins_object, n_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_OperandIsBranchDisplacement(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyObject* n;
    PyArg_ParseTuple(args, "L|O", &ins, &n);
    INS ins_object = *(INS*) ins;
    UINT32 n_object = (UINT32) PyInt_AsLong(n);
    if (INS_OperandIsBranchDisplacement(ins_object, n_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_OperandIsReg(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyObject* n;
    PyArg_ParseTuple(args, "L|O", &ins, &n);
    INS ins_object = *(INS*) ins;
    UINT32 n_object = (UINT32) PyInt_AsLong(n);
    if (INS_OperandIsReg(ins_object, n_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_OperandReg(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyObject* n;
    PyArg_ParseTuple(args, "L|O", &ins, &n);
    INS ins_object = *(INS*) ins;
    UINT32 n_object = (UINT32) PyInt_AsLong(n);
    REG* reg_return = (REG*) malloc(sizeof(REG));
    *reg_return = INS_OperandReg(ins_object, n_object);
    return Py_BuildValue("L", reg_return);
}

PyObject* Python_INS_OperandIsImmediate(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyObject* n;
    PyArg_ParseTuple(args, "L|O", &ins, &n);
    INS ins_object = *(INS*) ins;
    UINT32 n_object = (UINT32) PyInt_AsLong(n);
    if (INS_OperandIsImmediate(ins_object, n_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_OperandImmediate(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyObject* n;
    PyArg_ParseTuple(args, "L|O", &ins, &n);
    INS ins_object = *(INS*) ins;
    UINT32 n_object = (UINT32) PyInt_AsLong(n);
    return Py_BuildValue("L", INS_OperandImmediate(ins_object, n_object));
}

PyObject* Python_INS_OperandIsImplicit(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyObject* n;
    PyArg_ParseTuple(args, "L|O", &ins, &n);
    INS ins_object = *(INS*) ins;
    UINT32 n_object = (UINT32) PyInt_AsLong(n);
    if (INS_OperandIsImplicit(ins_object, n_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_OperandWidth(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyObject* n;
    PyArg_ParseTuple(args, "L|O", &ins, &n);
    INS ins_object = *(INS*) ins;
    UINT32 n_object = (UINT32) PyInt_AsLong(n);
    return Py_BuildValue("L", INS_OperandWidth(ins_object, n_object));
}

PyObject* Python_INS_OperandRead(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyObject* n;
    PyArg_ParseTuple(args, "L|O", &ins, &n);
    INS ins_object = *(INS*) ins;
    UINT32 n_object = (UINT32) PyInt_AsLong(n);
    if (INS_OperandRead(ins_object, n_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_OperandWritten(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyObject* n;
    PyArg_ParseTuple(args, "L|O", &ins, &n);
    INS ins_object = *(INS*) ins;
    UINT32 n_object = (UINT32) PyInt_AsLong(n);
    if (INS_OperandWritten(ins_object, n_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_OperandReadOnly(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyObject* n;
    PyArg_ParseTuple(args, "L|O", &ins, &n);
    INS ins_object = *(INS*) ins;
    UINT32 n_object = (UINT32) PyInt_AsLong(n);
    if (INS_OperandReadOnly(ins_object, n_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_OperandWrittenOnly(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyObject* n;
    PyArg_ParseTuple(args, "L|O", &ins, &n);
    INS ins_object = *(INS*) ins;
    UINT32 n_object = (UINT32) PyInt_AsLong(n);
    if (INS_OperandWrittenOnly(ins_object, n_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_OperandReadAndWritten(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyObject* n;
    PyArg_ParseTuple(args, "L|O", &ins, &n);
    INS ins_object = *(INS*) ins;
    UINT32 n_object = (UINT32) PyInt_AsLong(n);
    if (INS_OperandReadAndWritten(ins_object, n_object)) {
        return Py_BuildValue("O", Py_True);
    } else {
        return Py_BuildValue("O", Py_False);
    }
}

PyObject* Python_INS_MemoryOperandIndexToOperandIndex(PyObject* self, PyObject* args) {
    PyObject* ins;
    PyObject* memopidx;
    PyArg_ParseTuple(args, "L|O", &ins, &memopidx);
    INS ins_object = *(INS*) ins;
    UINT32 memopidx_object = (UINT32) PyInt_AsLong(memopidx);
    return Py_BuildValue("L", INS_MemoryOperandIndexToOperandIndex(ins_object, memopidx_object));
}


