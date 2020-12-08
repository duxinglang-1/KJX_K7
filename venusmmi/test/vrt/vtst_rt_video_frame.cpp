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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vtst_rt_video_frame.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for video frame
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vtst_rt_main.h"
#include "vfx_uc_include.h"
#include "vfx_mc_include.h"
#ifdef __cplusplus
extern "C"
{
#endif

#include "gdi_include.h"
#include "MMIDataType.h"
#include "mdi_datatype.h"
#include "mdi_include.h"
#include "mdi_camera.h"
/* mcu cache header */
#include "cache_sw.h"
#include "GlobalResDef.h"
#ifdef __cplusplus

extern gdi_handle vrt_get_blt_layer(void);
}
#endif

#ifdef __AFX_RT_TEST__


/***************************************************************************** 
 * VideoFrame Create Test Implementation
 *****************************************************************************/

class VtstRtVideoFrameCreate : public VtstRtScr
{
// Variable
public:
    VfxVideoFrame  *m_videoFrame;
    VfxU8          *m_buffer;
    VfxFrame       *m_frame1;
    VfxFrame       *m_frame2;

// Constructor / Destructor
public:
    VtstRtVideoFrameCreate() : 
        m_videoFrame(NULL),
        m_buffer(NULL),
        m_frame1(NULL),
        m_frame2(NULL)
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        setTitle(VFX_WSTR("Video Frame Test"));
                
        VFX_OBJ_CREATE(m_frame1, VfxFrame, this);
        VFX_OBJ_CREATE(m_videoFrame, VfxVideoFrame, this);
        VFX_OBJ_CREATE(m_frame2, VfxFrame, this);

        m_videoFrame->setPos(100, 120);
        m_videoFrame->setSize(160, 120);
        m_videoFrame->setMultimediaType(VfxVideoFrame::MULTIMEDIA_CAMERA);

        m_frame1->setPos(60, 80);
        m_frame1->setSize(80, 80);
        m_frame1->setBgColor(VFX_COLOR_WHITE);
        
        m_frame2->setPos(220, 200);
        m_frame2->setSize(80, 80);
        m_frame2->setBgColor(VFX_COLOR_YELLOW);
            
        m_videoFrame->setBuffer(FW_TEST1);
        m_videoFrame->prepare();

        VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        renderer->suspendUntilCommit();
            
        mdi_camera_setting_struct camera_setting_data = {0};
        mdi_camera_preview_struct camera_preview_data = {0};

        mdi_camera_power_on(APP1_BASE);

        mdi_camera_load_default_setting(&camera_setting_data);

        /* start preview */
        camera_setting_data.preview_width = m_videoFrame->getSize().width;
        camera_setting_data.preview_height = m_videoFrame->getSize().height;

        /* capture parameters */
        camera_setting_data.image_qty = MDI_CAMERA_JPG_QTY_HIGH;
        camera_setting_data.image_width = m_videoFrame->getSize().width;
        camera_setting_data.image_height = m_videoFrame->getSize().height;

        camera_setting_data.lcm = MDI_CAMERA_PREVIEW_LCM_MAINLCD;
        #if defined(__MDI_CAMERA_FD_SUPPORT__)
        camera_setting_data.fd_callback = NULL;
        #endif

        #if 0    
/* under construction !*/
/* under construction !*/
        #endif    
//        camera_setting_data.osd_rotate = FALSE; 
        camera_setting_data.xenon_flash_status_callback = NULL;

        camera_preview_data.preview_layer_handle = m_videoFrame->getLayerHandle();
        camera_preview_data.blt_layer_flag = m_videoFrame->getDisplayLayerFlag();
        camera_preview_data.preview_layer_flag = m_videoFrame->getHwLayerFlag();
        camera_preview_data.is_lcd_update = TRUE;
        camera_preview_data.src_key_color = GDI_COLOR_TRANSPARENT;
        camera_preview_data.is_tvout = TRUE;

        gdi_layer_blt(vrt_get_blt_layer(), camera_preview_data.preview_layer_handle, 0, 0, 0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

        mdi_camera_preview_start(
            &camera_preview_data,
            &camera_setting_data,
            NULL); 

    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        VFX_UNUSED(idx);

        m_frame2->setAutoAnimate(VFX_TRUE);
        m_frame2->setPos(20, 200);
        m_frame2->setBgColor(VFX_COLOR_SILVER);
        
        confirm(VFX_WSTR("PEN UP THREE TIMES. Result is correct?"));
        
        return -1;
    }
    
    virtual VfxS32 start() {return 1;}

    virtual void onDeinit()
    {
        mdi_camera_preview_stop();
        mdi_camera_power_off();

        m_videoFrame->unPrepare();

//        VFX_SYS_FREE_MEM(m_buffer);

        VtstRtScr::onDeinit();
    }
    
};


VtstTestResultEnum vtst_rt_video_frame_create(VfxU32 param)
{
    VTST_START_SCRN(VtstRtVideoFrameCreate);
    return VTST_TR_OK;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class VtstVFAppScr : public VtstRtAppScr
{
    VFX_DECLARE_CLASS(VtstVFAppScr);

public:
    VfxVideoFrame  *m_videoFrame;
    VfxU8          *m_buffer;
    VfxFrame       *m_frame1;
    VfxFrame       *m_frame2;
    VfxTimer       *m_timer;
    VfxTimer       *m_timerBuffer;
    VfxU8          *m_buffercontent;
    VfxImageFrame  *m_imageFrame;
// Constructor / Destructor
public:
    VtstVFAppScr() : 
        m_videoFrame(NULL),
        m_buffer(NULL),
        m_frame1(NULL),
        m_frame2(NULL),
        m_buffercontent(NULL),
        m_imageFrame(NULL)
    {
    }
        
// Override
protected:
    virtual void onInit()
    {
        VtstRtAppScr::onInit();

        setBgColor(VFX_COLOR_BLUE);
        
        setTitle(VFX_WSTR("Video Frame Test"));
                
        VFX_OBJ_CREATE(m_frame1, VfxFrame, this);
        VFX_OBJ_CREATE(m_videoFrame, VfxVideoFrame, this);
        VFX_OBJ_CREATE(m_frame2, VfxFrame, this);
        VFX_OBJ_CREATE(m_timer, VfxTimer, this);
        VFX_OBJ_CREATE(m_timerBuffer, VfxTimer, this);
        VFX_OBJ_CREATE(m_imageFrame, VfxImageFrame, this);
        
        m_videoFrame->setPos(100, 120);
        m_videoFrame->setSize(160, 120);
        m_videoFrame->setMultimediaType(VfxVideoFrame::MULTIMEDIA_CAMERA);

        m_frame1->setPos(60, 80);
        m_frame1->setSize(80, 80);
        m_frame1->setBgColor(VFX_COLOR_WHITE);
        
        m_frame2->setPos(220, 200);
        m_frame2->setSize(80, 80);
        m_frame2->setBgColor(VFX_COLOR_YELLOW);

        m_videoFrame->setBuffer(APP1_BASE);
        m_videoFrame->prepare();

        m_timer->setStartDelay(100);
        m_timer->setDuration(100);
        m_timer->m_signalTick.connect(this, &VtstVFAppScr::onTimerTick);

        m_timerBuffer->setStartDelay(500);
        m_timerBuffer->setDuration(100);
        m_timerBuffer->m_signalTick.connect(this, &VtstVFAppScr::onBufferTimerTick);
        
        m_imageFrame->setPos(100, 350);
        m_imageFrame->setSize(160, 120);
        m_imageFrame->setBgColor(VFX_COLOR_SILVER);

        m_buffercontent = (VfxU8*)applib_asm_alloc_nc_r(APP1_BASE, 160*120*2);
                
        m_timer->start();

    }
    virtual void onDeinit()
    {
        mdi_camera_preview_stop();
        mdi_camera_power_off();

        m_videoFrame->unPrepare();
        applib_asm_free_r(APP1_BASE, m_buffercontent);

        VfxAppScr::onDeinit();
    }

    void onTimerTick(VfxTimer *source)
    {
        if (!isShown())
            return;

        m_timer->stop();
    #if 0
/* under construction !*/
/* under construction !*/
    #endif        
        mdi_camera_setting_struct camera_setting_data = {0};
        mdi_camera_preview_struct camera_preview_data = {0};

        mdi_camera_power_on(APP1_BASE);
        
        mdi_camera_load_default_setting(&camera_setting_data);

        /* start preview */
        camera_setting_data.preview_width = m_videoFrame->getSize().width;
        camera_setting_data.preview_height = m_videoFrame->getSize().height;

        /* capture parameters */
        camera_setting_data.image_qty = MDI_CAMERA_JPG_QTY_HIGH;
        camera_setting_data.image_width = m_videoFrame->getSize().width;
        camera_setting_data.image_height = m_videoFrame->getSize().height;

        camera_setting_data.lcm = MDI_CAMERA_PREVIEW_LCM_MAINLCD;
//        camera_setting_data.preview_rotate = MDI_CAMERA_LCM_ROTATE_0;
//        camera_setting_data.lcm_rotate = MDI_CAMERA_PREVIEW_ROTATE_0;
        #if defined(__MDI_CAMERA_FD_SUPPORT__)
        camera_setting_data.fd_callback = NULL;
        #endif

        #if 0    
/* under construction !*/
/* under construction !*/
        #endif    

        camera_preview_data.preview_layer_handle = m_videoFrame->getLayerHandle();
        camera_preview_data.blt_layer_flag = m_videoFrame->getDisplayLayerFlag();
        camera_preview_data.preview_layer_flag = m_videoFrame->getHwLayerFlag();
        camera_preview_data.is_lcd_update = TRUE;
        camera_preview_data.src_key_color = GDI_COLOR_TRANSPARENT;
        camera_preview_data.is_tvout = TRUE;
        camera_setting_data.xenon_flash_status_callback = NULL;

//        gdi_layer_blt(vrt_get_blt_layer(), camera_preview_data.preview_layer_handle, 0, 0, 0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);

        mdi_camera_preview_start(
            &camera_preview_data,
            &camera_setting_data,
            NULL); 

        m_timerBuffer->start();
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    
    }

    void onBufferTimerTick(VfxTimer *source)
    {
        mdi_camera_get_hw_layer_buffer_content(m_videoFrame->getLayerHandle(), m_buffercontent, 160*120*2);

        VfxImageBuffer imageBuf;
        imageBuf.ptr = (VfxU8*)m_buffercontent;
        imageBuf.pitchBytes = m_videoFrame->getSize().width * 2;
        imageBuf.width = m_videoFrame->getSize().width;
        imageBuf.height = m_videoFrame->getSize().height;
        imageBuf.colorFormat = VRT_COLOR_TYPE_RGB565;

        m_imageFrame->setImgContent(VfxImageSrc(imageBuf));
        invalidate();
    }
    
    virtual VfxBool onKeyInput(
        VfxKeyEvent &event
    )
    {
        if(event.keyCode == VFX_KEY_CODE_RSK)
        {
            if(event.type == VFX_KEY_EVENT_TYPE_UP)
            {
                exit();
                return VFX_TRUE;
            }
        }

        return VfxAppScr::onKeyInput(event);
    }

};
VFX_IMPLEMENT_CLASS("VtstVFAppScr", VtstVFAppScr, VtstRtAppScr);


class VtstVFApp : public VtstRtApp
{
    VFX_DECLARE_CLASS(VtstVFApp);
        
protected:
    virtual void onInit()
    {
        VtstRtApp::onInit();
    }

    virtual int start()
    {
        return 0; // unknow phase count
    }
    
// Override
public:
    virtual void onRun(void* args, VfxU32 argSize)
    {
        VfxApp::onRun(args, argSize);

        VtstVFAppScr *scr;
        VFX_OBJ_CREATE(scr, VtstVFAppScr, this);
        scr->show();
    }

};
VFX_IMPLEMENT_CLASS("VtstVFApp", VtstVFApp, VtstRtApp);

VtstTestResultEnum vtst_rt_vf_scr(VfxU32 param)
{
    VfxAppLauncher::launchWithAsmSize( 
        APP1_BASE, 
        VFX_OBJ_CLASS_INFO(VtstVFApp),
        GRP_ID_ROOT, 204800,
        NULL, 0);
    return VTST_TR_OK;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif // __AFX_RT_TEST__

