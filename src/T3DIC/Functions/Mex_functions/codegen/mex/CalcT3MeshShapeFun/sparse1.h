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
namespace coder {
class c_sparse;

class b_sparse;

} // namespace coder
struct struct_T;

// Type Definitions
namespace coder {
class sparse {
public:
  static void assertValidSize(const emlrtStack &sp, real_T s);
  static int32_T countNumnzInColumn(const emlrtStack &sp,
                                    const array<real_T, 2U> &rhs,
                                    int32_T rhsIter_idx, int32_T sm);
  void parenReference(const emlrtStack &sp, const array<real_T, 1U> &varargin_1,
                      const real_T varargin_2[3], c_sparse &s) const;
  static void spallocLike(const emlrtStack &sp, int32_T b_m, int32_T nzmax,
                          c_sparse &s);
  static void b_realloc(const emlrtStack &sp, b_sparse *b_this,
                        int32_T numAllocRequested, int32_T ub1, int32_T lb2,
                        int32_T ub2, int32_T offs);
  static int32_T copyNonzeroValues(const emlrtStack &sp, b_sparse *b_this,
                                   struct_T &rhsIter, int32_T outStart,
                                   const array<real_T, 2U> &rhs);
  static void sparseSparseRowExpandBinOp(const emlrtStack &sp,
                                         const c_sparse &rowA,
                                         const c_sparse *b, c_sparse &s);
  void parenAssign(const emlrtStack &sp, const c_sparse &rhs,
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
  void parenReference(const emlrtStack &sp, c_sparse &s) const;
  void parenAssign(const emlrtStack &sp, const array<real_T, 2U> &rhs);
  void b_parenAssign(const emlrtStack &sp, const array<real_T, 2U> &rhs);
  array<real_T, 1U> d;
  array<int32_T, 1U> colidx;
  array<int32_T, 1U> rowidx;
  int32_T m;
  int32_T maxnz;
};

class c_sparse {
public:
  void plus(const emlrtStack &sp, const c_sparse &b, c_sparse &s) const;
  array<real_T, 1U> d;
  array<int32_T, 1U> colidx;
  array<int32_T, 1U> rowidx;
  int32_T m;
};

} // namespace coder

// End of code generation (sparse1.h)
