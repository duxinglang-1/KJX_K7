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
 *   CameraCuiGprot.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef CUI_CAMERACCUI_GPROT_H
#define CUI_CAMERACCUI_GPROT_H

/*******************************************************************************
* Include Header File
*******************************************************************************/
#if defined(__COSMOS_MMI_PACKAGE__)
#define CAMERA_BASE 0
#endif
/*******************************************************************************
* Structure Define
*******************************************************************************/
/* common UI struct */
#if defined(__MMI_CAMCORDER__)
typedef struct
{
    U32 req_mode;
} cui_camera_run_struct, *p_cui_camera_run_struct;
#else
typedef struct
{
    U32 req_mode;
} cui_camera_run_struct, *p_cui_camera_run_struct;
#endif

/* common UI event struct*/
#if defined(__MMI_CAMCORDER__)
typedef struct  
{
    MMI_EVT_GROUP_PARAM_HEADER
    CHAR* file_path;
} cui_camera_event_struct;
#else
typedef struct  
{
    MMI_EVT_GROUP_PARAM_HEADER
    PS8 file_path;
} cui_camera_event_struct;
#endif
/*******************************************************************************
* Enum Define
*******************************************************************************/
/* camera event enum */
#if defined(__MMI_CAMCORDER__)
typedef enum
{
    CUI_CAMERA_EVENT_RESULT_SUCCESS = CAMCORDER_BASE,
    CUI_CAMERA_EVENT_RESULT_FAILED,
    CUI_CAMERA_EVENT_RESULT_CLOSE_ME,

    CUI_CAMERA_EVENT_ALL
} cui_camera_event_enum;
#else
typedef enum
{
    CUI_CAMERA_EVENT_RESULT_SUCCESS = CAMERA_BASE,
    CUI_CAMERA_EVENT_RESULT_FAILED,
    CUI_CAMERA_EVENT_RESULT_CLOSE_ME,
    CUI_CAMCO_CAM_EVENT_ALL
    
} cui_camera_event_enum;
#endif
/*******************************************************************************
* Macro Define
*******************************************************************************/


/*******************************************************************************
* Export API 
*******************************************************************************/

/*****************************************************************************              
 * FUNCTION
 *   cui_camera_struct_init
 * DESCRIPTION
 *   init camera struct
 * PARAMETERS
 *  p_args      : [OUT] camera cui struct
 * RETURNS
 *  None
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_camera_struct_init(p_cui_camera_run_struct p_args);

/*****************************************************************************              
 * FUNCTION
 *   cui_camera_create
 * DESCRIPTION
 *   camera cui group create
 * PARAMETERS
 *  parent_gid  : [IN] parent group ID
 * RETURNS
 *  camera cui group ID
 * RETURN VALUES
 *  camera cui group ID
*****************************************************************************/
extern mmi_id cui_camera_create(mmi_id parent_gid);

/*****************************************************************************              
 * FUNCTION
 *   cui_camera_run
 * DESCRIPTION
 *   camera cui run
 * PARAMETERS
 *  parent_gid : [IN] camera cui group ID
 *  p_args     : [IN] camera structure to receive parameter
 * RETURNS
 *  None
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_camera_run(mmi_id cui_gid, p_cui_camera_run_struct p_args);

/*****************************************************************************              
 * FUNCTION
 *   cui_camera_close
 * DESCRIPTION
 *   close camera cui
 * PARAMETERS
 *  cui_gid     : [IN] camera cui group id
 * RETURNS
 *  None
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_camera_close(mmi_id cui_gid);

/*****************************************************************************              
 * FUNCTION
 *   cui_camera_ex_create
 * DESCRIPTION
 *   create CUI. currently APP do not have screen group realization, 
 *   and we will realize screen group first, So we will make the easy to use our CUI,
 *   Even them do not have screen group, we will create the group in cui create
 * PARAMETERS
 *  parent_gid :        [IN] parent group ID
 *  parent_group_proc : [IN] parent group proc function
 * RETURNS
 *  CUI screen group ID
 * RETURN VALUES
 *  CUI screen group ID
*****************************************************************************/
extern mmi_id cui_camera_ex_create(mmi_id parent_gid, mmi_proc_func parent_group_proc);

/*****************************************************************************              
 * FUNCTION
 *   cui_vdorec_ex_run
 * DESCRIPTION
 *   run cui. Currently we will help parent to entry parent group ,
 *   and then we will entry CUI group, So parent group do not have any screen,
 *   it exists just for using the group proc function
 * PARAMETERS
 *  parent_gid : [IN] parent group ID
 *  cui_gid    : [IN] CUI group ID
 *  p_cui_vdorec_run_struct : [IN] CUI structure to receive para
 * RETURNS
 *  None
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_camera_ex_run(mmi_id parent_gid, mmi_id cui_gid, p_cui_camera_run_struct p_args);

/*****************************************************************************              
 * FUNCTION
 *   cui_camera_ex_close
 * DESCRIPTION
 *   close camera cui
 * PARAMETERS
 *  cui_gid     : [IN] camera cui group id
 * RETURNS
 *  None
 * RETURN VALUES
 *  None
*****************************************************************************/
extern void cui_camera_ex_close(mmi_id cui_gid);

/*****************************************************************************              
 * FUNCTION
 *   cui_camera_check_and_display_popup
 * DESCRIPTION
 *   before enter camera cui, we will check the run codition is ok or not
 *   if NOK, parent should not create/run the camera cui.
 * PARAMETERS
 *  None
 * RETURNS
 *  if the camera cui is ready for running or not
 * RETURN VALUES
 *  if the camera cui is ready for running or not
*****************************************************************************/
extern MMI_BOOL cui_camera_check_and_display_popup(void);

#endif /* CUI_CAMERACCUI_GPROT_H */ 

