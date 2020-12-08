/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  vapp_screen_lock_mre.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the MRE screen lock
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_SCREEN_LOCK_MRE__)

//#define VAPP_SCREEN_LOCK_MRE_SWLA_LOG

/*****************************************************************************
 * Include
 *****************************************************************************/

#include <ctype.h>

#include "vfx_uc_include.h"
#include "vapp_screen_lock_base.h"
#include "vapp_screen_lock_mre.h"
#include "vcp_form.h"
#include "vapp_screen_lock_gprot.h"
#include "vapp_platform_context.h"
#include "vapp_screen_lock_setting_provider.h"

#include "vpi_app_launcher.h"
#include "vfx_renderer.h"

#include "vmres.h"

#ifdef __MMI_VUI_SCREEN_LOCK_MRE_USE_ASM__
#include "vadp_asm.h"
#endif

extern "C"
{
#include "MMIDataType.h"
#include "gpiosrvgprot.h"
#include "MREAppMgrSrvGprot.h"
#include "FileMgrSrvGprot.h"
#include "USBSrvGProt.h"
#include "vapp_screen_lock_mre_def.h"

#ifdef __MMI_VUI_SCREEN_LOCK_MRE_USE_ASM__
#include "mmi_rp_vapp_screen_lock_mre_def.h"
#endif

#if defined(VAPP_SCREEN_LOCK_MRE_SWLA_LOG)
#include "SST_sla.h"
#endif

}

#ifndef __MMI_VUI_SCREEN_LOCK_MRE_USE_ASM__

/*****************************************************************************
* Global Memory for MRE heap memory
*****************************************************************************/
#ifdef __MTK_TARGET__
    #if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
        #pragma arm section zidata = "DYNAMICCACHEABLEZI_NC_MMIPOOL"
        __align(4)     kal_uint8 s_vAppScrnLockMreMemPool[VAPP_SCRNLOCK_MRE_HEAP_SIZE];
        #pragma arm section zidata
    #else
        #pragma arm section zidata = "LARGEPOOL_ZI"
        __align(4)     kal_uint8 s_vAppScrnLockMreMemPool[VAPP_SCRNLOCK_MRE_HEAP_SIZE];
        #pragma arm section zidata
    #endif
#else
    kal_uint8 s_vAppScrnLockMreMemPool[VAPP_SCRNLOCK_MRE_HEAP_SIZE];    
#endif

#endif /* __MMI_VUI_SCREEN_LOCK_MRE_USE_ASM__ */

/*****************************************************************************
 * Utility Class
 *****************************************************************************/

VappScreenLockMreUtil::VappScreenLockMreUtil()
{
    // Do nothing.
}

VfxS32 VappScreenLockMreUtil::isDriveLetterMatch(
    const VappScreenLockId mreId,
    const VfxU8 *driveLetter,
    VfxU32 count)
{
    VfxU8 mreDrive = VappScreenLockMreUtil::getDriveLetter(mreId);    

    if (mreDrive <= 0)
    {
        return -1;
    }
    
    for (VfxU32 i = 0; i < count; i++)
    {
        if (toupper(driveLetter[i]) == toupper(mreDrive))
        {
            return 1;
        }
    }

    return 0;
}

VfxU8 VappScreenLockMreUtil::getDriveLetter(
        const VappScreenLockId mreId)
{
    WCHAR path[SRV_FMGR_PATH_MAX_LEN + 1]; // 1: null terminated char
    MMI_BOOL ret;

    ret = srv_mre_appmgr_get_file_path(
            (mmi_app_package_char *)mreId.getStringType(),
            path);

    if (!ret)
    {
        return 0; 
    }

    return (VfxU8)path[0];
}

/*****************************************************************************
 * MRE Screen Lock Screenshot
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappScreenLockMreScreenshot", VappScreenLockMreScreenshot, VfxFrame);

VappScreenLockMreScreenshot::VappScreenLockMreScreenshot() :
    m_mreId(),
    m_imgFrame(NULL),
    m_imgBuf(NULL),
    m_textFrmErr(NULL),
    m_errStrId(0) 
{
    // Do nothing  
}

VappScreenLockMreScreenshot::VappScreenLockMreScreenshot(const VappScreenLockId &mreId):
    m_mreId(mreId),
    m_imgFrame(NULL),
    m_imgBuf(NULL),
    m_textFrmErr(NULL),
    m_errStrId(0)    
{
    // Do nothing   
}

VappScreenLockMreScreenshot::~VappScreenLockMreScreenshot()
{
    // Do nothing
}

void VappScreenLockMreScreenshot::onInit()
{
    VfxFrame::onInit();

    setSize(PREVIEW_IMG_WIDTH, PREVIEW_IMG_HEIGHT);
    
    // Image Frame to display preview image
    VFX_OBJ_CREATE(m_imgFrame, VfxImageFrame, this);

    // Text Frame to display error string
    VFX_OBJ_CREATE(m_textFrmErr, VfxTextFrame, this); 
    m_textFrmErr->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_textFrmErr->setColor(VFX_COLOR_WHITE);
    VfxSize size(PREVIEW_IMG_WIDTH, PREVIEW_IMG_HEIGHT);
    m_textFrmErr->setPos(VfxPoint(size.width>>1, size.height>>1));
    m_textFrmErr->setAnchor(0.5f, 0.5f);

    
    updateScreenshot();

    // Register event handler
    mmi_frm_cb_reg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT,
        VappScreenLockMreScreenshot::eventProc,
        getObjHandle());  

    mmi_frm_cb_reg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN,
        VappScreenLockMreScreenshot::eventProc,
        getObjHandle());  

#if defined(__MMI_USB_SUPPORT__)
    mmi_frm_cb_reg_event(
        EVT_ID_USB_ENTER_MS_MODE,
        VappScreenLockMreScreenshot::eventProc,
        getObjHandle());

    mmi_frm_cb_reg_event(
        EVT_ID_USB_EXIT_MS_MODE,
        VappScreenLockMreScreenshot::eventProc,
        getObjHandle());
    
#endif /* defined(__MMI_USB_SUPPORT__) */
    
}

void VappScreenLockMreScreenshot::onDeinit()
{
    //To avoid VRT from using the memory
    VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();
        
    // release memory
    VFX_FREE_MEM(m_imgBuf);

    // Unregister event handler
    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT,
        VappScreenLockMreScreenshot::eventProc,
        getObjHandle());
    
    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN,
        VappScreenLockMreScreenshot::eventProc,
        getObjHandle());
    
#if defined(__MMI_USB_SUPPORT__)
    mmi_frm_cb_dereg_event(
        EVT_ID_USB_ENTER_MS_MODE,
        VappScreenLockMreScreenshot::eventProc,
        getObjHandle());

    mmi_frm_cb_dereg_event(
        EVT_ID_USB_EXIT_MS_MODE,
        VappScreenLockMreScreenshot::eventProc,
        getObjHandle());
   
#endif /* defined(__MMI_USB_SUPPORT__) */

    VfxFrame::onDeinit();
}

void VappScreenLockMreScreenshot::updateScreenshot()
{
    if (getPreviewImg())
    {
        m_imgFrame->setMem(m_imgBuf); 
        //m_imgFrame->setHidden(VFX_FALSE);
        
        m_textFrmErr->setHidden(VFX_TRUE);
    }
    else
    {
        m_imgFrame->setMem(NULL); 
        //m_imgFrame->setHidden(VFX_TRUE);
        
        m_textFrmErr->setHidden(VFX_FALSE);
        m_textFrmErr->setString(m_errStrId);
    } 
}

VfxBool VappScreenLockMreScreenshot::getPreviewImg()
{
    // get path
    MMI_BOOL ret;
    U16 filePath[SRV_MRE_APPMGR_FILEPATH_LEN];
    ret = srv_mre_appmgr_get_file_path(
         (mmi_app_package_char *)m_mreId.getStringType(),
         filePath);

    if (ret != MMI_TRUE)
    {
        m_errStrId = STR_GLOBAL_FAILED;
        return VFX_FALSE;
    }

    // get image size
    vm_res_read_hint_struct hint;
    VMBOOL result;
    result = vm_load_resource_use_outside_memory(
                (VMWSTR)filePath,
                "MRE.PREVIEW_0",
                NULL,
                0,
                &hint);
    if (result != VM_TRUE)
    {
        m_errStrId = STR_GLOBAL_FILE_NOT_FOUND;
        return VFX_FALSE;
    }

    if (hint.res_size > VAPP_SCRNLOCK_MRE_SCREENSHOT_SIZE)
    {
        m_errStrId = STR_GLOBAL_INSUFFICIENT_MEMORY;
        return VFX_FALSE;
    }
    
    VFX_FREE_MEM(m_imgBuf);
    VFX_ALLOC_MEM(m_imgBuf, hint.res_size, this); 
    if (!m_imgBuf)
    {
        m_errStrId = STR_GLOBAL_INSUFFICIENT_MEMORY;
        return VFX_FALSE;
    }

    // get image content
    result = vm_load_resource_use_outside_memory(
        (VMWSTR)filePath,
        "MRE.PREVIEW_0",
        m_imgBuf,
        hint.res_size,
        &hint);
    if (result != VM_TRUE)
    {
        VFX_FREE_MEM(m_imgBuf);
        
        m_errStrId = STR_GLOBAL_FILE_NOT_FOUND;        
        return VFX_FALSE;
    }
    return VFX_TRUE;
}

mmi_ret VappScreenLockMreScreenshot::eventProc(mmi_event_struct *evt)
{
    VappScreenLockMreScreenshot *shot;

    shot = (VappScreenLockMreScreenshot *)handleToObject((VfxObjHandle)evt->user_data);
    VFX_OBJ_ASSERT_VALID(shot);

    switch (evt->evt_id)
    { 
    
    case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
    {
        srv_fmgr_notification_dev_plug_event_struct *p;

        p = (srv_fmgr_notification_dev_plug_event_struct *)evt;

        VfxS32 match;
        match = VappScreenLockMreUtil::isDriveLetterMatch(
                    shot->m_mreId, p->drv_letters, p->count);
        if (match > 0)
        {
            // Notify to update preview image
            shot->updateScreenshot();
        }
        
        break;
    }
    case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
    {
        srv_fmgr_notification_dev_plug_event_struct *p;

        p = (srv_fmgr_notification_dev_plug_event_struct *)evt;

        VfxS32 match;
        match = VappScreenLockMreUtil::isDriveLetterMatch(
                    shot->m_mreId, p->drv_letters, p->count);
        if (match > 0)
        {
            // Notify to update preview image
            shot->updateScreenshot();
        }
        break;        
    }

#if defined(__MMI_USB_SUPPORT__)
    case EVT_ID_USB_ENTER_MS_MODE:
    {
        // Notify to update preview image
        shot->updateScreenshot();
        break;
    } 
    case EVT_ID_USB_EXIT_MS_MODE:
    {
        // Notify to update preview image
        shot->updateScreenshot();
        break;
    }
#endif /* defined(__MMI_USB_SUPPORT__) */

    default:
    {
        break;
    }

    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * MRE Screen Lock Provider
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappScreenLockMreProvider", VappScreenLockMreProvider, VfxControl);


VappScreenLockMreProvider::VappScreenLockMreProvider()
{
    // Do nothing.
}

void VappScreenLockMreProvider::onObjectNotify(VfxId id, void *userData)
{    
    switch (id)
    {        
        case VFX_FRAME_NOTIFY_ID_PARENT_FRAME_CHANGED:
        {
            VfxFrame *origParentFrame = (VfxFrame *)userData;
            
            VfxControl::onObjectNotify(id, userData);

            m_screenLockMre = VFX_OBJ_DYNAMIC_CAST(origParentFrame, VappScreenLockMre);
            if (m_screenLockMre.isValid())
            {
                m_screenLockMre->setMreProvider(NULL);
            }

            m_screenLockMre = VFX_OBJ_DYNAMIC_CAST(getParentFrame(), VappScreenLockMre);
            if (m_screenLockMre.isValid())
            {
                m_screenLockMre->setMreProvider(this);
            }
            return;
        }
        default:
        {
            VfxControl::onObjectNotify(id, userData);
            return;
        }
    }
}

void VappScreenLockMreProvider::onUnlock(VappScreenLockMreProvider *provider)
{
    if (m_screenLockMre.isValid())
    {
        m_screenLockMre->onUnlock();
    }
}

void VappScreenLockMreProvider::onConfigurationCompleted(VappScreenLockMreProvider *provider, VfxBool isSuccess)
{
    if (m_screenLockMre.isValid())
    {
        m_screenLockMre->onConfigurationCompleted(isSuccess);
    }
}

void VappScreenLockMreProvider::createView()
{
    onCreateView();
}

void VappScreenLockMreProvider::releaseView()
{
    onReleaseView();
}

void VappScreenLockMreProvider::pageEnter()
{
    onPageEnter();
}

void VappScreenLockMreProvider::pageExit()
{
    onPageExit();
}

void VappScreenLockMreProvider::backlightOn()
{
    onBacklightOn();
}

void VappScreenLockMreProvider::backlightOff()
{
    onBacklightOff();
}


void VappScreenLockMreProvider::onCreateView()
{
    // Do nothing.
}


void VappScreenLockMreProvider::onReleaseView()
{
    // Do nothing.
}

void VappScreenLockMreProvider::onPageEnter()
{
    // Do nothing.
}


void VappScreenLockMreProvider::onPageExit()
{
    // Do nothing.
}

void VappScreenLockMreProvider::onBacklightOn()
{
    // Do nothing.
}


void VappScreenLockMreProvider::onBacklightOff()
{
    // Do nothing.
}

/*****************************************************************************
* MRE Screen Lock Delegator
*****************************************************************************/

VAPP_SCREEN_LOCK_IMPLEMENT_CLASS(VappScreenLockMre, VappScreenLock);


VappScreenLockMre::VappScreenLockMre() :
    m_mreId(),
    m_launcher(NULL),
    m_screenLockProvider(NULL),
    m_isSelfClose(VFX_FALSE),
    m_isCardPlugOut(VFX_FALSE),
    m_isUSBMode(VFX_FALSE),
    m_errStrId(0)
#ifdef __MMI_VUI_SCREEN_LOCK_MRE_USE_ASM__
    ,m_asmGid(GRP_ID_INVALID)
#endif       
{
    // Do nothing.
}


VappScreenLockMre::~VappScreenLockMre()
{
    // Do nothing.
}

void VappScreenLockMre::onInit()
{
    VappScreenLock::onInit();
  
    //EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE
    //EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT
    
    mmi_frm_cb_reg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT,
        VappScreenLockMre::eventProc,
        getObjHandle());  

#if defined(__MMI_USB_SUPPORT__)
    mmi_frm_cb_reg_event(
        EVT_ID_USB_ENTER_MS_MODE,
        VappScreenLockMre::eventProc,
        getObjHandle());
    
#endif /* defined(__MMI_USB_SUPPORT__) */
}

void VappScreenLockMre::onDeinit()
{
    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT,
        VappScreenLockMre::eventProc,
        getObjHandle());    
    
#if defined(__MMI_USB_SUPPORT__)
    mmi_frm_cb_dereg_event(
        EVT_ID_USB_ENTER_MS_MODE,
        VappScreenLockMre::eventProc,
        getObjHandle());
   
#endif /* defined(__MMI_USB_SUPPORT__) */

    VappScreenLock::onDeinit();

}

void VappScreenLockMre::setId(const VappScreenLockId &id)
{
    m_mreId = id;
}


void VappScreenLockMre::setMreProvider(VappScreenLockMreProvider *screenLockProvider)
{
    if (!screenLockProvider)
    {
        m_screenLockProvider = NULL;
    }
    else
    {
        m_screenLockProvider = screenLockProvider;
    }
}

void VappScreenLockMre::onUnlock()
{
#ifdef VAPP_SCREEN_LOCK_MRE_SWLA_LOG
        SLA_CustomLogging("DS5", SA_start);
#endif
    m_signalUnlock.postEmit(this);

#ifdef VAPP_SCREEN_LOCK_MRE_SWLA_LOG
    SLA_CustomLogging("DS5", SA_stop);
#endif

}

void VappScreenLockMre::onConfigurationCompleted(VfxBool isSuccess)
{
    m_signalConfigurationCompleted.emit(this, isSuccess);
}


VappScreenLockId VappScreenLockMre::getId() const
{
    return m_mreId;
}


VfxS32 VappScreenLockMre::getName(VfxWChar *string, VfxS32 size) const
{
    WCHAR temp[MMI_APP_NAME_MAX_LEN + 1]; // 1: null terminated char
    mmi_ret ret;

    ret = srv_mre_appmgr_get_app_name(
         (mmi_app_package_char *)m_mreId.getStringType(),
         temp);

    if (ret != MMI_RET_OK)
    {
        string[0] = L'\0'; // If failed, set the name as empty string.
    }
    else
    {
        vfx_sys_wcsncpy(string, temp, size - 1);
    }

    return vfx_sys_wcslen(string);
}


VfxFrame *VappScreenLockMre::createIcon(VfxObject *parentObj)
{
    // Create icon.
    VfxImageFrame *icon;
    VFX_OBJ_CREATE(icon, VfxImageFrame, parentObj);


    // Get icon resource.
    mmi_image_src_struct imageSrc;
    mmi_ret ret;

    ret = srv_mre_appmgr_get_app_image(
         (mmi_app_package_char *)m_mreId.getStringType(),
         &imageSrc);


    if (ret != MMI_RET_OK)
    {
        return icon;
    }

    switch (imageSrc.type)
    {
        case MMI_IMAGE_SRC_TYPE_RES_ID:
            icon->setResId(imageSrc.data.res_id);
            break;

        case MMI_IMAGE_SRC_TYPE_PATH:
            icon->setPath(((const VfxWChar *)imageSrc.data.path));
            break;

        case MMI_IMAGE_SRC_TYPE_ROM_MEMORY:
            icon->setImgContent(
                VfxImageSrc(
                    imageSrc.data.image.image_ptr,
                    imageSrc.data.image.image_len));
            break;

        default:
            break;
    }

    return icon;
}

VfxS32 VappScreenLockMre::getScreenshotNum() const
{
    return 1;
}

VfxFrame **VappScreenLockMre::createScreenshot(VfxObject *parent) const
{
    VappScreenLockMreScreenshot **screenshot = NULL;

    VFX_ALLOC_MEM(screenshot, sizeof(VappScreenLockMreScreenshot*), parent);
    VFX_OBJ_CREATE_EX(screenshot[0], VappScreenLockMreScreenshot, parent, (m_mreId));

    return (VfxFrame**)screenshot;   
}


void VappScreenLockMre::onCreateView()
{    
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCRNLOCK_MRE_ON_CREATE_VIEW);

    VappScreenLock::onCreateView(); 

    // Add to the manager.
    VappScreenLockMreManager *mgr = VFX_OBJ_GET_INSTANCE(VappScreenLockMreManager);
    mgr->add(this);

#ifdef __MMI_VUI_SCREEN_LOCK_MRE_USE_ASM__
    initMemory();
#endif

    VfxBool ret;
    ret = launchVpi();

    if (!ret && 
        m_errStrId != STR_GLOBAL_INSUFFICIENT_MEMORY &&
        m_errStrId != STR_GLOBAL_FAILED)
    {        
        mgr->initReviver(m_mreId);
    }
    else
    {
        // init variable
        mgr->deinitReviver();
        m_isCardPlugOut = VFX_FALSE;
        m_isUSBMode = VFX_FALSE;        
    }
}


void VappScreenLockMre::onReleaseView()
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCRNLOCK_MRE_ON_RELEASE_VIEW);

    terminateVpi(); 
    
#ifdef __MMI_VUI_SCREEN_LOCK_MRE_USE_ASM__
    deinitMemory();
#endif   

    // Remove from the manager.
    VappScreenLockMreManager *mgr = VFX_OBJ_GET_INSTANCE(VappScreenLockMreManager);
    mgr->remove(this);
    
    VappScreenLock::onReleaseView();
}


VfxBool VappScreenLockMre::getCreateViewFailure(VfxWString &errorString)
{
    VfxBool valid = m_screenLockProvider.isValid();
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCRNLOCK_MRE_GET_CREATE_VIEW_FAILURE, !valid); 

    errorString.loadFromRes(m_errStrId);
    return !valid;    
}

VfxBool VappScreenLockMre::checkAvailable(VfxWString &errorString)
{
    VfxU8 mreDrive = VappScreenLockMreUtil::getDriveLetter(m_mreId); 
    
#if defined(__MMI_USB_SUPPORT__)
    if (srv_usb_is_in_mass_storage_mode())
    {
        errorString.loadFromRes(STR_GLOBAL_NOT_AVAILABLE_IN_MASS_STORAGE_MODE);
        return VFX_FALSE;
    }
#endif /* defined(__MMI_USB_SUPPORT__) */

    // preinstall app has drive letter: '@' 
    if (mreDrive != '@')
    {
        MMI_BOOL access = srv_fmgr_drv_is_accessible(mreDrive);
        if (!access)
        {           
            errorString.loadFromRes(STR_GLOBAL_FILE_NOT_FOUND);
            return VFX_FALSE;
        }
    }

    return VFX_TRUE;
}

void VappScreenLockMre::onPageEnter()
{
    if (m_screenLockProvider.isValid())
    {        
        srv_backlight_set_timer(
            SRV_BACKLIGHT_SET_TIMER_BY_APP, 
            VAPP_SCREEN_LOCK_MRE_BACKLIGHT_OFF_TIME*0.7,
            VAPP_SCREEN_LOCK_MRE_BACKLIGHT_OFF_TIME);
        
        m_screenLockProvider->pageEnter();
    }
}


void VappScreenLockMre::onPageExit()
{
    if (m_screenLockProvider.isValid())
    {
        // restore app timer when lock is not active
        srv_backlight_set_timer(SRV_BACKLIGHT_RESTORE_TIMER_BY_APP, 0, 0);
        srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
    
        m_screenLockProvider->pageExit();
    }
}

void VappScreenLockMre::onBacklightOn()
{
    if (m_screenLockProvider.isValid())
    {
        m_screenLockProvider->backlightOn();
    }
}


void VappScreenLockMre::onBacklightOff()
{
    if (m_screenLockProvider.isValid())
    {
        m_screenLockProvider->backlightOff();
    }
}

mmi_ret VappScreenLockMre::createDefaultScreenLock(mmi_event_struct *evt)
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCRNLOCK_MRE_CREATE_DEFAULT_SCREEN_LOCK);

    vapp_screen_lock_close();
    vapp_screen_lock_launch();

    return MMI_RET_OK;
}

VfxBool VappScreenLockMre::launchVpi()
{
    // Get the VSO file path.
    WCHAR path[SRV_FMGR_PATH_MAX_LEN + 1]; 
    MMI_BOOL ret;
    VfxBool vfxRet;

#ifdef VAPP_SCREEN_LOCK_MRE_SWLA_LOG
    SLA_CustomLogging("DS1", SA_start);
#endif

    ret = srv_mre_appmgr_get_file_path(
            (mmi_app_package_char *)m_mreId.getStringType(),
            path);

#ifdef VAPP_SCREEN_LOCK_MRE_SWLA_LOG
     SLA_CustomLogging("DS1", SA_stop);
#endif 

    if (!ret)
    {
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCRNLOCK_MRE_VAL_1, ret, __LINE__);
        m_errStrId = STR_GLOBAL_FAILED;
        return VFX_FALSE;
    }

    // Launch the VSO.
    VFX_ASSERT(!m_launcher);

    VFX_OBJ_CREATE_EX(
        m_launcher,
        VpiAppLauncher,
        this,
        (VFX_WSTR_MEM((const VfxWChar *)path)));   

#ifdef VAPP_SCREEN_LOCK_MRE_SWLA_LOG
     SLA_CustomLogging("DS2", SA_start);
#endif

     // Get preload APP info.
    vfxRet = preparePreloadAppInfo(
            m_launcher,
            path,
            m_preloadInfo);

#ifdef VAPP_SCREEN_LOCK_MRE_SWLA_LOG
     SLA_CustomLogging("DS2", SA_stop);
#endif 

    if (!vfxRet)
    {
        VFX_OBJ_CLOSE(m_launcher);        
        return VFX_FALSE;
    }
  

    VappPlatformContext *context = VFX_OBJ_GET_INSTANCE(VappPlatformContext);

#ifdef VAPP_SCREEN_LOCK_MRE_SWLA_LOG
     SLA_CustomLogging("DS3", SA_start);
#endif

    // Launch the VPP with platform context
    vfxRet = m_launcher->launch(context, this, &m_preloadInfo);

#ifdef VAPP_SCREEN_LOCK_MRE_SWLA_LOG
     SLA_CustomLogging("DS3", SA_stop);
#endif     

    // Launcher fail
    if (!vfxRet || !m_screenLockProvider.isValid())
    {
        releasePreloadAppInfo(m_launcher, m_preloadInfo);
        VFX_OBJ_CLOSE(m_launcher);
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCRNLOCK_MRE_VAL_1, -1, __LINE__);
        m_errStrId = STR_GLOBAL_FAILED;
        return VFX_FALSE;
    }  
    
    m_launcher->m_signalQuitByInterrupt.connect(this, &VappScreenLockMre::onQuitByInterrupt);

    m_screenLockProvider->setSize(getSize());

#ifdef VAPP_SCREEN_LOCK_MRE_SWLA_LOG
    SLA_CustomLogging("DS4", SA_start);
#endif   
    m_screenLockProvider->createView(); 

#ifdef VAPP_SCREEN_LOCK_MRE_SWLA_LOG
    SLA_CustomLogging("DS4", SA_stop);
#endif

    return VFX_TRUE;
}

void VappScreenLockMre::terminateVpi()
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCRNLOCK_MRE_TERMINATE_VPI);

#ifdef VAPP_SCREEN_LOCK_MRE_SWLA_LOG
    SLA_CustomLogging("DS6", SA_start);
#endif    
    // Release view.
    if (m_screenLockProvider.isValid())
    {
        m_screenLockProvider->releaseView();
    }    

#ifdef VAPP_SCREEN_LOCK_MRE_SWLA_LOG
    SLA_CustomLogging("DS6", SA_stop);
#endif

    // Close the VSO launcher.
    if (m_launcher)
    {  
    #ifdef VAPP_SCREEN_LOCK_MRE_SWLA_LOG
        SLA_CustomLogging("DS7", SA_start);
    #endif
        m_launcher->terminate();  
    
    #ifdef VAPP_SCREEN_LOCK_MRE_SWLA_LOG
        SLA_CustomLogging("DS7", SA_stop);
    #endif
        if (m_isSelfClose)
        {
            m_launcher->m_signalDestroy.connect(this, &VappScreenLockMre::onDestroy);
        }
        else
        {
            onDestroy(NULL);
        }
    }    
}

void VappScreenLockMre::onDestroy(VfxObject *obj)
{
    releasePreloadAppInfo(m_launcher, m_preloadInfo);
    VFX_OBJ_CLOSE(m_launcher);    
}

void VappScreenLockMre::handleInterrupt()
{    
    terminateVpi();

    mmi_event_struct evt;
    MMI_FRM_INIT_EVENT(&evt, 0);
    MMI_FRM_POST_EVENT(&evt, &VappScreenLockMre::createDefaultScreenLock, this);
}

void VappScreenLockMre::entryMassStorageMode()
{     
    if (!m_isUSBMode)
    {
        handleInterrupt(); 
        m_isUSBMode = VFX_TRUE;
    } 
}

void VappScreenLockMre::entryCardPlugOut()
{    
    if (!m_isCardPlugOut)
    {
        handleInterrupt(); 
        m_isCardPlugOut = VFX_TRUE;
    }   
}

mmi_ret VappScreenLockMre::eventProc(mmi_event_struct *evt)
{
    VappScreenLockMre *mre;

    mre = (VappScreenLockMre *)handleToObject((VfxObjHandle)evt->user_data);
    VFX_OBJ_ASSERT_VALID(mre);

    switch (evt->evt_id)
    { 
    
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        {
            srv_fmgr_notification_dev_plug_event_struct *p;

            p = (srv_fmgr_notification_dev_plug_event_struct *)evt;

            VfxS32 match;
            match = VappScreenLockMreUtil::isDriveLetterMatch(
                        mre->m_mreId, p->drv_letters, p->count);
            if (match <= 0)
            {
                break;
            }            
                   
            mre->entryCardPlugOut();        
            
            
            break;
        }

#if defined(__MMI_USB_SUPPORT__)
        case EVT_ID_USB_ENTER_MS_MODE:
        {
            mre->entryMassStorageMode();
            break;
        } 
#endif /* defined(__MMI_USB_SUPPORT__) */

        default:
        {
            break;
        }

    }

    return MMI_RET_OK;
}


void VappScreenLockMre::onQuitByInterrupt(
    VfxObject *obj,
    VpiAppLauncher::QuitByInterrupTypeEnum cause)
{
    m_isSelfClose = VFX_TRUE;

    switch (cause)
    {
        case VpiAppLauncher::QUIT_TYPE_PLUG_OUT_T_CARD:

            entryCardPlugOut(); 
            
            break;
            
        case VpiAppLauncher::QUIT_TYPE_PLUG_IN_USB:
            
            entryMassStorageMode();    
            
            break;    
    }    

    m_isSelfClose = VFX_FALSE;
}


VfxBool VappScreenLockMre::preparePreloadAppInfo(
    VpiAppLauncher *launcher,
    const WCHAR *path,
    vm_preload_app_info_t &info)
{
	//
	// Read memory requirement information from the VPP file.
	//
	if (!launcher->getPreloadInfo(info))
    {
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCRNLOCK_MRE_VAL_1, -1, __LINE__);
        m_errStrId = STR_GLOBAL_FILE_NOT_FOUND;
        return VFX_FALSE;
    } 
    
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCRNLOCK_MRE_INFO, info.loadSize, info.heapSize);
	//
	// Allocate memory for code and data.
	//
	VfxU32 load = 0;
    if (info.loadSize > 0)
    { 
    #ifdef __MMI_VUI_SCREEN_LOCK_MRE_USE_ASM__
    
        info.loadBufSize = info.loadSize;
        info.loadBase = malloc(info.loadBufSize);

        if (!info.loadBase)
        {
            MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCRNLOCK_MRE_VAL_1, -1, __LINE__);
            m_errStrId = STR_GLOBAL_INSUFFICIENT_MEMORY;
            return VFX_FALSE;
        }
        
    #else /* __MMI_VUI_SCREEN_LOCK_MRE_USE_ASM__ */
    
        load = VAPP_SCRNLOCK_MRE_4_ALIGN(info.loadSize);
        if (load > VAPP_SCRNLOCK_MRE_HEAP_SIZE)
        {
            MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCRNLOCK_MRE_VAL_1, -1, __LINE__);
            m_errStrId = STR_GLOBAL_INSUFFICIENT_MEMORY;
            return VFX_FALSE;            
        }

        info.loadBufSize = load;
        info.loadBase = s_vAppScrnLockMreMemPool;
        
    #endif /* __MMI_VUI_SCREEN_LOCK_MRE_USE_ASM__ */    
    }

    VfxU32 remainSize = VAPP_SCRNLOCK_MRE_HEAP_SIZE - load;

    //
    // Allocate memory for heap.
    //
    if (info.heapSize > 0)
    {
    #ifdef __MMI_VUI_SCREEN_LOCK_MRE_USE_ASM__

        info.heapBufSize = info.heapSize;
        info.heapBase = malloc(info.heapBufSize);

        if (!info.heapBase)
        {
            MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCRNLOCK_MRE_VAL_1, -1, __LINE__);
            free(info.loadBase);
            m_errStrId = STR_GLOBAL_INSUFFICIENT_MEMORY;
            return VFX_FALSE;
        }
    
    #else /* __MMI_VUI_SCREEN_LOCK_MRE_USE_ASM__ */
    
        VfxU32 heap = VAPP_SCRNLOCK_MRE_4_ALIGN(info.heapSize);
        if (heap > remainSize)
        {
            MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCRNLOCK_MRE_VAL_1, -1, __LINE__);
            m_errStrId = STR_GLOBAL_INSUFFICIENT_MEMORY;
            return VFX_FALSE;          
        }
        info.heapBufSize = heap;        
        info.heapBase = &s_vAppScrnLockMreMemPool[load];

    #endif /* __MMI_VUI_SCREEN_LOCK_MRE_USE_ASM__ */     
    }

    //
    // Preload the VPP
    //
    if (!launcher->preLoad(info))
    {
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCRNLOCK_MRE_VAL_1, -1, __LINE__);
        m_errStrId = STR_GLOBAL_FAILED;
    #ifdef __MMI_VUI_SCREEN_LOCK_MRE_USE_ASM__
        free(info.loadBase);
        free(info.heapBase);
    #endif /* __MMI_VUI_SCREEN_LOCK_MRE_USE_ASM__ */
    
        return VFX_FALSE;
    }

    return VFX_TRUE;
}


void VappScreenLockMre::releasePreloadAppInfo(
    VpiAppLauncher *launcher,
    vm_preload_app_info_t &info)
{
#ifdef __MMI_VUI_SCREEN_LOCK_MRE_USE_ASM__
    // Backup the load and heap base before unload
    void *heapBase = info.heapBase;
    void *loadBase = info.loadBase;
#endif /* __MMI_VUI_SCREEN_LOCK_MRE_USE_ASM__ */

#ifdef VAPP_SCREEN_LOCK_MRE_SWLA_LOG
    SLA_CustomLogging("DS8", SA_start);
#endif

    launcher->unload(info);

#ifdef VAPP_SCREEN_LOCK_MRE_SWLA_LOG
    SLA_CustomLogging("DS8", SA_stop);
#endif


#ifdef __MMI_VUI_SCREEN_LOCK_MRE_USE_ASM__    
    if (heapBase)
    {
        free(heapBase);
    }

    if (loadBase)
    {
        free(loadBase);
    }
#endif /* __MMI_VUI_SCREEN_LOCK_MRE_USE_ASM__ */   
}


#ifdef __MMI_VUI_SCREEN_LOCK_MRE_USE_ASM__

void VappScreenLockMre::initMemory()
{
    if (m_asmGid != GRP_ID_INVALID)
    {
        return; // already initialized.
    }

    VadpAsmProperty property;

    m_asmGid = mmi_frm_group_create(
                GRP_ID_ROOT,
                GRP_ID_VAPP_SCREEN_LOCK_MRE,
                &onAsmGroupEvent,
                getObjHandle());

    VFX_ASSERT(m_asmGid != GRP_ID_INVALID);

    VadpAsm::getProperty(m_asmGid, property);
    property.f_prepare_w_reserve = 0;
    property.f_hide_in_oom = 0;
    VadpAsm::setProperty(m_asmGid, property);
}


void VappScreenLockMre::deinitMemory()
{
    if (m_asmGid != GRP_ID_INVALID)
    {
        mmi_frm_group_close(m_asmGid);
        m_asmGid = GRP_ID_INVALID; 
    }    
}

void *VappScreenLockMre::malloc(VfxS32 size)
{
    VFX_ASSERT(m_asmGid != GRP_ID_INVALID);

    void *memPtr = vadpAsmAlloc(m_asmGid, size);

    return memPtr;
}


void VappScreenLockMre::free(void *mem)
{
    VFX_ASSERT(m_asmGid != GRP_ID_INVALID);
    
    vadpAsmFree(m_asmGid, mem);    
}


mmi_ret VappScreenLockMre::onAsmGroupEvent(mmi_event_struct *evt)
{   

    mmi_ret ret = MMI_RET_OK;

    switch(evt->evt_id)
    {
        case EVT_ID_DELETE_DANGLE_GROUP_REQ:
        {
            // Keep dangle group.
            ret = MMI_RET_ERR;
            break;
        }
        case EVT_ID_ASM_FREE_REQ:           // volunteer free
        case EVT_ID_ASM_FREE_REQ_NO_WAIT:   // volunteer free
        case EVT_ID_ASM_FORCE_FREE:         // force free
        {
            VappScreenLockMre *mre;

            mre = (VappScreenLockMre *)handleToObject((VfxObjHandle)evt->user_data);
            VFX_OBJ_ASSERT_VALID(mre);
            
            mre->terminateVpi(); 
    
        #ifdef __MMI_VUI_SCREEN_LOCK_MRE_USE_ASM__
            mre->deinitMemory();
        #endif   
            ret = MMI_FRM_ASM_FREED;
            break;
        }
        default:
        {
            break;
        }
    }

    return ret;
}
#endif /* __MMI_VUI_SCREEN_LOCK_MRE_USE_ASM__ */

/*****************************************************************************
 * MRE ScreenLock Manager
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappScreenLockMreManager", VappScreenLockMreManager, VfxObject);

VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappScreenLockMreManager);


VappScreenLockMreManager::VappScreenLockMreManager() :
    m_reviverInited(VFX_FALSE),
    m_driveLetter(0),
    m_mreId(),
    m_firstSkipped(VFX_FALSE),
    m_screenLockMre(NULL)
{
    // Do nothing.
}


VappScreenLockMreManager::~VappScreenLockMreManager()
{
    // Do nothing.
}


void VappScreenLockMreManager::onInit()
{
    VfxObject::onInit();   

    mmi_frm_cb_reg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN,
        VappScreenLockMreManager::eventProc,
        getObjHandle());  

#if defined(__MMI_USB_SUPPORT__)

    mmi_frm_cb_reg_event(
        EVT_ID_USB_EXIT_MS_MODE,
        VappScreenLockMreManager::eventProc,
        getObjHandle());

    
#endif /* defined(__MMI_USB_SUPPORT__) */
}


void VappScreenLockMreManager::onDeinit()
{
        
    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN,
        VappScreenLockMreManager::eventProc,
        getObjHandle());
    
#if defined(__MMI_USB_SUPPORT__)

    mmi_frm_cb_dereg_event(
        EVT_ID_USB_EXIT_MS_MODE,
        VappScreenLockMreManager::eventProc,
        getObjHandle());
   
#endif /* defined(__MMI_USB_SUPPORT__) */

    VfxObject::onDeinit();
}

void VappScreenLockMreManager::add(VappScreenLockMre *lock)
{
    VFX_ASSERT(!m_screenLockMre.isValid());

    m_screenLockMre = lock;
}


void VappScreenLockMreManager::remove(VappScreenLockMre *lock)
{
    if (m_screenLockMre.isValid())
    {
        VFX_ASSERT(m_screenLockMre == lock);

        m_screenLockMre = NULL;
    }
}

void VappScreenLockMreManager::initReviver(const VappScreenLockId mreId)
{
    if (m_reviverInited)
    {
        return; // have already been initialized.
    }

    m_reviverInited = VFX_TRUE;
    
    m_mreId = mreId;
    m_driveLetter = VappScreenLockMreUtil::getDriveLetter(m_mreId);

    VappScreenLockSettingProvider *provider;

    provider = VFX_OBJ_GET_INSTANCE(VappScreenLockSettingProvider);
    provider->m_signalDefaultScreenLockChanged.connect(this, &VappScreenLockMreManager::onScreenLockChanged);
}


void VappScreenLockMreManager::deinitReviver()
{
    if (!m_reviverInited)
    {
        return; // have not been initialized.
    }

    VappScreenLockSettingProvider *provider;

    provider = VFX_OBJ_GET_INSTANCE(VappScreenLockSettingProvider);
    provider->m_signalDefaultScreenLockChanged.disconnect(this, &VappScreenLockMreManager::onScreenLockChanged);

    m_driveLetter = 0xFF;
    m_mreId.assignWith(VAPP_SCREEN_LOCK_SRC_INVALID, 0);

    m_firstSkipped = VFX_FALSE;
    m_reviverInited = VFX_FALSE;
}


void VappScreenLockMreManager::invokeReviver()
{
    if (!m_reviverInited)
    {
        return; // have not been initialized.
    }

    VappScreenLockSettingProvider *provider;

    provider = VFX_OBJ_GET_INSTANCE(VappScreenLockSettingProvider);
    provider->setDefaultScreenLock(m_mreId);

    deinitReviver();
}


void VappScreenLockMreManager::onScreenLockChanged()
{
    if (!m_reviverInited)
    {
        return; // have not been initialized.
    }

    if (!m_firstSkipped)
    {
        m_firstSkipped = VFX_TRUE;
        return;
    }

    // cancel reviver
    deinitReviver();
}

mmi_ret VappScreenLockMreManager::eventProc(mmi_event_struct *evt)
{    
    VappScreenLockMreManager *mgr;

    mgr = (VappScreenLockMreManager *)handleToObject((VfxObjHandle)evt->user_data);
    VFX_OBJ_ASSERT_VALID(mgr);

    // m_mreId is invalid
    if (!mgr->m_reviverInited)
    {
        return MMI_RET_OK;
    }
    
    switch (evt->evt_id)
    {
    
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
        {
            srv_fmgr_notification_dev_plug_event_struct *p;

            p = (srv_fmgr_notification_dev_plug_event_struct *)evt;

            VfxS32 match;
            match = VappScreenLockMreUtil::isDriveLetterMatch(
                        mgr->m_mreId, p->drv_letters, p->count);
            if (match > 0)
            {
                //Invoke reviver
                VappScreenLockMreManager *mgr = VFX_OBJ_GET_INSTANCE(VappScreenLockMreManager);
                mgr->invokeReviver(); 
            }
            // already uninstalled
            else if (match < 0)
            {
                mgr->deinitReviver();
            }                          
            
            break;        
        }

#if defined(__MMI_USB_SUPPORT__)

        case EVT_ID_USB_EXIT_MS_MODE:
        {        
            //Invoke reviver
            VappScreenLockMreManager *mgr = VFX_OBJ_GET_INSTANCE(VappScreenLockMreManager);
            mgr->invokeReviver();
            
            break;
        }
#endif /* defined(__MMI_USB_SUPPORT__) */

        default:
        {
            break;
        }

    }

    return MMI_RET_OK;
}


#endif /* defined(__MMI_VUI_SCREEN_LOCK_MRE__) */

