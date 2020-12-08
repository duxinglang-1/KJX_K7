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
 *  vtst_sample_setting.cpp
 *
 * Project:
 * --------
 *  Venus Sample code of setting
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_config.h"

#ifdef __AFX_RT_TEST__

#include "vtst_rt_main.h"
#include "vcp_navi_title_bar.h"
#include "vcp_form.h"
#include "vfx_cpp_base.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vcp_list_menu.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_sys_memory.h"
#include "vfx_page.h"
#include "vfx_basic_type.h"
#include "vfx_signal.h"
#include "vfx_timer.h"
#include "vfx_frame.h"
#include "vfx_main_scr.h"
#include "vfx_app.h"
#include "vfx_app_launcher.h"
extern "C"
{
#include "mmi_res_range_def.h"
#include "GlobalResDef.h"
}
/***************************************************************************** 
 * Class VtstSampleRadioMenuItem implementation
 *****************************************************************************/

class VtstSampleRadioMenuItem : public VfxBase
{
public:
    VfxId      m_id;
    VfxWString m_text;
    VfxBool    m_isSelect;
};


/***************************************************************************** 
 * Class VtstSampleRadioMenu implementation
 *****************************************************************************/

class VtstSampleRadioMenu : public VcpListMenu, public IVcpListMenuContentProvider
{

    VFX_DECLARE_CLASS(VtstSampleRadioMenu);
// Constructor / Destructor
public:
    VtstSampleRadioMenu() : 
        m_data(NULL),
        m_dataCount(0),
        m_bufferCount(0)
        {}
// Override
protected:
    //virtual void onInit();
    virtual void onDeinit()
    {
        if (m_data)
        {
            for (VfxS32 i = 0; i < m_dataCount; i++)
            {
                VFX_DELETE(m_data[i]);
            }
            VFX_FREE_MEM(m_data);
        }
        VcpListMenu::onDeinit();
    }
    virtual void onUpdate()
    {   
        setContentProvider(this);
        setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
        setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_FALSE);

        VcpListMenu::onUpdate();
    }

    // IVcpListMenuContentProvider
    virtual VfxBool getItemText(
            VfxU32 index,                    
            VcpListMenuFieldEnum fieldType,  
            VfxWString &text,                
            VcpListMenuTextColorEnum &color  
            )
    {
        if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
        {
            text = m_data[index]->m_text;
            color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
        }

        return VFX_TRUE;
    }

    virtual VfxU32 getCount() const
    {
        return m_dataCount;   
    }

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   // [IN] index of the item
        ) const
    {
        if (m_data[index]->m_isSelect)
        {
            return VCP_LIST_MENU_ITEM_STATE_SELECTED;
        }
        else
        {
            return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
        }
    }

// Method
public:
    void addItem(const VtstSampleRadioMenuItem& item)
    {
        if (m_dataCount == m_bufferCount)
        {
            m_bufferCount += 4;
            
            VFX_ALLOC_MEM(m_data, m_bufferCount * sizeof(VtstSampleRadioMenuItem *), this);
            
            // TODO: copy original buffer to new buffer
        }    
        
        VFX_ALLOC_NEW(m_data[m_dataCount], VtstSampleRadioMenuItem, this);
        m_data[m_dataCount]->m_id = item.m_id;
        m_data[m_dataCount]->m_text = item.m_text;
        m_data[m_dataCount]->m_isSelect = item.m_isSelect;

        m_dataCount++;

        checkUpdate();
    }
    
// Variable
private:

    VtstSampleRadioMenuItem **m_data;
    VfxS32 m_dataCount;
    VfxS32 m_bufferCount;

};

VFX_IMPLEMENT_CLASS("VtstSampleRadioMenu", VtstSampleRadioMenu, VcpListMenu);

/***************************************************************************** 
 * Class VtstSampleSettingRadioPage implementation
 *****************************************************************************/
class VtstSampleSettingRadioPage : public VfxPage
{
    VFX_DECLARE_CLASS(VtstSampleSettingRadioPage);

public:
    VtstSampleSettingRadioPage() : m_index(0)
    {};
    VtstSampleSettingRadioPage(VfxS32 index, VfxS32 selectIndex) : 
        m_index(index), 
        m_selectIndex(selectIndex)
    {};

protected:
    virtual void onInit()
    {
        VfxPage::onInit();

        VcpTitleBar *bar;
        VFX_OBJ_CREATE(bar, VcpTitleBar, this);
        if (m_index == 0)
        {
            bar->setTitle(VFX_WSTR("Contacts storage"));
        }
        else
        {
            bar->setTitle(VFX_WSTR("Name display"));
        }
        setTopBar(bar);

        VFX_OBJ_CREATE(radioMenu, VtstSampleRadioMenu, this);
        radioMenu->setBounds(VfxRect(0,0,320,480));
        if (m_index == 0)
        {
            VtstSampleRadioMenuItem tempItem;
            tempItem.m_id = 0;
            tempItem.m_text = VFX_WSTR("Phone");
            if (m_selectIndex == 0)
            {
                tempItem.m_isSelect = VFX_TRUE;
            }
            else
            {
                tempItem.m_isSelect = VFX_FALSE;
            }
            radioMenu->addItem(tempItem);

            tempItem.m_id = 1;
            tempItem.m_text = VFX_WSTR("SIM1");
            if (m_selectIndex == 1)
            {
                tempItem.m_isSelect = VFX_TRUE;
            }
            else
            {
                tempItem.m_isSelect = VFX_FALSE;
            }
            radioMenu->addItem(tempItem);

            tempItem.m_id = 2;
            tempItem.m_text = VFX_WSTR("SIM2");
            if (m_selectIndex == 2)
            {
                tempItem.m_isSelect = VFX_TRUE;
            }
            else
            {
                tempItem.m_isSelect = VFX_FALSE;
            }
            radioMenu->addItem(tempItem);
            radioMenu->m_signalItemTapped.connect(this, &VtstSampleSettingRadioPage::onSelectionChanged);
        }
        else
        {
            VtstSampleRadioMenuItem tempItem;
            tempItem.m_id = 0;
            tempItem.m_text = VFX_WSTR("Last, First");
            if (m_selectIndex == 0)
            {
                tempItem.m_isSelect = VFX_TRUE;
            }
            else
            {
                tempItem.m_isSelect = VFX_FALSE;
            }
            radioMenu->addItem(tempItem);

            tempItem.m_id = 1;
            tempItem.m_text = VFX_WSTR("First, Last");
            if (m_selectIndex == 1)
            {
                tempItem.m_isSelect = VFX_TRUE;
            }
            else
            {
                tempItem.m_isSelect = VFX_FALSE;
            }
            radioMenu->addItem(tempItem);
            radioMenu->m_signalItemTapped.connect(this, &VtstSampleSettingRadioPage::onSelectionChanged);
        }
    }

    void onSelectionChanged(VcpListMenu *menu, VfxU32 index)
    {        
        m_signalSelectNewItem.emit(m_index, index);

        // ceate a timer to delay popop
        VfxTimer *tempTimer;
        VFX_OBJ_CREATE(tempTimer, VfxTimer, this);
        tempTimer->m_signalTick.connect(this, &VtstSampleSettingRadioPage::onTimerStop);
        tempTimer->setStartDelay(300);
        tempTimer->start();
    }

    void onTimerStop(VfxTimer *source)
    {   
        source->stop();
        getMainScr()->popPage();
    }
 

// Variable 
    VtstSampleRadioMenu *radioMenu;
    VfxS32 m_index;
    VfxS32 m_selectIndex;
public:
    VfxSignal2 <VfxS32, VfxS32> m_signalSelectNewItem;
};


VFX_IMPLEMENT_CLASS("VtstSampleSettingRadioPage", VtstSampleSettingRadioPage, VfxPage);
/***************************************************************************** 
 * Class VtstSampleSettingMainPage implementation
 *****************************************************************************/

class VtstSampleSettingMainPage : public VfxPage
{
    VFX_DECLARE_CLASS(VtstSampleSettingMainPage);
protected:
    virtual void onInit()
    {
        VfxPage::onInit();
		
        VcpTitleBar *bar;
        VFX_OBJ_CREATE(bar, VcpTitleBar, this);
        bar->setTitle(VFX_WSTR("Contacts setting"));
        setTopBar(bar);

        VFX_OBJ_CREATE(m_form, VcpForm, this);
        // because form does not support align now, we set the page final size here.
        m_form->setSize(320, 433);
        //m_form->setBounds(getBounds());
        //m_form->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);

        m_radioSelectIndex1 = 0;
        m_radioSelectIndex2 = 0;
        
        //VcpFormItemLauncherCell *setting;
    	VFX_OBJ_CREATE(m_setting[0], VcpFormItemLauncherCell, m_form);
    	m_setting[0]->setMainText(VFX_WSTR("Contacts storage"));
    	m_setting[0]->setHintText(VFX_WSTR("Phone"));
    	m_setting[0]->setAccessory(VCPFORM_NEXT_ITEM_ICON);
        m_setting[0]->m_signalTap.connect(this, &VtstSampleSettingMainPage::onButtonClicked);
        m_form->addItem(m_setting[0], 0);

        VFX_OBJ_CREATE(m_setting[1], VcpFormItemLauncherCell, m_form);
    	m_setting[1]->setMainText(VFX_WSTR("Name display"));
    	m_setting[1]->setHintText(VFX_WSTR("Last, First"));
    	m_setting[1]->setAccessory(VCPFORM_NEXT_ITEM_ICON);
        m_setting[1]->m_signalTap.connect(this, &VtstSampleSettingMainPage::onButtonClicked);
        m_form->addItem(m_setting[1], 1);

        VFX_OBJ_CREATE(m_setting[2], VcpFormItemLauncherCell, m_form);
    	m_setting[2]->setMainText(VFX_WSTR("Set speed dial list"));
    	//m_setting[2]->setHintText(VFX_WSTR("hint text"));
    	m_setting[2]->setAccessory(VCPFORM_NEXT_ITEM_ICON);
        m_setting[2]->m_signalTap.connect(this, &VtstSampleSettingMainPage::onButtonClicked);
        m_form->addItem(m_setting[2], 2);

        VFX_OBJ_CREATE(m_setting[3], VcpFormItemLauncherCell, m_form);
    	m_setting[3]->setMainText(VFX_WSTR("Set block list"));
    	//setting->setHintText(VFX_WSTR("hint text"));
    	m_setting[3]->setAccessory(VCPFORM_NEXT_ITEM_ICON);
        m_setting[3]->m_signalTap.connect(this, &VtstSampleSettingMainPage::onButtonClicked);
        m_form->addItem(m_setting[3], 3);

        //VcpFormItemSwitchCell *switchTypeSetting;
    	VFX_OBJ_CREATE(m_switchTypeSetting, VcpFormItemSwitchCell, m_form);
    	m_switchTypeSetting->setMainText(VFX_WSTR("Save stranger notify"));
    	m_switchTypeSetting->setSwitchStatus(VFX_TRUE);
    	//switchTypeSetting->m_signalSwitchChangeReq.connect(this, &FormAppScreen::SwitchChangeReq);
    	m_switchTypeSetting->m_signalTap.connect(this, &VtstSampleSettingMainPage::onButtonClicked);
        m_form->addItem(m_switchTypeSetting, 4);

        VFX_OBJ_CREATE(m_setting[4], VcpFormItemLauncherCell, m_form);
    	m_setting[4]->setMainText(VFX_WSTR("Backup/Restore contacts"));
    	//setting->setHintText(VFX_WSTR("hint text"));
    	//setting->setAccessory(VCPFORM_NEXT_ITEM_ICON);
        m_setting[4]->m_signalTap.connect(this, &VtstSampleSettingMainPage::onButtonClicked);
        m_form->addItem(m_setting[4], 5);

        VFX_OBJ_CREATE(m_setting[5], VcpFormItemLauncherCell, m_form);
    	m_setting[5]->setMainText(VFX_WSTR("Import contacts"));
    	//setting->setHintText(VFX_WSTR("hint text"));
    	//setting->setAccessory(VCPFORM_NEXT_ITEM_ICON);
        m_setting[5]->m_signalTap.connect(this, &VtstSampleSettingMainPage::onButtonClicked);
        m_form->addItem(m_setting[5], 6);

        VFX_OBJ_CREATE(m_setting[6], VcpFormItemLauncherCell, m_form);
    	m_setting[6]->setMainText(VFX_WSTR("Sync contacts"));
    	//setting->setHintText(VFX_WSTR("hint text"));
    	//setting->setAccessory(VCPFORM_NEXT_ITEM_ICON);
        m_setting[6]->m_signalTap.connect(this, &VtstSampleSettingMainPage::onButtonClicked);
        m_form->addItem(m_setting[6], 7);

        VFX_OBJ_CREATE(m_setting[7], VcpFormItemLauncherCell, m_form);
    	m_setting[7]->setMainText(VFX_WSTR("Set extra number manager"));
    	//setting->setHintText(VFX_WSTR("hint text"));
    	m_setting[7]->setAccessory(VCPFORM_NEXT_ITEM_ICON);
        m_setting[7]->m_signalTap.connect(this, &VtstSampleSettingMainPage::onButtonClicked);
        m_form->addItem(m_setting[7], 8);
    }	

    void onButtonClicked(VcpFormItemCell* sender, VfxId Id)
    {
        //Id = 0;
        if (Id == 0 || Id == 1)
        {
            VtstSampleSettingRadioPage *page;
            if (Id == 0)
            {
                VFX_OBJ_CREATE_EX(page, VtstSampleSettingRadioPage, getMainScr(), (Id, m_radioSelectIndex1));
            }
            else
            {
                VFX_OBJ_CREATE_EX(page, VtstSampleSettingRadioPage, getMainScr(), (Id, m_radioSelectIndex2));
            }
            page->m_signalSelectNewItem.connect(this,  &VtstSampleSettingMainPage::onSelectNewItem);
            getMainScr()->pushPage(VFX_ID_NULL, page);
        }
    }

    void onSelectNewItem(VfxS32 itemId, VfxS32 subItemId)
    {
        if (itemId == 0)
        {
            m_radioSelectIndex1  = subItemId;
            if (subItemId == 0)
            {
                m_setting[0]->setHintText(VFX_WSTR("Phone"));
            }
            else if (subItemId == 1)
            {
                m_setting[0]->setHintText(VFX_WSTR("SIM1"));
            }
            else
            {
                m_setting[0]->setHintText(VFX_WSTR("SIM2"));
            }
        }
        else
        {
            m_radioSelectIndex2  = subItemId;
            if (subItemId == 0)
            {
                m_setting[1]->setHintText(VFX_WSTR("Last, First"));
            }
            else if (subItemId == 1)
            {
                m_setting[1]->setHintText(VFX_WSTR("First, Last"));
            }
        }
    }


private:
    VcpForm *m_form;

    VcpFormItemLauncherCell *m_setting[8];
    VfxS32 m_radioSelectIndex1;
    VfxS32 m_radioSelectIndex2;
    VcpFormItemSwitchCell *m_switchTypeSetting;
};

VFX_IMPLEMENT_CLASS("VtstSampleSettingMainPage", VtstSampleSettingMainPage, VfxPage);


/***************************************************************************** 
 * Class VtstSampleSettingAppScr declaration
 *****************************************************************************/

class VtstSampleSettingAppScr : public VfxMainScr
{
    VFX_DECLARE_CLASS(VtstSampleSettingAppScr);


// Override
protected:
    virtual void on1stReady();

};

/***************************************************************************** 
 * Class VtstSampleSettingAppScr implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VtstSampleSettingAppScr", VtstSampleSettingAppScr, VfxMainScr);

void VtstSampleSettingAppScr::on1stReady()
{
    VfxMainScr::on1stReady();

    VfxPage *page;
    VFX_OBJ_CREATE(page, VtstSampleSettingMainPage, this);
    pushPage(0, page);
}

/***************************************************************************** 
 * Class VtstSampleSettingApp declaration
 *****************************************************************************/

class VtstSampleSettingApp : public VfxApp
{
    VFX_DECLARE_CLASS(VtstSampleSettingApp);

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize);
};

/***************************************************************************** 
 * Class VtstSampleSettingApp implementation
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VtstSampleSettingApp", VtstSampleSettingApp, VfxApp);

void VtstSampleSettingApp::onRun(void* args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    VtstSampleSettingAppScr *scr;
    VFX_OBJ_CREATE(scr, VtstSampleSettingAppScr, this);
    scr->show();
}

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

VtstTestResultEnum vtst_sample_setting_entry(VfxU32 param)
{
    VFX_UNUSED(param);
    VfxAppLauncher::launchWithAsmSize( 
        APP1_BASE, 
        VFX_OBJ_CLASS_INFO(VtstSampleSettingApp),
        GRP_ID_ROOT, 204800 * 1,
        NULL, 0);
   return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__

