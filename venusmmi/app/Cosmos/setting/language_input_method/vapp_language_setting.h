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
 *  Vapp_Setting_LanguageSetting.h
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_LANGUAGE_SETTING_H__
#define __VAPP_LANGUAGE_SETTING_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_setting_language_setting.h"
#include "vcui_language_setting_gprot.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/
 
/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappLanguageSettingPage : public VfxPage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappLanguageSettingPage);
    
    // Overrides
    public:
    virtual void onInit();
    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
    virtual VfxU32 getCount() const {return m_count;};
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const {return ((m_selectIdx == index) ? VCP_LIST_MENU_ITEM_STATE_SELECTED: VCP_LIST_MENU_ITEM_STATE_UNSELECTED);}
    virtual mmi_ret onProc(mmi_event_struct *evt);
    // Methods
    public:
    void onSelectItem(VcpListMenu *listMenu, VfxU32 selectIdx)
    {
        m_listMenu->setItemState(m_selectIdx, VCP_LIST_MENU_ITEM_STATE_UNSELECTED);
        m_selectIdx = selectIdx; 
        m_listMenu->setItemState(m_selectIdx, VCP_LIST_MENU_ITEM_STATE_SELECTED);
    };
    void onToolBarTap(VfxObject* sender, VfxId senderId);
    
    // Variables
    public:
    VfxSignal0 m_signalUpdate;
    
    private:
		
#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
	VfxU8 m_currentLangSSC[SSC_SIZE];
#else
    VfxU8 m_currentSetting;
#endif

    VfxU8 m_selectIdx;
    VfxU16 m_count;
    VfxU8 **m_languageStringArray;
    VfxId m_languageSettingCuiId;
    VcpListMenu *m_listMenu;
    VcpTitleBar *m_titleBar;
    VcpToolBar  *m_toolBar;
};

class VappLanguageSettingMainScr : public VfxMainScr
{
    // Methods
    public:
    VappLanguageSettingMainScr() {setIsSmallScreen();}

    // Overrides
    protected:
    virtual void on1stReady() {setBgColor(VFX_COLOR_TRANSPARENT);}
};

class VappLanguageSettingCui : public VfxCui
{
    VFX_DECLARE_CLASS(VappLanguageSettingCui);    

    // Overrides
    public:
    virtual void onRun(void * args, VfxU32 argSize);

    // Methods
    public:
    void onPopupBtnTap(VfxObject *obj, VfxId id);
    void onOk();
    void onCancel();    
    protected:
    void sendLanguageSettingResult(cui_language_setting_enum evtId);
    
	void setLanProc(VfxBasePopup *sender, VfxBasePopupStateEnum state);

    // Variables
    protected:
    VappLanguageSettingMainScr *m_scr;
    VcpIndicatorPopup *m_popup;
	
#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
	VfxU8 m_langSSC[SSC_SIZE];
#else
    VfxU8 m_languageIdx;
#endif
};
#endif /* __VAPP_LANGUAGE_SETTING_H__ */
 
