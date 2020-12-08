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
 * SSCStringHandle.C
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "MMIDataType.h"
#include "GSM7BitDefaultAlphabet.h"
#include "IdleAppDef.h"
#include "DevAppGprot.h"
#include "SecSetGprot.h" /* mmi_secset_ssc_process */
#include "kal_general_types.h"
#include "gui_data_types.h"
#include "mmi_frm_events_gprot.h"
#include "Unicodexdcl.h"
#include "mmi_frm_history_gprot.h"
#include "SSCGprot.h"
#include "SSCprot.h"
#include "globalResDef.h"
#include "SecSetGprot.h" /* mmi_secset_ssc_process */
#include "custom_phb_config.h"
#include "dialercuiGprot.h"

#ifdef __COSMOS_MMI_PACKAGE__
extern MMI_BOOL mmi_dialer_ssc_process_chv(WCHAR *str, void *screen);
U16 mmi_dialer_ssc_string[(MMI_PHB_NUMBER_LENGTH + 1 + 1) * ENCODING_LENGTH];
extern void*mmi_ssc_main_screen_g;
#endif

#if defined (__FLAVOR_VENDOR_SDK__) || defined(__MAUI_SDK_TEST__)
extern void mmi_entry_avk_app_scr(void);
#endif

/**********************************************/
/*   Local Functions                          */
/**********************************************/
extern CHAR ssc_dialpad_buffer[];

/*
 * For SSC disable
 * MMI_FALSE (0): ssc string unchanged
 * MMI_TRUE  (1): before executing ssc, check the 'ssc_disable_ctrl' flag first
 * 0xFF: read NVRAM first 
 */
#ifdef __MMI_SML_MENU__
extern SIMSTRINGTBL mmi_ssc_sim_table[7];
#else
extern SIMSTRINGTBL mmi_ssc_sim_table[4];
#endif

#ifdef __MMI_A2DP_SUPPORT__
U8 g_ssc_bt_a2dp_mode = 0;  /* 0: INT mode, 1: ACP mode, 2: ACP mode for PTS only */
#endif /*__MMI_A2DP_SUPPORT__*/


U8 mmi_ssc_process_chv(void)
{
#ifdef __COSMOS_MMI_PACKAGE__
    return mmi_dialer_ssc_process_chv(mmi_dialer_ssc_string, mmi_ssc_main_screen_g);
#else
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_secset_ssc_process((CHAR *)cui_dialer_get_dial_string_if_any());

    if (ret)
    {
        mmi_ssc_close_dialer();
    }

    return (U8)ret;
#endif
}


#ifdef __MMI_A2DP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  SSCHandle_BT_A2DP_Toggle_PTS_Mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandle_BT_A2DP_Toggle_PTS_Mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type text[2] = {L"A2DP Normal mode", L"A2DP PTS mode"};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ssc_bt_a2dp_mode)
    {
        g_ssc_bt_a2dp_mode = 0;
    }
    else
    {
        g_ssc_bt_a2dp_mode = 1;
    }

    mmi_ssc_popup(
        (WCHAR *)text[g_ssc_bt_a2dp_mode],
        MMI_EVENT_SUCCESS);
}
#endif /* __MMI_A2DP_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  SSCHandleVendorApp
 * DESCRIPTION
 *  SSC handler for Vendor App
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleVendorApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* enter testbed screen */
    mmi_entry_dev_app_scr();
}

#if defined (__FLAVOR_VENDOR_SDK__) || defined(__MAUI_SDK_TEST__)
extern void mmi_entry_sdk_test_scr();
/*****************************************************************************
 * FUNCTION
 *  SSCHandleAvkApp
 * DESCRIPTION
 *  SSC handler for Avk App
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandleAvkApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* enter testbed screen */
#ifdef __MAUI_SDK_TEST__
    mmi_entry_sdk_test_scr();
#endif
}

#endif

#ifdef __BTMTK__

#ifdef __BT_SIM_PROFILE__
extern void SimSrvSetGracefulDiscType(void);
extern void SimSrvSetImmediateDiscType(void);
#endif

#ifndef __COSMOS_MMI_PACKAGE__
#ifdef __MMI_SIMAP_SUPPORT__
extern void mmi_bth_simap_send_status_ind_with_unavailable_req(void);
#endif
#endif



/*****************************************************************************
 * FUNCTION
 *  SSCHandle_BT_PTS_SIMAP_Graceful_Disc_Type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandle_BT_PTS_SIMAP_Graceful_Disc_Type(void)
{
    UI_string_type text[2] = {L"BT_PTS_SIMAP_Graceful_Disc_Type", L"BT_PTS_SIMAP_Graceful_Disc_Type" };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ssc_popup(
        (WCHAR *)text[0],
        MMI_EVENT_SUCCESS);

#ifdef __BT_SIM_PROFILE__
    SimSrvSetGracefulDiscType();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  SSCHandle_BT_PTS_SIMAP_Immediate_Disc_Type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandle_BT_PTS_SIMAP_Immediate_Disc_Type(void)
{
    UI_string_type text[2] = {L"BT_PTS_SIMAP_Immediate_Disc_Type", L"BT_PTS_SIMAP_Immediate_Disc_Type" };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ssc_popup(
        (WCHAR *)text[0],
        MMI_EVENT_SUCCESS);

#ifdef __BT_SIM_PROFILE__
    SimSrvSetImmediateDiscType();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  SSCHandle_BT_PTS_SIMAP_PRS
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SSCHandle_BT_PTS_SIMAP_PRS(void)
{
    UI_string_type text[2] = {L"BT_PTS_SIMAP_PRS", L"BT_PTS_SIMAP_PRS" };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ssc_popup(
        (WCHAR *)text[0],
        MMI_EVENT_SUCCESS);

#ifndef __COSMOS_MMI_PACKAGE__
#ifdef __MMI_SIMAP_SUPPORT__
    /* Send a message to BT Stack instead of calling function call directly */
    mmi_bth_simap_send_status_ind_with_unavailable_req();
#endif
#endif
}
#endif /* __BTMTK__ */ 


#ifdef __COSMOS_MMI_PACKAGE__

mmi_id mmi_dialer_launch_by_string_ex(
    cui_dialer_type_enum type,
    const WCHAR *dial_string)
{
    return GRP_ID_INVALID;
}


void cui_dialer_close_if_present(void)
{
    return;
}


mmi_ret mmi_phb_dialer_search_sim_profile(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}


mmi_ret mmi_phb_ds_del_contact_at_proc(mmi_event_struct *param)
{
    return MMI_RET_OK;
}


mmi_ret mmi_phb_ds_startup_ready_proc(mmi_event_struct *param)
{
    return MMI_RET_OK;
}


mmi_ret mmi_phb_ds_upd_contact_at_proc(mmi_event_struct *param)
{
    return MMI_RET_OK;
}


void mmi_dialer_launch(void)
{
    return;
}


void mmi_dialer_launch_by_key(U16 key_code)
{
    return;
}


mmi_ret cui_dialer_main_evt_hdlr(mmi_event_struct *event)
{
    return MMI_RET_OK;
}


void cui_dialer_set_launch_style(mmi_id this_gid, cui_dialer_launch_type_enum value)
{
    return;
}


mmi_ret mmi_dialer_handle_dialer_change_type(mmi_event_struct *event)
{
    return MMI_RET_OK;
}

MMI_ID cui_dialer_handle_dialer_change_type(mmi_event_struct *event, MMI_ID parent_id)
{
	return 0;
}

/* For some further inpact */
#if defined(__MMI_DIALER_SEARCH__)
extern void cui_dialer_search_set_enable(MMI_BOOL enable)
{
    return;
}

extern MMI_BOOL cui_dialer_search_is_enable(void)
{
    return MMI_TRUE;
}

extern void cui_dialer_search_entry_setting(MMI_ID group_id)
{
    return;
}

#ifdef __MMI_ICON_BAR_SUPPORT__
extern void cui_dialer_toolbar_update(MMI_BOOL set)
{
    return;
}
#endif
/* DOM-NOT_FOR_SDK-END */

#endif /* defined(__MMI_DIALER_SEARCH__) */
#endif /* __COSMOS_MMI_PACKAGE__ */

