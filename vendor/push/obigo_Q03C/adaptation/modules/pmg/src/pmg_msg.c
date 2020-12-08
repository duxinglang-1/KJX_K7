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
 *   pmg_msg.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains functions for Push message management.
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
//#include "msf_int.h"
#include "msf_mem.h"
//#include "msf_dcvt.h"
//#include "msf_log.h"
//#include "msf_pipe.h"
//#include "msf_file.h"
//#include "msf_chrs.h"
//#include "msf_errc.h"

#include "Conversions.h"

#include "pmg_main.h"
#include "pmg_fs.h"
#include "pmg_if.h"
#include "pmg_msg.h"
//#include "pmg_inbox.h"
//#include "phs_msg.h"
#include "phs_cfg.h"

//suggested add
    #include "msf_def.h"
    #include "kal_general_types.h"
    #include "string.h"
    #include "pmg_struct.h"
    #include "msf_cmmn.h"
    #include "kal_public_api.h"

typedef struct pmg_msg_context_st
{
    int pmg_msg_last_id;
    MSF_UINT32 pmg_msg_count;
    pmg_msg_elem_t *pmg_msg_list;
}pmg_msg_context_t;

static pmg_msg_context_t g_pmg_msg_cntx = {0};

extern int mmi_charset_utf8_to_ucs2_length_in_bytes(const kal_uint8 *raw);
extern int mmi_charset_ucs2_to_utf8_length_in_bytes(const kal_uint8 *raw);


/*****************************************************************************
 * FUNCTION
 *  pmg_msg_init
 * DESCRIPTION
 *  initialise PMG's message component
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_msg_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_pmg_msg_cntx.pmg_msg_list = 0;
    g_pmg_msg_cntx.pmg_msg_count = 0;
    g_pmg_msg_cntx.pmg_msg_last_id = 0;

    pmg_fs_open();

    pmg_init_done(PMG_INIT_MSG);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_msg_add_elem_to_list
 * DESCRIPTION
 *  add message element to list
 * PARAMETERS
 *  elem             [in]
 * RETURNS
 *  void
 *****************************************************************************/
static void pmg_msg_add_elem_to_list(pmg_msg_elem_t *elem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_msg_elem_t *crt;
    pmg_msg_elem_t *prev;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    elem->next = 0;
    if (!g_pmg_msg_cntx.pmg_msg_list)
    {
        g_pmg_msg_cntx.pmg_msg_list = elem;
        g_pmg_msg_cntx.pmg_msg_count++;
        return;
    }

    prev = 0;
    crt = g_pmg_msg_cntx.pmg_msg_list;
    while (crt)
    {
        if (elem->sort_value > crt->sort_value ||
            (elem->sort_value == crt->sort_value && elem->sort_value_2 > crt->sort_value_2))
        {
            if (!prev)
            {
                elem->next = g_pmg_msg_cntx.pmg_msg_list;
                g_pmg_msg_cntx.pmg_msg_list = elem;
            }
            else
            {
                prev->next = elem;
                elem->next = crt;
            }
            g_pmg_msg_cntx.pmg_msg_count++;
            return;
        }
        prev = crt;
        crt = crt->next;
    }
    prev->next = elem;
    g_pmg_msg_cntx.pmg_msg_count++;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_msg_remove_elem_from_list
 * DESCRIPTION
 *  remove message element from list
 * PARAMETERS
 *  msgID               [in]
 * RETURNS
 *  void
 *****************************************************************************/
static pmg_msg_elem_t *pmg_msg_remove_elem_from_list(int msgID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_msg_elem_t *matched;
    pmg_msg_elem_t *prev;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prev = 0;
    matched = g_pmg_msg_cntx.pmg_msg_list;
    while (matched && matched->msgID != msgID)
    {
        prev = matched;
        matched = matched->next;
    }
    if (!matched)
        return 0;

    if (prev)
        prev->next = matched->next;
    else
        g_pmg_msg_cntx.pmg_msg_list = matched->next;

    return matched;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_msg_find_elem_by_id
 * DESCRIPTION
 *  find message element from list by message ID
 * PARAMETERS
 *  msgID               [in]
 * RETURNS
 *  message element
 *****************************************************************************/
pmg_msg_elem_t *pmg_msg_find_elem_by_id(int msgID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_msg_elem_t *matched;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    matched = g_pmg_msg_cntx.pmg_msg_list;
    while (matched && matched->msgID != msgID)
        matched = matched->next;

    return matched;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_msg_find_elem_by_siid
 * DESCRIPTION
 *  find message element from list by siid
 * PARAMETERS
 *  siid                [in]
 * RETURNS
 *  message element
 *****************************************************************************/
pmg_msg_elem_t *pmg_msg_find_elem_by_siid(const char *siid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_msg_elem_t *matched;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    matched = g_pmg_msg_cntx.pmg_msg_list;
    while (matched && (!matched->siid || strcmp(matched->siid, siid) != 0))
        matched = matched->next;

    return matched;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_msg_find_elem_by_href
 * DESCRIPTION
 *  find a SL message element from list by href
 * PARAMETERS
 *  href                [in]
 * RETURNS
 *  message element
 *****************************************************************************/
pmg_msg_elem_t *pmg_msg_find_elem_by_href(const char *href)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_msg_elem_t *matched;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    matched = g_pmg_msg_cntx.pmg_msg_list;
    while (matched && (matched->type!=PMG_MSGTYPE_SL || !matched->href || strcmp(matched->href, href)!=0))
        matched = matched->next;

    return matched;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_msg_find_elem_index
 * DESCRIPTION
 *  find index of the specified message matching the ID
 * PARAMETERS
 *  msgID               [in]
 * RETURNS
 *  index in list
 *****************************************************************************/
int pmg_msg_find_elem_index(int msgID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_msg_elem_t *matched;
    int index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = 0;
    matched = g_pmg_msg_cntx.pmg_msg_list;
    while (matched)
    {
        if (matched->msgID == msgID)
            return index;
        matched = matched->next;
        index++;
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_msg_release_msg_elem
 * DESCRIPTION
 *  release message element object
 * PARAMETERS
 *  elem             [in]
 * RETURNS
 *  void
 *****************************************************************************/
static void pmg_msg_release_msg_elem(pmg_msg_elem_t *elem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (elem->from)
        PMG_MEM_FREE(elem->from);

    if (elem->siid)
        PMG_MEM_FREE(elem->siid);

    if (elem->href)
        PMG_MEM_FREE(elem->href);

    if (elem->partialText)
        PMG_MEM_FREE(elem->partialText);

    if (elem->partialHref)
        PMG_MEM_FREE(elem->partialHref);

    PMG_MEM_FREE(elem);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_msg_construct_partial_text
 * DESCRIPTION
 *  truncate text "src" to "maxChars"
 *  non-ASCII chars are taken into consideration
 * PARAMETERS
 *  src                     [in]
 *  maxChars                [in]
 * RETURNS
 *  partial text
 *****************************************************************************/
static char *pmg_msg_construct_partial_text(const char *src, int maxChars)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *strout;
    int srclen;
    int isAscii;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    isAscii = pmg_check_is_ascii_string(src);
    if (isAscii)
        srclen = strlen(src);
    else
        srclen = mmi_chset_utf8_strlen((const kal_uint8*)src);

    if (maxChars >= srclen)
        return msf_cmmn_strdup(MSF_MODID_PMG, src);

    ASSERT(maxChars > 3);

    if (isAscii)
    {
        strout = pmg_mem_alloc(maxChars + 1);
        memset(strout, 0, maxChars + 1);
        memcpy(strout, src, maxChars - 3);
    }
    else
    {
        int ucs2bytes;
        char *ucs2str;
        int utf8bytes;

        ucs2bytes = mmi_charset_utf8_to_ucs2_length_in_bytes((const kal_uint8*)src);
        ucs2str = pmg_mem_alloc((maxChars - 3 + 1) * 2);
        memset(ucs2str, 0, (maxChars - 3 + 1) * 2);
        mmi_chset_utf8_to_ucs2_string((kal_uint8*) ucs2str, (kal_int32) ((maxChars - 3 + 1) * 2), (kal_uint8*) src);

        utf8bytes = mmi_charset_ucs2_to_utf8_length_in_bytes((const kal_uint8*)ucs2str);
        strout = pmg_mem_alloc(utf8bytes + 3 + 1);
        memset(strout, 0, utf8bytes + 3 + 1);
        mmi_chset_ucs2_to_utf8_string((kal_uint8*) strout, (kal_int32) (utf8bytes + 1), (kal_uint8*) ucs2str);

        PMG_MEM_FREE(ucs2str);
    }
    strout[maxChars - 1] = '.';
    strout[maxChars - 2] = '.';
    strout[maxChars - 3] = '.';

    return strout;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_msg_convert_fs_data_to_list_elem
 * DESCRIPTION
 *  convert file system's message object to message list element
 * PARAMETERS
 *  offset              [in]
 *  msgData             [in]
 * RETURNS
 *  message list element
 *****************************************************************************/
static pmg_msg_elem_t *pmg_msg_convert_fs_data_to_list_elem(long offset, long size, pmg_fs_msg_file_data_t *msgData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_msg_elem_t *msgElem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgElem = pmg_mem_alloc(sizeof(pmg_msg_elem_t));
    memset(msgElem, 0, sizeof(pmg_msg_elem_t));
    msgElem->next = 0;

    msgElem->blockOffset = offset;
    msgElem->blockSize = size;
    msgElem->sort_value = msgData->created;
    msgElem->sort_value_2 = msgData->msgID;
    msgElem->created = msgData->created;
    msgElem->expired = msgData->expired;
    msgElem->msgID = msgData->msgID;
    msgElem->type = msgData->msgType;
    msgElem->priority = msgData->priority;
    msgElem->read = msgData->read;
    msgElem->numInfoItems = msgData->numInfoItems;
    msgElem->fromType = msgData->fromType;
    if (msgData->from)
        msgElem->from = msf_cmmn_strdup(MSF_MODID_PMG, msgData->from);
    if (msgData->siid)
        msgElem->siid = msf_cmmn_strdup(MSF_MODID_PMG, msgData->siid);
    if (msgData->href)
        msgElem->href = msf_cmmn_strdup(MSF_MODID_PMG, msgData->href);

    if (msgData->text)
        msgElem->partialText = pmg_msg_construct_partial_text(msgData->text, PMG_MAX_PARTIAL_TEXT_CHARS);
    if (msgData->href)
        msgElem->partialHref = pmg_msg_construct_partial_text(msgData->href, PMG_MAX_PARTIAL_TEXT_CHARS);

/* for dual sim support */
   msgElem->sim_id = msgData->sim_id;

    return msgElem;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_msg_duplicate_msg_elem
 * DESCRIPTION
 *  duplicate message list element
 * PARAMETERS
 *  elem             [in]
 * RETURNS
 *  duplicated object
 *****************************************************************************/
static pmg_msg_elem_t *pmg_msg_duplicate_msg_elem(pmg_msg_elem_t *elem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_msg_elem_t *dupElem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dupElem = pmg_mem_alloc(sizeof(pmg_msg_elem_t));
	memset(dupElem, 0, sizeof(pmg_msg_elem_t));
    memcpy(dupElem, elem, sizeof(pmg_msg_elem_t));

    dupElem->next = 0;
    dupElem->blockOffset = -1;

    if (elem->from)
        dupElem->from = msf_cmmn_strdup(MSF_MODID_PMG, elem->from);

    if (elem->siid)
        dupElem->siid = msf_cmmn_strdup(MSF_MODID_PMG, elem->siid);

    if (elem->href)
        dupElem->href = msf_cmmn_strdup(MSF_MODID_PMG, elem->href);

    if (elem->partialText)
        dupElem->partialText = msf_cmmn_strdup(MSF_MODID_PMG, elem->partialText);

    if (elem->partialHref)
        dupElem->partialHref = msf_cmmn_strdup(MSF_MODID_PMG, elem->partialHref);

    return dupElem;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_msg_duplicate_msg_infoitem
 * DESCRIPTION
 *  duplicate message info item
 * PARAMETERS
 *  infoitem             [in]
 * RETURNS
 *  duplicated object
 *****************************************************************************/
static pmg_msg_infoitem_t *pmg_msg_duplicate_msg_infoitem(pmg_msg_infoitem_t *infoitem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_msg_infoitem_t *dupInfoitem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dupInfoitem = pmg_mem_alloc(sizeof(pmg_msg_infoitem_t));
    memset(dupInfoitem, 0, sizeof(pmg_msg_infoitem_t));

    if (infoitem->infoClass)
        dupInfoitem->infoClass = msf_cmmn_strdup(MSF_MODID_PMG, infoitem->infoClass);
    if (infoitem->infoText)
        dupInfoitem->infoText = msf_cmmn_strdup(MSF_MODID_PMG, infoitem->infoText);

    return dupInfoitem;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_msg_parse_msg_file_block
 * DESCRIPTION
 *  parse message's raw data from file system and add message to list
 * PARAMETERS
 *  blockData               [in]
 *  blockOffset             [in]
 *  blockSize               [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_msg_parse_msg_file_block(void *blockData, long blockOffset, long blockSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *ptrSrcBuffer;
    pmg_fs_msg_file_data_t *msgFileData;
    pmg_msg_elem_t *msgElem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptrSrcBuffer = (char*)blockData;
    msgFileData = pmg_fs_unpack_msg_data(&ptrSrcBuffer);

    msgElem = pmg_msg_convert_fs_data_to_list_elem(blockOffset, blockSize, msgFileData);
    pmg_msg_add_elem_to_list(msgElem);

    pmg_fs_release_msg_data(msgFileData);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_msg_generate_id
 * DESCRIPTION
 *  generate unique message ID
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static int pmg_msg_generate_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_msg_elem_t *msgElem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (1)
    {
        g_pmg_msg_cntx.pmg_msg_last_id++;
        if (!g_pmg_msg_cntx.pmg_msg_last_id)
            g_pmg_msg_cntx.pmg_msg_last_id++;

        msgElem = g_pmg_msg_cntx.pmg_msg_list;
        while (msgElem)
        {
            if (msgElem->msgID == g_pmg_msg_cntx.pmg_msg_last_id)
                break;
            msgElem = msgElem->next;
        }
        if (!msgElem)
            break;
    }
    return g_pmg_msg_cntx.pmg_msg_last_id;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_msg_add_new_message
 * DESCRIPTION
 *  add a file system's message object to list
 * PARAMETERS
 *  msg          [in]
 * RETURNS
 *  0: operation failed, 1: succeeded
 *****************************************************************************/
int pmg_msg_add_new_message(pmg_fs_msg_file_data_t *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_msg_elem_t *elem;
    long offset = -1, size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* generate unique message ID */
    if (!(msg->msgID))
        msg->msgID = pmg_msg_generate_id();

    /* set message arrival time */
    msg->arrived = pmg_get_current_sys_utc_time();
    if (!msg->created)
        msg->created = msg->arrived;

    /* check max allowed messages */
    if (g_pmg_msg_cntx.pmg_msg_count >= PMG_MAX_PUSH_MESSAGES)
        return 0;

    /* save message to storage */
    size = pmg_fs_write_msg_data(&offset, msg);
    if (offset == -1)
        return 0;

    /* add data to list */
    elem = pmg_msg_convert_fs_data_to_list_elem(offset, size, msg);
    pmg_msg_add_elem_to_list(elem);

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_msg_delete_message
 * DESCRIPTION
 *  delete a message from system (ie, from list and file system)
 * PARAMETERS
 *  msgID               [in]
 * RETURNS
 *  0: operation failed, 1: succeeded
 *****************************************************************************/
int pmg_msg_delete_message(int msgID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_msg_elem_t *elem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    elem = pmg_msg_remove_elem_from_list(msgID);
    if (elem)
    {
        g_pmg_msg_cntx.pmg_msg_count--;
        pmg_fs_erase_data(elem->blockOffset);
        pmg_msg_release_msg_elem(elem);
        return 1;
    }
    return 0;
}

#ifdef __MMI_BRW_PUSH_DELETE_LAST_ITEM_WHEN_STORAGE_FULL__
/*****************************************************************************
 * FUNCTION
 *  pmg_msg_delete_oldest_message
 * DESCRIPTION
 *  delete the oldest message from system (ie, from list and file system)
 * PARAMETERS
 *  msgID               [out]
 *  msgType             [out]
 * RETURNS
 *  0: operation failed, 1: succeeded
 *****************************************************************************/
int pmg_msg_delete_oldest_message(int *msgID, MSF_UINT8 *msgType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_msg_elem_t *elem;
    pmg_msg_elem_t *oldest;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pmg_msg_cntx.pmg_msg_list == NULL)
    {
        return 1;
    }

    oldest = g_pmg_msg_cntx.pmg_msg_list;
    elem = oldest->next;

    while (elem)
    {
        oldest = (oldest->created > elem->created) ? elem : oldest;
        elem = elem->next;
    }

    *msgID = oldest->msgID;
    *msgType = oldest->type;
    return pmg_msg_delete_message(oldest->msgID);
}

#endif /* __MMI_BRW_PUSH_DELETE_LAST_ITEM_WHEN_STORAGE_FULL__ */
/*****************************************************************************
 * FUNCTION
 *  pmg_msg_retrieve_full_message
 * DESCRIPTION
 *  retrieve the full message data given the ID (ie, load message from file system)
 * PARAMETERS
 *  msgID               [in]
 * RETURNS
 *  0: operation failed, non-zero: message object
 *****************************************************************************/
pmg_full_msg_t *pmg_msg_retrieve_full_message(int msgID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_msg_elem_t *elem;
    void *data;
    char *ptrSrcBuffer;
    pmg_fs_msg_file_data_t *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((elem = pmg_msg_find_elem_by_id(msgID)) == 0)
        return 0;

    if ((data = pmg_fs_read_raw_data(elem->blockOffset)) == 0)
        return 0;

    ptrSrcBuffer = (char*)data;
    msg = pmg_fs_unpack_msg_data(&ptrSrcBuffer);

  
    PMG_MEM_FREE(data);
    return (pmg_full_msg_t*) msg;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_msg_check_msg_property
 * DESCRIPTION
 *  check whether the message matches the specified properties
 * PARAMETERS
 *  elem                    [in]
 *  msgType                 [in]    {PMG_PARAM_NOT_SPECIFIED, PMG_MSGTYPE_SI, PMG_MSGTYPE_SL, PMG_MSGTYPE_SI|PMG_MSGTYPE_SL}
 *  isRead                  [in]    {PMG_PARAM_NOT_SPECIFIED, PMG_PARAM_YES, PMG_PARAM_NO}
 *  isExpired               [in]    {PMG_PARAM_NOT_SPECIFIED, PMG_PARAM_YES, PMG_PARAM_NO}
 *  hasInfo                 [in]    {PMG_PARAM_NOT_SPECIFIED, PMG_PARAM_YES, PMG_PARAM_NO}
 * RETURNS
 *  0: not match, 1: matched
 *****************************************************************************/
static int
pmg_msg_check_msg_property(
    pmg_msg_elem_t *elem,
    MSF_UINT8 msgType,
    MSF_UINT8 isRead,
    MSF_UINT8 isExpired,
    MSF_UINT8 hasInfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT32 crtTime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    crtTime = pmg_get_current_sys_utc_time();

    if (msgType != PMG_PARAM_NOT_SPECIFIED && (msgType & elem->type) == 0)
        return 0;
    if (isRead != PMG_PARAM_NOT_SPECIFIED &&
        ((isRead == PMG_PARAM_YES && elem->read == 0) || (isRead == PMG_PARAM_NO && elem->read == 1)))
        return 0;
    if (isExpired != PMG_PARAM_NOT_SPECIFIED &&
        ((isExpired == PMG_PARAM_YES && elem->expired > crtTime) ||
         (isExpired == PMG_PARAM_NO && elem->expired < crtTime)))
        return 0;
    if (hasInfo != PMG_PARAM_NOT_SPECIFIED &&
        ((hasInfo == PMG_PARAM_YES && elem->numInfoItems == 0) || (hasInfo == PMG_PARAM_NO && elem->numInfoItems > 0)))
        return 0;

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_msg_count_messages
 * DESCRIPTION
 *  count the number of message matching the specified properties
 * PARAMETERS
 *  msgType                 [in]    {PMG_PARAM_NOT_SPECIFIED, PMG_MSGTYPE_SI, PMG_MSGTYPE_SL, PMG_MSGTYPE_SI|PMG_MSGTYPE_SL}
 *  isRead                  [in]    {PMG_PARAM_NOT_SPECIFIED, PMG_PARAM_YES, PMG_PARAM_NO}
 *  isExpired               [in]    {PMG_PARAM_NOT_SPECIFIED, PMG_PARAM_YES, PMG_PARAM_NO}
 *  hasInfo                 [in]    {PMG_PARAM_NOT_SPECIFIED, PMG_PARAM_YES, PMG_PARAM_NO}
 * RETURNS
 *  message count
 *****************************************************************************/
int pmg_msg_count_messages(MSF_UINT8 msgType, MSF_UINT8 isRead, MSF_UINT8 isExpired, MSF_UINT8 hasInfo, MSF_UINT32 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_msg_elem_t *elem;
    int count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count = 0;
    elem = g_pmg_msg_cntx.pmg_msg_list;
    while (elem)
    {
        if (pmg_msg_check_msg_property(elem, msgType, isRead, isExpired, hasInfo))
        {
		if (elem->sim_id == sim_id)
			count++;
        }			
        elem = elem->next;
    }
    return count;
}

#ifdef __MMI_BRW_PUSH_DELETE_LAST_ITEM_WHEN_STORAGE_FULL__
/*****************************************************************************
 * FUNCTION
 *  pmg_msg_count_all_messages
 * DESCRIPTION
 *  count message number
 * PARAMETERS
 * RETURNS
 *  message count
 *****************************************************************************/
MSF_UINT32 pmg_msg_count_all_messages(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_pmg_msg_cntx.pmg_msg_count;
}
#endif /* __MMI_BRW_PUSH_DELETE_LAST_ITEM_WHEN_STORAGE_FULL__ */
/*****************************************************************************
 * FUNCTION
 *  pmg_msg_retrieve_list
 * DESCRIPTION
 *  retrieve message list satisfying the properties
 * PARAMETERS
 *  msgType                         [in]    {PMG_PARAM_NOT_SPECIFIED, PMG_MSGTYPE_SI, PMG_MSGTYPE_SL, PMG_MSGTYPE_SI|PMG_MSGTYPE_SL}
 *  isRead                          [in]    {PMG_PARAM_NOT_SPECIFIED, PMG_PARAM_YES, PMG_PARAM_NO}
 *  isExpired                       [in]    {PMG_PARAM_NOT_SPECIFIED, PMG_PARAM_YES, PMG_PARAM_NO}
 *  hasInfo                         [in]    {PMG_PARAM_NOT_SPECIFIED, PMG_PARAM_YES, PMG_PARAM_NO}
 *  startFrom                       [in]    index to start from
 *  sizeToRetrieve                  [in]    size to retrieve (0=retrieve all)
 *  maxAllowableSize                [in]    max number of messages to return
 * RETURNS
 *  message list
 *****************************************************************************/

pmg_msg_list_t *pmg_msg_retrieve_list(
                    MSF_UINT8 msgType,
                    MSF_UINT8 isRead,
                    MSF_UINT8 isExpired,
                    MSF_UINT8 hasInfo,
                    MSF_UINT32 startFrom,
                    MSF_UINT32 sizeToRetrieve,
                    MSF_UINT32 maxAllowableSize,
					MSF_UINT32 sim_id)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT32 count;
    pmg_msg_elem_t *elem;
    pmg_msg_list_t *msglist;
    pmg_msg_elem_t *tmp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* int num_msgs; */

    msglist = pmg_mem_alloc(sizeof(pmg_msg_list_t));
    memset(msglist, 0, sizeof(pmg_msg_list_t));

    //num_msgs = pmg_msg_count_messages(msgType, isRead, isExpired, hasInfo);
    //if (!sizeToRetrieve || sizeToRetrieve>num_msgs)
/* for dual sim */
if (!sizeToRetrieve)
{
#if(MMI_MAX_SIM_NUM >= 2)

     sizeToRetrieve = pmg_msg_count_messages(msgType, isRead, isExpired, hasInfo, WAP_PMG_SIM1);
	 sizeToRetrieve += pmg_msg_count_messages(msgType, isRead, isExpired, hasInfo, WAP_PMG_SIM2);	
	#if (MMI_MAX_SIM_NUM >= 3)
	 sizeToRetrieve += pmg_msg_count_messages(msgType, isRead, isExpired, hasInfo, WAP_PMG_SIM3);	
	#endif
	#if (MMI_MAX_SIM_NUM >= 4)
	 sizeToRetrieve += pmg_msg_count_messages(msgType, isRead, isExpired, hasInfo, WAP_PMG_SIM4);	
	#endif
#else
	sizeToRetrieve += pmg_msg_count_messages(msgType, isRead, isExpired, hasInfo, WAP_PMG_SIM_DEFAULT);
#endif/*(MMI_MAX_SIM_NUM >= 2)*/
}

    count = 0;
    elem = g_pmg_msg_cntx.pmg_msg_list;
    while (elem)
    {
        if (pmg_msg_check_msg_property(elem, msgType, isRead, isExpired, hasInfo))
        {

			if ((elem->sim_id == sim_id) || (sim_id == WAP_PMG_SIM_ALL))
			{

            count++;
            if (count > startFrom && msglist->size < maxAllowableSize && msglist->size < sizeToRetrieve)
            {
                if (!msglist->head)
                    msglist->head = pmg_msg_duplicate_msg_elem(elem);
                else
                {
                    tmp = msglist->head;
                    while (tmp->next)
                        tmp = tmp->next;
                    tmp->next = pmg_msg_duplicate_msg_elem(elem);
                }
                msglist->size++;
            }
            else if (msglist->size >= maxAllowableSize && msglist->remain_size + msglist->size < sizeToRetrieve)
            {
                /* msglist->remain_size = index - msglist->size - startFrom; */
                msglist->remain_size++;
            }
            else if (msglist->remain_size + msglist->size >= sizeToRetrieve)
            {
                break;
            }
        }
	
		}			
	
        elem = elem->next;
    }
    /* msglist->remain_size = 0; */
    return msglist;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_msg_release_list
 * DESCRIPTION
 *  release message list memories
 * PARAMETERS
 *  msglist          [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_msg_release_list(pmg_msg_list_t *msglist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_msg_elem_t *elem;
    pmg_msg_elem_t *next;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    elem = msglist->head;
    while (elem)
    {
        next = elem->next;
        pmg_msg_release_msg_elem(elem);
        elem = next;
    }
    PMG_MEM_FREE(msglist);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_msg_release_infoitem_list
 * DESCRIPTION
 *  release info item list memories
 * PARAMETERS
 *  infoitem_list            [in]
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_msg_release_infoitem_list(pmg_msg_infoitem_list_t *infoitem_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pmg_fs_release_infoitems((pmg_fs_msg_file_infoitem_t*) (infoitem_list->head));
    PMG_MEM_FREE(infoitem_list);
}


/*****************************************************************************
 * FUNCTION
 *  pmg_msg_retrieve_msg_infoitems
 * DESCRIPTION
 *  retrieve info item list
 * PARAMETERS
 *  msgID                   [in]
 *  startFrom               [in]
 *  size                    [in]
 * RETURNS
 *  infoitem list
 *****************************************************************************/
pmg_msg_infoitem_list_t *pmg_msg_retrieve_msg_infoitems(int msgID, MSF_UINT32 startFrom, MSF_UINT32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_msg_infoitem_list_t *infoitem_list;
    pmg_msg_infoitem_t *infoitem;
    pmg_full_msg_t *msg;
    pmg_msg_elem_t *msg_elem;
    pmg_msg_infoitem_t *last_infoitem;
    MSF_UINT32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    infoitem_list = pmg_mem_alloc(sizeof(pmg_msg_infoitem_list_t));
    memset(infoitem_list, 0, sizeof(pmg_msg_infoitem_list_t));

    msg_elem = pmg_msg_find_elem_by_id(msgID);
    if (!msg_elem)
    {
        PMG_MEM_FREE(infoitem_list);
        return 0;
    }
    if (msg_elem->numInfoItems == 0 || startFrom >= msg_elem->numInfoItems)
        return infoitem_list;

    msg = pmg_msg_retrieve_full_message(msgID);
    if (!msg)
        return infoitem_list;

    index = 0;
    last_infoitem = 0;
    infoitem = msg->infoitems;
    while (infoitem && infoitem_list->size < size)
    {
        if (index >= startFrom)
        {
            if (last_infoitem)
            {
                last_infoitem->next = pmg_msg_duplicate_msg_infoitem(infoitem);
                last_infoitem = last_infoitem->next;

            }
            else
            {
                infoitem_list->head = pmg_msg_duplicate_msg_infoitem(infoitem);
                last_infoitem = infoitem_list->head;
            }
            infoitem_list->size++;
        }
        index++;
        infoitem = infoitem->next;
    }

    pmg_lib_release_msg(msg);
    return infoitem_list;
}


/*****************************************************************************
 * FUNCTION
 *  pmg_msg_delete_all_messages
 * DESCRIPTION
 *  remove all messages matching specifeid type
 * PARAMETERS
 *  msgType             [in]  {PMG_PARAM_NOT_SPECIFIED, PMG_MSGTYPE_SI, PMG_MSGTYPE_SL, PMG_MSGTYPE_SI|PMG_MSGTYPE_SL}
 * RETURNS
 *  void
 *****************************************************************************/
void pmg_msg_delete_all_messages(MSF_UINT8 msgType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_msg_elem_t *elem;
    pmg_msg_elem_t *next;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    elem = g_pmg_msg_cntx.pmg_msg_list;
    while (elem)
    {
        next = elem->next;
        if (pmg_msg_check_msg_property
            (elem, msgType, PMG_PARAM_NOT_SPECIFIED, PMG_PARAM_NOT_SPECIFIED, PMG_PARAM_NOT_SPECIFIED))
        {
            if (elem == g_pmg_msg_cntx.pmg_msg_list)
                g_pmg_msg_cntx.pmg_msg_list = next;
            pmg_fs_erase_data(elem->blockOffset);
            pmg_msg_release_msg_elem(elem);
        }
        elem = next;
    }
    g_pmg_msg_cntx.pmg_msg_count = 0;
}

/*****************************************************************************
 * FUNCTION
 *  pmg_msg_update_all_message
 * DESCRIPTION
 *  update message's "read" flag
 * PARAMETERS
 *  read                [in]
 * RETURNS
 * srv_wap_push_msg_read_status_enum
 *****************************************************************************/
wps_pmg_status_enum pmg_msg_update_all_message( MSF_UINT8 read)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_msg_elem_t *elem;
    pmg_full_msg_t *msg;
    int msg_id;
	int count = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	elem = g_pmg_msg_cntx.pmg_msg_list;

	while (elem)
		{
			
			if ( elem->read != read)
			{
			count++;
				msg_id = elem->msgID;
				msg = pmg_msg_retrieve_full_message(msg_id);
				msg->read = read;
    				elem->read = read;
				elem->blockSize = pmg_fs_write_msg_data(&elem->blockOffset, (pmg_fs_msg_file_data_t*) msg);
				ASSERT(elem->blockOffset != -1);
				if(elem->blockOffset == -1)
					{return WAP_PMG_STATUS_FAIL;}
			}
			elem = elem->next;
		}


if (count)
        return WAP_PMG_STATUS_OK;
else
        return WAP_PMG_STATUS_NOT_FOUND;

}

/*****************************************************************************
 * FUNCTION
 *  pmg_msg_update_message
 * DESCRIPTION
 *  update message's "read" flag
 * PARAMETERS
 *  msgID               [in]
 *  read                [in]
 * RETURNS
 *  0: operation failed, 1: succeeded
 *****************************************************************************/
int pmg_msg_update_message(int msgID, MSF_UINT8 read)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pmg_msg_elem_t *elem;
    pmg_full_msg_t *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    elem = pmg_msg_find_elem_by_id(msgID);
    if (!elem)
        return 0;
    if (elem->read == read)
        return 1;

    msg = pmg_msg_retrieve_full_message(msgID);
    msg->read = read;
    elem->read = read;

    elem->blockSize = pmg_fs_write_msg_data(&elem->blockOffset, (pmg_fs_msg_file_data_t*) msg);
    ASSERT(elem->blockOffset != -1);
    return 1;
}

