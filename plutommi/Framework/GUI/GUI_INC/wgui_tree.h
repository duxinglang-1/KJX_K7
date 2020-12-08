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
 *  wgui_tree.h
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  Tree list header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __WGUI_TREE_H__
#define __WGUI_TREE_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMIDataType.h"
#include "gui_typedef.h"
#include "kal_general_types.h"
#include "gui.h"
#include "gui_data_types.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define WGUI_TREE_MAX_LEVEL_NUM                 4
#define WGUI_TREE_MAX_TOTAL_COORDINATES         16

#define WGUI_TREE_ITEM_NUMBER_UNCHANGED         -1
#define WGUI_TREE_HIGHLIGHT_DONTCARE            -1

#define WGUI_TREE_GET_LEVEL(i)      (wgui_tree_p->get_level_funcptr(i))
#define WGUI_TREE_GET_STATE(i)      (wgui_tree_p->get_state_funcptr(i))
#define WGUI_TREE_SET_STATE(i, st)  wgui_tree_p->set_state_funcptr(i, st)

#define WGUI_TREE_ITEM_FLAG_PARENT  (1 << 1)
#define WGUI_TREE_ITEM_FLAG_HIDDEN  (1 << 0)

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef S32 (*wgui_tree_get_item_callback_funcptr_type)(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size);
typedef GetAsyncHintFuncPtr wgui_tree_get_hint_callback_funcptr_type;

typedef S32 (*wgui_tree_get_item_level_callback_funcptr_type)(S32 item_index);
typedef S32 (*wgui_tree_get_item_state_callback_funcptr_type)(S32 item_index);
typedef void (*wgui_tree_set_item_state_callback_funcptr_type)(S32 item_index, S32 state);

typedef MMI_BOOL (*wgui_tree_folder_clicked_callback_funcptr_type)(S32 item_index);


typedef struct
{
    U8  text_num;
    U8  icon_num;
    U8  coordinate_start_index;
} wgui_tree_level_struct;

typedef struct
{
    UI_object_coordinates coordinate;
    UI_font_type font;
    color color;
} wgui_tree_level_coordinate_struct;

typedef struct
{
    S32 n_items;
    S32 viewable_n_items;

    wgui_tree_get_item_callback_funcptr_type get_item_funcptr;
    wgui_tree_get_hint_callback_funcptr_type get_hint_funcptr;
    wgui_tree_get_item_level_callback_funcptr_type get_level_funcptr;    
    wgui_tree_get_item_state_callback_funcptr_type get_state_funcptr;
    wgui_tree_set_item_state_callback_funcptr_type set_state_funcptr;  
    wgui_tree_folder_clicked_callback_funcptr_type folder_clicked_funcptr;

    void (*highlight_handler)(S32 item_index);

    S32 level_num;    
    wgui_tree_level_struct level_info[WGUI_TREE_MAX_LEVEL_NUM];    
    wgui_tree_level_coordinate_struct item_coordinates[WGUI_TREE_MAX_TOTAL_COORDINATES];
    U8 level_buffer[MAX_ASYNCDYNAMIC_ITEMS_BUFF];    
    
    U8 allocated_coordinate_num;  
} wgui_tree_struct;

typedef enum
{
    WGUI_TREE_ITEM_STATE_NORMAL_SHOW = 0,
    WGUI_TREE_ITEM_STATE_RESET = WGUI_TREE_ITEM_STATE_NORMAL_SHOW,    
    WGUI_TREE_ITEM_STATE_NORMAL_HIDDEN = WGUI_TREE_ITEM_FLAG_HIDDEN,
    WGUI_TREE_ITEM_STATE_PARENT_EXPANDED = WGUI_TREE_ITEM_FLAG_PARENT,
    WGUI_TREE_ITEM_STATE_PARENT_COLLAPSED = WGUI_TREE_ITEM_FLAG_PARENT | WGUI_TREE_ITEM_FLAG_HIDDEN
} wgui_tree_item_state_enum;

/***************************************************************************** 
 * Global Function
 *****************************************************************************/
extern void wgui_tree_create(
        S32 item_num,
        S32 level_num,
        S32 menu_item_height,
        wgui_tree_get_item_callback_funcptr_type get_item_callback,
        wgui_tree_get_hint_callback_funcptr_type get_hint_callback,
        wgui_tree_get_item_level_callback_funcptr_type get_level_callback,    
        wgui_tree_get_item_state_callback_funcptr_type get_state_callback,
        wgui_tree_set_item_state_callback_funcptr_type set_state_callback,
        wgui_tree_folder_clicked_callback_funcptr_type folder_clicked_callback,
        void (*highlight_handler)(S32 item_index),
        S32 highlighted_item,        
        U16 history_id,
        PU8 history_buffer);
        
extern void wgui_tree_close(void);
extern void wgui_tree_set_level_coordinate_num(S32 level_index, S32 text_num, S32 icon_num);
extern void wgui_tree_set_text_coordinate(S32 level_index, S32 i, S32 x, S32 y, S32 width, S32 height);
extern void wgui_tree_set_icon_coordinate(S32 level_index, S32 i, S32 x, S32 y, S32 width, S32 height);
extern void wgui_tree_show(void);
extern void wgui_tree_update(S32 item_num, S32 highlight_index);
extern void wgui_tree_set_text_font(S32 level_index, S32 i, UI_font_type font);

extern MMI_BOOL wgui_tree_is_parent_node(S32 item_index);
extern MMI_BOOL wgui_tree_is_hidden_node(S32 item_index);

extern void wgui_tree_expand_all(void);
extern void wgui_tree_collapse_all(void);

extern S32 wgui_tree_get_viewable_item_num(void);
extern S32 wgui_tree_get_item_num(void);
extern S32 wgui_tree_translate_viewable_index_to_item_index(S32 item_index);

#endif /* __WGUI_TREE_H__ */


