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
 *  vcp_popup_data_type.h
 *
 * Project:
 * --------
 *  Venus UI Component
 *
 * Description:
 * ------------
 *  Popup Component header
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
 * removed!
 * removed!
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VCP_POPUP_DATA_TYPE_H__
#define __VCP_POPUP_DATA_TYPE_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

/***************************************************************************** 
 * Define
 *****************************************************************************/

// <group DOM_PopupCommon_Macro&Enum_Macro>
// This button ID is used by all popups to supply when popup disappears without any button pressed event.
// For Example, when user presses HOME key, this ID will be supplied with the event.
#define     VCP_POPUP_BUTTON_NO_PRESSED         0xFFFFFFFF

// <group DOM_Popup_Macro&Enum_Macro>
// This button ID is used by all popups to supply when popup has a Cancel type button and it disappears by pressing back key.
// For Example, when user presses BACK key, this ID will be supplied with the event.
#define     VCP_POPUP_BUTTON_CANCEL_PRESSED     0xFFFFFFFE

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

// <group DOM_PopupCommon_Macro&Enum_Enum>
enum VcpPopupTypeEnum
{
    VCP_POPUP_TYPE_FAILURE,         // Failure type popup. COSMOS only -> Will play tone in case of command/confirm popup.
    VCP_POPUP_TYPE_INFO,            // Info type popup.
    VCP_POPUP_TYPE_WARNING,         // Warning type popup. COSMOS only -> Will play tone in case of command/confirm popup.
    VCP_POPUP_TYPE_SUCCESS,         // Success type popup.
    VCP_POPUP_TYPE_PROGRESS,        // Progress type popup.
    VCP_POPUP_TYPE_QUESTION,        // Question type popup.
    VCP_POPUP_TYPE_END_OF_ENUM
};

// <group DOM_Popup_Macro&Enum_Enum>
enum VcpPopupButtonTypeEnum
{
    VCP_POPUP_BUTTON_TYPE_NORMAL,       // Default visual for button.
    VCP_POPUP_BUTTON_TYPE_WARNING,      // Warniing visual for button.
    VCP_POPUP_BUTTON_TYPE_RECOMMEND,    // Customized visual for button.
    VCP_POPUP_BUTTON_TYPE_CANCEL,       // Cancel visual for button.
    VCP_POPUP_BUTTON_TYPE_END_OF_ENUM
};

#endif /* __VCP_POPUP_DATA_TYPE_H__ */

