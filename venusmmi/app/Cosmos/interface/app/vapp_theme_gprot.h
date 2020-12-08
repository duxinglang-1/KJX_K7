/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_theme_config.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 * -------
 *
 *============================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================
 ****************************************************************************/
#ifndef __VAPP_THEME_GPROT_H__
#define __VAPP_THEME_GPROT_H__

#include "MMI_features.h"
//
//	Support async frame
//

#if (defined(__MMI_COSMOS_DOWNLOADABLE_THEMES_SUPPORT__) || defined(__MMI_VUI_DOWNLOADABLE_APP_ICON__))
#define __MMI_THEME_DLT_SUPPORT__
#endif

#if defined(__LOW_COST_SUPPORT_COMMON__) && defined(__MMI_THEME_DLT_SUPPORT__)
#define __MMI_THEME_SUPPORT_ASYNC_IMAGE__
#endif

//
//	Solution depdency buffer size definiation
//
#ifdef __MMI_MAINLCD_480X800__ /* WVGA */

#define VAPP_THEME_CELL_CACHE_BUFFER_SIZE (40 * 1024)
#define VAPP_THEME_PREVIEW_CACHE_BUFFER_SIZE (70 * 1024)
#define VAPP_THEME_CELL_IMG_WIDTH (124)
#define VAPP_THEME_CELL_IMG_HEIGHT (207)
#define VAPP_THEME_CELL_HEIGHT (222)
#define VAPP_THEME_LCD_HEIGHT (800)
#define VAPP_THEME_HEAP_SIZE (800 * 1024)
#elif defined  __MMI_MAINLCD_320X480__ /* HVGA */

#define VAPP_THEME_CELL_CACHE_BUFFER_SIZE (25 * 1024)
#define VAPP_THEME_PREVIEW_CACHE_BUFFER_SIZE (50 * 1024)
#define VAPP_THEME_CELL_IMG_WIDTH (83)
#define VAPP_THEME_CELL_IMG_HEIGHT (125)
#define VAPP_THEME_CELL_HEIGHT (141)
#define VAPP_THEME_LCD_HEIGHT (480)
#define VAPP_THEME_HEAP_SIZE (500 * 1024)

#elif defined	__MMI_MAINLCD_240X320__ /* QVGA */

#define VAPP_THEME_CELL_CACHE_BUFFER_SIZE (20 * 1024)
#define VAPP_THEME_PREVIEW_CACHE_BUFFER_SIZE (40 * 1024)
#define VAPP_THEME_CELL_IMG_WIDTH (56)
#define VAPP_THEME_CELL_IMG_HEIGHT (75)
#define VAPP_THEME_CELL_HEIGHT (91)
#define VAPP_THEME_LCD_HEIGHT (320)
#define VAPP_THEME_HEAP_SIZE (460 * 1024)

#elif defined	__MMI_MAINLCD_240X400__ /* WQVGA */

#define VAPP_THEME_CELL_CACHE_BUFFER_SIZE (20 * 1024)
#define VAPP_THEME_PREVIEW_CACHE_BUFFER_SIZE (40 * 1024)
#define VAPP_THEME_CELL_IMG_WIDTH (56)
#define VAPP_THEME_CELL_IMG_HEIGHT (93)
#define VAPP_THEME_CELL_HEIGHT (109)
#define VAPP_THEME_LCD_HEIGHT (400)
#define VAPP_THEME_HEAP_SIZE (550 * 1024)

#else // Invalid value

#define VAPP_THEME_CELL_CACHE_BUFFER_SIZE (0)
#define VAPP_THEME_PREVIEW_CACHE_BUFFER_SIZE (0)
#define VAPP_THEME_CELL_IMG_WIDTH (0)
#define VAPP_THEME_CELL_IMG_HEIGHT (0)
#define VAPP_THEME_CELL_HEIGHT (0)
#define VAPP_THEME_LCD_HEIGHT (0)
#define VAPP_THEME_HEAP_SIZE (0)

#endif


#define VAPP_THEME_CELL_COLUMN_COUNT (3)


// Dependent on preivew page
#ifdef __MMI_THEME_DLT_SUPPORT__

#define VAPP_THEME_TOTAL_PREIVEW 	 	 (6)

// Async image working buffer for GDI
#ifdef __MMI_THEME_SUPPORT_ASYNC_IMAGE__
#define VAPP_THEME_CELL_CACHE_LEN 	 	 (0)
#define VAPP_THEME_CELL_MEM_FACTOR 	 	 (1.5)
#define VAPP_THEME_CELL_ASYNC_WORKBUFFER (VAPP_THEME_CELL_IMG_WIDTH * VAPP_THEME_CELL_IMG_HEIGHT * 2)
#else
#define VAPP_THEME_CELL_CACHE_LEN 	 	 (5)
#define VAPP_THEME_CELL_MEM_FACTOR 	 	 (10.0)
#define VAPP_THEME_CELL_ASYNC_WORKBUFFER (0)
#endif

#define VAPP_THEME_TOTAL_HEIGHT 	 (VAPP_THEME_LCD_HEIGHT * (VAPP_THEME_CELL_CACHE_LEN + 1) * VAPP_THEME_CELL_COLUMN_COUNT)

// 		(LCD_HEIGHT * (VAPP_THEME_CELL_CACHE_LEN + 1) 
//	   ----------------------------------------------- * CLOUMN_COUNT
//						CELL_HEIGHT

#define VAPP_THEME_TOTAL_CELL 		 ((VAPP_THEME_TOTAL_HEIGHT / VAPP_THEME_CELL_HEIGHT) + (VAPP_THEME_CELL_COLUMN_COUNT * 3))

#else // __MMI_THEME_DLT_SUPPORT__

#define VAPP_THEME_TOTAL_PREIVEW 	 	 (0)
#define VAPP_THEME_CELL_CACHE_LEN 	 	 (0)
#define VAPP_THEME_CELL_MEM_FACTOR 	 	 (0.0)
#define VAPP_THEME_CELL_ASYNC_WORKBUFFER (0)
#define VAPP_THEME_TOTAL_CELL        VAPP_THEME_CELL_COLUMN_COUNT

#endif //__MMI_THEME_DLT_SUPPORT__

#define VAPP_THEME_TOTAL_PREVIEW_MEM (VAPP_THEME_TOTAL_PREIVEW * VAPP_THEME_PREVIEW_CACHE_BUFFER_SIZE)

// Thumbnail + Preview
#define VAPP_THEME_ONE_CELL_MEM (VAPP_THEME_CELL_CACHE_BUFFER_SIZE + VAPP_THEME_CELL_ASYNC_WORKBUFFER)
#define VAPP_THEME_TOTAL_CELL_MEM 	 (max((VAPP_THEME_ONE_CELL_MEM * VAPP_THEME_TOTAL_CELL), VAPP_THEME_TOTAL_PREVIEW_MEM))

//
//	Interface
//

#ifdef __MMI_VUI_DOWNLOADABLE_APP_ICON__
extern 	mmi_id vapp_theme_appicon_launch(void);
#endif

//extern "C" mmi_id vapp_theme_init(mmi_event_struct *evt);

#endif /* __VAPP_THEME_GPROT_H__ */

