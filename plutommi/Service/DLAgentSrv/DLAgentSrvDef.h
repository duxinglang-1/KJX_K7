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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *
 *
 * Project:
 * --------
 *  MAUI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef DOWNLOAD_AGENT_DEF_H
#define DOWNLOAD_AGENT_DEF_H

//#ifdef __COSMOS_MMI_PACKAGE__
#include "kal_general_types.h"


/****************************************************************************
 * Constants                                                             
 ****************************************************************************/

/*
 * Maximum length of file path that download agent supports.
 * NOTE: This value is not the same to that file manager can handles.
 */
#define SRV_DA_MAX_FILE_PATH_LEN                260

/*
 * Maximum length of file name that download agent supports.
 * NOTE: This value is not the same to that file manager can handles.
 */
#define SRV_DA_MAX_FILE_NAME_LEN                128

/*
 * Length of URL field in mmi_da_dispatch_file_req_struct.
 */
#define SRV_DA_MAX_DISPATCH_FILE_REQ_URL_LEN    31

/*
 * Maximum length of MIME type string that download agent supports.
 */
#define SRV_DA_MAX_MIME_TYPE_STRING_LEN         255

/*
 * The size of data field of srv_da_extra_info_struct.
 */
#define SRV_DA_MAX_EXTRA_INFO_DATA_SIZE         260


/*
 * Error code used in callbacks or returned by download APIs.
 */
typedef enum
{
    SRV_DA_SUCCESS = 0,                     /* Action or request completed successfully */
    SRV_DA_ERROR_USER_CANCELLED = -1,       /* User cancelled the action */
    SRV_DA_ERROR_CONNECTION_CLOSED = -2,    /* Connection closed */
    SRV_DA_ERROR_DISK_FULL = -3,            /* Disk full while saving */
    SRV_DA_ERROR_FILE_ACCESS = -4,          /* Any file system error while saving */
    SRV_DA_ERROR_BROWSER_CLOSED = -5,       /* Browser closed so download is stopped or suspended */
    SRV_DA_ERROR_OTHERS = -100,             /* Other errors not defined */
    SRV_DA_ERROR_FAIL = -9999               /* Fail to complete a request */
} srv_da_error_enum;


/*
 * Download status which will be reported via report_hdlr().
 * SEE ALSO
 *  srv_da_report_hdlr, srv_da_setting_hdlr.
 */
typedef enum
{
    SRV_DA_STATE_INIT,          /* Download is in initialization */
    SRV_DA_STATE_DOWNLOADING,   /* Downloading */
    SRV_DA_STATE_COMPLETE,      /* Completed */
    SRV_DA_STATE_ABORT,         /* Aborted.
        If can_minimize == MMI_FALSE and any error occurs while downloading,
        the state of download will be changed to ABORTED state. Then
        the download will be removed from download list permanently.*/
        
    SRV_DA_STATE_PAUSE,         /* Paused.
        If can_minimize == MMI_TRUE and any error occurs while downloading,
        the state of download will be changed to PAUSED state. User can
        see the item when go back to download list and is allowed to select "Play"
        to report again. See also srv_da_filepath_hdlr, srv_da_report_hdlr. */
        
    SRV_DA_STATE_USER_CANCEL,   /* User cancelled the download.
        The download item is removed from list. */

    SRV_DA_STATE_END_OF_ENUM
} srv_da_state_enum;


/*
 * Storage parameter of setting. Download agent determines storage-selection policy
 * to decide the storage by this parameter.
 * SEE ALSO
 *  srv_da_setting_hdlr.
 */
typedef enum
{
    SRV_DA_STORAGE_NONE,    /* The same to SRV_DA_STORAGE_USER_SELECT. */
    
    SRV_DA_STORAGE_USER_SELECT = SRV_DA_STORAGE_NONE, /*
        Let user to decide storage. That is, provide an interface to user to select
        drive and input filename. */
        
    SRV_DA_STORAGE_GIVEN, /*
        Use the given drive.
        Application has to explicitly assign a drive to store the file. */
        
    SRV_DA_STORAGE_AUTO, /*
        Let DLAgent to select drive. The same to SRV_DA_STORAGE_ANY.  */
    
    SRV_DA_STORAGE_ANY = SRV_DA_STORAGE_AUTO, /*
        Any user drive can be accepted. Download agent will decide an proper user drive to
        store the file by checking available storages and storage sizes. */

    SRV_DA_STORAGE_PUSH_TEMP, /*
        Store in a temp folder, MAYBE IN SYSTEM DRIVE. If application processed the file
        after dispatching, be sure to delete the file by the application itself.
        This setting is legal only for push! */

    SRV_DA_STORAGE_PHONE,       /* Applications DO NOT use this enum value as the setting parameter */
    SRV_DA_STORAGE_MEMORY_CARD, /* Applications DO NOT use this enum value as the setting parameter */
    SRV_DA_STORAGE_OTHERS = 99, /* Applications DO NOT use this enum value as the setting parameter */

    SRV_DA_STORAGE_END_OF_ENUM
} srv_da_storage_enum;

/*
 * Method of file source. From push, or download or other method.
 */
typedef enum
{
    MMI_DA_NONE,                        /* Unknown source */
    MMI_DA_WAP_DOWNLOAD,                /* Via HTTP download */
    MMI_DA_OMA_DOWNLOAD,                /* Via OMA download OTA */
    MMI_DA_SAVE_AS,                     /* Object save-as of an application */
    
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_DA_DOWNLOAD = MMI_DA_SAVE_AS,   /* OBSOLETE */
    MMI_DA_WAP_SAVE,                    /* OBSOLETE */
    /* DOM-NOT_FOR_SDK-END */
    
    MMI_DA_PUSH,                        /* Via WAP push.
        In dual SIM project, it means from SIM 1; but use MMI_DA_PUSH_SIM1 / MMI_DA_PUSH_SIM2 instead is recommended. */
    
    MMI_DA_PUSH_SIM1 = MMI_DA_PUSH,     /* Push from SIM 1 */
    MMI_DA_PUSH_SIM2,                   /* Push from SIM 2 */
    MMI_DA_PUSH_SIM3,                   /* Push from SIM 3 */
    MMI_DA_PUSH_SIM4,                   /* Push from SIM 4 */

    MMI_DA_ACTION_END_OF_ENUM
} srv_da_action_enum;


/****************************************************************************
 * Structures
 ****************************************************************************/

/*********************************************************************************
  * UI parameter for save-object. Application can use this parameter to
  * control UI detail of download agent screens.
  * 
  * <paraattr align="center">
  * <img name="SAP_DA_mmi_da_ui_setting_struct" text="mmi_da_ui_setting_struct" />
  * Title icon &amp; title string
  * </paraattr>
  * 
  * See srv_da_save_file.                                                         
  *********************************************************************************/
typedef struct
{
    kal_uint16 title_string_id; /* String to be put on title, usually application name */
    kal_uint16 title_icon_id;   /* Icon to be put on title, usually appication icon */
} srv_da_ui_setting_struct;


/*
 * Additional data to be carried to callbacks. If application has something needed
 * to be carried to setting_hdlr or dispatch_hdlr, it can fill this structure
 * to put extra information. Application SHALL make sure that the callbacks are able
 * to recognize the data field.
 * The data field is 4-byte aligned and allowed to put a structure.
 *
 * EXAMPLE
 *
 * Application that invokes download agent:
 * <code>
 * mmi_myapp_info_struct info;
 * info.magic_number = MMI_MYAPP_INFO_MAGIC_NUMBER;
 * info.a = a;
 * info.b = b;
 *
 * srv_da_save_file(
 *     APP_MYAPP,
 *     filepath,
 *     MMI_MYAPP_FIX_FILENAME,
 *     MMI_MYAPP_MIME_TYPE_STRING,
 *     sizeof(info),
 *     &info, // srv_da_save_file will hold a copy of data
 *     ui_setting);
 * </code>
 * In dispatch_hdlr():
 * <code>
 * srv_da_extra_info_struct *extra_info_p;
 * mmi_myapp_info_struct *info_p;
 *
 * extra_info = srv_da_get_extra_info(session_id);
 *
 * if (extra_info_p != NULL && extra_info_p->size == sizeof(mmi_myapp_info_struct))
 * {
 *     info_p = (mmi_myapp_info_struct*)(extra_info_p->data); // To decode data field
 *     if (info_p->magic_number == MMI_MYAPP_INFO_MAGIC_NUMBER)
 *     {
 *          a = info_p->a;
 *          b = info_p->b;
 *     }
 * }
 * </code>
 * SEE ALSO
 *  srv_da_save_file, srv_da_setting_hdlr, srv_da_dispatch_hdlr, srv_da_get_extra_info
 */
typedef struct
{
    kal_uint32 size; /* Size of data */
    kal_uint8  data[SRV_DA_MAX_EXTRA_INFO_DATA_SIZE]; /* 4-byte aligned space */
} srv_da_extra_info_struct;


/*
 * Action command or WAP status notification to download agent.
 */
typedef enum
{
    MMI_DA_WAP_NOTIFY_DISPLAY_LIST,     /* Display download list */
    MMI_DA_WAP_NOTIFY_BROWSER_CLOSED,   /* Notify that browser is closed */
    MMI_DA_WAP_NOTIFY_BROWSER_REOPENED, /*
        Notify that original browser instance has been destroyed and new instance is created */

    MMI_DA_WAP_NOTIFY_NUM
} mmi_da_wap_notify_enum;


/*
 * Local parameter structure of MMI_DA_WAP_NOTIFY_IND.
 * Browser sends this primitive to download agent to inform browser's status or 
 * command download agent.
 */
typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    mmi_da_wap_notify_enum  notify; /* Command or browser's status */
} mmi_da_wap_notify_ind_struct;


/*
 * Local parameter structure of MMI_DA_DOWNLOAD_INFO_IND.
 * Download agent will send this primitive to WAP to inform download status.
 */
typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint32  job_count;          /* Total number of downloads in download list */
    kal_uint32  active_job_count;   /* Total number of downloads in DOWNLOADING in the list */
} mmi_da_download_info_ind_struct;


/* DOM-NOT_FOR_SDK-BEGIN */

typedef struct
{
    kal_uint8           ref_count;
    kal_uint16          msg_len;
    srv_da_action_enum  action;
    kal_int32           mime_type;              /* applib_mime_type_enum */
    kal_int32           mime_subtype;           /* applib_mime_subtype_enum */
    kal_wchar           filepath[SRV_DA_MAX_FILE_PATH_LEN + 1];
    kal_wchar           filename[SRV_DA_MAX_FILE_NAME_LEN + 1];
    kal_char            url[SRV_DA_MAX_DISPATCH_FILE_REQ_URL_LEN + 1];
    kal_char            mime_type_string[SRV_DA_MAX_MIME_TYPE_STRING_LEN + 1];  /* WAP_DL_MAX_MIME_TYPE_LEN */
    srv_da_extra_info_struct extra_info;
    srv_da_ui_setting_struct ui_setting;
} mmi_da_dispatch_file_req_struct;


/******************************************************************
 * OBSOLUTE
 ******************************************************************/

/*
    ex:
    peer_buff_ptr = construct_peer_buff(
        sizeof(mmi_da_dispatch_file_var_struct) + header_len ,
        0 , 0 , TD_RESET);

    peer_buff_ptr->header_len = header_len;
    mempcy( peer_buff_ptr->header, header, len);
 */
typedef struct
{
    kal_uint32          header_len;
    kal_uint8           header[1];              /* Please alloc enough memory to expand the array*/
} mmi_da_dispatch_file_var_struct;


typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    srv_da_error_enum error;
} mmi_da_dispatch_file_rsp_struct;


typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_int32 session_id;
    srv_da_action_enum action_type;
    kal_wchar *tmp_file;                /* UCS2 Max_len: FMGR_MAX_FILE_LEN+FMGR_MAX_PATH_LEN */
    kal_char *mime_type_string;         /* ASCII */
    kal_char *download_url;             /* ASCII */
    kal_int32 mod_id;                   /* module_type */
} mmi_da_get_file_ind_struct;


typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_int32 session_id;
    kal_int32 error_code;
} mmi_da_get_file_res_struct;


typedef enum
{
    MMI_DA_BYPASS_FALSE,
    MMI_DA_BYPASS_LEVEL_1,  /* bypass without confirm screen before dispatch to AP */
    MMI_DA_BYPASS_LEVEL_2,  /* bypass without all prompt */
    MMI_DA_BYPASS_LEVEL_3   /* bypass even when it is a push object */
} mmi_da_bypass_level_enum;

/* DOM-NOT_FOR_SDK-END */



#endif /* DOWNLOAD_AGENT_DEF_H */

