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

<APP id="VAPP_APP_WIDGET_CLOCK">

    <!-- Common Resource Area -------------------------------------------------->


    <!-- String Resource Area-------------------------------------------------->
    <STRING id="STR_ID_VAPP_WIDGET_ANALOG_CLOCK"/>
    <STRING id="STR_ID_VAPP_WIDGET_DIGITAL_CLOCK"/>


    <!-- Image Resource Area--------------------------------------------------->


    <!-- Digital Clock -->
    #define CLOCK_IMG_PATH CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Widget\\\\Clock\\\\04\\\\"

    <IMAGE id="IMG_ID_VAPP_WIDGET_DIGITAL_CLOCK_BG">CLOCK_IMG_PATH"Clock_BG.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_DIGITAL_CLOCK_NUM_0">CLOCK_IMG_PATH"0.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_DIGITAL_CLOCK_NUM_1">CLOCK_IMG_PATH"1.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_DIGITAL_CLOCK_NUM_2">CLOCK_IMG_PATH"2.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_DIGITAL_CLOCK_NUM_3">CLOCK_IMG_PATH"3.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_DIGITAL_CLOCK_NUM_4">CLOCK_IMG_PATH"4.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_DIGITAL_CLOCK_NUM_5">CLOCK_IMG_PATH"5.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_DIGITAL_CLOCK_NUM_6">CLOCK_IMG_PATH"6.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_DIGITAL_CLOCK_NUM_7">CLOCK_IMG_PATH"7.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_DIGITAL_CLOCK_NUM_8">CLOCK_IMG_PATH"8.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_DIGITAL_CLOCK_NUM_9">CLOCK_IMG_PATH"9.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_DIGITAL_CLOCK_COLON">CLOCK_IMG_PATH"Colon.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_DIGITAL_CLOCK_ICON">CLOCK_IMG_PATH"Clock04.png"</IMAGE>


    <!-- Analog Clock -->
    #undef  CLOCK_IMG_PATH
    #define CLOCK_IMG_PATH CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Widget\\\\Clock\\\\05\\\\"

    <IMAGE id="IMG_ID_VAPP_WIDGET_ANALOG_CLOCK_BG">CLOCK_IMG_PATH"Clock_BG.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_ANALOG_CLOCK_H">CLOCK_IMG_PATH"Hour.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_ANALOG_CLOCK_M">CLOCK_IMG_PATH"Minute.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_ANALOG_CLOCK_CENTER">CLOCK_IMG_PATH"Circle.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_ANALOG_CLOCK_ICON">CLOCK_IMG_PATH"Clock05.png"</IMAGE>


    <!-- Event Area--------------------------------------------------->


</APP>

