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
 *  DmSrvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 * DM service global prototype header.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __DM_SRV_GPROT_H__
#define __DM_SRV_GPROT_H__

/****************************************************************************
 * Include Files                                                                
 ****************************************************************************/
#include "MMIDataType.h"
#include "Mmi_res_range_def.h"

/****************************************************************************
 * Define
 ****************************************************************************/
/* MAX length of the ID name */
#define DM_MAX_ID_LEN       32

/* MAX length of the ID name (WCHAR) */
#define DM_MAX_NAME_LEN     64

/* MAX URL length */
#define DM_MAX_URL_LEN      128

#define MMI_DMUI_MO_TYPE_STEP 100
/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef enum
{
    EVT_ID_SRV_DM_LAWMO_LOCK_IND = SRV_DM_BASE + 1,
    EVT_ID_SRV_DM_LAWMO_WIPE_IND,
    EVT_ID_SRV_DM_LAWMO_WIPE_EX_IND,
    EVT_ID_SRV_DM_TOTAL
} srv_dm_evt_enum;

/* Lawmo lock command enum */
typedef enum
{
    SRV_DM_LAWMO_LOCK_CMD_NONE,
    SRV_DM_LAWMO_LOCK_CMD_LOCK,     /* Lock command */
    SRV_DM_LAWMO_LOCK_CMD_UNLOCK,   /* Unlock command */
    SRV_DM_LAWMO_LOCK_CMD_END       /* End of enum */
} srv_dm_lawmo_lock_cmd_enum;

/* Lawmo wipe command enum */
typedef enum
{
    SRV_DM_LAWMO_WIPE_CMD_NONE,         /* Idle state */
    SRV_DM_LAWMO_WIPE_CMD_START,        /* Start the wiping operation */
    SRV_DM_LAWMO_WIPE_CMD_FMGR_FORMAT,  /* File manager format command */
    SRV_DM_LAWMO_WIPE_CMD_APP_WIPE,     /* Application wipe data command */
    SRV_DM_LAWMO_WIPE_CMD_FINISH,       /* Finish the wiping operation */
    SRV_DM_LAWMO_WIPE_CMD_END           /* End of enum */
} srv_dm_lawmo_wipe_cmd_enum;

/* Scomo command enum */
typedef enum
{
    SRV_DM_SCOMO_CMD_NONE,              /* None status */
    SRV_DM_SCOMO_CMD_INSTALL,           /* Install command */
    SRV_DM_SCOMO_CMD_INSTALL_INACTIVE,  /* Install and inactive command */
    SRV_DM_SCOMO_CMD_ACTIVATE,          /* Activate command */
    SRV_DM_SCOMO_CMD_INACTIVATE,        /* Inactivate command */
    SRV_DM_SCOMO_CMD_REMOVE,            /* Remove command */
    SRV_DM_SCOMO_CMD_REMOVE_ALL,        /* Remove all applications command */
    SRV_DM_SCOMO_CMD_END                /* End of enum */
} srv_dm_scomo_cmd_enum;

typedef enum
{
    SRV_DM_SCOMO_RESULT_SUCCESS                   = 0,    /* Result success */
    SRV_DM_SCOMO_RESULT_FAILURE                   = -1,   /* Result failure */
    SRV_DM_SCOMO_RESULT_USER_CANCEL               = -2,   /* Result user cancel */
    SRV_DM_SCOMO_RESULT_DOWNLOAD_FAIL             = -3,   /* Result download fail */
    SRV_DM_SCOMO_RESULT_AUTH_FAIL                 = -4,   /* Result authentication fail */
    SRV_DM_SCOMO_RESULT_DOWNLOAD_OUT_MEMORY       = -5,   /* Result download out of memory */
    SRV_DM_SCOMO_RESULT_INSTALL_FAIL              = -6,   /* Result install fail */
    SRV_DM_SCOMO_RESULT_INSTALL_OUT_MEMORY        = -7,   /* Result install out of memory */
    SRV_DM_SCOMO_RESULT_PACKAGE_INVALID           = -8,   /* Result package invalid */
    SRV_DM_SCOMO_RESULT_REMOVE_FAIL               = -9,   /* Result remove fail */
    SRV_DM_SCOMO_RESULT_ACTIVE_FAIL               = -10,  /* Result active fail */
    SRV_DM_SCOMO_RESULT_DEACTIVE_FAIL             = -11,  /* Result deactive fail */
    SRV_DM_SCOMO_RESULT_OPERATION_REJECT          = -12,  /* Result operation reject */
    SRV_DM_SCOMO_RESULT_DOWNLOAD_SERVER_ERROR     = -13,  /* Result server error */
    SRV_DM_SCOMO_RESULT_END                       = -100  /* End of enum */
} srv_dm_scomo_result_enum;

/* Display mode enum */
typedef enum
{
    SRV_DM_SCOMO_DISPLAY_MODE_DEFAULT,      /* Display mode default */
    SRV_DM_SCOMO_DISPLAY_MODE_INFO,         /* Display mode default */
    SRV_DM_SCOMO_DISPLAY_MODE_CONFIRM,      /* Display mode user confirm */
    SRV_DM_SCOMO_DISPLAY_MODE_BACKGROUND,   /* Display mode background */
    SRV_DM_SCOMO_DISPLAY_MODE_TOTAL         /* Total number */
} srv_dm_scomo_display_mode_enum;

/* Fota query result enum */
typedef enum
{
    SRV_DM_FOTA_QUERY_RESULT_OK,            /* Fota query result OK */
    SRV_DM_FOTA_QUERY_RESULT_FAIL,          /* Fota query result fail */
    SRV_DM_FOTA_QUERY_RESULT_NOT_READY,     /* Fota query result not ready */
    SRV_DM_FOTA_QUERY_RESULT_ON_OPERATING,  /* Fota query result still on operating */
    SRV_DM_FOTA_QUERY_RESULT_NO_UPDATE_PKG, /* Fota query result there is no update package */
    SRV_DM_FOTA_QUERY_RESULT_CANCEL,        /* Fota query result cancel */
    SRV_DM_FOTA_QUERY_RESULT_END            /* End of enum */
} srv_dm_fota_query_result_enum;

/* SCOMO information struct for the command from DM to APP */
typedef struct
{
    CHAR dm_software_id[DM_MAX_ID_LEN];               /* DM software ID */
    CHAR app_software_id[DM_MAX_ID_LEN];              /* App software ID */
    WCHAR pkg_install_path[DM_MAX_URL_LEN];         /* Install file path */
    CHAR pkg_network_url[DM_MAX_URL_LEN];             /* network package url */
    srv_dm_scomo_display_mode_enum display_mode;    /* Display mode */
} srv_dm_scomo_java_cmd_info_struct;

/* SCOMO information struct for the command from APP to DM */
typedef struct
{
    CHAR dm_software_id[DM_MAX_ID_LEN];           /* DM software ID */
    CHAR app_software_id[DM_MAX_ID_LEN];          /* App software ID */
    WCHAR software_name[DM_MAX_NAME_LEN];         /* software name */
    CHAR software_version[DM_MAX_NAME_LEN];       /* software version */
} srv_dm_scomo_java_report_info_struct;

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  srv_dm_fota_query_cb_func_type
 * DESCRIPTION
 *  DM Fota query callback function
 * PARAMETERS
 *  result:     [IN] Fota query result
 *  debug_info: [IN] App user data
 * RETURN VALUES
 *  void
 *****************************************************************************/
typedef void(*srv_dm_fota_query_cb_func_type)(srv_dm_fota_query_result_enum result, void *user_data);

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  srv_dm_lawmo_lock_report_cb_func_type
 * DESCRIPTION
 *  lawmo lock callback function
 * PARAMETERS
 *  result:     [IN] Lawmo lock operation result
 *  debug_info: [IN] Lawmo lock app debug information
 * RETURN VALUES
 *  void
 *****************************************************************************/
typedef void(*srv_dm_lawmo_lock_report_cb_func_type)(MMI_BOOL result, CHAR *debug_info);

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  srv_dm_lawmo_wipe_report_cb_func_type
 * DESCRIPTION
 *  lawmo wipe callback function
 * PARAMETERS
 *  result:     [IN] Lawmo wipe operation result
 *  debug_info: [IN] Lawmo wipe app debug information
 * RETURN VALUES
 *  void
 *****************************************************************************/
typedef void(*srv_dm_lawmo_wipe_report_cb_func_type)(MMI_BOOL result, CHAR *debug_info);

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  srv_dm_scomo_report_cb
 * DESCRIPTION
 *  function of scomo callback
 * PARAMETERS
 *  report_info:     [IN] SCOMO application report information
 * RETURN VALUES
 *  void
 *****************************************************************************/
typedef void(*srv_dm_scomo_report_cb)(srv_dm_scomo_java_report_info_struct *report_info);

typedef void(*srv_dm_scomo_cmd_notify_cb)(srv_dm_scomo_cmd_enum cmd, srv_dm_scomo_java_cmd_info_struct *cmd_info);

/* event structure for EVT_ID_SRV_DM_LAWMO_LOCK_IND */
typedef struct {
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER                        /* MMI_EVENT_COMMON_HEADER */
    /* DOM-NOT_FOR_SDK-END */
    srv_dm_lawmo_lock_cmd_enum cmd;             /* Lock command enum */
    srv_dm_lawmo_lock_report_cb_func_type cb;   /* Lock report callback function */
} srv_dm_lawmo_lock_ind_evt_struct;

/* event structure for EVT_ID_SRV_DM_LAWMO_WIPE_IND */
typedef struct {
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER                        /* MMI_EVENT_COMMON_HEADER */
    /* DOM-NOT_FOR_SDK-END */
    srv_dm_lawmo_wipe_cmd_enum cmd;             /* Wipe command enum */
    srv_dm_lawmo_wipe_report_cb_func_type cb;   /* Wipe report callback function */
} srv_dm_lawmo_wipe_ind_evt_struct;

/* event structure for EVT_ID_SRV_DM_SCOMO_IND */
typedef struct {
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER                        /* MMI_EVENT_COMMON_HEADER */
    /* DOM-NOT_FOR_SDK-END */
    srv_dm_scomo_cmd_enum cmd;                  /* Scomo command */
    srv_dm_scomo_report_cb cb;                  /* Scomo report callback function */
    srv_dm_scomo_java_cmd_info_struct *cmd_info;/* Java info */
} srv_dm_scomo_ind_evt_struct;


/* DM service send command to other task. */
typedef struct 
{
    kal_uint8 ref_count;  /* reference count */
    kal_uint16 msg_len;   /* message length  */
    srv_dm_lawmo_lock_cmd_enum command;    /* lawmo command     */
} srv_dm_lawmo_cmd_ind_struct;

/****************************************************************************
 * Global variable
 ****************************************************************************/

/****************************************************************************
 * Global Function
 ****************************************************************************/

extern srv_dm_scomo_result_enum srv_dm_scomo_register_notify(srv_dm_scomo_cmd_notify_cb scomo_callback);

/*****************************************************************************
 * FUNCTION
 *  srv_dm_lawmo_is_locked
 * DESCRIPTION
 *  function to check is the phone locked
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE:   phone locked
 *  FALSE:  phone unlocked
 *****************************************************************************/
extern MMI_BOOL srv_dm_lawmo_is_locked(void);

/*****************************************************************************
 * FUNCTION
 *  srv_dm_lawmo_is_wiping
 * DESCRIPTION
 *  function to check is wiping data
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE:   data wiping
 *  FALSE:  not doing data wiping
 *****************************************************************************/
extern MMI_BOOL srv_dm_lawmo_is_wiping(void);

/*****************************************************************************
 * FUNCTION
 *  srv_dm_fota_query_update
 * DESCRIPTION
 *  function to check is wiping data
 * PARAMETERS
 *  cb        : [IN] fota query callback function
 *  user_data : [IN] application user data
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_dm_fota_query_update(srv_dm_fota_query_cb_func_type cb, void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_dm_fota_query_cancel
 * DESCRIPTION
 *  function to let application cancel fota query operation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_dm_fota_query_cancel(void);


/*below code used to compile with app that not update code*/
//#if 0

typedef enum
{
    MMI_DMUI_MO_TYPE_LAWMO_LOCK,    /* Type of LAWMO lock */
    MMI_DMUI_MO_TYPE_LAWMO_WIPE,    /* Type of LAWMO wipe */
    MMI_DMUI_MO_TYPE_SCOMO,         /* Type of SCOMO */
    MMI_DMUI_MO_TYPE_TOTAL          /* Type end */
} mmi_dmui_mo_type_enum;

/* Application ID enum */
typedef enum
{
    MMI_DMUI_APP_ID_IDLE,               /* APP idle */
    MMI_DMUI_APP_ID_FMGR,               /* APP file manager */
    MMI_DMUI_APP_ID_JAVA,               /* APP Java */
    MMI_DMUI_APP_ID_BLUETOOTH,          /* APP bluetooth */
    MMI_DMUI_APP_ID_UCM,                /* APP UCM */
    MMI_DMUI_APP_ID_USB,                /* APP USB */
    MMI_DMUI_APP_ID_CBM,                /* APP CBM */
    MMI_DMUI_APP_ID_MEDPLY,             /* APP MediaPlayer */
    MMI_DMUI_APP_ID_AUDPLY,             /* APP AudioPlayer */
    MMI_DMUI_APP_ID_MOBILETVPLAYER,     /* APP Mobile TV Player */
    MMI_DMUI_APP_ID_FMRDO,              /* APP FM Radio */
    MMI_DMUI_APP_ID_ATCI,               /* APP ATCI */
    MMI_DMUI_APP_ID_PROVBOX,            /* APP Provisioning Inbox */
    MMI_DMUI_APP_ID_CALL_LOG,           /* APP call log */
    MMI_DMUI_APP_ID_PHONEBOOK,          /* APP phonebook */
    MMI_DMUI_APP_ID_MMS,                /* APP MMS */
    MMI_DMUI_APP_ID_SMS,                /* APP SMS */
    MMI_DMUI_APP_ID_PUSH,               /* APP PUSH */
    MMI_DMUI_APP_ID_PICT,               /* APP Pictbridge */
    MMI_DMUI_APP_ID_SYNCML,             /* APP Syncml */
    MMI_DMUI_APP_ID_CCA,                /* APP CCA*/
    MMI_DMUI_APP_ID_PHNSET,             /* APP PHONESET */
    MMI_DMUI_APP_ID_TOTAL               /* Total APP number */
} mmi_dmui_app_id_enum;


/* MO command enum */
typedef enum
{
    MMI_DMUI_CMD_LAWMO_FULLYLOCK            = MMI_DMUI_MO_TYPE_LAWMO_LOCK * MMI_DMUI_MO_TYPE_STEP,  /* Command of fully lock */
    MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK,                                                               /* Command of partially lock */
    MMI_DMUI_CMD_LAWMO_UNLOCK,                                                                      /* Command of unlock */
    MMI_DMUI_CMD_LAWMO_FACTORYRESET         = MMI_DMUI_MO_TYPE_LAWMO_WIPE * MMI_DMUI_MO_TYPE_STEP,  /* Command of factory reset */
    MMI_DMUI_CMD_LAWMO_WIPE,                                                                        /* Command of wipe */
    MMI_DMUI_CMD_SCOMO_INSTALL              = MMI_DMUI_MO_TYPE_SCOMO * MMI_DMUI_MO_TYPE_STEP,       /* Command of install */
    MMI_DMUI_CMD_SCOMO_INSTALL_INACTIVE,                                                            /* Command of install inactive */
    MMI_DMUI_CMD_SCOMO_ACTIVATE,                                                                    /* Command of activate */
    MMI_DMUI_CMD_SCOMO_INACTIVATE,                                                                  /* Command of inactivate */
    MMI_DMUI_CMD_SCOMO_REMOVE,                                                                      /* Command of remove */
    MMI_DMUI_CMD_SCOMO_REMOVE_ALL,                                                                  /* Command of remove all software */
    MMI_DMUI_CMD_END                                                                                /* Command end */
} mmi_dmui_cmd_enum;

typedef enum
{
    MMI_DMUI_STATUS_IDLE,                       /* Status idle */
    MMI_DMUI_STATUS_LAWMO_LOCK_ON_LOCKING,      /* Status LAWMO on locking */
    MMI_DMUI_STATUS_LAWMO_LOCK_FULLYLOCK,       /* Status LAWMO lock fully lock */
    MMI_DMUI_STATUS_LAWMO_LOCK_PARTIALLYLOCK,   /* Status LAWMO lock partially lock */
    MMI_DMUI_STATUS_LAWMO_WIPE_FACTORYRESET,    /* Status LAWMO wipe factory reset */
    MMI_DMUI_STATUS_LAWMO_WIPE_WIPE,            /* Status LAWMO wipe wipe */
    MMI_DMUI_STATUS_SCOMO_INSTALL,              /* Status SCOMO install */
    MMI_DMUI_STATUS_SCOMO_INSTALL_INACTIVE,     /* Status SCOMO install inactive */
    MMI_DMUI_STATUS_SCOMO_ACTIVATE,             /* Status SCOMO activate */
    MMI_DMUI_STATUS_SCOMO_INACTIVATE,           /* Status SCOMO inactivate */
    MMI_DMUI_STATUS_SCOMO_REMOVE,               /* Status SCOMO remove */
    MMI_DMUI_STATUS_SCOMO_REMOVE_ALL,           /* Status SCOMO remove all software */
    MMI_DMUI_STATUS_END                         /* Status END */
} mmi_dmui_status_enum;

/* Report result enum */
typedef enum
{
    MMI_DMUI_RESULT_SUCCESS                         = 0,    /* Result success */
    MMI_DMUI_RESULT_FAILURE                         = -1,   /* Result failure */             
    MMI_DMUI_RESULT_SCOMO_USER_CANCEL               = -2,   /* Result SCOMO user cancel */
    MMI_DMUI_RESULT_SCOMO_DOWNLOAD_FAIL             = -3,   /* Result SCOMO download fail */
    MMI_DMUI_RESULT_SCOMO_AUTH_FAIL                 = -4,   /* Result SCOMO authentication fail */
    MMI_DMUI_RESULT_SCOMO_DOWNLOAD_OUT_MEMORY       = -5,   /* Result SCOMO download out of memory */
    MMI_DMUI_RESULT_SCOMO_INSTALL_FAIL              = -6,   /* Result SCOMO install fail */
    MMI_DMUI_RESULT_SCOMO_INSTALL_OUT_MEMORY        = -7,   /* Result SCOMO install out of memory */
    MMI_DMUI_RESULT_SCOMO_PACKAGE_INVALID           = -8,   /* Result SCOMO package invalid */
    MMI_DMUI_RESULT_SCOMO_REMOVE_FAIL               = -9,   /* Result SCOMO remove fail */
    MMI_DMUI_RESULT_SCOMO_ACTIVE_FAIL               = -10,  /* Result SCOMO active fail */
    MMI_DMUI_RESULT_SCOMO_DEACTIVE_FAIL             = -11,  /* Result SCOMO deactive fail */
    MMI_DMUI_RESULT_SCOMO_OPERATION_REJECT          = -12,  /* Result SCOMO operation reject */
    MMI_DMUI_RESULT_SCOMO_DOWNLOAD_SERVER_ERROR     = -13,  /* Result SCOMO server error */
    MMI_DMUI_RESULT_END                             = -100  /* End of Result code */
} mmi_dmui_result_enum;

/* Display mode enum */
typedef enum
{
    MMI_DMUI_APP_DISPLAY_MODE_DEFAULT,      /* Display mode default */
    MMI_DMUI_APP_DISPLAY_MODE_CONFIRM,      /* Display mode user confirm */
    MMI_DMUI_APP_DISPLAY_MODE_BACKGROUND,   /* Display mode background */
    MMI_DMUI_APP_DISPLAY_MODE_TOTAL         /* Total number */
} mmi_dmui_app_display_mode_enum;

/* SCOMO information struct for the command from DM to APP */
typedef struct
{
    CHAR dm_software_id[DM_MAX_ID_LEN];                 /* DM software ID */
    CHAR app_software_id[DM_MAX_ID_LEN];                /* App software ID */
    U16 pkg_install_path[DM_MAX_URL_LEN];               /* Install file path */
    CHAR pkg_network_url[DM_MAX_URL_LEN];               /* network package url */
    mmi_dmui_app_display_mode_enum display_mode;        /* Display mode */
} mmi_dmui_scomo_dm_cmd_info_struct;

/* SCOMO information struct for the command from DM to APP */
typedef struct
{
    CHAR dm_software_id[DM_MAX_ID_LEN];                 /* DM software ID */
    CHAR app_software_id[DM_MAX_ID_LEN];                /* App software ID */
    U16 pkg_install_path[DM_MAX_URL_LEN];               /* Install file path */
    CHAR pkg_network_url[DM_MAX_URL_LEN];               /* network package url */
    mmi_dmui_app_display_mode_enum display_mode;        /* Display mode */
} srv_dm_scomo_dm_cmd_info_struct;
/* SCOMO information struct for the command from APP to DM */
typedef struct
{
    CHAR dm_software_id[DM_MAX_ID_LEN];                 /* DM software ID */
    CHAR app_software_id[DM_MAX_ID_LEN];                /* App software ID */
    U16 software_name[DM_MAX_NAME_LEN];                 /* software name */
    CHAR software_version[DM_MAX_NAME_LEN];             /* software version */
} mmi_dmui_scomo_app_report_info_struct;

/* Save the user operation info into file */
typedef struct
{                
    mmi_dmui_app_id_enum app_id;
    mmi_dmui_cmd_enum cmd;
    mmi_dmui_scomo_app_report_info_struct app_cmd_info;
} mmi_dmui_scomo_app_report_save_file_info_struct;
typedef void(*mmi_dmui_lawmo_cb)(
                mmi_dmui_app_id_enum app_id,
                mmi_dmui_cmd_enum cmd);

extern mmi_dmui_result_enum mmi_dmui_lawmo_register_notify(
                        mmi_dmui_app_id_enum app_id,
                        mmi_dmui_mo_type_enum mo_type,
                        mmi_dmui_lawmo_cb lawmo_callback);

extern void mmi_dmui_lawmo_report(
        mmi_dmui_app_id_enum app_id,
        mmi_dmui_cmd_enum cmd,
        mmi_dmui_result_enum result);

extern kal_int8 mmi_dmui_is_phone_lock(void);
extern mmi_dmui_status_enum mmi_dmui_get_status(mmi_dmui_mo_type_enum mo_type);
    /*****************************************************************************
     * <GROUP CallBackFunctions>
     *
     * FUNCTION
     *  mmi_dmui_scomo_cb
     * DESCRIPTION
     *  function of scomo callback
     * PARAMETERS
     *  app_id:         [IN] Application ID
     *  cmd:            [IN] Command
     *  scomo_info:     [IN] SCOMO information
     * RETURN VALUES
     *  void
     *****************************************************************************/
    typedef void(*mmi_dmui_scomo_cb)(
                    mmi_dmui_app_id_enum app_id,
                    mmi_dmui_cmd_enum cmd,
                    mmi_dmui_scomo_dm_cmd_info_struct *scomo_info);
    
    /*****************************************************************************
     * FUNCTION
     *  mmi_dmui_scomo_register_notify
     * DESCRIPTION
     *  app can register the callback function to handle the DM scomo command
     * PARAMETERS
     *  app_id:         [IN] Application ID        
     *  cmd:            [IN] Command
     *  scomo_callback: [IN] Application SCOMO callback function
     * RETURNS
     *  mmi_dmui_result_enum
     *****************************************************************************/
    extern mmi_dmui_result_enum mmi_dmui_scomo_register_notify(
                                    mmi_dmui_app_id_enum app_id,
                                    mmi_dmui_mo_type_enum mo_type,
                                    mmi_dmui_scomo_cb scomo_callback);
    
    
    /*****************************************************************************
     * FUNCTION
     *  mmi_dmui_scomo_report
     * DESCRIPTION
     *  app use this function to report the scomo operation result
     * PARAMETERS
     *  app_id:     [IN] Application ID
     *  cmd:        [IN] Command
     *  result:     [IN] Application SCOMO operation result
     *  scomo_info: [IN] SCOMO information
     * RETURNS
     *  void
     *****************************************************************************/
    extern void mmi_dmui_scomo_report(
                    mmi_dmui_app_id_enum app_id,
                    mmi_dmui_cmd_enum cmd,
                    mmi_dmui_result_enum result,
                    mmi_dmui_scomo_app_report_info_struct *scomo_info);

//#endif
#endif /* __DM_SRV_GPROT_H__ */
