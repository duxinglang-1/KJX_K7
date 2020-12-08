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
 *  vapp_bt_pbap.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_BT_PBAP_H__
#define __VAPP_BT_PBAP_H__

#ifdef __MMI_PBAP_SUPPORT__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "Vapp_bt_server.h"
extern "C"{
#include "PbapSrvGprot.h"
}

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/
/***************************************************************************** 
 * Declare VappBTPBAP class
 *****************************************************************************/

extern "C" 
{
void vapp_pbap_init(void *param);
void vapp_pbap_deinit(void *param);
}

class VbtPbapService
{
public: 
	static void onInit(void);
	static void onDeInit(void);
	
public:
	static VfxS32 m_srvHd;
};


/***************************************************************************** 
 * Declare VappBTPBAPServer class
 *****************************************************************************/
class VappBTPBAPServer: public VbtServer
{
// Constructor / Destructor
	VFX_DECLARE_CLASS(VappBTPBAPServer);
public:
  
	virtual ~VappBTPBAPServer()
	{
		m_inst = NULL;
	}
public: 
    virtual void onStop();
	virtual void onAuthorizeDone(VfxBool result);
	
	static VfxS32 serviceEventHandle(VfxS32 srvHd, VfxU32 eventId, void *para);

    static VfxBool nmgrHandler(mmi_scenario_id scenarioId, void* arg);
    static void obexAuthticationLaunch(void* arg);
    mmi_id getGid()
    {
        return m_gid;
    }
public:
	static VappBTPBAPServer* m_inst;
	VfxU32 m_connId;
private:
    mmi_id m_gid;
    srv_pbap_authentication_notify_struct authticationPara;
};

/*****************************************************************************
 * Declare VappBTObexAuthtication App class
 *****************************************************************************/

class VappBTObexAuthticationApp: public VfxApp
{
    VFX_DECLARE_CLASS(VappBTObexAuthticationApp);
    friend class VappBTObexAuthticationScreen;
public:
    VappBTObexAuthticationApp(){}
    virtual void onRun(void* args, VfxU32 argSize);
};

/*****************************************************************************
 * Declare VappBTObexAuthtication screen class
 *****************************************************************************/
class VappBTObexAuthticationScreen: public VfxAppScr
{
 //   VFX_DECLARE_CLASS(VappBTObexAuthticationScreen);

public:
    VappBTObexAuthticationScreen(){}

    void showAuthticationPopup(void* arg);
    void onAuthenPopupBarClick(VfxObject *sender, VcpInputPopupButtonEnum Id);
};
#endif // __MMI_PBAP_SUPPORT__

#endif // __VAPP_BT_PBAP_H__

