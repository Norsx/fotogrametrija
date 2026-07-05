//
// CalcT3MeshShapeFun.h
//
// Code generation for function 'CalcT3MeshShapeFun'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "sparse1.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
void CalcT3MeshShapeFun(const emlrtStack *sp, real_T ee,
                        const coder::array<real_T, 2U> &coor,
                        const coder::array<real_T, 2U> &conn, real_T ndof,
                        real_T Npx, const coder::array<real_T, 2U> &X,
                        const coder::array<real_T, 2U> &Y, coder::sparse *PSI_X,
                        coder::sparse *PSI_Y);

// End of code generation (CalcT3MeshShapeFun.h)
