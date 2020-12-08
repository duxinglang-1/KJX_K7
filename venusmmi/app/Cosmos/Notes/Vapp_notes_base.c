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
 *  Vapp_notes_base.h
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
#include "MMI_features.h"
//#include "Vfx_basic_type.h" required for the colors enum

#ifdef __MMI_NOTE_APP__

#include "Vfx_datatype.h" 
#include "MMIDataType.h" /*for the definition of encoding length*/
#include "Custom_mmi_default_value.h" /*for macros defined in nvram data file - length and no of notes supported*/
#include "app_str.h"
#include "Vapp_notes_struct.h"
#include "Vapp_notes_base.h"
#include "common_nvram_editor_data_item.h"
#include "mmi_include.h"
#include "mmi_rp_vapp_notes_def.h"
#include "Wgui_categories_util.h"
venus_mmi_note_list_struct g_venus_mmi_note_cntx;			/* context of global note application */
venus_mmi_note_edit_struct g_venus_note_edit_cntx;
venus_mmi_note_mark_list_struct g_venus_note_mark_cntx;	/* context of note list mark screen */
extern U16 color_selected_from_category_screen = 0;
extern U8 color_for_add_new_item = NOTES_CATAEGORY_COLOR_WHITE;
VfxU16 g_sort_list[MMI_APP_NOTE_MAX_ITEM];
VfxU16 g_search_sort_list[MMI_APP_NOTE_MAX_ITEM];
U16 total_searched_notes_count = 0;
extern U8 category_list_node_selected = 0;
extern U8 search_list_node_index = 0;
extern VfxU16 g_list_in_search_mode = 0;
extern MMI_BOOL notes_list_change_done = MMI_FALSE;
extern void mmi_note_set_color_selected_from_category_screen(U16 color);
extern void mmi_notes_app_update_color_count(U8 color);
extern void mmi_notes_app_update_color_count_after_delete(U8 color);
extern void mmi_app_notes_update_note_count_by_color(U16 color);
extern void vapp_notes_set_searched_count(U16 k);
extern void mmi_notes_set_color_for_new_item(U8 color);
extern U16 vapp_notes_get_searched_count(void);
extern U8 mmi_notes_get_color_for_new_item(void);
extern U16 vapp_notes_get_current_editor_color_for_hilight(void);
extern U16 find_index_if_the_same_node_in_main_list(U16 index);
static U16 mmi_note_get(U16 index, nvram_ef_note_app_node_struct *node_cntx);
static U16 venus_mmi_note_update_content_hilite_cntx(U16 hilite, nvram_ef_note_app_node_struct *node_cntx, venus_mmi_note_operation_enum note_op);
static U16 mmi_note_add(U16 index, nvram_ef_note_app_node_struct *node_cntx);
static U16 mmi_note_check_pos_note_list(U32 curr_time, U16 nvram_index);
static U16 mmi_note_get_nvram_index(U16 hilite);
static U16 mmi_note_get_valid_storage_index(void);
static U16 mmi_note_get_hilite_index(U16 nvram_index);
static U16 mmi_note_update_content_note_record(venus_mmi_note_operation_enum note_opt, 
											  U16 update_node, 
											  nvram_ef_note_app_node_struct *node_cntx);
static U16 mmi_note_edit(U16 index, nvram_ef_note_app_node_struct *node_cntx);
static U16 mmi_note_delete(U16 index);




void vapp_notes_search_mode_reset(void)
{
	g_list_in_search_mode = 0;
}
/*****************************************************************************
* FUNCTION
*  venus_mmi_note_sort_list
* DESCRIPTION
*  This function is used to sort note list in initialize 
* PARAMETERS
*  void         
* RETURNS
*  U16
 *****************************************************************************/
void venus_mmi_note_sort_list(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxU16 i, count = 0, j, temp;
    VfxU16 *sort_list = NULL, *p;
	VfxU32 i_time, j_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_venus_mmi_note_cntx.item_num == 0)
	{
        g_venus_mmi_note_cntx.note_list[0].next_node = 0;
        g_venus_mmi_note_cntx.note_list[0].prior_node = 0;
        return;
    }
	
    /* sizeof(U16)* g_venus_mmi_note_cntx.item_numn  must be less than 2k */
    sort_list = (U16*)OslMalloc((U32)(sizeof(U16) * g_venus_mmi_note_cntx.item_num));
    MMI_ASSERT(sort_list);
    p = sort_list;
	
    /* set value of sort_list with init valid note index */
    for (i = 1; i <= MMI_APP_NOTE_MAX_ITEM; i++)
    {
        if (count == g_venus_mmi_note_cntx.item_num)
        {
            break;
        }
        if (g_venus_mmi_note_cntx.note_list[i].create_time)
		{
            *p = i;
            p++;
            count++;
        }
		}

	
    /* sort not list */
    for (i = 0; i < g_venus_mmi_note_cntx.item_num; i++)
    {
        for (j = i + 1 ; j < g_venus_mmi_note_cntx.item_num; j++)
        {
			
#ifdef __MMI_NOTE_SORT_BY_MODIFY_TIME__
			i_time = g_venus_mmi_note_cntx.note_list[sort_list[i]].modify_time;
			j_time = g_venus_mmi_note_cntx.note_list[sort_list[j]].modify_time;
#else
			i_time = g_venus_mmi_note_cntx.note_list[sort_list[i]].create_time;
			j_time = g_venus_mmi_note_cntx.note_list[sort_list[j]].create_time;
#endif /* __MMI_NOTE_SORT_BY_MODIFY_TIME__ */

			if ((i_time < j_time) ||
				(i_time == j_time && sort_list[i] > sort_list[j])) /* equal time, the one with greater nvarm index should be sorted into the behind position */
            {
                temp = sort_list[i];
                sort_list[i] = sort_list[j];
                sort_list[j] = temp;
            }
        }
    }
	
    /* set value for g_venus_mmi_note_cntx link */
    g_venus_mmi_note_cntx.note_list[0].next_node = sort_list[0];
    
    for (i = 0; i < g_venus_mmi_note_cntx.item_num; i++)
    {
        /* set next node of link */
        if (i == g_venus_mmi_note_cntx.item_num - 1)
        {
            /* for the last node */
            g_venus_mmi_note_cntx.note_list[sort_list[i]].next_node = 0;
            g_venus_mmi_note_cntx.note_list[0].prior_node = sort_list[i];
        }
        else
        {
            g_venus_mmi_note_cntx.note_list[sort_list[i]].next_node = sort_list[i + 1];
        }
		
        /* set previous node of link */
        if (i == 0)
        {
            /* for the first node */
            g_venus_mmi_note_cntx.note_list[sort_list[i]].prior_node = 0;
        }
        else
        {
            g_venus_mmi_note_cntx.note_list[sort_list[i]].prior_node = sort_list[i - 1];
        }
    }
    
	
    OslMfree(sort_list);
	
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_note_app_init
 * DESCRIPTION
 *  To iniitalise the nost list from the data read from Nvram
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  
 *****************************************************************************/
U8 vapp_note_app_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
     VfxU8 count = 0;
     VfxU16 i = 0;
     VfxS16 error;
     nvram_ef_note_app_node_struct *nvram_buf = NULL;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ReadValue(NVRAM_NOTES_APP_NOTE_COLOR, &color_for_add_new_item, DS_BYTE, &error);
	if((color_for_add_new_item <=0) || (color_for_add_new_item > NOTES_CATAEGORY_COLOR_RED))
	{
		color_for_add_new_item = NOTES_CATAEGORY_COLOR_WHITE;
	}
	//Todo - Add trace here
	//MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_APP_INIT);
	memset(&g_venus_mmi_note_cntx, 0x00, sizeof(venus_mmi_note_list_struct));

	nvram_buf = OslMalloc(sizeof(nvram_ef_note_app_node_struct));
		
	memset(nvram_buf, 0x00, sizeof(nvram_ef_note_app_node_struct));

	/* read record of all note items information */
	for (i = 1; i <= MMI_APP_NOTE_MAX_ITEM; i++)
	{
		/* read all items from NVRAM */
		ReadRecord(NVRAM_EF_NOTE_APP_LID, i, (void*)nvram_buf, sizeof(nvram_ef_note_app_node_struct), &error);  

		/* node time and record len to check empty record */
		if (nvram_buf->create_time)
		{
			/* save record of content and NVRAM index */
			/*update the string id for the string - ".."*/
			mmi_ucs2ncpy((S8*)g_venus_mmi_note_cntx.note_list[i].note_node, (S8*)nvram_buf->node_record, MMI_APP_NOTE_LIST_NODE_LEN);

			g_venus_mmi_note_cntx.note_list[i].modify_time = nvram_buf->modify_time;
			g_venus_mmi_note_cntx.note_list[i].create_time = nvram_buf->create_time;
			g_venus_mmi_note_cntx.note_list[i].category_color = nvram_buf->color;

			count++;
		}
	}

	g_venus_mmi_note_cntx.item_num = count;

    venus_mmi_note_sort_list();

	if (nvram_buf)
	{
		OslMfree(nvram_buf);
		nvram_buf = NULL;
	}
/*amit added for getting the count for showing on category page*/



	return count;

}
void save_current_edit_color(VfxId color)
{
	g_venus_note_edit_cntx.curr_color = color;
}


void save_and_add_notes_to_list(U16* string)
{
	S16 err;
	//U8 nvram_index = 0;
	U16 hilite = 0;
	nvram_ef_note_app_node_struct nvram_buf;
	memset(&nvram_buf, 0x00, sizeof(nvram_ef_note_app_node_struct));

	mmi_ucs2cpy((S8*)g_venus_note_edit_cntx.curr_edit, (S8*)string);		
    mmi_ucs2cpy((S8*)nvram_buf.node_record, (S8*)g_venus_note_edit_cntx.curr_edit);
	nvram_buf.color = g_venus_note_edit_cntx.curr_color;

	if(g_venus_note_edit_cntx.curr_item == (U16)(-1))
	{
		color_for_add_new_item = g_venus_note_edit_cntx.curr_color; /*to save the last color note added*/
		hilite = venus_mmi_note_update_content_hilite_cntx((U16)(-1), &nvram_buf, MMI_NOTE_OP_ADD);
		
	}
	else
	{
		color_for_add_new_item = g_venus_note_edit_cntx.curr_color; /*to save the last color note added*/
		hilite = venus_mmi_note_update_content_hilite_cntx(g_venus_note_edit_cntx.curr_item, &nvram_buf, MMI_NOTE_OP_EDIT);
	}
	WriteValue(NVRAM_NOTES_APP_NOTE_COLOR, &color_for_add_new_item, DS_BYTE, &err);
	g_venus_note_edit_cntx.curr_item = hilite;


}



static U16 venus_mmi_note_update_content_hilite_cntx(U16 hilite, nvram_ef_note_app_node_struct *node_cntx, venus_mmi_note_operation_enum note_op)
{
	U16 note_pos = 0;
	U16 nvram_index = 0;
	U8 update_color = 0;

	switch(note_op)
	{
		case MMI_NOTE_OP_ADD:
		{
			nvram_index = mmi_note_get_valid_storage_index();

			node_cntx->create_time = mmi_notes_app_get_time();
			node_cntx->modify_time = node_cntx->create_time;

			mmi_note_update_content_note_record(MMI_NOTE_OP_ADD, nvram_index, node_cntx);
			return mmi_note_get_hilite_index(note_pos);
		}
		

		case MMI_NOTE_OP_EDIT:
			{
					/* first valid note position */
				note_pos = mmi_note_get_nvram_index(hilite);
				/* set current modify time */
				node_cntx->create_time = g_venus_mmi_note_cntx.note_list[note_pos].create_time;
				node_cntx->modify_time = mmi_notes_app_get_time();
				mmi_note_update_content_note_record(MMI_NOTE_OP_EDIT, note_pos, node_cntx);

				/* return note hilite index */
				return mmi_note_get_hilite_index(note_pos);
			}

		case MMI_NOTE_OP_DELETE:
			{
				note_pos = mmi_note_get_nvram_index(hilite);
				update_color = g_venus_mmi_note_cntx.note_list[note_pos].category_color;
				mmi_note_update_content_note_record(MMI_NOTE_OP_DELETE, note_pos, node_cntx);				
				mmi_notes_app_update_color_count_after_delete(update_color);
			}
			break;

		default:
			break;
	}
	return (U16)(-1);
}


static U16 mmi_note_get_nvram_index(U16 hilite)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 i = 0;
	U16 next_note = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	next_note = g_venus_mmi_note_cntx.note_list[0].next_node;

	for (i = 0; i < hilite; i++)
	{
		MMI_ASSERT(next_note);
		next_note = g_venus_mmi_note_cntx.note_list[next_note].next_node;
	}
	
	return next_note;
}



static U16 mmi_note_get_hilite_index(U16 nvram_index)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 i = 0;
	U8 hilite = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, MMI_NOTEAPP_TRACE_007, nvram_index);
	for (hilite = 0; hilite < g_venus_mmi_note_cntx.item_num; hilite++)
	{
		/* time > cmp_time insert new note */
		if (g_venus_mmi_note_cntx.note_list[i].next_node == nvram_index)
		{
			return hilite;
		}
		else
		{
			i = g_venus_mmi_note_cntx.note_list[i].next_node;
		}
	}
	
	return (U16)(-1);
}


static U16 mmi_note_get_valid_storage_index(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_GET_NVRAM_INDEX);

	/* find a valid NVRAM index to save new note */
	for (i = 1; i <= MMI_APP_NOTE_MAX_ITEM; i++)
	{		
		if (g_venus_mmi_note_cntx.note_list[i].create_time == 0)
		{
			return i;
		}
	}

	return i;
}

/*****************************************************************************
* FUNCTION
*  mmi_note_update_content_note_record
* DESCRIPTION
*  This function is used to update a note record
* PARAMETERS
*  void         
* RETURNS
*  U16
 *****************************************************************************/
static U16 mmi_note_update_content_note_record(venus_mmi_note_operation_enum note_opt, 
											  U16 update_node, 
											  nvram_ef_note_app_node_struct *node_cntx)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 result = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(note_opt)
	{
	case MMI_NOTE_OP_EDIT:
		{
			MMI_ASSERT(node_cntx);

			/* delete and add note node */
			result = mmi_note_edit(update_node, node_cntx);

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
			if (result == 0)
			{
				//mmi_syncml_note_data_changed_notification(SYNCML_RECORD_MODIFY, (U16)(update_node - 1));
			}
#endif
		}
		break;

	case MMI_NOTE_OP_ADD:
		{
			MMI_ASSERT(node_cntx);
						
			result = mmi_note_add(update_node, node_cntx);

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
			if (result == 0)
			{
				//mmi_syncml_note_data_changed_notification(SYNCML_RECORD_ADD, (U16)(update_node - 1));
			}
#endif
		}
		break;

	case MMI_NOTE_OP_GET:
		{
			MMI_ASSERT(node_cntx);

			if (mmi_note_get_hilite_index(update_node) != (U16)(-1))
			{
				result = mmi_note_get(update_node, node_cntx);
			}
			else
			{
				result = 1;
				break;
			}
		}
	    break;

	case MMI_NOTE_OP_DELETE:
		{
			if (mmi_note_get_hilite_index(update_node) != (U16)(-1))
			{
				result = mmi_note_delete(update_node);
			}
			else
			{
				result = 1;;
				break;
			}

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
			if (result == 0)
			{
				//mmi_syncml_note_data_changed_notification(SYNCML_RECORD_DELETE, (U16)(update_node - 1));
			}
#endif
		}
	    break;

	default:
		{
			MMI_ASSERT(0);
		}
	    break;
	}

			
	return result;
}


static U16 mmi_note_add(U16 index, nvram_ef_note_app_node_struct *node_cntx)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 insert_pos = 0;
	S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* need find a new NVRAM index */
	if (index == (U16)(-1))
	{
		MMI_ASSERT(0);
	}

	if ((node_cntx->create_time == 0) || (node_cntx->modify_time == 0))
	{
		MMI_ASSERT(0);
	}
	
	/* find index position to insert note item */
#ifdef __MMI_NOTE_SORT_BY_MODIFY_TIME__
	insert_pos = mmi_note_check_pos_note_list(node_cntx->modify_time, index);
#else /* __MMI_NOTE_SORT_BY_MODIFY_TIME__ */
	insert_pos = mmi_note_check_pos_note_list(node_cntx->create_time, index);
#endif /* __MMI_NOTE_SORT_BY_MODIFY_TIME__ */

	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_UPDATE_CONTENT_ADD_INFO, index, insert_pos);
	
	WriteRecord(NVRAM_EF_NOTE_APP_LID, 
		index, 
		(void*)node_cntx, 
		sizeof(nvram_ef_note_app_node_struct), 
		&error);

	/* insert update node item to note list */
	{
		/* set update node information */
		g_venus_mmi_note_cntx.note_list[index].create_time = node_cntx->create_time;
		g_venus_mmi_note_cntx.note_list[index].modify_time = node_cntx->modify_time;
		g_venus_mmi_note_cntx.note_list[index].category_color = node_cntx->color;
		g_venus_mmi_note_cntx.note_list[index].prior_node = insert_pos;
		g_venus_mmi_note_cntx.note_list[index].next_node = g_venus_mmi_note_cntx.note_list[insert_pos].next_node;

		/*update the string id for the string - ".."*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
		mmi_ucs2ncpy((S8*)g_venus_mmi_note_cntx.note_list[index].note_node, 
					(S8*)node_cntx->node_record, MMI_APP_NOTE_LIST_NODE_LEN);
		
		/* set prior node information */
		g_venus_mmi_note_cntx.note_list[insert_pos].next_node = index;

		/* set next node information */
		g_venus_mmi_note_cntx.note_list[g_venus_mmi_note_cntx.note_list[index].next_node].prior_node = index;
	}
	mmi_notes_app_update_color_count(g_venus_mmi_note_cntx.note_list[index].category_color);
	return 0;
}

void mmi_notes_app_update_color_count(U8 color)
{
	switch(color)
	{
		case NOTES_CATAEGORY_COLOR_WHITE:
		g_venus_mmi_note_cntx.item_num_white++;
			break;
		case NOTES_CATAEGORY_COLOR_BLUE:
		g_venus_mmi_note_cntx.item_num_blue++;
			break;
		case NOTES_CATAEGORY_COLOR_GREEN:
		g_venus_mmi_note_cntx.item_num_green++;
			break;
		case NOTES_CATAEGORY_COLOR_YELLOW:
		g_venus_mmi_note_cntx.item_num_yellow++;
			break;
		case NOTES_CATAEGORY_COLOR_ORANGE:
		g_venus_mmi_note_cntx.item_num_orange++;
			break;
		case NOTES_CATAEGORY_COLOR_RED:
		g_venus_mmi_note_cntx.item_num_red++;
			break;
		default:
			break;
	}
	g_venus_mmi_note_cntx.item_num++;

}

void mmi_notes_app_update_color_count_after_delete(U8 color)
{
	switch(color)
	{
		case NOTES_CATAEGORY_COLOR_WHITE:
		g_venus_mmi_note_cntx.item_num_white--;
			break;
		case NOTES_CATAEGORY_COLOR_BLUE:
		g_venus_mmi_note_cntx.item_num_blue--;
			break;
		case NOTES_CATAEGORY_COLOR_GREEN:
		g_venus_mmi_note_cntx.item_num_green--;
			break;
		case NOTES_CATAEGORY_COLOR_YELLOW:
		g_venus_mmi_note_cntx.item_num_yellow--;
			break;
		case NOTES_CATAEGORY_COLOR_ORANGE:
		g_venus_mmi_note_cntx.item_num_orange--;
			break;
		case NOTES_CATAEGORY_COLOR_RED:
		g_venus_mmi_note_cntx.item_num_red--;
			break;
		default:
			break;
	}
	g_venus_mmi_note_cntx.item_num--;
}

void mmi_notes_app_update_color_count_after_edit(U8 previous_color, U8 new_color)
{
	mmi_notes_app_update_color_count_after_delete(previous_color);

	mmi_notes_app_update_color_count(new_color);
}



static U16 mmi_note_check_pos_note_list(U32 curr_time, U16 nvram_index)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 insert_pos = 0; /* init with first header node , insert after insert_pose */
    U16 j = 0;
	U8 count = 0;
	U32 cmp_time = 0;
	MYTIME calender_time;
	S8 arr[100] = {'\0',};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* get next node index from first note node */
	j = g_venus_mmi_note_cntx.note_list[0].next_node;

    /* insert_pos is the previous node, j is the current node to compare with */
	for (count = 0; count < g_venus_mmi_note_cntx.item_num; count++)
	{
#ifdef __MMI_NOTE_SORT_BY_MODIFY_TIME__
		cmp_time = g_venus_mmi_note_cntx.note_list[j].modify_time;
#else /* __MMI_NOTE_SORT_BY_MODIFY_TIME__ */
		cmp_time = g_venus_mmi_note_cntx.note_list[j].create_time;
#endif /* __MMI_NOTE_SORT_BY_MODIFY_TIME__ */
		applib_dt_sec_2_mytime(cmp_time, (applib_time_struct*)&calender_time);

		mmi_dt_utc_sec_2_mytime((U32) cmp_time, &calender_time, MMI_TRUE);
		date_string(&calender_time, (UI_string_type)arr, DT_IDLE_SCREEN);
		memset(arr,0,100);

		time_string(&calender_time, (UI_string_type)arr, DT_IDLE_SCREEN);

		/* time > cmp_time insert new note */

		if (curr_time > cmp_time)
		{
			/* return note node index and insert to index.next */
			return insert_pos;
		}
        else if (curr_time == cmp_time)
        {
		    /* if cmp_time's index is greater then input nvram index,
			   the target node should be previous to the j */
            if (j > nvram_index)
            {
			/* insert before this equal node, 
			the node with small nvram index and equal time value 
				should be sorted in prior position */
                return insert_pos; 
            }
			else
			{
				insert_pos = j;
				j = g_venus_mmi_note_cntx.note_list[j].next_node;
			}
		}
		else
		{
			insert_pos = j;
			j = g_venus_mmi_note_cntx.note_list[j].next_node;
		}
	}

	return insert_pos;
}



U32 mmi_notes_app_get_time(void)
{
	applib_time_struct t;

	 applib_dt_get_secure_time(&t);
    return (U32) applib_dt_sec_local_to_utc(applib_dt_mytime_2_utc_sec(&t, KAL_FALSE));
}

U16 mmi_notes_get_notes_count_from_category_selected_color_ext(U16 color)
{
	switch(color)
	{

		   case NOTES_CATAEGORY_COLOR_WHITE:
				   return g_venus_mmi_note_cntx.item_num_white;
		   case NOTES_CATAEGORY_COLOR_BLUE:
				   return g_venus_mmi_note_cntx.item_num_blue;
		   case NOTES_CATAEGORY_COLOR_GREEN:
				   return g_venus_mmi_note_cntx.item_num_green;
		   case NOTES_CATAEGORY_COLOR_YELLOW:
				   return g_venus_mmi_note_cntx.item_num_yellow;
		   case NOTES_CATAEGORY_COLOR_ORANGE:
				   return g_venus_mmi_note_cntx.item_num_orange;
		   case NOTES_CATAEGORY_COLOR_RED:
				   return g_venus_mmi_note_cntx.item_num_red;
		   case NOTES_CATAEGORY_COLOR_TOTAL:
				   return g_venus_mmi_note_cntx.item_num;
		   default:
				   return 0;
	}
   
}

U16 mmi_notes_get_notes_count_from_category_selected_color(void)
 {
	 U16 color=mmi_notes_get_notes_count_from_category_selected_color_ext(color_selected_from_category_screen);
	 return color;
 }

void mmi_note_list_highlight_set_hdlr(S32 index)
{
	/*check if the list is from particulr color selected*/
	U16 i;
	if(color_selected_from_category_screen)
	{
		if(g_list_in_search_mode == 2) /*item is from search list*/
		{
			search_list_node_index = index;
			g_venus_note_edit_cntx.curr_item = find_index_if_the_same_node_in_main_list(g_search_sort_list[index]);
			for(i=0; i<mmi_notes_get_notes_count_from_category_selected_color(); i++)
			{
				if(g_sort_list[i] == g_search_sort_list[index])
				{
					category_list_node_selected = i;
				}
			}

		}
		else
		{
			category_list_node_selected = index;
			/*traverse in selected color array to set the index in main list*/
			g_venus_note_edit_cntx.curr_item = find_index_if_the_same_node_in_main_list(g_sort_list[index]);
		}

	}
	else
	{
		if(g_list_in_search_mode == 2)
		{
			search_list_node_index = index;
			g_venus_note_edit_cntx.curr_item = find_index_if_the_same_node_in_main_list(g_search_sort_list[index]);
		}
		else
		{
			g_venus_note_edit_cntx.curr_item = index;
		}
	}
}



U16 find_index_if_the_same_node_in_main_list(U16 index)
{
	U16 node_index = 0;
	U16 k = 1,i = 0;

	node_index = g_venus_mmi_note_cntx.note_list[0].next_node;
	if(index == node_index)
	{
		return 0;
	}
	for(i=1; i <g_venus_mmi_note_cntx.item_num ; i++)
	{
		node_index = g_venus_mmi_note_cntx.note_list[node_index].next_node;
		if(index != node_index)
		{
			k++;
		}
		else
		{
			break;
		}
	}
	return k;
	

	/*this index is the index if the same node is present in all color list*/



}



U16 venus_mmi_note_load_text(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 hilite = g_venus_note_edit_cntx.curr_item;
	U16 node_pos = 0;
    nvram_ef_note_app_node_struct *nvram_buf = NULL;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_LOAD_FUNC, hilite);

	nvram_buf = OslMalloc(sizeof(nvram_ef_note_app_node_struct));

    memset(nvram_buf, 0x00, sizeof(nvram_ef_note_app_node_struct));
	
	node_pos = mmi_note_get_nvram_index(hilite);

	MMI_TRACE(MMI_COMMON_TRC_G2_ORG, TRC_MMI_NOTE_LOAD_POS, node_pos);

	mmi_note_update_content_note_record(MMI_NOTE_OP_GET, node_pos, nvram_buf);

	mmi_ucs2ncpy((S8*)g_venus_note_edit_cntx.curr_edit, (S8*)nvram_buf->node_record, MMI_MAX_NOTE_LEN);
	g_venus_note_edit_cntx.curr_color = nvram_buf->color;
#ifdef __MMI_NOTE_SORT_BY_MODIFY_TIME__
	g_venus_note_edit_cntx.time = nvram_buf->modify_time;
		#else /* __MMI_NOTE_SORT_BY_MODIFY_TIME__ */
	g_venus_note_edit_cntx.time = nvram_buf->create_time;
	#endif /* __MMI_NOTE_SORT_BY_MODIFY_TIME__ */
	
	if (nvram_buf)
	{
		OslMfree(nvram_buf);
		nvram_buf = NULL;
	}

    return node_pos;
	
}

static U16 mmi_note_get(U16 index, nvram_ef_note_app_node_struct *node_cntx)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(index);
	MMI_ASSERT(node_cntx);

	ReadRecord(NVRAM_EF_NOTE_APP_LID, 
		index, 
		(void*)node_cntx, 
		sizeof(nvram_ef_note_app_node_struct), 
		&error);
	
	return 0;
}

static U16 mmi_note_edit(U16 index, nvram_ef_note_app_node_struct *node_cntx)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 prior_note = 0;
	U16 next_note = 0;
	U16 insert_pos = 0;
	S16 error = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* remove this node from note list */
	{
		prior_note = g_venus_mmi_note_cntx.note_list[index].prior_node;
		next_note = g_venus_mmi_note_cntx.note_list[index].next_node;
		
		g_venus_mmi_note_cntx.note_list[prior_note].next_node = next_note;
		g_venus_mmi_note_cntx.note_list[next_note].prior_node = prior_note;
		
		g_venus_mmi_note_cntx.item_num--;
	}

	/* find index position to insert note item */
#ifdef __MMI_NOTE_SORT_BY_MODIFY_TIME__
	insert_pos = mmi_note_check_pos_note_list(node_cntx->modify_time, index);
#else /* __MMI_NOTE_SORT_BY_MODIFY_TIME__ */
	insert_pos = mmi_note_check_pos_note_list(node_cntx->create_time, index);
#endif /* __MMI_NOTE_SORT_BY_MODIFY_TIME__ */

	WriteRecord(NVRAM_EF_NOTE_APP_LID, 
		index, 
		(void*)node_cntx, 
		sizeof(nvram_ef_note_app_node_struct), 
		&error);

	/* insert update node item to note list */
	{
		/* set update node information */
		g_venus_mmi_note_cntx.note_list[index].create_time = node_cntx->create_time;
		g_venus_mmi_note_cntx.note_list[index].modify_time = node_cntx->modify_time;
		g_venus_mmi_note_cntx.note_list[index].prior_node = insert_pos;
		g_venus_mmi_note_cntx.note_list[index].category_color = node_cntx->color;
		g_venus_mmi_note_cntx.note_list[index].next_node = g_venus_mmi_note_cntx.note_list[insert_pos].next_node;

		/*update the string id for the string - ".."*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
		mmi_ucs2ncpy((S8*)g_venus_mmi_note_cntx.note_list[index].note_node, 
			(S8*)node_cntx->node_record, MMI_APP_NOTE_LIST_NODE_LEN);

		g_venus_mmi_note_cntx.item_num++;
		
		/* set prior node information */
		g_venus_mmi_note_cntx.note_list[insert_pos].next_node = index;
		
		/* set next node information */
		g_venus_mmi_note_cntx.note_list[g_venus_mmi_note_cntx.note_list[index].next_node].prior_node = index;
	}

	return 0;
}


void mmi_note_app_single_note_delete(void)
{
	venus_mmi_note_update_content_hilite_cntx(g_venus_note_edit_cntx.curr_item, NULL, MMI_NOTE_OP_DELETE);
	g_venus_note_edit_cntx.curr_item = 0;
}


static U16 mmi_note_delete(U16 index)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 prior_note = 0;
	U16 next_note = 0;
	nvram_ef_note_app_node_struct *note_node = NULL;
	S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(index);
	
	note_node = OslMalloc(sizeof(nvram_ef_note_app_node_struct));

	/* set update node NVRAM content to empty */
	memset(note_node, 0x00, sizeof(nvram_ef_note_app_node_struct));
	
	WriteRecord(NVRAM_EF_NOTE_APP_LID, 
		index, 
		(void*)note_node, 
		sizeof(nvram_ef_note_app_node_struct), 
		&error);
	
	

	if (note_node)
	{
		OslMfree(note_node);
		note_node = NULL;
	}

	/* set prior node and next node */
	{
		prior_note = g_venus_mmi_note_cntx.note_list[index].prior_node;
		next_note = g_venus_mmi_note_cntx.note_list[index].next_node;

		g_venus_mmi_note_cntx.note_list[prior_note].next_node = next_note;
		g_venus_mmi_note_cntx.note_list[next_note].prior_node = prior_note;
	}

	memset(&g_venus_mmi_note_cntx.note_list[index], 0x00, sizeof(venus_mmi_note_node_struct));
	

	return 0;
}


U16 mmi_note_sort_color_based_list(VfxId color)
{
	
	VfxU16 node_index,i;
	int k = 0;
	//sort_list = (U16*)OslMalloc((U32)(sizeof(U16) * g_venus_mmi_note_cntx.item_num));
    //MMI_ASSERT(sort_list);
	memset(g_sort_list, 0,sizeof(g_sort_list));

	node_index = g_venus_mmi_note_cntx.note_list[0].next_node;
	/*mode _index is the first index to read from main list*/


	for(i=0; i < g_venus_mmi_note_cntx.item_num; i++)
	{
		if(g_venus_mmi_note_cntx.note_list[node_index].category_color == color)
		{
			g_sort_list[k] = node_index;
			k++;
		}

		node_index = g_venus_mmi_note_cntx.note_list[node_index].next_node;
	}


	switch(color)
	{
		case NOTES_CATAEGORY_COLOR_WHITE:
		g_venus_mmi_note_cntx.item_num_white = k;
			break;
		case NOTES_CATAEGORY_COLOR_BLUE:
		g_venus_mmi_note_cntx.item_num_blue = k;
			break;
		case NOTES_CATAEGORY_COLOR_GREEN:
		g_venus_mmi_note_cntx.item_num_green = k;
			break;
		case NOTES_CATAEGORY_COLOR_YELLOW:
		g_venus_mmi_note_cntx.item_num_yellow = k;
			break;
		case NOTES_CATAEGORY_COLOR_ORANGE:
		g_venus_mmi_note_cntx.item_num_orange = k;
			break;
		case NOTES_CATAEGORY_COLOR_RED:
		g_venus_mmi_note_cntx.item_num_red = k;
			break;
		case NOTES_CATAEGORY_COLOR_TOTAL:
			g_venus_mmi_note_cntx.item_num_red = k;
			break;
		default:
			break;

	}
	mmi_note_set_color_selected_from_category_screen(color);

	return k;
	

}

void mmi_app_notes_update_note_count_by_color(U16 color)
{
	VfxU16 node_index,i;
	int k = 0;

	node_index = g_venus_mmi_note_cntx.note_list[0].next_node;
	/*mode _index is the first index to read from main list*/


	for(i=0; i < g_venus_mmi_note_cntx.item_num; i++)
	{
		if(g_venus_mmi_note_cntx.note_list[node_index].category_color == color)
		{
			k++;
		}

		node_index = g_venus_mmi_note_cntx.note_list[node_index].next_node;
	}


	switch(color)
	{
		case NOTES_CATAEGORY_COLOR_WHITE:
		g_venus_mmi_note_cntx.item_num_white = k;
			break;
		case NOTES_CATAEGORY_COLOR_BLUE:
		g_venus_mmi_note_cntx.item_num_blue = k;
			break;
		case NOTES_CATAEGORY_COLOR_GREEN:
		g_venus_mmi_note_cntx.item_num_green = k;
			break;
		case NOTES_CATAEGORY_COLOR_YELLOW:
		g_venus_mmi_note_cntx.item_num_yellow = k;
			break;
		case NOTES_CATAEGORY_COLOR_ORANGE:
		g_venus_mmi_note_cntx.item_num_orange = k;
			break;
		case NOTES_CATAEGORY_COLOR_RED:
		g_venus_mmi_note_cntx.item_num_red = k;
			break;
		case NOTES_CATAEGORY_COLOR_TOTAL:
			g_venus_mmi_note_cntx.item_num_red = k;
			break;
		default:
			break;

	}
	
	

}

 void mmi_note_set_color_selected_from_category_screen(U16 color)
 {
	 color_selected_from_category_screen = color;
 }

 U16 mmi_note_get_color_selected_from_category_screen(void)
 {
	 return color_selected_from_category_screen;
 }



 U16 mmi_notes_get_total_num_of_marked_notes(void)
 {
	 U16 k = 0;
	 U16 i = 0;
	 
	 U16 count = mmi_notes_get_notes_count_from_category_selected_color();

	for(i=0; i< mmi_notes_get_notes_count_from_category_selected_color(); i++)
	{
		if(g_venus_note_mark_cntx.mark_flag[i] == 1)
		{
			k++;
		}
	}
	return k;
 }

void mmi_notes_set_color_for_new_item(U8 color)
{
	color_for_add_new_item = color;
}

U8 mmi_notes_get_color_for_new_item(void)
{
	return color_for_add_new_item;
}


void mmi_get_rgb_color_for_notes(U8 color, U16* red ,U16* green, U16* blue)
{
	switch(color)
	{
			case NOTES_CATAEGORY_COLOR_WHITE:
					*red = *green = *blue = 255;
					break;
			case NOTES_CATAEGORY_COLOR_BLUE:
						*red = 121;
						*green = 209;
						*blue = 234;
						break;
			case NOTES_CATAEGORY_COLOR_GREEN:
					*red = 161;
						*green = 236; 
						*blue = 106;
						break;
			case NOTES_CATAEGORY_COLOR_YELLOW:
					*red = 241;
						*green = 231; 
						*blue = 124;
						break;
			case NOTES_CATAEGORY_COLOR_ORANGE:
					*red =247;
						*green = 164;
						*blue = 46;
						break;
			case NOTES_CATAEGORY_COLOR_RED:
					*red = 243;
						*green = 106;
						*blue = 176;
						break;
			default:
				break;

	}
}

void vapp_notes_get_rgb_color_for_underline_in_editor(U8 color, U16* red ,U16* green, U16* blue)
{
	switch(color)
	{
			case NOTES_CATAEGORY_COLOR_WHITE:
					*red = 186;
					*green = 186;
					*blue = 186;
					break;
			case NOTES_CATAEGORY_COLOR_BLUE:
						*red = 83;
						*green = 167;
						*blue = 191;
						break;
			case NOTES_CATAEGORY_COLOR_GREEN:
					*red = 123;
						*green = 195; 
						*blue = 74;
						break;
			case NOTES_CATAEGORY_COLOR_YELLOW:
					*red = 191;
						*green = 182; 
						*blue = 83;
						break;
			case NOTES_CATAEGORY_COLOR_ORANGE:
					*red =204;
						*green = 124;
						*blue = 32;
						break;
			case NOTES_CATAEGORY_COLOR_RED:
					*red = 193;
						*green = 78;
						*blue = 135;
						break;
			default:
				break;

	}
}

//U16 mmi_get_editor_image_id(U16 color)
//{
//	U16 image_id = 0;
//	switch(color)
//	{
//			case NOTES_CATAEGORY_COLOR_WHITE:
//					image_id = IMG_ID_VAPP_NOTES_CATEGROY_WHITE_BG;
					//
//					break;
//			case NOTES_CATAEGORY_COLOR_BLUE:
//						image_id = IMG_ID_VAPP_NOTES_CATEGROY_BLUE_BG; 
//						break;
//			case NOTES_CATAEGORY_COLOR_GREEN:
//					image_id = IMG_ID_VAPP_NOTES_CATEGROY_GREEN_BG;
//						break;
//			case NOTES_CATAEGORY_COLOR_YELLOW:
//					image_id = IMG_ID_VAPP_NOTES_CATEGROY_YELLOW_BG;
//						break;
			//
//			case NOTES_CATAEGORY_COLOR_ORANGE:
//					image_id= IMG_ID_VAPP_NOTES_CATEGROY_ORANGE_BG;
//						break;
//			case NOTES_CATAEGORY_COLOR_RED:
//					image_id = IMG_ID_VAPP_NOTES_CATEGROY_RED_BG;
//						break;
//			default:
//				image_id = 0;
//				break;

//	}
//	return image_id;
//}

U8 mmi_note_get_new_note_color(U8 opetation)
{
	switch(opetation)
	{
	case MMI_NOTE_OP_ADD:
		if(mmi_note_get_color_selected_from_category_screen())
		{
			return mmi_note_get_color_selected_from_category_screen();
		}
		else
		{
			return color_for_add_new_item;
		}

	case MMI_NOTE_OP_EDIT:
		return g_venus_note_edit_cntx.curr_color;

	default:
			return 0;

		
	}

}
void mmi_note_app_marked_list_delete(void)
{
	U16 i = 0, del_num = 0;
	U8 temp_array[50];
	
	U16 total_num = mmi_notes_get_notes_count_from_category_selected_color();
	/*if we are in category we need to get the index in main list*/
	
	
	if(mmi_note_get_color_selected_from_category_screen())
	{
		
		for(i=0 ;i<total_num;i++)
		{
				U16 index = g_sort_list[i];
				temp_array[i] = find_index_if_the_same_node_in_main_list(index); /*same as main original hilighter */
		}
		for(i=0 ;i<total_num;i++)
		{
			
			if(g_venus_note_mark_cntx.mark_flag[i] == 1)
			{
			    venus_mmi_note_update_content_hilite_cntx((U16)(temp_array[i] - del_num), NULL, MMI_NOTE_OP_DELETE);
    			del_num++;
			}
		}
	}
	else
	{

		for (i = 0; i < total_num; i++)
    		{
    			if (g_venus_note_mark_cntx.mark_flag[i] == 1)
    			{
    				venus_mmi_note_update_content_hilite_cntx((U16)(i - del_num), NULL, MMI_NOTE_OP_DELETE);
    				del_num++;
    			}
    		}
	}
	
}

U16 mmi_vapp_notes_search_text_in_notes_list(WCHAR* string)
{
	VfxU16 node_index,i;
	int k = 0;
	//S8 s[] = { 'T', 0, 'Y', 0, 0, 0};
	//S8* string = "ERT";
	kal_wchar cmp_array [101];
	kal_wchar* cmp_string;
	memset(cmp_array,0, 101);
	mmi_ucs2ncpy((S8*)cmp_array,(S8*)string, mmi_ucs2strlen((S8*)string));
	cmp_string = (kal_wchar*)mmi_ucs2lwr((S8*)cmp_array);
	memset(g_search_sort_list, 0,sizeof(g_search_sort_list));

	node_index = g_venus_mmi_note_cntx.note_list[0].next_node;
	/*mode _index is the first index to read from main list*/

	memset(g_search_sort_list,0,50);
	vapp_notes_set_searched_count(0);

	for(i=0; i < g_venus_mmi_note_cntx.item_num; i++)
	{
		kal_wchar* p = NULL;
		kal_wchar temp_array[101];
		kal_wchar* full_string;
		memset(temp_array,0,101);
		mmi_ucs2ncpy((S8*)temp_array,(S8*)g_venus_mmi_note_cntx.note_list[node_index].note_node,mmi_ucs2strlen((S8*)g_venus_mmi_note_cntx.note_list[node_index].note_node));
		full_string = (kal_wchar*)mmi_ucs2lwr((S8*)temp_array);
		 p = app_ucs2_strstr((kal_wchar*)full_string, cmp_string);
		if(p)
		{
			if(mmi_note_get_color_selected_from_category_screen())
			{
				if(mmi_note_get_color_selected_from_category_screen() == g_venus_mmi_note_cntx.note_list[node_index].category_color)
				{
					g_search_sort_list[k] = node_index;
					k++;
				}
			}
			else
			{
				g_search_sort_list[k] = node_index;
				k++;
			}
		}

		node_index = g_venus_mmi_note_cntx.note_list[node_index].next_node;
	}
	vapp_notes_set_searched_count(k);
	return k;
}


U16 vapp_notes_get_current_editor_color_for_hilight(void)
{
	return g_venus_note_edit_cntx.curr_color;
}


void vapp_notes_set_searched_count(U16 k)
{
	total_searched_notes_count = k;
}

U16 vapp_notes_get_searched_count(void)
{
	return total_searched_notes_count;
}
void vapp_notes_list_set_item_edited_deleted_or_added(MMI_BOOL set)
{
	notes_list_change_done = set;

}

MMI_BOOL vapp_notes_list_get_item_edited_deleted_or_added(void)
{
	return notes_list_change_done;

}

void mmi_notes_save_handling_on_editor_back_key(void)
{
	if(mmi_note_get_color_selected_from_category_screen()) /*pop the back color list*/
	{
		U16 color = mmi_note_get_color_selected_from_category_screen();
		mmi_note_sort_color_based_list(color);
	 
	}
}
#endif /*__MMI_NOTE_APP__*/


