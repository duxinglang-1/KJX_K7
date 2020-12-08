/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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

/*******************************************************************************
 * Filename:
 * ---------
 *  resource_vt_skins.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Video Telephony customization file.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *              HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_VIDEO_TELEPHONY__

#include "MMIDatatype.h"
#include "gdi_lcd_config.h"
#include "resource_vt_skins.h"

#ifndef __MMI_FTE_SUPPORT__

/***************************************************************************** 
 *
 * Customizable VT Skin     
 * [176x220]
 * [240x320]
 *
 *****************************************************************************/



#if ((GDI_LCD_WIDTH == 128) && (GDI_LCD_HEIGHT == 128))
#error "Currently, VT only support with LCD 176x220 or larger, add this part if needed"
#elif ((GDI_LCD_WIDTH == 128) && (GDI_LCD_HEIGHT == 160))
#error "Currently, VT only support with LCD 176x220 or larger, add this part if needed"

#elif ( (GDI_LCD_WIDTH == 176) && (GDI_LCD_HEIGHT == 220) )
/***************************************************************************** 
 *
 * [176x220]
 *
 *****************************************************************************/

    /* NOTICE, not config correct position yet */
    mmi_vtcs_skin_struct g_mmi_vtcs_skin_cntx =
    {
        /* bg */
        {0, 0, 176, 18},       /* status_rect */        
        {0, 0, 0, 0},    /* title_rect */
        {0, 18, 176, 152},   /* body_rect */     
        {0, 145, 176, 25},  /* panel_0_rect */                 
        {0, 170, 176, 30},  /* panel_1_rect */                             
        {0, 200, 176, 20},  /* softkey_rect */ 

        /* video window */        
        {0, 22, 176, 144}, /* main_wnd_rect */
        {112, 122, 64, 48},  /* sub_wnd_rect */ 
        {116, 118},          /* sub_bg_pos */             

        /* icons */      
        {55, 173},         /* icon_1_pos */
        {72, 173},         /* icon_2_pos */
        {89, 173},         /* icon_3_pos */                    
        {106, 173},         /* icon_4_pos */
        {123, 173},         /* icon_5_pos */
        {140, 173},         /* icon_6_pos */  
        {157, 173},         /* icon_7_pos */  
        {0, 0},             /* icon_8_pos */  
        {0, 0},             /* icon_9_pos */  
        {0, 0},             /* icon_10_pos */          
        {0, 0},             /* icon_11_pos */          

        /* time/cost */
        {5, 182},           /* time_pos */    
        {5, 182},           /* cost_pos */    

        /* scrollbar */   
        {149, 149},         /* inc_icon_pos */
        {3, 149},           /* dec_icon_pos */
        {31, 154},          /* scroll_bar_pos */    

        /* user input */
        {6, 151, 160, 19}, /* input_box_rect */
        {0, 145},           /* input_box_bg_pos */
            
        /* vk */
        {4, 173},         /* vk_0_pos */            
        {18, 173},           /* vk_1_pos */            
        {32, 173},          /* vk_2_pos */            
        {46, 173},          /* vk_3_pos */            
        {60, 173},          /* vk_4_pos */            
        {74, 173},         /* vk_5_pos */            
        {88, 173},         /* vk_6_pos */            
        {102, 173},         /* vk_7_pos */            
        {116, 173},         /* vk_8_pos */                        
        {130, 173},         /* vk_9_pos */ 
        {144, 173},         /* vk_star */    
        {158, 173},         /* vk_pound */                
        {0, 0},         /*fullscr_skin_bg_pos*/  
        {0, 0},         /*fullscr_main_wnd_pos*/  
        {0, 0},         /*fullscr_sub_wnd_pos*/   
        {0, 0},         /*fullscr_sub_bg_pos*/
        {0, 0},         /*fullscr_time_pos*/
           
        /* text color */
        {255, 255, 255, 0, 0, 0},    /* text color */
    };


#elif ((GDI_LCD_WIDTH == 240) && (GDI_LCD_HEIGHT == 320)) 
/***************************************************************************** 
 *
 * [240x320]
 *
 *****************************************************************************/
    mmi_vtcs_skin_struct g_mmi_vtcs_skin_cntx =
    {
        /* bg */
        {0, 0, 240, 18},     /* status_rect */        
        {0, 18, 240, 37},    /* title_rect */
        {0, 55, 220, 166},   /* body_rect */     
        {0, 221, 220, 35},   /* panel_0_rect */    
        {0, 256, 220, 37},   /* panel_1_rect */                   
        {0, 293, 240, 27},   /* softkey_rect */ 

        /* video window */        
        {32, 56, 176, 144},  /* main_wnd_rect */
        {154, 153, 80, 64},  /* sub_wnd_rect */ 
        {153, 159},          /* sub_bg_pos */             

        /* icons */      
        #ifdef __OP01__     
        {4, 257},          /* icon_1_pos */
        {33, 257},          /* icon_2_pos */
        {62, 257},          /* icon_3_pos */                    
        {91, 257},         /* icon_4_pos */
        {120, 257},         /* icon_5_pos */
        {149, 257},         /* icon_6_pos */  
        {178, 257},         /* icon_7_pos */  
        {207, 257},             /* icon_8_pos */ 
        #else 
        {33, 257},          /* icon_1_pos */
        {62, 257},          /* icon_2_pos */
        {91, 257},          /* icon_3_pos */                    
        {120, 257},         /* icon_4_pos */
        {149, 257},         /* icon_5_pos */
        {178, 257},         /* icon_6_pos */  
        {207, 257},         /* icon_7_pos */  
        {0, 0},             /* icon_8_pos */  
        #endif
        {0, 0},             /* icon_9_pos */  
        {0, 0},             /* icon_10_pos */                  
        {0, 0},             /* icon_11_pos */                  

        /* time/cost */
        {162, 230},         /* time_pos */    
        {6, 230},           /* cost_pos */    
            
        /* scrollbar */   
        {204, 225},         /* inc_icon_pos */
        {4, 225},           /* dec_icon_pos */
        {42, 235},          /* scroll_bar_pos */    

        /* user input */
        
        {10, 230, 218, 23}, /* input_box_rect */
        {0, 221},           /* input_box_bg_pos */

        /* vk */
        {7, 261},           /* vk_0_pos */            
        {26, 261},          /* vk_1_pos */            
        {45, 261},          /* vk_2_pos */            
        {64, 261},          /* vk_3_pos */            
        {83, 261},          /* vk_4_pos */            
        {102, 261},         /* vk_5_pos */            
        {121, 261},         /* vk_6_pos */            
        {140, 261},         /* vk_7_pos */            
        {159, 261},         /* vk_8_pos */                        
        {178, 261},         /* vk_9_pos */ 
        {197, 261},         /* vk_star */    
        {216, 261},         /* vk_pound */                
        {0, 0},         /*fullscr_skin_bg_pos*/  
        {0, 58},         /*fullscr_main_wnd_pos*/  
        {159, 190},         /*fullscr_sub_wnd_pos*/   
        {0, 0},         /*fullscr_sub_bg_pos*/ 
        {93, 269},         /*fullscr_time_pos*/
           
        /* text color */
        {255, 255, 255, 0, 0, 0},    /* text color */
    };
#elif ((GDI_LCD_WIDTH == 240) && (GDI_LCD_HEIGHT == 400))
/***************************************************************************** 
 *
 * [240x320]
 *
 *****************************************************************************/
    mmi_vtcs_skin_struct g_mmi_vtcs_skin_cntx =
    {
        /* bg */
        {0, 0, 240, 20},     /* status_rect */        
        {0, 20, 240, 46},    /* title_rect */
        {0, 66, 220, 216},   /* body_rect */        
        {0, 282, 220, 41},   /* panel_0_rect */    
        {0, 323, 220, 47},   /* panel_1_rect */                   
        {0, 370, 240, 30},   /* softkey_rect */ 

        /* video window */        
        {32, 99, 176, 144},  /* main_wnd_rect */
        {157, 214, 80, 64},  /* sub_wnd_rect */ 
        {157, 214},          /* sub_bg_pos */             

        /* icons */      
        #ifdef __OP01__     
        {4, 329},          /* icon_1_pos */
        {33, 329},          /* icon_2_pos */
        {62, 329},          /* icon_3_pos */                    
        {91, 329},         /* icon_4_pos */
        {120, 329},         /* icon_5_pos */
        {149, 329},         /* icon_6_pos */  
        {178, 329},         /* icon_7_pos */  
        {207, 329},             /* icon_8_pos */ 
        #else     
        {6, 329},          /* icon_1_pos */
        {39, 329},          /* icon_2_pos */
        {72, 329},          /* icon_3_pos */                    
        {105, 329},         /* icon_4_pos */
        {138, 329},         /* icon_5_pos */
        {171, 329},         /* icon_6_pos */  
        {204, 329},         /* icon_7_pos */  
        {0, 0},             /* icon_8_pos */  
        #endif  
        {0, 0},             /* icon_9_pos */  
        {0, 0},             /* icon_10_pos */                  
        {0, 0},             /* icon_11_pos */                    

        /* time/cost */
        {149, 296},         /* time_pos */    
        {6, 296},           /* cost_pos */    
            
        /* scrollbar */   
        {201, 288},         /* inc_icon_pos */
        {5, 288},           /* dec_icon_pos */
        {45, 298},          /* scroll_bar_pos */    

        /* user input */
        
        {5, 292, 223, 25}, /* input_box_rect */
        {0, 282},           /* input_box_bg_pos */

        /* vk */
        {6, 329},           /* vk_0_pos */            
        {25, 329},          /* vk_1_pos */            
        {44, 329},          /* vk_2_pos */            
        {63, 329},          /* vk_3_pos */            
        {82, 329},          /* vk_4_pos */            
        {101, 329},         /* vk_5_pos */            
        {120, 329},         /* vk_6_pos */            
        {139, 329},         /* vk_7_pos */            
        {158, 329},         /* vk_8_pos */                        
        {177, 329},         /* vk_9_pos */ 
        {196, 329},         /* vk_star */    
        {215, 329},         /* vk_pound */                
        {0, 0},         /*fullscr_skin_bg_pos*/  
        {0, 89},         /*fullscr_main_wnd_pos*/  
        {158, 219},         /*fullscr_sub_wnd_pos*/   
        {0, 0},         /*fullscr_sub_bg_pos*/
        {82, 334},         /*fullscr_time_pos*/
           
        /* text color */
        {255, 255, 255, 0, 0, 0},    /* text color */
    };

#elif (GDI_LCD_WIDTH == 320) && (GDI_LCD_HEIGHT == 240) 
/***************************************************************************** 
 *
 * [320x240]
 *
 *****************************************************************************/
    mmi_vtcs_skin_struct g_mmi_vtcs_skin_cntx =
    {
        /* bg */
        {0, 0, 0, 0},       /* status_rect : 320x240 do not show status */        
        {0, 0, 320, 30},    /* title_rect */
        {0, 30, 320, 72},   /* body_rect */     
        {0, 144, 320, 33},  /* panel_0_rect */                 
        {0, 177, 320, 33},  /* panel_1_rect */                             
        {0, 210, 320, 30},  /* softkey_rect */ 

        /* video window */        
        {21, 32, 176, 144}, /* main_wnd_rect */
        {218, 73, 80, 64},  /* sub_wnd_rect */ 
        {218, 73},          /* sub_bg_pos */             

        /* icons */      
        {113, 179},         /* icon_1_pos */
        {142, 179},         /* icon_2_pos */
        {171, 179},         /* icon_3_pos */                    
        {200, 179},         /* icon_4_pos */
        {229, 179},         /* icon_5_pos */
        {258, 179},         /* icon_6_pos */  
        {287, 179},         /* icon_7_pos */  
        {0, 0},             /* icon_8_pos */  
        {0, 0},             /* icon_9_pos */  
        {0, 0},             /* icon_10_pos */                  
        {0, 0},             /* icon_11_pos */                    

        /* time/cost */
        {6, 185},           /* time_pos */    
        {6, 185},           /* cost_pos */    

        /* scrollbar */   
        {258, 146},         /* inc_icon_pos */
        {6, 146},           /* dec_icon_pos */
        {69, 156},          /* scroll_bar_pos */    

        /* user input */
        {10, 155, 300, 23}, /* input_box_rect */
        {0, 144},           /* input_box_bg_pos */
            
        /* vk */
        {239, 179},         /* vk_0_pos */            
        {5, 179},           /* vk_1_pos */            
        {31, 179},          /* vk_2_pos */            
        {57, 179},          /* vk_3_pos */            
        {83, 179},          /* vk_4_pos */            
        {109, 179},         /* vk_5_pos */            
        {135, 179},         /* vk_6_pos */            
        {161, 179},         /* vk_7_pos */            
        {187, 179},         /* vk_8_pos */                        
        {213, 179},         /* vk_9_pos */ 
        {265, 179},         /* vk_star */    
        {291, 179},         /* vk_pound */                
        {0, 0},         /*fullscr_skin_bg_pos*/  
        {0, 0},         /*fullscr_main_wnd_pos*/  
        {0, 0},         /*fullscr_sub_wnd_pos*/   
        {0, 0},         /*fullscr_sub_bg_pos*/
        {0, 0},         /*fullscr_time_pos*/
           
        /* text color */
        {255, 255, 255, 0, 0, 0},    /* text color */
    };

#elif (GDI_LCD_WIDTH == 320) && (GDI_LCD_HEIGHT == 480) 
/***************************************************************************** 
 *
 * [320x240]
 *
 *****************************************************************************/
    mmi_vtcs_skin_struct g_mmi_vtcs_skin_cntx =
    {
        /* bg */
        {0, 0, 0, 0},       /* status_rect : 320x240 do not show status */        
        {0, 20, 320, 44},    /* title_rect */
        {0, 64, 320, 260},   /* body_rect */     
        {0, 324, 320, 51},  /* panel_0_rect */                 
        {0, 379, 320, 55},  /* panel_1_rect */                             
        {0, 444, 320, 36},  /* softkey_rect */ 

        /* video window */        
        {27, 102, 176, 144}, /* main_wnd_rect */
        {215, 228, 80, 64},  /* sub_wnd_rect */ 
        {215, 228},          /* sub_bg_pos */             

        /* icons */      
        {12, 387},         /* icon_1_pos */
        {55, 387},         /* icon_2_pos */
        {98, 387},         /* icon_3_pos */                    
        {141, 387},         /* icon_4_pos */
        {184, 387},         /* icon_5_pos */
        {227, 387},         /* icon_6_pos */  
        {270, 387},         /* icon_7_pos */ 
        {0, 0},             /* icon_8_pos */  
        {0, 0},             /* icon_9_pos */  
        {0, 0},             /* icon_10_pos */                  
        {0, 0},             /* icon_11_pos */                    

        /* time/cost */
        {226, 344},           /* time_pos */    
        {12, 344},           /* cost_pos */    

        /* scrollbar */   
        {266, 331},         /* inc_icon_pos */
        {12, 331},           /* dec_icon_pos */
        {67, 347},          /* scroll_bar_pos */    

        /* user input */
        {15, 345, 289, 28}, /* input_box_rect */
        {0, 324},           /* input_box_bg_pos */
            
        /* vk */
        {4, 387},         /* vk_0_pos */            
        {30, 387},           /* vk_1_pos */            
        {56, 387},          /* vk_2_pos */            
        {82, 387},          /* vk_3_pos */            
        {108, 387},          /* vk_4_pos */            
        {134, 387},         /* vk_5_pos */            
        {160, 387},         /* vk_6_pos */            
        {186, 387},         /* vk_7_pos */            
        {212, 387},         /* vk_8_pos */                        
        {238, 387},         /* vk_9_pos */ 
        {264, 387},         /* vk_star */    
        {290, 387},         /* vk_pound */                
        {0, 0},         /*fullscr_skin_bg_pos*/  
        {0, 0},         /*fullscr_main_wnd_pos*/  
        {0, 0},         /*fullscr_sub_wnd_pos*/   
        {0, 0},         /*fullscr_sub_bg_pos*/ 
        {0, 0},         /*fullscr_time_pos*/
           
        /* text color */
        {255, 255, 255, 0, 0, 0},    /* text color */
    };
    
#elif (GDI_LCD_WIDTH == 360) && (GDI_LCD_HEIGHT == 640) 
/***************************************************************************** 
 *
 * [320x240]
 *
 *****************************************************************************/
    mmi_vtcs_skin_struct g_mmi_vtcs_skin_cntx =
    {
        /* bg */
        {0, 0, 0, 0},       /* status_rect : 320x240 do not show status */        
        {0, 20, 320, 44},    /* title_rect */
        {0, 64, 320, 260},   /* body_rect */     
        {0, 324, 320, 51},  /* panel_0_rect */                 
        {0, 379, 320, 55},  /* panel_1_rect */                             
        {0, 444, 320, 36},  /* softkey_rect */ 

        /* video window */        
        {27, 102, 176, 144}, /* main_wnd_rect */
        {215, 228, 80, 64},  /* sub_wnd_rect */ 
        {215, 228},          /* sub_bg_pos */             

        /* icons */      
        {12, 387},         /* icon_1_pos */
        {55, 387},         /* icon_2_pos */
        {98, 387},         /* icon_3_pos */                    
        {141, 387},         /* icon_4_pos */
        {184, 387},         /* icon_5_pos */
        {227, 387},         /* icon_6_pos */  
        {270, 387},         /* icon_7_pos */  
        {0, 0},             /* icon_8_pos */  
        {0, 0},             /* icon_9_pos */  
        {0, 0},             /* icon_10_pos */                  
        {0, 0},             /* icon_11_pos */                     

        /* time/cost */
        {226, 344},           /* time_pos */    
        {12, 344},           /* cost_pos */    

        /* scrollbar */   
        {266, 331},         /* inc_icon_pos */
        {12, 331},           /* dec_icon_pos */
        {67, 347},          /* scroll_bar_pos */    

        /* user input */
        {15, 345, 289, 28}, /* input_box_rect */
        {0, 324},           /* input_box_bg_pos */
            
        /* vk */
        {4, 387},         /* vk_0_pos */            
        {30, 387},           /* vk_1_pos */            
        {56, 387},          /* vk_2_pos */            
        {82, 387},          /* vk_3_pos */            
        {108, 387},          /* vk_4_pos */            
        {134, 387},         /* vk_5_pos */            
        {160, 387},         /* vk_6_pos */            
        {186, 387},         /* vk_7_pos */            
        {212, 387},         /* vk_8_pos */                        
        {238, 387},         /* vk_9_pos */ 
        {264, 387},         /* vk_star */    
        {290, 387},         /* vk_pound */                
        {0, 0},         /*fullscr_skin_bg_pos*/  
        {0, 0},         /*fullscr_main_wnd_pos*/  
        {0, 0},         /*fullscr_sub_wnd_pos*/   
        {0, 0},         /*fullscr_sub_bg_pos*/
        {0, 0},         /*fullscr_time_pos*/
           
        /* text color */
        {255, 255, 255, 0, 0, 0},    /* text color */
    };

#else
/***************************************************************************** 
 *
 * [AAAxBBB] Other LCD size, avoid compile error
 *
 *****************************************************************************/
    mmi_vtcs_skin_struct g_mmi_vtcs_skin_cntx =
    {
        /* bg */
        {0, 0, 1, 1},   /* status_rect */        
        {0, 0, 1, 1},   /* title_rect */
        {0, 0, 1, 1},   /* body_rect */     
        {0, 0, 1, 1},  /* panel_0_rect */                 
        {0, 0, 1, 1},  /* panel_1_rect */                             
        {0, 0, 1, 1},   /* softkey_rect */ 

        /* video window */        
        {0, 0, 1, 1},   /* main_wnd_rect */
        {0, 0, 1, 1},   /* sub_wnd_rect */ 
        {0, 0},         /* sub_bg_pos */             

        /* icons */      
        {0, 0},         /* icon_1_pos */
        {0, 0},         /* icon_2_pos */
        {0, 0},         /* icon_3_pos */                    
        {0, 0},         /* icon_4_pos */
        {0, 0},         /* icon_5_pos */
        {0, 0},         /* icon_6_pos */  
        {0, 0},         /* icon_7_pos */ 
        {0, 0},         /* icon_8_pos */  
        {0, 0},         /* icon_9_pos */  
        {0, 0},         /* icon_10_pos */                  
        {0, 0},             /* icon_11_pos */                     

        /* time/cost */
        {0, 0},         /* time_pos */    
        {0, 0},         /* cost_pos */    
            
        /* scrollbar */   
        {0, 0},         /* inc_icon_pos */
        {0, 0},         /* dec_icon_pos */
        {0, 0},         /* scroll_bar_pos */    

        /* user input */
        
        {0, 0, 1, 1},   /* input_box_rect */
        {0, 0},         /* input_box_bg_pos */

        /* vk */
        {0, 0},         /* vk_0_pos */            
        {0, 0},         /* vk_1_pos */            
        {0, 0},         /* vk_2_pos */            
        {0, 0},         /* vk_3_pos */            
        {0, 0},         /* vk_4_pos */            
        {0, 0},         /* vk_5_pos */            
        {0, 0},         /* vk_6_pos */            
        {0, 0},         /* vk_7_pos */            
        {0, 0},         /* vk_8_pos */                        
        {0, 0},         /* vk_9_pos */ 
        {0, 0},         /* vk_star */    
        {0, 0},         /* vk_pound */                
        {0, 0},         /*fullscr_skin_bg_pos*/  
        {0, 0},         /*fullscr_main_wnd_pos*/  
        {0, 0},         /*fullscr_sub_wnd_pos*/   
        {0, 0},         /*fullscr_sub_bg_pos*/
        {0, 0},         /*fullscr_time_pos*/
           
        /* text color */
        {255, 255, 255, 0, 0, 0},    /* text color */
    };

#endif /* (GDI_LCD_WIDTH == XXX && GDI_LCD_HEIGHT == xxx) */

#else


/***************************************************************************** 
 *
 * Customizable VT Skin     
 * [176x220]
 * [240x320]
 *
 *****************************************************************************/



#if ((GDI_LCD_WIDTH == 128) && (GDI_LCD_HEIGHT == 128))
#error "Currently, FTE VT only support with LCD 240x320 or larger, add this part if needed"
#elif ((GDI_LCD_WIDTH == 128) && (GDI_LCD_HEIGHT == 160))
#error "Currently, FTE VT only support with LCD 240x320 or larger, add this part if needed"
#elif ( (GDI_LCD_WIDTH == 176) && (GDI_LCD_HEIGHT == 220) )
#error "Currently, FTE VT only support with LCD 240x320 or larger, add this part if needed"
#elif (GDI_LCD_WIDTH == 320) && (GDI_LCD_HEIGHT == 240) 
#error "Currently, FTE VT only support vertical UI, add this part if needed"


#elif ((GDI_LCD_WIDTH == 240) && (GDI_LCD_HEIGHT == 320)) 
/***************************************************************************** 
 *
 * [240x320]
 *
 *****************************************************************************/
    mmi_vtcs_skin_struct g_mmi_vtcs_skin_cntx =
    {
        /* bg */
        {0, 0, 240, 20},     /* status_rect */        
        {0, 20, 240, 34},    /* title_rect */
        {0, 54, 240, 164},   /* body_rect */     
        {0, 218, 240, 28},   /* panel_0_rect */    
        {0, 246, 240, 36},   /* panel_1_rect */                   
        {0, 282, 240, 39},   /* softkey_rect */ 

        #ifdef __OP01__  
        /* video window */        
        {50, 59, 176, 144}, /* main_wnd_rect */
        {146, 171, 80, 64},  /* sub_wnd_rect */
        {144, 169},          /* sub_bg_pos */ 
        #else
        {32, 59, 176, 144},   /* main_wnd_rect */
        {128, 171, 80, 64},  /* sub_wnd_rect */ 
        {126, 169},          /* sub_bg_pos */ 
        #endif            

        /* icons */      
        {1, 247},          /* icon_1_pos */
        {49, 247},          /* icon_2_pos */
        {97, 247},         /* icon_3_pos */                    
        {145, 247},         /* icon_4_pos */
        {193, 247},         /* icon_5_pos */
        {9, 289},           /* icon_6_pos */  
        {199, 289},         /* icon_7_pos */ 
        {0, 73},          /* icon_8_pos */  
        {0, 103},          /* icon_9_pos */  
        {0, 133},         /* icon_10_pos */                  
        #ifdef __OP01__ 
        {0, 163},           /* icon_11_pos */ 
        #else
        {0, 0},             /* icon_11_pos */                    
        #endif                                

        /* time/cost */
        #ifdef __OP01__ 
        {14, 229},           /* time_pos */    
        {14, 229},           /* cost_pos */ 
        #else
        {9, 225},           /* time_pos */    
        {9, 225},           /* cost_pos */   
        #endif     
            
        /* scrollbar */   
        {193, 247},             /* inc_icon_pos */
        {1, 247},           /* dec_icon_pos */
        {61, 262},            /* scroll_bar_pos */    

        /* user input */
        
        {12, 79, 229, 42}, /* input_box_rect */
        {5, 68},           /* input_box_bg_pos */

        /* vk */
        {81, 232},           /* vk_0_pos */            
        {3, 124},            /* vk_1_pos */            
        {81, 124},           /* vk_2_pos */            
        {159, 124},          /* vk_3_pos */            
        {3, 160},            /* vk_4_pos */            
        {81, 160},           /* vk_5_pos */            
        {159, 160},          /* vk_6_pos */            
        {3, 196},            /* vk_7_pos */            
        {81, 196},           /* vk_8_pos */                        
        {159, 196},          /* vk_9_pos */ 
        {3, 232},            /* vk_star */    
        {159, 232},          /* vk_pound */                
        #ifdef __OP01__ 
        {0, 72},           /* contrast bg_pos */         
        #endif 
		#if defined(__MMI_FTE_VT_SUBWND_BG__)
		{144, 169},  /* subwnd_bg */
		#endif
        {0, 0},         /*fullscr_skin_bg_pos*/  
        {0, 54},         /*fullscr_main_wnd_pos*/  
        {158, 186},         /*fullscr_sub_wnd_pos*/   
        {0, 0},         /*fullscr_sub_bg_pos*/ 
        {88, 264},         /*fullscr_time_pos*/
        /* text color */
        {255, 255, 255, 0, 0, 0},    /* text color */
    };
    mmi_vtcs_line_struct g_mmi_vtcs_line_cntx =
    {           
        /* panel icon line */      
        {47, 249},          /* line_1_pos:zoom */
        {95, 249},          /* line_2_pos:ev */
        {143, 249},         /* line_3_pos:camera */                    
        {191, 249},         /* line_4_pos:speaker */                

        /* panel scrollbar line */
        {47, 249},           /* scroll_line1:- */    
        {191, 249},           /* scroll_line1:+ */      
    };
#elif ((GDI_LCD_WIDTH == 240) && (GDI_LCD_HEIGHT == 400))
/***************************************************************************** 
 *
 * [240x320]
 *
 *****************************************************************************/
    mmi_vtcs_skin_struct g_mmi_vtcs_skin_cntx =
    {
        /* bg */
        {0, 0, 240, 20},     /* status_rect */        
        {0, 20, 240, 42},    /* title_rect */
        {0, 62, 240, 215},   /* body_rect */        
        {0, 277, 240, 42},   /* panel_0_rect */    
        {0, 319, 240, 37},   /* panel_1_rect */                   
        {0, 356, 240, 44},   /* softkey_rect */ 

        
        #ifdef __OP01__  
        /* video window */        
        {47, 84, 176, 144}, /* main_wnd_rect */
        {143, 230, 80, 64},  /* sub_wnd_rect */
        {143, 230},          /* sub_bg_pos */ 
        #else
        {32, 82, 176, 144},   /* main_wnd_rect */
        {128, 228, 80, 64},  /* sub_wnd_rect */ 
        {128, 228},          /* sub_bg_pos */ 
        #endif              

        /* icons */      
        {1, 320},          /* icon_1_pos */
        {49, 320},          /* icon_2_pos */
        {97, 320},         /* icon_3_pos */                    
        {145, 320},         /* icon_4_pos */
        {193, 320},         /* icon_5_pos */
        {9, 367},           /* icon_6_pos */  
        {199, 367},         /* icon_7_pos */  
        {0, 97},         /* icon_8_pos */  
        {0, 127},         /* icon_9_pos */  
        {0, 157},         /* icon_10_pos */                  
        #ifdef __OP01__ 
        {0, 187},           /* icon_11_pos */ 
        #else
        {0, 0},             /* icon_11_pos */                     
        #endif                             

        /* time/cost */
        {14, 293},          /* time_pos */    
        {14, 293},          /* cost_pos */    
            
        /* scrollbar */   
        {193, 320},         /* inc_icon_pos */
        {1, 320},           /* dec_icon_pos */
        {61, 335},          /* scroll_bar_pos */    

        /* user input */
        
        {12, 97, 230, 43}, /* input_box_rect */
        {6, 86},           /* input_box_bg_pos */

        /* vk */
        {82, 289},           /* vk_0_pos */            
        {3, 145},          /* vk_1_pos */            
        {82, 145},          /* vk_2_pos */            
        {161, 145},          /* vk_3_pos */            
        {3, 193},          /* vk_4_pos */            
        {82, 193},         /* vk_5_pos */            
        {161, 193},         /* vk_6_pos */            
        {3, 241},         /* vk_7_pos */            
        {82, 241},         /* vk_8_pos */                        
        {161, 241},         /* vk_9_pos */ 
        {3, 289},         /* vk_star */    
        {161, 289},         /* vk_pound */                
        #ifdef __OP01__ 
        {0, 97},           /* contrast bg_pos */         
        #endif
		#if defined(__MMI_FTE_VT_SUBWND_BG__)
		{0, 0},  /* subwnd_bg */
        #endif 
        {0, 0},         /*fullscr_skin_bg_pos*/  
        {0, 82},         /*fullscr_main_wnd_pos*/  
        {158, 214},         /*fullscr_sub_wnd_pos*/   
        {0, 0},         /*fullscr_sub_bg_pos*/
        {82, 322},         /*fullscr_time_pos*/
        /* text color */
        {255, 255, 255, 0, 0, 0},    /* text color */
    };
    mmi_vtcs_line_struct g_mmi_vtcs_line_cntx =
    {           
        /* panel icon line */      
        {49, 319},          /* line_1_pos:zoom */
        {97, 319},          /* line_2_pos:ev */
        {145, 319},         /* line_3_pos:camera */                    
        {193, 319},         /* line_4_pos:speaker */                

        /* panel scrollbar line */
        {49, 319},           /* scroll_line1:- */    
        {193, 319},           /* scroll_line1:+ */      
    };

#elif (GDI_LCD_WIDTH == 320) && (GDI_LCD_HEIGHT == 480) 
/***************************************************************************** 
 *
 * [320x240]
 *
 *****************************************************************************/
    mmi_vtcs_skin_struct g_mmi_vtcs_skin_cntx =
    {
        /* bg */
        {0, 0, 320, 20},      /* status_rect : 320x240 do not show status */        
        {0, 20, 320, 52},     /* title_rect */
        {0, 72, 320, 295},    /* body_rect */     
        {0, 317, 320, 49},    /* panel_0_rect */                 
        {0, 366, 320, 64},    /* panel_1_rect */                             
        {0, 430, 320, 50},    /* softkey_rect */ 

        /* video window */        
       	#ifdef __OP01__       
        {87, 106, 176, 144}, /* main_wnd_rect */
        {183, 262, 80, 64},  /* sub_wnd_rect */
        {183, 262},          /* sub_bg_pos */ 
        #else
        {72, 107, 176, 144}, /* main_wnd_rect */
        {168, 261, 80, 64},  /* sub_wnd_rect */ 
        {168, 261},          /* sub_bg_pos */             
        #endif
            

        /* icons */      
        {7, 376},          /* icon_1_pos */
        {71, 376},          /* icon_2_pos */
        {135, 376},         /* icon_3_pos */                    
        {199, 376},         /* icon_4_pos */
        {263, 376},         /* icon_5_pos */
        {11, 436},           /* icon_6_pos */  
        {265, 436},         /* icon_7_pos */  
        {0, 102},         /* icon_8_pos */  
        {0, 141},         /* icon_9_pos */  
        {0, 180},         /* icon_10_pos */                  
        #ifdef __OP01__ 
        {0, 219},           /* icon_11_pos */ 
        #else
        {0, 0},           /* icon_11_pos */          
        #endif                    

        /* time/cost */
        #ifdef __OP01__ 
        {25, 341},           /* time_pos */    
        {25, 341},           /* cost_pos */ 
        #else
        {27, 335},           /* time_pos */    
        {27, 335},           /* cost_pos */    
        #endif 

        /* scrollbar */   
        {263, 376},         /* inc_icon_pos */
        {7, 376},           /* dec_icon_pos */
        {80, 393},          /* scroll_bar_pos */    

        /* user input */
        {15, 120, 302, 65}, /* input_box_rect */
        {9, 102},           /* input_box_bg_pos */
            
        /* vk */
        {110, 349},        /* vk_0_pos */            
        {7, 181},          /* vk_1_pos */            
        {110, 181},        /* vk_2_pos */            
        {213, 181},        /* vk_3_pos */            
        {7, 237},          /* vk_4_pos */            
        {110, 237},        /* vk_5_pos */            
        {213, 237},        /* vk_6_pos */            
        {7, 293},          /* vk_7_pos */            
        {110, 293},        /* vk_8_pos */                        
        {213, 293},        /* vk_9_pos */ 
        {7, 349},          /* vk_star */    
        {213, 349},        /* vk_pound */                
           
        #ifdef __OP01__ 
        {0, 102},           /* contrast bg_pos */          
        #endif 
        #if defined(__MMI_FTE_VT_SUBWND_BG__)
		{0, 0},  /* subwnd_bg */
		#endif
		
		{0, 0},         /*fullscr_skin_bg_pos*/  
        {0, 86},         /*fullscr_main_wnd_pos*/  
        {238, 284},         /*fullscr_sub_wnd_pos*/   
        {0, 0},         /*fullscr_sub_bg_pos*/
        {122, 391},         /*fullscr_time_pos*/
        /* text color */
        {255, 255, 255, 0, 0, 0},    /* text color */
    };
    mmi_vtcs_line_struct g_mmi_vtcs_line_cntx =
    {           
        /* panel icon line */      
        {63, 369},          /* line_1_pos:zoom */
        {127, 369},          /* line_2_pos:ev */
        {191, 369},         /* line_3_pos:camera */                    
        {255, 369},         /* line_4_pos:speaker */              
        /* panel scrollbar line */
        {63, 369},           /* scroll_line1:- */    
        {255, 369},           /* scroll_line1:+ */      
    };
#elif (GDI_LCD_WIDTH == 480) && (GDI_LCD_HEIGHT == 800) 
/***************************************************************************** 
 *
 * [320x240]
 *
 *****************************************************************************/
    mmi_vtcs_skin_struct g_mmi_vtcs_skin_cntx =
    {
        /* bg */
        {0, 0, 320, 20},      /* status_rect : 320x240 do not show status */        
        {0, 20, 320, 52},     /* title_rect */
        {0, 72, 320, 294},    /* body_rect */     
        {0, 316, 320, 50},    /* panel_0_rect */                 
        {0, 366, 320, 64},    /* panel_1_rect */                             
        {0, 430, 320, 50},    /* softkey_rect */ 

        /* video window */        
        {26, 118, 176, 144}, /* main_wnd_rect */
        {214, 242, 80, 64},  /* sub_wnd_rect */ 
        {214, 242},          /* sub_bg_pos */             

        /* icons */      
        {16, 375},          /* icon_1_pos */
        {76, 375},          /* icon_2_pos */
        {136, 375},         /* icon_3_pos */                    
        {196, 375},         /* icon_4_pos */
        {256, 375},         /* icon_5_pos */
        {0, 430},           /* icon_6_pos */  
        {256, 430},         /* icon_7_pos */  
        {0, 0},             /* icon_8_pos */  
        {0, 0},             /* icon_9_pos */  
        {0, 0},             /* icon_10_pos */                  
        {0, 0},             /* icon_11_pos */                   

        /* time/cost */
        {34, 333},           /* time_pos */    
        {34, 333},           /* cost_pos */    

        /* scrollbar */   
        {253, 375},         /* inc_icon_pos */
        {18, 375},           /* dec_icon_pos */
        {80, 392},          /* scroll_bar_pos */    

        /* user input */
        {15, 120, 302, 65}, /* input_box_rect */
        {9, 102},           /* input_box_bg_pos */
            
        /* vk */
        {110, 349},        /* vk_0_pos */            
        {7, 181},          /* vk_1_pos */            
        {110, 181},        /* vk_2_pos */            
        {213, 181},        /* vk_3_pos */            
        {7, 237},          /* vk_4_pos */            
        {110, 237},        /* vk_5_pos */            
        {213, 237},        /* vk_6_pos */            
        {7, 293},          /* vk_7_pos */            
        {110, 293},        /* vk_8_pos */                        
        {213, 293},        /* vk_9_pos */ 
        {7, 349},          /* vk_star */    
        {213, 349},        /* vk_pound */                
        #ifdef __OP01__ 
        {0, 0},           /* contrast bg_pos */          
        #endif 
		#if defined(__MMI_FTE_VT_SUBWND_BG__)
		{0, 0},  /* subwnd_bg */
		#endif
        {0, 0},         /*fullscr_skin_bg_pos*/  
        {0, 0},         /*fullscr_main_wnd_pos*/  
        {0, 0},         /*fullscr_sub_wnd_pos*/   
        {0, 0},         /*fullscr_sub_bg_pos*/ 
        {0, 0},         /*fullscr_time_pos*/
        /* text color */
        {255, 255, 255, 0, 0, 0},    /* text color */
    };
    mmi_vtcs_line_struct g_mmi_vtcs_line_cntx =
    {           
        /* panel icon line */      
        {0, 0},          /* line_1_pos:zoom */
        {0, 0},          /* line_2_pos:ev */
        {0, 0},         /* line_3_pos:camera */                    
        {0, 0},         /* line_4_pos:speaker */               

        /* panel scrollbar line */
        {0, 0},           /* scroll_line1:- */    
        {0, 0},           /* scroll_line1:+ */      
    };
#else
#error "Currently, FTE VT not support this LCD size, add this part if needed"

#endif /* (GDI_LCD_WIDTH == XXX && GDI_LCD_HEIGHT == xxx) */

#endif /* __MMI_FTE_SUPPORT__ */

#endif /* __MMI_VIDEO_TELEPHONY__ */


