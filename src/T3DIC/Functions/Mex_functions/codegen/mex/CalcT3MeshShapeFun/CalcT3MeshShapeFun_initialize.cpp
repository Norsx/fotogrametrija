//
// CalcT3MeshShapeFun_initialize.cpp
//
// Code generation for function 'CalcT3MeshShapeFun_initialize'
//

// Include files
#include "CalcT3MeshShapeFun_initialize.h"
#include "CalcT3MeshShapeFun_data.h"
#include "_coder_CalcT3MeshShapeFun_mex.h"
#include "rt_nonfinite.h"

// Function Declarations
static void CalcT3MeshShapeFun_once();

// Function Definitions
static void CalcT3MeshShapeFun_once()
{
  mex_InitInfAndNan();
}

void CalcT3MeshShapeFun_initialize()
{
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
    CalcT3MeshShapeFun_once();
  }
}

// End of code generation (CalcT3MeshShapeFun_initialize.cpp)
