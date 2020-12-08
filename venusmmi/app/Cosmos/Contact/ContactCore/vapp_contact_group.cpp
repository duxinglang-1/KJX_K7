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
 *  vapp_contact_group.cpp
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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

#include "mmi_rp_vapp_contact_def.h"
#include "mmi_rp_srv_phb_def.h"

#include "vapp_contact_group.h"
#include "vapp_contact_storage.h"
#include "vapp_phb_app.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "FileMgrSrvGprot.h"
#include "ProfilesSrvGprot.h"

#ifdef __cplusplus
}
#endif

#ifdef __MMI_PHB_CALLER_GROUP__

#ifdef __MMI_PHB_USIM_SUPPORT__
VfxBool UsimGroup::isSupport(phb_storage_enum storage)
{
    return (srv_phb_get_support_field(storage) & MMI_PHB_CONTACT_FIELD_GROUP) ? VFX_TRUE : VFX_FALSE;
}


VfxU32 UsimGroup::getCount()
{
    VfxU32 count = 0;

    for (VfxU32 i = 0; i < ContactSim::getTotal(); i++)
    {
        mmi_sim_enum sim = mmi_frm_index_to_sim(i);
        if (isSupport(ContactSim::getStorage(sim)))
        {
            count++;
        }
    }

    return count;
}
#endif /* __MMI_PHB_USIM_SUPPORT__ */


#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
VfxBool TcardGroup::isSupport(phb_storage_enum storage)
{
    return (srv_phb_get_support_field(storage) & MMI_PHB_CONTACT_FIELD_GROUP) ? VFX_TRUE : VFX_FALSE;
}


VfxU32 TcardGroup::getCount()
{
    VfxU32 count = 0;

    if (isSupport(PHB_STORAGE_TCARD))
    {
        count++;
    }

    return count;
}
#endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */

#endif

/***************************************************************************** 
 * Class ContactGroup
 *****************************************************************************/
#ifdef __MMI_PHB_CALLER_GROUP__
ContactGroup::ContactGroup():
    m_id(MMI_PHB_INVALID_GROUP_ID)
{
}


ContactGroup::ContactGroup(VfxU8 id):
    m_id(id)
{
}


void ContactGroup::onInit()
{
    VfxObject::onInit();

    build();
}


VfxBool ContactGroup::isValid()
{
    return (m_id != MMI_PHB_INVALID_GROUP_ID) ? VFX_TRUE : VFX_FALSE;
}


VfxU8 ContactGroup::getGroupId() const
{
    return m_id;
}


void ContactGroup::setGroupName(const VfxWChar* name)
{
    if (name)
    {
        mmi_wcsncpy((WCHAR *) m_groupName, (const WCHAR *) name, MMI_PHB_GROUP_NAME_LENGTH);
    }
    else
    {
        m_groupName[0] = 0;
    }
}


VfxWString ContactGroup::getGroupName() const
{
    return VFX_WSTR_STATIC(m_groupName);
}


VfxWChar* ContactGroup::getGroupNameBuf()
{
    return m_groupName;
}


void ContactGroup::setImage(const VfxWChar* path, VfxU16 imgId)
{
    m_imgId = imgId;

    if (path)
    {
        mmi_wcsncpy((WCHAR *) m_imgPath, (const WCHAR *) path, SRV_FMGR_PATH_MAX_LEN);
    }
    else
    {
        m_imgPath[0] = 0;
    }
}


VfxImageSrc ContactGroup::getImageSrc()
{
    if (m_imgPath[0] != 0)
    {
        return VfxImageSrc(VFX_WSTR_MEM(m_imgPath));
    }
    else if (m_imgId != 0 && m_imgId != IMG_PHB_DEFAULT)
    {
        return VfxImageSrc(m_imgId);
    }
    else
    {
        return VfxImageSrc();
    }
}


VfxWChar* ContactGroup::getImage(VfxU16 &imgId)
{
    imgId = m_imgId;

    return m_imgPath;
}


void ContactGroup::setRingTone(const VfxWChar* path, VfxU16 toneId)
{
    m_ringToneId = toneId;

    if (path)
    {
        mmi_wcsncpy((WCHAR *) m_ringTonePath, (const WCHAR *) path, SRV_FMGR_PATH_MAX_LEN);
    }
    else
    {
        m_ringTonePath[0] = 0;
    }
}


void ContactGroup::setRingTone(const VfxWString &path, VfxU16 toneId)
{
    setRingTone(path.getBuf(), toneId);
}


VfxWString ContactGroup::getRingTone(VfxU16 &toneId) const
{
    toneId = m_ringToneId;

    return VFX_WSTR_STATIC(m_ringTonePath);
}


VfxWChar* ContactGroup::getRingPath(VfxU16 &toneId)
{
    toneId = m_ringToneId;

    return m_ringTonePath;
}


VfxWString ContactGroup::getRingName()
{
    if (m_ringToneId == 0 && m_ringTonePath[0] == 0)
    {
        return VFX_WSTR_RES(VAPP_PHB_STR_DEFAULT);
    }
    else if (m_ringTonePath[0] != 0)
    {
        return VFX_WSTR_MEM(srv_fmgr_path_get_filename_ptr(m_ringTonePath));
    }
    else
    {
        VfxU16 offset;
        srv_prof_audio_resource_type_enum type;

        type = srv_prof_get_audio_info_from_audio_resourece((srv_prof_audio_id) m_ringToneId, &offset);
        VfxResId id = srv_prof_get_string_id_from_audio_resourece(type, offset);

        return VFX_WSTR_RES(id);
    }
}


void ContactGroup::build()
{
    if (m_id != MMI_PHB_INVALID_GROUP_ID)
    {
        srv_phb_group_info_struct *info = (srv_phb_group_info_struct*) mmi_frm_temp_alloc(sizeof(srv_phb_group_info_struct));

        VfxS32 result = srv_phb_get_group_info(m_id, info);

        if (result == SRV_PHB_NO_ERROR)
        {
            setGroupName(info->group_name);
            setImage(info->image_path, info->image_id);
            setRingTone(info->ringtone_path, info->ringtone_id);
        }
        else
        {
            m_id = MMI_PHB_INVALID_GROUP_ID;
        }

        mmi_frm_temp_free(info);
    }
    else
    {
        m_groupName[0] = 0;
        m_imgId = 0;
        m_imgPath[0] = 0;
        m_ringToneId = 0;
        m_ringTonePath[0] = 0;
    }
}
#endif /* __MMI_PHB_CALLER_GROUP__ */


/***************************************************************************** 
 * Class ContactGroupManager
 *****************************************************************************/
#ifdef __MMI_PHB_CALLER_GROUP__ 
ContactGroupManager::ContactGroupManager():
    m_groupCount(0),
    m_storage(PHB_STORAGE_MAX)
{
}


ContactGroupManager::ContactGroupManager(phb_storage_enum storage):
    m_groupCount(0),
    m_storage(storage)
{
}


void ContactGroupManager::onInit()
{
    VfxObject::onInit();
    
    m_groupTcardCount = 0;
    m_groupPhoneCount = 0;
    m_groupCount = 0;

    getGroup();

#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    ContactTask *task = GET_CONTACT_TASK();
    task->m_signalTask.connect(this, &ContactGroupManager::onGroupChanged);
#endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */
}


void ContactGroupManager::onDeinit()
{
    srv_phb_group_cancel_operation(SRV_PHB_GROUP_OP_TYPE_TOTAL);

    VfxObject::onDeinit();
}


void ContactGroupManager::getGroup()
{
    m_groupCount = srv_phb_get_group_list(m_groupIdArray, (U16*)m_groupNameArray, m_storage);
    m_groupPhoneCount = m_groupCount;

#if defined (__MMI_PHB_USIM_SUPPORT__) || defined (__MMI_PHB_TCARD_STORAGE_SUPPORT__)
    VfxU32 count = 0, phone = 0, tcard = 0;

    for (VfxU32 i = 0; i < m_groupCount; i++)
    {
        if (ContactStorage::getMask() & ContactStorage::getMask(getStorageById(m_groupIdArray[i])))
        {
            m_groupIdArray[count] = m_groupIdArray[i];
            mmi_wcscpy(m_groupNameArray[count++], m_groupNameArray[i]);
        }

        if (getStorageById(m_groupIdArray[i]) == PHB_STORAGE_NVRAM)
        {
            phone++;
        }

        if (getStorageById(m_groupIdArray[i]) == PHB_STORAGE_TCARD)
        {
            tcard++;
        }
    }

    m_groupCount = count;
    m_groupPhoneCount = phone;
    m_groupTcardCount = tcard;
#endif /* defined (__MMI_PHB_USIM_SUPPORT__) || defined (__MMI_PHB_TCARD_STORAGE_SUPPORT__) */
}


VfxU32 ContactGroupManager::getGroupCount(phb_storage_enum storage)
{
    if (storage == PHB_STORAGE_MAX)
    {
        return m_groupCount;
    }

#if defined (__MMI_PHB_USIM_SUPPORT__) || defined (__MMI_PHB_TCARD_STORAGE_SUPPORT__)
    VfxU32 count = 0;

    for (VfxU32 i = 0; i < m_groupCount; i++)
    {
        if (getStorageById(m_groupIdArray[i]) == storage)
        {
            count++;
        }
    }

    return count;
#endif /* defined (__MMI_PHB_USIM_SUPPORT__) || defined (__MMI_PHB_TCARD_STORAGE_SUPPORT__) */

    return m_groupCount;
}


VfxU32 ContactGroupManager::getUsedGroupCount(phb_storage_enum storage)
{
#ifdef __MMI_PHB_USIM_SUPPORT__
    if (storage >= PHB_STORAGE_SIM && storage <= PHB_STORAGE_SIM4)
    {
        return srv_phb_get_usim_field_used(storage, 0, PHB_GAS);
    }
#endif /* __MMI_PHB_USIM_SUPPORT__ */

#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    if (PHB_STORAGE_TCARD == storage)
    {
        return m_groupTcardCount;
    }
#endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */
    return m_groupPhoneCount;
}


VfxU32 ContactGroupManager::getMaxGroupCount(phb_storage_enum storage)
{
#ifdef __MMI_PHB_USIM_SUPPORT__
    if (storage >= PHB_STORAGE_SIM && storage <= PHB_STORAGE_SIM4)
    {
        return srv_phb_get_usim_field_total(storage, 0, PHB_GAS);
    }
#endif /* __MMI_PHB_USIM_SUPPORT__ */

    return MMI_PHB_GROUP_COUNT;
}


VfxWString ContactGroupManager::getGroupName(VfxU32 index)
{
    VFX_ASSERT(index < m_groupCount);

    return VFX_WSTR_MEM(m_groupNameArray[index]);
}


VfxWString ContactGroupManager::getGroupNameById(VfxU8 groupId)
{
    VfxU8 index;
    VfxBool find = VFX_FALSE;

    for (index = 0; index < m_groupCount; index++)
    {
        if (groupId == m_groupIdArray[index])
        {
            find = VFX_TRUE;
            break;
        }
    }

    if (find)
    {
        return VFX_WSTR_MEM(m_groupNameArray[index]);
    }
    else
    {
        return VFX_WSTR_EMPTY;
    }
}


VfxU8 ContactGroupManager::getGroupId(VfxU32 index)
{
    VFX_ASSERT(index < m_groupCount);

    return m_groupIdArray[index];
}


phb_storage_enum ContactGroupManager::getStorageById(VfxU8 groupId)
{
    return srv_phb_get_storage_by_group_id(groupId);
}


void ContactGroupManager::addGroupMembersReq(mmi_phb_contact_id* idArray, VfxU16 count, VfxU8 groupId, srv_phb_group_callback_type cb)
{
    srv_phb_group_add_members_req req;
    req.id_array = idArray;
    req.entry_count = count;
    req.group_id = groupId;
    req.is_reset = MMI_TRUE;
    req.cb = cb;
    req.user_data = getObjHandle();

    srv_phb_add_group_members(&req);
}


void ContactGroupManager::addGroupMembers(mmi_phb_contact_id* idArray, VfxU16 count, VfxU8 groupId)
{
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[VAPP_CONTACT_GROUP]addGroupMembers--arrary: 0x%0x, count: %d, groupId: %d\n", idArray, count, groupId);

    addGroupMembersReq(idArray, count, groupId, ContactGroupManager::addGroupMembersCb);
}


void ContactGroupManager::addGroupMembersCb(VfxS32 result, void* user_data)
{
    ContactGroupManager *groupManager = (ContactGroupManager *)VfxObject::handleToObject((VfxObjHandle) user_data);

    if (groupManager)
    {
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[VAPP_CONTACT_GROUP]addCb--groupManager: 0x%0x, user_data: %d, result: %d\n", 
                    groupManager, user_data, result);
    }
    else
    {
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[VAPP_CONTACT_GROUP]addCb--groupManager is null userdata: %d, result: %d\n", user_data, result);
    }

    if (result >= 0)
    {
        ContactGroupManager *manager = (ContactGroupManager *)VfxObject::handleToObject((VfxObjHandle) user_data);
        if (manager)
        {
            manager->m_signalGroupMember.postEmit(manager);
        }
    }
    else // also postEmit
    {
        ContactGroupManager *manager = (ContactGroupManager *)VfxObject::handleToObject((VfxObjHandle) user_data);
        if (manager)
        {
            manager->m_signalGroupMember.postEmit(manager);
        }
    }
}


void ContactGroupManager::removeGroupMembers(mmi_phb_contact_id* idArray, VfxU16 count, VfxU8 groupId)
{
    m_groupOpCount = count;
    m_groupOpIndex = 0;
    m_groupOpId = groupId;

    for (VfxU16 i = 0; i < count; i++)
    {
        m_groupOpIdArray[i] = idArray[i];
    }

    if (count > 0)
    {
        srv_phb_remove_group_member(idArray[m_groupOpIndex++], groupId, ContactGroupManager::removeGroupMembersCb, getObjHandle());
    }

    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[VAPP_CONTACT_GROUP]removeGroupMembers--arrary: 0x%0x, count: %d, groupId: %d\n", idArray, count, groupId);
}


void ContactGroupManager::removeGroupMembersCb(VfxS32 result, void* user_data)
{
    ContactGroupManager *groupManager = (ContactGroupManager *)VfxObject::handleToObject((VfxObjHandle) user_data);

    if (groupManager)
    {
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[VAPP_CONTACT_GROUP]remaoveCb--groupManager: 0x%0x, index: %d, count: %d, result: %d\n", 
                    groupManager, groupManager->m_groupOpIndex, groupManager->m_groupOpCount, result);
    }
    else
    {
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[VAPP_CONTACT_GROUP]remaoveCb--groupManager is null userdata: %d\n", user_data);
    }

    if (result >= 0)
    {
        ContactGroupManager *manager = (ContactGroupManager *)VfxObject::handleToObject((VfxObjHandle) user_data);
        if (!manager)
        {
            return;
        }

        if (manager->m_groupOpIndex >= manager->m_groupOpCount)
        {
            manager->m_signalGroupMember.postEmit(manager);
        }
        else
        {
            srv_phb_remove_group_member(manager->m_groupOpIdArray[manager->m_groupOpIndex++], manager->m_groupOpId, ContactGroupManager::removeGroupMembersCb, user_data);
        }
    }
}


void ContactGroupManager::moveGroupMembers(mmi_phb_contact_id* idArray, VfxU16 count, VfxU8 fromId, VfxU8 toId)
{
    m_groupOpCount = count;
    m_groupOpId = fromId;
    m_groupOpId2 = toId;

    for (VfxU16 i = 0; i < count; i++)
    {
        m_groupOpIdArray[i] = idArray[i];
    }

    if (count > 0)
    {
        addGroupMembersReq(m_groupOpIdArray, m_groupOpCount, m_groupOpId2, ContactGroupManager::moveGroupMembersCb);
    }
}


void ContactGroupManager::moveGroupMembersCb(VfxS32 result, void* user_data)
{
    if (result >= 0)
    {
        ContactGroupManager *manager = (ContactGroupManager *)VfxObject::handleToObject((VfxObjHandle) user_data);
        if (manager)
        {
            manager->m_signalGroupMember.postEmit(manager);
        }
    }
}


void ContactGroupManager::addGroup(ContactGroup *group, phb_storage_enum storage)
{
    srv_phb_group_info_struct *info = (srv_phb_group_info_struct*) mmi_frm_temp_alloc(sizeof(srv_phb_group_info_struct));
    memset(info, 0, sizeof(srv_phb_group_info_struct));

    mmi_wcscpy(info->group_name, group->getGroupName().getBuf());

    VfxWChar* path = group->getImage(info->image_id);

    if (path && path[0] != 0)
    {
        mmi_wcscpy(info->image_path, path);
        info->res_type |= SRV_PHB_RES_TYPE_IMAGE_FILE;
    }
    else if (info->image_id != 0)
    {
        info->res_type |= SRV_PHB_RES_TYPE_IMAGE_ID;
    }

    path = group->getRingPath(info->ringtone_id);

    if (path && path[0] != 0)
    {
        mmi_wcscpy(info->ringtone_path, path);
        info->res_type |= SRV_PHB_RES_TYPE_AUDIO_RING_FILE;
    }
    else if (info->ringtone_id != 0)
    {
        info->res_type |= SRV_PHB_RES_TYPE_RING_ID;
    }

    info->storage = storage;
    info->user_data = getObjHandle();

    if (group->isValid())
    {
        info->cb = ContactGroupManager::editGroupCb;
        srv_phb_update_group_info((U8)group->getGroupId(), info);
    }
    else
    {
        info->cb = ContactGroupManager::addGroupCb;
        srv_phb_add_group(info);
    }

    mmi_frm_temp_free(info);
}


void ContactGroupManager::cancelGroupOp(srv_phb_group_op_type_enum opType)
{
    srv_phb_group_cancel_operation(opType); 
}


void ContactGroupManager::addGroupCb(VfxS32 result, void* user_data)
{
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[VAPP_CONTACT_GROUP]addGroupCb--result: %d, user_data: %d\n", result, user_data);

    if (result >= 0)
    {
        ContactGroupManager *manager = (ContactGroupManager *)VfxObject::handleToObject((VfxObjHandle) user_data);
        if (manager)
        {
            manager->m_signalGroupManager.postEmit(manager, (VfxU8)result, SRV_PHB_GROUP_OP_TYPE_ADD);
            manager->getGroup();
        }
    }
    else if (result == SRV_PHB_GROUP_NAME_DUP)
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE,
            (WCHAR*)VFX_WSTR_RES(STR_ID_VAPP_PHB_GROUP_NAME_DUPLICATED).getBuf());
    }
    else if (result == SRV_PHB_TCARD_NOT_AVAILABLE)
    {
        /*
        VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
        VfxWString errorStr = ContactStorage::getName(PHB_STORAGE_TCARD);
        errorStr += VFX_WSTR_RES(STR_ID_VAPP_PHB_STORAGE_IS_FULL);
        balloon->addItem(VCP_INFO_BALLOON_TYPE_FAILURE, errorStr);
        */
        VfxWString errorStr = ContactStorage::getName(PHB_STORAGE_TCARD);
        errorStr += VFX_WSTR_RES(STR_ID_VAPP_PHB_STORAGE_IS_FULL);

        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE,
            (WCHAR *)errorStr.getBuf());
    }
    else
    {
        vapp_phb_op_error_balloon(-100);
    }
}


void ContactGroupManager::editGroupCb(VfxS32 result, void* user_data)
{
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[VAPP_CONTACT_GROUP]editGroupCb--result: %d, user_data: %d\n", result, user_data);

    if (result >= 0)
    {
        ContactGroupManager *manager = (ContactGroupManager *)VfxObject::handleToObject((VfxObjHandle) user_data);
        if (manager)
        {
            manager->m_signalGroupManager.postEmit(manager, (VfxU8)result, SRV_PHB_GROUP_OP_TYPE_UPD);
            manager->getGroup();
        }
    }
    else if (result == SRV_PHB_GROUP_NAME_DUP)
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE,
            (WCHAR*)VFX_WSTR_RES(STR_ID_VAPP_PHB_GROUP_NAME_DUPLICATED).getBuf());
    }
}


void ContactGroupManager::deleteGroup(VfxU8* groupIdArray, VfxU16 count)
{
    m_groupOpCount = count;
    m_groupOpIndex = 0;

    for (VfxU16 i = 0; i < count; i++)
    {
        m_groupOpGroupIdArray[i] = groupIdArray[i];
    }

    if (count > 0)
    {
        srv_phb_delete_group(groupIdArray[m_groupOpIndex++], ContactGroupManager::deleteGroupCb, getObjHandle());
    }

    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[VAPP_CONTACT_GROUP]deleteGroup--count: %d", count);
}


void ContactGroupManager::deleteGroupCb(VfxS32 result, void* user_data)
{
    ContactGroupManager *groupManager = (ContactGroupManager *)VfxObject::handleToObject((VfxObjHandle) user_data);

    if (groupManager)
    {
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[VAPP_CONTACT_GROUP]deleteGroupCb--groupManager: 0x%0x, user_data: %d, result: %d, opIndex: %d, count: %d\n", 
                    groupManager, user_data, result, groupManager->m_groupOpIndex, groupManager->m_groupOpCount);
    }
    else
    {
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[VAPP_CONTACT_GROUP]deleteGroupCb--groupManager is null userdata: %d, result: %d\n", user_data, result);
    }

    if (result >= 0)
    {
        ContactGroupManager *manager = (ContactGroupManager *)VfxObject::handleToObject((VfxObjHandle) user_data);
        if (!manager)
        {
            return;
        }

        if (manager->m_groupOpIndex >= manager->m_groupOpCount)
        {
            manager->m_signalGroupManager.postEmit(manager, (VfxU8)result, SRV_PHB_GROUP_OP_TYPE_DEL);
            manager->getGroup();
        }
        else
        {
            srv_phb_delete_group(manager->m_groupOpGroupIdArray[manager->m_groupOpIndex++], ContactGroupManager::deleteGroupCb, user_data);
        }
    }
    else
    {
        ContactGroupManager *manager = (ContactGroupManager *)VfxObject::handleToObject((VfxObjHandle) user_data);
        if (!manager)
        {
            return;
        }

        manager->m_signalGroupOp.postEmit(manager, result, SRV_PHB_GROUP_OP_TYPE_DEL);
        manager->getGroup();
    }
}


#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
void ContactGroupManager::onGroupChanged(ContactTask *task, mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        /* for tcard group support, just listen following 4 evts */
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
        case EVT_ID_USB_ENTER_MS_MODE:
        case EVT_ID_USB_EXIT_MS_MODE:
        case EVT_ID_PHB_TCARD_READY:
        {
            m_signalGroupChanged.emit(this, evt);

            break;
        }
    }
}
#endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */
#endif  /* __MMI_PHB_CALLER_GROUP__ */


/***************************************************************************** 
 * Class VappContactGroupMarkObj
 *****************************************************************************/
#ifdef __MMI_PHB_CALLER_GROUP__
VappContactGroupMarkObj::VappContactGroupMarkObj()
{
}


void VappContactGroupMarkObj::onInit()
{
    VfxObject::onInit();

    VFX_OBJ_CREATE_EX(m_mark, VappContactGroupMarkStack, this, (MMI_PHB_GROUP_TOTAL_COUNT));
}


VfxU32 VappContactGroupMarkObj::getCount()
{
    return m_mark->getCount();
}


void VappContactGroupMarkObj::setMark(VfxU8 id)
{
    m_mark->pushValue(Key(id));
}


void VappContactGroupMarkObj::resetMark(VfxU8 id)
{
    Key key(id);

    m_mark->removeValue(m_mark->find(key));
}


VfxBool VappContactGroupMarkObj::checkMark(VfxU8 id)
{
    if (m_mark->find(Key(id)) > -1)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


void VappContactGroupMarkObj::changeMark(VfxU8 id)
{
    if (checkMark(id))
    {
        resetMark(id);
    }
    else
    {
        setMark(id);
    }
}


void VappContactGroupMarkObj::reset()
{
    m_mark->reset();
}


VappContactGroupMarkObj::Key VappContactGroupMarkObj::getMarkKey(VfxU32 index)
{
    return m_mark->getValue(index);
}
#endif /* __MMI_PHB_CALLER_GROUP__ */



