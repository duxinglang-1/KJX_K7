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
 * WgtMgrSrv.h
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
#ifndef WGTMGR_SRV_H
#define WGTMGR_SRV_H

#include "kal_general_types.h"
#include "MMIDataType.h"
#include "WgtMgrSrvGprot.h"
#include "WgtMgrSrvIprot.h"
#include "widget_adp_struct.h"

/************************************************************************/
/* Structure and Definition                                             */
/************************************************************************/
#ifdef __COSMOS_MMI_PACKAGE__
#define __WGTMGR_SAVE_ICON_FILE__
#endif

#ifdef __COSMOS_MMI_PACKAGE__
#define __WGTMGR_MAIN_MENU_SUPPORT__
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/* the path of widget manager folder */
#define SRV_WGTMGR_FOLDER      L"Z:\\@wgtmgr"

/* the path of widget icon folder */
#define SRV_WGTMGR_ICON_FOLDER L"Z:\\@wgtmgr\\icon"

/* the path of installed widget name data file */
#define SRV_WGTMGR_NAME_DATA_FILE      L"Z:\\@wgtmgr\\wgt_name_data"

/* the path of installed widget name guard file */
#define SRV_WGTMGR_NAME_GUARD_FILE     L"Z:\\@wgtmgr\\wgt_name_guard"

/* the path of installed widget version data file */
#define SRV_WGTMGR_VERSION_DATA_FILE   L"Z:\\@wgtmgr\\wgt_version_data"

/* the path of installed widget version guard file */
#define SRV_WGTMGR_VERSION_GUARD_FILE  L"Z:\\@wgtmgr\\wgt_version_guard"

/* the path of icon for widget installed in memory card */
#define SRV_WGTMGR_MEMCARD_WGT_ICON L"Z:\\@wgtmgr\\memcard_wgt_icon.png"

/* the maximum length of phone language */
#define SRV_WGTMGR_MAX_PHONE_LANG_CODE (8) //TODO


/* the type of sorting compare function */
typedef S32 (*srv_wgtmgr_sort_compare_func_type)(S32 left, S32 right);

/* the status of a slot for installed widget */
typedef enum
{
    SRV_WGTMGR_WGT_STATUS_NULL,     /* no widget occupies this slot. It is available. */
    SRV_WGTMGR_WGT_STATUS_ENABLED,  /* the status of widget is enabled */
    SRV_WGTMGR_WGT_STATUS_DISABLED, /* the status of widget is disabled */
    SRV_WGTMGR_WGT_STATUS_DELETING, /* the status of widget is deleting */
    SRV_WGTMGR_WGT_STATUS_UPDATING, /* the status of widget is updating */
    SRV_WGTMGR_WGT_STATUS_TOTAL_NUM
} srv_wgtmgr_wgt_status_enum;

/* the type of path */
typedef enum
{
    SRV_WGTMGR_PATH_FOLDER,    /* the path of widget folder */
    SRV_WGTMGR_PATH_ICON_DISPLAY,      /* the path of widget icon for display */
    SRV_WGTMGR_PATH_ICON_FILE,         /* the path of widget icon file */
    SRV_WGTMGR_PATH_OPTIONS_FILE,      /* the path of options file */
    SRV_WGTMGR_PATH_MAIN_VIEW,    
    SRV_WGTMGR_PATH_MANIFEST,
    SRV_WGTMGR_PATH_TOTAL_NUM
} srv_wgtmgr_path_enum;


/* the table contains all the callback functions */
typedef struct
{
    srv_wgtmgr_start_cb_func_ptr        start_cb;       /* invoked when native service is ready */
    srv_wgtmgr_delete_wgt_cb_func_ptr   delete_wgt_cb;  /* invoked when deletion of a widget is done */
    srv_wgtmgr_install_wgt_cont_cb_func_ptr      install_wgt_cont_cb;  /* invoked when verification of a widget is done */
    srv_wgtmgr_install_wgt_finished_cb_func_ptr  install_wgt_finished_cb; /* invoked when installation of a widget is done */    
    srv_wgtmgr_get_wgt_detail_cb_func_ptr        get_wgt_detail_cb;
    void * start_cb_user_data;
    void * delete_wgt_cb_user_data;
    void * install_wgt_cont_cb_user_data;
    void * install_wgt_finished_cb_user_data;
    void * get_wgt_detail_cb_user_data;
} srv_wgtmgr_cb_table_struct;

/* this table contains the request status */
typedef struct
{
    MMI_BOOL send_version_req; /* indicates that a request to version data is sent */
    MMI_BOOL send_name_req;	   /* indicates that a request to name data is sent    */
} srv_wgtmgr_req_table_struct;


/* the Widget Manager serive context */
typedef struct 
{
    MMI_BOOL is_start;
    srv_wgtmgr_wgt_asm_data_struct *asm_data; /* asm data */
#ifdef __WGTMGR_MGR_PHONE_WIDGET__
    S32 pwgt_id[SRV_WGTMGR_MAX_PHONE_WGT_NUM];       /* phone widget id */
    U8 pwgt_status[SRV_WGTMGR_MAX_PHONE_WGT_NUM];    /* Enabled native widget */
#endif
    U16 job_id;            /* used to identify the request */
    S16 updating_wgt_id;   /* to record the updating widget id */
    U32 data_account[SRV_WGTMGR_SIM_NUM];      /* data account for installed widget */
    srv_wgtmgr_cb_table_struct cb_table;      /* callback table */
    srv_wgtmgr_req_table_struct req_table;	  /* request table */
    char wgt_lang[SRV_WGTMGR_MAX_PHONE_LANG_CODE];   /* widget lange */	
    U8 dwgt_status[SRV_WGTMGR_MAX_DOWNLOADED_WGT_NUM]; /* Enabled installed widget */
    U8 dwgt_drive[SRV_WGTMGR_MAX_DOWNLOADED_WGT_NUM]; /* Enabled installed widget */
    U8 sort_order;        /* sort order of installed widget */
    U8 network_access;    /* network access setting for installed widget */
    U8 need_update_data;  /* identify if it needs to update widget name or version file */
    U8 memcard_exist;	  /* indicate if memory card exists */
    U8 da_app_id;         /* data account app id */
    MMI_BOOL wifi_only;   /* widget uses wifi only */
    char system_drive;    /* system drive letter */
    char public_drive;    /* publice drive letter */
    char memcard_drive;   /* memory card letter */
    srv_wgtmgr_sim_enum preferred_sim; 
} srv_wgtmgr_cntx_struct;


/* the structure for widget data stored in NVRAM LID */
typedef struct
{
    kal_uint8 dwgt_status[SRV_WGTMGR_MAX_DOWNLOADED_WGT_NUM];  /* installed widget status */
    srv_wgtmgr_wgt_item_struct dwgt[SRV_WGTMGR_MAX_DOWNLOADED_WGT_NUM]; /* installed widget information */
#ifdef __WGTMGR_MGR_PHONE_WIDGET__
    kal_uint8 pwgt_status[SRV_WGTMGR_MAX_PHONE_WGT_NUM];     /* native widget status */
#endif
} nvram_wgtmgr_lid_struct;



#define SRV_WGTMGR_UPDATE_NAME      0x01
#define SRV_WGTMGR_UPDATE_VERSION   0x02



/************************************************************************/
/* Internal Function Declaration                                        */
/************************************************************************/

/************************************************************************/
/* Golbal Variable                                                      */
/************************************************************************/
extern const WCHAR g_srv_wgtmgr_name_data[];     /* the path of installed widget name data file     */
extern const WCHAR g_srv_wgtmgr_name_guard[];    /* the path of installed widget name guard file    */
extern const WCHAR g_srv_wgtmgr_version_data[];  /* the path of installed widget version data file  */
extern const WCHAR g_srv_wgtmgr_version_guard[]; /* the path of installed widget version guard file */
extern const WCHAR g_srv_wgtmgr_memcard_wgt_icon[];
extern srv_wgtmgr_cntx_struct *g_srv_wgtmgr_cntx_p; /* the pointer to the context of widget manager service */


/************************************************************************/
/* Function Definition                                                  */
/************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_init
 * DESCRIPTION
 *  This function is used to init Widget Manager Service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_init(void);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_start_cont
 * DESCRIPTION
 *  This function is to continue to start the native service of Widget Manager Serive
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_start_cont(void);

/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_set_protocol_event_handler
 * DESCRIPTION
 *  This function is used to set protocol event handler 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_set_protocol_event_handler(void);

/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_sort_wgt
 * DESCRIPTION
 *  This is used to sort installed widgets
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_sort_wgt(void);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_send_name_req
 * DESCRIPTION
 *  This function is used to send WIDGET_MGR_GET_ALL_WGT_NAME_REQ to WIDGET task
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_send_name_req(void);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_send_version_req
 * DESCRIPTION
 *  This function is used to send WIDGET_MGR_GET_ALL_WGT_VERSION_REQ to WIDGET task
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_send_version_req(void);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_send_delete_wgt_req
 * DESCRIPTION
 *  This function is used to send WIDGET_MGR_DELETE_WGT_REQ to WIDGET task
 * PARAMETERS
 *  path: [IN] the path of widget file to delete
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_send_delete_wgt_req(U16 instance_id);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_send_delete_wgt_multiple_req
 * DESCRIPTION
 *  This function is used to send WIDGET_MGR_DELETE_WGT_REQ to WIDGET task
 * PARAMETERS
 *  instance_id: [IN] the instance id of widget to delete
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_send_delete_wgt_multiple_req(U8 num, U16 *instance_id);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_read_lid
 * DESCRIPTION
 *  this function is used to read data from lid
 * PARAMETERS
 *  lid_p : [OUT] the data buffer to store data
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_read_lid(nvram_wgtmgr_lid_struct *lid_p);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_write_lid
 * DESCRIPTION
 *  this function is used to write data to lid
 * PARAMETERS
 *  lid_p : [IN] the data buffer to write
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_write_lid(nvram_wgtmgr_lid_struct *lid_p);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_read_wgt_info_from_nvram
 * DESCRIPTION
 *  This function reads widget information from NVRAM LID
 * PARAMETERS
 *  info: [OUT] the buffer to store widget info
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_read_wgt_info_from_nvram(srv_wgtmgr_wgt_item_struct* info);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_read_wgt_info_from_nvram_by_id
 * DESCRIPTION
 *  This function reads widget information from NVRAM LID
 * PARAMETERS
 *  id  : [IN]  widget id
 *  info: [OUT] the buffer to store the widget info
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_read_wgt_info_from_nvram_by_id(S32 id, srv_wgtmgr_wgt_item_struct* info);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_read_name_or_version_from_file
 * DESCRIPTION
 *  This function reads widget name or file from file
 * PARAMETERS
 *  type : [IN]
           SRV_WGTMGR_UPDATE_VERSION : to read version
           SRV_WGTMGR_UPDATE_NAME: to read name
 * RETURNS
 *  MMI_TRUE: success, MMI_FALSE: fail
 *****************************************************************************/
extern MMI_BOOL srv_wgtmgr_read_name_or_version_from_file(int type);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_save_nvram_lid
 * DESCRIPTION
 *  This function saves widget info to lid
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_save_nvram_lid(void);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_path
 * DESCRIPTION
 *  This function is used to get path of a widget
 * PARAMETERS
 *  id     : [IN] the widget id
 *  type   : [IN] type of path
 *  path   : [OUT] the path in query
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_get_path(
       S32 id, 
       srv_wgtmgr_path_enum type, 
       WCHAR *path);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_save_wgt_status_to_nvram
 * DESCRIPTION
 *  Save widget status to nvram
 *  This is used when widget manager does not have lid data in hand
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_save_wgt_status_to_nvram(void);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_save_wgt_name_and_version_to_file
 * DESCRIPTION
 *  Save the name and version of a widget to file 
 * PARAMETERS
 *  id      : [IN] the widget id
 *  name    : [IN] the widget name
 *  version : [IN] the widget version
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_save_wgt_name_and_version_to_file(U16 id, WCHAR *name, WCHAR *version);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_save_wgt_info_to_nvram
 * DESCRIPTION
 *  Save the info of a widget to nvram
 * PARAMETERS
 *  id  : [IN] the widget id
 *  wgt : [IN] the info of the widget
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_save_wgt_info_to_nvram(U16 id, srv_wgtmgr_wgt_item_struct *wgt);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_unload_and_disable_all_downloaded_wgt
 * DESCRIPTION
 *  unload and disable all downloaded widget installed in a particular drive 
 * PARAMETERS
 *  drive: [IN] the specified drive
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_unload_and_disable_all_downloaded_wgt(srv_wgtmgr_wgt_drive_enum drive);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_delete_wgt_int
 * DESCRIPTION
 *  This function is used to send WIDGET_MGR_DELETE_WGT_REQ to WIDGET task
 * PARAMETERS
 *  id: [IN] the id of widget to delete
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_delete_wgt_int(U16 id);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_drive_letter
 * DESCRIPTION
 *  This is the function to get drive letter
 * PARAMETERS
 *  drive: [IN]
 * RETURNS
 *  drive letter
 *****************************************************************************/
extern char srv_wgtmgr_get_drive_letter(srv_wgtmgr_wgt_drive_enum drive);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_set_data_need_update
 * DESCRIPTION
 *  Set need_update_name to TRUE
 * PARAMETERS
 *  mode : [IN] specify which data need to be updated
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_set_data_need_update(int mode);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_current_time_in_sec
 * DESCRIPTION
 *  this funciton is to get current time in sec
 * PARAMETERS
 *  void
 * RETURNS
 *  U32
 *****************************************************************************/
extern U32 srv_wgtmgr_get_current_time_in_sec(void);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_is_memcard_available
 * DESCRIPTION
 *  This is the function to check memory card status
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if memory card is available
 *****************************************************************************/
extern MMI_BOOL srv_wgtmgr_is_memcard_available(void);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_dtcnt_ready_check
 * DESCRIPTION
 *  This function is to check if data account is ready
 * PARAMETERS
 *  ready_callback:  [IN] callback function
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_wgtmgr_dtcnt_ready_check(FuncPtr ready_callback);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_dtcnt_acct_is_valid
 * DESCRIPTION
 *  This function is to check if a id is valid
 * PARAMETERS
 *  id:  [IN] data account id 
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_wgtmgr_dtcnt_acct_is_valid(U32 id);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_is_preinstall_widget_finished
 * DESCRIPTION
 *  This function is used to check if widget preinstallation is finished
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
extern MMI_BOOL srv_wgtmgr_is_preinstall_widget_finished();


#ifdef __cplusplus
}
#endif
#endif /* WGTMGR_SRV_H */

