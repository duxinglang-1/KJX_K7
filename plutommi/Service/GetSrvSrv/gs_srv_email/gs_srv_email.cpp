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
 *   gs_srv_email.cpp
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   IEmail implement file
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

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 
#include "mmi_include.h"
#include "custom_mmi_default_value.h"
#include "nvram_common_defs.h"
#include "EmailAppGprot.h"
#ifdef __cplusplus
}
#endif 

#include "gs_srv_email_impl.h"
#include "vmpromng.h"

typedef void (*common_cb)(gs_srv_email_app_mre_send_error_code_enum errcode, void* user_data);

typedef struct
{
    VM_P_HANDLE handle;
    common_cb cb;
    void* user_data;
}callback_data;

void common_callback(gs_srv_email_app_mre_send_error_code_enum errcode,void* user_data)
{
    callback_data* data = (callback_data*)user_data;

    MMI_PRINT(MOD_MRE, TRACE_GROUP_1, "[MRE] common_callback");

    if (VM_PMNG_OP_OK == vm_pmng_set_ctx(data->handle))
    {
        if (data->cb)
        {
            (*data->cb)(errcode,data->user_data);      
        }
		gs_free(data);
        vm_pmng_reset_ctx();
    }  
}

GS_IBase *CreateEmailService(U32 hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EmailService* service = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    GS_NEW_EX(service, EmailService,(hd));
    return (GS_IBase*)(GS_CBase*)service;
}


S32 EmailService::queryInterface(S32 iid, GS_IBase **pptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Please notes: pptr may be a proxy, your call should not use it directly. */
    if (pptr == NULL)
        return 0;
    if (iid == IID_IMMS)
    {
        addRef();
        *pptr = BIND_PROXY(IEmail, this);
        return 1;
    }
    return GS_CBase::queryInterface(iid, pptr);
}



gs_srv_email_app_mre_send_error_code_enum EmailService::send_email(gs_srv_email_app_mre_send_param_struct *para, 
                                    gs_srv_email_app_mre_send_result_callback cb, 
                                    void* user_data,
                                    S32* req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_EMAIL_MRE_BACKGROUND__) && defined(__MMI_EMAIL__) && !defined(__COSMOS_MMI_PACKAGE__)
    callback_data* pdata = NULL;
    addRef();
    release();
    if (gs_is_MRE_free() && cb)
    {      
        pdata = (callback_data*)vm_malloc(sizeof(callback_data));
        if (!pdata)
        {
            return GS_SRV_EMAIL_APP_MRE_ERROR_CODE_UNKNOWN_ERROR;
        }
        pdata->cb = (common_cb)cb;
        pdata->handle = vm_pmng_get_current_handle();
        pdata->user_data = user_data;
        return (gs_srv_email_app_mre_send_error_code_enum)mmi_email_app_mre_send(
            (mmi_email_app_mre_send_param_struct*)para, 
            (mmi_email_app_mre_send_result_callback)common_callback, 
            (void*)pdata,
            req_id);
    }
    else
    {
        return (gs_srv_email_app_mre_send_error_code_enum)mmi_email_app_mre_send(
            (mmi_email_app_mre_send_param_struct*)para, 
            (mmi_email_app_mre_send_result_callback)cb, 
            (void*)user_data,
            req_id);
    }
#else //definded(__MMI_EMAIL_MRE_BACKGROUND__) && definded(__MMI_EMAIL__)
    return GS_SRV_EMAIL_APP_MRE_ERROR_CODE_UNKNOWN_ERROR;
#endif
}

MMI_BOOL EmailService::cancel_send_email(S32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_EMAIL_MRE_BACKGROUND__) && defined(__MMI_EMAIL__) && !defined(__COSMOS_MMI_PACKAGE__)   
    return mmi_email_app_mre_send_abort(req_id);
#else
    return MMI_FALSE;
#endif
}


