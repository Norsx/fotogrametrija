//
// _coder_CalcT3MeshShapeFun_api.cpp
//
// Code generation for function '_coder_CalcT3MeshShapeFun_api'
//

// Include files
#include "_coder_CalcT3MeshShapeFun_api.h"
#include "CalcT3MeshShapeFun.h"
#include "CalcT3MeshShapeFun_data.h"
#include "CalcT3MeshShapeFun_mexutil.h"
#include "rt_nonfinite.h"
#include "sparse1.h"
#include "coder_array.h"

// Function Declarations
static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                               const char_T *identifier,
                               coder::array<real_T, 2U> &y);

static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 2U> &y);

static void c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret);

static void d_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                             const char_T *identifier,
                             coder::array<real_T, 2U> &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 2U> &y);

static const mxArray *emlrt_marshallOut(const coder::sparse &u);

// Function Definitions
static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                               const char_T *identifier,
                               coder::array<real_T, 2U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId, y);
  emlrtDestroyArray(&b_nullptr);
}

static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<real_T, 2U> &y)
{
  d_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret)
{
  static const int32_T dims[2]{-1, 3};
  int32_T iv[2];
  boolean_T bv[2]{true, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret.prealloc(iv[0] * iv[1]);
  ret.set_size(static_cast<emlrtRTEInfo *>(nullptr), &sp, iv[0], iv[1]);
  ret.set(static_cast<real_T *>(emlrtMxGetData(src)), ret.size(0), ret.size(1));
  emlrtDestroyArray(&src);
}

static void d_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret)
{
  static const int32_T dims[2]{-1, -1};
  int32_T iv[2];
  boolean_T bv[2]{true, true};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret.prealloc(iv[0] * iv[1]);
  ret.set_size(static_cast<emlrtRTEInfo *>(nullptr), &sp, iv[0], iv[1]);
  ret.set(static_cast<real_T *>(emlrtMxGetData(src)), ret.size(0), ret.size(1));
  emlrtDestroyArray(&src);
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
  c_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
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

void CalcT3MeshShapeFun_api(const mxArray *const prhs[7], int32_T nlhs,
                            const mxArray *plhs[2])
{
  coder::sparse PSI_X;
  coder::sparse PSI_Y;
  coder::array<real_T, 2U> X;
  coder::array<real_T, 2U> Y;
  coder::array<real_T, 2U> conn;
  coder::array<real_T, 2U> coor;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  real_T Npx;
  real_T ee;
  real_T ndof;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  ee = emlrt_marshallIn(st, emlrtAliasP(prhs[0]), "ee");
  coor.no_free();
  emlrt_marshallIn(st, emlrtAlias(prhs[1]), "coor", coor);
  conn.no_free();
  emlrt_marshallIn(st, emlrtAlias(prhs[2]), "conn", conn);
  ndof = emlrt_marshallIn(st, emlrtAliasP(prhs[3]), "ndof");
  Npx = emlrt_marshallIn(st, emlrtAliasP(prhs[4]), "Npx");
  X.no_free();
  b_emlrt_marshallIn(st, emlrtAlias(prhs[5]), "X", X);
  Y.no_free();
  b_emlrt_marshallIn(st, emlrtAlias(prhs[6]), "Y", Y);
  // Invoke the target function
  CalcT3MeshShapeFun(&st, ee, coor, conn, ndof, Npx, X, Y, &PSI_X, &PSI_Y);
  // Marshall function outputs
  plhs[0] = emlrt_marshallOut(PSI_X);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(PSI_Y);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

// End of code generation (_coder_CalcT3MeshShapeFun_api.cpp)
