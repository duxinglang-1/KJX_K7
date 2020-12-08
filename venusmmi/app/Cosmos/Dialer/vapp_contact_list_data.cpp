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
 *  vapp_contact_list_data.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h" 
#if defined (__MMI_DIALER_SLIM__) && defined (__MMI_MAINLCD_240X320__)
#else
#include "vapp_contact_list_data.h"
#include "mmi_rp_cui_dialer_def.h"
#include "mmi_rp_vapp_dialer_def.h"
#include "mmi_rp_vapp_contact_def.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/
void VappContactDialerSearchListData::onInit()
{
    VfxObject::onInit();

    m_handle = NULL;
	VFX_OBJ_CREATE(m_queryMemManage, VappContactQueryManage, this);
}


void VappContactDialerSearchListData::onDeinit()
{
    if (m_handle != NULL)
    {
        srv_phb_free_query_handle(m_handle);
        m_handle = NULL;
    }
	VFX_OBJ_CLOSE(m_queryMemManage);

    VfxObject::onDeinit();
}


void VappContactDialerSearchListData::buildContactList(srv_phb_query_req_struct* req)
{
    if (m_handle == NULL)
    {
        m_handle = srv_phb_query(req, NULL);
    }
    else
    {
        srv_phb_query(req, m_handle);
    }
}


VfxU32 VappContactDialerSearchListData::getTotalCount() const
{
    return srv_phb_query_get_count(m_handle);
}


VfxWChar* VappContactDialerSearchListData::getName(VfxU32 index)
{
    return srv_phb_query_get_name(m_handle, index);
}


VfxWChar* VappContactDialerSearchListData::getNumber(VfxU32 index)
{
    memset(m_number, 0x00, sizeof(m_number));
    srv_phb_number_struct* number_p = srv_phb_query_get_number(m_handle, index, m_number);
    if (m_number[0]) //calllog
    {
        return m_number;
    }
    if (number_p) //phb
    {
        return number_p->number;
    }
    else
    {
        return (VfxWChar *)L"";
    }
}


VfxId VappContactDialerSearchListData::getIcon(VfxU32 index) const
{
#ifdef __MMI_DIALER_SEARCH__
    if (index < srv_phb_query_get_clog_count(m_handle))
    {
        return IMG_ID_DIALER_SEARCH_CALLLOG;
    }
    else
#endif /* __MMI_DIALER_SEARCH__ */
    {
        return IMG_ID_DIALER_SEARCH_CONTACT;
    }
}


VfxS32 VappContactDialerSearchListData::getMatchStart(VfxU32 index) const
{
    srv_phb_query_match_info_struct info;
    srv_phb_query_match_info_struct *p_info = &info;

    p_info = srv_phb_query_get_matched_info(m_handle, index);
    if (p_info)
    {
        return p_info->sequence_start;
    }
    else
    {
        return 0;
    }
}


VfxS32 VappContactDialerSearchListData::getMatchEnd(VfxU32 index) const
{
    srv_phb_query_match_info_struct info;
    srv_phb_query_match_info_struct *p_info = &info;

    p_info = srv_phb_query_get_matched_info(m_handle, index);
    if (p_info)
    {
        return p_info->sequence_start + p_info->sequence_len;
    }
    else
    {
        return 0;
    }
}


VfxU8 VappContactDialerSearchListData::getMatchField(VfxU32 index) const
{
    srv_phb_query_match_info_struct info;
    srv_phb_query_match_info_struct *p_info = &info;

    p_info = srv_phb_query_get_matched_info(m_handle, index);
    if (p_info)
    {
        return p_info->matched_field;
    }
    else
    {
        return 0;
    }
}


VfxBool VappContactDialerSearchListData::getMatchType(VfxU32 index) const
{
    srv_phb_query_match_info_struct info;
    srv_phb_query_match_info_struct *p_info = &info;

    p_info = srv_phb_query_get_matched_info(m_handle, index);
    if (!p_info)
    {
        return VFX_TRUE;
    }

    return p_info->is_sequence ? VFX_TRUE : VFX_FALSE;
}


VfxS32 VappContactDialerSearchListData::getMatchStartByPos(VfxU32 index, VfxU32 pos) const
{
    srv_phb_query_match_info_struct info;
    srv_phb_query_match_info_struct *p_info = &info;

    p_info = srv_phb_query_get_matched_info(m_handle, index);
    if (p_info && p_info->is_sequence == MMI_FALSE)
    {
        while (pos < SRV_PHB_QUERY_PATTERN_LEN)
        {
            if (p_info->mask[pos / 8] & (1 << (pos % 8)))
            {
                break;
            }
            pos++;
        }
        return pos;
    }
    else
    {
        return 0;
    }
}


VfxS32 VappContactDialerSearchListData::getMatchEndByPos(VfxU32 index, VfxU32 pos) const
{
    srv_phb_query_match_info_struct info;
    srv_phb_query_match_info_struct *p_info = &info;
    VfxBool flag = VFX_FALSE;

    p_info = srv_phb_query_get_matched_info(m_handle, index);
    if (p_info && p_info->is_sequence == MMI_FALSE)
    {
        while (pos < SRV_PHB_QUERY_PATTERN_LEN)
        {
            if (p_info->mask[pos / 8] & (1 << (pos % 8)) && flag == VFX_FALSE)
            {
                flag = VFX_TRUE;
                pos++;
                continue;
            }
            if ((p_info->mask[(pos + 7) / 8] & (1 << (pos % 8))) == 0 && flag == VFX_TRUE)
            {
                break;
            }
            pos++;
        }
        return pos;
    }
    else
    {
        return 0;
    }
}

#endif /* __MMI_DIALER_SLIM_SEARCH__ && __MMI_MAINLCD_240X320__*/
