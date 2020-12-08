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
 *  DialerCuiObject.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the dialer object.
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
#include "DialerCuiObject.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "DialerCuiMain.h"
#include "DialerCuiFactory.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "DialerCuiGprot.h"
#include "custom_phb_config.h"
#include "Unicodexdcl.h"
#include "GlobalConstants.h"
#include "DialerCuiCommon.h"

#ifdef __MMI_NCENTER_SUPPORT__
#include "vapp_ncenter_gprot.h"
#endif

/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_handle_group_deinit
 * DESCRIPTION
 *  This function handles the group deinit event.
 * PARAMETERS
 *  event               : [IN]          Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret cui_dialer_handle_group_deinit(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_dialer_obj_struct *obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    obj = (cui_dialer_obj_struct *)event->user_data;

    cui_dialer_emit_closed_ind(obj);

	cui_dialer_dereg_obj(obj);
    mmi_mfree(obj);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_obj_evt_hdlr
 * DESCRIPTION
 *  This function is the group event handler of the dialer CUI.
 * PARAMETERS
 *  event               : [IN]              Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret cui_dialer_obj_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (event->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            ret = cui_dialer_handle_group_deinit(event);
            break;
#ifdef	__MMI_NCENTER_SUPPORT__	
		case EVT_ID_VAPP_NCENTER_DRAG:
			if(cui_dialer_get_type_if_any() == CUI_DIALER_TYPE_SOS)
			{
				ret = MMI_RET_ERR;
			}
		break;
#endif	

        default:
            ret = MMI_RET_OK;
            break;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_obj_on_create
 * DESCRIPTION
 *  This function creates the dialer CUI.
 * PARAMETERS
 *  obj                 : [IN]              Object
 *  parent_gid          : [IN]              Parent group ID
 * RETURNS
 *  Dialer CUI group ID.
 *****************************************************************************/
mmi_id cui_dialer_obj_on_create(cui_dialer_obj_struct *obj, mmi_id parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id this_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    this_gid = mmi_frm_group_create(
                parent_gid,
                GRP_ID_AUTO_GEN,
                cui_dialer_obj_evt_hdlr,
                obj);

    MMI_ASSERT(this_gid != GRP_ID_INVALID);

    obj->parent_gid = parent_gid;
    obj->this_gid = this_gid;

    return this_gid;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_obj_on_close
 * DESCRIPTION
 *  This function closes the dialer CUI.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_obj_on_close(cui_dialer_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_group_close(obj->this_gid);
}

/*****************************************************************************
 * FUNCTION
 *  cui_dialer_obj_on_set_dial_string
 * DESCRIPTION
 *  This function sets the dialer string.
 * PARAMETERS
 *  obj                 : [IN]          Object
 *  string              : [IN]          String
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_obj_on_set_dial_string(
    cui_dialer_obj_struct *obj,
    const WCHAR *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_wcsncpy(obj->dial_string, string, CUI_DIALER_MAX_DIAL_STR_LEN);
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_obj_on_set_key
 * DESCRIPTION
 *  This function sets the first input key which opens the dialer.
 * PARAMETERS
 *  obj                 : [IN]              Object
 *  key_code            : [IN]              String
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_obj_on_set_key(cui_dialer_obj_struct *obj, U16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (key_code <= KEY_9 ||
        (key_code == KEY_STAR || key_code == KEY_POUND))
    {
        obj->first_input_source = CUI_DIALER_FIRST_INPUT_DIGITAL_KEY;
        obj->key_code = key_code;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_obj_on_set_translate_key
 * DESCRIPTION
 *  This function sets the translate key which opens the dialer.
 * PARAMETERS
 *  obj                 : [IN]          Object
 *  key_code            : [IN]          Key code
 *  key_type            : [IN]          Key type
 *  ucs2_value          : [IN]          UCS2 value
 *  key_flag            : [IN]          Key flag
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_obj_on_set_translate_key(
    cui_dialer_obj_struct *obj,
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

    obj->first_input_source = CUI_DIALER_FIRST_INPUT_QWERTY_KEY;

    obj->key_code = key_code;
    obj->key_type = key_type;
    obj->ucs2_value = ucs2_value;
    obj->key_flag = key_flag;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_obj_on_get_dial_string
 * DESCRIPTION
 *  This function gets the dial string.
 * PARAMETERS
 *  obj             : [IN]          Object
 * RETURNS
 *  void
 *****************************************************************************/
const WCHAR *cui_dialer_obj_on_get_dial_string(cui_dialer_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return obj->dial_string;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_obj_on_set_phb_data
 * DESCRIPTION
 *  This function sets the phone book data which will be passed to UCM when the
 *  user dials call.
 * PARAMETERS
 *  obj                 : [IN]              Object
 *  phb_data            : [IN]              Phone book data
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_obj_on_set_phb_data(cui_dialer_obj_struct *obj, void *phb_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    obj->phb_data = phb_data;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_obj_on_get_phb_data
 * DESCRIPTION
 *  This function gets the phone book data.
 * PARAMETERS
 *  obj                 : [IN]              Object
 * RETURNS
 *  Phone book data pointer.
 *****************************************************************************/
void *cui_dialer_obj_on_get_phb_data(cui_dialer_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return obj->phb_data;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_obj_on_get_phb_data
 * DESCRIPTION
 *  This function gets the phone book data.
 * PARAMETERS
 *  obj                 : [IN]              Object
 * RETURNS
 *  Phone book data pointer.
 *****************************************************************************/
void cui_dialer_obj_on_set_launch_by_calllog(cui_dialer_obj_struct *obj, MMI_BOOL value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    obj->launch_by_calllog = value;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_obj_on_want_to_run
 * DESCRIPTION
 *  This function checks if the dialer wants to run.
 * PARAMETERS
 *  void
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL cui_dialer_obj_on_want_to_run(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  cui_dialer_obj_on_init
 * DESCRIPTION
 *  This function initializes the dialer object.
 * PARAMETERS
 *  obj             : [IN]              Object
 * RETURNS
 *  void
 *****************************************************************************/
void cui_dialer_obj_on_init(cui_dialer_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    /* Member variable. */
	memset(obj,0,sizeof(obj));

    obj->first_input_source = CUI_DIALER_FIRST_INPUT_INVALID;

    cui_dialer_init_capability(&obj->capability);

    /* Member function. */
    obj->on_create = cui_dialer_obj_on_create;
    obj->on_close = cui_dialer_obj_on_close;
    obj->on_set_dial_string = cui_dialer_obj_on_set_dial_string;
    obj->on_set_key = cui_dialer_obj_on_set_key;
    obj->on_set_translate_key = cui_dialer_obj_on_set_translate_key;
    obj->on_get_dial_string = cui_dialer_obj_on_get_dial_string;
    obj->on_set_phb_data = cui_dialer_obj_on_set_phb_data;
    obj->on_get_phb_data = cui_dialer_obj_on_get_phb_data;
    obj->on_set_launch = cui_dialer_obj_on_set_launch_by_calllog;
}

