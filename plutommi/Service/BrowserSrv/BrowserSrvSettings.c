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
 * BrowserSrvSettings.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
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
*------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#ifndef MMI_BROWSERSRVSETTINGS_C
#define MMI_BROWSERSRVSETTINGS_C

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__
#include "MMIDataType.h"
#include "BrowserSrvProts.h"
#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
#include "gui_data_types.h"
#include "Unicodexdcl.h"
#include "Conversions.h"
#include "MMI_inet_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_rp_srv_browser_def.h"

/*****************************************************************************
 * FUNCTION
 *  srv_brw_read_settings_data
 * DESCRIPTION
 *  This function is used to read selected item from NVRAM
 *  interface
 * PARAMETERS
 *  read_item         [IN]        NVRAM Item to be read      
 * RETURNS
 *  NVRAM error code
 *****************************************************************************/
S32 srv_brw_read_settings_data(srv_brw_nvram_item_enum read_item)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(read_item)
    {
#ifdef OBIGO_Q05A
    case SRV_BRW_NVRAM_SETTINGS_NAVIGATE_MODE:
        ReadValue(NVRAM_BRW_SETTINGS_NAVIGATE_MODE, &(g_srv_brw_cntx.navigation_mode), DS_BYTE, &error);
        break;
    case SRV_BRW_NVRAM_SETTINGS_THUMBNAIL:
        ReadValue(NVRAM_BRW_SETTINGS_THUMBNAIL, &(g_srv_brw_cntx.thumbnail_status), DS_BYTE, &error);
        break;
	case SRV_BRW_NVRAM_SETTINGS_RENDER_MODE:
		ReadValue(NVRAM_BRW_SETTINGS_RENDER_MODE, &(g_srv_brw_cntx.rendering_mode), DS_BYTE, &error);
		break;
#ifdef __MMI_VECTOR_FONT_SUPPORT__
	case SRV_BRW_NVRAM_SETTINGS_FONT_SIZE:
		ReadValue(NVRAM_BRW_SETTINGS_FONT_SIZE, &(g_srv_brw_cntx.font_size), DS_BYTE, &error);
		break;
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */
#endif /* OBIGO_Q05A */
	case SRV_BRW_NVRAM_SETTINGS_SCREEN_SIZE:
		ReadValue(NVRAM_BRW_SETTINGS_SCREEN_SIZE, &(g_srv_brw_cntx.screen_size_status), DS_BYTE, &error);
		break;
#ifdef OBIGO_Q05A
	case SRV_BRW_NVRAM_SETTINGS_ENCODE_METHOD_INDEX:
		ReadValue(NVRAM_BRW_SETTINGS_ENCODE_METHOD_INDEX, &(g_srv_brw_cntx.encoding_method_index), DS_BYTE, &error);
		break;
	case SRV_BRW_NVRAM_SETTINGS_SHOW_VIDEO:
		ReadValue(NVRAM_BRW_SETTINGS_SHOW_VIDEO, &(g_srv_brw_cntx.show_videos_status), DS_BYTE, &error);
		break;
	case SRV_BRW_NVRAM_SETTINGS_PLAY_SOUND:
		ReadValue(NVRAM_BRW_SETTINGS_PLAY_SOUND, &(g_srv_brw_cntx.play_sounds_status), DS_BYTE, &error);
		break;
	case SRV_BRW_NVRAM_SETTINGS_LOAD_UNKOWN_MEDIA:
		ReadValue(NVRAM_BRW_SETTINGS_LOAD_UNKOWN_MEDIA, &(g_srv_brw_cntx.load_unknown_media_status), DS_BYTE, &error);
		break;
	case SRV_BRW_NVRAM_SETTINGS_CSS:
		ReadValue(NVRAM_BRW_SETTINGS_CSS, &(g_srv_brw_cntx.css_status), DS_BYTE, &error);
		break;
	case SRV_BRW_NVRAM_SETTINGS_SCRIPTS:
		ReadValue(NVRAM_BRW_SETTINGS_SCRIPTS, &(g_srv_brw_cntx.script_status), DS_BYTE, &error);
		break;
#endif /* OBIGO_Q05A */
	case SRV_BRW_NVRAM_SETTINGS_CACHE:
		ReadValue(NVRAM_BRW_SETTINGS_CACHE, &(g_srv_brw_cntx.cache_status), DS_BYTE, &error);
		break;
	case SRV_BRW_NVRAM_SETTINGS_COOKIE:
		ReadValue(NVRAM_BRW_SETTINGS_COOKIE, &(g_srv_brw_cntx.cookie_status), DS_BYTE, &error);
		break;
	case SRV_BRW_NVRAM_TIMEOUT_VALUE:
		ReadValue(NVRAM_BRW_PAGE_TIME_OUT_VALUE, &(g_srv_brw_cntx.timeout_value), DS_SHORT, &error);
		break;
	case SRV_BRW_NVRAM_SHOW_IMAGE_MODE:
		ReadValue(NVRAM_BRW_SHOW_IMAGE_MODE, &(g_srv_brw_cntx.show_images_status), DS_BYTE, &error);
		break;
#ifdef BRW_KEYPAD_SHORTCUTS_SUPPORT
	case SRV_BRW_NVRAM_SETTINGS_SHORTCUTS:
		ReadValue(NVRAM_BRW_SETTINGS_SHORTCUTS, &(g_srv_brw_cntx.shortcuts_status), DS_BYTE, &error);
		break;
#endif /* BRW_KEYPAD_SHORTCUTS_SUPPORT */
#ifdef BRW_SECURITY_WARNINGS_SUPPORT
	case SRV_BRW_NVRAM_SETTINGS_SECURITY_WARNINGS:
		ReadValue(NVRAM_BRW_SETTINGS_SECURITY_WARNINGS, &(g_srv_brw_cntx.security_warnings_status), DS_BYTE, &error);
		break;
#endif /* BRW_SECURITY_WARNINGS_SUPPORT */
#ifdef BRW_SEND_DEVICE_ID_SUPPORT
	case SRV_BRW_NVRAM_SETTINGS_SEND_DEVICE_ID:
		ReadValue(NVRAM_BRW_SETTINGS_SEND_DEVICE_ID, &(g_srv_brw_cntx.send_device_id_status), DS_BYTE, &error);
		break;
#endif /* BRW_SEND_DEVICE_ID_SUPPORT */
#ifdef __MMI_BRW_POST_SESSION_INFO__
	case SRV_BRW_NVRAM_SETTINGS_POST_SESSION_INFO:
		ReadValue(NVRAM_BRW_SETTINGS_POST_SESSION_INFO, &(g_srv_brw_cntx.post_session_info_status), DS_BYTE, &error);
		break;
#endif /* __MMI_BRW_POST_SESSION_INFO__ */
#ifdef OBIGO_Q05A
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
	case SRV_BRW_NVRAM_RECENT_PAGES_SORTING_METHOD:
		ReadValue(NVRAM_BRW_RECENT_PAGES_SORTING_METHOD, &(g_srv_brw_cntx.sorting_method), DS_BYTE, &error);
		break;
#endif
#endif /* #ifdef OBIGO_Q05A */
	case SRV_BRW_NVRAM_SETTINGS_HOMEPAGE:
		ReadValue(NVRAM_BRW_SETTINGS_HOMEPAGE, &(g_srv_brw_cntx.homepage_setting), DS_BYTE, &error);
		break;
#ifdef __COSMOS_MMI_PACKAGE__
	case SRV_BRW_NVRAM_SETTINGS_SEARCH_ENGINE:
		ReadValue(NVRAM_BRW_SETTINGS_SEARCH_ENGINE, &(g_srv_brw_cntx.sel_search_engine), DS_BYTE, &error);
		break;
	case SRV_BRW_NVRAM_SETTINGS_HISTORY:
		ReadValue(NVRAM_BRW_SETTINGS_HISTORY, &(g_srv_brw_cntx.history_setting), DS_BYTE, &error);
		break;
	case SRV_BRW_NVRAM_SETTINGS_PRIVATE_MODE:
		ReadValue(NVRAM_BRW_SETTINGS_PRIVATE_MODE, &(g_srv_brw_cntx.private_mode_setting), DS_BYTE, &error);
		break;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0
#endif
#ifdef __BAIDU_TRANSCODING_SUPPORT__
    case SRV_BRW_NVRAM_SETTINGS_BAIDU_PROXY:
		ReadValue(NVRAM_BRW_SETTINGS_BAIDU_PROXY, &(g_srv_brw_cntx.baidu_proxy_status), DS_BYTE, &error);
		break;
#endif // __BAIDU_TRANSCODING_SUPPORT__
		
    }
	return (S32)error;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_settings_restore_data
 * DESCRIPTION
 *  This function is used to restore NVRAM data
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
#if (defined(__MMI_BRW_ADVANCED_APP_FEATURES__) || defined(__COSMOS_MMI_PACKAGE__))
void srv_brw_settings_restore_data(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef OBIGO_Q05A
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
    mmi_frm_get_default_cache_value(DS_BYTE, NVRAM_BRW_RECENT_PAGES_SORTING_METHOD, &(g_srv_brw_cntx.sorting_method));
#endif
    mmi_frm_get_default_cache_value(DS_BYTE, NVRAM_BRW_SETTINGS_RENDER_MODE, &(g_srv_brw_cntx.rendering_mode));

    mmi_frm_get_default_cache_value(DS_BYTE, NVRAM_BRW_SETTINGS_NAVIGATE_MODE, &(g_srv_brw_cntx.navigation_mode));

#ifdef __MMI_VECTOR_FONT_SUPPORT__
    mmi_frm_get_default_cache_value(DS_BYTE, NVRAM_BRW_SETTINGS_FONT_SIZE, &(g_srv_brw_cntx.font_size));
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */ 

    mmi_frm_get_default_cache_value(DS_BYTE, NVRAM_BRW_SETTINGS_THUMBNAIL, &(g_srv_brw_cntx.thumbnail_status));

    mmi_frm_get_default_cache_value(DS_BYTE, NVRAM_BRW_SETTINGS_SCREEN_SIZE, &(g_srv_brw_cntx.screen_size_status));

    mmi_frm_get_default_cache_value(DS_BYTE, NVRAM_BRW_SETTINGS_ENCODE_METHOD_INDEX, &(g_srv_brw_cntx.encoding_method_index));
#endif /* OBIGO_Q05A */
    mmi_frm_get_default_cache_value(DS_SHORT, NVRAM_BRW_PAGE_TIME_OUT_VALUE, (U8*)(&(g_srv_brw_cntx.timeout_value)));

    mmi_frm_get_default_cache_value(DS_BYTE, NVRAM_BRW_SHOW_IMAGE_MODE, &(g_srv_brw_cntx.show_images_status));
#ifdef OBIGO_Q05A
    mmi_frm_get_default_cache_value(DS_BYTE, NVRAM_BRW_SETTINGS_SHOW_VIDEO, &(g_srv_brw_cntx.show_videos_status));

    mmi_frm_get_default_cache_value(DS_BYTE, NVRAM_BRW_SETTINGS_PLAY_SOUND, &(g_srv_brw_cntx.play_sounds_status));

    mmi_frm_get_default_cache_value(DS_BYTE, NVRAM_BRW_SETTINGS_LOAD_UNKOWN_MEDIA, &(g_srv_brw_cntx.load_unknown_media_status));

    mmi_frm_get_default_cache_value(DS_BYTE, NVRAM_BRW_SETTINGS_CSS, &(g_srv_brw_cntx.css_status));

    mmi_frm_get_default_cache_value(DS_BYTE, NVRAM_BRW_SETTINGS_SCRIPTS, &(g_srv_brw_cntx.script_status));
#endif /* OBIGO_Q05A */
    mmi_frm_get_default_cache_value(DS_BYTE, NVRAM_BRW_SETTINGS_CACHE, &(g_srv_brw_cntx.cache_status));

    mmi_frm_get_default_cache_value(DS_BYTE, NVRAM_BRW_SETTINGS_COOKIE, &(g_srv_brw_cntx.cookie_status));
#ifdef OBIGO_Q05A
#ifdef BRW_KEYPAD_SHORTCUTS_SUPPORT
    mmi_frm_get_default_cache_value(DS_BYTE, NVRAM_BRW_SETTINGS_SHORTCUTS, &(g_srv_brw_cntx.shortcuts_status));
#endif /* BRW_KEYPAD_SHORTCUTS_SUPPORT */ 

#ifdef BRW_SECURITY_WARNINGS_SUPPORT
    mmi_frm_get_default_cache_value(DS_BYTE, NVRAM_BRW_SETTINGS_SECURITY_WARNINGS, &(g_srv_brw_cntx.security_warnings_status));
#endif /* BRW_SECURITY_WARNINGS_SUPPORT */ 

#ifdef BRW_SEND_DEVICE_ID_SUPPORT
    mmi_frm_get_default_cache_value(DS_BYTE, NVRAM_BRW_SETTINGS_SEND_DEVICE_ID, &(g_srv_brw_cntx.send_device_id_status));
#endif /* BRW_SEND_DEVICE_ID_SUPPORT */ 

#ifdef __MMI_BRW_POST_SESSION_INFO__
    mmi_frm_get_default_cache_value(DS_BYTE, NVRAM_BRW_SETTINGS_POST_SESSION_INFO, (U8*)(&(g_srv_brw_cntx.post_session_info_status)));
#endif /* __MMI_BRW_POST_SESSION_INFO__ */ 
#endif /* OBIGO_Q05A */
    mmi_frm_get_default_cache_value(DS_BYTE, NVRAM_BRW_SETTINGS_HOMEPAGE, &(g_srv_brw_cntx.homepage_setting));
#ifdef __COSMOS_MMI_PACKAGE__
    mmi_frm_get_default_cache_value(DS_BYTE, NVRAM_BRW_SETTINGS_SEARCH_ENGINE, &(g_srv_brw_cntx.sel_search_engine));
    mmi_frm_get_default_cache_value(DS_BYTE, NVRAM_BRW_SETTINGS_HISTORY, &(g_srv_brw_cntx.history_setting));
    mmi_frm_get_default_cache_value(DS_BYTE, NVRAM_BRW_SETTINGS_PRIVATE_MODE, &(g_srv_brw_cntx.private_mode_setting));
#if 0
/* under construction !*/
#endif //0
#endif
#ifdef __BAIDU_TRANSCODING_SUPPORT__
    mmi_frm_get_default_cache_value(DS_BYTE, NVRAM_BRW_SETTINGS_BAIDU_PROXY, &(g_srv_brw_cntx.baidu_proxy_status));
#endif // #ifdef __BAIDU_TRANSCODING_SUPPORT__
}
#endif /* __MMI_BRW_ADVANCED_APP_FEATURES__ */

/*****************************************************************************
 * FUNCTION
 *  srv_brw_update_settings_data
 * DESCRIPTION
 *  Function to update the settings' data to NVRAM based on item type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_update_settings_data(srv_brw_nvram_item_enum item_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(item_type)
    {
#ifdef OBIGO_Q05A
      case SRV_BRW_NVRAM_SETTINGS_NAVIGATE_MODE:
        WriteValue(NVRAM_BRW_SETTINGS_NAVIGATE_MODE, &(g_srv_brw_cntx.navigation_mode), DS_BYTE, &error);
        break;
    case SRV_BRW_NVRAM_SETTINGS_THUMBNAIL:
        WriteValue(NVRAM_BRW_SETTINGS_THUMBNAIL, &(g_srv_brw_cntx.thumbnail_status), DS_BYTE, &error);
        break;
	case SRV_BRW_NVRAM_SETTINGS_RENDER_MODE:
		WriteValue(NVRAM_BRW_SETTINGS_RENDER_MODE, &(g_srv_brw_cntx.rendering_mode), DS_BYTE, &error);
		break;
#ifdef __MMI_VECTOR_FONT_SUPPORT__
	case SRV_BRW_NVRAM_SETTINGS_FONT_SIZE:
		WriteValue(NVRAM_BRW_SETTINGS_FONT_SIZE, &(g_srv_brw_cntx.font_size), DS_BYTE, &error);
		break;
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */
#endif /* OBIGO_Q05A */
	case SRV_BRW_NVRAM_SETTINGS_SCREEN_SIZE:
		WriteValue(NVRAM_BRW_SETTINGS_SCREEN_SIZE, &(g_srv_brw_cntx.screen_size_status), DS_BYTE, &error);
		break;
#ifdef OBIGO_Q05A
	case SRV_BRW_NVRAM_SETTINGS_ENCODE_METHOD_INDEX:
		WriteValue(NVRAM_BRW_SETTINGS_ENCODE_METHOD_INDEX, &(g_srv_brw_cntx.encoding_method_index), DS_BYTE, &error);
		break;
	case SRV_BRW_NVRAM_SETTINGS_SHOW_VIDEO:
		WriteValue(NVRAM_BRW_SETTINGS_SHOW_VIDEO, &(g_srv_brw_cntx.show_videos_status), DS_BYTE, &error);
		break;
	case SRV_BRW_NVRAM_SETTINGS_PLAY_SOUND:
		WriteValue(NVRAM_BRW_SETTINGS_PLAY_SOUND, &(g_srv_brw_cntx.play_sounds_status), DS_BYTE, &error);
		break;
	case SRV_BRW_NVRAM_SETTINGS_LOAD_UNKOWN_MEDIA:
		WriteValue(NVRAM_BRW_SETTINGS_LOAD_UNKOWN_MEDIA, &(g_srv_brw_cntx.load_unknown_media_status), DS_BYTE, &error);
		break;
	case SRV_BRW_NVRAM_SETTINGS_CSS:
		WriteValue(NVRAM_BRW_SETTINGS_CSS, &(g_srv_brw_cntx.css_status), DS_BYTE, &error);
		break;
	case SRV_BRW_NVRAM_SETTINGS_SCRIPTS:
		WriteValue(NVRAM_BRW_SETTINGS_SCRIPTS, &(g_srv_brw_cntx.script_status), DS_BYTE, &error);
		break;
#endif /* OBIGO_Q05A */
	case SRV_BRW_NVRAM_SETTINGS_CACHE:
		WriteValue(NVRAM_BRW_SETTINGS_CACHE, &(g_srv_brw_cntx.cache_status), DS_BYTE, &error);
		break;
	case SRV_BRW_NVRAM_SETTINGS_COOKIE:
		WriteValue(NVRAM_BRW_SETTINGS_COOKIE, &(g_srv_brw_cntx.cookie_status), DS_BYTE, &error);
		break;
	case SRV_BRW_NVRAM_TIMEOUT_VALUE:
		WriteValue(NVRAM_BRW_PAGE_TIME_OUT_VALUE, &(g_srv_brw_cntx.timeout_value), DS_SHORT, &error);
		break;
	case SRV_BRW_NVRAM_SHOW_IMAGE_MODE:
		WriteValue(NVRAM_BRW_SHOW_IMAGE_MODE, &(g_srv_brw_cntx.show_images_status), DS_BYTE, &error);
		break;
#ifdef BRW_KEYPAD_SHORTCUTS_SUPPORT
	case SRV_BRW_NVRAM_SETTINGS_SHORTCUTS:
		WriteValue(NVRAM_BRW_SETTINGS_SHORTCUTS, &(g_srv_brw_cntx.shortcuts_status), DS_BYTE, &error);
		break;
#endif /* BRW_KEYPAD_SHORTCUTS_SUPPORT */
#ifdef BRW_SECURITY_WARNINGS_SUPPORT
	case SRV_BRW_NVRAM_SETTINGS_SECURITY_WARNINGS:
		WriteValue(NVRAM_BRW_SETTINGS_SECURITY_WARNINGS, &(g_srv_brw_cntx.security_warnings_status), DS_BYTE, &error);
		break;
#endif /* BRW_SECURITY_WARNINGS_SUPPORT */
#ifdef BRW_SEND_DEVICE_ID_SUPPORT
	case SRV_BRW_NVRAM_SETTINGS_SEND_DEVICE_ID:
		WriteValue(NVRAM_BRW_SETTINGS_SEND_DEVICE_ID, &(g_srv_brw_cntx.send_device_id_status), DS_BYTE, &error);
		break;
#endif /* BRW_SEND_DEVICE_ID_SUPPORT */
#ifdef __MMI_BRW_POST_SESSION_INFO__
	case SRV_BRW_NVRAM_SETTINGS_POST_SESSION_INFO:
		WriteValue(NVRAM_BRW_SETTINGS_POST_SESSION_INFO, &(g_srv_brw_cntx.post_session_info_status), DS_BYTE, &error);
		break;
#endif /* __MMI_BRW_POST_SESSION_INFO__ */
#ifdef OBIGO_Q05A
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
	case SRV_BRW_NVRAM_RECENT_PAGES_SORTING_METHOD:
		WriteValue(NVRAM_BRW_RECENT_PAGES_SORTING_METHOD, &(g_srv_brw_cntx.sorting_method), DS_BYTE, &error);
		break;
#endif
#endif /* #ifdef OBIGO_Q05A */
	case SRV_BRW_NVRAM_SETTINGS_HOMEPAGE:
		WriteValue(NVRAM_BRW_SETTINGS_HOMEPAGE, &(g_srv_brw_cntx.homepage_setting), DS_BYTE, &error);
		break;
#ifdef __COSMOS_MMI_PACKAGE__
	case SRV_BRW_NVRAM_SETTINGS_SEARCH_ENGINE:
		WriteValue(NVRAM_BRW_SETTINGS_SEARCH_ENGINE, &(g_srv_brw_cntx.sel_search_engine), DS_BYTE, &error);
		break;
	case SRV_BRW_NVRAM_SETTINGS_HISTORY:
		WriteValue(NVRAM_BRW_SETTINGS_HISTORY, &(g_srv_brw_cntx.history_setting), DS_BYTE, &error);
		break;
	case SRV_BRW_NVRAM_SETTINGS_PRIVATE_MODE:
		WriteValue(NVRAM_BRW_SETTINGS_PRIVATE_MODE, &(g_srv_brw_cntx.private_mode_setting), DS_BYTE, &error);
		break;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0
#endif
#ifdef __BAIDU_TRANSCODING_SUPPORT__
    case SRV_BRW_NVRAM_SETTINGS_BAIDU_PROXY:
        WriteValue(NVRAM_BRW_SETTINGS_BAIDU_PROXY, &(g_srv_brw_cntx.baidu_proxy_status), DS_BYTE, &error);
        break;
#endif // #ifdef __BAIDU_TRANSCODING_SUPPORT__
	}
}


#ifdef WAP_SEC_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  srv_brw_settings_trusted_certificates_list_get_item
 * DESCRIPTION
 *  Item call back function for dynamic list of trusted certificates
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 *  str_buff            [IN]        Buffer to be shown
 *  img_buff_p          [IN]        Image to be shown
 *  str_img_mask        [IN]        
 * RETURNS
 *  TRUE, if successfull otherwise FALSE
 *****************************************************************************/
pBOOL srv_brw_settings_trusted_certificates_list_get_item(
        S32 item_index,
        UI_string_type str_buff,
		U16 buff_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2ncpy((S8*) str_buff, (S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[item_index].name, buff_len); 
    return TRUE;
}
#endif /* WAP_SEC_SUPPORT */

/*****************************************************************************
 * FUNCTION
 *  srv_brw_settings_read_browser_preferences
 * DESCRIPTION
 *  To read the updated Browser preferences from NVRAM 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_settings_read_browser_preferences(void)
{
	srv_brw_read_settings_data(SRV_BRW_NVRAM_TIMEOUT_VALUE);
	srv_brw_read_settings_data(SRV_BRW_NVRAM_SHOW_IMAGE_MODE);
#ifdef OBIGO_Q05A
	srv_brw_read_settings_data(SRV_BRW_NVRAM_SETTINGS_SHOW_VIDEO);
	srv_brw_read_settings_data(SRV_BRW_NVRAM_SETTINGS_PLAY_SOUND);
	srv_brw_read_settings_data(SRV_BRW_NVRAM_SETTINGS_LOAD_UNKOWN_MEDIA);
	srv_brw_read_settings_data(SRV_BRW_NVRAM_SETTINGS_CSS);
	srv_brw_read_settings_data(SRV_BRW_NVRAM_SETTINGS_SCRIPTS);
#endif /* OBIGO_Q05A */
	srv_brw_read_settings_data(SRV_BRW_NVRAM_SETTINGS_CACHE);
	srv_brw_read_settings_data(SRV_BRW_NVRAM_SETTINGS_COOKIE);
#ifdef BRW_KEYPAD_SHORTCUTS_SUPPORT
	srv_brw_read_settings_data(SRV_BRW_NVRAM_SETTINGS_SHORTCUTS);
#endif /* BRW_KEYPAD_SHORTCUTS_SUPPORT */
#ifdef BRW_SECURITY_WARNINGS_SUPPORT
	srv_brw_read_settings_data(SRV_BRW_NVRAM_SETTINGS_SECURITY_WARNINGS);
#endif /* BRW_SECURITY_WARNINGS_SUPPORT */
#ifdef BRW_SEND_DEVICE_ID_SUPPORT
	srv_brw_read_settings_data(SRV_BRW_NVRAM_SETTINGS_SEND_DEVICE_ID);
#endif /* #ifdef BRW_SEND_DEVICE_ID_SUPPORT */
#ifdef __MMI_BRW_POST_SESSION_INFO__
	srv_brw_read_settings_data(SRV_BRW_NVRAM_SETTINGS_POST_SESSION_INFO);
#endif /* #ifdef __MMI_BRW_POST_SESSION_INFO__ */
#ifdef __COSMOS_MMI_PACKAGE__
	srv_brw_read_settings_data(SRV_BRW_NVRAM_SETTINGS_SEARCH_ENGINE);
	srv_brw_read_settings_data(SRV_BRW_NVRAM_SETTINGS_HISTORY);
	srv_brw_read_settings_data(SRV_BRW_NVRAM_SETTINGS_PRIVATE_MODE);
#if 0
/* under construction !*/
#endif //0
#endif
#ifdef __BAIDU_TRANSCODING_SUPPORT__
    srv_brw_read_settings_data(SRV_BRW_NVRAM_SETTINGS_BAIDU_PROXY);
#endif // #ifdef __BAIDU_TRANSCODING_SUPPORT__
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_settings_read_browser_options
 * DESCRIPTION
 *  To read the updated Browser options from NVRAM 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef OBIGO_Q05A
void srv_brw_settings_read_browser_options(void)
{
	srv_brw_read_settings_data(SRV_BRW_NVRAM_SETTINGS_RENDER_MODE);
	srv_brw_read_settings_data(SRV_BRW_NVRAM_SETTINGS_NAVIGATE_MODE);
#ifdef __MMI_VECTOR_FONT_SUPPORT__
	srv_brw_read_settings_data(SRV_BRW_NVRAM_SETTINGS_FONT_SIZE);
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */
	srv_brw_read_settings_data(SRV_BRW_NVRAM_SETTINGS_THUMBNAIL);
	srv_brw_read_settings_data(SRV_BRW_NVRAM_SETTINGS_SCREEN_SIZE);
	srv_brw_read_settings_data(SRV_BRW_NVRAM_SETTINGS_ENCODE_METHOD_INDEX);
}
#endif /* OBIGO_Q05A */



/*****************************************************************************
 * FUNCTION
 *  srv_brw_settings_read_browser_options
 * DESCRIPTION
 *  To initialize NVRAM data at boot up 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_settings_nvram_data_init(void)
{
#ifdef OBIGO_Q05A
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
	srv_brw_read_settings_data(SRV_BRW_NVRAM_RECENT_PAGES_SORTING_METHOD);
#endif
	srv_brw_settings_read_browser_options();
#endif /* OBIGO_Q05A */
	srv_brw_settings_read_browser_preferences();
    srv_brw_read_settings_data(SRV_BRW_NVRAM_SETTINGS_HOMEPAGE);
}
void srv_brw_settings_update_all_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef OBIGO_Q05A
        WriteValue(NVRAM_BRW_SETTINGS_NAVIGATE_MODE, &(g_srv_brw_cntx.navigation_mode), DS_BYTE, &error);
        WriteValue(NVRAM_BRW_SETTINGS_THUMBNAIL, &(g_srv_brw_cntx.thumbnail_status), DS_BYTE, &error);
		WriteValue(NVRAM_BRW_SETTINGS_RENDER_MODE, &(g_srv_brw_cntx.rendering_mode), DS_BYTE, &error);
#ifdef __MMI_VECTOR_FONT_SUPPORT__
		WriteValue(NVRAM_BRW_SETTINGS_FONT_SIZE, &(g_srv_brw_cntx.font_size), DS_BYTE, &error);
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */
#endif /* OBIGO_Q05A */
		WriteValue(NVRAM_BRW_SETTINGS_SCREEN_SIZE, &(g_srv_brw_cntx.screen_size_status), DS_BYTE, &error);
#ifdef OBIGO_Q05A
		WriteValue(NVRAM_BRW_SETTINGS_ENCODE_METHOD_INDEX, &(g_srv_brw_cntx.encoding_method_index), DS_BYTE, &error);
		WriteValue(NVRAM_BRW_SETTINGS_SHOW_VIDEO, &(g_srv_brw_cntx.show_videos_status), DS_BYTE, &error);
		WriteValue(NVRAM_BRW_SETTINGS_PLAY_SOUND, &(g_srv_brw_cntx.play_sounds_status), DS_BYTE, &error);
		WriteValue(NVRAM_BRW_SETTINGS_LOAD_UNKOWN_MEDIA, &(g_srv_brw_cntx.load_unknown_media_status), DS_BYTE, &error);
		WriteValue(NVRAM_BRW_SETTINGS_CSS, &(g_srv_brw_cntx.css_status), DS_BYTE, &error);
		WriteValue(NVRAM_BRW_SETTINGS_SCRIPTS, &(g_srv_brw_cntx.script_status), DS_BYTE, &error);
#endif /* OBIGO_Q05A */
		WriteValue(NVRAM_BRW_SETTINGS_CACHE, &(g_srv_brw_cntx.cache_status), DS_BYTE, &error);
		WriteValue(NVRAM_BRW_SETTINGS_COOKIE, &(g_srv_brw_cntx.cookie_status), DS_BYTE, &error);
		WriteValue(NVRAM_BRW_PAGE_TIME_OUT_VALUE, &(g_srv_brw_cntx.timeout_value), DS_SHORT, &error);
		WriteValue(NVRAM_BRW_SHOW_IMAGE_MODE, &(g_srv_brw_cntx.show_images_status), DS_BYTE, &error);
#ifdef BRW_KEYPAD_SHORTCUTS_SUPPORT
		WriteValue(NVRAM_BRW_SETTINGS_SHORTCUTS, &(g_srv_brw_cntx.shortcuts_status), DS_BYTE, &error);
#endif /* BRW_KEYPAD_SHORTCUTS_SUPPORT */
#ifdef BRW_SECURITY_WARNINGS_SUPPORT
		WriteValue(NVRAM_BRW_SETTINGS_SECURITY_WARNINGS, &(g_srv_brw_cntx.security_warnings_status), DS_BYTE, &error);
#endif /* BRW_SECURITY_WARNINGS_SUPPORT */
#ifdef BRW_SEND_DEVICE_ID_SUPPORT
		WriteValue(NVRAM_BRW_SETTINGS_SEND_DEVICE_ID, &(g_srv_brw_cntx.send_device_id_status), DS_BYTE, &error);
#endif /* BRW_SEND_DEVICE_ID_SUPPORT */
#ifdef __MMI_BRW_POST_SESSION_INFO__
		WriteValue(NVRAM_BRW_SETTINGS_POST_SESSION_INFO, &(g_srv_brw_cntx.post_session_info_status), DS_BYTE, &error);
#endif /* __MMI_BRW_POST_SESSION_INFO__ */
#ifdef OBIGO_Q05A
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
		WriteValue(NVRAM_BRW_RECENT_PAGES_SORTING_METHOD, &(g_srv_brw_cntx.sorting_method), DS_BYTE, &error);
#endif
#endif /* #ifdef OBIGO_Q05A */
		WriteValue(NVRAM_BRW_SETTINGS_HOMEPAGE, &(g_srv_brw_cntx.homepage_setting), DS_BYTE, &error);
#ifdef __COSMOS_MMI_PACKAGE__
		WriteValue(NVRAM_BRW_SETTINGS_SEARCH_ENGINE, &(g_srv_brw_cntx.sel_search_engine), DS_BYTE, &error);
		WriteValue(NVRAM_BRW_SETTINGS_HISTORY, &(g_srv_brw_cntx.history_setting), DS_BYTE, &error);
		WriteValue(NVRAM_BRW_SETTINGS_PRIVATE_MODE, &(g_srv_brw_cntx.private_mode_setting), DS_BYTE, &error);
#endif
#ifdef __BAIDU_TRANSCODING_SUPPORT__
        WriteValue(NVRAM_BRW_SETTINGS_BAIDU_PROXY, &(g_srv_brw_cntx.baidu_proxy_status), DS_BYTE, &error);
#endif // #ifdef __BAIDU_TRANSCODING_SUPPORT__
}
#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERSRVSETTINGS_C */
