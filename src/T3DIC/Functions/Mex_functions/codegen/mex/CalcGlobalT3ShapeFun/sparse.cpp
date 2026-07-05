//
// sparse.cpp
//
// Code generation for function 'sparse'
//

// Include files
#include "sparse.h"
#include "CalcGlobalT3ShapeFun_data.h"
#include "bigProduct.h"
#include "eml_int_forloop_overflow_check.h"
#include "locBsearch.h"
#include "rt_nonfinite.h"
#include "sortSparseParenAssignInputs.h"
#include "validateNumericIndex.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstddef>
#include <cstring>
#include <emmintrin.h>

// Variable Definitions
static emlrtRSInfo d_emlrtRSI{
    25,                        // lineNo
    "sparse/parenReference2D", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenReference2D.m" // pathName
};

static emlrtRSInfo e_emlrtRSI{
    32,                        // lineNo
    "parenReference2DNumeric", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenReference2D.m" // pathName
};

static emlrtRSInfo f_emlrtRSI{
    33,                        // lineNo
    "parenReference2DNumeric", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenReference2D.m" // pathName
};

static emlrtRSInfo g_emlrtRSI{
    36,                        // lineNo
    "parenReference2DNumeric", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenReference2D.m" // pathName
};

static emlrtRSInfo h_emlrtRSI{
    53,                            // lineNo
    "parenReference2DNumericImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenReference2D.m" // pathName
};

static emlrtRSInfo n_emlrtRSI{
    1476,                 // lineNo
    "sparse/spallocLike", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pathName
};

static emlrtRSInfo p_emlrtRSI{
    176,             // lineNo
    "sparse/sparse", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pathName
};

static emlrtRSInfo q_emlrtRSI{
    142,             // lineNo
    "sparse/sparse", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pathName
};

static emlrtRSInfo t_emlrtRSI{
    292,           // lineNo
    "sparse/plus", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pathName
};

static emlrtRSInfo u_emlrtRSI{
    125,            // lineNo
    "sparse/binOp", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\binOp.m" // pathName
};

static emlrtRSInfo v_emlrtRSI{
    146,            // lineNo
    "sparse/binOp", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\binOp.m" // pathName
};

static emlrtRSInfo w_emlrtRSI{
    149,            // lineNo
    "sparse/binOp", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\binOp.m" // pathName
};

static emlrtRSInfo x_emlrtRSI{
    521,                // lineNo
    "allocEqsizeBinop", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\binOp.m" // pathName
};

static emlrtRSInfo y_emlrtRSI{
    331,                          // lineNo
    "sparseSparseRowExpandBinOp", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\binOp.m" // pathName
};

static emlrtRSInfo ab_emlrtRSI{
    341,                          // lineNo
    "sparseSparseRowExpandBinOp", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\binOp.m" // pathName
};

static emlrtRSInfo bb_emlrtRSI{
    264,                  // lineNo
    "sparse/parenAssign", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pathName
};

static emlrtRSInfo cb_emlrtRSI{
    72,                     // lineNo
    "sparse/parenAssign2D", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo db_emlrtRSI{
    84,                     // lineNo
    "parenAssign2DNumeric", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo eb_emlrtRSI{
    85,                     // lineNo
    "parenAssign2DNumeric", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo fb_emlrtRSI{
    88,                     // lineNo
    "parenAssign2DNumeric", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo gb_emlrtRSI{
    98,                         // lineNo
    "parenAssign2DNumericImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo hb_emlrtRSI{
    106,                        // lineNo
    "parenAssign2DNumericImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo ib_emlrtRSI{
    137,                        // lineNo
    "parenAssign2DNumericImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo jb_emlrtRSI{
    152,                        // lineNo
    "parenAssign2DNumericImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo kb_emlrtRSI{
    154,                        // lineNo
    "parenAssign2DNumericImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo lb_emlrtRSI{
    161,                        // lineNo
    "parenAssign2DNumericImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo mb_emlrtRSI{
    163,                        // lineNo
    "parenAssign2DNumericImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo nb_emlrtRSI{
    191,                        // lineNo
    "parenAssign2DNumericImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo ob_emlrtRSI{
    193,                        // lineNo
    "parenAssign2DNumericImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo pb_emlrtRSI{
    198,                        // lineNo
    "parenAssign2DNumericImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo yc_emlrtRSI{
    410,       // lineNo
    "realloc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo ad_emlrtRSI{
    418,       // lineNo
    "realloc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo bd_emlrtRSI{
    423,       // lineNo
    "realloc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo cd_emlrtRSI{
    326,                  // lineNo
    "shiftRowidxAndData", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo dd_emlrtRSI{
    327,                  // lineNo
    "shiftRowidxAndData", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo ed_emlrtRSI{
    345,          // lineNo
    "incrColIdx", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo fd_emlrtRSI{
    352,          // lineNo
    "decrColIdx", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRTEInfo emlrtRTEI{
    44,                            // lineNo
    1,                             // colNo
    "parenReference2DNumericImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenReference2D.m" // pName
};

static emlrtRTEInfo d_emlrtRTEI{
    1626,              // lineNo
    31,                // colNo
    "assertValidSize", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pName
};

static emlrtRTEInfo e_emlrtRTEI{
    1623,              // lineNo
    9,                 // colNo
    "assertValidSize", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pName
};

static emlrtRTEInfo f_emlrtRTEI{
    59,             // lineNo
    27,             // colNo
    "sparse/binOp", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\binOp.m" // pName
};

static emlrtRTEInfo g_emlrtRTEI{
    505,                // lineNo
    9,                  // colNo
    "allocEqsizeBinop", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\binOp.m" // pName
};

static emlrtRTEInfo j_emlrtRTEI{
    42,                     // lineNo
    23,                     // colNo
    "sparse/parenAssign2D", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pName
};

static emlrtRTEInfo k_emlrtRTEI{
    237,            // lineNo
    13,             // colNo
    "sparse/numel", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pName
};

static emlrtRTEInfo l_emlrtRTEI{
    250,      // lineNo
    17,       // colNo
    "sparse", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pName
};

static emlrtRTEInfo m_emlrtRTEI{
    240,      // lineNo
    22,       // colNo
    "sparse", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pName
};

static emlrtRTEInfo n_emlrtRTEI{
    1476,     // lineNo
    13,       // colNo
    "sparse", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pName
};

static emlrtRTEInfo o_emlrtRTEI{
    1492,     // lineNo
    38,       // colNo
    "sparse", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pName
};

static emlrtRTEInfo p_emlrtRTEI{
    1494,     // lineNo
    39,       // colNo
    "sparse", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pName
};

static emlrtRTEInfo q_emlrtRTEI{
    1495,     // lineNo
    39,       // colNo
    "sparse", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pName
};

static emlrtRTEInfo r_emlrtRTEI{
    98,              // lineNo
    6,               // colNo
    "parenAssign2D", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pName
};

static emlrtRTEInfo ab_emlrtRTEI{
    406,             // lineNo
    1,               // colNo
    "parenAssign2D", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pName
};

static emlrtRTEInfo bb_emlrtRTEI{
    407,             // lineNo
    1,               // colNo
    "parenAssign2D", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pName
};

static emlrtRTEInfo cb_emlrtRTEI{
    414,             // lineNo
    1,               // colNo
    "parenAssign2D", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pName
};

static emlrtRTEInfo db_emlrtRTEI{
    415,             // lineNo
    1,               // colNo
    "parenAssign2D", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pName
};

// Function Definitions
namespace coder {
void sparse::b_realloc(const emlrtStack &sp, sparse *b_this,
                       int32_T numAllocRequested, int32_T ub1, int32_T lb2,
                       int32_T ub2, int32_T offs)
{
  array<real_T, 1U> dt;
  array<int32_T, 1U> rowidxt;
  emlrtStack b_st;
  emlrtStack st;
  int32_T numAlloc;
  int32_T overflow;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  numAlloc = b_this->rowidx.size(0);
  rowidxt.set_size(&ab_emlrtRTEI, &sp, numAlloc);
  for (overflow = 0; overflow < numAlloc; overflow++) {
    rowidxt[overflow] = b_this->rowidx[overflow];
  }
  numAlloc = b_this->d.size(0);
  dt.set_size(&bb_emlrtRTEI, &sp, numAlloc);
  for (overflow = 0; overflow < numAlloc; overflow++) {
    dt[overflow] = b_this->d[overflow];
  }
  internal::bigProduct(b_this->m, b_this->n, overflow);
  if (overflow == 0) {
    st.site = &yc_emlrtRSI;
    internal::bigProduct(b_this->m, b_this->n, overflow);
    if (overflow != 0) {
      emlrtErrorWithMessageIdR2018a(&st, &k_emlrtRTEI,
                                    "Coder:toolbox:SparseNumelTooBig",
                                    "Coder:toolbox:SparseNumelTooBig", 0);
    }
    numAlloc = b_this->m * b_this->n;
    numAlloc = muIntScalarMin_sint32(numAllocRequested, numAlloc);
    if (numAlloc <= 1) {
      numAlloc = 1;
    }
  } else if (numAllocRequested <= 1) {
    numAlloc = 1;
  } else {
    numAlloc = numAllocRequested;
  }
  b_this->rowidx.set_size(&cb_emlrtRTEI, &sp, numAlloc);
  b_this->d.set_size(&db_emlrtRTEI, &sp, numAlloc);
  for (overflow = 0; overflow < numAlloc; overflow++) {
    b_this->rowidx[overflow] = 0;
    b_this->d[overflow] = 0.0;
  }
  b_this->maxnz = numAlloc;
  st.site = &ad_emlrtRSI;
  if (ub1 > 2147483646) {
    b_st.site = &i_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (numAlloc = 0; numAlloc < ub1; numAlloc++) {
    b_this->rowidx[numAlloc] = rowidxt[numAlloc];
    b_this->d[numAlloc] = dt[numAlloc];
  }
  st.site = &bd_emlrtRSI;
  if ((lb2 <= ub2) && (ub2 > 2147483646)) {
    b_st.site = &i_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (numAlloc = lb2; numAlloc <= ub2; numAlloc++) {
    overflow = (numAlloc + offs) - 1;
    b_this->rowidx[overflow] = rowidxt[numAlloc - 1];
    b_this->d[overflow] = dt[numAlloc - 1];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

void sparse::sparseSparseRowExpandBinOp(const emlrtStack &sp,
                                        const b_sparse &rowA, const b_sparse *b,
                                        b_sparse &s)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T bc;
  int32_T didx;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  didx = 1;
  s.colidx[0] = 1;
  bc = 1;
  for (int32_T c{0}; c < 3; c++) {
    real_T av;
    int32_T a_tmp;
    if (rowA.colidx[c] == rowA.colidx[c + 1]) {
      av = 0.0;
    } else {
      av = rowA.d[rowA.colidx[c] - 1];
    }
    a_tmp = b->colidx[bc - 1];
    if (a_tmp == b->colidx[bc]) {
      if (av != 0.0) {
        a_tmp = s.m;
        for (int32_T r{0}; r < a_tmp; r++) {
          if (av != 0.0) {
            s.d[didx - 1] = av;
            s.rowidx[didx - 1] = r + 1;
            didx++;
          }
        }
      }
      s.colidx[c + 1] = didx;
      bc++;
    } else {
      int32_T firstNonZeroRow_tmp;
      int32_T lastNonZeroRow_tmp;
      int32_T offset;
      firstNonZeroRow_tmp = b->rowidx[a_tmp - 1];
      lastNonZeroRow_tmp = b->rowidx[b->colidx[bc] - 2];
      if (av != 0.0) {
        for (int32_T r{0}; r <= firstNonZeroRow_tmp - 2; r++) {
          if (av != 0.0) {
            s.d[didx - 1] = av;
            s.rowidx[didx - 1] = r + 1;
            didx++;
          }
        }
      }
      offset = -1;
      st.site = &y_emlrtRSI;
      if ((firstNonZeroRow_tmp <= lastNonZeroRow_tmp) &&
          (lastNonZeroRow_tmp > 2147483646)) {
        b_st.site = &i_emlrtRSI;
        check_forloop_overflow_error(b_st);
      }
      for (int32_T r{firstNonZeroRow_tmp}; r <= lastNonZeroRow_tmp; r++) {
        int32_T i;
        i = a_tmp + offset;
        if (b->rowidx[i] == r) {
          real_T val;
          val = b->d[i] + av;
          if (val != 0.0) {
            s.d[didx - 1] = val;
            s.rowidx[didx - 1] = r;
            didx++;
          }
          offset++;
        } else if (av != 0.0) {
          s.d[didx - 1] = av;
          s.rowidx[didx - 1] = r;
          didx++;
        }
      }
      if (av != 0.0) {
        a_tmp = lastNonZeroRow_tmp + 1;
        firstNonZeroRow_tmp = s.m;
        st.site = &ab_emlrtRSI;
        if ((lastNonZeroRow_tmp + 1 <= s.m) && (s.m > 2147483646)) {
          b_st.site = &i_emlrtRSI;
          check_forloop_overflow_error(b_st);
        }
        for (int32_T r{a_tmp}; r <= firstNonZeroRow_tmp; r++) {
          if (av != 0.0) {
            s.d[didx - 1] = av;
            s.rowidx[didx - 1] = r;
            didx++;
          }
        }
      }
      s.colidx[c + 1] = didx;
      bc++;
    }
  }
}

void sparse::parenAssign(const emlrtStack &sp, const b_sparse &rhs,
                         const array<real_T, 1U> &varargin_1,
                         const real_T varargin_2[3])
{
  array<real_T, 2U> b_rhs;
  array<real_T, 1U> r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  real_T c[3];
  int32_T rhsIter_idx;
  int32_T sm_tmp;
  int32_T vectorUB;
  boolean_T found;
  boolean_T overflow;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  st.site = &bb_emlrtRSI;
  if (varargin_1.size(0) != rhs.m) {
    emlrtErrorWithMessageIdR2018a(&st, &j_emlrtRTEI,
                                  "MATLAB:subsassigndimmismatch",
                                  "MATLAB:subsassigndimmismatch", 0);
  }
  b_st.site = &cb_emlrtRSI;
  c_st.site = &db_emlrtRSI;
  sparse_validateNumericIndex(c_st, m, varargin_1);
  c_st.site = &eb_emlrtRSI;
  sparse_validateNumericIndex(c_st, n, varargin_2);
  sm_tmp = varargin_1.size(0);
  c_st.site = &fb_emlrtRSI;
  r.set_size(&r_emlrtRTEI, &c_st, varargin_1.size(0));
  for (vectorUB = 0; vectorUB < sm_tmp; vectorUB++) {
    r[vectorUB] = varargin_1[vectorUB];
  }
  c[0] = varargin_2[0];
  c[1] = varargin_2[1];
  c[2] = varargin_2[2];
  d_st.site = &gb_emlrtRSI;
  internal::sortSparseParenAssignInputs(d_st, rhs, r, c, b_rhs);
  rhsIter_idx = 0;
  overflow = (varargin_1.size(0) > 2147483646);
  for (int32_T cidx{0}; cidx < 3; cidx++) {
    real_T b_d;
    int32_T col_tmp;
    int32_T col_tmp_tmp;
    int32_T extraAlloc;
    int32_T pass;
    int32_T shiftleft;
    int32_T vidx;
    b_d = c[cidx];
    col_tmp_tmp = static_cast<int32_T>(b_d);
    col_tmp = static_cast<int32_T>(b_d) + 1;
    pass = 0;
    shiftleft = 0;
    extraAlloc = 0;
    vidx = 0;
    d_st.site = &hb_emlrtRSI;
    if (overflow) {
      e_st.site = &i_emlrtRSI;
      check_forloop_overflow_error(e_st);
    }
    for (int32_T ridx{0}; ridx < sm_tmp; ridx++) {
      real_T rhsv;
      int32_T nrow;
      rhsv = b_rhs[rhsIter_idx + ridx];
      if (ridx + 1 != sm_tmp) {
        nrow = static_cast<int32_T>(r[ridx + 1]);
      } else {
        nrow = 0;
      }
      vectorUB = static_cast<int32_T>(r[ridx]);
      if (vectorUB == nrow) {
        if (pass != 0) {
          shiftleft++;
          pass--;
        }
      } else {
        real_T thisv;
        int32_T b_vidx;
        int32_T cnt;
        if (pass == 0) {
          b_vidx = sparse_locBsearch(rowidx, vectorUB,
                                     colidx[static_cast<int32_T>(b_d) - 1],
                                     colidx[col_tmp_tmp], found);
          vidx = b_vidx - 1;
          if (found) {
            thisv = d[b_vidx - 1];
          } else {
            thisv = 0.0;
          }
          nrow = colidx[col_tmp_tmp] - b_vidx;
          if ((nrow > 1) || ((nrow == 1) && (r[ridx] != m))) {
            if (nrow > 1) {
              nrow = rowidx[b_vidx];
            } else {
              nrow = m + 1;
            }
            d_st.site = &ib_emlrtRSI;
            if ((ridx + 2 <= sm_tmp) && (sm_tmp > 2147483646)) {
              e_st.site = &i_emlrtRSI;
              check_forloop_overflow_error(e_st);
            }
            cnt = ridx + 1;
            while ((cnt + 1 <= sm_tmp) && (r[cnt] < nrow)) {
              pass++;
              cnt++;
            }
          }
          extraAlloc = pass;
          shiftleft = 0;
          if (thisv == 0.0) {
            if (colidx[colidx.size(0) - 1] + pass > maxnz) {
              if (pass + 1 < 10) {
                nrow = 9;
              } else {
                nrow = pass;
              }
              d_st.site = &jb_emlrtRSI;
              sparse::b_realloc(d_st, this, colidx[colidx.size(0) - 1] + nrow,
                                b_vidx, b_vidx + 1,
                                colidx[colidx.size(0) - 1] - 1, pass + 1);
            } else {
              d_st.site = &kb_emlrtRSI;
              nrow = (b_vidx + pass) + 1;
              cnt = (colidx[colidx.size(0) - 1] - b_vidx) - 1;
              if (cnt > 0) {
                e_st.site = &cd_emlrtRSI;
                std::memmove((void *)&rowidx[nrow], (void *)&rowidx[b_vidx],
                             (uint32_T)((size_t)cnt * sizeof(int32_T)));
                e_st.site = &dd_emlrtRSI;
                std::memmove((void *)&d[nrow], (void *)&d[b_vidx],
                             (uint32_T)((size_t)cnt * sizeof(real_T)));
              }
            }
            extraAlloc = pass + 1;
            vidx = b_vidx;
          } else if ((colidx[colidx.size(0) - 1] + pass) - 1 > maxnz) {
            if (pass < 10) {
              nrow = 10;
            } else {
              nrow = pass;
            }
            d_st.site = &lb_emlrtRSI;
            sparse::b_realloc(d_st, this,
                              (colidx[colidx.size(0) - 1] + nrow) - 1, b_vidx,
                              b_vidx + 1, colidx[colidx.size(0) - 1] - 1, pass);
          } else {
            d_st.site = &mb_emlrtRSI;
            nrow = b_vidx + pass;
            cnt = (colidx[colidx.size(0) - 1] - b_vidx) - 1;
            if (cnt > 0) {
              e_st.site = &cd_emlrtRSI;
              std::memmove((void *)&rowidx[nrow], (void *)&rowidx[b_vidx],
                           (uint32_T)((size_t)cnt * sizeof(int32_T)));
              e_st.site = &dd_emlrtRSI;
              std::memmove((void *)&d[nrow], (void *)&d[b_vidx],
                           (uint32_T)((size_t)cnt * sizeof(real_T)));
            }
          }
        } else {
          thisv = 0.0;
          pass--;
        }
        if ((thisv == 0.0) && (rhsv == 0.0)) {
          shiftleft++;
        } else if ((thisv != 0.0) && (rhsv != 0.0)) {
          d[vidx] = rhsv;
          vidx++;
        } else if (thisv == 0.0) {
          d[vidx] = rhsv;
          rowidx[vidx] = vectorUB;
          vidx++;
        } else {
          shiftleft++;
        }
        if (pass == 0) {
          nrow = extraAlloc - shiftleft;
          if (nrow > 0) {
            d_st.site = &nb_emlrtRSI;
            cnt = n + 1;
            e_st.site = &ed_emlrtRSI;
            if ((static_cast<int32_T>(b_d) + 1 <= cnt) && (cnt > 2147483646)) {
              f_st.site = &i_emlrtRSI;
              check_forloop_overflow_error(f_st);
            }
            b_vidx = ((((cnt - static_cast<int32_T>(b_d)) / 4) << 2) +
                      static_cast<int32_T>(b_d)) +
                     1;
            vectorUB = b_vidx - 4;
            for (int32_T k{col_tmp}; k <= vectorUB; k += 4) {
              __m128i b_r;
              b_r = _mm_loadu_si128((const __m128i *)&colidx[k - 1]);
              _mm_storeu_si128((__m128i *)&colidx[k - 1],
                               _mm_add_epi32(b_r, _mm_set1_epi32(nrow)));
            }
            for (int32_T k{b_vidx}; k <= cnt; k++) {
              colidx[k - 1] = colidx[k - 1] + nrow;
            }
          } else if (nrow < 0) {
            d_st.site = &ob_emlrtRSI;
            nrow = shiftleft - extraAlloc;
            cnt = n + 1;
            e_st.site = &fd_emlrtRSI;
            if ((static_cast<int32_T>(b_d) + 1 <= cnt) && (cnt > 2147483646)) {
              f_st.site = &i_emlrtRSI;
              check_forloop_overflow_error(f_st);
            }
            b_vidx = ((((cnt - static_cast<int32_T>(b_d)) / 4) << 2) +
                      static_cast<int32_T>(b_d)) +
                     1;
            vectorUB = b_vidx - 4;
            for (int32_T k{col_tmp}; k <= vectorUB; k += 4) {
              __m128i b_r;
              b_r = _mm_loadu_si128((const __m128i *)&colidx[k - 1]);
              _mm_storeu_si128((__m128i *)&colidx[k - 1],
                               _mm_sub_epi32(b_r, _mm_set1_epi32(nrow)));
            }
            for (int32_T k{b_vidx}; k <= cnt; k++) {
              colidx[k - 1] = colidx[k - 1] - nrow;
            }
          }
          if (shiftleft != 0) {
            d_st.site = &pb_emlrtRSI;
            nrow = vidx + shiftleft;
            cnt = (colidx[colidx.size(0) - 1] - vidx) - 1;
            if (cnt > 0) {
              e_st.site = &cd_emlrtRSI;
              std::memmove((void *)&rowidx[vidx], (void *)&rowidx[nrow],
                           (uint32_T)((size_t)cnt * sizeof(int32_T)));
              e_st.site = &dd_emlrtRSI;
              std::memmove((void *)&d[vidx], (void *)&d[nrow],
                           (uint32_T)((size_t)cnt * sizeof(real_T)));
            }
          }
        }
      }
    }
    if (sm_tmp - 1 >= 0) {
      rhsIter_idx += sm_tmp;
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

void sparse::parenReference(const emlrtStack &sp,
                            const array<real_T, 1U> &varargin_1,
                            const real_T varargin_2[3], b_sparse &s) const
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  int32_T colNnz;
  int32_T k;
  int32_T sm_tmp;
  boolean_T found;
  boolean_T overflow;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &c_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &d_emlrtRSI;
  c_st.site = &e_emlrtRSI;
  sparse_validateNumericIndex(c_st, m, varargin_1);
  c_st.site = &f_emlrtRSI;
  sparse_validateNumericIndex(c_st, n, varargin_2);
  sm_tmp = varargin_1.size(0);
  c_st.site = &g_emlrtRSI;
  if (varargin_1.size(0) * 3 < 0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  s.d.set_size(&l_emlrtRTEI, &c_st, 0);
  s.rowidx.set_size(&l_emlrtRTEI, &c_st, 0);
  s.colidx.set_size(&l_emlrtRTEI, &c_st, 4);
  s.colidx[1] = 0;
  s.colidx[2] = 0;
  s.colidx[3] = 0;
  s.colidx[0] = 1;
  colNnz = 1;
  k = 0;
  overflow = (varargin_1.size(0) > 2147483646);
  for (int32_T cidx{0}; cidx < 3; cidx++) {
    real_T nt;
    nt = varargin_2[cidx];
    d_st.site = &h_emlrtRSI;
    if (overflow) {
      e_st.site = &i_emlrtRSI;
      check_forloop_overflow_error(e_st);
    }
    for (int32_T ridx{0}; ridx < sm_tmp; ridx++) {
      int32_T idx;
      idx = sparse_locBsearch(rowidx, static_cast<int32_T>(varargin_1[ridx]),
                              colidx[static_cast<int32_T>(nt) - 1],
                              colidx[static_cast<int32_T>(nt)], found);
      if (found) {
        real_T b_d;
        int32_T i;
        int32_T i1;
        i = s.d.size(0);
        i1 = s.d.size(0) + 1;
        s.d.set_size(&m_emlrtRTEI, &c_st, s.d.size(0) + 1);
        b_d = d[idx - 1];
        s.d[i] = b_d;
        s.rowidx.set_size(&m_emlrtRTEI, &c_st, i1);
        s.rowidx[i] = ridx + 1;
        s.d[k] = b_d;
        s.rowidx[k] = ridx + 1;
        k = i1;
        colNnz++;
      }
    }
    s.colidx[cidx + 1] = colNnz;
  }
  if (s.colidx[3] - 1 == 0) {
    s.rowidx.set_size(&l_emlrtRTEI, &c_st, 1);
    s.rowidx[0] = 1;
    s.d.set_size(&l_emlrtRTEI, &c_st, 1);
    s.d[0] = 0.0;
  }
  s.m = varargin_1.size(0);
}

void b_sparse::plus(const emlrtStack &sp, const b_sparse &b, b_sparse &s) const
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T bidx;
  int32_T nza;
  int32_T offset;
  int32_T tmp;
  int32_T y;
  boolean_T x[2];
  boolean_T addInRange;
  boolean_T exitg1;
  boolean_T mulInRange;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &t_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if ((m != 1) && (b.m != 1) && (m != b.m)) {
    emlrtErrorWithMessageIdR2018a(&st, &f_emlrtRTEI, "MATLAB:dimagree",
                                  "MATLAB:dimagree", 0);
  }
  y = muIntScalarMax_sint32(m, b.m);
  b_st.site = &u_emlrtRSI;
  nza = colidx[colidx.size(0) - 1] - 1;
  bidx = b.colidx[b.colidx.size(0) - 1] - 1;
  if ((m != b.m) && (m == 1)) {
    nza *= b.m;
  }
  addInRange = (nza <= MAX_int32_T - bidx);
  tmp = 3 * (y >> 16);
  offset = tmp >> 16;
  if (offset <= 0) {
    offset = 0;
    if (3 * (y & 65535) > MAX_int32_T - (tmp << 16)) {
      offset = 1;
    }
  }
  mulInRange = (offset == 0);
  if ((!addInRange) && (!mulInRange)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &g_emlrtRTEI,
                                  "Coder:toolbox:SparseFuncAlmostFull",
                                  "Coder:toolbox:SparseFuncAlmostFull", 0);
  }
  if (addInRange) {
    nza += bidx;
  } else {
    nza = MAX_int32_T;
  }
  if (mulInRange) {
    bidx = 3 * y;
  } else {
    bidx = MAX_int32_T;
  }
  nza = muIntScalarMin_sint32(nza, bidx);
  if (nza < 1) {
    nza = 1;
  }
  c_st.site = &x_emlrtRSI;
  s.m = y;
  s.d.set_size(&o_emlrtRTEI, &c_st, nza);
  s.rowidx.set_size(&p_emlrtRTEI, &c_st, nza);
  s.colidx.set_size(&q_emlrtRTEI, &c_st, 4);
  x[0] = (m == b.m);
  x[1] = true;
  addInRange = true;
  nza = 0;
  exitg1 = false;
  while ((!exitg1) && (nza < 2)) {
    if (!x[nza]) {
      addInRange = false;
      exitg1 = true;
    } else {
      nza++;
    }
  }
  if (addInRange) {
    int32_T didx;
    didx = 1;
    s.colidx[0] = 1;
    for (int32_T c{0}; c < 3; c++) {
      nza = colidx[c] - 1;
      bidx = b.colidx[c] - 1;
      tmp = colidx[c + 1];
      addInRange = (colidx[c] < tmp);
      offset = b.colidx[c + 1];
      mulInRange = (b.colidx[c] < offset);
      while (addInRange || mulInRange) {
        while ((nza + 1 < tmp) &&
               ((!mulInRange) || (rowidx[nza] < b.rowidx[bidx]))) {
          if (d[nza] != 0.0) {
            s.d[didx - 1] = d[nza];
            s.rowidx[didx - 1] = rowidx[nza];
            didx++;
          }
          nza++;
        }
        addInRange = (nza + 1 < tmp);
        while ((bidx + 1 < offset) &&
               ((!addInRange) || (b.rowidx[bidx] < rowidx[nza]))) {
          if (b.d[bidx] != 0.0) {
            s.d[didx - 1] = b.d[bidx];
            s.rowidx[didx - 1] = b.rowidx[bidx];
            didx++;
          }
          bidx++;
        }
        while ((nza + 1 < tmp) && (bidx + 1 < offset) &&
               (rowidx[nza] == b.rowidx[bidx])) {
          real_T val;
          val = d[nza] + b.d[bidx];
          if (val != 0.0) {
            s.d[didx - 1] = val;
            s.rowidx[didx - 1] = b.rowidx[bidx];
            didx++;
          }
          bidx++;
          nza++;
        }
        addInRange = (nza + 1 < tmp);
        mulInRange = (bidx + 1 < offset);
      }
      s.colidx[c + 1] = didx;
    }
  } else if (m == 1) {
    int32_T bc;
    int32_T didx;
    b_st.site = &v_emlrtRSI;
    didx = 1;
    s.colidx[0] = 1;
    bc = 1;
    for (int32_T c{0}; c < 3; c++) {
      real_T av;
      if (colidx[c] == colidx[c + 1]) {
        av = 0.0;
      } else {
        av = d[colidx[c] - 1];
      }
      nza = b.colidx[bc - 1];
      if (nza == b.colidx[bc]) {
        if (av != 0.0) {
          for (int32_T r{0}; r < y; r++) {
            if (av != 0.0) {
              s.d[didx - 1] = av;
              s.rowidx[didx - 1] = r + 1;
              didx++;
            }
          }
        }
        s.colidx[c + 1] = didx;
        bc++;
      } else {
        int32_T lastNonZeroRow_tmp;
        tmp = b.rowidx[nza - 1];
        lastNonZeroRow_tmp = b.rowidx[b.colidx[bc] - 2];
        if (av != 0.0) {
          for (int32_T r{0}; r <= tmp - 2; r++) {
            if (av != 0.0) {
              s.d[didx - 1] = av;
              s.rowidx[didx - 1] = r + 1;
              didx++;
            }
          }
        }
        offset = -1;
        c_st.site = &y_emlrtRSI;
        if ((tmp <= lastNonZeroRow_tmp) && (lastNonZeroRow_tmp > 2147483646)) {
          d_st.site = &i_emlrtRSI;
          check_forloop_overflow_error(d_st);
        }
        for (int32_T r{tmp}; r <= lastNonZeroRow_tmp; r++) {
          bidx = nza + offset;
          if (b.rowidx[bidx] == r) {
            real_T val;
            val = av + b.d[bidx];
            if (val != 0.0) {
              s.d[didx - 1] = val;
              s.rowidx[didx - 1] = r;
              didx++;
            }
            offset++;
          } else if (av != 0.0) {
            s.d[didx - 1] = av;
            s.rowidx[didx - 1] = r;
            didx++;
          }
        }
        if (av != 0.0) {
          nza = lastNonZeroRow_tmp + 1;
          c_st.site = &ab_emlrtRSI;
          if ((lastNonZeroRow_tmp + 1 <= y) && (y > 2147483646)) {
            d_st.site = &i_emlrtRSI;
            check_forloop_overflow_error(d_st);
          }
          for (int32_T r{nza}; r <= y; r++) {
            if (av != 0.0) {
              s.d[didx - 1] = av;
              s.rowidx[didx - 1] = r;
              didx++;
            }
          }
        }
        s.colidx[c + 1] = didx;
        bc++;
      }
    }
  } else if (b.m == 1) {
    b_st.site = &w_emlrtRSI;
    sparse::sparseSparseRowExpandBinOp(b_st, b, this, s);
  }
}

void sparse::spallocLike(const emlrtStack &sp, int32_T b_m, int32_T nzmax,
                         b_sparse &s)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T numalloc;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &n_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &q_emlrtRSI;
  if (b_m < 0) {
    emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI,
                                  "Coder:toolbox:SparseNegativeSize",
                                  "Coder:toolbox:SparseNegativeSize", 0);
  }
  if (b_m >= MAX_int32_T) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &d_emlrtRTEI, "Coder:toolbox:SparseMaxSize",
        "Coder:toolbox:SparseMaxSize", 2, 12, MAX_int32_T);
  }
  s.m = b_m;
  b_st.site = &p_emlrtRSI;
  if (nzmax < 0) {
    emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI,
                                  "Coder:toolbox:SparseNegativeSize",
                                  "Coder:toolbox:SparseNegativeSize", 0);
  }
  if (nzmax >= MAX_int32_T) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &d_emlrtRTEI, "Coder:toolbox:SparseMaxSize",
        "Coder:toolbox:SparseMaxSize", 2, 12, MAX_int32_T);
  }
  numalloc = muIntScalarMax_sint32(nzmax, 1);
  s.d.set_size(&n_emlrtRTEI, &st, numalloc);
  for (int32_T i{0}; i < numalloc; i++) {
    s.d[i] = 0.0;
  }
  s.colidx.set_size(&n_emlrtRTEI, &st, 4);
  s.rowidx.set_size(&n_emlrtRTEI, &st, numalloc);
  for (int32_T i{0}; i < numalloc; i++) {
    s.rowidx[i] = 0;
  }
  s.colidx[0] = 1;
  s.colidx[1] = 1;
  s.colidx[2] = 1;
  s.colidx[3] = 1;
}

} // namespace coder

// End of code generation (sparse.cpp)
