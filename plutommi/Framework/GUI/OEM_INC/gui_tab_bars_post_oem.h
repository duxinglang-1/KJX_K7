/*******************************************************************************
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
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  gui_tab_bars_post_oem.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intends for tab bars.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *     HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __GUI_TAB_BARS_POST_OEM_H__
#define __GUI_TAB_BARS_POST_OEM_H__

#include "MMIDataType.h"
#include "gui_tab_bars_pre_oem.h"
#include "gdi_datatype.h"

#ifdef __MMI_OP11_TAB_BAR__
    extern void gui_horizontal_tab_bar_show_item_OG(horizontal_tab_bar *tb, S8 i);
    extern void gui_horizontal_tab_bar_show_focused_item_OG(horizontal_tab_bar *tb);
    extern void gui_show_horizontal_tab_bar_OG(horizontal_tab_bar *tb, BOOL disable_tab_area, BOOL disable_hint_area);
#else
    extern void gui_horizontal_tab_bar_show_item_normal(horizontal_tab_bar *tb, S8 i);
    extern void gui_horizontal_tab_bar_show_focused_item_normal(horizontal_tab_bar *tb);
    extern void gui_show_horizontal_tab_bar_normal(horizontal_tab_bar *tb, BOOL disable_tab_area, BOOL disable_hint_area);
#endif /* __MMI_OP11_TAB_BAR__ */

extern void gui_horizontal_tab_bar_focused_scrolling_text_handler_oem(void);
extern void gui_horizontal_tab_bar_locate_focused_item_oem(horizontal_tab_bar *tb);
extern void gui_horizontal_show_status_icon_oem(void);
extern gdi_handle gui_horizontal_tab_bar_setup_target_lcd_and_layer_oem(horizontal_tab_bar *tb);
extern void gui_horizontal_tab_bar_restore_target_lcd_and_layer_oem(horizontal_tab_bar *tb, gdi_handle old_lcd_handle);

#endif /*__GUI_TAB_BARS_POST_OEM_H__*/


