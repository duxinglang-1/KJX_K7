/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_widget_gallery.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the gallery widget.
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

#if defined(__MMI_VUI_WIDGET_GALLERY__)


/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vapp_widget_def.h"
#include "vapp_widget_native_factory.h"
#include "vapp_widget_gallery.h"
#include "vcp_include.h"
#include "mmi_rp_vapp_widget_gallery_def.h"

#include "mmi_rp_app_cosmos_global_def.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "Nvram_common_defs.h"
#include "custom_mmi_folders_config.h"
#include "FileMgrSrvGprot.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#endif

/* Pluto MMI headers: */
#ifdef __cplusplus
}
#endif

/*****************************************************************************
 * Gallery Widget
 *****************************************************************************/

VAPP_WIDGET_SYS_PUBLISH_NATIVE(
    VappWidgetGallery,
    VAPP_WIDGET_TYPE_GALLERY,
    VappWidgetGalleryPublisher);

VAPP_WIDGET_IMPLEMENT_CLASS(VappWidgetGallery, VappWidget);


VappWidgetGallery::VappWidgetGallery():
    m_resetFlag(VFX_FALSE),
    m_timerHideControlBar(NULL),
    m_galleryViewer(NULL),
    m_controlBar(NULL)
{
    // Do nothing.
}


VappWidgetId VappWidgetGallery::getId() const
{
    return VappWidgetId(VAPP_WIDGET_SRC_NATIVE, VAPP_WIDGET_TYPE_GALLERY);
}


VfxSize VappWidgetGallery::getMaxSize() const
{
    return VfxSize(WIDTH, HEIGHT);
}


VfxS32 VappWidgetGallery::getName(VfxWChar *string, VfxS32 size) const
{
    const VfxWChar *str = vfxSysResGetStr(STR_ID_VAPP_WIDGET_GALLERY);

    VFX_ASSERT(string && size > 0);

    mmi_wcsncpy((WCHAR *)string, (const WCHAR *)str, size - 1);

    return vfx_sys_wcslen(string);
}


VfxFrame *VappWidgetGallery::createIcon(VfxObject *parentObj)
{
    VfxImageFrame *icon;

    VFX_OBJ_CREATE(icon, VfxImageFrame, parentObj);
    icon->setResId(IMG_ID_VAPP_WIDGET_GALLERY_ICON);

    return icon;
}


void VappWidgetGallery::onCreateView()
{
    VappWidget::onCreateView();

    setBgColor(VFX_COLOR_TRANSPARENT);
    setBounds(VfxRect(0, 0, WIDTH, HEIGHT));

    VFX_OBJ_CREATE(m_galleryViewer, VappWidgetGalleryViewer, this);
    m_galleryViewer->createMediaList();
    m_galleryViewer->setDisableSlideShow(VFX_TRUE);

    VFX_OBJ_CREATE(m_controlBar, VappWidgetGalleryControlBar, this);
    m_controlBar->setAnchor(0.5,1);
    m_controlBar->setPos(getSize().width/2, getSize().height);

    VFX_OBJ_CREATE(m_timerHideControlBar, VfxTimer, this);
    m_timerHideControlBar->setStartDelay(VAPP_WIDGET_GALLERY_AUTO_HIDE_CONTROL_BAR_MSEC);
    m_timerHideControlBar->m_signalTick.connect(this,&VappWidgetGallery::onHideControlBarTimeout);
    m_timerHideControlBar->start();

    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, &eventHandler, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, &eventHandler, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION, &eventHandler, this);
#ifdef __MMI_USB_SUPPORT__
    mmi_frm_cb_reg_event(EVT_ID_USB_ENTER_MS_MODE, &eventHandler, this);
    mmi_frm_cb_reg_event(EVT_ID_USB_EXIT_MS_MODE, &eventHandler, this);
#endif
}


void VappWidgetGallery::onReleaseView()
{
#ifdef __MMI_USB_SUPPORT__
    mmi_frm_cb_dereg_event(EVT_ID_USB_ENTER_MS_MODE, &eventHandler, this);
    mmi_frm_cb_dereg_event(EVT_ID_USB_EXIT_MS_MODE, &eventHandler, this);
#endif
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION, &eventHandler, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, &eventHandler, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, &eventHandler, this);

    VFX_OBJ_CLOSE(m_timerHideControlBar);
    VFX_OBJ_CLOSE(m_controlBar);
    VFX_OBJ_CLOSE(m_galleryViewer);

    VappWidget::onReleaseView();
}


VappWidgetGalleryViewer *VappWidgetGallery::getGalleryViewer()
{
    return m_galleryViewer;
}


void VappWidgetGallery::onUSBEnterMS()
{
    // do nothing, this case will entry new screen
}


void VappWidgetGallery::onUSBExitMS()
{
    refreshGalleryWidget();
}


mmi_ret VappWidgetGallery::eventHandler(mmi_event_struct *event)
{
    MMI_ASSERT(event);
    VappWidgetGallery* gallery = (VappWidgetGallery *)event->user_data;
    
    switch (event->evt_id)
    {
        case EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION:
            // reset record pic number if the selected folder has changed status
            gallery->onStorageChanged(event);
            break;

        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
            gallery->onMemoryCardPlugInOut(event);
            break;
            
#ifdef __MMI_USB_SUPPORT__
        case EVT_ID_USB_ENTER_MS_MODE:
            gallery->onUSBEnterMS();
            break;

        case EVT_ID_USB_EXIT_MS_MODE:
            gallery->onUSBExitMS();
            break;
#endif   
        default:
            break;
    }
    return MMI_RET_OK;
}


void VappWidgetGallery::refreshGalleryWidget()
{
    // re-loading gallery pic
    // close and re-create media cache 
    VfxS32 picIndex = m_galleryViewer->getFadeoutPicId();
    VfxS32 playState = m_controlBar->getPlayBtnState();
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WIDGET_GALLERY_REFRESH_GALLERY_WIDGET, picIndex, 200);
    
    m_galleryViewer->stopSlideShowTimer();
    VFX_OBJ_CLOSE(m_timerHideControlBar);
    VFX_OBJ_CLOSE(m_controlBar);
    VFX_OBJ_CLOSE(m_galleryViewer);

    VFX_OBJ_CREATE(m_galleryViewer, VappWidgetGalleryViewer, this);
    m_galleryViewer->setNextLockPicId(picIndex);
    m_galleryViewer->createMediaList();
    m_galleryViewer->setDisableSlideShow(VFX_TRUE);

    VFX_OBJ_CREATE(m_controlBar, VappWidgetGalleryControlBar, this);
    m_controlBar->setAnchor(0.5,1);
    m_controlBar->setPos(getSize().width/2, getSize().height);
    m_controlBar->setPlayBtnState(playState);

    VFX_OBJ_CREATE(m_timerHideControlBar, VfxTimer, this);
    m_timerHideControlBar->setStartDelay(VAPP_WIDGET_GALLERY_AUTO_HIDE_CONTROL_BAR_MSEC);
    m_timerHideControlBar->m_signalTick.connect(this,&VappWidgetGallery::onHideControlBarTimeout);
    m_timerHideControlBar->start();
}


VfxS32 VappWidgetGallery::isSameFolder(const CHAR *string1, const CHAR *string2)
{
	VfxS32 len = mmi_ucs2strlen(string1);
	return (mmi_ucs2ncmp(string1, string2, len) == 0)? VFX_TRUE : VFX_FALSE;
}


void VappWidgetGallery::onStorageChanged(mmi_event_struct *event)
{
    srv_fmgr_notification_adv_action_event_struct *fmgr_act
        = (srv_fmgr_notification_adv_action_event_struct*)event;

    if(fmgr_act->state == SRV_FMGR_NOTIFICATION_STATE_AFTER && fmgr_act->result == FS_NO_ERROR)
    {
        if ((fmgr_act->action == SRV_FMGR_NOTIFICATION_ACTION_DELETE) ||
            (fmgr_act->action == SRV_FMGR_NOTIFICATION_ACTION_DELETE_ALL))
        {
            if (fmgr_act->src_filepath != NULL &&
				isSameFolder((const CHAR *)getSelectedFolderPath().getBuf(), 
                             (const CHAR *)fmgr_act->src_filepath))
            {
                m_resetFlag = VFX_TRUE;
            }
        }
        else if((fmgr_act->action == SRV_FMGR_NOTIFICATION_ACTION_MOVE) ||
                (fmgr_act->action == SRV_FMGR_NOTIFICATION_ACTION_COPY))
        {
            if (fmgr_act->dest_filepath != NULL &&
                mmi_ucs2cmp((const CHAR *)getSelectedFolderPath().getBuf(), 
                            (const CHAR *)fmgr_act->dest_filepath) == 0)
            {
                m_resetFlag = VFX_TRUE;
            }
        }
    }
}


void VappWidgetGallery::onMemoryCardPlugInOut(mmi_event_struct *event)
{
    srv_fmgr_notification_dev_plug_event_struct *evt = (srv_fmgr_notification_dev_plug_event_struct *)event;
    U32 i;
    for (i = 0; i < evt->count; i++)
    {
        if (evt->drv_letters[i] == srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE) ||
            evt->drv_letters[i] == srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_2_TYPE))
        {
            refreshGalleryWidget();
        }
    }
}


void VappWidgetGallery::onSerializeView(VfxArchive *ar)
{
    m_resetFlag = VFX_FALSE;
#ifdef __MMI_USB_SUPPORT__
        mmi_frm_cb_dereg_event(EVT_ID_USB_ENTER_MS_MODE, &eventHandler, this);
        mmi_frm_cb_dereg_event(EVT_ID_USB_EXIT_MS_MODE, &eventHandler, this);
#endif
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, &eventHandler, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, &eventHandler, this);

    // Release your resources if the home screen becomes inactive.
    ar->writeU32(m_galleryViewer->getFadeoutPicId());
    m_checkFolderPath = getSelectedFolderPath();
    ar->writeU32(m_controlBar->getPlayBtnState());
    m_galleryViewer->stopSlideShowTimer();
    VFX_OBJ_CLOSE(m_timerHideControlBar);
    VFX_OBJ_CLOSE(m_controlBar);
    VFX_OBJ_CLOSE(m_galleryViewer);
}


void VappWidgetGallery::onRestoreView(VfxArchive *ar)
{
    // Restore your resources if the home screen becomes active.
    VFX_OBJ_CREATE(m_galleryViewer, VappWidgetGalleryViewer, this);
    if(m_checkFolderPath == getSelectedFolderPath() && !m_resetFlag)
    {
        // no necessary to reset pic id if folder is changed
        m_galleryViewer->setNextLockPicId(ar->readU32());
    }
    else
    {
        // just skip recorded pic id
        ar->readU32();
    }
    m_galleryViewer->createMediaList();
    m_galleryViewer->setDisableSlideShow(VFX_TRUE);

    VFX_OBJ_CREATE(m_controlBar, VappWidgetGalleryControlBar, this);
    m_controlBar->setAnchor(0.5,1);
    m_controlBar->setPos(getSize().width/2, getSize().height);
    m_controlBar->setPlayBtnState(ar->readU32());

    VFX_OBJ_CREATE(m_timerHideControlBar, VfxTimer, this);
    m_timerHideControlBar->setStartDelay(VAPP_WIDGET_GALLERY_AUTO_HIDE_CONTROL_BAR_MSEC);
    m_timerHideControlBar->m_signalTick.connect(this,&VappWidgetGallery::onHideControlBarTimeout);
    m_timerHideControlBar->start();

    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, &eventHandler, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, &eventHandler, this);
#ifdef __MMI_USB_SUPPORT__
    mmi_frm_cb_reg_event(EVT_ID_USB_ENTER_MS_MODE, &eventHandler, this);
    mmi_frm_cb_reg_event(EVT_ID_USB_EXIT_MS_MODE, &eventHandler, this);
#endif
}


void VappWidgetGallery::onEnterEditMode()
{
    VappWidget::onEnterEditMode();
}


void VappWidgetGallery::onExitEditMode()
{
    VappWidget::onExitEditMode();
}


VfxPoint VappWidgetGallery::onGetEditButtonOffset()
{
    return VfxPoint(getSize().width-VAPP_WIDGET_GALLERY_EDIT_BUT_OFFSET_X, VAPP_WIDGET_GALLERY_EDIT_BUT_OFFSET_Y);
}


void VappWidgetGallery::onTap(const VfxPoint &pos)
{
    VappWidget::onTap(pos);

    if(m_controlBar->getHidden())
    {
        m_controlBar->setHidden(VFX_FALSE);
        m_timerHideControlBar->start();
        m_galleryViewer->stopSlideShowTimer();
        m_galleryViewer->setDisableSlideShow(VFX_TRUE);
    }
    else
    {
        m_controlBar->setHidden(VFX_TRUE);
        m_timerHideControlBar->stop();
        m_galleryViewer->setDisableSlideShow(VFX_FALSE);
        if(m_galleryViewer->isAllowSlideShow())
        {
            m_galleryViewer->startSlideShowTimer();
        }
    }
}


void VappWidgetGallery::onDrag(VfxPenEvent &event)
{
    VappWidget::onMove(event);
}


void VappWidgetGallery::onMove(VfxPenEvent &event)
{
    VappWidget::onMove(event);
}


void VappWidgetGallery::onDrop(VfxPenEvent &event)
{
    VappWidget::onDrop(event);
}


void VappWidgetGallery::onAbort(VfxPenEvent &event)
{
    VappWidget::onAbort(event);
}


void VappWidgetGallery::onFocus()
{
    VappWidget::onFocus();
}


void VappWidgetGallery::onDefocus()
{
    VappWidget::onDefocus();
}


void VappWidgetGallery::onHideControlBarTimeout(VfxTimer* pTimer)
{
    if(!m_controlBar->getHidden())
    {
        m_controlBar->setHidden(VFX_TRUE);

        m_galleryViewer->setDisableSlideShow(VFX_FALSE);
        if(m_galleryViewer->isAllowSlideShow())
        {
            m_galleryViewer->startSlideShowTimer();            
        }
    }
}


void VappWidgetGallery::restartHideControlBarTimer()
{
    m_timerHideControlBar->start();
}


VfxWString VappWidgetGallery::getSelectedFolderPath()
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
    
    return  VFX_WSTR_MEM(buffer);
}


#endif /* __MMI_VUI_WIDGET_GALLERY__ */
