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
 *  vfx_adp_os.c
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Operation System Adapatation Layer
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_adp_os.h"
#include "vfx_datatype.h"

#include "MMI_features.h"

/* For ILM */
#include "app_ltlcom.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "stack_ltlcom.h"

/* For SSE */
#include "gui_effect_oem.h" 

/* For theme resource */
#include "CustVenusThemeRes.h"  

/* For engineer mode */
#include "mmi_rp_app_engineermode1_def.h" 

#include "MMIDataType.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_rp_venus_ui_core_def.h"
#include "Unicodexdcl.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "CustDataRes.h"
#include "kal_trace.h"
#include "mmi_frm_input_gprot.h"
#include "GlobalResDef.h"
#include "med_smalloc.h"
#include "png_memory_usage.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_nvram_gprot.h"

/* For Mutex */
#include "vrt_mutex.h"


/***************************************************************************** 
 * Local Variable
 *****************************************************************************/

/* For check whether this is in MMI */
static kal_taskid g_vfx_mmi_task_id = KAL_NILTASK_ID;

/*
 * Mutex
 */ 
static vrt_mutex_struct g_vfx_sys_post_mutex = { 0 };
static vrt_mutex_struct g_vfx_sys_obj_mutex = { 0 };
static vrt_mutex_struct g_vfx_sys_weak_obj_mutex = { 0 };


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  vfx_adp_os_init
 * DESCRIPTION
 *  Initialize the Adapatation Layer on bootup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_adp_os_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vfx_mmi_task_id == KAL_NILTASK_ID)
    {
        g_vfx_mmi_task_id = kal_get_task_self_id();
    }

    /* Initialize mutex */
    vrt_mutex_init(&g_vfx_sys_post_mutex);
    vrt_mutex_init(&g_vfx_sys_obj_mutex);
    vrt_mutex_init(&g_vfx_sys_weak_obj_mutex);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_is_mmitask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  Non-zero if caller task is MMI
 *****************************************************************************/
int vfx_sys_is_mmitask(void)
{
    VFX_DEV_ASSERT(g_vfx_mmi_task_id != KAL_NILTASK_ID);
    return g_vfx_mmi_task_id == kal_get_task_self_id() ? 1 : 0;
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_notify_mmitask
 * DESCRIPTION
 *  Notify MMI task wake up to handle event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_sys_notify_mmitask(void)
{
    // If the caller task is not mmi, we need to weakup mmi task
    // TODO: should have another better solution to do this
    if (!vfx_sys_is_mmitask())
    {
        ilm_struct *ilm_ptr = NULL;
        ilm_ptr = allocate_ilm(stack_get_active_module_id());
        
        ilm_ptr->src_mod_id = stack_get_active_module_id();
        ilm_ptr->dest_mod_id = MOD_MMI;
        ilm_ptr->sap_id = (sap_type)0;
        ilm_ptr->msg_id = (msg_type)0;
        ilm_ptr->local_para_ptr = (local_para_struct*) NULL;
        ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;

        msg_send_ext_queue(ilm_ptr);        
    }
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mutex_lock
 * DESCRIPTION
 *  Lock the memory pool's mutex
 * PARAMETERS
 *  vrt_mutex_struct
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_sys_mutex_lock(vfx_sys_mutex_struct *mem_mutex)
{
    vrt_mutex_lock(mem_mutex);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mutex_unlock
 * DESCRIPTION
 *  Unlock the memory pool's mutex
 * PARAMETERS
 *  vrt_mutex_struct
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_sys_mutex_unlock(vfx_sys_mutex_struct * mem_mutex)
{
    vrt_mutex_unlock(mem_mutex);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_mutex_init
 * DESCRIPTION
 *  Init the memory pool's mutex
 * PARAMETERS
 *  vrt_mutex_struct
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_sys_mutex_init(vfx_sys_mutex_struct * mem_mutex)
{
    vrt_mutex_init(mem_mutex);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_acquire_post_lock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_sys_acquire_post_lock(void)
{
    vrt_mutex_lock(&g_vfx_sys_post_mutex);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_release_post_lock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_sys_release_post_lock(void)
{
    vrt_mutex_unlock(&g_vfx_sys_post_mutex);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_acquire_obj_hdl_lock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_sys_acquire_obj_hdl_lock(void)
{
    vrt_mutex_lock(&g_vfx_sys_obj_mutex);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_release_obj_hdl_lock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_sys_release_obj_hdl_lock(void)
{
    vrt_mutex_unlock(&g_vfx_sys_obj_mutex);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_acquire_weak_obj_hdl_lock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_sys_acquire_weak_obj_hdl_lock(void)
{
    vrt_mutex_lock(&g_vfx_sys_weak_obj_mutex);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_release_weak_obj_hdl_lock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_sys_release_weak_obj_hdl_lock(void)
{
    vrt_mutex_unlock(&g_vfx_sys_weak_obj_mutex);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_timer_start
 * DESCRIPTION
 *  Start the system timer
 * PARAMETERS
 *  delay       [IN]    time to delay
 *  callback    [IN]    the callback function after delay
 *  data        [IN]    callback data
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_sys_timer_start(VfxU32 delay, vfx_sys_callback_funcptr_type callback, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StartTimerEx(VENUS_UI_TIMER_BASE, (U32)delay,  callback, data);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_timer_stop
 * DESCRIPTION
 *  Stop the system timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_sys_timer_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(VENUS_UI_TIMER_BASE);
}


/*****************************************************************************
 * FUNCTION
 *  vfxSysResGetStr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
const VfxWChar *vfxSysResGetStr(VfxResId str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (const VfxWChar *)GetString((U16)str_id);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_res_get_binary
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
const VfxU8 *vfx_sys_res_get_binary(VfxResId binary_id, VfxU32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const VfxU8 *start = NULL; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    start = (const VfxU8*)GetBinary(binary_id);

    if (start == NULL)
    {
        return NULL;
    }

    /* first byte is type, 2~5 is size */
    if (size != NULL)
    {
        *size = 
            start[1] | 
            start[2] << 8 | 
            start[3] << 16 | 
            start[4] << 24;
    }

    return (start + 8);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_res_get_color
 * DESCRIPTION
 *  get color resource
 * PARAMETERS
 *  color_id    [IN] resource ID
 * RETURNS
 *  color value
 *****************************************************************************/
VfxU32 vfx_sys_res_get_color(VfxResId color_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (VfxU32)mmi_res_get_theme_color((U16)color_id);
}


/*****************************************************************************
 * FUNCTION
 *  vfx_sys_res_get_font
 * DESCRIPTION
 *  get font resource
 * PARAMETERS
 *  font_id     [IN] resource ID
 *  font        [OUT] font structure
 * RETURNS
 *  void
 *****************************************************************************/
void vfx_sys_res_get_font(VfxResId font_id, vfx_sys_res_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_res_theme_font_style_struct fontStyle = mmi_res_get_theme_font_style((U16)font_id);
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    font->size = (VfxU8)fontStyle.size;
    font->attribute = (VfxU8)fontStyle.attribute;
    font->effect = (VfxU8)fontStyle.effect;
}


/*****************************************************************************
 * FUNCTION
 *  vfx_debug_panel_get_enable
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  if debug panel enabled
 *****************************************************************************/
int vfx_debug_panel_get_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EM_PROFILING_VENUS_DEBUG_PANEL__
    VfxU8 value;
    VfxS16 error;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EM_PROFILING_VENUS_DEBUG_PANEL__
    ReadValue(NVRAM_VENUS_DEBUG_PANEL_ENABLE, &value, DS_BYTE, &error);
    return (error == NVRAM_READ_SUCCESS && value > 0) ? 1 : 0;
#else
    return 0;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vfx_profiling_panel_get_enable
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  if profiling panel enabled
 *****************************************************************************/
int vfx_profiling_panel_get_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_INTERACTIVE_PROFILNG__
    return mmi_frm_profiling_interactive_is_enabled();
#else
    return 0;
#endif
}

