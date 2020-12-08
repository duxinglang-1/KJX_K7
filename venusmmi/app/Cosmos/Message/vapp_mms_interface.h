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
 * MMSAppInterfaceGProt.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * 
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef MMS_APP_INTERFACE_GPROT_H
#define MMS_APP_INTERFACE_GPROT_H

#include "MMI_features.h"
#include "vapp_msg_features.h"

#ifdef __MMI_MMS_2__
#include "MsgViewerCuiGProt.h"


#ifdef __MMI_MMS_POSTCARD__
#include "FileManagerGprot.h"
#endif

typedef enum
{
    MMI_UMMS_OPEN_MMS_OPTION,
    MMI_UMMS_OPEN_MMS_VIEWER,
#ifdef __MMI_MMS_POSTCARD__
    MMI_UMMS_OPEN_MMS_PREVIEWER_POSTCARD,
#endif
	MMI_UMMS_OPEN_MMS_PREVIEWER_MMS
} mmi_umms_app_if_action_enum;

typedef enum
{
    CSK_LIST_OPTION_ON,     /* List Option On CSK Press */
    CSK_LIST_OPTION_OFF,    /* List Option On LSK press */
    CSK_OK_OPTION_ON,
    CSK_OK_OPTION_OFF,
    CSK_OPTION_ALL
} mmi_umms_list_csk_option;

#ifdef __MMI_OP12_TOOLBAR__
typedef enum
{
    UMMS_TB_STATE_NONE,
    UMMS_TB_STATE_VIEW,
    UMMS_TB_STATE_DELETE,
    UMMS_TB_STATE_CALL,
    UMMS_TB_STATE_TOTAL
} mmi_umms_tb_state;
#endif /* __MMI_OP12_TOOLBAR__ */ 

typedef struct
{
    mmi_umms_app_if_action_enum action;
    U16 msg_box_type;
    U32 msg_id;
	MMI_BOOL is_iterting;
	void *um_data;
	mmi_id parent_grp_id;
} mmi_umms_app_start_struct;

extern BOOL mmi_umms_app_if_is_viewer_init(void);
extern void mmi_umms_app_if_show_uc_add_address_screen(void);
extern void mmi_umms_app_if_show_message_settings_menu(void);
extern void mmi_umms_app_if_show_template_menu(void);
extern void mmi_umms_app_if_show_mms_screen(void *data);
extern void mmi_umms_app_if_show_mms_screen_no_reset(void *data);
extern void mmi_umms_app_if_show_mms_option_screen(void *data);
extern void mmi_umms_app_if_show_mms_view_screen(void *data);
extern void mmi_umms_app_if_show_mms_preview_screen(void *data);
extern MMI_BOOL mmi_umms_app_if_is_option_screen_present(void);
extern void mmi_umms_app_if_show_mms_notification(void);
extern void mmi_umms_app_if_show_java_mms_notification(void);
extern void mmi_umms_app_if_show_mms_full_popup(void);
extern void mmi_umms_app_if_stop_app_screen(void);
extern void mmi_umms_app_if_stop_viewer_screen(void);
extern void mmi_umms_app_if_show_mms_properties_screen(void);
extern void mmi_umms_app_if_deinit_viewer(void);
extern mmi_ret mmi_umms_app_if_is_mms_in_open_state(mmi_event_struct *);
extern BOOL mmi_umms_app_if_is_viewer_in_history(void);
extern mmi_ret mmi_umms_app_if_msg_in_view(mmi_event_struct *);
extern mmi_ret mmi_umms_app_lang_changed_hdlr(mmi_event_struct *evt);
extern void mmi_umms_app_if_uc_request_to_deinit(void);
extern void mmi_umms_app_if_uc_preview_msg(U32 msg_id, U8 msg_type, U8 sim_id);
extern void* cui_umms_app_set_uc_preview_msg(
                U32 msg_id,
                /* mma_msg_type_enum */ U8 msg_type,
                /* mmi_uc_sim_id */ U8 sim_id);
extern MMI_BOOL mmi_umms_app_interface_entry_from_um(U16 key, U32 msg_id, void *user_data, mmi_id parent_grp_id);

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
extern void mmi_umms_app_if_show_pref_storage_option(void);
extern void mmi_umms_app_if_show_memory_status_menu(void);
extern void mmi_umms_app_if_show_phone_memory_status_screen(void);
extern void mmi_umms_app_if_show_card_memory_status_screen(void);
#endif 

#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
extern void mmi_umms_op_hs_clear_recent_event(void);
extern void mmi_umms_op_hs_get_recent_mms(S32 num);
extern void mmi_umms_op_hs_get_mms_unread_count(void);
extern void mmi_umms_op_hs_get_new_mms_data(S32 num);
extern void mmi_umms_op_hs_get_mms_softnote(void);
#endif 

#ifdef __MMI_OP12_TOOLBAR__
extern void mmi_umms_op_tb_evnt_query_mms(S32 num);

#endif

#ifdef __MMI_OP11_MMS_SEND_TO_PHOTO_BLOG__
/* under construction !*/
#endif

#ifdef __MMI_MMS_POSTCARD__
extern MMI_BOOL mmi_umms_app_if_check_mms_insert_postcard(mmi_fmgr_filetype_enum file_type, char *file_path);
#endif
extern void srv_mms_de_init_uri(void);
extern mmi_ret mmi_umms_op_update_recent_event_list_from_phone_suit(mmi_event_struct *para);
extern mmi_ret mmi_umms_sd_card_plug_out_hdlr_cb(mmi_event_struct *param);
extern mmi_ret mmi_umms_sd_card_plug_in_hdlr_cb(mmi_event_struct *param);
extern mmi_ret mmi_umms_drv_format_hdlr_cb(mmi_event_struct *param);
extern void srv_mms_sd_card_plug_in_hdlr(U8 drive_count);
extern void srv_mms_sd_card_plug_out_hdlr(U8 drive_count);
extern void srv_mms_drv_format_hdlr(void);


#ifdef __MMI_FTE_SUPPORT__
extern void mmi_umms_app_if_reply_mms(mmi_id parent_id,  U32 msg_id);
extern void mmi_umms_app_if_forward_mms(mmi_id parent_id, U32 msg_id);
extern void mmi_umms_app_if_edit_mms(mmi_id parent_id, U32 msg_id);
extern void mmi_umms_app_if_send_mms(mmi_id parent_id, U32 msg_id);
extern void mmi_umms_app_if_resend_mms(mmi_id parent_id, U32 msg_id);
extern void mmi_umms_app_if_delete_mms(mmi_id parent_id, U32 msg_id);
#endif
extern mmi_id cui_umms_preview_mms_create(mmi_id parent_id);
extern void cui_umms_preview_mms_run(mmi_id parent_id, void *msg);
extern void cui_umms_preview_mms_close(mmi_id);
void *cui_umms_app_set_uc_preview_msg(U32 msg_id, U8 msg_type, U8 sim_id);

extern mmi_id cui_umms_mms_templates_launch(mmi_id parent_id);
extern mmi_id cui_umms_mms_settings_launch(mmi_id parent_id);
extern mmi_ret umms_cb_hdlr(mmi_event_struct *evt, void * para);
extern mmi_menu_id umms_menu_query_function(U32 msg_id);
extern void mmi_umms_app_if_start_viewer(U16 parent_grp_id, U32 msg_id, void *user_data, cui_msg_viewer_type_enum type);

extern mmi_ret mmi_umms_app_core_mma_insuf_mem(mmi_event_struct *param);
extern U16 mmi_umms_app_if_get_um_box_type_from_msg_id(U32 msg_id);

#ifdef __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__
extern void mmi_umms_app_if_show_delivery_status(void);
extern void mmi_umms_app_if_show_read_status(void);
#endif

extern mmi_ret mmi_umms_app_core_mms_deinit(mmi_event_struct *param);
extern mmi_ret mmi_umms_app_core_idle_hdlr(mmi_event_struct *evt);

#endif /* __MMI_MMS_2__  */
#endif /* MMS_APP_INTERFACE_GPROT_H */ 

