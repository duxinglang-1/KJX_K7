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
 *  vapp_imgclip_cui.cpp
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

extern "C" 
{
    #include "MMI_features.h" 
}

#ifdef __MMI_COSMOS_IMAGECLIPPER__
 
#include "vcui_imgedt_gprot.h"
#include "vapp_imgedt_util.h"
#include "vapp_imgclip_cui.h"
#include "mmi_rp_vapp_imgedt_def.h"
#include "mmi_rp_vcui_imgclip_def.h"

extern "C"
{
#include "gdi_layer.h"
#include "gdi_include.h"
#include "gd_include.h"
#include "gdi_image_dev_bmp.h"
#include "kal_public_api.h"
#include "FileMgrSrvGprot.h"
#include "FileMgrType.h"
#include "mmi_rp_srv_filemanager_def.h" //need error id
#include "Mmi_cb_mgr_gprot.h" 
#ifdef __MMI_USB_SUPPORT__
#include "mmi_rp_app_usbsrv_def.h"
#endif /*__MMI_USB_SUPPORT__*/
#ifdef __DRM_SUPPORT__
#include "Drm_Gprot.h"
#endif

typedef struct cui_imgclip_error_info_struct
{
    S32             error;      // error code value
    mmi_str_id      strID;      // error string ID
} cui_imgclip_error_info_struct;

const static cui_imgclip_error_info_struct g_cui_imgedt_error_table[] = 
{
    {CUI_IMGEDT_E_UNEXPECTED,                STR_GLOBAL_ERROR },
    {CUI_IMGEDT_E_INVALID_ARGS,              STR_GLOBAL_ERROR },
    {CUI_IMGEDT_E_NOT_ENOUGH_BUFFER,         STR_GLOBAL_NOT_ENOUGH_MEMORY },
    {CUI_IMGEDT_E_FILE_ACCESS_DENIED,        STR_ID_VCUI_IMGEDT_FS_ACCESS_DENIED_TEXT },
    {CUI_IMGEDT_E_UNSUPPORTED_RESOLUTION,    STR_ID_VCUI_IMGEDT_UNSUPPORTED_RESOLUTION},
    {CUI_IMGEDT_E_UNSUPPORTED_FORMAT,        STR_GLOBAL_UNSUPPORTED_FORMAT },
    {CUI_IMGEDT_E_NOT_IMPLEMENTED,           STR_GLOBAL_ERROR },
    {GDI_IMAGE_ENCODER_ERR_DISK_FULL,        STR_GLOBAL_NOT_ENOUGH_MEMORY},
    {GDI_IMAGE_ENCODER_ERR_WRITE_PROTECTION, FMGR_FS_WRITE_PROTECTION_TEXT},
    {GDI_IMAGE_ENCODER_ERR_NO_DISK,          STR_ID_VCUI_IMGEDT_FS_MSDC_NOT_PRESENT_TEXT},
    {GDI_IMAGE_ENCODER_ERR_ROOT_DIR_FULL,    FMGR_FS_ROOT_DIR_FULL_TEXT}
};

#define CUI_IMGEDT_ERROR_TABLE_SIZE        (sizeof(g_cui_imgedt_error_table)/sizeof(cui_imgclip_error_info_struct))

S32 cui_vapp_imgclip_is_file_support(const WCHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32         imgWidth, imgHeight;
    S32         view_x, view_y, view_w, view_h;
    S32         ret = CUI_IMGEDT_OK;
    FS_HANDLE   fs;
    GDI_RESULT  gdi_res;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_IS_FILE_SUPPORT, __LINE__);

    do
    {
    #ifdef __DRM_SUPPORT__
        if(DRM_METHOD_NONE != DRM_get_object_method(0, (kal_wchar*)path))
        {
            ret = CUI_IMGEDT_E_FILE_ACCESS_DENIED;
            break;
        }
    #endif /* __DRM_SUPPORT__ */

        if ((fs = FS_Open(path, FS_READ_ONLY)) < FS_NO_ERROR)
        {
            ret = CUI_IMGEDT_E_FILE_ACCESS_DENIED; 
            break;
        }
        FS_Close(fs);

        if (GDI_IMAGE_TYPE_INVALID == gdi_image_get_type_from_file((CHAR*) path))
        {
            ret = CUI_IMGEDT_E_UNSUPPORTED_FORMAT;
            break;
        }
    
        gdi_res = gdi_imgdec_get_dimension_file((U8*)path, &imgWidth, &imgHeight);
        if(GDI_SUCCEED != gdi_res)
        {
            ret = CUI_IMGEDT_E_UNSUPPORTED_FORMAT;
            break;
        }
        else
        {
            if((imgWidth  < IMGEDT_CLIP_MIN_LENGHTH) ||
               (imgHeight < IMGEDT_CLIP_MIN_LENGHTH))
            {
                ret = CUI_IMGEDT_E_UNSUPPORTED_RESOLUTION;
                break;
            }

            //init preview rect
            gdi_util_fit_box(GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT, 
                             GDI_LCD_WIDTH, 
                             GDI_LCD_HEIGHT, 
                             imgWidth, 
                             imgHeight, 
                             &view_x,
                             &view_y, 
                             &view_w, 
                             &view_h);
             if (view_w < IMGEDT_CLIP_MIN_LENGHTH || view_h < IMGEDT_CLIP_MIN_LENGHTH)
             {
                ret = CUI_IMGEDT_E_UNSUPPORTED_RESOLUTION;
                break;
             }
        }
    }while(0);

    //VAPP_IMGEDT_INFO_TRACE(ret);
    return ret;
}

mmi_id cui_vapp_imgclip_get_error_string(mmi_id cui_id, S32 error_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_IMGCLIP_GET_ERR_STR, error_id);
    //(void)cui_id;

    for(index = 0; index < CUI_IMGEDT_ERROR_TABLE_SIZE; index++)
    {
        if (g_cui_imgedt_error_table[index].error == error_id)
        {
            return g_cui_imgedt_error_table[index].strID;
        }
    }
    return STR_GLOBAL_ERROR;
}

mmi_id cui_vapp_imgclip_create(mmi_id parent_gid, const cui_imgclip_launch_struct* arg)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_IMGCLIP_CREATE, parent_gid);
    
    S32 ret = cui_vapp_imgclip_is_file_support((WCHAR*)arg->scr_file_path);
    mmi_id cui_id;
    if (CUI_IMGEDT_OK == ret)
    {
        cui_id = VfxAppLauncher::createCui(
                                    VCUI_IMGCLIP,
                                    VFX_OBJ_CLASS_INFO(VappImgClipCui),
                                    parent_gid,
                                    (void*)arg,
                                    sizeof(*arg));
    }
    else
    {
        cui_id = 0;
    }
    //VAPP_IMGEDT_INFO_TRACE(cui_id);
    return cui_id;
}

S32 cui_vapp_imgclip_run(mmi_id cui_gid)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_IMGCLIP_RUN, cui_gid);
    VfxAppLauncher::runCui(cui_gid);
    return CUI_IMGEDT_OK;
}

S32 cui_vapp_imgclip_close(mmi_id cui_gid)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_IMGCLIP_CLOSE, cui_gid);
    VfxAppLauncher::terminate(cui_gid);
    return CUI_IMGEDT_OK;
}

S32 cui_vapp_imgclip_get_user_data(mmi_id cui_id, U32 *user_data)
{    
    VappImgClipCui *cui = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappImgClipCui);
    cui->getUserData(user_data);
    //VAPP_IMGEDT_INFO_TRACE(user_data);
    return CUI_IMGEDT_OK;
}

S32 cui_vapp_imgclip_set_layout(mmi_id cui_id, cui_imgclip_layout_enum layout)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_IMGCLIP_SET_LAYOUT, cui_id, layout);
    VappImgClipCui *cui = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappImgClipCui);
    cui->setLayoutStyle(layout);
    return CUI_IMGEDT_OK;
}

S32 cui_vapp_imgclip_set_resolution(mmi_id cui_id, cui_imgclip_resolution_enum resolution)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_IMGCLIP_SET_RESOLUTION, cui_id, resolution);
    return CUI_IMGEDT_E_NOT_IMPLEMENTED;
}

S32 cui_vapp_imgclip_set_ratio_fixed(mmi_id cui_id, MMI_BOOL is_fixed)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_IMGCLIP_SET_RATIO_FIXED, cui_id, is_fixed);
    VappImgClipCui *cui = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappImgClipCui);
    cui->setIsRatioFixed((VfxBool)is_fixed);
    return CUI_IMGEDT_OK;
}

S32 cui_vapp_imgclip_set_ratio(mmi_id cui_id, S32 ratio_w, S32 ratio_h)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_IMGCLIP_SET_RATIO_FIXED, cui_id, ratio_w, ratio_h);
    VappImgClipCui *cui = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappImgClipCui);
    cui->setRatio(ratio_w, ratio_h);
    return CUI_IMGEDT_OK;
}

S32 cui_vapp_imgclip_set_size(mmi_id cui_id, S32 width, S32 height, MMI_BOOL isDestSize)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_IMGCLIP_SET_DEST_SIZE, cui_id, width, height);
    VappImgClipCui *cui = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappImgClipCui);
    if (width > GDI_LCD_HEIGHT || height > GDI_LCD_HEIGHT)
    {
        //not allow larger then GDI_LCD_HEIGHT !!!
        return CUI_IMGEDT_E_NOT_ENOUGH_BUFFER;
    }
    else
    {
    	if(isDestSize)
        cui->setDestDimension(width, height);
		else
			cui->setlimitDimension(width, height);
		
        return CUI_IMGEDT_OK;
    }
}

S32 cui_vapp_imgclip_set_dest_size(mmi_id cui_id, S32 width, S32 height)
{
	return cui_vapp_imgclip_set_size(cui_id,width, height,MMI_TRUE);
	
    /*MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_IMGCLIP_SET_DEST_SIZE, cui_id, width, height);
    VappImgClipCui *cui = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappImgClipCui);
    if (width > GDI_LCD_HEIGHT || height > GDI_LCD_HEIGHT)
    {
        //not allow larger then GDI_LCD_HEIGHT !!!
        return CUI_IMGEDT_E_NOT_ENOUGH_BUFFER;
    }
    else
    {
        cui->setDestDimension(width, height);
        return CUI_IMGEDT_OK;
    }*/
}

S32 cui_vapp_imgclip_set_size_limit(mmi_id cui_id, S32 width, S32 height)
{
	return cui_vapp_imgclip_set_size(cui_id,width, height,MMI_FALSE);

    /*MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_IMGCLIP_SET_DEST_SIZE, cui_id, width, height);
    VappImgClipCui *cui = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappImgClipCui);
    if (width > GDI_LCD_HEIGHT || height > GDI_LCD_HEIGHT)
    {
        //not allow larger then GDI_LCD_HEIGHT !!!
        return CUI_IMGEDT_E_NOT_ENOUGH_BUFFER;
    }
    else
    {
        cui->setlimitDimension(width, height);
        return CUI_IMGEDT_OK;
    }    */
}

S32 cui_vapp_imgclip_set_dest_path(mmi_id cui_id, const U8* path)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_IMGCLIP_SET_DEST_SIZE, cui_id);
    VappImgClipCui *cui = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappImgClipCui);
    cui->setDestPath((VfxU8 *)path);
    return CUI_IMGEDT_OK;
}

S32 cui_vapp_imgclip_get_dest_path(mmi_id cui_id, CHAR* path)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_IMGCLIP_GET_DEST_PATH, cui_id);
    VappImgClipCui *cui = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappImgClipCui);
    cui->getDestPath((VfxU8*)path);
    return CUI_IMGEDT_OK;
}

S32 cui_vapp_imgclip_get_dest_size(mmi_id cui_id, S32* width, S32* height)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_IMGCLIP_GET_DEST_SIZE, cui_id);
    VappImgClipCui *cui = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappImgClipCui);
    cui->getDestDimension(width, height);
    //VAPP_IMGEDT_INFO_TRACE(*width);
    //VAPP_IMGEDT_INFO_TRACE(*height);
    return CUI_IMGEDT_OK;
}

S32 cui_vapp_imgclip_get_src_size(mmi_id cui_id, S32* width, S32* height)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_IMGCLIP_GET_SRC_SIZE, cui_id);
    VappImgClipCui *cui = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappImgClipCui);
    cui->getSrcDimension(width, height);
    //VAPP_IMGEDT_INFO_TRACE(*width);
    //VAPP_IMGEDT_INFO_TRACE(*height);
    return CUI_IMGEDT_OK;
}

S32 cui_vapp_imgclip_save_pbm_file(mmi_id cui_id,MMI_BOOL savePbmFile)
{
    VappImgClipCui *cui = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VappImgClipCui);
    cui->savePbmFile(savePbmFile);

    return CUI_IMGEDT_OK;
}

} /* extern "C" */

//------ C++ part -------//

/***************************************************************************** 
 * Class VappImgEdtClipCuiPage
 *****************************************************************************/
VfxPage* VappImgEdtClipCuiPage::m_pageInst = NULL;

VFX_IMPLEMENT_CLASS("VappImgEdtClipCuiPage", VappImgEdtClipCuiPage, VfxPage);
VappImgEdtClipCuiPage::VappImgEdtClipCuiPage():
m_clipWd(NULL),
m_bottomBar(NULL),
m_waitIcon(NULL),
m_previewFrame(NULL),
m_pDecodeMem(NULL),
m_pPreviewLayerMem(NULL),
m_previewHdl(NULL),
m_renderHdl(NULL),
m_jobHdl(NULL),
m_state(0),
m_lastError(0),
m_isRedrawBg(VFX_FALSE)
{
}

void VappImgEdtClipCuiPage::onInit()
{
    VfxPage::onInit();
    VappImgEdtClipCuiPage::m_pageInst = (VfxPage*)this;

    setStatusBar(VFX_FALSE);
    setBgColor(VFX_COLOR_BLACK);
    
    VappImgEdtBaseScr *scr = VFX_OBJ_DYNAMIC_CAST(getMainScr(), VappImgEdtBaseScr);
    if (scr->checkVertMode())
    {
        setBounds(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
    }
    else
    {
        setBounds(0, 0, GDI_LCD_HEIGHT, GDI_LCD_WIDTH);
    }
    
    VFX_OBJ_CREATE(m_previewFrame, VfxFrame, this);
    m_previewFrame->setBounds(getBounds());
    m_previewFrame->setHints(VFX_FRAME_HINTS_DISABLE_COLOR_KEY);
	m_previewFrame->setBgColor(VFX_COLOR_BLACK);

    VfxS32 ratio_w, ratio_h;
    VappImgClipCui *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VappImgClipCui);
    VFX_OBJ_CREATE(m_clipWd, VcpImgEdtClipWindow, this);
    m_clipWd->setBounds(getBounds());
    m_clipWd->setFreeze(VFX_FALSE);
    cui->getRatio(&ratio_w, &ratio_h);
    if ((ratio_w != 0) && (ratio_h != 0))
    {
        m_clipWd->setRatio(ratio_w, ratio_h); 
        m_clipWd->setRatioFixed(cui->getIsRatioFixed());
    }

    //create bottom bar
    VFX_OBJ_CREATE(m_bottomBar, VcpImgEdtBottomBar, this);
    m_bottomBar->setBgSize(VfxSize(getBounds().getWidth(), IMGEDT_BOTTOM_BAR_HEIGHT));
    m_bottomBar->setBtnHeight(IMGEDT_BOTTOM_BAR_HEIGHT);
    m_bottomBar->setTranslucent(VFX_TRUE);
    m_bottomBar->m_signalBtnTap.connect(this, &VappImgEdtClipCuiPage::onBottomBtnClicked);
    m_bottomBar->show();
}

void VappImgEdtClipCuiPage::onDeinit()
{
	setWaitIconShown(VFX_FALSE);
    VappImgEdtClipCuiPage::m_pageInst = NULL;
    VfxPage::onDeinit();
}

void VappImgEdtClipCuiPage::onEnter(VfxBool isBackward)
{
    if (NULL == VappImgEdtClipCuiPage::m_pageInst)
    {
        VappImgEdtClipCuiPage::m_pageInst = (VfxPage*)this;
    }

    setStatusBar(VFX_FALSE);

    //is redraw bg for small screen, do not show image and clipwindow
    m_isRedrawBg = getMainScr()->getIsSnapshotDrawing();
    if (m_isRedrawBg)
    {
        m_clipWd->setHidden(VFX_TRUE);
        return;
    }
    else
    {
        m_clipWd->setHidden(VFX_FALSE);
    }
    
    VappImgClipCui *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VappImgClipCui);

    prepareMem();
    m_previewHdl = prepareLayer(getBounds(), 
                                (VfxU8*)m_pPreviewLayerMem, 
                                (VfxU8*)cui->getSrcFilePath().getBuf());
    onCuiStateChange(STATE_INITED);
                                
    if (0 != updateImgRect())
    {
        return;
    }    
    //VFX_ASSERT(NULL != m_previewHdl);  //already has a assert in prepareLayer()
    
    showFrame(m_previewFrame, getBounds(), (VfxU8*)m_pPreviewLayerMem);
    m_jobHdl = createGdiJob(m_previewHdl, m_previewRect, (VfxU8*)cui->getSrcFilePath().getBuf());

    m_clipWd->setImgRect(m_previewRect);
    m_clipWd->show();
    
    onCuiStateChange(STATE_DRAWING);

    VfxPage::onEnter(isBackward);
}

void VappImgEdtClipCuiPage::onEntered()
{
     if (m_isRedrawBg)
    {
        m_previewFrame->setHidden(VFX_TRUE);
        return;
    }
    //else
    //{
    //    m_previewFrame->setHidden(VFX_FALSE);
    //}
    
    VfxPage::onEntered();
    if (CUI_IMGEDT_OK != m_lastError)
    {
        onCuiStateChange(STATE_ERROR);
    }
}


void VappImgEdtClipCuiPage::onExit(VfxBool isBackward)
{
    if (m_isRedrawBg)
    {
        return;
    }

    VfxPage::onExit(isBackward);

    cancelAll();
    if (STATE_IDLE != m_state)
    {
        unprepareLayer(&m_renderHdl);
        unprepareLayer(&m_previewHdl);
        unprepareMem();
        onCuiStateChange(STATE_IDLE);
    }
}

void VappImgEdtClipCuiPage::onBack()
{
    VappImgClipCui *vcui = VFX_OBJ_DYNAMIC_CAST(getApp(), VappImgClipCui);
	
	if(NULL == m_waitIcon)
	{
		setWaitIconShown(VFX_TRUE);
	}
	VfxWString path = vcui->getSrcFilePath();
	VfxImageSrc tempImgSrc = VfxImageSrc(path);
	
	m_previewFrame->setImgContent(tempImgSrc);
	m_previewFrame->setPos(m_previewRect.getX(),m_previewRect.getY());
	m_previewFrame->setSize(m_previewRect.getWidth(),m_previewRect.getHeight());
	
	vcui->sendEvent(EVT_ID_CUI_IMGCLIP_CLOSE_REQUEST);
}

VfxBool VappImgEdtClipCuiPage::onKeyInput(VfxKeyEvent & event)
{
    if (VFX_KEY_CODE_CSK != event.keyCode)
    {
        return VfxPage::onKeyInput(event);
    }
    if (!m_bottomBar->isValid())
    {
        return VfxPage::onKeyInput(event);
    }
    if (STATE_READY != m_state)
    {
        return VFX_FALSE;
    }

    switch (event.type)
    {
    case VFX_KEY_EVENT_TYPE_DOWN:
        m_bottomBar->setBtnHilit(VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_OK, VFX_TRUE);
        break;

    case VFX_KEY_EVENT_TYPE_UP:
        m_bottomBar->setBtnHilit(VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_OK, VFX_FALSE);
        onBottomBtnClicked((VfxObject*)m_bottomBar, VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_OK);
        break;

    default:
        break;
    }
    return VfxPage::onKeyInput(event);
}


void VappImgEdtClipCuiPage::prepareMem()
{
    m_appId = getApp()->getGroupId();
    m_pDecodeMem = applib_asm_alloc_nc_r(m_appId, GDI_LCD_HEIGHT*GDI_LCD_HEIGHT*2);
    m_pPreviewLayerMem = applib_asm_alloc_nc_r(m_appId, GDI_LCD_WIDTH*GDI_LCD_HEIGHT*2);
    VFX_ASSERT((NULL != m_pPreviewLayerMem) && (NULL != m_pDecodeMem));
}

void VappImgEdtClipCuiPage::unprepareMem()
{
    VFX_ASSERT((NULL != m_pPreviewLayerMem) && (NULL != m_pDecodeMem));
    applib_asm_free_r(m_appId, m_pPreviewLayerMem);
    applib_asm_free_r(m_appId, m_pDecodeMem);
    m_pDecodeMem = NULL;
    m_pPreviewLayerMem = NULL;
}

gdi_handle VappImgEdtClipCuiPage::prepareLayer(const VfxRect& layerRect,
                                               const VfxU8* mem_p, 
                                               const VfxU8* path)
{
    gdi_handle gdi_hdl;
    //VFX_ASSERT((NULL != mem_p) && (NULL != path));
    gdi_layer_create_using_outside_memory(
                        0,
                        0,
                        layerRect.getWidth(),
                        layerRect.getHeight(),
                        &gdi_hdl,
                        (U8*)mem_p,
                        layerRect.getWidth() * layerRect.getHeight() * 2);

    VFX_ASSERT(NULL != gdi_hdl);

    gdi_layer_push_and_set_active((gdi_handle) gdi_hdl);
    gdi_layer_set_source_key(FALSE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear_background(GDI_COLOR_BLACK);    
    gdi_layer_pop_and_restore_active();
    
    return gdi_hdl;
}

void VappImgEdtClipCuiPage::unprepareLayer(gdi_handle *hdl_p)
{
    if (NULL != *hdl_p)
    {
        gdi_layer_free(*hdl_p);
        *hdl_p = NULL;
    }
}

void VappImgEdtClipCuiPage::showFrame(VfxFrame *preview, 
                                      const VfxRect &rect,
                                      const VfxU8 *mem_p)
{
    //prepare Image buffer
    VfxImageBuffer imgBuf;
    imgBuf.ptr = (VfxU8*)mem_p;
    imgBuf.pitchBytes = rect.getWidth() * 2;
    imgBuf.width = rect.getWidth();
    imgBuf.height = rect.getHeight();
    imgBuf.colorFormat = VRT_COLOR_TYPE_RGB565;

    preview->setImgContent(VfxImageSrc(imgBuf));
    preview->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
}


void VappImgEdtClipCuiPage::setWaitIconShown(VfxBool is_show)
{
    if (is_show)
    {
        VFX_ASSERT(NULL == m_waitIcon);
        VFX_OBJ_CREATE(m_waitIcon, VcpActivityIndicator, this);
        m_waitIcon->setPos(VfxPoint(getSize().width/2, getSize().height/2));
        m_waitIcon->setAnchor(0.5, 0.5);
        m_waitIcon->setAlignParent(VFX_FRAME_ALIGNER_MODE_MID,
                                   VFX_FRAME_ALIGNER_MODE_MID,
                                   VFX_FRAME_ALIGNER_MODE_MID,
                                   VFX_FRAME_ALIGNER_MODE_MID);    
        m_waitIcon->setHiddenWhenStopped(VFX_TRUE);
        m_waitIcon->setAutoAnimate(VFX_TRUE);
        m_waitIcon->start();
    }
    else
    {
        if ((NULL != m_waitIcon) && (m_waitIcon->isValid()))
        {
            m_waitIcon->stop();
            VFX_OBJ_CLOSE(m_waitIcon);
            m_waitIcon = NULL;
        }        
    }
}

gdi_handle VappImgEdtClipCuiPage::createGdiJob(gdi_handle layer, const VfxRect &rect, const VfxU8* path)
{
    VFX_ASSERT(((STATE_INITED == m_state) || (STATE_READY == m_state)) && (NULL != layer));
    gdi_handle job_hdl;
    job_hdl = gdi_imgdec_nb_draw_resized_file(
        layer,
        rect.getX(),
        rect.getY(),
        rect.getWidth(),
        rect.getHeight(),
        (U8*)path,
        &VappImgEdtClipCuiPage::gdiJobCallback);

    return job_hdl;
}

void VappImgEdtClipCuiPage::cancelGdiJob(gdi_handle *hdl_p)
{
    // note: a valid m_job could be GDI_NULL_HANDLE!
    switch (m_state)
    {
    case STATE_DRAWING:
    case STATE_SAVING:
        {
            GDI_RESULT res = gdi_imgdec_nb_stop(*hdl_p);
            *hdl_p = GDI_NULL_HANDLE;
        }
        break;
    default:
        break;
    }
    return;    
}

void VappImgEdtClipCuiPage::gdiJobCallback(gdi_result result, gdi_handle handle)
{
    VFX_ASSERT(NULL != VappImgEdtClipCuiPage::m_pageInst);
    VappImgEdtClipCuiPage* page = (VappImgEdtClipCuiPage*)VappImgEdtClipCuiPage::m_pageInst;
    page->onGdiJobCallback(result,handle);
}

void VappImgEdtClipCuiPage::onGdiJobCallback(gdi_result result, gdi_handle handle)
{
    VFX_ASSERT(handle == m_jobHdl);
        
    switch(m_state)
    {
    case STATE_DRAWING:
        if (GDI_SUCCEED == result)
        {
            gdi_handle gdi_hdl;
            gdi_layer_create_using_outside_memory(
                0,
                0,
                getBounds().getWidth() - 1,
                getBounds().getHeight() - 1,
                &gdi_hdl,
                (U8*)m_pPreviewLayerMem,
                getBounds().getWidth() * getBounds().getHeight() * 2);
            
            gdi_layer_push_and_set_active((gdi_handle)gdi_hdl);
            //gd_replace_src_key_16(
            gdi_act_replace_src_key(
                (U8*)m_pPreviewLayerMem,
                getBounds().getWidth(),
                0,
                0,
                0,
                0,
                getBounds().getWidth() - 1,
                getBounds().getHeight() - 1,
                GDI_COLOR_TRANSPARENT,
                getBounds().getWidth(),
                getBounds().getHeight());
            gdi_layer_pop_and_restore_active();
            
            m_previewFrame->invalidate();

            if (gdi_hdl != GDI_LAYER_EMPTY_HANDLE)
            {
                gdi_layer_free(gdi_hdl);
                gdi_hdl = GDI_LAYER_EMPTY_HANDLE;
            }
            onCuiStateChange(STATE_READY);
        }
        else
        {
            m_lastError = translateGDIResult(result);
            onCuiStateChange(STATE_ERROR);
        }
        break;

    case STATE_SAVING:
        if (GDI_SUCCEED == result)
        {
            VappImgClipCui *vcui = VFX_OBJ_DYNAMIC_CAST(getApp(), VappImgClipCui);
            if(vcui->isSavePbmFile())
			{
				VfxWString path = vcui->getPbmFilePath();
				//VfxSize size = VfxSize(0,0);
				//vcui->getSavedSize(size);
				
				result = gdi_image_device_bmp_encode_file(
					(WCHAR *)path.getBuf(), 
					(U8 *)m_pDecodeMem,
					GDI_COLOR_FORMAT_16,
					m_saveClipRect.size.width,
					m_saveClipRect.size.height);
				
				if(GDI_SUCCEED != result)
				{
					
					m_lastError = translateGDIResult(result);
					onCuiStateChange(STATE_ERROR);
					break;
				}
			}
			
            result = gdi_image_encode_layer_to_jpeg(
                                        m_renderHdl, 
                                        (S8*)vcui->getDestFilePath().getBuf());
            if(GDI_SUCCEED != result)
			{
				
				m_lastError = translateGDIResult(result);
				onCuiStateChange(STATE_ERROR);
				break;
			}

			VfxWString path = vcui->getDestFilePath();
			VfxImageSrc tempImgSrc = VfxImageSrc(path);
			
			VfxRect tempClipRect;
			m_clipWd->getClipRect(&tempClipRect);
			
			m_previewFrame->setPos(tempClipRect.getX(),tempClipRect.getY());
			m_previewFrame->setSize(tempClipRect.getWidth(),tempClipRect.getHeight());
			m_previewFrame->setImgContent(tempImgSrc);
			m_previewFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
			
	        onCuiStateChange(STATE_DONE);
	        break;
		}
    default:
        VFX_ASSERT(0);
        break;
    }  
}


VfxS32 VappImgEdtClipCuiPage::saveImage()
{
    VappImgClipCui *vcui = VFX_OBJ_DYNAMIC_CAST(getApp(), VappImgClipCui);
    VfxU8* path = (VfxU8*)vcui->getSrcFilePath().getBuf();
    
    mmi_ret ret = vcui->sendEvent(EVT_ID_CUI_IMGCLIP_SAVE_REQUEST);
    if (MMI_RET_OK != ret)
    {
        VAPP_IMGEDT_WARN_TRACE(ret);
        return ret;
    }
    
    m_renderHdl = prepareLayer(m_saveClipRect,
                               (VfxU8*)m_pDecodeMem,
                               (VfxU8*)vcui->getSrcFilePath().getBuf());
    //VFX_ASSERT(NULL != m_renderHdl);

    m_jobHdl = createGdiJob(m_renderHdl, m_saveRect, (VfxU8*)vcui->getSrcFilePath().getBuf());
    VFX_ASSERT(NULL != m_jobHdl);
    onCuiStateChange(STATE_SAVING);

    return 0;
}

void VappImgEdtClipCuiPage::onCuiStateChange(VfxS32 new_state)
{
    VFX_ASSERT(m_state != new_state);
    //VAPP_IMGEDT_INFO_TRACE(m_state);
    //VAPP_IMGEDT_INFO_TRACE(new_state);
    
    VfxS32 pre_state = m_state;
    m_state = new_state;

    switch(m_state)
    {
    case STATE_INITED:
        {
            m_bottomBar->setDisabled(VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_OK, VFX_TRUE);
            setWaitIconShown(VFX_FALSE);
            m_clipWd->setHidden(VFX_TRUE);
            m_previewFrame->setHidden(VFX_TRUE);
        }
        break;
        
    case STATE_DRAWING:
        {
            VFX_ASSERT(STATE_INITED == pre_state);
            m_bottomBar->setDisabled(VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_OK, VFX_TRUE);
            setWaitIconShown(VFX_TRUE);
            m_clipWd->setHidden(VFX_TRUE);
            m_previewFrame->setHidden(VFX_TRUE);
        }
        break;

    case STATE_READY:
        {
            m_bottomBar->setDisabled(VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_OK, VFX_FALSE);
            setWaitIconShown(VFX_FALSE);
            m_clipWd->setHidden(VFX_FALSE);
            m_clipWd->setFreeze(VFX_FALSE);
            m_previewFrame->setHidden(VFX_FALSE);
        }
        break;
        
    case STATE_SAVING:
        {
            VFX_ASSERT(STATE_READY == pre_state);
            m_bottomBar->setDisabled(VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_OK, VFX_TRUE);
            setWaitIconShown(VFX_TRUE);
            m_clipWd->setHidden(VFX_FALSE);
            m_clipWd->setFreeze(VFX_TRUE);
        }
        break;

    case STATE_DONE:
        {
            VFX_ASSERT(STATE_SAVING == pre_state);
            VappImgClipCui *vcui = VFX_OBJ_DYNAMIC_CAST(getApp(), VappImgClipCui);
            setWaitIconShown(VFX_FALSE);
            mmi_ret ret = vcui->sendEvent(EVT_ID_CUI_IMGCLIP_SAVE_NEW);
            if (MMI_RET_OK == ret)
            {
                ret = vcui->sendEvent(EVT_ID_CUI_IMGCLIP_CLOSE_REQUEST);
            }
        }
        break;

    case STATE_ERROR:
        setWaitIconShown(VFX_FALSE);
        errorHandle(pre_state);
        break;

    case STATE_IDLE:
    default:
        break;
    }
}

//this function only for voluntary stop such as interrupt & press back key
void VappImgEdtClipCuiPage::cancelAll()
{
    switch (m_state)
    {
    case STATE_DRAWING:
        cancelGdiJob(&m_jobHdl);
        onCuiStateChange(STATE_INITED);
        break;
    case STATE_SAVING:
        cancelGdiJob(&m_jobHdl);
        onCuiStateChange(STATE_READY);
        break;
    default:
        break;
    }
}

void VappImgEdtClipCuiPage::errorHandle(VfxS32 pre_state)
{
    switch (pre_state)
    {
    case STATE_INITED:
    case STATE_DRAWING:
    case STATE_READY:
        {
            VfxResId strId = cui_vapp_imgclip_get_error_string(0, m_lastError);
            onErrorPopup(strId);
        }
        break;

    case STATE_SAVING:
        {
            VappImgClipCui *vcui = VFX_OBJ_DYNAMIC_CAST(getApp(), VappImgClipCui);
            mmi_ret ret = vcui->sendEvent(EVT_ID_CUI_IMGCLIP_SAVE_NEW, (cui_imgclip_result)m_lastError);
            if (MMI_RET_OK == ret)
            {
                VfxResId strId = cui_vapp_imgclip_get_error_string(0, m_lastError);
                onErrorPopup(strId); 
            }
        }
        break;

    default:
        VFX_ASSERT(0);
    }
    return;
}

VfxS32 VappImgEdtClipCuiPage::updateImgRect()
{
    VappImgClipCui *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VappImgClipCui);
    
    //init image rect
    m_imgRect.origin = VfxPoint(0, 0);
    gdi_result res = gdi_imgdec_get_dimension_file(
                            (U8*)cui->getSrcFilePath().getBuf(), 
                            &m_imgRect.size.width, 
                            &m_imgRect.size.height);

    if (GDI_SUCCEED == res)
    {
        //init preview rect
        gdi_util_fit_box(GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT, 
                         getBounds().getWidth(), 
                         getBounds().getHeight(), 
                         m_imgRect.getWidth(), 
                         m_imgRect.getHeight(), 
                        &m_previewRect.origin.x,
                        &m_previewRect.origin.y, 
                        &m_previewRect.size.width, 
                        &m_previewRect.size.height);
    }
    else
    {
        m_lastError = CUI_IMGEDT_E_UNSUPPORTED_FORMAT;
    }

    return m_lastError;
}

void VappImgEdtClipCuiPage::updateImgClipRect()
{
    VfxFloat factor;
    m_clipWd->getClipRect(&m_previewClipRect);
    factor = (VfxFloat)m_imgRect.getWidth()/(VfxFloat)m_previewRect.getWidth();
    m_imgClipRect.origin.x = (m_previewClipRect.getX() - m_previewRect.getX()) * factor;
    m_imgClipRect.origin.y = (m_previewClipRect.getY() - m_previewRect.getY()) * factor;
    m_imgClipRect.size.width = m_previewClipRect.getWidth() * factor;
    m_imgClipRect.size.height = m_previewClipRect.getHeight() * factor;
}

void VappImgEdtClipCuiPage::updateClipRect()
{
    VfxFloat factor;
    
    VappImgClipCui *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappImgClipCui);
    
    m_saveClipRect.size = m_imgClipRect.size;
    app->getSavedSize(m_saveClipRect.size);
    factor = (VfxFloat)m_saveClipRect.getWidth()/(VfxFloat)m_imgClipRect.getWidth();
    m_saveClipRect.origin.x = m_imgClipRect.getX() * factor;
    m_saveClipRect.origin.y = m_imgClipRect.getY() * factor;

    m_saveRect.origin = VfxPoint(0,0);
    m_saveRect.size.width = m_imgRect.getWidth() * factor;
    m_saveRect.size.height = m_imgRect.getHeight() * factor;
    m_saveRect.origin.x -= m_saveClipRect.origin.x;
    m_saveRect.origin.y -= m_saveClipRect.origin.y;
}


void VappImgEdtClipCuiPage::onBottomBtnClicked(VfxObject *obj, VfxId id)
{    
    switch(id)
    {
    case VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_OK:
        {
            //must update imgclip info before update save cliprect
            updateImgClipRect();
            VFX_ASSERT(!m_imgClipRect.isEmpty());
            updateClipRect();
            VFX_ASSERT((!m_saveRect.isEmpty()) && (!m_saveClipRect.isEmpty()));
            saveImage();
        }
        break;

    case VcpImgEdtBottomBar::BOTTOM_BTN_TYPE_CANCEL:
        {
            VappImgClipCui *vcui = VFX_OBJ_DYNAMIC_CAST(getApp(), VappImgClipCui);

			if(NULL == m_waitIcon)
			{
				setWaitIconShown(VFX_TRUE);
			}
			
		    VfxWString path = vcui->getSrcFilePath();
			VfxImageSrc tempImgSrc = VfxImageSrc(path);
			
			m_previewFrame->setImgContent(tempImgSrc);
			m_previewFrame->setPos(m_previewRect.getX(),m_previewRect.getY());
			m_previewFrame->setSize(m_previewRect.getWidth(),m_previewRect.getHeight());

            vcui->sendEvent(EVT_ID_CUI_IMGCLIP_CLOSE_REQUEST);
        }
        break;

    default:
        break;
    }
}

void VappImgEdtClipCuiPage::onErrorPopupCallback(VfxObject* sender,VfxId btn_id)
{
    if(btn_id==VCP_CONFIRM_POPUP_BUTTON_OK)
    {
        VappImgClipCui *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappImgClipCui);
        mmi_ret ret = app->sendEvent(EVT_ID_CUI_IMGCLIP_CLOSE_REQUEST);
    }
}

void VappImgEdtClipCuiPage::onErrorPopup(VfxResId strId, VfxBool needCallback)
{
    VcpConfirmPopup *popup;
    VFX_OBJ_CREATE(popup, VcpConfirmPopup, this);
    if (needCallback)
    {
        popup->m_signalButtonClicked.connect(this, &VappImgEdtClipCuiPage::onErrorPopupCallback);
    }
    VcpImgEdtPopup::popupError(popup, strId);
}

VfxS32 VappImgEdtClipCuiPage::translateGDIResult(gdi_result result)
{
    switch(result)
    {
    case GDI_SUCCEED:
        return CUI_IMGEDT_OK;
    case GDI_IMAGE_ENCODER_ERR_DISK_FULL:
    case GDI_IMAGE_ENCODER_ERR_WRITE_PROTECTION:
    case GDI_IMAGE_ENCODER_ERR_NO_DISK:
    case GDI_IMAGE_ENCODER_ERR_ROOT_DIR_FULL:
        return result;
    default:
        return CUI_IMGEDT_E_UNSUPPORTED_FORMAT;
    }
}


/***************************************************************************** 
 * Class VappImgClipScr
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappImgClipScr", VappImgClipScr, VappImgEdtBaseScr);

void VappImgClipScr::on1stReady()
{
    VappImgEdtBaseScr::on1stReady();

    VFX_OBJ_CREATE(m_clipPage, VappImgEdtClipCuiPage, this);
    pushPage(0, m_clipPage);
}

/***************************************************************************** 
 * Class VappImgClipCui
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappImgClipCui", VappImgClipCui, VfxCui);

VappImgClipCui::VappImgClipCui():
m_ratioW(CUI_IMGCLIP_DEFAULT_RATIO_WIDTH),
m_ratioH(CUI_IMGCLIP_DEFAULT_RATIO_WIDTH),
m_destWidth(CUI_IMGCLIP_DEFAULT_DEST_WIDTH),
m_destHeight(CUI_IMGCLIP_DEFAULT_DEST_HEIGHT),
m_limitWidth(CUI_IMGCLIP_DEFAULT_DEST_WIDTH),
m_limitHeight(CUI_IMGCLIP_DEFAULT_DEST_HEIGHT),
m_isFixed(VFX_TRUE),
m_isLimited(VFX_FALSE),
m_layout(CUI_IMGCLIP_ROTATE_0),
m_userData(0),
m_saveAPbmFlie(VFX_FALSE)
{
}


void VappImgClipCui::onDeinit()
{
#ifdef __MMI_USB_SUPPORT__
    registerCBEvent(EVT_ID_USB_ENTER_MS_MODE, VFX_FALSE);
#endif /* __MMI_USB_SUPPORT__ */
    registerCBEvent(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, VFX_FALSE);
    registerCBEvent(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, VFX_FALSE);
    registerCBEvent(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT, VFX_FALSE);
    registerCBEvent(EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT, VFX_FALSE);

    VfxCui::onDeinit();
}

void VappImgClipCui::onRun(void *arg, VfxU32 argSize)
{
    VfxCui::onRun(arg, argSize);

    cui_imgclip_launch_struct *info = (cui_imgclip_launch_struct *)arg;
    m_srcFilePath = VFX_WSTR_MEM((VfxWChar*)info->scr_file_path);
    m_userData = info->user_data;

    //init file type
    VfxU16 gdiFileType = gdi_image_get_type_from_file((CHAR*)info->scr_file_path);
    VAPP_IMGEDT_INFO_TRACE(gdiFileType);
    switch(gdiFileType)
    {
    case GDI_IMAGE_TYPE_GIF_FILE_OFFSET:
    case GDI_IMAGE_TYPE_GIF:
    case GDI_IMAGE_TYPE_GIF_FILE:
    case GDI_IMAGE_TYPE_BMP:
    case GDI_IMAGE_TYPE_BMP_SEQUENCE:
    case GDI_IMAGE_TYPE_BMP_FILE:
    case GDI_IMAGE_TYPE_WBMP_FILE:
    case GDI_IMAGE_TYPE_WBMP:
#ifndef GDI_USING_HW_PNG
    case GDI_IMAGE_TYPE_PNG:
    case GDI_IMAGE_TYPE_PNG_FILE:
#endif
        m_isLimited = VFX_TRUE;
        break;
    default:
        break;
    }

#ifdef __MMI_USB_SUPPORT__
    registerCBEvent(EVT_ID_USB_ENTER_MS_MODE, VFX_TRUE);
#endif /* __MMI_USB_SUPPORT__ */
    registerCBEvent(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, VFX_TRUE);
    registerCBEvent(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, VFX_TRUE);
    registerCBEvent(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT, VFX_TRUE);
    registerCBEvent(EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT, VFX_TRUE);

    VFX_OBJ_CREATE(m_namingHelper, VcpImgEdtNamingHelper, this);

    VFX_OBJ_CREATE(m_clipScr, VappImgClipScr, this);
    m_clipScr->setScrRotate(getRotation());
    m_clipScr->show();
}

mmi_ret VappImgClipCui::onProc(mmi_event_struct *evt)
{
    switch(evt->evt_id)
    {
#ifdef __MMI_USB_SUPPORT__
    case EVT_ID_USB_ENTER_MS_MODE:
        {
            VfxMainScr *screen = VFX_OBJ_DYNAMIC_CAST(getTopScreen(), VfxMainScr);
            VappImgEdtClipCuiPage *page = VFX_OBJ_DYNAMIC_CAST(screen->getPage(), VappImgEdtClipCuiPage);
            if ((page == VappImgEdtClipCuiPage::m_pageInst) && 
                (NULL != VappImgEdtClipCuiPage::m_pageInst))
            {
                page->cancelAll();
            }
        }
        sendEvent(EVT_ID_CUI_IMGCLIP_CLOSE_REQUEST);
        break;
#endif /* __MMI_USB_SUPPORT__ */

    case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
    case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT:
    case EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT:
    {
        srv_fmgr_notification_dev_plug_event_struct *event = (srv_fmgr_notification_dev_plug_event_struct *)evt;
        for (VfxU32 i = 0; i < event->count; i++)
        {
            if (event->drv_letters[i] == m_srcFilePath[0])
            {
                VfxMainScr *screen = VFX_OBJ_DYNAMIC_CAST(getTopScreen(), VfxMainScr);
                VappImgEdtClipCuiPage *page = VFX_OBJ_DYNAMIC_CAST(screen->getPage(), VappImgEdtClipCuiPage);
                if ((page == VappImgEdtClipCuiPage::m_pageInst) && 
                    (NULL != VappImgEdtClipCuiPage::m_pageInst))
                {
                    page->cancelAll();
                }
                sendEvent(EVT_ID_CUI_IMGCLIP_CLOSE_REQUEST);
                break;
            }
        }
    }
        break;
    default:
        break;
    }
    return VfxCui::onProc(evt);
}


mmi_ret VappImgClipCui::sendEvent(cui_imgclip_evet_enum event, cui_imgclip_result result)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_IMGCLIP_SEND_EVENT_BEGIN, event, result);
    cui_imgclip_event_struct evt;
    MMI_FRM_INIT_GROUP_EVENT(&evt, event, getGroupId());
    evt.result = result;
    evt.user_data = (void *)m_userData;
    mmi_ret ret = sendToCaller((mmi_group_event_struct*)&evt);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_IMGEDT_IMGCLIP_SEND_EVENT_END, ret);
    return ret;
}

void VappImgClipCui::setParentData(S32 parent_data)
{
    this->m_parentData = parent_data;
}

VfxU32 VappImgClipCui::getParentData()
{
    return m_parentData;
}

void VappImgClipCui::setLayoutStyle(cui_imgclip_layout_enum layout)
{
    m_layout = layout;
}

VfxScrRotateTypeEnum VappImgClipCui::getRotation()
{
    VfxScrRotateTypeEnum rot;
    switch (m_layout)
    {
    case CUI_IMGCLIP_ROTATE_0:
        rot = VFX_SCR_ROTATE_TYPE_0;
        break;

    case CUI_IMGCLIP_ROTATE_270:
        rot = VFX_SCR_ROTATE_TYPE_270;
        break;

    case CUI_IMGCLIP_ROTATE_90:        
        rot = VFX_SCR_ROTATE_TYPE_90;
        break;

    default:
        rot = VFX_SCR_ROTATE_TYPE_0;
        break;
    }
    return rot;
}


void VappImgClipCui::setIsRatioFixed(VfxBool is_fixed)
{
    this->m_isFixed = is_fixed;
}

VfxBool VappImgClipCui::getIsRatioFixed()
{
    return m_isFixed;
}


void VappImgClipCui::setRatio(VfxS32 ratio_w, VfxS32 ratio_h)
{
    //VFX_ASSERT(ratio_w > 0 && ratio_h > 0);
    this->m_ratioW = ratio_w;
    this->m_ratioH = ratio_h;
}

void VappImgClipCui::getRatio(VfxS32 *ratio_w, VfxS32 *ratio_h)
{
    *ratio_w = m_ratioW;
    *ratio_h = m_ratioH;
}

void VappImgClipCui::setDestDimension(VfxS32 width, VfxS32 height)
{
    //VFX_ASSERT(width >= 0 && height >= 0);
    this->m_destWidth  = width;
    this->m_destHeight = height;
}

void VappImgClipCui::setlimitDimension(VfxS32 width, VfxS32 height)
{
    //VFX_ASSERT(width >= 0 && height >= 0);
    this->m_limitWidth  = width;
    this->m_limitHeight = height;
}

void VappImgClipCui::getDestDimension(VfxS32 *width, VfxS32 *height)
{
    *width  = this->m_destWidth;
    *height = this->m_destHeight;
}

void VappImgClipCui::getSrcDimension(VfxS32 *width, VfxS32 *height)
{
    
}

void VappImgClipCui::setDestPath(VfxU8 *path)
{
    VFX_ASSERT(path != NULL);
    m_destFilePath = VFX_WSTR_MEM((VfxWChar*)path);
}

void VappImgClipCui::getDestPath(VfxU8 *path)
{
    VfxWString str = getDestFilePath();
    vfx_sys_wcscpy((VfxWChar*)path, (VfxWChar*)str.getBuf());
}

VfxWString VappImgClipCui::getDestFilePath()
{
    if (m_destFilePath.isNull())
    {
        return  m_namingHelper->autoGenNewPath(m_srcFilePath);
    }
    else
    {
        return  m_destFilePath;
    }
    
}

VfxWString VappImgClipCui::getSrcFilePath()
{
    return m_srcFilePath;
}

void VappImgClipCui::getUserData(VfxU32 *user_data)
{
    *user_data = m_userData;
}

void VappImgClipCui::getSavedSize(VfxSize &size)
{
    if (CUI_IMGCLIP_DEFAULT_DEST_WIDTH != m_destWidth &&
        CUI_IMGCLIP_DEFAULT_DEST_WIDTH != m_destHeight)
    {
        VFX_ASSERT((m_destHeight > 0) && (m_destWidth  > 0) && (!size.isEmpty()));
        if (m_isLimited)
        {
            if (size.width  >= m_destWidth &&
                size.height >= m_destHeight)
            {
                size.width  = m_destWidth;
                size.height = m_destHeight;
            }
        }
        else
        {
            size.width = m_destWidth;
            size.height = m_destHeight;
        }
    }
    else if (CUI_IMGCLIP_DEFAULT_DEST_WIDTH != m_limitWidth &&
             CUI_IMGCLIP_DEFAULT_DEST_WIDTH != m_limitHeight)
    {
        VFX_ASSERT((m_limitHeight > 0) && (m_limitWidth > 0) && (!size.isEmpty()));
        if (size.width > m_limitWidth)
        {
            size.width = m_limitWidth;
        }
        if (size.height > m_limitHeight)
        {
            size.height = m_limitHeight;
        }
    }
    //VAPP_IMGEDT_INFO_TRACE(size.width);
    //VAPP_IMGEDT_INFO_TRACE(size.height);
}

void VappImgClipCui::savePbmFile(VfxBool saveABpmfile)
{
	m_saveAPbmFlie = saveABpmfile;
}

VfxBool VappImgClipCui::isSavePbmFile()
{
	return m_saveAPbmFlie;
}

VfxWString VappImgClipCui::getPbmFilePath()
{
	VfxWString path = getDestFilePath();
	VfxU32 len = path.getLength();
	VfxWChar *temppath = (VfxWChar *)path.getBuf();
	
	temppath[len-3] = 'p';
	temppath[len-2] = 'b';
	temppath[len-1] = 'm';
	
	return path;
}

#endif /* __MMI_COSMOS_IMAGECLIPPER__ */


