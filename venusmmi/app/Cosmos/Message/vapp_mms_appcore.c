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
 * MMSAppSrvHdlr.c
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *

 * removed!
 *
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "MMI_include.h"
#include "vapp_msg_features.h"

#ifdef __MMI_MMS_2__

 #include "mms_sap_struct.h"
#include "MmsSrvGprot.h"
#include "MmsSrvProt.h"
#include "mmi_rp_vapp_mms_def.h"
#include "vapp_mms_dtmgr.h"
#include "MMSMemoryManagerSrv.h"
#include "MMSBGSRSrvProt.h"
#include "vapp_mms_appcore.h"
#include "mmi_frm_timer_gprot.h" 
#include "mmi_rp_srv_mms_def.h"
#include "mmi_inet_app_trc.h"   
#include "vapp_mms_interface.h"

#ifdef __DM_LAWMO_SUPPORT__
#include "dmuigprot.h"
#endif /*__DM_LAWMO_SUPPORT__*/

#include "MmsSrvSendRcv.h"

#include "MMSAppCommonGprot.h"
extern void mmi_umms_app_ui_draw_dummy_screen(void);
extern U8 AlmIsTonePlaying(void);

static MMI_BOOL backgroundaudioresume = MMI_FALSE;

extern void mmi_umms_app_if_show_viewer_screen(void);
extern void mmi_umms_app_if_show_display_confirm_screen(void);



/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_set_setting_rsp_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  rsp_data        [?]         
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_set_setting_rsp_cb(srv_mms_result_enum result, void *rsp_data, void * user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	

	srv_mms_check_send_ota_mms_settings_rsp_to_profile(rsp_data);
    if(result == MMI_TRUE)
    {
        return;
    }
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_mms_app_asm_success_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_mms_app_asm_success_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	return;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ummsapp_core_mms_app_asm_stop_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ummsapp_core_mms_app_asm_stop_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Handle stop callback  */
    if (mmi_umms_app_if_is_viewer_init())
    {
        mmi_umms_app_if_deinit_viewer();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_asm_viewer_success_callback
 * DESCRIPTION
 *  if ASM successfully freed memory then this is called
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_asm_viewer_success_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_asm_viewer_stop_callback
 * DESCRIPTION
 *  if ASM successfully freed memory then this is called
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_asm_viewer_stop_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   

    return;
}

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_mark_several_rsp_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  msgrsp          [?]         
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_mark_several_rsp_handle(srv_mms_result_enum result, void *msgrsp, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   // mmi_umms_app_ui_plug_in_delete_option_screen(srv_mms_convert_umbox_type_to_mma_folder(msg->msg_box_type));
    mmi_umms_app_if_deinit_viewer();
}
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_delete_scrn_on_folder_id
 * DESCRIPTION
 *  Deletes option screen on basis of folder id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_core_delete_scrn_on_folder_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_UMMS_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_delete_msg_notify_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_delete_msg_notify_callback(U32 msg_id, kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

}



/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_delete_all_msg_notify_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_delete_all_msg_notify_callback(U32 msg_id, kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_delete_all_msg_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  rsp_data        [?]         
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_delete_all_msg_callback(srv_mms_result_enum result, void *rsp_data, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_show_status_icon();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_um_delete_folder_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pid             [IN]        
 *  rsp_data        [?]         
 *  para            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_umms_app_core_um_delete_folder_callback(S32 pid, srv_um_delete_folder_result *rsp_data, S32 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	return MMI_TRUE;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_get_option_scrn_data_callback
 * DESCRIPTION
 *  if ASM successfully freed memory then this is called
 * PARAMETERS
 *  result          [IN]        
 *  msgrsp          [?]         
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_get_option_scrn_data_callback(srv_mms_result_enum result, void *msgrsp, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    return;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_handle_view_option
 * DESCRIPTION
 *  display option according to various data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_core_handle_view_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    return MMI_UMMS_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_viewer_info_callback
 * DESCRIPTION
 *  if ASM successfully freed memory then this is called
 * PARAMETERS
 *  result          [IN]        
 *  msgrsp          [?]         
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_viewer_info_callback(srv_mms_result_enum result, void *msgrsp, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_handle_view
 * DESCRIPTION
 *  if ASM successfully freed memory then this is called
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_core_handle_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	return MMI_UMMS_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_get_use_details_list_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  msgrsp          [?]         
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_get_use_details_list_cb(void *msgrsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

}
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*0*/
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_msg_entry_new_msg_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 *  tone        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_msg_entry_new_msg_popup(U8 type, U8 tone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DM_LAWMO_SUPPORT__
    if(mmi_dmui_is_phone_lock())
    {
        return;
    }
#endif /*__DM_LAWMO_SUPPORT__*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_set_backgroundaudioresume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  msgrsp          [?]         
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_set_backgroundaudioresume(MMI_BOOL bgaudioresume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    backgroundaudioresume = bgaudioresume;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_get_backgroundaudioresume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  msgrsp          [?]         
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_umms_app_core_get_backgroundaudioresume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return backgroundaudioresume;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_viewer_show_error_popup
 * DESCRIPTION
 *  shows error popup
 * PARAMETERS
 *  result              [IN]        
 *  file_error_type     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_viewer_show_error_popup(srv_mms_viewer_result_enum result, S32 file_error_type)
{

}                       

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_get_msg_info_from_bgsr_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id          [IN]        
 *  msg_info        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_get_msg_info_from_bgsr_callback(U32 msg_id, srv_mms_bgsr_msg_info_struct *msg_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_show_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_show_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_get_msg_info_from_bgsr_callback_for_csk_view
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id          [IN]        
 *  msg_info        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_get_msg_info_from_bgsr_callback_for_csk_view(U32 msg_id, srv_mms_bgsr_msg_info_struct *msg_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

}
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_MMS_ITERATOR_VIEWER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_pre_display_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_app_core_pre_display_message(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_get_msg_info_from_bgsr_callback_for_pre_display_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id          [IN]        
 *  msg_info        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_get_msg_info_from_bgsr_callback_for_pre_display_msg(
        U32 msg_id,
        srv_mms_bgsr_msg_info_struct *msg_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_display_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_display_message(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

   // mmi_umms_app_sh_show_screen_based_on_msg_status(msg_id);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_get_msg_state_from_mma
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_core_get_msg_state_from_mma(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    return MMI_UMMS_TRUE;

}



/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_show_progress_screen_with_no_history
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_show_progress_screen_with_no_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_umms_app_ui_plug_in_show_progress_screen_with_no_history();
}





/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_updated_profile_send_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id                  [IN]        
 *  app_id                  [IN]        
 *  profile_id              [IN]        
 *  configure_dtcnt_rsp     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_updated_profile_send_callback(
        srv_wap_prof_sim_id_enum sim_id,
        srv_wap_prof_app_id_enum app_id,
        U8 profile_id,
        srv_wap_prof_result_enum configure_dtcnt_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

}


void mmi_umms_app_core_profile_download_callback(srv_wap_prof_sim_id_enum sim_id,srv_wap_prof_app_id_enum app_id,U8 profile_id,srv_wap_prof_result_enum configure_dtcnt_rsp)
{

}



/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_view_or_replace
 * DESCRIPTION
 *  View message or replace history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_view_or_replace(void)
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
 *  mmi_umms_app_core_send_rr_confirm_or_replace
 * DESCRIPTION
 *  Entry Send RR Confirmation or replace history.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_send_rr_confirm_or_replace(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
}

/*  memory card */
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_handle_change_storage_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET mmi_umms_app_core_handle_change_storage_rsp(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	return MMI_RET_OK;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_handle_sd_card_plug_out
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET mmi_umms_app_core_handle_sd_card_plug_out(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	return MMI_RET_OK;
}

/* memory card  */
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*0*/

#ifdef __DM_LAWMO_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_mo_type_lawmo_wipe_callback_hdlr
 * DESCRIPTION
 *  Call Back from DM to wipe all MMS Data
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_mo_type_lawmo_lock_callback_hdlr(mmi_dmui_app_id_enum app_id, mmi_dmui_cmd_enum cmd)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                      */
/*----------------------------------------------------------------*/

    if (app_id == MMI_DMUI_APP_ID_MMS)
    {
        if(!srv_mms_is_ready())
        {
            switch (cmd)
            {
                case MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK:
                {
                    mmi_dmui_lawmo_report(MMI_DMUI_APP_ID_MMS, MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK, MMI_DMUI_RESULT_SUCCESS);
                }
                break;
                case MMI_DMUI_CMD_LAWMO_UNLOCK:
                {
                    mmi_dmui_lawmo_report(MMI_DMUI_APP_ID_MMS, MMI_DMUI_CMD_LAWMO_UNLOCK, MMI_DMUI_RESULT_SUCCESS);
                }
                break;
                default:
                break;
            }
            return;
        }
        switch (cmd)
        {
            case MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK:
            {
                srv_mms_stop_object_indication_timer();
                srv_mms_refresh_profile_settings(MMI_SIM1);
            #if(MMI_MAX_SIM_NUM >= 2)
                srv_mms_refresh_profile_settings(MMI_SIM2);
            #endif/*MMI_MAX_SIM_NUM*/
                mmi_dmui_lawmo_report(MMI_DMUI_APP_ID_MMS, MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK, MMI_DMUI_RESULT_SUCCESS);
                break;
            }
            case MMI_DMUI_CMD_LAWMO_UNLOCK:
            {
                srv_mms_start_object_indication_timer();
                mmi_dmui_lawmo_report(MMI_DMUI_APP_ID_MMS, MMI_DMUI_CMD_LAWMO_UNLOCK, MMI_DMUI_RESULT_SUCCESS);
            }
            break;
            default:
            break;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_mo_type_lawmo_wipe_callback_hdlr
 * DESCRIPTION
 *  Call Back from DM to wipe all MMS Data
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_mo_type_lawmo_wipe_callback_hdlr(mmi_dmui_app_id_enum app_id, mmi_dmui_cmd_enum cmd)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body                                                      */
/*----------------------------------------------------------------*/
    if (app_id == MMI_DMUI_APP_ID_MMS)
    {
        switch (cmd)
        {
            case MMI_DMUI_CMD_LAWMO_WIPE:
            {
                if(!srv_mms_is_ready())
                {
                #ifdef __MMI_MMS_MMA_MMS_OBJECT_IND__
                    srv_mms_delete_all_obj_ind_msg();
                #endif /*__MMI_MMS_MMA_MMS_OBJECT_IND__*/
                    mmi_dmui_lawmo_report(MMI_DMUI_APP_ID_MMS,  MMI_DMUI_CMD_LAWMO_WIPE, MMI_DMUI_RESULT_SUCCESS);
                    return;
                }
                /*Call BGSR API with callback*/
                srv_mms_refresh_profile_settings(MMI_SIM1);
            #if(MMI_MAX_SIM_NUM >= 2)
                srv_mms_refresh_profile_settings(MMI_SIM2);
            #endif/*MMI_MAX_SIM_NUM*/

            #ifdef __MMI_MMS_MMA_MMS_OBJECT_IND__
                srv_mms_delete_all_obj_ind_msg();
            #endif /*__MMI_MMS_MMA_MMS_OBJECT_IND__*/
                srv_mms_bgsr_law_mo_wipe_notify();
                break;
            }
            default:
            break;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_remove_all_mms_rsp
 * DESCRIPTION
 *  This is the response handler for Delete Request.
 * PARAMETERS
 *  inMsg      response structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_remove_all_mms_rsp(srv_mms_result_enum result, void *rsp_data, S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_delete_folder_rsp_struct *msg = (srv_mms_delete_folder_rsp_struct*) rsp_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(result != SRV_MMS_RESULT_OK)
    {
         mmi_dmui_lawmo_report(MMI_DMUI_APP_ID_MMS,  MMI_DMUI_CMD_LAWMO_WIPE, MMI_DMUI_RESULT_FAILURE);
         return;
    }

    if(msg->result == MMI_TRUE  )
    {
         mmi_dmui_lawmo_report(MMI_DMUI_APP_ID_MMS,  MMI_DMUI_CMD_LAWMO_WIPE, MMI_DMUI_RESULT_SUCCESS);
    }
    else
    {
         mmi_dmui_lawmo_report(MMI_DMUI_APP_ID_MMS,  MMI_DMUI_CMD_LAWMO_WIPE, MMI_DMUI_RESULT_FAILURE);
    }
}
#endif /*__DM_LAWMO_SUPPORT__*/

void mmi_umms_app_core_handle_download_timer_expiry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_umms_app_core_no_duration_popup((U8*)GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY), (U8)MMI_EVENT_FAILURE);
    
    StopTimer(UMMS_DOWNLOAD_TIMER);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_show_use_details_progress
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_show_use_details_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_umms_app_if_show_progress_screen();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_show_memory_full_pop_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  min_sapce_required      [IN]        
 *  flag                    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_show_memory_full_pop_up(U32 min_sapce_required, MMI_BOOL flag)
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
 *  mmi_umms_app_core_no_duration_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_no_duration_popup(U8* str, U8 event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
}
#ifdef __MMI_MMS_ITERATOR_VIEWER__
#if(0)
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_query_indexing_for_template_iter_view
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_um_iter_viewer_result_struct     [OUT]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR mmi_umms_app_core_query_indexing_for_template_iter_view(void *data)
{

}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_ui_callback_um_data_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_um_data_ready_cb(void *user_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

}
#endif
#endif /*__MMI_MMS_ITERATOR_VIEWER__*/
#ifdef __MMI_FTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_delete_msg_notify_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_app_core_delete_msg_notify_for_msg_list_callback(U32 msg_id, kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     srv_mms_sync_msg_info_struct *sync_info = srv_mms_get_sync_msg_info();
     U8 error = 0;
     U8 srv_result = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if ((result != SRV_MMS_BGSR_RESULT_OK) && (result != SRV_MMS_BGSR_RESULT_FAIL_FILE_NOT_FOUND))
    {

    }
    else
    {
        srv_result = srv_mms_delete_msg(sync_info->msg_id, &error);

        if(srv_result != SRV_MMS_RESULT_OK)
        {
            return;
        }
        if (error == MMA_RESULT_OK)
        {
            srv_mms_show_status_icon();
        }
        else
        {

        }
    }
}
#endif/*__MMI_FTE_SUPPORT__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_idle_hdlr
 * DESCRIPTION
 *  This is called when Idle screen group is entered
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_umms_app_core_idle_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_umms_app_if_deinit_viewer();
    mmi_umms_app_dtmgr_reset_data();
#ifdef __MMI_MMS_URI_AGENT__
    srv_mms_de_init_uri();
#endif/*__MMI_MMS_URI_AGENT__*/
    return MMI_RET_OK;
}

#ifdef __MMI_SLIM_MMS_2__
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_bgsr_translate_result_to_strid
 * DESCRIPTION
 *  translate bgsr result to string ID
 * PARAMETERS
 *  bgsr_result          [IN]    BGSR result
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_umms_app_core_bgsr_translate_result_to_strid(srv_mms_bgsr_result_enum bgsr_result, U8 send_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

   
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif/*0*/

}
#else /*__MMI_SLIM_MMS_2__*/
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_core_bgsr_translate_result_to_strid
 * DESCRIPTION
 *  translate bgsr result to string ID
 * PARAMETERS
 *  bgsr_result          [IN]    BGSR result
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_umms_app_core_bgsr_translate_result_to_strid(srv_mms_bgsr_result_enum bgsr_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif/*0*/
	return 0;

}
#endif /*__MMI_SLIM_MMS_2__*/


mmi_ret mmi_umms_app_core_dummy_listener(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}


#endif /* __MMI_MMS_2__ */ 

