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
 *   resource_video_skins.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Video customization file.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h"
#if defined(__MMI_VIDEO_EDITOR__)

#include "MMIDataType.h"
#include "gdi_lcd_config.h"
#include "MMI_features_video.h"
#include "resource_vdoedt_skins.h"


/***************************************************************************** 
*
* Customizable OSD Skin     
* [176x220]
* [240x320]
*
*****************************************************************************/

#if ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )
/***************************************************************************** 
*
* [176x220]
*
*****************************************************************************/
    /* 
        1. Video Editor Mainscreen
        2. Video Editor CutScreen
    */  

    /****************************************************************************/
    /* 176X220 Video Editor Main Screen skin                                    */
    /****************************************************************************/
    extern vdoedt_osd_main_wnd_layout_sturct g_vdoedt_main_osd_cntx =
    {
        {0,0},   /* bg */
        /*play window */
        {0, 0,176,144},
        /*softkey*/
        {TRUE,                 /* is_lsk_icon */
        TRUE,                  /* is_rsk_icon */
        TRUE,                  /* is_ck_icon */                 
        {2,205},             /* icon_lsk_pos */
        {145,205},               /* icon_rsk_pos */                   
        {88,201},             /* icon_ck_pos */
        {0,0,0,0},             /* bottom bar rect, not used */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},   /* rsk */
        /* progress */
        {{13,164,0,0},              /*empty     */
        {13,164,0,0},               /*full      */
        {TRUE, 163,162},              /*forward   */
        {TRUE, 0,162}},           /*rewind    */
        /*status*/
        {{TRUE,13,148},             /* audio        */
        {TRUE,29,148},             /* frame        */
        {TRUE,45,148},             /* in effect    */
        {TRUE,61,148}},            /* out effect   */
        /*edit bar*/
        {{13,174,0, 0},              /* editbar empty*/
        {13,173, 0, 0},
        {{1,1,28,23},         /* shot 1       */
        {31,1,28,23},         /* shot 2       */
        {61,1,28,23},         /* shot 3       */
        {91,1,28,23},         /* shot 4       */
        {121,1,28,23}}},      /* shot 5       */
        /* time hh:mm:ss */
        {{TRUE,117,148},         /* h */
         {TRUE,124,148},         /* h */
        {TRUE,131,148},         /* : */
        {TRUE,133,148},         /* m */
        {TRUE,140,148},         /* m */
        {TRUE,147,148},         /* : */
        {TRUE,149,148},         /* S */
        {TRUE,156,148}}         /* S */
    };
    /****************************************************************************/
    /* 176x220 Video Editor Cut/FrameEdit Screen skin                           */
    /****************************************************************************/  
    extern vdoedt_osd_cut_layout_struct g_vdoedt_cut_osd_cntx = 
    {
        /* bg           */
        {0,0},
        /* play window  */
        {0, 0, 176,144},
        /* cut bar      */
        {{5, 156, 0, 0},
         {5, 156, 0, 0},
         {5, 156, 0, 0},
//        {TRUE, 165, 145},            /* cut out cursor */
        {TRUE, 164, 145, 0, 0}, 
        {TRUE, 122, 182},            /* cut out label */
        {TRUE,  98, 182},            /* cut out arrow*/
        {TRUE, 143, 182},
//        {TRUE,   0, 165},            /* cut in cursor*/
        {TRUE, 0, 165, 0, 0},
        {TRUE,  42, 182},            /* cut in label */
        {TRUE,  16, 182},            /* cut in arrow*/
        {TRUE,  61, 182}},
        /* soft key     */
        {TRUE,                 /* is_lsk_icon */
        TRUE,                  /* is_rsk_icon */
        TRUE,                  /* is_ck_icon */                 
        {2,205},             /* icon_lsk_pos */
        {140,205},               /* icon_rsk_pos */                   
        {88,201},             /* icon_ck_pos */
        {0,0,0,0},             /* bottom bar rect, not used */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}}   /* rsk */            
    };
    /****************************************************************************/
    /* 176x220 Video Editor Frame selection Screen skin                         */
    /****************************************************************************/  

    extern vdoedt_osd_frm_sel_layout_struct g_vdoedt_frm_sel_osd_cntx =
    {
        /* bg           */
        {0, 0},
        /* play window  */
        {0, 37, 176, 144},
        /* 2 arrow key */
        {TRUE, 70, 182},
        {TRUE, 90, 182},
        /* soft key     */
        {TRUE,                 /* is_lsk_icon */
        TRUE,                  /* is_rsk_icon */
        TRUE,                  /* is_ck_icon */
        {64,205},             /* icon_lsk_pos */
        {180,205},               /* icon_rsk_pos */
        {88,201},             /* icon_ck_pos */
        {0,0,0,0},             /* bottom bar rect, not used */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}}   /* rsk */
    };
 

#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )
/***************************************************************************** 
*
* [240x320]
*
*****************************************************************************/
    /* 
        1. Video Editor Mainscreen
        2. Video Editor CutScreen
    */  

    /****************************************************************************/
    /* 240x320 Video Editor Main Screen skin                                    */
    /****************************************************************************/
    extern vdoedt_osd_main_wnd_layout_sturct g_vdoedt_main_osd_cntx =
    {
        {0,0},   /* bg */
        /*play window */
        {32,33,176,144},
        /*softkey*/
        {TRUE,                 /* is_lsk_icon */
        TRUE,                  /* is_rsk_icon */
        TRUE,                  /* is_ck_icon */                 
        {2,300},             /* icon_lsk_pos */
        {200,300},               /* icon_rsk_pos */                   
        {120,300},             /* icon_ck_pos */
        {0,0,0,0},             /* bottom bar rect, not used */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},   /* rsk */
        /* progress */
        {{24,215},              /*empty     */
        {24,215},               /*full      */
        {TRUE, 219,215},          /*forward   */
        {TRUE, 5,215}},        /*rewind    */
        /*status*/
        {{TRUE,215,55},            /* audio        */
        {TRUE,215,80},             /* frame        */
        {TRUE, 7, 30},             /* in effect    */
        {TRUE,215,30}},            /* out effect   */
        /*edit bar*/
        {{25, 238, 0, 0},              /* editbar empty*/
        {25,  238, 0, 0},
        {{2,5,35,34},         /* shot 1       */
        {40,5,35,34},         /* shot 2       */
        {78,5,35,34},         /* shot 3       */
        {116,5,35,34},        /* shot 4       */
        {154,5,35,34}}},      /* shot 5       */
        /* time hh:mm:ss */
        {{TRUE,83,187},         /* h */
         {TRUE,95,187},         /* h */
        {TRUE,107,187},         /* : */
        {TRUE,112,187},         /* m */
        {TRUE,124,187},         /* m */
        {TRUE,136,187},         /* : */                
        {TRUE,141,187},         /* S */
        {TRUE,153,187}}         /* S */    
    };
    /****************************************************************************/
    /* 240x320 Video Editor Cut/FrameEdit Screen skin                           */
    /****************************************************************************/  
    extern vdoedt_osd_cut_layout_struct g_vdoedt_cut_osd_cntx = 
    {
        /* bg           */
        {0,0},
        /* play window  */
        {32, 33, 176,144},
        /* cut bar      */
        {{15, 212, 0, 0},
         {15, 212, 0, 0},
         {15, 212, 0, 0},
        //{TRUE, 217, 184},
        {TRUE, 215, 192, 0, 0},
        {TRUE, 170, 263},
        {TRUE, 141, 268},
        {TRUE, 208, 268},
        //{TRUE,   9, 243},
        {TRUE, 6, 245, 0, 0},
        {TRUE,  46, 263},
        {TRUE,  15, 268},
        {TRUE,  82, 268}},
        /* soft key     */
        {TRUE,                 /* is_lsk_icon */
        TRUE,                  /* is_rsk_icon */
        TRUE,                  /* is_ck_icon */                 
        {2,300},             /* icon_lsk_pos */
        {198,300},               /* icon_rsk_pos */                   
        {120,300},             /* icon_ck_pos */
        {0,0,0,0},             /* bottom bar rect, not used */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}}   /* rsk */            
    };
    /****************************************************************************/
    /* 240x320 Video Editor Frame selection Screen skin                         */
    /****************************************************************************/  

    extern vdoedt_osd_frm_sel_layout_struct g_vdoedt_frm_sel_osd_cntx =
    {
        /* bg           */
        {0, 0},
        /* play window  */
        {32, 67, 176, 144},
        /* 2 arrow key */
        {TRUE, 40, 232},
        {TRUE, 160, 232},
        /* soft key     */
        {TRUE,                 /* is_lsk_icon */
        TRUE,                  /* is_rsk_icon */
        TRUE,                  /* is_ck_icon */
        {2,300},             /* icon_lsk_pos */
        {198,300},               /* icon_rsk_pos */
        {120,300},             /* icon_ck_pos */
        {0,0,0,0},             /* bottom bar rect, not used */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}}   /* rsk */
    };
#elif ((LCD_WIDTH == 320) && (LCD_HEIGHT == 240))
/***************************************************************************** 
*
* [320x240]  Landscape
*
*****************************************************************************/
    /* 
        1. Video Editor Mainscreen
        2. Video Editor CutScreen
    */  

    /****************************************************************************/
    /* 320x240 landscape Video Editor Main Screen skin                          */
    /****************************************************************************/
    extern vdoedt_osd_main_wnd_layout_sturct g_vdoedt_main_osd_cntx =
    {
        {0,0},   /* bg */
        /*play window */
        {73 , 4, 176,144},
        /*softkey*/
        {TRUE,                 /* is_lsk_icon */
        TRUE,                  /* is_rsk_icon */
        TRUE,                  /* is_ck_icon */                 
        {2,216},             /* icon_lsk_pos */
        {280,216},               /* icon_rsk_pos */                   
        {160,216},             /* icon_ck_pos */
        {0,0,0,0},             /* bottom bar rect, not used */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},   /* rsk */
        /* progress */
        {{50,157},              /*empty     */
        {50,157},               /*full      */
        {TRUE, 273,154},          /*forward   */
        {TRUE, 23,154}},        /*rewind    */
        /*status*/
        {{TRUE,45,51},            /* audio        */
        {TRUE, 45,122},             /* frame        */
        {TRUE, 45, 75},             /* in effect    */
        {TRUE, 45, 99}},            /* out effect   */
        /*edit bar*/
        {{53, 172, 0, 0},              /* editbar empty*/
         {53, 172, 0, 0},
        {{3, 2,40,32},         /* shot 1       */
        {45, 2,40,32},         /* shot 2       */
        {87, 2,40,32},         /* shot 3       */
        {129,2,40,32},        /* shot 4       */
        {171,2,40,32}}},      /* shot 5       */
        /* time hh:mm:ss */
        {{TRUE,253,126},         /* h */
         {TRUE,262,126},         /* h */
        {TRUE,271,126},         /* : */
        {TRUE,274,126},         /* m */
        {TRUE,283,126},         /* m */
        {TRUE,292,126},         /* : */                
        {TRUE,295,126},         /* S */
        {TRUE,304,126}}         /* S */    
    };

    /****************************************************************************/
    /* 320x240 landscape Video Editor Cut/FrameEdit Screen skin                 */
    /****************************************************************************/  
    extern vdoedt_osd_cut_layout_struct g_vdoedt_cut_osd_cntx = 
    {
        /* bg           */
        {0,0},
        /* play window  */
        {73, 4, 176,144},
        /* cut bar      */
        {{20, 171, 0, 0},
         {20, 171, 0, 0},
         {20, 171, 0, 0},
        //{TRUE, 217, 184},
        {TRUE, 289, 152, 0, 0}, /* out cursor*/
        {TRUE, 272, 89},       /* out icon*/
        {TRUE, 265, 114},       /* left arrow */
        {TRUE, 286, 114},       /* right arrow */
        //{TRUE,   9, 243},
        {TRUE,  11, 193, 0, 0},
        {TRUE, 272, 26},
        {TRUE, 265, 53},
        {TRUE, 286, 53}},
        /* soft key     */
        {TRUE,                 /* is_lsk_icon */
        TRUE,                  /* is_rsk_icon */
        TRUE,                  /* is_ck_icon */                 
        {2,216},             /* icon_lsk_pos */
        {280,216},               /* icon_rsk_pos */                   
        {160,216},             /* icon_ck_pos */
        {0,0,0,0},             /* bottom bar rect, not used */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},   /* rsk */        
    };
    
    /****************************************************************************/
    /* 320x240 landscape Video Editor Frame selection Screen skin               */
    /****************************************************************************/  
    extern vdoedt_osd_frm_sel_layout_struct g_vdoedt_frm_sel_osd_cntx =
    {
        /* bg           */
        {0, 0},
        /* play window  */
        {73 , 4, 176, 144},
        /* 2 arrow key */
        {TRUE, 111, 184},
        {TRUE, 184, 184},
        /* soft key     */
        {TRUE,                 /* is_lsk_icon */
        TRUE,                  /* is_rsk_icon */
        TRUE,                  /* is_ck_icon */                 
        {2,216},             /* icon_lsk_pos */
        {280,216},               /* icon_rsk_pos */                   
        {160,216},             /* icon_ck_pos */
        {0,0,0,0},             /* bottom bar rect, not used */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},   /* rsk */

    };

#elif ((LCD_WIDTH == 240) && (LCD_HEIGHT == 400))
/***************************************************************************** 
*
*  [240X400] WQVGA
*
*****************************************************************************/
    /* 
        1. Video Editor Mainscreen
        2. Video Editor CutScreen
    */  

    /****************************************************************************/
    /* 240X400 WQVGA Video Editor Main Screen skin                              */
    /****************************************************************************/
    extern vdoedt_osd_main_wnd_layout_sturct g_vdoedt_main_osd_cntx =
    {
        {0,0},   /* bg */
        /*play window */
        {32, 75, 176,144},
        /*softkey*/
        {TRUE,                 /* is_lsk_icon */
        TRUE,                  /* is_rsk_icon */
        TRUE,                  /* is_ck_icon */                 
        {0, 0},                /* icon_lsk_pos */     /* not used now. */
        {0, 0},                /* icon_rsk_pos */ /* not used      */                  
        {120, 372},            /* icon_ck_pos */
        {0,0,0,0},             /* bottom bar rect, not used */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},   /* rsk */
        /* progress */
        {{31,246},              /*empty     */
        {31, 246},               /*full      */
        {TRUE, 214,242},          /*forward   */
        {TRUE,   6,242}},        /*rewind    */
        /*status*/
        {{TRUE,115,268},            /* audio        */
        {TRUE, 197,268},             /* frame        */
        {TRUE, 115, 268},             /* in effect    */
        {TRUE, 157, 268}},            /* out effect   */
        /*edit bar*/
        {{13, 319, 0, 0},              /* editbar empty*/
         {13, 319, 0, 0},
        {{3, 3,38,32},          /* shot 1       */
        {46, 3,38,32},          /* shot 2       */
        {89, 3,38,32},          /* shot 3       */
        {132,3,38,32},          /* shot 4       */
        {175,3,38,32}}},        /* shot 5       */
        /* time hh:mm:ss */
        {{TRUE,19,275},         /* h */
        {TRUE,30,275},         /* h */
        {TRUE,41,275},         /* : */
        {TRUE,46,275},         /* m */
        {TRUE,57,275},         /* m */
        {TRUE,68,275},         /* : */
        {TRUE,73,275},         /* S */
        {TRUE,84,275}}         /* S */
    };

    /****************************************************************************/
    /* 240X400 WQVGA Video Editor Cut/FrameEdit Screen skin                     */
    /****************************************************************************/  
    extern vdoedt_osd_cut_layout_struct g_vdoedt_cut_osd_cntx = 
    {
        /* bg           */
        {0,0},
        /* play window  */
        {32, 76, 176,144},
        /* cut bar      */
        {{25, 266, 0, 0},
         {25, 266, 0, 0},
         {25, 266, 0, 0},
        //{TRUE, 217, 184},
        {TRUE, 211, 245, 0, 0}, /* out cursor*/
        {TRUE, 144, 325},       /* out icon*/
        {TRUE, 166, 325},       /* left arrow */
        {TRUE, 188, 325},       /* right arrow */
        //{TRUE,   9, 243},
        {TRUE,  20, 283, 0, 0},
        {TRUE, 34,325},
        {TRUE, 56, 325},
        {TRUE, 78, 325}},
        /* soft key     */
        {TRUE,                 /* is_lsk_icon */
        TRUE,                  /* is_rsk_icon */
        TRUE,                  /* is_ck_icon */                 
        {0,0},               /* icon_lsk_pos */
        {0,0},              /* icon_rsk_pos */                   
        {120,372},             /* icon_ck_pos */
        {0,0,0,0},             /* bottom bar rect, not used */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},   /* rsk */        
    };
    
    /****************************************************************************/
    /* 240X400 WQVGA Video Editor Frame selection Screen skin                   */
    /****************************************************************************/  
    extern vdoedt_osd_frm_sel_layout_struct g_vdoedt_frm_sel_osd_cntx =
    {
        /* bg           */
        {0, 0},
        /* play window  */
        {32, 92, 176,144},
        /* 2 arrow key */
        {TRUE, 72 , 290},
        {TRUE, 133, 290},
        /* soft key     */
        {TRUE,                 /* is_lsk_icon */
        TRUE,                  /* is_rsk_icon */
        TRUE,                  /* is_ck_icon */                 
        {0,0},             /* icon_lsk_pos */
        {0,0},               /* icon_rsk_pos */                   
        {120,372},             /* icon_ck_pos */
        {0,0,0,0},             /* bottom bar rect, not used */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},   /* rsk */

    };
#elif ((LCD_WIDTH == 320) && (LCD_HEIGHT == 480))
/***************************************************************************** 
*
*  [320X480] WQVGA
*
*****************************************************************************/
    /* 
        1. Video Editor Mainscreen
        2. Video Editor CutScreen
    */  

    /****************************************************************************/
    /* 320X480 WQVGA Video Editor Main Screen skin                              */
    /****************************************************************************/
    extern vdoedt_osd_main_wnd_layout_sturct g_vdoedt_main_osd_cntx =
    {
        {0,0},   /* bg */
        /*play window */
        {72, 86, 176,144},
        /*softkey*/
        {TRUE,                 /* is_lsk_icon */
        TRUE,                  /* is_rsk_icon */
        TRUE,                  /* is_ck_icon */                 
        {0, 0},                /* icon_lsk_pos */     /* not used now. */
        {0, 0},                /* icon_rsk_pos */ /* not used      */                  
        {160, 445},            /* icon_ck_pos */
        {0,0,0,0},             /* bottom bar rect, not used */
        {255,255,255,0,0,0, VIDEO_TEXT_STYLE_NORMAL},   /* lsk */
        {255,255,255,0,0,0, VIDEO_TEXT_STYLE_NORMAL}},   /* rsk */
        /* progress */
        {{53,267},              /*empty     */
        {53, 267},               /*full      */
        {TRUE, 273,260},          /*forward   */
        {TRUE,   5,260}},        /*rewind    */
        /*status*/
        {{TRUE,115,268},            /* audio        */
        {TRUE, 262,299},             /* frame        */
        {TRUE, 161, 299},             /* in effect    */
        {TRUE, 206, 299}},            /* out effect   */
        /*edit bar*/
        {{26, 377, 0, 0},              /* editbar empty*/
         {26, 377, 0, 0},
        {{4,  4,50,40},          /* shot 1       */
        {58,  4,50,40},          /* shot 2       */
        {112, 4,50,40},          /* shot 3       */
        {166, 4,50,40},          /* shot 4       */
        {220 ,4,50,40}}},        /* shot 5       */
        /* time hh:mm:ss */
        {{TRUE,29,314},         /* h */
        {TRUE,42,314},         /* h */
        {TRUE,58,314},         /* : */
        {TRUE,67,314},         /* m */
        {TRUE,81,314},         /* m */
        {TRUE,97,314},         /* : */
        {TRUE,106,314},         /* S */
        {TRUE,120,314}}         /* S */
    };

    /****************************************************************************/
    /* 320X480 WQVGA Video Editor Cut/FrameEdit Screen skin                     */
    /****************************************************************************/  
    extern vdoedt_osd_cut_layout_struct g_vdoedt_cut_osd_cntx = 
    {
        /* bg           */
        {0,0},
        /* play window  */
        {72, 86, 176,144},
        /* cut bar      */
        {{24, 291, 0, 0},
         {24, 291, 0, 0},
         {24, 291, 0, 0},
        //{TRUE, 217, 184},
        {TRUE, 290, 269, 0, 0}, /* out cursor*/
        {TRUE, 179, 386},       /* out icon*/
        {TRUE, 205, 381},       /* left arrow */
        {TRUE, 255, 381},       /* right arrow */
        //{TRUE,   9, 243},
        {TRUE, 18, 320, 0, 0},
        {TRUE, 22,386},
        {TRUE, 49, 381},
        {TRUE, 99, 381}},
        /* soft key     */
        {TRUE,                 /* is_lsk_icon */
        TRUE,                  /* is_rsk_icon */
        TRUE,                  /* is_ck_icon */                 
        {0,0},               /* icon_lsk_pos */
        {0,0},              /* icon_rsk_pos */                   
        {160,445},             /* icon_ck_pos */
        {0,0,0,0},             /* bottom bar rect, not used */
        {255,255,255,0,0,0, VIDEO_TEXT_STYLE_NORMAL},   /* lsk */
        {255,255,255,0,0,0, VIDEO_TEXT_STYLE_NORMAL}},   /* rsk */        
    };
    
    /****************************************************************************/
    /* 320X480 WQVGA Video Editor Frame selection Screen skin                   */
    /****************************************************************************/  
    extern vdoedt_osd_frm_sel_layout_struct g_vdoedt_frm_sel_osd_cntx =
    {
        /* bg           */
        {0, 0},
        /* play window  */
        {72, 126, 176,144},
        /* 2 arrow key */
        {TRUE, 101 , 314},
        {TRUE, 169, 314},
        /* soft key     */
        {TRUE,                 /* is_lsk_icon */
        TRUE,                  /* is_rsk_icon */
        TRUE,                  /* is_ck_icon */                 
        {0,0},             /* icon_lsk_pos */
        {0,0},               /* icon_rsk_pos */                   
        {160,445},             /* icon_ck_pos */
        {0,0,0,0},             /* bottom bar rect, not used */
        {255,255,255,0,0,0, VIDEO_TEXT_STYLE_NORMAL},   /* lsk */
        {255,255,255,0,0,0, VIDEO_TEXT_STYLE_NORMAL}},   /* rsk */

    };
    
#else
/***************************************************************************** 
*
*  [XXXXXXXX] to avoid compile error on new platform
*
*****************************************************************************/
    /* 
        1. Video Editor Mainscreen
        2. Video Editor CutScreen
    */  

    /****************************************************************************/
    /* XXXXXXX WQVGA Video Editor Main Screen skin                              */
    /****************************************************************************/
    extern vdoedt_osd_main_wnd_layout_sturct g_vdoedt_main_osd_cntx =
    {
        {0,0},   /* bg */
        /*play window */
        {32, 75, 176,144},
        /*softkey*/
        {TRUE,                 /* is_lsk_icon */
        TRUE,                  /* is_rsk_icon */
        TRUE,                  /* is_ck_icon */                 
        {0, 0},                /* icon_lsk_pos */     /* not used now. */
        {0, 0},                /* icon_rsk_pos */ /* not used      */                  
        {120, 372},            /* icon_ck_pos */
        {0,0,0,0},             /* bottom bar rect, not used */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},   /* rsk */
        /* progress */
        {{31,246},              /*empty     */
        {31, 246},               /*full      */
        {TRUE, 214,242},          /*forward   */
        {TRUE,   6,242}},        /*rewind    */
        /*status*/
        {{TRUE,115,268},            /* audio        */
        {TRUE, 197,268},             /* frame        */
        {TRUE, 115, 268},             /* in effect    */
        {TRUE, 157, 268}},            /* out effect   */
        /*edit bar*/
        {{13, 319, 0, 0},              /* editbar empty*/
         {13, 319, 0, 0},
        {{3, 3,38,32},          /* shot 1       */
        {46, 3,38,32},          /* shot 2       */
        {89, 3,38,32},          /* shot 3       */
        {132,3,38,32},          /* shot 4       */
        {175,3,38,32}}},        /* shot 5       */
        /* time hh:mm:ss */
        {{TRUE,19,275},         /* h */
        {TRUE,30,275},         /* h */
        {TRUE,41,275},         /* : */
        {TRUE,46,275},         /* m */
        {TRUE,57,275},         /* m */
        {TRUE,68,275},         /* : */
        {TRUE,73,275},         /* S */
        {TRUE,84,275}}         /* S */
    };

    /****************************************************************************/
    /* QVGA Video Editor Cut/FrameEdit Screen skin                     */
    /****************************************************************************/  
    extern vdoedt_osd_cut_layout_struct g_vdoedt_cut_osd_cntx = 
    {
        /* bg           */
        {0,0},
        /* play window  */
        {32, 76, 176,144},
        /* cut bar      */
        {{25, 266, 0, 0},
         {25, 266, 0, 0},
         {25, 266, 0, 0},
        //{TRUE, 217, 184},
        {TRUE, 211, 245, 0, 0}, /* out cursor*/
        {TRUE, 144, 325},       /* out icon*/
        {TRUE, 166, 325},       /* left arrow */
        {TRUE, 188, 325},       /* right arrow */
        //{TRUE,   9, 243},
        {TRUE,  20, 283, 0, 0},
        {TRUE, 34,325},
        {TRUE, 56, 325},
        {TRUE, 78, 325}},
        /* soft key     */
        {TRUE,                 /* is_lsk_icon */
        TRUE,                  /* is_rsk_icon */
        TRUE,                  /* is_ck_icon */                 
        {0,0},               /* icon_lsk_pos */
        {0,0},              /* icon_rsk_pos */                   
        {120,372},             /* icon_ck_pos */
        {0,0,0,0},             /* bottom bar rect, not used */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},   /* rsk */        
    };
    
    /****************************************************************************/
    /*  WQVGA Video Editor Frame selection Screen skin                   */
    /****************************************************************************/  
    extern vdoedt_osd_frm_sel_layout_struct g_vdoedt_frm_sel_osd_cntx =
    {
        /* bg           */
        {0, 0},
        /* play window  */
        {32, 92, 176,144},
        /* 2 arrow key */
        {TRUE, 72 , 290},
        {TRUE, 133, 290},
        /* soft key     */
        {TRUE,                 /* is_lsk_icon */
        TRUE,                  /* is_rsk_icon */
        TRUE,                  /* is_ck_icon */                 
        {0,0},             /* icon_lsk_pos */
        {0,0},               /* icon_rsk_pos */                   
        {120,372},             /* icon_ck_pos */
        {0,0,0,0},             /* bottom bar rect, not used */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER},   /* lsk */
        {0,0,0,255,255,255,VIDEO_TEXT_STYLE_BORDER}},   /* rsk */

    };

#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */
    
#endif /* __MMI_VIDEO_EDITOR__ */

