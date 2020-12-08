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
 *  vapp_contact_several.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifndef __CONTACT_SEVERAL_H__
#define __CONTACT_SEVERAL_H__

#include "vfx_uc_include.h"

#include "vapp_contact_list.h"
#include "vapp_contact_entry.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "PhbSrvGprot.h"

#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Class MarkKey
 *****************************************************************************/ 
class MarkKey: public VfxBase
{
public:
    MarkKey():
        m_id(MMI_PHB_INVALID_CONTACT_ID),
        m_type(0),
        m_subId(0) {}

    MarkKey(mmi_phb_contact_id id, VfxU32 type, VfxU32 subType):
        m_id(id),
        m_type(type),
        m_subId(subType) {}

    MarkKey& operator = (const MarkKey& key)
    {
        m_id = key.m_id;
        m_type = key.m_type;
        m_subId = key.m_subId;

        return *this;
    }

    VfxBool operator == (const MarkKey& key) const
    {
        if (m_id == key.m_id && m_type == key.m_type && m_subId == key.m_subId)
        {
            return VFX_TRUE;
        }
        else
        {
            return VFX_FALSE;
        }
    }

    mmi_phb_contact_id m_id;
    VfxU32 m_type;
    VfxU32 m_subId;
};

typedef VappContactStackList<MarkKey> ContactMarkStack;
typedef ContactMarkStack::Element   ContactMarkStackNode;


/***************************************************************************** 
 * Class ContactMark
 *****************************************************************************/ 
class ContactMark: public VfxObject
{
public:
    // default constructor
    ContactMark():
        m_list(NULL),
        m_mark(NULL)
    {}

    // set list content
    void setList(ContactList *list)
    {
        m_list = list;
    }

    // set mark
    void setMark(VfxU32 index, VfxU32 groupIndex = 0)
    {
        VfxU32 listIndex = m_list->getIndex(index, groupIndex);
        
        VfxU32 id = m_list->getIdByIndex(listIndex);
        VfxU32 type = m_list->getTypeByIndex(listIndex);
        VfxU32 subId = m_list->getSubIdByIndex(listIndex);

        MarkKey *key;
        VFX_ALLOC_NEW_EX(key, MarkKey, this, (id, type, subId));

        m_mark->pushValue(key);
    }

    // reset mark
    void resetMark(VfxU32 index, VfxU32 groupIndex = 0)
    {
        ContactMarkStackNode *node = find(index, groupIndex);

        if (node)
        {
            MarkKey *key = node->m_element;
            VFX_DELETE(key);

            m_mark->clearNode(node);
        }
    }

    VfxBool clearIndexMarkKey(MarkKey &key)
    {
        ContactMarkStackNode *node = m_mark->getHead();

        while (node)
        {
            if (node->m_element->m_id == key.m_id && node->m_element->m_type == key.m_type && node->m_element->m_subId == key.m_subId)
            {
                break;
            }
            else
            {
                node = node->m_next;
            }
        }

        if (node)
        {
            MarkKey *key = node->m_element;
            VFX_DELETE(key);

            m_mark->clearNode(node);

            return VFX_TRUE;
        }

        return VFX_FALSE;
    }

    // change mark
    void changeMark(VfxU32 index, VfxU32 groupIndex = 0)
    {
        if (checkMark(index, groupIndex))
        {
            resetMark(index, groupIndex);
        }
        else
        {
            setMark(index, groupIndex);
        }

    }

    // check mark
    VfxBool checkMark(VfxU32 index, VfxU32 groupIndex = 0)
    {
        if (find(index, groupIndex) != NULL)
        {
            return VFX_TRUE;
        }
        else
        {
            return VFX_FALSE;
        }
    }

    // mark all
    void markAll()
    {
        unMarkAll();

        VfxU32 i = 0;
        VfxU32 j = 0;
        VfxU32 count;

        for (i = 0; i < m_list->getGroupCount(); i++)
        {
            count = m_list->getCountByGroup(i);
            for (j = 0; j < count; j++)
            {
                setMark(j, i);
            }
        }
    }

    // unmark all
    void unMarkAll()
    {
        clear();
    }

    // check status
    VfxBool checkMarkAll()
    {
        if (m_mark->getCount() < m_list->getCount())
        {
            return VFX_FALSE;
        }
        else
        {
            return VFX_TRUE;
        }
    }

    // get mark count
    VfxU32 getCount()
    {
        return m_mark->getCount();
    }

    MarkKey getMarkKey(VfxU32 index)
    {
        return m_mark->operator[](index);
    }

protected:
    virtual void onInit()
    {
        VfxObject::onInit();

        VFX_OBJ_CREATE(m_mark, ContactMarkStack, this);
    }

    virtual void onDeinit()
    {
        clear();
        VFX_OBJ_CLOSE(m_mark);

        VfxObject::onDeinit();
    }

private:
    ContactMarkStackNode* find(VfxU32 index, VfxU32 groupIndex = 0)
    {
        VfxU32 id = m_list->getId(index, groupIndex);
        VfxU32 type = m_list->getType(index, groupIndex);
        VfxU32 subId = m_list->getSubId(index, groupIndex);

        ContactMarkStackNode *node = m_mark->getHead();

        while (node)
        {
            if (node->m_element->m_id == id && node->m_element->m_type == type && node->m_element->m_subId == subId)
            {
                break;
            }
            else
            {
                node = node->m_next;
            }
        }

        return node;
    }

    void clear()
    {
        VfxU32 count = m_mark->getCount();

        for (VfxU32 i = 0; i < count; i++)
        {
            MarkKey *key = m_mark->popValue();

            VFX_DELETE(key);
        }
    }

private:
    ContactList *m_list;
    ContactMarkStack *m_mark;
};

#endif /* __CONTACT_SEVERAL_H__ */

