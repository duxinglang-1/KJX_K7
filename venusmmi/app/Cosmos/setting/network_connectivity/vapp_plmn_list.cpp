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
 *  vapp_plmn_list.cpp
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_plmn_list.h"
extern "C"
{
#include "PlmnEnum.h"
}

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/
/***************************************************************************** 
 * VappSettingPlmnNodeBase
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappSettingPlmnNodeBase", VappSettingPlmnNodeBase, VfxObject);
VappSettingPlmnNodeBase::VappSettingPlmnNodeBase(const CHAR* plmn, srv_netset_rat_mode_enum rat)
{
    memset(m_plmn, 0, (MAX_PLMN_LEN + 1));
    memcpy(m_plmn, plmn, (MAX_PLMN_LEN + 1));
    m_rat = rat;
}

VappSettingPlmnNodeBase::VappSettingPlmnNodeBase(VappSettingPlmnNodeBase *node)
{
    memset(m_plmn, 0, (MAX_PLMN_LEN + 1));
    memcpy(m_plmn, node->getPlmn(), (MAX_PLMN_LEN + 1));
    m_rat = node->getRat();
}

VfxWString VappSettingPlmnNodeBase::getOperatorName()
{
    VfxWChar buffer[20];
    memset(buffer, 0, 20 * sizeof(VfxWChar));
    srv_netset_get_opname((VfxU8*)m_plmn, buffer);

    return VFX_WSTR_MEM(buffer);
}

VfxWString VappSettingPlmnNodeBase::getRatString()
{
    switch (m_rat)
	{
	case SRV_NETSET_RAT_GSM:
        return VFX_WSTR("2G");		

	case SRV_NETSET_RAT_UMTS:
        return VFX_WSTR("3G");		

	default:
        return VFX_WSTR_EMPTY;
	}
}

/***************************************************************************** 
 * VappSettingPlmnList
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSettingPlmnList", VappSettingPlmnList, VfxObject);
VappSettingPlmnNodeBase* VappSettingPlmnList::getCurrentNode()
{
    if (!m_currentNode)
	{
	    return NULL;
	}

    VfxObjListEntry *tempNode = m_currentNode;
    m_currentNode = m_currentNode->getNext();
    return (VappSettingPlmnNodeBase*)tempNode->get();
}
    
VappSettingPlmnNodeBase* VappSettingPlmnList::getNode(VfxId index)
{
    VfxU16 count = 0;
    VfxObjListEntry *tempNode = m_plmnNodeList.getValidHead();
    for (count = 0; count < index; count++)
	{
		tempNode = tempNode->getNext();
                if (tempNode == NULL)
    	        {
                    return NULL;    	
    	        }
	}
    return (VappSettingPlmnNodeBase*)tempNode->get();
}

void VappSettingPlmnList::appendNode(VappSettingPlmnNodeBase* node)
{
    m_plmnNodeList.append(node);
    m_count++;
}

void VappSettingPlmnList::deleteNode(VappSettingPlmnNodeBase* node)
{
    ASSERT(m_count != 0);
    m_plmnNodeList.removeOne(node);
    m_count--;
}

void VappSettingPlmnList::deleteNode(VfxId index)
{
    ASSERT(m_count != 0);
    VfxU16 count = 0;
    VfxObjListEntry *tempNode = m_plmnNodeList.getValidHead();
    for (count = 0; count < index; count++)
	{
		tempNode = tempNode->getNext();
	}
    m_plmnNodeList.removePos(tempNode);    
    m_count--;
}

void VappSettingPlmnList::insertNodeBefore(VappSettingPlmnNodeBase* node, VfxId index)
{
    ASSERT(node && index < m_count);
    VfxU16 count = 0;
    VfxObjListEntry *tempNode = m_plmnNodeList.getValidHead();
    for (count = 0; count < index; count++)
	{
		tempNode = tempNode->getNext();
	}
    m_plmnNodeList.insertBefore(tempNode, node);
	m_count++;
}

void VappSettingPlmnList::insertNodeAfter(VappSettingPlmnNodeBase* node, VfxId index)
{
    ASSERT(node && index < m_count);
    VfxU16 count = 0;
    VfxObjListEntry *tempNode = m_plmnNodeList.getValidHead();
    for (count = 0; count < index; count++)
	{
		tempNode = tempNode->getNext();
	}
    m_plmnNodeList.insertAfter(tempNode, node);
	m_count++;
}
void VappSettingPlmnList::moveNode(VfxId oldId, VfxId newId)
{
    ASSERT((oldId < m_count) && (newId < m_count));
    VappSettingPlmnNodeBase *node = getNode(oldId);
    if (oldId > newId)
	{
	    insertNodeBefore(node, newId);
		oldId++;
    	deleteNode(oldId);
	}
    else
    {
	    insertNodeAfter(node, newId);
    	deleteNode(oldId);
    }
}
