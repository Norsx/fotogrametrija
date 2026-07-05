//
// sort.h
//
// Code generation for function 'sort'
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
namespace internal {
void sort(const emlrtStack &sp, array<real_T, 1U> &x, array<int32_T, 1U> &idx);

void sort(real_T x[3], int32_T idx[3]);

} // namespace internal
} // namespace coder

// End of code generation (sort.h)
