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
 *  vapp_cal_list_mgr.cpp
 *
 * Project:
 * --------
 *  Cosmos
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ***************************************************************************/
#include "vcp_list_menu.h"
#include "vapp_cal_list_mgr.h"
#ifndef __MMI_VCALENDAR__
#pragma arm section code = "DYNAMIC_CODE_CLNDR_ROCODE", rodata = "DYNAMIC_CODE_CLNDR_RODATA"
#endif
/***************************************************************************** 
 * Class VappCalListMgr
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappCalListMgr", VappCalListMgr, VfxObject);
void VappCalListMgr::onInit()
{
    VfxObject::onInit();

    VFX_ALLOC_MEM(m_list, m_capacity * sizeof(srv_tdl_event_task_struct), this);
    VFX_ALLOC_MEM(m_selList, m_capacity * sizeof(VfxU16), this);	

    for (VfxU32 i = 0; i < m_capacity; i++)
    {
        m_list[i].index = 0xFFFF;
        m_list[i].type = 0xFFFF;
        m_selList[i] = 0xFFFF;
    }

    m_count = 0;
    m_markedCount = 0;
}

void VappCalListMgr::onDeinit()
{
    VFX_FREE_MEM(m_selList);
    VFX_FREE_MEM(m_list);

    VfxObject::onDeinit();
}

VfxU16 VappCalListMgr::getAllList(const srv_tdl_vcal_enum &vcalType)
{
    return (srv_tdl_get_all_index(m_list, m_capacity, vcalType, &m_count));
}

VfxU16 VappCalListMgr::getList(const srv_tdl_search_filter_struct &filter)
{
    VfxU16 errorCode;

    errorCode = srv_tdl_search(
                        m_list, 
                        m_capacity, 
                        m_listType,
                        filter, 
                        &m_count);

    m_markedCount = 0;

    return errorCode;
}

MMI_BOOL VappCalListMgr::searchBySubCallback(const void *data, 
                                    const srv_tdl_vcal_enum vcal_type, 
                                    const srv_tdl_search_filter_struct search_filter)
{
    if (data == NULL)
    {
        return MMI_FALSE;
    }

    MMI_BOOL result = MMI_FALSE;

    WCHAR subject[MAX_TODO_LIST_NOTE / ENCODING_LENGTH];

    if (vcal_type == SRV_TDL_VCAL_EVENT)
    {
        srv_tdl_event_short_struct *event = (srv_tdl_event_short_struct*)data;

        if (event->present)
        {
            memcpy(subject, event->subject, MAX_TODO_LIST_NOTE);
        }
        else
        {
            return MMI_FALSE;
        }
    }
    
#ifdef __MMI_TASK_APP__
    else
    {
        srv_tdl_task_short_struct *task = (srv_tdl_task_short_struct*)data;

        if (task->present)
        {
            memcpy(subject, task->subject, MAX_TODO_LIST_NOTE);
        }
        else
        {
            return MMI_FALSE;
        }
    }
#endif

    if (VappCalListMgr::vappCalUcs2istr((CHAR *)subject, (CHAR *)search_filter.u.str_buf) != NULL)
    {
        result = MMI_TRUE;
    }

    return result;
}

VfxU16 VappCalListMgr::getListBySubject(const VfxWChar *subject)
{
    srv_tdl_search_filter_struct filter;

    filter.type = SRV_TDL_SEARCH_TYPE_SUBJECT;
    vfx_sys_wcscpy((VfxWChar*)(filter.u.str_buf), subject);

    VfxU16 errorCode = srv_tdl_search_ext(m_list,
                                    m_capacity,
                                    m_listType,
                                    filter,
                                    &m_count,
                                    VappCalListMgr::searchBySubCallback);
    m_markedCount = 0;

    return errorCode;
}

/*srv_tdl_event_task_struct VappCalListMgr::getListItem(const VfxU16 &index)
{
    return m_list[index];
}*/

VfxU16 VappCalListMgr::getListCount()
{
    return m_count;
}

VfxU16 VappCalListMgr::getListItemStoreIndex(const VfxU16 &index)
{
    return m_list[index].index;
}

/*srv_tdl_vcal_enum VappCalListMgr::getListItemType(const VfxU16 &index)
{
    return (srv_tdl_vcal_enum)m_list[index].type;
}*/

void VappCalListMgr::sortList(const srv_tdl_sort_type_enum &sortType)
{
    srv_tdl_sort(m_list, m_count, sortType);
}

/*srv_tdl_vcal_enum VappCalListMgr::getListType()
{
    return m_listType;
}*/

void VappCalListMgr::setSelListItemState(const VfxU16 &index, const VfxU16 &state)
{
    if (state == VCP_LIST_MENU_ITEM_STATE_SELECTED)
    {
        if (m_selList[index] != VCP_LIST_MENU_ITEM_STATE_SELECTED)
        {
            m_markedCount++;
        }
    }
    else if (state == VCP_LIST_MENU_ITEM_STATE_UNSELECTED)
    {
        if (m_selList[index] != VCP_LIST_MENU_ITEM_STATE_UNSELECTED)
        {
            m_markedCount--;
        }
    }

    m_selList[index] = state;
}

void VappCalListMgr::setSelListState(const VfxU16 &state)
{
    for (VfxU32 i = 0; i < m_capacity; i++)
    {
        m_selList[i] = state;
    }

    if (state == VCP_LIST_MENU_ITEM_STATE_SELECTED)
    {
        m_markedCount = m_count;
    }
    else if (state == VCP_LIST_MENU_ITEM_STATE_UNSELECTED)
    {
        m_markedCount = 0;
    }
}

VfxU16 VappCalListMgr::getSelListState(const VfxU16 &index)
{
    return m_selList[index];
}

VfxU16 VappCalListMgr::getSelListMarkedCount()
{
    return m_markedCount;
}

/*VfxU16 VappCalListMgr::getListCapacity()
{
    return m_capacity;
}*/

VfxU16 VappCalListMgr::getListIdx(const VfxU16 &storeIdx)
{
    for (VfxU32 i = 0; i < m_count; i++)
    {
        if (m_list[i].index == storeIdx)
        {
            return i;
        }
    }

    return m_count;
}

CHAR *VappCalListMgr::vappCalUcs2istr(CHAR *Dstr, CHAR *Sstr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *str1 = mmi_ucs2upr(Dstr); 
    CHAR *str2 = mmi_ucs2upr(Sstr); 

    CHAR *cp = (CHAR *) str1;
    CHAR *s1, *s2;
    
    if (!(*str2 || *(str2+1)))
    {    
        return((CHAR *)str1);
    }
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*cp || *(cp+1))
    {
        s1 = cp;
        s2 = (CHAR *) str2;
        
        while ((*s1 || *(s1+1)) 
               && (*s2 || *(s2+1)) 
               && !((*s1-*s2) || (*(s1+1)-*(s2+1))))
        {
            s1 += 2;
            s2 += 2;
        }
        
        if (!(*s2 || *(s2+1)))
        {
            return(cp);
        }
        
        cp += 2;
    }
    
    return NULL;   
}
#ifndef __MMI_VCALENDAR__
#pragma arm section code, rodata
#endif
