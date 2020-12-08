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

/*******************************************************************************
 * Filename:
 * ---------
 *  vrt_3d_interface.h
 *
 * Project:
 * --------
 *  Venus Rendering Task
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
#ifndef __VRT_INTERFACE__
#define __VRT_INTERFACE__

#include "vrt_datatype.h"
#include "vrt_3d_enum.h"

class IVrtSyncObject
{
public:
    virtual void syncData() const = 0;
    virtual void destroy() const = 0;
};


class IVrtCustomRender
{
public:
    virtual vrt_custom_render_type getType() const = 0;
};


class IVrtOwnerDraw : public IVrtCustomRender
{
public:
    virtual vrt_custom_render_type getType() const;
    virtual void initResource() = 0;
    virtual void deinitResource() = 0;
    virtual vrt_bool isUsingGLAPI() const = 0;
    virtual vrt_bool isUsingDepthStencil() const = 0;
    virtual vrt_owner_draw_funcptr_type getCallback() const = 0;
	virtual vrt_bool isDirty() const = 0;
	virtual vrt_render_owner_draw_dirty_type_enum executeAnimation(vrt_msec_type currFrameTime) = 0;
	virtual void getDirtyRect(vrt_rect_struct &rect) const = 0;
	virtual void resetDirtyRect() = 0;
	virtual void commitCallback() = 0;
    virtual vrt_bool needHWRenderingBuffer() = 0;
};


class IVrtFrameFilter : public IVrtCustomRender
{
public:
    virtual vrt_custom_render_type getType() const;
	virtual vrt_image_filter_buffer_mode getFilterBufferMode() const = 0;
	virtual vrt_color_type_enum getFilterColorFormat() const = 0;
	virtual vrt_image_filter_kernel_callback_funcptr_type getCallback() const = 0;
};


class IVrtProceduralMesh
{
public:
    /* vertex buffer */
    virtual vrt_u32 getVertexCount() const = 0;
    virtual vrt_u32 getVertexArrayCount() const = 0;
    virtual vrt_u32 getComponentCount(vrt_u32 i) const = 0;
    virtual vrt_type_id_enum getComponentDataType(vrt_u32 i) const = 0;
    virtual const vrt_char *getAttributeName(vrt_u32 i) const = 0;
    virtual vrt_bool isNormalized(vrt_u32 i) const = 0;
    virtual const vrt_float *getScaleVector(vrt_u32 i) const = 0;
    virtual const vrt_float *getBiasVector(vrt_u32 i) const = 0;

    /* index buffer */
    virtual vrt_u32 getIndexBufferCount() const = 0;
    virtual VrtPrimitiveType getPrimitiveType(vrt_u32 i) const = 0;
    virtual vrt_u32 getIndexCount(vrt_u32 i) const = 0;
    virtual vrt_type_id_enum getIndexDataType(vrt_u32 i) const = 0;

    /* init functions */
    virtual void initVertexArrays(void **va_buffers) const = 0;
    virtual void initIndexBuffers(void **ib_buffers) const = 0;

};

#endif




