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
 *  vcp_async_image_frame.h
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  Async Image Frame
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCP_ASYNC_IMAGE_FRAME_H__
#define __VCP_ASYNC_IMAGE_FRAME_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_frame.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
extern "C"
{
#include "gdi_include.h"
}


typedef void * (*VcpAsyncImageFrameMemAlloc)(VfxU32 size, void *userData);

typedef void (*VcpAsyncImageFrameMemFree)(void *mem, void *userData);


/*****************************************************************************
 * Class VcpAsyncImageFrame
 *  VcpAsyncImage is a frame and its content can be set two image.
 *  One is preview image. it should be load quickly (usually a image resource)
 *  Another is the real image. it may decode for a long time.
 *  When real image is decoding. VcpAsyncImage will show the preview image.
 *  Then, when the real image decoded done, It will change to show real image
 *  automatically.
 * EXAMPLE
 * <code>
 *  VcpAsyncImageFrame *m_asyncImage;
 *  VFX_OBJ_CREATE_EX(m_asyncImage, VcpAsyncImageFrame, this, (m_filename, m_previewImageId, m_size));
 *  m_asyncImage->setPos(0,0);
 * </code>
 *****************************************************************************/
class VcpAsyncImageFrame : public VfxFrame
{
// Constructor / Destructor
public:
    // <group DOM_AsyncImageFrame_VcpAsyncImageFrame_Constructor/Destructor>
    VcpAsyncImageFrame(const VfxWString &imagePath, VfxS32 previewImageId, VfxSize size);
	VcpAsyncImageFrame(const VfxWChar * imagePath, VfxS32 previewImageId, VfxSize size);

    // <group DOM_AsyncImageFrame_VcpAsyncImageFrame_Constructor/Destructor>
    VcpAsyncImageFrame(
        const VfxWString &imagePath, 
        VfxS32 previewImageId, 
        VfxSize size, 
        VfxS32 bytePerPixel, 
        VcpAsyncImageFrameMemAlloc allocFunc, 
        VcpAsyncImageFrameMemFree freeFunc,
        void *userData,
        gdi_util_mode_enum gdiMode = GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT
        );
	VcpAsyncImageFrame(
        const VfxWChar *imagePath, 
        VfxS32 previewImageId, 
        VfxSize size, 
        VfxS32 bytePerPixel, 
        VcpAsyncImageFrameMemAlloc allocFunc, 
        VcpAsyncImageFrameMemFree freeFunc,
        void *userData,
        gdi_util_mode_enum gdiMode = GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT
        );

    // <group DOM_AsyncImageFrame_VcpAsyncImageFrame_Constructor/Destructor>
    VcpAsyncImageFrame(
        const VfxImageSrc &imageSrc,
        VfxS32 previewImageId, 
        VfxSize size, 
        VfxS32 bytePerPixel, 
        VcpAsyncImageFrameMemAlloc allocFunc, 
        VcpAsyncImageFrameMemFree freeFunc,
        void *userData,
        gdi_util_mode_enum gdiMode = GDI_UTIL_MODE_NO_RESIZE_OR_LONG_SIDE_FIT
        );
// Event
public:
    // <group DOM_AsyncImageFrame_VcpAsyncImageFrame_Event>
    // notify APP the decode result
    VfxSignal1 <GDI_RESULT> m_gdiResultCallback;

// Override
protected:
    // <group DOM_AsyncImageFrame_VcpAsyncImageFrame_Override>
    virtual void onInit();
    // <group DOM_AsyncImageFrame_VcpAsyncImageFrame_Override>
    virtual void onDeinit();

// Variable
private:
    // <group DOM_AsyncImageFrame_VcpAsyncImageFrame_Variable>
    VcpAsyncImageFrame * m_nextObject;
    // <group DOM_AsyncImageFrame_VcpAsyncImageFrame_Variable>
    const VfxWString m_imagePath;
    // <group DOM_AsyncImageFrame_VcpAsyncImageFrame_Variable>
    const VfxImageSrc m_imageSrc;
    // <group DOM_AsyncImageFrame_VcpAsyncImageFrame_Variable>
    const VfxS32 m_previewImageId;
    // <group DOM_AsyncImageFrame_VcpAsyncImageFrame_Variable>
    VfxImageBuffer m_imageBuffer;
    // <group DOM_AsyncImageFrame_VcpAsyncImageFrame_Variable>
    VfxSize m_size;
    // <group DOM_AsyncImageFrame_VcpAsyncImageFrame_Variable>
    VfxU8 * m_data;
    // <group DOM_AsyncImageFrame_VcpAsyncImageFrame_Variable>
    static VcpAsyncImageFrame * m_firstObject;
    // <group DOM_AsyncImageFrame_VcpAsyncImageFrame_Variable>
    gdi_handle m_handle;
    // <group DOM_AsyncImageFrame_VcpAsyncImageFrame_Variable>
    gdi_handle m_layer;
    // <group DOM_AsyncImageFrame_VcpAsyncImageFrame_Variable>
    mmi_id m_gid;
    // <group DOM_AsyncImageFrame_VcpAsyncImageFrame_Variable>
    VfxTimer * m_timer;
    // <group DOM_AsyncImageFrame_VcpAsyncImageFrame_Variable>
    VfxBool m_isAppMem;
    // <group DOM_AsyncImageFrame_VcpAsyncImageFrame_Variable>
    VfxS32 m_bytePerPixel;
    // <group DOM_AsyncImageFrame_VcpAsyncImageFrame_Variable>
    VcpAsyncImageFrameMemAlloc m_allocFunc;
    // <group DOM_AsyncImageFrame_VcpAsyncImageFrame_Variable>
    VcpAsyncImageFrameMemFree  m_freeFunc;
    // <group DOM_AsyncImageFrame_VcpAsyncImageFrame_Variable>
    void *m_userData;
    // <group DOM_AsyncImageFrame_VcpAsyncImageFrame_Variable>
    gdi_util_mode_enum m_gdiMode;

// Implementation
private:
    // <group DOM_AsyncImageFrame_VcpAsyncImageFrame_Implementation>
    void onHandleGdiCallback(GDI_RESULT result);
    // <group DOM_AsyncImageFrame_VcpAsyncImageFrame_Implementation>
    void loadImage();
    // <group DOM_AsyncImageFrame_VcpAsyncImageFrame_Implementation>
    void onTimer(VfxTimer *source);    
public :
    // <group DOM_AsyncImageFrame_VcpAsyncImageFrame_Implementation>
    static void onGdiCallback(GDI_RESULT result,gdi_handle handle);
};


#endif // __VCP_ASYNC_IMAGE_FRAME_H__

