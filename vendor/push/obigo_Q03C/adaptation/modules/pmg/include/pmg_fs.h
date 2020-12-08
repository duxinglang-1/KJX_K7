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
 *   pmg_fs.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains PMG function prototypes, constant/macro/structure definition 
 *   for storage handling
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef _pmg_fs_h
#define _pmg_fs_h

//suggested add
#include "msf_def.h"

typedef struct pmg_fs_msg_file_infoitem_st
{
    struct pmg_fs_msg_file_infoitem_st *next;
    char *infoClass;
    char *infoText;
} pmg_fs_msg_file_infoitem_t;

typedef struct
{
    int msgID;
    MSF_UINT32 created;
    MSF_UINT32 expired;
    MSF_UINT32 arrived;

    char *siid;
    char *text;
    char *smsc; /* SMSC address used for trust list validation */
    char *from; /* Originating address (push-initiator address or URL) used for display only */
    char *href;

    pmg_fs_msg_file_infoitem_t *infoitems;

    MSF_UINT8 msgType;
    MSF_UINT8 priority;
    MSF_UINT8 read;
    MSF_UINT8 numInfoItems;
    MSF_UINT8 smscType; /* SMSC address type */
    MSF_UINT8 fromType; /* Originating address type */
	MSF_UINT32 sim_id;  /* SIM ID FOR DUAL SIM */


} pmg_fs_msg_file_data_t;

void pmg_fs_init(void);

void pmg_fs_open(void);

int pmg_fs_pack_msg_data(pmg_fs_msg_file_data_t *data, char **ptrBuffer);

pmg_fs_msg_file_data_t *pmg_fs_unpack_msg_data(char **ptrSrcBuffer);

void pmg_fs_release_infoitems(pmg_fs_msg_file_infoitem_t *head);

void pmg_fs_release_msg_data(pmg_fs_msg_file_data_t *msgData);

long pmg_fs_write_msg_data(long *offset, pmg_fs_msg_file_data_t *msgData);

void pmg_fs_erase_data(long offset);

void *pmg_fs_read_raw_data(long offset);

#endif /* _pmg_fs_h */ 

