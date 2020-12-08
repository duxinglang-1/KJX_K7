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
 *  vapp_hs_shortcut_mgr.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file implements the shortcut manager.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vrt_datatype.h"
#include "vfx_string.h"
#include "vapp_hs_def.h"
#include "vapp_hs_cp.h"
#include "vapp_hs_shortcut_cfg.h"
#include "vapp_hs_shortcut_mgr.h"
#include "HomeScreen\vadp_v2p_hs.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "kal_general_types.h"
#include "kal_public_api.h"

#include "mmi_frm_nvram_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "nvram_common_defs.h"

#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Venus home screen shortcut (base class)
 *****************************************************************************/

VappHsShortcut::VappHsShortcut()
{
}


VfxS32 VappHsShortcut::getType()
{
    return onGetType();
}


VfxS32 VappHsShortcut::getId()
{
    return onGetId();
}


void VappHsShortcut::launch()
{
    // TODO: add trace.
    onLaunch();
}


/***************************************************************************** 
 * Venus home screen shortcut (device shortcut)
 *****************************************************************************/

VappHsShortcutDevice::VappHsShortcutDevice(VfxS32 id) :
    m_id(id)
{
}


VfxS32 VappHsShortcutDevice::onGetType()
{
    return VAPP_HS_SHORTCUT_TYPE_DEVICE;
}


VfxS32 VappHsShortcutDevice::onGetId()
{
    return m_id;
}


void VappHsShortcutDevice::onLaunch()
{
    const VappHsShortcutCfg *tbl = VappHsGetShortcutCfgTable();

    // Find the corresponding entry in the shortcut configuration table. Call
    // the callback of the corresponding entry.
    for (VfxS32 i = 0; tbl[i].iconId != 0; i++)
    {
        if (tbl[i].iconId == m_id && tbl[i].cbf)
        {
            tbl[i].cbf();
            break;
        }
    }
}


#ifdef __MRE_AM__
/***************************************************************************** 
 * Venus home screen shortcut (VRE shortcut)
 *****************************************************************************/

VappHsShortcutVam::VappHsShortcutVam(VfxS32 id) :
    m_id(id)
{
}


VfxS32 VappHsShortcutVam::onGetType()
{
    return VAPP_HS_SHORTCUT_TYPE_VAM;
}


VfxS32 VappHsShortcutVam::onGetId()
{
    return m_id;
}


void VappHsShortcutVam::onLaunch()
{
    vadp_v2p_hs_am_launch_shortcut(m_id);
}
#endif /* __MRE_AM__ */


/***************************************************************************** 
 * Venus home screen shortcut creator (base class)
 *****************************************************************************/

VappHsShortcutCreator::VappHsShortcutCreator()
{
}


VfxS32 VappHsShortcutCreator::getType()
{
    return onGetType();
}


VfxBool VappHsShortcutCreator::isValid(VfxS32 id)
{
    return onIsValid(id);
}


VappHsShortcut *VappHsShortcutCreator::create(VfxS32 id, VfxObject *owner)
{
    return onCreate(id, owner);
}


VfxS32 VappHsShortcutCreator::getTotalNum()
{
    return onGetTotalNum();
}


VfxS32 VappHsShortcutCreator::getAllId(VfxS32 *id, VfxS32 size)
{
    return onGetAllId(id, size);
}


/***************************************************************************** 
 * Venus home screen shortcut creator (device shortcut)
 *****************************************************************************/

VappHsShortcutCreatorDevice::VappHsShortcutCreatorDevice()
{
}


VfxS32 VappHsShortcutCreatorDevice::onGetType()
{
    return VAPP_HS_SHORTCUT_TYPE_DEVICE;
}


VfxBool VappHsShortcutCreatorDevice::onIsValid(VfxS32 id)
{
    const VappHsShortcutCfg *tbl = VappHsGetShortcutCfgTable();

    // Check if 'id' is present as an icon ID in the device configuration
    // table. If yes, 'id' is valid; otherwise, 'id' is invalid.
    for (VfxS32 i = 0; tbl[i].iconId != 0; i++)
    {
        if (tbl[i].iconId == id)
        {
            return VFX_TRUE;
        }
    }
    
    return VFX_FALSE;
}


VappHsShortcut *VappHsShortcutCreatorDevice::onCreate(VfxS32 id, VfxObject *owner)
{
    VappHsShortcutDevice *shortcut;
    
    VFX_OBJ_CREATE_EX(shortcut, VappHsShortcutDevice, owner, (id));

    shortcut->setImageId(id);

    return shortcut;
}


VfxS32 VappHsShortcutCreatorDevice::onGetTotalNum()
{
    const VappHsShortcutCfg *tbl = VappHsGetShortcutCfgTable();
    VfxS32 i;

    for (i = 0; tbl[i].iconId != 0; i++)
    {
        // do nothing.
    }
    
    return i;
}


VfxS32 VappHsShortcutCreatorDevice::onGetAllId(VfxS32 *id, VfxS32 size)
{
    const VappHsShortcutCfg *tbl = VappHsGetShortcutCfgTable();
    VfxS32 totalNum;

    totalNum = onGetTotalNum();
    
    VFX_ASSERT(size >= totalNum); // caller's buffer is too small.

    for (VfxS32 i = 0; i < totalNum; i++)
    {
        id[i] = tbl[i].iconId;
    }

    return totalNum;
}


#ifdef __MRE_AM__
/***************************************************************************** 
 * Venus home screen shortcut creator (VRE shortcut)
 *****************************************************************************/

VappHsShortcutCreatorVam::VappHsShortcutCreatorVam() :
    m_num(0),
    m_id(NULL)
{
    // Do nothing.
}


void VappHsShortcutCreatorVam::onInit()
{
    VappHsShortcutCreator::onInit();

    // Get total number of VRE shortcuts on the home screen.
    m_num = vadp_v2p_hs_am_get_shortcut_number();

    // Get the id of all VRE shortcuts on the home screen.
    if (m_num > 0)
    {
        VFX_ALLOC_MEM(m_id, m_num * sizeof(VfxS32), this);
        vadp_v2p_hs_am_get_all_shortcut_id(m_id, m_num);
    }
}


void VappHsShortcutCreatorVam::onDeinit()
{
    if (m_id)
    {
        VFX_FREE_MEM(m_id);
    }

    VappHsShortcutCreator::onDeinit();
}


VfxS32 VappHsShortcutCreatorVam::onGetType()
{
    return VAPP_HS_SHORTCUT_TYPE_VAM;
}


VfxBool VappHsShortcutCreatorVam::onIsValid(VfxS32 id)
{
    // If true, it means there is no VRE shortcut on the home screen.
    if (!m_id || !m_num)
    {
        return VFX_FALSE;
    }

    // Check if the 'id' corresponds to some VRE shortcut on the home screen.
    for (VfxS32 i = 0; i < m_num; i++)
    {
        if (m_id[i] == id)
        {
            return VFX_TRUE;
        }
    }

    return VFX_FALSE;
}


VappHsShortcut *VappHsShortcutCreatorVam::onCreate(VfxS32 id, VfxObject *owner)
{
    VappHsShortcutVam *shortcut;
    VfxWChar filename[VADP_V2P_HS_VAM_MAX_ICON_FILE_NAME_SIZE];

    // If this 'id' of VRE shortcut cannot be created, return NULL.
    if (!onIsValid(id))
    {
        return NULL;
    }

    // Create the VRE shortcut.
    VFX_OBJ_CREATE_EX(shortcut, VappHsShortcutVam, owner, (id));

    // Get icon image path for the image source.
    vadp_v2p_hs_am_get_shortcut_icon(
        id, 
        filename, 
        VADP_V2P_HS_VAM_MAX_ICON_FILE_NAME_SIZE); 

    shortcut->setImageSrc(VFX_WSTR_MEM(filename));

    return shortcut;
}


VfxS32 VappHsShortcutCreatorVam::onGetTotalNum()
{
    return m_num;
}


VfxS32 VappHsShortcutCreatorVam::onGetAllId(VfxS32 *id, VfxS32 size)
{
    // If true, it means there is no VRE shortcut on the home screen.
    if (!m_id || !m_num)
    {
        return 0;
    }

    VFX_ASSERT(size >= m_num);

    vfx_sys_mem_copy(id, m_id, m_num * sizeof(VfxS32));

    return m_num;
}
#endif /* __MRE_AM__ */


/***************************************************************************** 
 * Venus home screen shortcut manager
 *****************************************************************************/

VappHsShortcutMgr::VappHsShortcutMgr() :
    m_shortcut(NULL),
    m_bar(NULL),
    m_pool(NULL),
    m_numTotal(0),
    m_numInBarOnInit(0),
    m_curr(0)
{
}


void VappHsShortcutMgr::onInit()
{
    VfxObject::onInit();
    
    m_list.num = 0;
    m_list.first = NULL;
    m_list.last = NULL;
    m_list.curr = NULL;

    // Register creator here. The order can be changed. Make sure the size of 
    // the array is large enough.
    VfxS32 idx = 0;

    VFX_OBJ_CREATE(m_creator[idx], VappHsShortcutCreatorDevice, this);
    
#ifdef __MRE_AM__
    idx++;
    VFX_OBJ_CREATE(m_creator[idx], VappHsShortcutCreatorVam, this);
#endif
}


void VappHsShortcutMgr::onDeinit()
{
    if (m_shortcut)
    {
        VFX_FREE_MEM(m_shortcut);
    }

    VfxObject::onDeinit();
}


void VappHsShortcutMgr::listAppend(const SettingElement &elem)
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


VfxBool VappHsShortcutMgr::listRemove(SettingElement &elem)
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


void VappHsShortcutMgr::listClear()
{
    SettingElement elem;
    
    while (listRemove(elem))
    {
        // do nothing.
    }
}


VfxS32 VappHsShortcutMgr::listGetNum()
{
    return m_list.num;
}


const VappHsShortcutMgr::SettingElement *VappHsShortcutMgr::listGetFirst()
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


const VappHsShortcutMgr::SettingElement *VappHsShortcutMgr::listGetNext()
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


VfxBool VappHsShortcutMgr::listIsPresent(const SettingElement &elem)
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


VappHsShortcutCreator *VappHsShortcutMgr::getCreator(VfxS32 type)
{
    for (VfxS32 i = 0; i < VAPP_HS_SHORTCUT_TYPE_TOTAL; i++)
    {
        if (m_creator[i]->getType() == type)
        {
            return m_creator[i];
        }
    }
    
    return NULL;
}


VfxBool VappHsShortcutMgr::canBeHandled(VfxS32 type, VfxS32 id)
{
    VappHsShortcutCreator *creator = getCreator(type);

    // If we cannot find this type of creator, return NULL.
    if (!creator)
    {
        return VFX_FALSE;
    }

    // Check if this creator can handle this id.
    return creator->isValid(id);
}


VfxBool VappHsShortcutMgr::addExtra()
{
    VfxBool isDeviceShortcutAdded = VFX_FALSE;

    for (VfxS32 type = 0; type < VAPP_HS_SHORTCUT_TYPE_TOTAL; type++)
    {
        VappHsShortcutCreator *creator = m_creator[type];
        VfxS32 num;
        VfxS32 *id;

        num = creator->getTotalNum();

        if (num == 0)
        {
            continue;
        }

        VFX_ALLOC_MEM(id, num * sizeof(VfxS32), this);

        creator->getAllId(id, num);
        
        for (VfxS32 i = 0; i < num; i++)
        {
            SettingElement elem;

            elem.type = type;
            elem.id = id[i];
            
            if (!listIsPresent(elem))
            {
                listAppend(elem);

                if (type == VAPP_HS_SHORTCUT_TYPE_DEVICE)
                {
                    isDeviceShortcutAdded = VFX_TRUE;
                }
            }
        }

        VFX_FREE_MEM(id);
    }

    return isDeviceShortcutAdded;
}


VfxBool VappHsShortcutMgr::initFromDefault()
{
    const VappHsShortcutCfg *tbl = VappHsGetShortcutCfgTable();
    SettingElement elem;
    VfxS32 i;

    listClear();

    elem.type = VAPP_HS_SHORTCUT_TYPE_DEVICE;
    m_numInBarOnInit = 0;
    
    for (i = 0; tbl[i].iconId != 0; i++)
    {
        if ((tbl[i].option & VAPP_HS_SHORTCUT_OPTION_IN_BAR))
        {
            elem.id = tbl[i].iconId;
            listAppend(elem);

            ++m_numInBarOnInit;
        }
    }

    for (i = 0; tbl[i].iconId != 0; i++)
    {
        if (!(tbl[i].option & VAPP_HS_SHORTCUT_OPTION_IN_BAR))
        {
            elem.id = tbl[i].iconId;
            listAppend(elem);
        }
    }

    return VFX_TRUE;
}


VfxBool VappHsShortcutMgr::initFromMem()
{
    const SettingHeader *header;
    const SettingElement *elem;
    VfxS16 size;
    
    header = (const SettingHeader *)readNvram(size);

    if ((header->guardPattern != GUARD_PATTERN) || 
        (header->settingSize > size) ||
        (header->numTotal < header->numInBar))
    {
        OslMfree((void *)header);
        return VFX_FALSE;
    }

    listClear();

    elem = &(header->elem[0]);
    m_numInBarOnInit = 0;
    
    for (VfxS32 i = 0; i < header->numTotal; i++)
    {
        if (canBeHandled(elem[i].type, elem[i].id))
        {
            // If the (type, id) couple can be handled, add it to the list.
            listAppend(elem[i]);

            // Increase the 'in-bar' counter if necessary.
            if (i < header->numInBar)
            {
                ++m_numInBarOnInit;
            }
        }
    }

    OslMfree((void *)header);

    // If device shortcut is added, it means the memory is corrupted.  In this
    // case, initialize the shortcut from the default setting. Note that it is
    // normal that a non-device shortcut is added, e.g. VRE shortcut.
    VfxBool isDeviceShortcutAdded = addExtra();

    if (!isDeviceShortcutAdded)
    {
        return VFX_TRUE;    // NVRAM is not corrupted.
    }
    else
    {
        listClear();
        return VFX_FALSE;   // NVRAM is corrupted. Use default setting.
    }
}


VfxU8 *VappHsShortcutMgr::readNvram(VfxS16 &size)
{
    VfxU8 *mem;
    VfxS16 error;
    
    size = NVRAM_EF_VENUS_HS_SHORTCUT_MGR_SIZE;

    mem = (VfxU8 *)OslMalloc(NVRAM_EF_VENUS_HS_SHORTCUT_MGR_SIZE);
    
    // Read setting from NVRAM.
    ReadRecord(
        NVRAM_EF_VENUS_HS_SHORTCUT_MGR_LID, 
        1, 
        mem, 
        NVRAM_EF_VENUS_HS_SHORTCUT_MGR_SIZE, 
        &error);
    VFX_ASSERT(error == NVRAM_READ_SUCCESS);

    return mem;
}


void VappHsShortcutMgr::writeNvram(VfxU8 *mem, VfxS16 size)
{
    VfxS16 error;
    
    // Make sure NVRAM size is large enough.
    VFX_ASSERT(size > 0 && size <= NVRAM_EF_VENUS_HS_SHORTCUT_MGR_SIZE);

    // Write setting to NVRAM.
    // TODO: size of 'mem' might be smaller than LID size.
    WriteRecord(
        NVRAM_EF_VENUS_HS_SHORTCUT_MGR_LID,
        1,
        mem,
        NVRAM_EF_VENUS_HS_SHORTCUT_MGR_SIZE,
        &error);
    VFX_ASSERT(error == NVRAM_WRITE_SUCCESS);
}


VfxBool VappHsShortcutMgr::load()
{
    const SettingElement *ptr;

    // Initialize the manager from the memory. If failed, initialize the manager
    // from the device default shortcut configuration table.
    if (!initFromMem())
    {
        // Memory is corrupted. Init the setting from the default configuration.
        initFromDefault();

        // Additional shortcuts might also been configured (MAUI_02334499).
        addExtra();
    }

    // Create the pointer array for the shortcuts.
    m_numTotal = listGetNum();

    VFX_ALLOC_MEM(m_shortcut, m_numTotal * sizeof(VappHsShortcut *), this);

    // Create all shortcuts.
    VfxS32 idx = 0;
    
    for (ptr = listGetFirst(); ptr; ptr = listGetNext())
    {
        VappHsShortcutCreator *creator = getCreator(ptr->type);
        m_shortcut[idx++] = creator->create(ptr->id, this);
    }

    listClear();

    return VFX_TRUE;
}


void VappHsShortcutMgr::bind(
        VappHsInteractiveImageArray *bar,
        VappHsInteractiveImageArray *pool)
{
    VFX_ASSERT(m_shortcut);     // please init the manager first.
    VFX_ASSERT(bar && pool);    // bar and pool cannot be NULL.
    
    m_bar = bar;
    m_pool = pool;

    // Initialize the shortcut bar.
    m_bar->initImage(m_numInBarOnInit, (VappHsDndImage **)m_shortcut);

    // Initialize the shortcut pool.
    m_pool->initImage(
        m_numTotal - m_numInBarOnInit, 
        (VappHsDndImage **)(m_shortcut + m_numInBarOnInit));
}


VfxBool VappHsShortcutMgr::isStateReliable()
{
    if (m_numTotal == m_bar->getImageNumber() + m_pool->getImageNumber())
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


VfxS32 VappHsShortcutMgr::getRequiredMemSize()
{
    VfxU32 size;

    // Header
    size = sizeof(SettingHeader);

    // Body
    size += sizeof(SettingElement) * (m_numTotal - 1);

    // Round to 4N
    size = ((size + 3) >> 2) << 2;
    
    return size; 
}


VfxBool VappHsShortcutMgr::serializeToNvram()
{
    SettingHeader *header;
    SettingElement *elem;
    VappHsShortcut **ptr;
    VfxS32 i, size, idx = 0;

    if (!isStateReliable())
    {
        return VFX_FALSE;
    }

    size = getRequiredMemSize();
    header = (SettingHeader *)OslMalloc(size);
    
    // Write headers to the memory.
    header->guardPattern = GUARD_PATTERN;
    header->settingSize = getRequiredMemSize();
    header->numTotal = m_numTotal;
    header->numInBar = m_bar->getImageNumber();

    // Write element to the memory.
    elem = &(header->elem[0]);

    ptr = (VappHsShortcut **)m_bar->getImageArray();

    for (i = 0; i < m_bar->getImageNumber(); i++)
    {
        elem[idx].type = ptr[i]->getType();
        elem[idx].id   = ptr[i]->getId();
        ++idx;
    }

    ptr = (VappHsShortcut **)m_pool->getImageArray();
    
    for (i = 0; i < m_pool->getImageNumber(); i++)
    {
        elem[idx].type = ptr[i]->getType();
        elem[idx].id   = ptr[i]->getId();
        ++idx;
    }

    writeNvram((VfxU8 *)header, size);
    OslMfree(header);

    return VFX_TRUE;
}


VfxS32 VappHsShortcutMgr::getTotalNum()
{
    return m_numTotal;
}


VappHsShortcut *VappHsShortcutMgr::getFirst()
{
    if (!m_shortcut)
    {
        return NULL;
    }
    
    m_curr = 0;
    
    return m_shortcut[m_curr++];
}


VappHsShortcut *VappHsShortcutMgr::getNext()
{
    if (!m_shortcut || m_curr >= m_numTotal)
    {
        return NULL;
    }

    return m_shortcut[m_curr++];
}

#endif /* __MMI_VUI_HOMESCREEN__ */

