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
 * WAPProfileSrvGProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This declares the interface API prototypes for UPP profile module.
 *
 * Author: Ramneek Kalra
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *==============================================================================
 *******************************************************************************/
#ifndef _WAPPROFILESRVGPROT_H
#define _WAPPROFILESRVGPROT_H

#include "MMI_features.h"
#include "MMIDataType.h"

#ifdef WAP_SUPPORT

#include "WAPProfileSrvType.h"
#include "WAPProvisioningSrvType.h"


typedef enum
{        
    /**********************************************************************************************/
    /* PROFILE Related Events                                                         */
    /**********************************************************************************************/

   EVT_ID_SRV_UPP_ENTER_DTCNT_CUI_IND = SRV_WAP_PROF_BASE + 1,
   EVT_ID_SRV_UPP_ACTIVATE_PROFILE_IND,
#ifndef __SRV_UPP_SLIM__
   EVT_ID_SRV_UPP_CLOSE_PLEASE_WAIT_SCR_IND,
#endif
   EVT_ID_SRV_UPP_DISPLAY_POPUP_IND,
   EVT_ID_SRV_UPP_CLOSE_CUI_IND,
 #ifndef __SRV_UPP_SLIM__
   EVT_ID_SRV_UPP_ENTRY_PLEASE_WAIT_SCRN,
 #endif
#ifdef PROV_SUPPORT
   EVT_ID_SRV_UPP_CREATE_PROV_SCR_IND,
   EVT_ID_SRV_UPP_RECREATE_PROV_SCR_IND,
   EVT_ID_SRV_UPP_PREENTRY_PROV_SCR_IND,
   EVT_ID_SRV_UPP_DTCNT_READY_CHECK_IND,
#endif
   EVT_ID_SRV_UPP_DTCNT_VALID_CHECK_IND,
   EVT_ID_SRV_UPP_CHECK_DTCNT_VALID,
   EVT_ID_SRV_UPP_RE_ENTRY_ALLOWED,
   EVT_ID_SRV_UPP_TOTAL

}srv_wap_prof_upp_event_enum;

#ifdef PROV_SUPPORT
/* EVENT STRUCTURE for EVT_ID_SRV_UPP_RECREATE_PROV_SCR_IND */
typedef struct{
   MMI_EVT_PARAM_HEADER
U32     profile_count;
srv_wap_prov_type_enum provisioning_type;
#ifdef __COSMOS_MMI_PACKAGE__
mmi_id cui_id;
#endif
}srv_wap_prov_create_prov_scrn_evt_struct; 

/* EVENT STRUCTURE for EVT_ID_SRV_UPP_DTCNT_READY_CHECK_IND */
typedef struct{
    MMI_EVT_PARAM_HEADER
FuncPtr callback;
MMI_BOOL scrn_lock;
}srv_wap_prov_dtcnt_ready_check_evt_struct;

#endif

/* EVENT STRUCTURE for EVT_ID_SRV_UPP_ENTER_DTCNT_CUI_IND */
typedef struct{
   MMI_EVT_PARAM_HEADER
srv_wap_prof_sim_id_enum sim_id;
srv_wap_prof_app_id_enum app_id;
U8 cbm_app_id;
mmi_id parent_id;
U16 icon_id;
U16 app_menu_id;
}srv_wap_prof_entry_dtcnt_cui_struct;  	

/* EVENT STRUCTURE for EVT_ID_SRV_UPP_ACTIVATE_PROFILE_IND */
typedef struct{
   MMI_EVT_PARAM_HEADER
U32 index;
MMI_BOOL inform_others;
srv_wap_prof_sim_id_enum sim_info;
srv_wap_prof_app_id_enum app_info;
}srv_wap_prof_activate_profile_struct; 

#ifndef __SRV_UPP_SLIM__
/* EVENT STRUCTURE for EVT_ID_SRV_UPP_CLOSE_PLEASE_WAIT_SCR_IND */
typedef struct{
   MMI_EVT_PARAM_HEADER
srv_wap_prof_profile_source_enum profile_content_src;
srv_wap_prof_action_enum action;
MMI_BOOL end_key_pressed;
}srv_wap_prof_close_scr_struct;
#endif

/* EVENT STRUCTURE for EVT_ID_SRV_UPP_DISPLAY_POPUP_IND */
typedef struct{
   MMI_EVT_PARAM_HEADER
U16 action; 
srv_wap_prof_result_enum result; 
MMI_BOOL use_action_as_string_id; 
FuncPtr popup_end_callback;
FuncPtr popup_exit_callback;
}srv_wap_prof_display_popup_struct;


/* EVENT STRUCTURE for EVT_ID_SRV_UPP_CLOSE_CUI_IND */
typedef struct{
   MMI_EVT_PARAM_HEADER
}srv_wap_prof_close_dtcnt_cui_struct;

/* EVENT STRUCTURE for EVT_ID_SRV_UPP_DTCNT_VALID_CHECK_IND */
typedef struct{
   MMI_EVT_PARAM_HEADER
srv_wap_prof_sim_id_enum sim_id;
   srv_wap_prof_app_id_enum app_id;
   U8 profile_id;
   kal_bool *result;
}srv_wap_prof_dtcnt_valid_struct;

/* EVENT STRUCTURE for EVT_ID_SRV_UPP_CHECK_DTCNT_VALID */

typedef struct{
   MMI_EVT_PARAM_HEADER
srv_wap_prof_sim_id_enum sim_id;
   srv_wap_prof_app_id_enum app_id;
   U8 profile_id;
   kal_bool result;
}srv_wap_prof_check_dtcnt_valid_struct;

/* EVENT STRUCTURE for EVT_ID_SRV_UPP_RE_ENTRY_ALLOWED */

typedef struct{
	MMI_EVT_PARAM_HEADER
   srv_wap_prof_sim_id_enum sim_id;
   srv_wap_prof_app_id_enum app_id;
   kal_bool result;
}srv_wap_prof_re_entry_allowed_struct;



/* API to display profile list */
extern void srv_wap_prof_display_profile_list(
                srv_wap_prof_sim_id_enum sim_id,
                srv_wap_prof_app_id_enum app_id,
                U16 titlebar_icon_id,
		U16 app_menu_id,
                mmi_id parent_id);



extern U8 srv_wap_prof_get_cbm_app_id(srv_wap_prof_app_id_enum app_id, srv_wap_prof_sim_id_enum sim_id );

extern srv_wap_prof_profile_content_struct *srv_wap_prof_get_profile_content(
                                                srv_wap_prof_sim_id_enum sim_id,
                                                srv_wap_prof_app_id_enum app_id,
                                                U8 profile_index,
                                                srv_wap_prof_dtcnt_count_enum  dtcnt_type,
                                                srv_wap_prof_get_profile_rsp_funcptr_type get_profile_rsp_callback);

extern srv_wap_prof_conn_type_enum srv_wap_prof_get_active_profile_connection_type(srv_wap_prof_app_id_enum app_id);
//extern MMI_BOOL srv_wap_prof_is_dtcnt_valid(srv_wap_prof_sim_id_enum sim_id, srv_wap_prof_app_id_enum app_id, U8 profile_id);

#ifndef __SRV_UPP_SLIM__
extern void srv_wap_prof_kill_profile(srv_wap_prof_app_id_enum app_id);    /* MAUI_01508716 */
#endif



extern MMI_BOOL srv_wap_prof_is_dtcnt_valid(
								srv_wap_prof_sim_id_enum sim_id, 
								srv_wap_prof_app_id_enum app_id,
								U8 profile_id );
 

extern srv_wap_prof_sim_id_enum srv_wap_prof_get_active_sim_id(srv_wap_prof_app_id_enum app_id);
CHAR* srv_wap_prof_get_homepage(srv_wap_prof_sim_id_enum sim_id, srv_wap_prof_app_id_enum app_id, U8 profile_index);


#endif /*WAP_SUPPORT */
#endif /* _WAPPROFILEGPROT_H */
