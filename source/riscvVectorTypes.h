/*
 * Copyright (c) 2005-2019 Imperas Software Ltd., www.imperas.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied.
 *
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#pragma once

// VMI header files
#include "vmi/vmiTypes.h"

// model header files
#include "riscvTypeRefs.h"


//
// Vector width control
//
typedef enum riscvVShapeE {

                    // INTEGER ARGUMENTS
    RVVW_111_II,    // SEW
    RVVW_BBB_II,    // SEW8
    RVVW_EXT_II,    // SEW, VEXT.X.V
    RVVW_111_PI,    // SEW, Vd is predicate
    RVVW_111_SI,    // SEW, Vd is scalar
    RVVW_CIN_II,    // SEW, mask is carry-in (VADC etc)
    RVVW_CIN_PI,    // SEW, Vd is predicate, mask is carry-in (VMADC etc)
    RVVW_212_SI,    // 2*SEW = SEW   op 2*SEW, Vd is scalar
    RVVW_121_II,    // SEW   = 2*SEW op SEW
    RVVW_121_IIS,   // SEW   = 2*SEW op SEW, saturating result
    RVVW_211_IIQ,   // 2*SEW = SEW   op SEW, implicit widening
    RVVW_211_II,    // 2*SEW = SEW   op SEW
    RVVW_221_II,    // 2*SEW = 2*SEW op SEW

                    // FLOATING POINT ARGUMENTS
    RVVW_111_FF,    // SEW
    RVVW_111_PF,    // SEW, Vd is predicate
    RVVW_111_SF,    // SEW, Vd is scalar
    RVVW_212_SF,    // 2*SEW = SEW   op 2*SEW, Vd is scalar
    RVVW_121_FFQ,   // SEW   = 2*SEW op SEW, implicit widening
    RVVW_211_FFQ,   // 2*SEW = SEW   op SEW, implicit widening
    RVVW_211_FF,    // 2*SEW = SEW   op SEW
    RVVW_221_FF,    // 2*SEW = 2*SEW op SEW

                    // MIXED ARGUMENTS
    RVVW_111_FI,    // SEW, Fd=Is
    RVVW_111_IF,    // SEW, Id=Fs
    RVVW_21_FIQ,    // 2*SEW = SEW, Fd=Is
    RVVW_21_IFQ,    // 2*SEW = SEW, Id=Fs
    RVVW_12_FIQ,    // SEW = 2*SEW, implicit widening
    RVVW_12_IFQ,    // SEW = 2*SEW, implicit widening

                    // MASK ARGUMENTS
    RVVW_111_PP,    // SEW
    RVVW_111_IP,    // SEW

                    // SLIDING ARGUMENTS
    RVVW_111_GR,    // SEW, VRGATHER instructions
    RVVW_111_UP,    // SEW, VSLIDEUP instructions
    RVVW_111_DN,    // SEW, VSLIDEDOWN instructions
    RVVW_111_CMP,   // SEW, VCOMPRESS instruction

    RVVW_LAST       // KEEP LAST: for sizing

} riscvVShape;

//
// Externally-implemented vector operation callback
//
#define RISCV_VEXTERNAL_FN(_NAME) void _NAME( \
    riscvP  riscv,      \
    void   *userData,   \
    vmiReg *r,          \
    Uns32   SEW         \
)
typedef RISCV_VEXTERNAL_FN((*riscvVExternalFn));

