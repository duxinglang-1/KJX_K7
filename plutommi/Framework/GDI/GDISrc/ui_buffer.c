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
 *  ui_buffer.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
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
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_debug.h"

#include "vfx_sys_config.h"
#include "gdi_ui_buffer.h"
#include "gui_sse_ui_buffer.h"

#include "..\GDIInc\ui_buffer.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
/* 
 * internal macros 
 */
/* add additional 32 byte to overcome size = 0 will make the buffer */
#define UI_BUFFER_SIZE_ALIGN_32(x) (((((x) + 31) >> 5) << 5) + 32)
/* leave some padding between ui buffers for OOB checking */
#define UI_BUFFER_PADDING       256

#ifdef __MTK_TARGET__
    #define __ui_buffer_align(x) __align(x)
#else
    #define __ui_buffer_align(x) __declspec(align(x))
#endif
#define UI_BUFFER_FOOTER_OFFSET         ((kal_uint32)(&(((ui_buffer_struct*)0)->footer[0])))
#define UI_BUFFER_OFFSET(x)             ((&(((ui_buffer_struct*)0)->ui_buffer_element_##x)))

#define UI_BUFFER_GET_START_ADDR(id)    (g_ui_buffer + UI_BUFFER_OFFSET(id))
#define UI_BUFFER_GET_SIZE(x)           UI_BUFFER_SIZE_##x
#define UI_BUFFER_DECLARE(x)            kal_uint8 ui_buffer_element_##x[UI_BUFFER_SIZE_ALIGN_32(UI_BUFFER_SIZE_##x) + UI_BUFFER_PADDING];
#define UI_BUFFER_ALIGNER_BEGIN(x)      kal_uint8 header[x];
#define UI_BUFFER_ALIGNER_END(x)        kal_uint8 footer[x];

#define UI_BUFFER_ELEMENT(x)    {UI_BUFFER_ID_##x, UI_BUFFER_SIZE_##x, UI_BUFFER_OFFSET(x)},
#define UI_BUFFER_ELEMENT_END   {(ui_buffer_id_enum)0, 0, NULL}
#define UI_BUFFER_NUM           UI_BUFFER_ID_NUM


/***************************************************************************** 
 *
 * UI buffer SIZE declaraion   (MODIFIABLE)
 *
 *****************************************************************************/

/*
 * GDI
 */
#define UI_BUFFER_SIZE_GDI_MBL              (GDI_MAINLCD_BUFFER_SIZE)
#define UI_BUFFER_SIZE_GDI_SBL              ((GDI_LAYER_BUFFER_SIZE + 8 * 1024))

/*
 * VRT
 */
#if defined(__VENUS_UI_ENGINE__) && defined(__MED_IN_ASM__) && defined(__COSMOS_MMI__)
    #define UI_BUFFER_SIZE_VRT_CACHE        (VFX_SYS_MEM_VRT_CACHE_MAX_SIZE)
#else
    #define UI_BUFFER_SIZE_VRT_CACHE        0
#endif    

/*
 * SSE
 */
#if defined(__MMI_SCREEN_SWITCH_EFFECT__)
    #define UI_BUFFER_SIZE_GUI_SSE_BUF_B    (GUI_SCREEN_SWITCH_EFFECT_MAIN_LCD_BUFFER_SIZE)
    #define UI_BUFFER_SIZE_GUI_SSE_BUF_A    (GUI_SCREEN_SWITCH_EFFECT_MAIN_LCD_BUFFER_SIZE)
#else /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */
    #define UI_BUFFER_SIZE_GUI_SSE_BUF_B    0
    #define UI_BUFFER_SIZE_GUI_SSE_BUF_A    0
#endif /* defined(__MMI_SCREEN_SWITCH_EFFECT__) */


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
/*
 * UI BUFFER layout     (MODIFIABLE)
 *
 * NOTE: remember to update g_ui_buffer_table as well after modification
 */
typedef struct
{
    UI_BUFFER_ALIGNER_BEGIN(32) /* BEGIN */

    /* GDI */
    UI_BUFFER_DECLARE(GDI_MBL)
    UI_BUFFER_DECLARE(GDI_SBL)
#ifndef __MMI_REDUCED_UI_BUFFER__
    /* VRT cache */
    UI_BUFFER_DECLARE(VRT_CACHE)
    /* SSE */
    UI_BUFFER_DECLARE(GUI_SSE_BUF_B)
    UI_BUFFER_DECLARE(GUI_SSE_BUF_A)
#endif /* __MMI_REDUCED_UI_BUFFER__ */
    UI_BUFFER_ALIGNER_END(32)   /* END */
} ui_buffer_struct;
    
#define UI_BUFFER_SIZE sizeof(ui_buffer_struct)

/* ui buffer element table */
typedef struct
{
    ui_buffer_id_enum   id;
    kal_uint32          size;
    void *offset;
} ui_buffer_element_struct;

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
#ifdef __MTK_TARGET__
    #pragma arm section zidata = "DYNAMICCACHEABLEZI_NC"
#endif
/* ui buffer memory pool */
static __ui_buffer_align(32) kal_uint8 g_ui_buffer[UI_BUFFER_SIZE];
#ifdef __MTK_TARGET__
    #pragma arm section zidata
#endif 


/* 
 * ui buffer information table (MODIFIABLE)
 *
 * NOTE: the order should be kept the same as ui_buffer_struct layout
 */
static const ui_buffer_element_struct g_ui_buffer_table[UI_BUFFER_NUM + 1] =
{
    UI_BUFFER_ELEMENT(GDI_MBL)
    UI_BUFFER_ELEMENT(GDI_SBL)
#ifndef __MMI_REDUCED_UI_BUFFER__
    UI_BUFFER_ELEMENT(VRT_CACHE)
    UI_BUFFER_ELEMENT(GUI_SSE_BUF_B)
    UI_BUFFER_ELEMENT(GUI_SSE_BUF_A)  
#endif /* __MMI_REDUCED_UI_BUFFER__ */
    UI_BUFFER_ELEMENT_END
};

static kal_mutexid g_ui_buffer_mutex = 0;

static ui_buffer_callback_func_ptr g_ui_buffer_mode_cb_table[UI_BUFFER_NUM];

static ui_buffer_mode_enum g_ui_buffer_mode = UI_BUFFER_MODE_DEFAULT;

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Local Function
 *****************************************************************************/

 
/*****************************************************************************
 * FUNCTION
 *  ui_buffer_take_mutex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ui_buffer_take_mutex(void)
{       
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_ui_buffer_mutex)
    {
        // create mutex
        g_ui_buffer_mutex = kal_create_mutex("UIB_MUTEX");
    }

    if (!kal_query_systemInit())
    {
        kal_take_mutex(g_ui_buffer_mutex);
    }        
}


/*****************************************************************************
 * FUNCTION
 *  ui_buffer_give_mutex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ui_buffer_give_mutex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_ui_buffer_mutex);

    if (!kal_query_systemInit())
    {
        kal_give_mutex(g_ui_buffer_mutex);
    }        
}


/*****************************************************************************
 * FUNCTION
 *  ui_buffer_search_element
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id       [IN]
 * RETURNS
 *  
 *****************************************************************************/
static const ui_buffer_element_struct *ui_buffer_search_element(ui_buffer_id_enum id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < UI_BUFFER_NUM; i++)
    {
        if (g_ui_buffer_table[i].id == id)
        {
            return &g_ui_buffer_table[i];
        }
    }    

    return NULL;
}


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  ui_buffer_get_start_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id       [IN]
 * RETURNS
 *  
 *****************************************************************************/
void *ui_buffer_get_start_addr(ui_buffer_id_enum id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const ui_buffer_element_struct *entry;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry = ui_buffer_search_element(id);
    ASSERT(entry != NULL);

    return (void*)(g_ui_buffer + (kal_uint32)entry->offset);
}


/*****************************************************************************
 * FUNCTION
 *  ui_buffer_get_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id       [IN]
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 ui_buffer_get_size(ui_buffer_id_enum id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const ui_buffer_element_struct *entry;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry = ui_buffer_search_element(id);
    ASSERT(entry != NULL);

    return entry->size;
}


/*****************************************************************************
 * FUNCTION
 *  ui_buffer_get_block_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id       [IN]
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 ui_buffer_get_block_size(ui_buffer_id_enum id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ui_buffer_get_block_size_by_addr(ui_buffer_get_start_addr(id));
}


/*****************************************************************************
 * FUNCTION
 *  ui_buffer_get_block_size_by_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mem_p       [IN]
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 ui_buffer_get_block_size_by_addr(void *mem_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < UI_BUFFER_NUM; i++)
    {
        if ((void*)(g_ui_buffer + (kal_uint32)g_ui_buffer_table[i].offset) == mem_p)
        {
            kal_uint32 size = 0;
            
            if (i == UI_BUFFER_NUM - 1)
            {
                size = UI_BUFFER_FOOTER_OFFSET;
                size -= (kal_uint32)mem_p - (kal_uint32)g_ui_buffer;
            }
            else
            {
                size = (kal_uint32)(g_ui_buffer + (kal_uint32)g_ui_buffer_table[i + 1].offset) - (kal_uint32)mem_p;
            }

            return size;
        }
    }    

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  ui_buffer_get_id_by_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mem_p       [IN]
 * RETURNS
 *  
 *****************************************************************************/
ui_buffer_id_enum ui_buffer_get_id_by_addr(void *mem_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < UI_BUFFER_NUM; i++)
    {
        if ((void*)(g_ui_buffer + (kal_uint32)g_ui_buffer_table[i].offset) == mem_p)
        {
            return g_ui_buffer_table[i].id;
        }
    }    

    return UI_BUFFER_ID_INVALID;
}


/*****************************************************************************
 * FUNCTION
 *  ui_buffer_print_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ui_buffer_print_debug_info(void)
{
#if !defined(__MTK_TARGET__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < UI_BUFFER_NUM; i++)
    {
        kal_printf("[%d] %d %08X %d\n", i, g_ui_buffer_table[i].id, g_ui_buffer + (kal_uint32)g_ui_buffer_table[i].offset, g_ui_buffer_table[i].size);
    } 
#endif /* !defined(__MTK_TARGET__) */
}


/*****************************************************************************
 * FUNCTION
 *  ui_buffer_get_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
ui_buffer_mode_enum ui_buffer_get_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ui_buffer_mode_enum mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: need mutex?
    mode = g_ui_buffer_mode;
    
    return mode;
}


/*****************************************************************************
 * FUNCTION
 *  ui_buffer_set_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode       [IN]
 * RETURNS
 *  
 *****************************************************************************/
ui_buffer_mode_enum ui_buffer_set_mode(ui_buffer_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    ui_buffer_mode_enum old_mode;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ui_buffer_take_mutex();

    old_mode = g_ui_buffer_mode;

    for (i = 0; i < (kal_int32)UI_BUFFER_ID_NUM; i++)
    {
        if (g_ui_buffer_mode_cb_table[i])
        {
            g_ui_buffer_mode_cb_table[i](mode, old_mode, UI_BUFFER_MODE_FLAG_NONE);
        }
    }

    g_ui_buffer_mode = mode;

    ui_buffer_give_mutex();
        
    return old_mode;
}


/*****************************************************************************
 * FUNCTION
 *  ui_buffer_register_mode_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id             [IN]
 *  func_ptr       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void ui_buffer_register_mode_callback(ui_buffer_id_enum id, ui_buffer_callback_func_ptr func_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(id < UI_BUFFER_ID_NUM);
    
    ui_buffer_take_mutex();
    g_ui_buffer_mode_cb_table[(kal_int32)id] = func_ptr;
    ui_buffer_give_mutex();
}


