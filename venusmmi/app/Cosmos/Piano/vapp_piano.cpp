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
 *  vapp_piano.cpp
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
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h" 
#if (defined(__MMI_FTO_PIANO__) && defined(__J2ME__))

#include "vapp_piano.h"
#include "mmi_rp_vapp_piano_def.h"

#include "SoundEffect.h"
#include "Resource_audio.h"
#include "vcp_include.h"

extern "C"
{
// on call
#include "UcmSrvGprot.h"
#include "mdi_audio.h"
}
#include "mmi_rp_vapp_fm_radio_def.h"
#include "vapp_vol_dialog_gprot.h"
#include "mmi_rp_vapp_vol_dialog_def.h"

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

extern "C"
{
void vapp_piano_launch(void)
{
    VfxAppLauncher::launch( 
        VAPP_PIANO,
        VFX_OBJ_CLASS_INFO(VappPianoApp),
        GRP_ID_ROOT);
}
mmi_ret vapp_piano_package_proc(mmi_event_struct* param)
{
    return MMI_RET_DONT_CARE;
}
}// end of extern "C"

VFX_IMPLEMENT_CLASS("VappPianoSettingPage", VappPianoSettingPage, VfxPage);
VappPianoSettingPage::VappPianoSettingPage()
    : m_form(NULL),
    m_keyLabelFormChell(NULL),
    m_midiFormChell(NULL),
    m_programFormChell(NULL),
    m_programTextFrame(NULL),
    m_programSlider(NULL),
    m_midiProgram(0)
{
}
void VappPianoSettingPage::onInit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_SETTING_ON_INIT);

    VfxPage::onInit();
    
    setStatusBar(VFX_FALSE); 

    // top frame
	VfxFrame *topFrame;
	VFX_OBJ_CREATE(topFrame, VfxFrame, this);
	topFrame->setPos(0, 0);
	topFrame->setSize(LCD_HEIGHT, VAPP_PIANO_TOP_FRAME_HEIGHT);
	topFrame->setImgContent(VfxImageSrc(IMG_ID_VAPP_PIANO_TOP_FRAME));
	VfxU32 topFrameHeight = topFrame->getSize().height;

	VfxTextFrame *titleFrame;
	VFX_OBJ_CREATE(titleFrame, VfxTextFrame, topFrame);
	titleFrame->setColor(VFX_COLOR_WHITE);
	titleFrame->setAnchor(0.5f, 0.5);
	titleFrame->setPos(LCD_HEIGHT * 0.5, topFrameHeight * 0.5);
	titleFrame->setString(VFX_WSTR_RES(STR_ID_VAPP_PIANO_SETTING_TITLE));

	VcpImageButton *backBtn;
	VFX_OBJ_CREATE(backBtn, VcpImageButton, topFrame);
	backBtn->setId(VAPP_PIANO_BACK_BTN);
	backBtn->setAnchor(0.5, 0.5f);
	backBtn->setImage(VcpStateImage(IMG_ID_VAPP_PIANO_BACK_BTN, 0, 0, 0));
	backBtn->setPos(LCD_HEIGHT - topFrameHeight * 0.5, topFrameHeight * 0.5);
	backBtn->setSize(VAPP_PIANO_TOP_FRAME_BTN_W, VAPP_PIANO_TOP_FRAME_BTN_H);	
	backBtn->setIsEffect(VFX_TRUE);
	backBtn->setEffectRatio(1.1f);
	backBtn->m_signalClicked.connect(this, &VappPianoSettingPage::onTitleBtnHandler);

    // setting form
    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setSize(getSize());
    m_form->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                VFX_FRAME_ALIGNER_MODE_SIDE,
                                VFX_FRAME_ALIGNER_MODE_SIDE, 
                                VFX_FRAME_ALIGNER_MODE_SIDE);
    m_form->setRect(0, topFrame->getRect().getMaxY() + 1, getSize().width, getSize().height - topFrame->getRect().getMaxY() - 1);

    VfxS32 sliLen = 250;

    // create sw form cell: key label
    VFX_OBJ_CREATE(m_keyLabelFormChell, VcpFormItemSwitchCell, m_form);
    m_keyLabelFormChell->setMainText(VFX_WSTR_RES(STR_ID_VAPP_PIANO_SETTING_SW_LABEL));
    m_keyLabelFormChell->setSwitchStatus(VFX_TRUE);
    m_form->addItem(m_keyLabelFormChell, ID_FORM_CELL_SWITCH_KEY_LABEL);
    m_keyLabelFormChell->m_signalSwitchChangeReq.connect(this, &VappPianoSettingPage::onLabelSwitchChangeReq);

    VfxU32 chellHeight = m_keyLabelFormChell->getSize().height;
    VfxColor mainTextColor = m_keyLabelFormChell->m_mainText->getColor();

    // create custom form cell: program
    
    VFX_OBJ_CREATE(m_programFormChell, VcpFormItemCustomFrame, m_form);

    VfxFrame *programFrame;
    VFX_OBJ_CREATE(programFrame, VfxFrame, m_programFormChell);
    programFrame->setSize(LCD_HEIGHT, chellHeight);

    VFX_OBJ_CREATE(m_programTextFrame, VfxTextFrame, programFrame);
    m_programTextFrame->setAnchor(0.0f, 0.5f);
    m_programTextFrame->setPos(20, chellHeight / 2);
    m_programTextFrame->setSize(VAPP_PIANO_SETTING_FORM_SLIDER_TEXTFRAME_W, VAPP_PIANO_SETTING_FORM_SLIDER_TEXTFRAME_H);
    m_programTextFrame->setColor(mainTextColor);
    m_programTextFrame->setString(VFX_WSTR_RES(STR_ID_VAPP_PIANO_SETTING_MIDI_PROGRAME));

    VFX_OBJ_CREATE(m_programSlider, VcpSlider, programFrame);
    m_programSlider->setAnchor(1, 0.5f);
    m_programSlider->setPos(LCD_HEIGHT - 20, chellHeight / 2);
    m_programSlider->setLayout(VCP_SLIDER_LAYOUT_HORZ);
    m_programSlider->setLength(sliLen);
    m_programSlider->setMaxValue(VAPP_PIANO_MIDI_INSTRUTMENT_NUM - 1);
    m_programSlider->setMinValue(0);
    m_programSlider->setTotalDiscreteStepsForPen(VAPP_PIANO_MIDI_INSTRUTMENT_NUM - 1);
    m_programSlider->m_signalThumbReleased.connect(this, &VappPianoSettingPage::onProgramSliderChange);
    m_programSlider->m_signalThumbDrag.connect(this, &VappPianoSettingPage::onProgramSlideThumbDrag);

    m_programFormChell->attachCustomFrame(programFrame);
    m_form->addItem(m_programFormChell);
    m_form->insertSeparator(m_programFormChell);


	////
/*
	VcpFormItemLauncherCell *launchProgram;
	VFX_OBJ_CREATE(launchProgram, VcpFormItemLauncherCell, m_form);
	launchProgram->setMainText(VFX_WSTR_RES(STR_ID_VAPP_PIANO_SETTING_MIDI_PROGRAME));
	launchProgram->setAccessory(VCPFORM_NEXT_ITEM_ICON);
	launchProgram->m_signalTap.connect(this, &VappPianoSettingPage::onItemCellLaunch);
	m_form->addItem(launchProgram, ID_FORM_CELL_LAUNCH_PROGRAM);
 */     
}

void VappPianoSettingPage::onQueryRotateEx( VfxScreenRotateParam &param)
{
    param.rotateTo = VFX_SCR_ROTATE_TYPE_270;
}

void VappPianoSettingPage::onTitleBtnHandler(VfxObject* sender, VfxId id)
{
    getMainScr()->popPage();
}
void VappPianoSettingPage::onLabelSwitchChangeReq(VcpFormItemSwitchCell* item, VfxId id, VfxBool newStatus)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_SETTING_ON_LABEL_SW_CHANGE, newStatus);

    item->setSwitchStatus(newStatus);
    m_sigLabelSwChange.emit(newStatus);

    // write to NVRAM
    VfxS16 sError = 0;
    VfxS32 ret = 0;
    ret = WriteValue(NVRAM_VAPP_PIANO_SETTING_SW_LABEL, (void*)&newStatus, DS_BYTE, &sError);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_FLUSH_TO_NVRAM, ret);
}

void VappPianoSettingPage::onMidiSwitchChangeReq(VcpFormItemSwitchCell* item, VfxId id, VfxBool newStatus)
{
    item->setSwitchStatus(newStatus);
    m_sigMidiSwChange.emit(newStatus);

    // if it is not midi mode, disable midi program control
    m_programFormChell->setIsDisabled(!newStatus);
}

void VappPianoSettingPage::onProgramSliderChange(VcpSlider* slider, VfxFloat value)
{
    setProgramChellValue(value);
    m_sigProgramSliChange.emit(transferToMidiProgramID(value));

    // write to NVRAM
    VfxS16 sError = 0;
    VfxS32 ret = 0;
    VfxU8 midiProgram = transferToMidiProgramID(value);
    ret = WriteValue(NVRAM_VAPP_PIANO_SETTING_MIDI_PROGRAM, (void*)&midiProgram, DS_BYTE, &sError);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_FLUSH_TO_NVRAM, ret); 
}

void VappPianoSettingPage::onProgramSlideThumbDrag(VcpSlider *slider, VfxFloat value)
{
    setProgramChellValue(value);
}

void VappPianoSettingPage::setProgramChellValue(VfxS32 g)
{
    m_programSlider->setCurrentValue(g);
    m_midiProgram = g;
    VfxWString str = VFX_WSTR_RES(STR_ID_VAPP_PIANO_SETTING_MIDI_PROGRAME);

    // set program name
    VfxU8 offset = g;
    VfxWString name = VFX_WSTR_RES(STR_ID_VAPP_PIANO_MIDI_PROGRAME_0 + offset);
    setProgramName(name);
}

void VappPianoSettingPage::setProgramName(VfxWString name)
{
    VfxWString str = VFX_WSTR_RES(STR_ID_VAPP_PIANO_SETTING_MIDI_PROGRAME);

    VfxWString str2= VFX_WSTR(": ");
    
    str += str2;
    str += name;
    m_programTextFrame->setString(str);
    
}

VfxU32 VappPianoSettingPage::transferToMidiProgramID(VfxU32 uiValue)
{
    switch (uiValue)
    {
        case 1:
            return VAPP_PIANO_MIDI_INSTRUTMENT_1;
        case 2:
            return VAPP_PIANO_MIDI_INSTRUTMENT_2;
        case 3:
            return VAPP_PIANO_MIDI_INSTRUTMENT_3;
        case 4:
            return VAPP_PIANO_MIDI_INSTRUTMENT_4;         
        case 0:
        default:
            return VAPP_PIANO_MIDI_INSTRUTMENT_0;
    }
}

VfxU32 VappPianoSettingPage::transferToUiProgramID(VfxU32 graogramID)
{
    switch (graogramID)
    {
        case VAPP_PIANO_MIDI_INSTRUTMENT_1:
            return 1;
        case VAPP_PIANO_MIDI_INSTRUTMENT_2:
            return 2;
        case VAPP_PIANO_MIDI_INSTRUTMENT_3:
            return 3;
        case VAPP_PIANO_MIDI_INSTRUTMENT_4:
            return 4;          
        case VAPP_PIANO_MIDI_INSTRUTMENT_0:
        default:
            return 0;
    }
}

VFX_IMPLEMENT_CLASS("VappPianoPage", VappPianoPage, VfxPage);

VappPianoPage::VappPianoPage()  
    :m_topFrame(NULL),
    m_pianoKeyboard(NULL)
{
}

void VappPianoPage::onInit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_ON_INIT);
    
    VfxPage::onInit(); 
    setStatusBar(VFX_FALSE); 
    setBgColor(VFX_COLOR_BLACK);

	// top frame
	VFX_OBJ_CREATE(m_topFrame, VfxFrame, this);
	m_topFrame->setPos(0, 0);
	m_topFrame->setSize(LCD_HEIGHT, VAPP_PIANO_TOP_FRAME_HEIGHT);
	m_topFrame->setImgContent(VfxImageSrc(IMG_ID_VAPP_PIANO_TOP_FRAME));
	VfxU32 topFrameHeight = m_topFrame->getSize().height;

	VfxTextFrame *titleFrame;
	VFX_OBJ_CREATE(titleFrame, VfxTextFrame, m_topFrame);
	titleFrame->setColor(VFX_COLOR_WHITE);
	titleFrame->setAnchor(0.5f, 0.5);
	titleFrame->setPos(LCD_HEIGHT * 0.5, topFrameHeight * 0.5);
	titleFrame->setString(VFX_WSTR_RES(STR_ID_VAPP_PIANO_TITLE));

	VcpImageButton *settingBtn;
	VFX_OBJ_CREATE(settingBtn, VcpImageButton, m_topFrame);
	settingBtn->setId(VAPP_PIANO_SETTING_BTN);
	settingBtn->setAnchor(0.5, 0.5f);
	settingBtn->setImage(VcpStateImage(IMG_ID_VAPP_PIANO_SETTING_BTN, 0, 0, 0));
    settingBtn->setPos(LCD_HEIGHT - topFrameHeight * 0.5, topFrameHeight * 0.5);
	settingBtn->setSize(VAPP_PIANO_TOP_FRAME_BTN_W, VAPP_PIANO_TOP_FRAME_BTN_H);	
	settingBtn->setIsEffect(VFX_TRUE);
	settingBtn->setEffectRatio(1.1f);
	settingBtn->m_signalClicked.connect(this, &VappPianoPage::onSettingBtnClicked);
   
}

void VappPianoPage::onDeinit()
{
    flushToNVRAM();
    VfxPage::onDeinit();
}

void VappPianoPage::onEnter(VfxBool isBackward)
{    
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_ON_ENTER, isBackward);

    // connect call event handle
    m_sigCallhandle.connect(this, &VappPianoPage::handleCallEvent);

    // register to media volume event
    mmi_frm_cb_reg_event(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE, (mmi_proc_func)&VappPianoPage::onServiceProc, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_UCM_STATUS_CHANGE, (mmi_proc_func)&VappPianoPage::onServiceProc, this);    

    // close background audio(not suspend)
    mdi_audio_terminate_background_play();

    // init keyboard
    if(m_pianoKeyboard == NULL)
    {
	    // initiate piano keyboard frame
        VFX_OBJ_CREATE(m_pianoKeyboard, VappPianoKeyboard, this);
        m_pianoKeyboard->setPos(0, VAPP_PIANO_TOP_FRAME_HEIGHT);
        m_pianoKeyboard->setRect(0, m_topFrame->getRect().getMaxY(), getSize().width, getSize().height - m_topFrame->getRect().getMaxY());
        m_pianoKeyboard->initKeyboard();

        // read setting saved in NYRAM
        readFromNVRAM();
    
        // update keyboard
        m_pianoKeyboard->displayKeyboard();
    }
    else
    {
        m_pianoKeyboard->resetKeyboard();
    }

    // init player when not on call
    if(!isOnCall())
    {
        m_pianoKeyboard->initPlayer();
    }
}
void VappPianoPage::onExit(VfxBool isBackward)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_ON_EXIT, isBackward);

    // disconnect call event handle
    m_sigCallhandle.disconnect(this, &VappPianoPage::handleCallEvent);

    // unregister to media volume event
    mmi_frm_cb_dereg_event(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE, (mmi_proc_func)&VappPianoPage::onServiceProc, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_UCM_STATUS_CHANGE, (mmi_proc_func)&VappPianoPage::onServiceProc, this);    

    // note we do not need to resume background audio
    //mdi_audio_resume_background_play();

    if(m_pianoKeyboard != NULL)
    {
        m_pianoKeyboard->setMultiTouchMode(VFX_FALSE);
        m_pianoKeyboard->closePlayer();
    }
}


mmi_ret VappPianoPage::onServiceProc(mmi_event_struct *evt)
{
    switch(evt->evt_id)
    {
        case EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE:
        {
            vapp_vol_dialog_evt_struct *vol_evt = (vapp_vol_dialog_evt_struct*) evt;

            if(vol_evt->type == VAPP_VOL_DIALOG_IS_MEDIA)
            {
                return !MMI_RET_OK;
            }
            break;
        }
        case EVT_ID_SRV_UCM_STATUS_CHANGE:
        {
            // post emit instead of return pThis->handleCallEvent to avoid error caused by
            // call service not terminate done while AP recieve call status change 
            VappPianoPage* pThis = (VappPianoPage*)evt->user_data;
            pThis->m_sigCallhandle.postEmit();
            break;
        }
        default:
            break;
    }

    return MMI_RET_OK;
    //return VfxPage::onProc(evt);
}

void VappPianoPage::handleCallEvent()
{
    VfxBool makingCall = isOnCall();
    if(makingCall)
    {   
        closePlayer();
    }
    else
    {            
        openPlayer();
    }
}

void VappPianoPage::onQueryRotateEx( VfxScreenRotateParam &param)
{
    param.rotateTo = VFX_SCR_ROTATE_TYPE_270;
}

void VappPianoPage::readFromNVRAM()
{
    // read MMI_CACHE
    VfxS16 sError = 0;
    VfxS32 ret = 0;
    if(m_pianoKeyboard != NULL)
    {
        VfxBool hideKeyLabel = VFX_FALSE;
        VfxU8 midiProgram = 0;
        ret = ReadValue(NVRAM_VAPP_PIANO_SETTING_SW_LABEL, (void*)&hideKeyLabel, DS_BYTE, &sError);
        ret = ReadValue(NVRAM_VAPP_PIANO_SETTING_MIDI_PROGRAM, (void*)&midiProgram, DS_BYTE, &sError);

        // set piano properties
        m_pianoKeyboard->setKeyLabelHidden(static_cast<VfxU8>(hideKeyLabel));
        m_pianoKeyboard->setMidiProgram(static_cast<VfxU8>(midiProgram));
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_READ_FROM_NVRAM, ret);
}

void VappPianoPage::flushToNVRAM()
{
    // write MMI_CACHE
    VfxS16 sError = 0;
    VfxS32 ret = 0;
    if(m_pianoKeyboard != NULL)
    {
        VfxBool hideKeyLabel = m_pianoKeyboard->getKeyLabelHidden();
        VfxU8 midiProgram = m_pianoKeyboard->getMidiProgram();
        ret = WriteValue(NVRAM_VAPP_PIANO_SETTING_SW_LABEL, (void*)&hideKeyLabel, DS_BYTE, &sError);
        ret = WriteValue(NVRAM_VAPP_PIANO_SETTING_MIDI_PROGRAM, (void*)&midiProgram, DS_BYTE, &sError);
    }

    // TODO: flush to NVRAM if change setting certainly     
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_FLUSH_TO_NVRAM, ret);
}
void VappPianoPage::showErrMsgFrame(VfxBool b)
{
    if(m_errMsgFrame == NULL)
    {
        // create msg frame for err handle
        VFX_OBJ_CREATE(m_errMsgFrame, VfxFrame, this);
        m_errMsgFrame->setSize(LCD_HEIGHT, LCD_WIDTH);
        m_errMsgFrame->setBgColor(VFX_COLOR_WHITE);
        m_errMsgFrame->setOpacity(0.5f);
        m_errMsgFrame->setPos(0, 0);
        m_errMsgFrame->setHidden(VFX_TRUE);
    }
    m_errMsgFrame->setHidden(!b);
}

void VappPianoPage::onSettingBtnClicked(VfxObject* sender, VfxId id)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_ON_SEETING_BTN_CLICKED);
    
	// create setting page    
	VappPianoSettingPage *settingPage;
	VFX_OBJ_CREATE(settingPage, VappPianoSettingPage, this->getMainScr());

    // set ui value
	settingPage->setKeyLabelChellStatus(m_pianoKeyboard->getKeyLabelHidden());
	VfxU32 uiProgramValue = settingPage->transferToUiProgramID(m_pianoKeyboard->getMidiProgram());
	settingPage->setProgramChellValue(uiProgramValue);
    
    // connect
	settingPage->m_sigLabelSwChange.connect(m_pianoKeyboard, &VappPianoKeyboard::slotLabelHidden);
	//settingPage->m_sigMidiSwChange.connect(m_pianoKeyboard, &VappPianoKeyboard::slotPlayMidi);
	settingPage->m_sigProgramSliChange.connect(m_pianoKeyboard, &VappPianoKeyboard::slotProgramChanged);

    // push page
	getMainScr()->pushPage(0, settingPage);
}

void VappPianoPage::openPlayer()
{
    if(m_pianoKeyboard != NULL)
    {
        m_pianoKeyboard->initPlayer();
    }
}
void VappPianoPage::closePlayer()
{
    if(m_pianoKeyboard != NULL)
    {
        m_pianoKeyboard->closePlayer();
    }
}

VfxBool VappPianoPage::isOnCall()
{
	if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        return VFX_TRUE;
    }
	return VFX_FALSE;
}

VFX_IMPLEMENT_CLASS("VappPianoScreen", VappPianoScreen, VfxMainScr);

void VappPianoScreen::on1stReady()
{
    VfxMainScr::on1stReady();

    // create and display piano page
    VFX_OBJ_CREATE(m_page, VappPianoPage, this);
    pushPage(VAPP_PIANO_PAGE, m_page);   
}

void VappPianoScreen::onQueryRotateEx( VfxScreenRotateParam &param)
{
    param.rotateTo = VFX_SCR_ROTATE_TYPE_270;
}

void VappPianoScreen::showErrMsgFrame(VfxBool b)
{
    if(getTopPageId() == VAPP_PIANO_PAGE)
    {
        m_page->showErrMsgFrame(b);
    }
}
void VappPianoScreen::openPlayer()
{
    if(getTopPageId() == VAPP_PIANO_PAGE)
    {
        m_page->openPlayer();
    }
}
void VappPianoScreen::closePlayer()
{
    m_page->closePlayer();
}


VFX_IMPLEMENT_CLASS("VappPianoApp", VappPianoApp, VfxApp);

void VappPianoApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    // create and display main screen
    VFX_OBJ_CREATE(m_scr, VappPianoScreen, this);
    m_scr->show();
}
void VappPianoApp::onDeinit()
{
    VfxApp::onDeinit();
}

#endif /* __MMI_FTO_PIANO__*/

