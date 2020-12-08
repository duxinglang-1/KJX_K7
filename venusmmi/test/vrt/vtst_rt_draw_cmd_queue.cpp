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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_datatype.h"
#include "vfx_input_event.h"
#include "vfx_string.h"
#include "vfx_draw_context.h"
#include "vfx_image_src.h"
#include "vfx_basic_type.h"
#include "vtst_rt_main.h"

extern "C"
{
    #include "GlobalResDef.h"
}

#ifdef __AFX_RT_TEST__


/***************************************************************************** 
 * Object Test Implementation
 *****************************************************************************/

class VtstRtDrawCmdQueue : public VtstRtScr
{
// Variable
public:
    VfxS32 m_phase;
    VfxS32 m_maxCount;
    
// Constructor / Destructor
public:
    VtstRtDrawCmdQueue() : 
        m_phase(0),
        m_maxCount(200)
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        setBgColor(VFX_COLOR_GREY);
        setFocused(VFX_TRUE);
    }

    virtual int start()
    {
        return 1;
    }

    virtual VfxBool onPenInput(VfxPenEvent & event)
    {
        VfxBool t = VtstRtScr::onPenInput(event);

        if (!t)
        {
            if (event.type == VFX_PEN_EVENT_TYPE_UP)
            {
                m_maxCount += 10;
                if (m_maxCount > 2400)
                {
                    m_maxCount = 10;
                }
            }

            invalidate();
            return VFX_TRUE;
        }
        else
        {
            return t;
        }
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        switch(idx)
        {
            case 0:
                setTitle(VFX_WSTR("Draw Cmd Queue"));
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
        VfxS32 x, y, width, height;
        
        for (VfxS32 i = 0; i < m_maxCount; i++)
        {
            width  = 8;
            height = 8;
            x = (width * i) % 320;
            y = ((width * i) / 320) * height;

            VfxImageSrc imgSrc;
            imgSrc.setResId(IMG_GLOBAL_L1);
        
            dc.drawResizedImage(VfxRect(x, y, width, height), imgSrc);
            VfxColor color = 0xFF000000 | (((x*256/40) & 0xFF) << 16) | (((y*256/40) & 0xFF) << 8) | (135 & 0xFF);
            dc.setFillColor(color);
            dc.fillRect(x, y, width, height);
        }
    }
};


VtstTestResultEnum vtst_rt_draw_cmd_queue(VfxU32 param)
{
    VTST_START_SCRN(VtstRtDrawCmdQueue);
    
    return VTST_TR_OK;
}


#endif // __AFX_RT_TEST__


