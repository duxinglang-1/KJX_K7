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

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_bt_manager.cpp
 *
 * Project:
 * --------
 *  Cosmos
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
 *
 *============================================================================
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
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
extern "C" {
#include "MMI_features.h" 
#include "stack_common.h"
#include "stack_msgs.h"
}
#ifdef __MMI_OPP_SUPPORT__
#include "vapp_bt_opp.h"
#endif
#include "vapp_bt_ftp.h"
#ifdef __MMI_HFP_SUPPORT__
#include "vapp_bt_hfg.h"
#endif
#ifdef __MMI_A2DP_SUPPORT__
#include "vapp_bt_a2dp.h"
#endif
#if defined(__MMI_HFP_SUPPORT__) || \
    defined(__MMI_A2DP_SUPPORT__)
#include "vapp_bt_audio.h"    
#endif
#ifdef __MMI_AVRCP_SUPPORT__
#include "vapp_bt_avrcp.h"
#endif
#ifdef __MMI_SPP_SUPPORT__
#include "vapp_bt_spp.h"
#endif
#ifdef __MMI_DUN_SUPPORT__
#include "vapp_bt_dun.h"
#endif
#ifdef __MMI_PBAP_SUPPORT__
#include "vapp_bt_pbap.h"
#endif
#ifdef __MMI_SIMAP_SUPPORT__
#include "vapp_bt_sap.h"
#endif
#include "vapp_bt_pair.h"
#include "vapp_bt_storage.h"
#include "vapp_bt_manager.h"
#include "vapp_bt_main.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
 
/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/
extern "C" mmi_ret vapp_bt_init(mmi_event_struct *evt)
{
    srv_bt_cm_init();

    VbtStorageSetting::onInit(evt);
    VbtRecvAgent::onInit(evt);

#if defined(__MMI_HFP_SUPPORT__) || \
    defined(__MMI_A2DP_SUPPORT__)
    vapp_btaud_init(evt);
#endif
#ifdef __MMI_SPP_SUPPORT__
    vapp_spp_init(evt);
#endif
#ifdef __MMI_DUN_SUPPORT__
    vapp_dun_init(evt);
#endif
    vapp_bt_obex_init();

#ifdef __MMI_OPP_SUPPORT__
    vapp_opp_init(evt);
#endif
#ifdef __MMI_FTS_SUPPORT__
    vapp_ftp_init(evt);
#endif
#ifdef __MMI_A2DP_SUPPORT__
    vapp_a2dp_init(evt);
#endif
#ifdef __MMI_AVRCP_SUPPORT__
    vapp_avrcp_init(evt);
#endif
#ifdef __MMI_SIMAP_SUPPORT__
    vapp_sap_init(evt);
#endif
#ifdef __MMI_PBAP_SUPPORT__
    vapp_pbap_init(evt);
#endif
#if 0
#if defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__)
/* under construction !*/
#endif
#endif

    VappBTPasskeyApp::initialize(evt);

    VappBtCm::initCM(evt);

    return MMI_RET_OK;
}

extern "C" void vapp_bt_deinit(void)
{
#if defined(__MMI_HFP_SUPPORT__) || defined(__MMI_A2DP_SUPPORT__)
    vapp_btaud_deinit(NULL);
#endif

#ifdef __MMI_A2DP_SUPPORT__
    vapp_a2dp_deinit(NULL);
#endif

#ifdef __MMI_AVRCP_SUPPORT__
    vapp_avrcp_deinit(NULL);
#endif

#ifdef __MMI_DUN_SUPPORT__
    vapp_dun_deinit(NULL);
#endif

#ifdef __MMI_PBAP_SUPPORT__
    vapp_pbap_deinit(NULL);
#endif

#ifdef __MMI_SPP_SUPPORT__
    vapp_spp_deinit(NULL);
#endif

#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)
    vapp_ftp_deinit(NULL);
#endif

#ifdef __MMI_OPP_SUPPORT__
    vapp_opp_deinit(NULL);
#endif
}

extern "C" {
#include "OppSrvGprot.h"
#include "FtpSrvGprots.h"
}
extern "C"
void mmi_bt_obex_msg_hdlr(void *msg, int mod_src, void *ilm_p)
{
    mmi_obex_msg_struct* obex_msg = (mmi_obex_msg_struct*)msg;
    ilm_struct* mmi_ilm_ptr = (ilm_struct*) ilm_p;

    /* OPP */
    if (obex_msg->uuid_len == 0 && obex_msg->uuid[0] == '\0')
    {
#if defined(__MMI_OPP_SUPPORT__)        
        srv_opp_event_hdlr(mmi_ilm_ptr->msg_id, msg);
        return;
#endif /* defined(__MMI_OPP_SUPPORT__) */ 
    }        
    /* FTP */
#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)        
    if (strncmp( (const char*)OBEX_FTP_UUID, (const char*)obex_msg->uuid, 16 ) == 0 )
    {
        srv_ftp_event_handle(mmi_ilm_ptr->msg_id, msg);
		return;
    }
#endif
}

extern "C"
void vapp_bt_obex_init()
{
    SetProtocolEventHandler((PsFuncPtr)mmi_bt_obex_msg_hdlr, MSG_ID_GOEP_REGISTER_SERVER_RSP);
    SetProtocolEventHandler((PsFuncPtr)mmi_bt_obex_msg_hdlr, MSG_ID_GOEP_DEREGISTER_SERVER_RSP);
    SetProtocolEventHandler((PsFuncPtr)mmi_bt_obex_msg_hdlr, MSG_ID_GOEP_CONNECT_IND);
    SetProtocolEventHandler((PsFuncPtr)mmi_bt_obex_msg_hdlr, MSG_ID_GOEP_PUSH_IND);
    SetProtocolEventHandler((PsFuncPtr)mmi_bt_obex_msg_hdlr, MSG_ID_GOEP_PULL_IND);
    SetProtocolEventHandler((PsFuncPtr)mmi_bt_obex_msg_hdlr, MSG_ID_GOEP_SET_FOLDER_IND);
    SetProtocolEventHandler((PsFuncPtr)mmi_bt_obex_msg_hdlr, MSG_ID_GOEP_ABORT_IND);
    SetProtocolEventHandler((PsFuncPtr)mmi_bt_obex_msg_hdlr, MSG_ID_GOEP_AUTHORIZE_IND);
    SetProtocolEventHandler((PsFuncPtr)mmi_bt_obex_msg_hdlr, MSG_ID_GOEP_CONNECT_RSP);
    SetProtocolEventHandler((PsFuncPtr)mmi_bt_obex_msg_hdlr, MSG_ID_GOEP_PUSH_RSP);    
    SetProtocolEventHandler((PsFuncPtr)mmi_bt_obex_msg_hdlr, MSG_ID_GOEP_PULL_RSP);
    SetProtocolEventHandler((PsFuncPtr)mmi_bt_obex_msg_hdlr, MSG_ID_GOEP_SET_FOLDER_RSP);
    SetProtocolEventHandler((PsFuncPtr)mmi_bt_obex_msg_hdlr, MSG_ID_GOEP_ABORT_RSP);
    SetProtocolEventHandler((PsFuncPtr)mmi_bt_obex_msg_hdlr, MSG_ID_GOEP_DISCONNECT_IND); 
}


