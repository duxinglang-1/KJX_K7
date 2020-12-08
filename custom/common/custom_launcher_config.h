/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *  custom_launcher_config.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file customizes the launcher.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef CUSTOM_LAUNCHER_CONFIG_H
#define CUSTOM_LAUNCHER_CONFIG_H

#include "MMI_features.h"


/*****************************************************************************
 * Registration
 *****************************************************************************/

/*
 * Launcher Type (for native launcher):
 *
 * VAPP_LAUNCHER_TYPE_TOTAL will be used to reserve resources precisely, e.g.,
 * memory or NVRAM. Remember to wrap your launcher with proper compile option if
 * it isn't always turned on.
 */
typedef enum
{
#if defined(__MMI_VUI_LAUNCHER_COSMOS__)
    VAPP_LAUNCHER_TYPE_COSMOS,
#endif

#if defined(__MMI_VUI_LAUNCHER_ROBOT__)
    VAPP_LAUNCHER_TYPE_ROBOT,
#endif

#if defined(__MMI_VUI_LAUNCHER_MM__)
    VAPP_LAUNCHER_TYPE_MM,
#endif

    VAPP_LAUNCHER_TYPE_TOTAL,
    VAPP_LAUNCHER_TYPE_INVALID
} VappLauncherTypeEnum;


/*****************************************************************************
 * Define
 *****************************************************************************/

/*
 * Max number of the native launchers.
 */
#define CUSTOM_LAUNCHER_NATIVE_MAX_NUM  (VAPP_LAUNCHER_TYPE_TOTAL)

/*
 * Max number of the downloadable MRE launchers.
 */
#if defined(__MMI_VUI_LAUNCHER_MRE__)
#define CUSTOM_LAUNCHER_MRE_MAX_NUM     (6)
#else
#define CUSTOM_LAUNCHER_MRE_MAX_NUM     (0)
#endif

/*
 * Max number of the launchers. Once this value is changed, remember to make
 * sure the reserve resource isn't too large. E.g., please check the NVRAM 
 * record size should not be larger than 2000 KB.
 */
#define CUSTOM_LAUNCHER_MAX_NUM \
    (CUSTOM_LAUNCHER_NATIVE_MAX_NUM + CUSTOM_LAUNCHER_MRE_MAX_NUM)

/*
 * Page number of the Cosmos launcher desktop.
 */
#define CUSTOM_LAUNCHER_COSMOS_PAGE_NUM (5)

/*
 * Page number of the robot launcher deskstop.
 */
#define CUSTOM_LAUNCHER_ROBOT_PAGE_NUM  (5)

#endif /* CUSTOM_LAUNCHER_CONFIG_H */

