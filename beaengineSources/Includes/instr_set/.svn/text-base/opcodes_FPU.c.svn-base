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
 *
 * ==================================================================== */
void __bea_callspec__ D8_(PDISASM pMyDisasm)
{
    long MyMODRM;
    char (*pRegistersFPU)[8][8] ;

    GV.DECALAGE_EIP = 0;
    if (!Security(1, pMyDisasm)) {return;}
    MyMODRM = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    pRegistersFPU = &RegistersFPU_Masm;
    if (GV.SYNTAX_ == NasmSyntax) {
        pRegistersFPU = &RegistersFPU_Nasm;
    }
    if (MyMODRM <= 0xbf) {
        GV.MemDecoration = Arg2dword;
        GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
        if (GV.REGOPCODE == 0) {
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fadd ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 1) {
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fmul ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 2) {
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcom ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ;
        }
        else if (GV.REGOPCODE == 3) {
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcomp ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ;
        }
        else if (GV.REGOPCODE == 4) {
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsub ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 5) {
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsubr ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 6) {
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fdiv ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 7) {
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fdivr ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    else {
        if ((MyMODRM & 0xf0) == 0xc0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fadd ");
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fmul ");
            }
            (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
            (*pMyDisasm).Argument1.ArgSize = 80;
            (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xd0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcom ");
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcomp ");
            }
            (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
            (*pMyDisasm).Argument1.ArgSize = 80;
            (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xe0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsub ");
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsubr ");
            }
            (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
            (*pMyDisasm).Argument1.ArgSize = 80;
            (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xf0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fdiv ");
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fdivr ");
            }
            (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
            (*pMyDisasm).Argument1.ArgSize = 80;
            (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
    }
    GV.EIP_ += GV.DECALAGE_EIP+2;
}

/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ D9_(PDISASM pMyDisasm)
{
    long MyMODRM;
    char (*pRegistersFPU)[8][8] ;

    GV.DECALAGE_EIP = 0;
    if (!Security(1, pMyDisasm)) {return;}
    MyMODRM = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    pRegistersFPU = &RegistersFPU_Masm;
    if (GV.SYNTAX_ == NasmSyntax) {
        pRegistersFPU = &RegistersFPU_Nasm;
    }
    if (MyMODRM <= 0xbf) {

        GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
        if (GV.REGOPCODE == 0) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fld ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 2) {
            GV.MemDecoration = Arg1dword;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fst ");
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 3) {
            GV.MemDecoration = Arg1dword;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fstp ");
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 4) {
            GV.MemDecoration = Arg2multibytes;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fldenv ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 5) {
            GV.MemDecoration = Arg2word;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fldcw ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 6) {
            GV.MemDecoration = Arg1multibytes;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fstenv ");
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 7) {
            GV.MemDecoration = Arg1word;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fstcw ");
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    else {
        if ((MyMODRM & 0xf0) == 0xc0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fld ");
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fxch ");
                (*pMyDisasm).Argument2.AccessMode = WRITE;
            }
            (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
            (*pMyDisasm).Argument1.ArgSize = 80;
            (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xd0) {
            if ((MyMODRM & 0xf) ==0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fnop ");
            }
            else if (((MyMODRM & 0xf) >=0x8) && ((MyMODRM & 0xf) <=0xf)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fstp1 ");
                (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else {
                FailDecode(pMyDisasm);
            }

        }
        else if ((MyMODRM & 0xf0) == 0xe0) {
            if ((MyMODRM & 0xf) ==0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fchs ");
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==1) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fabs ");
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==4) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ftst ");
            }
            else if ((MyMODRM & 0xf) ==5) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fxam ");
            }
            else if ((MyMODRM & 0xf) ==8) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOAD_CONSTANTS;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fld1 ");
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
                (*pMyDisasm).Argument2.ArgSize = 80;

            }
            else if ((MyMODRM & 0xf) ==9) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOAD_CONSTANTS;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fldl2t ");
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
                (*pMyDisasm).Argument2.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==0xa) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOAD_CONSTANTS;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fldl2e ");
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
                (*pMyDisasm).Argument2.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==0xb) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOAD_CONSTANTS;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fldpi ");
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
                (*pMyDisasm).Argument2.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==0xc) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOAD_CONSTANTS;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fldlg2 ");
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
                (*pMyDisasm).Argument2.ArgSize = 80;
            }

            else if ((MyMODRM & 0xf) ==0xd) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOAD_CONSTANTS;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fldln2 ");
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
                (*pMyDisasm).Argument2.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==0xe) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOAD_CONSTANTS;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fldz ");
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument2.ArgType = CONSTANT_TYPE+ABSOLUTE_;
                (*pMyDisasm).Argument2.ArgSize = 80;
            }

            else {
                FailDecode(pMyDisasm);
            }
        }
        else if ((MyMODRM & 0xf0) == 0xf0) {
            if ((MyMODRM & 0xf) ==0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOGARITHMIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "f2xm1 ");
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==1) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOGARITHMIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fyl2x ");
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==2) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+TRIGONOMETRIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fptan ");
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==3) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+TRIGONOMETRIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fpatan ");
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==4) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fxtract ");
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==5) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fprem1 ");
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==6) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fdecstp ");
            }
            else if ((MyMODRM & 0xf) ==7) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fincstp ");
            }
            else if ((MyMODRM & 0xf) ==8) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fprem ");
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==9) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOGARITHMIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fyl2xp1 ");
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==0xa) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsqrt ");
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==0xb) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+TRIGONOMETRIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsincos ");
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==0xc) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "frndint ");
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==0xd) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+LOGARITHMIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fscale ");
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==0xe) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+TRIGONOMETRIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsin ");
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else if ((MyMODRM & 0xf) ==0xf) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+TRIGONOMETRIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcos ");
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else {
                FailDecode(pMyDisasm);
            }
        }
    }
    GV.EIP_ += GV.DECALAGE_EIP+2;
}


/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ DA_(PDISASM pMyDisasm)
{
    long MyMODRM;
    char (*pRegistersFPU)[8][8] ;

    GV.DECALAGE_EIP = 0;
    if (!Security(1, pMyDisasm)) {return;}
    MyMODRM = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    pRegistersFPU = &RegistersFPU_Masm;
    if (GV.SYNTAX_ == NasmSyntax) {
        pRegistersFPU = &RegistersFPU_Nasm;
    }
    if (MyMODRM <= 0xbf) {

        GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
        if (GV.REGOPCODE == 0) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fiadd ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 1) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fimul ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 2) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ficom ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ;
        }
        else if (GV.REGOPCODE == 3) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ficomp ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ;
        }
        else if (GV.REGOPCODE == 4) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fisub ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 5) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fisubr ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 6) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fidiv ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 7) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fidivr ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    else {
        if ((MyMODRM & 0xf0) == 0xc0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcmovb ");
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcmove ");
                (*pMyDisasm).Argument2.AccessMode = WRITE;
            }
            (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
            (*pMyDisasm).Argument1.ArgSize = 80;
            (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xd0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcmovbe ");
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcmovu ");
                (*pMyDisasm).Argument2.AccessMode = WRITE;
            }
            (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
            (*pMyDisasm).Argument1.ArgSize = 80;
            (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument2.ArgSize = 80;

        }
        else if (MyMODRM == 0xe9) {
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fucompp ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    GV.EIP_ += GV.DECALAGE_EIP+2;
}


/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ DB_(PDISASM pMyDisasm)
{
    long MyMODRM;
    char (*pRegistersFPU)[8][8] ;

    GV.DECALAGE_EIP = 0;
    if (!Security(1, pMyDisasm)) {return;}
    MyMODRM = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    pRegistersFPU = &RegistersFPU_Masm;
    if (GV.SYNTAX_ == NasmSyntax) {
        pRegistersFPU = &RegistersFPU_Nasm;
    }
    if (MyMODRM <= 0xbf) {

        GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
        if (GV.REGOPCODE == 0) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fild ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 1) {
            GV.MemDecoration = Arg1dword;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fisttp ");
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 2) {
            GV.MemDecoration = Arg1dword;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fist ");
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 3) {
            GV.MemDecoration = Arg1dword;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fistp ");
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 5) {
            GV.MemDecoration = Arg2tbyte;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fld ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 7) {
            GV.MemDecoration = Arg1dword;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fstp ");
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    else {
        if ((MyMODRM & 0xf0) == 0xc0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcmovnb ");
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcmovne ");
                (*pMyDisasm).Argument2.AccessMode = WRITE;
            }
            (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
            (*pMyDisasm).Argument1.ArgSize = 80;
            (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xd0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcmovnbe ");
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcmovnu ");
                (*pMyDisasm).Argument2.AccessMode = WRITE;
            }
            (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[0]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
            (*pMyDisasm).Argument1.ArgSize = 80;
            (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xe0) {

            if ((MyMODRM & 0xf) ==0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+UNSUPPORTED_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fneni ");
            }
            else if ((MyMODRM & 0xf) ==1) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+UNSUPPORTED_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fndisi ");
            }
            else if ((MyMODRM & 0xf) ==2) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fnclex ");
            }
            else if ((MyMODRM & 0xf) ==3) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fninit ");
            }
            else if ((MyMODRM & 0xf) ==4) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+UNSUPPORTED_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fnsetpm ");
            }
            else if ((MyMODRM & 0xf) ==5) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "frstpm ");
            }
            else if (((MyMODRM & 0xf) >=0x8) && ((MyMODRM & 0xf) <=0xf)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fucomi ");
                (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[0]);
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument1.AccessMode = READ;
                (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
                (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
                (*pMyDisasm).Argument2.ArgSize = 80;
            }
            else {
                FailDecode(pMyDisasm);
            }
        }
        else if ((MyMODRM & 0xf0) == 0xf0) {
            if (((MyMODRM & 0xf) >=0x0) && ((MyMODRM & 0xf) <=0x7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcomi ");
                (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[0]);
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
                (*pMyDisasm).Argument1.AccessMode = READ;
                (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
                (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
                (*pMyDisasm).Argument2.ArgSize = 80;
            }
            else {
                FailDecode(pMyDisasm);
            }
        }
        else {
                FailDecode(pMyDisasm);
        }
    }
    GV.EIP_ += GV.DECALAGE_EIP+2;
}


/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ DC_(PDISASM pMyDisasm)
{
    long MyMODRM;
    char (*pRegistersFPU)[8][8] ;

    GV.DECALAGE_EIP = 0;
    if (!Security(1, pMyDisasm)) {return;}
    MyMODRM = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    pRegistersFPU = &RegistersFPU_Masm;
    if (GV.SYNTAX_ == NasmSyntax) {
        pRegistersFPU = &RegistersFPU_Nasm;
    }
    if (MyMODRM <= 0xbf) {

        GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
        if (GV.REGOPCODE == 0) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fadd ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 1) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fmul ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 2) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcom ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ;
        }
        else if (GV.REGOPCODE == 3) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcomp ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
            (*pMyDisasm).Argument1.AccessMode = READ;
        }
        else if (GV.REGOPCODE == 4) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsub ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 5) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsubr ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 6) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fdiv ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 7) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fdivr ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    else {
        if ((MyMODRM & 0xf0) == 0xc0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fadd ");
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fmul ");
                (*pMyDisasm).Argument1.AccessMode = WRITE;
            }
            (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[0]);
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
            (*pMyDisasm).Argument2.ArgSize = 80;
            (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xd0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcom2 ");

            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcomp3 ");
            }
            (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument1.ArgSize = 80;

        }
        else if ((MyMODRM & 0xf0) == 0xe0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsubr ");
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsub ");
            }
            (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[0]);
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
            (*pMyDisasm).Argument2.ArgSize = 80;
            (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xf0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fdivr ");
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fdiv ");
            }
            (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[0]);
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
            (*pMyDisasm).Argument2.ArgSize = 80;
            (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument1.ArgSize = 80;

        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    GV.EIP_ += GV.DECALAGE_EIP+2;
}


/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ DD_(PDISASM pMyDisasm)
{
    long MyMODRM;
    char (*pRegistersFPU)[8][8] ;

    GV.DECALAGE_EIP = 0;
    if (!Security(1, pMyDisasm)) {return;}
    MyMODRM = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    pRegistersFPU = &RegistersFPU_Masm;
    if (GV.SYNTAX_ == NasmSyntax) {
        pRegistersFPU = &RegistersFPU_Nasm;
    }
    if (MyMODRM <= 0xbf) {

        GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
        if (GV.REGOPCODE == 0) {
            GV.MemDecoration = Arg2qword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fld ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 1) {
            GV.MemDecoration = Arg1qword;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fisttp ");
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 2) {
            GV.MemDecoration = Arg1qword;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fst ");
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 3) {
            GV.MemDecoration = Arg1qword;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fstp ");
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 4) {
            GV.MemDecoration = Arg2multibytes;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "frstor ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 108*8;
        }
        else if (GV.REGOPCODE == 6) {
            GV.MemDecoration = Arg1multibytes;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsave ");
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 108*8;
        }
        else if (GV.REGOPCODE == 7) {
            GV.MemDecoration = Arg1word;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fstsw ");
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG;
            (*pMyDisasm).Argument2.ArgSize = 16;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    else {
        if ((MyMODRM & 0xf0) == 0xc0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ffree ");
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fxch4 ");
                (*pMyDisasm).Argument2.AccessMode = WRITE;
            }
            (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xd0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fst ");
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fstp ");
                (*pMyDisasm).Argument2.AccessMode = WRITE;
            }
            (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument1.ArgSize = 80;

        }
        else if ((MyMODRM & 0xf0) == 0xe0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fucom ");
                (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[0]);
                (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument2.ArgSize = 80;
                (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fucomp ");
                (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }

        }

        else {
            FailDecode(pMyDisasm);
        }
    }
    GV.EIP_ += GV.DECALAGE_EIP+2;
}


/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ DE_(PDISASM pMyDisasm)
{
    long MyMODRM;
    char (*pRegistersFPU)[8][8] ;

    GV.DECALAGE_EIP = 0;
    if (!Security(1, pMyDisasm)) {return;}
    MyMODRM = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    pRegistersFPU = &RegistersFPU_Masm;
    if (GV.SYNTAX_ == NasmSyntax) {
        pRegistersFPU = &RegistersFPU_Nasm;
    }
    if (MyMODRM <= 0xbf) {

        GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
        if (GV.REGOPCODE == 0) {
            GV.MemDecoration = Arg2word;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fiadd ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 1) {
            GV.MemDecoration = Arg2word;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fimul ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 2) {
            GV.MemDecoration = Arg2word;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ficom ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 3) {
            GV.MemDecoration = Arg2word;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ficomp ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 4) {
            GV.MemDecoration = Arg2word;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fisub ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 5) {
            GV.MemDecoration = Arg2word;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fisubr ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 6) {
            GV.MemDecoration = Arg2word;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fidiv ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 7) {
            GV.MemDecoration = Arg2word;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fidivr ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    else {
        if ((MyMODRM & 0xf0) == 0xc0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "faddp ");
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fmulp ");
                (*pMyDisasm).Argument2.AccessMode = WRITE;
            }
            (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[0]);
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
            (*pMyDisasm).Argument2.ArgSize = 80;
            (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xd0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcomp5 ");
                (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
                (*pMyDisasm).Argument1.ArgSize = 80;
            }
            else if (MyMODRM == 0xd9){
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcompp ");
            }


        }
        else if ((MyMODRM & 0xf0) == 0xe0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsubrp ");
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fsubp ");
                (*pMyDisasm).Argument2.AccessMode = WRITE;
            }
            (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[0]);
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
            (*pMyDisasm).Argument2.ArgSize = 80;
            (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xf0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fdivrp ");
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+ARITHMETIC_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fdivp ");
                (*pMyDisasm).Argument2.AccessMode = WRITE;
            }
            (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[0]);
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
            (*pMyDisasm).Argument2.ArgSize = 80;
            (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument1.ArgSize = 80;

        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    GV.EIP_ += GV.DECALAGE_EIP+2;
}


/* ====================================================================
 *
 * ==================================================================== */
void __bea_callspec__ DF_(PDISASM pMyDisasm)
{
    long MyMODRM;
    char (*pRegistersFPU)[8][8] ;

    GV.DECALAGE_EIP = 0;
    if (!Security(1, pMyDisasm)) {return;}
    MyMODRM = *((UInt8*)(UIntPtr) (GV.EIP_+1));
    pRegistersFPU = &RegistersFPU_Masm;
    if (GV.SYNTAX_ == NasmSyntax) {
        pRegistersFPU = &RegistersFPU_Nasm;
    }
    if (MyMODRM <= 0xbf) {

        GV.REGOPCODE = ((*((UInt8*)(UIntPtr) (GV.EIP_+1))) >> 3) & 0x7;
        if (GV.REGOPCODE == 0) {
            GV.MemDecoration = Arg2word;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fild ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 1) {
            GV.MemDecoration = Arg1word;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fisttp ");
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 2) {
            GV.MemDecoration = Arg1word;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fist ");
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 3) {
            GV.MemDecoration = Arg1word;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fistp ");
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 4) {
            GV.MemDecoration = Arg2multibytes;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fbld ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 5) {
            GV.MemDecoration = Arg2dword;
            MOD_RM(&(*pMyDisasm).Argument2, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fild ");
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 6) {
            GV.MemDecoration = Arg1multibytes;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fbstp ");
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else if (GV.REGOPCODE == 7) {
            GV.MemDecoration = Arg1qword;
            MOD_RM(&(*pMyDisasm).Argument1, pMyDisasm);
            (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fistp ");
            (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REG0;
            (*pMyDisasm).Argument2.ArgSize = 80;
        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    else {
        if ((MyMODRM & 0xf0) == 0xc0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "ffreep ");
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fxch7 ");
                (*pMyDisasm).Argument2.AccessMode = WRITE;
            }
            (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument1.ArgSize = 80;
        }
        else if ((MyMODRM & 0xf0) == 0xd0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fstp8 ");
            }
            else {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+DATA_TRANSFER;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fstp9 ");
                (*pMyDisasm).Argument2.AccessMode = WRITE;
            }
            (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
            (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
            (*pMyDisasm).Argument1.ArgSize = 80;

        }
        else if ((MyMODRM & 0xf0) == 0xe0) {
            if (MyMODRM == 0xe0) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+FPUCONTROL;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fstsw ");
            }
            else if ((MyMODRM & 0xf) >=8) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fucomip ");
                (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[0]);
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
                (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
                (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
                (*pMyDisasm).Argument2.ArgSize = 80;
            }


            else {
                FailDecode(pMyDisasm);
            }
        }

        else if ((MyMODRM & 0xf0) == 0xf0) {
            if (((MyMODRM & 0xf) >=0) && ((MyMODRM & 0xf) <=7)) {
                (*pMyDisasm).Instruction.Category = FPU_INSTRUCTION+COMPARISON_INSTRUCTION;
                (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "fcomip ");
                (void) strcpy ((*pMyDisasm).Argument1.ArgMnemonic, (*pRegistersFPU)[0]);
                (*pMyDisasm).Argument1.ArgType = REGISTER_TYPE+FPU_REG+REGS[0];
                (*pMyDisasm).Argument1.ArgSize = 80;
                (void) strcpy ((*pMyDisasm).Argument2.ArgMnemonic, (*pRegistersFPU)[(MyMODRM & 0xf)%8]);
                (*pMyDisasm).Argument2.ArgType = REGISTER_TYPE+FPU_REG+REGS[(MyMODRM & 0xf)%8];
                (*pMyDisasm).Argument2.ArgSize = 80;
            }
            else {
                FailDecode(pMyDisasm);
            }

        }
        else {
            FailDecode(pMyDisasm);
        }
    }
    GV.EIP_ += GV.DECALAGE_EIP+2;
}
