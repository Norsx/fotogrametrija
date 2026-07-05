//
// _coder_CalcT3MeshShapeFun_info.cpp
//
// Code generation for function 'CalcT3MeshShapeFun'
//

// Include files
#include "_coder_CalcT3MeshShapeFun_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

// Function Declarations
static const mxArray *c_emlrtMexFcnResolvedFunctionsI();

// Function Definitions
static const mxArray *c_emlrtMexFcnResolvedFunctionsI()
{
  const mxArray *nameCaptureInfo;
  const char_T *data[5]{
      "789ced56cb4edb40141d23a858d09245dbb5775d1151bc81eedabc84aa90425c40c2888e"
      "ed0b76329e313393f058a1fe40bf805d3fa55fc0960d8b2eaa7e0531"
      "cee461c572a42057a0decdf59933e373eeb57d65a46dd63584d02b14c79fa538bfece342"
      "3fcfa1f148f25a629f36be1d2da0f9b1738affd1cf0ea312ce650c28",
      "0e6070d265814f3195e64508888360a40bee0373ec1330fd009aa3602b424175841a8088"
      "8aae4b1e38ed662740dc13438764140cfa719752effc94fdb84ae947"
      "21c11f540e4b1facaf02b8b03ebabd8aad068532f7bba0afe855dcee1009521792b316e6"
      "4276b1eeeb36672e3be1d8a52db0f6186f5b752c09b62dd3286f96ac",
      "6a873ad26754584d0f873084254c1cd3a883f014510c54bde733d6fb3aa35ec59b468540"
      "00542a0b47bb6bd1baf2f16d461f2f527dc48ccb3a368191f77e46bd"
      "efa97ae37c9ecf79528f8b41ec23abcfcb53d69dccc3fd8b0fd9aedf6a79eafd7d77fd3b"
      "4f3d15ff4a6fd6eff56d8a5e21c1136f95f2fd8dedcbb2dfe86e9dd6",
      "c2d53d293f0d7d7cc9d0c9f28152705ef7bf4b39ff7fce4fae77da391f79a8116663621a"
      "ca45b4fe583ede64f850bcc35ce045bff793c129264511f6ba0be879"
      "cfff49bdcf7bfee39ce7ffcde75f3ff3d453f1dce7ffcefe7a28256bd955b6f3fecc361b"
      "8e11e2cad39ffff724683012",
      ""};
  nameCaptureInfo = nullptr;
  emlrtNameCaptureMxArrayR2016a(&data[0], 3328U, &nameCaptureInfo);
  return nameCaptureInfo;
}

mxArray *emlrtMexFcnProperties()
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *propFieldName[9]{"Version",
                                 "ResolvedFunctions",
                                 "Checksum",
                                 "EntryPoints",
                                 "CoverageInfo",
                                 "IsPolymorphic",
                                 "PropertyList",
                                 "UUID",
                                 "ClassEntryPointIsHandle"};
  const char_T *epFieldName[8]{
      "Name",     "NumberOfInputs", "NumberOfOutputs", "ConstantInputs",
      "FullPath", "TimeStamp",      "Constructor",     "Visible"};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 8, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 7);
  emlrtSetField(xEntryPoints, 0, "Name",
                emlrtMxCreateString("CalcT3MeshShapeFun"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(7.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "FullPath",
      emlrtMxCreateString("C:\\Users\\Admin\\OneDrive - Fakultet strojarstva i "
                          "brodogradnje\\Work\\Matlab\\T3DIC\\Functions\\ShapeF"
                          "unctions\\CalcT3MeshShap"
                          "eFun.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739599.60887731484));
  emlrtSetField(xEntryPoints, 0, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 9, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("24.1.0.2537033 (R2024a)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("ujedvKxLekkGuTaT8S4e4D"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

// End of code generation (_coder_CalcT3MeshShapeFun_info.cpp)
