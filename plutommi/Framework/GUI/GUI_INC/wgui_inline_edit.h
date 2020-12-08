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
 *  wgui_inline_edit.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Functions for Inline items.
 *
 *  Author:
 * -------
 *  MTK01123
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
     
     

#ifndef __WGUI_INLINE_EDIT_H__
#define __WGUI_INLINE_EDIT_H__
/* DOM-NOT_FOR_SDK-BEGIN */
/***************************************************************************** 
* Include
*****************************************************************************/

#include "ImeGprot.h"
#ifdef __MMI_TOUCH_SCREEN__
#include "kal_non_specific_general_types.h"
#endif


#ifdef __MMI_FTE_SUPPORT__ 
#include "Wgui_touch_screen.h"
#endif

#include "gui_progress_bar.h"


#include "MMI_features.h"
#include "MMIDataType.h"
#include "gui_inputs.h"
#include "gui_data_types.h"
#include "mmi_frm_input_gprot.h"
#include "gui_fixed_menus.h"
#include "kal_general_types.h"
#include "wgui.h"

#if defined(__OP01_FWPBW__)
#define __WGUI_CAT_DATE_YEAR_ONLY__
#else /* __OP01_FWPBW__ */
#undef __WGUI_CAT_DATE_YEAR_ONLY__
#endif /* __OP01_FWPBW__ */

/***************************************************************************** 
* Define
*****************************************************************************/
#define INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT  0x000000FE
    
#define INLINE_ITEM_TYPE_MASK                   0x000000FF
#define INLINE_ITEM_TYPE_CAPTION                0x00000001
#define INLINE_ITEM_TYPE_DISPLAY_ONLY           0x00000002
#define INLINE_ITEM_TYPE_TEXT_EDIT              0x00000003
#define INLINE_ITEM_TYPE_FULL_SCREEN_EDIT       0x00000004
#define INLINE_ITEM_TYPE_SELECT                 0x00000005
#define INLINE_ITEM_TYPE_USER_DEFINED_SELECT    0x00000006
#define INLINE_ITEM_TYPE_DATE                   0x00000007
#define INLINE_ITEM_TYPE_TIME                   0x00000008
#define INLINE_ITEM_TYPE_TIME_PERIOD            0x00000009
#define INLINE_ITEM_TYPE_DOW_SELECT             0x0000000A
#define INLINE_ITEM_TYPE_IP4_EDIT               0x0000000B
#define INLINE_ITEM_IMAGE_TEXT_TYPE             0x0000000C
#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
#define INLINE_ITEM_TYPE_MULTI_LINE_EDIT        0x0000000E
#define INLINE_ITEM_TYPE_MULTI_LINE_RD_ONLY     0x0000000F
#endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 
#define INLINE_ITEM_TYPE_COLOR_SELECT           0x00000010
#define INLINE_ITEM_TYPE_PROGRESS_BAR           0x00000011
#define INLINE_ITEM_TYPE_RADIO					0x00000012
#define INLINE_ITEM_TYPE_CHECKBOX				0x00000013
#if defined(__MMI_PHB_PHOTO_STICKER_SUPPORT__)
#define INLINE_ITEM_TYPE_CAPTION_THUMBNAIL		0x00000014
#endif /* __MMI_PHB_PHOTO_STICKER_SUPPORT__ */
#define INLINE_ITEM_TYPE_BUTTON					0x00000015
    
#define INLINE_ITEM_DISABLED                    0x00000100
#define INLINE_ITEM_OPEN                        0x00000200
#define INLINE_ITEM_CHANGED                     0x00000400
#define INLINE_ITEM_SELECTOR_NO_LOOP               0x00000800
#define INLINE_ITEM_LEFT_ALIGN                  0x00004000
#define INLINE_ITEM_DISABLE_HIGHLIGHT           0x00008000
#define INLINE_ITEM_JUSTIFY_MASK                0x00030000
#define INLINE_ITEM_LEFT_JUSTIFY                0x00000000
#define INLINE_ITEM_RIGHT_JUSTIFY               0x00010000
#define INLINE_ITEM_CENTER_JUSTIFY              0x00020000
#define INLINE_ITEM_BOUNDARY_MASK               0x000C0000
#define INLINE_ITEM_BOUNDARY_ON_EDIT            0x00000000
#define INLINE_ITEM_BOUNDARY_ALWAYS             0x00040000
#define INLINE_ITEM_BOUNDARY_NEVER              0x00080000
#define INLINE_ITEM_DOTTED_UNDERLINE            0x00100000
#define INLINE_ITEM_DISABLE_CURSOR_DISPLAY      0x00200000
#define INLINE_ITEM_IME_HINT                    0x00400000
#define INLINE_ITEM_ICON_IN_ITEM                0x00800000
#define INLINE_ITEM_DISPLAY_ONLY_SHOW           0X01000000    		
#define INLINE_ITEM_NO_LEADING_ZERO		0X02000000
#define INLINE_ITEM_DISPLAY_ONLY_NO_NUMKEY      0x04000000
#define INLINE_ITEM_TEXT_EDIT_FIRST_CURSOR      0x04000000
#define INLINE_ITEM_YEAR_ONLY					0x08000000


#define INLINE_PBAR_DIVIDED		 	0x00000100
#define INLINE_PBAR_SHOW_STRING  		0x00000200
#define INLINE_PBAR_SHOW_STRING_PERCENTAGE 	0x00000400
#define INLINE_PBAR_READ_ONLY		        0x00000800
#define INLINE_PBAR_FILL_GRADIENT		0x00001000

#define MMI_INLINE_ICON_RESERVED                8               /* For icon boundary */            

#if defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_INLINE_SLIM__)
#define MAX_INLINE_ITEMS   (16)
#else
#ifndef __MMI_PROF_SPLIT_MSG_TONES__
#define MAX_INLINE_ITEMS   32
#else
#define MAX_INLINE_ITEMS   38
#endif
#endif 

/* Image attachments */
#define MMI_ATTACHMENT_FILE_NAME_SIZE           12 * ENCODING_LENGTH

/* Same as MMI_EMAIL_MAX_NUM_ATTACH */
#define MAX_IMAGES_IN_INLINE_ATTACHMENT         3

#define WGUI_INLINE_EDITOR_SCR_MEM_SIZE         (5*1024 + 512)

#define MAX_INLINE_TEXT_EDIT_BUFFER_SIZE             160       /* For Email and Sns managment */

#ifdef __MMI_FTE_SUPPORT__

#if defined(__MMI_MAINLCD_240X320__)
#define INLINE_FTE_SCROLL_BAR_WIDTH         5
#define INLINE_FTE_SCROLL_BAR_GAP           1
#define INLINE_FTE_LEFT_GAP                 5
#define INLINE_FTE_ICON_CONTROL_GAP         1  
#define INLINE_FTE_ICON_SIZE                26
#define INLINE_FTE_SINGLELINE_TEXT_OFFSET   7
#define INLINE_FTE_SEPERATOR_LINE_HEIGHT    1
#define INLINE_FTE_ONE_LINE_HEIGHT          38
#define INLINE_FTE_CONTROL_HEIGHT           35
#define INLINE_FTE_CONTROL_VERTICAL_GAP(item_height)     (((item_height) - INLINE_FTE_SEPERATOR_LINE_HEIGHT - INLINE_FTE_CONTROL_HEIGHT) / 2)
#define INLINE_FTE_TWO_LINE_1_HEIGHT        31
#define INLINE_FTE_TWO_LINE_2_HEIGHT        38
#define INLINE_FTE_THREE_LINE_1_HEIGHT      31
#define INLINE_FTE_THREE_LINE_2_HEIGHT      38
#define INLINE_FTE_MULTILINE_EDIT_ROW_COUNT         3
#define INLINE_FTE_MULTILINE_READ_ONLY_ROW_COUNT    5
#define INLINE_FTE_BUTTON_RIGHT_BOUNDARY    13
#define GUI_COLOR_SELECT_FTE_BOX_VERTICAL_GAP    		(4)
#define GUI_COLOR_SELECT_FTE_BOX_BETWEEN_GAP     		(5) 
#define GUI_COLOR_SELECT_FTE_CONTROL_BORDER_WIDTH     	(3)
#define GUI_COLOR_SELECT_FTE_SELECTOR_BORDER     		(2)
#if defined(__MMI_PHB_PHOTO_STICKER_SUPPORT__)
#define INLINE_FTE_CAPTION_THUMBNAIL_WIDTH	45
#define INLINE_FTE_CAPTION_THUMBNAIL_HEIGHT	45
#define INLINE_FTE_CAPTION_THUMBNAIL_ITEM_HEIGHT	53
#define INLINE_FTE_CAPTION_THUMBNAIL_SIZE	((INLINE_FTE_CAPTION_THUMBNAIL_WIDTH*INLINE_FTE_CAPTION_THUMBNAIL_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3)
#endif /* __MMI_PHB_PHOTO_STICKER_SUPPORT__ */
#endif

#if defined(__MMI_MAINLCD_320X240__)
#define INLINE_FTE_SCROLL_BAR_WIDTH         5
#define INLINE_FTE_SCROLL_BAR_GAP           1
#define INLINE_FTE_LEFT_GAP                 5
#define INLINE_FTE_ICON_CONTROL_GAP         1  
#define INLINE_FTE_ICON_SIZE                26
#define INLINE_FTE_SINGLELINE_TEXT_OFFSET   7
#define INLINE_FTE_SEPERATOR_LINE_HEIGHT    1
#define INLINE_FTE_ONE_LINE_HEIGHT          42
#define INLINE_FTE_CONTROL_HEIGHT           35
#define INLINE_FTE_CONTROL_VERTICAL_GAP(item_height)     (((item_height) - INLINE_FTE_SEPERATOR_LINE_HEIGHT - INLINE_FTE_CONTROL_HEIGHT) / 2)
#define INLINE_FTE_TWO_LINE_1_HEIGHT        31
#define INLINE_FTE_TWO_LINE_2_HEIGHT        38
#define INLINE_FTE_THREE_LINE_1_HEIGHT      31
#define INLINE_FTE_THREE_LINE_2_HEIGHT      38
#define INLINE_FTE_MULTILINE_EDIT_ROW_COUNT         4
#define INLINE_FTE_MULTILINE_READ_ONLY_ROW_COUNT    4
#define INLINE_FTE_BUTTON_RIGHT_BOUNDARY    13
#define GUI_COLOR_SELECT_FTE_BOX_VERTICAL_GAP    		(4)
#define GUI_COLOR_SELECT_FTE_BOX_BETWEEN_GAP     		(5) 
#define GUI_COLOR_SELECT_FTE_CONTROL_BORDER_WIDTH     	(3)
#define GUI_COLOR_SELECT_FTE_SELECTOR_BORDER     		(2)
#if defined(__MMI_PHB_PHOTO_STICKER_SUPPORT__)
#define INLINE_FTE_CAPTION_THUMBNAIL_WIDTH	45
#define INLINE_FTE_CAPTION_THUMBNAIL_HEIGHT	45
#define INLINE_FTE_CAPTION_THUMBNAIL_ITEM_HEIGHT	53
#define INLINE_FTE_CAPTION_THUMBNAIL_SIZE	((INLINE_FTE_CAPTION_THUMBNAIL_WIDTH*INLINE_FTE_CAPTION_THUMBNAIL_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3)
#endif /* __MMI_PHB_PHOTO_STICKER_SUPPORT__ */
#endif

#if defined(__MMI_MAINLCD_240X400__)
#define INLINE_FTE_SCROLL_BAR_WIDTH         5
#define INLINE_FTE_SCROLL_BAR_GAP           1
#define INLINE_FTE_LEFT_GAP                 5
#define INLINE_FTE_ICON_CONTROL_GAP         1  
#define INLINE_FTE_ICON_SIZE                26
#define INLINE_FTE_SINGLELINE_TEXT_OFFSET   7
#define INLINE_FTE_SEPERATOR_LINE_HEIGHT    1
#define INLINE_FTE_ONE_LINE_HEIGHT          42
#define INLINE_FTE_CONTROL_HEIGHT           35
#define INLINE_FTE_CONTROL_VERTICAL_GAP(item_height)     (((item_height) - INLINE_FTE_SEPERATOR_LINE_HEIGHT - INLINE_FTE_CONTROL_HEIGHT) / 2)
#define INLINE_FTE_TWO_LINE_1_HEIGHT        31
#define INLINE_FTE_TWO_LINE_2_HEIGHT        38
#define INLINE_FTE_THREE_LINE_1_HEIGHT      31
#define INLINE_FTE_THREE_LINE_2_HEIGHT      38
#define INLINE_FTE_MULTILINE_EDIT_ROW_COUNT         4
#define INLINE_FTE_MULTILINE_READ_ONLY_ROW_COUNT    7
#define INLINE_FTE_BUTTON_RIGHT_BOUNDARY    13
#define GUI_COLOR_SELECT_FTE_BOX_VERTICAL_GAP    		(4)
#define GUI_COLOR_SELECT_FTE_BOX_BETWEEN_GAP     		(5) 
#define GUI_COLOR_SELECT_FTE_CONTROL_BORDER_WIDTH     	(3)
#define GUI_COLOR_SELECT_FTE_SELECTOR_BORDER     		(2)
#if defined(__MMI_PHB_PHOTO_STICKER_SUPPORT__)
#define INLINE_FTE_CAPTION_THUMBNAIL_WIDTH	45
#define INLINE_FTE_CAPTION_THUMBNAIL_HEIGHT	45
#define INLINE_FTE_CAPTION_THUMBNAIL_ITEM_HEIGHT	53
#define INLINE_FTE_CAPTION_THUMBNAIL_SIZE	((INLINE_FTE_CAPTION_THUMBNAIL_WIDTH*INLINE_FTE_CAPTION_THUMBNAIL_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3)
#endif /* __MMI_PHB_PHOTO_STICKER_SUPPORT__ */
#endif

#if defined(__MMI_MAINLCD_320X480__)
#define INLINE_FTE_SCROLL_BAR_WIDTH         5
#define INLINE_FTE_SCROLL_BAR_GAP           1
#define INLINE_FTE_LEFT_GAP                 9
#define INLINE_FTE_ICON_CONTROL_GAP         2  
#define INLINE_FTE_ICON_SIZE                34
#define INLINE_FTE_SINGLELINE_TEXT_OFFSET   8
#define INLINE_FTE_SEPERATOR_LINE_HEIGHT    1
#define INLINE_FTE_ONE_LINE_HEIGHT          46
#define INLINE_FTE_CONTROL_HEIGHT           40
#define INLINE_FTE_CONTROL_VERTICAL_GAP(item_height)     (((item_height) - INLINE_FTE_SEPERATOR_LINE_HEIGHT - INLINE_FTE_CONTROL_HEIGHT) / 2)
#define INLINE_FTE_TWO_LINE_1_HEIGHT        37
#define INLINE_FTE_TWO_LINE_2_HEIGHT        40
#define INLINE_FTE_THREE_LINE_1_HEIGHT      37
#define INLINE_FTE_THREE_LINE_2_HEIGHT      40
#define INLINE_FTE_MULTILINE_EDIT_ROW_COUNT         5
#define INLINE_FTE_MULTILINE_READ_ONLY_ROW_COUNT    7
#define INLINE_FTE_BUTTON_RIGHT_BOUNDARY    14
#define GUI_COLOR_SELECT_FTE_BOX_VERTICAL_GAP    		(4)
#define GUI_COLOR_SELECT_FTE_BOX_BETWEEN_GAP     		(5) 
#define GUI_COLOR_SELECT_FTE_CONTROL_BORDER_WIDTH     	(3)
#define GUI_COLOR_SELECT_FTE_SELECTOR_BORDER     		(2)
#if defined(__MMI_PHB_PHOTO_STICKER_SUPPORT__)
#define INLINE_FTE_CAPTION_THUMBNAIL_WIDTH	45
#define INLINE_FTE_CAPTION_THUMBNAIL_HEIGHT	45
#define INLINE_FTE_CAPTION_THUMBNAIL_ITEM_HEIGHT	53
#define INLINE_FTE_CAPTION_THUMBNAIL_SIZE	((INLINE_FTE_CAPTION_THUMBNAIL_WIDTH*INLINE_FTE_CAPTION_THUMBNAIL_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3)
#endif /* __MMI_PHB_PHOTO_STICKER_SUPPORT__ */
#endif

#if defined(__MMI_MAINLCD_480X800__)
#define INLINE_FTE_SCROLL_BAR_WIDTH         5
#define INLINE_FTE_SCROLL_BAR_GAP           1
#define INLINE_FTE_LEFT_GAP                 9
#define INLINE_FTE_ICON_CONTROL_GAP         2  
#define INLINE_FTE_ICON_SIZE                34
#define INLINE_FTE_SINGLELINE_TEXT_OFFSET   8
#define INLINE_FTE_SEPERATOR_LINE_HEIGHT    1
#define INLINE_FTE_ONE_LINE_HEIGHT          CFG_UI_MENUITEM_HEIGHT
#define INLINE_FTE_CONTROL_HEIGHT           67
#define INLINE_FTE_CONTROL_VERTICAL_GAP(item_height)     (((item_height) - INLINE_FTE_SEPERATOR_LINE_HEIGHT - INLINE_FTE_CONTROL_HEIGHT) / 2)
#define INLINE_FTE_TWO_LINE_1_HEIGHT        (CFG_UI_MENUITEM_HEIGHT - 10)
#define INLINE_FTE_TWO_LINE_2_HEIGHT        (CFG_UI_MENUITEM_HEIGHT - 6)
#define INLINE_FTE_THREE_LINE_1_HEIGHT      (CFG_UI_MENUITEM_HEIGHT - 10)
#define INLINE_FTE_THREE_LINE_2_HEIGHT      (CFG_UI_MENUITEM_HEIGHT - 6)
#define INLINE_FTE_MULTILINE_READ_ONLY_ROW_COUNT    4
#define INLINE_FTE_BUTTON_RIGHT_BOUNDARY    14
#define GUI_COLOR_SELECT_FTE_BOX_VERTICAL_GAP    		(8)
#define GUI_COLOR_SELECT_FTE_BOX_BETWEEN_GAP     		(5) 
#define GUI_COLOR_SELECT_FTE_CONTROL_BORDER_WIDTH     	(3)
#define GUI_COLOR_SELECT_FTE_SELECTOR_BORDER     		(2)
#if defined(__MMI_PHB_PHOTO_STICKER_SUPPORT__)
#define INLINE_FTE_CAPTION_THUMBNAIL_WIDTH	45
#define INLINE_FTE_CAPTION_THUMBNAIL_HEIGHT	45
#define INLINE_FTE_CAPTION_THUMBNAIL_ITEM_HEIGHT	53
#define INLINE_FTE_CAPTION_THUMBNAIL_SIZE	((INLINE_FTE_CAPTION_THUMBNAIL_WIDTH*INLINE_FTE_CAPTION_THUMBNAIL_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3)
#endif /* __MMI_PHB_PHOTO_STICKER_SUPPORT__ */
#endif

#define INLINE_FTE_MULTILINE_HEIGHT (INLINE_FTE_MULTILINE_READ_ONLY_ROW_COUNT * MMI_MENUITEM_HEIGHT)//INLINE_FTE_CONTROL_HEIGHT + 2 * INLINE_FTE_CONTROL_VERTICAL_GAP(INLINE_FTE_ONE_LINE_HEIGHT))

#endif

/* Compile Option for Slim Project */

#if defined(__MMI_INLINE_SLIM__)

#ifndef __MMI_INLINE_ITEM_TIME__
#define __MMI_INLINE_ITEM_TIME__
#endif

#ifndef __MMI_INLINE_ITEM_DATE__
#define __MMI_INLINE_ITEM_DATE__
#endif

#ifndef __MMI_INLINE_ITEM_IP4__
#define __MMI_INLINE_ITEM_IP4__
#endif

#define WGUI_INLINE_TEXT_EDIT_BUFFER_SIZE           512

#ifdef __MMI_INLINE_ITEM_TIME_PEROID__
#undef  __MMI_INLINE_ITEM_TIME_PEROID__
#endif

#endif

#ifdef __COSMOS_MMI_PACKAGE__
#ifdef __MMI_INLINE_ITEM_TIME__
#undef __MMI_INLINE_ITEM_TIME__
#endif 

#ifdef __MMI_INLINE_ITEM_DATE__
#undef __MMI_INLINE_ITEM_DATE__
#endif 

#ifdef __MMI_INLINE_ITEM_TIME_PEROID__
#undef __MMI_INLINE_ITEM_TIME_PEROID__
#endif

#ifdef __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__
#undef __MMI_INLINE_ITEM_MULTILINE_READ_ONLY__
#endif 

#ifdef __MMI_INLINE_ITEM_MULTILINE_EDIT__
#undef __MMI_INLINE_ITEM_MULTILINE_EDIT__
#endif 

#ifndef __MMI_INLINE_ITEM_IP4__
#define __MMI_INLINE_ITEM_IP4__
#endif

#else /* __COSMOS_MMI_PACKAGE__ */

#ifndef __MMI_INLINE_ITEM_TIME__
#define __MMI_INLINE_ITEM_TIME__
#endif /* __MMI_INLINE_ITEM_TIME__ */

#ifndef __MMI_INLINE_ITEM_DATE__
#define __MMI_INLINE_ITEM_DATE__
#endif /* __MMI_INLINE_ITEM_DATE__ */

#ifndef __MMI_INLINE_ITEM_IP4__
#define __MMI_INLINE_ITEM_IP4__
#endif

#endif /* __COSMOS_MMI_PACKAGE__ */

/* this feature is used for highlight caption and bellow item, only in pluto project */
#if !defined (__MMI_FTE_SUPPORT__) && !defined(__MMI_MAINLCD_96X64__)
#ifndef __MMI_INLINE_HIGHLIGHT_CAPTION__
#define __MMI_INLINE_HIGHLIGHT_CAPTION__
#endif
#endif

/***************************************************************************** 
* Typedef 
*****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
typedef enum
{
    GUI_INLINE_PEN_NONE,
    GUI_INLINE_PEN_NEED_REDRAW,
    GUI_INLINE_PEN_ITEM_SELECTED
} gui_inline_pen_enum;

typedef enum
{
    GUI_INLINE_ITEM_PEN_NONE,
    GUI_INLINE_ITEM_PEN_NEED_REDRAW_ITEM,
    GUI_INLINE_ITEM_PEN_NEED_REDRAW_MENU,
    GUI_INLINE_ITEM_PEN_SELECTED
} gui_inline_item_pen_enum;
#endif /* __MMI_TOUCH_SCREEN__ */ 

typedef struct 
{
    HILITE_STR * hilite_list;
    U16 count;
    U16 *curr_hilite_idx;
    void (*hilite_cb)(S32 idx);
    void (*click_cb)(S32 idx);
}wgui_inline_ml_rdly_highlight_list_struct;


/* Specific types of inline items   */
typedef struct _wgui_inline_item_text_edit
{
    U32 flags;
    U32 input_type;
    U16 input_ext_type; /* for 0x81 Encoding in Phone Book */
    U16 title;          /* Used only for full screen edit   */
    U16 title_icon;     /* Used only for full screen edit   */
    PU8 buffer;
    S32 buffer_size;
    PU8 mask_buffer;
	UI_buffer_type cursor_p;
    U8 max_lines;
    U8 height_of_item;
    void (*edit_complete_callback) (PU8 buffer, S32 buffer_size);
    S32 UCS2_count;
    void (*custom_setup_function) (void);
    void (*validation_callback) (UI_buffer_type text, UI_buffer_type cursor_p, S32 text_length);
#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__
    PU8 default_item_text;
#endif
#ifdef __MMI_FTE_SUPPORT__
    U32 x;
    U32 y;
    U32 width;
    U32 height;
    U8  status_flag;
#endif    
    mmi_imm_input_mode_enum *required_input_mode_set;
#ifdef __MMI_INLINE_SLIM__
    MMI_BOOL set_characters_flag;
    UI_character_type *set_characters_list;
#endif
} wgui_inline_item_text_edit;

typedef struct _wgui_inline_item_button
{
    U32 x;
    U32 y;
    U32 width;
    U32 height;
    U8  status_flag;
}wgui_inline_item_button;

typedef struct 
{
    U32 flags;
    PU8 buffer;
    U32 x;
    U32 y;
    U32 width;
    U32 height;
    U8  status_flag;
    
} wgui_inline_item_displayonly;

#if defined(__MMI_PHB_PHOTO_STICKER_SUPPORT__)
typedef struct
{
    MMI_BOOL IsFinished;
	MMI_BOOL IsSuccessed;
    PU8 thumbnail_path;
    PU8 t_buffer;
    gdi_handle decoding_layer;
    gdi_handle decoding_handle;
    S32 x1, y1;
    S32 width, height;
}Caption_thumbnail_struct;

typedef struct 
{
    U32 style;				// 1 image id : 2 thumbnail path
    U16 default_id;
    PU8 text_p;
    PU8 thumbnail_path;
	PU8 buffer_p;
    Caption_thumbnail_struct *thumbnail_struct;
} wgui_inline_item_caption_tn;
#endif /* __MMI_PHB_PHOTO_STICKER_SUPPORT__ */

typedef struct _wgui_inline_item_progress_bar
{
    U32 flags;
    gui_progress_bar_struct pbar;	
    U16* value;
    U16 max_value;
    U16 step_size;	
    void (*callback)(void);	
} wgui_inline_item_progress_bar;

typedef void (*radio_selected)(S32 index);

typedef struct
{
    U32 flags;
    S32 first_item;
    S32 n_items;
    MMI_BOOL IsSeld;
    PU8 text_p;
    radio_selected selected_callback;
}wgui_inline_item_radio;


typedef void (*checkbox_change)(S32 index);

typedef struct
{
    U32 flags;
    MMI_BOOL IsSeld;
    PU8 text_p;
    checkbox_change checkbox_change_callback;
}wgui_inline_item_checkbox;

typedef struct _wgui_inline_item_select
{
    U32 flags;
    S32 n_items;
    S32 *highlighted_item;
    PU8 *list_of_strings;
    void (*item_highlighted) (S32 item_index);
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_INLINE_SLIM__)
    U32 x;
    U32 y;
    U32 width;
    U32 height;
    U8	status_flag;
#endif /* __MMI_FTE_SUPPORT__ && __MMI_INLINE_SLIM__ */
} wgui_inline_item_select;

typedef struct _wgui_inline_item_date
{
    U32 flags;
    PU8 day_buffer;
    PU8 month_buffer;
    PU8 year_buffer;
    void (*string_construct_callback) (PU8 string_buffer, PU8 day_buffer, PU8 month_buffer, PU8 year_buffer);
} wgui_inline_item_date;

typedef struct _wgui_inline_item_time
{
    U32 flags;
    PU8 hours_buffer;
    PU8 minutes_buffer;
    PU8 seconds_buffer;
    PU8 AM_PM_flag;
    void (*string_construct_callback) (PU8 string_buffer, PU8 hours_buffer, PU8 minutes_buffer, PU8 AM_PM_flag);
} wgui_inline_item_time;

typedef struct _wgui_inline_item_user_defined_select
{
    U32 flags;
    PU8 current_text_p;
    PU8 (*current_item_callback) (void);
    PU8 (*previous_item_callback) (void);
    PU8 (*next_item_callback) (void);
} wgui_inline_item_user_defined_select;

typedef struct _wgui_inline_item_DOW_select
{
    U32 flags;
    PU8 list_of_states;
} wgui_inline_item_DOW_select;

typedef struct _wgui_inline_item_time_period
{
    U32 flags;
    PU8 hours_buffer1;
    PU8 minutes_buffer1;
    PU8 AM_PM_flag1;
    PU8 hours_buffer2;
    PU8 minutes_buffer2;
    PU8 AM_PM_flag2;
    void (*string_construct_callback) (PU8 string_buffer, PU8 hours_buffer1, PU8 minutes_buffer1,
                                       PU8 AM_PM_flag1, PU8 hours_buffer2, PU8 minutes_buffer2,
                                       PU8 AM_PM_flag2);
} wgui_inline_item_time_period;

typedef struct _wgui_inline_item_IP4
{
    U32 flags;
    PU8 b1;
    PU8 b2;
    PU8 b3;
    PU8 b4;
    void (*string_construct_callback) (PU8 string_buffer, PU8 b1, PU8 b2, PU8 b3, PU8 b4);
} wgui_inline_item_IP4;

typedef struct _wgui_inline_item_color_select
{
    U32 flags;
    U16 n_color;
    U16 highlighted_index;
    U16 start_index;
    color *list_of_color;
    void (*color_highlighted) (U16 index);
} wgui_inline_item_color_select;

typedef struct _wgui_inline_item
{
    U32 flags;
    S32 key_code;
    S32 key_event;
    PU8 text_p;
    PU8 side_img;
    U8 show_img_flag;
    void *item;
    void (*handler) (S32 x, S32 y, S32 width, S32 height, S32 key_code, S32 key_event, PU8 *text_p, void *item,
                     U32 flags, PU8 history_buffer);
} wgui_inline_item;

typedef wgui_inline_item InlineItem;

typedef struct _wgui_inline_image_text
{
    U32 flags;
    PU8 image1;
    PU8 image2;
    PU8 text;
    S32 buffer_size;
    PU8 image3;
    S32 UCS2_count;
    S32 x, y, width, height;
    wgui_inline_item_text_edit *inline_full_text;
#ifdef __MMI_TOUCH_SCREEN__
    /* Only support callback of image2 and image3 */
    FuncPtr image_callback[2];
    mmi_pen_point_struct image_left_top[2];
    mmi_pen_point_struct image_right_bottom[2];
    S16 pen_down_image_index;
    S16 pen_curr_pressed_image_index;
#endif /* __MMI_TOUCH_SCREEN__ */ 
} wgui_inline_image_text;

typedef struct _wgui_inline_images_detail
{
    U8 image_file_name[MMI_ATTACHMENT_FILE_NAME_SIZE];
    U8 type_of_image;
    PU8 image1;
} wgui_inline_images_detail;

#ifdef __MMI_FTE_SUPPORT__
typedef enum
{
    INLINE_LINE_STYLE_ONE_LINE,
    INLINE_LINE_STYLE_TWO_LINE,
    INLINE_LINE_STYLE_THREE_LINE
}inline_fte_line_style_enum;
#endif


#if defined(__MMI_INLINE_ITEM_COLOR_SELECT__)
typedef struct _gui_color_select_struct
{
    U16 region_x1, region_x2, region_y1, region_y2;
    U16 icon1_x1, icon1_x2;
    U16 icon2_x1, icon2_x2;
    U16 icon_y;
    U16 box_count;
    U16 box_size;
    U16 box_spacing;
    U8 icon1_pressed, icon2_pressed;
    U8 key_icon1, key_icon2;
#if defined(__MMI_TOUCH_SCREEN__)
    U8 pen_on_icon1;
    U8 pen_on_icon2;
#endif
    U16 x, y, width, height;
    U16 n_color;
    U16 highlighted_index;
    U16 start_index;
    color *list_of_color;
	void (*color_highlighted) (U16 index);
	U32 flags;
}gui_color_select_struct;

#define UI_COLOR_SELECT_FOCUSED_STATE          0x00000001

#define GUI_COLOR_SELECT_HEIGHT_SPACING			(3)
#define GUI_COLOR_SELECT_ICON_SPACING			(3)

#define GUI_COLOR_SELECT_INIT_START_VALUE		(255)

#endif

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
extern wgui_inline_item wgui_inline_items[MAX_INLINE_ITEMS];
extern wgui_inline_item *current_wgui_inline_item;


/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
extern BOOL UI_dummy_inline_item_pen_function(
                mmi_pen_event_type_enum pen_event,
                S16 x,
                S16 y,
                gui_inline_item_pen_enum *item_event);
extern BOOL gui_inline_translate_pen_event(
                fixed_list_menu *m,
                mmi_pen_event_type_enum pen_event,
                S16 x,
                S16 y,
                gui_inline_pen_enum *inline_event);

extern void wgui_inline_register_list_tap_callback(void (*tap_callback_funtion)(mmi_tap_type_enum tap_type,S32 index));
#endif /* __MMI_TOUCH_SCREEN__ */ 

extern void inline_edit_singleline_inputbox_delete_in_pos(S32 pos);
extern void inline_edit_singleline_inputbox_direct_input_in_pos(UI_character_type c, S32 pos);
extern MMI_BOOL inline_edit_singleline_inputbox_direct_input(UI_character_type c);

extern void ExitCategory657Screen(void);

/* For Draw Manager  */
/*****************************************************************************
 * FUNCTION
 *  wgui_get_inline_history
 * DESCRIPTION
 *  get current inline item's history buffer
 * PARAMETERS
 *  history_ID              : [IN]        history id
 *  history_buffer          : [OUT]        history buffer         
 * RETURNS
 *  history buffer
 *****************************************************************************/
extern PU8 wgui_get_inline_history(U16 history_ID, U8 *history_buffer);

/*****************************************************************************
 * FUNCTION
 *  wgui_get_inline_history_size
 * DESCRIPTION
 *  get current inline item's history size
 * PARAMETERS
 *  void
 * RETURNS
 *  history size
 *****************************************************************************/
extern S32 wgui_get_inline_history_size(void);

/*****************************************************************************
 * FUNCTION
 *  wgui_inline_edit_get_current_item_history
 * DESCRIPTION
 *  get current inline item history buffer.
 *  It Not be used now.
 * PARAMETERS
 *  history_buffer          : [OUT]   history buffer     
 * RETURNS
 *  history buffer
 *****************************************************************************/
extern PU8 wgui_inline_edit_get_current_item_history(PU8 history_buffer);

/* Signatures for MultiLine Input Box Inscreen Control. */
#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)

extern void handle_inline_multi_line_edit(
                S32 x,
                S32 y,
                S32 width,
                S32 height,
                S32 key_code,
                S32 key_event,
                PU8 *text_p,
                void *item,
                U32 flags,
                PU8 history_buffer);
extern void wgui_show_inline_inscreen_multi_line_edit(
                S32 x1,
                S32 y1,
                S32 width,
                S32 height,
                wgui_inline_item *item);
extern void gui_draw_inscreen_multi_line_input_box_title(S32 x1, S32 y1, S32 x2, S32 y2);
extern void inline_multiline_edit_clear_cursor_history(void);
extern void handle_inline_multi_line_edit_complete(void);
extern void handle_inline_full_screen_edit_close(void);
extern void handle_multi_line_rd_only_close(void);
extern void inline_multiline_edit_complete(void);
extern S8 MMI_multi_line_inputbox_present;
extern void handle_inline_multi_line_rd_only(
                S32 x,
                S32 y,
                S32 width,
                S32 height,
                S32 key_code,
                S32 key_event,
                PU8 *text_p,
                void *item,
                U32 flags,
                PU8 history_buffer);
extern void wgui_show_inline_multi_line_rd_only(S32 x1, S32 y1, S32 width, S32 height, wgui_inline_item *item);

extern S32 menu_item_inline_multiline_box(void);
#endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 


extern void handle_inline_full_screen_edit_complete(void);
extern void handle_inline_full_screen_edit_close(void);
extern void wgui_setup_inline_edit_themes(void);

extern void wgui_inline_multiline_append_string(U32 input_type, U8 *buffer, S32 buffer_size, U8 *string, U8 *history_buffer);

extern void wgui_inline_text_disable_cursor_display(S32 index);
extern void wgui_inline_text_enable_cursor_display(S32 index);

#ifdef __MMI_UI_LIST_GRID_LINE__
extern MMI_BOOL wgui_inline_editor_if_need_draw_separator_line(S32 item_index);
#endif /* __MMI_UI_LIST_GRID_LINE__ */
/* DOM-NOT_FOR_SDK-END */
/*****************************************************************************
 * FUNCTION
 *  ShowCategory57Screen
 * DESCRIPTION
 *  Displays the Category57 screen (In-line editor).
 *  Among the list of inline items, each can have a different inline editing feature and there can be any number of such items(Currently its restricted to 32 due to memory conservation, however).
 *
 *  The following Inline editing capability is currently available:
 *  (1)	    DisplayOnly (No editing allowed)
 *  (2)	    Caption
 *  (3)	    Multiline Read Only
 *  (4)	    Inline Horizontal Select
 *  (5)	    Inline DateEdit (Currently launches an external editor)
 *  (6)     Inline TimePeriod 
 *  (7)	    Inline TimeEdit (Currently launches an external editor)
 *  (8)	    Inline IP4
 *  (9)	    Inline TextEdit (Launches the inline text editor) 
 *  (10)	FullScreen edit (Launches a full screen editor)
 *                          
 *                                                     
 *  There are some critical steps to make an Category57 screen :
 *  (1) EntryNewScreen(SCR_ID_MYAPPLICATION_MAIN, mmi_myApplication_exit_main_screen, NULL, NULL);
 *	   	Inline screen can not have entry function, and if you hope to save history, you need write exit function by yourself.
 *  (2) InitializeCategory57Screen();
 *		Initialize the category screen: Specially required by inline category. 
 *  (3) You should call inline item setting function to set item list. 
 *  (4) Set input buffer: inputbuffer = GetCurrNInputBuffer(SCR_ID_MYAPPLICATION_MAIN, &inputBufferSize);
 *     	You should call GetCurrNInputBuffer to get input buffer if the screen is in history before.
 *  (5) ShowCategory57Screen():
 *		Call ShowCategory57Screen() to show inline screen.
 *	(6) mmi_myApplication_exit_main_screen(void);
 *		You should write exit function to save history.
 *                                                      
 * <img name="wgui_cat57_mainscreen" />
 * PARAMETERS
 *   title                       : [IN] (TITLE)  String ID of title
 *   title_icon                  : [IN] (N/A)    Image ID of title icon
 *   left_softkey                : [IN] (LSK)    String ID of left softkey
 *   left_softkey_icon           : [IN] (N/A)    Image ID of left softkey
 *   right_softkey               : [IN] (RSK)    String ID of right softkey
 *   right_softkey_icon          : [IN] (N/A)    Image ID of right softkey
 *   number_of_items             : [IN] (N/A)    Number of items
 *   list_of_icons               : [IN] (N/A)    Image ID array of icons
 *   list_of_items               : [IN] (*)      Inline item array list
 *   highlighted_item            : [IN] (N/A)    Current highlighted item
 *   history_buffer              : [IN] (N/A)    History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * //Here is an example of using the Inline edit category screen: This code makes an inline list with the following items:
 * //0        Display only
 * //1        Inline text edit
 * //2        Inline horizontal select
 * //3        Inline time edit
 * //4        Display only
 *
 * //Application string resource  
 * U8*  MyStrings[]=
 * { 
 *   (U8*)L("Display only item 1"),
 *   (U8*)L("Display only item 2"),
 * };
 *
 * //Buffer used by inline text editing, initialized to a valid string
 * U8 MyInlineTextEditBuffer[100]="Hello world";
 *
 * //Buffers used by inline time editing, all initialized
 * U8 MyInlineTimeHoursBuffer[20] = "12";
 * U8 MyInlineTimeMinutesBuffer[20] = "34";
 * U8 MyInlineTime_AM_PM_Flag = 0;
 *
 * //List of strings used by Inline Horizontal Select item
 * U8*  MyInlineSelectionList[]=
 * {
 *		(U8*)L("Home number"),
 *		(U8*)L("Office number"),
 *		(U8*)L("Mobile number"),
 *		(U8*)L("Fax number"),
 *		(U8*)L("Other number"),
 * };
 * 
 * //Firstly, create a list of Inline Items. 
 * //This list should be alive until the exit function of the application is called, so either use static data or allocate memory in the entry function and free it in the exit function. 
 * //This concept is similar to whatever happens with Category5 screen for edit buffer, other menu screens for list of items ¨C etc
 *
 * void MyApplicationEntryFunction(void)
 * {
 *    	U8 *guiBuffer;
 *   	U8 *inputBuffer;
 *  	U16 inputBufferSize;
 *   	U8 inline_total;
 *
 *      //Inline screen can not have entry function.	
 *  	EntryNewScreen(SCR_ID_MYAPPLICATION_MAIN, mmi_myApplication_exit_main_screen, NULL, NULL);
 *
 *      //Initialize the category screen: Specially required for Category57 screen.
 *      InitializeCategory57Screen();
 *
 *  	guiBuffer = GetCurrGuiBuffer(SCR_ID_MYAPPLICATION_MAIN);
 * 

 * 
 *
 *  	//Setup all the Displayonly items: Index 0 to 4 in this example
 *  	SetInlineItemActivation(&wgui_inline_items[0], 
 *		INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,0);
 *
 *  	SetInlineItemDisplayOnly(&wgui_inline_items[0], 
 *		MyStrings[string_index_1]);        //String to be displayed.
 *
 *  	SetInlineItemActivation( &wgui_inline_items[4], 
 *		INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,0);
 *
 *  	SetInlineItemDisplayOnly(&wgui_inline_items[4], 
 *		MyStrings[string_index_2]);        //String to be displayed.
 *
 *      //Setup the inline text editing item: Index 1 in this example
 *  	SetInlineItemActivation(&wgui_inline_items[1],
 *		KEY_LSK, KEY_EVENT_UP);            //Start editing on LSK.
 *
 *  	SetInlineItemTextEdit (&wgui_inline_items[1],
 *		MyInlineTextEditBuffer, 100, INPUT_TYPE_PHONE_NUMBER);
 *
 *      //Setup the inline Horizontal Select item: Index 2 in this example
 *  	SetInlineItemActivation( &wgui_inline_items[2], 
 *		INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,0);
 *
 * 		SetInlineItemSelect (&wgui_inline_items[2],
 *      5, MyInlineSelectionList, 0);		//5 items in Select item.
 *
 *      tup the inline time edit. See code below for function MyTimeStringConstructor     
 *  	SetInlineItemActivation(&wgui_inline_items[3], 
 *      KEY_LSK, KEY_EVENT_UP);			//Start editing on LSK.
 *
 * 		SetInlineItemTime (&wgui_inline_items[3], 
 *		MyInlineTimeHoursBuffer, MyInlineTimeMinutesBuffer,
 *      &MyInlineTime_AM_PM_Flag, MyTimeStringConstructor);
 *
 *
 *	    inputBuffer = GetCurrNInputBuffer(SCR_ID_MYAPPLICATION_MAIN, &inputBufferSize);
 *    	if (inputBuffer != NULL)
 *    	{
 *        SetCategory57Data(wgui_inline_items, MMI_MYSCHEDULE_MAX_INLINE_ITEM_LIST, inputBuffer);
 *    	}
 *
 *      ShowCategory57Screen (STR_MY_TITLE, IMG_MY_TITLE,
 *          STR_MY_LSK, IMG_MY_LSK,
 *          STR_MY_RSK, IMG_MY_RSK,
 *          5,                              //Number of items.
 *          MyListOfIcons,                  //Same as in icon menu screens.
 *      	wgui_inline_items,               //Inline items.
 *          0,                              //Highlight first item by default.
 *          GuiBuffer);                    //History buffer.
 *      }
 * }
 *
 *  //Sample time string construction function. This function may be typically implemented as a standard function and every application using inline time editing will simply need to pass this function to SetInlineItemTime. Also similarly with date inline editing.
 *  void MyTimeStringConstructor (U8* string_buffer, U8* hours_buffer, U8* minutes_buffer, U8* AM_PM_flag)
 *  {
 *      mmi_ucs2cpy ((S8*)string_buffer, (S8*)hours_buffer);
 *      mmi_ucs2cpy ((S8*)string_buffer, (S8*)L(":"));
 *      mmi_ucs2cpy ((S8*)string_buffer, (S8*)minutes_buffer);
 *      if( *AM_PM_flag == 0 )
 *          mmi_ucs2cpy ((S8*)string_buffer, (S8*)L("AM"));
 *      else
 *          mmi_ucs2cpy ((S8*)string_buffer, (S8*)L("PM"));
 *  }
 *
 * //APP writes inline screen exit function:
 * void mmi_myApplication_exit_main_screen(void)
 * {
 *   	GenericExitInlineScreen(SCR_ID_MYAPPLICATION_MAIN, mmi_myschedule_entry_main_screen);
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory57Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                U16 *list_of_icons,
                InlineItem *list_of_items,
                S32 highlighted_item,
                PU8 history_buffer);


/*****************************************************************************
 * FUNCTION
 *  ShowCategory657Screen
 * DESCRIPTION
 *  Displays the category657 screen (tab + In-line editor)
 * 
 * <img name="wgui_cat657_img1" />
 * PARAMETERS
 *   title                       : [IN ] (TITLE)  String ID of title
 *   title_icon                  : [IN ] (N/A)    Image ID of title icon
 *   left_softkey                : [IN ] (LSK)    String ID of left softkey
 *   left_softkey_icon           : [IN ] (N/A)    Image ID of left softkey
 *   right_softkey               : [IN ] (RSK)    String ID of right softkey
 *   right_softkey_icon          : [IN ] (N/A)    Image ID of right softkey
 *   number_of_items             : [IN ] (N/A)    Number of items
 *   list_of_icons               : [IN ] (N/A)    Image ID array of icons
 *   list_of_items               : [IN ] (N/A)    Inline item array list
 *   Region ID for list_of_items:
 *   (1)	Inline horizontal select ' The region id of each selected item's string  is C057_1
 *   (2)	Inline user defined select  ' The region id of each selected item's string  is C057_1
 *   (3)	Inline caption ' the region id of  Caption string  is  ICONTEXT
 *   highlighted_item            : [IN ] (N/A)    Currently highlighted item
 *   Highlighted_tab             : [IN ] (N/A)    Currently Highlighted tab
 *   history_buffer              : [IN ] (N/A)    History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 *  void EntryScreen_657(void)
 *  {
 *      mmi_frm_tab_struct tab_pages_info_array[2];
 * 
 *      tab_pages_info_array[0].screen_id = SCR_ID_CSB_DUMMY_SCR_ID + 1;
 *      tab_pages_info_array[0].tab_entry_func = entry_inline_tab_0;
 *      tab_pages_info_array[0].tab_icon = (U8*)GetImage(gIndexIconsImageList[0]);
 *      tab_pages_info_array[0].tab_string = NULL;   
 *    
 *      tab_pages_info_array[1].screen_id = SCR_ID_CSB_DUMMY_SCR_ID + 2;
 *      tab_pages_info_array[1].tab_entry_func = entry_inline_tab_1;
 *      tab_pages_info_array[1].tab_icon = (U8*)GetImage(gIndexIconsImageList[1]);
 *      tab_pages_info_array[1].tab_string = NULL;
 *     
 *      mmi_frm_general_tab_entry(SCR_ID_CSB_DUMMY_SCR_ID, EntryScreen_657, tab_pages_info_array, 2);
 *  }
 * 
 *  void exit_inline_tab_0(void)
 *  {
 *      history currHistory;
 *      S32 inputBufferSize;
 * 
 * 	    CloseCategory57Screen();
 *      currHistory.scrnID = SCR_ID_CSB_DUMMY_SCR_ID + 1;
 *      currHistory.entryFuncPtr = entry_inline_tab_0;
 *             
 *      GetCategoryHistory(currHistory.guiBuffer);
 * 	    inputBufferSize = (U16) GetCategory57DataSize();
 *      GetCategory57Data((U8*) currHistory.inputBuffer);    
 *      mmi_frm_add_tab_n_history(SCR_ID_CSB_DUMMY_SCR_ID + 1, &currHistory, (U16)inputBufferSize); 
 *  }
 * 
 *  void inline_tab_hilite_item(S32 index)
 *  {    
 *      SetKeyHandler(GoBackToMainMenu, KEY_END, KEY_EVENT_DOWN);
 *     
 *      SetKeyHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
 *      SetKeyHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);    
 *  }
 * 
 *  void entry_inline_tab_0(void)
 *  {
 *      U8 *guiBuffer = NULL;
 * 	    U8 *inputBuffer = NULL;
 * 	    U16 inputBufferSize;	
 *      S32 index;
 *      U16 nImgIds[CSB_MAX_BUFFER_LEN];
 * 
 *      EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID + 1 ,exit_inline_tab_0, NULL, MMI_TAB_PAGE);
 * 
 *      InitializeCategory57Screen();
 *      RegisterHighlightHandler(inline_tab_hilite_item);
 * 
 *      memset(g_buffer, 0, MAX_LOCAL_BUFFER);
 *      memset(g_buffer1, 0, MAX_LOCAL_BUFFER);
 * 
 *      SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
 *      SetInlineItemCaption(&wgui_inline_items[0], (U8*) L"Caption 1");
 *      SetInlineItemFullWidth(&wgui_inline_items[0]);
 * 
 *      SetInlineItemActivation(&wgui_inline_items[1], KEY_LSK, KEY_EVENT_UP);
 *      SetInlineItemFullScreenEdit(&wgui_inline_items[1], STR_GLOBAL_OPTIONS, GetRootTitleIcon(SERVICES_WAP_MENU_ID), g_buffer, 20, IMM_INPUT_TYPE_SENTENCE);
 *      SetInlineFullScreenEditCustomFunction(
 *          &wgui_inline_items[1], 
 *          csb_full_screen_edit);
 * 
 *      SetInlineItemActivation(&wgui_inline_items[2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
 *      SetInlineItemCaption(&wgui_inline_items[2], (U8*)L"Caption 2");
 *      SetInlineItemFullWidth(&wgui_inline_items[2]);
 *     
 *      SetInlineItemActivation(&wgui_inline_items[3], KEY_LSK, KEY_EVENT_UP);
 *      SetInlineItemFullScreenEdit(&wgui_inline_items[3], STR_GLOBAL_OPTIONS, GetRootTitleIcon(SERVICES_WAP_MENU_ID), g_buffer1, 20, IMM_INPUT_TYPE_SENTENCE);
 *      SetInlineFullScreenEditCustomFunction(
 *          &wgui_inline_items[3], 
 *          csb_full_screen_edit);
 * 
 *      SetInlineItemActivation(&wgui_inline_items[4], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
 *      SetInlineItemCaption(&wgui_inline_items[4], (U8*) L"Caption 3");
 *      SetInlineItemFullWidth(&wgui_inline_items[4]);
 * 
 *      for (index = 0; index < CSB_MAX_BUFFER_LEN; index++)
 *      {        
 *          nImgIds[index] = IMG_MENU8102_DIALED_CALLS;        
 *      }
 * 	
 * 	    inputBuffer = mmi_frm_get_cur_tab_n_input_buffer(SCR_ID_CSB_DUMMY_SCR_ID + 1,  &inputBufferSize);
 * 
 *      guiBuffer   = mmi_frm_get_cur_tab_gui_buffer(SCR_ID_CSB_DUMMY_SCR_ID + 1); 
 * 		
 * 	    if (inputBuffer != NULL)
 *      {
 *          SetCategory57Data(wgui_inline_items, CSB_MAX_BUFFER_LEN, inputBuffer);
 *      }
 * 
 *      ShowCategory657Screen(
 *          STR_ID_CSB_CATEGORY_TEXT,
 *          0,
 *          STR_ID_CSB_LSK_TEXT,
 *          0,
 *          STR_ID_CSB_RSK_TEXT,
 *          0,
 *          CSB_MAX_BUFFER_LEN,
 *          nImgIds,
 *          wgui_inline_items,
 *          0,
 *          0,
 *          guiBuffer);    
 * 
 *  #ifdef __MMI_TOUCH_SCREEN__ 
 *      wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);
 *  #endif 
 *      SetCategory57RightSoftkeyFunctions(GoBackToMainMenu, GoBackToMainMenu);
 * 
 *      SetKeyHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
 *      SetKeyHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
 *     
 *  }
 * 
 *  void exit_inline_tab_1(void)
 *  {
 *      history currHistory;
 *      S32  inputBufferSize;
 * 
 *      CloseCategory57Screen();
 *      currHistory.scrnID = SCR_ID_CSB_DUMMY_SCR_ID + 2;
 *      currHistory.entryFuncPtr = entry_inline_tab_1;
 *      
 *      GetCategoryHistory(currHistory.guiBuffer);
 * 	    inputBufferSize = (U16) GetCategory57DataSize();
 *      GetCategory57Data((U8*) currHistory.inputBuffer);    
 *      mmi_frm_add_tab_n_history(SCR_ID_CSB_DUMMY_SCR_ID + 2, &currHistory, (U16)inputBufferSize);    
 *  }
 * 
 *  void inline_tab_hilite_menu_item(S32 index)
 *  {
 *      SetKeyHandler(GoBackToMainMenu, KEY_END, KEY_EVENT_DOWN);    
 *      SetKeyHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
 *      SetKeyHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
 * 
 *      if (index%2 == 0)
 *      {
 *          ChangeLeftSoftkey(STR_ID_CSB_LSK_TEXT, 0);
 *      }
 *  }
 * 
 *  void entry_inline_tab_1(void)
 *  {
 *      U8 *guiBuffer = NULL;
 * 	    U8 *inputBuffer = NULL;
 * 	    U16 inputBufferSize;	
 *      S32 index;
 *      U16 nImgIds[CSB_MAX_BUFFER_LEN];
 * 	
 *      EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID + 2 ,exit_inline_tab_1, NULL, MMI_TAB_PAGE);
 * 	
 *      RegisterHighlightHandler(inline_tab_hilite_menu_item);
 * 	
 *      InitializeCategory57Screen();
 * 	
 *      memset(g_buffer2, 0, MAX_LOCAL_BUFFER);
 *      memset(g_buffer3, 0, MAX_LOCAL_BUFFER);
 *     
 * 
 *      SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
 *      SetInlineItemDisplayOnly(&wgui_inline_items[0], (U8*) GetString(STR_ID_CSB_MENUITEM1_TEXT));
 *      SetInlineItemFullWidth(&wgui_inline_items[0]);
 * 
 *      SetInlineItemActivation(&wgui_inline_items[1], KEY_LSK, KEY_EVENT_UP);
 *      SetInlineItemFullScreenEdit(&wgui_inline_items[1], STR_GLOBAL_OPTIONS, GetRootTitleIcon(SERVICES_WAP_MENU_ID), g_buffer2, 20, IMM_INPUT_TYPE_SENTENCE);
 *      SetInlineFullScreenEditCustomFunction(
 *          &wgui_inline_items[1], 
 *          csb_full_screen_edit);
 * 
 *      SetInlineItemActivation(&wgui_inline_items[2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
 *      SetInlineItemDisplayOnly(&wgui_inline_items[2], (U8*) GetString(STR_ID_CSB_MENUITEM2_TEXT));
 *      SetInlineItemFullWidth(&wgui_inline_items[2]);
 *     
 *      SetInlineItemActivation(&wgui_inline_items[3], KEY_LSK, KEY_EVENT_UP);
 *      SetInlineItemFullScreenEdit(&wgui_inline_items[3], STR_GLOBAL_OPTIONS, GetRootTitleIcon(SERVICES_WAP_MENU_ID), g_buffer3, 20, IMM_INPUT_TYPE_SENTENCE);
 *      SetInlineFullScreenEditCustomFunction(
 *          &wgui_inline_items[3], 
 *          csb_full_screen_edit);
 * 
 *      SetInlineItemActivation(&wgui_inline_items[4], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
 *      SetInlineItemDisplayOnly(&wgui_inline_items[4], (U8*) GetString(STR_ID_CSB_MENUITEM3_TEXT));
 *      SetInlineItemFullWidth(&wgui_inline_items[4]);
 * 	 	
 *      for (index = 0; index < CSB_MAX_BUFFER_LEN; index++)
 *      {        
 *          nImgIds[index] = IMG_MENU8102_DIALED_CALLS;        
 *      }
 * 	
 *      inputBuffer = mmi_frm_get_cur_tab_n_input_buffer(SCR_ID_CSB_DUMMY_SCR_ID + 2,  &inputBufferSize);
 * 	
 *      guiBuffer   = mmi_frm_get_cur_tab_gui_buffer(SCR_ID_CSB_DUMMY_SCR_ID + 2); 
 * 	
 * 	    if (inputBuffer != NULL)
 *      {
 *          SetCategory57Data(wgui_inline_items, CSB_MAX_BUFFER_LEN, inputBuffer);
 *      }
 * 	
 *      ShowCategory657Screen(
 *          STR_ID_CSB_CATEGORY_TEXT,
 *          0,
 *          STR_ID_CSB_LSK_TEXT,
 *          0,
 *          STR_ID_CSB_RSK_TEXT,
 *          0,
 *          CSB_MAX_BUFFER_LEN,
 *          nImgIds,
 *          wgui_inline_items,
 *          0,
 *          1,        
 *          guiBuffer);
 * 
 *      SetCategory57RightSoftkeyFunctions(GoBackToMainMenu, GoBackToMainMenu);
 * 
 *  #ifdef __MMI_TOUCH_SCREEN__ 
 *      wgui_set_horizontal_tab_bar_select_callback(mmi_frm_set_cur_sel_page);
 *  #endif
 * 
 *      SetKeyHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
 *      SetKeyHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);   
 *  }
 * </code>
 *****************************************************************************/
extern void ShowCategory657Screen(
            U16 title,
            U16 title_icon,
            U16 left_softkey,
            U16 left_softkey_icon,
            U16 right_softkey,
            U16 right_softkey_icon,
            S32 number_of_items,
            U16 *list_of_icons,
            InlineItem *list_of_items,
            S32 highlighted_item,
            S8 highlighted_tab,                
            PU8 history_buffer);

/*****************************************************************************
 * FUNCTION
 *  ShowCategory257Screen
 * DESCRIPTION
 *  Displays the category257 screen (In-line editor with image header)
 * 
 * <img name="wgui_cat257_mainscreen" />
 * PARAMETERS
 *   title                       : [IN ] (TITLE)  String ID of title
 *   title_icon                  : [IN ] (N/A)    Image ID of title icon
 *   left_softkey                : [IN ] (LSK)    String ID of left softkey
 *   left_softkey_icon           : [IN ] (N/A)    Image ID of left softkey
 *   right_softkey               : [IN ] (RSK)    String ID of right softkey
 *   right_softkey_icon          : [IN ] (N/A)    Image ID of right softkey
 *   ImgId						 : [IN ] (N/A)    Image ID of message icon
 *   number_of_items             : [IN ] (N/A)    Number of items
 *   list_of_icons               : [IN ] (N/A)    Image ID array of icons
 *   list_of_items               : [IN ] (N/A)    Inline item array list
 *   Region ID for list_of_items:
 *   (1)	Inline horizontal select ' The region id of each selected item's string  is C057_1
 *   (2)	Inline user defined select  ' The region id of each selected item's string  is C057_1
 *   (3)	Inline caption ' the region id of  Caption string  is  ICONTEXT
 *   highlighted_item            : [IN ] (N/A)    Currently highlighted item
 *   history_buffer              : [IN ] (N/A)    History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 *  void ExitScreen_Inline(void)
 *  {
 *      CloseCategory57Screen();
 *      ExitScreen_Generic();
 *  }
 *
 *  void EntryScreen_257(void)
 *  {
 *      U8 *guiBuffer = NULL;
 *
 *      EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Inline, EntryCSBStartView, NULL);
 *
 *      InitializeCategory57Screen();
 *
 *      CSBAppFillInlineStruct();
 *
 *      ShowCategory257Screen(
 *			STR_ID_CSB_CATEGORY_TEXT,
 *			NULL,
 *			STR_ID_CSB_LSK_TEXT,
 *			0,
 *			STR_ID_CSB_RSK_TEXT,
 *			0,
 *			NULL,
 *			5,
 *			NULL,
 *		    wgui_inline_items,
 *			1,
 *			guiBuffer);
 *
 *      ChangeLeftSoftkey(STR_ID_CSB_LSK_TEXT, 0);
 *      ChangeRightSoftkey(STR_ID_CSB_RSK_TEXT, 0);
 *
 *      SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_DOWN);
 *      SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_UP);
 *  }
 * </code>
 *****************************************************************************/
extern void ShowCategory257Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U16 ImgId,
                S32 number_of_items,
                U16 *list_of_icons,
                InlineItem *list_of_items,
                S32 highlighted_item,
                PU8 history_buffer);
/*****************************************************************************
 * FUNCTION
 *  ShowCategory357Screen
 * DESCRIPTION
 *  Displays the category357 screen (In-line editor with image header)
 * 
 * <img name="wgui_cat357_img1" />
 * PARAMETERS
 *   title                       : [IN ] (TITLE)  String ID of title
 *   title_icon                  : [IN ] (N/A)    Image ID of title icon
 *   left_softkey                : [IN ] (LSK)    String ID of left softkey
 *   left_softkey_icon           : [IN ] (N/A)    Image ID of left softkey
 *   right_softkey               : [IN ] (RSK)    String ID of right softkey
 *   right_softkey_icon          : [IN ] (N/A)    Image ID of right softkey
 *   ImgId						 : [IN ] (N/A)    Image ID of message icon
 *   number_of_items             : [IN ] (N/A)    Number of items
 *   list_of_icons               : [IN ] (N/A)    Image ID array of icons
 *   list_of_items               : [IN ] (N/A)    Inline item array list
 *   Region ID for list_of_items:
 *   (1)	Inline horizontal select ' The region id of each selected item's string  is C057_1
 *   (2)	Inline user defined select  ' The region id of each selected item's string  is C057_1
 *   (3)	Inline caption ' the region id of  Caption string  is  ICONTEXT
 *   highlighted_item            : [IN ] (N/A)    Currently highlighted item
 *   history_buffer              : [IN ] (N/A)    History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 *  #ifdef __MMI_WALLPAPER_ON_BOTTOM__
 *
 *  void EntryScreen_357(void)
 *  {
 *      U8 *guiBuffer = NULL;
 *
 *      EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Inline, EntryCSBStartView, NULL);
 *
 *      InitializeCategory57Screen();
 *
 *      CSBAppFillInlineStruct();
 *
 *      DisableCategory57ScreenDone();
 *
 *      ShowCategory357Screen(
 *          STR_ID_CSB_CATEGORY_TEXT,
 *          0,
 *          STR_ID_CSB_LSK_TEXT,
 *          0,
 *          STR_ID_CSB_RSK_TEXT,
 *          0,
 *          0,
 *          CSB_MAX_BUFFER_LEN,
 *          NULL,
 *          wgui_inline_items,
 *          0,
 *          guiBuffer);
 *
 *      ChangeLeftSoftkey(STR_ID_CSB_LSK_TEXT, 0);
 *      ChangeRightSoftkey(STR_ID_CSB_RSK_TEXT, 0);
 *
 *      SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_DOWN);
 *      SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_UP);
 *  }
 *
 *  #endif // __MMI_WALLPAPER_ON_BOTTOM__
 *
 * </code>
 *****************************************************************************/
extern void ShowCategory357Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U16 ImgId,
                S32 number_of_items,
                U16 *list_of_icons,
                InlineItem *list_of_items,
                S32 highlighted_item,
                PU8 history_buffer);

/*****************************************************************************
 * FUNCTION
 *  SetInlineItemActivation      
 * DESCRIPTION
 *  Set Inline item's key code and key state.
 *  key_code can be any of the standard MMI key codes: Ex: KEY_1, KEY_LSK - etc. 
 *  key_event can be any of the standard MMI key events KEY_EVENT_UP, KEY_EVENT_DOWN - etc. 
 *
 *  Specifying the key event that triggers inline editing of an item:
 *  The following functions(Present in example, like SetInlineItemActivation, SetInlineItemTextEdit) should be called for each item in the list_of_items.
 *  Inline editing for some items may need to be automatic (Editing starts as soon as the item is highlighted. For example, in Horizontal Select item). For this just pass the key_code as INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT and the key event as 0. Always do this for Displayonly items.
 *      
 *  If its required to change the softkey labels whenever an item is highlighted (For example, if LSK is used as the activation key, the LSK can change to "Edit" whenever an Inline TextEdit item is highlighted), write a custom highlight handler and change the softkey labels by calling ChangeLeftSoftkey, ChangeRightSoftkey.  To understand about custom highlight handlers and dynamic menus, see the beginning chapters of this document.
 * 
 *  If item is activated by highlight, it will be set to INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT.
 *  If item is activated by pressing key ,it will be set to KEY_LSK or other something.
 *  key activated items: FullScreen edit, ImageText edit, ImageAttach.
 *    
 * PARAMETERS
 *  item                    :   [IN]   Inline item's pointer 
 *  key_code                :   [IN]   Key code
 *  key_event               :   [IN]   Key event
 * RETURNS
 *  void                       
 * EXAMPLE
 * <code>
 *    U8 mmi_myschedule_fill_inlinestruct_for_add(void)
 *    {
 *        S32 inline_index = 0;
 *        SetInlineItemActivation(&(wgui_inline_items[inline_index]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
 *        SetInlineItemTextEdit(
 *            &wgui_inline_items[inline_index],
 *            (PU8) g_mmi_myschedule_cntx.m_record_note,
 *            (MMI_MYSCHEDULE_NOTE_BUFFER_SIZE) / ENCODING_LENGTH,
 *            INPUT_TYPE_USE_ENCODING_BASED_LENGTH | IMM_INPUT_TYPE_SENTENCE);
 *        inline_index++;
 *    }
 * </code>
 *****************************************************************************/
extern void SetInlineItemActivation(InlineItem *item, S32 key_code, S32 key_event);

/*****************************************************************************
 * FUNCTION
 *  InitializeCategory57Screen
 * DESCRIPTION
 *  Initialize Category57 screen variables and status.
 *  You should call this function in entry screen function before ShowCategory57Screen().
 *  
 * PARAMETERS
 * void 
 *
 * RETURNS
 *  void
 *****************************************************************************/
extern void InitializeCategory57Screen(void);

/*****************************************************************************
 * FUNCTION
 *  SetCategory57Data
 * DESCRIPTION
 *  Read Category57 data from Input buffer.
 *  When App go back to  the screen, it can call this function to set status of items .
 *  
 * PARAMETERS
 *  list_of_items           :   [OUT]  arroy of items's pointer. 
 *  number_of_items         :   [IN]   number of items. App should know how many items the screen have.
 *  data                    :   [IN]   input buffer pointer.there will do nothing if data is null.
 *
 * RETURNS
 *  void
 * 
 * EXAMPLE
 * <code>
 *  void mmi_myschedule_entry_main_screen(void)
 *  {
 *      U8 *inputBuffer;
 *      U8 inline_total;
 *      inputBuffer = GetCurrNInputBuffer(SCR_ID_MYSCHEDULE_ADD, &inputBufferSize);
 *      if (inputBuffer != NULL)
 *      {
 *          SetCategory57Data(wgui_inline_items, inline_total, inputBuffer);
 *      }       
 *  }
 * </code>
 *****************************************************************************/
extern void SetCategory57Data(InlineItem *list_of_items, S32 number_of_items, PU8 data);

/*****************************************************************************
 * FUNCTION
 *  GetCategory57History
 * DESCRIPTION
 *  Gets the history buffer for the category57 screen
 *  App can call this function to save history of 57screen by itself.
 * PARAMETERS
 *  history_buffer          :   [OUT]        Is the buffer into which the history data is stored (pre-allocated),it can not be null.
 * RETURNS
 *  pointer to the history buffer

 *****************************************************************************/
extern PU8 GetCategory57History(U8 *history_buffer);

/*****************************************************************************
 * FUNCTION
 *  GetCategory57HistorySize
 * DESCRIPTION
 *  Gets the size of  history buffer for the category57 screen.
 *  you should call this function before call GetCategory57History to get history.
 * PARAMETERS
 *  void
 * RETURNS
 *  size of history buffer in U8s
 *****************************************************************************/
extern S32 GetCategory57HistorySize(void);

/*****************************************************************************
 * FUNCTION
 *  SetCategory57RightSoftkeyFunctions
 * DESCRIPTION
 *  Set Category57 Right"functional key" handler.
 *  We call the key which decides the finial behavior of screen as "functional key". 
 *  When any item changes in 57screen ,inline will set handler of "functional key" is done function.
 *  When all items don't change in 57screen, inline will set handler of "functional key" is back function.
 
 *  When current activated item is singleline edit or Multiline edit , "functional key" is left softkey.
 *  When current activated item is ImageAttach or Imagetext edit, there are no certain "functional key".
 *  Otherelse, "functional key" is right softkey.
 * PARAMETERS
 *  done_function        :   [IN]    done function    
 *  back_function        :   [IN]    back function    
 * RETURNS
 *  void
 *****************************************************************************/
void SetCategory57RightSoftkeyFunctions(void (*done_function) (void), void (*back_function) (void));

/*****************************************************************************
 * FUNCTION
 *  SetCategory57LeftSoftkeyFunction
 * DESCRIPTION
 *  set Category57 LSK function
 *  calling this function may be invaild,for example, it will be invalid if the icon and the text of leftkey are null.
 * PARAMETERS
 *  LSK_function        :   [IN]   LSK function     
 * RETURNS
 *  void
 *****************************************************************************/
void SetCategory57LeftSoftkeyFunction(void (*LSK_function) (void));

/*****************************************************************************
 * FUNCTION
 *  GetCategory57DataSize
 * DESCRIPTION
 *  Get cat57 data size. App should call this function before call GetCategory57DataSize().
 *  See GetCategory57Data().
 * PARAMETERS
 *  void
 * RETURNS
 *  data size
 *****************************************************************************/
extern S32 GetCategory57DataSize(void);

/*****************************************************************************
 * FUNCTION
 *  GetCategory57Data
 * DESCRIPTION
 *  Save the data for the category57 screen.
 
 *  The data we also call as "input buffer" is just used for Inline layer.
 *  Inline category must not have entry function:
 *      When a category screen which has entry function exits, mmi_frm_generic_exit_screen will be called and it will call mmi_frm_add_history() with null inputbuffer point , so , inline category can not have entry function. 
 *  Add history by ourselves :
 *      When we want to add inline screen to history  ,we will implement  it  by ourselves in  exit function.

 * PARAMETERS
 *  data                :   [OUT]   data   
 * RETURNS
 *  data pointer
 
 * EXAMPLE
 * <code>
 *  	 //example1
 *  	 void mmi_myschedule_exit_main_screen(void)
 *  	 {
 *  	      GenericExitInlineScreen(SCR_ID_MYSCHEDULE_ADD, mmi_myschedule_entry_main_screen);
 *  	  }
 *   	 void mmi_myschedule_entry_main_screen(void)
 *   	 {
 *   	 	EntryNewScreen(SCR_ID_MYSCHEDULE_ADD, mmi_myschedule_exit_main_screen, NULL, NULL);
 *   	     InitializeCategory57Screen(); 	
 *   	 }
 *    
 *   	 //example2
 *    	 void mmi_myschedule_exit_main_screen(void)
 *    	 {
 *        	history h;
 *        
 *       	h.scrnID = SCR_ID_MYSCHEDULE_ADD;
 *        	CloseCategory57Screen();
 *       	 h.entryFuncPtr = mmi_myschedule_entry_main_screen;
 *        	mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & n_history);
 *        	GetCategory57History(h.guiBuffer);
 *        	input_buffer_size = (U16) GetCategory57DataSize();
 *        	GetCategory57Data((U8*) h.inputBuffer);
 *        	AddNHistory(h, input_buffer_size);
 *    	 }
 *    	 void mmi_myschedule_entry_main_screen(void)
 *    	 {
 *    		EntryNewScreen(SCR_ID_MYSCHEDULE_ADD, mmi_myschedule_exit_main_screen, NULL, NULL);
 *       	 InitializeCategory57Screen(); 	
 *   	 }
 *   
 * </code>
 *****************************************************************************/
extern PU8 GetCategory57Data(PU8 data);

/*****************************************************************************
 * FUNCTION
 *  CloseCategory57Screen
 * DESCRIPTION
 *  Close the Category57 screen.
 *  App should call this function when exits Category57 screen before 10A.
 *  And if you want to save input buffer by yourself, you must assure that this function will be called before saving input buffer action.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void CloseCategory57Screen(void);


/*****************************************************************************
 * FUNCTION
 *  set_wgui_inline_list_menu_changed
 * DESCRIPTION
 *  Set the right softkey to changed status.
 *  This function will do nothing if current status is disable done status.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void set_wgui_inline_list_menu_changed(void);

/*****************************************************************************
 * FUNCTION
 *  DisableInlineItem
 * DESCRIPTION
 *  Set inline item to be disable.
 * PARAMETERS
 *  item                : [IN] inline item's pointer     
 *  index               : [IN] item's index    
 * RETURNS
 *  void
 *****************************************************************************/
extern void DisableInlineItem(InlineItem *item, S32 index);

/*****************************************************************************
 * FUNCTION
 *  EnableInlineItem
 * DESCRIPTION
 *  Set inline item to be able.
 * PARAMETERS
 *  item                : [IN] inline item's pointer         
 *  index               : [IN] inline item's index    
 * RETURNS
 *  void
 *****************************************************************************/
extern void EnableInlineItem(InlineItem *item, S32 index);

/*****************************************************************************
 * FUNCTION
 *  SetInlineItemFullWidth
 * DESCRIPTION
 *  Set inline item as full width.
 * PARAMETERS
 *  item                : [IN] inline item's pointer     
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetInlineItemFullWidth(InlineItem *i);

/*****************************************************************************
 * FUNCTION
 *  ResetInlineItemFullWidth
 * DESCRIPTION
 *  Set inline item as no full width.
 * PARAMETERS
 *  item                : [IN] inline item's pointer     
 * RETURNS
 *  void
 *****************************************************************************/
extern void ResetInlineItemFullWidth(InlineItem *item);

/*****************************************************************************
 * FUNCTION
 *  LeftJustifyInlineItem
 * DESCRIPTION
 *  set inline item as left justify
 * PARAMETERS
 *  item                : [IN] inline item's pointer    
 * RETURNS
 *  void
 *****************************************************************************/
extern void LeftJustifyInlineItem(InlineItem *i);

/*****************************************************************************
 * FUNCTION
 *  RightJustifyInlineItem
 * DESCRIPTION
 *  set inline item as right justify
 * PARAMETERS
 *  item                : [IN] inline item's pointer      
 * RETURNS
 *  void
 *****************************************************************************/
extern void RightJustifyInlineItem(InlineItem *i);

/*****************************************************************************
 * FUNCTION
 *  CenterJustifyInlineItem
 * DESCRIPTION
 *  set inline item as center justify
 * PARAMETERS
 *  item                : [IN] inline item's pointer    
 * RETURNS
 *  void
 *****************************************************************************/
extern void CenterJustifyInlineItem(InlineItem *i);

/*****************************************************************************
 * FUNCTION
 *  DisableInlineItemBoundary
 * DESCRIPTION
 *  Disable inline item boundary
 * PARAMETERS
 *  item                : [IN] inline item's pointer     
 * RETURNS
 *  void
 *****************************************************************************/
extern void DisableInlineItemBoundary(InlineItem *i);

/*****************************************************************************
 * FUNCTION
 *  EnableInlineItemBoundary
 * DESCRIPTION
 *  Enable inline item boundary
 * PARAMETERS
 *  item                : [IN] inline item's pointer  
 * RETURNS
 *  void
 *****************************************************************************/
extern void EnableInlineItemBoundary(InlineItem *i);

/*****************************************************************************
 * FUNCTION
 *  DisableInlineItemHighlight
 * DESCRIPTION
 *  Disable inline item's highlight flag.
 *  Item setting this attribute will not have backlight.
 * PARAMETERS
 *  item                : [IN] inline item's pointer      
 * RETURNS
 *  void
 *****************************************************************************/
extern void DisableInlineItemHighlight(InlineItem *i);


/*****************************************************************************
 * FUNCTION
 *  EnableInlineItemHighlight
 * DESCRIPTION
 *  Enable inline item's highlight flag.
 *  Item setting this attribute will not have backlight.
 * PARAMETERS
 *  item                : [IN] inline item's pointer      
 * RETURNS
 *  void
 *****************************************************************************/
extern void EnableInlineItemHighlight(InlineItem *item);

/*****************************************************************************
 * FUNCTION
 *  SetInlineItemDottedUnderline
 * DESCRIPTION
 *  Set inine item's INLINE_ITEM_DOTTED_UNDERLINE flag
 * PARAMETERS
 *  item                : [IN] inline item's pointer    
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetInlineItemDottedUnderline(InlineItem *i);

#if defined(__WGUI_CAT_DATE_YEAR_ONLY__)
/*****************************************************************************
 * FUNCTION
 *  SetInlineItemYearOnly
 * DESCRIPTION
 *  Set inine item's INLINE_ITEM_YEAR_ONLY flag
 * PARAMETERS
 *  item                : [IN] inline item's pointer    
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetInlineItemYearOnly(InlineItem *item);
#endif /* __WGUI_CAT_DATE_YEAR_ONLY__ */

/*****************************************************************************
 * FUNCTION
 *  wgui_get_inline_item_height
 * DESCRIPTION
 *  Get inline item's height
 * PARAMETERS
 *  item_index          : [IN]    
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 wgui_get_inline_item_height(S32 item_index);

/*****************************************************************************
 * FUNCTION
 *  GetInlineDoneFlag
 * DESCRIPTION
 *  Get inline Done flag from history buffer.
 * PARAMETERS
 *  history_buffer      : [IN] history buffer
 * RETURNS
 *  DoneFlag
 *****************************************************************************/
extern U8 GetInlineDoneFlag(PU8 history_buffer);

/*****************************************************************************
 * FUNCTION
 *  SetInlineDoneFlag
 * DESCRIPTION
 *  Set inline Done flag into history buffer.
 * PARAMETERS
 *  history_buffer      : [IN/OUT] history buffer
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetInlineDoneFlag(PU8 history_buffer);

/*****************************************************************************
 * FUNCTION
 *  ResetInlineDoneFlag
 * DESCRIPTION
 *  Rest inline Done flag to 0(Done status) in history buffer.
 * PARAMETERS
 *  history_buffer     : [IN/OUT] history buffer     
 * RETURNS
 *  void
 *****************************************************************************/
extern void ResetInlineDoneFlag(PU8 history_buffer);


#ifdef __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__

/*****************************************************************************
 * FUNCTION
 *  SetInlineItemTextEditDefaultItemNameIfEmpty
 * DESCRIPTION
 *  Sets the pointer item->text_p to point to default item text.
 *  Only if the singleline item 's text is empty and inline layer allows to set default text,the function is valid.
 *  This function is just for singleline.
 * PARAMETERS
 *  item                :[IN] Is the pointer to InlineItem structure.
 *  default_text_id     :[IN] Is the string Id of the default text.
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetInlineItemTextEditDefaultItemNameIfEmpty(InlineItem *item, U16 default_text_id);

/*****************************************************************************
 * FUNCTION
 *  EnableInlineItemDefaultText
 * DESCRIPTION
 *  Sets the global flag variable to 1.
 *  This function is used to enable inline  item to set default text.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void EnableInlineItemDefaultText(void);

/*****************************************************************************
 * FUNCTION
 *  DisableInlineItemDefaultText
 * DESCRIPTION
 *  Sets the global flag variable to 0.
 *  This function is used to disable inline  item to set default text.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void DisableInlineItemDefaultText(void);

/*****************************************************************************
 * FUNCTION
 *  IsInlineItemDefaultTextEnable
 * DESCRIPTION
 *  Check whether the global flag is on or off.
 *  This function is used to check whether inline  items are allowed to  set default text.
 * PARAMETERS
 *  void
 * RETURNS
 *  1 if the flag is set otherwise 0.
 *****************************************************************************/
extern U8 IsInlineItemDefaultTextEnable(void);
#endif /* __MMI_UI_INLINE_EDIT_DEFAULT_TEXT_EFFECT__ */ 

/*****************************************************************************
 * FUNCTION
 *  wgui_inline_set_anykey_auto_enter
 * DESCRIPTION
 *  disable or able the anykey auto entering function
 * PARAMETERS
 *  b_enable            : [IN]
 * RETURNS
 *  void
 *****************************************************************************/   
extern void wgui_inline_set_anykey_auto_enter(MMI_BOOL b_enable);

/*****************************************************************************
 * FUNCTION
 *  Category57ChangeItemIcon
 * DESCRIPTION
 *  change item icon.
 * PARAMETERS
 *  index               : [IN]     item index   
 *  image_ID            : [IN]     image id   
 * RETURNS
 *  void
 *****************************************************************************/
extern void Category57ChangeItemIcon(S32 index, U16 image_ID);

/*****************************************************************************
 * FUNCTION
 *  DisableCategory57ScreenDone
 * DESCRIPTION
 *  Diable Done for Cateogry57Screen.
 *  See EnableCategory57ScreenDone.
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void DisableCategory57ScreenDone(void);


/*****************************************************************************
 * FUNCTION
 *  EnableCategory57ScreenDone
 * DESCRIPTION
 *  Enable Done status for Cateogry57Screen.
 
 *  Done/Back is a style of right key (for most items).
 *  When any item  changes, right key is Done.
 *  When all items don't change, right key is Back.
 
 *  SingleLine and Multiline's right key have 3 state: Back, Clear, Null, but no Done status.
 *  SingleLine, Multiline, FullScreen, ImageText,ImageAttach¡¯s softkey is not null.
 *  SingleLine's and Multiline's left key are set to Done/Back style. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void EnableCategory57ScreenDone(void);


/*****************************************************************************
 * FUNCTION
 *  DisableCategory57ScreenRskBack
 * DESCRIPTION
 *  Diable FTE Back for Cateogry57Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void DisableCategory57ScreenRskBack(void);

/*****************************************************************************
 * FUNCTION
 *  EnableCategory57ScreenRskBack
 * DESCRIPTION
 *  Enable FTE Back for Cateogry57Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void EnableCategory57ScreenRskBack(void);

/*****************************************************************************
 * FUNCTION
 *  RedrawCategory57Screen
 * DESCRIPTION
 *  Category57 redraw function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void RedrawCategory57Screen(void);

/*****************************************************************************
 * FUNCTION
 *  ExitCategory57Screen
 * DESCRIPTION
 *  This function will reset the internal variable and status of Category57 screen. 
 *  It should be called when exit Category57 screen in exit screen function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void ExitCategory57Screen(void);


/*****************************************************************************
 * FUNCTION
 *  Category57AppendTopInfoBox
 * DESCRIPTION
 *  Append top info box to Category screen 57.
 *  [NOTIC!] call this function before calling ShowCategory57Screen
 * PARAMETERS
 *  num_of_info_box_rows        :   [IN]       number of info box row 
 *  draw_info_callback          :   [IN]       draw info callback function 
 *  hide_info_callback          :   [IN]       hide info callback function 
 *  is_draw_once                :   [IN]       is draw once 
 * RETURNS
 *  void
 *****************************************************************************/
void Category57AppendTopInfoBox(U16 num_of_info_box_rows,
                                void (*draw_info_callback) (S32 idx, S32 x1, S32 y1, S32 x2, S32 y2),
                                void (*hide_info_callback) (S32 idx), BOOL is_draw_once);


/* function to set RSK to "Clear" */
/*****************************************************************************
 * FUNCTION
 *  SetCategory57ScreenRSKClear
 * DESCRIPTION
 *  Set Category57 Screen RSK status to 'clear' status.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetCategory57ScreenRSKClear(void);

/*****************************************************************************
 * FUNCTION
 *  get_wgui_inline_list_menu_status
 * DESCRIPTION
 *  get inline list menu changed status
 * PARAMETERS
 *  void
 * RETURNS
 *  the value of wgui_inline_list_menu_changed
 *****************************************************************************/
extern S32 get_wgui_inline_list_menu_status(void);

/*****************************************************************************
 * FUNCTION
 *  set_wgui_inline_list_menu_status
 * DESCRIPTION
 *  set inline list menu changed status
 * PARAMETERS
 *  status                  : [IN]        value of wgui_inline_list_menu_changed
 * RETURNS
 *  void
 *****************************************************************************/
extern void set_wgui_inline_list_menu_status(S32 status);

/*****************************************************************************
 * FUNCTION
 *  execute_wgui_inline_edit_RSK_function
 * DESCRIPTION
 *  execute 'function key' handler of inline item.
 *  When any item changes in 57screen ,inline will set handler of "functional key" is done function.
 *  When all items don't change in 57screen, inline will set handler of "functional key" is back function.
 
 *  See SetCategory57RightSoftkeyFunctions().
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void execute_wgui_inline_edit_RSK_function(void);

/*****************************************************************************
 * FUNCTION
 *  execute_wgui_inline_edit_LSK_function
 * DESCRIPTION
 *  execute LSK func of inline register by SetCategory57LeftSoftkeyFunction.
 *  See SetCategory57LeftSoftkeyFunction().
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void execute_wgui_inline_edit_LSK_function(void);

/*****************************************************************************
 * FUNCTION
 *  SetInlineListMenuChanged
 * DESCRIPTION
 *  wrapper function of set_wgui_inline_list_menu_changed()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetInlineListMenuChanged(void);

/*****************************************************************************
 * FUNCTION
 *  GetInlineListMenuChanged
 * DESCRIPTION
 *  get the status of inline change.
 * PARAMETERS
 *  void
 * RETURNS
 *  the value value of wgui_inline_list_menu_changed
 *****************************************************************************/
extern S32 GetInlineListMenuChanged(void);

/*****************************************************************************
 * FUNCTION
 *  RegisterInlineItemChangedNotification
 * DESCRIPTION
 *  Register inline item changed notification callback.
 *  When inline  status changs, inline layer will calls app callback function. 
 * PARAMETERS
 *  callback                : [IN]        Callback function to application
 * RETURNS
 *  void
 *****************************************************************************/
extern void RegisterInlineItemChangedNotification(void (*callback) (U16 index));

/*****************************************************************************
 * FUNCTION
 *  ResetInlineItemChangedNotification
 * DESCRIPTION
 *  Reset inline item changed notification callback.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void ResetInlineItemChangedNotification(void);

/*****************************************************************************
 * FUNCTION
 *  wgui_inline_menu_disable_looping
 * DESCRIPTION
 *  disable inline editor menu looping.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_inline_menu_disable_looping(void);

/*****************************************************************************
 * FUNCTION
 *  wgui_inline_edit_is_able_to_switch_highlight
 * DESCRIPTION
 *  to check if current inline editor can switch highlight to next/previous item
 * PARAMETERS
 *  direction   0 -> previous ; 1-> next
 * RETURNS
 *  MMI_TRUE -> can switch highlight   MMI_FALSE -> can't switch highlight
 *****************************************************************************/
extern MMI_BOOL wgui_inline_edit_is_able_to_switch_highlight(S32 direction);


/*****************************************************************************
Text edit
 *****************************************************************************/
 
 /*****************************************************************************
 * FUNCTION
 *  SetInlineItemTextEdit
 * DESCRIPTION
 *  Set data for Inline TextEdit item.
 *  The parameters are similar to the ones used in Category5 screen. Please see the Category5 screen for more details (input_type - etc).                       
 *  For the full screen edit feature, you also need to specify the title and title_icon to be displayed. This is similar to the Category 5 screen again.
 
 * <img name="wgui_cat57_text" />
 * PARAMETERS
 *  item               	: [IN]   Inline item         
 *  buffer              : [IN]   Is the buffer used for editing (It should be initialized to some valid string)    
 *  buffer_size      	: [IN]   Is the size of the buffer  
 *  input_type     	    : [IN]   Is the input type to use 
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 *    U8 mmi_myschedule_fill_inlinestruct_for_add(void)
 *    {
 *        S32 inline_index = 0;
 *        SetInlineItemActivation(&(wgui_inline_items[inline_index]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
 *        SetInlineItemTextEdit(
 *            &wgui_inline_items[inline_index],
 *            (PU8) g_mmi_myschedule_cntx.m_record_note,
 *            (MMI_MYSCHEDULE_NOTE_BUFFER_SIZE) / ENCODING_LENGTH,
 *            INPUT_TYPE_USE_ENCODING_BASED_LENGTH | IMM_INPUT_TYPE_SENTENCE);
 *        inline_index++;
 *    }
 * </code>
 *****************************************************************************/
extern void SetInlineItemTextEdit(InlineItem *item, PU8 buffer, S32 buffer_size, U32 input_type);

/*****************************************************************************
 * FUNCTION
 *  SetInlineItemTextEdit_ext
 * DESCRIPTION
 *  register validation function of inline text edit
 * PARAMETERS
 *  item                [IN]   inline item         
 *  buffer              [IN]   is the buffer used for editing (It should be initialized to some valid string).      
 *  buffer_size         [IN]   is the size of the buffer.     
 *  input_type          [IN]   is the input type to use.      
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineItemTextEdit_ext(InlineItem *item, U8 *buffer, S32 buffer_size, U32 input_type,S16 input_extended_type, mmi_imm_input_mode_enum *required_input_mode_set);

#ifndef __MMI_INLINE_SLIM__
/*****************************************************************************
 * FUNCTION
 *  SetInlineTextEditCustomFunction
 * DESCRIPTION
 *  register custom function of app for text edit.
 
 *  Only Text, FullScreenEdit, ImageText, MultiLine have this register function.
 *  Custom function will be called when inline activates item.

 * PARAMETERS
 *  item        : [IN]    inline item         
 *  f           : [IN]    custom function    
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineTextEditCustomFunction(InlineItem *item, void (*f) (void));

#endif

/*****************************************************************************
 * FUNCTION
 *  ReConfigureInlineItemTextEdit_ext
 * DESCRIPTION
 *  re-configure inline text edit
 * PARAMETERS
 *  item                : [IN]   inline item         
 *  buffer              : [IN]   buffer      
 *  buffer_size         : [IN]   size of buffer     
 *  input_type          : [IN]   input type         
 * RETURNS
 *  void
 *****************************************************************************/
void ReConfigureInlineItemTextEdit_ext(InlineItem *item, U8 *buffer, S32 buffer_size, U32 input_type,S16 input_extended_type, mmi_imm_input_mode_enum *required_input_mode_set);


/*****************************************************************************
FullScreen edit
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  wgui_inline_get_full_screen_changed
 * DESCRIPTION
 *  get current full screen edit changed status
 * PARAMETERS
 *  void
 * RETURNS
 *  return status
 *****************************************************************************/
extern U8 wgui_inline_get_full_screen_changed(void);


/*****************************************************************************
 * FUNCTION
 *  SetInlineItemFullScreenEdit
 * DESCRIPTION
 *  Set data for Inline FullScreen edit item.
 
 * <img name="wgui_cat57_fullscreen" />
 * PARAMETERS
 *  item            : [IN]      Inline item   
 *  title           : [IN]      Title string  
 *  title_icon      : [IN]      Title icon  
 *  buffer          : [IN]      Buffer   
 *  buffer_size     : [IN]      Size of buffer  
 *  input_type      : [IN]      Input type  
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 *    U8 mmi_myschedule_fill_inlinestruct_for_add(void)
 *    {
 *        SetInlineItemActivation(&(wgui_inline_items[inline_index]),  KEY_LSK, KEY_EVENT_UP);
 *        SetInlineItemFullScreenEdit(
 *        &wgui_inline_items[inline_index],
 *        STR_GLOBAL_EDIT,
 *        IMG_ID_MYSCHEDULE_NOTE,
 *        (PU8) g_mmi_myschedule_cntx.m_record_note,
 *        (MMI_MYSCHEDULE_NOTE_BUFFER_SIZE) / ENCODING_LENGTH,
 *        IMM_INPUT_TYPE_SENTENCE);
 *        inline_index++;
 * 
 *    }
 * </code>
 *****************************************************************************/
extern void SetInlineItemFullScreenEdit(
                InlineItem *item,
                U16 title,
                U16 title_icon,
                PU8 buffer,
                S32 buffer_size,
                U32 input_type);



/*****************************************************************************
 * FUNCTION
 *  SetInlineItemFullScreenEdit_ext
 * DESCRIPTION
 *  set data for inline full screen edit
 * PARAMETERS
 *  item                     : [IN]      inline item   
 *  title                    : [IN]      title string  
 *  title_icon               : [IN]      title icon  
 *  buffer                   : [IN]      buffer   
 *  buffer_size              : [IN]      size of buffer  
 *  input_type               : [IN]      input type      
 *  input_extended_type      : [IN]      input extended type      
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetInlineItemFullScreenEdit_ext(
                InlineItem *item,
                U16 title,
                U16 title_icon,
                PU8 buffer,
                S32 buffer_size,
                U32 input_type,
                S16 input_extended_type);

/*****************************************************************************
 * FUNCTION
 *  SetInlineItemFullScreenEdit_ext2
 * DESCRIPTION
 *  set data for inline full screen edit
 * PARAMETERS
 *  item                     : [IN]      inline item   
 *  title                    : [IN]      title string  
 *  title_icon               : [IN]      title icon  
 *  buffer                   : [IN]      buffer   
 *  buffer_size              : [IN]      size of buffer  
 *  input_type               : [IN]      input type      
 *  input_extended_type      : [IN]      input extended type 
 *  required_input_mode_set  : [IN]      requried input mode set
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineItemFullScreenEdit_ext2(
        InlineItem *item,
        U16 title,
        U16 title_icon,
        U8 *buffer,
        S32 buffer_size,
        U32 input_type,
        S16 input_extended_type,
        mmi_imm_input_mode_enum *required_input_mode_set);

#ifndef __MMI_INLINE_SLIM__
/*****************************************************************************
 * FUNCTION
 *  SetInlineFullScreenEditCustomFunction
 * DESCRIPTION
 *  set custom function of inline full screen edit.
 *  See SetInlineTextEditCustomFunction().
 * PARAMETERS
 *  item                    : [IN]    inline item         
 *  f                       : [IN]    custom function    
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineFullScreenEditCustomFunction(InlineItem *item, void (*f) (void));
#endif

/*****************************************************************************
 * FUNCTION
 *  ReConfigureInlineItemFullScreenEdit_ext
 * DESCRIPTION
 *  re-configure inline full screen edit
 * PARAMETERS
 *  item                    : [IN]      inline item   
 *  title                   : [IN]      title string  
 *  title_icon              : [IN]      title icon  
 *  buffer                  : [IN]      buffer   
 *  buffer_size             : [IN]      size of buffer  
 *  input_type              : [IN]      input type         
 * RETURNS
 *  void
 *****************************************************************************/
void ReConfigureInlineItemFullScreenEdit_ext(
    InlineItem *item,
    U16 title,
    U16 title_icon,
    U8 *buffer,
    S32 buffer_size,
    U32 input_type,
    S16 input_extended_type,
    mmi_imm_input_mode_enum *required_input_mode_set);

/*****************************************************************************
Multiline edit
 *****************************************************************************/

/* Signatures for MultiLine Input Box Inscreen Control. */
#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)



/*****************************************************************************
 * FUNCTION
 *  SetInlineItemMultiLineEdit
 * DESCRIPTION
 *  set data of inline multi line edit.
 * <img name="wgui_cat57_multiline" />
 * PARAMETERS
 *  item            : [IN]    inline item         
 *  buffer          : [IN]    buffer      
 *  title           : [IN]    title string     
 *  buffer_size     : [IN]    size of buffer    
 *  input_type      : [IN]    input type    
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 *    U8 mmi_myschedule_fill_inlinestruct_for_add(void)
 *    {
 *        SetInlineItemActivation(&(wgui_inline_items[inline_index]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
 *        SetInlineItemMultiLineEdit(
 *        &wgui_inline_items[inline_index],
 *        (PU8) g_mmi_myschedule_cntx.m_record_note,
 *        (U8*)GetString(STR_GLOBAL_EDIT),
 *        (MMI_MYSCHEDULE_NOTE_BUFFER_SIZE) / ENCODING_LENGTH,
 *        INPUT_TYPE_USE_ENCODING_BASED_LENGTH | IMM_INPUT_TYPE_SENTENCE);
 *        inline_index++;
 *    }
 * </code>
 *****************************************************************************/
extern void SetInlineItemMultiLineEdit(InlineItem *item, PU8 buffer, PU8 title, S32 buffer_size, U32 input_type);

/*****************************************************************************
 * FUNCTION
 *  SetInlineMultiLineRdOnly
 * DESCRIPTION
 *  Set data for Inline Multiline Read Only item.
 * <img name="wgui_cat57_multililnerdonly" />
 * PARAMETERS
 *  item            : [IN]    Inline item     
 *  buffer          : [IN]    Buffer      
 *  buffer_size     : [IN]    Size of buffer    
 *  input_type      : [IN]    Input type    
 *  max_lines       : [IN]    Max lines    
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 *    U8 mmi_myschedule_fill_inlinestruct_for_add(void)
 *    {
 *        SetInlineItemActivation(&(wgui_inline_items[inline_index]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
 *        SetInlineMultiLineRdOnly(&(wgui_inline_items[inline_index]),
 *            g_mmi_myschedule_cntx.m_record_note,
 *            (MMI_MYSCHEDULE_NOTE_BUFFER_SIZE) / ENCODING_LENGTH,
 *            IMM_INPUT_TYPE_SENTENCE,
 *            1);
 *        inline_index++;
 *    }
 * </code>
 *****************************************************************************/
extern void SetInlineMultiLineRdOnly(InlineItem *item, PU8 buffer, S32 buffer_size, U32 input_type, U8);


/* Inline Multiline Box History Control */
/*****************************************************************************
 * FUNCTION
 *  set_inscreen_multi_line_input_box_changed
 * DESCRIPTION
 *  set inscreen_multi_line_change_flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void set_inscreen_multi_line_input_box_changed(void);

/*****************************************************************************
 * FUNCTION
 *  reset_inscreen_multi_line_input_box_changed
 * DESCRIPTION
 *  reset inscreen_multi_line_change_flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void reset_inscreen_multi_line_input_box_changed(void);

#endif /* defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__) */ 


/*****************************************************************************
 * FUNCTION
 *  SetInlineItemMultiLineHeight
 * DESCRIPTION
 *  Set inline multiline height
 * PARAMETERS
 *  item                : [IN]
 *  n_item              : [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetInlineItemMultiLineHeight(InlineItem *item, S32 n_item);


/*****************************************************************************
 * FUNCTION
 *  SetInlineItemMultiLineCursor_p
 * DESCRIPTION
 *  Set inline multiline cursor postion
 * PARAMETERS
 *  item                : [IN]
 *  Cursor_p              : [IN]    Current cursor postion
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetInlineItemMultiLineCursor_p(InlineItem *item, PU8 Cursor_p);

/*****************************************************************************
Inline Image Text
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  SetInlineItemImageText
 * DESCRIPTION
 *  set data of linline image text.
 * <img name="wgui_cat57_imagetext />
 * PARAMETERS
 *  item            : [IN]      inline item   
 *  text            : [IN]      buffer   
 *  image1          : [IN]      image 1   
 *  image2          : [IN]      image 2  
 *  image3          : [IN]      image 3  
 *  buf_size        : [IN]      size of buffer  
 *  title           : [IN]      title string  
 *  title_icon      : [IN]      title icon  
 *  input_type      : [IN]      input type  
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 *    U8 mmi_myschedule_fill_inlinestruct_for_add(void)
 *   {
 *       SetInlineItemActivation(&wgui_inline_items[inline_index], KEY_LSK, KEY_EVENT_UP);
 *        SetInlineItemImageText(
 *                &wgui_inline_items[inline_index],
 *                (U8*) g_test_image_text,
 *                (PU8) GetImage(IMG_ID_MYSCHEDULE_NOTE),
 *                GetImage(IMG_ID_MYSCHEDULE_NOTE),
 *                GetImage(IMG_ID_MYSCHEDULE_NOTE),
 *                (MMI_MYSCHEDULE_NOTE_BUFFER_SIZE) / ENCODING_LENGTH,
 *                0,
 *               0,
 *               IMM_INPUT_TYPE_SENTENCE);
 *       
 *       SetInlineFullScreenEditCustomFunctionImageText(
 *            &wgui_inline_items[inline_index],
 *            mmi_myschedule_set_fullscreen_lsk);
 *        	 ShowAsControl(&wgui_inline_items[inline_index]); 
 *         	inline_index++;
 * 	}
 * </code>
 *****************************************************************************/
extern void SetInlineItemImageText(
                InlineItem *item,
                PU8 text,
                PU8 image1,
                PU8 image2,
                PU8 image3,
                S32 buf_size,
                U16 title,
                U16 title_icon,
                U32 input_type);

/*****************************************************************************
 * FUNCTION
 *  ShowAsControl
 * DESCRIPTION
 *  show inline item as control
 *  See SetInlineItemImageText().
 * PARAMETERS
 *  item            : [IN]     iniline item's pointer
 * RETURNS
 *  void
 *****************************************************************************/
extern void ShowAsControl(InlineItem *item);

/*****************************************************************************
 * FUNCTION
 *  SetInlineFullScreenEditCustomFunctionImageText
 * DESCRIPTION
 *  set custom function for inline imagetext full screen edit.
 *  See SetInlineItemImageText().
 * PARAMETERS
 *  item                    : [IN]    inline item         
 *  f                       : [IN]    custom function    
 * RETURNS
 *  void

 *****************************************************************************/
extern void SetInlineFullScreenEditCustomFunctionImageText(InlineItem *item, void (*f) (void));

#ifdef __MMI_TOUCH_SCREEN__

/*****************************************************************************
 * FUNCTION
 *  SetInlineImageTextPenHandler
 * DESCRIPTION
 *  Set pen handlers of inline image text.
 *  When pen is down at image, inline layer will call the pen callback registered by app.
 * PARAMETERS
 *  item                : [IN]    inline item         
 *  image2_callback     : [IN]    image2 callback function    
 *  image3_callback     : [IN]    image3 callback function    
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetInlineImageTextPenHandler(InlineItem *item, FuncPtr image2_callback, FuncPtr image3_callback);

#endif


#if defined(__MMI_PHB_PHOTO_STICKER_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  SetInlineItemCaptionThumbnail
 * DESCRIPTION
 *  Set data of inline Caption item Thumbnail
 * PARAMETERS
 *  item        			[IN]			inline item's pointer
 *  text_p      			[IN]    		item's text_p  
 *  thumbnail_path      	[IN]			thumbnail path
 *  buffer_p			[IN]			thumbnail buffer for parser
 *  default_id			[IN]			default id
 *  style				[IN]			1 image id , 2 thumbnail
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetInlineItemCaptionThumbnail(InlineItem *item, PU8 text_p, PU8 thumbnail_path, PU8 buffer_p, U16 default_id, U32 style);


/*****************************************************************************
 * FUNCTION
 *  ReconfigureInlineItemCaptionThumbnail
 * DESCRIPTION
 *  Re-configure data of inline Caption item Thumbnail
 * PARAMETERS
 *  item        			[IN]			inline item's pointer
 *  text_p      			[IN]    		item's text_p   
 *  thumbnail_path      	[IN]			thumbnail path
 *  buffer_p			[IN]			thumbnail buffer for parser
 *  default_id			[IN]			default id
 *  style				[IN]			1 image id , 2 thumbnail
 * RETURNS
 *  void
 *****************************************************************************/
extern void ReconfigureInlineItemCaptionThumbnail(InlineItem *item, PU8 text_p, PU8 thumbnail_path, PU8 buffer_p, U16 default_id, U32 style);
#endif /* __MMI_PHB_PHOTO_STICKER_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  SetInlineItemCaption
 * DESCRIPTION
 *  Set data for Inline Caption item.
 * PARAMETERS
 *  item                : [IN]    Inline item's pointer
 *  text_p              : [IN]    Is a pointer to the text to be displayed for that item    
 * RETURNS
 *  void
 *
 * EXAMPLE
 * <code>
 *   U8 mmi_myschedule_fill_inlinestruct_for_add(void)
 *  {
 *       SetInlineItemActivation(&(wgui_inline_items[inline_index]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
 *       SetInlineItemCaption(&(wgui_inline_items[inline_index]), g_mmi_myschedule_cntx.m_date_strbuff);
 *       inline_index++;
 *   }
 *
 * </code>
 *****************************************************************************/
extern void SetInlineItemCaption(InlineItem *item, PU8 text_p);

/*****************************************************************************
 * FUNCTION
 *  ReconfigureInlineItemCaption
 * DESCRIPTION
 *  Re-configure inline Caption item
 * PARAMETERS
 *  item                : [IN]    Inline item's pointer
 *  text_p              : [IN]    Item's text_p      
 * RETURNS
 *  void
 *****************************************************************************/
extern void ReconfigureInlineItemCaption(InlineItem *item, PU8 text_p);



/*****************************************************************************
Display only
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  SetInlineItemDisplayOnly
 * DESCRIPTION
 *  Set the data for Inline DisplayOnly item. 
 * PARAMETERS
 *  item                : [IN]    Inline item's pointer
 *  text_p              : [IN]    Item's text_p
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 *    U8 mmi_myschedule_fill_inlinestruct_for_add(void)
 *    {
 *        SetInlineItemActivation(&(wgui_inline_items[inline_index]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
 *        SetInlineItemDisplayOnly(&(wgui_inline_items[inline_index]), g_mmi_myschedule_cntx.m_date_strbuff);
 *        inline_index++;
 *    }
 * </code>
 *****************************************************************************/
extern void SetInlineItemDisplayOnly(InlineItem *item, PU8 text_p);

/*****************************************************************************
 * FUNCTION
 *  ReConfigureInlineItemDisplayOnly
 * DESCRIPTION
 *  Re-configure the text_p of inline Display Only item
 * <img name="wgui_cat57_display" />
 * PARAMETERS
 *  item                : [IN]    inline item's pointer
 *  text_p              : [IN]    item's text_p   
 * RETURNS
 *  void
 *****************************************************************************/
extern void ReConfigureInlineItemDisplayOnly(InlineItem *item, PU8 text_p);


/*****************************************************************************
Button
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  SetInlineItemButtion
 * DESCRIPTION
 *  Set the data for Inline button item. 
 * PARAMETERS
 *  item                : [IN]    Inline item's pointer
 *  text_p              : [IN]    Item's text_p
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 *    U8 mmi_myschedule_fill_inlinestruct_for_add(void)
 *    {
 *        SetInlineItemActivation(&(wgui_inline_items[inline_index]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
 *        SetInlineItemButtion(&(wgui_inline_items[inline_index]), g_mmi_myschedule_cntx.m_date_strbuff);
 *        inline_index++;
 *    }
 * </code>
 *****************************************************************************/
extern void SetInlineItemButton(InlineItem *item, U8 *text_p);

/*****************************************************************************
 * FUNCTION
 *  ReConfigureInlineItemButton
 * DESCRIPTION
 *  Re-configure the text_p of inline button item
 * <img name="wgui_cat57_display" />
 * PARAMETERS
 *  item                : [IN]    inline item's pointer
 *  text_p              : [IN]    item's text_p   
 * RETURNS
 *  void
 *****************************************************************************/
extern void ReConfigureInlineItemButton(InlineItem *item, U8 *text_p);

/*****************************************************************************
Inline Horizontal Selector
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  SetInlineItemSelect
 * DESCRIPTION
 *  Set data for Inline Horizontal Select item.
 *  Parameters are similar to the ones passed to any dynamic list, so see any dynamic list Category screen for more details.
 * <img name="wgui_cat57_select" />
 * PARAMETERS
 *  item                    : [IN]    Inline item         
 *  n_items                 : [IN]    Is the number of items in the selection list    
 *  list_of_items        	: [IN]    Is a pointer to a list of strings
 *  highlighted_item  	    : [IN]    Is the zero based index of the item that is shown selected when this screen is displayed    
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 *   static S32 selected_alert_index;
 *   U8 mmi_myschedule_fill_inlinestruct_for_add(void)
 *   {
 *       alert_name_list[0] = (PU8) GetString(STR_GLOBAL_NONE);
 *       alert_name_list[1] = (PU8) GetString(STR_GLOBAL_VIEW);
 *       alert_name_list[2] = (PU8) GetString(STR_GLOBAL_EDIT);
 *       alert_name_list[3] = (PU8) GetString(STR_GLOBAL_DELETE);
 *       alert_name_list[4] = (PU8) GetString(STR_GLOBAL_ADD);
 *       SetInlineItemActivation(&(wgui_inline_items[inline_index]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
 *       SetInlineItemSelect( 
 *               &wgui_inline_items[inline_index],
 *               MAX_PB_ALERT_TYPES,
 *               alert_name_list,
 *               &selected_alert_index);
 *       inline_index++;
 *       RegisterInlineSelectHighlightHandler(&wgui_inline_items[n_items], mmi_audply_audio_effect_inlineitem_highlight_hdlr_1);
 *   }
 * </code>
 *****************************************************************************/
extern void SetInlineItemSelect(InlineItem *item, S32 n_items, PU8 *list_of_items, S32 *highlighted_item);

/*****************************************************************************
 * FUNCTION
 *  RegisterInlineSelectHighlightHandler
 * DESCRIPTION
 *  register inline select highlight handler.
 *  When select item is highlight,inline layer will call hander registered by app. 
 * PARAMETERS
 *  item                : [IN]    inline item         
 *  f                   : [IN]    highlight handler    
 * RETURNS
 *  void

 *****************************************************************************/
void RegisterInlineSelectHighlightHandler(InlineItem *item, void (*f) (S32 item_index));


/*****************************************************************************
 * FUNCTION
 *  ReConfigureInlineItemSelect
 * DESCRIPTION
 *  re-configure of inline select
 * PARAMETERS
 *  item                    : [IN]    inline item         
 *  n_items                 : [IN]    item number    
 *  list_of_items           : [IN]    list of items    
 *  highlighted_item        : [IN]    highlighted item index          
 * RETURNS
 *  void
 *****************************************************************************/
extern void ReConfigureInlineItemSelect(
                InlineItem *item,
                S32 n_items,
                PU8 *list_of_items,
                S32 *highlighted_item);

/*****************************************************************************
Inline user defined select
 *****************************************************************************/
 

/*****************************************************************************
 * FUNCTION
 *  SetInlineItemUserDefinedSelect
 * DESCRIPTION
 *  set data for inline user defined select.
 * <img name="wgui_cat57_userselect" />
 * PARAMETERS
 *  item                        : [IN]    inline item         
 *  current_item_callback       : [IN]    current item callback function    
 *  previous_item_callback      : [IN]    previous item callback function    
 *  next_item_callback          : [IN]    next item callback function    
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 *   U8 mmi_myschedule_fill_inlinestruct_for_add(void)
 *   {
 *       SetInlineItemActivation(&(wgui_inline_items[inline_index]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
 *       SetInlineItemUserDefinedSelect(&wgui_inline_items[inline_index],usertest_func1,usertest_func2,usertest_func3);
 *      inline_index++;
 *   }
 * </code>
 *****************************************************************************/
void SetInlineItemUserDefinedSelect_ext(
        InlineItem *item,
        S16 item_index,
        U8 *(*current_item_callback) (void),
        U8 *(*previous_item_callback) (void),
        U8 *(*next_item_callback) (void));


/*****************************************************************************
 * FUNCTION
 *  ReConfigureInlineItemUserDefinedSelect_ext
 * DESCRIPTION
 *  re-configure inline user defined select
 * PARAMETERS
 *  item                        [IN]    inline item         
 *  current_item_callback       [IN]    current item callback function    
 *  previous_item_callback      [IN]    previous item callback function    
 *  next_item_callback          [IN]    next item callback function        
 * RETURNS
 *  void
 *****************************************************************************/
void ReConfigureInlineItemUserDefinedSelect_ext(
        InlineItem *item,
        S16 item_index,
        U8 *(*current_item_callback) (void),
        U8 *(*previous_item_callback) (void),
        U8 *(*next_item_callback) (void));

/*****************************************************************************
Inline color select
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  SetInlineItemColorSelect
 * DESCRIPTION
 *  Set color inline selection.
 * <img name="wgui_cat57_colorselect />
 * PARAMETERS
 *  item                    : [IN]        Inline item pointer
 *  n_color                 : [IN]        Number of color
 *  hilighted_index         : [IN]        Highlighed color index
 *  list_of_color           : [IN]        Array of colors
 *  color_highlighted       : [IN]        Color highlighted callback function
 * RETURNS: 
 *  void
 * EXAMPLE
 * <code>
 *   static const color g_pen_color_list[MAX_PEN_COLORS] = 
 *   {
 *       {0, 255, 255},
 *       {255, 0, 0},
 *       {0, 255, 0},
 *       {255, 255, 0},
 *       {255, 0, 255},
 *       {255, 128, 0},
 *       {0, 0, 128},
 *       {0, 0, 0}
 *   };
 *   U8 mmi_myschedule_fill_inlinestruct_for_add(void)
 *   {
 *       SetInlineItemActivation(&(wgui_inline_items[inline_index]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
 *       SetInlineItemColorSelect(
 *           &wgui_inline_items[inline_index],
 *           MAX_PEN_COLORS,
 *           (U16) 0,
 *           (color*) g_pen_color_list,
 *           Test_HandwritingSettingInlineColor);
 *       inline_index++;
 *   }
 * </code>
 *****************************************************************************/
void SetInlineItemColorSelect(InlineItem *item, S32 n_color, U16 highlighted_index, color *list_of_color,
                              void (*color_highlighted) (U16 index));


/*****************************************************************************
Inline  DOW select
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  SetInlineItemDOWSelect
 * DESCRIPTION
 *  set data for inline DOW select.
 * DOW is 'day of week'. 
 * <img name="wgui_cat57_DOW" />
 * PARAMETERS
 *  item                : [IN]    inline item         
 *  item_index          : [IN]    item index    
 *  list_of_states      : [IN]    list of states     
 * RETURNS
 *  void
 * EXAMPLE
 * <code>    
 *   static U8 gAlmDaysStates[NUM_DAYS];
 *   U8 mmi_myschedule_fill_inlinestruct_for_add(void)
 *   {
 *      SetInlineItemActivation(&(wgui_inline_items[inline_index]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
 *      SetInlineItemDOWSelect(&(wgui_inline_items[inline_index]), inline_index, gAlmDaysStates);
 *      inline_index++;
 *   }
 * </code>
 *****************************************************************************/
extern void SetInlineItemDOWSelect(InlineItem *item, S32 item_index, PU8 list_of_states);

/*****************************************************************************
 * FUNCTION
 *  ReConfigureInlineItemDOWSelect
 * DESCRIPTION
 *  re-configure inline DOW select.
 * PARAMETERS
 *  item                : [IN]    inline item         
 *  item_index          : [IN]    item index    
 *  list_of_states      : [IN]    list of states           
 * RETURNS
 *  void
 *****************************************************************************/
extern void ReConfigureInlineItemDOWSelect(InlineItem *item, S32 item_index, PU8 list_of_states);

/*****************************************************************************
Inline Radio 
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  SetInlineItemRadio
 * DESCRIPTION
 *  set data for inine radio
 * PARAMETERS
 *  item                    [IN]    inline item      
 *  first_item			[IN]	  first item index in list menu
 *  n_items                 [IN]    item number    
 *  IsSeld		           [IN]    the selected item number in radio list   
 *  text_p	        [IN]    current item text     
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetInlineItemRadio(InlineItem *item, S32 first_item, S32 n_items, S32 IsSeld, PU8 text_p);


/*****************************************************************************
 * FUNCTION
 *  ReconfigureInlineItemRadio
 * DESCRIPTION
 *  recongigure data for inine radio
 * PARAMETERS
 *  item                    [IN]    inline item      
 *  first_item			[IN]	  first item index in list menu
 *  n_items                 [IN]    item number    
 *  IsSeld		           [IN]    the selected item number in radio list   
 *  text_p	        [IN]    current item text     
 * RETURNS
 *  void
 *****************************************************************************/
extern void ReconfigureInlineItemRadio(InlineItem *item, S32 first_item, S32 n_items, S32 IsSeld, PU8 text_p);


/*****************************************************************************
 * FUNCTION
 *  SetInlineRadioSelectFunction
 * DESCRIPTION
 *  for focus change callback function
 * PARAMETERS
 *  item                    [IN]    inline item      
 *  cb				[IN]	  focus change call back function
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetInlineRadioSelectFunction(InlineItem *item, radio_selected cb);


/*****************************************************************************
Inline CheckBox 
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  SetInlineItemCheckBox
 * DESCRIPTION
 *  set data for inine checkbox
 * PARAMETERS
 *  item                    [IN]    inline item      
 *  text_p	        [IN]    current item text     
 *  IsSeld		           [IN]    the selected flag  
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetInlineItemCheckBox(InlineItem *item, PU8 text_p, MMI_BOOL IsSeld);


/*****************************************************************************
 * FUNCTION
 *  ReconfigureInlineItemCheckBox
 * DESCRIPTION
 *  reconfigure data for inine checkbox
 * PARAMETERS
 *  item                    [IN]    inline item      
 *  text_p	        [IN]    current item text     
 *  IsSeld		           [IN]    the selected flag  
 * RETURNS
 *  void
 *****************************************************************************/
extern void ReconfigureInlineItemCheckBox(InlineItem *item, PU8 text_p, MMI_BOOL IsSeld);
extern void SetInlineCheckboxChangeFunction(InlineItem *item, checkbox_change cb);
/*****************************************************************************
Inline date edit 
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  SetInlineItemDate
 * DESCRIPTION
 *  Set data for Inline DateEdit item.
 * <img name="wgui_cat57_date" />
 *  The parameters are similar to the ones passed to Category 26 screen. See Category 26 screen for more details.
 *  f	 is a pointer to a function with the following signature:
 *    	  void MyDateStringConstructor(U8* string_buffer,U8* day_buffer,U8* month_buffer,U8* year_buffer);
 *    	  This function makes the string to be displayed in the menu. This function typically makes a string by concatenating the various buffers passed to it.

 *      Output parameters:
 *      string_buffer is a pointer to a valid string. This string is allocated by Category57 screen internal and should not be re-allocated or freed by the application. This function writes into the string_buffer (see usage example), so this function should be implemented to take care that it writes only within the allocated size. The currently available size is 24 bytes.
 *                                          
 *      Input parameters:
 *      day_buffer:     buffer containing the day
 *      month_buffer:   buffer containing the month
 *      year_buffer:    buffer containing the year
 *                                            
 *      Currently the application has to provide this function, but later there may be a standard one available which can return the date string based on the locale.
 * PARAMETERS
 *  item                	: [IN]    Inline item     
 *  day_buffer       	    : [IN]    Day buffer     
 *  month_buffer   	        : [IN]    Month buffer     
 *  year_buffer  	        : [IN]    Year buffer     
 *  f               		: [IN]    Is a pointer to a function.
 * RETURNS
 *  void
 * EXAMPLE
 * <code> 
 *  U8 mmi_myschedule_fill_inlinestruct_for_add(void)
 *  {
 *      SetInlineItemActivation(&(wgui_inline_items[inline_index]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
 *      SetInlineItemDate(
 *           &(wgui_inline_items[inline_index]),
 *          (U8*) g_mmi_myschedule_cntx.m_daybuff,
 *          (U8*) g_mmi_myschedule_cntx.m_monbuff,
 *          (U8*) g_mmi_myschedule_cntx.m_yearbuff,
 *          mmi_myschedule_date_convert);  
 *      DisableInlineItemHighlight(&wgui_inline_items[inline_index]);
 *      set_inline_date_boundary(
 *          MMI_MYSCHEDULE_END_YEAR,
 *          MMI_MYSCHEDULE_START_YEAR,
 *          MMI_MYSCHEDULE_MONTH_COUNTS,
 *          MMI_MYSCHEDULE_MONTH_START);
 *      inline_index++;
 *   }
 * </code> 
 *****************************************************************************/
void SetInlineItemDate(InlineItem *item, PU8 day_buffer, PU8 month_buffer, PU8 year_buffer,
                       void (*f) (PU8 string_buffer, PU8 day_buffer, PU8 month_buffer, PU8 year_buffer));


/*****************************************************************************
 * FUNCTION
 *  ReConfigureInlineItemDate
 * DESCRIPTION
 *  re-configure of inline date
 * PARAMETERS
 *  item                : [IN]    inline item     
 *  day_buffer          : [IN]    day buffer     
 *  month_buffer        : [IN]    month buffer     
 *  year_buffer         : [IN]    year buffer     
 *  f                   : [IN]    string construct callback        
 * RETURNS
 *  void
 *****************************************************************************/
void ReConfigureInlineItemDate(InlineItem *item, PU8 day_buffer, PU8 month_buffer, PU8 year_buffer,
                               void (*f) (PU8 string_buffer, PU8 day_buffer, PU8 month_buffer,
                                          PU8 year_buffer));
/*****************************************************************************
Inline time period 
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  SetInlineItemTimePeriod
 * DESCRIPTION
 *  Set data for Inline TimePeriod item.
 * <img name="wgui_cat57_timeperiod" />
 * PARAMETERS
 *  item                : [IN]      Inine item   
 *  hours_buffer1       : [IN]      Hours buffer1   
 *  minutes_buffer1     : [IN]      Minutes buffer1   
 *  AM_PM_flag1         : [IN]      Flag1 of AM_PM   
 *  hours_buffer2       : [IN]      Hours buffer2   
 *  minutes_buffer2     : [IN]      Minutes buffer2   
 *  AM_PM_flag2         : [IN]      Flag2 of AM_PM   
 *  f                   : [IN]      String construct callback  
 * RETURNS
 *  void
 * EXAMPLE
 * <code> 
 *  U8 mmi_myschedule_fill_inlinestruct_for_add(void)
 *  {
 *      SetInlineItemActivation(&(wgui_inline_items[inline_index]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
 *      SetInlineItemTimePeriod(
 *          &(wgui_inline_items[inline_index]),
 *          (U8*) hour_buf,
 *          (U8*) min_buf,
 *          NULL,
 *          (U8*) hour_buf_1,
 *          (U8*) min_buf_1,
 *          NULL,
 *          mmi_fmrdo_scheduler_time_edit_callback);
 *      inline_index++;
 *  }
 * </code> 
 *****************************************************************************/
void SetInlineItemTimePeriod(InlineItem *item, PU8 hours_buffer1, PU8 minutes_buffer1, PU8 AM_PM_flag1,
                             PU8 hours_buffer2, PU8 minutes_buffer2, PU8 AM_PM_flag2,
                             void (*f) (PU8 string_buffer, PU8 hours_buffer1, PU8 minutes_buffer1,
                                        PU8 AM_PM_flag1, PU8 hours_buffer2, PU8 minutes_buffer2,
                                        PU8 AM_PM_flag2));

/*****************************************************************************
 * FUNCTION
 *  ReConfigureInlineItemTimePeriod
 * DESCRIPTION
 *  re-configure data of inline time period
 * PARAMETERS
 *  item                : [IN]      inine item   
 *  hours_buffer1       : [IN]      hours buffer1   
 *  minutes_buffer1     : [IN]      minutes buffer1   
 *  AM_PM_flag1         : [IN]      flag1 of AM_PM   
 *  hours_buffer2       : [IN]      hours buffer2   
 *  minutes_buffer2     : [IN]      minutes buffer2   
 *  AM_PM_flag2         : [IN]      flag2 of AM_PM   
 *  f                   : [IN]      string construct callback        
 * RETURNS
 *  void

 *****************************************************************************/
void ReConfigureInlineItemTimePeriod(InlineItem *item, PU8 hours_buffer1, PU8 minutes_buffer1, PU8 AM_PM_flag1,
                                     PU8 hours_buffer2, PU8 minutes_buffer2, PU8 AM_PM_flag2,
                                     void (*f) (PU8 string_buffer, PU8 hours_buffer1, PU8 minutes_buffer1,
                                                PU8 AM_PM_flag1, PU8 hours_buffer2, PU8 minutes_buffer2,
                                                PU8 AM_PM_flag2));


/*****************************************************************************
Inline time edit
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  SetInlineItemTime
 * DESCRIPTION
 *  Set data for Inline TimeEdit item.
 * <img name="wgui_cat57_time" />
 *  These parameters are similar to the ones passed to Category 27 screen.
 *  AM_PM_flag is  not implemented currently. Just pass a pointer to a valid U8 data for this. See the usage examples below for the use of this flag.
 *                                                  
 *  f is a function pointer to an application implemented function. This is similar to the one passed for inline DateEdit item. So see the above explanation for this.
 *                                                    
 *  To add the new inline item in the category following functions(Present in example, like SetInlineItemActivation, SetInlineItemTime) must be called in sequence.
 *  Note, each item passed in the list must be initialized. So the following functions(Present in example, like SetInlineItemActivation, SetInlineItemTime) must have been called for each item prior to the call to the Category57 screen. 
 * PARAMETERS
 *  item                : [IN]       Inline item         
 *  hours_buffer        : [IN]       Hours buffer  
 *  minutes_buffer      : [IN]       Minutes buffer  
 *  AM_PM_flag          : [IN]       Flag for AM_PM  
 *  f                   : [IN]       String construct callback 
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 *  U8 mmi_myschedule_fill_inlinestruct_for_add(void)
 *  {
 *      SetInlineItemActivation(&(wgui_inline_items[inline_index]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
 *      SetInlineItemTime(
 *           &(wgui_inline_items[inline_index]),
 *          (U8*) HourBuff1,
 *          (U8*) MinBuff1,
 *          NULL,
 *          mmi_tdl_time_editor_callback);
 *      inline_index++;
 *  }
 * </code> 
 *****************************************************************************/
void SetInlineItemTime(InlineItem *item, PU8 hours_buffer, PU8 minutes_buffer, PU8 AM_PM_flag,
                       void (*f) (PU8 string_buffer, PU8 hours_buffer, PU8 minutes_buffer, PU8 AM_PM_flag));

/*****************************************************************************
 * FUNCTION
 *  ReConfigureInlineItemTime
 * DESCRIPTION
 *  re-configure for inline time edit
 * PARAMETERS
 *  item                : [IN]       inline item         
 *  hours_buffer        : [IN]       hours buffer  
 *  minutes_buffer      : [IN]       minutes buffer  
 *  AM_PM_flag          : [IN]       flag for AM_PM  
 *  f                   : [IN]       string construct callback       
 * RETURNS
 *  void
 *****************************************************************************/
void ReConfigureInlineItemTime(InlineItem *item, PU8 hours_buffer, PU8 minutes_buffer, PU8 AM_PM_flag,
                               void (*f) (PU8 string_buffer, PU8 hours_buffer, PU8 minutes_buffer,
                                          PU8 AM_PM_flag));

/*****************************************************************************
Inline IP4
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  SetInlineItemIP4
 * DESCRIPTION
 *  Set data for Inline IP4 edit item.
 * <img name="wgui_cat57_ip4" />
 * PARAMETERS
 *  item                : [IN]    Inline item         
 *  b1                  : [IN]    Address part 1     
 *  b2                  : [IN]    Address part 2     
 *  b3                  : [IN]    Address part 3     
 *  b4                  : [IN]    Address part 4     
 *  f                   : [IN]    String construct callback    
 * RETURNS
 *  void
 * EXAMPLE
 * <code> 
 *  #define EM_SOCKET_IP_LEN   4
 *  U8 EmSocketIP1[EM_SOCKET_IP_LEN * ENCODING_LENGTH] = {'1',0,'2',0,'7',0};
 *  U8 EmSocketIP2[EM_SOCKET_IP_LEN * ENCODING_LENGTH] = {'0',0};   
 *  U8 EmSocketIP3[EM_SOCKET_IP_LEN * ENCODING_LENGTH] = {'0',0};
 *  U8 EmSocketIP4[EM_SOCKET_IP_LEN * ENCODING_LENGTH] = {'1',0};
 *  U8 mmi_myschedule_fill_inlinestruct_for_add(void)
 *  {
 *      SetInlineItemActivation(&(wgui_inline_items[inline_index]), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
 *      SetInlineItemIP4(
 *          (&wgui_inline_items[inline_index]),
 *          (U8*) EmSocketIP1,
 *          (U8*) EmSocketIP2,
 *          (U8*) EmSocketIP3,
 *          (U8*) EmSocketIP4,
 *          PreparedIPAddressString);
 *      inline_index++;    
 *  }
 * </code> 
 *****************************************************************************/
void SetInlineItemIP4(InlineItem *item, PU8 b1, PU8 b2, PU8 b3, PU8 b4,
                      void (*f) (PU8 string_buffer, PU8 b1, PU8 b2, PU8 b3, PU8 b4));


/*****************************************************************************
 * FUNCTION
 *  ReConfigureInlineItemIP4
 * DESCRIPTION
 *  re-configure data of inline IP4 edit
 * PARAMETERS
 *  item                : [IN]    inline item         
 *  b1                  : [IN]    address part 1     
 *  b2                  : [IN]    address part 2     
 *  b3                  : [IN]    address part 3     
 *  b4                  : [IN]    address part 4     
 *  f                   : [IN]    string construct callback        
 * RETURNS
 *  void
 
 *****************************************************************************/
void ReConfigureInlineItemIP4(InlineItem *item, PU8 b1, PU8 b2, PU8 b3, PU8 b4,
                              void (*f) (PU8 string_buffer, PU8 b1, PU8 b2, PU8 b3, PU8 b4));

#ifdef __MMI_FTE_SUPPORT__ 
#if defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  inline_is_handle_fte_tap
 * DESCRIPTION
 *  handle inline tap behavior
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL inline_is_handle_fte_tap(mmi_tap_type_enum tap_type, U16 index);
#endif /* __MMI_TOUCH_SCREEN__ */

/*****************************************************************************
 * FUNCTION
 *  wgui_inline_smooth_scrolling_by_pen
 * DESCRIPTION
 *  set whether ssp call this redraw.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void wgui_inline_set_ssp_redraw_state(MMI_BOOL state);

/*****************************************************************************
 * FUNCTION
 *  wgui_inline_shift_input_cursor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * 
 *****************************************************************************/
void wgui_inline_shift_input_cursor(S32 first_display, S32 last_display, S32 index, S32 y);


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_stop_scroll_when_ssp
 * DESCRIPTION
 * Stop scroll when ssp is run.
 * PARAMETERS
 *       
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_stop_scroll_when_ssp(void);

#endif

/*****************************************************************************
 * FUNCTION
 *  inline_fte_set_item_show_as_display_only
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * 
 *****************************************************************************/
void wgui_inline_fte_set_item_show_as_display_only(wgui_inline_item *inline_item);


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_fte_reset_item_show_as_display_only
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * 
 *****************************************************************************/
void wgui_inline_fte_reset_item_show_as_display_only(wgui_inline_item *inline_item);


/*****************************************************************************
 * FUNCTION
 *  set_leading_zero
 * DESCRIPTION
 *  set the flag whether zero is allowed as first number or not
 * PARAMETERS
 *  operation      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_set_leading_zero_style(wgui_inline_item *item, MMI_BOOL operation);


/*****************************************************************************
 * FUNCTION
 *  SetInlineItemProgressBar
 * DESCRIPTION
 *  
 * PARAMETERS
 *      
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineItemProgressBar(InlineItem *item, void(*funcptr)(void), U16* value, U16 max_value, U16 step_size);


/*****************************************************************************
 * FUNCTION
 *  SetInlineItemProgressBarStyle
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  void
 *****************************************************************************/
void SetInlineItemProgressBarStyle(InlineItem *item, U32 flags);

/*****************************************************************************
 * FUNCTION
 *  EntryScrForInputMethodAndDone
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrForInputMethodAndDone(void);

#ifndef __MMI_INLINE_SLIM__

/*****************************************************************************
 * FUNCTION
 *  wgui_inline_set_selector_no_loop
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_set_selector_no_loop(InlineItem *item, MMI_BOOL operation);

#endif

/*****************************************************************************
 * FUNCTION
 *  wgui_inline_set_displayonly_no_num_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_set_displayonly_no_num_key(InlineItem *item, MMI_BOOL operation);


/*****************************************************************************
 * FUNCTION
 *  wgui_inline_set_item_selector_by_string_id
 * DESCRIPTION
 *  set data for inine select by string id
 * PARAMETERS
 *  item                   : [IN]    inline item         
 *  n_items                : [IN]    item number    
 *  list_of_string_id      : [IN]    list of string id    
 *  highlighted_item       : [IN]    highlighted item index     
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_inline_set_item_selector_by_string_id(InlineItem *item, S32 n_items, U16 *list_of_string_id, S32 *highlighted_item);

/*****************************************************************************
* FUNCTION
*  wgui_inline_ml_rdly_set_hilite_list
* DESCRIPTION
*  Set highlight list for multiline readonly item.
* PARAMETERS
* RETURNS
*  characters inserted
*****************************************************************************/
void wgui_inline_ml_rdly_set_hilite_list( 
	wgui_inline_item  *item,
  	wgui_inline_ml_rdly_highlight_list_struct *highlight_list);


/*****************************************************************************
* FUNCTION
SetInlineItemTextEditDefaultItemNameIfEmpty_with_string *  SetInlineItemTextEditDefaultItemNameIfEmpty
* DESCRIPTION
 *  Sets the pointer item->text_p to point to default item text.
 *  Only if the singleline item 's text is empty and inline layer allows to set default text,the function is valid.
 *  This function is just for singleline.
* PARAMETERS
 *  item                :[IN] Is the pointer to InlineItem structure.
 *  default_text_id     :[IN] Is the string Id of the default text.
* RETURNS
 *  void
*****************************************************************************/
void wgui_inline_set_text_edit_first_cursor(InlineItem *item, MMI_BOOL operation);

void SetInlineItemTextEditDefaultItemNameIfEmpty_with_string(InlineItem *item, U8 *default_text);

/*****************************************************************************
* FUNCTION
*  wgui_inline_text_edit_move_cursor_to_first
* DESCRIPTION
*  
* PARAMETERS
* RETURNS
*  
*****************************************************************************/
void wgui_inline_text_edit_move_cursor_to_first(single_line_input_box *b);

#ifdef __MMI_INLINE_SLIM__

/*****************************************************************************
* FUNCTION
*  wgui_inline_set_char_filter
* DESCRIPTION
*  
* PARAMETERS
* RETURNS
*  
*****************************************************************************/
void wgui_inline_set_char_filter(S32 item_index, MMI_BOOL is_allowed, const UI_character_type *characters_list);



/*****************************************************************************
* FUNCTION
*  wgui_inline_set_parent_group
* DESCRIPTION
*  
* PARAMETERS
* RETURNS
*  
*****************************************************************************/
void wgui_inline_set_parent_group(MMI_ID parent_id);

#endif

/*****************************************************************************
 * FUNCTION
 *  wgui_inline_set_op_parent_group
 * DESCRIPTION
 *  Set parent  for inline screen option screen.
 * PARAMETERS
 *  MMI_ID  [IN] parent_id
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_inline_set_op_parent_group(MMI_ID parent_id);

/*****************************************************************************
 * FUNCTION
 *  wgui_inline_set_lsk_function
 * DESCRIPTION
 *  Changes the handler of softkeys for inline
 * PARAMETERS
 *  f       [IN]        Handler function
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_inline_set_lsk_function(void (*f) (void));

#endif /* __WGUI_INLINE_EDIT_H__ */ 



