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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  MmiMemMonitor.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 * Memory monitor mechanism
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
 
#include "kal_internal_api.h"
#include "MMI_include.h"
#include "vadp_p2v_mem_info.h"
#include "mmi_frm_prot.h"
#include "kal_afm.h"
#include "mmi_frm_scenario_prot.h"
/*****************************************************************************
 * typedef
 *****************************************************************************/
#ifdef __MMI_MEMORY_MONITOR__
#include "MMI_features.h"
#include "MMIDataType.h"
#include "app_mem.h"
#include "mmi_frm_mem_gprot.h"
#include "gui_config.h"
#include "gui.h"
#include "gui_data_types.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "Unicodexdcl.h"
#include "gui_themes.h"
#include "fix_size_mem.h"
#include "mmi_frm_events.h"
#include "string.h"
#include "ctrl_buff_pool.h"
#include "stack_buff_pool.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
#include "mmi_frm_input_gprot.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "mmi_rp_app_engineermode1_def.h"


//#define MMI_FRM_MEMMONT_OUTBUF_SIZE     64
#define MMI_FRM_MEMMONT_OUTBUF_SIZE     128
#define MMI_MEM_MONITOR_ASM_DATA_NUM    4
#define MMI_MEM_MONITOR_OSL_DATA_NUM    3

#define MMI_MEM_END_OF_LINE     (0x000A)    /* "\n" */

typedef struct
{
    /* Control buffer */
    U32 mem_osl_maximal_alloc_size;
    U32 mem_osl_current_alloc_size;
    U32 mem_osl_total_alloc_count;
    U32 mem_osl_total_alloc_size;
    /* Screen based asm */
    applib_asm_mem_detail_info_struct mem_scr_detail_info;
    /* Application asm */
    applib_asm_mem_detail_info_struct mem_app_detail_info;
    /* Control buffer */
#if defined(MONITOR_BUF1)
    asm_mem_alloc_info_struct mem_asm_alloc_info[APPLICATION_ID_TOTAL];
#endif
} mmi_mem_mon_info_struct;

/* string drawing function pointer, may set by venus UI */
static mmi_mem_mon_string_drawing_func_type string_drawing_function = NULL;

static mmi_mem_mon_canvas_type mem_mon_canvas = {0, 0, 0, 0};   /* x1, y1, x_offset, y_offset */

//
extern void mmi_mem_osl_info_cb(PU8 unicode_str, U32 str_len, mmi_mem_mon_canvas_type *canvas_p);
extern void mmi_mem_asm_info_cb(PU8 unicode_str, U32 str_len, mmi_mem_mon_canvas_type *canvas_p);
extern void mmi_mem_afm_info_cb(PU8 unicode_str, U32 str_len, mmi_mem_mon_canvas_type *canvas_p);

/* string and callback function, the order should be the same as mmi_mem_monitor_type_enum */
const mmi_mem_mon_info_str_cb_type g_mmi_mem_mon_list[MMI_EM_MEMORY_MONITOR_TOTAL] = {
    NULL,                           /* OFF */
    mmi_mem_osl_info_cb,            /* OSL */
    mmi_mem_asm_info_cb,            /* ASM */
    #ifdef __MMI_VUI_ENGINE__
    vadp_p2v_get_vui_mem_info,      /* VUI */
    #endif /* __MMI_VUI_ENGINE__ */
    mmi_mem_afm_info_cb             /* AFM */
};

/*****************************************************************************
 * Local Variable                                                              
 *****************************************************************************/
static mmi_mem_mon_info_struct g_mmi_mem_mon_info_struct;

/*****************************************************************************
 * Define                                                    
 *****************************************************************************/
#define MMI_MEM_MON_BG_COLOR    (gui_color(0, 0, 0))
#define MMI_MEM_MON_FT_COLOR    (gui_color(255, 255, 255))

/*****************************************************************************
 * Local Function declaration                                                     
 *****************************************************************************/
 
/*****************************************************************************
 * Global Function                                                              
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_mem_mon_draw_info
 * DESCRIPTION
 *  Draw memory monitor statistics
 * PARAMETERS
 *  unicode_str      [IN]   string content
 *  x1 y1 x2 y2      [IN]   string position
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mem_mon_draw_info(PU16 unicode_str, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* if drawing function is set, use it; otherwise, use default method */
    if (string_drawing_function)
    {
        string_drawing_function(unicode_str, x1, y1, x2, y2);
        return;
    }

    #if(UI_DOUBLE_BUFFER_SUPPORT)
        gui_lock_double_buffer();
    #endif 
        gui_push_clip();
        gui_set_clip(x1, y1, x2, y2);
    
        gui_fill_rectangle(x1, y1, x2, y2, MMI_MEM_MON_BG_COLOR);
        gui_set_text_color(MMI_MEM_MON_FT_COLOR);
        gui_move_text_cursor(x1, y1);
        gui_print_text((UI_string_type)unicode_str);
    
        gui_pop_clip();
    #if(UI_DOUBLE_BUFFER_SUPPORT)
        gui_unlock_double_buffer();
        gui_BLT_double_buffer(x1, y1, x2, y2);
    #endif /* (UI_DOUBLE_BUFFER_SUPPORT) */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mem_mon_set_string_drawing_function
 * DESCRIPTION
 *  set string drawing function
 * PARAMETERS
 *  func_ptr     [IN]    pointer to string drawing function
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mem_mon_set_string_drawing_function(mmi_mem_mon_string_drawing_func_type func_ptr)
{
    string_drawing_function = func_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mem_mon_print_string
 * DESCRIPTION
 *  print string to memory monitor canvas
 * PARAMETERS
 *  canvas_p        [IN]    pointer to canvas
 *  unicode_str     [IN]    unicode string (can have new-line char)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mem_mon_print_string(mmi_mem_mon_canvas_type *canvas_p, PU16 unicode_str)
{
    S32 sw, sh; /* string width and string height */
    S32 x1, y1, x2, y2;
    PU16 str = unicode_str;

    /* prevent string overflow */
    MMI_ASSERT(mmi_wcslen(unicode_str) <= MMI_FRM_MEMMONT_OUTBUF_SIZE * ENCODING_LENGTH);

    /* set string font */
    gui_set_font(&MMI_small_font);

    while (*unicode_str)
    {
        /* replace \n to end-of-string */
        while (*str)
        {
            if (MMI_MEM_END_OF_LINE == *str)
            {
                *str = 0;
                str++;
                break;
            }
            str++;   
        }

        /* measure string size */
        gui_measure_string((UI_string_type) unicode_str, &sw, &sh);

        /* set string position */
        x1 = canvas_p->x1;
        x2 = x1 + sw - 1;
        y1 = canvas_p->y1 + canvas_p->y_offset;
        y2 = y1 + sh - 1;

        /* update canvas info (x_offset is for max. x usage) */
        canvas_p->y_offset = y2;
        if (x2 > canvas_p->x_offset)
        {
            canvas_p->x_offset = x2;
        }

        mmi_mem_mon_draw_info(unicode_str, x1, y1, x2, y2);

        unicode_str = str;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mem_afm_info_cb
 * DESCRIPTION
 *  information string callback for AFM memory
 * PARAMETERS
 *  unicode_str     [IN]    string buffer
 *  str_len         [IN]    string buffer length
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mem_afm_info_cb(PU8 unicode_str, U32 str_len, mmi_mem_mon_canvas_type *canvas_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 size[MMI_AFM_SUB_POOL_NUM + 1];
    U32 total_num[MMI_AFM_SUB_POOL_NUM + 1];
    U32 left_num[MMI_AFM_SUB_POOL_NUM + 1];
    U32 min_left_num[MMI_AFM_SUB_POOL_NUM + 1];
    S32 pool_index;
    U32 i;
    const WCHAR *scenario_obj[SCENARIO_NODE_END] = {L"G", L"S", L"T", L"P", L"V",L"E", L"A"};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    size[MMI_AFM_SUB_POOL_NUM] = AFM_SUBPOOL_END_PATTERN;
    total_num[MMI_AFM_SUB_POOL_NUM] = AFM_SUBPOOL_END_PATTERN;
    left_num[MMI_AFM_SUB_POOL_NUM] = AFM_SUBPOOL_END_PATTERN;
    min_left_num[MMI_AFM_SUB_POOL_NUM] = AFM_SUBPOOL_END_PATTERN;

    mmi_frm_fix_mem_get_info(size, total_num, left_num, min_left_num, MMI_AFM_SUB_POOL_NUM + 1);


    for (pool_index = 0; pool_index < MMI_AFM_SUB_POOL_NUM; pool_index++)
    {
        kal_wsprintf((WCHAR *)unicode_str,
            "%d %d %d %d\n",
            size[pool_index],
            total_num[pool_index],
            left_num[pool_index],
            min_left_num[pool_index]
            );
        mmi_mem_mon_print_string(canvas_p, (PU16)unicode_str);
    }
    for (i = 0; i < SCENARIO_NODE_END; i++)
    {
        kal_wsprintf((WCHAR *)unicode_str,
            "%w %d %d\n",
            scenario_obj[i],
            mmi_frm_scenario_get_dync_obj_info((U8)i, DYNAMIC_VALUE),
            mmi_frm_scenario_get_dync_obj_info((U8)i, PEAK_VALUE));
        mmi_mem_mon_print_string(canvas_p, (PU16)unicode_str);
    }

    kal_wsprintf((WCHAR *)unicode_str, 
                    "%w\n%d\n%w\n%d\n%w\n%d\n", 
                    L"GUI", 
                    mmi_frm_get_max_history_buffer_size(GUI_BUFFER),
                    L"INPUT",
                    mmi_frm_get_max_history_buffer_size(INPUT_BUFFER),
                    L"POST EVT",
                    mmi_frm_get_post_event_peak_num()
                    );
    mmi_mem_mon_print_string(canvas_p, (PU16)unicode_str);
    memset(unicode_str, 0, ENCODING_LENGTH);    /* reset buffer since its already printed */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mem_asm_info_cb
 * DESCRIPTION
 *  information string callback for ASM memory
 * PARAMETERS
 *  unicode_str     [IN]    string buffer
 *  str_len         [IN]    string buffer length
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mem_asm_info_cb(PU8 unicode_str, U32 str_len, mmi_mem_mon_canvas_type *canvas_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_asm_mem_detail_info_struct *mntr_app_asm_ptr = &(g_mmi_mem_mon_info_struct.mem_app_detail_info);
    applib_asm_mem_detail_info_struct *mntr_scr_asm_ptr = &(g_mmi_mem_mon_info_struct.mem_scr_detail_info);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_wsprintf((WCHAR *)unicode_str, 
                    "%w\n%d\n%d\n%d\n%d\n", 
                    L"APP", 
                    mntr_app_asm_ptr->current_caller_id,
                    mntr_app_asm_ptr->current_alloc_size,
                    mntr_app_asm_ptr->total_left_size,
                    mntr_app_asm_ptr->max_alloc_size);

    mmi_mem_mon_print_string(canvas_p, (PU16)unicode_str);

    kal_wsprintf((WCHAR *)unicode_str, 
                    "%w\n%d\n%d\n%d\n%d\n", 
                    L"SCR", 
                    mntr_scr_asm_ptr->current_caller_id,
                    mntr_scr_asm_ptr->current_alloc_size,
                    mntr_scr_asm_ptr->total_left_size,
                    mntr_scr_asm_ptr->max_alloc_size);

    mmi_mem_mon_print_string(canvas_p, (PU16)unicode_str);
    memset(unicode_str, 0, ENCODING_LENGTH);    /* reset buffer since its already printed */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mem_osl_info_cb
 * DESCRIPTION
 *  information string callback for OSL memory
 * PARAMETERS
 *  unicode_str     [IN]    string buffer
 *  str_len         [IN]    string buffer length
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mem_osl_info_cb(PU8 unicode_str, U32 str_len, mmi_mem_mon_canvas_type *canvas_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 pool_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (pool_index = 0; pool_index < RPS_CREATED_CTRL_BUFF_POOLS; pool_index++)
    {
        if(ctrl_buff_pool_info_g[pool_index].no_of_buff != 0)
        {
            kal_wsprintf((WCHAR *)unicode_str, 
                "%d %d %d\n", 
                ctrl_buff_pool_info_g[pool_index].size, 
                ctrl_buff_pool_info_g[pool_index].no_of_buff,
            #if defined(DEBUG_KAL) && (defined(DEBUG_BUF1) || defined(DEBUG_BUF2))
                ((kal_internal_poolid)ctrl_buff_pool_info_g[pool_index].pool_id)->pool_stat->pool_info.current_allocation
            #else
                -1
            #endif
                );
            //unicode_str += (mmi_wcslen((U16 *)unicode_str) * ENCODING_LENGTH);  /* update string pointer */
            mmi_mem_mon_print_string(canvas_p, (PU16)unicode_str);
    	}
    }
    memset(unicode_str, 0, ENCODING_LENGTH);    /* reset buffer since its already printed */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mem_mon_start_periodic_profiling
 * DESCRIPTION
 *  start periodic profiling with given interval
 * PARAMETERS
 *  interval_in_ms  [IN]    periodic interval in ms
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mem_mon_start_periodic_profiling(U32 interval_in_ms)
{
    mmi_mem_monitor_type_enum type = mmi_mem_mon_profiling_get_enable();
    
    if (MMI_EM_MEMORY_MONITOR_OFF != type)
    {
        mmi_mem_mon_profiling_memory_monitor(type, NULL);
        StartTimerEx(MMI_MEMORY_MONITOR_TIMER, interval_in_ms, (oslTimerFuncPtr)mmi_mem_mon_start_periodic_profiling, (void *)interval_in_ms);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mem_mon_profiling_memory_monitor
 * DESCRIPTION
 *  Display memory profiling information on screen
 * PARAMETERS
 *  mem_type        [IN]    memory type of monitor statistics
 *  canvas_p        [IN]    pointer to canvas which information shows on. Set NULL to use default canvas.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mem_mon_profiling_memory_monitor(mmi_mem_monitor_type_enum mem_type, mmi_mem_mon_canvas_type *canvas_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mem_mon_info_str_cb_type info_str_cb = NULL;
    U8 unicode_str[MMI_FRM_MEMMONT_OUTBUF_SIZE * ENCODING_LENGTH + ENCODING_LENGTH] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    info_str_cb = g_mmi_mem_mon_list[mem_type];
    if (info_str_cb != NULL)
    {
        if (NULL == canvas_p)
            canvas_p = &mem_mon_canvas; /* use default canvas if not assigned */
   
        /* reset offset in canvas */
        canvas_p->x_offset = canvas_p->y_offset = 0;

        /* get information string */
        info_str_cb(unicode_str, MMI_FRM_MEMMONT_OUTBUF_SIZE, canvas_p);

        /* print string to screen */
        mmi_mem_mon_print_string(canvas_p, (PU16)unicode_str);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mem_mon_construct_static_statistic
 * DESCRIPTION
 *  Construct static memory statistics
 * PARAMETERS
 *  unicode_buff        [OUT]    buffer to display statistic information
 *  buff_size           [IN]     buffer size
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mem_mon_construct_static_statistic(U16 *unicode_buff, U32 buff_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_asm_mem_detail_info_struct *mntr_app_asm_ptr = &(g_mmi_mem_mon_info_struct.mem_app_detail_info);
    applib_asm_mem_detail_info_struct *mntr_scr_asm_ptr = &(g_mmi_mem_mon_info_struct.mem_scr_detail_info);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf((WCHAR *)unicode_buff,
        "*app-asm*\n"
        "pool size:%d\nmax caller id:%d\nmax alloc size:%d\n"
        "*scr-asm*\n"
        "pool size:%d\nmax caller id:%d\nmax alloc size:%d\n",
        (*mntr_app_asm_ptr).pool_size, (*mntr_app_asm_ptr).maximal_caller_id, (*mntr_app_asm_ptr).maximal_allocated_size,
        (*mntr_scr_asm_ptr).pool_size, (*mntr_scr_asm_ptr).maximal_caller_id, (*mntr_scr_asm_ptr).maximal_allocated_size);
    /* Prevent string overflow */
    MMI_ASSERT((U32)mmi_wcslen((U16 *)unicode_buff) < buff_size);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mem_mon_update_detail_info
 * DESCRIPTION
 *  Update memory statistics by monitor type
 * PARAMETERS
 *  monitor_type    [IN]    memory monitor type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mem_mon_update_detail_info(mmi_frm_mem_type monitor_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_asm_mem_detail_info_struct *mntr_app_asm_ptr = &(g_mmi_mem_mon_info_struct.mem_app_detail_info);
    applib_asm_mem_detail_info_struct *mntr_scr_asm_ptr = &(g_mmi_mem_mon_info_struct.mem_scr_detail_info);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (monitor_type)
    {
        case MMI_FRM_MEM_APP_ASM:
        {
            applib_mem_asm_get_detail_info((void *)mntr_app_asm_ptr, MMI_FRM_MEM_APP_ASM);
            break;
        }
        case MMI_FRM_MEM_SCR_ASM:
        {
            applib_mem_asm_get_detail_info((void *)mntr_scr_asm_ptr, MMI_FRM_MEM_SCR_ASM);
            break;
        }
        case MMI_FRM_MEM_ASM:
        {
            applib_mem_asm_get_detail_info((void *)mntr_app_asm_ptr, MMI_FRM_MEM_APP_ASM);
            applib_mem_asm_get_detail_info((void *)mntr_scr_asm_ptr, MMI_FRM_MEM_SCR_ASM);
            break;
        }
        default:
        {
            MMI_ASSERT(MMI_FALSE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mem_mon_profiling_get_enable
 * DESCRIPTION
 *  Get the state of memory profiling from MMI NVRAM cache. 
 *  It will return MMI_TRUE if enable, else return MMI_FALSE.
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_mem_monitor_type_enum
 *****************************************************************************/
mmi_mem_monitor_type_enum mmi_mem_mon_profiling_get_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 enable_value;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(
        NVRAM_MEMORY_PROFILING_ENABLE,
        &enable_value,
        DS_BYTE,
        &error);

    if ((error != NVRAM_READ_SUCCESS) ||
        (enable_value == 0xff) ||           /* Old-style default value */
        ((mmi_mem_monitor_type_enum)enable_value >= MMI_EM_MEMORY_MONITOR_TOTAL))
    {
        return MMI_EM_MEMORY_MONITOR_OFF;
    }
    return (mmi_mem_monitor_type_enum)enable_value;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mem_mon_profiling_set_enable
 * DESCRIPTION
 *  Save the state of memory profiling to MMI NVRAM cache.
 * PARAMETERS
 *  mmi_mem_monitor_type_enum   [IN]    enable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mem_mon_profiling_set_enable(mmi_mem_monitor_type_enum enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 enable_value = (U8)enable;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValue(
        NVRAM_MEMORY_PROFILING_ENABLE,
        &enable_value,
        DS_BYTE,
        &error);

    MMI_ASSERT(error == NVRAM_WRITE_SUCCESS);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_mem_monitor_post_key_routing_cb
 * DESCRIPTION
 *  Post key event routing event call back
 * PARAMETERS
 *  evt        :[IN]    key event
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_mem_monitor_post_key_routing_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(key_evt->evt_id == EVT_ID_POST_KEY_EVT_ROUTING);
    if (key_evt->key_type== KEY_EVENT_UP)
    {
        mmi_mem_monitor_type_enum type = mmi_mem_mon_profiling_get_enable();
        if (MMI_EM_MEMORY_MONITOR_OFF != type)
        {
            mmi_mem_mon_profiling_memory_monitor(type, NULL);
        }
    }
    return MMI_RET_OK;
}

#endif /* __MMI_MEMORY_MONITOR__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_mem_mon_print_info
 * DESCRIPTION
 *  This memory is used print memory info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mem_mon_print_info(void)
{
#ifdef  __MMI_PRINT_AFM_INFO__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    U32 size[MMI_AFM_SUB_POOL_NUM + 1];
    U32 total_num[MMI_AFM_SUB_POOL_NUM + 1];
    U32 left_num[MMI_AFM_SUB_POOL_NUM + 1];
    U32 min_left_num[MMI_AFM_SUB_POOL_NUM + 1];
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    size[MMI_AFM_SUB_POOL_NUM] = AFM_SUBPOOL_END_PATTERN;
    total_num[MMI_AFM_SUB_POOL_NUM] = AFM_SUBPOOL_END_PATTERN;
    left_num[MMI_AFM_SUB_POOL_NUM] = AFM_SUBPOOL_END_PATTERN;
    min_left_num[MMI_AFM_SUB_POOL_NUM] = AFM_SUBPOOL_END_PATTERN;
    
    mmi_frm_fix_mem_get_info(size, total_num, left_num, min_left_num, MMI_AFM_SUB_POOL_NUM + 1);
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_MEM_FIX_SIZE_MEM_DUMP_START);
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_MEM_GUI_BUFFER_PEAK_VALUE, mmi_frm_get_max_history_buffer_size(GUI_BUFFER));
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_MEM_INPUT_BUFFER_PEAK_VALUE, mmi_frm_get_max_history_buffer_size(INPUT_BUFFER));
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_MEM_POST_EVT_PEAK_NUM, mmi_frm_get_post_event_peak_num());
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_MEM_FIX_MEM_INFO);
    for (i = 0; i < MMI_AFM_SUB_POOL_NUM; i++)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, 
            TRC_MMI_FRM_MEM_SUB_POOL_INFO, 
            size[i], 
            total_num[i], 
            left_num[i], 
            min_left_num[i]);
    }
    for (i = 0; i < SCENARIO_NODE_END; i++) 
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM,
            TRC_MMI_FRM_MEM_SCENARIO_OBJ_STAT,
            i,
            mmi_frm_scenario_get_dync_obj_info((U8)i, DYNAMIC_VALUE),
            mmi_frm_scenario_get_dync_obj_info((U8)i, PEAK_VALUE));
    }
#endif /*__MMI_PRINT_AFM_INFO__*/
}



