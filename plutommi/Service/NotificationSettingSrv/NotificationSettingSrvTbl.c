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
 * NotificationSettingSrvTbl.c
 *
 * Project:
 * --------
 * MAUI  
 *
 * Description:
 * ------------
 * NSS (Notification setting service) static native table
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/***************************************************************************** 
 * Include 
 *****************************************************************************/
     
#include "GlobalResDef.h"
#include "NotificationSettingSrvGprot.h"
#include "NotificationSettingSrv.h"

#ifdef __MMI_NSS_SUPPORT__
 
#ifdef __PLUTO_MMI_PACKAGE__
#include "mmi_rp_app_mainmenu_def.h"
#include "mmi_rp_app_unifiedmessage_def.h"
#include "mmi_rp_app_calllog_def.h"
#include "mmi_pluto_res_range_def.h"

#ifdef __MMI_UM_SLIM__
#include "mmi_rp_app_sms_def.h"
#endif	 /*__MMI_UM_SLIM__*/ 

#ifdef __MMI_DOWNLOAD_AGENT__
#include "mmi_rp_app_downloadagent_def.h"
#endif

#if defined(__MMI_PROV_MESSAGE_SUPPORT__) 
#include "mmi_rp_app_provbox_def.h"
#endif

#ifdef __MMI_EMAIL__
#include "mmi_rp_app_email_def.h"
#endif
#ifdef __SOCIAL_NETWORK_SUPPORT__
#include "mmi_rp_app_sns_def.h"
#endif
#endif
#ifdef __COSMOS_MMI_PACKAGE__
#include "mmi_rp_vapp_msg_def.h"
#include "mmi_rp_vapp_calllog_def.h"
#include "mmi_rp_vapp_dlagent_def.h"
#ifdef __MMI_EMAIL__
#include "mmi_rp_vapp_email_def.h"
#endif
#ifdef __SOCIAL_NETWORK_SUPPORT__
#include "mmi_rp_vapp_sns_def.h"
#endif
#endif

#ifndef __MTK_TARGET__
MMI_ID g_test_native_alias_id[] = {(g_test_native_app_id-10), 
                                            (g_test_native_app_id+3), 
                                            (g_test_native_app_id+5), 
                                            (g_test_native_app_id+8), 
                                            0xffff, 0x0};//End with 0xffff, 0x0
#endif 

#ifdef __PLUTO_MMI_PACKAGE__
#if defined(__MMI_PROV_MESSAGE_SUPPORT__)
    #ifdef __MMI_CCA_SUPPORT__
		
	MMI_ID g_pluto_unified_message_alias_id[] = {APP_PROVBOX, APP_CCA,
	#ifdef __WAP_PUSH_SUPPORT__
												APP_MMI_WAP_PUSH,
	#endif
                                            0xffff, 0x0};//End with 0xffff, 0x0
		
		
    #else
    MMI_ID g_pluto_unified_message_alias_id[] = {APP_PROVBOX, 
		
	#ifdef __WAP_PUSH_SUPPORT__
												APP_MMI_WAP_PUSH,
	#endif
                                            0xffff, 0x0};//End with 0xffff, 0x0
    #endif                                            
#else
    #ifdef __MMI_CCA_SUPPORT__
    MMI_ID g_pluto_unified_message_alias_id[] = {APP_CCA, 
	#ifdef __WAP_PUSH_SUPPORT__
												APP_MMI_WAP_PUSH,
	#endif
                                            0xffff, 0x0};//End with 0xffff, 0x0
    #else
    MMI_ID g_pluto_unified_message_alias_id[] = {
	#ifdef __WAP_PUSH_SUPPORT__
												APP_MMI_WAP_PUSH,
	#endif
                                            0xffff, 0x0};//End with 0xffff, 0x0
    #endif
#endif                                            
#endif

/*Struct of native nss table*/
/*
* App id : the application identity, noted that NSS will use this field for finding app
* Application type : this value should be NATIVE_APP_TYPE in the static table
* Notification setting : the setting value, you can use 1. NSS_SETTING_DEFAULT or 2. Use NSS_FILL_SETTING_VALUE marco to fill the setting you want 
* Notification setting : the mask value, you can use 1. NSS_MASK_DEFAULT or 2. (NSS_MASK_BADGE_ICON | NSS_MASK_SOUND | 
*                                 NSS_MASK_LOCK_SCRN | NSS_MASK_NCENTER | NSS_MASK_ALERT) (Noted. only the masked value can be configured)
* String id : for retrieving the display name
* Image id : for retrieving the image icon   
* Alias idrange :the range of alias app id, Ex. if the range = 10,  when user try to query NSS setting by 
*                       app_id ~ app_id+10, we will give them the same app's setting 
*/
const mmi_srv_nss_node g_native_nss_table[]={
#ifdef __PLUTO_MMI_PACKAGE__
    {
        APP_UNIFIEDMESSAGE, 
        NATIVE_APP_TYPE,
        NSS_SETTING_DEFAULT,
        NSS_MASK_DEFAULT,
        MAIN_MENU_MESSAGES_TEXT, 
    #ifdef __MMI_UM_SLIM__
	    IMG_MESSAGE_UNREAD,
	#else    
        IMG_UM_MAIN_ID,
    #endif   /*__MMI_UM_SLIM__*/ 
        g_pluto_unified_message_alias_id        
    },
    {
        APP_CALLLOG,
        NATIVE_APP_TYPE,
        NSS_SETTING_DEFAULT,
        NSS_MASK_DEFAULT_NO_ALERT_NO_SOUND,
        STR_ID_CLOG_CALL_LOG,
        IMG_ID_CLOG_MAIN_ICON,
        NULL        
    }, 
    #ifdef __MMI_EMAIL__
    {
        APP_EMAIL,
        NATIVE_APP_TYPE,        
        NSS_SETTING_DEFAULT,
        NSS_MASK_DEFAULT,
        STR_GLOBAL_EMAIL,
        IMG_EMAIL_MAIN_ID,
        NULL        
    },
    #endif/*__MMI_EMAIL__*/
    #ifdef __MMI_SNS_CENTER__
    {
        APP_SNS, 
        NATIVE_APP_TYPE,
        NSS_FILL_SETTING_VALUE( SETTING_BADGE_DEFAULT,SETTING_OFF, SETTING_NCENTER_DEFAULT, SETTING_LOCK_SCRN_DEFAULT,  ALERT_TYPE_DEFAULT),
        (NSS_MASK_DEFAULT_NO_ALERT_NO_SOUND | NSS_MASK_SOUND),   
        STR_ID_SNS_CENTER,          
        IMG_ID_SNS_APP, 
        NULL        
    },
    #endif/*__MMI_SNS_CENTER__*/
	#ifdef __MMI_DOWNLOAD_AGENT__
    {
        APP_DOWNLOADAGENT, 
        NATIVE_APP_TYPE,
        NSS_SETTING_DEFAULT,
         (
        #ifdef __MMI_NCENTER_SUPPORT__
        NSS_MASK_NCENTER |
        #endif
        NSS_MASK_ALERT |
        NSS_MASK_SOUND),   
#ifndef __MMI_DA_CONF_PAGE_SLIM__
        STR_ID_DA_DOWNLOADS,          
        IMG_ID_DA_DOWNLOAD_ICON, 
#else
	0,
	0,
#endif
        NULL        
    },
    #endif  /*__MMI_DOWNLOAD_AGENT__*/
    #ifndef __MTK_TARGET__
    //Create for test
    {
        g_test_native_app_id, 
        NATIVE_APP_TYPE,
        NSS_SETTING_DEFAULT,
        NSS_MASK_DEFAULT,   
        g_test_native_app_str_id,          
        g_test_native_app_str_id, 
        g_test_native_alias_id
    }
    #endif/*__MTK_TARGET__*/
#endif/*__PLUTO_MMI_PACKAGE__*/

#ifdef __COSMOS_MMI_PACKAGE__
    {
        VAPP_MSG,
        NATIVE_APP_TYPE,
        NSS_SETTING_DEFAULT,
        NSS_MASK_DEFAULT,
        STR_ID_VAPP_MSG,                
        IMG_ID_VAPP_MSG_MAIN,
        NULL        
    },
    {
        VAPP_CALLLOG, 
        NATIVE_APP_TYPE,
        NSS_SETTING_DEFAULT,
        NSS_MASK_DEFAULT_NO_ALERT_NO_SOUND,   
        STR_ID_VAPP_CLOG,          
        IMG_ID_VAPP_CLOG_MAIN_MENU,
        NULL        
    },
    #ifdef __MMI_EMAIL__
    {
        VAPP_EMAIL, 
        NATIVE_APP_TYPE,
        NSS_SETTING_DEFAULT,
        NSS_MASK_DEFAULT,
        STR_EMAIL_FTO_EMAIL,
        IMG_EMAIL_FTO_MAINMENU,
        NULL        
    },
    #endif/*__MMI_EMAIL__*/
    #ifdef __SOCIAL_NETWORK_SUPPORT__
    {
        VAPP_SNS,
        NATIVE_APP_TYPE,
        NSS_FILL_SETTING_VALUE( SETTING_BADGE_DEFAULT,SETTING_OFF, SETTING_NCENTER_DEFAULT, SETTING_LOCK_SCRN_DEFAULT,  ALERT_TYPE_DEFAULT),
        (NSS_MASK_DEFAULT_NO_ALERT_NO_SOUND | NSS_MASK_SOUND),
        STR_ID_VAPP_SNS,          
        IMG_ID_VAPP_SNS_MAINMENU_ICN,
        NULL        
    },
    #endif/*__SOCIAL_NETWORK_SUPPORT__*/
    #ifdef __MMI_DOWNLOAD_AGENT__
     {
        VAPP_DLAGENT,
        NATIVE_APP_TYPE,
        NSS_SETTING_DEFAULT,
        (
        #ifdef __MMI_NCENTER_SUPPORT__
        NSS_MASK_NCENTER |
        #endif
        NSS_MASK_ALERT |
        NSS_MASK_SOUND),
        VAPP_STR_DLA_DOWNLOAD_AGENT,
        VAPP_IMG_ID_DLA_MAIN_ICON,
        NULL        
    },
    #endif /*__MMI_DOWNLOAD_AGENT__*/
    #ifndef __MTK_TARGET__
    //Create for test
    {
        g_test_native_app_id, 
        NATIVE_APP_TYPE,
        NSS_SETTING_DEFAULT,
        NSS_MASK_DEFAULT,   
        g_test_native_app_str_id,          
        g_test_native_app_str_id, 
        g_test_native_alias_id
    }
    #endif/*__MTK_TARGET__*/
#endif/*__COSMOS_MMI_PACKAGE__*/
};

U32 srv_notification_setting_get_native_table_size(void)
{
    return sizeof(g_native_nss_table)/sizeof(mmi_srv_nss_node);
}

#endif /*__MMI_NSS_SUPPORT__*/
