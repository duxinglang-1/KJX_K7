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
 *  vapp_phb_setting.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#include "vapp_contact_setting.h"
#include "vapp_contact_storage.h"
#include "vapp_phb_app.h"
#include "vapp_phb_launch.h"
#include "vapp_phb_multi.h"
#include "vapp_phb_speed.h"
#include "vapp_phb_extra.h"
#include "vapp_phb_setting.h"
#include "vapp_phb_backup_restore.h"
#include "vapp_phb_gprot.h"
#ifdef __MMI_USB_SUPPORT__
#include "vapp_usb_gprot.h"
#endif
#include "vcui_sync_gprot.h"
#include "mmi_rp_vapp_contact_def.h"

#ifdef __MMI_MOBILE_SERVICE__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_MOBILE_SERVICE__ */

#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
#include "mmi_rp_app_usbsrv_def.h"
#endif

#ifdef __VCARD_CLOUD_SUPPORT__
#include "vcui_sso_gprot.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif
#include "PhbSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGprot.h"
#endif
#include "GpioSrvGprot.h"
#ifdef __VCARD_CLOUD_SUPPORT__
#include "SsoSrvGprot.h"
#include "CloudSrvGprot.h"
#endif /* __VCARD_CLOUD_SUPPORT__ */
#ifdef __cplusplus
}
#endif


#ifdef __VCARD_CLOUD_SUPPORT__

#define MMI_PHB_CLOUD_MAX_PROVIDER 2

typedef struct
{
    VfxU32 idList[MMI_PHB_CLOUD_MAX_PROVIDER];
    VfxU8 count;
}mmi_phb_cloud_provider_struct;

static mmi_phb_cloud_provider_struct g_phb_cloud_provider;

#endif /* __VCARD_CLOUD_SUPPORT__ */


/***************************************************************************** 
 * Class VappContactSettingCUI
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappContactSettingCUI", VappContactSettingCUI, VfxCui);

void VappContactSettingCUI::onRun(void* args, VfxU32 argSize)
{
    VfxCui::onRun(args, argSize);

    VappContactSettingScr *scr;
    VFX_OBJ_CREATE(scr, VappContactSettingScr, this);
    scr->setTransitType(VFX_SCR_TRANSIT_TYPE_CUI);
    scr->show();
}


#ifdef __VCARD_CLOUD_SUPPORT__
VfxU32 VappContactSettingCUI::m_countAllocMem = 0;


void VappContactSettingCUI::onInit()
{
    VfxCui::onInit();
}


void VappContactSettingCUI::onDeinit()
{
    VfxCui::onDeinit();
}


VfxAppCloseAnswerEnum VappContactSettingCUI::onProcessClose(VfxAppCloseOption options)
{
    return VFX_APP_CLOSE_ANSWER_YES;
}


mmi_ret VappContactSettingCUI::listener(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}


void* VappContactSettingCUI::memAllocator(VfxU32 size)
{
    void *memPtr = NULL;
    VfxApp *app = VfxAppLauncher::findApp(
                          VCUI_CONTACT_SETTING,
                          VFX_OBJ_CLASS_INFO(VappContactSettingCUI),
                          VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG | VFX_APP_LAUNACHER_FIND_APP_BG_FLAG, 0);

    if (app && size > 0)
    {
        memPtr = mmi_frm_asm_alloc_r(app->getGroupId(), size);

        if (memPtr)
        {
            ++m_countAllocMem;
        }
    }
    MMI_TRACE(MMI_COMMON_TRC_G4_PHB, VAPP_CONTACT_SETTING_ALLOCATOR, m_countAllocMem, app, app->getGroupId(), size, memPtr);

    return memPtr;
}


void VappContactSettingCUI::memDeallocator(void *mem)
{
    VfxApp *app = VfxAppLauncher::findApp(
                          VCUI_CONTACT_SETTING,
                          VFX_OBJ_CLASS_INFO(VappContactSettingCUI),
                          VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG | VFX_APP_LAUNACHER_FIND_APP_BG_FLAG, 0);

    if (app && mem)
    {
        mmi_frm_asm_free_r(app->getGroupId(), mem);
        MMI_TRACE(MMI_COMMON_TRC_G4_PHB, VAPP_CONTACT_SETTING_FREE, m_countAllocMem, app, app->getGroupId(), -1, mem);

        --m_countAllocMem;
    }

    MMI_TRACE(MMI_COMMON_TRC_G4_PHB, VAPP_CONTACT_SETTING_FREE, m_countAllocMem, app, app->getGroupId(), -2, mem);
}
#endif /* __VCARD_CLOUD_SUPPORT__ */


/***************************************************************************** 
 * Class VappContactSettingScr
 *****************************************************************************/
void VappContactSettingScr::on1stReady()
{
    VfxMainScr::on1stReady();

    VappContactSettingPage *page;
    VFX_OBJ_CREATE(page, VappContactSettingPage, this);
    pushPage(VFX_ID_NULL, page);
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    ContactTask *task = GET_CONTACT_TASK();
    task->m_signalTask.connect(this, &VappContactSettingScr::onContactUpdated);
#endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */
}


#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
void VappContactSettingScr::onContactUpdated(ContactTask * task,mmi_event_struct * evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
        {
            processProc(evt);
            break;
        }
        case EVT_ID_USB_ENTER_MS_MODE:
        case EVT_ID_USB_EXIT_MS_MODE:
        {
            processProc(evt);
            break;
        }
        default:
            break;
    }
}
#endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */


#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
void VappContactSettingScr::onInit()
{
    VfxMainScr::onInit();
}


void VappContactSettingScr::onDeinit()
{
    ContactTask *task = GET_CONTACT_TASK();
    task->m_signalTask.disconnect(this, &VappContactSettingScr::onContactUpdated);

    VfxMainScr::onDeinit();
}
#endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */


/***************************************************************************** 
 * Class VappContactSettingPage
 *****************************************************************************/
void VappContactSettingPage::onInit()
{
    VfxPage::onInit();

    componentInit();
    componentPlace();
    componentSetAction();
}


#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
mmi_ret VappContactSettingPage::onProc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
        case EVT_ID_USB_ENTER_MS_MODE:
        case EVT_ID_USB_EXIT_MS_MODE:
        {
            onStorageChange();
            configItem();
            break;
        }
        default:
            break;
    }
    
    return  VfxPage::onProc(evt);
}


void VappContactSettingPage::configItem()
{
    if (srv_sim_ctrl_get_num_of_inserted() == 0
    #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        && !srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV)
    #endif
        )
    {
        m_setting[CONTACT_SETTING_IMPORT]->setIsDisabled(VFX_TRUE);
    }
    else
    {
        m_setting[CONTACT_SETTING_IMPORT]->setIsDisabled(VFX_FALSE);
    }
    
    if (srv_sim_ctrl_get_num_of_inserted() == 0
    #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        && !srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV)
    #endif
        )
    {
        m_setting[CONTACT_SETTING_EXPORT]->setIsDisabled(VFX_TRUE);
    }
    else
    {
        m_setting[CONTACT_SETTING_EXPORT]->setIsDisabled(VFX_FALSE);
    }
}
#endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */


void VappContactSettingPage::componentInit()
{
    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(STR_ID_VAPP_PHB_SETTING);
    setTopBar(bar);

    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setSize(getSize());
    m_form->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    VFX_OBJ_CREATE(m_setting[CONTACT_SETTING_STORAGE], VcpFormItemLauncherCell, m_form);
#ifdef __MMI_PHB_LAST_NAME_FIELD__
    VFX_OBJ_CREATE(m_setting[CONTACT_SETTING_NAME_DISPLAY], VcpFormItemLauncherCell, m_form);
#endif

#ifdef __MMI_PHB_SPEED_DIAL__
    VFX_OBJ_CREATE(m_setting[CONTACT_SETTING_SPEED_DIAL], VcpFormItemLauncherCell, m_form);
#endif /* __MMI_PHB_SPEED_DIAL__ */
#ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
    VFX_OBJ_CREATE(m_switch, VcpFormItemSwitchCell, m_form);
#endif
#if defined(__MMI_MULTI_VCARD__) || defined(__VCARD_CLOUD_SUPPORT__)
    VFX_OBJ_CREATE(m_setting[CONTACT_SETTING_BACKUP], VcpFormItemLauncherCell, m_form);
    VFX_OBJ_CREATE(m_setting[CONTACT_SETTING_RESTORE], VcpFormItemLauncherCell, m_form);
#endif /* defined(__MMI_MULTI_VCARD__) || defined(__VCARD_CLOUD_SUPPORT__) */
    VFX_OBJ_CREATE(m_setting[CONTACT_SETTING_IMPORT], VcpFormItemLauncherCell, m_form);
    VFX_OBJ_CREATE(m_setting[CONTACT_SETTING_EXPORT], VcpFormItemLauncherCell, m_form);
#ifdef __MMI_SYNCML_APP_SYNC_MENU_SUPPORT__
    VFX_OBJ_CREATE(m_setting[CONTACT_SETTING_SYNC], VcpFormItemLauncherCell, m_form);
#endif
#ifdef __MMI_MOBILE_SERVICE__
/* under construction !*/
#endif
    VFX_OBJ_CREATE(m_setting[CONTACT_SETTING_EXTRA_NUMBER], VcpFormItemLauncherCell, m_form);
}


void VappContactSettingPage::componentPlace()
{
    m_setting[CONTACT_SETTING_STORAGE]->setMainText(STR_ID_VAPP_PHB_SETTING_STORAGE);
    m_hint = VappContactStorageProvider::getStorageString();
    m_setting[CONTACT_SETTING_STORAGE]->setHintText(m_hint);
    m_setting[CONTACT_SETTING_STORAGE]->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_form->addItem(m_setting[CONTACT_SETTING_STORAGE], CONTACT_SETTING_STORAGE);

#ifdef __MMI_PHB_LAST_NAME_FIELD__
    m_setting[CONTACT_SETTING_NAME_DISPLAY]->setMainText(STR_ID_VAPP_PHB_SETTING_NAME_DISPLAY);
    m_hint = VappContactNameDisplayProvider::getNameDisplayString();
    m_setting[CONTACT_SETTING_NAME_DISPLAY]->setHintText(m_hint);
    m_setting[CONTACT_SETTING_NAME_DISPLAY]->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_form->addItem(m_setting[CONTACT_SETTING_NAME_DISPLAY], CONTACT_SETTING_NAME_DISPLAY);
#endif /* __MMI_PHB_LAST_NAME_FIELD__ */

#ifdef __MMI_PHB_SPEED_DIAL__
    m_setting[CONTACT_SETTING_SPEED_DIAL]->setMainText(STR_ID_VAPP_PHB_SETTING_SPEED_DIAL);
    m_setting[CONTACT_SETTING_SPEED_DIAL]->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_form->addItem(m_setting[CONTACT_SETTING_SPEED_DIAL], CONTACT_SETTING_SPEED_DIAL);
#endif /* __MMI_PHB_SPEED_DIAL__ */ 

#ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
    m_switch->setMainText(STR_ID_VAPP_PHB_SETTING_SAVE_NOTIFY);
    m_switch->setSwitchStatus(VFX_TRUE);
    m_form->addItem(m_switch, CONTACT_SETTING_SAVE_NOTIFY);
#endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */

#if defined(__MMI_MULTI_VCARD__) || defined(__VCARD_CLOUD_SUPPORT__)
    m_setting[CONTACT_SETTING_BACKUP]->setMainText(VFX_WSTR_RES(STR_ID_VAPP_PHB_SETTING_BACKUP));
    m_form->addItem(m_setting[CONTACT_SETTING_BACKUP], CONTACT_SETTING_BACKUP);

    m_setting[CONTACT_SETTING_RESTORE]->setMainText(VFX_WSTR_RES(STR_ID_VAPP_PHB_SETTING_RESTORE));
#ifndef __VCARD_CLOUD_SUPPORT__
    m_setting[CONTACT_SETTING_RESTORE]->setAccessory(VCPFORM_NEXT_ITEM_ICON);
#endif
    m_form->addItem(m_setting[CONTACT_SETTING_RESTORE], CONTACT_SETTING_RESTORE);
#endif /* defined(__MMI_MULTI_VCARD__) || defined(__VCARD_CLOUD_SUPPORT__) */

#ifdef __VCARD_CLOUD_SUPPORT__
    srv_cloud_support_backup_restore_list(SRV_CLD_TYPE_VCARD, g_phb_cloud_provider.idList, &g_phb_cloud_provider.count);
#ifndef __MMI_MULTI_VCARD__
    if (g_phb_cloud_provider.count == 0)
    {
        m_setting[CONTACT_SETTING_BACKUP]->setIsDisabled(VFX_TRUE);
        m_setting[CONTACT_SETTING_RESTORE]->setIsDisabled(VFX_TRUE);
    }
#endif /* __MMI_MULTI_VCARD__ */
#endif /* __VCARD_CLOUD_SUPPORT__ */

    m_setting[CONTACT_SETTING_IMPORT]->setMainText(STR_ID_VAPP_PHB_SETTING_IMPORT);
    m_form->addItem(m_setting[CONTACT_SETTING_IMPORT], CONTACT_SETTING_IMPORT);

    if (srv_sim_ctrl_get_num_of_inserted() == 0
    #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        && !srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV)
    #endif
        )
    {
        m_setting[CONTACT_SETTING_IMPORT]->setIsDisabled(VFX_TRUE);
    }

    m_setting[CONTACT_SETTING_EXPORT]->setMainText(STR_ID_VAPP_PHB_SETTING_EXPORT);
    m_form->addItem(m_setting[CONTACT_SETTING_EXPORT], CONTACT_SETTING_EXPORT);

    if (srv_sim_ctrl_get_num_of_inserted() == 0
    #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        && !srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV)
    #endif
        )
    {
        m_setting[CONTACT_SETTING_EXPORT]->setIsDisabled(VFX_TRUE);
    }

#ifdef __MMI_SYNCML_APP_SYNC_MENU_SUPPORT__
    m_setting[CONTACT_SETTING_SYNC]->setMainText(VFX_WSTR_RES(STR_ID_VAPP_PHB_SETTING_SYNC));
    m_form->addItem(m_setting[CONTACT_SETTING_SYNC], CONTACT_SETTING_SYNC);
#endif /* __MMI_SYNCML_APP_SYNC_MENU_SUPPORT__ */

#ifdef __MMI_MOBILE_SERVICE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_MOBILE_SERVICE__ */

    m_setting[CONTACT_SETTING_EXTRA_NUMBER]->setMainText(STR_ID_VAPP_PHB_SETING_EXTRA);
    m_setting[CONTACT_SETTING_EXTRA_NUMBER]->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_form->addItem(m_setting[CONTACT_SETTING_EXTRA_NUMBER], CONTACT_SETTING_EXTRA_NUMBER);

    if (srv_sim_ctrl_get_num_of_inserted() == 0 ||
        (srv_sim_ctrl_get_num_of_inserted() == 1 && srv_sim_ctrl_get_one_available_sim() == 0) ||
        (srv_sim_ctrl_get_num_of_inserted() == 1 && (!srv_phb_startup_is_phb_support((U8) mmi_frm_sim_to_index((mmi_sim_enum) srv_sim_ctrl_get_one_available_sim()), PHB_FDN))))
    {
        m_setting[CONTACT_SETTING_EXTRA_NUMBER]->setIsDisabled(VFX_TRUE);
    }
}


void VappContactSettingPage::componentSetAction()
{
    for (VfxU32 i = CONTACT_SETTING_STORAGE; i < CONTACT_SETTING_END; i++)
    {
    #ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
        if (i != CONTACT_SETTING_SAVE_NOTIFY)
    #endif
        {
            m_setting[i]->m_signalTap.connect(this, &VappContactSettingPage::onButtonClicked);
        }
    }

#ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
    m_switch->m_signalSwitchChangeReq.connect(this, &VappContactSettingPage::onItemSwitchReq);
#endif
}


void VappContactSettingPage::onButtonClicked(VcpFormItemCell* sender, VfxId id)
{
    switch (id)
    {
        case CONTACT_SETTING_STORAGE:
        {
            VappContactStoragePage *page;
            VFX_OBJ_CREATE(page, VappContactStoragePage, getMainScr());
            getMainScr()->pushPageHandler(VFX_ID_NULL, page);
            page->m_signalStorageSave.connect(this, &VappContactSettingPage::onStorageChange);
            break;
        }
    #ifdef __MMI_PHB_LAST_NAME_FIELD__
        case CONTACT_SETTING_NAME_DISPLAY:
        {
            VappContactNameDisplayPage *page;
            VFX_OBJ_CREATE(page, VappContactNameDisplayPage, getMainScr());
            getMainScr()->pushPage(VFX_ID_NULL, page);
            page->m_signalNameDisplaySet.connect(this, &VappContactSettingPage::onNameDisplayChange);
            break;
        }
    #endif /* __MMI_PHB_LAST_NAME_FIELD__ */
    #ifdef __MMI_PHB_SPEED_DIAL__
        case CONTACT_SETTING_SPEED_DIAL:
        {
            VappContactSpeedDialPage *page;
            VFX_OBJ_CREATE(page, VappContactSpeedDialPage, getMainScr());
            getMainScr()->pushPage(VFX_ID_NULL, page);
            break;
        }
    #endif /* __MMI_PHB_SPEED_DIAL__ */    
        case CONTACT_SETTING_IMPORT:
        {
            VappContactMultiCopyPage *page;
            VFX_OBJ_CREATE_EX(page, VappContactMultiCopyPage, getMainScr(), (VFX_TRUE));
            break;
        }
        case CONTACT_SETTING_EXPORT:
        {
            VappContactMultiCopyPage *page;
            //VFX_OBJ_CREATE(page, VappContactExportPage, getMainScr());
            VFX_OBJ_CREATE_EX(page, VappContactMultiCopyPage, getMainScr(), (VFX_FALSE));
            break;
        }
    #if defined(__MMI_MULTI_VCARD__) || defined(__VCARD_CLOUD_SUPPORT__)
        case CONTACT_SETTING_BACKUP:
        {
        #ifdef __VCARD_CLOUD_SUPPORT__
            VappContactBackupPage *page;
            VFX_OBJ_CREATE(page, VappContactBackupPage, getMainScr());
        #else /* __VCARD_CLOUD_SUPPORT__ */
            if (PBBackUp::doCanRun())
            {
                PBBackUp *page;
                VfxMainScr *mainScr = getMainScr();
                VFX_OBJ_CREATE_EX(page, PBBackUp, mainScr, (mainScr));
            }
            else
            {
            #ifdef __MMI_USB_SUPPORT__
                if (srv_usb_is_in_mass_storage_mode())
                {
                    vapp_usb_unavailable_popup(0);
                }
                else
            #endif /* __MMI_USB_SUPPORT__ */
                {
                    VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
                    balloon->addItem(VCP_INFO_BALLOON_TYPE_INFO, VFX_WSTR_RES(STR_ID_VAPP_PHB_INSERT_MEMORY_CARD));
                }
            }
        #endif /* __VCARD_CLOUD_SUPPORT__ */
            break;
        }
        case CONTACT_SETTING_RESTORE:
        {
        #ifdef __VCARD_CLOUD_SUPPORT__
            VappContactRestorePage *page;
            VFX_OBJ_CREATE(page, VappContactRestorePage, getMainScr());
        #else /* __VCARD_CLOUD_SUPPORT__ */
            if (PBRestorePage::doCanRun())
            {
                PBRestorePage *page;
                VfxMainScr *mainScr = getMainScr();
                VFX_OBJ_CREATE_EX(page, PBRestorePage, mainScr, (mainScr, NULL));
                mainScr->pushPage(VFX_ID_NULL, page);
            }
            else
            {
            #ifdef __MMI_USB_SUPPORT__
                if (srv_usb_is_in_mass_storage_mode())
                {
                    vapp_usb_unavailable_popup(0);
                }
                else
            #endif /* __MMI_USB_SUPPORT__ */
                {
                    VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
                    balloon->addItem(VCP_INFO_BALLOON_TYPE_INFO, VFX_WSTR_RES(STR_ID_VAPP_PHB_INSERT_MEMORY_CARD));
                }
            }
        #endif /* __VCARD_CLOUD_SUPPORT__ */
            break;
        }
    #endif /* defined(__MMI_MULTI_VCARD__) || defined(__VCARD_CLOUD_SUPPORT__) */
    #ifdef __MMI_SYNCML_APP_SYNC_MENU_SUPPORT__
        case CONTACT_SETTING_SYNC:
        {
            mmi_id grpId = vcui_sync_create(getMainScr()->getGroupId(), NULL);
            if (grpId != GRP_ID_INVALID)
            {
                vcui_sync_set_database(grpId, 1);
                vcui_sync_run(grpId);
            }
            break;
        }
    #endif /* __MMI_SYNCML_APP_SYNC_MENU_SUPPORT__ */
    #ifdef __MMI_MOBILE_SERVICE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_MOBILE_SERVICE__ */
        case CONTACT_SETTING_EXTRA_NUMBER:
        {
            if (srv_sim_ctrl_get_num_of_inserted() >= 2)
            {
                VappContactSettingExtraSimSelect *page;
                VFX_OBJ_CREATE(page, VappContactSettingExtraSimSelect, getMainScr());
                getMainScr()->pushPageHandler(VFX_ID_NULL, page);
            }
            else
            {
                VappContactSettingFdnList *page;
                VFX_OBJ_CREATE_EX(page, VappContactSettingFdnList, getMainScr(), ((mmi_sim_enum) srv_sim_ctrl_get_one_available_sim()));
                getMainScr()->pushPage(VFX_ID_NULL, page);
            }
            break;
        }
    }
}


#ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
void VappContactSettingPage::onItemSwitchReq(VcpFormItemSwitchCell* obj, VfxId id, VfxBool value)
{
    obj->setSwitchStatus(value);
    SRV_CONTACT_SAVE_CONTACT_NOTIFY_ENUM type = (value) ? SRV_CONTACT_SAVE_CONTACT_NOTIFY_ON : SRV_CONTACT_SAVE_CONTACT_NOTIFY_OFF;
    srv_phb_set_save_notify(type);
}
#endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */


void VappContactSettingPage::onStorageChange()
{
    VcpFormItemLauncherCell *cell = (VcpFormItemLauncherCell *)m_form->getItem(CONTACT_SETTING_STORAGE);
    m_hint = VappContactStorageProvider::getStorageString();
    cell->setHintText(m_hint);
}


#ifdef __MMI_PHB_LAST_NAME_FIELD__
void VappContactSettingPage::onNameDisplayChange()
{
    VcpFormItemLauncherCell *cell = (VcpFormItemLauncherCell *)m_form->getItem(CONTACT_SETTING_NAME_DISPLAY);
    m_hint = VappContactNameDisplayProvider::getNameDisplayString();
    cell->setHintText(m_hint);
}
#endif /* __MMI_PHB_LAST_NAME_FIELD__ */

#ifdef __MMI_CONTACT_SLIM__
void VappContactSettingPage:: onDeinit()
{
    VfxPage::onDeinit();
    vcui_phb_contact_viewer_result_event_struct evt;
    VappContactSettingCUI *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VappContactSettingCUI);
    
    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CUI_PHB_SETTING_RESULT, cui->getGroupId());
  
    evt.result = 1;
    cui->postToCaller((mmi_group_event_struct*)&evt);
}
#endif
/***************************************************************************** 
 * Class VappContactStoragePage
 *****************************************************************************/
void VappContactStoragePage::onPageInit(VfxPageEx * page)
{
    VfxPageHandler::onPageInit(page);

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar,page);
    bar->setTitle(STR_ID_VAPP_PHB_SETTING_STORAGE);
    page->setTopBar(bar);

    VFX_OBJ_CREATE(m_list, VcpListMenu, page);
    VFX_OBJ_CREATE(m_listProvider, VappContactStorageProvider, page);

    VcpToolBar *bottom_bar;
    VFX_OBJ_CREATE(bottom_bar, VcpToolBar, page);
    bottom_bar->addItem(1, (VfxResId)(STR_GLOBAL_SAVE), VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
    bottom_bar->addItem(2, (VfxResId)(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    page->setBottomBar(bottom_bar);

    bottom_bar->m_signalButtonTap.connect(this, &VappContactStoragePage::onToolBarClicked);
    componentPlace();
    componentSetAction();
}


#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
mmi_ret VappContactStoragePage::onPageProc(VfxPageEx *page, mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
        case EVT_ID_USB_ENTER_MS_MODE:
        case EVT_ID_USB_EXIT_MS_MODE:
        {
            updateStorageList();
            break;
        }
        default:
            break;
    }
    
    return  VfxPageHandler::onPageProc(page, evt);
}


void VappContactStoragePage::updateStorageList()
{
    m_listProvider->updateProvider();
    m_list->resetAllItems();
}
#endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */


void VappContactStoragePage::componentPlace()
{
    m_list->setSize(getPage()->getSize());
    m_list->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    m_list->setContentProvider(m_listProvider);
    m_list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT);
    m_list->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION);
}


void VappContactStoragePage::componentSetAction()
{
    m_list->m_signalItemSelectionStateChanged.connect(this, &VappContactStoragePage::onSelectStateChange);
}


void VappContactStoragePage::onSelectStateChange(VcpListMenu *list, VfxU32 index, VcpListMenuItemStateEnum state)
{
    m_listProvider->setStorageState(list, index, state);
    if (!m_listProvider->isUserSelect())
    {
       ((VcpToolBar *)getPage()->getBar(VFX_PAGE_BAR_LOCATION_BOTTOM))->setDisableItem(1, VFX_TRUE);
    }
    else
    {
        ((VcpToolBar *)getPage()->getBar(VFX_PAGE_BAR_LOCATION_BOTTOM))->setDisableItem(1, VFX_FALSE);
    }
}


void VappContactStoragePage::onToolBarClicked(VfxObject *obj, VfxId id)
{
    if (id == 1)
    {
        if (m_listProvider->isUserSelect())
        {
            m_listProvider->setStorageDone();
            m_signalStorageSave.emit();
        }
    }
    getPage()->getMainScr()->popPage();
}


#ifdef __MMI_PHB_LAST_NAME_FIELD__
/***************************************************************************** 
 * Class VappContactNameDisplayPage
 *****************************************************************************/
void VappContactNameDisplayPage::onInit()
{
    VfxPage::onInit();

    componentInit();
    componentPlace();
    componentSetAction();
}


void VappContactNameDisplayPage::componentInit()
{
    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(STR_ID_VAPP_PHB_SETTING_NAME_DISPLAY);
    setTopBar(bar);

    VFX_OBJ_CREATE(m_list, VcpListMenu, this);
    VFX_OBJ_CREATE(m_listProvider, VappContactNameDisplayProvider, this);
}


void VappContactNameDisplayPage::componentPlace()
{
    m_list->setContentProvider(m_listProvider);
    m_list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_list->setMenuMode(VCP_LIST_MENU_MODE_SINGLE_SELECTION);
    m_list->setSize(getSize());
    m_list->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
}


void VappContactNameDisplayPage::componentSetAction()
{
    m_list->m_signalItemTapped.connect(this, &VappContactNameDisplayPage::itemTapped);
}


void VappContactNameDisplayPage::itemTapped(VcpListMenu *list, VfxU32 index)
{
    VfxBool sync = VFX_FALSE;

    if (index == 0)
    {
        if (srv_phb_set_name_display(SRV_CONTACT_NAME_DISPLAY_TYPE_1, &VappContactNameDisplayPage::asycProcessing) != MMI_FALSE)
        {
            sync = VFX_TRUE;
        }
    }
    else if (index == 1)
    {
        if (srv_phb_set_name_display(SRV_CONTACT_NAME_DISPLAY_TYPE_3, &VappContactNameDisplayPage::asycProcessing) != MMI_FALSE)
        {
            sync = VFX_TRUE;
        }
    }
    else
    {
        VFX_ASSERT(0);
        return;
    }

    m_signalNameDisplaySet.emit();

    if (sync)
    {
        getMainScr()->popPage();
    }
    else
    {
        VFX_OBJ_CREATE(m_commandPopup, VcpCommandPopup, this);
        m_commandPopup->setInfoType(VCP_POPUP_TYPE_PROGRESS);
        m_commandPopup->setText(STR_ID_VAPP_PHB_SETTING_PROCESSING);
    }
}


void VappContactNameDisplayPage::asycProcessing(void *user_data)
{
    VappContactNameDisplayPage *op = (VappContactNameDisplayPage *)user_data;
    op->getMainScr()->popPage();
}
#endif /* __MMI_PHB_LAST_NAME_FIELD__ */
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
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
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
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
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
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
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__  // reset storage
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

VappContactMultiCopyPage::VappContactMultiCopyPage (VfxBool isImport)
    :m_isImport(isImport)
{
}


void VappContactMultiCopyPage::onInit()
{
    VfxPage::onInit();
    
       VcpCommandPopup *option;
       VFX_OBJ_CREATE(option, VcpCommandPopup, this);
    
       option->setInfoType(VCP_POPUP_TYPE_INFO);
       if(m_isImport)
        {
            option->setText(STR_ID_VAPP_PHB_IMPORT_FROM);
        }
       else
        {
            option->setText(STR_ID_VAPP_PHB_EXPORT_TO);
        }
       
    
       for (VfxU32 i = 0; i < ContactSim::getTotal(); i++)
       {
           mmi_sim_enum sim = mmi_frm_index_to_sim(i);
           if (srv_sim_ctrl_is_inserted(sim))
           {
               option->addItem(CONTACT_SETTING_IMPORT_OR_EXPORT_SIM + i, ContactSim::getName(sim));
               if (!srv_sim_ctrl_is_available(sim))
               {
                   option->disableItem(CONTACT_SETTING_IMPORT_OR_EXPORT_SIM + i);
               }
           }
       }

#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    if (srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV))
    {
        option->addItem(CONTACT_SETTING_EXPORT_TCARD, ContactStorage::getName(PHB_STORAGE_TCARD));
    }
#endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */
    
       option->addItem(CONTACT_SETTING_IMPORT_OR_EXPORT_END, (VfxResId)(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);
    
       option->m_signalButtonClicked.connect(this, &VappContactMultiCopyPage::onBtnClicked);
    
       option->show(VFX_TRUE);

}


void VappContactMultiCopyPage::onBtnClicked(VfxObject *obj, VfxId id)
{
    if (id >= CONTACT_SETTING_IMPORT_OR_EXPORT_END)
    {
        return;
    }
    phb_storage_enum storage;
    phb_storage_enum check_storage;
        // check storage status
    storage = (phb_storage_enum) (PHB_STORAGE_SIM + (id - CONTACT_SETTING_IMPORT_OR_EXPORT_SIM));
#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__  // reset storage
    if (CONTACT_SETTING_EXPORT_TCARD == id)
    {
        storage = PHB_STORAGE_TCARD;
    }
#endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */
    // check storage status
    if (m_isImport)
    {
        check_storage = PHB_STORAGE_NVRAM;
    }
    else 
    {
        check_storage = storage;
    }

    STORAGE_STATUS status = ContactStorage::getStatus(check_storage);
    VfxWString errorStr;

    if (status == STORAGE_NOT_ACCESSABLE)
    {
        errorStr = ContactStorage::getName(check_storage);
        errorStr += VFX_WSTR_RES(STR_ID_VAPP_PHB_STORAGE_IS_UNAVAILABLE);
    }
    else if (status == STORAGE_FULL)
    {
        errorStr = ContactStorage::getName(check_storage);
        errorStr += VFX_WSTR_RES(STR_ID_VAPP_PHB_STORAGE_IS_FULL);
    }

    if (!errorStr.isEmpty())
    {
        VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
        balloon->addItem(VCP_INFO_BALLOON_TYPE_FAILURE, errorStr);
    }
    else
    {
        VappPhbMultiCopyObj *multicpObj;
        if (m_isImport)
        {
          //  VappPhbMarkImportObj *importObj;
            VFX_OBJ_CREATE_EX(multicpObj, VappPhbMultiCopyObj, getMainScr(), (PHB_STORAGE_NVRAM, 
            storage, VFX_TRUE, getMainScr()));
        }
        else 
        {
            VFX_OBJ_CREATE_EX(multicpObj, VappPhbMultiCopyObj, getMainScr(), (storage, 
            PHB_STORAGE_NVRAM, VFX_FALSE, getMainScr()));

        }
      //VappPhbMarkExportObj *exportObj;
      
    }
}



#ifdef __VCARD_CLOUD_SUPPORT__
/***************************************************************************** 
 * Class VappContactBackupPage
 *****************************************************************************/
void VappContactBackupPage::onInit()
{
    VfxPage::onInit();

    VcpMenuPopup *option;
    VFX_OBJ_CREATE(option, VcpMenuPopup, getMainScr());

    option->setTitle(VFX_WSTR_RES(STR_ID_VAPP_PHB_BACKUP_TO));

#ifdef __MMI_MULTI_VCARD__
    option->addItem(VAPP_PHB_BACKUP_TO_MEMORY_CARD, VFX_WSTR_RES(STR_ID_VAPP_PHB_MEMORY_CARD), VCP_MENU_POPUP_ITEM_TYPE_2);

   // option->addItem(VAPP_PHB_BACKUP_TO_MEMORY_CARD, VFX_WSTR_RES(STR_ID_VAPP_PHB_MEMORY_CARD), ContactStorage::getIconEx(PHB_STORAGE_TCARD), VCP_MENU_POPUP_ITEM_TYPE_2);
   // ((VcpMenuPopupItemType2 *)option->getItemById(VAPP_PHB_BACKUP_TO_MEMORY_CARD))->setHintText(VFX_WSTR("Myler test"));
#endif
    srv_cloud_support_backup_restore_list(SRV_CLD_TYPE_VCARD, g_phb_cloud_provider.idList, &g_phb_cloud_provider.count);
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[VAPP_CONTACT_BACKUP_RESTORE]backup-srv_cloud_support_backup_restore_list--count: %d, cloud_enum: %d\n",
                g_phb_cloud_provider.count, SRV_CLD_TYPE_VCARD);

    for (VfxS32 i = 0; (i < g_phb_cloud_provider.count) && srv_sso_is_ready(); i++)
    {
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[VAPP_CONTACT_BACKUP_RESTORE][BackupInit]g_phb_cloud_provider--count: %d, i: %d, provider: %d\n", 
                    g_phb_cloud_provider.count, i, g_phb_cloud_provider.idList[i]);

        VfxWChar name[SRV_SSO_NAME_SIZE + 1];
        VfxWChar *icon = NULL;

        memset(name, 0, sizeof(name));
        if (srv_sso_get_provider_name(g_phb_cloud_provider.idList[i], name))
        {
            icon = srv_sso_get_provider_icon(g_phb_cloud_provider.idList[i], SRV_SSO_ICON_SMALL);
           // option->addItem(VAPP_PHB_BACKUP_TO_YAHOO + i, VFX_WSTR_MEM(name), VfxImageSrc(VFX_WSTR_MEM(icon)), VCP_MENU_POPUP_ITEM_TYPE_2);
            option->addItem(VAPP_PHB_BACKUP_TO_YAHOO + i, VFX_WSTR_MEM(name), VCP_MENU_POPUP_ITEM_TYPE_2);

            memset(name, 0, sizeof(name));
            if (srv_sso_get_account_count(g_phb_cloud_provider.idList[i], SRV_SSO_LOGIN_TRUE))
            {
                srv_sso_account_struct userAccount;
                srv_sso_get_accounts(g_phb_cloud_provider.idList[i], SRV_SSO_LOGIN_TRUE, &userAccount, 1);
                if (srv_sso_get_account_name(g_phb_cloud_provider.idList[i], userAccount.account, (WCHAR *)name) == MMI_TRUE)
                {
                    ((VcpMenuPopupItemType2 *)option->getItemById(VAPP_PHB_BACKUP_TO_YAHOO + i))->setHintText(VFX_WSTR_MEM(name));
                    ((VcpMenuPopupItemType2 *)option->getItemById(VAPP_PHB_BACKUP_TO_YAHOO + i))->setHintTextPlacement(VCP_MENU_POPUP_ITEM_TYPE2_HINT_PLACEMENT_BOTTOM);
                }
            }
        }
        else
        {
            option->addItem(VAPP_PHB_BACKUP_TO_YAHOO + i, VFX_WSTR_RES(STR_ID_VAPP_PHB_CLOUD_YAHOO_SERVICE));
        }
    }

    option->show(VFX_TRUE);
    option->m_signalMenuCallback.connect(this, &VappContactBackupPage::onContextMenuSelected);
}


mmi_ret VappContactBackupPage::onProc(mmi_event_struct *evt)
{
    MMI_TRACE(MMI_COMMON_TRC_G4_PHB, VAPP_CONTACT_BACKUP_ONPROC, evt->evt_id);
    switch (evt->evt_id)
    {
        case EVT_ID_VCUI_SSO_LOGIN_RESULT:
        {
            vcui_sso_login_result_event_struct *cloud_evt = (vcui_sso_login_result_event_struct*)evt;
            MMI_TRACE(MMI_COMMON_TRC_G4_PHB, VAPP_CONTACT_BACKUP_CLOUD_LOGIN, cloud_evt->result, cloud_evt->accountId, cloud_evt->providerId, cloud_evt->err);
            if (cloud_evt->result == VCUI_SSO_LOGIN_SUCCESS || cloud_evt->result == VCUI_SSO_LOGIN_ADD_SUCCESS)
            {
                PBBackUp *page;
                VfxMainScr *mainScr = getMainScr();
                VFX_OBJ_CREATE_EX(page, PBBackUp, mainScr, (mainScr, cloud_evt->providerId, cloud_evt->accountId));
                page->m_signalBackUpDone.connect(this, &VappContactBackupPage::backUpDone);
            }
            else
            {
            }
            vcui_sso_login_close(cloud_evt->sender_id);
            break;
        }
    }

    return VfxPage::onProc(evt);
}


void VappContactBackupPage::onContextMenuSelected(VcpMenuPopup* popup, VcpMenuPopupEventEnum flag, VcpMenuPopupItem* item)
{
    if (flag != VCP_MENU_POPUP_EVENT_ITEM_SELECTED)
    {
        return;
    }

#ifdef __MMI_MULTI_VCARD__
    if (item->getId() == VAPP_PHB_BACKUP_TO_MEMORY_CARD)
    {
        if (PBBackUp::doCanRun())
        {
            PBBackUp *page;
            VfxMainScr *mainScr = getMainScr();
            VFX_OBJ_CREATE_EX(page, PBBackUp, mainScr, (mainScr));
            page->m_signalBackUpDone.connect(this, &VappContactBackupPage::backUpDone);
        }
        else
        {
        #ifdef __MMI_USB_SUPPORT__
            if (srv_usb_is_in_mass_storage_mode())
            {
                vapp_usb_unavailable_popup(0);
            }
            else
        #endif /* __MMI_USB_SUPPORT__ */
            {
                VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
                balloon->addItem(VCP_INFO_BALLOON_TYPE_INFO, VFX_WSTR_RES(STR_ID_VAPP_PHB_INSERT_MEMORY_CARD));
            }
        }
    }
    else
#endif /* __MMI_MULTI_VCARD__ */
    if (item->getId() < (VfxU32) (VAPP_PHB_BACKUP_TO_YAHOO + g_phb_cloud_provider.count))
    {
        login(g_phb_cloud_provider.idList[item->getId() - VAPP_PHB_BACKUP_TO_YAHOO]);
    }
}


void VappContactBackupPage::login(VfxU32 providerId)
{
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[VAPP_CONTACT_BACKUP_RESTORE][BackupLogin]login--providerId: %d\n", providerId);

    if (srv_sso_get_account_count(providerId, SRV_SSO_LOGIN_TRUE))
    {
        VfxS32 ret = srv_sso_get_account_count(providerId, SRV_SSO_LOGIN_TRUE);

        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[VAPP_CONTACT_BACKUP_RESTORE][BackupLogin]loginState: %d, providerId: %d, srv_sso_get_account_count()--ret: %d\n", 
                    SRV_SSO_LOGIN_TRUE, providerId, ret);

        srv_sso_account_struct userAccount;
        srv_sso_get_accounts(providerId, SRV_SSO_LOGIN_TRUE, &userAccount, 1);

        PBBackUp *page;
        VfxMainScr *mainScr = getMainScr();
        VFX_OBJ_CREATE_EX(page, PBBackUp, mainScr, (mainScr, providerId, userAccount.account));
        page->m_signalBackUpDone.connect(this, &VappContactBackupPage::backUpDone);
    }
    else if (srv_sso_get_account_count(providerId, SRV_SSO_LOGIN_FALSE))
    {
        VfxS32 ret = srv_sso_get_account_count(providerId, SRV_SSO_LOGIN_FALSE);

        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[VAPP_CONTACT_BACKUP_RESTORE][BackupLogin]loginState: %d, providerId: %d, srv_sso_get_account_count()--ret: %d\n", 
                    SRV_SSO_LOGIN_FALSE, providerId, ret);

        srv_sso_account_struct userAccount;
        srv_sso_get_accounts(providerId, SRV_SSO_LOGIN_FALSE, &userAccount, 1);
        mmi_id grpId = vcui_sso_login_create(getMainScr()->getGroupId(), providerId, userAccount.account);
        mmi_frm_group_set_caller_proc(grpId, &VappContactBackupPage::listen, getObjHandle());
        vcui_sso_login_run(grpId);
    }
    else
    {
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[VAPP_CONTACT_BACKUP_RESTORE][BackupLogin]else--providerId: %d\n", providerId);

        mmi_id grpId = vcui_sso_login_create(getMainScr()->getGroupId(), providerId, SRV_SSO_INVALID_ACC_ID);
        mmi_frm_group_set_caller_proc(grpId, &VappContactBackupPage::listen, getObjHandle());
        vcui_sso_login_run(grpId);
    }
}


mmi_ret VappContactBackupPage::listen(mmi_event_struct *evt)
{
    VappContactBackupPage *pThis = (VappContactBackupPage*)handleToObject((VfxObjHandle)(evt->user_data));
    if(NULL == pThis)
    {
        return MMI_RET_OK;
    }
    return pThis->onProc(evt);
}


void VappContactBackupPage::backUpDone()
{
    closeSelf();
}


void VappContactBackupPage::closeSelf()
{
    VfxObject *obj = this;
    VFX_OBJ_CLOSE(obj);
}


/***************************************************************************** 
 * Class VappContactRestorePage
 *****************************************************************************/
void VappContactRestorePage::onInit()
{
    VfxPage::onInit();

    VcpMenuPopup *option;
    VFX_OBJ_CREATE(option, VcpMenuPopup, getMainScr());

    option->setTitle(VFX_WSTR_RES(STR_ID_VAPP_PHB_RESTORE_FROM));

#ifdef __MMI_MULTI_VCARD__
    option->addItem(VAPP_PHB_RESTORE_FROM_MEMORY_CARD, VFX_WSTR_RES(STR_ID_VAPP_PHB_MEMORY_CARD), VCP_MENU_POPUP_ITEM_TYPE_2);

   // option->addItem(VAPP_PHB_RESTORE_FROM_MEMORY_CARD, VFX_WSTR_RES(STR_ID_VAPP_PHB_MEMORY_CARD), ContactStorage::getIconEx(PHB_STORAGE_TCARD), VCP_MENU_POPUP_ITEM_TYPE_2);
#endif
    srv_cloud_support_backup_restore_list(SRV_CLD_TYPE_VCARD, g_phb_cloud_provider.idList, &g_phb_cloud_provider.count);
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[VAPP_CONTACT_BACKUP_RESTORE]restore-srv_cloud_support_backup_restore_list--count: %d, cloud_enum: %d\n",
                g_phb_cloud_provider.count, SRV_CLD_TYPE_VCARD);

    for (VfxS32 i = 0; (i < g_phb_cloud_provider.count) && srv_sso_is_ready(); i++)
    {
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[VAPP_CONTACT_BACKUP_RESTORE][RestoreInit]g_phb_cloud_provider--count: %d, i: %d, provider: %d\n", 
                    g_phb_cloud_provider.count, i, g_phb_cloud_provider.idList[i]);

        VfxWChar name[SRV_SSO_NAME_SIZE + 1];
        VfxWChar *icon = NULL;

        memset(name, 0, sizeof(name));
        if (srv_sso_get_provider_name(g_phb_cloud_provider.idList[i], name))
        {
            icon = srv_sso_get_provider_icon(g_phb_cloud_provider.idList[i], SRV_SSO_ICON_SMALL);
          //  option->addItem(VAPP_PHB_RESTORE_FROM_YAHOO + i, VFX_WSTR_MEM(name), VfxImageSrc(VFX_WSTR_MEM(icon)), VCP_MENU_POPUP_ITEM_TYPE_2);
            option->addItem(VAPP_PHB_RESTORE_FROM_YAHOO + i, VFX_WSTR_MEM(name), VCP_MENU_POPUP_ITEM_TYPE_2);

            memset(name, 0, sizeof(name));
            if (srv_sso_get_account_count(g_phb_cloud_provider.idList[i], SRV_SSO_LOGIN_TRUE))
            {
                srv_sso_account_struct userAccount;
                srv_sso_get_accounts(g_phb_cloud_provider.idList[i], SRV_SSO_LOGIN_TRUE, &userAccount, 1);
                if (srv_sso_get_account_name(g_phb_cloud_provider.idList[i], userAccount.account, (WCHAR *)name) == MMI_TRUE)
                {
                    ((VcpMenuPopupItemType2 *)option->getItemById(VAPP_PHB_RESTORE_FROM_YAHOO + i))->setHintText(VFX_WSTR_MEM(name));
                    ((VcpMenuPopupItemType2 *)option->getItemById(VAPP_PHB_RESTORE_FROM_YAHOO + i))->setHintTextPlacement(VCP_MENU_POPUP_ITEM_TYPE2_HINT_PLACEMENT_BOTTOM);
                }
            }
        }
        else
        {
            option->addItem(VAPP_PHB_RESTORE_FROM_YAHOO + i, VFX_WSTR_RES(STR_ID_VAPP_PHB_CLOUD_YAHOO_SERVICE));
        }
    }

    option->show(VFX_TRUE);
    option->m_signalMenuCallback.connect(this, &VappContactRestorePage::onContextMenuSelected);
}


mmi_ret VappContactRestorePage::onProc(mmi_event_struct *evt)
{
    MMI_TRACE(MMI_COMMON_TRC_G4_PHB, VAPP_CONTACT_RESTORE_ONPROC, evt->evt_id);
    switch (evt->evt_id)
    {
        case EVT_ID_VCUI_SSO_LOGIN_RESULT:
        {
            vcui_sso_login_result_event_struct *cloud_evt = (vcui_sso_login_result_event_struct*)evt;
            MMI_TRACE(MMI_COMMON_TRC_G4_PHB, VAPP_CONTACT_RESTORE_CLOUD_LOGIN, cloud_evt->result, cloud_evt->accountId, cloud_evt->providerId, cloud_evt->err);
            if (cloud_evt->result == VCUI_SSO_LOGIN_SUCCESS || cloud_evt->result == VCUI_SSO_LOGIN_ADD_SUCCESS)
            {
                PBRestore *page;
                VfxMainScr *mainScr = getMainScr();
                VFX_OBJ_CREATE_EX(page, PBRestore, mainScr, (mainScr, cloud_evt->providerId, cloud_evt->accountId));
                page->m_signalRestoreDone.connect(this, &VappContactRestorePage::RestoreDone);
            }
            else
            {
            }
            vcui_sso_login_close(cloud_evt->sender_id);
            break;
        }
    }

    return VfxPage::onProc(evt);
}


void VappContactRestorePage::onContextMenuSelected(VcpMenuPopup* popup, VcpMenuPopupEventEnum flag, VcpMenuPopupItem* item)
{
    if (flag != VCP_MENU_POPUP_EVENT_ITEM_SELECTED)
    {
        return;
    }

#ifdef __MMI_MULTI_VCARD__
    if (item->getId() == VAPP_PHB_RESTORE_FROM_MEMORY_CARD)
    {
        if (PBRestorePage::doCanRun())
        {
            PBRestorePage *page;
            VfxMainScr *mainScr = getMainScr();
            VFX_OBJ_CREATE_EX(page, PBRestorePage, mainScr, (mainScr, NULL));
            mainScr->pushPage(VFX_ID_NULL, page);
            closeSelf();
        }
        else
        {
        #ifdef __MMI_USB_SUPPORT__
            if (srv_usb_is_in_mass_storage_mode())
            {
                vapp_usb_unavailable_popup(0);
            }
            else
        #endif /* __MMI_USB_SUPPORT__ */
            {
                VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
                balloon->addItem(VCP_INFO_BALLOON_TYPE_INFO, VFX_WSTR_RES(STR_ID_VAPP_PHB_INSERT_MEMORY_CARD));
            }
        }
    }
    else
#endif /* __MMI_MULTI_VCARD__ */
    if (item->getId() < (VfxU32) (VAPP_PHB_RESTORE_FROM_YAHOO + g_phb_cloud_provider.count))
    {
        login(g_phb_cloud_provider.idList[item->getId() - VAPP_PHB_RESTORE_FROM_YAHOO]);
    }
}


void VappContactRestorePage::login(VfxU32 providerId)
{
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[VAPP_CONTACT_BACKUP_RESTORE][RestoreLogin]login--providerId: %d\n", providerId);

    if (srv_sso_get_account_count(providerId, SRV_SSO_LOGIN_TRUE))
    {
        VfxS32 ret = srv_sso_get_account_count(providerId, SRV_SSO_LOGIN_TRUE);

        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[VAPP_CONTACT_BACKUP_RESTORE][RestoreLogin]loginState: %d, providerId: %d, srv_sso_get_account_count()--ret: %d\n",
                    SRV_SSO_LOGIN_TRUE, providerId, ret);

        srv_sso_account_struct userAccount;
        srv_sso_get_accounts(providerId, SRV_SSO_LOGIN_TRUE, &userAccount, 1);

        PBRestore *page;
        VfxMainScr *mainScr = getMainScr();
        VFX_OBJ_CREATE_EX(page, PBRestore, mainScr, (mainScr, providerId, userAccount.account));
        page->m_signalRestoreDone.connect(this, &VappContactRestorePage::RestoreDone);
    }
    else if (srv_sso_get_account_count(providerId, SRV_SSO_LOGIN_FALSE))
    {
        VfxS32 ret = srv_sso_get_account_count(providerId, SRV_SSO_LOGIN_FALSE);

        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[VAPP_CONTACT_BACKUP_RESTORE][RestoreLogin]loginState: %d, providerId: %d, srv_sso_get_account_count()--ret: %d\n",
                    SRV_SSO_LOGIN_FALSE, providerId, ret);

        srv_sso_account_struct userAccount;
        srv_sso_get_accounts(providerId, SRV_SSO_LOGIN_FALSE, &userAccount, 1);
        mmi_id grpId = vcui_sso_login_create(getMainScr()->getGroupId(), providerId, userAccount.account);
        mmi_frm_group_set_caller_proc(grpId, &VappContactRestorePage::listen, getObjHandle());
        vcui_sso_login_run(grpId);
    }
    else
    {
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[VAPP_CONTACT_BACKUP_RESTORE][RestoreLogin]else--providerId: %d\n", providerId);

        mmi_id grpId = vcui_sso_login_create(getMainScr()->getGroupId(), providerId, SRV_SSO_INVALID_ACC_ID);
        mmi_frm_group_set_caller_proc(grpId, &VappContactRestorePage::listen, getObjHandle());
        vcui_sso_login_run(grpId);
    }
}


mmi_ret VappContactRestorePage::listen(mmi_event_struct *evt)
{
    VappContactRestorePage *pThis = (VappContactRestorePage*)handleToObject((VfxObjHandle)(evt->user_data));
    if(NULL == pThis)
    {
        return MMI_RET_OK;
    }
    return pThis->onProc(evt);
}


void VappContactRestorePage::RestoreDone()
{
    closeSelf();
}


void VappContactRestorePage::closeSelf()
{
    VfxObject *obj = this;
    VFX_OBJ_CLOSE(obj);
}
#endif /* __VCARD_CLOUD_SUPPORT__ */


void VappContactSettingLaunch(VfxMainScr* screen)
{
    if (!vapp_phb_check_ready() || vapp_phb_check_processing())
    {
        VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
        balloon->addItem(VCP_INFO_BALLOON_TYPE_INFO, VFX_WSTR_RES(STR_ID_VAPP_PHB_PROCESSING));
        return;
    }
    else
    {
        VfxApp *app = VfxAppLauncher::findApp(
                            VCUI_CONTACT_SETTING,
                            VFX_OBJ_CLASS_INFO(VappContactSettingCUI),
                            VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG | VFX_APP_LAUNACHER_FIND_APP_BG_FLAG);
        if (app)
        {
            VfxAppLauncher::terminate(app->getGroupId());
        }

        VfxAppLauncher::launch(
            VCUI_CONTACT_SETTING,
            VFX_OBJ_CLASS_INFO(VappContactSettingCUI),
            mmi_frm_group_get_active_id(),
            NULL,
            0);
    }
}

#ifdef __MMI_CONTACT_SLIM__
mmi_id vcui_phb_setting_create(mmi_id parent_id)
{
    if (!vapp_phb_check_ready() || vapp_phb_check_processing())
    {
          VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
          balloon->addItem(VCP_INFO_BALLOON_TYPE_INFO, VFX_WSTR_RES(STR_ID_VAPP_PHB_PROCESSING));
          return  GRP_ID_INVALID;
    }

    if (!vapp_phb_ready_balloon())
    {
        return GRP_ID_INVALID;
    }
            
    mmi_id cui_id = VfxAppLauncher::createCui(
                        VCUI_CONTACT_SETTING,
                        VFX_OBJ_CLASS_INFO(VappContactSettingCUI),
                         parent_id);
                return cui_id;
}

void vcui_phb_setting_run(mmi_id cui_id)
{
    VfxAppLauncher::runCui(cui_id);
}

void vcui_phb_setting_close(mmi_id cui_id)
{
    VfxAppLauncher::terminate(cui_id);
}
#endif
