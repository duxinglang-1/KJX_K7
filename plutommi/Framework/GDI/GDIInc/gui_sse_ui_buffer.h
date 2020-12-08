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
 *  gui_sse_ui_buffer.h
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __GUI_SSE_UI_BUFFER_H__
#define __GUI_SSE_UI_BUFFER_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "gdi_include.h"
#include "MMI_features_type.h"
#include "MMI_features.h"
#include "MMIDataType.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
    /* pixel format */
#define GUI_SCREEN_SWITCH_EFFECT_PIXEL_BYTE_SIZE    2
#define GUI_SCREEN_SWITCH_EFFECT_LAYER_COLOR_FORMAT   ((gdi_color_format)GUI_SCREEN_SWITCH_EFFECT_PIXEL_BYTE_SIZE)
    
    /* main lcd sized buffer size */
#define GUI_SCREEN_SWITCH_EFFECT_MAIN_LCD_BUFFER_SIZE (GDI_LCD_WIDTH * GDI_LCD_HEIGHT * GUI_SCREEN_SWITCH_EFFECT_PIXEL_BYTE_SIZE)
    
    /* GUI_SCREEN_SWITCH_EEFECT_MAX_LCD_SIDE_LENGTH */
#if (GDI_LCD_WIDTH > GDI_LCD_HEIGHT)
    #define GUI_SCREEN_SWITCH_EEFECT_MAX_LCD_SIDE_LENGTH GDI_LCD_WIDTH
#else /* (MAIN_LCD_DEVICE_WIDTH > MAIN_LCD_DEVICE_HEIGHT) */
    #define GUI_SCREEN_SWITCH_EEFECT_MAX_LCD_SIDE_LENGTH GDI_LCD_HEIGHT
#endif /* (MAIN_LCD_DEVICE_WIDTH > MAIN_LCD_DEVICE_HEIGHT) */
    
    /* temp buffer for gui effect engine to do software processing, such as scaling, affine and projective transform */
#if defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_MAINLCD_480X800__)
#define GUI_SCREEN_SWITCH_EFFECT_TEMP_BUFFER_SIZE (GUI_SCREEN_SWITCH_EFFECT_MAIN_LCD_BUFFER_SIZE + 256 * GUI_SCREEN_SWITCH_EEFECT_MAX_LCD_SIDE_LENGTH * GUI_SCREEN_SWITCH_EFFECT_PIXEL_BYTE_SIZE)
#else /* defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_MAINLCD_480X800__) */
#define GUI_SCREEN_SWITCH_EFFECT_TEMP_BUFFER_SIZE (GUI_SCREEN_SWITCH_EFFECT_MAIN_LCD_BUFFER_SIZE + 176 * GUI_SCREEN_SWITCH_EEFECT_MAX_LCD_SIDE_LENGTH * GUI_SCREEN_SWITCH_EFFECT_PIXEL_BYTE_SIZE)
#endif /* defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_MAINLCD_480X800__) */

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

#endif /* __GUI_SSE_UI_BUFFER_H__ */

