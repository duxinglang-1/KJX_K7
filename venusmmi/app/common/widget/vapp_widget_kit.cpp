/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vapp_widget_kit.cpp
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

#if defined(__MMI_VUI_WIDGET_FACTORY__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vapp_widget.h"
#include "vapp_widget_def.h"
#include "vapp_widget_kit.h"


/*****************************************************************************
 * Widget Kit Control
 *****************************************************************************/

VappWidgetKitControl::VappWidgetKitControl()
{
    for (VfxS32 i = 0; i < TOTAL_SOURCE_NUM; i++)
    {
        m_permitted[i] = VFX_TRUE;
    }
}


VappWidgetKitControl::VappWidgetKitControl(VfxBool initial)
{
    for (VfxS32 i = 0; i < TOTAL_SOURCE_NUM; i++)
    {
        m_permitted[i] = initial;
    }
}


VappWidgetKitControl::~VappWidgetKitControl()
{
    // Do nothing.
}


void VappWidgetKitControl::permit(VappWidgetSrcEnum source)
{
    VfxS32 idx = (VfxS32)source;

    VFX_ASSERT(idx >= 0 && idx < TOTAL_SOURCE_NUM);

    m_permitted[idx] = VFX_TRUE;
}


void VappWidgetKitControl::forbit(VappWidgetSrcEnum source)
{
    VfxS32 idx = (VfxS32)source;

    VFX_ASSERT(idx >= 0 && idx < TOTAL_SOURCE_NUM);

    m_permitted[idx] = VFX_FALSE;
}


VfxBool VappWidgetKitControl::isPermitted(VappWidgetSrcEnum source) const
{
    VfxS32 idx = (VfxS32)source;

    VFX_ASSERT(idx >= 0 && idx < TOTAL_SOURCE_NUM);

    return m_permitted[idx];
}


/*****************************************************************************
 * Widget Kit Class
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappWidgetKit", VappWidgetKit, VfxObject);

VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappWidgetKit);


VappWidgetKit::VappWidgetKit() :
    m_factoryList()
{
    // Do nothing.
}


void VappWidgetKit::add(VappWidgetFactory *factory)
{
    if (m_factoryList.contains(factory))
    {
        return;
    }

    m_factoryList.append(factory);
}


void VappWidgetKit::remove(VappWidgetFactory *factory)
{
    m_factoryList.removeOne(factory);
}


VfxS32 VappWidgetKit::getTotalNum(const VappWidgetKitControl *control)
{
    VfxS32 totalNum = 0;

    for (VfxObjListEntry *listEntry = m_factoryList.getHead();
         listEntry != NULL;
         listEntry = listEntry->getNext())
    {
        VappWidgetFactory *factory = (VappWidgetFactory *)listEntry->get();

        VFX_ASSERT(factory);

        if (control && !control->isPermitted(factory->getSource()))
        {
            continue;
        }

        totalNum += factory->getTotalNum();
    }

    return totalNum;
}


VfxS32 VappWidgetKit::getAllId(
    VappWidgetId **id,
    VfxS32 size,
    const VappWidgetKitControl *control)
{
    VfxS32 totalNum = getTotalNum(control);
    VfxS32 originalSize, filledSize;

    VFX_ASSERT(id && size >= totalNum);

    originalSize = size;

    for (VfxObjListEntry *listEntry = m_factoryList.getHead();
         listEntry != NULL;
         listEntry = listEntry->getNext())
    {
        VappWidgetFactory *factory = (VappWidgetFactory *)listEntry->get();

        VFX_ASSERT(factory);

        if (control && !control->isPermitted(factory->getSource()))
        {
            continue;
        }

        filledSize = factory->getAllId(id, size);
        id += filledSize;
        size -= filledSize;
    }

    VFX_ASSERT(size >= 0);

    return originalSize - size;
}


VfxBool VappWidgetKit::isIdValid(
    const VappWidgetId &id,
    const VappWidgetKitControl *control)
{
    for (VfxObjListEntry *listEntry = m_factoryList.getHead();
         listEntry != NULL;
         listEntry = listEntry->getNext())
    {
        VappWidgetFactory *factory = (VappWidgetFactory *)listEntry->get();

        VFX_ASSERT(factory);

        if (control && !control->isPermitted(factory->getSource()))
        {
            continue;
        }

        if (factory->isValid(id))
        {
            return VFX_TRUE;
        }
    }

    return VFX_FALSE;
}


VfxS32 VappWidgetKit::getName(
    const VappWidgetId &id,
    VfxWChar *string,
    VfxS32 size)
{
    for (VfxObjListEntry *listEntry = m_factoryList.getHead();
         listEntry != NULL;
         listEntry = listEntry->getNext())
    {
        VappWidgetFactory *factory = (VappWidgetFactory *)listEntry->get();

        VFX_ASSERT(factory);

        if (id.getSource() == factory->getSource())
        {
            return factory->getName(id, string, size);
        }
    }

    return 0;
}


VappWidget *VappWidgetKit::createWidget(
    const VappWidgetId &id,
    VfxObject *parentObj)
{
    for (VfxObjListEntry *listEntry = m_factoryList.getHead();
         listEntry != NULL;
         listEntry = listEntry->getNext())
    {
        VappWidgetFactory *factory = (VappWidgetFactory *)listEntry->get();

        VFX_ASSERT(factory);

        if (id.getSource() == factory->getSource())
        {
            VappWidget *widget = factory->createWidget(id, parentObj);

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


VfxFrame *VappWidgetKit::createIcon(
    const VappWidgetId &id,
    VfxObject *parentObj)
{
    for (VfxObjListEntry *listEntry = m_factoryList.getHead();
         listEntry != NULL;
         listEntry = listEntry->getNext())
    {
        VappWidgetFactory *factory = (VappWidgetFactory *)listEntry->get();

        VFX_ASSERT(factory);

        if (id.getSource() == factory->getSource())
        {
            return factory->createIcon(id, parentObj);
        }
    }

    return NULL;
}


VfxS32 VappWidgetKit::getPreInstalledNum() const
{
    VfxS32 preInstalledNum = 0;

    for (VfxObjListEntry *listEntry = m_factoryList.getHead();
         listEntry != NULL;
         listEntry = listEntry->getNext())
    {
        VappWidgetFactory *factory = (VappWidgetFactory *)listEntry->get();

        VFX_ASSERT(factory);

        preInstalledNum += factory->getPreInstalledNum();
    }

    return preInstalledNum;
}


VfxS32 VappWidgetKit::getPreInstalledWidget(
    VappWidgetPreInstalled **preInstalled,
    VfxS32 size) const
{
    VfxS32 preInstalledNum = getPreInstalledNum();
    VfxS32 originalSize, filledSize;

    VFX_ASSERT(preInstalled && size >= preInstalledNum);

    originalSize = size;

    for (VfxObjListEntry *listEntry = m_factoryList.getHead();
         listEntry != NULL;
         listEntry = listEntry->getNext())
    {
        VappWidgetFactory *factory = (VappWidgetFactory *)listEntry->get();

        VFX_ASSERT(factory);

        filledSize = factory->getPreInstalledWidget(preInstalled, size);

        preInstalled += filledSize;
        size -= filledSize;
    }

    VFX_ASSERT(size >= 0);

    return originalSize - size;
}

#endif /* defined(__MMI_VUI_WIDGET_FACTORY__) */
