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
 *  Vapp_op01_launcher_key_mainmenu.c
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  Launcher key mainmenu launch functions
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *          HISTORY
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

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "browser_api.h"
#include "Conversions.h"
#include "JavaAppFactorySrvGprot.h"
#include "vapp_op_launcher_key_mainmenu_util.h"

#ifdef BROWSER_SUPPORT
#define MMI_OP01_ONLINE_SALES   L"http://10086.cn/m"


/*****************************************************************************
 * FUNCTION
 *  vapp_op01_mobile_portal_launch
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID vapp_op01_mobile_portal_launch(void* param, U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wap_start_browser(WAP_BROWSER_GOTO_URL, (PU8)MMI_OP01_ONLINE_SALES);
    return MMI_RET_OK;
}


#if defined(OPERA_BROWSER)
#include "opera_api.h"  /* OperaApi_GotoUrlEx; vendor\opera\browser\v1_official\opdev\include */
#include "opera_browser_api.h"
#include "OpDevSystem.h"  /* OpDev_StartOperaCallback ; vendor\opera\browser\v1_official\opdev\include */
#include "DtcntSrvGprot.h"
//#include "MMI_inet_app_trc.h"
#include "Common_nvram_editor_data_item.h"  /* nvram_ef_op01_hs_setting_struct */
#include "mmi_frm_mem_gprot.h"


#define URL_LEN SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN+1
void vapp_op01_start_homepage_by_cmwap(void)
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
//        MMI_TRACE(MMI_INET_TRC_G4_BRW, OP01_HS_GET_DTCNT_ACCID, hs_setting.dtcnt_acc_id);
        WriteRecord(NVRAM_EF_OP01_HS_SETTING_LID, 1, &hs_setting, NVRAM_EF_OP01_HS_SETTING_SIZE, &error);
    }

    memset(&out_homepage, 0, sizeof(out_homepage));
    out_homepage.dest = (CHAR *)OslMalloc(sizeof(kal_uint8) * URL_LEN);
    memset(out_homepage.dest, 0, sizeof(kal_uint8) * URL_LEN);
    out_homepage.dest_len = SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN;

//    MMI_TRACE(MMI_INET_TRC_G4_BRW, OP01_HS_GET_ACCID, hs_setting.dtcnt_acc_id);
    srv_dtcnt_get_homepage(hs_setting.dtcnt_acc_id, &out_homepage, SRV_DTCNT_ACCOUNT_PRIMARY);
    
//    MMI_PRINT(MOD_MMI_INET_APP, MMI_INET_TRC_G4_BRW, "[HS]opera_adp_prof_get_profile_homepage = %s", out_homepage.dest);

    if (out_homepage.dest[0] == '\0')
    {
        memcpy(out_homepage.dest,"http://wap.monternet.com/?cp22=v22monternet",sizeof("http://wap.monternet.com/?cp22=v22monternet"));
    }

    opera_brw_api_goto_url((char*)out_homepage.dest);

//    opera_brw_api_set_homepage(out_homepage.dest, OpDev_StartOperaCallback, NULL);
//    opera_brw_api_goto_operator_homepage();

    OslMfree(out_homepage.dest);
}
#else /* defined(OPERA_BROWSER) */
void vapp_op01_start_homepage_by_cmwap(void)
{
    wap_internet_key_hdlr();
}
#endif  /* defined(OPERA_BROWSER) */


/*****************************************************************************
 * FUNCTION
 *  vapp_op01_monternet_launch
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID vapp_op01_monternet_launch(void* param, U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vapp_op01_start_homepage_by_cmwap();
    return MMI_RET_OK;
}

#endif /* BROWSER_SUPPORT */

#ifdef __MMI_OP01_MIDLET_FETION__
/*****************************************************************************
 * FUNCTION
 *  vapp_op01_fetion_launch
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID vapp_op01_fetion_launch(void* param, U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR app_name[64] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_ucs2_to_utf8_string((kal_uint8 *)app_name, sizeof(app_name), (kal_uint8 *)vapp_op_launcher_key_midlet_info[VAPP_OP01_LAUNCHER_KEY_MIDLET_FETION].midlet_name);
    srv_java_appfactory_launch(SRV_APP_FACTORY_APP_LAUNCH_TYPE, app_name, NULL, 0);

    return MMI_RET_OK;
}
#endif

#ifdef __MMI_OP01_MIDLET_MUSIC_WALKMAN__
/*****************************************************************************
 * FUNCTION
 *  vapp_op01_music_walkman_launch
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID vapp_op01_music_walkman_launch(void* param, U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR app_name[64] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_ucs2_to_utf8_string((kal_uint8 *)app_name, sizeof(app_name), (kal_uint8 *)vapp_op_launcher_key_midlet_info[VAPP_OP01_LAUNCHER_KEY_MIDLET_MUSIC].midlet_name);
    srv_java_appfactory_launch(SRV_APP_FACTORY_APP_LAUNCH_TYPE, app_name, NULL, 0);

    return MMI_RET_OK;
}
#endif


#ifdef __MMI_OP01_MIDLET_MOBILE_MARKET__
/*****************************************************************************
 * FUNCTION
 *  vapp_op01_mobile_market_launch
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID vapp_op01_mobile_market_launch(void* param, U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR app_name[64] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_ucs2_to_utf8_string((kal_uint8 *)app_name, sizeof(app_name), (kal_uint8 *)vapp_op_launcher_key_midlet_info[VAPP_OP01_LAUNCHER_KEY_MIDLET_MOBILE_MARKET].midlet_name);
    srv_java_appfactory_launch(SRV_APP_FACTORY_APP_LAUNCH_TYPE, app_name, NULL, 0);

    return MMI_RET_OK;
}
#endif


#ifdef __MMI_OP01_MIDLET_CMREAD__
/*****************************************************************************
 * FUNCTION
 *  vapp_op01_mobile_read_launch
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID vapp_op01_mobile_read_launch(void* param, U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR app_name[64] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_ucs2_to_utf8_string((kal_uint8 *)app_name, sizeof(app_name), (kal_uint8 *)vapp_op_launcher_key_midlet_info[VAPP_OP01_LAUNCHER_KEY_MIDLET_MOBILE_READER].midlet_name);
    srv_java_appfactory_launch(SRV_APP_FACTORY_APP_LAUNCH_TYPE, app_name, NULL, 0);

    return MMI_RET_OK;
}
#endif


#ifdef __MMI_OP01_MIDLET_139MAIL__
/*****************************************************************************
 * FUNCTION
 *  vapp_op01_139_push_mail_launch
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID vapp_op01_139_push_mail_launch(void* param, U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR app_name[64] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_ucs2_to_utf8_string((kal_uint8 *)app_name, sizeof(app_name), (kal_uint8 *)vapp_op_launcher_key_midlet_info[VAPP_OP01_LAUNCHER_KEY_MIDLET_139_MAIL].midlet_name);
    srv_java_appfactory_launch(SRV_APP_FACTORY_APP_LAUNCH_TYPE, app_name, NULL, 0);

    return MMI_RET_OK;
}
#endif


#ifdef __MMI_OP01_MIDLET_MOBILE_GAME__
/*****************************************************************************
 * FUNCTION
 *  vapp_op01_mobile_game_launch
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID vapp_op01_mobile_game_launch(void* param, U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR app_name[64] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_ucs2_to_utf8_string((kal_uint8 *)app_name, sizeof(app_name), (kal_uint8 *)vapp_op_launcher_key_midlet_info[VAPP_OP01_LAUNCHER_KEY_MIDLET_MOBILE_GAME].midlet_name);
    srv_java_appfactory_launch(SRV_APP_FACTORY_APP_LAUNCH_TYPE, app_name, NULL, 0);

    return MMI_RET_OK;
}
#endif


#ifdef __MMI_OP01_MIDLET_MOBILE_STOCK__
/*****************************************************************************
 * FUNCTION
 *  vapp_op01_mobile_game_launch
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID vapp_op01_mobile_stock_launch(void* param, U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR app_name[64] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_ucs2_to_utf8_string((kal_uint8 *)app_name, sizeof(app_name), (kal_uint8 *)vapp_op_launcher_key_midlet_info[VAPP_OP01_LAUNCHER_KEY_MIDLET_MOBILE_STOCK].midlet_name);
    srv_java_appfactory_launch(SRV_APP_FACTORY_APP_LAUNCH_TYPE, app_name, NULL, 0);

    return MMI_RET_OK;
}
#endif

