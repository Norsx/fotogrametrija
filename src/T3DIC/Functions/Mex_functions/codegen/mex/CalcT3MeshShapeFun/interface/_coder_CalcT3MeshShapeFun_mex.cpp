//
// _coder_CalcT3MeshShapeFun_mex.cpp
//
// Code generation for function '_coder_CalcT3MeshShapeFun_mex'
//

// Include files
#include "_coder_CalcT3MeshShapeFun_mex.h"
#include "CalcT3MeshShapeFun_data.h"
#include "CalcT3MeshShapeFun_initialize.h"
#include "CalcT3MeshShapeFun_terminate.h"
#include "_coder_CalcT3MeshShapeFun_api.h"
#include "rt_nonfinite.h"
#include <stdexcept>

void emlrtExceptionBridge();
void emlrtExceptionBridge()
{
  throw std::runtime_error("");
}
// Function Definitions
void CalcT3MeshShapeFun_mexFunction(int32_T nlhs, mxArray *plhs[2],
                                    int32_T nrhs, const mxArray *prhs[7])
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  const mxArray *outputs[2];
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  // Check for proper number of arguments.
  if (nrhs != 7) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 7, 4,
                        18, "CalcT3MeshShapeFun");
  }
  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 18,
                        "CalcT3MeshShapeFun");
  }
  // Call the function.
  CalcT3MeshShapeFun_api(prhs, nlhs, outputs);
  // Copy over outputs to the caller.
  if (nlhs < 1) {
    i = 1;
  } else {
    i = nlhs;
  }
  emlrtReturnArrays(i, &plhs[0], &outputs[0]);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&CalcT3MeshShapeFun_atexit);
  // Module initialization.
  CalcT3MeshShapeFun_initialize();
  try { // Dispatch the entry-point.
    CalcT3MeshShapeFun_mexFunction(nlhs, plhs, nrhs, prhs);
    // Module termination.
    CalcT3MeshShapeFun_terminate();
  } catch (...) {
    emlrtCleanupOnException((emlrtCTX *)emlrtRootTLSGlobal);
    throw;
  }
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, nullptr, 1,
                           (void *)&emlrtExceptionBridge, "windows-1250", true);
  return emlrtRootTLSGlobal;
}

// End of code generation (_coder_CalcT3MeshShapeFun_mex.cpp)
