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
 *  wgui_categories_panel.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *   exported interface for categories with panel component
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
 *==============================================================================
 *******************************************************************************/
#ifndef WGUI_CATEGORIES_PANEL_H
#define WGUI_CATEGORIES_PANEL_H

#ifdef __MMI_BT_MTK_SUPPORT__
#if defined(__MMI_HIDD_SUPPORT__) && defined(__MMI_HID_BQP_SUPPORT__)

/***************************************************************************** 
 * Include
 *****************************************************************************/
/*RHR*/
    #include "MMIDataType.h"
    #include "wgui_categories_list.h"
    #include "kal_general_types.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
    
/* structure for 1 button on cat95 */
typedef struct
{   
    S32 x;                          
    S32 y;
    S32 width;
    S32 height;
    U16 keycode;                    //corresponding key
    FuncPtr down_event_callback;
    FuncPtr up_event_callback;      
    FuncPtr repeat_event_callback;
    MMI_ID_TYPE disable_imageid;    //image if the button is disabled
    MMI_ID_TYPE off_imageid;        //image if the button is in normal state
    MMI_ID_TYPE on_imageid;         //image if the button gets focused
    MMI_ID_TYPE down_imageid;       //image if the button is pressed
    MMI_BOOL    enabled;            /* Is Panel item enabled.  MMI_TRUE = enabled, MMI_FALSE = disabled */ 
} wgui_cat95_panel_element_struct;


/*****************************************************************************
 * FUNCTION
 *  ShowCategory95Screen
 * DESCRIPTION
 *  This category is an example using ¡§Panel¡¨ component.
 *  Applications with many buttons to be interacted with users can be easily implemented by calling this category screen.
 * 
 * <img name="wgui_cat095_img1" />
 * PARAMETERS
 *   title                         : [IN ] (TITLE) Title for the screen
 *   left_softkey                  : [IN ] (LSK) Left softkey label
 *   left_softkey_icon             : [IN ] (N/A) Left softkey icon
 *   right_softkey                 : [IN ] (RSK) Right softkey label
 *   right_softkey_icon            : [IN ] (N/A) Right softkey icon
 *   history_buffer                : [IN ] (N/A) History buffer
 *   bg_id                         : [IN ] (N/A) panel background image id
 *   element_list                  : [IN ] (N/A) list of panel elements
 *   num_of_element                : [IN ] (N/A) number of panel elements
 *   focused_element               : [IN ] (N/A) focused panel element
 *   repeat_period                 : [IN ] (N/A) period of repeat events in milliseconds (0 for default)
 *   history_buffer                : [IN ] (N/A) history buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_95(void)
 * {
 *     U8 *guiBuffer = NULL;
 *     wgui_cat95_panel_element_struct element[17];
 *     S32 i;
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     for(i = 0; i < 12; i++)//1, 2, 3, 4, 5, 6, 7, 8, 9, *, 0, #
 *     {
 *         element[i].x = cat95_icon_pos[i][0];
 *         element[i].y = cat95_icon_pos[i][1];
 *         element[i].width = cat95_icon_pos[i][2];
 *         element[i].height = cat95_icon_pos[i][3];
 *         element[i].keycode = KEY_1+i;
 *         element[i].down_event_callback = NULL; 
 *         element[i].up_event_callback = NULL;
 *         element[i].repeat_event_callback = NULL;
 *         element[i].disable_imageid = IMG_ID_CSB_DESKTOP_IMG_01_DISALBE+i*4;
 *         element[i].off_imageid = IMG_ID_CSB_DESKTOP_IMG_01_OFF+i*4;
 *         element[i].on_imageid = IMG_ID_CSB_DESKTOP_IMG_01_ON+i*4;
 *         element[i].down_imageid = IMG_ID_CSB_DESKTOP_IMG_01_DOWN+i*4;
 *     }
 *     element[9].keycode = KEY_STAR;
 *     element[10].keycode = KEY_0;
 *     element[11].keycode = KEY_POUND;
 * 
 *     
 *     for(i = 12; i < 16; i++)//up, donw, left, right
 *     {
 *         element[i].x = cat95_icon_pos[i][0];
 *         element[i].y = cat95_icon_pos[i][1];
 *         element[i].width = cat95_icon_pos[i][2];
 *         element[i].height = cat95_icon_pos[i][3];
 *         element[i].keycode = KEY_UP_ARROW+i-12;
 *         element[i].down_event_callback = NULL; 
 *         element[i].up_event_callback = NULL;
 *         element[i].repeat_event_callback = NULL;
 *         element[i].disable_imageid = IMG_ID_CSB_MOUSE_IMG_UP_DISALBE+(i-12)*4;
 *         element[i].off_imageid = IMG_ID_CSB_MOUSE_IMG_UP_OFF+(i-12)*4;
 *         element[i].on_imageid = IMG_ID_CSB_MOUSE_IMG_UP_ON+(i-12)*4;
 *         element[i].down_imageid = IMG_ID_CSB_MOUSE_IMG_UP_DOWN+(i-12)*4;
 *     }
 *     
 *     //center key for displaing mouse only, no key handler
 *     element[16].x = cat95_icon_pos[16][0];
 *     element[16].y = cat95_icon_pos[16][1];
 *     element[16].width = cat95_icon_pos[16][2];
 *     element[16].height = cat95_icon_pos[16][3];
 *     element[16].keycode = KEY_INVALID;
 *     element[16].down_event_callback = NULL; 
 *     element[16].up_event_callback = NULL;
 *     element[16].repeat_event_callback = NULL;
 *     element[16].disable_imageid = IMG_ID_CSB_MOUSE_IMG_COMMON;
 *     element[16].off_imageid = IMG_ID_CSB_MOUSE_IMG_COMMON;
 *     element[16].on_imageid = IMG_ID_CSB_MOUSE_IMG_COMMON;
 *     element[16].down_imageid = IMG_ID_CSB_MOUSE_IMG_COMMON;
 *     
 *     ShowCategory95Screen(
 *         (U8 *)GetString(STR_ID_CSB_CATEGORY_TEXT), 
 *         NULL, 
 *         NULL, 
 *         STR_GLOBAL_BACK,
 *         IMG_GLOBAL_BACK,
 *         IMG_ID_CSB_HID_IMG_BG,
 *         element, 
 *         16, 
 *         0, 
 *         0,
 *         guiBuffer);
 * 
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory95Screen(
                U8 *title,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                MMI_ID_TYPE bg_id,
                wgui_cat95_panel_element_struct *element_list,
                S32 num_of_element,
                S32 focused_element,
                U32 repeat_period,
                U8 *history_buffer);
#endif
#endif
/*
#ifdef __MMI_BT_MTK_SUPPORT__
#if defined(__MMI_HIDD_SUPPORT__) && defined(__MMI_HID_BQP_SUPPORT__)
*/
    
#endif /* WGUI_CATEGORIES_PANEL_H */ 
    
    
    
    
    
    
    
    

