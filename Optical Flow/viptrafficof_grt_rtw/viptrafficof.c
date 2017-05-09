/*
 * viptrafficof.c
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

/* Block signals (auto storage) */
B_viptrafficof_T viptrafficof_B;

/* Block states (auto storage) */
DW_viptrafficof_T viptrafficof_DW;

/* Real-time model */
RT_MODEL_viptrafficof_T viptrafficof_M_;
RT_MODEL_viptrafficof_T *const viptrafficof_M = &viptrafficof_M_;

/* Forward declaration for local functions */
static void viptrafficof_repmat(real_T varargin_1, real_T b_data[], int32_T
  b_sizes[2]);
static void viptrafficof_meshgrid(const real_T x[31], const real_T y[23], real_T
  xx[713], real_T yy[713]);
int32_T div_s32_floor(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  uint32_T absNumerator;
  uint32_T absDenominator;
  uint32_T tempAbsQuotient;
  boolean_T quotientNeedsNegation;
  if (denominator == 0) {
    quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;

    /* Divide by zero handler */
  } else {
    absNumerator = numerator < 0 ? ~(uint32_T)numerator + 1U : (uint32_T)
      numerator;
    absDenominator = denominator < 0 ? ~(uint32_T)denominator + 1U : (uint32_T)
      denominator;
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }
    }

    quotient = quotientNeedsNegation ? -(int32_T)tempAbsQuotient : (int32_T)
      tempAbsQuotient;
  }

  return quotient;
}

boolean_T PadBConst_ub(const boolean_T u[], const int32_T uStride[], const
  int32_T idx[], const int32_T uStart[], const int32_T uEnd[], const int32_T
  sNumPreEdges, const int32_T sPreEdges[], const int32_T sNumPostEdges, const
  int32_T sPostEdges[], boolean_T padValue)
{
  boolean_T uOut;
  int32_T edgeNum;
  boolean_T isOutside;

  /* S-Function (svipmdnfilter): '<S3>/Median Filter' */
  /* For boundary sectors: */
  /* -check if index is outside of input bounds ... */
  /*   -if so then return pad extended value */
  /*   -else fetch input data at the index */
  isOutside = false;
  for (edgeNum = 0; edgeNum < sNumPreEdges; edgeNum++) {
    isOutside = (isOutside || (idx[sPreEdges[edgeNum]] <
      uStart[sPreEdges[edgeNum]]));
  }

  for (edgeNum = 0; edgeNum < sNumPostEdges; edgeNum++) {
    isOutside = (isOutside || (idx[sPostEdges[edgeNum]] >
      uEnd[sPostEdges[edgeNum]]));
  }

  if (isOutside) {
    /* return pad value */
    uOut = padValue;
  } else {
    /* linearize index and return input data */
    uOut = u[idx[0U] * uStride[0U] + idx[1U] * uStride[1U]];
  }

  /* End of S-Function (svipmdnfilter): '<S3>/Median Filter' */
  return uOut;
}

void MdnFlt_M_IBConst_ub_yb_ab_pb_f(const int32_T hLoc[], const int32_T hDims[],
  const boolean_T u[], const int32_T uDims[], boolean_T y[], const int32_T
  yDims[], const int32_T yOrigin[], boolean_T padValue)
{
  int32_T uOrigin[2];
  int32_T uEnd[2];
  int32_T uStride[2];
  int32_T hEnd[2];
  int32_T yEnd[2];
  int32_T mLoc[10];
  int32_T mWidth[10];
  int32_T hLoc_0;
  int32_T hEnd_0;
  int32_T uOrigin_0;
  int32_T uEnd_0;
  int32_T yEnd_0;
  int32_T hPre;
  int32_T hPost;
  int32_T bPreEnd;
  int32_T bPostEnd;
  boolean_T isSEmpty;
  int32_T sStart[2];
  int32_T sEnd[2];
  int32_T offset[2];
  int32_T idxB[2];
  int32_T idxALin[2];
  int32_T idxBLin[2];
  int32_T hIdxA[2];
  int32_T sStart_0[2];
  int32_T sEnd_0[2];
  int32_T sPreEdges[2];
  int32_T sPostEdges[2];
  int32_T c[2];
  int8_T o[5];
  boolean_T isEnd;
  boolean_T dimIsPre;
  int32_T offset_0[2];
  int32_T idxA[2];
  int32_T idxB_0[2];
  int32_T idxBLin_0[2];
  int32_T hIdxA_0[2];
  int32_T hIdxB[2];

  /* S-Function (svipmdnfilter): '<S3>/Median Filter' */
  uOrigin[0U] = 0;
  uEnd[0U] = uDims[0U] - 1;
  uStride[0U] = 1;
  uOrigin[1U] = 0;
  uEnd[1U] = uDims[1U] - 1;
  uStride[1U] = uDims[0U];
  hEnd[0U] = hDims[0U] - 1;
  hEnd[1U] = hDims[1U] - 1;
  yEnd[0U] = yDims[0U] - 1;
  yEnd[1U] = yDims[1U] - 1;

  /*  COMPUTE MARGINS BETWEEN INPUT AND OUTPUT       */
  /* =============================================== */
  /*      _________________________________________  */
  /*     |u                                        | */
  /*     |                                         | */
  /*     |         ______________________          | */
  /*     |        |y                     |         | */
  /*     |        |                      |         | */
  /*     |<-yPre->|                      |<-yPost->| */
  /*     |        |                      |         | */
  /*  */
  /*  KERNEL MARIGINS                               */
  /* ============================================== */
  /*      ____________________  */
  /*     |h                   | */
  /*     |        |<--hPost-->| */
  /*     |        |           | */
  /*     |        x(hCenter)  | */
  /*     |<-hPre->|           | */
  /*     |        |           | */
  /*  */
  /*  MARGINS (Valid, Boundary and Outside) definitions: */
  /*  Valid Margin: Processing region where entire kernel stays inside input boundaries. All input data thus considered is 'valid' data */
  /*  Boundary Margin: Processing region where part of kernel stays inside the input boundaries and part of it goes outside input boundaries. */
  /*  Outside Margin: Processing region where entire kernel stays outside the input boundaries and never touches input data. In most situations this region does not need to be processed. Instead output pad values are filled in */
  /* =========================================================== */
  /*   y |        |        |               |         |         | */
  /*     |<-oPre->|<-bPre->|<----valid---->|<-bPost->|<-oPost->| */
  /*     |        |        |               |         |         | */
  /*  */
  /*  All margin locations are stored relative to the output origin */
  /* margins between y and u */
  uOrigin_0 = -yOrigin[0];
  uEnd_0 = (yOrigin[0] + yEnd[0]) - uEnd[0];

  /* margins caused by kernel - defined by center location */
  /* hLoc and hEnd are defined relative to origin */
  hPre = -hLoc[0];
  hPost = hLoc[0] + hEnd[0];

  /* margins outside of kernel's influence around input */
  /* note that we subtract h'Post' from y'Pre' */
  hEnd_0 = uOrigin_0 - hPost;

  /* note that we subtract h'Pre' from y'Post' */
  hLoc_0 = uEnd_0 - hPre;
  hPre += uOrigin_0;
  hPost += uEnd_0;

  /* W refers to margin Width */
  /* L refers to margin Location */
  /* outer Pre */
  /* saturate */
  if (hEnd_0 < 0) {
    uOrigin_0 = 0;
  } else if (hEnd_0 > yDims[0]) {
    uOrigin_0 = yDims[0];
  } else {
    uOrigin_0 = hEnd_0;
  }

  /* boundary Pre */
  /* saturate */
  if (hPre < 0) {
    hPre = 0;
  } else {
    if (hPre > yDims[0]) {
      hPre = yDims[0];
    }
  }

  if (hEnd_0 < 0) {
    hEnd_0 = 0;
  } else {
    if (hEnd_0 > yDims[0]) {
      hEnd_0 = yDims[0];
    }
  }

  uEnd_0 = hPre - hEnd_0;
  hEnd_0 = yOrigin[0] + uOrigin_0;

  /* outer Post */
  /* saturate */
  if (hLoc_0 < 0) {
    hPre = 0;
  } else if (hLoc_0 > yDims[0]) {
    hPre = yDims[0];
  } else {
    hPre = hLoc_0;
  }

  yEnd_0 = ((yOrigin[0] + yEnd[0]) - hPre) + 1;

  /* boundary Post */
  /* saturate */
  if (hPost < 0) {
    hPost = 0;
  } else {
    if (hPost > yDims[0]) {
      hPost = yDims[0];
    }
  }

  if (hLoc_0 < 0) {
    hLoc_0 = 0;
  } else {
    if (hLoc_0 > yDims[0]) {
      hLoc_0 = yDims[0];
    }
  }

  hLoc_0 = hPost - hLoc_0;
  hPost = yEnd_0 - hLoc_0;
  bPreEnd = hEnd_0 + uEnd_0;
  bPostEnd = hPost + hLoc_0;
  if (bPreEnd - 1 >= hPost) {
    /* defines situation where hDims > uDims */
    uEnd_0 = hPost - hEnd_0;
    hPost = bPreEnd;
    hLoc_0 = bPostEnd - bPreEnd;
  }

  /* assign to the margin set of mLoc and mWidth */
  mLoc[0] = hEnd_0 + uEnd_0;
  mWidth[0] = (((yDims[0] - uOrigin_0) - hPre) - uEnd_0) - hLoc_0;
  mLoc[2] = hEnd_0;
  mWidth[2] = uEnd_0;
  mLoc[4] = hPost;
  mWidth[4] = hLoc_0;
  mLoc[6] = yOrigin[0];
  mWidth[6] = uOrigin_0;
  mLoc[8] = yEnd_0;
  mWidth[8] = hPre;

  /* margins between y and u */
  uOrigin_0 = -yOrigin[1];
  uEnd_0 = (yOrigin[1] + yEnd[1]) - uEnd[1];

  /* margins caused by kernel - defined by center location */
  /* hLoc and hEnd are defined relative to origin */
  hPre = -hLoc[1];
  hPost = hLoc[1] + hEnd[1];

  /* margins outside of kernel's influence around input */
  /* note that we subtract h'Post' from y'Pre' */
  hEnd_0 = uOrigin_0 - hPost;

  /* note that we subtract h'Pre' from y'Post' */
  hLoc_0 = uEnd_0 - hPre;
  hPre += uOrigin_0;
  hPost += uEnd_0;

  /* W refers to margin Width */
  /* L refers to margin Location */
  /* outer Pre */
  /* saturate */
  if (hEnd_0 < 0) {
    uOrigin_0 = 0;
  } else if (hEnd_0 > yDims[1]) {
    uOrigin_0 = yDims[1];
  } else {
    uOrigin_0 = hEnd_0;
  }

  /* boundary Pre */
  /* saturate */
  if (hPre < 0) {
    hPre = 0;
  } else {
    if (hPre > yDims[1]) {
      hPre = yDims[1];
    }
  }

  if (hEnd_0 < 0) {
    hEnd_0 = 0;
  } else {
    if (hEnd_0 > yDims[1]) {
      hEnd_0 = yDims[1];
    }
  }

  uEnd_0 = hPre - hEnd_0;
  hEnd_0 = yOrigin[1] + uOrigin_0;

  /* outer Post */
  /* saturate */
  if (hLoc_0 < 0) {
    hPre = 0;
  } else if (hLoc_0 > yDims[1]) {
    hPre = yDims[1];
  } else {
    hPre = hLoc_0;
  }

  yEnd_0 = ((yOrigin[1] + yEnd[1]) - hPre) + 1;

  /* boundary Post */
  /* saturate */
  if (hPost < 0) {
    hPost = 0;
  } else {
    if (hPost > yDims[1]) {
      hPost = yDims[1];
    }
  }

  if (hLoc_0 < 0) {
    hLoc_0 = 0;
  } else {
    if (hLoc_0 > yDims[1]) {
      hLoc_0 = yDims[1];
    }
  }

  hLoc_0 = hPost - hLoc_0;
  hPost = yEnd_0 - hLoc_0;
  bPreEnd = hEnd_0 + uEnd_0;
  bPostEnd = hPost + hLoc_0;
  if (bPreEnd - 1 >= hPost) {
    /* defines situation where hDims > uDims */
    uEnd_0 = hPost - hEnd_0;
    hPost = bPreEnd;
    hLoc_0 = bPostEnd - bPreEnd;
  }

  /* assign to the margin set of mLoc and mWidth */
  mLoc[1] = hEnd_0 + uEnd_0;
  mWidth[1] = (((yDims[1] - uOrigin_0) - hPre) - uEnd_0) - hLoc_0;
  mLoc[3] = hEnd_0;
  mWidth[3] = uEnd_0;
  mLoc[5] = hPost;
  mWidth[5] = hLoc_0;
  mLoc[7] = yOrigin[1];
  mWidth[7] = uOrigin_0;
  mLoc[9] = yEnd_0;
  mWidth[9] = hPre;

  /*  ////////////////////////////////////////// */
  /*  COMPUTE INSIDE SECTOR                      */
  /*  ////////////////////////////////////////// */
  /*  ========================================== */
  /*  Original arrangement of sectors            */
  /*  ========================================== */
  /*   |   3   |   1   |   0   |   2   |   4   | */
  /*   | OutPre| BndPre| Inside|BndPost|OutPost| */
  /*    _______________________________________  */
  /*   |       |       |       |       |       | */
  /*  3| (3,3) | (3,1) | (3,0) | (3,2) | (3,4) | */
  /*   |       |       |       |       |       | */
  /*    _______________________________________  */
  /*   |       |       |       |       |       | */
  /*  1| (1,3) | (1,1) | (1,0) | (1,2) | (1,4) | */
  /*   |       |       |       |       |       | */
  /*    _______________________________________  */
  /*   |       |       |       |       |       | */
  /*   |       |       | VALID |       |       | */
  /*  0| (0,3) | (0,1) | (0,0) | (0,2) | (0,4) | */
  /*   |       |       |       |       |       | */
  /*    _______________________________________  */
  /*   |       |       |       |       |       | */
  /*  2| (2,3) | (2,1) | (2,0) | (2,2) | (2,4) | */
  /*   |       |       |       |       |       | */
  /*    _______________________________________  */
  /*   |       |       |       |       |       | */
  /*  4| (4,3) | (4,1) | (4,0) | (4,2) | (4,4) | */
  /*   |       |       |       |       |       | */
  /*    ---------------------------------------  */
  /*  Sectors rearranged in order from 0 to 4 */
  /*  ========================================== */
  /*   |   0   |   1   |   2   |   3   |   4   | */
  /*   | Inside| BndPre|BndPost| OutPre|OutPost| */
  /*    _______________________________________  */
  /*   |///////|       |       |       |       | */
  /*   |/VALID/|       |       |       |       | */
  /*  0|/(0,0)/| (0,1) | (0,2) | (0,3) | (0,4) | */
  /*   |///////|       |       |       |       | */
  /*    _______________________________________  */
  /*   |       |       |       |       |       | */
  /*  1| (1,0) | (1,1) | (1,2) | (1,3) | (1,4) | */
  /*   |       |       |       |       |       | */
  /*    _______________________________________  */
  /*   |       |       |       |       |       | */
  /*  2| (2,0) | (2,1) | (2,2) | (2,3) | (2,4) | */
  /*   |       |       |       |       |       | */
  /*    _______________________________________  */
  /*   |       |       |       |       |       | */
  /*  3| (3,0) | (3,1) | (3,2) | (3,3) | (3,4) | */
  /*   |       |       |       |       |       | */
  /*    _______________________________________  */
  /*   |       |       |       |       |       | */
  /*  4| (4,0) | (4,1) | (4,2) | (4,3) | (4,4) | */
  /*   |       |       |       |       |       | */
  /*    ---------------------------------------  */
  /* setup counter for valid sector, that is 0 in all dims */
  /* compute inside sector */
  /* compute sector if not empty */
  if (!((mWidth[0] <= 0) || (mWidth[1] <= 0))) {
    /* sector start corresponds to margin loc */
    /* apply offset of margin width for sector end */
    /* sector start corresponds to margin loc */
    /* apply offset of margin width for sector end */
    /* setup indices for the loops */
    /* Origin stores the origin of Y with respect to U */
    /*  where the origin of Y is at its top left corner */
    /* Compute offset between origin of Y and origin of U(0,0) */
    offset[0U] = -yOrigin[0U];
    offset[1U] = -yOrigin[1U];

    /* sector start and end were computed relative to U */
    /* make them relative to Y by adding offset */
    sStart[0U] = mLoc[0] + offset[0U];
    sEnd[0U] = ((mLoc[0] + mWidth[0]) + offset[0U]) - 1;
    sStart[1U] = mLoc[1] + offset[1U];
    sEnd[1U] = ((mLoc[1] + mWidth[1]) + offset[1U]) - 1;

    /* adjust offset for kernel center */
    offset[0U] -= hLoc[0U];
    offset[1U] -= hLoc[1U];

    /* loop kernel over data */
    idxB[1U] = sStart[1U];
    while (idxB[1U] <= sEnd[1U]) {
      idxALin[1U] = (idxB[1U] - offset[1U]) * uDims[0U];
      idxBLin[1U] = yDims[0U] * idxB[1U];
      idxB[0U] = sStart[0U];
      while (idxB[0U] <= sEnd[0U]) {
        idxALin[0U] = (idxB[0U] - offset[0U]) + idxALin[1U];
        idxBLin[0U] = idxBLin[1U] + idxB[0U];
        uOrigin_0 = idxALin[0U];

        /* loop over kernel and compute median value */
        hPre = 0;

        /* loop over kernel */
        hIdxA[1U] = 0;
        while (hIdxA[1U] <= hEnd[1U]) {
          hIdxA[0U] = 0;
          while (hIdxA[0U] <= hEnd[0U]) {
            /* count number of trues in the window */
            hPre += u[uOrigin_0];
            uOrigin_0++;
            hIdxA[0U]++;
          }

          uOrigin_0 = (uOrigin_0 + uDims[0U]) - hDims[0U];
          hIdxA[1U]++;
        }

        if (idxBLin[0U] >= 0) {
          y[idxBLin[0U]] = ((hPre << 1) >= hDims[0U] * hDims[1U]);
        }

        idxB[0U]++;
      }

      idxB[1U]++;
    }
  }

  /*  ////////////////////////////////////////// */
  /*  COMPUTE ON-BOUNDARY SECTORS                */
  /*  ////////////////////////////////////////// */
  /* =========================================== */
  /*   |   0   |   1   |   2   |   3   |   4   | */
  /*   | Inside| BndPre|BndPost| OutPre|OutPost| */
  /*    _______________________________________  */
  /*   |       |///////|///////|       |       | */
  /*   | VALID |///////|///////|       |       | */
  /*  0| (0,0) |/(0,1)/|/(0,2)/| (0,3) | (0,4) | */
  /*   |       |///////|///////|       |       | */
  /*    _______________________________________  */
  /*   |///////|///////|///////|       |       | */
  /*  1|/(1,0)/|/(1,1)/|/(1,2)/| (1,3) | (1,4) | */
  /*   |///////|///////|///////|       |       | */
  /*    _______________________________________  */
  /*   |///////|///////|///////|       |       | */
  /*  2|/(2,0)/|/(2,1)/|/(2,2)/| (2,3) | (2,4) | */
  /*   |///////|///////|///////|       |       | */
  /*    _______________________________________  */
  /*   |       |       |       |       |       | */
  /*  3| (3,0) | (3,1) | (3,2) | (3,3) | (3,4) | */
  /*   |       |       |       |       |       | */
  /*    _______________________________________  */
  /*   |       |       |       |       |       | */
  /*  4| (4,0) | (4,1) | (4,2) | (4,3) | (4,4) | */
  /*   |       |       |       |       |       | */
  /*    ---------------------------------------  */
  o[0U] = 0;
  o[1U] = 1;
  o[2U] = 2;
  o[3U] = 3;
  o[4U] = 4;
  isEnd = false;
  c[1U] = 0;

  /* if hDims < uDims then the all INSIDE sector will not be pushed into the boundary sectors... hence the counter needs to skip the all INSIDEs sector and start from one sector down. */
  c[0U] = 1;
  while (!isEnd) {
    uOrigin_0 = 0;
    uEnd_0 = 0;

    /* compute on-boundary sector */
    /* compute sector if not empty */
    if (!((mWidth[o[c[0U]] << 1] <= 0) || (mWidth[(o[c[1U]] << 1) + 1] <= 0))) {
      /* compute sector for this dim */
      /* sector start corresponds to margin loc */
      /* apply offset of margin width for sector end */
      /* Inside Sector if 0 in all dimensions */
      isSEmpty = (o[c[0]] == 0);
      dimIsPre = ((o[c[0]] == 3) || (o[c[0]] == 1));
      if (dimIsPre || isSEmpty) {
        sPreEdges[0] = 0;
        uOrigin_0 = 1;
      }

      if ((!(dimIsPre || isSEmpty)) || isSEmpty) {
        sPostEdges[0] = 0;
        uEnd_0 = 1;
      }

      /* compute sector for this dim */
      /* sector start corresponds to margin loc */
      /* apply offset of margin width for sector end */
      /* Inside Sector if 0 in all dimensions */
      isSEmpty = (o[c[1]] == 0);
      dimIsPre = ((o[c[1]] == 3) || (o[c[1]] == 1));
      if (dimIsPre || isSEmpty) {
        sPreEdges[uOrigin_0] = 1;
        uOrigin_0++;
      }

      if ((!(dimIsPre || isSEmpty)) || isSEmpty) {
        sPostEdges[uEnd_0] = 1;
        uEnd_0++;
      }

      /* setup indices for the loops */
      /* Origin stores the origin of Y with respect to U */
      /*  where the origin of Y is at its top left corner */
      /* Compute offset between origin of Y and origin of U(0,0) */
      offset_0[0U] = -yOrigin[0U];
      offset_0[1U] = -yOrigin[1U];

      /* sector start and end were computed relative to U */
      /* make them relative to Y by adding offset */
      sStart_0[0U] = mLoc[o[c[0]] << 1] + offset_0[0U];
      sEnd_0[0U] = ((mLoc[o[c[0]] << 1] + mWidth[o[c[0]] << 1]) + offset_0[0U])
        - 1;
      sStart_0[1U] = mLoc[(o[c[1]] << 1) + 1] + offset_0[1U];
      sEnd_0[1U] = ((mLoc[(o[c[1]] << 1) + 1] + mWidth[(o[c[1]] << 1) + 1]) +
                    offset_0[1U]) - 1;

      /* adjust offset for kernel center */
      offset_0[0U] -= hLoc[0U];
      offset_0[1U] -= hLoc[1U];

      /* loop kernel over data */
      idxB_0[1U] = sStart_0[1U];
      while (idxB_0[1U] <= sEnd_0[1U]) {
        idxA[1U] = idxB_0[1U] - offset_0[1U];
        idxBLin_0[1U] = yDims[0U] * idxB_0[1U];
        idxB_0[0U] = sStart_0[0U];
        while (idxB_0[0U] <= sEnd_0[0U]) {
          idxA[0U] = idxB_0[0U] - offset_0[0U];
          idxBLin_0[0U] = idxBLin_0[1U] + idxB_0[0U];

          /* loop over kernel and compute conv/corr */
          hPre = 0;

          /* loop over kernel */
          hIdxA_0[1U] = 0;
          while (hIdxA_0[1U] <= hEnd[1U]) {
            hIdxB[1U] = idxA[1U] + hIdxA_0[1U];
            hIdxA_0[0U] = 0;
            while (hIdxA_0[0U] <= hEnd[0U]) {
              hIdxB[0U] = idxA[0U] + hIdxA_0[0U];
              isSEmpty = PadBConst_ub(&u[0U], &uStride[0U], &hIdxB[0U],
                &uOrigin[0U], &uEnd[0U], uOrigin_0, &sPreEdges[0U], uEnd_0,
                &sPostEdges[0U], padValue);

              /* count number of trues in the window */
              hPre += isSEmpty;
              hIdxA_0[0U]++;
            }

            hIdxA_0[1U]++;
          }

          if (idxBLin_0[0U] >= 0) {
            y[idxBLin_0[0U]] = ((hPre << 1) >= hDims[0U] * hDims[1U]);
          }

          idxB_0[0U]++;
        }

        idxB_0[1U]++;
      }
    }

    /* advance sector counter */
    uOrigin_0 = 0;
    while (uOrigin_0 < 2) {
      c[uOrigin_0]++;
      if (c[uOrigin_0] <= 2) {
        isEnd = false;
        uOrigin_0 = 2;
      } else {
        c[uOrigin_0] = 0;
        isEnd = true;
      }

      uOrigin_0++;
    }
  }

  /* End of S-Function (svipmdnfilter): '<S3>/Median Filter' */
}

/* Function for MATLAB Function: '<S7>/Array Vector add' */
static void viptrafficof_repmat(real_T varargin_1, real_T b_data[], int32_T
  b_sizes[2])
{
  int32_T ibmat;
  int32_T itilerow;
  int32_T varargin_1_idx_0;
  int8_T outsize_idx_0;
  outsize_idx_0 = (int8_T)(int32_T)varargin_1;
  b_sizes[0] = outsize_idx_0;
  b_sizes[1] = 4;
  if (!(outsize_idx_0 == 0)) {
    varargin_1_idx_0 = (int32_T)varargin_1;
    for (itilerow = 1; itilerow <= varargin_1_idx_0; itilerow++) {
      b_data[itilerow - 1] = 0.0;
    }

    for (itilerow = 1; itilerow <= varargin_1_idx_0; itilerow++) {
      b_data[(varargin_1_idx_0 + itilerow) - 1] = 22.0;
    }

    ibmat = varargin_1_idx_0 << 1;
    for (itilerow = 1; itilerow <= varargin_1_idx_0; itilerow++) {
      b_data[(ibmat + itilerow) - 1] = 0.0;
    }

    ibmat = 3 * varargin_1_idx_0;
    for (itilerow = 1; itilerow <= varargin_1_idx_0; itilerow++) {
      b_data[(ibmat + itilerow) - 1] = 0.0;
    }
  }
}

/* Function for MATLAB Function: '<S5>/Optical Flow Lines' */
static void viptrafficof_meshgrid(const real_T x[31], const real_T y[23], real_T
  xx[713], real_T yy[713])
{
  int32_T jcol;
  int32_T ibtile;
  int32_T k;
  for (jcol = 0; jcol < 31; jcol++) {
    ibtile = jcol * 23;
    for (k = 0; k < 23; k++) {
      xx[ibtile + k] = x[jcol];
    }
  }

  for (jcol = 0; jcol < 31; jcol++) {
    ibtile = jcol * 23;
    memcpy(&yy[ibtile], &y[0], 23U * sizeof(real_T));
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model output function */
static void viptrafficof_output(void)
{
  char_T *sErr;
  void *source_R;
  int32_T h1Dims[2];
  int32_T uDims[2];
  int32_T yDims[2];
  int32_T hLoc[2];
  int32_T yOrigin[2];
  boolean_T visited1;
  boolean_T visited2;
  boolean_T done;
  real32_T opacityVal;
  int32_T outRedIndx;
  int32_T colorIndx;
  int32_T rtb_BlobAnalysis[320];
  int32_T rtb_y[320];
  real32_T rtb_Meanvelocityperframeacrosst;
  uint32_T BlobAnalysis_NUM_PIX_DW[80];
  int32_T minc;
  int32_T maxc;
  int32_T minr;
  int32_T maxr;
  int32_T j_pixListNinc;
  boolean_T maxNumBlobsReached;
  uint8_T currentLabel;
  uint32_T pixIdx;
  uint32_T start_pixIdx;
  uint32_T walkerIdx;
  uint32_T padIdx;
  uint32_T stackIdx;
  int32_T loop;
  int32_T inIdx;
  int32_T outIdx;
  int32_T centerM;
  real_T tmp_data[320];
  int32_T line_idx_0;
  int32_T line_idx_3;
  int32_T line_idx_2;
  int32_T line_idx_1;
  int32_T line_idx_0_0;
  creal32_T rtb_OpticalFlowEstimation_0;
  real_T tmp;
  int64_T tmp_0;

  /* S-Function (sdspwmmfi2): '<Root>/From Multimedia File' */
  sErr = GetErrorBuffer(&viptrafficof_DW.FromMultimediaFile_HostLib[0U]);
  source_R = (void *)&viptrafficof_B.FromMultimediaFile[0U];
  LibOutputs_FromMMFile(&viptrafficof_DW.FromMultimediaFile_HostLib[0U],
                        GetNullPointer(), GetNullPointer(), source_R,
                        GetNullPointer(), GetNullPointer());
  if (*sErr != 0) {
    rtmSetErrorStatus(viptrafficof_M, sErr);
    rtmSetStopRequested(viptrafficof_M, 1);
  }

  /* End of S-Function (sdspwmmfi2): '<Root>/From Multimedia File' */

  /* S-Function (svipcolorconv): '<Root>/Color Space  Conversion' */
  for (loop = 0; loop < 19200; loop++) {
    viptrafficof_B.ColorSpaceConversion[loop] =
      (viptrafficof_B.FromMultimediaFile[19200 + loop] * 0.587F +
       viptrafficof_B.FromMultimediaFile[loop] * 0.299F) +
      viptrafficof_B.FromMultimediaFile[38400 + loop] * 0.114F;
    if (viptrafficof_B.ColorSpaceConversion[loop] > 1.0F) {
      viptrafficof_B.ColorSpaceConversion[loop] = 1.0F;
    } else {
      if (viptrafficof_B.ColorSpaceConversion[loop] < 0.0F) {
        viptrafficof_B.ColorSpaceConversion[loop] = 0.0F;
      }
    }
  }

  /* End of S-Function (svipcolorconv): '<Root>/Color Space  Conversion' */

  /* Delay: '<S2>/Delay' */
  memcpy(&viptrafficof_B.MathFunction[0], &viptrafficof_DW.Delay_DSTATE[0],
         19200U * sizeof(real32_T));

  /* S-Function (svipopticalflow): '<S2>/Optical Flow Estimation' */
  MWVIP_OpticalFlow_HS_C(&viptrafficof_B.ColorSpaceConversion[0],
    &viptrafficof_B.MathFunction[0], &viptrafficof_B.OpticalFlowEstimation[0],
    &viptrafficof_DW.OpticalFlowEstimation_MEMC0[0],
    &viptrafficof_DW.OpticalFlowEstimation_MEMC1[0],
    &viptrafficof_DW.OpticalFlowEstimation_MEMR0[0],
    &viptrafficof_DW.OpticalFlowEstimation_MEMR1[0],
    &viptrafficof_DW.OpticalFlowEstimation_GRADCC[0],
    &viptrafficof_DW.OpticalFlowEstimation_GRADRC[0],
    &viptrafficof_DW.OpticalFlowEstimation_GRADRR[0],
    &viptrafficof_DW.OpticalFlowEstimation_GRADCT[0],
    &viptrafficof_DW.OpticalFlowEstimation_GRADRT[0],
    &viptrafficof_DW.OpticalFlowEstimation_ALPHA[0],
    &viptrafficof_DW.OpticalFlowEstimation_VELBUFFC0[0],
    &viptrafficof_DW.OpticalFlowEstimation_VELBUFFC1[0],
    &viptrafficof_DW.OpticalFlowEstimation_VELBUFFR0[0],
    &viptrafficof_DW.OpticalFlowEstimation_VELBUFFR1[0],
    &viptrafficof_P.OpticalFlow1_lambda, true, false,
    &viptrafficof_P.OpticalFlow1_maxIter, 0, 120, 160);

  /* Math: '<S3>/Math Function'
   *
   * About '<S3>/Math Function':
   *  Operator: magnitude^2
   */
  for (loop = 0; loop < 19200; loop++) {
    rtb_OpticalFlowEstimation_0 = viptrafficof_B.OpticalFlowEstimation[loop];
    viptrafficof_B.MathFunction[loop] = rtb_OpticalFlowEstimation_0.re *
      rtb_OpticalFlowEstimation_0.re + rtb_OpticalFlowEstimation_0.im *
      rtb_OpticalFlowEstimation_0.im;
  }

  /* End of Math: '<S3>/Math Function' */

  /* S-Function (svipstatfcns): '<S8>/Mean velocity per frame' */
  for (loop = 0; loop < 19200; loop += 19200) {
    for (inIdx = loop; inIdx < loop + 1; inIdx++) {
      viptrafficof_DW.Meanvelocityperframe_AccVal =
        viptrafficof_B.MathFunction[inIdx];
      outIdx = 1;
      for (centerM = 19198; centerM >= 0; centerM += -1) {
        viptrafficof_DW.Meanvelocityperframe_AccVal +=
          viptrafficof_B.MathFunction[inIdx + outIdx];
        outIdx++;
      }

      rtb_Meanvelocityperframeacrosst =
        viptrafficof_DW.Meanvelocityperframe_AccVal / 19200.0F;
    }
  }

  /* End of S-Function (svipstatfcns): '<S8>/Mean velocity per frame' */

  /* S-Function (svipstatfcns): '<S8>/Mean velocity per frame across time' */
  viptrafficof_DW.Meanvelocityperframeacrosstim_i++;
  if (viptrafficof_DW.Meanvelocityperframeacrosstim_i > 1U) {
    viptrafficof_DW.Meanvelocityperframeacrosstime_ +=
      rtb_Meanvelocityperframeacrosst;
    rtb_Meanvelocityperframeacrosst =
      viptrafficof_DW.Meanvelocityperframeacrosstime_ / (real32_T)
      viptrafficof_DW.Meanvelocityperframeacrosstim_i;
  } else {
    if (viptrafficof_DW.Meanvelocityperframeacrosstim_i == 0U) {
      viptrafficof_DW.Meanvelocityperframeacrosstim_i = 1U;
    }

    viptrafficof_DW.Meanvelocityperframeacrosstime_ =
      rtb_Meanvelocityperframeacrosst;
  }

  /* End of S-Function (svipstatfcns): '<S8>/Mean velocity per frame across time' */

  /* RelationalOperator: '<S3>/Relational Operator' */
  for (loop = 0; loop < 19200; loop++) {
    viptrafficof_B.RelationalOperator[loop] = (viptrafficof_B.MathFunction[loop]
      >= rtb_Meanvelocityperframeacrosst);
  }

  /* End of RelationalOperator: '<S3>/Relational Operator' */

  /* S-Function (svipmdnfilter): '<S3>/Median Filter' */
  h1Dims[0U] = 3;
  h1Dims[1U] = 3;
  uDims[0U] = 120;
  uDims[1U] = 160;

  /* set up kernel related coordinates */
  /* compute center */
  /* hLoc is the location of top left corner relative to the center of kernel. */
  hLoc[0U] = -1;

  /* compute center */
  /* hLoc is the location of top left corner relative to the center of kernel. */
  hLoc[1U] = -1;

  /* Region of Support (ROS) definition: A selected region that restricts the input space for processing. */
  /* ====================================================== */
  /*                       ---------------------            */
  /*                      |ROI                  |           */
  /*                      |                     |           */
  /*  ----------------------------------------------------  */
  /* | INPUT(u)           |                     |         | */
  /* |                    |                     |         | */
  /* |   ---------------------------------------------    | */
  /* |  | ROS             |OUTPUT(y)////////////|     |   | */
  /* |  |                 |/////////////////////|     |   | */
  /* |  |                  ---------------------      |   | */
  /* |  |                                             |   | */
  /* The user's output mode choices of 'Valid', 'Same as input' and 'Full' map onto correspending definitions of a rectangular ROS. */
  /* Output range support is computed as an intersection of ROS with Region of Interest (ROI) */
  /* ///////////////////// */
  /* begin ROS computation */
  /* compute ROS based on u, h and output mode */
  /* ROS is SAME AS INPUT */
  /* end ROS computation */
  /* /////////////////// */
  /* ///////////////////////// */
  /* begin y sizes computation */
  /* we need to compute yOrigin and yEnd */
  /* yOrigin definition: Location of center of reference (origin) of output (y) coordintate system with respect to input (u) coordinate system */
  /* y sizes are same as ros sizes because there is no ROI */
  yOrigin[0U] = 0;
  yDims[0U] = 120;

  /* y sizes are same as ros sizes because there is no ROI */
  yOrigin[1U] = 0;
  yDims[1U] = 160;

  /* make yOrigin same as roiLoc when y is empty */
  /* end y sizes computation */
  /* /////////////////////// */
  MdnFlt_M_IBConst_ub_yb_ab_pb_f(&hLoc[0U], &h1Dims[0U],
    &viptrafficof_B.RelationalOperator[0U], &uDims[0U],
    &viptrafficof_B.MedianFilter[0U], &yDims[0U], &yOrigin[0U],
    viptrafficof_P.MedianFilter_padVal);

  /* S-Function (svipmorphop): '<S3>/Closing' */
  memset(&viptrafficof_DW.Closing_ONE_PAD_IMG_DW[0], 0, 21801U * sizeof
         (boolean_T));
  for (inIdx = 0; inIdx < 19200; inIdx++) {
    if (viptrafficof_B.MedianFilter[inIdx]) {
      loop = inIdx / 120;
      outIdx = (inIdx - loop * 120) + loop * 129;
      for (loop = 0; loop < viptrafficof_DW.Closing_NUMNONZ_DW; loop++) {
        viptrafficof_DW.Closing_ONE_PAD_IMG_DW[outIdx +
          viptrafficof_DW.Closing_DILATE_OFF_DW[loop]] = true;
      }
    }
  }

  inIdx = 260;
  outIdx = 0;
  for (centerM = 0; centerM < 160; centerM++) {
    for (maxc = 0; maxc < 120; maxc++) {
      viptrafficof_B.Closing[outIdx] =
        viptrafficof_DW.Closing_ONE_PAD_IMG_DW[inIdx];
      outIdx++;
      inIdx++;
    }

    inIdx += 9;
  }

  centerM = 0;
  outIdx = 0;
  for (loop = 0; loop < 2; loop++) {
    for (inIdx = 0; inIdx < 129; inIdx++) {
      viptrafficof_DW.Closing_ONE_PAD_IMG_DW[centerM] = true;
      centerM++;
    }
  }

  for (loop = 0; loop < 160; loop++) {
    viptrafficof_DW.Closing_ONE_PAD_IMG_DW[centerM] = true;
    centerM++;
    viptrafficof_DW.Closing_ONE_PAD_IMG_DW[centerM] = true;
    centerM++;
    memcpy(&viptrafficof_DW.Closing_ONE_PAD_IMG_DW[centerM],
           &viptrafficof_B.Closing[outIdx], 120U * sizeof(boolean_T));
    centerM += 120;
    outIdx += 120;
    for (inIdx = 0; inIdx < 7; inIdx++) {
      viptrafficof_DW.Closing_ONE_PAD_IMG_DW[centerM] = true;
      centerM++;
    }
  }

  for (loop = 0; loop < 7; loop++) {
    for (inIdx = 0; inIdx < 129; inIdx++) {
      viptrafficof_DW.Closing_ONE_PAD_IMG_DW[centerM] = true;
      centerM++;
    }
  }

  inIdx = 0;
  outIdx = 0;
  for (centerM = 0; centerM < 160; centerM++) {
    for (maxc = 0; maxc < 120; maxc++) {
      viptrafficof_B.Closing[outIdx] = true;
      loop = 0;
      while (loop < viptrafficof_DW.Closing_NUMNONZ_DW) {
        if (!viptrafficof_DW.Closing_ONE_PAD_IMG_DW[inIdx +
            viptrafficof_DW.Closing_ERODE_OFF_DW[loop]]) {
          viptrafficof_B.Closing[outIdx] = false;
          loop = viptrafficof_DW.Closing_NUMNONZ_DW;
        }

        loop++;
      }

      inIdx++;
      outIdx++;
    }

    inIdx += 9;
  }

  /* End of S-Function (svipmorphop): '<S3>/Closing' */

  /* MATLAB Function: '<S7>/Sub Matrix' */
  /* MATLAB Function 'Thresholding and Region Filtering/Region Filtering/Sub Matrix': '<S10>:1' */
  /* '<S10>:1:6' */
  for (loop = 0; loop < 160; loop++) {
    memcpy(&viptrafficof_B.y[loop * 99], &viptrafficof_B.Closing[loop * 120 + 21],
           99U * sizeof(boolean_T));
  }

  /* End of MATLAB Function: '<S7>/Sub Matrix' */

  /* S-Function (svipblob): '<S7>/Blob Analysis' */
  maxNumBlobsReached = false;
  memset(&viptrafficof_DW.BlobAnalysis_PAD_DW[0], 0, 102U * sizeof(uint8_T));
  currentLabel = 1U;
  loop = 0;
  inIdx = 102;
  for (centerM = 0; centerM < 160; centerM++) {
    for (maxc = 0; maxc < 99; maxc++) {
      viptrafficof_DW.BlobAnalysis_PAD_DW[inIdx] = (uint8_T)
        (viptrafficof_B.y[loop] ? 255 : 0);
      loop++;
      inIdx++;
    }

    viptrafficof_DW.BlobAnalysis_PAD_DW[inIdx] = 0U;
    viptrafficof_DW.BlobAnalysis_PAD_DW[inIdx + 1] = 0U;
    inIdx += 2;
  }

  memset(&viptrafficof_DW.BlobAnalysis_PAD_DW[inIdx], 0, 100U * sizeof(uint8_T));
  inIdx = 1;
  stackIdx = 0U;
  for (centerM = 0; centerM < 2; centerM++) {
    outIdx = 1;
    minc = inIdx * 101;
    for (maxc = 0; maxc < 99; maxc++) {
      padIdx = (uint32_T)(minc + outIdx);
      if (viptrafficof_DW.BlobAnalysis_PAD_DW[padIdx] == 255) {
        viptrafficof_DW.BlobAnalysis_PAD_DW[padIdx] = 0U;
        viptrafficof_DW.BlobAnalysis_STACK_DW[0U] = padIdx;
        stackIdx = 1U;
      }

      while (stackIdx != 0U) {
        stackIdx--;
        padIdx = viptrafficof_DW.BlobAnalysis_STACK_DW[stackIdx];
        for (loop = 0; loop < 8; loop++) {
          walkerIdx = padIdx + viptrafficof_ConstP.BlobAnalysis_WALKER_RTP[loop];
          if (viptrafficof_DW.BlobAnalysis_PAD_DW[walkerIdx] == 255) {
            viptrafficof_DW.BlobAnalysis_PAD_DW[walkerIdx] = 0U;
            viptrafficof_DW.BlobAnalysis_STACK_DW[stackIdx] = walkerIdx;
            stackIdx++;
          }
        }
      }

      outIdx++;
    }

    inIdx += 159;
  }

  inIdx = 2;
  for (centerM = 0; centerM < 158; centerM++) {
    outIdx = 1;
    minc = inIdx * 101;
    for (maxc = 0; maxc < 2; maxc++) {
      padIdx = (uint32_T)(minc + outIdx);
      if (viptrafficof_DW.BlobAnalysis_PAD_DW[padIdx] == 255) {
        viptrafficof_DW.BlobAnalysis_PAD_DW[padIdx] = 0U;
        viptrafficof_DW.BlobAnalysis_STACK_DW[0U] = padIdx;
        stackIdx = 1U;
      }

      while (stackIdx != 0U) {
        stackIdx--;
        padIdx = viptrafficof_DW.BlobAnalysis_STACK_DW[stackIdx];
        for (loop = 0; loop < 8; loop++) {
          walkerIdx = padIdx + viptrafficof_ConstP.BlobAnalysis_WALKER_RTP[loop];
          if (viptrafficof_DW.BlobAnalysis_PAD_DW[walkerIdx] == 255) {
            viptrafficof_DW.BlobAnalysis_PAD_DW[walkerIdx] = 0U;
            viptrafficof_DW.BlobAnalysis_STACK_DW[stackIdx] = walkerIdx;
            stackIdx++;
          }
        }
      }

      outIdx += 98;
    }

    inIdx++;
  }

  inIdx = 1;
  pixIdx = 0U;
  centerM = 0;
  while (centerM < 158) {
    outIdx = 1;
    minc = (inIdx + 1) * 101;
    maxc = 0;
    while (maxc < 97) {
      padIdx = (uint32_T)((minc + outIdx) + 1);
      start_pixIdx = pixIdx;
      if (viptrafficof_DW.BlobAnalysis_PAD_DW[padIdx] == 255) {
        viptrafficof_DW.BlobAnalysis_PAD_DW[padIdx] = currentLabel;
        viptrafficof_DW.BlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)inIdx;
        viptrafficof_DW.BlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)outIdx;
        pixIdx++;
        BlobAnalysis_NUM_PIX_DW[currentLabel - 1] = 1U;
        viptrafficof_DW.BlobAnalysis_STACK_DW[0U] = padIdx;
        stackIdx = 1U;
        while (stackIdx != 0U) {
          stackIdx--;
          padIdx = viptrafficof_DW.BlobAnalysis_STACK_DW[stackIdx];
          for (loop = 0; loop < 8; loop++) {
            walkerIdx = padIdx +
              viptrafficof_ConstP.BlobAnalysis_WALKER_RTP[loop];
            if (viptrafficof_DW.BlobAnalysis_PAD_DW[walkerIdx] == 255) {
              viptrafficof_DW.BlobAnalysis_PAD_DW[walkerIdx] = currentLabel;
              viptrafficof_DW.BlobAnalysis_N_PIXLIST_DW[pixIdx] = (int16_T)
                ((int16_T)(walkerIdx / 101U) - 1);
              viptrafficof_DW.BlobAnalysis_M_PIXLIST_DW[pixIdx] = (int16_T)
                (walkerIdx % 101U - 1U);
              pixIdx++;
              BlobAnalysis_NUM_PIX_DW[currentLabel - 1]++;
              viptrafficof_DW.BlobAnalysis_STACK_DW[stackIdx] = walkerIdx;
              stackIdx++;
            }
          }
        }

        if ((BlobAnalysis_NUM_PIX_DW[currentLabel - 1] <
             viptrafficof_P.BlobAnalysis_minArea) ||
            (BlobAnalysis_NUM_PIX_DW[currentLabel - 1] >
             viptrafficof_P.BlobAnalysis_maxArea)) {
          currentLabel--;
          pixIdx = start_pixIdx;
        }

        if (currentLabel == 80) {
          maxNumBlobsReached = true;
          centerM = 158;
          maxc = 97;
        }

        if (maxc < 97) {
          currentLabel++;
        }
      }

      outIdx++;
      maxc++;
    }

    inIdx++;
    centerM++;
  }

  stackIdx = (uint32_T)(maxNumBlobsReached ? (int32_T)currentLabel : (int32_T)
                        (uint8_T)(currentLabel - 1U));
  centerM = 0;
  outIdx = 0;
  for (loop = 0; loop < (int32_T)stackIdx; loop++) {
    minc = 160;
    minr = 99;
    maxc = 0;
    maxr = 0;
    for (inIdx = 0; inIdx < (int32_T)BlobAnalysis_NUM_PIX_DW[loop]; inIdx++) {
      j_pixListNinc = inIdx + outIdx;
      if (viptrafficof_DW.BlobAnalysis_N_PIXLIST_DW[j_pixListNinc] < minc) {
        minc = viptrafficof_DW.BlobAnalysis_N_PIXLIST_DW[j_pixListNinc];
      }

      if (viptrafficof_DW.BlobAnalysis_N_PIXLIST_DW[j_pixListNinc] > maxc) {
        maxc = viptrafficof_DW.BlobAnalysis_N_PIXLIST_DW[j_pixListNinc];
      }

      j_pixListNinc = inIdx + centerM;
      if (viptrafficof_DW.BlobAnalysis_M_PIXLIST_DW[j_pixListNinc] < minr) {
        minr = viptrafficof_DW.BlobAnalysis_M_PIXLIST_DW[j_pixListNinc];
      }

      if (viptrafficof_DW.BlobAnalysis_M_PIXLIST_DW[j_pixListNinc] > maxr) {
        maxr = viptrafficof_DW.BlobAnalysis_M_PIXLIST_DW[j_pixListNinc];
      }
    }

    rtb_BlobAnalysis[loop] = minc + 1;
    rtb_BlobAnalysis[stackIdx + loop] = minr + 1;
    rtb_BlobAnalysis[((int32_T)stackIdx << 1) + loop] = (maxc - minc) + 1;
    rtb_BlobAnalysis[3 * (int32_T)stackIdx + loop] = (maxr - minr) + 1;
    centerM += (int32_T)BlobAnalysis_NUM_PIX_DW[loop];
    outIdx += (int32_T)BlobAnalysis_NUM_PIX_DW[loop];
  }

  viptrafficof_DW.BlobAnalysis_DIMS1[0] = (int32_T)stackIdx;
  viptrafficof_DW.BlobAnalysis_DIMS1[1] = 4;

  /* End of S-Function (svipblob): '<S7>/Blob Analysis' */

  /* MATLAB Function: '<S7>/Array Vector add' */
  /* MATLAB Function 'Thresholding and Region Filtering/Region Filtering/Array Vector add': '<S9>:1' */
  /* '<S9>:1:3' */
  /* '<S9>:1:5' */
  /* '<S9>:1:7' */
  viptrafficof_DW.SFunction_DIMS2[0] = viptrafficof_DW.BlobAnalysis_DIMS1[0];
  viptrafficof_DW.SFunction_DIMS2[1] = viptrafficof_DW.BlobAnalysis_DIMS1[1];
  viptrafficof_repmat((real_T)viptrafficof_DW.BlobAnalysis_DIMS1[0], tmp_data,
                      h1Dims);
  maxc = viptrafficof_DW.BlobAnalysis_DIMS1[0] *
    viptrafficof_DW.BlobAnalysis_DIMS1[1];
  for (loop = 0; loop < maxc; loop++) {
    tmp = rt_roundd_snf(tmp_data[loop]);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        centerM = (int32_T)tmp;
      } else {
        centerM = MIN_int32_T;
      }
    } else {
      centerM = MAX_int32_T;
    }

    tmp_0 = (int64_T)rtb_BlobAnalysis[loop] + centerM;
    if (tmp_0 > 2147483647LL) {
      tmp_0 = 2147483647LL;
    } else {
      if (tmp_0 < -2147483648LL) {
        tmp_0 = -2147483648LL;
      }
    }

    rtb_y[loop] = (int32_T)tmp_0;
  }

  /* End of MATLAB Function: '<S7>/Array Vector add' */

  /* S-Function (svipdrawshapes): '<S4>/Draw Shapes' */
  maxNumBlobsReached = true;
  centerM = 0;
  if (viptrafficof_DW.SFunction_DIMS2[1] > 1) {
    maxNumBlobsReached = ((viptrafficof_DW.SFunction_DIMS2[1] >> 2) << 2 ==
                          viptrafficof_DW.SFunction_DIMS2[1]);
    centerM = viptrafficof_DW.SFunction_DIMS2[0];
  } else {
    if (viptrafficof_DW.SFunction_DIMS2[1] == 1) {
      maxNumBlobsReached = ((viptrafficof_DW.SFunction_DIMS2[0] >> 2) << 2 ==
                            viptrafficof_DW.SFunction_DIMS2[0]);
      centerM = 1;
    }
  }

  /* Copy the image from input to output. */
  memcpy(&viptrafficof_B.Assignment[0], &viptrafficof_B.FromMultimediaFile[0],
         57600U * sizeof(real32_T));
  if (maxNumBlobsReached && (centerM > 0)) {
    /* Update view port. */
    /* Draw all rectangles. */
    for (minc = 0; minc < centerM; minc++) {
      minr = rtb_y[minc + centerM] - 1;
      maxc = rtb_y[minc] - 1;
      maxr = (rtb_y[3 * centerM + minc] + minr) - 1;
      j_pixListNinc = (rtb_y[(centerM << 1) + minc] + maxc) - 1;
      if (viptrafficof_P.DrawShapes_lineWidth > 1) {
        loop = viptrafficof_P.DrawShapes_lineWidth >> 1;
        minr -= loop;
        maxr += loop;
        maxc -= loop;
        j_pixListNinc += loop;
      }

      if ((minr <= maxr) && (maxc <= j_pixListNinc)) {
        for (inIdx = 0; inIdx < viptrafficof_P.DrawShapes_lineWidth; inIdx++) {
          line_idx_0 = minr + inIdx;
          outIdx = minr + inIdx;
          maxNumBlobsReached = false;

          /* Find the visible portion of a line. */
          visited1 = false;
          visited2 = false;
          done = false;
          line_idx_0_0 = line_idx_0;
          line_idx_1 = maxc;
          line_idx_2 = outIdx;
          line_idx_3 = j_pixListNinc;
          while (!done) {
            stackIdx = 0U;
            pixIdx = 0U;

            /* Determine viewport violations. */
            if (line_idx_0_0 < 0) {
              stackIdx = 4U;
            } else {
              if (line_idx_0_0 > 119) {
                stackIdx = 8U;
              }
            }

            if (line_idx_2 < 0) {
              pixIdx = 4U;
            } else {
              if (line_idx_2 > 119) {
                pixIdx = 8U;
              }
            }

            if (line_idx_1 < 0) {
              stackIdx |= 1U;
            } else {
              if (line_idx_1 > 159) {
                stackIdx |= 2U;
              }
            }

            if (line_idx_3 < 0) {
              pixIdx |= 1U;
            } else {
              if (line_idx_3 > 159) {
                pixIdx |= 2U;
              }
            }

            if (!((stackIdx | pixIdx) != 0U)) {
              /* Line falls completely within bounds. */
              done = true;
              maxNumBlobsReached = true;
            } else if ((stackIdx & pixIdx) != 0U) {
              /* Line falls completely out of bounds. */
              done = true;
              maxNumBlobsReached = false;
            } else if (stackIdx != 0U) {
              /* Clip 1st point; if it's in-bounds, clip 2nd point. */
              if (visited1) {
                line_idx_0_0 = line_idx_0;
                line_idx_1 = maxc;
              }

              loop = line_idx_2 - line_idx_0_0;
              outRedIndx = line_idx_3 - line_idx_1;
              if ((loop > 1073741824) || (loop < -1073741824) || ((outRedIndx >
                    1073741824) || (outRedIndx < -1073741824))) {
                /* Possible Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
                visited1 = true;
              } else if ((stackIdx & 4U) != 0U) {
                /* Violated RMin. */
                colorIndx = -line_idx_0_0 * outRedIndx;
                if ((colorIndx > 1073741824) || (colorIndx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((colorIndx >= 0) && (loop >= 0)) || ((colorIndx < 0)
                            && (loop < 0))) {
                  line_idx_1 += (div_s32_floor(colorIndx << 1, loop) + 1) >> 1;
                } else {
                  line_idx_1 -= (div_s32_floor(-colorIndx << 1, loop) + 1) >> 1;
                }

                line_idx_0_0 = 0;
                visited1 = true;
              } else if ((stackIdx & 8U) != 0U) {
                /* Violated RMax. */
                colorIndx = (119 - line_idx_0_0) * outRedIndx;
                if ((colorIndx > 1073741824) || (colorIndx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((colorIndx >= 0) && (loop >= 0)) || ((colorIndx < 0)
                            && (loop < 0))) {
                  line_idx_1 += (div_s32_floor(colorIndx << 1, loop) + 1) >> 1;
                } else {
                  line_idx_1 -= (div_s32_floor(-colorIndx << 1, loop) + 1) >> 1;
                }

                line_idx_0_0 = 119;
                visited1 = true;
              } else if ((stackIdx & 1U) != 0U) {
                /* Violated CMin. */
                colorIndx = -line_idx_1 * loop;
                if ((colorIndx > 1073741824) || (colorIndx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((colorIndx >= 0) && (outRedIndx >= 0)) ||
                           ((colorIndx < 0) && (outRedIndx < 0))) {
                  line_idx_0_0 += (div_s32_floor(colorIndx << 1, outRedIndx) + 1)
                    >> 1;
                } else {
                  line_idx_0_0 -= (div_s32_floor(-colorIndx << 1, outRedIndx) +
                                   1) >> 1;
                }

                line_idx_1 = 0;
                visited1 = true;
              } else {
                /* Violated CMax. */
                colorIndx = (159 - line_idx_1) * loop;
                if ((colorIndx > 1073741824) || (colorIndx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((colorIndx >= 0) && (outRedIndx >= 0)) ||
                           ((colorIndx < 0) && (outRedIndx < 0))) {
                  line_idx_0_0 += (div_s32_floor(colorIndx << 1, outRedIndx) + 1)
                    >> 1;
                } else {
                  line_idx_0_0 -= (div_s32_floor(-colorIndx << 1, outRedIndx) +
                                   1) >> 1;
                }

                line_idx_1 = 159;
                visited1 = true;
              }
            } else {
              /* Clip the 2nd point. */
              if (visited2) {
                line_idx_2 = outIdx;
                line_idx_3 = j_pixListNinc;
              }

              loop = line_idx_2 - line_idx_0_0;
              outRedIndx = line_idx_3 - line_idx_1;
              if ((loop > 1073741824) || (loop < -1073741824) || ((outRedIndx >
                    1073741824) || (outRedIndx < -1073741824))) {
                /* Possible Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
                visited2 = true;
              } else if ((pixIdx & 4U) != 0U) {
                /* Violated RMin. */
                colorIndx = -line_idx_2 * outRedIndx;
                if ((colorIndx > 1073741824) || (colorIndx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((colorIndx >= 0) && (loop >= 0)) || ((colorIndx < 0)
                            && (loop < 0))) {
                  line_idx_3 += (div_s32_floor(colorIndx << 1, loop) + 1) >> 1;
                } else {
                  line_idx_3 -= (div_s32_floor(-colorIndx << 1, loop) + 1) >> 1;
                }

                line_idx_2 = 0;
                visited2 = true;
              } else if ((pixIdx & 8U) != 0U) {
                /* Violated RMax. */
                colorIndx = (119 - line_idx_2) * outRedIndx;
                if ((colorIndx > 1073741824) || (colorIndx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((colorIndx >= 0) && (loop >= 0)) || ((colorIndx < 0)
                            && (loop < 0))) {
                  line_idx_3 += (div_s32_floor(colorIndx << 1, loop) + 1) >> 1;
                } else {
                  line_idx_3 -= (div_s32_floor(-colorIndx << 1, loop) + 1) >> 1;
                }

                line_idx_2 = 119;
                visited2 = true;
              } else if ((pixIdx & 1U) != 0U) {
                /* Violated CMin. */
                colorIndx = -line_idx_3 * loop;
                if ((colorIndx > 1073741824) || (colorIndx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((colorIndx >= 0) && (outRedIndx >= 0)) ||
                           ((colorIndx < 0) && (outRedIndx < 0))) {
                  line_idx_2 += (div_s32_floor(colorIndx << 1, outRedIndx) + 1) >>
                    1;
                } else {
                  line_idx_2 -= (div_s32_floor(-colorIndx << 1, outRedIndx) + 1)
                    >> 1;
                }

                line_idx_3 = 0;
                visited2 = true;
              } else {
                /* Violated CMax. */
                colorIndx = (159 - line_idx_3) * loop;
                if ((colorIndx > 1073741824) || (colorIndx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((colorIndx >= 0) && (outRedIndx >= 0)) ||
                           ((colorIndx < 0) && (outRedIndx < 0))) {
                  line_idx_2 += (div_s32_floor(colorIndx << 1, outRedIndx) + 1) >>
                    1;
                } else {
                  line_idx_2 -= (div_s32_floor(-colorIndx << 1, outRedIndx) + 1)
                    >> 1;
                }

                line_idx_3 = 159;
                visited2 = true;
              }
            }
          }

          if (maxNumBlobsReached) {
            loop = line_idx_1 * 120 + line_idx_0_0;
            for (outRedIndx = line_idx_1; outRedIndx <= line_idx_3; outRedIndx++)
            {
              viptrafficof_B.Assignment[loop] =
                viptrafficof_P.DrawShapes_RTP_FILLCOLOR[0];
              line_idx_0 = loop + 19200;
              viptrafficof_B.Assignment[line_idx_0] =
                viptrafficof_P.DrawShapes_RTP_FILLCOLOR[1];
              line_idx_0 += 19200;
              viptrafficof_B.Assignment[line_idx_0] =
                viptrafficof_P.DrawShapes_RTP_FILLCOLOR[2];
              loop += 120;
            }
          }

          line_idx_1 = maxc + inIdx;
          line_idx_3 = maxc + inIdx;
          maxNumBlobsReached = false;

          /* Find the visible portion of a line. */
          visited1 = false;
          visited2 = false;
          done = false;
          line_idx_0 = minr;
          line_idx_0_0 = line_idx_1;
          outIdx = maxr;
          line_idx_2 = line_idx_3;
          while (!done) {
            stackIdx = 0U;
            pixIdx = 0U;

            /* Determine viewport violations. */
            if (line_idx_0 < 0) {
              stackIdx = 4U;
            } else {
              if (line_idx_0 > 119) {
                stackIdx = 8U;
              }
            }

            if (outIdx < 0) {
              pixIdx = 4U;
            } else {
              if (outIdx > 119) {
                pixIdx = 8U;
              }
            }

            if (line_idx_0_0 < 0) {
              stackIdx |= 1U;
            } else {
              if (line_idx_0_0 > 159) {
                stackIdx |= 2U;
              }
            }

            if (line_idx_2 < 0) {
              pixIdx |= 1U;
            } else {
              if (line_idx_2 > 159) {
                pixIdx |= 2U;
              }
            }

            if (!((stackIdx | pixIdx) != 0U)) {
              /* Line falls completely within bounds. */
              done = true;
              maxNumBlobsReached = true;
            } else if ((stackIdx & pixIdx) != 0U) {
              /* Line falls completely out of bounds. */
              done = true;
              maxNumBlobsReached = false;
            } else if (stackIdx != 0U) {
              /* Clip 1st point; if it's in-bounds, clip 2nd point. */
              if (visited1) {
                line_idx_0 = minr;
                line_idx_0_0 = line_idx_1;
              }

              loop = outIdx - line_idx_0;
              outRedIndx = line_idx_2 - line_idx_0_0;
              if ((loop > 1073741824) || (loop < -1073741824) || ((outRedIndx >
                    1073741824) || (outRedIndx < -1073741824))) {
                /* Possible Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
                visited1 = true;
              } else if ((stackIdx & 4U) != 0U) {
                /* Violated RMin. */
                colorIndx = -line_idx_0 * outRedIndx;
                if ((colorIndx > 1073741824) || (colorIndx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((colorIndx >= 0) && (loop >= 0)) || ((colorIndx < 0)
                            && (loop < 0))) {
                  line_idx_0_0 += (div_s32_floor(colorIndx << 1, loop) + 1) >> 1;
                } else {
                  line_idx_0_0 -= (div_s32_floor(-colorIndx << 1, loop) + 1) >>
                    1;
                }

                line_idx_0 = 0;
                visited1 = true;
              } else if ((stackIdx & 8U) != 0U) {
                /* Violated RMax. */
                colorIndx = (119 - line_idx_0) * outRedIndx;
                if ((colorIndx > 1073741824) || (colorIndx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((colorIndx >= 0) && (loop >= 0)) || ((colorIndx < 0)
                            && (loop < 0))) {
                  line_idx_0_0 += (div_s32_floor(colorIndx << 1, loop) + 1) >> 1;
                } else {
                  line_idx_0_0 -= (div_s32_floor(-colorIndx << 1, loop) + 1) >>
                    1;
                }

                line_idx_0 = 119;
                visited1 = true;
              } else if ((stackIdx & 1U) != 0U) {
                /* Violated CMin. */
                colorIndx = -line_idx_0_0 * loop;
                if ((colorIndx > 1073741824) || (colorIndx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((colorIndx >= 0) && (outRedIndx >= 0)) ||
                           ((colorIndx < 0) && (outRedIndx < 0))) {
                  line_idx_0 += (div_s32_floor(colorIndx << 1, outRedIndx) + 1) >>
                    1;
                } else {
                  line_idx_0 -= (div_s32_floor(-colorIndx << 1, outRedIndx) + 1)
                    >> 1;
                }

                line_idx_0_0 = 0;
                visited1 = true;
              } else {
                /* Violated CMax. */
                colorIndx = (159 - line_idx_0_0) * loop;
                if ((colorIndx > 1073741824) || (colorIndx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((colorIndx >= 0) && (outRedIndx >= 0)) ||
                           ((colorIndx < 0) && (outRedIndx < 0))) {
                  line_idx_0 += (div_s32_floor(colorIndx << 1, outRedIndx) + 1) >>
                    1;
                } else {
                  line_idx_0 -= (div_s32_floor(-colorIndx << 1, outRedIndx) + 1)
                    >> 1;
                }

                line_idx_0_0 = 159;
                visited1 = true;
              }
            } else {
              /* Clip the 2nd point. */
              if (visited2) {
                outIdx = maxr;
                line_idx_2 = line_idx_3;
              }

              loop = outIdx - line_idx_0;
              outRedIndx = line_idx_2 - line_idx_0_0;
              if ((loop > 1073741824) || (loop < -1073741824) || ((outRedIndx >
                    1073741824) || (outRedIndx < -1073741824))) {
                /* Possible Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
                visited2 = true;
              } else if ((pixIdx & 4U) != 0U) {
                /* Violated RMin. */
                colorIndx = -outIdx * outRedIndx;
                if ((colorIndx > 1073741824) || (colorIndx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((colorIndx >= 0) && (loop >= 0)) || ((colorIndx < 0)
                            && (loop < 0))) {
                  line_idx_2 += (div_s32_floor(colorIndx << 1, loop) + 1) >> 1;
                } else {
                  line_idx_2 -= (div_s32_floor(-colorIndx << 1, loop) + 1) >> 1;
                }

                outIdx = 0;
                visited2 = true;
              } else if ((pixIdx & 8U) != 0U) {
                /* Violated RMax. */
                colorIndx = (119 - outIdx) * outRedIndx;
                if ((colorIndx > 1073741824) || (colorIndx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((colorIndx >= 0) && (loop >= 0)) || ((colorIndx < 0)
                            && (loop < 0))) {
                  line_idx_2 += (div_s32_floor(colorIndx << 1, loop) + 1) >> 1;
                } else {
                  line_idx_2 -= (div_s32_floor(-colorIndx << 1, loop) + 1) >> 1;
                }

                outIdx = 119;
                visited2 = true;
              } else if ((pixIdx & 1U) != 0U) {
                /* Violated CMin. */
                colorIndx = -line_idx_2 * loop;
                if ((colorIndx > 1073741824) || (colorIndx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((colorIndx >= 0) && (outRedIndx >= 0)) ||
                           ((colorIndx < 0) && (outRedIndx < 0))) {
                  outIdx += (div_s32_floor(colorIndx << 1, outRedIndx) + 1) >> 1;
                } else {
                  outIdx -= (div_s32_floor(-colorIndx << 1, outRedIndx) + 1) >>
                    1;
                }

                line_idx_2 = 0;
                visited2 = true;
              } else {
                /* Violated CMax. */
                colorIndx = (159 - line_idx_2) * loop;
                if ((colorIndx > 1073741824) || (colorIndx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((colorIndx >= 0) && (outRedIndx >= 0)) ||
                           ((colorIndx < 0) && (outRedIndx < 0))) {
                  outIdx += (div_s32_floor(colorIndx << 1, outRedIndx) + 1) >> 1;
                } else {
                  outIdx -= (div_s32_floor(-colorIndx << 1, outRedIndx) + 1) >>
                    1;
                }

                line_idx_2 = 159;
                visited2 = true;
              }
            }
          }

          if (maxNumBlobsReached) {
            loop = line_idx_0_0 * 120 + line_idx_0;
            for (outRedIndx = line_idx_0; outRedIndx <= outIdx; outRedIndx++) {
              viptrafficof_B.Assignment[loop] =
                viptrafficof_P.DrawShapes_RTP_FILLCOLOR[0];
              line_idx_0 = loop + 19200;
              viptrafficof_B.Assignment[line_idx_0] =
                viptrafficof_P.DrawShapes_RTP_FILLCOLOR[1];
              line_idx_0 += 19200;
              viptrafficof_B.Assignment[line_idx_0] =
                viptrafficof_P.DrawShapes_RTP_FILLCOLOR[2];
              loop++;
            }
          }

          line_idx_0 = maxr - inIdx;
          outIdx = maxr - inIdx;
          maxNumBlobsReached = false;

          /* Find the visible portion of a line. */
          visited1 = false;
          visited2 = false;
          done = false;
          line_idx_0_0 = line_idx_0;
          line_idx_1 = maxc;
          line_idx_2 = outIdx;
          line_idx_3 = j_pixListNinc;
          while (!done) {
            stackIdx = 0U;
            pixIdx = 0U;

            /* Determine viewport violations. */
            if (line_idx_0_0 < 0) {
              stackIdx = 4U;
            } else {
              if (line_idx_0_0 > 119) {
                stackIdx = 8U;
              }
            }

            if (line_idx_2 < 0) {
              pixIdx = 4U;
            } else {
              if (line_idx_2 > 119) {
                pixIdx = 8U;
              }
            }

            if (line_idx_1 < 0) {
              stackIdx |= 1U;
            } else {
              if (line_idx_1 > 159) {
                stackIdx |= 2U;
              }
            }

            if (line_idx_3 < 0) {
              pixIdx |= 1U;
            } else {
              if (line_idx_3 > 159) {
                pixIdx |= 2U;
              }
            }

            if (!((stackIdx | pixIdx) != 0U)) {
              /* Line falls completely within bounds. */
              done = true;
              maxNumBlobsReached = true;
            } else if ((stackIdx & pixIdx) != 0U) {
              /* Line falls completely out of bounds. */
              done = true;
              maxNumBlobsReached = false;
            } else if (stackIdx != 0U) {
              /* Clip 1st point; if it's in-bounds, clip 2nd point. */
              if (visited1) {
                line_idx_0_0 = line_idx_0;
                line_idx_1 = maxc;
              }

              loop = line_idx_2 - line_idx_0_0;
              outRedIndx = line_idx_3 - line_idx_1;
              if ((loop > 1073741824) || (loop < -1073741824) || ((outRedIndx >
                    1073741824) || (outRedIndx < -1073741824))) {
                /* Possible Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
                visited1 = true;
              } else if ((stackIdx & 4U) != 0U) {
                /* Violated RMin. */
                colorIndx = -line_idx_0_0 * outRedIndx;
                if ((colorIndx > 1073741824) || (colorIndx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((colorIndx >= 0) && (loop >= 0)) || ((colorIndx < 0)
                            && (loop < 0))) {
                  line_idx_1 += (div_s32_floor(colorIndx << 1, loop) + 1) >> 1;
                } else {
                  line_idx_1 -= (div_s32_floor(-colorIndx << 1, loop) + 1) >> 1;
                }

                line_idx_0_0 = 0;
                visited1 = true;
              } else if ((stackIdx & 8U) != 0U) {
                /* Violated RMax. */
                colorIndx = (119 - line_idx_0_0) * outRedIndx;
                if ((colorIndx > 1073741824) || (colorIndx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((colorIndx >= 0) && (loop >= 0)) || ((colorIndx < 0)
                            && (loop < 0))) {
                  line_idx_1 += (div_s32_floor(colorIndx << 1, loop) + 1) >> 1;
                } else {
                  line_idx_1 -= (div_s32_floor(-colorIndx << 1, loop) + 1) >> 1;
                }

                line_idx_0_0 = 119;
                visited1 = true;
              } else if ((stackIdx & 1U) != 0U) {
                /* Violated CMin. */
                colorIndx = -line_idx_1 * loop;
                if ((colorIndx > 1073741824) || (colorIndx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((colorIndx >= 0) && (outRedIndx >= 0)) ||
                           ((colorIndx < 0) && (outRedIndx < 0))) {
                  line_idx_0_0 += (div_s32_floor(colorIndx << 1, outRedIndx) + 1)
                    >> 1;
                } else {
                  line_idx_0_0 -= (div_s32_floor(-colorIndx << 1, outRedIndx) +
                                   1) >> 1;
                }

                line_idx_1 = 0;
                visited1 = true;
              } else {
                /* Violated CMax. */
                colorIndx = (159 - line_idx_1) * loop;
                if ((colorIndx > 1073741824) || (colorIndx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((colorIndx >= 0) && (outRedIndx >= 0)) ||
                           ((colorIndx < 0) && (outRedIndx < 0))) {
                  line_idx_0_0 += (div_s32_floor(colorIndx << 1, outRedIndx) + 1)
                    >> 1;
                } else {
                  line_idx_0_0 -= (div_s32_floor(-colorIndx << 1, outRedIndx) +
                                   1) >> 1;
                }

                line_idx_1 = 159;
                visited1 = true;
              }
            } else {
              /* Clip the 2nd point. */
              if (visited2) {
                line_idx_2 = outIdx;
                line_idx_3 = j_pixListNinc;
              }

              loop = line_idx_2 - line_idx_0_0;
              outRedIndx = line_idx_3 - line_idx_1;
              if ((loop > 1073741824) || (loop < -1073741824) || ((outRedIndx >
                    1073741824) || (outRedIndx < -1073741824))) {
                /* Possible Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
                visited2 = true;
              } else if ((pixIdx & 4U) != 0U) {
                /* Violated RMin. */
                colorIndx = -line_idx_2 * outRedIndx;
                if ((colorIndx > 1073741824) || (colorIndx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((colorIndx >= 0) && (loop >= 0)) || ((colorIndx < 0)
                            && (loop < 0))) {
                  line_idx_3 += (div_s32_floor(colorIndx << 1, loop) + 1) >> 1;
                } else {
                  line_idx_3 -= (div_s32_floor(-colorIndx << 1, loop) + 1) >> 1;
                }

                line_idx_2 = 0;
                visited2 = true;
              } else if ((pixIdx & 8U) != 0U) {
                /* Violated RMax. */
                colorIndx = (119 - line_idx_2) * outRedIndx;
                if ((colorIndx > 1073741824) || (colorIndx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((colorIndx >= 0) && (loop >= 0)) || ((colorIndx < 0)
                            && (loop < 0))) {
                  line_idx_3 += (div_s32_floor(colorIndx << 1, loop) + 1) >> 1;
                } else {
                  line_idx_3 -= (div_s32_floor(-colorIndx << 1, loop) + 1) >> 1;
                }

                line_idx_2 = 119;
                visited2 = true;
              } else if ((pixIdx & 1U) != 0U) {
                /* Violated CMin. */
                colorIndx = -line_idx_3 * loop;
                if ((colorIndx > 1073741824) || (colorIndx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((colorIndx >= 0) && (outRedIndx >= 0)) ||
                           ((colorIndx < 0) && (outRedIndx < 0))) {
                  line_idx_2 += (div_s32_floor(colorIndx << 1, outRedIndx) + 1) >>
                    1;
                } else {
                  line_idx_2 -= (div_s32_floor(-colorIndx << 1, outRedIndx) + 1)
                    >> 1;
                }

                line_idx_3 = 0;
                visited2 = true;
              } else {
                /* Violated CMax. */
                colorIndx = (159 - line_idx_3) * loop;
                if ((colorIndx > 1073741824) || (colorIndx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((colorIndx >= 0) && (outRedIndx >= 0)) ||
                           ((colorIndx < 0) && (outRedIndx < 0))) {
                  line_idx_2 += (div_s32_floor(colorIndx << 1, outRedIndx) + 1) >>
                    1;
                } else {
                  line_idx_2 -= (div_s32_floor(-colorIndx << 1, outRedIndx) + 1)
                    >> 1;
                }

                line_idx_3 = 159;
                visited2 = true;
              }
            }
          }

          if (maxNumBlobsReached) {
            loop = line_idx_1 * 120 + line_idx_0_0;
            for (outRedIndx = line_idx_1; outRedIndx <= line_idx_3; outRedIndx++)
            {
              viptrafficof_B.Assignment[loop] =
                viptrafficof_P.DrawShapes_RTP_FILLCOLOR[0];
              line_idx_0 = loop + 19200;
              viptrafficof_B.Assignment[line_idx_0] =
                viptrafficof_P.DrawShapes_RTP_FILLCOLOR[1];
              line_idx_0 += 19200;
              viptrafficof_B.Assignment[line_idx_0] =
                viptrafficof_P.DrawShapes_RTP_FILLCOLOR[2];
              loop += 120;
            }
          }

          line_idx_1 = j_pixListNinc - inIdx;
          line_idx_3 = j_pixListNinc - inIdx;
          maxNumBlobsReached = false;

          /* Find the visible portion of a line. */
          visited1 = false;
          visited2 = false;
          done = false;
          line_idx_0 = minr;
          line_idx_0_0 = line_idx_1;
          outIdx = maxr;
          line_idx_2 = line_idx_3;
          while (!done) {
            stackIdx = 0U;
            pixIdx = 0U;

            /* Determine viewport violations. */
            if (line_idx_0 < 0) {
              stackIdx = 4U;
            } else {
              if (line_idx_0 > 119) {
                stackIdx = 8U;
              }
            }

            if (outIdx < 0) {
              pixIdx = 4U;
            } else {
              if (outIdx > 119) {
                pixIdx = 8U;
              }
            }

            if (line_idx_0_0 < 0) {
              stackIdx |= 1U;
            } else {
              if (line_idx_0_0 > 159) {
                stackIdx |= 2U;
              }
            }

            if (line_idx_2 < 0) {
              pixIdx |= 1U;
            } else {
              if (line_idx_2 > 159) {
                pixIdx |= 2U;
              }
            }

            if (!((stackIdx | pixIdx) != 0U)) {
              /* Line falls completely within bounds. */
              done = true;
              maxNumBlobsReached = true;
            } else if ((stackIdx & pixIdx) != 0U) {
              /* Line falls completely out of bounds. */
              done = true;
              maxNumBlobsReached = false;
            } else if (stackIdx != 0U) {
              /* Clip 1st point; if it's in-bounds, clip 2nd point. */
              if (visited1) {
                line_idx_0 = minr;
                line_idx_0_0 = line_idx_1;
              }

              loop = outIdx - line_idx_0;
              outRedIndx = line_idx_2 - line_idx_0_0;
              if ((loop > 1073741824) || (loop < -1073741824) || ((outRedIndx >
                    1073741824) || (outRedIndx < -1073741824))) {
                /* Possible Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
                visited1 = true;
              } else if ((stackIdx & 4U) != 0U) {
                /* Violated RMin. */
                colorIndx = -line_idx_0 * outRedIndx;
                if ((colorIndx > 1073741824) || (colorIndx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((colorIndx >= 0) && (loop >= 0)) || ((colorIndx < 0)
                            && (loop < 0))) {
                  line_idx_0_0 += (div_s32_floor(colorIndx << 1, loop) + 1) >> 1;
                } else {
                  line_idx_0_0 -= (div_s32_floor(-colorIndx << 1, loop) + 1) >>
                    1;
                }

                line_idx_0 = 0;
                visited1 = true;
              } else if ((stackIdx & 8U) != 0U) {
                /* Violated RMax. */
                colorIndx = (119 - line_idx_0) * outRedIndx;
                if ((colorIndx > 1073741824) || (colorIndx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((colorIndx >= 0) && (loop >= 0)) || ((colorIndx < 0)
                            && (loop < 0))) {
                  line_idx_0_0 += (div_s32_floor(colorIndx << 1, loop) + 1) >> 1;
                } else {
                  line_idx_0_0 -= (div_s32_floor(-colorIndx << 1, loop) + 1) >>
                    1;
                }

                line_idx_0 = 119;
                visited1 = true;
              } else if ((stackIdx & 1U) != 0U) {
                /* Violated CMin. */
                colorIndx = -line_idx_0_0 * loop;
                if ((colorIndx > 1073741824) || (colorIndx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((colorIndx >= 0) && (outRedIndx >= 0)) ||
                           ((colorIndx < 0) && (outRedIndx < 0))) {
                  line_idx_0 += (div_s32_floor(colorIndx << 1, outRedIndx) + 1) >>
                    1;
                } else {
                  line_idx_0 -= (div_s32_floor(-colorIndx << 1, outRedIndx) + 1)
                    >> 1;
                }

                line_idx_0_0 = 0;
                visited1 = true;
              } else {
                /* Violated CMax. */
                colorIndx = (159 - line_idx_0_0) * loop;
                if ((colorIndx > 1073741824) || (colorIndx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((colorIndx >= 0) && (outRedIndx >= 0)) ||
                           ((colorIndx < 0) && (outRedIndx < 0))) {
                  line_idx_0 += (div_s32_floor(colorIndx << 1, outRedIndx) + 1) >>
                    1;
                } else {
                  line_idx_0 -= (div_s32_floor(-colorIndx << 1, outRedIndx) + 1)
                    >> 1;
                }

                line_idx_0_0 = 159;
                visited1 = true;
              }
            } else {
              /* Clip the 2nd point. */
              if (visited2) {
                outIdx = maxr;
                line_idx_2 = line_idx_3;
              }

              loop = outIdx - line_idx_0;
              outRedIndx = line_idx_2 - line_idx_0_0;
              if ((loop > 1073741824) || (loop < -1073741824) || ((outRedIndx >
                    1073741824) || (outRedIndx < -1073741824))) {
                /* Possible Inf or Nan. */
                done = true;
                maxNumBlobsReached = false;
                visited2 = true;
              } else if ((pixIdx & 4U) != 0U) {
                /* Violated RMin. */
                colorIndx = -outIdx * outRedIndx;
                if ((colorIndx > 1073741824) || (colorIndx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((colorIndx >= 0) && (loop >= 0)) || ((colorIndx < 0)
                            && (loop < 0))) {
                  line_idx_2 += (div_s32_floor(colorIndx << 1, loop) + 1) >> 1;
                } else {
                  line_idx_2 -= (div_s32_floor(-colorIndx << 1, loop) + 1) >> 1;
                }

                outIdx = 0;
                visited2 = true;
              } else if ((pixIdx & 8U) != 0U) {
                /* Violated RMax. */
                colorIndx = (119 - outIdx) * outRedIndx;
                if ((colorIndx > 1073741824) || (colorIndx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((colorIndx >= 0) && (loop >= 0)) || ((colorIndx < 0)
                            && (loop < 0))) {
                  line_idx_2 += (div_s32_floor(colorIndx << 1, loop) + 1) >> 1;
                } else {
                  line_idx_2 -= (div_s32_floor(-colorIndx << 1, loop) + 1) >> 1;
                }

                outIdx = 119;
                visited2 = true;
              } else if ((pixIdx & 1U) != 0U) {
                /* Violated CMin. */
                colorIndx = -line_idx_2 * loop;
                if ((colorIndx > 1073741824) || (colorIndx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((colorIndx >= 0) && (outRedIndx >= 0)) ||
                           ((colorIndx < 0) && (outRedIndx < 0))) {
                  outIdx += (div_s32_floor(colorIndx << 1, outRedIndx) + 1) >> 1;
                } else {
                  outIdx -= (div_s32_floor(-colorIndx << 1, outRedIndx) + 1) >>
                    1;
                }

                line_idx_2 = 0;
                visited2 = true;
              } else {
                /* Violated CMax. */
                colorIndx = (159 - line_idx_2) * loop;
                if ((colorIndx > 1073741824) || (colorIndx < -1073741824)) {
                  /* Check for Inf or Nan. */
                  done = true;
                  maxNumBlobsReached = false;
                } else if (((colorIndx >= 0) && (outRedIndx >= 0)) ||
                           ((colorIndx < 0) && (outRedIndx < 0))) {
                  outIdx += (div_s32_floor(colorIndx << 1, outRedIndx) + 1) >> 1;
                } else {
                  outIdx -= (div_s32_floor(-colorIndx << 1, outRedIndx) + 1) >>
                    1;
                }

                line_idx_2 = 159;
                visited2 = true;
              }
            }
          }

          if (maxNumBlobsReached) {
            loop = line_idx_0_0 * 120 + line_idx_0;
            for (outRedIndx = line_idx_0; outRedIndx <= outIdx; outRedIndx++) {
              viptrafficof_B.Assignment[loop] =
                viptrafficof_P.DrawShapes_RTP_FILLCOLOR[0];
              line_idx_0 = loop + 19200;
              viptrafficof_B.Assignment[line_idx_0] =
                viptrafficof_P.DrawShapes_RTP_FILLCOLOR[1];
              line_idx_0 += 19200;
              viptrafficof_B.Assignment[line_idx_0] =
                viptrafficof_P.DrawShapes_RTP_FILLCOLOR[2];
              loop++;
            }
          }
        }
      }
    }
  }

  /* End of S-Function (svipdrawshapes): '<S4>/Draw Shapes' */

  /* Assignment: '<S4>/Assignment' incorporates:
   *  Constant: '<S4>/Constant'
   */
  for (loop = 0; loop < 3; loop++) {
    for (centerM = 0; centerM < 160; centerM++) {
      viptrafficof_B.Assignment[(120 * centerM + 19200 * loop) + 21] =
        viptrafficof_P.Constant_Value;
      viptrafficof_B.Assignment[(120 * centerM + 19200 * loop) + 22] =
        viptrafficof_P.Constant_Value;
    }
  }

  /* End of Assignment: '<S4>/Assignment' */

  /* Assignment: '<S4>/Assignment1' incorporates:
   *  Constant: '<S4>/Constant1'
   */
  memcpy(&viptrafficof_B.Assignment1[0], &viptrafficof_B.Assignment[0], 57600U *
         sizeof(real32_T));
  for (loop = 0; loop < 3; loop++) {
    for (centerM = 0; centerM < 30; centerM++) {
      for (maxc = 0; maxc < 15; maxc++) {
        viptrafficof_B.Assignment1[(maxc + 120 * centerM) + 19200 * loop] =
          viptrafficof_P.Constant1_Value;
      }
    }
  }

  /* End of Assignment: '<S4>/Assignment1' */

  /* Probe: '<S4>/Probe' */
  viptrafficof_B.Probe[0] = viptrafficof_DW.SFunction_DIMS2[0];
  viptrafficof_B.Probe[1] = viptrafficof_DW.SFunction_DIMS2[1];

  /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
   *  Selector: '<S4>/Selector'
   */
  tmp = floor(viptrafficof_B.Probe[0]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  viptrafficof_B.DataTypeConversion = (uint8_T)(tmp < 0.0 ? (int32_T)(uint8_T)
    -(int8_T)(uint8_T)-tmp : (int32_T)(uint8_T)tmp);

  /* End of DataTypeConversion: '<S4>/Data Type Conversion' */

  /* S-Function (sviptextrender): '<S4>/Insert Text' */
  /* put the pen at the beginning of the string */
  outIdx = 1;

  /* copy input to output since Simulink isn't giving us in-place operation */
  memcpy(&viptrafficof_B.InsertText[0], &viptrafficof_B.Assignment1[0], 57600U *
         sizeof(real32_T));
  while (outIdx > 0) {
    maxNumBlobsReached = true;
    if (viptrafficof_P.InsertText_textOpacity == 0.0F) {
      maxNumBlobsReached = false;
    }

    /* copy location to int32 container */
    minc = viptrafficof_P.InsertText_textLoc[0] - 1;

    /* update the color/intensity */
    viptrafficof_DW.InsertText_colorVectorDW[0] =
      viptrafficof_P.InsertText_textColor[0];

    /* Saturate color values */
    if (viptrafficof_DW.InsertText_colorVectorDW[0] < 0.0F) {
      viptrafficof_DW.InsertText_colorVectorDW[0] = 0.0F;
    } else {
      if (viptrafficof_DW.InsertText_colorVectorDW[0] > 1.0F) {
        viptrafficof_DW.InsertText_colorVectorDW[0] = 1.0F;
      }
    }

    viptrafficof_DW.InsertText_colorVectorDW[1] =
      viptrafficof_P.InsertText_textColor[1];

    /* Saturate color values */
    if (viptrafficof_DW.InsertText_colorVectorDW[1] < 0.0F) {
      viptrafficof_DW.InsertText_colorVectorDW[1] = 0.0F;
    } else {
      if (viptrafficof_DW.InsertText_colorVectorDW[1] > 1.0F) {
        viptrafficof_DW.InsertText_colorVectorDW[1] = 1.0F;
      }
    }

    viptrafficof_DW.InsertText_colorVectorDW[2] =
      viptrafficof_P.InsertText_textColor[2];

    /* Saturate color values */
    if (viptrafficof_DW.InsertText_colorVectorDW[2] < 0.0F) {
      viptrafficof_DW.InsertText_colorVectorDW[2] = 0.0F;
    } else {
      if (viptrafficof_DW.InsertText_colorVectorDW[2] > 1.0F) {
        viptrafficof_DW.InsertText_colorVectorDW[2] = 1.0F;
      }
    }

    viptrafficof_DW.InsertText_VarHolder[0] = viptrafficof_B.DataTypeConversion;
    viptrafficof_DW.InsertText_VarHolder[1] = viptrafficof_B.DataTypeConversion;
    MWVIP_snprintf_wrapper(&viptrafficof_DW.InsertText_RepBuf[0U],
      &viptrafficof_DW.InsertText_StringDataDW[0],
      &viptrafficof_DW.InsertText_VarHolder[0U], 2, 3, false, 29);
    loop = MWVIP_strlen(&viptrafficof_DW.InsertText_RepBuf[0]);
    outIdx = 0;
    if (maxNumBlobsReached) {
      /* put the pen at the beginning of the string */
      maxc = minc;
      maxr = viptrafficof_P.InsertText_textLoc[1];
      for (centerM = 0; centerM < loop; centerM++) {
        if (viptrafficof_DW.InsertText_RepBuf[centerM] == 10) {
          maxr += 14;
          maxc = minc;
        } else {
          j_pixListNinc = viptrafficof_DW.InsertText_RepBuf[centerM];
          inIdx = (int32_T)
            viptrafficof_ConstP.InsertText_GlyIndexes[j_pixListNinc];
          if (!((viptrafficof_ConstP.InsertText_GlyWidths[j_pixListNinc] != 0) &&
                (viptrafficof_ConstP.InsertText_GlyHeights[j_pixListNinc] != 0) &&
                (viptrafficof_ConstP.InsertText_GlyXAdvances[j_pixListNinc] != 0)))
          {
            j_pixListNinc = 32;
            inIdx = 0;
          }

          opacityVal = viptrafficof_P.InsertText_textOpacity;
          MWVIP_DrawText_I_single_AA
            (&viptrafficof_ConstP.InsertText_GlyData[inIdx], maxc, maxr + 10,
             viptrafficof_ConstP.InsertText_GlyLBearings[j_pixListNinc],
             viptrafficof_ConstP.InsertText_GlyTBearings[j_pixListNinc],
             viptrafficof_ConstP.InsertText_GlyWidths[j_pixListNinc],
             viptrafficof_ConstP.InsertText_GlyHeights[j_pixListNinc], 160U,
             120U, &viptrafficof_B.InsertText[0],
             &viptrafficof_DW.InsertText_colorVectorDW[0], &opacityVal, false);
          MWVIP_DrawText_I_single_AA
            (&viptrafficof_ConstP.InsertText_GlyData[inIdx], maxc, maxr + 10,
             viptrafficof_ConstP.InsertText_GlyLBearings[j_pixListNinc],
             viptrafficof_ConstP.InsertText_GlyTBearings[j_pixListNinc],
             viptrafficof_ConstP.InsertText_GlyWidths[j_pixListNinc],
             viptrafficof_ConstP.InsertText_GlyHeights[j_pixListNinc], 160U,
             120U, &viptrafficof_B.InsertText[19200],
             &viptrafficof_DW.InsertText_colorVectorDW[1], &opacityVal, false);
          MWVIP_DrawText_I_single_AA
            (&viptrafficof_ConstP.InsertText_GlyData[inIdx], maxc, maxr + 10,
             viptrafficof_ConstP.InsertText_GlyLBearings[j_pixListNinc],
             viptrafficof_ConstP.InsertText_GlyTBearings[j_pixListNinc],
             viptrafficof_ConstP.InsertText_GlyWidths[j_pixListNinc],
             viptrafficof_ConstP.InsertText_GlyHeights[j_pixListNinc], 160U,
             120U, &viptrafficof_B.InsertText[38400],
             &viptrafficof_DW.InsertText_colorVectorDW[2], &opacityVal, false);
          maxc += viptrafficof_ConstP.InsertText_GlyXAdvances[j_pixListNinc];
        }
      }
    }
  }

  /* End of S-Function (sviptextrender): '<S4>/Insert Text' */

  /* MATLAB Function: '<S5>/Optical Flow Lines' */
  /* MATLAB Function 'Display Results/Optical Flow Lines/Optical Flow Lines': '<S6>:1' */
  /*  Generates the coordinate points of optical flow lines */
  if (!viptrafficof_DW.first_time_not_empty) {
    /* '<S6>:1:10' */
    viptrafficof_DW.first_time_not_empty = true;

    /*     %% user may change the following three parameters */
    /*     %% */
    /* '<S6>:1:20' */
    viptrafficof_meshgrid(viptrafficof_DW.CV, viptrafficof_DW.RV,
                          viptrafficof_DW.Y, viptrafficof_DW.X);

    /* '<S6>:1:20' */
  }

  /* End of MATLAB Function: '<S5>/Optical Flow Lines' */
  /* '<S6>:1:23' */
  /* '<S6>:1:24' */
  /* '<S6>:1:25' */
}

/* Model update function */
static void viptrafficof_update(void)
{
  /* Update for Delay: '<S2>/Delay' */
  memcpy(&viptrafficof_DW.Delay_DSTATE[0], &viptrafficof_B.ColorSpaceConversion
         [0], 19200U * sizeof(real32_T));

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++viptrafficof_M->Timing.clockTick0)) {
    ++viptrafficof_M->Timing.clockTickH0;
  }

  viptrafficof_M->Timing.t[0] = viptrafficof_M->Timing.clockTick0 *
    viptrafficof_M->Timing.stepSize0 + viptrafficof_M->Timing.clockTickH0 *
    viptrafficof_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void viptrafficof_initialize(void)
{
  {
    char_T *sErr;
    int32_T idxNHood;
    int32_T idxOffsets;
    int32_T curNumNonZ;
    int32_T n;
    int32_T m;

    /* Start for S-Function (sdspwmmfi2): '<Root>/From Multimedia File' */
    sErr = GetErrorBuffer(&viptrafficof_DW.FromMultimediaFile_HostLib[0U]);
    CreateHostLibrary("frommmfile.dll",
                      &viptrafficof_DW.FromMultimediaFile_HostLib[0U]);
    createAudioInfo(&viptrafficof_DW.FromMultimediaFile_AudioInfo[0U], 0U, 0U,
                    0.0, 0, 0, 0, 0, 0);
    createVideoInfo(&viptrafficof_DW.FromMultimediaFile_VideoInfo[0U], 1U, 15.0,
                    15.000015000015, "RGB ", 1, 3, 160, 120, 0U, 1, 1, 0);
    if (*sErr == 0) {
      LibCreate_FromMMFile(&viptrafficof_DW.FromMultimediaFile_HostLib[0U], 0,
                           (void *)
                           "C:\\Program Files\\MATLAB\\R2016a\\toolbox\\vision\\visiondata\\viptraffic.avi",
                           1, "", "",
                           &viptrafficof_DW.FromMultimediaFile_AudioInfo[0U],
                           &viptrafficof_DW.FromMultimediaFile_VideoInfo[0U], 0U,
                           1U, 1U, 0U, 0U);
    }

    if (*sErr == 0) {
      LibStart(&viptrafficof_DW.FromMultimediaFile_HostLib[0U]);
    }

    if (*sErr != 0) {
      DestroyHostLibrary(&viptrafficof_DW.FromMultimediaFile_HostLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(viptrafficof_M, sErr);
        rtmSetStopRequested(viptrafficof_M, 1);
      }
    }

    /* End of Start for S-Function (sdspwmmfi2): '<Root>/From Multimedia File' */

    /* Start for S-Function (svipmorphop): '<S3>/Closing' */
    idxNHood = 0;
    idxOffsets = 0;
    curNumNonZ = 0;
    for (n = 0; n < 5; n++) {
      for (m = 0; m < 5; m++) {
        if (viptrafficof_ConstP.Closing_NHOOD_RTP[idxNHood]) {
          viptrafficof_DW.Closing_ERODE_OFF_DW[idxOffsets] = n * 129 + m;
          curNumNonZ++;
          idxOffsets++;
        }

        idxNHood++;
      }
    }

    viptrafficof_DW.Closing_NUMNONZ_DW = curNumNonZ;
    idxNHood = 0;
    idxOffsets = 0;
    curNumNonZ = 0;
    for (n = 0; n < 5; n++) {
      for (m = 0; m < 5; m++) {
        if (viptrafficof_ConstP.Closing_NHOOD_RTP[idxNHood]) {
          viptrafficof_DW.Closing_DILATE_OFF_DW[idxOffsets] = n * 129 + m;
          curNumNonZ++;
          idxOffsets++;
        }

        idxNHood++;
      }
    }

    viptrafficof_DW.Closing_NUMNONZ_DW = curNumNonZ;

    /* End of Start for S-Function (svipmorphop): '<S3>/Closing' */

    /* Start for S-Function (sviptextrender): '<S4>/Insert Text' */
    viptrafficof_DW.InsertText_StringDataDW[0] = 37U;
    viptrafficof_DW.InsertText_StringDataDW[1] = 52U;
    viptrafficof_DW.InsertText_StringDataDW[2] = 100U;
    viptrafficof_DW.InsertText_StringDataDW[3] = 0U;
  }

  {
    int32_T i;

    /* InitializeConditions for S-Function (sdspwmmfi2): '<Root>/From Multimedia File' */
    LibReset(&viptrafficof_DW.FromMultimediaFile_HostLib[0U]);

    /* InitializeConditions for Delay: '<S2>/Delay' */
    for (i = 0; i < 19200; i++) {
      viptrafficof_DW.Delay_DSTATE[i] = viptrafficof_P.Delay_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S2>/Delay' */

    /* InitializeConditions for S-Function (svipstatfcns): '<S8>/Mean velocity per frame across time' */
    viptrafficof_DW.Meanvelocityperframeacrosstim_i = 0U;
    viptrafficof_DW.Meanvelocityperframeacrosstime_ = 0.0F;

    /* SystemInitialize for MATLAB Function: '<S5>/Optical Flow Lines' */
    viptrafficof_DW.first_time_not_empty = false;
    for (i = 0; i < 23; i++) {
      viptrafficof_DW.RV[i] = 5.0 * (real_T)i + 5.0;
    }

    for (i = 0; i < 31; i++) {
      viptrafficof_DW.CV[i] = 5.0 * (real_T)i + 5.0;
    }

    /* End of SystemInitialize for MATLAB Function: '<S5>/Optical Flow Lines' */
  }
}

/* Model terminate function */
static void viptrafficof_terminate(void)
{
  char_T *sErr;

  /* Terminate for S-Function (sdspwmmfi2): '<Root>/From Multimedia File' */
  sErr = GetErrorBuffer(&viptrafficof_DW.FromMultimediaFile_HostLib[0U]);
  LibTerminate(&viptrafficof_DW.FromMultimediaFile_HostLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(viptrafficof_M, sErr);
    rtmSetStopRequested(viptrafficof_M, 1);
  }

  LibDestroy(&viptrafficof_DW.FromMultimediaFile_HostLib[0U], 0);
  DestroyHostLibrary(&viptrafficof_DW.FromMultimediaFile_HostLib[0U]);

  /* End of Terminate for S-Function (sdspwmmfi2): '<Root>/From Multimedia File' */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  viptrafficof_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  viptrafficof_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  viptrafficof_initialize();
}

void MdlTerminate(void)
{
  viptrafficof_terminate();
}

/* Registration function */
RT_MODEL_viptrafficof_T *viptrafficof(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)viptrafficof_M, 0,
                sizeof(RT_MODEL_viptrafficof_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = viptrafficof_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    viptrafficof_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    viptrafficof_M->Timing.sampleTimes =
      (&viptrafficof_M->Timing.sampleTimesArray[0]);
    viptrafficof_M->Timing.offsetTimes =
      (&viptrafficof_M->Timing.offsetTimesArray[0]);

    /* task periods */
    viptrafficof_M->Timing.sampleTimes[0] = (0.066666666666666666);

    /* task offsets */
    viptrafficof_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(viptrafficof_M, &viptrafficof_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = viptrafficof_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    viptrafficof_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(viptrafficof_M, -1);
  viptrafficof_M->Timing.stepSize0 = 0.066666666666666666;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    viptrafficof_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(viptrafficof_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(viptrafficof_M->rtwLogInfo, (NULL));
    rtliSetLogT(viptrafficof_M->rtwLogInfo, "");
    rtliSetLogX(viptrafficof_M->rtwLogInfo, "");
    rtliSetLogXFinal(viptrafficof_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(viptrafficof_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(viptrafficof_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(viptrafficof_M->rtwLogInfo, 0);
    rtliSetLogDecimation(viptrafficof_M->rtwLogInfo, 1);
    rtliSetLogY(viptrafficof_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(viptrafficof_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(viptrafficof_M->rtwLogInfo, (NULL));
  }

  viptrafficof_M->solverInfoPtr = (&viptrafficof_M->solverInfo);
  viptrafficof_M->Timing.stepSize = (0.066666666666666666);
  rtsiSetFixedStepSize(&viptrafficof_M->solverInfo, 0.066666666666666666);
  rtsiSetSolverMode(&viptrafficof_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  viptrafficof_M->ModelData.blockIO = ((void *) &viptrafficof_B);
  (void) memset(((void *) &viptrafficof_B), 0,
                sizeof(B_viptrafficof_T));

  {
    int32_T i;
    for (i = 0; i < 57600; i++) {
      viptrafficof_B.FromMultimediaFile[i] = 0.0F;
    }

    for (i = 0; i < 19200; i++) {
      viptrafficof_B.ColorSpaceConversion[i] = 0.0F;
    }

    for (i = 0; i < 57600; i++) {
      viptrafficof_B.InsertText[i] = 0.0F;
    }

    for (i = 0; i < 57600; i++) {
      viptrafficof_B.Assignment1[i] = 0.0F;
    }

    viptrafficof_B.Probe[0] = 0.0;
    viptrafficof_B.Probe[1] = 0.0;
  }

  /* parameters */
  viptrafficof_M->ModelData.defaultParam = ((real_T *)&viptrafficof_P);

  /* states (dwork) */
  viptrafficof_M->ModelData.dwork = ((void *) &viptrafficof_DW);
  (void) memset((void *)&viptrafficof_DW, 0,
                sizeof(DW_viptrafficof_T));

  {
    int32_T i;
    for (i = 0; i < 137; i++) {
      viptrafficof_DW.FromMultimediaFile_HostLib[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 5; i++) {
      viptrafficof_DW.FromMultimediaFile_AudioInfo[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 11; i++) {
      viptrafficof_DW.FromMultimediaFile_VideoInfo[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 713; i++) {
      viptrafficof_DW.X[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 713; i++) {
      viptrafficof_DW.Y[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 23; i++) {
      viptrafficof_DW.RV[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 31; i++) {
      viptrafficof_DW.CV[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 19200; i++) {
      viptrafficof_DW.Delay_DSTATE[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 57600; i++) {
      viptrafficof_DW.ColorSpaceConversion_DWORK1[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 19200; i++) {
      viptrafficof_DW.OpticalFlowEstimation_GRADCC[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 19200; i++) {
      viptrafficof_DW.OpticalFlowEstimation_GRADRC[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 19200; i++) {
      viptrafficof_DW.OpticalFlowEstimation_GRADRR[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 19200; i++) {
      viptrafficof_DW.OpticalFlowEstimation_GRADCT[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 19200; i++) {
      viptrafficof_DW.OpticalFlowEstimation_GRADRT[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 120; i++) {
      viptrafficof_DW.OpticalFlowEstimation_MEMC0[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 120; i++) {
      viptrafficof_DW.OpticalFlowEstimation_MEMC1[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 160; i++) {
      viptrafficof_DW.OpticalFlowEstimation_MEMR0[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 160; i++) {
      viptrafficof_DW.OpticalFlowEstimation_MEMR1[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 19200; i++) {
      viptrafficof_DW.OpticalFlowEstimation_ALPHA[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 120; i++) {
      viptrafficof_DW.OpticalFlowEstimation_VELBUFFC0[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 120; i++) {
      viptrafficof_DW.OpticalFlowEstimation_VELBUFFC1[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 120; i++) {
      viptrafficof_DW.OpticalFlowEstimation_VELBUFFR0[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 120; i++) {
      viptrafficof_DW.OpticalFlowEstimation_VELBUFFR1[i] = 0.0F;
    }
  }

  viptrafficof_DW.Meanvelocityperframe_AccVal = 0.0F;
  viptrafficof_DW.Meanvelocityperframeacrosstime_ = 0.0F;
  viptrafficof_DW.InsertText_colorVectorDW[0] = 0.0F;
  viptrafficof_DW.InsertText_colorVectorDW[1] = 0.0F;
  viptrafficof_DW.InsertText_colorVectorDW[2] = 0.0F;

  /* Initialize Sizes */
  viptrafficof_M->Sizes.numContStates = (0);/* Number of continuous states */
  viptrafficof_M->Sizes.numY = (0);    /* Number of model outputs */
  viptrafficof_M->Sizes.numU = (0);    /* Number of model inputs */
  viptrafficof_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  viptrafficof_M->Sizes.numSampTimes = (1);/* Number of sample times */
  viptrafficof_M->Sizes.numBlocks = (31);/* Number of blocks */
  viptrafficof_M->Sizes.numBlockIO = (9);/* Number of block outputs */
  viptrafficof_M->Sizes.numBlockPrms = (24);/* Sum of parameter "widths" */
  return viptrafficof_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
