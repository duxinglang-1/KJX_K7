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
 *  vcp_switch.cpp
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  Switch component
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
#include "vcp_switch.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_control.h"
#include "vfx_primitive_frame.h"
#include "vfx_image_src.h"
#include "vfx_basic_type.h"
#include "vfx_auto_animate.h"
#include "vfx_input_event.h"
#include "vfx_signal.h"
#include "vfx_adp_device.h"
#include "mmi_rp_srv_venus_component_switch_def.h"
#include "vfx_timer.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
static const VfxS32 ONOFF_IMAGE_GAP = 10;
#if defined (__MTK_TARGET__) && defined (__VENUS_SWLA_DBG_ON__)
	#define __MAUI_SOFTWARE_LA__
#endif // __MTK_TARGET__
#ifdef __MAUI_SOFTWARE_LA__
extern "C"
{
#include "SST_sla.h"
}
#endif 
	

#if defined(__MMI_MAINLCD_480X800__)
static const VfxS32 VCP_SWITCH_EXTRA_WIDTH_DEFAULT = 0;
static const VfxS32 VCP_SWITCH_EXTRA_HEIGHT_DEFAULT = 4;
static const VfxS32 VCP_SWITCH_BG_X_DEFAULT = 0;
static const VfxS32 VCP_SWITCH_BG_Y_DEFAULT = 2;

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
static const VfxS32 VCP_SWITCH_EXTRA_WIDTH_DEFAULT = 0;
static const VfxS32 VCP_SWITCH_EXTRA_HEIGHT_DEFAULT = 2;
static const VfxS32 VCP_SWITCH_BG_X_DEFAULT = 0;
static const VfxS32 VCP_SWITCH_BG_Y_DEFAULT = 1;

#else // default 320X480
static const VfxS32 VCP_SWITCH_EXTRA_WIDTH_DEFAULT = 0;
static const VfxS32 VCP_SWITCH_EXTRA_HEIGHT_DEFAULT = 0;
static const VfxS32 VCP_SWITCH_BG_X_DEFAULT = 0;
static const VfxS32 VCP_SWITCH_BG_Y_DEFAULT = 0;

#endif

static const VfxS32 VCP_SWITCH_EXTRA_TOUCH_MARGIN = VFX_TOUCH_FINGER_WIDTH * 3 / 4;

/***************************************************************************** 
 * Class VcpSwitch 
 *****************************************************************************/  
VFX_IMPLEMENT_CLASS("VcpSwitch", VcpSwitch, VfxControl);

VcpSwitch::VcpSwitch() :
    m_checked(VFX_FALSE),
    m_id(0),
    m_isHapticTouchEnabled(VFX_TRUE),
    m_animSyncTimer(NULL),
    m_bgFrame(NULL),
    m_slider(NULL),
    m_onIcon(NULL),
    m_offIcon(NULL),
    m_bgOnImage(VCP_IMG_SWITCH_BG_ON),
    m_bgOffImage(VCP_IMG_SWITCH_BG_OFF),
    m_sliderOnImage(VCP_IMG_SWITCH_SLIDE_BALL_ON),
    m_sliderOffImage(VCP_IMG_SWITCH_SLIDE_BALL_OFF),
    m_sliderOnPos(0, 0),
    m_sliderOffPos(0, 0)
{
}


void VcpSwitch::onInit()
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("SwI", SA_start); 
#endif		
    VfxControl::onInit();
    
    setAutoAnimate(VFX_TRUE);
    setFuzzy(VFX_TRUE);

    // initial the image source and position

    // create switch bg image frame
    VFX_OBJ_CREATE(m_bgFrame, VfxImageFrame, this );
    m_bgFrame->setImgContent(m_bgOnImage);
    m_bgFrame->setPos(VCP_SWITCH_BG_X_DEFAULT, VCP_SWITCH_BG_Y_DEFAULT);
    setSize(m_bgFrame->getSize().width + VCP_SWITCH_EXTRA_WIDTH_DEFAULT,
            m_bgFrame->getSize().height + VCP_SWITCH_EXTRA_HEIGHT_DEFAULT);

    // create on, off static frames
    VFX_OBJ_CREATE(m_onIcon, VfxImageFrame, this);
    m_onIcon->setImgContent(VfxImageSrc(VCP_IMG_SWITCH_ICON_ON) );
    m_onIcon->setPos(VfxPoint(getSize().width - m_onIcon->getSize().width - ONOFF_IMAGE_GAP, (getSize().height - m_onIcon->getSize().height) / 2) );
    VFX_OBJ_CREATE(m_offIcon, VfxImageFrame, this);
    m_offIcon->setImgContent(VfxImageSrc(VCP_IMG_SWITCH_ICON_OFF) );
    m_offIcon->setPos(VfxPoint(ONOFF_IMAGE_GAP, (getSize().height - m_offIcon->getSize().height) / 2) );

    // create the slider
    VFX_OBJ_CREATE(m_slider, VfxImageFrame, this );
    m_slider->setAutoAnimate(VFX_TRUE);
    m_slider->setImgContent(m_sliderOnImage);

    m_sliderOnPos = VfxPoint(getSize().width - m_slider->getSize().width, 0);
    m_sliderOffPos = VfxPoint(0, 0);
    setChecked(VFX_TRUE, VFX_FALSE);
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("SwI", SA_stop); 
#endif			
}


void VcpSwitch::onDeinit()
{
    VfxControl::onDeinit();
}


void VcpSwitch::setChecked(VfxBool checked, VfxBool isAnimated)
{
    if(m_checked == checked)
    {
        return;
    }
    m_checked = checked;

    if(m_animSyncTimer)
    {
        VFX_OBJ_CLOSE(m_animSyncTimer);
    }
    if(isAnimated)
    {
        VFX_OBJ_CREATE(m_animSyncTimer, VfxTimer, this);
        m_animSyncTimer->setStartDelay(VfxAutoAnimate::getDuration());
        m_animSyncTimer->m_signalTick.connect(this, &VcpSwitch::onSwitchAnimationComplete);
        m_animSyncTimer->start();
    }

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(!isAnimated);
    onUpdateState();
    VfxAutoAnimate::commit();
}

void VcpSwitch::setId(VfxId id)
{
    m_id = id;
}

VfxId VcpSwitch::getId()
{
    return m_id;
}

void VcpSwitch::setBgImage(VfxImageSrc onImage, VfxImageSrc offImage)
{
    m_bgOnImage = onImage;
    m_bgOffImage = offImage;
    onUpdateState();
    setSize(m_bgFrame->getSize() );
}

void VcpSwitch::setSliderImage(VfxImageSrc onImage, VfxImageSrc offImage)
{
    m_sliderOnImage = onImage;
    m_sliderOffImage = offImage;
    onUpdateState();
}

void VcpSwitch::setIconImage(VfxImageSrc onImage, VfxImageSrc offImage)
{
    m_onIcon->setImgContent(onImage);
    m_offIcon->setImgContent(offImage);
}

void VcpSwitch::setBgPos(VfxPoint pos)
{
    m_bgFrame->setPos(pos);
}

void VcpSwitch::setSliderPos(VfxPoint onPos, VfxPoint offPos)
{
    m_sliderOnPos = onPos;
    m_sliderOffPos = offPos;
    onUpdateState();
}

void VcpSwitch::setIconPos(VfxPoint onIconPos, VfxPoint offIconPos)
{
    m_onIcon->setPos(onIconPos);
    m_offIcon->setPos(offIconPos);
}

void VcpSwitch::setIsHapticTouchEnabled(VfxBool state)
{
       m_isHapticTouchEnabled = state;
}

VfxBool VcpSwitch::getIsHapticTouchEnabled()
{
    return m_isHapticTouchEnabled;
}


void VcpSwitch::onUpdateState()
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("SwU", SA_start); 
#endif		
    // change visual by states
    if (m_checked)
    {
        m_bgFrame->setImgContent(m_bgOnImage);
        m_slider->setImgContent(m_sliderOnImage);
        
        m_slider->setPos(m_sliderOnPos);
    }
    else
    {
        m_bgFrame->setImgContent(m_bgOffImage);
        m_slider->setImgContent(m_sliderOffImage);
        
        m_slider->setPos(m_sliderOffPos);
    }
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("SwU", SA_stop); 
#endif			
}


VfxBool VcpSwitch::onPenInput(VfxPenEvent &event)
{
    VfxBool ret;

    ret = VFX_FALSE;

    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
                if(getIsHapticTouchEnabled())
                {
                    vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_DOWN);
                }
        case VFX_PEN_EVENT_TYPE_MOVE:        
            ret = VFX_TRUE;
            break;

        case VFX_PEN_EVENT_TYPE_UP:
            // toggle state
            setChecked(!getChecked() );

            // emit value change signal
            m_signalSwitchChanged.emit(this, m_checked);
            
            ret = VFX_TRUE;
            break;

        default:
            break;       
    }

    return ret;
}

void VcpSwitch::onSwitchAnimationComplete(VfxTimer *timer)
{
    VFX_UNUSED(timer);
    m_signalToggleAnimationDone.postEmit(this, m_checked);
}

VfxBool VcpSwitch::onContainPoint(const VfxPoint &point) const
{
    VfxRect bounds = getBounds();
    bounds.origin.x -= VCP_SWITCH_EXTRA_TOUCH_MARGIN;
    bounds.origin.y -= VCP_SWITCH_EXTRA_TOUCH_MARGIN;
    bounds.size.width += VCP_SWITCH_EXTRA_TOUCH_MARGIN * 2;
    bounds.size.height += VCP_SWITCH_EXTRA_TOUCH_MARGIN * 2;
    return bounds.contains(point);
}

VfxBool VcpSwitch::onPenAbortAccepted(VfxControl *aborter, VfxPenAbortReasonEnum reason)
{
    //return VfxControl::onPenAbortAccepted(aborter, reason);
    VFX_UNUSED(aborter);
    VFX_UNUSED(reason);

    return VFX_FALSE;
}


