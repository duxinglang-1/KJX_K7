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
 *  gdi_lcd.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI LCD header file.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _GDI_LCD_H_
#define _GDI_LCD_H_

#include "MMI_features.h"
#include "gdi_lcd_config.h"
#include "gdi_include.h"
#include "wfc.h"

 
#define GDI_LCD_LOCK_MUTEX      gdi_lcd_lock_mutex()
#define GDI_LCD_UNLOCK_MUTEX    gdi_lcd_unlock_mutex()

/* W05.52 GDI Catcher Support */
extern gdi_lcd_cntx_struct GDI_LCD_ARRAY[GDI_LCD_SUM];

typedef struct
{
    WFCContext ctx_handle;                      /* WFCContext of mainlcd blt or sublcd blt or flatten */
    WFCElement elm[GDI_LAYER_HW_LAYER_COUNT];   /* each WFCElement is a input of WFCContext */
    WFCSource  src1[GDI_LAYER_HW_LAYER_COUNT];  /* each WFCElement has two WFCSource for double buffer */
    WFCSource  src2[GDI_LAYER_HW_LAYER_COUNT];
    WFCSource* src_act;                         /* point to src1 or src2 to indicate which source is active */
    WFCSource* src_pre;                         /* point to src1 or src2 to indicate which source is previous used */
} gdi_lcd_v2_context_struct;

extern WFCDevice gdi_lcd_v2_dev;
extern gdi_lcd_v2_context_struct gdi_lcd_v2_ctx_array[];


/****************************************************************************
* Function Declar                                                              
*****************************************************************************/
extern void gdi_lcd_init(void);

/*****************************************************************************
* FUNCTION
*  gdi_lcd_lock_mutex
* DESCRIPTION
*  Lock GDI LCD mutex
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
extern void gdi_lcd_lock_mutex(void);
/*****************************************************************************
* FUNCTION
*  gdi_lcd_unlock_mutex
* DESCRIPTION
*  Unlock GDI LCD mutex
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
extern void gdi_lcd_unlock_mutex(void);

#endif /* _GDI_LCD_H_ */ 


