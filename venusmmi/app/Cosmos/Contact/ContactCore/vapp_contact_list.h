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
 *  vapp_contact_list.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifndef __CONTACT_LIST_H__
#define __CONTACT_LIST_H__

#include "vfx_uc_include.h"

#include "vapp_contact_storage.h"
#include "vapp_contact_task.h"
#include "vfx_main_scr.h"
#include "vcui_phb_gprot.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "PhbSrvGprot.h"

#ifdef __cplusplus
}
#endif

#define MMI_PHB_LIST_GROUP_COUNT (26 + 1 + 1) // 26 alpha, 1 '#'

#define MMI_PHB_LIST_MATCHED_LEN ((SRV_PHB_QUERY_PATTERN_LEN + 7) / 8)

/***************************************************************************** 
 * Class ContactMatchInfo
 *****************************************************************************/ 
class ContactMatchInfo: public VfxBase
{
public:
    ContactMatchInfo():
        m_field(0),
        m_head(-1),
        m_tail(-1),
        m_manyPartMatched(VFX_FALSE)
    {}

    ContactMatchInfo(const ContactMatchInfo& matchedInfo)
    {
        set(matchedInfo);
    }

    ContactMatchInfo& operator= (const ContactMatchInfo& matchedInfo)
    {
        set(matchedInfo);

        return *this;
    }

    void set(const ContactMatchInfo& matchedInfo)
    {
        m_field = matchedInfo.m_field;
        m_head = matchedInfo.m_head;
        m_tail = matchedInfo.m_tail;
        m_manyPartMatched = matchedInfo.m_manyPartMatched;

        for (VfxU32 i = 0; i < MMI_PHB_LIST_MATCHED_LEN; i++)
        {
            m_mask[i] = matchedInfo.m_mask[i];
        }
    }

    void clear()
    {
        m_field = 0;
        m_head = -1;
        m_tail = -1;
        m_manyPartMatched = VFX_FALSE;
    }

    VfxU8 getMatchedField()
    {
        return m_field;
    }

    VfxPoint getRange(VfxS32 startPos = 0)
    {
        if (m_manyPartMatched)
        {
            VfxS32 start = -1;
            VfxS32 end = -1;
            VfxBool find = VFX_FALSE;
            for (VfxU32 i = startPos; i < SRV_PHB_QUERY_PATTERN_LEN; i++)
            {
                if (m_mask[i >> 3] & (1 << (i % 8)))
                {
                    if (!find)
                    {
                        find = VFX_TRUE;
                        start = i;
                    }

                    end = i;
                }
                else
                {
                    if (find)
                    {
                        break;
                    }
                }
            }

            if (find)
            {
                // since the range postion is the seperator of chars, so plus one to end
                end++;
            }

            return VfxPoint(start, end);
        }
        else
        {
            if (startPos == 0)
            {
                return VfxPoint(m_head, m_tail);
            }
            else
            {
                return VfxPoint(-1, -1);
            }
        }
    }

    VfxU8 m_field;                                      /* matched field type */
    VfxS32 m_head;                                      /* matched head pos */
    VfxS32 m_tail;                                      /* matched tail pos */

    /* Notice: if it has many part matched, the user should use the bit mask to caculate out the matched result */
    VfxBool m_manyPartMatched;                          /* many matched part */
    VfxU8 m_mask[MMI_PHB_LIST_MATCHED_LEN];             /* matched bit pos */
};


/***************************************************************************** 
 * Class VappContactQueryItem
 *****************************************************************************/ 

#define VAPP_CONTACT_QUERY_ITEM_MAX 32

class VappContactQueryItem: public VfxObject
{
public:
    VappContactQueryItem(VfxU32 size);
    virtual ~VappContactQueryItem();

public:
    VfxU32 getSize();
    void *getBuffer();

private:
    VappContactQueryItem();

private:
    VfxU32 m_size;
    void *m_buffer;
};


class VappContactQueryManage: public VfxObject
{
public:
    VappContactQueryManage();
    virtual ~VappContactQueryManage();

public:
    VfxS32 getTotal();
    void *getBuffer(VfxU32 index);
    VappContactQueryItem *getQueryItem(VfxU32 index);
    void *getNewBuffer(VfxU32 size);
    void freeBuffer(void *buf);

private:
    void freeAllQueryItem();
    VfxS32 searchBuffer(void *buf);

private:
    VfxS32 m_total;
    VappContactQueryItem *m_queryItem[VAPP_CONTACT_QUERY_ITEM_MAX];
};


/***************************************************************************** 
 * Class ContactList
 *****************************************************************************/ 
class ContactList: public VfxObject
{
public:
    // contact list
    ContactList():
        m_update(VFX_FALSE),
        m_updating(VFX_FALSE),
        m_handle(NULL),
        m_contactField(NULL){};

public:
    // set storage
    void setStorage(VfxU32 storageMask);

    // set field
    void setField(VfxU32 fieldMask);

    // set query
    void setQuery(
            const VfxWString& pattern,
            VfxU32 compareField = MMI_PHB_CONTACT_FIELD_NAME,
            srv_phb_query_type_enum compareStyle = SRV_PHB_QUERY_TYPE_PARTIAL);
    
#ifdef __MMI_PHB_CALLER_GROUP__
    // set group filter
    void setGroup(VfxU8 groupId, VfxBool isEqual = VFX_TRUE);

    // set group mask
    void setGroup(srv_phb_group_struct* groupId, VfxBool isEqual = VFX_TRUE);
#endif /* __MMI_PHB_CALLER_GROUP__ */
    // set alpha jump
    void setAlphaJumper(VfxBool isOn = VFX_TRUE);

    // set align field
    void setAlignField(VfxU32 fieldMask);

public:
    void updateList();

    VfxU32 getSeekerGroupCount() const;

    VfxBool isUpdating() const;

    // get list: UI call it to start build list. After building done
    // it will post signal ready to caller
    virtual void getList();

    void getListInter();

    // get list total count
    virtual VfxU32 getCount() const;

    // get group count
    virtual VfxU32 getGroupCount() const;

    // get count by group
    virtual VfxU32 getCountByGroup(VfxU32 groupIndex) const;

    VfxU32 getIndex(VfxU32 index, VfxU32 groupIndex) const;

    // get id
    virtual VfxU32 getId(VfxU32 index, VfxU32 groupIndex = 0) const;

    virtual VfxU32 getIdByIndex(VfxU32 index) const;

    // get type
    virtual VfxU32 getType(VfxU32 index, VfxU32 groupIndex = 0) const;

    virtual VfxU32 getTypeByIndex(VfxU32 index) const;

    // get sub type
    virtual VfxU32 getSubType(VfxU32 index, VfxU32 groupIndex = 0) const;

    // get sub id
    virtual VfxU32 getSubId(VfxU32 index, VfxU32 groupIndex = 0) const;

    virtual VfxU32 getSubIdByIndex(VfxU32 index) const;

    // get group string
    virtual VfxWString getGroupString(VfxU32 groupIndex);

    // get matched infomation
    virtual ContactMatchInfo& getMatchInfo(VfxU32 index, VfxU32 groupIndex = 0);

    // get position
    virtual VfxS32 getGroupPos(VfxU32 groupSeeker);

    virtual VfxS32 getIndexPos(VfxU32 indexSeeker);

    virtual VfxWString getGroupSeekerString(VfxU32 groupSeeker);

    // get storage maks
    VfxU32 getStorageMask();

    // event handler
    void onListChanged(ContactTask*, mmi_event_struct*);

private:
    class GroupList
    {
    public:
        GroupList(): m_groupCount(0){}

        VfxU32 getGroupCount() const
        {
            return m_groupCount;
        }

        VfxU32 getCountByGroup(VfxU32 groupIndex) const
        {
            VFX_ASSERT(groupIndex < (MMI_PHB_LIST_GROUP_COUNT));

            return m_index[groupIndex][0];
        }

        VfxU32 getIndexByGroup(VfxU32 index, VfxU32 groupIndex) const
        {
            VFX_ASSERT(groupIndex < (MMI_PHB_LIST_GROUP_COUNT));

            VfxU32 result = 0;

            for (VfxU32 i = 0; i < groupIndex; i++)
            {
                result += m_index[i][0];
            }

            result += index;

            return result;
        }

        VfxS32 getGroupIndexByGroupSeeker(VfxU32 groupSeeker) const
        {
            for (VfxU32 i = 0; i < m_groupCount; i++)
            {
                if (m_index[i][1] >= groupSeeker)
                {
                    return i;
                }
            }

            return (m_groupCount > 0) ? (m_groupCount - 1) : -1;
        }

        VfxWString getGroupSeekerString(VfxU32 groupSeeker)
        {
        #ifdef __MMI_PHB_EMPTY_NAME_TOP__
            if (groupSeeker == 0)
            {
                return VfxWString().format("%c", '#');
            }
            else
            {
                return VfxWString().format("%c", 'A' + (groupSeeker - 1));
            }
        #else
            if (groupSeeker >= 26)
            {
                return VfxWString().format("%c", '#');
            }
            else
            {
                return VfxWString().format("%c", 'A' + (groupSeeker));
            }
        #endif /* __MMI_PHB_EMPTY_NAME_TOP__ */
        }

        VfxWString getGroupString(VfxU32 groupIndex)
        {
            VfxU32 index = m_index[groupIndex][1];

            if (index == 0)
            {
                return VFX_WSTR("#");
            }
            else if (index <= 26)
            {
                index--;
                index += 'A';
                return VfxWString().format("%c", index);
            }
            else
            {
                return VFX_WSTR("#");
            }
        }

        // build group list
        void rebuild(srv_phb_query_handle handle)
        {
            m_groupCount = 0;
            srv_phb_alpha_info_struct *info = NULL;

            for (VfxU32 i = 0; i < MMI_PHB_LIST_GROUP_COUNT; i++)
            {
                info = srv_phb_query_get_alpha_count(handle, i);
                if (info != NULL)
                {
                    m_index[m_groupCount][0] = info->count;

                    if (m_index[m_groupCount][0] > 0)
                    {
                        m_index[m_groupCount++][1] = i; // to find the group name
                    }
                }
            }
        }

    private:
        VfxU8 m_groupCount;
        VfxU16 m_index[MMI_PHB_LIST_GROUP_COUNT][2];
    };

protected:
    // onInit
    virtual void onInit();

    // onDeinit
    virtual void onDeinit();

public:
    // refresh list
    VfxSignal2<ContactList*, mmi_event_struct*>  m_signalRefresh;

    // get list ready with ready count
    VfxSignal0 m_signalReady;

    // get list need more time
    VfxSignal0 m_signalGettingList;

private:
    static void onQueryCallback(srv_phb_query_async_cb_result_struct *ret);

    static void *memAllocator(VfxU32 size, void *userData);

    static void memDeallocator(void *mem, void *userData);

    static VfxMainScr *findMainScr(VfxObject *obj);

private:
    VfxBool m_update;
    VfxBool m_updating;

    // list item count
    srv_phb_query_handle m_handle;
    srv_phb_contact_filter m_contactField;
    srv_phb_query_req_struct m_req;
    GroupList m_groupList;

    // matched info
    ContactMatchInfo m_matchInfo;
    // async query flag
    VfxBool m_async;
    VfxBool m_sendSignal;

    // storage mask
    VfxU32 m_storageMask;

    // asm memory
    VappContactQueryManage *m_queryMemManage;
};

#endif /* __CONTACT_LIST_H__ */

