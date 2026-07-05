//
// validateNumericIndex.h
//
// Code generation for function 'validateNumericIndex'
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

// Function Declarations
namespace coder {
void sparse_validateNumericIndex(const emlrtStack &sp, int32_T upperBound,
                                 const array<real_T, 1U> &idx);

void sparse_validateNumericIndex(const emlrtStack &sp, int32_T upperBound,
                                 const real_T idx[3]);

} // namespace coder

// End of code generation (validateNumericIndex.h)
