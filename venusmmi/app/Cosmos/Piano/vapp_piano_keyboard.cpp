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
 *  vapp_piano_keyboard.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 * Piano app 
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

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h" 
#if (defined(__MMI_FTO_PIANO__) && defined(__J2ME__))

#include "vapp_piano_keyboard.h"
#include "mmi_rp_vapp_piano_def.h"
#include "vcp_pluto_control.h"
#include "vcp_include.h"

extern "C"
{
#include "Wgui_categories_util.h" 
#include "Med_api.h"
#include "AUD_Main.h"
#include "BthScoPathSrvGProt.h"
#include "mdi_audio.h"
#include "ProfilesSrvGprot.h"
#include "UcmSrvGprot.h"
}

#include "Unicodexdcl.h"


//#include "BthfSrvGprot.h"



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
VFX_IMPLEMENT_CLASS("VappPianoKey", VappPianoKey, VfxFrame);

VappPianoKey::VappPianoKey()
    :m_id(0),
    m_isSharp(VFX_FALSE),
    m_clicked(VFX_FALSE), 
    m_keyAnchorX(0.f),
    m_label(NULL),
    m_pressedFrame(NULL),
    m_releasedFrame(NULL),
    m_mdiHandle(NULL),
    m_debugFrame(NULL),
    m_pressLockCount(0)
{}

void VappPianoKey::onInit()
{
    VfxFrame::onInit();

    // key pressed frame and released frame
    VFX_OBJ_CREATE(m_pressedFrame, VfxFrame, this);
    m_pressedFrame->setPos(0, 0);

    VFX_OBJ_CREATE(m_releasedFrame, VfxFrame, this);
    m_releasedFrame->setPos(0, 0);
    
    // key label
    VFX_OBJ_CREATE(m_label, VfxTextFrame, this);
    m_label->setColor(VFX_COLOR_RED);
    m_label->setAnchor(0.5f, 1);
    m_label->setPos(50, 50);
   
    VfxWString str;
    str.format("%d", this->m_id);
    this->m_label->setString(str);

    // debug mode
    if(VAPP_PIANO_DEBUG_MODE)
    {
        VFX_OBJ_CREATE(m_debugFrame, VfxTextFrame, this);
        m_debugFrame->setHidden(VFX_FALSE);
        m_debugFrame->setAnchor(0, 1);
        printPressLockCount();
    }

    // prevent cache to enhance UI respond time
    setCacheMode(VFX_CACHE_MODE_PREVENT);
}
void VappPianoKey::setKeyData(VfxS32 id)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_KEY_SET_DATA, id);
    
    this->m_id = id;

    if(m_debugFrame)
    {
        m_debugFrame->setSize(VAPP_PIANO_KEYBOARD_SHARPKEY_WIDTH, 50);            
        m_debugFrame->setPos(0, VAPP_PIANO_KEYBOARD_SHARPKEY_HEIGHT);
    }

    // determine whether it is a sharp key
    VfxS32 keyNote = m_id % VAPP_PIANO_ONE_OCTAVE_KEY_CNT;
    switch (keyNote)
    {
        case 1:    // key C#
        case 6:    //key F#
        {
            this->m_isSharp = VFX_TRUE;
            this->m_keyAnchorX = VAPP_PIANO_KEYBOARD_SHARPKEY_ANCHORX_A;
            setPosZ(VAPP_PIANO_KEYBOARD_SHARPKEY_ZORDER);

            this->m_label->setPos(VAPP_PIANO_KEYBOARD_SHARPKEY_WIDTH / 2, VAPP_PIANO_KEYBOARD_SHARPKEY_HEIGHT - 50);
            break;
        }
        case 3:     // key D#
        case 10:    // key A#
        {
            this->m_isSharp = VFX_TRUE;
            this->m_keyAnchorX = VAPP_PIANO_KEYBOARD_SHARPKEY_ANCHORX_B;
            setPosZ(VAPP_PIANO_KEYBOARD_SHARPKEY_ZORDER);
            
            this->m_label->setPos(VAPP_PIANO_KEYBOARD_SHARPKEY_WIDTH / 2, VAPP_PIANO_KEYBOARD_SHARPKEY_HEIGHT - 50);
            break;
        }
        case 8:    // key G#
        {
            this->m_isSharp = VFX_TRUE;
            this->m_keyAnchorX = VAPP_PIANO_KEYBOARD_SHARPKEY_ANCHORX_C;
            setPosZ(VAPP_PIANO_KEYBOARD_SHARPKEY_ZORDER);

            this->m_label->setPos(VAPP_PIANO_KEYBOARD_SHARPKEY_WIDTH / 2, VAPP_PIANO_KEYBOARD_SHARPKEY_HEIGHT - 50);
            break;
        }
        default:
        {
            this->m_isSharp = VFX_FALSE;
            this->m_keyAnchorX = VAPP_PIANO_KEYBOARD_KEY_ANCHORX;
            setPosZ(VAPP_PIANO_KEYBOARD_KEY_ZORDER);

            this->m_label->setPos(VAPP_PIANO_KEYBOARD_KEY_WIDTH / 2, VAPP_PIANO_KEYBOARD_KEY_HEIGHT - 100);

            if(m_debugFrame)
            {
                m_debugFrame->setSize(VAPP_PIANO_KEYBOARD_KEY_WIDTH, 50);            
                m_debugFrame->setPos(0, VAPP_PIANO_KEYBOARD_KEY_HEIGHT);
            }
            break;
        }
    }

    //update anchor
    setAnchor(m_keyAnchorX, 0.f);

    // update label
    this->m_label->setString(getLabelString());
}

VfxS32 VappPianoKey::getOffsetX()
{
    VfxS32 keyNote = m_id % VAPP_PIANO_ONE_OCTAVE_KEY_CNT;
    switch (keyNote)
    {
        case 1:    
        case 6:    
            return 40;
        case 3:     
        case 10:    
            return 20;
        case 8:    
            return 30;
        default:
            return 0;   
    }
}

void VappPianoKey::resetKeyApprence(VfxS32 w, VfxS32 h)
{
    setKeySize(w, h);   
    if(getIsSharp())
    {
        m_pressedFrame->setImgContent(VfxImageSrc(IMG_ID_VAPP_PIANO_SHARPKEY_CLICKED));
        m_releasedFrame->setImgContent(VfxImageSrc(IMG_ID_VAPP_PIANO_SHARPKEY));

        setKeyLabelPos(VAPP_PIANO_KEYBOARD_SHARPKEY_WIDTH * 0.5, VAPP_PIANO_KEYBOARD_SHARPKEY_HEIGHT - 50);
    }
    else
    {
        m_pressedFrame->setImgContent(VfxImageSrc(IMG_ID_VAPP_PIANO_KEY_CLICKED));
        m_releasedFrame->setImgContent(VfxImageSrc(IMG_ID_VAPP_PIANO_KEY));

        setKeyLabelPos(VAPP_PIANO_KEYBOARD_KEY_WIDTH * 0.5, VAPP_PIANO_KEYBOARD_KEY_HEIGHT - 50);
    }
    m_pressedFrame->setOpacity(0.f);
    m_releasedFrame->setOpacity(1.f);     
}

VfxU8 VappPianoKey::getPressLockCount()
{
    return m_pressLockCount;
};
void VappPianoKey::resetPressLockCount()
{
    m_pressLockCount = VAPP_PIANO_VALID_KEY_PRESS_LOCK_COUNT;
}

void VappPianoKey::increasePressLockCount()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_INCREASE_PRESS_LOCK_COUNT, m_id, m_pressLockCount, m_pressLockCount + VAPP_PIANO_VALID_KEY_RELEASE_LOCK_COUNT);
    m_pressLockCount = m_pressLockCount + VAPP_PIANO_VALID_KEY_RELEASE_LOCK_COUNT;
    printPressLockCount();
};

void VappPianoKey::decreasePressLockCount()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_DECREASE_PRESS_LOCK_COUNT, m_id, m_pressLockCount, m_pressLockCount - VAPP_PIANO_VALID_KEY_RELEASE_LOCK_COUNT);

    m_pressLockCount = m_pressLockCount - VAPP_PIANO_VALID_KEY_RELEASE_LOCK_COUNT;
    printPressLockCount(); 
};

void VappPianoKey::printPressLockCount()
{
    VfxColor c = VFX_COLOR_SILVER;

    if(m_pressLockCount == VAPP_PIANO_VALID_KEY_RELEASE_LOCK_COUNT)
    {        
        c = VFX_COLOR_RED;
    }
    else if(m_pressLockCount > VAPP_PIANO_VALID_KEY_RELEASE_LOCK_COUNT)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_MORE_THAN_VALID_KEY_RELEASE_LOCK_COUNT, m_id, m_pressLockCount);
        c = VFX_COLOR_BLUE;
    }

    if(m_debugFrame)
    {
        VfxWString str;
        str.format("%d", m_pressLockCount);            
        m_debugFrame->setString(str);
        m_debugFrame->setBgColor(c);
    }
}

VfxWString VappPianoKey::getLabelString()
{
    VfxWString str;

    // determine whether it is a sharp key
    VfxS32 keyOctave = m_id / VAPP_PIANO_ONE_OCTAVE_KEY_CNT;
    VfxS32 keyNote = m_id % VAPP_PIANO_ONE_OCTAVE_KEY_CNT;
    switch (keyNote)
    {
        case 0:
            str.format("C%d", keyOctave);
            break;
        case 2:
            str.format("D%d", keyOctave);
            break;    
        case 4:
            str.format("E%d", keyOctave);
            break;
        case 5:
            str.format("F%d", keyOctave);
            break;    
        case 7:
            str.format("G%d", keyOctave);
			break;
        case 9:
            str.format("A%d", keyOctave);
            break;
        case 11:
            str.format("B%d", keyOctave);
            break;
            
        case 1:
            str.format("C#%d", keyOctave);
            break;
        case 3:
            str.format("D#%d", keyOctave);
            break;
        case 6:
            str.format("F#%d", keyOctave);
            break;
        case 8:
            str.format("G#%d", keyOctave);
            break;
        case 10:
            str.format("A#%d", keyOctave);
            break;            

        default:
            str.format("");
            break;
    }
    return str;
}

void VappPianoKey::setKeyLabelPos(VfxS32 x, VfxS32 y)
{
    this->m_label->setPos(x, y);
}


void VappPianoKey::onKeyClicked(VfxBool flag)
{
    PIANO_MEASURE_TIME_START("POK");    
	// renderer   
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    if(renderer)
    {
        renderer->mustShowNextFrame();
    }

    setKeyClicked(flag);
    if(flag)
    {           
        m_pressedFrame->setOpacity(1.f);
        m_releasedFrame->setOpacity(0.f);      
    }
    else
    {
        m_pressedFrame->setOpacity(0.f);        
        m_releasedFrame->setOpacity(1.f);
    }
    PIANO_MEASURE_TIME_STOP("POK"); 
}

void VappPianoKey::setKeySize(VfxS32 w, VfxS32 h)
{
    setSize(w, h);
    m_pressedFrame->setSize(w,h);
    m_releasedFrame->setSize(w,h);
}

VFX_IMPLEMENT_CLASS("VappPianoKeyboard", VappPianoKeyboard, VfxControl);
VappPianoKeyboard::VappPianoKeyboard()  
    :m_startKey(48),
     m_endKey(66),
     m_hideKeyLabel(VFX_FALSE),
     m_midiProgram(0),
     m_midiHandle(0)
{ 
}
    
void VappPianoKeyboard::onInit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_KEYBOARD_ON_INIT);

    VfxControl::onInit();
    // prevent cache to reduce UI respond time
    setCacheMode(VFX_CACHE_MODE_PREVENT_PARENTS);
}

void VappPianoKeyboard::onDeinit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_KEYBOARD_ON_DEINT);
    VfxControl::onDeinit();
}
void VappPianoKeyboard::setMultiTouchMode(VfxBool b)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_KEYBOARD_SET_TOUCH_MODE, b);

    if(b)
    {
        VfxPen *pensrv = VFX_OBJ_GET_INSTANCE(VfxPen);
        pensrv->setTouchMode(VFX_PEN_TOUCH_MODE_MULTI_TOUCH);
    }
    else
    {
        VfxPen *pensrv = VFX_OBJ_GET_INSTANCE(VfxPen);
        pensrv->setTouchMode(VFX_PEN_TOUCH_MODE_SINGLE_TOUCH);
    }
}

void VappPianoKeyboard::initKeyboard()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_KEYBOARD_INIT_KEYBOARD);

    // set multitouch mode
    setMultiTouchMode(VFX_TRUE);
    
    // z order sorting for displaying sharpkeys 
    this->setIsZSortChild(VFX_TRUE);

    // layout and bg
    this->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
    this->setBgColor(VFX_COLOR_BLACK);

    // initiate key items for keyboard
    VfxS32 length = m_endKey - m_startKey + 1;
    for(VfxS32 i = 0; i < length; i++)
    {
        VappPianoKey *tempKey;
        VFX_OBJ_CREATE(tempKey, VappPianoKey, this);
        m_keys.append(tempKey);
    }
    updateKeyboardData();
    displayKeyboard();

    if(VAPP_PIANO_DEBUG_MODE)
    {
        VfxFrame *testFrame;
        VFX_OBJ_CREATE(testFrame, VfxFrame, this);
        testFrame->setBgColor(VFX_COLOR_RED);
        testFrame->setSize(800, 1);
        testFrame->setPos(0, 80);
    }
}

void VappPianoKeyboard::resetKeyboard()
{
    setMultiTouchMode(VFX_TRUE);
    setAllKeyClicked(VFX_FALSE);
    initPlayer();
}

void VappPianoKeyboard::setMidiProgram(VfxU32 programID)
{
    m_midiProgram = programID;

    // update midi handle
    if(m_midiHandle != 0)
    {
        media_mma_aud_set_program(MOD_MMI, this->m_midiHandle, MMA_TYPE_MIDI, 0, 0, m_midiProgram);
    }
};
void VappPianoKeyboard::updateKeyboardData()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_KEYBOARD_UPDATE_KEYBOARD_DATA);
    
    VfxS32 keyID = m_startKey;
    VfxObjListEntry *iter = NULL;
    for (iter = m_keys.getHead(); iter != NULL; iter = iter->getNext())
    {
        VappPianoKey *k = (VappPianoKey *)iter->get();
        k->setKeyData(keyID);
        keyID++;
    }
 }

void VappPianoKeyboard::displayKeyboard()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_KEYBOARD_DISPLAY_KEYBOARD);

    VfxPoint keyPos = VfxPoint(0, 0);
    VfxObjListEntry *iter = NULL;
    for (iter = m_keys.getHead(); iter != NULL; iter = iter->getNext())
    {
        VappPianoKey *k = (VappPianoKey *)iter->get();
        if(k->getIsSharp())
        {
            k->setLabelHidden(VFX_TRUE);
            k->resetKeyApprence(VAPP_PIANO_KEYBOARD_SHARPKEY_WIDTH, VAPP_PIANO_KEYBOARD_SHARPKEY_HEIGHT);
            k->setPos(keyPos);
        }
        else
        {
            k->setLabelHidden(this->getKeyLabelHidden());
            k->resetKeyApprence(VAPP_PIANO_KEYBOARD_KEY_WIDTH, VAPP_PIANO_KEYBOARD_KEY_HEIGHT);
            k->setPos(keyPos); 
            
            keyPos.x += VAPP_PIANO_KEYBOARD_KEY_WIDTH;
	    }
    }

}
void VappPianoKeyboard::setAllKeyClicked(VfxBool b)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_KEYBOARD_SET_ALL_KEY_CLICKED, b);

    VfxObjListEntry *iter = NULL;
    for (iter = m_keys.getHead(); iter != NULL; iter = iter->getNext())
    {
        VappPianoKey *key = (VappPianoKey *)iter->get();
        key->onKeyClicked(b);
        if(!b){key->resetPressLockCount();}
    }
}

void VappPianoKeyboard::initPlayer()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_KEYBOARD_INIT_PLAYER);

    
    // set bluetooth sco
#if  defined(__MMI_BT_AUDIO_VIA_SCO__) 
    srv_btsco_connect_audio_via_sco();
    srv_btsco_set_always_on(MMI_TRUE);
#endif /* defined(__MMI_BT_AUDIO_VIA_SCO__) */

    
    // always open the midi device for accerating wav playing
    // if m_midiHandle eaquals to 0, it means open failed last time or never been opened
    if(m_midiHandle == 0)
    {
        // open midi handle
        m_midiHandle = media_mma_aud_open_device_ext(MOD_MMI, MMA_TYPE_MIDI, KAL_TRUE);

        // reset device speaker
        mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER2);

        // set media volume
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, srv_prof_get_media_vol());
        
        // if open midi device successfully, set program (instrument)
        if(m_midiHandle != 0)
        {
            media_mma_aud_set_program(MOD_MMI, m_midiHandle, MMA_TYPE_MIDI, 0, 0, m_midiProgram);
        }

        mdi_audio_start_use_by_other_task(&VappPianoKeyboard::onMdiAuioProc, getObjHandle());
    }
}

void VappPianoKeyboard::onMdiAuioProc(mdi_result result, void* user_data)
{
    VappPianoKeyboard *pThis = (VappPianoKeyboard*)handleToObject((VfxObjHandle)(user_data));
    if(NULL == pThis)
    {
        return;
    }
    return pThis->handleMdiAuioProc(result);
}

void VappPianoKeyboard::handleMdiAuioProc(mdi_result result)
{
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Piano][Keyboard] handleMdiAuioProc[%d]", result);
    return;
}

void VappPianoKeyboard::closePlayer()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_KEYBOARD_CLOSE_PLAYER);

    // close bluetooth sco
#if  defined(__MMI_BT_AUDIO_VIA_SCO__) 
    srv_btsco_set_always_on(MMI_FALSE);
#endif /* defined(__MMI_BT_AUDIO_VIA_SCO__) */
    
    // Because we always open a midi device for accerating wav playing, midi player must be closed
    closeMidiPlayer();
}
void VappPianoKeyboard::closeMidiPlayer()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_KEYBOARD_CLOSE_MIDI_PLAYER);
    if(m_midiHandle != 0)
    {
        mdi_audio_stop_use_by_other_task();
        media_mma_aud_close_device(MOD_MMI, m_midiHandle, MMA_TYPE_MIDI);
        m_midiHandle = 0;
    }
}

void VappPianoKeyboard::playMidiSound(VfxS32 keyID)
{
    if(m_midiHandle != 0)
    {
        PIANO_MEASURE_TIME_START("PMS");
        kal_uint8 pitch = VAPP_PIANO_MIDI_PITCH_OFFSET + keyID;
        media_mma_aud_send_short_msg(MOD_MMI, m_midiHandle, MMA_TYPE_MIDI, 0x90, pitch, 80);
        PIANO_MEASURE_TIME_STOP("PMS");
    }
}
void VappPianoKeyboard::stopMidiSound(VfxS32 keyID)
{
    if(m_midiHandle != 0)
    {
        PIANO_MEASURE_TIME_START("PMS");
        kal_uint8 pitch = VAPP_PIANO_MIDI_PITCH_OFFSET + keyID;
        media_mma_aud_send_short_msg(MOD_MMI, m_midiHandle, MMA_TYPE_MIDI, 0x80, pitch, 0);
        PIANO_MEASURE_TIME_STOP("PMS");
    }
}

void VappPianoKeyboard::setHarmonyBufData(VappPianoKeyListID listID, kal_uint8* buf, VfxU32 startIndex)
{
    // choose list and volume
    kal_uint8 noteFlag = 0x80;
    kal_uint8 volume = 0;
    VfxObjListEntry *iter = NULL;
    switch(listID)
    {
        case ID_DOWN_LIST:
        {
            noteFlag = 0x90;
            volume = 80;
            iter = m_downKeys.getHead();
            break;
        }
        case ID_UP_LIST:
        {
            noteFlag = 0x80;
            volume = 0;
            iter = m_upKeys.getHead();
            break;
        }
        case ID_TODO_DOWN_LIST:
        {
            noteFlag = 0x90;
            volume = 80;
            iter = m_todoDownKeys.getHead(); 
            break;
        }
        case ID_TODO_UP_LIST:
        {
            noteFlag = 0x80;
            volume = 0;
            iter = m_todoUpKeys.getHead();
            break;
        }
        default:
            break;
    }

    // set buffer data
    VfxU32 i = startIndex;
    for (; iter != NULL; iter = iter->getNext())
    {           
        kal_uint8 note_id = ((VappPianoKey *)iter->get())->getID() + VAPP_PIANO_MIDI_PITCH_OFFSET;

        buf[i  ] = noteFlag;
        buf[i+1] = note_id;
        buf[i+2] = volume;
        i        = i+3;
     }
}

void VappPianoKeyboard::playMidiHarmony(kal_uint8* buf, kal_uint16 len)
{        
    if(m_midiHandle != 0)
    {
        PIANO_MEASURE_TIME_START("PML");
        media_mma_aud_send_long_msg(MOD_MMI, m_midiHandle, MMA_TYPE_MIDI, buf, len);
        PIANO_MEASURE_TIME_STOP("PML");    
    }
}

void VappPianoKeyboard::handlePianoAudio(void *data)
{
    PIANO_MEASURE_TIME_START("PHA");
    kal_uint32 start_time;
    kal_get_time(&start_time);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_KEYBOARD_KEY_CATCHER_TIMEOUT_TOTAL_NOTE, 
                m_downKeys.getEntryCount(), 
                m_upKeys.getEntryCount(), 
                m_todoDownKeys.getEntryCount(), 
                m_todoUpKeys.getEntryCount());

    // process sound play
    VfxU32 numCatchedKey = 0;
    numCatchedKey = m_downKeys.getEntryCount() + m_upKeys.getEntryCount();    
    if(numCatchedKey > 1)
    {        
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_KEYBOARD_KEY_CATCHER_TIMEOUT_CASE_1);

        // allowcate buffer
        kal_uint8* buf;
        VFX_ALLOC_MEM(buf, sizeof(kal_uint8) * (numCatchedKey * 3), this);

        // set buffer data                
        setHarmonyBufData(ID_DOWN_LIST, buf, 0);
        setHarmonyBufData(ID_UP_LIST, buf, m_downKeys.getEntryCount() * 3);

        // play midi long msg
        playMidiHarmony(buf, sizeof(kal_uint8) * numCatchedKey * 3);
        
        // free buffer
        VFX_FREE_MEM(buf);        
    }
    else if (numCatchedKey == 1)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_KEYBOARD_KEY_CATCHER_TIMEOUT_CASE_2);
        
        if( m_downKeys.getEntryCount() == 1)
        {
            VfxObjListEntry *iter = m_downKeys.getHead();
            kal_uint8 keyId = ((VappPianoKey *)iter->get())->getID();
            playMidiSound(keyId);
        }
        else
        {
            VfxObjListEntry *iter = m_upKeys.getHead();
            kal_uint8 keyId = ((VappPianoKey *)iter->get())->getID();
            stopMidiSound(keyId);
        }
    }

    if(m_todoDownKeys.getEntryCount() > 0)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_KEYBOARD_KEY_CATCHER_TIMEOUT_CASE_3);

        // allocate buffer
        kal_uint8* buf;
        VFX_ALLOC_MEM(buf, sizeof(kal_uint8) * (m_todoDownKeys.getEntryCount() * 3), this);

        // set buffer data                
        setHarmonyBufData(ID_TODO_DOWN_LIST, buf, 0);        

        // play midi long msg
        playMidiHarmony(buf, sizeof(kal_uint8) * (m_todoDownKeys.getEntryCount()) * 3);

        // free buffer
        VFX_FREE_MEM(buf);
    }

    if(m_todoUpKeys.getEntryCount() > 0)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_KEYBOARD_KEY_CATCHER_TIMEOUT_CASE_4);

        // allocate buffer
        kal_uint8* buf;
        VFX_ALLOC_MEM(buf, sizeof(kal_uint8) * (m_todoUpKeys.getEntryCount() * 3), this);

        // set buffer data                
        setHarmonyBufData(ID_TODO_UP_LIST, buf, 0);        

        // play midi long msg
        playMidiHarmony(buf, sizeof(kal_uint8) * (m_todoUpKeys.getEntryCount()) * 3);

        // free buffer
        VFX_FREE_MEM(buf);
    }

    // clear        
    m_downKeys.clear();
    m_upKeys.clear();
    m_todoDownKeys.clear();
    m_todoUpKeys.clear();
    
    kal_uint32 end_time; 
    kal_get_time(&end_time);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_KEYBOARD_KEY_CATCHER_TIMEOUT_END, end_time, end_time - start_time);

    PIANO_MEASURE_TIME_STOP("PHA");
}

VfxBool VappPianoKeyboard::onPenInput(VfxPenEvent &event)
{
    if(isMakingCall())
    {
        // popup err message
        for (VfxU32 i = 0; i < event.touchCount; i++)
        {
            if( event.touchEvents[i].type == VFX_PEN_EVENT_TYPE_DOWN)
            {
                mmi_frm_nmgr_balloon(
                        MMI_SCENARIO_ID_DEFAULT,
                        MMI_EVENT_INFO_BALLOON,
                        MMI_NMGR_BALLOON_TYPE_FAILURE,
                        (WCHAR *)VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL).getBuf());
                break;
            }
        }
        return VFX_TRUE;
    }

    PIANO_MEASURE_TIME_START("POP");
    kal_uint32 start_time, end_time;    
    kal_get_time(&start_time);        
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_KEYBOARD_ON_PEN_INPUT_EVENT_START, start_time);

    VfxU8 numUPkeys = 0;
    VfxBool isPenAbort = VFX_FALSE;
    catchMoreKey = VFX_FALSE;
    for (VfxU32 i = 0; i < event.touchCount; i++)
    {        
        switch (event.touchEvents[i].type)
        {
            case VFX_PEN_EVENT_TYPE_ABORT:
            {
                isPenAbort = VFX_TRUE;
                break;   
            }
            case VFX_PEN_EVENT_TYPE_DOWN:
            {      
                VappPianoKey* key = findHitKey(event.touchEvents[i]);
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_KEYBOARD_PEN_EVENT_POS, event.touchEvents[i].pos.x, event.touchEvents[i].pos.y);
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_KEYBOARD_KEY_DOWN, i, key->getID(), key->getPressLockCount());
                pressKey(key);                
                break;
            }
            case VFX_PEN_EVENT_TYPE_UP:
            {		            
                VappPianoKey* key = findHitKey(event.touchEvents[i]);
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_KEYBOARD_PEN_EVENT_POS, event.touchEvents[i].pos.x, event.touchEvents[i].pos.y);
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_KEYBOARD_KEY_UP, i, key->getID(), key->getPressLockCount());
                releaseKey(key);
                numUPkeys = numUPkeys + 1;       
                break;
            }
            case VFX_PEN_EVENT_TYPE_MOVE:
            {	
                VappPianoKey* prevKey = findPrevHitKey(event.touchEvents[i]);
                VappPianoKey* key = findHitKey(event.touchEvents[i]);
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_KEYBOARD_PEN_EVENT_PREV_POS, event.touchEvents[i].prevPos.x, event.touchEvents[i].prevPos.y);
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_KEYBOARD_PEN_EVENT_POS, event.touchEvents[i].pos.x, event.touchEvents[i].pos.y);
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_KEYBOARD_KEY_MOVE_UP, i, prevKey->getID(), prevKey->getPressLockCount());                    
                MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_KEYBOARD_KEY_MOVE_DOWN, i, key->getID(), key->getPressLockCount());

                if(key->getID() != prevKey->getID())
                {
                    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_KEYBOARD_DO_MOVE);
                    pressKey(key);
                    releaseKey(prevKey);	
                }
                break;
            }
            default:
                break;
        }
        if(isPenAbort){ break; }
    }


    kal_get_time(&end_time);        
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_KEYBOARD_ON_PEN_INPUT_EVENT_END, end_time, end_time - start_time);

    if((event.touchCount == numUPkeys) || isPenAbort)
    {
        kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[Piano] All key up");	 

        m_downKeys.clear();
        m_upKeys.clear();
        m_todoDownKeys.clear();
        m_todoUpKeys.clear();
        
        VfxObjListEntry *iter = NULL;
        for (iter = m_keys.getHead(); iter != NULL; iter = iter->getNext())
        {
            VappPianoKey *k = (VappPianoKey *)iter->get();
            if(k)
            {
                m_upKeys.append(k);
            }
        }  
     	
        setAllKeyClicked(VFX_FALSE);
        displayKeyboard();
    }

    vfxPostInvoke(this, &VappPianoKeyboard::handlePianoAudio,NULL);
    PIANO_MEASURE_TIME_STOP("POP");

    return VFX_TRUE;
}
VappPianoKey* VappPianoKeyboard::findPrevHitKey(const VfxTouchEvent &event)
{
    VfxBool searchLastTime = VFX_FALSE;

    VappPianoKey *candidates[VAPP_PIANO_HITTEST_MAX_CANDIDATES];
    VfxS8 index = -1;
    VfxObjListEntry *iter = NULL;
    for (iter = m_keys.getHead(); iter != NULL; iter = iter->getNext())
    {
        VappPianoKey *k = (VappPianoKey *)iter->get();
        if(k->containPoint(event.getRelPrevPos(k)))
        {
            index ++;
            candidates[index] = k ;
        }
        if(searchLastTime) {break;}
        if(index == 0){searchLastTime = VFX_TRUE;}
    }

    switch(index)
    {
        case 0:
        {
            return candidates[0];
        }
        case 1:
        {
            if(candidates[0]->getPosZ() > candidates[1]->getPosZ()){return candidates[1];}
            else{return candidates[0];}
        }
        default:
            break;
    }
    
    return NULL;
}


VappPianoKey* VappPianoKeyboard::findHitKey(const VfxTouchEvent &event)
{
    VfxBool searchLastTime = VFX_FALSE;
   
    VappPianoKey *candidates[2];
    VfxS8 index = -1;
    VfxObjListEntry *iter = NULL;
    for (iter = m_keys.getHead(); iter != NULL; iter = iter->getNext())
    {
        VappPianoKey *k = (VappPianoKey *)iter->get();
        if(k->containPoint(event.getRelPos(k)))
        {
            index ++;
            candidates[index] = k ;
        }
        if(searchLastTime) {break;}
        if(index == 0){searchLastTime = VFX_TRUE;}
    }

    switch(index)
    {
        case 0:
        {   
            return candidates[0];
        }
        case 1:
        {
            if(candidates[0]->getPosZ() > candidates[1]->getPosZ())
            {
                return candidates[1];
            }
            else
            {
                return candidates[0];
            }
        }
        default:
            break;
    }
    
    return NULL;
}

VappPianoKey* VappPianoKeyboard::getKey(VfxU32 keyId)
{
    
    VfxObjListEntry *iter = m_keys.getHead();
    
    for (; iter != NULL; iter = iter->getNext())
    {   
        if(keyId == ((VappPianoKey *)iter->get())->getID())
        {
            return ((VappPianoKey *)iter->get());
        }
    }
    
    return NULL; 

}

void VappPianoKeyboard::pressKey(VappPianoKey* key)
{
    if(key == NULL)
    {
        return;
    }

    if(key->getPressLockCount() == VAPP_PIANO_VALID_KEY_PRESS_LOCK_COUNT)
    {
        // make sure the key is unclicked while recieve a request about key press, or it assert
        //VFX_ASSERT(!key->getKeyClicked());        

        // change image
        key->onKeyClicked(VFX_TRUE);

        // play sound
        {
            // check to prevent a note has on and off state in the same long msg at same time
            VfxBool addToDownList = searchList(ID_UP_LIST, key->getID());
            if(addToDownList){m_todoDownKeys.append(key);}
            else{m_downKeys.append(key);}
        }
        catchMoreKey = VFX_TRUE;
    }
    key->increasePressLockCount();
}
void VappPianoKeyboard::releaseKey(VappPianoKey* key)
{
    if(key == NULL)
    {
        return;
    }
    
    if(key->getPressLockCount() == VAPP_PIANO_VALID_KEY_RELEASE_LOCK_COUNT)
    {        
        // make sure the key is clicked while recieve a request about key release, or it assert
        //VFX_ASSERT(key->getKeyClicked());    
        
        // change image
        key->onKeyClicked(VFX_FALSE);
        
        // stop sound
        {
            // check to prevent a note has on and off state in the same long msg at same time
            VfxBool addToUpList = searchList(ID_DOWN_LIST, key->getID());
            if(addToUpList){m_todoUpKeys.append(key);}
            else{m_upKeys.append(key);}
        }
        catchMoreKey = VFX_TRUE;
    }

    if(key->getPressLockCount() == VAPP_PIANO_VALID_KEY_PRESS_LOCK_COUNT)
    {
        // workaround  for lossing pen event        
        VfxU32 realTargetID = key->getID() - 1;
        if(realTargetID < m_startKey)
        {
            return;
        }
        
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_PIANO_RELEASE_REAL_TARGET, realTargetID);
        releaseKey(getKey(realTargetID));
    }
    else
    {
        key->decreasePressLockCount();
    }
}

VfxBool VappPianoKeyboard::searchList(VappPianoKeyListID listID, VfxU32 keyId)
{
    VfxObjListEntry *iter = NULL;
    switch(listID)
    {
        case ID_DOWN_LIST:
            iter = m_downKeys.getHead();
            break;
        case ID_UP_LIST:
            iter = m_upKeys.getHead();
            break;
        case ID_TODO_DOWN_LIST:
            iter = m_todoDownKeys.getHead();
            break;
        case ID_TODO_UP_LIST:
            iter = m_todoUpKeys.getHead();
            break;
        default:
            return VFX_FALSE;
    }

    // search keyID from list 
    VfxBool isFind = VFX_FALSE;
    for (; iter != NULL; iter = iter->getNext())
    {   
        if(keyId == ((VappPianoKey *)iter->get())->getID())
        {
            isFind = VFX_TRUE;
            break;
        }
    }
    
    return isFind;    
}

void VappPianoKeyboard::slotLabelHidden(VfxBool b)
{
    setKeyLabelHidden(b);
    displayKeyboard();
}

void VappPianoKeyboard::slotProgramChanged(VfxFloat value)
{
    setMidiProgram((VfxS32)value);
    
    //m_sigProgramNameChanged.emit(getMidiProgramName());
}

VfxBool VappPianoKeyboard::isMakingCall()
{
    if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

#endif /* __MMI_FTO_PIANO__*/


