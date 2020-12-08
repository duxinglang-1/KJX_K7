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
 *  vapp_app_widget_def.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the widget's feature set.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_APP_WIDGET_DEF_H
#define VAPP_APP_WIDGET_DEF_H

#include "MMI_features.h"

#if defined(__MMI_VUI_LAUNCHER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "FileMgrSrvGprot.h"    // SRV_FMGR_SYSTEM_DRV


/*****************************************************************************
 * Macro
 *****************************************************************************/

#if 0 //defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#define VAPP_APP_WIDGET_LOG(_x)
#endif /* defined(__MTK_TARGET__) */


/*****************************************************************************
 * Define
 *****************************************************************************/

/* Drive of the widget archive. */
#define VAPP_APP_WIDGET_ARCHIVE_DRIVE       SRV_FMGR_SYSTEM_DRV

/* Path of the widget archive. */
#define VAPP_APP_WIDGET_ARCHIVE_PATH        "@widget"

/* Filename of the widget's archive file. */
#define VAPP_APP_WIDGET_ARCHIVE_FILE        "index.wgt"

/* The criteria of the distance in pixels that the widget will capture the pen
   event and start the drag-and-drop (DnD) process if the user long-tags the
   widget within such a distance. */
#define VAPP_APP_WIDGET_DND_CRITERIA        (0)

/* Turn on the operator name widget or not. */
#define VAPP_APP_WIDGET_OPERATOR_NAME


/*****************************************************************************
 * Enum
 *****************************************************************************/

/*
 * Widget Source:
 */
typedef enum
{
    VAPP_APP_WIDGET_SRC_NATIVE,

    VAPP_APP_WIDGET_SRC_SHORTCUT,

    VAPP_APP_WIDGET_SRC_TOTAL,

    VAPP_APP_WIDGET_SRC_INVALID
} VappAppWidgetSrcEnum;

/*
 * Widget Type (for native widget):
 */
typedef enum
{
    VAPP_APP_WIDGET_TYPE_ANALOG_CLOCK,

    VAPP_APP_WIDGET_TYPE_DIGITAL_CLOCK,

#if defined(VAPP_APP_WIDGET_OPERATOR_NAME)
    VAPP_APP_WIDGET_TYPE_OPERATOR_NAME_COSMOS,
#endif

    VAPP_APP_WIDGET_TYPE_TOTAL,

    VAPP_APP_WIDGET_TYPE_INVALID
} VappAppWidgetTypeEnum;

#endif /* defined(__MMI_VUI_LAUNCHER__) */
#endif /* VAPP_APP_WIDGET_DEF_H */

