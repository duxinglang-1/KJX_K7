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
 *   jvm_cache.cpp
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   
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

/****************************************************************************
 * Include Header Files
 ****************************************************************************/
#include "kal_release.h"
#include "cache_hw.h"
#include "cache_sw.h"
#include "jvm_interface.h"
#include "cp15.h"
#include "cache_sw.h"

/****************************************************************************
 * Function Definition
 ****************************************************************************/
#define _DERIVED(type, ptr, offset) ((type) (((kal_int32) (ptr))+((kal_int32) (offset))))

#if defined(__MTK_TARGET__) && (defined(MT6228) || defined(MT6229) || defined(MT6230))
static kal_uint8 l1cache_channels, saved_inited_channels;
static kal_uint32 last_channel;
static unsigned char *low_end, *high_start;

extern kal_uint32 SaveAndSetIRQMask(void);
extern void RestoreIRQMask(kal_uint32);
extern kal_bool CodeCacheGetChannel(kal_uint16 *channel);
extern kal_bool CodeCacheFreeChannel(kal_uint16 *channel);
extern void CodeCacheSetting(CacheMenuType *cache_setting);
void jvm_flush_cache(unsigned char *start, int size);


/*****************************************************************************
 * FUNCTION
 *  _jvm_config_codecache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start       [?]         
 *  size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint16 _jvm_config_codecache(unsigned char *start, kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CacheMenuType cache_setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (last_channel < 8)
    {
        for (; last_channel < 8; last_channel++)
        {
            if ((l1cache_channels & (1 << last_channel)) != 0)
            {
                break;
            }
        }
        if (CodeCacheGetChannel((kal_uint16*) & last_channel) == KAL_TRUE)
        {
            break;
        }
    }

    if (last_channel == 8)
    {
        return 0xffff;
    }

    l1cache_channels &= ~(1 < last_channel);
    cache_setting.c_channel = last_channel;
    last_channel++;
    cache_setting.c_enable = 1;
    cache_setting.c_addr = (kal_uint32) start;
    cache_setting.c_range = size;
    CodeCacheSetting(&cache_setting);

    return (kal_uint16) (last_channel - 1);
}
#endif /* defined(__MTK_TARGET__) && (defined(MT6228) || defined(MT6229) || defined(MT6230)) */ 


/*****************************************************************************
 * FUNCTION
 *  jvm_init_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start       [?]     
 *  end         [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_init_cache(unsigned char *start, unsigned char *end)
{
#if defined(__MTK_TARGET__) && (defined(MT6228) || defined(MT6229) || defined(MT6230))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 space_size = end - start;
    kal_int32 cachealign_size = 1024;   /* minimum 1K aligned */
    kal_int32 cachealign_mask;
    kal_uint16 channel;
    kal_bool find_region;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    last_channel = saved_inited_channels = 0;

    /* if requesting size is less than minimum cache alignment, return */
    if (space_size < cachealign_size)
    {
        return;
    }
    
    /* error, can not support such large size */
    if(space_size > 8 * 1024 * 1024)
    {
        return;
    }

    if(space_size == 8 * 1024 * 1024)
    {
        channel = _jvm_config_codecache(start, 4 * 1024 * 1024);
        if (channel == 0xFFFF)
        {
            return;
        }
        else
        {
            saved_inited_channels |= (1 << channel);
        }
        channel = _jvm_config_codecache(start + 4 * 1024 * 1024, 4 * 1024 * 1024);
        if (channel != 0xFFFF)
        {
            saved_inited_channels |= (1 << channel);
        }
        return;
    }
    
    /* find largest align size */
    while (cachealign_size < space_size && cachealign_size <= 4 * 1024 * 1024)
    {
        cachealign_size <<= 1;
    }

    if (cachealign_size > 1024)
    {
        cachealign_size >>= 1;
    }

    /* if the start address is just aligned with 2 ^ n */
    if (((kal_int32) start % (cachealign_size << 1)) == 0)
    {
        cachealign_size <<= 1;
    }
    cachealign_mask = ~(cachealign_size - 1);

    while (((_DERIVED(kal_int32, start, cachealign_size - 1) & cachealign_mask) + cachealign_size) > (kal_int32) end)
    {
        if (cachealign_size > 1024)
        {
            cachealign_size >>= 1;
            cachealign_mask = ~(cachealign_size - 1);
        }
        else
        {
            return;
        }
    }

    low_end = (unsigned char*)(_DERIVED(kal_int32, start, cachealign_size - 1) & cachealign_mask);
    high_start = _DERIVED(kal_uint8 *, low_end, cachealign_size);
    channel = _jvm_config_codecache(low_end, cachealign_size);
    if (channel == 0xFFFF)
    {
        return;
    }

    saved_inited_channels |= (1 << channel);
    if (end == high_start && start == low_end)
    {
        return;
    }

    while (1)
    {
        find_region = KAL_FALSE;

        /* find low address suitable region */
        if (_DERIVED(kal_uint8 *, low_end, -cachealign_size) >= start)
        {
            low_end = _DERIVED(kal_uint8 *, low_end, -cachealign_size);
            channel = _jvm_config_codecache(low_end, cachealign_size);
            if (channel == 0xFFFF)
            {
                break;
            }
            saved_inited_channels |= (1 << channel);
            find_region = KAL_TRUE;
        }
        /* find upper address suitable region */
        if (_DERIVED(kal_uint8 *, high_start, cachealign_size) <= end)
        {
            channel = _jvm_config_codecache(high_start, cachealign_size);
            if (channel == 0xFFFF)
            {
                break;
            }

            saved_inited_channels |= (1 << channel);
            high_start = _DERIVED(kal_uint8 *, high_start, cachealign_size);
            find_region = KAL_TRUE;
        }

        if (end == high_start && start == low_end)
        {
            break;
        }

        if (find_region == KAL_FALSE)
        {
            cachealign_size >>= 1;
            if (cachealign_size < 1024)
            {
                break;
            }
        }
    }
#endif /* defined(__MTK_TARGET__) && (defined(MT6228) || defined(MT6229) || defined(MT6230)) */ 
}


/*****************************************************************************
 * FUNCTION
 *  jvm_release_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_release_cache(void)
{
#if defined(__MTK_TARGET__) && (defined(MT6228) || defined(MT6229) || defined(MT6230))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 channel;
    CacheMenuType cache_setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    low_end = high_start = NULL;

    if (saved_inited_channels != 0)
    {
        for (channel = 0; channel < 8; channel++)
        {
            if ((saved_inited_channels & (1 << channel)) != 0)
            {
                CodeCacheFreeChannel(&channel);
                /* disable L1 cache mapping */
                cache_setting.c_channel = channel;
                cache_setting.c_enable = 0;
                cache_setting.c_addr = (kal_uint32) 0;
                cache_setting.c_range = 2048;
                CodeCacheSetting(&cache_setting);
            }
        }

        saved_inited_channels = l1cache_channels = 0;
    }

    jvm_flush_cache((unsigned char*)0, 0);
#endif /* defined(__MTK_TARGET__) && (defined(MT6228) || defined(MT6229) || defined(MT6230)) */ 
}


/*****************************************************************************
 * FUNCTION
 *  jvm_flush_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start       [?]         
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_flush_cache(unsigned char *start, int size)
{
#if defined(__MTK_TARGET__) && (defined(MT6228) || defined(MT6229) || defined(MT6230))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* kal_uint32 interrupt_mask; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // It should be OK that not in critical section, and interrupt occur. 
    // The performance will be better.
    /* do not have to turn off interrupt. */
    /* interrupt_mask = SaveAndSetIRQMask(); */

    /* Invalidate and clean data cache */
    *L2C_CON = 0x80000070;
    DataCacheWaitCommandReady();
    /* RestoreIRQMask(interrupt_mask); */

    /* Drain Write Buffer */
    /* interrupt_mask = SaveAndSetIRQMask(); */
    *L2C_CON = 0x80000002;
    /* Wait for command finishing */
    DataCacheWaitCommandReady();

    // Invalide all L1 code cache
    // !!! - As spec describe, L1 cache is write-through, and shouldn't be invalided ideally.
    // However, JIT need to modify some fields such as compiled method header (klass, size, link),
    // and other unknown fields before calling flush write buffer here. 
    // Even you didn't read back modified value, cache line will be filled by closing data fields.
    // For example, OopDesc::initalize() 
    //           initialize(klass);
    //           _set_size(size);
    // will be compiled as
    //           str r0,[r4]
    //           ldr r0,[r4+4]   <-      fetch whole cache line, and data not consistent if previous write not yet flushed.
    //
    // It's lucky that JIT wouldn't readback modified value before flushing here, or we only apply L2 cache or big 
    // job to add more invalidation action before read.
    *CACHE_OP = 0x03;

    /* RestoreIRQMask(interrupt_mask); */
#endif /* defined(__MTK_TARGET__) && (defined(MT6228) || defined(MT6229) || defined(MT6230)) */ 

    (void)start;
    (void)size;
}
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
static unsigned char *pre_start;
static unsigned char *pre_end;
#endif
/*****************************************************************************
 * FUNCTION
 *  jvm_init_cache_for_hi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start       [?]     
 *  end         [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_init_cache_for_hi(unsigned char *start, unsigned char *end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)

    kal_uint32 *invalidPtr;
		kal_uint32 length = (end - start);
		
    pre_start = start;
    pre_end = end;
    invalidPtr = (kal_uint32*) ((kal_int32) start & (~0x1f));
    length >>= 5;

    if (start != (unsigned char *)invalidPtr)
    {
        length += 2;
    }
    else
    {
        length++;
    }		
    invalidate_icache((kal_uint32)invalidPtr, (length<<5));    
    clean_dcache((kal_uint32)invalidPtr, (length<<5));
    invalidate_dcache((kal_uint32)invalidPtr, (length<<5));
#endif

#if !DATACACHE_FBBR_ON

	jvm_init_cache(start, end);
#else /* !DATACACHE_FBBR_ON */ 
    (void)start;
    (void)end;
#endif /* !DATACACHE_FBBR_ON */
}


/*****************************************************************************
 * FUNCTION
 *  jvm_release_cache_for_hi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_release_cache_for_hi(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)

    kal_uint32 *invalidPtr;
    kal_uint32 length = (pre_end - pre_start);

    invalidPtr = (kal_uint32*) ((kal_int32) pre_start & (~0x1f));
    length >>= 5;

    if (pre_start != (unsigned char *)invalidPtr)
    {
        length += 2;
    }
    else
    {
        length++;
    }		
    invalidate_icache((kal_uint32)invalidPtr, (length<<5));   
    clean_dcache((kal_uint32)invalidPtr, (length<<5));
    invalidate_dcache((kal_uint32)invalidPtr, (length<<5));

 
#endif

#if !DATACACHE_FBBR_ON
	jvm_release_cache();
#endif /* !DATACACHE_FBBR_ON */
}

/*****************************************************************************
 * FUNCTION
 *  jvm_flush_cache_for_hi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start       [?]         
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jvm_flush_cache_for_hi(unsigned char *start, int size)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)

    kal_uint32 *invalidPtr;
		kal_uint32 length = size;
		
    invalidPtr = (kal_uint32*) ((kal_int32) start & (~0x1f));
    length >>= 5;

    if (start != (unsigned char *)invalidPtr)
    {
        length += 2;
    }
    else
    {
        length++;
    }		
    invalidate_icache((kal_uint32)invalidPtr, (length<<5));  
    clean_dcache((kal_uint32)invalidPtr, (length<<5));
    invalidate_dcache((kal_uint32)invalidPtr, (length<<5));
#endif
  
#if !DATACACHE_FBBR_ON
	jvm_flush_cache(start, size);
#else /* !DATACACHE_FBBR_ON */ 
    (void)start;
    (void)size;
#endif /* !DATACACHE_FBBR_ON */
}
