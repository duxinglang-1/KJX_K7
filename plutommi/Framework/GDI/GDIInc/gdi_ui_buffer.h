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
 *  gdi_ui_buffer.h
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __GDI_UI_BUFFER_H__
#define __GDI_UI_BUFFER_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "gdi_include.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define AL8(N) ((N+7)&~0x7)

#define GDI_MAINLCD_BUFFER_SIZE ((AL8(GDI_LCD_WIDTH) * AL8(GDI_LCD_HEIGHT) * MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL + 7) >> 3)
    
#ifdef __MMI_SUBLCD__
    #define GDI_SUBLCD_BUFFER_SIZE ((AL8(GDI_SUBLCD_WIDTH) * AL8(GDI_SUBLCD_HEIGHT) * MMI_SUB_BASE_LAYER_BITS_PER_PIXEL + 7) >> 3)
#else 
    #define GDI_SUBLCD_BUFFER_SIZE   0
#endif 
    
#if defined(MAIN_MEDIA_LAYER_BITS_PER_PIXEL) && (MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24)
    #define GDI_MAIN_MEDIA_LAYER_SIZE	((GDI_LCD_WIDTH*GDI_LCD_HEIGHT * MAIN_MEDIA_LAYER_BITS_PER_PIXEL + 7) >> 3)
    #if (GDI_MAINLCD_BUFFER_SIZE > GDI_MAIN_MEDIA_LAYER_SIZE)
        #define GDI_MAIN_MEDIA_LAYER_SIZE GDI_MAINLCD_BUFFER_SIZE
    #endif
    #define GDI_LAYER_BUFFER_SIZE    ((GDI_MAIN_MEDIA_LAYER_SIZE * (GDI_MAINLCD_MAX_LAYERS - 1)) \
                                         + (GDI_SUBLCD_BUFFER_SIZE * GDI_SUBLCD_MAX_LAYERS))
#else
    #if defined(GDI_USE_RGB565_TO_SHOW_BW)
    #define GDI_LAYER_BUFFER_SIZE   GDI_MAINLCD_BUFFER_SIZE
    #else
    #define GDI_LAYER_BUFFER_SIZE    ((GDI_MAINLCD_BUFFER_SIZE*(GDI_MAINLCD_MAX_LAYERS-1)) \
                                         +(GDI_SUBLCD_BUFFER_SIZE* GDI_SUBLCD_MAX_LAYERS))
    #endif
#endif

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

#endif /* __GDI_UI_BUFFER_H__ */

