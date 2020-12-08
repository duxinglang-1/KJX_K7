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
 *  vadp_v2p_hs.c
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file provides the adaptation functions from the Venus MMI to the Pluto
 *  MMI.
 *
 *      Venus APP ---> v2p adaptor ---> Pluto APP
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN__

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "string.h"
#include "MMIDataType.h"
#include "MiscFunctions.h"
#include "browser_api.h"
#include "FileMgrGProt.h"
#include "CalendarProt.h"
#include "ToDoListProt.h"
#include "PhoneSetup.h"
#include "MediaPlayerGProt.h"
#include "AllAppGprot.h"
#include "AlarmProt.h"
#include "AlarmGprot.h"
#include "Calculator.h"
#include "WPSSProtos.h"
#include "SettingGprots.h"
#include "AMGprot.h"
#include "DialerGprot.h"
#include "CallLogGprot.h"
#include "gui_effect_oem.h"
#include "custom_mmi_default_value.h"
#include "gui_typedef.h"
#include "gui_data_types.h"
#include "wgui_categories_util.h"
#include "CustThemesRes.h"
#include "GlobalResDef.h"
#include "UMGProt.h"
#include "CalendarGprot.h"
#include "ProfilesAppGprot.h"

#ifdef __MMI_GADGET_SUPPORT__
#include "WgtMgrAppGprot.h"
#endif

#ifdef __cplusplus
}
#endif

/* Venus MMI headers: */
#include "vfx_datatype.h"
#include "vfx_base.h"
#include "vadp_v2p_hs.h"


/**********************************************************************
 * External Variables
 **********************************************************************/

/**********************************************************************
 * Structure Definitions:
 **********************************************************************/

/**********************************************************************
 * Global variables:
 **********************************************************************/


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_get_alarm_info
 * DESCRIPTION
 *  This function gets the alarm information.
 * PARAMETERS
 *  index           : [IN] index of the alarm
 *  hour            : [OUT] hours
 *  mins            : [OUT] minutes
 *  state           : [OUT] status of the alarm
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_get_alarm_info(VfxU8 index, VfxU8 *state, VfxU8 *time_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME t;
    U8 hour, min;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_alm_get_info(index, &hour, &min, state);

    memset(&t, 0, sizeof(MYTIME));
    t.nHour = hour;
    t.nMin = min;
    time_string(&t, (UI_string_type)time_str, DT_IDLE_SCREEN);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_set_alarm
 * DESCRIPTION
 *  This function gets the alarm information.
 * PARAMETERS
 *  index           : [IN] index of the alarm
 *  state           : [IN] status of the alarm
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_set_alarm(VfxU8 index, VfxU8 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_alm_set_alarm_state(index, state);
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


#ifdef BROWSER_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_launch_broswer
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_launch_broswer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_sse_setup_scenario(GUI_SSE_SCENARIO_FROM_VENUS_HS_SHORTCUT);

    goto_mobile_suite_screen();
}
#endif /* BROWSER_SUPPORT */


#ifdef __MMI_FILE_MANAGER__
/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_launch_file_manager
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_launch_file_manager(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_sse_setup_scenario(GUI_SSE_SCENARIO_FROM_VENUS_HS_SHORTCUT);

    mmi_fmgr_launch();
}
#endif


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_launch_phone_settting
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_launch_phone_settting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_sse_setup_scenario(GUI_SSE_SCENARIO_FROM_VENUS_HS_SHORTCUT);

    EntryPhnsetScr();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_launch_profiles
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_launch_profiles(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_sse_setup_scenario(GUI_SSE_SCENARIO_FROM_VENUS_HS_SHORTCUT);
    
    mmi_profiles_entry_main_screen();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_launch_phonebook
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_launch_phonebook(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_sse_setup_scenario(GUI_SSE_SCENARIO_FROM_VENUS_HS_SHORTCUT);
    
    mmi_phb_entry_main_menu();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_launch_call_history
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_launch_call_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_sse_setup_scenario(GUI_SSE_SCENARIO_FROM_VENUS_HS_SHORTCUT);

    mmi_clog_sendkey_launch();
}


#if defined(__MOD_SMSAL__)
/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_launch_message_center
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_launch_message_center(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_sse_setup_scenario(GUI_SSE_SCENARIO_FROM_VENUS_HS_SHORTCUT);

    mmi_um_entry_main_message_menu();
}
#endif /* defined(__MOD_SMSAL__) */


#ifdef __MMI_CALENDAR__
/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_launch_calendar
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_launch_calendar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_sse_setup_scenario(GUI_SSE_SCENARIO_FROM_VENUS_HS_SHORTCUT);

    mmi_clndr_launch(GRP_ID_ROOT, MMI_CAL_LAUNCH_TYPE_AUTO, NULL);
}
#endif /* __MMI_CALENDAR__ */


#ifdef __MMI_TODOLIST__
/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_launch_todo
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_launch_todo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_sse_setup_scenario(GUI_SSE_SCENARIO_FROM_VENUS_HS_SHORTCUT);
    
    TDLShowAllList();
}
#endif /* __MMI_TODOLIST__ */


#ifdef __MMI_VUI_3D_CUBE_APP__
/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_launch_alarm
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_launch_3d_cube(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* SSE cannot be applied from Venus screen to Venus screen. Do not setup
       SSE here. */
    EntryCubeVappByDir(MMI_TRUE, MMI_FALSE, MMI_CUBE_VAPP_DIR_NONE);
}
#endif /* __MMI_VUI_3D_CUBE_APP__ */


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_launch_alarm
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_launch_alarm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_sse_setup_scenario(GUI_SSE_SCENARIO_FROM_VENUS_HS_SHORTCUT);
    
    EntryAlmMenu();
}


#if defined(__MMI_CALCULATOR__) || defined(__MMI_MRE_CALCULATOR__)
/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_launch_calculator
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_launch_calculator(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_sse_setup_scenario(GUI_SSE_SCENARIO_FROM_VENUS_HS_SHORTCUT);
    
    CalcPreEntryApp();
}
#endif /* __MMI_CALCULATOR__ */


#ifdef __MMI_AUDIO_PLAYER__
/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_launch_audio_player
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_launch_audio_player(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_sse_setup_scenario(GUI_SSE_SCENARIO_FROM_VENUS_HS_SHORTCUT);
    
    mmi_audply_entry_main();
}
#endif /* __MMI_AUDIO_PLAYER__ */


#ifdef __MMI_VIDEO_PLAYER__
/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_launch_video_player
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_launch_video_player(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_sse_setup_scenario(GUI_SSE_SCENARIO_FROM_VENUS_HS_SHORTCUT);
    
    mmi_vdoply_entry_app();
}
#endif /* __MMI_VIDEO_PLAYER__ */


#ifdef __MMI_MEDIA_PLAYER__
/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_launch_video_player
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_launch_media_player(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_sse_setup_scenario(GUI_SSE_SCENARIO_FROM_VENUS_HS_SHORTCUT);
    
    mmi_medply_app_pre_entry();
}
#endif /* __MMI_MEDIA_PLAYER__ */


#ifdef __MMI_GADGET_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_launch_widget_manager
 * DESCRIPTION
 *  This function launches the widget manager.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_launch_widget_manager(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __PLUTO_MMI_PACKAGE__
    gui_sse_setup_scenario(GUI_SSE_SCENARIO_FROM_VENUS_HS_SHORTCUT);
    
    mmi_wgtmgr_entry_main();
#endif
}
#endif /* __MMI_GADGET_SUPPORT__ */


#ifdef __MRE_AM__
/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_am_get_shortcut_number
 * DESCRIPTION
 *  This function returns the total number of the MRE shortcut.
 * PARAMETERS
 *  void
 * RETURNS
 *  Total number of the MRE shortcut.
 *****************************************************************************/
VfxS32 vadp_v2p_hs_am_get_shortcut_number(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_am_get_shortcut_number();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_am_get_all_shortcut_id
 * DESCRIPTION
 *  This function gets all the MRE shortcut id.
 * PARAMETERS
 *  id          : [OUT]     The Obtained MRE shortcut id
 *  size        : [INT]     The size of the 'id' array
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_am_get_all_shortcut_id(VfxS32 *id, VfxU32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_am_get_all_shortcut_id((U32 *)id, size);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_am_get_shortcut_icon
 * DESCRIPTION
 *  This function gets the filename of the icon for the specified MRE shortcut.
 * PARAMETERS
 *  id              : [IN]      MRE shortcut id
 *  filename        : [OUT]     Filename of the icon in UCS2 encoding
 *  size            : [IN]      The size of the buffer
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_am_get_shortcut_icon(
        VfxS32 id, 
        VfxWChar *filename, 
        VfxU32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_am_get_shortcut_icon(id, (U16 *)filename, size);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_am_launch_shortcut
 * DESCRIPTION
 *  This function launches the specified MRE shortcut.
 * PARAMETERS
 *  id              : [IN]      MRE shortcut id
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_am_launch_shortcut(VfxS32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_am_launch_shortcut((U32)id);
}
#endif /* __MRE_AM__ */
#endif /* __MMI_VUI_HOMESCREEN__ */

