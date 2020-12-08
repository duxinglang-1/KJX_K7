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
 *  vtst_rt_switch.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for VcpSwitch
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_config.h"
#include "mmi_features.h"
#if defined(__AFX_RT_TEST__)  && defined(__MMI_VUI_COSMOS_CP__)

#include "vfx_uc_include.h"
#include "vfx_mc_include.h"
//#include "vcp_include.h"
#include "vtst_rt_main.h"
#include "vcp_async_image_frame.h"
#include "mmi_rp_srv_venus_component_popup_def.h"

/***************************************************************************** 
 * Control Test Implementation
 *****************************************************************************/

class VtstRtAsyncImageFrameScr : public VfxAppScr
{
//    VFX_DECLARE_CLASS(VtstRtAsyncImageFrameScr);


// Override
protected:
    virtual void onInit();

};

void VtstRtAsyncImageFrameScr::onInit()
{
    VfxAppScr::onInit();

    setBgColor(VFX_COLOR_WHITE);

    //for (int i = 0; i < 12; ++i)
    for (int i = 0; i < 12; ++i)
    {
        VcpAsyncImageFrame *async1;

        //VFX_OBJ_CREATE_EX(async1, VcpAsyncImageFrame, this, (VFX_WSTR("D:\\Images\\01.gif"), IMG_ID_VAPP_COSMOS_MAINMENU_ICON_HOME, VfxSize(80, 80)) );
        VFX_OBJ_CREATE_EX(async1, VcpAsyncImageFrame, this, (VFX_WSTR("E:\\frameEffect\\beanFlower2.jpg"), VCP_IMG_POPUP_TYPE_FAILURE_CONFIRM, VfxSize(80, 80)) );
        async1->setPos(20 + 90 * (i % 3), 20 + 90 * (i / 3));
    }
}

class VtstRtAsyncImageFrameApp : public VfxApp
{
    VFX_DECLARE_CLASS(VtstRtAsyncImageFrameApp );

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize);
};

VFX_IMPLEMENT_CLASS("VtstRtAsyncImageFrameApp", VtstRtAsyncImageFrameApp, VfxApp);

void VtstRtAsyncImageFrameApp::onRun(void* args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    VtstRtAsyncImageFrameScr *scr;
    VFX_OBJ_CREATE(scr, VtstRtAsyncImageFrameScr, this);
    scr->show();
}


VtstTestResultEnum vtst_rt_async_image_frame(VfxU32 param)
{
//    VTST_START_SCRN(VtstRtAsyncImageFrame);
    VFX_UNUSED(param);
    VfxAppLauncher::launchWithAsmSize(
        APP1_BASE,
        VFX_OBJ_CLASS_INFO(VtstRtAsyncImageFrameApp),
        GRP_ID_ROOT, 204800 * 3,
        NULL, 0);
    return VTST_TR_OK;
}

#endif // __AFX_RT_TEST__

