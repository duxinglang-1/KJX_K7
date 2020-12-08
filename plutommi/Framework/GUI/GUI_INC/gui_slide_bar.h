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
 * gui_slide_bar.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for slide bar control.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __GUI_SLIDE_BAR_H__
#define __GUI_SLIDE_BAR_H__

/****************************************************************************
 * Include
 ****************************************************************************/
#include "gui_typedef.h"

/****************************************************************************
 * Macro
 ****************************************************************************/
#define GUI_SLIDE_BAR_TOUCH_GAP         (20)

//#if defined(__MMI_SLIM_IMG_RES__)
//    #define GUI_SLIDE_BAR_BG_MIN_HEIGHT     (20)
//#else
#if defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__)
    #define GUI_SLIDE_BAR_BG_MIN_HEIGHT     (35)
#elif defined(__MMI_MAINLCD_320X480__)
    #define GUI_SLIDE_BAR_BG_MIN_HEIGHT     (40)
#else
    #define GUI_SLIDE_BAR_BG_MIN_HEIGHT     (35)
#endif
//#endif

/****************************************************************************
 * Gloabl function
 ****************************************************************************/

/*
 * slider control
 */

#ifdef GDI_USING_LAYER
extern void gui_slide_bar_set_target_layer(slide_control *s, gdi_handle target_layer);
extern void gui_slide_bar_reset_target_layer(slide_control *s);
#endif /* GDI_USING_LAYER */ 

extern void gui_slide_bar_show_control(slide_control *s);
extern void gui_slide_bar_show_value(slide_control *s);
extern void gui_slide_bar_show_text(slide_control *s);
extern void gui_slide_bar_show_background(slide_control *s, MMI_BOOL focused);
extern void gui_slide_bar_previous(slide_control *s);
extern void gui_slide_bar_next(slide_control *s);
extern void gui_slide_bar_set_range(slide_control *s, S32 lower_limit, S32 upper_limit);
extern void gui_slide_bar_change_text(slide_control *s, U8 *label_string);
extern void gui_slide_bar_set_value(slide_control *s, S32 value);
extern void gui_slide_bar_move(slide_control *s, S32 x, S32 y);
extern void gui_slide_bar_create(slide_control *s, S32 x, S32 y, S32 lower_limit, S32 upper_limit, S32 current_value, void (*change_callback) (S32 value));

#ifdef __MMI_TOUCH_SCREEN__
extern MMI_BOOL gui_slide_bar_translate_pen_event(
                slide_control *m,
                mmi_pen_event_type_enum pen_event,
                S16 x,
                S16 y,
                gui_slide_control_pen_event_enum *slide_event,
                gui_pen_event_param_struct *slide_param);
#endif /* __MMI_TOUCH_SCREEN__ */ 
    
#endif /* __GUI_SLIDE_BAR_H__ */


