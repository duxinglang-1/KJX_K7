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
 *  vapp_widget_gallery_setting.cpp
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

#if defined(__MMI_VUI_WIDGET_GALLERY__)

#include "vapp_widget_gallery_setting.h"
#include "vapp_widget_gallery_slide_show_interval_setting.h"
#include "mmi_rp_vapp_widget_gallery_setting_def.h"
#include "vcp_include.h"
#include "vapp_fmgr_cui_gprot.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "FileMgrSrvGProt.h"
#include "Nvram_common_defs.h"
#include "custom_mmi_folders_config.h"

#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/

extern "C" void vapp_widget_gallery_setting_launch(void)
{
    VfxAppLauncher::launch( 
        VAPP_WIDGET_GALLERY_SETTING,
        VFX_OBJ_CLASS_INFO(VappWidgetGallerySettingApp),
        GRP_ID_ROOT);
}

VFX_IMPLEMENT_CLASS("VappWidgetGallerySettingApp", VappWidgetGallerySettingApp, VfxApp);

void VappWidgetGallerySettingApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    // create and display main screen
    VappWidgetGallerySettingScreen *scr;
    VFX_OBJ_CREATE(scr, VappWidgetGallerySettingScreen, this);
    scr->show();
}

mmi_ret VappWidgetGallerySettingApp::onProc(mmi_event_struct *evt)
{
    return VfxApp::onProc(evt);
}

VFX_IMPLEMENT_CLASS("VappWidgetGallerySettingScreen", VappWidgetGallerySettingScreen, VfxMainScr);

void VappWidgetGallerySettingScreen::on1stReady()
{
    VfxMainScr::on1stReady();

    // create and display first page
    VappWidgetGallerySettingPage *page;
    VFX_OBJ_CREATE(page, VappWidgetGallerySettingPage, this);
    pushPage(0, page);
}

VFX_IMPLEMENT_CLASS("VappWidgetGallerySettingPage", VappWidgetGallerySettingPage, VfxPage);

VappWidgetGallerySettingPage::VappWidgetGallerySettingPage():
    m_pLaunchIntervalSetCel(NULL),
    m_pLaunchFolderSetCel(NULL)
{
}

void VappWidgetGallerySettingPage::onInit()
{
    VfxPage::onInit(); // call base class

    VcpForm *form = NULL;
    VFX_OBJ_CREATE(form, VcpForm, this);
    form->setSize(getSize().width, getSize().height);

    VFX_OBJ_CREATE(m_pLaunchIntervalSetCel, VappWidgetGallerySettingIntervalCell, form);
    m_pLaunchIntervalSetCel->setMainText(VFX_WSTR_RES(STR_ID_VAPP_WIDGET_GALLERY_SETTING_INTERVAL_CELLL_TITLE));
    m_pLaunchIntervalSetCel->setAccessory(VCPFORM_NEXT_ITEM_ICON);

    VFX_OBJ_CREATE(m_pLaunchFolderSetCel, VcpFormItemLauncherCell, form);
    m_pLaunchFolderSetCel->setMainText(VFX_WSTR_RES(STR_ID_VAPP_WIDGET_GALLERY_SETTING_FILE_CELLL_TITLE));
    m_pLaunchFolderSetCel->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_pLaunchFolderSetCel->m_signalTap.connect(this, &VappWidgetGallerySettingPage::createSelectFileCUI);

    form->addItem(m_pLaunchIntervalSetCel, 0);
    form->addItem(m_pLaunchFolderSetCel, 1);

    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_WIDGET_GALLERY_SETTING_TITLE));
    setTopBar(titleBar);

    m_folderPath = getSelectedFolderPath();
    m_pLaunchFolderSetCel->setHintText(m_folderPath);

    VfxS16 error;            
    WriteRecord(
     NVRAM_EF_VAPP_WIDGET_GALLERY_PHOTO_FOLDER_PATH_LID,
     1,
     (void*)(m_folderPath.getBuf()),
     NVRAM_EF_VAPP_WIDGET_GALLERY_PHOTO_FOLDER_PATH_SIZE,
     &error);
}


VfxWString VappWidgetGallerySettingPage::getSelectedFolderPath()
{
    VfxWChar buffer[SRV_FMGR_PATH_MAX_LEN + 1];
    S16 error;
    memset(buffer, 0, (SRV_FMGR_PATH_MAX_LEN + 1));
    ReadRecord(
        NVRAM_EF_VAPP_WIDGET_GALLERY_PHOTO_FOLDER_PATH_LID, 
        1, 
        &buffer, 
        NVRAM_EF_VAPP_WIDGET_GALLERY_PHOTO_FOLDER_PATH_SIZE, 
        &error); 

    if(mmi_wcslen(buffer) == 0)
    {   
        kal_wsprintf(buffer,"%c:\\",(CHAR)FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_NO_ALT_DRIVE));
        //mmi_wcscat(buffer, srv_fmgr_drv_get_path_by_type(SRV_FMGR_DRV_PHONE_TYPE));
        mmi_wcscat(buffer, (VfxWChar*)SHOOTING_DOWNLOAD_FOLDER_NAME);
    }
    
    return VFX_WSTR_MEM(buffer);
}


void VappWidgetGallerySettingPage::fileSystemErrorHandler(VfxS32 error_code)
{
    mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_GENERAL,
        MMI_EVENT_INFO_BALLOON,
        MMI_NMGR_BALLOON_TYPE_FAILURE,
        (WCHAR*)(VFX_WSTR_RES(srv_fmgr_fs_error_get_string(error_code)).getBuf()));
}


mmi_ret VappWidgetGallerySettingPage::onProc(mmi_event_struct *event)
{
    switch(event->evt_id)
    {
        case EVT_ID_VCUI_FOLDER_SELECTOR_RESULT:
            vcui_folder_selector_result_event_struct *evt = (vcui_folder_selector_result_event_struct*)event;
            if (evt->result == 1)
            {
                VfxWChar *folderPath = NULL;
                VfxS32 error_code = 0;
                VFX_ALLOC_MEM(folderPath, (SRV_FMGR_PATH_MAX_LEN + 1)* ENCODING_LENGTH, this);
                memset(folderPath, 0, (SRV_FMGR_PATH_MAX_LEN + 1)* ENCODING_LENGTH);
                error_code = vcui_folder_selector_get_selected_filepath(evt->sender_id, NULL, (WCHAR*)folderPath, (SRV_FMGR_PATH_MAX_LEN + 1)*ENCODING_LENGTH);

                if(error_code < FS_NO_ERROR)
                {
                    fileSystemErrorHandler(error_code);
                    VFX_FREE_MEM(folderPath);
                }
                else
                {
                    m_folderPath = VFX_WSTR_MEM(folderPath);
                    VFX_FREE_MEM(folderPath); 
                    
                    m_pLaunchFolderSetCel->setHintText(m_folderPath);    

                    VfxS16 error;            
                    WriteRecord(
                        NVRAM_EF_VAPP_WIDGET_GALLERY_PHOTO_FOLDER_PATH_LID,
                        1,
                        (void*)(m_folderPath.getBuf()),
                        NVRAM_EF_VAPP_WIDGET_GALLERY_PHOTO_FOLDER_PATH_SIZE,
                        &error);
                }
            }
            vcui_folder_selector_close(evt->sender_id);   
            break;

        return MMI_RET_OK;
    }
    return VfxPage::onProc(event);
}

void VappWidgetGallerySettingPage::createSelectFileCUI(VcpFormItemCell *cell, VfxId id)
{
    mmi_id cuiSelectFileId;
    cuiSelectFileId = vcui_folder_selector_create(
                            getMainScr()->getGroupId(),
                            (WCHAR*)L"root",
                            VCUI_FOLDER_SELECTOR_STYLE_READ,
                            VCUI_FOLDER_SELECTOR_OPT_FOLDER_TRAVERSE_ALL | VCUI_FOLDER_SELECTOR_OPT_FIXED_PATH_ON);
    // create fmgr cui failed
    if(cuiSelectFileId == GRP_ID_INVALID)
    {
        // not allow to enter file mgr service if in USB MS(main storage) mode
        return;
    }
    
    vcui_folder_selector_run(cuiSelectFileId);

    vfxSetCuiCallerScr(cuiSelectFileId, getMainScr());
}
#endif /* __MMI_VUI_WIDGET_GALLERY__ */
