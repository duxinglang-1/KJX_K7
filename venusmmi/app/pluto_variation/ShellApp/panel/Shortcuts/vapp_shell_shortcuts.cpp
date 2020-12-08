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
 *  vapp_shell_shortcuts.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  shell application
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

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_VUI_SHELL_SHORTCUTS__
#include "vapp_shell_shortcuts.h"
#include "trc/vadp_app_trc.h"
#include "vfx_datatype.h"
#include "vfx_system.h"
#include "vapp_shell_panel.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_primitive_frame.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vcp_popup.h"
#include "vfx_signal.h"
#include "vfx_string.h"
#include "vfx_image_src.h"
#include "vcp_option_menu.h"
#include "vfx_text_frame.h"
#include "vfx_font_desc.h"
#include "vfx_frame.h"
#include "vfx_animation.h"
#include "vfx_input_event.h"
#include "vcp_image_button.h"
#include "vcp_state_image.h"
#include "vcp_frame_effect.h"
#include "vcp_frame_effect_type.h"
#include "vfx_transform.h"
extern "C"
{
#include "mmi_rp_all_defs.h"
#include "mmi_rp_app_venus_shell_shortcuts_def.h"
#include "mmi_rp_app_shellapp_base_def.h"
#include "ShortcutsGProts.h"
#ifdef __J2ME__
#include "JavaAgencyGProt.h" //for java list display
#endif /* __J2ME__ */
#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
#endif /* __MMI_TOUCH_FEEDBACK_SUPPORT__ */
#include "custom_shell_shortcuts_cfg.h"
#include "CustMenuRes.h"
#include "kal_general_types.h"
#include "string.h"
#include "CustDataRes.h"
#include "Unicodexdcl.h"
#include "ImeGprot.h"
#include "ShortcutsDefs.h"
#include "kal_trace.h"
#include "common_nvram_editor_data_item.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "GlobalResDef.h"
}

const VappShellShctItemInfoStruct vappShellShctCandList[] =
{
    VAPP_SHELL_SHCT_CFG_ITEM_INFO(
        MITEM102_PBOOK_NEW_ENTRY,
        0,
        IMG_ID_SHELL_SHORTCUTS_ITEM_ICON_ADD_CONTACT),

    
    VAPP_SHELL_SHCT_CFG_ITEM_INFO(
        MAIN_MENU_FILE_MNGR_MENUID,
        0,
        IMG_ID_SHELL_SHORTCUTS_ITEM_ICON_FILE_MAN),

    
    VAPP_SHELL_SHCT_CFG_ITEM_INFO(
        MENU_ID_UM_WRITE_MSG,
        MAIN_MENU_MESSAGES_MENUID,
        IMG_ID_SHELL_SHORTCUTS_ITEM_ICON_NEW_MSG),

#ifdef __MMI_CALENDAR__
    VAPP_SHELL_SHCT_CFG_ITEM_INFO(
        ORGANIZER_CALENDER_MENU,
        0,
        IMG_ID_SHELL_SHORTCUTS_ITEM_ICON_CALENDAR),
#endif
#ifdef __MMI_TODOLIST__
    VAPP_SHELL_SHCT_CFG_ITEM_INFO(
        ORGANIZER_TODOLIST_MENU,
        0,
        IMG_ID_SHELL_SHORTCUTS_ITEM_ICON_TASKS_LIST),
#endif
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    VAPP_SHELL_SHCT_CFG_ITEM_INFO(
        ORGANIZER_ALARM_MENU,
        0,
        IMG_ID_SHELL_SHORTCUTS_ITEM_ICON_ALARM),

#ifdef __MMI_CALCULATOR__
    VAPP_SHELL_SHCT_CFG_ITEM_INFO(
        EXTRA_CALCULATOR_MENU,
        0,
        IMG_ID_SHELL_SHORTCUTS_ITEM_ICON_CALCULATOR),
#endif
#if 0
#ifdef __MMI_MMS_2__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
    VAPP_SHELL_SHCT_CFG_ITEM_INFO(
        MAIN_MENU_SETTINGS_MENUID,
        0,
        IMG_ID_SHELL_SHORTCUTS_ITEM_ICON_SETTINGS),

#ifdef __MMI_WORLD_CLOCK__
    VAPP_SHELL_SHCT_CFG_ITEM_INFO(
        ORGANIZER_WORLDCLOCK_MENU,
        0,
        IMG_ID_SHELL_SHORTCUTS_ITEM_ICON_WORLD_CLOCK),
#endif
#ifdef __MMI_EMAIL__
    VAPP_SHELL_SHCT_CFG_ITEM_INFO(
        MENU_ID_EMAIL_MAIN,
        MAIN_MENU_MESSAGES_MENUID,
        IMG_ID_SHELL_SHORTCUTS_ITEM_ICON_EMAIL),
#endif
#ifdef __MMI_MEDIA_PLAYER__
    VAPP_SHELL_SHCT_CFG_ITEM_INFO(
        MENU_ID_MEDPLY_MAIN,
        MAIN_MENU_MULTIMEDIA_MENUID,
        IMG_ID_SHELL_SHORTCUTS_ITEM_ICON_MEDIA),
#endif

#ifdef __MMI_FM_RADIO__
    VAPP_SHELL_SHCT_CFG_ITEM_INFO(
        MENU_ID_FMRDO_MAIN,
        MAIN_MENU_MULTIMEDIA_MENUID,
        IMG_ID_SHELL_SHORTCUTS_ITEM_ICON_FM_RADIO),
#endif

#ifdef __MMI_CAMCORDER__
    VAPP_SHELL_SHCT_CFG_ITEM_INFO(
        MENU_ID_CAMCORDER_APP,
        MAIN_MENU_MULTIMEDIA_MENUID,
        IMG_ID_SHELL_SHORTCUTS_ITEM_ICON_CAMERA),
#else /* __MMI_CAMCORDER__ */
    #ifdef __MMI_CAMERA__
    VAPP_SHELL_SHCT_CFG_ITEM_INFO(
        MENU_ID_CAMERA_APP,
        MAIN_MENU_MULTIMEDIA_MENUID,
        IMG_ID_SHELL_SHORTCUTS_ITEM_ICON_CAMERA),
    #endif /* __MMI_CAMERA__ */
    #ifdef __MMI_VIDEO_RECORDER__
    VAPP_SHELL_SHCT_CFG_ITEM_INFO(
        MENU_ID_VDOREC_APP,
        MAIN_MENU_MULTIMEDIA_MENUID,
        IMG_ID_SHELL_SHORTCUTS_ITEM_ICON_VIDEO_REC),
    #endif /* __MMI_VIDEO_RECORDER__ */
#endif /* __MMI_CAMCORDER__ */

#ifdef __MMI_EBOOK_READER__
    VAPP_SHELL_SHCT_CFG_ITEM_INFO(
        MAIN_MENU_EBOOK_MENUID,
        0,
        IMG_ID_SHELL_SHORTCUTS_ITEM_ICON_EBOOK),
#endif
#ifdef __MMI_NOTE_APP__
    VAPP_SHELL_SHCT_CFG_ITEM_INFO(
        MENU_ID_NOTE_APP_MAIN,
        0,
        IMG_ID_SHELL_SHORTCUTS_ITEM_ICON_NOTE),
#endif
#ifdef __MMI_BT_SUPPORT__
    VAPP_SHELL_SHCT_CFG_ITEM_INFO(
        MENU_CONN_BT_MAIN,
        0,
        IMG_ID_SHELL_SHORTCUTS_ITEM_ICON_BLUETOOTH),
#endif
#ifdef __MMI_WLAN_FEATURES__
    VAPP_SHELL_SHCT_CFG_ITEM_INFO(
        MAIN_MENU_WLAN_WIZARD_MENUID,
        0,
        IMG_ID_SHELL_SHORTCUTS_ITEM_ICON_WIFI),
#endif
#ifdef __J2ME__
    VAPP_SHELL_SHCT_CFG_ITEM_INFO(
        MENU_ID_SHELL_SHORTCUTS_JAVA_APPS,
        0,
        IMG_ID_SHELL_SHORTCUTS_ITEM_ICON_JAVA_APP),
#endif /* __J2ME__ */

#if defined(BROWSER_SUPPORT) && defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__)
    VAPP_SHELL_SHCT_CFG_ITEM_INFO(
        MENU_ID_SHELL_SHORTCUTS_BOOKMARKS,
        0,
        IMG_ID_SHELL_SHORTCUTS_ITEM_ICON_BOOKMARK),
#endif /* __MMI_BRW_BKM_INTERFACE_SUPPORT__ */

    VAPP_SHELL_SHCT_CFG_ITEM_INFO_END
};

const VfxU8 VAPP_SHELL_SHCT_CAND_LIST_NUM =
    sizeof(vappShellShctCandList)/sizeof(vappShellShctCandList[0]) - 1;

VappShellShctScr *gVappShellShctScrObj;
/***************************************************************************** 
 * VappShellShctScr
 *****************************************************************************/
VappShellShctScr::VappShellShctScr() :
    m_itemNvramInfo(NULL),
    m_shctItemSel(NULL),
    m_operationState(OPERATION_STATE_IDLE),
    m_candidateList(NULL),
    m_editCnfScr(NULL),
    m_menuItems(NULL),
    m_appCount(0),
    m_parentCount(0)
{
    for (VfxU8 i = 0; i < VAPP_SHELL_SHCT_MAX_ITEM; i++)
    {
        m_shctItem[i] = NULL;
    }
}


void VappShellShctScr::onInit()
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_SHCT_ONINIT);
    VappShellPanel::onInit();
    gVappShellShctScrObj = this;

    VFX_ALLOC_MEM(m_itemNvramInfo, sizeof(nvram_ef_shell_shortcuts_item_struct) * VAPP_SHELL_SHCT_MAX_ITEM, this);
    VfxS16 error;
    VfxBool isEmptyRecord = VFX_TRUE;
    VfxU8 i, j;
    for (i = 0; i < VAPP_SHELL_SHCT_MAX_ITEM; i++)
    {
        ReadRecord(NVRAM_EF_SHELL_SHORTCUTS_LID, (i + 1), &m_itemNvramInfo[i], NVRAM_EF_SHELL_SHORTCUTS_SIZE, &error);
        if (m_itemNvramInfo[i].item_id > 0)
        {
            isEmptyRecord = VFX_FALSE;
        }
    }
    if (isEmptyRecord == VFX_TRUE)
    {
        VFX_LOG(VFX_INFO, VAPP_SHELL_SHCT_EMPTY_RECORD);
        mmi_shct_del_system_maping_files();
    }

    // create the fixed candidate list from the config table
    VFX_ALLOC_MEM(m_appMenuList, sizeof(VfxId)*VAPP_SHELL_SHCT_CAND_LIST_NUM, this);
    VFX_ALLOC_MEM(m_parentMenuList, sizeof(VfxId)*VAPP_SHELL_SHCT_CAND_LIST_NUM, this);

    for (i = 0, j = 0; i < VAPP_SHELL_SHCT_CAND_LIST_NUM; i++)
    {
        if (vappShellShctCandList[i].parentMenuId != 0)
        {
            for (j = 0; j < m_parentCount; j++)
            {
                if (m_parentMenuList[j] == vappShellShctCandList[i].parentMenuId)
                {
                    break;
                }
            }
            if (j == m_parentCount)
            {
                m_appMenuList[m_appCount++] = vappShellShctCandList[i].parentMenuId;
                m_parentMenuList[m_parentCount++] = vappShellShctCandList[i].parentMenuId;
            }
        }
        else
        {
            m_appMenuList[m_appCount++] = vappShellShctCandList[i].menuId;
        }
    }
    m_maxOptionMenuItem = VAPP_SHELL_SHCT_CAND_LIST_NUM + m_parentCount;

    // create submenu lists
    VFX_ALLOC_MEM(m_subMenuList, sizeof(ShctCandSubMenuStruct)*m_parentCount, this);
    for (i = 0; i < m_parentCount; i++)
    {
        m_subMenuList[i].parentMenu = m_parentMenuList[i];
        m_subMenuList[i].count = getSubMenuItemCount(m_parentMenuList[i]);
        VFX_ALLOC_MEM(m_subMenuList[i].subMenuList, sizeof(VfxId)*m_subMenuList[i].count, this);
        getSubMenuItemList(m_parentMenuList[i], m_subMenuList[i].subMenuList);
    }
}


void VappShellShctScr::onDeinit()
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_SHCT_ONDEINIT);

    VFX_FREE_MEM(m_itemNvramInfo);

    // free the candidate list memory
    VFX_FREE_MEM(m_appMenuList);
    VFX_FREE_MEM(m_parentMenuList);
    VFX_FREE_MEM(m_menuItems);
    for (VfxU8 i(0); i < m_parentCount; i++)
    {
        VFX_FREE_MEM(m_subMenuList[i].subMenuList);
    }
    VFX_FREE_MEM(m_subMenuList);
    
    VappShellPanel::onDeinit();
}


void VappShellShctScr::onInitView()
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_SHCT_ONINITVIEW);
    VappShellPanel::onInitView();

    if (m_itemNvramInfo != NULL)
    {
        VFX_OBJ_CREATE(m_imgBg, VfxImageFrame, this);
        m_imgBg->setResId(VAPP_SHELL_IMG_SWITCH_BG);
        m_imgBg->setBgColor(VFX_COLOR_BLACK);
        m_imgBg->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
        configItemDisplay();
    }

    for (VfxU8 i = 0; i < VAPP_SHELL_SHCT_MAX_ITEM; i++)
    {
        if (m_shctItem[i] == NULL)
        {
            VFX_OBJ_CREATE_EX(m_shctItem[i], VappShellShctItem, this, (&m_itemNvramInfo[i], i));
            displayItem(i);
        }
    }
    VFX_FREE_MEM(m_itemNvramInfo);
}


void VappShellShctScr::onDeinitView()
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_SHCT_ONDEINITVIEW);
    for (VfxU8 i = 0; i < VAPP_SHELL_SHCT_MAX_ITEM; i++)
    {
        VFX_OBJ_CLOSE(m_shctItem[i]);
    }
    VFX_OBJ_CLOSE(m_imgBg);

    VappShellPanel::onDeinitView();
}


void VappShellShctScr::onEnterView()
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_SHCT_ONENTERVIEW, m_operationState);
    VappShellPanel::onEnterView();
    configItemDisplay(); // change the text height if language changed
    updateAllItemIcons();
    updateAllItemTexts();
}


void VappShellShctScr::onExitView(ShellExitCauseEnum cause)
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_SHCT_ONEXITVIEW);
    if (m_candidateList != NULL)
    {
        //m_candidateList->closeMenu(VFX_FALSE);
        m_candidateList = NULL;
    }
    if (m_editCnfScr != NULL)
    {
		// auto removed by mvc if switch to pluto screen
        //VFX_OBJ_CLOSE(m_editCnfScr);
		m_editCnfScr = NULL;
    }
    m_operationState = OPERATION_STATE_IDLE;
    VappShellPanel::onExitView(cause);
}


void VappShellShctScr::displayItemEditCnfScr()
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_SHCT_DISPLAY_POPUP_CONFIRM);
    VFX_OBJ_CREATE(m_editCnfScr, VcpCommandPopup, findScreen());
    m_editCnfScr->m_signalButtonClicked.connect(this, &VappShellShctScr::onItemEditCnfScrSel);

    m_editCnfScr->setText(VFX_WSTR_NULL);
    m_editCnfScr->setImage(VFX_IMAGE_SRC_NULL);
    m_editCnfScr->setAutoDestory(VFX_TRUE);

    m_editCnfScr->addItem(
        BUTTON_REMOVE_SHORTCUT,
        VFX_WSTR_RES(STR_ID_SHELL_SHORTCUTS_REMOVE_SHORTCUT),
        VCP_POPUP_BUTTON_TYPE_NORMAL);

    m_editCnfScr->addItem(
        BUTTON_REPLACE_SHORTCUT,
        VFX_WSTR_RES(STR_ID_SHELL_SHORTCUTS_REPLACE_SHORTCUT),
        VCP_POPUP_BUTTON_TYPE_NORMAL);

    m_editCnfScr->addItem(
        BUTTON_CANCEL,
        VFX_WSTR_RES(STR_GLOBAL_CANCEL),
        VCP_POPUP_BUTTON_TYPE_CANCEL);

    m_editCnfScr->show(VFX_TRUE);
}


void VappShellShctScr::displayCandidateList()
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_SHCT_DISPLAY_CANDIDATE_LIST);
    VFX_OBJ_CREATE(m_candidateList, VcpOptionMenu, findScreen());

    m_candidateList->m_signalMenuCallback.connect(this, &VappShellShctScr::onCandidateListSel);

    m_candidateList->setTitle(VFX_WSTR_NULL);
    m_candidateList->setIsAutoClose(VFX_TRUE);
    m_candidateList->setIsAutoCancel(VFX_TRUE);

    // alloc all the option menu items' pointers
    VFX_ALLOC_MEM(m_menuItems, sizeof(VcpOptionMenuItem*) * m_maxOptionMenuItem, this);

    // create first level
#ifndef MT6253
    // to adjust the performance
    candListSorting(m_appMenuList, m_appCount);
#endif /* MT6253 */
    VfxU8 i, j;
    for (i = 0; i < m_appCount; i++)
    {
        m_menuItems[i] = m_candidateList->createMenuItem(
                            m_appMenuList[i],
                            VFX_WSTR_RES(GetStringIdOfItem(m_appMenuList[i])));
        m_candidateList->appendItem(NULL, m_menuItems[i]);
    }

    // create each sub level
    VfxU8 currCreatedItemNum(0);
    currCreatedItemNum = m_appCount;
    for (i = 0; i < m_parentCount; i++)
    {
        VcpOptionMenuItem *parentOptionMenuItem = getOptionMenuItem(m_parentMenuList[i]);

    #ifndef MT6253
        // to adjust the performance
        candListSorting(m_subMenuList[i].subMenuList, m_subMenuList[i].count);
    #endif /* MT6253 */
        for (j = 0; j < m_subMenuList[i].count; j++)
        {
            m_menuItems[currCreatedItemNum] = m_candidateList->createMenuItem(
                                                m_subMenuList[i].subMenuList[j],
                                                VFX_WSTR_RES(GetStringIdOfItem(m_subMenuList[i].subMenuList[j])));
            m_candidateList->appendItem(parentOptionMenuItem, m_menuItems[currCreatedItemNum]);
            currCreatedItemNum++;
        }
    }
#ifdef __BT_AUTO_DETECT_SUPPORT__
    for (i = 0; i < m_maxOptionMenuItem; i++)
    {
        if (VFX_TRUE == mmi_shct_check_dynamic_unreg_menu(m_menuItems[i]->getId()))
        {
            m_candidateList->removeItem(m_menuItems[i]);
        }
    }
#endif /* __BT_AUTO_DETECT_SUPPORT__ */
    m_candidateList->showMenu();
}


void VappShellShctScr::candListSorting(VfxId *menuIdList, const VfxU8 itemNum)
{
#if defined(__MMI_ZI__) || defined(__MMI_CSTAR__) || defined(__MMI_T9__)
    // chinese pinin sort
    struct ItemPinyinInfo
    {
        VfxId menuId;
        WCHAR *itemPinyinPtr;
    };
    ItemPinyinInfo *itemPinyinList;
    VFX_ALLOC_MEM(itemPinyinList, sizeof(ItemPinyinInfo) * itemNum, this);
    WCHAR itemPinyin[8];
    VfxU8 i, j;
    WCHAR* str;
    VfxU8 strLen;
    for (i = 0; i < itemNum; i++)
    {
        itemPinyinList[i].menuId = menuIdList[i];
        VFX_ALLOC_MEM(itemPinyinList[i].itemPinyinPtr, 64, this);
        memset(itemPinyinList[i].itemPinyinPtr, 0x00, 64);
    }

    for (i = 0; i < itemNum; i++)
    {
        str = (WCHAR*)GetString(GetStringIdOfItem(menuIdList[i]));
        strLen = mmi_wcslen(str);
        for (j = 0; j < strLen; j++)
        {
            memset(itemPinyin, 0x00, 8);
            // chinese word
            if ((str[j] >= 0x4E00) && (str[j] <= 0x9FA5))
            {
                mmi_imc_get_char_info(
                    str[j],
                    itemPinyin,
                    8,
                    IMM_INPUT_MODE_QUICK_SEARCH_PINYIN);
            }
            else
            {
                itemPinyin[0] = str[j];
            }
            mmi_wcscat(itemPinyinList[i].itemPinyinPtr, itemPinyin);
        }
    }

    ItemPinyinInfo tempPinyinInfo;
    for (i = 0; i < itemNum; i++)
    {
        for (j = i + 1; j < itemNum; j++)
        {
            if (mmi_wcscmp((WCHAR*)itemPinyinList[i].itemPinyinPtr, (WCHAR*)itemPinyinList[j].itemPinyinPtr) > 0)
            {
                tempPinyinInfo = itemPinyinList[i];
                itemPinyinList[i] = itemPinyinList[j];
                itemPinyinList[j] = tempPinyinInfo;
            }
        }
    }

    for (i = 0; i < itemNum; i++)
    {
        menuIdList[i] = itemPinyinList[i].menuId;
        if (itemPinyinList[i].itemPinyinPtr != NULL)
        {
            VFX_FREE_MEM(itemPinyinList[i].itemPinyinPtr);
        }
    }
    
    if (itemPinyinList != NULL)
    {
        VFX_FREE_MEM(itemPinyinList);
    }
#else
    VfxId tempMenuId;
    VfxU8 i, j;
    for (i = 0; i < itemNum; i++)
    {
        for (j = i + 1; j < itemNum; j++)
        {
            if (mmi_wcscmp((WCHAR*)GetString(GetStringIdOfItem(menuIdList[i])), (WCHAR*)GetString(GetStringIdOfItem(menuIdList[j]))) > 0)
            {
                tempMenuId = menuIdList[i];
                menuIdList[i] = menuIdList[j];
                menuIdList[j] = tempMenuId;
            }
        }
    }
#endif
}


VfxU8 VappShellShctScr::getSubMenuItemCount(VfxId parentMenuId)
{
    VfxU8 i;
    VfxU8 count(0);
    for (i = 0; i < VAPP_SHELL_SHCT_CAND_LIST_NUM; i++)
    {
        if (parentMenuId == vappShellShctCandList[i].parentMenuId)
        {
            count++;
        }
    }
    return count;
}


VcpOptionMenuItem* VappShellShctScr::getOptionMenuItem(VfxId menuId)
{
    for (VfxS32 i = 0; i < m_maxOptionMenuItem; i++)
    {
        if (m_menuItems[i]->getId() == menuId)
        {
            return m_menuItems[i];
        }
    }
    return NULL;
}


void VappShellShctScr::getSubMenuItemList(const VfxId parentMenuId, VfxId *subMenuIdList)
{
    VfxU8 count(0);
    for (VfxU8 i = 0; i < VAPP_SHELL_SHCT_CAND_LIST_NUM; i++)
    {
        if (vappShellShctCandList[i].parentMenuId == parentMenuId)
        {
            subMenuIdList[count++] = vappShellShctCandList[i].menuId;
        }
    }
}


void VappShellShctScr::setOperationState(ShctOperationStateEnum operationState)
{
    m_operationState = operationState;
}


ShctOperationStateEnum VappShellShctScr::getOperationState()
{
    return m_operationState;
}


void VappShellShctScr::setSelItem(VappShellShctItem *shctItem)
{
    m_shctItemSel = shctItem;
}


void VappShellShctScr::onItemEditCnfScrSel(VfxObject* sender, VfxId id)
{
    if ((VcpCommandPopup*)sender == m_editCnfScr)
    {
        switch (id)
        {
            case BUTTON_REMOVE_SHORTCUT:
                m_operationState = OPERATION_STATE_REMOVE;
                m_shctItemSel->setItemChangedState(VFX_TRUE);
                m_shctItemSel->removeShctItem();
                break;
    
            case BUTTON_REPLACE_SHORTCUT:
                m_operationState = OPERATION_STATE_REPLACE;
                displayCandidateList();
                break;

            case BUTTON_CANCEL:
                break;

            default:
                break;
        }
        m_editCnfScr = NULL;
    }
}


void VappShellShctScr::onCandidateListSel(VcpOptionMenu *sender, VcpOptionMenu::VcpOptionMenuEventEnum evt, VcpOptionMenuItem *item)
{
    if (sender == m_candidateList)
    {
        if (evt == VcpOptionMenu::VCP_OPTION_MENU_EVENT_ITEM_SELECTED)
        {
        #ifdef __J2ME__
            if (item->getId() == MENU_ID_SHELL_SHORTCUTS_JAVA_APPS)
            {
                VFX_LOG(VFX_FUNC, VAPP_SHELL_SHCT_ENTRY_JAVA_SEL);
                mmi_shct_entry_java_sel();
                return;
            }
        #endif /* __J2ME__ */

        #if defined(BROWSER_SUPPORT) && defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__)
            if (item->getId() == MENU_ID_SHELL_SHORTCUTS_BOOKMARKS)
            {
                mmi_shct_entry_brw_bkm_sel();
                return;
            }
        #endif /* __MMI_BRW_BKM_INTERFACE_SUPPORT__ */

            VFX_LOG(VFX_INFO, VAPP_SHELL_SHCT_CANDIDATE_SEL, m_operationState);
            m_shctItemSel->setItemChangedState(VFX_TRUE);
            switch (m_operationState)
            {
                case OPERATION_STATE_ADD:
                    m_shctItemSel->addShctItem(MMI_SHCT_ITEM_TYPE_MENU, item->getId());
                    break;

                case OPERATION_STATE_REPLACE:
                    m_shctItemSel->replaceShctItem(MMI_SHCT_ITEM_TYPE_MENU, item->getId());
                    break;

                case OPERATION_STATE_REMOVE:
                    m_shctItemSel->removeShctItem();
                    break;

                default:
                    break;
            }
        }
        else if (evt == VcpOptionMenu::VCP_OPTION_MENU_EVENT_MENU_CLOSE)
        {
            VFX_LOG(VFX_FUNC, VAPP_SHELL_SHCT_CLOSE_CANDIDATE_LIST);
            VFX_FREE_MEM(m_menuItems);
            m_candidateList = NULL;
            setOperationState(OPERATION_STATE_IDLE);
        }
    }
}


VfxS32 VappShellShctScr::getPanelStrId()
{
    return STR_ID_SHELL_SHORTCUTS_TITLE;
}


void VappShellShctScr::removeShctItem(mmi_shct_item_type_enum itemType, VfxId itemId)
{
    VFX_LOG(VFX_INFO, VAPP_SHELL_SHCT_REMOVE_ITEMS, itemType, itemId);
    if (itemId == 0)
    {
        return;
    }
    
    for (VfxS32 i = 0; i < VAPP_SHELL_SHCT_MAX_ITEM; i++)
    {
        if (m_shctItem[i]->getItemId() == itemId && m_shctItem[i]->getItemType() == itemType)
        {
            m_shctItem[i]->removeShctItem();
        }
    }
}


void VappShellShctScr::configItemDisplay()
{
    VFX_LOG(VFX_INFO, VAPP_SHELL_SHCT_SCRN_CFG_INFO);
    //error handling for could not include the num of item
    VfxS32 maxNumH = VAPP_SHELL_SHCT_MAX_HORIZONTAL_ITEM;
    VfxS32 maxNumV = VAPP_SHELL_SHCT_MAX_VERTICAL_ITEM;
    VFX_LOG(VFX_INFO2, VAPP_SHELL_SHCT_MAX_ITEM_NUM, maxNumH, maxNumV);
    
    VfxRect scrBounds = VappShellPanel::getAppBounds();
    VfxSize iconSize = getIconSize();
    VFX_LOG(VFX_INFO2, VAPP_SHELL_SHCT_SCRN_INFO, scrBounds.origin.x, scrBounds.origin.y, scrBounds.size.width, scrBounds.size.height);

    // use float type to calculate the exact value
    VfxFloat iconDistanceX, iconDistanceY, itemDistanceX, itemDistanceY;
    iconDistanceX = (VfxFloat)((scrBounds.getWidth() - scrBounds.origin.x - iconSize.width * maxNumH) / maxNumH);
    iconDistanceY = (VfxFloat)((scrBounds.getHeight() - scrBounds.origin.y - iconSize.height * maxNumV) / maxNumV);
    itemDistanceX = iconDistanceX/3;
    itemDistanceY = 0;
    VFX_LOG(VFX_INFO2, VAPP_SHELL_SHCT_DISTANCE_INFO, (VfxS32)iconDistanceX, (VfxS32)iconDistanceY, (VfxS32)itemDistanceX, (VfxS32)itemDistanceY);

    VfxPoint point = VfxPoint((VfxS32)(iconDistanceX / 3) + iconSize.width / 2, iconSize.height / 2);
    setIconPos(point);
    VFX_LOG(VFX_INFO2, VAPP_SHELL_SHCT_ICON_INFO, point.x, point.y, iconSize.width, iconSize.height);

    VfxPoint textBgImgPos;
    VfxSize textBgImgSize;
    VfxSize fontSize;
    VfxTextFrame *textTemp;
    VFX_OBJ_CREATE(textTemp, VfxTextFrame, this);
    textTemp->setString(VFX_WSTR_RES(STR_GLOBAL_OK));
    textTemp->setFullLineHeightMode(VFX_TRUE);
    textTemp->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_SHELL_SHCT_ITEM_TEXT_FONT_SIZE), VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));
    fontSize = textTemp->getSize();
    VFX_OBJ_CLOSE(textTemp);
 
    VFX_LOG(VFX_INFO2, VAPP_SHELL_SHCT_TEXT_FONT_INFO, fontSize.width, fontSize.height);

    textBgImgSize.width = (VfxS32)(iconSize.width + iconDistanceX * 2 / 3);
    textBgImgSize.height = fontSize.height + VAPP_SHELL_SHCT_TEXT_BG_IMG_BORDER_HEIGHT * 2;
    textBgImgPos.x = (VfxS32)(iconSize.width / 2 + iconDistanceX / 3); // half of textBgImgSize.width
    textBgImgPos.y = iconSize.height + textBgImgSize.height / 2 + VAPP_SHELL_SHCT_ITEM_TEXT_ICON_DISTANCE;
    setTextBgImgPos(textBgImgPos);
    setTextBgImgSize(textBgImgSize);
    VFX_LOG(VFX_INFO2, VAPP_SHELL_SHCT_TEXT_BG_INFO, textBgImgPos.x, textBgImgPos.y, textBgImgSize.width, textBgImgSize.height);

    VfxPoint textPos;
    VfxSize textSize;
    textSize.width = textBgImgSize.width - VAPP_SHELL_SHCT_TEXT_BG_IMG_BORDER_WIDTH * 2;
    textSize.height = fontSize.height;
    textPos = textBgImgPos;
    setTextPos(textPos);
    setTextSize(textSize);
    VFX_LOG(VFX_INFO2, VAPP_SHELL_SHCT_TEXT_INFO, textPos.x, textPos.y, textSize.width, textSize.height);
}


void VappShellShctScr::displayItem(VfxU8 index)
{
    //error handling for could not include the num of item
    VfxS32 indexH, indexV;
    VfxS32 maxNumH = VAPP_SHELL_SHCT_MAX_HORIZONTAL_ITEM;
    VfxS32 maxNumV = VAPP_SHELL_SHCT_MAX_VERTICAL_ITEM;
    indexH = index % maxNumH;
    indexV = index / maxNumH;
    
    VfxRect scrBounds = VappShellPanel::getAppBounds();
    VfxSize iconSize = getIconSize();

    VfxFloat iconDistanceX, iconDistanceY, itemDistanceX, itemDistanceY;
    iconDistanceX = (VfxFloat)((scrBounds.getWidth() - scrBounds.origin.x - iconSize.width * maxNumH) / maxNumH);
    iconDistanceY = (VfxFloat)((scrBounds.getHeight() - scrBounds.origin.y - iconSize.height * maxNumV) / maxNumV);
    itemDistanceX = iconDistanceX/3;
    itemDistanceY = 0;

    VfxPoint itemPos;
    VfxSize itemSize;
    itemSize.width = getTextBgImgSize().width;
    itemSize.height = iconSize.height + getTextBgImgSize().height + VAPP_SHELL_SHCT_ITEM_TEXT_ICON_DISTANCE;
    itemPos.x = (VfxS32)(scrBounds.origin.x + itemDistanceX / 2 + indexH * (getTextBgImgSize().width + itemDistanceX));
    itemPos.y = (VfxS32)(scrBounds.origin.y + iconDistanceY / 2 + indexV * (iconSize.height + iconDistanceY));
    m_shctItem[index]->setPos(itemPos);
    m_shctItem[index]->setBounds(0, 0, itemSize.width, itemSize.height);
}


void VappShellShctScr::updateAllItemIcons()
{
    for (VfxU8 i = 0; i < VAPP_SHELL_SHCT_MAX_ITEM; i++)
    {
        m_shctItem[i]->updateItemIcon();
    }
}


void VappShellShctScr::updateAllItemTexts()
{
    for (VfxU8 i = 0; i < VAPP_SHELL_SHCT_MAX_ITEM; i++)
    {
        m_shctItem[i]->updateItemText();
    }
}


void VappShellShctScr::setIconPos( VfxPoint &iconPos)
{
    m_iconPos = iconPos;
}


VfxPoint VappShellShctScr::getIconPos()
{
    return m_iconPos;
}


VfxSize VappShellShctScr::getIconSize()
{
    return VfxImageSrc(IMG_ID_SHELL_SHORTCUTS_ITEM_ICON_EMPTY).getSize();
}


void VappShellShctScr::setTextPos( VfxPoint &textPos)
{
    m_textPos = textPos;
}


VfxPoint VappShellShctScr::getTextPos()
{
    return m_textPos;
}


void VappShellShctScr::setTextSize(VfxSize &textSize)
{
    m_textSize = textSize;
}


VfxSize VappShellShctScr::getTextSize()
{
    return m_textSize;
}


void VappShellShctScr::setTextBgImgPos( VfxPoint &textBgImgPos)
{
    m_textBgImgPos = textBgImgPos;
}


VfxPoint VappShellShctScr::getTextBgImgPos()
{
    return m_textBgImgPos;
}


void VappShellShctScr::setTextBgImgSize(VfxSize &textBgImgSize)
{
    m_textBgImgSize = textBgImgSize;
}


VfxSize VappShellShctScr::getTextBgImgSize()
{
    return m_textBgImgSize;
}


void VappShellShctScr::onJavaListSel(VfxId itemId)
{
    m_shctItemSel->setItemChangedState(VFX_TRUE);
    m_shctItemSel->addShctItem(MMI_SHCT_ITEM_TYPE_JAVA, itemId);
}


void VappShellShctScr::onBrwBkmListSel(VfxId itemId)
{
    m_shctItemSel->setItemChangedState(VFX_TRUE);
    /* should remove the original bookmark, shortcuts only store a bookmark copy */
    /* that means even the user delete the bookmark in browser, shortcuts still have the copy */
    /* as both add and replace will run in this function, when it will replace the bookmark, it should remove it from the maping file */
    m_shctItemSel->replaceShctItem(MMI_SHCT_ITEM_TYPE_BRW_BOOKMARK, itemId);
}


VfxBool VappShellShctScr::checkIsDuplicated(VfxId itemId, mmi_shct_item_type_enum itemType)
{
    VfxS32 j = 0;
    for (VfxS32 i = 0; i < VAPP_SHELL_SHCT_MAX_ITEM; i++)
    {
        if (itemId == m_shctItem[i]->getItemId() && itemType == m_shctItem[i]->getItemType())
        {
            j++;
        }
    }

    VFX_LOG(VFX_INFO, VAPP_SHELL_SHCT_CHECK_DUPLACATE_NUM, j);

    if (j > 1)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


/***************************************************************************** 
 * VappShellShctItem
 *****************************************************************************/
VappShellShctItem::VappShellShctItem(nvram_ef_shell_shortcuts_item_struct *itemInfo, VfxS32 index) :
    m_itemId(itemInfo->item_id),
    m_itemType((mmi_shct_item_type_enum)itemInfo->item_type),
    m_index(index),
    m_isChanged(VFX_FALSE)
{
}


void VappShellShctItem::onInit()
{
    VfxFrame::onInit();
    
    VFX_OBJ_CREATE(m_itemIcon, VappShellShctItemIcon, this);
    VFX_OBJ_CREATE(m_itemTextBg, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_itemText, VfxTextFrame, this);

    m_itemIcon->m_signalHold.connect(this, &VappShellShctItem::onShctItemHold);
    m_itemIcon->setIcon(getItemIconId());
    m_itemIcon->setPos(gVappShellShctScrObj->getIconPos());
    m_itemIcon->setBounds(VfxRect(VfxPoint(0, 0), gVappShellShctScrObj->getIconSize()));
    m_itemIcon->setAnchor(VfxFPoint(0.5f, 0.5f));

    m_itemText->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_SHELL_SHCT_ITEM_TEXT_FONT_SIZE), VFX_FONT_DESC_ATTR_NORMAL, VFX_FONT_DESC_EFFECT_NONE));
    VfxWString itemString;
    itemString = getItemString();
    if (itemString.isNull() == VFX_TRUE)
    {
        removeShctItem();
    }
    else
    {
        m_itemText->setString(itemString);
    }
    m_itemText->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_itemText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_itemText->setPos(gVappShellShctScrObj->getTextPos());
    m_itemText->setBounds(VfxRect(VfxPoint(0, 0), gVappShellShctScrObj->getTextSize()));
    //m_itemText->setBounds(m_itemText->getMeasureBounds());
    m_itemText->setAnchor(VfxFPoint(0.5f, 0.5f));
    m_itemText->setFullLineHeightMode(VFX_TRUE);
    //m_itemText->setAutoResized(VFX_TRUE);

    setItemTextBg();
    m_itemTextBg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_itemTextBg->setPos(gVappShellShctScrObj->getTextBgImgPos());
    m_itemTextBg->setAnchor(VfxFPoint(0.5f, 0.5f));
}


void VappShellShctItem::onDeinit()
{
    VfxFrame::onDeinit();
}


void VappShellShctItem::addShctItem(mmi_shct_item_type_enum itemType, VfxId itemId)
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_SHCT_ADD_SHCT_ITEM, m_itemType, itemType, m_itemId, itemId, m_index);
    if (itemId == m_itemId)
    {
        setItemChangedState(VFX_FALSE);
        return;
    }
    //gVappShellShctScrObj->removeShctItem(appMenuId);
    m_itemId = itemId;
    m_itemType = itemType;
    m_itemIcon->setIcon(getItemIconId());
    m_itemText->setString(getItemString());
    setItemTextBg();
    saveToNvram();
    //gVappShellShctScrObj->setOperationState(OPERATION_STATE_IDLE);
}


void VappShellShctItem::replaceShctItem(mmi_shct_item_type_enum itemType, VfxId itemId)
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_SHCT_REPLACE_SHCT_ITEM, m_itemType, itemType, m_itemId, itemId, m_index);
    if (itemId == m_itemId)
    {
        setItemChangedState(VFX_FALSE);
        return;
    }
    //gVappShellShctScrObj->removeShctItem(appMenuId);
#ifdef __J2ME__
    if (m_itemType == MMI_SHCT_ITEM_TYPE_JAVA)
    {
        if (VFX_FALSE == gVappShellShctScrObj->checkIsDuplicated(m_itemId, m_itemType))
        {
            mmi_shct_del_java_mid_id_in_map_file(m_itemId);
        }
    }
#endif /* __J2ME__ */
#if defined(BROWSER_SUPPORT) && defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__)
    if (m_itemType == MMI_SHCT_ITEM_TYPE_BRW_BOOKMARK)
    {
        mmi_shct_brw_bkm_del_url(m_itemId);
    }
#endif /* __MMI_BRW_BKM_INTERFACE_SUPPORT__ */
    m_itemId = itemId;
    m_itemType = itemType;
    m_itemIcon->setIcon(getItemIconId());
    m_itemText->setString(getItemString());
    setItemTextBg();
    saveToNvram();
    //gVappShellShctScrObj->setOperationState(OPERATION_STATE_IDLE);
}


void VappShellShctItem::removeShctItem()
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_SHCT_REMOVE_SHCT_ITEM, m_itemType, m_itemId, m_index);
#ifdef __J2ME__
    if (m_itemType == MMI_SHCT_ITEM_TYPE_JAVA)
    {
        if (VFX_FALSE == gVappShellShctScrObj->checkIsDuplicated(m_itemId, m_itemType))
        {
            mmi_shct_del_java_mid_id_in_map_file(m_itemId);
        }
    }
#endif /* __J2ME__ */
#if defined(BROWSER_SUPPORT) && defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__)
        if (m_itemType == MMI_SHCT_ITEM_TYPE_BRW_BOOKMARK)
        {
            mmi_shct_brw_bkm_del_url(m_itemId);
        }
#endif /* __MMI_BRW_BKM_INTERFACE_SUPPORT__ */

    m_itemId = 0;
    m_itemType = MMI_SHCT_ITEM_TYPE_NONE;
    m_itemIcon->setIcon(IMG_ID_SHELL_SHORTCUTS_ITEM_ICON_EMPTY);
    m_itemText->setString(VFX_WSTR_NULL);
    setItemTextBg();
    saveToNvram();
    //gVappShellShctScrObj->setOperationState(OPERATION_STATE_IDLE);
}


void VappShellShctItem::onShctItemTap(VfxBaseTimeline *timeLine, VfxBool isFinished)
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_SHCT_ON_TAP, m_itemType, m_itemId, m_index);
    if (isFinished == VFX_TRUE)
    {
        if (m_itemType == MMI_SHCT_ITEM_TYPE_NONE)
        {
            gVappShellShctScrObj->setOperationState(OPERATION_STATE_ADD);
            gVappShellShctScrObj->setSelItem(this);
            gVappShellShctScrObj->displayCandidateList();
        }
        else
        {
            launchApp(this->m_itemId);
        }
    }
}


void VappShellShctItem::onShctItemHold(VappShellShctItemIcon* obj, VfxPenEvent &event)
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_SHCT_ON_LONG_PRESS, m_itemType, m_itemId, m_index);
    if (m_itemType != MMI_SHCT_ITEM_TYPE_NONE)
    {
        obj->displayZoomAnimation(VappShellShctItemIcon::LONG_TAP_ZOOM_OUT);
        gVappShellShctScrObj->setSelItem(this);
        gVappShellShctScrObj->displayItemEditCnfScr();
    }
}


void VappShellShctItem::launchApp(VfxId itemId)
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_SHCT_LAUNCH_APP, m_itemType, m_itemId, m_index);
    if (m_itemType == MMI_SHCT_ITEM_TYPE_MENU)
    {
            mmi_shct_launch_app(itemId);
    }
    else if (m_itemType == MMI_SHCT_ITEM_TYPE_JAVA)
    {
    #ifdef __J2ME__
        mmi_shct_java_launch_midlet(itemId);
    #endif
    }
    else if (m_itemType == MMI_SHCT_ITEM_TYPE_BRW_BOOKMARK)
    {
    #if defined(BROWSER_SUPPORT) && defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__)
        mmi_shct_brw_bkm_launch_url(itemId);
    #endif /* __MMI_BRW_BKM_INTERFACE_SUPPORT__ */
    }
}


VfxId VappShellShctItem::getItemId()
{
    return m_itemId;
}


mmi_shct_item_type_enum VappShellShctItem::getItemType()
{
    return m_itemType;
}


VfxId VappShellShctItem::getItemIconId()
{
    if (m_itemType == MMI_SHCT_ITEM_TYPE_JAVA)
    {
        return IMG_ID_SHELL_SHORTCUTS_ITEM_ICON_JAVA_APP;
    }
    else if (m_itemType == MMI_SHCT_ITEM_TYPE_BRW_BOOKMARK)
    {
        return IMG_ID_SHELL_SHORTCUTS_ITEM_ICON_BOOKMARK;
    }

    for (VfxS32 i = 0; i < VAPP_SHELL_SHCT_CAND_LIST_NUM; i++)
    {
        if (m_itemId == vappShellShctCandList[i].menuId)
        {
            return vappShellShctCandList[i].iconId;
        }
    }

    // could not find the menu icon
    if (m_itemType == MMI_SHCT_ITEM_TYPE_MENU)
    {
        removeShctItem();
    }

    return IMG_ID_SHELL_SHORTCUTS_ITEM_ICON_EMPTY;
}


VfxWString VappShellShctItem::getItemString()
{
    if (m_itemType == MMI_SHCT_ITEM_TYPE_NONE)
    {
        return VFX_WSTR_NULL;
    }
    else
    {
        if (m_itemType == MMI_SHCT_ITEM_TYPE_JAVA)
        {
        #ifdef __J2ME__
            VfxWString itemText;
            return itemText.loadFromMem((VfxWChar*)mmi_shct_get_java_midlet_str(m_itemId));
        #endif /* __J2ME__ */
        }
        else if (m_itemType == MMI_SHCT_ITEM_TYPE_BRW_BOOKMARK)
        {
        #if defined(BROWSER_SUPPORT) && defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__)
            VfxWString itemText;
            VfxWChar title[SHCT_BRW_BKM_MAX_DISPLAY_LEN];
            mmi_shct_brw_bkm_get_display_str(m_itemId, title);
            return itemText.loadFromMem(title);
        #endif /* __MMI_BRW_BKM_INTERFACE_SUPPORT__ */
        }
        else if (m_itemType == MMI_SHCT_ITEM_TYPE_MENU)
        {
            VfxWString itemText;
            return itemText.loadFromRes(GetStringIdOfItem(m_itemId));
        }
    }
    return VFX_WSTR_NULL;
}


void VappShellShctItem::setItemTextBg()
{
    if (m_itemType == MMI_SHCT_ITEM_TYPE_NONE)
    {
        m_itemTextBg->setNull();
    }
    else
    {
        m_itemTextBg->setResId(IMG_ID_SHELL_SHORTCUTS_ITEM_TEXT_BG);
        VfxS32 bgWidth = m_itemText->getFont().measureStr(m_itemText->getString()).width > gVappShellShctScrObj->getTextSize().width ? gVappShellShctScrObj->getTextBgImgSize().width : (m_itemText->getFont().measureStr(m_itemText->getString()).width + VAPP_SHELL_SHCT_TEXT_BG_IMG_BORDER_WIDTH * 2);
        m_itemTextBg->setBounds(VfxRect(VfxPoint(0, 0), VfxSize(bgWidth, gVappShellShctScrObj->getTextBgImgSize().height)));
    }
}


void VappShellShctItem::setItemChangedState(VfxBool changeState)
{
    m_isChanged = changeState;
}


VfxBool VappShellShctItem::getItemChangedState()
{
    return m_isChanged;
}


void VappShellShctItem::saveToNvram()
{
    VFX_LOG(VFX_FUNC, VAPP_SHELL_SHCT_SAVE_NVRAM, m_itemType, m_itemId, m_index);
    nvram_ef_shell_shortcuts_item_struct itemNvramInfo;
    VfxS16 error;
    itemNvramInfo.item_id = m_itemId;
    itemNvramInfo.item_type = m_itemType;
    WriteRecord(NVRAM_EF_SHELL_SHORTCUTS_LID, (m_index + 1), &itemNvramInfo, NVRAM_EF_SHELL_SHORTCUTS_SIZE, &error);
}


void VappShellShctItem::updateItemIcon()
{
    m_itemIcon->setIcon(getItemIconId());
}


void VappShellShctItem::updateItemText()
{
    if (m_itemType == MMI_SHCT_ITEM_TYPE_MENU)
    {
        m_itemText->setString(getItemString());
        setItemTextBg();
    }
}


/***************************************************************************** 
 * VappShellShctItemIcon
 *****************************************************************************/
VappShellShctItemIcon::VappShellShctItemIcon() : VcpImageButton()
{
}


void VappShellShctItemIcon::onInit()
{
    VcpImageButton::onInit();
    setIsHighlight(VFX_FALSE);

    VFX_OBJ_CREATE(m_zoomTimeLine, VfxTransformTimeline, this);
    VFX_OBJ_CREATE(m_tapTimeLine, VfxTransformTimeline, this);
}


void VappShellShctItemIcon::onDeinit()
{
    VcpImageButton::onDeinit();
}


void VappShellShctItemIcon::setIcon(VfxId iconId)
{
    if (((VappShellShctItem*)getParentFrame())->getItemChangedState() == VFX_TRUE)
    {
        onIconSwitch(iconId);
        ((VappShellShctItem*)getParentFrame())->setItemChangedState(VFX_FALSE);
    }

    VcpStateImage imgList;
    imgList.setImage(iconId, iconId, iconId, iconId);
    setImage(imgList);
    m_iconId = iconId;
}


void VappShellShctItemIcon::onIconSwitch(VfxId iconId)
{
    setHidden(VFX_TRUE);
    VFX_OBJ_CREATE(m_frameEffect1, VcpFrameEffect, this);
    VFX_OBJ_CREATE(m_frameEffect2, VcpFrameEffect, this);
    VFX_OBJ_CREATE(m_frontIcon, VfxImageFrame, getParent());
    VFX_OBJ_CREATE(m_backIcon, VfxImageFrame, getParent());
    m_frontIcon->setPos(gVappShellShctScrObj->getIconPos());
    m_backIcon->setPos(gVappShellShctScrObj->getIconPos());
    m_frontIcon->setBounds(VfxRect(VfxPoint(0, 0), gVappShellShctScrObj->getIconSize()));
    m_backIcon->setBounds(VfxRect(VfxPoint(0, 0), gVappShellShctScrObj->getIconSize()));
    m_frontIcon->setAnchor(VfxFPoint(0.5f, 0.5f));
    m_backIcon->setAnchor(VfxFPoint(0.5f, 0.5f));
    m_frontIcon->setResId(m_iconId);
    m_frontIcon->setCullingType(VFX_FRAME_CULLING_TYPE_BACK);
    m_backIcon->setCullingType(VFX_FRAME_CULLING_TYPE_BACK);
    m_backIcon->setHidden(VFX_TRUE);
    m_frameEffect1->restore();
    m_frameEffect2->restore();
    m_frameEffect1->applyEffect(
        m_frontIcon,
        VCP_EFFECT_FLIP,
        VAPP_SHELL_SHCT_ICON_SWITCH_TIME,
        VCP_EFFECT_DIRECTION_FROM_RIGHT,
        VFX_TRUE);

    m_backIcon->setResId(iconId);
    m_backIcon->setHidden(VFX_FALSE);
    m_frameEffect2->applyEffect(
        m_backIcon,
        VCP_EFFECT_FLIP,
        VAPP_SHELL_SHCT_ICON_SWITCH_TIME,
        VCP_EFFECT_DIRECTION_FROM_RIGHT,
        VFX_FALSE);

    m_frameEffect2->m_signalFinished.connect(this, &VappShellShctItemIcon::onIconSwitchFinish);
}


void VappShellShctItemIcon::onIconSwitchFinish(VfxFrame *obj, VfxBool isFinish)
{
    m_backIcon = m_frontIcon;
    m_frontIcon = (VfxImageFrame*)obj;
    m_backIcon->setHidden(VFX_TRUE);
    VFX_OBJ_CLOSE(m_frontIcon);
    VFX_OBJ_CLOSE(m_backIcon);
    VFX_OBJ_CLOSE(m_frameEffect1);
    VFX_OBJ_CLOSE(m_frameEffect2);
    setHidden(VFX_FALSE);
}


VfxBool VappShellShctItemIcon::onPenInput(VfxPenEvent &event)
{
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
        {
            VFX_LOG(VFX_INFO, VAPP_SHELL_SHCT_PEN_INPUT_DOWN);
        #ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
        #endif /* __MMI_TOUCH_FEEDBACK_SUPPORT__ */
            m_tapTimeLine->m_signalStopped.connect(getParentFrame(), &VappShellShctItem::onShctItemTap);
            displayZoomAnimation(TAP_ZOOM_IN);
            return VFX_TRUE;
        }

        // handle long press should be in front of the pen event up
        case VFX_PEN_EVENT_TYPE_LONG_TAP:
        {
            VFX_LOG(VFX_INFO, VAPP_SHELL_SHCT_PEN_INPUT_LONG_TAP);
            if (m_pressStatus == ICON_STATUS_PRESSED && ((VappShellShctItem*)getParentFrame())->getItemType() != MMI_SHCT_ITEM_TYPE_NONE)
            {
                m_tapTimeLine->m_signalStopped.disconnect(getParentFrame(), &VappShellShctItem::onShctItemTap);
                m_signalHold.emit(this, event);
            }
            return VFX_TRUE;
        }

        case VFX_PEN_EVENT_TYPE_UP:
        {
            VFX_LOG(VFX_INFO, VAPP_SHELL_SHCT_PEN_INPUT_UP);
            if (m_pressStatus == ICON_STATUS_PRESSED)
            {
                displayZoomAnimation(TAP_ZOOM_OUT);
            }
            return VFX_TRUE;
        }

        case VFX_PEN_EVENT_TYPE_ABORT:
        {
            VFX_LOG(VFX_INFO, VAPP_SHELL_SHCT_PEN_INPUT_ABORT);
            m_tapTimeLine->m_signalStopped.disconnect(getParentFrame(), &VappShellShctItem::onShctItemTap);
            displayZoomAnimation(TAP_ZOOM_OUT);
            return VFX_TRUE;
        }

        case VFX_PEN_EVENT_TYPE_MOVE:
        {
            VFX_LOG(VFX_INFO, VAPP_SHELL_SHCT_PEN_INPUT_MOVE);
            if (m_pressStatus == ICON_STATUS_PRESSED)
            {
                if (gVappShellShctScrObj->hitTest(event.pos) != this)
                {
                    VFX_LOG(VFX_INFO, VAPP_SHELL_SHCT_PEN_INPUT_MOVE_OUT);
                    m_tapTimeLine->m_signalStopped.disconnect(getParentFrame(), &VappShellShctItem::onShctItemTap);
                    displayZoomAnimation(TAP_ZOOM_OUT);
                }
            }
            return VFX_TRUE;
        }

        default:
            break;
    }
    return VcpImageButton::onPenInput(event);
}


void VappShellShctItemIcon::displayZoomAnimation(ShctIconZoomTypeEnum zoomType)
{
    switch (zoomType)
    {
        case TAP_ZOOM_IN:
        {
            VFX_LOG(VFX_INFO, VAPP_SHELL_SHCT_ITEM_TAP_ZOOM_IN);
            VfxTransform trans;
            trans.type = VRT_TRANSFORM_TYPE_AFFINE;
            trans.data.affine.sx = VAPP_SHELL_SHCT_ICON_ZOOM_SCALE;
            trans.data.affine.sy = VAPP_SHELL_SHCT_ICON_ZOOM_SCALE;
            //m_zoomTimeLine->stop();
            //m_tapTimeLine->stop();
            m_zoomTimeLine->setTarget(this);
            m_zoomTimeLine->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
            m_zoomTimeLine->setFromValue(getTransform());
            m_zoomTimeLine->setToValue(trans);
            m_zoomTimeLine->setDurationTime(VAPP_SHELL_SHCT_ICON_ZOOM_TIME);
            setTransform(trans);
            m_zoomTimeLine->start();
            m_pressStatus = ICON_STATUS_PRESSED;
            break;
        }

        case TAP_ZOOM_OUT:
        {
            VFX_LOG(VFX_INFO, VAPP_SHELL_SHCT_ITEM_TAP_ZOOM_OUT);
            VfxTransform trans;
            trans.type = VRT_TRANSFORM_TYPE_AFFINE;
            trans.data.affine.sx = 1.0f;
            trans.data.affine.sy = 1.0f;
            //m_zoomTimeLine->stop();
            m_tapTimeLine->setTarget(this);
            m_tapTimeLine->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
            m_tapTimeLine->setFromValue(getTransform());
            m_tapTimeLine->setToValue(trans);
            m_tapTimeLine->setDurationTime(VAPP_SHELL_SHCT_ICON_ZOOM_TIME);
            setTransform(trans);
            m_tapTimeLine->start();
            m_pressStatus = ICON_STATUS_IDLE;
            break;
        }

        case LONG_TAP_ZOOM_OUT:
        {
            VFX_LOG(VFX_INFO, VAPP_SHELL_SHCT_ITEM_LONG_TAP_ZOOM_OUT);
            VfxTransform trans;
            trans.type = VRT_TRANSFORM_TYPE_AFFINE;
            trans.data.affine.sx = 1.0f;
            trans.data.affine.sy = 1.0f;
            //m_zoomTimeLine->stop();
            m_zoomTimeLine->setTarget(this);
            m_zoomTimeLine->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
            m_zoomTimeLine->setFromValue(getTransform());
            m_zoomTimeLine->setToValue(trans);
            m_zoomTimeLine->setDurationTime(VAPP_SHELL_SHCT_ICON_ZOOM_TIME);
            setTransform(trans);
            m_zoomTimeLine->start();
            m_pressStatus = ICON_STATUS_IDLE;
            break;
        }

        default:
            break;
    }
}

#endif /* __MMI_VUI_SHELL_SHORTCUTS__ */
