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
#include "vapp_autocap_osd.h"
#include "gdi_lcd_config.h"
#include "MMI_include.h"
#if defined(__MMI_CAMCORDER__) && (defined(__MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__) || defined(__MMI_CAMCO_FEATURE_CAM_MULTI_ANGLE_VIEW_SHOT__))

#if( (GDI_LCD_WIDTH == 320) && (GDI_LCD_HEIGHT == 480) )
vapp_autocap_osd_skin g_vapp_autocap_skin = 
{ 
    // settingBar:
    {52, 320},                  // width,height on H screen 

    //zoomControl:    
    {319,160},                  // x,y of zoom control
    142,                        // R of zoom control curve
    10,                         // distance of inner and outer cycle of zoomer indicator    
    9,                          // R of zoomer indicator

    // right side btn
    {455,25},                   // x,y of gallery btn
    {455,87},                   // x,y of switchSensor btn
    {455,259},                  // x,y of switchApp btn
    {441,160},                  // x,y of capture btn
    {455,450},                  // x,y of storage btn

    {64,48},                    // width,height on H screen
    {63,47},                    // width,height on H screen
        

    // direction icon
    {176, 160},
    {304, 160},
    {240, 96},
    {240, 224},

    // direction indicator icon
    {50, 160},
    {377, 160},
    {214, 50},
    {214, 270},

    // capture process
    {480, 78},
    {78, 320},
    {455, 80},
    {455, 240},
    {455, 80},
    {455, 240},
    
    // clip process
    {480, 78},
    {78, 320},
    {0, 200},
};
#elif( (GDI_LCD_WIDTH == 480) && (GDI_LCD_HEIGHT == 800) )
vapp_autocap_osd_skin g_vapp_autocap_skin = 
{ 
    // settingBar:
    {82, 480},                  // width,height on H screen 

    //zoomControl:    
    {595,240},                  // x,y of zoom control
    210,                        // R of zoom control curve
    25,                         // distance of inner and outer cycle of zoomer indicator    
    10,                         // R of zoomer indicator

    // right side btn
    {759,41},                   // x,y of gallery btn
    {757,137},                  // x,y of switchSensor btn
    {757,388},                  // x,y of switchApp btn
    {740,240},                  // x,y of capture btn
    {759,720},                  // x,y of storage btn

    {128,96},                   // width,height on H screen
    {127,97},                   // width,height on H screen

    // direction icon
    {306, 240},
    {494, 240},
    {400, 145},
    {400, 335},

    // direction indicator icon
    {65, 240},
    {575, 240},
    {320, 65},
    {320, 415},

    // capture process
    {800, 117},
    {117, 480},
    {754, 120},
    {754, 360},
    {754, 120},
    {754, 360},
    
    // clip process
    {800, 117},
    {117, 480},
    {0, 320},
};
#elif( (GDI_LCD_WIDTH == 240) && (GDI_LCD_HEIGHT == 400) )
vapp_autocap_osd_skin g_vapp_autocap_skin = 
{ 
    // settingBar:
    {52, 240},                  // width,height on H screen 

    //zoomControl:    
    {261,119},                  // x,y of zoom control
    148,                        // R of zoom control curve
    11,                         // distance of inner and outer cycle of zoomer indicator    
    8,                          // R of zoomer indicator

    // right side btn
    {375,23},                   // x,y of gallery btn
    {375,68},                   // x,y of switchSensor btn
    {375,200},                  // x,y of switchApp btn
    {361,119},                  // x,y of capture btn
    {375,360},                  // x,y of storage btn

    {64,48},                    // width,height on H screen
    {63,47},                    // width,height on H screen        

    // direction icon
    {152, 120},
    {248, 120},
    {200, 72},
    {200, 168},

    // direction indicator icon
    {32, 120},
    {288, 120},
    {160, 32},
    {160, 208},

    // capture process
    {400, 78},
    {78, 240},
    {375, 60},
    {375, 180},
    {375, 60},
    {375, 180},
    
    // clip process
    {400, 78},
    {78, 240},
    {0, 140},
};
#elif( (GDI_LCD_WIDTH == 240) && (GDI_LCD_HEIGHT == 320) )
vapp_autocap_osd_skin g_vapp_autocap_skin = 
{ 
    // settingBar:
    {52, 240},                  // width,height on H screen 

    //zoomControl:    
    {222,119},                  // x,y of zoom control
    148,                        // R of zoom control curve
    11,                         // distance of inner and outer cycle of zoomer indicator    
    8,                          // R of zoomer indicator

    // right side btn
    {295,23},                   // x,y of gallery btn
    {295,68},                   // x,y of switchSensor btn
    {295,200},                  // x,y of switchApp btn
    {281,119},                  // x,y of capture btn
    {375,360},                  // x,y of storage btn

    {64,48},                    // width,height on H screen
    {63,47},                    // width,height on H screen
    
    // direction icon
    {112, 120},
    {208, 120},
    {160, 72},
    {160, 168},
    
    // direction indicator icon
    {32, 120},
    {288, 120},
    {160, 32},
    {160, 208},
    
    // capture process
    {320, 78},
    {78, 240},
    {295, 60},
    {295, 180},
    {295, 60},
    {295, 180},
    
    // clip process
    {320, 78},
    {78, 240},
    {0, 140},
};
#else
vapp_autocap_osd_skin g_vapp_autocap_skin = 
{ 
    // settingBar:
    {82, 480},                  // width,height on H screen 

    //zoomControl:    
    {595,240},                  // x,y of zoom control
    210,                        // R of zoom control curve
    25,                         // distance of inner and outer cycle of zoomer indicator    
    10,                         // R of zoomer indicator

    // right side btn
    {759,41},                   // x,y of gallery btn
    {757,137},                  // x,y of switchSensor btn
    {757,388},                  // x,y of switchApp btn
    {740,240},                  // x,y of capture btn
    {759,720},                  // x,y of storage btn

    {128,96},                   // width,height on H screen
    {127,97},                   // width,height on H screen

    // direction icon
    {306, 240},
    {494, 240},
    {400, 145},
    {400, 335},

    // direction indicator icon
    {65, 240},
    {575, 240},
    {320, 65},
    {320, 415},

    // capture process
    {800, 117},
    {148, 480},
    {754, 120},
    {754, 360},
    {754, 120},
    {754, 360},
    
    // clip process
    {800, 117},
    {117, 480},
    {0, 320},
};

#endif
#endif
