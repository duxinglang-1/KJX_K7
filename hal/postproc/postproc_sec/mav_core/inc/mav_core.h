#ifndef _MAV_CORE_H_
#define _MAV_CORE_H_

#include "MTKMavErrCode.h"
#include "mav_comm_def.h"

//========================================================================================
/* Debug option */
#define DUMP        // define dump intermediate data, undefine dump only error and info

// maximum image number, if modified, should modify the MAV_RECTIFY_GLOBAL_SIZE and MAV_FEATURE_GLOBAL_SIZE in mav_comm_def.h as well.
#define MAV_MAX_IMAGE_NUM					(15)    

// Dummy for core
typedef enum DRVMavObject_s {
    DRV_MAV_OBJ_NONE = 0,
    DRV_MAV_OBJ_SW,
    DRV_MAV_OBJ_SW_NEON,    
    DRV_MAV_OBJ_PANO3D, 
    DRV_MAV_OBJ_UNKNOWN = 0xFF,
} DrvMavObject_e;

typedef enum
{
    WARP_IMAGE_YV12=0,          // input image format is YV12
    WARP_IMAGE_NV21,            // input image format is NV21
    WARP_IMAGE_RGB565,          // input image format is RGB565
    WARP_IMAGE_MAX              // maximum image format enum
}   WARP_IMAGE_FORMAT;

typedef enum
{
    MAV_CORE_PROCESS_STATE_STANDBY = 0,    
	MAV_CORE_PROCESS_STATE_FE,
	MAV_CORE_PROCESS_STATE_RECTIFY,
	MAV_CORE_PROCESS_STATE_WRAP,
    MAV_CORE_PROCESS_STATE_ALIGNIMG,          
    MAV_CORE_PROCESS_STATE_READY       
} MAV_CORE_PROCESS_STATE_ENUM;


typedef enum
{   
    MTKWARP_DIR_RIGHT=0,        // panorama direction is right
    MTKWARP_DIR_LEFT,           // panorama direction is left
    MTKWARP_DIR_UP,             // panorama direction is up
    MTKWARP_DIR_DOWN,           // panorama direction is down
    MTKWARP_DIR_NO              // panorama direction is not decided
} MTKWARP_DIRECTION_ENUM;


extern int GLOBAL_Pt_SIZE;
extern int GLOBAL_Ptf_SIZE;
extern int GLOBAL_Perspective_SIZE;
extern int GLOBAL_FEATURE_SIZE;
extern int GLOBAL_RECTIFY_SIZE;

//#define GLOBAL_Pt_SIZE				(sizeof(mav_point2D_struct)*MAV_IMAGE_NUM*MAX_FEATURE_NO)
//#define GLOBAL_Ptf_SIZE				(sizeof(MavMatchPointfStruct)*(MAV_IMAGE_NUM-1)*MAX_MATCH_NO)
//#define GLOBAL_Perspective_SIZE		(sizeof(mav_TPerspective_struct)*(MAV_IMAGE_NUM))
//#define GLOBAL_FEATURE_SIZE			((((GLOBAL_Pt_SIZE*2 + GLOBAL_Ptf_SIZE*2 + GLOBAL_Perspective_SIZE)+31)>>5)<<5)
//#define GLOBAL_RECTIFY_SIZE			((((sizeof(RECTIFY_IMAGE_CAL_STRUCT)+(sizeof(MFLOAT)*MAX_FEATURE_NO)+(sizeof(MINT32)*MAX_FEATURE_NO))+31)>>5)<<5)



//========= FeatureExtract.h for algorithm ==============//

/* perfomance parameter options in RectifyImage function */
#define RANK                    (3)
#define MAV_RECTIFY_ONCE        (1)

//========================================================================================
/* optimization option */
//========================================================================================
/* parameters in ExtractMatchedFeaturePairs */
#define RZ_SCALE                (0.2f)                      // scale of resize
#define MAV_RI_DATA_SIZE        (MAX_MATCH_NO*4+9)
#define denom                   (41943)                     // 20-bit is used

/* parameters in ExtractHarrisCorner function */
#define PARTIAL_DER_STEP        (1)
#define KAPPA                   (3)                         // Harris kappa
#define TH_RC                   (80)                        // Threshold for filtering out small corner responses resulted from noise
#define FE_HARRIS_KAPPA_BITS    (5)
#define HARRIS_AVG_BITS         (20)

/* parameters in imresize function */
#define P_HEIGHT                (13)                        // derived from kernel_height in imresize = 2/RZ_SCALE + 3

/* parameters in ExtractMatchedFeaturePairs */
#define MAX_FEATURE_NO          (1024)                      // maximum feature points number
#define MAX_MATCH_NO            (512)                       // maximum matching pairs number

/* perfomance parameter options in RectifyImage function */
#define PARA_NUM                (4)                         // I: parameter vector dimension (i.e. #unknowns)
#define BLOCK_SIZE              (32)                        /* block size for cache-friendly matrix-matrix multiply. It should be
                                                             * such that __BLOCKSZ__^2*sizeof(LM_REAL) is smaller than the CPU (L1)
                                                             * data cache size. Notice that a value of 32 when LM_REAL=double assumes
                                                             * an 8Kb L1 data cache (32*32*8=8K). This is a concervative choice since
                                                             * newer Pentium 4s have a L1 data cache of size 16K, capable of holding
                                                             * up to 45x45 double blocks.
                                                             */
#define BLOCK_SIZE_SQUARE       (BLOCK_SIZE)*(BLOCK_SIZE)
#define LM_INFO_SZ              (10)


#define MAV_max(a,b)  ((a) < (b) ? (b) : (a))
#define MAV_min(a,b)  ((a) < (b) ? (a) : (b))
#define MAV_ABS(a)    ((a) > 0 ? (a) : -(a))

//store position in 2-bytes (for NEON_OPT loading data)
typedef struct 
{
    MINT16  x;
    MINT16  y;
} mav_point2D_struct;

typedef struct
{
    MFLOAT  x;  
    MFLOAT  y;  
    MFLOAT  m_v[2];
}mav_point2Df_struct;

typedef struct 
{   
    MINT32 feature_no;
    mav_point2D_struct * feature_pt;
} mav_feature_point_struct ;

typedef struct 
{
    MFLOAT match_no;
    MBOOL  m_IsRectified;
    MFLOAT theta[RANK];          // 3x1 vector
    MFLOAT flen;                 // focal length
    MFLOAT Hmtx[RANK][RANK];     // 3x3 rectification matrix
    MFLOAT Ko[RANK][RANK];       // 3x3 Origin Calib matrix
    MFLOAT Kn[RANK][RANK];       // 3x3 New Calib matrix
    MFLOAT Rmtx[RANK][RANK];     // 3x3 Rot matrix
}mav_TPerspective_struct;

typedef struct 
{
    mav_point2Df_struct p1;
    mav_point2Df_struct p2;
    MFLOAT   similarity;
    MFLOAT   m_v[4];
} MavMatchPointfStruct;

typedef struct
{
    MINT32 match_no;
    MINT32 m_Image[2];
    MavMatchPointfStruct* m_MatchPt;
}MavMatchImagePairStruct;

typedef struct 
{
    mav_TPerspective_struct* m_Img;
    /* intermediate data */
    MavMatchImagePairStruct* m_Match;
    MavMatchImagePairStruct* m_RectifMatch;
    MINT32 imWidth;
    MINT32 imHeight;

    // Driver object enum
    DrvMavObject_e MavDrvObjectEnum;
}mav_rec_par_struct, *P_mav_rec_par_struct;

typedef MFLOAT ResizeArrayF[P_HEIGHT];
typedef MINT32 ResizeArrayI[P_HEIGHT];

/*****************************************************************************
    Proc and Structure
******************************************************************************/
typedef struct
{
    MUINT32                 ImgAddr;
    MUINT16                 Width;              // input image width
    MUINT16                 Height;             // input image height
    MUINT32                 AngleValueX;
    MUINT32                 AngleValueY;    
    MINT32                  ClipX;              // Image Global Offset X
    MINT32                  ClipY;              // Image Global Offset Y
    MINT32                  MotionValue[2];
} mav_image_info, *p_mav_image_info;

typedef struct
{
    MINT32                  ClipX;              // Image Global Offset X
    MINT32                  ClipY;              // Image Global Offset Y
    MFLOAT                  AngleValueX;        // AngleValue
    MFLOAT                  AngleValueY;        // AngleValue
    MFLOAT                  AngleValueZ;        // AngleValue

    // for 3D Panorama
    MINT16                  GridX;              // vertical offset in panorama space
    MINT16                  MinX;               // x_start in panorama space
    MINT16                  MaxX;               // x_end in panorama space
} MavResultImageInfo, *P_MavResultImageInfo;


typedef struct
{
    MRESULT                 RetCode;            // return warning
    MINT16                  ClipWidth;          // Image Result Width
    MINT16                  ClipHeight;         // Image Result Height
    MUINT16                 ViewIdx;            // Image Start View Index
    MUINT8                  ErrPattern;         // Returned error/Warning bit pattern
                                                // bit 0: lack of match points (set if error)
                                                // bit 1: small clip region (set if error)
                                                // bit 2: insufficient active matching pairs (set if error)
                                                // bit 3: reverse order(set if warning) -> 0/1 = Left-To-Right/Right-To-Left
    MavResultImageInfo      ImageInfo[MAV_MAX_IMAGE_NUM];
    MFLOAT                  ImageHmtx[MAV_MAX_IMAGE_NUM][RANK][RANK];   // 3x3 rectification matrix
} MavCoreResultInfo, *P_MavCoreResultInfo;


/*****************************************************************************
    Process Control 
******************************************************************************/
typedef struct
{
    // Extraction parameters
    MINT32                  RCWinBound;         // RC Window Bound to select points

    // Matching parameters
    MINT32                  SearchRange;        // Search Range to find the matching pair
    MINT32                  MatchRate;          // Error rate between minimum error and second minimum error
    MBOOL                   SwEisEnable;        // switch to enable global motion computation

    // Rectification parameters
    MINT32                  RectErrThre;        // Pixel error threshold for self image rectification
    MINT32                  IterNum;            // Iteration number of LM method
    MINT32                  MaxAngle;           // Maximum angle for self image recitification

    // Alignment parameters
    MINT32                  ClipRatio;          // Image clip ratio after alignment (real value*256)
    MFLOAT                  DispBound;          // bound for disparity check
    MFLOAT                  DispRatio;          // ratio for disparity check
    MINT32                  ActMatThre;         // threshold of active matching pairs

    // Disparity parameters
    MINT32                  SpecDispMin;        // disparity boundary of foreground
    MINT32                  SpecDispMax;        // disparity boundary of background
    MUINT32                 SpecPanelWidth;     // visible width of the panel
    MUINT32                 SpecPanelHeight;    // visible height of the panel
} MavCoreTuningInfo;

typedef enum
{
    MAV_ERR_LACK_MATCH_POINT=0,                 // error of lacking of matching points pair
    MAV_ERR_SMALL_CLIP_REGION,                  // error of small clip region
    MAV_ERR_ALIGN_INSUFF_NUM,                   // error of insufficient active matching pairs in alignement
    MAV_ERR_REVERSE_ORDER,                      // warning of reverse capture order
    MAV_ERR_VERGENCE_FAIL,                      // error of entering painful disparity
    MAV_ERR_VERGENCE_WARNING,                   // warning of entering discomfort disparity
    MAV_ERR_NO
} MAV_ERR_ENUM;


// MavInitStruct
typedef struct
{
	MUINT16				ImgWidth;					// Image width
	MUINT16				ImgHeight;					// Image height
	MUINT16				TotalImgNumber;				// total image number
    MUINT32				WorkingBuffAddr;			// 

	MUINT32				GlobalBuffAddr;				// = WorkingBuffer
	MUINT32				MavWorkingBuffAddr;			// = WorkingBuffer + GLOBAL_FEATURE_SIZE + GLOBAL_RECTIFY_SIZE
	MUINT32				WarpWorkingBuffAddr;		// = WorkingBuffer + GLOBAL_FEATURE_SIZE + GLOBAL_RECTIFY_SIZE + MAV_WORKING_BUFFER_SIZE
	DrvMavObject_e		ObjEnum;					// always set DRV_MAV_OBJ_SW

	MavCoreTuningInfo       *pTuningInfo;				// tuning parameters
    // Other Tuning Parameters
} mav_init_struct, *p_mav_init_struct;


// FeatureExtract.c cal structure
typedef struct
{ 
    MUINT32 SrcBufAddr[MAV_MAX_IMAGE_NUM];
    MUINT8* BlurImage[2];
    MINT16 ImageWidth;
    MINT16 ImageHeight;  
    MINT16 ImageIdx;  
    MUINT32 SrcBufAddrOffset;

    // Driver object enum
    DrvMavObject_e MavDrvObjectEnum;

    // working buffer in harris
    MINT8 *grdx;
    MINT8 *grdy;
    MINT32 *rc;
    MINT32 *tmp_rc;

    // tuning parameters
    MINT32 rc_win_bound;    // window bound for selecting points
    MINT32 search_range;    // search range for matching
    MINT32 match_rate;      // match rate of minimum error and second minimum error
    MBOOL  sw_eis_enable;

    // working buffer in imresize (used if SW EIS enable)
    MUINT8 *sIg1;
    MUINT8 *sIg2;
    MFLOAT *rz_u;
    MINT32 *rz_left;
    MFLOAT *rz_sum;
    ResizeArrayI* rz_indices;
    ResizeArrayF* rz_weights;
    MFLOAT* rz_tmp_out;
}mav_cal_struct;

typedef struct 
{
    MUINT32 ProcBufAddr;
    MINT32 num_para;                /* I: parameter vector dimension (i.e. #unknowns) */
    MINT32 match_no;                /* I: measurement vector dimension */
    MFLOAT p[PARA_NUM];             /* I/O: initial parameter estimates. On output has the estimated solution */
    MFLOAT x[MAX_MATCH_NO];         /* I: measurement vector. NULL implies a zero vector */
    MFLOAT lb[PARA_NUM];            /* I: vector of lower bounds. If NULL, no lower bounds apply */
    MFLOAT ub[PARA_NUM] ;           /* I: vector of upper bounds. If NULL, no upper bounds apply */
    MFLOAT opts[5];                 /* I: opts[0-4] = minim. options [\mu, \epsilon1, \epsilon2, \epsilon3, \delta]. Respectively the
                                     * scale factor for initial \mu, stopping thresholds for ||J^T e||_inf, ||Dp||_2 and ||e||_2 and
                                     * the step used in difference approximation to the Jacobian. Set to NULL for defaults to be used.
                                     * If \delta<0, the Jacobian is approximated with central differences which are more accurate
                                     * (but slower!) compared to the forward differences employed by default. 
                                     */
    MFLOAT info[LM_INFO_SZ];        /* O: information regarding the minimization. Set to NULL if don't care
                                     * info[0]= ||e||_2 at initial p.
                                     * info[1-4]=[ ||e||_2, ||J^T e||_inf,  ||Dp||_2, mu/max[J^T J]_ii ], all computed at estimated p.
                                     * info[5]= # iterations,
                                     * info[6]=reason for terminating: 1 - stopped by small gradient J^T e
                                     *                                 2 - stopped by small Dp
                                     *                                 3 - stopped by itmax
                                     *                                 4 - singular matrix. Restart from current p with increased mu 
                                     *                                 5 - no further error reduction is possible. Restart with increased mu
                                     *                                 6 - stopped by small ||e||_2
                                     *                                 7 - stopped by invalid (i.e. NaN or Inf) "func" values. This is a user error
                                     * info[7]= # function evaluations
                                     * info[8]= # Jacobian evaluations
                                     * info[9]= # linear systems solved, i.e. # attempts for reducing error
                                     */
    MINT32 ffdif;                   // nonzero if forward differencing is used
    MINT32 nfev;
    MFLOAT delta;                      
    MFLOAT *hx1;
    MFLOAT *hx2;                    /* \hat{x}_i, nx1 */
    MFLOAT *hxx;
    MFLOAT *adata;                  /* pointer to possibly additional data, passed uninterpreted to func.*/
                                    /* Set to NULL if not needed */

    // tuning parameters
    MFLOAT rect_th_err;
    MFLOAT rect_max_angle;
    MINT32 para_max_iter;           /* I: maximum number of iterations */
}RECTIFY_IMAGE_CAL_STRUCT, *P_RECTIFY_IMAGE_CAL_STRUCT;


typedef struct tagMavInitInfo
{
    MUINT32                 WorkingBuffAddr;    // default size : MAV_WORKING_BUFFER_SIZE
    // Other Tuning Parameters
    MavCoreTuningInfo           *pTuningInfo;       // tuning parameters
} MavInitInfo, *P_MavInitInfo;

//================ SwWarpCore ==================//

// WARP_FEATURE_ADD_IMAGE, 
// Input    : WarpImageInfo
// Output   : NONE
typedef struct tagWarpImageInfo
{
    MUINT32                 ImgAddr;                    // input image address
    MUINT32                 ImgNum;                     // input image number
    WARP_IMAGE_FORMAT       ImgFmt;                     // input image format
    MUINT16                 Width;                      // input image width
    MUINT16                 Height;                     // input image height
    MFLOAT                  Hmtx[MAV_MAX_IMAGE_NUM][9];  // input homography matrix for MAV
    MUINT32                 Flength;                    // input focal length for Autorama
    MTKWARP_DIRECTION_ENUM  Direction;                  // input capture direction for Autorama
    MUINT32                 WorkingBuffAddr;            // Working buffer start address

    MUINT32                 ClipX[MAV_MAX_IMAGE_NUM];    // image offset X
    MUINT32                 ClipY[MAV_MAX_IMAGE_NUM];    // image offset Y
    MUINT32                 ClipWidth;                  // image result width
    MUINT32                 ClipHeight;                 // image result height

    MUINT32                 ResizeEnable;               // 0:image clip / 1:image resize
} WarpImageInfo ,*P_WarpImageInfo;

// WARP_FEATURE_GET_RESULT
// Input    : NONE
// Output   : WarpResultInfo
typedef struct 
{
    MUINT32                 Width;                      // output image width for Autorama
    MUINT32                 Height;                     // output image hieght for Autorama
    MINT32                  ElapseTime[3];              // record execution time
    MRESULT                 RetCode;                    // returned status
} WarpResultInfo, *P_WarpResultInfo;


void MavInitWorkingBuffer(mav_init_struct *p_mav_init_info);
kal_int32 GetMavWorkingBufferSize(MUINT16 ImgWidth, MUINT16 ImgHeight);
void MavCoreReset(void);

MAV_CORE_PROCESS_STATE_ENUM MavCoreProcess(mav_image_info *p_mav_image_info, MavCoreResultInfo *p_mav_result,kal_uint16 ImageNumber);


#endif	// _MAV_CORE_H_