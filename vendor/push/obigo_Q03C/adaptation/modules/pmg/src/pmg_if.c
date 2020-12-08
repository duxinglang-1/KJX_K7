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
 *   pmg_if.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains PMG interface APIs for other Obigo modules
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
#include "msf_core.h"
#include "msf_int.h"
#include "msf_mem.h"
#include "msf_dcvt.h"
#include "msf_log.h"
//#include "msf_pipe.h"
//#include "msf_file.h"
//#include "msf_chrs.h"
//#include "msf_errc.h"
#include "msf_mime.h"

#include "pmg_main.h"
#include "pmg_fs.h"
#include "pmg_if.h"
#include "pmg_inbox.h"
#include "phs_cfg.h"
//#include "pmg_phs.h"
#include "cbm_api.h"

//suggested add
    #include "msf_def.h"
    #include "MMI_features.h"
    #include "pmg_msg.h"
    #include "kal_general_types.h"
    #include "UmSrvStruct.h"
    #include "pmg_struct.h"
    #include "phs_struct.h"
    #include "msf_cmmn.h"
    #include "string.h"
    #include "stdio.h"
    #include "kal_trace.h"
    #include "wps_trc.h"
    #include "MMIDataType.h"
 extern const U8* srv_brw_get_default_accept_header(void);
/*****************************************************************************
 * FUNCTION
 *  PMGif_startInterface
 * DESCRIPTION
 *  register PMG's signal alloc/destruct handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PMGif_startInterface(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
#ifdef  __OBIGO_FRMW2__ 
   MSF_SIGNAL_REG_FUNCTIONS(MSF_MODID_PMG, pmg_convert, pmg_destruct);
#endif
}

#ifdef  __OBIGO_FRMW2__
/*****************************************************************************
 * FUNCTION
 *  pmg_cvt_get_msg_by_attribute
 * DESCRIPTION
 *  PMG_SIG_GET_MSG_BY_ATTRIBUTE data conversion
 * PARAMETERS
 *  obj             [in]
 *  p               [in]
 * RETURNS
 *  TRUE        conversion succeeded
 *  FALSE       conversion failed
 *****************************************************************************/
int pmg_cvt_get_msg_by_attribute(msf_dcvt_t *obj, pmg_get_msg_by_attribute_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_uint16(obj, (MSF_UINT16*) & (p->transID)) ||
        !msf_dcvt_uint8(obj, (MSF_UINT8*) & (p->msgType)) || !msf_dcvt_string(obj, (char **)&(p->attribute)))
    {
        return FALSE;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_cvt_get_msg_by_attribute_reply
 * DESCRIPTION
 *  PMG_SIG_GET_MSG_BY_ATTRIBUTE_REPLY data conversion
 * PARAMETERS
 *  obj          [in]
 *  p            [in]
 * RETURNS
 *  TRUE        conversion succeeded
 *  FALSE       conversion failed
 *****************************************************************************/
int pmg_cvt_get_msg_by_attribute_reply(msf_dcvt_t *obj, pmg_get_msg_by_attribute_reply_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_uint16(obj, (MSF_UINT16*) & (p->transID)) ||
        !msf_dcvt_uint8(obj, (MSF_UINT8*) & (p->result)) || !msf_dcvt_uint32(obj, (MSF_UINT32*) & (p->msg)))
    {
        return FALSE;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_cvt_delete_msg
 * DESCRIPTION
 *  PMG_SIG_DELETE_MSG data conversion
 * PARAMETERS
 *  obj          [in]
 *  p            [in]
 * RETURNS
 *  TRUE        conversion succeeded
 *  FALSE       conversion failed
 *****************************************************************************/
int pmg_cvt_delete_msg(msf_dcvt_t *obj, pmg_delete_msg_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_uint32(obj, (MSF_UINT32*) & (p->msgID)))
        return FALSE;
    if (!msf_dcvt_uint8(obj, (MSF_UINT8*) & (p->isReplace)))
        return FALSE;
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_cvt_create_msg
 * DESCRIPTION
 *  PMG_SIG_CREATE_MSG data conversion
 * PARAMETERS
 *  obj          [in]
 *  p            [in]
 * RETURNS
 *  TRUE        conversion succeeded
 *  FALSE       conversion failed
 *****************************************************************************/
int pmg_cvt_create_msg(msf_dcvt_t *obj, pmg_create_msg_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_uint32(obj, (MSF_UINT32*) & (p->msg)))
        return FALSE;
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_cvt_inbox_config_req
 * DESCRIPTION
 *  PMG_SIG_INBOX_CONFIG_REQ data conversion
 * PARAMETERS
 *  obj          [in]
 *  p            [in]
 * RETURNS
 *  TRUE        conversion succeeded
 *  FALSE       conversion failed
 *****************************************************************************/
int pmg_cvt_inbox_config_req(msf_dcvt_t *obj, pmg_inbox_config_req_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_uint8(obj, (MSF_UINT8*) & (p->wapPushEnabled)) ||
        !msf_dcvt_uint8(obj, (MSF_UINT8*) & (p->slEnabled)) || 
        !msf_dcvt_uint8(obj, (MSF_UINT8*) & (p->trustEnabled)) ||
        !msf_dcvt_uint8(obj, (MSF_UINT8*) & (p->blackListEnabled)) ||
        !msf_dcvt_uint32(obj, (MSF_UINT32*) & (p->maxTrustAddrNo)) ||
        !msf_dcvt_uint32(obj, (MSF_UINT32*) & (p->maxBlackAddrNo)))
    {
        return FALSE;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_cvt_inbox_msg_count_req
 * DESCRIPTION
 *  PMG_SIG_INBOX_MSG_COUNT_REQ data conversion
 * PARAMETERS
 *  obj          [in]
 *  p            [in]
 * RETURNS
 *  TRUE        conversion succeeded
 *  FALSE       conversion failed
 *****************************************************************************/
int pmg_cvt_inbox_msg_count_req(msf_dcvt_t *obj, pmg_inbox_msg_count_req_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, (MSF_INT32*) & (p->transID)) ||
        !msf_dcvt_uint8(obj, (MSF_UINT8*) & (p->msgType)) ||
        !msf_dcvt_uint8(obj, (MSF_UINT8*) & (p->isRead)) ||
        !msf_dcvt_uint8(obj, (MSF_UINT8*) & (p->isExpired)) || !msf_dcvt_uint8(obj, (MSF_UINT8*) & (p->hasInfo)))
    {
        return FALSE;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_cvt_inbox_msg_list_req
 * DESCRIPTION
 *  PMG_SIG_INBOX_MSG_LIST_REQ data conversion
 * PARAMETERS
 *  obj          [in]
 *  p            [in]
 * RETURNS
 *  TRUE        conversion succeeded
 *  FALSE       conversion failed
 *****************************************************************************/
int pmg_cvt_inbox_msg_list_req(msf_dcvt_t *obj, pmg_inbox_msg_list_req_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, (MSF_INT32*) & (p->transID)) ||
        !msf_dcvt_uint8(obj, (MSF_UINT8*) & (p->msgType)) ||
        !msf_dcvt_uint8(obj, (MSF_UINT8*) & (p->isRead)) ||
        !msf_dcvt_uint8(obj, (MSF_UINT8*) & (p->isExpired)) ||
        !msf_dcvt_uint8(obj, (MSF_UINT8*) & (p->hasInfo)) ||
        !msf_dcvt_uint32(obj, (MSF_UINT32*) & (p->startFrom)) || !msf_dcvt_uint32(obj, (MSF_UINT32*) & (p->size)))
    {
        return FALSE;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_cvt_inbox_get_msg_req
 * DESCRIPTION
 *  PMG_SIG_INBOX_GET_MSG_REQ data conversion
 * PARAMETERS
 *  obj          [in]
 *  p            [in]
 * RETURNS
 *  TRUE        conversion succeeded
 *  FALSE       conversion failed
 *****************************************************************************/
int pmg_cvt_inbox_get_msg_req(msf_dcvt_t *obj, pmg_inbox_get_msg_req_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, (MSF_INT32*) & (p->transID)) || !msf_dcvt_int32(obj, (MSF_INT32*) & (p->msgID)))
    {
        return FALSE;
    }
    return TRUE;
}

/* SKS */
/*****************************************************************************
 * FUNCTION
 *   pmg_cvt_inbox_msg_read_status_req
 *
 * DESCRIPTION
 *  PMG_SIG_INBOX_MSG_READ_STATUS_REQ data conversion
 * PARAMETERS
 *  obj          [in]
 *  p            [in]
 * RETURNS
 *  TRUE        conversion succeeded
 *  FALSE       conversion failed
 *****************************************************************************/
int 	pmg_cvt_inbox_msg_read_status_req
(msf_dcvt_t *obj, pmg_inbox_msg_read_status_req_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, (MSF_INT32*) & (p->msg_id)) || 
	!msf_dcvt_int32(obj, (MSF_INT32*) & (p->status_func)))
    {
        return FALSE;
    }
    return TRUE;
}

/* SKS */

/*****************************************************************************
 * FUNCTION
 *  pmg_cvt_inbox_get_msg_infotag_req
 * DESCRIPTION
 *  PMG_SIG_INBOX_GET_MSG_INFOTAG_REQ data conversion
 * PARAMETERS
 *  obj          [in]
 *  p            [in]
 * RETURNS
 *  TRUE        conversion succeeded
 *  FALSE       conversion failed
 *****************************************************************************/
int pmg_cvt_inbox_get_msg_infotag_req(msf_dcvt_t *obj, pmg_inbox_get_msg_infotag_req_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, (MSF_INT32*) & (p->transID)) ||
        !msf_dcvt_int32(obj, (MSF_INT32*) & (p->msgID)) || !msf_dcvt_uint32(obj, (MSF_UINT32*) & (p->startFrom)))
    {
        return FALSE;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_cvt_inbox_delete_msg_req
 * DESCRIPTION
 *  PMG_SIG_INBOX_DELETE_MSG_REQ data conversion
 * PARAMETERS
 *  obj          [in]
 *  p            [in]
 * RETURNS
 *  TRUE        conversion succeeded
 *  FALSE       conversion failed
 *****************************************************************************/
int pmg_cvt_inbox_delete_msg_req(msf_dcvt_t *obj, pmg_inbox_delete_msg_req_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, (MSF_INT32*) & (p->transID)) || !msf_dcvt_int32(obj, (MSF_INT32*) & (p->msgID)))
    {
        return FALSE;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_cvt_inbox_delete_all_req
 * DESCRIPTION
 *  PMG_SIG_INBOX_DELETE_ALL_REQ data conversion
 * PARAMETERS
 *  obj          [in]
 *  p            [in]
 * RETURNS
 *  TRUE        conversion succeeded
 *  FALSE       conversion failed
 *****************************************************************************/
int pmg_cvt_inbox_delete_all_req(msf_dcvt_t *obj, pmg_inbox_delete_all_req_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, (MSF_INT32*) & (p->transID)) || !msf_dcvt_uint8(obj, (MSF_UINT8*) & (p->msgType)))
    {
        return FALSE;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_cvt_inbox_update_msg_req
 * DESCRIPTION
 *  PMG_SIG_INBOX_UPDATE_MSG_REQ data conversion
 * PARAMETERS
 *  obj          [in]
 *  p            [in]
 * RETURNS
 *  TRUE        conversion succeeded
 *  FALSE       conversion failed
 *****************************************************************************/
int pmg_cvt_inbox_update_msg_req(msf_dcvt_t *obj, pmg_inbox_update_msg_req_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, (MSF_INT32*) & (p->transID)) ||
        !msf_dcvt_int32(obj, (MSF_INT32*) & (p->msgID)) || !msf_dcvt_uint8(obj, (MSF_UINT8*) & (p->read)))
    {
        return FALSE;
    }
    return TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  pmg_cvt_inbox_update_all_msg_req
 * DESCRIPTION
 *  PMG_SIG_INBOX_UPDATE_ALL_MSG_REQ data conversion
 * PARAMETERS
 *  obj          [in]
 *  p            [in]
 * RETURNS
 *  TRUE        conversion succeeded
 *  FALSE       conversion failed
 *****************************************************************************/
int pmg_cvt_inbox_update_all_msg_req(msf_dcvt_t *obj, pmg_inbox_update_all_msg_req_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (       !msf_dcvt_uint8(obj, (MSF_UINT8*) & (p->read)))
    {
        return FALSE;
    }
    return TRUE;
}




/*****************************************************************************
 * FUNCTION
 *  pmg_cvt_inbox_auth_addr_list_req
 * DESCRIPTION
 *  PMG_SIG_INBOX_AUTH_ADDR_LIST_REQ data conversion
 * PARAMETERS
 *  obj          [in]
 *  p            [in]
 * RETURNS
 *  TRUE        conversion succeeded
 *  FALSE       conversion failed
 *****************************************************************************/
int pmg_cvt_inbox_auth_addr_list_req(msf_dcvt_t *obj, pmg_inbox_auth_addr_list_req_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, (MSF_INT32*) & (p->transID)) ||
        !msf_dcvt_int32(obj, (MSF_INT32*) & (p->type)) ||
        !msf_dcvt_int32(obj, (MSF_INT32*) & (p->segment)) ||
        !msf_dcvt_int32(obj, (MSF_INT32*) & (p->size)) || 
		!msf_dcvt_int32(obj, (MSF_INT32*) & (p->addrs)) ||
		!msf_dcvt_int32(obj, (MSF_INT32*) & (p->total_segment)))
    {
        return FALSE;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_cvt_inbox_dlg_response
 * DESCRIPTION
 *  PMG_SIG_INBOX_DLG_RESPONSE data conversion
 * PARAMETERS
 *  obj          [in]
 *  p            [in]
 * RETURNS
 *  TRUE        conversion succeeded
 *  FALSE       conversion failed
 *****************************************************************************/
int pmg_cvt_inbox_dlg_response(msf_dcvt_t *obj, pmg_inbox_dlg_response_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, (MSF_INT32*) & (p->type)) || 
        !msf_dcvt_uint32(obj, (MSF_UINT32*) & (p->id)) || 
        !msf_dcvt_int32(obj, (MSF_INT32*) & (p->result)))
    {
        return FALSE;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_cvt_inbox_dlg_query_req
 * DESCRIPTION
 *  PMG_SIG_INBOX_DLG_QUERY data conversion
 * PARAMETERS
 *  obj          [in]
 *  p            [in]
 * RETURNS
 *  TRUE        conversion succeeded
 *  FALSE       conversion failed
 *****************************************************************************/
int pmg_cvt_inbox_dlg_query_req(msf_dcvt_t *obj, pmg_inbox_dlg_query_req_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, (MSF_INT32*) & (p->transID)) ||
        !msf_dcvt_int32(obj, (MSF_INT32*) & (p->dlgID)))
    {
        return FALSE;
    }
    return TRUE;
}

#ifdef __MMI_PUSH_IN_UM__
/*****************************************************************************
 * FUNCTION
 *  pmg_cvt_um_get_msg_num_req
 * DESCRIPTION
 *  PMG_SIG_UM_GET_MSG_NUM_REQ data conversion
 * PARAMETERS
 *  obj          [in]
 *  p            [in]
 * RETURNS
 *  TRUE        conversion succeeded
 *  FALSE       conversion failed
 *****************************************************************************/
int pmg_cvt_um_get_msg_num_req(msf_dcvt_t *obj, pmg_um_get_msg_num_req_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_uint8(obj, (MSF_UINT8*) & (p->msgType)))
    {
        return FALSE;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_cvt_um_get_list_req
 * DESCRIPTION
 *  PMG_SIG_UM_GET_LIST_REQ data conversion
 * PARAMETERS
 *  obj          [in]
 *  p            [in]
 * RETURNS
 *  TRUE        conversion succeeded
 *  FALSE       conversion failed
 *****************************************************************************/
int pmg_cvt_um_get_list_req(msf_dcvt_t *obj, pmg_um_get_list_req_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
    if (!msf_dcvt_uint8(obj, (MSF_UINT8*) & (p->msgType)) || 
        !msf_dcvt_uint8(obj, (MSF_UINT8*) & (p->idxType)) || 
		!msf_dcvt_uint32(obj, (MSF_UINT32*) & (p->sim_id)) ||
        !msf_dcvt_uint32(obj, (MSF_UINT32*) & (p->startFrom)))
#else
    if (!msf_dcvt_uint8(obj, (MSF_UINT8*) & (p->msgType)) || 
		!msf_dcvt_uint32(obj, (MSF_UINT32*) & (p->sim_id)) ||
        !msf_dcvt_uint32(obj, (MSF_UINT32*) & (p->startFrom)))
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */
    {
        return FALSE;
    }
    return TRUE;
}


#ifdef WPS_PMG_CONVERSATION_BOX

/*****************************************************************************
 * FUNCTION
 *  pmg_cvt_um_get_traverse_list_req
 * DESCRIPTION
 *  PMG_SIG_UM_GET_TRAVERSE_LIST_REQ data conversion
 * PARAMETERS
 *  obj          [in]
 *  p            [in]
 * RETURNS
 *  TRUE        conversion succeeded
 *  FALSE       conversion failed
 *****************************************************************************/
int pmg_cvt_um_get_traverse_list_req(msf_dcvt_t *obj, pmg_um_get_traverse_list_req_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!msf_dcvt_uint8(obj, (MSF_UINT8*) & (p->msgType)) || 
        !msf_dcvt_int16(obj, (MSF_INT16*) & (p->startFrom)) ||
		!msf_dcvt_uint32(obj, (MSF_UINT32*) & (p->pid)) ||
		!msf_dcvt_uint32(obj, (MSF_UINT32*) & (p->app_id)) ||
		!msf_dcvt_uint32(obj, (MSF_UINT32*) & (p->sim_id)) ||
		!msf_dcvt_uint32(obj, (MSF_UINT32*) & (p->traverse_func)))
    {
        return FALSE;
    }
    return TRUE;
}

#endif /* WPS_PMG_CONVERSATION_BOX */

/*****************************************************************************
 * FUNCTION
 *  pmg_cvt_um_get_msg_info_req
 * DESCRIPTION
 *  PMG_SIG_UM_GET_MSG_INFO_REQ data conversion
 * PARAMETERS
 *  obj          [in]
 *  p            [in]
 * RETURNS
 *  TRUE        conversion succeeded
 *  FALSE       conversion failed
 *****************************************************************************/
int pmg_cvt_um_get_msg_info_req(msf_dcvt_t *obj, pmg_um_get_msg_info_req_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_uint8(obj, (MSF_UINT8*) & (p->msgType)) ||
        !msf_dcvt_uint16(obj, (MSF_UINT16*)&(p->msgNumber)) ||
        !msf_dcvt_uint32(obj, (MSF_UINT32*)&(p->msgIDs)))
    {
        return FALSE;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_cvt_um_delete_folder_req
 * DESCRIPTION
 *  PMG_SIG_UM_DELETE_FOLDER_REQ data conversion
 * PARAMETERS
 *  obj          [in]
 *  p            [in]
 * RETURNS
 *  TRUE        conversion succeeded
 *  FALSE       conversion failed
 *****************************************************************************/
int pmg_cvt_um_delete_folder_req(msf_dcvt_t *obj, pmg_um_delete_folder_req_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_uint8(obj, (MSF_UINT8*) & (p->msgType)))
    {
        return FALSE;
    }
    return TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  pmg_cvt_um_multi_op_req
 * DESCRIPTION
 *  PMG_SIG_UM_MULTI_OP_REQ data conversion
 * PARAMETERS
 *  obj          [in]
 *  p            [in]
 * RETURNS
 *  TRUE        conversion succeeded
 *  FALSE       conversion failed
 *****************************************************************************/
int pmg_cvt_um_multi_op_req(msf_dcvt_t *obj, pmg_um_multi_op_req_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_uint8(obj, (MSF_UINT8*)&(p->action)) ||
        !msf_dcvt_uint32(obj, (MSF_UINT32*)&(p->msgNumber)) ||
        !msf_dcvt_uint32(obj, (MSF_UINT32*)&(p->msgIDs)))
    {
        return FALSE;
    }
    return TRUE;
}
#endif /* __MMI_PUSH_IN_UM__ */
/*****************************************************************************
 * FUNCTION
 *  pmg_cvt_display_dialog_req
 * DESCRIPTION
 *  PMG_SIG_DISPLAY_DIALOG_REQ data conversion
 * PARAMETERS
 *  obj          [in]
 *  p            [in]
 * RETURNS
 *  TRUE        conversion succeeded
 *  FALSE       conversion failed
 *****************************************************************************/
int pmg_cvt_display_dialog_req(msf_dcvt_t *obj, pmg_display_dialog_req_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_dcvt_int32(obj, (MSF_INT32*) & (p->dlg_request)))
    {
        return FALSE;
    }
    return TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  pmg_convert
 * DESCRIPTION
 *  signal data retrieval
 * PARAMETERS
 *  module              [in]
 *  signal              [in]
 *  buffer              [in]
 * RETURNS
 *  signal data(?)
 *****************************************************************************/
void *pmg_convert(MSF_UINT8 module, MSF_UINT16 signal, void *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    msf_dcvt_t cvt_obj;
    void *user_data;
    MSF_UINT16 length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer == NULL)
        return NULL;

    user_data = MSF_SIGNAL_GET_USER_DATA(buffer, &length);
    if ((user_data == NULL) || (length == 0))
        return NULL;

    msf_dcvt_init(&cvt_obj, MSF_DCVT_DECODE, user_data, length, module);

    switch (signal)
    {
        case PMG_SIG_GET_MSG_BY_ATTRIBUTE:
        {
            pmg_get_msg_by_attribute_t *p;

            p = MSF_MEM_ALLOCTYPE(module, pmg_get_msg_by_attribute_t);
            (void)pmg_cvt_get_msg_by_attribute(&cvt_obj, p);
            return (void*)p;
        }
        case PMG_SIG_GET_MSG_BY_ATTRIBUTE_REPLY:
        {
            pmg_get_msg_by_attribute_reply_t *p;

            p = MSF_MEM_ALLOCTYPE(module, pmg_get_msg_by_attribute_reply_t);
            (void)pmg_cvt_get_msg_by_attribute_reply(&cvt_obj, p);
            return (void*)p;
        }
        case PMG_SIG_DELETE_MSG:
        {
            pmg_delete_msg_t *p;

            p = MSF_MEM_ALLOCTYPE(module, pmg_delete_msg_t);
            (void)pmg_cvt_delete_msg(&cvt_obj, p);
            return (void*)p;
        }
        case PMG_SIG_CREATE_MSG:
        {
            pmg_create_msg_t *p;

            p = MSF_MEM_ALLOCTYPE(module, pmg_create_msg_t);
            (void)pmg_cvt_create_msg(&cvt_obj, p);
            return (void*)p;
        }
        case PMG_SIG_INBOX_CONFIG_REQ:
        {
            pmg_inbox_config_req_t *p;

            p = MSF_MEM_ALLOCTYPE(module, pmg_inbox_config_req_t);
            (void)pmg_cvt_inbox_config_req(&cvt_obj, p);
            return (void*)p;
        }
        case PMG_SIG_INBOX_MSG_COUNT_REQ:
        {
            pmg_inbox_msg_count_req_t *p;

            p = MSF_MEM_ALLOCTYPE(module, pmg_inbox_msg_count_req_t);
            (void)pmg_cvt_inbox_msg_count_req(&cvt_obj, p);
            return (void*)p;
        }
        case PMG_SIG_INBOX_MSG_LIST_REQ:
        {
            pmg_inbox_msg_list_req_t *p;

            p = MSF_MEM_ALLOCTYPE(module, pmg_inbox_msg_list_req_t);
            (void)pmg_cvt_inbox_msg_list_req(&cvt_obj, p);
            return (void*)p;
        }
        case PMG_SIG_INBOX_GET_MSG_REQ:
        {
            pmg_inbox_get_msg_req_t *p;

            p = MSF_MEM_ALLOCTYPE(module, pmg_inbox_get_msg_req_t);
            (void)pmg_cvt_inbox_get_msg_req(&cvt_obj, p);
            return (void*)p;
        }

		case PMG_SIG_INBOX_MSG_READ_STATUS_REQ:
	{  
     		pmg_inbox_msg_read_status_req_t *p;
		p = MSF_MEM_ALLOCTYPE(module, pmg_inbox_msg_read_status_req_t);
		(void)pmg_cvt_inbox_msg_read_status_req(&cvt_obj, p);
		return (void*)p;

	}
        case PMG_SIG_INBOX_GET_MSG_INFOTAG_REQ:
        {
            pmg_inbox_get_msg_infotag_req_t *p;

            p = MSF_MEM_ALLOCTYPE(module, pmg_inbox_get_msg_infotag_req_t);
            (void)pmg_cvt_inbox_get_msg_infotag_req(&cvt_obj, p);
            return (void*)p;
        }
        case PMG_SIG_INBOX_DELETE_MSG_REQ:
        {
            pmg_inbox_delete_msg_req_t *p;

            p = MSF_MEM_ALLOCTYPE(module, pmg_inbox_delete_msg_req_t);
            (void)pmg_cvt_inbox_delete_msg_req(&cvt_obj, p);
            return (void*)p;
        }
        case PMG_SIG_INBOX_DELETE_ALL_REQ:
        {
            pmg_inbox_delete_all_req_t *p;

            p = MSF_MEM_ALLOCTYPE(module, pmg_inbox_delete_all_req_t);
            (void)pmg_cvt_inbox_delete_all_req(&cvt_obj, p);
            return (void*)p;
        }
        case PMG_SIG_INBOX_UPDATE_MSG_REQ:
        {
            pmg_inbox_update_msg_req_t *p;

            p = MSF_MEM_ALLOCTYPE(module, pmg_inbox_update_msg_req_t);
            (void)pmg_cvt_inbox_update_msg_req(&cvt_obj, p);
            return (void*)p;
        }

		case PMG_SIG_INBOX_UPDATE_ALL_MSG_REQ:
        {
            pmg_inbox_update_all_msg_req_t *p;

            p = MSF_MEM_ALLOCTYPE(module, pmg_inbox_update_all_msg_req_t);
            (void)pmg_cvt_inbox_update_all_msg_req(&cvt_obj, p);
            return (void*)p;
        }



        case PMG_SIG_INBOX_NEW_MSG_RSP:
        {
            return (void*)0;
        }
        case PMG_SIG_INBOX_AUTH_ADDR_LIST_REQ:
        {
            pmg_inbox_auth_addr_list_req_t *p;

            p = MSF_MEM_ALLOCTYPE(module, pmg_inbox_auth_addr_list_req_t);
            (void)pmg_cvt_inbox_auth_addr_list_req(&cvt_obj, p);
            return (void*)p;
        }
        case PMG_SIG_INBOX_DLG_RESPONSE:
        {
            pmg_inbox_dlg_response_t *p;
            p = MSF_MEM_ALLOCTYPE(module, pmg_inbox_dlg_response_t);
            (void)pmg_cvt_inbox_dlg_response(&cvt_obj, p);
            return (void*)p;
        }
#ifdef __MMI_PUSH_IN_UM__
        case PMG_SIG_UM_GET_MSG_NUM_REQ:
        {
            pmg_um_get_msg_num_req_t *p;

            p = MSF_MEM_ALLOCTYPE(module, pmg_um_get_msg_num_req_t);
            (void)pmg_cvt_um_get_msg_num_req(&cvt_obj, p);
            return (void*)p;
        }

#ifdef WPS_PMG_CONVERSATION_BOX
	case PMG_SIG_UM_GET_TRAVERSE_LIST_REQ:
	{
	    pmg_um_get_traverse_list_req_t *p;

            p = MSF_MEM_ALLOCTYPE(module, pmg_um_get_traverse_list_req_t);
            (void)pmg_cvt_um_get_traverse_list_req(&cvt_obj, p);
            return (void*)p;
	}
#endif /*WPS_PMG_CONVERSATION_BOX */

        case PMG_SIG_UM_GET_LIST_REQ:
        {
            pmg_um_get_list_req_t *p;

            p = MSF_MEM_ALLOCTYPE(module, pmg_um_get_list_req_t);
            (void)pmg_cvt_um_get_list_req(&cvt_obj, p);
            return (void*)p;
        }
        case PMG_SIG_UM_GET_MSG_INFO_REQ:
        {
            pmg_um_get_msg_info_req_t *p;

            p = MSF_MEM_ALLOCTYPE(module, pmg_um_get_msg_info_req_t);
            (void)pmg_cvt_um_get_msg_info_req(&cvt_obj, p);
            return (void*)p;
        }
        case PMG_SIG_UM_DELETE_FOLDER_REQ:
        {
            pmg_um_delete_folder_req_t *p;

            p = MSF_MEM_ALLOCTYPE(module, pmg_um_delete_folder_req_t);
            (void)pmg_cvt_um_delete_folder_req(&cvt_obj, p);
            return (void*)p;
        }
        case PMG_SIG_UM_MULTI_OP_REQ:
        {
            pmg_um_multi_op_req_t *p;

            p = MSF_MEM_ALLOCTYPE(module, pmg_um_multi_op_req_t);
            (void)pmg_cvt_um_multi_op_req(&cvt_obj, p);
            return (void*)p;
        }
#endif /* __MMI_PUSH_IN_UM__ */
        case PMG_SIG_DISPLAY_DIALOG_REQ:
        {
            pmg_display_dialog_req_t *p;

            p = MSF_MEM_ALLOCTYPE(module, pmg_display_dialog_req_t);
            (void)pmg_cvt_display_dialog_req(&cvt_obj, p);
            return (void*)p;
        }
        case PMG_SIG_INBOX_DLG_QUERY_REQ:
        {
            pmg_inbox_dlg_query_req_t *p;

            p = MSF_MEM_ALLOCTYPE(module, pmg_inbox_dlg_query_req_t);
            (void)pmg_cvt_inbox_dlg_query_req(&cvt_obj, p);
            return (void*)p;
        }
		case PMG_SIG_SET_DATA_TO_SETTING_REQ:
		{
			pmg_phs_setting_data_t  *p;
			p = MSF_MEM_ALLOCTYPE(module, pmg_phs_setting_data_t);
			(void)pmg_cvt_set_data_to_phs_setting(&cvt_obj, p);
			return (void*)p;
		}
		case PMG_SIG_SET_DEF_CONN:
		{
			pmg_phs_def_con *p;
			p = MSF_MEM_ALLOCTYPE(module, pmg_phs_def_con);
			(void)pmg_cvt_set_def_con(&cvt_obj, p);
			return (void*)p;
		}

		case PMG_SIG_CONTENT_DATA_ROUTE_REQ:
		{
			pmg_content_send_t *p;
			p = MSF_MEM_ALLOCTYPE(module, pmg_content_send_t);
			(void)pmg_cvt_content_send(&cvt_obj, p);
			return (void*)p;
		}
		case PMG_SIG_SET_LIST_DATA_IND:
		{
			pmg_phs_list_data_t *p;
			p = MSF_MEM_ALLOCTYPE(module, pmg_phs_list_data_t);
			(void)pmg_cvt_data_list(&cvt_obj, p);
			return (void*)p;
		}

        default:
            return NULL;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_destruct
 * DESCRIPTION
 *  signal destruct function
 * PARAMETERS
 *  module              [in]
 *  signal              [in]
 *  p                   [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_destruct(MSF_UINT8 module, MSF_UINT16 signal, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    msf_dcvt_t cvt_obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p == NULL)
        return;

    msf_dcvt_init(&cvt_obj, MSF_DCVT_FREE, NULL, 0, module);

    switch (signal)
    {
        case PMG_SIG_GET_MSG_BY_ATTRIBUTE:
            (void)pmg_cvt_get_msg_by_attribute(&cvt_obj, p);
            break;
        case PMG_SIG_GET_MSG_BY_ATTRIBUTE_REPLY:
            (void)pmg_cvt_get_msg_by_attribute_reply(&cvt_obj, p);
            break;
        case PMG_SIG_DELETE_MSG:
            (void)pmg_cvt_delete_msg(&cvt_obj, p);
            break;
        case PMG_SIG_CREATE_MSG:
            (void)pmg_cvt_create_msg(&cvt_obj, p);
            break;
        case PMG_SIG_INBOX_CONFIG_REQ:
            (void)pmg_cvt_inbox_config_req(&cvt_obj, p);
            break;
        case PMG_SIG_INBOX_MSG_COUNT_REQ:
            (void)pmg_cvt_inbox_msg_count_req(&cvt_obj, p);
            break;
        case PMG_SIG_INBOX_MSG_LIST_REQ:
            (void)pmg_cvt_inbox_msg_list_req(&cvt_obj, p);
            break;
        case PMG_SIG_INBOX_GET_MSG_REQ:
            (void)pmg_cvt_inbox_get_msg_req(&cvt_obj, p);
            break;
	case PMG_SIG_INBOX_MSG_READ_STATUS_REQ:
		(void)pmg_cvt_inbox_msg_read_status_req(&cvt_obj, p);
		break;	
        case PMG_SIG_INBOX_GET_MSG_INFOTAG_REQ:
            (void)pmg_cvt_inbox_get_msg_infotag_req(&cvt_obj, p);
            break;
        case PMG_SIG_INBOX_DELETE_MSG_REQ:
            (void)pmg_cvt_inbox_delete_msg_req(&cvt_obj, p);
            break;
        case PMG_SIG_INBOX_DELETE_ALL_REQ:
            (void)pmg_cvt_inbox_delete_all_req(&cvt_obj, p);
            break;
        case PMG_SIG_INBOX_UPDATE_MSG_REQ:
            (void)pmg_cvt_inbox_update_msg_req(&cvt_obj, p);
            break;
		case PMG_SIG_INBOX_UPDATE_ALL_MSG_REQ:
            (void)pmg_cvt_inbox_update_all_msg_req(&cvt_obj, p);
            break;
        case PMG_SIG_INBOX_NEW_MSG_RSP:
            break;
        case PMG_SIG_INBOX_AUTH_ADDR_LIST_REQ:
            (void)pmg_cvt_inbox_auth_addr_list_req(&cvt_obj, p);
            break;
#ifdef __MMI_PUSH_IN_UM__
        case PMG_SIG_UM_GET_MSG_NUM_REQ:
            (void)pmg_cvt_um_get_msg_num_req(&cvt_obj, p);
            break;

#ifdef WPS_PMG_CONVERSATION_BOX
	case PMG_SIG_UM_GET_TRAVERSE_LIST_REQ:
	    (void)pmg_cvt_um_get_traverse_list_req(&cvt_obj, p);
            break;
#endif /* WPS_PMG_CONVERSATION_BOX */

        case PMG_SIG_UM_GET_LIST_REQ:
            (void)pmg_cvt_um_get_list_req(&cvt_obj, p);
            break;
        case PMG_SIG_UM_GET_MSG_INFO_REQ:
            (void)pmg_cvt_um_get_msg_info_req(&cvt_obj, p);
            break;
        case PMG_SIG_UM_DELETE_FOLDER_REQ:
            (void)pmg_cvt_um_delete_folder_req(&cvt_obj, p);
            break;
        case PMG_SIG_UM_MULTI_OP_REQ:
            (void)pmg_cvt_um_multi_op_req(&cvt_obj, p);
            break;
#endif /* __MMI_PUSH_IN_UM__ */
        case PMG_SIG_DISPLAY_DIALOG_REQ:
            (void)pmg_cvt_display_dialog_req(&cvt_obj, p);
            break;
        case PMG_SIG_INBOX_DLG_QUERY_REQ:
            (void)pmg_cvt_inbox_dlg_query_req(&cvt_obj, p);
            break;
		case PMG_SIG_SET_DATA_TO_SETTING_REQ:
			(void)pmg_cvt_set_data_to_phs_setting(&cvt_obj, p);
			break;
		case PMG_SIG_SET_DEF_CONN:
			(void)pmg_cvt_set_def_con(&cvt_obj, p);
			break;
		case PMG_SIG_CONTENT_DATA_ROUTE_REQ:
			(void)pmg_cvt_content_send(&cvt_obj, p);
			break;
		case PMG_SIG_SET_LIST_DATA_IND:
			(void)pmg_cvt_data_list(&cvt_obj, p);
			break;
		default:
            break;
    }
    MSF_MEM_FREE(module, p);
}
#endif /*__OBIGO_FRMW2__*/

/*****************************************************************************
 * FUNCTION
 *  PMGif_getMsgByAttribute
 * DESCRIPTION
 *  send a PMG_SIG_GET_MSG_BY_ATTRIBUTE signal to PMG
 * PARAMETERS
 *  modid                   [in]
 *  transID                 [in]
 *  msgType                 [in]
 *  attribute               [in]
 * RETURNS
 *  void
 *****************************************************************************/
void PMGif_getMsgByAttribute(MSF_UINT8 modid, MSF_UINT16 transID, MSF_UINT8 msgType, char *attribute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    pmg_get_msg_by_attribute_t param;
    msf_dcvt_t cvt_obj;
    MSF_UINT16 length;
    void *signal_buffer, *user_data;
#else 
    pmg_get_msg_by_attribute_t  *sig;
#endif /*__OBIGO_FRMW2__*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__

    param.transID = transID;
    param.msgType = msgType;
    param.attribute = attribute;

    PMG_SEND_SIGNAL(pmg_cvt_get_msg_by_attribute, PMG_SIG_GET_MSG_BY_ATTRIBUTE, modid, MSF_MODID_PMG);

#else
	 sig= MSF_MEM_ALLOC(MSF_MODID_PMG, sizeof(pmg_get_msg_by_attribute_t));
	memset(sig, 0, sizeof(pmg_get_msg_by_attribute_t)); // recommended if signal has internal pointers.

	sig->transID = transID;
    sig->msgType = msgType;
	sig->attribute =(char *)msf_cmmn_strdup (MSF_MODID_PMG, attribute); // copies string in destination’s memory.
  
	MSF_SIGNAL_SEND (modid, MSF_MODID_PMG, PMG_SIG_GET_MSG_BY_ATTRIBUTE, sig);

#endif /*__OBIGO_FRMW2__*/


}


/*****************************************************************************
 * FUNCTION
 *  PMGif_deleteMsg
 * DESCRIPTION
 *  send a PMG_SIG_DELETE_MSG signal to PMG
 * PARAMETERS
 *  modid               [in]
 *  msgID               [in]
 * RETURNS
 *  void
 *****************************************************************************/
void PMGif_deleteMsg(MSF_UINT8 modid, MSF_UINT32 msgID, MSF_UINT8 isReplace)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    pmg_delete_msg_t param;
    msf_dcvt_t cvt_obj;
    MSF_UINT16 length;
    void *signal_buffer, *user_data;
#else
    pmg_delete_msg_t *sig;
#endif   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __OBIGO_FRMW2__
    param.msgID = msgID;
    param.isReplace = isReplace;

    PMG_SEND_SIGNAL(pmg_cvt_delete_msg, PMG_SIG_DELETE_MSG, modid, MSF_MODID_PMG);
#else
	sig = MSF_MEM_ALLOC(MSF_MODID_PMG, sizeof(pmg_delete_msg_t));

    sig->msgID = msgID;
    sig->isReplace = isReplace;

	MSF_SIGNAL_SEND (modid, MSF_MODID_PMG, PMG_SIG_DELETE_MSG, sig);
    
#endif
}


/*****************************************************************************
 * FUNCTION
 *  PMGif_createMsg
 * DESCRIPTION
 *  send a PMG_SIG_CREATE_MSG signal to PMG
 * PARAMETERS
 *  modid               [in]
 *  msg                 [in]
 * RETURNS
 *  void
 *****************************************************************************/
void PMGif_createMsg(MSF_UINT8 modid, pmg_full_msg_t *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    pmg_create_msg_t param;
    msf_dcvt_t cvt_obj;
    MSF_UINT16 length;
    void *signal_buffer, *user_data;
#else
    pmg_create_msg_t *sig;
#endif    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    param.msg = (MSF_UINT32) msg;

    PMG_SEND_SIGNAL(pmg_cvt_create_msg, PMG_SIG_CREATE_MSG, modid, MSF_MODID_PMG);
#else
	sig = MSF_MEM_ALLOC(MSF_MODID_PMG, sizeof(pmg_create_msg_t));
	memset(sig, 0, sizeof(pmg_create_msg_t)); // recommended if signal has internal pointers.

	//sig->msg = (MSF_UINT32)msf_cmmn_memndup (MSF_MODID_PMG, msg ,sizeof(pmg_full_msg_t));
	sig->msg = (MSF_UINT32)msg;
	
	MSF_SIGNAL_SEND (modid, MSF_MODID_PMG, PMG_SIG_CREATE_MSG, sig);
   
#endif
}


/*****************************************************************************
 * FUNCTION
 *  PMGif_inboxConfigReq
 * DESCRIPTION
 *  send a PMG_SIG_INBOX_CONFIG_REQ signal to PMG
 * PARAMETERS
 *  wapPushEnabled              [in]
 *  slEnabled                   [in]
 *  trustEnabled                [in]
 *  blackListEnabled            [in]
 *  maxTrustAddrNo              [in]
 *  maxBlackAddrNo              [in]
 * RETURNS
 *  void
 *****************************************************************************/
void PMGif_inboxConfigReq(
    MSF_UINT8 wapPushEnabled, 
    MSF_UINT8 slEnabled, 
    MSF_UINT8 trustEnabled,
    MSF_UINT8 blackListEnabled,
    MSF_UINT32 maxTrustAddrNo,
    MSF_UINT32 maxBlackAddrNo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    pmg_inbox_config_req_t param;
    msf_dcvt_t cvt_obj;
    MSF_UINT16 length;
    void *signal_buffer, *user_data;
#else
    pmg_inbox_config_req_t *sig;
#endif 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    param.wapPushEnabled = wapPushEnabled;
    param.slEnabled = slEnabled;
    param.trustEnabled = trustEnabled;
    param.blackListEnabled = blackListEnabled;
    param.maxTrustAddrNo = maxTrustAddrNo;
    param.maxBlackAddrNo = maxBlackAddrNo;
	PMG_SEND_SIGNAL(pmg_cvt_inbox_config_req, PMG_SIG_INBOX_CONFIG_REQ, MSF_MODID_PMG, MSF_MODID_PMG);
#else
	sig = MSF_MEM_ALLOC(MSF_MODID_PMG, sizeof(pmg_inbox_config_req_t));

    sig->wapPushEnabled = wapPushEnabled;
    sig->slEnabled = slEnabled;
    sig->trustEnabled = trustEnabled;
    sig->blackListEnabled = blackListEnabled;
    sig->maxTrustAddrNo = maxTrustAddrNo;
    sig->maxBlackAddrNo = maxBlackAddrNo;

	MSF_SIGNAL_SEND (MSF_MODID_PMG, MSF_MODID_PMG, PMG_SIG_INBOX_CONFIG_REQ, sig);
    
#endif
}


/*****************************************************************************
 * FUNCTION
 *  PMGif_inboxMsgCountReq
 * DESCRIPTION
 *  send a PMG_SIG_INBOX_MSG_COUNT_REQ signal to PMG
 * PARAMETERS
 *  transID                 [in]
 *  msgType                 [in]
 *  isRead                  [in]
 *  isExpired               [in]
 *  hasInfo                 [in]
 * RETURNS
 *  void
 *****************************************************************************/
void PMGif_inboxMsgCountReq(int transID, MSF_UINT8 msgType, MSF_UINT8 isRead, MSF_UINT8 isExpired, MSF_UINT8 hasInfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    pmg_inbox_msg_count_req_t param;
    msf_dcvt_t cvt_obj;
    MSF_UINT16 length;
    void *signal_buffer, *user_data;
#else
    pmg_inbox_msg_count_req_t *sig;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    param.transID = transID;
    param.msgType = msgType;
    param.isRead = isRead;
    param.isExpired = isExpired;
    param.hasInfo = hasInfo;

    PMG_SEND_SIGNAL(pmg_cvt_inbox_msg_count_req, PMG_SIG_INBOX_MSG_COUNT_REQ, MSF_MODID_PMG, MSF_MODID_PMG);
#else
	sig = MSF_MEM_ALLOC(MSF_MODID_PMG, sizeof(pmg_inbox_msg_count_req_t));

    sig->transID = transID;
    sig->msgType = msgType;
    sig->isRead = isRead;
    sig->isExpired = isExpired;
    sig->hasInfo = hasInfo;

	MSF_SIGNAL_SEND (MSF_MODID_PMG, MSF_MODID_PMG, PMG_SIG_INBOX_MSG_COUNT_REQ, sig);
    
#endif
}


/*****************************************************************************
 * FUNCTION
 *  PMGif_inboxMsgListReq
 * DESCRIPTION
 *  send a PMG_SIG_INBOX_MSG_LIST_REQ signal to PMG
 * PARAMETERS
 *  transID                 [in]
 *  msgType                 [in]
 *  isRead                  [in]
 *  isExpired               [in]
 *  hasInfo                 [in]
 *  startFrom               [in]
 *  size                    [in]
 * RETURNS
 *  void
 *****************************************************************************/
void
PMGif_inboxMsgListReq(
    int transID,
    MSF_UINT8 msgType,
    MSF_UINT8 isRead,
    MSF_UINT8 isExpired,
    MSF_UINT8 hasInfo,
    MSF_UINT32 startFrom,
    MSF_UINT32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    pmg_inbox_msg_list_req_t param;
    msf_dcvt_t cvt_obj;
    MSF_UINT16 length;
    void *signal_buffer, *user_data;
#else
    pmg_inbox_msg_list_req_t *sig;
#endif   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    param.transID = transID;
    param.msgType = msgType;
    param.isRead = isRead;
    param.isExpired = isExpired;
    param.hasInfo = hasInfo;
    param.startFrom = startFrom;
    param.size = size;

    PMG_SEND_SIGNAL(pmg_cvt_inbox_msg_list_req, PMG_SIG_INBOX_MSG_LIST_REQ, MSF_MODID_PMG, MSF_MODID_PMG);
#else
	sig = MSF_MEM_ALLOC(MSF_MODID_PMG, sizeof(pmg_inbox_msg_list_req_t));

    sig->transID = transID;
    sig->msgType = msgType;
    sig->isRead = isRead;
    sig->isExpired = isExpired;
    sig->hasInfo = hasInfo;
    sig->startFrom = startFrom;
    sig->size = size;

	MSF_SIGNAL_SEND (MSF_MODID_PMG, MSF_MODID_PMG, PMG_SIG_INBOX_MSG_LIST_REQ, sig);
   
#endif
}


/*****************************************************************************
 * FUNCTION
 *  PMGif_inboxGetMsgReq
 * DESCRIPTION
 *  send a PMG_SIG_INBOX_GET_MSG_REQ signal to PMG
 * PARAMETERS
 *  transID             [in]
 *  msgID               [in]
 * RETURNS
 *  void
 *****************************************************************************/
void PMGif_inboxGetMsgReq(int transID, int msgID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    pmg_inbox_get_msg_req_t param;
    msf_dcvt_t cvt_obj;
    MSF_UINT16 length;
    void *signal_buffer, *user_data;
#else
    pmg_inbox_get_msg_req_t *sig;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    param.transID = transID;
    param.msgID = msgID;

    PMG_SEND_SIGNAL(pmg_cvt_inbox_get_msg_req, PMG_SIG_INBOX_GET_MSG_REQ, MSF_MODID_PMG, MSF_MODID_PMG);
#else
	sig = MSF_MEM_ALLOC(MSF_MODID_PMG, sizeof(pmg_inbox_get_msg_req_t));

    sig->transID = transID;
    sig->msgID = msgID;

	MSF_SIGNAL_SEND (MSF_MODID_PMG, MSF_MODID_PMG, PMG_SIG_INBOX_GET_MSG_REQ, sig);
  
#endif
}


/* SKS */
/*****************************************************************************
 * FUNCTION
 *  PMGif_inboxGetReadStatus
 * DESCRIPTION
 *  send a PMG_SIG_INBOX_MSG_READ_STATUS_REQ signal to PMG
 * PARAMETERS
 *  msgID               [in]
 *  status_func		[in]
 * RETURNS
 *  void
 *****************************************************************************/
void PMGif_inboxGetReadStatus(MSF_UINT32 msg_id,srv_wap_push_msg_read_status_func status_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    pmg_inbox_msg_read_status_req_t param;
    msf_dcvt_t cvt_obj;
    MSF_UINT16 length;
    void *signal_buffer, *user_data;
#else
    pmg_inbox_msg_read_status_req_t *sig;
#endif    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    param.msg_id= msg_id;
    param.status_func= (srv_wap_push_msg_read_status_func)status_func;

    PMG_SEND_SIGNAL(pmg_cvt_inbox_msg_read_status_req, PMG_SIG_INBOX_MSG_READ_STATUS_REQ, MSF_MODID_PMG, MSF_MODID_PMG);
#else
	sig = MSF_MEM_ALLOC(MSF_MODID_PMG, sizeof(pmg_inbox_msg_read_status_req_t));

    sig->msg_id= msg_id;
    sig->status_func= (srv_wap_push_msg_read_status_func)status_func;

	MSF_SIGNAL_SEND (MSF_MODID_PMG, MSF_MODID_PMG, PMG_SIG_INBOX_MSG_READ_STATUS_REQ, sig);
   
#endif
}

#ifdef __MMI_PUSH_TURN_ON_OFF_SWITCH__


/*****************************************************************************
 * FUNCTION
 *  PMGif_inboxTurnOnOffPush
 * DESCRIPTION
 * send a signal PMG_SIG_INBOX_PUSH_TURN_ON_OFF_REQ
 * PARAMETERS
 *    push_turn_on_switch (variable)             [in]
 * RETURNS
 *  void
 *****************************************************************************/
void PMGif_inboxTurnOnOffPush(MSF_UINT8 push_turn_on_switch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  pmg_inbox_set_push_turn_on_switch(push_turn_on_switch);


}

#endif /*__MMI_PUSH_TURN_ON_OFF_SWITCH__*/

/* SKS */

/*****************************************************************************
 * FUNCTION
 *  PMGif_inboxGetMsgInfoTagReq
 * DESCRIPTION
 *  send a PMG_SIG_INBOX_GET_MSG_INFOTAG_REQ signal to PMG
 * PARAMETERS
 *  transID                 [in]
 *  msgID                   [in]
 *  startFrom               [in]
 * RETURNS
 *  void
 *****************************************************************************/
void PMGif_inboxGetMsgInfoTagReq(int transID, int msgID, MSF_UINT32 startFrom)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    pmg_inbox_get_msg_infotag_req_t param;
    msf_dcvt_t cvt_obj;
    MSF_UINT16 length;
    void *signal_buffer, *user_data;
#else
    pmg_inbox_get_msg_infotag_req_t *sig;
#endif    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    param.transID = transID;
    param.msgID = msgID;
    param.startFrom = startFrom;

    PMG_SEND_SIGNAL(pmg_cvt_inbox_get_msg_infotag_req, PMG_SIG_INBOX_GET_MSG_INFOTAG_REQ, MSF_MODID_PMG, MSF_MODID_PMG);
#else
	sig = MSF_MEM_ALLOC(MSF_MODID_PMG, sizeof(pmg_inbox_get_msg_infotag_req_t));

    sig->transID = transID;
    sig->msgID = msgID;
    sig->startFrom = startFrom;

	MSF_SIGNAL_SEND (MSF_MODID_PMG, MSF_MODID_PMG, PMG_SIG_INBOX_GET_MSG_INFOTAG_REQ, sig);
  
#endif
}


/*****************************************************************************
 * FUNCTION
 *  PMGif_inboxDeleteMsgReq
 * DESCRIPTION
 *  send a PMG_SIG_INBOX_DELETE_MSG_REQ signal to PMG
 * PARAMETERS
 *  transID             [in]
 *  msgID               [in]
 * RETURNS
 *  void
 *****************************************************************************/
void PMGif_inboxDeleteMsgReq(int transID, int msgID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    pmg_inbox_delete_msg_req_t param;
    msf_dcvt_t cvt_obj;
    MSF_UINT16 length;
    void *signal_buffer, *user_data;
#else
    pmg_inbox_delete_msg_req_t *sig;
#endif   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    param.transID = transID;
    param.msgID = msgID;

    PMG_SEND_SIGNAL(pmg_cvt_inbox_delete_msg_req, PMG_SIG_INBOX_DELETE_MSG_REQ, MSF_MODID_PMG, MSF_MODID_PMG);
#else
	sig = MSF_MEM_ALLOC(MSF_MODID_PMG, sizeof(pmg_inbox_delete_msg_req_t));

    sig->transID = transID;
    sig->msgID = msgID;

	MSF_SIGNAL_SEND (MSF_MODID_PMG, MSF_MODID_PMG, PMG_SIG_INBOX_DELETE_MSG_REQ, sig);
   
#endif
}


/*****************************************************************************
 * FUNCTION
 *  PMGif_inboxDeleteAllReq
 * DESCRIPTION
 *  send a PMG_SIG_INBOX_DELETE_ALL_REQ signal to PMG
 * PARAMETERS
 *  transID             [in]
 *  msgType             [in]
 * RETURNS
 *  void
 *****************************************************************************/
void PMGif_inboxDeleteAllReq(int transID, MSF_UINT8 msgType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    pmg_inbox_delete_all_req_t param;
    msf_dcvt_t cvt_obj;
    MSF_UINT16 length;
    void *signal_buffer, *user_data;
#else
    pmg_inbox_delete_all_req_t *sig;
#endif  

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    param.transID = transID;
    param.msgType = msgType;

    PMG_SEND_SIGNAL(pmg_cvt_inbox_delete_all_req, PMG_SIG_INBOX_DELETE_ALL_REQ, MSF_MODID_PMG, MSF_MODID_PMG);
#else
	sig = MSF_MEM_ALLOC(MSF_MODID_PMG, sizeof(pmg_inbox_delete_all_req_t));

    sig->transID = transID;
    sig->msgType = msgType;

	MSF_SIGNAL_SEND (MSF_MODID_PMG, MSF_MODID_PMG, PMG_SIG_INBOX_DELETE_ALL_REQ, sig);
   
#endif
}


/*****************************************************************************
 * FUNCTION
 *  PMGif_inboxUpdateMsgReq
 * DESCRIPTION
 *  send a PMG_SIG_INBOX_UPDATE_MSG_REQ signal to PMG
 * PARAMETERS
 *  transID             [in]
 *  msgID               [in]
 *  read                [in]
 * RETURNS
 *  void
 *****************************************************************************/
void PMGif_inboxUpdateMsgReq(int transID, int msgID, MSF_UINT8 read)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    pmg_inbox_update_msg_req_t param;
    msf_dcvt_t cvt_obj;
    MSF_UINT16 length;
    void *signal_buffer, *user_data;
#else
    pmg_inbox_update_msg_req_t *sig;
#endif    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    param.transID = transID;
    param.msgID = msgID;
    param.read = read;

    PMG_SEND_SIGNAL(pmg_cvt_inbox_update_msg_req, PMG_SIG_INBOX_UPDATE_MSG_REQ, MSF_MODID_PMG, MSF_MODID_PMG);
#else
	sig = MSF_MEM_ALLOC(MSF_MODID_PMG, sizeof(pmg_inbox_update_msg_req_t));

    sig->transID = transID;
    sig->msgID = msgID;
    sig->read = read;

	MSF_SIGNAL_SEND (MSF_MODID_PMG, MSF_MODID_PMG, PMG_SIG_INBOX_UPDATE_MSG_REQ, sig);
  
#endif
}

/*****************************************************************************
 * FUNCTION
 *  PMGif_inboxUpdateAllMsgReq
 * DESCRIPTION
 *  send a PMG_SIG_INBOX_UPDATE_ALL_MSG_REQ signal to PMG
 * PARAMETERS
 *  transID             [in]
 *  read                [in]
 * RETURNS
 *  void
 *****************************************************************************/
void PMGif_inboxUpdateAllMsgReq(MSF_UINT8 read)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    pmg_inbox_update_all_msg_req_t param;
    msf_dcvt_t cvt_obj;
    MSF_UINT16 length;
    void *signal_buffer, *user_data;
#else
    pmg_inbox_update_all_msg_req_t *sig;
#endif    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
       param.read = read;

    PMG_SEND_SIGNAL(pmg_cvt_inbox_update_all_msg_req, PMG_SIG_INBOX_UPDATE_ALL_MSG_REQ, MSF_MODID_PMG, MSF_MODID_PMG);
#else
    sig = MSF_MEM_ALLOC(MSF_MODID_PMG, sizeof(pmg_inbox_update_all_msg_req_t));
    sig->read = read;

    	MSF_SIGNAL_SEND (MSF_MODID_PMG, MSF_MODID_PMG, PMG_SIG_INBOX_UPDATE_ALL_MSG_REQ, sig);
   
#endif
}

/*****************************************************************************
 * FUNCTION
 *  PMGif_inboxNewMsgRsp
 * DESCRIPTION
 *  send a PMG_SIG_INBOX_NEW_MSG_RSP signal to PMG
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PMGif_inboxNewMsgRsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    void *signal_buffer;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    signal_buffer = MSF_SIGNAL_CREATE(PMG_SIG_INBOX_NEW_MSG_RSP, MSF_MODID_PMG, MSF_MODID_PMG, 0);
    if (signal_buffer != NULL)
        MSF_SIGNAL_SEND(signal_buffer);
#else
	MSF_SIGNAL_SEND (MSF_MODID_PMG, MSF_MODID_PMG, PMG_SIG_INBOX_NEW_MSG_RSP, 0);
#endif
}

#ifdef PHS_CFG_PUSH_WHITELIST_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  PMGif_inboxSetAuthListReq
 * DESCRIPTION
 *  send a PMG_SIG_INBOX_AUTH_ADDR_LIST_REQ signal to PMG
 * PARAMETERS
 *  transID             [in]
 *  type                [in]
 *  segment             [in]
 *  size                [in]
 *  addrs               [in]
 *  total_segment		[in]
 * RETURNS
 *  void
 *****************************************************************************/
void PMGif_inboxSetAuthListReq(int transID, pmg_auth_list_type type, int segment, int size, int addrs, int total_segment)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    pmg_inbox_auth_addr_list_req_t param;
    msf_dcvt_t cvt_obj;
    MSF_UINT16 length;
    void *signal_buffer, *user_data;
#else
    pmg_inbox_auth_addr_list_req_t *sig;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    param.transID = transID;
    param.type = type;
    param.segment = segment;
    param.size = size;
    param.addrs = addrs;
	param.total_segment = total_segment;
    PMG_SEND_SIGNAL(pmg_cvt_inbox_auth_addr_list_req, PMG_SIG_INBOX_AUTH_ADDR_LIST_REQ, MSF_MODID_PMG, MSF_MODID_PMG);
#else
	sig = MSF_MEM_ALLOC(MSF_MODID_PMG, sizeof(pmg_inbox_auth_addr_list_req_t));

    sig->transID = transID;
    sig->type = type;
    sig->segment = segment;
    sig->size = size;
    sig->addrs = addrs;
	sig->total_segment = total_segment;

	MSF_SIGNAL_SEND (MSF_MODID_PMG, MSF_MODID_PMG, PMG_SIG_INBOX_AUTH_ADDR_LIST_REQ, sig);
  
#endif
}
#endif

/*****************************************************************************
 * FUNCTION
 *  PMGif_inboxDialogResponse
 * DESCRIPTION
 *  send a PMG_SIG_INBOX_DLG_RESPONSE signal to PMG
 * PARAMETERS
 *  type                [in]
 *  result              [in]
 * RETURNS
 *  void
 *****************************************************************************/
void PMGif_inboxDialogResponse(int type, kal_uint32 id, int result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    pmg_inbox_dlg_response_t param;
    msf_dcvt_t cvt_obj;
    MSF_UINT16 length;
    void *signal_buffer, *user_data;
#else
    pmg_inbox_dlg_response_t *sig;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    param.type = type;
    param.id = id;
    param.result = result;

    PMG_SEND_SIGNAL(pmg_cvt_inbox_dlg_response, PMG_SIG_INBOX_DLG_RESPONSE, MSF_MODID_PMG, MSF_MODID_PMG);
#else
	sig = MSF_MEM_ALLOC(MSF_MODID_PMG, sizeof(pmg_inbox_dlg_response_t));

    sig->type = type;
    sig->id = id;
    sig->result = result;

	MSF_SIGNAL_SEND (MSF_MODID_PMG, MSF_MODID_PMG, PMG_SIG_INBOX_DLG_RESPONSE, sig);
  
#endif
}


/*****************************************************************************
 * FUNCTION
 *  PMGif_inboxDialogQueryReq
 * DESCRIPTION
 *  send a PMG_SIG_INBOX_DLG_QUERY signal to PMG
 * PARAMETERS
 *  type                [in]
 *  result              [in]
 * RETURNS
 *  void
 *****************************************************************************/
void PMGif_inboxDialogQueryReq(int transID, int dlgID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    pmg_inbox_dlg_query_req_t param;
    msf_dcvt_t cvt_obj;
    MSF_UINT16 length;
    void *signal_buffer, *user_data;
#else
    pmg_inbox_dlg_query_req_t *sig;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    param.transID = transID;
    param.dlgID = dlgID;

    PMG_SEND_SIGNAL(pmg_cvt_inbox_dlg_query_req, PMG_SIG_INBOX_DLG_QUERY_REQ, MSF_MODID_PMG, MSF_MODID_PMG);
#else
	sig = MSF_MEM_ALLOC(MSF_MODID_PMG, sizeof(pmg_inbox_dlg_query_req_t));


    sig->transID = transID;
    sig->dlgID = dlgID;

	MSF_SIGNAL_SEND (MSF_MODID_PMG, MSF_MODID_PMG, PMG_SIG_INBOX_DLG_QUERY_REQ, sig);
 
#endif
}

#ifdef __MMI_PUSH_IN_UM__
/*****************************************************************************
 * FUNCTION
 *  PMGif_umGetMsgNumReq
 * DESCRIPTION
 *  send a PMG_SIG_UM_GET_MSG_NUM_REQ signal to PMG
 * PARAMETERS
 *  msgType             [in]
 * RETURNS
 *  void
 *****************************************************************************/
void PMGif_umGetMsgNumReq(MSF_UINT8 msgType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    pmg_um_get_msg_num_req_t param;
    msf_dcvt_t cvt_obj;
    MSF_UINT16 length;
    void *signal_buffer, *user_data;
#else
    pmg_um_get_msg_num_req_t *sig;
#endif    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    param.msgType = msgType;

    PMG_SEND_SIGNAL(pmg_cvt_um_get_msg_num_req, PMG_SIG_UM_GET_MSG_NUM_REQ, MSF_MODID_PMG, MSF_MODID_PMG);
#else
	sig = MSF_MEM_ALLOC(MSF_MODID_PMG, sizeof(pmg_um_get_msg_num_req_t));

    sig->msgType = msgType;

	MSF_SIGNAL_SEND (MSF_MODID_PMG, MSF_MODID_PMG, PMG_SIG_UM_GET_MSG_NUM_REQ, sig);
  
#endif
}


/*****************************************************************************
 * FUNCTION
 *  PMGif_umGetListReq
 * DESCRIPTION
 *  send a PMG_SIG_UM_GET_LIST_REQ signal to PMG
 * PARAMETERS
 *  msgType                 [in]
 *  startFrom               [in]
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
	void PMGif_umGetListReq(MSF_UINT8 msgType, MSF_UINT32 startFrom, MSF_UINT8 idxType ,MSF_UINT32 sim_id)
#else
	void PMGif_umGetListReq(MSF_UINT8 msgType, MSF_UINT32 startFrom, MSF_UINT32 sim_id)
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    pmg_um_get_list_req_t param;
    msf_dcvt_t cvt_obj;
    MSF_UINT16 length;
    void *signal_buffer, *user_data;
#else
    pmg_um_get_list_req_t *sig;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__

    param.msgType = msgType;
    param.startFrom = startFrom;
#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
    param.idxType = idxType;
#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */

	param.sim_id = sim_id;

    PMG_SEND_SIGNAL(pmg_cvt_um_get_list_req, PMG_SIG_UM_GET_LIST_REQ, MSF_MODID_PMG, MSF_MODID_PMG);
#else
		sig = MSF_MEM_ALLOC(MSF_MODID_PMG, sizeof(pmg_um_get_list_req_t)); 

		sig->msgType = msgType;
		sig->startFrom = startFrom;
	#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
		sig->idxType = idxType;
	#endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */

		sig->sim_id = sim_id;

		MSF_SIGNAL_SEND (MSF_MODID_PMG, MSF_MODID_PMG, PMG_SIG_UM_GET_LIST_REQ, sig);
   
#endif /*__OBIGO_FRMW2__*/
}


#ifdef WPS_PMG_CONVERSATION_BOX

/*****************************************************************************
 * FUNCTION
 *  PMGif_umGetTraverseListReq
 * DESCRIPTION
 *  send a PMG_SIG_UM_GET_TRAVERSE_LIST_REQ signal to PMG
 * PARAMETERS
 *  msgType                 [in]
 *  startFrom               [in]
 * RETURNS
 *  void
 *****************************************************************************/

void PMGif_umGetTraverseListReq(MSF_UINT8 msgType, MSF_INT16 startFrom, srv_um_traverse_func traverse_func, MSF_UINT32 pid, MSF_UINT32 app_id, MSF_UINT32 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    pmg_um_get_traverse_list_req_t param;
    msf_dcvt_t cvt_obj;
    MSF_UINT16 length;
    void *signal_buffer, *user_data;
#else
    pmg_um_get_traverse_list_req_t *sig;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    param.msgType = msgType;
    param.startFrom = startFrom;
	param.pid = pid;
	param.app_id = app_id;
	param.sim_id = sim_id;
	param.traverse_func = (srv_um_traverse_func)traverse_func;
    PMG_SEND_SIGNAL(pmg_cvt_um_get_traverse_list_req, PMG_SIG_UM_GET_TRAVERSE_LIST_REQ, MSF_MODID_PMG, MSF_MODID_PMG);
#else
	sig = MSF_MEM_ALLOC(MSF_MODID_PMG, sizeof(pmg_um_get_traverse_list_req_t)); 
   
	sig->msgType = msgType;
    sig->startFrom = startFrom;
	sig->pid = pid;
	sig->app_id = app_id;
	sig->sim_id = sim_id;
	sig->traverse_func = (srv_um_traverse_func)traverse_func;

	MSF_SIGNAL_SEND (MSF_MODID_PMG, MSF_MODID_PMG, PMG_SIG_UM_GET_TRAVERSE_LIST_REQ, sig);

#endif
}
#endif /* WPS_PMG_CONVERSATION_BOX */

/*****************************************************************************
 * FUNCTION
 *  PMGif_umGetMsgInfoReq
 * DESCRIPTION
 *  send a PMG_SIG_UM_GET_MSG_INFO_REQ signal to PMG
 * PARAMETERS
 *  msgType                 [in]
 *  msgNumber               [in]
 *  msgIDs                  [in]
 * RETURNS
 *  void
 *****************************************************************************/
void PMGif_umGetMsgInfoReq(MSF_UINT8 msgType, MSF_UINT16 msgNumber, MSF_UINT32 *msgIDs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    pmg_um_get_msg_info_req_t param;
    msf_dcvt_t cvt_obj;
    MSF_UINT16 length;
    void *signal_buffer, *user_data;
#else
    pmg_um_get_msg_info_req_t *sig;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    param.msgType = msgType;
    param.msgNumber = msgNumber;
    param.msgIDs = msgIDs;

    PMG_SEND_SIGNAL(pmg_cvt_um_get_msg_info_req, PMG_SIG_UM_GET_MSG_INFO_REQ, MSF_MODID_PMG, MSF_MODID_PMG);
#else
	sig = MSF_MEM_ALLOC(MSF_MODID_PMG, sizeof(pmg_um_get_msg_info_req_t)); 
	memset(sig, 0, sizeof(pmg_um_get_msg_info_req_t)); // recommended if signal has internal pointers.

    sig->msgType = msgType;
    sig->msgNumber = msgNumber;
	sig->msgIDs =(MSF_UINT32 *)msf_cmmn_memndup (MSF_MODID_PMG, msgIDs, msgNumber*sizeof(MSF_UINT32)); // copies string in destination
  
	MSF_SIGNAL_SEND (MSF_MODID_PMG, MSF_MODID_PMG, PMG_SIG_UM_GET_MSG_INFO_REQ, sig);
   
#endif
}


/*****************************************************************************
 * FUNCTION
 *  PMGif_umDeleteFolderReq
 * DESCRIPTION
 *  send a PMG_SIG_UM_DELETE_FOLDER_REQ signal to PMG
 * PARAMETERS
 *  msgType             [in]
 * RETURNS
 *  void
 *****************************************************************************/
void PMGif_umDeleteFolderReq(MSF_UINT8 msgType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    pmg_um_delete_folder_req_t param;
    msf_dcvt_t cvt_obj;
    MSF_UINT16 length;
    void *signal_buffer, *user_data;
#else
    pmg_um_delete_folder_req_t *sig;
#endif  

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    param.msgType = msgType;

    PMG_SEND_SIGNAL(pmg_cvt_um_delete_folder_req, PMG_SIG_UM_DELETE_FOLDER_REQ, MSF_MODID_PMG, MSF_MODID_PMG);
#else
	sig = MSF_MEM_ALLOC(MSF_MODID_PMG, sizeof(pmg_um_delete_folder_req_t)); 
    sig->msgType = msgType;

	MSF_SIGNAL_SEND (MSF_MODID_PMG, MSF_MODID_PMG, PMG_SIG_UM_DELETE_FOLDER_REQ, sig);
   
#endif
}


/*****************************************************************************
 * FUNCTION
 *  PMGif_umMultiOpReq
 * DESCRIPTION
 *  send a PMG_SIG_UM_MULTI_OP_REQ signal to PMG
 * PARAMETERS
 *  action                  [in]
 *  msgNumber               [in]
 *  msgIDs                  [in]
 * RETURNS
 *  void
 *****************************************************************************/
void PMGif_umMultiOpReq(MSF_UINT8 action, MSF_UINT32 msgNumber, MSF_UINT32 *msgIDs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    pmg_um_multi_op_req_t param;
    msf_dcvt_t cvt_obj;
    MSF_UINT16 length;
    void *signal_buffer, *user_data;
#else
    pmg_um_multi_op_req_t *sig;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    param.action = action;
    param.msgNumber = msgNumber;
    param.msgIDs = msgIDs;

    PMG_SEND_SIGNAL(pmg_cvt_um_multi_op_req, PMG_SIG_UM_MULTI_OP_REQ, MSF_MODID_PMG, MSF_MODID_PMG);
#else
	sig = MSF_MEM_ALLOC(MSF_MODID_PMG, sizeof(pmg_um_multi_op_req_t)); 
	memset(sig, 0, sizeof(pmg_um_multi_op_req_t)); // recommended if signal has internal pointers.

    sig->action = action;
    sig->msgNumber = msgNumber;
	sig->msgIDs = (MSF_UINT32 *)msf_cmmn_memndup (MSF_MODID_PMG, msgIDs,msgNumber*sizeof(MSF_UINT32)); // copies string in destination  memory.

	MSF_SIGNAL_SEND (MSF_MODID_PMG, MSF_MODID_PMG, PMG_SIG_UM_MULTI_OP_REQ, sig);
  
#endif
}
#endif /* __MMI_PUSH_IN_UM__ */
/*****************************************************************************
 ****************** Exported Message info handling Functions *****************
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  pmg_lib_cvt_text
 * DESCRIPTION
 *  Convert to PMG SI message's text using PMG memory
 * PARAMETERS
 *  text                [in]
 * RETURNS
 *  char *
 *****************************************************************************/
char *pmg_lib_cvt_text(const char *text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *str = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (text)
    {
        str = pmg_utf8_strndup(text, PMG_MAX_MSG_TEXT_CHARS);
    }
    return str;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_lib_cvt_href
 * DESCRIPTION
 *  Convert to PMG message's href parameter using PMG memory
 * PARAMETERS
 *  href                [in]
 * RETURNS
 *  char *
 *****************************************************************************/
char *pmg_lib_cvt_href(const char *href)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *str = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (href)
    {
        str = msf_cmmn_strndup(MSF_MODID_PMG, href, PMG_MAX_MSG_HREF_CHARS);
    }
    return str;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_lib_cvt_addr
 * DESCRIPTION
 *  Convert to PMG message's address using PMG memory
 * PARAMETERS
 *  href                [in]
 * RETURNS
 *  char *
 *****************************************************************************/
char *pmg_lib_cvt_addr(const char *addr, MSF_INT16 addrLen, MSF_UINT8 addrType, MSF_UINT8 has_num_plan)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *str = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (addr)
    {
        pmg_msg_convert_addr_to_string(&str, addr, addrLen, addrType, has_num_plan);
    }
    return str;
}


int
pmg_lib_extract_address(msf_sockaddr_t *sockaddr, char **oa, MSF_UINT16 *oalen, char **sc, MSF_UINT16 *sclen)
{
  char *iter;

  if (sockaddr->type != MSF_SOCKADDR_TYPE_SMS)
    return 0;

  *oalen = *sclen = 0;
  *sc = 0;

  iter = (char*)(sockaddr->addr);
  *oa = iter;
  while (*iter != (char)0xFF) {
    iter++;
    (*oalen)++;
  }

  iter++;
  *sc = iter;
  while (*iter != (char)0xFF) {
    iter++;
    (*sclen)++;
  }

  return 1;
}

/*****************************************************************************
 ******************** Exported Message Creation Functions ********************
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  pmg_lib_new_msg
 * DESCRIPTION
 *  create a new PMG message object
 * PARAMETERS
 *  void
 * RETURNS
 *  message object pointer
 *****************************************************************************/
pmg_full_msg_t *pmg_lib_new_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_full_msg_t *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = pmg_mem_alloc(sizeof(pmg_full_msg_t));
    memset(msg, 0, sizeof(pmg_full_msg_t));

    return msg;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_lib_release_msg
 * DESCRIPTION
 *  release the PMG message object
 * PARAMETERS
 *  msg          [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_lib_release_msg(pmg_full_msg_t *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pmg_fs_release_msg_data(msg);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_lib_msg_set_created
 * DESCRIPTION
 *  set message's created time
 * PARAMETERS
 *  msg                 [in]
 *  created             [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_lib_msg_set_created(pmg_full_msg_t *msg, MSF_UINT32 created)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg->created = created;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_lib_msg_set_expired
 * DESCRIPTION
 *  set message's expiration time
 * PARAMETERS
 *  msg                 [in]
 *  expired             [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_lib_msg_set_expired(pmg_full_msg_t *msg, MSF_UINT32 expired)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg->expired = expired;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_lib_msg_set_msgType
 * DESCRIPTION
 *  set message type
 * PARAMETERS
 *  msg                  [in]
 *  msgType             [in]    {PMG_MSGTYPE_SI, PMG_MSGTYPE_SL}
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_lib_msg_set_msgType(pmg_full_msg_t *msg, MSF_UINT8 msgType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg->msgType = msgType;
}

/*****************************************************************************
 * FUNCTION
 *  pmg_lib_msg_get_msgType
 * DESCRIPTION
 *  set message type
 * PARAMETERS
 *  msg                  [in]
 *  msgType             [in]    {PMG_MSGTYPE_SI, PMG_MSGTYPE_SL}
 * RETURNS
 *  void
 *****************************************************************************/
int pmg_lib_msg_get_msgType(int msfMimeInt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(msfMimeInt)
    {
    case MSF_MIME_TYPE_TEXT_VND_WAP_SI:
    case MSF_MIME_TYPE_APPLICATION_VND_WAP_SIC:
        return PMG_MSGTYPE_SI;
    case MSF_MIME_TYPE_TEXT_VND_WAP_SL:
    case MSF_MIME_TYPE_APPLICATION_VND_WAP_SLC:
        return PMG_MSGTYPE_SL;
    case MSF_MIME_TYPE_TEXT_VND_WAP_CO:
    case MSF_MIME_TYPE_APPLICATION_VND_WAP_COC:
        return WAP_PMG_MSGTYPE_CO;
    case MSF_MIME_TYPE_APPLICATION_VND_WAP_SIA:
        return WAP_PMG_MSGTYPE_SIA;
    default:
        return WAP_PMG_MSGTYPE_NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  pmg_lib_msg_set_priority
 * DESCRIPTION
 *  set message's priority
 * PARAMETERS
 *  msg                     [in]
 *  priority                [in]    {PMG_MSGPRIO_LOW, PMG_MSGPRIO_MEDIUM, PMG_MSGPRIO_HIGH}
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_lib_msg_set_priority(pmg_full_msg_t *msg, MSF_UINT8 priority)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg->priority = priority;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_lib_msg_set_read
 * DESCRIPTION
 *  set message's "read" flag
 * PARAMETERS
 *  msg                 [in]
 *  read                [in]    {0: unread, 1: read}
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_lib_msg_set_read(pmg_full_msg_t *msg, MSF_UINT8 read)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg->read = read;
}

/*****************************************************************************
 * FUNCTION
 *  pmg_lib_msg_set_sim_id
 * DESCRIPTION
 *  set message's sim_id  flag
 * PARAMETERS
 *  msg                 [in]
 *  sim_id                [in]    {0: , 1: }
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_lib_msg_set_sim_id(pmg_full_msg_t *msg, MSF_UINT32 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg->sim_id = sim_id;
}

/*****************************************************************************
 * FUNCTION
 *  pmg_lib_msg_set_siid
 * DESCRIPTION
 *  set SI message's siid
 * PARAMETERS
 *  msg                 [in]
 *  siid                [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_lib_msg_set_siid(pmg_full_msg_t *msg, const char *siid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg->siid)
        PMG_MEM_FREE(msg->siid);

    msg->siid = 0;
    if (siid)
        msg->siid = msf_cmmn_strndup(MSF_MODID_PMG, siid, PMG_MAX_MSG_SIID_CHARS);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_lib_msg_set_text
 * DESCRIPTION
 *  set SI message's text
 * PARAMETERS
 *  msg                 [in]
 *  text                [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_lib_msg_set_text(pmg_full_msg_t *msg, const char *text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg->text)
        PMG_MEM_FREE(msg->text);

    msg->text = 0;
    msg->text = pmg_lib_cvt_text(text);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_lib_msg_log_address
 * DESCRIPTION
 *  log address to Catcher for debugging purpose
 * PARAMETERS
 *  addr                [in]
 *  addrLen             [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_lib_msg_log_address(const char *addr, MSF_INT16 addrLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char log[120];
    char tmp[4];
    MSF_INT16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(log, 0, 120);
    for (i = 0; i < addrLen; i++)
    {
        memset(tmp, 0, 4);
        sprintf(tmp, "%X ", (MSF_UINT8) addr[i]);
        strcat(log, tmp);
    }

    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_IF_B124E7202AD3A86B2E323C3DD0477559,
                      "PMG: pmg_lib_msg_log_address(%s)\n", log));
}


/*****************************************************************************
 * FUNCTION
 *  pmg_lib_msg_set_smsc
 * DESCRIPTION
 *  set message's Short Message Service Centre address
 * PARAMETERS
 *  msg                     [in]
 *  smsc                    [in]
 *  addrLen                 [in]
 *  addrType                [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_lib_msg_set_smsc(pmg_full_msg_t *msg, const char *smsc, MSF_INT16 addrLen, MSF_UINT8 addrType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_IF_5ADC8D6383BBCC9E6E5A60FA3E51F4F9,
                      "PMG: pmg_lib_msg_set_smsc(type=%d)\n", addrType));
    pmg_lib_msg_log_address(smsc, addrLen);

    msg->smsc = pmg_lib_cvt_addr(smsc, addrLen, addrType, 1);
    msg->smscType = addrType;
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_IF_852CACFA7B546C1BF9358701E4D8CB98, "PMG: smsc: %s\n",
                      msg->smsc));
}


/*****************************************************************************
 * FUNCTION
 *  pmg_lib_msg_set_from
 * DESCRIPTION
 *  set message's Originating Address
 * PARAMETERS
 *  msg                     [in]
 *  from                    [in]
 *  addrLen                 [in]
 *  addrType                [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_lib_msg_set_from(pmg_full_msg_t *msg, const char *from, MSF_INT16 addrLen, MSF_UINT8 addrType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_IF_101FCAC0C176FFB02084F28A36F65B4A,
                      "PMG: pmg_lib_msg_set_from(type=%d)\n", addrType));
    pmg_lib_msg_log_address(from, addrLen);

    msg->from = pmg_lib_cvt_addr(from, addrLen, addrType, 1);
    msg->fromType = addrType;
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_PMG, PMG_IF_DAE2610029F0CF3897139CE9C0ADA845, "PMG: from: %s\n",
                      msg->from));
}


/*****************************************************************************
 * FUNCTION
 *  pmg_lib_msg_set_href
 * DESCRIPTION
 *  set message's href parameter
 * PARAMETERS
 *  msg                 [in]
 *  href                [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_lib_msg_set_href(pmg_full_msg_t *msg, const char *href)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg->href)
        PMG_MEM_FREE(msg->href);

    msg->href = 0;
    msg->href = pmg_lib_cvt_href(href);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_lib_msg_add_infoitem
 * DESCRIPTION
 *  add INFO to SI message
 * PARAMETERS
 *  msg                  [in]
 *  infoClass            [in]
 *  infoText             [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_lib_msg_add_infoitem(pmg_full_msg_t *msg, char *infoClass, char *infoText)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_fs_msg_file_infoitem_t *infoitem;
    pmg_fs_msg_file_infoitem_t *crt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    infoitem = pmg_mem_alloc(sizeof(pmg_fs_msg_file_infoitem_t));
    memset(infoitem, 0, sizeof(pmg_fs_msg_file_infoitem_t));
    infoitem->next = 0;
    infoitem->infoClass = msf_cmmn_strndup(MSF_MODID_PMG, infoClass, PMG_MAX_INFOITEM_CLASS_CHARS);
    infoitem->infoText = msf_cmmn_strndup(MSF_MODID_PMG, infoText, PMG_MAX_INFOITEM_TEXT_CHARS);

    if (!(msg->infoitems))
    {
        msg->infoitems = infoitem;
        msg->numInfoItems = 1;
    }
    else
    {
        crt = msg->infoitems;
        while (crt->next)
            crt = crt->next;
        crt->next = infoitem;
        msg->numInfoItems++;
    }
}

/*****************************************************************************
 **************** Exported Dialog Display Requests Functions *****************
 *****************************************************************************/

#ifdef PHS_CFG_PUSH_SLIM_SUPPORT  
/*****************************************************************************
 * FUNCTION
 *  pmg_lib_new_dlg_display_req
 * DESCRIPTION
 *  create a new dialog display request object
 * PARAMETERS
 *  void
 * RETURNS
 *  dialog display request object pointer
 *****************************************************************************/
pmg_dlg_display_req_t *pmg_lib_new_dlg_display_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return pmg_inbox_new_dlg_display_req();
}


/*****************************************************************************
 * FUNCTION
 *  pmg_lib_new_dlg_display_req
 * DESCRIPTION
 *  create a new dialog display request object
 * PARAMETERS
 *  void
 * RETURNS
 *  dialog display request object pointer
 *****************************************************************************/
void pmg_lib_release_dlg_display_req(pmg_dlg_display_req_t *dlgreq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pmg_inbox_release_dlg_display_req(dlgreq);
}

/*****************************************************************************
 * FUNCTION
 *  PMGif_displayDialog
 * DESCRIPTION
 *  request MMI to display the specified dialog
 * PARAMETERS
 *  dlgRequest           [in]
 * RETURNS
 *  void
 *****************************************************************************/
void PMGif_displayDialog(pmg_dlg_display_req_t *dlgRequest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    pmg_display_dialog_req_t param;
    msf_dcvt_t cvt_obj;
    MSF_UINT16 length;
    void *signal_buffer, *user_data;
#else
    pmg_display_dialog_req_t *sig;
#endif   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    param.dlg_request = (int)dlgRequest;
    PMG_SEND_SIGNAL(pmg_cvt_display_dialog_req, PMG_SIG_DISPLAY_DIALOG_REQ, MSF_MODID_PMG, MSF_MODID_PMG);
#else
	sig = MSF_MEM_ALLOC(MSF_MODID_PMG, sizeof(pmg_display_dialog_req_t));
  
	sig->dlg_request = (int)dlgRequest;
	MSF_SIGNAL_SEND (MSF_MODID_PMG, MSF_MODID_PMG, PMG_SIG_DISPLAY_DIALOG_REQ, sig);
    
#endif
}
#endif
/*****************************************************************************
 * FUNCTION
 *  PMGif_contentDataRoute
 * DESCRIPTION
 *  send a PMG_SIG_CONTENT_DATA_ROUTE signal to PMG
 * PARAMETERS
 *  modid               [in]
 *  msg                 [in]
 * RETURNS
 *  void
 *****************************************************************************/
void PMGif_contentDataRoute(MSF_UINT8 src_modId, pmg_content_send_t* send)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    MSF_UINT16           length;
	void                 *buffer, *user_data;
	msf_dcvt_t           cvt_obj;
#else
	pmg_content_send_t *sig;
#endif


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __OBIGO_FRMW2__
    msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
    //msf_cvt_content_send (&cvt_obj, send);
	pmg_cvt_content_send (&cvt_obj, send);
    length = (MSF_UINT16)cvt_obj.pos;

    buffer = MSF_SIGNAL_CREATE (PMG_SIG_CONTENT_DATA_ROUTE_REQ, src_modId, MSF_MODID_PMG, length);
    if (buffer != NULL)
	{
		user_data = MSF_SIGNAL_GET_USER_DATA (buffer, &length);
		msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, src_modId);
		pmg_cvt_content_send (&cvt_obj, send);
		MSF_SIGNAL_SEND (buffer);
	}
#else
	sig = MSF_MEM_ALLOC(MSF_MODID_PMG, sizeof(pmg_content_send_t));
	memset(sig, 0, sizeof(pmg_content_send_t)); // recommended if signal has internal pointers.

	sig->destModId = send->destModId;
	sig->sendAck = send->sendAck;
	sig->id = send->id;
	sig->contentDataExists = send->contentDataExists;
	sig->startOptions = msf_cmmn_strdup(MSF_MODID_PMG, send->startOptions); // copies string in destination's memory.

	sig->contentData = MSF_MEM_ALLOC(MSF_MODID_PMG, sizeof(pmg_content_data_t));
	memset(sig->contentData, 0, sizeof(pmg_content_data_t)); // recommended if signal has internal pointers.

	sig->contentData->routingFormat = send->contentData->routingFormat;
	sig->contentData->contentDataType = send->contentData->contentDataType;
	sig->contentData->contentDRMDataExists = send->contentData->contentDRMDataExists;			 
	sig->contentData->routingIdentifier = msf_cmmn_strdup(MSF_MODID_PMG, send->contentData->routingIdentifier); // copies string in destination's memory.
	sig->contentData->contentUrl = msf_cmmn_strdup(MSF_MODID_PMG, send->contentData->contentUrl); // copies string in destination's memory.
	sig->contentData->contentSource = msf_cmmn_strdup(MSF_MODID_PMG, send->contentData->contentSource); // copies string in destination's memory.
	sig->contentData->contentParameters = msf_cmmn_strdup(MSF_MODID_PMG, send->contentData->contentParameters); // copies string in destination's memory.
	sig->contentData->contentHeaders = msf_cmmn_strdup(MSF_MODID_PMG, send->contentData->contentHeaders); // copies string in destination's memory.
	sig->contentData->contentData = msf_cmmn_memndup(MSF_MODID_PMG, send->contentData->contentData,send->contentData->contentDataLength); // copies string in destination's memory.
	sig->contentData->auxTypeIdentifier = msf_cmmn_strdup(MSF_MODID_PMG, send->contentData->auxTypeIdentifier); // copies string in destination's memory.
	sig->contentData->attrString = msf_cmmn_memndup(MSF_MODID_PMG,send->contentData->attrString,WAP_PHS_MAX_ADDR_CHARS);
	sig->contentData->networkAccountId = send->contentData->networkAccountId;
	sig->contentData->contentDataLength = send->contentData->contentDataLength;
	sig->contentData->attrLength = send->contentData->attrLength;

	sig->contentData->contentDRMData = MSF_MEM_ALLOC(MSF_MODID_PMG, sizeof(pmg_content_drm_data_t));
	memset(sig->contentData->contentDRMData, 0, sizeof(pmg_content_drm_data_t)); // recommended if signal has internal pointers.
	if(send->contentData->contentDRMData!=NULL)
	{
	sig->contentData->contentDRMData->drmDataLength = send->contentData->contentDRMData->drmDataLength;
	sig->contentData->contentDRMData->drmContentHeaders = msf_cmmn_strdup(MSF_MODID_PMG, send->contentData->contentDRMData->drmContentHeaders); // copies string in destination's memory.
	sig->contentData->contentDRMData->drmData = msf_cmmn_strdup(MSF_MODID_PMG, send->contentData->contentDRMData->drmData); // copies string in destination's memory.
	}
    MSF_SIGNAL_SEND (src_modId, MSF_MODID_PMG, PMG_SIG_CONTENT_DATA_ROUTE_REQ, sig);

  
#endif
}


int
PMGif_getProfileInfo(MSF_UINT32 sim_id, wps_pmg_channel_struct *ch_info) 
{
/* here push api will be called for network account id */
	extern void srv_wap_push_get_profile_info(U16 sim_id,wps_pmg_channel_struct * ch_info); 
	srv_wap_push_get_profile_info ((U16) sim_id, ch_info);
	ch_info->network_account_id = cbm_set_app_id(ch_info->network_account_id, g_pmg_app_id);
	return TRUE;

}
int pmg_cvt_content_send(msf_dcvt_t *obj,pmg_content_send_t *p)
{
	if (!msf_dcvt_uint8 (obj, &(p->destModId)) ||
      !msf_dcvt_uint8 (obj, &(p->sendAck)) ||
      !msf_dcvt_uint8 (obj, &(p->id)) ||
      !msf_dcvt_string (obj, &(p->startOptions)) ||
      !msf_dcvt_uint8 (obj, &(p->contentDataExists)) ||
      !msf_dcvt_array (obj, sizeof (pmg_content_data_t), p->contentDataExists,
                       (void **)&(p->contentData), (msf_dcvt_element_t *)pmg_cvt_content_data)) {
    return FALSE;
  }
  return TRUE;
}


int pmg_cvt_set_data_to_phs_setting(msf_dcvt_t *obj, pmg_phs_setting_data_t *p)
{
  if (!msf_dcvt_uint16 (obj, (MSF_UINT16*) &(p->security_level)) ||
      !msf_dcvt_uint16 (obj, (MSF_UINT16*) &(p->support_SIR)) ||
      !msf_dcvt_uint16 (obj, (MSF_UINT16*) &(p->support_SL)) ||
	  !msf_dcvt_uint16 (obj, (MSF_UINT16*) &(p->whitelist_disable)) ||
	  !msf_dcvt_uint16 (obj, (MSF_UINT16*) &(p->blacklist_enable)) ||
	  !msf_dcvt_uint16 (obj, (MSF_UINT16*) &(p->whitelist_behavior)))

  {
    return FALSE;
  }

  return TRUE;
}

int pmg_cvt_data_list(msf_dcvt_t *obj, pmg_phs_list_data_t *p)
{
  if (!msf_dcvt_string (obj, &(p->file_name))||
	  !msf_dcvt_uint8 (obj, &(p->list_type)))
  {
    return FALSE;
  }
  return TRUE;
}


int pmg_cvt_temp_data_list(msf_dcvt_t *obj, pmg_phs_temp_t *p)
{
  if (!msf_dcvt_string (obj, &(p->file_name)))
  {
    return FALSE;
  }
  return TRUE;
}

int pmg_cvt_set_def_con(msf_dcvt_t *obj, pmg_phs_def_con *p)
{
  if (!msf_dcvt_uint16 (obj, (MSF_UINT16*) &(p->net_id))||
	  !msf_dcvt_uint32 (obj, (MSF_UINT32*) &(p->type)))
  {
	  return FALSE;
  }
  return TRUE;
}
int pmg_cvt_content_data (msf_dcvt_t *obj, pmg_content_data_t *p)
{
  if (!msf_dcvt_uint8 (obj, &(p->routingFormat)) ||
      !msf_dcvt_string (obj, &(p->routingIdentifier)) ||
      !msf_dcvt_string (obj, &(p->contentUrl)) ||
      !msf_dcvt_string (obj, &(p->contentSource)) ||
      !msf_dcvt_string (obj, &(p->contentParameters)) ||
      !msf_dcvt_string (obj, &(p->contentHeaders)) ||
      !msf_dcvt_int32 (obj, &(p->networkAccountId)) ||
      !msf_dcvt_uint8 (obj, &(p->contentDataType)) ||
      !msf_dcvt_uint32 (obj, &(p->contentDataLength))) {
    return FALSE;
  }
  
  if (p->contentDataType == MSF_CONTENT_DATA_RAW){
    if (!msf_dcvt_uchar_vector (obj, p->contentDataLength, &(p->contentData)))
      return FALSE;
  }
  else
  {
   /* The actual data to be routed is in contentData 
      only for MSF_CONTENT_DATA_RAW */
    p->contentData = NULL;
  }
  if (!msf_dcvt_int32 (obj, &(p->attrLength)) ||
      (!msf_dcvt_uchar_vector (obj, p->attrLength, &(p->attrString))) ||      
      !msf_dcvt_uint8 (obj, &(p->contentDRMDataExists)) ||
      !msf_dcvt_array (obj, sizeof (pmg_content_drm_data_t), 
                       p->contentDRMDataExists,
                       (void **)&(p->contentDRMData), 
                       (msf_dcvt_element_t *)pmg_cvt_content_drm_data) ||
      !msf_dcvt_string (obj, &(p->auxTypeIdentifier))) {
        return FALSE;
  }
  
  return TRUE;
}


int pmg_cvt_content_drm_data (msf_dcvt_t *obj, pmg_content_drm_data_t *p)
{
  if (!msf_dcvt_uint16 (obj, &(p->drmDataLength)) ||
      !msf_dcvt_uchar_vector (obj, p->drmDataLength, &(p->drmData)) ||
      !msf_dcvt_string (obj, &(p->drmContentHeaders))) {
    return FALSE;
  }
  return TRUE;
}


const U8* pmg_if_get_accept_header(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_BROWSER_2__ 
	return((const U8*)srv_brw_get_default_accept_header());
#else
	return((const U8*)"accept: */*\r\n");
#endif


}

int PMGif_turnOnPushService(void)
{
#ifdef __MMI_PUSH_TURN_ON_OFF_SWITCH__

	return pmg_inbox_push_turn_on_off_check();
#else
	return TRUE;
#endif /*__MMI_PUSH_TURN_ON_OFF_SWITCH__*/
}
