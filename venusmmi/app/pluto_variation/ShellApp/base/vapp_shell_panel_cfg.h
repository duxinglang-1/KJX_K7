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
 *  vapp_shell_panel_cfg.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Shell Screen component configuration file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_SHELL_SCR_CP_CFG_H__
#define __VAPP_SHELL_SCR_CP_CFG_H__

#include "MMI_features.h"

#ifdef __MMI_VUI_SHELL_APP__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_object.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vapp_shell_panel.h"
#include "vapp_hs_scr.h"
#include "vapp_shell_msg_viewer.h"
#include "vapp_shell_mediaplayer.h"
#include "vapp_shell_imageviewer.h"
#include "vapp_shell_recent_calls.h"
#include "vapp_shell_settings.h"
#include "vapp_shell_fc.h"
#include "vapp_op01_hs_scr.h"
#include "vapp_shell_shortcuts.h"

/* resource header */
#include "mmi_rp_app_shellapp_base_def.h" 
#ifdef __MMI_VUI_SHELL_FAV_CONTACT__  
#include "mmi_rp_app_venus_shell_fc_def.h"
#endif
#ifdef __MMI_VUI_SHELL_IMAGE_VIEWER__
#include "mmi_rp_app_venus_shell_iv_def.h"
#endif
#include "mmi_rp_app_venus_shell_mediaplayer_def.h"
#if defined(__MMI_VUI_SHELL_MSG_VIEWER__)
#include "mmi_rp_app_venus_shell_msg_viewer_def.h"
#endif
#if defined(__MMI_VUI_SHELL_RECENT_CALLS__)
#include "mmi_rp_app_venus_shell_recent_calls_def.h"
#endif
#ifdef __MMI_VUI_SHELL_MULTI_PAGE__
#include "mmi_rp_app_venus_shell_settings_def.h"
#endif
#ifdef __MMI_VUI_SHELL_SHORTCUTS__
#include "mmi_rp_app_venus_shell_shortcuts_def.h"
#endif
#ifdef __MMI_VUI_SHELL_OP01_HOMESCREEN__
#include "mmi_rp_app_venus_shell_op01_hs_def.h"
#endif


/***************************************************************************** 
 * Enum
 *****************************************************************************/
/* please register one id to identify yourself */

typedef enum
{
    VAPP_SHELL_PANEL_SHORTCUTS,
    VAPP_SHELL_PANEL_IMAGE_VIEWER,
    VAPP_SHELL_PANEL_FAV_CONTACT,
    VAPP_SHELL_PANEL_HOME,
    VAPP_SHELL_PANEL_OP01_HOME = VAPP_SHELL_PANEL_HOME,
    VAPP_SHELL_PANEL_MSG_VIEWER,
    VAPP_SHELL_PANEL_MEDIA_PLAYER,
    VAPP_SHELL_PANEL_RECENT_CALLS,
    VAPP_SHELL_PANEL_SETTINGS,
    VAPP_SHELL_PANEL_ID_TOTAL
} vapp_shell_panel_id_enum;


typedef VappShellPanel *(*vapp_shell_panel_create_funcptr_type)(VfxObject *parent);

/***************************************************************************** 
 * Structure
 *****************************************************************************/
typedef struct
{
    vapp_shell_panel_id_enum             panel_id;
    VfxS32                               str_id;
    VfxS32                               img_id;    // image id in set Order
    VfxBool                              switchable;// whether can be hide
    vapp_shell_panel_create_funcptr_type func_ptr;
} vapp_shell_panel_tbl_struct;

/***************************************************************************** 
 * Extern
 *****************************************************************************/
extern vapp_shell_panel_tbl_struct g_vapp_shell_panel_create_tbl[];

/***************************************************************************** 
 * Define
 *****************************************************************************/
#if defined(SHELL_CP_DEFINE_IN_SCR)
#define VAPP_SHELL_PANEL_TABLE        vapp_shell_panel_tbl_struct g_vapp_shell_panel_create_tbl[] =
#define VAPP_SHELL_NEW_PANEL(_class)  _class##::createShellPanel
#define VAPP_SHELL_PANEL_ITEM(_id, _strId, _imgId, _switchable, _class) {_id, _strId, _imgId, _switchable, _class}
#define VAPP_SHELL_PANEL_LAST_ITEM    {VAPP_SHELL_PANEL_ID_TOTAL, NULL}
#define VAPP_SHELL_PANEL_TOTAL        (sizeof(g_vapp_shell_panel_create_tbl) / sizeof(vapp_shell_panel_tbl_struct) - 1)

#else /* defined(SHELL_CP_DEFINE_IN_SCR) */
#define VAPP_SHELL_PANEL_TABLE        enum
#define VAPP_SHELL_NEW_PANEL(_class)
#define VAPP_SHELL_PANEL_ITEM(_id, _strId, _imgId, _switchable, _class) VAPP_SHELL_CP_ENUM_##_id
#define VAPP_SHELL_PANEL_LAST_ITEM VAPP_SHELL_PANEL_TOTAL          

#endif /* !defined(SHELL_CP_DEFINE_IN_SCRR) */

#if !defined(__MMI_VUI_SHELL_MULTI_PAGE__)
#define VAPP_SHELL_IMG_SETTINGS_HOME    1
#define VAPP_SHELL_STR_HOME_TITLE      2
#endif /* !defined(__MMI_VUI_SHELL_MULTI_PAGE__) */

/***************************************************************************** 
 * Shell component table
 *****************************************************************************/

/* PLEASE PAY ATTENTION: 
 * The order you put here in the table will decide the initalize panel order.
 * This order can be changed later through setting panel.
 */
VAPP_SHELL_PANEL_TABLE
{
#ifdef __MMI_VUI_SHELL_SHORTCUTS__
    /* Shortcut ==> please put shortcut item under this comment */
    VAPP_SHELL_PANEL_ITEM(VAPP_SHELL_PANEL_SHORTCUTS,  
                          STR_ID_SHELL_SHORTCUTS_TITLE,
                          VAPP_SHELL_IMG_SETTINGS_SHORTCUTS,
                          VFX_TRUE,
                          VAPP_SHELL_NEW_PANEL(VappShellShctScr)),
#endif /* __MMI_VUI_SHELL_SHORTCUTS__ */
#ifdef __MMI_VUI_SHELL_IMAGE_VIEWER__
    /* Image viewer ==> please put image viewer item under this comment */
    VAPP_SHELL_PANEL_ITEM(VAPP_SHELL_PANEL_IMAGE_VIEWER,   
                          VAPP_SHELL_STR_IMAGE_VIEWER_TITLE,
                          VAPP_SHELL_IMG_SETTINGS_IMAGE,
                          VFX_TRUE,                          
                          VAPP_SHELL_NEW_PANEL(VappShellIVPanel)),
#endif                          
#ifdef __MMI_VUI_SHELL_FAV_CONTACT__
    /* Fav contact ==> please put Fav contact item under this comment */
    VAPP_SHELL_PANEL_ITEM(VAPP_SHELL_PANEL_FAV_CONTACT, 
                          VAPP_SHELL_FC_STR_FC,
                          VAPP_SHELL_IMG_SETTINGS_FAV_CONT,
                          VFX_FALSE,
                          VAPP_SHELL_NEW_PANEL(VappShellFCFrame)),
#endif /* __MMI_VUI_SHELL_FAV_CONTACT__ */                     
    /* Home ==> please put home item under this comment */
#if defined(__MMI_VUI_HOMESCREEN__)
    VAPP_SHELL_PANEL_ITEM(VAPP_SHELL_PANEL_HOME, 
                          VAPP_SHELL_STR_HOME_TITLE,
                          VAPP_SHELL_IMG_SETTINGS_HOME, 
                          VFX_FALSE,
                          VAPP_SHELL_NEW_PANEL(VappHsScr)),
#endif /* defined(__MMI_VUI_HOMESCREEN__) */
#ifdef __MMI_VUI_SHELL_OP01_HOMESCREEN__
    /* OP01 homescreen ==> please put OP01 homescreen item under this comment */
    VAPP_SHELL_PANEL_ITEM(VAPP_SHELL_PANEL_OP01_HOME, 
                          VAPP_SHELL_STR_HOME_TITLE,
                          VAPP_SHELL_IMG_SETTINGS_HOME,
                          VFX_FALSE,
                          VAPP_SHELL_NEW_PANEL(VappOp01HsScr)),
#endif /* __MMI_VUI_SHELL_OP01_HOMESCREEN__ */
#if defined(__MMI_VUI_SHELL_MSG_VIEWER__)
    /* SMS Viewer ==> please put home item under this comment */
    VAPP_SHELL_PANEL_ITEM(VAPP_SHELL_PANEL_MSG_VIEWER,
                          STR_ID_SHELL_MSG_VIEWER_TITLE,
                          VAPP_SHELL_IMG_SETTINGS_MSG_VIEWER,
                          VFX_FALSE,
                          VAPP_SHELL_NEW_PANEL(VappShellMsgViewer)),
#endif

#if defined(__MMI_VUI_SHELL_MEDIA_PLAYER__)
    /* Media Player ==> please put home item under this comment */
    VAPP_SHELL_PANEL_ITEM(VAPP_SHELL_PANEL_MEDIA_PLAYER,   
                          STR_ID_SHELL_MEDIAPLAYER_TITLE,
                          VAPP_SHELL_IMG_SETTINGS_MUSIC,
                          VFX_TRUE,
                          VAPP_SHELL_NEW_PANEL(VappShellMediaplayer)),
#endif

#if defined(__MMI_VUI_SHELL_RECENT_CALLS__)
    /* Recent Calls ==> please put home item under this comment */
    VAPP_SHELL_PANEL_ITEM(VAPP_SHELL_PANEL_RECENT_CALLS, 
                          VAPP_SHELL_STR_RECENT_CALLS,
                          VAPP_SHELL_IMG_SETTINGS_RECENT_CALL,
                          VFX_TRUE,
                          VAPP_SHELL_NEW_PANEL(VappShellRC)),
#endif /* defined(__MMI_VUI_SHELL_RECENT_CALLS__) */
#if defined(__MMI_VUI_SHELL_SETTINGS__)
    /* Settings ==> please put home item under this comment */
    VAPP_SHELL_PANEL_ITEM(VAPP_SHELL_PANEL_SETTINGS,
                          VAPP_SHELL_STR_SETTINGS_TITLE_TEXT,
                          VAPP_SHELL_IMG_SETTINGS_SETTING,
                          VFX_FALSE,
                          VAPP_SHELL_NEW_PANEL(VappShellSettingsScr)),
#endif /* defined(__MMI_VUI_SHELL_SETTINGS__) */
    VAPP_SHELL_PANEL_LAST_ITEM
};


#endif /* __MMI_VUI_SHELL_APP__ */
#endif /* ___VAPP_SHELL_SCR_CP_CFG_H__ */

