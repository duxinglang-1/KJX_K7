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
 *  vfx_app_cat_scr.cpp
 *
 * Project:
 * --------
 *  Venus UI Component
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_app_cat_scr.h"


#include "vfx_sys_config.h"
#include "vfx_mmi.h"

#include "vrt_datatype.h"
#include "vrt_canvas.h"

#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_screen.h"
#include "vfx_datatype.h"
#include "vfx_context.h"
#include "vfx_system.h"
#include "vfx_top_level.h"

#include "vadp_sys_trc.h"
extern "C"
{
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "gdi_include.h"
// for mmi_frm_is_in_backward_scenario()
#include "mmi_frm_prot.h"
#include "GlobalResDef.h"
}


/***************************************************************************** 
 * Class VfxAppCatScr
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VfxAppCatScr", VfxAppCatScr, VfxScreen);


VfxContext *VfxAppCatScr::s_context = NULL;
VfxU8 *VfxAppCatScr::s_memPoolBuf = NULL;


void VfxAppCatScr::initalize()
{
    // Initialize with default Screen ASM size
    initalizeWithScrAsmSize(VFX_SYS_MEM_DEFAULT_SCR_ASM_SIZE);
}


void VfxAppCatScr::initalizeWithScrAsmSize(VfxU32 heapSize)
{
    // Can not double initialize
    VFX_ASSERT(s_context == NULL);
    
    // Check parameters
    VFX_ASSERT(heapSize > 0);

    // Create heap from Screen ASM
    VFX_DEV_ASSERT(s_memPoolBuf == NULL);
    s_memPoolBuf = (VfxU8 *)mmi_frm_scrmem_alloc(heapSize);
    VfxBool outOfScreenASM = (s_memPoolBuf == NULL);
    VFX_ASSERT(!outOfScreenASM);

    // Create context
    initializeInt(s_memPoolBuf, heapSize);
}


void VfxAppCatScr::initalizeWithMem(void *heap, VfxU32 heapSize)
{
    // Can not double initialize
    VFX_ASSERT(s_context == NULL);

    // Check parameters
    VFX_ASSERT(heap != NULL && heapSize > 0);

    // Create context
    initializeInt((VfxU8 *)heap, heapSize);
}


void VfxAppCatScr::deinitalize()
{
    VFX_LOG(VFX_INFO, VFX_APPCATSCR_DEINITALIZE);

    // Must be initialized
    VFX_ASSERT(s_context != NULL);

    // Close context and free the memory buffer
    VFX_OBJ_CLOSE(s_context);

    // Free memory pool if needed
    if (s_memPoolBuf != NULL)
    {
        mmi_frm_scrmem_free(s_memPoolBuf);
        s_memPoolBuf = NULL;
    }
}

 
VfxAppCatScr::VfxAppCatScr() :
    m_isBackFromHistory(VFX_FALSE),
	m_appID(GRP_ID_INVALID)
{
}

VfxAppCatScr::VfxAppCatScr(MMI_ID app_id) :
    m_isBackFromHistory(VFX_FALSE),
	m_appID(app_id)
{
}


void VfxAppCatScr::onInit()
{
    VFX_LOG(VFX_INFO, VFX_APPCATSCR_ON_INIT, this);
        
    VfxScreen::onInit();

    VfxBool isBackward = mmi_frm_is_in_backward_scenario() ? VFX_TRUE : VFX_FALSE;
    m_isBackFromHistory = isBackward;

    // Setup Canvas Engine (VRT) and add screen to top level
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);

    // VfxAppCatSrc user may use vrt_sys_set_screen_rotation() to rotate screen.
    //  Apply it by default
    setRotateType(topLevel->getScreenRotateType());

    if (m_appID != GRP_ID_INVALID)
	{
	    setVrtCacheSize((VfxU32)(((mmi_res_get_app_vrt_mem_factor(m_appID))*VRT_MEM_UNIT_SIZE)+0.5));
    }
	
    topLevel->processScreenBeforeEnter(this, isBackward);
}


void VfxAppCatScr::onAfterInit()
{
    // Callback after the VfxAppCatScr has been initialized
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    topLevel->processScreenEnter(this, m_isBackFromHistory);
}


void VfxAppCatScr::onBeforeDeinit()
{
    VFX_LOG(VFX_INFO, VFX_APPCATSCR_ON_BEFORE_DEINIT, this);

    VfxBool isBackward = mmi_frm_is_in_backward_scenario() ? VFX_TRUE : VFX_FALSE;

    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    topLevel->processActiveScreenExit(isBackward);

    VfxScreen::onBeforeDeinit();
}


void VfxAppCatScr::onDeinit()
{
    VFX_LOG(VFX_INFO, VFX_APPCATSCR_ON_DEINIT, this);

    VfxBool isBackward = mmi_frm_is_in_backward_scenario() ? VFX_TRUE : VFX_FALSE;

    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    topLevel->processActiveScreenAfterExit(isBackward);

    VfxScreen::onDeinit();
}


void VfxAppCatScr::onObjectNotify(VfxId eventId, void *userData)
{
    switch (eventId)
    {
        case VFX_OBJECT_NOTIFY_ID_AFTER_INIT:
        {
            onAfterInit();
            return;
        }

        case VFX_OBJECT_NOTIFY_ID_BEFORE_DEINIT:
        {
            onBeforeDeinit();
            return;
        }

        default:
        {
            VfxScreen::onObjectNotify(eventId, userData);
            return;
        }
    }
}


void VfxAppCatScr::initializeInt(VfxU8 *heap, VfxU32 heapSize)
{
    VFX_LOG(VFX_INFO, VFX_APPCATSCR_INITALIZE, heap, heapSize);
    
    VFX_DEV_ASSERT(s_context == NULL);
    VFX_DEV_ASSERT(heap != NULL && heapSize > 0);
    
    // Prepare context
    VFX_OBJ_CREATE(s_context, VfxContext, VFX_SYS_GLOBAL_CONTEXT);
    s_context->assignPool(heap, heapSize);
}

