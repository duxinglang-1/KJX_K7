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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  Resource_bcr_skins.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  BCR Application
 *
 * Author:
 * -------
 * -------
 *                      
 *============================================================================
 *             HISTORY
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
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "mmi_features.h"
#ifdef __MMI_BCR__

#include "MMIDataType.h"
#include "gdi_lcd_config.h"
#include "MMI_features_bcr.h"
#include "resource_bcr_skins.h"

#if ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )
/***************************************************************************** 
* 
* [240x320]
* 
*****************************************************************************/
/*preview screen skin layout*/
mmi_bcr_osd_layeout_struct g_bcr_osd_cntx =
{
    /****** softkey   *********/
    {MMI_TRUE, 1, 289},      /* lsk */
    {MMI_TRUE, 201, 289},        /* rsk */

    /****** status icons ******/
    {MMI_TRUE, 96, 237}, 		/* flash */
    {MMI_TRUE, 60, 9}, 		/* ev */
    {MMI_TRUE, 104, 9}, 		/* ev_inc */
    {MMI_TRUE, 39, 9}, 		/* ev_dec */			
    {MMI_TRUE, 29, 237}, 		/* focus_mode */
    {MMI_TRUE, 112, 295}, 	    /* capture */
    {MMI_TRUE, 20, 56}, 	    /* banding */
    {MMI_TRUE, 50, 50},       /* zoom */
    {MMI_TRUE, 50, 50},       /* zoom digit*/
    {MMI_TRUE, 50, 50},       /* zoom in*/
    {MMI_TRUE, 50, 50},       /* zoom out*/
    /****** hint box ******/
    {MMI_TRUE,
    {67,87,153,255,255,255,MMI_BCR_TEXT_STYLE_BORDER}},
    /****** Softkey layer ******/
    {MMI_TRUE, 0, 280, 240, 40}, 
    /****** Hint layer ******/
    {MMI_TRUE, 0,110,240,70},
    /****** icon layer ******/
    {MMI_TRUE, 0, 0, 240, 40}, 
};


mmi_bcr_osd_layeout_struct g_bcr_osd_cntx_270 =
{
    /****** softkey   *********/
    {MMI_TRUE, 281, 209},      /* lsk */
    {MMI_TRUE, 281, 1},        /* rsk */

    /****** status icons ******/
    {MMI_TRUE, 140, 215}, 		/* flash */
    {MMI_TRUE, 45, 218}, 		/* ev */
    {MMI_TRUE, 89, 218}, 		/* ev_inc */
    {MMI_TRUE, 24, 218}, 		/* ev_dec */	
    {MMI_TRUE, 190, 215}, 		/* focus_mode */
    {MMI_TRUE, 289, 107}, 		/* capture */
    {MMI_TRUE, 20, 50}, 	    /* banding */
    {MMI_TRUE, 50, 50},       /* zoom */
    {MMI_TRUE, 50, 50},       /* zoom digit*/
    {MMI_TRUE, 50, 50},       /* zoom in*/
    {MMI_TRUE, 50, 50},       /* zoom out*/
    /****** hint box ******/
    {MMI_TRUE,
    {67,87,153,255,255,255,MMI_BCR_TEXT_STYLE_BORDER}},
    /****** Softkey layer ******/
    {MMI_TRUE, 280, 0, 40, 240}, 
    /****** Hint layer ******/
    {MMI_TRUE, 80,50,160,140},
    /****** icon layer ******/
    {MMI_TRUE, 0, 200, 240, 40}
};


#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )

/***************************************************************************** 
* 
* [320X240]
* 
*****************************************************************************/
/*preview screen skin layout*/
mmi_bcr_osd_layeout_struct g_bcr_osd_cntx =
{
    /****** softkey   *********/
    {MMI_TRUE, 1, 289},      /* lsk */
    {MMI_TRUE, 201, 289},        /* rsk */

    /****** status icons ******/
    {MMI_TRUE, 96, 237}, 		/* flash */
    {MMI_TRUE, 60, 9}, 		/* ev */
    {MMI_TRUE, 207, 9}, 		/* ev_inc */
    {MMI_TRUE, 38, 9}, 		/* ev_dec */			
    {MMI_TRUE, 29, 237}, 		/* focus_mode */
    {MMI_TRUE, 112, 295}, 	    /* capture */
    {MMI_TRUE, 20, 56}, 	    /* banding */
    {MMI_TRUE, 50, 50},       /* zoom */
    {MMI_TRUE, 50, 50},       /* zoom digit*/
    {MMI_TRUE, 50, 50},       /* zoom in*/
    {MMI_TRUE, 50, 50},       /* zoom out*/
    /****** hint box ******/
    {MMI_TRUE,
    {67,87,153,255,255,255,MMI_BCR_TEXT_STYLE_BORDER}},
    /****** Softkey layer ******/
    {MMI_TRUE, 0, 280, 240, 30}, 
    /****** Hint layer ******/
    {MMI_TRUE, 0,110,240,70},
    /****** icon layer ******/
    {MMI_TRUE, 0, 0, 240, 40}	
};


mmi_bcr_osd_layeout_struct g_bcr_osd_cntx_270 =
{
    /****** softkey   *********/
    {MMI_TRUE, 281, 209},      /* lsk */
    {MMI_TRUE, 281, 1},        /* rsk */

    /****** status icons ******/
    {MMI_TRUE, 140, 217}, 		/* flash */
    {MMI_TRUE, 45, 218}, 		/* ev */
    {MMI_TRUE, 110, 218}, 		/* ev_inc */
    {MMI_TRUE, 89, 218}, 		/* ev_dec */	
    {MMI_TRUE, 19, 215}, 		/* focus_mode */
    {MMI_TRUE, 289, 107}, 		/* capture */
    {MMI_TRUE, 20, 50}, 	    /* banding */
    {MMI_TRUE, 50, 50},       /* zoom */
    {MMI_TRUE, 50, 50},       /* zoom digit*/
    {MMI_TRUE, 50, 50},       /* zoom in*/
    {MMI_TRUE, 50, 50},       /* zoom out*/
    /****** hint box ******/
    {MMI_TRUE,{67,87,153,255,255,255,MMI_BCR_TEXT_STYLE_BORDER}},
    /****** Softkey layer ******/
    {MMI_TRUE, 220, 0, 100, 240}, 
    /****** Hint layer ******/
    {MMI_TRUE,110,60,100,100},
    /****** icon layer ******/
    {MMI_TRUE, 0, 200, 300, 40}
};


#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 480) )
/***************************************************************************** 
* 
* [320x480]
* 
*****************************************************************************/
/*preview screen skin layout*/
mmi_bcr_osd_layeout_struct g_bcr_osd_cntx =
{
    /****** softkey   *********/
    {MMI_TRUE, 1, 440},      /* lsk */
    {MMI_TRUE, 268, 440},        /* rsk */

    /****** status icons ******/
    {MMI_TRUE, 169, 10}, 		/* flash */
    {MMI_TRUE, 41, 10}, 		/* ev */
    {MMI_TRUE, 129, 10}, 		/* ev_inc */
    {MMI_TRUE, 97, 10}, 		/* ev_dec */			
    {MMI_TRUE, 10, 9}, 		/* focus_mode */
    {MMI_TRUE, 143, 450}, 	    /* capture */
    {MMI_TRUE, 20, 56}, 	    /* banding */
    {MMI_TRUE, 50, 50},       /* zoom */
    {MMI_TRUE, 50, 50},       /* zoom digit*/
    {MMI_TRUE, 50, 50},       /* zoom in*/
    {MMI_TRUE, 50, 50},       /* zoom out*/
    /****** hint box ******/
    {MMI_TRUE,
    {67,87,153,255,255,255,MMI_BCR_TEXT_STYLE_BORDER}},
    /****** Softkey layer ******/
    {MMI_TRUE, 0, 360, 320, 120}, 
    /****** Hint layer ******/
    {MMI_TRUE, 0,200,320,100},
    /****** icon layer ******/
    {MMI_TRUE, 0, 0, 320, 120}	
};


mmi_bcr_osd_layeout_struct g_bcr_osd_cntx_270 =
{
    /****** softkey   *********/
    {MMI_TRUE, 429, 281},      /* lsk */
    {MMI_TRUE, 429, 1},        /* rsk */

    /****** status icons ******/
    {MMI_TRUE, 168, 293}, 		/* flash */
    {MMI_TRUE, 52, 293}, 		/* ev */
    {MMI_TRUE, 140, 293}, 		/* ev_inc */
    {MMI_TRUE, 108, 293}, 		/* ev_dec */	
    {MMI_TRUE, 16, 293}, 		/* focus_mode */
    {MMI_TRUE, 437, 147}, 		/* capture */
    {MMI_TRUE, 20, 50}, 	    /* banding */
    {MMI_TRUE, 175, 293},       /* zoom */
    {MMI_TRUE, 194, 293},         /* zoom digit*/
    {MMI_TRUE, 224, 293},       /* zoom in*/
    {MMI_TRUE, 245, 293},       /* zoom out*/
    /****** hint box ******/
    {MMI_TRUE,{67,87,153,255,255,255,MMI_BCR_TEXT_STYLE_BORDER}},
    /****** Softkey layer ******/
    {MMI_TRUE, 300, 0, 180, 320}, 
    /****** Hint layer ******/
    {MMI_TRUE,140,110,200,100},
    /****** icon layer ******/
    {MMI_TRUE, 0, 280, 300, 40}
};


#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 400) )
/***************************************************************************** 
* 
* [240x400]
* 
*****************************************************************************/
/*preview screen skin layout*/
mmi_bcr_osd_layeout_struct g_bcr_osd_cntx =
{
    /****** softkey layer ******/
    {MMI_TRUE, 1, 369},      /* lsk */
    {MMI_TRUE, 201, 369},        /* rsk */

    /****** status icons ******/
    {MMI_TRUE, 96, 237}, 		/* flash */
    {MMI_TRUE, 60, 9}, 		/* ev */
    {MMI_TRUE, 207, 9}, 		/* ev_inc */
    {MMI_TRUE, 38, 9}, 		/* ev_dec */			
    {MMI_TRUE, 29, 237}, 		/* focus_mode */
    {MMI_TRUE, 112, 360}, 	    /* capture */
    {MMI_TRUE, 20, 56}, 	    /* banding */
    {MMI_TRUE, 50, 50},       /* zoom */
    {MMI_TRUE, 50, 50},       /* zoom digit*/
    {MMI_TRUE, 50, 50},       /* zoom in*/
    {MMI_TRUE, 50, 50},       /* zoom out*/
    /****** hint box ******/
    {MMI_TRUE,
    {67,87,153,255,255,255,MMI_BCR_TEXT_STYLE_BORDER}},
    /****** Softkey layer ******/
    {MMI_TRUE, 0, 280, 240, 30}, 
    /****** Hint layer ******/
    {MMI_TRUE, 0,110,240,70},
    /****** icon layer ******/
    {MMI_TRUE, 0, 0, 240, 40}	
};


mmi_bcr_osd_layeout_struct g_bcr_osd_cntx_270 =
{
    /****** softkey   *********/
    {MMI_TRUE, 360, 208},      /* lsk */
    {MMI_TRUE, 360, 1},        /* rsk */

    /****** status icons ******/
    {MMI_TRUE, 146, 218}, 		/* flash */
    {MMI_TRUE, 52, 218}, 		/* ev */
    {MMI_TRUE, 117, 218}, 		/* ev_inc */
    {MMI_TRUE, 96, 218}, 		/* ev_dec */	
    {MMI_TRUE, 16, 216}, 		/* focus_mode */
    {MMI_TRUE, 365, 107}, 		/* capture */
    {MMI_TRUE, 20, 50}, 	    /* banding */
    {MMI_TRUE, 175, 218},       /* zoom */
    {MMI_TRUE, 194, 218},         /* zoom digit*/
    {MMI_TRUE, 224, 218},       /* zoom in*/
    {MMI_TRUE, 245, 218},       /* zoom out*/
    /****** hint box ******/
    {MMI_TRUE,{67,87,153,255,255,255,MMI_BCR_TEXT_STYLE_BORDER}},
    /****** Softkey layer ******/
    {MMI_TRUE, 300, 0, 100, 240}, 
    /****** Hint layer ******/
    {MMI_TRUE,100,70,200,100},
    /****** icon layer ******/
    {MMI_TRUE, 0, 200, 300, 40}
};

#elif ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )
/***************************************************************************** 
* 
* [176x220]
* 
*****************************************************************************/
/*preview screen skin layout*/
mmi_bcr_osd_layeout_struct g_bcr_osd_cntx =
{
    /****** softkey   *********/
    {MMI_TRUE, 360, 208},      /* lsk */
    {MMI_TRUE, 360, 1},        /* rsk */

    /****** status icons ******/
    {MMI_TRUE, 65, 160}, 		/* flash */
    {MMI_TRUE, 49, 2}, 		/* ev */
    {MMI_TRUE, 150, 2}, 		/* ev_inc */
    {MMI_TRUE, 29, 2}, 		/* ev_dec */			
    {MMI_TRUE, 11, 160}, 		/* af_mode */
    {MMI_TRUE, 79, 203}, 		/* capture */
    {MMI_TRUE, 112, 295}, 	    /* banding */
    {MMI_TRUE, 50, 50},       /* zoom */
    {MMI_TRUE, 50, 50},       /* zoom digit*/
    {MMI_TRUE, 50, 50},       /* zoom in*/
    {MMI_TRUE, 50, 50},       /* zoom out*/
    /****** hint box ******/
    {MMI_TRUE,
    {67,87,153,255,255,255,MMI_BCR_TEXT_STYLE_BORDER}},
    /****** Softkey layer ******/
    {MMI_TRUE, 0, 50, 176, 50}, 
    /****** Hint layer ******/
    {MMI_TRUE,0,50,176,50},
    /****** icon layer ******/
    {MMI_TRUE, 0, 0, 240, 40}
};


mmi_bcr_osd_layeout_struct g_bcr_osd_cntx_270 =
{
    /****** softkey   *********/
    {MMI_TRUE, 360, 208},      /* lsk */
    {MMI_TRUE, 360, 1},        /* rsk */
    
    /****** status icons ******/
    {MMI_TRUE, 100, 156}, 		/* flash */
    {MMI_TRUE, 25, 156}, 		/* ev */
    {MMI_TRUE, 65, 156}, 		/* ev_inc */
    {MMI_TRUE, 9, 156}, 		/* ev_dec */			
    {MMI_TRUE, 130, 156}, 		/* af_mode */
    {MMI_TRUE, 202, 80}, 		/* capture */
    {MMI_TRUE, 112, 295}, 	    /* banding */
    {MMI_TRUE, 50, 50},       /* zoom */
    {MMI_TRUE, 50, 50},       /* zoom digit*/
    {MMI_TRUE, 50, 50},       /* zoom in*/
    {MMI_TRUE, 50, 50},       /* zoom out*/
    /****** hint box ******/
    {MMI_TRUE,
    {67,87,153,255,255,255,MMI_BCR_TEXT_STYLE_BORDER}},
    /****** Softkey layer ******/
    {MMI_TRUE, 0, 280, 240, 40}, 
    /****** Hint layer ******/
    {MMI_TRUE,0,30,220,88},
    /****** icon layer ******/
    {MMI_TRUE, 0, 0, 240, 40}
};

#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */

 
#endif /* __MMI_BCR__*/

