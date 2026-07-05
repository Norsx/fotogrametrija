//
// CalcGlobalT3ShapeFun.h
//
// Code generation for function 'CalcGlobalT3ShapeFun'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "sparse.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
void CalcGlobalT3ShapeFun(const emlrtStack *sp, coder::sparse *PSI_X,
                          coder::sparse *PSI_Y,
                          const coder::array<real_T, 1U> &ind,
                          const coder::array<real_T, 2U> &col,
                          const real_T n_id[3], const coder::b_sparse *psi_x,
                          const coder::b_sparse *psi_y);

// End of code generation (CalcGlobalT3ShapeFun.h)
