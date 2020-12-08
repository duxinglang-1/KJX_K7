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
 *  vapp_piano_key.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_PIANO_KEYBOARD_H__
#define __VAPP_PIANO_KEYBOARD_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h" 
#if (defined(__MMI_FTO_PIANO__) && defined(__J2ME__))

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vfx_uc_include.h"
#include "vcp_pluto_control.h"
extern "C"
{
#include "med_api.h"
#include "mdi_datatype.h"
}

#include "lcd_sw_inc.h"

#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__MM_DEBUG_MEASURE__)
#ifdef __cplusplus
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#ifdef __cplusplus
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#else
#define PIANO_MEASURE_TIME_START(_symbol_)
#define PIANO_MEASURE_TIME_STOP(_symbol_)
#endif
/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_PIANO_ONE_OCTAVE_KEY_CNT         12
#define VAPP_PIANO_KEYBOARD_KEY_ZORDER         1
#define VAPP_PIANO_KEYBOARD_SHARPKEY_ZORDER    0
#define VAPP_PIANO_KEYBOARD_KEY_ANCHORX             0.f
#define VAPP_PIANO_KEYBOARD_SHARPKEY_ANCHORX_A    0.67f
#define VAPP_PIANO_KEYBOARD_SHARPKEY_ANCHORX_B    0.33f
#define VAPP_PIANO_KEYBOARD_SHARPKEY_ANCHORX_C    0.5f

// keyboard
#define VAPP_PIANO_KEYBOARD_KEY_WIDTH               80
#define VAPP_PIANO_KEYBOARD_KEY_HEIGHT             400
#define VAPP_PIANO_KEYBOARD_SHARPKEY_WIDTH          60
#define VAPP_PIANO_KEYBOARD_SHARPKEY_HEIGHT        250

// Midi
#define VAPP_PIANO_MIDI_PITCH_OFFSET 12

// hit test
#define VAPP_PIANO_HITTEST_MAX_CANDIDATES 2

#define VAPP_PIANO_VALID_KEY_PRESS_LOCK_COUNT          0
#define VAPP_PIANO_VALID_KEY_RELEASE_LOCK_COUNT        2

//debug mode
#define VAPP_PIANO_DEBUG_MODE 0

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class
 *****************************************************************************/

class VappPianoKey : public VfxFrame
{
    VFX_DECLARE_CLASS(VappPianoKey);
public:
    VappPianoKey();
    void onInit();
    
public:
    //key data
    void    setKeyData(VfxS32 id);
    VfxS32  getID() {return this->m_id;};
    VfxBool getIsSharp() {return m_isSharp; };
    void    setKeyClicked(VfxBool flag){m_clicked = flag;};
    VfxBool getKeyClicked(){return m_clicked;};
    VfxS32 getOffsetX();
    void resetKeyApprence(VfxS32 w, VfxS32 h);

    // key press count
    VfxU8 getPressLockCount();
    void resetPressLockCount();
    void increasePressLockCount();
    void decreasePressLockCount();
    void printPressLockCount();
    
    // label
    VfxWString getLabelString();
    void setKeyLabelPos(VfxS32 x, VfxS32 y);  
    void setLabelHidden(VfxBool b){m_label->setHidden(b);};

    // audio effect 
    mdi_handle m_mdiHandle;

    //event
    void onKeyClicked(VfxBool flag);

private:    
    void setKeySize(VfxS32 w, VfxS32 h);
private:
    VfxS32 m_id;
    VfxBool m_isSharp;
    VfxBool m_clicked;
    VfxFloat m_keyAnchorX;
    VfxU8 m_pressLockCount;
    
    // label
    VfxTextFrame *m_label;
    VfxFrame *m_pressedFrame;
    VfxFrame *m_releasedFrame;

    // degug usage
    VfxTextFrame *m_debugFrame;
};


class VappPianoKeyboard : public VfxControl
{
    VFX_DECLARE_CLASS(VappPianoKeyboard);
public:
    VappPianoKeyboard();
    void onInit();
    void onDeinit();
    void initKeyboard();
    void resetKeyboard();
    void setMultiTouchMode(VfxBool b);

private:
    // keys of keyboard
    VfxS32 m_startKey;   
    VfxS32 m_endKey;
    VfxObjList m_keys;
    VfxBool m_hideKeyLabel;
    
    // midi handle
    VfxU32     m_midiProgram;
    kal_int32  m_midiHandle;

    enum VappPianoKeyListID
    {        
        ID_DOWN_LIST,
        ID_UP_LIST,
        ID_TODO_DOWN_LIST,
        ID_TODO_UP_LIST
    };
    VfxObjList m_upKeys;
    VfxObjList m_downKeys;
    VfxObjList m_todoDownKeys;
    VfxObjList m_todoUpKeys;

public:    
    // keyboard setting
    VfxBool getKeyLabelHidden(){return m_hideKeyLabel;};
    VfxU32 getMidiProgram(){return m_midiProgram;};    
    
    void setKeyLabelHidden(VfxBool b){m_hideKeyLabel = b;};
    void setMidiProgram(VfxU32 programID);

    // keyboard layout
    void updateKeyboardData();
    void displayKeyboard();   
    void setAllKeyClicked(VfxBool b);

    // hit test
	VappPianoKey* findHitKey(const VfxTouchEvent &event);
    VappPianoKey* findPrevHitKey(const VfxTouchEvent &event);
    VappPianoKey* getKey(VfxU32 keyId);

    // search 
    VfxBool catchMoreKey;
    void pressKey(VappPianoKey* key);
    void releaseKey(VappPianoKey* key);
    VfxBool searchList(VappPianoKeyListID listID, VfxU32 keyId);
    

    // key sound
    void initPlayer();
    void closePlayer();
    void closeMidiPlayer();
        
    void playMidiSound(VfxS32 keyID);
    void stopMidiSound(VfxS32 keyID);

    // midi player
    void setHarmonyBufData(VappPianoKeyListID listID, kal_uint8* buf, VfxU32 startIndex);
    void playMidiHarmony(kal_uint8* buf, kal_uint16 len);
    void handlePianoAudio(void *data);

    VfxBool isMakingCall();

    static void onMdiAuioProc(mdi_result result, void* param);    
    void handleMdiAuioProc(mdi_result result);

// override to handle the pen input event
protected:
    virtual VfxBool onPenInput(VfxPenEvent &event);

// slot
public:
    void slotLabelHidden(VfxBool b);
    void slotProgramChanged(VfxFloat value);
};


#endif /* __MMI_FTO_PIANO__*/

#endif /* __VAPP_PIANO_KEYBOARD_H__ */


