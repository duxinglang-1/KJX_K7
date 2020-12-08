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
 *  IdleNotificationManager.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the functionality of the idle screen notification 
 *  manager (NMGR).
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
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMI_features.h"
#include "IdleGprot.h"
#include "IdleNotificationManager.h"
#include "IdleHomescreenGprot.h"
#include "IdleHomescreen.h"
#include "ScrSaverGprot.h"
#include "IdleNotificationManagerGprot.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "lcd_cqueue.h"
#include "MMI_common_app_trc.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "string.h"
#include "GlobalResDef.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_cb_mgr_gprot.h"
#include "AlertScreen.h"
#include "CommonScreensResDef.h"
#include "mmi_rp_app_idle_nmgr_def.h"
#include "wgui_categories_util.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "wgui_categories.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "gui_effect_oem.h"
#include "gdi_include.h"
#include "Unicodexdcl.h"
#include "wgui_categories_list.h"
#include "CustDataRes.h"
#include "mmi_rp_app_idle_homescreen_def.h"
#include "wgui_categories_popup_op.h"


#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
/*****************************************************************************
 * Global Variables
 *****************************************************************************/

static mmi_nmgr_context_struct g_nmgr_cntx;


/****************************************************************************
 * Define
 ****************************************************************************/

/* Macro: (1) set flag (2) clear flag and (3) check if flag is set. */
#define MMI_NMGR_SET(_flag, _f)         (_flag |= _f)
#define MMI_NMGR_CLR(_flag, _f)         (_flag &= ~_f)
#define MMI_NMGR_HAS(_flag, _f)         (((_flag & _f) == _f))


/****************************************************************************
 * Prototype
 ****************************************************************************/

static MMI_BOOL mmi_nmgr_notify_common(mmi_nmgr_req_struct *req);

#ifdef __MMI_EVENT_LIST__
static U32 mmi_nmgr_event_list_get_event(U32 type);
static MMI_BOOL mmi_nmgr_entry_event_list(void);
#endif /* __MMI_EVENT_LIST__ */

#if defined(__MMI_OP11_HOMESCREEN__)
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_OP11_HOMESCREEN__) */


/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_reset_request
 * DESCRIPTION
 *  This function resets the request.
 * PARAMETERS
 *  req             : [IN]          Request
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nmgr_reset_request(mmi_nmgr_req_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(req);

    kal_mem_set(req, 0, sizeof(mmi_nmgr_req_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_queue_delete_duplicated
 * DESCRIPTION
 *  This function deletes the duplicated requests in the queue.
 * PARAMETERS
 *  req             : [IN]              Request
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE;
 *****************************************************************************/
static MMI_BOOL mmi_nmgr_queue_delete_duplicated(mmi_nmgr_req_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nmgr_queue_elem_struct *elem, *prev_elem, *next_elem;
    S32 num, i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(req);

    num = lcd_cqueue_num_of_items(g_nmgr_cntx.queue);

    for (i = 0; i < num; i++)
    {
        elem = (mmi_nmgr_queue_elem_struct *)
                    lcd_cqueue_index(g_nmgr_cntx.queue, i);

        if (req->trigger == elem->req.trigger &&
            req->type == elem->req.type &&
            req->flag == elem->req.flag &&
            req->func == elem->req.func)
        {
            /* Shift the remained requests. */
            for (j = i; j < num - 1; j++)
            {
                prev_elem = (mmi_nmgr_queue_elem_struct *)
                                lcd_cqueue_index(g_nmgr_cntx.queue, j);

                next_elem = (mmi_nmgr_queue_elem_struct *)
                                lcd_cqueue_index(g_nmgr_cntx.queue, j + 1);

                *prev_elem = *next_elem;
            }

            /* Remove the last requests. */
            elem = lcd_cqueue_remove_rear(g_nmgr_cntx.queue);
            elem->is_used = MMI_FALSE;

            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_queue_get_unused_elem
 * DESCRIPTION
 *  This function gets a unused element.
 * PARAMETERS
 *  void
 * RETURNS
 *  A unused element.
 *****************************************************************************/
static mmi_nmgr_queue_elem_struct *mmi_nmgr_queue_get_unused_elem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_NMGR_MAX_NOTIFY_NUM; i++)
    {
        if (!g_nmgr_cntx.queue_elem[i].is_used)
        {
            return &(g_nmgr_cntx.queue_elem[i]);
        }
    }

    MMI_ASSERT(0);  /* Elements are not enough. */

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_queue_insert_int
 * DESCRIPTION
 *  This function inserts a notification request into the pending queue.
 * PARAMETERS
 *  req             : [IN]          Request
 *  is_front        : [IN]          Insert to the front of the queue?
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nmgr_queue_insert_int(
    mmi_nmgr_req_struct *req,
    MMI_BOOL is_front)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nmgr_queue_elem_struct *elem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(req);

    if (lcd_cqueue_is_full(g_nmgr_cntx.queue))
    {
        return;
    }

    mmi_nmgr_queue_delete_duplicated(req);

    elem = mmi_nmgr_queue_get_unused_elem();

    if (elem)
    {
        elem->is_used = MMI_TRUE;
        elem->req = *req; /* copy */

        if (is_front)
        {
            lcd_cqueue_insert_front(g_nmgr_cntx.queue, elem);
        }
        else
        {
            lcd_cqueue_insert(g_nmgr_cntx.queue, elem);
        }

        MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_MMI_NMGR_QUEUE, 
            'I', req->type, req->flag, lcd_cqueue_num_of_items(g_nmgr_cntx.queue));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_queue_insert_front
 * DESCRIPTION
 *  This function inserts a notification request into the front of the queue.
 * PARAMETERS
 *  req             : [IN]          Request
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nmgr_queue_insert_front(mmi_nmgr_req_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_nmgr_queue_insert_int(req, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_queue_remove
 * DESCRIPTION
 *  This function removes a notification request from the queue.
 * PARAMETERS
 *  req             : [OUT]          The removed request
 * RETURNS
 *  On success, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL mmi_nmgr_queue_remove(mmi_nmgr_req_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nmgr_queue_elem_struct *elem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (lcd_cqueue_is_empty(g_nmgr_cntx.queue))
    {
        return MMI_FALSE;
    }

    elem = (mmi_nmgr_queue_elem_struct *)lcd_cqueue_remove(g_nmgr_cntx.queue);
    MMI_ASSERT(elem);

    MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_MMI_NMGR_QUEUE, 'D', 
        elem->req.type, elem->req.flag, lcd_cqueue_num_of_items(g_nmgr_cntx.queue));

    if (req)
    {
        *req = elem->req; /* copy */
    }

    elem->is_used = MMI_FALSE;

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_queue_peek
 * DESCRIPTION
 *  This function peeks the 'index'-th notification in the queue.
 * PARAMETERS
 *  index               : [IN]          Index
 * RETURNS
 *  Notification.
 *****************************************************************************/
static const mmi_nmgr_req_struct *mmi_nmgr_queue_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nmgr_queue_elem_struct *elem;
    S32 num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    num = lcd_cqueue_num_of_items(g_nmgr_cntx.queue);

    if (index < 0 || index >= num)
    {
        return NULL;
    }

    elem = (mmi_nmgr_queue_elem_struct *)
                lcd_cqueue_index(g_nmgr_cntx.queue, index);

    MMI_ASSERT(elem);

    return &(elem->req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_get_app_cntx
 * DESCRIPTION
 *  This function get the context of this APP.
 * PARAMETERS
 *  type                [IN]                The ID of the application
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_nmgr_answer_struct *mmi_nmgr_get_app_cntx(U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_nmgr_ctrl_tbl_struct *tbl = mmi_nmgr_get_ctrl_tbl();
    mmi_nmgr_answer_struct *info = NULL;
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_NMGR_APP_NUM; i++)
    {
        if (tbl[i].type == type)
        {
            info = &g_nmgr_cntx.info[i];
            break;
        }
    }

    MMI_ASSERT(info);

    return info;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_get_intgr_app_id
 * DESCRIPTION
 *  This function get the context of this APP.
 * PARAMETERS
 *  type                [IN]                The ID of the application
 * RETURNS
 *  void
 *****************************************************************************/
static U32 mmi_nmgr_get_intgr_app_id(U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_nmgr_intgr_ctrl_tbl_struct *tbl = mmi_nmgr_get_intgr_ctrl_tbl();
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_NMGR_INTGR_APP_NUM; i++)
    {
        if (MMI_NMGR_HAS(tbl[i].type, type))
        {
            return tbl[i].type;
        }
    }

    return type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_is_intgr_app_id
 * DESCRIPTION
 *  This function checks whether the APP is an integrated APP.
 * PARAMETERS
 *  type                [IN]                The ID of the application
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL mmi_nmgr_is_intgr_app_id(U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_nmgr_intgr_ctrl_tbl_struct *tbl = mmi_nmgr_get_intgr_ctrl_tbl();
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_NMGR_INTGR_APP_NUM; i++)
    {
        if (type == tbl[i].type)
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_get_intgr_app_slot
 * DESCRIPTION
 *  This function get the control slot of of the integration APP.
 * PARAMETERS
 *  type                [IN]                The ID of the application
 * RETURNS
 *  void
 *****************************************************************************/
static const 
mmi_nmgr_intgr_ctrl_tbl_struct *mmi_nmgr_get_intgr_app_slot(U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_nmgr_intgr_ctrl_tbl_struct *tbl = mmi_nmgr_get_intgr_ctrl_tbl();
    const mmi_nmgr_intgr_ctrl_tbl_struct *intgr_app = NULL;
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_NMGR_INTGR_APP_NUM; i++)
    {
        if (type == tbl[i].type)
        {
            intgr_app = &tbl[i];
            break;
        }
    }

    MMI_ASSERT(intgr_app);
    
    return intgr_app;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_get_intgr_app_cntx
 * DESCRIPTION
 *  This function get the context of the integration APP.
 * PARAMETERS
 *  type                [IN]                The ID of the application
 *  answer              [OUT]               APP context
 * RETURNS
 *  On success, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL mmi_nmgr_get_intgr_app_cntx(
    U32 type,
    mmi_nmgr_answer_struct *answer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_nmgr_intgr_ctrl_tbl_struct *intgr_app;
    mmi_nmgr_answer_struct *app_info;
    MMI_BOOL valid = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(answer);

    if (mmi_nmgr_is_intgr_app_id(type))
    {
        intgr_app = mmi_nmgr_get_intgr_app_slot(type);
        if (intgr_app && intgr_app->query_func )
        {
            intgr_app->query_func(answer);
            valid = MMI_TRUE;
        }
    }
    else
    {
        app_info = mmi_nmgr_get_app_cntx(type);
        if (app_info)
        {
            memcpy(answer, app_info, sizeof(mmi_nmgr_answer_struct));
            valid = MMI_TRUE;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_MMI_NMGR_GET_INTGR_APP_CNTX, type, valid, answer->total_num, answer->hdlr);

    return valid;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_query_new_event_of_app
 * DESCRIPTION
 *  To query whether an application has new event or not. The type can be an
 *  intergrated application or a normal application.
 * PARAMETERS
 *  type                [IN]                The ID of the application
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_nmgr_app_has_new_event(U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_nmgr_ctrl_tbl_struct *tbl = mmi_nmgr_get_ctrl_tbl();
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_NMGR_APP_NUM; i++)
    {
        if (MMI_NMGR_HAS(type, tbl[i].type) &&
            tbl[i].query_new_event && 
            tbl[i].query_new_event())
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_cancel
 * DESCRIPTION
 *  This function cancels the notification of the specified application.
 * PARAMETERS
 *  type                [IN]                The ID of the application
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nmgr_cancel(U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_nmgr_ctrl_tbl_struct *tbl = mmi_nmgr_get_ctrl_tbl();
	S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_MMI_NMGR_CANCEL, type);

    for (i = 0; i < MMI_NMGR_APP_NUM; i++)
    {
        if (MMI_NMGR_HAS(type, tbl[i].type) && tbl[i].cancel_func)
        {
            tbl[i].cancel_func();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_close_confirm_yes_hdlr
 * DESCRIPTION
 *  This function is the "Yes" handler for the close confirm popup.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nmgr_close_confirm_yes_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_nmgr_cancel(g_nmgr_cntx.prev_req.type);

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_NMGR_IDLE_CANCEL);
    MMI_FRM_CB_EMIT_EVENT(&evt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_close_confirm_evt_hdlr
 * DESCRIPTION
 *  This function handles the events of the close confirm screen.
 * PARAMETERS
 *  event               : [IN]          Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_nmgr_close_confirm_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *evt = (mmi_alert_result_evt_struct *)event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(evt);

    if (evt->evt_id == EVT_ID_ALERT_QUIT && evt->result == MMI_ALERT_CNFM_YES)
    {
        mmi_nmgr_close_confirm_yes_hdlr();
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_entry_close_confirm
 * DESCRIPTION
 *  This function shows a popup to confirm if the user really wants to cancel
 *  the notification.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nmgr_entry_close_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = mmi_nmgr_close_confirm_evt_hdlr;
    arg.user_tag = NULL;

    mmi_confirm_display(
        (WCHAR *)get_string(STR_ID_NMGR_CANCEL_ASK),
        MMI_EVENT_QUERY,
        &arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_default_close_hdlr
 * DESCRIPTION
 *  This function is the exit function of the default notification screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nmgr_default_close_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_nmgr_cancel(g_nmgr_cntx.active_req.type);
    mmi_frm_scrn_close(mmi_idle_get_group_id(), SCR_ID_NMGR_NOTIFY_ON_IDLE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_default_exec_hdlr
 * DESCRIPTION
 *  This function is the execute function of the default notification screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nmgr_default_exec_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_cntx_valid;
    mmi_nmgr_answer_struct *cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_nmgr_answer_struct*)OslMalloc(sizeof(mmi_nmgr_answer_struct));

    is_cntx_valid = mmi_nmgr_get_intgr_app_cntx(
                        g_nmgr_cntx.active_req.type,
                        cntx);
    
    if (is_cntx_valid && cntx->hdlr)
    {
        if (!MMI_NMGR_HAS(g_nmgr_cntx.active_req.flag, MMI_NMGR_OPTION_SELF_CANCEL_ON_EXEC))
        {
            mmi_nmgr_cancel(g_nmgr_cntx.active_req.type);
        }

        cntx->hdlr(cntx->user_data);
    }

    OslMfree(cntx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_exit_default
 * DESCRIPTION
 *  This function is the exit function of the default notification screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nmgr_exit_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If the event is not viewed or dismissed by the user, e.g. the
       notification screen is closed because of interrupts, insert the event
       to the qeueu. Then it can be displayed again when the handset goes back
       to idle screen. */
    if (mmi_nmgr_app_has_new_event(g_nmgr_cntx.active_req.type))
    {
        mmi_nmgr_queue_insert_front(&(g_nmgr_cntx.active_req));
    }

    /* Save & Reset the active event and flag. */
    g_nmgr_cntx.prev_req = g_nmgr_cntx.active_req;
    mmi_nmgr_reset_request(&g_nmgr_cntx.active_req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_entry_default
 * DESCRIPTION
 *  This function is called by APP to notify the user if toolbar is on.
 * PARAMETERS
 *  type            [IN]            Application ID
 *  flag            [IN]            Option flag
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_nmgr_entry_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nmgr_answer_struct *cntx;
    U16 lsk, rsk;
    U16 csk_img = IMG_GLOBAL_COMMON_CSK;
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_MMI_NMGR_DEFAULT_IDLE);

    /* Make sure it is 4-bytes aligned. */
    cntx = (mmi_nmgr_answer_struct *)subMenuData;
    cntx = (mmi_nmgr_answer_struct *)(((U32)cntx + 3) & ~0x3);

    ret = mmi_nmgr_get_intgr_app_cntx(g_nmgr_cntx.proc_req.type, cntx);

    /* APP could call mmi_nmgr_refresh to refresh the screen. If there is no
       events finally, we should close the notification screen. */
    if (!ret || cntx->total_num <= 0)
    {
        return MMI_FALSE;
    }
    
    ret = mmi_frm_scrn_enter(
            mmi_idle_get_group_id(), 
            SCR_ID_NMGR_NOTIFY_ON_IDLE, 
            mmi_nmgr_exit_default,
            NULL,
            MMI_FRM_FULL_SCRN);
    MMI_ASSERT(ret);
    
    /* Determine whether there should have left soft key. */
    if (!cntx->hdlr)
    {
        lsk = 0;
    }
    else
    {
        lsk = (cntx->left_softkey? cntx->left_softkey: STR_GLOBAL_VIEW);
    }

    /* Determine the RSK string ID. */
    if (MMI_NMGR_HAS(g_nmgr_cntx.proc_req.flag, MMI_NMGR_OPTION_CONFIRM_CANCEL))
    {
        rsk = STR_GLOBAL_CANCEL; /* RSK: show a "Cancel?" confirm */
    }
    else
    {
        rsk = STR_GLOBAL_BACK;   /* RSK: go back directly */
    }
    
    ShowCategory154Screen(
        0, 
        0, 
        lsk, 
        0, 
        rsk, 
        0, 
        (PU8)cntx->idle_text1, 
        (PU8)cntx->idle_text2, 
        cntx->image, 
        NULL);

    SetLeftSoftkeyFunction(mmi_nmgr_default_exec_hdlr, KEY_EVENT_UP);
    if (cntx->left_softkey == STR_GLOBAL_OPTIONS)
    {
        csk_img = IMG_GLOBAL_OPTION_CSK;
    }
	ChangeCenterSoftkey(0, csk_img);
	SetCenterSoftkeyFunction(mmi_nmgr_default_exec_hdlr, KEY_EVENT_UP);

    if (MMI_NMGR_HAS(g_nmgr_cntx.proc_req.flag, MMI_NMGR_OPTION_CONFIRM_CANCEL))
    {
        SetRightSoftkeyFunction(mmi_nmgr_entry_close_confirm, KEY_EVENT_UP);
        SetKeyHandler(mmi_nmgr_entry_close_confirm, KEY_END, KEY_EVENT_DOWN);
    }
    else
    {
        SetRightSoftkeyFunction(mmi_nmgr_default_close_hdlr, KEY_EVENT_UP);
        SetKeyHandler(mmi_nmgr_default_close_hdlr, KEY_END, KEY_EVENT_DOWN);
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_set_active_notify
 * DESCRIPTION
 *  This function is to reset nmgr context information.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nmgr_set_active_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_nmgr_cntx.active_req = g_nmgr_cntx.proc_req;
    mmi_nmgr_reset_request(&g_nmgr_cntx.proc_req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_timeout
 * DESCRIPTION
 *  This function handles the timeout of the notification guard timer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nmgr_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_shown;
    mmi_nmgr_req_struct req;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_MMI_NMGR_TIMEOUT, g_nmgr_cntx.state);

    StopTimer(IDLE_NMGR_GUARD_TIMER);

	g_nmgr_cntx.state = 0;

    if (g_nmgr_cntx.wait_req.type != 0)
    {
        mmi_nmgr_queue_insert_front(&(g_nmgr_cntx.proc_req));
        mmi_nmgr_reset_request(&g_nmgr_cntx.proc_req);

        req = g_nmgr_cntx.wait_req;
        mmi_nmgr_reset_request(&g_nmgr_cntx.wait_req);

        mmi_nmgr_notify_common(&req);

        return;
    }

    if (mmi_idle_is_group_active() &&
        mmi_frm_scrn_get_active_id() == SCR_ID_NMGR_DUMMY)
    {
        MMI_ASSERT(g_nmgr_cntx.proc_req.func);

        is_shown = g_nmgr_cntx.proc_req.func();
        if (is_shown)
        {
        #if defined(__MMI_SCREEN_SWITCH_EFFECT__)
            gui_screen_switch_effect_block(MMI_TRUE);
        #endif

            mmi_nmgr_set_active_notify();
        }
        else
        {
            mmi_nmgr_cancel(g_nmgr_cntx.proc_req.type);
            mmi_nmgr_reset_request(&g_nmgr_cntx.proc_req);
            mmi_frm_scrn_close(mmi_idle_get_group_id(), SCR_ID_NMGR_DUMMY);
        }
    }
    else
    {
       /*
        * If interrupt happens, e.g. the user enters main menu or USB connected,
        * push the event to the queue. The event will be processed when the
        * handset goes back to idle screen later.
        */
        mmi_nmgr_queue_insert_front(&(g_nmgr_cntx.proc_req));
        mmi_nmgr_reset_request(&g_nmgr_cntx.proc_req);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_exit_dummy
 * DESCRIPTION
 *  This function is the exit function of the dummy screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nmgr_exit_dummy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_freeze(MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_entry_dummy
 * DESCRIPTION
 *  This function shows a dummy screen when we are querying APP.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nmgr_entry_dummy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_get_active_id() == SCR_ID_NMGR_DUMMY)
    {
        return;
    }

    ret = mmi_frm_scrn_enter(
            mmi_idle_get_group_id(),
            SCR_ID_NMGR_DUMMY,
            mmi_nmgr_exit_dummy,
            NULL,
            MMI_FRM_UNKNOW_SCRN);
    MMI_ASSERT(ret);

    /* 
     * To make sure the notification can have the idle as their background, show
     * the idle's category screen. This is mainly used for the OP11 and OP12 
     * notification.
     */
    if (MMI_NMGR_HAS(g_nmgr_cntx.proc_req.flag, MMI_NMGR_FLAG_NEED_BACKGROUND))
    {
        mmi_idle_show_category();
    }

    gdi_lcd_freeze(MMI_TRUE);
    mmi_frm_set_all_key_hdlr_null();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_is_curr_evt_in_processing
 * DESCRIPTION
 *  This function check if nmgr is processing current notified event.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return MMI_TRUE if processed event is in processing,
 *  otherwise, return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL mmi_nmgr_is_curr_evt_in_processing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_nmgr_cntx.proc_req.type == MMI_NMGR_APP_NULL ? MMI_FALSE : MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_query_app_info
 * DESCRIPTION
 *  This function query app information for nmgr notify screen.
 * PARAMETERS
 *  type            [IN]            Application ID
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nmgr_query_app_info(U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_nmgr_ctrl_tbl_struct *tbl = mmi_nmgr_get_ctrl_tbl();
    U32 valid_type = 0;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_NMGR_APP_NUM; i++)
    {
        if (MMI_NMGR_HAS(type, tbl[i].type))
        {
            valid_type |= tbl[i].type;
        }
    }

    g_nmgr_cntx.state = valid_type;

    for (i = 0; i < MMI_NMGR_APP_NUM; i++)
    {
        if (MMI_NMGR_HAS(g_nmgr_cntx.state, tbl[i].type))
        {
            MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_MMI_NMGR_QUERY, tbl[i].type);
            tbl[i].query_func();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_invoke_notify_event
 * DESCRIPTION
 *  This function invoke and process notified event, then display nmgr screen to user.
 * PARAMETERS
 *  type            [IN]            Application ID
 *  flag            [IN]            Option flag
 *  entry_func      [IN]            entry function of nmgr notify screen
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nmgr_invoke_notify_event(mmi_nmgr_req_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_nmgr_cntx.proc_req = *req; /* copy */

    mmi_nmgr_entry_dummy();
    mmi_nmgr_query_app_info(g_nmgr_cntx.proc_req.type);

    /* 
     * Some APP will return MMI_NMGR_RESULT_NOT_READY in mmi_nmgr_answer. So,
     * start timer to set a deadline to invoke timeout to display the screen.
     */
    if (g_nmgr_cntx.state)
    {
        StartTimer(IDLE_NMGR_GUARD_TIMER, MMI_NMGR_GUARD_TOV, mmi_nmgr_timeout);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_notify_common
 * DESCRIPTION
 *  This function is the common function to notify the user.
 * PARAMETERS
 *  type            [IN]            Application ID
 *  flag            [IN]            Option flag
 * RETURNS
 *  If this event is processed immediately, return MMI_TRUE; otherwise, return
 *  MMI_FALSE if the notification manager is busy now.
 *****************************************************************************/
static MMI_BOOL mmi_nmgr_notify_common(mmi_nmgr_req_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Scenario:
     *  There is already an event being processed.
     *
     * Problem:
     *  The event being processed might be the same as the new one. We should
     *  re-collect the information after all APP has returned the answer.
     *
     * Solution:
     *  If the new event is the same as the one being processed, set a flag such
     *  that we can re-collect the information later. Otherwise, just put it
     *  into the queue.
     */
    if (mmi_nmgr_is_curr_evt_in_processing())
    {
        if (g_nmgr_cntx.wait_req.type != 0)
        {
            mmi_nmgr_queue_insert_front(&(g_nmgr_cntx.wait_req));
        }

        g_nmgr_cntx.wait_req = *req;

        return MMI_FALSE;
    }

    /*
     * Event can be notified immediately when
     *
     *  Condition 1: the event has higher priority than the active scenario and
     *  Condition 2: idle or screen saver or notification is active
     */
    if (!MMI_NMGR_HAS(req->flag, MMI_NMGR_OPTION_LOWER_PRIORITY) &&
        (mmi_idle_is_active() ||
    #if defined(__MMI_SCREEN_SAVER__)
         mmi_scr_saver_is_active() ||
    #endif
         mmi_nmgr_is_active()))
    {
        mmi_nmgr_invoke_notify_event(req);
        return MMI_TRUE;
    }
    else
    {
        /* This flag is only used when the notify API is called. Later, when we
           fetch the request from the queue to process it, it doesn't need to
           check this flag. */
        MMI_NMGR_CLR(req->flag, MMI_NMGR_OPTION_LOWER_PRIORITY);
        mmi_nmgr_queue_insert_front(req);
        return MMI_FALSE;
    }
}


/* For the detail information, please refer to IdleNotificationManagerGprot.h */
MMI_BOOL mmi_nmgr_notify(U32 type, U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL processed = MMI_FALSE;
    mmi_nmgr_req_struct req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_MMI_NMGR_NOTIFY, type, flag);

    /*
     * Initialize the request.
     */
    mmi_nmgr_reset_request(&req);
    req.trigger = type;
    req.flag = flag;

    /*
     * Find a notifier that can handle this type of the notification.
     */
#ifdef __MMI_EVENT_LIST__
    if ((req.type = mmi_nmgr_event_list_get_event(type)) != 0)
    {
        req.flag |= MMI_NMGR_FLAG_NEED_BACKGROUND;
        req.func = mmi_nmgr_entry_event_list;
        processed = mmi_nmgr_notify_common(&req);
        MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_MMI_NMGR_IS_PROCESSED, 300, processed);
    }
    else
#endif /* __MMI_EVENT_LIST__ */
#if defined(__MMI_OP11_HOMESCREEN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_OP11_HOMESCREEN__) */
    if ((req.type = mmi_nmgr_get_intgr_app_id(type)) != 0)
    {
        req.func = mmi_nmgr_entry_default;
        processed = mmi_nmgr_notify_common(&req);
        MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_MMI_NMGR_IS_PROCESSED, 9000, processed);
    }

    MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_MMI_NMGR_IS_PROCESSED, 10000, processed);
    
    return processed;
}


/* For the detail information, please refer to IdleNotificationManagerGprot.h */
MMI_BOOL mmi_nmgr_refresh(U32 type, U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* No need to refresh if the idle notification screen is not active. */
    if (!mmi_nmgr_is_active())
    {
        return ret;
    }
    
    /* Refresh idle notification screen if active event includes this type. */
    if (MMI_NMGR_HAS(g_nmgr_cntx.active_req.type, type))
    {
        mmi_nmgr_notify(type, flag);
    }
	
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_update_cntx
 * DESCRIPTION
 *  This function updates the context.
 * PARAMETERS
 *  cntx            [OUT]           Context
 *  info            [IN]            Information provided by APP
 *  hdlr            [IN]            Handler about this notification
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nmgr_update_cntx(
                mmi_nmgr_answer_struct *cntx,
                mmi_nmgr_info_struct *info,
                mmi_nmgr_hdlr_func_t hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_MMI_NMGR_ANSWER_INFO,
                info->total_num, info->icon, 0, (U32)hdlr);

    if (info->idle_text1)
    {
        mmi_ucs2ncpy(cntx->idle_text1, info->idle_text1, MMI_NMGR_MAX_STR_LEN);
    }
    else
    {
        mmi_ucs2cpy(cntx->idle_text1, (CHAR *)L"");
    }
    
    if (info->idle_text2)
    {
        mmi_ucs2ncpy(cntx->idle_text2, info->idle_text2, MMI_NMGR_MAX_STR_LEN);
    }
    else
    {
        mmi_ucs2cpy(cntx->idle_text2, (CHAR *)L"");
    }
    
    cntx->image        = info->image;
    cntx->total_num    = info->total_num;
    cntx->icon         = info->icon;
    cntx->left_softkey = info->left_softkey;
    cntx->hdlr         = hdlr;
    cntx->user_data    = info->user_data;
}


/* For the detail information, please refer to IdleNotificationManagerGprot.h */
void mmi_nmgr_answer(
        U32 type,
        mmi_nmgr_result_enum result,
        mmi_nmgr_info_struct *info,
        mmi_nmgr_hdlr_func_t hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nmgr_answer_struct *cntx = mmi_nmgr_get_app_cntx(type);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_MMI_NMGR_ANSWER, type, result);

    if (result == MMI_NMGR_RESULT_NOT_READY)
    {
        return;
    }

    /* 
     * Update notification default context. 
     */
    g_nmgr_cntx.state &= ~type;    
    
    if (info)
    {
        mmi_nmgr_update_cntx(cntx, info, hdlr);
    }
    else
    {
        memset(cntx, 0, sizeof(mmi_nmgr_answer_struct));
    }

    if (g_nmgr_cntx.state == 0 && mmi_nmgr_is_curr_evt_in_processing())
    {
        mmi_nmgr_timeout();
    }
}


/* For the detail information, please refer to IdleNotificationManagerGprot.h */
MMI_BOOL mmi_nmgr_is_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID scrn_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrn_id = mmi_frm_scrn_get_active_id();

    if ((mmi_idle_is_group_active()) &&
        (scrn_id == SCR_ID_NMGR_NOTIFY_ON_IDLE || scrn_id == SCR_ID_NMGR_DUMMY))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/* For the detail information, please refer to IdleNotificationManagerGprot.h */
/* TODO: Obsolete. Remove it. */
MMI_BOOL mmi_nmgr_is_active_on_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_nmgr_is_active();
}


/* For the detail information, please refer to IdleNotificationManagerGprot.h */
U32 mmi_nmgr_get_current_process_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_nmgr_cntx.proc_req.trigger != MMI_NMGR_APP_NULL)
    {
        return g_nmgr_cntx.proc_req.trigger;
    }
    else
    {
        return g_nmgr_cntx.active_req.trigger;
    }
}


/* For the detail information, please refer to IdleNotificationManagerGprot.h */
void mmi_nmgr_get_app_info(U32 type, mmi_nmgr_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nmgr_answer_struct *cntx = mmi_nmgr_get_app_cntx(type);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    info->idle_text1   = (CHAR *)cntx->idle_text1;
    info->idle_text2   = (CHAR *)cntx->idle_text2;
    info->image        = cntx->image;
    info->left_softkey = cntx->left_softkey;
    info->total_num    = cntx->total_num;
    info->user_data    = cntx->user_data;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_direct_notify
 * DESCRIPTION
 *  This function get and process notifieed event, display nmgr notify screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_nmgr_direct_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nmgr_req_struct req;
    MMI_BOOL is_success;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_nmgr_is_curr_evt_in_processing())
    {
        mmi_nmgr_entry_dummy();
        return;
    }

    is_success = mmi_nmgr_queue_remove(&req);
    MMI_ASSERT(is_success);

    mmi_nmgr_invoke_notify_event(&req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_need_notification
 * DESCRIPTION
 *  This function check if there are any notified events need to process.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_nmgr_need_notification(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_nmgr_req_struct *req;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_nmgr_is_curr_evt_in_processing())
    {
        return 1;
    }

    /*
     * Need to check if this pending event still exits. For example, for an SMS
     * event come in main menu, the user could first go to message inbox to view
     * it and then delete it. Then, when the user goes back to idle, it doesn't
     * need to notify this SMS anymore.
     */
    while ((req = mmi_nmgr_queue_index(0)) != NULL)
    {
        if (mmi_nmgr_app_has_new_event(req->type))
        {
            return 1;
        }
        else
        {
            mmi_nmgr_queue_remove(NULL);
        }
    }

    return 0;
}


/* For the detail information, please refer to IdleNotificationManagerGprot.h */
void mmi_nmgr_initialize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_nmgr_cntx, 0, sizeof(mmi_nmgr_context_struct));

    g_nmgr_cntx.queue = lcd_create_cqueue_with_mem(
                            MMI_NMGR_MAX_NOTIFY_NUM,
                            g_nmgr_cntx.queue_context);
}


/*****************************************************************************
 * [Event List]
 *
 * Follows implement the event list
 *****************************************************************************/

#ifdef __MMI_EVENT_LIST__

/*****************************************************************************
 * Typedef
 *****************************************************************************/

typedef struct
{
    U32                     app_id;
    U16                     singular;  /* String of singular, which will be appended to the number */
    U16                     plurality; /* String of plurality, which will be appended to the number*/
} mmi_nmgr_event_list_item_config_struct;
 
typedef struct
{
    U32                     app_id;
    U16                     lsk_str_id;
    void                   *user_data;
    mmi_nmgr_hdlr_func_t    hdlr;
} mmi_nmgr_event_list_item_data_struct;

typedef struct
{
    S32                                    highlighted_index;
    U32                                    highlighted_app;
    U32                                    num_of_items;
    mmi_nmgr_event_list_item_data_struct  *item_data;
    FuncPtr                                default_end_key_handler;
} mmi_nmgr_event_list_context_struct;


/*****************************************************************************
 * Configuration
 *****************************************************************************/

static const mmi_nmgr_event_list_item_config_struct g_mmi_nmgr_event_list_item_config[] =
{
    /*
     * NOTE: The union of each pair of apps should be empty set!
     */
    { MMI_NMGR_APP_MISSED_CALL,     STR_ID_NMGR_MISSED_CALL_SUFFIX,     STR_ID_NMGR_MISSED_CALLS_SUFFIX   },
    { MMI_NMGR_INTGR_APP_UM,        STR_ID_NMGR_NEW_MSG_SUFFIX,         STR_ID_NMGR_NEW_MSGS_SUFFIX       },
#ifndef __MMI_MMS_IN_UM__
    { MMI_NMGR_APP_MMS,             STR_ID_NMGR_NEW_MMS_MSG_SUFFIX,     STR_ID_NMGR_NEW_MMS_MSGS_SUFFIX   },
#endif /* !__MMI_MMS_IN_UM__ */
#ifndef __MMI_PUSH_IN_UM__
    { MMI_NMGR_APP_WAP_PUSH,        STR_ID_NMGR_NEW_PUSH_MSG_SUFFIX,    STR_ID_NMGR_NEW_PUSH_MSGS_SUFFIX  },
#endif /* !__MMI_PUSH_IN_UM__ */
#ifdef __MMI_EMAIL__
    { MMI_NMGR_APP_EMAIL,           STR_ID_NMGR_NEW_EMAIL_SUFFIX,       STR_ID_NMGR_NEW_EMAILS_SUFFIX     },
#endif
    { MMI_NMGR_APP_MESSAGE_WAITING, STR_ID_NMGR_NEW_VOICEMAIL_SUFFIX,   STR_ID_NMGR_NEW_VOICEMAILS_SUFFIX }
};

static const U32 g_mmi_nmgr_event_list_max_num_of_items =
    sizeof(g_mmi_nmgr_event_list_item_config)/sizeof(mmi_nmgr_event_list_item_config_struct);


/*****************************************************************************
 * Global Variables
 *****************************************************************************/
 
static mmi_nmgr_event_list_context_struct g_mmi_nmgr_event_list_context = {
    -1,
    0,
    0,
    NULL
    /* Follows we don't care */
};


/*****************************************************************************
 * Local Functions
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_event_list_get_event
 * DESCRIPTION
 *  Check whether the event is required by the event list of normal Idle
 * PARAMETERS
 *  type            [IN]            Application ID
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static U32 mmi_nmgr_event_list_get_event(U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_NMGR_HAS(MMI_NMGR_INTGR_APP_NORMAL_IDLE, type))
    {
        return MMI_NMGR_INTGR_APP_NORMAL_IDLE;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_event_list_reset
 * DESCRIPTION
 *  Reset status of event list when entering Idle without event raised
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nmgr_event_list_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_nmgr_event_list_context.highlighted_index = -1;
    g_mmi_nmgr_event_list_context.highlighted_app = 0;
    g_mmi_nmgr_event_list_context.num_of_items = 0;
    g_mmi_nmgr_event_list_context.item_data = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_event_list_go_back
 * DESCRIPTION
 *  Handler for "Back" on event list. It cancels all notifications, reset menu
 *  data and go back history.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nmgr_event_list_go_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_nmgr_event_list_reset();

    mmi_nmgr_cancel(g_nmgr_cntx.active_req.type);
    mmi_frm_scrn_close(mmi_idle_get_group_id(), SCR_ID_NMGR_NOTIFY_ON_IDLE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_event_list_on_item_selected
 * DESCRIPTION
 *  LSK handler for the event user selected. It calls the handler given by
 *  application for the event.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nmgr_event_list_on_item_selected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    mmi_nmgr_event_list_item_data_struct *item_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = g_mmi_nmgr_event_list_context.highlighted_index;
    
    if (index < 0 || index >= (S32)g_mmi_nmgr_event_list_context.num_of_items)
    {
        return; /* fail-safe */
    }

    item_data = &(g_mmi_nmgr_event_list_context.item_data[index]);
    
    mmi_nmgr_cancel(item_data->app_id);

    if (item_data->hdlr != NULL)
    {
        item_data->hdlr(item_data->user_data);
    }
    else
    {
        mmi_frm_scrn_close(mmi_idle_get_group_id(), SCR_ID_NMGR_NOTIFY_ON_IDLE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_event_list_on_highlight
 * DESCRIPTION
 *  Highlight handler of event list.
 * PARAMETERS
 *  index       [IN] The index which is highlighted currently
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_nmgr_event_list_on_highlight(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nmgr_event_list_item_data_struct *item_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < 0 || index >= (S32)g_mmi_nmgr_event_list_context.num_of_items)
    {
        return; /* fail-safe */
    }

    g_mmi_nmgr_event_list_context.highlighted_index = index;
    item_data = &(g_mmi_nmgr_event_list_context.item_data[index]);
    g_mmi_nmgr_event_list_context.highlighted_app = item_data->app_id;

    ChangeLeftSoftkey(item_data->lsk_str_id, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_nmgr_entry_event_list
 * DESCRIPTION
 *  Entry function of event list of normal Idle.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_nmgr_entry_event_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nmgr_answer_struct *intgr_answer; /* Temp space of intgr answer */
    U8 *buffer;
    U32 i;
    U8 *gui_buffer;
    U8 **list_of_strings;
    U8 **list_of_icons;
    mmi_nmgr_event_list_item_data_struct *item_data;
    S32 highlighted_index;
    U32 num_of_items;
    U16 suffix_id;
    U32 new_event_flags; /* For trace use */
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    buffer = (U8*)(&subMenuData);
    buffer = (U8*)(((U32)buffer + 3) & ~0x3); /* Align to 4-byte */
    list_of_strings = (U8**)buffer;
    buffer += g_mmi_nmgr_event_list_max_num_of_items * sizeof(U8*);
    list_of_icons = (U8**)buffer;
    buffer += g_mmi_nmgr_event_list_max_num_of_items * sizeof(U8*);
    g_mmi_nmgr_event_list_context.item_data = (mmi_nmgr_event_list_item_data_struct*)buffer;
    buffer += g_mmi_nmgr_event_list_max_num_of_items * sizeof(mmi_nmgr_event_list_item_data_struct);
    
    intgr_answer = NULL;
    highlighted_index = -1;
    num_of_items = 0;

    new_event_flags = 0;
    
    for (i = 0; i < g_mmi_nmgr_event_list_max_num_of_items; i++)
    {
        const mmi_nmgr_event_list_item_config_struct *item_config;
        mmi_nmgr_answer_struct *app_info;
    
        item_config = &(g_mmi_nmgr_event_list_item_config[i]);
        app_info = NULL;

        if (!mmi_nmgr_app_has_new_event(item_config->app_id))
        {
        	continue; /* No new event */
        }

        new_event_flags |= item_config->app_id; /* For trace use */
        
        if (mmi_nmgr_is_intgr_app_id(item_config->app_id))
        {
            if (intgr_answer == NULL)
            {
                intgr_answer = (mmi_nmgr_answer_struct*)OslMalloc(sizeof(mmi_nmgr_answer_struct));
            }
            if (mmi_nmgr_get_intgr_app_cntx(item_config->app_id, intgr_answer))
            {
                app_info = intgr_answer;
            }
        }
        else
        {
            app_info = mmi_nmgr_get_app_cntx(item_config->app_id);
        }

        if (app_info == NULL || app_info->total_num <= 0)
        {
            continue;
        }

        /* Allocate space to list_of_string[num_of_items] and generate string */
        if (app_info->total_num > 1)
        {
            suffix_id = item_config->plurality;
        }
        else
        {
            suffix_id = item_config->singular;
        }
        kal_wsprintf((U16*)buffer, "%d %w", app_info->total_num, GetString(suffix_id));
        list_of_strings[num_of_items] = (U8*)buffer;
        buffer += (mmi_ucs2strlen((CHAR *)buffer) + 1) * ENCODING_LENGTH;

        list_of_icons[num_of_items] = get_image((MMI_ID_TYPE)app_info->icon);
        item_data = &(g_mmi_nmgr_event_list_context.item_data[num_of_items]);
        item_data->app_id = item_config->app_id;

        /* Prepare LSK data */
        item_data->hdlr = app_info->hdlr;
        item_data->user_data = app_info->user_data;
        item_data->lsk_str_id = app_info->left_softkey;
        if (item_data->hdlr == NULL)
        {
            item_data->lsk_str_id = STR_GLOBAL_REMOVE;
        }
        if (item_data->lsk_str_id == 0)
        {
            item_data->lsk_str_id = STR_GLOBAL_VIEW;
        }

        /* Highlight the item which highlighted previously */
        if (item_data->app_id == g_mmi_nmgr_event_list_context.highlighted_app)
        {
            highlighted_index = num_of_items;
        }

        num_of_items++;
    }
    
    if (intgr_answer != NULL)
    {
        OslMfree(intgr_answer);
    }

    MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, TRC_MMI_NMGR_ENTRY_EVENT_LIST,
        new_event_flags, num_of_items, g_mmi_nmgr_event_list_context.highlighted_app);

    if (highlighted_index < 0) /* Not found the app which is highlighted previously */
    {
        highlighted_index = 0; /* Highlight first item by default */
        g_mmi_nmgr_event_list_context.highlighted_app = 0; /* Don't highlight any app by default next time */
    }
    g_mmi_nmgr_event_list_context.highlighted_index = highlighted_index;
    g_mmi_nmgr_event_list_context.num_of_items = num_of_items;

    /* APP could call mmi_nmgr_refresh to refresh the screen. If there is no
       events finally, we should close the notification screen. */
    if (g_mmi_nmgr_event_list_context.num_of_items <= 0)
    {
        return MMI_FALSE;
    }

    ret = mmi_frm_scrn_enter(
            mmi_idle_get_group_id(), 
            SCR_ID_NMGR_NOTIFY_ON_IDLE,
            mmi_nmgr_exit_default,
            NULL,
            MMI_FRM_FULL_SCRN);
    MMI_ASSERT(ret);

    gui_buffer = mmi_frm_scrn_get_gui_buf(
                    mmi_idle_get_group_id(), 
                    SCR_ID_NMGR_NOTIFY_ON_IDLE);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory110Screen(
        NULL,
        NULL,
        get_string(g_mmi_nmgr_event_list_context.item_data[highlighted_index].lsk_str_id),
        NULL,
        get_string(STR_GLOBAL_BACK),
        get_image(IMG_GLOBAL_BACK),
        num_of_items,
        list_of_strings,
        list_of_icons,
        NULL,
        0,
        highlighted_index,
        gui_buffer);

    SetParentHandler(0);
    RegisterHighlightHandler(mmi_nmgr_event_list_on_highlight);

    /* Set key handlers */
    SetLeftSoftkeyFunction(mmi_nmgr_event_list_on_item_selected, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_nmgr_event_list_on_item_selected, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_nmgr_event_list_go_back, KEY_EVENT_UP);
    SetKeyHandler(mmi_nmgr_event_list_go_back, KEY_END, KEY_EVENT_DOWN);

    return MMI_TRUE;
}
#endif /* __MMI_EVENT_LIST__ */


#if defined(__MMI_OP11_HOMESCREEN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_EMAIL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_EMAIL__) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_EMAIL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_EMAIL__) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_OP11_HOMESCREEN__) */

#endif/*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/
