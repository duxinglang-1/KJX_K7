/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  gui_title_post_oem.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intends for title.
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
#ifndef __GUI_TITLE_POST_OEM_H__
#define __GUI_TITLE_POST_OEM_H__

#include "MMI_features.h"
#include "gui_config.h"
#include "wgui.h"

#include "MMIDataType.h"
#include "gui_title_pre_oem.h"
#include "gdi_datatype.h"

extern S32 gui_title_oem_show_normal(gui_title_struct *t, U32 part);
extern void gui_title_oem_show_background(gui_title_struct *t, S32 x, S32 y, S32 w, S32 h);
extern gdi_handle gui_title_setup_target_lcd_and_layer(gui_title_struct *t);
extern void gui_title_restore_target_lcd_and_layer(gui_title_struct *t, gdi_handle old_lcd_handle);
extern void gui_title_measure_oem(gui_title_struct *t, U32 part, S32 *x1, S32 *x2, S32 *h);
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
extern void gui_title_show_status_icon_oem(gui_title_struct *t);
#endif

#endif /*__GUI_TITLE_POST_OEM_H__*/

