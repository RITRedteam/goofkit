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

void __bea_callspec__ FailDecode(PDISASM pMyDisasm)
{
	(void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "??? ");
	GV.ERROR_OPCODE = 1;
}
/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ aaa_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "aaa ");
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 8;
        GV.EIP_++;
    };
}

/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ aad_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "aad ");
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 16;
        if (!Security(1, pMyDisasm)) return;
        GV.ImmediatSize = 8;
	if (*((UInt8*)(UIntPtr) (GV.EIP_+1)) != 0x0A) {
            (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_+1));
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_+1)));
            (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
            (*pMyDisasm).Argument2.ArgSize = 8;
        }
        GV.EIP_+=2;
    };
}

/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ aam_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "aam ");
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 16;
        if (!Security(1, pMyDisasm)) return;
        GV.ImmediatSize = 8;
        if (*((UInt8*)(UIntPtr) (GV.EIP_+1)) != 0x0A) {
            (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_+1));
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_+1)));
            (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
            (*pMyDisasm).Argument2.ArgSize = 8;
        }
        GV.EIP_+=2;
    };
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ aas_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Archi == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "aas ");
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 8;
        GV.EIP_++;
    };
}

/* =======================================
 *      00h
 * ======================================= */
void __bea_callspec__ add_EbGb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "add ");
    EbGb(pMyDisasm);
    FillFlags(pMyDisasm,5);
}

/* =======================================
 *      01h
 * ======================================= */
void __bea_callspec__ add_EvGv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "add ");
    EvGv(pMyDisasm);
    FillFlags(pMyDisasm,5);
}

/* =======================================
 *      02h
 * ======================================= */
void __bea_callspec__ add_GbEb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "add ");
    GbEb(pMyDisasm);
    FillFlags(pMyDisasm,5);
}

/* =======================================
 *      03h
 * ======================================= */
void __bea_callspec__ add_GvEv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "add ");
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm,5);
}

/* =======================================
 *      04h
 * ======================================= */
void __bea_callspec__ add_ALIb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "add ");
    ALIb(pMyDisasm);
    FillFlags(pMyDisasm,5);
}

/* =======================================
 *      05h
 * ======================================= */
void __bea_callspec__ add_eAX_Iv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "add ");
    eAX_Iv(pMyDisasm);
    FillFlags(pMyDisasm,5);
}

/* =======================================
 *      10h
 * ======================================= */
void __bea_callspec__ adc_EbGb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "adc ");
    EbGb(pMyDisasm);
    FillFlags(pMyDisasm,4);
}

/* =======================================
 *      11h
 * ======================================= */
void __bea_callspec__ adc_EvGv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "adc ");
    EvGv(pMyDisasm);
    FillFlags(pMyDisasm,4);
}

/* =======================================
 *      12h
 * ======================================= */
void __bea_callspec__ adc_GbEb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "adc ");
    GbEb(pMyDisasm);
    FillFlags(pMyDisasm,4);
}

/* =======================================
 *      13h
 * ======================================= */
void __bea_callspec__ adc_GvEv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "adc ");
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm,4);
}

/* =======================================
 *      14h
 * ======================================= */
void __bea_callspec__ adc_ALIb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "adc ");
    ALIb(pMyDisasm);
    FillFlags(pMyDisasm,4);
}

/* =======================================
 *      15h
 * ======================================= */
void __bea_callspec__ adc_eAX_Iv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "adc ");
    eAX_Iv(pMyDisasm);
    FillFlags(pMyDisasm,4);
}

/* =======================================
 *      20h
 * ======================================= */
void __bea_callspec__ and_EbGb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "and ");
    EbGb(pMyDisasm);
    FillFlags(pMyDisasm,6);
}

/* =======================================
 *      21h
 * ======================================= */
void __bea_callspec__ and_EvGv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "and ");
    EvGv(pMyDisasm);
    FillFlags(pMyDisasm,6);
}

/* =======================================
 *      22h
 * ======================================= */
void __bea_callspec__ and_GbEb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "and ");
    GbEb(pMyDisasm);
    FillFlags(pMyDisasm,6);
}

/* =======================================
 *      23h
 * ======================================= */
void __bea_callspec__ and_GvEv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "and ");
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm,6);
}

/* =======================================
 *      24h
 * ======================================= */
void __bea_callspec__ and_ALIb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "and ");
    ALIb(pMyDisasm);
    FillFlags(pMyDisasm,6);
}

/* =======================================
 *      25h
 * ======================================= */
void __bea_callspec__ and_eAX_Iv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+LOGICAL_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "and ");
    eAX_Iv(pMyDisasm);
    FillFlags(pMyDisasm,6);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ arpl_(PDISASM pMyDisasm)
{

    if (GV.Architecture == 64) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsxd ");
        GvEv(pMyDisasm);
        FillFlags(pMyDisasm,69);
    }
    else {
        (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "arpl ");
        GV.OperandSize = 16;
        EvGv(pMyDisasm);
        GV.OperandSize = 32;
        FillFlags(pMyDisasm,7);
    }

}

/* =======================================
 *      62h
 * ======================================= */
void __bea_callspec__ bound_(PDISASM pMyDisasm)
{

    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bound ");
        GvEv(pMyDisasm);
        GV.MemDecoration = Arg2dword;
        (*pMyDisasm).Argument1.AccessMode = READ;
        FillFlags(pMyDisasm,8);
    }

}

/* =======================================
 *      0fc8h
 * ======================================= */
void __bea_callspec__ bswap_eax(PDISASM pMyDisasm)
{

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bswap ");
    if (GV.OperandSize == 64) {
        (*pMyDisasm).Argument1.ArgSize = 64;
        if (GV.REX.B_ == 1) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[8];
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
        }
    }
    else if (GV.OperandSize == 32){
        (*pMyDisasm).Argument1.ArgSize = 32;
        if (GV.REX.B_ == 1) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[8];
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
        }
    }
    else {
        (*pMyDisasm).Argument1.ArgSize = 16;
        if (GV.REX.B_ == 1) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[8];
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
        }
    }
    GV.EIP_++;
    FillFlags(pMyDisasm,10);

}


/* =======================================
 *      0fc8h
 * ======================================= */
void __bea_callspec__ bswap_ecx(PDISASM pMyDisasm)
{

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bswap ");
    if (GV.OperandSize == 64) {
        (*pMyDisasm).Argument1.ArgSize = 64;
        if (GV.REX.B_ == 1) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[1+8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1+8];
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[1+0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1+0];
        }
    }
    else if (GV.OperandSize == 32){
        (*pMyDisasm).Argument1.ArgSize = 32;
        if (GV.REX.B_ == 1) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[1+8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1+8];
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[1+0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1+0];
        }
    }
    else {
        (*pMyDisasm).Argument1.ArgSize = 16;
        if (GV.REX.B_ == 1) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[1+8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1+8];
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[1+0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1+0];
        }
    }
    GV.EIP_++;
    FillFlags(pMyDisasm,10);

}


/* =======================================
 *      0fc8h
 * ======================================= */
void __bea_callspec__ bswap_edx(PDISASM pMyDisasm)
{

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bswap ");
    if (GV.OperandSize == 64) {
        (*pMyDisasm).Argument1.ArgSize = 64;
        if (GV.REX.B_ == 1) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[2+8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2+8];
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[2+0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2+0];
        }
    }
    else if (GV.OperandSize == 32){
        (*pMyDisasm).Argument1.ArgSize = 32;
        if (GV.REX.B_ == 1) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[2+8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2+8];
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[2+0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2+0];
        }
    }
    else {
        (*pMyDisasm).Argument1.ArgSize = 16;
        if (GV.REX.B_ == 1) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[2+8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2+8];
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[2+0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2+0];
        }
    }
    GV.EIP_++;
    FillFlags(pMyDisasm,10);

}


/* =======================================
 *      0fc8h
 * ======================================= */
void __bea_callspec__ bswap_ebx(PDISASM pMyDisasm)
{

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bswap ");
    if (GV.OperandSize == 64) {
        (*pMyDisasm).Argument1.ArgSize = 64;
        if (GV.REX.B_ == 1) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[3+8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3+8];
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[3+0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3+0];
        }
    }
    else if (GV.OperandSize == 32){
        (*pMyDisasm).Argument1.ArgSize = 32;
        if (GV.REX.B_ == 1) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[3+8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3+8];
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[3+0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3+0];
        }
    }
    else {
        (*pMyDisasm).Argument1.ArgSize = 16;
        if (GV.REX.B_ == 1) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[3+8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3+8];
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[3+0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3+0];
        }
    }
    GV.EIP_++;
    FillFlags(pMyDisasm,10);

}


/* =======================================
 *      0fc8h
 * ======================================= */
void __bea_callspec__ bswap_esp(PDISASM pMyDisasm)
{

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bswap ");
    if (GV.OperandSize == 64) {
        (*pMyDisasm).Argument1.ArgSize = 64;
        if (GV.REX.B_ == 1) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[4+8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4+8];
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[4+0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4+0];
        }
    }
    else if (GV.OperandSize == 32){
        (*pMyDisasm).Argument1.ArgSize = 32;
        if (GV.REX.B_ == 1) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[4+8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4+8];
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[4+0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4+0];
        }
    }
    else {
        (*pMyDisasm).Argument1.ArgSize = 16;
        if (GV.REX.B_ == 1) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[4+8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4+8];
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[4+0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4+0];
        }
    }
    GV.EIP_++;
    FillFlags(pMyDisasm,10);

}


/* =======================================
 *      0fc8h
 * ======================================= */
void __bea_callspec__ bswap_ebp(PDISASM pMyDisasm)
{

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bswap ");
    if (GV.OperandSize == 64) {
        (*pMyDisasm).Argument1.ArgSize = 64;
        if (GV.REX.B_ == 1) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[5+8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5+8];
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[5+0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5+0];
        }
    }
    else if (GV.OperandSize == 32){
        (*pMyDisasm).Argument1.ArgSize = 32;
        if (GV.REX.B_ == 1) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[5+8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5+8];
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[5+0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5+0];
        }
    }
    else {
        (*pMyDisasm).Argument1.ArgSize = 16;
        if (GV.REX.B_ == 1) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[5+8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5+8];
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[5+0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5+0];
        }
    }
    GV.EIP_++;
    FillFlags(pMyDisasm,10);

}


/* =======================================
 *      0fc8h
 * ======================================= */
void __bea_callspec__ bswap_esi(PDISASM pMyDisasm)
{

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bswap ");
    if (GV.OperandSize == 64) {
        (*pMyDisasm).Argument1.ArgSize = 64;
        if (GV.REX.B_ == 1) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[6+8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6+8];
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[6+0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6+0];
        }
    }
    else if (GV.OperandSize == 32){
        (*pMyDisasm).Argument1.ArgSize = 32;
        if (GV.REX.B_ == 1) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[6+8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6+8];
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[6+0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6+0];
        }
    }
    else {
        (*pMyDisasm).Argument1.ArgSize = 16;
        if (GV.REX.B_ == 1) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[6+8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6+8];
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[6+0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6+0];
        }
    }
    GV.EIP_++;
    FillFlags(pMyDisasm,10);

}


/* =======================================
 *      0fc8h
 * ======================================= */
void __bea_callspec__ bswap_edi(PDISASM pMyDisasm)
{

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bswap ");
    if (GV.OperandSize == 64) {
        (*pMyDisasm).Argument1.ArgSize = 64;
        if (GV.REX.B_ == 1) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[7+8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7+8];
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[7+0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7+0];
        }
    }
    else if (GV.OperandSize == 32){
        (*pMyDisasm).Argument1.ArgSize = 32;
        if (GV.REX.B_ == 1) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[7+8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7+8];
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[7+0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7+0];
        }
    }
    else {
        (*pMyDisasm).Argument1.ArgSize = 16;
        if (GV.REX.B_ == 1) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[7+8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7+8];
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[7+0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7+0];
        }
    }
    GV.EIP_++;
    FillFlags(pMyDisasm,10);

}

/* =======================================
 *      0fbch
 * ======================================= */
void __bea_callspec__ bsf_GvEv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bsf ");
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm,9);
}

/* =======================================
 *      0fbdh
 * ======================================= */
void __bea_callspec__ bsr_GvEv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bsr ");
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm,9);
}

/* =======================================
 *      0fbbh
 * ======================================= */
void __bea_callspec__ btc_EvGv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;

    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "btc ");
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm,11);
}

/* =======================================
 *      0fa3h
 * ======================================= */
void __bea_callspec__ bt_EvGv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bt ");
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm,11);
}

/* =======================================
 *      0fb3h
 * ======================================= */
void __bea_callspec__ btr_EvGv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "btr ");
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm,11);
}

/* =======================================
 *      0fabh
 * ======================================= */
void __bea_callspec__ bts_EvGv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+BIT_UInt8;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "bts ");
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm,11);
}

/* =======================================
 *      e8h
 * ======================================= */
void __bea_callspec__ call_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    long MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = CallType;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "call ");
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1))+5+GV.NB_PREFIX;
        CalculateRelativeAddress(&MyAddress,(Int64) MyNumber, pMyDisasm);
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
        if (MyAddress >= 0x80000000) {
            (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
        }
        else {
            (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1))+3+GV.NB_PREFIX;
        CalculateRelativeAddress(&MyAddress,(Int64) MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;
        (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
    }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ callf_(PDISASM pMyDisasm)
{
    UInt32 MyNumber;
    size_t i = 0;
    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
        (*pMyDisasm).Instruction.BranchType = CallType;
        if (GV.SYNTAX_ == ATSyntax) {
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lcall ");
            (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic,"\x24");
            i++;
        }
        else {
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "call far ");
        }
        if (GV.OperandSize ==32) {
            if (!Security(7, pMyDisasm)) return;
            MyNumber = *((UInt16*)(UIntPtr) (GV.EIP_+5));
            i += CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument1.ArgMnemonic+i, "%.4X",(Int64) MyNumber);
        }
        else {
            if (!Security(5, pMyDisasm)) return;
            MyNumber = *((UInt16*)(UIntPtr) (GV.EIP_+3));
            i += CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument1.ArgMnemonic+i, "%.4X",(Int64) MyNumber);
        }
        if (GV.SYNTAX_ == ATSyntax) {
            (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic+i, " , \x24");
            i+=4;
        }
        else {
            (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic+i, " : ");
            i+=3;
        }
        MyNumber = *((UInt32*)(UIntPtr) (GV.EIP_+1));
        if (GV.OperandSize == 16) {
            MyNumber = MyNumber & 0xffff;
        }
        i += CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument1.ArgMnemonic+i, "%.8X",(Int64) MyNumber);
        if (GV.OperandSize == 32) {
            GV.EIP_+=7;
        }
        else {
            GV.EIP_+=5;
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG4;

    }
}

/* =======================================
 *      99h
 * ======================================= */
void __bea_callspec__ cdq_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    if (GV.OperandSize == 64) {
        if (GV.SYNTAX_ == ATSyntax) {
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cqto ");
        }
        else {
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cqo ");
        }
        (*pMyDisasm).Argument1.ArgSize = 64;
    }
    else if (GV.OperandSize ==32) {
        if (GV.SYNTAX_ == ATSyntax) {
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cltd ");
        }
        else {
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cdq ");
        }
        (*pMyDisasm).Argument1.ArgSize = 32;
    }
    else {
        if (GV.SYNTAX_ == ATSyntax) {
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cwtd ");
        }
        else {
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cwd ");
        }
        (*pMyDisasm).Argument1.ArgSize = 16;
    }
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ clts_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "clts ");
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+CR_REG+REG0;
    (*pMyDisasm).Argument1.ArgSize = 1;
    FillFlags(pMyDisasm, 17);
    GV.EIP_++;
}


/* =======================================
 *      F5h
 * ======================================= */
void __bea_callspec__ cmc_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmc ");
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+SPECIAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgSize = 1;
    FillFlags(pMyDisasm, 18);
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovo_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovo ");
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovno_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovno ");
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovb ");
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovnb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovnb ");
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmove_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmove ");
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovne_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovne ");
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovbe_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovbe ");
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovnbe_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovnbe ");
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovs_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovs ");
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovns_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovns ");
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovp_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovp ");
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovnp_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovnp ");
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovl_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovl ");
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovnl_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovnl ");
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovle_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovle ");
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmovnle_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmovnle ");
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm, 19);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmpx_EbGb(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpxchg ");
    EbGb(pMyDisasm);
    FillFlags(pMyDisasm,22);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cmpx_EvGv(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
        (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpxchg ");
    EvGv(pMyDisasm);
    FillFlags(pMyDisasm,22);
}

/* =======================================
 *      38h
 * ======================================= */
void __bea_callspec__ cmp_EbGb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmp ");
    EbGb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm,20);
}

/* =======================================
 *      39h
 * ======================================= */
void __bea_callspec__ cmp_EvGv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmp ");
    EvGv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm,20);
}

/* =======================================
 *      3ah
 * ======================================= */
void __bea_callspec__ cmp_GbEb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmp ");
    GbEb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm,20);
}

/* =======================================
 *      3bh
 * ======================================= */
void __bea_callspec__ cmp_GvEv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmp ");
    GvEv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm,20);
}

/* =======================================
 *      3ch
 * ======================================= */
void __bea_callspec__ cmp_ALIb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmp ");
    ALIb(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm,20);
}

/* =======================================
 *      3dh
 * ======================================= */
void __bea_callspec__ cmp_eAX_Iv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmp ");
    eAX_Iv(pMyDisasm);
    (*pMyDisasm).Argument1.AccessMode = READ;
    FillFlags(pMyDisasm,20);
}

/* =======================================
 *      a6h
 * ======================================= */
void __bea_callspec__ cmpsb_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpsb ");
    (*pMyDisasm).Argument1.ArgType = MEMORY_TYPE;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE;
    (*pMyDisasm).Argument2.ArgSize = 8;
    (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
    FillFlags(pMyDisasm,21);
    GV.EIP_++;
}

/* =======================================
 *      a7h
 * ======================================= */
void __bea_callspec__ cmps_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    (*pMyDisasm).Argument1.ArgType = MEMORY_TYPE;
    (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE;
    (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
    if (GV.Architecture == 64) {
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpsq ");
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 64;
    }
    else if (GV.OperandSize == 32) {
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpsd ");
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else {
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cmpsw ");
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }
    FillFlags(pMyDisasm,21);
    GV.EIP_++;
}

/* =======================================
 *      98h
 * ======================================= */
void __bea_callspec__ cwde_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    if (GV.OperandSize == 64) {
        if (GV.SYNTAX_ == ATSyntax) {
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cltq ");
        }
        else {
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cdqe ");
        }
        (*pMyDisasm).Argument1.ArgSize = 64;
    }
    else if (GV.OperandSize == 32) {
        if (GV.SYNTAX_ == ATSyntax) {
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cwtl ");
        }
        else {
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cwde ");
        }
        (*pMyDisasm).Argument1.ArgSize = 32;
    }
    else {
        if (GV.SYNTAX_ == ATSyntax) {
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cbtw ");
        }
        else {
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cbw ");
        }
        (*pMyDisasm).Argument1.ArgSize = 16;
    }
    GV.EIP_++;
}

/* =======================================
 *      f8h
 * ======================================= */
void __bea_callspec__ clc_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+SPECIAL_REG+REG0;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "clc ");
    (*pMyDisasm).Argument1.ArgSize = 1;
    FillFlags(pMyDisasm, 14);
    GV.EIP_++;
}

/* =======================================
 *      f8h
 * ======================================= */
void __bea_callspec__ cld_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+SPECIAL_REG+REG0;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cld ");
    (*pMyDisasm).Argument1.ArgSize = 1;
    FillFlags(pMyDisasm, 15);
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ cli_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+SPECIAL_REG+REG0;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cli ");
    (*pMyDisasm).Argument1.ArgSize = 1;
    FillFlags(pMyDisasm, 16);
    GV.EIP_++;
}

/* =======================================
 *      0fa2h
 * ======================================= */
void __bea_callspec__ cpuid_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+MISCELLANEOUS_INSTRUCTION;
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0+REG1+REG2+REG3;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "cpuid ");
    (*pMyDisasm).Argument1.ArgSize = 32;
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ daa_(PDISASM pMyDisasm)
{

    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "daa ");
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 8;
        FillFlags(pMyDisasm,28);
        GV.EIP_++;
    }

}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ das_(PDISASM pMyDisasm)
{

    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "das ");
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 8;
        FillFlags(pMyDisasm,29);
        GV.EIP_++;
    }

}

/* =======================================
 *      48h
 * ======================================= */
void __bea_callspec__ dec_eax(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(0, pMyDisasm)) return;
        GV.REX.W_ = 1;
        GV.REX.R_ = 0;
        GV.REX.X_ = 0;
        GV.REX.B_ = 0;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        GV.OperandSize = 64;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "dec ");
        if (GV.OperandSize == 32) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 30);
    }
}

/* =======================================
 *      49h
 * ======================================= */
void __bea_callspec__ dec_ecx(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(0, pMyDisasm)) return;
        GV.REX.W_ = 1;
        GV.REX.R_ = 0;
        GV.REX.X_ = 0;
        GV.REX.B_ = 1;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        GV.OperandSize = 64;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "dec ");
        if (GV.OperandSize == 32) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[1]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1+0];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[1]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1+0];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 30);
    }
}

/* =======================================
 *      4ah
 * ======================================= */
void __bea_callspec__ dec_edx(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(0, pMyDisasm)) return;
        GV.REX.W_ = 1;
        GV.REX.R_ = 0;
        GV.REX.X_ = 1;
        GV.REX.B_ = 0;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        GV.OperandSize = 64;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "dec ");
        if (GV.OperandSize == 32) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[2]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2+0];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[2]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2+0];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 30);
    }
}

/* =======================================
 *      4bh
 * ======================================= */
void __bea_callspec__ dec_ebx(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(0, pMyDisasm)) return;
        GV.REX.W_ = 1;
        GV.REX.R_ = 0;
        GV.REX.X_ = 1;
        GV.REX.B_ = 1;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        GV.OperandSize = 64;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "dec ");
        if (GV.OperandSize == 32) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[3]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3+0];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[3]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3+0];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 30);
    }
}

/* =======================================
 *      4ch
 * ======================================= */
void __bea_callspec__ dec_esp(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(0, pMyDisasm)) return;
        GV.REX.W_ = 1;
        GV.REX.R_ = 1;
        GV.REX.X_ = 0;
        GV.REX.B_ = 0;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        GV.OperandSize = 64;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "dec ");
        if (GV.OperandSize == 32) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[4]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4+0];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[4]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4+0];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 30);
    }
}

/* =======================================
 *      4dh
 * ======================================= */
void __bea_callspec__ dec_ebp(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(0, pMyDisasm)) return;
        GV.REX.W_ = 1;
        GV.REX.R_ = 1;
        GV.REX.X_ = 0;
        GV.REX.B_ = 1;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        GV.OperandSize = 64;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "dec ");
        if (GV.OperandSize == 32) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[5]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5+0];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[5]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5+0];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 30);
    }
}

/* =======================================
 *      4eh
 * ======================================= */
void __bea_callspec__ dec_esi(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(0, pMyDisasm)) return;
        GV.REX.W_ = 1;
        GV.REX.R_ = 1;
        GV.REX.X_ = 1;
        GV.REX.B_ = 0;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        GV.OperandSize = 64;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "dec ");
        if (GV.OperandSize == 32) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[6]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6+0];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[6]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6+0];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 30);
    }
}

/* =======================================
 *      4fh
 * ======================================= */
void __bea_callspec__ dec_edi(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(0, pMyDisasm)) return;
        GV.REX.W_ = 1;
        GV.REX.R_ = 1;
        GV.REX.X_ = 1;
        GV.REX.B_ = 1;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        GV.OperandSize = 64;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "dec ");
        if (GV.OperandSize == 32) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[7]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7+0];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[7]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7+0];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 30);
    }
}

/* =======================================
 *      0c8h
 * ======================================= */
void __bea_callspec__ enter_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "enter ");
    (void) CopyFormattedNumber (pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic,"%.4X",(Int64) *((UInt16*)(UIntPtr) (GV.EIP_+1)));
    (*pMyDisasm).Argument1.ArgSize = 16;
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (void) CopyFormattedNumber (pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic,"%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_+3)));
    (*pMyDisasm).Argument2.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    GV.EIP_+=4;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ femms_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = AMD_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "femms ");
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ hlt_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "hlt ");
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ invd_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "invd ");
    GV.EIP_++;
}

/* =======================================
 *      40h
 * ======================================= */
void __bea_callspec__ inc_eax(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(0, pMyDisasm)) return;
        GV.REX.W_ = 0;
        GV.REX.R_ = 0;
        GV.REX.X_ = 0;
        GV.REX.B_ = 0;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "inc ");
        if (GV.OperandSize == 32) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 40);
    }
}

/* =======================================
 *      41h
 * ======================================= */
void __bea_callspec__ inc_ecx(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(0, pMyDisasm)) return;
        GV.REX.W_ = 0;
        GV.REX.R_ = 0;
        GV.REX.X_ = 0;
        GV.REX.B_ = 1;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "inc ");
        if (GV.OperandSize == 32) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[1]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1+0];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[1]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[1+0];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 40);
    }
}

/* =======================================
 *      42h
 * ======================================= */
void __bea_callspec__ inc_edx(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(0, pMyDisasm)) return;
        GV.REX.W_ = 0;
        GV.REX.R_ = 0;
        GV.REX.X_ = 1;
        GV.REX.B_ = 0;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "inc ");
        if (GV.OperandSize == 32) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[2]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2+0];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[2]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2+0];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 40);
    }
}

/* =======================================
 *      43h
 * ======================================= */
void __bea_callspec__ inc_ebx(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(0, pMyDisasm)) return;
        GV.REX.W_ = 0;
        GV.REX.R_ = 0;
        GV.REX.X_ = 1;
        GV.REX.B_ = 1;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "inc ");
        if (GV.OperandSize == 32) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[3]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3+0];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[3]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[3+0];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 40);
    }
}

/* =======================================
 *      44h
 * ======================================= */
void __bea_callspec__ inc_esp(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(0, pMyDisasm)) return;
        GV.REX.W_ = 0;
        GV.REX.R_ = 1;
        GV.REX.X_ = 0;
        GV.REX.B_ = 0;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "inc ");
        if (GV.OperandSize == 32) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[4]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4+0];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[4]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[4+0];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 40);
    }
}

/* =======================================
 *      45h
 * ======================================= */
void __bea_callspec__ inc_ebp(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(0, pMyDisasm)) return;
        GV.REX.W_ = 0;
        GV.REX.R_ = 1;
        GV.REX.X_ = 0;
        GV.REX.B_ = 1;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "inc ");
        if (GV.OperandSize == 32) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[5]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5+0];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[5]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[5+0];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 40);
    }
}

/* =======================================
 *      46h
 * ======================================= */
void __bea_callspec__ inc_esi(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(0, pMyDisasm)) return;
        GV.REX.W_ = 0;
        GV.REX.R_ = 1;
        GV.REX.X_ = 1;
        GV.REX.B_ = 0;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "inc ");
        if (GV.OperandSize == 32) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[6]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6+0];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[6]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[6+0];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 40);
    }
}

/* =======================================
 *      47h
 * ======================================= */
void __bea_callspec__ inc_edi(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        if (!Security(0, pMyDisasm)) return;
        GV.REX.W_ = 0;
        GV.REX.R_ = 1;
        GV.REX.X_ = 1;
        GV.REX.B_ = 1;
        GV.REX.state = InUsePrefix;
        GV.EIP_++;
        GV.NB_PREFIX++;
        (*pMyDisasm).Prefix.Number++;
        (*pMyDisasm).Instruction.Opcode = *((UInt8*) (UIntPtr)GV.EIP_);
        (void) opcode_map1[*((UInt8*) (UIntPtr)GV.EIP_)](pMyDisasm);
        GV.OperandSize = 32;

    }
    else {
        if ((*pMyDisasm).Prefix.LockPrefix == InvalidPrefix) {
            (*pMyDisasm).Prefix.LockPrefix = InUsePrefix;
        }
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "inc ");
        if (GV.OperandSize == 32) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[7]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7+0];
            (*pMyDisasm).Argument1.ArgSize = 32;
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[7]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[7+0];
            (*pMyDisasm).Argument1.ArgSize = 16;
        }
        GV.EIP_++;
        FillFlags(pMyDisasm, 40);
    }
}
/* =======================================
 *  0xcf
 * ======================================= */
void __bea_callspec__ iret_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = RetType;
    if (GV.OperandSize ==64) {
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "iretq ");
    }
    else if (GV.OperandSize == 32) {
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "iretd ");
    }
    else {
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "iretw ");
    }
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ in_ALDX(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "in ");
    (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers8Bits[0]);
    (void) strcpy ((char*) (*pMyDisasm).Argument2.ArgMnemonic, Registers16Bits[2]);
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2];
    (*pMyDisasm).Argument2.ArgSize = 16;
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ in_ALIb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "in ");
    ALIb(pMyDisasm);
}

/* =======================================
 *      0xe5
 * ======================================= */
void __bea_callspec__ in_eAX_Ib(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "in ");
    if (!Security(1, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_+1)));
    (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[0]);
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
    (*pMyDisasm).Argument1.ArgSize = 32;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
    GV.EIP_+=2;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ insb_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.RepnePrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.RepPrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "insb ");
    (*pMyDisasm).Argument1.ArgType = MEMORY_TYPE;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
    (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REG2;
    (*pMyDisasm).Argument2.ArgSize = 16;
    GV.EIP_++;
    FillFlags(pMyDisasm, 41);


}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ ins_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.RepnePrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.RepPrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    if (GV.OperandSize >= 32) {
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "insd ");
        (*pMyDisasm).Argument1.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
        (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REG2;
        (*pMyDisasm).Argument2.ArgSize = 16;
        GV.EIP_++;
        FillFlags(pMyDisasm, 41);
    }
    else {
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "insw ");
        (*pMyDisasm).Argument1.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
        (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REG2;
        (*pMyDisasm).Argument2.ArgSize = 16;
        GV.EIP_++;
        FillFlags(pMyDisasm, 41);
    }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ into_(PDISASM pMyDisasm)
{
    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "into ");
        GV.EIP_++;
        FillFlags(pMyDisasm, 43);
    }
}

/* =======================================
 *      0edh
 * ======================================= */
void __bea_callspec__ in_eAX(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+InOutINSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "in ");
    if (GV.OperandSize >=32) {
        (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[0]);
        (void) strcpy ((char*) (*pMyDisasm).Argument2.ArgMnemonic, Registers16Bits[2]);
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2];
        (*pMyDisasm).Argument2.ArgSize = 16;
    }
    else {
        (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[0]);
        (void) strcpy ((char*) (*pMyDisasm).Argument2.ArgMnemonic, Registers16Bits[2]);
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[0];
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REGS[2];
        (*pMyDisasm).Argument2.ArgSize = 16;
    }
    GV.EIP_++;
}

/* =======================================
 *      0cdh
 * ======================================= */
void __bea_callspec__ int_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "int ");
    if (!Security(1, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_+1)));
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument1.ArgSize = 8;
    GV.EIP_+=2;
    FillFlags(pMyDisasm, 42);
}

/* =======================================
 *      0f1h
 * ======================================= */
void __bea_callspec__ int1_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "int1 ");
    GV.EIP_++;
    FillFlags(pMyDisasm, 42);
}

/* =======================================
 *      0cch
 * ======================================= */
void __bea_callspec__ int3_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "int3 ");
    GV.EIP_++;
    FillFlags(pMyDisasm, 42);
}

/* =======================================
 *      69h
 * ======================================= */
void __bea_callspec__ imul_GvEvIv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "imul ");
    if (GV.OperandSize >= 32) {
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg2qword;
        }
        else {
            GV.MemDecoration = Arg2dword;
        }
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP+6;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt32*)(UIntPtr) (GV.EIP_- 4));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.8X",(Int64) *((UInt32*)(UIntPtr) (GV.EIP_- 4)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 32;
        GV.ImmediatSize = 32;
        FillFlags(pMyDisasm, 38);
    }
    else {
        GV.MemDecoration = Arg2word;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP+4;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt16*)(UIntPtr) (GV.EIP_- 2));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.4X",(Int64) *((UInt16*)(UIntPtr) (GV.EIP_- 2)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 16;
        GV.ImmediatSize = 16;
        FillFlags(pMyDisasm, 38);
    }
}

/* =======================================
 *      6bh
 * ======================================= */
void __bea_callspec__ imul_GvEvIb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "imul ");
    if (GV.OperandSize >= 32) {
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg2qword;
        }
        else {
            GV.MemDecoration = Arg2dword;
        }
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP+3;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.ImmediatSize = 8;
        FillFlags(pMyDisasm, 38);
    }
    else {
        GV.MemDecoration = Arg2word;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP+3;
        if (!Security(0, pMyDisasm)) return;
        GV.third_arg = 1;
        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
        (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
        (*pMyDisasm).Argument3.ArgSize = 8;
        GV.ImmediatSize = 8;
        FillFlags(pMyDisasm, 38);
    }
}

/* =======================================
 *      0fafh
 * ======================================= */
void __bea_callspec__ imul_GvEv(PDISASM pMyDisasm)
{

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+ARITHMETIC_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "imul ");
    GvEv(pMyDisasm);
    FillFlags(pMyDisasm,38);
}

/* =======================================
 *      70h
 * ======================================= */
void __bea_callspec__ jo_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;

    signed long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JO;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jo ");
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
    }
    else {
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,49);
}

/* =======================================
 *      71h
 * ======================================= */
void __bea_callspec__ jno_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    signed long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JNO;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jno ");
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
    }
    else {
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,49);
}

/* =======================================
 *      72h
 * ======================================= */
void __bea_callspec__ jc_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    signed long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JC;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jc ");
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
    }
    else {
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,49);
}

/* =======================================
 *      73h
 * ======================================= */
void __bea_callspec__ jnc_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    signed long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JNC;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jnc ");
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
    }
    else {
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,49);
}
/* =======================================
 *      74h
 * ======================================= */
void __bea_callspec__ je_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    signed long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JE;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "je ");
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
    }
    else {
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,49);
}

/* =======================================
 *      75h
 * ======================================= */
void __bea_callspec__ jne_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    signed long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JNE;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jne ");
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
    }
    else {
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,49);
}

/* =======================================
 *      76h
 * ======================================= */
void __bea_callspec__ jbe_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    signed long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JB;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jbe ");
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
    }
    else {
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,49);
}

/* =======================================
 *      77h
 * ======================================= */
void __bea_callspec__ jnbe_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    signed long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JNB;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jnbe ");
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
    }
    else {
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,49);
}

/* =======================================
 *      78h
 * ======================================= */
void __bea_callspec__ js_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    signed long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JS;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "js ");
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
    }
    else {
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,49);
}

/* =======================================
 *      79h
 * ======================================= */
void __bea_callspec__ jns_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    signed long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JNS;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jns ");
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
    }
    else {
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,49);
}

/* =======================================
 *      7ah
 * ======================================= */
void __bea_callspec__ jp_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    signed long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JP;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jp ");
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
    }
    else {
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,49);
}

/* =======================================
 *      7bh
 * ======================================= */
void __bea_callspec__ jnp_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    signed long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JNP;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jnp ");
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
    }
    else {
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,49);
}

/* =======================================
 *      7ch
 * ======================================= */
void __bea_callspec__ jl_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    signed long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JL;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jl ");
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
    }
    else {
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,49);
}

/* =======================================
 *      7dh
 * ======================================= */
void __bea_callspec__ jnl_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    signed long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JNL;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jnl ");
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
    }
    else {
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,49);
}

/* =======================================
 *      7eh
 * ======================================= */
void __bea_callspec__ jle_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    signed long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JL;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jle ");
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
    }
    else {
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,49);
}

/* =======================================
 *      7fh
 * ======================================= */
void __bea_callspec__ jnle_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    signed long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JG;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jnle ");
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
    }
    else {
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,49);
}


/* =======================================
 *      0f80h
 * ======================================= */
void __bea_callspec__ jo_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JO;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jo ");
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
        }
        else {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,49);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,49);
    }
}


/* =======================================
 *      0f81h
 * ======================================= */
void __bea_callspec__ jno_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JNO;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jno ");
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
        }
        else {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,49);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,49);
    }
}

/* =======================================
 *      0f82h
 * ======================================= */
void __bea_callspec__ jc_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JC;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jc ");
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
        }
        else {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,49);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,49);
    }
}

/* =======================================
 *      0f83h
 * ======================================= */
void __bea_callspec__ jnc_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JNC;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jnc ");
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
        }
        else {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,49);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,49);
    }
}

/* =======================================
 *      0f84h
 * ======================================= */
void __bea_callspec__ je_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JE;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "je ");
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
        }
        else {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,49);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,49);
    }
}

/* =======================================
 *      0f85h
 * ======================================= */
void __bea_callspec__ jne_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JNE;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jne ");
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
        }
        else {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,49);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,49);
    }
}
/* =======================================
 *      0f86h
 * ======================================= */
void __bea_callspec__ jbe_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JB;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jbe ");
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
        }
        else {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,49);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,49);
    }
}


/* =======================================
 *      0f87h
 * ======================================= */
void __bea_callspec__ ja_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JA;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ja ");
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
        }
        else {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,49);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,49);
    }
}

/* =======================================
 *      0f88h
 * ======================================= */
void __bea_callspec__ js_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JS;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "js ");
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
        }
        else {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,49);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,49);
    }
}

/* =======================================
 *      0f89h
 * ======================================= */
void __bea_callspec__ jns_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JNS;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jns ");
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
        }
        else {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,49);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,49);
    }
}

/* =======================================
 *      0f8ah
 * ======================================= */
void __bea_callspec__ jp_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JP;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jp ");
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
        }
        else {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,49);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,49);
    }
}

/* =======================================
 *      0f8bh
 * ======================================= */
void __bea_callspec__ jnp_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JNP;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jnp ");
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
        }
        else {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,49);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,49);
    }
}

/* =======================================
 *      0f8ch
 * ======================================= */
void __bea_callspec__ jl_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JL;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jl ");
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
        }
        else {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,49);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,49);
    }
}

/* =======================================
 *      0f8dh
 * ======================================= */
void __bea_callspec__ jnl_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    long MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JNL;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jnl ");
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
        }
        else {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,49);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,49);
    }
}

/* =======================================
 *      0f8eh
 * ======================================= */
void __bea_callspec__ jle_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int32 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JNG;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jng ");
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
        }
        else {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,49);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,49);
    }
}

/* =======================================
 *      0f8fh
 * ======================================= */
void __bea_callspec__ jnle_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int64 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JG;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jg ");
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+6+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
        }
        else {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,49);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+4+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,49);
    }
}

/* =======================================
 *      0e3h
 * ======================================= */
void __bea_callspec__ jecxz_(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    Int64 MyNumber;
    if ((*pMyDisasm).Prefix.CSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.CSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchNotTaken = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.DSPrefix == InUsePrefix) {
        (*pMyDisasm).Prefix.DSPrefix = NotUsedPrefix;
        (*pMyDisasm).Prefix.BranchTaken = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JECXZ;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    if (GV.AddressSize == 64) {
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jrcxz ");
    }
    else if (GV.AddressSize == 32) {
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jecxz ");
    }
    else {
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jcxz ");
    }
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
        }
        else {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
        FillFlags(pMyDisasm,49);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
        FillFlags(pMyDisasm,49);
    }
}

/* =======================================
 *      0e9h
 * ======================================= */
void __bea_callspec__ jmp_near(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    long MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jmp ");
    if (GV.OperandSize >= 32) {
        if (!Security(5, pMyDisasm)) return;
        MyNumber = *((Int32*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+5+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
        }
        else {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        }
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;

        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=5;
        FillFlags(pMyDisasm,49);
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyNumber = *((Int16*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+3+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=3;
        FillFlags(pMyDisasm,49);
    }
}


/* =======================================
 *      0ebh
 * ======================================= */
void __bea_callspec__ jmp_short(PDISASM pMyDisasm)
{
    UInt64 MyAddress = 0;
    signed long MyNumber = 0;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JmpType;
    (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jmp ");
    if (!Security(1, pMyDisasm)) return;
    MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
    CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
    if (GV.OperandSize == 16) MyAddress = MyAddress & 0xffff;
    if (MyAddress >= W64LIT (0x100000000)) {
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
    }
    else {
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
    }
    (*pMyDisasm).Argument1.ArgType = CONSTANT_TYPE+RELATIVE_;
    (*pMyDisasm).Argument1.AccessMode = READ;
    (*pMyDisasm).Instruction.AddrValue = MyAddress;
    GV.EIP_+=2;
    FillFlags(pMyDisasm,49);
}


/* =======================================
 *
 * ======================================= */
void __bea_callspec__ jmp_far(PDISASM pMyDisasm)
{
    UInt32 MyNumber;
    size_t i = 0;
    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
        (*pMyDisasm).Instruction.BranchType = JmpType;
        (*pMyDisasm).Argument1.AccessMode = READ;
        if (GV.SYNTAX_ == ATSyntax) {
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ljmp ");
            (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic,"\x24");
            i++;
        }
        else {
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "jmp far ");
        }
        if (GV.OperandSize ==32) {
            if (!Security(7, pMyDisasm)) return;
            MyNumber = *((UInt16*)(UIntPtr) (GV.EIP_+5));
            i += CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument1.ArgMnemonic+i, "%.4X",(Int64) MyNumber);
        }
        else {
            if (!Security(5, pMyDisasm)) return;
            MyNumber = *((UInt16*)(UIntPtr) (GV.EIP_+3));
            i += CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument1.ArgMnemonic+i, "%.4X",(Int64) MyNumber);
        }
        if (GV.SYNTAX_ == ATSyntax) {
            (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic+i, " , \x24");
            i+=4;
        }
        else {
            (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic+i, " : ");
            i+=3;
        }
        MyNumber = *((UInt32*)(UIntPtr) (GV.EIP_+1));
        if (GV.OperandSize == 16) {
            MyNumber = MyNumber & 0xffff;
        }
        i += CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument1.ArgMnemonic+i, "%.8X",(Int64) MyNumber);
        if (GV.OperandSize == 32) {
            GV.EIP_+=7;
        }
        else {
            GV.EIP_+=5;
        }
    }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ lahf_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+FLAG_CONTROL_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lahf ");
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+SPECIAL_REG+REG0;
    (*pMyDisasm).Argument2.ArgSize = 8;
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ lar_GvEw(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lar ");
    GvEw(pMyDisasm);
    FillFlags(pMyDisasm, 53);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ lds_GvM(PDISASM pMyDisasm)
{
    /* if MOD == 11b, invalid instruction */
    /* or VEX Prefix - implemented in next release (AVX) */

    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+SEGMENT_REGISTER;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lds ");
        if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg2fword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
}

/* =======================================
 *      0c9h
 * ======================================= */
void __bea_callspec__ leave_(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "leave ");
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG4;
    (*pMyDisasm).Argument1.ArgSize = 32;
    (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+SPECIAL_REG+REG5;
    (*pMyDisasm).Argument2.ArgSize = 32;
    GV.EIP_++;
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ lea_GvM(PDISASM pMyDisasm)
{

    /* if MOD == 11b, invalid instruction */
    /* or VEX Prefix - implemented in next release (AVX) */

    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+MISCELLANEOUS_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lea ");
    if (GV.OperandSize >= 32) {
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg2qword;
        }
        else {
            GV.MemDecoration = Arg2dword;
        }
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }
    else {
        GV.MemDecoration = Arg2word;
        MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.EIP_+= GV.DECALAGE_EIP+2;
    }

}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ les_GvM(PDISASM pMyDisasm)
{

    if (GV.Architecture == 64) {
        FailDecode(pMyDisasm);
    }
    else {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+SEGMENT_REGISTER;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "les ");
        if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg2fword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
        else {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
            GV.EIP_+= GV.DECALAGE_EIP+2;
        }
    }
}

/* =======================================
 *      0ach
 * ======================================= */
void __bea_callspec__ lodsb_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.RepnePrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.RepPrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lodsb ");
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE;
    (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
    (*pMyDisasm).Argument2.ArgSize = 8;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG6;
    GV.EIP_++;
    FillFlags(pMyDisasm, 59);
}

/* =======================================
 *      0adh
 * ======================================= */
void __bea_callspec__ lodsw_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.RepnePrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.RepPrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    if (GV.OperandSize == 64) {
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lodsq ");
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG6;
        GV.EIP_++;
        FillFlags(pMyDisasm, 59);
    }
    else if (GV.OperandSize == 32) {
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lodsd ");
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
        (*pMyDisasm).Argument2.ArgSize = 32;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG6;
        GV.EIP_++;
        FillFlags(pMyDisasm, 59);
    }
    else {
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lodsw ");
        (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
        (*pMyDisasm).Argument2.ArgSize = 16;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG6;
        GV.EIP_++;
        FillFlags(pMyDisasm, 59);
    }
}

/* =======================================
 *      0e2h
 * ======================================= */
void __bea_callspec__ loop_(PDISASM pMyDisasm)
{
    signed long MyNumber;
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JE;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "loop ");
    if (!Security(1, pMyDisasm)) return;
    if (GV.OperandSize >= 32) {
        MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
        }
        else {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        }
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
        FillFlags(pMyDisasm, 60);
    }
    else {
        MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
        FillFlags(pMyDisasm, 60);

    }
}

/* =======================================
 *      0xe0
 * ======================================= */
void __bea_callspec__ loopne_(PDISASM pMyDisasm)
{
    signed long MyNumber;
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JNE;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "loopne ");
    if (!Security(1, pMyDisasm)) return;
    if (GV.OperandSize >= 32) {
        MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
        }
        else {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        }
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
        FillFlags(pMyDisasm, 61);
    }
    else {
        MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
        FillFlags(pMyDisasm, 61);

    }
}

/* =======================================
 *      0xe1
 * ======================================= */
void __bea_callspec__ loope_(PDISASM pMyDisasm)
{
    signed long MyNumber;
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+CONTROL_TRANSFER;
    (*pMyDisasm).Instruction.BranchType = JE;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "loope ");
    if (!Security(1, pMyDisasm)) return;
    if (GV.OperandSize >= 32) {
        MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
        if (MyAddress >= W64LIT (0x100000000)) {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
        }
        else {
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
        }
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
        FillFlags(pMyDisasm, 61);
    }
    else {
        MyNumber = *((Int8*)(UIntPtr) (GV.EIP_+1));
        CalculateRelativeAddress(&MyAddress,(Int64) GV.NB_PREFIX+2+MyNumber, pMyDisasm);
        MyAddress = MyAddress & 0xffff;
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
        (*pMyDisasm).Argument1.AccessMode = READ;
        (*pMyDisasm).Argument1.ArgSize = GV.OperandSize;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG1;
        (*pMyDisasm).Instruction.AddrValue = MyAddress;
        GV.EIP_+=2;
        FillFlags(pMyDisasm, 61);

    }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ lsl_GvEw(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lsl ");
    GvEw(pMyDisasm);
    FillFlags(pMyDisasm, 62);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ lss_Mp(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+SEGMENT_REGISTER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lss ");
    GvEv(pMyDisasm);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ lfs_Mp(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+SEGMENT_REGISTER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lfs ");
    GvEv(pMyDisasm);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ lgs_Mp(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+SEGMENT_REGISTER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "lgs ");
    GvEv(pMyDisasm);
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ mov_RdCd(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    if (GV.MOD_== 3) {
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
        GV.CR_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.CR_ = 0;
        FillFlags(pMyDisasm,67);
        GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else {
        FailDecode(pMyDisasm);
    }
}


/* =======================================
 *
 * ======================================= */
void __bea_callspec__ mov_RdDd(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    if (GV.MOD_== 3) {
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
        GV.DR_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
        GV.DR_ = 0;
        FillFlags(pMyDisasm,67);
        GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ mov_CdRd(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
    if (GV.MOD_== 3) {
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
        GV.CR_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.CR_ = 0;
        FillFlags(pMyDisasm,67);
        GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* =======================================
 *
 * ======================================= */
void __bea_callspec__ mov_DdRd(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = SYSTEM_INSTRUCTION;
    MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
    if (GV.MOD_== 3) {
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
        GV.DR_ = 1;
        Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
        GV.DR_ = 0;
        FillFlags(pMyDisasm,67);
        GV.EIP_ += GV.DECALAGE_EIP+2;
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* =======================================
 *      88h
 * ======================================= */
void __bea_callspec__ mov_EbGb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    EbGb(pMyDisasm);
}

/* =======================================
 *      89h
 * ======================================= */
void __bea_callspec__ mov_EvGv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    EvGv(pMyDisasm);
}

/* =======================================
 *      8ah
 * ======================================= */
void __bea_callspec__ mov_GbEb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    GbEb(pMyDisasm);
}

/* =======================================
 *      8bh
 * ======================================= */
void __bea_callspec__ mov_GvEv(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    GvEv(pMyDisasm);
}

/* =======================================
 *      0a0h
 * ======================================= */
void __bea_callspec__ mov_ALOb(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    GV.MemDecoration = Arg2byte;
    GV.RM_ = 5;
    GV.MOD_= 0;
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE ;
    (*pMyDisasm).Argument2.ArgSize = 8;
    if (GV.AddressSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_+1));
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%I64X",(Int64) MyAddress);
       GV.EIP_+=9;
       (*pMyDisasm).Argument2.Memory.Displacement = (Int64)MyAddress;
    }
    else if (GV.AddressSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_+1));
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.8X",(Int64) MyAddress);
       GV.EIP_+=5;
       (*pMyDisasm).Argument2.Memory.Displacement = (Int64)MyAddress;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_+1));
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.4X",(Int64) MyAddress);
       GV.EIP_+=3;
       (*pMyDisasm).Argument2.Memory.Displacement = (Int64)MyAddress;
    }

    if (GV.REX.B_ == 0) {
        (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers8Bits[0]);
    }
    else {
        (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers8Bits[0+8]);
    }

}

/* =======================================
 *      0a1h
 * ======================================= */
void __bea_callspec__ mov_eAXOv(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    GV.RM_ = 5;
    GV.MOD_= 0;
    if (GV.AddressSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_+1));
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%I64X",(Int64) MyAddress);
       GV.EIP_+=9;
       (*pMyDisasm).Argument2.Memory.Displacement = (Int64)MyAddress;
    }
    else if (GV.AddressSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_+1));
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.8X",(Int64) MyAddress);
       GV.EIP_+=5;
       (*pMyDisasm).Argument2.Memory.Displacement = (Int64)MyAddress;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_+1));
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.4X",(Int64) MyAddress);
       GV.EIP_+=3;
       (*pMyDisasm).Argument2.Memory.Displacement = (Int64)MyAddress;
    }

    if (GV.REX.B_ == 0) {
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg2qword;
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[0]);
        }
        else if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg2dword;
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[0]);
        }
        else {
            GV.MemDecoration = Arg2word;
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[0]);
        }
    }
    else {
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg2qword;
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[0+8]);
        }
        else if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg2dword;
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[0+8]);
        }
        else {
            GV.MemDecoration = Arg2word;
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[0+8]);
        }
    }
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE ;
    if (GV.MemDecoration == 104) {
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 64;
    }
    else if (GV.MemDecoration == 103) {
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else if (GV.MemDecoration == 102) {
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }

}

/* =======================================
 *      0a2h
 * ======================================= */
void __bea_callspec__ mov_ObAL(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    GV.MemDecoration = Arg1byte;
    GV.RM_ = 5;
    GV.MOD_= 0;
    (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgType = MEMORY_TYPE ;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgSize = 8;
    if (GV.AddressSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_+1));
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
       GV.EIP_+=9;
       (*pMyDisasm).Argument1.Memory.Displacement = (Int64)MyAddress;
    }
    else if (GV.AddressSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_+1));
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
       GV.EIP_+=5;
       (*pMyDisasm).Argument1.Memory.Displacement = (Int64)MyAddress;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_+1));
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
       GV.EIP_+=3;
       (*pMyDisasm).Argument1.Memory.Displacement = (Int64)MyAddress;
    }

    if (GV.REX.B_ == 0) {
        (void) strcpy ((char*) (*pMyDisasm).Argument2.ArgMnemonic, Registers8Bits[0]);
    }
    else {
        (void) strcpy ((char*) (*pMyDisasm).Argument2.ArgMnemonic, Registers8Bits[0+8]);
    }

}

/* =======================================
 *      0a3h
 * ======================================= */
void __bea_callspec__ mov_OveAX(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    GV.RM_ = 5;
    GV.MOD_= 0;
    if (GV.AddressSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_+1));
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%I64X",(Int64) MyAddress);
       GV.EIP_+=9;
       (*pMyDisasm).Argument1.Memory.Displacement = (Int64)MyAddress;
    }
    else if (GV.AddressSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_+1));
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.8X",(Int64) MyAddress);
       GV.EIP_+=5;
       (*pMyDisasm).Argument1.Memory.Displacement = (Int64)MyAddress;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_+1));
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument1.ArgMnemonic, "%.4X",(Int64) MyAddress);
       GV.EIP_+=3;
       (*pMyDisasm).Argument1.Memory.Displacement = (Int64)MyAddress;
    }

    if (GV.REX.B_ == 0) {
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg1qword;
            (void) strcpy ((char*) (*pMyDisasm).Argument2.ArgMnemonic, Registers64Bits[0]);
        }
        else if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg1dword;
            (void) strcpy ((char*) (*pMyDisasm).Argument2.ArgMnemonic, Registers32Bits[0]);
        }
        else {
            GV.MemDecoration = Arg1word;
            (void) strcpy ((char*) (*pMyDisasm).Argument2.ArgMnemonic, Registers16Bits[0]);
        }
    }
    else {
        if (GV.OperandSize == 64) {
            GV.MemDecoration = Arg1qword;
            (void) strcpy ((char*) (*pMyDisasm).Argument2.ArgMnemonic, Registers64Bits[0+8]);
        }
        else if (GV.OperandSize == 32) {
            GV.MemDecoration = Arg1dword;
            (void) strcpy ((char*) (*pMyDisasm).Argument2.ArgMnemonic, Registers32Bits[0+8]);
        }
        else {
            GV.MemDecoration = Arg1word;
            (void) strcpy ((char*) (*pMyDisasm).Argument2.ArgMnemonic, Registers16Bits[0+8]);
        }
    }

    (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgType = MEMORY_TYPE ;
    if (GV.MemDecoration == 104) {
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 64;
    }
    else if (GV.MemDecoration == 103) {
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else if (GV.MemDecoration == 102) {
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }
}

/* =======================================
 *      0b0h
 * ======================================= */
void __bea_callspec__ mov_ALIb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    ALIb(pMyDisasm);
}

/* =======================================
 *      0b1h
 * ======================================= */
void __bea_callspec__ mov_CLIb(PDISASM pMyDisasm)
{
    long MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    if (!Security(2, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument2.ArgMnemonic,"%.2X",(Int64) MyNumber);
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    (void) strcpy((char*) &(*pMyDisasm).Argument1.ArgMnemonic, Registers8BitsLegacy[1]);
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG1;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
    GV.EIP_ += 2;
}

/* =======================================
 *      0b2h
 * ======================================= */
void __bea_callspec__ mov_DLIb(PDISASM pMyDisasm)
{
    long MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    if (!Security(2, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument2.ArgMnemonic,"%.2X",(Int64) MyNumber);
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    (void) strcpy((char*) &(*pMyDisasm).Argument1.ArgMnemonic, Registers8BitsLegacy[2]);
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG2;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
    GV.EIP_ += 2;
}

/* =======================================
 *      0b3h
 * ======================================= */
void __bea_callspec__ mov_BLIb(PDISASM pMyDisasm)
{
    long MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    if (!Security(2, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument2.ArgMnemonic,"%.2X",(Int64) MyNumber);
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    (void) strcpy((char*) &(*pMyDisasm).Argument1.ArgMnemonic, Registers8BitsLegacy[3]);
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG3;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
    GV.EIP_ += 2;
}

/* =======================================
 *      0b4h
 * ======================================= */
void __bea_callspec__ mov_AHIb(PDISASM pMyDisasm)
{
    long MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    if (!Security(2, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument2.ArgMnemonic,"%.2X",(Int64) MyNumber);
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    (void) strcpy((char*) &(*pMyDisasm).Argument1.ArgMnemonic, Registers8BitsLegacy[4]);
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
    GV.EIP_ += 2;
}

/* =======================================
 *      0b5h
 * ======================================= */
void __bea_callspec__ mov_CHIb(PDISASM pMyDisasm)
{
    long MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    if (!Security(2, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument2.ArgMnemonic,"%.2X",(Int64) MyNumber);
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    (void) strcpy((char*) &(*pMyDisasm).Argument1.ArgMnemonic, Registers8BitsLegacy[5]);
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG1;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
    GV.EIP_ += 2;
}

/* =======================================
 *      0b6h
 * ======================================= */
void __bea_callspec__ mov_DHIb(PDISASM pMyDisasm)
{
    long MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    if (!Security(2, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument2.ArgMnemonic,"%.2X",(Int64) MyNumber);
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    (void) strcpy((char*) &(*pMyDisasm).Argument1.ArgMnemonic, Registers8BitsLegacy[6]);
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG2;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
    GV.EIP_ += 2;
}

/* =======================================
 *      0b7h
 * ======================================= */
void __bea_callspec__ mov_BHIb(PDISASM pMyDisasm)
{
    long MyNumber;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    if (!Security(2, pMyDisasm)) return;
    GV.ImmediatSize = 8;
    MyNumber = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    (void) CopyFormattedNumber(pMyDisasm, (char*) &(*pMyDisasm).Argument2.ArgMnemonic,"%.2X",(Int64) MyNumber);
    (*pMyDisasm).Instruction.Immediat = MyNumber;
    (void) strcpy((char*) &(*pMyDisasm).Argument1.ArgMnemonic, Registers8BitsLegacy[7]);
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG3;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    (*pMyDisasm).Argument2.ArgSize = 8;
    GV.EIP_ += 2;
}


/* =======================================
 *      0a4h
 * ======================================= */
void __bea_callspec__ movs_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.RepnePrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.RepPrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsb ");
    (*pMyDisasm).Argument1.ArgType = MEMORY_TYPE;
    (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
    (*pMyDisasm).Argument1.ArgSize = 8;
    (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE;
    (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
    (*pMyDisasm).Argument2.ArgSize = 8;
    (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG6+REG7;
    GV.EIP_++;
    FillFlags(pMyDisasm, 68);
}

/* =======================================
 *      0a5h
 * ======================================= */
void __bea_callspec__ movsw_(PDISASM pMyDisasm)
{
    if ((*pMyDisasm).Prefix.RepnePrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepnePrefix = InUsePrefix;
    }
    if ((*pMyDisasm).Prefix.RepPrefix == SuperfluousPrefix) {
        (*pMyDisasm).Prefix.RepPrefix = InUsePrefix;
    }
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+STRING_INSTRUCTION;
    if (GV.OperandSize == 64) {
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsq ");
        (*pMyDisasm).Argument1.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
        (*pMyDisasm).Argument2.ArgSize = 64;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG6+REG7;
        GV.EIP_++;
        FillFlags(pMyDisasm, 68);
    }
    else if (GV.OperandSize == 32) {
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsd ");
        (*pMyDisasm).Argument1.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
        (*pMyDisasm).Argument2.ArgSize = 32;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG6+REG7;
        GV.EIP_++;
        FillFlags(pMyDisasm, 68);
    }
    else {
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsw ");
        (*pMyDisasm).Argument1.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument1.Memory.BaseRegister = REG7;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgType = MEMORY_TYPE;
        (*pMyDisasm).Argument2.Memory.BaseRegister = REG6;
        (*pMyDisasm).Argument2.ArgSize = 16;
        (*pMyDisasm).Instruction.ImplicitModifiedRegs = GENERAL_REG+REG6+REG7;
        GV.EIP_++;
        FillFlags(pMyDisasm, 68);
    }
}

/* =======================================
 *      0fb6h
 * ======================================= */
void __bea_callspec__ movzx_GvEb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movzx ");
    GvEb(pMyDisasm);
}


/* =======================================
 *      0fbeh
 * ======================================= */
void __bea_callspec__ movsx_GvEb(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsx ");
    GvEb(pMyDisasm);
}

/* =======================================
 *      0fbfh
 * ======================================= */
void __bea_callspec__ movsx_GvEw(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movsx ");
    GvEw(pMyDisasm);
}

/* =======================================
 *      0fb7h
 * ======================================= */
void __bea_callspec__ movzx_GvEw(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "movzx ");
    GvEw(pMyDisasm);
}

/* =======================================
 *      0b8h
 * ======================================= */
void __bea_callspec__ mov_EAX(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG0;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    if (GV.OperandSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_+1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%I64X",(Int64) MyAddress);
        GV.EIP_+=9;
        (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 64;
    }
    else if (GV.OperandSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_+1));
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.8X",(Int64) MyAddress);
       GV.EIP_+=5;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_+1));
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.4X",(Int64) MyAddress);
       GV.EIP_+=3;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }

    if (GV.REX.B_ == 0) {
        if (GV.OperandSize == 64) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[0]);
        }
        else if (GV.OperandSize == 32) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[0]);
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[0]);
        }
    }
    else {
        if (GV.OperandSize == 64) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[0+8]);
        }
        else if (GV.OperandSize == 32) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[0+8]);
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[0+8]);
        }
    }

}

/* =======================================
 *      0b9h
 * ======================================= */
void __bea_callspec__ mov_ECX(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG1;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    if (GV.OperandSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_+1));
        (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%I64X",(Int64) MyAddress);
        GV.EIP_+=9;
        (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 64;
    }
    else if (GV.OperandSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_+1));
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.8X",(Int64) MyAddress);
       GV.EIP_+=5;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_+1));
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.4X",(Int64) MyAddress);
       GV.EIP_+=3;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }

    if (GV.REX.B_ == 0) {
        if (GV.OperandSize == 64) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[1+0]);
        }
        else if (GV.OperandSize == 32) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[1+0]);
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[1+0]);
        }
    }
    else {
        if (GV.OperandSize == 64) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[1+0+8]);
        }
        else if (GV.OperandSize == 32) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[1+0+8]);
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[1+0+8]);
        }
    }

}

/* =======================================
 *      0bah
 * ======================================= */
void __bea_callspec__ mov_EDX(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG2;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    if (GV.OperandSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_+1));
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%I64X",(Int64) MyAddress);
       GV.EIP_+=9;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 64;
    }
    else if (GV.OperandSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_+1));
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.8X",(Int64) MyAddress);
       GV.EIP_+=5;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_+1));
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.4X",(Int64) MyAddress);
       GV.EIP_+=3;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }

    if (GV.REX.B_ == 0) {
        if (GV.OperandSize == 64) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[2+0]);
        }
        else if (GV.OperandSize == 32) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[2+0]);
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[2+0]);
        }
    }
    else {
        if (GV.OperandSize == 64) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[2+0+8]);
        }
        else if (GV.OperandSize == 32) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[2+0+8]);
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[2+0+8]);
        }
    }

}

/* =======================================
 *      0bbh
 * ======================================= */
void __bea_callspec__ mov_EBX(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG3;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    if (GV.OperandSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_+1));
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%I64X",(Int64) MyAddress);
       GV.EIP_+=9;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 64;
    }
    else if (GV.OperandSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_+1));
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.8X",(Int64) MyAddress);
       GV.EIP_+=5;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_+1));
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.4X",(Int64) MyAddress);
       GV.EIP_+=3;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }

    if (GV.REX.B_ == 0) {
        if (GV.OperandSize == 64) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[3+0]);
        }
        else if (GV.OperandSize == 32) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[3+0]);
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[3+0]);
        }
    }
    else {
        if (GV.OperandSize == 64) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[3+0+8]);
        }
        else if (GV.OperandSize == 32) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[3+0+8]);
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[3+0+8]);
        }
    }

}

/* =======================================
 *      0bch
 * ======================================= */
void __bea_callspec__ mov_ESP(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG4;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    if (GV.OperandSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_+1));
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%I64X",(Int64) MyAddress);
       GV.EIP_+=9;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 64;
    }
    else if (GV.OperandSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_+1));
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.8X",(Int64) MyAddress);
       GV.EIP_+=5;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_+1));
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.4X",(Int64) MyAddress);
       GV.EIP_+=3;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }

    if (GV.REX.B_ == 0) {
        if (GV.OperandSize == 64) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[4+0]);
        }
        else if (GV.OperandSize == 32) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[4+0]);
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[4+0]);
        }
    }
    else {
        if (GV.OperandSize == 64) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[4+0+8]);
        }
        else if (GV.OperandSize == 32) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[4+0+8]);
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[4+0+8]);
        }
    }

}

/* =======================================
 *      0bdh
 * ======================================= */
void __bea_callspec__ mov_EBP(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG5;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    if (GV.OperandSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_+1));
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%I64X",(Int64) MyAddress);
       GV.EIP_+=9;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 64;
    }
    else if (GV.OperandSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_+1));
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.8X",(Int64) MyAddress);
       GV.EIP_+=5;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_+1));
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.4X",(Int64) MyAddress);
       GV.EIP_+=3;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }

    if (GV.REX.B_ == 0) {
        if (GV.OperandSize == 64) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[5+0]);
        }
        else if (GV.OperandSize == 32) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[5+0]);
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[5+0]);
        }
    }
    else {
        if (GV.OperandSize == 64) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[5+0+8]);
        }
        else if (GV.OperandSize == 32) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[5+0+8]);
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[5+0+8]);
        }
    }

}

/* =======================================
 *      0beh
 * ======================================= */
void __bea_callspec__ mov_ESI(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG6;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    if (GV.OperandSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_+1));
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%I64X",(Int64) MyAddress);
       GV.EIP_+=9;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 64;
    }
    else if (GV.OperandSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_+1));
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.8X",(Int64) MyAddress);
       GV.EIP_+=5;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_+1));
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.4X",(Int64) MyAddress);
       GV.EIP_+=3;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }

    if (GV.REX.B_ == 0) {
        if (GV.OperandSize == 64) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[6+0]);
        }
        else if (GV.OperandSize == 32) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[6+0]);
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[6+0]);
        }
    }
    else {
        if (GV.OperandSize == 64) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[6+0+8]);
        }
        else if (GV.OperandSize == 32) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[6+0+8]);
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[6+0+8]);
        }
    }

}

/* =======================================
 *      0bfh
 * ======================================= */
void __bea_callspec__ mov_EDI(PDISASM pMyDisasm)
{
    UInt64 MyAddress;
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+GENERAL_REG+REG7;
    (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
    if (GV.OperandSize == 64) {
        if (!Security(9, pMyDisasm)) return;
        MyAddress = *((UInt64 *)(UIntPtr) (GV.EIP_+1));
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%I64X",(Int64) MyAddress);
       GV.EIP_+=9;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 64;
        (*pMyDisasm).Argument2.ArgSize = 64;
    }
    else if (GV.OperandSize == 32) {
        if (!Security(5, pMyDisasm)) return;
        MyAddress = *((UInt32*)(UIntPtr) (GV.EIP_+1));
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.8X",(Int64) MyAddress);
       GV.EIP_+=5;
       (*pMyDisasm).Instruction.Immediat = (Int64)MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 32;
        (*pMyDisasm).Argument2.ArgSize = 32;
    }
    else {
        if (!Security(3, pMyDisasm)) return;
        MyAddress = *((UInt16*)(UIntPtr) (GV.EIP_+1));
       (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument2.ArgMnemonic, "%.4X",(Int64) MyAddress);
       GV.EIP_+=3;
       (*pMyDisasm).Instruction.Immediat = (Int64) MyAddress;
        (*pMyDisasm).Argument1.ArgSize = 16;
        (*pMyDisasm).Argument2.ArgSize = 16;
    }

    if (GV.REX.B_ == 0) {
        if (GV.OperandSize == 64) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[7+0]);
        }
        else if (GV.OperandSize == 32) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[7+0]);
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[7+0]);
        }
    }
    else {
        if (GV.OperandSize == 64) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers64Bits[7+0+8]);
        }
        else if (GV.OperandSize == 32) {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers32Bits[7+0+8]);
        }
        else {
            (void) strcpy ((char*) (*pMyDisasm).Argument1.ArgMnemonic, Registers16Bits[7+0+8]);
        }
    }

}
/* =======================================
 *      0c6h-Group 11
 * ======================================= */
void __bea_callspec__ mov_EbIb(PDISASM pMyDisasm)
{
    GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
    if (GV.REGOPCODE == 0) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
        EbIb(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* =======================================
 *      0c7h-Group 11
 * ======================================= */
void __bea_callspec__ mov_EvIv(PDISASM pMyDisasm)
{
    GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
    if (GV.REGOPCODE == 0) {
        (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
        (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
        EvIv(pMyDisasm);
    }
    else {
        FailDecode(pMyDisasm);
    }
}

/* =======================================
 *      08ch
 * ======================================= */
void __bea_callspec__ mov_EwSreg(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    GV.MemDecoration = Arg1word;
    GV.OperandSize = 16;
    MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
    GV.OperandSize = 32;
    GV.SEG_ = 1;
    Reg_Opcode(&(*pMyDisasm).Argument2, pMyDisasm);
    GV.SEG_ = 0;
    GV.EIP_ += GV.DECALAGE_EIP+2;
}

/* =======================================
 *      08eh
 * ======================================= */
void __bea_callspec__ mov_SregEw(PDISASM pMyDisasm)
{
    (*pMyDisasm).Instruction.Category = GENERAL_PURPOSE_INSTRUCTION+DATA_TRANSFER;
    (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "mov ");
    GV.MemDecoration = Arg2word;
    GV.OperandSize = 16;
    MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
    GV.OperandSize = 32;
    GV.SEG_ = 1;
    Reg_Opcode(&(*pMyDisasm).Argument1, pMyDisasm);
    GV.SEG_ = 0;
    GV.EIP_ += GV.DECALAGE_EIP+2;
}
