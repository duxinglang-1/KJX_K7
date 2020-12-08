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
 *  EmailSrvObject.c
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#include "EmailSrvGprot.h"
#include "EmailSrvProt.h"

#include "EmailSrvStorage.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"

#define email_om_malloc srv_email_mem_alloc
#define email_om_mfree  srv_email_mem_free

#define SET_NOTIFY_MAX_NUM  5

typedef struct
{
    srv_email_om_notify_funcptr_type acct_callback[SET_NOTIFY_MAX_NUM];
    srv_email_om_notify_funcptr_type fldr_callback[SET_NOTIFY_MAX_NUM];
    srv_email_om_notify_funcptr_type msg_callback[SET_NOTIFY_MAX_NUM];
    srv_email_om_notify_struct notify;
} email_om_cntx_struct;

email_om_cntx_struct g_email_om_cntx = {NULL, NULL, NULL};
email_om_cntx_struct *email_om_p = &g_email_om_cntx;

extern MMI_BOOL srv_email_msg_able_to_get_permission(
                    EMAIL_MSG_ID msg_id,
                    srv_email_om_permission_type_enum permision_type);
extern MMI_BOOL srv_email_fldr_able_to_get_permission(
                    EMAIL_ACCT_ID acct_id,
                    EMAIL_FLDR_ID fldr_id,
                    srv_email_om_permission_type_enum type);
extern MMI_BOOL srv_email_acct_able_to_get_permission(
                    EMAIL_ACCT_ID acct_id,
                    srv_email_om_permission_type_enum permision_type);
extern MMI_BOOL srv_email_msg_acct_able_to_delete(EMAIL_ACCT_ID acct_id);

void srv_email_om_init(void)
{
    S32 i;
    for (i = 0; i < SET_NOTIFY_MAX_NUM; i++)
    {
        email_om_p->acct_callback[i] = NULL;
    }
    
    for (i = 0; i < SET_NOTIFY_MAX_NUM; i++)
    {
        email_om_p->fldr_callback[i] = NULL;
    }
    
    for (i = 0; i < SET_NOTIFY_MAX_NUM; i++)
    {
        email_om_p->msg_callback[i] = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_email_om_get_notify_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_email_om_get_notify_id(srv_email_om_notify_obj_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case SRV_EMAIL_OM_NOTIFY_OBJ_ACCT:
            for (i = 0; i < SET_NOTIFY_MAX_NUM; i++)
                if (email_om_p->acct_callback[i] == NULL)
                    return i;
            break;
        case SRV_EMAIL_OM_NOTIFY_OBJ_FLDR:
            for (i = 0; i < SET_NOTIFY_MAX_NUM; i++)
                if (email_om_p->fldr_callback[i] == NULL)
                    return i;
            break;
        case SRV_EMAIL_OM_NOTIFY_OBJ_MSG:
            for (i = 0; i < SET_NOTIFY_MAX_NUM; i++)
                if (email_om_p->msg_callback[i] == NULL)
                    return i;
            break;
        default:
            break;
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_om_set_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type            [IN]        
 *  callback        [IN]        
 *  notify_id       [?]         
 * RETURNS
 *  
 *****************************************************************************/
srv_email_result_enum srv_email_om_set_notify(
                        srv_email_om_notify_obj_type_enum type,
                        srv_email_om_notify_funcptr_type callback,
                        S32 *notify_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *notify_id = srv_email_om_get_notify_id(type);

    if (*notify_id < 0)
    {
        return SRV_EMAIL_RESULT_FAIL;
    }

    switch (type)
    {
        case SRV_EMAIL_OM_NOTIFY_OBJ_ACCT:
            email_om_p->acct_callback[*notify_id] = callback;
            break;
        case SRV_EMAIL_OM_NOTIFY_OBJ_FLDR:
            email_om_p->fldr_callback[*notify_id] = callback;
            break;
        case SRV_EMAIL_OM_NOTIFY_OBJ_MSG:
            email_om_p->msg_callback[*notify_id] = callback;
            break;
        default:
            MMI_ASSERT(0);
            break;
    }
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_om_unset_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type            [IN]        
 *  notify_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_om_unset_notify(srv_email_om_notify_obj_type_enum type, S32 notify_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(notify_id < SET_NOTIFY_MAX_NUM);

    switch (type)
    {
        case SRV_EMAIL_OM_NOTIFY_OBJ_ACCT:
            email_om_p->acct_callback[notify_id] = NULL;
            break;
        case SRV_EMAIL_OM_NOTIFY_OBJ_FLDR:
            email_om_p->fldr_callback[notify_id] = NULL;
            break;
        case SRV_EMAIL_OM_NOTIFY_OBJ_MSG:
            email_om_p->msg_callback[notify_id] = NULL;
            break;
        default:
            MMI_ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_om_nofity_msg_from_stor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type            [IN]        
 *  notify_data     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_om_nofity_msg_from_stor(srv_email_om_notify_enum type, srv_email_om_notify_msg_struct *notify_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    srv_email_om_notify_struct *notify = &email_om_p->notify;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case SRV_EMAIL_OM_NOTIFY_MSG_ADD:
        case SRV_EMAIL_OM_NOTIFY_MSG_DEL:
        case SRV_EMAIL_OM_NOTIFY_MSG_UPDATE:
            notify->notify_type = type;
            notify->data = notify_data;
            break;
        default:
            MMI_ASSERT(0);
            break;
    }

    for (i = 0; i < SET_NOTIFY_MAX_NUM; i++)
    {
        if (email_om_p->msg_callback[i] != NULL)
        {
            (email_om_p->msg_callback[i]) (notify);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_om_nofity_fldr_from_stor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type            [IN]        
 *  notify_data     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_om_nofity_fldr_from_stor(srv_email_om_notify_enum type, void *notify_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    srv_email_om_notify_struct *notify = &email_om_p->notify;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    notify->notify_type = type;
    notify->data = notify_data;

    for (i = 0; i < SET_NOTIFY_MAX_NUM; i++)
    {
        if (email_om_p->fldr_callback[i] != NULL)
        {
            (email_om_p->fldr_callback[i]) (notify);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_om_nofity_acct_from_stor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type            [IN]        
 *  notify_data     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_om_nofity_acct_from_stor(srv_email_om_notify_enum type, srv_email_om_notify_acct_struct *notify_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    srv_email_om_notify_struct *notify = &email_om_p->notify;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case SRV_EMAIL_OM_NOTIFY_ACCT_MSG_NUM_CHG:
            notify->notify_type = type;
            notify->data = notify_data;
            break;
        default:
            MMI_ASSERT(0);
            break;
    }

    for (i = 0; i < SET_NOTIFY_MAX_NUM; i++)
    {
        if (email_om_p->acct_callback[i] != NULL)
        {
            (email_om_p->acct_callback[i]) (notify);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_om_get_msg_permission
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 *  type        [IN]        
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
MMI_BOOL srv_email_om_get_msg_permission(EMAIL_MSG_ID msg_id, srv_email_om_permission_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_email_msg_able_to_get_permission(msg_id, type);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_om_get_fldr_permission
 * DESCRIPTION
 *  
 * PARAMETERS
 *  acct_id     [IN]        
 *  fldr_id     [IN]        
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_email_om_get_fldr_permission(
            EMAIL_ACCT_ID acct_id,
            EMAIL_FLDR_ID fldr_id,
            srv_email_om_permission_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_email_fldr_able_to_get_permission(acct_id, fldr_id, type);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_om_get_acct_permission
 * DESCRIPTION
 *  
 * PARAMETERS
 *  acct_id     [IN]        
 *  type        [IN]        
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
MMI_BOOL srv_email_om_get_acct_permission(EMAIL_ACCT_ID acct_id, srv_email_om_permission_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_msg_acct_able_to_delete(acct_id))
    {
        return MMI_FALSE;
    }

    return srv_email_acct_able_to_get_permission(acct_id, type);
}

