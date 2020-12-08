/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   camera_pano_core.h
 *
 * Project:
 * --------
 *   MT6238
 *
 * Description:
 * ------------
 *   Panorama algorithm header file
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _AUTPCAP_CORE_H_
#define _AUTPCAP_CORE_H_


#include "kal_release.h"
#include "autocap_comm_def.h"

#define ABS(a) (((a) < 0) ? (-(a)) : (a))
#define MAX(a,b) (((a)>(b))? (a) : (b))
#define MIN(a,b) (((a)<(b))? (a) : (b))


/****************************************************************************
 *          AUTOCAP PANO Core State Enum
 ****************************************************************************/

///////////////tunning parameters///////////////////////////////////
#define OVERLAP_RATIO                   (32)      //32-->overlapping ratio is 50%, 16-->overlapping ratio is 25%, etc.
#define SAD_SUBSAMPLE_D                 (4)       //Sub-smaple ratio in both direction 
#define AUTOCAP_TOLERANCE_X             (8)       //if difference between mv and dest mv(overlap width), ready to shot
#define AUTOCAP_TOLERANCE_Y             (8)      //if difference between mv and dest mv(overlap width), ready to shot
#define DIR_DECIDE_MV_X                 (30)      //if mv is bigger than this value, the autpcap direction is decided
#define DIR_DECIDE_MV_Y                 (23)      //if mv is bigger than this value, the autpcap direction is decided


///////////////const parameters//////////////////////////////////////
#define CAMERA_AUTOCAP_IMAGE_BYTES      (2)       //Because the input format is RGB565 
#define MAX_FAST_SEARCH_MV              (10)      //the base of g_max_fast_search_mv, if 160*120, g_max_fast_search_mv=10, if 320*240, g_max_fast_search_mv=20, Max search range of fast search before jump to small search
#define OVERFLOW_FRAME_JUMP             (10)      //If motion>20, count_overflow++, and last frame won't update except count_overflow>=OVERFLOW_FRAME_JUMP
#define MV_THRESHOLD                    (2)       //Search range around 0 for uniform region
#define	SAD_THRESHOLD                   (13)      //Real threshold = SAD_THRESHOLD/10.  The best SAD should be higher than first or center SAD with this ratio to prove it reliablity in uniform frame
#define	MV_LIMITOR                      (8)       //Max/Min MV in vertical(horizontal) direction when pano_dir is right or left (up or down)
#define UNIFORM_FAST_ENABLE             (0)       //0: no fast search for uniform case, 1: open fast search for uniform case 
#define UNIFORM_SEARCH_RANGE_LARGE      (7)       //Larger full search range for uniform case. For right and left, it is for x dimension; otherwise, it is for y dimension.
#define UNIFORM_SEARCH_RANGE_SMALL      (3)       //Smaller full search range for uniform case. For up and down, it is for y dimension; otherwise, it is for x dimension.
#define UNIFORM_SEARCH_RANGE_NO_DIR     (3)       //Full search range for no direction situation
#define MARGIN_X                        (4)       //must not zero!! should be a multiple of 4. Define the non-use region of the boundary.
#define MARGIN_Y                        (4)       //must not zero!! should be a multiple of 4. Define the non-use region of the boundary.
#define NORMAL_FULL_SEARCH_RANGE_LARGE  (3)       //The search range of normal case
#define NORMAL_FULL_SEARCH_RANGE_SMALL  (2)       //The search range of normal case
#define MAX_COUNT                       (200)     //Control the largest iteration of motion estimation
#define MAX_TYPE_THRESHOLD              (900000)  //max_block threshold to check if the uniform case or not, if edge value is bigger than this, type is 0~9 not uniform, else type is 10-27, uniform case
#define NORMAL_CASE_NUM                 (10)      //Totally 10 differcne normal cases
#define SAD_DIFF_TOL                    (1)
#define COLOR_TRANSFORM_QUALITY         (0)       //the number is bigger, the Y quality is better, but spent more time
                                                  //>2=>R:G:B=306:601:117, 2=>R:G:B=2:5:1, 1=>1:2:1 0:only G channel
#define INITIAL_GMV_ENABLE              (1)       //If INITIAL_GMV_ENABLE==1, using previous GMV as initial MV for non-uniform case; else, initial MV = 0

#define IUL_I_TO_X(i)         ((i) << 16)                ///< Convert from integer to S15.16 fixed-point
#define IUL_X_TO_I(x)         (((x) + (1 << 15)) >> 16)  ///< Convert from S15.16 fixed-point to integer (round)
#define IUL_X_TO_I_CHOP(x)    ((x) >> 16)                ///< Convert from S15.16 fixed-point to integer (chop)
#define IUL_X_TO_I_CARRY(x)   (((x) + 0x0000FFFF) >> 16) ///< Convert from S15.16 fixed-point to integer (carry)
#define IUL_X_FRACTION(x)     ((x) & 0x0000FFFF)


/*-----------------------------------Color Space Transformation-------------------------------------*/
#define RGB565_R_MASK 0xF800
#define RGB565_G_MASK 0x07E0
#define RGB565_B_MASK 0x001F

#define RGB565_TO_RGB888_R(VALUE)   ((((VALUE) & RGB565_R_MASK)>>8))
#define RGB565_TO_RGB888_G(VALUE)   ((((VALUE) & RGB565_G_MASK)>>3))
#define RGB565_TO_RGB888_B(VALUE)   ((((VALUE) & RGB565_B_MASK)<<3))

#define	RGB888_TO_RGB565(R,G,B)		(((((R)+4) >> 3)<<11) | ((((G)+2)>>2)<<5) | (((B)+4)>>3))	
// the equation above will not result in overflow because input RGB comes from color interpolation of source RGB565 images.
// therefore maximum input RGB value is (255-7,255-3,255-7), hence overflow would not occur (R+4<255, G+2<255, B+4<255).

#if(COLOR_TRANSFORM_QUALITY == 2)
#define RGB888_TO_YUV_Y(R, G, B)    (  (R<<1) + (G<<2)+ (G) + (B) >> 3)
#elif(COLOR_TRANSFORM_QUALITY == 1)
#define RGB888_TO_YUV_Y(R, G, B)    (  (R) + (G<<1)+ (B) >>2)
#elif(COLOR_TRANSFORM_QUALITY >= 3)
#define RGB888_TO_YUV_Y(R, G, B)    ((  306 * (R) + 601 * (G) + 117 * (B) + 512) >> 10)
#endif
/****************************************************************************
 *          AUTOCAP PANO Core State Enum
 ****************************************************************************/
typedef enum
{
     AUTOCAP_IDLE_MODE=0,
     AUTOCAP_READY_MODE,
     AUTOCAP_BUSY_MODE,	
} AUTOCAP_OPERATION_MODE_ENUM;

typedef enum
{
    AUTOCAP_PROCESS_OK,
    AUTOCAP_ERROR_STATE,

} AUTOCAP_ERROR_ENUM;

typedef enum
{
     AUTOCAP_IMAGE_FORMAT_RGB565=0,
     AUTOCAP_IMAGE_FORMAT_YUV420,
     AUTOCAP_IMAGE_FORMAT_MAX,
} AUTOCAP_IMAGE_FORMAT_ENUM;
/****************************************************************************
 *          AUTOCAP PANO Core Struct
 ****************************************************************************/
typedef struct
{
	/* autocap log */
	kal_uint16 frame_idx;
	kal_uint16 me_time;
	kal_uint16 period_time;
	kal_int32 mv_x;
	kal_int32 mv_y;
	kal_int32 accu_mv_x;
	kal_int32 accu_mv_y;
	kal_uint16 step_count;
	float min_sad;
	kal_uint8 ready_to_shot;
} autocap_log_struct;
/* for ALGO interface */
typedef struct
{
     kal_uint32 ext_mem_start_addr;     /* working mem for autocap alg */
     kal_uint32 ext_mem_size;
     kal_uint16 image_width;	              /* prz frame size */
     kal_uint16 image_height;
     kal_uint16 lcd_width;                   /* lcd frame size */
     kal_uint16 lcd_height;
     kal_bool log_enable;		
     kal_uint32 log_mem_start_addr;
     kal_uint32 log_mem_size;
     kal_uint32 tolerance_x;
     kal_uint32 tolerance_y;
     kal_uint32 image_format;
} camera_autocap_init_struct;

typedef struct
{
     kal_uint32 ext_mem_start_addr;     /* working mem for autocap alg */
     kal_uint32 ext_mem_size;
     
} camera_autocap_set_mem_struct;

typedef enum
{
        AUTOCAP_IDLE,
        AUTOCAP_BUFFER_BUSY,	
        AUTOCAP_ALG_BUSY
} CAMERA_AUTOCAP_STATE_ENUM;
/* for MED/ALGO interface */
typedef struct
{
     /* motion tracking results */
     kal_int16 mv_x;		        /* horizontal accumulated motion */
     kal_int16 mv_y;		        /* vertical accumulated motion */
     kal_bool ready_to_shot;		/* ready to shot flag */
     AUTOCAP_DIRECTION_ENUM direction; /* stitch direction */
     AUTOCAP_HINT_DIRECTION_ENUM hint_direction; /* hint to user direction */
} camera_autocap_result_struct;

//#define AUTOCAP_TIME_LOG
/****************************************************************************
 *          AUTOCAP PANO Core Interface
 ****************************************************************************/
void AutoCapCoreSetInfo(camera_autocap_init_struct* autocap_init_para);
void AutoCapCoreSetProcInfo(camera_autocap_set_mem_struct* autocap_set_mem_para);
void AutoCapCoreResetMV(void);
AUTOCAP_ERROR_ENUM AutoCapCoreProcess(kal_uint32 image_address, camera_autocap_result_struct *result);
void AutoCapCoreExit(void);
#endif	// _AUTPCAP_CORE_H_

