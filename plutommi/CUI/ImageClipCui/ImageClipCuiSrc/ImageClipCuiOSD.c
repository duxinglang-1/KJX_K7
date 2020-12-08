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
 *  ImageClipCuiOSD.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Image Clip Cui skin main file
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
  ****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_IMAGE_CLIP_CUI__

#include "ImageClipCuiOSD.h"
#include "mmi_rp_cui_image_clip_def.h"
#include "wgui.h"
#include "gdi_lcd_config.h"

#if (LCD_WIDTH == 320) && (LCD_HEIGHT == 480)
#ifdef __MMI_FTE_SUPPORT__
cui_image_clip_skin_struct g_clip_skin_struct = 
{
    // work_rect
    {0, MMI_STATUS_BAR_HEIGHT, GDI_LCD_WIDTH, GDI_LCD_HEIGHT - MMI_STATUS_BAR_HEIGHT - MMI_SOFTKEY_BAR_HEIGHT},
    
    {100, 388},                   // zoom in button content position
    {180, 388},                   // zoom out button content position
    
    { 80, 380, 80, 50},           // zoom in button back ground rect
    {160, 380, 80, 50},           // zoom out button back ground rect

    {85, 164, 150, 98},           // animation back ground rect
    {95, 174},                   // animation string postion
    {105, 227},                   // animation position

    { 20,  23,  30},              // clip layer bg color
    {118, 118, 118},              // bound color

    {215, 192, 66},              // animation string color
    {215, 192, 66}               // hint string color
};
#endif /* __MMI_FTE_SUPPORT__ */
#elif (LCD_WIDTH == 240) && (LCD_HEIGHT == 320)
#ifdef __MMI_FTE_SUPPORT__
cui_image_clip_skin_struct g_clip_skin_struct = 
{
    // work_rect
    {0, MMI_STATUS_BAR_HEIGHT, GDI_LCD_WIDTH, GDI_LCD_HEIGHT - MMI_STATUS_BAR_HEIGHT - MMI_SOFTKEY_BAR_HEIGHT},
    
    { 78, 250},                   // zoom in button content position
    {137, 250},                   // zoom out button content position
    
    { 60, 244, 60, 33},           // zoom in button back ground rect
    {120, 244, 60, 33},           // zoom out button back ground rect

    { 60, 110, 120, 78},           // animation back ground rect
    { 70, 120},                   // animation string postion
    { 65, 150},                   // animation position

    { 20,  23,  30},              // clip layer bg color
    {118, 118, 118},              // bound color
    
    {215, 192, 66},              // animation string color
    {215, 192, 66}               // hint string color
};
#else /* __MMI_FTE_SUPPORT__ */
cui_image_clip_skin_struct g_clip_skin_struct = 
{
    // work rect
    {0, MMI_STATUS_BAR_HEIGHT, GDI_LCD_WIDTH, GDI_LCD_HEIGHT - MMI_STATUS_BAR_HEIGHT - MMI_SOFTKEY_BAR_HEIGHT},

    { 80, 260, 20, 20},           // zoom in button rect
    {140, 260, 20, 20},           // zoom out button rect

    {60, 90},                   // animation position

    { 20,  23,  30},              // clip layer bg color
    {118, 118, 118},              // bound color
    
    {215, 192, 66}               // hint string color
};
#endif /* __MMI_FTE_SUPPORT__ */
#elif (LCD_WIDTH == 240) && (LCD_HEIGHT == 400)
#ifdef __MMI_FTE_SUPPORT__
cui_image_clip_skin_struct g_clip_skin_struct = 
{
    // work_rect
    {0, MMI_STATUS_BAR_HEIGHT, GDI_LCD_WIDTH, GDI_LCD_HEIGHT - MMI_STATUS_BAR_HEIGHT - MMI_SOFTKEY_BAR_HEIGHT},
    
    { 75, 310},                   // zoom in button content position
    {135, 310},                   // zoom out button content position
    
    { 60, 302, 60, 42},           // zoom in button back ground rect
    {120, 302, 60, 42},           // zoom out button back ground rect

    { 60, 135, 120, 78},           // animation back ground rect
    { 70, 145},                   // animation string postion
    { 65, 175},                   // animation position

    { 20,  23,  30},              // clip layer bg color
    {118, 118, 118},              // bound color
    
    {215, 192, 66},              // animation string color
    {215, 192, 66}               // hint string color
};
#else /* __MMI_FTE_SUPPORT__ */
cui_image_clip_skin_struct g_clip_skin_struct = 
{
    // work rect
    {0, MMI_STATUS_BAR_HEIGHT, GDI_LCD_WIDTH, GDI_LCD_HEIGHT - MMI_STATUS_BAR_HEIGHT - MMI_SOFTKEY_BAR_HEIGHT},

    { 70, 305, 20, 20},           // zoom in button rect
    {130, 305, 20, 20},           // zoom out button rect

    {60, 130},                   // animation position

    { 20,  23,  30},              // clip layer bg color
    {118, 118, 118},              // bound color
    
    {215, 192, 66}               // hint string color
};
#endif /* __MMI_FTE_SUPPORT__ */
#elif (LCD_WIDTH == 320) && (LCD_HEIGHT == 240)
#ifdef __MMI_FTE_SUPPORT__
cui_image_clip_skin_struct g_clip_skin_struct = 
{
    // work_rect
    {0, MMI_STATUS_BAR_HEIGHT, GDI_LCD_WIDTH, GDI_LCD_HEIGHT - MMI_STATUS_BAR_HEIGHT - MMI_SOFTKEY_BAR_HEIGHT},
    
    {105, 170},                   // zoom in button content position
    {185, 170},                   // zoom out button content position
    
    { 80, 165, 80, 33},           // zoom in button back ground rect
    {160, 165, 80, 33},           // zoom out button back ground rect

    {100, 80, 120, 78},           // animation back ground rect
    {110, 90},                   // animation string postion
    {105, 120},                   // animation position

    { 20,  23,  30},              // clip layer bg color
    {118, 118, 118},              // bound color
    
    {215, 192, 66},              // animation string color
    {215, 192, 66}               // hint string color
};
#else /* __MMI_FTE_SUPPORT__ */
cui_image_clip_skin_struct g_clip_skin_struct = 
{
    // work rect
    {0, MMI_STATUS_BAR_HEIGHT, GDI_LCD_WIDTH, GDI_LCD_HEIGHT - MMI_STATUS_BAR_HEIGHT - MMI_SOFTKEY_BAR_HEIGHT},

    {120, 185, 20, 20},           // zoom in button rect
    {180, 185, 20, 20},           // zoom out button rect

    {60, 130},                   // animation position

    { 20,  23,  30},              // clip layer bg color
    {118, 118, 118},              // bound color
    
    {215, 192, 66}               // hint string color
};
#endif /* __MMI_FTE_SUPPORT__ */
#endif

#endif /*  __MMI_IMAGE_CLIP_CUI__ */
