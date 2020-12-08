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
 *  vapp_piano.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Piano app
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_PIANO_H__
#define __VAPP_PIANO_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#if (defined(__MMI_FTO_PIANO__) && defined(__J2ME__))

#include "vapp_piano_keyboard.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_base_picker.h"
#include "mmi_rp_vapp_piano_def.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define  VAPP_PIANO_TOP_FRAME_HEIGHT   80
#define  VAPP_PIANO_TOP_FRAME_BTN_H   60
#define  VAPP_PIANO_TOP_FRAME_BTN_W   60


#define VAPP_PIANO_SETTING_FORM_SLIDER_TEXTFRAME_H 50
#define VAPP_PIANO_SETTING_FORM_SLIDER_TEXTFRAME_W 80


#define VAPP_PIANO_MIDI_INSTRUTMENT_NUM     5
#define VAPP_PIANO_MIDI_INSTRUTMENT_0       0
#define VAPP_PIANO_MIDI_INSTRUTMENT_1       9
#define VAPP_PIANO_MIDI_INSTRUTMENT_2      33//60
#define VAPP_PIANO_MIDI_INSTRUTMENT_3      19//29
#define VAPP_PIANO_MIDI_INSTRUTMENT_4      13//73



/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class
 *****************************************************************************/
class VappPianoSettingPage: public VfxPage
{
    VFX_DECLARE_CLASS(VappPianoSettingPage);    

public:
     VappPianoSettingPage();
protected:
    virtual void onInit();
    virtual void onQueryRotateEx( VfxScreenRotateParam &param);

public:
    VfxSignal0 m_sigUpdatePianoKeyboard;
    VfxSignal1<VfxFloat> m_sigVolumeSliChange;
    VfxSignal1<VfxFloat> m_sigSustainSliChange;
    VfxSignal1<VfxBool> m_sigLabelSwChange;

    VfxSignal1<VfxBool> m_sigMidiSwChange;
    VfxSignal1<VfxFloat> m_sigProgramSliChange;
    VfxSignal1<VfxU8> m_sigProgramChange;

private:
    // setting form
    VcpForm *m_form;
    VcpFormItemSwitchCell *m_keyLabelFormChell;
    VcpFormItemSwitchCell *m_midiFormChell;    
    VcpFormItemCustomFrame *m_programFormChell;
    VfxTextFrame *m_programTextFrame;
    VcpSlider *m_programSlider;
    VfxU8 m_midiProgram;
    
    // setting button
    enum
    {
        VAPP_PIANO_BACK_BTN     
    };
    void onTitleBtnHandler(VfxObject* sender, VfxId id);
    // form
    enum 
    {
        ID_FORM_CELL_SWITCH_TOUCH_GLOW,
        ID_FORM_CELL_SWITCH_KEY_LABEL,
        ID_FORM_CELL_SWITCH_MIDI,
        ID_FORM_CELL_LAUNCH_PROGRAM
    };
    void onLabelSwitchChangeReq(VcpFormItemSwitchCell *obj, VfxId id, VfxBool newState);
    void onMidiSwitchChangeReq(VcpFormItemSwitchCell *obj, VfxId id, VfxBool newState);
    void onProgramSliderChange(VcpSlider* slider, VfxFloat value);
    void onProgramSlideThumbDrag(VcpSlider *slider, VfxFloat value);

public:        
    void setKeyLabelChellStatus(VfxBool b){m_keyLabelFormChell->setSwitchStatus(b);};   
    void setMidiChellStatus(VfxBool b){m_midiFormChell->setSwitchStatus(b);};   
    void setProgramChellValue(VfxS32 g);    
    void setProgramChellDisable(VfxBool b){m_programFormChell->setIsDisabled(b); }
    
    
    void setProgramName(VfxWString name);

    VfxU32 transferToMidiProgramID(VfxU32 uiValue);
    VfxU32 transferToUiProgramID(VfxU32 graogramID);
};


class VappPianoPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappPianoPage);
public:
    VappPianoPage();
// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onExit(VfxBool isBackward);    
    virtual void onQueryRotateEx( VfxScreenRotateParam &param);

private:    
	VfxFrame *m_topFrame;
    // keyboard
    VappPianoKeyboard *m_pianoKeyboard;

    // msg frame
    VfxFrame *m_errMsgFrame;
    
    // button event
    enum
    {
        VAPP_PIANO_SETTING_BTN
    };
    
public:
    VfxSignal0 m_sigCallhandle;

    static mmi_ret onServiceProc(mmi_event_struct *evt);
    void handleCallEvent();

    // read/write piano setting to memory 
    void readFromNVRAM();
    void flushToNVRAM(); 
    
    // err msg mechanishm
    void showErrMsgFrame(VfxBool b);
    
    // event handle
    void onSettingBtnClicked(VfxObject* sender, VfxId id);

    // player control
    void openPlayer();
    void closePlayer();

    // call
    VfxBool isOnCall();
};


class VappPianoScreen : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappPianoScreen);

public:
    VappPianoScreen():m_page(NULL){};

// override
protected:
    virtual void on1stReady();
    virtual void onQueryRotateEx( VfxScreenRotateParam &param);

// data member
private:
    VappPianoPage *m_page;
    enum
    {
        VAPP_PIANO_PAGE = 1
    };

public:
    void showErrMsgFrame(VfxBool b);

    // player control
    void openPlayer();
    void closePlayer();
};

class VappPianoApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappPianoApp);

// Override
protected:
    virtual void onRun(void* args, VfxU32 argSize);
    virtual void onDeinit();
private:
    VappPianoScreen *m_scr;
};


#endif /*__MMI_FTO_PIANO__*/

#endif /* __VAPP_PIANO_H__*/




