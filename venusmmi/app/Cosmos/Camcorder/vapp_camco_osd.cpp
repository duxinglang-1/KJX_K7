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
#include "vapp_camco_osd.h"
#include "gdi_lcd_config.h"
#include "MMI_include.h"
#ifdef __VAPP_CAMCO__

#if( (GDI_LCD_WIDTH == 320) && (GDI_LCD_HEIGHT == 480) )
vapp_camco_osd_skin g_vapp_camco_skin = 
{ 
    // settingBar:
    {50, 320},                  // width,height on H screen 
    {50, 320},                  // width,height on H screen 

    //circleControl:  
    {320, 193},                 // width,height on H screen 
    {23,96},                    // x,y of setting icon related to control origin
    {58,96},                    // x,y of cicle plate related to control origin 
    {52,96},                    // x,y of selected setting indicator related to control origin
    
    66,                         // R of setting item circle
    20,                         // offset of circle item    

    //menuControl:      
    {398, 193},                 // width,height on H screen
    0.5376,                     // Ratio of setting and setting item
    31,                         // offset for level 1 text to icon

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
    {441,160},                  // x,y of record btn    
    
    {30,290},                   // x,y of reset btn    

    {{80,  305},                // x,y of status icon
     {125,  305},    
     {170,  305},    
     {215,  305},    
     {260,  305},    
     {305,  305},         
     {345,  305},    
     {390,  305}         
    },

    {90,  45},                  // x,y of remain capture Num info
    {90,  45},                  // x,y of remain capture Num info

    // multi shot related:
    {{60,  40},                 // width,height of multi shot frame on H screen
     {60,  40},    
     {60,  40},    
     {60,  40},    
     {60,  40}           
    }, 
    {{105,  295},               // x,y of multi shot frame
     {175,  295},    
     {245,  295},    
     {315,  295},    
     {385,  295}           
    },    
    {{32,  25},                 // x,y of multi shot frame on V screen   
     {96,  25},    
     {160,  25},    
     {224,  25},    
     {288,  25}           
    },
    {{40,  20},                 // x,y of check on multi shot frame (related to frame letf/up corner)
     {40,  20},    
     {40,  20},    
     {40,  20},    
     {40,  20}           
    },

    {455,  87},                 // x,y of record pause btn    
    {20,  30},                  // x,y of record indicator     
    {40,  30},                  // x,y of record time text    
      
};
#elif( (GDI_LCD_WIDTH == 480) && (GDI_LCD_HEIGHT == 800) )
vapp_camco_osd_skin g_vapp_camco_skin = 
{ 
    // settingBar:
    {82, 480},                  // width,height on H screen 
    {82, 480},                  // width,height on H screen 

    //circleControl:  
    {480, 352},                 // width,height on H screen 
    {30,144},                   // x,y of setting icon related to control origin
    {90,144},                   // x,y of cicle plate related to control origin 
    {82,144},                   // x,y of selected setting indicator related to control origin
    
    120,                        // R of setting item circle
    27,                         // offset of circle item    

    //menuControl:      
    {759, 352},                 // width,height on H screen
    0.5296,                     // Ratio of setting and setting item
    77,                         // offset for level 1 text to icon

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
    {740,240},                  // x,y of record btn    
    
    {46,438},                   // x,y of reset btn    

    {{105,  460},               // x,y of status icon
     {180,  460},               
     {255,  460},    
     {330,  460},    
     {405,  460},    
     {480,  460},         
     {555,  460},    
     {630,  460}         
    },

    {140,  60},                 // x,y of remain capture Num info
    {140,  60},                 // x,y of remain capture Num info

    // multi shot related:
    {{90,  60},                 // width,height of multi shot frame on H screen
     {90,  60},    
     {90,  60},    
     {90,  60},    
     {90,  60}           
    }, 
    {{200,  440},               // x,y of multi shot frame
     {300,  440},    
     {400,  440},    
     {500,  440},    
     {600,  440}           
    },    
    {{60,  40},                 // x,y of multi shot frame on V screen   
     {150,  40},    
     {240,  40},    
     {330,  40},    
     {420,  40}           
    },
    {{65,  35},                 // x,y of check on multi shot frame (related to frame letf/up corner)
     {65,  35},    
     {65,  35},    
     {65,  35},    
     {65,  35}           
    },

    {757,  137},                // x,y of record pause btn    
    {30,  40},                  // x,y of record indicator     
    {50,  40},                  // x,y of record time text    
      
};
#elif( (GDI_LCD_WIDTH == 240) && (GDI_LCD_HEIGHT == 400) )
vapp_camco_osd_skin g_vapp_camco_skin = 
{ 
    // settingBar:
    {50, 240},                  // width,height on H screen 
    {50, 240},                  // width,height on H screen 

    //circleControl:  
    {300, 220},                 // width,height on H screen 
    {21,96},                    // x,y of setting icon related to control origin
    {58,96},                    // x,y of cicle plate related to control origin 
    {52,96},                    // x,y of selected setting indicator related to control origin
    
    67,                         // R of setting item circle
    20,                         // offset of circle item    

    //menuControl:      
    {400, 193},                 // width,height on H screen
    0.516,                      // Ratio of setting and setting item
    35,                         // offset for level 1 text to icon

    //zoomControl:    
    {261,119},                  // x,y of zoom control
    148,                        // R of zoom control curve
    11,                         // distance of inner and outer cycle of zoomer indicator    
    8,                          // R of zoomer indicator

    // right side btn
    {375,23},                   // x,y of gallery btn
    {375,68},                   // x,y of switchSensor btn
    {375,195},                  // x,y of switchApp btn
    {361,119},                  // x,y of capture btn
    {361,119},                  // x,y of record btn    
    
    {25,220},                   // x,y of reset btn    

    {{95,  228},                // x,y of status icon
     {125,  228},               
     {155,  228},    
     {185,  228},    
     {215,  228},    
     {245,  228},         
     {275,  228},    
     {305,  228}         
    },

    {90,  45},                  // x,y of remain capture Num info
    {90,  45},                  // x,y of remain capture Num info

    // multi shot related:
    {{45,  30},                 // width,height of multi shot frame on H screen
     {45,  30},    
     {45,  30},    
     {45,  30},    
     {45,  30}           
    }, 
    {{80,   210},               // x,y of multi shot frame
     {140,  210},    
     {200,  210},    
     {260,  210},    
     {320,  210}           
    },    
    {{24,  40},                 // x,y of multi shot frame on V screen   
     {72,  40},    
     {120,  40},    
     {168,  40},    
     {216,  40}           
    },
    {{33,  22},                 // x,y of check on multi shot frame (related to frame letf/up corner)
     {33,  22},    
     {33,  22},    
     {33,  22},    
     {33,  22}           
    },

    {375,  68},                 // x,y of record pause btn    
    {30,  40},                  // x,y of record indicator     
    {50,  40},                  // x,y of record time text    
      
};
#elif( (GDI_LCD_WIDTH == 240) && (GDI_LCD_HEIGHT == 320) )
vapp_camco_osd_skin g_vapp_camco_skin = 
{ 
    // settingBar:
    {50, 240},                  // width,height on H screen 
    {50, 240},                  // width,height on H screen 

    //circleControl:  
    {240, 193},                 // width,height on H screen 
    {21,96},                    // x,y of setting icon related to control origin
    {58,96},                    // x,y of cicle plate related to control origin 
    {52,96},                    // x,y of selected setting indicator related to control origin
    
    67,                         // R of setting item circle
    15,                         // offset of circle item    

    //menuControl:      
    {320, 193},                 // width,height on H screen
    0.59375,                    // Ratio of setting and setting item
    35,                         // offset for level 1 text to icon

    //zoomControl:    
    {222,119},                  // x,y of zoom control
    148,                        // R of zoom control curve
    11,                         // distance of inner and outer cycle of zoomer indicator    
    8,                          // R of zoomer indicator

    // right side btn
    {295,23},                   // x,y of gallery btn
    {295,68},                   // x,y of switchSensor btn
    {295,195},                  // x,y of switchApp btn
    {281,119},                  // x,y of capture btn
    {281,119},                  // x,y of record btn    
    
    {25,220},                   // x,y of reset btn    

    {{65,  229},                // x,y of status icon
     {88,  229},               
     {111,  229},    
     {134,  229},    
     {157,  229},    
     {180,  229},         
     {203,  229},    
     {226,  229}         
    },

    {90,  45},                  // x,y of remain capture Num info
    {90,  45},                  // x,y of remain capture Num info

    // multi shot related:
    {{45,  30},                 // width,height of multi shot frame on H screen
     {45,  30},    
     {45,  30},    
     {45,  30},    
     {45,  30}           
    }, 
    {{40,  210},                // x,y of multi shot frame
     {100,  210},    
     {160,  210},    
     {220,  210},    
     {280,  210}           
    },    
    {{24,  40},                 // x,y of multi shot frame on V screen   
     {72,  40},    
     {120,  40},    
     {168,  40},    
     {216,  40}           
    },
    {{33,  22},                 // x,y of check on multi shot frame (related to frame letf/up corner)
     {33,  22},    
     {33,  22},    
     {33,  22},    
     {33,  22}           
    },

    {295,  60},                 // x,y of record pause btn    
    {30,  40},                  // x,y of record indicator     
    {50,  40},                  // x,y of record time text    
      
};
#else
vapp_camco_osd_skin g_vapp_camco_skin = 
{ 
    // settingBar:
    {50, 320},                  // width,height on H screen 
    {50, 320},                  // width,height on H screen 

    //circleControl:  
    {320, 193},                 // width,height on H screen 
    {23,96},                    // x,y of setting icon related to control origin
    {58,96},                    // x,y of cicle plate related to control origin 
    {52,96},                    // x,y of selected setting indicator related to control origin
    
    66,                         // R of setting item circle
    20,                         // offset of circle item    

    //menuControl:      
    {398, 193},                 // width,height on H screen
    0.5376,                     // Ratio of setting and setting item
    31,                         // offset for level 1 text to icon

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
    {441,160},                  // x,y of record btn    
    
    {30,290},                   // x,y of reset btn    

    {{80,  305},                // x,y of status icon
     {125,  305},               
     {170,  305},    
     {215,  305},    
     {260,  305},    
     {305,  305},         
     {345,  305},    
     {390,  305}         
    },

    {90,  45},                  // x,y of remain capture Num info
    {90,  45},                  // x,y of remain capture Num info

    // multi shot related:
    {{60,  40},                 // width,height of multi shot frame on H screen
     {60,  40},    
     {60,  40},    
     {60,  40},    
     {60,  40}           
    }, 
    {{105,  295},               // x,y of multi shot frame
     {175,  295},    
     {245,  295},    
     {315,  295},    
     {385,  295}           
    },    
    {{35,  25},                 // x,y of multi shot frame on V screen   
     {99,  25},    
     {163,  25},    
     {227,  25},    
     {291,  25}           
    },
    {{40,  20},                 // x,y of check on multi shot frame (related to frame letf/up corner)
     {40,  20},    
     {40,  20},    
     {40,  20},    
     {40,  20}           
    },

    {455,  87},                 // x,y of record pause btn    
    {20,  30},                  // x,y of record indicator     
    {40,  30},                  // x,y of record time text    
      
};

#endif
#endif
