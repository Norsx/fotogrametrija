//
// T3ElementShapeFun_V2.h
//
// Code generation for function 'T3ElementShapeFun_V2'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Declarations
namespace coder {
class b_sparse;

}

// Function Declarations
void T3ElementShapeFun_V2(const emlrtStack &sp, const real_T coor[6],
                          const coder::array<real_T, 1U> &X,
                          const coder::array<real_T, 1U> &Y,
                          coder::b_sparse &psi_x, coder::b_sparse &psi_y,
                          coder::array<real_T, 2U> &vec);

// End of code generation (T3ElementShapeFun_V2.h)
