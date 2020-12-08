/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vadp_v2p_title_bar.h
 *
 * Project:
 * --------
 *  Venus UI Components
 *
 * Description:
 * ------------
 *  This file provides the adaptation functions from the Venus MMI to 
 *  the Pluto title bar components
 *
 *      Venus ---> v2p adaptor ---> Pluto 
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *****************************************************************************/

#ifndef __VADP_V2P_TITLE_BAR_H__
#define __VADP_V2P_TITLE_BAR_H__

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gdi_datatype.h"


#ifdef __cplusplus
extern "C"
{
#endif


/**********************************************************************
 * Structure Definitions
 **********************************************************************/


/**********************************************************************
 * External Interfaces
 **********************************************************************/

extern void vadp_v2p_change_title_bar_text(U8* text);

extern void vadp_v2p_change_title_bar_left_icon(U16 image_id);

extern void vadp_v2p_change_title_bar_right_icon(U16 image_id);
                
extern void vadp_v2p_enable_integrate_title(MMI_BOOL enable);

extern void vadp_v2p_enable_shortcut_display(MMI_BOOL enable);

extern void vadp_v2p_start_title_bar_scroll(void);

extern void vadp_v2p_stop_title_bar_scroll(void);

extern void vadp_v2p_create_title_bar(
                   void (*update_screen_callback)(void *handle),
                   void *update_screen_handle,
                   gdi_handle target_layer);

extern void vadp_v2p_close_title_bar(void);

extern void vadp_v2p_show_title_bar(void);

extern void vadp_v2p_get_title_bar_prefered_size(S32 *width, S32 *height);

extern void vadp_v2p_move_title_bar(S32 x, S32 y);

extern void vadp_v2p_resize_title_bar(S32 width, S32 height);

extern U8* vadp_v2p_get_title_string(void);


#ifdef __cplusplus
}   /* extern "C" */
#endif

#endif /* __VADP_V2P_TITLE_BAR_H__ */
