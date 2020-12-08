/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_hs_widget_aclock.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen widget: analog clock
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
 *
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "vfx_uc_include.h"
#include "vcp_popup.h"
#ifndef _WIDGET_API_H
#define _WIDGET_API_H

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*unlock_func)(void *);

typedef struct canvas_lock_st
{
    kal_mutexid mutex;
    unlock_func unlock_canvas;
    void *context;
    short view_type;
} canvas_lock_struct;

typedef struct
{
  void* user_data;
  WCHAR data[250];
  WCHAR number[30];
} widget_sms_req_struct;


typedef struct widget_sending_sms_st
{
    void *sms_handle;
    void *user_data;
    struct widget_sending_sms_st *next;
} widget_sending_sms_struct;

typedef struct widget_contact_op_st
{
    void *info;
    void *user_data;
    struct widget_contact_op_st *next;
} widget_contact_op_struct;

extern void vapp_widget_send_message(void *local_para_ptr, void *peer_buff_ptr, msg_type ilm_id, module_type dst_id);
extern void vapp_widget_notify_content_update(void *param);
extern void vapp_widget_handle_terminate_all_ind(void *param);
extern void vapp_widget_handle_terminate_ind(void *param);

extern void vapp_widget_load_widget(int instance_id, int details);
extern void widget_unload_widget(int instance_id);
extern void vapp_widget_focus_in(int instance_id, void *view_handle);
extern void vapp_widget_focus_out(int instance_id, void *view_handle);
extern VfxBool vapp_widget_is_wait_asm_rsp(void);
extern void vapp_widget_disable_view_cache(VfxBool isDetails, VfxBool is_heap_shrink);
extern void vapp_widget_show_setting_dialog(int instance_id);
extern void vapp_widget_update_content(int instance_id, void *view_handle);

extern void vapp_widget_launch_details_view(void *param);  
extern void vapp_widget_view_check_load_result(int result);
extern int vapp_widget_close_view_by_id(int instance_id);
extern void vapp_widget_close_main_menu_view();
extern void vapp_widget_view_unlock_canvas(void *lock);
extern void *vapp_widget_view_lock_canvas(int instance_id,void * view_handle,void * * ptr_buffer,int width,int height); //???

extern void vapp_widget_close_view(int instance_id, void *view_handle, int type, int response);
extern void vapp_widget_terminate_widget(int id);
extern void vapp_widget_canvas_free(void *p);

extern VfxBool vapp_widget_is_view_notify_to_free_handler();
extern VfxBool vapp_widget_installer_is_wait_to_free_handler();
extern VfxBool vapp_widget_is_details_view_launched(void);
extern void gadget_adp_set_redraw_pending(void *view_handle, bool pending);	/*TESTING*/


typedef enum
{
    PEN_DOWN,
    PEN_UP,
    PEN_MOVE,
    PEN_LONGTAP,
    PEN_REPEAT,
    PEN_ABORT,
} pen_event_enum;

extern void vapp_widget_handle_pen_event(int id, void *view_handle, int x, int y, int type);
extern void vapp_widget_handle_key_event(int id, void *view_handle, int keycode, int keytype);

/* Used for Gadget and LiveWallpaper co-existed case */
extern void widget_set_widget_active_flag(bool active_flag);
extern void widget_enter_widget_active_mode(void);
extern void widget_leave_widget_active_mode(void);
extern void vapp_widget_set_ignore_load_rsp_flag(bool ignore_flag);
extern VfxBool vapp_widget_enable_view_cache(void);
extern void vapp_widget_handle_enter_text_response(void *view_handle, int text_modified, VfxWChar *text);

extern void vapp_widget_initialize(void);

extern int g_vapp_confirm_dialog_gid;

#ifdef __cplusplus
}
#endif

#endif /* _WIDGET_API_H */
