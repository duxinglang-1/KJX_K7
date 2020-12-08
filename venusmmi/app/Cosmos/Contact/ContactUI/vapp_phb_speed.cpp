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
 *  vapp_phb_speed.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_PHB_SPEED_DIAL__ 
#include "vapp_contact_entry.h"
#include "vapp_phb_speed.h"
#include "vcui_phb_gprot.h"
#include "mmi_rp_vapp_dialer_def.h"
#include "mmi_rp_vapp_contact_def.h"


/***************************************************************************** 
 * Class VappContactSpeedDialPage
 *****************************************************************************/
void VappContactSpeedDialPage::onInit()
{
    VfxPage::onInit();

    componentInit();
    componentPlace();
    componentSetAction();
}


VfxU32 VappContactSpeedDialPage::getCount() const
{
    return 8;
}


VfxBool VappContactSpeedDialPage::getItemText(
         VfxU32 index,                    // [IN] the index of item
         VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
         VfxWString &text,                // [OUT] the text resource
         VcpListMenuTextColorEnum &color  // [OUT] the text color
         )
{
    if (index > 7)
    {
        return MMI_FALSE;
    }

    if (srv_phb_speed_dial_is_sync(index))
    {
        if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
        {
            if (mmi_wcslen(srv_phb_speed_dial_get_name(index)))
            {
                text.loadFromMem((VfxWChar *)srv_phb_speed_dial_get_name(index));
            }
            else
            {
                text = VFX_WSTR_RES(VAPP_PHB_STR_UNNAMED);
            }
        }
        if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
        {
            mmi_phb_contact_id contactID = srv_phb_speed_dial_get_store_index(index);
            MMI_BOOL ret = srv_phb_check_storage_accessible(srv_phb_get_storage(contactID));

            if (ret)
            {
                ContactEntry entry(srv_phb_speed_dial_get_store_index(index));
                VappContactNumber number = entry.getNumberById(srv_phb_speed_dial_get_number_type(index));
                text = number.getLabel();
                text += VFX_WSTR_RES(VAPP_PHB_STR_COLON);
                text += number.getString();
            }
            else
            {
                text = VFX_WSTR_RES(VAPP_PHB_STR_MOBILE);
                text += VFX_WSTR_RES(VAPP_PHB_STR_COLON);
                text += VFX_WSTR_MEM(srv_phb_speed_dial_get_number(index));
            }
        }
    }
    else
    {
        if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
        {
            text = VFX_WSTR_RES(STR_ID_VAPP_PHB_SETTING_SPEED_NO_SET);
        }
        if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
        {
            text = VFX_WSTR("");
        }
    }

    return MMI_TRUE;
}


VfxBool VappContactSpeedDialPage::getItemImage(
    VfxU32 index,                    // [IN] the index of item
    VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
    VfxImageSrc &image              // [OUT] the image resource
    )
{
    image.setResId(IMG_ID_DIALER_SPEED_2 + index);

    return MMI_TRUE;
}


mmi_ret VappContactSpeedDialPage::onProc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_PHB_LIST_RESULT:
        {
            vcui_phb_list_result_event_struct *result = (vcui_phb_list_result_event_struct*) evt;
            if (result->result && result->select_count > 0)
            {
                mmi_phb_contact_id id;
                id = vcui_phb_list_get_contact_id_by_index(((mmi_group_event_struct*) evt)->sender_id, 0);

                VfxU32 type, sub_type, sub_id;
                vcui_phb_list_get_selected_contact_data(((mmi_group_event_struct*) evt)->sender_id, m_number, MMI_PHB_NUMBER_PLUS_LENGTH);
                vcui_phb_list_get_selected_contact_data_type(((mmi_group_event_struct*) evt)->sender_id, &type, &sub_type, &sub_id);

                if (srv_phb_check_valid_number(m_number))
                {
                    srv_phb_update_speed_dial(m_activeIndex, id, m_number, sub_id); 
                    m_list->resetAllItems(VFX_TRUE);
                }
            }

            vcui_phb_list_close(((mmi_group_event_struct*) evt)->sender_id);
            break;
        }
    }

    return VfxPage::onProc(evt);
}


void VappContactSpeedDialPage::componentInit()
{
    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_PHB_SPEED_DIAL_LIST));
    setTopBar(bar);

    VFX_OBJ_CREATE(m_list, VcpListMenu, this);
}


void VappContactSpeedDialPage::componentPlace()
{
    m_list->setSize(getSize());
    m_list->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    m_list->setContentProvider(this);
    m_list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_MULTI_TEXT);
}


void VappContactSpeedDialPage::componentSetAction()
{
    m_list->m_signalItemTapped.connect(this, &VappContactSpeedDialPage::itemTapped);
}


void VappContactSpeedDialPage::itemTapped(VcpListMenu *list, VfxU32 index)
{
    VcpCommandPopup *option;
    VFX_OBJ_CREATE(option, VcpCommandPopup, this);

    option->setInfoType(VCP_POPUP_TYPE_INFO);
    option->setText(VFX_WSTR_RES(STR_ID_VAPP_PHB_SPEED_DIAL_SELECT_ACTION));

    option->addItem(1, VFX_WSTR_RES(STR_ID_VAPP_PHB_SPEED_SELECT_FROM_CONTACT));
    if (srv_phb_speed_dial_is_sync(index))
    {
        option->addItem(2, VFX_WSTR_RES(STR_GLOBAL_CLEAR));
    }
    option->addItem(3, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);

    option->m_signalButtonClicked.connect(this, &VappContactSpeedDialPage::onCommondClicked);

    option->show(VFX_TRUE);

    m_activeIndex = index;
}


void VappContactSpeedDialPage::onCommondClicked(VfxObject* obj, VfxId id)
{
    if (id == 1)
    {
        selectContact();
    }
    else if (id == 2)
    {
        deleteSpeedDial();
    }
}


void VappContactSpeedDialPage::selectContact()
{
    mmi_id cui_id = vcui_phb_list_create(getApp()->getGroupId());

    vcui_phb_list_set_req_field(cui_id, MMI_PHB_CONTACT_FIELD_NUMBER);
    vcui_phb_list_set_req_type(cui_id, VAPP_PHB_LIST_SINGLE_SELECTOR);
    vcui_phb_list_set_title_str(cui_id, STR_ID_VAPP_PHB_SELECT_A_CONTACT);
    vcui_phb_list_run(cui_id);

    vfxSetCuiCallerScr(cui_id, getMainScr());
}


void VappContactSpeedDialPage::deleteSpeedDial()
{
    srv_phb_delete_speed_dial(m_activeIndex);
    m_list->resetAllItems(VFX_TRUE);
}
#endif /* __MMI_PHB_SPEED_DIAL__ */


