//
// _coder_CalcGlobalT3ShapeFun_api.cpp
//
// Code generation for function '_coder_CalcGlobalT3ShapeFun_api'
//

// Include files
#include "_coder_CalcGlobalT3ShapeFun_api.h"
#include "CalcGlobalT3ShapeFun.h"
#include "CalcGlobalT3ShapeFun_data.h"
#include "rt_nonfinite.h"
#include "sparse.h"
#include "coder_array.h"

// Function Declarations
static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<int32_T, 1U> &ret);

static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 1U> &y);

static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret);

static real_T (*b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3];

static void c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 1U> &ret);

static int32_T c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId);

static void d_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 1U> &ret);

static real_T (*d_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[3];

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier, coder::sparse &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::sparse &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier, coder::b_sparse &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::b_sparse &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 1U> &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<int32_T, 1U> &y);

static int32_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier,
                             coder::array<real_T, 1U> &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier,
                             coder::array<real_T, 2U> &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 2U> &y);

static real_T (*emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                                 const char_T *identifier))[3];

static const mxArray *emlrt_marshallOut(const coder::sparse &u);

// Function Definitions
static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<int32_T, 1U> &ret)
{
  static const int32_T dims{-1};
  int32_T i;
  boolean_T b{true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "int32", false, 1U,
                            (const void *)&dims, &b, &i);
  ret.set_size(static_cast<emlrtRTEInfo *>(nullptr), &sp, i);
  emlrtImportArrayR2015b((emlrtConstCTX)&sp, src, &(ret.data())[0], 4, false);
  emlrtDestroyArray(&src);
}

static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 1U> &y)
{
  d_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret)
{
  static const int32_T dims[2]{-1, 2};
  int32_T iv[2];
  boolean_T bv[2]{true, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret.prealloc(iv[0] * iv[1]);
  ret.set_size(static_cast<emlrtRTEInfo *>(nullptr), &sp, iv[0], iv[1]);
  ret.set(static_cast<real_T *>(emlrtMxGetData(src)), ret.size(0), ret.size(1));
  emlrtDestroyArray(&src);
}

static real_T (*b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3]
{
  real_T(*y)[3];
  y = d_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 1U> &ret)
{
  static const int32_T dims{-1};
  int32_T i;
  boolean_T b{true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &i);
  ret.set_size(static_cast<emlrtRTEInfo *>(nullptr), &sp, i);
  emlrtImportArrayR2015b((emlrtConstCTX)&sp, src, &(ret.data())[0], 8, false);
  emlrtDestroyArray(&src);
}

static int32_T c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  int32_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "int32", false, 0U,
                          (const void *)&dims);
  ret = *static_cast<int32_T *>(emlrtMxGetData(src));
  emlrtDestroyArray(&src);
  return ret;
}

static void d_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 1U> &ret)
{
  static const int32_T dims{-1};
  int32_T i;
  boolean_T b{true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 1U,
                            (const void *)&dims, &b, &i);
  ret.prealloc(i);
  ret.set_size(static_cast<emlrtRTEInfo *>(nullptr), &sp, i);
  ret.set(static_cast<real_T *>(emlrtMxGetData(src)), ret.size(0));
  emlrtDestroyArray(&src);
}

static real_T (*d_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[3]
{
  static const int32_T dims[2]{1, 3};
  real_T(*ret)[3];
  int32_T iv[2];
  boolean_T bv[2]{false, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret = (real_T(*)[3])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier, coder::sparse &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId, y);
  emlrtDestroyArray(&b_nullptr);
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::sparse &y)
{
  emlrtMsgIdentifier thisId;
  const mxArray *propValues[6];
  int32_T iv[2];
  const char_T *propClasses[6]{
      "coder.internal.sparse", "coder.internal.sparse",
      "coder.internal.sparse", "coder.internal.sparse",
      "coder.internal.sparse", "coder.internal.sparse"};
  const char_T *propNames[6]{"d", "colidx", "rowidx", "m", "n", "maxnz"};
  boolean_T bv[2];
  for (int32_T i{0}; i < 6; i++) {
    propValues[i] = nullptr;
  }
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  bv[0] = true;
  iv[0] = -1;
  bv[1] = true;
  iv[1] = -1;
  emlrtCheckSparse((emlrtCTX)&sp, parentId, u, &iv[0], &bv[0], mxDOUBLE_CLASS,
                   mxREAL);
  emlrtCheckMcosClass2017a((emlrtCTX)&sp, parentId, u, "sparse");
  emlrtAssign(&u, emlrtConvertInstanceToRedirectTarget(
                      (emlrtCTX)&sp, u, 0, "coder.internal.sparse"));
  emlrtCheckMcosClass2017a((emlrtCTX)&sp, parentId, u, "coder.internal.sparse");
  emlrtGetAllProperties((emlrtCTX)&sp, u, 0, 6, (const char_T **)&propNames[0],
                        (const char_T **)&propClasses[0], &propValues[0]);
  thisId.fIdentifier = "d";
  emlrt_marshallIn(sp, emlrtAlias(propValues[0]), &thisId, y.d);
  thisId.fIdentifier = "colidx";
  emlrt_marshallIn(sp, emlrtAlias(propValues[1]), &thisId, y.colidx);
  thisId.fIdentifier = "rowidx";
  emlrt_marshallIn(sp, emlrtAlias(propValues[2]), &thisId, y.rowidx);
  thisId.fIdentifier = "m";
  y.m = emlrt_marshallIn(sp, emlrtAlias(propValues[3]), &thisId);
  thisId.fIdentifier = "n";
  y.n = emlrt_marshallIn(sp, emlrtAlias(propValues[4]), &thisId);
  thisId.fIdentifier = "maxnz";
  y.maxnz = emlrt_marshallIn(sp, emlrtAlias(propValues[5]), &thisId);
  emlrtDestroyArrays(6, &propValues[0]);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier, coder::b_sparse &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId, y);
  emlrtDestroyArray(&b_nullptr);
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::b_sparse &y)
{
  static const boolean_T bv[2]{true, false};
  emlrtMsgIdentifier thisId;
  const mxArray *propValues[5];
  int32_T iv[2];
  const char_T *propClasses[5]{"coder.internal.sparse", "coder.internal.sparse",
                               "coder.internal.sparse", "coder.internal.sparse",
                               "coder.internal.sparse"};
  const char_T *propNames[5]{"d", "colidx", "rowidx", "m", "maxnz"};
  for (int32_T i{0}; i < 5; i++) {
    propValues[i] = nullptr;
  }
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  iv[0] = -1;
  iv[1] = 6;
  emlrtCheckSparse((emlrtCTX)&sp, parentId, u, &iv[0], &bv[0], mxDOUBLE_CLASS,
                   mxREAL);
  emlrtCheckMcosClass2017a((emlrtCTX)&sp, parentId, u, "sparse");
  emlrtAssign(&u, emlrtConvertInstanceToRedirectTarget(
                      (emlrtCTX)&sp, u, 0, "coder.internal.sparse"));
  emlrtCheckMcosClass2017a((emlrtCTX)&sp, parentId, u, "coder.internal.sparse");
  emlrtGetAllProperties((emlrtCTX)&sp, u, 0, 5, (const char_T **)&propNames[0],
                        (const char_T **)&propClasses[0], &propValues[0]);
  thisId.fIdentifier = "d";
  emlrt_marshallIn(sp, emlrtAlias(propValues[0]), &thisId, y.d);
  thisId.fIdentifier = "colidx";
  emlrt_marshallIn(sp, emlrtAlias(propValues[1]), &thisId, y.colidx);
  thisId.fIdentifier = "rowidx";
  emlrt_marshallIn(sp, emlrtAlias(propValues[2]), &thisId, y.rowidx);
  thisId.fIdentifier = "m";
  y.m = emlrt_marshallIn(sp, emlrtAlias(propValues[3]), &thisId);
  thisId.fIdentifier = "maxnz";
  emlrt_marshallIn(sp, emlrtAlias(propValues[4]), &thisId);
  emlrtDestroyArrays(5, &propValues[0]);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 1U> &y)
{
  c_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<int32_T, 1U> &y)
{
  b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static int32_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId)
{
  int32_T y;
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier,
                             coder::array<real_T, 1U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId, y);
  emlrtDestroyArray(&b_nullptr);
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier,
                             coder::array<real_T, 2U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId, y);
  emlrtDestroyArray(&b_nullptr);
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 2U> &y)
{
  b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                                 const char_T *identifier))[3]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[3];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId);
  emlrtDestroyArray(&b_nullptr);
  return y;
}

static const mxArray *emlrt_marshallOut(const coder::sparse &u)
{
  const mxArray *y;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateSparse(
                      &(((coder::array<real_T, 1U> *)&u.d)->data())[0],
                      &(((coder::array<int32_T, 1U> *)&u.colidx)->data())[0],
                      &(((coder::array<int32_T, 1U> *)&u.rowidx)->data())[0],
                      u.m, u.n, u.maxnz, mxDOUBLE_CLASS, mxREAL));
  return y;
}

void CalcGlobalT3ShapeFun_api(const mxArray *const prhs[7], int32_T nlhs,
                              const mxArray *plhs[2])
{
  coder::b_sparse psi_x;
  coder::b_sparse psi_y;
  coder::sparse PSI_X;
  coder::sparse PSI_Y;
  coder::array<real_T, 2U> col;
  coder::array<real_T, 1U> ind;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T(*n_id)[3];
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  emlrt_marshallIn(st, emlrtAliasP(prhs[0]), "PSI_X", PSI_X);
  emlrt_marshallIn(st, emlrtAliasP(prhs[1]), "PSI_Y", PSI_Y);
  ind.no_free();
  emlrt_marshallIn(st, emlrtAlias(prhs[2]), "ind", ind);
  col.no_free();
  emlrt_marshallIn(st, emlrtAlias(prhs[3]), "col", col);
  n_id = emlrt_marshallIn(st, emlrtAlias(prhs[4]), "n_id");
  emlrt_marshallIn(st, emlrtAliasP(prhs[5]), "psi_x", psi_x);
  emlrt_marshallIn(st, emlrtAliasP(prhs[6]), "psi_y", psi_y);
  // Invoke the target function
  CalcGlobalT3ShapeFun(&st, &PSI_X, &PSI_Y, ind, col, *n_id, &psi_x, &psi_y);
  // Marshall function outputs
  plhs[0] = emlrt_marshallOut(PSI_X);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(PSI_Y);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

// End of code generation (_coder_CalcGlobalT3ShapeFun_api.cpp)
