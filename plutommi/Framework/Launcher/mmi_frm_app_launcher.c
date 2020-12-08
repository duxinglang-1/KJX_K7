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
 *    mmi_frm_app_launcher.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is used for pluto launcher
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/
#include "mmi_frm_app_launcher_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"
#include "Wgui_categories.h"
#include "fix_size_mem.h"
#include "CustDataRes.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_history.h"
/***************************************************************************** 
* Define
*****************************************************************************/

/* Macro to send application events */
#define SEND_APP_EVT(evt, cntx, evt_id)  emit_app_evt((mmi_app_evt_struct*)(evt), (cntx), (evt_id), MMI_FALSE)
#define POST_APP_EVT(evt, cntx, evt_id)  emit_app_evt((mmi_app_evt_struct*)(evt), (cntx), (evt_id), MMI_TRUE)

#define GET_CNTX(evt) ((mmi_frm_app_launcher_struct *)((evt)->user_data))

/* Internal flag to record application state */
#define NORMAL_CLOSE  0x00000001   /* normal close  procedure */
#define BACK_HOME     0x00000002   /* close when mmi_idle_display */
#define ASM_CANCEL    0x00000004   /* close because ASM cancel */
#define INSERT_GROUP  0x00000008   /* need mmi_frm_group_insert */
#define ACTIVED       0x00000010   /* has been received EVT_ID_APP_ACTIVE or not */
#define SKIP_CHECK    0x00000020   /* need to send EVT_ID_APP_CLOSE_REQ or not */
#define FREE_ASM      0x00000040   /* close from OOM list */
#define TOP_ACTIVED   0x00000080   /* has been received EVT_ID_APP_TOP_ACTIVE or not */
/***************************************************************************** 
* Typedef
*****************************************************************************/

/* app launcher context struct */
typedef struct
{
    MMI_ID app_id;         /* Applicaton ID*/
    MMI_ID caller_id;      /* Caller ID */
    MMI_ID base_id;        /* Base ID to launch */
    mmi_proc_func proc;    /* The proc to receive app related event */
    void *user_data;       /* The user data related to this app */
    U32 option;            /* launch option */
    U32 flag_int;          /* Internal flag of an application */
} mmi_frm_app_launcher_struct;

/***************************************************************************** 
* Declaration of Local Functions
*****************************************************************************/
static void init_app_evt(mmi_app_evt_struct *evt, MMI_ID evt_id, MMI_ID app_id, MMI_ID caller_id);
static MMI_RET send_app_evt(mmi_app_evt_struct *evt, mmi_frm_app_launcher_struct *cntx, MMI_ID evt_id);
static void app_launcher_entry_dummy_screen(void);
static void app_launcher_close_dummy_screen(void);
static MMI_RET app_launcher_proc(mmi_event_struct *evt);
static U32 get_base_size(MMI_ID app_id);
static U32 get_heap_size(mmi_id app_id);
static U32 get_fg_size(mmi_id app_id);
static MMI_RET app_launcher_entry_proc(mmi_event_struct *evt);
static MMI_RET post_free_proc(mmi_event_struct *evt);
/***************************************************************************** 
* Local Functions
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  init_app_evt
 * DESCRIPTION
 *  This function is used to init an application event
 * PARAMETERS
 *  evt :         [OUT] The application event pointer
 *  evt_id:       [IN] The application event ID
 *  app_id:       [IN] The application ID
 *  caller_id:    [IN] The caller ID of this application
 * RETURN
 *  void
 *****************************************************************************/
static void init_app_evt(mmi_app_evt_struct *evt, MMI_ID evt_id, MMI_ID app_id, MMI_ID caller_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(evt, evt_id);
    evt->app_id = app_id;
    evt->caller_id = caller_id;
}


/*****************************************************************************
 * FUNCTION
 *  emit_app_evt
 * DESCRIPTION
 *  This function is used to emit the application event to the application proc function
 * PARAMETERS
 *  evt :         [OUT] The application event pointer
 *  cntx:         [IN] The context of this application
 *  evt_id:       [IN] The application event ID
 * RETURN
 *  The return value of the application after process this event in the proc function
 *****************************************************************************/
static MMI_RET emit_app_evt(mmi_app_evt_struct *evt, mmi_frm_app_launcher_struct *cntx, MMI_ID evt_id, MMI_BOOL is_post)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    init_app_evt(evt, evt_id, cntx->app_id, cntx->caller_id);
	if (is_post == MMI_FALSE)
	{
		return MMI_FRM_SEND_EVENT(evt, cntx->proc, cntx->user_data);
	}
	else
	{
		MMI_FRM_POST_EVENT(evt, cntx->proc, cntx->user_data);
		return MMI_RET_OK;
	}
}


/*****************************************************************************
 * FUNCTION
 *  app_launcher_entry_dummy_screen
 * DESCRIPTION
 *  This function is used to enter a dummy screen under ROOT
 * PARAMETERS
 *  void
 * RETURN
 *  void
 *****************************************************************************/
static void app_launcher_entry_dummy_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_frm_scrn_enter(GRP_ID_ROOT, SCR_ID_DUMMY, NULL, app_launcher_entry_dummy_screen, MMI_FRM_FULL_SCRN))
    {
        ShowCategoryDummyScreen();
        mmi_frm_scrn_clear_attribute(GRP_ID_ROOT, SCR_ID_DUMMY, MMI_SCRN_ATTRIB_ADD_HISTORY);
    }
}


/*****************************************************************************
 * FUNCTION
 *  app_launcher_close_dummy_screen
 * DESCRIPTION
 *  This function is used to close the dummy screen under ROOT
 * PARAMETERS
 *  void
 * RETURN
 *  void
 *****************************************************************************/
static void app_launcher_close_dummy_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(GRP_ID_ROOT, SCR_ID_DUMMY);
}


/*****************************************************************************
 * FUNCTION
 *  post_free_proc
 * DESCRIPTION
 *  This function is used to notify asm stop finished
 * PARAMETERS
 *  evt:  [IN]  event structure
 * RETURN
 *  MMI_RET_OK
 *****************************************************************************/
static MMI_RET post_free_proc(mmi_event_struct *evt)
{
	MMI_ID app_id = (MMI_ID)(0x0FFFF & ((U32)(evt->user_data)));
	applib_mem_ap_notify_stop_finished(app_id, KAL_TRUE);
	return MMI_RET_OK;
}

static MMI_RET process_close(mmi_frm_app_launcher_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_RET ret = MMI_RET_OK;
	mmi_app_evt_struct app_evt;
	MMI_RET answer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!(cntx->flag_int & SKIP_CHECK))
	{
		answer = SEND_APP_EVT(&app_evt, cntx, EVT_ID_APP_CLOSE_REQ);
		switch (answer)
		{
			case MMI_APP_CLOSE_ANSWER_NO:
			case MMI_APP_CLOSE_ANSWER_LATER:
			{
				if ((cntx->flag_int & BACK_HOME))
				{
					ret = MMI_RET_STOP_END_KEY_FLOW;
				}
				else
				{
					ret = MMI_RET_ERR;
				}
				break;
			}
			
			case MMI_APP_CLOSE_ANSWER_HIDE:
			{
				ret = MMI_RET_ERR;
				mmi_frm_app_set_hidden(cntx->app_id, MMI_TRUE, 0);
				break;
			}
		}
	}
	return ret;
}


/*****************************************************************************
 * FUNCTION
 *  app_launcher_proc
 * DESCRIPTION
 *  This function is used to handle screen group event of the launcher
 *
 * PARAMETERS
 *  evt:     [IN] screen group event
 * RETURN
 *  MMI_RET
 *****************************************************************************/
static MMI_RET app_launcher_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_RET ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
    #ifdef __MMI_FRM_HISTORY__
        case EVT_ID_DELETE_DANGLE_GROUP_REQ:
        {
            /* Keep the screen group when back to idle if it is only created */
            ret = MMI_RET_ERR;
            break;
        }
    #endif

		case EVT_ID_ASM_FORCE_FREE:
		{
			MMI_RET answer;
			mmi_frm_app_launcher_struct *cntx = GET_CNTX(evt);
			mmi_app_evt_struct app_evt;
			cntx->flag_int |= FREE_ASM;

			answer = SEND_APP_EVT(&app_evt, cntx, EVT_ID_APP_FORCE_CLOSE);
			switch (answer)
			{
				case MMI_APP_CLOSE_ANSWER_YES:
				{
					mmi_event_struct post_free_evt;
					MMI_FRM_INIT_EVENT(&post_free_evt, 0);
					MMI_FRM_POST_EVENT(&post_free_evt, post_free_proc, (void *)cntx->app_id);
					cntx->flag_int |= SKIP_CHECK;
					mmi_frm_group_close(cntx->app_id);
				}

				case MMI_APP_CLOSE_ANSWER_LATER:
				{
					return MMI_FRM_ASM_WAITING_TO_FREE;
				}

				default:
				{
					break;
				}
			}
			break;
		}
        
        case EVT_ID_ASM_CANCELED:
		{
            mmi_frm_app_launcher_struct *cntx = GET_CNTX(evt);
            
            /* set flag to indicate close reason */
			cntx->flag_int |= ASM_CANCEL;
            mmi_frm_group_close(cntx->app_id);
            app_launcher_close_dummy_screen();
			break;
		}
            
        case EVT_ID_ASM_PREPARED:
		{
            mmi_frm_app_launcher_struct *cntx = GET_CNTX(evt);
            mmi_group_enter_flag flag = MMI_FRM_NODE_NONE_FLAG;
 
            mmi_frm_group_enter(cntx->app_id, flag);            
            break;
		}

        case EVT_ID_GROUP_DEINIT:
		{
            mmi_frm_app_launcher_struct *cntx = GET_CNTX(evt);
            mmi_app_deinit_evt_struct app_evt;
            
            /* set deinit reason */
			if (cntx->flag_int & ASM_CANCEL)
			{
				app_evt.reason = MMI_APP_DEINIT_BY_ASM_CANCEL;
			}
			else if (cntx->flag_int & NORMAL_CLOSE)
			{
				app_evt.reason = MMI_APP_DEINIT_BY_CLOSE;
			}
			else if (cntx->flag_int & BACK_HOME)
			{
				app_evt.reason = MMI_APP_DEINIT_BY_BACK_HOME;
			}
			
			if ((cntx->flag_int & INSERT_GROUP) && (!(cntx->flag_int & ACTIVED)))
			{
				app_evt.reason = MMI_APP_DEINIT_INSERT_WITHOUT_ENTER;
			}
			
            SEND_APP_EVT(&app_evt, cntx, EVT_ID_APP_DEINIT);
            mmi_frm_free((void *)cntx);
            break;
		}
            
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
		{
            mmi_frm_app_launcher_struct *cntx = GET_CNTX(evt);
			
			/* Skip close check for insert but not entered case */
			if ((cntx->flag_int & INSERT_GROUP) && (!(cntx->flag_int & ACTIVED)))
			{
				break;
			}
			
			/* set close reason */
			cntx->flag_int |= NORMAL_CLOSE;

			ret = process_close(cntx);
			break;
		}
		
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
		{
            mmi_frm_app_launcher_struct *cntx = GET_CNTX(evt);
			
			/* Skip close check for insert but not entered case */
			if ((cntx->flag_int & INSERT_GROUP) && (!(cntx->flag_int & ACTIVED)))
			{
				break;
			}

            /* set close reason */
			cntx->flag_int |= BACK_HOME;
			
			ret = process_close(cntx);
			break;
		}

        case EVT_ID_GROUP_ENTER:
		{
			mmi_frm_app_launcher_struct *cntx = GET_CNTX(evt);
            mmi_app_evt_struct app_evt;
            
            SEND_APP_EVT(&app_evt, cntx, EVT_ID_APP_ENTER);
            POST_APP_EVT(&app_evt, cntx, EVT_ID_APP_POST_ENTER);
			break;
		}

        case EVT_ID_GROUP_HIDE:
		{
			mmi_frm_app_launcher_struct *cntx = GET_CNTX(evt);
            mmi_app_evt_struct app_evt;
            
            SEND_APP_EVT(&app_evt, cntx, EVT_ID_APP_HIDE);
			break;
		}

        case EVT_ID_GROUP_UNHIDE:
		{
			mmi_frm_app_launcher_struct *cntx = GET_CNTX(evt);
            mmi_app_evt_struct app_evt;
            
            SEND_APP_EVT(&app_evt, cntx, EVT_ID_APP_UNHIDE);
			POST_APP_EVT(&app_evt, cntx, EVT_ID_APP_POST_UNHIDE);
			break;
		}

        case EVT_ID_GROUP_ACTIVE:
		{
			mmi_frm_app_launcher_struct *cntx = GET_CNTX(evt);
            mmi_app_evt_struct app_evt;
            
            /* 
			 * comment code here, we may enable it in the future if some more apps use
			 * insert way to launch besides IDLE
             * use mmi_frm_group_insert and receiving EVT_ID_GROUP_ACTIVE first time
             * we send EVT_ID_APP_ENTER_WITH_MEM_READY first
             * 
			if ((cntx->flag_int & INSERT_GROUP) && (!(cntx->flag_int & ACTIVED)))
			{
				SEND_APP_EVT(&app_evt, cntx, EVT_ID_APP_ENTER_WITH_MEM_READY);
			}
			*/
			
            SEND_APP_EVT(&app_evt, cntx, EVT_ID_APP_ACTIVE);
            
            /* update state to indicate that application has receiving EVT_ID_GROUP_ACTIVE once at lease */
			cntx->flag_int |= ACTIVED;
			break;
		}

        case EVT_ID_GROUP_INACTIVE:
		{
			mmi_frm_app_launcher_struct *cntx = GET_CNTX(evt);
            mmi_app_evt_struct app_evt;
            
            SEND_APP_EVT(&app_evt, cntx, EVT_ID_APP_INACTIVE);
			break;
		}

        case EVT_ID_GROUP_FOCUSED:
		{
			mmi_frm_app_launcher_struct *cntx = GET_CNTX(evt);
            mmi_app_top_active_evt_struct app_evt;

			if (cntx->flag_int & TOP_ACTIVED)
			{
				app_evt.is_1st = MMI_FALSE;
				
			}
			else
			{
				cntx->flag_int |= TOP_ACTIVED;
				app_evt.is_1st = MMI_TRUE;
			}
            
            SEND_APP_EVT(&app_evt, cntx, EVT_ID_APP_TOP_ACTIVE);
			break;
		}

        case EVT_ID_GROUP_DEFOCUSED:
		{
			mmi_frm_app_launcher_struct *cntx = GET_CNTX(evt);
            mmi_app_evt_struct app_evt;
            
            SEND_APP_EVT(&app_evt, cntx, EVT_ID_APP_TOP_INACTIVE);
			break;
		}
		
		case EVT_ID_NO_CHILD_NOTIFY:
		{
			mmi_frm_app_launcher_struct *cntx = GET_CNTX(evt);
            mmi_app_evt_struct app_evt;
            MMI_RET answer;
            answer = SEND_APP_EVT(&app_evt, cntx, EVT_ID_APP_NO_CHILD);
            if (answer != MMI_APP_NO_CHILD_HANDLED_BY_APP)
            {
                cntx->flag_int |= SKIP_CHECK;
                mmi_frm_group_close(cntx->app_id);
            }
			break;
		}
		
    #ifdef __MMI_FTE_SUPPORT__
		case EVT_ID_GROUP_REDRAW_START:
		{
			mmi_frm_asm_property_struct p;
			mmi_frm_app_launcher_struct *cntx = GET_CNTX(evt);
			if (!(cntx->option & MMI_FRM_APP_SKIP_SIZE_CHECK))
			{
			    mmi_frm_asm_get_property(cntx->app_id, &p);
			    p.f_skip_size_checking = 1;
			    mmi_frm_asm_set_property(cntx->app_id, &p);
			}
			break;
		}

		case EVT_ID_GROUP_REDRAW_DONE:
		{
			mmi_frm_asm_property_struct p;
			mmi_frm_app_launcher_struct *cntx = GET_CNTX(evt);
			if (!(cntx->option & MMI_FRM_APP_SKIP_SIZE_CHECK))
			{
			    mmi_frm_asm_get_property(cntx->app_id, &p);
			    p.f_skip_size_checking = 0;
			    mmi_frm_asm_set_property(cntx->app_id, &p);
			}
		    break;
		}
	#endif
		    
		default:
		{
		    break;
		}
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  get_base_size
 * DESCRIPTION
 *  get base part size of the application
 * PARAMETERS
 *  app_id :         [IN] application ID
 * RETURN
 *  memory size of base part
 *****************************************************************************/
static U32 get_base_size(MMI_ID app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 base_size = mmi_res_get_app_base_mem_size(app_id);;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return base_size;
}


/*****************************************************************************
 * FUNCTION
 *  get_heap_size
 * DESCRIPTION
 *  get heap size of the application
 * PARAMETERS
 *  app_id :         [IN] application ID
 * RETURN
 *  memory size of the application heap
 *****************************************************************************/
static U32 get_heap_size(mmi_id app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 heap_size = mmi_res_get_app_heap_size(app_id);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!heap_size)
        heap_size = get_base_size(app_id);
#if defined(__MMI_USE_MMV2__)
    heap_size -= applib_mem_ap_slmm_get_shrunk_heap_size_by_ID(app_id);
#endif
    return heap_size;
}


/*****************************************************************************
 * FUNCTION
 *  get_fg_size
 * DESCRIPTION
 *  get foreground memory size of the application
 * PARAMETERS
 *  app_id :         [IN] application ID
 * RETURN
 *  memory size of the application foregrond
 *****************************************************************************/
static U32 get_fg_size(mmi_id app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 fg_size = mmi_res_get_app_fg_mem_size(app_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return fg_size;
}


/*****************************************************************************
 * FUNCTION
 *  app_launcher_entry_proc
 * DESCRIPTION
 *  get foreground memory size of the application
 * PARAMETERS
 *  app_id :         [IN] application ID
 * RETURN
 *  memory size of the application foregrond
 *****************************************************************************/
static MMI_RET app_launcher_entry_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_app_launcher_struct *cntx = (mmi_frm_app_launcher_struct *)evt->user_data;
    mmi_frm_asm_prepare_flag_type prepare_flags = MMI_FRM_ASM_F_NONE;
    U32 fg_size = get_fg_size(cntx->app_id);
    U32 base_size = get_base_size(cntx->app_id);
    U32 heap_size = get_heap_size(cntx->app_id);
    U32 size_to_check = base_size + fg_size;
#ifndef __128_64_SEG__
    mmi_frm_asm_property_struct p;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (MMI_FRM_APP_FORCE_PREPARE_MEM & cntx->option)
    {
        prepare_flags = MMI_FRM_ASM_F_FORCE_PREPARE;
    }
    
    //put dummy here to free fg memory of the previous application
    app_launcher_entry_dummy_screen();

	if ((MMI_FRM_APP_SKIP_SIZE_CHECK & cntx->option) &&
		(MMI_FRM_APP_SKIP_RESVERVE_CHECK & cntx->option))
	{
		size_to_check = size_to_check + GDI_ASM_MEM_SIZE;
	}

    if (MMI_FRM_APP_SKIP_PREPARE & cntx->option)
    {
        size_to_check = 0;
    }
    else
    {
    #ifndef __128_64_SEG__
	    mmi_frm_asm_get_property(cntx->app_id, &p);
	    p.f_prepare_w_reserve = 1;
	    mmi_frm_asm_set_property(cntx->app_id, &p);
    #endif
    }
    
	if (size_to_check > 0 &&
		(mmi_frm_asm_check_enough_with_subsize(cntx->app_id, size_to_check, size_to_check) == MMI_FALSE))
	{		
		//do prepare for apps who do the config in res file
		mmi_frm_asm_prepare_w_subsize(
			cntx->app_id,
			size_to_check,
			size_to_check,
			app_launcher_proc,
			(void *)cntx,
			prepare_flags);    
	}
	else
	{
		//send prepared directly for app who don't need ASM.
		mmi_event_struct tmp;
		MMI_FRM_INIT_EVENT(&tmp, EVT_ID_ASM_PREPARED);
		MMI_FRM_SEND_EVENT(&tmp, app_launcher_proc, (void *)cntx);
	}
    return MMI_RET_OK;
}

/***************************************************************************** 
* External Functions
*****************************************************************************/

MMI_ID mmi_frm_app_launch(MMI_ID app_id, MMI_ID caller_id, MMI_ID base_id, mmi_proc_func proc, void *user_data, U32 option)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_struct evt;
    mmi_frm_app_launcher_struct *cntx;
    mmi_app_evt_struct app;
	MMI_ID gid;
	mmi_frm_asm_property_struct p;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    MMI_ASSERT(proc != NULL);
    MMI_ASSERT(app_id !=0 );
	MMI_ASSERT(mmi_frm_group_is_present(app_id) == MMI_FALSE);
	MMI_ASSERT(mmi_frm_get_root_app(base_id) == base_id);
	
    cntx = (mmi_frm_app_launcher_struct *)mmi_frm_malloc(sizeof(mmi_frm_app_launcher_struct));

    gid = mmi_frm_group_create(GRP_ID_ROOT, app_id, app_launcher_proc, (void *)cntx);
    mmi_frm_group_set_caller(app_id, caller_id);

	cntx->app_id = app_id;
	cntx->base_id = base_id;
	cntx->caller_id = caller_id;
	cntx->option = option;
	cntx->proc = proc;
	cntx->user_data = user_data;
	cntx->flag_int = 0;
	
	mmi_frm_asm_get_property(app_id, &p);
	if (option & MMI_FRM_APP_SKIP_SIZE_CHECK)
	{
	    p.f_skip_size_checking = 1;
	}
	if (option & MMI_FRM_APP_SKIP_RESVERVE_CHECK)
	{
	    p.f_skip_reserve_checking = 1;
	}
	p.f_pluto_launcher = 1;
	mmi_frm_asm_set_property(app_id, &p);
    
    SEND_APP_EVT(&app, cntx, EVT_ID_APP_INIT);

	if ((option & MMI_FRM_APP_LAUNCH_AFTER_BASE) && (mmi_frm_app_get_active_id() != base_id) || (option & MMI_FRM_APP_LAUNCH_BEFORE_BASE))
	{
		MMI_RET ret;
		mmi_frm_node_struct group_info;
		mmi_scenario_node_flag  flag;
		flag = (option & (MMI_FRM_APP_LAUNCH_AFTER_BASE)) ? MMI_FRM_NODE_AFTER_FLAG : MMI_FRM_NODE_BEFORE_FLAG;
		group_info.id = gid;
		group_info.entry_proc = app_launcher_proc;
		group_info.user_data = (void *)cntx;
		ret = mmi_frm_group_insert(
				GRP_ID_ROOT,
				base_id,
				&group_info,
				flag);
		cntx->flag_int |= INSERT_GROUP;
    #ifndef __128_64_SEG__
	    mmi_frm_asm_get_property(app_id, &p);
	    p.f_prepare_w_reserve = 1;
	    mmi_frm_asm_set_property(app_id, &p);
    #endif
		//not guarantee memory here
		SEND_APP_EVT(&app, cntx, EVT_ID_APP_ENTER);
	}
	else
	{
		MMI_FRM_INIT_EVENT(&evt, 0);


        if (option & MMI_FRM_APP_USE_SEND_WAY)
        {
            MMI_FRM_SEND_EVENT(&evt, app_launcher_entry_proc, (void *)cntx);
        }
        else
        {
		    MMI_FRM_POST_EVENT(&evt, app_launcher_entry_proc, (void *)cntx);
        }
	}

	return gid;
}


void mmi_frm_app_close(MMI_ID app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    mmi_frm_group_close(app_id);
}


void mmi_frm_app_set_active(MMI_ID app_id, U32 option)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	mmi_frm_set_active_group(app_id);
}


MMI_ID mmi_frm_app_get_active_id()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_ID focus_group_id = mmi_frm_group_get_active_id();
	MMI_ID root_app_id = mmi_frm_get_root_app(focus_group_id);
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	return root_app_id;
}


MMI_ID mmi_frm_app_get_idle_app_id()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id idle_app_id = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
#ifdef __MMI_FRM_HISTORY__
	idle_app_id = GetIdleScrnId();
#else
	idle_app_id = mmi_frm_scrn_get_neighbor_id(GRP_ID_ROOT, 0, MMI_FRM_NODE_AT_BEGINNING_FLAG);
#endif
    
    return idle_app_id;
}


void mmi_frm_app_set_hidden(MMI_ID app_id, MMI_BOOL is_hide, U32 option)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	if (is_hide == MMI_TRUE)
	{
		mmi_frm_asm_app_hide(app_id);
	}
	else
	{
		mmi_frm_asm_app_unhide(app_id);
	}
}


MMI_BOOL mmi_frm_app_is_hidden(MMI_ID app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 state = mmi_frm_group_get_state(app_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if((state & MMI_SCENARIO_STATE_HIDE) ||
        (state & MMI_SCENARIO_STATE_HIDING))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


void mmi_frm_app_continue_to_close(MMI_ID app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
	mmi_frm_app_launcher_struct *cntx = (mmi_frm_app_launcher_struct *)mmi_frm_group_get_user_data(app_id);
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	cntx->flag_int |= SKIP_CHECK;
	if (cntx->flag_int & BACK_HOME)
	{
		mmi_frm_close_to_idle_group_with_start_id(app_id);
	}
	else if (cntx->flag_int & FREE_ASM)
	{
		mmi_event_struct post_free_evt;
		MMI_FRM_INIT_EVENT(&post_free_evt, 0);
		MMI_FRM_POST_EVENT(&post_free_evt, post_free_proc, (void *)cntx->app_id);
		mmi_frm_group_close(app_id);
	}
	else
	{
		mmi_frm_group_close(app_id);
	}
}


U32 mmi_frm_app_get_base_mem_size(MMI_ID app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_res_get_app_base_mem_size(app_id);
}


U32 mmi_frm_app_get_fg_mem_size(MMI_ID app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_res_get_app_fg_mem_size(app_id);    
}

MMI_BOOL mmi_frm_app_is_launched(MMI_ID app_id)
{
    return mmi_frm_group_is_present(app_id);
}
