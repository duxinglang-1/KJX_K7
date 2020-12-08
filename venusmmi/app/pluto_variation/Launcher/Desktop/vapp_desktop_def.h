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
 *  vapp_desktop_def.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_DESKTOP_DEF_H
#define VAPP_DESKTOP_DEF_H

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER__)

/*****************************************************************************
 * Inlcude
 *****************************************************************************/

#include "lcd_sw_inc.h"


/*****************************************************************************
 * Configuration (Debug Only)
 *****************************************************************************/

/* Unit-test: desktop tile. */
//#define VAPP_DESKTOP_UT_DESKTOP_TILE

/* Unit-test: desktop slide. */
//#define VAPP_DESKTOP_UT_DESKTOP_SLIDE

/* Unit-test: desktop auto-slide. */
//#define VAPP_DESKTOP_UT_DESKTOP_AUTO_SLIDE

/* Unit-test: control panel to set the page selector auto animation time. */
//#define VAPP_DESKTOP_UT_PAGE_SELECTOR_DEBUG_PANEL

/* Unit-test: enable catcher logging. */
//#define VAPP_DESKTOP_UT_ENABLE_CATCHER_LOG

/* Unit-test: enable SWLA logging. */
//#define VAPP_DESKTOP_UT_ENABLE_SWLA_LOG


/*****************************************************************************
 * Configuration
 *****************************************************************************/

/* Max. number of pages on the desktop. */
#define VAPP_DESKTOP_MAX_PAGE_NUM               (3)

/* Max. size of context memory which will be allocated from ASM. */
#define VAPP_DESKTOP_MAX_CNTX_MEM_SIZE          (300 * 1024)


/*****************************************************************************
 * Macro
 *****************************************************************************/

/*
 * Catcher logging:
 *
 * Note: Only target compiler supports C99 __VA_ARGS__.
 * Note: Pluto doesn't support to generate logs using resource files. Fix it.
 */
#if defined(__MTK_TARGET__) && defined(VAPP_DESKTOP_UT_ENABLE_CATCHER_LOG)
#define VAPP_DESKTOP_LOG_EX(...) MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, __VA_ARGS__)
#define VAPP_DESKTOP_LOG(_x)     VAPP_DESKTOP_LOG_EX _x
#else
#define VAPP_DESKTOP_LOG(_x)
#endif /* defined(__MTK_TARGET__) */

/*
 * SWLA logging:
 */
#if defined(__MTK_TARGET__) && defined(VAPP_DESKTOP_UT_ENABLE_SWLA_LOG)
#define VAPP_DESKTOP_SLA(_x)    SLA_CustomLogging _x
#else
#define VAPP_DESKTOP_SLA(_x)
#endif

#endif /* defined(__MMI_VUI_LAUNCHER__) */
#endif /* VAPP_DESKTOP_DEF_H */

