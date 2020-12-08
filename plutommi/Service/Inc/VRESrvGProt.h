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
 *  VRESrvGProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  VRE external interface.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __VRESRVGPROT_H__
#define __VRESRVGPROT_H__

#include "MMIDataType.h"

typedef enum
{
    SRV_VRE_CALLER_NULL,
    SRV_VRE_CALLER_SERVICE,
    SRV_VRE_CALLER_AM,
    SRV_VRE_CALLER_DOWNLOAD,
    SRV_VRE_CALLER_END_OF_ENUM
} srv_vre_load_core_caller_enum;

typedef enum
{
    SRV_VRE_LOAD_CORE_SUCCESS = 0,
    SRV_VRE_LOAD_CORE_ASYN_ALLOC_ASM,
    SRV_VRE_LOAD_CORE_MASS_STORAGE,
    SRV_VRE_LOAD_CORE_INTERNEL_ERROR,
    SRV_VRE_LOAD_CORE_END_OF_ENUM
} srv_vre_load_core_result_enum;

typedef enum
{
    SRV_VRE_LOAD_CORE_EVT_SUCCESS = 0,
    SRV_VRE_LOAD_CORE_EVT_INTERNAL_ERROR,
    SRV_VRE_LOAD_CORE_EVT_QUIT,
    SRV_VRE_LOAD_CORE_EVT_END_OF_ENUM
} srv_vre_load_core_evt_enum;

typedef enum
{
    SRV_VRE_LAUNCH_APP_EVT_SUCCESS = 0,
    SRV_VRE_LAUNCH_APP_ASM_READY,
    SRV_VRE_LAUNCH_APP_EVT_INTERNEL_ERROR,
    SRV_VRE_LAUNCH_APP_EVT_QUIT,
    SRV_VRE_LAUNCH_APP_EVT_END_OF_ENUM
} srv_vre_launch_app_evt_enum;

typedef void (*srv_vre_load_core_cb_t) (srv_vre_load_core_evt_enum evt);
typedef void (*srv_vre_launch_app_cb_t) (U16 *app_path, srv_vre_launch_app_evt_enum evt);

/* App start result */
typedef enum
{
    SRV_VRE_LAUNCH_APP_SUCCESS = 0,
    SRV_VRE_LAUNCH_APP_ILLEGAL,
    SRV_VRE_LAUNCH_APP_NOT_ENOUGH_MEMORY,
    SRV_VRE_LAUNCH_APP_CALL_STACK_FULL,
    SRV_VRE_LAUNCH_APP_INTERNAL_ERROR,
    SRV_VRE_LAUNCH_APP_PLATFORM_PARAM_DISMATCH,
    SRV_VRE_LAUNCH_APP_TIMESTAMP_ERROR,
    SRV_VRE_LAUNCH_APP_BANNED_APP,
    SRV_VRE_LAUNCH_APP_IMSI_DISMATCH,
    SRV_VRE_LAUNCH_APP_CERT_OVERDUE,
    SRV_VRE_LAUNCH_APP_EXCEED_FILE_IN_VRE_DIRECTORY,
    SRV_VRE_LAUNCH_APP_SYS_ASYN_ASM,
    SRV_VRE_LAUNCH_APP_BAD_PARAM,
    SRV_VRE_LAUNCH_APP_END_OF_ENUM
} srv_vre_launch_app_result_enum;

typedef enum
{
    SRV_VRE_APP_STATE_UNKNOWN,
    SRV_VRE_APP_STATE_NONEXIST,
    SRV_VRE_APP_STATE_NONSTART,
    SRV_VRE_APP_STATE_STARTING,
    SRV_VRE_APP_STATE_FORGROUND,
    SRV_VRE_APP_STATE_INACTIVE,
    SRV_VRE_APP_STATE_BACKGROUND,
    SRV_VRE_APP_STATE_CLOSING,
    SRV_VRE_APP_STATE_END_OF_ENUM
} srv_vre_check_app_state_result_enum;

typedef enum
{
    SRV_VRE_INFO_NULL,      /* NULL */
    SRV_VRE_INFO_DEV,       /* developer */
    SRV_VRE_INFO_APP_ID,    /* app id */
    SRV_VRE_INFO_NAME,      /* app name */
    SRV_VRE_INFO_VER,       /* app version id */
    SRV_VRE_INFO_DESC,      /* app introduction */
    SRV_VRE_INFO_TEL,       /* telephone number */
    SRV_VRE_INFO_BG_RUN,    /* wether support bg run */
    SRV_VRE_INFO_END_OF_ENUM
} srv_vre_info_type_enum;

typedef struct
{
    srv_vre_info_type_enum info_id[SRV_VRE_INFO_END_OF_ENUM];
    S32 info_size[SRV_VRE_INFO_END_OF_ENUM];
    S8 *info_data[SRV_VRE_INFO_END_OF_ENUM];
} srv_vre_multi_info_struct;

typedef enum
{
    SRV_VRE_VERITY_INSUFFICIENT_SYS_MEM,
    SRV_VRE_VERIFY_KEY_EXPIRED,         /* fail to invoke the check func */
    SRV_VRE_VERIFY_CHECK_PARAM_FAIL,    /* fail to invoke the check func */
    SRV_VRE_VERIFY_PER_MEM_ERROR,
    SRV_VRE_VERIFY_PER_INIT_ERROR,      /* can not initial permission system */
    SRV_VRE_VERIFY_PER_CATCH_ERROR,     /* compose func list error */
    SRV_VRE_VERIFY_RESOLUTION_DISMATCH, /* the lcd size is smalled than the app requirements */
    SRV_VRE_VERIFY_INSUFFICIENT_MEM,    /* the system can not provide enough memory to run the app */
    SRV_VRE_VERIFY_TIMESTAMP_ERROR,
    SRV_VRE_VERIFY_IMSI_DISMATCH,       /* the app is personal used and the user is not matched */
    SRV_VRE_VERIFY_APP_BANNED,          /* the app is banned */
    SRV_VRE_VERIFY_DIGEST_DISMATCH,     /* the verify result is not matched with the desired one */
    SRV_VRE_VERIFY_VERIFY_FAILED,       /* can not finish the verification with the assigned pub key */
    SRV_VRE_VERIFY_BAD_DIGEST,          /* can not caculate app & cert digest */
    SRV_VRE_VERIFY_BAD_PARAM,           /* can not catch the Cert envelope structure OR can not catch the digest string OR */
    /* any of the points to CertID, AppID, IssueData and ExpiredData is NULL */

    SRV_VRE_VERIFY_OK,  /* verify finished and the app is OK to run */
    SRV_VRE_VERIFY_END_OF_ENUM
} srv_vre_verify_result_enum;

/*****************************************************************************
 * FUNCTION
 *  srv_vre_is_core_loaded
 * DESCRIPTION
 *  Check if VRE Core is loaded.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MMI_TRUE : If loaded.
 *  MMI_FALSE : If not loaded.
 *****************************************************************************/
extern MMI_BOOL srv_vre_is_core_loaded(void);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_load_core
 * DESCRIPTION
 *  Load VRE Core.
 * PARAMETERS
 *  load_cb : [IN]  Callback function.
 *  caller : [IN] Type of load VRE core.
 * RETURN VALUES
 *  TODO:
 *****************************************************************************/
extern srv_vre_load_core_result_enum srv_vre_load_core(
                                        srv_vre_load_core_cb_t load_cb,
                                        srv_vre_load_core_caller_enum caller);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_unload_core
 * DESCRIPTION
 *  Unload VRE Core.
 * PARAMETERS
 *  caller : [IN] Type of load VRE core.
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void srv_vre_unload_core(srv_vre_load_core_caller_enum caller);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_launch_app
 * DESCRIPTION
 *  Launch a VRE application.
 * PARAMETERS
 *  app_path : [IN]  VRE application full path.
 *  app_cb : [IN] Callback function.
 * RETURN VALUES
 *  
 *****************************************************************************/
extern srv_vre_launch_app_result_enum srv_vre_launch_app(U16 *app_path, srv_vre_launch_app_cb_t app_cb);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_close_app
 * DESCRIPTION
 *  Close a VRE application.
 * PARAMETERS
 *  app_path : [IN]  VRE application full path.
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void srv_vre_close_app(U16 *app_path);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_get_app_state
 * DESCRIPTION
 *  Get the application's state, including FG RUNNING, BG RUNNING and CLOSE.
 * PARAMETERS
 *  app_path : [IN]  VRE application full path.
 * RETURN VALUES
 *  .
 *****************************************************************************/
extern srv_vre_check_app_state_result_enum srv_vre_get_app_state(U16 *app_path);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_get_info_by_tag
 * DESCRIPTION
 *  Get info by tag.
 * PARAMETERS
 *  app_path : [IN]  VRE application full path.
 *  tag : [IN] Tag type.
 *  des_buf : [OUT] Destination buffer.
 *  des_size : [OUT] Destination buffer size.
 *  lan_type : [IN] Language type.
 * RETURN VALUES
 *  MMI_TRUE : If successful.
 *  MMI_FALSE : If failed.
 *****************************************************************************/
extern MMI_BOOL srv_vre_get_info_by_tag(
                    U16 *app_path,
                    srv_vre_info_type_enum tag,
                    void *des_buf,
                    U32 *des_size,
                    S32 lan_type);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_get_app_image
 * DESCRIPTION
 *  Get the image data of a VRE application. If p_img is NULL, then return the image size by img_size.
 * PARAMETERS
 *  app_path : [IN]  VRE application full path.
 *  p_img : [OUT] Pointer to image buffer.
 *  img_size : [OUT] Size of image.
 * RETURN VALUES
 *  MMI_TRUE : If successful.
 *  MMI_FALSE : If failed.
 *****************************************************************************/
extern MMI_BOOL srv_vre_get_app_image(U16 *app_path, U8 *p_img, U32 *img_size);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_get_app_name
 * DESCRIPTION
 *  Get the name of a VRE application. If p_name is NULL, then return the name size by name_size.
 * PARAMETERS
 *  app_path : [IN]  VRE application full path.
 *  p_name : [OUT] Pointer to name buffer.
 *  name_size : [OUT] Size of name.
 * RETURN VALUES
 *  MMI_TRUE : If successful.
 *  MMI_FALSE : If failed.
 *****************************************************************************/
extern MMI_BOOL srv_vre_get_app_name(U16 *app_path, U16 *p_name, U32 *name_size);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_get_app_name
 * DESCRIPTION
 *  Get the zimo name of a VRE application. If zimo_buf is NULL, then return the name size by name_size.
 * PARAMETERS
 *  app_path : [IN]  VRE application full path.
 *  zimo_buf : [OUT] Pointer to name buffer.
 *  name_size : [OUT] Size of name.
 *  name_len : [OUT] Length of name.
 * RETURN VALUES
 *  MMI_TRUE : If successful.
 *  MMI_FALSE : If failed.
 *****************************************************************************/
extern MMI_BOOL srv_vre_get_app_zimo_name(U16 *app_path, S8 *zimo_buf, U32 *name_size, U32 *name_len);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_get_app_version
 * DESCRIPTION
 *  Get the version id of a VRE application. The version id use format x.y.z which present by a U32.
 * PARAMETERS
 *  app_path : [IN]  VRE application full path.
 *  version : [OUT] Version id, first byte is x, second byte is y, third byte is z.
 * RETURN VALUES
 *  MMI_TRUE : If successful.
 *  MMI_FALSE : If failed.
 *****************************************************************************/
extern MMI_BOOL srv_vre_get_app_version(U16 *app_path, S32 *version);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_get_app_id
 * DESCRIPTION
 *  Get the id of a VRE application. The id uses 32-bits.
 * PARAMETERS
 *  app_path : [IN]  VRE application full path.
 *  p_id : [OUT] Pointer to id buffer.
 * RETURN VALUES
 *  MMI_TRUE : If successful.
 *  MMI_FALSE : If failed.
 *****************************************************************************/
extern MMI_BOOL srv_vre_get_app_id(U16 *app_path, U32 *p_id);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_get_app_developer
 * DESCRIPTION
 *  Get the developer name of a VRE application. If p_developer is NULL, then return the name size by developer_size.
 * PARAMETERS
 *  app_path : [IN]  VRE application full path.
 *  p_developer : [OUT] Pointer to developer name buffer.
 *  developer_size : [OUT] Size of developer name.
 * RETURN VALUES
 *  MMI_TRUE : If successful.
 *  MMI_FALSE : If failed.
 *****************************************************************************/
extern MMI_BOOL srv_vre_get_app_developer(U16 *app_path, U16 *p_developer, U32 *developer_size);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_get_app_description
 * DESCRIPTION
 *  Get the description of a VRE application. If p_desc is NULL, then return the description size by desc_size.
 * PARAMETERS
 *  app_path : [IN]  VRE application full path.
 *  p_desc : [OUT] Pointer to app description buffer.
 *  desc_size : [OUT] Size of app description.
 * RETURN VALUES
 *  MMI_TRUE : If successful.
 *  MMI_FALSE : If failed.
 *****************************************************************************/
extern MMI_BOOL srv_vre_get_app_description(U16 *app_path, U16 *p_desc, U32 *desc_size);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_get_app_tel
 * DESCRIPTION
 *  Get the telephone number of the developer.
 * PARAMETERS
 *  app_path : [IN]  VRE application full path.
 *  p_tel : [OUT] Pointer to telephone number buffer, and the length of number less than 20.
 * RETURN VALUES
 *  MMI_TRUE : If successful.
 *  MMI_FALSE : If failed.
 *****************************************************************************/
extern MMI_BOOL srv_vre_get_app_tel(U16 *app_path, U16 *p_tel);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_is_app_bg_running
 * DESCRIPTION
 *  Check if the application is running in background.
 * PARAMETERS
 *  app_path : [IN]  VRE application full path.
 * RETURN VALUES
 *  MMI_TRUE : If support.
 *  MMI_FALSE : If not support.
 *****************************************************************************/
extern MMI_BOOL srv_vre_is_app_bg_running(U16 *app_path);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_is_app_support_bg_running
 * DESCRIPTION
 *  Check if the application support background running.
 * PARAMETERS
 *  app_path : [IN]  VRE application full path.
 * RETURN VALUES
 *  MMI_TRUE : If support.
 *  MMI_FALSE : If not support.
 *****************************************************************************/
extern MMI_BOOL srv_vre_is_app_support_bg_running(U16 *app_path);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_get_multi_info
 * DESCRIPTION
 *  Get multiple information from file or rom.
 * PARAMETERS
 *  app_path : [IN]  VRE application full path.
 *  tag : [IN] Tag type.
 *  des_buf : [OUT] Destination buffer.
 *  des_size : [OUT] Destination buffer size.
 * RETURN VALUES
 *  MMI_TRUE : If successful.
 *  MMI_FALSE : If failed.
 *****************************************************************************/
extern MMI_BOOL srv_vre_get_multi_info(U16 *app_path, srv_vre_multi_info_struct *info_req);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_get_buildin_app_list
 * DESCRIPTION
 *  Get build-in application full path list. You should get call srv_vre_get_buildin_app_list(NULL, app_num) firstly
 *  to get application number, and then prepare enough memory to get the list.
 * PARAMETERS
 *  app_path_list : [IN]  List of build in application full path.
 *  app_num : [OUT]  Number of build in application.
 * RETURNS
 *  Return number of build in applications
 *****************************************************************************/
extern U32 srv_vre_get_buildin_app_list(U16 **app_list, U32 *app_num);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_is_buildin_app
 * DESCRIPTION
 *  Check if the app is build-in application.
 * PARAMETERS
 *  app_path : [IN]  VRE application full path.
 * RETURN VALUES
 *  MMI_TRUE : If it is a build-in application.
 *  MMI_FALSE : If it is not a build-in application.
 *****************************************************************************/
extern MMI_BOOL srv_vre_is_buildin_app(U16 *app_path);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_is_using_media_buffer
 * DESCRIPTION
 *  Check if VRE using media buffer.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MMI_TRUE : If using media buffer.
 *  MMI_FALSE : If not using media buffer.
 *****************************************************************************/
extern MMI_BOOL srv_vre_is_using_media_buffer(void);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_is_app_valid
 * DESCRIPTION
 *  Check if the application is valid.
 * PARAMETERS
 *  app_path : [IN]  VRE application full path.
 * RETURN VALUES
 *  
 *****************************************************************************/
extern srv_vre_verify_result_enum srv_vre_is_app_valid(U16 *app_path);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_is_first_load_core
 * DESCRIPTION
 *  Check if it is the first time to load VRE Core.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MMI_TRUE : If it is the first time.
 *  MMI_FALSE : If it is not the first time.
 *****************************************************************************/
extern MMI_BOOL srv_vre_is_first_load_core(void);

/***************************************************************************** 
 * FUNCTION
 *  srv_vre_get_bg_app_num
 * DESCRIPTION
 *  get the number of background running app.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  background running app number
 *****************************************************************************/
U32 srv_vre_get_bg_app_num(void);


/*****************************************************************************
 * FUNCTION
 *  srv_vre_get_bg_filename
 * DESCRIPTION
 *  get the background running file name of specified index
 * PARAMETERS
 *  index : [IN] the index of background running application to be checked.
 *  filename : [OUT] the file name of specified index of background running application.
 *  size : [IN] the buffer size of the parameter of filename
 * RETURN VALUES
 *  MMI_TRUE : get file name successfully
 *  MMI_FALSE : there is no background running application of specified index
 *****************************************************************************/
MMI_BOOL srv_vre_get_bg_filename(U32 index, U16* filename, U32 size);



/***************************************************************************** 
* application communication service apis
*****************************************************************************/
   
typedef S32 (*SRV_VRE_MSG_PROC) (S32 sender, U32 msg_id, S32 wparam, S32 lparam);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_get_running_handle
 * DESCRIPTION
 *  get process handle of specified file name
 * PARAMETERS
 *  handle : [IN] file name to be checked. 
 * RETURNS
 *  the process ID of specified file if larger than zero, 0 means there is no specified file running 
 *****************************************************************************/
S32 srv_vre_get_running_handle(WCHAR * file_name);


/*****************************************************************************
 * FUNCTION
 *  srv_vre_reg_msg_proc
 * DESCRIPTION
 *  register VRE message proc
 * PARAMETERS
 *  handle : [IN] message sender handle, if despite of sender, this parameter should be set to zero.
 *  proc : [IN] message proc
 * RETURNS
 *  1 if register successfully
 *  0 if register failed
 *****************************************************************************/
S32 srv_vre_reg_msg_proc(S32 handle, SRV_VRE_MSG_PROC proc);


/*****************************************************************************
 * FUNCTION
 *  srv_vre_dereg_msg_proc
 * DESCRIPTION
 *  deregister VRE message proc
 * PARAMETERS
 *  handle : [IN] message sender handle, if despite of sender, this parameter should be set to zero.
 *  proc : [IN] message proc
 * RETURNS
 *  1 if deregister successfully
 *  0 if deregister failed
 *****************************************************************************/
S32 srv_vre_dereg_msg_proc(S32 handle, SRV_VRE_MSG_PROC proc);


/*****************************************************************************
 * FUNCTION
 *  srv_vre_send_msg
 * DESCRIPTION
 *  send message to VRE app or native app, will invoke message procedure directly.
 * PARAMETERS
 *  phandle : [IN] receiver process handle, if receiver is native application, this value should be zero.
 *  msg_id : [IN] user defined message ID, should larger than VM_MESSAGE_ID_BASE.
 *  wparam : [IN] wparam of message.
 *  lparam : [IN] lparam of message.
 * RETURNS
 *  message procedure return value.
 *****************************************************************************/
S32 srv_vre_send_msg(S32 handle, U32 msg_id, S32 wparam, S32 lparam);


/*****************************************************************************
 * FUNCTION
 *  srv_vre_send_msg
 * DESCRIPTION
 *  send message to VRE app or native app, will invoke message procedure directly.
 * PARAMETERS
 *  phandle : [IN] receiver process handle, if receiver is native application, this value should be zero.
 *  msg_id : [IN] user defined message ID, should larger than VM_MESSAGE_ID_BASE.
 *  wparam : [IN] wparam of message.
 *  lparam : [IN] lparam of message.
 * RETURNS
 *  message procedure return value.
 *****************************************************************************/
S32 srv_vre_post_msg(S32 handle, U32 msg_id, S32 wparam, S32 lparam);

/***************************************************************************** 
 * FUNCTION
 *  srv_vre_get_group_id
 * DESCRIPTION
 *  Get the screen group id of current VRE App
 * RETURNS
 *  Screen group id of current VRE App
 *****************************************************************************/
U32 srv_vre_get_group_id(void);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_get_res_base
 * DESCRIPTION
 *  Get the MMI resource base of current VRE App
 * RETURNS
 *  MMI resource base of current VRE App
 *****************************************************************************/
U32 srv_vre_get_res_base(void);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_set_venus_flag
 * DESCRIPTION
 *  set Venus flag of MRE app, MRE will trigger key and pen handler even if app is background running
 *****************************************************************************/
void srv_vre_set_venus_flag(void);
/***************************************************************************** 
* Download service apis
*****************************************************************************/
/*
 * TODO: Add by Nan
 */

#endif /* __VRESRVGPROT_H__ */ 

