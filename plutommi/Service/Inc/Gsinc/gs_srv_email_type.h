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
 *   gs_srv_email_type.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   IEmail type header file
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _GS_SRV_EMAIL_TYPE_
#define _GS_SRV_EMAIL_TYPE_

/* structure of send address to recipients field */
typedef struct
{
    S8 *addr_mail;          /* Email address field(UCS2) */
    S8 *addr_name;          /* Email display field(UCS2) */
} gs_srv_email_app_send_addr_struct;

/* Email priority type enum */
typedef enum
{
    GS_SRV_EMAIL_PRIOR_NORMAL = 0,             /* normal priority */
    GS_SRV_EMAIL_PRIOR_LOW = 1,                /* low priority */
    GS_SRV_EMAIL_PRIOR_HIGH = 2                /* high priority */
} gs_srv_email_app_prior_enum;

// New added for MRE
typedef enum
{
    GS_SRV_EMAIL_APP_MRE_ERROR_CODE_SUCCESS,           /* Send successfully */
    GS_SRV_EMAIL_APP_MRE_ERROR_CODE_WOULDBLOCK,        /* Action taken */
    GS_SRV_EMAIL_APP_MRE_ERROR_CODE_INVLAID_PARAM,     /* Invalid parameter, such as NO receptions */
    GS_SRV_EMAIL_APP_MRE_ERROR_CODE_NO_EMAIL_ACCOUNT,  /* No email account in system */
    GS_SRV_EMAIL_APP_MRE_ERROR_CODE_EMAIL_NOT_AVAIABLE,/* Email is NOT available currently, such as phone is in FLIGHT mode, USB mode etc. */
    GS_SRV_EMAIL_APP_MRE_ERROR_CODE_EMAIL_NOT_READY,   /* Email is during in progress of initialization */
    GS_SRV_EMAIL_APP_MRE_ERROR_CODE_EMAIL_BUSY,        /* Email is busy on receiving or sending */
    GS_SRV_EMAIL_APP_MRE_ERROR_CODE_NETWORK_ERROR,     /* Network error happen during sending */
    GS_SRV_EMAIL_APP_MRE_ERROR_CODE_FILESYSTEM_ERROR,  /* File system error happen during sending */
    GS_SRV_EMAIL_APP_MRE_ERROR_CODE_UNKNOWN_ERROR,     /* Other unknown error happen during sending */
    /* More error code would be added during implement */
}gs_srv_email_app_mre_send_error_code_enum;

typedef struct
{
    gs_srv_email_app_send_addr_struct *from;               /* From address, could be NULL */
    U32 to_num;                                         /* To address number */
    gs_srv_email_app_send_addr_struct *to;                 /* To address list */
    U32 cc_num;                                         /* Cc address number */
    gs_srv_email_app_send_addr_struct *cc;                 /* Cc address list */
    U32 bcc_num;                                        /* Bcc address number */
    gs_srv_email_app_send_addr_struct *bcc;                /* Bcc address list */
    WCHAR *subject;                                     /* Subject string pointer(UCS2) */
    WCHAR *content;                                     /* Content data pointer(UCS2) */
    S32 attach_file_num;                                /* Attachment file number */
    WCHAR **attch_file_list;                            /* Attachment file path string pointer(UCS2) list */
    gs_srv_email_app_prior_enum priority;                  /* APP defined priority */
    S32 is_save_to_sent;                           /* Save the Email to SENT box after sent successfully */
} gs_srv_email_app_mre_send_param_struct;

/* Callback function define 
*   gs_srv_email_app_mre_send_error_code_enum errcode. See gs_srv_email_app_mre_send_error_code_enum
*/
typedef void (*gs_srv_email_app_mre_send_result_callback)(gs_srv_email_app_mre_send_error_code_enum errcode, void* user_data);

#endif //_GS_SRV_UM_TYPE_


