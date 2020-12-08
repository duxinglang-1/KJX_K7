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
 *
 * Filename:
 * ---------
 * CatScreenBrowserResDef.h
 *
 * Description:
 * ------------
 *    
 * (definition of data types)
 *
 * Author:
 *  Zhao Nan
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _CSB_BROWSER_RES_DEF_H
#define _CSB_BROWSER_RES_DEF_H
#include "MMI_features.h"

#ifdef __MMI_CSB_BROWSER__

/* Enum for UI Controls */
typedef enum
{
    CSB_CONT_CALL_SCR = 0,
    CSB_CONT_COLOR_PICKER_SCR,
    CSB_CONT_EDITOR_SCR,
    CSB_CONT_IDLE_SCR,
    CSB_CONT_IMAGE_VIEWER_SCR,
    CSB_CONT_LIST_MENU_SCR,
    CSB_CONT_MATRIX_MENU_SCR,
    CSB_CONT_POPUP_SCR,
    CSB_CONT_PROGRESS_BAR_SCR,
    CSB_CONT_SLIDER_SCR,
    CSB_CONT_RADIO_BUTTON_SCR,
    CSB_CONT_CHECK_BOX_SCR,
    CSB_CONT_SUB_LCD,
    CSB_CONT_PANEL,//052907 CSB
    CSB_TOTAL_CONTROLS
} csb_control_enum;

/* Enum for Applications */
typedef enum
{
    CSB_APP_CALLS = 0,
    CSB_APP_EDITOR,
    CSB_APP_ENGG_MODE,
    CSB_APP_EXTRA,
    CSB_APP_FUN_AND_GAMES,
    CSB_APP_FILE_MANAGER,
    CSB_APP_MESSAGES,
    CSB_APP_MISC,
    CSB_APP_MULTIMEDIA,
    CSB_APP_ORGANIZER,
    CSB_APP_PHONEBOOK,
    CSB_APP_PROFILE,
    CSB_APP_SERVICES,
    CSB_APP_SHORTCUT,
    CSB_APP_SETTINGS,
    CSB_APP_WAP,
    CSB_APP_HID,//052907 CSB
    CSB_TOTAL_APP
} csb_app_enum;
#endif /* __MMI_CSB_BROWSER__ */ 

#endif /* _CSB_BROWSER_RES_DEF_H */ 


