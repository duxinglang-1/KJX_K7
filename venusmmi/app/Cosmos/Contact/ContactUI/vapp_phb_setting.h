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
 *  vapp_phb_setting.h
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

#ifndef __PB_SETTING_H__
#define __PB_SETTING_H__

#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vcp_menu_popup.h"

#include "vapp_contact_setting.h"
#include "vapp_contact_op.h"


/***************************************************************************** 
 * Class VappContactSettingCUI
 *****************************************************************************/ 
class VappContactSettingCUI : public VfxCui
{
    VFX_DECLARE_CLASS(VappContactSettingCUI);

#ifdef __VCARD_CLOUD_SUPPORT__
public:
    static void *memAllocator(VfxU32 size);

    static void memDeallocator(void *mem);

    static VfxU32 m_countAllocMem;
#endif /* __VCARD_CLOUD_SUPPORT__ */

protected:
    virtual void onRun(void* args, VfxU32 argSize);

#ifdef __VCARD_CLOUD_SUPPORT__
	using  VfxApp::onProcessClose;
    virtual VfxAppCloseAnswerEnum onProcessClose(VfxAppCloseOption options);

    virtual void onInit();

    virtual void onDeinit();

    static mmi_ret listener(mmi_event_struct *evt);
#endif /* __VCARD_CLOUD_SUPPORT__ */
};


/***************************************************************************** 
 * Class VappContactSettingScr
 *****************************************************************************/ 
class VappContactSettingScr : public VfxMainScr
{
protected:
    virtual void on1stReady();

#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    void onContactUpdated(ContactTask* task, mmi_event_struct* evt);

    virtual void onInit();

    virtual void onDeinit();
#endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */
};


/***************************************************************************** 
 * Class VappContactSettingPage
 *****************************************************************************/ 
class VappContactSettingPage : public VfxPage
{
public:
    enum SettingItemEnum
    {
        CONTACT_SETTING_STORAGE,
    #ifdef __MMI_PHB_LAST_NAME_FIELD__
        CONTACT_SETTING_NAME_DISPLAY,
    #endif
    #ifdef __MMI_PHB_SPEED_DIAL__ 
        CONTACT_SETTING_SPEED_DIAL,
    #endif /* __MMI_PHB_SPEED_DIAL__ */
   
    #ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
        CONTACT_SETTING_SAVE_NOTIFY,
    #endif
    #if defined(__MMI_MULTI_VCARD__) || defined(__VCARD_CLOUD_SUPPORT__)
        CONTACT_SETTING_BACKUP,
        CONTACT_SETTING_RESTORE,
    #endif /* defined(__MMI_MULTI_VCARD__) || defined(__VCARD_CLOUD_SUPPORT__) */
        CONTACT_SETTING_IMPORT,
        CONTACT_SETTING_EXPORT,
    #ifdef __MMI_SYNCML_APP_SYNC_MENU_SUPPORT__
        CONTACT_SETTING_SYNC,
    #endif
    #ifdef __MMI_MOBILE_SERVICE__
/* under construction !*/
    #endif
        CONTACT_SETTING_EXTRA_NUMBER,
        CONTACT_SETTING_END
    };

protected:
    virtual void onInit();
#ifdef __MMI_CONTACT_SLIM__
		virtual void onDeinit();
#endif
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    virtual mmi_ret onProc(mmi_event_struct *evt);
    void configItem();
#endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */

private:
    void componentInit();
    void componentPlace();
    void componentSetAction();

private:
    VcpForm                 *m_form;
    VcpFormItemLauncherCell *m_setting[CONTACT_SETTING_END];
    VcpFormItemSwitchCell   *m_switch;
    VfxWString               m_hint;

private:
    void onButtonClicked(VcpFormItemCell* sender, VfxId id);
    void onItemSwitchReq(VcpFormItemSwitchCell* obj, VfxId id, VfxBool value);
    void onStorageChange();
    void onNameDisplayChange();
};


/***************************************************************************** 
 * Class VappContactStoragePage
 *****************************************************************************/
class VappContactStoragePage : public VfxPageHandler
{
protected:
    virtual void onPageInit(VfxPageEx * page);
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    virtual mmi_ret onPageProc(VfxPageEx *page, mmi_event_struct *evt);
    void updateStorageList();
#endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */

public:
    VfxSignal0                  m_signalStorageSave;

private:
    //void componentInit();
    void componentPlace();
    void componentSetAction();

private:
    VcpListMenu                *m_list;
    VappContactStorageProvider *m_listProvider;

private:
    void onToolBarClicked(VfxObject *obj, VfxId id);
    void onSelectStateChange(VcpListMenu *list, VfxU32 index, VcpListMenuItemStateEnum state);
};


#ifdef __MMI_PHB_LAST_NAME_FIELD__
/***************************************************************************** 
 * Class VappContactNameDisplayPage
 *****************************************************************************/ 
class VappContactNameDisplayPage : public VfxPage
{
protected:
    virtual void onInit();

public:
    VfxSignal0                     m_signalNameDisplaySet;

private:
    void componentInit();
    void componentPlace();
    void componentSetAction();

private:
    VcpListMenu                    *m_list;
    VappContactNameDisplayProvider *m_listProvider;
    VcpCommandPopup                *m_commandPopup;

private:
    void itemTapped(VcpListMenu *list, VfxU32 index);
    static void asycProcessing(void *user_data);
};
#endif /* __MMI_PHB_LAST_NAME_FIELD__ */


/***************************************************************************** 
 * Class VappContactImportPage
 *****************************************************************************/ 
/*class VappContactImportPage : public VfxPage
{
protected:
    virtual void onInit();

public:
    enum SettingImportEnum
    {
        CONTACT_SETTING_IMPORT_SIM = 0,
        CONTACT_SETTING_IMPORT_SIM2,
        CONTACT_SETTING_IMPORT_SIM3,
        CONTACT_SETTING_IMPORT_SIM4,
    #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        CONTACT_SETTING_IMPORT_TCARD,
    #endif
        CONTACT_SETTING_IMPORT_END
    };

private:
    void onImportBtnClicked(VfxObject *obj, VfxId id);
};
*/

/***************************************************************************** 
 * Class VappContactExportPage
 *****************************************************************************/ 
/*class VappContactExportPage : public VfxPage
{
protected:
    virtual void onInit();

public:
    enum SettingImportEnum
    {
        CONTACT_SETTING_EXPORT_SIM = 0,
        CONTACT_SETTING_EXPORT_SIM2,
        CONTACT_SETTING_EXPORT_SIM3,
        CONTACT_SETTING_EXPORT_SIM4,
    #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        CONTACT_SETTING_EXPORT_TCARD,
    #endif
        CONTACT_SETTING_EXPORT_END
    };

private:
    void onExportBtnClicked(VfxObject *obj, VfxId id);
};
*/
/***************************************************************************** 
 * Class VappContactImportExportPage
 *****************************************************************************/ 

class VappContactMultiCopyPage : public VfxPage
{
protected:
    virtual void onInit();

public:
	VappContactMultiCopyPage (VfxBool isImport);
    enum SettingImportEnum
    {
        CONTACT_SETTING_IMPORT_OR_EXPORT_SIM = 0,
        CONTACT_SETTING_IMPORT_OR_EXPORT_SIM2,
        CONTACT_SETTING_IMPORT_OR_EXPORT_SIM3,
        CONTACT_SETTING_IMPORT_OR_EXPORT_SIM4,
 #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        CONTACT_SETTING_EXPORT_TCARD,
    #endif
        CONTACT_SETTING_IMPORT_OR_EXPORT_END
    };

private:
    void onBtnClicked(VfxObject *obj, VfxId id);
    VfxBool m_isImport;
};



#ifdef __VCARD_CLOUD_SUPPORT__
/***************************************************************************** 
 * Class VappContactBackupPage
 *****************************************************************************/ 
class VappContactBackupPage : public VfxPage
{
public:
    void backUpDone();
    
protected:
    virtual void onInit();

    virtual mmi_ret onProc(mmi_event_struct *evt);

private:
    void onContextMenuSelected(VcpMenuPopup*, VcpMenuPopupEventEnum, VcpMenuPopupItem*);

    void login(VfxU32 providerId);

    static mmi_ret listen(mmi_event_struct *evt);

    void closeSelf();

    enum
    {
        VAPP_PHB_BACKUP_TO_MEMORY_CARD,
        VAPP_PHB_BACKUP_TO_YAHOO = 0x10
    };
};


/***************************************************************************** 
 * Class VappContactRestorePage
 *****************************************************************************/ 
class VappContactRestorePage : public VfxPage
{
public:
    void RestoreDone();
    
protected:
    virtual void onInit();

    virtual mmi_ret onProc(mmi_event_struct *evt);

private:
    void onContextMenuSelected(VcpMenuPopup*, VcpMenuPopupEventEnum, VcpMenuPopupItem*);

    void login(VfxU32 providerId);

    static mmi_ret listen(mmi_event_struct *evt);

    void closeSelf();
    
    enum
    {
        VAPP_PHB_RESTORE_FROM_MEMORY_CARD,
        VAPP_PHB_RESTORE_FROM_YAHOO = 0x10
    };
};
#endif /* __VCARD_CLOUD_SUPPORT__ */

void VappContactSettingLaunch(VfxMainScr* scr);
#ifdef __MMI_CONTACT_SLIM__
    mmi_id vcui_phb_setting_create(mmi_id parent_id);
    void vcui_phb_setting_run(mmi_id cui_id);
    void vcui_phb_setting_close(mmi_id cui_id); 
#endif

#endif /* __PB_SETTING_H__ */

