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
 *  vapp_wallpaper.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen wallpaper base class
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

/*****************************************************************************
 * Include
 *****************************************************************************/
extern "C"
{
#include "mmi_trc_int.h"
#include "MMI_common_app_trc.h"
#include "trc/vadp_app_trc.h"
}
#include "vapp_wallpaper.h"
/* RHR start */
#include "vfx_cpp_base.h"    
#include "vfx_object.h"   
#include "vfx_sys_memory.h"  
#include "vfx_class_info.h"  
#include "vfx_control.h"   
#include "vfx_datatype.h"   
#include "vfx_basic_type.h" 
#include "vrt_datatype.h"    
#include "vfx_input_event.h"
#include "vfx_top_level.h"
#include "vfx_signal.h" 
#include "vfx_frame.h" 
#include "vrt_system.h"
/* RHR end */
#include "vapp_wallpaper_wide.h"

extern "C"
{
#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"                // for reg event
#include "mmi_rp_app_usbsrv_def.h"      // for reg event
#endif
#include "gpiosrvgprot.h"               // for reg event
#include "UcmSrvGprot.h"                // for reg event
}

#ifdef __VENUS_3D_UI_ENGINE__
#include "gles2\gl2.h"
#ifdef WIN32
    #define GL_CHECK(x) \
            x; \
            { \
                GLenum glError = glGetError(); \
                VRT_EXT_ASSERT(glError == GL_NO_ERROR, glError, glError, glError); \
            }
#else
    #define GL_CHECK(x)    x;
#endif
#endif // #ifdef __VENUS_3D_UI_ENGINE__

#ifdef __COSMOS_MMI_PACKAGE__
#include "vapp_wallpaper_setting_method_gprot.h"
#else
extern "C"
{
#include "SettingGprots.h"
#include "PhoneSetupGprots.h"
#include "WPSSProtos.h"
#include "AlertScreen.h"
}
#endif

#define SUSPEND_MAX 255

/*****************************************************************************
 * Home screen UI componet: base wallpaper class
 *****************************************************************************/
VFX_IMPLEMENT_VIRTUAL_CLASS("Wallpaper", VappWallpaper, VfxControl);

VappWallpaper::VappWallpaper() :
    m_isCreated(VFX_FALSE),
    m_isSerialized(VFX_FALSE),
    m_source(-1),
    m_suspendCount(0),
    m_numOfChild(0),
    m_isPreview(VFX_FALSE),
    m_fallbackImgFrame(NULL),
    m_state(STATE_NULL),
    m_totalDesktopPage(0),
    m_extAppId(0)
{
}

void VappWallpaper::onInit()
{
    VfxControl::onInit();
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WALLPAPER_ON_INIT);
    // Set wallpaper size
    setBounds(VfxRect(VFX_POINT_ZERO, getScreenSize()));
    setBgColor(VFX_COLOR_BLACK);
}


void VappWallpaper::onDeinit()
{
    m_suspendCount = 0;
    
    releaseView();
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WALLPAPER_ON_DEINIT);
    VfxControl::onDeinit();
}


void VappWallpaper::createView()
{
    if (!m_isCreated)
    {
        // remove fallback wallpaper
        showDefaultWallpaperFrame(VFX_FALSE);
        
        // Used to check memory leak.
        m_numOfChild = getChildCount();
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WALLPAPER_ON_CREATE_VIEW);
        onCreateView();
        m_isCreated = VFX_TRUE;
    }

    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    if (topLevel)
    {
        topLevel->m_signalShelterExist.connect(this, &VappWallpaper::onShelterExist);
    }
}


void VappWallpaper::releaseView()
{
    if (m_isCreated)
    {
        // remove fallback wallpaper
        showDefaultWallpaperFrame(VFX_FALSE);
        
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WALLPAPER_ON_RELEASE_VIEW);
        onReleaseView();

        // Used to check memory leak
        VfxS32 numOfChild = getChildCount();
//        VFX_ASSERT(m_numOfChild == numOfChild);
        
        m_isCreated = VFX_FALSE;
    }

    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    if (topLevel)
    {
        topLevel->m_signalShelterExist.disconnect(this, &VappWallpaper::onShelterExist);
    }
}

void VappWallpaper::onShelterExist(VfxBool isExist)
{
    if (isExist)
    {
        suspend();
    }
    else
    {
        resume();
    }
}

void VappWallpaper::onCreateView()
{
}


void VappWallpaper::onReleaseView()
{
}


void VappWallpaper::doPenInput(VfxPenEvent &event)
{
    if(m_suspendCount)
    {
        // do not transmit pen event when wallpaper suspended
        return;
    }

    onPenInput(event);
}


VfxBool VappWallpaper::onPenInput(VfxPenEvent &event)
{
    return VFX_TRUE;
}


VfxBool VappWallpaper::isAllowSuspendOnSwipe()
{
    return onAllowSuspendOnSwipe();
}


VfxBool VappWallpaper::onAllowSuspendOnSwipe()
{
    return VFX_TRUE;
}


VfxBool VappWallpaper::isAllowSuspendOnPenDown()
{
    return onAllowSuspendOnPenDown();
}


VfxBool VappWallpaper::onAllowSuspendOnPenDown()
{
    return VFX_FALSE;
}


void VappWallpaper::onSerializeView()
{
    // Do nothing.
}


void VappWallpaper::onRestoreView()
{
    // Do nothing.
}


void VappWallpaper::onSuspend()
{
}


void VappWallpaper::onResume()
{
}


void VappWallpaper::serializeView()
{
    // Serialize & restore mechanism is only feasible when the view is created.
    VFX_ASSERT(m_isCreated);

    if (!m_isSerialized)
    {
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WALLPAPER_ON_SERIALIZE_VIEW);
        onSerializeView();
        m_isSerialized = VFX_TRUE;
    }
}


void VappWallpaper::restoreView()
{
    // Serialize & restore mechanism is only feasible when the view is created.
    VFX_ASSERT(m_isCreated);

    if (m_isSerialized)
    {
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WALLPAPER_ON_RESTORE_VIEW);
        onRestoreView();
        m_isSerialized = VFX_FALSE;
        
        // if already resumed before restoreView(),
        // we should resume the wallpaper
        if(!isSuspended())
        {
             // Register backlight event
            VfxRenderer* renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
            renderer->m_signalBacklightSwitch.connect(this, &VappWallpaper::backlightSwitchHdlr);
            MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WALLPAPER_ON_RESUME);
            onResume();
        }
    }
}


void VappWallpaper::suspend()
{
    if(!m_isCreated)
    {
        return;
    }
    
    if (m_suspendCount >= SUSPEND_MAX)
    {
        return;
    }
    if(m_suspendCount == 0 && !m_isSerialized)
    {
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WALLPAPER_ON_SUSPEND);
        VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();
        onSuspend();
    }
    ++m_suspendCount;
}

void VappWallpaper::resume()
{
    if(!m_isCreated)
    {
        return;
    }

    if (m_suspendCount == 0)
    {
        return;
    }
    --m_suspendCount;
    
    // don't allow resume when serialized. 
    // we'll resume when restoreView() is called.
    if (m_suspendCount == 0 && !m_isSerialized)
    {
        // Register backlight event
        VfxRenderer* renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        renderer->m_signalBacklightSwitch.connect(this, &VappWallpaper::backlightSwitchHdlr);
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WALLPAPER_ON_RESUME);
        onResume();
    }
}

VfxBool VappWallpaper::isSuspended()
{
    return (m_suspendCount > 0);
}

void VappWallpaper::setSource(VfxS32 source)
{
    if(source >= VAPP_WALLPAPER_SRC_LAST_ITEM)
    {
        VFX_ASSERT(0);
    }
    m_source = source;
}


S32 VappWallpaper::getSource()
{
    return m_source;
}


void VappWallpaper::setWidgetDragged(
        VfxPoint pos,
        VfxControl *targetWidget)
{
    onWidgetDragged(pos, targetWidget);
}

void VappWallpaper::setWidgetMoved(
        VfxPoint pos,
        VfxControl *targetWidget)
{
    onWidgetMoved(pos, targetWidget);
}

void VappWallpaper::setWidgetDropped(
        VfxPoint pos,
        VfxControl *targetWidget)
{
    onWidgetDropped(pos, targetWidget);
}

void VappWallpaper::onWidgetDragged(
        VfxPoint pos,
        VfxControl *targetWidget)
{
}

void VappWallpaper::onWidgetMoved(
        VfxPoint pos,
        VfxControl *targetWidget)
{
    VFX_UNUSED(pos);
    VFX_UNUSED(targetWidget);
}

void VappWallpaper::onWidgetDropped(
        VfxPoint pos,
        VfxControl *targetWidget)
{
    VFX_UNUSED(pos);
    VFX_UNUSED(targetWidget);
}

void VappWallpaper::setDesktopBoundsChanged(
        const VfxU32 totalPage,
        VfxFrame *source,
        const VfxRect &oldBounds)
{
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else
    // TODO: remove later. also notify old-style wallpapers
    onDesktopBoundsChanged(totalPage, source, oldBounds);

    // new-style cursor
    const VfxS32 curPos = source->getBounds().origin.x;
    const VfxS32 oldPos = oldBounds.origin.x;
    const VfxS32 a = vfxMax((VfxS32)1, (VfxS32)(totalPage-1)*source->getBounds().getWidth());
    setDesktopCursorChanged(curPos * 1.0f / a, oldPos * 1.0f / a);
    #endif
}

void VappWallpaper::setDesktopCursorChanged(VfxFloat curPos, VfxFloat oldPos)
{
    if(m_fallbackImgFrame)
    {
        VappWallpaperWide::adjustWallpaperByDesktopCursor(m_fallbackImgFrame, curPos);
    }
    onDesktopCursorChanged(curPos, oldPos);
}

void VappWallpaper::backlightSwitchHdlr(VfxBool on)
{
    if(on)
    {
        resume();
    }
    else
    {
        suspend();
    }
}
 
void VappWallpaper::onDesktopBoundsChanged(
        const VfxU32 totalPage,
        VfxFrame *source,
        const VfxRect &oldBounds)
{
    VFX_UNUSED(totalPage);
    VFX_UNUSED(source);
    VFX_UNUSED(oldBounds);
}

void VappWallpaper::onDesktopCursorChanged(VfxFloat curPos, VfxFloat oldPos)
{
    VFX_UNUSED(curPos);
    VFX_UNUSED(oldPos);
}

MMI_IMG_ID VappWallpaper::getThumbnail()
{
    return 0;
}

VfxBool VappWallpaper::getThumbnailImage(VfxImageBuffer &output)
{
    return VFX_FALSE;
}

VfxBool VappWallpaper::getThumbnailImageSrc(VfxImageSrc &output)
{
    return VFX_FALSE;
}

void VappWallpaper::getName(VfxWString &wallpaperName)
{
    wallpaperName.setEmpty();
    return;
}

VfxBool VappWallpaper::checkResource()
{ 
    return VFX_TRUE;
}

void VappWallpaper::setTotalPage(VfxS32 page)
{
    m_totalDesktopPage = page;
}


VfxS32 VappWallpaper::getTotalPage()
{
    return m_totalDesktopPage;
}

void VappWallpaper::setExternalMemorySource(VfxId appId)
{
    m_extAppId = appId;
}

VfxId VappWallpaper::getExternalMemorySource() const
{
    return m_extAppId;
}

VfxU32 VappWallpaper::getVrtMemFactor()
{
#if defined(__VENUS_3D_UI_ENGINE__)

    #if defined(__MMI_MAINLCD_480X800__)
        #define EXTRA_CACHE_MEM_FACTOR_WITH_IG  30
    #elif defined(__MMI_MAINLCD_320X480__)
        #define EXTRA_CACHE_MEM_FACTOR_WITH_IG  40
    #else
        #define EXTRA_CACHE_MEM_FACTOR_WITH_IG  45
    #endif

    return GDI_LCD_WIDTH * GDI_LCD_HEIGHT * 2 * EXTRA_CACHE_MEM_FACTOR_WITH_IG;

#endif
    
    return 0;
}

VfxSize VappWallpaper::getScreenSize()
{
    vrt_size_struct main_screen_size;
    vrt_color_type_enum main_screen_color_format;

    vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

    return VfxSize(main_screen_size.width, main_screen_size.height);
}

void VappWallpaper::setPreview(VfxBool isPreview)
{
    m_isPreview = isPreview;
}

void VappWallpaper::restoreWallpaperSetting(VfxId errStr)
{
    if(m_isPreview) 
    {
        return;
    }
       
    const VappWallpaperSrcEnum source = (VappWallpaperSrcEnum)getSource();
#ifdef __COSMOS_MMI_PACKAGE__
    // restore wallpaper back to default
    VappWallpaperSettingInterface *wallpaperInterface = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
    wallpaperInterface->restoreWallpaper((VappWallpaperType)source);
#else
    switch(source)
    {
    case VAPP_WALLPAPER_SRC_HOMESCREEN:
        PhnsetWallpaperBadFileCallBack(errStr);
        break;
    case VAPP_WALLPAPER_SRC_LOCK:
        mmi_phnset_lock_wallpaper_bad_file_callback(errStr);
        break;
    }
#endif
}

void VappWallpaper::showDefaultWallpaperFrame(VfxBool show)
{
    if(!show)
    {
        VFX_OBJ_CLOSE(m_fallbackImgFrame);
    }
    else if(getIsPreview())
    {
        setBgColor(VFX_COLOR_BLACK);
    }
    else 
    {
        if(NULL == m_fallbackImgFrame)
        {
            m_fallbackImgFrame = VappWallpaperWide::createDefaultWallpaperFrame(this);   
        }
        m_fallbackImgFrame->bringToFront();    
    }
}

mmi_id VappWallpaper::findRootAppGroupId(VfxFrame *obj)
{
#ifdef __COSMOS_MMI_PACKAGE__
    mmi_id appId = NULL;
    VfxApp *pApp = NULL;
    VfxScreen *topScr = NULL;
    for(VfxFrame *f = obj; f != NULL; f = f->getParentFrame())
    {
        topScr = VFX_OBJ_DYNAMIC_CAST(f, VfxScreen);
        if(topScr)
        {
            break;
        }
    }
    if(NULL == topScr)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_FIND_ROOT_APP_GROUP_ID_FIND_SCREEN_FAILED);
        return NULL;
    }

    for(VfxObject *pObj = topScr; pObj != NULL; pObj = pObj->getParent())
    {
        pApp = VFX_OBJ_DYNAMIC_CAST(pObj, VfxApp);
        if(pApp != NULL)
        {
            appId = pApp->getGroupId();
            return appId;
        }
    }

    // root is not VfxApp, why?
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_FIND_ROOT_APP_GROUP_ID_FAILED);
    return NULL;
#else
    return NULL;
#endif
}

void VappWallpaper::registerEvents(VfxBool isReg)
{
    typedef mmi_ret (*PFNFrameworkRegFunc)(U16 evt_id, mmi_proc_func call_back, void *user_data);
    PFNFrameworkRegFunc regFunc = isReg ? &mmi_frm_cb_reg_event : &mmi_frm_cb_dereg_event;

    const static U16 events[] = {EVT_ID_GPIO_AFTER_LCD_SLEEP_IN,
                                 EVT_ID_GPIO_LCD_SLEEP_OUT,
                                 EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN,
                                 EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT,
                                 EVT_ID_SRV_UCM_INDICATION,
                                 #ifdef __MMI_USB_SUPPORT__
                                 EVT_ID_USB_ENTER_MS_MODE,
                                 EVT_ID_USB_EXIT_MS_MODE
                                 #endif
                                 };

    VfxObjHandle hObj = getObjHandle();
    for(VfxS32 i = 0; i < sizeof(events) / sizeof(events[0]); ++i)
    {
        regFunc(events[i], &VappWallpaper::onEvent, hObj);
    }
}

mmi_ret VappWallpaper::onEvent(mmi_event_struct *param)
{
    VappWallpaper *pThis = (VappWallpaper*)VfxObject::handleToObject((VfxObjHandle)param->user_data);
    if(NULL == pThis)
    {
        return MMI_RET_OK;
    }

    // dispatch to child
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_HANDLE_EVENT_EVT_D, param->evt_id);
    mmi_ret ret = pThis->handleEvent(param);
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_WALLPAPER_HANDLE_EVENT_RET_D, ret);
    return ret;
}

mmi_ret VappWallpaper::handleEvent(mmi_event_struct *param)
{
    return MMI_RET_OK;
}


#ifdef __VENUS_3D_UI_ENGINE__
extern "C" GDI_RESULT gdi_image_parse_info(
                gdi_image_src_enum src_type,
                U8 *img_src,
                U8 **data_ptr,
                U8 *img_type,
                S32 *img_size,
                S32 *frame_number,
                S32 *width,
                S32 *height);

GLuint VappWallpaper::loadResourceTexture(const U16 resId)
{
    typedef struct KTX_header_t {
    vrt_u8  identifier[12];
    vrt_u32 endianness;
    vrt_u32 glType;
    vrt_u32 glTypeSize;
    vrt_u32 glFormat;
    vrt_u32 glInternalFormat;
    vrt_u32 glBaseInternalFormat;
    vrt_u32 pixelWidth;
    vrt_u32 pixelHeight;
    vrt_u32 pixelDepth;
    vrt_u32 numberOfArrayElements;
    vrt_u32 numberOfFaces;
    vrt_u32 numberOfMipmapLevels;
    vrt_u32 bytesOfKeyValueData;
    } KTX_header;
    
    // Texture object handle
    GLuint textureId = 0;

    // Use tightly packed data
    glPixelStorei ( GL_UNPACK_ALIGNMENT, 1 );
    // Generate a texture object
    glGenTextures ( 1, &textureId );
    // Bind the texture object
    glBindTexture ( GL_TEXTURE_2D, textureId );

    // Load KTX data
    S32 imgWidth = 0, imgHeight = 0;
    PU8 mem_buffer = (PU8)GetImage(resId);
    vrt_u8 img_type = mem_buffer[0];
    VFX_ASSERT(GDI_IMAGE_TYPE_KTX == img_type);
    vrt_u8 *data_ptr;
    vrt_u32 faceLodSize = 0;
    S32 img_size = 0;
    S32 frame_number = 0;
    gdi_image_parse_info(GDI_IMAGE_SRC_FROM_RESOURCE, mem_buffer, &data_ptr, &img_type, &img_size, &frame_number, &imgWidth, &imgHeight);

    KTX_header header;
    memcpy(&header, data_ptr, sizeof(KTX_header));
    data_ptr += sizeof(KTX_header) + header.bytesOfKeyValueData;
    memcpy(&faceLodSize, data_ptr, sizeof(vrt_u32));
    data_ptr += sizeof(vrt_u32);
    GL_CHECK(glCompressedTexImage2D ( GL_TEXTURE_2D, 0, header.glInternalFormat, header.pixelWidth, header.pixelHeight, 0, faceLodSize , data_ptr));

    // Set the filtering mode
    glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
    glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    return textureId;
}
#endif
