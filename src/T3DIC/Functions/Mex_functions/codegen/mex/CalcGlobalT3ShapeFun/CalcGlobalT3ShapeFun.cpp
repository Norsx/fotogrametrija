//
// CalcGlobalT3ShapeFun.cpp
//
// Code generation for function 'CalcGlobalT3ShapeFun'
//

// Include files
#include "CalcGlobalT3ShapeFun.h"
#include "CalcGlobalT3ShapeFun_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "sparse.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo emlrtRSI{
    5,                      // lineNo
    "CalcGlobalT3ShapeFun", // fcnName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcGlobalT3"
    "Sh"
    "apeFun.m" // pathName
};

static emlrtRSInfo b_emlrtRSI{
    6,                      // lineNo
    "CalcGlobalT3ShapeFun", // fcnName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcGlobalT3"
    "Sh"
    "apeFun.m" // pathName
};

static emlrtRSInfo j_emlrtRSI{
    20,                        // lineNo
    "sparse/parenReference2D", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenReference2D.m" // pathName
};

static emlrtRSInfo k_emlrtRSI{
    81,                        // lineNo
    "parenReference2DColumns", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenReference2D.m" // pathName
};

static emlrtRSInfo l_emlrtRSI{
    93,                        // lineNo
    "parenReference2DColumns", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenReference2D.m" // pathName
};

static emlrtRSInfo m_emlrtRSI{
    104,                       // lineNo
    "parenReference2DColumns", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenReference2D.m" // pathName
};

static emlrtRTEInfo i_emlrtRTEI{
    92,                        // lineNo
    1,                         // colNo
    "parenReference2DColumns", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenReference2D.m" // pName
};

static emlrtBCInfo emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    5,                      // lineNo
    15,                     // colNo
    "col",                  // aName
    "CalcGlobalT3ShapeFun", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcGlobalT3"
    "Sh"
    "apeFun.m", // pName
    0           // checkKind
};

static emlrtBCInfo b_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    5,                      // lineNo
    41,                     // colNo
    "col",                  // aName
    "CalcGlobalT3ShapeFun", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcGlobalT3"
    "Sh"
    "apeFun.m", // pName
    0           // checkKind
};

static emlrtDCInfo emlrtDCI{
    5,                      // lineNo
    41,                     // colNo
    "CalcGlobalT3ShapeFun", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcGlobalT3"
    "Sh"
    "apeFun.m", // pName
    1           // checkKind
};

// Function Definitions
void CalcGlobalT3ShapeFun(const emlrtStack *sp, coder::sparse *PSI_X,
                          coder::sparse *PSI_Y,
                          const coder::array<real_T, 1U> &ind,
                          const coder::array<real_T, 2U> &col,
                          const real_T n_id[3], const coder::b_sparse *psi_x,
                          const coder::b_sparse *psi_y)
{
  coder::b_sparse r;
  coder::b_sparse r1;
  coder::b_sparse s;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T b_col[3];
  real_T b_col_tmp;
  real_T c_col_tmp;
  real_T col_tmp;
  int32_T colNnz;
  int32_T i;
  int32_T i1;
  int32_T nd;
  int32_T ub;
  boolean_T b;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &emlrtRSI;
  b_st.site = &c_emlrtRSI;
  c_st.site = &j_emlrtRSI;
  d_st.site = &k_emlrtRSI;
  ub = psi_x->m * 3;
  nd = ((((psi_x->colidx[1] - psi_x->colidx[0]) + psi_x->colidx[3]) -
         psi_x->colidx[2]) +
        psi_x->colidx[5]) -
       psi_x->colidx[4];
  if ((nd > ub) && (ub != 0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &i_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  d_st.site = &l_emlrtRSI;
  coder::sparse::spallocLike(d_st, psi_x->m, nd, s);
  if (nd != 0) {
    ub = 0;
    for (int32_T cidx{0}; cidx < 3; cidx++) {
      nd = cidx << 1;
      i = psi_x->colidx[nd];
      colNnz = psi_x->colidx[nd + 1] - i;
      d_st.site = &m_emlrtRSI;
      if (colNnz > 2147483646) {
        e_st.site = &i_emlrtRSI;
        coder::check_forloop_overflow_error(e_st);
      }
      for (int32_T k{0}; k < colNnz; k++) {
        nd = (i + k) - 1;
        i1 = ub + k;
        s.d[i1] = psi_x->d[nd];
        s.rowidx[i1] = psi_x->rowidx[nd];
      }
      if (colNnz - 1 >= 0) {
        ub += colNnz;
      }
      s.colidx[cidx + 1] = s.colidx[cidx] + colNnz;
    }
  }
  if (n_id[0] != static_cast<int32_T>(muDoubleScalarFloor(n_id[0]))) {
    emlrtIntegerCheckR2012b(n_id[0], &emlrtDCI, (emlrtConstCTX)sp);
  }
  if ((static_cast<int32_T>(n_id[0]) < 1) ||
      (static_cast<int32_T>(n_id[0]) > col.size(0))) {
    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(n_id[0]), 1, col.size(0),
                                  &b_emlrtBCI, (emlrtConstCTX)sp);
  }
  b_col[0] = col[static_cast<int32_T>(n_id[0]) - 1];
  if (n_id[1] != static_cast<int32_T>(muDoubleScalarFloor(n_id[1]))) {
    emlrtIntegerCheckR2012b(n_id[1], &emlrtDCI, (emlrtConstCTX)sp);
  }
  if ((static_cast<int32_T>(n_id[1]) < 1) ||
      (static_cast<int32_T>(n_id[1]) > col.size(0))) {
    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(n_id[1]), 1, col.size(0),
                                  &b_emlrtBCI, (emlrtConstCTX)sp);
  }
  b_col[1] = col[static_cast<int32_T>(n_id[1]) - 1];
  if (n_id[2] != static_cast<int32_T>(muDoubleScalarFloor(n_id[2]))) {
    emlrtIntegerCheckR2012b(n_id[2], &emlrtDCI, (emlrtConstCTX)sp);
  }
  if ((static_cast<int32_T>(n_id[2]) < 1) ||
      (static_cast<int32_T>(n_id[2]) > col.size(0))) {
    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(n_id[2]), 1, col.size(0),
                                  &b_emlrtBCI, (emlrtConstCTX)sp);
  }
  b_col[2] = col[static_cast<int32_T>(n_id[2]) - 1];
  st.site = &emlrtRSI;
  PSI_X->parenReference(st, ind, b_col, r);
  st.site = &emlrtRSI;
  r.plus(st, s, r1);
  b = ((static_cast<int32_T>(n_id[0]) < 1) ||
       (static_cast<int32_T>(n_id[0]) > col.size(0)));
  if (b) {
    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(n_id[0]), 1, col.size(0),
                                  &emlrtBCI, (emlrtConstCTX)sp);
  }
  b_col[0] = col[static_cast<int32_T>(n_id[0]) - 1];
  b = ((static_cast<int32_T>(n_id[1]) < 1) ||
       (static_cast<int32_T>(n_id[1]) > col.size(0)));
  if (b) {
    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(n_id[1]), 1, col.size(0),
                                  &emlrtBCI, (emlrtConstCTX)sp);
  }
  b_col[1] = col[static_cast<int32_T>(n_id[1]) - 1];
  b = ((static_cast<int32_T>(n_id[2]) < 1) ||
       (static_cast<int32_T>(n_id[2]) > col.size(0)));
  if (b) {
    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(n_id[2]), 1, col.size(0),
                                  &emlrtBCI, (emlrtConstCTX)sp);
  }
  b_col[2] = col[static_cast<int32_T>(n_id[2]) - 1];
  st.site = &emlrtRSI;
  PSI_X->parenAssign(st, r1, ind, b_col);
  st.site = &b_emlrtRSI;
  b_st.site = &c_emlrtRSI;
  c_st.site = &j_emlrtRSI;
  d_st.site = &k_emlrtRSI;
  ub = psi_y->m * 3;
  nd = ((((psi_y->colidx[2] - psi_y->colidx[1]) + psi_y->colidx[4]) -
         psi_y->colidx[3]) +
        psi_y->colidx[6]) -
       psi_y->colidx[5];
  if ((nd > ub) && (ub != 0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &i_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  d_st.site = &l_emlrtRSI;
  coder::sparse::spallocLike(d_st, psi_y->m, nd, s);
  if (nd != 0) {
    ub = 0;
    for (int32_T cidx{0}; cidx < 3; cidx++) {
      nd = cidx << 1;
      i = psi_y->colidx[nd + 1];
      colNnz = psi_y->colidx[nd + 2] - i;
      d_st.site = &m_emlrtRSI;
      if (colNnz > 2147483646) {
        e_st.site = &i_emlrtRSI;
        coder::check_forloop_overflow_error(e_st);
      }
      for (int32_T k{0}; k < colNnz; k++) {
        nd = (i + k) - 1;
        i1 = ub + k;
        s.d[i1] = psi_y->d[nd];
        s.rowidx[i1] = psi_y->rowidx[nd];
      }
      if (colNnz - 1 >= 0) {
        ub += colNnz;
      }
      s.colidx[cidx + 1] = s.colidx[cidx] + colNnz;
    }
  }
  col_tmp = col[(static_cast<int32_T>(n_id[0]) + col.size(0)) - 1];
  b_col[0] = col_tmp;
  b_col_tmp = col[(static_cast<int32_T>(n_id[1]) + col.size(0)) - 1];
  b_col[1] = b_col_tmp;
  c_col_tmp = col[(static_cast<int32_T>(n_id[2]) + col.size(0)) - 1];
  b_col[2] = c_col_tmp;
  st.site = &b_emlrtRSI;
  PSI_Y->parenReference(st, ind, b_col, r);
  st.site = &b_emlrtRSI;
  r.plus(st, s, r1);
  b_col[0] = col_tmp;
  b_col[1] = b_col_tmp;
  b_col[2] = c_col_tmp;
  st.site = &b_emlrtRSI;
  PSI_Y->parenAssign(st, r1, ind, b_col);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

// End of code generation (CalcGlobalT3ShapeFun.cpp)
