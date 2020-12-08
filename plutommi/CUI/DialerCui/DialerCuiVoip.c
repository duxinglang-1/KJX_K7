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
 *  DialerCuiVoip.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the VoIP dialer.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
 * TODO: VoIP MMI depends on SCR_ID_VOIP_CALL_EDITOR. Fix it.
 */

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VOIP__)

#include "MMI_include.h"
#include "DialerCuiProt.h"
#include "VoIPResDef.h"
#include "NetworkSetupDefs.h"


/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_voip_enter
 * DESCRIPTION
 *  This function is the enter function of the VoIP dialer.
 * PARAMETERS
 *  param               : [IN]              Screen parameter
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_voip_enter(mmi_scrn_essential_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_voip_struct *p;
    U8 *history;
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_frm_scrn_enter(
            param->group_id,
            param->scrn_id,
            NULL,
            (FuncPtr)cui_dialer_voip_enter,
            MMI_FRM_FULL_SCRN);

    if (!ret)
    {
        return;
    }

    p = (cui_dialer_voip_struct *)param->user_data;

    history = mmi_frm_scrn_get_gui_buf(param->group_id, param->scrn_id);

    EnableCenterSoftkey(0, IMG_GLOBAL_CALL_CSK);

    mmi_imm_set_characters(MMI_TRUE, mmi_imm_get_allowed_voip_number_characters());

    ShowCategory404Screen(
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        IMG_ID_VOIP_CALL_EDITOR,
        (PU8)p->dial_string,
        CUI_DIALER_MAX_DIAL_STR_LEN,
        history);

    /* RSK handler. */
    SetCategory5RightSoftkeyFunction(cui_dialer_do_close, KEY_EVENT_UP);

    // TODO: figure out what these compile option means.
#if defined(CUI_DIALER_VOIP_SUPPORT_PREFER_INPUT_METHOD)
    if (mmi_imm_get_prefer_input_mode() == IMM_INPUT_MODE_123_SYMBOLS)
    {
        /* Input the first digit, if present. */
        cui_dialer_input_first_char((cui_dialer_obj_struct *)p);
    }
#endif /* defined(CUI_DIALER_VOIP_SUPPORT_PREFER_INPUT_METHOD) */

    /* Setup the key handler. */
    cui_dialer_set_handler((cui_dialer_obj_struct *)p);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_voip_on_run
 * DESCRIPTION
 *  This function runs the dialer.
 * PARAMETERS
 *  obj             : [IN]              Object
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_voip_on_run(cui_dialer_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_enter(obj->this_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_first_enter(
        obj->this_gid,
        SCR_ID_CUI_DIALER_MAIN,
        (FuncPtr)cui_dialer_voip_enter,
        obj);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_voip_on_set_key
 * DESCRIPTION
 *  This function sets the key of the VoIP dialer.
 * PARAMETERS
 *  obj                 : [IN]              Object
 *  key_code            : [IN]              Key code
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_dialer_voip_on_set_key(cui_dialer_obj_struct *obj, U16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    // TODO: check why the original VoIP dialer does not allow * and #.
    if (key_code != KEY_STAR && key_code != KEY_POUND)
    {
        cui_dialer_obj_on_set_key(obj, key_code);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_voip_on_want_to_run
 * DESCRIPTION
 *  This function checks if the dialer wants to run.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL cui_dialer_voip_on_want_to_run(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_WLAN_FEATURES__)
    if (mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY ||
        mmi_netset_get_active_preferred_mode() == P_WLAN_PREFERRED)
    {
        return MMI_TRUE;
    }
    else
#endif /* defined(__MMI_WLAN_FEATURES__) */
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_voip_on_init
 * DESCRIPTION
 *  This function initializes the VoIP dialer object.
 * PARAMETERS
 *  obj             : [IN]              Object
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_voip_on_init(cui_dialer_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_voip_struct *p;
    cui_dialer_capability_struct *capability;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Initialized by parent.
     */
    cui_dialer_obj_on_init(obj);

    /*
     * Override parent's behavior.
     */
    p = (cui_dialer_voip_struct *)obj;

    p->type = CUI_DIALER_TYPE_VOIP;
    p->on_run = cui_dialer_voip_on_run;
    p->on_set_key = cui_dialer_voip_on_set_key;

    /*
     * Change the capabilities.
     */
    capability = &p->capability;

    capability->enable_abbrev_dial = MMI_FALSE;
    capability->enable_ip_dial = MMI_FALSE;
    capability->enable_toggle_profile = MMI_FALSE;
    capability->enable_speed_dial = MMI_FALSE;
    capability->enable_baidu_search = MMI_FALSE;
}

#endif /* defined(__MMI_VOIP__) */

