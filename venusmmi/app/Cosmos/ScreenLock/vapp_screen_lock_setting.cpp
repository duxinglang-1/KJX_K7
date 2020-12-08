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
 *  vapp_screen_lock_setting.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_screen_lock_gprot.h"
#include "vapp_screen_lock_setting.h"
#include "mmi_rp_vapp_screen_lock_def.h"


/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "GpioSrvGprot.h"
#include "BootupSrvGprot.h"

#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Define
 *****************************************************************************/
// Enum
enum vapp_scr_lock_setting_enum
{
    VAPP_SCR_LOCK_SET_15_SEC = 0,
    VAPP_SCR_LOCK_SET_30_SEC,
    VAPP_SCR_LOCK_SET_1_MIN,
    VAPP_SCR_LOCK_SET_2_MIN,
    VAPP_SCR_LOCK_SET_5_MIN,
    VAPP_SCR_LOCK_SET_10_MIN,
    VAPP_SCR_LOCK_SET_NEVER,

    VAPP_SCR_LOCK_SET_END_OF_ENUM
};

struct vapp_slk_set_mapping_entry_struct
{
    vapp_scr_lock_setting_enum stored_value;
    MMI_STR_ID str_id;
    VfxS32 timeout_value;
};

static const vapp_slk_set_mapping_entry_struct vapp_scr_lock_set_mapping[] =
{
    { VAPP_SCR_LOCK_SET_15_SEC,  STR_ID_SCR_LOCK_15_SEC, 15 },
    { VAPP_SCR_LOCK_SET_30_SEC,  STR_ID_SCR_LOCK_30_SEC, 30 },
    { VAPP_SCR_LOCK_SET_1_MIN,   STR_ID_SCR_LOCK_1_MIN,  60 },
    { VAPP_SCR_LOCK_SET_2_MIN,   STR_ID_SCR_LOCK_2_MIN,   2 * 60 },
    { VAPP_SCR_LOCK_SET_5_MIN,   STR_ID_SCR_LOCK_5_MIN,   5 * 60 },
    { VAPP_SCR_LOCK_SET_10_MIN,  STR_ID_SCR_LOCK_10_MIN, 10 * 60 },
    { VAPP_SCR_LOCK_SET_NEVER,   STR_ID_SCR_LOCK_NEVER,  0 }
};

static const U32 vapp_scr_lock_set_max_mapping_num =
    sizeof(vapp_scr_lock_set_mapping) / sizeof(vapp_scr_lock_set_mapping[0]);

#define VAPP_SCR_LOCK_BACKLIGHT_DEFAULT_VALUE VAPP_SCR_LOCK_SET_1_MIN


/***************************************************************************** 
 * Function
 *****************************************************************************/
// set default backlight timer during EVT_ID_SRV_BOOTUP_NORMAL_INIT
extern "C" mmi_ret vapp_screen_lock_set_default_backlight_timer()
{
    VfxU8 value;
    VfxS16 error;
    ReadValue(NVRAM_SETTING_AUTO_SCREENLOCK_TIME, &value, DS_BYTE, &error);
    if (value >= VAPP_SCR_LOCK_SET_END_OF_ENUM)
    {
        value = VAPP_SCR_LOCK_BACKLIGHT_DEFAULT_VALUE;
        WriteValue(NVRAM_SETTING_AUTO_SCREENLOCK_TIME, &value, DS_BYTE, &error);
    }

    if(vapp_scr_lock_set_mapping[value].stored_value == VAPP_SCR_LOCK_SET_NEVER)
    {
        srv_gpio_setting_set_bl_time(SRV_GPIO_BACKLIGHT_PERMANENT_ON_TIME);
    }
    else
    {
        srv_gpio_setting_set_bl_time(vapp_scr_lock_set_mapping[value].timeout_value);
    }
    return MMI_RET_OK;
}


extern "C" mmi_ret vapp_screen_lock_setting_main_evt_hdlr(mmi_event_struct *event)
{
    mmi_ret ret;

    MMI_ASSERT(event);

    switch (event->evt_id)
    {
       case EVT_ID_SRV_BOOTUP_COMPLETED:
            ret = vapp_screen_lock_set_default_backlight_timer();
            break;

        default:
            ret = MMI_RET_OK;
            break;
    }

    return ret;
}


/***************************************************************************** 
 * VappScreenLockSettingCell
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappScreenLockSettingCell", VappScreenLockSettingCell, VcpFormItemLauncherCell);


VappScreenLockSettingCell::VappScreenLockSettingCell()
{
}


void VappScreenLockSettingCell::onInit()
{
    VcpFormItemLauncherCell::onInit();

    VfxU8 value;
    VfxS16 error;
    ReadValue(NVRAM_SETTING_AUTO_SCREENLOCK_TIME, &value, DS_BYTE, &error);
    if (value >= VAPP_SCR_LOCK_SET_END_OF_ENUM)
    {
        value = VAPP_SCR_LOCK_BACKLIGHT_DEFAULT_VALUE;
        WriteValue(NVRAM_SETTING_AUTO_SCREENLOCK_TIME, &value, DS_BYTE, &error);
    }
    m_storeValue = value;

    setAccessory(VCPFORM_NEXT_ITEM_ICON);

    setMainText(VFX_WSTR_RES(STR_ID_SCR_LOCK_SETTING_TITLE));
    setHintText(getHint());
    m_signalTap.connect(this, &VappScreenLockSettingCell::onTap);
}


void VappScreenLockSettingCell::onTap(VcpFormItemCell *cell, VfxId id)
{
    VfxMainScr *mainScr = VFX_OBJ_DYNAMIC_CAST(findScreen(), VfxMainScr);

    if (mainScr != NULL)
    {
        // Entry a new page 
        VappScreenLockSettingListPage *scrLockSetListPage;
        VFX_OBJ_CREATE(scrLockSetListPage, VappScreenLockSettingListPage, mainScr);

        scrLockSetListPage->m_signalUpdate.connect(this, &VappScreenLockSettingCell::onContextUpdate);
        scrLockSetListPage->setHighlightItem((VfxU32)(m_storeValue));
        scrLockSetListPage->showMenuItem((VfxU32)(m_storeValue));

        mainScr->pushPage(0, scrLockSetListPage);  
    }
}


VfxWString VappScreenLockSettingCell::getHint()
{
    VfxS32 i;
    for(i = 0; i<vapp_scr_lock_set_max_mapping_num; i++)
    {
        if(vapp_scr_lock_set_mapping[i].stored_value == m_storeValue)
        {
            return VFX_WSTR_RES(vapp_scr_lock_set_mapping[i].str_id);
        }
    }
}


/***************************************************************************** 
 * VappScreenLockSettingListPage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappScreenLockSettingListPage", VappScreenLockSettingListPage, VfxPage);


VappScreenLockSettingListPage::VappScreenLockSettingListPage()
{
}


void VappScreenLockSettingListPage::onInit()
{
    VfxPage::onInit();
    
    VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);

    m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_listMenu->setContentProvider(this);

    m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_TRUE);
    
    m_listMenu->setSize(getSize());
    m_listMenu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
           
    m_listMenu->m_signalItemTapped.connect(this, &VappScreenLockSettingListPage::onSelectItem);  

    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(STR_ID_SCR_LOCK_SETTING_TITLE);
    setTopBar(titleBar);
}


void VappScreenLockSettingListPage::showMenuItem(VfxU32 highlightItem)
{
    m_listMenu->setVisibleMenuItem(highlightItem);
}


VfxU32 VappScreenLockSettingListPage::getCount() const
{
    return vapp_scr_lock_set_max_mapping_num;
}



VfxBool VappScreenLockSettingListPage::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
{
    if (index < (VfxU32)getCount())
    {
        if (fieldType == VCP_LIST_MENU_FIELD_TEXT)  
        {
           text.loadFromRes(vapp_scr_lock_set_mapping[index].str_id);
           color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
           return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}

void VappScreenLockSettingListPage::onSelectItem(VcpListMenu *listMenu, VfxU32 selectIdx)
{
    m_selectItem = selectIdx;

    if (m_selectItem != m_highlightItem)
    {
        // update setting cell info
        m_signalUpdate.emit((VfxS32)(m_selectItem));
        
        // write value to nvram
        VfxU8 value = m_selectItem;
        VfxS16 error;
        WriteValue(NVRAM_SETTING_AUTO_SCREENLOCK_TIME, &value, DS_BYTE, &error);

        if(vapp_scr_lock_set_mapping[m_selectItem].stored_value == VAPP_SCR_LOCK_SET_NEVER)
        {
            srv_gpio_setting_set_bl_time(SRV_GPIO_BACKLIGHT_PERMANENT_ON_TIME);
        }
        else
        {
            srv_gpio_setting_set_bl_time(vapp_scr_lock_set_mapping[m_selectItem].timeout_value);
        }
    }
    getMainScr()->popPage();
}
