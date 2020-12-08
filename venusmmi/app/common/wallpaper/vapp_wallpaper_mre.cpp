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
 *  vapp_wallpaper_mre.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#if defined(__MMI_VUI_WALLPAPER_MRE__)

/*****************************************************************************
 * Include
 *****************************************************************************/
#include <ctype.h>

extern "C"
{
#include "MMIDataType.h"
#include "MREAppMgrSrvGprot.h"
#include "FileMgrSrvGprot.h"
#include "mmi_rp_vapp_wallpaper_mre_def.h"

#if defined(VAPP_WALLPAPER_MRE_SWLA_LOG)
#include "SST_sla.h"
#endif

}

#include "vfx_uc_include.h"
#include "vapp_wallpaper.h"
#include "vapp_wallpaper_mre.h"
#include "vpi_app_launcher.h"
#include "vmenv.h"
#include "vadp_asm.h"

/*****************************************************************************
* MRE Screen Lock
*****************************************************************************/

VFX_IMPLEMENT_CLASS("VappWallpaperMreProvider", VappWallpaperMreProvider, VfxControl);

VappWallpaperMreProvider::VappWallpaperMreProvider()
{
    // Do nothing.
}

void VappWallpaperMreProvider::onObjectNotify(VfxId id, void *userData)
{
    switch (id)
    {        
        case VFX_FRAME_NOTIFY_ID_PARENT_FRAME_CHANGED:
        {
            VfxFrame *origParentFrame = (VfxFrame *)userData;
            
            VfxControl::onObjectNotify(id, userData);

            m_wallpaperMre = VFX_OBJ_DYNAMIC_CAST(origParentFrame, VappWallpaperMre);
            if (m_wallpaperMre.isValid())
            {
                m_wallpaperMre->setMreProvider(NULL);
            }

            m_wallpaperMre = VFX_OBJ_DYNAMIC_CAST(getParentFrame(), VappWallpaperMre);
            if (m_wallpaperMre.isValid())
            {
                m_wallpaperMre->setMreProvider(this);
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

VfxU32 VappWallpaperMreProvider::getEnv(
        vapp_wp_provider_env_enum env,
        void *value)
{
    if (m_wallpaperMre.isValid())
    {
        if (env == VAPP_WP_PROVIDER_ENV_SRC_TYPE)
        {
            VfxS32 src;
            src = m_wallpaperMre->getSource();
            *((VfxS32 *)value) = src;
        }
    }
    return 0;
}

VfxS32 VappWallpaperMreProvider::getTotalPage()
{
    if (m_wallpaperMre.isValid())
    {
        return m_wallpaperMre->getTotalPage();
    }
    return 1;
}

VfxBool VappWallpaperMreProvider::isSuspended()
{
    if (m_wallpaperMre.isValid())
    {
        return m_wallpaperMre->isSuspended();
    }
    return VFX_FALSE;
}

void VappWallpaperMreProvider::suspend()
{
    // suspend parent wallpaper
    if (m_wallpaperMre.isValid())
    {
        m_wallpaperMre->suspend();
    }
}

void VappWallpaperMreProvider::resume()
{
    // resume parent wallpaper
    if (m_wallpaperMre.isValid())
    {
        m_wallpaperMre->resume();
    }
}

void VappWallpaperMreProvider::onCreateView()
{
    // Do nothing.
}

void VappWallpaperMreProvider::onReleaseView()
{
    // Do nothing.
}

void VappWallpaperMreProvider::onSerializeView()
{
    // Do nothing.
}

void VappWallpaperMreProvider::onRestoreView()
{
    // Do nothing
}

void VappWallpaperMreProvider::onSuspend()
{
    // Do nothing
}

void VappWallpaperMreProvider::onResume()
{
    // Do nothing
}

void VappWallpaperMreProvider::onDesktopCursorChanged(VfxFloat curPos, VfxFloat oldPos)
{
    // Do nothing
}

VfxBool VappWallpaperMreProvider::onQuerySuspend(vapp_wp_provider_suspend_type_enum suspendType)
{
    // Follow base class's behavior
    if (suspendType == VAPP_WP_PROVIDER_SUSPEND_ON_DESKTOP_SWIPE)
    {
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

void VappWallpaperMreProvider::onEvent(vapp_wp_provider_event_struct* event)
{
    // Do nothing
}

/*****************************************************************************
* MRE Screen Lock Delegator
*****************************************************************************/

VFX_IMPLEMENT_CLASS("MRE Wallpaper", VappWallpaperMre, VappWallpaper);

VappWallpaperMre* s_wallpaperMre = NULL;

VappWallpaperMre::VappWallpaperMre() :
    m_mreId(),
    m_launcher(NULL),
    m_wallpaperProvider(NULL),
    m_asmGid(GRP_ID_INVALID),
    m_textFrmErr(NULL),
    m_errStrId(0),
    m_isSelfClose(VFX_FALSE),
    m_isCardPlugOut(VFX_FALSE),
    m_isCreateView(VFX_FALSE)
{
    // Do nothing.
}


VappWallpaperMre::~VappWallpaperMre()
{
    // Do nothing.
}


void VappWallpaperMre::onInit()
{
    VappWallpaper::onInit();
  
    //EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE
    //EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT
    //EVT_ID_USB_ENTER_MS_MODE
    
    mmi_frm_cb_reg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT,
        VappWallpaperMre::eventProc,
        getObjHandle());    

    mmi_frm_cb_reg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN,
        VappWallpaperMre::eventProc,
        getObjHandle()); 

    // error string
    VFX_OBJ_CREATE(m_textFrmErr, VfxTextFrame, this);   
    
    m_textFrmErr->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_textFrmErr->setColor(VFX_COLOR_WHITE);
    VfxSize size = getSize();
    m_textFrmErr->setPos(VfxPoint(size.width>>1, size.height>>1));
    m_textFrmErr->setAnchor(0.5f, 0.5f);
    m_textFrmErr->setHidden(VFX_TRUE);
}

void VappWallpaperMre::onDeinit()
{
    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT,
        VappWallpaperMre::eventProc,
        getObjHandle());
    
    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN,
        VappWallpaperMre::eventProc,
        getObjHandle());


    VappWallpaper::onDeinit();

}



void VappWallpaperMre::setMreId(const VfxString &mreId)
{
    m_mreId = mreId;
}

void VappWallpaperMre::setMreProvider(VappWallpaperMreProvider *wallpaperProvider)
{
    if (!wallpaperProvider)
    {
        m_wallpaperProvider = NULL;
    }
    else
    {
        m_wallpaperProvider = wallpaperProvider;
    }
}

void VappWallpaperMre::getName(VfxWString &wallpaperName)
{
    WCHAR *temp = wallpaperName.lockBuf(MMI_APP_NAME_MAX_LEN + 1); // 1: null terminated char
    mmi_ret ret;
    ret = srv_mre_appmgr_get_app_name(
         (mmi_app_package_char *)m_mreId.getBuf(),
         temp);
    wallpaperName.unlockBuf();

    if (ret != MMI_RET_OK)
    {
        wallpaperName.setEmpty();
    }
}


MMI_IMG_ID VappWallpaperMre::getThumbnail()
{
    // Get icon resource.
    mmi_image_src_struct imageSrc;
    mmi_ret ret;

    ret = srv_mre_appmgr_get_app_image(
         (mmi_app_package_char *)m_mreId.getBuf(),
         &imageSrc);

    if (ret != MMI_RET_OK)
    {
        return 0;
    }

    if (imageSrc.type == MMI_IMAGE_SRC_TYPE_RES_ID)
    {
        return imageSrc.data.res_id;
    }
    else
    {
        return 0;
    }
}

VfxBool VappWallpaperMre::getThumbnailImageSrc(VfxImageSrc &output)
{
    // Get icon resource.
    mmi_image_src_struct imageSrc;
    mmi_ret ret;

    ret = srv_mre_appmgr_get_app_image(
         (mmi_app_package_char *)m_mreId.getBuf(),
         &imageSrc);

    if (ret != MMI_RET_OK)
    {
        return VFX_FALSE;
    }

    switch (imageSrc.type)
    {
        case MMI_IMAGE_SRC_TYPE_RES_ID:
            output.setResId(imageSrc.data.res_id);
            break;

        case MMI_IMAGE_SRC_TYPE_PATH:
            output.setPath(VFX_WSTR_MEM((const VfxWChar *)imageSrc.data.path));
            break;

        case MMI_IMAGE_SRC_TYPE_ROM_MEMORY:
            output = VfxImageSrc(imageSrc.data.image.image_ptr, imageSrc.data.image.image_len);
            break;

        default:
            break;
    }

    return VFX_TRUE;
}


void VappWallpaperMre::onCreateView()
{
    VappWallpaper::onCreateView();

    // terminate previous VPI
    if (s_wallpaperMre)
    {
        s_wallpaperMre->releaseResource();
    }
    
    getResource();  

    m_isCreateView = VFX_TRUE;
}

void VappWallpaperMre::onReleaseView()
{   
    m_isCreateView = VFX_FALSE;
    
    releaseResource();
    
    VappWallpaper::onReleaseView();
}

void VappWallpaperMre::getResource()
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WALLPAPER_GET_RESOURCE);
	
    m_textFrmErr->setHidden(VFX_TRUE);
    
    initMemory();
    
    VfxBool ret;
    ret = launchVpi(); 
    
    if (!ret)
    {
        showDefault();
    } 
}

void VappWallpaperMre::releaseResource()
{   
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WALLPAPER_RELEASE_RESOURCE);

    showDefaultWallpaperFrame(VFX_FALSE);
    
    terminateVpi();

    deinitMemory();
}

void VappWallpaperMre::showDefault()
{   
    if (getIsPreview())
    {
        m_textFrmErr->setHidden(VFX_FALSE);
        m_textFrmErr->setString(m_errStrId);
    }
    else
    {
        showDefaultWallpaperFrame(VFX_TRUE);
    }
}

void VappWallpaperMre::onSerializeView()
{
    if (m_wallpaperProvider.isValid())
    {
        m_wallpaperProvider->onSerializeView();
    }
}

void VappWallpaperMre::onRestoreView()
{   
    if (!s_wallpaperMre)
    {
        getResource();

        if (m_wallpaperProvider.isValid())
        {
            m_wallpaperProvider->onDesktopCursorChanged(m_curPos, 0);
        }
    }
    else
    {
        if (m_wallpaperProvider.isValid())
        {
            m_wallpaperProvider->onRestoreView();
        }
    }
}

void VappWallpaperMre::onSuspend()
{
    if (m_wallpaperProvider.isValid())
    {
        m_wallpaperProvider->onSuspend();
    }
}

void VappWallpaperMre::onResume()
{
    if (m_wallpaperProvider.isValid())
    {
        m_wallpaperProvider->onResume();
    }
}

void VappWallpaperMre::onDesktopCursorChanged(VfxFloat curPos, VfxFloat oldPos)
{
    m_curPos = curPos;
    if (m_wallpaperProvider.isValid())
    {
        m_wallpaperProvider->onDesktopCursorChanged(m_curPos, oldPos);
    }
}

VfxBool VappWallpaperMre::onAllowSuspendOnSwipe()
{
    if (m_wallpaperProvider.isValid())
    {
        return m_wallpaperProvider->onQuerySuspend(VAPP_WP_PROVIDER_SUSPEND_ON_DESKTOP_SWIPE);
    }
    return VFX_TRUE;
}

VfxBool VappWallpaperMre::onAllowSuspendOnPenDown()
{
    if (m_wallpaperProvider.isValid())
    {
        return m_wallpaperProvider->onQuerySuspend(VAPP_WP_PROVIDER_SUSPEND_ON_PEN_DOWN);
    }
    return VFX_FALSE;
}

void VappWallpaperMre::onWidgetDragged(
      VfxPoint pos,
      VfxControl *targetWidget)
{
    vapp_wp_provider_pos_struct position;
    position.pos = pos;
    // TODO: confirm ??
    position.targetWidget = targetWidget;

    vapp_wp_provider_event_struct evt;
    evt.event = VAPP_WP_PROVIDER_EVENT_DRAGGED;
    evt.userData = &position;
    evt.size = sizeof(position);

    if (m_wallpaperProvider.isValid())
    {
        m_wallpaperProvider->onEvent(&evt);
    }
}

void VappWallpaperMre::onWidgetMoved(
      VfxPoint pos,
      VfxControl *targetWidget)
{
    vapp_wp_provider_pos_struct position;
    position.pos = pos;
    // TODO: confirm ??
    position.targetWidget = targetWidget;

    vapp_wp_provider_event_struct evt;
    evt.event = VAPP_WP_PROVIDER_EVENT_MOVED;
    evt.userData = &position;
    evt.size = sizeof(position);

    if (m_wallpaperProvider.isValid())
    {
        m_wallpaperProvider->onEvent(&evt);
    }
}

void VappWallpaperMre::onWidgetDropped(
      VfxPoint pos,
      VfxControl *targetWidget)
{
    vapp_wp_provider_pos_struct position;
    position.pos = pos;
    // TODO: confirm ??
    position.targetWidget = targetWidget;

    vapp_wp_provider_event_struct evt;
    evt.event = VAPP_WP_PROVIDER_EVENT_DROPPED;
    evt.userData = &position;
    evt.size = sizeof(position);

    if (m_wallpaperProvider.isValid())
    {
        m_wallpaperProvider->onEvent(&evt);
    }
}

VfxBool VappWallpaperMre::checkResource()
{
    if (!m_isCreateView)
    {
        return VFX_TRUE;
    }
    VfxBool valid = m_wallpaperProvider.isValid();

    return valid;
}

VfxBool VappWallpaperMre::onPenInput(VfxPenEvent &event)
{
    if (m_wallpaperProvider.isValid())
    {
        return m_wallpaperProvider->onPenInput(event);
    }
    return VFX_TRUE;
}


VfxBool VappWallpaperMre::launchVpi()
{
    // Get the VSO file path.
    WCHAR path[SRV_FMGR_PATH_MAX_LEN + 1]; // 1: null terminated char
    MMI_BOOL ret;
    VfxBool vfxRet;

#ifdef VAPP_WALLPAPER_MRE_SWLA_LOG
    SLA_CustomLogging("DW1", SA_start);
#endif    
    ret = srv_mre_appmgr_get_file_path(
            (mmi_app_package_char *)m_mreId.getBuf(),
            path);

#ifdef VAPP_WALLPAPER_MRE_SWLA_LOG
    SLA_CustomLogging("DW1", SA_stop);
#endif 

    if (!ret)
    {
        m_errStrId = STR_GLOBAL_FILE_NOT_FOUND;
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WALLPAPER_ERR, -1, __LINE__);
    
        return VFX_FALSE;
    }

    // create VPI launcher
    VFX_ASSERT(!m_launcher);

    VFX_OBJ_CREATE_EX(
        m_launcher,
        VpiAppLauncher,
        this,
        (VFX_WSTR_MEM((const VfxWChar *)path)));

#ifdef VAPP_WALLPAPER_MRE_SWLA_LOG
    SLA_CustomLogging("DW2", SA_start);
#endif

    // Get preload APP info.
    vfxRet = preparePreloadAppInfo(
            m_launcher,
            path,
            m_preloadInfo);

#ifdef VAPP_WALLPAPER_MRE_SWLA_LOG
    SLA_CustomLogging("DW2", SA_stop);
#endif 

    if (!vfxRet)
    {
        VFX_OBJ_CLOSE(m_launcher);        
        return VFX_FALSE;
    }

#ifdef VAPP_WALLPAPER_MRE_SWLA_LOG
    SLA_CustomLogging("DW3", SA_start);
#endif

    // Launch the VPP.
    vfxRet = m_launcher->launch(this, &m_preloadInfo);

#ifdef VAPP_WALLPAPER_MRE_SWLA_LOG
     SLA_CustomLogging("DW3", SA_stop);
#endif     
    if (!vfxRet || !m_wallpaperProvider.isValid())
    {
        releasePreloadAppInfo(m_launcher, m_preloadInfo);
        VFX_OBJ_CLOSE(m_launcher);
        m_errStrId = STR_GLOBAL_FAILED;
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WALLPAPER_ERR, -1, __LINE__);
    
        return VFX_FALSE;
    }
    
    m_launcher->m_signalQuitByInterrupt.connect(this, &VappWallpaperMre::onQuitByInterrupt);

    m_wallpaperProvider->setSize(getSize());

#ifdef VAPP_WALLPAPER_MRE_SWLA_LOG
    SLA_CustomLogging("DW4", SA_start);
#endif    
    m_wallpaperProvider->onCreateView();

#ifdef VAPP_WALLPAPER_MRE_SWLA_LOG
    SLA_CustomLogging("DW4", SA_stop);
#endif

    return VFX_TRUE;
}

void VappWallpaperMre::terminateVpi()
{
    // Release view.
    if (m_wallpaperProvider.isValid())
    {
        m_wallpaperProvider->onReleaseView();
    }

    // Close the VSO launcher.
    if (m_launcher)
    {        
        m_launcher->terminate();        

        if (m_isSelfClose)
        {
            m_launcher->m_signalDestroy.connect(this, &VappWallpaperMre::onDestroy);
        }
        else
        {
            onDestroy(NULL);
        }
    }
}

void VappWallpaperMre::onDestroy(VfxObject *obj)
{
    releasePreloadAppInfo(m_launcher, m_preloadInfo);
    VFX_OBJ_CLOSE(m_launcher);
}

VfxBool VappWallpaperMre::isDriveLetterMatch(
    const VfxU8 *driveLetter,
    VfxU32 count) const
{
    WCHAR path[SRV_FMGR_PATH_MAX_LEN + 1]; 
    MMI_BOOL ret;

    ret = srv_mre_appmgr_get_file_path(
            (mmi_app_package_char *)m_mreId.getBuf(),
            path);

    if (!ret)
    {
        return VFX_FALSE;
    }
    
    for (VfxU32 i = 0; i < count; i++)
    {
        if (toupper(driveLetter[i]) == toupper((VfxU8)path[0]))
        {
            return VFX_TRUE;
        }
    }

    return VFX_FALSE;
}

void VappWallpaperMre::handleCardPlugOut()
{
    if (!m_isCardPlugOut)
    {
        terminateVpi();

        // load default wallpaper
        m_errStrId = STR_GLOBAL_FILE_NOT_FOUND;
        showDefault();
        m_isCardPlugOut = VFX_TRUE;  
    }   
}

mmi_ret VappWallpaperMre::eventProc(mmi_event_struct *evt)
{
    VappWallpaperMre *mre;

    mre = (VappWallpaperMre *)handleToObject((VfxObjHandle)evt->user_data);
    VFX_OBJ_ASSERT_VALID(mre);

    switch (evt->evt_id)
    { 
    
    case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
    {
        // no memory resource, so no need to handle VPI issues
        if (mre->m_asmGid == GRP_ID_INVALID)
        {
            return MMI_RET_OK;
        }
        
        srv_fmgr_notification_dev_plug_event_struct *p;

        p = (srv_fmgr_notification_dev_plug_event_struct *)evt;

        VfxBool match;
        match = mre->isDriveLetterMatch(p->drv_letters, p->count);
        if (match)
        {
            mre->handleCardPlugOut();  
        }
        
        break;
    }

    case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
    {
        // no memory resource, so no need to handle VPI issues
        if (mre->m_asmGid == GRP_ID_INVALID)
        {
            return MMI_RET_OK;
        }
        
        srv_fmgr_notification_dev_plug_event_struct *p;

        p = (srv_fmgr_notification_dev_plug_event_struct *)evt;

        if (!mre->m_wallpaperProvider.isValid())
        {
            VfxBool match;
            match = mre->isDriveLetterMatch(p->drv_letters, p->count);
            if (match)
            {
                mre->m_isCardPlugOut = VFX_FALSE;
                
                // load MRE wallpaper
                mre->showDefaultWallpaperFrame(VFX_FALSE);

                VfxBool ret;
                ret = mre->launchVpi();  

                if (!ret)
                {
                    mre->showDefault();     
                }
            }
        }
        break;
    }


    default:
    {
        break;
    }

    }

    return MMI_RET_OK;
}

void VappWallpaperMre::onQuitByInterrupt(
    VfxObject *obj,
    VpiAppLauncher::QuitByInterrupTypeEnum cause)
{
    m_isSelfClose = VFX_TRUE;

    switch (cause)
    {
        case VpiAppLauncher::QUIT_TYPE_PLUG_OUT_T_CARD:            

            handleCardPlugOut();            
            break;    
    }    

    m_isSelfClose = VFX_FALSE;
}


VfxBool VappWallpaperMre::preparePreloadAppInfo(
    VpiAppLauncher *launcher,
    const WCHAR *path,
    vm_preload_app_info_t &info)
{
	//
	// Read memory requirement information from the VPP file.
	//
	if (!launcher->getPreloadInfo(info))
    {
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WALLPAPER_ERR, -1, __LINE__);
        m_errStrId = STR_GLOBAL_FILE_NOT_FOUND;
        return VFX_FALSE;
    } 
    
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WALLPAPER_APP_INFO, info.loadSize, info.heapSize);
	//
	// Allocate memory for code and data.
	//
    if (info.loadSize > 0)
    {
        info.loadBufSize = info.loadSize;
        info.loadBase = malloc(info.loadBufSize);

        if (!info.loadBase)
        {
            MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WALLPAPER_ERR, -1, __LINE__);
            m_errStrId = STR_GLOBAL_INSUFFICIENT_MEMORY;
            return VFX_FALSE;
        }
    }

    //
    // Allocate memory for heap.
    //
    if (info.heapSize > 0)
    {
        info.heapBufSize = info.heapSize;
        info.heapBase = malloc(info.heapBufSize);

        if (!info.heapBase)
        {
            MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WALLPAPER_ERR, -1, __LINE__);
            m_errStrId = STR_GLOBAL_INSUFFICIENT_MEMORY;
            free(info.loadBase);
            return VFX_FALSE;
        }
    }

    //
    // Preload the VPP
    //
    if (!launcher->preLoad(info))
    {
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WALLPAPER_ERR, -1, __LINE__);
        m_errStrId = STR_GLOBAL_FAILED;
        free(info.loadBase);
        free(info.heapBase);
        return VFX_FALSE;
    }

    return VFX_TRUE;
}


void VappWallpaperMre::releasePreloadAppInfo(
    VpiAppLauncher *launcher,
    vm_preload_app_info_t &info)
{
    // Backup the load and heap base before unload
    void *heapBase = info.heapBase;
    void *loadBase = info.loadBase;

    launcher->unload(info);
    
    if (heapBase)
    {
        free(heapBase);
    }

    if (loadBase)
    {
        free(loadBase);
    }
}


void VappWallpaperMre::initMemory()
{
    if (m_asmGid != GRP_ID_INVALID)
    {
        return; // already initialized.
    }

    if(GRP_ID_INVALID != getExternalMemorySource())
    {
        // use external-assigned group first
        m_asmGid = getExternalMemorySource();
        //kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_3, "[Wallpaper][MRE] use external asm grou %d", m_asmGroupId);
        return;
    }

    VadpAsmProperty property;

    m_asmGid = mmi_frm_group_create(
                GRP_ID_ROOT,
                GRP_ID_VAPP_WALLPAPER_MRE_ASM,
                &onAsmGroupEvent,
                getObjHandle());

    VFX_ASSERT(m_asmGid != GRP_ID_INVALID);

    VadpAsm::getProperty(m_asmGid, property);
    property.f_prepare_w_reserve = 0;
    property.f_hide_in_oom = 0;
    VadpAsm::setProperty(m_asmGid, property);

    // store mre object
    s_wallpaperMre = this;  
}


void VappWallpaperMre::deinitMemory()
{
    if(GRP_ID_INVALID != getExternalMemorySource())
    {
        m_asmGid = GRP_ID_INVALID;
        return;
    }

    if (m_asmGid != GRP_ID_INVALID)
    {
        mmi_frm_group_close(m_asmGid);
        m_asmGid = GRP_ID_INVALID;

        // reset mre object
        s_wallpaperMre = NULL;  
    }    
}

void *VappWallpaperMre::malloc(VfxS32 size)
{
    VFX_ASSERT(m_asmGid != GRP_ID_INVALID);

    void *memPtr = vadpAsmAlloc(m_asmGid, size);

    return memPtr;
}


void VappWallpaperMre::free(void *mem)
{
    VFX_ASSERT(m_asmGid != GRP_ID_INVALID);
    
    vadpAsmFree(m_asmGid, mem);    
}


mmi_ret VappWallpaperMre::onAsmGroupEvent(mmi_event_struct *evt)
{
    VappWallpaperMre *mre;

    mre = (VappWallpaperMre *)handleToObject((VfxObjHandle)evt->user_data);
    VFX_OBJ_ASSERT_VALID(mre);

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
            mre->releaseResource();
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

#endif /* defined(__MMI_VUI_WALLPAPER_MRE__) */

