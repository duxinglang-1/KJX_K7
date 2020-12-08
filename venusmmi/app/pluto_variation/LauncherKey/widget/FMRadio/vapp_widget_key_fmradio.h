/***************************************************************************** 
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_widget_key_fmradio.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_KEY_FM_RADIO__)
#include "vapp_widget_def.h"
#include "vfx_control.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_signal.h"
#include "vfx_input_event.h"
#include "vfx_cpp_base.h"
#include "vfx_primitive_frame.h"
#include "vfx_frame.h"
#include "vfx_draw_context.h"
#include "vapp_widget.h"
#include "vfx_sys_memory.h"
#include "vfx_string.h"
#include "vfx_timer.h"
#include "vfx_weak_ptr.h"
#include "vfx_text_frame.h"


extern "C"
{
#include "wgui.h"
#include "FileMgrSrvGProt.h"
}


class VappWidgetKeyFMRadioButton:public VfxControl
{
public:    
    VappWidgetKeyFMRadioButton();    
    ~VappWidgetKeyFMRadioButton(); 

    // Override    
protected:
    // On init
    virtual void onInit();

    // On Deinit
    virtual void onDeinit();
    // Signal
public:
    // Pen down signal
    VfxSignal1 <VfxPenEvent &> m_eventPenDown;
    // Pen up signal
    VfxSignal1 <VfxPenEvent &> m_eventPenUp;	
    
public:
    void setImage(VfxS32 imageid );
    void setDisplay(VfxBool isDisplay);
    VfxBool isContains(VfxPoint pos, VfxU16 type);

private:
    VfxImageFrame *m_Image;
};


class VappWidgetKeyFMRadioPanel:public VfxControl
{
public:
    VappWidgetKeyFMRadioPanel();
    ~VappWidgetKeyFMRadioPanel();

protected:
    virtual void onInit();
    virtual void onDeinit();

private:
    VfxU16 getState(void);
    VfxU16 getCurFreq(void);
    void setFreq(VfxU16);
    void onTimerClick(VfxTimer *timer);    
    void startCurTimer(void);
    void stopCurTimer(void);
	
    void onLTimerClick(VfxTimer *timer);    
    void startLTimer(void);
    void stopLTimer(void);	
    void getFreqString(VfxU16 freq, VfxWChar *timeStr,VfxU32 maxLength) const;
 
public:

    static void fmRadioSearchCallback(const void *user_data, VfxU16 result);
    static void fmRadioPowerCallback(const void *user_data, VfxU32 result);
    void updateDisplay(void);
    void onPowerOn(VfxKeyEvent &event);
    void onPowerOff(VfxKeyEvent &event);
    void switchPrev(VfxKeyEvent & event);
    void switchNext(VfxKeyEvent & event);
    void resetSearchImage(void);
    void onButtonUp(VfxObjWeakPtr this_ptr);

public:
    virtual VfxBool onKeyInput(VfxKeyEvent & event);
    virtual VfxBool onPenInput(VfxPenEvent & event);

private:
    VfxImageFrame *m_ImageBg;
    VfxImageFrame *m_ImageHole;
    VappWidgetKeyFMRadioButton *m_Power;
    VappWidgetKeyFMRadioButton *m_ButPrev;
    VappWidgetKeyFMRadioButton *m_ButNext;
    VfxImageFrame *m_Searching;
    VfxBool m_IsSearching;
    VfxBool m_IsTimerStart;
    VfxBool m_IsLTimerStart;
    VfxBool m_IsLPrev;
    VfxBool m_IsLNext;
    VfxBool m_IsButPower;
    VfxBool m_IsButPrev;
    VfxBool m_IsButNext;
    VfxBool m_IsPrevPressing;
    VfxBool m_IsNextPressing;
    VfxBool m_IsPowerPressing;
    VfxTimer *m_Timer;
    VfxTimer *m_LTimer;
    VfxU16 m_State;
    VfxU16 m_CurFrequency;
    VfxTextFrame *m_FMRadioName;
    VfxTextFrame *m_FMRadioChannel;
    VfxTextFrame *m_FMRadioMHZ;
    VfxFontEffect  *m_Effect;
};

class VappWidgetKeyFMRadio:public VappWidget
{
    VAPP_WIDGET_DECLARE_CLASS(VappWidgetKeyFMRadio);
public:
    VappWidgetKeyFMRadio();
	
// Override
public:
    virtual VappWidgetId getId() const;
    virtual VfxSize getMaxSize() const;
    virtual VfxS32 getName(VfxWChar *string, VfxS32 size) const;
    virtual VfxFrame *createIcon(VfxObject *parentObj);
    virtual VfxPoint onGetEditButtonOffset();
    virtual void onCreateView();
    // Release the whole widget content
    virtual void onReleaseView();
    virtual VfxBool onPreviewPenInput(VfxPenEvent & event);
    virtual VfxBool onPenInput(VfxPenEvent & event);

private:
    VappWidgetKeyFMRadioPanel  *m_Panel;    
};

#endif
