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
 *  vapp_sms_notifier_scrn.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  SMS setting for Venus UI
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifndef __VAPP_SMS_NOTIFIER_SCRN_H__
#define __VAPP_SMS_NOTIFIER_SCRN_H__
#include "mmi_features.h"
#include "vfx_mc_include.h"
#include "vapp_sms_util.h"
#include "vcp_include.h"
#include "vapp_ncenter_base_cell.h"
#include "vapp_sms_notifier_core.h"


/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
    #include "SmssrvGprot.h"
#ifdef __cplusplus
}
#endif


/**************************************************************************** 
 * Class VappSmsNotifyControl
 *****************************************************************************/
class VappSmsClass0NotifyCp: public VfxBasePopup
{
    //VFX_DECLARE_CLASS(VappSmsClass0NotifyCp);

public:

	enum NotifyType
	{
		NOTIFY_CP_TYPE_NONE,
		NOTIFY_CP_TYPE_SMS,
		NOTIFY_CP_TYPE_CBS
	};
    VappSmsClass0NotifyCp(VfxScrRotateTypeEnum m_dir, VappSmsClass0NotifyCp::NotifyType type);
	void updateView();
	void setRelatedNmgr(MsgNotifyManager *nmgr){ m_relatedNmgr = nmgr; }


protected:
    virtual void onInit();
    virtual void onUpdate();
    virtual void onDeinit();
    virtual void onRotate(const VfxScreenRotateParam &param);
    virtual VfxBool onKeyInput(VfxKeyEvent & event);

private:
	void createCp();
    void onContentBoundsChanged(VfxFrame *frame, const VfxRect &rect);
    void onButtonClicked(VfxObject *sender, VfxId id);
    void onSaved(VfxBool result, srv_sms_cause_enum cause);
#if (defined (__SIM_HOT_SWAP_SUPPORT__) || (__SIM_RECOVERY_ENHANCEMENT__))
	static mmi_ret onSmsReady(mmi_event_struct *evt);
#endif /* (defined (__SIM_HOT_SWAP_SUPPORT__) || (__SIM_RECOVERY_ENHANCEMENT__)) */ 


public:
    VfxSignal2 <
        VfxObject*,     // sender 
        VfxId           // id
    > m_signalButtonClicked;

private:
    enum
    {
        ITEM_ID_BUTTON_SAVE,
        ITEM_ID_BUTTON_DISCARD,
        ITEM_ID_BUTTON_OK,
        TTEM_ID_TOTAL
    };

    VfxFrame *m_backgroundTop;
    VfxFrame *m_backgroundBottom;
    VfxTextFrame *m_contactFrame;
    VcpTextView *m_contentView;
    VfxTextFrame *m_timeFrame;
    VcpButton *m_saveButton;
    VcpButton *m_closeButton;
	VcpButton *m_okButton;
	MsgNotifyManager *m_relatedNmgr;
    VfxU8 m_curNotifyIndex;

    VfxScrRotateTypeEnum m_dir;
	NotifyType m_notifyType;
	
};


/***************************************************************************** 
 * Class VappSmsClass0ViewerScr
 *****************************************************************************/
class VappSmsClass0ViewerScr : public VfxAppScr
{


public:
    VappSmsClass0ViewerScr(VfxScrRotateTypeEnum dir);
	void updateView();

protected:
    virtual void onInit();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);
	virtual void onEnter(VfxBool isBackward);


private:
    VappSmsClass0NotifyCp *m_notifyCp;
    VfxScrRotateTypeEnum m_rotation;
};

/////////////////////////////////////////////////////
class VappClass0NewMsgApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappClass0NewMsgApp);
public:

    VappClass0NewMsgApp();
	void updateView();

protected:
    virtual void onRun(void * args, VfxU32 argSize);
	virtual void onDeinit();
    virtual void onGroupActive();
    virtual void onGroupInactive();
 
private:

    VappSmsClass0ViewerScr *m_popupViewer;
};





#endif /* __VAPP_SMS_NOTIFIER_SCRN_H__ */
