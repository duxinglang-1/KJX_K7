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
 *  vapp_widget_calendar.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the home screen widget calendar resources.
 *
 * Author:
 * -------
 *  Hongxi Shi (mtk80137)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 05 22 2012 hongxi.shi
 * [MAUI_03186179] [Cosmos_HS_Widget_000_015]show red X icon in the widget screen.
 * .
 *
 * 05 03 2012 hongxi.shi
 * [MAUI_03142047] [check in] cosmos slim
 * .
 *
 * 01 18 2012 ch.ko
 * [MAUI_03118855] Check-in Cosmos 2.0 launcher and screen lock
 * Check-in patch.
 *
 * 03 30 2011 hongxi.shi
 * [MAUI_02904265] [Home] Fix incorrect AP naming
 * .
 *
 * 01 07 2011 hongxi.shi
 * [MAUI_02646851] [check in]  Calendar, Clock widget for WVGA
 * .
 *
 * 12 31 2010 hongxi.shi
 * [MAUI_02646556] [check in] Revise Clock widget
 * .
 *
 * 12 24 2010 hongxi.shi
 * [MAUI_02644584] [HS widget] check in Calendar , Clock
 * .
 *
 * 12 24 2010 hongxi.shi
 * [MAUI_02644584] [HS widget] check in Calendar , Clock
 * .
 *
 * 12 24 2010 hongxi.shi
 * [MAUI_02852869] [Home][IT] Background image of clocks has abnormal line
 * .
 *
 * 12 23 2010 shinn.lin
 * [MAUI_02852469] add type attribute for venus app in <APP> tag
 * .
 *
 * 12 20 2010 ch.ko
 * [MAUI_02850838] [Widget] Move widgets from common to cosmos package
 * Move widgets to Cosmos package.
 *
 * 12 17 2010 hongxi.shi
 * [MAUI_02644584] [HS widget] check in Calendar , Clock
 * .
 *
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
#ifdef __MMI_VUI_WIDGET_CALENDAR__ 
<APP id="VAPP_WIDGET_CALENDAR">

    <!-- Common Resource Area -------------------------------------------------->

    <!-- String Resource Area-------------------------------------------------->
// calendar
    <STRING id="STR_ID_WIDGET_CALENDAR_MON"/>
    <STRING id="STR_ID_WIDGET_CALENDAR_TUE"/>
    <STRING id="STR_ID_WIDGET_CALENDAR_WED"/>
    <STRING id="STR_ID_WIDGET_CALENDAR_THU"/>
    <STRING id="STR_ID_WIDGET_CALENDAR_FRI"/>
    <STRING id="STR_ID_WIDGET_CALENDAR_SAT"/>
    <STRING id="STR_ID_WIDGET_CALENDAR_SUN"/>
    
    <STRING id="STR_ID_WIDGET_CALENDAR_NAME"/>
    <STRING id="STR_ID_WIDGET_CALENDAR_TODAY"/>
    
// Month name
		<STRING id="STR_ID_WIDGET_CALENDAR_JAN"/>
		<STRING id="STR_ID_WIDGET_CALENDAR_FEB"/>
		<STRING id="STR_ID_WIDGET_CALENDAR_MAR"/>
		<STRING id="STR_ID_WIDGET_CALENDAR_APR"/>
		<STRING id="STR_ID_WIDGET_CALENDAR_MAY"/>
		<STRING id="STR_ID_WIDGET_CALENDAR_JUN"/>
		<STRING id="STR_ID_WIDGET_CALENDAR_JUL"/>
		<STRING id="STR_ID_WIDGET_CALENDAR_AUG"/>
		<STRING id="STR_ID_WIDGET_CALENDAR_SEP"/>
		<STRING id="STR_ID_WIDGET_CALENDAR_OCT"/>
		<STRING id="STR_ID_WIDGET_CALENDAR_NOV"/>
		<STRING id="STR_ID_WIDGET_CALENDAR_DEC"/>

    <!-- Image Resource Area--------------------------------------------------->
    #define ROOT_CAL_PATH       RES_IMG_ROOT"\\\\Widget\\\\Canlendar\\\\"
		//#define CALENDAR_WIDGET_THEME_PATH RES_THEME_ROOT"\\\\Theme1\\\\Calendar\\\\"
// Calendar
	<IMAGE id="IMG_CALENDAR_WIDGET_ICON">ROOT_CAL_PATH"Calendar.png"</IMAGE>
    <IMAGE id="IMG_CALENDAR_WIDGET_BG">ROOT_CAL_PATH"BG.9slice.png"</IMAGE>
    <IMAGE id="IMG_CALENDAR_WIDGET_BUTTON_N">ROOT_CAL_PATH"Button_N.9slice.png"</IMAGE>
    <IMAGE id="IMG_CALENDAR_WIDGET_BUTTON_P">ROOT_CAL_PATH"Button_P.9slice.png"</IMAGE>
    <THEME>
    	<IMAGE id = "IMG_CALENDAR_WIDGET_HL" desc = "today background image for calendar widget"/>
    	<IMAGE id="IMG_CALENDAR_WIDGET_TIP" desc = "tip image for calendar widtget if have event"/>
    	<IMAGE id="IMG_CALENDAR_WIDGET_SEL" desc = "highlight image for calendar widget"/>
	</THEME>
    <!-- Event Area--------------------------------------------------->
    <RECEIVER id="EVT_ID_VAPP_WIDGET_SYS_INIT" proc="VappWidgetCalendarPublisher"/>

</APP>
#endif /* __MMI_VUI_WIDGET_CALENDAR__  */
