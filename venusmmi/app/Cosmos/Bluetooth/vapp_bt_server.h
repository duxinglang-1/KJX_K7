/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_bt_server.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_BT_SERVER_H__
#define __VAPP_BT_SERVER_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vcp_include.h"
#include "vfx_mc_include.h"
#include "vapp_bt_storage.h"
extern "C" {
#include "BtcmSrvGprot.h"
#include "mmi_frm_scenario_gprot.h"
}


/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Declare VbtServer class
 *****************************************************************************/
class VbtServer: public VfxObject
{
    friend class VbtServerAgent;

public:
    void stop();
protected: 
	virtual void onStart();
    virtual void onStop();
	virtual void onAuthorizeDone(VfxBool result) {}
    virtual void getDisplayText(VfxWString &text, srv_bt_cm_bt_addr *addr);
    void startNmgr();
    void errorHandle();
private:
    void showAuthorize();
    static void onConfirmDone(VfxId id, void *userData);

protected:
	srv_bt_cm_bt_addr m_devAddr;
    VfxWString m_displayText;
    VbtReceiver *receiver;

    VfxS32 popupHandle;
};

/***************************************************************************** 
 * Declare VbtServerAgent class
 *****************************************************************************/

/*
 * BT server app class
 * EXAMPLE
 * <code>
 * VbtServerAgent::launchProfServer(SRV_BT_CM_OBEX_OBJECT_PUSH_SERVICE_UUID, addr);
 * VbtServerAgent::terminateProfServer(SRV_BT_CM_OBEX_OBJECT_PUSH_SERVICE_UUID);
 * </code>
 */
class VbtServerAgent
{
//    VFX_DECLARE_CLASS(VbtServerAgent);
// Constructor / Destructor
public:

// Method
public:
    // profile use this function to launch it's server and get the server object when receive authorize_ind
    static VbtServer* launchServer(VbtServer *server, srv_bt_cm_bt_addr* addr);
    // when profile server exit, call this function
    static void terminateServer(VbtServer *instance);
// override
public:
    virtual void onRun(void* args, VfxU32 argSize);
// Implementation

// Variable
private:
    static VbtServerAgent *m_selfInstance;
//    VfxU32 m_refCount;
};

#endif // __VAPP_BT_SERVER_H__

