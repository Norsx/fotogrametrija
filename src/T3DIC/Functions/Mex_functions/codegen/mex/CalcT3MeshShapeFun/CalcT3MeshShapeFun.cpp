//
// CalcT3MeshShapeFun.cpp
//
// Code generation for function 'CalcT3MeshShapeFun'
//

// Include files
#include "CalcT3MeshShapeFun.h"
#include "CalcT3MeshShapeFun_data.h"
#include "CalcT3MeshShapeFun_mexutil.h"
#include "T3ElementShapeFun_V2.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "rt_nonfinite.h"
#include "sparse.h"
#include "sparse1.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <emmintrin.h>

// Variable Definitions
static emlrtRTEInfo emlrtRTEI{
    9,                    // lineNo
    1,                    // colNo
    "CalcT3MeshShapeFun", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m" // pName
};

static emlrtRTEInfo b_emlrtRTEI{
    33,                   // lineNo
    9,                    // colNo
    "CalcT3MeshShapeFun", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m" // pName
};

static emlrtRSInfo emlrtRSI{
    5,                    // lineNo
    "CalcT3MeshShapeFun", // fcnName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m" // pathName
};

static emlrtRSInfo b_emlrtRSI{
    6,                    // lineNo
    "CalcT3MeshShapeFun", // fcnName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m" // pathName
};

static emlrtRSInfo c_emlrtRSI{
    8,                    // lineNo
    "CalcT3MeshShapeFun", // fcnName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m" // pathName
};

static emlrtRSInfo d_emlrtRSI{
    9,                    // lineNo
    "CalcT3MeshShapeFun", // fcnName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m" // pathName
};

static emlrtRSInfo e_emlrtRSI{
    24,                   // lineNo
    "CalcT3MeshShapeFun", // fcnName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m" // pathName
};

static emlrtRSInfo f_emlrtRSI{
    30,                   // lineNo
    "CalcT3MeshShapeFun", // fcnName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m" // pathName
};

static emlrtRSInfo g_emlrtRSI{
    33,                   // lineNo
    "CalcT3MeshShapeFun", // fcnName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m" // pathName
};

static emlrtRSInfo n_emlrtRSI{
    35,        // lineNo
    "fprintf", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m" // pathName
};

static emlrtRSInfo dc_emlrtRSI{
    5,                      // lineNo
    "CalcGlobalT3ShapeFun", // fcnName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcGlobalT3"
    "Sh"
    "apeFun.m" // pathName
};

static emlrtRSInfo ec_emlrtRSI{
    6,                      // lineNo
    "CalcGlobalT3ShapeFun", // fcnName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcGlobalT3"
    "Sh"
    "apeFun.m" // pathName
};

static emlrtRSInfo bf_emlrtRSI{
    29,        // lineNo
    "sprintf", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\strfun\\sprintf.m" // pathName
};

static emlrtMCInfo emlrtMCI{
    66,        // lineNo
    18,        // colNo
    "fprintf", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m" // pName
};

static emlrtMCInfo d_emlrtMCI{
    53,              // lineNo
    14,              // colNo
    "nonConstPrint", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\strfun\\sprintf.m" // pName
};

static emlrtMCInfo e_emlrtMCI{
    55,              // lineNo
    15,              // colNo
    "nonConstPrint", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\strfun\\sprintf.m" // pName
};

static emlrtDCInfo emlrtDCI{
    57,              // lineNo
    53,              // colNo
    "nonConstPrint", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\strfun\\sprintf.m", // pName
    4 // checkKind
};

static emlrtECInfo emlrtECI{
    -1,                   // nDims
    27,                   // lineNo
    17,                   // colNo
    "CalcT3MeshShapeFun", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m" // pName
};

static emlrtECInfo b_emlrtECI{
    2,                    // nDims
    22,                   // lineNo
    12,                   // colNo
    "CalcT3MeshShapeFun", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m" // pName
};

static emlrtECInfo c_emlrtECI{
    1,                    // nDims
    22,                   // lineNo
    12,                   // colNo
    "CalcT3MeshShapeFun", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m" // pName
};

static emlrtECInfo d_emlrtECI{
    2,                    // nDims
    22,                   // lineNo
    41,                   // colNo
    "CalcT3MeshShapeFun", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m" // pName
};

static emlrtECInfo e_emlrtECI{
    2,                    // nDims
    22,                   // lineNo
    13,                   // colNo
    "CalcT3MeshShapeFun", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m" // pName
};

static emlrtBCInfo emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    13,                   // lineNo
    17,                   // colNo
    "conn",               // aName
    "CalcT3MeshShapeFun", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m", // pName
    0         // checkKind
};

static emlrtRTEInfo e_emlrtRTEI{
    11,                   // lineNo
    10,                   // colNo
    "CalcT3MeshShapeFun", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m" // pName
};

static emlrtBCInfo b_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    24,                   // lineNo
    55,                   // colNo
    "X",                  // aName
    "CalcT3MeshShapeFun", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m", // pName
    0         // checkKind
};

static emlrtBCInfo c_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    24,                   // lineNo
    63,                   // colNo
    "Y",                  // aName
    "CalcT3MeshShapeFun", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m", // pName
    0         // checkKind
};

static emlrtBCInfo d_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    6,                      // lineNo
    15,                     // colNo
    "col",                  // aName
    "CalcGlobalT3ShapeFun", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcGlobalT3"
    "Sh"
    "apeFun.m", // pName
    0           // checkKind
};

static emlrtBCInfo e_emlrtBCI{
    -1,                     // iFirst
    -1,                     // iLast
    6,                      // lineNo
    41,                     // colNo
    "col",                  // aName
    "CalcGlobalT3ShapeFun", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcGlobalT3"
    "Sh"
    "apeFun.m", // pName
    0           // checkKind
};

static emlrtBCInfo f_emlrtBCI{
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

static emlrtBCInfo g_emlrtBCI{
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

static emlrtBCInfo h_emlrtBCI{
    -1,                   // iFirst
    -1,                   // iLast
    15,                   // lineNo
    18,                   // colNo
    "coor",               // aName
    "CalcT3MeshShapeFun", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m", // pName
    0         // checkKind
};

static emlrtDCInfo b_emlrtDCI{
    15,                   // lineNo
    18,                   // colNo
    "CalcT3MeshShapeFun", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m", // pName
    1         // checkKind
};

static emlrtRTEInfo t_emlrtRTEI{
    8,                    // lineNo
    9,                    // colNo
    "CalcT3MeshShapeFun", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m" // pName
};

static emlrtRTEInfo u_emlrtRTEI{
    8,                    // lineNo
    31,                   // colNo
    "CalcT3MeshShapeFun", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m" // pName
};

static emlrtRTEInfo
    v_emlrtRTEI{
        74,                  // lineNo
        9,                   // colNo
        "eml_mtimes_helper", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" // pName
    };

static emlrtRTEInfo w_emlrtRTEI{
    8,                    // lineNo
    8,                    // colNo
    "CalcT3MeshShapeFun", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m" // pName
};

static emlrtRTEInfo x_emlrtRTEI{
    8,                    // lineNo
    1,                    // colNo
    "CalcT3MeshShapeFun", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m" // pName
};

static emlrtRTEInfo y_emlrtRTEI{
    22,                   // lineNo
    13,                   // colNo
    "CalcT3MeshShapeFun", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m" // pName
};

static emlrtRTEInfo ab_emlrtRTEI{
    22,                   // lineNo
    26,                   // colNo
    "CalcT3MeshShapeFun", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m" // pName
};

static emlrtRTEInfo bb_emlrtRTEI{
    22,                   // lineNo
    41,                   // colNo
    "CalcT3MeshShapeFun", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m" // pName
};

static emlrtRTEInfo cb_emlrtRTEI{
    22,                   // lineNo
    54,                   // colNo
    "CalcT3MeshShapeFun", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m" // pName
};

static emlrtRTEInfo db_emlrtRTEI{
    1,                    // lineNo
    27,                   // colNo
    "CalcT3MeshShapeFun", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m" // pName
};

static emlrtRTEInfo eb_emlrtRTEI{
    24,                   // lineNo
    53,                   // colNo
    "CalcT3MeshShapeFun", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m" // pName
};

static emlrtRTEInfo fb_emlrtRTEI{
    24,                   // lineNo
    61,                   // colNo
    "CalcT3MeshShapeFun", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m" // pName
};

static emlrtRTEInfo gb_emlrtRTEI{
    27,                   // lineNo
    28,                   // colNo
    "CalcT3MeshShapeFun", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m" // pName
};

static emlrtRTEInfo hb_emlrtRTEI{
    27,                   // lineNo
    5,                    // colNo
    "CalcT3MeshShapeFun", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m" // pName
};

static emlrtRTEInfo xc_emlrtRTEI{
    22,                   // lineNo
    12,                   // colNo
    "CalcT3MeshShapeFun", // fName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m" // pName
};

static emlrtRSInfo cf_emlrtRSI{
    66,        // lineNo
    "fprintf", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m" // pathName
};

static emlrtRSInfo df_emlrtRSI{
    68,        // lineNo
    "fprintf", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m" // pathName
};

static emlrtRSInfo ff_emlrtRSI{
    53,              // lineNo
    "nonConstPrint", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\strfun\\sprintf.m" // pathName
};

static emlrtRSInfo gf_emlrtRSI{
    55,              // lineNo
    "nonConstPrint", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\strfun\\sprintf.m" // pathName
};

static emlrtRSInfo hf_emlrtRSI{
    22,                   // lineNo
    "CalcT3MeshShapeFun", // fcnName
    "C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
    "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeFunctions\\CalcT3MeshSh"
    "ap"
    "eFun.m" // pathName
};

static emlrtRSInfo kf_emlrtRSI{
    58,              // lineNo
    "nonConstPrint", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2024a\\toolbox\\eml\\lib\\matlab\\strfun\\sprintf.m" // pathName
};

// Function Declarations
static void b_and(const emlrtStack &sp, coder::array<boolean_T, 2U> &in1,
                  const coder::array<boolean_T, 2U> &in2);

static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<char_T, 2U> &ret);

static const mxArray *b_emlrt_marshallOut(const emlrtStack &sp,
                                          const char_T u[37]);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *tmpStr,
                             const char_T *identifier,
                             coder::array<char_T, 2U> &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<char_T, 2U> &y);

static const mxArray *emlrt_marshallOut(const emlrtStack &sp,
                                        const char_T u[7]);

static const mxArray *feval(const emlrtStack &sp, const mxArray *m1,
                            const mxArray *m2, const mxArray *m3,
                            emlrtMCInfo &location);

static const mxArray *feval(const emlrtStack &sp, const mxArray *m1,
                            const mxArray *m2, const mxArray *m3,
                            const mxArray *m4, emlrtMCInfo &location);

static const mxArray *length(const emlrtStack &sp, const mxArray *m1,
                             emlrtMCInfo &location);

// Function Definitions
static void b_and(const emlrtStack &sp, coder::array<boolean_T, 2U> &in1,
                  const coder::array<boolean_T, 2U> &in2)
{
  coder::array<boolean_T, 2U> b_in1;
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T b_loop_ub;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_1_0;
  int32_T stride_1_1;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  if (in2.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in2.size(0);
  }
  if (in2.size(1) == 1) {
    b_loop_ub = in1.size(1);
  } else {
    b_loop_ub = in2.size(1);
  }
  b_in1.set_size(&xc_emlrtRTEI, &sp, loop_ub, b_loop_ub);
  stride_0_0 = (in1.size(0) != 1);
  stride_0_1 = (in1.size(1) != 1);
  stride_1_0 = (in2.size(0) != 1);
  stride_1_1 = (in2.size(1) != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (int32_T i{0}; i < b_loop_ub; i++) {
    for (int32_T i1{0}; i1 < loop_ub; i1++) {
      b_in1[i1 + b_in1.size(0) * i] =
          (in1[i1 * stride_0_0 + in1.size(0) * aux_0_1] &&
           in2[i1 * stride_1_0 + in2.size(0) * aux_1_1]);
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  in1.set_size(&xc_emlrtRTEI, &sp, loop_ub, b_loop_ub);
  for (int32_T i{0}; i < b_loop_ub; i++) {
    for (int32_T i1{0}; i1 < loop_ub; i1++) {
      in1[i1 + in1.size(0) * i] = b_in1[i1 + b_in1.size(0) * i];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<char_T, 2U> &ret)
{
  static const int32_T dims[2]{1, -1};
  int32_T iv[2];
  boolean_T bv[2]{false, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "char", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret.set_size(static_cast<emlrtRTEInfo *>(nullptr), &sp, iv[0], iv[1]);
  emlrtImportArrayR2015b((emlrtConstCTX)&sp, src, &ret[0], 1, false);
  emlrtDestroyArray(&src);
}

static const mxArray *b_emlrt_marshallOut(const emlrtStack &sp,
                                          const char_T u[37])
{
  static const int32_T iv[2]{1, 37};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a((emlrtConstCTX)&sp, 37, m, &u[0]);
  emlrtAssign(&y, m);
  return y;
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *tmpStr,
                             const char_T *identifier,
                             coder::array<char_T, 2U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(tmpStr), &thisId, y);
  emlrtDestroyArray(&tmpStr);
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<char_T, 2U> &y)
{
  b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *emlrt_marshallOut(const emlrtStack &sp, const char_T u[7])
{
  static const int32_T iv[2]{1, 7};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a((emlrtConstCTX)&sp, 7, m, &u[0]);
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *feval(const emlrtStack &sp, const mxArray *m1,
                            const mxArray *m2, const mxArray *m3,
                            emlrtMCInfo &location)
{
  const mxArray *pArrays[3];
  const mxArray *m;
  pArrays[0] = m1;
  pArrays[1] = m2;
  pArrays[2] = m3;
  return emlrtCallMATLABR2012b((emlrtConstCTX)&sp, 1, &m, 3, &pArrays[0],
                               "feval", true, &location);
}

static const mxArray *feval(const emlrtStack &sp, const mxArray *m1,
                            const mxArray *m2, const mxArray *m3,
                            const mxArray *m4, emlrtMCInfo &location)
{
  const mxArray *pArrays[4];
  const mxArray *m;
  pArrays[0] = m1;
  pArrays[1] = m2;
  pArrays[2] = m3;
  pArrays[3] = m4;
  return emlrtCallMATLABR2012b((emlrtConstCTX)&sp, 1, &m, 4, &pArrays[0],
                               "feval", true, &location);
}

static const mxArray *length(const emlrtStack &sp, const mxArray *m1,
                             emlrtMCInfo &location)
{
  const mxArray *m;
  const mxArray *pArray;
  pArray = m1;
  return emlrtCallMATLABR2012b((emlrtConstCTX)&sp, 1, &m, 1, &pArray, "length",
                               true, &location);
}

void CalcT3MeshShapeFun(const emlrtStack *sp, real_T ee,
                        const coder::array<real_T, 2U> &coor,
                        const coder::array<real_T, 2U> &conn, real_T ndof,
                        real_T Npx, const coder::array<real_T, 2U> &X,
                        const coder::array<real_T, 2U> &Y, coder::sparse *PSI_X,
                        coder::sparse *PSI_Y)
{
  static const int32_T iv2[2]{1, 7};
  static const int32_T iv3[2]{1, 20};
  static const char_T cv1[37]{'C', 'a', 'l', 'c', 'u', 'l',  'a', 't', 'i', 'n',
                              'g', ' ', 't', 'h', 'e', ' ',  's', 'h', 'a', 'p',
                              'e', ' ', 'f', 'u', 'n', 'c',  't', 'i', 'o', 'n',
                              's', '.', '.', '.', ' ', '\\', 'n'};
  static const char_T formatSpec[20]{'e', 'l', 'e', 'm', 'e',  'n', 't',
                                     ' ', '%', '3', 'd', ' ',  '/', ' ',
                                     '%', '3', 'd', ' ', '\\', 'n'};
  static const char_T cv[7]{'f', 'p', 'r', 'i', 'n', 't', 'f'};
  static const char_T u[7]{'s', 'p', 'r', 'i', 'n', 't', 'f'};
  coder::b_sparse psi_x;
  coder::b_sparse psi_y;
  coder::c_sparse r8;
  coder::c_sparse r9;
  coder::c_sparse s;
  coder::array<real_T, 2U> vec;
  coder::array<real_T, 1U> b_Y;
  coder::array<real_T, 1U> linearIdx;
  coder::array<int32_T, 1U> r5;
  coder::array<uint32_T, 2U> col;
  coder::array<uint32_T, 2U> r;
  coder::array<uint32_T, 2U> r1;
  coder::array<uint32_T, 1U> varargin_1;
  coder::array<char_T, 2U> charStr;
  coder::array<boolean_T, 2U> Mask;
  coder::array<boolean_T, 2U> r2;
  coder::array<boolean_T, 2U> r3;
  coder::array<boolean_T, 2U> r4;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *m;
  const mxArray *tmpStr;
  const mxArray *y;
  real_T strSize;
  int32_T iv[2];
  int32_T b_X;
  int32_T b_col;
  int32_T b_coor;
  int32_T b_loop_ub_tmp;
  int32_T c_col;
  int32_T d_col;
  int32_T e_col;
  int32_T i;
  int32_T idx;
  int32_T loop_ub_tmp;
  int32_T ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &b_st;
  d_st.tls = b_st.tls;
  e_st.prev = &c_st;
  e_st.tls = c_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  //  Wiki link to barycentric coordinates:
  //  https://en.wikipedia.org/wiki/Barycentric_coordinate_system
  st.site = &emlrtRSI;
  coder::d_sparse(st, Npx, ndof, PSI_X);
  st.site = &b_emlrtRSI;
  coder::d_sparse(st, Npx, ndof, PSI_Y);
  if (coor.size(0) == 0) {
    idx = 0;
  } else {
    i = coor.size(0);
    idx = muIntScalarMax_sint32(i, 3);
  }
  if (idx < 1) {
    r.set_size(&t_emlrtRTEI, sp, 1, 0);
    r1.set_size(&u_emlrtRTEI, sp, 1, 0);
  } else {
    r.set_size(&t_emlrtRTEI, sp, 1, idx);
    ub = idx - 1;
    for (i = 0; i <= ub; i++) {
      r[i] = static_cast<uint32_T>(i) + 1U;
    }
    r1.set_size(&u_emlrtRTEI, sp, 1, idx);
    ub = idx - 1;
    for (i = 0; i <= ub; i++) {
      r1[i] = static_cast<uint32_T>(i) + 1U;
    }
  }
  ub = r1.size(1);
  linearIdx.set_size(&v_emlrtRTEI, sp, r1.size(1));
  for (i = 0; i < ub; i++) {
    linearIdx[i] = static_cast<real_T>(r1[i]) * 2.0;
  }
  st.site = &c_emlrtRSI;
  idx = r.size(1);
  varargin_1.set_size(&w_emlrtRTEI, &st, r.size(1));
  for (i = 0; i < idx; i++) {
    varargin_1[i] = (r[i] << 1) - 1U;
  }
  b_st.site = &l_emlrtRSI;
  c_st.site = &m_emlrtRSI;
  if (linearIdx.size(0) != varargin_1.size(0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &d_emlrtRTEI,
                                  "MATLAB:catenate:matrixDimensionMismatch",
                                  "MATLAB:catenate:matrixDimensionMismatch", 0);
  }
  col.set_size(&x_emlrtRTEI, &b_st, r.size(1), 2);
  for (i = 0; i < idx; i++) {
    col[i] = varargin_1[i];
  }
  for (i = 0; i < ub; i++) {
    col[i + col.size(0)] = static_cast<uint32_T>(linearIdx[i]);
  }
  st.site = &d_emlrtRSI;
  b_st.site = &n_emlrtRSI;
  y = nullptr;
  m = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&y, m);
  c_st.site = &cf_emlrtRSI;
  d_st.site = &df_emlrtRSI;
  strSize = emlrt_marshallIn(c_st,
                             feval(c_st, emlrt_marshallOut(c_st, cv), y,
                                   b_emlrt_marshallOut(d_st, cv1), emlrtMCI),
                             "<output of feval>");
  b_y = nullptr;
  m = emlrtCreateDoubleScalar(strSize);
  emlrtAssign(&b_y, m);
  emlrtDisplayR2012b(b_y, "ans", &emlrtRTEI, (emlrtCTX)sp);
  i = static_cast<int32_T>(ee);
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, ee, mxDOUBLE_CLASS,
                                static_cast<int32_T>(ee), &e_emlrtRTEI,
                                (emlrtConstCTX)sp);
  if (static_cast<int32_T>(ee) - 1 >= 0) {
    b_coor = coor.size(0);
    loop_ub_tmp = X.size(0) * X.size(1);
    b_loop_ub_tmp = Y.size(0) * Y.size(1);
    b_X = X.size(0);
    b_col = r.size(1);
    c_col = r.size(1);
    d_col = r.size(1);
    e_col = r.size(1);
  }
  for (int32_T kk{0}; kk < i; kk++) {
    __m128d r6;
    real_T coord[6];
    real_T f_col[3];
    real_T x_max;
    real_T x_min;
    real_T y_max;
    real_T y_min;
    int32_T iv1[2];
    int32_T c_loop_ub_tmp;
    int32_T i1;
    int32_T i2;
    int32_T k;
    uint32_T b_col_tmp;
    uint32_T c_col_tmp;
    uint32_T col_tmp;
    boolean_T b;
    boolean_T exitg1;
    //  tic
    if ((kk + 1 < 1) || (kk + 1 > conn.size(0))) {
      emlrtDynamicBoundsCheckR2012b(kk + 1, 1, conn.size(0), &emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    i1 = static_cast<int32_T>(conn[kk]);
    c_loop_ub_tmp = static_cast<int32_T>(conn[kk + conn.size(0)]);
    i2 = static_cast<int32_T>(conn[kk + conn.size(0) * 2]);
    for (idx = 0; idx < 2; idx++) {
      if (conn[kk] != static_cast<int32_T>(muDoubleScalarFloor(conn[kk]))) {
        emlrtIntegerCheckR2012b(conn[kk], &b_emlrtDCI, (emlrtConstCTX)sp);
      }
      if ((i1 < 1) || (i1 > b_coor)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, b_coor, &h_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      coord[3 * idx] = coor[(i1 + coor.size(0) * idx) - 1];
      if (conn[kk + conn.size(0)] !=
          static_cast<int32_T>(muDoubleScalarFloor(conn[kk + conn.size(0)]))) {
        emlrtIntegerCheckR2012b(conn[kk + conn.size(0)], &b_emlrtDCI,
                                (emlrtConstCTX)sp);
      }
      if ((c_loop_ub_tmp < 1) || (c_loop_ub_tmp > b_coor)) {
        emlrtDynamicBoundsCheckR2012b(c_loop_ub_tmp, 1, b_coor, &h_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      coord[3 * idx + 1] = coor[(c_loop_ub_tmp + coor.size(0) * idx) - 1];
      if (conn[kk + conn.size(0) * 2] !=
          static_cast<int32_T>(
              muDoubleScalarFloor(conn[kk + conn.size(0) * 2]))) {
        emlrtIntegerCheckR2012b(conn[kk + conn.size(0) * 2], &b_emlrtDCI,
                                (emlrtConstCTX)sp);
      }
      if ((i2 < 1) || (i2 > b_coor)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, b_coor, &h_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      coord[3 * idx + 2] = coor[(i2 + coor.size(0) * idx) - 1];
    }
    b = !muDoubleScalarIsNaN(coord[3]);
    if (b) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 4)) {
        if (!muDoubleScalarIsNaN(coord[k + 2])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      x_min = coord[3];
    } else {
      x_min = coord[idx + 2];
      i1 = idx + 1;
      for (k = i1; k < 4; k++) {
        strSize = coord[k + 2];
        if (x_min > strSize) {
          x_min = strSize;
        }
      }
    }
    if (b) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 4)) {
        if (!muDoubleScalarIsNaN(coord[k + 2])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      x_max = coord[3];
    } else {
      x_max = coord[idx + 2];
      i1 = idx + 1;
      for (k = i1; k < 4; k++) {
        strSize = coord[k + 2];
        if (x_max < strSize) {
          x_max = strSize;
        }
      }
    }
    b = !muDoubleScalarIsNaN(coord[0]);
    if (b) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 4)) {
        if (!muDoubleScalarIsNaN(coord[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      y_min = coord[0];
    } else {
      y_min = coord[idx - 1];
      i1 = idx + 1;
      for (k = i1; k < 4; k++) {
        strSize = coord[k - 1];
        if (y_min > strSize) {
          y_min = strSize;
        }
      }
    }
    if (b) {
      idx = 1;
    } else {
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 4)) {
        if (!muDoubleScalarIsNaN(coord[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      y_max = coord[0];
    } else {
      y_max = coord[idx - 1];
      i1 = idx + 1;
      for (k = i1; k < 4; k++) {
        strSize = coord[k - 1];
        if (y_max < strSize) {
          y_max = strSize;
        }
      }
    }
    //  Create a mask for the bounding box
    Mask.set_size(&y_emlrtRTEI, sp, X.size(0), X.size(1));
    r2.set_size(&ab_emlrtRTEI, sp, X.size(0), X.size(1));
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      Mask[i1] = (X[i1] >= x_min);
      r2[i1] = (X[i1] <= x_max);
    }
    if ((Mask.size(0) != r2.size(0)) || (Mask.size(1) != r2.size(1))) {
      emlrtSizeEqCheckNDErrorR2021b(Mask.size(), r2.size(), &e_emlrtECI,
                                    (emlrtCTX)sp);
    }
    r3.set_size(&bb_emlrtRTEI, sp, Y.size(0), Y.size(1));
    r4.set_size(&cb_emlrtRTEI, sp, Y.size(0), Y.size(1));
    for (i1 = 0; i1 < b_loop_ub_tmp; i1++) {
      r3[i1] = (Y[i1] >= y_min);
      r4[i1] = (Y[i1] <= y_max);
    }
    if ((r3.size(0) != r4.size(0)) || (r3.size(1) != r4.size(1))) {
      emlrtSizeEqCheckNDErrorR2021b(r3.size(), r4.size(), &d_emlrtECI,
                                    (emlrtCTX)sp);
    }
    c_loop_ub_tmp = Mask.size(0) * Mask.size(1);
    for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
      Mask[i1] = (Mask[i1] && r2[i1]);
    }
    idx = r3.size(0) * r3.size(1);
    for (i1 = 0; i1 < idx; i1++) {
      r3[i1] = (r3[i1] && r4[i1]);
    }
    if ((X.size(0) != Y.size(0)) && ((X.size(0) != 1) && (Y.size(0) != 1))) {
      emlrtDimSizeImpxCheckR2021b(X.size(0), Y.size(0), &c_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if ((X.size(1) != Y.size(1)) && ((X.size(1) != 1) && (Y.size(1) != 1))) {
      emlrtDimSizeImpxCheckR2021b(X.size(1), Y.size(1), &b_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    if ((Mask.size(0) == r3.size(0)) && (Mask.size(1) == r3.size(1))) {
      for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
        Mask[i1] = (Mask[i1] && r3[i1]);
      }
    } else {
      st.site = &hf_emlrtRSI;
      b_and(st, Mask, r3);
    }
    iv[0] = (*(int32_T(*)[2])((coder::array<real_T, 2U> *)&X)->size())[0];
    iv[1] = (*(int32_T(*)[2])((coder::array<real_T, 2U> *)&X)->size())[1];
    iv1[0] = (*(int32_T(*)[2])Mask.size())[0];
    iv1[1] = (*(int32_T(*)[2])Mask.size())[1];
    st.site = &e_emlrtRSI;
    coder::internal::indexShapeCheck(st, iv, iv1);
    iv[0] = (*(int32_T(*)[2])((coder::array<real_T, 2U> *)&Y)->size())[0];
    iv[1] = (*(int32_T(*)[2])((coder::array<real_T, 2U> *)&Y)->size())[1];
    iv1[0] = (*(int32_T(*)[2])Mask.size())[0];
    iv1[1] = (*(int32_T(*)[2])Mask.size())[1];
    st.site = &e_emlrtRSI;
    coder::internal::indexShapeCheck(st, iv, iv1);
    ub = Mask.size(0) * Mask.size(1) - 1;
    idx = 0;
    for (c_loop_ub_tmp = 0; c_loop_ub_tmp <= ub; c_loop_ub_tmp++) {
      if (Mask[c_loop_ub_tmp]) {
        idx++;
      }
    }
    r5.set_size(&db_emlrtRTEI, sp, idx);
    idx = 0;
    for (c_loop_ub_tmp = 0; c_loop_ub_tmp <= ub; c_loop_ub_tmp++) {
      if (Mask[c_loop_ub_tmp]) {
        r5[idx] = c_loop_ub_tmp;
        idx++;
      }
    }
    c_loop_ub_tmp = r5.size(0);
    linearIdx.set_size(&eb_emlrtRTEI, sp, r5.size(0));
    for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
      if (r5[i1] > loop_ub_tmp - 1) {
        emlrtDynamicBoundsCheckR2012b(r5[i1], 0, loop_ub_tmp - 1, &b_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      linearIdx[i1] = X[r5[i1]];
    }
    b_Y.set_size(&fb_emlrtRTEI, sp, r5.size(0));
    for (i1 = 0; i1 < c_loop_ub_tmp; i1++) {
      if (r5[i1] > b_loop_ub_tmp - 1) {
        emlrtDynamicBoundsCheckR2012b(r5[i1], 0, b_loop_ub_tmp - 1, &c_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      b_Y[i1] = Y[r5[i1]];
    }
    st.site = &e_emlrtRSI;
    T3ElementShapeFun_V2(st, coord, linearIdx, b_Y, psi_x, psi_y, vec);
    c_loop_ub_tmp = vec.size(0);
    linearIdx.set_size(&gb_emlrtRTEI, sp, vec.size(0));
    idx = (vec.size(0) / 2) << 1;
    ub = idx - 2;
    for (i1 = 0; i1 <= ub; i1 += 2) {
      r6 = _mm_loadu_pd(&vec[i1 + vec.size(0)]);
      _mm_storeu_pd(&linearIdx[i1],
                    _mm_mul_pd(_mm_sub_pd(r6, _mm_set1_pd(1.0)),
                               _mm_set1_pd(static_cast<real_T>(b_X))));
    }
    for (i1 = idx; i1 < c_loop_ub_tmp; i1++) {
      linearIdx[i1] = (vec[i1 + vec.size(0)] - 1.0) * static_cast<real_T>(b_X);
    }
    if (vec.size(0) != linearIdx.size(0)) {
      emlrtSizeEqCheck1DR2012b(vec.size(0), linearIdx.size(0), &emlrtECI,
                               (emlrtConstCTX)sp);
    }
    linearIdx.set_size(&hb_emlrtRTEI, sp, vec.size(0));
    for (i1 = 0; i1 <= ub; i1 += 2) {
      __m128d r7;
      r6 = _mm_loadu_pd(&vec[i1]);
      r7 = _mm_loadu_pd(&linearIdx[i1]);
      _mm_storeu_pd(&linearIdx[i1], _mm_add_pd(r6, r7));
    }
    for (i1 = idx; i1 < c_loop_ub_tmp; i1++) {
      linearIdx[i1] = vec[i1] + linearIdx[i1];
    }
    st.site = &f_emlrtRSI;
    b_st.site = &dc_emlrtRSI;
    c_st.site = &fc_emlrtRSI;
    e_st.site = &lc_emlrtRSI;
    f_st.site = &mc_emlrtRSI;
    ub = psi_x.m * 3;
    idx = ((((psi_x.colidx[1] - psi_x.colidx[0]) + psi_x.colidx[3]) -
            psi_x.colidx[2]) +
           psi_x.colidx[5]) -
          psi_x.colidx[4];
    if ((idx > ub) && (ub != 0)) {
      emlrtErrorWithMessageIdR2018a(&e_st, &c_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    f_st.site = &nc_emlrtRSI;
    coder::sparse::spallocLike(f_st, psi_x.m, idx, s);
    if (idx != 0) {
      idx = 0;
      for (int32_T cidx{0}; cidx < 3; cidx++) {
        i1 = cidx << 1;
        c_loop_ub_tmp = psi_x.colidx[i1];
        ub = psi_x.colidx[i1 + 1] - c_loop_ub_tmp;
        f_st.site = &oc_emlrtRSI;
        if (ub > 2147483646) {
          g_st.site = &gb_emlrtRSI;
          coder::check_forloop_overflow_error(g_st);
        }
        for (k = 0; k < ub; k++) {
          i1 = (c_loop_ub_tmp + k) - 1;
          i2 = idx + k;
          s.d[i2] = psi_x.d[i1];
          s.rowidx[i2] = psi_x.rowidx[i1];
        }
        if (ub - 1 >= 0) {
          idx += ub;
        }
        s.colidx[cidx + 1] = s.colidx[cidx] + ub;
      }
    }
    i1 = static_cast<int32_T>(conn[kk]);
    if ((i1 < 1) || (i1 > b_col)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, b_col, &g_emlrtBCI, &st);
    }
    col_tmp = col[i1 - 1];
    f_col[0] = col_tmp;
    c_loop_ub_tmp = static_cast<int32_T>(conn[kk + conn.size(0)]);
    if ((c_loop_ub_tmp < 1) || (c_loop_ub_tmp > b_col)) {
      emlrtDynamicBoundsCheckR2012b(c_loop_ub_tmp, 1, b_col, &g_emlrtBCI, &st);
    }
    b_col_tmp = col[c_loop_ub_tmp - 1];
    f_col[1] = b_col_tmp;
    i2 = static_cast<int32_T>(conn[kk + conn.size(0) * 2]);
    if ((i2 < 1) || (i2 > b_col)) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, b_col, &g_emlrtBCI, &st);
    }
    c_col_tmp = col[i2 - 1];
    f_col[2] = c_col_tmp;
    b_st.site = &dc_emlrtRSI;
    PSI_X->parenReference(b_st, linearIdx, f_col, r8);
    b_st.site = &dc_emlrtRSI;
    r8.plus(b_st, s, r9);
    if (i1 > c_col) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, c_col, &f_emlrtBCI, &st);
    }
    f_col[0] = col_tmp;
    if (c_loop_ub_tmp > c_col) {
      emlrtDynamicBoundsCheckR2012b(c_loop_ub_tmp, 1, c_col, &f_emlrtBCI, &st);
    }
    f_col[1] = b_col_tmp;
    if (i2 > c_col) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, c_col, &f_emlrtBCI, &st);
    }
    f_col[2] = c_col_tmp;
    b_st.site = &dc_emlrtRSI;
    PSI_X->parenAssign(b_st, r9, linearIdx, f_col);
    if (i1 > d_col) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, d_col, &e_emlrtBCI, &st);
    }
    col_tmp = col[(i1 + col.size(0)) - 1];
    f_col[0] = col_tmp;
    if (c_loop_ub_tmp > d_col) {
      emlrtDynamicBoundsCheckR2012b(c_loop_ub_tmp, 1, d_col, &e_emlrtBCI, &st);
    }
    b_col_tmp = col[(c_loop_ub_tmp + col.size(0)) - 1];
    f_col[1] = b_col_tmp;
    if (i2 > d_col) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, d_col, &e_emlrtBCI, &st);
    }
    c_col_tmp = col[(i2 + col.size(0)) - 1];
    f_col[2] = c_col_tmp;
    b_st.site = &ec_emlrtRSI;
    PSI_Y->parenReference(b_st, linearIdx, f_col, r8);
    b_st.site = &ec_emlrtRSI;
    psi_y.parenReference(b_st, r9);
    b_st.site = &ec_emlrtRSI;
    r8.plus(b_st, r9, s);
    if (i1 > e_col) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, e_col, &d_emlrtBCI, &st);
    }
    f_col[0] = col_tmp;
    if (c_loop_ub_tmp > e_col) {
      emlrtDynamicBoundsCheckR2012b(c_loop_ub_tmp, 1, e_col, &d_emlrtBCI, &st);
    }
    f_col[1] = b_col_tmp;
    if (i2 > e_col) {
      emlrtDynamicBoundsCheckR2012b(i2, 1, e_col, &d_emlrtBCI, &st);
    }
    f_col[2] = c_col_tmp;
    b_st.site = &ec_emlrtRSI;
    PSI_Y->parenAssign(b_st, s, linearIdx, f_col);
    if (muDoubleScalarRem(static_cast<real_T>(kk) + 1.0, 100.0) == 1.0) {
      int16_T i3;
      st.site = &g_emlrtRSI;
      b_st.site = &bf_emlrtRSI;
      tmpStr = nullptr;
      c_y = nullptr;
      m = emlrtCreateCharArray(2, &iv2[0]);
      emlrtInitCharArrayR2013a(&b_st, 7, m, &u[0]);
      emlrtAssign(&c_y, m);
      d_y = nullptr;
      m = emlrtCreateCharArray(2, &iv3[0]);
      emlrtInitCharArrayR2013a(&b_st, 20, m, &formatSpec[0]);
      emlrtAssign(&d_y, m);
      e_y = nullptr;
      m = emlrtCreateNumericMatrix(1, 1, mxINT16_CLASS, mxREAL);
      if (static_cast<uint32_T>(kk) + 1U < 32768U) {
        i3 = static_cast<int16_T>(static_cast<real_T>(kk) + 1.0);
      } else {
        i3 = MAX_int16_T;
      }
      *static_cast<int16_T *>(emlrtMxGetData(m)) = i3;
      emlrtAssign(&e_y, m);
      f_y = nullptr;
      m = emlrtCreateNumericMatrix(1, 1, mxINT16_CLASS, mxREAL);
      strSize = muDoubleScalarRound(ee);
      if (strSize < 32768.0) {
        if (strSize >= -32768.0) {
          i3 = static_cast<int16_T>(strSize);
        } else {
          i3 = MIN_int16_T;
        }
      } else if (strSize >= 32768.0) {
        i3 = MAX_int16_T;
      } else {
        i3 = 0;
      }
      *static_cast<int16_T *>(emlrtMxGetData(m)) = i3;
      emlrtAssign(&f_y, m);
      c_st.site = &ff_emlrtRSI;
      emlrtAssign(&tmpStr, feval(c_st, c_y, d_y, e_y, f_y, d_emlrtMCI));
      c_st.site = &gf_emlrtRSI;
      strSize =
          emlrt_marshallIn(c_st, length(c_st, emlrtAlias(tmpStr), e_emlrtMCI),
                           "<output of length>");
      if (!(strSize >= 0.0)) {
        emlrtNonNegativeCheckR2012b(strSize, &emlrtDCI, &b_st);
      }
      c_st.site = &kf_emlrtRSI;
      emlrt_marshallIn(c_st, emlrtAlias(tmpStr), "tmpStr", charStr);
      emlrtDestroyArray(&tmpStr);
      g_y = nullptr;
      iv[0] = 1;
      iv[1] = charStr.size(1);
      m = emlrtCreateCharArray(2, &iv[0]);
      emlrtInitCharArrayR2013a((emlrtConstCTX)sp, charStr.size(1), m,
                               &charStr[0]);
      emlrtAssign(&g_y, m);
      emlrtDisplayR2012b(g_y, "ans", &b_emlrtRTEI, (emlrtCTX)sp);
      //  toc
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

// End of code generation (CalcT3MeshShapeFun.cpp)
