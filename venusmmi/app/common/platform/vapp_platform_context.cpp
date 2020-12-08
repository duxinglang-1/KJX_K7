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
 *  vapp_platform_context.cpp
 *
 * Project:
 * --------
 *  Venus Platform
 *
 * Description:
 * ------------
 *  Venus Platform Context, used by platform applications: 
 *    Home, Mainmenu, Lock, NCenter, Call
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vapp_platform_context.h"
#include "vapp_platform_context_cfg.h"
#include "vadp_asm.h"
#if defined(__VAPP_PLATFORM_CONTEXT_USE_MMV2__)
extern "C"
{
#include "CustDataRes.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
}
#endif

#if defined(__VAPP_PLATFORM_CONTEXT_USE_MMV2__)
static mmi_ret platfrom_context_static_proc(mmi_event_struct *evt);
#endif

/***************************************************************************** 
 * Local
 *****************************************************************************/

#if !defined(__VAPP_PLATFORM_CONTEXT_USE_MMV2__)

#ifdef __MTK_TARGET__
#ifdef __DYNAMIC_SWITCH_CACHEABILITY__
#pragma arm section zidata = "DYNAMICCACHEABLEZI_C_MMIPOOL"
#else
#pragma arm section zidata = "LARGEPOOL_FIRST_ZI"
#endif
#endif /* __MTK_TARGET__ */

static VfxU8 s_vappPlatformBuffer[VAPP_PLATFORM_CONTEXT_TOTAL];
#endif

/***************************************************************************** 
 * Class VfxObject
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappPlatformContext", VappPlatformContext, VfxContext);
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappPlatformContext);

VappPlatformContext::VappPlatformContext()
{

}

void VappPlatformContext::onInit()
{
    VfxContext::onInit();

#if defined(__VAPP_PLATFORM_CONTEXT_USE_MMV2__)
    VadpAsmProperty p;
	mmi_frm_group_create(GRP_ID_ROOT, VAPP_PLATFORM_CONTEXT, platfrom_context_static_proc, NULL);
    VadpAsm::getProperty(VAPP_PLATFORM_CONTEXT, p);
    p.f_prepare_w_reserve = 1;
    p.f_hide_in_oom = 1;
    VadpAsm::setProperty(VAPP_PLATFORM_CONTEXT, p);

    assignPoolWithSlmm(VAPP_PLATFORM_CONTEXT, mmi_res_get_app_heap_size(VAPP_PLATFORM_CONTEXT));
#else
    assignPool(s_vappPlatformBuffer, VAPP_PLATFORM_CONTEXT_TOTAL);
#endif
}

#if defined(__VAPP_PLATFORM_CONTEXT_USE_MMV2__)
VfxU32 VappPlatformContext::onGetShrinkSize(mmi_id app_id)
{
    return mmi_res_get_app_heap_shrink_size(VAPP_PLATFORM_CONTEXT);
}

VfxBool VappPlatformContext::onEnlargeHeapPrepare()
{
	return VFX_FALSE;
}

static mmi_ret platfrom_context_static_proc(mmi_event_struct *evt)
{
    mmi_ret ret = MMI_RET_OK;
    switch(evt->evt_id)
    {
    case EVT_ID_DELETE_DANGLE_GROUP_REQ:
        /* keep dangle group */
        return MMI_RET_ERR;
    }
    return ret;
}
#endif
