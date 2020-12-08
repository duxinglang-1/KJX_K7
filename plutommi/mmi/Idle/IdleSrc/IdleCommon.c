/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  IdleCommon.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the common part of the idle application.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/****************************************************************************
 * Include
 ****************************************************************************/
#include "MMI_features.h"
#include "IdleGprot.h"
#include "DialerGprot.h"
#include "ScrLockerGprot.h"
#include "NwInfoSrvGprot.h"
#include "NwNameSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "CphsSrvGprot.h"
#include "NetworkSetupGprot.h"
#include "BrowserGprots.h"
#include "browser_api.h"
#include "MiscFunctions.h"
#include "PhbCuiGprot.h"
#include "CallLogGprot.h"
#include "ShortcutsProts.h"
#include "VolumeHandler.h"
#include "CallSetSrvGprot.h"
#include "PhoneSetupGprots.h"
#include "ImeiSrvGprot.h"
#include "netsetsrvgprot.h"
#include "AmGprot.h"
#include "NetworkSetupGProt.h"

#if defined(__MMI_SEARCH_WEB__)
#include "SearchWebGProt.h"
#endif

#if defined(__MMI_VRSD__)
#include "VRSD.h"
#endif

#if defined(__MMI_VRSI__)
#include "VRSIProt.h"
#endif

#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)
#include "MMI_features_camera.h"
#include "CameraApp.h"
#elif defined (__MMI_CAMERA__) && defined(__MMI_CAMCORDER__)
#include "CamcorderGprot.h"
#endif /* defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)*/

#ifdef __MMI_OP01_DCD__
#include "DCDGProt.h"
#include "mmi_rp_app_dcd_def.h"
#endif

#if defined(__MMI_ATV_SUPPORT__)
#include "MobileTVPlayerGProt.h"
#endif

#if (MMI_MAX_SIM_NUM >= 3)
#include "SimSpaceGprot.h"
#endif /* (MMI_MAX_SIM_NUM >= 3) */

#include "MMIDataType.h"
#include "wgui_categories_list.h"
#include "IdleMain.h"
#include "IdleObject.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "wgui_categories_util.h"
#include "mmi_frm_timer_gprot.h"
#include "TimerEvents.h"
#include "mmi_rp_app_idle_def.h"
#include "GlobalResDef.h"
#include "AlertScreen.h"
#include "mmi_frm_events_gprot.h"
#include "CommonScreensResDef.h"
#include "gui_effect_oem.h"
#include "Unicodexdcl.h"
#include "l4c_nw_cmd.h"
#include "IdleCommon.h"
#include "wgui_inputs.h"

#if defined(__OP01_FWPCOLOR__) || defined(__OP01_FWPBW__)
#include "UMGProt.h"
#include "UcmGprot.h"
#include "PhoneBookGprot.h"
#include "PhbSrvGprot.h"
#include "dialercuigprot.h"
    #ifdef __MMI_FM_RADIO__
    extern void mmi_fmrdo_run_app(void);
    #endif
#endif

/****************************************************************************
 * Global context
 ****************************************************************************/

typedef struct
{
    U8          flag;
    FuncPtr     right_softkey_hdlr;
    FuncPtr     left_softkey_hdlr;
} mmi_idle_key_cntx_struct;


static mmi_idle_key_cntx_struct g_idle_key_cntx;


/****************************************************************************
 * Define
 ****************************************************************************/

#define MMI_IDLE_KEY_DELAYED_RSK_TIMEOUT_VALUE      (500)


/****************************************************************************
 * Option Flag
 ****************************************************************************/

#define MMI_IDLE_KEY_FLAG_DISABLE_LOCK_BY_END       (1 << 0)


/* Macro: (1) set flag (2) clear flag and (3) check if flag is set. */
#define MMI_IDLE_KEY_SET(_f)       (g_idle_key_cntx.flag |= _f)
#define MMI_IDLE_KEY_CLR(_f)       (g_idle_key_cntx.flag &= ~_f)
#define MMI_IDLE_KEY_HAS(_f)       (((g_idle_key_cntx.flag & _f) == _f))


/****************************************************************************
 * Function
 ****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_rsk_hdlr
 * DESCRIPTION
 *  This function sets the right softkey handler.
 * PARAMETERS
 *  hdlr                : [IN]          Key handler
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_set_rsk_hdlr(FuncPtr hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_obj_struct *obj = mmi_idle_get_obj();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    if (hdlr)
    {
        if (!(obj->capability & ENABLE_SOFT_KEY_AREA))
        {
            SetKeyHandler(hdlr, KEY_RSK, KEY_EVENT_DOWN);
        }
        else
        {
            SetRightSoftkeyFunction(hdlr, KEY_EVENT_UP);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_rsk_view
 * DESCRIPTION
 *  This function sets the right softkey string and image.
 * PARAMETERS
 *  string_id           : [IN]          String ID
 *  image_id            : [IN]          Image ID
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_set_rsk_view(U16 string_id, U16 image_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_obj_struct *obj = mmi_idle_get_obj();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);
   
    if (obj->capability & ENABLE_SOFT_KEY_AREA)
    {
        ChangeRightSoftkey(string_id, image_id);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_csk_hdlr
 * DESCRIPTION
 *  This function sets the center softkey handler.
 * PARAMETERS
 *  hdlr                : [IN]          Key handler
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_set_csk_hdlr(FuncPtr hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_obj_struct *obj = mmi_idle_get_obj();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    if (hdlr)
    {
        if (!(obj->capability & ENABLE_SOFT_KEY_AREA))
        {
            SetKeyHandler(hdlr, KEY_CSK, KEY_EVENT_DOWN);
        }
        else
        {
            SetCenterSoftkeyFunction(hdlr, KEY_EVENT_UP);
        }
    }
}

#ifndef __MMI_WGUI_DISABLE_CSK__

/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_csk_view
 * DESCRIPTION
 *  This function sets the center softkey string and image.
 * PARAMETERS
 *  string_id           : [IN]          String ID
 *  image_id            : [IN]          Image ID
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_set_csk_view(U16 string_id, U16 image_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_obj_struct *obj = mmi_idle_get_obj();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    if (obj->capability & ENABLE_SOFT_KEY_AREA)
    {
        ChangeCenterSoftkey(string_id, image_id);
    }
}
#endif /*__MMI_WGUI_DISABLE_CSK__*/


#if defined(__MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_entry_camera_ex
 * DESCRIPTION
 *  This function entry the camera application. In addition, it will stop the
 *  current audio player.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_entry_camera_ex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Stop playing audio by camera key.
     */
#ifdef __MMI_AUDIO_PLAYER__
    if (mmi_audply_is_playing())
    {
        mmi_audply_do_stop_action(MMI_TRUE);
    }
    else
#endif /* __MMI_AUDIO_PLAYER__ */
#ifdef __MMI_FM_RADIO__
    if (mmi_fmrdo_is_power_on())
    {
        mmi_fmrdo_power_on_check(MMI_FALSE);
    }
    else
#endif /* __MMI_FM_RADIO__ */
#ifdef __A8BOX_SUPPORT__
    if (mmi_a8box_is_playing())
    {
        mmi_a8box_enter_cameraapp();
    }
#endif /* __A8BOX_SUPPORT__ */

    /*
     * Launch camera.
     */
#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)
    mmi_camera_lauch();
#elif defined (__MMI_CAMERA__) && defined(__MMI_CAMCORDER__)
    mmi_camco_launch();
#endif /* defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__) */
}
#endif /* defined(__MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__) */


#if (__MRE_AM__) && defined(__MMI_MRE_APP_OPERA_MINI__)
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_entry_mre_opera
 * DESCRIPTION
 *  This function launches the MRE Opera Mini browser.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_entry_mre_opera(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_am_start_from_mm(APPID_OPERA);
}
#endif /* (__MRE_AM__) && defined(__MMI_MRE_APP_OPERA_MINI__) */


#if defined(__OP12__)
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_entry_op12_live
 * DESCRIPTION
 *  This function launches the browser to open the OP12 home page.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_entry_op12_live(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wap_start_browser(WAP_BROWSER_GOTO_URL, (PU8)L"http://live.vodafone.com/");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_handle_delayed_rsk_timeout
 * DESCRIPTION
 *  This function is the time-out handler of the delayed RSK function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_handle_delayed_rsk_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_idle_is_active())
    {
        mmi_idle_set_rsk_hdlr(mmi_idle_entry_op12_live);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_rsk_delayed
 * DESCRIPTION
 *  This function sets the delayed RSK handler. This is a special requirement
 *  of OP12. When going back to the home screen using the back key (e.g. right
 *  soft key), the user shall be prevented from accidentally accessing the
 *  service that is assigned to this key on the home screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_set_rsk_delayed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StartTimer(
        IDLE_DELAYED_RSK_TIMER,
        MMI_IDLE_KEY_DELAYED_RSK_TIMEOUT_VALUE,
        mmi_idle_handle_delayed_rsk_timeout);
}
#endif /* __OP12__ */


#if defined(__MMI_OP01_WITH_WAP_KEY__)
#if defined(__OP01_0202__)
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
#endif /* defined(__OP01_0202__) */
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
#if defined(__OP01_0202__)
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
#endif /* defined(__MMI_OP01_WITH_WAP_KEY__)  */


#if defined(__OP01_FWPCOLOR__) || defined(__OP01_FWPBW__)
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_op01_dial_12580
 * DESCRIPTION
 *  This function is the handler for the op01 dial 12580 key.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_op01_dial_12580(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 number[SRV_UCM_MAX_NUM_URI_LEN + 1];
    mmi_ucm_make_call_para_struct make_call_para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((CHAR*)number, (CHAR*)L"12580");

    mmi_ucm_init_call_para(&make_call_para);

    make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_ALL;
    make_call_para.ucs2_num_uri = number;

    mmi_ucm_call_launch(0, &make_call_para);

}
#endif

#if defined(__OP01_FWPBW__)
static void mmi_idle_op01_direct_dial_handler(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 number[SRV_UCM_MAX_NUM_URI_LEN + 1];
    MMI_BOOL ret;
    mmi_id group_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    ret = srv_phb_get_direct_dial(index, number);
    if (ret)
    {
        group_id = cui_dialer_create(GRP_ID_IDLE_MAIN);
        cui_dialer_set_dial_string(group_id, number);
        cui_dialer_run(group_id);
    }
    else
    {
        mmi_phb_direct_dial_launch(index);
    }
}


static void mmi_idle_op01_direct_dial_0(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_idle_op01_direct_dial_handler(0);
}

static void mmi_idle_op01_direct_dial_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_idle_op01_direct_dial_handler(1);
}

static void mmi_idle_op01_direct_dial_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_idle_op01_direct_dial_handler(2);
}

static void mmi_idle_op01_direct_dial_3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_idle_op01_direct_dial_handler(3);
}

static void mmi_idle_op01_direct_dial_4(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_idle_op01_direct_dial_handler(4);
}

static void mmi_idle_op01_direct_dial_5(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_idle_op01_direct_dial_handler(5);
}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_right_soft_key_hdlr
 * DESCRIPTION
 *  This function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_set_right_soft_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = 0;
    FuncPtr hdlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Get the handler and string.
     */
#if defined(__MMI_OP01_DCD__)
    if (mmi_dcd_is_switch_on())
    {
        str_id = STR_ID_DCD;
        hdlr   = mmi_dcd_entry_main_option;
    }
    else
#endif /* defined(__MMI_OP01_DCD__) */
#if defined(__OP12__)
    if (MMI_TRUE)
    {
        str_id = STR_ID_IDLE_OP12_LIVE;
        mmi_idle_set_rsk_delayed();     /* RSK handler is delayed. */
    }
    else
#endif /* defined(__OP12__) */
    {
        str_id = STR_ID_IDLE_CONTACT;
        hdlr   = mmi_phb_idle_launch;
    }

    /*
     * Set the handler and string.
     */
    mmi_idle_set_rsk_hdlr(hdlr);
    mmi_idle_set_rsk_view(str_id, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_center_soft_key_hdlr
 * DESCRIPTION
 *  This function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_set_center_soft_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 img_id = 0;
    FuncPtr hdlr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Get the handler and string.
 	 * for FTE_KEY_ONLY, the UE of CSK is the same as LSK 
	*/
#if defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_TOUCH_SCREEN__)
	img_id = IMG_GLOBAL_COMMON_CSK;     
    hdlr = EntryMainMenuFromIdleScreen;    
#else
	img_id = IMG_GLOBAL_DIAL_PAD_CSK;    
    hdlr = mmi_dialer_launch;    
#endif
    /*
     * Set the handler and string.
     */
    mmi_idle_set_csk_hdlr(hdlr);
#ifndef __MMI_WGUI_DISABLE_CSK__
    mmi_idle_set_csk_view(0, img_id);
#endif /*__MMI_WGUI_DISABLE_CSK__*/
}



/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_send_key_hdlr
 * DESCRIPTION
 *  This function sets the send key handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_set_send_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__SENDKEY2_SUPPORT__)
    SetKeyHandler(mmi_clog_sendkey_launch, KEY_SEND, KEY_EVENT_DOWN);
#else
    SetKeyHandler(mmi_clog_sendkey_launch, KEY_SEND1, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_clog_sendkey_launch, KEY_SEND2, KEY_EVENT_DOWN);
#endif /* __SENDKEY2_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_navigation_key_hdlr
 * DESCRIPTION
 *  This function sets the navigation key handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_set_navigation_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_OP01_DCD__)
    if (mmi_dcd_is_switch_on() && mmi_dcd_is_idle_on())
    {
        SetKeyHandler(mmi_dcd_idle_prev_channel, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_dcd_idle_next_channel, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_dcd_idle_prev_entry, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_dcd_idle_next_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
#endif /* defined(__MMI_OP01_DCD__) */
    {
    #if defined(__MMI_DEDICATED_KEY_SHORTCUTS__)
        RegisterDedicatedKeyHandlers();
    #else
    #if !defined(__DISABLE_SHORTCUTS_MENU__)
        SetKeyHandler(EntryShctInIdle, KEY_UP_ARROW, KEY_EVENT_DOWN);
    #if (__MRE_AM__) && defined(__MMI_MRE_APP_OPERA_MINI__)
        SetKeyHandler(mmi_idle_entry_mre_opera, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    #endif
    #if (MMI_MAX_SIM_NUM >= 3)
        SetKeyHandler(mmi_sim_space_launch, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* !defined(__DISABLE_SHORTCUTS_MENU__) */
    #endif /* defined(__MMI_DEDICATED_KEY_SHORTCUTS__) */

    // google search handler is the highest priority
    #if defined(__MMI_SEARCH_WEB__)
        if (mmi_search_web_hot_key_is_enabled(MMI_SEARCH_WEB_HOT_KEY_DOWN_KEY))
        {
            SetKeyHandler(mmi_search_web_trigger_by_down_key, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        }
    #endif /* defined(__MMI_SEARCH_WEB__) */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_disable_lock_by_end_key
 * DESCRIPTION
 *  This function turns off the availability to lock the keypad by END key. When
 *  the unit testing is running using the tool, e.g., MSC composer, it sometimes
 *  needs to emit some END key events to make sure the handset is in the idle
 *  screen. If the "Lock keypad?" confirm screen is shown, the unit test case
 *  might fail since the handset is not in the idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_disable_lock_by_end_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_IDLE_KEY_SET(MMI_IDLE_KEY_FLAG_DISABLE_LOCK_BY_END);

    mmi_popup_display_simple(
        (WCHAR *)get_string(STR_GLOBAL_DONE),
        MMI_EVENT_SUCCESS,
        GRP_ID_ROOT,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_lock_keypad_confirm_evt_hdlr
 * DESCRIPTION
 *  This function handles the event of the lock keypad confirm screen.
 * PARAMETERS
 *  event               : [IN]              Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_idle_lock_keypad_confirm_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *evt = (mmi_alert_result_evt_struct *)event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt);

    if (evt->evt_id == EVT_ID_ALERT_QUIT && evt->result == MMI_ALERT_CNFM_YES)
    {
        mmi_idle_display();
        mmi_scr_locker_launch();
    }

    return MMI_RET_OK;
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
#endif

#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_entry_dialer_by_translate_key
 * DESCRIPTION
 *  This function is the translate key handler if APP wants to launch dialer by
 *  the tranlate key.
 * PARAMETERS
 *  key_code                : [IN]      Key code
 *  key_type                : [IN]      Key type
 *  ucs2_value              : [IN]      UCS2 value
 *  key_flag                : [IN]      Key flag
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_idle_entry_dialer_by_translate_key(
    S16 key_code,
    S16 key_type,
    U16 ucs2_value,
    U32 key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Skip non-dialer key. */
    if ((!wgui_inputs_dialer_is_dialer_keys(key_code)) ||
        (key_type != KEY_EVENT_DOWN))
    {
        return MMI_FALSE; /* continue the key routing. */
    }

    /* set SSE effect */
    gui_sse_setup_scenario(GUI_SSE_SCENARIO_FROM_IDLE);

	mmi_frm_send_incomplete_key_event_to_new_screen(MMI_TRUE);

    /* Show the dial pad. */
    mmi_dialer_launch_by_translate_key(key_code, key_type, ucs2_value, key_flag);

    return MMI_TRUE; /* stop the key routing. */
}
#else /* defined(__MMI_QWERTY_KEYPAD_SUPPORT__) */
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_entry_dialer_by_key
 * DESCRIPTION
 *  This function is the digital key handler if APP wants to launch dialer by
 *  the digital key.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_entry_dialer_by_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 key_code, key_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&key_code, &key_type);

	mmi_frm_send_incomplete_key_event_to_new_screen(MMI_TRUE);
    /* set SSE effect */
    gui_sse_setup_scenario(GUI_SSE_SCENARIO_FROM_IDLE);

    mmi_dialer_launch_by_key(key_code);
}
#endif /* defined(__MMI_QWERTY_KEYPAD_SUPPORT__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_dial_pad_hdlr
 * DESCRIPTION
 *  This function sets the dial pad handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_set_dial_pad_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_dial_key_tone_type(MMI_DIALER_KEY_TONE_DTMF);
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    mmi_frm_set_app_translate_key_handler(mmi_idle_entry_dialer_by_translate_key);

    /*
     * On QWERTY phone, the DTMF tones are played when the user wants to dial
     * calls; otherwise, normal key tone is played, e.g. in the editor. Enable
     * the DTMF tone here.
     *
     * PS. Our non-QWERTY phone will always play DTMF tone no matter in the dial
     *     pad or editor.
     */
#else
    SetGroupKeyHandler(
        mmi_idle_entry_dialer_by_key,
        (PU16)PresentAllDialerKeys,
        TOTAL_DIALER_KEYS,
        KEY_EVENT_DOWN);
#endif /* __MMI_QWERTY_KEYPAD_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_voice_recognition_hdlr
 * DESCRIPTION
 *  This function sets the voice recognition handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_VRSD__) || defined(__MMI_VRSI__)
static void mmi_idle_set_voice_recognition_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_obj_struct *obj = mmi_idle_get_obj();
    FuncPtr hdlr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

#if defined(__MMI_VRSD__)
    hdlr = mmi_vrsd_rcg_pre_entry;
#elif defined(__MMI_VRSI__)
    hdlr = mmi_vrsi_rcg_pre_entry;
#else
    hdlr = NULL;
#endif

    if (!(obj->capability & ENABLE_SOFT_KEY_AREA))
    {
        SetKeyHandler(hdlr, KEY_RSK, KEY_LONG_PRESS);
    }
    else
    {
        SetRightSoftkeyFunction(hdlr, KEY_LONG_PRESS);
    }
}
#endif /* defined(__MMI_VRSD__) || defined(__MMI_VRSI__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_camera_hdlr
 * DESCRIPTION
 *  This function sets the camera key handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined (__MMI_CAMERA__)
static void mmi_idle_set_camera_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)
    /*
     * Not support camcoder
     */
#if defined(__MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__)
    SetKeyHandler(mmi_idle_entry_camera_ex, CAMERA_SHORTCUT_KEY, KEY_EVENT_UP);
#else
    SetKeyHandler(mmi_camera_lauch, CAMERA_SHORTCUT_KEY, KEY_EVENT_DOWN);
#endif /* defined(__MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__) */
#elif defined (__MMI_CAMERA__) && defined(__MMI_CAMCORDER__)
    /*
     * Support camcoder
     */
#if defined(__MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__)
    SetKeyHandler(mmi_idle_entry_camera_ex, CAMERA_SHORTCUT_KEY, KEY_EVENT_UP);
#else
    SetKeyHandler(mmi_camco_launch, KEY_CAMERA, KEY_EVENT_DOWN);
#endif /* defined(__MMI_IDLE_CAMERA_KEY_TO_STOP_AUDIOPLAYER__) */
#endif /* defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__) */
}
#endif/*defined (__MMI_CAMERA__)*/

#if defined(__MMI_OP01_DCD__) || defined(__MMI_OP01_WITH_WAP_KEY__) || defined(__MMI_OP02_WITH_WAP_KEY__)

/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_wap_hdlr_int
 * DESCRIPTION
 *  This function sets the WAP key handler. If the handset does not have
 *  dedicated WAP key, the WAP key is the same as the center softkey. In this
 *  case, it should use the softkey API to setup the handler and follow the
 *  key rule to use the correct image icon.
 * PARAMETERS
 *  hdlr                : [IN]          WAP key handler
 *  image_id            : [IN]          WAP key icon image
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_set_wap_hdlr_int(FuncPtr hdlr, U16 image_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (hdlr)
    {
        if (KEY_WAP != KEY_CSK)
        {
            SetKeyHandler(hdlr, KEY_WAP, KEY_EVENT_UP);
        }
        else
        {
            mmi_idle_set_csk_hdlr(hdlr);
        #ifndef __MMI_WGUI_DISABLE_CSK__
            mmi_idle_set_csk_view(0, image_id);
        #endif
        }

    }
}
#endif /*defined(__MMI_OP01_DCD__) || defined(__MMI_OP01_WITH_WAP_KEY__) || defined(__MMI_OP02_WITH_WAP_KEY__)*/

/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_browser_hdlr
 * DESCRIPTION
 *  This function sets up the wap key handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_set_wap_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_OP01_DCD__)
    if (mmi_dcd_is_switch_on() && mmi_dcd_is_idle_on())
    {
        mmi_idle_set_wap_hdlr_int(
            mmi_dcd_idle_to_story_viewer,
            IMG_GLOBAL_COMMON_CSK);

    #if defined(__MMI_OP01_WITH_WAP_KEY__)
/* under construction !*/
    #endif
    }
    else
#endif /* defined(__MMI_OP01_DCD__) */
    {
    #if defined(__MMI_OP01_WITH_WAP_KEY__)
        #if defined(__OP01_3G__) && defined(__MMI_REDUCED_KEYPAD__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #else /* defined(__OP01_3G__) && defined(__MMI_REDUCED_KEYPAD__) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* defined(__OP01_3G__) && defined(__MMI_REDUCED_KEYPAD__) */
    #elif defined(__MMI_OP02_WITH_WAP_KEY__)
        mmi_idle_set_wap_hdlr_int(
            wap_internet_key_hdlr,
            IMG_GLOBAL_WEB_BROWSER_CSK);
    #elif defined(BROWSER_SUPPORT) && defined(__MMI_WITH_WAP_KEY__)
        SetKeyHandler(wap_internet_key_hdlr, KEY_WAP, KEY_LONG_PRESS);
    #endif
    }
}


#if defined(__OP01_FWPCOLOR__) || defined(__OP01_FWPBW__)

/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_op01_fwp_hdlr
 * DESCRIPTION
 *  This function sets the OP01 TD FWP keys handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_idle_set_op01_fwp_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__OP01_FWPCOLOR__)
    SetKeyHandler(mmi_idle_op01_dial_12580, KEY_F7, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_um_entry_inbox, KEY_MESSAGE, KEY_EVENT_DOWN);
#endif

#if defined(__OP01_FWPBW__)
    SetKeyHandler(mmi_idle_op01_dial_12580, KEY_F7, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_um_entry_inbox, KEY_MESSAGE, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_idle_op01_direct_dial_0, KEY_F1, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_idle_op01_direct_dial_1, KEY_F2, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_idle_op01_direct_dial_2, KEY_F3, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_idle_op01_direct_dial_3, KEY_F4, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_idle_op01_direct_dial_4, KEY_F5, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_idle_op01_direct_dial_5, KEY_F6, KEY_EVENT_DOWN);

    #ifdef __MMI_FM_RADIO__
    SetKeyHandler(mmi_fmrdo_run_app, KEY_F10, KEY_EVENT_DOWN);
    #endif
#endif

}
#endif /* defined(__OP01_FWPCOLOR__) || defined(__OP01_FWPBW__)*/
#ifndef WIN32
#include "Gpio_sw.h"
#endif
void mmi_open_watch_dog(void)
{
#if defined(CUSTOMER_NAME_B603)

#else /*CUSTOMER_NAME_B603*/
GPIO_ModeSetup(12,0);
GPIO_InitIO(1, 12);
GPIO_WriteIO(1, 12);	
#endif /* CUSTOMER_NAME_B603 */

}

/*****************************************************************************
 * FUNCTION
 *  mmi_idle_set_handler
 * DESCRIPTION
 *  This function sets the default handler according to the capability of the
 *  idle object.
 * PARAMETERS
 *  obj           : [IN]        Idle object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_set_handler(mmi_idle_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 capability; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    capability = obj->capability;

#if defined(__GGT_TASK__)
	mmi_open_watch_dog();
#if defined(__CITY_EASY_MODEL_W__)
{
    extern void city_easy_send_by_sos(void);
    extern void city_easy_send_by_key1(void);
    extern void city_easy_send_by_key2(void);
    extern void city_easy_send_by_key3(void);

    //ClearKeyEvents();
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_UP);
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_LEFT_ARROW, KEY_LONG_PRESS);

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_LONG_PRESS);

    ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_UP);
    ClearKeyHandler(KEY_UP_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_UP_ARROW, KEY_LONG_PRESS);

    ClearKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_UP);
    ClearKeyHandler(KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_DOWN_ARROW, KEY_LONG_PRESS);
	
    SetKeyHandler(city_easy_send_by_sos, KEY_LEFT_ARROW, KEY_LONG_PRESS);
    SetKeyHandler(city_easy_send_by_key1,KEY_RIGHT_ARROW, KEY_LONG_PRESS);
    SetKeyHandler(city_easy_send_by_key2, KEY_UP_ARROW, KEY_LONG_PRESS);
    SetKeyHandler(city_easy_send_by_key3, KEY_DOWN_ARROW, KEY_LONG_PRESS);

	return;
}
#elif defined(CUSTOMER_NAME_B603)
{
    extern void city_easy_send_by_sos(void);

    ClearKeyHandler(KEY_SEND, KEY_EVENT_UP);
    ClearKeyHandler(KEY_SEND, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_SEND, KEY_LONG_PRESS);
	
    //SetKeyHandler(city_easy_send_by_sos, KEY_SEND, KEY_LONG_PRESS);

	//return;
}
#endif/*__CITY_EASY_MODEL_W__*/
#endif/*__GGT_TASK__*/

#if defined(__KJX_OLED_64_48_UI__)	//xb add 2016-09-02 待机界面按键单独处理
	SetKeyHandler(EntryMainMenuFromIdleScreen, KEY_LSK, KEY_EVENT_UP);
	if (capability & ENABLE_VOLUME_CONTROL)
	{
		SetDefaultVolumeKeyHandlers();
	}

	return;
#endif/*__KJX_OLED_64_48_UI__*/

#ifdef __MMI_IDLE_CLASSIC_AND_MAINMENU_SUPPORT__
    if (capability & ENABLE_LEFT_SOFT_KEY)
    {
        if (!(obj->capability & ENABLE_SOFT_KEY_AREA))
        {
            SetKeyHandler(EntryMainMenuFromIdleScreen, KEY_LSK, KEY_EVENT_DOWN);
        }
        else
        {
            SetLeftSoftkeyFunction(EntryMainMenuFromIdleScreen, KEY_EVENT_UP);
            ChangeLeftSoftkey(STR_ID_IDLE_MAIN_MENU, 0);
        }
    }
#endif /*__MMI_IDLE_CLASSIC_AND_MAINMENU_SUPPORT__*/

    if (capability & ENABLE_RIGHT_SOFT_KEY)
    {
        mmi_idle_set_right_soft_key_hdlr();
    }
    if (capability & ENABLE_CENTER_SOFT_KEY)
    {
        mmi_idle_set_center_soft_key_hdlr();
    }
    if (capability & ENABLE_SEND_KEY)
    {
        mmi_idle_set_send_key_hdlr();
    }

    if (capability & ENABLE_NAVIGATION_KEY)
    {
        mmi_idle_set_navigation_key_hdlr();
    }

#if (!defined(__GGT_TASK__))
    if (capability & ENABLE_END_KEY)
    {
        //SetKeyHandler(mmi_idle_entry_lock_keypad_confirm, KEY_END, KEY_EVENT_UP);
        SetKeyHandler(mmi_scr_locker_launch, KEY_END, KEY_EVENT_UP);
    }
#endif

    if (capability & ENABLE_DIALER)
    {
        mmi_idle_set_dial_pad_hdlr();
    }

#if defined(__MMI_VRSD__) || defined(__MMI_VRSI__)
    if (capability & ENABLE_VOICE_RECOGNITION)
    {
        mmi_idle_set_voice_recognition_hdlr();
    }
#endif

#if defined (__MMI_CAMERA__)
    if (capability & ENABLE_CAMERA)
    {
        mmi_idle_set_camera_hdlr();
    }
#endif

    if (capability & ENABLE_WAP)
    {
        mmi_idle_set_wap_hdlr();
    }

#if defined(__MMI_MAPBAR_GIS__)
    if (capability & ENABLE_GIS)
    {
        SetKeyHandler(mmi_gis_enter_app_check_conform, KEY_EXTRA_2, KEY_EVENT_UP);        
    }
#endif

#if defined(__MMI_ATV_SUPPORT__)
    if (capability & ENABLE_MTV)
    {        
        SetKeyHandler(mmi_mtv_player_launch, KEY_EXTRA_1, KEY_EVENT_DOWN);        
    }
#endif

#if defined(__OP01_FWPCOLOR__) || defined(__OP01_FWPBW__)
    if (capability & ENABLE_OP01_FWP_KEY)
    {
        mmi_idle_set_op01_fwp_hdlr();
    }
#endif

 
}


#if defined(__HOMEZONE_SUPPORT__ )
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_get_homezone_string
 * DESCRIPTION
 *  This function prepares the service string in the homezone situation.
 * PARAMETERS
 *  sim                     : [IN]            SIM ID
 *  service_indication      : [OUT]           mmi_idle_service_indication_struct
 * RETURNS
 *  In homezone, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL mmi_idle_get_homezone_string(
    mmi_sim_enum sim,
    mmi_idle_service_indication_struct *service_indication)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_homezone_info_struct homezone;
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_nw_info_get_homezone_info(sim, &homezone);
    if (!ret || !homezone.is_in_homezone)
    {
        return MMI_FALSE; /* It's not in home zone. */
    }

    mmi_wcsncpy(service_indication->line2, homezone.tag, MMI_IDLE_NW_NAME_MAX_STR_LEN);

    return MMI_TRUE;
}
#endif /* defined(__HOMEZONE_SUPPORT__ ) */


#if defined(__OP12__) && defined(__NBR_CELL_INFO__)
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_get_cell_info_string
 * DESCRIPTION
 *  This function gets the service string in the cell info.
 * PARAMETERS
 *  sim                     : [IN]            SIM ID
 *  service_indication      : [OUT]           mmi_idle_service_indication_struct
 * RETURNS
 *  If cell info is present, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL mmi_idle_get_cell_info_string(
    mmi_sim_enum sim,
    mmi_idle_service_indication_struct *service_indication)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_location_info_struct location;
    MMI_BOOL is_valid;
    CHAR tmp_ascii[32]; /* 32 is large enough for any cell info string. */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_valid = srv_nw_info_get_location_info(sim, &location);
    if (is_valid)
    {
        kal_snprintf(
            (kal_char *)tmp_ascii,
            sizeof(tmp_ascii),
            "%s %d %d",
            location.plmn,
            location.lac,
            location.cell_id);

        mmi_asc_n_to_wcs(service_indication->line2, tmp_ascii, SRV_NW_NAME_MAX_STR_LEN);

        return MMI_TRUE;
    }

    return MMI_FALSE;
}
#endif /* defined(__OP12__) && defined(__NBR_CELL_INFO__) */


#if defined(__MMI_IDLE_SCREEN_OWNER_NUMBER__)
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_get_msisdn_type
 * DESCRIPTION
 *  This function gets the MSISDN type.
 * PARAMETERS
 *  sim             : [IN]              SIM id
 * RETURNS
 *  srv_cphs_msisdn_type_enum
 *****************************************************************************/
static srv_cphs_msisdn_type_enum mmi_idle_get_msisdn_type(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_line_id_enum line_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    line_id = srv_callset_line_switch_get_id(sim);

    return line_id == SRV_CALLSET_LINE2 ?
           SRV_CPHS_MSISDN_TYPE_LINE2 : SRV_CPHS_MSISDN_TYPE_LINE1;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_idle_get_owner_number_string
 * DESCRIPTION
 *  This function gets the owner number string.
 * PARAMETERS
 *  sim                     : [IN]            SIM ID
 *  service_indication      : [OUT]           mmi_idle_service_indication_struct
 * RETURNS
 *  On available, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL mmi_idle_get_owner_number_string(
    mmi_sim_enum sim,
    mmi_idle_service_indication_struct *service_indication)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cphs_msisdn_type_enum msisdn_type;
    const WCHAR *string;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_phnset_show_owner_number_is_on(sim) &&
        srv_sim_ctrl_is_available(sim))
    {
        /*
         * Priority: owner name > owner number.
         */
        msisdn_type = mmi_idle_get_msisdn_type(sim);

        string = srv_cphs_get_msisdn_name(msisdn_type, sim);
        if (!string || !mmi_wcslen(string))
        {
            string = srv_cphs_get_msisdn_number(msisdn_type, sim);
        }

        if (string && mmi_wcslen(string))
        {
            mmi_wcsncpy(service_indication->line2, string, SRV_NW_NAME_MAX_STR_LEN);
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}
#endif /* defined(__MMI_IDLE_SCREEN_OWNER_NUMBER__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_get_extra_indication_for_line2_string
 * DESCRIPTION
 *  This function gets the extra infomation string instead of spn for specific UE.
 * PARAMETERS
 *  sim                     : [IN]            SIM ID
 *  service_indication      : [OUT]           mmi_idle_service_indication_struct
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_get_extra_indication_for_line2_string(
    mmi_sim_enum sim,
    mmi_idle_service_indication_struct *service_indication)

{
 /*----------------------------------------------------------------*/
 /* Local Variables                                                */
 /*----------------------------------------------------------------*/

 /*----------------------------------------------------------------*/
 /* Code Body                                                      */
 /*----------------------------------------------------------------*/

    /*
      * Override 2nd line if there is other information required.
      */
#if defined(__OP12__) && defined(__NBR_CELL_INFO__)
     if (mmi_netset_get_cell_info_status() &&
         mmi_idle_get_cell_info_string(sim,service_indication))
     {
         return;
     }
#endif /* defined(__OP12__) */

#if defined(__HOMEZONE_SUPPORT__ )
     if (mmi_idle_get_homezone_string(sim,service_indication))
     {
         return;
     }
#endif /* defined(__HOMEZONE_SUPPORT__ ) */

#if defined(__MMI_IDLE_SCREEN_OWNER_NUMBER__)
     if (mmi_idle_get_owner_number_string(sim,service_indication))
     {
         return;
     }
#endif /* defined(__MMI_IDLE_SCREEN_OWNER_NUMBER__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_get_service_indication_string
 * DESCRIPTION
 *  This function gets the service indication string of the specified SIM in the idle.
 *  include special info , like homezone, cell info, owner number
 * PARAMETERS
 *  sim                     : [IN]            SIM ID
 *  service_indication      : [OUT]           mmi_idle_service_indication_struct
 * RETURNS

 *  void
 *****************************************************************************/
void mmi_idle_get_service_indication_string(
    mmi_sim_enum sim,
    mmi_idle_service_indication_struct *service_indication)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_name_service_indication_struct tmp_indication;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_nw_name_get_service_indication_string(sim, &tmp_indication);

    mmi_wcsncpy(service_indication->line1, tmp_indication.line1, MMI_IDLE_NW_NAME_MAX_STR_LEN);
    mmi_wcsncpy(service_indication->line2, tmp_indication.line2, MMI_IDLE_NW_NAME_MAX_STR_LEN);

    /*
     * Override 2nd line if there is other information required.
     */
    mmi_idle_get_extra_indication_for_line2_string(sim, service_indication);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_update_service_indication_context
 * DESCRIPTION
 *  This function updates service indication of idle context
 * PARAMETERS
 *  obj             : [IN]              Object
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_idle_update_service_indication_context(mmi_idle_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_idle_service_indication_struct *service_indication;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        service_indication = mmi_idle_get_service_indication_context(obj, mmi_frm_index_to_sim(i));
        mmi_idle_get_service_indication_string(mmi_frm_index_to_sim(i), service_indication);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_idle_get_service_indication_context
 * DESCRIPTION
 *  This function gets the context of the service string.
 * PARAMETERS
 *  obj                 : [IN]              Object
 *  sim                 : [IN]              SIM ID
 * RETURNS
 *  void
 *****************************************************************************/
mmi_idle_service_indication_struct *mmi_idle_get_service_indication_context(
    mmi_idle_obj_struct *obj,
    mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &(obj->service_indication[mmi_frm_sim_to_index(sim)]);
}

