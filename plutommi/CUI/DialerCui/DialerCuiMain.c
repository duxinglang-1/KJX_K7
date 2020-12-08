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
 *  DialerCuiMain.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the main component of the dialer common UI.
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
 * removed!
 * removed!
 * removed!
 * removed!
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

#include "MMIDataType.h"
#include "BootupSrvGprot.h"
#include "DialerCuiObject.h"
#include "DialerCuiGprot.h"
#include "DialerCuiMain.h"
#include "mmi_common_app_trc.h"
#include "MMI_common_app_trc.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "mmi_frm_scenario_gprot.h"
#include "DialerCuiFactory.h"
#include "DialerCuiSearch.h"
#include "mmi_rp_cui_dialer_def.h"
#include "Unicodexdcl.h"
#ifdef __OP01_FWPBW__
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "Gpiosrvgprot.h"
#include "UcmSrvGprot.h"
#include "UcmGprot.h"
#endif

/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_emit_close_req
 * DESCRIPTION
 *  This function emits the close request.
 * PARAMETERS
 *  obj             : [IN]          Dialer object
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_emit_close_req(cui_dialer_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_close_req_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __OP01_FWPBW__
    if (!srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL))
    {
        if(mdi_audio_get_audio_mode() == AUD_MODE_LOUDSPK)
        {
            srv_speech_disable_hand_free();
        }
    } 
#endif

    CUI_DIALER_LOG((TRC_CUI_DIALER_EMIT_CLOSE_REQ, 200));


    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CUI_DIALER_CLOSE_REQ, obj->this_gid);
    evt.type = obj->type;

    mmi_frm_group_post_to_parent(obj->this_gid, (mmi_group_event_struct *)&evt);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_emit_closed_ind
 * DESCRIPTION
 *  This function emits the closed indication.
 * PARAMETERS
 *  obj             : [IN]          Dialer object
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_emit_closed_ind(cui_dialer_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_closed_ind_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CUI_DIALER_LOG((TRC_CUI_DIALER_EMIT_CLOSED_IND, 200));


    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CUI_DIALER_CLOSED_IND, obj->this_gid);
    evt.type = obj->type;

    mmi_frm_group_send_to_parent(obj->this_gid, (mmi_group_event_struct *)&evt);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_emit_change_type
 * DESCRIPTION
 *  This function posts the change type request.
 * PARAMETERS
 *  obj                 : [IN]          Dialer object
 *  new_type            : [IN]          New type of the dialer
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_emit_change_type(
    cui_dialer_obj_struct *obj,
    cui_dialer_type_enum new_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_change_type_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    CUI_DIALER_LOG((TRC_CUI_DIALER_EMIT_CHANGE_TYPE, 200, obj->type, new_type));

    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CUI_DIALER_CHANGE_TYPE, obj->this_gid);
    evt.old_type = obj->type;
    evt.new_type = new_type;

    mmi_frm_group_post_to_parent(obj->this_gid, (mmi_group_event_struct *)&evt);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_emit_before_call_launched
 * DESCRIPTION
 *  This function emits the before call launched event.
 * PARAMETERS
 *  obj             : [IN]          Dialer object
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_emit_before_call_launched(cui_dialer_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_before_call_launched_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CUI_DIALER_LOG((TRC_CUI_DIALER_EMIT_BEFORE_CALL_LAUNCHED, 200));


    MMI_FRM_INIT_GROUP_EVENT(
        &evt,
        EVT_ID_CUI_DIALER_BEFORE_CALL_LAUNCHED,
        obj->this_gid);

    evt.type = obj->type;

    mmi_frm_group_send_to_parent(obj->this_gid, (mmi_group_event_struct *)&evt);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_handle_bootup_normal_init
 * DESCRIPTION
 *  This function handles the bootup normal init.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret cui_dialer_handle_bootup_normal_init(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CUI_DIALER_LOG((TRC_CUI_DIALER_HANDLE_BOOTUP_NORMAL_INIT, 200));

    cui_dialer_factory_init();

#if defined(__MMI_DIALER_SEARCH__)
	cui_dialer_search_read_setting();
#endif

#if defined(__GENERAL_TTS__)
    cui_dialer_get_tts_setting();
#endif

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_main_evt_hdlr
 * DESCRIPTION
 *  This function is the main event handler of the dialer common UI.
 * PARAMETERS
 *  event           : [IN]      event
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret cui_dialer_main_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (event->evt_id)
    {
        case EVT_ID_SRV_BOOTUP_NORMAL_INIT:
            ret = cui_dialer_handle_bootup_normal_init(event);
            break;

        default:
            ret = MMI_RET_OK;
            break;
    }

    return ret;
}


/* For the detail information, please refer to the DialerCuiGprot.h */
mmi_id cui_dialer_create(mmi_id parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CUI_DIALER_LOG((TRC_CUI_DIALER_CREATE, 200));

    obj = cui_dialer_new_obj();

    MMI_ASSERT(obj && obj->on_create);

    return obj->on_create(obj, parent_gid);
}


/* For the detail information, please refer to the DialerCuiGprot.h */
mmi_id cui_dialer_create_ex(mmi_id parent_gid, cui_dialer_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CUI_DIALER_LOG((TRC_CUI_DIALER_CREATE_EX, 200, type));

    obj = cui_dialer_new_obj_ex(type);

    MMI_ASSERT(obj && obj->on_create);

    return obj->on_create(obj, parent_gid);
}


/* For the detail information, please refer to the DialerCuiGprot.h */
void cui_dialer_run(mmi_id this_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CUI_DIALER_LOG((TRC_CUI_DIALER_RUN, 200));

    obj = (cui_dialer_obj_struct *)mmi_frm_group_get_user_data(this_gid);

    MMI_ASSERT(obj && obj->on_run);

    obj->on_run(obj);
}


/* For the detail information, please refer to the DialerCuiGprot.h */
void cui_dialer_close(mmi_id this_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CUI_DIALER_LOG((TRC_CUI_DIALER_CLOSE, 200));

    obj = (cui_dialer_obj_struct *)mmi_frm_group_get_user_data(this_gid);

    MMI_ASSERT(obj && obj->on_close);

    obj->on_close(obj);
}


/* For the detail information, please refer to the DialerCuiGprot.h */
void cui_dialer_set_dial_string(mmi_id this_gid, const WCHAR *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CUI_DIALER_LOG((TRC_CUI_DIALER_SET_DIAL_STRING, 200));

    obj = (cui_dialer_obj_struct *)mmi_frm_group_get_user_data(this_gid);

    MMI_ASSERT(obj && obj->on_set_dial_string);

    obj->on_set_dial_string(obj, string);
}


/* For the detail information, please refer to the DialerCuiGprot.h */
void cui_dialer_set_key(mmi_id this_gid, U16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CUI_DIALER_LOG((TRC_CUI_DIALER_SET_KEY, 200));

    obj = (cui_dialer_obj_struct *)mmi_frm_group_get_user_data(this_gid);

    MMI_ASSERT(obj && obj->on_set_key);

    obj->on_set_key(obj, key_code);
}


/* For the detail information, please refer to the DialerCuiGprot.h */
void cui_dialer_set_translate_key(
        mmi_id this_gid,
        S16 key_code,
        S16 key_type,
        U16 ucs2_value,
        U32 key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CUI_DIALER_LOG((TRC_CUI_DIALER_SET_TRANSLATE_KEY, 200));

    obj = (cui_dialer_obj_struct *)mmi_frm_group_get_user_data(this_gid);

    MMI_ASSERT(obj && obj->on_set_translate_key);

    obj->on_set_translate_key(obj, key_code, key_type, ucs2_value, key_flag);
}


/* For the detail information, please refer to the DialerCuiGprot.h */
const WCHAR *cui_dialer_get_dial_string(mmi_id this_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CUI_DIALER_LOG((TRC_CUI_DIALER_GET_DIAL_STRING, 200));

    obj = (cui_dialer_obj_struct *)mmi_frm_group_get_user_data(this_gid);

    MMI_ASSERT(obj && obj->on_get_dial_string);

    return obj->on_get_dial_string(obj);
}


/* For the detail information, please refer to the DialerCuiGprot.h */
void cui_dialer_set_phb_data(mmi_id this_gid, void *phb_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CUI_DIALER_LOG((TRC_CUI_DIALER_SET_PHB_DATA, 200));

    obj = (cui_dialer_obj_struct *)mmi_frm_group_get_user_data(this_gid);

    MMI_ASSERT(obj && obj->on_set_phb_data);

    obj->on_set_phb_data(obj, phb_data);
}


/* For the detail information, please refer to the DialerCuiGprot.h */
void *cui_dialer_get_phb_data(mmi_id this_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CUI_DIALER_LOG((TRC_CUI_DIALER_GET_PHB_DATA, 200));

    obj = (cui_dialer_obj_struct *)mmi_frm_group_get_user_data(this_gid);

    MMI_ASSERT(obj && obj->on_get_phb_data);

    return obj->on_get_phb_data(obj);
}


/* For the detail information, please refer to the DialerCuiGprot.h */
MMI_BOOL cui_dialer_is_active_if_any(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_struct *obj = cui_dialer_get_obj_in_active_serial();
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (obj && mmi_frm_group_get_active_id() == obj->this_gid &&
        mmi_frm_scrn_get_active_id() == SCR_ID_CUI_DIALER_MAIN)
    {
        ret = MMI_TRUE;
    }

    CUI_DIALER_LOG((TRC_CUI_DIALER_IS_ACTIVE_IF_ANY, 200, ret));

    return ret;
}

cui_dialer_type_enum cui_dialer_get_type_if_any(void)
{
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	cui_dialer_obj_struct *obj;
	
	obj = cui_dialer_get_obj_in_active_serial();
	if(obj)
	{
		return obj->type;
	}
	else
	{
		return CUI_DIALER_TYPE_INVALID;
	}

}

/* For the detail information, please refer to the DialerCuiGprot.h */
const WCHAR *cui_dialer_get_dial_string_if_any(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cui_dialer_is_active_if_any())
    {
        CUI_DIALER_LOG((TRC_CUI_DIALER_GET_DIAL_STRING_IF_ANY, 200));

        obj = cui_dialer_get_obj_in_active_serial();
        MMI_ASSERT(obj);

        return cui_dialer_get_dial_string(obj->this_gid);
    }

    CUI_DIALER_LOG((TRC_CUI_DIALER_GET_DIAL_STRING_IF_ANY, 500));

    return NULL;
}


/* For the detail information, please refer to the DialerCuiGprot.h */
void cui_dialer_close_if_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_struct *obj = cui_dialer_get_obj_in_history();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (obj)
    {
    #ifdef __OP01_FWPBW__
        if (obj->type == CUI_DIALER_TYPE_BWT)
        {
            cui_dialer_bwt_close();
        }
        else
    #endif /* __OP01_FWPBW__ */
        {
            cui_dialer_emit_close_req(obj);
        }
    }
}


/* For the detail information, please refer to the DialerCuiGprot.h */
void cui_dialer_set_launch_style(mmi_id this_gid, cui_dialer_launch_type_enum value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj = (cui_dialer_obj_struct *)mmi_frm_group_get_user_data(this_gid);

    MMI_ASSERT(obj && obj->on_set_launch);

    if (value == CUI_DIALER_LAUNCH_TYPE_EDIT_BEFORE_CALL)
    {
        obj->on_set_launch(obj, MMI_TRUE);
    }
    else
    {
       obj->on_set_launch(obj, MMI_FALSE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_handle_dialer_change_type
 * DESCRIPTION
 *  This function handles the dialer type event.
 * PARAMETERS
 *  event               : [IN]          Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
MMI_ID cui_dialer_handle_dialer_change_type(mmi_event_struct *event, MMI_ID parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_id this_gid;
    cui_dialer_change_type_evt_struct *p;
    WCHAR dial_string[CUI_DIALER_MAX_DIAL_BUF_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = (cui_dialer_change_type_evt_struct *)event;

    mmi_wcsncpy(
        dial_string,
        cui_dialer_get_dial_string(p->sender_id),
        CUI_DIALER_MAX_DIAL_STR_LEN);

    cui_dialer_close(p->sender_id);

	this_gid = cui_dialer_create_ex(parent_id, p->new_type);
    if (p->new_type != CUI_DIALER_TYPE_VOIP &&
        p->old_type != CUI_DIALER_TYPE_VOIP)
    {
        cui_dialer_set_dial_string(this_gid, dial_string);
    }
	
	cui_dialer_run(this_gid);

    return this_gid;
}


