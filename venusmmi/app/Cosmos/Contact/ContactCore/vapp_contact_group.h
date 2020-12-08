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
 *  vapp_contact_group.h
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

#ifdef __MMI_PHB_CALLER_GROUP__

#ifndef __CONTACT_GROUP_H__
#define __CONTACT_GROUP_H__

#include "vfx_uc_include.h"

#include "vapp_contact_entry.h"
#include "vapp_contact_task.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "PhbSrvGprot.h"
#include "FileMgrSrvGprot.h"
#include "mmi_rp_app_usbsrv_def.h"

#ifdef __cplusplus
}
#endif


#ifdef __MMI_PHB_USIM_SUPPORT__
/***************************************************************************** 
 * Class UsimGroup
 *****************************************************************************/
class UsimGroup: public VfxObject
{
public:
static VfxBool isSupport(phb_storage_enum storage);

static VfxU32 getCount();
};
#endif /* __MMI_PHB_USIM_SUPPORT__ */


#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
/***************************************************************************** 
 * Class TcardGroup
 *****************************************************************************/
class TcardGroup: public VfxObject
{
public:
    static VfxBool isSupport(phb_storage_enum storage);

    static VfxU32 getCount();
};
#endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */


/***************************************************************************** 
 * Class ContactGroup
 *****************************************************************************/ 
class ContactGroup: public VfxObject
{
public:
    ContactGroup();

    ContactGroup(VfxU8 id);

public:
    VfxBool isValid();

    VfxU8 getGroupId() const;

    void setGroupName(const VfxWChar* name);

    VfxWString getGroupName() const;

    VfxWChar* getGroupNameBuf();

    void setImage(const VfxWChar* path, VfxU16 imgId);

    VfxImageSrc getImageSrc();

    VfxWChar* getImage(VfxU16 &toneId);

    void setRingTone(const VfxWChar* path, VfxU16 toneId);

    void setRingTone(const VfxWString &path, VfxU16 toneId);

    VfxWString getRingTone(VfxU16 &toneId) const;

    VfxWChar* getRingPath(VfxU16 &toneId);

    VfxWString getRingName();

protected:
    virtual void onInit();

private:
    void build();

private:
    VfxU8 m_id;
    VfxWChar m_groupName[MMI_PHB_GROUP_NAME_LENGTH + 1];
    VfxU16 m_imgId;
    VfxWChar m_imgPath[SRV_FMGR_PATH_MAX_LEN + 1];
    VfxU16 m_ringToneId;
    VfxWChar m_ringTonePath[SRV_FMGR_PATH_MAX_LEN + 1];
};


/***************************************************************************** 
 * Class ContactGroupManager
 *****************************************************************************/ 
class ContactGroupManager: public VfxObject
{
public:
    ContactGroupManager();

    ContactGroupManager(phb_storage_enum storage);

    void getGroup();

    VfxU32 getGroupCount(phb_storage_enum storage = PHB_STORAGE_MAX);

    VfxU32 getUsedGroupCount(phb_storage_enum storage);

    VfxU32 getMaxGroupCount(phb_storage_enum storage);

    VfxWString getGroupName(VfxU32 index);

    VfxWString getGroupNameById(VfxU8 groupId);

    VfxU8 getGroupId(VfxU32 index);

    phb_storage_enum getStorageById(VfxU8 groupId);

    void addGroupMembersReq(mmi_phb_contact_id* idArray, VfxU16 count, VfxU8 groupId, srv_phb_group_callback_type cb);

    void addGroupMembers(mmi_phb_contact_id* idArray, VfxU16 count, VfxU8 groupId);

    static void addGroupMembersCb(VfxS32 result, void* user_data);

    void removeGroupMembers(mmi_phb_contact_id* idArray, VfxU16 count, VfxU8 groupId);

    static void removeGroupMembersCb(VfxS32 result, void* user_data);

    void moveGroupMembers(mmi_phb_contact_id* idArray, VfxU16 count, VfxU8 fromId, VfxU8 toId);

    static void moveGroupMembersCb(VfxS32 result, void* user_data);

    void addGroup(ContactGroup *group, phb_storage_enum storage);

    void cancelGroupOp(srv_phb_group_op_type_enum opType);

    static void addGroupCb(VfxS32 result, void* user_data);

    static void editGroupCb(VfxS32 result, void* user_data);

    void deleteGroup(VfxU8* groupIdArray, VfxU16 count);

    static void deleteGroupCb(VfxS32 result, void* user_data);

    VfxSignal3<ContactGroupManager*, VfxU8, srv_phb_group_op_type_enum> m_signalGroupManager;

    VfxSignal3<ContactGroupManager*, VfxS32, srv_phb_group_op_type_enum> m_signalGroupOp;

    VfxSignal1<ContactGroupManager*> m_signalGroupMember;
    
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    VfxSignal2<ContactGroupManager *, mmi_event_struct *> m_signalGroupChanged;

    void onGroupChanged(ContactTask *task, mmi_event_struct *evt);
#endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */

protected:
    virtual void onInit();

    virtual void onDeinit(); 

private:
    VfxU32      m_groupCount;
    VfxU32      m_groupPhoneCount;
    VfxU32      m_groupTcardCount;
    VfxU8       m_groupIdArray[MMI_PHB_GROUP_TOTAL_COUNT];
    VfxWChar    m_groupNameArray[MMI_PHB_GROUP_TOTAL_COUNT][MMI_PHB_GROUP_NAME_LENGTH + 1];
    phb_storage_enum m_storage;
    VfxU16      m_groupOpCount;
    VfxU16      m_groupOpIndex;
    VfxU8       m_groupOpId;
    VfxU8       m_groupOpId2;
    mmi_phb_contact_id m_groupOpIdArray[MMI_PHB_PHONE_ENTRIES + MMI_PHB_SIM_ENTRIES];
    VfxU8       m_groupOpGroupIdArray[MMI_PHB_GROUP_TOTAL_COUNT];
};


/***************************************************************************** 
 * Class VappContactGroupMarkObj
 *****************************************************************************/ 
class VappContactGroupMarkObj: public VfxObject
{
public:
    class Key: public VfxBase
    {
    public:
        Key(): m_id(0) {}

        Key(VfxU8 id): m_id(id) {}

        VfxBool operator == (const Key &key)
        {
            if (key.m_id == m_id)
            {
                return VFX_TRUE;
            }
            else
            {
                return VFX_FALSE;
            }
        }

        VfxU8 m_id;
    };

typedef ContactStack<Key> VappContactGroupMarkStack;

public:
    VappContactGroupMarkObj();

    void setMark(VfxU8 id);

    void resetMark(VfxU8 id);

    VfxBool checkMark(VfxU8 id);

    void changeMark(VfxU8 id);

    VfxU32 getCount();

    void reset();

    Key getMarkKey(VfxU32 index);

protected:
    virtual void onInit();

private:
    VappContactGroupMarkStack *m_mark;
};

#endif /* __CONTACT_GROUP_H__ */

#endif /* MMI_PHB_CALLER_GROUP */

