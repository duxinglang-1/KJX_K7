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
 *
 * Filename:
 * ---------
 *	wap_um.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for WAP UM interface.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "kal_release.h"

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       	/* Task message communiction */
#include "stack_types.h"
#include "task_config.h"

#include "msm_env.h"

#include "msf_cfg.h"
#include "msf_int.h"
#include "msf_core.h"
#include "msf_mem.h"
#include "msf_cmmn.h"

#ifdef OBIGO_Q03C_MMS_V01
#include "mms_def.h"
#include "mms_cfg.h"
#include "mms_if.h"
#include "mea_def.h"
#include "mea_if.h"
#endif


#include "wap.h"
#include "wap_ps_struct.h"
#include "Widget_extension.h"
//#include "UnifiedMessageGProt.h"
#include "UmSrvStruct.h"
#ifdef OBIGO_Q03C_MMS_V01
#ifdef __MMI_MMS_BGSR_SUPPORT__
#include "MMSBGSRGprot.h"
#include "mea_int.h"
extern void widget_execute_MMI_p(func_ptr func, void *arg, kal_bool is_blocking);
#endif // __MMI_MMS_BGSR_SUPPORT__
#endif

#ifdef __MMI_MMS_IN_UM__
#ifdef OBIGO_Q03C_MMS_V01
extern int msm_get_module_status(MSF_UINT8 modId);
extern MSF_BOOL getMmsMsgSubAddr(MSF_UINT8 modId,MmsMsgId msgId, char** subject, char** address,int MaxBufSize);
extern MeaAddrType meaGetAddrType(const char *addr);
extern char * meaLookupNameFromPHB(char *number);
extern ctk_image_id createImgList(int suffix, MSF_BOOL read, MSF_BOOL forwardLock, MmsPriority prio, MSF_BOOL isJSR, MSF_UINT32 msg_id);
extern MSF_BOOL mmcIsJSRMsg(MSF_UINT32 msgId);
extern MSF_BOOL smaIsRunning(void);
extern void wap_um_highlight_mms_message_ind(kal_uint32 msg_id, MeaFolder mea_box);
#ifdef __USB_IN_NORMAL_MODE__
extern int is_mms_storage_exported_to_pc(void);
extern kal_bool mmi_usb_is_in_mass_storage_mode(void);
extern MmsFolderType meaFolder2MmsFolder(MeaFolder folder);
extern void fldrMgrGetNumberOfMessages(MSF_UINT16 folderId, MSF_UINT16 *nMsgs, MSF_UINT16 *nUnreadMsgs);
#endif

/*************************************************************************
* FUNCTION
*	wap_translate_um_folder_2_mea_folder
* DESCRIPTION
*  This function is used to convert UM folder definition to MEA folder definition
*
* CALLS
*
* PARAMETERS
* box
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
MeaFolder wap_translate_um_folder_2_mea_folder(srv_um_msg_box_enum box)
{
    MeaFolder folder = MEA_FOLDER_NONE;
#if (defined(__MMI_MMS_IN_UM__) && defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__))
    if(box & SRV_UM_MSG_BOX_ARCHIVE)
    {
        folder |= MEA_FOLDER_ARCHIVE;
    }
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
    if(box & SRV_UM_MSG_BOX_INBOX)
    {
        folder |= MEA_FOLDER_INBOX;
    }

    if(box & SRV_UM_MSG_BOX_SENT)
    {
        folder |= MEA_FOLDER_SENT;
    }

    if(box & SRV_UM_MSG_BOX_UNSENT)
    {
        folder |= MEA_FOLDER_OUTBOX;
    }

    if(box & SRV_UM_MSG_BOX_DRAFT)
    {
        folder |= MEA_FOLDER_DRAFTS;
    }

    return folder;
}

/*************************************************************************
* FUNCTION
*	wap_translate_mea_folder_2_um_folder
* DESCRIPTION
*  This function is used to convert MEA folder definition to UM folder definition
*
* CALLS
*
* PARAMETERS
* box
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
srv_um_msg_box_enum wap_translate_mea_folder_2_um_folder(MeaFolder folder)
{
    srv_um_msg_box_enum box = 0;
#if (defined(__MMI_MMS_IN_UM__) && defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__))
    if(folder & MEA_FOLDER_ARCHIVE)
    {
        box |= SRV_UM_MSG_BOX_ARCHIVE;
    }
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
    if(folder & MEA_FOLDER_INBOX)
    {
        box |= SRV_UM_MSG_BOX_INBOX;
    }

    if(folder & MEA_FOLDER_SENT)
    {
        box |= SRV_UM_MSG_BOX_SENT;
    }

    if(folder & MEA_FOLDER_OUTBOX)
    {
        box |= SRV_UM_MSG_BOX_UNSENT;
    }

    if(folder & MEA_FOLDER_DRAFTS)
    {
        box |= SRV_UM_MSG_BOX_DRAFT;
    }

    return box;
}


/*****************************************************************************
 * FUNCTION
 *  wap_um_highlight_mms_message_ind
 * DESCRIPTION
 *  Function to send information to UM about the currently highlighted item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wap_um_highlight_mms_message_ind(kal_uint32 msg_id, MeaFolder mea_box)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    srv_um_highlight_msg_ind_struct *mms_highlight_ind_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mms_highlight_ind_p = (srv_um_highlight_msg_ind_struct *) construct_local_para((kal_uint16)sizeof(srv_um_highlight_msg_ind_struct), TD_RESET);
    mms_highlight_ind_p->msg_type = SRV_UM_MSG_MMS;
    mms_highlight_ind_p->msg_box_type = wap_translate_mea_folder_2_um_folder(mea_box);
    mms_highlight_ind_p->msg_id = msg_id;

    /* Prepare response structure */
    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->msg_id	= MSG_ID_MMI_UM_HIGHLIGHT_MSG_IND;

    /* Send Response to MMI Queue */
    ilm_ptr->local_para_ptr	= (local_para_struct *) mms_highlight_ind_p;
    ilm_ptr->peer_buff_ptr 	= NULL;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}


/*************************************************************************
* FUNCTION
*	wap_send_mmi_mms_refresh_ind
* DESCRIPTION
*  This function is used to send mms refresh signal to MMI task for refreshing UM screen
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void wap_send_mmi_mms_refresh_ind(MeaFolder folder)
{
    srv_um_msg_box_enum box = wap_translate_mea_folder_2_um_folder(folder);
    ilm_struct *ilm_ptr = NULL;
    srv_um_refresh_ind_struct *um_refresh_ind = NULL;

    if(box)
    {
        um_refresh_ind = (srv_um_refresh_ind_struct *) construct_local_para((kal_uint16)sizeof(srv_um_refresh_ind_struct), TD_RESET);
        um_refresh_ind->msg_type = SRV_UM_MSG_MMS;
        um_refresh_ind->msg_box_type = box;
    
        ilm_ptr = allocate_ilm(MOD_WAP);
        ilm_ptr->msg_id			= MSG_ID_MMI_UM_REFRESH_IND;
        ilm_ptr->local_para_ptr	= (local_para_struct *) um_refresh_ind;
        ilm_ptr->peer_buff_ptr 	= NULL;
        SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
    }
}


/*************************************************************************
* FUNCTION
*	wap_send_mmi_mms_ready_ind
* DESCRIPTION
*  This function is used to send mms ready signal to MMI task for enter unified message
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void wap_send_mmi_mms_ready_ind(void)
{
   ilm_struct *ilm_ptr = allocate_ilm(MOD_WAP);
   srv_um_ready_ind_struct *um_ready_ind = NULL;

   um_ready_ind = (srv_um_ready_ind_struct *) construct_local_para((kal_uint16)sizeof(srv_um_ready_ind_struct), TD_RESET);
   um_ready_ind->result = (kal_bool) KAL_TRUE;
   um_ready_ind->msg_type = SRV_UM_MSG_MMS;
   
   ilm_ptr->msg_id			= MSG_ID_MMI_UM_READY_IND;
   ilm_ptr->local_para_ptr	= (local_para_struct *) um_ready_ind;
   ilm_ptr->peer_buff_ptr 	= NULL;
   SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}


/*************************************************************************
* FUNCTION
*	wap_send_mmi_mms_terminate_ind
* DESCRIPTION
*  This function is used to send mms terminate signal to Unified message
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void wap_send_mmi_mms_terminate_ind(void)
{
   ilm_struct *ilm_ptr = allocate_ilm(MOD_WAP);
   srv_um_ready_ind_struct *um_ready_ind = NULL;

   um_ready_ind = (srv_um_ready_ind_struct *) construct_local_para((kal_uint16)sizeof(srv_um_ready_ind_struct), TD_RESET);
   um_ready_ind->result = (kal_bool) KAL_FALSE;
   um_ready_ind->msg_type = SRV_UM_MSG_MMS;
   
   ilm_ptr->msg_id			= MSG_ID_MMI_UM_READY_IND;
   ilm_ptr->local_para_ptr	= (local_para_struct *) um_ready_ind;
   ilm_ptr->peer_buff_ptr 	= NULL;
   SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}


/*************************************************************************
* FUNCTION
*	wap_send_mmi_mms_get_msg_num_rsp
* DESCRIPTION
*  This function is used to send mms message number signal to MMI task
*
* CALLS
*
* PARAMETERS
*  inboxUnread
*  inboxRead
*  unsent
*  sent
*  draft
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void wap_send_mmi_mms_get_msg_num_rsp(MSF_UINT16 inboxUnread, MSF_UINT16 inboxRead, MSF_UINT16 unsent, MSF_UINT16 sent, MSF_UINT16 draft
#if (defined(__MMI_MMS_IN_UM__) && defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__))
									  , MSF_UINT16 archive
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/   									  
									  )
{
   ilm_struct *ilm_ptr = allocate_ilm(MOD_WAP);
   srv_um_get_msg_num_rsp_struct *um_get_msg_num_rsp = NULL;

   um_get_msg_num_rsp = (srv_um_get_msg_num_rsp_struct *) construct_local_para((kal_uint16)sizeof(srv_um_get_msg_num_rsp_struct), TD_RESET);
   um_get_msg_num_rsp->result = KAL_TRUE;
   um_get_msg_num_rsp->msg_type = SRV_UM_MSG_MMS;
   um_get_msg_num_rsp->inbox_unread_msg_number = inboxUnread;
   um_get_msg_num_rsp->inbox_read_msg_number = inboxRead;
   um_get_msg_num_rsp->unsent_msg_number = unsent;
   um_get_msg_num_rsp->sent_msg_number = sent;
   um_get_msg_num_rsp->draft_msg_number = draft;
#if (defined(__MMI_MMS_IN_UM__) && defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__))
   um_get_msg_num_rsp->archive_msg_number = archive;
#endif /*__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/   
   ilm_ptr->msg_id			= MSG_ID_MMI_UM_GET_MSG_NUM_RSP;
   ilm_ptr->local_para_ptr	= (local_para_struct *) um_get_msg_num_rsp;
   ilm_ptr->peer_buff_ptr 	= NULL;
   SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}

/*************************************************************************
* FUNCTION
*	wap_send_mmi_mms_get_msg_list_rsp
* DESCRIPTION
*  This function is used to send mms list signal to MMI task
*
* CALLS
*
* PARAMETERS
*  result
*  folder
*  start
*  num
*  list
*  more
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void wap_send_mmi_mms_get_msg_list_rsp(MSF_BOOL result, MeaFolder folder, 
    MSF_UINT16 start, const MmsListOfProperties *list)
{

    int i = 0;
    MSF_UINT32 returnNo = 0;
    MSF_BOOL more = FALSE;
   ilm_struct *ilm_ptr = allocate_ilm(MOD_WAP);
   srv_um_get_msg_list_rsp_struct *um_get_msg_list_rsp = NULL;

   um_get_msg_list_rsp = (srv_um_get_msg_list_rsp_struct *) construct_local_para((kal_uint16)sizeof(srv_um_get_msg_list_rsp_struct), TD_RESET);
   um_get_msg_list_rsp->result = (kal_bool)result;
   um_get_msg_list_rsp->msg_type = SRV_UM_MSG_MMS;
   um_get_msg_list_rsp->msg_box_type = wap_translate_mea_folder_2_um_folder(folder);
   um_get_msg_list_rsp->start_entry = start;

    if(start + SRV_UM_MAX_GET_MSG_LIST_NUMBER < list->noOfElements)
    {
        returnNo = SRV_UM_MAX_GET_MSG_LIST_NUMBER;
        more = TRUE;
    }
    else
    {
        returnNo = list->noOfElements - start;
        more = FALSE;
    }

    memset(um_get_msg_list_rsp->list_info, 0x00, sizeof(srv_um_msg_list_struct) * SRV_UM_MAX_GET_MSG_LIST_NUMBER);
    for( i = 0; i < returnNo; i++)
    {
        um_get_msg_list_rsp->list_info[i].msg_id = (kal_uint32)(start + i);
        um_get_msg_list_rsp->list_info[i].timestamp = list->msgPropertyList[start + i].msgFolderInfo.receiveDate;
#if 0
/* under construction !*/
#endif
    }

   um_get_msg_list_rsp->msg_number = returnNo;
   um_get_msg_list_rsp->more = (kal_bool)more;
   
   ilm_ptr->msg_id			= MSG_ID_MMI_UM_GET_MSG_LIST_RSP;
   ilm_ptr->local_para_ptr	= (local_para_struct *) um_get_msg_list_rsp;
   ilm_ptr->peer_buff_ptr 	= NULL;
   SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}

/*************************************************************************
* FUNCTION
*	wap_send_mmi_mms_get_msg_info_rsp
* DESCRIPTION
*  This function is used to send mms info signal to MMI task
*
* CALLS
*
* PARAMETERS
*  result
*  folder
*  start
*  num
*  list
*  more
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void wap_send_mmi_mms_get_msg_info_rsp(MSF_BOOL result, MeaFolder folder, 
    MSF_UINT16 start, MSF_UINT16 max, const MmsListOfProperties *list)
{

    int i = 0;
    char *subject=NULL, *address=NULL;
    MSF_UINT32 returnNo = MIN(max, SRV_UM_MAX_GET_MSG_INFO_NUMBER);  /* in case */
    ilm_struct *ilm_ptr = NULL;
    srv_um_get_msg_info_rsp_struct *um_get_msg_info_rsp = NULL;
 
    um_get_msg_info_rsp = (srv_um_get_msg_info_rsp_struct *) construct_local_para((kal_uint16)sizeof(srv_um_get_msg_info_rsp_struct), TD_RESET);
    um_get_msg_info_rsp->result = (kal_bool)result;
    um_get_msg_info_rsp->msg_type = SRV_UM_MSG_MMS;
    um_get_msg_info_rsp->msg_box_type = wap_translate_mea_folder_2_um_folder(folder);
    um_get_msg_info_rsp->start_entry = start;

    returnNo = (returnNo < list->noOfElements - start)? returnNo : (list->noOfElements - start);
    memset(um_get_msg_info_rsp->msg_info, 0x00, sizeof(srv_um_msg_info_struct) * SRV_UM_MAX_GET_MSG_INFO_NUMBER);

    for( i = 0; i < returnNo; i++)
    {
        MmsMessageFolderInfo *msgInfo = &list->msgPropertyList[start + i].msgFolderInfo;
        MeaAddrType addrType = MEA_ADDR_TYPE_NONE;
        char *name = NULL;
        
        um_get_msg_info_rsp->msg_info[i].msg_id = (kal_uint32)(start + i);
        um_get_msg_info_rsp->msg_info[i].timestamp = msgInfo->receiveDate;
#if 0
/* under construction !*/
#endif
        getMmsMsgSubAddr(MSF_MODID_MEA, msgInfo->msgId, &subject, &address, 250);
        addrType = meaGetAddrType(address);
        
        /* address */
        if (MEA_ADDR_TYPE_PLMN == addrType)
        {
            um_get_msg_info_rsp->msg_info[i].address_type = SRV_UM_ADDR_PHONE_NUMBER;
            name = meaLookupNameFromPHB(address);
        }
        else if (MEA_ADDR_TYPE_EMAIL == addrType)
        {
            um_get_msg_info_rsp->msg_info[i].address_type = SRV_UM_ADDR_EMAIL_ADDRESS;
        }

        if(name != NULL)
        {
            um_get_msg_info_rsp->msg_info[i].address_length = strlen(name);
            widget_utf8_to_ucs2_string((kal_uint8 *)um_get_msg_info_rsp->msg_info[i].address, (SRV_UM_MAX_ADDR_LEN + 1) * sizeof(kal_wchar), (const kal_uint8 *)name);
            MSF_MEM_FREE(MSF_MODID_MEA, name);
        }
        else if(address != NULL)
        {
            um_get_msg_info_rsp->msg_info[i].address_length = strlen(address);
            widget_utf8_to_ucs2_string((kal_uint8 *)um_get_msg_info_rsp->msg_info[i].address, (SRV_UM_MAX_ADDR_LEN + 1) * sizeof(kal_wchar), (const kal_uint8 *)address);
        }
        MSF_MEM_FREE(MSF_MODID_MEA, address);

        /* subject */
        if(subject != NULL)
        {
            widget_utf8_to_ucs2_string((kal_uint8 *)um_get_msg_info_rsp->msg_info[i].subject, (SRV_UM_MAX_SUBJECT_LEN + 1) * sizeof(kal_wchar), (const kal_uint8 *)subject);
            um_get_msg_info_rsp->msg_info[i].subject_length = widget_ucs2_length((kal_uint8 *)um_get_msg_info_rsp->msg_info[i].subject);
            MSF_MEM_FREE(MSF_MODID_MEA, subject);
        }
        else if(msgInfo->suffix == MMS_SUFFIX_DELIVERYREPORT)
        {
            char *drSubject = (char *)HDIa_widgetExtStringGetPredefinedUCS2buffer(MEA_STR_ID_DELIV_REPORT);
            um_get_msg_info_rsp->msg_info[i].subject_length = widget_ucs2_length((kal_uint8 *)drSubject);
            widget_ucs2_strncpy((kal_uint8 *)um_get_msg_info_rsp->msg_info[i].subject, (kal_uint8 *)drSubject, (SRV_UM_MAX_SUBJECT_LEN + 1) * sizeof(kal_wchar));
        }
        else if(msgInfo->suffix == MMS_SUFFIX_READREPORT)
        {
            char *rrSubject = (char *)HDIa_widgetExtStringGetPredefinedUCS2buffer(MEA_STR_ID_READ_REPORT);
            um_get_msg_info_rsp->msg_info[i].subject_length = widget_ucs2_length((kal_uint8 *)rrSubject);
            widget_ucs2_strncpy((kal_uint8 *)um_get_msg_info_rsp->msg_info[i].subject, (kal_uint8 *)rrSubject, (SRV_UM_MAX_SUBJECT_LEN + 1) * sizeof(kal_wchar));
        }
        
        /* icon */
        um_get_msg_info_rsp->msg_info[i].icon_id = createImgList(msgInfo->suffix, msgInfo->read, msgInfo->forwardLock, msgInfo->priority, mmcIsJSRMsg(msgInfo->msgId), msgInfo->msgId);
    }

   um_get_msg_info_rsp->msg_number = returnNo;

   ilm_ptr = allocate_ilm(MOD_WAP);  /* meaLookupNameFromPHB would allocate ilm, so we do it here */
   ilm_ptr->msg_id			= MSG_ID_MMI_UM_GET_MSG_INFO_RSP;
   ilm_ptr->local_para_ptr	= (local_para_struct *) um_get_msg_info_rsp;
   ilm_ptr->peer_buff_ptr 	= NULL;
   SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);

}


/*************************************************************************
* FUNCTION
*	wap_send_mmi_mms_delete_folder_rsp
* DESCRIPTION
*  This function is used to send delete folder signal to MMI task
*
* CALLS
*
* PARAMETERS
* result
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void wap_send_mmi_mms_delete_folder_rsp(MSF_BOOL result)
{
   ilm_struct *ilm_ptr = allocate_ilm(MOD_WAP);
   srv_um_delete_folder_rsp_struct *um_delete_folder_rsp = NULL;

   um_delete_folder_rsp = (srv_um_delete_folder_rsp_struct *) construct_local_para((kal_uint16)sizeof(srv_um_delete_folder_rsp_struct), TD_RESET);
   um_delete_folder_rsp->msg_type = SRV_UM_MSG_MMS;
   um_delete_folder_rsp->result = (kal_bool)result;
   
   ilm_ptr->msg_id			= MSG_ID_MMI_UM_DELETE_FOLDER_RSP;
   ilm_ptr->local_para_ptr	= (local_para_struct *) um_delete_folder_rsp;
   ilm_ptr->peer_buff_ptr 	= NULL;
   SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}

/*************************************************************************
* FUNCTION
*	wap_send_mmi_mms_new_msg_ind
* DESCRIPTION
*  This function is used to send new mms arrival signal to MMI task for informing user
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void wap_send_mmi_mms_new_msg_ind(kal_uint32 timestamp)
{
   ilm_struct *ilm_ptr = allocate_ilm(MOD_WAP);
   srv_um_new_msg_ind_struct *um_new_msg_ind = NULL;

   um_new_msg_ind = (srv_um_new_msg_ind_struct *) construct_local_para((kal_uint16)sizeof(srv_um_new_msg_ind_struct), TD_RESET);
   um_new_msg_ind->msg_type = SRV_UM_MSG_MMS;
   um_new_msg_ind->msg_box_type = SRV_UM_MSG_BOX_INBOX;
   um_new_msg_ind->msg_id = 0;
   um_new_msg_ind->timestamp = timestamp;
   
   ilm_ptr->msg_id			= MSG_ID_MMI_UM_NEW_MSG_IND;
   ilm_ptr->local_para_ptr	= (local_para_struct *) um_new_msg_ind;
   ilm_ptr->peer_buff_ptr 	= NULL;
   SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}

/*************************************************************************
* FUNCTION
*	wap_send_mmi_mms_delete_all_ind
* DESCRIPTION
*  This function is used to send new mms arrival signal to MMI task for informing user
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void wap_send_mmi_mms_delete_all_ind(MeaFolder folder)
{
   ilm_struct *ilm_ptr = allocate_ilm(MOD_WAP);
   srv_um_delete_all_ind_struct *um_delete_all_ind = NULL;

   um_delete_all_ind = (srv_um_delete_all_ind_struct *) construct_local_para((kal_uint16)sizeof(srv_um_delete_all_ind_struct), TD_RESET);
   um_delete_all_ind->msg_type = SRV_UM_MSG_MMS;
   um_delete_all_ind->msg_box_type = wap_translate_mea_folder_2_um_folder(folder);
   
   ilm_ptr->msg_id			= MSG_ID_MMI_UM_DELETE_ALL_IND;
   ilm_ptr->local_para_ptr	= (local_para_struct *) um_delete_all_ind;
   ilm_ptr->peer_buff_ptr 	= NULL;
   SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}

/*************************************************************************
* FUNCTION
*	wap_um_mms_msg_hdlr
* DESCRIPTION
*  This function is used to handle signal passed from UM to WAP for MMS
*
* CALLS
*
* PARAMETERS
* ilm_ptr
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
int wap_um_mms_msg_hdlr(ilm_struct *ilm_ptr)
{
    if(msm_get_module_status (MSF_MODID_MEA) != MODULE_STATUS_ACTIVE)
    {
        MSMc_startModule(MSF_MODID_MEA, NULL);
        return 0;
    }
    	
    switch(ilm_ptr->msg_id)
    {
        case MSG_ID_MMI_UM_GET_MSG_NUM_REQ:
        {
            MEAif_getMessageNumber(MSF_MODID_MSM);
            break;
        }

        case MSG_ID_MMI_UM_GET_MSG_LIST_REQ:
        {
            srv_um_get_msg_list_req_struct *local_data = (srv_um_get_msg_list_req_struct *) ilm_ptr->local_para_ptr;
            MeaFolder folder = wap_translate_um_folder_2_mea_folder(local_data->msg_box_type);
            if(folder != MEA_FOLDER_NONE)
            {
                MEAif_getMessageList(MSF_MODID_MSM, folder, local_data->start_entry);
            }
            break;
        }

        case MSG_ID_MMI_UM_GET_MSG_INFO_REQ:
        {
            srv_um_get_msg_info_req_struct *local_data = (srv_um_get_msg_info_req_struct *) ilm_ptr->local_para_ptr;
            MeaFolder folder = wap_translate_um_folder_2_mea_folder(local_data->msg_box_type);
            if(folder != MEA_FOLDER_NONE)
            {
                MEAif_getMessageInfo(MSF_MODID_MSM, folder, local_data->start_entry, local_data->msg_number);
            }
            break;
        }

        case MSG_ID_MMI_UM_DELETE_FOLDER_REQ:
        {
            srv_um_delete_folder_req_struct *local_data = (srv_um_delete_folder_req_struct *) ilm_ptr->local_para_ptr;
            MeaFolder folder = wap_translate_um_folder_2_mea_folder(local_data->msg_box_type);
#ifdef __USB_IN_NORMAL_MODE__
            if(mmi_usb_is_in_mass_storage_mode() && is_mms_storage_exported_to_pc())
            {
                MSF_UINT16 unread_no = 0, total_no = 0;
                MmsFolderType m_folder = meaFolder2MmsFolder(folder);
                fldrMgrGetNumberOfMessages(m_folder, &total_no, &unread_no);
                if (total_no == 0)
                {
                    wap_send_mmi_mms_delete_folder_rsp(TRUE);
                }
                else
                {
                    wap_send_mmi_mms_delete_folder_rsp(FALSE);
                }
            }
            else
#endif
            {
#ifdef __MMI_MMS_BGSR_SUPPORT__
				//  handling deleting all folders
				mmi_mms_bgsr_msg_struct *data;
				data = MSF_MEM_ALLOCTYPE(MSF_MODID_WIDGET, mmi_mms_bgsr_msg_struct);
                memset((S8*)data, 0, sizeof(mmi_mms_bgsr_msg_struct));

				if (local_data->msg_box_type & SRV_UM_MSG_BOX_UNSENT &&
					local_data->msg_box_type & SRV_UM_MSG_BOX_INBOX)
				{
					data->op = MMI_MMS_BGSR_OP_DELETE_ALL_INBOX_OUTBOX;	 
					widget_execute_MMI_p(MEAa_chagneMessageBGSRNotify, data, FALSE);
				}

				else if (local_data->msg_box_type & SRV_UM_MSG_BOX_INBOX)
				{
					data->op = MMI_MMS_BGSR_OP_DELETE_ALL_INBOX;
					widget_execute_MMI_p(MEAa_chagneMessageBGSRNotify, data, FALSE);
				}

				else if (local_data->msg_box_type & SRV_UM_MSG_BOX_UNSENT)
				{
				    data->op = MMI_MMS_BGSR_OP_DELETE_ALL_OUTBOX;
					widget_execute_MMI_p(MEAa_chagneMessageBGSRNotify, data, FALSE);
				}
#endif				

                if(folder != MEA_FOLDER_NONE)
                {
                    MEAif_deleteFolder(MSF_MODID_MSM, folder);
                }
            }
            break;
        }

        case MSG_ID_MMI_UM_DELETE_ALL_RES:
        {
            break;
        }
        
        default:
            return 0;
			break;
    }
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_send_highlight_decided_by_um_ind
 * DESCRIPTION
 *  send highlight need to change ind to UM when msg is deleted after sent
 * PARAMETERS
 *  msg_box_type        [IN]	UM box type
 *  msg_index			[IN]	the deleted msg index after sent 
 * RETURNS
 *  void
 *****************************************************************************/
void wap_um_send_highlight_decided_by_um_ind(MeaFolder mea_box, U16 msg_index)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    srv_um_highlight_decided_by_UM_struct *mms_highlight_ind_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mms_highlight_ind_p = (srv_um_highlight_decided_by_UM_struct *) 
    construct_local_para((kal_uint16)sizeof(srv_um_highlight_msg_ind_struct), TD_RESET);
    mms_highlight_ind_p->msg_type = SRV_UM_MSG_MMS;
    mms_highlight_ind_p->msg_box_type = wap_translate_mea_folder_2_um_folder(mea_box);
    mms_highlight_ind_p->msg_id = (kal_uint32)msg_index;

    /* Prepare response structure */
    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->msg_id	= MSG_ID_MMI_UM_HIGHLIGHT_DECIDED_BY_UM_IND;

    /* Send Response to MMI Queue */
    ilm_ptr->local_para_ptr	= (local_para_struct *) mms_highlight_ind_p;
    ilm_ptr->peer_buff_ptr 	= NULL;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}

#endif

/*************************************************************************
* FUNCTION
*	wap_um_msg_hdlr
* DESCRIPTION
*  This function is used to handle signal passed from UM to WAP
*
* CALLS
*
* PARAMETERS
* ilm_ptr
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
int wap_um_msg_hdlr(ilm_struct *ilm_ptr)
{
#ifdef OBIGO_Q03C_MMS_V01
    srv_um_generic_req_struct *p = NULL;
#endif

    if(ilm_ptr != NULL && ilm_ptr->local_para_ptr != NULL)
    {
#ifdef OBIGO_Q03C_MMS_V01
        p = (srv_um_generic_req_struct*)(ilm_ptr->local_para_ptr);

        if(p->msg_type == SRV_UM_MSG_MMS)
        {
            return wap_um_mms_msg_hdlr(ilm_ptr); 
        }
#endif
    }
    return 0;
}

#endif
