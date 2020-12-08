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
 *  EmailSrvComposer.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __COMPOSER_H__
#define __COMPOSER_H__

#include "MMIDataType.h"
#include "emailsrvgprot.h"
#include "kal_general_types.h"

typedef enum
{
    EMAIL_COMP_OP_INIT = 0,

    /* write RFC 822 header */
    EMAIL_COMP_OP_WRITE_HEADER_DATE,
    EMAIL_COMP_OP_WRITE_HEADER_ADDR_REPLY_TO_FROM,
    EMAIL_COMP_OP_WRITE_HEADER_ADDR_TO,
    EMAIL_COMP_OP_WRITE_HEADER_ADDR_CC,
    EMAIL_COMP_OP_WRITE_HEADER_ADDR_BCC,
    EMAIL_COMP_OP_WRITE_HEADER_SUBJ,
    EMAIL_COMP_OP_WRITE_HEADER_OTHERS,

    /* write body header */
    EMAIL_COMP_OP_FORM_BODY_HDR_INIT,   /* line limit check init */
    EMAIL_COMP_OP_FORM_BODY_HDR_ENCOD,  /* line limit check */
    EMAIL_COMP_OP_WRITE_BODY_HEADER_TO_BUFF,
    EMAIL_COMP_OP_WRITE_BODY_HEADER_TO_FILE,

    /* write message content */
    EMAIL_COMP_OP_WRITE_CONT_INIT,
    EMAIL_COMP_OP_WRITE_CONT_TO_FILE,

    EMAIL_COMP_OP_WRITE_ATTCH_INIT,
    EMAIL_COMP_OP_WRITE_ATTCH_HEADER_TO_BUFF,   /* write attachment */
    EMAIL_COMP_OP_WRITE_ATTCH_HEADER_TO_FILE,

    /* SMTP Sub Operational States for writing attachments
       used for EMAIL_COMP_OP_WRITE_BODY_ATTACH */
    EMAIL_COMP_OP_ATTCH_BODY_WRITE,
    EMAIL_COMP_OP_ATTCH_BODY_BOUNDARY,

    EMAIL_COMP_OP_WRITE_END_BDRY,

    EMAIL_COMP_OP_FRAME_MSG_END    /* Frame Message End */
} email_comp_op_enum;

typedef enum
{
    EMAIL_COMP_BY_HD = 0,
    EMAIL_COMP_BY_ID = 1,
    EMAIL_COMP_TYPE_TOTAL
} email_comp_type_enum;

/* The Email composer handle type */
typedef U32 EMAIL_COMP_HANDLE;

#define SRV_EMAIL_COMP_INVALID_HANDLE       (0)
#define SRV_EMAIL_COMP_INSTANCE_MAX_NUM     (3)

srv_email_result_enum srv_email_comp_init(void);

/* Create Email composer instance */
srv_email_result_enum srv_email_comp_create(EMAIL_COMP_HANDLE *handle);

/* Compose eml file, by MSG ID */
srv_email_result_enum srv_email_comp_start_by_msg_id(
                        EMAIL_COMP_HANDLE handle,
                        EMAIL_MSG_ID msg_id,
                        MMI_BOOL comp_size_only,
                        WCHAR *filename,
                        srv_email_comp_funcptr_type callback,
                        void *user_data);

/* Compose eml file, by MSG handle */
srv_email_result_enum srv_email_comp_start_by_msg_handle(
                        EMAIL_COMP_HANDLE comp_handle,
                        EMAIL_MSG_HANDLE msg_handle,
                        MMI_BOOL comp_size_only,
                        WCHAR *filename,
                        srv_email_comp_funcptr_type callback,
                        void *user_data);

/* Destroy Email composer instance */
srv_email_result_enum srv_email_comp_destroy(EMAIL_COMP_HANDLE handle);

/* Stop the composing */
srv_email_result_enum srv_email_comp_stop(EMAIL_COMP_HANDLE handle);

void srv_email_get_compose_error(srv_email_result_enum ret, S32 *major, S32 *minor);

/******************************************************************/

#endif /* __COMPOSER_H__ */

