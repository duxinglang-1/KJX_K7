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
 *  vtst_rt_control.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for control
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
#include "vfx_string.h"
#include "vfx_datatype.h"
#include "vfx_frame.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_basic_type.h"
#include "vfx_control.h"
#include "vfx_app_cat_scr.h"


/***************************************************************************** 
 * Control Test Implementation
 *****************************************************************************/

class VtstRtControl : public VtstRtScr
{
// Variable
public:

// Constructor / Destructor
public:
    VtstRtControl()
    {
    }

// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();
        setTitle(VFX_WSTR("Control Test"));
    }

    virtual int start()
    {
        VfxFrame    *frameRed;
        VFX_OBJ_CREATE(frameRed, VfxFrame, this);
        frameRed->setRect(VfxRect(20, 20, 40, 40));
        
        VfxControl    *controlBlue;
        VFX_OBJ_CREATE(controlBlue, VfxControl, frameRed);
        controlBlue->setRect(VfxRect(10, 10, 15, 15));
        
        VfxControl    *controlGreen;
        VFX_OBJ_CREATE(controlGreen, VfxControl, frameRed);
        controlGreen->setRect(VfxRect(10, 10, 15, 15));
        
        VfxControl    *controlYellow;
        VFX_OBJ_CREATE(controlYellow, VfxControl, controlGreen);
        controlYellow->setRect(VfxRect(10, 10, 15, 15));
        
        check(controlBlue->getParentControl() == this, VFX_WSTR("Get Parent #1"));
        check(controlGreen->getParentControl() == this, VFX_WSTR("Get Parent #2"));
        check(controlYellow->getParentControl() == controlGreen, VFX_WSTR("Get Parent #3"));
        
        check(controlBlue->findScreen() == this, VFX_WSTR("Find Screen #1"));
        check(controlGreen->findScreen() == this, VFX_WSTR("Find Screen #2"));
        check(controlYellow->findScreen() == this, VFX_WSTR("Find Screen #3"));
        
        return 0; // no phase
    }
};


VtstTestResultEnum vtst_rt_control(VfxU32 param)
{
    VTST_START_SCRN(VtstRtControl);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__

