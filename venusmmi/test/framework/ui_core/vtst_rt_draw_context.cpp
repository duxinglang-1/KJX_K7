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
 *  vtst_rt_draw_context.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for draw context
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
#include "vfx_string.h"
#include "vfx_draw_context.h"
#include "vfx_image_src.h"
#include "vfx_basic_type.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_app_cat_scr.h"

extern "C"
{
#include "GlobalResDef.h"
}


/***************************************************************************** 
 * Object Test Implementation
 *****************************************************************************/

class VtstRtDrawContext : public VtstRtScr
{
// Variable
public:
    VfxS32 m_phase;
    
// Constructor / Destructor
public:
    VtstRtDrawContext() : m_phase(0)
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        switch(m_phase)
        {
            case 0:
                setTitle(VFX_WSTR("Image Source"));
                break;
                
            default:
                break;
        }
        
        m_phase = idx;
        invalidate();
        
        confirm(VFX_WSTR("Correct?"));
        return -1;
    }

    virtual void onDraw(VfxDrawContext &dc)
    {
        switch(m_phase)
        {
            case 0:
                onDraw0(dc);
                break;
                
            default:
                break;
        }
    }
    
    void onDraw0(VfxDrawContext &dc)
    {
        VfxImageSrc img1(IMG_GLOBAL_L1);
        VfxImageSrc img2(IMG_GLOBAL_L2);
        VfxImageSrc img3(IMG_GLOBAL_L3);
        VfxImageSrc img4(IMG_GLOBAL_L4);
        VfxImageSrc img5(IMG_GLOBAL_L5);

        VfxSize resizedSize(img1.getSize());
        resizedSize.width /= 2;
        resizedSize.height /= 2;
        
        dc.drawImage(10, 100, img1);
        dc.drawImage(40, 100, img2);
        dc.drawImage(70, 100, img3);
        dc.drawImage(100, 100, img4);
        dc.drawImage(130, 100, img5);
        dc.drawResizedImage(VfxRect(10, 150, resizedSize.width, resizedSize.height), img1);
        dc.drawResizedImage(VfxRect(40, 150, resizedSize.width, resizedSize.height), img2);
        dc.drawResizedImage(VfxRect(70, 150, resizedSize.width, resizedSize.height), img3);
        dc.drawResizedImage(VfxRect(100, 150, resizedSize.width, resizedSize.height), img4);
        dc.drawResizedImage(VfxRect(130, 150, resizedSize.width, resizedSize.height), img5);
    }
};


VtstTestResultEnum vtst_rt_draw_context(VfxU32 param)
{
    VTST_START_SCRN(VtstRtDrawContext);
    return VTST_TR_OK;
}


#endif // __AFX_RT_TEST__

