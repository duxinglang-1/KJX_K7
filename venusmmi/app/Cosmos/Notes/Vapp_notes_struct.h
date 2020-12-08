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
 *  Vapp_notes_struct.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Header file for base functions for the notes application.
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/


#ifndef __VAPP_NOTES_STRUCT_H__
#define __VAPP_NOTES_STRUCT_H__

#include "MMI_features.h"
//#include "Vfx_basic_type.h" required for the colors enum

#ifdef __MMI_NOTE_APP__

#define __MMI_NOTE_SORT_BY_MODIFY_TIME__

#include "Vfx_datatype.h" 
#include "MMIDataType.h" /*for the definition of encoding length*/
#include "Custom_mmi_default_value.h" /*for macros define din nvram dat file - length and no of notes supported*/

#define MMI_APP_NOTE_LIST_NODE_LEN                           100
#define MMI_APP_NOTE_MAX_ITEM                                     50
#define MMI_APP_NOTE_APPEND_STR_LEN                        2

typedef enum
{
	NOTES_CATAEGORY_COLOR_TOTAL,
        NOTES_CATAEGORY_COLOR_WHITE,
        NOTES_CATAEGORY_COLOR_BLUE,
	NOTES_CATAEGORY_COLOR_GREEN,
        NOTES_CATAEGORY_COLOR_YELLOW,
	NOTES_CATAEGORY_COLOR_ORANGE,
	NOTES_CATAEGORY_COLOR_RED
} mmi_note_category_color_enum;

typedef enum
{
	NOTES_CATEGORY_PAGE,
	NOTES_CATEGORY_LIST_PAGE,
	NOTES_CATEGORY_VIEW_PAGE
}venus_mmi_note_page_enum;

typedef enum
{
	MMI_NOTE_OP_NONE,
	MMI_NOTE_OP_EDIT,
	MMI_NOTE_OP_ADD,
	MMI_NOTE_OP_DELETE,
	MMI_NOTE_OP_GET,
	MMI_NOTE_OP_NUM
} venus_mmi_note_operation_enum;

typedef struct 
{
	VfxU32 modify_time;
	VfxU32 create_time;
	VfxU32 category_color; /*to store the back ground color for the note*/
	VfxU16 prior_node;
	VfxU16 next_node;			/* next node in note list and +1 is next NVRAM storage index */
	VfxU8 note_node[(MMI_APP_NOTE_LIST_NODE_LEN + 1) * ENCODING_LENGTH];	/* display content in note list */
} venus_mmi_note_node_struct;

/* structure for note application status */
typedef struct
{
    VfxU16 item_num;    /* number of note item in list */
	VfxU16 item_num_white;
	VfxU16 item_num_blue;
	VfxU16 item_num_green;
	VfxU16 item_num_yellow;
	VfxU16 item_num_orange;
	VfxU16 item_num_red;
	venus_mmi_note_node_struct note_list[MMI_MAX_NOTE_ITEM + 1];
} venus_mmi_note_list_struct;

typedef struct 
{
	VfxU32 time;
	VfxU16 curr_item;    /* current edit or delete item */
	VfxU16 curr_color;
	VfxU8 curr_edit[(MMI_MAX_NOTE_LEN + 1) * ENCODING_LENGTH];   
} venus_mmi_note_edit_struct;

typedef struct 
{
	/* current high light item of mark list */
	VfxU8	mark_flag[MMI_APP_NOTE_MAX_ITEM];
} venus_mmi_note_mark_list_struct;


#endif /*__MMI_NOTE_APP__*/
#endif /*__VAPP_NOTES_STRUCT_H__*/
