//
// sparse1.h
//
// Code generation for function 'sparse1'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Declarations
struct struct_T;

// Type Definitions
namespace coder {
class sparse {
public:
  void parenAssign(const emlrtStack &sp, const array<real_T, 2U> &rhs);
  void b_parenAssign(const emlrtStack &sp, const array<real_T, 2U> &rhs);

private:
  static int32_T countNumnzInColumn(const emlrtStack &sp,
                                    const array<real_T, 2U> &rhs,
                                    int32_T rhsIter_idx, int32_T sm);
  static void b_realloc(const emlrtStack &sp, sparse *b_this,
                        int32_T numAllocRequested, int32_T ub1, int32_T lb2,
                        int32_T ub2, int32_T offs);
  static int32_T copyNonzeroValues(const emlrtStack &sp, sparse *b_this,
                                   struct_T &rhsIter, int32_T outStart,
                                   const array<real_T, 2U> &rhs);

public:
  array<real_T, 1U> d;
  array<int32_T, 1U> colidx;
  array<int32_T, 1U> rowidx;
  int32_T m;
  int32_T maxnz;
};

} // namespace coder

// End of code generation (sparse1.h)
