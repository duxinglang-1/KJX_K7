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
 *  vmime.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  IME implement file.
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
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/* include vmswitch.h in order to check whether __MRE_LIB_IME__ is defined. */
#include "vmswitch.h"
#ifdef __MRE_LIB_IME__

#include "MMI_features.h"
#include "MMIDataType.h"
#include "string.h"
#include "GlobalConstants.h"
#include "GpioSrvGprot.h"
#include "ImeGprot.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_list.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_inputs.h"
#include "wgui_categories_util.h"
#include "kal_non_specific_general_types.h"
#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
/* For WorldClock & Calculator */
#include "worldclock.h"
#include "PhoneSetup.h"
#include "AMGprot.h"
#include "DateTimeType.h"
/* For srv_prof_play_tone */
#include "ProfilesSrvGprot.h"
#include "vmio.h"
#include "vmlog.h"
#include "vmsys.h"
#include "vmstdlib.h" 
#include "vmopt.h"
#include "vmmod.h"
#include "vmmem.h"
#include "vmresmng.h"
#include "vmpromng.h"
#include "mmi_rp_app_mre_def.h"
#include "mmi_trc_int.h"
#include "MMI_mre_trc.h"
#include "CommonScreens.h"

/* the maximium number of characters can be inputted by default. */
#define MAX_SIZE_OF_INPUT 250

/* 
* global pointer which points to the input buffer.
*/
static VMWSTR input_text_ptr = NULL;

/* global variable to store the input type. */
static VMINT vm_input_type = IMM_INPUT_TYPE_MULTITAP_SENTENCE;

/* global variable to store the size of input buffer. */
static VMINT vm_input_size = MAX_SIZE_OF_INPUT;

/* input mode */
static mmi_imm_input_mode_enum g_vm_input_mode = IMM_INPUT_MODE_NONE;

/* for power saving. */
struct vm_power_saving_controller_t
{
    VMINT vm_power_saving_switch;   /* 
                                     * true means power saving, false means NOT. 
                                     */
                                     
    VMINT vm_process_handle;        /* in process_status_callback, it will be 
                                     * used to check whether current process 
                                     * can change power saving mode. */
};

/* power saving is turned on by default. */
static struct vm_power_saving_controller_t vm_power_saving_controller 
    = {TRUE, 0};

/* title of vm input editor, its size must less than 60 */
static U16 g_vm_editor_title[60] = {0};

/* flag that indicates whether user has provided a title */
static VMINT g_vm_editor_title_is_user_provided = FALSE;

/* prepare to entry input screen. */
static VMINT entry_input_screen(
    VMWSTR  input_txt_buffer, 
    VMINT   input_buffer_size,
    VMINT   input_mode, 
    void    (*app_input_callback)(VMINT state, VMWSTR text));

/* show the screen of input editor. */
static void vm_show_ime_screen(void);

/* when user press 'OK' on input editor screen, do_input_ok will be called. */
static void do_input_ok(void);

/* 
 * when user press 'Cancel' on input editor screen, do_input_cancel will be 
 * called. 
 */
static void do_input_cancel(void);

/* 
 * internal function, it will be called by do_input_ok, do_input_cancel, 
 * vm_input_close_screen.
 */
static void do_input_ok_cancel_close_internal(VMINT message_type);

extern MMI_BOOL srv_mre_get_app_name(
    U16     *app_path, 
    U16     *p_name, 
    U32     *name_size);

/*****************************************************************************
 * FUNCTION
 *  vm_ime_process_status_callback
 * DESCRIPTION
 *  when process status changes, the function will be called.
 * PARAMETERS
 *  process_handle   :   [IN]    the handle of process whose status changed.        
 *  sys_state         :  [IN]    the new status of the process.        
 * RETURNS
 *  void
 *****************************************************************************/
static void vm_ime_process_status_callback(
    VM_P_HANDLE     process_handle, 
    VMINT           sys_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT rHandle = VM_RES_NOT_FIND;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sys_state)
    {
    case VM_PMNG_UNLOAD:
        while ((rHandle = vm_res_findfirst(process_handle, VM_RES_TYPE_IME))
                != VM_RES_NOT_FIND)
        {
            vm_res_findclose(VM_RES_TYPE_IME);
            vm_res_release_data(VM_RES_TYPE_IME, rHandle);
            vm_ime_close_ime_screen();
        }
        /*
        * no "break" statement here, because we need to turn on power saving mode 
        * when app exits.
        */
    case VM_PMNG_BACKGROUND:
        /* when app exits or run in background, we should turn on power saving mode. */
        if (process_handle == vm_power_saving_controller.vm_process_handle
            && vm_power_saving_controller.vm_power_saving_switch == FALSE)
        {
            srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
            srv_backlight_turn_off();
            vm_power_saving_controller.vm_power_saving_switch = TRUE;
            vm_power_saving_controller.vm_process_handle = 0;
        }
        break;
    }
}

/******************************************************************************
 * FUNCTION
 *  vm_turn_on_power_saving_internal
 * DESCRIPTION
 *  turn on power saving mode.
 *  this function will be used only in this file.
 * PARAMETERS
 *  void
 * RETURN
 *  void
 ******************************************************************************/
static void vm_turn_on_power_saving_internal(void)
{
    /* 
     * if power saving mode is not turn on, then we will turn on it here.
     */
    if (vm_power_saving_controller.vm_power_saving_switch == FALSE)
    {
        srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
        srv_backlight_turn_off();
    }
    
    /* set the flags, so we can know power saving mode is turn on now. */
    vm_power_saving_controller.vm_power_saving_switch = TRUE;
    vm_power_saving_controller.vm_process_handle = 0;
}

/*****************************************************************************
 * FUNCTION
 *   vm_initialize_ime
 * DESCRIPTION
 *   this function will be called to handle MOD_EVENT_INIT of IME module.
 *   it will turn on power saving mode, and register 
 *   vm_ime_process_status_callback to handle the status change of an app.
 * PARAMETERS
 *   void
 * RETURNS
 *   if no error, return 0.
 *   otherwise, return -1.
 *****************************************************************************/
static VMINT vm_initialize_ime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    vm_turn_on_power_saving_internal();
    
    if (vm_res_type_set_notify_callback(
            VM_RES_TYPE_IME, 
            vm_ime_process_status_callback) != 0)
    {
        return -1;
    }

    return 0;
}

/*****************************************************************************
 * FUNCTION
 *   vm_finialize_ime
 * DESCRIPTION
 *   this function will be called to handle the MOD_EVENT_RELEASE of IME module.
 *   it will turn off power saving mode, release resources, and reset notify 
 *   callback of app's status change.
 * PARAMETERS
 *   void
 * RETURNS
 *   the return value is always 0.
 *****************************************************************************/
static VMINT vm_finialize_ime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT rHandle = VM_RES_NOT_FIND;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vm_turn_on_power_saving_internal();

    while ((rHandle = vm_res_findfirst(-1, VM_RES_TYPE_IME)) != VM_RES_NOT_FIND)
    {
        vm_res_findclose(VM_RES_TYPE_IME);
        vm_res_release_data(VM_RES_TYPE_IME, rHandle);
    }
    vm_res_type_set_notify_callback(VM_RES_TYPE_IME, NULL);

    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  vm_ime_close_ime_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_ime_close_ime_screen(void)
{
    mmi_ime_delete_editor_common_scr(MRE_INPUT_SCREEN_ID);
    mmi_frm_scrn_close(GRP_ID_ROOT, MRE_INPUT_SCREEN_ID);

    return 1;
}

/*****************************************************************************
 * FUNCTION
 *  vm_ime_mod_evt_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vm_ime_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event)
    {
    case EVT_MOD_INIT:
        vm_initialize_ime();
        break;

    case EVT_MOD_RELEASE:
        vm_finialize_ime();
        break;
    }

    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  _vm_reg_ime_module
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VMINT _vm_reg_ime_module(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return _vm_reg_module(
        "IME MODULE", 
        (MOD_EVT_PROCESS) vm_ime_mod_evt_proc);
}


/*****************************************************************************
 * FUNCTION
 *  entry_input_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input_txt_buffer        [IN]        
 *  input_buffer_size       [IN]        
 *  input_mode              [IN]        
 *  app_input_callback      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static VMINT entry_input_screen(
    VMWSTR  input_txt_buffer,
    VMINT   input_buffer_size,
    VMINT   input_mode,
    void    (*app_input_callback)(VMINT state, VMWSTR text))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT           rHandle     =   0;
    VM_P_HANDLE     pHandle     =   vm_pmng_get_current_handle();
    VM_P_HANDLE     pHandle2    =   NULL;
    VMWCHAR         *file_path  =   NULL;
    U32             title_size  =   60;
    void            (*app_callback)(VMINT state, VMWSTR text) = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vm_pmng_state(pHandle) != VM_PMNG_FOREGROUND)
    {
        MMI_TRACE(MMI_MRE_TRC_G2_IME, TRC_MRE_IME_ERROR_NOT_IN_FG);
        return -1;
    }

    /* 
     * if an IME screen is already exist, then close it and send VM_INPUT_NOTIFY 
     * to app's callback function.
     */
    if ((rHandle = vm_res_findfirst(-1, VM_RES_TYPE_IME)) != VM_RES_NOT_FIND)
    {
        vm_res_findclose(VM_RES_TYPE_IME);

        if (vm_res_get_callback(VM_RES_TYPE_IME, rHandle, (void **)&app_callback) == 0
            && app_callback != NULL 
            && (pHandle2 = vm_res_get_process_handle(VM_RES_TYPE_IME, rHandle)) >= 0)
        {
            vm_res_release_data(VM_RES_TYPE_IME, rHandle);

            mmi_frm_scrn_close(GRP_ID_ROOT, MRE_INPUT_SCREEN_ID);
            
            if (vm_pmng_set_ctx(pHandle2) == VM_PMNG_OP_OK)
            {
                app_callback(VM_INPUT_NOTIFY, input_text_ptr);
                if (input_text_ptr != NULL)
                {
                    vm_free(input_text_ptr);
                }
                vm_pmng_reset_ctx();
            }
            
            input_text_ptr = NULL;
        }
    }

    /* 
     * if no IME screen is already exist, then we try to open a new IME screen. 
     */
    if (vm_res_save_data(
            VM_RES_TYPE_IME, 
            NULL, 
            0, 
            (void *) app_input_callback, 
            pHandle) < 0)
    {
        MMI_TRACE(MMI_MRE_TRC_G2_IME, TRC_MRE_IME_ERROR_SAVE_FAILED);
        return -2;
    }

    vm_input_type = input_mode;
    input_text_ptr = input_txt_buffer;
    vm_input_size = input_buffer_size;

    if (g_vm_editor_title_is_user_provided) 
    {
        /*
        * user has provided a title. we should clear the flag below, so it will
        * NOT affect the next editor title.
        */
        g_vm_editor_title_is_user_provided = FALSE;
    } 
    else 
    {
        /* get app name and set as editor title */
        file_path = (VMWCHAR *) _vm_kernel_malloc(
            MAX_APP_NAME_LEN * sizeof(VMWCHAR));
        
        memset(g_vm_editor_title, 0x00, sizeof(g_vm_editor_title));
        
        if (NULL != file_path)
        {
            vm_pmng_file_name(
                vm_pmng_get_app_handle(), 
                (VMWCHAR*) file_path, 
                MAX_APP_NAME_LEN);
            
            if (!srv_mre_get_app_name(file_path, g_vm_editor_title, &title_size))
            {
                mmi_wcscpy(g_vm_editor_title, get_string(STR_MRE_TITLE));
            }
            MMI_TRACE(
                MMI_MRE_TRC_G2_IME, 
                TRC_MRE_IME_SHOW_SCREEN_CATEGORY, 
                file_path, 
                g_vm_editor_title);
            
            _vm_kernel_free(file_path); /* release memory */
        }
        else
        {
            mmi_wcscpy(g_vm_editor_title, get_string(STR_MRE_TITLE));
        }
    }

    vm_show_ime_screen();

    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  vm_show_ime_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vm_show_ime_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    U8 *gui_buffer = NULL;
    S32 ime = (S32) IMM_INPUT_TYPE_SENTENCE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G2_IME, TRC_MRE_IME_SHOW_SCREEN_S, vm_input_type);

    ret = mmi_frm_scrn_enter(
        GRP_ID_ROOT, 
        MRE_INPUT_SCREEN_ID, 
        NULL, 
        (FuncPtr) vm_show_ime_screen, 
        MMI_FRM_FULL_SCRN);

    if (ret == MMI_FALSE)
    {
        return;
    }

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    switch (vm_input_type)
    {
    case VM_INPUT_METHOD_PASSWORD:
        ime = (S32) IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD;
        break;

    case VM_INPUT_METHOD_NUMERIC:
        ime = (S32) IMM_INPUT_TYPE_NUMERIC_SYMBOL;
        if (gui_buffer == NULL)
        {
            mmi_imm_set_app_desired_input_mode(IMM_INPUT_MODE_123_SYMBOLS);
        }
        break;

    case VM_INPUT_METHOD_ALPHABETIC:
        ime = (S32) IMM_INPUT_TYPE_SENTENCE;
        if (gui_buffer == NULL)
        {
            mmi_imm_set_app_desired_input_mode(IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC);
        }
        break;

    case VM_INPUT_METHOD_URL:
        ime = (S32) IMM_INPUT_TYPE_URL;
        if (gui_buffer == NULL)
        {
            mmi_imm_set_app_desired_input_mode(IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC);
        }
        break;

    default:
        ime = (S32) IMM_INPUT_TYPE_SENTENCE;
        break;
    }

    if (IMM_INPUT_MODE_NONE != g_vm_input_mode && gui_buffer == NULL)
    {
        mmi_imm_set_app_desired_input_mode(g_vm_input_mode);
        g_vm_input_mode = IMM_INPUT_MODE_NONE;
    }

    #ifdef __MMI_FTE_SUPPORT__
    
        ShowCategory5Screen_ext2(
            g_vm_editor_title,
            NULL,
            get_string(STR_GLOBAL_OK),
            get_image(IMG_GLOBAL_OK),
            get_string(STR_GLOBAL_BACK),
            get_image(IMG_GLOBAL_BACK),
            ime,
            (PU8) input_text_ptr,
            vm_input_size + 1,
            gui_buffer,
            0,
            NULL);
            
    #else /* __MMI_FTE_SUPPORT__ */
    
        ShowCategory5Screen_ext2(
            g_vm_editor_title,
            get_image(IMAGE_MRE_EDITOR_TITLE),
            get_string(STR_GLOBAL_OK),
            get_image(IMG_GLOBAL_OK),
            get_string(STR_GLOBAL_BACK),
            get_image(IMG_GLOBAL_BACK),
            ime,
            (PU8) input_text_ptr,
            vm_input_size + 1,
            gui_buffer,
            0,
            NULL);
    #endif /* __MMI_FTE_SUPPORT__ */

    SetLeftSoftkeyFunction(do_input_ok, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(do_input_cancel, KEY_EVENT_UP);
    
    #ifdef __COSMOS_MMI_PACKAGE__
        SetKeyHandler(do_input_cancel, KEY_BACK, KEY_EVENT_UP);
    #endif

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(do_input_ok, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  vm_input_text
 * DESCRIPTION
 *  Display a editor screen. The default input method is VM_INPUT_METHOD_TEXT.
 *  The max length of input string is 250.
 * PARAMETERS
 *  f : [IN] This callback will be invoked when the editor screen closed. 
 *           If user selects OK, the state will be VM_INPUT_OK.
 *           If user select Cancel, the state will be VM_INPUT_CANCEL.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  0 : If open the input screen successfully.
 *  <0 : If failed.
 *****************************************************************************/
VMINT vm_input_text(void (*f)(VMINT state, VMWSTR text))
{
    VMWSTR input_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G2_IME, TRC_MRE_IME_INPUT, f);

    if (f == NULL || !vm_pmng_is_fg(VM_PMNG_CUR_HANDLE))
    {
        return -1;
    }

    input_buffer = vm_calloc((MAX_SIZE_OF_INPUT + 1) * sizeof(VMWCHAR));
    if (NULL == input_buffer)
    {
        return -2;
    }

    return entry_input_screen(
        input_buffer, 
        MAX_SIZE_OF_INPUT, 
        VM_INPUT_METHOD_TEXT, 
        f);
}

/*****************************************************************************
 * FUNCTION
 *  vm_input_text2
 * DESCRIPTION
 *  Display a editor screen. User can set default string and default input method.
 *  The max length of input string is 250.
 * PARAMETERS
 *  def_str : [IN] Default string in editor screen.
 *  def_input_method: [IN] Default input method.
 *  f : [IN] This callback will be invoked when the editor screen closed. 
 *           If user selects OK, the state will be VM_INPUT_OK.
 *           If user select Cancel, the state will be VM_INPUT_CANCEL.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  0 : If open the input screen successfully.
 *  <0 : If failed.
 *****************************************************************************/
VMINT vm_input_text2(
    VMWSTR  default_string, 
    VMINT   default_input_method, 
    void    (*f)(VMINT state, VMWSTR text))
{
    VMWSTR input_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_MRE_TRC_G2_IME, 
        TRC_MRE_IME_INPUT2, 
        default_string, 
        default_input_method, 
        f);

    if (f == NULL || !(vm_pmng_is_fg(VM_PMNG_CUR_HANDLE)))
        return -1;

    input_buffer = vm_calloc((MAX_SIZE_OF_INPUT + 1) * sizeof(VMWCHAR));
    if (NULL == input_buffer)
    {
        return -2;
    }

    if (default_string != NULL && default_string[0] != 0)
    {
        vm_wstrncpy(input_buffer, default_string, MAX_SIZE_OF_INPUT);
    }

    return entry_input_screen(
        input_buffer, 
        MAX_SIZE_OF_INPUT, 
        default_input_method, 
        f);
}

/*****************************************************************************
 * FUNCTION
 *  vm_input_text3
 * DESCRIPTION
 *  Display a editor screen. User can set default string and default input method.
 *  User can also set the max input length (in short) via parameter input_max_size.
 * PARAMETERS
 *  default_string : [IN] Default string in editor screen.
 *  input_max_size : [IN] 
 *  default_input_method: [IN] Default input method.
 *  input_text_cb : [IN] This callback will be invoked when the editor screen closed. 
 *                       If user selects OK, the state will be VM_INPUT_OK.
 *                       If user select Cancel, the state will be VM_INPUT_CANCEL.
 * RETURNS
 *  The error code of the operation.
 * RETURN VALUES
 *  0 : If open the input screen successfully.
 *  <0 : If failed.
 *****************************************************************************/
VMINT vm_input_text3(
    VMWSTR  default_string,
    VMINT   input_max_size,
    VMINT   default_input_method,
    void    (*f)(VMINT state, VMWSTR text))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMWSTR input_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_MRE_TRC_G2_IME, 
        TRC_MRE_IME_INPUT3, 
        default_string, 
        input_max_size, 
        default_input_method, 
        f);

    if (f == NULL || input_max_size <= 0 || !vm_pmng_is_fg(VM_PMNG_CUR_HANDLE))
    {
        return -1;
    }

    input_buffer = vm_calloc((input_max_size + 1) * sizeof(VMWCHAR));
    if (NULL == input_buffer)
    {
        return -2;
    }

    if ((default_string != NULL) && (default_string[0] != 0))
    {
        vm_wstrncpy(input_buffer, default_string, input_max_size);
    }

    return entry_input_screen(
        input_buffer, 
        input_max_size, 
        default_input_method, 
        f);
}

/*****************************************************************************
 * FUNCTION
 *  do_input_ok
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void do_input_ok(void)
{
    do_input_ok_cancel_close_internal(VM_INPUT_OK);
}

/*****************************************************************************
 * FUNCTION
 *  do_input_cancel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void do_input_cancel(void)
{
    do_input_ok_cancel_close_internal(VM_INPUT_CANCEL);
}

static void do_input_ok_cancel_close_internal(VMINT message_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT rHandle = 0;
    VM_P_HANDLE pHandle = 0;
    void (*app_callback) (VMINT state, VMWSTR text) = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_IME) != 1)
    {
        if (message_type != VM_INPUT_CLOSE) /* VM_INPUT_OK or VM_INPUT_CANCEL */
        {
            mmi_frm_scrn_close_active_id();
        }

        return;
    }

    while ((rHandle = vm_res_findfirst(-1, VM_RES_TYPE_IME)) != VM_RES_NOT_FIND)
    {
        vm_res_findclose(VM_RES_TYPE_IME);

        if (vm_res_get_callback(VM_RES_TYPE_IME, rHandle, (void **)&app_callback) == 0
            && app_callback != NULL 
            && (pHandle = vm_res_get_process_handle(VM_RES_TYPE_IME, rHandle)) >= 0)
        {
            vm_res_release_data(VM_RES_TYPE_IME, rHandle);

            if (message_type == VM_INPUT_CLOSE)
            {
                mmi_frm_scrn_close(GRP_ID_ROOT, MRE_INPUT_SCREEN_ID);
            }
            else /* VM_INPUT_OK or VM_INPUT_CANCEL */
            {
                mmi_frm_scrn_close_active_id();
            }

            if (vm_pmng_set_ctx(pHandle) == VM_PMNG_OP_OK)
            {
                app_callback(message_type, input_text_ptr);

                if (input_text_ptr != NULL)
                {
                    vm_free(input_text_ptr);
                }

                vm_pmng_reset_ctx();
            }

            input_text_ptr = NULL;
            break;
        }
        else
        {
            vm_res_release_data(VM_RES_TYPE_IME, rHandle);

            if (message_type == VM_INPUT_CLOSE)
            {
                mmi_frm_scrn_close(GRP_ID_ROOT, MRE_INPUT_SCREEN_ID);
            }
            else /* VM_INPUT_OK or VM_INPUT_CANCEL */
            {
                mmi_frm_scrn_close_active_id();
            }

            break;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  vm_switch_power_saving_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_switch_power_saving_mode(power_saving_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G2_IME, TRC_MRE_IME_SWITCH_POWER_SAVE_MODE, mode);
    
    if (vm_pmng_is_fg(VM_PMNG_CUR_HANDLE)
        || (vm_power_saving_controller.vm_process_handle 
            == vm_pmng_get_current_handle() && mode == turn_on_mode))
    {
        switch (mode)
        {
        case turn_on_mode:
            if (!vm_power_saving_controller.vm_power_saving_switch)
            {
                srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
                srv_backlight_turn_off();
                vm_power_saving_controller.vm_power_saving_switch = TRUE;
                vm_power_saving_controller.vm_process_handle 
                    = vm_pmng_get_current_handle();
            }
            return 0;

        case turn_off_mode:
            if (vm_power_saving_controller.vm_power_saving_switch)
            {
                srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
                vm_power_saving_controller.vm_power_saving_switch = FALSE;
                vm_power_saving_controller.vm_process_handle 
                    = vm_pmng_get_current_handle();
            }
            return 0;

        default:
            return -1;
        }
    }

    return -2;
}

const VMUINT16 input_mode_list[] = 
{
    IMM_INPUT_MODE_NONE,                                /*  0   VM_INPUT_MODE_NONE  */
    IMM_INPUT_MODE_123,                                 /*  1   VM_INPUT_MODE_123   */
    IMM_INPUT_MODE_123_SYMBOLS,                         /*  2   VM_INPUT_MODE_123_SYMBOLS   */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC,              /*  3   VM_INPUT_MODE_MULTITAP_UPPERCASE_ABC    */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC,              /*  4   VM_INPUT_MODE_MULTITAP_LOWERCASE_ABC    */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ABC_NO_NUMERIC,   /*  5   VM_INPUT_MODE_MULTITAP_UPPERCASE_ABC_NO_NUMERIC */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC_NO_NUMERIC,   /*  6   VM_INPUT_MODE_MULTITAP_LOWERCASE_ABC_NO_NUMERIC */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ABC,        /*  7   VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ABC  */
    IMM_INPUT_MODE_SMART_LOWERCASE_ABC,                 /*  8   VM_INPUT_MODE_SMART_LOWERCASE_ABC   */
    IMM_INPUT_MODE_SMART_UPPERCASE_ABC,                 /*  9   VM_INPUT_MODE_SMART_UPPERCASE_ABC   */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ABC,           /*  10  VM_INPUT_MODE_SMART_FIRST_UPPERCASE_ABC */
    IMM_INPUT_MODE_ARABIC_NUMERIC,                      /*  11  VM_INPUT_MODE_ARABIC_NUMERIC    */
    IMM_INPUT_MODE_FLOAT_123,                           /*  12  VM_INPUT_MODE_FLOAT_123 */
    IMM_INPUT_MODE_HK_STROKE,                           /*  13  VM_INPUT_MODE_HK_STROKE     */
    IMM_INPUT_MODE_KEYPAD_NUMERIC,                      /*  14  VM_INPUT_MODE_KEYPAD_NUMERIC    */
    IMM_INPUT_MODE_MAGIC_NUMBER,                        /*  15  VM_INPUT_MODE_MAGIC_NUMBER  */
    IMM_INPUT_MODE_PHONE_NUMBER,                        /*  16  VM_INPUT_MODE_PHONE_NUMBER  */
    IMM_INPUT_MODE_PHONE_NUMBER_WILDCHAR,               /*  17  VM_INPUT_MODE_PHONE_NUMBER_WILDCHAR */
    IMM_INPUT_MODE_SIGNED_123,                          /*  18  VM_INPUT_MODE_SIGNED_123    */
    IMM_INPUT_MODE_SIGNED_FLOAT_123,                    /*  19  VM_INPUT_MODE_SIGNED_FLOAT_123  */
    IMM_INPUT_MODE_SIM_NUMERIC,                         /*  20  VM_INPUT_MODE_SIM_NUMERIC   */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_AFRIKAANS,        /*  21  VM_INPUT_MODE_MULTITAP_UPPERCASE_AFRIKAANS      */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_AFRIKAANS,        /*  22  VM_INPUT_MODE_MULTITAP_LOWERCASE_AFRIKAANS  */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_AFRIKAANS,  /*  23  VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_AFRIKAANS    */
    IMM_INPUT_MODE_SMART_LOWERCASE_AFRIKAANS,           /*  24  VM_INPUT_MODE_SMART_LOWERCASE_AFRIKAANS */
    IMM_INPUT_MODE_SMART_UPPERCASE_AFRIKAANS,           /*  25  VM_INPUT_MODE_SMART_UPPERCASE_AFRIKAANS */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_AFRIKAANS,     /*  26  VM_INPUT_MODE_SMART_FIRST_UPPERCASE_AFRIKAANS   */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ALBANIAN,         /*  27  VM_INPUT_MODE_MULTITAP_UPPERCASE_ALBANIAN       */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ALBANIAN,         /*  28  VM_INPUT_MODE_MULTITAP_LOWERCASE_ALBANIAN   */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ALBANIAN,   /*  29  VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ALBANIAN */
    IMM_INPUT_MODE_SMART_LOWERCASE_ALBANIAN,            /*  30  VM_INPUT_MODE_SMART_LOWERCASE_ALBANIAN  */
    IMM_INPUT_MODE_SMART_UPPERCASE_ALBANIAN,            /*  31  VM_INPUT_MODE_SMART_UPPERCASE_ALBANIAN  */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ALBANIAN,      /*  32  VM_INPUT_MODE_SMART_FIRST_UPPERCASE_ALBANIAN    */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ARMENIAN,         /*  33  VM_INPUT_MODE_MULTITAP_UPPERCASE_ARMENIAN       */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ARMENIAN,         /*  34  VM_INPUT_MODE_MULTITAP_LOWERCASE_ARMENIAN   */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ARMENIAN,   /*  35  VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ARMENIAN */
    IMM_INPUT_MODE_SMART_LOWERCASE_ARMENIAN,            /*  36  VM_INPUT_MODE_SMART_LOWERCASE_ARMENIAN  */
    IMM_INPUT_MODE_SMART_UPPERCASE_ARMENIAN,            /*  37  VM_INPUT_MODE_SMART_UPPERCASE_ARMENIAN  */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ARMENIAN,      /*  38  VM_INPUT_MODE_SMART_FIRST_UPPERCASE_ARMENIAN    */
    IMM_INPUT_MODE_MULTITAP_ARABIC,                     /*  39  VM_INPUT_MODE_MULTITAP_ARABIC       */
    IMM_INPUT_MODE_SMART_ARABIC,                        /*  40  VM_INPUT_MODE_SMART_ARABIC  */
    IMM_INPUT_MODE_MULTITAP_ASSAMESE,                   /*  41  VM_INPUT_MODE_MULTITAP_ASSAMESE     */
    IMM_INPUT_MODE_SMART_ASSAMESE,                      /*  42  VM_INPUT_MODE_SMART_ASSAMESE    */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_AZERBAIJANI,      /*  43  VM_INPUT_MODE_MULTITAP_UPPERCASE_AZERBAIJANI    */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_AZERBAIJANI,      /*  44  VM_INPUT_MODE_MULTITAP_LOWERCASE_AZERBAIJANI    */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_AZERBAIJANI,/*  45  VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_AZERBAIJANI  */
    IMM_INPUT_MODE_SMART_LOWERCASE_AZERBAIJANI,         /*  46  VM_INPUT_MODE_SMART_LOWERCASE_AZERBAIJANI   */
    IMM_INPUT_MODE_SMART_UPPERCASE_AZERBAIJANI,         /*  47  VM_INPUT_MODE_SMART_UPPERCASE_AZERBAIJANI   */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_AZERBAIJANI,   /*  48  VM_INPUT_MODE_SMART_FIRST_UPPERCASE_AZERBAIJANI */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_BASQUE,           /*  49  VM_INPUT_MODE_MULTITAP_UPPERCASE_BASQUE     */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_BASQUE,           /*  50  VM_INPUT_MODE_MULTITAP_LOWERCASE_BASQUE */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_BASQUE,     /*  51  VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_BASQUE   */
    IMM_INPUT_MODE_SMART_LOWERCASE_BASQUE,              /*  52  VM_INPUT_MODE_SMART_LOWERCASE_BASQUE    */
    IMM_INPUT_MODE_SMART_UPPERCASE_BASQUE,              /*  53  VM_INPUT_MODE_SMART_UPPERCASE_BASQUE    */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_BASQUE,        /*  54  VM_INPUT_MODE_SMART_FIRST_UPPERCASE_BASQUE  */
    IMM_INPUT_MODE_MULTITAP_BENGALI,                    /*  55  VM_INPUT_MODE_MULTITAP_BENGALI      */
    IMM_INPUT_MODE_SMART_BENGALI,                       /*  56  VM_INPUT_MODE_SMART_BENGALI */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_BULGARIAN,        /*  57  VM_INPUT_MODE_MULTITAP_UPPERCASE_BULGARIAN      */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_BULGARIAN,        /*  58  VM_INPUT_MODE_MULTITAP_LOWERCASE_BULGARIAN  */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_BULGARIAN,  /*  59  VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_BULGARIAN    */
    IMM_INPUT_MODE_SMART_LOWERCASE_BULGARIAN,           /*  60  VM_INPUT_MODE_SMART_LOWERCASE_BULGARIAN */
    IMM_INPUT_MODE_SMART_UPPERCASE_BULGARIAN,           /*  61  VM_INPUT_MODE_SMART_UPPERCASE_BULGARIAN */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_BULGARIAN,     /*  62  VM_INPUT_MODE_SMART_FIRST_UPPERCASE_BULGARIAN   */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_CATALAN,          /*  63  VM_INPUT_MODE_MULTITAP_UPPERCASE_CATALAN    */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_CATALAN,          /*  64  VM_INPUT_MODE_MULTITAP_LOWERCASE_CATALAN    */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_CATALAN,    /*  65  VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_CATALAN  */
    IMM_INPUT_MODE_SMART_LOWERCASE_CATALAN,             /*  66  VM_INPUT_MODE_SMART_LOWERCASE_CATALAN   */
    IMM_INPUT_MODE_SMART_UPPERCASE_CATALAN,             /*  67  VM_INPUT_MODE_SMART_UPPERCASE_CATALAN   */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_CATALAN,       /*  68  VM_INPUT_MODE_SMART_FIRST_UPPERCASE_CATALAN */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_CROATIAN,         /*  69  VM_INPUT_MODE_MULTITAP_UPPERCASE_CROATIAN       */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_CROATIAN,         /*  70  VM_INPUT_MODE_MULTITAP_LOWERCASE_CROATIAN   */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_CROATIAN,   /*  71  VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_CROATIAN */
    IMM_INPUT_MODE_SMART_LOWERCASE_CROATIAN,            /*  72  VM_INPUT_MODE_SMART_LOWERCASE_CROATIAN  */
    IMM_INPUT_MODE_SMART_UPPERCASE_CROATIAN,            /*  73  VM_INPUT_MODE_SMART_UPPERCASE_CROATIAN  */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_CROATIAN,      /*  74  VM_INPUT_MODE_SMART_FIRST_UPPERCASE_CROATIAN    */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_CZECH,            /*  75  VM_INPUT_MODE_MULTITAP_UPPERCASE_CZECH      */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_CZECH,            /*  76  VM_INPUT_MODE_MULTITAP_LOWERCASE_CZECH  */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_CZECH,      /*  77  VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_CZECH    */
    IMM_INPUT_MODE_SMART_LOWERCASE_CZECH,               /*  78  VM_INPUT_MODE_SMART_LOWERCASE_CZECH */
    IMM_INPUT_MODE_SMART_UPPERCASE_CZECH,               /*  79  VM_INPUT_MODE_SMART_UPPERCASE_CZECH */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_CZECH,         /*  80  VM_INPUT_MODE_SMART_FIRST_UPPERCASE_CZECH   */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_DANISH,           /*  81  VM_INPUT_MODE_MULTITAP_UPPERCASE_DANISH     */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_DANISH,           /*  82  VM_INPUT_MODE_MULTITAP_LOWERCASE_DANISH */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_DANISH,     /*  83  VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_DANISH   */
    IMM_INPUT_MODE_SMART_LOWERCASE_DANISH,              /*  84  VM_INPUT_MODE_SMART_LOWERCASE_DANISH    */
    IMM_INPUT_MODE_SMART_UPPERCASE_DANISH,              /*  85  VM_INPUT_MODE_SMART_UPPERCASE_DANISH    */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_DANISH,        /*  86  VM_INPUT_MODE_SMART_FIRST_UPPERCASE_DANISH  */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_DUTCH,            /*  87  VM_INPUT_MODE_MULTITAP_UPPERCASE_DUTCH      */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_DUTCH,            /*  88  VM_INPUT_MODE_MULTITAP_LOWERCASE_DUTCH  */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_DUTCH,      /*  89  VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_DUTCH    */
    IMM_INPUT_MODE_SMART_LOWERCASE_DUTCH,               /*  90  VM_INPUT_MODE_SMART_LOWERCASE_DUTCH */
    IMM_INPUT_MODE_SMART_UPPERCASE_DUTCH,               /*  91  VM_INPUT_MODE_SMART_UPPERCASE_DUTCH */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_DUTCH,         /*  92  VM_INPUT_MODE_SMART_FIRST_UPPERCASE_DUTCH   */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ESTONIAN,         /*  93  VM_INPUT_MODE_MULTITAP_UPPERCASE_ESTONIAN       */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ESTONIAN,         /*  94  VM_INPUT_MODE_MULTITAP_LOWERCASE_ESTONIAN   */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ESTONIAN,   /*  95  VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ESTONIAN */
    IMM_INPUT_MODE_SMART_LOWERCASE_ESTONIAN,            /*  96  VM_INPUT_MODE_SMART_LOWERCASE_ESTONIAN  */
    IMM_INPUT_MODE_SMART_UPPERCASE_ESTONIAN,            /*  97  VM_INPUT_MODE_SMART_UPPERCASE_ESTONIAN  */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ESTONIAN,      /*  98  VM_INPUT_MODE_SMART_FIRST_UPPERCASE_ESTONIAN    */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_FILIPINO,         /*  99  VM_INPUT_MODE_MULTITAP_UPPERCASE_FILIPINO       */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_FILIPINO,         /*  100 VM_INPUT_MODE_MULTITAP_LOWERCASE_FILIPINO   */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_FILIPINO,   /*  101 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_FILIPINO */
    IMM_INPUT_MODE_SMART_LOWERCASE_FILIPINO,            /*  102 VM_INPUT_MODE_SMART_LOWERCASE_FILIPINO  */
    IMM_INPUT_MODE_SMART_UPPERCASE_FILIPINO,            /*  103 VM_INPUT_MODE_SMART_UPPERCASE_FILIPINO  */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_FILIPINO,      /*  104 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_FILIPINO    */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_FINNISH,          /*  105 VM_INPUT_MODE_MULTITAP_UPPERCASE_FINNISH    */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_FINNISH,          /*  106 VM_INPUT_MODE_MULTITAP_LOWERCASE_FINNISH    */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_FINNISH,    /*  107 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_FINNISH  */
    IMM_INPUT_MODE_SMART_LOWERCASE_FINNISH,             /*  108 VM_INPUT_MODE_SMART_LOWERCASE_FINNISH   */
    IMM_INPUT_MODE_SMART_UPPERCASE_FINNISH,             /*  109 VM_INPUT_MODE_SMART_UPPERCASE_FINNISH   */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_FINNISH,       /*  110 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_FINNISH */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_FRENCH,           /*  111 VM_INPUT_MODE_MULTITAP_UPPERCASE_FRENCH     */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_FRENCH,           /*  112 VM_INPUT_MODE_MULTITAP_LOWERCASE_FRENCH */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_FRENCH,     /*  113 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_FRENCH   */
    IMM_INPUT_MODE_SMART_LOWERCASE_FRENCH,              /*  114 VM_INPUT_MODE_SMART_LOWERCASE_FRENCH    */
    IMM_INPUT_MODE_SMART_UPPERCASE_FRENCH,              /*  115 VM_INPUT_MODE_SMART_UPPERCASE_FRENCH    */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_FRENCH,        /*  116 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_FRENCH  */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_GALICIAN,         /*  117 VM_INPUT_MODE_MULTITAP_UPPERCASE_GALICIAN       */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_GALICIAN,         /*  118 VM_INPUT_MODE_MULTITAP_LOWERCASE_GALICIAN   */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_GALICIAN,   /*  119 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_GALICIAN */
    IMM_INPUT_MODE_SMART_LOWERCASE_GALICIAN,            /*  120 VM_INPUT_MODE_SMART_LOWERCASE_GALICIAN  */
    IMM_INPUT_MODE_SMART_UPPERCASE_GALICIAN,            /*  121 VM_INPUT_MODE_SMART_UPPERCASE_GALICIAN  */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_GALICIAN,      /*  122 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_GALICIAN    */
    IMM_INPUT_MODE_MULTITAP_GEORGIAN,                   /*  123 VM_INPUT_MODE_MULTITAP_GEORGIAN     */
    IMM_INPUT_MODE_SMART_GEORGIAN,                      /*  124 VM_INPUT_MODE_SMART_GEORGIAN    */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_GERMAN,           /*  125 VM_INPUT_MODE_MULTITAP_UPPERCASE_GERMAN     */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_GERMAN,           /*  126 VM_INPUT_MODE_MULTITAP_LOWERCASE_GERMAN */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_GERMAN,     /*  127 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_GERMAN   */
    IMM_INPUT_MODE_SMART_LOWERCASE_GERMAN,              /*  128 VM_INPUT_MODE_SMART_LOWERCASE_GERMAN    */
    IMM_INPUT_MODE_SMART_UPPERCASE_GERMAN,              /*  129 VM_INPUT_MODE_SMART_UPPERCASE_GERMAN    */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_GERMAN,        /*  130 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_GERMAN  */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_GREEK,            /*  131 VM_INPUT_MODE_MULTITAP_UPPERCASE_GREEK      */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_GREEK,            /*  132 VM_INPUT_MODE_MULTITAP_LOWERCASE_GREEK  */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_GREEK,      /*  133 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_GREEK    */
    IMM_INPUT_MODE_SMART_LOWERCASE_GREEK,               /*  134 VM_INPUT_MODE_SMART_LOWERCASE_GREEK */
    IMM_INPUT_MODE_SMART_UPPERCASE_GREEK,               /*  135 VM_INPUT_MODE_SMART_UPPERCASE_GREEK */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_GREEK,         /*  136 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_GREEK   */
    IMM_INPUT_MODE_MULTITAP_GUJARATI,                   /*  137 VM_INPUT_MODE_MULTITAP_GUJARATI     */
    IMM_INPUT_MODE_SMART_GUJARATI,                      /*  138 VM_INPUT_MODE_SMART_GUJARATI    */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_HAUSA,            /*  139 VM_INPUT_MODE_MULTITAP_UPPERCASE_HAUSA      */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_HAUSA,            /*  140 VM_INPUT_MODE_MULTITAP_LOWERCASE_HAUSA  */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_HAUSA,      /*  141 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_HAUSA    */
    IMM_INPUT_MODE_SMART_LOWERCASE_HAUSA,               /*  142 VM_INPUT_MODE_SMART_LOWERCASE_HAUSA */
    IMM_INPUT_MODE_SMART_UPPERCASE_HAUSA,               /*  143 VM_INPUT_MODE_SMART_UPPERCASE_HAUSA */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_HAUSA,         /*  144 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_HAUSA   */
    IMM_INPUT_MODE_MULTITAP_HEBREW,                     /*  145 VM_INPUT_MODE_MULTITAP_HEBREW       */
    IMM_INPUT_MODE_SMART_HEBREW,                        /*  146 VM_INPUT_MODE_SMART_HEBREW  */
    IMM_INPUT_MODE_MULTITAP_HINDI,                      /*  147 VM_INPUT_MODE_MULTITAP_HINDI    */
    IMM_INPUT_MODE_SMART_HINDI,                         /*  148 VM_INPUT_MODE_SMART_HINDI   */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_HUNGARIAN,        /*  149 VM_INPUT_MODE_MULTITAP_UPPERCASE_HUNGARIAN      */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_HUNGARIAN,        /*  150 VM_INPUT_MODE_MULTITAP_LOWERCASE_HUNGARIAN  */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_HUNGARIAN,  /*  151 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_HUNGARIAN    */
    IMM_INPUT_MODE_SMART_LOWERCASE_HUNGARIAN,           /*  152 VM_INPUT_MODE_SMART_LOWERCASE_HUNGARIAN */
    IMM_INPUT_MODE_SMART_UPPERCASE_HUNGARIAN,           /*  153 VM_INPUT_MODE_SMART_UPPERCASE_HUNGARIAN */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_HUNGARIAN,     /*  154 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_HUNGARIAN   */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ICELANDIC,        /*  155 VM_INPUT_MODE_MULTITAP_UPPERCASE_ICELANDIC      */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ICELANDIC,        /*  156 VM_INPUT_MODE_MULTITAP_LOWERCASE_ICELANDIC  */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ICELANDIC,  /*  157 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ICELANDIC    */
    IMM_INPUT_MODE_SMART_LOWERCASE_ICELANDIC,           /*  158 VM_INPUT_MODE_SMART_LOWERCASE_ICELANDIC */
    IMM_INPUT_MODE_SMART_UPPERCASE_ICELANDIC,           /*  159 VM_INPUT_MODE_SMART_UPPERCASE_ICELANDIC */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ICELANDIC,     /*  160 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_ICELANDIC   */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_IGBO,             /*  161 VM_INPUT_MODE_MULTITAP_UPPERCASE_IGBO       */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_IGBO,             /*  162 VM_INPUT_MODE_MULTITAP_LOWERCASE_IGBO   */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_IGBO,       /*  163 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_IGBO */
    IMM_INPUT_MODE_SMART_LOWERCASE_IGBO,                /*  164 VM_INPUT_MODE_SMART_LOWERCASE_IGBO  */
    IMM_INPUT_MODE_SMART_UPPERCASE_IGBO,                /*  165 VM_INPUT_MODE_SMART_UPPERCASE_IGBO  */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_IGBO,          /*  166 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_IGBO    */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_INDONESIAN,       /*  167 VM_INPUT_MODE_MULTITAP_UPPERCASE_INDONESIAN     */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_INDONESIAN,       /*  168 VM_INPUT_MODE_MULTITAP_LOWERCASE_INDONESIAN */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_INDONESIAN, /*  169 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_INDONESIAN   */
    IMM_INPUT_MODE_SMART_LOWERCASE_INDONESIAN,          /*  170 VM_INPUT_MODE_SMART_LOWERCASE_INDONESIAN    */
    IMM_INPUT_MODE_SMART_UPPERCASE_INDONESIAN,          /*  171 VM_INPUT_MODE_SMART_UPPERCASE_INDONESIAN    */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_INDONESIAN,    /*  172 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_INDONESIAN  */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_IRISH,            /*  173 VM_INPUT_MODE_MULTITAP_UPPERCASE_IRISH      */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_IRISH,            /*  174 VM_INPUT_MODE_MULTITAP_LOWERCASE_IRISH  */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_IRISH,      /*  175 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_IRISH    */
    IMM_INPUT_MODE_SMART_LOWERCASE_IRISH,               /*  176 VM_INPUT_MODE_SMART_LOWERCASE_IRISH */
    IMM_INPUT_MODE_SMART_UPPERCASE_IRISH,               /*  177 VM_INPUT_MODE_SMART_UPPERCASE_IRISH */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_IRISH,         /*  178 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_IRISH   */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ITALIAN,          /*  179 VM_INPUT_MODE_MULTITAP_UPPERCASE_ITALIAN    */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ITALIAN,          /*  180 VM_INPUT_MODE_MULTITAP_LOWERCASE_ITALIAN    */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ITALIAN,    /*  181 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ITALIAN  */
    IMM_INPUT_MODE_SMART_LOWERCASE_ITALIAN,             /*  182 VM_INPUT_MODE_SMART_LOWERCASE_ITALIAN   */
    IMM_INPUT_MODE_SMART_UPPERCASE_ITALIAN,             /*  183 VM_INPUT_MODE_SMART_UPPERCASE_ITALIAN   */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ITALIAN,       /*  184 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_ITALIAN */
    IMM_INPUT_MODE_MULTITAP_KANNADA,                    /*  185 VM_INPUT_MODE_MULTITAP_KANNADA      */
    IMM_INPUT_MODE_SMART_KANNADA,                       /*  186 VM_INPUT_MODE_SMART_KANNADA */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_KAZAKH,           /*  187 VM_INPUT_MODE_MULTITAP_UPPERCASE_KAZAKH     */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_KAZAKH,           /*  188 VM_INPUT_MODE_MULTITAP_LOWERCASE_KAZAKH */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_KAZAKH,     /*  189 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_KAZAKH   */
    IMM_INPUT_MODE_SMART_LOWERCASE_KAZAKH,              /*  190 VM_INPUT_MODE_SMART_LOWERCASE_KAZAKH    */
    IMM_INPUT_MODE_SMART_UPPERCASE_KAZAKH,              /*  191 VM_INPUT_MODE_SMART_UPPERCASE_KAZAKH    */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_KAZAKH,        /*  192 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_KAZAKH  */
    IMM_INPUT_MODE_MULTITAP_KOREAN,                     /*  193 VM_INPUT_MODE_MULTITAP_KOREAN   */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_LATVIAN,          /*  194 VM_INPUT_MODE_MULTITAP_UPPERCASE_LATVIAN    */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_LATVIAN,          /*  195 VM_INPUT_MODE_MULTITAP_LOWERCASE_LATVIAN    */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_LATVIAN,    /*  196 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_LATVIAN  */
    IMM_INPUT_MODE_SMART_LOWERCASE_LATVIAN,             /*  197 VM_INPUT_MODE_SMART_LOWERCASE_LATVIAN   */
    IMM_INPUT_MODE_SMART_UPPERCASE_LATVIAN,             /*  198 VM_INPUT_MODE_SMART_UPPERCASE_LATVIAN   */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_LATVIAN,       /*  199 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_LATVIAN */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_LITHUANIAN,       /*  200 VM_INPUT_MODE_MULTITAP_UPPERCASE_LITHUANIAN     */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_LITHUANIAN,       /*  201 VM_INPUT_MODE_MULTITAP_LOWERCASE_LITHUANIAN */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_LITHUANIAN, /*  202 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_LITHUANIAN   */
    IMM_INPUT_MODE_SMART_LOWERCASE_LITHUANIAN,          /*  203 VM_INPUT_MODE_SMART_LOWERCASE_LITHUANIAN    */
    IMM_INPUT_MODE_SMART_UPPERCASE_LITHUANIAN,          /*  204 VM_INPUT_MODE_SMART_UPPERCASE_LITHUANIAN    */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_LITHUANIAN,    /*  205 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_LITHUANIAN  */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_MACEDONIAN,       /*  206 VM_INPUT_MODE_MULTITAP_UPPERCASE_MACEDONIAN     */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_MACEDONIAN,       /*  207 VM_INPUT_MODE_MULTITAP_LOWERCASE_MACEDONIAN */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_MACEDONIAN,     /*  208 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_MACEDONIAN   */
    IMM_INPUT_MODE_SMART_LOWERCASE_MACEDONIAN,          /*  209 VM_INPUT_MODE_SMART_LOWERCASE_MACEDONIAN    */
    IMM_INPUT_MODE_SMART_UPPERCASE_MACEDONIAN,          /*  210 VM_INPUT_MODE_SMART_UPPERCASE_MACEDONIAN    */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_MACEDONIAN,    /*  211 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_MACEDONIAN  */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_MALAY,            /*  212 VM_INPUT_MODE_MULTITAP_UPPERCASE_MALAY      */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_MALAY,            /*  213 VM_INPUT_MODE_MULTITAP_LOWERCASE_MALAY  */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_MALAY,      /*  214 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_MALAY    */
    IMM_INPUT_MODE_SMART_LOWERCASE_MALAY,               /*  215 VM_INPUT_MODE_SMART_LOWERCASE_MALAY */
    IMM_INPUT_MODE_SMART_UPPERCASE_MALAY,               /*  216 VM_INPUT_MODE_SMART_UPPERCASE_MALAY */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_MALAY,         /*  217 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_MALAY   */
    IMM_INPUT_MODE_MULTITAP_MALAYALAM,                  /*  218 VM_INPUT_MODE_MULTITAP_MALAYALAM    */
    IMM_INPUT_MODE_MULTITAP_LAO,                        /*  219 VM_INPUT_MODE_MULTITAP_LAO  */
    IMM_INPUT_MODE_MULTITAP_KHMER,                      /*  220 VM_INPUT_MODE_MULTITAP_KHMER    */
    IMM_INPUT_MODE_SMART_KHMER,                         /*  221 VM_INPUT_MODE_SMART_KHMER   */
    IMM_INPUT_MODE_MULTITAP_MYANMAR,                    /*  222 VM_INPUT_MODE_MULTITAP_MYANMAR  */
    IMM_INPUT_MODE_SMART_MALAYALAM,                     /*  223 VM_INPUT_MODE_SMART_MALAYALAM   */
    IMM_INPUT_MODE_MULTITAP_MARATHI,                    /*  224 VM_INPUT_MODE_MULTITAP_MARATHI      */
    IMM_INPUT_MODE_SMART_MARATHI,                       /*  225 VM_INPUT_MODE_SMART_MARATHI */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_MOLDOVAN,         /*  226 VM_INPUT_MODE_MULTITAP_UPPERCASE_MOLDOVAN       */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_MOLDOVAN,         /*  227 VM_INPUT_MODE_MULTITAP_LOWERCASE_MOLDOVAN   */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_MOLDOVAN,   /*  228 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_MOLDOVAN */
    IMM_INPUT_MODE_SMART_LOWERCASE_MOLDOVAN,            /*  229 VM_INPUT_MODE_SMART_LOWERCASE_MOLDOVAN  */
    IMM_INPUT_MODE_SMART_UPPERCASE_MOLDOVAN,            /*  230 VM_INPUT_MODE_SMART_UPPERCASE_MOLDOVAN  */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_MOLDOVAN,      /*  231 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_MOLDOVAN    */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_NORWEGIAN,        /*  232 VM_INPUT_MODE_MULTITAP_UPPERCASE_NORWEGIAN      */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_NORWEGIAN,        /*  233 VM_INPUT_MODE_MULTITAP_LOWERCASE_NORWEGIAN  */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_NORWEGIAN,  /*  234 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_NORWEGIAN    */
    IMM_INPUT_MODE_SMART_LOWERCASE_NORWEGIAN,           /*  235 VM_INPUT_MODE_SMART_LOWERCASE_NORWEGIAN */
    IMM_INPUT_MODE_SMART_UPPERCASE_NORWEGIAN,           /*  236 VM_INPUT_MODE_SMART_UPPERCASE_NORWEGIAN */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_NORWEGIAN,     /*  237 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_NORWEGIAN   */
    IMM_INPUT_MODE_MULTITAP_ORIYA,                      /*  238 VM_INPUT_MODE_MULTITAP_ORIYA    */
    IMM_INPUT_MODE_SMART_ORIYA,                         /*  239 VM_INPUT_MODE_SMART_ORIYA   */
    IMM_INPUT_MODE_MULTITAP_PERSIAN,                    /*  240 VM_INPUT_MODE_MULTITAP_PERSIAN      */
    IMM_INPUT_MODE_SMART_PERSIAN,                       /*  241 VM_INPUT_MODE_SMART_PERSIAN */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_POLISH,           /*  242 VM_INPUT_MODE_MULTITAP_UPPERCASE_POLISH     */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_POLISH,           /*  243 VM_INPUT_MODE_MULTITAP_LOWERCASE_POLISH */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_POLISH,     /*  244 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_POLISH   */
    IMM_INPUT_MODE_SMART_LOWERCASE_POLISH,              /*  245 VM_INPUT_MODE_SMART_LOWERCASE_POLISH    */
    IMM_INPUT_MODE_SMART_UPPERCASE_POLISH,              /*  246 VM_INPUT_MODE_SMART_UPPERCASE_POLISH    */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_POLISH,        /*  247 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_POLISH  */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_PORTUGUESE,       /*  248 VM_INPUT_MODE_MULTITAP_UPPERCASE_PORTUGUESE     */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_PORTUGUESE,       /*  249 VM_INPUT_MODE_MULTITAP_LOWERCASE_PORTUGUESE */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_PORTUGUESE, /*  250 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_PORTUGUESE   */
    IMM_INPUT_MODE_SMART_LOWERCASE_PORTUGUESE,          /*  251 VM_INPUT_MODE_SMART_LOWERCASE_PORTUGUESE    */
    IMM_INPUT_MODE_SMART_UPPERCASE_PORTUGUESE,          /*  252 VM_INPUT_MODE_SMART_UPPERCASE_PORTUGUESE    */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_PORTUGUESE,    /*  253 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_PORTUGUESE  */
    IMM_INPUT_MODE_MULTITAP_PUNJABI,                    /*  254 VM_INPUT_MODE_MULTITAP_PUNJABI      */
    IMM_INPUT_MODE_SMART_PUNJABI,                       /*  255 VM_INPUT_MODE_SMART_PUNJABI */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ROMANIAN,         /*  256 VM_INPUT_MODE_MULTITAP_UPPERCASE_ROMANIAN       */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ROMANIAN,         /*  257 VM_INPUT_MODE_MULTITAP_LOWERCASE_ROMANIAN   */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ROMANIAN,   /*  258 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ROMANIAN */
    IMM_INPUT_MODE_SMART_LOWERCASE_ROMANIAN,            /*  259 VM_INPUT_MODE_SMART_LOWERCASE_ROMANIAN  */
    IMM_INPUT_MODE_SMART_UPPERCASE_ROMANIAN,            /*  260 VM_INPUT_MODE_SMART_UPPERCASE_ROMANIAN  */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ROMANIAN,      /*  261 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_ROMANIAN    */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_RUSSIAN,          /*  262 VM_INPUT_MODE_MULTITAP_UPPERCASE_RUSSIAN    */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_RUSSIAN,          /*  263 VM_INPUT_MODE_MULTITAP_LOWERCASE_RUSSIAN    */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_RUSSIAN,    /*  264 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_RUSSIAN  */
    IMM_INPUT_MODE_SMART_LOWERCASE_RUSSIAN,             /*  265 VM_INPUT_MODE_SMART_LOWERCASE_RUSSIAN   */
    IMM_INPUT_MODE_SMART_UPPERCASE_RUSSIAN,             /*  266 VM_INPUT_MODE_SMART_UPPERCASE_RUSSIAN   */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_RUSSIAN,       /*  267 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_RUSSIAN */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SERBIAN,          /*  268 VM_INPUT_MODE_MULTITAP_UPPERCASE_SERBIAN    */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SERBIAN,          /*  269 VM_INPUT_MODE_MULTITAP_LOWERCASE_SERBIAN    */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SERBIAN,    /*  270 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SERBIAN  */
    IMM_INPUT_MODE_SMART_LOWERCASE_SERBIAN,             /*  271 VM_INPUT_MODE_SMART_LOWERCASE_SERBIAN   */
    IMM_INPUT_MODE_SMART_UPPERCASE_SERBIAN,             /*  272 VM_INPUT_MODE_SMART_UPPERCASE_SERBIAN   */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SERBIAN,       /*  273 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_SERBIAN */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SESOTHO,          /*  274 VM_INPUT_MODE_MULTITAP_UPPERCASE_SESOTHO    */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SESOTHO,          /*  275 VM_INPUT_MODE_MULTITAP_LOWERCASE_SESOTHO    */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SESOTHO,    /*  276 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SESOTHO  */
    IMM_INPUT_MODE_SMART_LOWERCASE_SESOTHO,             /*  277 VM_INPUT_MODE_SMART_LOWERCASE_SESOTHO   */
    IMM_INPUT_MODE_SMART_UPPERCASE_SESOTHO,             /*  278 VM_INPUT_MODE_SMART_UPPERCASE_SESOTHO   */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SESOTHO,       /*  279 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_SESOTHO */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SLOVAK,           /*  280 VM_INPUT_MODE_MULTITAP_UPPERCASE_SLOVAK     */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SLOVAK,           /*  281 VM_INPUT_MODE_MULTITAP_LOWERCASE_SLOVAK */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SLOVAK,     /*  282 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SLOVAK   */
    IMM_INPUT_MODE_SMART_LOWERCASE_SLOVAK,              /*  283 VM_INPUT_MODE_SMART_LOWERCASE_SLOVAK    */
    IMM_INPUT_MODE_SMART_UPPERCASE_SLOVAK,              /*  284 VM_INPUT_MODE_SMART_UPPERCASE_SLOVAK    */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SLOVAK,        /*  285 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_SLOVAK  */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SLOVENIAN,        /*  286 VM_INPUT_MODE_MULTITAP_UPPERCASE_SLOVENIAN      */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SLOVENIAN,        /*  287 VM_INPUT_MODE_MULTITAP_LOWERCASE_SLOVENIAN  */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SLOVENIAN,  /*  288 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SLOVENIAN    */
    IMM_INPUT_MODE_SMART_LOWERCASE_SLOVENIAN,           /*  289 VM_INPUT_MODE_SMART_LOWERCASE_SLOVENIAN */
    IMM_INPUT_MODE_SMART_UPPERCASE_SLOVENIAN,           /*  290 VM_INPUT_MODE_SMART_UPPERCASE_SLOVENIAN */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SLOVENIAN,     /*  291 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_SLOVENIAN   */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SPANISH,          /*  292 VM_INPUT_MODE_MULTITAP_UPPERCASE_SPANISH    */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SPANISH,          /*  293 VM_INPUT_MODE_MULTITAP_LOWERCASE_SPANISH    */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SPANISH,    /*  294 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SPANISH  */
    IMM_INPUT_MODE_SMART_LOWERCASE_SPANISH,             /*  295 VM_INPUT_MODE_SMART_LOWERCASE_SPANISH   */
    IMM_INPUT_MODE_SMART_UPPERCASE_SPANISH,             /*  296 VM_INPUT_MODE_SMART_UPPERCASE_SPANISH   */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SPANISH,       /*  297 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_SPANISH */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SWAHILI,          /*  298 VM_INPUT_MODE_MULTITAP_UPPERCASE_SWAHILI    */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SWAHILI,          /*  299 VM_INPUT_MODE_MULTITAP_LOWERCASE_SWAHILI    */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SWAHILI,    /*  300 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SWAHILI  */
    IMM_INPUT_MODE_SMART_LOWERCASE_SWAHILI,             /*  301 VM_INPUT_MODE_SMART_LOWERCASE_SWAHILI   */
    IMM_INPUT_MODE_SMART_UPPERCASE_SWAHILI,             /*  302 VM_INPUT_MODE_SMART_UPPERCASE_SWAHILI   */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SWAHILI,       /*  303 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_SWAHILI */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_SWEDISH,          /*  304 VM_INPUT_MODE_MULTITAP_UPPERCASE_SWEDISH    */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_SWEDISH,          /*  305 VM_INPUT_MODE_MULTITAP_LOWERCASE_SWEDISH    */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SWEDISH,    /*  306 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_SWEDISH  */
    IMM_INPUT_MODE_SMART_LOWERCASE_SWEDISH,             /*  307 VM_INPUT_MODE_SMART_LOWERCASE_SWEDISH   */
    IMM_INPUT_MODE_SMART_UPPERCASE_SWEDISH,             /*  308 VM_INPUT_MODE_SMART_UPPERCASE_SWEDISH   */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SWEDISH,       /*  309 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_SWEDISH */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_TAGALOG,          /*  310 VM_INPUT_MODE_MULTITAP_UPPERCASE_TAGALOG    */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_TAGALOG,          /*  311 VM_INPUT_MODE_MULTITAP_LOWERCASE_TAGALOG    */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_TAGALOG,    /*  312 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_TAGALOG  */
    IMM_INPUT_MODE_SMART_LOWERCASE_TAGALOG,             /*  313 VM_INPUT_MODE_SMART_LOWERCASE_TAGALOG   */
    IMM_INPUT_MODE_SMART_UPPERCASE_TAGALOG,             /*  314 VM_INPUT_MODE_SMART_UPPERCASE_TAGALOG   */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_TAGALOG,       /*  315 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_TAGALOG */
    IMM_INPUT_MODE_MULTITAP_TAMIL,                      /*  316 VM_INPUT_MODE_MULTITAP_TAMIL    */
    IMM_INPUT_MODE_SMART_TAMIL,                         /*  317 VM_INPUT_MODE_SMART_TAMIL   */
    IMM_INPUT_MODE_MULTITAP_TELUGU,                     /*  318 VM_INPUT_MODE_MULTITAP_TELUGU       */
    IMM_INPUT_MODE_SMART_TELUGU,                        /*  319 VM_INPUT_MODE_SMART_TELUGU  */
    IMM_INPUT_MODE_MULTITAP_THAI,                       /*  320 VM_INPUT_MODE_MULTITAP_THAI     */
    IMM_INPUT_MODE_SMART_THAI,                          /*  321 VM_INPUT_MODE_SMART_THAI    */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_TURKISH,          /*  322 VM_INPUT_MODE_MULTITAP_UPPERCASE_TURKISH    */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_TURKISH,          /*  323 VM_INPUT_MODE_MULTITAP_LOWERCASE_TURKISH    */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_TURKISH,    /*  324 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_TURKISH  */
    IMM_INPUT_MODE_SMART_LOWERCASE_TURKISH,             /*  325 VM_INPUT_MODE_SMART_LOWERCASE_TURKISH   */
    IMM_INPUT_MODE_SMART_UPPERCASE_TURKISH,             /*  326 VM_INPUT_MODE_SMART_UPPERCASE_TURKISH   */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_TURKISH,       /*  327 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_TURKISH */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_UKRAINIAN,        /*  328 VM_INPUT_MODE_MULTITAP_UPPERCASE_UKRAINIAN      */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_UKRAINIAN,        /*  329 VM_INPUT_MODE_MULTITAP_LOWERCASE_UKRAINIAN  */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_UKRAINIAN,  /*  330 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_UKRAINIAN    */
    IMM_INPUT_MODE_SMART_LOWERCASE_UKRAINIAN,           /*  331 VM_INPUT_MODE_SMART_LOWERCASE_UKRAINIAN */
    IMM_INPUT_MODE_SMART_UPPERCASE_UKRAINIAN,           /*  332 VM_INPUT_MODE_SMART_UPPERCASE_UKRAINIAN */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_UKRAINIAN,     /*  333 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_UKRAINIAN   */
    IMM_INPUT_MODE_MULTITAP_URDU,                       /*  334 VM_INPUT_MODE_MULTITAP_URDU     */
    IMM_INPUT_MODE_SMART_URDU,                          /*  335 VM_INPUT_MODE_SMART_URDU    */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_VIETNAMESE,       /*  336 VM_INPUT_MODE_MULTITAP_UPPERCASE_VIETNAMESE     */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_VIETNAMESE,       /*  337 VM_INPUT_MODE_MULTITAP_LOWERCASE_VIETNAMESE */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_VIETNAMESE, /*  338 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_VIETNAMESE   */
    IMM_INPUT_MODE_SMART_LOWERCASE_VIETNAMESE,          /*  339 VM_INPUT_MODE_SMART_LOWERCASE_VIETNAMESE    */
    IMM_INPUT_MODE_SMART_UPPERCASE_VIETNAMESE,          /*  340 VM_INPUT_MODE_SMART_UPPERCASE_VIETNAMESE    */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_VIETNAMESE,    /*  341 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_VIETNAMESE  */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_XHOSA,            /*  342 VM_INPUT_MODE_MULTITAP_UPPERCASE_XHOSA      */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_XHOSA,            /*  343 VM_INPUT_MODE_MULTITAP_LOWERCASE_XHOSA  */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_XHOSA,      /*  344 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_XHOSA    */
    IMM_INPUT_MODE_SMART_LOWERCASE_XHOSA,               /*  345 VM_INPUT_MODE_SMART_LOWERCASE_XHOSA */
    IMM_INPUT_MODE_SMART_UPPERCASE_XHOSA,               /*  346 VM_INPUT_MODE_SMART_UPPERCASE_XHOSA */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_XHOSA,         /*  347 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_XHOSA   */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_YORUBA,           /*  348 VM_INPUT_MODE_MULTITAP_UPPERCASE_YORUBA     */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_YORUBA,           /*  349 VM_INPUT_MODE_MULTITAP_LOWERCASE_YORUBA */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_YORUBA,     /*  350 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_YORUBA   */
    IMM_INPUT_MODE_SMART_LOWERCASE_YORUBA,              /*  351 VM_INPUT_MODE_SMART_LOWERCASE_YORUBA    */
    IMM_INPUT_MODE_SMART_UPPERCASE_YORUBA,              /*  352 VM_INPUT_MODE_SMART_UPPERCASE_YORUBA    */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_YORUBA,        /*  353 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_YORUBA  */
    IMM_INPUT_MODE_MULTITAP_UPPERCASE_ZULU,             /*  354 VM_INPUT_MODE_MULTITAP_UPPERCASE_ZULU       */
    IMM_INPUT_MODE_MULTITAP_LOWERCASE_ZULU,             /*  355 VM_INPUT_MODE_MULTITAP_LOWERCASE_ZULU   */
    IMM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ZULU,       /*  356 VM_INPUT_MODE_MULTITAP_FIRST_UPPERCASE_ZULU */
    IMM_INPUT_MODE_SMART_LOWERCASE_ZULU,                /*  357 VM_INPUT_MODE_SMART_LOWERCASE_ZULU  */
    IMM_INPUT_MODE_SMART_UPPERCASE_ZULU,                /*  358 VM_INPUT_MODE_SMART_UPPERCASE_ZULU  */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_ZULU,          /*  359 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_ZULU    */
    IMM_INPUT_MODE_SMART_UPPERCASE_UK_ABC,              /*  360 VM_INPUT_MODE_SMART_UPPERCASE_UK_ABC    */
    IMM_INPUT_MODE_SMART_LOWERCASE_UK_ABC,              /*  361 VM_INPUT_MODE_SMART_LOWERCASE_UK_ABC    */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_UK_ABC,        /*  362 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_UK_ABC  */
    IMM_INPUT_MODE_SMART_UPPERCASE_CA_FRENCH,           /*  363 VM_INPUT_MODE_SMART_UPPERCASE_CA_FRENCH */
    IMM_INPUT_MODE_SMART_LOWERCASE_CA_FRENCH,           /*  364 VM_INPUT_MODE_SMART_LOWERCASE_CA_FRENCH */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_CA_FRENCH,     /*  365 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_CA_FRENCH   */
    IMM_INPUT_MODE_SMART_UPPERCASE_HINGLISH,            /*  366 VM_INPUT_MODE_SMART_UPPERCASE_HINGLISH  */
    IMM_INPUT_MODE_SMART_LOWERCASE_HINGLISH,            /*  367 VM_INPUT_MODE_SMART_LOWERCASE_HINGLISH  */
    IMM_INPUT_MODE_SMART_UPPERCASE_SA_SPANISH,          /*  368 VM_INPUT_MODE_SMART_UPPERCASE_SA_SPANISH    */
    IMM_INPUT_MODE_SMART_LOWERCASE_SA_SPANISH,          /*  369 VM_INPUT_MODE_SMART_LOWERCASE_SA_SPANISH    */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SA_SPANISH,    /*  370 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_SA_SPANISH  */
    IMM_INPUT_MODE_SMART_UPPERCASE_SA_PORTUGUESE,       /*  371 VM_INPUT_MODE_SMART_UPPERCASE_SA_PORTUGUESE */
    IMM_INPUT_MODE_SMART_LOWERCASE_SA_PORTUGUESE,       /*  372 VM_INPUT_MODE_SMART_LOWERCASE_SA_PORTUGUESE */
    IMM_INPUT_MODE_SMART_FIRST_UPPERCASE_SA_PORTUGUESE, /*  373 VM_INPUT_MODE_SMART_FIRST_UPPERCASE_SA_PORTUGUESE   */
    IMM_INPUT_MODE_TR_BOPOMO,                           /*  374 VM_INPUT_MODE_TR_BOPOMO */
    IMM_INPUT_MODE_TR_MULTITAP_BOPOMO,                  /*  375 VM_INPUT_MODE_TR_MULTITAP_BOPOMO    */
    IMM_INPUT_MODE_TR_STROKE,                           /*  376 VM_INPUT_MODE_TR_STROKE */
    IMM_INPUT_MODE_QUICK_SEARCH_BOPOMO,                 /*  377 VM_INPUT_MODE_QUICK_SEARCH_BOPOMO   */
    IMM_INPUT_MODE_QUICK_SEARCH_HK_STROKE,              /*  378 VM_INPUT_MODE_QUICK_SEARCH_HK_STROKE    */
    IMM_INPUT_MODE_QUICK_SEARCH_PINYIN,                 /*  379 VM_INPUT_MODE_QUICK_SEARCH_PINYIN   */
    IMM_INPUT_MODE_QUICK_SEARCH_SM_STROKE,              /*  380 VM_INPUT_MODE_QUICK_SEARCH_SM_STROKE    */
    IMM_INPUT_MODE_QUICK_SEARCH_TR_STROKE,              /*  381 VM_INPUT_MODE_QUICK_SEARCH_TR_STROKE    */
    IMM_INPUT_MODE_SM_MULTITAP_PINYIN,                  /*  382 VM_INPUT_MODE_SM_MULTITAP_PINYIN    */
    IMM_INPUT_MODE_SM_PINYIN,                           /*  383 VM_INPUT_MODE_SM_PINYIN */
    IMM_INPUT_MODE_SM_STROKE,                           /*  384 VM_INPUT_MODE_SM_STROKE */
    IMM_INPUT_MODE_MAX_NUM                              /*  385 VM_INPUT_MODE_MAX_NUM   */
};

mmi_imm_input_mode_enum vm_editor_input_mode_mapping_func(
    vm_input_mode_enum vm_input_mode)
{
    if (vm_input_mode >= VM_INPUT_MODE_NONE 
        && vm_input_mode <= VM_INPUT_MODE_MAX_NUM)
    {
        return (mmi_imm_input_mode_enum) input_mode_list[vm_input_mode];
    }
    else
    {
        return VM_INPUT_MODE_NONE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  vm_set_app_desired_input_mode
 * DESCRIPTION
 *  To set editor desired input mode. Used when App call 
 *  vm_input_text/vm_input_text2/vm_input_text3 to enter editor screen.
 * PARAMETERS
 *  desired_input_mode : [IN] input mode.
 * RETURN VALUES
 *  void
 *****************************************************************************/
void vm_set_app_desired_input_mode(vm_input_mode_enum desired_input_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (desired_input_mode == VM_INPUT_MODE_NONE 
        || desired_input_mode >= VM_INPUT_MODE_MAX_NUM)
    {
        return;
    }

    g_vm_input_mode = vm_editor_input_mode_mapping_func(desired_input_mode);
}

/*****************************************************************************
 * FUNCTION
 *  vm_input_close_screen
 * DESCRIPTION
 *  Close input screen by application self. And it will send VM_INPUT_CLOSE to 
 *  application.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
void vm_input_close_screen(void)
{
    do_input_ok_cancel_close_internal(VM_INPUT_CLOSE);
}

/*****************************************************************************
 * FUNCTION
 *  vm_input_move_cursor_to_start
 * DESCRIPTION
 *  Move the cursor to the start position and edit from the beginning.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
void vm_input_move_cursor_to_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_inputs_ml_move_cursor_to_start();
    wgui_inputs_ml_redraw();
}

/*****************************************************************************
 * FUNCTION
 *  vm_input_set_vk_default_enlarge
 * DESCRIPTION
 *  Set VK default enlarge.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
void vm_input_set_vk_default_enlarge(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if defined(__MMI_IME_FTE_ENHANCE__)
        mmi_imc_set_vk_present(MMI_IMC_VK_DEFAULT_ENLARGE);
    #endif
}

/******************************************************************************
 * FUNCTION
 *   vm_input_set_editor_title
 * DESCRIPTION
 *   set the input editor title
 * PARAMETERS
 *   title:  [IN]    editor title provided by user
 * RETURN VALUES
 *   TRUE:   if set the editor title successfully.
 *   FALSE:  if fail to set the editor title.
 * NOTICE
 *   If you want to show your own title on the editor screen, you must call this
 *   function just before calling vm_input_text, vm_input_text2, or 
 *   vm_input_text3.
 *****************************************************************************/
VMINT vm_input_set_editor_title(VMWSTR title)
{
    if (title != NULL)
    {
        vm_wstrcpy(g_vm_editor_title, title);
        g_vm_editor_title_is_user_provided = TRUE;
    }
    else 
    {
        g_vm_editor_title_is_user_provided = FALSE;
    }

    return g_vm_editor_title_is_user_provided;
}

#ifndef __COSMOS_MMI_PACKAGE__
#include "AMGprot.h"
/*****************************************************************************
 *
 * The code bellow is for MRE Calculator
 *
 *****************************************************************************/
#ifdef __MMI_MRE_CALCULATOR__
/*****************************************************************************
 * FUNCTION
 *  CalcPreEntryApp
 * DESCRIPTION
 *  Initialize data before entry calculator.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CalcPreEntryApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_am_start_from_mm(APPID_CALCULATOR);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightCalcMenu
 * DESCRIPTION
 *  Highlight handler of Calculator menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightCalcMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(CalcPreEntryApp, KEY_EVENT_UP);
    SetKeyHandler(CalcPreEntryApp, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}
#endif /* __MMI_MRE_CALCULATOR__ */ 

/*****************************************************************************
 *
 * The code bellow is for MRE Worldclock
 *
 *****************************************************************************/
#if defined(__MMI_MRE_WORLD_CLOCK__)
#include "worldclock.h"
#include "worldclockResdef.h"
#include "PhoneSetup.h"

extern wc_context_struct g_wc_cntx;

extern PHNSET_CNTX g_phnset_cntx;
extern U8 PhnsetGetHomeCity(void);
extern U8 PhnsetGetForeignCity(void);
extern U8 PhnsetGetDateSeperatorFormat(void);
extern U8 PhnsetGetDateFormat(void);
extern U8 PhnsetGetTimeFormat(void);
extern BOOL ATSetHomeCity(U8 CityIndex);
extern void PhnsetSetHomeCity(void);

#ifdef __MMI_DUAL_CLOCK__
extern void PhnsetSetForeignCity(void);
#endif 
#ifdef __MMI_WC_TZ_SUPPORT__
extern U8 mmi_wc_entry_from_phnset(void);
extern U8 Cat230HighlightedIndex;
#endif 

static MMI_BOOL wc_sel_scrn = MMI_FALSE;    /* It is flag of phone setting select the worldclock */

/*****************************************************************************
 * FUNCTION
 *  vm_get_phoneset_info
 * DESCRIPTION
 *  Get the phone setup information
 * PARAMETERS
 *  phnset_info     [IN]        Phone setup information
 * RETURNS
 *  void
 *****************************************************************************/
void vm_get_phoneset_info(vm_phoneset_info_struct *phnset_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U8 foreign_index = 0, wc_dst = 0, setting_dt_dst = 0;
    U16 timezone = 0, frn_timezone = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(phnset_info, 0x00, sizeof(vm_phoneset_info_struct));

    /* Get current home city index */
    phnset_info->home_city = PhnsetGetHomeCity();
    //MMI_MRE_APP_TRACE("[Worldclock]get home_city = %d", phnset_info->home_city);

    #ifdef __MMI_DUAL_CLOCK__
        /* Get current foreign city index */
        phnset_info->foreign_city = PhnsetGetForeignCity();
        //MMI_MRE_APP_TRACE("[Worldclock]get foreign_city = %d", phnset_info->foreign_city);
    #endif /* __MMI_DUAL_CLOCK__ */ 

    /* Get the seperator of current date */
    phnset_info->date_seperator = PhnsetGetDateSeperatorFormat();

    /* Get the current format of date */
    phnset_info->date_format = PhnsetGetDateFormat();

    /* Get the current format of time */
    phnset_info->time_format = PhnsetGetTimeFormat();

    /* Get the current city daylight saving time */
    phnset_info->current_dst = g_phnset_cntx.currentDST;
    //MMI_MRE_APP_TRACE("[Worldclock]get current_dst = %d", phnset_info->current_dst);

    /* Get the current city index */
    phnset_info->current_city = g_wc_cntx.CurrCityIndex;
    //MMI_MRE_APP_TRACE("[Worldclock]get current_city = %d", phnset_info->current_city);

    #ifdef __MMI_WC_TZ_SUPPORT__
        /* Get the current time zone */
        phnset_info->current_timezone = g_wc_cntx.CurrTZ;
    #endif /* __MMI_WC_TZ_SUPPORT__ */ 
    
        /* read the nvram value */
    #ifdef __MMI_WORLDCLOCK_DST__
        ReadValue(NVRAM_WC_DST, &wc_dst, DS_BYTE, &error);
    #endif 
        ReadValue(NVRAM_SETTING_DT_DST, &setting_dt_dst, DS_BYTE, &error);
    #ifdef __MMI_WC_TZ_SUPPORT__
        ReadValue(FOREIGN_CITY, &foreign_index, DS_BYTE, &error);
        ReadValue(NVRAM_TIMEZONE, &timezone, DS_SHORT, &error);
    #endif /* __MMI_WC_TZ_SUPPORT__ */ 
    #ifdef __MMI_DUAL_CLOCK__
        ReadValue(NVRAM_FRN_TIMEZONE, &frn_timezone, DS_SHORT, &error);
    #endif 

    phnset_info->foreign_index = foreign_index;
    phnset_info->wc_dst = wc_dst;
    phnset_info->setting_dt_dst = setting_dt_dst;
    phnset_info->timezone = timezone;
    phnset_info->frn_timezone = frn_timezone;

    #ifdef __MMI_WC_TZ_SUPPORT__
        /* Get the wc entry screen */
        if (MMI_TRUE == wc_sel_scrn)
        {
            phnset_info->wc_entry_screen = mmi_wc_entry_from_phnset();
            wc_sel_scrn = MMI_FALSE;    /* reset the entry screen flag */
        }
        //MMI_MRE_APP_TRACE("[Worldclock]get wc_entry_screen = %d", phnset_info->wc_entry_screen);
    #endif /* __MMI_WC_TZ_SUPPORT__ */ 

    /* Set the timezone and city match default */
    phnset_info->tz_city_match = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  vm_set_phoneset_info
 * DESCRIPTION
 *  Set the information to phonse setup
 * PARAMETERS
 *  phnset_info     [IN]        Phone setup information
 * RETURNS
 *  void
 *****************************************************************************/
void vm_set_phoneset_info(vm_phoneset_info_struct *phnset_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U8 wc_dst = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check the timezone and city is match or not */
    if (MMI_FALSE == phnset_info->tz_city_match)
    {
        ATSetHomeCity((VMUINT8) phnset_info->current_city + 1);
        //MMI_MRE_APP_TRACE("[Worldclock]ATSetHomeCity current_city = %d", phnset_info->current_city);
    }

    /* Set current city index */
    g_wc_cntx.CurrCityIndex = phnset_info->current_city;
    //MMI_MRE_APP_TRACE("[Worldclock]set current_city = %d", phnset_info->current_city);

    #ifdef __MMI_WC_TZ_SUPPORT__
        /* Set the current time zone */
        g_wc_cntx.CurrTZ = phnset_info->current_timezone;
    #endif /* __MMI_WC_TZ_SUPPORT__ */ 

    /* This function is to set the home city, the app should be launched from setting. */
    if (0xFF != phnset_info->current_city)
    {
        //MMI_MRE_APP_TRACE("[Worldclock]vm_set_phoneset_info wc_entry_screen = %d", phnset_info->wc_entry_screen);
        if (1 == phnset_info->wc_entry_screen)
        {
            PhnsetSetHomeCity();
        }
        else if (2 == phnset_info->wc_entry_screen)
        {
            #ifdef __MMI_DUAL_CLOCK__
                        PhnsetSetForeignCity();
            #endif 
        }
    }

    /* save the setting information to the nvram value */
    #ifdef __MMI_WORLDCLOCK_DST__
        wc_dst = phnset_info->wc_dst;
        WriteValue(NVRAM_WC_DST, &wc_dst, DS_BYTE, &error);
    #endif /* __MMI_WORLDCLOCK_DST__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  EntryWcBrowseCity
 * DESCRIPTION
 *  Display browse city screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryWcBrowseCity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wc_sel_scrn = MMI_FALSE;    /* entry from the Organizer */
    mmi_am_start_from_mm(APPID_WORLDCLOCK);
}


/*****************************************************************************
 * FUNCTION
 *  EntryWcBrowseCityEx
 * DESCRIPTION
 *  Display browse city screen
 * PARAMETERS
 *  entry_func      [IN]        
 *  exit_func       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EntryWcBrowseCityEx(void (*entry_func)(void), void (*exit_func)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_am_start_from_mm(APPID_WORLDCLOCK);
}

/*****************************************************************************
 * FUNCTION
 *  HighlightWCMenu
 * DESCRIPTION
 *  Highlight handler of World Clock menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightWCMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_DUAL_CLOCK__
        g_phnset_cntx_p->city_flag = 2;
    #endif 
    
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    #if defined(__MMI_WORLD_CLOCK_SUBLCD_SETTING__)
        SetKeyHandler(EntryWcApp, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetLeftSoftkeyFunction(EntryWcApp, KEY_EVENT_UP);
    #else /* defined(__MMI_WORLD_CLOCK_SUBLCD_SETTING__) */ 
        SetLeftSoftkeyFunction(EntryWcBrowseCity, KEY_EVENT_UP);
        SetKeyHandler(EntryWcBrowseCity, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    #endif /* defined(__MMI_WORLD_CLOCK_SUBLCD_SETTING__) */ 
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  HighlightWcBrowseCity
 * DESCRIPTION
 *  Highlight handler of browse city menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightWcBrowseCity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_DUAL_CLOCK__
        g_phnset_cntx_p->city_flag = 2;
    #endif 

    SetLeftSoftkeyFunction(EntryWcBrowseCity, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wc_get_index_info
 * DESCRIPTION
 *  This function is used to get the index information.
 * PARAMETERS
 *  index_info     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wc_get_index_info(void *index_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wc_get_foreign_city_dt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dt     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wc_get_foreign_city_dt(MYTIME *dt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME incTime;
    U8 HomeCity;
    FLOAT TimeDiff;
    U8 TimeFlag = 0;
    S32 temp;

    #ifdef __MMI_WORLDCLOCK_DST__
        MYTIME dstTime;
    #endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get time zone difference */
    HomeCity = PhnsetGetHomeCity() + 1;
    /* TimeDiff = WcTimeZoneDiff(g_wc_cntx.CurrCityIndex, HomeCity); */
    TimeDiff = g_wc_cntx.CurrTZ - TimeZoneData[HomeCity].CityTimeZone;

    memset(&incTime, 0, sizeof(MYTIME));
    DTGetRTCTime(dt);

    if (TimeDiff < 0)
    {
        TimeDiff = TimeDiff * (-1);
        TimeFlag = 1;
    }

    temp = (S32) (TimeDiff * 60);

    incTime.nDay = (U8) (TimeDiff / 24);
    incTime.nHour = ((S32) TimeDiff) % 24;
    incTime.nMin = temp % 60;

    if (TimeFlag)   /* decrement */
    {
        DecrementTime(*dt, incTime, dt);
    }
    else
    {
        IncrementTime(*dt, incTime, dt);
    }

    #ifdef __MMI_WORLDCLOCK_DST__
        memset(&dstTime, 0, sizeof(MYTIME));
        dstTime.nHour = 1;
        /* both date light saving is on or off */
        if ((g_wc_cntx.DSTForeign && g_phnset_cntx_p->currentDST) ||
            (g_wc_cntx.DSTForeign == 0 && g_phnset_cntx_p->currentDST == 0) || (g_wc_cntx.CurrCityIndex == HomeCity))
        {
            /* do nothing */
        }
        else if (g_phnset_cntx_p->currentDST)   /* only home city turns on DST */
        {
            DecrementTime(*dt, dstTime, dt);
        }
        else if (g_wc_cntx.DSTForeign)  /* only foreign city turns on DST */
        {
            IncrementTime(*dt, dstTime, dt);
        }
    #endif /* __MMI_WORLDCLOCK_DST__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wc_leftkey_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index_num       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wc_leftkey_handler(U8 index_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wc_rightkey_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index_num       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wc_rightkey_handler(U8 index_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_wc_paint_pen_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x               [IN]        
 *  y               [IN]        
 *  event_type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wc_paint_pen_handler(S32 x, S32 y, S32 event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  WcTimeZoneDiff
 * DESCRIPTION
 *  Calculate the time zone difference between 2 cities.
 * PARAMETERS
 *  City1       [IN]        Index of city 1.
 *  City2       [IN]        Index of city 2.
 * RETURNS
 *  time tone of city 1 - time zone of city 2.
 *****************************************************************************/
FLOAT WcTimeZoneDiff(U8 City1, U8 City2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (City1 == 0 || City2 == 0)   /* of one the cities is "None" */
    {
        return 25;
    }
    else
    {
        return (TimeZoneData[City1].CityTimeZone - TimeZoneData[City2].CityTimeZone);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitWcBrowseCity
 * DESCRIPTION
 *  Exit function of browse city screen. Free allocated data.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitWcBrowseCity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifndef __MMI_WC_TZ_SUPPORT__
    #else /* __MMI_WC_TZ_SUPPORT__ */ 
        g_wc_cntx.highlightIndex = Cat230HighlightedIndex;
    #endif /* __MMI_WC_TZ_SUPPORT__ */ 
    g_wc_cntx.running_flag = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wc_entry_city_scrn
 * DESCRIPTION
 *  Display browse city screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wc_entry_city_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wc_sel_scrn = MMI_TRUE; /* entry from the phone setting */
    /* EntryWcBrowseCity(); */
    mmi_am_start_from_mm(APPID_WORLDCLOCK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wc_set_wc_enter_flag
 * DESCRIPTION
 *  Set the entry screen flag
 * PARAMETERS
 *  flag        [IN]        MMI_TRUE: entry from the phone setting;
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wc_set_wc_enter_flag(MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wc_sel_scrn = flag; /* entry from the phone setting */
}
#else /* __MMI_MRE_WORLD_CLOCK__ */ 
void vm_get_phoneset_info(vm_phoneset_info_struct * phnset_info)
{
}
void vm_set_phoneset_info(vm_phoneset_info_struct * phnset_info)
{
}
#endif /* __MMI_MRE_WORLD_CLOCK__ */ 

#else /* __COSMOS_MMI_PACKAGE__ */

void vm_get_phoneset_info(vm_phoneset_info_struct * phnset_info)
{
}
void vm_set_phoneset_info(vm_phoneset_info_struct * phnset_info)
{
}
#endif /* __COSMOS_MMI_PACKAGE__ */

/* Play Tone API, can play the error, key tone */
#include "ProfilesSrvGprot.h"


/*****************************************************************************
 * FUNCTION
 *  vm_play_request_tone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  play_tone       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vm_play_request_tone(VMINT play_tone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* playRequestedTone(ERROR_TONE); */
    srv_prof_play_tone(SRV_PROF_TONE_ERROR, NULL);
}

VMINT vm_get_input_sym(VMCHAR* func_name)
{
	return 0;
}

#endif /* __MRE_LIB_IME__ */ 

