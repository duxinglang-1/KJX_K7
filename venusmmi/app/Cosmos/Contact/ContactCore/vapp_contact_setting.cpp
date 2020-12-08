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
 *  vapp_contact_setting.cpp
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
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#include "vapp_contact_setting.h"
#include "vapp_contact_storage.h"
#include "mmi_rp_vapp_contact_def.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "PhbSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
#include "FileMgrSrvGprot.h"
#endif
#ifdef __cplusplus
}
#endif


/***************************************************************************** 
* Class VappContactStorageProvider
 *****************************************************************************/
void VappContactStorageProvider::onInit()
{
    VfxObject::onInit();

    m_count = 0;
    m_storageList[m_count++] = PHB_STORAGE_NVRAM;

    for (VfxU32 i = 0; i < ContactSim::getTotal(); i++)
    {
        if (srv_sim_ctrl_is_inserted(mmi_frm_index_to_sim(i)))
        {
            m_storageList[m_count++] = (phb_storage_enum) (PHB_STORAGE_SIM + i);
        }
    }

#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    if (srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV))
    {
        m_storageList[m_count++] = PHB_STORAGE_TCARD;
    }
#endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */

    storageSelectInit();
}


void VappContactStorageProvider::storageSelectInit()
{
    for (VfxU32 i = 0; i < m_count; i++)
    {
        if (ContactStorage::getMask() & ContactStorage::getMask(m_storageList[i]))
        {
            m_chooseList[i] = VFX_TRUE;
        }
        else
        {
            m_chooseList[i] = VFX_FALSE;
        }
    }
}


VfxU32 VappContactStorageProvider::getCount() const
{
    return m_count;
}


VfxBool VappContactStorageProvider::getItemText(
         VfxU32 index,                    // [IN] the index of item
         VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
         VfxWString &text,                // [OUT] the text resource
         VcpListMenuTextColorEnum &color  // [OUT] the text color
         )
{
    VFX_ASSERT(index < getCount());

    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        text = ContactStorage::getName(m_storageList[index]);
    }
    else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
        text.format("%d/%d ",
        srv_phb_get_used_contact(m_storageList[index]),
        srv_phb_get_total_contact(m_storageList[index]));
        text += VFX_WSTR_RES(VAPP_PHB_STR_CONTACTS_APPEND);
    }

    return VFX_TRUE;
}


VcpListMenuItemStateEnum VappContactStorageProvider::getItemState(
        VfxU32 index   // [IN] index of the item
        ) const
{
    VFX_ASSERT(index < getCount());

    if (m_chooseList[index])
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }
    else
    {
        return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
    }
}


VfxBool VappContactStorageProvider::getItemIsDisabled(VfxU32 index) const
{
    VFX_ASSERT(index < getCount());

    for (VfxU32 i = 0, j = 0; i < ContactSim::getTotal(); i++)
    {
        mmi_sim_enum sim = mmi_frm_index_to_sim(i);
        if (srv_sim_ctrl_is_inserted(sim))
        {
            if (j++ == (index - 1) && !srv_sim_ctrl_is_available(sim))
            {
                return VFX_TRUE;
            }
        }
    }

    return VFX_FALSE;
}


void VappContactStorageProvider::setStorageDone()
{
    VfxU32 storage = 0;

    for (VfxU32 i = 0; i < m_count; i++)
    {
        if (m_chooseList[i])
        {
            storage |= ContactStorage::getMask(m_storageList[i]);
        }
    }

    srv_phb_set_storage_mask((VfxU8) storage);
}


void VappContactStorageProvider::setStorageState(VcpListMenu *list, VfxU32 index, VcpListMenuItemStateEnum state)
{
    if (state == VCP_LIST_MENU_ITEM_STATE_UNSELECTED)
    {
        m_chooseList[index] = VFX_FALSE;
    }
    else if (state == VCP_LIST_MENU_ITEM_STATE_SELECTED)
    {
        m_chooseList[index] = VFX_TRUE;
    }
}


VfxBool VappContactStorageProvider::isUserSelect()
{
    for (VfxU32 i = 0; i < m_count; i++)
    {
        if (m_chooseList[i])
        {
            return VFX_TRUE;
        }
    }

    return VFX_FALSE;
}


VfxWString VappContactStorageProvider::getStorageString()
{
    VfxWString storage;

    if (ContactStorage::getMask() & SRV_PHB_STORAGE_MASK_PHONE)
    {
        storage += ContactStorage::getName(PHB_STORAGE_NVRAM);
        storage += VFX_WSTR("  ");
    }

    for (VfxU32 i = 0; i < ContactSim::getTotal(); i++)
    {
        if (ContactStorage::getMask() & ContactStorage::getMask((phb_storage_enum) (PHB_STORAGE_SIM + i)))
        {
            storage += ContactStorage::getName((phb_storage_enum) (PHB_STORAGE_SIM + i));
            storage += VFX_WSTR("  ");
        }
    }
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    if (srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV) && (ContactStorage::getMask() & SRV_PHB_STORAGE_MASK_TCARD))
    {
        storage += ContactStorage::getName(PHB_STORAGE_TCARD);
    }
#endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */
    return storage;
}


#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
void VappContactStorageProvider::updateProvider()
{
    onInit(); // re-onInit better re-create provider
}
#endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */


#ifdef __MMI_PHB_LAST_NAME_FIELD__
/***************************************************************************** 
* Class VappContactNameDisplayProvider
*****************************************************************************/
void VappContactNameDisplayProvider::onInit()
{
    VfxObject::onInit();

    if (srv_phb_get_name_display() == SRV_CONTACT_NAME_DISPLAY_TYPE_1)
    {
        m_chooseList[0] = VFX_TRUE;
        m_chooseList[1] = VFX_FALSE;
    }
    else
    {
        m_chooseList[0] = VFX_FALSE;
        m_chooseList[1] = VFX_TRUE;
    }
}


VfxU32 VappContactNameDisplayProvider::getCount() const
{
    return 2;
}


VfxBool VappContactNameDisplayProvider::getItemText(
         VfxU32 index,                    // [IN] the index of item
         VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
         VfxWString &text,                // [OUT] the text resource
         VcpListMenuTextColorEnum &color  // [OUT] the text color
        )
{
    if (index == 0)
    {
        text.loadFromRes(STR_ID_VAPP_PHB_SETTING_NAME_DISPLAY_FIRST_NAME_LAST);
    }
    else
    {
        text.loadFromRes(STR_ID_VAPP_PHB_SETTING_NAME_DISPLAY_FIRST_NAME_FIRST);
    }

    return VFX_TRUE;
}


VcpListMenuItemStateEnum VappContactNameDisplayProvider::getItemState(
        VfxU32 index   // [IN] index of the item
        ) const
{
    if (m_chooseList[index])
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }
    else
    {
        return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
    }
}


VfxWString VappContactNameDisplayProvider::getNameDisplayString()
{
    if (srv_phb_get_name_display() == SRV_CONTACT_NAME_DISPLAY_TYPE_1)
    {
        return VFX_WSTR_RES(STR_ID_VAPP_PHB_SETTING_NAME_DISPLAY_FIRST_NAME_LAST);
    }
    else
    {
        return VFX_WSTR_RES(STR_ID_VAPP_PHB_SETTING_NAME_DISPLAY_FIRST_NAME_FIRST);
    }
}
#endif /* __MMI_PHB_LAST_NAME_FIELD__ */

