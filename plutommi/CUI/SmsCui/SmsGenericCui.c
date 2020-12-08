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
 *  SmsSettingSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service Setting Handler
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
 *****************************************************************************/
#ifdef __MOD_SMSAL__
/**************************************************************
* Header Files Include
**************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "kal_general_types.h"
#include "AlertScreen.h"
#include "CustDataRes.h"
#include "CommonScreensResDef.h"
#include "gui_data_types.h"
#include "TimerEvents.h"
#include "custom_events_notify.h"
#include "wgui_categories_popup.h"
#include "kal_public_api.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_timer_gprot.h"
#include "wgui_categories_util.h"
#include "mmi_rp_app_sms_def.h"
#include "SmsCuiGprot.h"
#include "SmsGenericCui.h"
#include "mmi_frm_events_gprot.h"
#include "UcmSrvGprot.h"

/**************************************************************
* MARCO
**************************************************************/
#define CUI_SMS_PROGRESS_TIME_OUT           1000*50


/**************************************************************
* Structure Declaration
**************************************************************/
typedef struct
{
    FuncPtr lsk_func;
    FuncPtr rsk_func;
} cui_sms_confirm_data_struct;


/**************************************************************
* Global Variables Declaration
**************************************************************/ 


/**************************************************************
* Extern Function Declaration
**************************************************************/
#ifdef __MMI_MESSAGES_TEMPLATE__
extern MMI_ID mmi_sms_template_list_create(MMI_ID parent_gid, MMI_BOOL allow_empty_list, cui_sms_template_type_enum templ_type, MMI_BOOL is_popup);
extern void mmi_sms_template_list_run(MMI_ID template_gid);
extern void mmi_sms_template_list_close(MMI_ID template_gid);
extern WCHAR* mmi_sms_template_list_get_select_content(MMI_ID template_gid);
extern void mmi_sms_template_list_set_left_softkey(MMI_ID template_gid, U16 left_string_id, U16 left_icon_id);
extern void mmi_sms_template_list_set_csk_softkey(MMI_ID template_gid, U16 csk_string_id, U16 csk_icon_id);
#endif /* __MMI_MESSAGES_TEMPLATE__ */

/**************************************************************
* Static Variables Defination
**************************************************************/
static S16 process_body_str_id;
static U16 process_rsk_str_id;
static FuncPtr process_lsk_func = NULL;
static FuncPtr process_rsk_func = NULL;
static MMI_ID process_gid;


/**************************************************************
* Static Function Declaration
**************************************************************/
static mmi_ret cui_sms_confirm_display_hdlr(mmi_event_struct *evt);
    

/**************************************************************
* Function Defination
**************************************************************/

/*****************************************************************************
 * FUNCTION
 *  cui_sms_entry_confirm
 * DESCRIPTION
 *  Entry MSG generic confirmation screen group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_sms_entry_confirm(
        MMI_ID parent_id,
        U16 str_id,
        FuncPtr lsk_func,
        FuncPtr rsk_func,
        MMI_BOOL is_enable_csk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    cui_sms_confirm_data_struct *confirm_data = OslMalloc(sizeof(cui_sms_confirm_data_struct));
    WCHAR* text = (WCHAR*)GetString(str_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = (mmi_proc_func)cui_sms_confirm_display_hdlr;
    arg.parent_id = parent_id;
    arg.f_auto_map_empty_softkey = is_enable_csk;
    confirm_data->lsk_func = lsk_func;
    confirm_data->rsk_func = rsk_func;
    arg.user_tag = confirm_data;
    
    mmi_confirm_display(text, MMI_EVENT_QUERY, &arg);
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_entry_confirm_sg_ext
 * DESCRIPTION
 *  Entry MSG generic confirmation screen group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_sms_entry_confirm_sg_ext(
        MMI_ID parent_id,
        WCHAR* str,
        FuncPtr lsk_func,
        FuncPtr rsk_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    cui_sms_confirm_data_struct *confirm_data = OslMalloc(sizeof(cui_sms_confirm_data_struct));
    WCHAR* text = str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = (mmi_proc_func)cui_sms_confirm_display_hdlr;
    arg.parent_id = parent_id;
    confirm_data->lsk_func = lsk_func;
    confirm_data->rsk_func = rsk_func;
    arg.user_tag = confirm_data;
    
    mmi_confirm_display(text, MMI_EVENT_QUERY, &arg);
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_confirm_display_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  alert_result    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret cui_sms_confirm_display_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *alert_result = (mmi_alert_result_evt_struct*)evt;
    cui_sms_confirm_data_struct *confirm_data = (cui_sms_confirm_data_struct*) alert_result->user_tag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_DELETE_REQ:
            break;

        case EVT_ID_SCRN_DEINIT:
            break;

        case EVT_ID_ALERT_QUIT:
            switch (alert_result->result)
            {
        	    case MMI_ALERT_CNFM_YES:
                    (confirm_data->lsk_func)();
                    break;

                case MMI_ALERT_CNFM_NO:
                    (confirm_data->rsk_func)();
                    break;

                case MMI_ALERT_NORMAL_EXIT:
                case MMI_ALERT_INTERRUPT_EXIT:
                case MMI_ALERT_NO_SHOW:
                    if (confirm_data != NULL)
                    {
                        OslMfree(confirm_data);
                		alert_result->user_tag = NULL;
                    }
                    break;

                default:
                    break;
            }
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_display_popupcallback_sg
 * DESCRIPTION
 *  
 * PARAMETERS
 *               
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL cui_sms_display_popupcallback_sg(
    MMI_ID parent_id,
    WCHAR* string,
    mmi_event_notify_enum event_id,
    mmi_proc_func receiver_proc,
    void *user_data,
    U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct arg;
    WCHAR * title = string;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_property_init(&arg);
    arg.callback = receiver_proc;
    arg.user_tag = user_data;
    arg.parent_id = parent_id;

    if (GRP_ID_INVALID != mmi_popup_display(title, event_id, &arg))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_display_popupcallback_sg_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *               
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL cui_sms_display_popupcallback_sg_ext(
    MMI_ID parent_id,
    MMI_STR_ID title,
    mmi_event_notify_enum event_id,
    mmi_proc_func receiver_proc,
    void *user_data,
    U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_property_init(&arg);
    arg.callback = receiver_proc;
    arg.user_tag = user_data;
    arg.parent_id = parent_id;

    if (GRP_ID_INVALID != mmi_popup_display_ext(title, event_id, &arg))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_display_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text        [IN]        
 *  event_id    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cui_sms_display_popup(UI_string_type text, mmi_event_notify_enum event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display((WCHAR*)text, event_id, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_display_popup_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text        [IN]        
 *  event_id    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cui_sms_display_popup_ext(MMI_STR_ID title, mmi_event_notify_enum event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_ext(title, event_id, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_processing_screen
 * DESCRIPTION
 *  Set string and image for MSG processing screen
 * PARAMETERS
 *  captionStrId            [IN]        
 *  bodyStrId               [IN]        
 *  animationImageId        [IN]        
 *  rskStrId                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cui_sms_set_processing_screen(mmi_id sms_gid, U16 bodyStrId, U16 rskStrId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    process_body_str_id = bodyStrId;
    process_rsk_str_id = rskStrId;
    process_lsk_func = NULL;
    process_rsk_func = NULL;
    process_gid = sms_gid;
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_exit_processing_generic
 * DESCRIPTION
 *  Exit MSG generic processing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_exit_processing_generic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(MESSAGES_INPROGRESS_TIMER_ID);
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_processing_generic_time_out
 * DESCRIPTION
 *  Time out call back of processing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_processing_generic_time_out(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(MESSAGES_INPROGRESS_TIMER_ID);

    if (mmi_frm_scrn_get_active_id() == SCR_ID_SMS_PROCESSING)
    {
        cui_sms_display_popup_ext(
            STR_GLOBAL_UNFINISHED,
            MMI_EVENT_FAILURE);
    }

    mmi_frm_scrn_close(process_gid, SCR_ID_SMS_PROCESSING);
}

/*****************************************************************************
 * FUNCTION
 *  cui_sms_entry_processing_generic
 * DESCRIPTION
 *  Entry MSG generic processing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_sms_entry_processing_generic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr end_key_func;
    U16 process_image_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(
            process_gid,
            SCR_ID_SMS_PROCESSING,
            cui_sms_exit_processing_generic,
            cui_sms_entry_processing_generic,
            MMI_FRM_FULL_SCRN))
    {
        process_image_id = mmi_get_event_based_image(MMI_EVENT_PROGRESS);

        /*do not set title and title icon, otherwise processing screen will be a full screen*/
        ShowCategory8Screen(
            0,
            0,
            0,
            0,
            process_rsk_str_id,
            0,
            process_body_str_id,
            process_image_id,
            NULL);

        end_key_func = GetKeyHandler(KEY_END, KEY_EVENT_DOWN);

        ClearKeyHandler(KEY_END, KEY_EVENT_UP);
        ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
        ClearKeyHandler(KEY_END, KEY_REPEAT);

        if (process_rsk_str_id == 0)
        {
            StartTimer(MESSAGES_INPROGRESS_TIMER_ID, CUI_SMS_PROGRESS_TIME_OUT, cui_sms_processing_generic_time_out);
        }

        if (process_rsk_func != NULL)
        {
            SetRightSoftkeyFunction(process_rsk_func, KEY_EVENT_UP);   
        }
        else if (process_rsk_str_id != 0)
        {
            SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);       
        }
        if (process_lsk_func != NULL)
        {
            SetLeftSoftkeyFunction(process_lsk_func, KEY_EVENT_UP);
        }

        if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
        {
            SetKeyHandler(end_key_func, KEY_END, KEY_EVENT_DOWN);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_template_list_create
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID cui_sms_template_list_create(MMI_ID parent_gid, MMI_BOOL allow_empty_list, cui_sms_template_type_enum templ_type, MMI_BOOL is_show_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_TEMPLATE__
    return mmi_sms_template_list_create(parent_gid, allow_empty_list, templ_type, is_show_popup);
#else
    if (is_show_popup)
    {
        cui_sms_display_popup_ext(
            STR_GLOBAL_NOT_SUPPORTED,
            MMI_EVENT_FAILURE);
    }
    return GRP_ID_INVALID;
#endif /* __MMI_MESSAGES_TEMPLATE__ */
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_template_list_runs
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void cui_sms_template_list_run(MMI_ID template_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_TEMPLATE__
    mmi_sms_template_list_run(template_gid);
#endif /* __MMI_MESSAGES_TEMPLATE__ */
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_template_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_template_close(MMI_ID template_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_TEMPLATE__
    mmi_sms_template_list_close(template_gid);
#endif /* __MMI_MESSAGES_TEMPLATE__ */
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_template_list_get_select_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
WCHAR* cui_sms_template_list_get_select_content(MMI_ID template_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_TEMPLATE__
    return mmi_sms_template_list_get_select_content(template_gid);
#else
    return NULL;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_template_list_set_left_softkey
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void cui_sms_template_list_set_left_softkey(MMI_ID template_gid, U16 left_string_id, U16 left_icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_TEMPLATE__
    mmi_sms_template_list_set_left_softkey(template_gid, left_string_id, left_icon_id);
#endif /* __MMI_MESSAGES_TEMPLATE__ */
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_template_list_set_csk_softkey
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void cui_sms_template_list_set_csk_softkey(MMI_ID template_gid, U16 csk_string_id, U16 csk_icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_TEMPLATE__
    mmi_sms_template_list_set_csk_softkey(template_gid, csk_string_id, csk_icon_id);
#endif /* __MMI_MESSAGES_TEMPLATE__ */
}


#endif /* __MOD_SMSAL__ */
