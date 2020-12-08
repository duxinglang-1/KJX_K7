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
 *  wgui_icon_bar.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Public Header
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
#ifndef __WGUI_ICON_BAR_H__
#define __WGUI_ICON_BAR_H__

/*****************************************************************************
 * include
 ****************************************************************************/
#include "MMI_features.h"
#include "gui_icon_bar.h"

#include "wgui.h"
/*****************************************************************************
 * Define
 ****************************************************************************/
#ifdef __MMI_FTE_SUPPORT__

#if defined(__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__)
#define WGUI_ICONBAR_ITEM_WIDTH_4           60
#define WGUI_ICONBAR_ITEM_WIDTH_3           80
#define WGUI_ICONBAR_ITEM_WIDTH_2           120
#define WGUI_ICONBAR_ITEM_WIDTH_1           240
#else
#define WGUI_ICONBAR_ITEM_WIDTH_4           80
#define WGUI_ICONBAR_ITEM_WIDTH_3           106
#define WGUI_ICONBAR_ITEM_WIDTH_2           160
#define WGUI_ICONBAR_ITEM_WIDTH_1           320
#endif

#define WGUI_ICONBAR_ITEM_HEIGHT            MMI_ICON_BAR_HEIGHT
#define WGUI_ICONBAR_ITEM_GAP               0
#define WGUI_ICONBAR_MAX_COUNT              4

#endif /* __MMI_FTE_SUPPORT__ */
#ifdef __MMI_ICON_BAR_SUPPORT__
/*****************************************************************************
 * Typedef
 ****************************************************************************/


/*****************************************************************************
 * Global Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  wgui_icon_bar_setup_ex
 * DESCRIPTION
 *  Set up an idle icon bar component content. It is the extend API of
 *  wgui_icon_bar_setup.
 * PARAMETERS
 *  item_count              : [IN] Is the count of items that need display
 *  normal_icon             : [IN] Is up image of item
 *  down_icon               : [IN] Is down image of item
 *  content_icon            : [IN] Is content image of item
 *  disabled_content_icon   : [IN] Is item's content image of its disabled state
 *  string                  : [IN] Is description of item
 *  callback                : [IN] Is callback function when item pressed
 *  enable_key_event        : [IN] Is enable the left/right key event or not
 *  hint_use_double_buffer  : [IN] Use double buffer to display hint
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_icon_bar_setup_ex(
             S32 item_count,
             PU8* normal_icon,
             PU8* down_icon,
             PU8* content_icon,
             PU8* disabled_content_icon,
             PU8* string,
             GUIIconbarItemCallback callback,
             MMI_BOOL enable_key_event,
             MMI_BOOL hint_use_double_buffer);
extern void wgui_icon_bar_set_item(
             U32 index,
             U8 *normal_icon,
             U8 *down_icon,
             U8 *content_icon,
             U8 *disabled_content_icon,
             U8 *text_of_description,
             GUIIconbarItemCallback callback);
extern void wgui_icon_bar_set_arrow_icon(
             gui_icon_bar_arrow_enum arrow,
             U8 *normal_icon,
             U8 *down_icon);
extern void wgui_icon_bar_set_highlight_icon(U8 *highlight_icon);
extern void wgui_icon_bar_register_update_handler(
             MMI_BOOL (*dynamic_update_handler)(
                         U32 start_index,
                         U32 item_count,
                         PU8 *normal_icon,
                         PU8 *down_icon,
                         PU8 *content_icon,
                         PU8 *disabled_content_icon,
                         PU8 *text_of_description));
extern void wgui_icon_bar_register_highlight_handler(void (*f)(S32 index));
extern void wgui_icon_bar_active(void);
extern void wgui_icon_bar_deactive(void);
#endif//__MMI_ICON_BAR_SUPPORT__

#endif /* __WGUI_ICON_BAR_H__ */


