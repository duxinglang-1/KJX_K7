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
*  vapp_cal_at_entry.cpp
*
* Project:
* --------
*  Venus
*
* Description:
* ------------
*  exercise
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/


#include "mmi_features.h"
#ifdef __MMI_VCALENDAR__
extern "C"
{
    #include "mmi_msg_struct.h"
    #include "mmi_frm_queue_gprot.h"
    #include "generalsettingsrvgprot.h"	

#ifdef __SYNCML_SUPPORT__   
    #include "vapp_sync_gprot.h"
#endif
}

#include "FileMgrSrvGprot.h"
#include "mmi_rp_vapp_calendar_def.h"

#include "vfx_cpp_base.h"
#include "vcp_global_popup.h"

#include "vapp_cal_prot.h"
#include "vapp_cal_view_detail_ext.h"
#include "vapp_cal_at_entry.h"


static void mmi_tdl_at_req_ind(void* info);
static void mmi_tdl_at_res_req(U8 mode, BOOL result,U8 index, U8 number, U8 *file_path);
static U16 mmi_tdl_at_get_sorted_index(U16 search_item, srv_tdl_event_task_struct *sorted_list, U16 total, U16 vcal_type);
static void mmi_at_get_default_filename(S8 *result);


/*****************************************************************************
* FUNCTION
*  vapp_cal_at_data_handler_init
* DESCRIPTION
*   This function initializes todolist handler for at command.
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void vapp_cal_at_data_handler_init(void)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_tdl_at_req_ind, MSG_ID_MMI_EQ_VCALENDAR_REQ_IND);
}


/*****************************************************************************
* FUNCTION
*  mmi_tdl_at_req_ind
* DESCRIPTION
*   This function handle AT command to request todolist record.
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
static void mmi_tdl_at_req_ind(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_vcalendar_req_ind_struct* LocalPtr;
    U8 file_path[TDL_FOR_AT_MAX_FILE_PATH_LEN];
    U16 recordindex, delete_result;
    S16 i;
    srv_tdl_event_task_struct sorted_list[VAPP_TDL_MAX_COUNT];
    U16 total;
    S32 vclndr_error_code;

    srv_vcal_parse_struct *handle;
    void *pobject, *pdata = NULL;
    srv_vcal_type_enum vcal_type;
    U8 flag_finish;
    U16 list_size;
    U8 m_storeIndex;
    S32 m_result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    LocalPtr = (mmi_eq_vcalendar_req_ind_struct*)info;

    m_storeIndex = VAPP_TDL_MAX_COUNT;
    list_size = 0;

#ifdef __SYNCML_SUPPORT__   	
    if (vapp_sync_is_cal_synchronizing(0) || vapp_sync_is_task_synchronizing(0))
    {
        return;
    }    
#endif       

    mmi_chset_enum encode_type = (mmi_chset_enum)0;
#ifdef __MMI_SET_DEF_ENCODING_TYPE__    
    encode_type = srv_setting_get_encoding_type();
#endif

    switch (LocalPtr->mode)
    {
        /*ADD*/
        case MMI_TDL_AT_ADD:
        {
            /* file path check */
            if (LocalPtr->file_path == NULL)
            {
                m_result = MMI_FALSE;
                break;
            }

            handle = (srv_vcal_parse_struct *)srv_vcal_parse_begin((U16*)LocalPtr->file_path, encode_type);

            S32 parseresult ;
            parseresult = srv_vcal_parse(handle, &pobject, (srv_vcal_type_enum*)&vcal_type, &flag_finish);
            if (parseresult != SRV_VCAL_RESULT_SUCCESS)
            {
                srv_vcal_parse_free_object(handle, pobject);
                srv_vcal_parse_end(handle);
                m_result = MMI_FALSE;
                break;
            }

            if (vcal_type == SRV_VCAL_VEVENT)
            {
                VFX_SYS_ALLOC_MEM(pdata, sizeof(srv_tdl_event_struct));
                VFX_ASSERT(pdata);
                memcpy(pdata, pobject, sizeof(srv_tdl_event_struct));
                list_size = VAPP_CAL_MAX_COUNT;
            }
            else if (vcal_type == SRV_VCAL_VTODO)
            {
                VFX_SYS_ALLOC_MEM(pdata, sizeof(srv_tdl_task_struct));
                VFX_ASSERT(pdata);
                memcpy(pdata, pobject, sizeof(srv_tdl_task_struct));
                list_size = VAPP_TASK_MAX_COUNT;
            }
            else
            {        
                srv_vcal_parse_free_object(handle, pobject);
                srv_vcal_parse_end(handle);
                m_result = MMI_FALSE;
                break;
            }

            srv_vcal_parse_free_object(handle, pobject);
            srv_vcal_parse_end(handle);

            VappCalViewDetailFromExtPage::adjustDataValidation(pdata, (srv_tdl_vcal_enum)vcal_type);

            S32 addresult ;
            addresult = srv_tdl_add(pdata, (srv_tdl_vcal_enum)vcal_type, &recordindex);
            if(addresult != SRV_VCAL_RESULT_SUCCESS)
            {
                VFX_FREE_MEM(pdata);
                m_result = MMI_FALSE;
                break;
            }

            srv_tdl_get_all_index(sorted_list, list_size, (srv_tdl_vcal_enum)vcal_type, &total);
            srv_tdl_sort(sorted_list, total, SRV_TDL_SORT_TYPE_ENTRY_TIME);
             
            /* sort task and get index*/
            i = mmi_tdl_at_get_sorted_index(recordindex, sorted_list, total, vcal_type);
            if (i == 0xFFFF)
            {
                m_result = MMI_FALSE;
            }                 
            else
            {
                LocalPtr->index = i;
                m_storeIndex = sorted_list[i].index;
            }

            VFX_FREE_MEM(pdata);
            break;
        }
             
        /*UPDATE*/
        case MMI_TDL_AT_UPDATE:
        {
            handle = (srv_vcal_parse_struct *)srv_vcal_parse_begin((U16*)LocalPtr->file_path, encode_type);

            S32 parseResult;
            parseResult = srv_vcal_parse(handle, &pobject, (srv_vcal_type_enum*)&vcal_type, &flag_finish);
            if (parseResult != SRV_VCAL_RESULT_SUCCESS)
            {
            srv_vcal_parse_free_object(handle, pobject);
            srv_vcal_parse_end(handle);
            m_result = MMI_FALSE;
            break;
            }

            if (vcal_type == SRV_VCAL_VEVENT)
            {
                VFX_SYS_ALLOC_MEM(pdata, sizeof(srv_tdl_event_struct));
                VFX_ASSERT(pdata);

                S32 getResult;
                getResult = srv_tdl_get(
                pdata, 
                sizeof(srv_tdl_event_struct), 
                SRV_TDL_VCAL_EVENT,
                LocalPtr->index);
                if((getResult != SRV_TDL_RESULT_OK)||(((srv_tdl_event_struct*)pdata)->present != 1))
                {
                    VFX_FREE_MEM(pdata);
                    m_result = MMI_FALSE;
                    break;
                }

                memcpy(pdata, pobject, sizeof(srv_tdl_event_struct));
                list_size = VAPP_CAL_MAX_COUNT;
            }
            else if (vcal_type == SRV_VCAL_VTODO)
            {
                VFX_SYS_ALLOC_MEM(pdata, sizeof(srv_tdl_task_struct));
                VFX_ASSERT(pdata);

                S32 getResult;
                getResult = srv_tdl_get(
                pdata, 
                sizeof(srv_tdl_task_struct), 
                SRV_TDL_VCAL_TASK,
                LocalPtr->index);

                if((getResult != SRV_TDL_RESULT_OK)||(((srv_tdl_event_struct*)pdata)->present != 1))
                {
                    VFX_FREE_MEM(pdata);
                    m_result = MMI_FALSE;
                    break;
                }

                memcpy(pdata, pobject, sizeof(srv_tdl_task_struct));
                list_size = VAPP_TASK_MAX_COUNT;
            }
            else
            {        
                srv_vcal_parse_free_object(handle, pobject);
                srv_vcal_parse_end(handle);
                m_result = MMI_FALSE;
                break;
            }

            srv_vcal_parse_free_object(handle, pobject);
            srv_vcal_parse_end(handle);

            VappCalViewDetailFromExtPage::adjustDataValidation(pdata, (srv_tdl_vcal_enum)vcal_type);

            //srv_tdl_get_all_index(sorted_list, list_size, (srv_tdl_vcal_enum)vcal_type, &total);
            //srv_tdl_sort(sorted_list, total, SRV_TDL_SORT_TYPE_ENTRY_TIME);

            if(vcal_type == SRV_VCAL_VEVENT)
            {
                srv_tdl_update(
                            pdata, 
                            SRV_TDL_VCAL_EVENT, 
                            LocalPtr->index);
            }
            else if(SRV_VCAL_VTODO == vcal_type)
            {
                srv_tdl_update(
                            pdata, 
                            SRV_TDL_VCAL_TASK, 
                            LocalPtr->index);

            }


            VFX_FREE_MEM(pdata);

            break;
        }
             
        /*DELETE*/
        case MMI_TDL_AT_DELETE:
        {
            if (LocalPtr->vcal_type == SRV_VCAL_VEVENT)
            {
                VFX_SYS_ALLOC_MEM(pdata, sizeof(srv_tdl_event_struct));
                VFX_ASSERT(pdata);

                S32 getResult;
                getResult = srv_tdl_get(
                                    pdata, 
                                    sizeof(srv_tdl_event_struct), 
                                    SRV_TDL_VCAL_EVENT,
                                    LocalPtr->index);
                if((getResult != SRV_TDL_RESULT_OK)||(((srv_tdl_event_struct*)pdata)->present != 1))
                {
                    VFX_FREE_MEM(pdata);
                    m_result = MMI_FALSE;
                    break;
                }

                list_size = VAPP_CAL_MAX_COUNT;
            }
            else if (LocalPtr->vcal_type == SRV_VCAL_VTODO)
            {
                VFX_SYS_ALLOC_MEM(pdata, sizeof(srv_tdl_task_struct));
                VFX_ASSERT(pdata);

                S32 getResult;
                getResult = srv_tdl_get(
                                    pdata, 
                                    sizeof(srv_tdl_task_struct), 
                                    SRV_TDL_VCAL_TASK,
                                    LocalPtr->index);

                if((getResult != SRV_TDL_RESULT_OK)||(((srv_tdl_event_struct*)pdata)->present != 1))
                {
                    VFX_FREE_MEM(pdata);
                    m_result = MMI_FALSE;
                    break;
                }

                list_size = VAPP_TASK_MAX_COUNT;
            }
            else
            {
            // srv_vcal_parse_free_object(handle, pobject);
            //srv_vcal_parse_end(handle);
                m_result = MMI_FALSE;
                break;
            }

            delete_result = srv_tdl_delete(
                                        LocalPtr->index, 
                                        (srv_tdl_vcal_enum)LocalPtr->vcal_type);

            /* delete fail */
            if (delete_result != SRV_TDL_RESULT_OK)
            {
                VFX_FREE_MEM(pdata);
                m_result = MMI_FALSE;
                break;
            }                       
            VFX_FREE_MEM(pdata);
            break;
             
        }
             
        /*READ*/
        case MMI_TDL_AT_READ:
        {
            if (SRV_TDL_VCAL_EVENT == LocalPtr->vcal_type)
            {
                VFX_SYS_ALLOC_MEM(pdata, sizeof(srv_tdl_event_struct));
                VFX_ASSERT(pdata);

                S32 getResult;

                getResult = srv_tdl_get(
                                    pdata, 
                                    sizeof(srv_tdl_event_struct), 
                                    SRV_TDL_VCAL_EVENT,
                                    LocalPtr->index);
                if((getResult != SRV_TDL_RESULT_OK)||(((srv_tdl_event_struct*)pdata)->present != 1))
                {
                    VFX_FREE_MEM(pdata);
                    m_result = MMI_FALSE;
                    break;
                }
                list_size = VAPP_CAL_MAX_COUNT;
            }
            else
            {
                VFX_SYS_ALLOC_MEM(pdata, sizeof(srv_tdl_task_struct));
                VFX_ASSERT(pdata);

                S32 getResult;
                getResult = srv_tdl_get(
                                    pdata, 
                                    sizeof(srv_tdl_task_struct), 
                                    SRV_TDL_VCAL_TASK,
                                    LocalPtr->index);
                if ((getResult != SRV_TDL_RESULT_OK)||(((srv_tdl_task_struct*)pdata)->present != 1))
                {
                    VFX_FREE_MEM(pdata);
                    m_result = MMI_FALSE;
                    break;
                }
                list_size = VAPP_TASK_MAX_COUNT;

            }
            srv_vcal_build_struct *handle;

            memset(file_path, 0, TDL_FOR_AT_MAX_FILE_PATH_LEN);
            mmi_at_get_default_filename((S8*)file_path);

            handle = (srv_vcal_build_struct *)srv_vcal_build_begin((U16*)file_path, SRV_VCAL_VER_VCAL_1_0);
            vclndr_error_code = srv_vcal_build_add(handle, pdata, (srv_vcal_type_enum)LocalPtr->vcal_type);            

            srv_vcal_build_end(handle);

            VFX_FREE_MEM(pdata);
            if (vclndr_error_code != SRV_VCAL_RESULT_SUCCESS)
            {
                m_result = MMI_FALSE;
                break;
            }
            m_storeIndex = LocalPtr->index;

            break;
        }
         /*QUERY*/
         case MMI_TDL_AT_QUERY:
            srv_tdl_get_all_index(NULL, 0, (srv_tdl_vcal_enum)LocalPtr->vcal_type, &list_size);
            m_result = MMI_TRUE;
            break;
         
         /* vCalendar is support? */
         case MMI_TDL_AT_SUPPORT:
            LocalPtr->mode = MMI_TRUE;
            m_result = MMI_TRUE;
            break;
         
    }
 
    mmi_tdl_at_res_req(LocalPtr->mode, m_result, m_storeIndex,(U8)list_size, file_path);
}


/*****************************************************************************
* FUNCTION
*  mmi_tdl_at_res_req
* DESCRIPTION
*   This function return result to AT command
*
* PARAMETERS
*  
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
void mmi_tdl_at_res_req(U8 mode, BOOL result,U8 index, U8 number, U8 *file_path)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   mmi_eq_vcalendar_res_req_struct *MsgPtr;
   
   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/

   MsgPtr = (mmi_eq_vcalendar_res_req_struct*) OslConstructDataPtr(sizeof(mmi_eq_vcalendar_res_req_struct));
   MsgPtr->mode = mode;
   MsgPtr->result = (kal_bool)result;
   MsgPtr->index = index;
    if (MsgPtr->mode == MMI_TDL_AT_QUERY)
    {
        MsgPtr->total = NUM_OF_TDL;
        MsgPtr->used= number;
    }
    else if (MsgPtr->mode == MMI_TDL_AT_READ)
    {
        memcpy(MsgPtr->file_path, file_path, TDL_FOR_AT_MAX_FILE_PATH_LEN);
    }
 
   mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_EQ_VCALENDAR_RES_REQ, (oslParaType *)MsgPtr, NULL);

}



/*****************************************************************************
* FUNCTION
*  mmi_tdl_at_get_sorted_index
* DESCRIPTION
*   This function get tdl info by index
*
* PARAMETERS
*  void
* RETURNS
*  handle index, -1 means no matched record
* GLOBALS AFFECTED
*   none
*****************************************************************************/
static U16 mmi_tdl_at_get_sorted_index(U16 search_item, srv_tdl_event_task_struct *sorted_list, U16 total, U16 vcal_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tdl_event_short_struct *pevent = NULL;
    srv_tdl_task_short_struct *ptask = NULL;
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if (vcal_type == SRV_TDL_VCAL_EVENT)
    {
        srv_tdl_get_cache(
            (void**)&pevent, 
            sizeof(srv_tdl_event_short_struct), 
            SRV_TDL_VCAL_EVENT,
            search_item);

        for (i = 0; i < total; i++)
        {
            if (sorted_list[i].index == search_item) 
            {
                return i;
            }
        }        
    }
    else
    {
        srv_tdl_get_cache(
            (void**)&ptask, 
            sizeof(srv_tdl_task_short_struct), 
            SRV_TDL_VCAL_TASK,
            search_item);
    
        for (i = 0; i < total ; i++)
        {
            if (sorted_list[i].index == search_item) 
            {
                return i;
            }
        }       
    }
    return 0xFFFF;
}


/*****************************************************************************
* FUNCTION
*  mmi_at_get_default_filename
* DESCRIPTION
*   This function handle AT command to request todolist record.
*
* PARAMETERS
*  void
* RETURNS
*  void
* GLOBALS AFFECTED
*   none
*****************************************************************************/
static void mmi_at_get_default_filename(S8 *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *ascii_path;
    S32 retval;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_SYS_ALLOC_MEM(ascii_path, (SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH);

    sprintf(
            ascii_path, 
            "%c:\\%s", 
            MMI_TDL_PIM_DRV, 
            MMI_TDL_PIM_FILE_PATH);

    mmi_asc_to_ucs2(result, ascii_path);

    retval = FS_GetAttributes((const WCHAR *)result);
    if (retval == FS_PATH_NOT_FOUND || retval == FS_FILE_NOT_FOUND)
    {
        retval = FS_CreateDir((const WCHAR *)result);
    }
    
    sprintf(
            ascii_path, 
            "%c:\\%s\\%s", 
            MMI_TDL_PIM_DRV, 
            MMI_TDL_PIM_FILE_PATH, 
            MMI_TDL_PIM_DEFAULT_FILE_NAME_FOR_AT);

    mmi_asc_to_ucs2(result, ascii_path);

    VFX_FREE_MEM(ascii_path);
}
#endif

