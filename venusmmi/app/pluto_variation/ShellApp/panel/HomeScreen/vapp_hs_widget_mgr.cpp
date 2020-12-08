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
 *  vapp_hs_widget_mgr.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file implements the widget manager.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN__

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vapp_hs_widget_base.h"
#include "vapp_hs_widget_cfg.h"
#include "vapp_hs_widget_mgr.h"
#include "trc/vadp_app_trc.h"
#include "vapp_hs_widget_delegator.h"
#include "vfx_cpp_base.h"
#include "vfx_datatype.h"
#include "vrt_datatype.h"
#include "vapp_hs_def.h"
#include "vfx_object.h"
#include "vapp_hs_cp.h"
#include "vfx_sys_memory.h"
#include "vfx_timer.h"
#include "vfx_basic_type.h"
#include "vfx_signal.h"
#include "vfx_frame.h"
#include "vfx_auto_animate.h"
#include "vfx_system.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"

#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "mmi_frm_mem_gprot.h"

#if defined(__MMI_GADGET_SUPPORT__)
#include "WgtMgrSrvGprot.h"
#include "WgtMgrSrvIprot.h"
#endif

#ifdef __cplusplus
}
#endif


/*****************************************************************************
 * Venus home widget creator (device widget)
 *****************************************************************************/

VappHsWidgetCreatorDevice::VappHsWidgetCreatorDevice() :
    m_id(NULL),
    m_count(0)
{
}


void VappHsWidgetCreatorDevice::loadSetting(void)
{
    VfxBool ret;

    ret = loadManagerSetting();
    if (ret)
    {
        return;
    }

    ret = loadDefaultSetting();
    if (ret)
    {
        return;
    }

    VFX_ASSERT(0);
}


VfxBool VappHsWidgetCreatorDevice::loadDefaultSetting(void)
{
    const vapp_hs_widget_cfg_struct *tbl = vapp_hs_get_widget_cfg_table();

    m_count = VAPP_HS_WIDGET_TOTAL;

    VFX_ASSERT(m_id == NULL);
    VFX_ALLOC_MEM(m_id, m_count * sizeof(VfxS32), this);

    for (VfxS32 i = 0; i < VAPP_HS_WIDGET_TOTAL; i++)
    {
        m_id[i] = tbl[i].id;
    }

    return VFX_TRUE;
}


VfxBool VappHsWidgetCreatorDevice::loadManagerSetting(void)
{
#if !defined(__MMI_GADGET_SUPPORT__)
    return VFX_FALSE;
#else
    srv_wgtmgr_wgt_list_struct *list = NULL;
    VfxS32 totalNum, idx, i;

    totalNum = srv_wgtmgr_get_enabled_wgt_num();
    if (totalNum <= 0)
    {
        return VFX_TRUE;
    }

    VFX_ALLOC_MEM(list, totalNum * sizeof(srv_wgtmgr_wgt_list_struct), this);

    srv_wgtmgr_get_enabled_wgt_list(list);

    for (i = 0; i < totalNum; i++)
    {
        if (list[i].type == SRV_WGTMGR_WGT_TYPE_PHONE)
        {
            ++m_count;
        }
    }

    if (m_count == 0)
    {
        VFX_FREE_MEM(list);
        return VFX_TRUE;
    }

    VFX_ASSERT(m_id == NULL);
    VFX_ALLOC_MEM(m_id, m_count * sizeof(VfxS32), this);

    idx = 0;

    for(i = 0; i < totalNum; i++)
    {
        if (list[i].type == SRV_WGTMGR_WGT_TYPE_PHONE)
        {
            m_id[idx++] = list[i].id;
        }
    }

    VFX_FREE_MEM(list);

    return VFX_TRUE;
#endif /* defined(__MMI_GADGET_SUPPORT__) */
}


void VappHsWidgetCreatorDevice::unloadSetting(void)
{
    if (m_id)
    {
        VFX_FREE_MEM(m_id);
    }
}


void VappHsWidgetCreatorDevice::onInit()
{
    VappHsWidgetCreator::onInit();

    loadSetting();
}


void VappHsWidgetCreatorDevice::onDeinit()
{
    unloadSetting();

    VappHsWidgetCreator::onDeinit();
}


VfxS32 VappHsWidgetCreatorDevice::getType()
{
    return VAPP_HS_WIDGET_TYPE_DEVICE;
}


VfxBool VappHsWidgetCreatorDevice::isValid(VfxS32 id)
{
    if (!m_id || !m_count)
    {
        return VFX_FALSE;   // All widgets are disable.
    }

    for (VfxS32 i = 0; i < m_count; i++)
    {
        if (m_id[i] == id)
        {
            return VFX_TRUE;
        }
    }

    return VFX_FALSE;
}


VfxBool VappHsWidgetCreatorDevice::create(
    VfxS32 id,
    VfxObject *parentObj,
    VappHsWidget *&widget,
    VappHsDndImage *&widgetIcon)
{
    const vapp_hs_widget_cfg_struct *tbl = vapp_hs_get_widget_cfg_table();
    VfxS32 i;

    for (i = 0; i < VAPP_HS_WIDGET_TOTAL; i++)
    {
        if (tbl[i].id == id)
        {
            break;
        }
    }

    if (i == VAPP_HS_WIDGET_TOTAL)
    {
        return VFX_FALSE; // id is invalid.
    }

    // Create the widget.
    VFX_ASSERT(tbl[i].create);
    widget = (VappHsWidget *)tbl[i].create(parentObj);

    // Create the Widget icon.
    VFX_OBJ_CREATE(widgetIcon, VappHsDndImage, parentObj);

    VfxBool isLiveIcon = widget->createIconView();

    if (isLiveIcon)
    {
        widgetIcon->setImageChild(widget->m_controlIcon);
    }
    else
    {
        widgetIcon->setImageId(widget->getIcon());
    }

    return VFX_TRUE;
}


VfxS32 VappHsWidgetCreatorDevice::getTotalNum()
{
    return m_count;
}


VfxS32 VappHsWidgetCreatorDevice::getAllId(VfxS32 *id, VfxS32 size)
{
    if (!m_id || !m_count)
    {
        return 0;   // All widgets are disable.
    }

    VFX_ASSERT(size >= m_count); // caller's buffer is too small.

    for (VfxS32 i = 0; i < m_count; i++)
    {
        id[i] = m_id[i];
    }

    return m_count;
}


#if defined(__MMI_GADGET_SUPPORT__)
/*****************************************************************************
 * Venus home widget creator (Google gadget)
 *****************************************************************************/

VappHsWidgetCreatorGadget::VappHsWidgetCreatorGadget() :
    m_id(NULL),
    m_count(0)
{
}


void VappHsWidgetCreatorGadget::onInit()
{
    srv_wgtmgr_wgt_list_struct *list = NULL;
    VfxS32 totalNum, idx, i;

    VappHsWidgetCreator::onInit();

    totalNum = srv_wgtmgr_get_enabled_wgt_num();
    if (totalNum <= 0)
    {
        return;
    }

    VFX_ALLOC_MEM(list, totalNum * sizeof(srv_wgtmgr_wgt_list_struct), this);

    srv_wgtmgr_get_enabled_wgt_list(list);

    for(i = 0; i < totalNum; i++)
    {
        if (list[i].type == SRV_WGTMGR_WGT_TYPE_DOWNLOADED)
        {
            ++m_count;
        }
    }

    if (m_count == 0)
    {
        VFX_FREE_MEM(list);
        return;
    }

    VFX_ASSERT(m_id == NULL);
    VFX_ALLOC_MEM(m_id, m_count * sizeof(VfxS32), this);

    idx = 0;

    for(i = 0; i < totalNum; i++)
    {
        if (list[i].type == SRV_WGTMGR_WGT_TYPE_DOWNLOADED)
        {
            m_id[idx++] = list[i].id;
        }
    }

    VFX_FREE_MEM(list);
}


void VappHsWidgetCreatorGadget::onDeinit()
{
    if (m_id)
    {
        VFX_FREE_MEM(m_id);
    }

    VappHsWidgetCreator::onDeinit();
}


VfxS32 VappHsWidgetCreatorGadget::getType()
{
    return VAPP_HS_WIDGET_TYPE_GADGET;
}


VfxBool VappHsWidgetCreatorGadget::isValid(VfxS32 id)
{
    if (!m_id || !m_count)
    {
        return VFX_FALSE;   // All gadgets are disable.
    }

    for (VfxS32 i = 0; i < m_count; i++)
    {
        if (m_id[i] == id)
        {
            return VFX_TRUE;
        }
    }

    return VFX_FALSE;
}


VfxBool VappHsWidgetCreatorGadget::create(
    VfxS32 id,
    VfxObject *parentObj,
    VappHsWidget *&widget,
    VappHsDndImage *&widgetIcon)
{
    if (isValid(id) == VFX_FALSE)
    {
        return VFX_FALSE; // id is invalid.
    }

    // Create the widget.
    widget = (VappHsWidget *)VappHsWidgetDelegator::createWidget(id, parentObj);

    // Create the Widget icon.
    VFX_OBJ_CREATE(widgetIcon, VappHsDndImage, parentObj);

    VfxBool isLiveIcon = widget->createIconView();

    if (isLiveIcon)
    {
        widgetIcon->setImageChild(widget->m_controlIcon);
    }
    else
    {
        widgetIcon->setImageId(widget->getIcon());
    }

    return VFX_TRUE;
}


VfxS32 VappHsWidgetCreatorGadget::getTotalNum()
{
    return m_count;
}


VfxS32 VappHsWidgetCreatorGadget::getAllId(VfxS32 *id, VfxS32 size)
{
    if (!m_id || !m_count)
    {
        return 0;   // All gadgets are disable.
    }

    VFX_ASSERT(size >= m_count); // caller's buffer is too small.

    for (VfxS32 i = 0; i < m_count; i++)
    {
        id[i] = m_id[i];
    }

    return m_count;
}

VfxS32 VappHsWidgetCreatorGadget::getPreInstalledNum() const
{
    return srv_wgtmgr_get_preload_widget_num();
}

VfxS32 VappHsWidgetCreatorGadget::getPreInstalledWidget(
		VfxS32 *id,
		VfxS32 *pageIdx,
		VfxS32 *posX,
		VfxS32 *posY,
		VfxS32 size) const
{

    srv_wgtmgt_preload_wgt_struct *preload_list = NULL;

    VfxS32 num = srv_wgtmgr_get_preload_widget_num();

    // There is no preload gadget existed.
    if (num == 0)
    {
        return 0;
    }

    VFX_ASSERT(id && pageIdx && posX && posY && size >= num);

    preload_list = (srv_wgtmgt_preload_wgt_struct*)mmi_frm_asm_alloc_anonymous_nc(num * sizeof(srv_wgtmgt_preload_wgt_struct));

    srv_wgtmgr_get_preload_widget_list(preload_list);

    // Copy ID to the buffer.
    for (VfxS32 i = 0; i < num; i++)
    {
        id[i] = preload_list[i].id;
        pageIdx[i] = preload_list[i].page;
        posX[i] = preload_list[i].x_pos;
        posY[i] = preload_list[i].y_pos;
    }

    mmi_frm_asm_free_anonymous(preload_list);

    return num;
}

#endif /* defined(__MMI_GADGET_SUPPORT__) */


/*****************************************************************************
 * Venus home widget manager
 *****************************************************************************/

// Delayed widget creation duration
#if !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
const VfxS32 VappHsWidgetMgr::s_createDelayedDuration = 80;
#else
const VfxS32 VappHsWidgetMgr::s_createDelayedDuration = 150;
#endif /* !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */

VfxBool VappHsWidgetMgr::s_isNvramLocked = VFX_FALSE;


VappHsWidgetMgr::VappHsWidgetMgr() :
    m_creatorDevice(NULL),
#if defined(__MMI_GADGET_SUPPORT__)
    m_creatorGadget(NULL),
#endif
    m_widget(NULL),
    m_widgetIcon(NULL),
    m_desktop(NULL),
    m_bar(NULL),
    m_numTotal(0),
    m_numInDesktopOnInit(0),
    m_curr(0),
    m_timerCreateWidget(NULL)
{
    for (VfxS32 i = 0; i < VAPP_HS_WIDGET_TYPE_TOTAL; i++)
    {
        m_creator[i] = NULL;
    }
}


void VappHsWidgetMgr::onInit()
{
    VfxObject::onInit();

    m_list.num = 0;
    m_list.first = NULL;
    m_list.last = NULL;
    m_list.curr = NULL;

    VFX_OBJ_CREATE(m_timerCreateWidget, VfxTimer, this);

    // Register creator here. The order can be changed. Make sure the size of
    // the array is large enough.
    VfxS32 idx = 0;

    VFX_OBJ_CREATE(m_creatorDevice, VappHsWidgetCreatorDevice, this);
    m_creator[idx++] = m_creatorDevice;

#if defined(__MMI_GADGET_SUPPORT__)
    VFX_OBJ_CREATE(m_creatorGadget, VappHsWidgetCreatorGadget, this);
    m_creator[idx++] = m_creatorGadget;
#endif /* defined(__MMI_GADGET_SUPPORT__) */
}


void VappHsWidgetMgr::onDeinit()
{
    if (m_widget)
    {
        VFX_FREE_MEM(m_widget);
    }

    if (m_widgetIcon)
    {
        VFX_FREE_MEM(m_widgetIcon);
    }

    VfxObject::onDeinit();
}

void VappHsWidgetMgr::listAppend(const SettingElement &elem)
{
    ListObj *obj;

    VFX_ALLOC_MEM(obj, sizeof(ListObj), this);

    obj->next = NULL;
    obj->elem = elem;

    if (!m_list.first)
    {
        // List is empty. Add this object as the first one.
        VFX_DEV_ASSERT(!m_list.last && m_list.num == 0);

        m_list.first = obj;
        m_list.last = obj;
    }
    else
    {
        // List isn't empty. Append this object to the list.
        VFX_ASSERT(m_list.last && m_list.num > 0);

        m_list.last->next = obj;
        m_list.last = obj;
    }

    ++m_list.num;
}


VfxBool VappHsWidgetMgr::listRemove(SettingElement &elem)
{
    ListObj *obj;

    if (!m_list.first)
    {
        VFX_DEV_ASSERT(!m_list.last && m_list.num == 0);

        return VFX_FALSE;
    }

    obj = m_list.first;

    if (m_list.first == m_list.last)
    {
        // List contains only one object. Remove this one.
        m_list.first = NULL;
        m_list.last = NULL;
    }
    else
    {
        // List contains more than one object. Remove the object from head.
        m_list.first = obj->next;
    }

    --m_list.num;

    elem = obj->elem;

    VFX_FREE_MEM(obj);

    return VFX_TRUE;
}


void VappHsWidgetMgr::listClear()
{
    SettingElement elem;

    while (listRemove(elem))
    {
        // do nothing.
    }
}


VfxS32 VappHsWidgetMgr::listGetNum()
{
    return m_list.num;
}


const VappHsWidgetMgr::SettingElement *VappHsWidgetMgr::listGetFirst()
{
    SettingElement *elem;

    if (!m_list.first)
    {
        return NULL;
    }

    elem = &(m_list.first->elem);
    m_list.curr = m_list.first->next;

    return elem;
}


const VappHsWidgetMgr::SettingElement *VappHsWidgetMgr::listGetNext()
{
    SettingElement *elem;

    if (!m_list.curr)
    {
        return NULL;
    }

    elem = &(m_list.curr->elem);
    m_list.curr = m_list.curr->next;

    return elem;
}


VfxBool VappHsWidgetMgr::listIsPresent(const SettingElement &elem)
{
    const SettingElement *ptr;

    // Traverse throught the list and check if the (type, id) couple is present.
    for (ptr = listGetFirst(); ptr; ptr = listGetNext())
    {
        if (ptr->type == elem.type && ptr->id == elem.id)
        {
            return VFX_TRUE;
        }
    }

    return VFX_FALSE;
}


VappHsWidgetCreator *VappHsWidgetMgr::getCreator(VfxS32 type)
{
    for (VfxS32 i = 0; i < VAPP_HS_WIDGET_TYPE_TOTAL; i++)
    {
        if (m_creator[i]->getType() == type)
        {
            return m_creator[i];
        }
    }

    return NULL;
}


VfxBool VappHsWidgetMgr::canBeHandled(VfxS32 type, VfxS32 id)
{
    VappHsWidgetCreator *creator = getCreator(type);

    if (!creator)
    {
        return VFX_FALSE;
    }

    return creator->isValid(id);
}


void VappHsWidgetMgr::addExtra()
{
    for (VfxS32 type = 0; type < VAPP_HS_WIDGET_TYPE_TOTAL; type++)
    {
        VappHsWidgetCreator *creator = m_creator[type];
        VfxS32 totalNum, num;
        VfxS32 *id;

        totalNum = creator->getTotalNum();
        if (totalNum == 0)
        {
            continue;
        }

        VFX_ALLOC_MEM(id, totalNum * sizeof(VfxS32), this);

        num = creator->getAllId(id, totalNum);

        for (VfxS32 i = 0; i < num; i++)
        {
            SettingElement elem;

            elem.type = type;
            elem.id = id[i];
            elem.x = 0; // dummy
            elem.y = 0; // dummy

            if (!listIsPresent(elem))
            {
                listAppend(elem);
            }
        }

        VFX_FREE_MEM(id);
    }
}


VfxBool VappHsWidgetMgr::initFromMem()
{
    const SettingHeader *header;
    const SettingElement *elem;
    VfxU8 *buf;

    buf = (VfxU8 *)mmi_malloc(NVRAM_EF_VENUS_HS_WIDGET_MGR_SIZE);

    header = (const SettingHeader *)
                readNvram(buf, NVRAM_EF_VENUS_HS_WIDGET_MGR_SIZE);

    if ((header->guardPattern != GUARD_PATTERN) ||
        (header->settingSize > NVRAM_EF_VENUS_HS_WIDGET_MGR_SIZE) ||
        (header->numTotal < header->numInDesktop))
    {
        mmi_mfree(buf);
        return VFX_FALSE;
    }

    listClear();

    elem = &(header->elem[0]);

    for (VfxS32 i = 0; i < header->numTotal; i++)
    {
        if (canBeHandled(elem[i].type, elem[i].id))
        {
            // If the (type, id) couple can be handled, add it to the list.
            listAppend(elem[i]);

            // Increase the 'in-bar' counter if necessary.
            if (i < header->numInDesktop)
            {
                ++m_numInDesktopOnInit;
            }
        }
    }

    // If memory is corrupted, some widget might be missed. Add such widget into
    // the widget bar.
    addExtra();

    mmi_mfree(buf);

    return VFX_TRUE;
}


void VappHsWidgetMgr::initPreInstalledWidget()
{
    vrt_size_struct screenSize;
    vrt_color_type_enum colorFormat;

    vrt_sys_get_main_screen_info(&screenSize, &colorFormat);

    for (VfxS32 type = 0; type < VAPP_HS_WIDGET_TYPE_TOTAL; type++)
    {
        VappHsWidgetCreator *creator = m_creator[type];

        VfxS32 size = creator->getPreInstalledNum();
        if (size == 0)
        {
            continue;
        }

        VfxS32 *id, *pageIdx, *x, *y;

        VFX_ALLOC_MEM(id, size * sizeof(VfxS32), this);
        VFX_ALLOC_MEM(pageIdx, size * sizeof(VfxS32), this);
        VFX_ALLOC_MEM(x, size * sizeof(VfxS32), this);
        VFX_ALLOC_MEM(y, size * sizeof(VfxS32), this);

        VfxS32 num = creator->getPreInstalledWidget(id, pageIdx, x, y, size);

        for (VfxS32 i = 0; i < num; i++)
        {
            SettingElement elem;

            elem.type = type;
            elem.id = id[i];
            elem.x = pageIdx[i] * screenSize.width + x[i];
            elem.y = y[i];

            if (!listIsPresent(elem))
            {
                listAppend(elem);
                ++m_numInDesktopOnInit;
            }
        }

        VFX_FREE_MEM(id);
        VFX_FREE_MEM(pageIdx);
        VFX_FREE_MEM(x);
        VFX_FREE_MEM(y);
    }

    addExtra();
}


void VappHsWidgetMgr::load()
{
    const SettingElement *ptr;
    VfxS32 idx;

    // Initialize the manager from the memory. If failed, initialize the manager
    // from the default configuration.
    if (!initFromMem())
    {
        initPreInstalledWidget();
    }

    // Create the pointer array for the shortcuts.
    m_numTotal = listGetNum();
    if (m_numTotal <= 0)
    {
        listClear();
        return;
    }

    // Make sure 'load' does not be called twice.
    VFX_ASSERT(!m_widget && !m_widgetIcon);

    VFX_ALLOC_MEM(m_widget, m_numTotal * sizeof(VappHsWidget *), this);
    VFX_ALLOC_MEM(m_widgetIcon, m_numTotal * sizeof(VappHsDndImage *), this);

    // Create all widgets.
    idx = 0;

    for (ptr = listGetFirst(); ptr; ptr = listGetNext())
    {
        VappHsWidgetCreator *creator = getCreator(ptr->type);
        VfxBool ret;

        ret = creator->create(ptr->id, this, m_widget[idx], m_widgetIcon[idx]);
        VFX_ASSERT(ret);

        // Set position for the widgets in the desktop.
        if (idx < m_numInDesktopOnInit)
        {
            VfxPoint p;
            p.x = ptr->x;
            p.y = ptr->y;

            m_widget[idx]->setPos(p);
        }

        ++idx;
    }

    listClear();
}


void VappHsWidgetMgr::bindWidgetBar(VappHsInteractiveImageArray *widgetBar)
{
    // Make sure this function does not be called twice.
    VFX_ASSERT(!m_bar && widgetBar);

    m_bar = widgetBar;

    // Should always call initImage to init the state of the widget bar even
    // if the number of widgets is 0 such that the state of widget bar can
    // be initialized.
    m_bar->initImage(
        m_numTotal - m_numInDesktopOnInit,
        m_widgetIcon + m_numInDesktopOnInit);
}


void VappHsWidgetMgr::bindDesktop(VappHsDesktop *desktop)
{
    // Make sure 'load' does not be called twice.
    VFX_ASSERT(!m_desktop && desktop);

    m_desktop = desktop;
}


void VappHsWidgetMgr::activateWidget(VfxBool isRedrawingBkScreens)
{
    // Make sure the manager has been binded with the widget bar and desktop.
    VFX_ASSERT(m_bar && m_desktop);

    // Add the widget to the desktop.
    for (VfxS32 i = 0; i < m_numInDesktopOnInit; i++)
    {
        m_desktop->addChildFrame(m_widget[i]);

        // Prevent the widget from being renderred or dragged before it is
        // created.
        m_widget[i]->setHidden(VFX_TRUE);
    }

    // If this is not the "small go back" case, start the timer for the
    // delayed widget creation mechanism. Otherwise, we shall create all the
    // widgets immediately for the background of "small go back".
    if (isRedrawingBkScreens)
    {
        createAllDelayedWidget();
    }
    else
    {
        m_timerCreateWidget->setStartDelay(s_createDelayedDuration);

        m_timerCreateWidget->m_signalTick.connect(
            this,
            &VappHsWidgetMgr::onTimerCreateWidget);

        // Emit immediately to create the top-most widget first.
        m_timerCreateWidget->m_signalTick.emit(m_timerCreateWidget);
    }

    s_isNvramLocked = VFX_FALSE;
}


void VappHsWidgetMgr::deactivateWidget()
{
    const VfxFrame *iter;
    VappHsWidget *widget;
    VappHsDndImage *widgetIcon;
    VfxS32 i;

    // Make sure the manager has been binded with the widget bar and desktop.
    VFX_ASSERT(m_bar && m_desktop);

    // Stop the timer if it still wants to create the widget.
    if (m_timerCreateWidget)
    {
        m_timerCreateWidget->stop();
    }

    // Move the widgets on the desktop to the front of the array such that it
    // can be activated again later.
    m_numInDesktopOnInit = 0;

    for (iter = m_desktop->getFirstChildFrame();
         iter != NULL;
         iter = iter->getNextFrame())
    {
        // skip non-widget frame
        for (i = 0; i < getTotalNum(); i++)
        {
            if (iter == m_widget[i])
            {
                break;
            }
        }

        if (i == getTotalNum())
        {
            continue; // this is a non-widget frame
        }

        // Switch the position of this widget to the front of the widget array.
        widget = m_widget[m_numInDesktopOnInit];
        m_widget[m_numInDesktopOnInit] = m_widget[i];
        m_widget[i] = widget;

        widgetIcon = m_widgetIcon[m_numInDesktopOnInit];
        m_widgetIcon[m_numInDesktopOnInit] = m_widgetIcon[i];
        m_widgetIcon[i] = widgetIcon;

        ++m_numInDesktopOnInit;
    }

    // Release view and remove from parent frame such that it will not be
    // renderred. (Do this for all widgets for fail-safe.)
    for (i = 0; i < m_numTotal; i++)
    {
        // Notify the widget that it will be removed from the desktop. This is
        // applied to the widget that is on the desktop and is created.
        if (i < m_numInDesktopOnInit && m_widget[i]->isCreated())
        {
            m_desktop->removeWidget(m_widget[i]); // widget on the desktop
        }
        else
        {
            m_widget[i]->removeFromParentFrame(); // otherwise
        }

        m_widget[i]->releaseView();
    }
}


void VappHsWidgetMgr::createAllDelayedWidget()
{
    for (VfxS32 i = m_numInDesktopOnInit - 1; i >= 0; i--)
    {
    #if defined(__MMI_GADGET_SUPPORT__)
        // Loading gadget needs some processing time. In "small screen go back"
        // case, we do not create gadget's view.
        if (m_widget[i]->getType() == VAPP_HS_WIDGET_TYPE_GADGET)
        {
            continue; // Skip gadgets.
        }
    #endif /* defined(__MMI_GADGET_SUPPORT__) */

        // TODO: the story of 0.9f
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);

        m_widget[i]->createView();
        m_widget[i]->setHidden(VFX_FALSE);
        m_widget[i]->setOpacity(0.9f);
        m_widget[i]->setOpacity(1.0f);

        VfxAutoAnimate::commit();

        // Add to the desktop formally.
        m_desktop->addWidgetFromHistory(m_widget[i]);
    }
}


void VappHsWidgetMgr::onTimerCreateWidget(VfxTimer *timer)
{
    VFX_LOG(VFX_STATE, VAPP_HS_ON_TIMER_CREATE_WIDGET_MSG, 0, -1);

    for (VfxS32 i = m_numInDesktopOnInit - 1; i >= 0; i--)
    {
        if (!m_widget[i]->isCreated())
        {
            VFX_LOG(VFX_STATE, VAPP_HS_ON_TIMER_CREATE_WIDGET_MSG, 1, i);

            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE);
           
            m_widget[i]->createView();
            m_widget[i]->setHidden(VFX_FALSE);

        #if !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
            m_widget[i]->setOpacity(0.0f);
        #endif

            VfxAutoAnimate::commit();

        #if !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
            m_widget[i]->setOpacity(1.0f);
        #endif

            // Add to the desktop formally.
            m_desktop->addWidgetFromHistory(m_widget[i]);

            // Start the timer to create the next widget later.
            timer->start();

            return;
        }
    }

    // To avoid from the complication that the user drags a widget to the 
    // desktop during the creation period, after all the widgets are created,
    // update the NVRAM.
    serializeToNvram();
    
    VFX_LOG(VFX_STATE, VAPP_HS_ON_TIMER_CREATE_WIDGET_MSG, 2, -1);
}


VfxU8 *VappHsWidgetMgr::readNvram(VfxU8 *buf, VfxS16 size)
{
    VfxS16 error;

    VFX_ASSERT(size >= NVRAM_EF_VENUS_HS_WIDGET_MGR_SIZE);

    // Read setting from NVRAM.
    ReadRecord(
        NVRAM_EF_VENUS_HS_WIDGET_MGR_LID,
        1,
        buf,
        NVRAM_EF_VENUS_HS_WIDGET_MGR_SIZE,
        &error);
    VFX_ASSERT(error == NVRAM_READ_SUCCESS);

    return buf;
}


void VappHsWidgetMgr::writeNvram(VfxU8 *buf, VfxS16 size)
{
    VfxS16 error;

    // Make sure NVRAM size is large enough.
    VFX_ASSERT(size > 0 && size <= NVRAM_EF_VENUS_HS_WIDGET_MGR_SIZE);

    // Write setting to NVRAM.
    // TODO: size of 'mem' might be smaller than LID size.
    WriteRecord(
        NVRAM_EF_VENUS_HS_WIDGET_MGR_LID,
        1,
        buf,
        NVRAM_EF_VENUS_HS_WIDGET_MGR_SIZE,
        &error);
    VFX_ASSERT(error == NVRAM_WRITE_SUCCESS);
}


VfxBool VappHsWidgetMgr::isStateReliable()
{
    VfxFrame *iter;
    VfxS32 count = 0;

    // In desktop widget.
    for (iter = m_desktop->getFirstChildFrame();
         iter != NULL;
         iter = iter->getNextFrame())
    {
        for (VfxS32 j = getTotalNum() - 1; j >= 0; j--)
        {
            if (iter == m_widget[j])        // m_widget: full view array
            {
                ++count;
                break;  // check the next frame in the desktop
            }
        }
    }

    if (m_numTotal == m_bar->getImageNumber() + count)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


VfxS32 VappHsWidgetMgr::getRequiredMemSize()
{
    VfxU32 size;

    // Header
    size = sizeof(SettingHeader);

    // Body if it is present.
    if (m_numTotal >= 0)
    {
        size += sizeof(SettingElement) * (m_numTotal - 1);
    }

    // Round to 4N
    size = ((size + 3) >> 2) << 2;

    return size;
}


VfxBool VappHsWidgetMgr::serializeToMem(SettingHeader *&header, VfxS32 &size)
{
    SettingElement *elem;
    VfxFrame *iter;
    VappHsDndImage **ptr;
    VfxS32 i, idx = 0;

    if (!isStateReliable() || s_isNvramLocked)
    {
        return VFX_FALSE;
    }

    size = getRequiredMemSize();
    VFX_ALLOC_MEM(header, size, this);

    // Write headers to the memory.
    header->guardPattern = GUARD_PATTERN;
    header->settingSize = getRequiredMemSize();
    header->numTotal = m_numTotal;
    header->numInDesktop = m_numTotal - m_bar->getImageNumber();

    // Write element to the memory.
    elem = &(header->elem[0]);

    // Collect the widgets in the desktop.
    for (iter = m_desktop->getFirstChildFrame();
         iter != NULL;
         iter = iter->getNextFrame())
    {
        for (VfxS32 j = getTotalNum() - 1; j >= 0; j--)
        {
            if (iter == m_widget[j])        // m_widget: full view array
            {
                elem[idx].id    = m_widget[j]->getId();
                elem[idx].type  = m_widget[j]->getType();
                elem[idx].x     = m_widget[j]->getPos().x;
                elem[idx].y     = m_widget[j]->getPos().y;
                ++idx;

                break;  // check the next frame in the desktop
            }
        }
    }

    // Collect the widgets in the widget bar.
    ptr = (VappHsDndImage **)m_bar->getImageArray();

    for (i = 0; i < m_bar->getImageNumber(); i++)
    {
        for (VfxS32 j = getTotalNum() - 1; j >= 0; j--)
        {
            if (ptr[i] == m_widgetIcon[j])
            {
                elem[idx].id    = m_widget[j]->getId();
                elem[idx].type  = m_widget[j]->getType();
                elem[idx].x     = 0; // dummy
                elem[idx].y     = 0; // dummy
                ++idx;

                break; // check the next widget icon in the widget bar
            }
        }
    }

    return VFX_TRUE;
}


VfxBool VappHsWidgetMgr::serializeToNvram()
{
    SettingHeader *header;
    VfxS32 size;
    VfxBool ret;

    ret = serializeToMem(header, size);
    if (ret)
    {
        // Success. Write to NVRAM.
        writeNvram((VfxU8 *)header, size);

        // Header is only allocated when ret is VFX_TRUE.
        VFX_FREE_MEM(header);
    }

    return ret;
}


VfxBool VappHsWidgetMgr::dismissWidget(
    VfxS32 type,
    VfxBool compareID,
    VfxS32 id)
{
    SettingHeader *header;
    SettingElement *elem;
    VfxU8 *buf;

    buf = (VfxU8 *)mmi_malloc(NVRAM_EF_VENUS_HS_WIDGET_MGR_SIZE);

    header = (SettingHeader *)readNvram(buf, NVRAM_EF_VENUS_HS_WIDGET_MGR_SIZE);

    if ((header->guardPattern != GUARD_PATTERN) ||
        (header->settingSize > NVRAM_EF_VENUS_HS_WIDGET_MGR_SIZE) ||
        (header->numTotal < header->numInDesktop))
    {
        mmi_mfree(buf);
        return VFX_FALSE;
    }

    elem = &(header->elem[0]);

    for (VfxS32 i = 0; i < header->numInDesktop; i++)
    {
        // To put the widget back to the widget bar, we corrupt the setting of
        // this widget such that it will not be loaded successfully next time.
        if ((elem[i].type == type) &&
            (!compareID || elem[i].id == id))
        {
            elem[i].type = VAPP_HS_WIDGET_TYPE_INVALID; /* discard */
        }
    }

    writeNvram(buf, NVRAM_EF_VENUS_HS_WIDGET_MGR_SIZE);
    s_isNvramLocked = VFX_TRUE;

    mmi_mfree(buf);

    return VFX_TRUE;
}


VfxS32 VappHsWidgetMgr::getTotalNum()
{
    return m_numTotal;
}


VappHsWidget *VappHsWidgetMgr::get(VfxS32 idx)
{
    if (!m_widget)
    {
        return NULL;
    }

    VFX_ASSERT(idx >= 0 && idx < m_numTotal);

    return m_widget[idx];
}


VappHsDndImage *VappHsWidgetMgr::getIcon(VfxS32 idx)
{
    if (!m_widgetIcon)
    {
        return NULL;
    }

    VFX_ASSERT(idx >= 0 && idx < m_numTotal);

    return m_widgetIcon[idx];
}


VappHsWidget *VappHsWidgetMgr::getFirst()
{
    if (!m_widget)
    {
        return NULL;
    }

    m_curr = 0;

    return m_widget[m_curr++];
}


VappHsWidget *VappHsWidgetMgr::getNext()
{
    if (!m_widget || m_curr >= m_numTotal)
    {
        return NULL;
    }

    return m_widget[m_curr++];
}


VappHsDndImage *VappHsWidgetMgr::getFirstIcon()
{
    if (!m_widgetIcon)
    {
        return NULL;
    }

    m_curr = 0;

    return m_widgetIcon[m_curr++];
}


VappHsDndImage *VappHsWidgetMgr::getNextIcon()
{
    if (!m_widgetIcon || m_curr >= m_numTotal)
    {
        return NULL;
    }

    return m_widgetIcon[m_curr++];
}

#endif /* __MMI_VUI_HOMESCREEN__ */

