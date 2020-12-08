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
 *	resource_vt_skins.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Video Telephony customization file.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef RESOURCE_VT_SKIN_H
#define RESOURCE_VT_SKIN_H

#include "MMI_features.h"
#if defined(__MMI_VIDEO_TELEPHONY__) 

#ifdef  __MMI_FTE_SUPPORT__
#if defined(__MMI_MAINLCD_320X480__)||defined(__MMI_MAINLCD_240X320__)||defined(__MMI_MAINLCD_240X400__)
#define __MMI_FTE_VT_ENHANCE__
#endif

#if defined(__MMI_MAINLCD_240X320__)
#define __MMI_FTE_VT_SUBWND_BG__
#endif

#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/
typedef enum {
	MMI_VTCS_TEXT_STYLE_NORMAL,
	MMI_VTCS_TEXT_STYLE_BORDER,
	MMI_VTCS_TEXT_STYLE_SHADOW	
} mmi_vtcs_text_style;


/***************************************************************************** 
 * Struct
 *****************************************************************************/
typedef struct
{
	S32 offset_x;
	S32	offset_y;
	S32	width;
	S32 height;
} mmi_vtcs_rect_struct;


typedef struct
{
	S32	offset_x;
	S32 offset_y;
} mmi_vtcs_pos_struct;


typedef struct {
	U8	r;
	U8	g;	
	U8	b;		
	U8	border_r;
	U8	border_g;	
	U8	border_b;
} mmi_vtcs_text_color_struct;


typedef struct {
    /* bg */
    mmi_vtcs_rect_struct  status_rect;    
    mmi_vtcs_rect_struct  title_rect;
    mmi_vtcs_rect_struct  body_rect; 
    mmi_vtcs_rect_struct  panel_0_rect;    
    mmi_vtcs_rect_struct  panel_1_rect;
    mmi_vtcs_rect_struct  softkey_rect;
    
    /* video window */
    mmi_vtcs_rect_struct  main_wnd_rect; 
    mmi_vtcs_rect_struct  sub_wnd_rect; 
    mmi_vtcs_pos_struct   sub_bg_pos; 

    /* icons */ 
    mmi_vtcs_pos_struct  icon_1_pos;
    mmi_vtcs_pos_struct  icon_2_pos;
    mmi_vtcs_pos_struct  icon_3_pos;    
    mmi_vtcs_pos_struct  icon_4_pos;
    mmi_vtcs_pos_struct  icon_5_pos;
    mmi_vtcs_pos_struct  icon_6_pos;    
    mmi_vtcs_pos_struct  icon_7_pos;   
    mmi_vtcs_pos_struct  icon_8_pos;   
    mmi_vtcs_pos_struct  icon_9_pos;   
    mmi_vtcs_pos_struct  icon_10_pos;       
    mmi_vtcs_pos_struct  icon_11_pos;      

    /* time/cost */
    mmi_vtcs_pos_struct  time_pos;
    mmi_vtcs_pos_struct  cost_pos;   
 
    /* scrollbar */
    mmi_vtcs_pos_struct  inc_icon_pos;
    mmi_vtcs_pos_struct  dec_icon_pos;    
    mmi_vtcs_pos_struct  scroll_bar_pos;

    /* user input */
    mmi_vtcs_rect_struct input_box_rect;
    mmi_vtcs_pos_struct  input_box_bg_pos;

    /* vk */
    mmi_vtcs_pos_struct vk_0_pos;
    mmi_vtcs_pos_struct vk_1_pos;    
    mmi_vtcs_pos_struct vk_2_pos;        
    mmi_vtcs_pos_struct vk_3_pos;            
    mmi_vtcs_pos_struct vk_4_pos;                
    mmi_vtcs_pos_struct vk_5_pos;                    
    mmi_vtcs_pos_struct vk_6_pos;
    mmi_vtcs_pos_struct vk_7_pos;    
    mmi_vtcs_pos_struct vk_8_pos;
    mmi_vtcs_pos_struct vk_9_pos;    
    mmi_vtcs_pos_struct vk_star_pos;        
    mmi_vtcs_pos_struct vk_pound_pos;    
	#if defined(__OP01__) && defined(__MMI_FTE_SUPPORT__)
	mmi_vtcs_pos_struct contrast_bg;  
	#endif
    #if defined(__MMI_FTE_VT_SUBWND_BG__)
	mmi_vtcs_pos_struct subwnd_bg;  
	#endif
    
	mmi_vtcs_pos_struct  fullscr_skin_bg_pos;   
    mmi_vtcs_pos_struct  fullscr_main_wnd_pos;   
    mmi_vtcs_pos_struct  fullscr_sub_wnd_pos;   
    mmi_vtcs_pos_struct  fullscr_sub_bg_pos; 
	mmi_vtcs_pos_struct  fullscr_time_pos; 
    /* text sytle */
    mmi_vtcs_text_color_struct text_color;
} mmi_vtcs_skin_struct;

typedef struct {
	mmi_vtcs_pos_struct line1;
	mmi_vtcs_pos_struct	line2;
	mmi_vtcs_pos_struct	line3;	
	mmi_vtcs_pos_struct line4;
	mmi_vtcs_pos_struct	scroll_line1;
	mmi_vtcs_pos_struct	scroll_line2;
} mmi_vtcs_line_struct;

/***************************************************************************** 
 * Extern
 *****************************************************************************/
extern mmi_vtcs_skin_struct g_mmi_vtcs_skin_cntx;

#ifdef __MMI_FTE_SUPPORT__
extern mmi_vtcs_line_struct g_mmi_vtcs_line_cntx;
#endif

#endif /* __MMI_VIDEO_TELEPHONY__ */
#endif /* RESOURCE_VT_SKIN_H */


