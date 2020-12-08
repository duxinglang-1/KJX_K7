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
 * SSCStringProcess.C
 *
 * Project:
 * --------
 *   PlutoMMI
 *
 * Description:
 * ------------
 *   To handle the ssc string.
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "MMIDataType.h"
#include "SSCResDef.h"
#include "idleGprot.h"
#include "alertScreen.h"
#include "mmi_rp_srv_phb_def.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_text_viewer.h"
#include "GlobalResDef.h"
#include "mmi_frm_history_gprot.h"
#include "GlobalConstants.h"
#include "wgui_categories_util.h"
#include "mmi_msg_struct.h"
#include "stack_msgs.h"
#include "Unicodexdcl.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "kal_general_types.h"
#include "string.h"
#include "DebugInitDef_Int.h"
#include "MMI_trc_Int.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
#include "mmi_rp_app_engineermode1_def.h"
#include "wgui_categories_list.h"
#include "DialerCuiGprot.h"
#include "Gui_effect_oem.h"


#ifdef __COSMOS_MMI_PACKAGE__
extern void vcp_dialer_popup(WCHAR *str);
extern void vcp_dialer_imei_pupup(WCHAR *str, void *scr);
extern void *mmi_ssc_main_screen_g;
#endif

#define MAX_IMEISV_DISPLAY_LEN 33       /* including null-terminator */
#define MAX_IMEI_LEN 16
#define MAX_IMEISV_LEN  2

#ifdef __MMI_IMEISV_SUPPORT__
static CHAR gstrIMEI[MAX_IMEISV_DISPLAY_LEN * MMI_MAX_SIM_NUM * ENCODING_LENGTH];
#else
static CHAR gstrIMEI[((MAX_IMEI_LEN + 1) * MMI_MAX_SIM_NUM + 1)* ENCODING_LENGTH];
#endif


#define IMEI_SSC_PROCESSING

/*****************************************************************************
 * FUNCTION
 *  mmi_ssc_show_imei
 * DESCRIPTION
 *  Display IMEI Number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ssc_show_imei(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __COSMOS_MMI_PACKAGE__
    vcp_dialer_imei_pupup((WCHAR *)gstrIMEI, mmi_ssc_main_screen_g);
#else
    mmi_frm_scrn_enter(mmi_frm_group_get_active_id(), SCR_ENTER_SSC, NULL, mmi_ssc_show_imei, MMI_FRM_FULL_SCRN);

#ifdef __MMI_IMEISV_SUPPORT__
    ShowCategory7Screen(
        SSC_SCR_IMEI_CAPTION_ID,
        0,
        0,
        0,
        STR_GLOBAL_BACK,
        0,
        (U8*) gstrIMEI,
        NULL);
#else /* __MMI_IMEISV_SUPPORT__ */ 
    ShowCategory152Screen(
        SSC_SCR_IMEI_CAPTION_ID, 
        0, 
        0, 
        0, 
        STR_GLOBAL_BACK, 
        0, 
        (U8*) gstrIMEI, 
        NULL);
#endif /* __MMI_IMEISV_SUPPORT__ */ 

    /* Delete previous one because it might be shown from idle dialpad and then
       from call management dial pad. */

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#endif /* __COSMOS_MMI_PACKAGE__ */
}


MMI_BOOL mmi_ssc_set_imei(void *buf)
{
    U8 tempbuf[(MAX_IMEI_LEN + 1) * ENCODING_LENGTH];
    mmi_nw_get_imei_rsp_struct *imeiresponse = (mmi_nw_get_imei_rsp_struct*) buf;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_clear_protocol_event_handler(MSG_ID_MMI_NW_GET_IMEI_RSP, NULL);
     
    if (imeiresponse->result == 1)
    {
    #ifdef __ASCII
        memcpy(gstrIMEI, (CHAR*) imeiresponse->imei, MAX_IMEI_LEN);
    #endif 
            
    #ifdef __UCS2_ENCODING
    #ifdef __MMI_IMEISV_SUPPORT__
        mmi_asc_to_ucs2((CHAR*) tempbuf, "IMEI:");
        mmi_ucs2cat(gstrIMEI, (const CHAR*)tempbuf);
        mmi_asc_to_ucs2((CHAR*) tempbuf, (CHAR*) imeiresponse->imei);
        mmi_ucs2cat(gstrIMEI, (const CHAR*)tempbuf);
        mmi_asc_to_ucs2((CHAR*) tempbuf, "\nSVN:");
        mmi_ucs2cat(gstrIMEI, (const CHAR*)tempbuf);
        mmi_asc_to_ucs2((CHAR*) tempbuf, (CHAR*) imeiresponse->svn);
        mmi_ucs2cat(gstrIMEI, (const CHAR*)tempbuf);
        mmi_asc_to_ucs2((CHAR*) tempbuf, "\n");
        mmi_ucs2cat(gstrIMEI, (const CHAR*)tempbuf);
    #else /* __MMI_IMEISV_SUPPORT__ */ 
        mmi_asc_to_ucs2((CHAR*) tempbuf, "IMEI:");
        mmi_ucs2cat(gstrIMEI, (const CHAR*)tempbuf);
        mmi_asc_to_ucs2((CHAR*) tempbuf, (CHAR*) imeiresponse->imei);
        mmi_ucs2cat(gstrIMEI, (const CHAR*)tempbuf);
        mmi_asc_to_ucs2((CHAR*) tempbuf, "\n");
        mmi_ucs2cat(gstrIMEI, (const CHAR*)tempbuf);
    #endif /* __MMI_IMEISV_SUPPORT__ */
    #endif /* __UCS2_ENCODING */

        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


void mmi_ssc_send_imei_get_ilm(module_type dest_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslMsgId = MSG_ID_MMI_NW_GET_IMEI_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = dest_mod;
    OslMsgSendExtQueue(&Message);
}

#if (MMI_MAX_SIM_NUM >= 2)
#if (MMI_MAX_SIM_NUM >= 3)
#if (MMI_MAX_SIM_NUM >= 4)
void mmi_ssc_get_sim4_imei_rsp(void *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ssc_set_imei(buf);
    mmi_ssc_show_imei();
}

void mmi_ssc_get_sim4_imei_req()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ssc_send_imei_get_ilm(MOD_L4C_4);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_NW_GET_IMEI_RSP,
        mmi_ssc_get_sim4_imei_rsp,
        MMI_FALSE);

}
#endif
void mmi_ssc_get_sim3_imei_rsp(void *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ssc_set_imei(buf);
#if (MMI_MAX_SIM_NUM >= 4)
    mmi_ssc_get_sim4_imei_req();
#else
    mmi_ssc_show_imei();
#endif
}

void mmi_ssc_get_sim3_imei_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ssc_send_imei_get_ilm(MOD_L4C_3);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_NW_GET_IMEI_RSP,
        mmi_ssc_get_sim3_imei_rsp,
        MMI_FALSE);
}
#endif
U8 mmi_ssc_get_sim2_imei_rsp(void *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ssc_set_imei(buf);
#if (MMI_MAX_SIM_NUM >= 3)
    mmi_ssc_get_sim3_imei_req();
#else
    mmi_ssc_show_imei();
#endif
    return 1;
}

void mmi_ssc_get_sim2_imei_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ssc_send_imei_get_ilm(MOD_L4C_2);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_NW_GET_IMEI_RSP,
        mmi_ssc_get_sim2_imei_rsp,
        MMI_FALSE);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_ssc_get_imei_rsp
 * DESCRIPTION
 *  Response handler fn of request to get IMEI number.
 * PARAMETERS
 *  buf     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_ssc_get_imei_rsp(void *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ssc_set_imei(buf);
#if (MMI_MAX_SIM_NUM >= 2)
    mmi_ssc_get_sim2_imei_req();
#else
    mmi_ssc_show_imei();
#endif
    return 1;
}

void scrn_dummy_entry()
{
	if (mmi_frm_scrn_enter(SCR_ID_DUMMY, SCR_ID_DUMMY, (FuncPtr)NULL, (FuncPtr)scrn_dummy_entry, MMI_FRM_FULL_SCRN))
    {    
		mmi_frm_scrn_clear_attribute(SCR_ID_DUMMY, SCR_ID_DUMMY, MMI_SCRN_ATTRIB_ADD_HISTORY);
        ShowCategoryDummyScreen();
		gui_sse_set_is_dummy_screen(MMI_FALSE);
    }
}
/*****************************************************************************
 * FUNCTION
 *  SSCHandleIMEI
 * DESCRIPTION
 *  Send req to get the IMEI number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleIMEI(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __COSMOS_MMI_PACKAGE__
	mmi_frm_group_create_ex(GRP_ID_ROOT, SCR_ID_DUMMY, NULL, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	scrn_dummy_entry();
#endif
    ClearInputEventHandler(MMI_DEVICE_ALL); /* send message and wait response in the same screen and no input can be accepted */
    memset(gstrIMEI, 0x00, sizeof(gstrIMEI));

    mmi_ssc_send_imei_get_ilm(MOD_L4C);
    
    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_NW_GET_IMEI_RSP,
        mmi_ssc_get_imei_rsp,
        MMI_FALSE);
}


#define SSC_COMMON_FUNCTION
/*****************************************************************************
 * FUNCTION
 *  Serial_num
 * DESCRIPTION
 *  Stub fn to return Serial Number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
CHAR* Serial_num()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return "123456789012340";
}


void mmi_ssc_popup(WCHAR *str, mmi_event_notify_enum type)
{
#ifdef __COSMOS_MMI_PACKAGE__
    vcp_dialer_popup(str);
#else
    mmi_popup_display_simple(
            str,
            type,
            GRP_ID_ROOT,
            NULL);
#endif
}


void mmi_ssc_close_dialer()
{
    cui_dialer_close_if_present();
}


#define SOFT_VERSION_SSC_PROCESSING
#ifdef __MMI_FACTORY_MODE__ 
extern void EntryFMVersionSummaryMenu(void);
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_SSC_handle_software_version_summary
 * DESCRIPTION
 *  Display sofeware version.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_SSC_handle_software_version_summary(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#ifdef __MMI_FACTORY_MODE__ 
    EntryFMVersionSummaryMenu();
#else /* __MMI_FACTORY_MODE__ */ 
    mmi_idle_display();

    mmi_ssc_popup(
        get_string(SSC_SCR_FACTORY_MODE_STR_ID),
        MMI_EVENT_FAILURE);
#endif /* __MMI_FACTORY_MODE__ */ 
}


#define HW_VERSION_SSC_PROCESSING
#ifdef __MMI_HW_VERSION__
extern char *release_hw_ver(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_SSC_handle_hardware_version
 * DESCRIPTION
 *  Execute the sofeware version dispaly
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_SSC_handle_hardware_version(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    CHAR strHWVersionNo[(MAX_SW_VER_LEN + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(strHWVersionNo, 0, sizeof(strHWVersionNo));
#ifdef __ASCII
    strcpy(strHWVersionNo, (CHAR*) release_hw_ver());
#endif 

#ifdef __UCS2_ENCODING
    mmi_asc_n_to_ucs2(strHWVersionNo, (CHAR*) release_hw_ver(), MAX_SW_VER_LEN);
#endif 

    EntryNewScreen(SCR_ENTER_HW_VERSION, NULL, mmi_SSC_handle_hardware_version, NULL);

    ShowCategory7Screen(SSC_SCR_HW_VERSION_CAPTION_ID, 0, STR_GLOBAL_OK, 0, 0, 0, (PU8) strHWVersionNo, NULL);

    SetLeftSoftkeyFunction(mmi_idle_display, KEY_EVENT_UP);
}
#endif /* __MMI_HW_VERSION__ */


#define FACTORY_MODE_SSC_PROCESSING
#define MAX_SW_VER_LEN   30

#ifdef __MMI_ENGINEER_MODE__ 
extern void mmi_em_pre_entry_engineermode_menu(void);
#endif

#ifdef __MMI_FACTORY_MODE__
extern void EntryFMMenu(void);
extern void EntryFMMenuAutoTest(void);

#ifdef __MMI_FM_LCD_CONTRAST__
extern void EntryFMLCDContrastMenuHdlr(void);
#endif

#endif /* __MMI_FACTORY_MODE__ */ 

#ifdef __MMI_FM_LCD_CONTRAST__
/*****************************************************************************
 * FUNCTION
 *  mmi_SSC_handle_LCD_contrast_setting
 * DESCRIPTION
 *  Display LCD Contrast Setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_SSC_handle_LCD_contrast_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_FACTORY_MODE__ 
    EntryFMLCDContrastMenuHdlr();
#else /* __MMI_FACTORY_MODE__ */ 
    mmi_idle_display();

    mmi_ssc_popup(
        get_string(SSC_SCR_FACTORY_MODE_STR_ID),
        MMI_EVENT_FAILURE);
#endif /* __MMI_FACTORY_MODE__ */ 
}


#endif /* __MMI_FM_LCD_CONTRAST__ */

#define DISABLE_SSC_PROCESSING
extern U8 ssc_disable_flag;
/*****************************************************************************
 * FUNCTION
 *  SSCHandleDisable
 * DESCRIPTION
 *  SSC disable for shipment
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleDisable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!ssc_disable_flag)
    {
        ssc_disable_flag = MMI_TRUE;
        WriteValue(NVRAM_SSC_DISABLE_FLAG, &ssc_disable_flag, DS_BYTE, &error);

        mmi_idle_display();
        mmi_ssc_popup(
            get_string(STR_GLOBAL_DONE),
            MMI_EVENT_SUCCESS);
    }
}


#define VENUS_SSC_PROCESSING
#ifdef __VENUS_UI_ENGINE__
extern void vtst_rt_main_entry(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_SSC_handle_venus_UI_test
 * DESCRIPTION
 *  SSC handler for Venus UI Test
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_SSC_handle_venus_UI_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* enter Venus UI testbed screen */
    vtst_rt_main_entry();
}
#endif

#ifdef __MMI_EM_PROFILING_VENUS_DEBUG_PANEL__
static U8 debug_panel_enabled = 0;
/*****************************************************************************
 * FUNCTION
 *  mmi_ssc_venus_debug_panel_hilite_hdlr(
 * DESCRIPTION
 *  SSC handler for Venus UI Debug Panel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ssc_venus_debug_panel_hilite_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    debug_panel_enabled = (index == 0) ? 1 : 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssc_venus_debug_panel_done
 * DESCRIPTION
 *  SSC handler for Venus UI Debug Panel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ssc_venus_debug_panel_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValue(NVRAM_VENUS_DEBUG_PANEL_ENABLE, &debug_panel_enabled, DS_BYTE, &error);
    if (error == NVRAM_WRITE_SUCCESS)
    {
        mmi_popup_display_simple(get_string(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);
    }
    else
    {
        mmi_popup_display_simple(get_string(STR_GLOBAL_FAILED), MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
    }
    mmi_frm_scrn_close(GRP_ID_ROOT, SCR_ENTER_SSC);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ssc_handle_venus_debug_panel
 * DESCRIPTION
 *  SSC handler for Venus UI Debug Panel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ssc_venus_debug_panel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 items[2];
    U8* gui_buffer;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(GRP_ID_ROOT, SCR_ENTER_SSC, NULL, mmi_ssc_venus_debug_panel, MMI_FRM_FULL_SCRN))
    {
        return;
    }

    ReadValue(NVRAM_VENUS_DEBUG_PANEL_ENABLE, &debug_panel_enabled, DS_BYTE, &error);
    items[0] = (PU8)GetString(STR_GLOBAL_ON);
    items[1] = (PU8)GetString(STR_GLOBAL_OFF);
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    RegisterHighlightHandler(mmi_ssc_venus_debug_panel_hilite_hdlr);
    ShowCategory36Screen(
        STR_ID_EM_PROFILING_VENUS_DEBUG_PANEL,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        2,
        (PU8*)items,
        debug_panel_enabled ? 0 : 1,
        gui_buffer);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetLeftSoftkeyFunction(mmi_ssc_venus_debug_panel_done, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif /* __MMI_EM_PROFILING_VENUS_DEBUG_PANEL__ */

