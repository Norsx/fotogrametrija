//
// sparse1.cpp
//
// Code generation for function 'sparse1'
//

// Include files
#include "sparse1.h"
#include "T3ElementShapeFun_V2_data.h"
#include "T3ElementShapeFun_V2_types.h"
#include "bigProduct.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstddef>
#include <cstring>
#include <emmintrin.h>

// Variable Definitions
static emlrtRSInfo bb_emlrtRSI{
    264,                  // lineNo
    "sparse/parenAssign", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pathName
};

static emlrtRSInfo cb_emlrtRSI{
    62,                     // lineNo
    "sparse/parenAssign2D", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo eb_emlrtRSI{
    249,                    // lineNo
    "parenAssign2DColumns", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo fb_emlrtRSI{
    259,                    // lineNo
    "parenAssign2DColumns", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo hb_emlrtRSI{
    263,                    // lineNo
    "parenAssign2DColumns", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo ib_emlrtRSI{
    267,                    // lineNo
    "parenAssign2DColumns", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo kb_emlrtRSI{
    516,                  // lineNo
    "countNumnzInColumn", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo lb_emlrtRSI{
    410,       // lineNo
    "realloc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo mb_emlrtRSI{
    418,       // lineNo
    "realloc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo nb_emlrtRSI{
    423,       // lineNo
    "realloc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo qb_emlrtRSI{
    381,                 // lineNo
    "copyNonzeroValues", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRTEInfo f_emlrtRTEI{
    42,                     // lineNo
    23,                     // colNo
    "sparse/parenAssign2D", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pName
};

static emlrtRTEInfo g_emlrtRTEI{
    237,            // lineNo
    13,             // colNo
    "sparse/numel", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pName
};

static emlrtRTEInfo cb_emlrtRTEI{
    406,             // lineNo
    1,               // colNo
    "parenAssign2D", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pName
};

static emlrtRTEInfo db_emlrtRTEI{
    407,             // lineNo
    1,               // colNo
    "parenAssign2D", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pName
};

static emlrtRTEInfo eb_emlrtRTEI{
    414,             // lineNo
    1,               // colNo
    "parenAssign2D", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pName
};

static emlrtRTEInfo fb_emlrtRTEI{
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
  rowidxt.set_size(&cb_emlrtRTEI, &sp, numAlloc);
  for (overflow = 0; overflow < numAlloc; overflow++) {
    rowidxt[overflow] = b_this->rowidx[overflow];
  }
  numAlloc = b_this->d.size(0);
  dt.set_size(&db_emlrtRTEI, &sp, numAlloc);
  for (overflow = 0; overflow < numAlloc; overflow++) {
    dt[overflow] = b_this->d[overflow];
  }
  internal::bigProduct(b_this->m, overflow);
  if (overflow == 0) {
    st.site = &lb_emlrtRSI;
    internal::bigProduct(b_this->m, overflow);
    if (overflow != 0) {
      emlrtErrorWithMessageIdR2018a(&st, &g_emlrtRTEI,
                                    "Coder:toolbox:SparseNumelTooBig",
                                    "Coder:toolbox:SparseNumelTooBig", 0);
    }
    numAlloc = b_this->m * 6;
    numAlloc = muIntScalarMin_sint32(numAllocRequested, numAlloc);
    if (numAlloc <= 1) {
      numAlloc = 1;
    }
  } else if (numAllocRequested <= 1) {
    numAlloc = 1;
  } else {
    numAlloc = numAllocRequested;
  }
  b_this->rowidx.set_size(&eb_emlrtRTEI, &sp, numAlloc);
  b_this->d.set_size(&fb_emlrtRTEI, &sp, numAlloc);
  for (overflow = 0; overflow < numAlloc; overflow++) {
    b_this->rowidx[overflow] = 0;
    b_this->d[overflow] = 0.0;
  }
  b_this->maxnz = numAlloc;
  st.site = &mb_emlrtRSI;
  if (ub1 > 2147483646) {
    b_st.site = &r_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (numAlloc = 0; numAlloc < ub1; numAlloc++) {
    b_this->rowidx[numAlloc] = rowidxt[numAlloc];
    b_this->d[numAlloc] = dt[numAlloc];
  }
  st.site = &nb_emlrtRSI;
  if ((lb2 <= ub2) && (ub2 > 2147483646)) {
    b_st.site = &r_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (numAlloc = lb2; numAlloc <= ub2; numAlloc++) {
    overflow = (numAlloc + offs) - 1;
    b_this->rowidx[overflow] = rowidxt[numAlloc - 1];
    b_this->d[overflow] = dt[numAlloc - 1];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

int32_T sparse::copyNonzeroValues(const emlrtStack &sp, sparse *b_this,
                                  struct_T &rhsIter, int32_T outStart,
                                  const array<real_T, 2U> &rhs)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T b;
  int32_T outIdx;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  outIdx = outStart;
  b = b_this->m;
  st.site = &qb_emlrtRSI;
  if (b_this->m > 2147483646) {
    b_st.site = &r_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T k{0}; k < b; k++) {
    real_T rhsv;
    rhsv = rhs[rhsIter.idx - 1];
    rhsIter.idx++;
    rhsIter.row++;
    if (rhsv != 0.0) {
      b_this->rowidx[outIdx - 1] = k + 1;
      b_this->d[outIdx - 1] = rhsv;
      outIdx++;
    }
  }
  return outIdx;
}

int32_T sparse::countNumnzInColumn(const emlrtStack &sp,
                                   const array<real_T, 2U> &rhs,
                                   int32_T rhsIter_idx, int32_T sm)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T nz;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  nz = 0;
  st.site = &kb_emlrtRSI;
  if (sm > 2147483646) {
    b_st.site = &r_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T k{0}; k < sm; k++) {
    if (!(rhs[(rhsIter_idx + k) - 1] == 0.0)) {
      nz++;
    }
  }
  return nz;
}

void sparse::b_parenAssign(const emlrtStack &sp, const array<real_T, 2U> &rhs)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  struct_T rhsIter;
  int32_T sm;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &bb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (m != rhs.size(0)) {
    emlrtErrorWithMessageIdR2018a(&st, &f_emlrtRTEI,
                                  "MATLAB:subsassigndimmismatch",
                                  "MATLAB:subsassigndimmismatch", 0);
  }
  b_st.site = &cb_emlrtRSI;
  sm = m;
  rhsIter.idx = 1;
  rhsIter.col = 1;
  rhsIter.row = 1;
  for (int32_T cidx{0}; cidx < 3; cidx++) {
    int32_T col_tmp_tmp;
    int32_T nzColAlloc;
    int32_T nzRhs;
    col_tmp_tmp = cidx << 1;
    nzColAlloc = colidx[col_tmp_tmp + 2] - colidx[col_tmp_tmp + 1];
    c_st.site = &eb_emlrtRSI;
    nzRhs = sparse::countNumnzInColumn(c_st, rhs, rhsIter.idx, sm);
    if (nzColAlloc < nzRhs) {
      int32_T extraSpace;
      int32_T outIdx;
      extraSpace = nzRhs - nzColAlloc;
      nzRhs = colidx[colidx.size(0) - 1];
      nzColAlloc = (maxnz - nzRhs) + 1;
      if (nzColAlloc < extraSpace) {
        c_st.site = &fb_emlrtRSI;
        sparse::b_realloc(c_st, this, (maxnz + extraSpace) - nzColAlloc,
                          colidx[col_tmp_tmp + 1] - 1, colidx[col_tmp_tmp + 2],
                          nzRhs - 1, extraSpace);
      } else {
        nzColAlloc = (colidx[col_tmp_tmp + 2] + extraSpace) - 1;
        nzRhs -= colidx[col_tmp_tmp + 2];
        if (nzRhs > 0) {
          std::memmove((void *)&rowidx[nzColAlloc],
                       (void *)&rowidx[colidx[col_tmp_tmp + 2] - 1],
                       (uint32_T)((size_t)nzRhs * sizeof(int32_T)));
          std::memmove((void *)&d[nzColAlloc],
                       (void *)&d[colidx[col_tmp_tmp + 2] - 1],
                       (uint32_T)((size_t)nzRhs * sizeof(real_T)));
        }
      }
      c_st.site = &hb_emlrtRSI;
      sparse::copyNonzeroValues(c_st, this, rhsIter, colidx[col_tmp_tmp + 1],
                                rhs);
      outIdx = col_tmp_tmp + 3;
      nzColAlloc = ((((5 - col_tmp_tmp) / 4) << 2) + col_tmp_tmp) + 3;
      nzRhs = nzColAlloc - 4;
      for (col_tmp_tmp = outIdx; col_tmp_tmp <= nzRhs; col_tmp_tmp += 4) {
        __m128i r;
        r = _mm_loadu_si128((const __m128i *)&colidx[col_tmp_tmp - 1]);
        _mm_storeu_si128((__m128i *)&colidx[col_tmp_tmp - 1],
                         _mm_add_epi32(r, _mm_set1_epi32(extraSpace)));
      }
      for (col_tmp_tmp = nzColAlloc; col_tmp_tmp < 8; col_tmp_tmp++) {
        colidx[col_tmp_tmp - 1] = colidx[col_tmp_tmp - 1] + extraSpace;
      }
    } else {
      int32_T extraSpace;
      int32_T outIdx;
      c_st.site = &ib_emlrtRSI;
      outIdx = sparse::copyNonzeroValues(c_st, this, rhsIter,
                                         colidx[col_tmp_tmp + 1], rhs) -
               1;
      extraSpace = nzColAlloc - nzRhs;
      if (extraSpace > 0) {
        nzRhs = colidx[colidx.size(0) - 1] - colidx[col_tmp_tmp + 2];
        if (nzRhs > 0) {
          std::memmove((void *)&rowidx[outIdx],
                       (void *)&rowidx[colidx[col_tmp_tmp + 2] - 1],
                       (uint32_T)((size_t)nzRhs * sizeof(int32_T)));
          std::memmove((void *)&d[outIdx],
                       (void *)&d[colidx[col_tmp_tmp + 2] - 1],
                       (uint32_T)((size_t)nzRhs * sizeof(real_T)));
        }
        outIdx = col_tmp_tmp + 3;
        nzColAlloc = ((((5 - col_tmp_tmp) / 4) << 2) + col_tmp_tmp) + 3;
        nzRhs = nzColAlloc - 4;
        for (col_tmp_tmp = outIdx; col_tmp_tmp <= nzRhs; col_tmp_tmp += 4) {
          __m128i r;
          r = _mm_loadu_si128((const __m128i *)&colidx[col_tmp_tmp - 1]);
          _mm_storeu_si128((__m128i *)&colidx[col_tmp_tmp - 1],
                           _mm_sub_epi32(r, _mm_set1_epi32(extraSpace)));
        }
        for (col_tmp_tmp = nzColAlloc; col_tmp_tmp < 8; col_tmp_tmp++) {
          colidx[col_tmp_tmp - 1] = colidx[col_tmp_tmp - 1] - extraSpace;
        }
      }
    }
    rhsIter.col++;
    rhsIter.row = 1;
  }
}

void sparse::parenAssign(const emlrtStack &sp, const array<real_T, 2U> &rhs)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  struct_T rhsIter;
  int32_T sm;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &bb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (m != rhs.size(0)) {
    emlrtErrorWithMessageIdR2018a(&st, &f_emlrtRTEI,
                                  "MATLAB:subsassigndimmismatch",
                                  "MATLAB:subsassigndimmismatch", 0);
  }
  b_st.site = &cb_emlrtRSI;
  sm = m;
  rhsIter.idx = 1;
  rhsIter.col = 1;
  rhsIter.row = 1;
  for (int32_T cidx{0}; cidx < 3; cidx++) {
    int32_T col_tmp_tmp;
    int32_T nzColAlloc;
    int32_T nzRhs;
    col_tmp_tmp = cidx << 1;
    nzColAlloc = colidx[col_tmp_tmp + 1] - colidx[col_tmp_tmp];
    c_st.site = &eb_emlrtRSI;
    nzRhs = sparse::countNumnzInColumn(c_st, rhs, rhsIter.idx, sm);
    if (nzColAlloc < nzRhs) {
      int32_T extraSpace;
      int32_T outIdx;
      extraSpace = nzRhs - nzColAlloc;
      nzRhs = colidx[colidx.size(0) - 1];
      nzColAlloc = (maxnz - nzRhs) + 1;
      if (nzColAlloc < extraSpace) {
        c_st.site = &fb_emlrtRSI;
        sparse::b_realloc(c_st, this, (maxnz + extraSpace) - nzColAlloc,
                          colidx[col_tmp_tmp] - 1, colidx[col_tmp_tmp + 1],
                          nzRhs - 1, extraSpace);
      } else {
        nzColAlloc = (colidx[col_tmp_tmp + 1] + extraSpace) - 1;
        nzRhs -= colidx[col_tmp_tmp + 1];
        if (nzRhs > 0) {
          std::memmove((void *)&rowidx[nzColAlloc],
                       (void *)&rowidx[colidx[col_tmp_tmp + 1] - 1],
                       (uint32_T)((size_t)nzRhs * sizeof(int32_T)));
          std::memmove((void *)&d[nzColAlloc],
                       (void *)&d[colidx[col_tmp_tmp + 1] - 1],
                       (uint32_T)((size_t)nzRhs * sizeof(real_T)));
        }
      }
      c_st.site = &hb_emlrtRSI;
      sparse::copyNonzeroValues(c_st, this, rhsIter, colidx[col_tmp_tmp], rhs);
      outIdx = col_tmp_tmp + 2;
      nzColAlloc = ((((6 - col_tmp_tmp) / 4) << 2) + col_tmp_tmp) + 2;
      nzRhs = nzColAlloc - 4;
      for (col_tmp_tmp = outIdx; col_tmp_tmp <= nzRhs; col_tmp_tmp += 4) {
        __m128i r;
        r = _mm_loadu_si128((const __m128i *)&colidx[col_tmp_tmp - 1]);
        _mm_storeu_si128((__m128i *)&colidx[col_tmp_tmp - 1],
                         _mm_add_epi32(r, _mm_set1_epi32(extraSpace)));
      }
      for (col_tmp_tmp = nzColAlloc; col_tmp_tmp < 8; col_tmp_tmp++) {
        colidx[col_tmp_tmp - 1] = colidx[col_tmp_tmp - 1] + extraSpace;
      }
    } else {
      int32_T extraSpace;
      int32_T outIdx;
      c_st.site = &ib_emlrtRSI;
      outIdx = sparse::copyNonzeroValues(c_st, this, rhsIter,
                                         colidx[col_tmp_tmp], rhs) -
               1;
      extraSpace = nzColAlloc - nzRhs;
      if (extraSpace > 0) {
        nzRhs = colidx[colidx.size(0) - 1] - colidx[col_tmp_tmp + 1];
        if (nzRhs > 0) {
          std::memmove((void *)&rowidx[outIdx],
                       (void *)&rowidx[colidx[col_tmp_tmp + 1] - 1],
                       (uint32_T)((size_t)nzRhs * sizeof(int32_T)));
          std::memmove((void *)&d[outIdx],
                       (void *)&d[colidx[col_tmp_tmp + 1] - 1],
                       (uint32_T)((size_t)nzRhs * sizeof(real_T)));
        }
        outIdx = col_tmp_tmp + 2;
        nzColAlloc = ((((6 - col_tmp_tmp) / 4) << 2) + col_tmp_tmp) + 2;
        nzRhs = nzColAlloc - 4;
        for (col_tmp_tmp = outIdx; col_tmp_tmp <= nzRhs; col_tmp_tmp += 4) {
          __m128i r;
          r = _mm_loadu_si128((const __m128i *)&colidx[col_tmp_tmp - 1]);
          _mm_storeu_si128((__m128i *)&colidx[col_tmp_tmp - 1],
                           _mm_sub_epi32(r, _mm_set1_epi32(extraSpace)));
        }
        for (col_tmp_tmp = nzColAlloc; col_tmp_tmp < 8; col_tmp_tmp++) {
          colidx[col_tmp_tmp - 1] = colidx[col_tmp_tmp - 1] - extraSpace;
        }
      }
    }
    rhsIter.col++;
    rhsIter.row = 1;
  }
}

} // namespace coder

// End of code generation (sparse1.cpp)
