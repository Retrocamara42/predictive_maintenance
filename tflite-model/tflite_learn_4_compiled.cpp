/*
 * Copyright (c) 2024 EdgeImpulse Inc.
 *
 * Generated by Edge Impulse and licensed under the applicable Edge Impulse
 * Terms of Service. Community and Professional Terms of Service
 * (https://docs.edgeimpulse.com/page/terms-of-service) or Enterprise Terms of
 * Service (https://docs.edgeimpulse.com/page/enterprise-terms-of-service),
 * according to your product plan subscription (the “License”).
 *
 * This software, documentation and other associated files (collectively referred
 * to as the “Software”) is a single SDK variation generated by the Edge Impulse
 * platform and requires an active paid Edge Impulse subscription to use this
 * Software for any purpose.
 *
 * You may NOT use this Software unless you have an active Edge Impulse subscription
 * that meets the eligibility requirements for the applicable License, subject to
 * your full and continued compliance with the terms and conditions of the License,
 * including without limitation any usage restrictions under the applicable License.
 *
 * If you do not have an active Edge Impulse product plan subscription, or if use
 * of this Software exceeds the usage limitations of your Edge Impulse product plan
 * subscription, you are not permitted to use this Software and must immediately
 * delete and erase all copies of this Software within your control or possession.
 * Edge Impulse reserves all rights and remedies available to enforce its rights.
 *
 * Unless required by applicable law or agreed to in writing, the Software is
 * distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific language governing
 * permissions, disclaimers and limitations under the License.
 */
// Generated on: 27.09.2024 11:57:42

#include <stdio.h>
#include <stdlib.h>
#include "edge-impulse-sdk/tensorflow/lite/c/builtin_op_data.h"
#include "edge-impulse-sdk/tensorflow/lite/c/common.h"
#include "edge-impulse-sdk/tensorflow/lite/micro/micro_mutable_op_resolver.h"
#include "edge-impulse-sdk/porting/ei_classifier_porting.h"

#if EI_CLASSIFIER_PRINT_STATE
#if defined(__cplusplus) && EI_C_LINKAGE == 1
extern "C" {
    extern void ei_printf(const char *format, ...);
}
#else
extern void ei_printf(const char *format, ...);
#endif
#endif

#if defined (__GNUC__)  /* GNU compiler */
#define ALIGN(X) __attribute__((aligned(X)))
#define DEFINE_SECTION(x) __attribute__((section(x)))
#elif defined (_MSC_VER)
#define ALIGN(X) __declspec(align(X))
#elif defined (__TASKING__) /* TASKING Compiler */
#define ALIGN(X) __align(X)
#define DEFINE_SECTION(x) __attribute__(section(x)))
#elif defined (__ARMCC_VERSION) /* Arm Compiler */
#define ALIGN(X) __ALIGNED(x)
#define DEFINE_SECTION(x) __attribute__((section(x)))
#elif defined (__ICCARM__) /* IAR Compiler */
#define ALIGN(x) __attribute__((aligned(x)))
#define DEFINE_SECTION(x) __attribute__((section(x)))
#elif defined (__clang__) /* LLVM/Clang Compiler */
#define ALIGN(X) __ALIGNED(x)
#define DEFINE_SECTION(x) __attribute__((section(x)))
#endif

#ifndef EI_MAX_SCRATCH_BUFFER_COUNT
#ifndef CONFIG_IDF_TARGET_ESP32S3
#define EI_MAX_SCRATCH_BUFFER_COUNT 4
#else
#define EI_MAX_SCRATCH_BUFFER_COUNT 4
#endif // CONFIG_IDF_TARGET_ESP32S3
#endif // EI_MAX_SCRATCH_BUFFER_COUNT

#ifndef EI_MAX_OVERFLOW_BUFFER_COUNT
#define EI_MAX_OVERFLOW_BUFFER_COUNT 10
#endif // EI_MAX_OVERFLOW_BUFFER_COUNT

using namespace tflite;
using namespace tflite::ops;
using namespace tflite::ops::micro;

namespace {

#if defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX) || defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX_GNU)
constexpr int kTensorArenaSize = 2880;
#else
constexpr int kTensorArenaSize = 1856;
#endif

#if defined(EI_CLASSIFIER_ALLOCATION_STATIC)
#if defined (EI_TENSOR_ARENA_LOCATION)
#define STRINGIZE(x) #x
#define STRINGIZE_VALUE_OF(x) STRINGIZE(x)
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16) DEFINE_SECTION(STRINGIZE_VALUE_OF(EI_TENSOR_ARENA_LOCATION));
#else
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#endif
#elif defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX)
#pragma Bss(".tensor_arena")
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16);
#pragma Bss()
#elif defined(EI_CLASSIFIER_ALLOCATION_STATIC_HIMAX_GNU)
uint8_t tensor_arena[kTensorArenaSize] ALIGN(16) __attribute__((section(".tensor_arena")));
#else
#define EI_CLASSIFIER_ALLOCATION_HEAP 1
uint8_t* tensor_arena = NULL;
#endif

static uint8_t* tensor_boundary;
static uint8_t* current_location;

template <int SZ, class T> struct TfArray {
  int sz; T elem[SZ];
};

enum used_operators_e {
  OP_RESHAPE, OP_CONV_2D, OP_MAX_POOL_2D, OP_FULLY_CONNECTED, OP_SOFTMAX,  OP_LAST
};

struct TensorInfo_t { // subset of TfLiteTensor used for initialization from constant memory
  TfLiteAllocationType allocation_type;
  TfLiteType type;
  void* data;
  TfLiteIntArray* dims;
  size_t bytes;
  TfLiteQuantization quantization;
};

typedef struct {
  TfLiteTensor tensor;
  int16_t index;
} TfLiteTensorWithIndex;

typedef struct {
  TfLiteEvalTensor tensor;
  int16_t index;
} TfLiteEvalTensorWithIndex;

TfLiteContext ctx{};
static const int MAX_TFL_TENSOR_COUNT = 4;
static TfLiteTensorWithIndex tflTensors[MAX_TFL_TENSOR_COUNT];
static const int MAX_TFL_EVAL_COUNT = 4;
static TfLiteEvalTensorWithIndex tflEvalTensors[MAX_TFL_EVAL_COUNT];
TfLiteRegistration registrations[OP_LAST];

namespace g0 {
const TfArray<2, int> tensor_dimension0 = { 2, { 1,663 } };
const TfArray<1, float> quant0_scale = { 1, { 0.046091686934232712, } };
const TfArray<1, int> quant0_zero = { 1, { 21 } };
const TfLiteAffineQuantization quant0 = { (TfLiteFloatArray*)&quant0_scale, (TfLiteIntArray*)&quant0_zero, 0 };
const ALIGN(16) int32_t tensor_data1[4] = { 1, 1, 51, 13, };
const TfArray<1, int> tensor_dimension1 = { 1, { 4 } };
const ALIGN(16) int32_t tensor_data2[4] = { 1, 51, 1, 8, };
const TfArray<1, int> tensor_dimension2 = { 1, { 4 } };
const ALIGN(8) int32_t tensor_data3[2] = { -1, 208, };
const TfArray<1, int> tensor_dimension3 = { 1, { 2 } };
const ALIGN(8) int32_t tensor_data4[2] = { -259, 259, };
const TfArray<1, int> tensor_dimension4 = { 1, { 2 } };
const TfArray<1, float> quant4_scale = { 1, { 0.00011124557931907475, } };
const TfArray<1, int> quant4_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant4 = { (TfLiteFloatArray*)&quant4_scale, (TfLiteIntArray*)&quant4_zero, 0 };
const ALIGN(16) int8_t tensor_data5[2*208] = { 
  57, 51, -60, -20, -29, -127, 11, 88, 89, 25, 5, -42, -47, -50, 65, 73, 64, 11, -31, -32, 6, -84, 41, 73, 76, 22, -25, -30, -16, -42, 47, 26, 34, 40, -68, -78, -33, -58, 13, 53, -15, -14, -103, -38, -69, -57, 72, 63, 24, -11, -70, -38, -32, -75, 40, 43, 59, 55, -17, -53, -52, -52, 14, 21, 20, 56, -76, 9, -61, -80, 69, 68, 31, 37, -61, -50, -87, -88, 67, 69, 34, 23, -53, -53, -73, -25, 24, 91, 45, 71, -102, -22, -25, -87, 54, 45, 27, 69, -38, -26, -3, -55, 9, 35, 68, -10, 0, -26, -68, -96, 52, 33, 42, 25, -62, -64, -79, -78, 23, 81, 58, 55, -90, -15, -35, -50, 63, 38, 73, 3, -36, -70, -78, -58, 63, 76, 65, 54, -24, -47, -93, -72, 64, -25, 58, 30, -26, -95, -74, -113, 52, 94, 31, 1, -71, -48, -7, -64, 91, 81, 27, 12, -54, -41, -52, -81, 84, 54, 65, 22, -15, -74, -37, -49, 2, -2, 59, 76, -45, -69, -54, -94, 5, 39, 17, 45, -36, -39, -45, -67, 85, 12, 57, 50, -54, -75, -40, -85, 3, 65, 56, 62, -32, -64, -23, -39, 38, 33, 
  -63, -37, 8, 49, 70, 53, -43, -38, -36, -37, -5, 77, -17, 45, -50, -42, -22, -8, 24, 47, 54, 39, -85, -46, -11, -31, 32, 12, 80, 94, -23, -63, -51, -1, 18, 0, 23, 98, -69, -59, -23, -13, 22, 72, 87, 44, -48, -58, -35, -21, 58, 89, 97, 77, -26, -56, -21, -9, 77, 80, 101, 15, -42, -23, -50, -3, 6, 35, 34, 18, -21, -74, -31, -72, 69, 53, 42, 25, -55, -39, -53, 0, 20, 109, 33, 28, -83, -28, -49, -9, 57, 24, 27, 86, -72, -48, -26, -45, 57, 43, 39, 79, -92, -35, -16, -50, 60, 56, 79, 14, -64, -63, 16, -50, 37, 94, 21, 44, -85, -53, -58, 1, 68, 67, 93, 78, -112, -53, -22, -66, 32, 61, 65, 22, -59, -66, -36, -33, 98, 5, 44, 64, -33, -54, -35, -26, 78, 39, 87, 60, 17, -61, -59, -43, 70, 71, 71, 115, -83, -66, -88, -5, 19, 74, 46, 13, -33, -89, -114, -30, 62, 97, 79, 29, -79, -43, -32, -16, 1, 77, 25, 47, -59, -28, -10, -25, 74, 18, 76, 96, -35, -30, -48, 24, 5, 50, 44, 127, -52, -4, -16, -58, 46, 92, 21, 84, -63, -72, 
};
const TfArray<2, int> tensor_dimension5 = { 2, { 2,208 } };
const TfArray<1, float> quant5_scale = { 1, { 0.0037329541519284248, } };
const TfArray<1, int> quant5_zero = { 1, { 0 } };
const TfLiteAffineQuantization quant5 = { (TfLiteFloatArray*)&quant5_scale, (TfLiteIntArray*)&quant5_zero, 0 };
const ALIGN(16) int32_t tensor_data6[8] = { -2420, -1853, -1485, -2093, -2273, -1769, -2066, -2538, };
const TfArray<1, int> tensor_dimension6 = { 1, { 8 } };
const TfArray<8, float> quant6_scale = { 8, { 0.00021497346460819244, 0.0002112727815983817, 0.00033201967016793787, 0.00024748180294409394, 0.00030860261176712811, 0.00036439453833736479, 0.000286571477772668, 0.00024006188323255628, } };
const TfArray<8, int> quant6_zero = { 8, { 0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant6 = { (TfLiteFloatArray*)&quant6_scale, (TfLiteIntArray*)&quant6_zero, 0 };
const ALIGN(16) int8_t tensor_data7[8*1*3*13] = { 
  /* [0][0][][] */ 29,84,36,58,28,4,-6,-41,-41,-68,-20,-54,38, -10,-127,-51,-14,-24,-22,-18,31,47,62,66,45,-37, -2,-118,-22,-36,-25,-23,7,49,77,63,27,26,-16, 
  /* [1][0][][] */ -30,-22,-7,11,19,42,-78,44,27,29,10,22,28, -21,90,47,-4,32,63,-25,-23,-30,-111,-45,-35,28, -25,-104,-63,-28,-28,-45,28,31,20,127,78,-2,-76, 
  /* [2][0][][] */ -15,127,14,-11,-69,-72,-21,-5,22,51,29,31,0, -16,18,66,42,-108,-14,-19,15,36,6,20,23,-15, 23,-43,16,-37,39,48,-35,15,0,-28,14,-17,-3, 
  /* [3][0][][] */ -2,-64,3,-56,110,33,-16,-3,-6,-40,2,-28,-5, 10,127,60,28,-77,-77,-60,17,75,58,91,56,-2, -23,-101,19,23,17,47,21,-10,-1,-11,-21,2,-5, 
  /* [4][0][][] */ 19,-67,-5,8,47,39,-18,14,-18,-7,-11,-19,23, -26,12,40,-10,-17,-25,-2,19,-11,16,-1,11,-7, 33,127,91,-47,-93,-56,-77,28,74,36,53,44,-12, 
  /* [5][0][][] */ 5,71,21,14,-43,-38,-14,16,24,50,17,40,4, 6,-12,3,-29,16,6,13,-16,5,-13,7,-6,21, -38,-79,-82,127,-24,22,82,-38,-29,-1,-44,-1,27, 
  /* [6][0][][] */ 22,127,48,58,24,7,6,-45,-77,-80,-71,-52,6, -16,-15,2,1,-8,4,6,-23,26,4,13,-16,3, 10,14,8,-5,16,-3,0,-42,-31,-11,-7,-2,-5, 
  /* [7][0][][] */ 16,10,-24,35,-10,-3,-6,51,-2,-26,42,-17,-9, -35,-1,5,-20,27,-17,-8,-2,32,-35,-2,51,-38, 26,127,93,67,45,19,2,-41,-83,-96,-79,-69,24, 
};
const TfArray<4, int> tensor_dimension7 = { 4, { 8,1,3,13 } };
const TfArray<8, float> quant7_scale = { 8, { 0.0046640397049486637, 0.0045837503857910633, 0.0072034611366689205, 0.0053693372756242752, 0.0066954069770872593, 0.0079058622941374779, 0.0062174219638109207, 0.0052083553746342659, } };
const TfArray<8, int> quant7_zero = { 8, { 0,0,0,0,0,0,0,0 } };
const TfLiteAffineQuantization quant7 = { (TfLiteFloatArray*)&quant7_scale, (TfLiteIntArray*)&quant7_zero, 0 };
const TfArray<4, int> tensor_dimension8 = { 4, { 1,1,51,13 } };
const TfArray<1, float> quant8_scale = { 1, { 0.046091686934232712, } };
const TfArray<1, int> quant8_zero = { 1, { 21 } };
const TfLiteAffineQuantization quant8 = { (TfLiteFloatArray*)&quant8_scale, (TfLiteIntArray*)&quant8_zero, 0 };
const TfArray<4, int> tensor_dimension9 = { 4, { 1,1,51,8 } };
const TfArray<1, float> quant9_scale = { 1, { 0.029800949618220329, } };
const TfArray<1, int> quant9_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant9 = { (TfLiteFloatArray*)&quant9_scale, (TfLiteIntArray*)&quant9_zero, 0 };
const TfArray<4, int> tensor_dimension10 = { 4, { 1,51,1,8 } };
const TfArray<1, float> quant10_scale = { 1, { 0.029800949618220329, } };
const TfArray<1, int> quant10_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant10 = { (TfLiteFloatArray*)&quant10_scale, (TfLiteIntArray*)&quant10_zero, 0 };
const TfArray<4, int> tensor_dimension11 = { 4, { 1,26,1,8 } };
const TfArray<1, float> quant11_scale = { 1, { 0.029800949618220329, } };
const TfArray<1, int> quant11_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant11 = { (TfLiteFloatArray*)&quant11_scale, (TfLiteIntArray*)&quant11_zero, 0 };
const TfArray<2, int> tensor_dimension12 = { 2, { 1,208 } };
const TfArray<1, float> quant12_scale = { 1, { 0.029800949618220329, } };
const TfArray<1, int> quant12_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant12 = { (TfLiteFloatArray*)&quant12_scale, (TfLiteIntArray*)&quant12_zero, 0 };
const TfArray<2, int> tensor_dimension13 = { 2, { 1,2 } };
const TfArray<1, float> quant13_scale = { 1, { 0.10131467878818512, } };
const TfArray<1, int> quant13_zero = { 1, { -4 } };
const TfLiteAffineQuantization quant13 = { (TfLiteFloatArray*)&quant13_scale, (TfLiteIntArray*)&quant13_zero, 0 };
const TfArray<2, int> tensor_dimension14 = { 2, { 1,2 } };
const TfArray<1, float> quant14_scale = { 1, { 0.00390625, } };
const TfArray<1, int> quant14_zero = { 1, { -128 } };
const TfLiteAffineQuantization quant14 = { (TfLiteFloatArray*)&quant14_scale, (TfLiteIntArray*)&quant14_zero, 0 };
const TfLiteReshapeParams opdata0 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs0 = { 2, { 0,1 } };
const TfArray<1, int> outputs0 = { 1, { 8 } };
const TfLiteConvParams opdata1 = { kTfLitePaddingSame, 1,1, kTfLiteActRelu, 1,1 };
const TfArray<3, int> inputs1 = { 3, { 8,7,6 } };
const TfArray<1, int> outputs1 = { 1, { 9 } };
const TfLiteReshapeParams opdata2 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs2 = { 2, { 9,2 } };
const TfArray<1, int> outputs2 = { 1, { 10 } };
const TfLitePoolParams opdata3 = { kTfLitePaddingSame, 1,2, 1,2, kTfLiteActNone, { { 0,0, 0, 0 } } };
const TfArray<1, int> inputs3 = { 1, { 10 } };
const TfArray<1, int> outputs3 = { 1, { 11 } };
const TfLiteReshapeParams opdata4 = { { 0, 0, 0, 0, 0, 0, 0, 0, }, 0 };
const TfArray<2, int> inputs4 = { 2, { 11,3 } };
const TfArray<1, int> outputs4 = { 1, { 12 } };
const TfLiteFullyConnectedParams opdata5 = { kTfLiteActNone, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> inputs5 = { 3, { 12,5,4 } };
const TfArray<1, int> outputs5 = { 1, { 13 } };
const TfLiteSoftmaxParams opdata6 = { 1 };
const TfArray<1, int> inputs6 = { 1, { 13 } };
const TfArray<1, int> outputs6 = { 1, { 14 } };
};

TensorInfo_t tensorData[] = {
{ kTfLiteArenaRw, kTfLiteInt8, (int32_t*)(tensor_arena + 672), (TfLiteIntArray*)&g0::tensor_dimension0, 663, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&g0::quant0))}, },
{ kTfLiteMmapRo, kTfLiteInt32, (int32_t*)g0::tensor_data1, (TfLiteIntArray*)&g0::tensor_dimension1, 16, {kTfLiteNoQuantization, nullptr}, },
{ kTfLiteMmapRo, kTfLiteInt32, (int32_t*)g0::tensor_data2, (TfLiteIntArray*)&g0::tensor_dimension2, 16, {kTfLiteNoQuantization, nullptr}, },
{ kTfLiteMmapRo, kTfLiteInt32, (int32_t*)g0::tensor_data3, (TfLiteIntArray*)&g0::tensor_dimension3, 8, {kTfLiteNoQuantization, nullptr}, },
{ kTfLiteMmapRo, kTfLiteInt32, (int32_t*)g0::tensor_data4, (TfLiteIntArray*)&g0::tensor_dimension4, 8, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&g0::quant4))}, },
{ kTfLiteMmapRo, kTfLiteInt8, (int32_t*)g0::tensor_data5, (TfLiteIntArray*)&g0::tensor_dimension5, 416, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&g0::quant5))}, },
{ kTfLiteMmapRo, kTfLiteInt32, (int32_t*)g0::tensor_data6, (TfLiteIntArray*)&g0::tensor_dimension6, 32, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&g0::quant6))}, },
{ kTfLiteMmapRo, kTfLiteInt8, (int32_t*)g0::tensor_data7, (TfLiteIntArray*)&g0::tensor_dimension7, 312, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&g0::quant7))}, },
{ kTfLiteArenaRw, kTfLiteInt8, (int32_t*)(tensor_arena + 0), (TfLiteIntArray*)&g0::tensor_dimension8, 663, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&g0::quant8))}, },
{ kTfLiteArenaRw, kTfLiteInt8, (int32_t*)(tensor_arena + 672), (TfLiteIntArray*)&g0::tensor_dimension9, 408, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&g0::quant9))}, },
{ kTfLiteArenaRw, kTfLiteInt8, (int32_t*)(tensor_arena + 0), (TfLiteIntArray*)&g0::tensor_dimension10, 408, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&g0::quant10))}, },
{ kTfLiteArenaRw, kTfLiteInt8, (int32_t*)(tensor_arena + 416), (TfLiteIntArray*)&g0::tensor_dimension11, 208, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&g0::quant11))}, },
{ kTfLiteArenaRw, kTfLiteInt8, (int32_t*)(tensor_arena + 0), (TfLiteIntArray*)&g0::tensor_dimension12, 208, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&g0::quant12))}, },
{ kTfLiteArenaRw, kTfLiteInt8, (int32_t*)(tensor_arena + 208), (TfLiteIntArray*)&g0::tensor_dimension13, 2, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&g0::quant13))}, },
{ kTfLiteArenaRw, kTfLiteInt8, (int32_t*)(tensor_arena + 0), (TfLiteIntArray*)&g0::tensor_dimension14, 2, {kTfLiteAffineQuantization, const_cast<void*>(static_cast<const void*>(&g0::quant14))}, },
};

#ifndef TF_LITE_STATIC_MEMORY
TfLiteNode tflNodes[7] = {
{ (TfLiteIntArray*)&g0::inputs0, (TfLiteIntArray*)&g0::outputs0, (TfLiteIntArray*)&g0::inputs0, nullptr, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata0)), nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs1, (TfLiteIntArray*)&g0::outputs1, (TfLiteIntArray*)&g0::inputs1, nullptr, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata1)), nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs2, (TfLiteIntArray*)&g0::outputs2, (TfLiteIntArray*)&g0::inputs2, nullptr, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata2)), nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs3, (TfLiteIntArray*)&g0::outputs3, (TfLiteIntArray*)&g0::inputs3, nullptr, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata3)), nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs4, (TfLiteIntArray*)&g0::outputs4, (TfLiteIntArray*)&g0::inputs4, nullptr, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata4)), nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs5, (TfLiteIntArray*)&g0::outputs5, (TfLiteIntArray*)&g0::inputs5, nullptr, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata5)), nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs6, (TfLiteIntArray*)&g0::outputs6, (TfLiteIntArray*)&g0::inputs6, nullptr, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata6)), nullptr, 0, },
};
#else
TfLiteNode tflNodes[7] = {
{ (TfLiteIntArray*)&g0::inputs0, (TfLiteIntArray*)&g0::outputs0, (TfLiteIntArray*)&g0::inputs0, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata0)), nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs1, (TfLiteIntArray*)&g0::outputs1, (TfLiteIntArray*)&g0::inputs1, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata1)), nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs2, (TfLiteIntArray*)&g0::outputs2, (TfLiteIntArray*)&g0::inputs2, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata2)), nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs3, (TfLiteIntArray*)&g0::outputs3, (TfLiteIntArray*)&g0::inputs3, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata3)), nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs4, (TfLiteIntArray*)&g0::outputs4, (TfLiteIntArray*)&g0::inputs4, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata4)), nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs5, (TfLiteIntArray*)&g0::outputs5, (TfLiteIntArray*)&g0::inputs5, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata5)), nullptr, 0, },
{ (TfLiteIntArray*)&g0::inputs6, (TfLiteIntArray*)&g0::outputs6, (TfLiteIntArray*)&g0::inputs6, nullptr, const_cast<void*>(static_cast<const void*>(&g0::opdata6)), nullptr, 0, },
};
#endif

used_operators_e used_ops[] =
{OP_RESHAPE, OP_CONV_2D, OP_RESHAPE, OP_MAX_POOL_2D, OP_RESHAPE, OP_FULLY_CONNECTED, OP_SOFTMAX, };


// Indices into tflTensors and tflNodes for subgraphs
const size_t tflTensors_subgraph_index[] = {0, 15, };
const size_t tflNodes_subgraph_index[] = {0, 7, };

// Input/output tensors
static const int in_tensor_indices[] = {
  0, 
};

static const int out_tensor_indices[] = {
  14, 
};


size_t current_subgraph_index = 0;

static void init_tflite_tensor(size_t i, TfLiteTensor *tensor) {
  tensor->type = tensorData[i].type;
  tensor->is_variable = false;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
  tensor->allocation_type = tensorData[i].allocation_type;
#else
  tensor->allocation_type = (tensor_arena <= tensorData[i].data && tensorData[i].data < tensor_arena + kTensorArenaSize) ? kTfLiteArenaRw : kTfLiteMmapRo;
#endif
  tensor->bytes = tensorData[i].bytes;
  tensor->dims = tensorData[i].dims;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
  if(tensor->allocation_type == kTfLiteArenaRw){
    uint8_t* start = (uint8_t*) ((uintptr_t)tensorData[i].data + (uintptr_t) tensor_arena);

    tensor->data.data =  start;
  }
  else {
      tensor->data.data = tensorData[i].data;
  }
#else
  tensor->data.data = tensorData[i].data;
#endif // EI_CLASSIFIER_ALLOCATION_HEAP
  tensor->quantization = tensorData[i].quantization;
  if (tensor->quantization.type == kTfLiteAffineQuantization) {
    TfLiteAffineQuantization const* quant = ((TfLiteAffineQuantization const*)(tensorData[i].quantization.params));
    tensor->params.scale = quant->scale->data[0];
    tensor->params.zero_point = quant->zero_point->data[0];
  }

}

static void init_tflite_eval_tensor(int i, TfLiteEvalTensor *tensor) {

  tensor->type = tensorData[i].type;

  tensor->dims = tensorData[i].dims;

#if defined(EI_CLASSIFIER_ALLOCATION_HEAP)
  auto allocation_type = tensorData[i].allocation_type;
  if(allocation_type == kTfLiteArenaRw) {
    uint8_t* start = (uint8_t*) ((uintptr_t)tensorData[i].data + (uintptr_t) tensor_arena);

    tensor->data.data =  start;
  }
  else {
    tensor->data.data = tensorData[i].data;
  }
#else
  tensor->data.data = tensorData[i].data;
#endif // EI_CLASSIFIER_ALLOCATION_HEAP
}

static void* overflow_buffers[EI_MAX_OVERFLOW_BUFFER_COUNT];
static size_t overflow_buffers_ix = 0;
static void * AllocatePersistentBufferImpl(struct TfLiteContext* ctx,
                                       size_t bytes) {
  void *ptr;
  uint32_t align_bytes = (bytes % 16) ? 16 - (bytes % 16) : 0;

  if (current_location - (bytes + align_bytes) < tensor_boundary) {
    if (overflow_buffers_ix > EI_MAX_OVERFLOW_BUFFER_COUNT - 1) {
      ei_printf("ERR: Failed to allocate persistent buffer of size %d, does not fit in tensor arena and reached EI_MAX_OVERFLOW_BUFFER_COUNT\n",
        (int)bytes);
      return NULL;
    }

    // OK, this will look super weird, but.... we have CMSIS-NN buffers which
    // we cannot calculate beforehand easily.
    ptr = ei_calloc(bytes, 1);
    if (ptr == NULL) {
      ei_printf("ERR: Failed to allocate persistent buffer of size %d\n", (int)bytes);
      return NULL;
    }
    overflow_buffers[overflow_buffers_ix++] = ptr;
    return ptr;
  }

  current_location -= bytes;

  // align to the left aligned boundary of 16 bytes
  current_location -= 15; // for alignment
  current_location += 16 - ((uintptr_t)(current_location) & 15);

  ptr = current_location;
  memset(ptr, 0, bytes);

  return ptr;
}

typedef struct {
  size_t bytes;
  void *ptr;
} scratch_buffer_t;

static scratch_buffer_t scratch_buffers[EI_MAX_SCRATCH_BUFFER_COUNT];
static size_t scratch_buffers_ix = 0;

static TfLiteStatus RequestScratchBufferInArenaImpl(struct TfLiteContext* ctx, size_t bytes,
                                                int* buffer_idx) {
  if (scratch_buffers_ix > EI_MAX_SCRATCH_BUFFER_COUNT - 1) {
    ei_printf("ERR: Failed to allocate scratch buffer of size %d, reached EI_MAX_SCRATCH_BUFFER_COUNT\n",
      (int)bytes);
    return kTfLiteError;
  }

  scratch_buffer_t b;
  b.bytes = bytes;

  b.ptr = AllocatePersistentBufferImpl(ctx, b.bytes);
  if (!b.ptr) {
    ei_printf("ERR: Failed to allocate scratch buffer of size %d\n",
      (int)bytes);
    return kTfLiteError;
  }

  scratch_buffers[scratch_buffers_ix] = b;
  *buffer_idx = scratch_buffers_ix;

  scratch_buffers_ix++;

  return kTfLiteOk;
}

static void* GetScratchBufferImpl(struct TfLiteContext* ctx, int buffer_idx) {
  if (buffer_idx > (int)scratch_buffers_ix) {
    return NULL;
  }
  return scratch_buffers[buffer_idx].ptr;
}

static const uint16_t TENSOR_IX_UNUSED = 0x7FFF;

static void ResetTensors() {
  for (size_t ix = 0; ix < MAX_TFL_TENSOR_COUNT; ix++) {
    tflTensors[ix].index = TENSOR_IX_UNUSED;
  }
  for (size_t ix = 0; ix < MAX_TFL_EVAL_COUNT; ix++) {
    tflEvalTensors[ix].index = TENSOR_IX_UNUSED;
  }
}

static TfLiteTensor* GetTensorImpl(const struct TfLiteContext* context,
                               int tensor_idx) {

  tensor_idx = tflTensors_subgraph_index[current_subgraph_index] + tensor_idx;

  for (size_t ix = 0; ix < MAX_TFL_TENSOR_COUNT; ix++) {
    // already used? OK!
    if (tflTensors[ix].index == tensor_idx) {
      return &tflTensors[ix].tensor;
    }
    // passed all the ones we've used, so end of the list?
    if (tflTensors[ix].index == TENSOR_IX_UNUSED) {
      // init the tensor
      init_tflite_tensor(tensor_idx, &tflTensors[ix].tensor);
      tflTensors[ix].index = tensor_idx;
      return &tflTensors[ix].tensor;
    }
  }

  ei_printf("ERR: GetTensor called beyond MAX_TFL_TENSOR_COUNT (%d)\n", MAX_TFL_TENSOR_COUNT);
  return nullptr;
}

static TfLiteEvalTensor* GetEvalTensorImpl(const struct TfLiteContext* context,
                                       int tensor_idx) {

  tensor_idx = tflTensors_subgraph_index[current_subgraph_index] + tensor_idx;

  for (size_t ix = 0; ix < MAX_TFL_EVAL_COUNT; ix++) {
    // already used? OK!
    if (tflEvalTensors[ix].index == tensor_idx) {
      return &tflEvalTensors[ix].tensor;
    }
    // passed all the ones we've used, so end of the list?
    if (tflEvalTensors[ix].index == TENSOR_IX_UNUSED) {
      // init the tensor
      init_tflite_eval_tensor(tensor_idx, &tflEvalTensors[ix].tensor);
      tflEvalTensors[ix].index = tensor_idx;
      return &tflEvalTensors[ix].tensor;
    }
  }

  ei_printf("ERR: GetTensor called beyond MAX_TFL_EVAL_COUNT (%d)\n", (int)MAX_TFL_EVAL_COUNT);
  return nullptr;
}

class EonMicroContext : public MicroContext {
 public:
 
  EonMicroContext(): MicroContext(nullptr, nullptr, nullptr) { }

  void* AllocatePersistentBuffer(size_t bytes) {
    return AllocatePersistentBufferImpl(nullptr, bytes);
  }

  TfLiteStatus RequestScratchBufferInArena(size_t bytes,
                                           int* buffer_index) {
  return RequestScratchBufferInArenaImpl(nullptr, bytes, buffer_index);
  }

  void* GetScratchBuffer(int buffer_index) {
    return GetScratchBufferImpl(nullptr, buffer_index);
  }
 
  TfLiteTensor* AllocateTempTfLiteTensor(int tensor_index) {
    return GetTensorImpl(nullptr, tensor_index);
  }

  void DeallocateTempTfLiteTensor(TfLiteTensor* tensor) {
    return;
  }

  bool IsAllTempTfLiteTensorDeallocated() {
    return true;
  }

  TfLiteEvalTensor* GetEvalTensor(int tensor_index) {
    return GetEvalTensorImpl(nullptr, tensor_index);
  }

};


} // namespace

TfLiteStatus tflite_learn_4_init( void*(*alloc_fnc)(size_t,size_t) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  tensor_arena = (uint8_t*) alloc_fnc(16, kTensorArenaSize);
  if (!tensor_arena) {
    ei_printf("ERR: failed to allocate tensor arena\n");
    return kTfLiteError;
  }
#else
  memset(tensor_arena, 0, kTensorArenaSize);
#endif
  tensor_boundary = tensor_arena;
  current_location = tensor_arena + kTensorArenaSize;

  EonMicroContext micro_context_;
  
  // Set microcontext as the context ptr
  ctx.impl_ = static_cast<void*>(&micro_context_);
  // Setup tflitecontext functions
  ctx.AllocatePersistentBuffer = &AllocatePersistentBufferImpl;
  ctx.RequestScratchBufferInArena = &RequestScratchBufferInArenaImpl;
  ctx.GetScratchBuffer = &GetScratchBufferImpl;
  ctx.GetTensor = &GetTensorImpl;
  ctx.GetEvalTensor = &GetEvalTensorImpl;
  ctx.ReportError = &MicroContextReportOpError;

  ctx.tensors_size = 15;
  for (size_t i = 0; i < 15; ++i) {
    TfLiteTensor tensor;
    init_tflite_tensor(i, &tensor);
    if (tensor.allocation_type == kTfLiteArenaRw) {
      auto data_end_ptr = (uint8_t*)tensor.data.data + tensorData[i].bytes;
      if (data_end_ptr > tensor_boundary) {
        tensor_boundary = data_end_ptr;
      }
    }
  }

  if (tensor_boundary > current_location /* end of arena size */) {
    ei_printf("ERR: tensor arena is too small, does not fit model - even without scratch buffers\n");
    return kTfLiteError;
  }

  registrations[OP_RESHAPE] = Register_RESHAPE();
  registrations[OP_CONV_2D] = Register_CONV_2D();
  registrations[OP_MAX_POOL_2D] = Register_MAX_POOL_2D();
  registrations[OP_FULLY_CONNECTED] = Register_FULLY_CONNECTED();
  registrations[OP_SOFTMAX] = Register_SOFTMAX();

  for (size_t g = 0; g < 1; ++g) {
    current_subgraph_index = g;
    for(size_t i = tflNodes_subgraph_index[g]; i < tflNodes_subgraph_index[g+1]; ++i) {
      if (registrations[used_ops[i]].init) {
        tflNodes[i].user_data = registrations[used_ops[i]].init(&ctx, (const char*)tflNodes[i].builtin_data, 0);
      }
    }
  }
  current_subgraph_index = 0;

  for(size_t g = 0; g < 1; ++g) {
    current_subgraph_index = g;
    for(size_t i = tflNodes_subgraph_index[g]; i < tflNodes_subgraph_index[g+1]; ++i) {
      if (registrations[used_ops[i]].prepare) {
        ResetTensors();
        TfLiteStatus status = registrations[used_ops[i]].prepare(&ctx, &tflNodes[i]);
        if (status != kTfLiteOk) {
          return status;
        }
      }
    }
  }
  current_subgraph_index = 0;

  return kTfLiteOk;
}

TfLiteStatus tflite_learn_4_input(int index, TfLiteTensor *tensor) {
  init_tflite_tensor(in_tensor_indices[index], tensor);
  return kTfLiteOk;
}

TfLiteStatus tflite_learn_4_output(int index, TfLiteTensor *tensor) {
  init_tflite_tensor(out_tensor_indices[index], tensor);
  return kTfLiteOk;
}

TfLiteStatus tflite_learn_4_invoke() {
  for (size_t i = 0; i < 7; ++i) {
    ResetTensors();

    TfLiteStatus status = registrations[used_ops[i]].invoke(&ctx, &tflNodes[i]);

#if EI_CLASSIFIER_PRINT_STATE
    ei_printf("layer %lu\n", i);
    ei_printf("    inputs:\n");
    for (size_t ix = 0; ix < tflNodes[i].inputs->size; ix++) {
      auto d = tensorData[tflNodes[i].inputs->data[ix]];

      size_t data_ptr = (size_t)d.data;

      if (d.allocation_type == kTfLiteArenaRw) {
        data_ptr = (size_t)tensor_arena + data_ptr;
      }

      if (d.type == TfLiteType::kTfLiteInt8) {
        int8_t* data = (int8_t*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes; jx++) {
          ei_printf("%d ", data[jx]);
        }
      }
      else {
        float* data = (float*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes / 4; jx++) {
          ei_printf("%f ", data[jx]);
        }
      }
      ei_printf("\n");
    }
    ei_printf("\n");

    ei_printf("    outputs:\n");
    for (size_t ix = 0; ix < tflNodes[i].outputs->size; ix++) {
      auto d = tensorData[tflNodes[i].outputs->data[ix]];

      size_t data_ptr = (size_t)d.data;

      if (d.allocation_type == kTfLiteArenaRw) {
        data_ptr = (size_t)tensor_arena + data_ptr;
      }

      if (d.type == TfLiteType::kTfLiteInt8) {
        int8_t* data = (int8_t*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes; jx++) {
          ei_printf("%d ", data[jx]);
        }
      }
      else {
        float* data = (float*)data_ptr;
        ei_printf("        %lu (%zu bytes, ptr=%p, alloc_type=%d, type=%d): ", ix, d.bytes, data, (int)d.allocation_type, (int)d.type);
        for (size_t jx = 0; jx < d.bytes / 4; jx++) {
          ei_printf("%f ", data[jx]);
        }
      }
      ei_printf("\n");
    }
    ei_printf("\n");
#endif // EI_CLASSIFIER_PRINT_STATE

    if (status != kTfLiteOk) {
      return status;
    }
  }
  return kTfLiteOk;
}

TfLiteStatus tflite_learn_4_reset( void (*free_fnc)(void* ptr) ) {
#ifdef EI_CLASSIFIER_ALLOCATION_HEAP
  free_fnc(tensor_arena);
#endif

  // scratch buffers are allocated within the arena, so just reset the counter so memory can be reused
  scratch_buffers_ix = 0;

  // overflow buffers are on the heap, so free them first
  for (size_t ix = 0; ix < overflow_buffers_ix; ix++) {
    ei_free(overflow_buffers[ix]);
  }
  overflow_buffers_ix = 0;
  return kTfLiteOk;
}