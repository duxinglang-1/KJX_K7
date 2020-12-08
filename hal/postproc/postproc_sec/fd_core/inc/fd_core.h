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
 *   fd_core.h
 *
 * Project:
 * --------
 *   MT6236
 *
 * Description:
 * ------------
 *   Face detection algorithm header file
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

#ifndef _FD_CORE_H_
#define _FD_CORE_H_

#include "fd_comm_def.h"
#include "utility_core.h"



/*-----------------------------------Macro Definition-----------------------------------------------*/
//#define abs(a) (((a) < 0) ? -(a) : (a)) 

#define FD_SRC_BUFFER_SIZE (FD_IMAGE_XS*FD_IMAGE_YS*2)	// 160x120x2
#define FD_INTEGRAL_IMAGE_SIZE	(FD_IMAGE_XS*FD_IMAGE_YS*4)	// 160x120x4

#define TRACK_POSE_SIZE_EXT_00 5		 	// The number of poses LocalFD will search for RIP00 detected faces
#define TRACK_POSE_SIZE_EXT_30 4			// The number of poses LocalFD will search for RIP30 detected faces

#define LFD_LAYER_REDUCE_24x24 170		// Total layer = 311, larger value lower calculation loading
#define LFD_LAYER_REDUCE_12x12 500		// Total layer = 845, larger value lower calculation loading

#define GAMMA_TABLE_NUM	256				// Inverse gamma table size

#define MAX_FEATURE_SELECT_INDEX 3		// RIP00, RIP-30, and RIP+30

//define FD_HAAR_PIX_MAX 2				// 2 for shrink, 8 for all, Pixel position numbers for one feature
//define FD_NUMBER_OF_BINS 12				// Confidence table size for one feature

#define FACE_SELECTION_AREA_X0 40   		/* Definition of center        */
#define FACE_SELECTION_AREA_Y0 30   		/* area to select centeral   */
#define FACE_SELECTION_AREA_X1 120  		/* face.                          */
#define FACE_SELECTION_AREA_Y1 90 

#define FACE_SIZE_NUM_MAX 10				// The max number of face sizes could be detected

#define FACE_SIZE_NUM_24x24_MAX 7		// The number of face sizes could be detected by 24x24 learnin data
#define FACE_SIZE_NUM_12x12_MAX 3		// The number of face sizes could be detected by 12x12 learnin data

#define FD_CASCADE_LAYER_NUM_24x24_MAX 481		// Total cascade layer number of 24x24 learning data
#define FD_CASCADE_LAYER_NUM_12x12_MAX 1345		// Total cascade layer number of 12x12 learning data

#define FD_POS_NUM	12 					// Total pose number of each degree
                                  
#define VT_HORI_SHIFT_PIXEL  1                   // Horizontally shift pixel number in LFD
#define VT_VERI_SHIFT_PIXEL  1				// Vertically shift pixel number in LFD

#define REMAP0	1						// Confidence value calculation using REMAP0 option
#define REMAP1	1						// Confidence value calculation using REMAP1 option
#define REMAP2	1						// Confidence value calculation using REMAP2 option

#define FD_VERI_SHIFT_PIXEL  2				// Vertically shift pixel number in GFD 
#define GFD_REGION_SHRINK_12x12	 10		/* Definition of shrink size   */                           
#define GFD_REGION_SHRINK_15x15	 8		/* for GFD region for each   */                                                                  
#define GFD_REGION_SHRINK_20x20    6		/* face size.                     */                                
#define GFD_REGION_SHRINK_24x24    5                      
#define GFD_REGION_SHRINK_30x30    2                      
#define GFD_REGION_SHRINK_40x40    2                      
#define GFD_REGION_SHRINK_52x52    2                      
#define GFD_REGION_SHRINK_68x68    2                      
#define GFD_REGION_SHRINK_88x88    0                      
#define GFD_REGION_SHRINK_115x115  0                                            
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

/*-----------------------------------------------------------------------------------------------*/

typedef enum
{
	FD_FDVT_MODE,	
	FD_LFFD_MODE,
} FD_OPERATION_MODE_ENUM;

typedef enum
{
	GFD_RST_TYPE=0,
	LFD_RST_TYPE,
	COLOR_COMP_RST_TYPE
} face_result_enum;

/*---------------------------------Struct Definition-------------------------------------------------*/
typedef struct
{
	kal_uint8 	box_vibration_tolerance;			/* 0 - 6 */    
	kal_uint8 	min_detect_face_size_index_00; 	/* 0 - 8 */              	
	kal_uint8 	min_detect_face_size_index_30; 	/* 0 - 8 */  
	kal_uint8 	frame_detect_division; 			/* 1 - 20 */
	kal_uint8		max_tracking_face_num;			/* 1 - 9 */
	kal_uint8 	error_box_closing_time; 			/* 15 - 110 */
	kal_uint8 	phone_rotation_mode; 			/* H_CR_CCR_MODE or H_CCR_CR_MODE */
	kal_uint8 	support_direction_num; 			/* 1 - 4 */
	kal_uint8		support_rip_num; 				/* RIP_00 or RIP_00_30 */
	kal_uint8		color_check_threshold;	 		/* 30 - 60 */
	kal_uint8		hori_top_det_cycle;				/* 1- 10, detection cycles in top direction */
	kal_uint8		hori_bot_det_cycle;				/* 1- 10, detection cycles in bottom direction */
	kal_uint8		hori_lft_det_cycle;				/* 1- 10, detection cycles in left direction */
	kal_uint8		hori_rgt_det_cycle;				/* 1- 10, detection cycles in right direction */
	kal_uint8		priority_mode; 					/* PRIOR_TO_SIZE, PRIOR_TO_CENTER, PRIOR_TO_BOTH_WEIGHT */
	kal_uint16	priority_weight; 					/* 0 - 256, the value is for size*/
	kal_uint8		direction_offset_horizontal ; 		/* FACE_DIR_OFST_0, FACE_DIR_OFST_270, FACE_DIR_OFST_180, FACE_DIR_OFST_90*/
       kal_uint8		direction_offset_vertical ; 		/* FACE_DIR_OFST_0, FACE_DIR_OFST_270, FACE_DIR_OFST_180, FACE_DIR_OFST_90*/
} FD_TUNING_PARA_STRUCT, *P_FD_TUNING_PARA_STRUCT;

typedef struct
{
	kal_uint16 target_width;
	kal_uint16 target_height;
	kal_uint32 ImgFmtList;
	FD_TUNING_PARA_STRUCT fd_tuning_data;
} FD_SET_ENV_INFO_STRUCT, *P_FD_SET_ENV_INFO_STRUCT;

typedef struct
{
	kal_uint16 			ImageWidth;
	kal_uint16 			ImageHeight;
	kal_uint32 			WorkingBufSize;
	MM_IMAGE_FORMAT_ENUM 		SrcImgFormat;
} FD_GET_ENV_INFO_STRUCT, *P_FD_GET_ENV_INFO_STRUCT;

typedef struct
{
	kal_uint32 ext_mem_start_addr;
	kal_uint32 ext_mem_size;
	MM_IMAGE_FORMAT_ENUM	SrcImgFormat;				
} FD_SET_PROC_INFO_STRUCT, *P_FD_SET_PROC_INFO_STRUCT;

typedef struct
{
//	MM_IMAGE_FORMAT_ENUM 	SrcImgFormat;
	FD_OPERATION_MODE_ENUM OperationMode;
}	FD_PROCESS_IN_STRUCT, *P_FD_PROCESS_IN_STRUCT;

typedef struct 
{
	UTL_CASCADED_CLASSIFIERS_STRUCT cascaded_classifiers[(FD_CASCADE_LAYER_NUM_12x12_MAX+FD_CASCADE_LAYER_NUM_12x12_MAX)];		// 0 degree & 30 degree
	kal_int8 	pattern_index[FD_POS_NUM*FD_CASCADE_LAYER_NUM_12x12_MAX];
	UTL_PIX_POSITION_STRUCT scaled_posed_pix_position[FACE_SIZE_NUM_12x12_MAX*(FD_CASCADE_LAYER_NUM_12x12_MAX+FD_CASCADE_LAYER_NUM_12x12_MAX)];

} fd_data_struct1 ; // learning_data_12x12_struct_fd 

typedef struct 
{
	UTL_CASCADED_CLASSIFIERS_STRUCT cascaded_classifiers[(FD_CASCADE_LAYER_NUM_24x24_MAX+FD_CASCADE_LAYER_NUM_24x24_MAX)];	// 0 degree & 30 degree
	kal_int8 	pattern_index[FD_POS_NUM*FD_CASCADE_LAYER_NUM_24x24_MAX];
	UTL_PIX_POSITION_STRUCT scaled_posed_pix_position[FACE_SIZE_NUM_24x24_MAX*(FD_CASCADE_LAYER_NUM_24x24_MAX+FD_CASCADE_LAYER_NUM_24x24_MAX)];

} fd_data_struct2 ;// learning_data_24x24_struct_fd 

typedef struct
{
	P_FD_SET_ENV_INFO_STRUCT pFdEnvInfo;	
	void* fd_data1;
	void* fd_data2;
	kal_uint8 FdLevelOption;
} FD_SET_INFO_STRUCT, *P_FD_SET_INFO_STRUCT;

typedef struct
{
	kal_uint32 *integral_img;				// Pointer to integral Image buffer
	kal_uint16 *prz_buffer_ptr;				// Pointer to a cacheable buffer copied from prz output buffer

	const kal_uint8 *detect_face_size_lut;	// Pointer to face size table
	const fd_data_struct1 *learned_cascaded_classifiers_12x12_fd;	// Pointer to 12x12 learning data
	const fd_data_struct2 *learned_cascaded_classifiers_24x24_fd;	// Pointer to 24x24 learning data
	
	kal_uint8 feature_select_sequence_index;	// Current feature select seq. index for g_direction_feature_sequence table
	kal_uint8 current_fd_detect_column;		// Current frame detect division index
	kal_uint8 current_direction;				// Current phone direction (1: H(0), 2: CR(-90), 3: CCR(90), 4: INV(-180))				
	kal_uint8 current_feature_index;			// Current feature index for learning data
	kal_bool	rotation_search;				// Phone rotation request flag
	kal_uint8 skip_pattern;					// Skip pixel counter used in GFD
	kal_uint8 top_skip_pattern_idx;			// Skip pixel counter used in GFD in top direction
	kal_uint8 left_skip_pattern_idx;			// Skip pixel counter used in GFD in top direction
	kal_uint8 right_skip_pattern_idx;			// Skip pixel counter used in GFD in top direction
	kal_uint8 bottom_skip_pattern_idx;		// Skip pixel counter used in GFD in top direction
	kal_bool 	is_first_frame;					// First frame check
	kal_uint8 dir_cycle_count;				// Detection cycle count
	
	kal_uint8 new_face_number;				// Face number detected by GFD
	kal_uint8 lfd_face_number;				// Face number tracked by LFD
	kal_uint8 color_compensate_face_number;	// Face number tracked by color compensate
	
//	kal_bool  af_face_indicator[MAX_FACE_SEL_NUM];	// Specify which face has highest priority for focus
	kal_uint8  fd_priority[MAX_FACE_SEL_NUM];	// face priority array, 0:highest
	kal_bool  display_flag[MAX_FACE_SEL_NUM];		// Record if need to display for each face bin
	kal_bool  box_display_position_update_flag[MAX_FACE_SEL_NUM];	// Record if need to update face rectnage
	kal_bool execute_skin_color_track[MAX_FACE_SEL_NUM];	// Record if need to execute color compensate
	kal_uint8 non_lfd_tracking_count[MAX_FACE_SEL_NUM];		// Record the non-lfd (color comp.) tracking count
	kal_uint32 face_reliabiliy_value[MAX_FACE_SEL_NUM];		// Record the reliability value for each face bin
	face_result_enum result_type[MAX_FACE_SEL_NUM];		// Record the detected result type for each face bin (GFD_RST_TYPE, LFD_RST_TYPE, COLOR_COMP_RST_TYPE)
	kal_uint8 avg_r_value[MAX_FACE_SEL_NUM];				/* Record color statistics  	*/
	kal_uint8 avg_g_value[MAX_FACE_SEL_NUM];				/* for color compensate	*/
	kal_uint8 avg_b_value[MAX_FACE_SEL_NUM];				/* for each face bin		*/
	float avg_div_rg[MAX_FACE_SEL_NUM];					

	kal_uint32 continuous_lfd_tracking_count[MAX_FACE_SEL_NUM];	// Record continuous lfd tracking count
	kal_uint8 detected_face_size_label[MAX_FACE_SEL_NUM];		// Record face size label for each face bin
	kal_uint8 face_feature_set_index[MAX_FACE_SEL_NUM];			// Record used feature set index for each face bin

	kal_int32 face_candi_pos_x0[MAX_FACE_SEL_NUM]; 		// Position of the faces candidates
	kal_int32 face_candi_pos_y0[MAX_FACE_SEL_NUM];
	kal_int32 face_candi_pos_x1[MAX_FACE_SEL_NUM];
	kal_int32 face_candi_pos_y1[MAX_FACE_SEL_NUM];

	kal_int32 face_display_pos_x0[MAX_FACE_SEL_NUM]; 		// Position of the faces to disply 
	kal_int32 face_display_pos_y0[MAX_FACE_SEL_NUM];
	kal_int32 face_display_pos_x1[MAX_FACE_SEL_NUM];
	kal_int32 face_display_pos_y1[MAX_FACE_SEL_NUM];	

	kal_uint8 face_lum[MAX_FACE_SEL_NUM];	// Face luminance for Face AE

	//HAL Add 
	kal_uint8	direction_offset ; 		/* FACE_DIR_OFST_0, FACE_DIR_OFST_270, FACE_DIR_OFST_180, FACE_DIR_OFST_90*/
	kal_uint8 fd_level;
} fd_cal_struct;

typedef struct
{
	kal_uint32  version;
	kal_uint32	frame_idx;
	kal_uint8 feature_select_sequence_index;	// Current feature select seq. index for g_direction_feature_sequence table
	kal_uint8 current_fd_detect_column;		// Current frame detect division index
	kal_uint8 current_direction;				// Current phone direction (1: H(0), 2: CR(-90), 3: CCR(90), 4: INV(-180))				
	kal_uint8 current_feature_index;			// Current feature index for learning data
	kal_uint8	rotation_search;				// Phone rotation request flag
	kal_uint8 skip_pattern;					// Skip pixel counter used in GFD
	
	kal_uint8 new_face_number;				// Face number detected by GFD
	kal_uint8 lfd_face_number;				// Face number tracked by LFD
	kal_uint8 color_compensate_face_number;	// Face number tracked by color compensate
	
//	kal_uint8  af_face_indicator[MAX_FACE_SEL_NUM];	// Specify which face has highest priority for focus
	kal_uint8  display_flag[MAX_FACE_SEL_NUM];		// Record if need to display for each face bin
	kal_uint8  box_display_position_update_flag[MAX_FACE_SEL_NUM];	// Record if need to update face rectnage
	kal_uint8 execute_skin_color_track[MAX_FACE_SEL_NUM];	// Record if need to execute color compensate
	kal_uint8 non_lfd_tracking_count[MAX_FACE_SEL_NUM];		// Record the non-lfd (color comp.) tracking count
	kal_uint32 face_reliabiliy_value[MAX_FACE_SEL_NUM];		// Record the reliability value for each face bin
	kal_uint8 result_type[MAX_FACE_SEL_NUM];				// Record the detected result type for each face bin (GFD_RST_TYPE, LFD_RST_TYPE, COLOR_COMP_RST_TYPE)
	kal_uint8 avg_r_value[MAX_FACE_SEL_NUM];				/* Record color statistics  	*/
	kal_uint8 avg_g_value[MAX_FACE_SEL_NUM];				/* for color compensate	*/
	kal_uint8 avg_b_value[MAX_FACE_SEL_NUM];				/* for each face bin		*/
	float avg_div_rg[MAX_FACE_SEL_NUM];

	kal_uint32 continuous_lfd_tracking_count[MAX_FACE_SEL_NUM];	// Record continuous lfd tracking count
	kal_uint8 detected_face_size_label[MAX_FACE_SEL_NUM];		// Record face size label for each face bin
	kal_uint8 face_feature_set_index[MAX_FACE_SEL_NUM];			// Record used feature set index for each face bin

	kal_int32 face_candi_pos_x0[MAX_FACE_SEL_NUM]; 		// Position of the faces candidates
	kal_int32 face_candi_pos_y0[MAX_FACE_SEL_NUM];
	kal_int32 face_candi_pos_x1[MAX_FACE_SEL_NUM];
	kal_int32 face_candi_pos_y1[MAX_FACE_SEL_NUM];

	kal_int32 face_display_pos_x0[MAX_FACE_SEL_NUM]; 		// Position of the faces to disply 
	kal_int32 face_display_pos_y0[MAX_FACE_SEL_NUM];
	kal_int32 face_display_pos_x1[MAX_FACE_SEL_NUM];
	kal_int32 face_display_pos_y1[MAX_FACE_SEL_NUM];

	/* FD duration log */
	kal_uint32 mem_time;
	kal_uint32 total_fdvt_time;
	kal_uint32 fdvt_period_time;

	kal_uint32 dt1;	//fd_cal_ii
	kal_uint32 dt2;	//fd_dir_sel
	kal_uint32 dt3;	//fd_local_core
	kal_uint32 dt4;	//fd_global_core
	kal_uint32 dt5;	//fd_face_merge_sort
	kal_uint32 dt6;	//lfd_time;
	kal_uint32 dt7;	//gfd_time;
}FD_LOG_STRUCT,*P_FD_LOG_STRUCT;
//} fdvt_log_struct;

 typedef struct
{
	kal_uint32 fd_cal_ii;
	kal_uint32 fd_dir_sel;
	kal_uint32 fd_local_core;
	kal_uint32 fd_global_core;
	kal_uint32 fd_face_merge_sort;
	kal_uint32 lfd_time;
	kal_uint32 gfd_time;
} fd_duration_struct;

/*-----------------------------------------------------------------------------------------------*/

/*----------------------------------- Function declaration-------------------------------------------*/

void FdCoreSetInfo(P_FD_SET_INFO_STRUCT fd_init_data);
void FdCoreGetInfo(P_FD_GET_ENV_INFO_STRUCT pFdGetInfo);
void FdCoreSetProcInfo(P_FD_SET_PROC_INFO_STRUCT pFdSetProcInfo);
void FdCoreMain(void *pParaIn, void* pParaOut);
void FdCoreReset(void);
void FdCoreGetResult(P_FD_RESULT_STRUCT pFdResultData);
void FdCoreSaveLog(P_FD_LOG_STRUCT fdvt_log_buf);

void FaceDirectionSelection(fd_cal_struct *fd_cal_data);

void GlobalFaceDetectionEngine(fd_cal_struct *fd_cal_data);

void LocalFaceDetectionEngine(fd_cal_struct *fd_cal_data);

void LocalFDDetectSizeSelection(kal_int32 fd_size_index,
								  kal_int32 *tracking_size_index1, 
								  kal_int32 *tracking_size_index2);

void FaceSkinValueStatistics(fd_cal_struct* fd_cal_data);

void FaceSkinValueInput(fd_cal_struct *fd_cal_data, kal_int32 store_label);

void FaceCandidateOverlapMerge(fd_cal_struct *fd_cal_data);

void FaceOverlapDetection(fd_cal_struct *fd_cal_data);

void FacePrioritySorting(fd_cal_struct *fd_cal_data);

void FaceBoxPositionUpdate(fd_cal_struct *fd_cal_data);

/****************************************************************************
 *          Extern Time Log Interface
 ****************************************************************************/ 
extern kal_uint32 drv_get_current_time(void);
extern kal_uint32 drv_get_duration_ms(kal_uint32 previous_time);

/*-----------------------------------------------------------------------------------------------*/
#endif	// _FD_CORE_H_

