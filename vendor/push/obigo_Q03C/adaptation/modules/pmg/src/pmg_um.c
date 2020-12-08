/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   pmg_um.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains functions for UM AP request handling
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *==============================================================================
 *******************************************************************************/
#include "msf_cfg.h"
//#include "msf_core.h"
#include "msf_int.h"
#include "msf_mem.h"
//#include "msf_dcvt.h"
#include "msf_log.h"
//#include "msf_pipe.h"
//#include "msf_file.h"
//#include "msf_chrs.h"
//#include "msf_errc.h"

//#include "kal_release.h"
//#include "stack_common.h"
#include "stack_msgs.h"
//#include "stack_types.h"
#include "app_ltlcom.h"     /* Task message communiction */
//#include "task_config.h"    /* Task creation */

#include "Conversions.h"
#include "MMI_features.h"
//#include "app_datetime.h"
#include "app_usedetails.h"
#include "app_url.h"

//#include "GlobalDefs.h"
//#include "WAPPushResDef.h"
//#include "BrowserResDef.h"
#include "pmg_main.h"
#include "pmg_env.h"
#include "pmg_if.h"
#include "pmg_inbox.h"
//#include "UMGprot.h"
//#include "phs_msg.h"
#include "phs_cfg.h"

//suggested add
    #include "stack_config.h"
    #include "MMIDataType.h"
    #include "kal_general_types.h"
    #include "msf_def.h"
    #include "pmg_msg.h"
    #include "UmSrvStruct.h"
    #include "string.h"
    #include "UmSrvDefs.h"
    #include "pmg_struct.h"
    #include "kal_public_api.h"
    #include "customer_email_num.h"

  #ifndef __COSMOS_MMI_PACKAGE__
    #include "mmi_rp_app_mmi_wap_push_def.h"
#endif /*__COSMOS_MMI_PACKAGE__*/

    #include "GlobalResDef.h"
    #include "kal_trace.h"
    #include "wps_trc.h"
extern void pmg_send_primitive(module_type destmod, msg_type msgid, void *local_param, void *peer_buff);
extern S32 mmi_ucs2strlen(const char *arrOut);

#ifdef __MMI_PUSH_IN_UM__
static void pmg_um_send_um_ready_ind(kal_bool result);
#endif /* __MMI_PUSH_IN_UM__ */


#ifdef WPS_PMG_CONVERSATION_BOX
static MSF_UINT8 pmg_um_check_msg_id_to_traverse_msg_id (int msg_id);
#define MAX_TRAVERSE_MSG_NUMBER		5
extern kal_int32 msg_id_with_num [MAX_TRAVERSE_MSG_NUMBER + 1] = {-1};
#endif /* WPS_PMG_CONVERSATION_BOX */


/*****************************************************************************
 * FUNCTION
 *  pmg_um_init
 * DESCRIPTION
 *  initialise PMG's UM interface component
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_um_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_PUSH_IN_UM__
    pmg_um_send_um_ready_ind(KAL_TRUE);
#endif /* __MMI_PUSH_IN_UM__ */

    pmg_init_done(PMG_INIT_UM);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_um_terminate
 * DESCRIPTION
 *  Terminate PMG's UM interface component
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_um_terminate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_PUSH_IN_UM__
    pmg_um_send_um_ready_ind(KAL_FALSE);
#endif /* __MMI_PUSH_IN_UM__ */ 
}


#ifdef __MMI_PUSH_IN_UM__
/*****************************************************************************
 * FUNCTION
 *  pmg_um_convert_msglist_elem_to_umlistinfo_elem
 * DESCRIPTION
 *  convert PMG message list element to UM's list info element in local parameter
 *  [pre] destination buffer must aleady be set to 0
 * PARAMETERS
 *  msg_elem        [?]     
 *  lp_elem         [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void pmg_um_convert_msglist_elem_to_umlistinfo_elem(pmg_msg_elem_t *msg_elem, srv_um_msg_list_struct *lp_elem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_elem->created)
        lp_elem->timestamp = (kal_uint32)msg_elem->created;
    lp_elem->msg_id = (kal_uint16) (msg_elem->msgID);

	/* fill sim id attribute */
#if(MMI_MAX_SIM_NUM >= 2)
   if(msg_elem->sim_id == WAP_PMG_SIM1)
   {
        lp_elem->sim_id = SRV_UM_SIM_GSM_SIM1;
   }
   else if(msg_elem->sim_id == WAP_PMG_SIM2)
   {
        lp_elem->sim_id = SRV_UM_SIM_GSM_SIM2;
   }
 #if (MMI_MAX_SIM_NUM >= 3)
	 else if(msg_elem->sim_id == WAP_PMG_SIM3)
   {
      lp_elem->sim_id = SRV_UM_SIM_GSM_SIM3;
   }
 #endif /*MMI_MAX_SIM_NUM >= 3)*/
 #if (MMI_MAX_SIM_NUM >= 4)
	 else if(msg_elem->sim_id == WAP_PMG_SIM4)
   {
        lp_elem->sim_id = SRV_UM_SIM_GSM_SIM4;
   }
 #endif /*MMI_MAX_SIM_NUM >= 4)*/

   else
       ASSERT(0);
#endif /* (MMI_MAX_SIM_NUM >= 2) */
}


#ifdef WPS_PMG_CONVERSATION_BOX

/*****************************************************************************
 * FUNCTION
 *  pmg_um_convert_msglist_elem_to_um_traverselist_elem
 * DESCRIPTION
 *  convert PMG message list element to UM's traverse list info element 
 * PARAMETERS
 *  msg_elem        [?]         
 * RETURNS
 *  srv_um_msg_detail_struct*
 *****************************************************************************/
srv_um_msg_detail_struct* pmg_um_convert_msglist_elem_to_um_traverselist_elem(pmg_msg_elem_t *msg_elem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_um_msg_detail_struct *um_msg_details;
	kal_wchar *fromaddr = 0;
	int len = -1;
	int i = 0;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    um_msg_details = pmg_mem_alloc (sizeof(srv_um_msg_detail_struct));
    memset (um_msg_details, 0, sizeof(srv_um_msg_detail_struct));

    if (msg_elem->created)
        um_msg_details->timestamp = (kal_uint32)msg_elem->created;

    um_msg_details->msg_id = (kal_uint16) (msg_elem->msgID);
    um_msg_details->msg_type = SRV_UM_MSG_WAP_PUSH;
    um_msg_details->msg_size = (kal_uint32) msg_elem->blockSize;
    um_msg_details->msg_box_type = SRV_UM_MSG_BOX_INBOX;
    um_msg_details->read_status  = (kal_bool) msg_elem->read;
    um_msg_details->msg_status  = msg_elem->priority;

/* fill sim id attribute */
#if(MMI_MAX_SIM_NUM >= 2)
   if(msg_elem->sim_id == WAP_PMG_SIM1)
   {
        um_msg_details->sim_id = SRV_UM_SIM_GSM_SIM1;
   }
   else if(msg_elem->sim_id == WAP_PMG_SIM2)
   {
        um_msg_details->sim_id = SRV_UM_SIM_GSM_SIM2;
   }
 #if (MMI_MAX_SIM_NUM >= 3)
	 else if(msg_elem->sim_id == WAP_PMG_SIM3)
   {
        um_msg_details->sim_id = SRV_UM_SIM_GSM_SIM3;
   }
 #endif /*MMI_MAX_SIM_NUM >= 3)*/
 #if (MMI_MAX_SIM_NUM >= 4)
	 else if(msg_elem->sim_id == WAP_PMG_SIM4)
   {
        um_msg_details->sim_id = SRV_UM_SIM_GSM_SIM4;
   }
 #endif /*MMI_MAX_SIM_NUM >= 4)*/

   else
       ASSERT(0);
#endif /* (MMI_MAX_SIM_NUM >= 2) */

	
	/* fill subject attribute */
	um_msg_details->subject = pmg_mem_alloc((SRV_UM_MAX_SUBJECT_LEN + 1) * sizeof(kal_wchar));
	memset (um_msg_details->subject, 0, (SRV_UM_MAX_SUBJECT_LEN + 1) * sizeof(kal_wchar));
	if (msg_elem->partialText)
    {
        mmi_chset_utf8_to_ucs2_string(
              (kal_uint8*) (um_msg_details->subject),
              (kal_int32) (SRV_UM_MAX_SUBJECT_LEN + 1) * sizeof(kal_wchar),
              (kal_uint8*) (msg_elem->partialText));
    }
#ifndef __MMI_BRW_DISABLE_PUSH_URL_DISPLAY__
        else if (msg_elem->partialHref)
        {
            mmi_chset_utf8_to_ucs2_string(
                (kal_uint8*) (um_msg_details->subject),
                (kal_int32) (SRV_UM_MAX_SUBJECT_LEN + 1) * sizeof(kal_wchar),
                (kal_uint8*) (msg_elem->partialHref));
        }
#endif
	
	/* fill from address and its sub attributes */
	um_msg_details->address.addr = pmg_mem_alloc ((SRV_UM_MAX_ADDR_LEN + 1) * sizeof(kal_wchar));
	memset (um_msg_details->address.addr, 0, (SRV_UM_MAX_ADDR_LEN + 1) * sizeof(kal_wchar));
	if (msg_elem->from)
    {
        if (applib_is_valid_number((kal_uint8*)msg_elem->from))
        {
            um_msg_details->address.type = SRV_UM_ADDR_PHONE_NUMBER;
        }
        else if (applib_url_check_ip((char*)msg_elem->from, strlen(msg_elem->from)))
        {
            um_msg_details->address.type = SRV_UM_ADDR_IP_ADDRESS;
        }
        else
        {
            um_msg_details->address.type = SRV_UM_ADDR_PLAIN_TEXT;
        }

        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8*) (um_msg_details->address.addr),
            (kal_int32) (SRV_UM_MAX_ADDR_LEN + 1) * sizeof(kal_wchar),
            (kal_uint8*) (msg_elem->from));
	}
	um_msg_details->address.next = NULL;
    um_msg_details->address.previous = NULL;	
    um_msg_details->address.group = SRV_UM_ADDR_GROUP_FROM;	
    
	return um_msg_details;
}

#endif /* WPS_PMG_CONVERSATION_BOX */


#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
/*****************************************************************************
 * FUNCTION
 *  pmg_um_convert_msglist_elem_to_umlistindex_elem
 * DESCRIPTION
 *  convert PMG message list element to UM's list index element in local parameter
 *  [pre] destination buffer must aleady be set to 0
 * PARAMETERS
 *  msg_elem        [?]     
 *  lp_elem         [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void pmg_um_convert_msglist_elem_to_umlistindex_elem(srv_um_list_idx_enum type, 
                                                            pmg_msg_elem_t *msg_elem, 
                                                            srv_um_list_idx_data_union *li_elem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
    case SRV_UM_LIST_IDX_MSG_SIZE:
        li_elem->msg_size = msg_elem->blockSize;
        break;
    case SRV_UM_LIST_IDX_MSG_TYPE:
        li_elem->msg_type = SRV_UM_MSG_WAP_PUSH;
        break;
    case SRV_UM_LIST_IDX_SUBJECT:
        if (msg_elem->partialText)
        {
            mmi_chset_utf8_to_ucs2_string(
                (kal_uint8*) (li_elem->subject),
                (kal_int32) (SRV_UM_MAX_LIST_INDEX_LEN + 1) * sizeof(kal_wchar),
                (kal_uint8*) (msg_elem->partialText));
        }
#ifndef __MMI_BRW_DISABLE_PUSH_URL_DISPLAY__
        else if (msg_elem->partialHref)
        {
            mmi_chset_utf8_to_ucs2_string(
                (kal_uint8*) (li_elem->subject),
                (kal_int32) (SRV_UM_MAX_LIST_INDEX_LEN + 1) * sizeof(kal_wchar),
                (kal_uint8*) (msg_elem->partialHref));
        }
#endif
        break;
    case SRV_UM_LIST_IDX_ADDRESS:
        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8*) (li_elem->address),
            (kal_int32) (SRV_UM_MAX_LIST_INDEX_LEN + 1) * sizeof(kal_wchar),
            (kal_uint8*) (msg_elem->from));
        break;
    case SRV_UM_LIST_IDX_READ_STATUS:
        li_elem->read_status = msg_elem->read;
        break;
    default:
        break;
    }
}
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */


/*****************************************************************************
 * FUNCTION
 *  pmg_um_convert_msglist_elem_to_ummsginfo_elem
 * DESCRIPTION
 *  convert PMG message list element to UM's msg info element in local parameter
 * PARAMETERS
 *  msg_elem        [?]     
 *  lp_elem         [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void pmg_um_convert_msglist_elem_to_ummsginfo_elem(pmg_msg_elem_t *msg_elem, srv_um_msg_info_struct *lp_elem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int len;
    MSF_UINT32 crtTime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lp_elem->msg_id = (kal_uint16) (msg_elem->msgID);
    if (msg_elem->created)
        lp_elem->timestamp = (kal_uint32)msg_elem->created;
    lp_elem->address_length = 0;

    lp_elem->icon_id = (kal_uint16) 0;
    crtTime = pmg_get_current_sys_utc_time();



#if(MMI_MAX_SIM_NUM == 2)

	if (msg_elem->sim_id == WAP_PMG_SIM1)
	{
		if (msg_elem->read)
		{
			if (msg_elem->expired && (msg_elem->expired < crtTime))
			{
				#ifndef __COSMOS_MMI_PACKAGE__
				lp_elem->icon_id = (kal_uint16) IMG_ID_BRW_PUSH_EXPIRED_READ;			
				#else
				lp_elem->icon_id = (kal_uint16) IMG_GLOBAL_OK;
				#endif /*__COSMOS_MMI_PACKAGE__*/
			}
			else
			{
			#ifndef __COSMOS_MMI_PACKAGE__	
				lp_elem->icon_id = (kal_uint16) IMG_ID_BRW_PUSH_READ;				
			#else
				lp_elem->icon_id = (kal_uint16) IMG_GLOBAL_OK;
			#endif /*__COSMOS_MMI_PACKAGE__*/
			
			}
		}
		else
		{
			if (msg_elem->expired && (msg_elem->expired < crtTime))
			{
				#ifndef __COSMOS_MMI_PACKAGE__	
				lp_elem->icon_id = (kal_uint16) IMG_ID_BRW_PUSH_EXPIRED_UNREAD;
			#else
				lp_elem->icon_id = (kal_uint16) IMG_GLOBAL_OK;
			#endif /*__COSMOS_MMI_PACKAGE__*/
			}
			else
			{
				#ifndef __COSMOS_MMI_PACKAGE__				
				lp_elem->icon_id = (kal_uint16) IMG_ID_BRW_PUSH_UNREAD;
			#else
				lp_elem->icon_id = (kal_uint16) IMG_GLOBAL_OK;
			#endif /*__COSMOS_MMI_PACKAGE__*/
			
			}
		}		
		lp_elem->sim_id = SRV_UM_SIM_GSM_SIM1;
	}
	else if (msg_elem->sim_id == WAP_PMG_SIM2)
	{
		if (msg_elem->read)
		{
			if (msg_elem->expired && (msg_elem->expired < crtTime))
			{
				#ifndef __COSMOS_MMI_PACKAGE__
				lp_elem->icon_id = (kal_uint16) IMG_ID_BRW_PUSH_EXPIRED_READ;
				#else
				lp_elem->icon_id = (kal_uint16) IMG_GLOBAL_OK;
			#endif /*__COSMOS_MMI_PACKAGE__*/
			}
			else
			{
			#ifndef __COSMOS_MMI_PACKAGE__				
				lp_elem->icon_id = (kal_uint16) IMG_ID_BRW_PUSH_READ;
			#else
				lp_elem->icon_id = (kal_uint16) IMG_GLOBAL_OK;
			#endif /*__COSMOS_MMI_PACKAGE__*/	

			}
		}
		else
		{
			if (msg_elem->expired && (msg_elem->expired < crtTime))
		{
				#ifndef __COSMOS_MMI_PACKAGE__
				lp_elem->icon_id = (kal_uint16) IMG_ID_BRW_PUSH_EXPIRED_UNREAD;
				#else
				lp_elem->icon_id = (kal_uint16) IMG_GLOBAL_OK;
			        #endif /*__COSMOS_MMI_PACKAGE__*/
			}
			else
			{
				#ifndef __COSMOS_MMI_PACKAGE__
				lp_elem->icon_id = (kal_uint16) IMG_ID_BRW_PUSH_UNREAD;
			        #else
				lp_elem->icon_id = (kal_uint16) IMG_GLOBAL_OK;
			        #endif /*__COSMOS_MMI_PACKAGE__*/
			}
		}		
	lp_elem->sim_id = SRV_UM_SIM_GSM_SIM2;
			}
	else
	{
		ASSERT(0);
	}
	
#else 
    if (msg_elem->read)
    {
        if (msg_elem->expired && (msg_elem->expired < crtTime))
        {
           #ifndef __COSMOS_MMI_PACKAGE__
            lp_elem->icon_id = (kal_uint16) IMG_ID_BRW_PUSH_EXPIRED_READ;
            /* lp_elem->icon_id = (kal_uint16)WAP_IMAGE_SW_PUSH_EREAD; */
           #else
             lp_elem->icon_id = (kal_uint16) IMG_GLOBAL_OK;        

			#endif/*__COSMOS_MMI_PACKAGE__*/
         }      
        else
        {
           #ifndef __COSMOS_MMI_PACKAGE__
            lp_elem->icon_id = (kal_uint16) IMG_ID_BRW_PUSH_READ;
            /* lp_elem->icon_id = (kal_uint16)WAP_IMAGE_SW_PUSH_READ; */
           #else
             lp_elem->icon_id = (kal_uint16) IMG_GLOBAL_OK;        
			 #endif/*__COSMOS_MMI_PACKAGE__*/
        
        }
    }
    else
    {
        if (msg_elem->expired && (msg_elem->expired < crtTime))
        {
           #ifndef __COSMOS_MMI_PACKAGE__
            lp_elem->icon_id = (kal_uint16) IMG_ID_BRW_PUSH_EXPIRED_UNREAD;
            /* lp_elem->icon_id = (kal_uint16)WAP_IMAGE_SW_PUSH_EUREAD; */
           #else
             lp_elem->icon_id = (kal_uint16) IMG_GLOBAL_OK;   
	#endif/*__COSMOS_MMI_PACKAGE__*/
        }
        else
        {
           #ifndef __COSMOS_MMI_PACKAGE__
            lp_elem->icon_id = (kal_uint16) IMG_ID_BRW_PUSH_UNREAD;
            /* lp_elem->icon_id = (kal_uint16)WAP_IMAGE_SW_PUSH_UREAD; */
           #else
             lp_elem->icon_id = (kal_uint16) IMG_GLOBAL_OK;   
			
	#endif/*__COSMOS_MMI_PACKAGE__*/
        }
    }
#endif /*(MMI_MAX_SIM_NUM == 2)*/
			
#if(MMI_MAX_SIM_NUM >= 3)
	
if (msg_elem->sim_id == WAP_PMG_SIM1)

{
	lp_elem->sim_id = SRV_UM_SIM_GSM_SIM1;
}

else if (msg_elem->sim_id == WAP_PMG_SIM2)
{
	lp_elem->sim_id = SRV_UM_SIM_GSM_SIM2;
}

else if (msg_elem->sim_id == WAP_PMG_SIM3) 
    {
	lp_elem->sim_id = SRV_UM_SIM_GSM_SIM3;
         }      
        
#if (MMI_MAX_SIM_NUM >= 4)

else if (msg_elem->sim_id == WAP_PMG_SIM4)
    {
	lp_elem->sim_id = SRV_UM_SIM_GSM_SIM4;
        }
#endif /*(MMI_MAX_SIM_NUM >= 4)*/

	else
	{
		ASSERT(0);
	}


    if (msg_elem->read)
    {
        if (msg_elem->expired && (msg_elem->expired < crtTime))
        {
 			#ifndef __COSMOS_MMI_PACKAGE__          
            lp_elem->icon_id = (kal_uint16) IMG_ID_BRW_PUSH_EXPIRED_READ;
            /* lp_elem->icon_id = (kal_uint16)WAP_IMAGE_SW_PUSH_EREAD; */
 			#else
				lp_elem->icon_id = (kal_uint16) IMG_GLOBAL_OK;
			#endif /*__COSMOS_MMI_PACKAGE__*/       
        }
        else
        {
     #ifndef __COSMOS_MMI_PACKAGE__         
            lp_elem->icon_id = (kal_uint16) IMG_ID_BRW_PUSH_READ;
            /* lp_elem->icon_id = (kal_uint16)WAP_IMAGE_SW_PUSH_READ; */
    #else
				lp_elem->icon_id = (kal_uint16) IMG_GLOBAL_OK;
			#endif /*__COSMOS_MMI_PACKAGE__*/    
       
        }
    }
    else
    {
        if (msg_elem->expired && (msg_elem->expired < crtTime))
        {
           #ifndef __COSMOS_MMI_PACKAGE__          
            lp_elem->icon_id = (kal_uint16) IMG_ID_BRW_PUSH_EXPIRED_UNREAD;
            /* lp_elem->icon_id = (kal_uint16)WAP_IMAGE_SW_PUSH_EUREAD; */
           #else
	    lp_elem->icon_id = (kal_uint16) IMG_GLOBAL_OK;
	   #endif /*__COSMOS_MMI_PACKAGE__*/         
        }
        else
        {
           #ifndef __COSMOS_MMI_PACKAGE__      
            lp_elem->icon_id = (kal_uint16) IMG_ID_BRW_PUSH_UNREAD;
            /* lp_elem->icon_id = (kal_uint16)WAP_IMAGE_SW_PUSH_UREAD; */
           #else
	    lp_elem->icon_id = (kal_uint16) IMG_GLOBAL_OK;
	   #endif /*__COSMOS_MMI_PACKAGE__*/     
        }
    }


#endif /*(MMI_MAX_SIM_NUM >= 3)*/

    if (msg_elem->from)
    {
        if (applib_is_valid_number((kal_uint8*)msg_elem->from))
        {
            lp_elem->address_type = SRV_UM_ADDR_PHONE_NUMBER;
        }
        else if (applib_url_check_ip((char*)msg_elem->from, strlen(msg_elem->from)))
        {
            lp_elem->address_type = SRV_UM_ADDR_IP_ADDRESS;
        }
        else
        {
            lp_elem->address_type = SRV_UM_ADDR_PLAIN_TEXT;
        }

        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8*) (lp_elem->address),
            (kal_int32) (SRV_UM_MAX_ADDR_LEN + 1) * sizeof(kal_wchar),
            (kal_uint8*) (msg_elem->from));
        lp_elem->address_length = (kal_uint8) mmi_ucs2strlen((const char*)(lp_elem->address));
    }

    len = 0;
    if (msg_elem->partialText)
    {
        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8*) (lp_elem->subject),
            (kal_int32) (SRV_UM_MAX_SUBJECT_LEN + 1) * sizeof(kal_wchar),
            (kal_uint8*) (msg_elem->partialText));
        len = strlen((const char*)(msg_elem->partialText));
    }
#ifndef __MMI_BRW_DISABLE_PUSH_URL_DISPLAY__
    else if (msg_elem->partialHref)
    {
        mmi_chset_utf8_to_ucs2_string(
            (kal_uint8*) (lp_elem->subject),
            (kal_int32) (SRV_UM_MAX_SUBJECT_LEN + 1) * sizeof(kal_wchar),
            (kal_uint8*) (msg_elem->partialHref));
        len = strlen((const char*)(msg_elem->partialHref));
    }
#endif
    lp_elem->subject_length = (len > SRV_UM_MAX_SUBJECT_LEN ? SRV_UM_MAX_SUBJECT_LEN : len);
    lp_elem->csk_icon_id = IMG_GLOBAL_COMMON_CSK;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_um_convert_multi_op_action_types
 * DESCRIPTION
 *  convert PMG message list element to UM's list info element in local parameter
 *  [pre] destination buffer must aleady be set to 0
 * PARAMETERS
 *  dire            [IN]        1: UM->PMG, 0:PMG->UM
 *  umAction        [IN/OUT]     
 *  pmgAction       [IN/OUT]     
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_um_multi_op_action_to_pmg(MSF_UINT8 dire, void *umAction, MSF_UINT8 *pmgAction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_mark_several_op_action_enum *pUmAct = (srv_um_mark_several_op_action_enum*)umAction;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dire)
    {
        switch (*pUmAct)
        {
            case SRV_UM_MARK_SEVERAL_OP_ACTION_DELETE:
                *pmgAction = PMG_UM_MULTI_OP_DELETE;
                break;

          //  case SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_ARCHIVE:
          //      *pmgAction = PMG_UM_MULTI_OP_MOVE_TO_ARCHIVE;
          //      break;

            default:
                break;
        }
    }
    else
    {
        switch (*pmgAction)
        {
            case PMG_UM_MULTI_OP_DELETE:
                *pUmAct = SRV_UM_MARK_SEVERAL_OP_ACTION_DELETE;
                break;

          //  case PMG_UM_MULTI_OP_MOVE_TO_ARCHIVE:
          //      *pUmAct = SRV_UM_MARK_SEVERAL_OP_ACTION_DELETE;
           //     break;

            default:
                break;
        }
    }
}

#ifdef __MMI_PUSH_IN_UM__
/*****************************************************************************
 * FUNCTION
 *  pmg_um_send_um_ready_ind
 * DESCRIPTION
 *  send MSG_ID_MMI_UM_READY_IND to UM
 * PARAMETERS
 *  result    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void pmg_um_send_um_ready_ind(kal_bool result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_ready_ind_struct *local_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param =
        (srv_um_ready_ind_struct*) construct_local_para((kal_uint16) sizeof(srv_um_ready_ind_struct), TD_RESET);
    local_param->result = result;
    local_param->msg_type = SRV_UM_MSG_WAP_PUSH;

    pmg_send_primitive(MOD_MMI, MSG_ID_MMI_UM_READY_IND, (void*)local_param, (void*)0);
}
#endif/*__MMI_PUSH_IN_UM__*/

/*****************************************************************************
 * FUNCTION
 *  pmg_um_send_um_refresh_ind
 * DESCRIPTION
 *  send MSG_ID_MMI_UM_REFRESH_IND to UM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_um_send_um_refresh_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_refresh_ind_struct *local_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param =
        (srv_um_refresh_ind_struct*) construct_local_para((kal_uint16) sizeof(srv_um_refresh_ind_struct), TD_RESET);
    local_param->msg_type = SRV_UM_MSG_WAP_PUSH;
    local_param->msg_box_type = SRV_UM_MSG_BOX_INBOX;

    pmg_send_primitive(MOD_MMI, MSG_ID_MMI_UM_REFRESH_IND, (void*)local_param, (void*)0);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_um_handle_get_msg_num_req
 * DESCRIPTION
 *  handle MSG_ID_MMI_UM_GET_MSG_NUM_REQ from UM
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_um_handle_get_msg_num_req(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_um_get_msg_num_req_t *data = (pmg_um_get_msg_num_req_t*) p;
    srv_um_get_msg_num_rsp_struct *local_param;
    int msgCount_read = 0;
    int msgCount_unread = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/* for dual sim */
#if(MMI_MAX_SIM_NUM >= 2)	
    msgCount_unread = pmg_msg_count_messages(data->msgType, PMG_PARAM_NO, PMG_PARAM_NOT_SPECIFIED, PMG_PARAM_NOT_SPECIFIED, WAP_PMG_SIM1);
    msgCount_unread += pmg_msg_count_messages(data->msgType, PMG_PARAM_NO, PMG_PARAM_NOT_SPECIFIED, PMG_PARAM_NOT_SPECIFIED, WAP_PMG_SIM2);

 #if (MMI_MAX_SIM_NUM >= 3)
	msgCount_unread += pmg_msg_count_messages(data->msgType, PMG_PARAM_NO, PMG_PARAM_NOT_SPECIFIED, PMG_PARAM_NOT_SPECIFIED, WAP_PMG_SIM3);
 #endif /*(MMI_MAX_SIM_NUM >= 3)*/
 #if (MMI_MAX_SIM_NUM >= 4)
	msgCount_unread += pmg_msg_count_messages(data->msgType, PMG_PARAM_NO, PMG_PARAM_NOT_SPECIFIED, PMG_PARAM_NOT_SPECIFIED, WAP_PMG_SIM4); 
 #endif /*(MMI_MAX_SIM_NUM >= 4)*/

    msgCount_read = pmg_msg_count_messages(data->msgType, PMG_PARAM_YES, PMG_PARAM_NOT_SPECIFIED, PMG_PARAM_NOT_SPECIFIED,  WAP_PMG_SIM1);
    msgCount_read += pmg_msg_count_messages(data->msgType, PMG_PARAM_YES, PMG_PARAM_NOT_SPECIFIED, PMG_PARAM_NOT_SPECIFIED,  WAP_PMG_SIM2);

 #if (MMI_MAX_SIM_NUM >= 3)
	msgCount_read += pmg_msg_count_messages(data->msgType, PMG_PARAM_YES, PMG_PARAM_NOT_SPECIFIED, PMG_PARAM_NOT_SPECIFIED, WAP_PMG_SIM3);
 #endif /*(MMI_MAX_SIM_NUM >= 3)*/
 #if (MMI_MAX_SIM_NUM >= 4)
	msgCount_read += pmg_msg_count_messages(data->msgType, PMG_PARAM_YES, PMG_PARAM_NOT_SPECIFIED, PMG_PARAM_NOT_SPECIFIED, WAP_PMG_SIM4); 
#endif /*(MMI_MAX_SIM_NUM >= 4)*/


#else
    msgCount_unread = pmg_msg_count_messages(data->msgType, PMG_PARAM_NO, PMG_PARAM_NOT_SPECIFIED, PMG_PARAM_NOT_SPECIFIED, WAP_PMG_SIM_DEFAULT);
    msgCount_read = pmg_msg_count_messages(data->msgType, PMG_PARAM_YES, PMG_PARAM_NOT_SPECIFIED, PMG_PARAM_NOT_SPECIFIED,  WAP_PMG_SIM_DEFAULT);
#endif /*(MMI_MAX_SIM_NUM >= 2)	*/
    local_param =
        (srv_um_get_msg_num_rsp_struct*) construct_local_para(
                                            (kal_uint16) sizeof(srv_um_get_msg_num_rsp_struct),
                                            TD_RESET);
    local_param->result = KAL_TRUE;
    local_param->msg_type = SRV_UM_MSG_WAP_PUSH;
    local_param->inbox_unread_msg_number = (kal_uint16) msgCount_unread;
    local_param->inbox_read_msg_number = (kal_uint16) msgCount_read;
    local_param->unsent_msg_number = 0;
    local_param->sent_msg_number = 0;
    local_param->draft_msg_number = 0;

    pmg_send_primitive(MOD_MMI, MSG_ID_MMI_UM_GET_MSG_NUM_RSP, (void*)local_param, (void*)0);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_um_handle_get_list_req
 * DESCRIPTION
 *  handle MSG_ID_MMI_UM_GET_MSG_LIST_REQ from UM
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_um_handle_get_list_req(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_um_get_list_req_t *data = (pmg_um_get_list_req_t*)p;
    srv_um_get_msg_list_rsp_struct *local_param;
    pmg_msg_list_t *msg_list;
    pmg_msg_elem_t *msg_elem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_list = pmg_msg_retrieve_list(
                data->msgType,
                PMG_PARAM_NOT_SPECIFIED,            /* isRead */
                PMG_PARAM_NOT_SPECIFIED,            /* isExpired */
                PMG_PARAM_NOT_SPECIFIED,            /* hasInfo */
                data->startFrom,
                0,                                  /* sizeToRetrieve */
                SRV_UM_MAX_GET_MSG_LIST_NUMBER,     /* maxAllowableSize */
				data->sim_id		);    

					  


    local_param =
        (srv_um_get_msg_list_rsp_struct*) construct_local_para((kal_uint16) sizeof(srv_um_get_msg_list_rsp_struct), TD_RESET);
    local_param->result = KAL_TRUE;
    local_param->msg_type = SRV_UM_MSG_WAP_PUSH;
    local_param->msg_box_type = SRV_UM_MSG_BOX_INBOX;
    local_param->start_entry = (kal_uint16) data->startFrom;
    local_param->more = (msg_list->remain_size ? KAL_TRUE : KAL_FALSE);

    if (!(msg_list->size))
        local_param->msg_number = 0;
    else
    {
        int i;

        local_param->msg_number = (kal_uint16) msg_list->size;
        memset(local_param->list_info, 0, sizeof(srv_um_msg_list_struct) * SRV_UM_MAX_GET_MSG_LIST_NUMBER);

        i = 0;
        msg_elem = msg_list->head;
        while (msg_elem)
        {
            ASSERT(i < SRV_UM_MAX_GET_MSG_LIST_NUMBER);
            pmg_um_convert_msglist_elem_to_umlistinfo_elem(msg_elem, local_param->list_info + i);
#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
            pmg_um_convert_msglist_elem_to_umlistindex_elem((srv_um_list_idx_enum) data->idxType, 
                                                            msg_elem, 
                                                            local_param->list_idx_data + i);
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */
            i++;
            msg_elem = msg_elem->next;
        }
    }

    pmg_msg_release_list(msg_list);
    pmg_send_primitive(MOD_MMI, MSG_ID_MMI_UM_GET_MSG_LIST_RSP, (void*)local_param, (void*)0);
}


#ifdef WPS_PMG_CONVERSATION_BOX


/*****************************************************************************
 * FUNCTION
 *  pmg_um_handle_get_traverse_list_req
 * DESCRIPTION
 *  handle MSG_ID_MMI_UM_TRAVERSE_MSG_REQ from UM
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_um_handle_get_traverse_list_req(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_um_get_traverse_list_req_t *data = (pmg_um_get_traverse_list_req_t*)p;
    srv_um_traverse_msg_rsp_struct *local_param;
    srv_um_msg_detail_struct	*um_msg_details;
    pmg_msg_list_t *msg_list;
    pmg_msg_elem_t *msg_elem;
    srv_um_traverse_func traverse_func = (srv_um_traverse_func) data->traverse_func;
    int i = 0, found = 0, set = 0;
	kal_int32 result = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data->startFrom >= 0)
	{
    msg_list = pmg_msg_retrieve_list(
                data->msgType,
                PMG_PARAM_NOT_SPECIFIED,            /* isRead */
                PMG_PARAM_NOT_SPECIFIED,            /* isExpired */
                PMG_PARAM_NOT_SPECIFIED,            /* hasInfo */
                data->startFrom,
                0,                                  /* sizeToRetrieve */
                SRV_UM_MAX_GET_MSG_LIST_NUMBER,		/* maxAllowableSize */
				data->sim_id);    
	}
	else
	{
		msg_list = pmg_msg_retrieve_list(
                data->msgType,
                PMG_PARAM_NOT_SPECIFIED,            /* isRead */
                PMG_PARAM_NOT_SPECIFIED,            /* isExpired */
                PMG_PARAM_NOT_SPECIFIED,            /* hasInfo */
                0,									/* data->startFrom = 0*/
                0,                                  /* sizeToRetrieve */
                SRV_UM_MAX_GET_MSG_LIST_NUMBER,		/* maxAllowableSize */
				data->sim_id   );    
	}
    /* response to UM */
    local_param =
        (srv_um_traverse_msg_rsp_struct*) construct_local_para((kal_uint16) sizeof(srv_um_traverse_msg_rsp_struct), TD_RESET);
    local_param->msg_type = SRV_UM_MSG_WAP_PUSH;
    local_param->app_id = data->app_id;
    local_param->msg_number = 0;
	local_param->more = KAL_FALSE;
	local_param->result = KAL_TRUE;

    msg_elem = msg_list->head;
    while (msg_elem)
    {
		if (data->startFrom < 0)
		{
			found = pmg_um_check_msg_id_to_traverse_msg_id (msg_elem->msgID);
			if (found)
			{
        /* Fill the srv_um_msg_detail_struct with message element detail */
		um_msg_details = pmg_um_convert_msglist_elem_to_um_traverselist_elem(msg_elem);
        /* API OF UM WILL BE CALLED HERE */
				result = (kal_int32) traverse_func (data->pid, um_msg_details);
				if (result == SRV_UM_RESULT_OK)
					set = 1;
			}
			else
			{
				set = 0;
				goto free;
			}
		}
		else
		{
			/* Fill the srv_um_msg_detail_struct with message element detail */
		    um_msg_details = pmg_um_convert_msglist_elem_to_um_traverselist_elem(msg_elem);
			result = (kal_int32) traverse_func (data->pid, um_msg_details);
		}
		MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_UM_TRAVERSE_LIST_RESULT,
                    "PMG: result : %d\n", result));
		
		/* Free the allocated memory in pmg_um_convert_msglist_elem_to_um_traverselist_elem API*/
		memset (um_msg_details->subject, 0, (SRV_UM_MAX_SUBJECT_LEN + 1) * sizeof(kal_wchar));
		PMG_MEM_FREE (um_msg_details->subject);

		memset (um_msg_details->address.addr, 0, (SRV_UM_MAX_ADDR_LEN + 1) * sizeof(kal_wchar));
		PMG_MEM_FREE (um_msg_details->address.addr);
		
		memset (um_msg_details, 0, sizeof(srv_um_msg_detail_struct));	
		PMG_MEM_FREE (um_msg_details);

free:				
        i++;
		msg_elem = msg_elem->next; 
		
		if (result == SRV_UM_RESULT_OK)
		{
			local_param->more = KAL_FALSE;
			local_param->result = KAL_TRUE;
			if (data->startFrom < 0)
	                {	
                                if (set)
				{
					local_param->msg_number++;
				}	
			}
			else
					local_param->msg_number++;
			continue;
		}
		else if (result == SRV_UM_RESULT_BUFFER_FULL)
		{
			local_param->more = KAL_TRUE;
			local_param->result = KAL_TRUE;
			break;
		}
		else if (result == SRV_UM_RESULT_CANCELLLED)
		{
			local_param->more = KAL_FALSE;
			local_param->result = KAL_FALSE;
			break;
		}
		else
		{
			ASSERT(0);
		}
		if (data->startFrom < 0 && result == SRV_UM_RESULT_OK)
		{
			if (local_param->msg_number == (kal_uint16) msg_id_with_num[0])
			{
				break;
			}
		}
    }
	/* As if start_entry is less then 0 then msg_number should be 
	equal to the requested one*/
	if (data->startFrom < 0 && result == SRV_UM_RESULT_OK)
	{
		if (local_param->msg_number != (kal_uint16) msg_id_with_num[0])
		{
			ASSERT(0);
		}
	}
	
    pmg_msg_release_list(msg_list);
    /* response to UM */
	pmg_send_primitive(MOD_MMI, MSG_ID_MMI_UM_TRAVERSE_MSG_RSP, (void*)local_param, (void*)0);
	
}

#endif /* WPS_PMG_CONVERSATION_BOX */


/*****************************************************************************
 * FUNCTION
 *  pmg_um_handle_get_msg_info_req
 * DESCRIPTION
 *  handle MSG_ID_MMI_UM_GET_MSG_INFO_REQ from UM
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_um_handle_get_msg_info_req(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_um_get_msg_info_req_t *data = (pmg_um_get_msg_info_req_t*)p;
    srv_um_get_msg_info_rsp_struct *local_param;
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_param =
        (srv_um_get_msg_info_rsp_struct*) construct_local_para(
                                            (kal_uint16) sizeof(srv_um_get_msg_info_rsp_struct),
                                            TD_RESET);
    local_param->msg_type = SRV_UM_MSG_WAP_PUSH;
    local_param->msg_box_type = SRV_UM_MSG_BOX_INBOX;
    local_param->msg_number = data->msgNumber;
    memcpy(local_param->msg_id, data->msgIDs, data->msgNumber * sizeof(kal_uint32));

    for (i = 0; i < data->msgNumber; i++)
    {
        pmg_msg_elem_t *msg_elem = pmg_msg_find_elem_by_id(data->msgIDs[i]);
        if (msg_elem)
        {
            local_param->result[i] = KAL_TRUE;
            pmg_um_convert_msglist_elem_to_ummsginfo_elem(msg_elem, local_param->msg_info + i);
        }
        else
        {
            local_param->result[i] = KAL_FALSE;
        }
    }

    pmg_send_primitive(MOD_MMI, MSG_ID_MMI_UM_GET_MSG_INFO_RSP, (void*)local_param, (void*)0);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_um_handle_delete_folder_req
 * DESCRIPTION
 *  handle MSG_ID_MMI_UM_DELETE_FOLDER_REQ from UM
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_um_handle_delete_folder_req(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_um_delete_folder_req_t *data = (pmg_um_delete_folder_req_t*) p;
    srv_um_delete_folder_rsp_struct *local_param;
    wps_pmg_delete_folder_ind_struct *lp_inbox;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pmg_msg_delete_all_messages(data->msgType);

    /* send delete folder response to UM */
    local_param = (srv_um_delete_folder_rsp_struct*)
                    construct_local_para(
                        (kal_uint16) sizeof(srv_um_delete_folder_rsp_struct),
                        TD_RESET);
    local_param->result = KAL_TRUE;
    local_param->msg_type = SRV_UM_MSG_WAP_PUSH;

    pmg_send_primitive(MOD_MMI, MSG_ID_MMI_UM_DELETE_FOLDER_RSP, (void*)local_param, (void*)0);


    /* send delete folder indication to Push Inbox */
    lp_inbox = (wps_pmg_delete_folder_ind_struct*)
                    construct_local_para(
                        (kal_uint16) sizeof(wps_pmg_delete_folder_ind_struct),
                        TD_RESET);
    lp_inbox->folder = WAP_PMG_FOLDER_INBOX;
    pmg_send_primitive(MOD_MMI, MSG_ID_WPS_PMG_DELETE_FOLDER_IND, (void*)lp_inbox, (void*)0);
}


#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  pmg_um_handle_multi_op_req
 * DESCRIPTION
 *  handle PMG_SIG_UM_MULTI_OP_REQ from UM
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_um_handle_multi_op_req(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_um_multi_op_req_t *data = (pmg_um_multi_op_req_t*) p;
    srv_um_mark_several_op_rsp_struct *local_param;
    MSF_UINT32 i;
    pmg_msg_id_struct deleted_msgs[WAP_PMG_MAX_DELETED_MSG_LIST_SIZE];
    kal_uint32 deleted_msgs_size;
    pmg_msg_elem_t *msgelem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* prepare response local parameter */
    local_param = (srv_um_mark_several_op_rsp_struct*)construct_local_para((kal_uint16) sizeof(srv_um_mark_several_op_rsp_struct), TD_RESET);
    local_param->msg_type = SRV_UM_MSG_WAP_PUSH;
    local_param->app_id = 0;
    local_param->msg_box_type = SRV_UM_MSG_BOX_INBOX;
    pmg_um_multi_op_action_to_pmg(0, (void*)&(local_param->action_type), &(data->action));
    local_param->msg_number = (kal_uint16)data->msgNumber;
    memcpy(local_param->msg_id, data->msgIDs, data->msgNumber * sizeof(kal_uint32));
    
    deleted_msgs_size = 0;
    memset(deleted_msgs, 0, WAP_PMG_MAX_DELETED_MSG_LIST_SIZE * sizeof(pmg_msg_id_struct));

    if (data->action == PMG_UM_MULTI_OP_DELETE)
    {
        for (i=0; i<data->msgNumber; i++)
        {
            msgelem = pmg_msg_find_elem_by_id(data->msgIDs[i]);
            if (msgelem)
            {
                deleted_msgs[deleted_msgs_size].msg_id = data->msgIDs[i];
                deleted_msgs[deleted_msgs_size].msg_type = msgelem->type;
                deleted_msgs_size++;
            }

            if (pmg_msg_delete_message(data->msgIDs[i]))
                local_param->action_result[i] = KAL_TRUE;

            if (deleted_msgs_size >= WAP_PMG_MAX_DELETED_MSG_LIST_SIZE)
            {
                pmg_inbox_send_wps_pmg_delete_ind_ext(deleted_msgs_size, deleted_msgs);
                deleted_msgs_size = 0;
                memset(deleted_msgs, 0, WAP_PMG_MAX_DELETED_MSG_LIST_SIZE * sizeof(pmg_msg_id_struct));
            }
        }

        if (deleted_msgs_size > 0)
        {
            pmg_inbox_send_wps_pmg_delete_ind_ext(deleted_msgs_size, deleted_msgs);
            deleted_msgs_size = 0;
            memset(deleted_msgs, 0, WAP_PMG_MAX_DELETED_MSG_LIST_SIZE * sizeof(pmg_msg_id_struct));
        }
    }
    else
    {
        /* local_param->action_result defaults to 0 already */
    }

    PMG_MEM_FREE(data->msgIDs);
    pmg_send_primitive(MOD_MMI, MSG_ID_MMI_UM_MARK_SEVERAL_OP_RSP, (void*)local_param, (void*)0);
}
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */



#ifdef WPS_PMG_CONVERSATION_BOX

void set_msg_id_with_num(MSF_UINT8 entry, MSF_UINT8 index)
{
	if (index > (MAX_TRAVERSE_MSG_NUMBER + 1))
	{
		ASSERT(0);
	}
	else
	{
		msg_id_with_num[index] = entry;
	}
}

MSF_UINT8 pmg_um_check_msg_id_to_traverse_msg_id (int msg_id)
{
	int i = 0;
	for (i = 1; i <= msg_id_with_num[0]; i++)
	{
		if (msg_id_with_num [i] == msg_id)
			return 1;
	}
	return 0;
}
#endif /* WPS_PMG_CONVERSATION_BOX */

#endif /* __MMI_PUSH_IN_UM__ */ 

