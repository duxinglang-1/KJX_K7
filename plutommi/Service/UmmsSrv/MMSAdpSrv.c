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
 *   mmsadp.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contain all common MMS functions defined mmsadp.h
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
#ifndef _MMSADP_C
#define _MMSADP_C

#include "MMI_features.h"
#include "MMIDataType.h"
//#include "kal_general_types.h"
//#include "kal_public_api.h"


#include "kal_public_defs.h" 
#include "custom_wap_config.h"
#include "mma_struct.h"
#include "mmc_struct.h"
#include "mms_adp_struct.h"
#include "mms_sap_struct.h"
#include "mms_api.h"
#include "mma_api.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "mmsadp.h"
#include "wapadp.h"

/* PlutoMMI */
// #include "SimDetectionGprot.h"
#include "NwInfoSrvGprot.h"

/* APPLIB */
#include "app_mine.h"
#include "app_str.h"
#include "Unicodexdcl.h"
#ifdef __MMI_MMS_IN_UM__
#ifndef __COSMOS_MMI_PACKAGE__
#include "UMGProt.h"
#endif 
#include "UmSrvGprot.h"
#endif /* __MMI_MMS_IN_UM__ */ 

#if (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__))
#include "UcAppGprot.h"
#include "UcSrvGprot.h"
#endif /* (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__)) */ 
#ifndef __COSMOS_MMI_PACKAGE__
#include "MMSAppInterfaceGprot.h"
#endif 
#include "UmSrvStruct.h"
#include "UmSrvDefs.h"
#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGProt.h"
#include "USBSrvGProt.h"
/* extern pBOOL mmi_usb_is_in_mass_storage_mode(void); */
extern void mmi_usb_app_unavailable_popup(kal_uint16 stringId);
#endif /* __USB_IN_NORMAL_MODE__ */ 

#ifdef __WIFI_SUPPORT__
/* WLAN includes */
#include "NetSetSrvGprot.h"
#include "NetSetAppGprot.h"
#endif /* __WIFI_SUPPORT__ */ 

#include "EngineerModeInetAppGprot.h"   /* Added for Engineer Mode */

#include "ModeSwitchSrvGprot.h"
#include "MmsSrvGprot.h"
#if defined(MMS_SUPPORT)
#ifdef __MMI_MMS_FALLBACK__
extern void srv_mms_refresh_profile_settings(U8 sim_id);
#endif 
#include "app_ua.h"
#ifdef __DRM_SUPPORT__
#include "drm_def.h"
#include "DRM_gprot.h"
#endif /* __DRM_SUPPORT__ */ 

#include "MMSTemplateGenSrv.h"

extern void mms_multi_object_insert_req(void *in_data_p, int mod_src, void *peerBuf);
extern void mms_multi_object_insert_continue_ind(void *in_data_p, int mod_src, void *peerBuf);

extern void mms_mma_send_ilm(void *local_para_ptr, void *peer_buff_ptr, msg_type msg_id, module_type dst_id);


/*****************************************************************************
 * FUNCTION
 *  mms_set_protocol_event_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mms_set_protocol_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMS Multiselect Primitives */
    SetProtocolEventHandler(mms_multi_object_insert_req, MSG_ID_MMS_MULTI_OBJECT_INSERT_REQ);
    SetProtocolEventHandler(mms_multi_object_insert_continue_ind, MSG_ID_MMS_MULTI_OBJECT_INSERT_CONTINUE_IND);

}


/*****************************************************************************
 * FUNCTION
 *  mms_adp_mmi_sap_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mms_adp_mmi_sap_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mms_set_protocol_event_handler();
}


/*****************************************************************************
 * FUNCTION
 *  mms_send_ilm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [IN]        
 *  peer_buff_ptr       [IN]        
 *  msg_id              [IN]        
 *  dst_id              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_send_ilm(void *local_para_ptr, void *peer_buff_ptr, msg_type msg_id, module_type dst_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* MYQUEUE Message; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_send_ilm(
        (oslModuleType) dst_id,
        (oslMsgType) msg_id,
        (oslParaType*) local_para_ptr,
        (oslPeerBuffType*) peer_buff_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  mms_send_multi_object_insert_msg_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  source      [IN]        
 *  result      [IN]        
 *  req_id      [IN]        
 *  void*(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mms_send_multi_object_insert_msg_rsp(module_type source, kal_uint32 result, kal_uint32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_multi_object_insert_rsp_struct *mms_insert_multi_object_rsp_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mms_insert_multi_object_rsp_p =
        (mms_multi_object_insert_rsp_struct*) construct_local_para(
                                                sizeof(mms_multi_object_insert_rsp_struct),
                                                TD_CTRL | TD_RESET);

    mms_insert_multi_object_rsp_p->request_id = req_id;
    mms_insert_multi_object_rsp_p->result =(kal_bool)result;

    mms_send_ilm(mms_insert_multi_object_rsp_p, NULL, MSG_ID_MMS_MULTI_OBJECT_INSERT_RSP, source);
}


/*****************************************************************************
 * FUNCTION
 *  mms_send_multi_object_insert_continue_ind_res
 * DESCRIPTION
 *  
 * PARAMETERS
 *  source          [IN]        
 *  request_id      [IN]        
 *  result          [IN]        
 *  void*(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mms_send_multi_object_insert_continue_ind_res(module_type source, kal_uint32 request_id, kal_bool result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_multi_object_insert_continue_res_struct *mms_insert_multi_object_continue_res_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mms_insert_multi_object_continue_res_p =
        (mms_multi_object_insert_continue_res_struct*)
        construct_local_para(sizeof(mms_multi_object_insert_continue_res_struct), TD_CTRL | TD_RESET);

    mms_insert_multi_object_continue_res_p->request_id = request_id;
    mms_insert_multi_object_continue_res_p->result = result;

    mms_send_ilm(mms_insert_multi_object_continue_res_p, NULL, MSG_ID_MMS_MULTI_OBJECT_INSERT_CONTINUE_RES, source);
}


/*****************************************************************************
 * FUNCTION
 *  mms_multi_object_insert_continue_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_data_p       [?]         
 *  mod_src         [IN]        
 *  ilmptr_p        [?]         
 *  void*(?)
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __COSMOS_MMI_PACKAGE__
extern kal_bool mmi_uc_is_multi_object_req_is_in_process(void);
#endif 
void mms_multi_object_insert_continue_ind(void *in_data_p, int mod_src, void *ilmptr_p)
{
#ifndef __COSMOS_MMI_PACKAGE__
#if (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_multi_object_insert_continue_ind_struct *req_data = (mms_multi_object_insert_continue_ind_struct*) in_data_p;
    mmi_uc_entry_write_struct *uc_data = NULL;
    MYQUEUE *msg_p = (MYQUEUE*) ilmptr_p;
    void *peerBuf = msg_p->oslPeerBuffPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (req_data->is_aborted || mmi_uc_is_multi_object_req_is_in_process() == KAL_FALSE)
    {
        mms_send_multi_object_insert_continue_ind_res((module_type) mod_src, req_data->request_id, KAL_FALSE);
        mmi_uc_free_collected_object_ind_data();
        return;
    }
    if (req_data->more == KAL_TRUE)
    {
        mmi_uc_collect_object_ind_data(peerBuf, req_data->num_of_object, req_data->more, &uc_data);

        mms_send_multi_object_insert_continue_ind_res((module_type) mod_src, req_data->request_id, KAL_TRUE);
    }
    else
    {
        mmi_uc_collect_object_ind_data(peerBuf, req_data->num_of_object, req_data->more, &uc_data);
        uc_data->msg_type = MMI_UC_MSG_TYPE_MMS_ONLY;
        uc_data->info_type = MMI_UC_INFO_TYPE_MMS;

        mmi_uc_entry_write_msg_with_content(MMI_UC_STATE_WRITE_NEW_MSG, uc_data);
        mms_send_multi_object_insert_continue_ind_res((module_type) mod_src, req_data->request_id, KAL_TRUE);
        mmi_uc_free_collected_object_ind_data();
    }
#endif /* (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__)) */ 
#endif /* __COSMOS_MMI_PACKAGE__ */ 
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mms_multi_object_insert_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_data_p       [?]         
 *  mod_src         [IN]        
 *  ilmptr_p        [?]         
 *  void*(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mms_multi_object_insert_req(void *in_data_p, int mod_src, void *ilmptr_p)
{
#ifndef __COSMOS_MMI_PACKAGE__
#if (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_multi_object_insert_req_struct *req_data = (mms_multi_object_insert_req_struct*) in_data_p;
    mmi_uc_entry_write_struct *uc_data;
    MYQUEUE *msg_p = (MYQUEUE*) ilmptr_p;
    void *peerBuf = msg_p->oslPeerBuffPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_uc_multi_object_insert_req())
    {
        mms_send_multi_object_insert_msg_rsp(mod_src, KAL_FALSE, req_data->request_id);
    }
    else
    {
        if (req_data->more == KAL_TRUE)
        {
            mmi_uc_collect_object_ind_data(peerBuf, req_data->num_of_object, req_data->more, &uc_data);
            mms_send_multi_object_insert_msg_rsp(mod_src, KAL_TRUE, req_data->request_id);
        }
        else
        {
            mmi_uc_collect_object_ind_data(peerBuf, req_data->num_of_object, req_data->more, &uc_data);
            uc_data->msg_type = MMI_UC_MSG_TYPE_MMS_ONLY;
            uc_data->info_type = MMI_UC_INFO_TYPE_MMS;
            mmi_uc_entry_write_msg_with_content(MMI_UC_STATE_WRITE_NEW_MSG, uc_data);
            mms_send_multi_object_insert_msg_rsp(mod_src, KAL_TRUE, req_data->request_id);
            mmi_uc_free_collected_object_ind_data();
        }
    }
#endif /* (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__)) */ 
#endif /* __COSMOS_MMI_PACKAGE__ */ 
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mms_is_sim_valid
 * DESCRIPTION
 *  To Check sim valid or not
 * CALLS
 *  
 * PARAMETERS
 *  void
 *  content_source(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
int mms_is_sim_valid()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (srv_mms_is_sim_valid(MMI_SIM1)
#if (MMI_MAX_SIM_NUM >= 2)
            || srv_mms_is_sim_valid(MMI_SIM2)
#if (MMI_MAX_SIM_NUM >= 3)
            || srv_mms_is_sim_valid(MMI_SIM3)
#if (MMI_MAX_SIM_NUM >= 4)
            || srv_mms_is_sim_valid(MMI_SIM4)
#endif /* (MMI_MAX_SIM_NUM >= 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */ /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */ /* (MMI_MAX_SIM_NUM >= 2) */
        );
}


/*****************************************************************************
 * FUNCTION
 *  mms_is_ready
 * DESCRIPTION
 *  The function is used to check if mms application is ready
 * PARAMETERS
 *  void
 * RETURNS
 *  0: FASLE, 1: TRUE
 *****************************************************************************/
int mms_is_ready()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (srv_mms_is_ready() 
#ifdef __MMI_MMS_IN_UM__
            && srv_um_check_ready()
#endif 
        );
}

#ifdef __MMI_MMS_FALLBACK__


/*****************************************************************************
 * FUNCTION
 *  mms_refresh_profile
 * DESCRIPTION
 *  The function is used to refresh profile settings
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_refresh_profile(kal_int32 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_refresh_profile_settings((U8) sim_id);

}
#endif /* __MMI_MMS_FALLBACK__ */ 

#if (defined(__MMI_MMS_2__) || defined(__MMI_MMS_BGSR_SUPPORT__))


/*****************************************************************************
 * FUNCTION
 *  mms_send_msg
 * DESCRIPTION
 *  send message request
 * PARAMETERS
 *  sim_id              [IN]        
 *  msg_id              [IN]        -  the message id
 *  storage_type        [IN]        
 *  app_id              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 mms_send_msg(kal_int32 sim_id, kal_uint32 msg_id, kal_uint8 storage_type, kal_uint16 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_2__
    extern U8 srv_mms_entry_send_msg(const U32 msg_id, kal_uint8 sim_id, U8 storage_type, U8 app_id);

    return srv_mms_entry_send_msg(msg_id, (kal_uint8) sim_id, storage_type, (kal_uint8) app_id);
#else /* __MMI_MMS_2__ */ 
    return srv_mms_bgsr_send_req(sim_id, msg_id, 0, mma_conf_get_send_setting());
#endif /* __MMI_MMS_2__ */ 
}
#endif /* (defined(__MMI_MMS_2__) || defined(__MMI_MMS_BGSR_SUPPORT__)) */ 


/*****************************************************************************
 * FUNCTION
 *  mms_mma_is_open
 * DESCRIPTION
 *  The function is used to check if MMS is opened.
 * PARAMETERS
 *  void
 * RETURNS
 *  0: FASLE, 1: TRUE
 *****************************************************************************/
int mms_mma_is_open()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* return (msm_get_module_status (MSF_MODID_MMA) == MODULE_STATUS_ACTIVE); */
    return 1;   /* This API can be removed */
}


/*****************************************************************************
 * FUNCTION
 *  goto_mms_screen
 * DESCRIPTION
 *  MMS entry point from MMI menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void goto_mms_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mms_is_reentrant
 * DESCRIPTION
 *  The function is used to check if UM enter MMS menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  KAL_FASLE, KAL_TRUE
 *****************************************************************************/
int mms_is_reentrant()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mms_is_ready())
    {
        return KAL_FALSE;
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mms_get_content_class
 * DESCRIPTION
 *  This function is used to get mms content class
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  mms_content_class_enum
 *****************************************************************************/
mms_content_class_enum mms_get_content_class(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_content_class_enum result = MMS_CONTENT_CLASS_TEXT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(MP4_DECODE) && defined(JPG_DECODE) && defined(__MMI_VCALENDAR__) && defined(__MMI_VCARD__) && defined(__DRM_SUPPORT__) && WAP_CUSTOM_CFG_MAX_MMS_MSG_SIZE >= 300*1024)
    result = MMS_CONTENT_CLASS_VIDEO_RICH;
#elif (defined(MP4_DECODE) && defined(JPG_DECODE) && defined(__MMI_VCALENDAR__) && defined(__MMI_VCARD__) && defined(__DRM_SUPPORT__) && WAP_CUSTOM_CFG_MAX_MMS_MSG_SIZE >= 100*1024)
    result = MMS_CONTENT_CLASS_VIDEO_BASIC;
#elif (defined(JPG_DECODE) && defined(__MMI_VCALENDAR__) && defined(__MMI_VCARD__) && defined(__DRM_SUPPORT__) && WAP_CUSTOM_CFG_MAX_MMS_MSG_SIZE >= 100*1024)
    result = MMS_CONTENT_CLASS_IMAGE_RICH;
#elif (defined(JPG_DECODE) && defined(__MMI_VCALENDAR__) && defined(__MMI_VCARD__) && WAP_CUSTOM_CFG_MAX_MMS_MSG_SIZE >= 30*1024)
    result = MMS_CONTENT_CLASS_IMAGE_BASIC;
#endif 
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mms_get_max_msg_size_in_restricted_mode
 * DESCRIPTION
 *  This function is used to get max mms size in restricted creation mode
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  Max size
 *****************************************************************************/
kal_uint32 mms_get_max_msg_size_in_restricted_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_content_class_enum mms_content_class = mms_get_content_class();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mms_content_class == MMS_CONTENT_CLASS_VIDEO_RICH)
    {
        return 300 * 1024;
    }
    else if (mms_content_class == MMS_CONTENT_CLASS_VIDEO_BASIC || mms_content_class == MMS_CONTENT_CLASS_IMAGE_RICH)
    {
        return 100 * 1024;
    }
    else
    {
        return 30 * 1024;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mms_get_max_image_resolution_in_restricted_mode
 * DESCRIPTION
 *  The function is used to get image resolution limit in restricted mode
 * PARAMETERS
 *  width       [OUT]       
 *  height      [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void mms_get_max_image_resolution_in_restricted_mode(kal_int32 *width, kal_int32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_content_class_enum mms_content_class = mms_get_content_class();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mms_content_class)
    {
        case MMS_CONTENT_CLASS_IMAGE_BASIC:
            *width = 160;
            *height = 120;
            break;

        case MMS_CONTENT_CLASS_IMAGE_RICH:
        case MMS_CONTENT_CLASS_VIDEO_BASIC:
        case MMS_CONTENT_CLASS_VIDEO_RICH:
            *width = 640;
            *height = 480;
            break;

        case MMS_CONTENT_CLASS_TEXT:
        case MMS_CONTENT_CLASS_UNKNOWN:
        default:
            *width = 0;
            *height = 0;
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mms_is_content_forward
 * DESCRIPTION
 *  The function is used to check if the media can be forwarded to MMS
 * PARAMETERS
 *  filename        [IN]        Encoded by UCS2
 * RETURNS
 *  0: FASLE, 1: TRUE
 *****************************************************************************/
int mms_is_content_forward(const char *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mms_is_ready())
    {
    #ifdef __DRM_SUPPORT__
        drm_method_enum type = DRM_METHOD_NONE;
    #endif 
        {
            kal_wchar *extension = srv_fmgr_path_get_extension_ptr((WCHAR*) filename);

            if (extension && app_ucs2_strcmp((const kal_int8*)extension, (const kal_int8*)L"dm") == 0)
            {
                return FALSE;
            }
        }
    #ifdef __DRM_SUPPORT__
        /* check drm */
        type = DRM_get_object_method(0, (kal_wchar*) filename);
        if (type == DRM_METHOD_FORWARD_LOCK || type == DRM_METHOD_COMBINED_DELIVERY)
        {
            return FALSE;
        }
    #endif /* __DRM_SUPPORT__ */ 
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
		{
			applib_mime_type_struct *file_type = applib_mime_get_file_type((kal_wchar *)filename);
		#ifdef __MMI_MMS_LT_NO_AUDIO_SUPPORT__
			if(file_type->mime_type == MIME_TYPE_AUDIO)
			{
				return FALSE;
			}
		#endif
		#ifdef __MMI_MMS_LT_NO_ATTACHMENT_SUPPORT__
			if(file_type->mime_type != MIME_TYPE_IMAGE && file_type->mime_type != MIME_TYPE_VIDEO && file_type->mime_type != MIME_TYPE_AUDIO)
			{
				return FALSE;
			}
		#endif
		}
#endif /*__MMI_MMS_SIMPLIFIED_UI_SUPPORT__*/
        return TRUE;
    }
    return FALSE;
}

#ifdef __USB_IN_NORMAL_MODE__


/*****************************************************************************
 * FUNCTION
 *  mms_on_enter_usb_mode
 * DESCRIPTION
 *  This function is invoked when entering USB mode. When WAP MMS is ready
 *  send MSG_ID_MMS_ENTER_USB_MODE_RSP to MMI.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mms_on_enter_usb_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* MYQUEUE Message; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Message.oslSrcId = MOD_MMI;
     * Message.oslDestId = MOD_MMS;
     * Message.oslMsgId = MSG_ID_MMS_ENTER_USB_MODE_REQ;
     * Message.oslDataPtr = NULL;
     * Message.oslPeerBuffPtr = NULL;
     * OslMsgSendExtQueue(&Message);
     */
    mmi_frm_send_ilm(MOD_MMS, MSG_ID_MMS_ENTER_USB_MODE_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mms_on_exit_usb_mode
 * DESCRIPTION
 *  This function is invoked when leaving USB mode. When WAP MMS is ready
 *  send MSG_ID_MMS_EXIT_USB_MODE_RSP to MMI.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mms_on_exit_usb_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* MYQUEUE Message; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Message.oslSrcId = MOD_MMI;
     * Message.oslDestId = MOD_MMS;
     * Message.oslMsgId = MSG_ID_MMS_EXIT_USB_MODE_REQ;
     * Message.oslDataPtr = NULL;
     * Message.oslPeerBuffPtr = NULL;
     * OslMsgSendExtQueue(&Message);
     */
    mmi_frm_send_ilm(MOD_MMS, MSG_ID_MMS_EXIT_USB_MODE_REQ, NULL, NULL);

}
#endif /* __USB_IN_NORMAL_MODE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mms_em_change_setting
 * DESCRIPTION
 *  This function is used to infom changes done in engineer-mode.
 * CALLS
 *  
 * PARAMETERS
 *  opt             [IN]        
 *  new_setting     [?]         
 *  val(?)          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_em_change_setting(applib_inet_option_enum opt, applib_inet_setting_struct *new_setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* MYQUEUE Message; */
    mms_target_data_ind_struct *req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (mms_target_data_ind_struct*) construct_local_para(
                                            (kal_uint16) sizeof(mms_target_data_ind_struct),
                                            TD_CTRL | TD_RESET);
    switch (opt)
    {
        case APPLIB_INET_UA_STRING_OPT:
            req->data_type = MMS_TARGET_DATA_USER_AGENT;
            break;

        case APPLIB_INET_MMS_VERSION_OPT:
            req->data_type = MMS_TARGET_DATA_MMS_VERSION;
            break;

        default:
            ASSERT(0);
            break;
    }
    /*
     * Message.oslSrcId = MOD_MMI;
     * Message.oslDestId = MOD_MMS;
     * Message.oslMsgId = MSG_ID_MMS_TARGET_DATA_IND;
     * Message.oslDataPtr = (local_para_struct*)req;
     * Message.oslPeerBuffPtr = NULL;
     * OslMsgSendExtQueue(&Message);
     */
    mmi_frm_send_ilm(MOD_MMS, MSG_ID_MMS_TARGET_DATA_IND, (oslParaType*) req, NULL);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mms_plmn_number_indication_callback
 * DESCRIPTION
 *  This function is used to infom WAP task of PLMN number of current operator.
 *  MMS version may be changed by this number. Ex: Taiwan FET => MMS v1.0
 * CALLS
 *  
 * PARAMETERS
 *  plmn_number     [IN]        PLMN number of network we campon
 * RETURNS
 *  void
 *****************************************************************************/
void mms_plmn_number_indication_callback(const unsigned char *plmn_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mms_roaming_status_indication_callback
 * DESCRIPTION
 *  This function is used to infom WAP task of PLMN number of current operator.
 *  MMS version may be changed by this number. Ex: Taiwan FET => MMS v1.0
 * CALLS
 *  
 * PARAMETERS
 *  simId           [IN]        
 *  isRoaming       [IN]        
 *  plmn_number(?)      [IN]        PLMN number of network we campon(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mms_roaming_status_indication_callback(int simId, unsigned long isRoaming)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* MYQUEUE Message; */
    peer_buff_struct *peer_buff_ptr = NULL;
    kal_uint8 *peer_pdu = NULL;
    kal_uint16 peer_pdu_len = 0;
    mms_target_data_ind_struct *req = NULL;
    mms_target_data_roaming_status_struct roaming_st = {KAL_FALSE, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req =
        (mms_target_data_ind_struct*) construct_local_para(
                                        (kal_uint16) sizeof(mms_target_data_ind_struct),
                                        TD_CTRL | TD_RESET);

    roaming_st.sim_id = simId;
    roaming_st.is_roaming = (kal_bool)isRoaming;

    req->data_type = MMS_TARGET_DATA_ROAMING_STATUS;
    peer_buff_ptr =
        (peer_buff_struct*) construct_peer_buff(sizeof(mms_target_data_roaming_status_struct), 0, 0, TD_CTRL);
    peer_pdu = (kal_uint8*) get_pdu_ptr(peer_buff_ptr, &peer_pdu_len);
    if (peer_pdu)
    {
        memcpy((kal_uint8*) peer_pdu, &roaming_st, sizeof(mms_target_data_roaming_status_struct));
    }

    /*
     * Message.oslSrcId = MOD_MMI;
     * Message.oslDestId = MOD_MMS;
     * Message.oslMsgId = MSG_ID_MMS_TARGET_DATA_IND;
     * Message.oslDataPtr = (local_para_struct*)req;
     * Message.oslPeerBuffPtr = (peer_buff_struct*) peer_buff_ptr;
     * 
     * OslMsgSendExtQueue(&Message);
     */
    mmi_frm_send_ilm(MOD_MMS, MSG_ID_MMS_TARGET_DATA_IND, (oslParaType*) req, (oslPeerBuffType*) peer_buff_ptr);
#ifdef __MMI_MMS_ROAMING_NO_ACCEPT_SUPPORT__
#ifdef __MMI_MMS_2__
    srv_mms_roaming_info_check(isRoaming, simId);
#endif 
#endif /* __MMI_MMS_ROAMING_NO_ACCEPT_SUPPORT__ */ 
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_on_home_plmn_changed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_mms_on_home_plmn_changed(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Currently MMS is not handling PLMN number */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_RET_OK;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_on_roaming_status_changed
 * DESCRIPTION
 *  
 * CALLS
 *  
 * PARAMETERS
 *  evt     [?]     
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_mms_on_roaming_status_changed(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_roaming_status_changed_evt_struct *roaming_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    roaming_evt = (srv_nw_info_roaming_status_changed_evt_struct*) evt;

    mms_roaming_status_indication_callback(
        roaming_evt->sim == MMI_SIM1 ? MMA_SIM_ID_SIM1 : MMA_SIM_ID_SIM2,
        roaming_evt->is_roaming_now ? TRUE : FALSE);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mms_hide_send_mms_menu
 * DESCRIPTION
 *  This function is used to infom other App
 *  about MMS that it will be initialized under network settings or not.
 *  To show send/fw content option to MMS.
 * CALLS
 *  
 * PARAMETERS
 *  void
 *  void(?)     [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool mms_hide_send_mms_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __COSMOS_MMI_PACKAGE__
    if (mms_is_sim_valid()
#ifdef __FLIGHT_MODE_SUPPORT__
        && srv_mode_switch_is_network_service_available() == KAL_TRUE
#endif  
        )
    {
        return KAL_FALSE;
    }
    else
    {
        return KAL_TRUE;
    }
#else /* __COSMOS_MMI_PACKAGE__ */ 
    return KAL_FALSE;
#endif /* __COSMOS_MMI_PACKAGE__ */ 
}


#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mms_is_default_templates_ready
 * DESCRIPTION
 *  This function is used to infom other App
 *  about MMS templates is ready or not.
 * CALLS
 *  
 * PARAMETERS
 *  void
 *  void(?)     [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool mms_is_default_templates_ready(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     srv_mms_default_template_states tmplt_gen_state;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    tmplt_gen_state = srv_mms_default_template_generation_state();

    if(tmplt_gen_state == SRV_MMS_TMPLT_READY)
    {
        return KAL_TRUE;
    }
    else if(tmplt_gen_state == SRV_MMS_TMPLT_FAIL_AND_STOP)
    {
        return KAL_TRUE;
    }
    else if(tmplt_gen_state == SRV_MMS_TMPLT_FAIL)
    {
        mms_mma_send_ilm(NULL, NULL, MSG_ID_WAP_MMA_CHECK_TEMPLATE_REQ, MOD_MMI);
        return KAL_FALSE;
    }
    else if(tmplt_gen_state == SRV_MMS_TMPLT_GENERATING)
    {
        return KAL_FALSE;
    }
    else
    {
        MMI_ASSERT(0);

    }    
}
#endif/* __MMI_MMS_TEMPLATE_SUPPORT__*/
/*****************************************************************************
 * FUNCTION
 *  mms_get_service_module
 * DESCRIPTION
 *  This function is to implement get module id to handle mms primitives
 * CALLS
 *  
 * PARAMETERS
 *  msg_id      [IN]        Primitve id
 * RETURNS
 *  module id, MOD_MMI or MOD_WAP
 *****************************************************************************/
module_type mms_get_service_module(kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_id)
    {
    #ifdef MMS_SUPPORT
        case MSG_ID_WAP_MMC_READ_FOLDER_STATUS_REQ_IND:
        case MSG_ID_WAP_MMC_UPLOAD_MSG_REQ_IND:
        case MSG_ID_WAP_MMC_DELETE_MSG_REQ_IND:
        case MSG_ID_WAP_MMC_READ_MSG_PATH_IND:
        case MSG_ID_WAP_MMC_SEND_APPMMS_REQ:
        case MSG_ID_WAP_MMC_POST_APPMMS_MSG_PART_RES:
        case MSG_ID_WAP_MMC_RECV_APPMMS_REQ:
        case MSG_ID_WAP_MMC_READ_APPMMS_MSG_PART_REQ:
        case MSG_ID_WAP_MMC_CFG_APPMMS_APPID_REQ:
        case MSG_ID_WAP_MMC_ABORT_APPMMS_REQ:
        case MSG_ID_WAP_MMC_CHECK_APPMMS_COMING_REQ:
        case MSG_ID_WAP_MMC_GET_MMS_PROF_REQ:
        case MSG_ID_MMS_GET_ACTIVE_MMS_ATTACHMENT_REQ:
    #ifdef __MMI_MMS_IN_UM__
    #ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
        case MSG_ID_MMI_UM_ENTRY_MARK_SEVERAL_RSP:
        case MSG_ID_MMI_UM_MARK_SEVERAL_OP_REQ:
    #endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */ 
    #endif /* __MMI_MMS_IN_UM__ */ 
        case MSG_ID_MMI_UM_DELETE_ALL_RES:
        case MSG_ID_MMI_UM_DELETE_ALL_IND:
    #endif /* MMS_SUPPORT */ 
    #ifdef __UNIFIED_COMPOSER_SUPPORT__
        case MSG_ID_WAP_MMA_UC_START_RSP:
    #endif 
        case MSG_ID_MMS_MULTI_OBJECT_INSERT_REQ:
        case MSG_ID_MMS_MULTI_OBJECT_INSERT_CONTINUE_IND:
    #ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
        case MSG_ID_MMI_MMS_VENDOR_DELETE_RSP:
        case MSG_ID_MMI_MMS_VENDOR_CREATE_RSP:
        case MSG_ID_MMI_MMS_VENDOR_SEND_RSP:
    #endif /* __MMI_MMS_VENDOR_APP_SUPPORT__ */ 
            return MOD_MMI;
        default:
            return MOD_MMS;
    }
}

#endif /* defined(MMS_SUPPORT) */ 
#endif /* _MMSADP_C */ 

