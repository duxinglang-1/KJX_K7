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
 *  vfx_system.c
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Provide system information for porting.
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
 * removed!
 *
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

#include "vfx_system.h"
// For vfx_sys_mem_init()
#include "vfx_sys_memory.h"
// For vfx_sys_mem_config_entry(), etc.
#include "vfx_sys_mem_config.h"
// For vfx_adp_lcd_get_state()
#include "vfx_adp_device.h"
// For VFX_SYS_MEM_VRT_CACHE_LIMIT_SIZE and VFX_SYS_MEM_VRT_CACHE_MAX_SIZE
#include "vfx_sys_config.h"

#include "vrt_datatype.h"
#include "vrt_base_allocator.h"
#include "vrt_system.h"
#include "vrt_canvas.h"
#include "vfx_datatype.h"

#include "MMI_features.h"

#include "vadp_sys_trc.h"

#include "MMIDataType.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_trace.h"

#include "mmi_frm_scenario_gprot.h"


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/* System status */
static vfx_sys_state_enum g_vfx_sys_canvas_state = VFX_SYS_STATE_UNKNOWN;


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  vfx_sys_init
 * DESCRIPTION
 *  Initialize UI Core system
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_sys_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vfx_sys_canvas_state = VFX_SYS_STATE_INIT;

    /* Initialize sub systems */
    vfx_adp_os_init();
    vfx_sys_mem_init();

    /* Initialize VRT Canvas engine */
    vrt_canvas_init(vfx_sys_get_vrt_mem_provider());

    /* Change the engine state */    
    g_vfx_sys_canvas_state = VFX_SYS_STATE_LEAVE;
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_entry_canvas
 * DESCRIPTION
 *  Entry the Venus UI Screen
 * PARAMETERS
 *  allocator       [IN] The memory pool for Canvas Engine (don't used)
 *  flags           [IN] The flags to entry Canvas Engine
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_sys_entry_canvas(vrt_allocator_handle app_allocator, VfxFlag mem_config_flags, VfxFlag vrt_entry_canvas_flags, vrt_s32 cache_config_size, vrt_u32 cache_limit_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vfx_sys_mem_config_param_struct mem_config_param;
    vrt_canvas_entry_param_struct entry_param;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_LOG(VFX_INFO, VFX_SYS_ENTRY_CANVAS, vrt_get_current_frame_time());

    /* Check state */
    VFX_ASSERT(g_vfx_sys_canvas_state != VFX_SYS_STATE_ENTRY);

    /* Check parameter */
    VFX_ASSERT(app_allocator != NULL);

    /* 
     * Setup system memory 
     */
    mem_config_param.app_allocator = app_allocator;
    mem_config_param.flags = mem_config_flags;
    vfx_sys_mem_config_entry(&mem_config_param);

    /* 
     * Entry VRT 
     */
    entry_param.flags = vrt_entry_canvas_flags;
    entry_param.app_id = mmi_frm_group_get_active_id();
    entry_param.allocator = vfx_sys_get_vrt_context_allocator();
    entry_param.asm_cache_size = cache_config_size;
    entry_param.cache_limit_size = 
        VFX_MIN(VFX_SYS_MEM_VRT_CACHE_LIMIT_SIZE, VFX_SYS_MEM_VRT_CACHE_MAX_SIZE) + 
            (cache_limit_size != 0 ? cache_limit_size : cache_config_size);
    vrt_canvas_entry(&entry_param);

    /* 
     * Finish. Change the engine state.
     */
    g_vfx_sys_canvas_state = VFX_SYS_STATE_ENTRY;
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_entry_canvas_entered
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *****************************************************************************/
void vfx_sys_entry_canvas_entered(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vfx_sys_mem_config_screen_entered();
    vrt_canvas_entered(); 
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_leave
 * DESCRIPTION
 *  Leave the Venus UI Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_sys_leave_canvas(VfxFlag vrt_leave_canvas_flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vrt_canvas_leave_param_struct leave_param;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_ASSERT(g_vfx_sys_canvas_state == VFX_SYS_STATE_ENTRY);

    /* Leave canvas and free VRT usage memory */
    leave_param.flags = vrt_leave_canvas_flags;
    vrt_canvas_leave(&leave_param);

    /* Deinit system memory */
    vfx_sys_mem_config_leave();
    
    /* Finish. Change the engine state. */
    g_vfx_sys_canvas_state = VFX_SYS_STATE_LEAVE;

    VFX_LOG(VFX_INFO, VFX_SYS_LEAVE_CANVAS, vrt_get_current_frame_time());
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_get_state
 * DESCRIPTION
 *  Get the Venus UI engine state
 * PARAMETERS
 *  void
 * RETURNS
 *  The state of Venus UI engine
 *****************************************************************************/
vfx_sys_state_enum vfx_sys_get_canvas_state(void)
{
    return g_vfx_sys_canvas_state;
}

