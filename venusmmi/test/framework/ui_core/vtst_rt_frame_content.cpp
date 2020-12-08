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
 *  vtst_rt_frame_content.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for Frame Content
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
#include "vfx_datatype.h"
#include "vfx_frame.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_string.h"
#include "vfx_image_src.h"
#include "vfx_app_cat_scr.h"

extern "C"
{
#include "GlobalResDef.h"
}


/***************************************************************************** 
 * VtstRtFrameContent Implementation
 *****************************************************************************/

class VtstRtFrameContent : public VtstRtScr
{
    enum 
    {
        TEST_BUF_WIDTH  = 10,
        TEST_BUF_HEIGHT = 8
    };
    
// Variable
public:
    VfxFrame *m_frame[VFX_FRAME_CONTENT_PLACEMENT_TYPE_END_OF_ENUM];

// Constructor / Destructor
public:
    VtstRtFrameContent()
    {
    }
    
// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        VfxS32 i;
        for (i = 0; i < (VfxS32)VFX_FRAME_CONTENT_PLACEMENT_TYPE_END_OF_ENUM; i++)
        {
            VFX_OBJ_CREATE(m_frame[i], VfxFrame, this);
            m_frame[i]->setRect(VfxRect(10 + (i % 3) * 80, 10 + (i / 3) * 80, 60, 40));
            m_frame[i]->setBorderColor(VFX_COLOR_WHITE);
            m_frame[i]->setBorderWidth(1);
            m_frame[i]->setContentPlacement((VfxFrameContentPlacementTypeEnum)i);
        }
    }

    virtual int start()
    {
        return 2;
    }

    void test0()
    {
        setTitle(VFX_WSTR("Resource ID"));
        
        VfxImageSrc imgSrc(IMG_GLOBAL_L1);

        VfxS32 i;
        for (i = 0; i < (VfxS32)VFX_FRAME_CONTENT_PLACEMENT_TYPE_END_OF_ENUM; i++)
        {
            m_frame[i]->setImgContent(imgSrc);
        }
        
        confirm(VFX_WSTR("Display L1 icon?"));
    }
    
    void test1()
    {
        setTitle(VFX_WSTR("NULL Resource ID"));
        
        VfxS32 i;
        for (i = 0; i < (VfxS32)VFX_FRAME_CONTENT_PLACEMENT_TYPE_END_OF_ENUM; i++)
        {
            m_frame[i]->setImgContent(VFX_IMAGE_SRC_NULL);
        }
        
        confirm(VFX_WSTR("Display no icon?"));
    }
    
    virtual VfxS32 phase(VfxS32 idx)
    {
        switch (idx)
        {
            case 0:
                test0();
                break;

            case 1:
                test1();
                break;

            default:
                VFX_DEV_ASSERT(0);
        }
        
        return -1;
    }
};


VtstTestResultEnum vtst_rt_frame_content(VfxU32 param)
{
    VTST_START_SCRN(VtstRtFrameContent);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__

