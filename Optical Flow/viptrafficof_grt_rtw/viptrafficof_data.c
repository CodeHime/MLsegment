/*
 * viptrafficof_data.c
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

#include "viptrafficof.h"
#include "viptrafficof_private.h"

/* Block parameters (auto storage) */
P_viptrafficof_T viptrafficof_P = {
  1.0F,

  { 1.0F, 1.0F, 1.0F },
  1.0F,
  1,
  1,
  10,

  { 1, 1 },
  3600U,
  300U,
  1,
  20.0,
  0.0F,

  { 0.0F, 1.0F, 0.0F },
  1.0F,
  0.0F,

  { 255.0F, 255.0F, 0.0F },
  1U
};

/* Constant parameters (auto storage) */
const ConstP_viptrafficof_T viptrafficof_ConstP = {
  /* Computed Parameter: BlobAnalysis_WALKER_RTP
   * Referenced by: '<S7>/Blob Analysis'
   */
  { -1, 100, 101, 102, 1, -100, -101, -102 },

  /* Computed Parameter: InsertText_GlyLBearings
   * Referenced by: '<S4>/Insert Text'
   */
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 1, 1,
    1, 0, 1, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0, -1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
    1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

  /* Computed Parameter: InsertText_GlyTBearings
   * Referenced by: '<S4>/Insert Text'
   */
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 7, 0, 4, 2, 0, 9, 9, 9, 9,
    9, 9, 9, 9, 9, 9, 7, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 7, 9, 7, 9, 7, 9, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

  /* Computed Parameter: InsertText_GlyIndexes
   * Referenced by: '<S4>/Insert Text'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 81U, 0U, 130U, 135U, 0U, 139U, 193U, 238U, 283U, 328U,
    382U, 427U, 481U, 526U, 580U, 634U, 0U, 0U, 0U, 0U, 0U, 0U, 648U, 729U, 774U,
    819U, 864U, 909U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 954U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 1035U, 1077U, 1122U, 1157U,
    1202U, 1237U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 1291U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U },

  /* Computed Parameter: InsertText_GlyWidths
   * Referenced by: '<S4>/Insert Text'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 9U,
    0U, 0U, 0U, 0U, 0U, 7U, 0U, 5U, 2U, 0U, 6U, 5U, 5U, 5U, 6U, 5U, 6U, 5U, 6U,
    6U, 2U, 0U, 0U, 0U, 0U, 0U, 0U, 9U, 5U, 5U, 5U, 5U, 5U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 9U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 6U, 5U, 5U, 5U, 5U, 6U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 7U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Computed Parameter: InsertText_GlyHeights
   * Referenced by: '<S4>/Insert Text'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 9U,
    0U, 0U, 0U, 0U, 0U, 7U, 0U, 1U, 2U, 0U, 9U, 9U, 9U, 9U, 9U, 9U, 9U, 9U, 9U,
    9U, 7U, 0U, 0U, 0U, 0U, 0U, 0U, 9U, 9U, 9U, 9U, 9U, 9U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 9U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 7U, 9U, 7U, 9U, 7U, 9U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 7U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Computed Parameter: InsertText_GlyXAdvances
   * Referenced by: '<S4>/Insert Text'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 7U, 0U, 0U, 0U, 0U, 7U,
    0U, 0U, 0U, 0U, 0U, 7U, 0U, 7U, 7U, 0U, 7U, 7U, 7U, 7U, 7U, 7U, 7U, 7U, 7U,
    7U, 7U, 0U, 0U, 0U, 0U, 0U, 0U, 7U, 7U, 7U, 7U, 7U, 7U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 7U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 7U, 7U, 7U, 7U, 7U, 7U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 7U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Computed Parameter: InsertText_GlyData
   * Referenced by: '<S4>/Insert Text'
   */
  { 0U, 88U, 235U, 87U, 0U, 0U, 37U, 203U, 11U, 0U, 231U, 64U, 231U, 0U, 5U,
    197U, 48U, 0U, 0U, 231U, 63U, 232U, 0U, 139U, 112U, 0U, 0U, 0U, 88U, 235U,
    90U, 70U, 180U, 1U, 0U, 0U, 0U, 0U, 0U, 22U, 207U, 21U, 0U, 0U, 0U, 0U, 0U,
    1U, 180U, 70U, 88U, 235U, 87U, 0U, 0U, 0U, 113U, 139U, 0U, 231U, 64U, 231U,
    0U, 0U, 49U, 197U, 5U, 0U, 231U, 63U, 232U, 0U, 11U, 203U, 37U, 0U, 0U, 88U,
    235U, 90U, 0U, 0U, 0U, 0U, 255U, 0U, 0U, 0U, 0U, 0U, 0U, 255U, 0U, 0U, 0U,
    0U, 0U, 0U, 255U, 0U, 0U, 0U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 0U,
    0U, 0U, 255U, 0U, 0U, 0U, 0U, 0U, 0U, 255U, 0U, 0U, 0U, 0U, 0U, 0U, 255U, 0U,
    0U, 0U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 0U, 90U, 230U,
    229U, 87U, 0U, 51U, 203U, 33U, 33U, 202U, 48U, 171U, 72U, 0U, 0U, 72U, 170U,
    224U, 20U, 0U, 0U, 21U, 222U, 248U, 5U, 0U, 0U, 5U, 247U, 223U, 20U, 0U, 0U,
    22U, 222U, 170U, 70U, 0U, 0U, 76U, 170U, 49U, 199U, 31U, 35U, 205U, 50U, 0U,
    90U, 232U, 229U, 88U, 0U, 16U, 95U, 181U, 0U, 0U, 230U, 155U, 255U, 0U, 0U,
    4U, 0U, 255U, 0U, 0U, 0U, 0U, 255U, 0U, 0U, 0U, 0U, 255U, 0U, 0U, 0U, 0U,
    255U, 0U, 0U, 0U, 0U, 255U, 0U, 0U, 0U, 0U, 255U, 0U, 0U, 255U, 255U, 255U,
    255U, 255U, 255U, 255U, 244U, 186U, 35U, 0U, 0U, 10U, 126U, 198U, 0U, 0U, 0U,
    10U, 244U, 0U, 0U, 0U, 67U, 177U, 0U, 0U, 27U, 197U, 30U, 0U, 28U, 196U, 41U,
    0U, 17U, 192U, 35U, 0U, 0U, 167U, 63U, 0U, 0U, 0U, 255U, 255U, 255U, 255U,
    255U, 255U, 255U, 246U, 197U, 52U, 0U, 0U, 7U, 108U, 219U, 0U, 0U, 0U, 6U,
    244U, 0U, 1U, 10U, 83U, 161U, 0U, 255U, 255U, 210U, 27U, 0U, 1U, 18U, 115U,
    191U, 0U, 0U, 0U, 12U, 245U, 0U, 0U, 11U, 109U, 190U, 255U, 255U, 235U, 168U,
    26U, 0U, 0U, 0U, 87U, 255U, 0U, 0U, 0U, 23U, 208U, 255U, 0U, 0U, 0U, 176U,
    71U, 255U, 0U, 0U, 95U, 153U, 0U, 255U, 0U, 28U, 207U, 12U, 0U, 255U, 0U,
    183U, 64U, 0U, 0U, 255U, 0U, 255U, 255U, 255U, 255U, 255U, 255U, 0U, 0U, 0U,
    0U, 255U, 0U, 0U, 0U, 0U, 0U, 255U, 0U, 255U, 255U, 255U, 255U, 255U, 255U,
    0U, 0U, 0U, 0U, 255U, 0U, 0U, 0U, 0U, 255U, 249U, 234U, 192U, 61U, 0U, 9U,
    33U, 135U, 206U, 0U, 0U, 0U, 12U, 246U, 0U, 0U, 0U, 19U, 233U, 0U, 0U, 17U,
    142U, 143U, 255U, 255U, 227U, 136U, 7U, 0U, 43U, 182U, 244U, 255U, 255U, 32U,
    220U, 89U, 17U, 0U, 0U, 157U, 95U, 0U, 0U, 0U, 0U, 227U, 110U, 223U, 240U,
    161U, 13U, 250U, 169U, 23U, 11U, 122U, 158U, 233U, 23U, 0U, 0U, 15U, 238U,
    196U, 14U, 0U, 0U, 10U, 227U, 95U, 121U, 11U, 7U, 107U, 138U, 1U, 135U, 237U,
    235U, 147U, 8U, 255U, 255U, 255U, 255U, 255U, 0U, 0U, 0U, 57U, 178U, 0U, 0U,
    0U, 170U, 56U, 0U, 0U, 31U, 187U, 0U, 0U, 0U, 139U, 82U, 0U, 0U, 10U, 215U,
    4U, 0U, 0U, 98U, 150U, 0U, 0U, 0U, 180U, 75U, 0U, 0U, 0U, 231U, 23U, 0U, 0U,
    22U, 162U, 233U, 245U, 203U, 65U, 182U, 127U, 16U, 14U, 114U, 230U, 235U,
    17U, 0U, 0U, 43U, 205U, 104U, 193U, 85U, 124U, 175U, 31U, 42U, 243U, 176U,
    236U, 196U, 42U, 191U, 80U, 0U, 4U, 120U, 207U, 246U, 10U, 0U, 0U, 12U, 240U,
    194U, 113U, 13U, 11U, 113U, 164U, 30U, 177U, 240U, 234U, 153U, 13U, 9U, 149U,
    235U, 240U, 159U, 8U, 140U, 105U, 7U, 12U, 125U, 120U, 228U, 10U, 0U, 0U,
    15U, 205U, 239U, 14U, 0U, 0U, 24U, 236U, 162U, 117U, 9U, 23U, 171U, 250U,
    16U, 165U, 241U, 223U, 111U, 226U, 0U, 0U, 0U, 0U, 98U, 157U, 0U, 0U, 16U,
    89U, 222U, 33U, 255U, 255U, 245U, 184U, 44U, 0U, 255U, 255U, 255U, 255U, 0U,
    0U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 255U, 0U, 0U, 0U, 65U, 255U, 65U, 0U,
    0U, 0U, 0U, 0U, 0U, 156U, 193U, 155U, 0U, 0U, 0U, 0U, 0U, 6U, 231U, 31U,
    230U, 6U, 0U, 0U, 0U, 0U, 80U, 175U, 0U, 172U, 79U, 0U, 0U, 0U, 0U, 170U,
    85U, 0U, 81U, 169U, 0U, 0U, 0U, 13U, 234U, 9U, 0U, 7U, 229U, 13U, 0U, 0U,
    95U, 255U, 255U, 255U, 255U, 255U, 94U, 0U, 0U, 185U, 71U, 0U, 0U, 0U, 67U,
    184U, 0U, 22U, 229U, 3U, 0U, 0U, 0U, 2U, 226U, 22U, 255U, 255U, 250U, 216U,
    77U, 255U, 1U, 19U, 117U, 228U, 255U, 0U, 0U, 13U, 239U, 255U, 2U, 21U, 125U,
    133U, 255U, 255U, 255U, 244U, 20U, 255U, 2U, 19U, 111U, 166U, 255U, 0U, 0U,
    7U, 244U, 255U, 0U, 9U, 94U, 217U, 255U, 255U, 252U, 216U, 62U, 0U, 97U,
    225U, 255U, 255U, 59U, 233U, 61U, 1U, 0U, 173U, 103U, 0U, 0U, 0U, 225U, 29U,
    0U, 0U, 0U, 248U, 6U, 0U, 0U, 0U, 228U, 27U, 0U, 0U, 0U, 181U, 103U, 0U, 0U,
    0U, 67U, 236U, 74U, 6U, 0U, 0U, 104U, 227U, 255U, 255U, 255U, 255U, 223U,
    81U, 0U, 255U, 4U, 44U, 201U, 66U, 255U, 0U, 0U, 67U, 187U, 255U, 0U, 0U,
    16U, 239U, 255U, 0U, 0U, 3U, 252U, 255U, 0U, 0U, 18U, 236U, 255U, 0U, 0U,
    74U, 188U, 255U, 5U, 57U, 219U, 86U, 255U, 254U, 226U, 112U, 0U, 255U, 255U,
    255U, 255U, 255U, 255U, 0U, 0U, 0U, 0U, 255U, 0U, 0U, 0U, 0U, 255U, 0U, 0U,
    0U, 0U, 255U, 255U, 255U, 255U, 0U, 255U, 0U, 0U, 0U, 0U, 255U, 0U, 0U, 0U,
    0U, 255U, 0U, 0U, 0U, 0U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
    255U, 255U, 255U, 0U, 0U, 0U, 0U, 255U, 0U, 0U, 0U, 0U, 255U, 0U, 0U, 0U, 0U,
    255U, 255U, 255U, 255U, 0U, 255U, 0U, 0U, 0U, 0U, 255U, 0U, 0U, 0U, 0U, 255U,
    0U, 0U, 0U, 0U, 255U, 0U, 0U, 0U, 0U, 11U, 203U, 36U, 0U, 0U, 0U, 36U, 203U,
    11U, 0U, 49U, 195U, 5U, 0U, 5U, 196U, 49U, 0U, 0U, 0U, 112U, 137U, 0U, 138U,
    113U, 0U, 0U, 0U, 0U, 1U, 179U, 132U, 181U, 1U, 0U, 0U, 0U, 0U, 0U, 42U,
    255U, 46U, 0U, 0U, 0U, 0U, 0U, 0U, 179U, 136U, 182U, 1U, 0U, 0U, 0U, 0U,
    112U, 140U, 0U, 141U, 113U, 0U, 0U, 0U, 48U, 197U, 5U, 0U, 6U, 198U, 49U, 0U,
    11U, 203U, 37U, 0U, 0U, 0U, 37U, 203U, 11U, 255U, 255U, 252U, 206U, 52U, 0U,
    0U, 0U, 5U, 97U, 213U, 0U, 0U, 0U, 0U, 3U, 254U, 0U, 30U, 167U, 233U, 254U,
    255U, 0U, 202U, 114U, 23U, 3U, 255U, 0U, 238U, 50U, 16U, 106U, 255U, 25U,
    91U, 231U, 231U, 131U, 146U, 242U, 255U, 0U, 0U, 0U, 0U, 255U, 0U, 0U, 0U,
    0U, 255U, 79U, 232U, 210U, 36U, 255U, 153U, 19U, 118U, 174U, 255U, 6U, 0U,
    19U, 234U, 255U, 0U, 0U, 5U, 247U, 255U, 12U, 0U, 29U, 218U, 255U, 137U, 15U,
    141U, 134U, 255U, 82U, 242U, 186U, 14U, 7U, 140U, 228U, 255U, 255U, 130U,
    150U, 23U, 0U, 0U, 220U, 22U, 0U, 0U, 0U, 247U, 2U, 0U, 0U, 0U, 221U, 12U,
    0U, 0U, 0U, 132U, 104U, 9U, 0U, 0U, 8U, 141U, 228U, 255U, 255U, 0U, 0U, 0U,
    0U, 255U, 0U, 0U, 0U, 0U, 255U, 14U, 186U, 243U, 96U, 255U, 135U, 87U, 12U,
    169U, 255U, 219U, 12U, 0U, 28U, 255U, 247U, 2U, 0U, 0U, 255U, 236U, 19U, 0U,
    6U, 255U, 176U, 116U, 17U, 150U, 255U, 39U, 212U, 233U, 79U, 255U, 7U, 162U,
    245U, 204U, 37U, 125U, 102U, 10U, 110U, 172U, 218U, 15U, 0U, 9U, 231U, 247U,
    255U, 255U, 255U, 251U, 224U, 10U, 0U, 0U, 0U, 141U, 112U, 10U, 0U, 0U, 11U,
    151U, 233U, 255U, 255U, 0U, 0U, 78U, 215U, 253U, 255U, 0U, 0U, 243U, 38U, 1U,
    0U, 255U, 255U, 255U, 255U, 255U, 255U, 0U, 0U, 255U, 0U, 0U, 0U, 0U, 0U,
    255U, 0U, 0U, 0U, 0U, 0U, 255U, 0U, 0U, 0U, 0U, 0U, 255U, 0U, 0U, 0U, 0U, 0U,
    255U, 0U, 0U, 0U, 0U, 0U, 255U, 0U, 0U, 0U, 12U, 211U, 28U, 0U, 29U, 210U,
    12U, 0U, 74U, 180U, 0U, 181U, 71U, 0U, 0U, 0U, 165U, 170U, 161U, 0U, 0U, 0U,
    0U, 41U, 255U, 37U, 0U, 0U, 0U, 0U, 165U, 166U, 161U, 0U, 0U, 0U, 73U, 179U,
    0U, 179U, 71U, 0U, 12U, 211U, 28U, 0U, 29U, 210U, 12U },

  /* Expression: nhood
   * Referenced by: '<S3>/Closing'
   */
  { 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 }
};
