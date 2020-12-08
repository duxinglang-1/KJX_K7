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
#include "mmi_features.h"

#if defined(__MMI_VUI_WIDGET_GALLERY__)

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_widget_gallery_slide_show_interval_setting.h"
#include "mmi_rp_vapp_widget_gallery_setting_def.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/
// Enum
enum vapp_widget_gallery_interval_setting_enum
{
    VAPP_WIDGET_GALLERY_INTERVAL_SET_1_SEC = 0,
    VAPP_WIDGET_GALLERY_INTERVAL_SET_10_SECS,
    VAPP_WIDGET_GALLERY_INTERVAL_SET_30_SECS,
    VAPP_WIDGET_GALLERY_INTERVAL_SET_1_MIN,
    VAPP_WIDGET_GALLERY_INTERVAL_SET_5_MINS,
    VAPP_WIDGET_GALLERY_INTERVAL_SET_10_MINS,
    VAPP_WIDGET_GALLERY_INTERVAL_SET_30_MINS,

    VAPP_WIDGET_GALLERY_INTERVAL_SET_END_OF_ENUM
};

struct vapp_widget_gallery_interval_set_mapping_entry_struct
{
    vapp_widget_gallery_interval_setting_enum stored_value;
    MMI_STR_ID str_id;
    VfxMsec timeout_value;      // MSec
};

static const vapp_widget_gallery_interval_set_mapping_entry_struct vapp_widget_gallery_interval_set_mapping[] =
{
    { VAPP_WIDGET_GALLERY_INTERVAL_SET_1_SEC,       STR_ID_WIDGET_GALLERY_INTERVAL_1_SEC, (1000-200) }, // minus fade in animation time 200ms
    { VAPP_WIDGET_GALLERY_INTERVAL_SET_10_SECS,     STR_ID_WIDGET_GALLERY_INTERVAL_10_SECS, 10 * 1000 },
    { VAPP_WIDGET_GALLERY_INTERVAL_SET_30_SECS,     STR_ID_WIDGET_GALLERY_INTERVAL_30_SECS, 30 * 1000 },
    { VAPP_WIDGET_GALLERY_INTERVAL_SET_1_MIN,       STR_ID_WIDGET_GALLERY_INTERVAL_1_MIN,   60 * 1000 },
    { VAPP_WIDGET_GALLERY_INTERVAL_SET_5_MINS,      STR_ID_WIDGET_GALLERY_INTERVAL_5_MINS,  5 * 60 * 1000 },
    { VAPP_WIDGET_GALLERY_INTERVAL_SET_10_MINS,     STR_ID_WIDGET_GALLERY_INTERVAL_10_MINS, 10 * 60 * 1000 },
    { VAPP_WIDGET_GALLERY_INTERVAL_SET_30_MINS,     STR_ID_WIDGET_GALLERY_INTERVAL_30_MINS, 30 * 60 * 1000 }
};

static const U32 vapp_widget_gallery_interval_set_max_mapping_num =
    sizeof(vapp_widget_gallery_interval_set_mapping) / sizeof(vapp_widget_gallery_interval_set_mapping[0]);

#define VAPP_WIDGET_GALLERY_SLIDE_SHOW_INTERVAL_DEFAULT_VALUE VAPP_WIDGET_GALLERY_INTERVAL_SET_5_MINS


/***************************************************************************** 
 * Function
 *****************************************************************************/


/***************************************************************************** 
 * VappWidgetGallerySettingIntervalCell
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappWidgetGallerySettingIntervalCell", VappWidgetGallerySettingIntervalCell, VcpFormItemLauncherCell);


VappWidgetGallerySettingIntervalCell::VappWidgetGallerySettingIntervalCell()
{
}


void VappWidgetGallerySettingIntervalCell::onInit()
{
    VcpFormItemLauncherCell::onInit();

    VfxU8 value;
    VfxS16 error;
    ReadValue(NVRAM_SETTING_SLIDE_SHOW_INTERVAL_TIME, &value, DS_BYTE, &error);
    if (value >= VAPP_WIDGET_GALLERY_INTERVAL_SET_END_OF_ENUM)
    {
        value = VAPP_WIDGET_GALLERY_SLIDE_SHOW_INTERVAL_DEFAULT_VALUE;
        WriteValue(NVRAM_SETTING_SLIDE_SHOW_INTERVAL_TIME, &value, DS_BYTE, &error);
    }
    m_storeValue = value;

    setMainText(VFX_WSTR_RES(STR_ID_VAPP_WIDGET_GALLERY_SETTING_INTERVAL_CELLL_TITLE));
    setHintText(getHint());
    m_signalTap.connect(this, &VappWidgetGallerySettingIntervalCell::onTap);
}


void VappWidgetGallerySettingIntervalCell::onTap(VcpFormItemCell *cell, VfxId id)
{
    VfxMainScr *mainScr = VFX_OBJ_DYNAMIC_CAST(findScreen(), VfxMainScr);

    if (mainScr != NULL)
    {
        // Entry a new page 
        VappWidgetGallerySettingIntervalListPage *scrLockSetListPage;
        VFX_OBJ_CREATE(scrLockSetListPage, VappWidgetGallerySettingIntervalListPage, mainScr);

        scrLockSetListPage->m_signalUpdate.connect(this, &VappWidgetGallerySettingIntervalCell::onContextUpdate);
        scrLockSetListPage->setHighlightItem((VfxU32)(m_storeValue));

        mainScr->pushPage(0, scrLockSetListPage);  
    }
}


VfxWString VappWidgetGallerySettingIntervalCell::getHint()
{
    VfxS32 i;
    for(i = 0; i<vapp_widget_gallery_interval_set_max_mapping_num; i++)
    {
        if(vapp_widget_gallery_interval_set_mapping[i].stored_value == m_storeValue)
        {
            return VFX_WSTR_RES(vapp_widget_gallery_interval_set_mapping[i].str_id);
        }
    }
}


/***************************************************************************** 
 * VappWidgetGallerySettingIntervalListPage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappWidgetGallerySettingIntervalListPage", VappWidgetGallerySettingIntervalListPage, VfxPage);


VappWidgetGallerySettingIntervalListPage::VappWidgetGallerySettingIntervalListPage()
{
}


void VappWidgetGallerySettingIntervalListPage::onInit()
{
    VfxPage::onInit();
    
    VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);

    m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_listMenu->setContentProvider(this);

    m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_TRUE);
    
    m_listMenu->setRect(0, 0, LCD_WIDTH, LCD_HEIGHT);        
    m_listMenu->m_signalItemTapped.connect(this, &VappWidgetGallerySettingIntervalListPage::onSelectItem);  

    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_WIDGET_GALLERY_SETTING_INTERVAL_CELLL_TITLE));
    setTopBar(titleBar);
}


VfxU32 VappWidgetGallerySettingIntervalListPage::getCount() const
{
    return vapp_widget_gallery_interval_set_max_mapping_num;
}



VfxBool VappWidgetGallerySettingIntervalListPage::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
{
    if (index < (VfxU32)getCount())
    {
        if (fieldType == VCP_LIST_MENU_FIELD_TEXT)  
        {
           text = VFX_WSTR_RES(vapp_widget_gallery_interval_set_mapping[index].str_id);
           color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
           return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}

void VappWidgetGallerySettingIntervalListPage::onSelectItem(VcpListMenu *listMenu, VfxU32 selectIdx)
{
    m_selectItem = selectIdx;

    if (m_selectItem != m_highlightItem)
    {
        // update setting cell info
        m_signalUpdate.emit((VfxS32)(m_selectItem));
        
        // write value to nvram
        VfxU8 value = m_selectItem;
        VfxS16 error;
        WriteValue(NVRAM_SETTING_SLIDE_SHOW_INTERVAL_TIME, &value, DS_BYTE, &error);

//        if(vapp_widget_gallery_interval_set_mapping[m_selectItem].stored_value == VAPP_WIDGET_GALLERY_INTERVAL_SET_10_MINS)
    }
    getMainScr()->popPage();
}


VfxMsec vapp_widget_gallery_set_get_slide_show_timeout_value_in_msec(void)
{
    VfxU8 value;
    VfxS16 error;

    ReadValue(NVRAM_SETTING_SLIDE_SHOW_INTERVAL_TIME, &value, DS_BYTE, &error);
    if (value >= VAPP_WIDGET_GALLERY_INTERVAL_SET_END_OF_ENUM)
    {
        value = VAPP_WIDGET_GALLERY_SLIDE_SHOW_INTERVAL_DEFAULT_VALUE;
        WriteValue(NVRAM_SETTING_SLIDE_SHOW_INTERVAL_TIME, &value, DS_BYTE, &error);
    }
    vapp_widget_gallery_interval_setting_enum stored_value;
    stored_value = (vapp_widget_gallery_interval_setting_enum)value;

    VfxS32 i=0;
    for (i = 0; i < vapp_widget_gallery_interval_set_max_mapping_num; i++)
    {
        if (vapp_widget_gallery_interval_set_mapping[i].stored_value == stored_value)
        {
            return vapp_widget_gallery_interval_set_mapping[i].timeout_value;
        }
    }
    return 0;
}
#endif
