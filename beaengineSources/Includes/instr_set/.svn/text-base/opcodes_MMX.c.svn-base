/* Copyright 2006-2009, BeatriX
 * File coded by BeatriX
 *
 * This file is part of BeaEngine.
 *
 *    BeaEngine is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU Lesser General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    BeaEngine is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public License
 *    along with BeaEngine.  If not, see <http://www.gnu.org/licenses/>. */

void __bea_callspec__ emms_(PDISASM pMyDisasm)
{
	(*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+STATE_MANAGEMENT;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "emms ");
	GV.EIP_++;
}

/* ====================================================================
 *      0x 0f 7e
 * ==================================================================== */
void __bea_callspec__ movd_EP(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+DATA_TRANSFER;
    /* ========= 0xf3 */
    if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movq ");
        GV.SSE_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        if (GV.REX.W_ == 1) {
            GV.MemDecoration = Arg1qword;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movq ");
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.SSE_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            GV.MemDecoration = Arg1dword;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movd ");
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.SSE_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
    else {
        if (GV.REX.W_ == 1) {
            GV.MemDecoration = Arg1qword;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movq ");
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.MMX_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.MMX_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            GV.MemDecoration = Arg1dword;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movd ");
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.MMX_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.MMX_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
}


/* ====================================================================
 *      0x 0f 6e
 * ==================================================================== */
void __bea_callspec__ movd_PE(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+DATA_TRANSFER;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        if (GV.REX.W_ == 1) {
            GV.MemDecoration = Arg2qword;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movq ");
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.SSE_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            GV.MemDecoration = Arg2dword;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movd ");
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.SSE_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
    else {
        if (GV.REX.W_ == 1) {
            GV.MemDecoration = Arg2qword;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movq ");
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.MMX_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.MMX_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            GV.MemDecoration = Arg2dword;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movd ");
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.MMX_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.MMX_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
}



/* ====================================================================
 *      0x 0f 6f
 * ==================================================================== */
void __bea_callspec__ movq_PQ(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+DATA_TRANSFER;
    /* ========= 0xf3 */
    if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movdqu ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movdqa ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movq ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 7f
 * ==================================================================== */
void __bea_callspec__ movq_QP(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+DATA_TRANSFER;
    /* ========= 0xf3 */
    if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg1dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movdqu ");
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg1dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movdqa ");
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg1qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movq ");
        GV.MMX_ = 1;
        ExGx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f d6
 * ==================================================================== */
void __bea_callspec__ movq_WV(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+DATA_TRANSFER;
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movdq2q ");
        GV.MMX_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.MMX_ = 0;
        GV.SSE_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;

    }
    /* ========= 0xf3 */
    else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movq2dq ");
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 0;
        GV.MMX_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.MMX_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg1qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movq ");
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 1c
 * ==================================================================== */
void __bea_callspec__ pabsb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pabsb ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pabsb ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 38 1e
 * ==================================================================== */
void __bea_callspec__ pabsd_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pabsd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pabsd ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 38 1d
 * ==================================================================== */
void __bea_callspec__ pabsw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pabsw ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pabsw ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 63
 * ==================================================================== */
void __bea_callspec__ packsswb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+CONVERSION_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "packsswb ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "packsswb ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 6b
 * ==================================================================== */
void __bea_callspec__ packssdw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+CONVERSION_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "packssdw ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "packssdw ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 67
 * ==================================================================== */
void __bea_callspec__ packuswb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+CONVERSION_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "packuswb ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "packuswb ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f fc
 * ==================================================================== */
void __bea_callspec__ paddb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "paddb ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "paddb ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f fd
 * ==================================================================== */
void __bea_callspec__ paddw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "paddw ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "paddw ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f fe
 * ==================================================================== */
void __bea_callspec__ paddd_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "paddd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "paddd ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f ec
 * ==================================================================== */
void __bea_callspec__ paddsb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "paddsb ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "paddsb ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f ed
 * ==================================================================== */
void __bea_callspec__ paddsw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "paddsw ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "paddsw ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f dc
 * ==================================================================== */
void __bea_callspec__ paddusb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "paddusb ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "paddusb ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f dd
 * ==================================================================== */
void __bea_callspec__ paddusw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "paddusw ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "paddusw ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f db
 * ==================================================================== */
void __bea_callspec__ pand_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+LOGICAL_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pand ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pand ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}
/* ====================================================================
 *      0x 0f df
 * ==================================================================== */
void __bea_callspec__ pandn_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+LOGICAL_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pandn ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pandn ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 74
 * ==================================================================== */
void __bea_callspec__ pcmpeqb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+COMPARISON_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpeqb ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpeqb ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 75
 * ==================================================================== */
void __bea_callspec__ pcmpeqw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+COMPARISON_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpeqw ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpeqw ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 76
 * ==================================================================== */
void __bea_callspec__ pcmpeqd_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+COMPARISON_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpeqd ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpeqd ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 64
 * ==================================================================== */
void __bea_callspec__ pcmpgtb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+COMPARISON_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpgtb ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpgtb ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 65
 * ==================================================================== */
void __bea_callspec__ pcmpgtw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+COMPARISON_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpgtw ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpgtw ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 66
 * ==================================================================== */
void __bea_callspec__ pcmpgtd_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+COMPARISON_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpgtd ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpgtd ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f e5
 * ==================================================================== */
void __bea_callspec__ pmulhw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmulhw ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmulhw ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f d5
 * ==================================================================== */
void __bea_callspec__ pmullw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmullw ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmullw ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f f5
 * ==================================================================== */
void __bea_callspec__ pmaddwd_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmaddwd ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmaddwd ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f eb
 * ==================================================================== */
void __bea_callspec__ por_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+LOGICAL_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "por ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "por ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f f1
 * ==================================================================== */
void __bea_callspec__ psllw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+SHIFT_ROTATE;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psllw ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psllw ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f f2
 * ==================================================================== */
void __bea_callspec__ pslld_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+SHIFT_ROTATE;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pslld ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pslld ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f f3
 * ==================================================================== */
void __bea_callspec__ psllq_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+SHIFT_ROTATE;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psllq ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psllq ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f d1
 * ==================================================================== */
void __bea_callspec__ psrlw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+SHIFT_ROTATE;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psrlw ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psrlw ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f d2
 * ==================================================================== */
void __bea_callspec__ psrld_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+SHIFT_ROTATE;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psrld ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psrld ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f d3
 * ==================================================================== */
void __bea_callspec__ psrlq_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+SHIFT_ROTATE;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psrlq ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psrlq ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f e1
 * ==================================================================== */
void __bea_callspec__ psraw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+SHIFT_ROTATE;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psraw ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psraw ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f e2
 * ==================================================================== */
void __bea_callspec__ psrad_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+SHIFT_ROTATE;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psrad ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psrad ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f f8
 * ==================================================================== */
void __bea_callspec__ psubb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psubb ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psubb ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f f9
 * ==================================================================== */
void __bea_callspec__ psubw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psubw ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psubw ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f fa
 * ==================================================================== */
void __bea_callspec__ psubd_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psubd ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psubd ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f e8
 * ==================================================================== */
void __bea_callspec__ psubsb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psubsb ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psubsb ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f e9
 * ==================================================================== */
void __bea_callspec__ psubsw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psubsw ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psubsw ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f d8
 * ==================================================================== */
void __bea_callspec__ psubusb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psubusb ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psubusb ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f d9
 * ==================================================================== */
void __bea_callspec__ psubusw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psubusw ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psubusw ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 68
 * ==================================================================== */
void __bea_callspec__ punpckhbw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+CONVERSION_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpckhbw ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpckhbw ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 69
 * ==================================================================== */
void __bea_callspec__ punpckhwd_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+CONVERSION_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpckhwd ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpckhwd ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 6a
 * ==================================================================== */
void __bea_callspec__ punpckhdq_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+CONVERSION_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpckhdq ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpckhdq ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 60
 * ==================================================================== */
void __bea_callspec__ punpcklbw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+CONVERSION_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpcklbw ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpcklbw ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 61
 * ==================================================================== */
void __bea_callspec__ punpcklwd_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+CONVERSION_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpcklwd ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpcklwd ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 62
 * ==================================================================== */
void __bea_callspec__ punpckldq_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+CONVERSION_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpckldq ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpckldq ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}

/* ====================================================================
 *      0x 0f ef
 * ==================================================================== */
void __bea_callspec__ pxor_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = MMX_INSTRUCTION+LOGICAL_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {            
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pxor ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pxor ");
        (*pMyDisasm).Argument1.AccessMode = READ;
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}
