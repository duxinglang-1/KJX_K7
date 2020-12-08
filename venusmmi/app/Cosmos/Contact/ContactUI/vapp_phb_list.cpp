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
 *  vapp_phb_list.cpp
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

#include "vapp_phb_list.h"
#include "vapp_contact_entry.h"
#include "mmi_rp_vapp_dialer_def.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "vcp_form.h"
#include "vapp_phb_menu_list_cp.h"

#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
#include "mmi_rp_app_usbsrv_def.h"
#endif

/***************************************************************************** 
 * Class VappPhbListCp
 *****************************************************************************/
void VappPhbListCp::onInit()
{
    VcpGroupListMenu::onInit();

#if !defined(__MMI_MAINLCD_480X800__)
    setItemHeight(59);
#endif

    // reset single mask
    m_singleMask = VFX_FALSE;

    // reset tcard mask
    m_tcardMask = VFX_FALSE;

    // auto refresh list
    m_stopRefresh = VFX_FALSE;

    // seek bar
    enableSeekBar(VFX_TRUE);

    // search bar
    enableSearchBar();

    if (!m_b2ndReady)
    {
        // list provider config
        VFX_OBJ_CREATE(m_list, ContactList, this);

        // set align field
        setAlignField(MMI_PHB_CONTACT_FIELD_NAME);

        // set search string
        setSearchString(VFX_WSTR_EMPTY);

        // content provider
        setContentProvider(this);

        // set list type
        setListType(VAPP_PHB_LIST_NORMAL);
    }
    else
    {
        m_list = NULL;

        // content provider
        setContentProvider(NULL);
    }

    // auto anitmation
    setAutoAnimate(VFX_TRUE);

    // set empty string    
    m_str = VAPP_PHB_STR_CONTACT_EMPTY;

    // list signal
    if (!m_b2ndReady)
    {
        m_list->m_signalRefresh.connect(this, &VappPhbListCp::onListRefresh);
        m_list->m_signalGettingList.connect(this, &VappPhbListCp::onListGetting);
        m_list->m_signalReady.connect(this, &VappPhbListCp::onListReady);
    }

    // create bottom frame
    if (!m_b2ndReady)
    {
        VFX_OBJ_CREATE(m_countText, VappPhbListCountFrame, this);
    }
    else
    {
        m_countText = NULL;
    }

    // create activity
    if (!m_b2ndReady)
    {
        VFX_OBJ_CREATE(m_activity, VcpActivityIndicator, this);
        m_activity->setAnchor(0.5f, 0.5f);
        m_activity->setPos(getSize().width/2, getSize().height/2);
        m_activity->setHiddenWhenStopped(VFX_TRUE);

        // show activity
        // m_activity->start(); // if do, it's ready
    }
    else
    {
        m_activity = NULL;
    }

    m_signalItemTapped.connect(this, &VappPhbListCp::onItemTaped);
    m_signalItemLongTapped.connect(this, &VappPhbListCp::onItemLongTaped);
    m_signalBoundsChanged.connect(this, &VappPhbListCp::onListBoundsChanged);

    ContactTask *task = GET_CONTACT_TASK();
    task->m_signalTask.connect(this, &VappPhbListCp::onContactUpdated);
}


void VappPhbListCp::onItemTaped(VcpGroupListMenu *list, VcpMenuPos pos)
{
    getSearchBar()->getSearchEditor()->deactivate();
}


void VappPhbListCp::onItemLongTaped(VcpGroupListMenu *list, VcpMenuPos pos)
{
    getSearchBar()->getSearchEditor()->deactivate();
}


void VappPhbListCp::setProvider()
{
    m_b2ndReady = VFX_FALSE;

    // list provider config
    if (!m_list)
    {
        VFX_OBJ_CREATE(m_list, ContactList, this);

        // set align field
        setAlignField(MMI_PHB_CONTACT_FIELD_NAME);

        // set search string
        setSearchString(VFX_WSTR_EMPTY);

        // content provider
        setContentProvider(this);

        // set list type
        setListType(VAPP_PHB_LIST_NORMAL);

        m_list->m_signalRefresh.connect(this, &VappPhbListCp::onListRefresh);
        m_list->m_signalGettingList.connect(this, &VappPhbListCp::onListGetting);
        m_list->m_signalReady.connect(this, &VappPhbListCp::onListReady);
    }

    if (!m_countText)
    {
        VFX_OBJ_CREATE(m_countText, VappPhbListCountFrame, this);
    }
    
    if (!m_activity)
    {
        VFX_OBJ_CREATE(m_activity, VcpActivityIndicator, this);
        m_activity->setAnchor(0.5f, 0.5f);
        m_activity->setPos(getSize().width/2, getSize().height/2);
        m_activity->setHiddenWhenStopped(VFX_TRUE);

        // show activity
        if (!srv_phb_startup_is_phb_ready())
        {
            m_activity->start();
        }
    }
}


void VappPhbListCp::setListType(vapp_phb_list_type_enum type)
{
    m_listType = type;

    if (type == VAPP_PHB_LIST_NORMAL)
    {
        setAlignField(MMI_PHB_CONTACT_FIELD_NAME);
        setMenuMode(VCP_LIST_MENU_MODE_NORMAL);
        resetAllItems(VFX_TRUE);

        VFX_OBJ_CLOSE(m_mark);
        m_signalItemSelectionStateChanged.disconnect(this, &VappPhbListCp::onStateChanged);
    }
    else if (type == VAPP_PHB_LIST_SINGLE)
    {
        setMenuMode(VCP_LIST_MENU_MODE_NORMAL);
        resetAllItems(VFX_TRUE);

        m_signalItemSelectionStateChanged.disconnect(this, &VappPhbListCp::onStateChanged);
    }
    else if (type == VAPP_PHB_LIST_MARK)
    {
        // mark several
        VFX_OBJ_CREATE(m_mark, ContactMark, this);
        m_mark->setList(m_list);

        // reset list
        setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION);
        resetAllItems(VFX_TRUE);

        m_signalItemSelectionStateChanged.connect(this, &VappPhbListCp::onStateChanged);
    }
}


void VappPhbListCp::setSearchString(const VfxWString& search)
{
    VcpListMenuSearchBar *m_searchbar = enableSearchBar();
    VcpTextEditor        *m_editor;

    m_searchText = search;
    m_editor = m_searchbar->getSearchEditor();

    VfxWString text = search;
    m_editor->setText(text, MMI_PHB_QSEARCH_LENGTH - 1);
    m_editor->setHint(STR_GLOBAL_SEARCH);
    m_editor->m_signalTextChanged.connect(this, &VappPhbListCp::onTextChanged);

    // query result
    m_list->setQuery(search);
}


void VappPhbListCp::setAlignField(VfxU32 alignField)
{
    if (alignField & MMI_PHB_CONTACT_FIELD_NAME)
    {
        if((alignField & MMI_PHB_CONTACT_FIELD_ALL) == (MMI_PHB_CONTACT_FIELD_NAME | MMI_PHB_CONTACT_FIELD_NUMBER))
        {
            m_list->setAlignField(alignField);
            //setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_MULTI_TEXT);
            setCellStyle(VCP_LIST_MENU_CELL_STYLE_CUSTOM);
            m_listMode = VappPhbListMenuItemBase::VCP_LIST_MENU_CELL_STYLE_MSG;
        }
        else
        {
            m_list->setAlignField(MMI_PHB_CONTACT_FIELD_NAME);
            //setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT);
            setCellStyle(VCP_LIST_MENU_CELL_STYLE_CUSTOM);
            m_listMode = VappPhbListMenuItemBase::VCP_LIST_MENU_CELL_STYLE_SNS;
        }
    }
    else
    {
        m_list->setAlignField(alignField);
        //setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_MULTI_TEXT);
        setCellStyle(VCP_LIST_MENU_CELL_STYLE_CUSTOM);
        m_listMode = VappPhbListMenuItemBase::VCP_LIST_MENU_CELL_STYLE_MSG;
    }
}


void VappPhbListCp::setStorage(phb_storage_enum storage)
{
    m_list->setStorage(1 << storage);
}


#ifdef __MMI_PHB_CALLER_GROUP__
void VappPhbListCp::setGroup(VfxU8 groupId, VfxBool isEqual)
{
    m_list->setGroup(groupId, isEqual);
}
#endif /* __MMI_PHB_CALLER_GROUP__*/ 

void VappPhbListCp::setEmptyStr(VfxResId str)
{
    m_str = str;
}


void VappPhbListCp::setRefreshFlag(VfxBool flag)
{
    m_stopRefresh = flag;
}


void VappPhbListCp::setListStorageType(vapp_phb_list_storage_type_enum storageType)
{
    m_storageType = storageType;
}


void VappPhbListCp::markAll()
{
    m_mark->markAll();
    resetAllItems(VFX_TRUE);
}


void VappPhbListCp::unMarkAll()
{
    m_mark->unMarkAll();
    resetAllItems(VFX_TRUE);
}


ContactMark *VappPhbListCp::getMarked() const
{
    return m_mark;
}


VfxWString VappPhbListCp::getAlignValue(VfxU32 index, VfxU32 groupIndex)
{
    mmi_phb_contact_id id = (mmi_phb_contact_id) m_list->getId(index, groupIndex);
    VfxU32 type = m_list->getType(index, groupIndex);
    VfxU32 subId = m_list->getSubId(index, groupIndex);

    // only support email & number
    switch (type)
    {
        case MMI_PHB_CONTACT_FIELD_ID_NUMBER:
        {
            return ContactEntry(id).getNumberById(subId).getString();
        }
        case MMI_PHB_CONTACT_FIELD_ID_EMAIL:
        {
            return ContactEntry(id).getEmailById(subId).getString();
        }
    }

    return VFX_WSTR_EMPTY;
}


void VappPhbListCp::getList()
{
    m_list->getList();
}


ContactList* VappPhbListCp::getListObject()
{
    return m_list;
}


VfxU32 VappPhbListCp::getCount(VfxU32 group) const
{
    return m_list->getCountByGroup(group);
}


VfxU32 VappPhbListCp::getGroupCount() const
{
    return m_list->getGroupCount();
}


VfxWString& VappPhbListCp::getSearchString()
{
    return m_searchText;
}


VfxBool VappPhbListCp::hasGroupHeader(VfxS32 group) const
{
    if (!m_searchText.isEmpty())
    {
        return VFX_FALSE;
    }

    return VFX_TRUE;
}


VfxU32 VappPhbListCp::getId(VfxU32 index, VfxU32 groupIndex)
{
    return m_list->getId(index, groupIndex);
}


VfxWString VappPhbListCp::getGroupString(VfxU32 group)
{
    return m_list->getGroupString(group);
}


VfxBool VappPhbListCp::getMenuEmptyText(
    VfxWString &text,                // [OUT] the text resource
    VcpListMenuTextColorEnum &color  // [OUT] the text color
    )
{
    if (m_list->isUpdating())
    {
        text = VFX_WSTR_EMPTY;
    }
    else
    {
        text.loadFromRes(m_str);
    }

    return VFX_TRUE;
}


VfxBool VappPhbListCp::getItemText(
            VcpMenuPos pos,                    // [IN] the position of item
            VcpListMenuFieldEnum fieldType,    // [IN] the type of the field in the cell
            VfxWString &text,                  // [OUT] the text resource
            VcpListMenuTextColorEnum &color    // [OUT] the text color
            )
{
    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        ContactEntry entry(getId(pos.pos, pos.group));
        text = entry.getName().getString();

        if (text.isEmpty())
        {
            //if (getCellStyle() == VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT)
            if (VappPhbListMenuItemBase::VCP_LIST_MENU_CELL_STYLE_SNS == m_listMode)
            {
                ContactEntry entry(getId(pos.pos, pos.group));
                VfxU32 count = entry.getNumber();
                if (count > 0)
                {
                    VappContactNumber number = entry.getNextNumber();
                    text = number.getString();
                    return VFX_TRUE;
                }
                count = entry.getEmail();
                if (count > 0)
                {
                    VappContactEmail email = entry.getNextEmail();
                    text = email.getString();
                    return VFX_TRUE;
                }
                else
                {
                    text.loadFromRes(VAPP_PHB_STR_UNNAMED);
                    return VFX_TRUE;
                }
            }
            else
            {
                text.loadFromRes(VAPP_PHB_STR_UNNAMED);
                return VFX_TRUE;
            }
        }
    }
    else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
        ContactEntry entry(getId(pos.pos, pos.group));
        VfxU32 type = m_list->getType(pos.pos, pos.group);
        VfxU32 subType = m_list->getSubType(pos.pos, pos.group);
        VfxU32 subId = m_list->getSubId(pos.pos, pos.group);
        switch (type)
        {
            case MMI_PHB_CONTACT_FIELD_ID_NUMBER:
            {
                VappContactNumber number = entry.getNumberById(subId);
                text = number.getLabel();
                text += VFX_WSTR_RES(VAPP_PHB_STR_COLON);
                text += number.getString();
                break;
            }
            case MMI_PHB_CONTACT_FIELD_ID_EMAIL:
            {
                VappContactEmail email = entry.getEmailById(subId);
                text = email.getLabel();
                text += VFX_WSTR_RES(VAPP_PHB_STR_COLON);
                text += email.getString();
                break;
            }
        }
    }
    else if (fieldType == VCP_LIST_MENU_FIELD_GROUP_HEADER_TEXT)
    {
        text = getGroupString((VfxU32)pos.group);
    }
    color = VCP_LIST_MENU_TEXT_COLOR_HIGHLIGHT;

    return VFX_TRUE;
}


VfxBool VappPhbListCp::getItemTextFormat(
            VcpMenuPos pos,                  // [IN] the position of item
            VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
            VcpRichText &format              // [OUT] the text resource
            )
{

    //m_searchbar = getSearchBar();
    //m_editor = m_searchbar->getSearchEditor();

    if (fieldType == VCP_LIST_MENU_FIELD_TEXT && vfx_sys_wcslen(m_searchText.getBuf()) > 0)
    //if (fieldType == VCP_LIST_MENU_FIELD_TEXT && vfx_sys_wcslen(m_editor->getText()) > 0)
    {
        // matched info
        ContactMatchInfo& matchInfo = m_list->getMatchInfo(pos.pos, pos.group);

        // get range info, 0 to get range from start postion
        VfxPoint range = matchInfo.getRange(0);

        format.setRange(range.x, range.y);
        format.setTextColor(VfxColor(VCP_FORM_DARK_FONT_COLOR));
        format.setTextBgColor(VfxColor(VFX_COLOR_RES(COL_ID_DIALER_HINT_BG)));

        while (1)
        {
            // get next range from the end postion of prev. one
            range = matchInfo.getRange(range.y);

            if (range.x >= 0)
            {
                VcpRichText txtFormat;
                txtFormat.setRange(range.x, range.y);
                txtFormat.setTextColor(VfxColor(VCP_FORM_DARK_FONT_COLOR));
                txtFormat.setTextBgColor(VfxColor(VFX_COLOR_RES(COL_ID_DIALER_HINT_BG)));

                format.add(txtFormat, this);
            }
            else
            {
                break;
            }
        }

        return VFX_TRUE;
    }

    return VFX_FALSE;
}


VfxBool VappPhbListCp::getItemImage(
            VcpMenuPos pos,                  // [IN] the position of item
            VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
            VfxImageSrc &image               // [OUT] the image resource
            )
{
    if (fieldType == VCP_LIST_MENU_FIELD_ICON)
    {
        ContactEntry entry(getId(pos.pos, pos.group));
        image = entry.getImage().getImageSrc();
        if (image.isEmpty())
        {
            image.setResId(VAPP_PHB_IMG_DEFAULT_CONTACT);
        }

        return VFX_TRUE;
    }
    else if (fieldType == VCP_LIST_MENU_FIELD_ICON_EXTRA1) // Storage icon
    {
         image = ContactStorage::getIcon(m_list->getId(pos.pos, pos.group));

         return VFX_TRUE;
    }

    return VFX_FALSE;
}


VfxU32 VappPhbListCp::getSeekBarEntryCount()
{
    return m_list->getSeekerGroupCount();
}


VfxBool VappPhbListCp::getSeekBarEntryText(
    VfxU32 index,       // [IN] index of the seek bar entry
    VfxWString &text    // [OUT] the text of the seek bar entry
    )
{
    text = m_list->getGroupSeekerString(index);

    return VFX_TRUE;
}


VfxBool VappPhbListCp::getItemPosNeedJumpTo(
    VfxU32 touchedSeekBarEntryIndex,  // [IN] the index of the touched seek bar entry
    VcpMenuPos &posJumpTo             // [OUT] the list menu position need jump to
    )
{
    posJumpTo.pos = 0;
    posJumpTo.group = m_list->getGroupPos(touchedSeekBarEntryIndex);

    return VFX_TRUE;
}


VcpListMenuItemStateEnum VappPhbListCp::getItemState(
    VcpMenuPos pos                           // [IN] position of the item
    ) const
{
    return (m_mark->checkMark(pos.pos, pos.group)) ?
               VCP_LIST_MENU_ITEM_STATE_SELECTED :
               VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}


VcpListMenuCellClientBaseFrame *VappPhbListCp::getItemCustomContentFrame(
        VcpMenuPos pos,         // [IN] position of the item
        VfxFrame *parentFrame   // [IN] parent frame of the custom content frame
        )
{
    VappPhbListMenuItemBase *cell;
    VFX_OBJ_CREATE_EX(cell, VappPhbListMenuItemBase, parentFrame, (m_listMode));

    return cell;
}


void VappPhbListCp::configSeekBar()
{
    if (m_searchText.isEmpty())
    {
        enableSeekBar(VFX_TRUE);
    }
    else
    {
        disableSeekBar(VFX_TRUE);
    }
}


void VappPhbListCp::onTextChanged(VcpTextEditor *editor)
{
    m_searchText.loadFromMem(editor->getText());
    m_list->setQuery(m_searchText);

    // config seekbar
    configSeekBar();
}


void VappPhbListCp::onStateChanged(VcpGroupListMenu *list, VcpMenuPos pos, VcpListMenuItemStateEnum state)
{
    m_mark->changeMark(pos.pos, pos.group);
}


void VappPhbListCp::onListBoundsChanged(VfxFrame* frame, const VfxRect& rect)
{
    if (m_b2ndReady)
    {
        return;
    }

    m_activity->setPos(getSize().width/2, getSize().height/2);
}


void VappPhbListCp::onListReady()
{
    // stop acitvity
    m_activity->stop();

    //enableSearchBar(VFX_TRUE);

    resetAllItems(VFX_TRUE);

    if (m_list->getCount())
    {
        m_countText->setCount(m_list->getCount());

        if (!m_countTextExist)
        {
            addMarginAreaFrame(VCP_LIST_MENU_MARGIN_AREA_BOTTOM, VCP_LIST_MENU_MARGIN_AREA_FRAME_PLACEMENT_CENTER, m_countText);
        }

        m_countTextExist = VFX_TRUE;
    }
    else
    {
        if (m_countTextExist)
        {
            removeMarginAreaFrame(m_countText);
        }

        m_countTextExist = VFX_FALSE;
    }

    m_signalCount.postEmit(this, m_list->getCount());
}


void VappPhbListCp::onListRefresh(ContactList* list, mmi_event_struct* evt)
{
    //m_signalCount.postEmit(this, 0);

    //resetAllItems(VFX_TRUE);

    //getList();

    //m_list->getListInter();
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    // refresh list should reset storage mask in t-card support & EVT_ID_USB_ENTER/EXIT_MS_MODE
    if (evt->evt_id == EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT || evt->evt_id == EVT_ID_USB_ENTER_MS_MODE)
    {
        VfxU32 storageMask = m_list->getStorageMask();

        if (storageMask & SRV_PHB_STORAGE_MASK_TCARD)
        {
            m_tcardMask = VFX_TRUE;
            storageMask &= ~SRV_PHB_STORAGE_MASK_TCARD;

            if (0 == storageMask && m_storageType != VAPP_PHB_LIST_STORAGE_TYPE_IMPORT) // single mask
            {
                m_singleMask = VFX_TRUE;
                storageMask |= SRV_PHB_STORAGE_MASK_PHONE; // default phone mask
            }

            m_list->setStorage(storageMask);

            return ;
        }
        return ;
    }
    else if (evt->evt_id == EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN || evt->evt_id == EVT_ID_USB_EXIT_MS_MODE)
    {
        return ; // do nothing
    }
    else if (EVT_ID_PHB_TCARD_READY == evt->evt_id)
    {
        srv_phb_tcard_ready_evt_struct *tcard_evt = (srv_phb_tcard_ready_evt_struct *) evt;

        if (tcard_evt->is_ready)
        {
            if (m_tcardMask)
            {
                m_tcardMask = VFX_FALSE;
                VfxU32 storageMask = m_list->getStorageMask();

                storageMask |= SRV_PHB_STORAGE_MASK_TCARD;

                if (m_singleMask)
                {
                    m_singleMask = VFX_FALSE;
                    storageMask &= ~SRV_PHB_STORAGE_MASK_PHONE;
                }

                m_list->setStorage(storageMask);

                return ;
            }

            if (VAPP_PHB_LIST_STORAGE_TYPE_ENTRY == m_storageType)
            {
                //VfxU16 storageMask, localMask;
                VfxU16 storageMask;
                storageMask = srv_phb_get_storage_mask();
                //localMask = m_list->getStorageMask();

                m_list->setStorage(storageMask);

                return ;
            }
        }
        // refresh list
        resetAllItems(VFX_TRUE);
        m_list->getListInter();

        return ;
    }
#endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */
    if (!m_stopRefresh)
    {
        resetAllItems(VFX_TRUE);
        m_list->getListInter();
    }
}


void VappPhbListCp::onListGetting()
{
    // show activity
    if (!srv_phb_startup_is_phb_ready())
    {
        m_activity->start();
    }
    //disableSearchBar(VFX_TRUE);

    if (!m_b2ndReady && m_countTextExist)
    {
        removeMarginAreaFrame(m_countText);
        m_countTextExist = VFX_FALSE;
    }

    if (m_countTextExist)
    {
        removeMarginAreaFrame(m_countText);
        m_countTextExist = VFX_FALSE;
    }
    //resetAllItems(VFX_TRUE);

    m_signalCount.postEmit(this, 0);
}


void VappPhbListCp::onContactUpdated(ContactTask* task, mmi_event_struct* evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_PHB_UPD_CONTACT:
        {
            srv_phb_op_evt_struct *op = (srv_phb_op_evt_struct*) evt;
            if (m_mark)
            {
                if (m_mark->getCount() > 0)
                {
                    MarkKey markKey;

                    for (VfxS32 index = 0; index < (VfxS32) m_mark->getCount(); index++)
                    {
                        markKey = m_mark->getMarkKey(index);
                        if (markKey.m_id == op->id)
                        {
                            switch (markKey.m_type)
                            {
                                case MMI_PHB_CONTACT_FIELD_ID_NUMBER:
                                {
                                    VappContactNumber number = ContactEntry(markKey.m_id).getNumberById(markKey.m_subId);
                                    
                                    if (number.isEmpty())
                                    {
                                        if (m_mark->clearIndexMarkKey(markKey))
                                        {
                                            index--;
                                        }
                                    }
                                    break;
                                }
                                case MMI_PHB_CONTACT_FIELD_ID_EMAIL:
                                {
                                    VappContactEmail email = ContactEntry(markKey.m_id).getEmailById(markKey.m_subId);
                                    
                                    if (email.isEmpty())
                                    {
                                        if (m_mark->clearIndexMarkKey(markKey))
                                        {
                                            index--;
                                        }
                                    }
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            break;
        }
        case EVT_ID_PHB_DEL_CONTACT:
        {
            srv_phb_op_evt_struct *op = (srv_phb_op_evt_struct*) evt;
            if (m_mark)
            {
                if (m_mark->getCount() > 0)
                {
                    MarkKey markKey;

                    for (VfxS32 index = 0; index < (VfxS32) m_mark->getCount(); index++)
                    {
                        markKey = m_mark->getMarkKey(index);
                        if (markKey.m_id == op->id)
                        {
                            if (m_mark->clearIndexMarkKey(markKey))
                            {
                                index--;
                            }
                        }
                    }
                }
            }
            break;
        }
        case EVT_ID_PHB_READY:
        {
            srv_phb_startup_evt_struct *ready = (srv_phb_startup_evt_struct*) evt;

            if (ready->phb_ready && !m_b2ndReady)
            {
                setSearchString(m_searchText);
            }
            else
            {
                //disableSearchBar(VFX_TRUE);
            #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__  // later check myler
                if(m_mark)
                {
                    m_mark->unMarkAll();
                }
            #endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */
            }
            break;
        }
    #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        case EVT_ID_USB_ENTER_MS_MODE:
        {
            if (m_mark)
            {
                MarkKey markKey;
                phb_storage_enum storage;
                for (VfxS32 index = 0; index < (VfxS32) m_mark->getCount(); index++)
                {
                    markKey = m_mark->getMarkKey(index);
                    storage = ContactStorage::getStorage(markKey.m_id);
                    if (storage == PHB_STORAGE_TCARD && m_mark->clearIndexMarkKey(markKey)) // myler: (plug out)clean tcard mark, (plug in)but can't recovery
                    {
                        index--;
                    }
                }
            }
            break;
        }
    #endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */
    }
}


/***************************************************************************** 
 * Class VappPhbListCountFrame
 *****************************************************************************/
void VappPhbListCountFrame::onInit()
{
    VfxFrame::onInit();

    setSize(300, LIST_COUNT_FRM_SIZE_H);

    VFX_OBJ_CREATE(m_text, VfxTextFrame, this);

    m_text->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_EMPTY));
    m_text->setFont(VFX_FONT_RES(FNT_COSMOS_TEXT_EMPTY));
    m_text->setAnchor(0.5f, 0.5f);
    m_text->setPos(getSize().width/2, getSize().height/2);
    m_text->setSize(150, LIST_COUNT_FONT_SIZE);

    removeFromParentFrame();
}


void VappPhbListCountFrame::setCount(VfxU32 count)
{
    VfxWString text = VfxWString().format("%d", count);

    if (count == 1)
    {
        text += VFX_WSTR_RES(VAPP_PHB_STR_CONTACT_APPEND);
    }
    else
    {
        text += VFX_WSTR_RES(VAPP_PHB_STR_CONTACTS_APPEND);
    }
    m_text->setString(text);
}


/* List menu cell - used in VcpListMenu/VcpGroupListMenu */
#ifdef __SOCIAL_NETWORK_SUPPORT__
VFX_IMPLEMENT_CLASS("VappPhbPhotoBorderFrame", VappPhbPhotoBorderFrame, VcpPhotoBorderFrame);
#endif

// VappPhbListMenuItemBase Implementation
VFX_IMPLEMENT_CLASS("VappPhbListMenuItemBase", VappPhbListMenuItemBase, VcpListMenuCellClientBaseFrame);

VappPhbListMenuItemBase::VappPhbListMenuItemBase(ListModeEnum listMode):
    m_listMode(listMode),
    m_imageFrame(NULL),
#ifdef __SOCIAL_NETWORK_SUPPORT__
    m_asyncFrame(NULL),
    m_asyncImgPath(VFX_WSTR_NULL),
#endif /*__SOCIAL_NETWORK_SUPPORT__*/
    m_textFrame(NULL),
    m_subText(NULL),
    m_iconFrame(NULL)
{
    if (m_listMode == VCP_LIST_MENU_CELL_STYLE_SNS)
    {
        m_style = VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT;
    }
    else if (m_listMode == VCP_LIST_MENU_CELL_STYLE_MSG)
    {
        m_style = VCP_LIST_MENU_CELL_STYLE_ICON_MULTI_TEXT;
    }
}


void VappPhbListMenuItemBase::setListMode(ListModeEnum listMode)
{
    m_listMode = listMode;
}


void VappPhbListMenuItemBase::onCreateElements()
{
    if (!m_imageFrame)
    {
    #ifdef __SOCIAL_NETWORK_SUPPORT__
        VFX_OBJ_CREATE(m_imageFrame, VappPhbPhotoBorderFrame, this);
    #else
        VFX_OBJ_CREATE(m_imageFrame, VcpPhotoBorderFrame, this);
    #endif /*__SOCIAL_NETWORK_SUPPORT__*/
    }

    if (!m_textFrame)
    {
        VFX_OBJ_CREATE(m_textFrame, VfxFrame, this);
    }

    if (m_listMode == VCP_LIST_MENU_CELL_STYLE_MSG)
    {
        if (!m_subText)
        {
            VFX_OBJ_CREATE(m_subText, VfxFrame, this);
        }
    }

    if (!m_iconFrame)
    {
        VFX_OBJ_CREATE(m_iconFrame, VfxImageFrame, this);
    }
}


void VappPhbListMenuItemBase::onCloseElements()
{
    if (m_imageFrame)
    {
        if (getContentProvider())
        {
            VfxImageSrc img = m_imageFrame->getImgContent();
            getContentProvider()->closeItemImage(getCell()->m_pos, VCP_LIST_MENU_FIELD_ICON, img);
        }

        VFX_OBJ_CLOSE(m_imageFrame);
    }

    if (m_textFrame)
    {
        VFX_OBJ_CLOSE(m_textFrame);
    }

    if (m_subText)
    {
        VFX_OBJ_CLOSE(m_subText);
    }

    if (m_iconFrame)
    {
        if (getContentProvider())
        {
            VfxImageSrc img = m_iconFrame->getImgContent();
            getContentProvider()->closeItemImage(getCell()->m_pos, VCP_LIST_MENU_FIELD_ICON_EXTRA1, img);
        }

        VFX_OBJ_CLOSE(m_iconFrame);
    }
}


void VappPhbListMenuItemBase::onLayoutElements()
{
    if (m_imageFrame)
    {
        m_imageFrame->setAnchor(0.0f, 0.5f);
        m_imageFrame->setPos(IMG_LEFT_GAPS, getSize().height / 2);
        m_imageFrame->setSize(IMG_WIDTH, IMG_HEIGHT);
        m_imageFrame->setMaxSize(VfxSize(IMG_WIDTH, IMG_HEIGHT));
        m_imageFrame->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE);
    }

    if (m_textFrame)
    {
        m_textFrame->setRect(VfxRect(TEXT_LEFT_GAPS + IMG_LEFT_GAPS + IMG_RIGHT_GAPS + IMG_MAX_WIDTH, 
                                 (getBounds().getHeight() - m_textFrame->getBounds().getHeight()) / 2,
                                 getRect().getWidth() - TEXT_LEFT_GAPS - TEXT_RIGHT_GAPS - (IMG_LEFT_GAPS + IMG_RIGHT_GAPS + IMG_MAX_WIDTH) - (ICON_WIDTH + ICON_LEFT_GAPS + ICON_RIGHT_GAPS),
                                 m_textFrame->getRect().getHeight()));
        m_textFrame->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                    VFX_FRAME_ALIGNER_MODE_SIDE,
                                    VFX_FRAME_ALIGNER_MODE_SIDE,
                                    VFX_FRAME_ALIGNER_MODE_SIDE);
    }

    if (m_subText)
    {
        if (!m_textFrame)
        {
            VFX_ASSERT(0);
        }

        m_textFrame->setRect(VfxRect(TEXT1_LEFT_GAPS + IMG_LEFT_GAPS + IMG_RIGHT_GAPS + IMG_MAX_WIDTH, 
                                      TEXT1_TOP_GAPS,
                                      getRect().getWidth() - TEXT1_LEFT_GAPS - TEXT1_RIGHT_GAPS - (IMG_LEFT_GAPS + IMG_RIGHT_GAPS + IMG_MAX_WIDTH) - (ICON_WIDTH + ICON_LEFT_GAPS + ICON_RIGHT_GAPS),
                                      m_textFrame->getRect().getHeight()));
        m_textFrame->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                    VFX_FRAME_ALIGNER_MODE_SIDE,
                                    VFX_FRAME_ALIGNER_MODE_SIDE,
                                    VFX_FRAME_ALIGNER_MODE_SIDE);

        m_subText->setRect(VfxRect(TEXT2_LEFT_GAPS + IMG_LEFT_GAPS + IMG_RIGHT_GAPS + IMG_MAX_WIDTH, 
                                      getRect().getHeight() - 1 - TEXT2_BOTTOM_GAPS - m_subText->getRect().getHeight(),
                                      getRect().getWidth() - TEXT2_LEFT_GAPS - TEXT2_RIGHT_GAPS - (IMG_LEFT_GAPS + IMG_RIGHT_GAPS + IMG_MAX_WIDTH) - (ICON_WIDTH + ICON_LEFT_GAPS + ICON_RIGHT_GAPS),
                                      m_subText->getRect().getHeight()));
        m_subText->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                   VFX_FRAME_ALIGNER_MODE_SIDE,
                                   VFX_FRAME_ALIGNER_MODE_SIDE,
                                   VFX_FRAME_ALIGNER_MODE_SIDE);
    }
    else
    {
        /* vertical center alignment text 1 if no text 2 */
        m_textFrame->setPos(m_textFrame->getPos().x, (getRect().getHeight() - m_textFrame->getRect().getHeight()) / 2);
    }

    VfxU32 iconPosX, iconPosY;

    if (m_iconFrame)
    {
        iconPosX = getSize().width - ICON_RIGHT_GAPS;
        iconPosY = ICON_TOP_GAPS;
        m_iconFrame->setAnchor(1.0f, 0.0f);
        m_iconFrame->setPos(iconPosX, iconPosY);
        m_iconFrame->setSize(ICON_WIDTH, ICON_HEIGHT);
    }
}


void VappPhbListMenuItemBase::onUpdateElements()
{
    IVcpListMenuContentProviderInt *contentProvider = getContentProvider();
    VfxImageSrc image;
#ifdef __SOCIAL_NETWORK_SUPPORT__
    VfxWString imagePath = VFX_WSTR_NULL;
    VcpListMenuTextColorEnum color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
#endif /*__SOCIAL_NETWORK_SUPPORT__*/

    if (contentProvider)
    {
        if (m_imageFrame)
        {
            image.setNull();
        #ifdef __SOCIAL_NETWORK_SUPPORT__
            if (contentProvider->getItemText(getCell()->m_pos, VCP_LIST_MENU_FIELD_ICON, imagePath, color) && imagePath != VFX_WSTR_NULL)
            {
                setAsyncImgContent(imagePath);
            }
            else if (contentProvider->getItemImage(getCell()->m_pos, VCP_LIST_MENU_FIELD_ICON, image))
            {
                m_imageFrame->setAutoAnimate(VFX_FALSE);
                m_imageFrame->setImgContent(image);
                m_imageFrame->setPlacement(VCP_PHOTO_BORDER_FRAME_PLACEMENT_FIT_EXACT_SIZE);
                m_imageFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
                m_imageFrame->setIsUnhittable(VFX_TRUE);
            }
        #else /*__SOCIAL_NETWORK_SUPPORT__*/
            if (contentProvider->getItemImage(getCell()->m_pos, VCP_LIST_MENU_FIELD_ICON, image))
            {
                m_imageFrame->setAutoAnimate(VFX_FALSE);
                m_imageFrame->setImgContent(image);
                m_imageFrame->setPlacement(VCP_PHOTO_BORDER_FRAME_PLACEMENT_FIT_EXACT_SIZE);
                m_imageFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
                m_imageFrame->setIsUnhittable(VFX_TRUE);
            }
        #endif /*__SOCIAL_NETWORK_SUPPORT__*/
        }

        if (m_textFrame)
        {
            VfxFrame *frame = NULL;
            VFX_OBJ_CLOSE(m_textFrame); // Must close previous text object

            frame = createItemTextFrameInt(VCP_LIST_MENU_FIELD_TEXT);
            if (frame)
            {
                m_textFrame = frame;
            }
        }

        if (m_subText)
        {
            VfxFrame *frame = NULL;
            VFX_OBJ_CLOSE(m_subText); // Must close previous text object

            frame = createItemTextFrameInt(VCP_LIST_MENU_FIELD_SUB_TEXT1);
            if (frame)
            {
                m_subText = frame;
            }
        }

        if (m_iconFrame)
        {
            image.setNull();
            if (contentProvider->getItemImage(getCell()->m_pos, VCP_LIST_MENU_FIELD_ICON_EXTRA1, image))
            {
                m_iconFrame->setImgContent(image);
                m_iconFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
            }
        }
    }
}


void VappPhbListMenuItemBase::onUpdateTextFrameStyle(VcpListMenuFieldEnum fieldType, VfxTextFrame *frame)
{
    VcpListMenuCellClientBaseFrame::onUpdateTextFrameStyle(fieldType, frame);

    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        frame->setFont(VfxFontDesc(VCP_LIST_MENU_FONT_SIZE_MEDIUM));
        frame->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
        frame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    }
    else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
        frame->setFont(VfxFontDesc(VCP_LIST_MENU_FONT_SIZE_SMALL));
        frame->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
        frame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    }
}


void VappPhbListMenuItemBase::onUpdateTextViewStyle(VcpListMenuFieldEnum fieldType, VcpTextView *frame)
{
    VcpListMenuCellClientBaseFrame::onUpdateTextViewStyle(fieldType, frame);

    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        frame->setFont(VfxFontDesc(VCP_LIST_MENU_FONT_SIZE_MEDIUM));
        frame->setAlignMode(VCP_TEXT_ALIGN_MODE_LEFT);
        frame->setTruncateMode(VCP_TEXT_TRUNCATE_MODE_END);
    }
    else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
        frame->setFont(VfxFontDesc(VCP_LIST_MENU_FONT_SIZE_SMALL));
        frame->setAlignMode(VCP_TEXT_ALIGN_MODE_LEFT);
        frame->setTruncateMode(VCP_TEXT_TRUNCATE_MODE_END);
    }
}


#ifdef __SOCIAL_NETWORK_SUPPORT__
void VappPhbListMenuItemBase::setAsyncImgContent(const VfxWString &imagePath)
{
    if (imagePath && (m_asyncImgPath == VFX_WSTR_NULL || m_asyncImgPath != imagePath))
    {
        if (m_asyncFrame)
        {
            VFX_OBJ_CLOSE(m_asyncFrame);
            m_asyncImgPath = VFX_WSTR_NULL;
        }

        m_asyncImgPath = imagePath;

        VFX_OBJ_CREATE_EX(m_asyncFrame, VcpAsyncImageFrame, this,
            (imagePath,
            0,
            VfxSize((IMG_WIDTH - 4 * 2), (IMG_HEIGHT - 4 * 2)),
            4,
            &VappPhbListMenuItemBase::memAllocator, &VappPhbListMenuItemBase::memDeallocator,
            getObjHandle(),
            GDI_UTIL_MODE_SHORT_SIDE_FIT));

        VfxFrame *contentFrame = m_imageFrame->getContentFrame();
        m_imageFrame->setIsUnhittable(VFX_TRUE);

        if (contentFrame)
        {
            contentFrame->addChildFrame(m_asyncFrame);
        }
    }
}


void *VappPhbListMenuItemBase::memAllocator(VfxU32 size, void *userData)
{
    VappPhbListMenuItemBase *self = (VappPhbListMenuItemBase *)VfxObject::handleToObject((VfxObjHandle)userData);

    if (self)
    {
        if (VfxMainScr::findMainScr(self) && size > 0)
        {
            VfxU8 *memPtr = (U8 *)mmi_frm_asm_alloc_nc_r(
                VfxMainScr::findMainScr(self)->getGroupId(), 
                size);

            return memPtr;
        }
    }

    return NULL;
}


void VappPhbListMenuItemBase::memDeallocator(void *mem, void *userData)
{
    VappPhbListMenuItemBase *self = (VappPhbListMenuItemBase *)VfxObject::handleToObject((VfxObjHandle)userData);

    if (self)
    {
        if (VfxMainScr::findMainScr(self) && mem)
        {
            mmi_frm_asm_free_r(VfxMainScr::findMainScr(self)->getGroupId(), mem);
        }
    }
}
#endif /*__SOCIAL_NETWORK_SUPPORT__*/

