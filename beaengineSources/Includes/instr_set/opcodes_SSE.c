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

/* ====================================================================
 *      0x 0f 58
 * ==================================================================== */
void __bea_callspec__ addps_VW(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "addsd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========= 0xf3 */
    else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "addss ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "addpd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "addps ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}

/* ====================================================================
 *      0x 0f d0
 * ==================================================================== */
void __bea_callspec__ addsubpd_(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SIMD_FP_PACKED;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "addsubps ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }

    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SIMD_FP_PACKED;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "addsubpd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 55
 * ==================================================================== */
void __bea_callspec__ andnps_VW(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+LOGICAL_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "andnpd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+LOGICAL_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "andnps ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 54
 * ==================================================================== */
void __bea_callspec__ andps_VW(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+LOGICAL_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "andpd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+LOGICAL_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "andps ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 3a 0d
 * ==================================================================== */
void __bea_callspec__ blendpd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_BLENDING_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "blendpd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.ImmediatSize = 8;

    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 3a 0c
 * ==================================================================== */
void __bea_callspec__ blendps_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_BLENDING_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "blendps ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.ImmediatSize = 8;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 15
 * ==================================================================== */
void __bea_callspec__ blendvpd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_BLENDING_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "blendvpd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 38 14
 * ==================================================================== */
void __bea_callspec__ blendvps_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_BLENDING_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "blendvps ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f c2
 * ==================================================================== */
void __bea_callspec__ cmpps_VW(PDISASM pMyDisasm)
{

    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+COMPARISON_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpsd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0xf3 */
    else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+COMPARISON_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpss ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+COMPARISON_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmppd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+COMPARISON_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpps ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    (*pMyDisasm).Argument1.AccessMode = READ;
    GV.EIP_++;
    if (!Security(0, pMyDisasm)) return;
    GV.third_arg = 1;
    (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
    (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
    (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument3.ArgSize = 8;
    GV.ImmediatSize = 8;
}


/* ====================================================================
 *      0x 0f 38 f0
 * ==================================================================== */
void __bea_callspec__ crc32_GvEb(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+ACCELERATOR_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "crc32 ");
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg2byte;
            GV.OperandSize = 8;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.OperandSize = 64;
        }
        else if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg2byte;
            GV.OperandSize = 8;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.OperandSize = 32;
        }
        else {
            GV.MemDecoration = Arg2byte;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        }

        if (GV.OperandSize == 16) {
            GV.OperandSize = 32;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.OperandSize = 16;
        }
        else {
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        }
        GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 f1
 * ==================================================================== */
void __bea_callspec__ crc32_GvEv(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+ACCELERATOR_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "crc32 ");

        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg2qword;
        }
        else if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg2dword;
        }
        else {
            GV.MemDecoration = Arg2word;
        }
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);

        if (GV.OperandSize == 16) {
            GV.OperandSize = 32;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.OperandSize = 16;
        }
        else {
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        }
        GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 2f
 * ==================================================================== */
void __bea_callspec__ comiss_VW(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+COMPARISON_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "comisd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+COMPARISON_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "comiss ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 5a
 * ==================================================================== */
void __bea_callspec__ cvtps2pd_(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtsd2ss ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0xf3 */
    else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtss2sd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtpd2ps ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtps2pd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 5b
 * ==================================================================== */
void __bea_callspec__ cvtdq2ps_(PDISASM pMyDisasm)
{
    /* ========== 0xf3 */
    if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvttps2dq ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtps2dq ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtdq2ps ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 2a
 * ==================================================================== */
void __bea_callspec__ cvtpi2ps_(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtsi2sd ");
        if (GV.REX.W_ == 1) {
            GV.MemDecoration = Arg2qword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.SSE_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.SSE_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
    /* ========== 0xf3 */
    else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtsi2ss ");
        if (GV.REX.W_ == 1) {
            GV.MemDecoration = Arg2qword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.SSE_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 1;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.SSE_ = 0;
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtpi2pd ");
        GV.MemDecoration = Arg2qword;
        GV.MMX_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.MMX_ = 0;
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtpi2ps ");
        GV.MemDecoration = Arg2qword;
        GV.MMX_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.MMX_ = 0;
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
}


/* ====================================================================
 *      0x 0f 2d
 * ==================================================================== */
void __bea_callspec__ cvtps2pi_(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtsd2si ");
        if (GV.REX.W_ == 1) {
            GV.MemDecoration = Arg2qword;
            GV.SSE_ = 1;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 0;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            GV.MemDecoration = Arg2qword;
            GV.SSE_ = 1;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 0;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
    /* ========== 0xf3 */
    else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtss2si ");
        if (GV.REX.W_ == 1) {
            GV.MemDecoration = Arg2dword;
            GV.SSE_ = 1;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 0;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            GV.MemDecoration = Arg2dword;
            GV.SSE_ = 1;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 0;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtpd2pi ");
        GV.MemDecoration = Arg2dqword;
        GV.SSE_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        GV.MMX_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.MMX_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtps2pi ");
        GV.MemDecoration = Arg2qword;
        GV.SSE_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        GV.MMX_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.MMX_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
}


/* ====================================================================
 *      0x 0f 2c
 * ==================================================================== */
void __bea_callspec__ cvttps2pi_(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvttsd2si ");
        if (GV.REX.W_ == 1) {
            GV.MemDecoration = Arg2qword;
            GV.SSE_ = 1;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 0;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            GV.MemDecoration = Arg2qword;
            GV.SSE_ = 1;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            GV.SSE_ = 0;
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
    /* ========== 0xf3 */
    else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvttss2si ");
        GV.MemDecoration = Arg2dword;
        GV.SSE_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvttpd2pi ");
        GV.MemDecoration = Arg2dqword;
        GV.SSE_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        GV.MMX_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.MMX_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvttps2pi ");
        GV.MemDecoration = Arg2qword;
        GV.SSE_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        GV.MMX_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.MMX_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
}


/* ====================================================================
 *      0x 0f e6
 * ==================================================================== */
void __bea_callspec__ cvtpd2dq_(PDISASM pMyDisasm)
{
    /* ========== 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtpd2dq ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0xf3 */
    else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvtdq2pd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cvttpd2dq ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 3a 41
 * ==================================================================== */
void __bea_callspec__ dppd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+DOT_PRODUCT;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "dppd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.ImmediatSize = 8;

    }
    else {
        FailDecode(pMyDisasm);
    }

}

/* ====================================================================
 *      0x 0f 3a 40
 * ==================================================================== */
void __bea_callspec__ dpps_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+DOT_PRODUCT;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "dpps ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.ImmediatSize = 8;

    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 5e
 * ==================================================================== */
void __bea_callspec__ divps_VW(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "divsd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========= 0xf3 */
    else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "divss ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "divpd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "divps ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 3a 17
 * ==================================================================== */
void __bea_callspec__ extractps_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg1dword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "extractps ");
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.ImmediatSize = 8;

    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 7c
 * ==================================================================== */
void __bea_callspec__ haddpd_VW(PDISASM pMyDisasm)
{

    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SIMD_FP_HORIZONTAL;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "haddpd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SIMD_FP_HORIZONTAL;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "haddps ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 7d
 * ==================================================================== */
void __bea_callspec__ hsubpd_VW(PDISASM pMyDisasm)
{

    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SIMD_FP_HORIZONTAL;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "hsubpd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SIMD_FP_HORIZONTAL;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "hsubps ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 3a 21
 * ==================================================================== */
void __bea_callspec__ insertps_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "insertps ");
        GV.SSE_ = 1;
        GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
        if (GV.MOD_== 0x3) {
            GV.MemDecoration = Arg2qword;
        }
        else {
            GV.MemDecoration = Arg2dword;
        }
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);


        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.ImmediatSize = 8;

    }
    else {
        FailDecode(pMyDisasm);
    }

}



/* ====================================================================
 *      0x 0f f0
 * ==================================================================== */
void __bea_callspec__ lddqu_(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+SPECIALIZED_128bits;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lddqu ");
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f f7
 * ==================================================================== */
void __bea_callspec__ maskmovq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CACHEABILITY_CONTROL;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "maskmovdqu ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+CACHEABILITY_CONTROL;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "maskmovq ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 5f
 * ==================================================================== */
void __bea_callspec__ maxps_VW(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "maxsd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========= 0xf3 */
    else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "maxss ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "maxpd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "maxps ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 5d
 * ==================================================================== */
void __bea_callspec__ minps_VW(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "minsd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========= 0xf3 */
    else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "minss ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "minpd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "minps ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 28
 * ==================================================================== */
void __bea_callspec__ movaps_VW(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movapd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movaps ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 29
 * ==================================================================== */
void __bea_callspec__ movaps_WV(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg1dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movapd ");
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movaps ");
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 16
 * ==================================================================== */
void __bea_callspec__ movhps_VM(PDISASM pMyDisasm)
{

    /* ========= 0xf3 */
    if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+DATA_TRANSFER;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movshdup ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movhpd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+DATA_TRANSFER;
        GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
        if (GV.MOD_== 0x3) {
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movlhps ");
        }
        else {
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movhps ");
        }
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 17
 * ==================================================================== */
void __bea_callspec__ movhps_MV(PDISASM pMyDisasm)
{

    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg1qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movhpd ");
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg1qword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+DATA_TRANSFER;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movhps ");
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 12
 * ==================================================================== */
void __bea_callspec__ movlps_VM(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+DATA_TRANSFER;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movddup ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========= 0xf3 */
    else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE3_INSTRUCTION+DATA_TRANSFER;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsldup ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movlpd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+DATA_TRANSFER;
        if (GV.MOD_== 0x3) {
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movhlps ");
        }
        else {
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movlps ");
        }
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 13
 * ==================================================================== */
void __bea_callspec__ movlps_MV(PDISASM pMyDisasm)
{

    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg1qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movlpd ");
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg1qword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+DATA_TRANSFER;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movlps ");
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 50
 * ==================================================================== */
void __bea_callspec__ movmskps_(PDISASM pMyDisasm)
{
    GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
    if (GV.MOD_!= 0x3) {
        FailDecode(pMyDisasm);
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+DATA_TRANSFER;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movmskpd ");
        GV.SSE_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;

    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+DATA_TRANSFER;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movmskps ");
        GV.SSE_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;

    }
}


/* ====================================================================
 *      0x 0f 38 2a
 * ==================================================================== */
void __bea_callspec__ movntdqa_(PDISASM pMyDisasm)
{

    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+STREAMING_LOAD;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movntdqa ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f c3
 * ==================================================================== */
void __bea_callspec__ movnti_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CACHEABILITY_CONTROL;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movnti ");
    EvGv(pMyDisasm);

}


/* ====================================================================
 *      0x 0f 2b
 * ==================================================================== */
void __bea_callspec__ movntps_(PDISASM pMyDisasm)
{
    GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
    if (GV.MOD_== 0x3) {
        FailDecode(pMyDisasm);
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg1dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CACHEABILITY_CONTROL;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movntpd ");
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;

    }
    else {
        GV.MemDecoration = Arg1dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CACHEABILITY_CONTROL;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movntps ");
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;

    }
}


/* ====================================================================
 *      0x 0f e7
 * ==================================================================== */
void __bea_callspec__ movntq_(PDISASM pMyDisasm)
{
    GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
    if (GV.MOD_== 0x3) {
        FailDecode(pMyDisasm);
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg1dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+CACHEABILITY_CONTROL;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movntdq ");
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg1qword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+CACHEABILITY_CONTROL;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movntq ");
        GV.MMX_ = 1;
        ExGx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 10
 * ==================================================================== */
void __bea_callspec__ movups_VW(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========= 0xf3 */
    else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movss ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movupd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movups ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}



/* ====================================================================
 *      0x 0f 11
 * ==================================================================== */
void __bea_callspec__ movups_WV(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg1qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsd ");
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========= 0xf3 */
    else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg1dword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movss ");
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg1dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movupd ");
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg1dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movups ");
        GV.SSE_ = 1;
        ExGx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 3a 42
 * ==================================================================== */
void __bea_callspec__ mpsadbw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+SAD_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mpsadbw ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.ImmediatSize = 8;

    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 59
 * ==================================================================== */
void __bea_callspec__ mulps_VW(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mulsd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0xf3 */
    else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mulss ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mulpd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mulps ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 56
 * ==================================================================== */
void __bea_callspec__ orps_VW(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+LOGICAL_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "orpd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+LOGICAL_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "orps ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 38 2b
 * ==================================================================== */
void __bea_callspec__ packusdw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "packusdw ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;

    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f d4
 * ==================================================================== */
void __bea_callspec__ paddq_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SIMD128bits;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "paddq ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "paddq ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f e0
 * ==================================================================== */
void __bea_callspec__ pavgb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pavgb ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pavgb ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f e3
 * ==================================================================== */
void __bea_callspec__ pavgw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pavgw ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pavgw ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 3a 0f
 * ==================================================================== */
void __bea_callspec__ palignr_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "palignr ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.ImmediatSize = 8;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "palignr ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.ImmediatSize = 8;
    }
}


/* ====================================================================
 *      0x 0f 38 10
 * ==================================================================== */
void __bea_callspec__ pblendvb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_BLENDING_INSTRUCTION;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pblendvb ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pblendvb ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 3a 0e
 * ==================================================================== */
void __bea_callspec__ pblendw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+SAD_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pblendw ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.ImmediatSize = 8;

    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 38 29
 * ==================================================================== */
void __bea_callspec__ pcmpeqq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_EQUALITY;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpeqq ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;

    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 3a 61
 * ==================================================================== */
void __bea_callspec__ pcmpestri_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+COMPARISON_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpestri ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.ImmediatSize = 8;

    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 3a 60
 * ==================================================================== */
void __bea_callspec__ pcmpestrm_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+COMPARISON_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpestrm ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.ImmediatSize = 8;

    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 3a 63
 * ==================================================================== */
void __bea_callspec__ pcmpistri_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+COMPARISON_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpistri ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.ImmediatSize = 8;

    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 3a 62
 * ==================================================================== */
void __bea_callspec__ pcmpistrm_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+COMPARISON_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpestrm ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.ImmediatSize = 8;

    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 38 37
 * ==================================================================== */
void __bea_callspec__ pcmpgtq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+COMPARISON_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pcmpgtq ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;

    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 3a 14
 * ==================================================================== */
void __bea_callspec__ pextrb_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pextrb ");
        GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
        if (GV.MOD_== 0x3) {
            GV.MemDecoration = Arg1dword;
        }
        else {
            GV.MemDecoration = Arg1byte;
        }
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_ += GV.DECALAGE_EIP+3;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.ImmediatSize = 8;

    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 3a 16
 * ==================================================================== */
void __bea_callspec__ pextrd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
        if (GV.REX.W_ == 0x1) {
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pextrq ");
            GV.MemDecoration = Arg1qword;
        }
        else {
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pextrd ");
            GV.MemDecoration = Arg1dword;
        }
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_ += GV.DECALAGE_EIP+3;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.ImmediatSize = 8;

    }
    else {
        FailDecode(pMyDisasm);
    }

}

/* ====================================================================
 *      0x 0f c5
 * ==================================================================== */
void __bea_callspec__ pextrw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pextrw ");
        GV.MemDecoration = Arg2dqword;
        GV.SSE_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+3;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.ImmediatSize = 8;

    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pextrw ");
        GV.MemDecoration = Arg2dqword;
        GV.MMX_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.MMX_ = 0;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+3;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.ImmediatSize = 8;
    }

}

/* ====================================================================
 *      0x 0f 3a 15
 * ==================================================================== */
void __bea_callspec__ pextrw2_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pextrw ");
        GV.MOD_= ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 6) & 0x3;
        if (GV.MOD_== 0x3) {
            GV.MemDecoration = Arg1dword;
        }
        else {
            GV.MemDecoration = Arg1word;
        }
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_ += GV.DECALAGE_EIP+3;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.ImmediatSize = 8;

    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 38 02
 * ==================================================================== */
void __bea_callspec__ phaddd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phaddd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phaddd ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 38 03
 * ==================================================================== */
void __bea_callspec__ phaddsw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phaddsw ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phaddsw ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 38 01
 * ==================================================================== */
void __bea_callspec__ phaddw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phaddw ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phaddw ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 38 41
 * ==================================================================== */
void __bea_callspec__ phminposuw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+HORIZONTAL_SEARCH;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phminposuw ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 05
 * ==================================================================== */
void __bea_callspec__ phsubw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phsubw ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phsubw ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 38 06
 * ==================================================================== */
void __bea_callspec__ phsubd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phsubd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phsubd ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 38 07
 * ==================================================================== */
void __bea_callspec__ phsubsw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phsubsw ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "phsubsw ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 3a 20
 * ==================================================================== */
void __bea_callspec__ pinsrb_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pinsrb ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.ImmediatSize = 8;

    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 3a 22
 * ==================================================================== */
void __bea_callspec__ pinsrd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+INSERTION_EXTRACTION;
        if (GV.REX.W_ == 0x1) {
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pinsrq ");
            GV.MemDecoration = Arg1qword;
        }
        else {
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pinsrd ");
            GV.MemDecoration = Arg1dword;
        }
        MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_ += GV.DECALAGE_EIP+3;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.ImmediatSize = 8;

    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f c4
 * ==================================================================== */
void __bea_callspec__ pinsrw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pinsrw ");
        GV.MemDecoration = Arg2word;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_ += GV.DECALAGE_EIP+3;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.ImmediatSize = 8;

    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pinsrw ");
        GV.MemDecoration = Arg2word;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.MMX_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.MMX_ = 0;
        GV.EIP_ += GV.DECALAGE_EIP+3;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.ImmediatSize = 8;
    }

}


/* ====================================================================
 *      0x 0f 38 3c
 * ==================================================================== */
void __bea_callspec__ pmaxsb_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_MINMAX;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmaxsb ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 3d
 * ==================================================================== */
void __bea_callspec__ pmaxsd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_MINMAX;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmaxsd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 3e
 * ==================================================================== */
void __bea_callspec__ pmaxuw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_MINMAX;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmaxuw ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 3f
 * ==================================================================== */
void __bea_callspec__ pmaxud_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_MINMAX;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmaxud ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 38
 * ==================================================================== */
void __bea_callspec__ pminsb_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_MINMAX;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pminsb ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 39
 * ==================================================================== */
void __bea_callspec__ pminsd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_MINMAX;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pminsd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 3a
 * ==================================================================== */
void __bea_callspec__ pminuw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_MINMAX;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pminuw ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* ====================================================================
 *      0x 0f 38 3b
 * ==================================================================== */
void __bea_callspec__ pminud_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_MINMAX;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pminud ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f da
 * ==================================================================== */
void __bea_callspec__ pminub_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pminub ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pminub ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f de
 * ==================================================================== */
void __bea_callspec__ pmaxub_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmaxub ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmaxub ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f ea
 * ==================================================================== */
void __bea_callspec__ pminsw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pminsw ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pminsw ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f ee
 * ==================================================================== */
void __bea_callspec__ pmaxsw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmaxsw ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmaxsw ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 38 04
 * ==================================================================== */
void __bea_callspec__ pmaddubsw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmaddubsw ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmaddubsw ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f d7
 * ==================================================================== */
void __bea_callspec__ pmovmskb_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {

        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovmskb ");
        GV.MemDecoration = Arg2dqword;
        GV.SSE_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.SSE_ = 0;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else {
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovmskb ");
        GV.MemDecoration = Arg2qword;
        GV.MMX_ = 1;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.MMX_ = 0;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_ += GV.DECALAGE_EIP+2;
    }

}


/* ====================================================================
 *      0x 0f 38 21
 * ==================================================================== */
void __bea_callspec__ pmovsxbd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovsxbd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 22
 * ==================================================================== */
void __bea_callspec__ pmovsxbq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovsxbq ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 20
 * ==================================================================== */
void __bea_callspec__ pmovsxbw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovsxbw ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 25
 * ==================================================================== */
void __bea_callspec__ pmovsxdq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovsxdq ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 23
 * ==================================================================== */
void __bea_callspec__ pmovsxwd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovsxwd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 24
 * ==================================================================== */
void __bea_callspec__ pmovsxwq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovsxwq ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 31
 * ==================================================================== */
void __bea_callspec__ pmovzxbd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovzxbd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 32
 * ==================================================================== */
void __bea_callspec__ pmovzxbq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovzxbq ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 30
 * ==================================================================== */
void __bea_callspec__ pmovzxbw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovzxbw ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 35
 * ==================================================================== */
void __bea_callspec__ pmovzxdq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovzxdq ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 33
 * ==================================================================== */
void __bea_callspec__ pmovzxwd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovzxwd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 34
 * ==================================================================== */
void __bea_callspec__ pmovzxwq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+CONVERSION_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmovzxwq ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 28
 * ==================================================================== */
void __bea_callspec__ pmuldq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmuldq ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 40
 * ==================================================================== */
void __bea_callspec__ pmulld_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmulld ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 38 0b
 * ==================================================================== */
void __bea_callspec__ pmulhrsw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmulhrsw ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmulhrsw ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f e4
 * ==================================================================== */
void __bea_callspec__ pmulhuw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmulhuw ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmulhuw ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f f4
 * ==================================================================== */
void __bea_callspec__ pmuludq_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmuludq ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pmuludq ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* =======================================
 *      0x 0f b8
 * ======================================= */
void __bea_callspec__ popcnt_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE42_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "popcnt ");
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm,114);
}


/* ====================================================================
 *      0x 0f f6
 * ==================================================================== */
void __bea_callspec__ psadbw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SIMD64bits;
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psadbw ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psadbw ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 38 00
 * ==================================================================== */
void __bea_callspec__ pshufb_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+SHUFFLE_UNPACK;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pshufb ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+SHUFFLE_UNPACK;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pshufb ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 70
 * ==================================================================== */
void __bea_callspec__ pshufw_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SIMD128bits;
    /* ========= 0xf3 */
    if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pshufhw ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.ImmediatSize = 8;
    }
    /* ========= 0xf2 */
    else if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pshuflw ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.ImmediatSize = 8;
    }

    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pshufd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.ImmediatSize = 8;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pshufw ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.ImmediatSize = 8;
    }
}

/* ====================================================================
 *      0x 0f 38 08
 * ==================================================================== */
void __bea_callspec__ psignb_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+PACKED_SIGN;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psignb ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+PACKED_SIGN;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psignb ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 38 0a
 * ==================================================================== */
void __bea_callspec__ psignd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+PACKED_SIGN;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psignd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+PACKED_SIGN;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psignd ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 38 09
 * ==================================================================== */
void __bea_callspec__ psignw_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+PACKED_SIGN;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psignw ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSSE3_INSTRUCTION+PACKED_SIGN;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psignw ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f fb
 * ==================================================================== */
void __bea_callspec__ psubq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SIMD128bits;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psubq ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SIMD128bits;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "psubq ");
        GV.MMX_ = 1;
        GxEx(pMyDisasm);
        GV.MMX_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 38 17
 * ==================================================================== */
void __bea_callspec__ ptest_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+PACKED_TEST;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ptest ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }

}

/* ====================================================================
 *      0x 0f 6c
 * ==================================================================== */
void __bea_callspec__ punpcklqdq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SIMD128bits;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpcklqdq ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }

}

/* ====================================================================
 *      0x 0f 6d
 * ==================================================================== */
void __bea_callspec__ punpckhqdq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SIMD128bits;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "punpckhqdq ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        FailDecode(pMyDisasm);
    }

}


/* ====================================================================
 *      0x 0f 53
 * ==================================================================== */
void __bea_callspec__ rcpps_(PDISASM pMyDisasm)
{
    /* ========== 0xf3 */
    if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "rcpss ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "rcpps ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 3a 09
 * ==================================================================== */
void __bea_callspec__ roundpd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+ROUND_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "roundpd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.ImmediatSize = 8;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 3a 08
 * ==================================================================== */
void __bea_callspec__ roundps_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+ROUND_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "roundps ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.ImmediatSize = 8;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 3a 0b
 * ==================================================================== */
void __bea_callspec__ roundsd_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+ROUND_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "roundsd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.ImmediatSize = 8;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 3a 0a
 * ==================================================================== */
void __bea_callspec__ roundss_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE41_INSTRUCTION+ROUND_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "roundpd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.ImmediatSize = 8;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* ====================================================================
 *      0x 0f 52
 * ==================================================================== */
void __bea_callspec__ rsqrtps_(PDISASM pMyDisasm)
{
    /* ========== 0xf3 */
    if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "rsqrtss ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "rsqrtps ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f c6
 * ==================================================================== */
void __bea_callspec__ shufps_(PDISASM pMyDisasm)
{

    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SHUFFLE_UNPACK;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "shufpd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+SHUFFLE_UNPACK;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "shufps ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    (*pMyDisasm).Argument1.AccessMode = READ;
    GV.EIP_++;
    if (!Security(0, pMyDisasm)) return;
    GV.third_arg = 1;
    (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
    (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
    (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument3.ArgSize = 8;
    GV.ImmediatSize = 8;
}


/* ====================================================================
 *      0x 0f 51
 * ==================================================================== */
void __bea_callspec__ sqrtps_VW(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sqrtsd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========= 0xf3 */
    else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sqrtss ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sqrtpd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "sqrtps ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 5c
 * ==================================================================== */
void __bea_callspec__ subps_VW(PDISASM pMyDisasm)
{
    /* ========= 0xf2 */
    if (GV.PrefRepne == 1) {
        (*pMyDisasm).Prefix.RepnePrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2qword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "subsd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========= 0xf3 */
    else if (GV.PrefRepe == 1) {
        (*pMyDisasm).Prefix.RepPrefix = MandatoryPrefix;
        GV.MemDecoration = Arg2dword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "subss ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    /* ========== 0x66 */
    else if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "subpd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "subps ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 2e
 * ==================================================================== */
void __bea_callspec__ ucomiss_VW(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if (GV.OperandSize == 16) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+COMPARISON_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ucomisd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+COMPARISON_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ucomiss ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 15
 * ==================================================================== */
void __bea_callspec__ unpckhps_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if (GV.OperandSize == 16) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SHUFFLE_UNPACK;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "unpckhpd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SHUFFLE_UNPACK;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "unpckhps ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}

/* ====================================================================
 *      0x 0f 14
 * ==================================================================== */
void __bea_callspec__ unpcklps_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SHUFFLE_UNPACK;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "unpcklpd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+SHUFFLE_UNPACK;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "unpcklps ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}


/* ====================================================================
 *      0x 0f 57
 * ==================================================================== */
void __bea_callspec__ xorps_VW(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if ((*pMyDisasm).Prefix.OperandSize == InUsePrefix) {
        GV.OperandSize = GV.OriginalOperandSize;
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE2_INSTRUCTION+LOGICAL_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "xorpd ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
    else {
        GV.MemDecoration = Arg2dqword;
        (*pMyDisasm).Instruction.Category = SSE_INSTRUCTION+LOGICAL_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "xorps ");
        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
    }
}
