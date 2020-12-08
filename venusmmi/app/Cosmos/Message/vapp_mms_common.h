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
 *  vapp_mms_common.h
 *
 * Project:
 * --------
 *  MMS Viewer
 *
 * Description:
 * ------------
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

// This include is for proc call
#ifndef __VAPP_MMS_COMMON_H__
#define __VAPP_MMS_COMMON_H__
#include "MMI_features.h" 
#include "vapp_msg_features.h"


#include "vadp_mmi_frm.h"
#include "vfx_uc_include.h"
#include "vcp_text_view.h"
#include "vcp_app_scr.h"
#include "vapp_mms_data.h"

#include "vapp_mms_toolbar.h"
#include "vcp_include.h"
#include "ui_core\mvc\vfx_mmi.h"

#include "vcp_status_icon_bar.h"
#include "vcp_page_panel.h"
#include "vcp_list_menu.h"
#include "vcp_popup.h"
#include "vcp_image_button.h"
#include "mmi_rp_vapp_mms_def.h"
#include "vapp_mms_details_viewer.h"



/* This structure defines the request parameters for uc launch API vapp_mms_start_uc_struct*/
typedef struct
{
    U32 msg_id;/* Message id*/
	mmi_id grp_id;/*Group ID*/
    U8 sim_id;/*Sim id, mmi_sim_id_enum */
    U8 uc_mode;/*UC mode, mma_mode_enum*/
	U8 uc_type;/*UC state, srv_uc_state_enum*/
	U8 uc_op; /*UC operation, vappUcMsgOperationEnum*/
	
    U8 edit_mode;/*Edit mode, srv_uc_MMS_edit_mode_enum*/
	U8 storage_type;/* mma_msg_storage_type_enum, storage type*/
}vapp_mms_start_uc_struct;

void vapp_mms_show_error_pop_up(const VfxU8 error_result, VfxScreen *scr);
VfxBool vapp_mms_show_uri_confirm_pop_up_cb(mmi_scenario_id scen_id, void *arg);
void vapp_mms_uri_confirm_cb(VfxId id, void *userData);
VfxU16 vapp_mms_get_msg_icon(VfxU8 msg_status);
mmi_ret vapp_mms_show_bgsr_pop_up(mmi_event_struct* evt);
void vapp_mms_start_uc(vapp_mms_start_uc_struct *para);
mmi_ret vapp_mms_proc(mmi_event_struct *evt);

VfxU16 vapp_mms_get_string_for_msg_dr_status(VfxU8 status);
VfxU16 vapp_mms_get_string_for_msg_rr_status(VfxU8 status);
mmi_sim_enum vapp_mms_convert_mma_sim_to_mmi_sim(kal_uint8 sim_id);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
VfxBool vapp_mms_is_need_show_edit_cnfm(VfxU32 msg_id, VfxU16 *str_id);

#endif/*__VAPP_MMS_COMMON_H__*/
