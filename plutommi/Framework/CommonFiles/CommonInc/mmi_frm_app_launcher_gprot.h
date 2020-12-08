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
 *    mmi_frm_app_launcher_gprot.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MMI_FRM_APP_LAUNCHER_GPROT_H
#define MMI_FRM_APP_LAUNCHER_GPROT_H
/***************************************************************************** 
* Include
*****************************************************************************/
#include "MMIDatatype.h"
#include "GlobalResDef.h"

/***************************************************************************** 
* Define
*****************************************************************************/
/* The option value of mmi_frm_app_launch */
#define MMI_FRM_APP_NORMAL_LAUNCH        0x00000000
#define MMI_FRM_APP_FORCE_PREPARE_MEM    0x00000001
#define MMI_FRM_APP_LAUNCH_AFTER_BASE    0x00000004
#define MMI_FRM_APP_LAUNCH_BEFORE_BASE   0x00000008
#define MMI_FRM_APP_SKIP_SIZE_CHECK      0x00000010
#define MMI_FRM_APP_SKIP_RESVERVE_CHECK  0x00000020
#define MMI_FRM_APP_USE_SEND_WAY         0x00000040
#define MMI_FRM_APP_SKIP_PREPARE         0x10000000

/* The return value when receiving EVT_ID_APP_CLOSE_REQ */
#define MMI_APP_CLOSE_ANSWER_YES      MMI_RET_OK
#define MMI_APP_CLOSE_ANSWER_NO       (1001)
#define MMI_APP_CLOSE_ANSWER_HIDE     (1002)
#define MMI_APP_CLOSE_ANSWER_LATER    (1003)

/* The return value of EVT_ID_APP_NO_CHILD */
#define MMI_APP_NO_CHILD_HANDLED_BY_APP  (1001)

/* Application event base member */
#define MMI_APP_EVT_PARAM_HEADER                     \
    MMI_EVT_PARAM_HEADER                             \
    MMI_ID app_id;      /* The application ID */     \
    MMI_ID caller_id;   /* The caller app ID  */

/* Macro to get application ID from app event structure */
#define GET_APP_ID(evt)          ((mmi_app_evt_struct *)(evt))->app_id

/* Macro to get deinit reason from mmi_app_deinit_evt_struct structure */
#define GET_DEINIT_REASON(evt)   ((mmi_app_deinit_evt_struct *)(evt))->reason
    
/***************************************************************************** 
* Typedef
*****************************************************************************/

/* Deinit reason when receive EVT_ID_APP_DEINIT */
typedef enum
{
    MMI_APP_DEINIT_BY_CLOSE,              /* Deinit by normal close */
    MMI_APP_DEINIT_BY_ASM_CANCEL,         /* Deinit by select cancel in OOM */
    MMI_APP_DEINIT_BY_BACK_HOME,          /* Deinit by mmi_idle_display */
    MMI_APP_DEINIT_INSERT_WITHOUT_ENTER,  /* launch with base_id, but not entered */
        
    MMI_APP_END
} mmi_app_deinit_reason_enum;

/* Application common event structure */
typedef struct
{
    MMI_APP_EVT_PARAM_HEADER
} mmi_app_evt_struct;

/* Event Struct of EVT_ID_APP_DEINIT */
typedef struct
{
    MMI_APP_EVT_PARAM_HEADER
    mmi_app_deinit_reason_enum reason; /* The reason of deinit, please see mmi_app_deinit_reason_enum */
} mmi_app_deinit_evt_struct;

/* Event Struct of EVT_ID_TOP_ACTIVE */
typedef struct
{
	MMI_APP_EVT_PARAM_HEADER
	MMI_BOOL is_1st;
} mmi_app_top_active_evt_struct;

/***************************************************************************** 
* CallBack
*****************************************************************************/

/*****************************************************************************
 * CALLBACK
 *  Application proc function
 * DESCRIPTION
 *  Application proc function is to use handle application event.
 *  We will not use this type in code, just use it to show the example code.
 *  It has the same type as mmi_proc_func
 *
 * PARAMETERS
 *  evt       : [IN] this is an comment event pointer
 * RETURNS
 *  MMI_RET according to EVT_ID_XXX's need
 * EXAMPLE
 * <code>
 *
 *  typedef struct
 *  {
 *	    void *base_ptr;
 *	    void *fg_ptr;
 *  } mem_ptr_struct;
 *
 *  static MMI_RET xxx_app_proc(mmi_event_struct *evt)
 *  {
 *      MMI_ID app_id =	GET_APP_ID(evt);
 *	    mem_ptr_struct *ptr = (mem_ptr_struct *)evt->user_data;
 *	    switch (evt->evt_id)
 *	    {
 *		    case EVT_ID_APP_ENTER:
 *		    {
 *              //After APP_ENTER, can allocate base memory *
 *			    U32 base = mmi_frm_app_get_base_mem_size(app_id);
 *			    ptr->base_ptr = mmi_frm_asm_alloc_r(app_id, base);
 *			    MMI_ASSERT(ptr->base_ptr);
 *
 *              //create a screen for this application
 *			    mmi_frm_scrn_create(app_id, 1000, xxx_scrn_proc, NULL);
 *			    break;
 *		    }
 *
 *		    case EVT_ID_APP_TOP_ACTIVE:
 *		    {
 *              //After TOP ACTIVE, can allocate foreground memory
 *			    U32 fg = mmi_frm_app_get_fg_mem_size(app_id);
 *			    ptr->fg_ptr = mmi_frm_asm_alloc_r(app_id, fg);
 *			    MMI_ASSERT(ptr->fg_ptr);
 *			    break;
 *		    }
 *
 *		    case EVT_ID_APP_TOP_INACTIVE:
 *          {
 *              //must free all foreground part or will got assert fail
 *			    mmi_frm_asm_free_r(app_id, ptr->fg_ptr);
 *			    break;
 *			}
 *
 *		    case EVT_ID_APP_DEINIT:
 *          {
 *			    if (GET_DEINIT_REASON(evt) != MMI_APP_DEINIT_BY_ASM_CANCEL)
 *              {
 *                  //We must free based memory when app deinit
 *                  //except asm cancel case because we have not allocate memory yet in that case
 *				    mmi_frm_asm_free_r(app_id, ptr->base_ptr);
 *			    }
 *              //we use control buffer as the memory of the user data, so free it here
 *			    mmi_mfree(evt->user_data);
 *			    break;
 *	        }
 *      }
 *      return MMI_RET_OK;
 *  }
 * </code>
 *****************************************************************************/
typedef MMI_RET (* app_proc)(mmi_event_struct *evt);

/***************************************************************************** 
* Function Declaration
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_app_launch
 * DESCRIPTION
 *  This function is used to launch an application
 *  This launch function only support single instance.
 *  As a result, the application ID, must be unique
 *  must define in res file.
 *
 * PARAMETERS
 *  app_id :        [IN] application ID, define in resource
 *  caller_id :     [IN] caller application ID, if not need, set as 0
 *  base_id :       [IN] reference application ID, if use option MMI_FRM_APP_LAUNCH_AFTER_BASE or MMI_FRM_APP_LAUNCH_BEFORE_BASE
 *  proc :          [IN] the proc function that will receive the related event
 *  user_data:      [IN] the user data that will pass to user in the proc
 *  option :        [IN] launch option, please the option value in the section of define, such as MMI_FRM_APP_FORCE_PREPARE_MEM       
 *
 * RETURN
 *  The application ID
 *
 * EXAMPLE
 * <code>
 *
 *  // Launch an application and support smart close
 *  void xxx_app_launch()
 *  {
 *      xxx_app_cntx_struct *ptr = (xxx_app_cntx_struct *)mmi_malloc(sizeof(xxx_app_cntx_struct));
 *      mmi_frm_app_launch(APP_XXX, 0, 0, xxx_app_proc, (void *)ptr, MMI_FRM_APP_SMART_CLOSE);
 *  }
 *
 *  // Launch an application above idle
 *  void xxx_app_launch()
 *  {
 *	    xxx_app_cntx_struct *ptr = (xxx_app_cntx_struct *)mmi_malloc(sizeof(xxx_app_cntx_struct));
 *      MMI_ID base_id = mmi_frm_app_get_idle_app_id();
 *	    mmi_frm_app_launch(APP_XXX, 0, base_id, xxx_app_proc, (void *)ptr, MMI_FRM_APP_SMART_CLOSE | MMI_FRM_APP_LAUNCH_AFTER_BASE);
 *  }
 *
 *  // Launch an application with hidden check
 *  void xxx_app_launch()
 *  {
 *	    if (mmi_frm_app_is_hidden(APP_XXX) == MMI_FALSE)
 *      {
 *		    xxx_app_cntx_struct *ptr = (xxx_app_cntx_struct *)mmi_malloc(sizeof(xxx_app_cntx_struct));
 *		    mmi_frm_app_launch(APP_XXX, 0, 0, app_xxx_proc, (void *)ptr, MMI_FRM_APP_SMART_CLOSE);
 *	    }
 *	    else
 *	    {
 *		    mmi_frm_app_set_hidden(APP_XXX, MMI_FALSE, 0);
 *	    }
 *  }
 *
 * </code>
 *****************************************************************************/
extern MMI_ID mmi_frm_app_launch(MMI_ID app_id, MMI_ID caller_id, MMI_ID base_id, mmi_proc_func proc, void *user_data, U32 option);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_app_close
 * DESCRIPTION
 *  This function is used to close an application
 *  (Screen Group under Root)
 *
 * PARAMETERS
 *  app_id : [IN] application ID
 *
 * RETURN
 *  void
 *
 * EXAMPLE
 * <code>
 *
 *  mmi_frm_app_close(app_id);
 *
 * </code>
 *****************************************************************************/
extern void mmi_frm_app_close(MMI_ID app_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_app_set_active
 * DESCRIPTION
 *  This function is used to make the application into foreground
 *
 *   APP_A
 *   APP_B
 *   APP_C
 *
 *  after calling mmi_frm_app_set_active(APP_B)
 *  The order of the application should be
 *
 *   APP_B
 *   APP_A
 *   APP_C
 *
 * PARAMETERS
 *  app_id : [IN] application ID
 *  option : [IN] reserved
 *
 * RETURN
 *  The Idle Application ID(Home Application)
 *
 * EXAMPLE
 * <code>
 *
 *  mmi_frm_app_set_active(app_id, 0);
 *
 * </code>
 *****************************************************************************/
extern void mmi_frm_app_set_active(MMI_ID app_id, U32 option);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_app_get_idle_app_id
 * DESCRIPTION
 *  This function is used to get the idle application ID(The first child of ROOT)
 *
 *   APP_A
 *   APP_B
 *   APP_C
 *
 *  The idle app id is APP_C
 *
 * PARAMETERS
 *  void
 *
 * RETURN
 *  The Idle Application ID(Home Application)
 *
 * EXAMPLE
 * <code>
 *
 *  MMI_ID idle_app_id = mmi_frm_app_get_idle_app_id();
 *
 * </code>
 *****************************************************************************/
extern MMI_ID mmi_frm_app_get_idle_app_id(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_app_get_active_id
 * DESCRIPTION
 *  This function is used to get the current active application ID
 *  (Screen Group ID under root)
 *
 *   APP_A
 *   APP_B
 *   APP_C
 *
 *  The active app id is APP_A
 *
 * PARAMETERS
 *  void
 *
 * RETURN
 *  The current Application ID
 *
 * EXAMPLE
 * <code>
 *
 *  MMI_ID app_id = mmi_frm_app_get_active_id();
 *
 * </code>
 *****************************************************************************/
extern MMI_ID mmi_frm_app_get_active_id(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_app_set_hidden
 * DESCRIPTION
 *  This function is used to make the application from foreground to background
 *  or make it from background to foreground
 *
 * PARAMETERS
 *  app_id  :         [IN] Application ID
 *  is_hide :         [IN] hidden or unhidden
 *  option  :         [IN] reserved, fill 0
 *
 * RETURN
 *  void
 *
 * EXAMPLE
 * <code>
 *
 *  void xxx_app_launch()
 *  {
 *      MMI_ID app_id = VAPP_MSG;
 *      // Check if the application is in background
 *	    if (mmi_frm_app_is_hidden(app_id) == MMI_FALSE)
 *	    {
 *          //If not hidden, launch the app
 *		    mmi_frm_app_launch(app_id, 0, 0, tst_app_common_proc, (void *)ptr, MMI_FRM_APP_SMART_CLOSE);
 *	    }
 *	    else
 *	    {
 *          //If hidden, unhidden the app
 *          mmi_frm_app_set_hidden(app_id, MMI_FALSE, 0);
 *	    }  
 *  }
 *
 *  // make application into background when xxx_menu is tapped.
 *  void xxx_menu_handler()
 *  {
 *      mmi_frm_app_set_hidden(app_id, MMI_TRUE, 0);
 *  }
 *
 * </code>
 *****************************************************************************/
extern void mmi_frm_app_set_hidden(MMI_ID app_id, MMI_BOOL is_hide, U32 option);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_app_is_hidden
 * DESCRIPTION
 *  This function is used to check if the application is in background.
 *
 * PARAMETERS
 *  app_id :         [IN] Application ID
 *
 * RETURN
 *  If the application is in background, return MMI_TRUE, otherwise return MMI_FALSE
 *
 * EXAMPLE
 * <code>
 *
 *  void xxx_app_launch()
 *  {
 *      MMI_ID app_id = VAPP_MSG;
 *      // Check if the application is in background
 *	    if (mmi_frm_app_is_hidden(app_id) == MMI_FALSE)
 *	    {
 *          //If not hidden, launch the app
 *		    mmi_frm_app_launch(app_id, 0, 0, tst_app_common_proc, (void *)ptr, MMI_FRM_APP_SMART_CLOSE);
 *	    }
 *	    else
 *	    {
 *          //If hidden, unhidden the app
 *          mmi_frm_app_set_hidden(app_id, MMI_FALSE, 0);
 *	    }  
 *  }
 *
 * </code>
 *****************************************************************************/
extern MMI_BOOL mmi_frm_app_is_hidden(MMI_ID app_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_app_continue_to_close
 * DESCRIPTION
 *  If return MMI_APP_CLOSE_ANSWER_LATER in app proc when handle EVT_ID_APP_CLOSE_REQ
 *  Please use this API to do continue close.
 *
 * PARAMETERS
 *  app_id :         [IN] Application ID
 * RETURN
 *  void
 * EXAMPLE
 * <code>
 *  
 *  //In application proc
 *  static MMI_RET xxx_app_proc(mmi_event_struct *evt)
 *  {
 *      MMI_ID app_id =	GET_APP_ID(evt);
 *      MMI_RET ret = MMI_RET_OK;
 *
 *      swith (evt->evt_id)
 *      {
 *          ...
 *		    case EVT_ID_APP_CLOSE_REQ:
 *		    {
 *              // If you need to free resource in an async procedure
 *              // Please answer LATER here, and when free is done
 *              // call mmi_frm_app_continue_to_close
 *              // here we use a timer to simulate the async case
 *              // to indicate that how to use mmi_frm_app_continue_to_close
 *			    ret = MMI_APP_CLOSE_ANSWER_LATER;
 *			    gui_start_timer_ex(1000, async_close_app_timer_callback, (void *)app_id);
 *			    break;
 *		    }
 *          ...
 *      }
 *      return ret;
 *  }
 *
 *  static void async_close_app_timer_callback(void *arg)
 *  {
 *      //When resource is freed, call mmi_frm_app_continue_to_close
 *	    MMI_ID app_id = (MMI_ID)arg;
 *      mmi_frm_app_continue_to_close(app_id);
 *  }
 *
 * </code>
 *****************************************************************************/
extern void mmi_frm_app_continue_to_close(MMI_ID app_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_app_get_fg_mem_size
 * DESCRIPTION
 *  This function is used to get the foreground memory size of the application
 * PARAMETERS
 *  app_id :         [IN] application ID
 * RETURN
 *  foreground memory size of the application
 *****************************************************************************/
extern U32 mmi_frm_app_get_fg_mem_size(MMI_ID app_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_app_get_base_mem_size
 * DESCRIPTION
 *  This function is used to get the base memory size of the application
 * PARAMETERS
 *  app_id :         [IN] application ID
 * RETURN
 *  base memory size of the application
 *****************************************************************************/
extern U32 mmi_frm_app_get_base_mem_size(MMI_ID app_id);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_app_is_launched
 * DESCRIPTION
 *  This function is used to get the base memory size of the application
 * PARAMETERS
 *  app_id :         [IN] application ID
 * RETURN
 *  base memory size of the application
 *****************************************************************************/
extern MMI_BOOL mmi_frm_app_is_launched(MMI_ID app_id);

#endif
