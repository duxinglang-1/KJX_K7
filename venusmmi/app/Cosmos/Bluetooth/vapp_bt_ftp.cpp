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
 *  vapp_bt_ftp.cpp
 *
 * Project:
 * --------
 *  Venus
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h" 

#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)

extern "C"
{
#include "BtCmSrvGprot.h"
#include "FtpSrvGprots.h"
#include "USBSrvGprot.h"
#include "GlobalResDef.h"
}
#include "mmi_rp_vapp_bt_main_def.h"
#include "vapp_bt_storage.h"
#include "vapp_bt_ftp.h"

#include "vapp_platform_context.h" // for VappPlatformContext

/***************************************************************************** 
 * Define
 *****************************************************************************/
#ifndef __VAPP_BT_DEBUG_INTENAL__
#define __VAPP_BT_DEBUG_INTENAL__
#endif

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/

void vapp_ftp_init(void *param)
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPP_FTP_INIT);
#endif  // __VAPP_BT_DEBUG_INTENAL__

    srv_ftp_init();
#ifdef __MMI_FTS_SUPPORT__
    VappBtFtpServer::m_ftpsSrvHd = srv_ftp_open(SRV_FTP_ROLE_SERVER);
    if (VappBtFtpServer::m_ftpsSrvHd > SRV_FTP_SERVER_HANDLE_DOMAIN)
    {
        VfxU16 eventMask(
            //SRV_FTPS_EVENT_START |
            //SRV_FTPS_EVENT_STOP |
            //SRV_FTPS_EVENT_CONNECT |
            SRV_FTPS_EVENT_AUTHORIZE |
            SRV_FTPS_EVENT_DISCONNECT |
            SRV_FTPS_EVENT_OPERATION_BEGIN |
            SRV_FTPS_EVENT_OPERATION_END);
        srv_ftp_set_notify(
            VappBtFtpServer::m_ftpsSrvHd,
            (ftp_notify)&VappBtFtpServer::ftpsEventHandle,
            eventMask);
    }
    
    srv_ftps_set_permission(SRV_FTPS_PERMISSION_FULL_CONTROL);
#endif  /* __MMI_FTS_SUPPORT__ */
}


void vapp_ftp_deinit(void *param)
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPP_FTP_DEINIT);
#endif  // __VAPP_BT_DEBUG_INTENAL__

    srv_ftp_deinit();

#ifdef __MMI_FTS_SUPPORT__
    VappBtFtpServer::m_ftpsSrvHd = -1;
#endif  // __MMI_FTS_SUPPORT__
}


extern "C"
{
    MMI_RET vapp_ftp_enter_usb_ms_callback(mmi_event_struct *param)
    {
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPP_FTP_ENTER_USB_MS_CALLBACK);
#endif  // __VAPP_BT_DEBUG_INTENAL__

#ifdef __MMI_FTS_SUPPORT__  
        srv_ftps_stop_receiving();
        if (VappBtFtpServer::m_ftpsReceiver)
        {
            VappBtFtpServer::m_ftpsReceiver->abort();
            VappBtFtpServer::m_ftpsReceiver = NULL;
        }
#endif

        return MMI_RET_OK;
    }
}


#ifdef __MMI_FTS_SUPPORT__
VFX_IMPLEMENT_CLASS("VappBtFtpServer", VappBtFtpServer, VbtServer);
VappBtFtpServer* VappBtFtpServer::m_ftpServerSelf;
VfxS32 VappBtFtpServer::m_ftpsSrvHd;
VbtReceiver* VappBtFtpServer::m_ftpsReceiver;


void VappBtFtpServer::ftpsEventHandle(VfxS32 srvHd, VfxU32 event, void* para)
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTFTPSERVER_FTPSEVENTHANDLE,
        srvHd,
        event);
#endif  // __VAPP_BT_DEBUG_INTENAL__

    switch (event)
    {
        //case SRV_FTPS_EVENT_START:
        //    break;
        //case SRV_FTPS_EVENT_STOP:
        //    break;
        //case SRV_FTPS_EVENT_CONNECT:
        //    break;

        case SRV_FTPS_EVENT_AUTHORIZE:
#ifdef __MMI_USB_SUPPORT__
            if (srv_usb_is_in_mass_storage_mode())
            {
                srv_ftps_authorize_reject(VappBtFtpServer::m_ftpsSrvHd);
                if (VappBtFtpServer::m_ftpServerSelf)
                {
                    VappBtFtpServer::m_ftpServerSelf->stop();
                }
                return;
            }
#endif  // __MMI_USB_SUPPORT__

            if (!VappBtFtpServer::m_ftpServerSelf)
            {
                srv_ftps_authorize_indication_struct* authorize_ind((srv_ftps_authorize_indication_struct*)para);
				VFX_OBJ_CREATE(m_ftpServerSelf, VappBtFtpServer, VFX_OBJ_GET_INSTANCE(VappPlatformContext));
				VbtServerAgent::launchServer(m_ftpServerSelf, &authorize_ind->bd_address);
            }
            else
            {
                srv_ftps_authorize_reject(VappBtFtpServer::m_ftpsSrvHd);
            }
            break;

        case SRV_FTPS_EVENT_DISCONNECT:
            if (VappBtFtpServer::m_ftpServerSelf)
            {
                VappBtFtpServer* ftpServer = VappBtFtpServer::m_ftpServerSelf;
                VappBtFtpServer::m_ftpServerSelf = NULL;
                ftpServer->stop();
            }
            break;

        case SRV_FTPS_EVENT_OPERATION_BEGIN:
            if (VappBtFtpServer::m_ftpServerSelf)
            {
                m_ftpServerSelf->ftpsOperationBeginHandle((srv_ftps_operation_begin_struct*)para);
            }
            break;

        case SRV_FTPS_EVENT_OPERATION_END:
            if (VappBtFtpServer::m_ftpServerSelf)
            {
                m_ftpServerSelf->ftpsOperationEndHandle((srv_ftps_operation_end_struct*)para);
            }
            break;
    }
}


void VappBtFtpServer::onAuthorizeDone(VfxBool result)
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTFTPSERVER_ONAUTHORIZEDONE,
        result);
#endif  // __VAPP_BT_DEBUG_INTENAL__

    if (VappBtFtpServer::m_ftpServerSelf)
    {
        if (result)
        {
            srv_ftps_authorize_accept(VappBtFtpServer::m_ftpsSrvHd);
        }
        else
        {
            srv_ftps_authorize_reject(VappBtFtpServer::m_ftpsSrvHd);
            VappBtFtpServer::m_ftpServerSelf->stop();
        }
    }
}

void VappBtFtpServer::ftpsOperationBeginHandle(srv_ftps_operation_begin_struct* para)
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTFTPSERVER_FTPSOPERATIONBEGINHANDLE,
        para->operation);
#endif  // __VAPP_BT_DEBUG_INTENAL__

    switch (para->operation)
    {
        case SRV_FTPS_OPERATION_PULL:
            break;

        case SRV_FTPS_OPERATION_PUSH:
            if (para->result == SRV_FTP_MASK_RESULT_OK)
            {
                VbtRecvAgent recvAgent;
                recvAgent.setObject((VfxWChar*)para->name_p, para->obj_total_size, NULL);
                U16* path = srv_ftps_get_current_folder();
                recvAgent.setStorage((VfxChar)path[0], (VfxWChar*)(path + 3));
                VappBtFtpServer::m_ftpsReceiver = recvAgent.start(this, VBT_RECV_OPT_BKGOUND | VBT_RECV_OPT_KEEP_NAME);
                if (VappBtFtpServer::m_ftpsReceiver)
                {
                    srv_ftps_accept_push_obj(
                        VappBtFtpServer::m_ftpsSrvHd,
                        1,
                        (U16*)VappBtFtpServer::m_ftpsReceiver->getPath());
                }
                else
                {
                    srv_ftps_authorize_reject(VappBtFtpServer::m_ftpsSrvHd);
                    errorHandle();
                }
            }
            else
            {
                srv_ftps_authorize_reject(VappBtFtpServer::m_ftpsSrvHd);
                // showPopup
            }
            break;
    }
}


void VappBtFtpServer::ftpsOperationEndHandle(srv_ftps_operation_end_struct* para)
{
#ifdef __VAPP_BT_DEBUG_INTENAL__
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        MMI_VAPPBTFTPSERVER_FTPSOPERATIONENDHANDLE,
        para->operation);
#endif  // __VAPP_BT_DEBUG_INTENAL__

    switch (para->operation)
    {
        case SRV_FTPS_OPERATION_PULL:
            break;

        case SRV_FTPS_OPERATION_PUSH:
            if (VappBtFtpServer::m_ftpsReceiver)
            {
                if (para->result == SRV_FTP_MASK_RESULT_OK)
                {
                    VappBtFtpServer::m_ftpsReceiver->stop();
                }
                else
                {
                    VfxS32 reason = VBT_RECV_FAIL;
                    switch (para->result)
                    {
                        case SRV_FTP_MASK_ROOT_DIR_FULL:
                            break;

                        case SRV_FTP_MASK_DISK_FULL:
                            reason = VBT_RECV_MEMORY_FULL;
                            break;

                        case SRV_FTP_MASK_DEVICE_EXPORTED:
                            break;

                        case SRV_FTP_MASK_FS_DEVICE_BUSY:
                        case SRV_FTP_MASK_FS_LOCK_MUTEX_FAIL:
                            break;

                        case SRV_FTP_MASK_FS_NO_CARD:
                            reason = VBT_RECV_MSDC_MISSED;
                            break;

                        case SRV_FTP_MASK_FS_WRITE_PROTEC:
                            break;

                        case SRV_FTP_MASK_WRITE_FILE_FAIL:
                            break;
                    }
                    
                    VappBtFtpServer::m_ftpsReceiver->abort(reason);
                }
                
                VappBtFtpServer::m_ftpsReceiver = NULL;
            }
            break;
    }
}

#endif  // __MMI_FTS_SUPPORT__

#endif // defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)
