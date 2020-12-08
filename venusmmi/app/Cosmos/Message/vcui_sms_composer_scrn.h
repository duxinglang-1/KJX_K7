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
 *  vcui_sms_composer_scrn.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *
 * Author: Qian Zhao
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCUI_SMS_COMPOSER_SCRN_H__
#define __VCUI_SMS_COMPOSER_SCRN_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"

#include "vfx_page.h"
#include "vcp_text_editor.h"
#include "vfx_cui.h"
#include "vfx_app.h"
#include "vfx_object.h"

#include "vcui_phb_gprot.h"

#include "vcui_sms_composer_contactlist.h"
#include "vcui_sms_composer_core.h"
#include "vcui_sms_composer_util.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "Conversions.h"
#include "app_url.h"
#include "app_str.h"

#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VCUI_SMS_COMPOSER_TWO_ITEM_MARGIN_LARGE VCPFRM_SIDE_MARGIN_LARGE
#define VCUI_SMS_COMPOSER_TWO_ITEM_MARGIN_SMALL VCPFRM_SIDE_MARGIN_SMALL
#define VCUI_SMS_COMPOSER_LEFT_MARGIN (VCPFRM_INDENT_L1 + VCPFRM_INDENT_L2)
#define VCUI_SMS_COMPOSER_ITEM_HORZ_GAP VCPFRM_ITEM_HORZ_GAP
#define VCUI_SMS_COMPOSER_STANDARD_BTN_HEIGHT VCPFRM_STANDARD_BTN_HEIGHT
    
#if defined(__MMI_MAINLCD_320X480__)
#define VCUI_SMS_COMPOSER_MSG_VIEW_CONT_LINE_HEIGHT                     36
#elif defined(__MMI_MAINLCD_480X800__)
#define VCUI_SMS_COMPOSER_MSG_VIEW_CONT_LINE_HEIGHT                     60
#else
#define VCUI_SMS_COMPOSER_MSG_VIEW_CONT_LINE_HEIGHT                     32
#endif

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
class VcuiSmsComposerPage;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/******************************************************************************/
/*                          Class VcuiSmsComposer                             */
/******************************************************************************/
class VcuiSmsComposer : public VfxCui
{
// Declaration
    VFX_DECLARE_CLASS(VcuiSmsComposer);

// Constructor / Destructor
public:
    VcuiSmsComposer();

// Method
    void setRotate(VfxBool isRotate);

    void setEntryData(const VcuiSmsComposerEntryStruct *entryData);
    VcuiSmsComposerEntryStruct* getEntryData() const;
    void freeEntryData();
    
// Override
protected:
    virtual void onRun(void *args, VfxU32 argSize);
    virtual mmi_ret onProc(mmi_event_struct *evt);
    virtual void onDeinit();
    
private:
    VfxBool m_isRotate;
    VcuiSmsComposerEntryStruct *m_entryData;
};

/******************************************************************************/
/*                          Class VcuiSmsComposerScrn                         */
/******************************************************************************/
class VcuiSmsComposerScrn : public VfxMainScr
{
// Declaration
    // VFX_DECLARE_CLASS(VcuiSmsComposerScrn);

// Constructor / Destructor
public:
    VcuiSmsComposerScrn() : 
        m_isOn2ndReady(VFX_FALSE),
        m_pageWeakPtr(NULL)
    { 
        setAppContextShareForVrt(VFX_TRUE);
    }

// Method

// Overridable

// Override
public:
    virtual void on1stReady();   
    virtual void on2ndReady();  //for APP to Page switch performance
    
// Variable
private:
    VfxBool m_isOn2ndReady;  //for APP to Page switch performance
    VfxWeakPtr<VcuiSmsComposerPage> m_pageWeakPtr;
  
// Implementation
public:
    VfxBool getIsOn2ndReady();  //for APP to Page switch performance
};

/******************************************************************************/
/*                          Class VcuiSmsComposerPage                         */
/******************************************************************************/
class VcuiSmsComposerPage : public VfxPage
{
// Declaration
    // VFX_DECLARE_CLASS(VcuiSmsComposerPage);
    
    enum
    {
        VCUI_SMS_COMPOSER_TOOLBAR_SEND = 1, 
        VCUI_SMS_COMPOSER_TOOLBAR_SWITCH_SIM,
        VCUI_SMS_COMPOSER_TOOLBAR_SAVE,
        VCUI_SMS_COMPOSER_TOOLBAR_INSERT,
        VCUI_SMS_COMPOSER_TOOLBAR_END
    };
    
    enum
    {
        VCUI_SMS_COMPOSER_POP_SIM1 = 1,
        VCUI_SMS_COMPOSER_POP_SIM2,
        VCUI_SMS_COMPOSER_POP_SIM3,
        VCUI_SMS_COMPOSER_POP_SIM4,        
        VCUI_SMS_COMPOSER_POP_PHB_NUM,       
        VCUI_SMS_COMPOSER_POP_PHB_NAME,
        VCUI_SMS_COMPOSER_POP_END
    };
    
    enum 
    {
        VCUI_SMS_COMPOSER_FUNC_BAR_SEND = 1, 
        VCUI_SMS_COMPOSER_FUNC_BAR_PREV,    
        VCUI_SMS_COMPOSER_FUNC_BAR_NEXT,
        VCUI_SMS_COMPOSER_FUNC_BAR_INSERT,
        VCUI_SMS_COMPOSER_FUNC_BAR_END
    };

    enum
    {
        VCUI_SMS_COMPOSER_FORM_RECIPIENT = 1, 
        VCUI_SMS_COMPOSER_FORM_CONTENT = 1 << 1,        
        VCUI_SMS_COMPOSER_FORM_CONTACT = 1 << 2, 
        VCUI_SMS_COMPOSER_FORM_HINT = 1 << 3,
        VCUI_SMS_COMPOSER_FORM_END
    };

    typedef enum
    {
        VCUI_SMS_COMPOSER_STATE_NONE,
        VCUI_SMS_COMPOSER_STATE_INSERT_ADDRESS,
        VCUI_SMS_COMPOSER_STATE_INSERT_PHONE_NUM,
        VCUI_SMS_COMPOSER_STATE_INSERT_PHONE_NAME,
        VCUI_SMS_COMPOSER_STATE_TOTAL
    }VcuiSmsComposerPbCuiState;
    
// constructor
public:
    VcuiSmsComposerPage();

// Method
    void setRotate(VfxBool isRotate);
    void page2ndEnter();
    VfxBool isPageReady();      
    VfxBool isGettingData();  
    
    void setContactChange(VcpContactSelector *obj);
    VcpContactSelector* getContactSelector() const;

// Override
protected:
    virtual void onInit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered();
    virtual void onDeinit();
    virtual void onUpdate();
    virtual mmi_ret onProc(mmi_event_struct *evt);
    virtual void onBack();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);
    virtual void setBounds(const VfxRect &value);
    virtual void onRotate(const VfxScreenRotateParam &param);

// internal apis
private:
    void onFunctionBarClicked(VfxObject *obj, VfxId id);
    void onToolBarClicked(VfxObject *obj, VfxId id);
    void onCommandPopClicked(VfxObject *obj, VfxId id);    
    void onConfirmPopClicked(VfxObject *obj, VfxId id);
    void onSearchButtonClicked();
    void onFormItemBoundsChanged(VfxFrame *obj, const VfxRect &rect);
    void onContentTextChanged(VcpTextEditor *obj);
    void onRecipientListNumChanged(VcpContactSelector *obj, VcpContactChangedEnum state);
    void onMoreButtonClicked(VcpContactSelector *obj);    
    void onRecipientListTextChanged(VcpContactSelector *obj, VfxWChar *text);
    void onContactListUpdate(VfxU32 count);
    void onContactlistItemTap(VcpListMenu *listMenu, VfxU32 itemIndex);
    void onToEditorBeforeChange(VfxWChar *text, VfxS32 curPos, VcpTextChangeEnum type, VfxBool *ret) ;      
    void onToEditerEnterKeyClicked(VcpTextEditor *editor, IMEVKEnterKeyStyleEnum enterKeyStyle);
    void onTextEditorActivated(VcpTextEditor *editor, VfxBool activated);
    void onDataRefreshHdlr(VcuiSmsComposerRefreshTypeEnum refresh_type, VcuiSmsComposerResultEnum result);
    
    void createToolBar(void);     
    void createTitleBar(void);
    void updateToolBar(void);   
    void updateFunctionBar(void);   
    void updateHintText(void);
    void updateToggleBar(void);        
    void updateTitleBar(void);
    
    void hideUnhideFormItem(VfxU32 ids, VfxBool isHide);
    void restoreFormItem(void); 

    void clickSendButton(void);    
    void clickSaveButton(void);
    void clickSwitchSimButton(void);   
    void clickInsertButton(void);

    void handleAddrInsertionEvent(VfxU16 cnt);   
    void handleDataReadyEvent(VcuiSmsComposerResultEnum result);
    void handleSendDoneEvent(VcuiSmsComposerResultEnum result);
    void handleSaveDoneEvent(VcuiSmsComposerResultEnum result);    
    void handleSimRefreshEvent(VcuiSmsComposerResultEnum result);   
    void handleCloseAppEvent(VcuiSmsComposerResultEnum result);
    
    VfxBool insertRecipientAddr(const VfxWChar *name, const VfxWChar *address, VfxU32 addressType);
    void insertContentText(VfxWChar *string, VfxBool isReplace);
   
    void showSwapSimConfirmPop(void);
    
    void setContentTextEditorActive(void);
    void setTextEditorAutoActivated(void);   
    
    VfxBool isSendButtonValid(void);
    void openPhbCui(VfxBool isMultiSelect, VfxU32 mode);    
    void postEventToCaller(VcuiSmsComposerEventEnum eventId);

    void sendSms(void);
    void saveSms(void);

// member variables
private:
    VcpTitleBar                 *m_titleBar;
    VcpContactSelector          *m_recipientList;
    VcpTextEditor               *m_content; 
    VcpForm                     *m_form;
    VcpContactEditor            *m_editor;   
    VcpToolBar                  *m_toolBar; 
    VcpFunctionBar              *m_funcBar;    
    VcpTextEditor               *m_curEditor;
    VcpActivityIndicator        *m_loading;
    VfxTextFrame                *m_hintText;
    // VcpCommandPopup          *m_commandPopup;
	VcuiSmsComposerContactList  *m_contactlist;   
    VcpIndicatorPopup           *m_waitingPop;

    mmi_id m_phbCuiId;
    VfxU32 m_itemsAlraedyDraw;   
	VfxU32 m_backUpitemsAlraedyDraw;    
	VfxU32 m_cursorIndexToHeighlight;
    VcuiSmsComposerPbCuiState m_pbInsertState;

    VfxBool m_isRotate;
    VfxBool m_isPageReady;    
    VfxBool m_isGettingData;

    VcuiSmsComposerDataProvider *m_dataProvider;
};

/******************************************************************************/
/*                   Class VcuiSmsComposerRecipientPage                       */
/******************************************************************************/
class VcuiSmsComposerRecipientPage : public VfxPage, public IVcpListMenuContentProvider
{
// Declaration
    // VFX_DECLARE_CLASS(VcuiSmsComposerRecipientPage);

// constructor
public:
    VcuiSmsComposerRecipientPage(VcuiSmsComposerPage *mainPage = NULL);

// Method
    void setRotate(VfxBool isRotate);

// Override
protected:
    virtual void onInit();
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

// Provider 
public:
    virtual VfxU32 getCount() const;
    virtual VfxBool getItemText(
        VfxU32 index,                   // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxWString &text,               // [OUT] the text resource
        VcpListMenuTextColorEnum &color // [OUT] the text color
        );
    virtual VfxBool getItemImage(
        VfxU32 index,                   // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        );

// internal apis
private:
    void onDeleteRecipient(VcpListMenu *list, VfxU32 index);

// member variables
private:
    VfxBool m_isRotate;
    VcuiSmsComposerPage *m_mainPage;
    VcpContactSelector *m_contactSelector;
	VfxS32 m_recipientCount;
};

#endif /* __VCUI_SMS_COMPOSER_SCRN_H__ */
