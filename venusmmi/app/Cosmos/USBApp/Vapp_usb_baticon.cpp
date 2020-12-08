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
 *  vapp_usb_baticon.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __USB_MMI_DEBUG__

#ifndef __MTK_TARGET__
#ifndef __MMI_USB_SUPPORT__
#define __MMI_USB_SUPPORT__
#endif
#endif
#endif

#include "MMI_features.h" 


#if defined(__MMI_USB_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__)

/***************************************************************************** 
* Include
*****************************************************************************/
#include "mmi_rp_vapp_usbmmi_def.h"
#include "Vapp_usb_baticon.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/

void VappUSBBatIcon::onInit()
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBBATICON_ONINIT);
    VfxFrame::onInit();
    createBorder();
}

void VappUSBBatIcon::onDeinit()
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBBATICON_ONDEINIT);
    VfxFrame::onDeinit();
}


void VappUSBBatIcon::update(StateEnum state, LevelEnum level)
{
    VfxBool levelChange;
    
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBBATICON_UPDATE, state, level);
    
    
    levelChange = updateLevel(level, (state == STATE_BLINK));

    if (m_level >= LEVEL_3)
    {
        state = STATE_STATIC;
    }
    
    /* Stop blinking*/
    if (state == STATE_STATIC &&
        m_state == STATE_BLINK)
    {
        stopBlink();
    }
    else if (state == STATE_BLINK &&
        m_state == STATE_STATIC)
    {
        startBlink();
    }
    else if (state == STATE_BLINK &&
        levelChange)
    {
        startBlink();
    }
    
    m_state = state;
}

VfxBool VappUSBBatIcon::updateLevel(LevelEnum level, VfxBool blink)
{
    VfxS32 i;
	VfxS32 max;
    VfxBool levelChanged;
    
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBBATICON_UPDATELEVEL, level);

    if (m_level == level)
    {
        levelChanged = VFX_FALSE;
    }
    else
    {
        levelChanged = VFX_TRUE;
    }
    m_level = level;

    if (!blink)
    {
		if (m_level >= LEVEL_2)
			max = LEVEL_2;
		else
			max = m_level;

		for (i = 0; (LevelEnum)i <= max; i++)
		{
			createBlock((LevelEnum)i);
		}
        for ( ; (LevelEnum)i < LEVEL_COUNT; i++)
        {
            deleteBlock((LevelEnum)i);
        }
    }
    else
    {
        for (i = 0 ; (LevelEnum)i < LEVEL_COUNT; i++)
        {
            createBlock((LevelEnum)i);
        }
    }

    return levelChanged;
}

VfxU8 VappUSBBatIcon::getLevelCount(void)
{
    return LEVEL_COUNT;
}

VappUSBBatIcon::StateEnum VappUSBBatIcon::getCurState(void)
{
    return m_state;
}

VappUSBBatIcon::LevelEnum VappUSBBatIcon::getCurLevel(void)
{
    return m_level;
}

void VappUSBBatIcon::createTimer(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBBATICON_CREATETIMER);
    if (m_timer)
        return;

    VFX_OBJ_CREATE(m_timer, VfxTimer, this);
    m_timer->m_signalTick.connect(this, &VappUSBBatIcon::onTimer);
}

void VappUSBBatIcon::closeTimer(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBBATICON_CLOSETIMER);
    if (!m_timer)
        return;

    m_timer->m_signalTick.disconnect(this, &VappUSBBatIcon::onTimer);
    VFX_OBJ_CLOSE(m_timer);
}

void VappUSBBatIcon::startTimer(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBBATICON_STARTTIMER);
    createTimer();
    m_timer->setDuration(m_blinkDur);
    m_timer->start();
}

void VappUSBBatIcon::stopTimer(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBBATICON_STOPTIMER);
    if (m_timer->getIsEnabled())
    {
        m_timer->stop();
    }
    closeTimer();
}

void VappUSBBatIcon::stopBlink(void)
{
    VfxS32 max;
    VfxS32 i;
    
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBBATICON_STOPBLINK);

    stopTimer();
    m_blinkIndex = 0;

    if (m_level == LEVEL_0)
    {
        return;
    }

    if (m_level >= LEVEL_2)
    {
        max = LEVEL_COUNT;
    }
    else
    {
        max = m_level;
    }

    for (i  = 0; i < max; i++)
    {
        if (m_block[i] && m_block[i]->getHidden())
        {
            m_block[i]->setHidden(VFX_FALSE);
        }
    }
    
}

void VappUSBBatIcon::startBlink(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBBATICON_STARTBLINK);
    m_blinkIndex = 0;
    startTimer();
}

void VappUSBBatIcon::createBlock(LevelEnum level)
{
    VfxS32 nLevel = (VfxS32)level;

    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBBATICON_CREATEBLOCK, level);
    
    if (m_block[nLevel])
        return;

    VFX_OBJ_CREATE(m_block[nLevel], VfxFrame, this);
    m_block[nLevel]->setPos(getX(level), getY(level));
    m_block[nLevel]->setSize(getWidth(level), getHeight(level));
    m_block[nLevel]->setImgContent(VfxImageSrc(getLevelImgId(level)));
    m_block[nLevel]->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_block[nLevel]->setHidden(VFX_FALSE);
}

void VappUSBBatIcon::deleteBlock(LevelEnum level)
{
    VfxS32 nLevel = (VfxS32)level;

    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBBATICON_DELETEBLOCK, level);
    
    if (m_block[nLevel])
    {
        VFX_OBJ_CLOSE(m_block[nLevel]);
    }
}

void VappUSBBatIcon::createBorder(void)
{
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBBATICON_CREATEBORDER);
    if (!m_border)
    {
        VFX_OBJ_CREATE(m_border, VfxFrame, this);
        m_border->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        m_border->setPos(BORDER_POS_X, BORDER_POS_Y);
        m_border->setSize(BORDER_POS_WIDTH, BORDER_POS_HEIGHT);
        m_border->setImgContent(VfxImageSrc(IMG_ID_VAPP_USB_BATTERY_BORDER));
    }
}

void VappUSBBatIcon::onTimer(VfxTimer *source)
{
    LevelBlinkMapStruct *map;
    VfxU8 *line;
    VfxU8 i;
    
    MMI_TRACE(TRACE_GROUP_8, TRC_MMI_VAPP_USB_VAPPUSBBATICON_ONTIMER);
    
    if (!m_timer)
        return;
    if (source != m_timer)
        return;
    if (m_state != STATE_BLINK)
        return;
    //if (m_level == LEVEL_0)
    //    return;
    if (m_level >= LEVEL_3)
        return;
    
    map = (LevelBlinkMapStruct*)levelBlinkMap[m_level];
    if (map[m_blinkIndex].block[0] == 255)
    {
        m_blinkIndex = 0;
    }

    line = map[m_blinkIndex].block;
    
    for (i = 0; i < LEVEL_COUNT; i++)
    {
        if (line[i])
        {
            if (m_block[i])
            {
                if (m_block[i]->getHidden())
                {
                    m_block[i]->setHidden(VFX_FALSE);
                }
            }
        }
        else
        {
            if (m_block[i])
            {
                if (!m_block[i]->getHidden())
                {
                    m_block[i]->setHidden(VFX_TRUE);
                }
            }
        }
    }
    
    m_blinkIndex++;
}

#endif /* __MMI_USB_SUPPORT__*/
