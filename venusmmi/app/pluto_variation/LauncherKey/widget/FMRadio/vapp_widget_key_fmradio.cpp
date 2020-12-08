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
 *  vapp_widget_key_fmradio.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_KEY_FM_RADIO__)
#include "vapp_widget_key_fmradio.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h" 
#include "vfx_class_info.h"
#include "vfx_control.h"
#include "vfx_datatype.h"
#include "vfx_input_event.h"
#include "vfx_primitive_frame.h"
#include "vfx_basic_type.h"
#include "vfx_signal.h"
#include "vfx_frame.h" 
#include "vfx_draw_context.h"
#include "vrt_system.h"
#include "vfx_string.h"
#include "vfx_timer.h"
#include "vfx_weak_ptr.h"
#include "vfx_renderer.h"
#include "vrt_canvas.h"
#include "vrt_datatype.h"
#include "vfx_system.h"
#include "Vfx_font_desc.h"
#include "vapp_widget_native_factory.h"
#include "../app/common/widget/vapp_widget_def.h"
#include "mmi_rp_app_venus_key_wg_fmradio_def.h"
#include "fmr_config_customize.h"


/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
#include "ConnectivityResDef.h"
#ifdef __MMI_USB_SUPPORT__
 #include "USBSrvGProt.h"
#endif
#include "gui_touch_feedback.h"
#include "gui_typedef.h"
#if !defined(__COSMOS_MMI__)
#include "mmi_rp_app_usbmmi_def.h"
#endif

#include "MMIDataType.h"
#include "kal_trace.h"
#include "GlobalResDef.h"
#include "FMradioprot.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "med_api.h"
#include "kal_general_types.h"
#include "mmi_common_app_trc.h"

enum
{
	STATE_POWER_OFF,
	STATE_POWER_ON,
	STATE_SEARCHING
};

enum
{
    BUTTON_ARROW_UP,
    BUTTON_ARROW_DOWN,
    BUTTON_POWER
};
#define MIN_FM_FREQ FM_RADIO_MIN_FREQ
#define MAX_FM_FREQ FM_RADIO_MAX_FREQ

void mmi_key_fmrdo_register_callback(void* userdata, void (*search_callback)(const void*, VfxU16), void (*poweroff_callback)(const void*, VfxU32))
{
    fmrdo_srv_callback_struct callback_fmr;
    callback_fmr.user_data = userdata;
    callback_fmr.preemped_callback = poweroff_callback;
    callback_fmr.search_callback = search_callback;
    mmi_fmrdo_srv_set_callback((const fmrdo_srv_callback_struct*)&callback_fmr);
}

void mmi_key_fmrdo_deregister_callback(void* userdata)
{
    fmrdo_srv_callback_struct callback_fmr = {userdata, NULL, NULL};
    mmi_fmrdo_srv_stop_search();
    mmi_fmrdo_srv_set_callback((const fmrdo_srv_callback_struct*)&callback_fmr);
}

VfxU16 mmi_key_fmrdo_get_state(void)
{
    if(!mmi_fmrdo_srv_get_power_on_off_state())
    {
        return STATE_POWER_OFF;
    }
    else
    {
        return STATE_POWER_ON;
    }
}

void mmi_key_fmrdo_set_power_on(VfxBool is_power_on)
{
    if(is_power_on)
    {
        /*do power on*/
        mmi_fmrdo_srv_power_on_by_others(APP_FTE_WIDGET, KAL_TRUE);
    }
    else
    {
        /* do power off */
        mmi_fmrdo_srv_power_on_by_others(APP_FTE_WIDGET, KAL_FALSE);
    }    
}

void mmi_key_fmrdo_get_cur_frequency(VfxU16 *frequency)
{
   mmi_fmrdo_srv_get_cur_frequency(frequency);
}

void mmi_key_fmrdo_set_cur_frequency(VfxU16 frequency)
{
    mmi_fmrdo_srv_set_frequency(frequency);
}


void mmi_key_fmrdo_search_next_frequency(VfxU16 freq, VfxBool is_search_next)
{
    if(is_search_next)
    {/* Yaling todo check input */
        mmi_fmrdo_srv_search_next(freq, KAL_TRUE);
    }
    else
    {
        mmi_fmrdo_srv_search_next(freq, KAL_FALSE);
    }
}

#ifdef __cplusplus
}
#endif


#ifdef __MMI_MAINLCD_320X480__

#define VAPP_WG_KEY_FM_COVER_WIDTH  (249)
#define VAPP_WG_KEY_FM_COVER_HEIGHT  (210)
#define VAPP_WG_KEY_FM_LARGE_FONT (36)
#define VAPP_WG_KEY_FM_SMALE_FONT (12)
#define VAPP_WG_KEY_FM_HOLE_X  (3)
#define VAPP_WG_KEY_FM_HOLE_Y  (1)
#define VAPP_WG_KEY_FM_HOLE_WIDTH  (187)
#define VAPP_WG_KEY_FM_HOLE_HEIGHT  (199)
#define VAPP_WG_KEY_FM_NAME_X  (10)
#define VAPP_WG_KEY_FM_NAME_Y  (61)
#define VAPP_WG_KEY_FM_SEARCH_X  (13)
#define VAPP_WG_KEY_FM_SEARCH_Y  (61+34+43)

#define VAPP_WG_KEY_FM_BUT_PREV_X  (187 + 11 + 3)
#define VAPP_WG_KEY_FM_BUT_PREV_Y  (29)

#define VAPP_WG_KEY_FM_BUT_PREV_WIDTH   (24)
#define VAPP_WG_KEY_FM_BUT_PREV_HEIGHT  (24)

#define VAPP_WG_KEY_FM_BUT_NEXT_X  (187 + 11 + 3)
#define VAPP_WG_KEY_FM_BUT_NEXT_Y  (29+24+29+42+29)

#define VAPP_WG_KEY_FM_BUT_POWER_X  (187 + 4 + 3)
#define VAPP_WG_KEY_FM_BUT_POWER_Y  (29+24+29)
#define VAPP_WG_KEY_FM_BUT_POWER_WIDTH   (42)
#define VAPP_WG_KEY_FM_BUT_POWER_HEIGHT  (42)

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)

#define VAPP_WG_KEY_FM_COVER_WIDTH  (189)
#define VAPP_WG_KEY_FM_COVER_HEIGHT  (159)
#define VAPP_WG_KEY_FM_LARGE_FONT (27)
#define VAPP_WG_KEY_FM_SMALE_FONT (9)
#define VAPP_WG_KEY_FM_HOLE_X  (2)
#define VAPP_WG_KEY_FM_HOLE_Y  (1)
#define VAPP_WG_KEY_FM_HOLE_WIDTH  (141)
#define VAPP_WG_KEY_FM_HOLE_HEIGHT  (150)
#define VAPP_WG_KEY_FM_NAME_X  (8 - 3)
#define VAPP_WG_KEY_FM_NAME_Y  (47)
#define VAPP_WG_KEY_FM_SEARCH_X  (11)
#define VAPP_WG_KEY_FM_SEARCH_Y  (105)

#define VAPP_WG_KEY_FM_BUT_PREV_X  (153)
#define VAPP_WG_KEY_FM_BUT_PREV_Y  (17)

#define VAPP_WG_KEY_FM_BUT_PREV_WIDTH   (21)
#define VAPP_WG_KEY_FM_BUT_PREV_HEIGHT  (18)

#define VAPP_WG_KEY_FM_BUT_NEXT_X  (153)
#define VAPP_WG_KEY_FM_BUT_NEXT_Y  (17+18+22+32+22)

#define VAPP_WG_KEY_FM_BUT_POWER_X  (147)
#define VAPP_WG_KEY_FM_BUT_POWER_Y  (17+18+22)
#define VAPP_WG_KEY_FM_BUT_POWER_WIDTH   (32)
#define VAPP_WG_KEY_FM_BUT_POWER_HEIGHT  (32)

#elif defined(__MMI_MAINLCD_320X240__)
#define VAPP_WG_KEY_FM_COVER_WIDTH  (206)
#define VAPP_WG_KEY_FM_COVER_HEIGHT  (132)
#define VAPP_WG_KEY_FM_LARGE_FONT (27)
#define VAPP_WG_KEY_FM_SMALE_FONT (9)

#define VAPP_WG_KEY_FM_HOLE_X  (2)
#define VAPP_WG_KEY_FM_HOLE_Y  (0)
#define VAPP_WG_KEY_FM_HOLE_WIDTH  (158)
#define VAPP_WG_KEY_FM_HOLE_HEIGHT  (132)
#define VAPP_WG_KEY_FM_NAME_X  (23)
#define VAPP_WG_KEY_FM_NAME_Y  (38)
#define VAPP_WG_KEY_FM_SEARCH_X  (19)
#define VAPP_WG_KEY_FM_SEARCH_Y  (86)

#define VAPP_WG_KEY_FM_BUT_PREV_X  (158+10)
#define VAPP_WG_KEY_FM_BUT_PREV_Y  (18)

#define VAPP_WG_KEY_FM_BUT_PREV_WIDTH   (20)
#define VAPP_WG_KEY_FM_BUT_PREV_HEIGHT  (18)

#define VAPP_WG_KEY_FM_BUT_NEXT_X  (158 + 10)
#define VAPP_WG_KEY_FM_BUT_NEXT_Y  (18+18+12+32+12)

#define VAPP_WG_KEY_FM_BUT_POWER_X  (158 + 4)
#define VAPP_WG_KEY_FM_BUT_POWER_Y  (18+18+12)
#define VAPP_WG_KEY_FM_BUT_POWER_WIDTH   (32)
#define VAPP_WG_KEY_FM_BUT_POWER_HEIGHT  (32)
#endif

/*****************************************************************************
 * Class VappWidgetKeyFMRadioPanel
 *****************************************************************************/
VappWidgetKeyFMRadioButton::VappWidgetKeyFMRadioButton():m_Image(NULL)
{

}

VappWidgetKeyFMRadioButton::~VappWidgetKeyFMRadioButton()
{

}

void VappWidgetKeyFMRadioButton::onInit()
{
    VfxControl::onInit();
    VFX_OBJ_CREATE(m_Image, VfxImageFrame, this);
}

void VappWidgetKeyFMRadioButton::onDeinit()
{
    VfxControl::onDeinit();
}


VfxBool VappWidgetKeyFMRadioButton::isContains(VfxPoint pos, VfxU16 type)
{
    VfxBool ret = VFX_FALSE;
    
    if(type == BUTTON_ARROW_DOWN)
    {
        vrt_s32 xInRect = pos.x - VAPP_WG_KEY_FM_BUT_NEXT_X;
        vrt_s32 yInRect = pos.y - VAPP_WG_KEY_FM_BUT_NEXT_Y;

        ret = xInRect >= 0 && xInRect < VAPP_WG_KEY_FM_BUT_PREV_WIDTH && yInRect >= 0 && yInRect < VAPP_WG_KEY_FM_BUT_PREV_WIDTH;
    }
    else if(type == BUTTON_ARROW_UP)
    {
        vrt_s32 xInRect = pos.x - VAPP_WG_KEY_FM_BUT_PREV_X;
        vrt_s32 yInRect = pos.y - VAPP_WG_KEY_FM_BUT_PREV_Y;
        ret = xInRect >= 0 && xInRect < VAPP_WG_KEY_FM_BUT_PREV_WIDTH && yInRect >= 0 && yInRect < VAPP_WG_KEY_FM_BUT_PREV_WIDTH;
    }
    else if(type == BUTTON_POWER)
    {
        vrt_s32 xInRect = pos.x - VAPP_WG_KEY_FM_BUT_POWER_X;
        vrt_s32 yInRect = pos.y - VAPP_WG_KEY_FM_BUT_POWER_Y;
        ret = xInRect >= 0 && xInRect < VAPP_WG_KEY_FM_BUT_POWER_WIDTH &&  yInRect >= 0 && yInRect < VAPP_WG_KEY_FM_BUT_POWER_WIDTH;
    }    
    return ret;
}


void VappWidgetKeyFMRadioButton::setImage(VfxS32 imageid)
{
    if(m_Image->getResId() != imageid)
    {
        m_Image->setResId(imageid);
    }
    setBounds(m_Image->getBounds());
}


/*****************************************************************************
 * Class VappWidgetKeyFMRadioPanel
 *****************************************************************************/
VappWidgetKeyFMRadioPanel::VappWidgetKeyFMRadioPanel():
m_ImageBg(NULL),
m_ImageHole(NULL),
m_Power(NULL),
m_ButPrev(NULL),
m_ButNext(NULL),
m_Searching(NULL),
m_IsSearching(VFX_FALSE),
m_IsTimerStart(VFX_FALSE),
m_IsLTimerStart(VFX_FALSE),
m_IsLPrev(VFX_FALSE),
m_IsLNext(VFX_FALSE),
m_IsButPower(VFX_FALSE),
m_IsButPrev(VFX_FALSE),
m_IsButNext(VFX_FALSE),
m_IsPrevPressing(VFX_FALSE),
m_IsNextPressing(VFX_FALSE),
m_IsPowerPressing(VFX_FALSE),
m_Timer(NULL),
m_State(STATE_POWER_OFF),
m_CurFrequency(MIN_FM_FREQ),
m_FMRadioName(NULL),
m_Effect(NULL)
{

}

VappWidgetKeyFMRadioPanel::~VappWidgetKeyFMRadioPanel()
{

}

VfxU16 VappWidgetKeyFMRadioPanel::getState()
{    
    m_State = mmi_key_fmrdo_get_state();
    VFX_LOG(VFX_INFO2, TRC_VAPP_KEY_WG_FM_GET_STATE, m_State);
    return m_State;
}

void VappWidgetKeyFMRadioPanel::onTimerClick(VfxTimer *timer)
{
    VFX_UNUSED(timer);
    if(m_Searching->getResId() != VAPP_KL_WG_FM_SEARCH_LOADING_1)
    {
        m_Searching->setResId(VAPP_KL_WG_FM_SEARCH_LOADING_1);
    }
    else
    {
        m_Searching->setResId(VAPP_KL_WG_FM_SEARCH_LOADING_2);
    }
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->mustShowNextFrame();
}

void VappWidgetKeyFMRadioPanel::startCurTimer(void)
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_KEY_WG_FM_STARTCT, m_IsTimerStart);
    if(!m_IsTimerStart)
    {
        m_Timer->setStartDelay(100);
        m_Timer->setDuration(100);
        m_Timer->start();
        m_IsTimerStart = VFX_TRUE;
    }
}

void VappWidgetKeyFMRadioPanel::stopCurTimer(void)
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_KEY_WG_FM_STOPCT,m_IsTimerStart);
    if(m_IsTimerStart)
    {
        m_Timer->stop();
        m_IsTimerStart = VFX_FALSE;
    } 
}


void VappWidgetKeyFMRadioPanel::onLTimerClick(VfxTimer * timer)
{
    VFX_UNUSED(timer);
    VFX_LOG(VFX_INFO2, TRC_VAPP_KEY_WG_FM_LTIMERTICK,m_IsLNext, m_IsLPrev, m_IsLTimerStart);
    if(m_IsLNext)
    {
        if(m_CurFrequency < MAX_FM_FREQ)
        {
            m_CurFrequency++;
        }
        else
        {
            m_CurFrequency = MIN_FM_FREQ;
        }
    }
    else if(m_IsLPrev)
    {
        if(m_CurFrequency > MIN_FM_FREQ)
        {
            m_CurFrequency--;
        }
        else
        {
            m_CurFrequency = MAX_FM_FREQ;
        }        
    }
    
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->mustShowNextFrame();
    
    updateDisplay();
}

void VappWidgetKeyFMRadioPanel::startLTimer(void)
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_KEY_WG_FM_STARTLCT, m_IsLTimerStart);
    
    if(m_State == STATE_POWER_ON && !m_IsLTimerStart)
    {
        m_LTimer->setStartDelay(100);
        m_LTimer->setDuration(1000);
        m_LTimer->start();
        m_IsLTimerStart = VFX_TRUE;
    }

}

void VappWidgetKeyFMRadioPanel::stopLTimer(void)
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_KEY_WG_FM_STOPLCT, m_IsLTimerStart);

    if(m_IsLTimerStart)
    {
        m_LTimer->stop();
        m_IsLTimerStart = VFX_FALSE;
    } 
}

void VappWidgetKeyFMRadioPanel::resetSearchImage(void)
{
    m_Searching->setResId(VAPP_KL_WG_FM_SEARCH);
}

void VappWidgetKeyFMRadioPanel::fmRadioSearchCallback(const void *user_data, VfxU16 result)
{
    VappWidgetKeyFMRadioPanel  *this_ptr = (VappWidgetKeyFMRadioPanel*)user_data;

    VFX_LOG(VFX_INFO2, TRC_VAPP_KEY_WG_FM_SEARCH_CALLBACK);
     
    this_ptr->stopCurTimer();
    this_ptr->getCurFreq();
    this_ptr->resetSearchImage();
    this_ptr->updateDisplay();
}

void VappWidgetKeyFMRadioPanel::fmRadioPowerCallback(const void *user_data, VfxU32 result)
{
    VappWidgetKeyFMRadioPanel  *this_ptr = (VappWidgetKeyFMRadioPanel*)user_data;
    
    VFX_LOG(VFX_INFO2, TRC_VAPP_KEY_WG_FM_POWER_CALLBACK);
    
    this_ptr->stopCurTimer();
    this_ptr->updateDisplay();
}

VfxU16 VappWidgetKeyFMRadioPanel::getCurFreq(void)
{
    mmi_key_fmrdo_get_cur_frequency(&m_CurFrequency);
    VFX_LOG(VFX_INFO2, TRC_VAPP_KEY_WG_FM_GET_FREG, m_CurFrequency);
    if(!m_CurFrequency)
    {
        m_CurFrequency = MIN_FM_FREQ;
    }
    return m_CurFrequency;
}

void VappWidgetKeyFMRadioPanel::setFreq(VfxU16 freq)
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_KEY_WG_FM_SET_FREG, freq);
    mmi_key_fmrdo_set_cur_frequency(freq);    
}


void VappWidgetKeyFMRadioPanel::getFreqString(VfxU16 freq, VfxWChar *timeStr,VfxU32 maxLength) const
{
    VfxU16 int_freq;
    VfxU16 int_freq_remain;
    VfxU16 dot_freq;

    #define STRING_LENGTH_MAX (10)
    VfxChar *temp;    
    VfxU32 wtemp_length;    
    VfxChar temp_string[STRING_LENGTH_MAX];
    VfxWChar temp_wstring[STRING_LENGTH_MAX];
    VfxChar dot;

    dot = '.';
    
    int_freq = freq / 10;
    dot_freq = freq % 10; 

    temp = &temp_string[0];

    int_freq_remain = freq/1000;

    if(int_freq_remain)
    {
        sprintf(temp, "%03d%c%01d",  int_freq, dot, dot_freq);
        *(temp + 5) = '\0';
    }
    else
    {
        sprintf(temp, "%02d%c%01d",  int_freq, dot, dot_freq);
        *(temp + 4) = '\0';
    } 

    wtemp_length = vfx_sys_strlen(temp_string);
    VFX_ASSERT(wtemp_length<STRING_LENGTH_MAX);
    mmi_asc_n_to_ucs2((CHAR*)temp_wstring, (CHAR*)temp_string, wtemp_length + 1);

    if (maxLength < wtemp_length)
    {
        return;
    }

    vfx_sys_wcscpy(timeStr, temp_wstring);

}


void VappWidgetKeyFMRadioPanel::updateDisplay(void)
{
    VfxWString temp_title1, temp_title2;    

    getState();
    if(m_State == STATE_POWER_OFF)
    {
        m_ImageHole->setResId(VAPP_KL_WG_FM_BG_TURNOFF);
        if(m_IsPowerPressing)
        {
            m_Power->setImage(VAPP_KL_WG_FM_POWEROFF_DOWN);
        }
        else
        {
            m_Power->setImage(VAPP_KL_WG_FM_POWEROFF);
        }
        m_ButPrev->setImage(VAPP_KL_WG_FM_ARROW_UP_TURNOFF);
        m_ButNext->setImage(VAPP_KL_WG_FM_ARROW_DOWN_TURNOFF);
	m_Searching->setResId(VAPP_KL_WG_FM_SEARCH);
    }
    else
    {
        m_ImageHole->setResId(VAPP_KL_WG_FM_BG_TURNON);
        if(m_IsPowerPressing)
        {
            m_Power->setImage(VAPP_KL_WG_FM_POWERON_DOWN);
        }
        else
        {
            m_Power->setImage(VAPP_KL_WG_FM_POWERON);
        }
        if(m_IsPrevPressing)
        {
            m_ButPrev->setImage(VAPP_KL_WG_FM_ARROW_UP_SELECT);
        }
        else
        {
            m_ButPrev->setImage(VAPP_KL_WG_FM_ARROW_UP_TURNON);
        }
        if(m_IsNextPressing)
        {
            m_ButNext->setImage(VAPP_KL_WG_FM_ARROW_DOWN_SELECT);
        }
        else
        {
            m_ButNext->setImage(VAPP_KL_WG_FM_ARROW_DOWN_TURNON);
        }
    }
    m_Effect->setType(VFX_FONT_EFFECT_ENHANCED_BORDER);
    m_Effect->setEnhancedBorder(VfxColor(255, 0, 0, 0), 2, 40);

    VfxFontDesc fontDesc;
    fontDesc.effect = m_Effect->getEffectId();    
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_WG_KEY_FM_LARGE_FONT);
    temp_title1 = VFX_WSTR("FM");
    m_FMRadioName->setString(temp_title1);
    m_FMRadioName->setFont(fontDesc);

    VfxPoint pos;
    pos.x = m_FMRadioName->getBounds().getWidth() + VAPP_WG_KEY_FM_NAME_X;
    pos.y = VAPP_WG_KEY_FM_NAME_Y;

    VfxWChar str_buf[10];
    getFreqString(m_CurFrequency, str_buf,10);
    m_FMRadioChannel->setString(VFX_WSTR_MEM(str_buf));
    m_FMRadioChannel->setFont(fontDesc);
    m_FMRadioChannel->setPos(pos);

    temp_title2 = VFX_WSTR("MHz");
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_WG_KEY_FM_SMALE_FONT);
    m_FMRadioMHZ->setString(temp_title2);
    m_FMRadioMHZ->setFont(fontDesc);
    pos.x = pos.x + m_FMRadioChannel->getBounds().getWidth() + 2;
    pos.y = VAPP_WG_KEY_FM_NAME_Y+ (m_FMRadioChannel->getBounds().getHeight() - m_FMRadioMHZ->getBounds().getHeight());
    m_FMRadioMHZ->setPos(pos);
   
}

void VappWidgetKeyFMRadioPanel::onPowerOn(VfxKeyEvent &event)
{
    stopCurTimer();
    stopLTimer();
    mmi_key_fmrdo_set_power_on(VFX_TRUE);
}


void VappWidgetKeyFMRadioPanel::onPowerOff(VfxKeyEvent &event)
{
    stopCurTimer();
    stopLTimer();
    mmi_key_fmrdo_set_power_on(VFX_FALSE);
}

void VappWidgetKeyFMRadioPanel::switchPrev(VfxKeyEvent & event)
{
    stopCurTimer();
    if(m_State == STATE_POWER_ON && event.type == VFX_KEY_EVENT_TYPE_UP)
    {
        mmi_key_fmrdo_search_next_frequency(m_CurFrequency, VFX_FALSE);
        startCurTimer();
    }
}

void VappWidgetKeyFMRadioPanel::switchNext(VfxKeyEvent & event)
{
    stopCurTimer();
    if(m_State == STATE_POWER_ON && event.type == VFX_KEY_EVENT_TYPE_UP)
    {
        mmi_key_fmrdo_search_next_frequency(m_CurFrequency, VFX_TRUE);
        startCurTimer();
    } 
}
 
void VappWidgetKeyFMRadioPanel::onButtonUp(VfxObjWeakPtr this_ptr)
{
    if(this_ptr != NULL)
    {
        updateDisplay();
    }
}
 
 VfxBool VappWidgetKeyFMRadioPanel::onKeyInput(VfxKeyEvent & event)
 { 
     VFX_LOG(VFX_INFO2,TRC_VAPP_KEY_WG_FM_KEY_TYPE ,event.type, event.keyCode,m_State, m_IsLNext, m_IsLPrev);
     if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
     {     
         m_IsLNext = VFX_FALSE;
         m_IsLPrev = VFX_FALSE;
         stopLTimer();
         switch(event.keyCode)
         {
         case VFX_KEY_CODE_ARROW_UP:
            mmi_fmrdo_srv_stop_search();
            if(m_State == STATE_POWER_ON)
            {
                m_IsPrevPressing = VFX_TRUE;
                switchPrev(event);
                updateDisplay();
                return VFX_TRUE;
            }
            break;
         case VFX_KEY_CODE_CSK:
            mmi_fmrdo_srv_stop_search();                                  
            m_IsPowerPressing = VFX_TRUE;
            updateDisplay();
             return VFX_TRUE;
         case VFX_KEY_CODE_ARROW_DOWN:
            mmi_fmrdo_srv_stop_search();            
            if(m_State == STATE_POWER_ON)
            {
                m_IsNextPressing = VFX_TRUE;
                updateDisplay();
                switchNext(event);
                return VFX_TRUE;
            }
            break;
         default:
             break;
          }
     }
     else if(event.type == VFX_KEY_EVENT_TYPE_LONG_PRESS)
     {     
     VFX_TRACE(("\nyaling on key input long press"));
         if(!m_IsPrevPressing && !m_IsPowerPressing && !m_IsNextPressing)
         {
            return VfxControl::onKeyInput(event);
         }
         switch(event.keyCode)
         {
         case VFX_KEY_CODE_ARROW_UP:
             stopLTimer();
             if(m_State == STATE_POWER_ON)
             {
                 m_IsLPrev = VFX_TRUE;
                 m_IsLNext = VFX_FALSE;
                 startLTimer();
                 return VFX_TRUE;
             }
             break;
         case VFX_KEY_CODE_ARROW_DOWN:
             stopLTimer();
            if(m_State == STATE_POWER_ON)
            {
                 m_IsLNext = VFX_TRUE;
                 m_IsLPrev = VFX_FALSE;
                 startLTimer();
                 return VFX_TRUE;
            }
            break;
         default:
             m_IsLNext = VFX_FALSE;
             m_IsLPrev = VFX_FALSE;
             stopLTimer();
             break;
         }
     }
     else if (event.type == VFX_KEY_EVENT_TYPE_UP)
     {
         VFX_TRACE(("\nyaling onkeyinput up\n"));
         VfxObjWeakPtr this_ptr = this;
         if(!m_IsPrevPressing && !m_IsPowerPressing && !m_IsNextPressing)
         {
            return VfxControl::onKeyInput(event);
         }
         m_IsPrevPressing = VFX_FALSE;
         m_IsNextPressing = VFX_FALSE;
         m_IsPowerPressing = VFX_FALSE;
         stopLTimer();
         if(m_IsLNext || m_IsLPrev)
         {         
             m_IsLNext = VFX_FALSE;
             m_IsLPrev = VFX_FALSE;
             if(m_State == STATE_POWER_ON)
             {
                 setFreq(m_CurFrequency);
             }
             onButtonUp(this_ptr);
         }
         else
         {
             switch(event.keyCode)
             {
             case VFX_KEY_CODE_ARROW_UP:
                 switchPrev(event);
                 onButtonUp(this_ptr);
                 return VFX_TRUE;
             case VFX_KEY_CODE_CSK:
                if(m_State == STATE_POWER_ON)
                {
                    onPowerOff(event);
                }
                else
                {
                    onPowerOn(event);
                }
                 onButtonUp(this_ptr);
                 return VFX_TRUE;
             case VFX_KEY_CODE_ARROW_DOWN:
                 switchNext(event);
                 onButtonUp(this_ptr);
                 return VFX_TRUE;
             default:
                 break;
             }
         }
     }    
    return VfxControl::onKeyInput(event);
 }
 
 
 VfxBool VappWidgetKeyFMRadioPanel::onPenInput(VfxPenEvent & event)
 {
     VfxBool ret = VFX_FALSE;
     VfxSize distance;
     VfxPoint pos(event.getRelPos(this));
     VfxObjWeakPtr this_ptr = this;
     VFX_LOG(VFX_INFO2, TRC_VAPP_KEY_WG_FM_PEN_TYPE,event.type,m_State, m_IsButNext,m_IsButPrev, m_IsButPower);
     switch(event.type)       
     {
     case  VFX_PEN_EVENT_TYPE_DOWN:         
         if (m_State != STATE_POWER_OFF && m_ButPrev->isContains(pos, BUTTON_ARROW_UP))
         {
             m_IsButPrev = VFX_TRUE;
             m_IsButNext = VFX_FALSE;
             m_IsButPower = VFX_FALSE;
             m_IsPrevPressing = VFX_TRUE;
             updateDisplay();
             mmi_fmrdo_srv_stop_search();
             ret = MMI_TRUE;
             return ret;
         }
         else if(m_ButNext->isContains(pos, BUTTON_ARROW_DOWN))
         {
             m_IsButNext = VFX_TRUE;
             m_IsButPrev = VFX_FALSE;
             m_IsButPower = VFX_FALSE;
             m_IsNextPressing = VFX_TRUE;
             updateDisplay();
             mmi_fmrdo_srv_stop_search();
             ret = VFX_TRUE;
             return ret;
         }              
         else if(m_Power->isContains(pos, BUTTON_POWER))
         {
             m_IsButPower = VFX_TRUE;
             m_IsButNext = VFX_FALSE;
             m_IsButPrev = VFX_FALSE;
             m_IsPowerPressing = VFX_TRUE;
             updateDisplay();
             mmi_fmrdo_srv_stop_search();
             ret = VFX_TRUE;
             return ret;
         }
         break;
     case VFX_PEN_EVENT_TYPE_LONG_TAP:
        VFX_TRACE(("\nyaling on pen input long tap\n"));
        if(m_IsButPrev)
        {
            m_IsLPrev = VFX_TRUE;
            m_IsLNext = VFX_FALSE;
            m_IsButPrev = VFX_FALSE;
            m_IsButNext = VFX_FALSE;
            m_IsButPower = VFX_FALSE;
            m_IsPrevPressing = VFX_TRUE;
            startLTimer();
            return VFX_TRUE;
        }
        else if(m_IsButNext)
        {
            m_IsLPrev = VFX_FALSE;
            m_IsLNext = VFX_TRUE; 
            m_IsButPrev = VFX_FALSE;
            m_IsButNext = VFX_FALSE;
            m_IsButPower = VFX_FALSE;
            m_IsNextPressing = VFX_TRUE;
            startLTimer();
            return VFX_TRUE;
        };
        break;
        
     case VFX_PEN_EVENT_TYPE_MOVE:         
         VFX_TRACE(("\nyaling on pen input move\n"));
         if(m_IsButPrev || m_IsPrevPressing)
         {
            if(!(m_ButPrev->isContains(pos, BUTTON_ARROW_UP)))
            {
                if(m_IsLPrev)  
                {
                    setFreq(m_CurFrequency);
                    m_IsLPrev = MMI_FALSE;
                }
                m_IsButPrev = VFX_FALSE;
                m_IsPrevPressing = VFX_FALSE;
                stopLTimer();
                onButtonUp(this_ptr);
            }
         }
         else if(m_IsButNext || m_IsNextPressing)
         {
             if(!(m_ButNext->isContains(pos, BUTTON_ARROW_DOWN)))
             {
                 if(m_IsLNext)  
                 {
                     setFreq(m_CurFrequency);
                     m_IsLNext = MMI_FALSE;				
                 }
                 m_IsButNext = VFX_FALSE;
                 m_IsNextPressing = VFX_FALSE;
                 stopLTimer();
                 onButtonUp(this_ptr);
             }
         }
         else if(m_IsButPower)
         {
             if(!(m_Power->isContains(pos,BUTTON_POWER)))
             {
                 m_IsPowerPressing = VFX_FALSE;
                 stopLTimer();
             }
             else if(m_Power->isContains(pos,BUTTON_POWER))
             {
		 m_IsPowerPressing = VFX_TRUE;
	         m_IsButPower = VFX_TRUE;	 
             }
             onButtonUp(this_ptr);           
         }
         ret = VFX_TRUE;
         return ret;

 
     case VFX_PEN_EVENT_TYPE_UP:        
        VFX_TRACE(("\nyaling on pen input up\n"));
         stopLTimer();
         if (m_IsButNext)
         {
             VfxKeyEvent event;
             event.type = VFX_KEY_EVENT_TYPE_DOWN;
             switchNext(event);
             event.type = VFX_KEY_EVENT_TYPE_UP;
             switchNext(event);            
             m_IsNextPressing = VFX_FALSE;
             m_IsButNext = VFX_FALSE;
             ret = VFX_TRUE;
             onButtonUp(this_ptr);
             return ret;
         }
         else if(m_IsButPrev)
         {
             VfxKeyEvent  event;
             event.type = VFX_KEY_EVENT_TYPE_DOWN;
             switchPrev(event);
             event.type = VFX_KEY_EVENT_TYPE_UP;
             switchPrev(event);      
             m_IsPrevPressing = VFX_FALSE;
             m_IsButPrev = VFX_FALSE;
             onButtonUp(this_ptr);
             return VFX_TRUE;
         }
         else if(m_IsButPower)
         {
             m_IsPowerPressing = VFX_FALSE;
             m_IsButPower = VFX_FALSE;
             if(m_State == STATE_POWER_OFF)
             {
                VfxKeyEvent  event;
                event.type = VFX_KEY_EVENT_TYPE_UP;
                onPowerOn(event);
             }
             else
             {
                VfxKeyEvent  event;
                event.type = VFX_KEY_EVENT_TYPE_UP;
                onPowerOff(event);
             }
             onButtonUp(this_ptr);
             return VFX_TRUE;
         }
         else if(m_IsLNext || m_IsLPrev)
         {
            m_IsPrevPressing = VFX_FALSE;
            m_IsNextPressing = VFX_FALSE;
            setFreq(m_CurFrequency);
            onButtonUp(this_ptr);
            return VFX_TRUE;
         }
        break;
     case VFX_PEN_EVENT_TYPE_ABORT:
         VFX_TRACE(("\nyaling on pen input abort\n"));
         m_IsButNext = VFX_FALSE;
         m_IsButPrev = VFX_FALSE;
         m_IsButPower = VFX_FALSE;
         m_IsNextPressing = VFX_FALSE;
         m_IsPrevPressing = VFX_FALSE;
         m_IsPowerPressing = VFX_FALSE;
         updateDisplay();
         return VFX_TRUE;
     }
    return VFX_TRUE;
}


void VappWidgetKeyFMRadioPanel::onInit()
{
    VfxControl::onInit();
    setFocused(VFX_TRUE);
    VFX_OBJ_CREATE(m_ImageBg, VfxImageFrame, this);
    m_ImageBg->setResId(VAPP_KL_WG_FM_BACKGROUND);
    setBounds(m_ImageBg->getBounds());

    VFX_OBJ_CREATE(m_ImageHole, VfxImageFrame, this);
    m_ImageHole->setResId(VAPP_KL_WG_FM_BG_TURNOFF);
    m_ImageHole->setPos(VAPP_WG_KEY_FM_HOLE_X,VAPP_WG_KEY_FM_HOLE_Y);

    VFX_OBJ_CREATE(m_Power, VappWidgetKeyFMRadioButton, this);
    m_Power->setImage(VAPP_KL_WG_FM_POWERON);    
    m_Power->setPos(VAPP_WG_KEY_FM_BUT_POWER_X, VAPP_WG_KEY_FM_BUT_POWER_Y);

    VFX_OBJ_CREATE(m_ButPrev, VappWidgetKeyFMRadioButton, this);
    m_ButPrev->setImage(VAPP_KL_WG_FM_ARROW_DOWN_TURNOFF);    
    m_ButPrev->setPos(VAPP_WG_KEY_FM_BUT_PREV_X, VAPP_WG_KEY_FM_BUT_PREV_Y);

    VFX_OBJ_CREATE(m_ButNext, VappWidgetKeyFMRadioButton, this);
    m_ButNext->setImage(VAPP_KL_WG_FM_ARROW_DOWN_TURNOFF);    
    m_ButNext->setPos(VAPP_WG_KEY_FM_BUT_NEXT_X, VAPP_WG_KEY_FM_BUT_NEXT_Y);

    VFX_OBJ_CREATE(m_Searching, VfxImageFrame, this);
    m_Searching->setResId(VAPP_KL_WG_FM_SEARCH);
    m_Searching->setPos(VAPP_WG_KEY_FM_SEARCH_X,VAPP_WG_KEY_FM_SEARCH_Y);


    VFX_OBJ_CREATE(m_FMRadioName, VfxTextFrame, this);
    m_FMRadioName->setPos(VAPP_WG_KEY_FM_NAME_X, VAPP_WG_KEY_FM_NAME_Y);

    VFX_OBJ_CREATE(m_FMRadioChannel, VfxTextFrame, this);
    VFX_OBJ_CREATE(m_FMRadioMHZ, VfxTextFrame, this);
    
    VFX_OBJ_CREATE(m_Timer, VfxTimer, this);
    m_Timer->m_signalTick.connect(this, &VappWidgetKeyFMRadioPanel::onTimerClick);

    VFX_OBJ_CREATE(m_LTimer, VfxTimer, this);
    m_LTimer->m_signalTick.connect(this, &VappWidgetKeyFMRadioPanel::onLTimerClick);
   
    VFX_ALLOC_NEW(m_Effect, VfxFontEffect, this);
    getCurFreq();
    updateDisplay();

    mmi_key_fmrdo_register_callback((void*)this, fmRadioSearchCallback, fmRadioPowerCallback);
}

void VappWidgetKeyFMRadioPanel::onDeinit()
{    
    mmi_key_fmrdo_deregister_callback((void*)this);
    VFX_DELETE(m_Effect);
    if(m_IsLNext || m_IsLPrev)
    {
        setFreq(m_CurFrequency);
    }
    setFocused(VFX_FALSE);
    stopCurTimer();
    stopLTimer();
    m_Timer->m_signalTick.disconnect(this, &VappWidgetKeyFMRadioPanel::onTimerClick);
    m_LTimer->m_signalTick.disconnect(this, &VappWidgetKeyFMRadioPanel::onLTimerClick);

    VfxControl::onDeinit();
}
 
 
VAPP_WIDGET_SYS_PUBLISH_NATIVE(
    VappWidgetKeyFMRadio,
    VAPP_WIDGET_TYPE_KEY_FMRADIO,
    VappWidgetKeyFMRadioPublisher);

VAPP_WIDGET_IMPLEMENT_CLASS(VappWidgetKeyFMRadio, VappWidget);

/*****************************************************************************
 * Class VappKLWidgetMusicPlayer
 *****************************************************************************/
VappWidgetKeyFMRadio::VappWidgetKeyFMRadio(): m_Panel(NULL)
{

}


VappWidgetId VappWidgetKeyFMRadio::getId() const
{
    return VappWidgetId(VAPP_WIDGET_SRC_NATIVE, VAPP_WIDGET_TYPE_KEY_FMRADIO);
}


VfxSize VappWidgetKeyFMRadio::getMaxSize() const
{
    return VfxSize(VAPP_WG_KEY_FM_COVER_WIDTH, VAPP_WG_KEY_FM_COVER_HEIGHT);
}


VfxS32 VappWidgetKeyFMRadio::getName(VfxWChar *string, VfxS32 size) const
{
    const VfxWChar *str = vfxSysResGetStr(VAPP_WIDGET_KEY_STR_FM);

    VFX_ASSERT(string && size > 0);

    mmi_wcsncpy((WCHAR *)string, (const WCHAR *)str, size - 1);

    return vfx_sys_wcslen(string);
}


VfxFrame *VappWidgetKeyFMRadio::createIcon(VfxObject *parentObj)
{
    VfxImageFrame *icon;

    VFX_OBJ_CREATE(icon, VfxImageFrame, parentObj);
    icon->setResId(VAPP_KEY_IMG_WG_ICON_FMRADIO);

    return icon;
}

void VappWidgetKeyFMRadio::onCreateView()
{
    VappWidget::onCreateView();

    VFX_OBJ_CREATE(m_Panel, VappWidgetKeyFMRadioPanel, this);
}

void VappWidgetKeyFMRadio::onReleaseView()
{  
    VFX_OBJ_CLOSE(m_Panel);
    VappWidget::onReleaseView();
}

VfxPoint VappWidgetKeyFMRadio::onGetEditButtonOffset()
{
    return VfxPoint(0, 0);
}

VfxBool VappWidgetKeyFMRadio::onPreviewPenInput(VfxPenEvent & event)
{
    return VFX_FALSE;
}

VfxBool VappWidgetKeyFMRadio::onPenInput(VfxPenEvent & event)
{
    return VFX_TRUE;
}

#endif/*defined(__MMI_VUI_WIDGET_KEY_FM_RADIO__)*/
