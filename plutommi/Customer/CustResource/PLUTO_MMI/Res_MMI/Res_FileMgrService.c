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
#ifdef __PLUTO_MMI_PACKAGE__

#include "MMI_features.h" 

#if defined(__MMI_FILE_MANAGER__)
#include "MMIDataType.h"    /* for resource base */
#include "GDI_include.h"

#include "CustResDef.h"         /* for image/audio path */
#include "CustDataProts.h"      /* for resource generator API */
#include "GlobalMenuItems.h"    /* for menu resource */

/****************************************************************************/

#include "FileMgrServiceResDef.h"
#include "mmi_rp_app_filemanager_def.h"
/****************************************************************************/
/* include your OWN RESOURCE ID here. */

//#include "MMIThemesResDef.h"
#include "Mmi_rp_srv_mmi_theme_def.h"
#ifdef __MMI_MMS_2__
#include "mmi_rp_srv_mms_def.h"
#endif

#ifdef __MMI_EBOOK_READER__
#include "mmi_rp_app_ebook_def.h"
#endif
#include "PhoneBookResDef.h"
#include "SettingResDef.h"

#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
#include "mmi_rp_app_font_manager_def.h"
#endif
#include "mmi_rp_app_profiles_def.h"
#include "mmi_rp_app_phonebook_def.h"

#ifdef __MMI_PHOTOEDITOR__
#include "mmi_rp_app_phoedt_def.h"
#endif

#ifdef __MMI_IMAGE_VIEWER__
#include "mmi_rp_app_imageviewer_def.h"
#endif

#ifndef __COSMOS_MMI_PACKAGE__
#ifdef __MMI_SMS_APP_EMS_SUPPORT__
#include "mmi_rp_app_sms_def.h"
#endif
#endif

#ifdef __MMI_UDX_SUPPORT__
#include "mmi_rp_app_udx_def.h"
#endif

#ifdef __MMI_VCALENDAR__
#include "mmi_rp_srv_vcalendar_def.h"
#endif

#ifdef __CERTMAN_SUPPORT__
#include "mmi_rp_app_mmi_certman_def.h"
#endif /* __CERTMAN_SUPPORT__ */

#ifdef __J2ME__
#include "mmi_rp_app_java_def.h"
#endif

#include "mmi_rp_srv_wallpaper_def.h"
#include "mmi_rp_srv_screensaver_def.h"
#include "mmi_rp_srv_phnset_onoff_def.h"
/****************************************************************************/

#ifdef __MMI_SUB_WALLPAPER__
#define FMGR_COMMON_FWD_IMAGE_SUB_WALLPAPER \
    MENU_ID_FMGR_FWD_SUB_WALLPAPER,
#else
#define FMGR_COMMON_FWD_IMAGE_SUB_WALLPAPER
#endif

#ifdef __MMI_POWER_ON_OFF_DISPLAY__
#define FMGR_COMMON_FWD_IMAGE_POWER_ONOFF \
    MENU_ID_FMGR_FWD_POWER_ON, \
    MENU_ID_FMGR_FWD_POWER_OFF,
#else
#define FMGR_COMMON_FWD_IMAGE_POWER_ONOFF
#endif
#ifdef __MMI_OPP_SUPPORT__
#include "mmi_rp_app_bluetooth_def.h"
#endif

#include "gdi_features.h"
/****************************************************************************/





/****************************************************************************/

#if !defined (__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
#define FMGR_COMMON_FWD_SMS     MENU_ID_FMGR_FWD_SMS,
#else
#define FMGR_COMMON_FWD_SMS
#endif

#ifdef __MMI_MMS__
#define FMGR_COMMON_FWD_MMS     MENU_ID_FMGR_FWD_MMS,
#else
#define FMGR_COMMON_FWD_MMS
#endif

#if defined(__MMI_MMS_2__) && defined(__MMI_OP11_MMS_SEND_TO_PHOTO_BLOG__)
/* under construction !*/
#else
#define FMGR_COMMON_FWD_TO_BLOG
#endif
#if defined(__MMI_MMS_2__) && defined(__MMI_MMS_POSTCARD__)
#define FMGR_COMMON_FWD_TO_POSTCARD     MENU_ID_UMMS_FMGR_SEND_TO_POSTCARD,
#else
#define FMGR_COMMON_FWD_TO_POSTCARD
#endif


#ifdef __MMI_EMAIL__
#define FMGR_COMMON_FWD_EMAIL   MENU_ID_FMGR_FWD_EMAIL,
#else
#define FMGR_COMMON_FWD_EMAIL
#endif

#ifdef __MMI_IRDA_SUPPORT__
#define FMGR_COMMON_FWD_IRDA    MENU_ID_FMGR_FWD_IRDA,
#else
#define FMGR_COMMON_FWD_IRDA
#endif

/* Bluetooth sending API revise */
#ifdef __MMI_OPP_SUPPORT__
#define FMGR_COMMON_FWD_BT      MENU_ID_FMGR_FWD_BT,
#else
#define FMGR_COMMON_FWD_BT
#endif


#if defined(__MMI_SNS_PHOTO_UPLOAD__) && defined(__MMI_IMAGE_VIEWER__)
#define FMGR_COMMON_FWD_SNS_PHOTO_UPLOAD    MENU_ID_FMGR_FWD_SNS_PHOTO_UPLOAD,
#else
#define FMGR_COMMON_FWD_SNS_PHOTO_UPLOAD
#endif

/****************************************************************************/

//#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "PopulateRes.h"

void PopulateFileMgrServMenuRes(void)
{
    /************************************************************/
    /*                                                          */
    /*          Forward Option                                  */
    /*                                                          */
    /************************************************************/

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_GEN_SEND_OPTION, 0,
        FMGR_COMMON_FWD_MMS
        FMGR_COMMON_FWD_EMAIL
        FMGR_COMMON_FWD_IRDA
        FMGR_COMMON_FWD_BT
        MENU_ITEM_END,
        SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, STR_GLOBAL_SEND,0));


    /* Phonebook */
    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_FWD_CONTACT,         0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_ID_FMGR_FWD_CONTACT,0));

#ifdef __MMI_BG_SOUND_EFFECT__
    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_FWD_BGSOUND,         0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_FMGR_BGSOUND,0));
#endif

    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_FWD_SMS,             0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_AS_TEXT_MESSAGE,0));
#ifdef __MMI_MMS__
    //ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_FWD_MMS,             0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_AS_MULTIMEDIA_MSG,0));
#ifdef __MMI_MMS_2__
#ifdef __MMI_OP11_MMS_SEND_TO_PHOTO_BLOG__
/* under construction !*/
#endif
#ifdef __MMI_MMS_POSTCARD__
    //ADD_APPLICATION_MENUITEM((MENU_ID_UMMS_FMGR_SEND_TO_POSTCARD,          0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_FMGR_UMMS_TO_POSTCARD,0));
#endif
#endif
#endif
#ifdef __MMI_IRDA_SUPPORT__
    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_FWD_IRDA,            0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_VIA_INFRARED,0));
#endif
#ifdef __MMI_BT_SUPPORT__
    //ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_FWD_BT,              0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_VIA_BLUETOOTH,0));
#endif
#ifdef __MMI_EMAIL__
    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_FWD_EMAIL,           0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_AS_EMAIL,0));
#endif
#if defined(__MMI_FMGR_MULTI_SELECT_SUPPORT__) && defined(__MMI_OPP_SUPPORT__)
    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_MARK_OPTION_TO_BT,   0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_ID_FMGR_MARK_TO_BT,  0));        
#endif

#if (defined(__MMI_PICT_BRIDGE_SUPPORT__) || defined(__MMI_BPP_SUPPORT__)) && (defined(__MMI_IMAGE_VIEWER_EX__))
    ADD_APPLICATION_MENUITEM2((MENU_ID_FMGR_IMG_OPTION_PRINT,0,
#if defined(__MMI_PICT_BRIDGE_SUPPORT__)
        MENU_ID_FMGR_PRINT_PICTBRIGE,
#endif
#if defined(__MMI_BPP_SUPPORT__)
        MENU_ID_FMGR_PRINT_BLUETOOTH,
#endif
        MENU_ITEM_END,
        SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, STR_GLOBAL_PRINT,0));
#endif

#if defined(__MMI_PICT_BRIDGE_SUPPORT__)
    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_PRINT_PICTBRIGE,     0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_ID_FMGR_TO_PICTBRIGE,0));
#endif
#if defined(__MMI_BPP_SUPPORT__)
    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_PRINT_BLUETOOTH,     0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_VIA_BLUETOOTH,0));
#endif

    /************************************************************/
    /*                                                          */
    /*          File Type Option                                */
    /*                                                          */
    /************************************************************/

    /********************* Image files *********************************/

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_IMG_TYPE_OPTIONS,0,
#if defined(__MMI_IMAGE_VIEWER__)
        MENU_ID_IMGVIEW_OPTION_IMG_VIEW,
#endif        
#if (defined(__MMI_PICT_BRIDGE_SUPPORT__) || defined(__MMI_BPP_SUPPORT__)) && (defined(__MMI_IMAGE_VIEWER_EX__))
        MENU_ID_FMGR_IMG_OPTION_PRINT,
#endif
#if defined(__MMI_IMAGE_VIEWER__)
        MENU_ID_IMGVIEW_OPTION_IMG_INFORMATION, 
#endif        
#ifdef __MMI_PHOTOEDITOR__
        MENU_ID_FMGR_IMG_OPTION_EDIT,
#endif
        FMGR_GENERAL_OPTION
        MENU_ITEM_END,
        SHOW, NONMOVEABLE|INSERTABLE, DISP_LIST, STR_GLOBAL_OPTIONS,0));


    ADD_FMGR_MENUITEM((MENU_ID_FMGR_IMG_FWD_USE_OPTION,0,       
#if defined(__MMI_FILE_USEAS_SUPPORT__)
#ifdef __MMI_VUI_SCREEN_LOCK_KEY__
		MENU_ID_FMGR_FWD_HOME_WALLPAPER,
		MENU_ID_FMGR_FWD_LOCK_WALLPAPER,
#else
        #ifndef __MMI_MAINLCD_96X64__ 
        MENU_ID_FMGR_FWD_WALLPAPER,
        #endif
#endif
        FMGR_COMMON_FWD_IMAGE_SUB_WALLPAPER
#ifdef __MMI_SCREEN_SAVER__
        MENU_ID_FMGR_FWD_SCREENSAVER,
#endif
        FMGR_COMMON_FWD_IMAGE_POWER_ONOFF
#ifdef __MMI_PHB_CALLER_RES__
#if !defined(LOW_COST_SUPPORT)
#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_FILE_USEAS_SUPPORT__)&&defined(__SRV_PHB_CALLER_RES_DATA_STORE__)
        MENU_ID_PHB_PIC_USE_AS,
#endif
#endif
#endif
#endif
        MENU_ITEM_END,
        SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, STR_FMGR_USE,0));

#ifndef __COSMOS_MMI_PACKAGE__
    ADD_FMGR_MENUITEM((MENU_ID_FMGR_IMG_FWD_SEND_OPTION,0,       
    #ifdef __MMI_SMS_APP_EMS_SUPPORT__
        MENU_ID_SMS_FMGR_FWD_EMS,
    #endif
        FMGR_COMMON_FWD_MMS
        FMGR_COMMON_FWD_TO_BLOG
        FMGR_COMMON_FWD_TO_POSTCARD
        FMGR_COMMON_FWD_EMAIL
        FMGR_COMMON_FWD_IRDA
        FMGR_COMMON_FWD_BT
        FMGR_COMMON_FWD_SNS_PHOTO_UPLOAD
        MENU_ITEM_END,
        SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, STR_GLOBAL_SEND,0));
#endif

    /********************* Audio files *********************************/

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_AUD_TYPE_OPTIONS,0,
        MENU_ID_FMGR_AUD_OPTION_PLAY, 
        FMGR_GENERAL_OPTION
        MENU_ITEM_END,
        SHOW, NONMOVEABLE|INSERTABLE, DISP_LIST, STR_GLOBAL_OPTIONS,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_AUD_OPTION_PLAY,     0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_PLAY,0));
    ADD_APPLICATION_MENUITEM2((MENU_ID_FMGR_AUD_FWD_USE_OPTION,0,

    MENU_ID_PROF_USE_AS_SIM1_RINGTONE,
    MENU_ID_PROF_USE_AS_SIM2_RINGTONE,
    MENU_ID_PROF_USE_AS_SIM3_RINGTONE,
    MENU_ID_PROF_USE_AS_SIM4_RINGTONE,
    MENU_ID_PROF_USE_AS_RINGTONE,
    

#ifdef __MMI_VIDEO_TELEPHONY__    
    MENU_ID_PROF_USE_AS_VIDEO_TONE,
#endif

#ifdef __MMI_BG_SOUND_EFFECT__      
        MENU_ID_FMGR_FWD_BGSOUND,      
#endif      
        MENU_ITEM_END,
        SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, STR_FMGR_USE,0));

#ifndef __COSMOS_MMI_PACKAGE__
    ADD_FMGR_MENUITEM((MENU_ID_FMGR_AUD_FWD_SEND_OPTION,0,
    #ifdef __MMI_SMS_APP_EMS_SUPPORT__
        MENU_ID_SMS_FMGR_FWD_EMS,
    #endif
        FMGR_COMMON_FWD_MMS
        FMGR_COMMON_FWD_TO_BLOG
        FMGR_COMMON_FWD_EMAIL
        FMGR_COMMON_FWD_IRDA
        FMGR_COMMON_FWD_BT
        MENU_ITEM_END,
        SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, STR_GLOBAL_SEND,0));
#endif

    /********************* Video files *********************************/

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_VID_TYPE_OPTIONS,0,
        MENU_ID_FMGR_VID_OPTION_PLAY, 
        FMGR_GENERAL_OPTION
        MENU_ITEM_END,
        SHOW, NONMOVEABLE|INSERTABLE, DISP_LIST, STR_GLOBAL_OPTIONS,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_VID_OPTION_PLAY,     0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_PLAY,0));
    
    ADD_APPLICATION_MENUITEM2((MENU_ID_FMGR_VID_FWD_USE_OPTION,0,
#if defined(__MMI_FILE_USEAS_SUPPORT__)
	#if (defined (__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__)) || (defined (__MMI_LAUNCHER_APP_LIST_VIDEO_WALLPAPER__)) 
		#ifdef __MMI_VUI_SCREEN_LOCK_KEY__
		MENU_ID_FMGR_FWD_HOME_WALLPAPER,
		MENU_ID_FMGR_FWD_LOCK_WALLPAPER,
		#else
		  #ifndef __MMI_MAINLCD_96X64__ 
          MENU_ID_FMGR_FWD_WALLPAPER,
          #endif
	    #endif
	#endif
    #if defined(__MMI_SCREENSAVER_DISPLAY_VIDEO__) && defined(__MMI_SCREEN_SAVER__)
        MENU_ID_FMGR_FWD_SCREENSAVER,
    #endif
    #ifdef __MMI_POWER_ON_OFF_DISPLAY_VIDEO__
        MENU_ID_FMGR_FWD_POWER_ON,
        MENU_ID_FMGR_FWD_POWER_OFF,
    #endif
    #ifdef __MMI_PHB_CALLER_VIDEO__
    #ifdef __MMI_PHB_CALLER_RES__
        MENU_ID_PHB_VIDEO_USE_AS,
    #endif
    #endif         
#endif
        MENU_ITEM_END,
        SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, STR_FMGR_USE,0));

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_VID_FWD_SEND_OPTION,0,
        FMGR_COMMON_FWD_MMS
        FMGR_COMMON_FWD_TO_BLOG
        FMGR_COMMON_FWD_EMAIL
        FMGR_COMMON_FWD_IRDA
        FMGR_COMMON_FWD_BT
        MENU_ITEM_END,
        SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, STR_GLOBAL_SEND,0));

#if defined ( __J2ME__ ) 
/********************* Java files *********************************/

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_JAD_TYPE_OPTIONS,0,
    #if !defined (__MMI_FMGR_DISABLE_JAVA_INSTALL__)
        MENU_ID_FMGR_JAVA_OPTION_EXECUTE, 
    #endif
        MENU_ID_FMGR_JAVA_OPTION_PACKAGE, 
        MENU_ID_FMGR_GEN_OPTION_FORWARD_SEND, 
        MENU_ID_FMGR_GEN_OPTION_FORWARD_USE, 
        MENU_ID_FMGR_FOLDER_CREATE,
    #ifdef __MMI_RMGR__
        MENU_ID_FMGR_GEN_OPTION_MORE_RITS, 
    #endif
        MENU_ID_FMGR_GEN_OPTION_RENAME, 
        MENU_ID_FMGR_GEN_OPTION_DELETE, 
        FMGR_GENERAL_OPT_SORT 
        FMGR_GENERAL_OPT_MULTI_SELECT 
        MENU_ID_FMGR_GEN_OPTION_COPY, 
        MENU_ID_FMGR_GEN_OPTION_MOVE,
    #ifndef __MMI_SLIM_FILE_MANAGER__
        MENU_ID_FMGR_GEN_OPTION_DELETE_ALL, 
    #endif
        MENU_ID_FMGR_GEN_OPTION_DETAIL, 
        MENU_ITEM_END,
        SHOW, NONMOVEABLE|INSERTABLE, DISP_LIST, STR_GLOBAL_OPTIONS,0));

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_JAR_TYPE_OPTIONS,0,
    #if !defined (__MMI_FMGR_DISABLE_JAVA_INSTALL__)
        MENU_ID_FMGR_JAVA_OPTION_EXECUTE, 
    #endif
        FMGR_GENERAL_OPTION
        MENU_ITEM_END,
        SHOW, NONMOVEABLE|INSERTABLE, DISP_LIST, STR_GLOBAL_OPTIONS,0));

#endif
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/********************* Theme files *********************************/

    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_THEME_ACTIVATE,      0, 0, SHOW, NONMOVEABLE, DISP_LIST, STR_GLOBAL_ACTIVATE,0));

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_THEME_TYPE_OPTIONS, 0,
        MENU_ID_FMGR_THEME_ACTIVATE, 
        FMGR_GENERAL_OPTION
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, DISP_LIST, STR_FMGR_THEME_OPTION,0));

#endif


#ifdef __CERTMAN_SUPPORT__
/********************* CERT files *********************************/

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_CERT_TYPE_OPTIONS,0,
        MENU_FMGR_CER_OPTION_INSTALL, 
        FMGR_GENERAL_OPTION
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, DISP_LIST, STR_GLOBAL_OPTIONS,0));
#endif

/* kamal */
#if defined(OBIGO_Q05A)
/********************* bookmark files *********************************/

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_BOOKMARK_TYPE_OPTIONS,0,
        MENU_ID_FMGR_BOOKMARK_FILE_OPEN, 
        FMGR_GENERAL_OPTION
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, DISP_LIST, STR_GLOBAL_OPTIONS,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_BOOKMARK_FILE_OPEN,  0, 0, SHOW, NONMOVEABLE, DISP_LIST, STR_GLOBAL_GO_TO,0));
#endif
//#if defined(__VRE__)
///********************* vre *********************************/
//
//    ADD_FMGR_MENUITEM((MENU_ID_FMGR_VRE_TYPE_OPTIONS,0,
//        MENU_ID_FMGR_VRE_FILE_OPEN, 
//        FMGR_GENERAL_OPTION
//        MENU_ITEM_END,
//        SHOW, NONMOVEABLE, DISP_LIST, STR_GLOBAL_OPTIONS,0));
//
//    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_VRE_FILE_OPEN,  0, 0, SHOW, NONMOVEABLE, DISP_LIST, STR_GLOBAL_OPEN,0));
//#endif


#ifdef __MMI_VCARD__
/********************* vcard files *********************************/

    ADD_APPLICATION_MENUITEM2((MENU_ID_FMGR_VCARD_FWD_USE_OPTION,0,
        MENU_ID_FMGR_FWD_CONTACT,
        MENU_ITEM_END,
        SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, STR_FMGR_USE,0));

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_VCARD_FWD_SEND_OPTION,0,
        FMGR_COMMON_FWD_SMS
        FMGR_COMMON_FWD_MMS
        FMGR_COMMON_FWD_EMAIL
        FMGR_COMMON_FWD_IRDA
        FMGR_COMMON_FWD_BT
        MENU_ITEM_END,
        SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, STR_GLOBAL_SEND,0));
#endif

#ifdef __MMI_VCALENDAR__
/********************* vcalendar files *********************************/
    ADD_APPLICATION_MENUITEM2((MENU_ID_FMGR_VCAL_FWD_USE_OPTION,0,
        MENU_VCLNDR_USE_AS_EVENT,
        MENU_VCLNDR_USE_AS_TASK,
        MENU_ITEM_END,
        SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, STR_FMGR_USE,0));

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_VCAL_FWD_SEND_OPTION,0,
        FMGR_COMMON_FWD_SMS
        FMGR_COMMON_FWD_MMS
        FMGR_COMMON_FWD_EMAIL
        FMGR_COMMON_FWD_IRDA
        FMGR_COMMON_FWD_BT
        MENU_ITEM_END,
        SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, STR_GLOBAL_SEND,0));
#endif
/* UDX_SUPPORT */
#ifdef __MMI_UDX_SUPPORT__
/********************* UDX files *********************************/

    ADD_APPLICATION_MENUITEM2((MENU_ID_FMGR_UDX_FWD_USE_OPTION,0,
        MENU_ID_UDX_FMGR_FWD_UDX,
        MENU_ITEM_END,
        SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, STR_FMGR_USE,0));

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_UDX_FWD_SEND_OPTION,0,
        FMGR_COMMON_FWD_MMS
        FMGR_COMMON_FWD_EMAIL
        FMGR_COMMON_FWD_IRDA
        FMGR_COMMON_FWD_BT
        MENU_ITEM_END,
        SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, STR_GLOBAL_SEND,0));
#endif
/* UDX_SUPPORT */

#ifdef __MMI_SWFLASH__
/********************* MFH files *********************************/

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_MFH_FWD_USE_OPTION,0,
        
	#ifdef __MMI_VUI_SCREEN_LOCK_KEY__
		MENU_ID_FMGR_FWD_HOME_WALLPAPER,
		MENU_ID_FMGR_FWD_LOCK_WALLPAPER,
	#else
        #ifndef __MMI_MAINLCD_96X64__ 
        MENU_ID_FMGR_FWD_WALLPAPER,
        #endif
	#endif
    #ifdef __MMI_SCREEN_SAVER__
        MENU_ID_FMGR_FWD_SCREENSAVER,
    #endif
        FMGR_COMMON_FWD_IMAGE_POWER_ONOFF
    #ifdef __MMI_PHB_CALLER_VIDEO__
    #ifdef __MMI_PHB_CALLER_RES__
        MENU_ID_PHB_VIDEO_USE_AS,
    #endif
    #endif
        MENU_ITEM_END,
        SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, STR_FMGR_USE,0));

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_MFH_FWD_SEND_OPTION,0,
        FMGR_COMMON_FWD_MMS
        FMGR_COMMON_FWD_EMAIL
        FMGR_COMMON_FWD_IRDA
        FMGR_COMMON_FWD_BT
        MENU_ITEM_END,
        SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, STR_GLOBAL_SEND,0));
#endif

#if defined (__MMI_VBOOKMARK__ ) && defined(__MMI_BRW_BOOKMARK_IN_FMGR__)
/********************* vbookmark files *********************************/

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_VBOOKMARK_TYPE_OPTIONS,0,
        MENU_ID_FMGR_VBOOKMARK_OPTION_GOTO, 
        MENU_ID_FMGR_VBOOKMARK_OPTION_OPEN,
        FMGR_GENERAL_OPTION
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, DISP_LIST, STR_GLOBAL_OPTIONS,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_VBOOKMARK_OPTION_GOTO, 0, 0, SHOW, NONMOVEABLE, DISP_LIST, STR_GLOBAL_GO_TO, 0));
    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_VBOOKMARK_OPTION_OPEN, 0, 0, SHOW, NONMOVEABLE, DISP_LIST, STR_GLOBAL_OPEN,  0));

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_VBOOKMARK_FWD_SEND_OPTION,0,
        FMGR_COMMON_FWD_SMS
        FMGR_COMMON_FWD_MMS
        FMGR_COMMON_FWD_EMAIL
        FMGR_COMMON_FWD_IRDA
        FMGR_COMMON_FWD_BT
        MENU_ITEM_END,
        SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, STR_GLOBAL_SEND,0));
#endif /* #if defined (__MMI_VBOOKMARK__ ) && defined(__MMI_BRW_BOOKMARK_IN_FMGR__) */


#ifdef __MMI_IMPS__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

}

void PopulateFileMgrServImgRes(void)
{

    /********* small icon *********/
#ifdef  __FTE_NON_SLIM_RES__

ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_IMG,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIIMAGE.png", "image icon" );

//    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_MSG,
//        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIMSG.bmp", "message icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_AUD,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.png", "audio icon" );

#if defined(__MMI_VIDEO_PLAYER__) || defined(__MMI_MEDIA_PLAYER_VIDEO__) || defined(__MMI_VIDEO_RECORDER__)
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_VDO,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIVIDEO.png", "video icon" );
#endif


#ifdef __J2ME__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_JAVA,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIJAVA.png", "java icon" );
#endif

#ifdef __MMI_VCARD__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_VCF,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIVCF.png", "vcf icon" );
#endif

#ifdef __MMI_VCALENDAR__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_VCS,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIVCS.png", "vcs icon" );
#endif

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_THEME,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIIMAGE.png", "theme icon" );
#endif


#else /*__FTE_NON_SLIM_RES__*/


    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_IMG,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIIMAGE.bmp", "image icon" );

//    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_MSG,
//        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIMSG.bmp", "message icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_AUD,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.bmp", "audio icon" );

#if defined(__MMI_VIDEO_PLAYER__) || defined(__MMI_MEDIA_PLAYER_VIDEO__) || defined(__MMI_VIDEO_RECORDER__)
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_VDO,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIVIDEO.bmp", "video icon" );
#endif


#ifdef __J2ME__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_JAVA,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIJAVA.bmp", "java icon" );
#endif

#ifdef __MMI_VCARD__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_VCF,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIVCF.bmp", "vcf icon" );
#endif

#ifdef __MMI_VCALENDAR__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_VCS,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIVCS.bmp", "vcs icon" );
#endif

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_THEME,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIIMAGE.bmp", "theme icon" );
#endif

#endif /*__FTE_NON_SLIM_RES__*/







#ifdef __MMI_UDX_VCARD_SUPPORT__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_UDX,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIUDX.bmp", "udx icon" );
#endif





#ifdef __MMI_SVG__
/* under construction !*/
/* under construction !*/
#endif


#ifdef __MMI_BARCODEREADER__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_MBC,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIQRV.bmp", "MBC icon" );
#endif

#ifdef __MMI_SWFLASH__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_SWFLASH,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_Sianimation.bmp", "swflash icon" );
#endif

    /********* large icon **********/
#ifndef __MMI_ULTRA_SLIM_FILE_MANAGER__
    /* image */
#if defined(__MMI_FTE_SUPPORT_SLIM__)
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_BMP,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIMAGE.bmp", "bmp large icon" );
    #ifdef JPG_DECODE
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_JPG,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIMAGE.bmp", "jpg large icon" );
    #endif

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_GIF,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIMAGE.bmp", "gif large icon" );

    #ifdef GDI_USING_PNG
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_PNG,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIMAGE.bmp", "png large icon" );
    #endif

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_WBMP,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIMAGE.bmp", "wbmp large icon" );

    /* message */
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_EMS,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIMAGE.bmp", "ems large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_ANM,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIMAGE.bmp", "anm large icon" );

    #ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_MAV,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIMAGE.bmp", "mav large icon" );
    #endif

#elif defined(__MMI_SLIM_FILE_MANAGER__)
#ifndef GDI_USING_GIF
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_BMP,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIMAGE.bmp", "bmp large icon" );
    #ifdef JPG_DECODE
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_JPG,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIMAGE.bmp", "jpg large icon" );
    #endif

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_GIF,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIMAGE.bmp", "gif large icon" );

    #ifdef GDI_USING_PNG
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_PNG,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIMAGE.bmp", "png large icon" );
    #endif

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_WBMP,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIMAGE.bmp", "wbmp large icon" );

    /* message */
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_EMS,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIMAGE.bmp", "ems large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_ANM,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIMAGE.bmp", "anm large icon" );

    #ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_MAV,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIMAGE.bmp", "mav large icon" );
    #endif
#else
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_BMP,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIMAGE.gif", "bmp large icon" );
    #ifdef JPG_DECODE
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_JPG,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIMAGE.gif", "jpg large icon" );
    #endif

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_GIF,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIMAGE.gif", "gif large icon" );

    #ifdef GDI_USING_PNG
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_PNG,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIMAGE.gif", "png large icon" );
    #endif

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_WBMP,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIMAGE.gif", "wbmp large icon" );

    /* message */
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_EMS,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIMAGE.gif", "ems large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_ANM,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIMAGE.gif", "anm large icon" );

    #ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_MAV,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIMAGE.gif", "mav large icon" );
    #endif
#endif
    

#else
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_BMP,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIBMP.gif", "bmp large icon" );

    #ifdef JPG_DECODE
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_JPG,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIJPG.gif", "jpg large icon" );
    #endif

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_GIF,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIGIF.gif", "gif large icon" );

    #ifdef GDI_USING_PNG
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_PNG,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIPNG.gif", "png large icon" );
    #endif

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_WBMP,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIWBMP.gif", "wbmp large icon" );

    /* message */
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_EMS,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIEMS.gif", "ems large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_ANM,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIANM.gif", "anm large icon" );

    #ifdef __MULTIPLE_ANGLE_VIEW_SUPPORT__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_MAV,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIMAV.gif", "mav large icon" );
    #endif
#endif


    /* audio */
#if defined (__MMI_SLIM_FILE_MANAGER__) || defined (__MMI_FTE_SUPPORT_SLIM__)
    #if defined(DAF_DECODE) || defined(YAMAHA_MA3)
    #ifndef GDI_USING_GIF
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_DAF,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.bmp", "daf large icon" );
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_IMY,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.bmp", "imy large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_MID,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.bmp", "midi large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_WAV,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.bmp", "wav large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_AMR,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.bmp", "amr large icon" );

    #ifdef AAC_DECODE
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_AAC,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.bmp", "aac large icon" );
    #endif
    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_VM,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.bmp", "vm large icon" );

    #ifdef AMRWB_DECODE
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_AWB,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.bmp", "awb large icon" );
    #endif

    #ifdef AIFF_DECODE
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_AIF,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.bmp", "aif large icon" );
    #endif

    #ifdef AU_DECODE
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_AU,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.bmp", "au large icon" );
    #endif

    #ifdef SND_DECODE
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_SND,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.bmp", "snd large icon" );
    #endif

    #ifdef KUR_DECODE
	ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_KUR,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.bmp", "snd large icon" );
    #endif

    #ifdef M4A_DECODE
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_M4A,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.bmp", "m4a large icon" );
    #endif

    #ifdef WMA_DECODE
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_WMA,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.bmp", "wma large icon" );
    #endif
    
    #ifdef BSAC_DECODE
/* under construction !*/
/* under construction !*/
    #endif 

    #ifdef __RM_DEC_SUPPORT__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_RA,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.bmp", "ra large icon" );
    #endif 

    #ifdef __APE_DECODE__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_APE,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.bmp", "ape large icon" );
    #endif

    #ifdef __VORBIS_DECODE__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_OGG,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.bmp", "ogg large icon" );
    #endif
    #ifdef __FLAC_DECODE__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_FLAC,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.bmp", "flac large icon" );
    #endif
	
  	#else/*GDI_USING_GIF*/
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_DAF,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.gif", "daf large icon" );
    #endif /* GDI_USING_GIF */
	
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_IMY,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.gif", "imy large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_MID,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.gif", "midi large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_WAV,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.gif", "wav large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_AMR,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.gif", "amr large icon" );

    #ifdef AAC_DECODE
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_AAC,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.gif", "aac large icon" );
    #endif
    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_VM,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.gif", "vm large icon" );

    #ifdef AMRWB_DECODE
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_AWB,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.gif", "awb large icon" );
    #endif

    #ifdef AIFF_DECODE
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_AIF,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.gif", "aif large icon" );
    #endif

    #ifdef AU_DECODE
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_AU,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.gif", "au large icon" );
    #endif

    #ifdef SND_DECODE
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_SND,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.gif", "snd large icon" );
    #endif

    #ifdef KUR_DECODE
	ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_KUR,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.gif", "snd large icon" );
    #endif

    #ifdef M4A_DECODE
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_M4A,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.gif", "m4a large icon" );
    #endif

    #ifdef WMA_DECODE
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_WMA,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.gif", "wma large icon" );
    #endif
    
    #ifdef BSAC_DECODE
/* under construction !*/
/* under construction !*/
    #endif 

    #ifdef __RM_DEC_SUPPORT__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_RA,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.gif", "ra large icon" );
    #endif 

    #ifdef __APE_DECODE__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_APE,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.gif", "ape large icon" );
    #endif

    #ifdef __VORBIS_DECODE__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_OGG,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.gif", "ogg large icon" );
    #endif
    #ifdef __FLAC_DECODE__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_FLAC,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.gif", "flac large icon" );
    #endif
    #endif  /*defined(DAF_DECODE) || defined(YAMAHA_MA3)*/  

#else/*__MMI_SLIM_FILE_MANAGER__*/
    #if defined(DAF_DECODE) || defined(YAMAHA_MA3)
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_DAF,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIDAF.gif", "daf large icon" );
    #endif

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_IMY,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIMY.gif", "imy large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_MID,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIMIDI.gif", "midi large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_WAV,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIWAV.gif", "wav large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_AMR,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAMR.gif", "amr large icon" );

    #ifdef AAC_DECODE
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_AAC,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAAC.gif", "aac large icon" );
    #endif
    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_VM,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIVM.gif", "vm large icon" );

    #ifdef AMRWB_DECODE
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_AWB,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAWB.gif", "awb large icon" );
    #endif

    #ifdef AIFF_DECODE
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_AIF,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAIF.gif", "aif large icon" );
    #endif

    #ifdef AU_DECODE
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_AU,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAU.gif", "au large icon" );
    #endif

    #ifdef SND_DECODE
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_SND,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LISND.gif", "snd large icon" );
    #endif

    #ifdef KUR_DECODE
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_KUR,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIKUR.gif", "snd large icon" );
    #endif

    #ifdef M4A_DECODE
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_M4A,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIM4A.gif", "m4a large icon" );
    #endif 

    #ifdef WMA_DECODE
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_WMA,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIWMA.gif", "wma large icon" );
    #endif

    #ifdef BSAC_DECODE
/* under construction !*/
/* under construction !*/
    #endif 

    #ifdef __RM_DEC_SUPPORT__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_RA,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIRA.gif", "ra large icon" );
    #endif 
    #ifdef __APE_DECODE__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_APE,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAPE.gif", "ape large icon" );
    #endif

    #ifdef __VORBIS_DECODE__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_OGG,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIOGG.gif", "ogg large icon" );
    #endif
    #ifdef __FLAC_DECODE__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_FLAC,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.gif", "flac large icon" );
    #endif
#endif



#if defined(MP4_DECODE) || defined(__MMI_PURE_AUDIO__)
    /* video */
#ifndef GDI_USING_GIF
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_3GP,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LI3GP.bmp", "large icon" );
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_MP4,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIMP4.bmp", "large icon" );
#else
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_3GP,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LI3GP.gif", "large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_MP4,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIMP4.gif", "large icon" );
#endif    
#endif 

#if defined(__RM_DEC_SUPPORT__)
    /* video */
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_RM,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIRM.gif", "large icon" );
#endif 


#if defined(__QQMOVIE_SUPPORT__)
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_3GQ,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_3gq.gif", "3GQ icon" );
#endif

#if defined(__MMI_VIDEO_PLAYER__) || defined(__MMI_MEDIA_PLAYER_VIDEO__) || defined(__MMI_VIDEO_RECORDER__)
#ifndef GDI_USING_GIF
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_AVI,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAVI.bmp", "large icon" ); 
#else
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_AVI,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAVI.gif", "large icon" );  
#endif
#endif
#endif	/* #ifndef __MMI_ULTRA_SLIM_FILE_MANAGER__ */ 
    /* others */
   
#ifdef __J2ME__ 
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_JAD,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIJAD.gif", "jad large icon" );
    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_JAR,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIJAR.gif", "jar large icon" );
#if defined(__MMI_JAVA_FMGR_HYPERLINK__)
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_JAVA,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIJAVA.gif", "jar large icon" );
#endif    
#endif

#ifdef __MMI_VCARD__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_VCF,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIVCF.gif", "vcf large icon" );
#endif

#ifdef __MMI_UDX_VCARD_SUPPORT__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_UDX,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIUDX.gif", "vcf large icon" );
#endif                                                                

#ifdef __MMI_VCALENDAR__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_VCS,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIVCS.gif", "vcs large icon" );
#endif

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_THEME,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LITHM.gif", "theme large icon" );
#endif

#ifdef __MMI_SVG__
/* under construction !*/
/* under construction !*/
#endif

#ifdef __MMI_BARCODEREADER__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_MBC,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIMBC.gif", "MBC icon" );
#endif

#ifdef __MMI_SWFLASH__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_CMP,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LICMP.gif", "cmp large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_VIS,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIVIS.gif", "cmp large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_IVIS,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIVIS.gif", "cmp large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_ZDD,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIZDD.gif", "cmp large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_KVIS,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIKVIS.gif", "cmp large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_MVIS,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIMVIS.gif", "cmp large icon" );

#endif

#ifdef __MMI_VIDEO_STREAM__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_SDP,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LISDP.gif", "SDP large icon" );    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_RAM,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIRAM.gif", "RAM large icon" );    
#ifdef  __FTE_NON_SLIM_RES__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_SDP,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIVSTREAM.png", "SDP small icon" );    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_RAM,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIVSTREAM.png", "RAM small icon" ); 
#else /*__FTE_NON_SLIM_RES__*/
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_SDP,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIVSTREAM.bmp", "SDP small icon" );    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_RAM,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIVSTREAM.bmp", "RAM small icon" );  
#endif /*__FTE_NON_SLIM_RES__*/
#endif /*__MMI_VIDEO_STREAM__*/

/* kamal */
#if defined(OBIGO_Q05A)
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_HTM,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIWEB.bmp", "Brower HTML small icon" );    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_BRW_HTM_LARGE_TYPE,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_HTM.gif", "HTM large icon" );    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_BRW_HTML_LARGE_TYPE,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_HTML.gif", "HTML large icon" );    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_BRW_WML_LARGE_TYPE,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_WML.gif", "WML large icon" );    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_BRW_XHTML_LARGE_TYPE,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_XHTML.gif", "XHTML large icon" );    
#endif


#if defined (__MMI_VBOOKMARK__ ) && defined(__MMI_BRW_BOOKMARK_IN_FMGR__)
    #if defined(__COSMOS_MMI__)
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_VBOOKMARK,
        CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Bookmark\\\\BM_PDefine.pbm", "Vbookmark small icon" );    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_URL,
        CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Bookmark\\\\BM_URL.pbm", "URL large icon" );    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_VBM,
        CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Bookmark\\\\BM_VBM.pbm", "VBM large icon" );
    #else
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_VBOOKMARK,
        CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Bookmark\\\\BM_PDefine.bmp", "Vbookmark small icon" );    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_URL,
        CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Bookmark\\\\BM_URL.bmp", "URL large icon" );    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_VBM,
        CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Bookmark\\\\BM_VBM.bmp", "VBM large icon" );
    #endif
#endif /* #if defined (__MMI_VBOOKMARK__ ) && defined(__MMI_BRW_BOOKMARK_IN_FMGR__)  */


#ifdef __CERTMAN_SUPPORT__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_CER,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SICER.bmp", "cer small icon" );    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_CER_CER_LARGE_TYPE,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIcer.gif", "cer large icon" );    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_CER_PFX_LARGE_TYPE,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIpfx.gif", "pfx large icon" );    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_CER_DER_LARGE_TYPE,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIder.gif", "der large icon" );    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_CER_PEM_LARGE_TYPE,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIpem.gif", "pem large icon" );    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_CER_P7B_LARGE_TYPE,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIp7b.gif", "p7b large icon" );    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_CER_CRT_LARGE_TYPE,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIcrt.gif", "crt large icon" );    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_CER_SPC_LARGE_TYPE,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIspc.gif", "spc large icon" );    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_CER_P12_LARGE_TYPE,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIp12.gif", "p12 large icon" );    

#endif /* #ifdef __CERTMAN_SUPPORT__ */

#ifdef __MMI_IMPS__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

void PopulateFileMgrServStrRes(void)
{
    /************************************************************/
    /*                                                          */
    /*              exif strings                                */
    /*                                                          */
    /************************************************************/

#if defined(__MMI_EXIF__)
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_MAKE,              "Make",                 "STR_ID_FMGR_EXIF_MAKE");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_MODEL,             "Model",                "STR_ID_FMGR_EXIF_MODEL");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_ORIENTATION,       "Orientation",          "STR_ID_FMGR_EXIF_ORIENTATION");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_X_RESOLUTION,      "X Resolution",         "STR_ID_FMGR_EXIF_X_RESOLUTION");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_Y_RESOLUTION,      "Y Resolution",         "STR_ID_FMGR_EXIF_Y_RESOLUTION");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_RESOLUTION_UNIT,   "Resolution Unit",      "STR_ID_FMGR_EXIF_RESOLUTION_UNIT");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_SOFTWARE,          "Software",             "STR_ID_FMGR_EXIF_SOFTWARE");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_DATE_TIME,         "Date Time",            "STR_ID_FMGR_EXIF_DATE_TIME");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_YCBCR_POSITIONING, "YCbCr Position",       "STR_ID_FMGR_EXIF_YCBCR_POSITIONING");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_EXIF_IFD,          "EXIF IFD",             "STR_ID_FMGR_EXIF_EXIF_IFD");

    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_EXPOSURE_TIME,     "Exposure Time",        "STR_ID_FMGR_EXIF_EXPOSURE_TIME");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_FNUMBER,           "F Number",             "STR_ID_FMGR_EXIF_FNUMBER");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_EXPOSURE_PROGRAM,  "Exposure Program",     "STR_ID_FMGR_EXIF_EXPOSURE_PROGRAM");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_ISO_SPEED_RATINGS, "ISO Speed Ratings",    "STR_ID_FMGR_EXIF_ISO_SPEED_RATINGS");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_EXIF_VERSION,      "EXIF Version",         "STR_ID_FMGR_EXIF_EXIF_VERSION");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_DATE_TIME_ORIGINAL,"Date Time Original",   "STR_ID_FMGR_EXIF_DATE_TIME_ORIGINAL");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_DATE_TIME_DIGITIZED,"Date Time Digitized", "STR_ID_FMGR_EXIF_DATE_TIME_DIGITIZED");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_COMPONENTS_CONFIG, "Components Config",    "STR_ID_FMGR_EXIF_COMPONENTS_CONFIG");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_EXPOSURE_BIAS_VALUE,"Exposure Bias Value", "STR_ID_FMGR_EXIF_EXPOSURE_BIAS_VALUE");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_METERING_MODE,     "Metering Mode",        "STR_ID_FMGR_EXIF_METERING_MODE");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_LIGHT_SOURCE,      "Light Source",         "STR_ID_FMGR_EXIF_LIGHT_SOURCE");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_FLASH,             "Flash",                "STR_ID_FMGR_EXIF_FLASH");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_MAKER_NOTE,        "Maker Note",           "STR_ID_FMGR_EXIF_MAKER_NOTE");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_FLASHPIX_VERSION,  "Flashpix Version",     "STR_ID_FMGR_EXIF_FLASHPIX_VERSION");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_COLOR_SPACE,       "Color Space",          "STR_ID_FMGR_EXIF_COLOR_SPACE");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_PIXEL_X_DIMENSION, "X Dimension",          "STR_ID_FMGR_EXIF_PIXEL_X_DIMENSION");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_PIXEL_Y_DIMENSION, "Y Dimension",          "STR_ID_FMGR_EXIF_PIXEL_Y_DIMENSION");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_EXPOSURE_MODE,     "Exposure Mode",        "STR_ID_FMGR_EXIF_EXPOSURE_MODE");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_DIGITAL_ZOOM_RATIO,"Digital Zoom Ratio",   "STR_ID_FMGR_EXIF_DIGITAL_ZOOM_RATIO");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_SCENE_CAPTURE_TYPE,"Scene Capture Type",   "STR_ID_FMGR_EXIF_SCENE_CAPTURE_TYPE");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_NO_INFORMATION,    "No Information",       "STR_ID_FMGR_EXIF_NO_INFORMATION");    
#endif

    ADD_APPLICATION_STRING2(STR_ID_FMGR_FILE_LIMIT_IMAGE_TOO_LARGE, "Image too large\nLimit", "STR_ID_FMGR_FILE_LIMIT_IMAGE_TOO_LARGE" );
    ADD_APPLICATION_STRING2(STR_ID_FMGR_FILE_LIMIT_VIDEO_TOO_LARGE, "Video too large\nLimit", "STR_ID_FMGR_FILE_LIMIT_VIDEO_TOO_LARGE" );
    ADD_APPLICATION_STRING2(STR_ID_FMGR_FILE_LIMIT_VIDEO_TOO_LONG, "Video too long\nLimit", "STR_ID_FMGR_FILE_LIMIT_VIDEO_TOO_LONG" );
    ADD_APPLICATION_STRING2(STR_ID_FMGR_FILE_LIMIT_FILE_TOO_LARGE, "File too large\nLimit", "STR_ID_FMGR_FILE_LIMIT_FILE_TOO_LARGE" );
    
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__ 
    ADD_APPLICATION_STRING2(STR_FMGR_THEME_OPTION,              "Theme",                "THEME String");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_THEME_INCORRECT_LOCATION,"Theme File Location Incorrect. Do You Want To Move?","THEME warning String");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_ACTIVE_THEME_DELETE,    "Active Theme Cant Be Deleted","THEME Delete warning String");

    ADD_APPLICATION_STRING2(STR_ID_THEME_ERROR_FAILURE,         "Theme Error",          "Theme Error String");
    
    ADD_APPLICATION_STRING2(STR_ID_FMGR_SPACE_NOT_AVAILABLE,    "Full Space",           "Theme space not available");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_MAX_COUNT_REACHED,      "Maximum Count Reached","THEME max count String");
#endif
#ifdef __MMI_THEMES_V2_SUPPORT__ 
    ADD_APPLICATION_STRING2(STR_ID_FMGR_ALREADY_ACTIVE,         "Theme Already Active", "THEME already active String");
#endif

#if defined(__MMI_EXIF__)
    ADD_APPLICATION_STRING2(STR_FMGR_VIEW_IMG_JPG_DETAIL,       "Image Info",           "STR_FMGR_VIEW_IMG_JPG_DETAIL");
#endif

    /* Use as */
    ADD_APPLICATION_STRING2(STR_ID_FMGR_FWD_CONTACT,            "Contact",              "STR_ID_FMGR_FWD_CONTACT" );
#ifdef __MMI_BG_SOUND_EFFECT__
    ADD_APPLICATION_STRING2(STR_FMGR_BGSOUND,                   "Backgound Sound",      "STR_FMGR_BGSOUND" );
#endif

    /* Send via */
#ifdef __MMI_MMS__
#ifdef __MMI_MMS_2__
#ifdef __MMI_OP11_MMS_SEND_TO_PHOTO_BLOG__
/* under construction !*/
#endif
#ifdef __MMI_MMS_POSTCARD__
   // ADD_APPLICATION_STRING2(STR_FMGR_UMMS_TO_POSTCARD,          "To Postcard",          "STR_FMGR_UMMS_TO_POSTCARD");
#endif
#endif
#endif

#if defined(__MMI_PICT_BRIDGE_SUPPORT__)
    ADD_APPLICATION_STRING2(STR_ID_FMGR_TO_PICTBRIGE,           "To PictBridge",        "STR_ID_FMGR_FORWARD_TO_PICTBRIGE" );
#endif

#if defined(__MMI_FMGR_MULTI_SELECT_SUPPORT__) && defined(__MMI_OPP_SUPPORT__)
    ADD_APPLICATION_STRING2(STR_ID_FMGR_MARK_TO_BT,             "Send marked via Bluetooth",   "STR_ID_FMGR_MARK_TO_BT" );
#endif

}

void PopulateFileMgrServiceResource(void)
{
    PopulateFileMgrServImgRes();
    PopulateFileMgrServStrRes();
    PopulateFileMgrServMenuRes();
    
    /*----------------------------------------------------------------*/
    /*  Forward options 
     */
    /* Use as - image / video */
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_FWD_CONTACT,         mmi_fmgr_highlight_to_phb);
#ifdef __MMI_BG_SOUND_EFFECT__		
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_FWD_BGSOUND,         mmi_fmgr_highlight_to_bgsound);
#endif
    /* Use as - todolist */

    /* Send via */
#if !defined (__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_FWD_SMS,             mmi_fmgr_highlight_to_sms);
#endif
#ifdef __MMI_MMS__
    //ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_FWD_MMS,             mmi_fmgr_highlight_to_mms);
#ifdef __MMI_MMS_2__
#ifdef __MMI_OP11_MMS_SEND_TO_PHOTO_BLOG__
/* under construction !*/
#endif
#ifdef __MMI_MMS_POSTCARD__
   // ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_UMMS_FMGR_SEND_TO_POSTCARD,             mmi_fmgr_highlight_to_postcard);
#endif
#endif
#endif
#ifdef __MMI_EMAIL__
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_FWD_EMAIL,           mmi_fmgr_highlight_to_email);
#endif
#ifdef __MMI_IRDA_SUPPORT__
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_FWD_IRDA,            mmi_fmgr_highlight_to_irda);
#endif
/* Bluetooth sending API revise */
    /*----------------------------------------------------------------*/
    /*  Image option
     */

#if (defined(__MMI_PICT_BRIDGE_SUPPORT__) || defined(__MMI_BPP_SUPPORT__)) && (defined(__MMI_IMAGE_VIEWER_EX__))
    /* Print options */
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_IMG_OPTION_PRINT,     mmi_fmgr_highlight_image_print);
#ifdef __MMI_PICT_BRIDGE_SUPPORT__
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_PRINT_PICTBRIGE,      mmi_fmgr_highlight_image_print_to_pictbridge);
#endif
#ifdef __MMI_BPP_SUPPORT__
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_PRINT_BLUETOOTH,      mmi_fmgr_highlight_image_print_to_bluetooth);
#endif
#endif /* defined(__MMI_PICT_BRIDGE_SUPPORT__) || defined(__MMI_BPP_SUPPORT__) */

    /*----------------------------------------------------------------*/
    /*  Other option
     */
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_AUD_OPTION_PLAY,      mmi_fmgr_highlight_audio_play);
#if defined(__MMI_VIDEO_PLAYER__) || defined(__MMI_MEDIA_PLAYER_VIDEO__) 
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_VID_OPTION_PLAY,      mmi_fmgr_highlight_video_play);
#endif

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_THEME_ACTIVATE,       mmi_fmgr_highlight_theme_activate);
//    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_THEME_DELETE,        mmi_fmgr_highlight_theme_delete); // TODO: not necessary
#endif



/* kamal */
#if defined(OBIGO_Q05A)
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_BOOKMARK_FILE_OPEN,   mmi_fmgr_highlight_bookmark_goto);
#endif
#ifdef __MMI_SWFLASH__
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_SWFLASH_OPTION_PLAY,       mmi_fmgr_highlight_swflash_play);
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_SWFLASH_OPTION_INFO,       mmi_fmgr_highlight_swflash_info);
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_SWFLASH_OPTION_DOWNLOAD,   mmi_fmgr_highlight_swflash_download);
#endif
#if defined (__MMI_VBOOKMARK__ ) && defined(__MMI_BRW_BOOKMARK_IN_FMGR__)
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_VBOOKMARK_OPTION_GOTO, mmi_fmgr_highlight_vbookmark_goto);
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_VBOOKMARK_OPTION_OPEN, mmi_fmgr_highlight_vbookmark_open);
#endif /* #if defined (__MMI_VBOOKMARK__ ) && defined(__MMI_BRW_BOOKMARK_IN_FMGR__) */

#ifdef __MMI_RMGR__
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_GEN_OPTION_MORE_RITS, mmi_rmgr_highlight_more_rits);
#endif

#ifdef __MMI_IMPS__         
/* under construction !*/
#endif
}

#endif /* __MMI_FILE_MANAGER__ */

#else
#if defined(__MMI_FILE_MANAGER__)
void PopulateFileMgrServiceResource(void)
{
}
#endif /* __MMI_FILE_MANAGER__ */
#endif /* __PLUTO_MMI_PACKAGE__ */
