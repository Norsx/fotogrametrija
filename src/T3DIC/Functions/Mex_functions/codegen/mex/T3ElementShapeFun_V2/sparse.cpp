//
// sparse.cpp
//
// Code generation for function 'sparse'
//

// Include files
#include "sparse.h"
#include "rt_nonfinite.h"
#include "sparse1.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo x_emlrtRSI{
    13,       // lineNo
    "sparse", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\sparfun\\sparse.m" // pathName
};

static emlrtRSInfo y_emlrtRSI{
    84,              // lineNo
    "sparse/sparse", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pathName
};

static emlrtRSInfo ab_emlrtRSI{
    1621,              // lineNo
    "assertValidSize", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pathName
};

static emlrtRTEInfo c_emlrtRTEI{
    58,                   // lineNo
    23,                   // colNo
    "assertValidSizeArg", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\assertValidSizeArg.m" // pName
};

static emlrtRTEInfo d_emlrtRTEI{
    1626,              // lineNo
    31,                // colNo
    "assertValidSize", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pName
};

static emlrtRTEInfo bb_emlrtRTEI{
    13,       // lineNo
    1,        // colNo
    "sparse", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\sparfun\\sparse.m" // pName
};

// Function Definitions
namespace coder {
void b_sparse(const emlrtStack &sp, real_T varargin_1, sparse *y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &x_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &y_emlrtRSI;
  c_st.site = &ab_emlrtRSI;
  if (varargin_1 != varargin_1) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &c_emlrtRTEI, "Coder:MATLAB:NonIntegerInput",
        "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
  }
  if (!(varargin_1 < 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &d_emlrtRTEI, "Coder:toolbox:SparseMaxSize",
        "Coder:toolbox:SparseMaxSize", 2, 12, MAX_int32_T);
  }
  y->m = static_cast<int32_T>(varargin_1);
  y->d.set_size(&bb_emlrtRTEI, &st, 1);
  y->d[0] = 0.0;
  y->colidx.set_size(&bb_emlrtRTEI, &st, 7);
  for (int32_T i{0}; i < 7; i++) {
    y->colidx[i] = 1;
  }
  y->rowidx.set_size(&bb_emlrtRTEI, &st, 1);
  y->rowidx[0] = 1;
  y->maxnz = 1;
}

} // namespace coder

// End of code generation (sparse.cpp)
