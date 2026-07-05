//
// T3ElementShapeFun_V2_internal_types.h
//
// Code generation for function 'T3ElementShapeFun_V2'
//

#pragma once

// Include files
#include "T3ElementShapeFun_V2_types.h"
#include "rtwtypes.h"
#include "emlrt.h"

// Type Definitions
struct rtDesignRangeCheckInfo {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
};

struct rtDoubleCheckInfo {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
  int32_T checkKind;
};

struct rtRunTimeErrorInfo {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
};

// End of code generation (T3ElementShapeFun_V2_internal_types.h)
