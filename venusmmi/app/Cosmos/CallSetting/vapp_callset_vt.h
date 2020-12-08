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
 *  vapp_callset_vt.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Video related frame
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_CALLSET_VT_H__
#define __VAPP_CALLSET_VT_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMIDataType.h" /* mmi_id */

extern "C" 
{
#include "CallSetSrvGprot.h"
#include "SsSrvGprot.h"
}


#include "vfx_datatype.h"
#include "vfx_page.h"
#include "vfx_string.h"

#include "vcp_list_menu.h"

#include "vapp_ucm_video_frame.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef struct
{
    VfxBool nightModeFront;
    srv_callset_vt_ev_enum evFront;
    U8 zoomFront;
    VfxBool nightModeBack;
    srv_callset_vt_ev_enum evBack;
    U8 zoomBack;
    srv_callset_vt_camera_mode_enum camMode;
    VappVtVideoFrame* videoFrame; /* since hw layer shall NOT be > 2, videoFrame need to be reused */
    VfxWString imagePath;
#ifdef __MMI_EM_PROFILING_VT_LOOKBACK__
/* under construction !*/
#endif /* __MMI_EM_PROFILING_VT_LOOKBACK__ */
} VappCallSetVtStatusStruct;

/***************************************************************************** 
 * Class VappCallSetPageVt
 *****************************************************************************/
class VcpForm;
class VcpFormItemCell;
class VcpFormItemSwitchCell;
class VappCallSetPageVt : public VfxPage
{

// Override
protected:
    virtual void onInit();
    virtual void onEnter(VfxBool isBackward);

private:
	enum
	{
		ID_FORM_LAUNCH_VT_PREVIEW,
		ID_FORM_LAUNCH_VT_DIAL_MODE,
		ID_FORM_LAUNCH_VT_ANS_MODE,
		ID_FORM_SWITCH_VT_OPEN_MIC,
		ID_FORM_SWITCH_VT_OPEN_SPEAKER,
		ID_FORM_TOTAL
	};
    void onItemTap(VcpFormItemCell *item, VfxId id);
    void onSwitch(VcpFormItemSwitchCell* item, VfxId id, VfxBool state);
    void updateForm(void);

    VcpForm *m_form;
};


/***************************************************************************** 
 * Class VappCallSetPageVtPreview
 *****************************************************************************/
class VcpSlider;
class VcpSegmentButton;
class VcpFormItemCustomFrame;
class VcpFormItemCustomFrame;
class VcpFormItemSwitchCell;
class VcpFormItemLauncherCell;

class VappCallSetPageVtPreview : public VfxPage
{

public:
    VappCallSetPageVtPreview();
    VappCallSetPageVtPreview(VfxBool previewOnly, VappCallSetVtStatusStruct *status = NULL);
    VfxSignal2 <
        VappCallSetPageVtPreview*, //sender pointer
        VappCallSetVtStatusStruct* //status
        > m_signalVFrameMastershipReturn;

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEntered();
    virtual void onExit(VfxBool isBackward);
    virtual mmi_ret onProc(mmi_event_struct *evt);
    virtual VfxBool onKeyInput(VfxKeyEvent & event);

private:
    void onSegBtnClicked(VfxObject* sender, VfxId id);
    void onSlideZoom(VcpSlider* slider, VfxFloat value);
    void onSlideEv(VcpSlider* slider, VfxFloat value);
    void onSwitch(VcpFormItemSwitchCell* item, VfxId id, VfxBool state);
	void onAniDone(VcpFormItemSwitchCell* item, VfxId id, VfxBool state);
    void onItemTap(VcpFormItemCell *item, VfxId id);
    void startUpdateLocalView(VfxTimer *timer);
    void updateLocalView(void);
    void updateLocalValue(void);
    static mmi_ret onEvtHdlr(mmi_event_struct *evt);
    void onVFrameEvent(VappVtVideoFrameEvtEnum evt, VfxS32 param);
    void disableAllOp(VfxBool isDisable);
    void postExit(void);
    void onPostExit(VfxTimer *timer);
    void vFramePause();
    void vFrameResume();
    VappVtVideoFrameEvEnum getVFrameAppEv(srv_callset_vt_ev_enum ev);
    srv_callset_vt_ev_enum getCallsetSrvVtEv(VappVtVideoFrameEvEnum ev);
	
	srv_callset_vt_camera_mode_enum getCamMode(void) const;
	VfxBool getNightMode(void) const;
	srv_callset_vt_ev_enum getEV(void) const;
	void setEV(const srv_callset_vt_ev_enum &ev);
	VfxU8 getZoom(void) const;
    VfxBool inVtSession(void) const;

private:
    VcpSegmentButton *m_segBtn;
    VfxFrame *m_vFrameCell;
    VappVtVideoFrame *m_vFrame;
    VcpFormItemCustomFrame *m_zoom;
    VcpFormItemCustomFrame *m_ev;
    VcpFormItemSwitchCell *m_niMode;
    VcpFormItemLauncherCell *m_selPic;
    VcpSlider *m_sliZoom;
    VcpSlider *m_sliEv;
    VfxTextFrame *m_evText;
    VfxBool m_previewOnly;
    VappCallSetVtStatusStruct *m_status;
    VfxBool m_needUpdateValue;
    VfxBool m_ready;
    mmi_id m_fmgr;
    VfxBool m_waitForClose;
    VfxBool m_waitForCloseFmgr;
    VfxTimer *m_formAniTimer;
    VfxBool m_isBg;
	VfxBool m_isSwitched;

	static const VfxResId s_evStrId[VAPP_VT_VIDEOFRAME_EV_TOTAL];
	static const srv_callset_vt_ev_enum s_evSrvVal[VAPP_VT_VIDEOFRAME_EV_TOTAL];
};



/***************************************************************************** 
 * Class VappCallSetPageVtDialMode
 *****************************************************************************/
class VappCallSetPageVtDialMode : public VfxPage, public IVcpListMenuContentProvider
{

// Override IVcpListMenuContentProvider
public:
    virtual VfxBool getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        );
    virtual VfxU32 getCount() const;
    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   
        ) const;

// Override VfxPage
protected:
    virtual void onInit();

private:
    void onSelect(VcpListMenu* menu, VfxU32 index, VcpListMenuItemStateEnum state);
    void onTapped(VcpListMenu* menu, VfxU32 index);

    VfxU32 m_activateIndex;
    VfxU32 m_count;
};


/***************************************************************************** 
 * Class VappCallSetPageVtDialMode
 *****************************************************************************/
class VappCallSetPageVtAnsMode : public VfxPage, public IVcpListMenuContentProvider
{

// Override IVcpListMenuContentProvider
public:
    virtual VfxBool getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        );
    virtual VfxU32 getCount() const;
    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   
        ) const;

// Override VfxPage
protected:
    virtual void onInit();

private:
    void onSelect(VcpListMenu* menu, VfxU32 index, VcpListMenuItemStateEnum state);
    void onTapped(VcpListMenu* menu, VfxU32 index);

    VfxU32 m_activateIndex;
    VfxU32 m_count;
};
#endif /* __VAPP_CALLSET_VT_H__ */

