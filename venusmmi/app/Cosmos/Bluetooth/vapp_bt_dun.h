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
 *  vapp_bt_dun.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_BT_DUN_H__
#define __VAPP_BT_DUN_H__

#ifdef __MMI_DUN_SUPPORT__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "Vapp_bt_server.h"
extern "C"
{
#include "bt_common_config.h"
}
/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MMI_DUN_BUF_SIZE (SPP_MIN_RX_BUFSIZE + SPP_MIN_TX_BUFSIZE)

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum
{
	DUN_STAT_IDLE,
	DUN_STAT_ACTIVATE,
	DUN_STAT_AUTHORIZING,
	DUN_STAT_CONNECT,	
	DUN_STAT_DISCONNECT

} m_dunState;

/***************************************************************************** 
 * Class 
 *****************************************************************************/
extern "C" {
void vapp_dun_init(void *param);
void vapp_dun_deinit(void *param);
}

/***************************************************************************** 
 * Declare VappBTDUN class
 *****************************************************************************/
extern "C" 
{
void vapp_dun_init(void * param);
void vapp_dun_deinit(void * param);
}


class VbtDunService
{
public: 
	static void onInit(void);
    static void onDeInit(void);
	static void onActivate(void);
    static void onDeactivate(void);
    static void onDisconnect(VfxU32 connId);
    //static void authResponse(VfxBool accept);

private: 
    static VfxU8 onProtocolMessage(void *ilmData, VfxS32 srcModule, ilm_struct *ilm);
    static void onActivateDone();
    static void onDeactivateDone();
	static void onAuthStart(void *param);
	
public:
    VfxSignal2 <VfxU32, VfxU32> m_evtNotify;

	static VfxU8 m_state;

};


/***************************************************************************** 
 * Declare VappBTDUNServer class
 *****************************************************************************/
class VappBTDUNServer: public VbtServer
{
	VFX_DECLARE_CLASS(VappBTDUNServer);
// Constructor / Destructor

public:
	virtual ~VappBTDUNServer()
    {
		m_inst = NULL;
    }
public:	
	//virtual void onStart(){}
    virtual void onStop();
	virtual void onAuthorizeDone(VfxBool result);

	void onConnectDone(void *param);
	
public:
	static VappBTDUNServer* m_inst;
	static VfxS32 m_connId;
	static DCL_DEV m_port;
	static VfxU8 m_buf[MMI_DUN_BUF_SIZE];
	srv_bt_cm_bt_addr m_devAddr;
};

#endif //__MMI_DUN_SUPPORT__
#endif /* __VAPP_BT_DUN_H__ */

