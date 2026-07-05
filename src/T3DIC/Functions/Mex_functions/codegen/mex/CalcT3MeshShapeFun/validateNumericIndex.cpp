//
// validateNumericIndex.cpp
//
// Code generation for function 'validateNumericIndex'
//

// Include files
#include "validateNumericIndex.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRTEInfo f_emlrtRTEI{
    11,                                   // lineNo
    27,                                   // colNo
    "sparse/sparse_validateNumericIndex", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\private\\validateNumericIndex.m" // pName
};

static emlrtRTEInfo n_emlrtRTEI{
    12,                                   // lineNo
    27,                                   // colNo
    "sparse/sparse_validateNumericIndex", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\private\\validateNumericIndex.m" // pName
};

// Function Definitions
namespace coder {
void sparse_validateNumericIndex(const emlrtStack &sp, int32_T upperBound,
                                 const array<real_T, 1U> &idx)
{
  int32_T i;
  i = idx.size(0);
  for (int32_T k{0}; k < i; k++) {
    if ((!(muDoubleScalarFloor(idx[k]) == idx[k])) ||
        muDoubleScalarIsInf(idx[k]) || (!(idx[k] > 0.0))) {
      emlrtErrorWithMessageIdR2018a(&sp, &f_emlrtRTEI,
                                    "Coder:MATLAB:badsubscript",
                                    "Coder:MATLAB:badsubscript", 0);
    }
    if (!(idx[k] <= upperBound)) {
      emlrtErrorWithMessageIdR2018a(&sp, &n_emlrtRTEI,
                                    "Coder:builtins:IndexOutOfBounds",
                                    "Coder:builtins:IndexOutOfBounds", 6, 6,
                                    idx[k], 12, 1, 12, upperBound);
    }
  }
}

void sparse_validateNumericIndex(const emlrtStack &sp, int32_T upperBound,
                                 const real_T idx[3])
{
  for (int32_T k{0}; k < 3; k++) {
    real_T d;
    d = idx[k];
    if ((!(muDoubleScalarFloor(d) == d)) || muDoubleScalarIsInf(d)) {
      emlrtErrorWithMessageIdR2018a(&sp, &f_emlrtRTEI,
                                    "Coder:MATLAB:badsubscript",
                                    "Coder:MATLAB:badsubscript", 0);
    }
    if (!(d <= upperBound)) {
      emlrtErrorWithMessageIdR2018a(
          &sp, &n_emlrtRTEI, "Coder:builtins:IndexOutOfBounds",
          "Coder:builtins:IndexOutOfBounds", 6, 6, d, 12, 1, 12, upperBound);
    }
  }
}

} // namespace coder

// End of code generation (validateNumericIndex.cpp)
