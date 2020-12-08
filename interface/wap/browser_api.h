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

/*******************************************************************************
 * Filename:
 * ---------
 *   browser_api.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains prototypes for exported browser APIs
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *                              HISTORY
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
#ifdef BROWSER_SUPPORT

#ifndef _BROWSER_API_H
#define _BROWSER_API_H 

#include "kal_general_types.h"


typedef enum
{
    WAP_BROWSER_GOTO_MAIN_MENU,
    WAP_BROWSER_GOTO_HOMEPAGE,
    WAP_BROWSER_GOTO_URL,
    WAP_BROWSER_ADD_BOOKMARK,
    WAP_BROWSER_GOTO_URL_BACKGROUND,
    WAP_BROWSER_GOTO_OP_HOMEPAGE,
    WAP_BROWSER_VIEW_PUSH_MSG = 8,
    WAP_BROWSER_VIEW_PUSH_MSG_DIRECTLY = 9,
    WAP_BROWSER_LOW_MEMORY
} wap_browser_startup_opt_enum;


typedef enum
{
    MMI_BRW_SIM_ID_DEFAULT = 0,
    MMI_BRW_SIM_ID_SIM1,
    MMI_BRW_SIM_ID_SIM2,
    MMI_BRW_SIM_ID_SIM3,
    MMI_BRW_SIM_ID_SIM4,
    MMI_BRW_SIM_ID_ALWAYS_ASK,
    MMI_BRW_SIM_ID_WLAN,
    MMI_BRW_SIM_ID_TOTAL
} mmi_brw_sim_id_enum;

extern int wap_entry_select_bookmark (void);
extern void goto_mobile_suite_screen(void); /* mmi_browser_hilite_hdlr */
extern int wap_start_browser(kal_uint8 option, const kal_uint8 *url);
extern int wap_browser_is_open(void);
extern kal_uint16 wap_get_screen_id(void);
extern void wap_internet_key_hdlr(void);

extern kal_bool mmi_brw_is_browser_active(void);
extern void mmi_brw_show_bookmarks_list(void);
extern kal_bool mmi_brw_is_active_profile_in_use(mmi_brw_sim_id_enum sim_id);
extern void mmi_brw_load_service_message(kal_uint8 *url, kal_bool is_from_inbox, kal_uint16 sim_id);
extern kal_bool mmi_brw_scrn_is_present(void);
extern void mmi_brw_app_init(void);
extern void mmi_brw_bookmarks_recv_file_view (kal_uint8 *file_path, kal_uint8 *file_name);
extern void mmi_brw_bookmarks_recv_file_save_to_bookmark (kal_uint8 *file_path, kal_uint8 *file_name, kal_uint8 *file_extn);
extern void mmi_brw_bookmarks_recv_file_save_to_fmgr (kal_uint8 *file_path, kal_uint8 *file_name, kal_uint8 *file_extn);

#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
extern void mmi_brw_enter_web_address(void);
extern void mmi_brw_enter_user_defined_bookmark_list(void);
#endif

#endif /* _BROWSER_API_H */

#endif /* BROWSER_SUPPORT */
