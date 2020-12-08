#ifndef _MAV_IF_H_
#define _MAV_IF_H_

#include "mav_comm_def.h"
#include "mm_comm_def.h"
#include "pp_comm_def.h"
#include "MavWarpSwCore.h"

typedef enum
{
    MAV_STATE_STANDBY=0,    // After Called MavOpen
    MAV_STATE_INIT,         // After Called MavInit
    MAV_STATE_PROC,         // After Called MavMain
    MAV_STATE_PROC_READY,   // After Finish MavMain 
    MAV_STATE_READY         // After Finish MavMerge
} MAV_STATE_ENUM;



/*****************************************************************************
    Feature Control Enum and Structure
******************************************************************************/
typedef enum
{
    MAV_FEATURE_GET_ENV_INFO,
    MAV_FEATURE_SET_ENV_INFO,
    MAV_FEATURE_SET_PROC_INFO,
	MAV_FEATURE_GET_RESULT,
	MAV_FEATURE_GET_STATE,
	MAV_FEATURE_SET_LOG_INFO,
    MAV_FEATURE_MAX
}   MAV_FEATURE_ENUM;

// MAV_FEATURE_GET_ENV_INFO
typedef struct
{
	kal_uint16				MaxImageNumber;				// total image number, if image number get from set env info is larger than MAX_IMG_NO, return MAX_IMG_NO
    kal_uint32				WorkingBufSize;				// required working buffer size
} MAV_GET_ENV_INFO_STRUCT, *P_MAV_GET_ENV_INFO_STRUCT;


// MAV_FEATURE_SET_ENV_INFO
typedef struct
{
    kal_uint16				ImageWidth;					// processing image width
    kal_uint16				ImageHeight;				// processing image height			
    kal_uint32				WorkingBuffAddr;			// default size 
	kal_uint32				WorkingBufSize;			// default size 
    // Other Tuning Parameters
    MavTuningInfo           *pTuningInfo;				// tuning parameters
} MAV_SET_ENV_INFO_STRUCT, *P_MAV_SET_ENV_INFO_STRUCT;

// MAV_FEATURE_SET_PROC_INFO
typedef struct
{
	kal_uint16				TotalImgNumber;							// total image number
    kal_uint32				PpImgBufAddr;							// source image address
    kal_uint32				PpImgBufSize;							// source image size*9
	kal_int32				GlobalMotion[MAV_IMAGE_NUM][2];		// global motion from MavCap 
} MAV_SET_PROC_INFO_STRUCT, *P_MAV_SET_PROC_INFO_STRUCT;

typedef struct
{
    MM_ERROR_CODE_ENUM (* MavOpen)(void);
    MM_ERROR_CODE_ENUM (* MavFeatureCtrl) (MAV_FEATURE_ENUM FeatureId, void* pFeatureParaIn, void* pFeatureParaOut, kal_uint16 FeatureParaOutLen);
    MM_ERROR_CODE_ENUM (* MavCtrl) (PP_SCENARIO_ENUM ScenarioId, PP_SCENARIO_CTRL_ENUM CtrlCode, void *pParaIn, void *pParaOut, kal_uint16 ParaOutLen);
    MM_ERROR_CODE_ENUM (* MavClose)(void);
} MAV_FUNCTION_STRUCT, *P_MAV_FUNCTION_STRUCT;

MM_ERROR_CODE_ENUM MavInit(MM_ERROR_CODE_ENUM (* pfAutoCapCallback) (PP_CALLBACK_ID_ENUM CbId,
                               void *pCallbackPara, kal_uint16 CallbackParaLen),
								P_MAV_FUNCTION_STRUCT *pfAutoCapFunc);
#endif	// _MAV_IF_H_