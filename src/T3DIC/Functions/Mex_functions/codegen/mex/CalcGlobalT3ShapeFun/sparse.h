//
// sparse.h
//
// Code generation for function 'sparse'
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
namespace coder {
class b_sparse;

}

// Type Definitions
namespace coder {
class sparse {
public:
  void parenReference(const emlrtStack &sp, const array<real_T, 1U> &varargin_1,
                      const real_T varargin_2[3], b_sparse &s) const;
  static void spallocLike(const emlrtStack &sp, int32_T b_m, int32_T nzmax,
                          b_sparse &s);
  static void sparseSparseRowExpandBinOp(const emlrtStack &sp,
                                         const b_sparse &rowA,
                                         const b_sparse *b, b_sparse &s);
  void parenAssign(const emlrtStack &sp, const b_sparse &rhs,
                   const array<real_T, 1U> &varargin_1,
                   const real_T varargin_2[3]);

private:
  static void b_realloc(const emlrtStack &sp, sparse *b_this,
                        int32_T numAllocRequested, int32_T ub1, int32_T lb2,
                        int32_T ub2, int32_T offs);

public:
  array<real_T, 1U> d;
  array<int32_T, 1U> colidx;
  array<int32_T, 1U> rowidx;
  int32_T m;
  int32_T n;
  int32_T maxnz;
};

class b_sparse {
public:
  void plus(const emlrtStack &sp, const b_sparse &b, b_sparse &s) const;
  array<real_T, 1U> d;
  array<int32_T, 1U> colidx;
  array<int32_T, 1U> rowidx;
  int32_T m;
};

} // namespace coder

// End of code generation (sparse.h)
