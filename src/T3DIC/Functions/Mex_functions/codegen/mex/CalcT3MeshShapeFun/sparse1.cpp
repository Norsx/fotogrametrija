//
// sparse1.cpp
//
// Code generation for function 'sparse1'
//

// Include files
#include "sparse1.h"
#include "CalcT3MeshShapeFun_data.h"
#include "CalcT3MeshShapeFun_types.h"
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
static emlrtRSInfo k_emlrtRSI{
    1621,              // lineNo
    "assertValidSize", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pathName
};

static emlrtRSInfo mb_emlrtRSI{
    264,                  // lineNo
    "sparse/parenAssign", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pathName
};

static emlrtRSInfo nb_emlrtRSI{
    62,                     // lineNo
    "sparse/parenAssign2D", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo pb_emlrtRSI{
    249,                    // lineNo
    "parenAssign2DColumns", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo qb_emlrtRSI{
    259,                    // lineNo
    "parenAssign2DColumns", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo sb_emlrtRSI{
    263,                    // lineNo
    "parenAssign2DColumns", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo tb_emlrtRSI{
    267,                    // lineNo
    "parenAssign2DColumns", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo vb_emlrtRSI{
    516,                  // lineNo
    "countNumnzInColumn", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo wb_emlrtRSI{
    410,       // lineNo
    "realloc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo xb_emlrtRSI{
    418,       // lineNo
    "realloc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo yb_emlrtRSI{
    423,       // lineNo
    "realloc", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo ac_emlrtRSI{
    326,                  // lineNo
    "shiftRowidxAndData", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo bc_emlrtRSI{
    327,                  // lineNo
    "shiftRowidxAndData", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo cc_emlrtRSI{
    381,                 // lineNo
    "copyNonzeroValues", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo gc_emlrtRSI{
    25,                        // lineNo
    "sparse/parenReference2D", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenReference2D.m" // pathName
};

static emlrtRSInfo hc_emlrtRSI{
    32,                        // lineNo
    "parenReference2DNumeric", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenReference2D.m" // pathName
};

static emlrtRSInfo ic_emlrtRSI{
    33,                        // lineNo
    "parenReference2DNumeric", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenReference2D.m" // pathName
};

static emlrtRSInfo jc_emlrtRSI{
    36,                        // lineNo
    "parenReference2DNumeric", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenReference2D.m" // pathName
};

static emlrtRSInfo kc_emlrtRSI{
    53,                            // lineNo
    "parenReference2DNumericImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenReference2D.m" // pathName
};

static emlrtRSInfo pc_emlrtRSI{
    1476,                 // lineNo
    "sparse/spallocLike", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pathName
};

static emlrtRSInfo rc_emlrtRSI{
    176,             // lineNo
    "sparse/sparse", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pathName
};

static emlrtRSInfo sc_emlrtRSI{
    142,             // lineNo
    "sparse/sparse", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pathName
};

static emlrtRSInfo uc_emlrtRSI{
    292,           // lineNo
    "sparse/plus", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pathName
};

static emlrtRSInfo vc_emlrtRSI{
    125,            // lineNo
    "sparse/binOp", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\binOp.m" // pathName
};

static emlrtRSInfo wc_emlrtRSI{
    146,            // lineNo
    "sparse/binOp", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\binOp.m" // pathName
};

static emlrtRSInfo xc_emlrtRSI{
    149,            // lineNo
    "sparse/binOp", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\binOp.m" // pathName
};

static emlrtRSInfo yc_emlrtRSI{
    521,                // lineNo
    "allocEqsizeBinop", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\binOp.m" // pathName
};

static emlrtRSInfo ad_emlrtRSI{
    331,                          // lineNo
    "sparseSparseRowExpandBinOp", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\binOp.m" // pathName
};

static emlrtRSInfo bd_emlrtRSI{
    341,                          // lineNo
    "sparseSparseRowExpandBinOp", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\binOp.m" // pathName
};

static emlrtRSInfo cd_emlrtRSI{
    72,                     // lineNo
    "sparse/parenAssign2D", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo dd_emlrtRSI{
    84,                     // lineNo
    "parenAssign2DNumeric", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo ed_emlrtRSI{
    85,                     // lineNo
    "parenAssign2DNumeric", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo fd_emlrtRSI{
    88,                     // lineNo
    "parenAssign2DNumeric", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo gd_emlrtRSI{
    98,                         // lineNo
    "parenAssign2DNumericImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo hd_emlrtRSI{
    106,                        // lineNo
    "parenAssign2DNumericImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo id_emlrtRSI{
    137,                        // lineNo
    "parenAssign2DNumericImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo jd_emlrtRSI{
    152,                        // lineNo
    "parenAssign2DNumericImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo kd_emlrtRSI{
    154,                        // lineNo
    "parenAssign2DNumericImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo ld_emlrtRSI{
    161,                        // lineNo
    "parenAssign2DNumericImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo md_emlrtRSI{
    163,                        // lineNo
    "parenAssign2DNumericImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo nd_emlrtRSI{
    191,                        // lineNo
    "parenAssign2DNumericImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo od_emlrtRSI{
    193,                        // lineNo
    "parenAssign2DNumericImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo pd_emlrtRSI{
    198,                        // lineNo
    "parenAssign2DNumericImpl", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo ye_emlrtRSI{
    345,          // lineNo
    "incrColIdx", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRSInfo af_emlrtRSI{
    352,          // lineNo
    "decrColIdx", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pathName
};

static emlrtRTEInfo g_emlrtRTEI{
    1623,              // lineNo
    9,                 // colNo
    "assertValidSize", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pName
};

static emlrtRTEInfo h_emlrtRTEI{
    1626,              // lineNo
    31,                // colNo
    "assertValidSize", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pName
};

static emlrtRTEInfo i_emlrtRTEI{
    58,                   // lineNo
    23,                   // colNo
    "assertValidSizeArg", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\assertValidSizeArg.m" // pName
};

static emlrtRTEInfo j_emlrtRTEI{
    64,                   // lineNo
    15,                   // colNo
    "assertValidSizeArg", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\assertValidSizeArg.m" // pName
};

static emlrtRTEInfo m_emlrtRTEI{
    44,                            // lineNo
    1,                             // colNo
    "parenReference2DNumericImpl", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenReference2D.m" // pName
};

static emlrtRTEInfo o_emlrtRTEI{
    59,             // lineNo
    27,             // colNo
    "sparse/binOp", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\binOp.m" // pName
};

static emlrtRTEInfo p_emlrtRTEI{
    505,                // lineNo
    9,                  // colNo
    "allocEqsizeBinop", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\binOp.m" // pName
};

static emlrtRTEInfo r_emlrtRTEI{
    42,                     // lineNo
    23,                     // colNo
    "sparse/parenAssign2D", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pName
};

static emlrtRTEInfo s_emlrtRTEI{
    237,            // lineNo
    13,             // colNo
    "sparse/numel", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pName
};

static emlrtRTEInfo fc_emlrtRTEI{
    250,      // lineNo
    17,       // colNo
    "sparse", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pName
};

static emlrtRTEInfo gc_emlrtRTEI{
    240,      // lineNo
    22,       // colNo
    "sparse", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pName
};

static emlrtRTEInfo hc_emlrtRTEI{
    1476,     // lineNo
    13,       // colNo
    "sparse", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pName
};

static emlrtRTEInfo ic_emlrtRTEI{
    1492,     // lineNo
    38,       // colNo
    "sparse", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pName
};

static emlrtRTEInfo jc_emlrtRTEI{
    1494,     // lineNo
    39,       // colNo
    "sparse", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pName
};

static emlrtRTEInfo kc_emlrtRTEI{
    1495,     // lineNo
    39,       // colNo
    "sparse", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\sparse.m" // pName
};

static emlrtRTEInfo lc_emlrtRTEI{
    406,             // lineNo
    1,               // colNo
    "parenAssign2D", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pName
};

static emlrtRTEInfo mc_emlrtRTEI{
    407,             // lineNo
    1,               // colNo
    "parenAssign2D", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pName
};

static emlrtRTEInfo nc_emlrtRTEI{
    414,             // lineNo
    1,               // colNo
    "parenAssign2D", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pName
};

static emlrtRTEInfo oc_emlrtRTEI{
    415,             // lineNo
    1,               // colNo
    "parenAssign2D", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pName
};

static emlrtRTEInfo pc_emlrtRTEI{
    98,              // lineNo
    6,               // colNo
    "parenAssign2D", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@"
    "sparse\\parenAssign2D.m" // pName
};

// Function Definitions
namespace coder {
void sparse::b_realloc(const emlrtStack &sp, b_sparse *b_this,
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
  rowidxt.set_size(&lc_emlrtRTEI, &sp, numAlloc);
  for (overflow = 0; overflow < numAlloc; overflow++) {
    rowidxt[overflow] = b_this->rowidx[overflow];
  }
  numAlloc = b_this->d.size(0);
  dt.set_size(&mc_emlrtRTEI, &sp, numAlloc);
  for (overflow = 0; overflow < numAlloc; overflow++) {
    dt[overflow] = b_this->d[overflow];
  }
  internal::bigProduct(b_this->m, overflow);
  if (overflow == 0) {
    st.site = &wb_emlrtRSI;
    internal::bigProduct(b_this->m, overflow);
    if (overflow != 0) {
      emlrtErrorWithMessageIdR2018a(&st, &s_emlrtRTEI,
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
  b_this->rowidx.set_size(&nc_emlrtRTEI, &sp, numAlloc);
  b_this->d.set_size(&oc_emlrtRTEI, &sp, numAlloc);
  for (overflow = 0; overflow < numAlloc; overflow++) {
    b_this->rowidx[overflow] = 0;
    b_this->d[overflow] = 0.0;
  }
  b_this->maxnz = numAlloc;
  st.site = &xb_emlrtRSI;
  if (ub1 > 2147483646) {
    b_st.site = &gb_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (numAlloc = 0; numAlloc < ub1; numAlloc++) {
    b_this->rowidx[numAlloc] = rowidxt[numAlloc];
    b_this->d[numAlloc] = dt[numAlloc];
  }
  st.site = &yb_emlrtRSI;
  if ((lb2 <= ub2) && (ub2 > 2147483646)) {
    b_st.site = &gb_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (numAlloc = lb2; numAlloc <= ub2; numAlloc++) {
    overflow = (numAlloc + offs) - 1;
    b_this->rowidx[overflow] = rowidxt[numAlloc - 1];
    b_this->d[overflow] = dt[numAlloc - 1];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

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
  rowidxt.set_size(&lc_emlrtRTEI, &sp, numAlloc);
  for (overflow = 0; overflow < numAlloc; overflow++) {
    rowidxt[overflow] = b_this->rowidx[overflow];
  }
  numAlloc = b_this->d.size(0);
  dt.set_size(&mc_emlrtRTEI, &sp, numAlloc);
  for (overflow = 0; overflow < numAlloc; overflow++) {
    dt[overflow] = b_this->d[overflow];
  }
  internal::bigProduct(b_this->m, b_this->n, overflow);
  if (overflow == 0) {
    st.site = &wb_emlrtRSI;
    internal::bigProduct(b_this->m, b_this->n, overflow);
    if (overflow != 0) {
      emlrtErrorWithMessageIdR2018a(&st, &s_emlrtRTEI,
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
  b_this->rowidx.set_size(&nc_emlrtRTEI, &sp, numAlloc);
  b_this->d.set_size(&oc_emlrtRTEI, &sp, numAlloc);
  for (overflow = 0; overflow < numAlloc; overflow++) {
    b_this->rowidx[overflow] = 0;
    b_this->d[overflow] = 0.0;
  }
  b_this->maxnz = numAlloc;
  st.site = &xb_emlrtRSI;
  if (ub1 > 2147483646) {
    b_st.site = &gb_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (numAlloc = 0; numAlloc < ub1; numAlloc++) {
    b_this->rowidx[numAlloc] = rowidxt[numAlloc];
    b_this->d[numAlloc] = dt[numAlloc];
  }
  st.site = &yb_emlrtRSI;
  if ((lb2 <= ub2) && (ub2 > 2147483646)) {
    b_st.site = &gb_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (numAlloc = lb2; numAlloc <= ub2; numAlloc++) {
    overflow = (numAlloc + offs) - 1;
    b_this->rowidx[overflow] = rowidxt[numAlloc - 1];
    b_this->d[overflow] = dt[numAlloc - 1];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

int32_T sparse::copyNonzeroValues(const emlrtStack &sp, b_sparse *b_this,
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
  st.site = &cc_emlrtRSI;
  if (b_this->m > 2147483646) {
    b_st.site = &gb_emlrtRSI;
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
  st.site = &vb_emlrtRSI;
  if (sm > 2147483646) {
    b_st.site = &gb_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (int32_T k{0}; k < sm; k++) {
    if (!(rhs[(rhsIter_idx + k) - 1] == 0.0)) {
      nz++;
    }
  }
  return nz;
}

void sparse::sparseSparseRowExpandBinOp(const emlrtStack &sp,
                                        const c_sparse &rowA, const c_sparse *b,
                                        c_sparse &s)
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
      st.site = &ad_emlrtRSI;
      if ((firstNonZeroRow_tmp <= lastNonZeroRow_tmp) &&
          (lastNonZeroRow_tmp > 2147483646)) {
        b_st.site = &gb_emlrtRSI;
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
        st.site = &bd_emlrtRSI;
        if ((lastNonZeroRow_tmp + 1 <= s.m) && (s.m > 2147483646)) {
          b_st.site = &gb_emlrtRSI;
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

void sparse::assertValidSize(const emlrtStack &sp, real_T s)
{
  emlrtStack st;
  real_T b_d;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &k_emlrtRSI;
  if ((s != muDoubleScalarFloor(s)) || muDoubleScalarIsInf(s) ||
      (s < -2.147483648E+9) || (s > 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(
        &st, &i_emlrtRTEI, "Coder:MATLAB:NonIntegerInput",
        "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
  }
  if (s <= 0.0) {
    b_d = 0.0;
  } else {
    b_d = s;
  }
  if (!(b_d <= 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(&st, &j_emlrtRTEI, "Coder:MATLAB:pmaxsize",
                                  "Coder:MATLAB:pmaxsize", 0);
  }
  if (s < 0.0) {
    emlrtErrorWithMessageIdR2018a(&sp, &g_emlrtRTEI,
                                  "Coder:toolbox:SparseNegativeSize",
                                  "Coder:toolbox:SparseNegativeSize", 0);
  }
  if (!(s < 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(
        &sp, &h_emlrtRTEI, "Coder:toolbox:SparseMaxSize",
        "Coder:toolbox:SparseMaxSize", 2, 12, MAX_int32_T);
  }
}

void b_sparse::b_parenAssign(const emlrtStack &sp, const array<real_T, 2U> &rhs)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  struct_T rhsIter;
  int32_T sm;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &mb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (m != rhs.size(0)) {
    emlrtErrorWithMessageIdR2018a(&st, &r_emlrtRTEI,
                                  "MATLAB:subsassigndimmismatch",
                                  "MATLAB:subsassigndimmismatch", 0);
  }
  b_st.site = &nb_emlrtRSI;
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
    c_st.site = &pb_emlrtRSI;
    nzRhs = sparse::countNumnzInColumn(c_st, rhs, rhsIter.idx, sm);
    if (nzColAlloc < nzRhs) {
      int32_T extraSpace;
      int32_T outIdx;
      extraSpace = nzRhs - nzColAlloc;
      nzRhs = colidx[colidx.size(0) - 1];
      nzColAlloc = (maxnz - nzRhs) + 1;
      if (nzColAlloc < extraSpace) {
        c_st.site = &qb_emlrtRSI;
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
      c_st.site = &sb_emlrtRSI;
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
      c_st.site = &tb_emlrtRSI;
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

void b_sparse::parenAssign(const emlrtStack &sp, const array<real_T, 2U> &rhs)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  struct_T rhsIter;
  int32_T sm;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &mb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (m != rhs.size(0)) {
    emlrtErrorWithMessageIdR2018a(&st, &r_emlrtRTEI,
                                  "MATLAB:subsassigndimmismatch",
                                  "MATLAB:subsassigndimmismatch", 0);
  }
  b_st.site = &nb_emlrtRSI;
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
    c_st.site = &pb_emlrtRSI;
    nzRhs = sparse::countNumnzInColumn(c_st, rhs, rhsIter.idx, sm);
    if (nzColAlloc < nzRhs) {
      int32_T extraSpace;
      int32_T outIdx;
      extraSpace = nzRhs - nzColAlloc;
      nzRhs = colidx[colidx.size(0) - 1];
      nzColAlloc = (maxnz - nzRhs) + 1;
      if (nzColAlloc < extraSpace) {
        c_st.site = &qb_emlrtRSI;
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
      c_st.site = &sb_emlrtRSI;
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
      c_st.site = &tb_emlrtRSI;
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

void sparse::parenAssign(const emlrtStack &sp, const c_sparse &rhs,
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
  st.site = &mb_emlrtRSI;
  if (varargin_1.size(0) != rhs.m) {
    emlrtErrorWithMessageIdR2018a(&st, &r_emlrtRTEI,
                                  "MATLAB:subsassigndimmismatch",
                                  "MATLAB:subsassigndimmismatch", 0);
  }
  b_st.site = &cd_emlrtRSI;
  c_st.site = &dd_emlrtRSI;
  sparse_validateNumericIndex(c_st, m, varargin_1);
  c_st.site = &ed_emlrtRSI;
  sparse_validateNumericIndex(c_st, n, varargin_2);
  sm_tmp = varargin_1.size(0);
  c_st.site = &fd_emlrtRSI;
  r.set_size(&pc_emlrtRTEI, &c_st, varargin_1.size(0));
  for (vectorUB = 0; vectorUB < sm_tmp; vectorUB++) {
    r[vectorUB] = varargin_1[vectorUB];
  }
  c[0] = varargin_2[0];
  c[1] = varargin_2[1];
  c[2] = varargin_2[2];
  d_st.site = &gd_emlrtRSI;
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
    d_st.site = &hd_emlrtRSI;
    if (overflow) {
      e_st.site = &gb_emlrtRSI;
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
            d_st.site = &id_emlrtRSI;
            if ((ridx + 2 <= sm_tmp) && (sm_tmp > 2147483646)) {
              e_st.site = &gb_emlrtRSI;
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
              d_st.site = &jd_emlrtRSI;
              sparse::b_realloc(d_st, this, colidx[colidx.size(0) - 1] + nrow,
                                b_vidx, b_vidx + 1,
                                colidx[colidx.size(0) - 1] - 1, pass + 1);
            } else {
              d_st.site = &kd_emlrtRSI;
              nrow = (b_vidx + pass) + 1;
              cnt = (colidx[colidx.size(0) - 1] - b_vidx) - 1;
              if (cnt > 0) {
                e_st.site = &ac_emlrtRSI;
                std::memmove((void *)&rowidx[nrow], (void *)&rowidx[b_vidx],
                             (uint32_T)((size_t)cnt * sizeof(int32_T)));
                e_st.site = &bc_emlrtRSI;
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
            d_st.site = &ld_emlrtRSI;
            sparse::b_realloc(d_st, this,
                              (colidx[colidx.size(0) - 1] + nrow) - 1, b_vidx,
                              b_vidx + 1, colidx[colidx.size(0) - 1] - 1, pass);
          } else {
            d_st.site = &md_emlrtRSI;
            nrow = b_vidx + pass;
            cnt = (colidx[colidx.size(0) - 1] - b_vidx) - 1;
            if (cnt > 0) {
              e_st.site = &ac_emlrtRSI;
              std::memmove((void *)&rowidx[nrow], (void *)&rowidx[b_vidx],
                           (uint32_T)((size_t)cnt * sizeof(int32_T)));
              e_st.site = &bc_emlrtRSI;
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
            d_st.site = &nd_emlrtRSI;
            cnt = n + 1;
            e_st.site = &ye_emlrtRSI;
            if ((static_cast<int32_T>(b_d) + 1 <= cnt) && (cnt > 2147483646)) {
              f_st.site = &gb_emlrtRSI;
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
            d_st.site = &od_emlrtRSI;
            nrow = shiftleft - extraAlloc;
            cnt = n + 1;
            e_st.site = &af_emlrtRSI;
            if ((static_cast<int32_T>(b_d) + 1 <= cnt) && (cnt > 2147483646)) {
              f_st.site = &gb_emlrtRSI;
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
            d_st.site = &pd_emlrtRSI;
            nrow = vidx + shiftleft;
            cnt = (colidx[colidx.size(0) - 1] - vidx) - 1;
            if (cnt > 0) {
              e_st.site = &ac_emlrtRSI;
              std::memmove((void *)&rowidx[vidx], (void *)&rowidx[nrow],
                           (uint32_T)((size_t)cnt * sizeof(int32_T)));
              e_st.site = &bc_emlrtRSI;
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
                            const real_T varargin_2[3], c_sparse &s) const
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
  st.site = &fc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &gc_emlrtRSI;
  c_st.site = &hc_emlrtRSI;
  sparse_validateNumericIndex(c_st, m, varargin_1);
  c_st.site = &ic_emlrtRSI;
  sparse_validateNumericIndex(c_st, n, varargin_2);
  sm_tmp = varargin_1.size(0);
  c_st.site = &jc_emlrtRSI;
  if (varargin_1.size(0) * 3 < 0) {
    emlrtErrorWithMessageIdR2018a(&c_st, &m_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  s.d.set_size(&fc_emlrtRTEI, &c_st, 0);
  s.rowidx.set_size(&fc_emlrtRTEI, &c_st, 0);
  s.colidx.set_size(&fc_emlrtRTEI, &c_st, 4);
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
    d_st.site = &kc_emlrtRSI;
    if (overflow) {
      e_st.site = &gb_emlrtRSI;
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
        s.d.set_size(&gc_emlrtRTEI, &c_st, s.d.size(0) + 1);
        b_d = d[idx - 1];
        s.d[i] = b_d;
        s.rowidx.set_size(&gc_emlrtRTEI, &c_st, i1);
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
    s.rowidx.set_size(&fc_emlrtRTEI, &c_st, 1);
    s.rowidx[0] = 1;
    s.d.set_size(&fc_emlrtRTEI, &c_st, 1);
    s.d[0] = 0.0;
  }
  s.m = varargin_1.size(0);
}

void b_sparse::parenReference(const emlrtStack &sp, c_sparse &s) const
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  int32_T nd;
  int32_T ub;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &fc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &lc_emlrtRSI;
  c_st.site = &mc_emlrtRSI;
  ub = m * 3;
  nd = ((((colidx[2] - colidx[1]) + colidx[4]) - colidx[3]) + colidx[6]) -
       colidx[5];
  if ((nd > ub) && (ub != 0)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &c_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  c_st.site = &nc_emlrtRSI;
  sparse::spallocLike(c_st, m, nd, s);
  if (nd != 0) {
    ub = 0;
    for (int32_T cidx{0}; cidx < 3; cidx++) {
      int32_T colNnz;
      int32_T i;
      nd = cidx << 1;
      i = colidx[nd + 1];
      colNnz = colidx[nd + 2] - i;
      c_st.site = &oc_emlrtRSI;
      if (colNnz > 2147483646) {
        d_st.site = &gb_emlrtRSI;
        check_forloop_overflow_error(d_st);
      }
      for (int32_T k{0}; k < colNnz; k++) {
        int32_T i1;
        nd = (i + k) - 1;
        i1 = ub + k;
        s.d[i1] = d[nd];
        s.rowidx[i1] = rowidx[nd];
      }
      if (colNnz - 1 >= 0) {
        ub += colNnz;
      }
      s.colidx[cidx + 1] = s.colidx[cidx] + colNnz;
    }
  }
}

void c_sparse::plus(const emlrtStack &sp, const c_sparse &b, c_sparse &s) const
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
  st.site = &uc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if ((m != 1) && (b.m != 1) && (m != b.m)) {
    emlrtErrorWithMessageIdR2018a(&st, &o_emlrtRTEI, "MATLAB:dimagree",
                                  "MATLAB:dimagree", 0);
  }
  y = muIntScalarMax_sint32(m, b.m);
  b_st.site = &vc_emlrtRSI;
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
    emlrtErrorWithMessageIdR2018a(&b_st, &p_emlrtRTEI,
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
  c_st.site = &yc_emlrtRSI;
  s.m = y;
  s.d.set_size(&ic_emlrtRTEI, &c_st, nza);
  s.rowidx.set_size(&jc_emlrtRTEI, &c_st, nza);
  s.colidx.set_size(&kc_emlrtRTEI, &c_st, 4);
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
    b_st.site = &wc_emlrtRSI;
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
        c_st.site = &ad_emlrtRSI;
        if ((tmp <= lastNonZeroRow_tmp) && (lastNonZeroRow_tmp > 2147483646)) {
          d_st.site = &gb_emlrtRSI;
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
          c_st.site = &bd_emlrtRSI;
          if ((lastNonZeroRow_tmp + 1 <= y) && (y > 2147483646)) {
            d_st.site = &gb_emlrtRSI;
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
    b_st.site = &xc_emlrtRSI;
    sparse::sparseSparseRowExpandBinOp(b_st, b, this, s);
  }
}

void sparse::spallocLike(const emlrtStack &sp, int32_T b_m, int32_T nzmax,
                         c_sparse &s)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T numalloc;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &pc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &sc_emlrtRSI;
  if (b_m < 0) {
    emlrtErrorWithMessageIdR2018a(&b_st, &g_emlrtRTEI,
                                  "Coder:toolbox:SparseNegativeSize",
                                  "Coder:toolbox:SparseNegativeSize", 0);
  }
  if (b_m >= MAX_int32_T) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &h_emlrtRTEI, "Coder:toolbox:SparseMaxSize",
        "Coder:toolbox:SparseMaxSize", 2, 12, MAX_int32_T);
  }
  s.m = b_m;
  b_st.site = &rc_emlrtRSI;
  if (nzmax < 0) {
    emlrtErrorWithMessageIdR2018a(&b_st, &g_emlrtRTEI,
                                  "Coder:toolbox:SparseNegativeSize",
                                  "Coder:toolbox:SparseNegativeSize", 0);
  }
  if (nzmax >= MAX_int32_T) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &h_emlrtRTEI, "Coder:toolbox:SparseMaxSize",
        "Coder:toolbox:SparseMaxSize", 2, 12, MAX_int32_T);
  }
  numalloc = muIntScalarMax_sint32(nzmax, 1);
  s.d.set_size(&hc_emlrtRTEI, &st, numalloc);
  for (int32_T i{0}; i < numalloc; i++) {
    s.d[i] = 0.0;
  }
  s.colidx.set_size(&hc_emlrtRTEI, &st, 4);
  s.rowidx.set_size(&hc_emlrtRTEI, &st, numalloc);
  for (int32_T i{0}; i < numalloc; i++) {
    s.rowidx[i] = 0;
  }
  s.colidx[0] = 1;
  s.colidx[1] = 1;
  s.colidx[2] = 1;
  s.colidx[3] = 1;
}

} // namespace coder

// End of code generation (sparse1.cpp)
