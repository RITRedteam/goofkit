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
 *      0x 0f 3a 44
 * ==================================================================== */
void __bea_callspec__ pclmulqdq_(PDISASM pMyDisasm)
{
    /* ========== 0x66 */
    if (GV.OperandSize == 16) {
        (*pMyDisasm).Prefix.OperandSize = MandatoryPrefix;
        GV.MemDecoration = 0;
        (*pMyDisasm).Instruction.Category = CLMUL_INSTRUCTION;

        GV.SSE_ = 1;
        GxEx(pMyDisasm);
        GV.SSE_ = 0;
        GV.EIP_++;
        if (!Security(0, pMyDisasm)) return;

        (*pMyDisasm).Instruction.Immediat = *((UInt8*)(UIntPtr) (GV.EIP_- 1));
        GV.ImmediatSize = 8;
        if ((*pMyDisasm).Instruction.Immediat == 0) {
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pclmullqlqdq ");
        }
        else if ((*pMyDisasm).Instruction.Immediat == 0x01 ) {
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pclmulhqlqdq ");
        }
        else if ((*pMyDisasm).Instruction.Immediat == 0x10 ) {
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pclmullqhqdq ");
        }
        else if ((*pMyDisasm).Instruction.Immediat == 0x011 ) {
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pclmulhqhqdq ");
        }
        else {
            (void) strcpy ((*pMyDisasm).Instruction.Mnemonic, "pclmulqdq ");
            GV.third_arg = 1;
            (void) CopyFormattedNumber(pMyDisasm, (char*) (*pMyDisasm).Argument3.ArgMnemonic, "%.2X",(Int64) *((UInt8*)(UIntPtr) (GV.EIP_- 1)));
            (*pMyDisasm).Argument3.ArgType = CONSTANT_TYPE+ABSOLUTE_;
            (*pMyDisasm).Argument3.ArgSize = 8;
        }
    }
    else {
        FailDecode(pMyDisasm);
    }
}
