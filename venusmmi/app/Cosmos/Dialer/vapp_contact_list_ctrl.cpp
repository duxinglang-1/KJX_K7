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
 *  vapp_contact_list_ctrl.cpp
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
#if defined( __MMI_DIALER_SLIM__) && defined (__MMI_MAINLCD_240X320__)
#else
#include "vapp_contact_list_ctrl.h"
#include "mmi_rp_cui_dialer_def.h"
#include "mmi_rp_vapp_dialer_def.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "vcp_form.h"
#include "..\Contact\ContactCore\vapp_contact_list.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "PhbSrvGprot.h"

#ifdef __cplusplus
}
#endif

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
void VappContactListMenuContentProvider::onInit()
{
    VfxObject::onInit();

    VFX_OBJ_CREATE(m_listContact, VappContactDialerSearchListData, this);

    VfxWChar a[2];
    a[0] = 0;
    a[1] = 0;
    m_sendSignal = VFX_FALSE;

    //srv_phb_query_req_struct req;
    req.item_order = MMI_TRUE;
    req.filter = srv_phb_create_contact_filter();
#ifdef __MMI_DIALER_SEARCH__
    srv_phb_contact_filter_set_query(req.filter, a, MMI_PHB_CONTACT_FIELD_NUMBER, SRV_PHB_QUERY_TYPE_DS);
#else
    srv_phb_contact_filter_set_query(req.filter, a, MMI_PHB_CONTACT_FIELD_NUMBER, SRV_PHB_QUERY_TYPE_PARTIAL);
#endif
    srv_phb_contact_filter_set_query_entry(req.filter, &VappContactListMenuContentProvider::onQueryCallback, 0, 10, getObjHandle());
    //m_async = VFX_TRUE;
    // asm memory entry
    srv_phb_contact_filter_set_mem_entry(req.filter, &VappContactListMenuContentProvider::memAllocator, &VappContactListMenuContentProvider::memDeallocator, getObjHandle());

   // VFX_OBJ_CREATE(m_queryMemManage, VappContactQueryManage, this);
	m_queryMemManage = m_listContact->m_queryMemManage;
    m_listContact->buildContactList(&req);

  // srv_phb_free_contact_filter(req.filter);
}


void VappContactListMenuContentProvider::onQueryCallback(srv_phb_query_async_cb_result_struct *ret)
{
    VappContactListMenuContentProvider *pThis = (VappContactListMenuContentProvider *)VfxObject::handleToObject((VfxObjHandle)ret->user_data);

    if (!pThis)
    {
        return;
    } 
    if (srv_phb_query_get_count(pThis->m_listContact->m_handle) < 3 && ret->result == 0) //  don't refresh list if ...
    {
        return;
    }
   
        if ( ret->result == 1|| !pThis->m_sendSignal) 
        {
            pThis->m_sendSignal = VFX_TRUE;
            pThis->m_signalRefresh.postEmit();
            //vfxPostInvoke(this , &VappDialerPage::onRefresh);
        }
    

}


void *VappContactListMenuContentProvider::memAllocator(VfxU32 size, void *userData)
{
    void *memPtr = NULL;
    VappContactListMenuContentProvider *self = (VappContactListMenuContentProvider *)VfxObject::handleToObject((VfxObjHandle)userData);
   /* VfxMainScr *mainScr = findMainScr(self);

    if (mainScr && size > 0)
    {
        memPtr = mmi_frm_asm_alloc_r(mainScr->getGroupId(), size);
    }*/
    if (size > 0 && self && self->m_queryMemManage)
    {
        //memPtr = mmi_frm_asm_alloc_r(mainScr->getGroupId(), size);

        memPtr = self->m_queryMemManage->getNewBuffer(size);
    }

    return memPtr;
}


void VappContactListMenuContentProvider::memDeallocator(void *mem, void *userData)
{
    VappContactListMenuContentProvider *self = (VappContactListMenuContentProvider *)VfxObject::handleToObject((VfxObjHandle)userData);
    /*VfxMainScr *mainScr = findMainScr(self);

    if (mainScr && mem)
    {
        mmi_frm_asm_free_r(mainScr->getGroupId(), mem);
    }*/
    if (self && mem && self->m_queryMemManage)
    {
        self->m_queryMemManage->freeBuffer(mem);
    }
}


VfxMainScr *VappContactListMenuContentProvider::findMainScr(VfxObject *obj)
{
    while(obj)
    {
        if(obj->isKindOf(VFX_OBJ_CLASS_INFO(VfxMainScr)))
            return VFX_OBJ_DYNAMIC_CAST(obj, VfxMainScr);

        obj = obj->getParent();
    }
    return NULL;
}


void VappContactListMenuContentProvider::onDeinit()
{
    //m_listContact->onDeinit();
     srv_phb_free_contact_filter(req.filter);
}


VfxU32 VappContactListMenuContentProvider::getCount() const
{
    return m_listContact->getTotalCount();
}


VfxBool VappContactListMenuContentProvider::getItemText(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VfxWString &text,
        VcpListMenuTextColorEnum &color
        )
{
    if (fieldType != VCP_LIST_MENU_FIELD_TEXT && fieldType != VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
        return VFX_FALSE;
    }

    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        text.loadFromMem(m_listContact->getName(index));
    }
    else
    {
        text.loadFromMem(m_listContact->getNumber(index));
    }

    return VFX_TRUE;
}


VfxBool VappContactListMenuContentProvider::getItemTextFormat(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VcpRichText &format
        )
{
    if (m_listContact->getMatchStart(index) != m_listContact->getMatchEnd(index))
    {
        if (MMI_PHB_CONTACT_FIELD_ID_NAME == m_listContact->getMatchField(index) && fieldType == VCP_LIST_MENU_FIELD_TEXT)
        {
            setTextFormat(index, format);
        }
        else if (MMI_PHB_CONTACT_FIELD_ID_NUMBER == m_listContact->getMatchField(index) && fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
        {
            setTextFormat(index, format);
        }
    }

    return VFX_TRUE;
}


void VappContactListMenuContentProvider::setTextFormat(VfxU32 index, VcpRichText &format)
{
    if (m_listContact->getMatchType(index))
    {
        format.setRange(m_listContact->getMatchStart(index), m_listContact->getMatchEnd(index));
        format.setTextColor(VfxColor(VCP_FORM_DARK_FONT_COLOR));
        format.setTextBgColor(VfxColor(VFX_COLOR_RES(COL_ID_DIALER_HINT_BG)));
    }
    else
    {
        VfxU32 pos = 0;

        format.setRange(m_listContact->getMatchStartByPos(index, pos), m_listContact->getMatchEndByPos(index, pos));
        format.setTextColor(VfxColor(VCP_FORM_DARK_FONT_COLOR));
        format.setTextBgColor(VfxColor(VFX_COLOR_RES(COL_ID_DIALER_HINT_BG)));
        pos = m_listContact->getMatchEndByPos(index, pos);

        while (m_listContact->getMatchStartByPos(index, pos) != m_listContact->getMatchEndByPos(index, pos))
        {
            VcpRichText txtFormat;
            txtFormat.setRange(m_listContact->getMatchStartByPos(index, pos), m_listContact->getMatchEndByPos(index, pos));
            txtFormat.setTextColor(VfxColor(VCP_FORM_DARK_FONT_COLOR));
            txtFormat.setTextBgColor(VfxColor(VFX_COLOR_RES(COL_ID_DIALER_HINT_BG)));
            format.add(txtFormat, this);

            pos = m_listContact->getMatchEndByPos(index, pos);
        }
    }
}


VfxBool VappContactListMenuContentProvider::getItemImage(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VfxImageSrc &image
        )
{
    if (fieldType == VCP_LIST_MENU_FIELD_ICON)
    {
        image = VfxImageSrc(m_listContact->getIcon(index));
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


void VappContactListMenuContentProvider::search(VfxWChar *str)
{
    //srv_phb_query_req_struct req;
    //req.item_order = MMI_TRUE;
    //req.filter = srv_phb_create_contact_filter();
    srv_phb_contact_filter_set_storage(req.filter, srv_phb_get_storage_mask());
    req.align_field = MMI_PHB_CONTACT_FIELD_NAME | MMI_PHB_CONTACT_FIELD_NUMBER;
#ifdef __MMI_DIALER_SEARCH__
    srv_phb_contact_filter_set_query(req.filter, str, MMI_PHB_CONTACT_FIELD_ALL, SRV_PHB_QUERY_TYPE_DS);
#else
    srv_phb_contact_filter_set_query(req.filter, str, MMI_PHB_CONTACT_FIELD_ALL, SRV_PHB_QUERY_TYPE_FULL);
#endif

    srv_phb_contact_filter_set_query_entry(req.filter, &VappContactListMenuContentProvider::onQueryCallback, 0, SRV_PHB_QUERY_MAX_TIME, getObjHandle());
    //m_async = VFX_TRUE;
    // asm memory entry
    srv_phb_contact_filter_set_mem_entry(req.filter, &VappContactListMenuContentProvider::memAllocator, &VappContactListMenuContentProvider::memDeallocator, getObjHandle());

    m_listContact->buildContactList(&req);

    //srv_phb_free_contact_filter(req.filter);
}

#endif /* __MMI_DIALER_SLIM__  && __MMI_MAINLCD_240X320__*/

