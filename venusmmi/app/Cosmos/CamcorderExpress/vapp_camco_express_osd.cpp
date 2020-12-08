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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

#include "MMI_features.h"
#include "MMIDataType.h"
#include "vapp_camco_express_osd.h"
#include "gdi_lcd_config.h"
#include "MMI_include.h"
#ifdef __VAPP_CAMCO_EXPRESS__

#if( (GDI_LCD_WIDTH == 480) && (GDI_LCD_HEIGHT == 800) )
vapp_camco_osd_skin g_vapp_camco_skin =
{
    // settingBar:
    {82, 480},                  // width,height on H screen
    {82, 480},                  // width,height on H screen

    //circleControl:
    {400, 120},                 // width,height on H screen

    //menuControl:
    {480, 480},                 // width,height on H screen

    //zoomControl:
    {595, 240},                 // x,y of zoom control
    210,                        // R of zoom control curve
    25,                         // distance of inner and outer cycle of zoomer indicator
    10,                         // R of zoomer indicator

    // right side btn
    {759, 41},                  // x,y of gallery btn
    {757, 137},                 // x,y of switchSensor btn
    {757, 388},                 // x,y of switchApp btn
    {740, 240},                 // x,y of capture btn
    {740, 240},                 // x,y of record btn

    {39, 39},                   // x,y of flash btn
    {39, 441},                  // x,y of advance setting btn

    {20, 20},                   // x,y of remain capture Num info (no flash case coordinate)

    {757, 137},                 // x,y of record pause btn
    {20, 20},                   // x,y of record indicator
    {50, 40},                   // x,y of record time text
};
#elif( (GDI_LCD_WIDTH == 320) && (GDI_LCD_HEIGHT == 480) )
vapp_camco_osd_skin g_vapp_camco_skin =
{
    // settingBar:
    {50, 320},                  // width,height on H screen
    {50, 320},                  // width,height on H screen

    //circleControl:
    {200, 80},                 // width,height on H screen

    //menuControl:
    {320, 320},                 // width,height on H screen

    //zoomControl:
    {350, 160},                  // x,y of zoom control
    142,                        // R of zoom control curve
    10,                         // distance of inner and outer cycle of zoomer indicator
    9,                          // R of zoomer indicator

    // right side btn
    {455, 25},                  // x,y of gallery btn
    {455, 87},                  // x,y of switchSensor btn
    {455, 259},                 // x,y of switchApp btn
    {441, 160},                 // x,y of capture btn
    {441, 160},                 // x,y of record btn

    {35, 35},                   // x,y of flash btn
    {35, 285},                  // x,y of advance setting btn

    {18,  18},                  // x,y of remain capture Num info (no flash case coordinate)

    {455, 100},                 // x,y of record pause btn
    {15, 15},                   // x,y of record indicator
    {40, 30},                   // x,y of record time text
};
#elif( (GDI_LCD_WIDTH == 240) && (GDI_LCD_HEIGHT == 400) )
vapp_camco_osd_skin g_vapp_camco_skin =
{
    // settingBar:
    {50, 240},                  // width,height on H screen
    {50, 240},                  // width,height on H screen

    //circleControl:
    {200, 60},                  // width,height on H screen

    //menuControl:
    {240, 240},                 // width,height on H screen

    //zoomControl:
    {300, 120},                 // x,y of zoom control
    148,                        // R of zoom control curve
    11,                         // distance of inner and outer cycle of zoomer indicator
    8,                          // R of zoomer indicator

    // right side btn
    {375, 23},                  // x,y of gallery btn
    {375, 68},                  // x,y of switchSensor btn
    {375, 200},                 // x,y of switchApp btn
    {361, 119},                 // x,y of capture btn
    {361, 119},                 // x,y of record btn

    {29, 29},                   // x,y of flash btn
    {29, 211},                  // x,y of advance setting btn

    {15,  15},                  // x,y of remain capture Num info (no flash case coordinate)

    {375, 58},                  // x,y of record pause btn
    {15, 15},                   // x,y of record indicator
    {50, 40},                   // x,y of record time text
};
#elif( (GDI_LCD_WIDTH == 240) && (GDI_LCD_HEIGHT == 320) )
vapp_camco_osd_skin g_vapp_camco_skin =
{
    // settingBar:
    {50, 240},                  // width,height on H screen
    {50, 240},                  // width,height on H screen

    //circleControl:
    {150, 60},                  // width,height on H screen

    //menuControl:
    {240, 240},                 // width,height on H screen

    //zoomControl:
    {222, 120},                 // x,y of zoom control
    148,                        // R of zoom control curve
    11,                         // distance of inner and outer cycle of zoomer indicator
    8,                          // R of zoomer indicator

    // right side btn
    {295, 23},                  // x,y of gallery btn
    {295, 68},                  // x,y of switchSensor btn
    {295, 200},                 // x,y of switchApp btn
    {281, 119},                 // x,y of capture btn
    {281, 119},                 // x,y of record btn

    {29, 29},                   // x,y of flash btn
    {29, 211},                  // x,y of advance setting btn

    {15, 15} ,                  // x,y of remain capture Num info (no flash case coordinate)

    {295, 58},                  // x,y of record pause btn
    {15, 15},                   // x,y of record indicator
    {50, 40},                   // x,y of record time text
};
#else
vapp_camco_osd_skin g_vapp_camco_skin =
{
    // settingBar:
    {82, 480},                  // width,height on H screen
    {82, 480},                  // width,height on H screen

    //circleControl:
    {400, 120},                 // width,height on H screen

    //menuControl:
    {480, 480},                 // width,height on H screen

    //zoomControl:
    {595, 240},                 // x,y of zoom control
    210,                        // R of zoom control curve
    25,                         // distance of inner and outer cycle of zoomer indicator
    10,                         // R of zoomer indicator

    // right side btn
    {759, 41},                  // x,y of gallery btn
    {757, 137},                 // x,y of switchSensor btn
    {757, 388},                 // x,y of switchApp btn
    {740, 240},                 // x,y of capture btn
    {740, 240},                 // x,y of record btn

    {39, 39},                   // x,y of flash btn
    {39, 441},                  // x,y of advance setting btn

    {20, 20},                   // x,y of remain capture Num info (no flash case coordinate)

    {757, 137},                 // x,y of record pause btn
    {15, 15},                   // x,y of record indicator
    {50, 40},                   // x,y of record time text
};
#endif

#endif /*__VAPP_CAMCO_EXPRESS__*/
