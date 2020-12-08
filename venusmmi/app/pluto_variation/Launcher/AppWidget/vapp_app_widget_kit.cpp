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
 *  vapp_app_widget_kit.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the widget kit.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vapp_app_widget.h"
#include "vapp_app_widget_def.h"
#include "vapp_app_widget_kit.h"
#include "vapp_app_widget_native_factory.h"
#include "vapp_app_widget_shortcut_factory.h"


/*****************************************************************************
 * Define
 *****************************************************************************/

#define VAPP_APP_WIDGET_ADD_FACTORY(_class)     (_class::createFactory)


/*****************************************************************************
 * Configuration
 *****************************************************************************/

const VappAppWidgetKit::createFunc VappAppWidgetKit::m_factoryCreateTbl[] =
{
    /* Factory used to create native widgets. */
    VAPP_APP_WIDGET_ADD_FACTORY(VappAppWidgetNativeFactory)

    /* Factory used to create shortcut widgets. */
    ,
    VAPP_APP_WIDGET_ADD_FACTORY(VappAppWidgetShortcutFactory)
};


/*****************************************************************************
 * Widget Kit Control
 *****************************************************************************/

VappAppWidgetKitControl::VappAppWidgetKitControl()
{
    for (VfxS32 i = 0; i < TOTAL_SOURCE_NUM; i++)
    {
        m_permitted[i] = VFX_TRUE;
    }
}


VappAppWidgetKitControl::VappAppWidgetKitControl(VfxBool initial)
{
    for (VfxS32 i = 0; i < TOTAL_SOURCE_NUM; i++)
    {
        m_permitted[i] = initial;
    }
}


VappAppWidgetKitControl::~VappAppWidgetKitControl()
{
    // Do nothing.
}


void VappAppWidgetKitControl::permit(VappAppWidgetSrcEnum source)
{
    VfxS32 idx = (VfxS32)source;

    VFX_ASSERT(idx >= 0 && idx < TOTAL_SOURCE_NUM);

    m_permitted[idx] = VFX_TRUE;
}


void VappAppWidgetKitControl::forbit(VappAppWidgetSrcEnum source)
{
    VfxS32 idx = (VfxS32)source;

    VFX_ASSERT(idx >= 0 && idx < TOTAL_SOURCE_NUM);

    m_permitted[idx] = VFX_FALSE;
}


VfxBool VappAppWidgetKitControl::isPermitted(VappAppWidgetSrcEnum source) const
{
    VfxS32 idx = (VfxS32)source;

    VFX_ASSERT(idx >= 0 && idx < TOTAL_SOURCE_NUM);

    return m_permitted[idx];
}


/*****************************************************************************
 * Widget Kit Class
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappAppWidgetKit", VappAppWidgetKit, VfxObject);

VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappAppWidgetKit);


VappAppWidgetKit::VappAppWidgetKit() :
    m_numOfFactory(0)
{
    // Do nothing.
}


void VappAppWidgetKit::onInit()
{
    m_numOfFactory = sizeof(m_factoryCreateTbl) / sizeof(createFunc);

    VFX_ASSERT(m_numOfFactory <= VAPP_APP_WIDGET_KIT_MAX_NUM_FACTORY);

    for (VfxS32 i = 0; i < m_numOfFactory; i++)
    {
        m_factory[i] = m_factoryCreateTbl[i]();
    }
}


void VappAppWidgetKit::onDeinit()
{
    for (VfxS32 i = 0; i < m_numOfFactory; i++)
    {
        VFX_OBJ_CLOSE(m_factory[i]);
    }
}


VfxS32 VappAppWidgetKit::getTotalNum(const VappAppWidgetKitControl *control)
{
    VfxS32 totalNum = 0;

    for (VfxS32 i = 0; i < m_numOfFactory; i++)
    {
        VFX_ASSERT(m_factory[i]);

        if (control && !control->isPermitted(m_factory[i]->getSource()))
        {
            continue;
        }

        totalNum += m_factory[i]->getTotalNum();
    }

    return totalNum;
}


VfxS32 VappAppWidgetKit::getAllId(
    VappAppWidgetId **id,
    VfxS32 size,
    const VappAppWidgetKitControl *control)
{
    VfxS32 totalNum = getTotalNum(control);
    VfxS32 originalSize, filledSize;

    VFX_ASSERT(id && size >= totalNum);

    originalSize = size;

    for (VfxS32 i = 0; i < m_numOfFactory; i++)
    {
        VFX_ASSERT(m_factory[i]);

        if (control && !control->isPermitted(m_factory[i]->getSource()))
        {
            continue;
        }

        filledSize = m_factory[i]->getAllId(id, size);

        id += filledSize;
        size -= filledSize;
    }

    VFX_ASSERT(size >= 0);

    return originalSize - size;
}


VfxBool VappAppWidgetKit::isIdValid(
    const VappAppWidgetId &id,
    const VappAppWidgetKitControl *control)
{
    for (VfxS32 i = 0; i < m_numOfFactory; i++)
    {
        VFX_ASSERT(m_factory[i]);

        if (control && !control->isPermitted(m_factory[i]->getSource()))
        {
            continue;
        }

        if (m_factory[i]->isValid(id))
        {
            return VFX_TRUE;
        }
    }

    return VFX_FALSE;
}


VfxS32 VappAppWidgetKit::getName(
    const VappAppWidgetId &id,
    VfxWChar *string,
    VfxS32 size)
{
    for (VfxS32 i = 0; i < m_numOfFactory; i++)
    {
        VFX_ASSERT(m_factory[i]);

        if (id.getSource() == m_factory[i]->getSource())
        {
            return m_factory[i]->getName(id, string, size);
        }
    }

    return 0;
}


VappAppWidget *VappAppWidgetKit::createWidget(
    const VappAppWidgetId &id,
    VfxObject *parentObj)
{
    for (VfxS32 i = 0; i < m_numOfFactory; i++)
    {
        VFX_ASSERT(m_factory[i]);

        if (id.getSource() == m_factory[i]->getSource())
        {
            VappAppWidget *widget = m_factory[i]->createWidget(id, parentObj);

            if (!widget)
            {
                return NULL;
            }

            widget->setSize(widget->getMaxSize());

            return widget;
        }
    }

    return NULL;
}


VfxFrame *VappAppWidgetKit::createIcon(
    const VappAppWidgetId &id,
    VfxObject *parentObj)
{
    for (VfxS32 i = 0; i < m_numOfFactory; i++)
    {
        VFX_ASSERT(m_factory[i]);

        if (id.getSource() == m_factory[i]->getSource())
        {
            return m_factory[i]->createIcon(id, parentObj);
        }
    }

    return NULL;
}


VfxS32 VappAppWidgetKit::getPreInstalledNum() const
{
    VfxS32 preInstalledNum = 0;

    for (VfxS32 i = 0; i < m_numOfFactory; i++)
    {
        VFX_ASSERT(m_factory[i]);
        preInstalledNum += m_factory[i]->getPreInstalledNum();
    }

    return preInstalledNum;
}


VfxS32 VappAppWidgetKit::getPreInstalledWidget(
    VappAppWidgetPreInstalled **preInstalled,
    VfxS32 size) const
{
    VfxS32 preInstalledNum = getPreInstalledNum();
    VfxS32 originalSize, filledSize;

    VFX_ASSERT(preInstalled && size >= preInstalledNum);

    originalSize = size;

    for (VfxS32 i = 0; i < m_numOfFactory; i++)
    {
        VFX_ASSERT(m_factory[i]);

        filledSize = m_factory[i]->getPreInstalledWidget(preInstalled, size);

        preInstalled += filledSize;
        size -= filledSize;
    }

    VFX_ASSERT(size >= 0);

    return originalSize - size;
}

#endif /* defined(__MMI_VUI_LAUNCHER__) */
