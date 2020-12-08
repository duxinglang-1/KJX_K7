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
 *   camera_sd_core.h
 *
 * Project:
 * --------
 *   MT6236
 *
 * Description:
 * ------------
 *   smile detection algorithm header file
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

#ifndef _SD_CORE_H_
#define _SD_CORE_H_

#include "sd_comm_def.h"
#include "utility_core.h"

/*-----------------------------------Macro Definition-----------------------------------------------*/
#define SD_SRC_BUFFER_SIZE (SD_IMAGE_XS*SD_IMAGE_YS*2)	// 160x120x2
#define SD_INTEGRAL_IMAGE_SIZE	(SD_IMAGE_XS*SD_IMAGE_YS*4)	// 160x120x4

#define SD_CASCADE_LAYER_NUM_24x24_RIP00    801
#define SD_CASCADE_LAYER_NUM_24x24_RIP30    401
#define SD_CASCADE_LAYER_NUM_12x12_RIP00   1249
#define SD_CASCADE_LAYER_NUM_12x12_RIP30    689

#define TRACK_POSE_SIZE_EXT_00_SD 5		 	// The number of poses SD will search for RIP00 detected faces
#define TRACK_POSE_SIZE_EXT_30_SD 5			// The number of poses SD will search for RIP30 detected faces

#define VT_HORI_SHIFT_PIXEL_SD  1                   // Horizontally shift pixel number in LFD
#define VT_VERI_SHIFT_PIXEL_SD  1				// Vertically shift pixel number in LFD

#define FACE_SIZE_NUM_24x24_MAX 7		// The number of face sizes could be detected by 24x24 learnin data
#define FACE_SIZE_NUM_12x12_MAX 3		// The number of face sizes could be detected by 12x12 learnin data
#define FD_POS_NUM	12 					// Total pose number of each degree

#define REMAP0	1						// Confidence value calculation using REMAP0 option
#define REMAP1	1						// Confidence value calculation using REMAP1 option
#define REMAP2	1						// Confidence value calculation using REMAP2 option

#define HORI_SEARCH_DISTANCE_BIGGER_12x12   8			/* Definition of LFD horizontal search */                     
#define HORI_SEARCH_DISTANCE_NORMAL_12x12   7		/* distance for each face size and    */  
#define HORI_SEARCH_DISTANCE_SMALLER_12x12  0		/* with bigger and smaller size         */
#define HORI_SEARCH_DISTANCE_BIGGER_15x15   8             
#define HORI_SEARCH_DISTANCE_NORMAL_15x15   7             
#define HORI_SEARCH_DISTANCE_SMALLER_15x15  0             
#define HORI_SEARCH_DISTANCE_BIGGER_20x20   8             
#define HORI_SEARCH_DISTANCE_NORMAL_20x20   7             
#define HORI_SEARCH_DISTANCE_SMALLER_20x20  0             
#define HORI_SEARCH_DISTANCE_BIGGER_24x24   8             
#define HORI_SEARCH_DISTANCE_NORMAL_24x24   7             
#define HORI_SEARCH_DISTANCE_SMALLER_24x24  0             
#define HORI_SEARCH_DISTANCE_BIGGER_30x30   9             
#define HORI_SEARCH_DISTANCE_NORMAL_30x30   7             
#define HORI_SEARCH_DISTANCE_SMALLER_30x30  0             
#define HORI_SEARCH_DISTANCE_BIGGER_40x40   11            
#define HORI_SEARCH_DISTANCE_NORMAL_40x40   7             
#define HORI_SEARCH_DISTANCE_SMALLER_40x40  0             
#define HORI_SEARCH_DISTANCE_BIGGER_52x52   13            
#define HORI_SEARCH_DISTANCE_NORMAL_52x52   8             
#define HORI_SEARCH_DISTANCE_SMALLER_52x52  0             
#define HORI_SEARCH_DISTANCE_BIGGER_68x68   15            
#define HORI_SEARCH_DISTANCE_NORMAL_68x68   9             
#define HORI_SEARCH_DISTANCE_SMALLER_68x68  0             
#define HORI_SEARCH_DISTANCE_BIGGER_88x88   17            
#define HORI_SEARCH_DISTANCE_NORMAL_88x88   11            
#define HORI_SEARCH_DISTANCE_SMALLER_88x88  0             
#define HORI_SEARCH_DISTANCE_BIGGER_115x115   0                                   
#define HORI_SEARCH_DISTANCE_NORMAL_115x115   13          
#define HORI_SEARCH_DISTANCE_SMALLER_115x115  7           
#define VERI_SEARCH_DISTANCE_BIGGER_12x12   8			/* Definition of LFD horizontal search */                   
#define VERI_SEARCH_DISTANCE_NORMAL_12x12   7		/* distance for each face size and    */
#define VERI_SEARCH_DISTANCE_SMALLER_12x12  0		/* with bigger and smaller size         */
#define VERI_SEARCH_DISTANCE_BIGGER_15x15   8             
#define VERI_SEARCH_DISTANCE_NORMAL_15x15   7             
#define VERI_SEARCH_DISTANCE_SMALLER_15x15  0             
#define VERI_SEARCH_DISTANCE_BIGGER_20x20   8             
#define VERI_SEARCH_DISTANCE_NORMAL_20x20   7             
#define VERI_SEARCH_DISTANCE_SMALLER_20x20  0             
#define VERI_SEARCH_DISTANCE_BIGGER_24x24   8             
#define VERI_SEARCH_DISTANCE_NORMAL_24x24   7             
#define VERI_SEARCH_DISTANCE_SMALLER_24x24  0             
#define VERI_SEARCH_DISTANCE_BIGGER_30x30   9             
#define VERI_SEARCH_DISTANCE_NORMAL_30x30   7             
#define VERI_SEARCH_DISTANCE_SMALLER_30x30  0             
#define VERI_SEARCH_DISTANCE_BIGGER_40x40   11            
#define VERI_SEARCH_DISTANCE_NORMAL_40x40   7             
#define VERI_SEARCH_DISTANCE_SMALLER_40x40  0             
#define VERI_SEARCH_DISTANCE_BIGGER_52x52   13            
#define VERI_SEARCH_DISTANCE_NORMAL_52x52   8             
#define VERI_SEARCH_DISTANCE_SMALLER_52x52  0             
#define VERI_SEARCH_DISTANCE_BIGGER_68x68   15            
#define VERI_SEARCH_DISTANCE_NORMAL_68x68   9             
#define VERI_SEARCH_DISTANCE_SMALLER_68x68  0             
#define VERI_SEARCH_DISTANCE_BIGGER_88x88   17            
#define VERI_SEARCH_DISTANCE_NORMAL_88x88   11            
#define VERI_SEARCH_DISTANCE_SMALLER_88x88  0             
#define VERI_SEARCH_DISTANCE_BIGGER_115x115   0           
#define VERI_SEARCH_DISTANCE_NORMAL_115x115   13          
#define VERI_SEARCH_DISTANCE_SMALLER_115x115  7           


typedef struct
{
	kal_uint8       sd_end_count_threshold; /* 0:once smile detected, enter capture, N:"continue" N smile detectedcam_fd_process to end the sd and enter capture */
	kal_uint8       sd_max_detect_smile_per_round; /* 1-9, max smiles for detecting in a fd process */		
	kal_uint8       sd_tolerance_count  ;
	kal_uint8       sd_smile_required_num  ;
	kal_bool        sd_main_face_must_flag;
} SD_TUNING_PARA_STRUCT, *P_SD_TUNING_PARA_STRUCT;

typedef struct
{
	kal_uint16 target_width;
	kal_uint16 target_height;
	kal_uint32 ImgFmtList;
	SD_TUNING_PARA_STRUCT sd_tuning_data;
} SD_SET_ENV_INFO_STRUCT, *P_SD_SET_ENV_INFO_STRUCT;

typedef struct
{
	kal_uint16 			ImageWidth;
	kal_uint16 			ImageHeight;
	kal_uint32			WorkingBufSize;
	MM_IMAGE_FORMAT_ENUM 		SrcImgFormat;
} SD_GET_ENV_INFO_STRUCT, *P_SD_GET_ENV_INFO_STRUCT;

typedef struct
{
	kal_uint32 ext_mem_start_addr;
	kal_uint32 ext_mem_size;
	MM_IMAGE_FORMAT_ENUM	SrcImgFormat;	
} SD_SET_PROC_INFO_STRUCT, *P_SD_SET_PROC_INFO_STRUCT;

typedef struct 
{
	UTL_CASCADED_CLASSIFIERS_STRUCT cascaded_classifiers[(SD_CASCADE_LAYER_NUM_12x12_RIP00+SD_CASCADE_LAYER_NUM_12x12_RIP30)];		// 0 degree & 30 degree
	kal_int8 	pattern_index[FD_POS_NUM/2*(SD_CASCADE_LAYER_NUM_12x12_RIP00+SD_CASCADE_LAYER_NUM_12x12_RIP30)];
	UTL_PIX_POSITION_STRUCT scaled_posed_pix_position[FACE_SIZE_NUM_12x12_MAX*(SD_CASCADE_LAYER_NUM_12x12_RIP00+SD_CASCADE_LAYER_NUM_12x12_RIP30)];

} sd_data_struct1;//learning_data_12x12_struct_sd ;

typedef struct 
{
	UTL_CASCADED_CLASSIFIERS_STRUCT cascaded_classifiers[(SD_CASCADE_LAYER_NUM_24x24_RIP00+SD_CASCADE_LAYER_NUM_24x24_RIP30)];	// 0 degree & 30 degree
	kal_int8 	pattern_index[FD_POS_NUM/2*(SD_CASCADE_LAYER_NUM_24x24_RIP00+SD_CASCADE_LAYER_NUM_24x24_RIP30)];
	UTL_PIX_POSITION_STRUCT scaled_posed_pix_position[FACE_SIZE_NUM_24x24_MAX*(SD_CASCADE_LAYER_NUM_24x24_RIP00+SD_CASCADE_LAYER_NUM_24x24_RIP30)];

} sd_data_struct2;//learning_data_24x24_struct_sd ;

typedef struct
{
	P_SD_SET_ENV_INFO_STRUCT pSdEnvInfo;	
	void* sd_data1;
	void* sd_data2;
	kal_uint8 SdLevelOption;
} SD_SET_INFO_STRUCT, *P_SD_SET_INFO_STRUCT;

typedef struct
{
	kal_uint32 *integral_img;				// Pointer to integral Image buffer
	kal_uint16 *prz_buffer_ptr;				// Pointer to a cacheable buffer copied from prz output buffer

	const sd_data_struct1 *learned_cascaded_classifiers_12x12_sd;	// Pointer to 12x12 learning data
	const sd_data_struct2 *learned_cascaded_classifiers_24x24_sd;	// Pointer to 24x24 learning data

	const kal_uint8 *detect_face_size_lut;	// Pointer to face size table
//	kal_bool  display_flag[CAMERA_SD_MAX_NO];		// Record if need to display for each face bin
	kal_uint8 face_feature_set_index[CAMERA_SD_MAX_NO];			// Record used feature set index for each face bin
	kal_uint8 detected_face_size_label[CAMERA_SD_MAX_NO];		// Record face size label for each face bin
//	kal_uint32 continuous_lfd_tracking_count[CAMERA_SD_MAX_NO];	// Record continuous lfd tracking count
	kal_uint8 face_no;/* detected face no */
	kal_int32 face_pos_x0[CAMERA_SD_MAX_NO]; 		// Position of the detected faces  
	kal_int32 face_pos_y0[CAMERA_SD_MAX_NO];
	kal_int32 face_pos_x1[CAMERA_SD_MAX_NO];
	kal_int32 face_pos_y1[CAMERA_SD_MAX_NO];	

	/* SD */
	kal_bool  sd_main_smile_must_flag[1]      ;
	kal_bool  sd_detect_flag[CAMERA_SD_MAX_NO]      ;   // SD flag
	kal_int32 sd_pos_x0[CAMERA_SD_MAX_NO]           ; 	// SD position
	kal_int32 sd_pos_y0[CAMERA_SD_MAX_NO]           ;
	kal_int32 sd_pos_x1[CAMERA_SD_MAX_NO]           ;
	kal_int32 sd_pos_y1[CAMERA_SD_MAX_NO]           ;
	kal_int8 sd_det_num[1];
	kal_int8 sd_dis_num[1];
	kal_uint8 sd_req_num[1];
//	kal_int32 sd_priority[CAMERA_SD_MAX_NO]         ;
	kal_bool  sd_display_flag[CAMERA_SD_MAX_NO]     ;
	kal_uint8 sd_display_count[CAMERA_SD_MAX_NO]    ;
	kal_uint8 sd_level;
} sd_cal_struct;

typedef struct
{
	kal_uint32 version;
	kal_uint32 sd_main_smile_must_flag[1]			;
	kal_uint32 sd_det_num[1];
	kal_uint32 sd_dis_num[1];
	kal_uint32 sd_req_num[1];
	kal_uint32 sd_end_flag;
	kal_uint32 sd_detect_flag[CAMERA_SD_MAX_NO]		;
	kal_uint32 sd_pos_x0[CAMERA_SD_MAX_NO]			;
	kal_uint32 sd_pos_y0[CAMERA_SD_MAX_NO]			;
	kal_uint32 sd_pos_x1[CAMERA_SD_MAX_NO]			;
	kal_uint32 sd_pos_y1[CAMERA_SD_MAX_NO]			;
	kal_uint32 sd_display_flag[CAMERA_SD_MAX_NO] 		;
	kal_uint32 sd_display_count[CAMERA_SD_MAX_NO]	;
	kal_uint32 face_display_pos_x0[CAMERA_SD_MAX_NO] ;
	kal_uint32 face_display_pos_y0[CAMERA_SD_MAX_NO] ;
	kal_uint32 face_display_pos_x1[CAMERA_SD_MAX_NO] ;
	kal_uint32 face_display_pos_y1[CAMERA_SD_MAX_NO] ;

	// time duration log 
	kal_uint32 frame_idx;
	kal_uint32 feature_info;		// Record used feature set index for each face bin
	kal_uint32 face_size;
	kal_uint32 mem_time;
	kal_uint32 fd_time;
	kal_uint32 sd_time; 
	kal_uint32 total_time;	//FD+SD+Dummy
	kal_uint32 sd_period_time;	//FD+SD
	kal_uint16 *prz_buf;
}SD_LOG_STRUCT,*P_SD_LOG_STRUCT;

/*----------------------------------- Function declaration-------------------------------------------*/
void SdCoreGetInfo(P_SD_GET_ENV_INFO_STRUCT pSdGetInfo);
void SdCoreSetProcInfo(P_SD_SET_PROC_INFO_STRUCT pSdSetProcInfo);
void SdCoreSetInfo(P_SD_SET_INFO_STRUCT sd_init_data);
void SdCoreMain(void *pParaIn, void*pParaOut);
void SdCoreGetResult(P_SD_RESULT_STRUCT pSdResultData);
void SdCoreSaveLog(P_SD_LOG_STRUCT sd_log_buf);

void SmileFaceDetectionEngine(sd_cal_struct *sd_cal_data);
void SmileFDDetectSizeSelection(kal_int32 fd_size_index,
								  kal_int32 *tracking_size_index1, 
								  kal_int32 *tracking_size_index2,
                                  kal_int32 sd_scaledown_step);


#endif	// _BD_CORE_H_
