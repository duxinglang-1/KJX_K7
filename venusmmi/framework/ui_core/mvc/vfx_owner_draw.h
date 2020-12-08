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
 *  vfx_owner_draw.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Venus UI Owner Draw Class 
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
#ifndef __VFX_OWNER_DRAW_H__
#define __VFX_OWNER_DRAW_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxObject
#include "vfx_object.h"

#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_image_src.h"
#include "vfx_basic_type.h"
#include "vfx_cpp_base.h"
#include "vrt_datatype.h"
#include "vrt_interface.h"
#include "gdi_include.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VFX_OWNER_DRAW_ENTER_CRITICAL_SECTION  GDI_LOCK
#define VFX_OWNER_DRAW_EXIT_CRITICAL_SECTION   GDI_UNLOCK


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
 
// Predefine Classes
class VfxFrame;


/***************************************************************************** 
 * Class VfxOwnerDraw
 *****************************************************************************/

/*
 * VfxOwnerDraw is the base class of a owner draw.
 */
class VfxOwnerDraw : public VfxObject, public IVrtOwnerDraw
{
// Define
public:

// Constructor / Destructor
public:
    // Default constructor
    VfxOwnerDraw();
    virtual ~VfxOwnerDraw();

// Method
public:

    // Add image source to owner draw process.
    void setResourceFromResId(VfxId key, VfxResId resId);

    void setResourceFromPath(VfxId key, const VfxWString &path);

	void setResourceFromRawData(VfxId key, VfxU8* buf_p, VfxU32 imageSize, VfxFileRawDataFormatEnum imageFormat = VFX_FILE_FORMAT_TYPE_AUTO);

#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
    void setResource(VfxId key, const VfxImageSrc &imgSrc);
#endif

    void setTargetFrame(VfxFrame *ptr);

    // Remove image source from owner draw process.
    void removeResource(VfxId key);
    
	void setDirtyRect(VfxRect &rect);
  
    void setNeedHWRenderingBuffer(VfxBool isNeeded) {m_isNeedHWRenderingBuffer = isNeeded ? VRT_TRUE : VRT_FALSE;}

    VfxBool getNeedHWRenderingBuffer() {return m_isNeedHWRenderingBuffer ? VFX_TRUE : VFX_FALSE;}
  
// Overridable
protected:

    virtual void onDeinit();

    // Override the method to initialize resouce.
    virtual void onInitResource();

    // Override the method to deinitialize resource.
    virtual void onDeinitResource();

    // Override the method to avoid SW overhead if using GL API.
    // RETURNS: Return VFX_TRUE if the buffer memory can be NULL.
    //  Otherwise return VFX_FALSE.
    virtual vrt_bool isUsingGLAPI() const { return VFX_FALSE; }

    // Override the method to solve depth/stencil conflict issue.
    // RETURNS: Return VFX_TRUE if this ownerdraw writes depth/stencil buffer.
    //  Otherwise return VFX_FALSE.
    virtual vrt_bool isUsingDepthStencil() const { return VFX_FALSE; }

    // Override the method to provide owner draw callback.
    // RETURNS: Return owner draw static callback function.
    virtual vrt_owner_draw_funcptr_type getCallback() const { return VfxOwnerDraw::onCallback; }

    // Override the method to process the image.
    // RETURNS: Return VFX_TRUE if the filter processed. 
    //  Otherwise return VFX_FALSE.
    virtual void onDraw(VfxImageBuffer &dstBuffer, VfxRect &dstRect, VfxRect &srcRect) = 0;

	virtual vrt_render_owner_draw_dirty_type_enum onExecuteAnimation(VfxMsec currFrameTime, VfxRect &dirtyRect) {return VRT_RENDER_OWNER_DRAW_DIRTY_TYPE_NONE;}

    virtual void onCommit() {}
	
// Implementation
protected:
    // Get image buffer from resource. This function can only be called in onDraw.
    VfxBool getResource(VfxId, VfxImageBuffer &imgBuf) const;

    virtual vrt_bool needHWRenderingBuffer() {return m_isNeedHWRenderingBufferVrt;}

protected:

	VfxRect m_dirtyRect;
	
private:
    friend class VfxFrame;

    VfxBool m_bInit;

    VfxFrame* m_targetFrame;

    VfxImageList m_ImageSrcList;

    vrt_bool m_isNeedHWRenderingBuffer;

    vrt_bool m_isNeedHWRenderingBufferVrt;

private:
        
    // Internal method for init owner draw resource in VRT task
    virtual void initResource();

    // Internal method for deinit owner draw resource in VRT task
    virtual void deinitResource();
    
	virtual vrt_render_owner_draw_dirty_type_enum executeAnimation(vrt_msec_type currFrameTime);

	virtual void resetDirtyRect();

	virtual void getDirtyRect(vrt_rect_struct &rect) const;

	virtual vrt_bool isDirty() const;

	virtual void commitCallback();
    
    static void onCallback(
        const vrt_image_buffer_struct *image_buffer,
        const vrt_rect_struct *dst_rect,
        const vrt_rect_struct *src_rect,
        void *param);

    friend class VpiOwnerDrawProxy;
};



/***************************************************************************** 
 * Class VfxOwnerDrawWrapper
 *****************************************************************************/

/*
 * VfxOwnerDrawWrapper is a wrapper of VfxOwnerDraw, it add some frame buffer
 * management mechanism
 */

typedef vrt_render_owner_draw_dirty_type_enum (*VfxOwnerDrawAnimationCallbackFuncptrType)(vrt_msec_type currFrameTime, VfxRect &dirtyRect, void *userData, VfxU32 userDataSize);

typedef void (*VfxOwnerDrawCallbackFuncptrType)(VfxImageBuffer &dstBuffer, const VfxPoint &frameOrigin, const VfxRect &dirtyRect, void *userData, VfxU32 userDataSize);

typedef void (*VfxOwnerDrawCommitCallbackFuncptrType)(void *userData, VfxU32 userDataSize);
	
class VfxOwnerDrawWrapper : public VfxOwnerDraw
{
// Define
public:

// Constructor / Destructor
public:

	VfxOwnerDrawWrapper();
	
	virtual ~VfxOwnerDrawWrapper();

// Method
public:

	void setFrameBuffer(VfxImageBuffer &buffer);

	const VfxImageBuffer &getFrameBuffer() const;

	void resetFrameBuffer();

	void setOwnerDrawAnimationCallback(VfxOwnerDrawAnimationCallbackFuncptrType callback, void *userData, VfxU32 userDataSize);

	void setOwnerDrawCallback(VfxOwnerDrawCallbackFuncptrType callback, void *userData, VfxU32 userDataSize);

	void setCommitCallback(VfxOwnerDrawCommitCallbackFuncptrType callback, void *userData, VfxU32 userDataSize);

	void invalidate(VfxRect &rect);

	void setFrameAttributes(VfxU32 width, VfxU32 height, VfxColorTypeEnum cf);

// Override
protected:

    virtual void onDraw(VfxImageBuffer &dstBuffer, VfxRect &dstRect, VfxRect &srcRect);

	virtual vrt_render_owner_draw_dirty_type_enum onExecuteAnimation(VfxMsec currFrameTime, VfxRect &dirtyRect);

	virtual void onCommit();

    virtual vrt_bool needHWRenderingBuffer();

// Implementation
private:

    VfxU32 getBitsPerPixel(VfxColorTypeEnum cf);

	VfxColorTypeEnum mapGdiCFToVfxCF(gdi_color_format cf);

	gdi_color_format mapVfxCFToGdiCF(VfxColorTypeEnum colorFormat);

    void copyFrameBuffer(VfxImageBuffer &dstBuffer, VfxRect &dstRect, VfxImageBuffer &srcBuffer, VfxRect &srcRect);

    void flattenFrameBuffer(VfxImageBuffer &dstBuffer, VfxRect &dstRect, VfxImageBuffer &srcBuffer, VfxRect &srcRect);

#if defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__)
    VfxBool isCachedBuffer(VfxImageBuffer &buf);
    void cleanInvalidateBufferDcacheByRect(VfxImageBuffer &buf, VfxRect &rect, VfxBool isInv);
	void enableBufferDcache(VfxImageBuffer &buf, VfxBool enable);
	void *physToVirt(void *address);
	void *virtToPhys(void *address);
#endif

// Implementation
private:

   VfxImageBuffer m_frameBuffer;
   
   VfxOwnerDrawCallbackFuncptrType m_callback;
   
   void *m_userData;

   VfxU32 m_userDataSize;

   VfxOwnerDrawAnimationCallbackFuncptrType m_animationCallback;

   void *m_animationUserData;

   VfxU32 m_animationUserDataSize;
   
   VfxOwnerDrawCommitCallbackFuncptrType m_commitCallback;

   void *m_commitUserData;

   VfxU32 m_commitUserDataSize;

   VfxU32 m_frameWidth;

   VfxU32 m_frameHeight;

   VfxColorTypeEnum m_frameColorFormat;
};

#endif /* __VFX_OWNER_DRAW_H__ */

