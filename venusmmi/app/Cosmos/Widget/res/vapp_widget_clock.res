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
 *  vapp_widget_clock.res
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
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 12 25 2012 min.dong
 * [MAUI_03299595] [Cosmos Slim]Cosmos App patch back to 11B
 * theme res.
 *
 * 05 03 2012 hongxi.shi
 * [MAUI_03142047] [check in] cosmos slim
 * .
 *
 * 01 18 2012 ch.ko
 * [MAUI_03118855] Check-in Cosmos 2.0 launcher and screen lock
 * Check-in patch.
 *
 * 04 08 2011 hongxi.shi
 * [MAUI_02455646] The digital and analog 2 clock time do not reset when restore factory setting
 * .
 *
 * 03 30 2011 hongxi.shi
 * [MAUI_02904265] [Home] Fix incorrect AP naming
 * .
 *
 * 01 24 2011 hongxi.shi
 * [MAUI_02648721] [check in] Fix Calendar issue and revise clock launch function
 * .
 *
 * 01 24 2011 hongxi.shi
 * [MAUI_02648721] [check in] Fix Calendar issue and revise clock launch function
 * .
 *
 * 01 23 2011 hongxi.shi
 * [MAUI_02648721] [check in] Fix Calendar issue and revise clock launch function
 * .
 *
 * 01 17 2011 hongxi.shi
 * [MAUI_02648721] [check in] Fix Calendar issue and revise clock launch function
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
 * 12 23 2010 shinn.lin
 * [MAUI_02852469] add type attribute for venus app in <APP> tag
 * .
 *
 * 12 20 2010 ch.ko
 * [MAUI_02850838] [Widget] Move widgets from common to cosmos package
 * Move widgets to Cosmos package.
 *
 * 12 19 2010 hongxi.shi
 * [MAUI_02644584] [HS widget] check in Calendar , Clock
 * .
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
#if defined(__MMI_VUI_WIDGET_CLOCK1__) || defined(__MMI_VUI_WIDGET_CLOCK2__) || defined(__MMI_VUI_WIDGET_CLOCK3__) || defined(__MMI_VUI_WIDGET_CLOCK4__) || defined(__MMI_VUI_WIDGET_DCLOCK__)

<APP id="VAPP_WIDGET_CLOCK" name="STR_ID_APP_HOME_WIDGET_CLOCK">

    <!-- Common Resource Area -------------------------------------------------->
	<MEMORY base="100*1024 + base(VCUI_WORLDCLOCK)" heap="100*1024" fg="fg(VCUI_WORLDCLOCK)"/>

#ifdef __MMI_VUI_WIDGET_CLOCK2__
   <CACHEDATA type="short" id="NVRAM_WIDGET_CLOCK2_CITY_INDEX" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF,0xFF] </DEFAULT_VALUE>
        <DESCRIPTION>city index</DESCRIPTION>
    </CACHEDATA>
#endif
#ifdef __MMI_VUI_WIDGET_DCLOCK__
    <CACHEDATA type="short" id="NVRAM_WIDGET_DCLOCK_CITY_INDEX" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF,0xFF] </DEFAULT_VALUE>
        <DESCRIPTION>digtial city index</DESCRIPTION>
    </CACHEDATA> 
#endif
    
    <!-- String Resource Area-------------------------------------------------->
    <STRING id="STR_ID_APP_HOME_WIDGET_CLOCK"/>
#ifdef __MMI_VUI_WIDGET_CLOCK1__
    <STRING id="STR_ID_WIDGET_CLOCK1_NAME"/>
#endif
#ifdef __MMI_VUI_WIDGET_CLOCK2__
    <STRING id="STR_ID_WIDGET_CLOCK2_NAME"/>
		<STRING id="STR_ID_WIDGET_CLOCK2_JAN"/>
		<STRING id="STR_ID_WIDGET_CLOCK2_FEB"/>
		<STRING id="STR_ID_WIDGET_CLOCK2_MAR"/>
		<STRING id="STR_ID_WIDGET_CLOCK2_APR"/>
		<STRING id="STR_ID_WIDGET_CLOCK2_MAY"/>
		<STRING id="STR_ID_WIDGET_CLOCK2_JUN"/>
		<STRING id="STR_ID_WIDGET_CLOCK2_JUL"/>
		<STRING id="STR_ID_WIDGET_CLOCK2_AUG"/>
		<STRING id="STR_ID_WIDGET_CLOCK2_SEP"/>
		<STRING id="STR_ID_WIDGET_CLOCK2_OCT"/>
		<STRING id="STR_ID_WIDGET_CLOCK2_NOV"/>
		<STRING id="STR_ID_WIDGET_CLOCK2_DEC"/>
#endif
#ifdef __MMI_VUI_WIDGET_CLOCK3__
    <STRING id="STR_ID_WIDGET_CLOCK3_NAME"/>
#endif
#ifdef __MMI_VUI_WIDGET_CLOCK4__
    <STRING id="STR_ID_WIDGET_CLOCK4_NAME"/>
#endif
#ifdef __MMI_VUI_WIDGET_DCLOCK__
    <STRING id="STR_ID_WIDGET_DCLOCK_NAME"/>
#endif
#if defined(__MMI_VUI_WIDGET_CLOCK2__) || defined(__MMI_VUI_WIDGET_DCLOCK__)
    <STRING id="STR_ID_WIDGET_CLOCK_NEW_CITY"/>
#endif

    <!-- Image Resource Area--------------------------------------------------->

    #define ROOT_CLOCK_PATH       RES_IMG_ROOT"\\\\Widget\\\\Clock\\\\"
// Clock 1
#ifdef __MMI_VUI_WIDGET_CLOCK1__
    <IMAGE id="IMG_CLOCK1_WIDGET_BG">ROOT_CLOCK_PATH"01\\\\Clock_BG.png"</IMAGE>
    <IMAGE id="IMG_CLOCK1_WIDGET_H">ROOT_CLOCK_PATH"01\\\\Hour.png"</IMAGE>
    <IMAGE id="IMG_CLOCK1_WIDGET_M">ROOT_CLOCK_PATH"01\\\\Minute.png"</IMAGE>
    <IMAGE id="IMG_CLOCK1_WIDGET_S">ROOT_CLOCK_PATH"01\\\\Second.png"</IMAGE>
    <IMAGE id="IMG_CLOCK1_WIDGET_CENTER">ROOT_CLOCK_PATH"01\\\\Circle.png"</IMAGE>
    <IMAGE id="IMG_CLOCK1_WIDGET_ICON">ROOT_CLOCK_PATH"01\\\\Clock01.png"</IMAGE>
#endif
// Clock 2
#ifdef __MMI_VUI_WIDGET_CLOCK2__
    <IMAGE id="IMG_CLOCK2_WIDGET_BG">ROOT_CLOCK_PATH"02\\\\Clock_BG.png"</IMAGE>
    <IMAGE id="IMG_CLOCK2_WIDGET_H">ROOT_CLOCK_PATH"02\\\\Hour.png"</IMAGE>
    <IMAGE id="IMG_CLOCK2_WIDGET_M">ROOT_CLOCK_PATH"02\\\\Minute.png"</IMAGE>
    <IMAGE id="IMG_CLOCK2_WIDGET_S">ROOT_CLOCK_PATH"02\\\\Second.png"</IMAGE>
    <IMAGE id="IMG_CLOCK2_WIDGET_CENTER">ROOT_CLOCK_PATH"02\\\\Circle.png"</IMAGE>
    <IMAGE id="IMG_CLOCK2_WIDGET_ICON">ROOT_CLOCK_PATH"02\\\\Clock02.png"</IMAGE>
#endif
// Clock 3
#ifdef __MMI_VUI_WIDGET_CLOCK3__
    <IMAGE id="IMG_CLOCK3_WIDGET_BG">ROOT_CLOCK_PATH"03\\\\Clock_BG.png"</IMAGE>
    <IMAGE id="IMG_CLOCK3_WIDGET_H">ROOT_CLOCK_PATH"03\\\\Hour.png"</IMAGE>
    <IMAGE id="IMG_CLOCK3_WIDGET_M">ROOT_CLOCK_PATH"03\\\\Minute.png"</IMAGE>
    <IMAGE id="IMG_CLOCK3_WIDGET_S">ROOT_CLOCK_PATH"03\\\\Second.png"</IMAGE>
    <IMAGE id="IMG_CLOCK3_WIDGET_CENTER">ROOT_CLOCK_PATH"03\\\\Circle.png"</IMAGE>
    <IMAGE id="IMG_CLOCK3_WIDGET_ICON">ROOT_CLOCK_PATH"03\\\\Clock03.png"</IMAGE>
#endif
//  D Clock 
#ifdef __MMI_VUI_WIDGET_DCLOCK__
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_BG">ROOT_CLOCK_PATH"04\\\\Clock_BG.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_NUM_0">ROOT_CLOCK_PATH"04\\\\0.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_NUM_1">ROOT_CLOCK_PATH"04\\\\1.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_NUM_2">ROOT_CLOCK_PATH"04\\\\2.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_NUM_3">ROOT_CLOCK_PATH"04\\\\3.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_NUM_4">ROOT_CLOCK_PATH"04\\\\4.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_NUM_5">ROOT_CLOCK_PATH"04\\\\5.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_NUM_6">ROOT_CLOCK_PATH"04\\\\6.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_NUM_7">ROOT_CLOCK_PATH"04\\\\7.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_NUM_8">ROOT_CLOCK_PATH"04\\\\8.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_NUM_9">ROOT_CLOCK_PATH"04\\\\9.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_COLON">ROOT_CLOCK_PATH"04\\\\Colon.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DCLOCK_ICON">ROOT_CLOCK_PATH"04\\\\Clock04.png"</IMAGE>
#endif
// Clock 4
#ifdef __MMI_VUI_WIDGET_CLOCK4__
    <IMAGE id="IMG_CLOCK4_WIDGET_BG">ROOT_CLOCK_PATH"05\\\\Clock_BG.png"</IMAGE>
    <IMAGE id="IMG_CLOCK4_WIDGET_H">ROOT_CLOCK_PATH"05\\\\Hour.png"</IMAGE>
    <IMAGE id="IMG_CLOCK4_WIDGET_M">ROOT_CLOCK_PATH"05\\\\Minute.png"</IMAGE>
    <IMAGE id="IMG_CLOCK4_WIDGET_S">ROOT_CLOCK_PATH"05\\\\Second.png"</IMAGE>
    <IMAGE id="IMG_CLOCK4_WIDGET_CENTER">ROOT_CLOCK_PATH"05\\\\Circle.png"</IMAGE>
    <IMAGE id="IMG_CLOCK4_WIDGET_ICON">ROOT_CLOCK_PATH"05\\\\Clock05.png"</IMAGE>
#endif

    <!-- Event Area--------------------------------------------------->
#ifdef __MMI_VUI_WIDGET_CLOCK1__
    <RECEIVER id="EVT_ID_VAPP_WIDGET_SYS_INIT" proc="VappWidgetClock1Publisher"/>
#endif
#ifdef __MMI_VUI_WIDGET_CLOCK2__
    <RECEIVER id="EVT_ID_VAPP_WIDGET_SYS_INIT" proc="VappWidgetClock2Publisher"/>
#endif
#ifdef __MMI_VUI_WIDGET_CLOCK3__
    <RECEIVER id="EVT_ID_VAPP_WIDGET_SYS_INIT" proc="VappWidgetClock3Publisher"/>
#endif
#ifdef __MMI_VUI_WIDGET_CLOCK4__
    <RECEIVER id="EVT_ID_VAPP_WIDGET_SYS_INIT" proc="VappWidgetClock4Publisher"/>
#endif
#ifdef __MMI_VUI_WIDGET_DCLOCK__
    <RECEIVER id="EVT_ID_VAPP_WIDGET_SYS_INIT" proc="VappWidgetDigtialClockPublisher"/>
#endif
</APP>
#else
<APP id="VAPP_WIDGET_CLOCK"></APP>
#endif
