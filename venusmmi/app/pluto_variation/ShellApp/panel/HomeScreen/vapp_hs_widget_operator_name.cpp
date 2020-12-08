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
 *  vapp_hs_widget_operator_name.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen widget: operator name
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
     
/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_OPERATOR_NAME__

/* Venus MMI headers: */
#include "vapp_hs_widget_operator_name.h"
#include "vadp_app_trc.h"
#include "vrt_datatype.h"
#include "vfx_datatype.h"
#include "vfx_control.h"
#include "vfx_object.h"
#include "vfx_signal.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_text_frame.h"
#include "vfx_string.h"
#include "vfx_animation.h"
#include "vrt_canvas.h"
#include "vfx_basic_type.h"
#include "vfx_frame.h"
#include "vdat_network_info.h"
#include "vfx_system.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "mmi_rp_app_venus_homescreen_wg_operator_name_def.h"

#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * Network info class
 *****************************************************************************/

// font of network info string, medium bordered font
const vrt_font_struct VappHsNetworkInfo::s_font = {0, 0, 0, 1, 0, 1, 0, 0, VRT_TRUE};


VappHsNetworkInfo::VappHsNetworkInfo() :
    m_netname(NULL),
    m_netstat(NULL),
    m_animScroll(NULL)
{
    for (VfxS32 i = 0 ; i < 2 ; i ++)
    {
        for( VfxS32 j = 0 ; j < 2 ; j++)
        {
            m_tlPos[i][j] = NULL;
            m_tlOpa[i][j] = NULL;
        }
    }
}


void VappHsNetworkInfo::onInit()
{
    VfxControl::onInit();

    // init
    m_signalBoundsChanged.connect(this, &VappHsNetworkInfo::onBoundsValueChange);

    // init netname text
    VFX_OBJ_CREATE(m_netname, VfxTextFrame, this);
    m_netname->setString(VFX_WSTR_NULL);    // TODO: null string, otherwise empty string 
    m_netname->setHidden(VFX_TRUE);         // do not display by default
    m_netname->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_netname->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_netname->setFont(VfxFontDesc(s_font));

    // init netstat text
    VFX_OBJ_CREATE(m_netstat, VfxTextFrame, this);
    m_netstat->setString(VFX_WSTR_NULL);    // TODO: null string, otherwise empty string
    m_netstat->setHidden(VFX_TRUE);         // do not display by default
    m_netstat->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_netstat->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_netstat->setFont(VfxFontDesc(s_font));

    // init scroll animation
    VFX_OBJ_CREATE(m_animScroll, VfxAnimation, this);

    // create timeline for two text transition
    for (VfxS32 i = 0 ; i < 2 ; i ++)
    {
        VfxTextFrame *t1, *t2;

        t1 = (i) ? (m_netname) : (m_netstat);
        t2 = (i) ? (m_netstat) : (m_netname);

        // create timeline for incoming and outgoing text with changing position and opacity
        // [0][0]: netname->out
        // [0][1]: netstat->in
        // [1][0]: netstat->out
        // [1][1]: netname->in
        for (VfxS32 j = 0 ; j < 2 ; j ++)
        {
            VfxTextFrame *t = (j) ? (t1) : (t2); // target text

            {   // position transition
                VFX_OBJ_CREATE(m_tlPos[i][j], VfxS32Timeline, m_animScroll);
                m_tlPos[i][j]->setTarget(t);
                m_tlPos[i][j]->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_Y);
                m_tlPos[i][j]->setIsFromCurrent(VFX_FALSE);
                m_tlPos[i][j]->setFromValue(0);    // wait for bounds change
                m_tlPos[i][j]->setToValue(0);    // wait for bounds chagne
                m_tlPos[i][j]->setDurationTime(SLIDING_TIME);
                m_tlPos[i][j]->setRepeatDuration(TOTAL_TIME);
                m_tlPos[i][j]->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
            }

            {   // opacity transition
                VfxFloat o1, o2;
    
                o1 = (j) ? (0.0f) : (1.0f);
                o2 = (j) ? (1.0f) : (0.0f);
    
                VFX_OBJ_CREATE(m_tlOpa[i][j], VfxFloatTimeline, m_animScroll);
                m_tlOpa[i][j]->setTarget(t);
                m_tlOpa[i][j]->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
                m_tlOpa[i][j]->setIsFromCurrent(VFX_FALSE);
                m_tlOpa[i][j]->setFromValue(o1);
                m_tlOpa[i][j]->setToValue(o2);
                m_tlOpa[i][j]->setDurationTime(SLIDING_TIME);
                m_tlOpa[i][j]->setRepeatDuration(TOTAL_TIME);
                m_tlOpa[i][j]->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
            }
        }
    }
}


void VappHsNetworkInfo::centerAlignment(VfxTextFrame *text)
{
    VfxPoint pos;
    VfxSize size;
    VfxS32 max_width = getBounds().getWidth();

    // center alignment
    pos = text->getPos();
    size = text->getBounds().size;
    pos.x = (max_width > size.width) ? ((max_width - size.width) >> 1) : (0);
    text->setPos(pos);
}


void VappHsNetworkInfo::show()
{
    VfxBool is_display_single = VFX_FALSE;

    // if animation is enabled before
    if (m_animScroll->getIsEnabled())
    {
        if (m_netname->getString() && m_netstat->getString())
        {
            // if both strings, do nothing
        }
        else
        {   // if only one string left, stop scrolling
            m_animScroll->stop();
            is_display_single = VFX_TRUE;
        }
    }
    else
    {
        // if both strings, start animation
        if (m_netname->getString() && m_netstat->getString())
        {   // check the scrolling is from network name or status
            VfxBool is_from_name = (!m_netstat->getHidden()) ? (VFX_FALSE) : (VFX_TRUE);

            // adjust start time according to which text to scroll
            if (is_from_name)
            {
                m_netname->setPos(VfxPoint((m_netname->getPos().x), 0));
                m_netstat->setPos(VfxPoint((m_netstat->getPos().x), -getBounds().getHeight()));
                for (VfxS32 i = 0 ; i < 2 ; i++)
                {
                    for (VfxS32 j = 0 ; j < 2 ; j++)
                    {
                        m_tlPos[i][j]->setStartTime(DISPLAY_TIME + ((DISPLAY_TIME + SLIDING_TIME) * i));
                        m_tlOpa[i][j]->setStartTime(DISPLAY_TIME + ((DISPLAY_TIME + SLIDING_TIME) * i));
                    }
                }
            }
            else
            {
                m_netname->setPos(VfxPoint((m_netname->getPos().x), -getBounds().getHeight()));
                m_netstat->setPos(VfxPoint((m_netstat->getPos().x), 0));
                for (VfxS32 i = 0 ; i < 2 ; i++)
                {
                    for (VfxS32 j = 0 ; j < 2 ; j++)
                    {
                        m_tlPos[i][j]->setStartTime(DISPLAY_TIME + ((DISPLAY_TIME + SLIDING_TIME) * (1 - i)));
                        m_tlOpa[i][j]->setStartTime(DISPLAY_TIME + ((DISPLAY_TIME + SLIDING_TIME) * (1 - i)));
                    }
                }
            }
            m_netname->setHidden(VFX_FALSE);
            m_netstat->setHidden(VFX_FALSE);

            m_animScroll->start();
        }
        else
        {
            is_display_single = VFX_TRUE;
        }
    }

    // if only display one string, adjust position and hide the other
    if (is_display_single)
    {
        if (m_netname->getString())
        {
            m_netname->setPos(VfxPoint((m_netname->getPos().x), 0));
            m_netname->setHidden(VFX_FALSE);
            m_netstat->setHidden(VFX_TRUE);
        }

        if (m_netstat->getString())
        {
            m_netstat->setPos(VfxPoint((m_netstat->getPos().x), 0));
            m_netstat->setHidden(VFX_FALSE);
            m_netname->setHidden(VFX_TRUE);
        }
    }

    invalidate();   // TODO: remove this
}


void VappHsNetworkInfo::setNetname(const VfxWString &str)
{
    if (m_netname)
    {
        m_netname->setString(str);
        centerAlignment(m_netname);
        show();
    }
}


void VappHsNetworkInfo::setNetstat(const VfxWString &str)
{
    if (m_netstat)
    {
        m_netstat->setString(str);
        centerAlignment(m_netstat);
        show();
    }
}


const VfxWChar *VappHsNetworkInfo::getNetname()
{
    if (m_netname)
    {
        return m_netname->getString().getBuf();
    }

    return NULL;
}


const VfxWChar *VappHsNetworkInfo::getNetstat()
{
    if (m_netstat)
    {
        return m_netstat->getString().getBuf();
    }

    return NULL;
}


void VappHsNetworkInfo::onBoundsValueChange(VfxFrame *source, const VfxRect &oldBounds)
{
    VFX_UNUSED(source);
    VFX_UNUSED(oldBounds);

    VfxS32 max_height = getBounds().getHeight();
    VfxS32 y1, y2;

    for (VfxS32 i = 0 ; i < 2 ; i ++)
    {
        for (VfxS32 j = 0 ; j < 2 ; j ++)
        {
            y1 = (j) ? (-max_height) : (0);
            y2 = (j) ? (0) : (max_height);

            m_tlPos[i][j]->setFromValue(y1);
            m_tlPos[i][j]->setToValue(y2);
        }
    }

    m_netname->setBounds(getBounds());
    m_netstat->setBounds(getBounds());

    centerAlignment(m_netname);
    centerAlignment(m_netstat);
    show();
}



/***************************************************************************** 
 * Home screen widget: operator name
 *****************************************************************************/

VappHsWidgetOperatorName::VappHsWidgetOperatorName() :
#if (MMI_MAX_SIM_NUM == 2)
    m_ni2(NULL),
#endif
    m_ni(NULL)
{
}


VfxU16 VappHsWidgetOperatorName::getIcon()
{
    return VAPP_HS_IMG_WG_ICON_OPERATOR_NAME;
}


VfxU16 VappHsWidgetOperatorName::getName()
{
    return VAPP_HS_STR_WG_OPERATOR_NAME;
}


void VappHsWidgetOperatorName::onCreateView()
{
    // background image
    VfxImageSrc bgImage;
    bgImage.setResId(VAPP_HS_IMG_WG_OPERATOR_NAME_BG);

#if defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
    setIsOpaque(VFX_TRUE);
#endif

    VfxSize size = bgImage.getSize();

    setImgContent(bgImage);
    setBounds(VfxRect(VFX_POINT_ZERO, size));
    setIsCached(VFX_TRUE);

    // Network information
    VdatNetworkInfo *networkSrv = VFX_OBJ_GET_INSTANCE(VdatNetworkInfo);

#if (MMI_MAX_SIM_NUM == 1)
    // SIM 1 network information
    VFX_OBJ_CREATE(m_ni, VappHsNetworkInfo, this);
    m_ni->setAnchor(VfxFPoint(0.5f, 0.5f));
    m_ni->setBounds(VfxRect(0, 0, size.width - GAP_X, INFO_HEIGHT));

    // Connect signal.    
    networkSrv->m_signalNameChanged.connect(this, &VappHsWidgetOperatorName::onNetworkNameChanged);
    networkSrv->m_signalStatusChanged.connect(this, &VappHsWidgetOperatorName::onNetworkStatusChanged);

    // Update string immediately.
    onNetworkNameChanged(networkSrv);
    onNetworkStatusChanged(networkSrv);
#else
    // SIM 1 network information
    VFX_OBJ_CREATE(m_ni, VappHsNetworkInfo, this);
    m_ni->setAnchor(VfxFPoint(0.5f, 0.5f));
    m_ni->setBounds(VfxRect(0, 0, size.width - GAP_X, INFO_HEIGHT));
    
    // SIM 2 network information
    VFX_OBJ_CREATE(m_ni2, VappHsNetworkInfo, this);
    m_ni2->setAnchor(VfxFPoint(0.5f, 0.5f));
    m_ni2->setBounds(VfxRect(0, 0, size.width - GAP_X, INFO_HEIGHT));

    // Connect signal.
    networkSrv->m_signalNameChanged.connect(this, &VappHsWidgetOperatorName::onNetworkNameChanged);
    networkSrv->m_signalStatusChanged.connect(this, &VappHsWidgetOperatorName::onNetworkStatusChanged);
    networkSrv->m_signalNameChanged2.connect(this, &VappHsWidgetOperatorName::onNetworkNameChanged2);
    networkSrv->m_signalStatusChanged2.connect(this, &VappHsWidgetOperatorName::onNetworkStatusChanged2);

    // Update string immediately.
    onNetworkNameChanged(networkSrv);
    onNetworkStatusChanged(networkSrv);
    onNetworkNameChanged2(networkSrv);
    onNetworkStatusChanged2(networkSrv);
#endif /* (MMI_MAX_SIM_NUM == 1) */
}


void VappHsWidgetOperatorName::onReleaseView()
{
    VdatNetworkInfo *networkSrv = VFX_OBJ_GET_INSTANCE(VdatNetworkInfo);

    // Close the network information of SIM 1.
    VFX_OBJ_CLOSE(m_ni);
    networkSrv->m_signalNameChanged.disconnect(this, &VappHsWidgetOperatorName::onNetworkNameChanged);
    networkSrv->m_signalStatusChanged.disconnect(this, &VappHsWidgetOperatorName::onNetworkStatusChanged);

#if (MMI_MAX_SIM_NUM == 2)
    // Close the network information of SIM 2.
    VFX_OBJ_CLOSE(m_ni2);
    networkSrv->m_signalNameChanged2.disconnect(this, &VappHsWidgetOperatorName::onNetworkNameChanged2);
    networkSrv->m_signalStatusChanged2.disconnect(this, &VappHsWidgetOperatorName::onNetworkStatusChanged2);
#endif /* (MMI_MAX_SIM_NUM == 2) */
}


void VappHsWidgetOperatorName::onNetworkNameChanged(VdatNetworkInfo *networkSrv)
{
    m_ni->setNetname(networkSrv->getName());
    arrangePosition();
}


void VappHsWidgetOperatorName::onNetworkStatusChanged(VdatNetworkInfo *networkSrv)
{
    m_ni->setNetstat(networkSrv->getStatus());
    arrangePosition();
}


#if (MMI_MAX_SIM_NUM == 2)
void VappHsWidgetOperatorName::onNetworkNameChanged2(VdatNetworkInfo *networkSrv)
{
    m_ni2->setNetname(networkSrv->getName2());
    arrangePosition();
}


void VappHsWidgetOperatorName::onNetworkStatusChanged2(VdatNetworkInfo *networkSrv)
{
    m_ni2->setNetstat(networkSrv->getStatus2());
    arrangePosition();
}
#endif /* (MMI_MAX_SIM_NUM == 2) */


void VappHsWidgetOperatorName::arrangePosition()
{
    VfxImageSrc bgImage;
    bgImage.setResId(VAPP_HS_IMG_WG_OPERATOR_NAME_BG);

    VfxSize size = bgImage.getSize();

#if (MMI_MAX_SIM_NUM == 1)
    // Single SIM: 
    //  operator name is always center-aligned.

    m_ni->setPos(VfxPoint(size.width / 2, INFO_Y));
#else
    // Dual SIM:
    //  If m_ni2 is empty, e.g. flight mode, then m_ni is center-aligned. 
    //  Otherwise, m_ni and m_ni2 shares the height.

    const VfxWChar *name = m_ni2->getNetname();
    const VfxWChar *stat = m_ni2->getNetstat();

    if ((name != NULL && vfx_sys_wcslen(name) != 0) ||
        (stat != NULL && vfx_sys_wcslen(stat) != 0))
    {
        m_ni->setPos(VfxPoint(size.width / 2, INFO_Y1));
        m_ni2->setPos(VfxPoint(size.width / 2, INFO_Y2));
    }
    else
    {
        m_ni->setPos(VfxPoint(size.width / 2, INFO_Y));
    }
#endif /* (MMI_MAX_SIM_NUM == 1) */
}

#endif /* __MMI_VUI_HOMESCREEN_OPERATOR_NAME__ */

