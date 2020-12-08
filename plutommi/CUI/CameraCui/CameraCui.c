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
 *   CameraCui.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Camera Common UI header file.
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

#include "MMI_include.h"


/*******************************************************************************
* Include Header File
*******************************************************************************/
#include "MMI_features.h"
#include "mmi_features_camera.h"
#include "mmi_features_camcorder.h"
#include "CameraGprot.h"
#include "CamcorderGprot.h"
#include "CameraCui.h"
#include "CameraCuiGprot.h"
#include "CamcorderResDef.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "string.h"
#include "mmi_rp_app_camco_def.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"

/*******************************************************************************
* Structure Define
*******************************************************************************/

/*******************************************************************************
* Macro Define
*******************************************************************************/

/*******************************************************************************
* Function Declaration
*******************************************************************************/

/*******************************************************************************
* External Function Declaration
*******************************************************************************/
extern void mmi_camera_enter_from_cui(mmi_id cui_gid, p_cui_camera_run_struct p_args);
extern mmi_ret mmi_camera_group_proc(mmi_event_struct *evt);
extern void mmi_camco_cam_enter_from_cui(mmi_id cur_gid, p_cui_camera_run_struct p_args);
extern mmi_ret mmi_camco_cam_group_proc(mmi_event_struct *evt);
extern MMI_BOOL mmi_camera_entry_app_pre_check(void);

/*******************************************************************************
* Function Realization 
*******************************************************************************/
MMI_BOOL cui_camera_check_and_display_popup(void)
{
#ifdef __MMI_AP_DCM_CAMIMGV__
	mmi_ap_send_dcm_load_evt(DYNAMIC_CODE_COMPRESS_CAMIMGV);
#endif
#if defined(__MMI_CAMCORDER__)
	return mmi_camco_check_and_display_popup();
#elif defined(__MMI_CAMERA__)
	return MMI_TRUE;
#endif
}
#ifdef __MMI_AP_DCM_CAMIMGV__
#pragma arm section code = "DYNAMIC_CODE_CAMIMGV_ROCODE", rodata = "DYNAMIC_CODE_CAMIMGV_RODATA"
#endif
void cui_camera_struct_init(p_cui_camera_run_struct p_args)
{
#if defined(__MMI_CAMCORDER__)    
    /* do nothing now */
    memset(p_args, 0, sizeof(cui_camera_run_struct));
    p_args->req_mode = MMI_CAMERA_EXTERNAL_MODE_NORMAL;
#elif defined(__MMI_CAMERA__)
    memset(p_args, 0, sizeof(cui_camera_run_struct));
    p_args->req_mode = MMI_CAMERA_EXTERNAL_MODE_NORMAL;
#endif
}


mmi_id cui_camera_create(mmi_id parent_gid)
{
#if defined(__MMI_CAMCORDER__)
    mmi_frm_group_close (SCR_GROUP_ID_CAMCO_EXT_APP);     
    return mmi_frm_group_create (parent_gid,  SCR_GROUP_ID_CAMCO_EXT_APP, mmi_camco_cam_group_proc, NULL);
#elif defined(__MMI_CAMERA__)
    /* currently vdorec will have only one screen group, for it just single instance*/
    return mmi_frm_group_create (parent_gid,  GRP_ID_AUTO_GEN, mmi_camera_group_proc, NULL);
#endif
}


void cui_camera_run(mmi_id cui_gid, p_cui_camera_run_struct p_args) /*why no parent gid*/
{
#if defined(__MMI_CAMCORDER__)
    mmi_camco_cam_enter_from_cui(cui_gid, p_args);
#elif defined(__MMI_CAMERA__)
    mmi_camera_enter_from_cui(cui_gid, p_args);
#endif
}


void cui_camera_close(mmi_id cui_gid)
{
    mmi_frm_group_close(cui_gid);
#ifdef __MMI_AP_DCM_CAMIMGV__
	mmi_ap_send_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_CAMIMGV);
#endif
}

/*
    these two interface is just for transition period only, if all app use FW20 screen, this function is useless
*/
mmi_id cui_camera_ex_create(mmi_id parent_gid, mmi_proc_func parent_group_proc)
{
#if defined(__MMI_CAMCORDER__)
    mmi_frm_group_create(GRP_ID_ROOT, parent_gid, parent_group_proc, NULL);

    mmi_frm_group_close (SCR_GROUP_ID_CAMCO_EXT_APP);         
    return mmi_frm_group_create (parent_gid,  SCR_GROUP_ID_CAMCO_EXT_APP, mmi_camco_cam_group_proc, NULL);
#elif defined(__MMI_CAMERA__)
    mmi_frm_group_create(GRP_ID_ROOT, parent_gid, parent_group_proc, NULL);
    
    return mmi_frm_group_create(parent_gid,  GRP_ID_AUTO_GEN, mmi_camera_group_proc, NULL);
#endif
}

void cui_camera_ex_run(mmi_id parent_id, mmi_id cui_gid, p_cui_camera_run_struct p_args)
{
    mmi_frm_group_enter(parent_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    cui_camera_run(cui_gid, p_args);
}


void cui_camera_ex_close(mmi_id cui_gid)
{
    mmi_group_node_struct node_info;
    
    mmi_frm_group_get_info(cui_gid, &node_info);
    
    mmi_frm_group_close(cui_gid);
    mmi_frm_group_close(node_info.parent);
}
#ifdef __MMI_AP_DCM_CAMIMGV__
#pragma arm section code,rodata
#endif


