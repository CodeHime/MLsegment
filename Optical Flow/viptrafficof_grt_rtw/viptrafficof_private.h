/*
 * viptrafficof_private.h
 *
 * Code generation for model "viptrafficof".
 *
 * Model version              : 1.1107
 * Simulink Coder version : 8.10 (R2016a) 10-Feb-2016
 * C source code generated on : Thu Apr 20 15:12:09 2017
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (Generic->MATLAB Host Computer)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_viptrafficof_private_h_
#define RTW_HEADER_viptrafficof_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

extern boolean_T PadBConst_ub(const boolean_T u[], const int32_T uStride[],
  const int32_T idx[], const int32_T uStart[], const int32_T uEnd[], const
  int32_T sNumPreEdges, const int32_T sPreEdges[], const int32_T sNumPostEdges,
  const int32_T sPostEdges[], boolean_T padValue);
extern void MdnFlt_M_IBConst_ub_yb_ab_pb_f(const int32_T hLoc[], const int32_T
  hDims[], const boolean_T u[], const int32_T uDims[], boolean_T y[], const
  int32_T yDims[], const int32_T yOrigin[], boolean_T padValue);
extern real_T rt_roundd_snf(real_T u);
extern int32_T div_s32_floor(int32_T numerator, int32_T denominator);

#endif                                 /* RTW_HEADER_viptrafficof_private_h_ */
