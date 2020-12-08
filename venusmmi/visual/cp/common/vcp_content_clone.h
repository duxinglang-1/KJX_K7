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
 *  vcp_cloner.h
 *
 * Project:
 * --------
 *  Venus UI Component
 *
 * Description:
 * ------------
 *  Venus Component
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VCP_CLONER_H__
#define __VCP_CLONER_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"

#if !defined(__MMI_VUI_COSMOS_CP_SLIM__)

#include "vfx_control.h"
#include "vfx_frame.h"
#include "vfx_basic_type.h"
#include "vfx_datatype.h"
#include "vrt_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_frame_filter.h"
#include "vfx_image_src.h"
#include "vfx_weak_ptr.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

// Enum
enum VcpContentCloneFilterTypeEnum
{
    VCP_CONTENT_CLONE_FILTER_TYPE_COPY,
    VCP_CONTENT_CLONE_FILTER_TYPE_REFLECTION,
    VCP_CONTENT_CLONE_FILTER_TYPE_GRADIENT_REFLECTION,
    VCP_CONTENT_CLONE_FILTER_TYPE_END
};

/*****************************************************************************
 * Class VcpContentClone
 *  VcpContentClone can clone a content of target frame. it can also do some 
 *  image processing to achieve reflection on Venus.
 *
 * EXAMPLE
 * <code>
 *  VcpContentClone *m_reflection;
 *  VFX_OBJ_CREATE(m_reflection, VcpContentClone, this);
 *  m_reflection->setPos(20, 180);
 *  m_reflection->setTargetFrame(m_frame1);
 *  m_reflection->setFilterType(VCP_CONTENT_CLONE_FILTER_TYPE_GRADIENT_REFLECTION);
 *  m_reflection->setOutputAlpha(VFX_TRUE);
 *  m_reflection->setTargetRect(VfxRect(0,0,100,149));     
 * </code>
 *****************************************************************************/
class VcpContentClone : public VfxControl
{
// Constructor / Destructor
public:
    // <group DOM_ContentClone_VcpContentClone_Constructor/Destructor>
    VcpContentClone(); 

// Method
public:
    // <group DOM_ContentClone_VcpContentClone_Method>
    // set targetFrame you want clone.
    void setTargetFrame(VfxFrame *target)
    {
        m_targetFrame = target;
        checkUpdate();
    }
    // <group DOM_ContentClone_VcpContentClone_Method>
    // set filter to do differenet image processing.
    void setFilterType(VcpContentCloneFilterTypeEnum type)
    {
        m_filterType = type;
        checkUpdate();
    }
    // <group DOM_ContentClone_VcpContentClone_Method>
    // set the rectangle of target you want to clone. the final result will be the 
    // intersection of this rectangle and the rectangle of target frame.
    // because there are some limit on VRT, it can't set twice.
    void setTargetRect(const VfxRect &rect)
    {
        if (m_targetRect != VfxRect(0,0,0,0))
        {
            // can't setTargetRect twice
            VFX_ASSERT(0);
        }
        m_targetRect = rect;
        checkUpdate();
    }
    // <group DOM_ContentClone_VcpContentClone_Method>
    // set if you want the VcpCotentClone with Aphla. notice that if two VcpContentClones
    // with Aphla, it will blending together. It won't be like the real reflection shadow.
    void setOutputAlpha(VfxBool value)
    {
        m_outputAlpha = value;
        checkUpdate();
    }
    // <group DOM_ContentClone_VcpContentClone_Method>
    // get Target frame you want clone.
    VfxFrame* getTargetFrame()
    {
        return m_targetFrame.get();
    }
    // <group DOM_ContentClone_VcpContentClone_Method>
    // get filter to do differenet image processing.
    VcpContentCloneFilterTypeEnum getFilterType()
    {
        return m_filterType;
    }
    // <group DOM_ContentClone_VcpContentClone_Method>
    // get the rectangle of target you want to clone. 
    const VfxRect &getTargetRect() const
    {
        return m_targetRect;
    }
    // <group DOM_ContentClone_VcpContentClone_Method>
    // get if you want the VcpCotentClone with Aphla.
    VfxBool getOutputAlpha()
    {
        return m_outputAlpha;
    }
    
// Override
protected:
    // <group DOM_ContentClone_VcpContentClone_Override>
    virtual void onInit();
    // <group DOM_ContentClone_VcpContentClone_Override>
    virtual void onDeinit();
    // <group DOM_ContentClone_VcpContentClone_Override>
    virtual void onUpdate();
// Implementation
private:
    // <group DOM_ContentClone_VcpContentClone_Implementation>
    static vrt_render_dirty_type_enum framePropertyEffectCallback(
        vrt_frame_visual_property_struct *target_frame,
        const vrt_frame_visual_property_struct *watch_frame,
        void *user_data,
        vrt_u32 user_data_size)
    {
        VFX_UNUSED(target_frame);
        VFX_UNUSED(watch_frame);
        VFX_UNUSED(user_data);
        VFX_UNUSED(user_data_size);
        return VRT_RENDER_DIRTY_TYPE_DIRTY;
    }

// Sub structure and class
private:
    class cloneBaseFilter : public VfxFrameFilter
    {
    // Vairable
    public:
        VcpContentClone     *m_destFrame;

        VfxRect        m_rect;
        VfxBool        m_outputAlpha;
    // Constructor / Destructor
    public:
        cloneBaseFilter(){};

    // Override
    protected:
        // <group DOM_ContentClone_VcpContentClone_Override>
        virtual BufferModeEnum onGetBufferMode() const
        {
            return BUFFER_MODE_IN_PLACE;
        }
        // <group DOM_ContentClone_VcpContentClone_Override>
        virtual VfxBool onProcess(VfxU8 *outBuf, VfxImageBuffer &inBuf, VfxFloat level);
        // <group DOM_ContentClone_VcpContentClone_Override>
        virtual void *lockCloneBuffer();
        virtual void unlockCloneBuffer();

    // Overriable
    protected:
        // <group DOM_ContentClone_VcpContentClone_Override>
        virtual void processRGB565toARGB8888(VfxImageBuffer &inBuf) = 0;
        // <group DOM_ContentClone_VcpContentClone_Override>
        virtual void processRGB565toPARGB8888(VfxImageBuffer &inBuf) = 0;
        // <group DOM_ContentClone_VcpContentClone_Override>
        virtual void processRGB565toRGB565(VfxImageBuffer &inBuf)= 0;
        // <group DOM_ContentClone_VcpContentClone_Override>
        virtual void processARGB8888toARGB8888(VfxImageBuffer &inBuf) = 0;
        // <group DOM_ContentClone_VcpContentClone_Override>
        virtual void processPARGB8888toPARGB8888(VfxImageBuffer &inBuf)= 0;
        // <group DOM_ContentClone_VcpContentClone_Override>
        virtual void processRGB565toPARGB6666(VfxImageBuffer &inBuf)= 0;
        // <group DOM_ContentClone_VcpContentClone_Override>
        virtual void processPARGB6666toPARGB6666(VfxImageBuffer &inBuf)= 0;
        
    };
    
    class copyFilter : public cloneBaseFilter
    {
    public:
        copyFilter(){};

    // Override
    protected:
        //virtual VfxBool onProcess(VfxU8 *outBuf, VfxImageBuffer &inBuf, VfxFloat level);
        // <group DOM_ContentClone_VcpContentClone_Override>
        virtual void processRGB565toARGB8888(VfxImageBuffer &inBuf);
        // <group DOM_ContentClone_VcpContentClone_Override>
        virtual void processRGB565toPARGB8888(VfxImageBuffer &inBuf);
        // <group DOM_ContentClone_VcpContentClone_Override>
        virtual void processRGB565toRGB565(VfxImageBuffer &inBuf);
        // <group DOM_ContentClone_VcpContentClone_Override>
        virtual void processARGB8888toARGB8888(VfxImageBuffer &inBuf);
        // <group DOM_ContentClone_VcpContentClone_Override>
        virtual void processPARGB8888toPARGB8888(VfxImageBuffer &inBuf); 
        // <group DOM_ContentClone_VcpContentClone_Override>
        virtual void processRGB565toPARGB6666(VfxImageBuffer &inBuf);
        // <group DOM_ContentClone_VcpContentClone_Override>
        virtual void processPARGB6666toPARGB6666(VfxImageBuffer &inBuf);
    private:
        void copyFrameCommon(VfxImageBuffer &inBuf);
        void copyFrame6666(VfxImageBuffer &inBuf);
    };

    class reflectionFilter : public cloneBaseFilter
    {
    public:
        reflectionFilter(){};

    // Override
    protected:
        //virtual VfxBool onProcess(VfxU8 *outBuf, VfxImageBuffer &inBuf, VfxFloat level);
        // <group DOM_ContentClone_VcpContentClone_Override>
        virtual void processRGB565toARGB8888(VfxImageBuffer &inBuf);
        // <group DOM_ContentClone_VcpContentClone_Override>
        virtual void processRGB565toPARGB8888(VfxImageBuffer &inBuf);
        // <group DOM_ContentClone_VcpContentClone_Override>
        virtual void processRGB565toRGB565(VfxImageBuffer &inBuf);
        // <group DOM_ContentClone_VcpContentClone_Override>
        virtual void processARGB8888toARGB8888(VfxImageBuffer &inBuf);
        // <group DOM_ContentClone_VcpContentClone_Override>
        virtual void processPARGB8888toPARGB8888(VfxImageBuffer &inBuf);
        // <group DOM_ContentClone_VcpContentClone_Override>
        virtual void processRGB565toPARGB6666(VfxImageBuffer &inBuf);
        // <group DOM_ContentClone_VcpContentClone_Override>
        virtual void processPARGB6666toPARGB6666(VfxImageBuffer &inBuf);
    };

    class gradientReflectionFilter : public cloneBaseFilter
    {
    public:
        gradientReflectionFilter(){};

    // Override
    protected:
        //virtual VfxBool onProcess(VfxU8 *outBuf, VfxImageBuffer &inBuf, VfxFloat level);
        // <group DOM_ContentClone_VcpContentClone_Override>
        virtual void processRGB565toARGB8888(VfxImageBuffer &inBuf);
        // <group DOM_ContentClone_VcpContentClone_Override>
        virtual void processRGB565toPARGB8888(VfxImageBuffer &inBuf);
        // <group DOM_ContentClone_VcpContentClone_Override>
        virtual void processRGB565toRGB565(VfxImageBuffer &inBuf);
        // <group DOM_ContentClone_VcpContentClone_Override>
        virtual void processARGB8888toARGB8888(VfxImageBuffer &inBuf);
        // <group DOM_ContentClone_VcpContentClone_Override>
        virtual void processPARGB8888toPARGB8888(VfxImageBuffer &inBuf);
        // <group DOM_ContentClone_VcpContentClone_Override>
        virtual void processRGB565toPARGB6666(VfxImageBuffer &inBuf);
        // <group DOM_ContentClone_VcpContentClone_Override>
        virtual void processPARGB6666toPARGB6666(VfxImageBuffer &inBuf);
    };
// Variable
private:
    // <group DOM_ContentClone_VcpContentClone_Variable>
    VfxFrameWeakPtr m_targetFrame;
    // <group DOM_ContentClone_VcpContentClone_Variable>
    VfxFrame *m_notifyFrame;
    // <group DOM_ContentClone_VcpContentClone_Variable>
    VcpContentCloneFilterTypeEnum m_filterType;
    // <group DOM_ContentClone_VcpContentClone_Variable>
    cloneBaseFilter *m_filter;
    // <group DOM_ContentClone_VcpContentClone_Variable>
    VfxRect m_targetRect;
    // <group DOM_ContentClone_VcpContentClone_Variable>
    VfxBool m_outputAlpha;
};

#endif /* !defined(__MMI_VUI_COSMOS_CP_SLIM__) */

#endif /* __VCP_CLONER_H__ */
