//
// _coder_T3ElementShapeFun_V2_mex.cpp
//
// Code generation for function '_coder_T3ElementShapeFun_V2_mex'
//

// Include files
#include "_coder_T3ElementShapeFun_V2_mex.h"
#include "T3ElementShapeFun_V2_data.h"
#include "T3ElementShapeFun_V2_initialize.h"
#include "T3ElementShapeFun_V2_terminate.h"
#include "_coder_T3ElementShapeFun_V2_api.h"
#include "rt_nonfinite.h"
#include <stdexcept>

void emlrtExceptionBridge();
void emlrtExceptionBridge()
{
  throw std::runtime_error("");
}
// Function Definitions
void T3ElementShapeFun_V2_mexFunction(int32_T nlhs, mxArray *plhs[3],
                                      int32_T nrhs, const mxArray *prhs[3])
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  const mxArray *outputs[3];
  int32_T i;
  st.tls = emlrtRootTLSGlobal;
  // Check for proper number of arguments.
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        20, "T3ElementShapeFun_V2");
  }
  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 20,
                        "T3ElementShapeFun_V2");
  }
  // Call the function.
  T3ElementShapeFun_V2_api(prhs, nlhs, outputs);
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
  mexAtExit(&T3ElementShapeFun_V2_atexit);
  // Module initialization.
  T3ElementShapeFun_V2_initialize();
  try { // Dispatch the entry-point.
    T3ElementShapeFun_V2_mexFunction(nlhs, plhs, nrhs, prhs);
    // Module termination.
    T3ElementShapeFun_V2_terminate();
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

// End of code generation (_coder_T3ElementShapeFun_V2_mex.cpp)
