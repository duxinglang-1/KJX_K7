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
 *  vapp_widget_message.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines message widget resources for key launcher project.
 *
 * Author:
 * -------
 *  Naiming Guo (MTK80900)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 03 09 2012 naiming.guo
 * [MAUI_03140405] key launcher widget check in
 * .
 *
 * 03 02 2012 naiming.guo
 * [MAUI_03140405] key launcher widget check in
 * .
 *
 * 02 24 2012 naiming.guo
 * [MAUI_03134160] [Key Launcher]Check in new feature - Key launcher
 * .
 *
 * 02 22 2012 naiming.guo
 * [MAUI_03134160] [Key Launcher]Check in new feature - Key launcher
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_KEY_MESSAGE__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "CustResDef.h"


/*****************************************************************************
 * XML
 *****************************************************************************/

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_WIDGET_MESSAGE">
    <RECEIVER id="EVT_ID_VAPP_WIDGET_SYS_INIT" proc="VappWidgetMessagePublisher"/>
    <!----- Screen Resource Area ---------------------------------------------->

    <!-- String Resource Area-------------------------------------------------->

    <STRING id="STR_ID_VAPP_WIDGET_MESSAGE"/>
    <STRING id="STR_ID_VAPP_WIDGET_MESSAGE_NO_MESSAGE"/>
    <STRING id="STR_ID_VAPP_WIDGET_MESSAGE_UNSAVED"/>

    <!-- Image Resource Area--------------------------------------------------->
    <IMAGE id="IMG_ID_VAPP_WIDGET_MESSAGE">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\Common\\\\widget_common\\\\widget_message.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_MESSAGE_TYPE_MMS">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\Widget\\\\Message\\\\Message__MMS.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_MESSAGE_TYPE_WAP">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\Widget\\\\Message\\\\Message_push.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_MESSAGE_TYPE_PRO">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\Widget\\\\Message\\\\Message_provisoning.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_MESSAGE_CELL_BG">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\Widget\\\\SNS_Message_common\\\\SNS_glass.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_MESSAGE_CELL_BG_NL">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\Widget\\\\Message\\\\Message_glass.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_MESSAGE_CELL_BG_NR">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\Widget\\\\Message\\\\Message_glass1.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_MESSAGE_CELL_BG_HL">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\Widget\\\\Message\\\\Message_glass_select.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_MESSAGE_CELL_BG_HR">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\Widget\\\\Message\\\\Message_glass_select1.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_MESSAGE_DEFAULT_HEADPORTRAIT">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\Widget\\\\SNS_Message_common\\\\head_portrait.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_MESSAGE_ICON_VIDEO">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\Widget\\\\SNS_Message_common\\\\Video_File.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_MESSAGE_ICON_DEFAULT">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\Widget\\\\Message\\\\Message_glass_image_Files.png"</IMAGE>
</APP>

#endif /* defined(__MMI_VUI_WIDGET_KEY_MESSAGE__) */


