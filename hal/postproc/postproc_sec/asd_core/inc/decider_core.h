#ifndef __DECIDER_CORE_DEF_H__
#define __DECIDER_CORE_DEF_H__

#include "kal_release.h"
#include "asd_comm_def.h"

#define SCORE_LOWEST (0)
#define SCORE_HIGHEST (100)
#define IDX_WEIGHT_TBL_HIGHER_RATIO_SLIGHT (2) /*3a results will this times higher than content results and vice versa*/
#define IDX_WEIGHT_TBL_HIGHER_RATIO_HEAVY  (5) /*3a results will this times higher than content results and vice versa*/
#define TIME_SMOOTH_MAX_CYCLE (ASD_TIME_WEIGHT_RANGE_CYCLE_MAX-1)  /* 10 */
#define THRESHOLD_SCENE_NIGHT (80)    /*the same result while setting 1~99, just assign a typical value*/
#define THRESHOLD_SCENE_PORTRAIT (80) /*the same result while setting 1~99, just assign a typical value*/
#define CWF_D65_RATIO_SCORE_LOWEST (4) /* score=0 while gain locate @ cwf-(d65-cwf)/(this value)*/
#define MACRO_INF_POS_RATIO_SCORE_LOWEST (3) /* lens position which the score=0 */

/* external */

/* input source type enum */
typedef enum
{
	DECIDER_INFO_SRC_YUV,    /* from YUV sensor */
	DECIDER_INFO_SRC_FP_RAW, /* from WCP1 FP */
	DECIDER_INFO_SRC_SP_RAW, /* from WCP2 SP */
	DECIDER_INFO_SRC_NUM
}	DECIDER_INFO_SRC_ENUM;

/* all possible scene types enum, only 7 scenes are available for this MP */
// move to asd_comm_def.h

/* 3A information for decider usage */
typedef struct
{
    kal_int16  AeEv;        /* AE Ev value */
    kal_int16  AeFaceEnhanceEv;        /* AE Ev value */
    kal_bool   AeIsBacklit; /* AE Backlit Condition from AE algorithm */
    kal_bool   AeIsStable;  /* AE converge to stable situation */
    kal_uint16 AwbCurRgain; /* Current AWB R channel gain */
    kal_uint16 AwbCurBgain; /* Current AWB B channel gain */
    kal_bool   AwbIsStable; /* AWB converge to stable situation */
    kal_uint16 AfPosition;  /* Current lens position */
    kal_bool   AfIsStable;  /* Af converge to stable situation */
} DECIDER_INFO_3A_STRUCT;

/* FD information for decider usage */
typedef struct
{
    kal_uint8  FdFaceNum;
    kal_uint8  FdMainFacePose;
    kal_uint16 FdMainFaceLuma;
    kal_uint16 FdMainFaceX0;
    kal_uint16 FdMainFaceX1;
    kal_uint16 FdMainFaceY0;
    kal_uint16 FdMainFaceY1;
    kal_uint32 FdProcTimeStart;
    kal_uint32 FdProcTimeEnd;
} DECIDER_INFO_FD_STRUCT;

/* Content scene detection information for decider usage */
typedef enum
{
    CONTENT_SCENE_LANDSCAPE=0,
    CONTENT_SCENE_BACKLIGHT,
    CONTENT_SCENE_NUM
} CONTENT_SCD_SCENE_ENUM;

typedef struct
{
    kal_uint32 ScdProcTimeStart;
    kal_uint32 ScdProcTimeEnd;
    kal_uint8  ScdScore[CONTENT_SCENE_NUM];
} DECIDER_INFO_SCD_STRUCT;

/* union information data for decider */
typedef struct
{
    DECIDER_INFO_3A_STRUCT  InfoAaa; /* 3A information for ASD usage */
    DECIDER_INFO_FD_STRUCT  InfoFd;  /* FD information for ASD usage */
    DECIDER_INFO_SCD_STRUCT InfoScd; /* Scene Detection information for ASD usage */
} DECIDER_INFO_STRUCT;

/* decider final result scene */
typedef struct
{
    kal_bool DataScdValid; /* TRUE if content scene detection's data are updated in this cycle */
    kal_bool DataFdValid;  /* TRUE if fd data are updated in this cycle */
    ASD_DECIDER_UI_SCENE_TYPE_ENUM DeciderUiScene;
} DECIDER_RESULT_STRUCT;

/* reference parameters for decider usage, it's varied by projects */
typedef struct
{
    DECIDER_INFO_SRC_ENUM DeciderInfoVer;  /* information version control, 0,1,2 for YUV,WCP1-RAW, WCP2-RAW*/
    kal_uint16 RefAwbD65Rgain;  /* D65 R channel gain */
    kal_uint16 RefAwbD65Bgain;  /* D65 B channel gain */
    kal_uint16 RefAwbCwfRgain;  /* CWF R channel gain */
    kal_uint16 RefAwbCwfBgain;  /* CWF B channel gain */
    void       *RefAfTbl;       /* the whole AF table including macro index & total number of the table */
} DECIDER_REF_STRUCT;

/* tuning parameters */
typedef struct
{
    ASD_DECIDER_TIME_WEIGHT_TYPE_ENUM  TimeWeightType;
	ASD_DECIDER_TIME_WEIGHT_RANGE_ENUM TimeWeightRange;
	kal_int16 IdxWeightBlAe;
	kal_int16 IdxWeightBlScd;
	kal_int16 IdxWeightLsAe;
	kal_int16 IdxWeightLsAwb;
	kal_int16 IdxWeightLsAf;
	kal_int16 IdxWeightLsScd;
	kal_int16 EvLoThrNight;
	kal_int16 EvHiThrNight;
	kal_int16 EvLoThrOutdoor;
	kal_int16 EvHiThrOutdoor;
	kal_int16 BacklitLockEvDiff;
	kal_uint8 ScoreThrNight;
	kal_uint8 ScoreThrBacklit;
	kal_uint8 ScoreThrPortrait;	
	kal_uint8 ScoreThrLandscape;
	kal_bool BacklitLockEnable;
    ASD_DECIDER_UI_SCENE_TYPE_ENUM UiSceneLut[ASD_DECIDER_UI_SCENE_NUM];
	kal_bool  bReserved;
	void      *pReserved;
} DECIDER_TUNING_PARA_STRUCT;

/* union init parameters, contain reference & tuning parameters*/
typedef struct
{
	DECIDER_REF_STRUCT  DeciderRefData;
	DECIDER_TUNING_PARA_STRUCT DeciderTuneData;
} DECIDER_INIT_STRUCT;



/* Internal */
typedef enum
{
    TIME_SMOOTH_TYPE_AVERAGE=0,
    TIME_SMOOTH_TYPE_LATER_HIGHER,
    TIME_SMOOTH_TYPE_NUM
} TIME_SMOOTH_TYPE_ENUM;

typedef enum
{
    BASIC_SCENE_NIGHT=0,
    BASIC_SCENE_BACKLIT,
    BASIC_SCENE_PORTRAIT,
    BASIC_SCENE_LANDSCAPE,
    BASIC_SCENE_NUM
} BASIC_SCENE_ENUM;

typedef enum
{
    IDX_AE_NIGHT=0,
    IDX_AE_OUTDOOR,
    IDX_AE_BACKLIT,
    IDX_AWB_GAIN,
    IDX_AF_POSI,
    IDX_3A_NUM
} INDEX_VECTOR_3A_ENUM;

typedef enum
{
    IDX_FD_SCORE=IDX_3A_NUM,
    IDX_BL_SCORE,
    IDX_LS_SCORE,
    IDX_NUM
} INDEX_VECTOR_CONTENT_ENUM;

typedef enum
{
    STATE_IDLE=0,     /* before open or after close */
    STATE_STANDBY,    /* after open & before init */
    STATE_INIT_DONE,  /* after init & before 1st trigger */
    STATE_BUSY,       /* during process */
    STATE_BLANK,      /* after process done & waiting for next trigger */
    STATE_MAX
} DECIDER_STATE_ENUM;

typedef struct
{
    kal_int16 x;
    kal_int16 y;
} POINT_2D_STRUCT;

typedef struct
{
    kal_bool IsValid; /* if af table is not valid, KAL_FALSE */
    kal_int16 InfPos;
    kal_int16 MacPos;
    kal_int16 ZroPos;
} AF_REF_STRUCT;

typedef struct
{
    kal_int16 Lm; /* row number of left matrix */
    kal_int16 Ln; /* column number of left matrix */
    kal_int16 Rm; /* row number of right matrix, Ln should equal to Rm */
    kal_int16 Rn; /* column number of right matrix */
} MATX_MULT_STRUCT;

/* FP AF table structure */
#define	AF_MAX_TABLE_NO_FP (24)
typedef struct {
	kal_uint16		af_table_num;
	kal_uint16		af_home_idx;
	kal_uint16		af_macro_idx;
	kal_uint16		af_infinite_idx;
	kal_uint16		af_hyper_pos;
	kal_uint16		af_me_home_pos;
	kal_uint16		af_me_macro_pos;
	kal_uint16		af_filter_type;
}AF_TABLE_RANGE_STRUCT;
typedef struct {
	kal_uint16	pos;
	kal_uint16	distance;
}AF_TABLE_STEP_STRUCT;
typedef struct
{
	AF_TABLE_RANGE_STRUCT	table_range;
	AF_TABLE_STEP_STRUCT	table_step[AF_MAX_TABLE_NO_FP];
}AF_LUT_FP_STRUCT;

/* SP AF table structure */
#define	AF_MAX_TABLE_NO_SP (30)
typedef struct
{
   	kal_int32 i4Table_No;
    kal_int32 i4Pos[AF_MAX_TABLE_NO_SP];
}AF_LUT_SP_STRUCT;

/* Logger structure */
typedef struct
{
    kal_uint32 Type; // 0 : feature phone 1:smart phone 2:cmodel
    kal_uint32 Version; // 201101
    kal_int8 *pLogger;
    kal_int8 *pLoggerBackup;
    kal_uint16 LoggerIdx;
    kal_uint16 WrapCount;
    kal_uint16 SizeInit;
    kal_uint16 SizeLogger;
    kal_uint16 SizeRun;
    kal_uint16 MaxBytePerCycle;
    kal_uint16 MaxCycle;
    kal_bool   LoggerEnable;  // gLogger.LoggerEnable
}LOGGER_STRUCT;

/* FP FD pose enum */
typedef enum
{
    FD_FACE_POSE_0 = 0,
    FD_FACE_POSE_90,
    FD_FACE_POSE_180,
    FD_FACE_POSE_270,
    FD_FACE_POSE_NUM
} FD_FACE_POSE_ENUM;

/* entry */
kal_bool DeciderCoreInit(void* pParaIn, void* pParaOut);
kal_bool DeciderCoreMain(void* pParaIn, void* pParaOut);
kal_bool DeciderCoreGetResult(void* pParaIn, void* pParaOut);
kal_bool DeciderCoreOpen(void);
kal_bool DeciderCoreReset(void);
kal_bool DeciderCoreSetLogger(void* pParaIn, void* pParaOut);

#endif
