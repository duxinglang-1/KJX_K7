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
#include "vapp_camco_slim_osd.h"
#include "gdi_lcd_config.h"
#include "MMI_include.h"
#ifdef __VAPP_CAMCO_SLIM__

#pragma arm section code = "DYNAMIC_CODE_CAMCO_ROCODE", rodata = "DYNAMIC_CODE_CAMCO_RODATA"


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
    {31, 320},                  // left bar
    {50, 320},                  // right bar

    //circleControl:
    {30, 30},                 // slider  +
    {30, 293},                 // slider -

    //zoomControl:
    {30, 160},                  // x, y of slider 
    220,                        // 
    20,                         // 
    9,                          // 

    // right side btn
    {455, 35},                  // x,y of gallery btn
    {455, 96},                  // x,y of dirve switch
    {455, 253},                 // x,y of switchApp btn
    {455, 160},                 // x,y of capture btn
    {455, 160},                 // x,y of record btn

    {455, 292},                   // x,y of capture img
    {455, 221},                  // x,y of recder img

    {50,  18},                  // x,y of remain capture Num info (no flash case coordinate)

    {455, 222},                 // x,y of record pause btn
    {50, 18},                   // x,y of record indicator
    {50, 30},                   // x,y of record time text
};
#elif( (GDI_LCD_WIDTH == 240) && (GDI_LCD_HEIGHT == 400) )
vapp_camco_osd_skin g_vapp_camco_skin =
{
    // settingBar:
    {24, 240},                  // left bar
    {50, 240},                  // right bar

    //circleControl:
    {25, 17},                  // slider +
    {25, 220},                 // slider -

    //zoomControl:
    {25, 120},                 // x,y slider
    160,                        // 
    11,                         //  
    8,                          // 

    // right side btn
    {295, 25},                  // x,y of gallery btn
    {295, 68},                  //
    {295, 185},                 // x,y of switchApp btn
    {295, 120},                 // x,y of capture btn
    {295, 120},                 // x,y of record btn

    {295, 222},                   // x,y of capture img
    {295, 155},                  // x,y of recder img

    {40,  15},                  // x,y of remain capture Num info (no flash case coordinate)

    {295, 167},                  // x,y of record pause btn
    {40, 15},                   // x,y of record indicator
    {40, 30},                   // x,y of record time text
};
#elif( (GDI_LCD_WIDTH == 240) && (GDI_LCD_HEIGHT == 320) )
vapp_camco_osd_skin g_vapp_camco_skin =
{
    // settingBar:
    {24, 240},                  // left bar
    {50, 240},                  // right bar

    //circleControl:
    {24, 20},                  // slider +
    {25, 220},                 // slider -

    //zoomControl:
    {25, 120},                 // x,y slider
    160,                        // 
    11,                         //  
    8,                          // 

    // right side btn
    {295, 25},                  // x,y of gallery btn
    {295, 68},                  //
    {295, 188},                 // x,y of switchApp btn
    {295, 120},                 // x,y of capture btn
    {295, 120},                 // x,y of record btn

    {295, 222},                   // x,y of capture img
    {295, 155},                  // x,y of recder img

    {52,  15},                  // x,y of remain capture Num info (no flash case coordinate)

    {295, 167},                  // x,y of record pause btn
    {52, 15},                   // x,y of record indicator
    {52, 30},                   // x,y of record time text
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
#pragma arm section code, rodata

#endif /*__VAPP_CAMCO_SLIM__*/
