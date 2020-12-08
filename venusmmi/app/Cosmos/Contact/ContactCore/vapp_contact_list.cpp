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
 *  vapp_contact_list.cpp
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
#include "MMI_features.h"

#include "vapp_contact_storage.h"
#include "vapp_contact_setting.h"
#include "vapp_contact_list.h"
#include "vapp_contact_util.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "PhbSrvGprot.h"

#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Class ContactList
 *****************************************************************************/ 
void ContactList::onInit()
{
    VfxObject::onInit();
    // reset storage mask
    m_storageMask = 0;

    // async query
    m_async = VFX_FALSE;
    m_sendSignal = VFX_FALSE;

    // config contact field
    m_contactField = srv_phb_create_contact_filter();
    srv_phb_contact_filter_set_storage(m_contactField, srv_phb_get_storage_mask());
    m_storageMask = srv_phb_get_storage_mask();
    srv_phb_contact_filter_set_field(m_contactField, MMI_PHB_CONTACT_FIELD_EXIST);
    srv_phb_contact_filter_set_query(m_contactField, NULL, MMI_PHB_CONTACT_FIELD_NAME, SRV_PHB_QUERY_TYPE_PARTIAL);

    // async query
    srv_phb_contact_filter_set_query_entry(m_contactField, &ContactList::onQueryCallback, 0, SRV_PHB_QUERY_MAX_TIME, getObjHandle());
    m_async = VFX_TRUE;
    //srv_phb_contact_filter_set_query_entry(m_contactField, &ContactList::onQueryCallback, 0, 5, this);
    // asm memory entry
    srv_phb_contact_filter_set_mem_entry(m_contactField, &ContactList::memAllocator, &ContactList::memDeallocator, getObjHandle());

    // asm memory manage
    m_queryMemManage = NULL;
    VFX_OBJ_CREATE(m_queryMemManage, VappContactQueryManage, this);

    // config list handle
    m_req.alpha_table = MMI_TRUE;
    m_req.item_order = MMI_FALSE;
    m_req.align_field = MMI_PHB_CONTACT_FIELD_NAME;
    m_req.filter = m_contactField;

    // get list
    updateList();

    // list changed event
    GET_CONTACT_TASK()->m_signalTask.connect(this, &ContactList::onListChanged);
}


void ContactList::onDeinit()
{
    srv_phb_free_query_entry(m_contactField, m_handle);

    VFX_OBJ_CLOSE(m_queryMemManage);

    VfxObject::onDeinit();

    /*
    // free contact field filter
    srv_phb_free_contact_filter(m_contactField);

    // free list handle
    if (m_handle)
    {
        srv_phb_free_query_handle(m_handle);
    }
    */
}


void ContactList::setStorage(VfxU32 storageMask)
{
    /**** for tcard import ****/
    // if (storageMask == 0)
    // {
    //     return;
    // }

    srv_phb_contact_filter_set_storage(m_contactField, storageMask);
    m_storageMask = storageMask;
    updateList();
}


void ContactList::setField(VfxU32 fieldMask)
{
    srv_phb_contact_filter_set_field(m_contactField, fieldMask);
    updateList();
}


void ContactList::setQuery(const VfxWString& pattern, VfxU32 compareField, srv_phb_query_type_enum compareStyle)
{
    WCHAR queryStr[SRV_PHB_QUERY_PATTERN_LEN + 1]; // notice the strlength
    VfxU32 maxLength, strLength;

    strLength = pattern.getLength();
    maxLength = SRV_PHB_QUERY_PATTERN_LEN > strLength ? strLength : SRV_PHB_QUERY_PATTERN_LEN;
    
    mmi_wcsncpy(queryStr, (WCHAR *)pattern.getBuf(), maxLength);
    queryStr[maxLength] = L'\0';
    removeSuffixSpace(queryStr, mmi_wcslen(queryStr));
    
    srv_phb_contact_filter_set_query(
        m_contactField,
        queryStr,
       // (WCHAR*)pattern.getBuf(),
        compareField,
        compareStyle);
    updateList();
}


#ifdef __MMI_PHB_CALLER_GROUP__
void ContactList::setGroup(VfxU8 groupId, VfxBool isEqual)
{
    if (groupId == MMI_PHB_INVALID_GROUP_ID)
    {
        return;
    }

    srv_phb_contact_filter_set_group(m_contactField, groupId, (isEqual) ? MMI_TRUE : MMI_FALSE);
    updateList();
}


void ContactList::setGroup(srv_phb_group_struct *groupId, VfxBool isEqual)
{
    if (!groupId)
    {
        srv_phb_contact_filter_set_group_ex(m_contactField, groupId, (isEqual) ? MMI_TRUE : MMI_FALSE);
        updateList();
    }
}
#endif /* __MMI_PHB_CALLER_GROUP__*/

void ContactList::setAlphaJumper(VfxBool isOn)
{
    m_req.alpha_table = (isOn) ? MMI_TRUE : MMI_FALSE;
    updateList();
}


void ContactList::setAlignField(VfxU32 fieldMask)
{
    m_req.align_field = fieldMask;
    updateList();
}


VfxU32 ContactList::getSeekerGroupCount() const
{
    return MMI_PHB_LIST_GROUP_COUNT - 1;
}


VfxU32 ContactList::getCount() const
{
    if (isUpdating())
    {
        return 0;
    }

    return srv_phb_query_get_count(m_handle);
}


VfxU32 ContactList::getGroupCount() const
{
    if (isUpdating())
    {
        return 0;
    }

    return m_groupList.getGroupCount();
}


VfxU32 ContactList::getCountByGroup(VfxU32 groupIndex) const
{
    if (isUpdating())
    {
        return 0;
    }

    return m_groupList.getCountByGroup(groupIndex);
}


VfxU32 ContactList::getIndex(VfxU32 index, VfxU32 groupIndex) const
{
    return m_groupList.getIndexByGroup(index, groupIndex);
}


VfxU32 ContactList::getId(VfxU32 index, VfxU32 groupIndex) const
{
    return srv_phb_query_get_contact_id(
                m_handle,
                m_groupList.getIndexByGroup(index, groupIndex));
}


VfxU32 ContactList::getIdByIndex(VfxU32 index) const
{
    return srv_phb_query_get_contact_id(m_handle, index);
}


VfxU32 ContactList::getType(VfxU32 index, VfxU32 groupIndex) const
{
    return srv_phb_query_get_align_field_type(
               m_handle,
               m_groupList.getIndexByGroup(index, groupIndex));
}


VfxU32 ContactList::getTypeByIndex(VfxU32 index) const
{
    return srv_phb_query_get_align_field_type(m_handle, index);
}


VfxU32 ContactList::getSubType(VfxU32 index, VfxU32 groupIndex) const
{
    mmi_phb_contact_field_id_enum type;
    void* info = srv_phb_query_get_align_field(
                     m_handle,
                     m_groupList.getIndexByGroup(index, groupIndex),
                     &type);

    if (info == NULL)
    {
        return 0;
    }

    if (type == MMI_PHB_CONTACT_FIELD_ID_NUMBER)
    {
        srv_phb_number_struct *num = (srv_phb_number_struct*) info;
        return num->type;
    }
    else if (type == MMI_PHB_CONTACT_FIELD_ID_EMAIL)
    {
        srv_phb_email_struct *email = (srv_phb_email_struct*) info;
        return email->type;
    }
    else
    {
        return 0;
    }
}


VfxU32 ContactList::getSubId(VfxU32 index, VfxU32 groupIndex) const
{
    mmi_phb_contact_field_id_enum type;
    void* info = srv_phb_query_get_align_field(
                     m_handle,
                     m_groupList.getIndexByGroup(index, groupIndex),
                     &type);

    if (info == NULL)
    {
        return 0;
    }

    if (type == MMI_PHB_CONTACT_FIELD_ID_NUMBER)
    {
        srv_phb_number_struct *num = (srv_phb_number_struct*) info;
        return num->sub_id;
    }
    else if (type == MMI_PHB_CONTACT_FIELD_ID_EMAIL)
    {
        srv_phb_email_struct *email = (srv_phb_email_struct*) info;
        return email->sub_id;
    }
    else
    {
        return 0;
    }
}


VfxU32 ContactList::getSubIdByIndex(VfxU32 index) const
{
    mmi_phb_contact_field_id_enum type;
    void* info = srv_phb_query_get_align_field(
                     m_handle,
                     index,
                     &type);

    if (info == NULL)
    {
        return 0;
    }

    if (type == MMI_PHB_CONTACT_FIELD_ID_NUMBER)
    {
        srv_phb_number_struct *num = (srv_phb_number_struct*) info;
        return num->sub_id;
    }
    else if (type == MMI_PHB_CONTACT_FIELD_ID_EMAIL)
    {
        srv_phb_email_struct *email = (srv_phb_email_struct*) info;
        return email->sub_id;
    }
    else
    {
        return 0;
    }
}


VfxWString ContactList::getGroupString(VfxU32 groupIndex)
{
    return m_groupList.getGroupString(groupIndex);
}


ContactMatchInfo& ContactList::getMatchInfo(VfxU32 index, VfxU32 groupIndex)
{
    srv_phb_query_match_info_struct *matchInfo = srv_phb_query_get_matched_info(
                                                    m_handle,
                                                    m_groupList.getIndexByGroup(index, groupIndex));

    m_matchInfo.clear();

    if (matchInfo)
    {
        m_matchInfo.m_field = matchInfo->matched_field;
        m_matchInfo.m_head = matchInfo->sequence_start;
        m_matchInfo.m_tail = matchInfo->sequence_start + matchInfo->sequence_len;
        if (!matchInfo->is_sequence)
        {
            m_matchInfo.m_manyPartMatched = VFX_TRUE;
        }

        for (VfxU32 i = 0; i < MMI_PHB_LIST_MATCHED_LEN; i++)
        {
            m_matchInfo.m_mask[i] = matchInfo->mask[i];
        }
    }

    return m_matchInfo;
}


VfxS32 ContactList::getGroupPos(VfxU32 groupSeeker)
{
    return m_groupList.getGroupIndexByGroupSeeker(groupSeeker);
}


VfxS32 ContactList::getIndexPos(VfxU32 indexSeeker)
{
    return 0;
}


VfxWString ContactList::getGroupSeekerString(VfxU32 groupSeeker)
{
    return m_groupList.getGroupSeekerString(groupSeeker);
}


VfxU32 ContactList::getStorageMask()
{
    return m_storageMask;
}


void ContactList::updateList()
{
    if (!m_update)
    {
        m_update = VFX_TRUE;
        vfxPostInvoke0(this, &ContactList::getListInter);
    }
}


void ContactList::getList()
{
    updateList();
}


void ContactList::getListInter()
{
    // set update flag
    m_update = VFX_FALSE;

    if (GET_CONTACT_TASK()->checkReady())
    {
        if (m_handle)
        {
            srv_phb_query(&m_req, m_handle);
        }
        else
        {
            m_handle = srv_phb_query(&m_req, NULL);
        }

        // build group list
        if (m_req.alpha_table)
        {
            m_groupList.rebuild(m_handle);
        }

        if (!m_async)
        {
            m_updating = VFX_FALSE;
            m_signalReady.postEmit();
        }
        else
        {
            m_updating = VFX_TRUE;
            m_signalGettingList.postEmit();
        }
    }
    else
    {
        m_updating = VFX_TRUE;
        m_signalGettingList.postEmit();
    }
}


void ContactList::onListChanged(ContactTask* task, mmi_event_struct* evt)
{
    m_signalRefresh.emit(this, evt);
}


VfxBool ContactList::isUpdating() const
{
    if (m_update || m_updating)
    {
        return VFX_TRUE;
    }

    return VFX_FALSE;
}


void ContactList::onQueryCallback(srv_phb_query_async_cb_result_struct *ret)
{
    ContactList *pThis = (ContactList *)VfxObject::handleToObject((VfxObjHandle)ret->user_data);

    if (!pThis)
    {
        return;
    }

    // build group list
    if (pThis->m_req.alpha_table)
    {
         pThis->m_groupList.rebuild( pThis->m_handle);
    }
    pThis->m_update = VFX_FALSE;
    pThis->m_updating = VFX_FALSE;

    if (srv_phb_query_get_count(pThis->m_handle) < 6 && ret->result == 0) // don't refresh list if ...
    {
        return;
    }

    //  pThis->getListInter();
    if (!pThis->m_sendSignal || ret->result == 1)
    {
        pThis->m_sendSignal = VFX_TRUE;
        pThis->m_signalReady.postEmit();
    }
}


void *ContactList::memAllocator(VfxU32 size, void *userData)
{
    void *memPtr = NULL;
    ContactList *self = (ContactList *)VfxObject::handleToObject((VfxObjHandle)userData);
    //VfxMainScr *mainScr = findMainScr(self);

    //if (mainScr && size > 0)
    if (size > 0 && self && self->m_queryMemManage)
    {
        //memPtr = mmi_frm_asm_alloc_r(mainScr->getGroupId(), size);

        memPtr = self->m_queryMemManage->getNewBuffer(size);
    }

    return memPtr;
}


void ContactList::memDeallocator(void *mem, void *userData)
{
    ContactList *self = (ContactList *)VfxObject::handleToObject((VfxObjHandle)userData);
    //VfxMainScr *mainScr = findMainScr(self);

    //if (mainScr && mem)
    //{
        //mmi_frm_asm_free_r(mainScr->getGroupId(), mem);
    //}
    if (mem && self && self->m_queryMemManage)
    {
        self->m_queryMemManage->freeBuffer(mem);
    }
}


VfxMainScr *ContactList::findMainScr(VfxObject *obj)
{
    while(obj)
    {
        if(obj->isKindOf(VFX_OBJ_CLASS_INFO(VfxMainScr)))
            return VFX_OBJ_DYNAMIC_CAST(obj, VfxMainScr);

        obj = obj->getParent();
    }
    return NULL;
}


/***************************************************************************** 
 * Class VappContactQueryItem
 *****************************************************************************/
VappContactQueryItem::VappContactQueryItem(VfxU32 size)
{
    VFX_ASSERT(size > 0);

    m_size = size;
    m_buffer = NULL;
    VFX_ALLOC_MEM(m_buffer, m_size, this);

    VFX_ASSERT(m_buffer);
}


VappContactQueryItem::~VappContactQueryItem()
{
    VFX_FREE_MEM(m_buffer);
}


VfxU32 VappContactQueryItem::getSize()
{
    return m_size;
}


void *VappContactQueryItem::getBuffer()
{
    return m_buffer;
}


/***************************************************************************** 
 * Class VappContactQueryManage
 *****************************************************************************/
VappContactQueryManage::VappContactQueryManage()
{
    m_total = 0;
}


VappContactQueryManage::~VappContactQueryManage()
{
    freeAllQueryItem();
}


void *VappContactQueryManage::getNewBuffer(VfxU32 size)
{
    VFX_ASSERT(m_total <= VAPP_CONTACT_QUERY_ITEM_MAX);

    VappContactQueryItem *queryItem = NULL;

    VFX_OBJ_CREATE_EX(queryItem, VappContactQueryItem, this, (size));

    m_queryItem[m_total++] = queryItem;

    return queryItem->getBuffer();
}


void VappContactQueryManage::freeBuffer(void *buf)
{
    VappContactQueryItem *queryItem = NULL;
    VfxS32 index = 0, i = 0;

    index = searchBuffer(buf);

    //VFX_ASSERT(index >= 0);
    if (index == -1)
    {
        return ;
    }

    queryItem = m_queryItem[i];

    if (queryItem->isValid())
    {
        MMI_TRACE(MMI_COMMON_TRC_G4_PHB, VAPP_CONTACT_OP_TASK, buf);
        VFX_OBJ_CLOSE(queryItem);
    }

    for (i = index; i < (m_total - 1); ++i)
    {
        m_queryItem[i] = m_queryItem[i + 1];
    }

    --m_total;
}


VfxS32 VappContactQueryManage::searchBuffer(void *buf)
{
    VfxS32 index = -1, i = 0;

    for (i = 0; i < m_total; ++i)
    {
        if (buf == m_queryItem[i]->getBuffer())
        {
            index = i;
            break;
        }
    }

    return index;
}


void VappContactQueryManage::freeAllQueryItem()
{
    VfxS32 i = 0, j = 0;
    VappContactQueryItem *queryItem = NULL;


    for (i = 0; i < m_total; ++i)
    {
        queryItem = m_queryItem[i];
        if (queryItem->isValid())

        {
            VFX_OBJ_CLOSE(m_queryItem[i]);
        }
        else
        {
            for (j = i; j < (m_total - 1); ++j)
            {
                m_queryItem[j] = m_queryItem[j + 1];
            }
            --m_total;
            --i;
        }
    }
}


VfxS32 VappContactQueryManage::getTotal()
{
    return m_total;
}

