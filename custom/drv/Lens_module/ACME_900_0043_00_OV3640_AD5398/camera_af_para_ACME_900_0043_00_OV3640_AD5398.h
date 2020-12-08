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
 *   camera_af_para.h
 *
 * Project:
 * --------
 *   MT6238
 *
 * Description:
 * ------------
 *   Camera Operation Parameter 
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
 * removed!
 ****************************************************************************/
#if defined(ISP_SUPPORT)

#ifndef _CAMERA_AF_PARA_ACME_900_0043_00_OV3640_AD5398_H_
#define _CAMERA_AF_PARA_ACME_900_0043_00_OV3640_AD5398_H_

#include "camera_para.h"

/* Michael add for the LENS_SCALING_STEP.2008-09-10 */
#define AF_LENS_SCALING    5
    
 #define CAMERA_AF_DEFAULT_VALUE_ACME_900_0043_00_OV3640_AD5398   {\
	{	0,	0 },	/* af calibration offset, af calibration data */\
   	{	/* af_table_num, af_home_idx, af_macro_idx, af_infinity_idx,af_hyper_pos, af_me_home_pos, af_me_macro_pos, filter_type */\
   	{	{	12, 0, 10, 0, 5 * AF_LENS_SCALING, 5 * AF_LENS_SCALING, 216 * AF_LENS_SCALING, 1 },	\
   		{	{5 * AF_LENS_SCALING,  250}, {42 * AF_LENS_SCALING, 100}, {65 * AF_LENS_SCALING, 80}, {73 * AF_LENS_SCALING, 75},		/* 1. Normal Preview Mode*/\
			{89 * AF_LENS_SCALING, 60}, 	{112 * AF_LENS_SCALING, 50}, {127 * AF_LENS_SCALING, 40}, {135 * AF_LENS_SCALING, 30},\
			{146 * AF_LENS_SCALING, 25},	{158 * AF_LENS_SCALING, 20}, 	{181 * AF_LENS_SCALING, 10}, {202 * AF_LENS_SCALING, 5},\
			{0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00}, \
			{0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00}, \
			{0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00} \
   		}\
   	},  \
   	{	{	11, 0, 9, 0, 5 * AF_LENS_SCALING, 5 * AF_LENS_SCALING, 216 * AF_LENS_SCALING, 1 },	\
   		{	{5 * AF_LENS_SCALING,  250}, {42 * AF_LENS_SCALING, 100}, {65 * AF_LENS_SCALING, 80}, {73 * AF_LENS_SCALING, 75},		/* 2. Normal Video Mode*/\
			{89 * AF_LENS_SCALING, 60}, 	{112 * AF_LENS_SCALING, 50}, {127 * AF_LENS_SCALING, 40}, {135 * AF_LENS_SCALING, 30},\
			{146 * AF_LENS_SCALING, 25},	{158 * AF_LENS_SCALING, 20}, 	{181 * AF_LENS_SCALING, 10}, {0, 0},\
			{0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00}, \
			{0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00}, \
			{0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00}\
   		}\
   	},  \
   	{	{	0, 0, 0, 0, 0, 0, 0, 0 },	\
   		{	{0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00},\
			{0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00},\
			{0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00},\
			{0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00}, \
			{0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00},\
			{0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00}, {0x00, 0x00}\
   		}\
   	},\
   	},\
   	{7,{{84,27,48},{92,23,48},{104,15,48},{108,15,48},{116,11,24},{120,11,12},{252,11,8},{0,0,0}}},\
	{	\
	/*AF_PARAM_VERSION*/			100,\
	/*AF_PARAM_PEAK_THRE*/			254,\
	/*AF_PARAM_NOFOCUS_THRE*/		72,\
	/*AF_PARAM_STOP_THRE*/			192,\
	/*AF_PARAM_HYSTERESIS_THRE*/	254,\
	/*AF_PARAM_HYSTERESIS_DIR*/		0,\
	/*AF_PARAM_SLOW_MOVE_MAX_STEP*/	32,\
	/*AF_PARAM_SLOW_BACK_MAX_STEP*/	64,\
	/*AF_PARAM_WAIT_STABLE_THRE2*/	160,\
	/*AF_PARAM_WAIT_STABLE_THRE3*/	8,\
	/*AF_PARAM_STARTUP_POS*/		20,\
	/*AF_PARAM_STARTUP_WAIT_FRAME*/	1,\
	/*AF_PARAM_SEARCH_OPTION*/		SEARCH_OPTION_LOCALMAX|SEARCH_OPTION_NOFOCUS|SEARCH_OPTION_SWITCHTOMACRO|SEARCH_OPTION_WAIT_STABLE|SEARCH_OPTION_LENS_HOLD,\
	/*AF_PARAM_CONT_DD_STEP_RATIO*/	80,\
	/*AF_PARAM_CONT_DD_RANGE_THRE*/	48,\
	/*AF_PARAM_CONT_FV_DELTA*/	256,\
	/*AF_PARAM_CONT_FV_BLUR*/	10,\
	/*AF_PARAM_CONT_FV_DELTA_HIGH*/	224,\
	/*AF_PARAM_CONT_FV_DELTA_LOW*/	64,\
	/*AF_PARAM_CONT_AE_DELTA_HIGH*/	8,\
	/*AF_PARAM_CONT_AE_DELTA_LOW*/	2,\
	/*AF_PARAM_CONT_WAIT_STABLE_AE*/		32,\
	/*AF_PARAM_CONT_WAIT_STABLE_FV_HIGH*/	32,\
	/*AF_PARAM_CONT_WAIT_STABLE_FV_LOW*/	64,\
	/*AF_PARAM_CONT_WAIT_STABLE_FREEZE*/	3,\
	/*AF_PARAM_CONT_JUMP_COUNT_THRE*/		1,\
	/*AF_PARAM_CONT_WAIT_STABLE_MAX*/		54000,\
	/*AF_PARAM_MZ_MAX_INF_DOF*/		2,\
	/*AF_PARAM_MZ_MAX_MACRO_DOF*/	2,\
	/*AF_PARAM_END_TAG*/			0xAFAF,\
	/*AF_PARAM_RESERVED*/			0,\
	/*AF_PARAM_RESERVED*/			0,\
	/*AF_PARAM_RESERVED*/			0,\
	/*AF_PARAM_RESERVED*/			0,\
	/*AF_PARAM_RESERVED*/			0,\
	/*AF_PARAM_RESERVED*/			0,\
	/*AF_PARAM_RESERVED*/			0,\
	/*AF_PARAM_RESERVED*/			0\
	}	    \
    }


	
//#define	AF_SINGLE_MODE_IDX		(0)
//#define	AF_MULTI_ZONE_MODE_IDX	(0)
//#define	AF_FULL_SEARCH_MODE_IDX	(0)
//#define	AF_CONTINUOUS_MODE_IDX	(1)

#endif // _CAMERA_AF_PARA_H_
	#endif
	
