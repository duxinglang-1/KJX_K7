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
 *  vapp_launcher_def.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the launcher feature set.
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

#ifndef VAPP_LAUNCHER_DEF_H
#define VAPP_LAUNCHER_DEF_H

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER_FACTORY__)

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "custom_launcher_config.h" // VappLauncherTypeEnum


/*****************************************************************************
 * Enum
 *****************************************************************************/

/*
 * Launcher Source:
 */
typedef enum
{
    VAPP_LAUNCHER_SRC_NATIVE,

#if defined(__MMI_VUI_LAUNCHER_MRE__)
    VAPP_LAUNCHER_SRC_MRE,
#endif

    VAPP_LAUNCHER_SRC_TOTAL,
    VAPP_LAUNCHER_SRC_INVALID
} VappLauncherSrcEnum;


/*****************************************************************************
 * Configuration (Debug Only)
 *****************************************************************************/

/* Unit-test: enable catcher logging. */
//#define VAPP_LAUNCHER_UT_ENABLE_CATCHER_LOG

/* Unit-test: enable SWLA logging. We don't use __MAUI_SOFTWARE_LA__ to prevent
   from it is opened because other APP defines __MAUI_SOFTWARE_LA__. */
//#define VAPP_LAUNCHER_UT_ENABLE_SWLA_LOG


/*****************************************************************************
 * Config
 *****************************************************************************/

/*
 * Max heap size of the launcher.
 */
#if defined(__MMI_VUI_LAUNCHER_HEAP_USE_ASM__)
#define VAPP_LAUNCHER_HEAP_ASM_SIZE     (500 * 1024)
#else
#define VAPP_LAUNCHER_HEAP_ASM_SIZE     (0)
#endif


/*****************************************************************************
 * Macro
 *****************************************************************************/

/*
 * Catcher logging:
 *
 * Note: Only target compiler supports C99 __VA_ARGS__.
 */
#if defined(__MTK_TARGET__) && defined(VAPP_LAUNCHER_UT_ENABLE_CATCHER_LOG)
#define VAPP_LAUNCHER_LOG_EX(...) MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, __VA_ARGS__)
#define VAPP_LAUNCHER_LOG(_x)     VAPP_LAUNCHER_LOG_EX _x
#else
#define VAPP_LAUNCHER_LOG(_x)
#endif /* defined(__MTK_TARGET__) */

/*
 * SWLA logging:
 */
#if defined(__MTK_TARGET__) && defined(VAPP_LAUNCHER_UT_ENABLE_SWLA_LOG)
#define VAPP_LAUNCHER_SLA(_x)   SLA_CustomLogging _x
#else
#define VAPP_LAUNCHER_SLA(_x)
#endif


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* defined(__MMI_VUI_LAUNCHER_FACTORY__) */
#endif /* VAPP_LAUNCHER_DEF_H */

