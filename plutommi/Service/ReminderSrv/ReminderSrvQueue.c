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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  ReminderSrvQueue.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Reminder queue implement file, to support multiple handle, just please rewrite create,init,destory function
 *
 * Author:
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 /****************************************************************************
 * Include
 ****************************************************************************/
#include "MMI_include.h"
#include "App_datetime.h"
#include "nvram_common_defs.h"

#include "ReminderSrvTypeTable.h"
#include "ReminderSrvQueue.h"
#include "ReminderSrv.h"

/****************************************************************************
 * Define
 ****************************************************************************/
#define Q_LOCK()
#define Q_UNLOCK()

/****************************************************************************
 * Typedef
 ****************************************************************************/
typedef enum{
	RET_OK,
	RET_REPLACE,
	RET_STOP,
	RET_OOM, 
	RET_TOTAL
}Ret;

typedef Ret (*visit_funcptr)(void *data, void* usr_data);

struct srv_reminder_q_cntx{ 
	srv_reminder_q_node_type *list;
	srv_reminder_compare_funcptr cmp_callback;
	Ret last_ret;
	U32 total;
	void *usr_data;
};

/****************************************************************************
 * Global variables
 ****************************************************************************/


/****************************************************************************
 * Local variables
 ****************************************************************************/
static struct srv_reminder_q_cntx g_srv_remdr_q_cntx;
static srv_reminder_q_node_type g_srv_remdr_q_list[REMINDER_Q_TOTAL];

/****************************************************************************
 * Global function
 ****************************************************************************/


/****************************************************************************
 * Local Function
 ****************************************************************************/

/*****************************************************************************
* FUNCTION
*   srv_reminder_q_for_each_ext
* DESCRIPTION
*   scan all the node table with start and end index
* PARAMETERS
*	table	:[IN]	list table
*	start	:[IN]	start index
*	end		:[IN]	end index
*	visit		:[IN]	vist function pointer
*	usr_data	:[IN]	user data
* RETURNS
*   S32	-> stop position
*****************************************************************************/
static S32 srv_reminder_q_for_each_ext(
				const srv_reminder_q_node_type *table, 
				U32 start, 
				U32 end,
				visit_funcptr visit,
				void *usr_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/
	U32 i = start;
	Ret ret = RET_OK;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL((table != NULL) &&( visit != NULL) && (start < end), REMINDER_Q_TOTAL);
	
	while (i < end)
	{
		ret = visit((void *)&table[i], usr_data);
		if (ret != RET_OK)
		{
			break;
		}
		i++;
	}

	return i;

}


/*****************************************************************************
* FUNCTION
*   srv_reminder_q_for_each
* DESCRIPTION
*   scan all the node  of the table
* PARAMETERS
*   table		[IN]		list table
*   visit		[IN]		vist function pointer
*   usr_data	[IN]		user data
* RETURNS
*   S32	-> stop position
*****************************************************************************/
static S32 srv_reminder_q_for_each(const srv_reminder_q_node_type *table, visit_funcptr visit, void *usr_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/
	return srv_reminder_q_for_each_ext(table, 0, REMINDER_Q_TOTAL, visit, usr_data);
}

/*****************************************************************************
 * FUNCTION
 *  srv_reminder_q_count_callback
 * DESCRIPTION
 *  callback funtion for counting valid q node
 * PARAMETERS
 *	data			:[IN]	node in reminder queue
 *	usr_data		:[IN]	user data
 * RETURNS
 *  Ret
 *****************************************************************************/
static Ret srv_reminder_q_count_callback(void *data, void* usr_data)
{
	/*----------------------------------------------------------------*/
	/* Local Variables													   */
	/*----------------------------------------------------------------*/
	srv_reminder_q_node_type *q_node;
	srv_reminder_q_type *q;
	
	/*----------------------------------------------------------------*/
	/* Code Body														   */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(data != NULL && usr_data != NULL, RET_OK);
	
	q_node = (srv_reminder_q_node_type *)data;
	q = (srv_reminder_q_type *)usr_data;
	
	if ((q_node->type >= SRV_REMINDER_TYPE_TOTAL) ||
		!applib_dt_is_valid((applib_time_struct *)&q_node->time))
	{
		return RET_STOP;
	}

	q->total++;
	
	return RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_reminder_q_add_callback
 * DESCRIPTION
 *  callback funtion for adding a new node to reminder queue.
 * PARAMETERS
 *	data			:[IN]	q node
 *	usr_data		:[IN]	any type of user data
 * RETURNS
 *  Ret
 *****************************************************************************/
static Ret srv_reminder_q_add_callback(void *data, void* usr_data)
{
	/*----------------------------------------------------------------*/
	/* Local Variables													   */
	/*----------------------------------------------------------------*/
	srv_reminder_q_node_type *q_node, *new_node;
	srv_reminder_q_type *q;
	S32 ret;
	Ret last_ret;
	
	/*----------------------------------------------------------------*/
	/* Code Body														   */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(data != NULL && usr_data != NULL, RET_OK);
	
	q_node = (srv_reminder_q_node_type *)data;	
	q = (srv_reminder_q_type *)usr_data;
	
	new_node = (srv_reminder_q_node_type *)q->usr_data;
	
	RETURN_VAL_IF_FAIL(new_node != NULL, RET_OK);
	
	ret = applib_dt_compare_time((applib_time_struct *)&new_node->time, (applib_time_struct *)&q_node->time, NULL);
	
	if (ret == DT_TIME_GREATER)
	{
		last_ret = RET_OK;
	}
	else if (ret == DT_TIME_EQUAL)
	{
		/* low type has high priority */
		if (new_node->type < q_node->type)
		{
			last_ret = RET_STOP;
		}
		else if (new_node->type == q_node->type)
		{
			if (q->cmp_callback != NULL)
			{
				ret = q->cmp_callback(q_node->usr_data, new_node->usr_data);

				/* new one should be before the exist one*/
				if (ret > 0)
				{
					last_ret = RET_STOP;
				}
				else if (ret < 0) /* don't replace, so ask for the next node */
				{
					last_ret = RET_OK;
				}
				else /*  new node should replace the exist one */
				{
					last_ret = RET_REPLACE;
				}
			}
			else /* new node should after the exist one  */
			{

				last_ret = RET_OK;
			}
		}
		else /* ask for the next node */
		{
			last_ret = RET_OK;
		}
	}
	else
	{
		last_ret = RET_STOP;
	}

	q->last_ret = last_ret;
	
	return last_ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_reminder_q_search_callback
 * DESCRIPTION
 *  callback funtion for searching a node in  reminder queue.
 * PARAMETERS
 *	data			:[IN]	node in reminder queue
 *	usr_data		:[IN]	user data
 * RETURNS
 *  Ret
 *****************************************************************************/
static Ret srv_reminder_q_search_callback(void *data, void* usr_data)
{
	/*----------------------------------------------------------------*/
	/* Local Variables													   */
	/*----------------------------------------------------------------*/
	srv_reminder_q_node_type *q_node, *new_node;
	
	/*----------------------------------------------------------------*/
	/* Code Body														   */
	/*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(data != NULL && usr_data != NULL, RET_OK);
	
	q_node = (srv_reminder_q_node_type *)data;
	new_node = (srv_reminder_q_node_type *)usr_data;
	
	if (q_node->type == new_node->type &&
		q_node->usr_data == new_node->usr_data)
	{
		memcpy(&new_node->time , &q_node->time, sizeof(MYTIME));
		return RET_STOP;
	}
	
	return RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_reminder_q_shrink
 * DESCRIPTION
 *	shrink the queue list from the start index
 * PARAMETERS
 *	list		:[IN]	the list
 *	total		:[IN]	total node
 *	index	:[IN]	start index
 * RETURNS
 *  srv_reminder_ret_enum
 *****************************************************************************/
static void srv_reminder_q_shrink(srv_reminder_q_node_type *list, U32 total, U32 index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables													   */
	/*----------------------------------------------------------------*/
	U32 i = index;
	
	/*----------------------------------------------------------------*/
	/* Code Body														   */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(list != NULL && total < REMINDER_Q_TOTAL && index < REMINDER_Q_TOTAL);
	
	for (; i < total -1; i++)
	{
		memcpy(&list[i], &list[i + 1], sizeof(srv_reminder_q_node_type));
	}
	
	memset(&list[total - 1], 0xFF, sizeof(srv_reminder_q_node_type));
}


/*****************************************************************************
 * FUNCTION
 *  srv_reminder_q_enlarge
 * DESCRIPTION
 *	enlarge the queue list from the start index
 * PARAMETERS
 *	list		:[IN]	the list
 *	total		:[IN]	total node
 *	index	:[IN]	start index
 * RETURNS
 *  srv_reminder_ret_enum
 *****************************************************************************/
static void srv_reminder_q_enlarge(srv_reminder_q_node_type *list, U32 total, U32 index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables													   */
	/*----------------------------------------------------------------*/
	U32 i;
	
	/*----------------------------------------------------------------*/
	/* Code Body														   */
	/*----------------------------------------------------------------*/
	RETURN_IF_FAIL(list != NULL && (total < (REMINDER_Q_TOTAL - 1)) && index < REMINDER_Q_TOTAL);
	
	for (i = total; i > index; i--)
	{
		memcpy(&list[i], &list[i - 1], sizeof(srv_reminder_q_node_type));
	}
}


/*****************************************************************************
 * FUNCTION
 *	srv_reminder_q_read_all
 * DESCRIPTION
 *	read all node from data base
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
static void srv_reminder_q_read_all(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables													   */
	/*----------------------------------------------------------------*/
	S16 error;
	
	/*----------------------------------------------------------------*/
	/* Code Body														   */
	/*----------------------------------------------------------------*/
	SRV_RMDR_LOG0(SRV_RMDR_Q_READ_ALL);

	ReadRecord(NVRAM_EF_SRV_REMINDER_Q_LID, 
			   1,
			   g_srv_remdr_q_list, 
			   NVRAM_EF_SRV_REMINDER_Q_SIZE,
			   &error);
}


/*****************************************************************************
 * FUNCTION
 *	srv_reminder_q_write_all
 * DESCRIPTION
 *	write all node to data base
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
static void srv_reminder_q_write_all(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables													   */
	/*----------------------------------------------------------------*/
	S16 error;
	
	/*----------------------------------------------------------------*/
	/* Code Body														   */
	/*----------------------------------------------------------------*/
	SRV_RMDR_LOG0(SRV_RMDR_Q_WRITE_ALL);
	
	WriteRecord(NVRAM_EF_SRV_REMINDER_Q_LID, 
			   1,
			   g_srv_remdr_q_list, 
			   NVRAM_EF_SRV_REMINDER_Q_SIZE,
			   &error);
}

#define GLOBAL_API
/*****************************************************************************
 * FUNCTION
 *	srv_reminder_q_create
 * DESCRIPTION
 *	create reminder queue
 * PARAMETERS
 *	void
 * RETURNS
 *  srv_reminder_q_type
 *****************************************************************************/
srv_reminder_q_type	*srv_reminder_q_create(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables													   */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body														   */
	/*----------------------------------------------------------------*/
	SRV_RMDR_LOG0(SRV_RMDR_Q_CREATE);

	return &g_srv_remdr_q_cntx;
}


/*****************************************************************************
 * FUNCTION
 *	srv_reminder_q_destroy
 * DESCRIPTION
 *	destroy reminder queue
 * PARAMETERS
 *	thiz		:[IN]	q handler
 * RETURNS
 *	void
 *****************************************************************************/
void srv_reminder_q_destroy(srv_reminder_q_type *thiz)
{
	/*----------------------------------------------------------------*/
	/* Local Variables													   */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body														   */
	/*----------------------------------------------------------------*/
	SRV_RMDR_LOG0(SRV_RMDR_Q_DESTROY);
	
	RETURN_IF_FAIL(thiz != NULL);
	
	thiz->total = 0;
	thiz->list = NULL;
	thiz->cmp_callback = NULL;
	thiz->last_ret = RET_TOTAL;

}


/*****************************************************************************
 * FUNCTION
 *	srv_reminder_q_init
 * DESCRIPTION
 *	init reminder queue
 * PARAMETERS
 *	thiz		:[IN]	q handler
 * RETURNS
 *	void
 *****************************************************************************/
void srv_reminder_q_init(srv_reminder_q_type *thiz)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/
	RETURN_IF_FAIL(thiz != NULL);

	srv_reminder_q_read_all();

	thiz->list = g_srv_remdr_q_list;
	thiz->cmp_callback = NULL;
	thiz->last_ret = RET_TOTAL;
	thiz->total = 0;
	
	srv_reminder_q_for_each(thiz->list, srv_reminder_q_count_callback, thiz);

	SRV_RMDR_LOG1(SRV_RMDR_Q_INIT, thiz->total);
	
}


/*****************************************************************************
 * FUNCTION
 *  srv_reminder_q_cnt
 * DESCRIPTION
 *	return total number of node in the queue
 * PARAMETERS
 *	thiz		:[IN]	q handler
 * RETURNS
 *  U32
 *****************************************************************************/
U32 srv_reminder_q_cnt(srv_reminder_q_type *thiz)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(thiz != NULL, 0);
	
	SRV_RMDR_LOG1(SRV_RMDR_Q_CNT, thiz->total);
	
	return thiz->total;
}


/*****************************************************************************
 * FUNCTION
 *  srv_reminder_q_is_empty
 * DESCRIPTION
 *  To judge whether the q is empty
 * PARAMETERS
 *	thiz		:[IN]	node in reminder queue
 * RETURNS
 *	MMI_TRUE -> empty
 *	MMI_FALSE	->	not empty
 *****************************************************************************/
MMI_BOOL srv_reminder_q_is_empty(srv_reminder_q_type *thiz)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/		
	RETURN_VAL_IF_FAIL(thiz != NULL, MMI_TRUE);

	SRV_RMDR_LOG1(SRV_RMDR_Q_IS_EMPTY, thiz->total);
	
	return (MMI_BOOL)(thiz->total == 0);
}


/*****************************************************************************
 * FUNCTION
 *  srv_reminder_q_add
 * DESCRIPTION
 *  Add a new node to reminder queue
 * PARAMETERS
 *	thiz		:[IN]	q handler
 *	node	:[IN]	q node
 * RETURNS
 *  srv_reminder_ret_enum
 *****************************************************************************/
srv_reminder_ret_enum srv_reminder_q_add(srv_reminder_q_type *thiz, const srv_reminder_q_node_type *node)
{
	/*----------------------------------------------------------------*/
	/* Local Variables													   */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body														   */
	/*----------------------------------------------------------------*/
	SRV_RMDR_LOG0(SRV_RMDR_Q_ADD);
	
	return srv_reminder_q_add_with_callback(thiz, node, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_reminder_q_add_with_callback
 * DESCRIPTION
 *  Add a new node to reminder queue
 * PARAMETERS
 *	thiz		:[IN]	q handler
 *	node	:[IN]	q node
 *	cmp		:[IN]	callback function
 * RETURNS
 *  srv_reminder_ret_enum
 *****************************************************************************/
srv_reminder_ret_enum srv_reminder_q_add_with_callback(
							srv_reminder_q_type *thiz, 
							const srv_reminder_q_node_type *node, 
							srv_reminder_compare_funcptr cmp)
{
	/*----------------------------------------------------------------*/
	/* Local Variables													   */
	/*----------------------------------------------------------------*/
	srv_reminder_ret_enum ret = SRV_REMINDER_RET_OK;
	U32 index = 0;
	
	/*----------------------------------------------------------------*/
	/* Code Body														   */
	/*----------------------------------------------------------------*/
	SRV_RMDR_LOG1(SRV_RMDR_Q_ADD_WITH_CALLBACK, cmp);
	
	RETURN_VAL_IF_FAIL(thiz != NULL && node != NULL, SRV_REMINDER_RET_INVALID_DATA);	

	if (srv_reminder_q_is_empty(thiz))
	{
		srv_reminder_q_insert(thiz, 0, node);
	}
	else
	{
		thiz->cmp_callback = cmp;
		thiz->usr_data = (void*)node;
		
		index =	srv_reminder_q_for_each_ext(
					thiz->list,
					0,
					thiz->total,
					srv_reminder_q_add_callback,
					thiz);
		
		thiz->cmp_callback = NULL;
		//overwrite
		if (index < REMINDER_Q_TOTAL)
		{
			if (thiz->last_ret == RET_REPLACE)
			{
				srv_reminder_q_update(thiz, index, node);
			}
			else
			{
				srv_reminder_q_insert(thiz, index, node);
			}
		}
		else
		{
			ret = SRV_REMINDER_RET_FAIL;
		}
	}	

	SRV_RMDR_LOG3(SRV_RMDR_Q_ADD_WITH_CALLBACK_RET, index, thiz->last_ret, ret);
	
	return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_reminder_q_update
 * DESCRIPTION
 *  Add a new node to reminder queue
 * PARAMETERS
 *	thiz		:[IN]	q handle
 *	index	:[IN]	node in reminder queue
 *	node	:[IN]	data
 * RETURNS
 *  srv_reminder_ret_enum
 *****************************************************************************/
srv_reminder_ret_enum srv_reminder_q_update(
							srv_reminder_q_type *thiz,
							U32 index, 
							const srv_reminder_q_node_type *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/
	SRV_RMDR_LOG1(SRV_RMDR_Q_UPDATE, index);
	
	RETURN_VAL_IF_FAIL(thiz != NULL && node != NULL && index < REMINDER_Q_TOTAL, 
					   SRV_REMINDER_RET_INVALID_DATA);

	memcpy(&thiz->list[index], node, sizeof(srv_reminder_q_node_type));

	srv_reminder_q_write_all();

	return SRV_REMINDER_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_reminder_q_insert
 * DESCRIPTION
 *  Add a new node to reminder queue
 * PARAMETERS
 *	thiz		:[IN]	q handle
 *	index	:[IN]	node in reminder queue
 *	node	:[IN]	data
 * RETURNS
 *  srv_reminder_ret_enum
 *****************************************************************************/
srv_reminder_ret_enum srv_reminder_q_insert(
							srv_reminder_q_type *thiz,
							U32 index, 
							const srv_reminder_q_node_type *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/
	SRV_RMDR_LOG1(SRV_RMDR_Q_INSERT, index);
	
	RETURN_VAL_IF_FAIL(thiz != NULL && node != NULL && index < REMINDER_Q_TOTAL, SRV_REMINDER_RET_INVALID_DATA);

	srv_reminder_q_enlarge(thiz->list, thiz->total, index);
	srv_reminder_q_update(thiz, index, node);
	thiz->total++;
	
	return SRV_REMINDER_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *	srv_reminder_q_empty
 * DESCRIPTION
 *	Empty the queue
 * PARAMETERS
 *	thiz		:[IN]	q handle
 * RETURNS
 *	void
 *****************************************************************************/
void srv_reminder_q_empty(srv_reminder_q_type *thiz)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/
	SRV_RMDR_LOG0(SRV_RMDR_Q_EMPTY);
	
	RETURN_IF_FAIL(thiz != NULL);

	memset(thiz->list, 0xFF, sizeof(srv_reminder_q_node_type) * REMINDER_Q_TOTAL);
	thiz->total = 0;

	srv_reminder_q_write_all();
}


/*****************************************************************************
 * FUNCTION
 *  srv_reminder_q_delete
 * DESCRIPTION
 *  Add a new node to reminder queue
 * PARAMETERS
 *	thiz		:[IN]	q handle
 *	node	:[IN]	q node which will be deleted
 * RETURNS
 *  srv_reminder_ret_enum
 *****************************************************************************/
srv_reminder_ret_enum srv_reminder_q_delete(srv_reminder_q_type *thiz, const srv_reminder_q_node_type *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/
	srv_reminder_ret_enum ret = SRV_REMINDER_RET_OK;
	U32 index = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/	
	RETURN_VAL_IF_FAIL(thiz != NULL && node != NULL, SRV_REMINDER_RET_FAIL);
	SRV_RMDR_LOG2(SRV_RMDR_Q_DELETE, node->type, node->usr_data);
	
	if (!srv_reminder_q_is_empty(thiz) && 
		((index = srv_reminder_q_search(thiz, node)) < thiz->total))		
	{
		srv_reminder_q_shrink(thiz->list, thiz->total, index);

		srv_reminder_q_write_all();
		thiz->total--;
	}
	else
	{
		ret = SRV_REMINDER_RET_FAIL;
	}

    SRV_RMDR_LOG2(SRV_RMDR_Q_DELETE_RET, index, ret);
	return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_reminder_q_delete_by_index
 * DESCRIPTION
 *  Add a new node to reminder queue
 * PARAMETERS
 *	thiz		:[IN]	q handle
 *	index	:[IN]	q node index which will be deleted
 * RETURNS
 *  srv_reminder_ret_enum
 *****************************************************************************/
srv_reminder_ret_enum srv_reminder_q_delete_by_index(srv_reminder_q_type *thiz, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/
	srv_reminder_ret_enum ret = SRV_REMINDER_RET_OK;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/	
	RETURN_VAL_IF_FAIL(thiz != NULL, SRV_REMINDER_RET_FAIL);

	if (!srv_reminder_q_is_empty(thiz) && (index < thiz->total))
	{
		srv_reminder_q_shrink(thiz->list, thiz->total, index);

		srv_reminder_q_write_all();
		thiz->total--;
	}
	else
	{
		ret = SRV_REMINDER_RET_FAIL;
	}

	SRV_RMDR_LOG2(SRV_RMDR_Q_DELETE_RET_BY_INDEX,index, ret);

	return ret;

}

/*****************************************************************************
 * FUNCTION
 *  srv_reminder_q_get
 * DESCRIPTION
 *  Add a new node to reminder queue
 * PARAMETERS
 *	thiz		:[IN]	q handle
 *	index	:[IN]	list index
 * RETURNS
 *  srv_reminder_q_node_type
 *****************************************************************************/
srv_reminder_q_node_type *srv_reminder_q_get(srv_reminder_q_type *thiz, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/
	SRV_RMDR_LOG1(SRV_RMDR_Q_GET, index);
	
	RETURN_VAL_IF_FAIL(thiz != NULL && index < thiz->total, NULL);

	return &(thiz->list[index]);
}


/*****************************************************************************
 * FUNCTION
 *  srv_reminder_q_search
 * DESCRIPTION
 *  Search the node
 * PARAMETERS
 *	thiz		:[IN]	q handle
 *	node	:[IN]	node
 * RETURNS
 *  U32
 *****************************************************************************/
U32 srv_reminder_q_search(srv_reminder_q_type *thiz, const srv_reminder_q_node_type *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/
	U32 index;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(thiz != NULL && node != NULL, REMINDER_Q_TOTAL);
	
	SRV_RMDR_LOG2(SRV_RMDR_Q_SEARCH, node->type, node->usr_data);

	index =	srv_reminder_q_for_each_ext(
				thiz->list, 
				0,
				thiz->total,
				srv_reminder_q_search_callback, 
				(void *)node);

	index = (index >= thiz->total) ? REMINDER_Q_TOTAL : index;
	
	SRV_RMDR_LOG1(SRV_RMDR_Q_SEARCH_RET, index);
	
	return index;
}

