//
// sort.cpp
//
// Code generation for function 'sort'
//

// Include files
#include "sort.h"
#include "CalcT3MeshShapeFun_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "sortIdx.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo yd_emlrtRSI{
    76,     // lineNo
    "sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" // pathName
};

static emlrtRSInfo ae_emlrtRSI{
    79,     // lineNo
    "sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" // pathName
};

static emlrtRSInfo be_emlrtRSI{
    81,     // lineNo
    "sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" // pathName
};

static emlrtRSInfo ce_emlrtRSI{
    84,     // lineNo
    "sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" // pathName
};

static emlrtRSInfo de_emlrtRSI{
    87,     // lineNo
    "sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" // pathName
};

static emlrtRSInfo ee_emlrtRSI{
    90,     // lineNo
    "sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" // pathName
};

static emlrtRTEInfo sc_emlrtRTEI{
    56,     // lineNo
    24,     // colNo
    "sort", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" // pName
};

static emlrtRTEInfo tc_emlrtRTEI{
    75,     // lineNo
    26,     // colNo
    "sort", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m" // pName
};

// Function Definitions
namespace coder {
namespace internal {
void sort(const emlrtStack &sp, array<real_T, 1U> &x, array<int32_T, 1U> &idx)
{
  array<real_T, 1U> vwork;
  array<int32_T, 1U> iidx;
  emlrtStack b_st;
  emlrtStack st;
  int32_T dim;
  int32_T i;
  int32_T vlen;
  int32_T vstride;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  dim = 0;
  if (x.size(0) != 1) {
    dim = -1;
  }
  if (dim + 2 <= 1) {
    i = x.size(0);
  } else {
    i = 1;
  }
  vlen = i - 1;
  vwork.set_size(&sc_emlrtRTEI, &sp, i);
  idx.set_size(&tc_emlrtRTEI, &sp, x.size(0));
  st.site = &yd_emlrtRSI;
  vstride = 1;
  for (int32_T k{0}; k <= dim; k++) {
    vstride *= x.size(0);
  }
  st.site = &ae_emlrtRSI;
  st.site = &be_emlrtRSI;
  if (vstride > 2147483646) {
    b_st.site = &gb_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T j{0}; j < vstride; j++) {
    st.site = &ce_emlrtRSI;
    if (i > 2147483646) {
      b_st.site = &gb_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T k{0}; k <= vlen; k++) {
      vwork[k] = x[j + k * vstride];
    }
    st.site = &de_emlrtRSI;
    sortIdx(st, vwork, iidx);
    st.site = &ee_emlrtRSI;
    for (int32_T k{0}; k <= vlen; k++) {
      dim = j + k * vstride;
      x[dim] = vwork[k];
      idx[dim] = iidx[k];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

void sort(real_T x[3], int32_T idx[3])
{
  if ((x[0] <= x[1]) || muDoubleScalarIsNaN(x[1])) {
    if ((x[1] <= x[2]) || muDoubleScalarIsNaN(x[2])) {
      idx[0] = 1;
      idx[1] = 2;
      idx[2] = 3;
    } else if (x[0] <= x[2]) {
      real_T tmp;
      idx[0] = 1;
      idx[1] = 3;
      idx[2] = 2;
      tmp = x[1];
      x[1] = x[2];
      x[2] = tmp;
    } else {
      real_T tmp;
      idx[0] = 3;
      idx[1] = 1;
      idx[2] = 2;
      tmp = x[2];
      x[2] = x[1];
      x[1] = x[0];
      x[0] = tmp;
    }
  } else if ((x[0] <= x[2]) || muDoubleScalarIsNaN(x[2])) {
    real_T tmp;
    idx[0] = 2;
    idx[1] = 1;
    idx[2] = 3;
    tmp = x[0];
    x[0] = x[1];
    x[1] = tmp;
  } else if (x[1] <= x[2]) {
    real_T tmp;
    idx[0] = 2;
    idx[1] = 3;
    idx[2] = 1;
    tmp = x[0];
    x[0] = x[1];
    x[1] = x[2];
    x[2] = tmp;
  } else {
    real_T tmp;
    idx[0] = 3;
    idx[1] = 2;
    idx[2] = 1;
    tmp = x[0];
    x[0] = x[2];
    x[2] = tmp;
  }
}

} // namespace internal
} // namespace coder

// End of code generation (sort.cpp)
