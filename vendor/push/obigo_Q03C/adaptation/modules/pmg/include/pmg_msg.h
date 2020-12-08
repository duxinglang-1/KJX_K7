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
 *   pmg_msg.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains PMG function prototypes, constant/macro/structure definition 
 *   for message management
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef _pmg_msg_h
#define _pmg_msg_h

#include "pmg_fs.h"

//suggested add
    #include "msf_def.h"
    #include "phs_cfg.h"

typedef pmg_fs_msg_file_data_t pmg_full_msg_t;
typedef pmg_fs_msg_file_infoitem_t pmg_msg_infoitem_t;

typedef struct pmg_msg_elem_st
{
    struct pmg_msg_elem_st *next;
    long blockOffset;
    long blockSize;
    MSF_UINT32 sort_value;
    MSF_UINT32 sort_value_2;
    int msgID;
    MSF_UINT32 created; /* created time in UTC */
    MSF_UINT32 expired; /* expiration time in UTC */
    MSF_UINT8 type;
    MSF_UINT8 priority;
    MSF_UINT8 read;
    MSF_UINT8 numInfoItems;
    MSF_UINT8 fromType; /* Originating address type */
    char *from;         /* Originating address (push-initiator address or URL) used for display only */
    char *siid;
    char *href;
    char *partialText;  /* max of PMG_MAX_MSG_LIST_TEXT_CHARS characters */
    char *partialHref;  /* max of PMG_MAX_MSG_LIST_HREF_CHARS characters */
/* for dual sim support */
    MSF_UINT32 sim_id;	
} pmg_msg_elem_t;

typedef struct
{
    MSF_UINT32 size;
    int remain_size;
    pmg_msg_elem_t *head;
} pmg_msg_list_t;

typedef struct
{
    MSF_UINT32 size;
    pmg_msg_infoitem_t *head;
} pmg_msg_infoitem_list_t;

void pmg_msg_init(void);

pmg_msg_elem_t *pmg_msg_find_elem_by_id(int msgID);

pmg_msg_elem_t *pmg_msg_find_elem_by_siid(const char *siid);

pmg_msg_elem_t *pmg_msg_find_elem_by_href(const char *href);

int pmg_msg_find_elem_index(int msgID);

pmg_full_msg_t *pmg_msg_retrieve_full_message(int msgID);

int pmg_msg_add_new_message(pmg_fs_msg_file_data_t *msg);

int pmg_msg_delete_message(int msgID);

#ifdef __MMI_BRW_PUSH_DELETE_LAST_ITEM_WHEN_STORAGE_FULL__

int pmg_msg_delete_oldest_message(int *msgID, MSF_UINT8 *msgType);

MSF_UINT32 pmg_msg_count_all_messages(void);

#endif /*__MMI_BRW_PUSH_DELETE_LAST_ITEM_WHEN_STORAGE_FULL__*/

void pmg_msg_parse_msg_file_block(void *blockData, long blockOffset, long blockSize);

/*
 * msgType = {PMG_PARAM_NOT_SPECIFIED, PMG_MSGTYPE_SI, PMG_MSGTYPE_SL, PMG_MSGTYPE_SI|PMG_MSGTYPE_SL}
 * isRead = {PMG_PARAM_NOT_SPECIFIED, PMG_PARAM_YES, PMG_PARAM_NO}
 * isExpired = {PMG_PARAM_NOT_SPECIFIED, PMG_PARAM_YES, PMG_PARAM_NO}
 * hasInfo = {PMG_PARAM_NOT_SPECIFIED, PMG_PARAM_YES, PMG_PARAM_NO}
 */
int pmg_msg_count_messages(MSF_UINT8 msgType, MSF_UINT8 isRead, MSF_UINT8 isExpired, MSF_UINT8 hasInfo, MSF_UINT32 sim_id);

/*
 * msgType = {PMG_PARAM_NOT_SPECIFIED, PMG_MSGTYPE_SI, PMG_MSGTYPE_SL, PMG_MSGTYPE_SI|PMG_MSGTYPE_SL}
 * isRead = {PMG_PARAM_NOT_SPECIFIED, PMG_PARAM_YES, PMG_PARAM_NO}
 * isExpired = {PMG_PARAM_NOT_SPECIFIED, PMG_PARAM_YES, PMG_PARAM_NO}
 * hasInfo = {PMG_PARAM_NOT_SPECIFIED, PMG_PARAM_YES, PMG_PARAM_NO}
 * startFrom = index to start from
 * sizeToRetrieve = size to retrieve (d0=retrieve all)
 * maxAllowableSize = max number of messages to return
 */
pmg_msg_list_t *pmg_msg_retrieve_list(
                    MSF_UINT8 msgType,
                    MSF_UINT8 isRead,
                    MSF_UINT8 isExpired,
                    MSF_UINT8 hasInfo,
                    MSF_UINT32 startFrom,
                    MSF_UINT32 sizeToRetrieve,
                    MSF_UINT32 maxAllowableSize,
                    MSF_UINT32 sim_id);

void pmg_msg_release_list(pmg_msg_list_t *msglist);

void pmg_msg_release_infoitem_list(pmg_msg_infoitem_list_t *infoitem_list);

pmg_msg_infoitem_list_t *pmg_msg_retrieve_msg_infoitems(int msgID, MSF_UINT32 startFrom, MSF_UINT32 size);

/*
 * msgType = {PMG_PARAM_NOT_SPECIFIED, PMG_MSGTYPE_SI, PMG_MSGTYPE_SL, PMG_MSGTYPE_SI|PMG_MSGTYPE_SL}
 */
void pmg_msg_delete_all_messages(MSF_UINT8 msgType);

int pmg_msg_update_message(int msgID, MSF_UINT8 read);

#endif /* _pmg_msg_h */ 

