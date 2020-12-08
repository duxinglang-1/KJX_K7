/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  pano_core.h
 *
 * Project:
 * --------
 *   MT6236
 *
 * Description:
 * ------------
 *   This file is intends for Panorama core algorithm.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __PANO_CORE_H__
#define __PANO_CORE_H__

#include "kal_release.h"
#include "pano_comm_def.h"

/****************************************************************************
 *          PANO Core Macro
 ****************************************************************************/
#define OVLP_RATIO              (16)        // overlap ratio (base = 64, OVLP_RATIO = 16=>16/64=1/4, OVLP_RATIO = 21=>21/64~=1/3, OVLP_RATIO = 26=>26/64~=0.4)
#define SUBSAMPLE_D             (2)         // subsample for motion estimation
#define MAX_SEAM_SIZE           (1600)      // maximum seam array size (2M)
#define BLEND_WIDTH             (20)        // blending window width
#define BLEND_ENABLE            (1)         // blending enable
#define FEATHER_BLEND           (0)
#define BLEND_SCALE             (8)
#define SEAM_COST_THRES         (5)         // clamp cost to 0 if cost below threshold
#define SHADING_BOUNDARY_ENABLE (1)
#define VERTICAL_MARGIN_RATIO   (10)        // means 1/10
#define HORIZONTAL_MARGIN_RATIO (10)        // means 1/10
#define PANO_DBG_EXIF_BASE      (150+73)
#define RGB565_BYTES_PER_PIXEL  (2)
#define PANO_MAX_IMG_NUM    (3)

/****************************************************************************
 *          PANO Core Data Structure
 ****************************************************************************/
typedef enum
{
    PANO_IDLE = 0,
    PANO_INIT_START,
    PANO_CLIP_PHASE1_START,
    PANO_CONVERT_GRAY_START,
    PANO_MOTIONESTIMATION_START,
    PANO_SEAMSELECTION_START,
    PANO_ADD_IMAGE_END,
    PANO_CALCULATEPANOSIZE_START,   
    PANO_CLIP_PHASE2_START,
    PANO_IMAGESTITCH_START,
    PANO_FINISH,
    PANO_STATE_MAX  
} PANO_OPERATION_STATE_ENUM;

typedef enum
{
    PANO_RESUME_ADD_IMAGE_STATE,
    PANO_RESUME_STITCH_STATE
} PANO_RESUME_STATE_ENUM;

typedef struct
{
    kal_int32 op_v;
    kal_int32 op_h;
    const kal_int32 *search_pos_pt;
    kal_int32 dir;
    kal_int32 op_dir;
    kal_int32 v_ori; 
    kal_int32 h_ori;
    kal_int32 kk;
    kal_int32 op_kk;
    kal_uint32 total_step_count;
    float op_ts;
    kal_bool first_time;
    kal_bool first_round;
    kal_bool small_search;
} pano_motion_estimation_struct;

typedef struct
{
    kal_uint32 snapshot_number;             // the number of images to be stitched
    kal_uint32 work_mem_addr;               // the address of working memory
    kal_uint32 work_mem_size;               // working memory size
    kal_uint32 jpeg_dec_ext_mem_addr;       // jpeg dec ext. working memory
    kal_uint32 jpeg_dec_ext_mem_size;       // jpeg dec ext. working memory size
    kal_uint8  *image_src_buffer_addr[PANO_MAX_IMG_NUM];    // source buffer address 
    kal_uint32  image_src_buffer_size[PANO_MAX_IMG_NUM];    // source buffer size               
} panoinfo_struct;

/* PANO_FEATURE_GET_ENV_INFO */
typedef struct
{
    kal_uint32  AddImageWorkingBufSize;
    kal_uint32  StitchWorkingBufSize;
    kal_uint16  OverlapRatio;
} PANO_GET_INFO_STRUCT, *P_PANO_GET_INFO_STRUCT;

/* PANO_FEATURE_SET_INFO (for PPI) */
typedef struct
{
    kal_uint16  SrcImgWidth;
    kal_uint16  SrcImgHeight;
    kal_uint16  MaxPanoImgWidth;
    kal_uint8   MaxSnapshotNumber;
    MM_IMAGE_FORMAT_ENUM SrcImgFormat;
    MM_IMAGE_FORMAT_ENUM DstImgFormat;
    PANO_DIRECTION_ENUM StitchDirection;
    kal_int32   BlendScale;
    kal_int32   UpperMargin;  
    kal_int32   LowerMargin;
    kal_int32   LeftMargin;   
    kal_int32   RightMargin;
    kal_bool    FixAe;
    kal_bool    FixAwb;
} PANO_ENV_INFO_STRUCT, *P_PANO_ENV_INFO_STRUCT;
    
#define PANO_TIME_LOG

#define TIME_LOG_BUFFER_SIZE 50
typedef struct 
{
    PANO_OPERATION_STATE_ENUM state;
    kal_uint32 time_ticks;
    kal_uint32 cur_img_num;
} pano_time_log_struct;


/****************************************************************************
 *          PANO Core Interface
 ****************************************************************************/ 
void PanoCoreSetInfo(P_PANO_ENV_INFO_STRUCT pPanoInfo);
void PanoCoreGetInfo(P_PANO_GET_INFO_STRUCT pPanoInfo);
void PanoCoreStitch(panoinfo_struct* panoinfo);
void PanoCoreAddImage(panoinfo_struct* panoinfo);
kal_uint8 PanoCoreProcess(void);
void PanoCoreExit(void);
void PanoCorePause(void);
PANO_RESUME_STATE_ENUM PanoCoreResume(panoinfo_struct* pano_info_data);
void PanoCoreGetResult(P_PANO_RESULT_STRUCT pResult);
void PanoCoreSaveLog(char* pLogBuf);

#endif /* __PANO_CORE_H__ */
