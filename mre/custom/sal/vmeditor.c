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
 *  vmeditor.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Inline editor implement file.
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

/* include vmswitch.h in order to check whether __MRE_LIB_EDITOR__ is defined */
#include "vmswitch.h"
#ifdef __MRE_LIB_EDITOR__

/* native header file */
#include "gui.h"
#include "wgui.h"
#include "wgui_editor.h"

/* MRE header file */
#include "vmeditor.h"
#include "vmgraph.h"
#include "vmpromng.h"

/* APIs implemented in other files. */
extern void vm_reg_key_handler(void);
extern mmi_imm_input_mode_enum vm_editor_input_mode_mapping_func(
    vm_input_mode_enum vm_input_mode);
extern VMINT vm_graphic_is_gif_file(VMUINT8 *img_data);
extern VMINT vm_graphic_is_bmp_file(VMUINT8 *img_data);
extern VMINT vm_graphic_is_png_file(VMUINT8 *img_data);
extern VMINT vm_graphic_is_jpeg_file(VMUINT8 *img_data);

extern void vm_graphic_async_blt_stop(void);
extern void vm_graphic_async_blt_start(void);

/* MRE editor struct, each editor has one instance. */
typedef struct
{
    wgui_editor_struct                      *wgui_editor_ptr;
    U8                                      *history_ptr;

    /* 
     * user provided callback function, in which VM_EDITOR_MESSAGE_xxx will be 
     * be handled. 
     */
    vm_editor_message_funcptr               ime_callback;

    /* 
     * user provided callback function, when the text in editor is changed, this
     * callback function will be called. Please note that the callback function
     * will be invoked before editor redraw.
     */
    vm_update_text_funcptr                  update_text_callback;

    /*
     * user provided callback function, when the text in editor is changed, this
     * callback function will be called. Please note that the callback function
     * will be invoked after editor redraw.
     */
    vm_update_text_with_cursor_rect_funcptr update_text_with_cursor_rect_callback;

    /*
     * user provided callback function, when left softkey, right softkey or 
     * center softkey is pressed, the corresponding callback function will be
     * called.
     */
    vm_soft_key_handle_funcptr              lsk_callback;
    vm_soft_key_handle_funcptr              rsk_callback;
    vm_soft_key_handle_funcptr              csk_callback;
} vm_editor_struct;

/*
 * a pointer to the current active editor, and NULL means there is no active 
 * editor now. 
 */
static vm_editor_struct *g_vm_cur_active_editor = NULL;

/* 
 * The current pcb handle, and NULL means there is no active process now. 
 * when editor is activated, g_vm_cur_active_pcb is set to be current process
 * handle. and when editor is deactivated, it is set to be NULL. 
 */
static VM_P_HANDLE g_vm_cur_active_pcb = NULL;

/* 
 * a pointer to the callback function which is reponsible for drawing IMUI's
 * background. When redraw IMUI's background, if this pointer isn't NULL, we 
 * will call user provided callback function, otherwise, we will flush the 
 * IMUI's background to white color.
 */
static vm_draw_imui_background_funcptr g_vm_draw_imui_background_callback;

/* 
 * It means how many editors have been created now.
 * when the 1st editor is being created, we will disable async blt. and when the 
 * last editor has been closed, we will enable async blt again.
 */
static VMINT created_editor_number = 0;

/*****************************************************************************
 * FUNCTION
 *  vm_editor_create
 * DESCRIPTION
 *  Creates an editor, it will use some application's heap memory.
 *  For single line editor, it will malloc 550Byte; 
 *  For multiple line editor, it will malloc xxxByte.
 * PARAMETERS
 *  editor_type             [IN]        Is the editor type
 *  x                       [IN]        Is the left-top corner (x coordinate)
 *  y                       [IN]        Is the left-top corner (y coordinate)
 *  width                   [IN]        Is the width of the editor
 *  height                  [IN]        Is the height of the editor
 *  text_buffer             [IN]        Is the text buffer the editor should use
 *                                      (pre-allocated).
 *  text_buffer_size        [IN]        Is the text buffer size in Bytes
 *  is_disable_softkey      [IN]        Disable softkey or not
 *  layer_handle            [IN]        Is the layer handle
 * RETURNS
 *  If create editor successfully, return the editor handle.
 *  Otherwise, return NULL.
 *****************************************************************************/
VMINT32 vm_editor_create(
    VM_EDITOR_TYPE editor_type,
    VMINT32        x,
    VMINT32        y,
    VMINT32        width,
    VMINT32        height,
    VMUWSTR        text_buffer,
    VMINT32        text_buffer_size,
    VMBOOL         is_disable_softkey,
    VM_GDI_HANDLE  layer_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WGUI_EDITOR_TYPE    wgui_editor_type;
    U32                 wgui_editor_buffer_size;
    U32                 history_buffer_size;
    wgui_editor_struct  *wgui_editor_ptr            = NULL;
    U8                  *history_ptr                = NULL;
    vm_editor_struct    *editor_ptr                 = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (text_buffer == NULL)
    {
        return NULL;
    }

    switch (editor_type)
    {
    case VM_EDITOR_SINGLELINE:
        wgui_editor_type = WGUI_EDITOR_SINGLELINE;
        break;

    case VM_EDITOR_MULTILINE:
        wgui_editor_type = WGUI_EDITOR_MULTILINE;
        break;

    default:
        return NULL;
    }

    wgui_editor_buffer_size = wgui_editor_get_memory_size(wgui_editor_type);
    history_buffer_size = sizeof(wgui_editor_history_struct);
    wgui_editor_ptr = (wgui_editor_struct*) vm_calloc(wgui_editor_buffer_size);
    history_ptr = (U8*) vm_calloc(history_buffer_size);
    editor_ptr = (vm_editor_struct*) vm_calloc(sizeof(vm_editor_struct));

    if (wgui_editor_ptr == NULL || history_ptr == NULL || editor_ptr == NULL)
    {
        if (wgui_editor_ptr != NULL)
        {
            vm_free(wgui_editor_ptr);
        }

        if (history_ptr != NULL)
        {
            vm_free(history_ptr);
        }

        if (editor_ptr != NULL)
        {
            vm_free(editor_ptr);
        }

        return NULL;
    }

    editor_ptr->wgui_editor_ptr = wgui_editor_ptr;
    editor_ptr->history_ptr = history_ptr;

    /*
     * before the 1st editor being created, we should stop async blt to prevent
     * problem caused by async blt and gdi draw.
     */
    vm_graphic_async_blt_stop();

    wgui_editor_create(
        wgui_editor_ptr,
        wgui_editor_type,
        x,
        y,
        width,
        height,
        text_buffer,
        text_buffer_size,
        (MMI_BOOL) is_disable_softkey,
        layer_handle);

    /* when an editor has been created, add 1 to created_editor_number. */
    created_editor_number++;

    /* Singleline editor will select fit font auto. */
    if (editor_type == VM_EDITOR_SINGLELINE)
    {
        wgui_editor_set_fit_text_font(wgui_editor_ptr);
    }

    /*
     * if app didn't provide a IMUI's background filler,
     * then we use the default one.
     */
    if (g_vm_draw_imui_background_callback == NULL)
    {
        vm_editor_set_imui_background_filler(
            (vm_draw_imui_background_funcptr) NULL);
    }

    return (VMINT32) editor_ptr;
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_close
 * DESCRIPTION
 *  Close the editor, it will free the editor's memory in this API.
 * PARAMETERS
 *  editor_handle    :   [IN]    the editor handle
 * RETURNS
 *  void
 *****************************************************************************/
void vm_editor_close(VMINT32 editor_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_editor_struct *editor_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_ptr = (vm_editor_struct*) editor_handle;

    /* Check parameter */
    if (editor_ptr == NULL)
    {
        return;
    }

    wgui_editor_close((wgui_editor_struct*) editor_ptr->wgui_editor_ptr);

    /* Free memory */
    if (editor_ptr->wgui_editor_ptr != NULL)
    {
        vm_free(editor_ptr->wgui_editor_ptr);
        editor_ptr->wgui_editor_ptr = NULL;
    }

    if (editor_ptr->history_ptr != NULL)
    {
        vm_free(editor_ptr->history_ptr);
        editor_ptr->history_ptr = NULL;
    }

    if (editor_ptr != NULL)
    {
        vm_free(editor_ptr);
        if (g_vm_cur_active_editor == editor_ptr)
        {
            g_vm_cur_active_editor = NULL;
        }
    }

    /*
     * when the last editor has been closed, we should enable async blt again. 
     */
    created_editor_number--;
    if (created_editor_number == 0)
    {
        vm_graphic_async_blt_start();
    }
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_set_IME_call_back
 * DESCRIPTION
 *  this function is the ime_callback for wgui editor.
 *  when editor's status changes, wgui editor will pass some events to mre 
 *  inline editor. we transfer these events from MMI_IMC_MESSAGE_xxx to 
 *  VM_EDITOR_MESSAGE_xxx, then call user provided ime_callback to handle the
 *  events.
 * PARAMETERS
 *  input_box_handle        [IN]
 *  msg_ptr                 [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static VMUINT32 vm_editor_set_IME_call_back(
    void                        *input_box_handle, 
    mmi_imc_message_struct_p    msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 lresult = 0;
    vm_editor_message_struct app_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&app_msg, 0, sizeof(vm_editor_message_struct));

    switch (msg_ptr->message_id)
    {
    /*
     * VM_EDITOR_MESSAGE_REDRAW_FLOATING_UI means floating UI's position or size
     * is changed, the new position and size is stored in app_msg.rect. We will 
     * call user provided ime_callback to handle this event, and user should be
     * responsible for redraw app's screen. after app redraws its screen, the 
     * floating UI will be redrawed again. 
     */
    case MMI_IMC_MESSAGE_REDRAW:
        if (msg_ptr->param_0 == 0)
        {
            return 0;
        }
        app_msg.message_id = VM_EDITOR_MESSAGE_REDRAW_FLOATING_UI;
        memcpy(
            &(app_msg.rect), 
            (const void*) msg_ptr->param_1, 
            sizeof(vm_editor_rect));
        break;

    /*
     * use vm_transfer_sys_2_mre_qwerty_key to handle key events.
     * firstly, we will call wgui editor to handle the key events, if it handles
     * these events, then we will do nothing else. but if wgui editor doesn't 
     * handle these key events, we will call vm_pmng_deal_key_event to handle
     * them.
     */
    case MMI_IMC_MESSAGE_SET_KEY:
        vm_reg_key_handler();
        return lresult;

    /*
     * when app calls vm_editor_activate, the activate event will happen.
     * we will call user provided ime_callback to handle this event, and app
     * should be responsible for redraw its screen.
     */
    case MMI_IMC_MESSAGE_ACTIVATE:
        app_msg.message_id = VM_EDITOR_MESSAGE_ACTIVATE;
        break;

    /*
     * when app calls vm_editor_deactivate, the deactivate event will happen.
     * we will call user provided ime_callback to handle this event, and app
     * should be responsible for redraw its screen.
     */
    case MMI_IMC_MESSAGE_DEACTIVATE:
        app_msg.message_id = VM_EDITOR_MESSAGE_DEACTIVATE;
        break;

    /*
     * when IMUI's display or hide, or its height changes, this event will 
     * happen. we will call user provided ime_callback to handle this event, and
     * app should be responsible for re-arrange its layout and redraw app's 
     * screen.
     */
    case MMI_IMC_MESSAGE_IMUI_RECTANGLE_IS_UPDATED:
        app_msg.message_id = VM_EDITOR_MESSAGE_REDRAW_IMUI_RECTANGLE;
        memcpy(
            &(app_msg.rect), 
            (const void*) msg_ptr->param_1, 
            sizeof(vm_editor_rect));
        break;

    /*
     * for other events, we will NOT handle them, and will NOT transfer them to
     * app's ime_callback.
     */
    default:
        return lresult;
    }

    /*
     * for VM_EDITOR_MESSAGE_ACTIVATE, VM_EDITOR_MESSAGE_DEACTIVATE, 
     * VM_EDITOR_MESSAGE_REDRAW_IMUI_RECTANGLE, 
     * VM_EDITOR_MESSAGE_REDRAW_FLOATING_UI, we will call app's ime_callback
     * to handle them. App may need to redraw its screen in the handler.
     */
    if (g_vm_cur_active_editor && g_vm_cur_active_editor->ime_callback)
    {
        if (vm_pmng_set_ctx(g_vm_cur_active_pcb) == VM_PMNG_OP_OK)
        {
            g_vm_cur_active_editor->ime_callback(
                (VMINT32) g_vm_cur_active_editor, 
                &app_msg);

            vm_pmng_reset_ctx();
        }
    }

    /* no matter what happens, the return value should always be 0. */
    return lresult;
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_set_IME
 * DESCRIPTION
 *  To set IME input type, input mode and callback function.
 * PARAMETERS
 *  editor_handle      [IN] the editor handle.
 *  input_type         [IN] the input type, refer to vm_input_type_enum.
 *  input_mode_array   [IN] the input mode set, can pass null to use default 
 *                          mode set.
 *                          If want to use user defined input mode list, 
 *                            1. You need to set input_type as 
 *                               VM_INPUT_TYPE_USER_SPECIFIC.
 *                            2. Application need to use global array variable 
 *                               and end with VM_INPUT_MODE_NONE.
 *                            3. The max length of the array can not more than 10.
 *                          Example:
 *                          static vm_input_mode_enum my_input_modes_lower_first[]
 *                          {
 *                              VM_INPUT_MODE_MULTITAP_LOWERCASE_ABC,
 *                              VM_INPUT_MODE_MULTITAP_UPPERCASE_ABC,
 *                              VM_INPUT_MODE_123,
 *                              VM_INPUT_MODE_SM_PINYIN,
 *                              VM_INPUT_MODE_NONE
 *                          };
 *  default_input_mode [IN]  the default input mode.
 *  ime_callback       [IN]  the ime callback function, app should handle
 *                           VM_EDITOR_MESSAGE_xxx in this callback function.
 * RETURNS
 *  void
 *****************************************************************************/
void vm_editor_set_IME(
    VMINT32                     editor_handle,
    VMUINT32                    input_type,
    vm_input_mode_enum          *input_mode_array,
    vm_input_mode_enum          default_input_mode,
    vm_editor_message_funcptr   ime_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_editor_struct *editor_ptr;
    mmi_imm_input_mode_enum mmi_imm_input_mode;
    mmi_imm_input_mode_enum mmi_imm_input_mode_list[11];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_ptr = (vm_editor_struct*) editor_handle;

    /* Check parameter */
    if (editor_ptr == NULL 
        && input_type == VM_INPUT_TYPE_USER_SPECIFIC 
        && input_mode_array == NULL)
    {
        return;
    }

    mmi_imm_input_mode = vm_editor_input_mode_mapping_func(default_input_mode);
    editor_ptr->ime_callback = ime_callback;
    memset(
        mmi_imm_input_mode_list, 
        IMM_INPUT_MODE_NONE, 
        sizeof(mmi_imm_input_mode_list));

    if (input_type == VM_INPUT_TYPE_USER_SPECIFIC)
    {
        S32 i;
        for (i = 0; i < 11 && input_mode_array[i] != IMM_INPUT_MODE_NONE; i++)
        {
            mmi_imm_input_mode_list[i] 
                = vm_editor_input_mode_mapping_func(input_mode_array[i]);
        }
    }

    wgui_editor_set_IME(
        (wgui_editor_struct*) editor_ptr->wgui_editor_ptr,
        (mmi_imm_input_type_enum) input_type,
        0,  /* no use */
        mmi_imm_input_mode_list,
        mmi_imm_input_mode,
        (mmi_imc_message_funcptr) vm_editor_set_IME_call_back);
}

/******************************************************************************
 * FUNCTION
 *  vm_editor_set_softkey_callback_internal
 * DESCRIPTION
 *  this function is help to call the user provided callback function when
 *  softkey is pressed. It is only a helper, and it will be called in
 *  vm_editor_set_softkey_lsk_cb, vm_editor_set_softkey_rsk_cb and
 *  vm_editor_set_softkey_csk_cb.
 * PARAMETERS
 *  softkey_type    :   [IN]    the value is VM_LEFT_SOFTKEY, VM_RIGHT_SOFTKEY
 *                              or VM_CENTER_SOFTKEY.
 * RETURNS
 *  void.
 ******************************************************************************/
static void vm_editor_set_softkey_callback_internal(VMINT softkey_type)
{
    vm_soft_key_handle_funcptr softkey_callback = NULL;

    /* check which callback function should be called. */
    if (softkey_type == VM_LEFT_SOFTKEY)
    {
        softkey_callback = g_vm_cur_active_editor->lsk_callback;
    }
    else if (softkey_type == VM_RIGHT_SOFTKEY)
    {
        softkey_callback = g_vm_cur_active_editor->rsk_callback;
    }
    else
    {
        softkey_callback = g_vm_cur_active_editor->csk_callback;
    }

    /* try to call user provided callback function to handle softkey events. */
    if (g_vm_cur_active_editor && softkey_callback)
    {
        if (vm_pmng_set_ctx(g_vm_cur_active_pcb) == VM_PMNG_OP_OK)
        {
            softkey_callback();
            vm_pmng_reset_ctx();
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_set_softkey_lsk_cb
 * DESCRIPTION
 *  this is the callback function that we registered in wgui_editor_struct.
 *  when left softkey is pressed, wgui_editor will call this function, and in
 *  this function, we will try to call user provided callback to handle softkey
 *  events.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vm_editor_set_softkey_lsk_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vm_editor_set_softkey_callback_internal(VM_LEFT_SOFTKEY);
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_set_softkey_rsk_cb
 * DESCRIPTION
 *  this is the callback function that we registered in wgui_editor_struct.
 *  when right softkey is pressed, this function will be called by wgui_editor,
 *  and in this function, we will try to call user provided callback function to
 *  handle softkey events.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vm_editor_set_softkey_rsk_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vm_editor_set_softkey_callback_internal(VM_RIGHT_SOFTKEY);
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_set_softkey_csk_cb
 * DESCRIPTION
 *  this is the callback function that we registered in wgui_editor_struct.
 *  when center softkey is pressed, this function will be called by wgui editor,
 *  and in this function, we will try to call user provided callback function to
 *  handle softkey events.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vm_editor_set_softkey_csk_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vm_editor_set_softkey_callback_internal(VM_CENTER_SOFTKEY);
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_set_softkey
 * DESCRIPTION
 *  Set editor's softkey handler. 
 *  Only send key press event to application, other key event will be discarded.
 *  when softkey is pressed, corresponding event will be passed to app's softkey
 *  handler, and app should handle the event.
 * PARAMETERS
 *  editor_handle       [IN]        Is the editor handle
 *  s                   [IN]        Is the label
 *  key                 [IN]        Is softkey type
 *  f                   [IN]        Is the softkey handle
 * RETURNS
 *  void
 *****************************************************************************/
void vm_editor_set_softkey(
    VMINT32                     editor_handle, 
    VMUWSTR                     s, 
    VM_SOFTKEY_ENUM             key, 
    vm_soft_key_handle_funcptr  f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WGUI_SOFTKEY_ENUM   wgui_key;
    vm_editor_struct    *editor_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_ptr = (vm_editor_struct*) editor_handle;

    /* Check parameter */
    if (editor_ptr == NULL)
    {
        return;
    }

    switch (key)
    {
    /* 
     * use vm_editor_set_softkey_lsk_cb to handle the event when left softkey
     * is pressed. and in the handler, we will do nothing but call app's left
     * softkey handler.
     */
    case VM_LEFT_SOFTKEY:
        wgui_key = MMI_LEFT_SOFTKEY;
        editor_ptr->lsk_callback = f;
        wgui_editor_set_softkey(
            (wgui_editor_struct*) editor_ptr->wgui_editor_ptr,
            s,
            NULL,
            wgui_key,
            vm_editor_set_softkey_lsk_cb);
        break;

    /*
     * use vm_editor_set_softkey_rsk_cb to handle the event when right softkey
     * is pressed. and in the handler, we will do nothing but call app's right
     * softkey handler.
     */
    case VM_RIGHT_SOFTKEY:
        wgui_key = MMI_RIGHT_SOFTKEY;
        editor_ptr->rsk_callback = f;
        wgui_editor_set_softkey(
            (wgui_editor_struct*) editor_ptr->wgui_editor_ptr,
            s,
            NULL,
            wgui_key,
            vm_editor_set_softkey_rsk_cb);
        break;

    /*
     * use vm_editor_set_softkey_csk_cb to handle the event when center softkey
     * is pressed. and in the handler, we will do nothing but call app's center
     * softkey handler.
     */
    case VM_CENTER_SOFTKEY:
        wgui_key = MMI_CENTER_SOFTKEY;
        editor_ptr->csk_callback = f;
        wgui_editor_set_softkey(
            (wgui_editor_struct*) editor_ptr->wgui_editor_ptr,
            s,
            NULL,
            wgui_key,
            vm_editor_set_softkey_csk_cb);
        break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_get_softkey_height
 * DESCRIPTION
 *  get the height of softkey area.  
 * PARAMETERS
 *  void
 * RETURNS
 *  Soft key's height in pixel.
 *****************************************************************************/
VMUINT32 vm_editor_get_softkey_height(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_SOFTKEY_HEIGHT;
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_show
 * DESCRIPTION
 *  Display the editor (not flush to screen).
 * PARAMETERS
 *  editor_handle       [IN]        Is the editor handle
 * RETURNS
 *  void
 *****************************************************************************/
void vm_editor_show(VMINT32 editor_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_editor_struct *editor_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_ptr = (vm_editor_struct*) editor_handle;

    /* Check parameter */
    if (editor_ptr == NULL)
    {
        return;
    }

    /* 
     * before show editor, we should disable async blt, otherwise some problems
     * may happen.
     */
    vm_graphic_async_blt_stop();

    wgui_editor_show((wgui_editor_struct*) editor_ptr->wgui_editor_ptr);
}

/******************************************************************************
 * FUNCTION
 *  vm_editor_select_font_size
 * DESCRIPTION
 *  this function can help to get the suitable font size. please note that the
 *  function is internal, and it can be used only in this file.
 *      VM_SMALL_FONT  --> SMALL_FONT
 *      VM_MEDIUM_FONT --> MEDIUM_FONT
 *      VM_LARGE_FONT  --> LARGE_FONT
 *      OTHER          --> FONT_PIXEL_SIZE(size_wanted) (for vector font)
 *                     --> MEDIUM_FONT (for non-vector font)
 * PARAMETERS
 *  size_wanted :   [IN]    the font size that user wanted.
 * RETRUNS
 *  the suitable font size.
 ******************************************************************************/
static VMUINT8 vm_editor_select_font_size(VMUINT8 size_wanted)
{
    VMUINT8 default_font_size;

    if (vm_graphic_is_use_vector_font())
    {
        default_font_size = FONT_PIXEL_SIZE(size_wanted);
    }
    else
    {
        default_font_size = MEDIUM_FONT;
    }

    switch (size_wanted)
    {
    case VM_SMALL_FONT:
        return SMALL_FONT;

    case VM_MEDIUM_FONT:
        return MEDIUM_FONT;

    case VM_LARGE_FONT:
        return LARGE_FONT;

    default:
        return default_font_size;
    }
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_set_multiline_text_font
 * DESCRIPTION
 *  Set multi line editor input text font. 
 *  Recommended that use font_size_t type to define size.
 *  If use number directly, you need to check if the phone support vector font.
 * PARAMETERS
 *  editor_handle    :   [IN]    the editor handle
 *  text_font        :   [IN]    the text font
 * RETURNS
 *  void
 *****************************************************************************/
void vm_editor_set_multiline_text_font(
    VMINT32                     editor_handle, 
    vm_editor_font_attribute    text_font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_editor_struct    *editor_ptr;
    stFontAttribute     wgui_text_font;
    U8                  default_font_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_ptr = (vm_editor_struct*) editor_handle;
    memset(&wgui_text_font, 0, sizeof(wgui_text_font));

    /*
     * only multi-line editor can use this function. if it is a single-line
     * editor, call this function will cause nothing to happen.
     */
    if (editor_ptr == NULL 
        || editor_ptr->wgui_editor_ptr->editor_type != WGUI_EDITOR_MULTILINE)
    {
        return;
    }

    wgui_text_font.size = vm_editor_select_font_size(text_font.size);
    wgui_text_font.bold = text_font.bold;
    wgui_text_font.italic = text_font.italic;
    wgui_text_font.underline = text_font.underline;

    wgui_editor_set_text_font(
        (wgui_editor_struct*) editor_ptr->wgui_editor_ptr, 
        (UI_font_type) &wgui_text_font);
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_get_font_attribute
 * DESCRIPTION
 *  Get editor's font attribute.
 * PARAMETERS
 *  editor_handle    :   [IN]     the editor handle
 *  text_font        :   [OUT]    the text font
 * RETURNS
 *  void
 *****************************************************************************/
void vm_editor_get_font_attribute(
    VMINT32                     editor_handle, 
    vm_editor_font_attribute    *text_font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_editor_struct    *editor_ptr;
    stFontAttribute     *p_font;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_ptr = (vm_editor_struct*) editor_handle;
    p_font = &(editor_ptr->wgui_editor_ptr->text_font);

    /* Check parameter */
    if (editor_ptr == NULL || text_font == NULL)
    {
        return;
    }

    text_font->bold         =   p_font->bold;
    text_font->italic       =   p_font->italic;
    text_font->underline    =   p_font->underline;
    text_font->size         =   p_font->size;
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_set_bg_image
 * DESCRIPTION
 *  Set the normal and focuss image pointers for image background
 *  (there are two styles of background: image background and rectangle background)
 * PARAMETERS
 *  editor_handle           [IN]        Is the editor handle
 *  focus_image             [IN]        Is the focuss image
 *  normal_image            [IN]        Is the normal image
 *  focus_image_size        [IN]        Is the focuss image size
 *  normal_image_size       [IN]        Is the normal image size
 * RETURNS
 *  0 : If successful.
 *  -1 : Parameter error.
 *  -2 : Focus image type error.
 *  -3 : Normal image type error.
 *****************************************************************************/
VMINT32 vm_editor_set_bg_image(
    VMINT32    editor_handle,
    VMUINT8    *focus_image,
    VMUINT8    *normal_image,
    VMINT32    focus_image_size,
    VMINT32    normal_image_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_editor_struct    *editor_ptr;
    U8                  focus_image_type;
    U8                  normal_image_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_ptr = (vm_editor_struct*) editor_handle;

    /* Check parameter */
    if (editor_ptr == NULL || focus_image == NULL || normal_image == NULL)
    {
        return -1;
    }

    /* Get focus image type */
    if (vm_graphic_is_gif_file(focus_image))
    {
        focus_image_type = GDI_IMAGE_TYPE_GIF;
    }
    else if (vm_graphic_is_bmp_file(focus_image))
    {
        focus_image_type = GDI_IMAGE_TYPE_BMP;
    }
    else if (vm_graphic_is_png_file(focus_image))
    {
        focus_image_type = GDI_IMAGE_TYPE_PNG;
    }
    else if (vm_graphic_is_jpeg_file(focus_image))
    {
        focus_image_type = GDI_IMAGE_TYPE_JPG;
    }
    else
    {
        return -2;
    }

    /* Get normal image type */
    if (vm_graphic_is_gif_file(normal_image))
    {
        normal_image_type = GDI_IMAGE_TYPE_GIF;
    }
    else if (vm_graphic_is_bmp_file(normal_image))
    {
        normal_image_type = GDI_IMAGE_TYPE_BMP;
    }
    else if (vm_graphic_is_png_file(normal_image))
    {
        normal_image_type = GDI_IMAGE_TYPE_PNG;
    }
    else if (vm_graphic_is_jpeg_file(normal_image))
    {
        normal_image_type = GDI_IMAGE_TYPE_JPG;
    }
    else
    {
        return -3;
    }

    wgui_editor_set_bg_image_from_memory(
        (wgui_editor_struct*) editor_ptr->wgui_editor_ptr,
        focus_image,
        normal_image,
        focus_image_size,
        normal_image_size,
        focus_image_type,
        normal_image_type);

    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_set_bg_border_style
 * DESCRIPTION
 *  Set border style for rectangle background
 *  (there are two styles of background: image background and rectangle background)
 * PARAMETERS
 *  editor_handle           [IN]        Is the editor handle
 *  border_width            [IN]        Is the border width
 *                                      (no border/single border/double border)
 *  border_normal_color     [IN]        Is the border color of normal style
 *  border_focuss_color     [IN]        Is the border color of focuss style
 * RETURNS
 *  void
 *****************************************************************************/
void vm_editor_set_bg_border_style(
    VMINT32                 editor_handle,
    VM_EDITOR_BORDER_TYPE   border_width,
    VMUINT16                border_normal_color,
    VMUINT16                border_focuss_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_editor_struct        *editor_ptr;
    WGUI_EDITOR_BORDER_TYPE wgui_border_width;
    color                   wgui_border_normal_color;
    color                   wgui_border_focus_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_ptr = (vm_editor_struct*) editor_handle;

    /* Check parameter */
    if (editor_ptr == NULL)
    {
        return;
    }

    switch (border_width)
    {
    case VM_EDITOR_NO_BORDER:
        wgui_border_width = WGUI_EDITOR_NO_BORDER;
        break;

    case VM_EDITOR_SINGLE_BORDER:
        wgui_border_width = WGUI_EDITOR_SINGLE_BORDER;
        break;

    case VM_EDITOR_DOUBLE_BORDER:
        wgui_border_width = WGUI_EDITOR_DOUBLE_BORDER;
        break;
    
    case VM_EDITOR_BORDER_END:
        wgui_border_width = WGUI_EDITOR_BORDER_END;
        break;
    
    default:
        wgui_border_width = WGUI_EDITOR_NO_BORDER;
        break;
    }

    wgui_border_normal_color = gui_color(
        VM_COLOR_GET_RED(border_normal_color),
        VM_COLOR_GET_GREEN(border_normal_color),
        VM_COLOR_GET_BLUE(border_normal_color));

    wgui_border_focus_color = gui_color(
        VM_COLOR_GET_RED(border_focuss_color),
        VM_COLOR_GET_GREEN(border_focuss_color),
        VM_COLOR_GET_BLUE(border_focuss_color));

    wgui_editor_set_bg_border_style(
        (wgui_editor_struct*) editor_ptr->wgui_editor_ptr,
        wgui_border_width,
        wgui_border_normal_color,
        wgui_border_focus_color);
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_set_margin
 * DESCRIPTION
 *  Set margin for editor
 *  (for singleline, align center along y direction, so no need to set top/down 
 *  margin)
 * PARAMETERS
 *  editor_handle       [IN]    Is the editor handle
 *  top                 [IN]    Top >0: set new value; -1: use default value
 *  down                [IN]    Down >0: set new value; -1: use default value
 *  left                [IN]    Left >0: set new value; -1: use default value
 *  right               [IN]    Right >0: set new value; -1: use default value
 * RETURNS
 *  void
 *****************************************************************************/
void vm_editor_set_margin(
    VMINT32 editor_handle, 
    VMINT32 top, 
    VMINT32 down, 
    VMINT32 left, 
    VMINT32 right)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_editor_struct *editor_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_ptr = (vm_editor_struct*) editor_handle;

    // TODO: check for top/down/left/right

    /* Check parameter */
    if (editor_ptr == NULL)
    {
        return;
    }

    wgui_editor_set_margin(
        (wgui_editor_struct*) editor_ptr->wgui_editor_ptr, 
        top, 
        down, 
        left, 
        right);

    /* Singleline editor will select fit font auto. */
    if (editor_ptr->wgui_editor_ptr->editor_type == VM_EDITOR_SINGLELINE)
    {
        wgui_editor_set_fit_text_font(editor_ptr->wgui_editor_ptr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vm_editor_set_layer_handle
 * DESCRIPTION
 *  Set editor layer handle
 * PARAMETERS
 *  editor_handle       [IN]        Is the editor handle
 *  layer_handle        [IN]        Is the layer handle
 * RETURNS
 *  void
 *****************************************************************************/
void vm_editor_set_layer_handle(
    VMINT32         editor_handle, 
    VM_GDI_HANDLE   layer_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_editor_struct *editor_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_ptr = (vm_editor_struct*) editor_handle;

    /* Check parameter */
    if (editor_ptr == NULL)
    {
        return;
    }

    wgui_editor_set_layer_handle(
        (wgui_editor_struct*) editor_ptr->wgui_editor_ptr, 
        layer_handle);
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_set_update_text_callback_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text            [IN]        
 *  cursor          [IN]        
 *  text_length     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void vm_editor_set_update_text_callback_cb(
    UI_buffer_type  text, 
    UI_buffer_type  cursor, 
    S32             text_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vm_cur_active_editor && g_vm_cur_active_editor->update_text_callback)
    {
        if (vm_pmng_set_ctx(g_vm_cur_active_pcb) == VM_PMNG_OP_OK)
        {
            g_vm_cur_active_editor->update_text_callback(
                text, 
                cursor, 
                text_length);

            vm_pmng_reset_ctx();
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_set_update_text_callback
 * DESCRIPTION
 *  Set update text call back
 * PARAMETERS
 *  editor_handle               [IN]        Is the editor handle
 *  update_text_callback        [IN]        Is update text callback
 * RETURNS
 *  void
 *****************************************************************************/
void vm_editor_set_update_text_callback(
    VMINT32                 editor_handle, 
    vm_update_text_funcptr  update_text_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_editor_struct *editor_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_ptr = (vm_editor_struct*) editor_handle;

    /* Check parameter */
    if (editor_ptr == NULL)
    {
        return;
    }

    editor_ptr->update_text_callback = update_text_callback;

    wgui_editor_set_update_text_callback(
        (wgui_editor_struct*) editor_ptr->wgui_editor_ptr,
        vm_editor_set_update_text_callback_cb);
}

/*****************************************************************************
 * FUNCTION
 *   vm_editor_set_update_text_with_cursor_rect_callback_cb
 * DESCRIPTION
 *   this is the callback function provided by mre editor which will be set to
 *   wgui editor.
 * PARAMETERS
 *   text    :               [IN]    point to the begin of the input string.
 *   cursor  :               [IN]    point to the current cursor position.
 *   text_length :           [IN]    length of the input string.
 *   cursor_rect_points  :   [IN]    rect of cursor.
 * RETURNS
 *   void
 *****************************************************************************/
static void vm_editor_set_update_text_with_cursor_rect_callback_cb(
    UI_buffer_type              text,
    UI_buffer_type              cursor,
    S32                         text_length,
    wgui_editor_rect_points_p   cursor_rect_points)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vm_cur_active_editor 
        && g_vm_cur_active_editor->update_text_with_cursor_rect_callback) 
    {
        if (vm_pmng_set_ctx(g_vm_cur_active_pcb) == VM_PMNG_OP_OK)
        {
            g_vm_cur_active_editor->update_text_with_cursor_rect_callback(
                text, 
                cursor, 
                text_length, 
                (vm_editor_rect_points_p) cursor_rect_points);

            vm_pmng_reset_ctx();
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *   vm_editor_set_update_text_with_cursor_rect_callback
 * DESCRIPTION
 *   set update text with cursor rect callback
 * PARAMETERS
 *   editor_handle                           :   [IN] the editor handle
 *   update_text_with_cursor_rect_callback   :   [IN] callback provided by app
 *****************************************************************************/
void vm_editor_set_update_text_with_cursor_rect_callback(
    VMINT32                                 editor_handle, 
    vm_update_text_with_cursor_rect_funcptr update_text_with_cursor_rect_callback)
{
    /*---------------------------------------------------------------*/
    /* Local Variables                                               */
    /*---------------------------------------------------------------*/
    vm_editor_struct *editor_ptr;

    /*---------------------------------------------------------------*/
    /* Code Body                                                     */
    /*---------------------------------------------------------------*/
    editor_ptr = (vm_editor_struct*) editor_handle;

    /* check parameter */
    if (editor_ptr == NULL)
    {
        return;
    }

    editor_ptr->update_text_with_cursor_rect_callback 
        = update_text_with_cursor_rect_callback;

    wgui_editor_set_update_text_with_cursor_rect_callback(
        (wgui_editor_struct*) editor_ptr->wgui_editor_ptr,
        vm_editor_set_update_text_with_cursor_rect_callback_cb);
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_set_pos
 * DESCRIPTION
 *  Move the editor and show.
 * PARAMETERS
 *  editor_handle       [IN]        Is the editor handle
 *  x                   [IN]        Is the left-top corner
 *  y                   [IN]        Is the left-top corner
 * RETURNS
 *  void
 *****************************************************************************/
void vm_editor_set_pos(VMINT32 editor_handle, VMINT32 x, VMINT32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_editor_struct *editor_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_ptr = (vm_editor_struct*) editor_handle;

    /* Check parameter */
    if (editor_ptr == NULL)
    {
        return;
    }

    wgui_editor_set_pos(
        (wgui_editor_struct*) editor_ptr->wgui_editor_ptr, 
        x, 
        y);
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_get_pos
 * DESCRIPTION
 *  Get editor position.
 * PARAMETERS
 *  editor_handle       [IN]        Is the editor handle
 *  x                   [OUT]       Is the left-top corner
 *  y                   [OUT]       Is the left-top corner
 * RETURNS
 *  void
 *****************************************************************************/
void vm_editor_get_pos(VMINT32 editor_handle, VMINT32 *x, VMINT32 *y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_editor_struct *editor_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_ptr = (vm_editor_struct*) editor_handle;

    /* Check parameter */
    if (editor_ptr == NULL)
    {
        return;
    }

    wgui_editor_get_pos(
        (wgui_editor_struct*) editor_ptr->wgui_editor_ptr, 
        (S32*) x, 
        (S32*) y);
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_set_size
 * DESCRIPTION
 *  Resize the editor and show.
 * PARAMETERS
 *  editor_handle       [IN]        Is the editor handle
 *  width               [IN]        Is the width of the editor
 *  height              [IN]        Is the height of the editor
 * RETURNS
 *  void
 *****************************************************************************/
void vm_editor_set_size(VMINT32 editor_handle, VMINT32 width, VMINT32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_editor_struct *editor_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_ptr = (vm_editor_struct*) editor_handle;

    /* Check parameter */
    if (editor_ptr == NULL)
    {
        return;
    }

    wgui_editor_set_size(
        (wgui_editor_struct*) editor_ptr->wgui_editor_ptr, 
        width, 
        height);

    /* Singleline editor will select fit font auto. */
    if (editor_ptr->wgui_editor_ptr->editor_type == VM_EDITOR_SINGLELINE)
    {
        wgui_editor_set_fit_text_font(editor_ptr->wgui_editor_ptr);
    }
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_get_size
 * DESCRIPTION
 *  Get the editor size.
 * PARAMETERS
 *  editor_handle       [IN]        Is the editor handle
 *  width               [OUT]       Is the width of the editor
 *  height              [OUT]       Is the height of the editor
 * RETURNS
 *  void
 *****************************************************************************/
void vm_editor_get_size(VMINT32 editor_handle, VMINT32 *width, VMINT32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_editor_struct *editor_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_ptr = (vm_editor_struct*) editor_handle;

    /* Check parameter */
    if (editor_ptr == NULL)
    {
        return;
    }

    wgui_editor_get_size(
        (wgui_editor_struct*) editor_ptr->wgui_editor_ptr, 
        (S32*) width, 
        (S32*) height);
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_set_text
 * DESCRIPTION
 *  Set the text show in the editor.
 * PARAMETERS
 *  editor_handle       [IN]        Is the editor handle
 *  text_buffer         [IN]        Is the text buffer
 *  text_size           [IN]        Is the text buffer size(byte)
 * RETURNS
 *  void
 *****************************************************************************/
void vm_editor_set_text(
    VMINT32 editor_handle, 
    VMUWSTR text_buffer, 
    VMINT32 text_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_editor_struct *editor_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_ptr = (vm_editor_struct*) editor_handle;

    /* Check parameter */
    if (editor_ptr == NULL)
    {
        return;
    }

    wgui_editor_set_text(
        (wgui_editor_struct*) editor_ptr->wgui_editor_ptr, 
        text_buffer, 
        text_size);
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_get_text
 * DESCRIPTION
 *  Get the input text of the editor.
 * PARAMETERS
 *  editor_handle       [IN]            Is the editor handle
 *  text_buffer         [IN/OUT]        Is the text buffer
 *  text_size           [IN]            Is the text buffer size(byte)
 * RETURNS
 *  VMINT32: text length
 *****************************************************************************/
VMINT32 vm_editor_get_text(
    VMINT32 editor_handle, 
    VMUWSTR text_buffer, 
    VMINT32 text_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_editor_struct    *editor_ptr;
    VMINT32             length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_ptr = (vm_editor_struct*) editor_handle;

    /* Check parameter */
    if (editor_ptr == NULL)
    {
        return 0;
    }

    length = wgui_editor_get_text(
        (wgui_editor_struct*) editor_ptr->wgui_editor_ptr, 
        text_buffer, 
        text_size);

    return length;
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_set_text_color
 * DESCRIPTION
 *  set text color
 * PARAMETERS
 *  editor_handle       [IN]        Is the editor handle
 *  text_color          [IN]        Is the text color
 * RETURNS
 *  void
 *****************************************************************************/
void vm_editor_set_text_color(VMINT32 editor_handle, VMUINT16 text_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_editor_struct    *editor_ptr;
    color               wgui_text_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_ptr = (vm_editor_struct*) editor_handle;

    /* Check parameter */
    if (editor_ptr == NULL)
    {
        return;
    }


    wgui_text_color = gui_color(
        VM_COLOR_GET_RED(text_color),
        VM_COLOR_GET_GREEN(text_color),
        VM_COLOR_GET_BLUE(text_color));

    wgui_editor_set_text_color(editor_ptr->wgui_editor_ptr, wgui_text_color);
}

/*****************************************************************************
 * FUNCTION
 *  wgui_editor_set_cursor_color
 * DESCRIPTION
 *  set cursor color
 * PARAMETERS
 *  editor_handle       [IN]            Is the editor handle
 *   cursor_color    [IN]        Is the cursor color
 * RETURNS
 *  void
 *****************************************************************************/
void vm_editor_set_cursor_color(VMINT32 editor_handle, VMUINT16 cursor_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_editor_struct    *editor_ptr;
    color               wgui_cursor_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_ptr = (vm_editor_struct*) editor_handle;

    /* Check parameter */
    if (editor_ptr == NULL)
    {
        return;
    }

    wgui_cursor_color = gui_color(
        VM_COLOR_GET_RED(cursor_color),
        VM_COLOR_GET_GREEN(cursor_color),
        VM_COLOR_GET_BLUE(cursor_color));

    wgui_editor_set_cursor_color(
        editor_ptr->wgui_editor_ptr, 
        wgui_cursor_color);
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_activate
 * DESCRIPTION
 *  Activate the editor.
 * PARAMETERS
 *  editor_handle       [IN]        Is the editor handle
 *  is_vk_default_on    [IN]        If TRUE, the VK will be on when active the editor; 
 *                                  If FALSE, the VK will be not on when active the editor, you need extra tap to show VK.
 * RETURNS
 *  void
 *****************************************************************************/
void vm_editor_activate(VMINT32 editor_handle, VMBOOL is_vk_default_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_editor_struct *editor_ptr;
    BOOL lcd_freeze = gdi_lcd_get_freeze();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_ptr = (vm_editor_struct*) editor_handle;

    /* Check parameter */
    if (editor_ptr == NULL || g_vm_cur_active_editor == editor_ptr)
    {
        return;
    }

    gdi_lcd_freeze(MMI_TRUE);
    if (g_vm_cur_active_editor != editor_ptr && g_vm_cur_active_editor != NULL)
    {
        vm_editor_deactivate((VMINT32) g_vm_cur_active_editor);
    }

    g_vm_cur_active_pcb = vm_pmng_get_current_handle();
    g_vm_cur_active_editor = editor_ptr;

    vm_graphic_async_blt_stop();

    wgui_editor_activate(
        (wgui_editor_struct*) editor_ptr->wgui_editor_ptr, 
        (MMI_BOOL) is_vk_default_on);
    gdi_lcd_freeze(lcd_freeze);
    gdi_lcd_repaint_all();
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_deactivate
 * DESCRIPTION
 *  Deactivate the editor.
 *  If application state switch to inactive/background/unload, must call this API.
 * PARAMETERS
 *  editor_handle       [IN]        Is the editor handle
 * RETURNS
 *  void
 *****************************************************************************/
void vm_editor_deactivate(VMINT32 editor_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_editor_struct *editor_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_ptr = (vm_editor_struct*) editor_handle;

    /* Check parameter */
    if (editor_ptr == NULL)
    {
        return;
    }

    wgui_editor_deactivate((wgui_editor_struct*) editor_ptr->wgui_editor_ptr);

    g_vm_cur_active_editor = NULL;
    g_vm_cur_active_pcb = NULL;
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_get_active_editor
 * DESCRIPTION
 *  Get current active editor.
 * PARAMETERS
 *  void
 * RETURNS
 *  The active editor handle.
 *****************************************************************************/
VMINT32 vm_editor_get_active_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_editor_struct *wgui_editor_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_editor_get_active_editor((wgui_editor_struct **) (&wgui_editor_ptr));
    if (g_vm_cur_active_editor && wgui_editor_ptr)
    {
        ASSERT(g_vm_cur_active_editor->wgui_editor_ptr == wgui_editor_ptr);
    }

    return (VMINT32) g_vm_cur_active_editor;
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_get_fit_height
 * DESCRIPTION
 *  Get the fit editor height. This API only used to calculate single line editor
 *  height.
 *  For text_font_size, you can use font_size_t type to define the size or use 
 *  number directly.
 * PARAMETERS
 *  vertical_margin_size        [IN]        Is the vertical margin size
 *  text_font_size              [IN]        Is the text font size
 * RETURNS
 *  editor height.
 *****************************************************************************/
VMINT32 vm_editor_get_fit_height(
    VMUINT8 vertical_margin_size, 
    VMUINT8 text_font_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT8 wgui_text_font_size;
    VMINT32 fit_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_text_font_size = vm_editor_select_font_size(text_font_size);
    fit_height = wgui_editor_get_fit_height(
        (S32) vertical_margin_size, 
        wgui_text_font_size);

    return fit_height;
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_get_indicator_height
 * DESCRIPTION
 *  Get indicator height.
 * PARAMETERS
 *  void
 * RETURNS
 *  Indicator height.
 *****************************************************************************/
VMINT32 vm_editor_get_indicator_height(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_save
 * DESCRIPTION
 *  Save the history info of the editor.
 * PARAMETERS
 *  editor_handle       [IN]        Is the editor handle
 * RETURNS
 *  void
 *****************************************************************************/
void vm_editor_save(VMINT32 editor_handle)      // TODO: when to use this API
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_editor_struct *editor_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_ptr = (vm_editor_struct*) editor_handle;

    /* Check parameter */
    if (editor_ptr == NULL)
    {
        return;
    }

    wgui_editor_save(
        (wgui_editor_struct*) editor_ptr->wgui_editor_ptr, 
        editor_ptr->history_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_restore
 * DESCRIPTION
 *  Restore the history info to the editor.
 * PARAMETERS
 *  editor_handle       [IN]        Is the editor handle
 * RETURNS
 *  void
 *****************************************************************************/
void vm_editor_restore(VMINT32 editor_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_editor_struct *editor_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_ptr = (vm_editor_struct*) editor_handle;

    /* Check parameter */
    if (editor_ptr == NULL)
    {
        return;
    }

    wgui_editor_restore(
        (wgui_editor_struct*) editor_ptr->wgui_editor_ptr, 
        editor_ptr->history_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_is_draw_floating_indicator
 * DESCRIPTION
 *  Set if draw ime floating indicator.
 * PARAMETERS
 *  is_draw_floating_indicator        [IN]        if draw ime floating indicator
 * RETURNS
 *  void
 *****************************************************************************/
void vm_editor_is_draw_floating_indicator(VMBOOL is_draw_floating_indicator)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_editor_set_is_draw_ime_floating_indicator(
        (MMI_BOOL) is_draw_floating_indicator);
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_redraw_floating_ui_within_rect
 * DESCRIPTION
 *  Redraw ime floating ui within given rectangle area.
 * PARAMETERS
 *  rect               [IN]        Is the given rectangle area
 * RETURNS
 *  void
 *****************************************************************************/
void vm_editor_redraw_floating_ui_within_rect(vm_editor_rect rect)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_imc_rect wgui_rect;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_rect.x = rect.x;
    wgui_rect.y = rect.y;
    wgui_rect.height = rect.height;
    wgui_rect.width = rect.width;

    wgui_editor_redraw_ime_floating_ui_within_rect((mmi_imc_rect_p) &wgui_rect);
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_redraw_ime_screen
 * DESCRIPTION
 *  Redraw ime UIs(floating ui and fixed ui).
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vm_editor_redraw_ime_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_editor_redraw_ime_screen();
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_get_extra_imui_layer_handler
 * DESCRIPTION
 *  get extra imui layer handler (like handwriting drawn layer).
 * PARAMETERS
 *  void
 * RETURNS
 *  Layer handle.
 *****************************************************************************/
VM_GDI_HANDLE vm_editor_get_extra_imui_layer_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE wgui_layer_hdl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_layer_hdl = wgui_editor_get_extra_imui_layer_handler();

    return wgui_layer_hdl;
}

/*****************************************************************************
 * FUNCTION
 *   vm_editor_draw_imui_background_callback
 * DESCRIPTION
 *   callback function provided by mre editor to redraw imui background.
 *   It will call the app's callback directly.
 * PARAMETERS
 *   x1  :   [IN]    x-coordination of top-left point.
 *   y1  :   [IN]    y-coordination of top-left point.
 *   x2  :   [IN]    x-coordination of down-right point.
 *   y2  :   [IN]    y-coordination of down-right point.
 * RETURNS
 *   void
 *****************************************************************************/
static void vm_editor_draw_imui_background_callback(
    S32 x1, 
    S32 y1, 
    S32 x2, 
    S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vm_draw_imui_background_callback)
    {
        if (vm_pmng_set_ctx(g_vm_cur_active_pcb) == VM_PMNG_OP_OK)
        {
            g_vm_draw_imui_background_callback(x1, y1, x2, y2);

            vm_pmng_reset_ctx();
        }
    }
    else
    {
        extern VMINT vm_graphic_get_active_layer(void);
        if (vm_pmng_set_ctx(g_vm_cur_active_pcb) == VM_PMNG_OP_OK)
        {
            vm_graphic_color color;

            color.vm_color_565 = VM_COLOR_WHITE;
            vm_graphic_setcolor(&color);

            vm_graphic_fill_rect_ex(
                vm_graphic_get_active_layer(),
                x1,
                y1,
                x2 - x1,
                y2 - y1);

            vm_pmng_reset_ctx();
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *   vm_editor_set_imui_background_filler
 * DESCRIPTION
 *   set the callback function to draw imui background.
 *   this function should be called before activate any mre editor.
 * PARAMETERS
 *   draw_imui_background_callback   :   [IN]    the callback to draw imui background.
 * RETURNS
 *   void
 *****************************************************************************/
void vm_editor_set_imui_background_filler(
    vm_draw_imui_background_funcptr draw_imui_background_callback)
{
    g_vm_draw_imui_background_callback = draw_imui_background_callback;

    wgui_editor_set_imui_background_filler(
        vm_editor_draw_imui_background_callback);
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_insert_string
 * DESCRIPTION
 *  insert string.
 * PARAMETERS
 *  editor_handle   :   [IN]    the handle of editor.
 *  str :   [IN]    string to be inserted.
 *  len :   [IN]    length of string.
 * RETURNS
 *  the length of string actually inserted.
 *****************************************************************************/
VMINT32 vm_editor_insert_string(VMINT32 editor_handle, VMUWSTR str, VMINT32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_editor_struct *editor_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_ptr = (vm_editor_struct*) editor_handle;

    /* Check parameter */
    if (editor_ptr == NULL)
    {
        return 0;
    }

    return wgui_editor_insert_string(
        (wgui_editor_struct*) editor_ptr->wgui_editor_ptr,
        (UI_string_type) str,
        (U32) len);
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_set_cursor_index
 * DESCRIPTION
 *  set editor cursor index
 * PARAMETERS
 *  editor_handle   :   [IN]    the handle of editor.
 *  cursor_index    :   [IN]    the cursor index
 * RETURNS
 *  void
 *****************************************************************************/
void vm_editor_set_cursor_index(VMINT32 editor_handle, VMINT32 cursor_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_editor_struct *editor_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_ptr = (vm_editor_struct*) editor_handle;

    /* Check parameter */
    if (editor_ptr == NULL)
    {
        return;
    }

    wgui_editor_set_cursor_index(
        (wgui_editor_struct*) editor_ptr->wgui_editor_ptr,
        (U32) cursor_index);
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_get_cursor_index
 * DESCRIPTION
 *  get editor cursor index
 * PARAMETERS
 *  editor_handle   :   [IN]    the handle of editor.
 * RETURNS
 *  the cursor index.
 *****************************************************************************/
VMINT32 vm_editor_get_cursor_index(VMINT32 editor_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_editor_struct *editor_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_ptr = (vm_editor_struct*) editor_handle;

    /* Check parameter */
    if (editor_ptr == NULL)
    {
        return;
    }

    return wgui_editor_get_cursor_index(
        (wgui_editor_struct*) editor_ptr->wgui_editor_ptr);
}

/*****************************************************************************
 * FUNCTION
 *   vm_editor_set_default_text
 * DESCRIPTION
 *   set default text.
 * PARAMETERS
 *   editor_handle   :   [IN]    the handle of editor.
 *   default_text_buffer :   [IN]    the buffer that stores default text.
 * RETURNS
 *   void
 *****************************************************************************/
void vm_editor_set_default_text(
    VMINT32 editor_handle, 
    VMUWSTR default_text_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_editor_struct *editor_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_ptr = (vm_editor_struct*) editor_handle;

    /* Check parameter */
    if (editor_ptr == NULL)
    {
        return;
    }

    wgui_editor_set_default_text(
        (wgui_editor_struct*) editor_ptr->wgui_editor_ptr,
        (UI_string_type) default_text_buffer);
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_show_from_first_line
 * DESCRIPTION
 *  jump to start to show from the first line of multiline editor.
 * PARAMETERS
 *  editor_handle    :   [IN]    handle of the editor.
 * RETURNS
 *  void
 *****************************************************************************/
void vm_editor_show_from_first_line(VMINT32 editor_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_editor_struct *editor_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_ptr = (vm_editor_struct*) editor_handle;

    if (editor_ptr != NULL 
        && ((wgui_editor_struct*) editor_ptr)->editor_type
        == WGUI_EDITOR_MULTILINE)
    {
        wgui_editor_show_from_start(
            (wgui_editor_struct*) editor_ptr->wgui_editor_ptr);
    }
}

/*****************************************************************************
 * FUNCTION
 *  vm_editor_show_from_start
 * DESCRIPTION
 *  for multi-line editor, show from the first line.
 *  for single-line editor, show from the first charactor.
 * PARAMETERS
 *  editor_handle    :   [IN]    handle of the editor.
 * RETURNS
 *  void
 *****************************************************************************/
void vm_editor_show_from_start(VMINT32 editor_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_editor_struct *editor_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    editor_ptr = (vm_editor_struct*) editor_handle;

    if (editor_ptr == NULL)
    {
        return;
    }

    wgui_editor_show_from_start(
        (wgui_editor_struct*) editor_ptr->wgui_editor_ptr);
}

#endif /* __MRE_LIB_EDITOR__ */
