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
 *  vapp_bt_opp.cpp
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
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
extern "C"
{
#include "MMI_features.h" 
#include "MMIDataType.h"
#include "USBSrvGprot.h"
#include "Conversions.h"
#include "MMI_conn_app_trc.h"
}

#ifdef __MMI_OPP_SUPPORT__

#include "vapp_platform_context.h" // for VappPlatformContext

#include "mmi_rp_vapp_bt_main_def.h"
#include "vapp_bt_opp.h"
#include "vapp_bt_storage.h"

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
void vapp_opp_init(void *param)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_OPP_INIT);

    srv_opp_init();

    VappBTOPPServer::srvHd = srv_opp_open(SRV_OPP_ROLE_SERVER);

    if (VappBTOPPServer::srvHd < 0)
         return;
    
    VfxU32 event_mask;
    event_mask = SRV_OPP_EVENT_START |
        SRV_OPP_EVENT_STOP |
        SRV_OPP_EVENT_AUTHORIZE_NOTIFY |
        SRV_OPP_EVENT_CONN_NOTIFY | SRV_OPP_EVENT_DISCONN_NOTIFY | SRV_OPP_EVENT_RECV_NOTIFY;

    srv_opp_set_notify(VappBTOPPServer::srvHd, event_mask, (bt_notify)&VappBTOPPServer::serviceEventHandle);
}

void vapp_opp_deinit(void *param)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_OPP_DEINIT);

    srv_opp_deinit();
    srv_opp_close(VappBTOPPServer::srvHd);
    VappBTOPPServer::srvHd = -1;
}

mmi_ret vapp_opps_usb_plugin_hdlr(mmi_event_struct *evt)
{
    if (VappBTOPPServer::inst != NULL)
    {
        VappBTOPPServer::inst->onUsbPlugIn();
    }
    return MMI_RET_OK;
}


VfxS32 VappBTOPPServer::srvHd = -1;
VappBTOPPServer* VappBTOPPServer::inst = NULL;

VFX_IMPLEMENT_CLASS("VappBTOPPServer", VappBTOPPServer, VbtServer);

void VappBTOPPServer::onStart()
{
	receiver = NULL;
}

void VappBTOPPServer::onStop()
{
    if (receiver != NULL)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_OPP_ONSTOP);
        receiver->abort(VBT_RECV_FAIL);
        receiver = NULL;
    }
    VbtServer::onStop();
}

void VappBTOPPServer::onUsbPlugIn()
{
    if (srv_opps_is_receiving())
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_OPP_USBPLUGIN);
        srv_opp_close_temp_obj();
        srv_opps_disconn_client(VappBTOPPServer::srvHd);
    }
}

void VappBTOPPServer::getDisplayText(VfxWString &text, srv_bt_cm_bt_addr *addr)
{	
	VfxWChar devName[SRV_BT_CM_BD_NAME_UCS2_LEN+1];
	VfxWChar* textArray;
	textArray = text.lockBuf(80);
    srv_bt_cm_get_dev_name(&m_devAddr, SRV_BT_CM_BD_FNAME_LEN, (U8*)textArray);
    
    mmi_chset_utf8_to_ucs2_string((VfxU8 *)devName, SRV_BT_CM_BD_NAME_UCS2_LEN, (U8*)textArray);
	mmi_wsprintf(textArray,160,STR_ID_VAPP_BT_ACCEPT_EXCHANGE,devName);
	text.unlockBuf();
}

void VappBTOPPServer::onAuthorizeDone(VfxBool result)
{
    if (result)
    {
        acceptFile();
    }
    else
    {
        srv_opps_reject(srvHd);
	}
}

VfxS32 VappBTOPPServer::serviceEventHandle(VfxS32 handler, VfxU32 eventId, void *para)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_OPP_EVENTHDLR, eventId, handler);

    if (handler <= 0)
        return SRV_OPP_RESULT_INVALID_HANDLE;

    if (srvHd == handler)
    {
        switch (eventId)
        {
            case SRV_OPP_EVENT_START:
            case SRV_OPP_EVENT_STOP:
            case SRV_OPP_EVENT_CONN_NOTIFY:
                break;

            case SRV_OPP_EVENT_AUTHORIZE_NOTIFY:
                {
                    srv_opp_authorize_notify_struct *authNotify = (srv_opp_authorize_notify_struct*) para;
					VFX_OBJ_CREATE(VappBTOPPServer::inst, VappBTOPPServer, VFX_OBJ_GET_INSTANCE(VappPlatformContext));
					VbtServerAgent::launchServer(VappBTOPPServer::inst, &authNotify->bt_addr);
	                inst->authorizeHandle(authNotify);
                }
                break;

            case SRV_OPP_EVENT_RECV_NOTIFY:
                if (inst != NULL)
                    inst->recvIndHandle(para);
                break;

            case SRV_OPP_EVENT_DISCONN_NOTIFY:
                if (inst != NULL)
                    inst->stop();
                break;

            default:
                return SRV_OPP_RESULT_INVALID_PARAM;
        }

        return SRV_OPP_RESULT_OK;
    }
    return SRV_OPP_RESULT_INVALID_HANDLE;
}

void VappBTOPPServer::recvIndHandle(void* para)
{
    srv_opp_recv_notify_struct *recvNotify = (srv_opp_recv_notify_struct*) para;
	srv_opp_obj_detail_struct* detail = &(recvNotify->u.detail);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_OPP_RECVINDHDLR, recvNotify->type);
    switch (recvNotify->type)
    {
        case SRV_OPP_RECV_READY:
            mmi_wcscpy(objName, detail->name);
            strcpy((CHAR*)objMime, (CHAR*)(detail->mime_type));
            objLen = detail->total_len;
            startNmgr();
            break;
			
        case SRV_OPP_RECV_BEGIN:
            mmi_wcscpy(objName, detail->name);
            strcpy((CHAR*)objMime, (CHAR*)(detail->mime_type));
            objLen = detail->total_len;
            acceptFile();
            break;
    
        case SRV_OPP_RECV_SUCCESS:
            if (receiver != NULL)
            {
                receiver->stop();
                receiver = NULL;
            }
            break;
    
        case SRV_OPP_RECV_FAIL:
            if (receiver != NULL)
            {
				MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_VAPP_OPP_RECV_FAIL, recvNotify->u.err_code);
                switch (recvNotify->u.err_code)
                {
                    case SRV_OPP_DISK_FULL:
                    case SRV_OPP_ROOT_DIR_FULL:
                        receiver->abort(VBT_RECV_MEMORY_FULL);
                        break;
                    case SRV_OPP_MEDIA_CHANGED:
                        receiver->abort(VBT_RECV_MSDC_MISSED);
                        break;
                    default:
                        receiver->abort(VBT_RECV_FAIL);
                        break;
                }
                receiver = NULL;
            }
            break;
        default:
            break;
    }

}

void VappBTOPPServer::authorizeHandle(srv_opp_authorize_notify_struct* para)
{
    #ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        srv_opps_reject(srvHd);
        return;
    }
    #endif /* __USB_IN_NORMAL_MODE__ */ 

    srv_opps_accept(srvHd, (U16*) NULL);

}

void VappBTOPPServer::acceptFile()
{
    VbtRecvAgent recvAgent;
    recvAgent.setObject((VfxWChar *)objName,objLen, (VfxChar *)objMime);
    receiver = recvAgent.start(this,0);
    if (receiver == NULL)
    {
        srv_opps_reject(srvHd);
        errorHandle();
        stop();
    }
    else
    {
        srv_opps_accept(srvHd, (U16 *)receiver->getPath());
    }
}
#endif // __MMI_OPP_SUPPORT__

