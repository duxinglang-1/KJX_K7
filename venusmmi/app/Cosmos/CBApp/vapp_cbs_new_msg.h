/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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
 * vapp_cbs_new_msg.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines class of CB app pages of venus.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *			   HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
**********************************************************************************/

#ifndef __VAPP_CBS_NEW_MSG_H__
#define __VAPP_CBS_NEW_MSG_H__
#include "mmi_features.h"

#ifndef __cplusplus
#error "this header file can be used in C++ only."
#endif

#include "vapp_cbs_iprot.h"
#include "vfx_xml_loader.h"
#include "vapp_sms_notifier_scrn.h"
#include "vapp_sms_notifier_core.h"



#define __VAPP_CBS_NEW_MSG__

#ifdef __VAPP_CBS_NEW_MSG__
#define MAX_NEW_HOLD_NUMBER 4

/***************************************************************************** 
 * Include
 *****************************************************************************/
class VappCbsNewMsgApp;
class VappCbsNewMsgPopupViewer;

/**************************************************************************** 
 * Class VappSmsNotifyControl
 *****************************************************************************/
class VappCbsNewMsgPopupViewer: public VfxAppScr
{

public:
    VappCbsNewMsgPopupViewer(VfxScrRotateTypeEnum dir);
	void updateView();
protected:
    virtual void onInit();
    virtual void onQueryRotateEx(
        VfxScreenRotateParam &param // The parameter to rotate
    );
	virtual void onEnter(VfxBool isBackward); 

private:

    VfxScrRotateTypeEnum m_rotation;
	VappSmsClass0NotifyCp *m_notifyCp;
};


class VappCbsNewMsgManager : public MsgNotifyManager
{

    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappCbsNewMsgManager);
	
public:
    VappCbsNewMsgManager();    
    virtual void notify(VfxBool needSetAppActive); 
    virtual VfxBool deleteInd(VfxU8 index);
    static mmi_ret cbsMsgDeleteProc(mmi_event_struct *evt);         // msg deleted and msg viewed
    static MMI_BOOL VappCbsNewMsgShow(mmi_scenario_id scen_id, void *arg);
    virtual void getContent(VfxU8 index, VfxWString &content);
	virtual void getFormatAddr(VfxU8 index, VfxWString &addr);
	virtual void getFormatTimestamp(VfxU8 index, VfxWString &timesatmp);
	virtual VfxU8 getNotifyIndex();
	virtual VfxBool addNewInd(mmi_event_struct *evt);
    

protected:
    virtual void onDeinit();
	virtual void onInit();
	
private:
    void deleteInd(VfxId msg_id, VfxS32 sim_id);
    void updateView();

	
    
private:
    class VappCbsNewMsgUnit :public VfxObject
    {
    public:
        friend class VappCbsNewMsgManager;
        VappCbsNewMsgUnit() : m_msgId(VAPP_CB_INVALID_MSG_ID), m_simId(0){};
    private:
        VfxId m_msgId;
        VfxS32 m_simId;
    };
    VappCbsNewMsgUnit m_msgUnits[MAX_NEW_HOLD_NUMBER];
    VfxU32 m_totalUnitNumber;

};


class VappCbsNewMsgApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappCbsNewMsgApp);
public:

    VappCbsNewMsgApp();
	void updateView();

    
protected:
    virtual void onRun(void * args, VfxU32 argSize);
    virtual void onDeinit();
private:
   
    VappCbsNewMsgPopupViewer *m_popupViewer;
};

#endif // __NEW_MSG
#endif /* __VAPP_CBS_NEW_MSG_H_ */
