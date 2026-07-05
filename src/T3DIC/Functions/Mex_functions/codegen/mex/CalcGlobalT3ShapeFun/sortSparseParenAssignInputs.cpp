//
// sortSparseParenAssignInputs.cpp
//
// Code generation for function 'sortSparseParenAssignInputs'
//

// Include files
#include "sortSparseParenAssignInputs.h"
#include "CalcGlobalT3ShapeFun_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "sparse.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo qb_emlrtRSI{
    21,                            // lineNo
    "sortSparseParenAssignInputs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\sortSparseParenAssignInputs.m" // pathName
};

static emlrtRSInfo rb_emlrtRSI{
    25,                            // lineNo
    "sortSparseParenAssignInputs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\sortSparseParenAssignInputs.m" // pathName
};

static emlrtRSInfo sb_emlrtRSI{
    29,                            // lineNo
    "sortSparseParenAssignInputs", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\sortSparseParenAssignInputs.m" // pathName
};

static emlrtRSInfo tb_emlrtRSI{
    275,           // lineNo
    "sparse/full", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pathName
};

static emlrtRSInfo ub_emlrtRSI{
    74,         // lineNo
    "issorted", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\issorted.m" // pathName
};

static emlrtRSInfo vb_emlrtRSI{
    112,      // lineNo
    "looper", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\issorted.m" // pathName
};

static emlrtRSInfo wb_emlrtRSI{
    95,       // lineNo
    "looper", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\issorted.m" // pathName
};

static emlrtRSInfo xb_emlrtRSI{
    37,     // lineNo
    "sort", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m" // pathName
};

static emlrtRTEInfo s_emlrtRTEI{
    21,                            // lineNo
    1,                             // colNo
    "sortSparseParenAssignInputs", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\sortSparseParenAssignInputs.m" // pName
};

static emlrtRTEInfo t_emlrtRTEI{
    37,                            // lineNo
    1,                             // colNo
    "sortSparseParenAssignInputs", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\sortSparseParenAssignInputs.m" // pName
};

// Function Definitions
namespace coder {
namespace internal {
void sortSparseParenAssignInputs(const emlrtStack &sp, const b_sparse &rhs,
                                 array<real_T, 1U> &r, real_T c[3],
                                 array<real_T, 2U> &rhs_out)
{
  array<real_T, 2U> temp;
  array<int32_T, 1U> iidx;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T v_idx_1;
  int32_T a;
  int32_T dim;
  int32_T idx;
  int32_T loop_ub_tmp;
  int32_T n;
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T y;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  st.site = &qb_emlrtRSI;
  rhs_out.set_size(&s_emlrtRTEI, &st, rhs.m, 3);
  loop_ub_tmp = rhs.m * 3;
  for (idx = 0; idx < loop_ub_tmp; idx++) {
    rhs_out[idx] = 0.0;
  }
  for (n = 0; n < 3; n++) {
    dim = rhs.colidx[n + 1] - 1;
    a = rhs.colidx[n];
    b_st.site = &tb_emlrtRSI;
    if ((rhs.colidx[n] <= dim) && (dim > 2147483646)) {
      c_st.site = &i_emlrtRSI;
      check_forloop_overflow_error(c_st);
    }
    for (idx = a; idx <= dim; idx++) {
      rhs_out[(rhs.rowidx[idx - 1] + rhs_out.size(0) * n) - 1] = rhs.d[idx - 1];
    }
  }
  st.site = &rb_emlrtRSI;
  y = true;
  dim = 2;
  if (r.size(0) != 1) {
    dim = 1;
  }
  if (r.size(0) != 0) {
    if (dim <= 1) {
      idx = r.size(0);
    } else {
      idx = 1;
    }
    if (idx != 1) {
      b_st.site = &ub_emlrtRSI;
      if (dim == 2) {
        idx = -1;
      } else {
        idx = 0;
      }
      c_st.site = &wb_emlrtRSI;
      a = 0;
      exitg1 = false;
      while ((!exitg1) && (a <= idx)) {
        boolean_T exitg2;
        c_st.site = &vb_emlrtRSI;
        if (dim == 1) {
          n = r.size(0) - 1;
        } else {
          n = r.size(0);
        }
        d_st.site = &wb_emlrtRSI;
        if (n > 2147483646) {
          e_st.site = &i_emlrtRSI;
          check_forloop_overflow_error(e_st);
        }
        a = 0;
        exitg2 = false;
        while ((!exitg2) && (a <= n - 1)) {
          int32_T subs[2];
          subs[0] = a + 1;
          subs[1] = 1;
          subs[dim - 1]++;
          v_idx_1 = r[subs[0] - 1];
          if ((r[a] <= v_idx_1) || muDoubleScalarIsNaN(v_idx_1)) {
            a++;
          } else {
            y = false;
            exitg2 = true;
          }
        }
        if (!y) {
          exitg1 = true;
        } else {
          a = 1;
        }
      }
    }
  }
  guard1 = false;
  if (y) {
    y = true;
    a = 0;
    exitg1 = false;
    while ((!exitg1) && (a < 2)) {
      v_idx_1 = c[a + 1];
      if ((c[a] <= v_idx_1) || muDoubleScalarIsNaN(v_idx_1)) {
        a++;
      } else {
        y = false;
        exitg1 = true;
      }
    }
    if (!y) {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }
  if (guard1) {
    int32_T b_iidx[3];
    st.site = &sb_emlrtRSI;
    b_st.site = &xb_emlrtRSI;
    sort(b_st, r, iidx);
    sort(c, b_iidx);
    temp.set_size(&t_emlrtRTEI, &sp, rhs_out.size(0), 3);
    for (idx = 0; idx < loop_ub_tmp; idx++) {
      temp[idx] = rhs_out[idx];
    }
    if (r.size(0) > 1) {
      idx = r.size(0);
      for (a = 0; a < idx; a++) {
        rhs_out[a] = temp[(iidx[a] + temp.size(0) * (b_iidx[0] - 1)) - 1];
        rhs_out[a + rhs_out.size(0)] =
            temp[(iidx[a] + temp.size(0) * (b_iidx[1] - 1)) - 1];
        rhs_out[a + rhs_out.size(0) * 2] =
            temp[(iidx[a] + temp.size(0) * (b_iidx[2] - 1)) - 1];
      }
    } else if (r.size(0) == 1) {
      rhs_out[0] = temp[b_iidx[0] - 1];
      rhs_out[1] = temp[b_iidx[1] - 1];
      rhs_out[2] = temp[b_iidx[2] - 1];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

} // namespace internal
} // namespace coder

// End of code generation (sortSparseParenAssignInputs.cpp)
