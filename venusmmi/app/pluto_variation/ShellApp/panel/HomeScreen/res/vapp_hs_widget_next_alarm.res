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
 *  vapp_hs_widget_next_alarm.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the resource ID for the "Next Alarm" widget.
 *
 * Author:
 * -------
 *  Cheng-Hung Ko (mtk01585)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * Jun 22 2010 mtk01585
 * [MAUI_02567833] [Idle] Revise codes by using XML resources
 * Check-in XML resources.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "CustResDef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_VENUS_HOMESCREEN_WG_NEXT_ALARM">

#if defined(__MMI_VUI_HOMESCREEN_NEXT_ALARM__)

    <!----- Include Area ------------------------------------------------------>
    <INCLUDE file="GlobalResDef.h"/>


    <!----- String Resource Area ---------------------------------------------->
    <STRING id="VAPP_HS_STR_WG_NEXT_ALARM"/>


    <!----- Image Resource Area ----------------------------------------------->
    #define ROOT_PATH               CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\"
    #define WIDGET_PATH             ROOT_PATH"Widget\\\\"
    #define NEXT_ALARM_WIDGET_PATH  WIDGET_PATH"NextAlarm\\\\"

#if defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
    #define VUI_HS_IMG_TYPE "BMP"
#else
    #define VUI_HS_IMG_TYPE "PNG"
#endif

    <IMAGE id="VAPP_HS_IMG_WG_ICON_NEXT_ALARM">WIDGET_PATH"Widgeticon_NextAlarm.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_NEXT_ALARM_BG">NEXT_ALARM_WIDGET_PATH"NextAlarm_BG."VUI_HS_IMG_TYPE</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_NEXT_ALARM_CLOCK_NUMBER_0">NEXT_ALARM_WIDGET_PATH"NextAlarm_Time0.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_NEXT_ALARM_CLOCK_NUMBER_1">NEXT_ALARM_WIDGET_PATH"NextAlarm_Time1.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_NEXT_ALARM_CLOCK_NUMBER_2">NEXT_ALARM_WIDGET_PATH"NextAlarm_Time2.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_NEXT_ALARM_CLOCK_NUMBER_3">NEXT_ALARM_WIDGET_PATH"NextAlarm_Time3.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_NEXT_ALARM_CLOCK_NUMBER_4">NEXT_ALARM_WIDGET_PATH"NextAlarm_Time4.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_NEXT_ALARM_CLOCK_NUMBER_5">NEXT_ALARM_WIDGET_PATH"NextAlarm_Time5.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_NEXT_ALARM_CLOCK_NUMBER_6">NEXT_ALARM_WIDGET_PATH"NextAlarm_Time6.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_NEXT_ALARM_CLOCK_NUMBER_7">NEXT_ALARM_WIDGET_PATH"NextAlarm_Time7.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_NEXT_ALARM_CLOCK_NUMBER_8">NEXT_ALARM_WIDGET_PATH"NextAlarm_Time8.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_NEXT_ALARM_CLOCK_NUMBER_9">NEXT_ALARM_WIDGET_PATH"NextAlarm_Time9.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_NEXT_ALARM_CLOCK_AM">NEXT_ALARM_WIDGET_PATH"NextAlarm_TimeAm.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_NEXT_ALARM_CLOCK_PM">NEXT_ALARM_WIDGET_PATH"NextAlarm_TimePm.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_NEXT_ALARM_CLOCK_COLON">NEXT_ALARM_WIDGET_PATH"NextAlarm_TimeColon.png"</IMAGE>


    <!----- Screen Resource Area ---------------------------------------------->


    <!----- Menu Resource Area ------------------------------------------------>


#endif /* defined(__MMI_VUI_HOMESCREEN_NEXT_ALARM__) */

</APP>

