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
 * MMIthemes.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements Theme application.
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
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
                                                                               ****************************************************************************//**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************
   FILENAME : MMIThemes.c
   PURPOSE     : Theme application
   REMARKS     : nil
   AUTHOR      : Restructured by manju
   DATE     : Restructured on May-24-2003
**************************************************************/
#include "MMI_features.h"

/*  Include: MMI header file */
#ifdef __MMI_THEMES_APPLICATION__
#include "CommonScreens.h"
#include "AlarmFrameworkProt.h"
#include "AlarmGprot.h"
#include "FileMgrSrvGProt.h"
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
#include "app_url.h"
#include "conversions.h" 
#include "DLAgentSrvGProt.h"
#include "Fseditorcuigprot.h"
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */

#include "WPSSProtos.h"
#include "InlineCuiGprot.h"
#include "AlarmGprot.h"
#include "Menucuigprot.h"
#include "BootupSrvGprot.h"
#include "ProfilesSrvGprot.h"
#include "ReminderSrvGprot.h"
#include "mmi_rp_srv_reminder_def.h"

#ifdef __MMI_USB_SUPPORT__
#include "mmi_rp_app_usbmmi_def.h"
#endif
#include "mmi_rp_srv_mmi_theme_def.h"
#include "MMIThemesGprot.h"
#include "MMIThemesDef.h"
#include "MMIThemes.h"
#include "JavaAgencyDef.h"

    #include "MMI_common_app_trc.h"
    #include "DebugInitDef_Int.h"
    #include "MMIDataType.h"
    #include "kal_non_specific_general_types.h"
    #include "GlobalResDef.h"
    #include "wgui_categories_list.h"
    #include "wgui_touch_screen.h"
    #include "wgui_inline_edit.h"
    #include "wgui_categories_util.h"
    #include "custom_mmi_default_value.h"
    #include "mmi_theme_mgr.h"
    #include "mmi_frm_history_gprot.h"
    #include "CommonScreensResDef.h"
    #include "AlertScreen.h"
    #include "mmi_frm_scenario_gprot.h"
    #include "CustDataRes.h"
    #include "mmi_frm_events_gprot.h"
    #include "mmi_frm_mem_gprot.h"
    #include "string.h"
    #include "GlobalConstants.h"
    #include "wgui_draw_manager.h"
    #include "gui_typedef.h"
    #include "wgui_categories.h"
    #include "mmi_frm_input_gprot.h"
    #include "mmi_frm_gprot.h"
    #include "NotificationGprot.h"
    #include "kal_trace.h"
    #include "nvram_common_defs.h"
    #include "mmi_frm_nvram_gprot.h"
    #include "gui_data_types.h"
    #include "custom_events_notify.h"
    #include "wgui_categories_popup.h"
    #include "browser_api.h"
    #include "kal_general_types.h"
    #include "mmi_common_app_trc.h"
    #include "Unicodexdcl.h"
    #include "kal_public_api.h"
    #include "ImeGprot.h"
    #include "wgui_categories_inputs.h"
    #include "CustMenuRes.h"
    #include "wgui_inputs.h"
    #include "FileMgrServiceResDef.h"
    #include "MMI_fw_trc.h"
    #include "mmi_fw_trc.h"
    #include "stdio.h"
    #include "fs_func.h"
    #include "fs_errcode.h"
    #include "fs_type.h"
    #include "PhoneSetupResList.h"
    #include "lcd_sw_inc.h"
    #include "stdlib.h"
    #include "FileMgrType.h"
#include "IdleGprot.h"    
#include "ModeSwitchSrvGprot.h"
#include "AlarmProt.h"      
#include "MMI_ap_dcm_config.h"
#include "AlarmDef.h"
/******************************************************************************
 * typedef
 *****************************************************************************/
typedef void (*soft_key_hdlr) (MMI_ID);
typedef void (*del_callback_hdlr) (MMI_ID);

typedef struct
{
    mmi_id sg_id;
    soft_key_hdlr LSK_function;
    soft_key_hdlr CSK_function;
    soft_key_hdlr RSK_function;
}mmi_theme_confirm_user_data_struct;

typedef struct
{
    mmi_id sg_id;
    del_callback_hdlr callback_function;
}mmi_theme_popup_user_data_struct;
    
    
typedef struct
{
    mmi_id parent_id;
    mmi_id group_id;
    mmi_id child_id;
}mmi_theme_common_group_data_struct;

typedef struct
{
    mmi_id parent_id;
    mmi_id group_id;
    mmi_id child_id;
    mmi_id cui_inline_id;
}mmi_theme_set_order_group_data_struct;


#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__

typedef struct
{
    mmi_id parent_id;
    mmi_id group_id;
    mmi_id child_id;
    mmi_id main_menu_gid;
    mmi_id adress_opt_menu_gid;
    mmi_id fseditor_gid;
}mmi_theme_download_group_data_struct;

/*
 * This context control the downloadable theme related operation
 */
typedef struct
{
	void* file_info_ptr; /* FMGR_FILE_INFO_STRUCT pointer*/
	CHAR *org_path;		 /* The original path*/
	CHAR *new_path;		 /* The target path */
}mmi_thm_dlt_file_cntx;

typedef struct
{
    U32 curr_activated_theme_id;
    U8 total_thm_cnt;
    U8 sys_thm_cnt;
} mmi_theme_context_struct;

typedef struct
{
    U32 theme_id;
    U8 theme_name[MAX_THEME_NAME_LENGTH *ENCODING_LENGTH];
    U8 theme_checksum_verified;
    U8 theme_type;
    CHAR drv_letter; /*if otg enable, this will be used */
} tm_theme_list_struct;

typedef enum
{
    CHECKSUM_NOT_VERIFIED,
    CHECKSUM_VERIFIED_OK,
    CHECKSUM_VERIFIED_BAD
} tm_theme_checksum_enum;

#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */


#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
typedef struct
{
    U16 freq_type;
    S16 set_order_flag;
    U32 themes_order[TOTAL_THEMES_COUNT];
} thm_nvram_struct;
#else /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
typedef struct
{
    U8 freq_type;
    U8 current_theme_index;
    S16 set_order_flag;
    U8 themes_order[4];
} thm_nvram_struct;
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 

/******************************************************************************
 * Define
 *****************************************************************************/
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
#define MAX_DESCRIPTOR_ELEMENTS_NUM     8
#define MAX_ACCEPTABLE_THEME_FILE_TYPE  2
#define MAX_LCD_STRING_SIZE         	10

#define MMI_THEME_INLINE_ITEM_COUNT		    (1)
#else
#define MMI_THEME_INLINE_ITEM_COUNT		    (NO_OF_ORDERS)
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */

#define NO_OF_THEME_OPTION_MENUITEMS_IN_USB_MODE 2
#define THM_MAX_URL_LENGTH      255
#define THM_DEFAULT_URI_SCHEME	"http://"
#define MAX_URL_LIST_ENTRIES 		7

#define MMI_THM_TRACE0(sub_grp) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp)

#define MMI_THM_TRACE1(sub_grp, arg) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg)
		
#define MMI_THM_TRACE2(sub_grp, arg1, arg2) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg1, arg2)

#define MMI_THM_TRACE3(sub_grp, arg1, arg2, arg3) \
		MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg1, arg2, arg3)

/******************************************************************************
 * Local Variable
 *****************************************************************************/
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
static MMI_BOOL g_tm_was_theme_alarm_cb; /* flag for usb pwr on*/
static MMI_BOOL g_tm_USB_mode;
static srv_prof_tone_enum g_mmi_thm_snd_id; /* event based sound id */
#endif

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
static const cui_inline_set_item_struct cui_set_order[1] = 
{
    {CUI_INLINE_ITEM_ID_BASE + 0, CUI_INLINE_ITEM_TYPE_SELECT, IMG_GLOBAL_L1, NULL}
};
#else /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
static const cui_inline_set_item_struct cui_set_order[4] = 
{
    {CUI_INLINE_ITEM_ID_BASE + 0, CUI_INLINE_ITEM_TYPE_SELECT, IMG_GLOBAL_L1, NULL},
    {CUI_INLINE_ITEM_ID_BASE + 1, CUI_INLINE_ITEM_TYPE_SELECT, IMG_GLOBAL_L2, NULL},
    {CUI_INLINE_ITEM_ID_BASE + 2, CUI_INLINE_ITEM_TYPE_SELECT, IMG_GLOBAL_L3, NULL},
    {CUI_INLINE_ITEM_ID_BASE + 3, CUI_INLINE_ITEM_TYPE_SELECT, IMG_GLOBAL_L4, NULL}
};
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */

//static mmi_id mmi_theme_set_order_child_gid = GRP_ID_INVALID;
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
static mmi_theme_context_struct g_theme_cntx;
__align(4)
tm_theme_list_struct g_tm_NvramThmArr[MAX_DOWNLOADED_THEMES];
__align(4)
tm_theme_list_struct g_tm_theme_list[TOTAL_THEMES_COUNT];

static const CHAR *g_mmi_thm_descriptor_tags[MAX_DESCRIPTOR_ELEMENTS_NUM] = 
{
    {"type"},
    {"objectURI"},
    {"size"},
    {"ddversion"},
    {"installNotifyURI"},
    {"Name"},
    {"lcdht"},
    {"lcdwidth"}
};

static const CHAR *g_mmi_thm_acceptable_theme_filetypes[MAX_ACCEPTABLE_THEME_FILE_TYPE] = 
{
    {"mtk/med.thm"},
    {"theme"}
};

mmi_theme_confirm_user_data_struct g_theme_confirm_user_data;

#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */

thm_contex_struct g_thm_cntx;

/* map update period to index */
static const U8 g_themes_freq_set[THMEM_FREQ_NUM] =
{
    ALM_FREQ_OFF, 
    ALM_FREQ_HOURLY, 
    ALM_FREQ_EVERYDAY, 
    ALM_FREQ_WEEKLY, 
    ALM_FREQ_MONTHLY, 
    ALM_FREQ_SEASONALLY
};

/******************************************************************************
 * Local Function
 *****************************************************************************/
static mmi_ret mmi_theme_main_group_proc(mmi_event_struct *evt);
static void mmi_theme_entry_int(void);
static mmi_ret mmi_theme_option_group_proc(mmi_event_struct* evt);
static void EntryThmOptions(void);
static void mmi_theme_option_menu_cui_entry_hdlr(cui_menu_event_struct *menu_evt);
static void mmi_theme_option_menu_cui_highlight_hdlr(cui_menu_event_struct *menu_evt);
static void mmi_theme_option_menu_cui_select_hdlr(cui_menu_event_struct *menu_evt);
static mmi_ret mmi_theme_set_order_group_proc(mmi_event_struct* evt);
static void mmi_theme_inline_submit_proc(mmi_event_struct *evt);
static void SaveOrderThemes(mmi_id parent_id);

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
static MMI_BOOL mmi_thm_is_dlt_theme(U32 theme_id);
static void mmi_theme_entry_usb_int(void);
static S16  mmi_thm_validate_url(U8 *url_p);
static void mmi_thm_goto_url(void);
static void mmi_thm_pre_entry_dwnld(void);
static void mmi_thm_entry_input_address(void);
//static void mmi_thm_exit_input_address(void);
static void mmi_thm_add_to_URL_List(void);
static void mmi_thm_input_addr_entry_option(void);
static void mmi_thm_input_addr_exit_option(void);
static MMI_BOOL mmi_thm_check_white_spaces(CHAR *string);
static MMI_BOOL mmi_thm_get_usb_mode(void);
static void mmi_tm_activate_theme_at_bootup(void);
static S32 mmi_tm_activate_downloaded_theme(tm_theme_list_struct *theme_struct_p);
static S32  mmi_tm_delete_theme(THEME_ID theme_id, PS32 error_type);
static U8  mmi_tm_get_total_themes_count(void);
static U8  mmi_tm_get_themes(tm_theme_list_struct **theme_list_p);
static mmi_ret mmi_theme_download_group_proc(mmi_event_struct* evt);
static void mmi_theme_download_menu_cui_entry_hdlr(cui_menu_event_struct *menu_evt);
static void mmi_theme_download_menu_cui_select_hdlr(cui_menu_event_struct *menu_evt);
static void mmi_theme_download_menu_cui_highlight_hdlr(cui_menu_event_struct *menu_evt);
static void mmi_theme_download_menu_cui_tap_hdlr(cui_menu_event_struct *menu_evt);
static mmi_ret mmi_thm_address_edit_group_proc(mmi_event_struct* evt);
static MMI_BOOL mmi_thm_is_file_exist(CHAR *file_path_name);
#else /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
static U8 mmi_thm_reset_current_theme(void);
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */

//static void mmi_thm_display_confirm(U16 strId, FuncPtr lskFuncs, FuncPtr rskFuns);

#ifdef __MMI_TOUCH_SCREEN__
static void mmi_thm_tap_list_callback(mmi_tap_type_enum tap_type, S32 index);
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
static void mmi_thm_tap_url_callback(mmi_tap_type_enum tap_type, S32 index);
#endif
#endif /* __MMI_TOUCH_SCREEN__ */

#ifndef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
static void ReadThemesFromNVRAM(void);
#endif

/****************************************************************************** 
 * Global Variable
 *****************************************************************************/
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__

tm_theme_list_struct *thm_details;
static S32 setorderIDList[TOTAL_THEMES_COUNT]; /* it is only for stub testing); */
static U8 g_temp_thm_index;
static S16 currorderindex;                     /* this is only for set order list */

static thm_nvram_download_list recent_url_list;
static CHAR  g_thm_download_address[MAX_ENTER_ADDRESS_SIZE * ENCODING_LENGTH + ENCODING_LENGTH];
static U16 g_recent_item_index;
static U8  dontSaveURLinHistory;

static mmi_thm_dlt_file_cntx g_mmi_thm_dlt_file_cntx;
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */

/****************************************************************************** 
 * Global Function
 *****************************************************************************/
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__

extern void mmi_frm_highlight_input_method_generic(void);
extern void EntryInputMethodScreen(void);
#ifdef OBIGO_SUPPORT
extern void wap_entry_widget_not_ready(void);
#endif 

extern S32 wap_browser_is_open(void);
static mmi_ret mmi_theme_fmgr_active_group_proc(mmi_event_struct* evt);
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */

/* Leo end */
#ifdef __J2ME__
extern void jam_pause_dummy_screen(void);
extern void jam_resume_dummy_screen(void);
#endif /* __J2ME__ */ 

extern void UpdateUITheme(void);
extern const CHAR *gDefaultDLT_URL;

/* Leo add for DLT */
extern int wap_is_ready(void);
/* Leo end */

#ifndef __MTK_TARGET__
extern S32 mmi_mte_is_active(void);
#endif /* __MTK_TARGET__ */


/*****************************************************************************
 * FUNCTION
 *  InitThemes
 * DESCRIPTION
 *  Initialize themes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitThemes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Leo add for DLT */
#ifdef __MMI_THEMES_V2_SUPPORT__        /* ritesh */
    mmi_theme_manager_init();
    ConstructThemeList();

    /* ConstructThemeOrderList(); */
    mmi_tm_activate_theme_at_bootup();
    g_thm_cntx.CurrTheme = mmi_tm_get_current_theme_id();

    SetThemes((U8)g_thm_cntx.CurrTheme);
#else /* __MMI_THEMES_V2_SUPPORT__ */ 
    FillThemesList();
    ReadThemesFromNVRAM();
    MMI_apply_current_theme();
#endif /* __MMI_THEMES_V2_SUPPORT__ */ /* ritesh */

    /* Leo end */
}


/*****************************************************************************
 * FUNCTION
 *  ThemesFCBInit
 * DESCRIPTION
 *  Set calback function of alarm framework
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ThemesFCBInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*mmi_alm_set_start_index(ALM_TYPE_THEME, ALM_THM_START);
    AlmSetExpiryTimeCB(ALM_TYPE_THEME, ThemesExpiryTimeCBH);
    AlmSetExpiryHandlerCB(ALM_TYPE_THEME, ThemeAlarmCallBack);
#ifdef __MMI_THEMES_V2_SUPPORT__
    AlmSetInitHandlerCB(ALM_TYPE_THEME, ConstructThemeOrderList, ThemesReInitQueueCBH);
#else
	AlmSetInitHandlerCB(ALM_TYPE_THEME, ReadThemesFromNVRAM, ThemesReInitQueueCBH);
#endif */

}

mmi_ret mmi_theme_rmdr_notify(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables																	   */
	/*----------------------------------------------------------------*/
	srv_reminder_evt_struct *remdr_evt;
	U16 period;

	/*----------------------------------------------------------------*/
	/* Code Body																		   */
	/*----------------------------------------------------------------*/
	if (evt->evt_id != EVT_ID_SRV_REMINDER_NOTIFY)
	{
		return MMI_RET_OK;
	}
	
	remdr_evt = (srv_reminder_evt_struct *)evt;
	if (remdr_evt->reminder_type != SRV_REMINDER_TYPE_THEME && 
		remdr_evt->reminder_type != SRV_REMINDER_TYPE_TOTAL)
	{
		return MMI_RET_OK;
	}
	
	switch(remdr_evt->notify)
	{
		case SRV_REMINDER_NOTIFY_INIT:
		#ifdef __MMI_THEMES_V2_SUPPORT__
			ConstructThemeOrderList();
		#else
			ReadThemesFromNVRAM();
#endif
			break;
			
		case SRV_REMINDER_NOTIFY_EXPIRY:
			ThemeAlarmCallBack(remdr_evt->usr_data, &period, !remdr_evt->pwr_off);
			break;

		case SRV_REMINDER_NOTIFY_REINIT:
			ThemesReInitQueueCBH();
			break;

		case SRV_REMINDER_NOTIFY_DEINIT:
			break;

		default:
			break;
	}

	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ThemesExpiryTimeCBH
 * DESCRIPTION
 *  Callback handler to get information of theme expiry setting.
 * PARAMETERS
 *  index           [IN]            
 *  alarmTime       [?]             
 *  Freq            [?]             
 *  WeekDays        [?]             
 *  MYTIME(?)       [IN/OUT]        Expiry time set by user
 *  U8(?)           [IN/OUT]        Expiry days of week
 * RETURNS
 *  void
 *****************************************************************************/
void ThemesExpiryTimeCBH(U8 index, MYTIME *alarmTime, U8 *Freq, U8 *WeekDays, MYTIME* preReminder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *Freq = g_themes_freq_set[g_thm_cntx.CurrUpdatePeriod];
    *WeekDays = 1;
}


/*****************************************************************************
 * FUNCTION
 *  ThemesReInitQueueCBH
 * DESCRIPTION
 *  Reinit themes to alarm queue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ThemesReInitQueueCBH(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 freq = g_themes_freq_set[g_thm_cntx.CurrUpdatePeriod];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (freq != ALM_FREQ_OFF)
    {
    	MYTIME currTime, almTime;
		
    	DTGetRTCTime(&currTime);
		currTime.nMin = 0;
		currTime.nSec = 0;
        almTime = srv_reminder_calc_time(&currTime, (srv_reminder_repeat_enum)freq, 0);
	srv_reminder_set(SRV_REMINDER_TYPE_THEME, &almTime, 0);
    }
}

extern void ExecSubLCDCurrExitHandler(void);
extern void GoBackSubLCDHistory(void);


/*****************************************************************************
 * FUNCTION
 *  SetBothLCDThemes
 * DESCRIPTION
 *  Set themes of both main and sub lcd
 * PARAMETERS
 *  index       [IN]        Index of theme
 * RETURNS
 *  void
 *****************************************************************************/
void SetBothLCDThemes(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_THEMES_V2_SUPPORT__
    ExecSubLCDCurrExitHandler();
    GoBackSubLCDHistory();
#else /* __MMI_THEMES_V2_SUPPORT__ */ 
    SetThemes(index);
    UpdateUITheme();
    //MTK Leo add, fix theme update issue
    //      SUBLCD_RedrawCategoryFunction();
    ExecSubLCDCurrExitHandler();
    GoBackSubLCDHistory();
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_theme_confirm_user_data_init
 * DESCRIPTION
 *  Highlight handler of to do list task list, store the index of selected task.
 * PARAMETERS
 *  nIndex      [IN]        Index of selected task.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_theme_confirm_user_data_init(mmi_theme_confirm_user_data_struct* arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    arg->sg_id = GRP_ID_INVALID;
    arg->LSK_function = NULL;
    arg->CSK_function = NULL;
    arg->RSK_function = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_theme_comfirm_proc
 * DESCRIPTION
 *  Highlight handler of to do list task list, store the index of selected task.
 * PARAMETERS
 *  nIndex      [IN]        Index of selected task.
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_theme_comfirm_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_ALERT_QUIT:
        {
            mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*)evt;
            mmi_theme_confirm_user_data_struct* confirm_data = 
                (mmi_theme_confirm_user_data_struct*)alert->user_tag;

            switch (alert->result)
            {
                case MMI_ALERT_NORMAL_EXIT:
                {
                    mmi_frm_group_close(alert->alert_id);
                    break;
                }
                case MMI_ALERT_CNFM_YES:
                {
                    if (confirm_data->LSK_function != NULL)
                    {
                        confirm_data->LSK_function(confirm_data->sg_id);
                    }
                    break;
                }
                case MMI_ALERT_CNFM_NO:
                {
                    if (confirm_data->RSK_function != NULL)
                    {
                        confirm_data->RSK_function(confirm_data->sg_id);
                    }
                    break;
                }
                default:
                    break;
            }
        }
        default:
        {
            break;
        }        
    }
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_theme_popup_user_data_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_theme_popup_user_data_init(mmi_theme_popup_user_data_struct* arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    arg->sg_id = GRP_ID_INVALID;
    arg->callback_function = NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_theme_popup_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_theme_popup_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_POPUP_QUIT:
        {        
            mmi_event_popoupcallback_result_struct *popup_evt = (mmi_event_popoupcallback_result_struct*)evt;
            mmi_theme_popup_user_data_struct *popup_data = popup_evt->user_tag;
            popup_data->callback_function(popup_data->sg_id);
            break;
        }
        default:
        {
            break;
        }
    }
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ConstructThemeOrderList
 * DESCRIPTION
 *  function to construct themes order list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
void ConstructThemeOrderList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U8 index = 0;
    thm_nvram_struct nvram_theme;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* initialize global contex */
    MMI_THM_TRACE0(MMI_THEME_CONSTRUCT_THEME_ORDERLIST);
    g_thm_cntx.TotalTheme = mmi_tm_get_total_themes_count();
    ReadRecord(NVRAM_EF_THEMES_VALUES, 1, &nvram_theme, sizeof(thm_nvram_struct), &error);
    g_thm_cntx.CurrUpdatePeriod = (U8) (nvram_theme.freq_type);

    /* set order list */
    if (nvram_theme.set_order_flag >= -1)    /* order has be set before */
    {
        g_thm_cntx.IsOrderChanged = 1;
        g_thm_cntx.CurrOrderIndex = nvram_theme.set_order_flag;
        currorderindex = (U8) nvram_theme.set_order_flag;

        for (index = 0; index < TOTAL_THEMES_COUNT; index++)    /* ritesh */
        {
            /* g_thm_cntx.CurrOrderList[index] = nvram_theme.themes_order[index]; */
            if (index  < g_thm_cntx.TotalTheme)
            {
                setorderIDList[index] = nvram_theme.themes_order[index];
            }
        }
    }
    else
    {
        g_thm_cntx.IsOrderChanged = 0;
    }

    /* set and apply current theme */
}


/*****************************************************************************
 * FUNCTION
 *  ConstructThemeList
 * DESCRIPTION
 *  Get the themes and construct set order list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ConstructThemeList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* U8 i,j; */
    U8 no_of_setorder_themes, themecount;
    U32 *p;
    U8 set_flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    no_of_setorder_themes = GetIDList(&p, &g_thm_cntx.CurrOrderIndex);
    g_thm_cntx.TotalTheme = mmi_tm_get_total_themes_count();
    g_thm_cntx.CurrTheme = mmi_tm_get_current_theme_id();
	MMI_THM_TRACE3(
	        MMI_THEME_CONSTRUCT_THEME_LIST, 
	        no_of_setorder_themes, 
	        g_thm_cntx.TotalTheme, 
	        g_thm_cntx.CurrTheme);

    SetThemes((U8)g_thm_cntx.CurrTheme);

    switch (no_of_setorder_themes)
    {
        case 0:
            for (no_of_setorder_themes = 0; no_of_setorder_themes < g_thm_cntx.TotalTheme; no_of_setorder_themes++)
            {
                g_thm_cntx.TmpOrderList[no_of_setorder_themes] = g_thm_cntx.TotalTheme;
                g_thm_cntx.SetOrderIDList[no_of_setorder_themes] = p[no_of_setorder_themes];
            }
            break;

        default:
            for (no_of_setorder_themes = 0; no_of_setorder_themes < g_thm_cntx.TotalTheme; no_of_setorder_themes++)
            {
                g_thm_cntx.SetOrderIDList[no_of_setorder_themes] = p[no_of_setorder_themes];
                for (themecount = 0; themecount < g_thm_cntx.TotalTheme; themecount++)
                {
                    if (g_thm_cntx.SetOrderIDList[no_of_setorder_themes] == 0)
                    {
                        g_thm_cntx.TmpOrderList[no_of_setorder_themes] = g_thm_cntx.TotalTheme;
                        set_flag = 1;
                        break;
                    }
                    else if (g_thm_cntx.SetOrderIDList[no_of_setorder_themes] == thm_details[themecount].theme_id)
                    {
                        g_thm_cntx.TmpOrderList[no_of_setorder_themes] = themecount;
                        set_flag = 1;
                        break;
                    }
                }
                if (set_flag == 0)
                {
                    g_thm_cntx.TmpOrderList[no_of_setorder_themes] = g_thm_cntx.TotalTheme;
                }

                set_flag = 0;
            }
    }

    for (no_of_setorder_themes = 0; no_of_setorder_themes < g_thm_cntx.TotalTheme; no_of_setorder_themes++)
    {
        g_thm_cntx.ThemeName[no_of_setorder_themes] = thm_details[no_of_setorder_themes].theme_name;
    }

    g_thm_cntx.ThemeName[g_thm_cntx.TotalTheme] = (PU8) GetString(STR_GLOBAL_NONE);
}
#else /* __MMI_THEMES_V2_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  FillThemesList
 * DESCRIPTION
 *  Fill inline item selection items
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FillThemesList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_thm_cntx.TmpOrderList[0] = (S32) g_thm_cntx.CurrOrderList[0];
    g_thm_cntx.TmpOrderList[1] = (S32) g_thm_cntx.CurrOrderList[1];
    g_thm_cntx.TmpOrderList[2] = (S32) g_thm_cntx.CurrOrderList[2];
    g_thm_cntx.TmpOrderList[3] = (S32) g_thm_cntx.CurrOrderList[3];

    for (index = 0; index < g_thm_cntx.TotalTheme; index++)
    {
        g_thm_cntx.ThemeName[index] = (PU8) GetString((U16) (STR_THEME_DEFAULT + index));
    }

    g_thm_cntx.ThemeName[index] = (PU8) GetString(STR_GLOBAL_NONE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_thm_reset_current_theme
 * DESCRIPTION
 *  delete callback function of theme menu screen.
 *  used to reset preview theme.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_thm_reset_current_theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_thm_cntx.CurrHiliteTheme != g_thm_cntx.CurrTheme)
    {
        SetBothLCDThemes(g_thm_cntx.CurrTheme);
    }
    
    g_thm_cntx.IsInThmApp = 0;
    
    return MMI_FALSE;
    
}

#endif /* __MMI_THEMES_V2_SUPPORT__ */ 

#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif

/*****************************************************************************
 * FUNCTION
 *  SaveOrderThemes
 * DESCRIPTION
 *  set order themes and save in NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SaveOrderThemes(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    U8 flag = 0;

    /* Leo add for DLT */
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    U32 TempID;
    U8 count = 0, no_of_setorder_themes;

#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    mmi_tm_get_themes(&thm_details);    
    for (no_of_setorder_themes = 0; no_of_setorder_themes < g_thm_cntx.TotalTheme; no_of_setorder_themes++)
    {
        if ((thm_details[g_thm_cntx.TmpOrderList[no_of_setorder_themes]].theme_id == 0 
            || mmi_ucs2cmp((CHAR*)g_thm_cntx.ThemeName[g_thm_cntx.TmpOrderList[no_of_setorder_themes]], (CHAR*)thm_details[g_thm_cntx.TmpOrderList[no_of_setorder_themes]].theme_name) != 0)
            && g_thm_cntx.TmpOrderList[no_of_setorder_themes] != g_thm_cntx.TotalTheme)
        {
            flag = 1;
            mmi_popup_display_simple(
                        (WCHAR*)get_string(STR_THEME_NOT_AVAILABLE),
                        MMI_EVENT_FAILURE,
                        parent_id,
                        0);
            g_thm_cntx.IsInThmApp = 0;
            return;
        }
    }
    for (index = 0; index < g_thm_cntx.TotalTheme; index++)
    {
        TempID = thm_details[g_thm_cntx.TmpOrderList[index]].theme_id;
        if (g_thm_cntx.SetOrderIDList[index] != TempID)
        {
            flag = 1;
            break;
        }
    }
#else /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
    for (index = 0; index < NO_OF_ORDERS; index++)
    {
        if (g_thm_cntx.CurrOrderList[index] != (U8) g_thm_cntx.TmpOrderList[index])
        {
            flag = 1;
            break;
        }
    }
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 

    if (flag)   /* order changed */
    {
        g_thm_cntx.CurrOrderIndex = -1;
        g_thm_cntx.IsOrderChanged = 1;
    #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
        for (index = 0; index < g_thm_cntx.TotalTheme; index++)
        {
            if (g_thm_cntx.TmpOrderList[index] == TOTAL_THEMES_COUNT)
            {
                g_thm_cntx.SetOrderIDList[index] = 0;
            }
            else
            {
                g_thm_cntx.SetOrderIDList[index] = thm_details[g_thm_cntx.TmpOrderList[index]].theme_id;
            }
            if (g_thm_cntx.SetOrderIDList[index] != 0)
            {
                count++;
            }
        }
    #else /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
        g_thm_cntx.CurrOrderList[0] = (CHAR) g_thm_cntx.TmpOrderList[0];
        g_thm_cntx.CurrOrderList[1] = (CHAR) g_thm_cntx.TmpOrderList[1];
        g_thm_cntx.CurrOrderList[2] = (CHAR) g_thm_cntx.TmpOrderList[2];
        g_thm_cntx.CurrOrderList[3] = (CHAR) g_thm_cntx.TmpOrderList[3];
        g_thm_cntx.IsOrderChanged = 1;
    #endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
        SetStartPositionofCurIndex();
        WriteThemesToNVRAM();
    #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
        SetOrderIDList(g_thm_cntx.SetOrderIDList, count, g_thm_cntx.CurrOrderIndex);
    #endif 
    }

	mmi_popup_display_simple(
                	(WCHAR*)get_string(STR_GLOBAL_DONE),
                	MMI_EVENT_SUCCESS,
                	parent_id,
                	0);
    g_thm_cntx.IsInThmApp = 0;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightThmSetOrder
 * DESCRIPTION
 *  Set LSK of set order list
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightThmSetOrder(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);    /* Force LSK label to "Ok" each time */
//    SetCategory57LeftSoftkeyFunction(SaveOrderThemes);  
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);    
//    SetCenterSoftkeyFunction(SaveOrderThemes, KEY_EVENT_UP);                            
}


/*****************************************************************************
 * FUNCTION
 *  mmi_theme_get_period_hint_string
 * DESCRIPTION
 *  hint the update period menu
 * PARAMETERS
 *  index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __MMI_PHNSET_SLIM__    
CHAR*  mmi_theme_get_period_hint_string(FREQ_ALARM theme_freq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	CHAR *hint_string = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (theme_freq)
    {
    case ALM_FREQ_OFF:
        hint_string = GetString(STR_GLOBAL_OFF);
        break;
        
    case ALM_FREQ_HOURLY:
        hint_string = GetString(STR_MENU3302_UPDATE_HOURLY);
        break;
        
    case ALM_FREQ_EVERYDAY:
        hint_string = GetString(STR_MENU3303_UPDATE_DAILY);
        break;

    case ALM_FREQ_WEEKLY:
        hint_string = GetString(STR_MENU3304_UPDATE_WEEKLY);
        break;
        
    case ALM_FREQ_MONTHLY:
        hint_string = GetString(STR_MENU_UPDATE_MONTHLY);
        break;
        
    case ALM_FREQ_SEASONALLY:
        hint_string = GetString(STR_MENU_UPDATE_SEASONALLY);
        break;
        
    default:
        break;
    }
    
	return hint_string;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  EntryThmSetOrder
 * DESCRIPTION
 *  Entry function of set order screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryThmSetOrder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    mmi_theme_set_order_group_data_struct *set_order_user_data;         
    cui_inline_struct inline_data;
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    cui_inline_set_item_struct item_data;
#endif
    U8 item_number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_order_user_data = (mmi_theme_set_order_group_data_struct*)
                                    OslMalloc(sizeof(mmi_theme_set_order_group_data_struct));
    memset(set_order_user_data, 0, sizeof(mmi_theme_set_order_group_data_struct));
    set_order_user_data->parent_id = GRP_ID_THM_MAIN;

    set_order_user_data->group_id = mmi_frm_group_create_ex(
                                                GRP_ID_THM_MAIN,
                                                GRP_ID_THM_SET_ORDER,
                                                mmi_theme_set_order_group_proc,
                                                set_order_user_data,
                                                MMI_FRM_NODE_NONE_FLAG);

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    g_thm_cntx.IsInThmApp = 1;
    g_thm_cntx.CurrTheme = mmi_tm_get_current_theme_id();
    ConstructThemeList();    
    item_number = (g_thm_cntx.TotalTheme > MMI_THEME_INLINE_ITEM_COUNT) ? 
                    g_thm_cntx.TotalTheme : MMI_THEME_INLINE_ITEM_COUNT;
#else /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
    g_thm_cntx.IsInThmApp = 2;
    for (i = 0; i < NO_OF_ORDERS; i++)
    {
        g_thm_cntx.TmpOrderList[i] = (S32)g_thm_cntx.CurrOrderList[i];
    }
    item_number = MMI_THEME_INLINE_ITEM_COUNT;
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */

    inline_data.items_count = MMI_THEME_INLINE_ITEM_COUNT;
    inline_data.title = STR_MENU3202_SET_ORDER;
    inline_data.title_icon = NULL;//GetRootTitleIcon(MENU3101_THEMES);
    inline_data.screen_flag = CUI_INLINE_SCREEN_DISABLE_DONE;
    inline_data.softkey = NULL;
    inline_data.items = cui_set_order;

    set_order_user_data->cui_inline_id = cui_inline_create(
                                                GRP_ID_THM_SET_ORDER,
                                                &inline_data);

    if (set_order_user_data->cui_inline_id != GRP_ID_INVALID)
    {           
    #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
        if (g_thm_cntx.TotalTheme > MMI_THEME_INLINE_ITEM_COUNT)
        {
            for (i = 0; i < g_thm_cntx.TotalTheme - MMI_THEME_INLINE_ITEM_COUNT; i++)
            {
                item_data.item_id = CUI_INLINE_ITEM_ID_BASE + MMI_THEME_INLINE_ITEM_COUNT + i;
                item_data.item_flag = CUI_INLINE_ITEM_TYPE_SELECT;
                item_data.image_id = NULL;//IMG_GLOBAL_L1 + i + 1;
                item_data.item_data = NULL;
                cui_inline_insert_item(
                                set_order_user_data->cui_inline_id,
                                CUI_INLINE_INSERT_TAIL,
                                &item_data);
            }
        }
    #endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
    
        for (i = 0; i < item_number; i++)
        {                                    
            cui_inline_set_item_select(
                                    set_order_user_data->cui_inline_id,
                                    CUI_INLINE_ITEM_ID_BASE + i,
                                    g_thm_cntx.TotalTheme + 1,
                                    g_thm_cntx.ThemeName,
                                    g_thm_cntx.TmpOrderList[i]);
                            
        }        
        cui_inline_run(set_order_user_data->cui_inline_id);
    }
    else
    {
        mmi_frm_group_close(GRP_ID_THM_MAIN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_theme_set_order_group_proc
 * DESCRIPTION
 *  Generate the menus.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_theme_set_order_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_theme_set_order_group_data_struct *set_order_user_data;         

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    set_order_user_data = (mmi_theme_set_order_group_data_struct*)evt->user_data;
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_INACTIVE:
        {
            mmi_frm_group_close(GRP_ID_THM_SET_ORDER);        
            break;
        }
        case EVT_ID_POPUP_QUIT:
        {        
            mmi_frm_group_close(GRP_ID_THM_SET_ORDER);
            break;
        }
        case EVT_ID_GROUP_DEINIT:
        {
            OslMfree(set_order_user_data);
            break;
        }    
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_CSK_PRESS:
        {
            mmi_theme_inline_submit_proc(evt);
            break;
        }
        case EVT_ID_CUI_INLINE_ABORT:
        {        
            cui_inline_close(set_order_user_data->cui_inline_id);
            mmi_frm_group_close(set_order_user_data->group_id);
            break;
        }            
    }
    return MMI_RET_OK;        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_theme_inline_submit_proc
 * DESCRIPTION
 *  Inline proc
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_theme_inline_submit_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U8 item_number;    
    mmi_theme_set_order_group_data_struct *set_order_user_data;         

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    set_order_user_data = (mmi_theme_set_order_group_data_struct*)evt->user_data;

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__    
    item_number = (g_thm_cntx.TotalTheme > MMI_THEME_INLINE_ITEM_COUNT) ? 
                    g_thm_cntx.TotalTheme : MMI_THEME_INLINE_ITEM_COUNT;
#else
    item_number = MMI_THEME_INLINE_ITEM_COUNT;
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
    
    for (i = 0; i < item_number; i++)
    {
        cui_inline_get_value(
                    set_order_user_data->cui_inline_id, 
                    CUI_INLINE_ITEM_ID_BASE + i,
                    &g_thm_cntx.TmpOrderList[i]);
    }
    SaveOrderThemes(set_order_user_data->group_id);
}


/*****************************************************************************
 * FUNCTION
 *  ExitThmSetOrder
 * DESCRIPTION
 *  Exit function of set order screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitThmSetOrder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    g_thm_cntx.IsInThmApp = 0;
#endif 
}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  ActivateDefaultTheme
 * DESCRIPTION
 *  function to activate default theme
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ActivateDefaultTheme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_tm_activate_theme(DefaultThmID);
    g_thm_cntx.CurrTheme = mmi_tm_get_current_theme_id();
    SetThemes((U8)g_thm_cntx.CurrTheme);
	mmi_thm_activate_update_thm_order();
    
}

#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_check_white_spaces
 * DESCRIPTION
 *  This function is used for checking whether the given string contains any
 *  white spaces or not
 * PARAMETERS
 *  string		[OUT]		string in unicode
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_thm_check_white_spaces(CHAR *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(string);

	if(!mmi_ucs2strlen(string))
	{
		return MMI_FALSE;
	}

	for(index = 0; index < (mmi_ucs2strlen((CHAR*)string) * ENCODING_LENGTH); index += ENCODING_LENGTH)
	{
		if( ( string[index] ==  9 && string[index + 1] == 0 ) ||
			( string[index] == 10 && string[index + 1] == 0 ) ||
			( string[index] == 13 && string[index + 1] == 0 ) ||
			( string[index] == 32 && string[index + 1] == 0 )
		   )
		{
			return MMI_TRUE;
		}
	}
	
	return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_thm_validate_url
 * DESCRIPTION
 *  Utility function to validate the url.
 * PARAMETERS
 *  url_p       [IN]     Url in unicode to be validated
 * RETURNS
 *  void
 *****************************************************************************/
static S16 mmi_thm_validate_url(U8 *url_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 temp[THM_MAX_URL_LENGTH + 1];
	U8 url_ascii[THM_MAX_URL_LENGTH+1];
	//S32 error_code;
	U8 uri_schm_len;
	applib_url_struct url_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	MMI_ASSERT(url_p);

	/*check the zero length and white spaces in the URL string*/
	if(!mmi_ucs2strlen((CHAR*)url_p) || mmi_thm_check_white_spaces((CHAR*)url_p))
	{
		return APPLIB_URL_ERR_INVALID_PARAM;
	}

	/* convert the UCS2 URL string into UTF-8 */
    mmi_chset_ucs2_to_utf8_string((U8*)url_ascii, THM_MAX_URL_LENGTH + 1,(U8*)url_p);

	/* parse the URL string by using Applib API */
	if(!(S32)applib_parse_url((CHAR*)url_ascii, &url_info))
	{
		/* if there is an empty URI scheme in the URL then append the default ("http://") */
		/* URI scheme */
		if(url_info.scheme_type == applib_scheme_empty)
	    {
		    uri_schm_len = strlen((CHAR*)THM_DEFAULT_URI_SCHEME);
		    if( strlen((CHAR*)url_ascii) > (THM_MAX_URL_LENGTH - uri_schm_len) )
		    {
			    strncpy((CHAR*)temp, (CHAR*)url_ascii, THM_MAX_URL_LENGTH  - uri_schm_len);
			    temp[THM_MAX_URL_LENGTH  - uri_schm_len] = '\0';
		    }
		    else
		    {
		        strcpy((CHAR*)temp, (CHAR*)url_ascii);
		    }
		    strcpy((CHAR*)url_ascii, (CHAR*)THM_DEFAULT_URI_SCHEME);
		    strcat((CHAR*)url_ascii, (CHAR*)temp);
		    mmi_chset_utf8_to_ucs2_string((U8*)url_p, (THM_MAX_URL_LENGTH + 1)* ENCODING_LENGTH, (U8*)url_ascii);
  
		    /* check whether it contain HTTP or HTTPS URI scheme with empty host */
		    if(!(S32)applib_parse_url((CHAR*)url_ascii, &url_info))
		    {
			    if( url_info.scheme_type == applib_scheme_http ||
				    url_info.scheme_type == applib_scheme_https
				    )
			    {
				    if(!url_info.len[APPLIB_URL_HOST_PART])
				    {
					    return APPLIB_URL_ERR_INVALID_HOST;
	                }
			    }
		    }
	    }
	    /* check whether it contain HTTP or HTTPS URI scheme with empty host */
	    else if( url_info.scheme_type == applib_scheme_http ||
			     url_info.scheme_type == applib_scheme_https
			    )
	    {
		    if(!url_info.len[APPLIB_URL_HOST_PART])
	        {
			    return APPLIB_URL_ERR_INVALID_HOST;
		    }
	    }
    }

	/* validate the UTF-8 URL string by using Applib API */
	return (S32)applib_url_is_valid((CHAR*)url_ascii); 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_thm_pre_entry_dwnld
 * DESCRIPTION
 *  It download a theme
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_thm_pre_entry_dwnld(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    mmi_theme_download_group_data_struct *download_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    download_cntx = (mmi_theme_download_group_data_struct*)
                            OslMalloc(sizeof(mmi_theme_download_group_data_struct));
    memset(download_cntx, 0, sizeof(mmi_theme_common_group_data_struct));
    download_cntx->parent_id = GRP_ID_THM_MAIN;
   
    ReadRecord(
        NVRAM_EF_THEME_DOWNLOAD_LIST_LID,
        1,
        &recent_url_list,
        NVRAM_THEMES_DOWNLOAD_SIZE,
        &error);

    download_cntx->group_id = mmi_frm_group_create_ex(
                                    GRP_ID_THM_MAIN,
                                    GRP_ID_THM_DOWNLOAD,
                                    mmi_theme_download_group_proc,
                                    download_cntx,
                                    MMI_FRM_NODE_SMART_CLOSE_FLAG);

    
    download_cntx->main_menu_gid = cui_menu_create_and_run(
                                        download_cntx->group_id,
                                        CUI_MENU_SRC_TYPE_APPCREATE,
                                        CUI_MENU_TYPE_APPSUB,
                                        MENU_THEMES_DOWNLOAD,
                                        MMI_FALSE,
                                        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_theme_download_group_proc
 * DESCRIPTION
 *  Generate the menus.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_theme_download_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    mmi_theme_download_group_data_struct *download_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    download_cntx = (mmi_theme_download_group_data_struct*)evt->user_data;
    switch(menu_evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
        {
            OslMfree(download_cntx);
            break;
        }    
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            mmi_theme_download_menu_cui_entry_hdlr(menu_evt);
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        {
            mmi_theme_download_menu_cui_highlight_hdlr(menu_evt);
            break;
        }
		case EVT_ID_CUI_MENU_ITEM_TAP:
		{
			mmi_theme_download_menu_cui_tap_hdlr(menu_evt);
			break;
		}		
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            mmi_theme_download_menu_cui_select_hdlr(menu_evt);
            break;
        }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(menu_evt->sender_id);
            break;
        }
        case EVT_ID_CUI_FSEDITOR_ABORT:
        {
            cui_fseditor_close(download_cntx->fseditor_gid);
            break;
        }
        case EVT_ID_CUI_FSEDITOR_CSK_PRESSED:
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
        {
            mmi_thm_add_to_URL_List();
            break;
        }
        default:
        {
            break;
        }
    }
    return MMI_RET_OK;        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_theme_download_menu_cui_entry_hdlr
 * DESCRIPTION
 *  Generate the menus.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_theme_download_menu_cui_entry_hdlr(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    mmi_theme_download_group_data_struct *download_cntx = menu_evt->user_data;     
    mmi_menu_id list_of_ids[MAX_URL_ENTRIES + 2];    
    WCHAR *url_buffer;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MENU_THEMES_DOWNLOAD != menu_evt->parent_menu_id)
    {
        return;
    }
    for (i = 0; i < recent_url_list.total_entries + 2; i++)
    {
        list_of_ids[i] = i;
    }
    
	cui_menu_set_default_title_image_by_id(download_cntx->main_menu_gid, 
									 GetRootTitleIcon(MENU3101_THEMES));	
    cui_menu_set_currlist_title_by_id(
                            download_cntx->main_menu_gid,
                            STR_THEMES_DOWNLOAD,
                            0/*GetRootTitleIcon(MENU3101_THEMES)*/);
    cui_menu_set_currlist(
                    download_cntx->main_menu_gid,
                    recent_url_list.total_entries + 2,
                    list_of_ids);
    cui_menu_set_item_string_by_id(
                    download_cntx->main_menu_gid, 
                    0,
                    STR_DOWNLOAD_ENTER_ADDRESS);
    cui_menu_set_item_image(download_cntx->main_menu_gid, 0, IMG_GLOBAL_L1);
    
	url_buffer = (WCHAR *)OslMalloc((MAX_ENTER_ADDRESS_SIZE + 1) * sizeof(WCHAR));

    mmi_asc_n_to_wcs(url_buffer, (CHAR*)gDefaultDLT_URL, MAX_SUBMENU_CHARACTERS);
    cui_menu_set_item_string(download_cntx->main_menu_gid, 1, url_buffer);
    cui_menu_set_item_image(download_cntx->main_menu_gid, 1, IMG_GLOBAL_L2);
    
    for(i = 0; i < recent_url_list.total_entries + 2; i++)
    {
        mmi_asc_to_wcs(url_buffer,(CHAR*)recent_url_list.g_thm_recent_url[i]);
        cui_menu_set_item_string(download_cntx->main_menu_gid, i + 2, url_buffer);
        cui_menu_set_item_image(download_cntx->main_menu_gid, i + 2, IMG_GLOBAL_L1 + i + 2);
    }
    
	OslMfree(url_buffer);
    cui_menu_set_currlist_left_softkey_by_id(
                        download_cntx->main_menu_gid, 
                        STR_GLOBAL_OK);        

	cui_menu_enable_tap_to_highlight(download_cntx->main_menu_gid);
	cui_menu_set_access_by_shortcut(download_cntx->main_menu_gid, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_theme_download_menu_cui_tap_hdlr
 * DESCRIPTION
 *  Generate the menus.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_theme_download_menu_cui_tap_hdlr(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    //mmi_theme_download_group_data_struct *download_cntx = menu_evt->user_data;     
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (menu_evt->highlighted_menu_id)
	{
		case 0:
		{
			mmi_thm_entry_input_address();
			break;
		}	
		case 1:
		default:
		{
			mmi_thm_goto_url();
			break;
		}
	}
}



/*****************************************************************************
 * FUNCTION
 *  mmi_theme_download_menu_cui_highlight_hdlr
 * DESCRIPTION
 *  Generate the menus.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_theme_download_menu_cui_highlight_hdlr(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    mmi_theme_download_group_data_struct *download_cntx = menu_evt->user_data;     
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MENU_THEMES_DOWNLOAD != menu_evt->parent_menu_id)
    {
        return;
    }
    
    g_recent_item_index = menu_evt->highlighted_menu_id;
    switch (menu_evt->highlighted_menu_id)
    {
        case 0:
        case 1:
        {
			cui_menu_change_center_softkey_content(download_cntx->main_menu_gid, NULL, (UI_image_type)GetImage(IMG_GLOBAL_COMMON_CSK));
            cui_menu_change_left_softkey_string_by_id(
                                download_cntx->main_menu_gid,
                                STR_GLOBAL_OK);
            break;
        }
        default:
        {
			cui_menu_change_center_softkey_content(download_cntx->main_menu_gid, NULL, (UI_image_type)GetImage(IMG_GLOBAL_OPTION_CSK));
            cui_menu_change_left_softkey_string_by_id(
                                download_cntx->main_menu_gid,
                                STR_GLOBAL_OPTIONS);
            break;
        }
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_theme_download_menu_cui_select_hdlr
 * DESCRIPTION
 *  Generate the menus.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_theme_download_menu_cui_select_hdlr(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch (menu_evt->highlighted_menu_id)
    {
        case MENU_THEMES_ENTER_ADR_GOTO:
        {
            mmi_thm_goto_url();
            break;
        }
        case MENU_THEMES_ENTER_ADR_EDIT:
        {
            mmi_thm_address_list_edit_item();
            break;
        }
        case MENU_THEMES_ENTER_ADR_DELETE:
        {
            mmi_thm_address_list_delete_confirm();
            break;
        }
        case MENU_THEMES_ENTER_ADR_DELETE_ALL:
        {
            mmi_thm_address_list_delete_all_confirm();
            break;
        }
        case 0:
        {
            mmi_thm_entry_input_address();
            break;
        }   
        case 1:
        {
            mmi_thm_goto_url();
            break;
        }
        default:
        {
            mmi_thm_entry_enter_address_options();
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_thm_entry_input_address
 * DESCRIPTION
 *  It download a theme
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_thm_entry_input_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_theme_download_group_data_struct *download_cntx;
//    U16 scr_id = 0, title_str = 0, note_len = 0;
//    CHAR *note_str = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((CHAR *) g_thm_download_address, (CHAR *) "http://");
    download_cntx = mmi_frm_group_get_user_data(GRP_ID_THM_DOWNLOAD);
    download_cntx->fseditor_gid = cui_fseditor_create(GRP_ID_THM_DOWNLOAD);    
    if (0 == download_cntx->fseditor_gid)
    {
        return;
    }
	
    cui_fseditor_set_title(
                        download_cntx->fseditor_gid, 
                        STR_DOWNLOAD_ENTER_ADDRESS, 
                        GetRootTitleIcon(MENU3101_THEMES));
    cui_fseditor_set_buffer(
                        download_cntx->fseditor_gid, 
                        g_thm_download_address, 
                        (MAX_ENTER_ADDRESS_SIZE + 1) * ENCODING_LENGTH, 
                        MAX_ENTER_ADDRESS_SIZE);
    cui_fseditor_set_input_method(
                        download_cntx->fseditor_gid, 
                        IMM_INPUT_TYPE_URL, 
                        NULL, 
                        0);
    cui_fseditor_run(download_cntx->fseditor_gid);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_thm_highlight_edit_url_done
 * DESCRIPTION
 *  Exit function to edit url address screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_thm_highlight_edit_url_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if (IsScreenPresent(SCR_ID_DOWNLOAD_ENTER_ADDRESS_OPTIONS) == MMI_TRUE)
    {
        SetLeftSoftkeyFunction(mmi_thm_address_list_editor_done, KEY_EVENT_UP);    
        SetCenterSoftkeyFunction(mmi_thm_address_list_editor_done, KEY_EVENT_UP);         
    }
    else
    {
        SetLeftSoftkeyFunction(mmi_thm_add_to_URL_List, KEY_EVENT_UP);    
        SetCenterSoftkeyFunction(mmi_thm_add_to_URL_List, KEY_EVENT_UP);         
    }
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(get_left_softkey_function(KEY_EVENT_UP), KEY_EVENT_UP);     
}

/*****************************************************************************
 * FUNCTION
 *  mmi_thm_highlight_edit_url_cancel
 * DESCRIPTION
 *  Exit function to edit url address screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_thm_highlight_edit_url_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    SetLeftSoftkeyFunction(mmi_thm_cancel_edit_url, KEY_EVENT_UP);    
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);     
    SetCenterSoftkeyFunction(mmi_thm_cancel_edit_url, KEY_EVENT_UP);       
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_thm_highlight_edit_url_input_type
 * DESCRIPTION
 *  Exit function to edit url address screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_thm_highlight_edit_url_input_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP); 
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);     
    SetCenterSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);           
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);  
}

/*****************************************************************************
 * FUNCTION
 *  mmi_thm_cancel_edit_url
 * DESCRIPTION
 *  Exit function to edit url address screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_thm_cancel_edit_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_DOWNLOAD_EDIT_ADDRESS);
    GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_thm_goback_edit_url
 * DESCRIPTION
 *  Exit function to edit url address screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_thm_goback_edit_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackToHistory(SCR_ID_DOWNLOAD_EDIT_ADDRESS);    
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_thm_input_addr_entry_option
 * DESCRIPTION
 *  Entry function to download theme
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_thm_input_addr_entry_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[10];
    U16 numItems;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dontSaveURLinHistory = 0;
    EntryNewScreen(SCR_ID_DOWNLOAD_DONE_OPTION, mmi_thm_input_addr_exit_option, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_DOWNLOAD_DONE_OPTION);
    SetParentHandler(MENU_THEMES_DOWNLOAD);
    numItems = GetNumOfChild(MENU_THEMES_DOWNLOAD);
    GetSequenceStringIds(MENU_THEMES_DOWNLOAD, nStrItemList);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ShowCategory529Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU3101_THEMES),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (PU16) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer,
        ExecuteCurrHiliteHandler,
        mmi_thm_goback_edit_url);

    if (wgui_inputs_menu_index_in_editor_range() == MMI_FALSE)
    {
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_thm_input_addr_exit_option
 * DESCRIPTION
 *  Exit function to download theme
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_thm_input_addr_exit_option()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dontSaveURLinHistory != 1)
    {
        GenericExitScreen(SCR_ID_DOWNLOAD_DONE_OPTION, mmi_thm_input_addr_entry_option);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_thm_add_to_URL_List
 * DESCRIPTION
 *  Function to add url in history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_thm_add_to_URL_List(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    S32 index = 0;
	CHAR temp_thm_download_address[MAX_ENTER_ADDRESS_SIZE + 1];
	CHAR download_address[MAX_ENTER_ADDRESS_SIZE * ENCODING_LENGTH + ENCODING_LENGTH];
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_ucs2_to_asc((CHAR*)temp_thm_download_address, (CHAR*)g_thm_download_address);
	mmi_ucs2cpy((CHAR*)download_address, (CHAR*)g_thm_download_address);
	
    dontSaveURLinHistory = 1;
    if (g_thm_download_address != NULL)
    {        
		if(mmi_thm_validate_url((U8*)download_address) == 0)
		{
	        if (recent_url_list.total_entries == MAX_URL_ENTRIES)
	        {
	            recent_url_list.total_entries--;
	        }
	
	        if (recent_url_list.total_entries > 0)
	        {
	            for (index = recent_url_list.total_entries - 1; index >= 0; index--)
	            {
	                strcpy(
                        (CHAR*) recent_url_list.g_thm_recent_url[index + 1],
						(CHAR*) recent_url_list.g_thm_recent_url[index]);
	
	            }
	
	        }
            strcpy((CHAR*) recent_url_list.g_thm_recent_url[0], (CHAR*) temp_thm_download_address);
	        recent_url_list.total_entries++;
		    WriteRecord(
		        NVRAM_EF_THEME_DOWNLOAD_LIST_LID,
		        1,
		        &recent_url_list,
		        NVRAM_THEMES_DOWNLOAD_SIZE /* sizeof(thm_nvram_download_list) */ ,
		        &error);
		    g_recent_item_index = 0;
		    mmi_thm_goto_url();
		}
		else
		{
		    mmi_popup_display_simple(
            		    (WCHAR*)(get_string(STR_GLOBAL_INVALID_URL)),
            		    MMI_EVENT_FAILURE,
            		    GRP_ID_THM_DOWNLOAD,
            		    0);
		}
				
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_entry_enter_address_options
 * DESCRIPTION
 *  Entry function for Enter Address Options screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_thm_entry_enter_address_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_theme_download_group_data_struct *download_cntx; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    download_cntx = (mmi_theme_download_group_data_struct*)
                            mmi_frm_group_get_user_data(GRP_ID_THM_DOWNLOAD);
    
    download_cntx->adress_opt_menu_gid = cui_menu_create(
                                                download_cntx->group_id,
                                                CUI_MENU_SRC_TYPE_RESOURCE,
                                                CUI_MENU_TYPE_OPTION,
                                                MENU_THEMES_ENTER_ADR_OPTIONS,
                                                MMI_TRUE,
                                                NULL);
    cui_menu_set_default_title_by_id(
                    download_cntx->adress_opt_menu_gid,
                    STR_GLOBAL_OPTIONS,
                    0/* GetRootTitleIcon(MENU3101_THEMES) */);
                    
    cui_menu_run(download_cntx->adress_opt_menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_thm_address_list_goto_highlight_hdlr
 * DESCRIPTION
 *  Highlight function of goto url
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_thm_address_list_goto_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_thm_goto_url, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_thm_goto_url, KEY_EVENT_UP);     
}

/*****************************************************************************
 * FUNCTION
 *  mmi_thm_address_list_goto_highlight_hdlr
 * DESCRIPTION
 *  Highlight function of goto url
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_thm_address_list_edit_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_thm_address_list_edit_item, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_thm_address_list_edit_item, KEY_EVENT_UP);         
}

/*****************************************************************************
 * FUNCTION
 *  mmi_thm_address_list_goto_highlight_hdlr
 * DESCRIPTION
 *  Highlight function of goto url
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_thm_address_list_delete_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_thm_address_list_delete_confirm, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_thm_address_list_delete_confirm, KEY_EVENT_UP);        
}

/*****************************************************************************
 * FUNCTION
 *  mmi_thm_address_list_goto_highlight_hdlr
 * DESCRIPTION
 *  Highlight function of goto url
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_thm_address_list_delete_all_highlight_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_thm_address_list_delete_all_confirm, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_thm_address_list_delete_all_confirm, KEY_EVENT_UP);       
}

/*****************************************************************************
 * FUNCTION
 *  mmi_thm_address_list_edit_item
 * DESCRIPTION
 *  Entry function for Enter Address Edit Menu Item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_thm_address_list_edit_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_theme_download_group_data_struct *download_cntx;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    mmi_asc_n_to_ucs2((CHAR*)g_thm_download_address, (CHAR*)recent_url_list.g_thm_recent_url[g_recent_item_index - 2], MAX_ENTER_ADDRESS_SIZE + 1);
    //mmi_thm_entry_input_address();
    download_cntx = mmi_frm_group_get_user_data(GRP_ID_THM_DOWNLOAD);

    download_cntx->child_id = mmi_frm_group_create_ex(
                                                GRP_ID_THM_DOWNLOAD,
                                                GRP_ID_AUTO_GEN,
                                                mmi_thm_address_edit_group_proc,
                                                NULL,
                                                 MMI_FRM_NODE_SMART_CLOSE_FLAG);
    download_cntx->fseditor_gid = cui_fseditor_create(download_cntx->child_id);
    if (0 == download_cntx->fseditor_gid)
    {
        return;
    }
    cui_fseditor_set_title(
                        download_cntx->fseditor_gid, 
                        STR_DOWNLOAD_ENTER_ADDRESS, 
                        GetRootTitleIcon(MENU3101_THEMES));
    cui_fseditor_set_buffer(
                        download_cntx->fseditor_gid, 
                        g_thm_download_address, 
                        (MAX_ENTER_ADDRESS_SIZE + 1) * ENCODING_LENGTH, 
                        MAX_ENTER_ADDRESS_SIZE);
    cui_fseditor_set_input_method(
                        download_cntx->fseditor_gid, 
                        IMM_INPUT_TYPE_URL, 
                        NULL, 
                        0);
    cui_fseditor_run(download_cntx->fseditor_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_thm_address_edit_group_proc
 * DESCRIPTION
 *  Generate the menus.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_thm_address_edit_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch(menu_evt->evt_id)
    {
        case EVT_ID_CUI_FSEDITOR_CSK_PRESSED:
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
        {
            mmi_thm_address_list_editor_done();
            break;
        }
		
        case EVT_ID_CUI_FSEDITOR_ABORT:
            cui_fseditor_close(menu_evt->sender_id);
            break;
			
        default:
        {
            break;
        }
    }
    return MMI_RET_OK;        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_thm_address_list_editor_done
 * DESCRIPTION
 *  Function to edi url and confirm the modification
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_thm_address_list_editor_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    CHAR temp_thm_download_address[MAX_ENTER_ADDRESS_SIZE + 1];
    CHAR download_address[MAX_ENTER_ADDRESS_SIZE * ENCODING_LENGTH + ENCODING_LENGTH];
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((CHAR*)temp_thm_download_address, (CHAR*)g_thm_download_address);
	mmi_ucs2cpy((CHAR*)download_address, (CHAR*)g_thm_download_address);
    dontSaveURLinHistory = 1;
    if (g_thm_download_address != NULL)
    {
        if(mmi_thm_validate_url((U8*)download_address) == 0)
		{
            strcpy((CHAR*) recent_url_list.g_thm_recent_url[g_recent_item_index - 2], (CHAR*) temp_thm_download_address);
            WriteRecord(
		        NVRAM_EF_THEME_DOWNLOAD_LIST_LID,
		        1,
		        &recent_url_list,
		        NVRAM_THEMES_DOWNLOAD_SIZE /* sizeof(thm_nvram_download_list) */ ,
		        &error);
			
			mmi_thm_goto_url();                    
		}
		else
		{
            mmi_popup_display_simple_ext(
                        STR_GLOBAL_INVALID_URL,
                        MMI_EVENT_FAILURE,
                        GRP_ID_THM_DOWNLOAD,
                        0);
		}
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_thm_address_list_delete_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of enter address url.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_thm_address_list_delete_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR str_buff[100];
    mmi_confirm_property_struct arg;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_ucs2cpy((CHAR*)str_buff, (CHAR*)get_string(STR_GLOBAL_DELETE));
    /*mmi_ucs2cat((CHAR*)str_buff, (CHAR*)L"?");*/

    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = GRP_ID_THM_DOWNLOAD;
    arg.callback = (mmi_proc_func)mmi_theme_comfirm_proc;

    mmi_theme_confirm_user_data_init(&g_theme_confirm_user_data);
    g_theme_confirm_user_data.sg_id = GRP_ID_THM_DOWNLOAD;
    g_theme_confirm_user_data.LSK_function = mmi_thm_address_list_delete_item;

    arg.user_tag = (void*)&g_theme_confirm_user_data;
    arg.f_auto_map_empty_softkey = MMI_FALSE;
	arg.f_auto_question_mark = MMI_TRUE;
    //mmi_confirm_display((WCHAR*)str_buff, MMI_EVENT_QUERY, &arg);
    mmi_confirm_display_ext((STR_GLOBAL_DELETE, MMI_EVENT_QUERY, &arg);
}

/****************************************************************************
 * FUNCTION
 *  mmi_thm_address_list_delete_all_confirm
 * DESCRIPTION
 *  This function displays the confirmation screen for deletion of complete
 *  enter address list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_thm_address_list_delete_all_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR str_buff[100];
    mmi_confirm_property_struct arg;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_ucs2cpy((CHAR*)str_buff, (CHAR*) get_string(STR_GLOBAL_DELETE_ALL));
    /*mmi_ucs2cat((CHAR*)str_buff, (CHAR*) L"?");*/

    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = GRP_ID_THM_DOWNLOAD;
    arg.callback = (mmi_proc_func)mmi_theme_comfirm_proc;

    mmi_theme_confirm_user_data_init(&g_theme_confirm_user_data);
    g_theme_confirm_user_data.sg_id = GRP_ID_THM_DOWNLOAD;
    g_theme_confirm_user_data.LSK_function = mmi_thm_address_list_delete_all;

    arg.user_tag = (void*)&g_theme_confirm_user_data;
    arg.f_auto_map_empty_softkey = MMI_FALSE;
	arg.f_auto_question_mark = MMI_TRUE;
    //mmi_confirm_display((WCHAR*)str_buff, MMI_EVENT_QUERY, &arg);
    mmi_confirm_display_ext(STR_GLOBAL_DELETE_ALL, MMI_EVENT_QUERY, &arg);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_thm_address_list_delete_item 
 * DESCRIPTION
 *  Delete the selected enter address url.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_thm_address_list_delete_item(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;
    S16 error = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = g_recent_item_index - 2; index < recent_url_list.total_entries - 1; index++)
    {
        strcpy((CHAR*)recent_url_list.g_thm_recent_url[index],
                    (CHAR*)recent_url_list.g_thm_recent_url[index+1]);
    }
    memset(recent_url_list.g_thm_recent_url[index], 0, MAX_ENTER_ADDRESS_SIZE + 1);
    recent_url_list.total_entries--;
    
    WriteRecord(
		        NVRAM_EF_THEME_DOWNLOAD_LIST_LID,
		        1,
		        &recent_url_list,
		        NVRAM_THEMES_DOWNLOAD_SIZE /* sizeof(thm_nvram_download_list) */ ,
		        &error);
    mmi_popup_display_simple_ext(STR_GLOBAL_DELETED, MMI_EVENT_SUCCESS, parent_id, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_thm_address_list_delete_all 
 * DESCRIPTION
 *  Delete all selected enter address url.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_thm_address_list_delete_all(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(recent_url_list.g_thm_recent_url, 0, MAX_URL_ENTRIES * (MAX_ENTER_ADDRESS_SIZE + 1));
    recent_url_list.total_entries = 0;
    	
    WriteRecord(
		        NVRAM_EF_THEME_DOWNLOAD_LIST_LID,
		        1,
		        &recent_url_list,
		        NVRAM_THEMES_DOWNLOAD_SIZE /* sizeof(thm_nvram_download_list) */ ,
		        &error);	

    mmi_popup_display_simple((WCHAR*)(get_string(STR_GLOBAL_DELETED)), MMI_EVENT_SUCCESS, parent_id, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_thm_goto_url
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_thm_goto_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR url[(MAX_ENTER_ADDRESS_SIZE + 1) * ENCODING_LENGTH] = {0};    
    mmi_theme_download_group_data_struct *download_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    download_cntx = (mmi_theme_download_group_data_struct*)mmi_frm_group_get_user_data(GRP_ID_THM_DOWNLOAD);
    if (g_recent_item_index == 0)
    {
        mmi_asc_n_to_ucs2((CHAR*)url, (CHAR*)recent_url_list.g_thm_recent_url[g_recent_item_index], MAX_ENTER_ADDRESS_SIZE + 1);
    }
    else if (g_recent_item_index == 1)
    {
        mmi_asc_n_to_ucs2((CHAR*)url, (CHAR*)gDefaultDLT_URL, MAX_ENTER_ADDRESS_SIZE + 1);        
    }
    else
    {
        mmi_asc_n_to_ucs2((CHAR*)url, (CHAR*)recent_url_list.g_thm_recent_url[g_recent_item_index - 2], MAX_ENTER_ADDRESS_SIZE + 1);
    }
#ifdef BROWSER_SUPPORT
    wap_start_browser(WAP_BROWSER_GOTO_URL, (PU8) url);
#endif    
    cui_fseditor_close(download_cntx->fseditor_gid);
}


#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  HighlightThmMenu
 * DESCRIPTION
 *  Hilite function of main themes menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightThmMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_theme_launch, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_theme_launch, KEY_EVENT_UP);    
    //SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightThmUpdatePeriod
 * DESCRIPTION
 *  Hilite function of pupdate period
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightThmUpdatePeriod(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set IsSetFromMenu flag */
    g_thm_cntx.IsSetFromMenu = 1;
    g_thm_cntx.CurrHiliteItem = (U8) nIndex;

    if (nIndex > 0) /* update theme */
    {
        SetLeftSoftkeyFunction(UpdateThemePeriod, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(UpdateThemePeriod, KEY_EVENT_UP);
    }
    else    /* OFF */
    {
        SetLeftSoftkeyFunction(UpdateThemeOff, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(UpdateThemeOff, KEY_EVENT_UP);        
    }
}


/*****************************************************************************
 * FUNCTION
 *  HighlightThmItems
 * DESCRIPTION
 *  Highlight handler of Theme menu,
 *  function show the current selected theme
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightThmItems(S32 index)
{
#ifdef __MMI_THEMES_V2_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_thm_cntx.CurrHiliteTheme = thm_details[index].theme_id;
    g_temp_thm_index = index;
#else /* __MMI_THEMES_V2_SUPPORT__ */ 
    g_thm_cntx.CurrHiliteTheme = (U8) index;
    SetBothLCDThemes(g_thm_cntx.CurrHiliteTheme);
    /* PMT VIKAS START 20050707 */
#if (defined __MMI_MAINLCD_176X220__) && (defined __MMI_UI_DALMATIAN_STATUSBAR__)
    gOnFullScreen |= MMI_LEAVE_FULL_SCREEN; /* for showing the updated status bar on Theme menu. */
#endif 
    /* PMT VIKAS END 20050707 */
    /* Reset screen background layer */
    dm_set_scr_bg_redraw(MMI_TRUE); 
    RedrawCategoryFunction();
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ThmHandleRSK
 * DESCRIPTION
 *  Change theme to original one and go back history.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ThmHandleRSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_thm_cntx.CurrHiliteTheme != g_thm_cntx.CurrTheme)
    {
        SetBothLCDThemes((U8)g_thm_cntx.CurrTheme);
    }

    g_thm_cntx.IsInThmApp = 0;
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  ThmRedrawTheme
 * DESCRIPTION
 *  Redraw current hilite theme in option menu to make the user preceive current
 *  selecting theme
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ThmRedrawTheme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_thm_cntx.CurrHiliteTheme != g_thm_cntx.CurrTheme)
    {
        SetBothLCDThemes((U8)g_thm_cntx.CurrHiliteTheme);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitThmMenu
 * DESCRIPTION
 *  Exit function for theme menu, restore theme after exit theme screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitThmMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_thm_cntx.CurrHiliteTheme != g_thm_cntx.CurrTheme)
        /* PMT VIKAS START 20050707 */
#if (defined __MMI_MAINLCD_176X220__) && (defined __MMI_UI_DALMATIAN_STATUSBAR__)
    {
        gOnFullScreen |= MMI_LEAVE_FULL_SCREEN; /* for showing the updated status bar on Theme menu. */
#endif /* (defined __MMI_MAINLCD_176X220__) && (defined __MMI_UI_DALMATIAN_STATUSBAR__) */ 
        //if (IsBackHistory == MMI_TRUE)
        {
            SetBothLCDThemes((U8)g_thm_cntx.CurrTheme);
        }
    #if (defined __MMI_MAINLCD_176X220__) && (defined __MMI_UI_DALMATIAN_STATUSBAR__)
    }
    #endif 
    /* PMT VIKAS END 20050707 */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_theme_menu_handler
 * DESCRIPTION
 *  Proc function for display setup group 
 * PARAMETERS
 *  param   [IN]
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_theme_menu_handler(void *param, MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    mmi_ret ret = MMI_RET_DONT_CARE;
    cui_menu_event_struct *evt = (cui_menu_event_struct *)param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            switch (evt->highlighted_menu_id)
            {
                case MENU3101_THEMES:
                {
                    mmi_theme_launch();
                    return MMI_RET_OK;
                }
                default:
                    break;
            }    
            break;
        }
        default:
        {        
            break;
        }
    }
    return MMI_RET_DONT_CARE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_theme_launch
 * DESCRIPTION
 *  Show a lsit of themes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_theme_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create_ex(GRP_ID_ROOT,
                         GRP_ID_THM_MAIN,
                         mmi_theme_main_group_proc,
                         NULL,
                         MMI_FRM_NODE_SMART_CLOSE_FLAG);
    g_thm_cntx.IsInThmApp = MMI_TRUE;
    
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__    
    if (mmi_thm_get_usb_mode())
    {
        mmi_theme_entry_usb_int();
    }
    else
#endif    
    {
        mmi_theme_entry_int();
    }
}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif


#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_theme_entry_usb_int
 * DESCRIPTION
 *  Show a list of themes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_theme_entry_usb_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 i = 0;
    U16 list_icons1[MAX_SUB_MENUS];
    U16 list_icons2[MAX_SUB_MENUS];
    U8 *temp_name;
    U8 nSystemThemeCount;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_enter(
            GRP_ID_THM_MAIN,
            SCR_ID_THM_MENU,
            ExitThmMenu,
            mmi_theme_entry_usb_int,
            MMI_FRM_FULL_SCRN);

    nSystemThemeCount = (U8)GetThemesNames((U8 ***) & temp_name);
    if (nSystemThemeCount > MAX_SYSTEM_THEMES)
    {
        nSystemThemeCount = MAX_SYSTEM_THEMES;
    }

    for (i = 0; i < nSystemThemeCount; i++)
    {
#ifndef __MMI_PHNSET_SLIM__    
        if (thm_details[i].theme_type == THEME_TYPE_SYSTEM)
        {
            list_icons2[i] = IMAGE_SYSTEM_THEME;
        }
        else
        {
            list_icons2[i] = 0;
        }
    #else
        list_icons2[i]=(thm_details[i].theme_type == THEME_TYPE_SYSTEM ? IMAGE_SYSTEM_THEME : 0 );
    #endif
        if (g_thm_cntx.CurrTheme == thm_details[i].theme_id)
        {
            g_thm_cntx.CurrThemeIndex = i;
            list_icons1[i] = IMG_VICON;
        }
        else
        {
            list_icons1[i] = IMAGE_NOIMAGE_THEME;
        }

        g_thm_cntx.ThemeName[i] = (PU8)GetString((U16)(STR_THEME_DEFAULT + i));
    }
    
    g_thm_cntx.ThemeName[i] = (PU8) GetString(STR_GLOBAL_NONE);
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    RegisterHighlightHandler(HighlightThmItems);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    
    ShowCategory73Screen(
        STR_MENU3101_THEMES,
        GetRootTitleIcon(MENU3101_THEMES),        
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nSystemThemeCount,
        (U8**)g_thm_cntx.ThemeName,
        list_icons1,
        list_icons2,
        (U16)g_thm_cntx.CurrThemeIndex,
        guiBuffer,
        1);
    
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_tap_callback(mmi_thm_tap_list_callback);
#endif

    SetLeftSoftkeyFunction(EntryThmOptions, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(ActivateTheme, KEY_EVENT_UP);      
    SetRightSoftkeyFunction(ThmHandleRSK, KEY_EVENT_UP);
    SetKeyHandler(ThmHandleEndKey, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_theme_entry_int
 * DESCRIPTION
 *  Function to show theme list from theme application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_theme_entry_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    U8 thm_file_check = 0;
    U8 *guiBuffer;
    U8 i = 0;
    U16 list_icons1[MAX_SUB_MENUS];
    U16 list_icons2[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_frm_scrn_enter(
            GRP_ID_THM_MAIN,
            SCR_ID_THM_MENU,
            ExitThmMenu,
            mmi_theme_entry_int,
            MMI_FRM_FULL_SCRN);

    ConstructThemeList();
    g_thm_cntx.CurrTheme = mmi_tm_get_current_theme_id();

    for (i = 0; i < g_thm_cntx.TotalTheme; i++)
    {
        if (thm_details[i].theme_type == THEME_TYPE_SYSTEM)
        {
            list_icons2[i] = IMAGE_SYSTEM_THEME;
        }
        else if (thm_details[i].theme_type == THEME_TYPE_DOWNLOADED_PHONE)
        {
            list_icons2[i] = IMAGE_PHONE_THEME;
        }
        else if (thm_details[i].theme_type == THEME_TYPE_DOWNLOADED_CARD)
        {
            list_icons2[i] = IMAGE_CARD_THEME;
        }

        list_icons1[i] = IMAGE_NOIMAGE_THEME;
        if (g_thm_cntx.CurrTheme == thm_details[i].theme_id)
        {
            g_thm_cntx.CurrThemeIndex = i;
            list_icons1[i] = IMG_VICON;
        }
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    RegisterHighlightHandler(HighlightThmItems);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ShowCategory73Screen(
        STR_MENU3101_THEMES,
        GetRootTitleIcon(MENU3101_THEMES),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_thm_cntx.TotalTheme,
        (U8**)g_thm_cntx.ThemeName,
        list_icons1,
        list_icons2,
        (U16) g_thm_cntx.CurrThemeIndex,
        guiBuffer,
        1);
    
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_tap_callback(mmi_thm_tap_list_callback);
#endif
    SetLeftSoftkeyFunction(EntryThmOptions, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(ActivateTheme, KEY_EVENT_UP);     
    SetRightSoftkeyFunction(ThmHandleRSK, KEY_EVENT_UP);
    SetKeyHandler(ThmHandleEndKey, KEY_END, KEY_EVENT_DOWN);
}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_thm_card_plug_out_hdlr
 * DESCRIPTION
 *  callback handler of plug out memory card
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
//void mmi_thm_card_plug_out_hdlr(void *para)
void mmi_thm_card_plug_out_hdlr(srv_fmgr_notification_dev_plug_event_struct *dev_plug)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __OTG_ENABLE__
    //mmi_fmgr_notify_unmount_info_struct *unmount_info = (mmi_fmgr_notify_unmount_info_struct*)para;
    S32 j;
#endif
    S32 i;
    
    MMI_BOOL clear_flag = MMI_FALSE;
	U16 active_scr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* theme may be set in fmgr */
    g_thm_cntx.CurrTheme = mmi_tm_get_current_theme_id();
    g_thm_cntx.TotalTheme = mmi_tm_get_total_themes_count();

    for (i = 0; i < g_thm_cntx.TotalTheme; i++)
    {
    	if (thm_details[i].theme_type == THEME_TYPE_DOWNLOADED_CARD)
		{
	    	if (g_thm_cntx.CurrHiliteTheme== thm_details[i].theme_id)
			{
				clear_flag = MMI_TRUE;
			}
			
	        if (g_thm_cntx.CurrTheme == thm_details[i].theme_id)
            {
#ifndef __OTG_ENABLE__
                ActivateDefaultTheme();
#endif
                break;
            }
        }
    }
	
    MMI_TRACE(MMI_COMMON_TRC_G2_ORG, MMI_THEME_PLUG_OUT_CARD_THM_DRV, thm_details[i].drv_letter);
#ifdef __OTG_ENABLE__
    if (i != g_thm_cntx.TotalTheme)
    {
        for(j = 0; j < dev_plug->count; j++)
        {
            MMI_TRACE(MMI_COMMON_TRC_G2_ORG, MMI_THEME_PLUG_OUT_CARD_PLUGOUT_DRV, dev_plug->drv_letters[j]);
 
            if(dev_plug->drv_letters[j] == thm_details[i].drv_letter)
            {
            	if (g_thm_cntx.CurrHiliteTheme== thm_details[i].theme_id)
        		{
        			clear_flag = MMI_TRUE;
        		}
				
				if (g_thm_cntx.CurrTheme == thm_details[i].theme_id)
				{
                    ActivateDefaultTheme();
                    break;
                }
            }
        }
    }
  
#endif /* __OTG_ENABLE__ */
	/*
	 * If the current theme is being edited, then deleting all the related screen.
	 */
	if (clear_flag)
	{
		active_scr = GetActiveScreenId();

		DeleteScreenIfPresent(SCR_ID_THM_OPTIONS);
		DeleteScreenIfPresent(SCR_ID_THM_SET_ORDER);

		if (active_scr == SCR_ID_THM_OPTIONS || active_scr == SCR_ID_THM_SET_ORDER)
		{
			GoBackHistory();
		}
	}
}
#else /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_theme_entry_int
 * DESCRIPTION
 *  Function to show theme list from theme application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_theme_entry_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *list_icons1;
    U16 *list_icons2;
    U16 nItems;
    U8 *guiBuffer;
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    mmi_frm_scrn_enter(
            GRP_ID_THM_MAIN,
            SCR_ID_THM_MENU,
            ExitThmMenu,
            mmi_theme_entry_int,
            MMI_FRM_FULL_SCRN);

    FillThemesList();
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    nItems = (U16) g_thm_cntx.TotalTheme;
    list_icons1 = (U16*) OslMalloc(nItems * sizeof(PU16));
    list_icons2 = (U16*) OslMalloc(nItems * sizeof(PU16));
    
    for (i = 0; i < nItems; i++)
    {
        if (i == g_thm_cntx.CurrTheme)
        {
            list_icons1[i] = IMG_VICON;
        }
        else
        {
            list_icons1[i] = IMAGE_NOIMAGE_THEME;
        }
    }
    
    for (i = 0; i < nItems; i++)
    {
        list_icons2[i] = IMAGE_NOIMAGE_THEME;
    }

    RegisterHighlightHandler(HighlightThmItems);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory73Screen(
        STR_MENU3101_THEMES,
        GetRootTitleIcon(MENU3101_THEMES),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        (U8 **) g_thm_cntx.ThemeName,
        list_icons1,
        list_icons2,
        (U16) g_thm_cntx.CurrTheme,
        guiBuffer,
        0);

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_tap_callback(mmi_thm_tap_list_callback);
#endif

    SetLeftSoftkeyFunction(EntryThmOptions, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(ActivateTheme, KEY_EVENT_UP); 
    
    SetRightSoftkeyFunction(ThmHandleRSK, KEY_EVENT_UP);
    SetKeyHandler(ThmHandleEndKey, KEY_END, KEY_EVENT_DOWN);
    
    if (list_icons1)
    {
        OslMfree(list_icons1);
    }
    
    if (list_icons2)
    {
        OslMfree(list_icons2);
    }
}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */

#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata = "DYNAMIC_CODE_SETTINGS_RODATA" , code = "DYNAMIC_CODE_SETTINGS_ROCODE"
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_theme_main_group_proc
 * DESCRIPTION
 *  Proc function of edit group.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_theme_main_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch(evt->evt_id)
    {
#ifndef __MMI_PHNSET_SLIM__    
        case EVT_ID_GROUP_FIRST_ENTRY:
        {
            break;
        }
        #endif
        case EVT_ID_GROUP_DEINIT:
        {
        #ifndef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
            mmi_thm_reset_current_theme();        
        #endif
            break;
        }
#ifndef __MMI_PHNSET_SLIM__    
        default:
            break;
        #endif    
    }
    return MMI_RET_OK;

}


/*****************************************************************************
 * FUNCTION
 *  ThmHandleEndKey
 * DESCRIPTION
 *  Function handle end key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ThmHandleEndKey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_thm_cntx.CurrHiliteTheme != g_thm_cntx.CurrTheme)
    {
        SetBothLCDThemes((U8)g_thm_cntx.CurrTheme);
    }

    g_thm_cntx.IsInThmApp = 0;
    mmi_idle_display();
}


/*****************************************************************************
 * FUNCTION
 *  EntryThmOptions
 * DESCRIPTION
 *  Entry func of themes option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void EntryThmOptions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_menu_id menu_id = 0;  
    mmi_theme_common_group_data_struct *opt_user_data;         
//    U16 nItems;
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    /* PMT DLT_FIXES - TK 20060321 START */
    U8 *temp_name;
    U8 nSystemThemeCount;
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    opt_user_data = (mmi_theme_common_group_data_struct*)OslMalloc(sizeof(mmi_theme_common_group_data_struct));
    memset(opt_user_data, 0, sizeof(mmi_theme_common_group_data_struct));
    opt_user_data->parent_id = GRP_ID_THM_MAIN;

    opt_user_data->group_id = mmi_frm_group_create_ex(
                                                GRP_ID_THM_MAIN,
                                                GRP_ID_AUTO_GEN,
                                                mmi_theme_option_group_proc,
                                                opt_user_data,
                                                MMI_FRM_NODE_NONE_FLAG);

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    if (g_thm_cntx.CurrHiliteTheme == g_thm_cntx.CurrTheme)
    {
        if (MMI_FALSE
        #ifdef __FLIGHT_MODE_SUPPORT__
            || !srv_mode_switch_is_network_service_available()
        #endif 
            )
        {
            menu_id = MENU3001_THEMES_LIST_1_FLIGHTMODE;
        }
        else
        {
            menu_id = MENU3001_THEMES_LIST_1;
        }
    }
    else
    {
        nSystemThemeCount = (U8) GetThemesNames((U8 ***) & temp_name);
        if (nSystemThemeCount > MAX_SYSTEM_THEMES)
        {
            nSystemThemeCount = MAX_SYSTEM_THEMES;
        }
        if (g_temp_thm_index < nSystemThemeCount)
        {
            if (MMI_FALSE
            #ifdef __FLIGHT_MODE_SUPPORT__
                || !srv_mode_switch_is_network_service_available()
            #endif 
                )
            {            
                menu_id = MENU3001_THEMES_LIST_1_FLIGHTMODE;
            }
            else
            {            
                menu_id = MENU3001_THEMES_LIST_1;
            }
        }
        else
        {
            if (MMI_FALSE
            #ifdef __FLIGHT_MODE_SUPPORT__
                || !srv_mode_switch_is_network_service_available()
            #endif 
                )
            {
                menu_id = MENU3001_THEMES_LIST_FLIGHTMODE;
            }
            else
            {
                menu_id = MENU3001_THEMES_LIST;
            }
        }
    }
//    if (mmi_thm_get_usb_mode())
//    {
//        nItems = NO_OF_THEME_OPTION_MENUITEMS_IN_USB_MODE; 
//
//    }
#else /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
    menu_id = MENU3001_THEMES_LIST;
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */     

    opt_user_data->child_id = cui_menu_create(
                                        opt_user_data->group_id,
                                        CUI_MENU_SRC_TYPE_RESOURCE,
                                        CUI_MENU_TYPE_OPTION,
                                        menu_id,
                                        MMI_TRUE,
                                        NULL);
    cui_menu_set_default_title_by_id(
                            opt_user_data->child_id, 
                            STR_GLOBAL_OPTIONS,
                            0);

    cui_menu_run(opt_user_data->child_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_theme_option_group_proc
 * DESCRIPTION
 *  Generate the menus.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_theme_option_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    mmi_theme_common_group_data_struct *opt_user_data;     
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    opt_user_data = (mmi_theme_common_group_data_struct*)evt->user_data;
    switch(menu_evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
        {
            OslMfree(opt_user_data);
            break;
        }    
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            mmi_theme_option_menu_cui_entry_hdlr(menu_evt);
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        {
            mmi_theme_option_menu_cui_highlight_hdlr(menu_evt);
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            mmi_theme_option_menu_cui_select_hdlr(menu_evt);
            break;
        }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(opt_user_data->child_id);
            mmi_frm_group_close(opt_user_data->group_id);
            break;
        }
    }
    return MMI_RET_OK;        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_theme_option_menu_cui_entry_hdlr
 * DESCRIPTION
 *  Generate the menus.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_theme_option_menu_cui_entry_hdlr(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    //mmi_theme_common_group_data_struct *opt_user_data = menu_evt->user_data;     
    mmi_group_event_struct *common_evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->parent_menu_id)
    {
        case MENU3201_UPDATE_PERIOD:
        {
            common_evt = (mmi_group_event_struct*)menu_evt;
			cui_menu_set_default_title_string_by_id(common_evt->sender_id,STR_MENU3201_UPDATE_PERIOD);
			cui_menu_set_default_title_image_by_id(common_evt->sender_id, GetRootTitleIcon(MENU3101_THEMES));

	    if (menu_evt->cui_menu_event_flags != CUI_MENU_LIST_FROM_HISTORY)
	    {
            cui_menu_set_currlist_highlighted_id(
                    common_evt->sender_id, 
                    g_thm_cntx.CurrUpdatePeriod + MENU3301_UPDATE_OFF);
							
	    }
            break;
        }   
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
		case MENU3001_THEMES_LIST_1_FLIGHTMODE:
		case MENU3001_THEMES_LIST_1:
		case MENU3001_THEMES_LIST_FLIGHTMODE:
#endif
		case MENU3001_THEMES_LIST:
			common_evt = (mmi_group_event_struct*)menu_evt;
			cui_menu_set_default_title_image_by_id(common_evt->sender_id, GetRootTitleIcon(MENU3101_THEMES));
		cui_menu_set_non_leaf_item(common_evt->sender_id, MENU3201_UPDATE_PERIOD, MMI_FALSE);
			break;
			
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_theme_option_menu_cui_highlight_hdlr
 * DESCRIPTION
 *  Generate the menus.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_theme_option_menu_cui_highlight_hdlr(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    mmi_theme_common_group_data_struct *thm_data = (mmi_theme_common_group_data_struct *)menu_evt->user_data;     
    //U16 hint_string;
    CHAR* hint_string;
	U8 freq;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->highlighted_menu_id)
    {
#ifndef __MMI_PHNSET_SLIM__    
        case MENU_THEMES_ACTIVATE:
            break;
#endif            
            
        case MENU3201_UPDATE_PERIOD:
			freq = g_themes_freq_set[g_thm_cntx.CurrUpdatePeriod];
#ifndef __MMI_PHNSET_SLIM__    
			hint_string = mmi_theme_get_period_hint_string((FREQ_ALARM)freq);
            #else
            {
                U16 i=0;
                U16  theme_period_hint_string[]={
                                    ALM_FREQ_HOURLY,
                                    ALM_FREQ_EVERYDAY,
                                    ALM_FREQ_WEEKLY,
                                    ALM_FREQ_MONTHLY,
                                    ALM_FREQ_SEASONALLY,
                                    NULL
                                    };
                    if(freq==ALM_FREQ_OFF)
                     {
                        hint_string = (CHAR*)GetString(STR_GLOBAL_OFF);;
                     }
                     else
                    {
                        while(theme_period_hint_string[i]!=freq)
                          {
                             i++;
                          }
                        hint_string=(CHAR*)GetString(STR_MENU3302_UPDATE_HOURLY+i);
                    }
       }
       #endif     
			cui_menu_set_item_hint(thm_data->child_id, MENU3201_UPDATE_PERIOD, (WCHAR *)hint_string);
			break;
			
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_theme_option_menu_cui_select_hdlr
 * DESCRIPTION
 *  Generate the menus.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_theme_option_menu_cui_select_hdlr(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    mmi_theme_common_group_data_struct *opt_user_data = menu_evt->user_data;     
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch (menu_evt->highlighted_menu_id)
    {
        case MENU_THEMES_ACTIVATE:
        {
            ActivateTheme();
            break;
        }   
        case MENU3202_SET_ORDER:
        {
            EntryThmSetOrder();
            break;
        }

		case MENU3201_UPDATE_PERIOD:
		{
			EntryThmUpdatePeriod();
			break;
		}
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__        
        case MENU_THEMES_DOWNLOAD:
        {
            mmi_thm_pre_entry_dwnld();
            break;
        }
        case MENU_THEMES_DELETE:
        {
            ThemeDeleteConfirmation();
            break;
        }
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */  
        case MENU3301_UPDATE_OFF:
        {
            g_thm_cntx.IsSetFromMenu = 1;
            g_thm_cntx.CurrHiliteItem = 0;
            UpdateThemeOff();
			mmi_frm_group_close(opt_user_data->group_id);
            break;
        }
        case MENU3302_UPDATE_HOURLY:
        {
            g_thm_cntx.IsSetFromMenu = 1;
            g_thm_cntx.CurrHiliteItem = 1;        
            UpdateThemePeriod();
			mmi_frm_group_close(opt_user_data->group_id);
            break;
        }
        case MENU3303_UPDATE_DAILY:
        {
            g_thm_cntx.IsSetFromMenu = 1;
            g_thm_cntx.CurrHiliteItem = 2;        
            UpdateThemePeriod();
			mmi_frm_group_close(opt_user_data->group_id);
            break;
        }
        case MENU3304_UPDATE_WEEKLY:
        {
            g_thm_cntx.IsSetFromMenu = 1;
            g_thm_cntx.CurrHiliteItem = 3;        
            UpdateThemePeriod();
			mmi_frm_group_close(opt_user_data->group_id);
            break;
        }
        case MENU_UPDATE_MONTHLY:
        {
            g_thm_cntx.IsSetFromMenu = 1;
            g_thm_cntx.CurrHiliteItem = 4;        
            UpdateThemePeriod();
			mmi_frm_group_close(opt_user_data->group_id);
            break;
        }
        case MENU_UPDATE_SEASONALLY:
        {
            g_thm_cntx.IsSetFromMenu = 1;
            g_thm_cntx.CurrHiliteItem = 5;        
            UpdateThemePeriod();
			mmi_frm_group_close(opt_user_data->group_id);
            break;
        }
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryThmUpdatePeriod
 * DESCRIPTION
 *  entry func of themes update period menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryThmUpdatePeriod(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_theme_common_group_data_struct *opt_user_data;         

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    opt_user_data = (mmi_theme_common_group_data_struct*)OslMalloc(sizeof(mmi_theme_common_group_data_struct));
    memset(opt_user_data, 0, sizeof(mmi_theme_common_group_data_struct));
    opt_user_data->parent_id = GRP_ID_THM_MAIN;

    opt_user_data->group_id = mmi_frm_group_create_ex(
                                                GRP_ID_THM_MAIN,
                                                GRP_ID_AUTO_GEN,
                                                mmi_theme_option_group_proc,
                                                opt_user_data,
                                                MMI_FRM_NODE_NONE_FLAG);

    opt_user_data->child_id = cui_menu_create(
                                        opt_user_data->group_id,
                                        CUI_MENU_SRC_TYPE_RESOURCE,
                                        CUI_MENU_TYPE_APPMAIN,
                                        MENU3201_UPDATE_PERIOD,
                                        MMI_TRUE,
                                        NULL);
    cui_menu_set_default_title_by_id(
                            opt_user_data->child_id, 
                            STR_MENU3201_UPDATE_PERIOD,
                            0/*GetRootTitleIcon(MENU3101_THEMES)*/);
                            
    cui_menu_run(opt_user_data->child_id);


}
#ifdef __MMI_AP_DCM_SETTING__
#pragma arm section rodata , code
#endif
/*****************************************************************************
 * FUNCTION
 *  ActivateTheme
 * DESCRIPTION
 *  Activate theme select bu yser and write to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ActivateTheme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_THEMES_V2_SUPPORT__
    S32 result;
    U16 img_id;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifndef __MTK_TARGET__
    /* If MTE is active, no theme activation is allowed. */
    if (mmi_mte_is_active())
    {
        mmi_popup_display_simple_ext(STR_THEME_NOT_AVAILABLE, MMI_EVENT_FAILURE, GRP_ID_THM_MAIN, NULL);
        return;
    }
#endif /* __MTK_TARGET__ */

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__

	if (mmi_thm_is_dlt_theme(g_thm_cntx.CurrHiliteTheme))
	{

    mmi_frm_scrn_enter(
            GRP_ID_THM_MAIN,
            SCR_ID_DUMMY,
            NULL,
            NULL,
            MMI_FRM_FULL_SCRN);

	img_id = mmi_get_event_based_image(MMI_EVENT_PROGRESS);
		
	
    ShowCategory66Screen(
        STR_SCR3001_THEMES_CAPTION,
        GetRootTitleIcon(MENU3101_THEMES),
        0,
        0,
        0,
        0,
        (PU8) GetString(STR_ID_DLT_THM_PROGRESS),
        img_id,
        NULL);
		g_mmi_thm_snd_id = mmi_get_event_based_sound(MMI_EVENT_PROGRESS);
    if(!srv_prof_is_tone_playing(g_mmi_thm_snd_id))
    {
        srv_prof_play_tone(g_mmi_thm_snd_id, NULL);
    }
	}
	
    result = mmi_tm_activate_theme(g_thm_cntx.CurrHiliteTheme);
    if (result == THEME_ERROR_SUCCESS)
    {
        g_thm_cntx.CurrTheme = g_thm_cntx.CurrHiliteTheme;
        g_thm_cntx.CurrThemeIndex = g_temp_thm_index;
        SetThemes((U8)g_thm_cntx.CurrTheme);
        if (g_themes_freq_set[g_thm_cntx.CurrUpdatePeriod] != ALM_FREQ_OFF)
        {
            SetStartPositionofCurIndex();
        }

        SetCurrOrderIndex(g_thm_cntx.CurrOrderIndex);
    }

    mmi_thm_display_error_msg(result, GRP_ID_THM_MAIN);

#else /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
	{
    if (g_thm_cntx.CurrHiliteTheme != g_thm_cntx.CurrTheme)
    {
        SetBothLCDThemes(g_thm_cntx.CurrHiliteTheme);
        g_thm_cntx.CurrTheme = g_thm_cntx.CurrHiliteTheme;

        if (g_themes_freq_set[g_thm_cntx.CurrUpdatePeriod] != ALM_FREQ_OFF)
        {
            SetStartPositionofCurIndex();
        }
        WriteThemesToNVRAM();
    }

    mmi_popup_display_simple_ext(STR_GLOBAL_ACTIVATED, MMI_EVENT_SUCCESS, GRP_ID_THM_MAIN, NULL);
		
	}
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
	g_thm_cntx.IsInThmApp = 0;
}

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/*****************************************************************************
 * FUNCTIONs
 *  ThemeDeleteConfirmation
 * DESCRIPTION
 *  Function for theme delete confirmation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ThemeDeleteConfirmation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR str_buff[100];
    mmi_confirm_property_struct arg;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((CHAR*)str_buff, (CHAR*)get_string(STR_GLOBAL_DELETE));
    mmi_ucs2cat((CHAR*)str_buff, (CHAR*)L" ");
    mmi_ucs2cat((CHAR*)str_buff, (CHAR*)g_thm_cntx.ThemeName[g_temp_thm_index]);
    /*mmi_ucs2cat((CHAR*)str_buff, (CHAR*)L"?");*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = GRP_ID_THM_MAIN;
    arg.callback = (mmi_proc_func)mmi_theme_comfirm_proc;
    mmi_theme_confirm_user_data_init(&g_theme_confirm_user_data);
    g_theme_confirm_user_data.sg_id = GRP_ID_THM_MAIN;
    g_theme_confirm_user_data.LSK_function = DeleteTheme;
    arg.user_tag = (void*)&g_theme_confirm_user_data;
    arg.f_auto_map_empty_softkey = MMI_FALSE;
	arg.f_auto_question_mark = MMI_TRUE;
    mmi_confirm_display((WCHAR*)str_buff, MMI_EVENT_QUERY, &arg);
}


/*****************************************************************************
 * FUNCTION
 *  DeleteTheme
 * DESCRIPTION
 *  Function to delete a theme from theme application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeleteTheme(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error_type, result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmi_tm_delete_theme(g_thm_cntx.CurrHiliteTheme, &error_type);
    if (result == THEME_ERROR_SUCCESS)
    {
        UpdateOrder(g_thm_cntx.CurrHiliteTheme);
        mmi_popup_display_simple_ext(STR_GLOBAL_DELETED, MMI_EVENT_SUCCESS, GRP_ID_THM_MAIN, NULL);
    }        
    else
    {
        mmi_popup_display_simple_ext(
                        srv_fmgr_fs_error_get_string(error_type),
                        (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(error_type),
                        GRP_ID_THM_DOWNLOAD,
                        0);
        
    }
}


/*****************************************************************************
 * FUNCTION
 *  UpdateOrder
 * DESCRIPTION
 *  Function to update set order during deletion
 * PARAMETERS
 *  thm_del_ID      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UpdateOrder(U32 thm_del_ID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
    U8 count = 0;
    U16 tmpidlist[TOTAL_THEMES_COUNT];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_thm_cntx.TotalTheme = mmi_tm_get_total_themes_count();

    if (g_thm_cntx.CurrTheme == thm_del_ID)
    {
        g_thm_cntx.CurrTheme = DefaultThmID;
        g_thm_cntx.CurrThemeIndex = DefaultThmIndex;
    }

    for (i = 0; i <= g_thm_cntx.CurrOrderIndex; i++)
    {
        if (thm_del_ID == g_thm_cntx.SetOrderIDList[i])
        {
            count++;
        }
    }
    if (g_thm_cntx.CurrOrderIndex >= count)
    {
        g_thm_cntx.CurrOrderIndex = g_thm_cntx.CurrOrderIndex - count;
    }
    count = 0;

    for (i = 0; i < g_thm_cntx.TotalTheme + 1; i++)
    {
        if (thm_del_ID != g_thm_cntx.SetOrderIDList[i])
        {
            tmpidlist[count] = g_thm_cntx.SetOrderIDList[i];
            count++;
        }
    }
    for (i = 0; i <= count; i++)
    {
        g_thm_cntx.SetOrderIDList[i] = tmpidlist[i];

    }
    for (i = count; i < g_thm_cntx.TotalTheme; i++)
    {

        g_thm_cntx.SetOrderIDList[i] = 0;

    }

    SetOrderIDList(g_thm_cntx.SetOrderIDList, count, g_thm_cntx.CurrOrderIndex);
    WriteThemesToNVRAM();
}
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  UpdateThemeOff
 * DESCRIPTION
 *  Cancel the update alarm set by user and write to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UpdateThemeOff(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_thm_cntx.CurrOrderIndex = -1;
    g_thm_cntx.IsOrderChanged = 0;

    /* if previous setting is not off, some theme-alarm is set before, cancel the alarm */
    if (g_themes_freq_set[g_thm_cntx.CurrUpdatePeriod] != ALM_FREQ_OFF)
    {
        //AlmCancelAlarm(ALM_THM_START);
        srv_reminder_cancel(SRV_REMINDER_TYPE_THEME,0);   
    }

    g_thm_cntx.CurrUpdatePeriod = ALM_FREQ_OFF;

    WriteThemesToNVRAM();
    mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
    g_thm_cntx.IsInThmApp = 0;
}

/* PMT DNLD_THEME_FIXES: SHARIQ START BUG# MAUI_00191466 */


/*****************************************************************************
 * FUNCTION
 *  AlarmExpireUpdateThemeOff
 * DESCRIPTION
 *  Sets the update theme alarm to off when no theme is present in set order list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlarmExpireUpdateThemeOff(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_thm_cntx.CurrOrderIndex = -1;
    g_thm_cntx.IsOrderChanged = 0;

    /* if previous setting is not off, some theme-alarm is set before, cancel the alarm */
    if (g_thm_cntx.CurrUpdatePeriod > 0)
    {
        //AlmCancelAlarm(ALM_THM_START);
        srv_reminder_cancel(SRV_REMINDER_TYPE_THEME,0);
    }

    g_thm_cntx.CurrUpdatePeriod = ALM_FREQ_OFF;

    WriteThemesToNVRAM();

    g_thm_cntx.IsInThmApp = 0;
}

/* PMT DNLD_THEME_FIXES: SHARIQ END BUG# MAUI_00191466 */


/*****************************************************************************
 * FUNCTION
 *  UpdateThemePeriod
 * DESCRIPTION
 *  Set update period and write to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UpdateThemePeriod(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Leo add for DLT */
#ifdef __MMI_THEMES_V2_SUPPORT__

    if (g_thm_cntx.IsSetFromMenu == 1 && g_thm_cntx.CurrHiliteItem != g_thm_cntx.CurrUpdatePeriod)
    {
        g_thm_cntx.CurrUpdatePeriod = g_thm_cntx.CurrHiliteItem;
        g_thm_cntx.IsOrderChanged = 1;
    }
#else /* __MMI_THEMES_V2_SUPPORT__ */ 
    if (g_thm_cntx.IsSetFromMenu == 1)
    {
        g_thm_cntx.CurrUpdatePeriod = g_thm_cntx.CurrHiliteItem;
        g_thm_cntx.IsOrderChanged = 1;
    }
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 
    SetStartPositionofCurIndex();

    WriteThemesToNVRAM();

	// set reminder
    ThemesReInitQueueCBH();

    if (g_thm_cntx.IsSetFromMenu == 1)  /* not OFF */
    {
        mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
        g_thm_cntx.IsInThmApp = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ThemeAlarmCallBack
 * DESCRIPTION
 *  Call back function when theme alarm expires
 * PARAMETERS
 *  index           [IN]        
 *  period          [?]         
 *  power_on        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 ThemeAlarmCallBack(U8 index, U16 *period, BOOL power_on)
{
#ifdef __J2ME__
	U8 IsJavaPlaying = FALSE;
#endif	

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifdef __MMI_THEMES_V2_SUPPORT__
    U8 no_of_times;
    S32 result = THEME_ERROR_FAILURE;
    U16 order_theme_id = 0;
    U16 count, start_index;
    U32 *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_THM_TRACE1(MMI_THEME_UPDATE_CALLBACK_PATH, 1);
    
    /* PMT DNLD_THEME_FIXES: SHARIQ END BUG# MAUI_00221092 */
    if (mmi_thm_get_usb_mode())
    {
        g_tm_was_theme_alarm_cb = MMI_TRUE;
        *period = ALM_WITHOUD_EXPIRY_PERIOD;
        #ifndef __MMI_DEV_NEW_SLIM__
            return ALM_HAS_NO_IND;
        #else
            return MMI_FALSE;
        #endif
    }

    count = GetIDList(&p, &g_thm_cntx.CurrOrderIndex); 
    MMI_THM_TRACE1(MMI_THEME_UPDATE_CALLBACK_PATH, 2);

    g_thm_cntx.CurrTheme = mmi_tm_get_current_theme_id();

    g_thm_cntx.TotalTheme = mmi_tm_get_total_themes_count();

    for (no_of_times = 0; no_of_times < g_thm_cntx.TotalTheme; no_of_times++)
    {
        g_thm_cntx.SetOrderIDList[no_of_times] = p[no_of_times];
    }

    start_index = (U16)g_thm_cntx.CurrOrderIndex;
    if (start_index >= g_thm_cntx.TotalTheme)
    {
        start_index = 0;
    }
	
   MMI_TRACE(MMI_COMMON_TRC_G2_ORG, 
    		 MMI_THEME_UPDATE_CALLBACK, 
    		 (S32)count, 
    		 (S32)g_thm_cntx.CurrTheme, 
    		 (S32)g_thm_cntx.TotalTheme); 
               
    /* PMT DNLD_THEME_FIXES: SHARIQ START BUG# MAUI_00191466 */
    if (count == 0)
    {
        AlarmExpireUpdateThemeOff();
    }
    /* PMT DNLD_THEME_FIXES: SHARIQ END BUG# MAUI_00191466 */
    else
        /* Fix for dodge ball game */
    {
	//PMT DNLD FIXES 20060513: SUKRIT START MAUI_00192671	
	#ifdef __J2ME__
        if (GetActiveScreenId() == SCR_JAVA_APP)
        {
            IsJavaPlaying = TRUE;
            jam_pause_dummy_screen();
        }
    #endif /* __J2ME__ */ 
	//PMT DNLD FIXES 20060513: SUKRIT END MAUI_00192671

        for (no_of_times = 0; no_of_times < g_thm_cntx.TotalTheme; no_of_times++)
        {
            if ((g_thm_cntx.CurrOrderIndex == (g_thm_cntx.TotalTheme) - 1) ||
                g_thm_cntx.CurrOrderIndex >= g_thm_cntx.TotalTheme)
            {
                g_thm_cntx.CurrOrderIndex = 0;
            }
            else
            {
                g_thm_cntx.CurrOrderIndex++;
            }

            /* There's no theme to updated */
            if (g_thm_cntx.CurrOrderIndex == start_index && no_of_times != 0)
            {
                MMI_THM_TRACE0(MMI_THEME_UPDATE_NO_THEME);
                *period = ALM_WITHOUD_EXPIRY_PERIOD;
                #ifndef __MMI_DEV_NEW_SLIM__
                 return ALM_HAS_NO_IND;
                #else
                 return MMI_FALSE;
                #endif
            }

            order_theme_id = g_thm_cntx.SetOrderIDList[g_thm_cntx.CurrOrderIndex];

            /* if current order theme is "none" */
            if (order_theme_id != 0)
            {
                break;
            }
        }

        /* Update theme */
        if (!AlmIsRTCPwron())
        {
            MMI_THM_TRACE1(MMI_THEME_UPDATE_CALLBACK_PATH, 3);
            if (g_thm_cntx.IsInThmApp == 0) /* is not in theme menu */
            {
                /* To exit previous screen, error case: multimedia screen will allocate lots of memory, and then the cache wallpaper will fail */
                /* 2006/12/31 */
                EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
                result = mmi_tm_activate_theme(order_theme_id); /* PMT TM Coding Conventions - MOHD SHARIQ 20060406 */

                if (result == THEME_ERROR_SUCCESS)
                {
                    MMI_THM_TRACE1(MMI_THEME_UPDATE_CALLBACK_PATH, 4);
                    g_thm_cntx.CurrTheme = order_theme_id;
                    SetThemes((U8)g_thm_cntx.CurrTheme);

					//mmi_display_popup((UI_string_type)GetString(STR_THEMES_ALARM_ACTIVATION), MMI_EVENT_INFO);
					mmi_frm_nmgr_popup(
                					MMI_SCENARIO_ID_REMINDER_OTHER, 
                					MMI_EVENT_INFO, 
                					get_string(STR_THEMES_ALARM_ACTIVATION));                    
                    SetCurrOrderIndex(g_thm_cntx.CurrOrderIndex);
                }
                else
                {
                	if (result == THEME_ERROR_ALREADY_ACTIVATED)
            		{
            		    MMI_THM_TRACE1(MMI_THEME_UPDATE_CALLBACK_PATH, 5);
            			//mmi_display_popup((UI_string_type)GetString(STR_THEMES_ALARM_ACTIVATION), MMI_EVENT_INFO);
                        mmi_frm_nmgr_popup(
                                        MMI_SCENARIO_ID_REMINDER_OTHER, 
                                        MMI_EVENT_INFO, 
                                        get_string(STR_THEMES_ALARM_ACTIVATION));
            		}
					else
					{
					    MMI_THM_TRACE1(MMI_THEME_UPDATE_CALLBACK_PATH, 6);
						mmi_thm_display_error_msg(result, GRP_ID_ROOT);
					}
                    
                    SetCurrOrderIndex(g_thm_cntx.CurrOrderIndex);
                }
            }
        }
        else
        {
            MMI_THM_TRACE1(MMI_THEME_UPDATE_CALLBACK_PATH, 7);
            result = mmi_tm_activate_theme(order_theme_id);

            /* PMT SUKRIT START PMTSW00006364 */
            if (result == THEME_ERROR_SUCCESS)
            {
                MMI_THM_TRACE1(MMI_THEME_UPDATE_CALLBACK_PATH, 8);
                g_thm_cntx.CurrTheme = order_theme_id;
                /* PMT SUKRIT END PMTSW00006364 */
                SetThemes((U8)g_thm_cntx.CurrTheme);
                SetCurrOrderIndex(g_thm_cntx.CurrOrderIndex);
                /* PMT SUKRIT START PMTSW00006364 */
            }
            /* PMT SUKRIT END PMTSW00006364 */
        }

	//PMT DNLD FIXES 20060513: SUKRIT START MAUI_00192671
	#ifdef __J2ME__
		if(IsJavaPlaying == TRUE)
		{
			if(result != THEME_ERROR_SUCCESS)
			{
                MMI_THM_TRACE1(MMI_THEME_UPDATE_CALLBACK_PATH, 9);
                jam_resume_dummy_screen();
			}
		}
	#endif
	//PMT DNLD FIXES 20060513: SUKRIT START MAUI_00192671
	}

    /* Leo add for DLT */
    WriteThemesToNVRAM();
    /* Leo end */
#else /* __MMI_THEMES_V2_SUPPORT__ */ 

    U8 no_of_times;
    U8 order_theme = 0;

	/* check the theme in the orderlist , if all are empty, update the period*/
	if (g_thm_cntx.CurrOrderList[0] == 3 &&
		g_thm_cntx.CurrOrderList[1] == 3 &&
		g_thm_cntx.CurrOrderList[2] == 3 &&
		g_thm_cntx.CurrOrderList[3] == 3)
	{
		AlarmExpireUpdateThemeOff();
	}
	else
	{
	    /* find the next index of theme to be updated */
	    for (no_of_times = 0; no_of_times < g_thm_cntx.TotalTheme; no_of_times++)
	    {
	        /* move order to next one */
	        if (g_thm_cntx.CurrOrderIndex == NO_OF_ORDERS - 1)
	        {
	            g_thm_cntx.CurrOrderIndex = 0;
	        }
	        else
	        {
	            g_thm_cntx.CurrOrderIndex++;
	        }

	        order_theme = g_thm_cntx.CurrOrderList[g_thm_cntx.CurrOrderIndex];

	        /* if found theme different to current one, found the first one */
	        if (order_theme != g_thm_cntx.CurrTheme && order_theme < g_thm_cntx.TotalTheme)
	        {
	            break;
	        }
	    }
#ifdef __J2ME__
	    if (GetActiveScreenId() == SCR_JAVA_APP)
	    {
	        IsJavaPlaying = TRUE;
        jam_pause_dummy_screen();
	    }
#endif /* __J2ME__ */ 
	    if (no_of_times < NO_OF_ORDERS)
	    {
	        g_thm_cntx.CurrTheme = order_theme;
	        WriteThemesToNVRAM();

	        if (!AlmIsRTCPwron())
	        {
	            if (g_thm_cntx.IsInThmApp == 0) /* is not in theme menu */
	            {
	                SetThemes((U8)g_thm_cntx.CurrTheme);
					//mmi_display_popup((UI_string_type)GetString(STR_THEMES_ALARM_ACTIVATION), MMI_EVENT_INFO);					
                    mmi_frm_nmgr_popup(
                                    MMI_SCENARIO_ID_REMINDER_OTHER, 
                                    MMI_EVENT_INFO, 
                                    get_string(STR_THEMES_ALARM_ACTIVATION));
 	            }
	            else if (g_thm_cntx.IsInThmApp == 1)
	            {
					//mmi_display_popup((UI_string_type)GetString(STR_THEMES_ALARM_ACTIVATION), MMI_EVENT_INFO);                
                    mmi_frm_nmgr_popup(
                                    MMI_SCENARIO_ID_REMINDER_OTHER, 
                                    MMI_EVENT_INFO, 
                                    get_string(STR_THEMES_ALARM_ACTIVATION));					
 	            }
	            order_theme++;
	        }
	        else
	        {
	            SetThemes((U8)g_thm_cntx.CurrTheme);
	        }
	    }
#ifdef __J2ME__
	    if (IsJavaPlaying == TRUE)
	    {
        jam_resume_dummy_screen();
	    }
#endif /* __J2ME__ */ 
	}
	WriteThemesToNVRAM();
	
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 
    /* Leo add for DLT */
    /* WriteThemesToNVRAM(); */
    /* Leo end */
    *period = ALM_WITHOUD_EXPIRY_PERIOD;
    
    srv_reminder_notify_finish(MMI_FALSE);
    ThemesReInitQueueCBH();
    #ifndef __MMI_DEV_NEW_SLIM__
    return ALM_HAS_NO_IND;
    #else
    return MMI_FALSE;
    #endif
}


#ifndef __MMI_THEMES_V2_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  ReadThemesFromNVRAM
 * DESCRIPTION
 *  Read theme settings from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ReadThemesFromNVRAM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Leo add for DLT */
    S16 error = 0;
    U8 index = 0;
    U8 *temp_name;
    thm_nvram_struct nvram_theme;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* initialize global contex */
    MMI_THM_TRACE0(MMI_THEME_ENTRY_READ_FROM_NVRAM);
    memset(&g_thm_cntx, 0, sizeof(g_thm_cntx));
    g_thm_cntx.TotalTheme = (U8) GetThemesNames((U8 ***) & temp_name);

    ReadRecord(NVRAM_EF_THEMES_VALUES, 1, &nvram_theme, 8, &error);

    /* to present abonromal case of NVRAM default value */
    if (nvram_theme.freq_type > ALM_FREQ_SEASONALLY)
    {
        g_thm_cntx.CurrUpdatePeriod = ALM_FREQ_OFF;
    }
    else
    {
        g_thm_cntx.CurrUpdatePeriod = (U8) (nvram_theme.freq_type);
    }

    g_thm_cntx.CurrTheme = nvram_theme.current_theme_index;

    /* set order list */
    if (nvram_theme.set_order_flag >= -1)    /* order has be set before */
    {
        g_thm_cntx.IsOrderChanged = 1;

        g_thm_cntx.CurrOrderIndex = nvram_theme.set_order_flag;

        for (index = 0; index < NO_OF_ORDERS; index++)
        {
            g_thm_cntx.CurrOrderList[index] = nvram_theme.themes_order[index];
        }
    }
    else
    {
        g_thm_cntx.IsOrderChanged = 0;
        g_thm_cntx.CurrOrderIndex = 0;
        for (index = 0; index < NO_OF_ORDERS; index++)
        {
            g_thm_cntx.CurrOrderList[index] = index;
        }
    }

    /* set and apply current theme */
    if (g_thm_cntx.CurrTheme >= g_thm_cntx.TotalTheme)
    {
        g_thm_cntx.CurrOrderIndex = 0;
        g_thm_cntx.CurrTheme = 0;
    }

    SetThemes((U8)g_thm_cntx.CurrTheme);
    /* Leo end */
}
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  WriteThemesToNVRAM
 * DESCRIPTION
 *  write theme settings to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void WriteThemesToNVRAM()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;
    S16 error = 0;
    thm_nvram_struct nvram_theme;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_THM_TRACE0(MMI_THEME_ENTRY_WRITE_FROM_NVRAM);
    
    nvram_theme.freq_type = g_thm_cntx.CurrUpdatePeriod;

    if (g_thm_cntx.IsOrderChanged == 1)
#ifdef __MMI_THEMES_V2_SUPPORT__
        nvram_theme.set_order_flag = currorderindex;    /* changes made on saturday 09/04/05 */
#else 
        nvram_theme.set_order_flag = g_thm_cntx.CurrOrderIndex;
#endif 

    if (g_thm_cntx.IsOrderChanged == 0)
    {
        nvram_theme.set_order_flag = -1;
    }

#ifndef __MMI_THEMES_V2_SUPPORT__
    if (g_thm_cntx.CurrTheme < g_thm_cntx.TotalTheme)
    {
        nvram_theme.current_theme_index = (U8) g_thm_cntx.CurrTheme;
    }
    else
    {
        g_thm_cntx.CurrTheme = nvram_theme.current_theme_index = 0;
    }
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 

#ifdef __MMI_THEMES_V2_SUPPORT__
    for (index = 0; index < TOTAL_THEMES_COUNT; index++)    /* ritesh */
    {
        nvram_theme.themes_order[index] = setorderIDList[index];
    }
#else /* __MMI_THEMES_V2_SUPPORT__ */ 
    for (index = 0; index < NO_OF_ORDERS; index++)
    {
        nvram_theme.themes_order[index] = g_thm_cntx.CurrOrderList[index];
    }
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 

#if (defined(__MMI_THEMES_V2_SUPPORT__) || defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__))        /* ritesh */
    WriteRecord(NVRAM_EF_THEMES_VALUES, 1, &nvram_theme, sizeof(thm_nvram_struct), &error);
#else 
    WriteRecord(NVRAM_EF_THEMES_VALUES, 1, &nvram_theme, sizeof(thm_nvram_struct), &error);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  UpdateThemeAlarm
 * DESCRIPTION
 *  Call by settings application when time/date change
 *  and set the alam of update theme according to current time/date
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UpdateThemeAlarm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_thm_cntx.IsSetFromMenu = 0;

    if (g_themes_freq_set[g_thm_cntx.CurrUpdatePeriod] != ALM_FREQ_OFF) /* not OFF */
    {
        UpdateThemePeriod();
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetStartPositionofCurIndex
 * DESCRIPTION
 *  set the starting position of update order index
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetStartPositionofCurIndex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0, flag = 0;
    U8 curr_order;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    if (g_thm_cntx.CurrOrderIndex < 0 || g_thm_cntx.CurrOrderIndex >= TOTAL_THEMES_COUNT)
#else 
    if (g_thm_cntx.CurrOrderIndex < 0)
#endif 
        curr_order = 0;
    else
    {
        curr_order = (U8) g_thm_cntx.CurrOrderIndex;
    }

    /* find the position of current selected theme */
#ifdef __MMI_THEMES_V2_SUPPORT__
    for (index = 0; index < g_thm_cntx.TotalTheme; index++) /* ritesh */
    {
        if (g_thm_cntx.SetOrderIDList[curr_order] == g_thm_cntx.CurrTheme)
        {
            flag = 1;
            break;
        }
        if (curr_order == (g_thm_cntx.TotalTheme) - 1)
        {
            curr_order = 0;
        }
        else
        {
            curr_order++;
        }
    }
#else /* __MMI_THEMES_V2_SUPPORT__ */ 
    for (index = 0; index < NO_OF_ORDERS; index++)
    {
        if (g_thm_cntx.CurrOrderList[curr_order] == g_thm_cntx.CurrTheme)
        {
            flag = 1;
            break;
        }

        if (curr_order == (NO_OF_ORDERS) - 1)
        {
            curr_order = 0;
        }
        else
        {
            curr_order++;
        }
    }
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 
    if (flag == 1)  /* it's in the list */
    {
        g_thm_cntx.CurrOrderIndex = curr_order;
        g_thm_cntx.IsOrderChanged = 1;
    }
    else
    {
        g_thm_cntx.CurrOrderIndex = -1;
    }

}


/*****************************************************************************
 * FUNCTION
 *  ATSetTheme
 * DESCRIPTION
 *  To change theme setting from AT command
 * PARAMETERS
 *  index       [IN]        Index of theme to be set
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __MMI_PHNSET_AT_DISABLE__
BOOL ATSetTheme(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* added by ritesh for V2 support */
#ifdef __MMI_THEMES_V2_SUPPORT__
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_thm_cntx.IsInThmApp == 0)
    {
        mmi_tm_get_themes(&thm_details);
        result = mmi_tm_activate_theme(thm_details[index].theme_id);    /* PMT TM Coding Conventions - MOHD SHARIQ 20060406 */
        SetThemes((U8)g_thm_cntx.CurrTheme);

        if (result == THEME_ERROR_SUCCESS)
        {
            g_thm_cntx.CurrTheme = thm_details[index].theme_id;
            if (g_themes_freq_set[g_thm_cntx.CurrUpdatePeriod] != ALM_FREQ_OFF)
            {
                SetStartPositionofCurIndex();
            }
            SetCurrOrderIndex(g_thm_cntx.CurrOrderIndex);
        }
        mmi_thm_display_error_msg(result, GRP_ID_ROOT);
        DeleteUptoScrID(SCR_ID_THM_MENU);

        if ((result == THEME_ERROR_SUCCESS) || (result == THEME_ERROR_ALREADY_ACTIVATED))
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    }
    else
    {
        return MMI_FALSE;
    }
#else /* __MMI_THEMES_V2_SUPPORT__ */ 
    /* index exceeds boundary or theme is not changed */
    if (index >= g_thm_cntx.TotalTheme || index == g_thm_cntx.CurrTheme)
    {
        return MMI_FALSE;
    }

    g_thm_cntx.CurrTheme = index;

    /* reset postion index of update period */
    if (g_themes_freq_set[g_thm_cntx.CurrUpdatePeriod] != ALM_FREQ_OFF)
    {
        SetStartPositionofCurIndex();
    }

    /* write change to NVRAM */
    WriteThemesToNVRAM();

    /* change theme */
    if (g_thm_cntx.IsInThmApp == 0) /* is not in theme menu */
    {
        SetBothLCDThemes(index);
        /* MTK Leo add, fix theme update issue */
        EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
        GoBackHistory();
    }
    else if (g_thm_cntx.IsInThmApp == 1)
    {
        /* SetExitHandler(SCR_ID_THM_MENU, NULL); */
        ClearExitHandler();
        mmi_theme_entry_int();
    }

    return MMI_TRUE;
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 
}
#endif
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  SetOrderIDList
 * DESCRIPTION
 *  To construct set order ID list
 * PARAMETERS
 *  IDList              [?]         
 *  SetNoOfThemes       [IN]        
 *  index               [IN]        Of the activated theme
 *  three:(?)
 *  pointer to array of ID list(?)
 *  total no of themes in set order list(?)
 * RETURNS
 *  void
 *****************************************************************************/
void SetOrderIDList(U32 IDList[], U8 SetNoOfThemes, S16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_thm_cntx.TotalTheme; i++)
    {
        setorderIDList[i] = IDList[i];
    }
    currorderindex = index;
    WriteThemesToNVRAM();
}


/*****************************************************************************
 * FUNCTION
 *  GetIDList
 * DESCRIPTION
 *  function to get set order ID List
 * PARAMETERS
 *  plist       [IN]        
 *  index           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
U8 GetIDList(U32 **plist, S16 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count = CheckForCorrectOrder();
    MMI_THM_TRACE1(MMI_THEME_GET_ID, count);
    
    if (count == 0)
    {
        currorderindex = -1;
    }
    *plist = setorderIDList;
    *index = currorderindex;
    WriteThemesToNVRAM();
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  CheckForCorrectOrder
 * DESCRIPTION
 *  function to check for correct order in set order list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 CheckForCorrectOrder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j = 0, set_flag = 0;
    U8 count = 0, totaltheme;
    S32 tempIDList[TOTAL_THEMES_COUNT];
	U16 actual_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_THM_TRACE0(MMI_THEME_CHECK_FOR_ORDER);
    totaltheme = mmi_tm_get_themes(&thm_details);

    ConstructThemeOrderList();

    for (i = 0; i < TOTAL_THEMES_COUNT; i++)
    {
        while (j != totaltheme)
        {

            if (setorderIDList[i] == 0)
            {
                tempIDList[i] = setorderIDList[i];
                set_flag = 1;
				actual_count++;
                break;
            }
            if (setorderIDList[i] == thm_details[j].theme_id)
            {
                tempIDList[i] = setorderIDList[i];
                count++;
				actual_count++;
                set_flag = 1;
                break;
            }
            j++;
        }
        if (set_flag == 0)
        {

            tempIDList[i] = -1;
            if (currorderindex >= i)
            {
                currorderindex--;
            }
        }
        set_flag = 0;
        j = 0;
    }

    for (i = 0; i < TOTAL_THEMES_COUNT; i++)
    {
        if (tempIDList[i] != -1)
        {
            setorderIDList[set_flag++] = tempIDList[i];
        }
    }

	for (i = actual_count; i < TOTAL_THEMES_COUNT; i++)
    {
        setorderIDList[i] = -1;
    }
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  SetCurrOrderIndex
 * DESCRIPTION
 *  function to set current order index
 * PARAMETERS
 *  index       [IN]        Of current theme in set order list
 * RETURNS
 *  void
 *****************************************************************************/
void SetCurrOrderIndex(S16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currorderindex = index;
    WriteThemesToNVRAM();
}


/*****************************************************************************
 * FUNCTION
 *  dmmi_thm_display_error_msg
 * DESCRIPTION
 *  Display error msg of theme operation
 * PARAMETERS
 *  thm_del_ID      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_thm_display_error_msg(S32 error_type, mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 str_id = STR_GLOBAL_ACTIVATED;
	mmi_event_notify_enum evt_id = MMI_EVENT_FAILURE;;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (error_type < 0)
    {
    	str_id = (U16)srv_fmgr_fs_error_get_string(error_type);
	    evt_id = (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(error_type);
    }
    else
    {
        switch (error_type)
        {
            case THEME_ERROR_SUCCESS:
				str_id = STR_GLOBAL_ACTIVATED;
				evt_id = MMI_EVENT_SUCCESS;
                break;
					
            case THEME_ERROR_ALREADY_ACTIVATED:
				str_id = STR_GLOBAL_ACTIVATED;
				evt_id = MMI_EVENT_SUCCESS;
                break;
				
            case THEME_ERROR_SPACE_NOT_AVAILABLE:
				str_id = STR_ID_FMGR_SPACE_NOT_AVAILABLE;
                break;
			
            case THEME_ERROR_THEME_NOT_AVAILABLE:
				str_id = STR_THEME_NOT_AVAILABLE;
                break;
				
            case THEME_ERROR_FILE_FORMAT_BAD:
				str_id = STR_THEME_FORMAT_NOT_SUPPORTED;
                break;
				
            case THEME_ERROR_FAILURE:
				str_id = STR_THEME_UNKNOWN_ERROR;
                break;
				
            case THEME_ERROR_MAX_COUNT_REACHED:
				str_id = STR_ID_FMGR_MAX_COUNT_REACHED;
                break;
			
            case THEME_ERROR_VERSION_FAILURE:
				str_id = STR_DOWNLOAD_THEME_UNSUPPORTED;
	                break;
				
            case THEME_ERROR_PROCESS_QUEUE_SUCESS:
				str_id = 0;
				evt_id = MMI_EVENT_PROGRESS;
                break;
				
                /* PMT DNLD_THEME_FIXES: SHARIQ START BUG# MAUI_00192708 */
            case THEME_ERROR_LCD_SIZE_MISMATCH:
				str_id = STR_LCD_SIZE_MISMATCH;
                break;
                //PMT DNLD_THEME_FIXES: SHARIQ END BUG# MAUI_00192708
                //PMT DNLD FIXES 20060513: SUKRIT START MAUI_00221313
            case THEME_ERROR_FILENAME_INCORRECT:
				str_id = STR_THEME_ERROR_FILENAME_INCORRECT;
                break;
				
                /* PMT DNLD FIXES 20060513: SUKRIT END MAUI_00221313 */
            case THEME_ERROR_PHONE_MODEL_MISMATCH:
				str_id = STR_THEME_ERROR_PHONE_MODEL_MISMATCH;
	            break;	
        #ifdef __USB_IN_NORMAL_MODE__
            case THEME_ERROR_USB_MODE_ON:
				str_id = STR_GLOBAL_NOT_AVAILABLE_IN_MASS_STORAGE_MODE;
				evt_id = MMI_EVENT_FAILURE;
                break;
        #endif
            default:
				str_id = STR_THEME_UNKNOWN_ERROR;
				evt_id = MMI_EVENT_FAILURE;
                break;
                /* break; */
        }
    }

    if (GRP_ID_ROOT == parent_id)
    {
        mmi_frm_group_create_ex(
                        GRP_ID_ROOT,
                        GRP_ID_THM_MAIN,
                        mmi_dummy_proc,
                        NULL,
                        MMI_FRM_NODE_SMART_CLOSE_FLAG);
        parent_id = GRP_ID_THM_MAIN;
    }
    mmi_popup_display_simple_ext(str_id, evt_id, parent_id, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_thm_activate_dflt_theme
 * DESCRIPTION
 *  activate the default system 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_thm_activate_dflt_sys_theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 themetype = mmi_tm_get_curr_theme_type();
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (themetype == THEME_TYPE_DOWNLOADED_PHONE)  
    {
        ActivateDefaultTheme();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_thm_activate_update_thm_order
 * DESCRIPTION
 *  activate the default system 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_thm_activate_update_thm_order(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
		
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
		
    g_thm_cntx.CurrTheme = (U8)mmi_tm_get_current_theme_id();
    g_thm_cntx.CurrThemeIndex = g_temp_thm_index;
    SetThemes((U8)g_thm_cntx.CurrTheme);
    if (g_themes_freq_set[g_thm_cntx.CurrUpdatePeriod] != ALM_FREQ_OFF)
    {
        SetStartPositionofCurIndex();
    }
    SetCurrOrderIndex(g_thm_cntx.CurrOrderIndex);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_delete_theme
 * DESCRIPTION
 *  This function deletes the theme with the corresponding theme id
 * PARAMETERS
 *  theme_id        [IN]        
 *  error_type      [IN]        
 * RETURNS
 *  theme error code
 *****************************************************************************/
S32 mmi_tm_delete_theme(THEME_ID theme_id, PS32 error_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, found = 0;
    S16 err;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_TM_DELETE_THEME, theme_id);

    for (i = g_theme_cntx.sys_thm_cnt; i < g_theme_cntx.total_thm_cnt; ++i)
    {
        if (g_tm_theme_list[i].theme_id == theme_id)
        {
            found = 1;
            break;
        }
    }

    if (!found)
    {
        return THEME_ERROR_THEME_NOT_AVAILABLE;
    }
    else
    {
        U8 tmp_file_name[50];
        U8 file_name[100];

        sprintf((CHAR*) tmp_file_name, "%c%s", g_tm_theme_list[i].drv_letter, DOWNLOADED_THEMES_PATH);
        mmi_asc_to_ucs2((CHAR*) file_name, (CHAR*) tmp_file_name);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

        mmi_ucs2cat((CHAR*) file_name, (CHAR*) g_tm_theme_list[i].theme_name);

        if ((*error_type = FS_Delete((U16*) file_name)) == FS_NO_ERROR)
        {
            for (; i < g_theme_cntx.total_thm_cnt - 1; ++i)
            {
                memcpy((void*)&g_tm_theme_list[i], (void*)&g_tm_theme_list[i + 1], sizeof(tm_theme_list_struct));
            }
            memset((void*)&g_tm_theme_list[g_theme_cntx.total_thm_cnt - 1], 0, sizeof(tm_theme_list_struct));
            WriteRecord(
                NVRAM_EF_THEME_MANAGER_LID,
                1,
                (void*)(g_tm_theme_list + g_theme_cntx.sys_thm_cnt),
                NVRAM_EF_THEME_MANAGER_RECORD_SIZE,
                &err);
            --g_theme_cntx.total_thm_cnt;

            return THEME_ERROR_SUCCESS;
        }
        else
        {
            return THEME_ERROR_FAILURE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_get_themes
 * DESCRIPTION
 *  1. Purge the theme list of any non-existant themes
 *  2. Add any new themes if available.
 * PARAMETERS
 *  theme_list_p        [IN]        
 * RETURNS
 *  total number of themes
 *****************************************************************************/
static U8 mmi_tm_get_themes(tm_theme_list_struct **theme_list_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 dwnl_ph_thm_cnt = 0;
    S32 dwnl_card_thm_cnt = 0;
    S32 nvm_card_thm_cnt = 0;
    tm_theme_list_struct *tmp_theme_list_p;

    U8 h, i, j, k, len;
    S16 err;
    U32 max_theme_id;
    U64 buff;
    U8 *temp_name;
    U8 nSystemThemeCount;
    S16 error_code;

    CHAR tmp_str[MAX_DWNL_THM_PATH_LEN + MAX_THEME_SEARCH_STR_LEN];
    U16 theme_path[MAX_DWNL_THM_PATH_LEN + MAX_THEME_SEARCH_STR_LEN + MAX_THEME_NAME_LENGTH + 1];
    U16 theme_path_phone[MAX_DWNL_THM_PATH_LEN];    /* Plus 2 for SRV_FMGR_PUBLIC_DRV: check */
    U16 theme_path_card[MAX_DWNL_THM_PATH_LEN];     /* Plus 2 for SRV_FMGR_CARD_DRV: check */
    U16 theme_search_path[MAX_DWNL_THM_PATH_LEN + MAX_THEME_SEARCH_STR_LEN];

    U8 theme_type_bitmap[MAX_DOWNLOADED_THEMES] = {0};
    FS_HANDLE fh_cur;
    FS_DOSDirEntry file_info;
    U16 filename[MAX_THEME_NAME_LENGTH + 1];
    U16 *file_name_p;
    U8 theme_already_on_nvram_list = MMI_FALSE;
    /* OTG support */
    U8 drv_list[SRV_FMGR_DRV_TOTAL];
    S32 drv_count;
    S32 drv_enum;
    CHAR* theme_name_ptr;
    SRV_FMGR_DRVLIST_HANDLE fmgr_drv_handle;	
    CHAR *p_ext;


	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nSystemThemeCount = (U8) GetThemesNames((U8 ***) & temp_name);
    if (nSystemThemeCount > MAX_SYSTEM_THEMES)
    {
        nSystemThemeCount = MAX_SYSTEM_THEMES;
    }

    MMI_THM_TRACE0(MMI_THEME_ENTRY_GET_THEMES);
    memset((void*)g_tm_theme_list, 0, sizeof(tm_theme_list_struct) * TOTAL_THEMES_COUNT);
    g_theme_cntx.total_thm_cnt = 0;
    g_theme_cntx.sys_thm_cnt = 0;

    for (j = 0; j < nSystemThemeCount; ++j)
    {
        mmi_ucs2ncpy(
            (CHAR*) g_tm_theme_list[j].theme_name,
            GetString((U16) (STR_THEME_DEFAULT + j)),
            MAX_THEME_NAME_LENGTH);
        g_tm_theme_list[j].theme_checksum_verified = CHECKSUM_VERIFIED_OK;
        g_tm_theme_list[j].theme_id = j + 1;
        g_tm_theme_list[j].theme_type = THEME_TYPE_SYSTEM;
    }

    g_theme_cntx.total_thm_cnt = g_theme_cntx.sys_thm_cnt = nSystemThemeCount;

    /* Read Themes from NVRAM */
    ReadRecord(
        NVRAM_EF_THEME_MANAGER_LID,
        1,
        (void*)(g_tm_theme_list + g_theme_cntx.sys_thm_cnt),
        NVRAM_EF_THEME_MANAGER_RECORD_SIZE,
        &err);
    /* err = 1 => NVRAM_READ_SUCCESS */
    if (err != NVRAM_READ_SUCCESS)
    {
        *theme_list_p = g_tm_theme_list;
        return g_theme_cntx.total_thm_cnt;
    }

    /* Sukrit: A better way to do it will be through something like does file exists on phone folder */
    sprintf(tmp_str, "%c%s", SRV_FMGR_PUBLIC_DRV, DOWNLOADED_THEMES_PATH);
    mmi_asc_to_ucs2((CHAR*) theme_path_phone, tmp_str);
    dwnl_ph_thm_cnt = FS_Count(theme_path_phone, FS_FILE_TYPE, NULL, 0);
    
    /* count all the theme folder */
    //mmi_fmgr_get_exist_drive_letter(drv_list, &drv_count);
    fmgr_drv_handle = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE);
    drv_count = srv_fmgr_drivelist_count(fmgr_drv_handle);
    for (j = 0; j < drv_count; j++)
    {
        drv_list[j] = srv_fmgr_drivelist_get_drv_letter(fmgr_drv_handle, j);
    }
    srv_fmgr_drivelist_destroy(fmgr_drv_handle);
    
    for (j = 0; j < drv_count; j++)
    {
        drv_enum = srv_fmgr_drv_get_type((U8)(drv_list[j]));
        
        switch (drv_enum)
        {
            case SRV_FMGR_DRV_PHONE_TYPE:
            case SRV_FMGR_DRV_PHONE_2_TYPE:
                dwnl_ph_thm_cnt = FS_Count(theme_path_phone, FS_FILE_TYPE, NULL, 0);
                break;

            case SRV_FMGR_DRV_CARD_TYPE:
#ifdef __OTG_ENABLE__
            case SRV_FMGR_DRV_OTG_TYPE:
            case SRV_FMGR_DRV_OTG_2_TYPE:
            case SRV_FMGR_DRV_OTG_3_TYPE:
            case SRV_FMGR_DRV_OTG_4_TYPE:
#endif /* __OTG_ENABLE__ */
                sprintf(tmp_str, "%c%s", drv_list[j], DOWNLOADED_THEMES_PATH);
                mmi_asc_to_ucs2((CHAR*) theme_path_card, tmp_str);
                dwnl_card_thm_cnt += FS_Count(theme_path_card, FS_FILE_TYPE, NULL, 0);
                break;
                
            default:
                /* Do nothing here */
                break;
        }
    }

    MMI_THM_TRACE2(MMI_THEME_GET_THEMES_COUNT, dwnl_ph_thm_cnt, dwnl_card_thm_cnt);
    
    ReadValue(THEME_MANAGER_MAX_THEME_ID, (void*)&buff, DS_DOUBLE, &err);
    max_theme_id = (U32) buff;
    if (max_theme_id == 0xFFFFFFFF || err == -1)
    {
        max_theme_id = 10;
        WriteValue(THEME_MANAGER_MAX_THEME_ID, (void*)&max_theme_id, DS_DOUBLE, &err);
    }

    tmp_theme_list_p = (tm_theme_list_struct*) & g_tm_NvramThmArr;

    /*
     * Here the algorithm should be better..
     * For each theme item in g_tm_theme_list, traverse in phone and card.
     * When found the same in phone, add it into tmp_theme_list_p.
     * When found the same in card, nvm_card_thm_cnt add 1, not add into tmp_theme_list_p.
     * Because should check if has enough memory later.
     */
    for (j = g_theme_cntx.sys_thm_cnt, k = 0; j < TOTAL_THEMES_COUNT; ++j)
    {
        if ((g_tm_theme_list[j].theme_type == THEME_TYPE_DOWNLOADED_PHONE))
        {
            mmi_ucs2ncpy((CHAR*) theme_path, (CHAR*) theme_path_phone, MAX_DWNL_THM_PATH_LEN);
            mmi_ucs2ncat((CHAR*) theme_path, (CHAR*) g_tm_theme_list[j].theme_name, MAX_THEME_NAME_LENGTH);
            error_code = FS_GetAttributes(theme_path);
            if (((error_code >= 0) && (error_code != FS_ATTR_DIR)) || (error_code == FS_ACCESS_DENIED))
            {
                memcpy((void*)(tmp_theme_list_p + k), (void*)&g_tm_theme_list[j], sizeof(tm_theme_list_struct));
                theme_type_bitmap[k] = THEME_TYPE_DOWNLOADED_PHONE;
                ++k;
                dwnl_ph_thm_cnt--;
            }
        }
        else if (g_tm_theme_list[j].theme_type == THEME_TYPE_DOWNLOADED_CARD)
        {
            sprintf(tmp_str, "%c%s", g_tm_theme_list[j].drv_letter, DOWNLOADED_THEMES_PATH);
            mmi_asc_to_ucs2((CHAR*) theme_path_card, tmp_str);
            mmi_ucs2ncpy((CHAR*) theme_path, (CHAR*) theme_path_card, MAX_DWNL_THM_PATH_LEN);
            mmi_ucs2ncat((CHAR*) theme_path, (CHAR*) g_tm_theme_list[j].theme_name, MAX_THEME_NAME_LENGTH);
            error_code = FS_GetAttributes(theme_path);
            if (((error_code >= 0) && (error_code != FS_ATTR_DIR)) || (error_code == FS_ACCESS_DENIED))
            {
                nvm_card_thm_cnt++;
                dwnl_card_thm_cnt--;
            }
        }
    }
    
    /* 
     * For each theme item in phone, traverse tmp_theme_list_p.
     * If not found, add it into tmp_theme_list_p.
     */
    MMI_THM_TRACE2(MMI_THEME_AFTER_SEARCH_COUNT, dwnl_ph_thm_cnt, dwnl_card_thm_cnt);
    
    sprintf(tmp_str, "%c%s%s", SRV_FMGR_PUBLIC_DRV, DOWNLOADED_THEMES_PATH, THEME_SEARCH_STR);
    mmi_asc_to_ucs2((CHAR*) theme_search_path, tmp_str);
    if (dwnl_ph_thm_cnt > 0 && k < (MAX_DOWNLOADED_THEMES - nvm_card_thm_cnt))
    {
        if ((fh_cur = FS_FindFirst(
                        (U16*) theme_search_path,
                        0,
                        0,
                        &file_info,
                        (U16*)filename,
                        (MAX_THEME_NAME_LENGTH + 1) * ENCODING_LENGTH)) >= 0)
        {
            do
            {
                sprintf(tmp_str, "%c", *filename);
                MMI_THM_TRACE1(MMI_THEME_SEARCH_PHONE_FILE_NAME, tmp_str[0]);
                theme_already_on_nvram_list = MMI_FALSE;
                file_name_p = (U16*)filename;
                /* Check if theme already in the list */
                for (j = g_theme_cntx.sys_thm_cnt; j < TOTAL_THEMES_COUNT; ++j)
                {
                	theme_name_ptr = (CHAR*)tmp_theme_list_p[j - g_theme_cntx.sys_thm_cnt].theme_name;
                    if (theme_type_bitmap[j - g_theme_cntx.sys_thm_cnt] == THEME_TYPE_DOWNLOADED_PHONE &&
                        mmi_ucs2icmp(
                            (CHAR*) theme_name_ptr,
                            (CHAR*) file_name_p) == 0)
                    {
                        theme_already_on_nvram_list = MMI_TRUE;
						mmi_ucs2cpy((CHAR*) theme_name_ptr, (CHAR*) file_name_p);
                        theme_type_bitmap[j - g_theme_cntx.sys_thm_cnt] = 0xFF;
                        break;
                    }
                }

                if (theme_already_on_nvram_list == MMI_FALSE)
                {
                    memset((void*)&tmp_theme_list_p[k], 0, sizeof(tm_theme_list_struct));
                    mmi_ucs2ncpy((CHAR*)tmp_theme_list_p[k].theme_name, (CHAR*)file_name_p, (MAX_THEME_NAME_LENGTH + 1));
                    tmp_theme_list_p[k].theme_checksum_verified = CHECKSUM_NOT_VERIFIED;
                    tmp_theme_list_p[k].theme_id = ++max_theme_id;
                    tmp_theme_list_p[k].theme_type = THEME_TYPE_DOWNLOADED_PHONE;
                    tmp_theme_list_p[k].drv_letter = SRV_FMGR_PUBLIC_DRV;
                    ++k;
                    dwnl_ph_thm_cnt--;
                }
            } while (k < (MAX_DOWNLOADED_THEMES - nvm_card_thm_cnt) &&
                     (FS_FindNext(fh_cur, &file_info, (U16*)filename, MAX_THEME_NAME_LENGTH * ENCODING_LENGTH) ==
                      FS_NO_ERROR));
            FS_FindClose(fh_cur);
        }
    }

    /*
     * For each theme item in g_tm_theme_list, traverse storage card.
     * When found the same in card, add it into tmp_theme_list_p.
     */
    for (j = g_theme_cntx.sys_thm_cnt; j < TOTAL_THEMES_COUNT; ++j)
    {
        if ((g_tm_theme_list[j].theme_type == THEME_TYPE_DOWNLOADED_CARD))
        {
            mmi_ucs2ncpy((CHAR*) theme_path, (CHAR*) theme_path_card, MAX_DWNL_THM_PATH_LEN);
            mmi_ucs2ncat((CHAR*) theme_path, (CHAR*) g_tm_theme_list[j].theme_name, MAX_THEME_NAME_LENGTH);

            error_code = FS_GetAttributes(theme_path);
            if (((error_code >= 0) && (error_code != FS_ATTR_DIR)) || (error_code == FS_ACCESS_DENIED))
            {
                memcpy((void*)(tmp_theme_list_p + k), (void*)&g_tm_theme_list[j], sizeof(tm_theme_list_struct));
                theme_type_bitmap[k] = THEME_TYPE_DOWNLOADED_CARD;
                ++k;
            }
        }
    }
    
    /* 
     * For each theme item in storage card, traverse tmp_theme_list_p.
     * If not found, add it into tmp_theme_list_p.
     */     
    MMI_THM_TRACE2(MMI_THEME_AFTER_SEARCH_PHONE_COUNT, dwnl_ph_thm_cnt, dwnl_card_thm_cnt);
    
    for (i = 0; i < drv_count; i++)
    {
        drv_enum = srv_fmgr_drv_get_type((U8)(drv_list[i]));
        if (drv_enum != SRV_FMGR_DRV_CARD_TYPE
#ifdef __OTG_ENABLE__
            && drv_enum != SRV_FMGR_DRV_OTG_TYPE
            && drv_enum != SRV_FMGR_DRV_OTG_2_TYPE
            && drv_enum != SRV_FMGR_DRV_OTG_3_TYPE
            && drv_enum != SRV_FMGR_DRV_OTG_4_TYPE
#endif /* __OTG_ENABLE__ */
            )
        {
            continue;
        }
        /* Insert new Card themes in NVRAM list */
        sprintf(tmp_str, "%c%s%s", drv_list[i], DOWNLOADED_THEMES_PATH, THEME_SEARCH_STR);
        mmi_asc_to_ucs2((CHAR*) theme_search_path, tmp_str);

        if (dwnl_card_thm_cnt > 0 && k < MAX_DOWNLOADED_THEMES)
        {
            if ((fh_cur = FS_FindFirst(
                            (U16*) theme_search_path,
                            0,
                            0,
                            &file_info,
                            (U16*)filename,
                            (MAX_THEME_NAME_LENGTH + 1) * ENCODING_LENGTH)) >= 0)
            {
                do
                {
                    sprintf(tmp_str, "%c", *filename);
                    MMI_THM_TRACE1(MMI_THEME_SEARCH_CARD_FILE_NAME, tmp_str[0]);                    
                    theme_already_on_nvram_list = MMI_FALSE;
                    file_name_p = (U16*)filename;
                    /* Check if theme already in the list */
                    for (j = g_theme_cntx.sys_thm_cnt; j < TOTAL_THEMES_COUNT; ++j)
                    {
                    	theme_name_ptr = (CHAR*)tmp_theme_list_p[j - g_theme_cntx.sys_thm_cnt].theme_name;
                        if (theme_type_bitmap[j - g_theme_cntx.sys_thm_cnt] == THEME_TYPE_DOWNLOADED_CARD &&
                            mmi_ucs2icmp(
                                (CHAR*)theme_name_ptr,
                                (CHAR*)file_name_p) == 0)
                        {
                            theme_already_on_nvram_list = MMI_TRUE;
							mmi_ucs2cpy((CHAR*) theme_name_ptr, (CHAR*) file_name_p);
                            theme_type_bitmap[j - g_theme_cntx.sys_thm_cnt] = 0xFF;
                            break;
                        }
                    }

                    if (theme_already_on_nvram_list == MMI_FALSE)
                    {
                        memset((void*)&tmp_theme_list_p[k], 0, sizeof(tm_theme_list_struct));
                        mmi_ucs2ncpy((CHAR*) tmp_theme_list_p[k].theme_name, (CHAR*)file_name_p, (MAX_THEME_NAME_LENGTH + 1));
                        tmp_theme_list_p[k].theme_checksum_verified = CHECKSUM_NOT_VERIFIED;
                        tmp_theme_list_p[k].theme_id = ++max_theme_id;
                        tmp_theme_list_p[k].theme_type = THEME_TYPE_DOWNLOADED_CARD;
                        tmp_theme_list_p[k].drv_letter = drv_list[i];
                        dwnl_card_thm_cnt--;
                        ++k;
                    }

                } while (k < MAX_DOWNLOADED_THEMES &&
                         (FS_FindNext(fh_cur, &file_info, (U16*)filename, MAX_THEME_NAME_LENGTH * ENCODING_LENGTH) ==
                          FS_NO_ERROR));
                FS_FindClose(fh_cur);

            }
        }
    }

    MMI_THM_TRACE2(MMI_THEME_AFTER_SEARCH_CARD_COUNT, dwnl_ph_thm_cnt, dwnl_card_thm_cnt);
    for (i = 0; i < k;)
    {
        p_ext = mmi_ucs2str((CHAR*)tmp_theme_list_p[i].theme_name, (CHAR*)L".");
        p_ext += ENCODING_LENGTH;
        len = mmi_ucs2strlen(p_ext);
        if (mmi_ucs2nicmp(p_ext, (CHAR*)L"med", 3) || (3 != len))
        {
            memset(&tmp_theme_list_p[i], 0, sizeof(tm_theme_list_struct));            
            for (j = i + 1, h = i; j < k; j++, h++)
            {
                memcpy(&tmp_theme_list_p[h], &tmp_theme_list_p[j], sizeof(tm_theme_list_struct));
            }
            k--;
        }
        else
        {
            i++;
        }
    }
    g_theme_cntx.total_thm_cnt = g_theme_cntx.sys_thm_cnt + k;

    memset((void*)(g_tm_theme_list + g_theme_cntx.sys_thm_cnt), 0, sizeof(tm_theme_list_struct) * MAX_DOWNLOADED_THEMES);
    memcpy((void*)(g_tm_theme_list + g_theme_cntx.sys_thm_cnt), tmp_theme_list_p, sizeof(tm_theme_list_struct) * k);

    /* Write Themes back to NVRAM */
    WriteRecord(
        NVRAM_EF_THEME_MANAGER_LID,
        1,
        (void*)(g_tm_theme_list + g_theme_cntx.sys_thm_cnt),
        NVRAM_EF_THEME_MANAGER_RECORD_SIZE,
        &err);
    /* err = 4 => NVRAM_WRITE_SUCCESS */
    WriteValue(THEME_MANAGER_MAX_THEME_ID, (void*)&max_theme_id, DS_DOUBLE, &err);

    *theme_list_p = g_tm_theme_list;
    return g_theme_cntx.total_thm_cnt;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_get_total_themes_count
 * DESCRIPTION
 *  It gets the total no. of the themes
 * PARAMETERS
 *  void
 * RETURNS
 *  total number of themes
 *****************************************************************************/
static U8 mmi_tm_get_total_themes_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_theme_cntx.total_thm_cnt;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_get_current_theme_id
 * DESCRIPTION
 *  This function gets the current theme ID
 * PARAMETERS
 *  void
 * RETURNS
 *  numeric theme id value
 *****************************************************************************/
U32 mmi_tm_get_current_theme_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 err;
    U64 buff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(THEME_MANAGER_CURR_THEME_ID, (void*)&buff, DS_DOUBLE, &err);
    g_theme_cntx.curr_activated_theme_id = (U32) buff;
    if (g_theme_cntx.curr_activated_theme_id == 0xFFFFFFFF || err == -1)
    {
        g_theme_cntx.curr_activated_theme_id = 1;
        MMI_THM_TRACE1(MMI_THEME_GET_CURR_THEME_ID, g_theme_cntx.curr_activated_theme_id);
        WriteValue(THEME_MANAGER_CURR_THEME_ID, (void*)&g_theme_cntx.curr_activated_theme_id, DS_DOUBLE, &err);
    }

    MMI_THM_TRACE1(MMI_THEME_GET_CURR_THEME_ID, g_theme_cntx.curr_activated_theme_id);
    return g_theme_cntx.curr_activated_theme_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_handle_theme_activation_error_status
 * DESCRIPTION
 *  This function handles error status at the time of theme activation
 * PARAMETERS
 *  status      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tm_handle_theme_activation_error_status(S32 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 	mmi_thm_display_error_msg(status, GRP_ID_ROOT);	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_activate_system_theme
 * DESCRIPTION
 *  This function activates system theme
 * PARAMETERS
 *  theme_struct_p      [?]     [?]
 * RETURNS
 *  theme error code
 *****************************************************************************/
S32 mmi_tm_activate_system_theme(tm_theme_list_struct *theme_struct_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 err;
    U64 buff;     
	S32 usb_id;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_TM_ACTIVATE_SYSTEM_THEME, theme_struct_p->theme_id);

    /* reset NVRAM_USB_PREVIOUS_THEME_INDEX if there's value there */
    if (g_tm_USB_mode == MMI_TRUE)
    {
        MMI_THM_TRACE1(MMI_THEME_ACTIVE_SYSTEM_PATH, 1);
    	ReadValue(NVRAM_USB_PREVIOUS_THEME_INDEX, (void*)&buff, DS_DOUBLE, &err);
    	usb_id = (U32) buff;
    	if (usb_id != -1)
    	{			
            MMI_THM_TRACE1(MMI_THEME_ACTIVE_SYSTEM_PATH, 2);
    		usb_id = -1;
    		WriteValue(NVRAM_USB_PREVIOUS_THEME_INDEX, (void*)&usb_id, DS_DOUBLE, &err);
    	}
    }

    if ((result = mmi_tm_activate(theme_struct_p->theme_id, theme_struct_p->theme_type, NULL)) == THEME_ERROR_SUCCESS)
    {
        MMI_THM_TRACE1(MMI_THEME_ACTIVE_SYSTEM_PATH, 3);

        /* todo: To copy from MCT */
        g_theme_cntx.curr_activated_theme_id = theme_struct_p->theme_id;
        WriteValue(THEME_MANAGER_CURR_THEME_ID, (void*)&g_theme_cntx.curr_activated_theme_id, DS_DOUBLE, &err);
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_activate_theme
 * DESCRIPTION
 *  This function activates theme at the time of theme selection
 * PARAMETERS
 *  theme_id        [IN]        
 * RETURNS
 *  theme error code
 *****************************************************************************/
S32 mmi_tm_activate_theme(U32 theme_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 audio_id;
    U8 i;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ShowCategory66Screen(STR_SCR3001_THEMES_CAPTION,0, 0, 0, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, (PU8)GetString(STR_ID_DLT_THM_PROGRESS), IMG_THEME_ACTIVATION, NULL); */
	MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_TM_ACTIVATE_THEME, theme_id);

    if (g_theme_cntx.curr_activated_theme_id == theme_id)
    {
        MMI_THM_TRACE1(MMI_THEME_ACTIVE_THEME_PATH, 1);
        return THEME_ERROR_ALREADY_ACTIVATED;
    }

    for (i = 0; i < g_theme_cntx.total_thm_cnt; ++i)
    {
        if (theme_id == g_tm_theme_list[i].theme_id)
        {
            break;
        }
    }

    if (g_tm_theme_list[i].theme_type == THEME_TYPE_SYSTEM)
    {
        MMI_THM_TRACE1(MMI_THEME_ACTIVE_THEME_PATH, 2);
        result = mmi_tm_activate_system_theme(&g_tm_theme_list[i]);
    }
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__      /* ritesh */
    else
    {
        result = mmi_tm_activate_downloaded_theme(&g_tm_theme_list[i]);
    }
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ /* ritesh */

    if (result == THEME_ERROR_SUCCESS)
    {
        /* only set theme wallpaper when selected by user */
        if ( PhnsetIsWPCurrentTheme() ) 
        {
             MMI_THM_TRACE1(MMI_THEME_ACTIVE_THEME_PATH, 3);
            ThemeManagerSetWallpaper(IMG_ID_DISPCHAR_THEME_WALLPAPER);
        }
        
        if (PhnsetIsScrSvrCurrentTheme())
        {
            MMI_THM_TRACE1(MMI_THEME_ACTIVE_THEME_PATH, 4);
            ThemeManagerSetScreensaver(IMG_ID_DISPCHAR_THEME_SCREENSAVER);
        }
        
        if (mmi_tm_does_theme_res_exist(THEME_RES_RINGTONE))
        {
            MMI_THM_TRACE1(MMI_THEME_ACTIVE_THEME_PATH, 5);
            audio_id = CURRENT_THEME_INCOMING_CALL_TONE;
            srv_prof_set_current_profile_value(
                                    SRV_PROF_SETTINGS_MT_CALL_TONE,
                                    &audio_id);
		#if (MMI_MAX_SIM_NUM >= 2)
            audio_id = CURRENT_THEME_INCOMING_CALL_TONE;
            srv_prof_set_current_profile_value(
                                    SRV_PROF_SETTINGS_MT_CALL_CARD2_TONE,
                                    &audio_id);
        #endif	/* MMI_MAX_SIM_NUM */
            //mmi_alm_set_dlt_alarm_tone(CURRENT_THEME_ALARM_EXPIRY_TONE);
        }
        else
        {
            MMI_THM_TRACE1(MMI_THEME_ACTIVE_THEME_PATH, 6);
            srv_prof_reset_tone_with_audio_id(
                                    SRV_PROF_SETTINGS_MT_CALL_TONE,
                                    CURRENT_THEME_INCOMING_CALL_TONE);
        #if (MMI_MAX_SIM_NUM >= 2)
            srv_prof_reset_tone_with_audio_id(
                                    SRV_PROF_SETTINGS_MT_CALL_CARD2_TONE,
                                    CURRENT_THEME_INCOMING_CALL_TONE);
        #endif	
            mmi_alm_reset_dlt_alarm_tone();
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_activate_theme_at_bootup
 * DESCRIPTION
 *  This function activates theme at bootup time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_tm_activate_theme_at_bootup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0, found = 0;
    S32 result;
    U32 curr_theme_id;
	S32 usb_id;  
	S16 err;	
	U64 buff;   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_TM_ACTIVATE_THEME_AT_BOOTUP);

    ReadValue(NVRAM_USB_PREVIOUS_THEME_INDEX, (void*)&buff, DS_DOUBLE, &err);
	usb_id = (U32) buff;
	if (usb_id != -1)
	{
		WriteValue(THEME_MANAGER_CURR_THEME_ID, (void*)&usb_id, DS_DOUBLE, &err);
		usb_id = -1;
		WriteValue(NVRAM_USB_PREVIOUS_THEME_INDEX, (void*)&usb_id, DS_DOUBLE, &err);
	}
    curr_theme_id = mmi_tm_get_current_theme_id();
    for (i = 0; i < g_theme_cntx.total_thm_cnt; ++i)
    {
        if (curr_theme_id == g_tm_theme_list[i].theme_id)
        {
            found = 1;
            break;
        }
    }

    if (found)
    {
        if (g_tm_theme_list[i].theme_type == THEME_TYPE_SYSTEM)
        {
            result = mmi_tm_activate_system_theme(&g_tm_theme_list[i]);
        }
    #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__      /* ritesh */
        else
        {
            result = mmi_tm_activate_downloaded_theme(&g_tm_theme_list[i]);
        }
    #endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
    
        if (result != THEME_ERROR_SUCCESS)
        {
            mmi_tm_activate_system_theme(&g_tm_theme_list[0]);

        #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__      /* ritesh */
            srv_prof_reset_tone_with_audio_id(
                                    SRV_PROF_SETTINGS_MT_CALL_TONE,
                                    CURRENT_THEME_INCOMING_CALL_TONE);            
        #if (MMI_MAX_SIM_NUM >= 2)
            srv_prof_reset_tone_with_audio_id(
                                    SRV_PROF_SETTINGS_MT_CALL_CARD2_TONE,
                                    CURRENT_THEME_INCOMING_CALL_TONE);
        #endif
            mmi_alm_reset_dlt_alarm_tone();
        #endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ /* ritesh */
        }

        /* only set theme wallpaper when selected by user */
        if (PhnsetIsWPCurrentTheme()) 
        {
            ThemeManagerSetWallpaper(IMG_ID_DISPCHAR_THEME_WALLPAPER);
        }
        
        if (PhnsetIsScrSvrCurrentTheme())
        {
            ThemeManagerSetScreensaver(IMG_ID_DISPCHAR_THEME_SCREENSAVER);
        }
    }
    else
    {
        mmi_tm_activate_system_theme(&g_tm_theme_list[0]);
        if (PhnsetIsWPCurrentTheme())
        {
            ThemeManagerSetWallpaper(IMG_ID_DISPCHAR_THEME_WALLPAPER);
        }

        if (PhnsetIsScrSvrCurrentTheme())
        {
            ThemeManagerSetScreensaver(IMG_ID_DISPCHAR_THEME_SCREENSAVER);
        }
        
    #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__      /* ritesh */
        srv_prof_reset_tone_with_audio_id(
                                SRV_PROF_SETTINGS_MT_CALL_TONE,
                                CURRENT_THEME_INCOMING_CALL_TONE);        
    #if (MMI_MAX_SIM_NUM >= 2)
        srv_prof_reset_tone_with_audio_id(
                                SRV_PROF_SETTINGS_MT_CALL_CARD2_TONE,
                                CURRENT_THEME_INCOMING_CALL_TONE);
    #endif
        mmi_alm_reset_dlt_alarm_tone();
    #endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ /* ritesh */
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_activate_downloaded_theme
 * DESCRIPTION
 *  This function activates downloadable theme
 * PARAMETERS
 *  theme_struct_p      [?]     
 * RETURNS
 *  theme error code
 *****************************************************************************/
S32 mmi_tm_activate_downloaded_theme(tm_theme_list_struct *theme_struct_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    S16 err;
    U8 theme_file_name[(MAX_DWNL_THM_PATH_LEN + MAX_THEME_NAME_LENGTH) * ENCODING_LENGTH] = {0};
    U8 tmp_path[50] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_TM_ACTIVATE_DOWNLOADED_THEME);
    
    sprintf((CHAR*) tmp_path, "%c%s", theme_struct_p->drv_letter, DOWNLOADED_THEMES_PATH);
    mmi_asc_to_ucs2((CHAR*) theme_file_name, (CHAR*) tmp_path);
    mmi_ucs2cat((CHAR*) theme_file_name, (CHAR*) theme_struct_p->theme_name);
    
    result = mmi_tm_verify_theme_checksum(theme_file_name);

    MMI_THM_TRACE1(MMI_THEME_ACTIVATE_DOWNLOADED, result);
    if (result == THEME_ERROR_SUCCESS)
    {
        theme_struct_p->theme_checksum_verified = CHECKSUM_VERIFIED_OK;
        WriteRecord(
            NVRAM_EF_THEME_MANAGER_LID,
            1,
            (void*)(g_tm_theme_list + g_theme_cntx.sys_thm_cnt),
            NVRAM_EF_THEME_MANAGER_RECORD_SIZE,
            &err);
    }
    else
    {
        theme_struct_p->theme_checksum_verified = CHECKSUM_VERIFIED_BAD;
        WriteRecord(
            NVRAM_EF_THEME_MANAGER_LID,
            1,
            (void*)(g_tm_theme_list + g_theme_cntx.sys_thm_cnt),
            NVRAM_EF_THEME_MANAGER_RECORD_SIZE,
            &err);
        return THEME_ERROR_FILE_FORMAT_BAD;
    }
    
    if ((result = mmi_tm_activate(theme_struct_p->theme_id, theme_struct_p->theme_type, (U16*)theme_file_name)) == THEME_ERROR_SUCCESS)
    {
        g_theme_cntx.curr_activated_theme_id = theme_struct_p->theme_id;
        MMI_THM_TRACE1(MMI_THEME_ACTIVATE_DOWNLOAD_CURR_ID, g_theme_cntx.curr_activated_theme_id);
        WriteValue(THEME_MANAGER_CURR_THEME_ID, (void*)&g_theme_cntx.curr_activated_theme_id, DS_DOUBLE, &err);
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ta_check_theme_file_lcd_dim_compatibiltiy
 * DESCRIPTION
 *  validates LCD dimensions.
 * PARAMETERS
 *  lcd_width       [IN]        
 *  lcd_height      [IN]        
 * RETURNS
 *  true if compatible otherwise false
 *****************************************************************************/
U16 mmi_thm_check_theme_file_lcd_dim_compatibiltiy(U32 lcd_width, U32 lcd_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (lcd_height == LCD_HEIGHT && lcd_width == LCD_WIDTH)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ta_check_theme_type_compatibility
 * DESCRIPTION
 *  validates Theme type.
 * PARAMETERS
 *  input_type_p        [?]     
 * RETURNS
 *  true if compatible otherwise false
 *****************************************************************************/
static U16 mmi_thm_check_theme_type_compatibility(CHAR *input_type_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_ACCEPTABLE_THEME_FILE_TYPE; i++)
    {
        if (strcmp(input_type_p, g_mmi_thm_acceptable_theme_filetypes[i]) == 0)
        {
            return TRUE;
        }
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ta_parse_lcd_size
 * DESCRIPTION
 *  It parses the lcd height and lcd width string given in dd file
 * PARAMETERS
 *  lcd_size_string_p       [IN]        
 *  lcd_height_p            [IN]        
 *  lcd_width_p             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_thm_parse_lcd_size(const CHAR *lcd_size_string_p, CHAR *lcd_height_p, CHAR *lcd_width_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int count1 = 0, count2 = 0;
    CHAR lcd_size_param[MAX_LCD_STRING_SIZE];
    CHAR temp_ch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(lcd_size_param, 0, MAX_LCD_STRING_SIZE);

    while (*lcd_size_string_p != '\0')
    {
        temp_ch = (CHAR) * lcd_size_string_p;

        if (temp_ch != ':' && temp_ch != (CHAR) ';' && temp_ch != ' ' && temp_ch != '\t')
        {
            lcd_size_param[count1] = temp_ch;
            ++count1;
        }
        else if (*lcd_size_string_p == ':')
        {
            lcd_size_param[count1] = 0;
            count1 = 0;
            count2 = 0;

            while (temp_ch == ':' || temp_ch == ';' || temp_ch == ' ' || temp_ch == '\t')
            {
                ++(lcd_size_string_p);
                temp_ch = (CHAR) * lcd_size_string_p;
            }

            while (temp_ch != '\0' && temp_ch != ':' && temp_ch != ';' && temp_ch != ' ' && temp_ch != '\t')
            {
                if (!strcmp(lcd_size_param, g_mmi_thm_descriptor_tags[6]))
                {
                    lcd_height_p[count2] = temp_ch;
                    ++count2;
                }
                else if (!strcmp(lcd_size_param, g_mmi_thm_descriptor_tags[7]))
                {
                    lcd_width_p[count2] = temp_ch;
                    ++count2;
                }
                ++(lcd_size_string_p);
                temp_ch = (CHAR) * lcd_size_string_p;
            }
            if (!strcmp(lcd_size_param, g_mmi_thm_descriptor_tags[6]))
            {
                lcd_height_p[count2] = 0;
            }
            else if (!strcmp(lcd_size_param, g_mmi_thm_descriptor_tags[7]))
            {
                lcd_width_p[count2] = 0;
            }
        }

        ++(lcd_size_string_p);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ta_da_oma_install_check_hdlr
 * DESCRIPTION
 *  Its a OMA download callback function and called by download agent for validating the
 *  theme descriptor file
 * PARAMETERS
 *  dd_file     [IN]        
 * RETURNS
 *  TRUE                   if descriptor file contains valid info
 *  FALSE                  if descriptor file contains in-valid info
 *****************************************************************************/
MMI_BOOL mmi_ta_da_oma_install_check_hdlr(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* FLOAT theme_version; */
	srv_da_oma_dd_struct* dd_file;
    U16 err_status;
    CHAR lcd_height_p[MAX_LCD_STRING_SIZE];
    CHAR lcd_width_p[MAX_LCD_STRING_SIZE];

    memset(lcd_height_p, 0, MAX_LCD_STRING_SIZE);
    memset(lcd_width_p, 0, MAX_LCD_STRING_SIZE);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(param != NULL);
	
	dd_file = (srv_da_oma_dd_struct *)param;
	if (dd_file->type[0] == NULL || dd_file->installParam == NULL)
	{
		return MMI_FALSE;
	}
	
    /* Checking theme type compatibility */
    if (!mmi_thm_check_theme_type_compatibility(dd_file->type[0]))
    {
        return MMI_FALSE;
    }

    /* Checking theme type compatibility */
    mmi_thm_parse_lcd_size(dd_file->installParam, (CHAR*) lcd_height_p, (CHAR*) lcd_width_p);
    err_status = mmi_thm_check_theme_file_lcd_dim_compatibiltiy(
                    (U32) atof((const CHAR*)lcd_width_p),
                    (U32) atof((const CHAR*)lcd_height_p));
    if (!err_status)
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_thm_get_usb_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_thm_get_usb_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_tm_USB_mode || 
        SRV_BOOTUP_MODE_USB == srv_bootup_get_booting_mode())
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_init_theme_usb_mode_plugout_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tm_init_theme_usb_mode_plugout_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 period;
	S16 err;
    U64 buff;     
	S32 usb_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ReadValue(NVRAM_USB_PREVIOUS_THEME_INDEX, (void*)&buff, DS_DOUBLE, &err);
	usb_id = (U32) buff;
	if (usb_id != -1)
	{			
        if (mmi_tm_activate_theme(usb_id) != THEME_ERROR_SUCCESS)
		{
			usb_id = mmi_tm_get_current_theme_id(); /* get default theme ID */
		}
        WriteValue(THEME_MANAGER_CURR_THEME_ID, (void*)&usb_id, DS_DOUBLE, &err);
        
		usb_id = -1;
		WriteValue(NVRAM_USB_PREVIOUS_THEME_INDEX, (void*)&usb_id, DS_DOUBLE, &err);
	}
    g_tm_USB_mode = MMI_FALSE;
    if (g_tm_was_theme_alarm_cb == MMI_TRUE)
    {
        ThemeAlarmCallBack(0, &period, 0);
        g_tm_was_theme_alarm_cb = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_init_theme_usb_mode_plugin_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tm_init_theme_usb_mode_plugin_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S16 err;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_tm_get_curr_theme_type() != THEME_TYPE_SYSTEM)  /* fixed for usb */
    {
		WriteValue(NVRAM_USB_PREVIOUS_THEME_INDEX, (void*)&g_theme_cntx.curr_activated_theme_id, DS_DOUBLE, &err);
        ActivateDefaultTheme();
        g_thm_cntx.CurrTheme = mmi_tm_get_current_theme_id();
    }
    g_tm_USB_mode = MMI_TRUE;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_theme_enter_usb_ms_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_theme_enter_usb_ms_callback(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S16 err;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_tm_get_curr_theme_type() != THEME_TYPE_SYSTEM)  /* fixed for usb */
    {
		WriteValue(NVRAM_USB_PREVIOUS_THEME_INDEX, (void*)&g_theme_cntx.curr_activated_theme_id, DS_DOUBLE, &err);
        ActivateDefaultTheme();
        g_thm_cntx.CurrTheme = mmi_tm_get_current_theme_id();
    }
    g_tm_USB_mode = MMI_TRUE;
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_theme_exit_usb_ms_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_theme_exit_usb_ms_callback(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 period;
	S16 err;
    U64 buff;     
	S32 usb_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ReadValue(NVRAM_USB_PREVIOUS_THEME_INDEX, (void*)&buff, DS_DOUBLE, &err);
	usb_id = (S32) buff;
	if (usb_id != -1)
	{			
        if (mmi_tm_activate_theme(usb_id) != THEME_ERROR_SUCCESS)
		{
			usb_id = mmi_tm_get_current_theme_id(); /* get default theme ID */
		}
        WriteValue(THEME_MANAGER_CURR_THEME_ID, (void*)&usb_id, DS_DOUBLE, &err);
        
		usb_id = -1;
		WriteValue(NVRAM_USB_PREVIOUS_THEME_INDEX, (void*)&usb_id, DS_DOUBLE, &err);
	}
    g_tm_USB_mode = MMI_FALSE;
    if (g_tm_was_theme_alarm_cb == MMI_TRUE)
    {
        ThemeAlarmCallBack(0, &period, 0);
        g_tm_was_theme_alarm_cb = MMI_FALSE;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_is_theme_activated
 * DESCRIPTION
 *  This function returns theme activation status
 * PARAMETERS
 *  theme_type          [IN]        
 *  theme_name          [IN]        
 * RETURNS
 *  activated or not
 *****************************************************************************/
static MMI_BOOL mmi_tm_is_theme_activated(U16 theme_type, CHAR* theme_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = g_theme_cntx.sys_thm_cnt; i < g_theme_cntx.total_thm_cnt; ++i)
    {
        if ((g_tm_theme_list[i].theme_id == g_theme_cntx.curr_activated_theme_id) &&
            !mmi_ucs2cmp((CHAR*) g_tm_theme_list[i].theme_name, (CHAR*) theme_name) &&
            (g_tm_theme_list[i].theme_type == theme_type))
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_tm_get_themes_for_fmgr
 * DESCRIPTION
 *  1. Purge the theme list of any non-existant themes
 *  2. Add theme to list if space available.
 * PARAMETERS
 *  theme_list_p        [IN]        
 *  filename            [IN]        
 *  storage_type        [IN]        
 * RETURNS
 *  total number of themes
 *****************************************************************************/
U8 mmi_tm_get_themes_for_fmgr(tm_theme_list_struct **theme_list_p, CHAR drv_letter, CHAR* filename, tm_theme_type_enum storage_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nvm_card_thm_cnt = 0;
    tm_theme_list_struct *tmp_theme_list_p;

    U8 h, i, j, k;
    S16 err;
    U32 max_theme_id;
    U64 buff;
    U8 *temp_name;
    U8 nSystemThemeCount;
    S16 error_code;

    CHAR tmp_str[MAX_DWNL_THM_PATH_LEN + MAX_THEME_SEARCH_STR_LEN];
    U16 theme_path[MAX_DWNL_THM_PATH_LEN + MAX_THEME_SEARCH_STR_LEN + MAX_THEME_NAME_LENGTH + 1];
    U16 theme_path_phone[MAX_DWNL_THM_PATH_LEN];
    U16 theme_path_card[MAX_DWNL_THM_PATH_LEN];

	MMI_BOOL exist_flag = MMI_FALSE;
	U8 exist_idx = 0;
	CHAR *p_ext;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nSystemThemeCount = (U8) GetThemesNames((U8 ***) & temp_name);
    if (nSystemThemeCount > MAX_SYSTEM_THEMES)
    {
        nSystemThemeCount = MAX_SYSTEM_THEMES;
    }
    memset((void*)g_tm_theme_list, 0, sizeof(tm_theme_list_struct) * TOTAL_THEMES_COUNT);
    g_theme_cntx.total_thm_cnt = 0;
    g_theme_cntx.sys_thm_cnt = 0;

    for (j = 0; j < nSystemThemeCount; ++j)
    {
        mmi_ucs2ncpy(
            (CHAR*) g_tm_theme_list[j].theme_name,
            GetString((U16) (STR_THEME_DEFAULT + j)),
            MAX_THEME_NAME_LENGTH);
        g_tm_theme_list[j].theme_checksum_verified = CHECKSUM_VERIFIED_OK;
        g_tm_theme_list[j].theme_id = j + 1;
        g_tm_theme_list[j].theme_type = THEME_TYPE_SYSTEM;
    }
    g_theme_cntx.total_thm_cnt = g_theme_cntx.sys_thm_cnt = nSystemThemeCount;

    /* Read Themes from NVRAM */
    ReadRecord(
        NVRAM_EF_THEME_MANAGER_LID,
        1,
        (void*)(g_tm_theme_list + g_theme_cntx.sys_thm_cnt),
        NVRAM_EF_THEME_MANAGER_RECORD_SIZE,
        &err);
    /* err = 1 => NVRAM_READ_SUCCESS */
    if (err != NVRAM_READ_SUCCESS)
    {
        *theme_list_p = g_tm_theme_list;
        return g_theme_cntx.total_thm_cnt;
    }

    /* Sukrit: A better way to do it will be through something like does file exists on phone folder */

    sprintf(tmp_str, "%c%s", SRV_FMGR_PUBLIC_DRV, DOWNLOADED_THEMES_PATH);
    mmi_asc_to_ucs2((CHAR*) theme_path_phone, tmp_str);

    sprintf(tmp_str, "%c%s", SRV_FMGR_CARD_DRV, DOWNLOADED_THEMES_PATH);
    mmi_asc_to_ucs2((CHAR*) theme_path_card, tmp_str);

    ReadValue(THEME_MANAGER_MAX_THEME_ID, (void*)&buff, DS_DOUBLE, &err);
    max_theme_id = (U32) buff;
    if (max_theme_id == 0xFFFFFFFF || err == -1)
    {
        max_theme_id = 10;
        WriteValue(THEME_MANAGER_MAX_THEME_ID, (void*)&max_theme_id, DS_DOUBLE, &err);
    }

    tmp_theme_list_p = (tm_theme_list_struct*) & g_tm_NvramThmArr;

    /* Get all themes from NVRAM list, which are actually present on Phone, in a new theme list */
    /* Also, Count number of themes on phone and card that are actually on NVRAM */

    for (j = g_theme_cntx.sys_thm_cnt, k = 0; j < TOTAL_THEMES_COUNT; ++j)
    {
        if ((g_tm_theme_list[j].theme_type == THEME_TYPE_DOWNLOADED_PHONE))
        {
            mmi_ucs2ncpy((CHAR*) theme_path, (CHAR*) theme_path_phone, MAX_DWNL_THM_PATH_LEN);
            mmi_ucs2ncat((CHAR*) theme_path, (CHAR*) g_tm_theme_list[j].theme_name, MAX_THEME_NAME_LENGTH);

			if (mmi_ucs2icmp((CHAR*)g_tm_theme_list[j].theme_name, (CHAR *)filename) == 0)
			{
				exist_flag = MMI_TRUE;
				exist_idx = j;

				MMI_THM_TRACE1(MMI_THEME_GET_FMGR_PHN_ICMP_SUCCESS, exist_idx);
				/* Case sensitive */
				if (mmi_ucs2cmp((CHAR*)g_tm_theme_list[j].theme_name, (CHAR *)filename) != 0)
				{
					MMI_THM_TRACE0(MMI_THEME_GET_FMGR_PHN_CMP_FAIL);
					mmi_ucs2ncpy((CHAR*)g_tm_theme_list[j].theme_name, (CHAR*)filename, MAX_THEME_NAME_LENGTH);
				}
			}
			
            error_code = FS_GetAttributes(theme_path);
            if (((error_code >= 0) && (error_code != FS_ATTR_DIR)) || (error_code == FS_ACCESS_DENIED))
            {
                memcpy((void*)(tmp_theme_list_p + k), (void*)&g_tm_theme_list[j], sizeof(tm_theme_list_struct));
                MMI_THM_TRACE1(MMI_THEME_GET_FMGR_PHN_ADD_TEMP, k);
                ++k;
            }
        }
    }

    /* Insert new Phone themes in NVRAM list */
    if (storage_type == THEME_TYPE_DOWNLOADED_PHONE && k < (MAX_DOWNLOADED_THEMES - nvm_card_thm_cnt))
    {
    	if (exist_flag)
		{
			mmi_ucs2ncpy((CHAR*)g_tm_theme_list[exist_idx].theme_name, (CHAR*)filename, MAX_THEME_NAME_LENGTH);
			exist_flag = MMI_FALSE;
		}
        else
        {
            memset((void*)&tmp_theme_list_p[k], 0, sizeof(tm_theme_list_struct));
            mmi_ucs2ncpy((CHAR*) tmp_theme_list_p[k].theme_name, (CHAR*) filename, MAX_THEME_NAME_LENGTH);
            tmp_theme_list_p[k].theme_checksum_verified = CHECKSUM_NOT_VERIFIED;
            tmp_theme_list_p[k].theme_id = ++max_theme_id;
            tmp_theme_list_p[k].theme_type = THEME_TYPE_DOWNLOADED_PHONE;
            tmp_theme_list_p[k].drv_letter = drv_letter;
            ++k;
        }
    }
    exist_flag = MMI_FALSE;
    /* Get all themes from NVRAM list, which are actually present on card, in a new theme list */
    for (j = g_theme_cntx.sys_thm_cnt; j < TOTAL_THEMES_COUNT; ++j)
    {
        if ((g_tm_theme_list[j].theme_type == THEME_TYPE_DOWNLOADED_CARD))
        {
            sprintf(tmp_str, "%c%s", g_tm_theme_list[j].drv_letter, DOWNLOADED_THEMES_PATH);
            mmi_asc_to_ucs2((CHAR*) theme_path_card, tmp_str);
            mmi_ucs2ncpy((CHAR*) theme_path, (CHAR*) theme_path_card, MAX_DWNL_THM_PATH_LEN);
            mmi_ucs2ncat((CHAR*) theme_path, (CHAR*) g_tm_theme_list[j].theme_name, MAX_THEME_NAME_LENGTH);
			
			if (mmi_ucs2icmp((CHAR*)g_tm_theme_list[j].theme_name, (CHAR *)filename) == 0)
			{
				exist_flag = MMI_TRUE;
				exist_idx = j;
				MMI_THM_TRACE1(MMI_THEME_GET_FMGR_CARD_ICMP_SUCCESS, exist_idx);
				/* Case sensitive */
				if (mmi_ucs2cmp((CHAR*)g_tm_theme_list[j].theme_name, (CHAR *)filename) != 0)
				{
				    MMI_THM_TRACE0(MMI_THEME_GET_FMGR_CARD_CMP_FAIL);
					mmi_ucs2ncpy((CHAR*)g_tm_theme_list[j].theme_name, (CHAR*)filename, MAX_THEME_NAME_LENGTH);
				}
			}
            error_code = FS_GetAttributes(theme_path);
            if (((error_code >= 0) && (error_code != FS_ATTR_DIR)) || (error_code == FS_ACCESS_DENIED))
            {
                memcpy((void*)(tmp_theme_list_p + k), (void*)&g_tm_theme_list[j], sizeof(tm_theme_list_struct));
                MMI_THM_TRACE1(MMI_THEME_GET_FMGR_CARD_ADD_TEMP, k);
                ++k;
            }
        }
    }

    /* Insert new Card themes in NVRAM list */
    if (storage_type == THEME_TYPE_DOWNLOADED_CARD && k < MAX_DOWNLOADED_THEMES)
    {
    	if (exist_flag)
		{
			mmi_ucs2ncpy((CHAR*)g_tm_theme_list[exist_idx].theme_name, (CHAR*)filename, MAX_THEME_NAME_LENGTH);
			exist_flag = MMI_FALSE;
		}
        else
        {
            memset((void*)&tmp_theme_list_p[k], 0, sizeof(tm_theme_list_struct));
	        mmi_ucs2ncpy((CHAR*) tmp_theme_list_p[k].theme_name, (CHAR*) filename, MAX_THEME_NAME_LENGTH);
	        tmp_theme_list_p[k].theme_checksum_verified = CHECKSUM_NOT_VERIFIED;
	        tmp_theme_list_p[k].theme_id = ++max_theme_id;
	        tmp_theme_list_p[k].theme_type = THEME_TYPE_DOWNLOADED_CARD;
	        tmp_theme_list_p[k].drv_letter = drv_letter;

	        ++k;
    	}

    }
    
    for (i = 0; i < k;)
    {
        p_ext = mmi_ucs2str((CHAR*)tmp_theme_list_p[i].theme_name, (CHAR*)L".");
        p_ext += ENCODING_LENGTH;
        if (mmi_ucs2cmp(p_ext, (CHAR*)L"med") && mmi_ucs2cmp(p_ext, (CHAR*)L"MED"))
        {
            memset(&tmp_theme_list_p[i], 0, sizeof(tm_theme_list_struct));            
            for (j = i + 1, h = i; j < k; j++, h++)
            {
                memcpy(&tmp_theme_list_p[h], &tmp_theme_list_p[j], sizeof(tm_theme_list_struct));
            }
            k--;
        }
        else
        {
            i++;
        }
    }
    
    g_theme_cntx.total_thm_cnt = g_theme_cntx.sys_thm_cnt + k;

    memset((void*)(g_tm_theme_list + g_theme_cntx.sys_thm_cnt), 0, sizeof(tm_theme_list_struct) * MAX_DOWNLOADED_THEMES);
    memcpy((void*)(g_tm_theme_list + g_theme_cntx.sys_thm_cnt), tmp_theme_list_p, sizeof(tm_theme_list_struct) * k);

    /* Write Themes back to NVRAM */
    WriteRecord(
        NVRAM_EF_THEME_MANAGER_LID,
        1,
        (void*)(g_tm_theme_list + g_theme_cntx.sys_thm_cnt),
        NVRAM_EF_THEME_MANAGER_RECORD_SIZE,
        &err);
    /* err = 4 => NVRAM_WRITE_SUCCESS */
    WriteValue(THEME_MANAGER_MAX_THEME_ID, (void*)&max_theme_id, DS_DOUBLE, &err);

    *theme_list_p = g_tm_theme_list;
    return g_theme_cntx.total_thm_cnt;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_delete_theme_from_fmgr
 * DESCRIPTION
 *  This function deletes theme with the corresponding theme name from file manager
 * PARAMETERS
 *  theme_type          [IN]        
 *  theme_name_p        [?]         
 *  error_type          [IN]        
 * RETURNS
 *  theme error code
 *****************************************************************************/
S32 mmi_tm_delete_theme_from_fmgr
(
	tm_theme_type_enum theme_type, 
	U8 *theme_name_p, 
	PS32 error_type
)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, found = 0;
    S16 err;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_TM_DELETE_THEME_FROM_FMGR, theme_type);
    MMI_THM_TRACE0(MMI_THEME_ENTRY_DEL_FROM_FMGR);
    
    for (i = g_theme_cntx.sys_thm_cnt; i < g_theme_cntx.total_thm_cnt; ++i)
    {
        if (!mmi_ucs2cmp((CHAR*) g_tm_theme_list[i].theme_name, (CHAR*) theme_name_p) &&
            (g_tm_theme_list[i].theme_type == theme_type))
        {
            found = 1;
            MMI_THM_TRACE1(MMI_THEME_DEL_FROM_FMGR_FOUND, i);
            break;
        }
    }

    if (found)
    {
        if (g_tm_theme_list[i].theme_id == g_theme_cntx.curr_activated_theme_id)
        {
            return THEME_ERROR_ALREADY_ACTIVATED;
        }
        
		for (; i < g_theme_cntx.total_thm_cnt - 1; ++i)
        {
            memcpy((void*)&g_tm_theme_list[i], (void*)&g_tm_theme_list[i + 1], sizeof(tm_theme_list_struct));
        }
        memset((void*)&g_tm_theme_list[g_theme_cntx.total_thm_cnt - 1], 0, sizeof(tm_theme_list_struct));
        WriteRecord(
            NVRAM_EF_THEME_MANAGER_LID,
            1,
            (void*)(g_tm_theme_list + g_theme_cntx.sys_thm_cnt),
            NVRAM_EF_THEME_MANAGER_RECORD_SIZE,
            &err);
        --g_theme_cntx.total_thm_cnt;

        return THEME_ERROR_SUCCESS;
    }
    else
    {
        return THEME_ERROR_FAILURE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_activate_theme_from_fmgr
 * DESCRIPTION
 *  This function activates theme from file manager
 * PARAMETERS
 *  theme_type          [IN]        
 *  theme_name_p        [IN]     
 *  is_short            [IN]    
 * RETURNS
 *  theme error code
 *****************************************************************************/
S32 mmi_tm_activate_theme_from_fmgr(tm_theme_type_enum theme_type, CHAR drv_letter, U8 *theme_name_p, MMI_BOOL is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 found = 0;
    S32 result;
    U16 filename[(MAX_THEME_NAME_LENGTH + 1)];
    tm_theme_list_struct *theme_list_p;
    U16 audio_id;
    FS_HANDLE handle;
    WCHAR* full_path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_TM_ACTIVATE_THEME_FROM_FMGR);
    MMI_THM_TRACE0(MMI_THEME_ENTRY_ACTIVE_FROM_FMGR);
    
    if (mmi_thm_get_usb_mode())
    {
        return THEME_ERROR_USB_MODE_ON;
    }

	if (mmi_ucs2strlen((CHAR*)theme_name_p) > MAX_THEME_NAME_LENGTH)
	{
		CHAR path[MAX_DWNL_THM_PATH_LEN + MAX_THEME_SEARCH_STR_LEN];
		sprintf(path, "%c%s", drv_letter, DOWNLOADED_THEMES_PATH);
		
		full_path = OslMalloc(sizeof(WCHAR) * (SRV_FMGR_PATH_MAX_LEN + 1));
		mmi_asc_to_ucs2((CHAR *)full_path, path);
		mmi_ucs2cat((CHAR *)full_path, (CHAR*)theme_name_p);
		handle = FS_Open(full_path, FS_READ_ONLY);
		FS_MakeFileName(handle, 0, filename, (MAX_THEME_NAME_LENGTH + 1));
		FS_Close(handle);
		OslMfree(full_path);
	}
	else
    {
        mmi_ucs2cpy((CHAR*) filename, (CHAR*) theme_name_p);
    }

    /* Check if theme already on the list */
    for (i = g_theme_cntx.sys_thm_cnt; i < g_theme_cntx.total_thm_cnt; ++i)
    {
        if ((mmi_ucs2cmp((CHAR*) g_tm_theme_list[i].theme_name, (CHAR*) filename) == 0) &&
            (g_tm_theme_list[i].theme_type == theme_type))
        {
            found = 1;
            MMI_THM_TRACE1(MMI_THEME_ACTIVE_FMGR_ALREADY_EXIST, i);
            break;
        }
    }

    if (found == 0)
    {
        /* Try to add theme to theme list */
        mmi_tm_get_themes_for_fmgr(&theme_list_p, drv_letter, (CHAR*) filename, theme_type);

        /* Theme still might not have been added: Check */
        for (i = g_theme_cntx.sys_thm_cnt; i < g_theme_cntx.total_thm_cnt; ++i)
        {
            if ((mmi_ucs2icmp((CHAR*) g_tm_theme_list[i].theme_name, (CHAR*) filename) == 0) &&
                (g_tm_theme_list[i].theme_type == theme_type))
            {
                found = 1;
                MMI_THM_TRACE1(MMI_THEME_ACTIVE_FMGR_ALREADY_ADDED, i);
                break;
            }
        }
    }
    if (found == 0)
    {
        return THEME_ERROR_MAX_COUNT_REACHED;
    }
    else
    {
        if (g_theme_cntx.curr_activated_theme_id == g_tm_theme_list[i].theme_id)
        {
            return THEME_ERROR_ALREADY_ACTIVATED;
        }
        else
        {
            result = mmi_tm_activate_downloaded_theme(&g_tm_theme_list[i]);
        }
    }

    if (result == THEME_ERROR_SUCCESS)
    {
        /* only set theme wallpaper when selected by user */
        if ( PhnsetIsWPCurrentTheme() ) 
        {
            ThemeManagerSetWallpaper(IMG_ID_DISPCHAR_THEME_WALLPAPER);
        }
        
        if (PhnsetIsScrSvrCurrentTheme())
        {
            ThemeManagerSetScreensaver(IMG_ID_DISPCHAR_THEME_SCREENSAVER);
        }

        if (mmi_tm_does_theme_res_exist(THEME_RES_RINGTONE))
        {
            audio_id = CURRENT_THEME_INCOMING_CALL_TONE;
            srv_prof_set_current_profile_value(
                                    SRV_PROF_SETTINGS_MT_CALL_TONE,
                                    &audio_id);
	#if (MMI_MAX_SIM_NUM >= 2)
            audio_id = CURRENT_THEME_INCOMING_CALL_TONE;
            srv_prof_set_current_profile_value(
                                    SRV_PROF_SETTINGS_MT_CALL_CARD2_TONE,
                                    &audio_id);		     
	#endif
            mmi_alm_set_dlt_alarm_tone(CURRENT_THEME_ALARM_EXPIRY_TONE);
        }
        else
        {
            srv_prof_reset_tone_with_audio_id(
                                    SRV_PROF_SETTINGS_MT_CALL_TONE,
                                    CURRENT_THEME_INCOMING_CALL_TONE);            
	#if (MMI_MAX_SIM_NUM >= 2)
            srv_prof_reset_tone_with_audio_id(
                                    SRV_PROF_SETTINGS_MT_CALL_CARD2_TONE,
                                    CURRENT_THEME_INCOMING_CALL_TONE);        		    
	#endif
            mmi_alm_reset_dlt_alarm_tone();
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_thm_dlt_get_path_location
 * DESCRIPTION
 *  This function activates theme from file manager
 * PARAMETERS
 *  path		[IN]		theme file path   
 * RETURNS
 *  tm_theme_type_enum
 *****************************************************************************/
tm_theme_type_enum mmi_thm_dlt_get_path_location(CHAR* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16* upper_ptr;
    U8* tmp_str;
    CHAR* filename;
    U16 len, new_len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(path != NULL);
    
    len = mmi_ucs2strlen(path);
    tmp_str = OslMalloc((len + 2) * ENCODING_LENGTH);
    mmi_ucs2cpy((CHAR*)tmp_str, path);
    upper_ptr = mmi_wcsupr((U16*)tmp_str);
    if (mmi_ucs2str((CHAR*)upper_ptr, (CHAR*)MMI_THM_THEME_FOLDER2))
    {
        /*
         * If it in sub folder of folder mmitheme
         */
        filename = (CHAR*)srv_fmgr_path_get_filename_ptr((WCHAR*)upper_ptr);
        new_len = mmi_ucs2strlen(filename) + 9 + 1;
        if (new_len != len)
        {
            OslMfree(tmp_str);
            return (tm_theme_type_enum)0;
        }
      
        /*
         * The drive letter is the first char
         */
        if (path[0] == SRV_FMGR_PUBLIC_DRV)
        {
            OslMfree(tmp_str);
            return THEME_TYPE_DOWNLOADED_PHONE;
        }
        /*
         * Memory and OTG will be as this type
         */
        else
        {
            OslMfree(tmp_str);
            return THEME_TYPE_DOWNLOADED_CARD;
        }
    }

    OslMfree(tmp_str);
    return (tm_theme_type_enum)0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_thm_dlt_activate_from_fmgr
 * DESCRIPTION
 *  Activate the theme file from filemgr
 * PARAMETERS
 *  path		[IN]		path
 *	filename	[IN]		the file name
 *	is_short	[IN]		is short name
 * RETURNS
 *  tm_theme_type_enum
 *****************************************************************************/
static tm_theme_type_enum mmi_thm_dlt_activate_from_fmgr
(
	CHAR* path, 
	CHAR* filename , 
	MMI_BOOL is_short
)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tm_theme_type_enum  type;
    tm_theme_error_enum status;
    CHAR drv_letter;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    type = mmi_thm_dlt_get_path_location(path);
    /* drv_letter */
    drv_letter = path[0];
    status = (tm_theme_error_enum)mmi_tm_activate_theme_from_fmgr(type, drv_letter, (PU8) filename, is_short);
	/*
	 *	WenWu, Start. Update auto-update theme order after active.
	 */
	if (status == 0) /* theme success */
	{
		mmi_thm_activate_update_thm_order();
	}
	 
    if(type)
	{
		mmi_thm_display_error_msg(status, GRP_ID_THM_FMGR_ACTIVE);
	}
    

    return type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_thm_reset_file_cntx
 * DESCRIPTION
 *  Move the theme file to theme folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 static void mmi_thm_reset_file_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (g_mmi_thm_dlt_file_cntx.file_info_ptr != NULL)
	{
		OslMfree(g_mmi_thm_dlt_file_cntx.file_info_ptr);
		g_mmi_thm_dlt_file_cntx.file_info_ptr = NULL;
	}
	
    if(g_mmi_thm_dlt_file_cntx.new_path != NULL)
	{
		OslMfree(g_mmi_thm_dlt_file_cntx.new_path);
		g_mmi_thm_dlt_file_cntx.new_path = NULL;
	}
    	
	if (g_mmi_thm_dlt_file_cntx.org_path != NULL)
	{
		OslMfree(g_mmi_thm_dlt_file_cntx.org_path);
		g_mmi_thm_dlt_file_cntx.org_path = NULL;
	}

}


/*****************************************************************************
 * FUNCTION
 *  mmi_thm_dlt_move_theme_file
 * DESCRIPTION
 *  Move the theme file to theme folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_thm_dlt_move_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//FMGR_FILE_INFO_STRUCT *file_info_ptr;
    SRV_FMGR_FILEINFO_HANDLE file_info_handle;
    WCHAR *file_name;	
	S32 fs_result;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* To test whether it can be created */
	fs_result = FS_Open((WCHAR*)g_mmi_thm_dlt_file_cntx.new_path, FS_CREATE_ALWAYS | FS_READ_WRITE);
	if (fs_result < 0)
	{
		goto fs_error;
	}
	else
	{
		FS_Close(fs_result);
        FS_Delete((WCHAR*)g_mmi_thm_dlt_file_cntx.new_path);
	}
	
    fs_result = FS_Move((WCHAR*)g_mmi_thm_dlt_file_cntx.org_path, (WCHAR*)g_mmi_thm_dlt_file_cntx.new_path, FS_MOVE_KILL, NULL, NULL, 0);
    if(fs_result < 0)
    {
        goto fs_error;
    }

	//file_info_ptr = (FMGR_FILE_INFO_STRUCT *)g_mmi_thm_dlt_file_cntx.file_info_ptr;
    file_name = OslMalloc(sizeof(WCHAR) * (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1));
    srv_fmgr_fileinfo_create((WCHAR*)g_mmi_thm_dlt_file_cntx.new_path, &file_info_handle);
    srv_fmgr_fileinfo_get_name(file_info_handle, file_name, SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1);
    srv_fmgr_fileinfo_destroy(file_info_handle);
    mmi_thm_dlt_activate_from_fmgr(g_mmi_thm_dlt_file_cntx.new_path, (CHAR*)file_name, MMI_FALSE);
    OslMfree(file_name);
fs_error:
    if(fs_result < 0)
    {
        mmi_popup_display_simple_ext(
                        srv_fmgr_fs_error_get_string(fs_result),
                        (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(fs_result),
                        GRP_ID_THM_FMGR_ACTIVE,
                        0);
    }
	mmi_thm_reset_file_cntx();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_thm_dlt_move_theme_file
 * DESCRIPTION
 *  Move the theme file to theme folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_thm_dlt_move_file_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_thm_reset_file_cntx();
	GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_thm_dlt_move_theme_file
 * DESCRIPTION
 *  Move the theme file to theme folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_thm_dlt_move_file_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_FMGR_FILEINFO_HANDLE file_info_handle;
    WCHAR *file_name;
    S32 fs_result, len;
    mmi_confirm_property_struct arg;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_mmi_thm_dlt_file_cntx.org_path);
    /* check file if present */
	if (g_mmi_thm_dlt_file_cntx.file_info_ptr != NULL)
	{
		OslMfree(g_mmi_thm_dlt_file_cntx.file_info_ptr);
	}
    file_name = OslMalloc(sizeof(WCHAR) * (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1));
    srv_fmgr_fileinfo_create((WCHAR*)g_mmi_thm_dlt_file_cntx.org_path, &file_info_handle);
    srv_fmgr_fileinfo_get_name(file_info_handle, file_name, SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1);
    srv_fmgr_fileinfo_destroy(file_info_handle);
           
    /* compose folder path, create dir */
    len = 3 + mmi_ucs2strlen((CHAR*)FMGR_DEFAULT_FOLDER_THEMES) + mmi_ucs2strlen((CHAR*)file_name) + 1;

	if (g_mmi_thm_dlt_file_cntx.new_path != NULL)
	{
		OslMfree(g_mmi_thm_dlt_file_cntx.new_path);
	}
    g_mmi_thm_dlt_file_cntx.new_path = OslMalloc(len * ENCODING_LENGTH);
    mmi_ucs2ncpy(g_mmi_thm_dlt_file_cntx.new_path, g_mmi_thm_dlt_file_cntx.org_path, 3);
    mmi_ucs2cat(g_mmi_thm_dlt_file_cntx.new_path, (CHAR*)FMGR_DEFAULT_FOLDER_THEMES);

    fs_result = srv_fmgr_fs_create_folder((WCHAR*)(g_mmi_thm_dlt_file_cntx.new_path));
    if(fs_result < 0)
	{
	    goto fs_error;
	}
    
    mmi_ucs2cat(g_mmi_thm_dlt_file_cntx.new_path, (CHAR*)file_name);

	if (mmi_thm_is_file_exist(g_mmi_thm_dlt_file_cntx.new_path))
	{
        mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
        arg.parent_id = GRP_ID_THM_FMGR_ACTIVE;
        arg.callback = (mmi_proc_func)mmi_theme_comfirm_proc;
        
        mmi_theme_confirm_user_data_init(&g_theme_confirm_user_data);
        g_theme_confirm_user_data.sg_id = arg.parent_id;
        g_theme_confirm_user_data.LSK_function = (soft_key_hdlr)mmi_thm_dlt_move_file;
        g_theme_confirm_user_data.RSK_function = (soft_key_hdlr)mmi_thm_dlt_move_file_cancel;
        
        arg.user_tag = (void*)&g_theme_confirm_user_data;
        mmi_confirm_display_ext(
                    STR_GLOBAL_OVERWRITE_EXISTING_FILE, 
                    MMI_EVENT_QUERY, 
                    &arg);
	
		return;
	}
	
	mmi_thm_dlt_move_file();
	
fs_error:
        
    if(fs_result < 0)
    {
        mmi_popup_display_simple_ext(
                        srv_fmgr_fs_error_get_string(fs_result),
                        (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(fs_result),
                        GRP_ID_THM_FMGR_ACTIVE,
                        0);
    }
    OslMfree(file_name);
	mmi_thm_reset_file_cntx();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_thm_dlt_move_goback
 * DESCRIPTION
 *  Usr don't move the theme file and goback directly
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_thm_dlt_move_goback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_thm_reset_file_cntx();
	
	GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_thm_dlt_display_theme_popup
 * DESCRIPTION
 *  Display the move confirm screen
 * PARAMETERS
 *  filepath		[IN]		the dest path
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_thm_dlt_display_theme_popup(CHAR* filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len;
    mmi_confirm_property_struct arg;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_mmi_thm_dlt_file_cntx.org_path!= NULL)
	{
		OslMfree(g_mmi_thm_dlt_file_cntx.org_path);
	}
        
    len = mmi_ucs2strlen(filepath);
    g_mmi_thm_dlt_file_cntx.org_path = OslMalloc((len + 1) * ENCODING_LENGTH);
    mmi_ucs2cpy(g_mmi_thm_dlt_file_cntx.org_path, filepath);

    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = GRP_ID_THM_FMGR_ACTIVE;
    arg.callback = (mmi_proc_func)mmi_theme_comfirm_proc;

    mmi_theme_confirm_user_data_init(&g_theme_confirm_user_data);
    g_theme_confirm_user_data.sg_id = arg.parent_id;
    g_theme_confirm_user_data.LSK_function = (soft_key_hdlr)mmi_thm_dlt_move_file_check;
    g_theme_confirm_user_data.RSK_function = (soft_key_hdlr)mmi_thm_dlt_move_goback;

    arg.user_tag = (void*)&g_theme_confirm_user_data;
    mmi_confirm_display_ext(
                STR_ID_FMGR_THEME_INCORRECT_LOCATION, 
                MMI_EVENT_QUERY, 
                &arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_theme_activate_hdlr
 * DESCRIPTION
 *  hide extension file name
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmgr_theme_activate_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_fileinfo_struct file_info; 
    SRV_FMGR_FILEINFO_HANDLE file_info_handle;
    WCHAR *file_name;
    WCHAR *filepath;
	U16 img_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(
                GRP_ID_ROOT, 
                GRP_ID_THM_FMGR_ACTIVE,
                mmi_theme_fmgr_active_group_proc,
                NULL);

    mmi_frm_group_enter(
                GRP_ID_THM_FMGR_ACTIVE,
                MMI_FRM_NODE_SMART_CLOSE_FLAG);
                
#ifndef __MTK_TARGET__
    /* If MTE is active, no theme activation is allowed. */
    if (mmi_mte_is_active())
    {
        mmi_popup_display_simple_ext(
                STR_THEME_NOT_AVAILABLE,
                MMI_EVENT_FAILURE,
                GRP_ID_THM_FMGR_ACTIVE,
                0);
        return;
    }
#endif /* __MTK_TARGET__ */

    mmi_frm_scrn_enter(
                GRP_ID_THM_FMGR_ACTIVE,
                0,
                NULL,
                NULL,
                MMI_FRM_FULL_SCRN);
	img_id = mmi_get_event_based_image(MMI_EVENT_PROGRESS);
	g_mmi_thm_snd_id = mmi_get_event_based_sound(MMI_EVENT_PROGRESS);
    ShowCategory66Screen(
        STR_SCR3001_THEMES_CAPTION,
        GetRootTitleIcon(MENU3101_THEMES),
        0,
        0,
        0,
        0,
        (PU8) GetString(STR_ID_DLT_THM_PROGRESS),
        img_id,
        NULL);        
    if(!srv_prof_is_tone_playing(g_mmi_thm_snd_id))
    {
        srv_prof_play_tone(g_mmi_thm_snd_id, NULL);
    }
    filepath = (WCHAR*)srv_fmgr_types_query_fileinfo(&file_info);
    file_name = OslMalloc(sizeof(WCHAR) * (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1));
    srv_fmgr_fileinfo_create(filepath, &file_info_handle);
    srv_fmgr_fileinfo_get_name(file_info_handle, file_name, (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * sizeof(WCHAR));
    srv_fmgr_fileinfo_destroy(file_info_handle);
    if(mmi_thm_dlt_activate_from_fmgr((CHAR*)filepath, (CHAR*)file_name, MMI_FALSE) == 0)
	{
		mmi_thm_dlt_display_theme_popup((CHAR*)filepath);
	}
    OslMfree(file_name);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_theme_fmgr_active_group_proc
 * DESCRIPTION
 *  Generate the menus.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_theme_fmgr_active_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
        {
            break;
        }    
        default:
        {
            break;
        }
    }
    return MMI_RET_OK;        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_thm_drv_format_hdlr
 * DESCRIPTION
 *  hide extension file name
 * PARAMETERS
 *  drv_letter         [IN]	Filemgr notify
 * RETURNS
 *  BOOL
 *****************************************************************************/
void mmi_thm_drv_format_hdlr(CHAR drv_letter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 theme_id;
    U8 total_thm;
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    theme_id = mmi_tm_get_current_theme_id();
    total_thm = mmi_tm_get_total_themes_count();

    for (i = 0; i < total_thm; i++)
    {
        if (theme_id == thm_details[i].theme_id)
        {
            if (thm_details[i].drv_letter == drv_letter)
            {
                ActivateDefaultTheme();
            }
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_thm_is_file_exist
 * DESCRIPTION
 *  To check if file is already exist
 * PARAMETERS
 *  file_path_name      [IN]        File path and name
 * RETURNS
 *  TURE of file exists; otherwise FALSE.
 *****************************************************************************/
static MMI_BOOL mmi_thm_is_file_exist(CHAR *file_path_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if file already exist */
    fh = FS_Open((U16*) file_path_name, FS_READ_ONLY);

    if (fh > 0)
    {
        FS_Close(fh);
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_thm_folder_check
 * DESCRIPTION
 *  To check whether this 
 * PARAMETERS
 *  CHAR*			    [IN]		path
 * RETURNS
 *  BOOL
 *****************************************************************************/
static BOOL mmi_thm_is_theme_folder(CHAR* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16* upper_ptr;
    U8* tmp_str;
    U16 len;
	BOOL ret = FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(path != NULL);
    
    len = mmi_ucs2strlen(path);
    tmp_str = OslMalloc((len + 2) * ENCODING_LENGTH);
    mmi_ucs2cpy((CHAR*)tmp_str, path);
    upper_ptr = mmi_wcsupr((U16*)tmp_str);
    if (mmi_ucs2str((CHAR*)upper_ptr, (CHAR*)L"THEMES"))
    {
    	ret = TRUE;
	}
	OslMfree(tmp_str);
	return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_thm_folder_check
 * DESCRIPTION
 *  To check whether this 
 * PARAMETERS
 *  CHAR*			    [IN]		path
 * RETURNS
 *  BOOL
 *****************************************************************************/
static MMI_BOOL mmi_thm_is_dlt_theme(U32 theme_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 theme_type = 0;
	U8 i;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (i = 0; i < TOTAL_THEMES_COUNT; i++)
	{
		if (g_tm_theme_list[i].theme_id == theme_id)
		{
			theme_type = g_tm_theme_list[i].theme_type;
			break;
		}
	}

	if (i == TOTAL_THEMES_COUNT)
	{
		return MMI_FALSE;
	}
	
	if (theme_type == THEME_TYPE_DOWNLOADED_PHONE || theme_type == THEME_TYPE_DOWNLOADED_CARD)
	{
		return MMI_TRUE;
	}
	else
	{
		return MMI_FALSE;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_theme_notify_hdlr
 * DESCRIPTION
 *  hide extension file name
 * PARAMETERS
 *  notify_flag     [IN]	Filemgr notify
 *	para			[IN]	path struct
 * RETURNS
 *  BOOL
 *****************************************************************************/
mmi_ret mmi_fmgr_theme_notify_hdlr(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 flag;
    srv_fmgr_notification_format_event_struct *format;
    srv_fmgr_notification_adv_action_event_struct *adv_action;
    srv_fmgr_notification_dev_plug_event_struct *dev_plug;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(para != NULL);
    switch(para->evt_id)
    {
        case EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT:
        {
            format = (srv_fmgr_notification_format_event_struct*)para;
            mmi_thm_drv_format_hdlr((CHAR)format->drv_letter);
            break;
        }
        case EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION:
        {
            adv_action = (srv_fmgr_notification_adv_action_event_struct*)para;            
            if(adv_action->state == SRV_FMGR_NOTIFICATION_STATE_QUERY)
            {            
                if(!(adv_action->src_fileinfo.attribute & FS_ATTR_DIR))
                {
                    flag = mmi_thm_dlt_get_path_location((CHAR*)adv_action->src_filepath);
                    if(flag)
                    {
                    	CHAR* filename = (CHAR*)srv_fmgr_path_get_filename_ptr((WCHAR*)adv_action->src_filepath);
                    	if (mmi_tm_is_theme_activated(flag, filename))
	                	{
	                	    return MMI_RET_ERR;
	                	}
						else
						{
						    return MMI_RET_OK;
						}
                    }
                }
                else
                {
                    if (mmi_thm_is_theme_folder((CHAR*)adv_action->src_filepath) &&
						mmi_thm_is_dlt_theme(g_thm_cntx.CurrTheme))
            	    {
            	        return MMI_RET_ERR;
            	    }
				    else
				    {
						return MMI_RET_OK;
				    }
                }
            }
            else if(adv_action->state == SRV_FMGR_NOTIFICATION_STATE_AFTER)
            {
                if (SRV_FMGR_NOTIFICATION_ACTION_MOVE == adv_action->action ||
                    SRV_FMGR_NOTIFICATION_ACTION_DELETE == adv_action->action)
                {
                    if(!(adv_action->src_fileinfo.attribute & FS_ATTR_DIR))
                    {
                        flag = mmi_thm_dlt_get_path_location((CHAR*)adv_action->src_filepath);
                        if(flag)
                        {
                            mmi_tm_delete_theme_from_fmgr((tm_theme_type_enum)flag, (U8*)srv_fmgr_path_get_filename_ptr((WCHAR*)(adv_action->src_filepath)), NULL);
                        }
                    }
                }
            }
            break;
        }
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        {
            dev_plug = (srv_fmgr_notification_dev_plug_event_struct*)para;
            mmi_thm_card_plug_out_hdlr(dev_plug);
            break;
        }
    }
    return MMI_RET_OK;
}


#define MMI_THEME_IRDA_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_ta_thmgr_hide_ext_name
 * DESCRIPTION
 *  hide extension file name
 * PARAMETERS
 *  file_name_p     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ta_thmgr_hide_ext_name(CHAR *file_name_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* find ext name - by finding "." */
    S32 str_len;
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_len = mmi_ucs2strlen(file_name_p);
    index = (str_len - 1) * ENCODING_LENGTH;

    while (index > 0)
    {
        if (mmi_ucs2ncmp((CHAR*) & file_name_p[index], (CHAR*) L".", 1) == 0)
        {
            file_name_p[index] = '\0';
            file_name_p[index + 1] = '\0';
            break;
        }

        file_name_p[index] = '\0';
        file_name_p[index + 1] = '\0';
        index -= 2;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ta_check_if_file_alrdy_exist_in_fm
 * DESCRIPTION
 *  Check if file Already exists in File manager.
 * PARAMETERS
 *  file_path       [IN]        
 *  file_name       [IN]        
 *  CHAR* file name and file path(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ta_check_if_file_alrdy_exist_in_fm(CHAR* file_path, CHAR* file_name)
{
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_theme_v2_notify_hdlr
 * DESCRIPTION
 *  Check if file Already exists in File manager.
 * PARAMETERS
 *  file_path       [IN]        
 *  file_name       [IN]        
 *  CHAR* file name and file path(?)
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_fmgr_theme_v2_notify_hdlr(U32 notify_flag, void* para)
{
    return TRUE;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_theme_fmgr_use_enabler
 * DESCRIPTION
 *  Forward a vCalendar object from file manager via SMS
 * PARAMETERS
 *  path        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_theme_fmgr_use_enabler(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_theme_fmgr_use_enabler
 * DESCRIPTION
 *  Forward a vCalendar object from file manager via SMS
 * PARAMETERS
 *  path        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_theme_fmgr_use_handler(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmgr_theme_activate_hdlr();
}


#endif /* __MMI_THEMES_V2_SUPPORT__ */

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef __MMI_TOUCH_SCREEN__

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_thm_tap_url_callback
 * DESCRIPTION
 *  when tap url of downloadble theme, trigger goto function.
 * PARAMETERS
 *  mmi_tap_type_enum   [IN] tap type.
 *  S32                 [IN] item index.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_thm_tap_url_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (recent_url_list.total_entries != 0) /* has customized url */
    {
        if (tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM)
        {
            // only change the highlight
            return;
        }
    }
    
    if (index == 0)
    {
        mmi_thm_entry_input_address();
    }
    else 
    {
        mmi_thm_goto_url();
    }
    
}
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_thm_tap_list_callback
 * DESCRIPTION
 *  tap on theme list, activate it.
 * PARAMETERS
 *  mmi_tap_type_enum   [IN] tap type.
 *  S32                 [IN] item index.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_thm_tap_list_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM)
    {
        // only change the highlight
        return;
    } 
    ActivateTheme();
}
#endif /* __MMI_TOUCH_SCREEN__ */

#endif /* __MMI_THEMES_APPLICATION__ */

