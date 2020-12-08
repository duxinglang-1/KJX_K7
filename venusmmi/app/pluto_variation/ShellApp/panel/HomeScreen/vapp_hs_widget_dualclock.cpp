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
 *  vapp_hs_widget_dualclock.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen widget: dual clock
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_DUALCLOCK__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_hs_widget_dualclock.h"


/***************************************************************************** 
 * Home screen widget: dual clock
 *****************************************************************************/

VappHsWidgetDualclock::VappHsWidgetDualclock() :
    m_clock(NULL),
    m_textCity(NULL)
{
}


void VappHsWidgetDualclock::onCreateView()
{
    // background image 
    setImgContent(VfxImageSrc(VAPP_HS_IMG_WG_DUALCLOCK_BG));
    setBounds(VfxRect(VFX_POINT_ZERO, getImgContent().getSize()));

#if defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
    setIsOpaque(VFX_TRUE);
#endif /* defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */

    // set city time
    VfxU32 hour = 0, mins = 0, secs = 0;
    VfxDateTime dt;
    vadp_v2p_hs_dualclock_get_time(&hour, &mins, &secs);
    dt.setTime(hour, mins, secs);

    VFX_OBJ_CREATE(m_clock, VcpDigitalImageClock, this);
    m_clock->setAnchor(VfxFPoint(0.5, 0.5));
    m_clock->setPos(VfxPoint(getBounds().getWidth() / 2, CLOCK_Y_OFFSET));
    m_clock->setBackground(NULL);
    m_clock->setTime(dt);
    m_clock->startClock();

    // city name
    VFX_OBJ_CREATE(m_textCity, VfxTextFrame, this);
    m_textCity->setAnchor(VfxFPoint(0.5, 0.5));
    m_textCity->setPos(VfxPoint(TEXT_X_OFFSET, TEXT_Y_OFFSET));
    m_textCity->setBounds(VfxRect(0, 0, TEXT_WIDTH, 0 /* text frame will assign automatically */));
    m_textCity->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_textCity->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_textCity->setString(VFX_WSTR_MEM(vadp_v2p_hs_dualclock_get_name()));
}


void VappHsWidgetDualclock::onReleaseView()
{
    setImgContent(VFX_IMAGE_SRC_NULL);

    VFX_OBJ_CLOSE(m_textCity);
    VFX_OBJ_CLOSE(m_clock);
}

#endif /* __MMI_VUI_HOMESCREEN_DUALCLOCK__ */

