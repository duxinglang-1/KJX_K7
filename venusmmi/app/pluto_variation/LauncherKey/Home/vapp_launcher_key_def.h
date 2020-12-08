/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  vapp_launcher_key_def.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the internal compile options, constants, and etc.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_KEYLAUNCHER_DEF_H
#define VAPP_KEYLAUNCHER_DEF_H

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER_KEY__)

/*****************************************************************************
 * Inlcude
 *****************************************************************************/

#include "lcd_sw_inc.h"
#include "IdleMemCfg.h"



/*****************************************************************************
 * Configuration (Debug Only)
 *****************************************************************************/

/* Unit-test: enable catcher logging. */
#define VAPP_KEYLAUNCHER_UT_ENABLE_CATCHER_LOG

/* Unit-test: enable SWLA logging. */
#define VAPP_KEYLAUNCHER_UT_ENABLE_SWLA_LOG


/*****************************************************************************
 * Configuration
 *****************************************************************************/

/* Max. size of context memory which will be allocated from ASM2.0. 
 * It must be smaller than IdleMemCfg.h KEY_LAUNCHER_ASM_FG_SIZE
 * if need modify this define, also remerber to modify that value */
#define VAPP_KEYLAUNCHER_MAX_CNTX_MEM_SIZE          (KEY_LAUNCHER_HOME_ASM_FG_SIZE)


/* Max. number of pages on the key launcher. */
#define VAPP_KEYLAUNCHER_MAX_PAGE_NUM               (1)


/*****************************************************************************
 * Macro
 *****************************************************************************/

/*
 * Catcher logging:
 *
 * Note: Only target compiler supports C99 __VA_ARGS__.
 * Note: Pluto doesn't support to generate logs using resource files. Fix it.
 */
#if /*defined(__MTK_TARGET__) && */defined(VAPP_KEYLAUNCHER_UT_ENABLE_CATCHER_LOG)
#define VAPP_KEYLAUNCHER_LOG_EX(...) MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, __VA_ARGS__)
#define VAPP_KEYLAUNCHER_LOG(_x)     VAPP_KEYLAUNCHER_LOG_EX _x
#else
#define VAPP_KEYLAUNCHER_LOG(_x)
#endif /* defined(__MTK_TARGET__) */

/*
 * SWLA logging:
 */
#if defined(__MTK_TARGET__) && defined(VAPP_KEYLAUNCHER_UT_ENABLE_SWLA_LOG)
#define VAPP_KEYLAUNCHER_SLA(_x)    SLA_CustomLogging _x
#else
#define VAPP_KEYLAUNCHER_SLA(_x)
#endif

#endif /* defined(__MMI_VUI_LAUNCHER_KEY__) */
#endif /* VAPP_KEYLAUNCHER_DEF_H */


