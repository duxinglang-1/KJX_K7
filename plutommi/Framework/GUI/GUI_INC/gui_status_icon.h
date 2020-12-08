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
 * gui_status_icon.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for status icon bars control.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __GUI_STATUS_ICON_H__
#define __GUI_STATUS_ICON_H__

#include "wgui_categories.h"
#include "wgui_include.h"
#include "gui_status_icon_bar_pre_oem.h"
#include "gui_status_icon_bar.h"

#include "MMIDataType.h"
#include "kal_general_types.h"


/****************************************************************************
 * Flags of icon
 ****************************************************************************/

#define GUI_STATUS_ICON_BAR_ICON_DEFAULT     0x00000000
#define GUI_STATUS_ICON_BAR_ICON_DISPLAY     0x00000001
#define GUI_STATUS_ICON_BAR_ICON_ANIMATE     0x00000002
#define GUI_STATUS_ICON_BAR_ICON_BLINK       0x00000004
#define GUI_STATUS_ICON_BAR_ICON_BLINK_ON    0x00000008


/****************************************************************************
 * Struct
 ****************************************************************************/

typedef enum
{
    GUI_STATUS_ICON_BAR_ICON_NO_GROUP,
    GUI_STATUS_ICON_BAR_ICON_LINE_SWITCH_GROUP,
    GUI_STATUS_ICON_BAR_ICON_CALL_GROUP,
    GUI_STATUS_ICON_BAR_ICON_RING_GROUP,
    GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP,
    GUI_STATUS_ICON_BAR_ICON_NETWORK1_GROUP,
    GUI_STATUS_ICON_BAR_ICON_VOICE_GROUP,
    GUI_STATUS_ICON_BAR_ICON_FAX_GROUP,
    GUI_STATUS_ICON_BAR_ICON_EMAIL_GROUP,
    GUI_STATUS_ICON_BAR_ICON_NET_GROUP,
    GUI_STATUS_ICON_BAR_ICON_VIDEO_GROUP,
    GUI_STATUS_ICON_BAR_ICON_IMPS_GROUP,
    GUI_STATUS_ICON_BAR_ICON_PRINT_GROUP,
    GUI_STATUS_ICON_BAR_ICON_ROAMING_GROUP,
    GUI_STATUS_ICON_BAR_ICON_HOMEZONE_GROUP,
    GUI_STATUS_ICON_BAR_ICON_EARPHONE_GROUP,
    GUI_STATUS_ICON_BAR_ICON_CONTACT_GROUP,
    GUI_STATUS_ICON_BAR_ICON_PUSH_GROUP,
    GUI_STATUS_ICON_BAR_ICON_SUBLCD_RING_GROUP,
    GUI_STATUS_ICON_BAR_ICON_END_GROUP
} gui_status_icon_bar_icon_group_enum;


typedef struct
{
    S32 x, y;               /* Offset within a status icon bar                    */
    S32 width, height;      /* For quick lookup                             */
    S32 image_id;           /* MMI_ID_TYPE of the icon                         */
    PU8 image_data;         /* For quick lookup                             */
    S16 n_frames;           /* For quick lookup                             */
    S16 current_frame;      /* For animated icons                              */
    U32 flags;              /* Internal flags: See flag names below               */
    U8 state;               /* For icons with multiple states                     */
    gui_status_icon_bar_icon_group_enum group;            /* 0: No group, 1,2,3 ... Groups                   */
} gui_status_icon_bar_icon_struct;


typedef struct
{
    /* The x coordinate of element */
    S32 x;
    /* The y coordinate of element */
    S32 y;
    /* The width of element */
    S32 width;
    /* The height of element */
    S32 height;
    /* the show function of the element */
    void (*show)(S32 x1, S32 y1, S32 x2, S32 y2);
    /* the flag of element */
    U32 flag;
    /* whether the element have be created */
    MMI_BOOL active;
} gui_status_icon_bar_element_struct;


/****************************************************************************
 * Function
 ****************************************************************************/
extern void gui_status_icon_bar_enable_icon_display(gui_status_icon_bar_icon_struct *icon, MMI_BOOL enable);
extern void gui_status_icon_bar_enable_icon_animate(gui_status_icon_bar_icon_struct *icon, MMI_BOOL enable);
extern void gui_status_icon_bar_enable_icon_blink(gui_status_icon_bar_icon_struct *icon, MMI_BOOL enable);
extern void gui_status_icon_bar_change_icon_level(gui_status_icon_bar_icon_struct *icon, S32 level);
extern S32 gui_status_icon_bar_get_icon_frame_number(gui_status_icon_bar_icon_struct *icon);
extern void gui_status_icon_bar_change_icon_image(gui_status_icon_bar_icon_struct *icon, S32 image_id);
extern void gui_status_icon_bar_change_icon_image_ex(gui_status_icon_bar_icon_struct *icon, PU8 image_data);
extern S32 gui_status_icon_bar_get_icon_image_id(gui_status_icon_bar_icon_struct *icon);
extern void gui_status_icon_bar_set_icon_flag(gui_status_icon_bar_icon_struct *icon, U32 flag);
extern U32 gui_status_icon_bar_get_icon_flag(gui_status_icon_bar_icon_struct *icon);
extern MMI_BOOL gui_status_icon_bar_get_icon_area(gui_status_icon_bar_icon_struct *icon, S32 *x1, S32 *y1, S32 *x2, S32 *y2);
extern MMI_BOOL gui_status_icon_bar_whether_icon_display(gui_status_icon_bar_icon_struct *icon);
extern void gui_status_icon_bar_get_icon_position(gui_status_icon_bar_icon_struct *icon, S32 *x, S32 *y);
extern void gui_status_icon_bar_get_icon_size(gui_status_icon_bar_icon_struct *icon, S32 *width, S32 *height);
extern void gui_status_icon_bar_show_integrated_icon(gui_status_icon_bar_icon_struct *icon, S32 x, S32 y);
extern void (*gui_status_icon_bar_show_icon)(gui_status_icon_bar_struct *bar, gui_status_icon_bar_icon_struct *icon);
extern void gui_status_icon_bar_initialize_icon(void);

extern void gui_status_icon_bar_create_element(gui_status_icon_bar_element_struct *element, S32 width, S32 height, void (*show)(S32 x1, S32 y1, S32 x2, S32 y2), U32 flag);
extern void gui_status_icon_bar_register_element_show(gui_status_icon_bar_element_struct *element, void (*show)(S32 x1, S32 y1, S32 x2, S32 y2));
extern void gui_status_icon_bar_resize_element(gui_status_icon_bar_element_struct *element, S32 width, S32 height);
extern void gui_status_icon_bar_close_element(gui_status_icon_bar_element_struct *element);

#include "gui_status_icon_bar_post_oem.h"

#endif /* __GUI_STATUS_ICON_H__ */

