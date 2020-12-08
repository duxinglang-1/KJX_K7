/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vfx_system.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  SSE (Screen switch effect)  Adapatation Layer
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

#include "vfx_adp_sse.h"

extern "C"
{
#include "gui_effect_oem.h"    /* for gui_sse_scenario_enum && gui_sse_setup_scenario */
}


/***************************************************************************** 
 * Local Variable
 *****************************************************************************/

static const struct
{
    gui_sse_scenario_enum in;
    gui_sse_scenario_enum out;
} g_vfx_adp_sse_table[VFX_SCR_TRANSIT_TYPE_END_OF_ENUM] = 
{
     {GUI_SSE_SCENARIO_NONE, GUI_SSE_SCENARIO_NONE}
    ,{GUI_SSE_SCENARIO_NO_EFFECT, GUI_SSE_SCENARIO_NO_EFFECT}
     
    /* ===== System effect ===== */
#if defined(__COSMOS_MMI__)
    ,{GUI_SSE_SCENARIO_COSMOS_APP_ENTRY, GUI_SSE_SCENARIO_COSMOS_APP_EXIT}
    ,{GUI_SSE_SCENARIO_COSMOS_PAGE_ENTRY, GUI_SSE_SCENARIO_COSMOS_PAGE_EXIT}
    ,{GUI_SSE_SCENARIO_COSMOS_PAGE_ENTRY, GUI_SSE_SCENARIO_COSMOS_PAGE_EXIT}
    ,{GUI_SSE_SCENARIO_COSMOS_MOVE_ENTRY, GUI_SSE_SCENARIO_COSMOS_MOVE_EXIT}
#if defined(__MMI_SCREEN_SWITCH_EFFECT_VENUS__) &&  defined(__COSMOS_3D_V10__)
    ,{GUI_SSE_SCENARIO_COSMOS_3D_TRIANGLE_ENTER, GUI_SSE_SCENARIO_COSMOS_3D_TRIANGLE_EXIT}
    ,{GUI_SSE_SCENARIO_COSMOS_3D_CIRCLE_ENTER, GUI_SSE_SCENARIO_COSMOS_3D_CIRCLE_EXIT}
    ,{GUI_SSE_SCENARIO_COSMOS_3D_CUBE_ENTER, GUI_SSE_SCENARIO_COSMOS_3D_CUBE_EXIT}
    ,{GUI_SSE_SCENARIO_COSMOS_3D_BRICK_ENTER, GUI_SSE_SCENARIO_COSMOS_3D_BRICK_EXIT}
    ,{GUI_SSE_SCENARIO_COSMOS_3D_TWIST_ENTER, GUI_SSE_SCENARIO_COSMOS_3D_TWIST_EXIT}
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT_VENUS__) &&  defined(__COSMOS_3D_V10__) */
#else
    ,{GUI_SSE_SCENARIO_NONE, GUI_SSE_SCENARIO_NONE}
    ,{GUI_SSE_SCENARIO_NONE, GUI_SSE_SCENARIO_NONE}
    ,{GUI_SSE_SCENARIO_NONE, GUI_SSE_SCENARIO_NONE}
    ,{GUI_SSE_SCENARIO_NONE, GUI_SSE_SCENARIO_NONE}
#if defined(__MMI_SCREEN_SWITCH_EFFECT_VENUS__) &&  defined(__PLUTO_3D_V10__)
    ,{GUI_SSE_SCENARIO_COSMOS_3D_TRIANGLE_ENTER, GUI_SSE_SCENARIO_COSMOS_3D_TRIANGLE_EXIT}
    ,{GUI_SSE_SCENARIO_COSMOS_3D_CIRCLE_ENTER, GUI_SSE_SCENARIO_COSMOS_3D_CIRCLE_EXIT}
    ,{GUI_SSE_SCENARIO_COSMOS_3D_CUBE_ENTER, GUI_SSE_SCENARIO_COSMOS_3D_CUBE_EXIT}
    ,{GUI_SSE_SCENARIO_COSMOS_3D_BRICK_ENTER, GUI_SSE_SCENARIO_COSMOS_3D_BRICK_EXIT}
    ,{GUI_SSE_SCENARIO_COSMOS_3D_TWIST_ENTER, GUI_SSE_SCENARIO_COSMOS_3D_TWIST_EXIT}
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT_VENUS__) &&  defined(__PLUTO_3D_V10__) */
#endif

    /* ===== App effect ===== */
};

static gui_sse_scenario_enum g_vfx_adp_sse_type = GUI_SSE_SCENARIO_NONE;
static VfxScrTransitPriority g_vfx_adp_sse_priority  = VFX_SCR_TRANSIT_PRIORITY_SCR;


/***************************************************************************** 
 * Local Function
 *****************************************************************************/

void vfx_adp_sse_setup_transit(VfxScrTransitTypeEnum type, VfxBool in, VfxScrTransitPriority priority)
{
    if (type == VFX_SCR_TRANSIT_TYPE_DEFAULT)
        return;

    if(priority >= g_vfx_adp_sse_priority)
    {
        g_vfx_adp_sse_priority = priority;
        g_vfx_adp_sse_type = in ? g_vfx_adp_sse_table[type].in : g_vfx_adp_sse_table[type].out;
    }
}

void vfx_adp_sse_commit()
{
    if(g_vfx_adp_sse_type != GUI_SSE_SCENARIO_NONE)
    {
        gui_sse_setup_scenario(g_vfx_adp_sse_type);
    }

    g_vfx_adp_sse_type = GUI_SSE_SCENARIO_NONE;
    g_vfx_adp_sse_priority  = VFX_SCR_TRANSIT_PRIORITY_SCR;
}

