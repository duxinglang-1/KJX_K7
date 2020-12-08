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
 *  vapp_app_widget_clock.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the home screen widget clock resources.
 *
 * Author:
 * -------
 *  Hongxi Shi (mtk80137)
 *  Cheng-Hung Ko (mtk01585)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 03 31 2012 muyi.lan
 * [MAUI_03159071] [UE]same imageshould not  used for alarm and add tab
 * .
 *
 * 02 21 2012 muyi.lan
 * [MAUI_03134160] [Key Launcher]Check in new feature - Key launcher
 * .
 *
 * 02 13 2012 muyi.lan
 * NULL
 * .
 *
 * 02 07 2012 muyi.lan
 * NULL
 * .
 *
 * 09 01 2011 ch.ko
 * [MAUI_03018122] [Home] Check-in FTE launcher
 * Check-in new feature.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "CustResDef.h"


/*****************************************************************************
 * XML
 *****************************************************************************/

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_WIDGET_KEY_ALARM">

    <!-- Common Resource Area -------------------------------------------------->


    <!-- String Resource Area-------------------------------------------------->


    <!-- Image Resource Area--------------------------------------------------->
    <!-- Analog Clock -->
    #undef  CLOCK_IMG_PATH
    #define CLOCK_IMG_PATH CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\Widget\\\\alarm_clock\\\\"
    


    <IMAGE id="IMG_ID_VAPP_WIDGET_ALARM_COMMON_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\Common\\\\widget_common\\\\widget_alarm.png"</IMAGE>  
    <IMAGE id="IMG_ID_VAPP_WIDGET_ALARM_BACKGROUND">CLOCK_IMG_PATH"alarm_9.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_ALARM_HIGHLIGHT">CLOCK_IMG_PATH"alarm_9_s.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_ALARM_CLOCK_ICON">CLOCK_IMG_PATH"alarm_icon.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_ALARM_DIVIDE_LINE">CLOCK_IMG_PATH"line.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_ALARM_PLUS_ICON">CLOCK_IMG_PATH"alarm_add.png"</IMAGE>

    <!-- Event Area--------------------------------------------------->
    <RECEIVER id="EVT_ID_VAPP_WIDGET_SYS_INIT" proc="VappWidgetKeyAlarmPublisher"/>

</APP>

