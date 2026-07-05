//
// sparse.cpp
//
// Code generation for function 'sparse'
//

// Include files
#include "sparse.h"
#include "CalcT3MeshShapeFun_data.h"
#include "rt_nonfinite.h"
#include "sparse1.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo j_emlrtRSI{
    85,              // lineNo
    "sparse/sparse", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pathName
};

static emlrtDCInfo c_emlrtDCI{
    13,       // lineNo
    1,        // colNo
    "sparse", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\sparfun\\sparse.m", // pName
    4 // checkKind
};

static emlrtRTEInfo ib_emlrtRTEI{
    13,       // lineNo
    1,        // colNo
    "sparse", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\sparfun\\sparse.m" // pName
};

// Function Definitions
namespace coder {
void d_sparse(const emlrtStack &sp, real_T varargin_1, real_T varargin_2,
              sparse *y)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T loop_ub;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &h_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &i_emlrtRSI;
  sparse::assertValidSize(b_st, varargin_1);
  b_st.site = &j_emlrtRSI;
  sparse::assertValidSize(b_st, varargin_2);
  y->m = static_cast<int32_T>(varargin_1);
  y->n = static_cast<int32_T>(varargin_2);
  y->d.set_size(&ib_emlrtRTEI, &st, 1);
  y->d[0] = 0.0;
  if (static_cast<int32_T>(varargin_2) + 1 < 0) {
    emlrtNonNegativeCheckR2012b(
        static_cast<real_T>(static_cast<int32_T>(varargin_2) + 1), &c_emlrtDCI,
        &st);
  }
  loop_ub = static_cast<int32_T>(varargin_2) + 1;
  y->colidx.set_size(&ib_emlrtRTEI, &st, static_cast<int32_T>(varargin_2) + 1);
  for (int32_T i{0}; i < loop_ub; i++) {
    y->colidx[i] = 1;
  }
  y->rowidx.set_size(&ib_emlrtRTEI, &st, 1);
  y->rowidx[0] = 1;
  y->maxnz = 1;
}

} // namespace coder

// End of code generation (sparse.cpp)
