//
// bigProduct.cpp
//
// Code generation for function 'bigProduct'
//

// Include files
#include "bigProduct.h"
#include "rt_nonfinite.h"

// Function Definitions
namespace coder {
namespace internal {
int32_T bigProduct(int32_T a, int32_T &highorderbits)
{
  int32_T loworderbits;
  int32_T partialResults_idx_0_tmp;
  int32_T partialResults_idx_2;
  int32_T tmp;
  loworderbits = 0;
  partialResults_idx_0_tmp = (a & 65535) * 6;
  tmp = (a >> 16) * 6;
  partialResults_idx_2 = tmp << 16;
  highorderbits = tmp >> 16;
  if (highorderbits <= 0) {
    highorderbits = 0;
    if (partialResults_idx_0_tmp > MAX_int32_T - partialResults_idx_2) {
      loworderbits =
          (partialResults_idx_0_tmp + partialResults_idx_2) - MAX_int32_T;
      highorderbits = 1;
    } else {
      loworderbits = partialResults_idx_0_tmp + partialResults_idx_2;
    }
  }
  return loworderbits;
}

} // namespace internal
} // namespace coder

// End of code generation (bigProduct.cpp)
