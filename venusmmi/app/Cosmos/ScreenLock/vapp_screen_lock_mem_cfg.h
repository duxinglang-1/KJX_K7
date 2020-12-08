
#ifndef _VAPP_SCREEN_LOCK_MEM_CFG_H_
#define _VAPP_SCREEN_LOCK_MEM_CFG_H_

#include "MMI_features.h"
#include "gdi_include.h"

//
//this file is config for vrt factor because that
//vrt reduce cache buffer to 1 screen size on 6464 cosmos slim version, 
//so app needs to increase vrt cache factor, vrt will use this extra buffer to cache.
//
#if defined(__LOW_COST_SUPPORT_COMMON__)
    #if defined(__MMI_REDUCED_UI_BUFFER__)
        #define VAPP_SCREEN_LOCK_EXTRA_CACHE_MEM_FACTOR    (1)
        #define VAPP_SCREEN_LOCK_EXTRA_CACHE_MEM_FACTOR_LIMIT    (0.6f)
    #else
        #define VAPP_SCREEN_LOCK_EXTRA_CACHE_MEM_FACTOR    (0)
        #define VAPP_SCREEN_LOCK_EXTRA_CACHE_MEM_FACTOR_LIMIT      (0)
    #endif
#else
    #define VAPP_SCREEN_LOCK_EXTRA_CACHE_MEM_FACTOR        (0)
    #define VAPP_SCREEN_LOCK_EXTRA_CACHE_MEM_FACTOR_LIMIT      (0)
#endif /* defined(__LOW_COST_SUPPORT_COMMON__) */

#define VAPP_SCREEN_LOCK_VRT_CACHE_LIMIT (VAPP_SCREEN_LOCK_EXTRA_CACHE_MEM_FACTOR_LIMIT*LCD_WIDTH*LCD_HEIGHT*2)
#define VAPP_SCREEN_LOCK_FG_MEM (VAPP_SCREEN_LOCK_EXTRA_CACHE_MEM_FACTOR*LCD_WIDTH*LCD_HEIGHT*2)

#endif /* _VAPP_SCREEN_LOCK_MEM_CFG_H_ */

