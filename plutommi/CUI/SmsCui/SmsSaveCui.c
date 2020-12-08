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
#include "MMI_features.h"

#ifdef __MOD_SMSAL__
/**************************************************************
* Header Files Include
**************************************************************/
#include "MMIDataType.h"
#include "string.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "ems.h"
#include "kal_general_types.h"
#include "custom_mmi_default_value.h"
#include "CustDataRes.h"
#include "gui_data_types.h"
#include "Unicodexdcl.h"
#include "kal_public_api.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_rp_app_sms_def.h"
#include "SmsSrvGprot.h"
#include "SmsCuiGprot.h"
#include "SmsGenericCui.h"
#include "FileMgrSrvGProt.h"
#include "MenuCuiGprot.h"
#include "SimCtrlSrvGProt.h"
#include "NwUsabSrvGprot.h"

/**************************************************************
* MARCO
**************************************************************/
#define CUI_SMS_MAX_SAVE_INSTANCE       1


/**************************************************************
* Structure Declaration
**************************************************************/
typedef struct
{
    S8 number[(CUI_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH];
    S8 sc_addr[(CUI_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH];
    MMI_BOOL save_result;
    U16 saved_msg_id;
    srv_sms_sim_enum sim_id;
    srv_sms_status_enum status;

    srv_sms_para_enum para_flag;
    MYTIME timestamp;
    srv_sms_pid_enum pid;
    srv_sms_dcs_enum dcs;
    MMI_BOOL status_report;
    MMI_BOOL reply_path;
    MMI_BOOL is_asc_content;
    U16 content_buff_size;
    S8 *content_buff;
    S8 *content_file_path;
    EMSData *content_ems;
} cui_sms_save_handle_data_struct;

typedef struct
{
    mmi_id save_gid;
    mmi_id parent_gid;
    cui_sms_save_handle_data_struct *data;
    SMS_HANDLE srv_save_handle;
    U16 title_id;
    U16 string_id;
    U16 draft_msg_id;
    MMI_BOOL is_edit_draft;
} cui_sms_save_handle_struct;

typedef struct
{
    mmi_id parent_gid;
    mmi_id save_gid;
    MMI_BOOL save_result;
    srv_sms_cause_enum cause;
    U16 saved_msg_id;
} cui_evt_sms_save_popup_info_struct;


/**************************************************************
* Global Variables Declaration
**************************************************************/ 


/**************************************************************
* Extern Function Declaration
**************************************************************/


/**************************************************************
* Static Variables Defination
**************************************************************/
static U8 save_instance_in_use = 0;
static mmi_id cui_sms_save_instance[CUI_SMS_MAX_SAVE_INSTANCE];
static mmi_id cui_sms_save_active_gid = GRP_ID_INVALID;

/**************************************************************
* Static Function Declaration
**************************************************************/
static mmi_ret cui_sms_save_proc(mmi_event_struct* evt);
static void* cui_sms_get_save_handle(mmi_id sms_gid);
static cui_sms_save_handle_data_struct* cui_sms_get_save_handle_data(mmi_id sms_gid);
static mmi_id cui_sms_get_active_save_gid(void);
static void cui_sms_set_active_save_gid(mmi_id sms_gid);
static void cui_sms_save_msg_callback(srv_sms_callback_struct *callback_data);
static void cui_sms_save_send_evt_to_parent(cui_evt_sms_save_popup_info_struct *para_info);
static void cui_sms_save_msg(void);
static void cui_sms_pre_save_msg(void);
static void cui_sms_save_to_drafts_del_callback(srv_sms_callback_struct* callback_data);
#ifdef __MMI_DUAL_SIM_MASTER__
static void cui_sms_set_save_sim_type(srv_sms_sim_enum sim_id);
static void cui_sms_entry_save_select_sim_options(void);
static void cui_sms_save_select_sim_hdlr(cui_menu_event_struct *menu_evt);
static void cui_sms_save_opt_by_sim1(void);
static void cui_sms_save_opt_by_sim2(void);
#if  (MMI_MAX_SIM_NUM >= 3)
static void cui_sms_save_opt_by_sim3(void);
#endif
#if  (MMI_MAX_SIM_NUM >= 4)
static void cui_sms_save_opt_by_sim4(void);
#endif
static void cui_sms_dm_pre_save_msg(void);
#endif
static void cui_sms_save_entry(mmi_id sms_gid);
static void cui_sms_save_deinit_handle(cui_sms_save_handle_struct *handle);


/**************************************************************
* Function Defination
**************************************************************/
/*****************************************************************************
 * FUNCTION
 *  cui_sms_save_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mmi_id cui_sms_save_create(mmi_id parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_save_gid = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_is_sms_ready() && save_instance_in_use < CUI_SMS_MAX_SAVE_INSTANCE)
    {
        U8 i;
        cui_sms_save_handle_struct *gid_data = OslMalloc(sizeof(cui_sms_save_handle_struct));

        gid_data->parent_gid = parent_gid;

        gid_data->data = OslMalloc(sizeof(cui_sms_save_handle_data_struct));
        memset(gid_data->data, 0, sizeof(cui_sms_save_handle_data_struct));

        gid_data->data->para_flag |= SRV_SMS_PARA_STATUS;
        gid_data->data->status = SRV_SMS_STATUS_DRAFT;
        
    #ifdef __MMI_MESSAGES_DRAFT_BOX__
        gid_data->title_id = STR_SMS_SAVE_TO_DRAFTS_MENU_ITEM;
    #else /*__MMI_MESSAGES_DRAFT_BOX__*/
        gid_data->title_id = STR_GLOBAL_SAVE;
    #endif /*__MMI_MESSAGES_DRAFT_BOX__*/
        gid_data->string_id = STR_GLOBAL_SAVED;

        sms_save_gid = mmi_frm_group_create(parent_gid, GRP_ID_AUTO_GEN, cui_sms_save_proc, gid_data);

        gid_data->save_gid = sms_save_gid;
        gid_data->is_edit_draft = MMI_FALSE;

        for (i = 0; i< CUI_SMS_MAX_SAVE_INSTANCE; i++)
        {
            if (cui_sms_save_instance[i] == 0)
            {
                cui_sms_save_instance[i] = sms_save_gid;
                break;
            }
        }

        save_instance_in_use++;
    }

    if (sms_save_gid == GRP_ID_INVALID)
    {
        cui_sms_display_popup_ext(
            STR_GLOBAL_NOT_AVAILABLE,
            MMI_EVENT_FAILURE);
    }

    return sms_save_gid;
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_save_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret cui_sms_save_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_save_handle_struct *save_hd = (cui_sms_save_handle_struct*)evt->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_ACTIVE:
            cui_sms_set_active_save_gid(save_hd->save_gid);
            break;

        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
            break;

        case EVT_ID_GROUP_DEINIT:
            /* need addd code to release buffer */
            cui_sms_save_deinit_handle(save_hd);
            break;
            
    #ifdef __MMI_DUAL_SIM_MASTER__
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            break;

        case EVT_ID_CUI_MENU_LIST_ENTRY:
            {
                cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;

                switch (menu_evt->parent_menu_id)
                {
                    case MENU_ID_SMS_SAVE_TO_BOX:
                        break;

                    default:
                        break;
                }
            }
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
            {
                cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
                
                switch (menu_evt->parent_menu_id)
                {
                    case MENU_ID_SMS_SAVE_TO_BOX:
                        cui_sms_save_select_sim_hdlr(menu_evt);
                        break;

                    default:
                        break;
                }
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            {
                cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
                cui_menu_close(menu_evt->sender_id);
            }
            break;
    #endif /* __MMI_DUAL_SIM_MASTER__ */

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_save_run
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_save_run(mmi_id sms_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sms_gid !=GRP_ID_INVALID)
    {
        mmi_frm_group_enter(sms_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

        cui_sms_save_entry(sms_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_save_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_save_close(mmi_id sms_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(sms_gid, SCR_ID_SMS_PROCESSING);

    mmi_frm_group_close(sms_gid);
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_save_deinit_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void cui_sms_save_deinit_handle(cui_sms_save_handle_struct *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    mmi_id sms_save_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(handle != NULL);

    sms_save_gid = handle->save_gid;

    if(handle->data != NULL)
    {
        if (handle->data->content_file_path)
        {
            OslMfree(handle->data->content_file_path);
            handle->data->content_file_path = NULL;
        }
        OslMfree(handle->data);
        handle->data = NULL;
    }

    OslMfree(handle);
    handle = NULL;

    for (i = 0; i< CUI_SMS_MAX_SAVE_INSTANCE; i++)
    {
        if (cui_sms_save_instance[i] == sms_save_gid)
        {
            cui_sms_save_instance[i] = 0;
            break;
        }
    }

    if (save_instance_in_use > 0)
    {
        save_instance_in_use--;
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_sms_get_send_parent_gid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void* cui_sms_get_save_handle(mmi_id sms_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_save_handle_struct *handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = (cui_sms_save_handle_struct*) mmi_frm_group_get_user_data(sms_gid);

    return handle;
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_get_save_handle_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
cui_sms_save_handle_data_struct* cui_sms_get_save_handle_data(mmi_id sms_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_save_handle_struct *handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = (cui_sms_save_handle_struct*)mmi_frm_group_get_user_data(sms_gid);

    if (sms_gid == handle->save_gid)
    {
        return handle->data;
    }
    else
    {
        return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_save_address
 * DESCRIPTION
 *  CUI for send and save
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_save_address(mmi_id sms_gid, U16 *ucs2_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 invalid_num = 0;
    cui_sms_save_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sms_gid != GRP_ID_INVALID)
    {
        hd_data = cui_sms_get_save_handle_data(sms_gid);
        if (srv_sms_check_ucs2_number((S8*)ucs2_addr) == MMI_FALSE)
        {
            invalid_num++;
        }
        else if (mmi_ucs2strlen((S8*)ucs2_addr) > 0)
        {
            memcpy(hd_data->number, (S8*)ucs2_addr, (CUI_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH);
            hd_data->para_flag |= SRV_SMS_PARA_NUM;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_save_sc_addr
 * DESCRIPTION
 *  CUI for send and save
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_save_sc_addr(mmi_id sms_gid, U16 *ucs2_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 invalid_num = 0;
    cui_sms_save_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sms_gid != GRP_ID_INVALID)
    {
        hd_data = cui_sms_get_save_handle_data(sms_gid);
        if (srv_sms_check_ucs2_number((S8*)ucs2_addr) == MMI_FALSE)
        {
            invalid_num++;
        }
        else if (mmi_ucs2strlen((S8*)ucs2_addr) > 0)
        {
            memcpy(hd_data->sc_addr, (S8*)ucs2_addr, (CUI_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH);
            hd_data->para_flag |= SRV_SMS_PARA_SCA;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_save_content_text
 * DESCRIPTION
 *  CUI for send and save, content buffer DCS is ucs2
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_save_content_text(mmi_id sms_gid, U16 *content_buff, U16 content_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_save_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sms_gid != GRP_ID_INVALID)
    {
        hd_data = cui_sms_get_save_handle_data(sms_gid);

        hd_data->para_flag |= SRV_SMS_PARA_DCS;
        hd_data->dcs = SRV_SMS_DCS_7BIT;

        hd_data->para_flag |= SRV_SMS_PARA_CONTENT_BUFF;

        hd_data->content_buff = (S8*)content_buff;
        hd_data->content_buff_size = content_size;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_save_content_text_file
 * DESCRIPTION
 *  CUI for send and save,content_file_path dcs is UCS2, file content is ucs2 characters
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_save_content_text_file(mmi_id sms_gid, U16 *content_file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_save_handle_data_struct *hd_data;
    S32 file_path_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sms_gid != GRP_ID_INVALID)
    {
        hd_data = cui_sms_get_save_handle_data(sms_gid);

        hd_data->para_flag |= SRV_SMS_PARA_DCS;
        hd_data->para_flag |= SRV_SMS_PARA_CONTENT_FILE;

        hd_data->dcs = SRV_SMS_DCS_UCS2;

        file_path_len = mmi_ucs2strlen((S8*)content_file_path);

        if (file_path_len > SRV_FMGR_PATH_MAX_LEN)
        {
            file_path_len = SRV_FMGR_PATH_MAX_LEN;
        }

        hd_data->content_file_path = OslMalloc((file_path_len +1) *ENCODING_LENGTH);

        mmi_ucs2ncpy((S8*)hd_data->content_file_path, (S8*) content_file_path, (U32)file_path_len);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_save_content_ems
 * DESCRIPTION
 *  CUI for send and save
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_save_content_ems(mmi_id sms_gid, void *content_ems)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_save_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sms_gid != GRP_ID_INVALID)
    {
        hd_data = cui_sms_get_save_handle_data(sms_gid);
        
        hd_data->para_flag |= SRV_SMS_PARA_CONTENT_EMS;
        hd_data->content_ems = content_ems;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_save_sim_id
 * DESCRIPTION
 *  CUI for send and save
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_save_sim_id(mmi_id sms_gid, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_save_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sms_gid != GRP_ID_INVALID)
    {
        hd_data = cui_sms_get_save_handle_data(sms_gid);

        hd_data->para_flag |= SRV_SMS_PARA_SIM_ID;
        hd_data->sim_id = sim_id;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_save_handle_data_struct
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_save_status_report(mmi_id sms_gid, MMI_BOOL is_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_save_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sms_gid != GRP_ID_INVALID)
    {
        hd_data = cui_sms_get_save_handle_data(sms_gid);

        hd_data->para_flag |= SRV_SMS_PARA_STATUS_REPORT;
        hd_data->status_report = is_set;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_save_reply_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_save_reply_path(mmi_id sms_gid, MMI_BOOL is_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_save_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sms_gid != GRP_ID_INVALID)
    {
        hd_data = cui_sms_get_save_handle_data(sms_gid);

        hd_data->para_flag |= SRV_SMS_PARA_REPLY_PATH;
        hd_data->reply_path = is_set;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_save_msg_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_save_msg_status(mmi_id sms_gid, srv_sms_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_save_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sms_gid != GRP_ID_INVALID)
    {
        hd_data = cui_sms_get_save_handle_data(sms_gid);

        hd_data->para_flag |= SRV_SMS_PARA_STATUS;
        hd_data->status = status;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_save_pid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_save_pid(mmi_id sms_gid, srv_sms_pid_enum pid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_save_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sms_gid != GRP_ID_INVALID)
    {
        hd_data = cui_sms_get_save_handle_data(sms_gid);

        hd_data->para_flag |= SRV_SMS_PARA_PID;
        hd_data->pid = pid;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_save_msg_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_save_timestamp(mmi_id sms_gid, MYTIME *timestamp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_save_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sms_gid != GRP_ID_INVALID)
    {
        hd_data = cui_sms_get_save_handle_data(sms_gid);

        hd_data->para_flag |= SRV_SMS_PARA_TIMESTAMP;

        memcpy(&(hd_data->timestamp), timestamp, sizeof(MYTIME));
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_save_title_id
 * DESCRIPTION
 *  Default Save tille is STR_SMS_SAVE_TO_DRAFTS_MENU_ITEM,
 *  If need use other Title id need set this parameter.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_save_title_id(mmi_id sms_gid, U16 title_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_save_handle_struct *handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sms_gid != GRP_ID_INVALID)
    {
        handle = cui_sms_get_save_handle(sms_gid);

        handle->title_id = title_id;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_save_success_popup_string_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_save_success_popup_string_id(mmi_id sms_gid, U16 string_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_save_handle_struct *handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sms_gid != GRP_ID_INVALID)
    {
        handle = cui_sms_get_save_handle(sms_gid);

        handle->string_id = string_id;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_save_edit_draft
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_set_save_edit_draft_msg_id(mmi_id sms_gid, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_save_handle_struct *handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sms_gid != GRP_ID_INVALID)
    {
        handle = cui_sms_get_save_handle(sms_gid);

        handle->is_edit_draft = MMI_TRUE;
        handle->draft_msg_id = msg_id;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_get_active_save_gid
 * DESCRIPTION
 *  Cntx mgr get current running sg id
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_id
 *****************************************************************************/
static mmi_id cui_sms_get_active_save_gid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    /**
         * Now use framework api to get current running sg id. In furture, maybe need to maintain it by itself
         */
    //return mmi_frm_group_get_active_id();
    return cui_sms_save_active_gid;
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_active_save_gid
 * DESCRIPTION
 *  Cntx mgr get current running sg id
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_id
 *****************************************************************************/
static void cui_sms_set_active_save_gid(mmi_id sms_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    /**
         * Now use framework api to get current running sg id. In furture, maybe need to maintain it by itself
         */
    cui_sms_save_active_gid = sms_gid;
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_save_msg_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_id
 *****************************************************************************/
static void cui_sms_save_msg_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    cui_sms_save_handle_struct *handle = (cui_sms_save_handle_struct*) callback_data->user_data;
    cui_evt_sms_save_popup_info_struct param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    param.parent_gid = handle->parent_gid;
    param.save_gid = handle->save_gid;
    param.save_result = callback_data->result;
    param.cause = callback_data->cause;
    param.saved_msg_id = 0;

    if (callback_data->result == MMI_TRUE)
    {
        param.saved_msg_id = *(U16*)callback_data->action_data;

        cui_sms_display_popup_ext(
            handle->string_id,
            MMI_EVENT_EXPLICITLY_SAVED);

        cui_sms_save_send_evt_to_parent(&param);
    }
    else
    {
        switch (callback_data->cause)
        {
            case SRV_SMS_CAUSE_MEM_FULL:
            {
                cui_sms_display_popup_ext(
                    STR_GLOBAL_MEMORY_FULL,
                    MMI_EVENT_FAILURE);

                cui_sms_save_send_evt_to_parent(&param);
                break;
            }

            case SRV_SMS_CAUSE_MEM_INSUFFICIENT:
            {
                cui_sms_display_popup_ext(
                    STR_GLOBAL_NOT_ENOUGH_MEMORY,
                    MMI_EVENT_FAILURE);

                cui_sms_save_send_evt_to_parent(&param);
                break;
            }

            case SRV_SMS_CAUSE_NOT_READY:
            {
                cui_sms_display_popup_ext(
                    STR_SMS_MSG_NOT_READY_YET,
                    MMI_EVENT_FAILURE);

                cui_sms_save_send_evt_to_parent(&param);
                break;
            }

            case SRV_SMS_CAUSE_NUMBER_INVALID:
            {
                cui_sms_display_popup_ext(
                    STR_GLOBAL_INVALID_NUMBER,
                    MMI_EVENT_FAILURE);

                cui_sms_save_send_evt_to_parent(&param);
                break;
            }

            case SRV_SMS_CAUSE_DATA_INVALID:
            {
                cui_sms_display_popup_ext(
                    STR_SMS_FAILURE_DATA_INVALID,
                    MMI_EVENT_FAILURE);

                cui_sms_save_send_evt_to_parent(&param);
                break;
            }

            case SRV_SMS_CAUSE_DATA_EXCEED:
            {
                cui_sms_display_popup_ext(
                    STR_SMS_FAILURE_DATA_EXCEED,
                    MMI_EVENT_FAILURE);

                cui_sms_save_send_evt_to_parent(&param);
                break;
            }

            case SRV_SMS_CAUSE_SC_EMPTY:
            {
                cui_sms_display_popup_ext(
                    STR_SMS_FAILURE_SC_NUM_EMPTY,
                    MMI_EVENT_FAILURE);

                cui_sms_save_send_evt_to_parent(&param);
                break;
            }

            default:
            {
                cui_sms_display_popup_ext(
                    STR_GLOBAL_FAILED_TO_SAVE,
                    MMI_EVENT_FAILURE);

                cui_sms_save_send_evt_to_parent(&param);
                break;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_pre_save_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/
static void cui_sms_save_send_evt_to_parent(cui_evt_sms_save_popup_info_struct *para_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_evt_sms_save_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt.evt_id = EVT_ID_CUI_SMS_SAVE;
    evt.parent_gid = para_info->parent_gid;
    evt.save_result = para_info->save_result;
    evt.cause = para_info->cause;
    evt.saved_msg_id = para_info->saved_msg_id;
    mmi_frm_group_send_to_parent(para_info->save_gid, (mmi_group_event_struct*)&evt);
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_pre_save_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/
static void cui_sms_save_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_save_gid;
    SMS_HANDLE sms_handle;
    cui_sms_save_handle_struct *cui_handle;
    cui_sms_save_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_save_gid = cui_sms_get_active_save_gid();
    cui_handle = cui_sms_get_save_handle(sms_save_gid);
    hd_data = cui_handle->data;

    sms_handle = srv_sms_get_save_handle();

    if (hd_data->para_flag & SRV_SMS_PARA_NUM)
    {
        srv_sms_set_address(sms_handle, hd_data->number);
    }

    if (hd_data->para_flag & SRV_SMS_PARA_SCA)
    {
        srv_sms_set_sc_address(sms_handle, hd_data->sc_addr);
    }

    if (hd_data->para_flag & SRV_SMS_PARA_PID)
    {
        srv_sms_set_pid(sms_handle, hd_data->pid);
    }

    if (hd_data->para_flag & SRV_SMS_PARA_DCS)
    {
        srv_sms_set_content_dcs(sms_handle, hd_data->dcs);
    }

    if (hd_data->para_flag & SRV_SMS_PARA_STATUS_REPORT)
    {
        srv_sms_set_status_report(sms_handle, hd_data->status_report);
    }

    if (hd_data->para_flag & SRV_SMS_PARA_REPLY_PATH)
    {
        srv_sms_set_reply_path(sms_handle, hd_data->reply_path);
    }

    if (hd_data->para_flag & SRV_SMS_PARA_STATUS)
    {
        srv_sms_set_status(sms_handle, hd_data->status);
    }

    if (hd_data->para_flag & SRV_SMS_PARA_SIM_ID)
    {
        srv_sms_set_sim_id(sms_handle, hd_data->sim_id);
    }

    if (hd_data->para_flag & SRV_SMS_PARA_TIMESTAMP)
    {
        srv_sms_set_save_timestamp(sms_handle, &(hd_data->timestamp));
    }
    
    if (hd_data->para_flag & SRV_SMS_PARA_CONTENT_EMS)
    {
        srv_sms_set_content_ems(sms_handle, hd_data->content_ems);
    }
    else if (hd_data->para_flag & SRV_SMS_PARA_CONTENT_BUFF)
    {
        srv_sms_set_content(sms_handle, hd_data->content_buff, hd_data->content_buff_size);
    }
    else if (hd_data->para_flag & SRV_SMS_PARA_CONTENT_FILE)
    {
        srv_sms_set_content_file(sms_handle, hd_data->content_file_path);
    }

    srv_sms_save_msg(sms_handle, cui_sms_save_msg_callback, (void*)cui_handle);
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_pre_save_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/
static void cui_sms_pre_save_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_save_gid;
    cui_sms_save_handle_struct *cui_handle;
    cui_sms_save_handle_data_struct *hd_data;
#ifdef __MMI_DUAL_SIM_MASTER__
    srv_sms_sim_enum msg_sim_id;
#endif /* __MMI_DUAL_SIM_MASTER__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_save_gid = cui_sms_get_active_save_gid();
    cui_handle = cui_sms_get_save_handle(sms_save_gid);
    hd_data = cui_handle->data;

    cui_sms_set_processing_screen(sms_save_gid, STR_GLOBAL_SAVING, 0);
    cui_sms_entry_processing_generic();

    if (cui_handle->is_edit_draft == MMI_TRUE)
    {
    #ifdef __MMI_DUAL_SIM_MASTER__
        msg_sim_id = srv_sms_get_msg_sim_id(cui_handle->draft_msg_id);
        if(msg_sim_id == hd_data->sim_id)
    #endif /* __MMI_DUAL_SIM_MASTER__ */
        {
            srv_sms_delete_msg(
                cui_handle->draft_msg_id,
                cui_sms_save_to_drafts_del_callback,
                (void*)cui_handle);
        }
    #ifdef __MMI_DUAL_SIM_MASTER__
        else
        {
            cui_sms_save_msg();
        }
    #endif /* __MMI_DUAL_SIM_MASTER__ */
    }
    else
    {
        cui_sms_save_msg();
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_save_to_drafts_del_callback
 * DESCRIPTION
 *  Delete the Edited Drafts's Msg Response
 * PARAMETERS
 *  data        [IN]    Dummy
 *  mod         [IN]    Module Type
 *  result      [IN]    SMS Framework Result
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_save_to_drafts_del_callback(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (callback_data->result == MMI_TRUE)
    {
        //mmi_frm_sms_set_save_highlight_handler(mmi_sms_get_save_to_drafts_msg_index);
        cui_sms_save_msg();
    }
    else
    {
        cui_sms_save_handle_struct *handle = (cui_sms_save_handle_struct*) callback_data->user_data;
        cui_evt_sms_save_popup_info_struct param;

        param.parent_gid = handle->parent_gid;
        param.save_gid = handle->save_gid;
        param.save_result = callback_data->result;
        param.cause = callback_data->cause;
        param.saved_msg_id = *(U16*)callback_data->action_data;

        cui_sms_display_popup_ext(
            STR_GLOBAL_FAILED_TO_SAVE,
            MMI_EVENT_FAILURE);

        cui_sms_save_send_evt_to_parent(&param);
    }
}


#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  cui_sms_set_send_sim_type
 * DESCRIPTION
 *  Set the SIM Type for Sending
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_sms_set_save_sim_type(srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_save_gid;
    cui_sms_save_handle_data_struct *hd_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_save_gid = cui_sms_get_active_save_gid();
    hd_data = cui_sms_get_save_handle_data(sms_save_gid);

    hd_data->para_flag |= SRV_SMS_PARA_SIM_ID;
    hd_data->sim_id = sim_id;
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_entry_save_select_sim_options
 * DESCRIPTION
 *  Entry Send SIM Card Select Options Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_entry_save_select_sim_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_gid;
    mmi_id sms_save_gid = cui_sms_get_active_save_gid();
    cui_sms_save_handle_struct *handle = cui_sms_get_save_handle(sms_save_gid); 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_cui_gid = cui_menu_create(
                        sms_save_gid,
                        CUI_MENU_SRC_TYPE_RESOURCE,
                        CUI_MENU_TYPE_OPTION,
                        MENU_ID_SMS_SAVE_TO_BOX,
                        MMI_FALSE,
                        NULL);

    cui_menu_set_default_title_by_id(menu_cui_gid, handle->title_id, IMG_SMS_ENTRY_SCRN_CAPTION);

    /* cui_menu_enable_cascading_option_menu(menu_cui_gid); */

    cui_menu_run(menu_cui_gid);
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_save_select_sim_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_save_select_sim_hdlr(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_menu_id menu_item_id = menu_evt->highlighted_menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_item_id)
    {
        case MENU_ID_SMS_SAVE_TO_BOX_OPT_BY_SIM1:
            cui_sms_save_opt_by_sim1();
            break;
    
        case MENU_ID_SMS_SAVE_TO_BOX_OPT_BY_SIM2:
            cui_sms_save_opt_by_sim2();
            break;
    
    #if (MMI_MAX_SIM_NUM >= 3)
        case MENU_ID_SMS_SAVE_TO_BOX_OPT_BY_SIM3:
            cui_sms_save_opt_by_sim3();
            break;
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        case MENU_ID_SMS_SAVE_TO_BOX_OPT_BY_SIM4:
            cui_sms_save_opt_by_sim4();
            break;            
    #endif
    
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_save_opt_by_sim1
 * DESCRIPTION
 *  Save MSG to SIM1's Drafts
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_save_opt_by_sim1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_save_gid = cui_sms_get_active_save_gid();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_sms_set_save_sim_type(SRV_SMS_SIM_1);
    cui_sms_pre_save_msg();
}


/*****************************************************************************
 * FUNCTION
 *  cui_sms_save_opt_by_sim2
 * DESCRIPTION
 *  Save MSG to SIM2's Drafts
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_save_opt_by_sim2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_save_gid = cui_sms_get_active_save_gid();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_sms_set_save_sim_type(SRV_SMS_SIM_2);
    cui_sms_pre_save_msg();
}


#if (MMI_MAX_SIM_NUM >= 3)
/*****************************************************************************
 * FUNCTION
 *  cui_sms_save_opt_by_sim3
 * DESCRIPTION
 *  Save MSG to SIM3's Drafts
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_save_opt_by_sim3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_save_gid = cui_sms_get_active_save_gid();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_sms_set_save_sim_type(SRV_SMS_SIM_3);
    cui_sms_pre_save_msg();
}
#endif


#if (MMI_MAX_SIM_NUM >= 4)
/*****************************************************************************
 * FUNCTION
 *  cui_sms_save_opt_by_sim4
 * DESCRIPTION
 *  Save MSG to SIM4's Drafts
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sms_save_opt_by_sim4(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id sms_save_gid = cui_sms_get_active_save_gid();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_sms_set_save_sim_type(SRV_SMS_SIM_4);
    cui_sms_pre_save_msg();
}
#endif


/*****************************************************************************
 * FUNCTION
 *  cui_sms_dm_pre_save_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/
static void cui_sms_dm_pre_save_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_sim1_valid;
    MMI_BOOL is_sim2_valid;
#if (MMI_MAX_SIM_NUM >= 3)    
    MMI_BOOL is_sim3_valid;
#endif        
#if (MMI_MAX_SIM_NUM >= 4)        
    MMI_BOOL is_sim4_valid;
#endif    
	U8 menuitems = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_sim1_valid = srv_nw_usab_is_usable(MMI_SIM1);
    is_sim2_valid = srv_nw_usab_is_usable(MMI_SIM2);
#if (MMI_MAX_SIM_NUM >= 3)    
    is_sim3_valid = srv_nw_usab_is_usable(MMI_SIM3);
#endif        
#if (MMI_MAX_SIM_NUM >= 4)        
    is_sim4_valid = srv_nw_usab_is_usable(MMI_SIM4);
#endif

    if (is_sim1_valid == MMI_TRUE) 
    {
    	menuitems++;
    }
    if (is_sim2_valid == MMI_TRUE)
    {
    	menuitems++;
    }
    #if (MMI_MAX_SIM_NUM >= 3)    
    if (is_sim3_valid == MMI_TRUE)
    {
    	menuitems++;
    }
    #endif        
    #if (MMI_MAX_SIM_NUM >= 4)        
    if (is_sim4_valid == MMI_TRUE)
    {
    	menuitems++;
    }
    #endif

    if (menuitems > 1)
    {
        mmi_id sms_save_gid = cui_sms_get_active_save_gid();
        cui_sms_save_handle_data_struct *hd_data = cui_sms_get_save_handle_data(sms_save_gid); 

        if (hd_data->para_flag & SRV_SMS_PARA_SIM_ID)
        {
            cui_sms_set_save_sim_type(hd_data->sim_id);
            cui_sms_pre_save_msg();
        }
        else
        {
            cui_sms_entry_save_select_sim_options();
        }
    }
    else
    {
        if (is_sim2_valid == MMI_TRUE)
        {
            cui_sms_save_opt_by_sim2();
        }
    #if (MMI_MAX_SIM_NUM >= 3)    
        else if (is_sim3_valid == MMI_TRUE)
        {
            cui_sms_save_opt_by_sim3();
        }        
    #endif        
    #if (MMI_MAX_SIM_NUM >= 4)        
        else if (is_sim4_valid == MMI_TRUE)
        {
            cui_sms_save_opt_by_sim4();
        }
    #endif
        else
        {
            cui_sms_save_opt_by_sim1();
        }
    }
}
#endif /* __MMI_DUAL_SIM_MASTER__ */


/*****************************************************************************
 * FUNCTION
 *  cui_sms_save_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_sms_save_entry(mmi_id sms_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
     cui_sms_dm_pre_save_msg();
#else
     cui_sms_pre_save_msg();
#endif
}

#endif /* __MOD_SMSAL__ */
