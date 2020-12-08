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
 *    AlertScreen.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   for alert (popup/confirm) screens
 *
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
 *
 * removed!
 * removed!
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
 *
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
*  Include
*****************************************************************************/


#include "AlertScreen.h"
#include "ProfilesSrvGprot.h"
#include "wgui_categories_list.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_frm_events_gprot.h"
#include "wgui.h"
#include "MMI_features.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_util.h"
#include "GlobalResDef.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "string.h"
#include "MMI_fw_trc.h"
#include "mmi_fw_trc.h"
#include "kal_trace.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "GlobalConstants.h"
#include "gui.h"
#include "CommonScreensResDef.h"
#include "gui_typedef.h"
#include "ScreenRotationGprot.h"
#include "mmi_frm_history_gprot.h"
#include "gui_effect_oem.h"
#include "custom_events_notify.h"
#include "wgui_categories_popup.h"
#include "Unicodexdcl.h"
#include "wgui_include.h"
#include "mmi_rp_cui_alert_def.h"
#include "gpiosrvgprot.h"
#include "mmi_rp_srv_editor_def.h"
#include "mmi_frm_prot.h"
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 


/*****************************************************************************
 *  Define
 *****************************************************************************/
#define MMI_ALERT_TITLE_CHARACTER_MAX (51)  // Application can input max character in popup
#define MMI_ALERT_TITLE_MAX     (MMI_ALERT_TITLE_CHARACTER_MAX + 4)   /* 3 is the "..." */


#if defined(__MMI_BASIC_UI_STYLE__) || defined(__COSMOS_MMI_PACKAGE__)
	#define MMI_ALERT_POOL_SIZE     (5)
#else
	#define MMI_ALERT_POOL_SIZE     (10)
#endif


/* if defined, use local buffer; otherwise, use control buffer */
#define __MMI_ALERT_CTX_USE_LOCAL_BUFFER__

/*****************************************************************************
 *  Typedef
 *****************************************************************************/

typedef enum {
    MMI_ALERT_TYPE_POPUP,
    MMI_ALERT_TYPE_CONFIRM,
    MMI_ALERT_TYPE_END
} mmi_alert_type_enum;

typedef struct {
    FuncPtr hdlr;
    MMI_STR_ID  str_id;
    MMI_IMG_ID  img_id; 
} mmi_confirm_sk_info_struct;

typedef struct {
    mmi_confirm_type_enum ctype;
    mmi_confirm_sk_info_struct sk_info[MMI_CONFIRM_SOFTKEY_NUM];
} mmi_confirm_sk_mapping_struct;


#ifdef __MMI_ALERT_CTX_USE_LOCAL_BUFFER__

typedef struct list_struct {
    struct list_struct *next;
} list_struct;

#define LIST_STRUCT \
    list_struct *next

#define LIST_INIT(_buff, _type, _free_list)     list_init((U32)_buff, sizeof(_type), sizeof(_buff), (list_struct *)_free_list)
#define LIST_GET(_free_list, _used_list)  list_get((list_struct *)_free_list, (list_struct *)_used_list)
#define LIST_FREE(_item, _free_list, _used_list) list_free((list_struct *)_item, (list_struct *)_free_list, (list_struct *)_used_list)
#define LIST_RESET_ITEM(_item, _struct)             \
            do {                                    \
                list_struct *tmp = _item->next;     \
                memset(_item, 0, sizeof(_struct));  \
                _item->next = tmp;                  \
            } while(0)

#endif /* __MMI_ALERT_CTX_USE_LOCAL_BUFFER__ */

typedef struct {
    mmi_popup_property_struct arg;
    MMI_BOOL timer_longer_than_tone;
    MMI_BOOL popup_keydown_flag;
    MMI_BOOL is_normal_exit_event_sent;
} mmi_popup_ctx_struct; 

typedef struct {
    mmi_confirm_property_struct arg;
    MMI_BOOL is_normal_exit_event_sent;
} mmi_confirm_ctx_struct;

typedef struct {
#ifdef __MMI_ALERT_CTX_USE_LOCAL_BUFFER__
    LIST_STRUCT;
#endif
    mmi_alert_type_enum type;
    mmi_event_notify_enum event_type;
    WCHAR title[MMI_ALERT_TITLE_MAX+1];
    srv_prof_tone_enum tone_id;
    MMI_ID alert_id;
    union {
        mmi_popup_ctx_struct   popup;
        mmi_confirm_ctx_struct confirm;
    } sub;
} mmi_alert_ctx_struct;


typedef void (*set_softkey_func_type)(void (*)(void), MMI_key_event_type);

/*
typedef struct {
    mmi_alert_type_enum type;
    mmi_proc_func entry_func;
} mmi_alert_entry_mapping_struct;
*/

/*****************************************************************************
 * Global variables
 *****************************************************************************/

/*
static mmi_alert_entry_mapping_struct alert_entry[] = {
            {MMI_ALERT_TYPE_POPUP, popup_entry},
            {MMI_ALERT_TYPE_CONFIRM, confirm_entry}};
*/

/*****************************************************************************
 * Local variables
 *****************************************************************************/

static void alert_event(U16 evt_id,mmi_alert_result_enum result,mmi_alert_ctx_struct * ctx,U32 tx_type);
static void post_invoke(mmi_proc_func proc, void *user_data);
static mmi_ret show_alert(mmi_event_struct *evt);
static void alert_finish(mmi_alert_ctx_struct *ctx, mmi_alert_result_enum result);
static void alert_tx_quit_event(U32 tx_type, mmi_alert_ctx_struct *ctx, mmi_alert_result_enum result);
static mmi_proc_func get_callback(mmi_alert_ctx_struct *ctx);
static void *get_user_tag(mmi_alert_ctx_struct *ctx);
static mmi_ret alert_tx_event(U32 tx_type, mmi_proc_func callback, mmi_event_struct *evt, mmi_alert_ctx_struct *ctx);


static void popup_keydown_handler(void);
static void popup_timeout_hdlr(void* arg);
static void popup_general_key_hdlr(void);
static void popup_tone_end_hdlr(S32 result);
#ifdef __MMI_TOUCH_SCREEN__
static MMI_BOOL popup_pen_down_hdlr(mmi_pen_point_struct point);
#endif
static mmi_ret popup_entry(mmi_scrn_essential_struct *info);
static mmi_ret confirm_entry(mmi_scrn_essential_struct *info);
static mmi_ret mmi_popup_key_proc(mmi_event_struct *evt);
static void get_alert_display_title(WCHAR* src_title, WCHAR* dest_title);
static void confirm_sk_hdlr(mmi_alert_result_enum result);

static void confirm_sk_ok_hdlr(void);
static void confirm_sk_yes_hdlr(void);
static void confirm_sk_no_hdlr(void);
static void confirm_sk_cancel_hdlr(void);
static void confirm_sk1_hdlr(void);
static void confirm_sk2_hdlr(void);
static void confirm_sk3_hdlr(void);

static mmi_alert_ctx_struct *alert_ctx_p = NULL;    /* for active (1) popup and (2) confirm softkey callback */

#ifdef __MMI_ALERT_CTX_USE_LOCAL_BUFFER__
static MMI_BOOL is_alert_ctx_initialized = MMI_FALSE;
static mmi_alert_ctx_struct alert_ctx_pool[MMI_ALERT_POOL_SIZE];
static list_struct alert_ctx_pool_free_list = {0};
static list_struct alert_ctx_pool_used_list = {0};
#endif /* __MMI_ALERT_CTX_USE_LOCAL_BUFFER__ */
static MMI_ID mmi_alert_get_screen_id(mmi_alert_ctx_struct *ctx);

static const FuncPtr default_sk_hdlr_tbl[MMI_CONFIRM_SOFTKEY_NUM] = {
    confirm_sk1_hdlr, confirm_sk2_hdlr, confirm_sk3_hdlr};


static const set_softkey_func_type set_softkey_func_tbl[MMI_CONFIRM_SOFTKEY_NUM] = {
    SetLeftSoftkeyFunction, SetCenterSoftkeyFunction, SetRightSoftkeyFunction};


static const mmi_confirm_sk_mapping_struct mmi_confirm_sk_mapping[] = {
    {CNFM_TYPE_OK,          {
                             {confirm_sk_ok_hdlr, STR_GLOBAL_OK, NULL},         /* confirm 1 */
                             {NULL, NULL, NULL},                                /* confirm 2 */
                             {NULL, NULL, NULL}                                 /* confirm 3 */ 
                            }},                               
    {CNFM_TYPE_YESNO,       {
                             {confirm_sk_yes_hdlr, STR_GLOBAL_YES, NULL},       /* confirm 1 */
						#ifdef __KJX_MULTI_LANGUAGE__	//xb add 2017-10-13 CSK仅用作播放暂停继续
							 {NULL, NULL, NULL},
						#else
                             {confirm_sk_yes_hdlr, NULL,NULL},                	/* confirm 2 */
                        #endif
                             {confirm_sk_no_hdlr, STR_GLOBAL_NO, NULL}          /* confirm 3 */
                            }},
    {CNFM_TYPE_CANCEL,      {
                             {NULL, NULL, NULL},                                /* confirm 1 */
                             {NULL, NULL, NULL},                                /* confirm 2 */
                             {confirm_sk_cancel_hdlr, STR_GLOBAL_CANCEL, NULL}  /* confirm 3 */
                            }},
    {CNFM_TYPE_OKCANCEL,    {
                             {confirm_sk_ok_hdlr, STR_GLOBAL_OK, NULL},         /* confirm 1 */
                             {confirm_sk_ok_hdlr, NULL,NULL},                 /* confirm 2 */
                             {confirm_sk_cancel_hdlr, STR_GLOBAL_CANCEL, NULL}  /* confirm 3 */
                            }},
    {CNFM_TYPE_YESNOCANCEL, {
                             {confirm_sk_yes_hdlr, STR_GLOBAL_YES, NULL},       /* confirm 1 */
                             {confirm_sk_no_hdlr, STR_GLOBAL_NO, NULL},         /* confirm 2 */
                             {confirm_sk_cancel_hdlr, STR_GLOBAL_CANCEL, NULL}  /* confirm 3 */
                            }}
    };


#ifdef __MMI_ALERT_CTX_USE_LOCAL_BUFFER__

static void add_node(list_struct *list, list_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	list_struct *temp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(list && node);
	temp = list;
    while(temp)
    {
        if(temp->next == node)
            return;
        temp = temp->next;
    }
    node->next = list->next;
    list->next = node;
}

static void remove_node(list_struct *list, list_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(list && node);
    while (list)
    {
        if (list->next == node)
        {
            list->next = node->next;
            node->next = NULL;
            break;
        }
        list = list->next;
    }
}


void list_init(U32 buff, U32 element_size, U32 buff_size, list_struct *free_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    list_struct *last_ptr = (list_struct *)(buff + buff_size - element_size);
    free_list->next = (list_struct *)buff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(buff < (U32)last_ptr)
    {
        ((list_struct *)buff)->next = (list_struct *)(buff + element_size);
        buff += element_size;
    }
    ((list_struct *)buff)->next = NULL;
}

void *list_get(list_struct *free_list, list_struct *used_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    list_struct *item = free_list->next;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item)
    {
        /* remove from free */  
        remove_node(free_list, item);

        /* add to used list */
        add_node(used_list, item);   
    }

    return item;
}

void list_free(list_struct *item, list_struct *free_list, list_struct *used_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item)
    {
        /* remove from used */
        remove_node(used_list, item);

        /* add to free list */
        add_node(free_list, item);
    }
}

#endif /* __MMI_ALERT_CTX_USE_LOCAL_BUFFER__ */

/*****************************************************************************
 * External function
 *****************************************************************************/



/*
1. where to store title/msg string for confirm in history
2. confirm can enter history, should give AP methods to remove it from history (ok)
3. have dismiss API for alert/confirm (ok)
4. buttons should be abstract and change its position
*/

/*****************************************************************************
 * alert general
 *****************************************************************************/ 


static void mmi_alert_ctx_init()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_ALERT_CTX_USE_LOCAL_BUFFER__
    is_alert_ctx_initialized = MMI_TRUE;
    memset(alert_ctx_pool, 0, sizeof(alert_ctx_pool));

    LIST_INIT(alert_ctx_pool, mmi_alert_ctx_struct, &alert_ctx_pool_free_list);
    alert_ctx_pool_used_list.next = NULL;
#endif
}

/* allocate ctx */
static void *allocate_ctx()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_ctx_struct *ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_ALERT_CTX_USE_LOCAL_BUFFER__
    if (!is_alert_ctx_initialized)
        mmi_alert_ctx_init();

    MMI_ASSERT(alert_ctx_pool_free_list.next != NULL);
    ptr = LIST_GET(&alert_ctx_pool_free_list, &alert_ctx_pool_used_list);
    LIST_RESET_ITEM(ptr, mmi_alert_ctx_struct);
#else
    ptr = mmi_malloc(sizeof(mmi_alert_ctx_struct));
    memset(ptr, 0, sizeof(*ptr));
#endif

    MMI_ASSERT(ptr);
    return ptr;
}

/* free ctx */
static void free_ctx(void *ctx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ctx)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM,MMI_POPUP_TRC_FREE_CTX,ctx);
#ifdef __MMI_ALERT_CTX_USE_LOCAL_BUFFER__
        LIST_FREE(ctx, &alert_ctx_pool_free_list, &alert_ctx_pool_used_list);
#else
        mmi_mfree(ctx);
#endif
    }
}

/* free alert ctx interface for event trigger */
static void free_alert_ctx(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    free_ctx(evt->user_data);
}

static void alert_set_global_ctx(mmi_alert_ctx_struct *ctx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    alert_ctx_p = ctx;
}

static void alert_reset_global_ctx(mmi_alert_ctx_struct *ctx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (alert_ctx_p == ctx) /* only reset global ctx when it's same as given */
    alert_ctx_p = NULL;
}

static mmi_alert_ctx_struct *alert_get_global_ctx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return alert_ctx_p;
}


static mmi_ret alert_scrn_post_close(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_ctx_struct *ctx = (mmi_alert_ctx_struct *)(evt->user_data);
    MMI_ID alert_id = ctx->alert_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM,MMI_POPUP_TRC_CLOSE_SCREEN,ctx,alert_id);
    mmi_frm_scrn_close(alert_id, alert_id);
	free_ctx(ctx);
    return MMI_RET_OK;
}


// for debug
//extern void print_event(PU8 str_prefix, mmi_event_struct *evt);


static mmi_ret alert_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_ctx_struct *ctx = (mmi_alert_ctx_struct *)evt->user_data;
    MMI_ID alert_id;
    mmi_alert_type_enum alert_type = ctx->type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //print_event((PU8)"alert_proc", (mmi_event_struct *)evt);

    if (ctx == NULL)
    {
        // TODO: add trace here
        return MMI_RET_OK;
    }

    alert_id = ctx->alert_id;

    switch (evt->evt_id)
    {
    case EVT_ID_GROUP_INACTIVE:
        /* close group by self. this is to cover scenario malfunction, may be removed when scenario is ready */
        if (mmi_frm_scrn_get_count(alert_id) == 0)
            mmi_frm_group_close(alert_id);
        break;

    case EVT_ID_GROUP_DEINIT:
        if (!((alert_type == MMI_ALERT_TYPE_POPUP) && ctx->sub.popup.arg.f_auto_dismiss) && 
        !((alert_type == MMI_ALERT_TYPE_CONFIRM) && ctx->sub.confirm.arg.f_auto_dismiss))
            free_ctx(ctx);
        mmi_frm_group_set_proc_data(alert_id, alert_proc, NULL);
        break;

    case EVT_ID_GROUP_GOBACK_IN_END_KEY:
    case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
        {
			alert_event(evt->evt_id, MMI_POPUP_INTERRUPT_EXIT, ctx, 'send');
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            /* also notify confirm for cancel */
            if ((ctx->type == MMI_ALERT_TYPE_CONFIRM) && (ctx->sub.confirm.is_normal_exit_event_sent == MMI_FALSE))
                alert_finish(ctx, MMI_ALERT_CNFM_CANCEL);
        }
    }

    return MMI_RET_OK;
}


static mmi_ret alert_scrn_leave_proc(mmi_scenario_evt_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_ctx_struct *ctx = (mmi_alert_ctx_struct *)info->user_data;
    MMI_BOOL enterHistory = MMI_FALSE;
    mmi_alert_type_enum alert_type = ctx->type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //print_event((PU8)"scrn_leave_proc", (mmi_event_struct *)info);

    switch (ctx->type)
    {
    case MMI_ALERT_TYPE_POPUP:
        {
            StopTimer(POPUP_TIMER);
            enterHistory = MMI_FALSE;
        }
        break;

    case MMI_ALERT_TYPE_CONFIRM:
        {
            mmi_confirm_ctx_struct *confirm = &ctx->sub.confirm;

            enterHistory = (MMI_BOOL)confirm->arg.f_enter_history;
#ifndef __MMI_WGUI_DISABLE_CSK__
            if (info->state & MMI_SCENARIO_STATE_INACTIVE)
            {
                ResetCenterSoftkey();
            }
#endif			
			
        }
        break;

    default:
        MMI_ASSERT(0);  /* wrong alert type */
        break;
    }

    /* do not enter history and exit by interrupt */
    if (info->evt_id == EVT_ID_SCRN_DEINIT)
    {
        /* if inerrupt event come, send exit screen event to caller*/
        //MMI_TRACE(MMI_FW_TRC_G2_GUI,MMI_POPUP_TRC_POST_EVENT);
		if ((ctx->type == MMI_ALERT_TYPE_CONFIRM)&&( ctx->sub.confirm.is_normal_exit_event_sent == MMI_TRUE))
		{
			alert_tx_quit_event('post', ctx, MMI_ALERT_NORMAL_EXIT);
		}
		else
		{
            alert_tx_quit_event('post', ctx, MMI_ALERT_INTERRUPT_EXIT);
		}
        if (((alert_type == MMI_ALERT_TYPE_POPUP) && ctx->sub.popup.arg.f_auto_dismiss) || 
        ((alert_type == MMI_ALERT_TYPE_CONFIRM) && ctx->sub.confirm.arg.f_auto_dismiss))
        {
		    if (ctx->type == MMI_ALERT_TYPE_POPUP)
		    {
			    if( ctx->sub.popup.is_normal_exit_event_sent == MMI_FALSE)
			    {
				    post_invoke((mmi_proc_func)free_alert_ctx, ctx);
			    }
		    }
		    if((ctx->type == MMI_ALERT_TYPE_CONFIRM)&& !enterHistory)
		    {
		        if( ctx->sub.confirm.is_normal_exit_event_sent == MMI_FALSE)
                {      
			        post_invoke((mmi_proc_func)free_alert_ctx, ctx);
                }
		    }
        }
    }

    alert_reset_global_ctx(ctx);

    if (ctx->tone_id)
    {
        srv_profiles_stop_tone(ctx->tone_id);
        ctx->tone_id = SRV_PROF_TONE_NONE;//0;
    }

    return MMI_RET_OK;
}



static void alert_finish(mmi_alert_ctx_struct *ctx, mmi_alert_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_type_enum alert_type = ctx->type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (alert_type)
    {
    case MMI_ALERT_TYPE_POPUP:
        StopTimer(POPUP_TIMER);
        SetGroupKeyHandler(UI_dummy_function, (PU16) PresentAllKeys, TOTAL_KEYS, KEY_EVENT_DOWN);    
        break;
	case MMI_ALERT_TYPE_CONFIRM:
		ctx->sub.confirm.is_normal_exit_event_sent = MMI_TRUE;
		break;
    }
    alert_reset_global_ctx(ctx);

    if (result < MMI_ALERT_END)
        alert_tx_quit_event('send', ctx, result);

    if (((alert_type == MMI_ALERT_TYPE_POPUP) && ctx->sub.popup.arg.f_auto_dismiss) || 
        ((alert_type == MMI_ALERT_TYPE_CONFIRM) && ctx->sub.confirm.arg.f_auto_dismiss))
        post_invoke(alert_scrn_post_close, (void *)ctx);
}

static mmi_ret alert_tx_event(U32 tx_type, mmi_proc_func callback, mmi_event_struct *evt, mmi_alert_ctx_struct *ctx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret= MMI_RET_OK;
    //mmi_alert_result_evt_struct *event = (mmi_alert_result_evt_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (callback)
    {
        if (tx_type == 'send')
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM,MMI_POPUP_TRC_INVOKE_CALLBACK, ctx, ((mmi_alert_result_evt_struct*)evt)->result, ((mmi_alert_result_evt_struct*)evt)->user_tag, callback, 0);
            ret = mmi_frm_send_event(evt, callback, NULL);
        }
        else // 'post'
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM,MMI_POPUP_TRC_INVOKE_CALLBACK, ctx, ((mmi_alert_result_evt_struct*)evt)->result, ((mmi_alert_result_evt_struct*)evt)->user_tag, callback, 1);
            mmi_frm_post_event(evt, callback, NULL);
        }
      
      
        MMI_TRACE(MMI_FW_TRC_G1_FRM,MMI_POPUP_TRC_INVOKE_CALLBACK_DONE, ctx, ((mmi_alert_result_evt_struct*)evt)->result, callback);
        return ret;
    }
    /* if callback not exists, send result to parent proc */
    else 
    {
        mmi_group_node_struct parent_node;
		MMI_ID parent_id;

		if(ctx->type == MMI_ALERT_TYPE_CONFIRM)
		{
			parent_id = ctx->sub.confirm.arg.parent_id;
		}
		else if(ctx->type == MMI_ALERT_TYPE_POPUP)
		{
			parent_id = ctx->sub.popup.arg.parent_id;
		}
		else
		{
			parent_id = 0;
		}
        /* get parent info */
		if ((GRP_ID_INVALID != parent_id) && (GRP_ID_ROOT != parent_id))
        {
			if (mmi_frm_group_get_info(parent_id, &parent_node) == MMI_RET_OK)
            {
                if (tx_type == 'send')
                {
                    MMI_TRACE(MMI_FW_TRC_G1_FRM,MMI_POPUP_TRC_INVOKE_PARENT, ctx, ((mmi_alert_result_evt_struct*)evt)->result, ((mmi_alert_result_evt_struct*)evt)->user_tag,parent_id, 0);
                    ret = mmi_frm_send_event(evt, parent_node.proc, parent_node.user_data);
                    
                }
                else
                {
                    MMI_TRACE(MMI_FW_TRC_G1_FRM,MMI_POPUP_TRC_INVOKE_PARENT, ctx, ((mmi_alert_result_evt_struct*)evt)->result, ((mmi_alert_result_evt_struct*)evt)->user_tag, parent_id, 1);
                    mmi_frm_post_event(evt, parent_node.proc, parent_node.user_data);

                }
                MMI_TRACE(MMI_FW_TRC_G1_FRM,MMI_POPUP_TRC_INVOKE_PARENT_DONE, ctx, ((mmi_alert_result_evt_struct*)evt)->result, parent_id);
                return ret;
            }
        }
    }
 
    return ret;
}


static mmi_proc_func get_callback(mmi_alert_ctx_struct *ctx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ctx->type == MMI_ALERT_TYPE_POPUP)
        return ctx->sub.popup.arg.callback;
    else
        return ctx->sub.confirm.arg.callback;
}

static void *get_user_tag(mmi_alert_ctx_struct *ctx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ctx->type == MMI_ALERT_TYPE_POPUP)
        return ctx->sub.popup.arg.user_tag;
    else
        return ctx->sub.confirm.arg.user_tag;
}

static void alert_tx_quit_event(U32 tx_type, mmi_alert_ctx_struct *ctx, mmi_alert_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   // mmi_alert_result_evt_struct evt;
    //mmi_proc_func callback;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if (ctx->type == MMI_ALERT_TYPE_POPUP)
    {
        switch (result)
        {
        case MMI_ALERT_NORMAL_EXIT:
                ctx->sub.popup.is_normal_exit_event_sent = MMI_TRUE;
            break;

        case MMI_ALERT_INTERRUPT_EXIT:
            if (ctx->sub.popup.is_normal_exit_event_sent)
                return;
            break;
        }
    }
    if (ctx->type == MMI_ALERT_TYPE_CONFIRM)
    {
        switch (result)
        {
        case MMI_ALERT_NORMAL_EXIT:
                ctx->sub.confirm.is_normal_exit_event_sent = MMI_TRUE;
            break;

        case MMI_ALERT_INTERRUPT_EXIT:
            if (ctx->sub.confirm.is_normal_exit_event_sent)
                return;
            break;
        }
    }

   //
   alert_event(EVT_ID_ALERT_QUIT, result, ctx, tx_type);
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
}
static void alert_event(U16 evt_id, mmi_alert_result_enum result, 
	mmi_alert_ctx_struct *ctx, U32 tx_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
	MMI_FRM_INIT_EVENT(&evt, evt_id);
    evt.alert_id    = ctx->alert_id;
    evt.result      = result;
    evt.user_tag    = get_user_tag(ctx);
 
    alert_tx_event(tx_type, get_callback(ctx), (mmi_event_struct *)&evt, ctx);  

}
static void alert_tx_enter_event(mmi_alert_ctx_struct *ctx)
{
   alert_event(EVT_ID_ALERT_ENTER, MMI_ALERT_END, ctx, 'post');
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}
static void post_invoke(mmi_proc_func proc, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, 0);
    mmi_frm_post_event(&evt, proc, user_data);
}


static mmi_ret show_alert(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_ctx_struct *ctx = (mmi_alert_ctx_struct *)evt->user_data;
    MMI_ID alert_id = ctx->alert_id;
    MMI_ID parent_id;
 
    FuncPtr scrn_entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(ctx->type)
    {
    case MMI_ALERT_TYPE_POPUP:
        scrn_entry = (FuncPtr)popup_entry;
        parent_id = ctx->sub.popup.arg.parent_id;
        break;

    case MMI_ALERT_TYPE_CONFIRM:
        scrn_entry = (FuncPtr)confirm_entry;
        parent_id = ctx->sub.confirm.arg.parent_id;
        break;

    default:
        MMI_ASSERT(0); /* wrong type */
        return MMI_RET_OK;
    }
    mmi_frm_group_create(parent_id, alert_id, alert_proc, ctx);
    /* enter group */
    mmi_frm_group_enter(alert_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);   /* we close screen and let group close itself */

    /* enter screen */
    mmi_frm_scrn_first_enter(alert_id, alert_id, scrn_entry, ctx);

    /* set screen leave proc */
    mmi_frm_scrn_set_leave_proc(alert_id, alert_id, (mmi_proc_func)alert_scrn_leave_proc);
    return MMI_RET_OK;
}


/*****************************************************************************
 * Popup
 *****************************************************************************/ 


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  popup_pen_down_hdlr
 * DESCRIPTION
 *  pen down handler
 * PARAMETERS
 *  point       [IN]        pen down position
 * RETURNS
 *  Is handled
 *****************************************************************************/
static MMI_BOOL popup_pen_down_hdlr(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    popup_keydown_handler();
    popup_general_key_hdlr();
    return MMI_TRUE;
}
#endif /* __MMI_TOUCH_SCREEN__ */

/*****************************************************************************
 * FUNCTION
 *  popup_timeout_hdlr
 * DESCRIPTION
 *  Stops the timer and Call Callback function after pop-up timer over
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void popup_timeout_hdlr(void* arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_ctx_struct *ctx = (mmi_alert_ctx_struct *)arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!ctx)
        return;

    if(ctx->sub.popup.timer_longer_than_tone)
    {
        alert_finish(ctx, MMI_ALERT_NORMAL_EXIT);
    }
    else
    {
        ctx->sub.popup.timer_longer_than_tone = MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  popup_keydown_handler
 * DESCRIPTION
 *  turn on popup keydown flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void popup_keydown_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_ctx_struct *ctx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ctx = alert_get_global_ctx();
    if (!ctx)
        return;

    MMI_ASSERT(ctx->type == MMI_ALERT_TYPE_POPUP);
    ctx->sub.popup.popup_keydown_flag = MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  popup_general_key_hdlr
 * DESCRIPTION
 *  Stops the timer and goes back if users press any key.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void popup_general_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_ctx_struct *ctx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ctx = alert_get_global_ctx();
    if (!ctx)
        return;

    MMI_ASSERT(ctx->type == MMI_ALERT_TYPE_POPUP);
    if (ctx->sub.popup.popup_keydown_flag == MMI_TRUE)
    {
        ctx->sub.popup.popup_keydown_flag = MMI_FALSE;
        alert_finish(ctx, MMI_ALERT_NORMAL_EXIT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  popup_tone_end_hdlr
 * DESCRIPTION
 *  callback when tone is finished
 * PARAMETERS
 *  result  [IN]    reserved
 * RETURNS
 *  void
 *****************************************************************************/
static void popup_tone_end_hdlr(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_ctx_struct *ctx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ctx = alert_get_global_ctx();
    if (!ctx)
        return;

    MMI_ASSERT(ctx->type == MMI_ALERT_TYPE_POPUP);
    popup_timeout_hdlr(ctx);
}

static mmi_ret mmi_popup_key_proc(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;
    U8 key_code = key_evt->key_code;
    U8 key_type = key_evt->key_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (key_evt->evt_id == EVT_ID_ON_KEY)
	{
		if (key_code == KEY_END)
			return MMI_RET_OK;
		if(key_type == KEY_EVENT_DOWN)
			popup_keydown_handler();
		if(key_type == KEY_EVENT_UP)
			popup_general_key_hdlr();
	}
	return MMI_RET_OK;  
	
}

static mmi_ret popup_entry(mmi_scrn_essential_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 image_id = 0;
    U32 duration;
    srv_prof_tone_enum tone_id = NONE_TONE;
    //FuncPtr endKeyDownFuncPtr = NULL, endKeyUpFuncPtr = NULL;
    mmi_alert_ctx_struct *ctx = (mmi_alert_ctx_struct *)info->user_data;
    mmi_popup_ctx_struct *popup = &ctx->sub.popup;

	//bwl_dbg_print("popup_entry \r\n");
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_frm_scrn_enter(ctx->alert_id, ctx->alert_id, NULL, (FuncPtr)popup_entry, MMI_FRM_UNKNOW_SCRN))
    {
		// Post enter event to caller
		alert_tx_enter_event(ctx);

        srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
        mmi_frm_scrn_clear_attribute(ctx->alert_id, ctx->alert_id, MMI_SCRN_ATTRIB_ADD_HISTORY);    /* do not add popup to history */

    #ifdef __MMI_SCREEN_ROTATE__
        mmi_frm_screen_rotate(popup->arg.rotation);
    #endif
        /* Becasue alert will not be added into history, it will not set small screen flag */
        //force_no_small_screen();

        if(!(popup->arg.f_sliding_effect))
        {
    #ifdef __MMI_SCREEN_SWITCH_EFFECT__
            gui_screen_switch_effect_block(MMI_TRUE);
    #endif
        }

        if (popup->arg.f_msg_icon)
        {
            image_id = popup->arg.msg_icon ? popup->arg.msg_icon : mmi_get_event_based_image(ctx->event_type);
        }
        if (popup->arg.f_play_tone)
        {
            tone_id = popup->arg.tone_id ? popup->arg.tone_id : mmi_get_event_based_sound(ctx->event_type);
        }
        duration = popup->arg.duration ? popup->arg.duration : mmi_get_event_based_duration(ctx->event_type);

        /* set global ctx for key handler */
        alert_set_global_ctx(ctx);
        MMI_TRACE(MMI_FW_TRC_G1_FRM,MMI_POPUP_TRC_SHOW_SCREEN,ctx, ctx->alert_id);

        /* display */
        ShowCategory63Screen((U8*)ctx->title, image_id, NULL);

        /* pen and key handler */
    #ifdef __MMI_TOUCH_SCREEN__
        wgui_cat63_register_pen_down_handler(popup_pen_down_hdlr);
    #endif
		mmi_frm_scrn_set_key_proc(ctx->alert_id, ctx->alert_id,mmi_popup_key_proc);
        /* timer */
        StartTimerEx(POPUP_TIMER, duration, popup_timeout_hdlr, ctx);

        /* tone */
        /* popup rule: popup duration will extend to tone duration if tone duration is larger than popup duration */
        ctx->tone_id = tone_id;
        if(SRV_PROF_RET_SUCCESS != srv_prof_play_tone(tone_id, (srv_prof_play_tone_callback)popup_tone_end_hdlr))
        {
            popup->timer_longer_than_tone = MMI_TRUE; /* timer is longer than tone period, so can only handle popup timer */
        }
    }
    return MMI_RET_OK;
}
#if !defined(__MMI_ALERT_CTX_USE_LOCAL_BUFFER__)
static U8 g_alert_screen_count;
#endif
static MMI_ID mmi_alert_get_screen_id(mmi_alert_ctx_struct *ctx)
{
#ifdef __MMI_ALERT_CTX_USE_LOCAL_BUFFER__
    MMI_ID g0 = SCR_ID_ALERT_0;
    MMI_ID g9 = SCR_ID_ALERT_9;
    U32 buf = (U32) alert_ctx_pool;
    U32 curr_buf;
    U32 buf_size;
    U32 index = 0;

    MMI_ASSERT(ctx);
    MMI_ASSERT((g9-g0 + 1)>=MMI_ALERT_POOL_SIZE);
    
    curr_buf = (U32) ctx;
    buf_size = sizeof(mmi_alert_ctx_struct);
    index = (curr_buf - buf) / buf_size;

    return g0 + index;   
#else
    MMI_ID g0 = SCR_ID_ALERT_0;
    MMI_ID g9 = SCR_ID_ALERT_9;
    if(g_alert_screen_count > 10)
        g_alert_screen_count = 0;
    return g0+g_alert_screen_count++;
#endif
}

MMI_ID mmi_popup_display_simple_ext(
            MMI_STR_ID title, 
            mmi_event_notify_enum event_type, 
            MMI_ID parent_id,
            void * user_tag)
{
	return mmi_popup_display_simple(
				(WCHAR*)GetString(title),
				event_type,
				parent_id,
				user_tag);
}

MMI_ID mmi_popup_display_simple(
            WCHAR* title, 
            mmi_event_notify_enum event_type, 
            MMI_ID parent_id,
            void * user_tag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_property_init(&arg);
    arg.parent_id   = parent_id;
    arg.user_tag    = user_tag;

    return mmi_popup_display(title, event_type, &arg);
}

MMI_ID mmi_popup_display_ext( 
            MMI_STR_ID title, 
        	mmi_event_notify_enum event_type, 
        	mmi_popup_property_struct *arg)
{
	return mmi_popup_display(
				(WCHAR*)GetString(title),
				event_type,
				arg);
}

static void get_alert_display_title(WCHAR* src_title, WCHAR* dest_title)
{
   S32 title_number;

   
   	mmi_wcsncpy(dest_title, src_title, MMI_ALERT_TITLE_CHARACTER_MAX);
	title_number = mmi_wcslen(src_title);
	if(title_number > MMI_ALERT_TITLE_CHARACTER_MAX)
		mmi_wcscat(dest_title, (WCHAR*) L"...");

}
MMI_ID mmi_popup_display( 
            WCHAR* title, 
        	mmi_event_notify_enum event_type, 
        	mmi_popup_property_struct *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID alert_id = GRP_ID_INVALID, parent_id;
    mmi_group_node_struct node;
    mmi_event_struct evt = {0};
    mmi_alert_ctx_struct *ctx;
	//S32 title_number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* allocate and initialize context struct */
    ctx = allocate_ctx();
    ctx->type = MMI_ALERT_TYPE_POPUP;
    MMI_TRACE(MMI_FW_TRC_G1_FRM,MMI_POPUP_TRC_ALLOC_CTX,ctx,ctx->type);
    if (NULL != arg)
    {
        ctx->sub.popup.arg   = *arg;
        MMI_TRACE(MMI_FW_TRC_G1_FRM,MMI_POPUP_TRC_ARG,arg->parent_id,arg->f_auto_dismiss,0);
    }
    else
    {
        mmi_popup_property_init(&ctx->sub.popup.arg);
    }

    ctx->event_type  = event_type;
	get_alert_display_title(title, ctx->title);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    parent_id = ctx->sub.popup.arg.parent_id;

    /* if parent group is inactive, do not show popup, just return */
    if ((parent_id != GRP_ID_ROOT) && 
        ((MMI_RET_OK != mmi_frm_group_get_info(parent_id, &node)) ||
            !(node.state & MMI_SCENARIO_STATE_ACTIVE)))
    {
        alert_tx_quit_event('post', ctx, MMI_ALERT_NO_SHOW);
        post_invoke((mmi_proc_func)free_alert_ctx, ctx);   /* no group to handle ctx, so should free ctx here */
        return alert_id;    /* GRP_ID_INVALID */
    }

    /* always create group to contain popup screen */
    alert_id = mmi_alert_get_screen_id(ctx);
    ctx->alert_id = alert_id;
    
    /* for showing global alert in goback process, we'll post to show it */
    if ((mmi_frm_is_in_deinit_scenario() || mmi_frm_shell_is_in_backward_scenario()) && parent_id == GRP_ID_ROOT)
    {
        post_invoke(show_alert, ctx);
        MMI_TRACE(MMI_FW_TRC_G1_FRM,MMI_POPUP_TRC_POST_SHOW,ctx);
        return alert_id;
    }
   
    evt.user_data = ctx;
    show_alert(&evt);
    return alert_id;
}


/*****************************************************************************
 * Confirm
 *****************************************************************************/ 

static void confirm_sk1_hdlr(void)
{
  confirm_sk_hdlr(MMI_ALERT_CNFM_1);
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
}


static void confirm_sk2_hdlr(void)
{
    confirm_sk_hdlr(MMI_ALERT_CNFM_2);
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
}


static void confirm_sk3_hdlr(void)
{
  confirm_sk_hdlr(MMI_ALERT_CNFM_3);
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
}

static void confirm_sk_hdlr(mmi_alert_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_ctx_struct *ctx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    ctx = alert_get_global_ctx();
    if (!ctx)
        return;

    alert_finish(ctx, result);
    if(!(ctx->sub.confirm.arg.f_auto_dismiss) && ctx->sub.confirm.arg.f_enter_history)
    {
        post_invoke(alert_scrn_post_close, (void *)ctx);
        ctx->sub.confirm.arg.f_auto_dismiss = MMI_TRUE;
    }


}
static void confirm_sk_ok_hdlr(void)
{
   confirm_sk_hdlr(MMI_ALERT_CNFM_OK);
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
}

static void confirm_sk_yes_hdlr(void)
{
    confirm_sk_hdlr(MMI_ALERT_CNFM_YES);
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
}

static void confirm_sk_no_hdlr(void)
{
   confirm_sk_hdlr(MMI_ALERT_CNFM_NO);
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
}

static void confirm_sk_cancel_hdlr(void)
{
  	confirm_sk_hdlr(MMI_ALERT_CNFM_CANCEL);
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
}


static const mmi_confirm_sk_mapping_struct *get_confirm_sk_mapping(mmi_confirm_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, i_max = sizeof(mmi_confirm_sk_mapping)/sizeof(mmi_confirm_sk_mapping_struct);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i=0; i<i_max; i++)
    {
        if (mmi_confirm_sk_mapping[i].ctype == type)
            return &mmi_confirm_sk_mapping[i];
    }
    return NULL;
}

static mmi_ret confirm_entry(mmi_scrn_essential_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 image_id = 0;
    srv_prof_tone_enum tone_id;
    const mmi_confirm_sk_mapping_struct *sk_mapping;
    FuncPtr sk_hdlr[MMI_CONFIRM_SOFTKEY_NUM];
    U32 i;

    mmi_alert_ctx_struct *ctx = (mmi_alert_ctx_struct *)info->user_data;
    mmi_confirm_ctx_struct *confirm = &ctx->sub.confirm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(ctx);

    if (mmi_frm_scrn_enter(ctx->alert_id, ctx->alert_id, NULL, (FuncPtr)confirm_entry, MMI_FRM_SMALL_SCRN))
    {       
        srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);//
		alert_tx_enter_event(ctx);
        /* do not add popup to history when related flag is set */
        if (!(confirm->arg.f_enter_history))
            mmi_frm_scrn_clear_attribute(ctx->alert_id, ctx->alert_id, MMI_SCRN_ATTRIB_ADD_HISTORY);

    #ifdef __MMI_SCREEN_ROTATE__
        mmi_frm_screen_rotate(confirm->arg.rotation);
    #endif 

#ifndef __MMI_WGUI_DISABLE_CSK__
        if ((confirm->arg.softkey[1].str!= NULL) || (confirm->arg.softkey[1].img != NULL))
        {
            /* EnableCenterSoftkey uses ID only now. may replace by new API if created later */
            EnableCenterSoftkey(STRING_ID_NULL, IMAGE_ID_NULL);
            if (confirm->arg.softkey[1].str != NULL)
            set_softkey_label(confirm->arg.softkey[1].str, MMI_CENTER_SOFTKEY);
            else if (confirm->arg.softkey[1].img != NULL)
            set_softkey_icon((PU8)confirm->arg.softkey[1].img, MMI_CENTER_SOFTKEY);
        }
#endif
        if(!(confirm->arg.f_sliding_effect))
        {
    #ifdef __MMI_SCREEN_SWITCH_EFFECT__
            gui_screen_switch_effect_block(MMI_TRUE);
    #endif
        }
    
        if(confirm->arg.f_msg_icon)
        {
            image_id = confirm->arg.msg_icon ? confirm->arg.msg_icon : mmi_get_event_based_image(ctx->event_type);
        }
        tone_id = confirm->arg.tone_id ? confirm->arg.tone_id : mmi_get_event_based_sound(ctx->event_type);

        /* set global ctx for key handler */
        alert_set_global_ctx(ctx);
        MMI_TRACE(MMI_FW_TRC_G1_FRM,MMI_POPUP_TRC_SHOW_SCREEN,ctx, ctx->alert_id);
        ShowCategory163Screen(
                confirm->arg.softkey[0].str, 
                (PU8)confirm->arg.softkey[0].img, 
                confirm->arg.softkey[2].str, 
                (PU8)confirm->arg.softkey[2].img, 
                ctx->title, 
                image_id, 
                NULL);
        ctx->tone_id = tone_id;
        if (ctx->tone_id)
            srv_prof_play_tone(ctx->tone_id, NULL);

        /* regeister softkeys */
        if ((sk_mapping = get_confirm_sk_mapping(confirm->arg.ctype)) != NULL)
        {
            for (i=0; i<MMI_CONFIRM_SOFTKEY_NUM; i++)
                sk_hdlr[i] = sk_mapping->sk_info[i].hdlr;

            /* handle f_auto_map_empty_softkey for CSK key rule */
            if (ctx->sub.confirm.arg.f_auto_map_empty_softkey && (MMI_CONFIRM_SOFTKEY_NUM >= 3) &&
                (sk_hdlr[0] != NULL) && (sk_hdlr[1] == NULL))
            {
                sk_hdlr[1] = sk_hdlr[0];
            }
        }
        /* use default handlers for user define type */
        else
        {
            for (i=0; i<MMI_CONFIRM_SOFTKEY_NUM; i++)
                sk_hdlr[i] = default_sk_hdlr_tbl[i];
        }

        for (i=0; i<MMI_CONFIRM_SOFTKEY_NUM; i++)
        {
            /* only set handler when str or img is set */
            if ((1==i)||confirm->arg.softkey[i].str || confirm->arg.softkey[i].img)
            (set_softkey_func_tbl[i])(sk_hdlr[i], KEY_EVENT_UP);
        }
    }

    return MMI_RET_OK;
}

MMI_ID mmi_confirm_display_ext(
        	MMI_STR_ID title, 
        	mmi_event_notify_enum event_type, 
        	mmi_confirm_property_struct *arg)
{
	return mmi_confirm_display(
			(WCHAR*)GetString(title),
			event_type,
			arg);
}

MMI_ID mmi_confirm_display(
        	WCHAR* title, 
        	mmi_event_notify_enum event_type, 
        	mmi_confirm_property_struct *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_group_node_struct node;
    mmi_alert_ctx_struct *ctx;
    MMI_ID alert_id = GRP_ID_INVALID, parent_id;
    mmi_event_struct evt = {0};
//	S32 title_number = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* get context */
    ctx = allocate_ctx();
    ctx->type = MMI_ALERT_TYPE_CONFIRM;
    MMI_TRACE(MMI_FW_TRC_G1_FRM,MMI_POPUP_TRC_ALLOC_CTX,ctx,ctx->type);
    /* initialize context struct */
    if (arg != NULL)
    {
		if(arg->f_enter_history)
			arg->f_auto_dismiss = 0;
        ctx->sub.confirm.arg   = *arg;
        MMI_TRACE(MMI_FW_TRC_G1_FRM,MMI_POPUP_TRC_ARG,arg->parent_id,arg->f_auto_dismiss,arg->f_enter_history);
    }
    else
    {
        mmi_confirm_property_init(&ctx->sub.confirm.arg, CNFM_TYPE_OK);
    }

    /* handle f_auto_map_empty_softkey for CSK key rule */
    if (ctx->sub.confirm.arg.f_auto_map_empty_softkey && (MMI_CONFIRM_SOFTKEY_NUM >= 3) &&
        ((ctx->sub.confirm.arg.softkey[0].str != NULL) || (ctx->sub.confirm.arg.softkey[0].img != NULL)) &&
        ((ctx->sub.confirm.arg.softkey[1].str == NULL) || (ctx->sub.confirm.arg.softkey[1].img == NULL)))
    {
        ctx->sub.confirm.arg.softkey[1].img = (PS8)get_image(IMG_GLOBAL_COMMON_CSK);
    }

    ctx->event_type  = event_type;

	get_alert_display_title(title, ctx->title);
#if 0	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	if(ctx->sub.confirm.arg.f_auto_question_mark)
		mmi_wcscat(ctx->title, (WCHAR*)GetString(STR_ID_ALERT_QUESTION_MARK));

    parent_id = ctx->sub.confirm.arg.parent_id;

    /* just return if can't get parent group info */
    if ((parent_id != GRP_ID_ROOT) && 
        (MMI_RET_OK != mmi_frm_group_get_info(parent_id, &node)))
    {
        alert_tx_quit_event('post', ctx, MMI_ALERT_NO_SHOW);
        post_invoke((mmi_proc_func)free_alert_ctx, ctx);
        return alert_id;    /* GRP_ID_INVALID */
    }

    /* always create group to contain popup screen */
    alert_id = mmi_alert_get_screen_id(ctx);
    ctx->alert_id = alert_id;

    /* for showing global confirm in goback process, we'll post to show it */
    if ((mmi_frm_is_in_deinit_scenario() || mmi_frm_shell_is_in_backward_scenario()) && parent_id == GRP_ID_ROOT)
    {
        post_invoke(show_alert, ctx);
        MMI_TRACE(MMI_FW_TRC_G1_FRM,MMI_POPUP_TRC_POST_SHOW,ctx);
        return alert_id;
    }

    evt.user_data = ctx;
    show_alert(&evt);
    return alert_id;
}


/* dismiss an alert (popup or confirm) */
MMI_BOOL mmi_alert_dismiss(MMI_ID id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_ctx_struct *ctx = (mmi_alert_ctx_struct *)mmi_frm_group_get_user_data(id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ctx)
    {
        /* if auto_dismiss is reset, set it */
        switch (ctx->type)
        {
        case MMI_ALERT_TYPE_CONFIRM:
			if(ctx->sub.confirm.is_normal_exit_event_sent)
			{
				/* 
				 *  if in alert_finish, app call dismiss, but auto_dimiss is false
				 *  will next dismiss in the alert_finish
				 */
				if(ctx->sub.confirm.arg.f_auto_dismiss)
				{
					return MMI_FALSE;
				}
				else
				{
					ctx->sub.confirm.arg.f_auto_dismiss = MMI_TRUE;
					return MMI_FALSE;
				}
			}
            else
            {
                ctx->sub.confirm.arg.f_auto_dismiss = MMI_TRUE;
            }
            break;

        case MMI_ALERT_TYPE_POPUP:
            if((ctx->sub.popup.arg.f_auto_dismiss)&&(ctx->sub.popup.is_normal_exit_event_sent))
            {
                return MMI_FALSE;
            }
            else
            {
                ctx->sub.popup.arg.f_auto_dismiss = MMI_TRUE;
            }
            break;
        }
        MMI_TRACE(MMI_FW_TRC_G1_FRM,MMI_POPUP_TRC_DISMISS,ctx, ctx->alert_id);
        alert_finish(ctx, MMI_ALERT_END);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

void mmi_popup_property_init(mmi_popup_property_struct *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(arg, 0, sizeof(*arg));
    arg->parent_id          = GRP_ID_ROOT;
#ifdef __MMI_SCREEN_ROTATE__
    arg->rotation           = MMI_FRM_SCREEN_ROTATE_0;
#endif
    arg->f_msg_icon         = MMI_TRUE;
    arg->f_sliding_effect   = MMI_TRUE;
    arg->f_auto_dismiss     = MMI_TRUE;
    arg->f_play_tone        = MMI_TRUE;
}


void mmi_confirm_property_init(mmi_confirm_property_struct *arg, mmi_confirm_type_enum ctype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(arg, 0, sizeof(*arg));
    arg->parent_id          = GRP_ID_ROOT;  /* default to global one */
    arg->ctype              = ctype;
    arg->f_enter_history    = MMI_FALSE;
    arg->f_msg_icon         = MMI_TRUE;
    arg->f_sliding_effect   = MMI_TRUE;
    arg->f_auto_dismiss     = MMI_TRUE;
    arg->f_auto_map_empty_softkey = MMI_TRUE;   /* e.g. CSK map to LSK */
	arg->f_auto_question_mark = MMI_FALSE;

#ifdef __MMI_SCREEN_ROTATE__
    arg->rotation = MMI_FRM_SCREEN_ROTATE_0;
#endif
    if (ctype != CNFM_TYPE_USER_DEFINE)
    {
        const mmi_confirm_sk_mapping_struct *mapping;

        /* load default setting */
        if ((mapping = get_confirm_sk_mapping(ctype)) != NULL)
        {
            arg->softkey[0].str = (WCHAR *)get_string(mapping->sk_info[0].str_id);
            arg->softkey[0].img = (PS8)get_image(mapping->sk_info[0].img_id);
            arg->softkey[1].str = (WCHAR *)get_string(mapping->sk_info[1].str_id);
            arg->softkey[1].img = (PS8)get_image(mapping->sk_info[1].img_id);
            arg->softkey[2].str = (WCHAR *)get_string(mapping->sk_info[2].str_id);
            arg->softkey[2].img = (PS8)get_image(mapping->sk_info[2].img_id);
        }
    }
}


mmi_ret mmi_alert_normal_exit_helper(mmi_event_struct *evt)
{
    mmi_alert_result_evt_struct *alertEvt = (mmi_alert_result_evt_struct *)evt;

    if ((alertEvt->evt_id == EVT_ID_ALERT_QUIT) && 
        (alertEvt->result == MMI_ALERT_NORMAL_EXIT) && alertEvt->user_tag)
    {
        return ((mmi_proc_func)alertEvt->user_tag)(evt); // invoke callback
    }
    return MMI_RET_OK;
}


#ifdef __cplusplus
}
#endif 


