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
 *  vapp_platform_context_cfg.h
 *
 * Project:
 * --------
 *  Venus Platform
 *
 * Description:
 * ------------
 *  Venus Platform Context, used by platform applications: 
 *    Home, Mainmenu, Lock, NCenter, Call
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_PLATFORM_CONTEXT_CFG_H__
#define __VAPP_PLATFORM_CONTEXT_CFG_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"

/***************************************************************************** 
 * Setting
 *****************************************************************************/

#if defined(__MMI_USE_MMV2__) && !defined(OPERA_BROWSER)
#define __VAPP_PLATFORM_CONTEXT_USE_MMV2__
#endif

/***************************************************************************** 
 * Macro
 *****************************************************************************/

/***************************************************************************** 
 * TOTAL
 *****************************************************************************/
#if defined(__MMI_VUI_PLATFORM_CONTEXT_SLIM__)
//
//Screen lock base size
//
#if defined(__MMI_VUI_SCREEN_LOCK_COSMOS__)
#define VAPP_SCREEN_LOCK_BASE_SIZE    (70*1024)
#elif defined(__MMI_VUI_SCREEN_LOCK_PATTERN__)
#define VAPP_SCREEN_LOCK_BASE_SIZE    (28*1024)
#elif defined(__MMI_VUI_SCREEN_LOCK_RHYTHM__)
#define VAPP_SCREEN_LOCK_BASE_SIZE    (10*1024)
#else /* __MMI_VUI_SCREEN_LOCK_PAINTING */
#define VAPP_SCREEN_LOCK_BASE_SIZE    (7*1024)
#endif

//
//Oom screen need memory size about 18k.
//
#define VAPP_OOM_SCREEN_BASE_SIZE    (18*1024)  

//
//launcher base size = VfxApp + VfxMainScr + VfxPage..etc + wallpaper nvram lid size + widget setting data
//                               = 4k + 1100 + 15 * (30 + 10) ¡Ö 6k
//
#define VAPP_LAUNCHER_BASE_SIZE       (6*1024)

#ifndef MAX
#define MAX(a, b)   ((a) > (b) ? (a) : (b))
#endif

#define VAPP_PLATFORM_CONTEXT_SLIM_TOTAL (VAPP_LAUNCHER_BASE_SIZE + MAX(VAPP_SCREEN_LOCK_BASE_SIZE, VAPP_OOM_SCREEN_BASE_SIZE))
#endif /* __MMI_VUI_PLATFORM_CONTEXT_SLIM__ */

#if defined(LOW_COST_SUPPORT)
#if defined(__MMI_VUI_LAUNCHER_HEAP_USE_ASM__)
#if defined(__MMI_VUI_PLATFORM_CONTEXT_SLIM__)
#define VAPP_PLATFORM_CONTEXT_BASE  (VAPP_PLATFORM_CONTEXT_SLIM_TOTAL)
#define VAPP_PLATFORM_CONTEXT_FG    (0)
#else
#define VAPP_PLATFORM_CONTEXT_BASE  (120*1024)
#define VAPP_PLATFORM_CONTEXT_FG    (100*1024)
#endif /* __MMI_VUI_PLATFORM_CONTEXT_SLIM__ */
#else
#define VAPP_PLATFORM_CONTEXT_BASE  (300*1024)
#define VAPP_PLATFORM_CONTEXT_FG    (250*1024)
#endif /* define(__MMI_VUI_LAUNCHER_HEAP_USE_ASM__) */
#else /* defined(LOW_COST_SUPPORT) */
#define VAPP_PLATFORM_CONTEXT_BASE  (1000*1024)
#define VAPP_PLATFORM_CONTEXT_FG    (224*1024)
#endif
#define VAPP_PLATFORM_CONTEXT_TOTAL (VAPP_PLATFORM_CONTEXT_BASE+VAPP_PLATFORM_CONTEXT_FG)



#endif /* __VAPP_PLATFORM_CONTEXT_CFG_H__ */

