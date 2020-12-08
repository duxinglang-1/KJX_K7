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
 *  gdi.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "gdi_internal.h"
#include "kal_general_types.h"
#include "kal_release.h"
#include "string.h"
#include "MMIDataType.h"

#include "gdi_include.h"
#include "gdi_mutex.h"
#include "gdi_lfs.h"
#include "gdi_lcd.h"
#include "gdi_layer.h"
#include "gdi_2d_engine.h"
#include "gdi_image.h"
#include "gdi_animate.h"
#include "gdi_image_gif.h"
#include "gdi_image_jpeg.h"
#include "gdi_image_alpha_bmp.h"
#include "gdi_image_alpha_bmp_v2.h"
#include "gdi_imgdec_internal.h"
#include "gdi_datatype.h"
#include "gdi_primitive.h"
#include "med_utility.h"
#include "rgb_rotator_api.h"


/*****************************************************************************
 * FUNCTION
 *  gdi_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 GDI_DEBUG_FLAG;
U32 GDI_DEBUG_CNT;
U8 GDI_DEBUG_ARG[32];

kal_eventgrpid gdi_event_group;
extern KAL_ADM_ID gdi_layer_buffer_pool_id;


#define GDI_MEM_CACHELINE_SIZE 32

#define GDI_MEM_MAX_EXT_ALLOCATOR_NUM 2

typedef struct
{
    gdi_mem_allocate_func alloc;
    gdi_mem_free_func free;
    kal_uint32 min_addr, max_addr;
} gdi_mem_allocator_struct;

static struct
{
    volatile kal_int32 num;
    gdi_mutex_struct mutex;
    gdi_mem_allocator_struct allocator[GDI_MEM_MAX_EXT_ALLOCATOR_NUM];
} gdi_mem_external;


#if defined(GDI_USING_ASM)

/* ASM API */
#include "app_mem_med.h"

/*****************************************************************************
 * FUNCTION
 *  gdi_ext_smalloc_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static void* gdi_alloc_ext_mem_ext_internal(kal_int32 size, unsigned short location)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (size == 0)
    {
        return NULL;
    }

    if (location == GDI_EXT_MEMORY_TYPE_CACHEABLE)
    {
        ptr = applib_asm_alloc_anonymous((kal_uint32)size);
    }
    else if (location == GDI_EXT_MEMORY_TYPE_FRAMEBUFFER)
    {
        /* FRAMEBUFFER means "address and size must be 32byte alignment" and "have to be non-cacheable"*/
        /* Currently ASM will always return 32byte alignment address */
        if (size%32!=0)
        {
            size = (size+31)/32*32;
        }
        ptr = applib_asm_alloc_anonymous_nc((kal_uint32)size);
    }
    else
    {
        ptr = applib_asm_alloc_anonymous_nc((kal_uint32)size);
    }

    return (void*) ptr;
}   /* malloc */





/*****************************************************************************
 * FUNCTION
 *  gdi_ext_sfree
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_free_ext_mem_ext_internal(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (ptr!=NULL)
    {
        applib_asm_free_anonymous(ptr);
    }
}
#endif


static void gdi_mem_init(void)
{
    gdi_mem_external.num = 0;
    gdi_mutex_init(&gdi_mem_external.mutex);
}


static void gdi_mem_ext_update_addr_range(gdi_mem_allocator_struct *allocator, void *addr)
{
    /* To remove the address tag bits of cacheable */
    kal_uint32 addr_val = ((kal_uint32)addr << 4 >> 4);

    if (allocator->min_addr == 0)
    {
        allocator->min_addr = allocator->max_addr = addr_val;
    }
    else
    {
        if (addr_val < allocator->min_addr)
            allocator->min_addr = addr_val;
        else if (addr_val > allocator->max_addr)
            allocator->max_addr = addr_val;
    }
}


static kal_bool gdi_mem_ext_addr_in_range(gdi_mem_allocator_struct *allocator, void *addr)
{
    kal_uint32 addr_val = ((kal_uint32)addr << 4 >> 4);

    return (allocator->min_addr <= addr_val && addr_val <= allocator->max_addr);
}


GDI_RESULT gdi_mem_reg_ext_allocator(gdi_mem_allocate_func alloc, gdi_mem_free_func free)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT ret = GDI_FAILED;
    kal_bool found;
    kal_int32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_mutex_lock(&gdi_mem_external.mutex);

    found = KAL_FALSE;
    for (i = gdi_mem_external.num - 1; i >= 0; i--)
    {
        if (gdi_mem_external.allocator[i].alloc == alloc &&
            gdi_mem_external.allocator[i].free == free)
        {
            found = KAL_TRUE;
            break;
        }
    }

    if (found)
    {
        ret = GDI_SUCCEED;
    }
    else if (gdi_mem_external.num < GDI_MEM_MAX_EXT_ALLOCATOR_NUM)
    {
        kal_int32 slot_index = gdi_mem_external.num;
        gdi_mem_allocator_struct *allocator = &gdi_mem_external.allocator[slot_index];
        allocator->alloc = alloc;
        allocator->free = free;
        allocator->min_addr = allocator->max_addr = 0;
        
        gdi_mem_external.num++;
        
        ret = GDI_SUCCEED;
    }
    
    gdi_mutex_unlock(&gdi_mem_external.mutex);

    return ret;
}


GDI_RESULT gdi_mem_dereg_ext_allocator(gdi_mem_allocate_func alloc, gdi_mem_free_func free)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_mutex_lock(&gdi_mem_external.mutex);

    for (i = gdi_mem_external.num - 1; i >= 0; i--)
    {
        if (gdi_mem_external.allocator[i].alloc == alloc &&
            gdi_mem_external.allocator[i].free == free)
        {
            for (j = i + 1; j < gdi_mem_external.num; j++)
            {
                gdi_mem_external.allocator[j - 1] = gdi_mem_external.allocator[j];
            }

            gdi_mem_external.num--;
            
            break;
        }
    }
    
    gdi_mutex_unlock(&gdi_mem_external.mutex);

    return GDI_SUCCEED;
}


static void* gdi_mem_alloc_from_external(kal_uint32 size, gdi_memory_type_enum int_mem_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_mem_type_enum mem_type = GDI_MEM_TYPE_FRAMEBUFFER;
    kal_int32 i;
    void *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (int_mem_type)
    {
        case GDI_EXT_MEMORY_TYPE_NONCACHEABLE:
        case GDI_EXT_MEMORY_TYPE_FRAMEBUFFER:
            mem_type = GDI_MEM_TYPE_FRAMEBUFFER;
            break;

        case GDI_EXT_MEMORY_TYPE_CACHEABLE:
            mem_type = GDI_MEM_TYPE_CACHEABLE;
            break;

        default:
            GDI_ASSERT(0);
            break;
    }

    p = NULL;

    gdi_mutex_lock(&gdi_mem_external.mutex);
    
    for (i = gdi_mem_external.num - 1; i >= 0; i--)
    {
        p = gdi_mem_external.allocator[i].alloc(size, mem_type, GDI_MEM_CACHELINE_SIZE);
        if (p != NULL)
        {
            gdi_mem_ext_update_addr_range(&gdi_mem_external.allocator[i], p);
            break;
        }
    }
    
    gdi_mutex_unlock(&gdi_mem_external.mutex);

    return p;
}


static kal_bool gdi_mem_free_to_ext_allocator(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    kal_bool freed;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_mutex_lock(&gdi_mem_external.mutex);

    freed = KAL_FALSE;
    for (i = gdi_mem_external.num - 1; i >= 0; i--)
    {
        if (gdi_mem_ext_addr_in_range(&gdi_mem_external.allocator[i], p))
        {
            /* Free function will check the address again, return KAL_TRUE
               only if the address belongs to the pool and really freed */
            if (gdi_mem_external.allocator[i].free(p))
            {
                freed = KAL_TRUE;
                break;
            }
        }
    }
    
    gdi_mutex_unlock(&gdi_mem_external.mutex);

    return freed;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_alloc_ext_mem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *gdi_alloc_ext_mem_ext(kal_int32 size, kal_uint8 location
     #ifndef GDI_SLIM_SUPPORT
         , char* file_p, long line_p
     #endif
     )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_PRINT(MOD_GDI, GDI_TRC_MEM,
        "[GDI][ALLOC] size=%d, from: %s, %d", //GDI_MEM_ALLOC_START
        size, file_p,line_p);
    /* gdi decode memory can from ASM or MED. Now only Cosmos 
     * project will use memory from ASM. Others all from MED.
     */
    {
       /* If GDI decode memory is from MED, we can not use med_alloc_xxx
        * in bootup procedure. But in boot up period, we need to show bootup
        * logo. 
        * Since bootup period only have one layer: main base layer, So we 
        * use a tricky way to get memory from gdi_layer_buffer_pool. 
       */
        kal_bool is_system_init = KAL_FALSE;
        is_system_init = kal_query_systemInit();
        if (is_system_init)
        {
            p = MMI_FRM_ADM_ALLOC_FRAMEBUFFER(gdi_layer_buffer_pool_id, size);
        }
        else
        {
        #if defined(GDI_USING_ASM)
            p = gdi_alloc_ext_mem_ext_internal(size, location);
        #else
            switch(location)
            {
                case GDI_EXT_MEMORY_TYPE_NONCACHEABLE:
                    p = med_alloc_ext_mem_topmost_noncacheable(size);
                    break;

                case GDI_EXT_MEMORY_TYPE_CACHEABLE:
                    p = med_alloc_ext_mem_topmost_cacheable(size);
                    break;
    
                case GDI_EXT_MEMORY_TYPE_FRAMEBUFFER:
                    p = med_alloc_ext_mem_framebuffer(size);
                    break;

                default:
                   GDI_ASSERT(0); 
            }
        #endif

            if (p == NULL && gdi_mem_external.num > 0)
            {
                p = gdi_mem_alloc_from_external(size, (gdi_memory_type_enum)location);
            }
        }
    }
    GDI_TRACE(GDI_TRC_MEM, GDI_MEM_ALLOC_END,//"[GDI][ALLOC] ptr=%x"
        p);
    
    if ((size != 0) && (p == NULL))
    {
        GDI_TRACE(GDI_TRC_MEM, GDI_MEM_ALLOC_FAIL//"[GDI][ALLOC] alloc fail"
        );
    }

    return p;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_free_ext_mem_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pointer     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_free_ext_mem_ext(void **pointer
     #ifndef GDI_SLIM_SUPPORT
         ,char* file_p, long line_p
     #endif
     )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_PRINT(MOD_GDI, GDI_TRC_MEM, "[GDI][FREE]  ptr=%x, from: %s, %d", //GDI_MEM_FREE
        *pointer, file_p,line_p);
    {
        kal_bool is_system_init = KAL_FALSE;
        is_system_init = kal_query_systemInit();
        if (is_system_init)
        {
            kal_adm_free(gdi_layer_buffer_pool_id, (void*)*pointer);
        }
        else
        {
            if (gdi_mem_external.num > 0 &&
                gdi_mem_free_to_ext_allocator(*pointer))
            {
                /* OK, do nothing */
            }
            else
            {
            #if defined(GDI_USING_ASM)
                gdi_free_ext_mem_ext_internal((void*)*pointer);
            #else
                med_free_ext_mem(pointer);
            #endif
            }
        }
    }
    *pointer = NULL;
}


void gdi_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static BOOL is_init = FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_init)
    if(!is_init)
    {
        /* set flag to true avoid re-init */
        is_init = TRUE;

        if (gdi_event_group == NULL)
        {
            gdi_event_group = kal_create_event_group("gdi_event_group");
        }

        GDI_DEBUG_FLAG = 0;
        gdi_mem_init();
        
        /* init global lfs object */
        gdi_lfs_initialize();
        
        /* init lcd */
        gdi_lcd_init();

        /* init layer */
        gdi_layer_init();

        /* init 2D engine */
  
        gdi_2d_engine_init();
    
        rgbRotatorInit();

        /* init image */
        gdi_image_init();

        /* init animation */
        gdi_anim_init();

        gdi_image_abm_init();
        gdi_image_ab2_init();

    #if defined(WIN32)
    #if defined(GDI_USING_W32_JPEG) || defined(GDI_USING_W32_PNG)
        w32_image_init();
    #endif 
    #endif /* defined(WIN32) */ 

        /* init IMGDEC */
        gdi_imgdec_init();

    #if defined(GDI_USING_HW_JPEG_V2)
        gdi_image_jpeg_v2_init();
    #endif

    #if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)
        gdi_image_mav_init();
    #endif
        
        /* set Main LCD and base layer active */
        gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
        
        /* set the default ABM source layer to the main LCD base layer */
        gdi_set_alpha_blending_source_layer(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_init)
}


void gdi_debug_handler(S32 index,U8* string)
{
    strncpy((char*)GDI_DEBUG_ARG,(char*)string,sizeof(GDI_DEBUG_ARG));
    GDI_DEBUG_FLAG = index;
    GDI_DEBUG_CNT  = 0;
}


