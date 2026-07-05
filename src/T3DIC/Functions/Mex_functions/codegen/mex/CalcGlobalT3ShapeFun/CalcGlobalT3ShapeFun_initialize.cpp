//
// CalcGlobalT3ShapeFun_initialize.cpp
//
// Code generation for function 'CalcGlobalT3ShapeFun_initialize'
//

// Include files
#include "CalcGlobalT3ShapeFun_initialize.h"
#include "CalcGlobalT3ShapeFun_data.h"
#include "_coder_CalcGlobalT3ShapeFun_mex.h"
#include "rt_nonfinite.h"

// Function Declarations
static void CalcGlobalT3ShapeFun_once();

// Function Definitions
static void CalcGlobalT3ShapeFun_once()
{
  mex_InitInfAndNan();
}

void CalcGlobalT3ShapeFun_initialize()
{
  static const volatile char_T *emlrtBreakCheckR2012bFlagVar{nullptr};
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2022b(&st);
  emlrtClearAllocCountR2012b(&st, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    CalcGlobalT3ShapeFun_once();
  }
}

// End of code generation (CalcGlobalT3ShapeFun_initialize.cpp)
