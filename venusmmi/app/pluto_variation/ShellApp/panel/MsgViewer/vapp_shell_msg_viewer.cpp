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
 * Vapp_shell_msg_viewer.cpp
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_SHELL_MSG_VIEWER__

/*****************************************************************************
 * Include
 *****************************************************************************/
/**********  KAL Layer Header **************/
/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "string.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "app_datetime.h"

#ifdef __cplusplus
}
#endif

/**********  MMI Layer Header **************/
#include "MMI_features.h"

#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_date_time.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_control.h"
#include "vfx_frame.h"
#include "vfx_basic_type.h"
#include "vfx_signal.h"
#include "vfx_system.h"
#include "vfx_image_src.h"
#include "vfx_text_frame.h"
#include "vfx_font_desc.h"
#include "vfx_primitive_frame.h"
#include "vfx_auto_animate.h"
#include "vfx_animation.h"
#include "vfx_screen.h"
#include "vfx_base_popup.h"

#include "vrt_datatype.h"
#include "vrt_system.h"

#include "vcp_command_title.h"
#include "vcp_state_image.h"
#include "vcp_list_menu.h"
#include "vcp_waiting_icon.h"
#include "vcp_segment_button.h"
#include "vcp_frame_effect_type.h"
#include "vcp_popup.h"
#include "vcp_page_panel.h"

#include "vadp_app_trc.h"

#include "mmi_rp_app_shellapp_base_def.h"
#include "mmi_rp_app_venus_shell_msg_viewer_def.h"
#include "Vapp_shell_msg_viewer.h"
#include "vapp_msg_data_provider.h"
#include "vapp_shell_msg_viewer_cfg.h"
#include "vapp_shell_panel.h"
#include "vapp_notepaper.h"

#include "vdat_systime.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
    #include "MMIDataType.h"

    #include "GlobalResDef.h"
    #include "customer_email_num.h"
    #include "mmi_frm_scenario_gprot.h"
    #include "mmi_cb_mgr_gprot.h"

    #include "MsgViewerCuiGProt.h"
    #include "SmsAppGprot.h"
    #include "SmsSrvGprot.h"
    #include "PhbSrvGprot.h" /* srv_phb_get_name_by_number */
    #include "UMGProt.h"
    #include "UmSrvGprot.h"


    #ifdef __MMI_SIMAP_SUPPORT__
    #include "SimCtrlSrvGprot.h" /* srv_sim_ctrl_get_unavailable_cause & SRV_SIM_CTRL_UA_CAUSE_BT_ACCESS_PROFILE */
    #endif

    #ifdef __MMI_WLAN_FEATURES__
    #include "NetSetSrvGprot.h"
    #endif /* __MMI_WLAN_FEATURES__ */

    #include "ModeSwitchSrvGprot.h"

#ifdef __cplusplus
}
#endif


/*****************************************************************************
 * Static Declaration
 *****************************************************************************/

/*****************************************************************************
 * Global Variable
 *****************************************************************************/

/*****************************************************************************
 * Local Function
 *****************************************************************************/

/*****************************************************************************
 * Global Function
 *****************************************************************************/
#define MAX_LEN_TIME_STR  (15 + 1 + 10 + 1) /* Date string + 1 space + Time string + NULL terminator*/

static void timestamp2String(VfxWString &msg_time, VfxU32 timestamp, VfxU32 flags)
{
    VfxDateTime tempTime;
    VfxU32 local_sec = 0;
    applib_time_struct time;

    local_sec = applib_dt_sec_utc_to_local(timestamp);
    applib_dt_utc_sec_2_mytime(local_sec, &time, MMI_FALSE);
    tempTime.setDateTime(&time);
    msg_time = VFX_WSTR_EMPTY;

    if ((flags & VFX_DATE_TIME_DATE_YEAR) &&
        (flags & VFX_DATE_TIME_DATE_MONTH) &&
        (flags & VFX_DATE_TIME_DATE_DAY))
    {
        applib_time_struct current_time;

        applib_dt_get_date_time(&current_time);

        //the timestamp is in today
        if (current_time.nYear == time.nYear &&
            current_time.nMonth == time.nMonth &&
            current_time.nDay == time.nDay)
        {
            msg_time += VFX_WSTR_RES(STR_ID_SHELL_MSG_VIEWER_TODAY);
            flags = flags & ~(VFX_DATE_TIME_DATE_YEAR | VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY);
        }
    }

    if (flags)
    {
        VfxWChar str[MAX_LEN_TIME_STR];
        tempTime.getDateTimeString(flags, str, MAX_LEN_TIME_STR);

        if (msg_time != VFX_WSTR_EMPTY)
        {
            msg_time += VFX_WSTR(" ");
        }

        msg_time += VFX_WSTR_MEM(str);
    }
}


/*****************************************************************************
 * Class VappShellMsgListScreen
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappShellMsgListScreen", VappShellMsgListScreen, VfxControl);

VappShellMsgListScreen::VappShellMsgListScreen():
    m_listMenu(NULL),
    m_commandTitle(NULL),
    m_msgList(NULL),
    m_dataProvider(NULL),
    m_msgInfo(NULL),
    m_isFreeze(VFX_FALSE),
    m_isDirty(VFX_TRUE)
{

}

void VappShellMsgListScreen::onInit(void)
{
    Super::onInit();

    vrt_size_struct main_screen_size;
    vrt_color_type_enum main_screen_color_format;
    vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

    VFX_OBJ_CREATE(m_dataProvider, VappMsgDataProvider, this);

    // In order to increase performance, we set listscreen as Opaque
    // but there is nothing in top region, we need to a block frame here
    VfxFrame *bg;
    VFX_OBJ_CREATE(bg, VfxFrame, this);
    bg->setPos(0,0);
    bg->setSize(main_screen_size.width, 20 + 46);
    bg->setBgColor(VFX_COLOR_BLACK);
    bg->setIsOpaque(VFX_TRUE);

    VFX_OBJ_CREATE(m_commandTitle, VcpCommandTitle, this);
    m_commandTitle->setPos(0, 20);
    m_commandTitle->setSize(main_screen_size.width, 46);
    m_commandTitle->setText(VFX_WSTR_RES(STR_ID_SHELL_MSG_VIEWER_TITLE));
    m_commandTitle->setAddOnImageButton(
        1,
        VcpStateImage(
            VAPP_SHELL_IMG_BK_NORMAL,
            VAPP_SHELL_IMG_BK_PRESS,
            VAPP_SHELL_IMG_BK_DISABLE,
            0),
        0,
        VcpCommandTitleButtonCB(this, &Self::onBackButtonClick));


    VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);

    m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_QUADRUPLE_TEXT);
    m_listMenu->setContentProvider(this);
    m_listMenu->m_signalItemTapped.connect(this, &Self::onListMenuTap);

    m_listMenu->setPos(VfxPoint(0, 46 + 20));
    m_listMenu->setSize(main_screen_size.width, main_screen_size.height - 46 - 20);
}

void VappShellMsgListScreen::onDeinit(void)
{
    if (m_msgList)
    {
        m_msgList->m_signalListUpdated.disconnect(this, &Self::onMsgListUpdated);
        m_msgList->m_signalListReleased.disconnect(this, &Self::onMsgListReleased);
    }

    m_dataProvider->m_signalGetMsgInfoFinished.disconnect(this, &Self::onGetMsgInfoFinished);

    VFX_OBJ_CLOSE(m_dataProvider);
    VFX_OBJ_CLOSE(m_commandTitle);
    VFX_OBJ_CLOSE(m_listMenu);
    Super::onDeinit();
}


// -------------------------------------------------------------
// Property set/get
// -------------------------------------------------------------

void VappShellMsgListScreen::setMsgList(VappMsgList * msgList)
{
    m_msgList = msgList;
    m_msgList->m_signalListUpdated.connect(this, &Self::onMsgListUpdated);
    m_msgList->m_signalListReleased.connect(this, &Self::onMsgListReleased);
}

void VappShellMsgListScreen::setIsFreeze(VfxBool isFreeze)
{
    m_isFreeze = isFreeze;
    if (m_listMenu)
    {
        m_listMenu->setIsDisabled(isFreeze);
    }
}

VfxBool VappShellMsgListScreen::getIsFreeze() const
{
    return m_isFreeze;
}

void VappShellMsgListScreen::setIsDirty(VfxBool isDirty)
{
    m_isDirty = isDirty;
}

VfxBool VappShellMsgListScreen::getIsDirty() const
{
    return m_isDirty;
}

// -------------------------------------------------------------
// Method
// -------------------------------------------------------------

// -------------------------------------------------------------
// Event Handler
// -------------------------------------------------------------

void VappShellMsgListScreen::onUpdate()
{
    if (getIsFreeze())
    {
        return;
    }

    m_commandTitle->setText(VFX_WSTR_RES(STR_ID_SHELL_MSG_VIEWER_TITLE));

    if (getIsDirty())
    {
        m_listMenu->resetAllItems();
    }
    else
    {
        m_listMenu->updateAllItems();
    }

    setIsDirty(VFX_FALSE);
}

void VappShellMsgListScreen::onListMenuTap(VcpListMenu *menu, VfxU32 index)
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_LISTSCREEN_ONLISTMENUTAP, index);

    m_signalItemSelected.emit(index + 1);
}

void VappShellMsgListScreen::onBackButtonClick(VfxObject* sender, VfxId id)
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_LISTSCREEN_ONBACKBUTTONCLICK);

    m_signalBackButtonClicked.emit();
}

void VappShellMsgListScreen::onMsgListUpdated()
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_LISTSCREEN_ONMSGLISTUPDATED);

    VFX_ASSERT(m_msgList);

    // The process may be cancelled, so the message list is still out of date
    // In this case, we just need to show empty screen
    // VFX_ASSERT(!m_msgList->isOutOfDate());

    VFX_ASSERT(!m_msgList->isUpdating());
    setIsDirty(VFX_TRUE);
    checkUpdate();
}

void VappShellMsgListScreen::onMsgListReleased()
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_LISTSCREEN_ONMSGLISTRELEASED);
    // In original, we can only disable all component and not process
    // any key event or pen event and not update screen
    // however, even we disable list menu, he would try to get data at this time
    // just only disable key and pen event
    setIsDirty(VFX_TRUE);
    checkUpdate();
}

void VappShellMsgListScreen::onGetMsgInfoFinished(srv_um_get_msg_info_result result)
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_LISTSCREEN_ONGETMSGINFOFINISHED);

    if (result.error == SRV_UM_RESULT_OK)
    {
        checkUpdate();
    }
}

// -------------------------------------------------------------
// IVcpListMenuContentProvider
// -------------------------------------------------------------

// Set the list menu pointer to content provider
void VappShellMsgListScreen::setMenu(VcpListMenu *)
{

}

VfxBool VappShellMsgListScreen::getItemText(
    VfxU32 index,                    // [IN] the index of item
    VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
    VfxWString &text,                // [OUT] the text resource
    VcpListMenuTextColorEnum &color  // [OUT] the text color
    )
{
    VFX_ASSERT(m_msgList);
    VFX_ASSERT(!m_msgList->isUpdating());
    if (0 == getCount())
    {
         return VFX_FALSE;
    }
    m_dataProvider->m_signalGetMsgInfoFinished.connect(this, &Self::onGetMsgInfoFinished);

    // not exist in cache
    if (m_dataProvider->getMsgInfo(m_msgList->getMsgList(), m_msgList->getListSize(), index, 1, &m_msgInfo) != SRV_UM_RESULT_OK)
    {
        return VFX_FALSE;
    }

    switch(fieldType)
    {
    case VCP_LIST_MENU_FIELD_TEXT:
        {
            if (vfx_sys_wcslen(m_msgInfo->address) == 0)
            {
                text.loadFromRes(STR_GLOBAL_NO_NUMBER);
            }
            else
            {
                VfxWChar *phb_name;

                VFX_ALLOC_MEM(phb_name, (SRV_UM_MAX_ADDR_LEN + 1) * 2, this);

                srv_phb_get_name_by_number((U16*)m_msgInfo->address, (U16*)phb_name, SRV_UM_MAX_ADDR_LEN);

                if (vfx_sys_wcslen(phb_name) != 0)
                {
                    text.loadFromMem(phb_name);
                }
                else
                {
                    text.loadFromMem(m_msgInfo->address);
                }
                color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;

                VFX_FREE_MEM(phb_name);
            }
        }

        break;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    case VCP_LIST_MENU_FIELD_SUB_TEXT1:
        text.loadFromMem(m_msgInfo->subject);
        color = VCP_LIST_MENU_TEXT_COLOR_HIGHLIGHT;
        break;

    case VCP_LIST_MENU_FIELD_SUB_TEXT2:
        timestamp2String(text, m_msgInfo->timestamp, VFX_DATE_TIME_DATE_YEAR | VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY);
        color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
        break;

    case VCP_LIST_MENU_FIELD_SUB_TEXT3:
        timestamp2String(text, m_msgInfo->timestamp, VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE);
        color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
        break;
    default:
        return VFX_FALSE;

    }

    return VFX_TRUE;
}

// Get the image resource for the image fields of list cell
VfxBool VappShellMsgListScreen::getItemImage(
     VfxU32 index,                    // [IN] the index of item
     VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
     VfxImageSrc &image              // [OUT] the image resource
     )
{
    VFX_ASSERT(m_msgList);
    VFX_ASSERT(!m_msgList->isUpdating());
    if (0 == getCount())
    {
         return VFX_FALSE;
    }
    if (m_msgList->getListSize() > index)
    {
        if (srv_sms_get_msg_status((U16)(m_msgList->getMsgList()[index].msg_id)) & SRV_SMS_STATUS_UNREAD)
        {
            image.setResId(IMG_ID_SHELL_MSG_VIEWER_UNREAD);
        }
        else
        {
            image.setResId(IMG_ID_SHELL_MSG_VIEWER_READ);
        }
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

void VappShellMsgListScreen::closeItemImage(
    VfxU32 index,                    // [IN] the index of item
    VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
    VfxImageSrc Image               // [IN] the image resource
    )
{

}

// Get the item count of the lis menu
VfxU32 VappShellMsgListScreen::getCount() const
{
    if (m_msgList)
    {
        return m_msgList->getListSize();
    }
    return 0;
}

// Get the state of a list item
VcpListMenuItemStateEnum VappShellMsgListScreen::getItemState(
    VfxU32 index   // [IN] index of the item
    ) const
{
    return VCP_LIST_MENU_ITEM_STATE_NONE;
}

// Swap two items, user should update its internal data of the two items
VfxBool VappShellMsgListScreen::swapItem(
    VfxU32 index1, // [IN] index of the first item
    VfxU32 index2  // [IN] index of the second item
    )
{
    return VFX_TRUE;
}

/*****************************************************************************
 * Class VappShellMsgNotePaperFrame
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappShellMsgNotePaperFrame", VappShellMsgNotePaperFrame, VfxFrame);

VappShellMsgNotePaperFrame::VappShellMsgNotePaperFrame(void):
    m_nameFrame(NULL),
    m_dateFrame(NULL),
    m_contentFrame(NULL),
    m_currentPageFrame(NULL),
    m_totalPageFrame(NULL),
    m_waitingIcon(NULL),
    m_newMsgIcon(NULL),
    m_dataProvider(NULL),
    m_msgInfo(NULL),
    m_loading(VFX_FALSE),
    m_pageIndex(0),
    m_totalPage(0),
    m_IsRead(VFX_FALSE)
{
    memset(&m_msgNode, 0, sizeof(m_msgNode));
    memset(&m_smsData, 0, sizeof(m_smsData));
}

void VappShellMsgNotePaperFrame::onInit(void)
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_NPFRAME_ONINIT, (VfxS32)this);

    Super::onInit();

    VFX_OBJ_CREATE(m_nameFrame, VfxTextFrame, this);
    m_nameFrame->setFont(VfxFontDesc(VAPP_SHELL_MV_FRAME_NAME_FONT_SIZE));
    m_nameFrame->setColor(VFX_COLOR_BLACK);
    m_nameFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_nameFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_nameFrame->setBorderColor(VFX_COLOR_BLACK);

    VFX_OBJ_CREATE(m_dateFrame, VfxTextFrame, this);
    m_dateFrame->setFont(VfxFontDesc(VAPP_SHELL_MV_FRAME_DATE_FONT_SIZE));
    m_dateFrame->setColor(VFX_COLOR_BLACK);
    m_dateFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_dateFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_dateFrame->setBorderColor(VFX_COLOR_BLACK);

    VFX_OBJ_CREATE(m_contentFrame, VfxTextFrame, this);
    m_contentFrame->setFont(VfxFontDesc(VAPP_SHELL_MV_FRAME_CONTENT_FONT_SIZE));
    m_contentFrame->setColor(VFX_COLOR_BLACK);
    m_contentFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_contentFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_contentFrame->setBorderColor(VFX_COLOR_BLACK);

    VFX_OBJ_CREATE(m_currentPageFrame, VfxTextFrame, this);
    m_currentPageFrame->setFont(VfxFontDesc(VAPP_SHELL_MV_FRAME_PAGE_FONT_SIZE));
    m_currentPageFrame->setColor(VRT_COLOR_MAKE(255,182,86,0));
    m_currentPageFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_RIGHT);

    VFX_OBJ_CREATE(m_totalPageFrame, VfxTextFrame, this);
    m_totalPageFrame->setFont(VfxFontDesc(VAPP_SHELL_MV_FRAME_PAGE_FONT_SIZE));
    m_totalPageFrame->setColor(VFX_COLOR_BLACK);
    m_totalPageFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);

    VFX_OBJ_CREATE(m_waitingIcon, VcpWaitingIcon, this);

    VFX_OBJ_CREATE(m_dataProvider, VappMsgDataProvider, this);

    VFX_OBJ_CREATE(m_newMsgIcon, VfxImageFrame, this);
    m_newMsgIcon->setResId(IMG_ID_SHELL_MSG_VIEWER_NEW_MESSAGE);
    m_newMsgIcon->setHidden(VFX_TRUE);

    m_dataProvider->m_signalGetMsgInfoFinished.connect(this, &Self::onGetMsgInfoFinished);

}

void VappShellMsgNotePaperFrame::onDeinit(void)
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_NPFRAME_ONDEINIT, (VfxS32)this);

    m_dataProvider->m_signalGetMsgInfoFinished.disconnect(this, &Self::onGetMsgInfoFinished);

    Super::onDeinit();
}

// -------------------------------------------------------------
// Property set/get
// -------------------------------------------------------------
void VappShellMsgNotePaperFrame::setPageData(const srv_um_msg_node_struct &msgNode, const VfxS32 pageIndex, const VfxS32 totalPage)
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_NPFRAME_SETPAGEDATA, (VfxS32) this, msgNode.msg_id, pageIndex);

    m_IsRead = VFX_FALSE;

    if (m_msgNode.msg_id != msgNode.msg_id ||
        m_msgNode.msg_type != msgNode.msg_type)
    {
        m_newMsgIcon->setHidden(VFX_TRUE);
    }

    // the content may be "Not supported" which is controlled by different languague
    // therefore, we do not check the id and type and always update it
    // if the content is the same, text frame would not flush it

//    if (m_msgNode.msg_id != msgNode.msg_id ||
//        m_msgNode.msg_type != msgNode.msg_type)
    {
        m_msgNode = msgNode;
        updateMsgInfo();
    }

    // can be handled by text frame, no need to check here

    if (m_pageIndex != pageIndex ||
        m_totalPage != totalPage)
    {
        m_pageIndex = pageIndex;
        m_totalPage = totalPage;

        setCurrentPage(VfxWString().format("%d", m_pageIndex));
        setTotalPage(VfxWString().format("/%d", m_totalPage));
    }
}

void VappShellMsgNotePaperFrame::setSize(const VfxSize &value)
{
    m_nameFrame->setAnchor(VfxFPoint(0.5f, 0.0f));
    m_nameFrame->setPos(value.width / 2, VAPP_SHELL_MV_FRAME_NAME_Y_POSITION + VAPP_SHELL_MV_FRAME_BORDER_HEIGTH);
    m_nameFrame->setSize(value.width - VAPP_SHELL_MV_FRAME_BORDER_WIDTH * 2, VAPP_SHELL_MV_FRAME_NAME_HEIGTH);
    m_nameFrame->setMargins(VAPP_SHELL_MV_FRAME_MARGIN, 0, VAPP_SHELL_MV_FRAME_MARGIN, 0);

    m_dateFrame->setAnchor(VfxFPoint(0.5f, 0.0f));
    m_dateFrame->setPos(value.width / 2, VAPP_SHELL_MV_FRAME_DATE_Y_POSITION + VAPP_SHELL_MV_FRAME_BORDER_HEIGTH);
    m_dateFrame->setSize(value.width - VAPP_SHELL_MV_FRAME_BORDER_WIDTH * 2, VAPP_SHELL_MV_FRAME_DATE_HEIGTH);
    m_dateFrame->setMargins(VAPP_SHELL_MV_FRAME_MARGIN, 0, VAPP_SHELL_MV_FRAME_MARGIN, 0);

    m_contentFrame->setAnchor(VfxFPoint(0.5f, 0.0f));
    m_contentFrame->setPos(value.width / 2, VAPP_SHELL_MV_FRAME_CONTENT_Y_POSITION + VAPP_SHELL_MV_FRAME_BORDER_HEIGTH);
    m_contentFrame->setSize(value.width - VAPP_SHELL_MV_FRAME_BORDER_WIDTH * 2, VAPP_SHELL_MV_FRAME_CONTENT_TOTAL_HEIGTH);
    m_contentFrame->setMargins(VAPP_SHELL_MV_FRAME_MARGIN, 0, VAPP_SHELL_MV_FRAME_MARGIN, 0);
    m_contentFrame->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
    m_contentFrame->setMaxLines(VAPP_SHELL_MV_FRAME_CONTENT_LINE_NUMBER);
    m_contentFrame->setLineGap(0);
    m_contentFrame->setMinLineHeight(VAPP_SHELL_MV_FRAME_CONTENT_LINE_HEIGTH);
    m_contentFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);

    m_currentPageFrame->setAnchor(VfxFPoint(1.0f, 0.0f));
    m_currentPageFrame->setPos(value.width / 2, VAPP_SHELL_MV_FRAME_PAGE_Y_POSITION + VAPP_SHELL_MV_FRAME_BORDER_HEIGTH);

    m_totalPageFrame->setAnchor(VfxFPoint(0.0f, 0.0f));
    m_totalPageFrame->setPos(value.width / 2, VAPP_SHELL_MV_FRAME_PAGE_Y_POSITION + VAPP_SHELL_MV_FRAME_BORDER_HEIGTH);

    m_waitingIcon->setAnchor(VfxFPoint(0.5f, 0.5f));
    m_waitingIcon->setPos(value.width / 2 , value.height / 2);
    m_waitingIcon->setHidden(VFX_TRUE);

    m_newMsgIcon->setAnchor(VfxFPoint(0.0f, 0.0f));
    m_newMsgIcon->setPos(VAPP_SHELL_MV_FRAME_NEW_MSG_ICON_X_POSITION + VAPP_SHELL_MV_FRAME_BORDER_WIDTH,
                         VAPP_SHELL_MV_FRAME_NEW_MSG_ICON_Y_POSITION + VAPP_SHELL_MV_FRAME_BORDER_HEIGTH);
    m_waitingIcon->setHidden(VFX_TRUE);

    Super::setSize(value);
}

void VappShellMsgNotePaperFrame::setName(const VfxWString &value)
{
    m_nameFrame->setString(value);
}

void VappShellMsgNotePaperFrame::setDate(const VfxWString &value)
{
    m_dateFrame->setString(value);
}

void VappShellMsgNotePaperFrame::setContent(const VfxWString &value)
{
    m_contentFrame->setString(value);
}

void VappShellMsgNotePaperFrame::setCurrentPage(const VfxWString &value)
{
    m_currentPageFrame->setString(value);
}

void VappShellMsgNotePaperFrame::setTotalPage(const VfxWString &value)
{
    m_totalPageFrame->setString(value);
}

void VappShellMsgNotePaperFrame::setIsRead(VfxBool isRead)
{
    // we need to show the animation when the status changed from unread to read
    // however, the timing is different from the data read back
    //   ex:  notepaper change the page first
    //        set unread to read
    //        read sms content
    //        sms callback, set the sms data content status to read/unread
    //        show animation if need
    //

    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_NPFRAME_SETISREAD, (VfxS32)this, m_loading, isRead, m_smsData.status);

    if (!m_loading && isRead && m_smsData.status == SRV_SMS_STATUS_UNREAD)
    {
        showNewMsgAnimation();
    }

    m_IsRead = isRead;
}

// -------------------------------------------------------------
// Method
// -------------------------------------------------------------

void VappShellMsgNotePaperFrame::updateMsgInfo()
{

    m_loading = VFX_TRUE;

    m_dataProvider->m_signalGetMsgInfoFinished.connect(this, &Self::onGetMsgInfoFinished);

    VfxS32 result = m_dataProvider->getMsgInfo(&m_msgNode, 1, 0, 1, &m_msgInfo);
    // call back handler :  onGetMsgInfoFinished

    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_NPFRAME_UPDATEMSGINFO, (VfxS32)this, result);

    if (result == SRV_UM_RESULT_OK)
    {
        VfxWChar *phb_name;

        VFX_ALLOC_MEM(phb_name, (SRV_UM_MAX_ADDR_LEN + 1) * 2, this);

        srv_phb_get_name_by_number((U16*)m_msgInfo->address, (U16*)phb_name, SRV_UM_MAX_ADDR_LEN);

        if (vfx_sys_wcslen(phb_name) != 0)
        {
            setName(VfxWString().loadFromMem(phb_name));
        }
        else
        {
            // set the name frame
            setName(VfxWString().loadFromMem(m_msgInfo->address));
        }

        VFX_FREE_MEM(phb_name);

        // set the date frame
        VfxWString my_time;
        timestamp2String(my_time, m_msgInfo->timestamp, VFX_DATE_TIME_DATE_YEAR | VFX_DATE_TIME_DATE_MONTH
             | VFX_DATE_TIME_DATE_DAY | VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE);
        setDate(my_time);

        // Get the SMS detail content
        srv_sms_msg_data_struct *tmp_smsData;
        VFX_ALLOC_MEM(tmp_smsData, sizeof(srv_sms_msg_data_struct), this);
        memset(tmp_smsData, 0, sizeof(srv_sms_msg_data_struct));
        VFX_ALLOC_MEM(tmp_smsData->content_buff, 250, this);
        tmp_smsData->para_flag = (srv_sms_para_enum)(SRV_SMS_PARA_STATUS | SRV_SMS_PARA_CONTENT_BUFF);
        tmp_smsData->content_buff_size = 250;

        srv_sms_read_msg(m_msgNode.msg_id, MMI_FALSE, tmp_smsData, &Self::onReadSmsDataFinished, getObjHandle());

    }
    else if (result == SRV_UM_RESULT_PROCESS_BUSY)
    {
        m_waitingIcon->start();
    }
}

void VappShellMsgNotePaperFrame::showNewMsgAnimation()
{
    srv_sms_change_msg_status(
        m_msgNode.msg_id,
        SRV_SMS_STATUS_READ,
        NULL,
        this);

    m_smsData.status = SRV_SMS_STATUS_READ;

    m_newMsgIcon->setAutoAnimate(VFX_FALSE);
    m_newMsgIcon->setOpacity(1.0f);
    m_newMsgIcon->setHidden(VFX_FALSE);

    m_newMsgIcon->setAutoAnimate(VFX_TRUE);
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDuration(5000);
    VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
    m_newMsgIcon->setOpacity(0.0f);
    VfxAutoAnimate::commit();
}

// -------------------------------------------------------------
// Event Handler
// -------------------------------------------------------------

void VappShellMsgNotePaperFrame::onGetMsgInfoFinished(srv_um_get_msg_info_result result)
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_NPFRAME_ONGETMSGINFOFINISHED, (VfxS32)this, result.error);

    if (result.error == SRV_UM_RESULT_OK)
    {
        updateMsgInfo();
    }
    else
    {
        m_loading = VFX_FALSE;
        m_waitingIcon->stop();
        setName(VFX_WSTR("Unknown"));
        setContent(VFX_WSTR(""));
        setCurrentPage(VFX_WSTR(""));
        setTotalPage(VFX_WSTR(""));
    }
}

void VappShellMsgNotePaperFrame::onReadSmsDataFinished(srv_sms_callback_struct* callback_data)
{
    VappShellMsgNotePaperFrame *myFrame =  (VappShellMsgNotePaperFrame *) VfxObject::handleToObject((VfxObjHandle*)callback_data->user_data);

    srv_sms_msg_data_struct *sms_data = ((srv_sms_read_msg_cb_struct*)(callback_data->action_data))->msg_data;

    if (myFrame && myFrame->isKindOf(VFX_OBJ_CLASS_INFO(VappShellMsgNotePaperFrame)))
    {
        VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_NPFRAME_ONREADSMSDATAFINISHED, 1,
            (VfxS32)callback_data->user_data, callback_data->result, sms_data->status);

        myFrame->m_loading = VFX_FALSE;
        myFrame->m_waitingIcon->stop();

        memcpy(&myFrame->m_smsData, sms_data, sizeof(srv_sms_msg_data_struct));

        if (callback_data->result == MMI_TRUE)
        {
            if (sms_data->status & SRV_SMS_STATUS_UNSUPPORTED)
            {
                myFrame->setContent(VfxWString().loadFromRes(STR_GLOBAL_NOT_SUPPORTED));

            }
            else
            {
                myFrame->setContent(VfxWString().loadFromMem((const VfxWChar *)sms_data->content_buff));

            }

            if (sms_data->status & SRV_SMS_STATUS_UNREAD)
            {
                if (myFrame->m_IsRead)
                {
                    myFrame->showNewMsgAnimation();
                }
            }
        }
        else
        {
            // sometimes, sim card is locked, we cannot get the content from sim
            // ex: phonesuite connected
            myFrame->setContent(VfxWString().loadFromRes(STR_GLOBAL_NOT_SUPPORTED));
        }

        // would be freed later
        myFrame->m_smsData.content_buff = NULL;
    }
    else
    {
        VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_NPFRAME_ONREADSMSDATAFINISHED, 0,
            (VfxS32)callback_data->user_data, callback_data->result, sms_data->status);
    }

    VFX_FREE_MEM(sms_data->content_buff);
    VFX_FREE_MEM(sms_data);
}

/*****************************************************************************
 * Class VappShellFgView
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappShellMsgMainScreen", VappShellMsgMainScreen, VfxScreen);

const VfxResId VappShellMsgMainScreen::toolbarConfig[VAPP_SHELL_MV_TOOLBAR_TOTAL_ENUM][4] = VAPP_SHELL_MV_TOOLBAR_SETTING;

VappShellMsgMainScreen::VappShellMsgMainScreen(void):
    m_notePaper(NULL),
    m_toolbar(NULL),
    m_msgList(NULL),
    m_isFreeze(VFX_FALSE),
    m_noMsgImage(NULL),
    m_noMsgText(NULL),
    m_waitingIcon(NULL),
    m_deleteConfirmed(VFX_FALSE),
    m_confirmPopup(NULL)
{
    m_cacheMsgIndex = 0;
    memset(&m_cacheMsgNode, 0, sizeof(m_cacheMsgNode));
}

void VappShellMsgMainScreen::onInit(void)
{

    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_MAINSCREEN_ONINIT, (VfxS32) this);

    Super::onInit();

    vrt_size_struct main_screen_size;
    vrt_color_type_enum main_screen_color_format;
    vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

    setRect(0, 0, main_screen_size.width, main_screen_size.height);
    //setImgContent(VfxImageSrc(VAPP_SHELL_IMG_SWITCH_BG));

    // In order to increase performance, we separate the background image from main screen
    // then this frame can add into cache and never dirty
    VfxImageFrame *bg;
    VFX_OBJ_CREATE(bg, VfxImageFrame, this);
    bg->setResId(VAPP_SHELL_IMG_SWITCH_BG);
    bg->setBgColor(VFX_COLOR_BLACK);
    bg->setIsOpaque(VFX_TRUE);

    VFX_OBJ_CREATE(m_noMsgImage, VfxImageFrame, this);
    m_noMsgImage->setResId(IMG_ID_SHELL_MSG_VIEWER_NO_MESSAGE);
    m_noMsgImage->setAnchor(VfxFPoint(0.5f, 0.0f));
    m_noMsgImage->setPos(main_screen_size.width / 2, VAPP_SHELL_MV_NO_MESSAGE_ICON_Y_POSITION);
    m_noMsgImage->setHidden(VFX_TRUE);

    VFX_OBJ_CREATE(m_noMsgText, VfxTextFrame, this);
    m_noMsgText->setString(VFX_WSTR_RES(STR_ID_SHELL_MSG_VIEWER_INITIALIZING));
    m_noMsgText->setColor(VAPP_SHELL_MV_NO_MESSAGE_TEXT_COLOR);
    m_noMsgText->setFont(VfxFontDesc(VAPP_SHELL_MV_NO_MESSAGE_TEXT_SIZE, VFX_FONT_DESC_ATTR_NORMAL));
    m_noMsgText->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_noMsgText->setAnchor(VfxFPoint(0.5f, 0.0f));
    m_noMsgText->setSize(VAPP_SHELL_MV_NO_MESSAGE_TEXT_WIDTH, VAPP_SHELL_MV_NO_MESSAGE_TEXT_HEIGTH);
    m_noMsgText->setPos(main_screen_size.width / 2, VAPP_SHELL_MV_NO_MESSAGE_TEXT_Y_POSITION);

    VFX_OBJ_CREATE(m_notePaper, VappNotePaper, this);
    m_notePaper->setAnchor(VfxFPoint(0.5f, 0.0f));
    m_notePaper->setPos(main_screen_size.width / 2, VAPP_SHELL_MV_NOTEPAPER_Y_POSITION);
    m_notePaper->setFrameProvider(this);
    m_notePaper->setHidden(VFX_TRUE);
    m_notePaper->m_signalPageIndexChanged.connect(this, &Self::onPageIndexChanged);
    m_notePaper->m_signalTap.connect(this, &Self::onNotePaperTap);

    VFX_OBJ_CREATE(m_toolbar, VcpSegmentButton, this);
    m_toolbar->setAnchor(VfxFPoint(0.5f, 0.0f));
    m_toolbar->setPos(main_screen_size.width / 2, VAPP_SHELL_MV_TOOLBAR_Y_POSITION);
    m_toolbar->setSize(VAPP_SHELL_MV_TOOLBAR_BUTTON_WIDTH * VAPP_SHELL_MV_TOOLBAR_TOTAL_ENUM, VAPP_SHELL_MV_TOOLBAR_BUTTON_HEIGTH);
    m_toolbar->setHidden(VFX_TRUE);

    for(int i = 0; i < VAPP_SHELL_MV_TOOLBAR_TOTAL_ENUM ; i++)
    {
        m_toolbar->addButton(
            i,
            VcpStateImage(
                Self::toolbarConfig[i][0], Self::toolbarConfig[i][1],
                Self::toolbarConfig[i][2], Self::toolbarConfig[i][3]),
            VFX_WSTR(""));
    }

    m_toolbar->m_signalButtonClicked.connect(this, &Self::onToolbarClick);
}

void VappShellMsgMainScreen::onDeinit(void)
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_MAINSCREEN_ONDEINIT, (VfxS32) this);

    if (m_msgList)
    {
        m_msgList->m_signalListUpdating.disconnect(this, &Self::onMsgListUpdating);
        m_msgList->m_signalListUpdated.disconnect(this, &Self::onMsgListUpdated);
        m_msgList->m_signalListReleased.disconnect(this, &Self::onMsgListReleased);
    }

    Super::onDeinit();
}

// -------------------------------------------------------------
// Property set/get
// -------------------------------------------------------------

void VappShellMsgMainScreen::setMsgIndex(VfxS32 index)
{

    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_MAINSCREEN_SETMSGINDEX, index);

    VFX_ASSERT(m_msgList);
//    VFX_ASSERT(!m_msgList->isOutOfDate());
//    VFX_ASSERT(!m_msgList->isUpdating());

    if (index < 0 || index > m_msgList->getListSize())
    {
        index = 0;
    }

    // the value are the same, no need to update
    if (m_cacheMsgIndex == index)
    {
        if (index == 0)
        {
            return;
        }

        if (m_cacheMsgNode.msg_id == m_msgList->getMsgList()[index - 1].msg_id &&
            m_cacheMsgNode.msg_type == m_msgList->getMsgList()[index - 1].msg_type)
        {
            return;
        }
    }

    if (index == 0)
    {
        m_cacheMsgIndex = 0;
        memset(&m_cacheMsgNode, 0, sizeof(m_cacheMsgNode));
    }
    else
    {
        m_cacheMsgIndex = index;
        memcpy(&m_cacheMsgNode, &m_msgList->getMsgList()[index - 1], sizeof(m_cacheMsgNode));
    }

    checkUpdate();
}

VfxS32 VappShellMsgMainScreen::getMsgIndex(void) const
{
    return m_notePaper->getCurrentPage();
}

void VappShellMsgMainScreen::setMsgList(VappMsgList * msgList)
{
    m_msgList = msgList;
    m_msgList->m_signalListUpdating.connect(this, &Self::onMsgListUpdating);
    m_msgList->m_signalListUpdated.connect(this, &Self::onMsgListUpdated);
    m_msgList->m_signalListReleased.connect(this, &Self::onMsgListReleased);
}

void VappShellMsgMainScreen::setIsFreeze(VfxBool isFreeze)
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_MAINSCREEN_SETISFREEZE, isFreeze);

    m_isFreeze = isFreeze;
    m_notePaper->setIsFreeze(isFreeze);

    if (isFreeze == VFX_TRUE && m_waitingIcon)
    {
        m_waitingIcon->stop();
    }
}

VfxBool VappShellMsgMainScreen::getIsFreeze() const
{
    return m_isFreeze;
}

// Set the frame is focused
void VappShellMsgMainScreen::setFocused(VfxBool value)
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_MAINSCREEN_SETFOCUSED, value);

    if (value == VFX_TRUE)
    {
        m_notePaper->setFocused(VFX_TRUE);
    }
    else
    {
        Super::setFocused(value);
    }
}

// -------------------------------------------------------------
// Method
// -------------------------------------------------------------

VfxS32 VappShellMsgMainScreen::replyMsg(void)
{
    VFX_ASSERT(m_msgList);
    VFX_ASSERT(!m_msgList->isOutOfDate());
    VFX_ASSERT(!m_msgList->isUpdating());

    // create group
    MMI_ID opt_grp_id = mmi_frm_group_create(
                        GRP_ID_ROOT,
                        GRP_ID_AUTO_GEN,
                        &Self::screenGroupProg,
                        (void*) this);

    mmi_frm_group_enter(opt_grp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_sms_um_activate_reply(
        opt_grp_id,
        m_msgList->getMsgList()[getMsgIndex() - 1].msg_type,
        m_msgList->getMsgList()[getMsgIndex() - 1].msg_id);

    return 0;
}

VfxS32 VappShellMsgMainScreen::createMsg(void)
{
    mmi_um_entry_write_msg_ext();
    return 0;
}

VfxS32 VappShellMsgMainScreen::deleteMsg(void)
{
    VFX_ASSERT(m_msgList);
    VFX_ASSERT(!m_msgList->isOutOfDate());
    VFX_ASSERT(!m_msgList->isUpdating());

    setIsDisabled(VFX_TRUE);

    VfxS32 delete_id = m_msgList->getMsgList()[getMsgIndex() - 1].msg_id;

    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_MAINSCREEN_DELETEMSG, delete_id);

    if (getMsgIndex() == m_msgList->getListSize())
    {
        setMsgIndex(getMsgIndex() - 1);
    }
    else
    {
        setMsgIndex(getMsgIndex() + 1);
    }

    VcpEffectMorphFadeInData input;
    input.fromRect = VfxRect(
        VfxPoint(m_toolbar->getPos().x + VAPP_SHELL_MV_TOOLBAR_BUTTON_WIDTH, m_toolbar->getPos().y - VAPP_SHELL_MV_TOOLBAR_BUTTON_WIDTH),
        VfxSize(VAPP_SHELL_MV_TOOLBAR_BUTTON_WIDTH, VAPP_SHELL_MV_TOOLBAR_BUTTON_HEIGTH));
    m_notePaper->deletePage(VCP_EFFECT_MORPH_FADE_IN, 1500, VCP_EFFECT_DIRECTION_FROM_NONE,
        VFX_TRUE, &input, sizeof(input));

    srv_sms_delete_msg(delete_id, &Self::smsDeletedCb, getObjHandle());    

	return 0;
}


void VappShellMsgMainScreen::showDeleteConfirm()
{
    VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, this->findScreen());

    m_confirmPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
    m_confirmPopup->setText(VFX_WSTR_RES(STR_ID_SHELL_MSG_VIEWER_DELETE_MESSAGE));
    m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    m_confirmPopup->setCustomButton(
        VfxWString().loadFromRes(STR_GLOBAL_DELETE),
        VfxWString().loadFromRes(STR_GLOBAL_CANCEL),
        VCP_POPUP_BUTTON_TYPE_WARNING,
        VCP_POPUP_BUTTON_TYPE_CANCEL
        );
    m_confirmPopup->m_signalButtonClicked.connect(this, &Self::onConfirmPopupClicked);
    m_confirmPopup->m_signalPopupState.connect(this, &Self::onConfirmPopupStateChanged);
    m_confirmPopup->setAutoDestory(VFX_TRUE);

    m_confirmPopup->show(VFX_TRUE);
}

void VappShellMsgMainScreen::forceUpdate()
{
    VfxBool isFreeze = getIsFreeze();

    if (isFreeze)
    {
        setIsFreeze(VFX_FALSE);
    }

    onUpdate();

    if (isFreeze)
    {
        setIsFreeze(VFX_TRUE);
    }
}

// -------------------------------------------------------------
// Event Handler
// -------------------------------------------------------------

void VappShellMsgMainScreen::onUpdate()
{
    if (m_isFreeze)
    {
        if (m_noMsgText)
        {
            m_noMsgText->checkUpdate();
        }
        return;
    }

    VFX_ASSERT(m_msgList);

    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_MAINSCREEN_UPDATEALL, m_msgList->isUpdating(), m_msgList->isOutOfDate());

    if (!srv_um_check_ready_type(SRV_UM_MSG_SMS) || m_msgList->isUpdating())
    {
        if (!m_waitingIcon)
        {
            vrt_size_struct main_screen_size;
            vrt_color_type_enum main_screen_color_format;
            vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

            VFX_OBJ_CREATE(m_waitingIcon, VcpWaitingIcon, this);
            m_waitingIcon->setAnchor(VfxFPoint(0.5f, 0.0f));
            m_waitingIcon->setPos(main_screen_size.width / 2, VAPP_SHELL_MV_NO_MESSAGE_ICON_Y_POSITION);
            m_waitingIcon->setHiddenWhenStopped(VFX_FALSE);
            m_waitingIcon->setHidden(VFX_FALSE);
        }

        if (!srv_um_check_ready_type(SRV_UM_MSG_SMS))
        {
            m_notePaper->setHidden(VFX_TRUE);
            m_toolbar->setHidden(VFX_TRUE);
            m_noMsgImage->setHidden(VFX_TRUE);
            m_noMsgText->setString(VFX_WSTR_RES(STR_ID_SHELL_MSG_VIEWER_INITIALIZING));
            m_noMsgText->setHidden(VFX_FALSE);
        }

        m_toolbar->setIsDisabled(VFX_TRUE);

        m_waitingIcon->start();

        return;
    }
    else
    {
        if (m_waitingIcon)
        {
            VFX_OBJ_CLOSE(m_waitingIcon);
        }
    }

    // no message or the service is not available
    if (m_cacheMsgIndex == 0 || m_msgList->isOutOfDate())
    {
        m_notePaper->setCurrentPage(0);
        m_notePaper->setHidden(VFX_TRUE);
        m_toolbar->setIsDisabled(VFX_FALSE);
        m_toolbar->setHidden(VFX_FALSE);
        m_noMsgImage->setHidden(VFX_FALSE);
        m_noMsgText->setString(VFX_WSTR_RES(STR_ID_SHELL_MSG_VIEWER_NO_MESSAGE));
        m_noMsgText->setHidden(VFX_FALSE);

        for(int i = 0; i < VAPP_SHELL_MV_TOOLBAR_TOTAL_ENUM ; i++)
        {
            m_toolbar->setButtonIsDisabled(i, VFX_TRUE);
        }

        // service is not available
        if (!m_msgList->isOutOfDate())
        {
            m_toolbar->setButtonIsDisabled(VAPP_SHELL_MV_TOOLBAR_NEW_MESSAGE, VFX_FALSE);
        }
    }
    else
    {
        m_notePaper->setCurrentPage(m_cacheMsgIndex);
        m_notePaper->setHidden(VFX_FALSE);
        m_toolbar->setIsDisabled(VFX_FALSE);
        m_toolbar->setHidden(VFX_FALSE);
        m_noMsgImage->setHidden(VFX_TRUE);
        m_noMsgText->setHidden(VFX_TRUE);

        for(int i = 0; i < VAPP_SHELL_MV_TOOLBAR_TOTAL_ENUM ; i++)
        {
            m_toolbar->setButtonIsDisabled(i, VFX_FALSE);
        }
    }
}

void VappShellMsgMainScreen::onToolbarClick(VfxObject *sender, VfxId Id)
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_MAINSCREEN_ONTOOLBARCLICK, Id);

    switch(Id)
    {
        case VAPP_SHELL_MV_TOOLBAR_NEW_MESSAGE:
            createMsg();
            break;

        case VAPP_SHELL_MV_TOOLBAR_REPLY_MESSAGE:
            replyMsg();
            break;

        case VAPP_SHELL_MV_TOOLBAR_SWITCH_LIST_MENU:
            m_signalSwitchButtonClicked.emit();
            break;

        case VAPP_SHELL_MV_TOOLBAR_DELETE:
            showDeleteConfirm();
            break;
    }
}

void VappShellMsgMainScreen::onConfirmPopupClicked(VfxObject* sender, VfxId id)
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_MAINSCREEN_ONCONFIRMPOPUPCLICKED, id);

    // Delete
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        m_deleteConfirmed = VFX_TRUE;
    }
    // Cancel
    else if (id == VCP_CONFIRM_POPUP_BUTTON_USER_2)
    {
        // do nothing
    }
}

void VappShellMsgMainScreen::onConfirmPopupStateChanged(VfxBasePopup* popup, VfxBasePopupStateEnum state)
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_MAINSCREEN_ONCONFIRMPOPUPSTATECHANGED, state, m_deleteConfirmed);

    if (state == VFX_BASE_POPUP_AFTER_END_ANIMATION)
    {
        if (m_deleteConfirmed)
        {
            deleteMsg();
            m_deleteConfirmed = VFX_FALSE;
        }
        m_confirmPopup = NULL;
    }
}

void VappShellMsgMainScreen::onMsgListUpdating()
{
    if (m_confirmPopup)
    {
        VFX_OBJ_CLOSE(m_confirmPopup);
        m_deleteConfirmed = VFX_FALSE;
    }
}

void VappShellMsgMainScreen::onMsgListUpdated()
{
    VFX_ASSERT(m_msgList);

    // Sometimes the process may be cancelled due to sms unready
    // In this case, we just to show empty screen or initializing
    // VFX_ASSERT(!m_msgList->isOutOfDate());

    VFX_ASSERT(!m_msgList->isUpdating());

    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_MAINSCREEN_ONMSGLISTUPDATED, m_msgList->getListSize(), m_cacheMsgNode.msg_type);

    if (m_msgList->getListSize() == 0)
    {
        setMsgIndex(0);
    }
    else
    {

        if (m_cacheMsgNode.msg_type != SRV_UM_MSG_NONE)
        {
            VfxS32 i;

            for(i = 0; i < m_msgList->getListSize();i++)
            {
                if (m_msgList->getMsgList()[i].msg_type == m_cacheMsgNode.msg_type &&
                    m_msgList->getMsgList()[i].msg_id == m_cacheMsgNode.msg_id)
                {
                    setMsgIndex(i + 1);
                    break;
                }
            }

            VFX_LOG(VFX_INFO, VAPP_SHELL_MV_MAINSCREEN_ONMSGLISTUPDATED_INFO, i);

            /* not found */
            if (i == m_msgList->getListSize())
            {
                setMsgIndex(1);
            }
        }
        else
        {
            setMsgIndex(1);
        }
    }

    checkUpdate();
}

void VappShellMsgMainScreen::onMsgListReleased()
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_MAINSCREEN_ONMSGLISTRELEASED);

    if (m_confirmPopup)
    {
        VFX_OBJ_CLOSE(m_confirmPopup);
        m_deleteConfirmed = VFX_FALSE;
    }
}

void VappShellMsgMainScreen::onPageIndexChanged(VfxS32 pageIndex, VfxFrame *cell)
{
    VFX_ASSERT(m_msgList);
//    VFX_ASSERT(!m_msgList->isOutOfDate());
//    VFX_ASSERT(!m_msgList->isUpdating());
    VFX_ASSERT(pageIndex <= m_msgList->getListSize());

    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_MAINSCREEN_ONPAGEINDEXCHANGED, pageIndex, (VfxS32) cell);

    if (pageIndex == 0)
    {
        m_cacheMsgIndex = 0;
        memset(&m_cacheMsgNode, 0, sizeof(m_cacheMsgNode));
    }
    else
    {
        VappShellMsgNotePaperFrame *myFrame = VFX_OBJ_DYNAMIC_CAST(cell, VappShellMsgNotePaperFrame);
        myFrame->setIsRead(VFX_TRUE);

        m_cacheMsgIndex = pageIndex;
        memcpy(&m_cacheMsgNode, &m_msgList->getMsgList()[pageIndex - 1], sizeof(m_cacheMsgNode));
    }
}

void VappShellMsgMainScreen::onNotePaperTap(VfxS32 pageIndex, VfxFrame *cell)
{
    VFX_ASSERT(m_msgList);
    VFX_ASSERT(!m_msgList->isOutOfDate());
    VFX_ASSERT(!m_msgList->isUpdating());
    VFX_ASSERT(pageIndex <= m_msgList->getListSize());

    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_MAINSCREEN_ONNOTEPAPERTAP, pageIndex, (VfxS32) cell);

    mmi_id opt_grp_id;

    // create group
    opt_grp_id = mmi_frm_group_create(
                            GRP_ID_ROOT,
                            GRP_ID_AUTO_GEN,
                            &Self::screenGroupProg,
                            (void*) this);

    mmi_frm_group_enter(opt_grp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    opt_grp_id = cui_msg_viewer_create(opt_grp_id, m_msgList->getMsgList()[getMsgIndex() - 1].msg_id,
        m_msgList->getMsgList()[getMsgIndex() - 1].msg_type, 0);

    cui_msg_viewer_run(opt_grp_id);
}

void VappShellMsgMainScreen::onNotePaperPageDeleted(void)
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_MAINSCREEN_ONNOTEPAPERPAGEDELETED);
}

// -------------------------------------------------------------
// Plutommi callback or prog, static function
// -------------------------------------------------------------

void VappShellMsgMainScreen::smsDeletedCb(srv_sms_callback_struct* callback_data)
{
    VappShellMsgMainScreen *myMainScreen =  (VappShellMsgMainScreen *) VfxObject::handleToObject((VfxObjHandle)(callback_data->user_data));

    if (myMainScreen && myMainScreen->isKindOf(VFX_OBJ_CLASS_INFO(VappShellMsgMainScreen)))
    {
        VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_MAINSCREEN_SMSDELETEDCB, 1 , callback_data->result);

        if (callback_data->result == MMI_TRUE)
        {
            myMainScreen->setIsDisabled(VFX_FALSE);
        }
        else
        {
            // delete fail, go back to original page
            myMainScreen->setMsgIndex(myMainScreen->getMsgIndex() - 1);
            myMainScreen->m_msgList->update();
        }
    }
    else
    {
        VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_MAINSCREEN_SMSDELETEDCB, 0 , callback_data->result);
    }
}

mmi_ret VappShellMsgMainScreen::screenGroupProg(mmi_event_struct *evt)
{
//    VappShellMsgMainScreen *myMainScreen =  (VappShellMsgMainScreen *) evt->user_data;

//    if (myMainScreen->isValid() && myMainScreen->isKindOf(VFX_OBJ_CLASS_INFO(VappShellMsgMainScreen)))
    {
        VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_MAINSCREEN_SCREENGROUPPROG, evt->evt_id);

        switch(evt->evt_id)
        {
        case EVT_ID_CUI_MSG_VIEWER_CLOSE:
            cui_msg_viewer_event_struct *cui_msg_viewer_evt = (cui_msg_viewer_event_struct*)evt;
            cui_msg_viewer_close(cui_msg_viewer_evt->sender_id);
            break;
        }
    }

    return MMI_RET_OK;
}

// -------------------------------------------------------------
// IVappNotePaperFrameProvider Implement
// -------------------------------------------------------------

VfxFrame* VappShellMsgMainScreen::createNPFrame(VfxS32 page, VfxSize size)
{
    VFX_ASSERT(m_msgList);

    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_MAINSCREEN_CREATENPFRAME, page, size.height, m_msgList->isUpdating());

    if (page > m_msgList->getListSize() || page <= 0)
    {
        return NULL;
    }

    if (!m_msgList->isUpdating())
    {
        VappShellMsgNotePaperFrame *myFrame;

        VFX_OBJ_CREATE(myFrame, VappShellMsgNotePaperFrame, this);

        myFrame->setSize(size);

        myFrame->setPageData(m_msgList->getMsgList()[page - 1], page, m_msgList->getListSize());

        return myFrame;
    }

    return NULL;
}

void VappShellMsgMainScreen::closeNPFrame(VfxFrame *cell)
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_MAINSCREEN_CLOSENPFRAME, (VfxS32) cell);

    if (cell)
    {
        if (cell->isKindOf(VFX_OBJ_CLASS_INFO(VappShellMsgNotePaperFrame)))
        {
            VFX_OBJ_CLOSE(cell);
        }
        else
        {
            VFX_ASSERT(0);
        }
    }
}

VfxFrame* VappShellMsgMainScreen::updateNPFrame(VfxS32 page, VfxSize size, VfxFrame *cell)
{
    VFX_ASSERT(m_msgList);

    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_MAINSCREEN_UPDATENPFRAME, page, size.height, (VfxS32) cell);

    if (page > m_msgList->getListSize() || page <= 0)
    {
        VFX_OBJ_CLOSE(cell);
        return NULL;
    }

    if (!m_msgList->isUpdating() && cell)
    {
        VappShellMsgNotePaperFrame *myFrame = VFX_OBJ_DYNAMIC_CAST(cell, VappShellMsgNotePaperFrame);

        VFX_ASSERT(myFrame);

        if (!m_msgList->isUpdating())
        {
            myFrame->setPageData(m_msgList->getMsgList()[page - 1], page, m_msgList->getListSize());
        }
        return myFrame;
    }
    else
    {
        VFX_OBJ_CLOSE(cell);
    }

    return NULL;
}

VfxU32 VappShellMsgMainScreen::getNPCount() const
{
    if (m_msgList)
    {
        return m_msgList->getListSize();
    }
    return 0;
}

/*****************************************************************************
 * Class VappShellMsgViewer
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappShellMsgViewer", VappShellMsgViewer, VappShellPanel);

VappShellMsgViewer* VappShellMsgViewer::m_activeShellMsgViewer = NULL;

VappShellMsgViewer::VappShellMsgViewer(void):
    m_pagePanel(NULL),
    m_mainScreen(NULL),
    m_listScreen(NULL),
    m_viewMode(MAIN_SCREEN_VIEW),
    m_listCntx(NULL),
    m_msgList(NULL)
{

}

void VappShellMsgViewer::onInit(void)
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_ONINIT, (VfxS32) this);

    Super::onInit();

    VFX_OBJ_CREATE(m_msgList, VappMsgList, this);
    m_msgList->setMsgBoxInfo(SRV_UM_MSG_SMS, SRV_UM_MSG_BOX_INBOX);
    m_msgList->setSortBy(SRV_UM_LIST_IDX_TIMESTAMP, SRV_UM_SORT_ORDER_UNCLASSIFIED);
    m_msgList->m_signalListUpdating.connect(this, &Self::onMsgListUpdating);
    m_msgList->m_signalListUpdated.connect(this, &Self::onMsgListUpdated);
    m_msgList->m_signalListReleased.connect(this, &Self::onMsgListReleased);

    m_activeShellMsgViewer = this;
}

void VappShellMsgViewer::onInitView(void)
{

    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_ONINITVIEW, (VfxS32) this);

    Super::onInitView();

    mmi_frm_cb_reg_event(EVT_ID_SRV_UM_NOTIFY_READY, &Self::onUmSrvReadyNotify, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_UM_NOTIFY_REFRESH, &Self::onUmSrvRefreshNotify, this);

    // Connect signal to refresh the viewer time string.
    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.connect(this, &VappShellMsgViewer::onTimeChanged);

    vrt_size_struct main_screen_size;
    vrt_color_type_enum main_screen_color_format;
    vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

    this->setRect(0, 0, main_screen_size.width, main_screen_size.height);

    VFX_OBJ_CREATE(m_pagePanel, VcpPagePanel, this);
    VFX_OBJ_CREATE(m_mainScreen, VappShellMsgMainScreen, m_pagePanel);
    VFX_OBJ_CREATE(m_listScreen, VappShellMsgListScreen, m_pagePanel);

    m_pagePanel->setRect(0, 0, main_screen_size.width, main_screen_size.height);
    m_pagePanel->setBgColor(VRT_COLOR_BLACK);

    m_mainScreen->setRect(0, 0, main_screen_size.width, main_screen_size.height);
    m_mainScreen->m_signalSwitchButtonClicked.connect(this, VFX_STATIC_CAST(&Self::onSwitchView, void (VfxObject::*)()));
    m_mainScreen->setIsOpaque(VFX_TRUE);

    m_listScreen->setRect(0, 0, main_screen_size.width, main_screen_size.height);
    m_listScreen->m_signalBackButtonClicked.connect(this, VFX_STATIC_CAST(&Self::onSwitchView, void (VfxObject::*)()));
    m_listScreen->m_signalItemSelected.connect(this, VFX_STATIC_CAST(&Self::onSwitchView, void (VfxObject::*)(VfxS32)));
    m_listScreen->setIsOpaque(VFX_TRUE);

    m_mainScreen->setMsgList(m_msgList);
    m_listScreen->setMsgList(m_msgList);

    if (!serviceIsAvailable())
    {
        // release message list in this case
        m_msgList->release(VFX_TRUE);
    }
    else
    {
        if (m_msgList->isOutOfDate())
        {
            m_msgList->update();
        }
    }

    if (m_viewMode == MAIN_SCREEN_VIEW)
    {
        m_pagePanel->setCurrentFrame(m_mainScreen);
        hideShortcutBar(VFX_FALSE);
        m_mainScreen->checkUpdate();
    }
    else
    {
        m_pagePanel->setCurrentFrame(m_listScreen);
        hideShortcutBar(VFX_TRUE);
        m_listScreen->checkUpdate();
    }

    m_mainScreen->setIsFreeze(VFX_TRUE);
    m_listScreen->setIsFreeze(VFX_TRUE);
}


void VappShellMsgViewer::onEnterView()
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_ONENTERVIEW, (VfxS32) this, m_viewMode);

    Super::onEnterView();

    if (!serviceIsAvailable())
    {
        /* release message list in this case */
        m_msgList->release(VFX_TRUE);
    }
    else
    {
        if (m_msgList->isOutOfDate())
        {
            m_msgList->update();
        }
    }

    if (m_viewMode == MAIN_SCREEN_VIEW)
    {
        m_mainScreen->setIsFreeze(VFX_FALSE);
        m_listScreen->setIsFreeze(VFX_TRUE);

        m_pagePanel->setCurrentFrame(m_mainScreen);
        hideShortcutBar(VFX_FALSE);
        m_mainScreen->checkUpdate();
    }
    else
    {
        m_mainScreen->setIsFreeze(VFX_TRUE);
        m_listScreen->setIsFreeze(VFX_FALSE);
        m_pagePanel->setCurrentFrame(m_listScreen);
        hideShortcutBar(VFX_TRUE);
        m_listScreen->checkUpdate();
    }
}

void VappShellMsgViewer::onExitView(ShellExitCauseEnum cause)
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_ONEXITVIEW, (VfxS32) this, cause);

    if (cause == APP_SHELL_END_KEY_EXIT)
    {
        m_viewMode = MAIN_SCREEN_VIEW;
    }

    m_pagePanel->setCurrentFrame(m_mainScreen);
    m_mainScreen->setIsFreeze(VFX_TRUE);
    m_listScreen->setIsFreeze(VFX_TRUE);

    Super::onExitView(cause);
}

void VappShellMsgViewer::onDeinitView()
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_ONDEINITVIEW, (VfxS32) this);

    VFX_OBJ_CLOSE(m_mainScreen);
    VFX_OBJ_CLOSE(m_listScreen);
    VFX_OBJ_CLOSE(m_pagePanel);

    mmi_frm_cb_dereg_event(EVT_ID_SRV_UM_NOTIFY_READY, &Self::onUmSrvReadyNotify, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_UM_NOTIFY_REFRESH, &Self::onUmSrvRefreshNotify, this);

    // Connect signal to refresh the viewer time string.
    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.disconnect(this, &VappShellMsgViewer::onTimeChanged);

    Super::onDeinitView();
}

void VappShellMsgViewer::onDeinit()
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_ONDEINIT, (VfxS32) this);

    m_msgList->m_signalListUpdating.disconnect(this, &Self::onMsgListUpdating);
    m_msgList->m_signalListUpdated.disconnect(this, &Self::onMsgListUpdated);
    m_msgList->m_signalListReleased.disconnect(this, &Self::onMsgListReleased);

    m_activeShellMsgViewer = NULL;

    Super::onDeinit();
}

void VappShellMsgViewer::onUpdateView()
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_ONUPDATEVIEW, (VfxS32) this);

    // before enter shell msg viewer, user can go to setting menu to change language
    // In this case, shell msg viwer is still in init state

    Super::onUpdateView();

    if (!serviceIsAvailable())
    {
        /* release message list in this case */
        m_msgList->release(VFX_TRUE);
    }
    else
    {
        if (m_msgList->isOutOfDate())
        {
            m_msgList->update();
        }
    }

    if (m_mainScreen)
    {
        m_mainScreen->forceUpdate();
    }
}

// -------------------------------------------------------------
// Property set/get
// -------------------------------------------------------------

VfxS32 VappShellMsgViewer::getPanelStrId()
{
    return STR_ID_SHELL_MSG_VIEWER_TITLE;
}

VfxResId VappShellMsgViewer::getReadImgId(VfxBool isRead)
{
    if (isRead)
    {
        return IMG_ID_SHELL_MSG_VIEWER_READ;
    }
    else
    {
        return IMG_ID_SHELL_MSG_VIEWER_UNREAD;
    }
}

// Set the frame is focused
void VappShellMsgViewer::setFocused(VfxBool value)
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_SETFOCUSED, value);

    if (value == VFX_TRUE)
    {
        if (m_viewMode == MAIN_SCREEN_VIEW)
        {
            m_mainScreen->setFocused(VFX_TRUE);
        }
        else
        {
            m_listScreen->setFocused(VFX_TRUE);
        }
    }
    else
    {
        Super::setFocused(value);
    }
}

VappShellMsgViewer * VappShellMsgViewer::getActiveShellMsgViewer()
{
    return m_activeShellMsgViewer;
}

// -------------------------------------------------------------
// Method
// -------------------------------------------------------------
VfxBool VappShellMsgViewer::serviceIsAvailable()
{
    VfxBool is_available = VFX_TRUE;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    if (!srv_um_check_ready_type(SRV_UM_MSG_SMS))
    {
        is_available = VFX_FALSE;
    }

    return is_available;
}

// -------------------------------------------------------------
// Event Handler
// -------------------------------------------------------------

void VappShellMsgViewer::onUpdate()
{
    if (m_mainScreen && m_listScreen)
    {
        m_mainScreen->checkUpdate();
        m_listScreen->checkUpdate();
    }
}

void VappShellMsgViewer::onSwitchView(void)
{
    onSwitchView(0);
}

void VappShellMsgViewer::onSwitchView(VfxS32 index)
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_ONSWITCHVIEW, m_viewMode);

    if (m_viewMode == MAIN_SCREEN_VIEW)
    {
        m_viewMode = LIST_SCREEN_VIEW;
        m_mainScreen->setIsFreeze(VFX_TRUE);
        m_listScreen->setIsFreeze(VFX_FALSE);
        m_pagePanel->switchTo(m_listScreen, VCP_PAGE_EFFECT_SMALL_FLIP, 500, VCP_PAGE_DIRECTION_FROM_LEFT);
        hideShortcutBar(VFX_TRUE);
        m_listScreen->checkUpdate();
    }
    else
    {
        m_viewMode = MAIN_SCREEN_VIEW;
        m_mainScreen->setIsFreeze(VFX_FALSE);
        m_listScreen->setIsFreeze(VFX_TRUE);

        if (index != 0)
        {
            m_mainScreen->setMsgIndex(index);
        }

        m_pagePanel->switchTo(m_mainScreen, VCP_PAGE_EFFECT_SMALL_FLIP, 500, VCP_PAGE_DIRECTION_FROM_LEFT);
        hideShortcutBar(VFX_FALSE);
        m_mainScreen->checkUpdate();
    }
}

void VappShellMsgViewer::onMsgListUpdating()
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_ONMSGLISTUPDATING);

    m_mainScreen->setIsDisabled(VFX_TRUE);
    m_listScreen->setIsDisabled(VFX_TRUE);
}

void VappShellMsgViewer::onMsgListUpdated()
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_ONMSGLISTUPDATED);

    m_mainScreen->setIsDisabled(VFX_FALSE);
    m_listScreen->setIsDisabled(VFX_FALSE);
}

void VappShellMsgViewer::onMsgListReleased()
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_ONMSGLISTRELEASED);
    m_mainScreen->setIsDisabled(VFX_TRUE);
    m_listScreen->setIsDisabled(VFX_TRUE);
}

// -------------------------------------------------------------
// Static MMI Callback Handler
// -------------------------------------------------------------
mmi_ret VappShellMsgViewer::onUmSrvReadyNotify(mmi_event_struct *param)
{
    VappShellMsgViewer *m_activeViewer =  (VappShellMsgViewer *) param->user_data;

    srv_um_notify_ready_evt_struct *evt = (srv_um_notify_ready_evt_struct*) param;

    if (evt->msg_type == SRV_UM_MSG_SMS)
    {
        if (evt->result == KAL_TRUE)
        {
            if (m_activeViewer->getPanelState() == APP_SHELL_ENTER_VIEW)
            {
                m_activeViewer->m_msgList->update();
            }
        }
        else
        {
            // let the main screen go back to empty screen
            m_activeViewer->m_msgList->release(VFX_TRUE);
            m_activeViewer->m_mainScreen->checkUpdate();
            m_activeViewer->m_listScreen->checkUpdate();
        }
    }
    return MMI_RET_OK;
}

mmi_ret VappShellMsgViewer::onUmSrvRefreshNotify(mmi_event_struct *param)
{
    VappShellMsgViewer *m_activeViewer =  (VappShellMsgViewer *) param->user_data;

    srv_um_notify_refresh_evt_struct *evt = (srv_um_notify_refresh_evt_struct*) param;

    VFX_LOG(VFX_FUNC, VAPP_SHELL_MV_ONUMSRVREFRESHNOTIFY, evt->msg_type, m_activeViewer->getPanelState());

    if (evt->msg_type == SRV_UM_MSG_SMS && (evt->msg_box_type & SRV_UM_MSG_BOX_INBOX))
    {
        if (m_activeViewer->getPanelState() != APP_SHELL_ENTER_VIEW)
        {
            m_activeViewer->m_msgList->release(VFX_TRUE);
        }
        else
        {
            // refresh message list , and update main screen and list screen
            // after updated message list.
            if (evt->refresh_type != SRV_UM_REFRESH_MSG_STATUS_CHANGED)
            {
                m_activeViewer->m_msgList->update();
            }
            // do not refresh the message list, but we need to refresh
            // the data in list screen
            else
            {
                m_activeViewer->m_listScreen->checkUpdate();
            }
        }
    }
    return MMI_RET_OK;
}


void VappShellMsgViewer::onTimeChanged(VfxU32 flag)
{
    if (flag & VDAT_SYSTIME_CHANGED_DAY)
    {
        if (getPanelState() != APP_SHELL_ENTER_VIEW)
        {
            m_msgList->release(VFX_TRUE);
        }
        else
        {
            if (m_mainScreen && m_listScreen)
            {
                m_mainScreen->checkUpdate();
                m_listScreen->checkUpdate();
            }
        }
    }
}

#endif /* __MMI_VUI_SHELL_MSG_VIEWER__ */
