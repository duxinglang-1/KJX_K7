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
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_launcher_mem_cfg.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file used to config vrt cache factor
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _VAPP_LAUNCHER_MEM_CFG_H_
#define _VAPP_LAUNCHER_MEM_CFG_H_

#include "MMI_features.h"
#include "gdi_include.h"

/*
this file is config for vrt factor because that
vrt reduce global memory from 18M to 12M, but it is not enough memory to provide GPU resource,
so app needs to increase vrt cache factor, vrt will use this extra buffer to provide memory to GPU resource

if need, please add your config as below.

Note:  VRT_MEM_FACTOR must be Integer not Float.

EX.

#ifdef __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER__

    #define EXTRA_CACHE_MEM_FACTOR_WITH_IG  22

    #if (VAPP_LAUNCHER_EXTRA_CACHE_MEM_FACTOR < EXTRA_CACHE_MEM_FACTOR_WITH_IG)
    #undef VAPP_LAUNCHER_EXTRA_CACHE_MEM_FACTOR
    #define VAPP_LAUNCHER_EXTRA_CACHE_MEM_FACTOR EXTRA_CACHE_MEM_FACTOR_WITH_IG
    #endif

#endif

*/

#if defined(__LOW_COST_SUPPORT_COMMON__)
    #if defined(__COSMOS_SLIM_ASM3X_PROFILE__)
        #define VAPP_LAUNCHER_EXTRA_CACHE_MEM_FACTOR    (4)
    #else
        #define VAPP_LAUNCHER_EXTRA_CACHE_MEM_FACTOR    (3)
    #endif
#else
    #define VAPP_LAUNCHER_EXTRA_CACHE_MEM_FACTOR        (10)
#endif /* defined(__LOW_COST_SUPPORT_COMMON__) */

#define VAPP_LAUNCHER_VRT_CACHE_LIMIT (VAPP_LAUNCHER_EXTRA_CACHE_MEM_FACTOR*LCD_WIDTH*LCD_HEIGHT*2)
#define VAPP_LAUNCHER_FG_MEM VAPP_LAUNCHER_VRT_CACHE_LIMIT

/* You can not add your configuration above. */

#if defined(__VENUS_3D_UI_ENGINE__)

    #if defined(__MMI_MAINLCD_480X800__)
        #define EXTRA_CACHE_MEM_FACTOR_WITH_IG  30
    #elif defined(__MMI_MAINLCD_320X480__)
        #define EXTRA_CACHE_MEM_FACTOR_WITH_IG  40
    #else
        #define EXTRA_CACHE_MEM_FACTOR_WITH_IG  45
    #endif

    #if (VAPP_LAUNCHER_EXTRA_CACHE_MEM_FACTOR < EXTRA_CACHE_MEM_FACTOR_WITH_IG)
    #undef VAPP_LAUNCHER_EXTRA_CACHE_MEM_FACTOR
    #define VAPP_LAUNCHER_EXTRA_CACHE_MEM_FACTOR EXTRA_CACHE_MEM_FACTOR_WITH_IG
    #endif

    #define EXTRA_FG_MEM_WITH_IG (EXTRA_CACHE_MEM_FACTOR_WITH_IG*LCD_WIDTH*LCD_HEIGHT*2)
    #if (VAPP_LAUNCHER_FG_MEM < EXTRA_FG_MEM_WITH_IG)
    #undef VAPP_LAUNCHER_FG_MEM
    #define VAPP_LAUNCHER_FG_MEM EXTRA_FG_MEM_WITH_IG
    #endif
#endif

#endif /* _VAPP_LAUNCHER_MEM_CFG_H_ */

