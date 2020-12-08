#ifndef _MAV_WARP_SW_CORE_H
#define _MAV_WARP_SW_CORE_H

#include "MTKMavType.h"
#include "MTKMavErrCode.h"
#include "mav_comm_def.h"
#include "mav_core.h"


#define SW_WARP_MATRIX_SIZE     (9*MAV_MAX_IMAGE_NUM)
#define SW_WARP_MATRIX_BIT      (20)

typedef struct{
    MUINT32             ProcBufAddr;                // working buffer address
    MUINT8              *ImgAddr;                   // input image address
    MUINT32             ImgNum;                     // input image number
    WARP_IMAGE_FORMAT   ImgFmt;                     // input image format
    MUINT32             ImgWidth;                   // input image width
    MUINT32             ImgHeight;                  // input image height
    MFLOAT              *WarpMatrix;                // warping matrix pointer
    MUINT8              *ImgBufferAddr;             // image buffer address

    MUINT32             ClipX[MAV_MAX_IMAGE_NUM];    // image offset X
    MUINT32             ClipY[MAV_MAX_IMAGE_NUM];    // image offset Y
    MUINT32             ClipWidth;                  // image result width
    MUINT32             ClipHeight;                 // image result height
} warp_sw_cal_struct;


void SwWarpingInit(WarpImageInfo *);
void SwWarping(MINT32, WarpResultInfo *);
MUINT8 SimpleBilinear(MUINT8 *src, MINT32 x4, MINT32 y4, MINT32 stride);

#endif
