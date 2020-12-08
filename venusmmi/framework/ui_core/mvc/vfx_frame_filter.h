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
 *  vfx_frame_filter.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Venus UI Frame Filter Class 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VFX_FRAME_FILTER_H__
#define __VFX_FRAME_FILTER_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxObject
#include "vfx_object.h"
// For VfxImageList
#include "vfx_image_src.h"

#include "vrt_datatype.h"
#include "vrt_interface.h"
#include "vfx_cpp_base.h"
#include "vfx_datatype.h"
#include "vfx_string.h"


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
 
// Predefine Classes
class VfxImageBuffer;
class VfxFrame;


/***************************************************************************** 
 * Class VfxFrameFilter
 *****************************************************************************/

/*
 * VfxFrameFilter is the base class of a frame filter.
 */
class VfxFrameFilter : public VfxObject, public IVrtFrameFilter
{
// Define
public:
    // Buffer mode
    enum BufferModeEnum
    {
        BUFFER_MODE_IN_PLACE                = VRT_IMAGE_FILTER_BUFFER_MODE_IN_PLACE,
        BUFFER_MODE_OUT_OF_PLACE            = VRT_IMAGE_FILTER_BUFFER_MODE_OUT_OF_PLACE,
        BUFFER_MODE_OUT_OF_PLACE_AND_POLLUTE_INPUT = VRT_IMAGE_FILTER_BUFFER_MODE_OUT_OF_PLACE_AND_POLLUTE_INPUT,
        BUFFER_MODE_OUT_OF_PLACE_AND_COPY   = VRT_IMAGE_FILTER_BUFFER_MODE_OUT_OF_PLACE_AND_COPY,
        BUFFER_MODE_OUT_OF_PLACE_AND_COPY_AND_POLLUTE_INPUT = VRT_IMAGE_FILTER_BUFFER_MODE_OUT_OF_PLACE_AND_COPY_AND_POLLUTE_INPUT,
        BUFFER_MODE_END_OF_ENUM
    };

// Constructor / Destructor
public:
    // Default constructor
    VfxFrameFilter();

// Method
public:
    // Return the buffer mode of the filter
    // RETURNS: The buffer mode of the filter
    // SEE ALSO: onGetBufferMode
    BufferModeEnum getBufferMode() const
    {
        return onGetBufferMode();
    }
    
    // Process the given image.
    // RETURNS: Return VFX_TRUE if the filter processed. 
    //  Otherwise return VFX_FALSE.
    // SEE ALSO: onProcess
    VfxBool process(VfxU8 *outBuf, VfxImageBuffer &inBuf, VfxFloat timing)
    {
        return onProcess(outBuf, inBuf, timing);
    }

    // Add image source to filtering process.
    void setResourceFromResId(VfxId key, VfxResId resId);

    void setResourceFromPath(VfxId key, const VfxWString &path);

	void setResourceFromRawData(VfxId key, VfxU8* buf_p, VfxU32 imageSize, VfxFileRawDataFormatEnum imageFormat = VFX_FILE_FORMAT_TYPE_AUTO);
#ifdef __MMI_VENUS_PLUG_IN_ENGINE__
    void setResource(VfxId key, const VfxImageSrc &imgSrc);
#endif

    void setTargetFrame(VfxFrame *ptr);

    // Remove image source from filtering process.
    void removeResource(VfxId key);

    // Set filter OUT_OF_PLACE color format
    void setColorFormat(VfxColorTypeEnum format)
    {
        m_colorFormat = format;
    }

    // Get filter OUT_OF_PLACE color format
    VfxColorTypeEnum getColorFormat() const
    {
        return m_colorFormat;
    }
    
// Overridable
protected:

    virtual void onDeinit();

    // Override the method to return buffer mode of the filter, 
    // must always return the same mode.
    // RETURNS : The buffer mode of the filter.
    virtual BufferModeEnum onGetBufferMode() const;

    // Override the method to process the image.
    // RETURNS: Return VFX_TRUE if the filter processed. 
    //  Otherwise return VFX_FALSE.
    virtual VfxBool onProcess(VfxU8 *outBuf, VfxImageBuffer &inBuf, VfxFloat timing);

// Implementation
protected:
    // Get image buffer from resource. This function can only be called in onProcess.
    VfxBool getResource(VfxId, VfxImageBuffer &imgBuf) const;

	virtual vrt_image_filter_buffer_mode getFilterBufferMode() const;
	
	virtual vrt_color_type_enum getFilterColorFormat() const;
	
	virtual vrt_image_filter_kernel_callback_funcptr_type getCallback() const;

private:
    friend class VfxFrame;

    VfxImageList m_ImageSrcList;

    VfxFrame* m_targetFrame;

    // filter can specify the color format for OUT_OF_PLACE only
    VfxColorTypeEnum m_colorFormat;
    
    static vrt_bool onCallback(
        const vrt_image_buffer_struct *image_buffer, 
        vrt_u8 *out_buf_p, 
        void *param, 
        vrt_float t);    
    friend class VpiFrameFilterProxy;
};


#endif /* __VFX_FRAME_FILTER_H__ */

