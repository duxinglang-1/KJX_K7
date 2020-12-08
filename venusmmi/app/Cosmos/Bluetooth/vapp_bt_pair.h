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
 *  vapp_bt_pair.h
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

#ifndef __VAPP_BT_PAIR_H__
#define __VAPP_BT_PAIR_H__

#ifdef __MMI_BT_SUPPORT__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "BTcmSrvGprot.h"
#include "vfx_datatype.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MAX_SECURITY_PASSKEY_LENGTH                     6 
#define MAX_INPUT_PASSKEY_LENGHT                        16

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappPasskey
{
public:
	union{
		srv_bt_cm_pair_ind_struct passkeyInput;
		srv_bt_cm_security_user_confirm_struct userConfirm;
		srv_bt_cm_security_passkey_struct securityPasskey;
		srv_bt_cm_security_keypress_struct keyPress;
		}u;
	VfxU32 event;
	VfxU8 passcode[MAX_SECURITY_PASSKEY_LENGTH];
};


class VappBTPasskeyScreen: public VfxAppScr
{
 //   VFX_DECLARE_CLASS(VappBTPasskeyScreen);

public:
    VappBTPasskeyScreen(void *args, VfxU32 argSize)
    {
        setIsSmallScreen();
        //passKey.event = ((VappPasskey*)args)->event;
        memcpy(&passKey , args, sizeof(passKey));
    }
    
    void displayPasskeyInput(void *para);
    void onPasskeyInputBarClick(VfxObject* sender, VcpInputPopupButtonEnum Id);
    
#ifdef __MMI_BT_SIMPLE_PAIR__
    void displayUserConfirm(void *para);

    void displayPasskeyNotify(void *para);
    void onPasskeyNotifyBarClick(VfxObject* sender, VfxId Id);

private:

/*---------------------------------------------------------------------------*
 * Function: disPlayText()
 * Date:Dec 19/2011
 * Description: gen a string, for duplicate codes.
 *    
 *---------------------------------------------------------------------------*/
	void displayText(VfxWString &text, VfxChar* aPassCode, VfxChar* aDevName);
#endif
private:
	void getDevName();
    
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onQueryRotateEx(
        VfxScreenRotateParam &param // The parameter to rotate
    );
    virtual void onRotate(const VfxScreenRotateParam &param);

    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered(VfxBool isBackward);
    virtual void onExit(VfxBool isBackward);

private:
    srv_bt_cm_bt_addr m_devAddr;
    VfxScrRotateTypeEnum m_direction;
    VcpStatusIconBar *m_statusBar;
    VfxBool m_pairRspFlag;

public:
    VappPasskey passKey;
};

class VappBTPasskeyApp: public VfxApp
{
	VFX_DECLARE_CLASS(VappBTPasskeyApp);
	
public:
	virtual void onRun(void *args, VfxU32 argSize);
	static VfxBool nmgrHandler(mmi_scenario_id scenarioId, void* arg);
	static void btPasskeyEventNotify(VfxU32 event, void *para);
    static void initialize(void *param);

	
	static void pairResult(void *para);

protected:
    virtual void onDeinit();

    virtual void onGroupActive();
    virtual void onGroupInactive();

public:
	static VappBTPasskeyApp *btPasskeyApp;
	static VfxS32 passkey_srv_handle;
	static mmi_id gid;
	static VappPasskey *m_passkeyPara;
	//VappBTPasskeyScreen *passkeyScr;
};

#endif //def __MMI_BT_SUPPORT__
#endif // __VAPP_BT_PAIR_H__

