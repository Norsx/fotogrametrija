//
// T3ElementShapeFun_V2_initialize.cpp
//
// Code generation for function 'T3ElementShapeFun_V2_initialize'
//

// Include files
#include "T3ElementShapeFun_V2_initialize.h"
#include "T3ElementShapeFun_V2_data.h"
#include "_coder_T3ElementShapeFun_V2_mex.h"
#include "rt_nonfinite.h"

// Function Declarations
static void T3ElementShapeFun_V2_once();

// Function Definitions
static void T3ElementShapeFun_V2_once()
{
  mex_InitInfAndNan();
}

void T3ElementShapeFun_V2_initialize()
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
    T3ElementShapeFun_V2_once();
  }
}

// End of code generation (T3ElementShapeFun_V2_initialize.cpp)
