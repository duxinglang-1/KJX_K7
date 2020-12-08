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
 *  vfx_owner_draw_control.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Description
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VFX_OWNER_DRAW_CONTROL_H__
#define __VFX_OWNER_DRAW_CONTROL_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_control.h"
#include "vfx_owner_draw.h"

/***************************************************************************** 
 * Class VfxOwnerDrawControl
 *****************************************************************************/

class VfxOwnerDrawControl : public VfxControl
{
    VFX_DECLARE_CLASS(VfxOwnerDrawControl);

// Constructor / Destructor
public:

    // Default constructor
    VfxOwnerDrawControl();
	
    // Destructor
    virtual ~VfxOwnerDrawControl(){}

// Method
public:

    void setFrameBuffer(VfxImageBuffer &buffer);

	VfxImageBuffer getFrameBuffer() const;

	void invalidateFrameBuffer(VfxRect rect = VFX_RECT_ZERO);

	void setFrameAttributes(VfxU32 width, VfxU32 height, VfxColorTypeEnum cf);

	void beginUpdateRenderProperties();

	void endUpdateRenderProperties();

    VfxU8 *beginHWRendering();

    VfxU8 *endHWRendering();

    void setNeedHWRenderingBuffer(VfxBool isNeeded);

    VfxBool getNeedHWRenderingBuffer();

// Overridable
protected:

    virtual void onDrawFrameBuffer(VfxImageBuffer &buffer, const VfxPoint &frameOrigin, const VfxRect &dirtyRect) {}

	virtual vrt_render_owner_draw_dirty_type_enum onExecuteAnimation(VfxMsec currFrameTime, VfxRect &dirtyRect) {return VRT_RENDER_OWNER_DRAW_DIRTY_TYPE_NONE;}

    virtual void onCommit(){};
    
// Override
public:

    virtual void setBounds(const VfxRect &value);

// Override
protected:

    virtual void onInit();

// Implementation
private:

    static void onOwnerDraw(VfxImageBuffer &dstBuffer, const VfxPoint &frameOrigin, const VfxRect &dirtyRect, void *userData, VfxU32 userDataSize);

	static vrt_render_owner_draw_dirty_type_enum onOwnerDrawAnimation(vrt_msec_type currFrameTime, VfxRect &dirtyRect, void *userData, VfxU32 userDataSize);

    static void onCommitCallback(void *userData, VfxU32 userDataSize);

// Implementation
private:

    VfxOwnerDrawWrapper *m_ownerDraw;
	
    VfxImageBuffer m_curDstBuffer;
	
    VfxBool m_switched;
	
};

#endif /* __VFX_OWNER_DRAW_CONTROL_H__ */

