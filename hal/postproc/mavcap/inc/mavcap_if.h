#ifndef _MAVCAP_IF_H_
#define _MAVCAP_IF_H_

#include "pp_comm_def.h"
#include "mm_comm_def.h"
#include "mavcap_comm_def.h"
#include "pp_if.h"

typedef enum
{
    MAVCAP_IDLE_STATE=0,
    MAVCAP_CONFIG_STATE,
    MAVCAP_READY_STATE,
    MAVCAP_MEM_PROCESS_STATE,
    MAVCAP_PROCESS_STATE
} MAVCAP_STATE_ENUM;


/*****************************************************************************
    Feature Control Enum and Structure
******************************************************************************/
typedef enum
{
    MAVCAP_FEATURE_BEGIN,
    MAVCAP_FEATURE_GET_ENV_INFO,
    MAVCAP_FEATURE_SET_ENV_INFO,
    MAVCAP_FEATURE_SET_PROC_INFO,
    MAVCAP_FEATURE_GET_STATE,
    MAVCAP_FEATURE_GET_RESULT,
    MAVCAP_FEATURE_SET_LOG_INFO,
    MAVCAP_FEATURE_MAX
}	MAVCAP_FEATURE_ENUM;

typedef struct
{
    kal_uint16  ImageWidth;               // processing image width
    kal_uint16  ImageHeight;              // processing image height
    kal_uint32  WorkingBufSize;           // required working buffer size
    MM_IMAGE_FORMAT_ENUM SrcImgFormat;    // supported input image format, currently only RGB565 is supported.
} MAVCAP_GET_ENV_INFO_STRUCT, *P_MAVCAP_GET_ENV_INFO_STRUCT;

typedef struct
{
    kal_uint16 target_width;                        // lcd width
    kal_uint16 target_height;                       // lcd height
    kal_bool dir_decided;                           // if true, this is not the first autocap image and driver only refreshs mv, and keeps direction
    P_MAVCAP_TUNING_PARA_STRUCT p_tuning_data; 

} MAVCAP_SET_ENV_INFO_STRUCT, *P_MAVCAP_SET_ENV_INFO_STRUCT;

typedef struct
{
    kal_uint32  PpSrcBufAddr;              // source image address
    kal_uint32  PpSrcBufSize;	           // source image size
    PP_MEM_OP_TYPE_ENUM	PpMemOpType;   // check if the source image needs bilinear resize or just memory copy				
    kal_uint32  PpProcBufAddr;             // working buffer address
    kal_uint32 	PpProcBufSize;             // working buffer size
    MM_IMAGE_FORMAT_ENUM  PpProcFmt;	   // source image format, currently only RGB565 is supported	
    float	MotionValueXY[MOTION_TOTAL_BN*2];   //From EIS
    float	TrustValueXY[MOTION_TOTAL_BN*2];    //From EIS
    kal_bool PpForceToShot;

} MAVCAP_SET_MEM_INFO_STRUCT, *P_MAVCAP_SET_MEM_INFO_STRUCT;


typedef struct
{
    MM_ERROR_CODE_ENUM (* MavCapOpen)(void);
    MM_ERROR_CODE_ENUM (* MavCapFeatureCtrl) (MAVCAP_FEATURE_ENUM FeatureId, void* pFeatureParaIn, void* pFeatureParaOut, kal_uint16 FeatureParaOutLen);
    MM_ERROR_CODE_ENUM (* MavCapCtrl) (PP_SCENARIO_ENUM ScenarioId, PP_SCENARIO_CTRL_ENUM CtrlCode, void *pParaIn, void *pParaOut, kal_uint16 ParaOutLen);
    MM_ERROR_CODE_ENUM (* MavCapClose)(void);
} MAVCAP_FUNCTION_STRUCT, *P_MAVCAP_FUNCTION_STRUCT;

MM_ERROR_CODE_ENUM MavCapInit(MM_ERROR_CODE_ENUM (* pfMavCapCallback) (PP_CALLBACK_ID_ENUM CbId,
                               void *pCallbackPara, kal_uint16 CallbackParaLen),
                           P_MAVCAP_FUNCTION_STRUCT *pfMavCapFunc);

#endif	// _MAVCAP_IF_H_

