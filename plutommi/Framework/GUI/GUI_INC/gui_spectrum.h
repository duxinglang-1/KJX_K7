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
*  gui_spectrum.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   audio spectrum display header file
*
* Author:
* -------
 * -------
*
*==============================================================================
*           HISTORY
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

/*
 * This file contains internal UI component API, and is intended to be used by category screen module only. 
 * It's not recommended to be included in application code directly. 
 * For application developers, please include category screen header files instead (e.g., wgui_categories.h).
 */

/*****************************************************************************
 * include
 ****************************************************************************/
 
/* DOM-NOT_FOR_SDK-BEGIN */

#include "MMI_features.h"
#include "MMIDataType.h"

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
#include "gdi_datatype.h"
#include "gdi_const.h"

/* DOM-NOT_FOR_SDK-END */

/***************************************************************************** 
* Define
*****************************************************************************/

/* DOM-NOT_FOR_SDK-BEGIN */

/* <group dom_spectrum_macro>
 *  The maximum number of spectrums that can be supported in one screen. */
#define MAX_NUM_OF_SPECTRUMS      5

/* #define SPACE_FOR_SCALE           3    3 pixels are allocated for scale (both vert. and hrzntl) this include 1 lines
   ( i.e. 1 pixels) & 2 pixels for scale markings.  */
/* <group dom_spectrum_macro> */
#define DIST_BETWEEN_BARS         1     /* this is in pixels.the distance between the various different frequency structures 
                                           which may be single unit bars or multiple block bars. */
/* <group dom_spectrum_macro> */
#define BLOCK_HEIGHT              2     /* the height of each block in the block */
/* <group dom_spectrum_macro> */
#define DIST_BETWEEN_BLOCKS       1     /* this is used for vertical distance between the blocks and the vert. dist. between 
                                           horizontal scale line and bars */
/* <group dom_spectrum_macro> */
#define MIN_BAR_WIDTH             2     /* this is the minimum bar width for checking the width parameter in Init function. */
/* <group dom_spectrum_macro> */
#define NUM_OF_COLOR_COMPONENTS 3
/* <group dom_spectrum_macro> */
#define SPECTRUM_BKGD_COLOR_BAR_STYLE       gdi_act_color_from_rgb(0xFF,0,0,0)  /* black color for the background in bar style */

//block style colors
//#define SPECTRUM_BKGD_COLOR_BLOCK_STYLE                gdi_act_color_from_rgb(0xFF,145,201,200)     //blue for bkgd in block style.
/* <group dom_spectrum_macro> */
#define SPECTRUM_BKGD_COLOR_BLOCK_STYLE   GDI_COLOR_TRANSPARENT
/* <group dom_spectrum_macro> */
#define SPECTRUM_BLOCK_RED_COMPONENT         255
/* <group dom_spectrum_macro> */
#define SPECTRUM_BLOCK_BLUE_COMPONENT        35
/* <group dom_spectrum_macro> */
#define SPECTRUM_TOP_INDICATOR_COLOR_BLOCK_STYLE       gdi_act_color_from_rgb(0xFF,255,0,0)
/* <group dom_spectrum_macro> */
#define SPECTRUM_TOP_INDICATOR_COLOR_BAR_STYLE      gdi_act_color_from_rgb(0xFF,255,0,0)
/* <group dom_spectrum_macro> */
#define SPECTRUM_SCALE_COLOR            gdi_act_color_from_rgb(0xFF,69,139,141)
/* <group dom_spectrum_macro> */
#define SPACE_TO_BE_LEFT_FOR_CIRCLES_STYLE    10
/* DOM-NOT_FOR_SDK-END */


/***************************************************************************** 
* Typedef 
*****************************************************************************/

/* <group dom_spectrum_enum>
 *  Enum values of spectrum which are used to describe different display styles. */
typedef enum
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    STYLE_OFF,
    /* DOM-NOT_FOR_SDK-END */

    /* Is an enum value which represents block style of spectrum */
    STYLE_BLOCKS,
    /* Is an enum value which represents bar style of spectrum */
    STYLE_BARS,
    /* Is an enum value which represents circle style of spectrum */
    STYLE_CIRCLES
} SPECTRUM_STYLE_ENUM;


/* <group dom_spectrum_struct>
 *  spectrum struct */
typedef struct
{
    /* Is the x position of spectrum */
    S16 start_x;
    /* Is the y position of spectrum */
    S16 start_y;
    /* Is the width of spectrum */
    S32 width;
    /* Is the height of spectrum */
    S32 height;
    /* Is the number of spectrum's bar */
    S16 number_of_bars;
    /* Is the target layer of spectrum */
    GDI_HANDLE target_layer;
    /* Is the target lcd of spectrum */
    GDI_HANDLE target_lcd;
    /* Is the style of spectrum */
    S8 style;
    /* Is the active state of spectrum */
    BOOL active;
    /* before draw spectrum callback function */
    void (*draw_callback) (S32 x1, S32 y1, S32 x2, S32 y2);/*draw before callback funtion*/
} spectrum_struct;

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
/* functions */


/*****************************************************************************
 * <group dom_spectrum_gui_layer_basic>
 * FUNCTION
 *  mmi_audio_spectrum_init_display
 * DESCRIPTION
 *  Init the spectrum and clear spectrum's display area.
 * PARAMETERS
 *  spectrum         : [IN] Is the spectrum object
 * RETURNS
 *  BOOL
 *****************************************************************************/
extern BOOL mmi_audio_spectrum_init_display(spectrum_struct *spectrum);


/*****************************************************************************
 * <group dom_spectrum_gui_layer_misc>
 * FUNCTION
 *  mmi_audio_spectrum_start_display
 * DESCRIPTION
 *  Start the display of spectrum.
 * PARAMETERS
 *  spectrum         : [IN] Is the spectrum object
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_audio_spectrum_start_display(spectrum_struct *spectrum);


/* DOM-NOT_FOR_SDK-BEGIN */

extern void mmi_audio_spectrum_display_timer(void);

/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */

extern void mmi_audio_spectrum_redraw_display(spectrum_struct *spectrum, U8 *amplitude_val, U8 *top);

/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */

extern void mmi_audio_spectrum_clear_display(spectrum_struct *spectrum);

/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * <group dom_spectrum_gui_layer_misc>
 * FUNCTION
 *  mmi_audio_spectrum_stop_display
 * DESCRIPTION
 *  Stop the display of spectrum.
 * PARAMETERS
 *  spectrum         : [IN] Is the spectrum object
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_audio_spectrum_stop_display(spectrum_struct *spectrum);

#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 


