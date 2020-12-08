/*
    Harris corner detector (harris_corner.h)
    Author: Thomas Tzeng (thomas.tzeng@mediatek.com)
    Copyright 2010 by MediaTek
*/

#ifndef MAV_MOTION_CORE_H
#define MAV_MOTION_CORE_H

#include "MTKMotionType.h"
#include "mavcap_comm_def.h"
#include "mm_comm_def.h"

// Tuning parameters
#define TV_TH       10      // trust value threshold
#define MAX_MV      8       // the accumulated motion that should shot
#define BN_TH       3       // the threshold of block number that exceed MAX_MV
#define STEP_LB	    3       // the lower bound of frame jump step
#define STEP_UB	    8       // the upper bound of frame jump step

// working buffer size details
#define MOTION_MV_SIZE          (MOTION_TOTAL_BN*2)
#define MOTION_TV_SIZE          (MOTION_TOTAL_BN*2)
#define MOTION_TV_CNT_SIZE      (MOTION_TOTAL_BN*2)
#define MOTION_ACC_MV_SIZE      (MOTION_TOTAL_BN*2)
#define MOTION_GMV_SIZE         (2)
#define MOTION_TMP_MV_SIZE      (2)
#define MOTION_CGMV_SIZE        (2)

// computational data structure
typedef struct {
    // input
    MUINT32 ProcBufAddr;

    // tuning parameters
    MFLOAT max_mv;          // maximum mv
    MINT32 step_lb;         // step lower bound
    MINT32 step_ub;         // step upper bound

    // intermediate         // offset   size(Byte)
    MFLOAT *mv;             //      0   32*4 = 128
    MFLOAT *tv;             //    128   32*4 = 128
    MINT32 *tv_cnt;         //    256   32*4 = 128
    MFLOAT *acc_mv;         //    384   32*4 = 128
    MFLOAT *tmp_mv;         //    512    2*4 =   8
    MINT32 shot_step;       //    520    1*4 =   4
    MINT32 cur_step;        //    524    1*4 =   4
    MBOOL moving;           //    528            1
                            //    529 (total size)
}motion_cal_struct;

typedef struct 
{
     /* motion tracking results */
    MINT16      MV_X;                   // horizontal accumulated motion
    MINT16      MV_Y;                   // vertical accumulated motion
    MBOOL       ReadyToShot;            // ready to shot flag
    //MRESULT     RetCode;                // returned code of state machine
    MUINT8      ErrPattern;             // returned error/warning bit pattern 
                                        // bit 0: low trust value (set if warning)
                                        // bit 1: large motion vector (set if warning)
                                        // bit 2: vertical shake (set if warning)
    MAVCAP_DIRECTION_ENUM Direction; // panorama direction enum
	MUINT16		FrameCount;
}MTKMotionResultInfo, *P_MTKMotionResultInfo;

typedef struct
{
	// Tuning Parameter for AutoCap
    kal_uint32 tolerance_x;					// x direction tolerance for capture, currently, not be used just for extension in the future
    kal_uint32 tolerance_y;					// y direction tolerance for capture, currently, not be used just for extension in the future
} MAVCAP_CORE_CAP_TUNING_PARA_STRUCT, *P_MAVCAP_CORE_CAP_TUNING_PARA_STRUCT;


typedef struct
{
	// Tuning Parameter for MavMotion
    kal_int32  MaxMV;						// maximum motion vertor        (default: 8)
    kal_int32  StepLB;						// upper bound of frame step    (default: 3)
    kal_int32  StepUB;						// lower bound of frame step    (default: 8)
    kal_int32  ToleranceX;					// horizontal tolerance of motion vector deviation
    kal_int32  ToleranceY;					// vertical tolerance of motion vector deviation
    kal_int32  OverlapRatio;				// overlap ratio between captured images
} MAVCAP_CORE_MOTION_TUNING_PARA_STRUCT, *P_MAVCAP_CORE_MOTION_TUNING_PARA_STRUCT;

typedef struct
{
    kal_uint16 target_width;                        // lcd width
    kal_uint16 target_height;                       // lcd height
    kal_bool dir_decided;                           // if true, this is not the first autocap image and driver only refreshs mv, and keeps direction
	P_MAVCAP_CORE_MOTION_TUNING_PARA_STRUCT p_mavmotion_tuning_data; 

} MAVCAP_CORE_SET_ENV_INFO_STRUCT, *P_MAVCAP_CORE_SET_ENV_INFO_STRUCT;

typedef struct
{   
    kal_uint32  PpProcBufAddr;             // working buffer address
    kal_uint32 	PpProcBufSize;             // working buffer size
    MM_IMAGE_FORMAT_ENUM  PpProcFmt;	   // source image format, currently only RGB565 is supported	
	float	MotionValueXY[MOTION_TOTAL_BN*2];   //From EIS
    float	TrustValueXY[MOTION_TOTAL_BN*2];    //From EIS

} MAVCAP_CORE_SET_MEM_INFO_STRUCT, *P_MAVCAP_CORE_SET_MEM_INFO_STRUCT;


/*****************************************************************************
    Process Control 
******************************************************************************/
typedef enum
{   
    MTKMOTION_ERR_LOW_TV=0,             // warning of low trust value
    MTKMOTION_ERR_LARGE_MV,             // warning of large motion vector
    MTKMOTION_ERR_VERT_SHAKE,           // warning of vertical shaking
    MTKMOTION_ERR_NO
} MTKMOTION_ERR_ENUM;

// functions declaration
void MotionDetectInit(P_MAVCAP_CORE_SET_ENV_INFO_STRUCT MotionEnvInfo);
void MotionDetect(P_MAVCAP_CORE_SET_MEM_INFO_STRUCT ProcInfo, P_MTKMotionResultInfo ResultInfo);

#endif
