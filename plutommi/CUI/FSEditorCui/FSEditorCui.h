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
 *  FSEditorCui.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MMI_FSEDITORCUI_H
#define MMI_FSEDITORCUI_H

#ifdef __cplusplus
extern "C"{
#endif 

//#include "MMI_include.h"

    #include "MMIDataType.h"
    #include "kal_general_types.h"
    #include "ImeGprot.h"
    #include "gui_data_types.h"

#ifdef __cplusplus
}
#endif




/***************************************************************************** 
*  Define
*****************************************************************************/
#define CUI_FSEDITOR_MAX_BUFFER_SIZE           512

/***************************************************************************** 
*  Typedef 
*****************************************************************************/
typedef enum
{
    CUI_FSEDITOR_STATE_NONE = 0,
    CUI_FSEDITOR_STATE_CREATE,
    CUI_FSEDITOR_STATE_RUN,
    CUI_FSEDITOR_STATE_CLOSE,
    CUI_FSEDITOR_STATE_END
} cui_fseditor_state_enum;

typedef struct
{
    MMI_BOOL set_characters_flag;
    MMI_BOOL lsk_change_flag;
    MMI_BOOL csk_change_flag;
    MMI_BOOL buffer_change_flag;
    MMI_BOOL disable_def_opt_menu_flag; /* Disable default option menu (Done) or not */
    MMI_BOOL disable_cancel_item;       /* Disable Cancel option menu item */
    MMI_BOOL is_title_in_header;        /* Draw title in editor header area */
    MMI_BOOL set_cursor_first_pos;      /* set cursor position to first beginning */
    MMI_BOOL is_auto_display_counter;   /* set cursor position to first beginning */
    MMI_BOOL is_delete_all;   /* set cursor position to first beginning */
    MMI_BOOL is_disable_ncenter;   /* disable ncenter or not */
    U8  memory_id;
    U8  options_cust_menu_count;        /* App customized menu item count */
    cui_fseditor_state_enum state;
    U16 title;                          /* title label */
    U16 title_icon;                     /* title icon */
    U16 lsk_label;
    U16 lsk_icon;
    U16 rsk_label;
    U16 rsk_icon;
    U16 csk_label;
    U16 csk_icon;
    U16 options_done_label;             /* Done label in Option menu */
    U16 options_cancel_label;           /* Cancel label in Option menu */
    U16 editor_scr_id, editor_options_scr_id;
    S16 input_ext_type;                 /* extended input type */
    PU16 options_cust_menu_list;        /* App customized menu item */
    const WCHAR *title_string;          /* title string */
    WCHAR *buffer;
    WCHAR text_buffer[CUI_FSEDITOR_MAX_BUFFER_SIZE / 2];   /* buffer for editor */
    S32 buffer_size;              /* buffer size */
    S32 edit_length;              /* Edit limit length */
    U32 input_type;               /* input type */
    U32 parent_data;              /* parent data */
    const mmi_imm_input_mode_enum *required_input_mode_set; /* input mode set */
    const UI_character_type *set_characters_list;
} cui_fseditor_struct;


/***************************************************************************** 
*  Extern Variables
*****************************************************************************/


/***************************************************************************** 
*  Global Variables
*****************************************************************************/


/*****************************************************************************  
*  Local Variables 
*****************************************************************************/


/*****************************************************************************  
*   Extern Functions 
*****************************************************************************/

/*****************************************************************************  
*   Local Functions  
*****************************************************************************/


#endif /* MMI_FSEDITORCUI_H */
