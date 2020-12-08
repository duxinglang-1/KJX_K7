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
 *  vapp_widget_favorite_contact.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines favorite conatct widget resources for key launcher project.
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
 * 04 12 2012 naiming.guo
 * [MAUI_03162236] [UE]Two menu option should not be selected at the same time
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

#if defined(__MMI_VUI_WIDGET_KEY_VIP_CONTACT__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "CustResDef.h"


/*****************************************************************************
 * XML
 *****************************************************************************/

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_WIDGET_FAVORITE_CONTACT">

    <RECEIVER id="EVT_ID_VAPP_WIDGET_SYS_INIT" proc="VappWidgetFavContactPublisher"/>
    <!----- Screen Resource Area ---------------------------------------------->

    <!-- String Resource Area-------------------------------------------------->

    <STRING id="STR_ID_VAPP_WIDGET_FAVORITE_CONTACT"/>
    <STRING id="STR_ID_VAPP_WIDGET_FAVORITE_CONTACT_ADD"/>
    <STRING id="STR_ID_VAPP_WIDGET_FAVORITE_CONTACT_WARNING"/>

    <!-- Image Resource Area--------------------------------------------------->
    <IMAGE id="IMG_ID_VAPP_WIDGET_CONTACT">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\Common\\\\widget_common\\\\widget_favorite_contacts.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_CONTACT_DEFAULT_PIC">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\Widget\\\\VIP_contact\\\\image.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_CONTACT_ADD_SMALL">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\Widget\\\\VIP_contact\\\\image_add_small.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_CONTACT_ADD_BIG">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\Widget\\\\VIP_contact\\\\image_add.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_CONTACT_BG_SOFTKEY">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\HS\\\\hone_softkey.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_CONTACT_BG_CELL_N">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\Widget\\\\VIP_contact\\\\contact_glass.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_CONTACT_BG_CELL_H">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\Widget\\\\VIP_contact\\\\contact_select_glass.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_CONTACT_BG_POP">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\Widget\\\\VIP_contact\\\\contact_pop.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_CONTACT_BG_POP_BUTTON_N">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\Widget\\\\VIP_contact\\\\contact_pop_button.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_CONTACT_BG_POP_BUTTON_H">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\Widget\\\\VIP_contact\\\\contact_pop_select.9slice.png"</IMAGE>
</APP>

#endif /* defined(__MMI_VUI_WIDGET_KEY_VIP_CONTACT__) */


