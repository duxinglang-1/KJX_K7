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

/*******************************************************************************
 * Filename:
 * ---------
 * vmpn.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  MRE push
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
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/


#include "mmi_features.h"
#include "vmswitch.h"
#include "PnSrvGprot.h"

// TODO: header file of zhibo
//#include ""

#ifdef __MRE_SAL_PN__
#include "vmpn.h"
#include "vmresmng.h"
#include "vmmod.h"
#include "vmcert.h"
#include "vmgettag.h"
#include "vmmem.h"
#include "vmchset.h"
#include "vmcert.h"
#include "MMI_trc.h"

extern mmi_ret srv_mre_push_receiver_pns_deregister(U32 appId);
extern mmi_ret srv_mre_push_receiver_pns_register(U32 appId,char* senderId, mmi_proc_func cb, void* user_data);
extern mmi_ret srv_mre_push_receiver_pns_query(vm_srv_pns_query_event event,int AppID,void* userdata);
extern mmi_ret srv_mre_push_receiver_set_notify_style(U32 appId,vm_srv_pns_notify_switch OnOff,vm_srv_pns_notify_style style);
extern mmi_ret srv_mre_push_receiver_set_badge_number(U32 appId,U32 badge);

typedef struct 
{
    VM_P_HANDLE p_hdl;
    void * user_data;
    vm_pn_cb cb;
}vm_pn_ctx_t;

//static vm_pn_cb _cb = NULL;
mmi_ret vm_pn_proc(mmi_event_struct *param, void * user_data)
{
    //mmi_event_struct * evt = (mmi_event_struct *)param;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_S, 6, __LINE__);
    switch (((mmi_event_struct *)param)->evt_id)
    {
        case EVT_ID_SRV_PNS_REGISTER_RSP:
        {
            vm_srv_pns_identity_event_struct app_reg_evt;
            srv_pns_reg_rsp_event_struct * reg_evt = (srv_pns_reg_rsp_event_struct *)param;
            vm_pn_ctx_t * ctx_p = (vm_pn_ctx_t *)user_data;
            
            app_reg_evt.result = (vm_srv_pns_result)reg_evt->result;
            app_reg_evt.appId = reg_evt->appId;
            memcpy(app_reg_evt.reg_id, reg_evt->reg_id, VM_SRV_PNS_REGID_LEN);
            app_reg_evt.evt_id = reg_evt->evt_id;
            app_reg_evt.size = reg_evt->size;
            
            MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_LOG, 
                app_reg_evt.result, 
                app_reg_evt.appId, 
                app_reg_evt.evt_id, 
                app_reg_evt.size,
                0, 
                0,
                6, __LINE__);
            
            MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_S, 61, __LINE__);
            
            if (ctx_p)
            {
                app_reg_evt.user_data = ctx_p->user_data;

                MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_LOG, 
                    0, 
                    0, 
                    0, 
                    ctx_p->cb, 
                    ctx_p->p_hdl,
                    app_reg_evt.user_data,
                    61, __LINE__);

                if (ctx_p->cb)
                {
                    PMNG_WRAP_CALLBACK(ctx_p->p_hdl, 
                    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_E1, 61, __LINE__);
                    ctx_p->cb((vm_srv_pns_event_struct *)&app_reg_evt, app_reg_evt.user_data));
                }

                MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_E2, 61, __LINE__);
                _vm_kernel_free(ctx_p);
            }

            
            MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_E, 61, __LINE__);

        }break;
    }
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_E, 6, __LINE__);

    return 0;
}

VMINT vm_pn_query(vm_srv_pns_query_event query_id, void* user_data)
{
    mmi_ret		ret = MMI_FALSE;
    U32				appId;
    VMWCHAR*		fullFilename;
    S32 			app_id_buf_size = 26;
    S8				*sender_id_buf;
    S32 			sender_id_buf_size = ((48)*sizeof(char));
    char*			senderId;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_S, 3, __LINE__);
    if ((VMINT)query_id < 0 || VM_SRV_MRE_MPR_QUERY_END <= query_id)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_E1, 3, __LINE__);
        return -2;
    }
    
    // 1.get app file path
    if (NULL != (fullFilename = vm_calloc((MAX_APP_NAME_LEN + 1) * sizeof(VMWCHAR)))){
    if (0 != vm_get_exec_filename(fullFilename)){
        vm_free(fullFilename);
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_E2, 30, __LINE__);
        return -4;
        }
    }
    // 1.get app file path	 
    if (NULL == (sender_id_buf = vm_calloc((48) * sizeof(VMWCHAR)))){
        vm_free(fullFilename);
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_E2, 31, __LINE__);
        return -4;
    }
    if (NULL == (senderId = vm_calloc((48) * sizeof(VMCHAR)))){		
        vm_free(fullFilename);
        vm_free(sender_id_buf);
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_E2, 32, __LINE__);
        return -4;
    }

    // 2.read tag. 
    if(GET_TAG_TRUE == vm_get_vm_tag(fullFilename, VM_CE_INFO_PUSH_APPID, &appId, &app_id_buf_size))
    {
        ret = srv_mre_push_receiver_pns_query(query_id, appId, (void*)user_data);			
    }
    
	
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_LOG, 
        query_id, 
        senderId, 
        appId, 
        ret,
        0, 
        0,
        3, __LINE__);

    vm_free(fullFilename);
    vm_free(sender_id_buf);
    vm_free(senderId);

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_E, 3, __LINE__);
    
    return ret;
}


VMINT vm_pn_is_support(void)
{
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_S, 0, __LINE__);
    return 1;
}

VMINT vm_pn_get_global_setting(void)
{
    VMINT ret = 0;
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_S, 13, __LINE__);
    ret = (VMINT)srv_pns_get_global_setting();
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_E, 13, ret);
    return ret;
}


VMINT vm_pn_reg(vm_pn_cb cb, void* user_data)
{
    mmi_ret		ret = MMI_FALSE;
    U32				appId = 0;
    char*			senderId;
    //VM_P_HANDLE	phandle = 0;
    vm_pn_ctx_t * ctx_p;
    // TODO: appid, senderid. hadn't test
#if 1

    VMWCHAR*		fullFilename;
    VMUINT			is_support_push=0;
    VMINT			bufSize = 4;
    S32 			app_id_buf_size = 26;
    VMWSTR		    sender_id_buf;
    S32 			sender_id_buf_size = ((48)*sizeof(char));

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_S, 1, __LINE__);
    if (NULL == cb)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_E1, 1, __LINE__);
        return -2;
    }

    ctx_p = (vm_pn_ctx_t*)_vm_kernel_calloc(sizeof(vm_pn_ctx_t));
    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_E2, 1, __LINE__);
        return -3;
    }

    ctx_p->cb = cb;
    ctx_p->p_hdl = vm_pmng_get_current_handle();
    ctx_p->user_data = user_data;

    // 1.get app file path	 
    if (NULL != (fullFilename = vm_calloc((MAX_APP_NAME_LEN + 1) * sizeof(VMWCHAR)))){
        if (0 != vm_get_exec_filename(fullFilename)){
            vm_free(fullFilename);
            vm_free(ctx_p);
            MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_E3, 10, __LINE__);
            return -4;
        }
    }
    // 1.get app file path	 
    if (NULL == (sender_id_buf = vm_calloc((48) * sizeof(VMWCHAR)))){
        vm_free(fullFilename);
        vm_free(ctx_p);
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_E3, 11, __LINE__);
        return -4;
    }
    if (NULL == (senderId = vm_calloc((48) * sizeof(VMCHAR)))){		
        vm_free(fullFilename);
        vm_free(sender_id_buf);
        vm_free(ctx_p);
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_E3, 12, __LINE__);
        return -4;
    }

	// 2.read tag.
    if (vm_get_vm_tag(fullFilename, VM_CE_INFO_PUSH, &is_support_push, &bufSize) == GET_TAG_TRUE && is_support_push == 1)
    {

        if(GET_TAG_TRUE == vm_get_vm_tag(fullFilename, VM_CE_INFO_PUSH_APPID, &appId, &app_id_buf_size))
        {
            ret = MMI_TRUE;
        }
        if(GET_TAG_TRUE == vm_get_vm_tag(fullFilename, VM_CE_INFO_PUSH_SENDERID, sender_id_buf, &sender_id_buf_size))
        {	
            int i = 0;
            i = vm_ucs2_to_ascii(senderId, 48, sender_id_buf);
            if (i){
                ret = MMI_FALSE;
            }
            else{
                ret = MMI_TRUE;
            }
        }

    }

	
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_LOG, 
        appId, 
        senderId, 
        ret,
        ctx_p->cb, 
        ctx_p->p_hdl,
        ctx_p->user_data,
        1, __LINE__);

    ret = srv_mre_push_receiver_pns_register(appId, senderId, (mmi_proc_func)vm_pn_proc, (void *)ctx_p);
    
    vm_free(sender_id_buf);
    vm_free(fullFilename);
    vm_free(senderId);
    
#endif    

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_E, ret, __LINE__);
    
    return (VMINT)ret;
}

VMINT vm_pn_dereg()
{
    mmi_ret ret = 0;
    U32 appId = 0;

    // TODO: get appid. hadn't test
#if 1
    VMWCHAR*		fullFilename;
    VMINT			bufSize = 0;
    S32 			app_id_buf_size = 4;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_S, 2, __LINE__);
    // 1.get app file path	 
    if (NULL != (fullFilename = vm_calloc((MAX_APP_NAME_LEN + 1) * sizeof(VMWCHAR))))
    {		
        if (0 != vm_get_exec_filename(fullFilename) )
        {
            vm_free(fullFilename);
            MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_E1, 2, __LINE__);
            return -2;
        }
    }
    
    // TODO: if @3241234.rom ?
    // 2.read tag.
    if(GET_TAG_TRUE == vm_get_vm_tag(fullFilename, VM_CE_INFO_PUSH_APPID, &appId, &app_id_buf_size))
    {
        ret = MMI_TRUE;
    }	
#endif    

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_LOG, 
        appId, 
        app_id_buf_size, 
        ret,
        0, 
        0,
        0,
        2, __LINE__);


    ret = srv_mre_push_receiver_pns_deregister(appId);

    
    vm_free(fullFilename);
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_E, ret, __LINE__);
    
    return (VMINT)ret;
}

VMINT vm_pn_get_mps_info_ex(const VMCHAR * msgBody, vm_srv_pns_msg_mps_struct_ex * mpsPtr)
{
    srv_pns_result rst;
    srv_pns_msg_mps_struct mps;
    VMINT i;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_S, 4, __LINE__);
    if (NULL == msgBody || NULL == mpsPtr)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_E1, 4, __LINE__);
        return -2;
    }

    rst = srv_pns_get_mps_info((char *)msgBody, &mps);

    if (SRV_PNS_NO_ERROR == rst)
    {
        mpsPtr->mainLen = mps.mainLen;
        memcpy(mpsPtr->main, mps.main, VM_SRV_PNS_ALERT_TEXT_MAX_LEN);
        mpsPtr->hintLen = mps.hintLen;
        memcpy(mpsPtr->hint, mps.hint, VM_SRV_PNS_ALERT_TEXT_MAX_LEN);
        mpsPtr->mainResId = mps.mainResId;
		mpsPtr->main_args_num = mps.main_args_num;
		for(i=0;i<mpsPtr->main_args_num;i++)
			memcpy(mpsPtr->main_args[i],mps.main_args[i],SRV_PNS_MAX_MPS_ARG_LEN);
        mpsPtr->hintResId = mps.hintResId;
		mpsPtr->hint_args_num = mps.hint_args_num;
		for(i=0;i<mpsPtr->hint_args_num;i++)
			memcpy(mpsPtr->hint_args[i],mps.hint_args[i],SRV_PNS_MAX_MPS_ARG_LEN);
        mpsPtr->actionLen = mps.actionLen;
        memcpy(mpsPtr->action, mps.action, VM_SRV_PNS_ACTION_TEXT_MAX_LEN);
		mpsPtr->actionResId = mps.actionResId;
        mpsPtr->badge = mps.badge;
        mpsPtr->icon = mps.icon;
        mpsPtr->sound = mps.sound;
    }

    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_LOG, 
        mpsPtr->mainLen, 
        mpsPtr->hintLen, 
        mpsPtr->mainResId,
        mpsPtr->hintResId, 
        mpsPtr->badge,
        rst,
        4, __LINE__);

            
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_LOG, 
        mpsPtr->icon, 
        mpsPtr->sound, 
        mpsPtr->actionResId,
        mpsPtr->hint_args_num, 
        mpsPtr->main_args_num,
        0,
        41, __LINE__);
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_E, 4, __LINE__);
    return (vm_srv_pns_result)rst;
}

VMINT vm_pn_get_mps_info(const VMCHAR * msgBody, vm_srv_pns_msg_mps_struct * mpsPtr)
{
    srv_pns_result rst;
    srv_pns_msg_mps_struct mps = {0};

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_S, 4, __LINE__);
    if (NULL == msgBody || NULL == mpsPtr)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_E1, 4, __LINE__);
        return -2;
    }

    rst = srv_pns_get_mps_info((char *)msgBody, &mps);

    if (SRV_PNS_NO_ERROR == rst)
    {
        mpsPtr->mainLen = mps.mainLen;
        memcpy(mpsPtr->main, mps.main, VM_SRV_PNS_ALERT_TEXT_MAX_LEN);
        mpsPtr->hintLen = mps.hintLen;
        memcpy(mpsPtr->hint, mps.hint, VM_SRV_PNS_ALERT_TEXT_MAX_LEN);
        mpsPtr->mainResId = mps.mainResId;
        mpsPtr->hintResId = mps.hintResId;
        mpsPtr->actionLen = mps.actionLen;
        memcpy(mpsPtr->action, mps.action, VM_SRV_PNS_ACTION_TEXT_MAX_LEN);
        mpsPtr->badge = mps.badge;
        mpsPtr->icon = mps.icon;
        mpsPtr->sound = mps.sound;
    }

    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_LOG, 
        mpsPtr->mainLen, 
        mpsPtr->hintLen, 
        mpsPtr->mainResId,
        mpsPtr->hintResId, 
        mpsPtr->badge,
        rst,
        4, __LINE__);

            
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_LOG, 
        mpsPtr->icon, 
        mpsPtr->sound, 
        0,
        0, 
        0,
        0,
        41, __LINE__);
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_E, 4, __LINE__);
    return (vm_srv_pns_result)rst;
}

VMINT vm_pn_get_object(const VMCHAR * msgBody, const VMCHAR * key, vm_srv_pns_msg_value_struct * value)
{
    srv_pns_result rst;
    srv_pns_msg_value_struct mps;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_S, 5, __LINE__);
    if (NULL == msgBody || NULL == key || NULL == value)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_E1, 5, __LINE__);
        return -2;
    }

    rst = srv_pns_get_object((char *)msgBody, (char *)key, &mps);
    if (SRV_PNS_NO_ERROR == rst)
    {
        value->dictionary = mps.dictionary;
        memcpy(value->msgBody, mps.msgBody, VM_SRV_PNS_MAX_MSGBODY_SIZE);
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_LOG, 
        value->dictionary, 
        rst, 
        0,
        0, 
        0,
        0,
        5, __LINE__);

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_E, 5, __LINE__);
    return (vm_srv_pns_result)rst;
}

VMINT vm_pn_set_notify_style(vm_srv_pns_notify_switch OnOff, vm_srv_pns_notify_style style)
{
    VMINT ret;
    U32 appId = 0;
    VMWCHAR * fullFilename;
    VMUINT is_support_push =0;
    VMINT	 bufSize = 4;
    S32 app_id_buf_size = 26;
    mmi_ret ret_int;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_S, 6, __LINE__);
    // parameter check
    if((OnOff < VM_SRV_MRE_MPR_NOTIFY_OFF) ||(OnOff >= VM_SRV_MRE_MPR_NOTIFY_END))
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_E1, 6, __LINE__);
        return -2;	
    }
    
    if(((VMINT)style<0) ||(style >= VM_SRV_MRE_MPR_NOTIFY_STYLE_END))
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_E2, 6, __LINE__);
        return -2;	
    }

    // 1.get app file path	 
    if (NULL != (fullFilename = vm_calloc((MAX_APP_NAME_LEN + 1) * sizeof(VMWCHAR)))){
        if (0 != vm_get_exec_filename(fullFilename)){
            vm_free(fullFilename);
            MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_E3, 6, __LINE__);
            return -4;
        }
    }	
    
    // 2.read tag.
    if (vm_get_vm_tag(fullFilename, VM_CE_INFO_PUSH, &is_support_push, &bufSize) == GET_TAG_TRUE && is_support_push == 1)
    {
        vm_get_vm_tag(fullFilename, VM_CE_INFO_PUSH_APPID, &appId, &app_id_buf_size);
    }

    
    // 3.set notify stlye
    ret_int = srv_mre_push_receiver_set_notify_style(appId, OnOff, style);
    if (0 == ret_int)
    {
        ret = 0;
    }
    else
    {
        ret = -5;
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_LOG, 
        appId, 
        OnOff, 
        style,
        ret_int, 
        0,
        0,
        6, __LINE__);
    
    vm_free(fullFilename);
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_E, 6, __LINE__);
    return (VMINT)ret;
}

VMINT vm_pn_set_badge(VMINT32 badege_number)
{
    mmi_ret ret_int;
    U32 appId = 0;
    VMWCHAR * fullFilename;
    VMUINT is_support_push =0;
    VMINT bufSize = 4;
    S32 app_id_buf_size = 26;
    VMINT ret;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_S, 7, __LINE__);
    if(badege_number<0)	// parameter check
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_E1, 7, __LINE__);
        return -2;	// bad parameter
    }

    // 1.get app file path	 
    if (NULL != (fullFilename = vm_calloc((MAX_APP_NAME_LEN + 1) * sizeof(VMWCHAR)))){
        if (0 != vm_get_exec_filename(fullFilename)){
            vm_free(fullFilename);
            MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_E2, 7, __LINE__);
            return -4;
        }
    }

    // 2.read tag.
    if (vm_get_vm_tag(fullFilename, VM_CE_INFO_PUSH, &is_support_push, &bufSize) == GET_TAG_TRUE && is_support_push == 1)
    {
        vm_get_vm_tag(fullFilename, VM_CE_INFO_PUSH_APPID, &appId, &app_id_buf_size);
    }

    // 3.set notify stlye
    ret_int = srv_mre_push_receiver_set_badge_number(appId, badege_number);
    if (0 == ret_int)
    {
        ret = 0;
    }
    else
    {
        ret = -5;
    }
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_LOG, 
        appId, 
        badege_number, 
        ret_int, 
        0,
        0,
        0,
        7, __LINE__);

    vm_free(fullFilename); 	
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMSOCK_PN_E, 7, __LINE__);
    return (VMINT)ret;

}
#endif /* __MRE_SAL_PN__ */

