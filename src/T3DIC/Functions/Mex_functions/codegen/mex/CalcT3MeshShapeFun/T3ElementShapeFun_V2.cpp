//
// T3ElementShapeFun_V2.cpp
//
// Code generation for function 'T3ElementShapeFun_V2'
//

// Include files
#include "T3ElementShapeFun_V2.h"
#include "CalcT3MeshShapeFun_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "sparse1.h"
#include "warning.h"
#include "blas.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <cstddef>
#include <emmintrin.h>

// Variable Definitions
static emlrtRSInfo q_emlrtRSI{
    20,                     // lineNo
    "T3ElementShapeFun_V2", // fcnName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pathName
};

static emlrtRSInfo r_emlrtRSI{
    25,                     // lineNo
    "T3ElementShapeFun_V2", // fcnName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pathName
};

static emlrtRSInfo s_emlrtRSI{
    28,                     // lineNo
    "T3ElementShapeFun_V2", // fcnName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pathName
};

static emlrtRSInfo t_emlrtRSI{
    37,                     // lineNo
    "T3ElementShapeFun_V2", // fcnName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pathName
};

static emlrtRSInfo u_emlrtRSI{
    44,                     // lineNo
    "T3ElementShapeFun_V2", // fcnName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pathName
};

static emlrtRSInfo v_emlrtRSI{
    45,                     // lineNo
    "T3ElementShapeFun_V2", // fcnName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pathName
};

static emlrtRSInfo w_emlrtRSI{
    47,                     // lineNo
    "T3ElementShapeFun_V2", // fcnName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pathName
};

static emlrtRSInfo x_emlrtRSI{
    48,                     // lineNo
    "T3ElementShapeFun_V2", // fcnName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pathName
};

static emlrtRSInfo y_emlrtRSI{
    20,                // lineNo
    "mrdivide_helper", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\mrdivide_"
    "helper.m" // pathName
};

static emlrtRSInfo ab_emlrtRSI{
    42,      // lineNo
    "mrdiv", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\mrdivide_"
    "helper.m" // pathName
};

static emlrtRSInfo bb_emlrtRSI{
    61,        // lineNo
    "lusolve", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" // pathName
};

static emlrtRSInfo cb_emlrtRSI{
    293,          // lineNo
    "lusolve3x3", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" // pathName
};

static emlrtRSInfo db_emlrtRSI{
    90,              // lineNo
    "warn_singular", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\lusolve.m" // pathName
};

static emlrtRSInfo
    eb_emlrtRSI{
        94,                  // lineNo
        "eml_mtimes_helper", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" // pathName
    };

static emlrtRSInfo fb_emlrtRSI{
    142,      // lineNo
    "mtimes", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "blas\\mtimes.m" // pathName
};

static emlrtRSInfo hb_emlrtRSI{
    178,           // lineNo
    "mtimes_blas", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "blas\\mtimes.m" // pathName
};

static emlrtRSInfo ib_emlrtRSI{
    15,    // lineNo
    "sum", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" // pathName
};

static emlrtRSInfo jb_emlrtRSI{
    99,        // lineNo
    "sumprod", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumpro"
    "d.m" // pathName
};

static emlrtRSInfo kb_emlrtRSI{
    149,                     // lineNo
    "combineVectorElements", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combin"
    "eVectorElements.m" // pathName
};

static emlrtRSInfo lb_emlrtRSI{
    209,                // lineNo
    "colMajorFlatIter", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combin"
    "eVectorElements.m" // pathName
};

static emlrtECInfo f_emlrtECI{
    -1,                     // nDims
    33,                     // lineNo
    1,                      // colNo
    "T3ElementShapeFun_V2", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pName
};

static emlrtECInfo g_emlrtECI{
    -1,                     // nDims
    34,                     // lineNo
    1,                      // colNo
    "T3ElementShapeFun_V2", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pName
};

static emlrtECInfo h_emlrtECI{
    -1,                     // nDims
    35,                     // lineNo
    1,                      // colNo
    "T3ElementShapeFun_V2", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pName
};

static emlrtECInfo i_emlrtECI{
    1,                      // nDims
    36,                     // lineNo
    8,                      // colNo
    "T3ElementShapeFun_V2", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pName
};

static emlrtECInfo j_emlrtECI{
    -1,                     // nDims
    40,                     // lineNo
    1,                      // colNo
    "T3ElementShapeFun_V2", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pName
};

static emlrtECInfo k_emlrtECI{
    -1,                     // nDims
    41,                     // lineNo
    1,                      // colNo
    "T3ElementShapeFun_V2", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pName
};

static emlrtBCInfo i_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    40,                     // lineNo
    14,                     // colNo
    "X",                    // aName
    "T3ElementShapeFun_V2", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m", // pName
    0           // checkKind
};

static emlrtBCInfo j_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    41,                     // lineNo
    14,                     // colNo
    "Y",                    // aName
    "T3ElementShapeFun_V2", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m", // pName
    0           // checkKind
};

static emlrtBCInfo k_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    47,                     // lineNo
    23,                     // colNo
    "N",                    // aName
    "T3ElementShapeFun_V2", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m", // pName
    0           // checkKind
};

static emlrtBCInfo l_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    48,                     // lineNo
    23,                     // colNo
    "N",                    // aName
    "T3ElementShapeFun_V2", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m", // pName
    0           // checkKind
};

static emlrtRTEInfo jb_emlrtRTEI{
    4,                      // lineNo
    1,                      // colNo
    "T3ElementShapeFun_V2", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pName
};

static emlrtRTEInfo kb_emlrtRTEI{
    25,                     // lineNo
    1,                      // colNo
    "T3ElementShapeFun_V2", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pName
};

static emlrtRTEInfo lb_emlrtRTEI{
    218,      // lineNo
    20,       // colNo
    "mtimes", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "blas\\mtimes.m" // pName
};

static emlrtRTEInfo
    mb_emlrtRTEI{
        94,                  // lineNo
        5,                   // colNo
        "eml_mtimes_helper", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" // pName
    };

static emlrtRTEInfo nb_emlrtRTEI{
    28,                     // lineNo
    16,                     // colNo
    "T3ElementShapeFun_V2", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pName
};

static emlrtRTEInfo ob_emlrtRTEI{
    28,                     // lineNo
    1,                      // colNo
    "T3ElementShapeFun_V2", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pName
};

static emlrtRTEInfo pb_emlrtRTEI{
    29,                     // lineNo
    1,                      // colNo
    "T3ElementShapeFun_V2", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pName
};

static emlrtRTEInfo qb_emlrtRTEI{
    30,                     // lineNo
    1,                      // colNo
    "T3ElementShapeFun_V2", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pName
};

static emlrtRTEInfo rb_emlrtRTEI{
    33,                     // lineNo
    10,                     // colNo
    "T3ElementShapeFun_V2", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pName
};

static emlrtRTEInfo sb_emlrtRTEI{
    36,                     // lineNo
    9,                      // colNo
    "T3ElementShapeFun_V2", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pName
};

static emlrtRTEInfo tb_emlrtRTEI{
    36,                     // lineNo
    23,                     // colNo
    "T3ElementShapeFun_V2", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pName
};

static emlrtRTEInfo ub_emlrtRTEI{
    36,                     // lineNo
    39,                     // colNo
    "T3ElementShapeFun_V2", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pName
};

static emlrtRTEInfo vb_emlrtRTEI{
    36,                     // lineNo
    53,                     // colNo
    "T3ElementShapeFun_V2", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pName
};

static emlrtRTEInfo wb_emlrtRTEI{
    36,                     // lineNo
    69,                     // colNo
    "T3ElementShapeFun_V2", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pName
};

static emlrtRTEInfo xb_emlrtRTEI{
    36,                     // lineNo
    83,                     // colNo
    "T3ElementShapeFun_V2", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pName
};

static emlrtRTEInfo yb_emlrtRTEI{
    39,                     // lineNo
    1,                      // colNo
    "T3ElementShapeFun_V2", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pName
};

static emlrtRTEInfo ac_emlrtRTEI{
    1,                      // lineNo
    31,                     // colNo
    "T3ElementShapeFun_V2", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pName
};

static emlrtRTEInfo bc_emlrtRTEI{
    44,                     // lineNo
    1,                      // colNo
    "T3ElementShapeFun_V2", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pName
};

static emlrtRTEInfo cc_emlrtRTEI{
    45,                     // lineNo
    1,                      // colNo
    "T3ElementShapeFun_V2", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pName
};

static emlrtRTEInfo dc_emlrtRTEI{
    47,                     // lineNo
    21,                     // colNo
    "T3ElementShapeFun_V2", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pName
};

static emlrtRTEInfo ec_emlrtRTEI{
    48,                     // lineNo
    21,                     // colNo
    "T3ElementShapeFun_V2", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pName
};

static emlrtRTEInfo yc_emlrtRTEI{
    36,                     // lineNo
    8,                      // colNo
    "T3ElementShapeFun_V2", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pName
};

static emlrtRSInfo if_emlrtRSI{
    36,                     // lineNo
    "T3ElementShapeFun_V2", // fcnName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pathName
};

static emlrtRSInfo jf_emlrtRSI{
    33,                     // lineNo
    "T3ElementShapeFun_V2", // fcnName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\T3ElementSha"
    "pe"
    "Fun_V2.m" // pathName
};

// Function Declarations
static void binary_expand_op(const emlrtStack &sp,
                             coder::array<real_T, 1U> &in1,
                             const coder::array<real_T, 1U> &in2,
                             const coder::array<real_T, 1U> &in3);

static void c_and(const emlrtStack &sp, coder::array<boolean_T, 1U> &in1,
                  const coder::array<boolean_T, 1U> &in2);

// Function Definitions
static void binary_expand_op(const emlrtStack &sp,
                             coder::array<real_T, 1U> &in1,
                             const coder::array<real_T, 1U> &in2,
                             const coder::array<real_T, 1U> &in3)
{
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  in1.set_size(&rb_emlrtRTEI, &sp, loop_ub);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  for (int32_T i{0}; i < loop_ub; i++) {
    in1[i] = (1.0 - in2[i * stride_0_0]) - in3[i * stride_1_0];
  }
}

static void c_and(const emlrtStack &sp, coder::array<boolean_T, 1U> &in1,
                  const coder::array<boolean_T, 1U> &in2)
{
  coder::array<boolean_T, 1U> b_in1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  if (in2.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in2.size(0);
  }
  b_in1.set_size(&yc_emlrtRTEI, &sp, loop_ub);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  for (int32_T i{0}; i < loop_ub; i++) {
    b_in1[i] = (in1[i * stride_0_0] && in2[i * stride_1_0]);
  }
  in1.set_size(&yc_emlrtRTEI, &sp, loop_ub);
  for (int32_T i{0}; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

void T3ElementShapeFun_V2(const emlrtStack &sp, const real_T coor[6],
                          const coder::array<real_T, 1U> &X,
                          const coder::array<real_T, 1U> &Y,
                          coder::b_sparse &psi_x, coder::b_sparse &psi_y,
                          coder::array<real_T, 2U> &vec)
{
  __m128d b_r1;
  __m128d r;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  coder::array<real_T, 2U> N;
  coder::array<real_T, 2U> P_global;
  coder::array<real_T, 2U> P_normalized;
  coder::array<real_T, 2U> b_N;
  coder::array<real_T, 2U> b_P_normalized;
  coder::array<real_T, 1U> b_r2;
  coder::array<real_T, 1U> eta;
  coder::array<real_T, 1U> xi;
  coder::array<int32_T, 1U> r6;
  coder::array<boolean_T, 1U> Mask;
  coder::array<boolean_T, 1U> b_r3;
  coder::array<boolean_T, 1U> r4;
  coder::array<boolean_T, 1U> r5;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  real_T A[9];
  real_T Transform[9];
  real_T T[4];
  real_T b[2];
  real_T Transform_tmp;
  real_T a21;
  real_T b_Transform_tmp;
  real_T c_Transform_tmp;
  real_T d_Transform_tmp;
  real_T maxval;
  int32_T e_Transform_tmp;
  int32_T loop_ub;
  int32_T nz;
  int32_T r1;
  int32_T r2;
  int32_T r3;
  int32_T rtemp;
  char_T TRANSA1;
  char_T TRANSB1;
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
  loop_ub = X.size(0);
  N.set_size(&jb_emlrtRTEI, &sp, X.size(0), 3);
  nz = X.size(0) * 3;
  for (r1 = 0; r1 < nz; r1++) {
    N[r1] = 0.0;
  }
  //  vec = zeros()
  //  keyboard
  //  Vertex A in pixels
  //  Vertex B in pixels
  //  Vertex C in pixels
  //  2P3(1,1) matrix, each column is a vertex
  //  Unit triangle vertices
  //  Unit triangle x-coordinates
  //  Unit triangle y-coordinates
  //  Construct the system for T and b
  A[0] = coor[0];
  A[3] = coor[1];
  A[6] = coor[2];
  A[1] = coor[3];
  A[4] = coor[4];
  A[7] = coor[5];
  A[2] = 1.0;
  A[5] = 1.0;
  A[8] = 1.0;
  st.site = &q_emlrtRSI;
  b_st.site = &y_emlrtRSI;
  c_st.site = &ab_emlrtRSI;
  d_st.site = &bb_emlrtRSI;
  r1 = 0;
  r2 = 1;
  r3 = 2;
  maxval = muDoubleScalarAbs(coor[0]);
  a21 = muDoubleScalarAbs(coor[3]);
  if (a21 > maxval) {
    maxval = a21;
    r1 = 1;
    r2 = 0;
  }
  if (maxval < 1.0) {
    r1 = 2;
    r2 = 1;
    r3 = 0;
  }
  A[r2] /= A[r1];
  A[r3] /= A[r1];
  A[r2 + 3] -= A[r2] * A[r1 + 3];
  A[r3 + 3] -= A[r3] * A[r1 + 3];
  A[r2 + 6] -= A[r2] * A[r1 + 6];
  A[r3 + 6] -= A[r3] * A[r1 + 6];
  if (muDoubleScalarAbs(A[r3 + 3]) > muDoubleScalarAbs(A[r2 + 3])) {
    rtemp = r2;
    r2 = r3;
    r3 = rtemp;
  }
  A[r3 + 3] /= A[r2 + 3];
  A[r3 + 6] -= A[r3 + 3] * A[r2 + 6];
  if ((A[r1] == 0.0) || (A[r2 + 3] == 0.0) || (A[r3 + 6] == 0.0)) {
    e_st.site = &cb_emlrtRSI;
    f_st.site = &db_emlrtRSI;
    coder::internal::warning(f_st);
  }
  Transform[3 * r1] = 0.0 / A[r1];
  maxval = A[r1 + 3];
  Transform[3 * r2] = 1.0 - Transform[3 * r1] * maxval;
  a21 = A[r1 + 6];
  Transform[3 * r3] = 0.0 - Transform[3 * r1] * a21;
  Transform_tmp = A[r2 + 3];
  Transform[3 * r2] /= Transform_tmp;
  b_Transform_tmp = A[r2 + 6];
  Transform[3 * r3] -= Transform[3 * r2] * b_Transform_tmp;
  c_Transform_tmp = A[r3 + 6];
  Transform[3 * r3] /= c_Transform_tmp;
  d_Transform_tmp = A[r3 + 3];
  Transform[3 * r2] -= Transform[3 * r3] * d_Transform_tmp;
  Transform[3 * r1] -= Transform[3 * r3] * A[r3];
  Transform[3 * r1] -= Transform[3 * r2] * A[r2];
  rtemp = 3 * r1 + 1;
  Transform[rtemp] = 0.0 / A[r1];
  e_Transform_tmp = 3 * r2 + 1;
  Transform[e_Transform_tmp] = 0.0 - Transform[rtemp] * maxval;
  nz = 3 * r3 + 1;
  Transform[nz] = 1.0 - Transform[rtemp] * a21;
  Transform[e_Transform_tmp] /= Transform_tmp;
  Transform[nz] -= Transform[e_Transform_tmp] * b_Transform_tmp;
  Transform[nz] /= c_Transform_tmp;
  Transform[e_Transform_tmp] -= Transform[nz] * d_Transform_tmp;
  Transform[rtemp] -= Transform[nz] * A[r3];
  Transform[rtemp] -= Transform[e_Transform_tmp] * A[r2];
  rtemp = 3 * r1 + 2;
  Transform[rtemp] = 1.0 / A[r1];
  e_Transform_tmp = 3 * r2 + 2;
  Transform[e_Transform_tmp] = 1.0 - Transform[rtemp] * maxval;
  nz = 3 * r3 + 2;
  Transform[nz] = 1.0 - Transform[rtemp] * a21;
  Transform[e_Transform_tmp] /= Transform_tmp;
  Transform[nz] -= Transform[e_Transform_tmp] * b_Transform_tmp;
  Transform[nz] /= c_Transform_tmp;
  Transform[e_Transform_tmp] -= Transform[nz] * d_Transform_tmp;
  Transform[rtemp] -= Transform[nz] * A[r3];
  Transform[rtemp] -= Transform[e_Transform_tmp] * A[r2];
  //  Transformation matrix
  T[0] = Transform[0];
  T[1] = Transform[1];
  b[0] = Transform[6];
  T[2] = Transform[3];
  T[3] = Transform[4];
  b[1] = Transform[7];
  //  Translation vector
  //  Define a global point
  st.site = &r_emlrtRSI;
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  if (X.size(0) != Y.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &d_emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  nz = Y.size(0);
  P_global.set_size(&kb_emlrtRTEI, &b_st, Y.size(0), 2);
  for (r1 = 0; r1 < nz; r1++) {
    P_global[r1] = Y[r1];
  }
  for (r1 = 0; r1 < loop_ub; r1++) {
    P_global[r1 + P_global.size(0)] = X[r1];
  }
  //  Map to normalized coordinates
  st.site = &s_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  if (P_global.size(0) == 0) {
    P_normalized.set_size(&mb_emlrtRTEI, &b_st, 2, 0);
  } else {
    c_st.site = &fb_emlrtRSI;
    d_st.site = &hb_emlrtRSI;
    TRANSB1 = 'T';
    TRANSA1 = 'N';
    maxval = 1.0;
    a21 = 0.0;
    m_t = (ptrdiff_t)2;
    n_t = (ptrdiff_t)P_global.size(0);
    k_t = (ptrdiff_t)2;
    lda_t = (ptrdiff_t)2;
    ldb_t = (ptrdiff_t)P_global.size(0);
    ldc_t = (ptrdiff_t)2;
    P_normalized.set_size(&lb_emlrtRTEI, &d_st, 2, Y.size(0));
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &maxval, &T[0], &lda_t,
          &(P_global.data())[0], &ldb_t, &a21, &(P_normalized.data())[0],
          &ldc_t);
  }
  nz = P_normalized.size(1);
  b_P_normalized.set_size(&nb_emlrtRTEI, &sp, 2, P_normalized.size(1));
  for (r1 = 0; r1 < nz; r1++) {
    r = _mm_loadu_pd(&P_normalized[2 * r1]);
    b_r1 = _mm_loadu_pd(&b[0]);
    _mm_storeu_pd(&b_P_normalized[2 * r1], _mm_add_pd(r, b_r1));
  }
  nz = b_P_normalized.size(1);
  P_normalized.set_size(&ob_emlrtRTEI, &sp, 2, b_P_normalized.size(1));
  rtemp = b_P_normalized.size(1) << 1;
  for (r1 = 0; r1 < rtemp; r1++) {
    P_normalized[r1] = b_P_normalized[r1];
  }
  xi.set_size(&pb_emlrtRTEI, &sp, b_P_normalized.size(1));
  eta.set_size(&qb_emlrtRTEI, &sp, b_P_normalized.size(1));
  for (r1 = 0; r1 < nz; r1++) {
    xi[r1] = P_normalized[2 * r1];
    eta[r1] = P_normalized[2 * r1 + 1];
  }
  //  keyboard
  //  Shape functions in normalized space
  if (xi.size(0) == eta.size(0)) {
    b_r2.set_size(&rb_emlrtRTEI, &sp, b_P_normalized.size(1));
    rtemp = (xi.size(0) / 2) << 1;
    e_Transform_tmp = rtemp - 2;
    for (r1 = 0; r1 <= e_Transform_tmp; r1 += 2) {
      r = _mm_loadu_pd(&xi[r1]);
      b_r1 = _mm_loadu_pd(&eta[r1]);
      _mm_storeu_pd(&b_r2[r1],
                    _mm_sub_pd(_mm_sub_pd(_mm_set1_pd(1.0), r), b_r1));
    }
    for (r1 = rtemp; r1 < nz; r1++) {
      b_r2[r1] = (1.0 - xi[r1]) - eta[r1];
    }
  } else {
    st.site = &jf_emlrtRSI;
    binary_expand_op(st, b_r2, xi, eta);
  }
  emlrtSubAssignSizeCheckR2012b(((coder::array<real_T, 1U> *)&X)->size(), 1,
                                b_r2.size(), 1, &f_emlrtECI, (emlrtCTX)&sp);
  for (r1 = 0; r1 < loop_ub; r1++) {
    N[r1] = b_r2[r1];
  }
  emlrtSubAssignSizeCheckR2012b(((coder::array<real_T, 1U> *)&X)->size(), 1,
                                xi.size(), 1, &g_emlrtECI, (emlrtCTX)&sp);
  for (r1 = 0; r1 < loop_ub; r1++) {
    N[r1 + N.size(0)] = xi[r1];
  }
  emlrtSubAssignSizeCheckR2012b(((coder::array<real_T, 1U> *)&X)->size(), 1,
                                eta.size(), 1, &h_emlrtECI, (emlrtCTX)&sp);
  for (r1 = 0; r1 < loop_ub; r1++) {
    N[r1 + N.size(0) * 2] = eta[r1];
  }
  Mask.set_size(&sb_emlrtRTEI, &sp, X.size(0));
  b_r3.set_size(&tb_emlrtRTEI, &sp, X.size(0));
  for (r1 = 0; r1 < loop_ub; r1++) {
    maxval = N[r1];
    Mask[r1] = (maxval >= 0.0);
    b_r3[r1] = (maxval <= 1.0);
  }
  r4.set_size(&ub_emlrtRTEI, &sp, X.size(0));
  r5.set_size(&vb_emlrtRTEI, &sp, X.size(0));
  for (r1 = 0; r1 < loop_ub; r1++) {
    maxval = N[r1 + N.size(0)];
    r4[r1] = (maxval >= 0.0);
    r5[r1] = (maxval <= 1.0);
  }
  for (r1 = 0; r1 < loop_ub; r1++) {
    Mask[r1] = (Mask[r1] && b_r3[r1]);
    r4[r1] = (r4[r1] && r5[r1]);
  }
  b_r3.set_size(&wb_emlrtRTEI, &sp, X.size(0));
  r5.set_size(&xb_emlrtRTEI, &sp, X.size(0));
  for (r1 = 0; r1 < loop_ub; r1++) {
    maxval = N[r1 + N.size(0) * 2];
    b_r3[r1] = (maxval >= 0.0);
    r5[r1] = (maxval <= 1.0);
  }
  if (Mask.size(0) == r4.size(0)) {
    for (r1 = 0; r1 < loop_ub; r1++) {
      Mask[r1] = (Mask[r1] && r4[r1]);
    }
  } else {
    st.site = &if_emlrtRSI;
    c_and(st, Mask, r4);
  }
  for (r1 = 0; r1 < loop_ub; r1++) {
    b_r3[r1] = (b_r3[r1] && r5[r1]);
  }
  loop_ub = Mask.size(0);
  if ((Mask.size(0) != X.size(0)) &&
      ((Mask.size(0) != 1) && (X.size(0) != 1))) {
    emlrtDimSizeImpxCheckR2021b(Mask.size(0), X.size(0), &i_emlrtECI,
                                (emlrtConstCTX)&sp);
  }
  if (Mask.size(0) == b_r3.size(0)) {
    for (r1 = 0; r1 < loop_ub; r1++) {
      Mask[r1] = (Mask[r1] && b_r3[r1]);
    }
  } else {
    st.site = &if_emlrtRSI;
    c_and(st, Mask, b_r3);
  }
  st.site = &t_emlrtRSI;
  b_st.site = &ib_emlrtRSI;
  c_st.site = &jb_emlrtRSI;
  rtemp = Mask.size(0);
  if (Mask.size(0) == 0) {
    nz = 0;
  } else {
    d_st.site = &kb_emlrtRSI;
    nz = Mask[0];
    e_st.site = &lb_emlrtRSI;
    if (Mask.size(0) > 2147483646) {
      f_st.site = &gb_emlrtRSI;
      coder::check_forloop_overflow_error(f_st);
    }
    for (e_Transform_tmp = 2; e_Transform_tmp <= rtemp; e_Transform_tmp++) {
      nz += Mask[e_Transform_tmp - 1];
    }
  }
  //  keyboard
  vec.set_size(&yb_emlrtRTEI, &sp, nz, 2);
  loop_ub = nz << 1;
  for (r1 = 0; r1 < loop_ub; r1++) {
    vec[r1] = 0.0;
  }
  e_Transform_tmp = Mask.size(0) - 1;
  rtemp = 0;
  for (r1 = 0; r1 <= e_Transform_tmp; r1++) {
    if (Mask[r1]) {
      rtemp++;
    }
  }
  r6.set_size(&ac_emlrtRTEI, &sp, rtemp);
  rtemp = 0;
  for (r1 = 0; r1 <= e_Transform_tmp; r1++) {
    if (Mask[r1]) {
      r6[rtemp] = r1;
      rtemp++;
    }
  }
  e_Transform_tmp = r6.size(0);
  for (r1 = 0; r1 < e_Transform_tmp; r1++) {
    if (r6[r1] > X.size(0) - 1) {
      emlrtDynamicBoundsCheckR2012b(r6[r1], 0, X.size(0) - 1, &i_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
  }
  emlrtSubAssignSizeCheckR2012b(&nz, 1, r6.size(), 1, &j_emlrtECI,
                                (emlrtCTX)&sp);
  for (r1 = 0; r1 < nz; r1++) {
    vec[r1] = X[r6[r1]];
  }
  for (r1 = 0; r1 < e_Transform_tmp; r1++) {
    if (r6[r1] > Y.size(0) - 1) {
      emlrtDynamicBoundsCheckR2012b(r6[r1], 0, Y.size(0) - 1, &j_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
  }
  rtemp = vec.size(0);
  emlrtSubAssignSizeCheckR2012b(vec.size(), 1, r6.size(), 1, &k_emlrtECI,
                                (emlrtCTX)&sp);
  for (r1 = 0; r1 < rtemp; r1++) {
    vec[r1 + vec.size(0)] = Y[r6[r1]];
  }
  //  keyboard
  st.site = &u_emlrtRSI;
  b_st.site = &h_emlrtRSI;
  c_st.site = &i_emlrtRSI;
  coder::sparse::assertValidSize(c_st, static_cast<real_T>(nz));
  psi_x.m = nz;
  psi_x.d.set_size(&bc_emlrtRTEI, &b_st, 1);
  psi_x.d[0] = 0.0;
  psi_x.colidx.set_size(&bc_emlrtRTEI, &b_st, 7);
  for (r1 = 0; r1 < 7; r1++) {
    psi_x.colidx[r1] = 1;
  }
  psi_x.rowidx.set_size(&bc_emlrtRTEI, &b_st, 1);
  psi_x.rowidx[0] = 1;
  psi_x.maxnz = 1;
  st.site = &v_emlrtRSI;
  b_st.site = &h_emlrtRSI;
  c_st.site = &i_emlrtRSI;
  coder::sparse::assertValidSize(c_st, static_cast<real_T>(nz));
  psi_y.m = nz;
  psi_y.d.set_size(&cc_emlrtRTEI, &b_st, 1);
  psi_y.d[0] = 0.0;
  psi_y.colidx.set_size(&cc_emlrtRTEI, &b_st, 7);
  for (r1 = 0; r1 < 7; r1++) {
    psi_y.colidx[r1] = 1;
  }
  psi_y.rowidx.set_size(&cc_emlrtRTEI, &b_st, 1);
  psi_y.rowidx[0] = 1;
  psi_y.maxnz = 1;
  b_N.set_size(&dc_emlrtRTEI, &sp, r6.size(0), 3);
  for (r1 = 0; r1 < 3; r1++) {
    for (rtemp = 0; rtemp < e_Transform_tmp; rtemp++) {
      if (r6[rtemp] > N.size(0) - 1) {
        emlrtDynamicBoundsCheckR2012b(r6[rtemp], 0, N.size(0) - 1, &k_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      b_N[rtemp + b_N.size(0) * r1] = N[r6[rtemp] + N.size(0) * r1];
    }
  }
  st.site = &w_emlrtRSI;
  psi_x.parenAssign(st, b_N);
  b_N.set_size(&ec_emlrtRTEI, &sp, r6.size(0), 3);
  for (r1 = 0; r1 < 3; r1++) {
    for (rtemp = 0; rtemp < e_Transform_tmp; rtemp++) {
      if (r6[rtemp] > N.size(0) - 1) {
        emlrtDynamicBoundsCheckR2012b(r6[rtemp], 0, N.size(0) - 1, &l_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      b_N[rtemp + b_N.size(0) * r1] = N[r6[rtemp] + N.size(0) * r1];
    }
  }
  st.site = &x_emlrtRSI;
  psi_y.b_parenAssign(st, b_N);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

// End of code generation (T3ElementShapeFun_V2.cpp)
