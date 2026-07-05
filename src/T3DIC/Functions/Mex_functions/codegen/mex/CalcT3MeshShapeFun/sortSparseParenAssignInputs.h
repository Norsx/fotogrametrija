//
// sortSparseParenAssignInputs.h
//
// Code generation for function 'sortSparseParenAssignInputs'
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
class c_sparse;

}

// Function Declarations
namespace coder {
namespace internal {
void sortSparseParenAssignInputs(const emlrtStack &sp, const c_sparse &rhs,
                                 array<real_T, 1U> &r, real_T c[3],
                                 array<real_T, 2U> &rhs_out);

}
} // namespace coder

// End of code generation (sortSparseParenAssignInputs.h)
