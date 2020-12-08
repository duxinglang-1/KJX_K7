/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vapp_widget_flip_clock.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines widget flip clock resource.
 *
 * Author:
 * -------
 * 
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 05 24 2012 snow.wang
 * [MAUI_03188000] Widget Flip Clock check in 11B
 * .
 *
 * 05 18 2012 snow.wang
 * [MAUI_03188000] Widget Flip Clock check in 11B
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#include "MMI_features.h"

#ifdef __MMI_VUI_WIDGET_FLIP_CLOCK__

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "CustResDef.h"

/*****************************************************************************
 * XML
 *****************************************************************************/

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_WIDGET_FLIP_CLOCK" name="STR_ID_APP_HOME_WIDGET_FLIP_CLOCK">

    <!-- Common Resource Area -------------------------------------------------->
    
    <!-- String Resource Area-------------------------------------------------->
    <STRING id="STR_ID_APP_HOME_WIDGET_FLIP_CLOCK"/>

    <!-- Image Resource Area--------------------------------------------------->

    #define ROOT_CLOCK_PATH       RES_IMG_ROOT"\\\\Widget\\\\FlipClock\\\\"
    
    <IMAGE id="IMG_FCLOCK_WIDGET_BG">ROOT_CLOCK_PATH"Widget_Clock_BG.png"</IMAGE>
    <IMAGE id="IMG_FCLOCK_WIDGET_LEFT_BOTTOM">ROOT_CLOCK_PATH"Page_Lower_Left.9slice.png"</IMAGE>
    <IMAGE id="IMG_FCLOCK_WIDGET_RIGHT_BOTTOM">ROOT_CLOCK_PATH"Page_Lower_Right.9slice.png"</IMAGE>
    <IMAGE id="IMG_FCLOCK_WIDGET_LEFT_TOP">ROOT_CLOCK_PATH"Page_Top_Left.9slice.png"</IMAGE>
    <IMAGE id="IMG_FCLOCK_WIDGET_RIGHT_TOP">ROOT_CLOCK_PATH"Page_Top_Right.9slice.png"</IMAGE>
    <IMAGE id="IMG_FCLOCK_WIDGET_NUM_B_0">ROOT_CLOCK_PATH"Number\\\\0_Bottom.png"</IMAGE>
    <IMAGE id="IMG_FCLOCK_WIDGET_NUM_B_1">ROOT_CLOCK_PATH"Number\\\\1_Bottom.png"</IMAGE>
    <IMAGE id="IMG_FCLOCK_WIDGET_NUM_B_2">ROOT_CLOCK_PATH"Number\\\\2_Bottom.png"</IMAGE>
    <IMAGE id="IMG_FCLOCK_WIDGET_NUM_B_3">ROOT_CLOCK_PATH"Number\\\\3_Bottom.png"</IMAGE>
    <IMAGE id="IMG_FCLOCK_WIDGET_NUM_B_4">ROOT_CLOCK_PATH"Number\\\\4_Bottom.png"</IMAGE>
    <IMAGE id="IMG_FCLOCK_WIDGET_NUM_B_5">ROOT_CLOCK_PATH"Number\\\\5_Bottom.png"</IMAGE>
    <IMAGE id="IMG_FCLOCK_WIDGET_NUM_B_6">ROOT_CLOCK_PATH"Number\\\\6_Bottom.png"</IMAGE>
    <IMAGE id="IMG_FCLOCK_WIDGET_NUM_B_7">ROOT_CLOCK_PATH"Number\\\\7_Bottom.png"</IMAGE>
    <IMAGE id="IMG_FCLOCK_WIDGET_NUM_B_8">ROOT_CLOCK_PATH"Number\\\\8_Bottom.png"</IMAGE>
    <IMAGE id="IMG_FCLOCK_WIDGET_NUM_B_9">ROOT_CLOCK_PATH"Number\\\\9_Bottom.png"</IMAGE>
    <IMAGE id="IMG_FCLOCK_WIDGET_NUM_T_0">ROOT_CLOCK_PATH"Number\\\\0_Top.png"</IMAGE>
    <IMAGE id="IMG_FCLOCK_WIDGET_NUM_T_1">ROOT_CLOCK_PATH"Number\\\\1_Top.png"</IMAGE>
    <IMAGE id="IMG_FCLOCK_WIDGET_NUM_T_2">ROOT_CLOCK_PATH"Number\\\\2_Top.png"</IMAGE>
    <IMAGE id="IMG_FCLOCK_WIDGET_NUM_T_3">ROOT_CLOCK_PATH"Number\\\\3_Top.png"</IMAGE>
    <IMAGE id="IMG_FCLOCK_WIDGET_NUM_T_4">ROOT_CLOCK_PATH"Number\\\\4_Top.png"</IMAGE>
    <IMAGE id="IMG_FCLOCK_WIDGET_NUM_T_5">ROOT_CLOCK_PATH"Number\\\\5_Top.png"</IMAGE>
    <IMAGE id="IMG_FCLOCK_WIDGET_NUM_T_6">ROOT_CLOCK_PATH"Number\\\\6_Top.png"</IMAGE>
    <IMAGE id="IMG_FCLOCK_WIDGET_NUM_T_7">ROOT_CLOCK_PATH"Number\\\\7_Top.png"</IMAGE>
    <IMAGE id="IMG_FCLOCK_WIDGET_NUM_T_8">ROOT_CLOCK_PATH"Number\\\\8_Top.png"</IMAGE>
    <IMAGE id="IMG_FCLOCK_WIDGET_NUM_T_9">ROOT_CLOCK_PATH"Number\\\\9_Top.png"</IMAGE>
    <IMAGE id="IMG_FCLOCK_WIDGET_LEFT_SHADOW">ROOT_CLOCK_PATH"Shadow_Left.9slice.png"</IMAGE>
    <IMAGE id="IMG_FCLOCK_WIDGET_RIGHT_SHADOW">ROOT_CLOCK_PATH"Shadow_Right.9slice.png"</IMAGE>
    <IMAGE id="IMG_FCLOCK_WIDGET_ICON">ROOT_CLOCK_PATH"FlipClock.png"</IMAGE>    
    
    <!-- Event Area--------------------------------------------------->
    <RECEIVER id="EVT_ID_VAPP_WIDGET_SYS_INIT" proc="VappWidgetFlipClockPublisher"/>
</APP>

#endif
