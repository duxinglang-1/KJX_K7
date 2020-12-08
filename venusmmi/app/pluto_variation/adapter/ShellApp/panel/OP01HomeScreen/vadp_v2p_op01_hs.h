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
 *  vadp_v2p_op01_hs.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file provides the adaptation functions from the Pluto MMI to the Venus
 *  MMI.
 *
 *      Pluto APP ---> p2v adaptor ---> Venus APP
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VADP_V2P_OP01_HS_H__
#define __VADP_V2P_OP01_HS_H__

#include "MMI_Features.h"
#ifdef __MMI_VUI_SHELL_OP01_HOMESCREEN__

/* Venus MMI headers: */
#include "ui_core\base\vfx_base.h"

#ifdef __cplusplus
extern "C"
{
#endif

/* Pluto MMI headers: */
#include "MMIDataType.h"

/**********************************************************************
 * Structure Definitions:
 **********************************************************************/

/**********************************************************************
 * External Interfaces:
 **********************************************************************/
typedef enum
{
    BUTTON_TYPE_SMS,
    BUTTON_TYPE_MMS,
    BUTTON_TYPE_CALL,
    BUTTON_TYPE_TOTAL
};

typedef enum
{
    OP01_HS_WLAN_POWER_OFF,
    OP01_HS_WLAN_POWER_WAITING,
    OP01_HS_WLAN_POWER_ON,
    OP01_HS_WLAN_CONNECT_WAITING,
    OP01_HS_WLAN_CONNECTED,
} op01_hs_wlan_state_enum;


typedef struct
{
VfxS32 image_id;
FuncPtr app_entry_hdlr;
}vadp_v2p_op01_hs_shct_struct;

extern VfxU16 vadp_v2p_hs_get_wallpaper_id(void);
extern VfxWChar* vadp_v2p_hs_get_wallpaper_filename_original(void);
extern VfxWChar* vadp_v2p_hs_get_wallpaper_filename_cached(void);
extern VfxS8 vadp_v2p_hs_phnset_check_themeid_wallpaper(VfxU16 id);
extern struct _UI_filled_area *vadp_v2p_hs_get_theme_bg_filled_area(void);
extern void vadp_v2p_hs_phnset_wallpaper_bad_file_callback(VfxS8 is_prohibited);

extern void vadp_v2p_hs_launch_dialer(void);
extern void vadp_v2p_hs_launch_main_menu(void);
extern void vadp_v2p_hs_launch_date_time(void);

extern void vadp_v2p_hs_launch_call_inbox(void);
extern void vadp_v2p_hs_launch_sms_inbox(void);
extern void vadp_v2p_hs_launch_mms_inbox(void);

extern void vadp_v2p_hs_switch_wlan_req(void);
extern op01_hs_wlan_state_enum vadp_v2p_hs_get_wlan_state(void);

extern VfxS32 vadp_v2p_hs_get_unread_sms_number(void);
extern VfxS32 vadp_v2p_hs_get_unread_mms_number(void);
extern VfxS32 vadp_v2p_hs_get_unread_call_number(void);

extern VfxS32 vadp_v2p_hs_is_search_box_enable(void);
extern VfxS32 vadp_v2p_hs_is_wlan_box_enable(void);

extern void vadp_v2p_op01_hs_get_shct_info(VfxS32 *count, VfxS32 *res_id, FuncPtr *pen_handler);

extern VfxS32 vadp_v2p_op01_hs_get_shct_first_icon_index(void);
extern void vadp_v2p_op01_hs_set_shct_first_icon_index(VfxS32 index);

#ifdef __cplusplus
}   /* extern "C" */
#endif

#endif /* __MMI_VUI_SHELL_OP01_HOMESCREEN__ */
#endif /* __VADP_V2P_OP01_HS_H__ */

