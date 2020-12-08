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
 *  vapp_phb_backup_restore.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#if defined(__MMI_MULTI_VCARD__) || defined(__VCARD_CLOUD_SUPPORT__)

#include "vapp_phb_backup_restore.h"
#include "mmi_rp_vapp_contact_def.h"
#include "mmi_rp_app_usbsrv_def.h"
#ifdef __VCARD_CLOUD_SUPPORT__
#include "vapp_phb_setting.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#include "wgui_categories_util.h"
#include "GlobalResDef.h"
#include "PhbSrvGprot.h"
#include "FileMgrSrvGprot.h"
#include "GpioSrvGprot.h"
#ifdef __VCARD_CLOUD_SUPPORT__
#include "CloudSrvGprot.h"
#endif

#ifdef __cplusplus
}
#endif

static ContactBackUp        vapp_phb_backup_g;
static ContactRestore       vapp_phb_restore_g;
static ContactDeleteAll     vapp_phb_deleteall_g;
static VfxBool              vapp_phb_is_BG_run;

/***************************************************************************** 
 * Class PBBackUp
 *****************************************************************************/ 
void PBBackUp::onInit()
{
    VfxObject::onInit();

    vapp_phb_is_BG_run = VFX_FALSE;

#ifdef __MMI_MULTI_VCARD__
    if (!m_cloud)
    {
        VFX_OBJ_CREATE(m_configManage, ContactConfigManager, m_parent);

        if (m_configManage->isFileError())
        {
            vfxPostInvoke(this, &PBBackUp::closeSelf, this);
            return;
        }

        if (m_configManage->isBackUpFull())
        {
            VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
            balloon->addItem(
                VCP_INFO_BALLOON_TYPE_INFO,
                VFX_WSTR_RES(STR_ID_VAPP_PHB_BACKUP_FULL));
            vfxPostInvoke(this, &PBBackUp::closeSelf, this);
            return;
        }
    }
#endif /*__MMI_MULTI_VCARD__ */

    VFX_OBJ_CREATE(m_progress, VcpIndicatorPopup, m_parent);

    m_progress->setInfoType(VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON);
    if (m_cloud)
    {
        m_progress->setText(VFX_WSTR_RES(STR_ID_VAPP_PHB_CLOUD_BACKUPING));
    }
    else
    {
        m_progress->setText(VFX_WSTR_RES(STR_ID_VAPP_PHB_BACKUPING));
    }
    m_progress->setProgress(0);
    m_progress->show(VFX_TRUE);
    m_progress->m_signalCanceled.connect(this, &PBBackUp::onCancelClick);

    m_backUp = &vapp_phb_backup_g;
#ifdef __MMI_MULTI_VCARD__
    if (!m_cloud)
    {
        vapp_phb_backup_g.setPath(m_configManage->getFilePath());
    #ifdef __VCARD_CLOUD_SUPPORT__
        vapp_phb_backup_g.setMode(SRV_PHB_BACKUP_RESTORE_MODE_T_CARD);
    #endif
    }
    else
#endif /* __MMI_MULTI_VCARD__ */
    {
    #ifdef __VCARD_CLOUD_SUPPORT__
      //  vapp_phb_backup_g.setPath(ContactConfigManager().getFilePath()); // check this??
        vapp_phb_backup_g.setMode(SRV_PHB_BACKUP_RESTORE_MODE_CLOUD);
        vapp_phb_backup_g.setProvideId(m_providerId);
        vapp_phb_backup_g.setAccountId(m_accountId);
        vapp_phb_backup_g.setMallocFunc(&VappContactSettingCUI::memAllocator);
        vapp_phb_backup_g.setFreeFunc(&VappContactSettingCUI::memDeallocator);
    #endif /* __VCARD_CLOUD_SUPPORT__ */
    }
    vapp_phb_backup_g.setUserData(this);
    vapp_phb_backup_g.setCB(&PBBackUp::onBackUpCB);

    if (m_backUp->prepare(CONTACT_BACKUP, CONTACT_WANT) == CONTACT_RUN)
    {
        m_backUp->run();
        wgui_status_icon_bar_show_icon(STATUS_ICON_CONTACTS_BACKUP);
    }
}


void PBBackUp::onDeinit()
{
    m_progress = NULL;
    vapp_phb_is_BG_run = VFX_TRUE;

    if (m_backUp)
    {
        m_backUp->complete();
        wgui_status_icon_bar_hide_icon(STATUS_ICON_CONTACTS_BACKUP);
    }
    m_backUp = NULL;
    // operation done
    m_signalBackUpDone.postEmit();

    VfxObject::onDeinit();
}


VfxBool PBBackUp::doCanRun()
{
    VfxBool result = VFX_TRUE;

    if (!srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV))
    {
        result = VFX_FALSE;
    }

    return result;
}


void PBBackUp::onBackUpCB(ContactOP* op, CONTACT_STATE state, srv_phb_async_op_cb_struct* result)
{
    if (result->type == SRV_PHB_OP_CB_TYPE_BACKUP)
    {
        srv_phb_backup_cb_struct *backUpFinish = (srv_phb_backup_cb_struct *)result;
        PBBackUp *obj = (PBBackUp *)(vapp_phb_backup_g.getUserData());
        MMI_TRACE(MMI_COMMON_TRC_G4_PHB, VAPP_CONTACT_BACKUP_DONE, obj->m_cloud, backUpFinish->type, backUpFinish->finish_count,
                    backUpFinish->fail_count, backUpFinish->total_count, backUpFinish->user_data, backUpFinish->result);

        if (obj->m_progress && !vapp_phb_is_BG_run)
        {
        #ifdef __MMI_MULTI_VCARD__
            if (!obj->m_cloud && backUpFinish->finish_count > 0 && backUpFinish->finish_count == backUpFinish->total_count)
            {
                obj->m_configManage->setFileConfigure(backUpFinish->finish_count);
            }
        #endif /* __MMI_MULTI_VCARD__ */
            // obj->terminate();
            // delay 250ms before close progress
            VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
            renderer->blockAfterNextCommit(300, VfxCallback0(obj, &PBBackUp::onBackupDone));
        }
        else
        {
        #ifdef __MMI_MULTI_VCARD__
            if (!obj->m_cloud && backUpFinish->finish_count > 0 && backUpFinish->finish_count == backUpFinish->total_count)
            {
                obj->m_configManage->setFileConfigure(backUpFinish->finish_count);
            }
        #endif /* __MMI_MULTI_VCARD__ */
            vapp_phb_backup_g.complete();
        }

        VfxWString temp;
        VfxWString success_count;
        VfxWString total_count;
    
        success_count.format("%d ", backUpFinish->finish_count);
        total_count.format(" %d ", vapp_phb_restore_g.m_totalCount);
        temp += success_count;
        temp += VFX_WSTR_RES(STR_ID_VAPP_PHB_SUCCESS);
        temp += VFX_WSTR(", ");
        temp += VFX_WSTR_RES(STR_ID_VAPP_PHB_TOTAL);
        temp += total_count;
        if (vapp_phb_restore_g.m_totalCount == 1)
        {
            temp += VFX_WSTR_RES(VAPP_PHB_STR_CONTACT_APPEND);
        }
        else
        {
            temp += VFX_WSTR_RES(VAPP_PHB_STR_CONTACTS_APPEND);
        }

        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_GENERAL, MMI_EVENT_CONTACT_BACKUP_ERROR, MMI_NMGR_BALLOON_TYPE_INFO, temp);
        wgui_status_icon_bar_hide_icon(STATUS_ICON_CONTACTS_BACKUP);

        if (0 == backUpFinish->total_count && !obj->m_cloud)
        {
            VfxWString errorStr = VFX_WSTR_RES(VAPP_PHB_STR_PHONE);
            errorStr += VFX_WSTR_RES(STR_ID_VAPP_PHB_STORAGE_IS_EMPTY);
            VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
            balloon->addItem(VCP_INFO_BALLOON_TYPE_WARNING, errorStr);
        }
        else if (backUpFinish->result == FS_DISK_FULL && !obj->m_cloud)
        {
            VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
            balloon->addItem(VCP_INFO_BALLOON_TYPE_WARNING, VFX_WSTR_RES(STR_GLOBAL_NOT_ENOUGH_MEMORY));
        }

    #ifdef __VCARD_CLOUD_SUPPORT__
        if (obj->m_cloud && backUpFinish->result != 0)
        {
             VfxWString errorStr = VFX_WSTR_RES(STR_GLOBAL_FAILED);
             VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);

            if (SRV_PHB_CLOUD_NETWORK_ERROR == backUpFinish->result)
            {
                errorStr = VFX_WSTR_RES(STR_GLOBAL_UNFINISHED);
                balloon->addItem(VCP_INFO_BALLOON_TYPE_WARNING, errorStr);
            }
            else if (SRV_PHB_CLOUD_LOGOUT == backUpFinish->result)
            {
                errorStr = VFX_WSTR_RES(STR_ID_VAPP_PHB_CLOUD_RELOGIN);
                balloon->addItem(VCP_INFO_BALLOON_TYPE_WARNING, errorStr);
            }
            else if (SRV_PHB_CLOUD_NO_NEED_SYNC == backUpFinish->result)
            {
                errorStr = VFX_WSTR_RES(STR_ID_VAPP_PHB_CLOUD_NO_CONTACT_BACKUP);
                balloon->addItem(VCP_INFO_BALLOON_TYPE_WARNING, errorStr);
            }
            else
            {
                balloon->addItem(VCP_INFO_BALLOON_TYPE_WARNING, errorStr);
            }
        }
    #endif /* __VCARD_CLOUD_SUPPORT__ */
    }
    else
    {
        PBBackUp *obj = (PBBackUp *)(vapp_phb_backup_g.getUserData());
        srv_phb_multi_op_status_cb_struct *backUpUpdate = (srv_phb_multi_op_status_cb_struct *)result;
        MMI_TRACE(MMI_COMMON_TRC_G4_PHB, VAPP_CONTACT_BACKUP_CB, obj->m_cloud, backUpUpdate->type, backUpUpdate->finish_count,
                    backUpUpdate->fail_count, backUpUpdate->total_count, backUpUpdate->user_data);

        if (vapp_phb_is_BG_run)
        {
            return;
        }
        if (obj->m_progress)
        {
            if (backUpUpdate->finish_count)
            {
                obj->m_progress->setProgress((VfxFloat)backUpUpdate->finish_count / backUpUpdate->total_count);
            }
        }
    }
}


void PBBackUp::onCancelClick(VfxObject* obj, VfxFloat num)
{
    terminate();
    wgui_status_icon_bar_hide_icon(STATUS_ICON_CONTACTS_BACKUP);
}


void PBBackUp::terminate()
{
    if (m_progress)
    {
       m_progress->exit(VFX_TRUE);
       m_progress = NULL;
    }

    if (m_backUp)
    {
        m_backUp->complete();
        m_backUp = NULL;
    }

    PBBackUp *obj = this;
    VFX_OBJ_CLOSE(obj);
}


void PBBackUp::closeSelf(void *p)
{
    PBBackUp *obj = this;
    VFX_OBJ_CLOSE(obj);
}


void PBBackUp::onBackupDone()
{
    terminate();
}


#if defined(__MMI_MULTI_VCARD__) || defined(__VCARD_CLOUD_SUPPORT__)

/***************************************************************************** 
 * Class PBRestorePage
 *****************************************************************************/
void PBRestorePage::onInit()
{
    VfxPage::onInit();

    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, PBRestorePage::listener, this);
    mmi_frm_cb_reg_event(EVT_ID_USB_ENTER_MS_MODE, PBRestorePage::listener, this);

    VFX_OBJ_CREATE(m_configManage, ContactConfigManager, this);
    VFX_OBJ_CREATE_EX(m_listProvider, ContactRestoreProvider, this, (m_configManage));

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_PHB_SELECT_TO_RESTORE));
    setTopBar(bar);

    VFX_OBJ_CREATE(m_fileList, VcpListMenu, this);
    m_fileList->setSize(getSize());
    m_fileList->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    m_fileList->setContentProvider(m_listProvider);
    m_fileList->setCellStyle(VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT);
    m_fileList->setMenuMode(VCP_LIST_MENU_MODE_SINGLE_SELECTION);

    m_fileList->m_signalItemTapped.connect(this, &PBRestorePage::fileSelect);

    VcpToolBar *bottom_bar;
    VFX_OBJ_CREATE(bottom_bar, VcpToolBar, this);
    bottom_bar->addItem(1, VFX_WSTR_RES(STR_ID_VAPP_PHB_RESTORE_TITLE), VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
    bottom_bar->addItem(2, VFX_WSTR_RES(STR_GLOBAL_DELETE), VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
    bottom_bar->addItem(3, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    setBottomBar(bottom_bar);
    bottom_bar->m_signalButtonTap.connect(this, &PBRestorePage::onToolBarClicked);

    if (!m_listProvider->getCount())
    {
        bottom_bar->setDisableItem(1, VFX_TRUE);
        bottom_bar->setDisableItem(2, VFX_TRUE);
    }
}


void PBRestorePage::onDeinit()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, PBRestorePage::listener, this);
    mmi_frm_cb_dereg_event(EVT_ID_USB_ENTER_MS_MODE, PBRestorePage::listener, this);

    VfxPage::onDeinit();
}


mmi_ret PBRestorePage::onProc(mmi_event_struct *evt)
{
    if (evt->evt_id == EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT)
    {
        getMainScr()->popPage();
    }
    if (evt->evt_id == EVT_ID_USB_ENTER_MS_MODE)
    {
        getMainScr()->popPage();
    }

    return MMI_RET_OK;
}


VfxBool PBRestorePage::doCanRun()
{
    VfxBool result = VFX_TRUE;

    if (!srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV))
    {
        result = VFX_FALSE;
    }

    return result;
}


void PBRestorePage::fileSelect(VcpListMenu* list, VfxU32 index)
{
    m_selectFile = index;
    m_listProvider->setSelectItem(index);
}


void PBRestorePage::onToolBarClicked(VfxObject* obj, VfxId id)
{
    switch (id)
    {
    case 1:
        if (m_listProvider->getCount())
        {
            if (m_listProvider->getFileName(m_selectFile).isEmpty())/*list restore file but del the file through usb method*/
            {
                VFX_OBJ_CLOSE(m_listProvider);
                VFX_OBJ_CREATE_EX(m_listProvider, ContactRestoreProvider, this, (m_configManage));
                m_fileList->setContentProvider(m_listProvider);
                m_selectFile = 0;
                m_listProvider->setSelectItem(m_selectFile);
                m_fileList->resetAllItems();

                if (!m_listProvider->getCount())
                {
                    ((VcpToolBar *)getBar(VFX_PAGE_BAR_LOCATION_BOTTOM))->setDisableItem(1, VFX_TRUE);
                    ((VcpToolBar *)getBar(VFX_PAGE_BAR_LOCATION_BOTTOM))->setDisableItem(2, VFX_TRUE);
                }
            }
            else
            {
                VcpConfirmPopup *command;
                VFX_OBJ_CREATE(command, VcpConfirmPopup, this);

                PBRestore *restore;
                VFX_OBJ_CREATE_EX(restore, PBRestore, getMainScr(), (getMainScr(), m_listProvider->getFileName(m_selectFile), command));
                vapp_phb_restore_g.m_totalCount = m_listProvider->getContactCount(m_selectFile);
            }
        }
        break;
    case 2:
        deleteTap();
        break;
    case 3:
        getMainScr()->popPage();
        break;
    }
}


void PBRestorePage::deleteTap()
{
    VcpConfirmPopup *confirm;
    VFX_OBJ_CREATE(confirm, VcpConfirmPopup, this);

    VfxWString text = VFX_WSTR_RES(STR_GLOBAL_DELETE);
    text += VFX_WSTR_RES(STR_ID_VAPP_PHB_QUESTION);

    confirm->setText(text);
    confirm->setInfoType(VCP_POPUP_TYPE_WARNING);
    confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    confirm->setCustomButton(
        VFX_WSTR_RES(STR_GLOBAL_DELETE),
        VFX_WSTR_RES(STR_GLOBAL_CANCEL),
        VCP_POPUP_BUTTON_TYPE_WARNING,
        VCP_POPUP_BUTTON_TYPE_CANCEL);

    confirm->m_signalButtonClicked.connect(this, &PBRestorePage::onButtonClicked);

    confirm->show(VFX_TRUE);
}


void PBRestorePage::onButtonClicked(VfxObject* obj, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        removeSelectFile();
        if (!m_listProvider->getCount())
        {
            ((VcpToolBar *)getBar(VFX_PAGE_BAR_LOCATION_BOTTOM))->setDisableItem(1, VFX_TRUE);
            ((VcpToolBar *)getBar(VFX_PAGE_BAR_LOCATION_BOTTOM))->setDisableItem(2, VFX_TRUE);
        }
    }
}


void PBRestorePage::removeSelectFile()
{
    VfxS32 count;

    m_listProvider->removeFile(m_selectFile);

    count = m_listProvider->getCount();

    VFX_OBJ_CLOSE(m_listProvider);
    VFX_OBJ_CREATE_EX(m_listProvider, ContactRestoreProvider, this, (m_configManage));
    m_fileList->setContentProvider(m_listProvider);

    if (m_listProvider->getCount())
    {
        if (count == m_selectFile + 1)
        {
            --m_selectFile;
        }
        m_listProvider->setSelectItem(m_selectFile);
    }
    else
    {
        m_selectFile = 0;
    }
    m_fileList->resetAllItems();
}


mmi_ret PBRestorePage::listener(mmi_event_struct* evt)
{
    PBRestorePage *obj = (PBRestorePage *)evt->user_data;
    return obj->onProc(evt);
}
#endif /* (__MMI_MULTI_VCARD__) || defined(__VCARD_CLOUD_SUPPORT__) */


/***************************************************************************** 
 * Class PBRestore
 *****************************************************************************/ 
#if defined(__MMI_MULTI_VCARD__) || defined(__VCARD_CLOUD_SUPPORT__)

void PBRestore::onInit()
{
    VfxObject::onInit();

    vapp_phb_is_BG_run = VFX_FALSE;

    if (!m_cloud)
    {
        m_confirmPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_PHB_RESTORE_CHOOSE_ACTION));
        m_confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
        m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
        m_confirmPopup->setCustomButton(
            VFX_WSTR_RES(STR_ID_VAPP_PHB_RESTORE_TITLE),
            VFX_WSTR_RES(STR_GLOBAL_CANCEL),
            VCP_POPUP_BUTTON_TYPE_NORMAL,
            VCP_POPUP_BUTTON_TYPE_CANCEL);

        m_confirmPopup->m_signalButtonClicked.connect(this, &PBRestore::onBtnClicked);

        m_confirmPopup->show(VFX_TRUE);

        m_delete = &vapp_phb_deleteall_g;
        vapp_phb_deleteall_g.setStorage(PHB_STORAGE_NVRAM);
        vapp_phb_deleteall_g.setUserData(this);
        vapp_phb_deleteall_g.setCB(&PBRestore::onDeleteAllCB);

        m_restore = NULL;
    #ifdef __MMI_MULTI_VCARD__
        vapp_phb_restore_g.setPath(m_path);
        vapp_phb_restore_g.setUserData(this);
        vapp_phb_restore_g.setCB(&PBRestore::onRestoreCB);
    #ifdef __VCARD_CLOUD_SUPPORT__
        vapp_phb_restore_g.setMode(SRV_PHB_BACKUP_RESTORE_MODE_T_CARD);
    #endif
    #endif /* __MMI_MULTI_VCARD__ */
    }
    else
    {
    #ifdef __VCARD_CLOUD_SUPPORT__
       // vapp_phb_restore_g.setPath(ContactConfigManager().getFilePath()); // check this ??
        vapp_phb_restore_g.setMode(SRV_PHB_BACKUP_RESTORE_MODE_CLOUD);
        vapp_phb_restore_g.setProvideId(m_providerId);
        vapp_phb_restore_g.setAccountId(m_accountId);
        vapp_phb_restore_g.setUserData(this);
        vapp_phb_restore_g.setCB(&PBRestore::onRestoreCB);
        vapp_phb_restore_g.setMallocFunc(&VappContactSettingCUI::memAllocator);
        vapp_phb_restore_g.setFreeFunc(&VappContactSettingCUI::memDeallocator);
        restoreContinue();
    #endif /* __VCARD_CLOUD_SUPPORT__ */
    }
}


void PBRestore::onDeinit()
{
    m_progress_delete = NULL;
    m_progress_restore = NULL;
    vapp_phb_is_BG_run = VFX_TRUE;

    if (m_delete)
    {
        m_delete->complete();
        wgui_status_icon_bar_hide_icon(STATUS_ICON_CONTACTS_RESTORE);
    }
    m_delete = NULL;
    if (m_restore)
    {
        m_restore->complete();
        wgui_status_icon_bar_hide_icon(STATUS_ICON_CONTACTS_RESTORE);
    }
    m_restore = NULL;
    // operation done
    m_signalRestoreDone.postEmit();

    VfxObject::onDeinit();
}


void PBRestore::restoreBegin()
{
    VFX_OBJ_CREATE(m_progress_delete, VcpIndicatorPopup, m_parent);

    m_progress_delete->setInfoType(VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON);
    m_progress_delete->setText(VFX_WSTR_RES(STR_ID_VAPP_PHB_RESTORE_DELETING));
    m_progress_delete->setProgress(0);
    m_progress_delete->show(VFX_TRUE);
    m_progress_delete->m_signalCanceled.connect(this, &PBRestore::onCancelClick);

    if (m_delete->prepare(CONTACT_DELETE_ALL, CONTACT_WANT) == CONTACT_RUN)
    {
        m_delete->run();
        wgui_status_icon_bar_show_icon(STATUS_ICON_CONTACTS_RESTORE);
    }
}


void PBRestore::restoreContinue()
{
    if (m_progress_delete)
    {
        m_progress_delete->exit(VFX_TRUE);
        m_progress_delete = NULL;
    }

    VFX_OBJ_CREATE(m_progress_restore, VcpIndicatorPopup, m_parent);

    m_progress_restore->setInfoType(VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON);
    if (m_cloud)
    {
        m_progress_restore->setText(VFX_WSTR_RES(STR_ID_VAPP_PHB_CLOUD_RESTORING));
    }
    else
    {
        m_progress_restore->setText(VFX_WSTR_RES(STR_ID_VAPP_PHB_SETTING_RESTORE));
    }
    m_progress_restore->setProgress(0);
    m_progress_restore->show(VFX_TRUE);
    m_progress_restore->m_signalCanceled.connect(this, &PBRestore::onCancelClick);

    m_restore = &vapp_phb_restore_g;
    if (m_restore->prepare(CONTACT_DELETE_ALL, CONTACT_WANT) == CONTACT_RUN)
    {
        m_restore->run();
        wgui_status_icon_bar_show_icon(STATUS_ICON_CONTACTS_RESTORE);
    }
}


void PBRestore::onDeleteAllCB(ContactOP* op, CONTACT_STATE state, srv_phb_async_op_cb_struct* cb)
{
    if (cb->type == SRV_PHB_OP_CB_TYPE_DELETE_ALL)
    {
        srv_phb_delete_all_cb_struct *delAllFinish = (srv_phb_delete_all_cb_struct *)cb;
        PBRestore *obj = (PBRestore *)(vapp_phb_deleteall_g.getUserData());
        MMI_TRACE(MMI_COMMON_TRC_G4_PHB, VAPP_CONTACT_DELETE_DONE, obj->m_cloud, delAllFinish->type, delAllFinish->finish_count,
                    delAllFinish->fail_count, delAllFinish->total_count, delAllFinish->user_data, delAllFinish->result);

        vapp_phb_deleteall_g.complete();
        if (obj->m_progress_delete && !vapp_phb_is_BG_run)
        {
            obj->m_delete = NULL;
            obj->restoreContinue();
        }
        else
        {
            if (vapp_phb_restore_g.prepare(CONTACT_DELETE_ALL, CONTACT_WANT) == CONTACT_RUN)
            {
                vapp_phb_restore_g.run();
            }
        }
    }
    else
    {
        srv_phb_multi_op_status_cb_struct *delAllUpdate = (srv_phb_multi_op_status_cb_struct *)cb;
        PBRestore *obj = (PBRestore *)(vapp_phb_deleteall_g.getUserData());
        MMI_TRACE(MMI_COMMON_TRC_G4_PHB, VAPP_CONTACT_DELETE_CB, obj->m_cloud, delAllUpdate->type, delAllUpdate->finish_count,
                    delAllUpdate->fail_count, delAllUpdate->total_count, delAllUpdate->user_data);

        if (vapp_phb_is_BG_run)
        {
            return;
        }
        if (obj->m_progress_delete)
        {
            obj->m_progress_delete->setProgress((VfxFloat)delAllUpdate->finish_count / delAllUpdate->total_count);
        }
    }
}


void PBRestore::onRestoreCB(ContactOP* op, CONTACT_STATE state, srv_phb_async_op_cb_struct* cb)
{
    if (cb->type == SRV_PHB_OP_CB_TYPE_RESTORE)
    {
        srv_phb_restore_cb_struct *restoreFinish = (srv_phb_restore_cb_struct *)cb;
        PBRestore *obj = (PBRestore *)(vapp_phb_restore_g.getUserData());
        MMI_TRACE(MMI_COMMON_TRC_G4_PHB, VAPP_CONTACT_RESTORE_DONE, obj->m_cloud, restoreFinish->type, restoreFinish->finish_count,
                    restoreFinish->fail_count, restoreFinish->total_count, restoreFinish->user_data, restoreFinish->result);

        if (obj->m_progress_restore && !vapp_phb_is_BG_run)
        {
        #ifdef __VCARD_CLOUD_SUPPORT__
            if (restoreFinish->result == 0 && obj->m_cloud)
            {
                obj->m_progress_restore->setProgress(1);
            }
        #endif
        //    obj->terminate();
        // delay 250ms before close progress
            VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
            renderer->blockAfterNextCommit(300, VfxCallback0(obj, &PBRestore::onRestoreDone));
        }
        else
        {
            vapp_phb_restore_g.complete();
        }

        VfxWString temp;
        VfxWString success_count;
        VfxWString total_count;

        success_count.format("%d ", restoreFinish->finish_count);
        total_count.format(" %d ", vapp_phb_restore_g.m_totalCount);
        temp += success_count;
        temp += VFX_WSTR_RES(STR_ID_VAPP_PHB_SUCCESS);
        temp += VFX_WSTR(", ");
        temp += VFX_WSTR_RES(STR_ID_VAPP_PHB_TOTAL);
        temp += total_count;
        if (vapp_phb_restore_g.m_totalCount == 1)
        {
            temp += VFX_WSTR_RES(VAPP_PHB_STR_CONTACT_APPEND);
        }
        else
        {
            temp += VFX_WSTR_RES(VAPP_PHB_STR_CONTACTS_APPEND);
        }

        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_GENERAL, MMI_EVENT_CONTACT_RESTORE_ERROR, MMI_NMGR_BALLOON_TYPE_INFO, temp);
        wgui_status_icon_bar_hide_icon(STATUS_ICON_CONTACTS_RESTORE);
    #ifdef __VCARD_CLOUD_SUPPORT__
        if (obj->m_cloud && restoreFinish->result != 0)
        {
             VfxWString errorStr = VFX_WSTR_RES(STR_GLOBAL_FAILED);
             VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
    
            if (SRV_PHB_CLOUD_NETWORK_ERROR == restoreFinish->result)
            {
                errorStr = VFX_WSTR_RES(STR_GLOBAL_UNFINISHED);
                balloon->addItem(VCP_INFO_BALLOON_TYPE_WARNING, errorStr);
            }
            else if (SRV_PHB_CLOUD_LOGOUT == restoreFinish->result)
            {
                errorStr = VFX_WSTR_RES(STR_ID_VAPP_PHB_CLOUD_RELOGIN);
                balloon->addItem(VCP_INFO_BALLOON_TYPE_WARNING, errorStr);
            }
            else if (SRV_PHB_CLOUD_NO_NEED_SYNC == restoreFinish->result)
            {
                errorStr = VFX_WSTR_RES(STR_ID_VAPP_PHB_CLOUD_NO_CONTACT_RESTORE);
                balloon->addItem(VCP_INFO_BALLOON_TYPE_WARNING, errorStr);
            }
            else
            {
                balloon->addItem(VCP_INFO_BALLOON_TYPE_WARNING, errorStr);
            }
        }
    #endif /* __VCARD_CLOUD_SUPPORT__ */
    }
    else
    {
        srv_phb_multi_op_status_cb_struct *restoreUpdate = (srv_phb_multi_op_status_cb_struct *)cb;
        PBRestore *obj = (PBRestore *)(vapp_phb_restore_g.getUserData());
        MMI_TRACE(MMI_COMMON_TRC_G4_PHB, VAPP_CONTACT_RESTORE_CB, obj->m_cloud, restoreUpdate->type, restoreUpdate->finish_count,
                    restoreUpdate->fail_count, restoreUpdate->total_count, restoreUpdate->user_data);

        if (vapp_phb_is_BG_run)
        {
            return;
        }
        if (obj->m_progress_restore)
        {
        #ifdef __VCARD_CLOUD_SUPPORT__
            if (obj->m_cloud)
            {
                obj->m_progress_restore->setProgress((VfxFloat)restoreUpdate->finish_count / srv_phb_get_total_contact(PHB_STORAGE_NVRAM));
            }
            else
            {
                obj->m_progress_restore->setProgress((VfxFloat)restoreUpdate->finish_count / vapp_phb_restore_g.m_totalCount);
            }
        #else
            obj->m_progress_restore->setProgress((VfxFloat)restoreUpdate->finish_count / vapp_phb_restore_g.m_totalCount);
        #endif /* __VCARD_CLOUD_SUPPORT__ */
        }
    }
}


void PBRestore::onCancelClick(VfxObject* obj, VfxFloat num)
{
    terminate();
    wgui_status_icon_bar_hide_icon(STATUS_ICON_CONTACTS_RESTORE);
}


void PBRestore::onBtnClicked(VfxObject* obj, VfxId id)
{
    switch (id)
    {
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:
            restoreBegin();
            break;
        default:
            terminate();
            break;
    }
}


void PBRestore::terminate()
{
    if (m_progress_delete)
    {
       m_progress_delete->exit(VFX_TRUE);
       m_progress_delete = NULL;
    }
    if (m_progress_restore)
    {
       m_progress_restore->exit(VFX_TRUE);
       m_progress_delete = NULL;
    }

    if (m_delete)
    {
        m_delete->complete();
        m_delete = NULL;
    }
    if (m_restore)
    {
        m_restore->complete();
        m_restore = NULL;
    }

    PBRestore *obj = this;
    VFX_OBJ_CLOSE(obj);
}


void PBRestore::onRestoreDone()
{
    terminate();
}
#endif /* __MMI_MULTI_VCARD__ || __VCARD_CLOUD_SUPPORT__*/
#endif /* defined(__MMI_MULTI_VCARD__) || defined(__VCARD_CLOUD_SUPPORT__) */

