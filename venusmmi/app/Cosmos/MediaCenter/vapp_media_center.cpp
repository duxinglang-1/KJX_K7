/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
 *  vapp_media_center_app.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/

#include "MMI_features.h" 
#ifdef __MMI_3D_MEDIA_CENTER__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_config.h"
#include "vfx_object.h"
#include "vcp_include.h"
#include "vapp_media_center.h"

extern "C"  
{
#include "mmi_rp_vapp_media_center_def.h"
}

/***************************************************************************** 
 * Define
 *****************************************************************************/
/***************************************************************************** 
 * APP Launch function
 *****************************************************************************/
extern "C"
{
extern MMI_ID vapp_media_center_launch(void* param, U32 param_size)
{
    return VfxAppLauncher::launch(VAPP_MEDIA_CENTER,
                                   VFX_OBJ_CLASS_INFO(VappMediaCenterApp),
                                   GRP_ID_ROOT);
}

extern mmi_ret vapp_media_center_package_proc(mmi_event_struct* param)
{
    return MMI_RET_DONT_CARE;
}
}
/***************************************************************************** 
 * Class Implementation
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappMediaCenterApp", VappMediaCenterApp, VfxApp);
VFX_IMPLEMENT_CLASS("VappMediaCenterScreen", VappMediaCenterScreen, VfxMainScr);

/***************************************************************************** 
 * Class Implementation : VappMediaCenterApp
 *****************************************************************************/
void VappMediaCenterApp::onInit()
{
    VfxApp::onInit();
}

void VappMediaCenterApp::onDeinit()
{
    VfxApp::onDeinit();
}

void VappMediaCenterApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);
    VappMediaCenterScreen *scr = NULL;
    VFX_OBJ_CREATE(scr, VappMediaCenterScreen, this);
    scr->setBgColor(VFX_COLOR_TRANSPARENT);
    scr->show();
}

/***************************************************************************** 
 * Class Implementation : VappMediaCenterScreen
 *****************************************************************************/
VappMediaCenterScreen::VappMediaCenterScreen()
{
}

void VappMediaCenterScreen::onInit()
{
    VfxMainScr::onInit();
}
class VappMediaCenterPage;
void VappMediaCenterScreen::on1stReady()
{
    setBgColor(VFX_COLOR_BLACK);
    VappMediaCenterPage *page = NULL;
    VFX_OBJ_CREATE(page, VappMediaCenterPage, this);
    pushPage(0, page);
}

#endif // __COSMOS_3D_MEDIA_CENTER__
