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
 *  vadp_p2v_op01_hs.cpp
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
     
#ifdef __MMI_VUI_SHELL_OP01_HOMESCREEN__

#include "MMI_include.h"
#include "SettingGprots.h"

#include "vadp_v2p_op01_hs.h"
#include "mmi_rp_app_venus_shell_op01_hs_def.h"

#include "gui_effect_oem.h"
#include "DialerGprot.h"
#include "MainMenuProt.h"

#include "PhoneSetupGprots.h"
#include "SettingProfileEnum.h"
#include "IdleAppDef.h"
#include "IdleAppProt.h"
#include "CallSetUp.h"
#include "UCMGProt.h"  /* mmi_um_pre_entry_sms_inbox */
#include "UmSrvGprot.h"

#include "PhoneBookResDef.h" /* for STR_ID_PHB_UNNAMED*/

#include "SATGProts.h"     /* AP SIM Toolkit [STK]  */

#include "WguiCategoryGprot.h" 
#include "PixcomFontEngine.h"

#ifdef __MMI_BT_SUPPORT__
#include "BTMMIScrGprots.h"  /* AP Connections [CNX] */
#endif

#include "CallSetSrvGprot.h"  /* SS 10A split */
#include "ScrLockerGprot.h"  /* mmi_scr_locker_is_locked */
#include "CallLogSrvGprot.h"  /* Call log 10A split */
#include "ProfilesSrvGprot.h"  /* Profile 10A split */

#include "SmsSrvGprot.h"
#include "MmsSrvGprot.h"
//#include "MMSAppOp.h"  /* AP Message [MES] MMS  */
#include "CallLogGprot.h" /* mmi_clog_op11_hs32_sb_check_num, mmi_clog_op11_hs32_shct_query_data, mmi_clog_mclt_launch */

#include "browser_api.h"


#include "gui_config.h" /* for GUI_TEXT_TRUNCATE_SUFFIX */

#include "modeswitchsrvgprot.h" /* srv_mode_switch_get_current_mode() */

#ifdef __MMI_WLAN_FEATURES__
#include "DtcntSrvGprot.h"
#include "DtcntSrvIprot.h"
#include "DtcntSrvIntEnum.h"
extern srv_dtcnt_wlan_state_enum srv_dtcnt_wlan_state(void);  /* DtcntSrvWlan.h */
extern srv_dtcnt_result_enum mmi_wlan_cmcc_entry_deinit(srv_dtcnt_wlan_cb_func_ptr callback, void *user_data);
#endif

#include "NetSetSrvGprot.h"

#include "IdleGprot.h"

#include "vadp_p2v_op01_hs.h"

#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
//#include "DTVPlayerGprot.h"
extern void mmi_dtv_player_launch(void);
#endif

#ifdef __MMI_MOBILE_VIDEO__
#include "CM_Utils.h"
#endif

#include "HomeScreenOp01Def.h"

#ifdef __J2ME__
#include "JavaAgencyGProt.h"
#endif

/* DateAndTime.c */
extern void mmi_entry_phnset_time_format(void); /* add for OP01HS */

/* MainMenu.c  */
extern void goto_op01_online_sales(void);

#ifdef __MMI_139_PUSH_MAIL__
extern void PushMail_MMI_Entry(void);
#endif

#ifdef __MMI_WLAN_FEATURES__
static void vadp_v2p_hs_switch_wlan_rsp(void *user_data, srv_dtcnt_wlan_req_res_enum res);
#endif


/************************************************************/
/*															*/
/*			MIDlet launch functions 								*/
/*															*/
/************************************************************/

#ifdef __MMI_OP01_HS_MIDLET_CMREAD__
void vadp_v2p_hs_op01_midlet_launch_cmread(void)
{
    mmi_java_launch_midlet((kal_char*)L"00000001_");
    //jam_storage.c  getStorageNumberFromName
}
#endif

#ifdef __MMI_OP01_HS_MIDLET_FETION__
void vadp_v2p_hs_op01_midlet_launch_fetion(void)
{
    mmi_java_launch_midlet((kal_char*)L"00000002_");
}
#endif

#ifdef __MMI_OP01_HS_MIDLET_MAP__
void vadp_v2p_hs_op01_midlet_launch_map(void)
{
    mmi_java_launch_midlet((kal_char*)L"00000003_");
}
#endif

#ifdef __MMI_OP01_HS_MIDLET_MM__
void vadp_v2p_hs_op01_midlet_launch_mm(void)
{
    mmi_java_launch_midlet((kal_char*)L"00000004_");
}
#endif

#ifdef __MMI_OP01_HS_MIDLET_STOCK__
void vadp_v2p_hs_op01_midlet_launch_stock(void)
{
    mmi_java_launch_midlet((kal_char*)L"00000005_");
}
#endif

#ifdef __MMI_OP01_HS_MIDLET_MUSIC__
void vadp_v2p_hs_op01_midlet_launch_music(void)
{
    mmi_java_launch_midlet((kal_char*)L"00000006_");
}
#endif


/************************************************************/
/*															*/
/*			Global variable 									*/
/*															*/
/************************************************************/

const static vadp_v2p_op01_hs_shct_struct g_op01_hs_shct_info[] = 
{
#ifdef __MMI_139_PUSH_MAIL__
    {VAPP_SHELL_IMG_OP01HS_SC_MAIL, PushMail_MMI_Entry},
#endif
#ifdef __MMI_OP01_HS_MIDLET_FETION__
    {VAPP_SHELL_IMG_OP01HS_SC_FETION, vadp_v2p_hs_op01_midlet_launch_fetion},
#endif
#ifdef __MMI_OP01_HS_MIDLET_MAP__
    {VAPP_SHELL_IMG_OP01HS_SC_MAP, vadp_v2p_hs_op01_midlet_launch_map},
#endif
    {VAPP_SHELL_IMG_OP01HS_SC_MO, vadp_v2p_op01_hs_start_homepage_by_cmwap},
//    {VAPP_SHELL_IMG_OP01HS_SC_MO, wap_internet_key_hdlr},
#ifdef __MMI_OP01_HS_MIDLET_STOCK__
    {VAPP_SHELL_IMG_OP01HS_SC_STOCK, vadp_v2p_hs_op01_midlet_launch_stock},
#endif
#ifdef __MMI_OP01_HS_MIDLET_MUSIC__
    {VAPP_SHELL_IMG_OP01HS_SC_MUSIC, vadp_v2p_hs_op01_midlet_launch_music},
#endif
#ifdef __MMI_OP01_HS_MIDLET_MM__
    {VAPP_SHELL_IMG_OP01HS_SC_MARKET, vadp_v2p_hs_op01_midlet_launch_mm},
#endif
#ifdef __MMI_OP01_HS_MIDLET_CMREAD__
    {VAPP_SHELL_IMG_OP01HS_SC_READER, vadp_v2p_hs_op01_midlet_launch_cmread},
#endif
#if defined(__OP01_3G__) && defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
    {VAPP_SHELL_IMG_OP01HS_SC_TV, mmi_dtv_player_launch},
#endif
#ifdef __MMI_MOBILE_VIDEO__
    {VAPP_SHELL_IMG_OP01HS_SC_MOBILE_VIDEO, mmi_mobilevideo_launch},
#endif
    {VAPP_SHELL_IMG_OP01HS_SC_10086, goto_op01_online_sales},
    {-1,     NULL}
};

static VfxS32 first_icon_index = 0;

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_get_wallpaper_id
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  VfxU16
 *****************************************************************************/
VfxU16 vadp_v2p_hs_get_wallpaper_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern VfxU16 idle_screen_wallpaper_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (VfxU16)idle_screen_wallpaper_ID;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_phnset_check_themeid_wallpaper
 * DESCRIPTION
 *  This function checks whether the wallpaper comes from the theme.
 * PARAMETERS
 *  id              : [IN]          Resource ID
 * RETURNS
 *  void
 *****************************************************************************/
VfxS8 vadp_v2p_hs_phnset_check_themeid_wallpaper(VfxU16 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_phnset_check_themeid_wallpaper(id)? 1: 0;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_get_theme_bg_filled_area
 * DESCRIPTION
 *  This function gets the filled area of the theme idle background.
 * PARAMETERS
 *  id              : [IN]          Resource ID
 * RETURNS
 *  void
 *****************************************************************************/
UI_filled_area *vadp_v2p_hs_get_theme_bg_filled_area(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern MMI_theme *current_MMI_theme;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_MMI_theme && current_MMI_theme->idle_bkg_filler)
    {
        return current_MMI_theme->idle_bkg_filler;
    }
    else
    {
        return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_get_wallpaper_filename_original
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxWChar* vadp_v2p_hs_get_wallpaper_filename_original(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern VfxS8 *idle_screen_wallpaper_name_original;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (VfxWChar*)idle_screen_wallpaper_name_original;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_get_wallpaper_filename_cached
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxWChar* vadp_v2p_hs_get_wallpaper_filename_cached(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern VfxS8 *idle_screen_wallpaper_name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (VfxWChar*)idle_screen_wallpaper_name;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_phnset_wallpaper_bad_file_callback
 * DESCRIPTION
 *  This function callbacks to phone setup to handle the bad wallpaper file.
 * PARAMETERS
 *  is_prohibited       : [IN]      DRM rejects the file or not
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_phnset_wallpaper_bad_file_callback(VfxS8 is_prohibited)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern void PhnsetWallpaperBadFileCallBack(U16 strID);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_prohibited)
    {
        PhnsetWallpaperBadFileCallBack(STR_GLOBAL_DRM_PROHIBITED);
    }
    else
    {
        PhnsetWallpaperBadFileCallBack(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_launch_dialer
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_launch_dialer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_sse_setup_scenario(GUI_SSE_SCENARIO_FROM_VENUS_HS_SHORTCUT);

    mmi_dialer_launch();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_launch_main_menu
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_launch_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    goto_main_menu();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_launch_date_time
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_launch_date_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_entry_phnset_time_format();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_launch_call_inbox
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS  
 *  void
 *****************************************************************************/
void vadp_v2p_hs_launch_call_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern void mmi_clog_mclt_launch(void);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clog_mclt_launch();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_launch_sms_inbox
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_launch_sms_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern void mmi_um_launch_inbox_with_sms_only(void);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_launch_inbox_with_sms_only();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_launch_mms_inbox
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_launch_mms_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern void mmi_um_launch_inbox_with_mms_only(void);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_um_launch_inbox_with_mms_only();
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_switch_wlan_req
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_switch_wlan_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WLAN_FEATURES__
    U8 wlan_state = 0; /* 1: ON; 0: OFF */
    srv_dtcnt_result_enum ret = SRV_DTCNT_RESULT_SUCCESS;
#endif /* __MMI_WLAN_FEATURES__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // Call WLAN switch API and the state needs AP to store it.
#ifdef __MMI_WLAN_FEATURES__
    if ((srv_dtcnt_wlan_status() == SRV_DTCNT_WLAN_STATUS_ACTIVE) ||
        (srv_dtcnt_wlan_status() == SRV_DTCNT_WLAN_STATUS_CONNECTED))
    {
        wlan_state = 1;
    }
    else
    {
        wlan_state = 0;
    }

    if (wlan_state)
    {
        ret = mmi_wlan_cmcc_entry_deinit(vadp_v2p_hs_switch_wlan_rsp, NULL);
    }
    else
    {
        ret = srv_dtcnt_wlan_init(NULL, NULL);
//        ret = srv_dtcnt_wlan_init(vadp_v2p_hs_switch_wlan_rsp, NULL);
//        srv_dtcnt_wlan_auto_pw_on();
//        if (mmi_wlan_is_auto_conn_on())
//        {
//            ret = srv_dtcnt_wlan_connect_by_db_prof(NULL, NULL);
//        }
//        else
//        {
//            ret = srv_dtcnt_wlan_init(NULL, NULL);
//        }        
//        ret = srv_dtcnt_wlan_connect_by_db_prof(NULL, NULL);
    }

    if (ret == SRV_DTCNT_RESULT_FAILED)
    {
        vadp_v2p_hs_switch_wlan_rsp(NULL, ret);
    }
#endif /* __MMI_WLAN_FEATURES__ */

}

#ifdef __MMI_WLAN_FEATURES__
/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_switch_wlan_rsp
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_switch_wlan_rsp(void *user_data, srv_dtcnt_wlan_req_res_enum res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (res == SRV_DTCNT_WLAN_REQ_RES_DONE)
    {
        vadp_p2v_hs_update_wlan_button();
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_get_wlan_state
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
op01_hs_wlan_state_enum vadp_v2p_hs_get_wlan_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    op01_hs_wlan_state_enum wlan_state = OP01_HS_WLAN_POWER_OFF;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WLAN_FEATURES__
    switch (srv_dtcnt_wlan_state())
    {
        case SRV_DTCNT_WLAN_STATE_NULL:
            wlan_state = OP01_HS_WLAN_POWER_OFF;
            break;

        case SRV_DTCNT_WLAN_STATE_INIT_WAIT:
        case SRV_DTCNT_WLAN_STATE_DEINIT_WAIT:
            wlan_state = OP01_HS_WLAN_POWER_WAITING;
            break;

        case SRV_DTCNT_WLAN_STATE_INIT:
            wlan_state = OP01_HS_WLAN_POWER_ON;
            break;
            
        case SRV_DTCNT_WLAN_STATE_CONNECT_WAIT:
        case SRV_DTCNT_WLAN_STATE_DISCONNECT_WAIT:
            wlan_state = OP01_HS_WLAN_CONNECT_WAITING;
            break;
            
        case SRV_DTCNT_WLAN_STATE_CONNECTED:
            wlan_state = OP01_HS_WLAN_CONNECTED;
            break;
            
        default:
            wlan_state = OP01_HS_WLAN_POWER_OFF;
            break;
    }
#endif /* __MMI_WLAN_FEATURES__ */

    return wlan_state;
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_get_unread_sms_number
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxS32 vadp_v2p_hs_get_unread_sms_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxS32 number = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_sms_is_sms_ready())
    {
        number = srv_sms_get_unread_sms_num();
    }

    return number;
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_switch_wlan_req
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxS32 vadp_v2p_hs_get_unread_mms_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxS32 number = 0;
    S32 result = 0;
    srv_mms_get_msg_count_struct msg_count_req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

//    if (srv_mms_is_wap_ready())
//    {
        memset(&msg_count_req,0, sizeof(srv_mms_get_msg_count_struct));
        msg_count_req.count = 1;
        msg_count_req.req_tb[0] = SRV_MMS_QUERY_TOTAL_UNREAD_INBOX_MSG;
        result = srv_mms_get_msg_count(&msg_count_req);

        if (result == SRV_MMS_RESULT_OK)
        {
            number = msg_count_req.rsp_tb[0];
        }
//    }

    return number;
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_switch_wlan_req
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxS32 vadp_v2p_hs_get_unread_call_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxS32 number = 0;
    extern S32 mmi_clog_is_ready(void);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_clog_is_ready())
    {
        number = (VfxS32)srv_clog_get_unread_missed_call_num();
    }

    return number;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_switch_wlan_req
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxS32 vadp_v2p_hs_is_search_box_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxS32 is_enable = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return is_enable;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_switch_wlan_req
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxS32 vadp_v2p_hs_is_wlan_box_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxS32 is_enable = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WLAN_FEATURES__
    is_enable = 1;

    if (srv_mode_switch_get_current_mode() == SRV_MODE_FLIGHT_MODE)
    {
        is_enable = 0;
    }

    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* 0 */

#endif /* __MMI_WLAN_FEATURES__ */

    return is_enable;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_op01_shell_idle_update
 * DESCRIPTION
 *  This function sets wlan button state.
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_shell_op01_hs_update(S32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxS32 num = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(id)
    {
        case 0:
            num = vadp_v2p_hs_get_unread_sms_number();
            vadp_p2v_hs_update_hint_button(BUTTON_TYPE_SMS, num);
            break;

        case 1:
            num = vadp_v2p_hs_get_unread_mms_number();
            vadp_p2v_hs_update_hint_button(BUTTON_TYPE_MMS, num);
            break;

        case 2:
            num = vadp_v2p_hs_get_unread_call_number();
            vadp_p2v_hs_update_hint_button(BUTTON_TYPE_CALL, num);
            break;

        default:
            MMI_EXT_ASSERT(MMI_FALSE, id, 0, 0);
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_shell_op01_hs_evt_hdlr
 * DESCRIPTION
 *  This function is the event hander.
 * PARAMETERS
 *  event           : [IN]      Event structure
 * RETURNS
 *  MMI_RET_OK.
 *****************************************************************************/
mmi_ret mmi_shell_op01_hs_evt_hdlr(mmi_event_struct* event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_idle_is_active())
    {
        switch (event->evt_id)
        {
            case EVT_ID_SRV_SMS_READY:
            case EVT_ID_SRV_SMS_ADD_MSG:
            case EVT_ID_SRV_SMS_DEL_MSG:
            case EVT_ID_SRV_SMS_UPDATE_MSG:
                mmi_shell_op01_hs_update(0);
                break;

            case EVT_ID_SRV_MMS_READY:
            case EVT_ID_SRV_UM_NOTIFY_REFRESH:
            case EVT_ID_JSR_DELETE_MMS:
                mmi_shell_op01_hs_update(1);
                break;

            case EVT_ID_SRV_CLOG_READY:
            case EVT_ID_SRV_CLOG_ADD_LOG:
            case EVT_ID_SRV_CLOG_UPDATE_LOG:
            case EVT_ID_SRV_CLOG_UPDATE_ALL:
            case EVT_ID_SRV_CLOG_DEL_LOG:
            case EVT_ID_SRV_CLOG_DEL_ALL:
            // case EVT_ID_SRV_CLOG_REFRESH:
                mmi_shell_op01_hs_update(2);
                break;

        #ifdef __MMI_WLAN_FEATURES__
            case EVT_ID_SRV_DTCNT_WLAN_ACTIVE:
            case EVT_ID_SRV_DTCNT_WLAN_CONNECTED:
            case EVT_ID_SRV_DTCNT_WLAN_INACTIVE:
            case EVT_ID_SRV_DTCNT_WLAN_SCAN:
            case EVT_ID_SRV_DTCNT_WLAN_CONNECT:
            case EVT_ID_SRV_DTCNT_WLAN_INIT_RES_IND:
            case EVT_ID_SRV_DTCNT_WLAN_DEINIT_RES_IND:
                vadp_v2p_hs_switch_wlan_rsp(NULL, SRV_DTCNT_WLAN_REQ_RES_DONE);
                break;
        #endif /* __MMI_WLAN_FEATURES__ */

            default:
                break;
        }

    }


    return MMI_RET_OK;

}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_op01_hs_get_shct_info
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_op01_hs_get_shct_info(VfxS32 *count, VfxS32 *res_id, FuncPtr *pen_handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(g_op01_hs_shct_info[i].image_id != -1)
    {
        res_id[i] = g_op01_hs_shct_info[i].image_id;
        pen_handler[i] = g_op01_hs_shct_info[i].app_entry_hdlr;
        i++;
    }
    *count = i;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_op01_hs_get_shct_info
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxS32 vadp_v2p_op01_hs_get_shct_first_icon_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return first_icon_index;
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_op01_hs_get_shct_info
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_op01_hs_set_shct_first_icon_index(VfxS32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    first_icon_index = index;
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

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

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
#endif

#if defined(OPERA_BROWSER)
#include "opera_api.h"  /* OperaApi_GotoUrlEx; vendor\opera\browser\v1_official\opdev\include */
#include "opera_browser_api.h"
#include "OpDevSystem.h"  /* OpDev_StartOperaCallback ; vendor\opera\browser\v1_official\opdev\include */
#include "DtcntSrvGprot.h"
#include "MMI_inet_app_trc.h"
#include "Common_nvram_editor_data_item.h"  /* nvram_ef_op01_hs_setting_struct */

#define URL_LEN SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN+1
void vadp_v2p_op01_hs_start_homepage_by_cmwap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_op01_hs_setting_struct hs_setting;
    srv_dtcnt_prof_str_info_qry_struct out_homepage;
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&hs_setting, 0, sizeof(hs_setting));
    ReadRecord(NVRAM_EF_OP01_HS_SETTING_LID, 1, &hs_setting, NVRAM_EF_OP01_HS_SETTING_SIZE, &error);

    if (hs_setting.dtcnt_acc_id == 0)
    {
        srv_dtcnt_get_acc_id_by_apn("CMWAP", &hs_setting.dtcnt_acc_id);
        MMI_TRACE(MMI_INET_TRC_G4_BRW, OP01_HS_GET_DTCNT_ACCID, hs_setting.dtcnt_acc_id);
        WriteRecord(NVRAM_EF_OP01_HS_SETTING_LID, 1, &hs_setting, NVRAM_EF_OP01_HS_SETTING_SIZE, &error);
    }

    memset(&out_homepage, 0, sizeof(out_homepage));
    out_homepage.dest = OslMalloc(sizeof(kal_uint8) * URL_LEN);
    memset(out_homepage.dest, 0, sizeof(kal_uint8) * URL_LEN);
    out_homepage.dest_len = SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN;

    MMI_TRACE(MMI_INET_TRC_G4_BRW, OP01_HS_GET_ACCID, hs_setting.dtcnt_acc_id);
    srv_dtcnt_get_homepage(hs_setting.dtcnt_acc_id, &out_homepage, SRV_DTCNT_ACCOUNT_PRIMARY);
    
    MMI_PRINT(MOD_MMI_INET_APP, MMI_INET_TRC_G4_BRW, "[HS]opera_adp_prof_get_profile_homepage = %s", out_homepage.dest);

    if (out_homepage.dest[0] == '\0')
    {
        memcpy(out_homepage.dest,"http://wap.monternet.com/?cp22=v22monternet",sizeof("http://wap.monternet.com/?cp22=v22monternet"));
    }

    opera_brw_api_goto_url((char*)out_homepage.dest);

//    opera_brw_api_set_homepage(out_homepage.dest, OpDev_StartOperaCallback, NULL);
//    opera_brw_api_goto_operator_homepage();

    OslMfree(out_homepage.dest);
}

#else
void vadp_v2p_op01_hs_start_homepage_by_cmwap(void)
{
    wap_internet_key_hdlr();
}
#endif


#endif /* __MMI_VUI_SHELL_OP01_HOMESCREEN__ */
