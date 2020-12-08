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
 *  vtst_rt_transform.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for Transfrom
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_config.h"

#ifdef __AFX_RT_TEST__

#include "vtst_rt_main.h"
#include "vfx_frame.h"
#include "vfx_string.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_transform.h"
#include "vfx_app_cat_scr.h"


/***************************************************************************** 
 * Auto Animation Test Implementation
 *****************************************************************************/

class VtstRtTransform : public VtstRtScr
{
// Variable
public:
    VfxFrame         *m_frame1;
    VfxFrame         *m_frame2;

// Constructor / Destructor
public:
    VtstRtTransform() : 
        m_frame1(NULL),
        m_frame2(NULL)
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        setTitle(VFX_WSTR("Test Test"));
        
        VFX_OBJ_CREATE(m_frame1, VfxFrame, this);
        m_frame1->setImgContent(VfxImageSrc(VFX_WSTR("E:\\AF\\IF03.jpg")));
        m_frame1->setPos(120, 160);
        m_frame1->setAnchor(0.5,0.5);
        m_frame1->setBounds(VfxRect(0, 0, 120, 120));
        m_frame1->setIsCached(VFX_TRUE);
        m_frame1->setIsOpaque(VFX_TRUE);
        m_frame1->setBgColor(VFX_COLOR_GREEN);

        VFX_OBJ_CREATE(m_frame2, VfxFrame, this);
        m_frame2->setImgContent(VfxImageSrc(VFX_WSTR("E:\\AF\\IF03.jpg")));
        m_frame2->setPos(120, 160);
        m_frame2->setAnchor(0.5,0.5);
        m_frame2->setBounds(VfxRect(0, 0, 120, 120));
        m_frame2->setIsCached(VFX_TRUE);
        m_frame2->setIsOpaque(VFX_TRUE);
        m_frame2->setOpacity(0.5);
        m_frame2->setBgColor(VFX_COLOR_GREY);
    }

    virtual int start()
    {      
        return 8;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        VfxTransform tempTransform;
        if (idx == 0)
        {
            confirm(VFX_WSTR("Affine scale OK?"));
            tempTransform.type = VFX_TRANSFORM_TYPE_AFFINE;
            tempTransform.data.affine.sx = 2;
            tempTransform.data.affine.sy = 0.5f;
            m_frame1->setTransform(tempTransform);
            return -1;
        }
        else if (idx == 1)
        {
            confirm(VFX_WSTR("Affine translate OK?"));
            tempTransform.type = VFX_TRANSFORM_TYPE_AFFINE;
            tempTransform.data.affine.tx = 40;
            tempTransform.data.affine.ty = 40;
            m_frame1->setTransform(tempTransform);
            return -1;
        }
        else if (idx == 2)
        {
            confirm(VFX_WSTR("Affine rotate OK?"));
            tempTransform.data.affine.rz = VFX_DEG_TO_RAD(30);
            m_frame1->setTransform(tempTransform);
            return -1;
        }
        else if (idx == 3)
        {
            confirm(VFX_WSTR("Affine combination OK?"));
            tempTransform.type = VFX_TRANSFORM_TYPE_AFFINE;
            tempTransform.data.affine.sx = 2;
            tempTransform.data.affine.sy = 0.5f;
            tempTransform.data.affine.tx = 40;
            tempTransform.data.affine.ty = 40;
            tempTransform.data.affine.rz = VFX_DEG_TO_RAD(30);
            m_frame1->setTransform(tempTransform);
            return -1;
        }
        else if (idx == 4)
        {
            confirm(VFX_WSTR("Matrix3x3 scale OK?"));
            tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;
            tempTransform.setIdentity();
            tempTransform.data.matrix3x3.m[0] = 2;
            tempTransform.data.matrix3x3.m[4] = 0.5;
            m_frame1->setTransform(tempTransform);
            return -1;
        }
        else if (idx == 5)
        {
            confirm(VFX_WSTR("Matrix3x3 translate OK?"));
            tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;
            tempTransform.setIdentity();
            tempTransform.data.matrix3x3.m[6] = 40;
            tempTransform.data.matrix3x3.m[7] = 40;
            m_frame1->setTransform(tempTransform);
            return -1;
        }
        else if (idx == 6)
        {
            confirm(VFX_WSTR("Matrix3x3 rotate OK?"));
            tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;
            tempTransform.setIdentity();
            tempTransform.data.matrix3x3.m[0] = vfxCos(VFX_DEG_TO_RAD(30));
            tempTransform.data.matrix3x3.m[3] = vfxSin(VFX_DEG_TO_RAD(30));
            tempTransform.data.matrix3x3.m[1] = -1 * tempTransform.data.matrix3x3.m[1];     // looks like a bug
            tempTransform.data.matrix3x3.m[4] = tempTransform.data.matrix3x3.m[0];
            m_frame1->setTransform(tempTransform);
            return -1;
        }
        else if (idx == 7)
        {
            confirm(VFX_WSTR("Matrix3x3 All OK?"));
            tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;
            tempTransform.setIdentity();
            tempTransform.data.matrix3x3.m[0] = 0.09585f;
            tempTransform.data.matrix3x3.m[3] = -0.03711f;
            tempTransform.data.matrix3x3.m[6] = 35;
            tempTransform.data.matrix3x3.m[1] = -0.26667f;
            tempTransform.data.matrix3x3.m[4] = 0.76176f;
            tempTransform.data.matrix3x3.m[7] = 32;
            tempTransform.data.matrix3x3.m[2] = -0.00510f;
            tempTransform.data.matrix3x3.m[5] = 0.00185f;
            tempTransform.data.matrix3x3.m[8] = 1;
            m_frame1->setTransform(tempTransform);
            return -1;
        }
        return VTST_RT_END_TESTCASE;
    }
};


VtstTestResultEnum vtst_rt_transform(VfxU32 param)
{
    VTST_START_SCRN(VtstRtTransform);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__

