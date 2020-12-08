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

/****************************************************************************
 * Include
 ****************************************************************************/

#ifndef DOWNLOAD_AGENT_GPROT_H
#define DOWNLOAD_AGENT_GPROT_H

//#ifdef __COSMOS_MMI_PACKAGE__
#ifndef _FILE_MGR_H_
//#include "FileMgr.h"
#endif

#ifndef DOWNLOAD_AGENT_DEF_H
#include "DLAgentSrvDef.h"
#endif

#ifndef __APP_MINE_H__
#include "app_mine.h"
#endif


    #include "FileMgrGProt.h"
    #include "MMIDataType.h"
    #include "kal_general_types.h"
    #include "MMI_features.h"

/****************************************************************************
 * Typedef
 ****************************************************************************/

#ifdef __CBM_BEARER_SWITCH__
#define MMI_DA_WLAN_PREFER_SUPPORT
#endif

#if defined(__HTTP_INTERFACE__) && defined(__MMI_DA_WPS_UTIL__)
//#define MMI_DA_HTTP_DOWNLOAD_SUPPORT
#endif


typedef enum
{
    SRV_DA_SWITCH_BEARER_WLAN = 0,
    SRV_DA_SWITCH_BEARER_CELLULAR,

    SRV_DA_SWITCH_BEARER_TOTAL
} srv_da_switch_current_bearer_enum;

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  srv_da_filepath_hdlr
 * DESCRIPTION
 *  Once filepath is decided for a download, download agent will call back
 *  this function to notify a download will start. The filepath will be also
 *  passed for progressive download.
 * PARAMETERS
 *  session_id     : [IN] Session ID
 *  mime_type      : [IN] applib_mime_type_enum
 *  mime_subtype   : [IN] applib_mime_subtype_enum
 *  filepath       : [IN] Filepath the download will be saved to
 * RETURNS
 *  Unused currently.
 *****************************************************************************/
typedef BOOL (*srv_da_filepath_hdlr)(
	S32 session_id,
	S32 mime_type,
	S32 mime_subtype,
	U16	*filepath);

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  srv_da_report_hdlr
 * DESCRIPTION
 *  AFTER server response is received, download agent will call back this function
 *  periodically to inform download progress.
 * PARAMETERS
 *  session_id      : [IN] Session ID
 *  status          : [IN] srv_da_state_enum; Download state
 *  cause           : [IN] srv_da_error_enum; Error code if download aborted.
 *                         If no error, this field is not defined.
 *  seq_num         : [IN] Sequential number of reporting. This number will plus
 *                         1 on one report.
 *  acc_size        : [IN] Size of the content already received.
 *  total_size      : [IN] Total size of content. But MAY BE NOT AVAILABLE if the response
 *                         did not describe. In such session, we can only know whether
 *                         the download has completed or not. If not available, this
 *                         value will be always 0.
 * RETURNS
 *  Unused currently.
 *****************************************************************************/
typedef void (*srv_da_report_hdlr)(
	S32	session_id,
	S32	status,
	S32	cause,
	U32	seq_num,
	U32	acc_size,
	U32 total_size);

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  srv_da_dispatch_hdlr
 * DESCRIPTION
 *  Download agent will call this function after file is received and do_dispatch == MMI_TRUE.
 * PARAMETERS
 *  session_id          : [IN] Session ID
 *  mime_type           : [IN] applib_mime_type_enum
 *  mime_subtype        : [IN] applib_mime_subtype_enum
 *  action              : [IN] srv_da_action_enum; file source
 *  filepath            : [IN] Filepath the download will be saved to
 *  url                 : [IN] File original URI
 *  mime_type_string    : [IN] MIME type string extracted from header
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_da_dispatch_hdlr)(
	S32 session_id,
	S32 mime_type,
	S32 mime_subtype,
	S32 action,
	U16 *filepath,
	S8  *url,
	S8  *mime_type_string
);


/* DOM-NOT_FOR_SDK-BEGIN */
typedef BOOL (*srv_da_hook_dispatch_hdlr)(
	S32	session_id,
	S32	mime_type,
	S32	mime_subtype,
	S32 action,
	PU16 filepath,
	PS8	url,
	PS8	mime_type_string
);
/* DOM-NOT_FOR_SDK-END */


/*
 * This structure describes the information to help presetting_hdlr() determine presetting.
 * SEE ALSO
 *  srv_da_presetting_hdlr
 */
typedef struct srv_da_presetting_param_struct_s
{
    srv_da_action_enum action;                  /* Source of the file. E.g. Via MMS or HTTP download */
    const applib_mime_type_struct *mime_type;   /* File MIME type */
    S8  *uri;                                   /* Source URI of the file */
} srv_da_presetting_param_struct;


/*
 * Application is allowed to control parameters before receiving a file. This structure
 * can be used to skip the confirm screen and tells download agent if it needs content
 * to help to determine setting.
 * Before content downloading, DLAgent will query the application that if partial content
 * is needed to determine setting. If no, DLAgent will pass NULL to the content parameter
 * to setting_hdlr(). Otherwise if yes, DLAgent will download partial content first, and
 * pass the partial content to setting handler. Presetting can also control whether the
 * download confirm screen should be shown.
 * Before fill application-specific configuration, ALWAYS use srv_da_default_presetting()
 * to initialize all fields first. For example,
 *  <code>
 *  void mmi_myapp_presetting_hdlr(
 *      const srv_da_presetting_param_struct *param,
 *      srv_da_presetting_struct *presetting)
 *  {
 *      <b>srv_da_default_presetting(param, presetting);</b>
 *      presetting->confirm_download = MMI_FALSE; // Overwrite the field required
 *  }
 *  </code>
 * SEE ALSO
 *  srv_da_default_presetting, srv_da_need_content_presetting
 */
typedef struct srv_da_presetting_struct_s
{
    MMI_BOOL    confirm_download; /*
        If MMI_TRUE, DLAgent will confirm with user before download.
        Otherwise, the confirm step will be skipped and download directly. */

    MMI_BOOL    need_content; /*
        MMI_TRUE indicates application needs content to determine setting.
        If MMI_FALSE, the content passed to the setting_hdlr() may be NULL.
        However, even if this field is set to be TRUE, the content may be
        not available and content may still be NULL. */
} srv_da_presetting_struct;


/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  srv_da_presetting_hdlr
 * DESCRIPTION
 *  Before calling setting_hdlr(), download agent may hope to get preliminary
 *  parameters to control the flow before really get the setting.
 *  This handler can help to provide preliminary parameters and describes
 *  which information is necessary to determine the real setting.
 *  Before fill application-specific configuration, ALWAYS use srv_da_default_presetting()
 *  to initialize all fields first. For example,
 *  <code>
 *  void mmi_myapp_presetting_hdlr(
 *      const srv_da_presetting_param_struct *param,
 *      srv_da_presetting_struct *presetting)
 *  {
 *      <b>srv_da_default_presetting(param, presetting);</b>
 *      presetting->confirm_download = MMI_FALSE; // Overwrite the field required
 *  }
 *  </code>
 * PARAMETERS
 *  param       : [IN]  Information to help to determine presetting
 *  presetting  : [OUT] Presetting, see the description of this structure.
 * RETURNS
 *  void
 * SEE ALSO
 *  srv_da_setting_hdlr, srv_da_default_presetting
 *****************************************************************************/
typedef void (*srv_da_presetting_hdlr)(
    const srv_da_presetting_param_struct *param,
    srv_da_presetting_struct *presetting);


/*
 * This structure is used to set parameters of receipt of particular MIME type.
 * Application's setting_hdlr() will fill this structure to control UI flows;
 * for example, whether to show select-storage interface to user, whether to
 * show confirm screen before dispatching. It can also assign the folder where
 * the file is saved to, or assign a default filename pattern. For progressive download
 * or application wants to know the download progress, it can also assign callback
 * function to listen to the progress by this structure.
 * Before fill application-specific configuration, ALWAYS use one of srv_da_default_presetting(),
 * srv_da_bypass_setting() or srv_da_push_setting() to initialize all fields first.
 * For example,
 *  <code>
 *  void mmi_myapp_setting_hdlr(..., srv_da_setting_struct *setting)
 *  {
 *      if (xxxx)
 *      {
 *          <b>srv_da_default_presetting(..., setting);</b>
 *          setting->xxx = xxx; // Overwrite the field required
 *          // ...
 *      }
 *      else
 *      {
 *          <b>srv_da_bypass_setting(..., setting);</b>
 *          setting->xxx = xxx; // Overwrite the field required
 *          // ...
 *      }
 *  }
 *  </code>
 */
typedef struct srv_da_setting_struct_s
{
    srv_da_storage_enum  storage; /*
        Policy to decide the storage for the file.
        If storage is not USER_SELECT nor AUTO, necessary to fill following drv also. */

    S32     drv; /*
        Which drive the file should be saved in.
        If storage == AUTO, DLAgent will decide the drive, not need to fill this field. */

    U16     folder[SRV_DA_MAX_FILE_NAME_LEN + 2]; /*
        The folder name to save the file. I.e., the file will be saved in {drv}:\{folder}\
        NOTE: The folder name MUST contain tail '\' */

    MMI_BOOL    default_filename; /*
        Two following variables will decide how to decide the filename.
        1. default_filename == MMI_TRUE
           => Let DLAgent to decide the filename
        2. default_filename == MMI_FALSE && LEN(filename) > 0
           => Always use {filename}
        3. default_filename == MMI_FALSE && LEN(filename) == 0
           => Let user to input filename
        */
    
    U16         filename[SRV_DA_MAX_FILE_NAME_LEN + 1]; /*
        Default filename pattern if default_filename == MMI_FALSE. However, the final filename
        may be not the same to this field. User may change the filename; or if there is already
        a file on the filepath assigned, the filename will be concatenated by "(1)", "(2)", etc. */

    MMI_BOOL    do_dispatch; /*
        If MMI_TRUE, DLAgent will invoke its dispatch_hdlr() after received the file */

    MMI_BOOL    confirm_dispatch; /*
        Before dispatching, confirm with user first. I.e. popup "Use file?" */

    MMI_BOOL    confirm_push; /*
        If MMI_TRUE, DLAgent will prompt user that the file is received.
        Otherwise, it will be slient when receive the file. If the push is received not on Idle screen
        the push will queued first and shown when entering Idle. */

    MMI_BOOL    can_minimize; /*
        If MMI_TRUE, background download is allowed. Otherwise, an progress screen dedicated for the
        file will be displayed but not the download list. User can know the progress of the download
        on the screen. He/she can only either wait for download completion or cancel the downloading.
        No other operation is allowed.
        Name it "can_background_download." may be better. */

    srv_da_filepath_hdlr    filepath_hdlr; /*
        Once the filepath is known, this function will be called.
        Note that the file has NOT started to download yet, this callback handler is only
        provided for applications to do initializations before file downloading.
        Applications usually use this mechanism by cooperating with report_hdlr().  */

    srv_da_report_hdlr      report_hdlr; /*
        To report download progress.
        This is used to implement progressive download. */


    MMI_BOOL    percentage_bar;         /* OBSOLETE; Not need to fill this field. */
    MMI_BOOL    keepfile;               /* OBSOLETE; Not need to fill this field. */
    mmi_da_bypass_level_enum bypass;    /* OBSOLETE; Not need to fill this field. */
} srv_da_setting_struct;


/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  srv_da_setting_hdlr
 * DESCRIPTION
 *  Get appropriate setting by given information.
 *  Before fill application-specific configuration, ALWAYS use one of srv_da_default_presetting(),
 *  srv_da_bypass_setting() or srv_da_push_setting() to initialize all fields first.
 *  For example,
 *  <code>
 *  void mmi_myapp_setting_hdlr(..., srv_da_setting_struct *setting)
 *  {
 *      if (xxxx)
 *      {
 *          <b>srv_da_default_presetting(..., setting);</b>
 *          setting->xxx = xxx; // Overwrite the field required
 *          // ...
 *      }
 *      else
 *      {
 *          <b>srv_da_bypass_setting(..., setting);</b>
 *          setting->xxx = xxx; // Overwrite the field required
 *          // ...
 *      }
 *  }
 *  </code>
 * PARAMETERS
 *  session_id          : [IN]    Session ID
 *  mime_type           : [IN]    applib_mime_type_enum
 *  mime_subtype        : [IN]    applib_mime_subtype_enum
 *  action              : [IN]    srv_da_action_enum; file source
 *  filesize            : [IN]    File size
 *  url                 : [IN]    URL in ASCII encoding; may be NULL if not available
 *  mime_type_string    : [IN]    MIME type string in ASCII encoding
 *  content_len         : [IN]    Length of partial content
 *  content             : [IN]    Partial content in HTTP response, may be NULL.
 *                                If application needs partial content to determine setting,
 *                                presetting->need_content should be MMI_TRUE. However,
 *                                this field may still be NULL if not available at present.
 *  setting             : [OUT]   Appropriate behavior setting by previous information.
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_da_setting_hdlr)(
    S32 session_id,
    S32 mime_type,
    S32 mime_subtype,
    S32 action,
    U32 filesize,
    S8  *url,
    S8  *mime_type_string,
    U32 content_len,
    S8  *content,
    srv_da_setting_struct *setting 
);


/*
 * Structure for OMA download descriptor
 */
typedef struct
{
    S8 *type[4];            /* Type tag. Empty element is represented by NULL. */
    S8 *objectURI;          /* objectURI, may be NULL. */
    S8 *installNotifyURI;   /* installNotifyURI, may be NULL. */
    S8 *nextURL;            /* nextURL, may be NULL. */
    S8 *DDVersion;          /* DD version, may be NULL. */
    S8 *name;               /* name, may be NULL. */
    S8 *description;        /* description, may be NULL. */
    S8 *vendor;             /* vendor, may be NULL. */
    S8 *infoURL;            /* infoURL, may be NULL. */
    S8 *iconURI;            /* iconURI, may be NULL. */
    S8 *installParam;       /* installParam, may be NULL. */
    U32 size;               /* size, 0 if not available */
    MMI_BOOL progressiveDownloadFlag; /* progressiveDownloadFlag, default is MMI_FALSE */

    U8  attr_order[20];     /* srv_da_oma_dd_elem_enum, the order of tag appears in the DD */
    U8  attr_num;           /* Number of atributes(tags) in the DD */

} srv_da_oma_dd_struct;


/****************************************************************************
 * Exported Functions & APIs
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_da_default_presetting
 * DESCRIPTION
 *  Set the presetting to default values. It sets
 *  1. Show confirm screen before download.
 *     I.e. confirm_download = MMI_TRUE;
 *  2. Not need content to determine setting.
 *     I.e. need_content = MMI_FALSE;
 * PARAMETERS
 *  param       : [IN]  Parameters to determine pre-setting
 *  presetting  : [OUT] Pre-setting
 * RETURNS
 *  void
 * SEE ALSO
 *  srv_da_setting_hdlr
 *****************************************************************************/
extern void srv_da_default_presetting(
    const srv_da_presetting_param_struct *param,
    srv_da_presetting_struct *presetting);

/*****************************************************************************
 * FUNCTION
 *  srv_da_need_content_presetting
 * DESCRIPTION
 *  Set the presetting to default values. It sets
 *  1. Show confirm screen before download.
 *     I.e. confirm_download = MMI_TRUE;
 *  2. Pass partial content to setting_hdlr.
 *     I.e. need_content = MMI_TRUE;
 * PARAMETERS
 *  param       : [IN]  Parameters to determine pre-setting
 *  presetting  : [OUT] Pre-setting
 * RETURNS
 *  void
 * SEE ALSO
 *  srv_da_setting_hdlr
 *****************************************************************************/
extern void srv_da_need_content_presetting(
    const srv_da_presetting_param_struct *param,
    srv_da_presetting_struct *presetting);

/*****************************************************************************
 * FUNCTION
 *  srv_da_default_setting
 * DESCRIPTION
 *  Default setting function for convenience. It applies default behavior of
 *  normal file receiving. The configurations are listed as below:
 *    1. Let user to decide the storage
 *    2. Let user to input the filename
 *    3. Default folder, assign folder according to the major MIME type.
 *       For example, audio/ * will be put in Audio folder, image/ * will be
 *       put in Picture folder.
 *    4. Confirm with user before dispatch
 *    5. Popup when received via push, queue the push if current screen if not Idle;
 *       I.e., setting->confirm_push = MMI_TRUE;
 *    6. Background download is allowed and download list will be shown
 *       I.e., setting->can_minimize = MMI_TRUE;
 *    7. Dispatch after file received.
 *    8. Both filepath_hdlr() and report_hdlr() are filled as NULL.
 * PARAMETERS
 *  session_id          : [IN]    Session ID
 *  mime_type           : [IN]    applib_mime_type_enum
 *  mime_subtype        : [IN]    applib_mime_subtype_enum
 *  action              : [IN]    srv_da_action_enum
 *  filesize            : [IN]    File size
 *  url                 : [IN]    URL in ASCII encoding
 *  mime_type_string    : [IN]    MIME type string in ASCII encoding
 *  content_len         : [IN]    Content-Length in HTTP header
 *  content             : [IN]    Content in HTTP response
 *  setting             : [OUT]   Appropriate behavior setting by previous information.
 * RETURNS
 *  void
 * SEE ALSO
 *  srv_da_setting_hdlr
 *****************************************************************************/
extern void srv_da_default_setting(
    S32 session_id,
    S32 mime_type,
    S32 mime_subtype,
    S32 action,
	U32 filesize,
	S8 *url,
	S8 *mime_type_string,
	U32 content_len,
	S8 *content,
	srv_da_setting_struct *setting);

/*****************************************************************************
 * FUNCTION
 *  srv_da_bypass_setting
 * DESCRIPTION
 *  Default setting function for convenience. This setting skips all interaction
 *  screens except the confirm screen before downloading and start to download directly.
 *  If application hopes to skip the confirm screen, please use presetting,
 *  see srv_da_presetting_hdlr. After download completed, download agent dispatches to
 *  application immediately.
 *  The configurations are listed as below:
 *    1. Auto select a storage, may be phone or memory card
 *    2. Assign a temporary filename
 *    3. Put the file in a temp folder, all files in the temp folder will be
 *       cleaned after reboot. If application does not need the file no longer after dispatch,
 *       make sure to delete the file by application itself to avoid waste of space.
 *       If application hopes the file can be kept, please overwrite folder field to
 *       assign another folder.
 *    4. Dispatch directly without the confirmation with user
 *    5. Popup when received via push, queue the push if current screen if not Idle;
 *       I.e., setting->confirm_push = MMI_TRUE;
 *    6. Background download is not allowed.
 *       I.e., setting->can_minimize = MMI_FALSE;
 *    7. Dispatch after file received.
 *    8. Both filepath_hdlr() and report_hdlr() are filled as NULL.
 *  If file is received from application's save-object(e.g. MMS save-object) operation,
 *  this setting will not dispatch and only save the file.
 * PARAMETERS
 *  session_id          : [IN]    Session ID
 *  mime_type           : [IN]    applib_mime_type_enum
 *  mime_subtype        : [IN]    applib_mime_subtype_enum
 *  action              : [IN]    srv_da_action_enum
 *  filesize            : [IN]    File size
 *  url                 : [IN]    URL in ASCII encoding
 *  mime_type_string    : [IN]    MIME type string in ASCII encoding
 *  content_len         : [IN]    Content-Length in HTTP header
 *  content             : [IN]    Content in HTTP response
 *  setting             : [OUT]   Appropriate behavior setting by previous information.
 * RETURNS
 *  void
 * SEE ALSO
 *  srv_da_setting_hdlr, srv_da_presetting_hdlr
 *****************************************************************************/
extern void srv_da_bypass_setting(
    S32 session_id,
    S32 mime_type,
    S32 mime_subtype,
    S32 action,
	U32 filesize,
	S8 *url,
	S8 *mime_type_string,
	U32 content_len,
	S8 *content,
	srv_da_setting_struct *setting);

/*****************************************************************************
 * FUNCTION
 *  srv_da_push_setting
 * DESCRIPTION
 *  Default setting function for convenience. If the file is usually received via
 *  WAP push, and application hopes that do not popup anything and dispatch directly
 *  whatever the circumstance when receiving the push, this setting function can
 *  help to fill appropriate values of setting.
 *  The configurations for push source are listed as below:
 *    1. Auto select a storage, may be phone or memory card. If none of each available,
 *       it will store the push on SYSTEM DRIVE and dispatch the file from SYSTEM DRIVE
 *       directly. Application MUST clean the file after dispatch by itself.
 *    2. Assign a temporary filename
 *    3. Put the file in a temp folder, all files in the temp folder will be
 *       cleaned after reboot. If application does not need the file no longer after dispatch,
 *       it HAS TO delete the file by itself. If application hopes the file can be kept,
 *       be sure to move the file to other space after dispatch.
 *    4. Dispatch directly without the confirmation with user
 *    5. Do not popup anything when receiving the push
 *       I.e., setting->confirm_push = MMI_FALSE;
 *    6. Dispatch after file received.
 *  If file is received from application's save-object(e.g. MMS save-object) operation,
 *  this setting will not dispatch and only save the file.
 * PARAMETERS
 *  session_id          : [IN]    Session ID
 *  mime_type           : [IN]    applib_mime_type_enum
 *  mime_subtype        : [IN]    applib_mime_subtype_enum
 *  action              : [IN]    srv_da_action_enum
 *  filesize            : [IN]    File size
 *  url                 : [IN]    URL in ASCII encoding
 *  mime_type_string    : [IN]    MIME type string in ASCII encoding
 *  content_len         : [IN]    Content-Length in HTTP header
 *  content             : [IN]    Content in HTTP response
 *  setting             : [OUT]   Appropriate behavior setting by previous information.
 * RETURNS
 *  void
 * SEE ALSO
 *  srv_da_setting_hdlr
 *****************************************************************************/
extern void srv_da_push_setting(
    S32 session_id,
    S32 mime_type,
    S32 mime_subtype,
    S32 action,
	U32 filesize,
	S8 *url,
	S8 *mime_type_string,
	U32 content_len,
	S8 *content,
	srv_da_setting_struct *setting);

/*****************************************************************************
 * FUNCTION
 *  srv_da_register_type_handler
 * DESCRIPTION
 *  Register a type handler to download agent.
 *  <b>This function is only provided to vendors. For internal development,
 *  please fill the MIME type handler table.</b>
 * PARAMETERS
 *  mime_type       : [IN] MIME type
 *  mime_subtype    : [IN] MIME subtype
 *  presetting_hdlr : [IN] Presetting handler to configure pre-setting.
 *                         See the description of srv_da_presetting_hdlr.
 *  setting_hdlr    : [IN] Setting handler to configure setting
 *                         See the description of srv_da_setting_hdlr.
 *  dispatch_hdlr   : [IN] Dispatch handler that the received file will be
 *                         dispatched to.
 *                         See the description of srv_da_dispatch_hdlr.
 * RETURNS
 *  MMI_TRUE : Successfully registered
 *  MMI_FALSE : Already a type handler exists or insufficient entry resource.
 *****************************************************************************/
extern MMI_BOOL srv_da_register_type_handler(
    applib_mime_type_enum mime_type,
    applib_mime_subtype_enum mime_subtype,
    srv_da_presetting_hdlr presetting_hdlr,
    srv_da_setting_hdlr setting_hdlr,
    srv_da_dispatch_hdlr dispatch_hdlr);

/*****************************************************************************
 * FUNCTION
 *  srv_da_save_file
 * DESCRIPTION
 *  Save and dispatch a file. Download agent will follow the formal saving
 *  procedure defined by the MIME type. Usually download agent will show
 *  a select-storage screen and then dispatch the saved file to appropriate
 *  application; but depends on the MIME type setting.
 *  Download agent will hode copies for all parameters, so the client is allowed
 *  to release the space of parameters after function calling.
 * PARAMETERS
 *  app_id              : [IN] Application ID
 *  filepath            : [IN] The path of file to be saved/dispatched
 *  default_filename    : [IN] This filename will be the default filename for the
 *                             filename editor for user. NOT contain file extension.
 *                             If this value is NULL, the default filename will
 *                             be extracted from filepath
 *  mime_type_string    : [IN] MIME type string. If NULL, it will get the MIME
 *                             type from the file extension of filepath
 *  extra_info_size     : [IN] Size of extra_info.data that dispatch_hdlr can
 *                             get by srv_da_get_extra_info().
 *  extra_info_data     : [IN] extra_info.data that dispatch_hdlr can get by
 *                             srv_da_get_extra_info(). This API will hold a copy
 *                             of data by memcpy(). See srv_da_extra_info_struct
 *                             for more information.
 *  ui_setting          : [IN] UI setting
 * RETURNS
 *  void
 * SEE ALSO
 *  srv_da_get_extra_info
 *****************************************************************************/
extern void srv_da_save_file(
    U16 app_id,
    const U16 *filepath,
    const U16 *default_filename,
    const S8 *mime_type_string,
    U32 extra_info_size,
    const void *extra_info_data,
    const srv_da_ui_setting_struct *ui_setting);

/*****************************************************************************
 * FUNCTION
 *  srv_da_get_extra_info
 * DESCRIPTION
 *  Get the data attached from lower layer.
 *  NOTE: Extra info is only available on setting handler & dispatch handler.
 *  if this function is called outside the context of these 2 handlers,
 *  it always returns NULL. And DO NOT hold the pointer returned outside these
 *  2 handlers.
 * PARAMETERS
 *  session_id  : [IN] Session ID of dispatching
 * RETURNS
 *  Extra info
 *****************************************************************************/
extern const srv_da_extra_info_struct* srv_da_get_extra_info(S32 session_id);

#ifdef __MMI_OMA_DD_DOWNLOAD__
/*****************************************************************************
 * FUNCTION
 *  srv_da_oma_get_installParam
 * DESCRIPTION
 *  Get the value of installParam of an OMA download.
 * PARAMETERS
 *  session_id      : [IN] Session ID
 * RETURNS
 *  The value of installParam. If absent, returns NULL.
 *****************************************************************************/
extern const S8* srv_da_oma_get_installParam(S32 session_id);
#endif

/* --------------------- Progressive download APIs -------------------- */
#ifdef __MMI_VIDEO_PDL__
/*****************************************************************************
 * FUNCTION
 *  srv_da_stop_pdl
 * DESCRIPTION
 *  Stop reporting.
 *  If application fills report_hdlr(), download agent will call this function
 *  if progress changes while downloading. Call this function will stop reporting
 *  afterward. If user selects continue reporting, download agent will call
 *  filepath_hdlr() again and start to continue reporting via report_hdlr().
 * PARAMETERS
 *  session_id      : [IN] Session ID
 * RETURN VALUES
 *  SRV_DA_SUCCESS : Succeed
 *  SRV_DA_ERROR_FAIL : Invalid session ID
 *****************************************************************************/
extern S32 srv_da_stop_pdl(S32 session_id);
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_da_stop_dl
 * DESCRIPTION
 *  Stop downloading. This function is only useful for
 *  DOWNLOADING, COMPLETED and PAUSED job. Once a download is stopped, it is removed
 *  from the job list permanently. After a download is removed, its session ID
 *  is no long valid.
 *  This API can be called only after download agent starts reporting, and DO NOT
 *  call in callbacks.
 * PARAMETERS
 *  session_id      : [IN] Session ID
 * RETURN VALUES
 *  SRV_DA_SUCCESS : Download stopped and is removed from list.
 *  SRV_DA_ERROR_FAIL : Invalid session ID or not in DOWNLOADING, COMPLETED or PAUSED state.
 *****************************************************************************/
extern S32 srv_da_stop_dl(S32 session_id);

/*****************************************************************************
 * FUNCTION
 *  srv_da_remove_dl
 * DESCRIPTION
 *  Remove a completed item from download list.
 *  For some settings, the item will stay on the list after download completed.
 *  This function is provided for the applications who want to remove it from
 *  the list.
 * PARAMETERS
 *  session_id      : [IN] Session ID
 * RETURN VALUES
 *  SRV_DA_SUCCESS : Removed successfully.
 *  SRV_DA_ERROR_FAIL : Invalid session ID or not in COMPLETED state.
 *****************************************************************************/
extern S32 srv_da_remove_dl(S32 session_id);

/*****************************************************************************
 * FUNCTION
 *  srv_da_get_cause_string
 * DESCRIPTION
 *  Get proper error string by cause. If the returned string is improper for
 *  certain special case of application, application should popup string
 *  by theirselves.
 * PARAMETERS
 *  cause   : [IN] Cause
 * RETURNS
 *  String ID
 *****************************************************************************/
extern U16 srv_da_get_cause_string(srv_da_error_enum cause);




/* ------------- Idle screen  / shutdown callback functions ----------- */

/*****************************************************************************
 * <GROUP InternalCallBacks>
 *
 * FUNCTION
 *  mmi_da_launch_ring_buffer_check
 * DESCRIPTION
 *  Check whether there is queued push. Idle callback mechanism calls this API
 *  to determine whether to enter New push screen.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MMI_TRUE : If there is push queued and waiting for user's confirmation
 *  MMI_FALSE : No push is queued
 *****************************************************************************/
extern U8 mmi_da_launch_ring_buffer_check(void);

/*****************************************************************************
 * <GROUP InternalCallBacks>
 *
 * FUNCTION
 *  mmi_da_entry_new_push_ind
 * DESCRIPTION
 *  Enter New push screen. Used in Idle callback mechanism.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_da_entry_new_push_ind(void);

/* ------------------ USB mode callback functions ----------------- */

/*****************************************************************************
 * <GROUP InternalCallBacks>
 *
 * FUNCTION
 *  srv_da_usb_mode_on
 * DESCRIPTION
 *  Notify download agent of entering USB mode.
 *  Download agent will suspend all downloads.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern mmi_ret srv_da_usb_mode_on(mmi_event_struct *evt);


/* ------------------ File manager notification callback  ----------------- */

/*****************************************************************************
 * <GROUP InternalCallBacks>
 *
 * FUNCTION
 *  srv_fmgr_dla_notify_hdlr
 * DESCRIPTION
 *  Notify download agent of drive status changes.
 * PARAMETERS
 *  notify_flag     : [IN] Event type; for example, DRIVE_UNMOUNT
 *                         Refer to mmi_fmgr_notify_event_flag
 *  para            : [IN] Unused
 * RETURNS
 *  Always TRUE
 *****************************************************************************/
extern BOOL srv_fmgr_dla_notify_hdlr(U32 notify_flag, void* para);


/* DOM-NOT_FOR_SDK-BEGIN */

#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
extern S32 srv_da_resume_dl(S32 session_id);
#endif


/******************************************
 * Only DM use following function now
 * WILL BE DISCARDED IN THE FUTURE
 ******************************************/
#ifdef __MMI_DA_OMADL_CUST_CHL_SUPPORT__
#ifdef __MMI_OMA_DD_DOWNLOAD__
typedef void (*srv_da_dl_report_callback)(BOOL success);
void srv_da_start_oma_download(S8* dd_filepath, void* req, BOOL show_confirm, srv_da_dl_report_callback cb);
#endif
#endif

extern const S8* srv_da_get_header(S32 session_id, U32* header_len);
extern void srv_da_display_download_list(void);
/* MRE Download Begin */
typedef enum
{
    SRV_DA_DOWNLOAD_STOP = 0,
    SRV_DA_DOWNLOAD_PAUSE,
    SRV_DA_DOWNLOAD_RESUME,
    
    SRV_DA_DOWNLOAD_STOP_END_OF_ENUM
} srv_da_download_cause_enum;

typedef struct
{
    U32 arg;
    U8 status;
    U32 curr_size;
	U32 total_size;
	U16 *savepath;
	S32 cause;
	void *user_data;
} srv_da_download_progress_struct;

typedef void (*srv_da_http_progress_funcptr_type)(srv_da_download_progress_struct *report_struct);
typedef void (*srv_da_http_aborted_funcptr_type)(U32 arg, srv_da_download_cause_enum cause);

typedef struct
{
    WCHAR *url;
    U32 acc_id;
	U32 file_length;
    MMI_BOOL show_confirm;
	U16 *filepath;
	void *user_data;
	srv_da_http_progress_funcptr_type dl_progress; //DLAgent will notify the APP(invoked DLAgent) about the progress of download (if the APP want they can provide the callback).
	srv_da_setting_hdlr setting_hdlr;
	srv_da_dispatch_hdlr dispatch_callback;	
} srv_da_start_download_struct;

extern U32 srv_da_start_http_download(srv_da_start_download_struct *arg);
extern void srv_da_http_dl_operation(U32 arg, srv_da_download_cause_enum cause);
extern S32 srv_da_get_job_count(void);

/* MRE Download END */

/* DOM-NOT_FOR_SDK-END */





typedef enum
{
    EVT_ID_DLA_SRV_SHOW_PROGRESS = DL_AGENT_BASE + 1,
    EVT_ID_DLA_SRV_POPUP_FOR_JOB_MSG,
	EVT_ID_DLA_SRV_POPUP, 
	EVT_ID_DLA_SRV_IS_USB_AVAILABLE,
	EVT_ID_DLA_SRV_JAVA_FILE_IND,
	EVT_ID_DLA_SRV_JAVA_SETTING_IND,
	EVT_ID_DLA_SRV_CERTMAN_SETTING_IND,
	EVT_ID_DLA_SRV_SET_STORAGE_INSTANCE,                 /* FOR PLUTO ONLY */
	EVT_ID_DLA_SRV_DISPLAY_JOB_LIST,
	EVT_ID_DLA_SRV_DISPLAY_JOB_DETAIL,                   /* FOR PLUTO ONLY */
	EVT_ID_DLA_SRV_PROGRESSING_CLOSE,
	EVT_ID_DLA_SRV_POPUP_ERRORCODE_WITH_CALLBACK,
	EVT_ID_DLA_SRV_SHOW_NEW_DOWNLOAD_CONFIRM_SCREEN,
	EVT_ID_DLA_SRV_SET_ACTIVE_DOWNLOAD_CONFIRM_SCREEN,
    EVT_ID_DLA_SRV_WPS_HTTP_RSP_CALLBACK,

	EVT_ID_DLA_SRV_CONFIRM_OMA_DOWNLOAD,
	EVT_ID_DLA_SRV_SELECT_STORAGE,                       /* FOR PLUTO ONLY */
    EVT_ID_DLA_SRV_OMA_HANDLE_HTTP_RSP,
    EVT_ID_DLA_SRV_SHOW_USER_AUTH_SCREEN,
    EVT_ID_DLA_SRV_PUSH_PROCESS_ITEM,
    EVT_ID_DLA_SRV_UPDATE_JOB_STATUS,
    EVT_ID_DLA_SRV_DRM_SAVE_AS,                          /* FOR PLUTO ONLY */
    EVT_ID_DLA_SRV_UPDATE_CONTENT_BY_DRM_PROCESSING,     /* FOR PLUTO ONLY */
    EVT_ID_DLA_SRV_CLICK_JOB,
    EVT_ID_DLA_SRV_JOB_ABORTED_CALLBACK,
    EVT_ID_DLA_SRV_REMOVE_JOB_SCREENS,
    EVT_ID_DLA_SRV_UPDATE_NCENTER,
    EVT_ID_DLA_SRV_UPDATE_NCENTER_DOWNLOADING_CELL,
    EVT_ID_DLA_SRV_UPDATE_NCENTER_COMPLETED_CELL,
    EVT_ID_DLA_SRV_UPDATE_NCENTER_FAILED_CELL,
    EVT_ID_DLA_SRV_UPDATE_NCENTER_PUSHED_OBJ_CELL,
    EVT_ID_DLA_SRV_CLOSE_APP,
	EVT_ID_DLA_SRV_POPUP_ERROR_FOR_JOB,
	EVT_ID_DLA_SRV_POPUP_FOR_JOB,
	EVT_ID_DLA_SRV_SHOW_NMGR_POPUP,

    /* Add events before this */
    EVT_ID_DLA_SRV_END
} srv_dla_event_enum;

#ifdef __J2ME__
typedef struct 
{
    MMI_EVT_PARAM_HEADER
	S32	session_id;
    S32	mime_type;
    S32	mime_subtype;
    S32 action;
    PU16 file_path;
    PS8	url;
    PS8	mime_type_string;

} srv_da_receive_java_file_struct;

typedef struct 
{
    MMI_EVT_PARAM_HEADER
	S32	session_id;
    S32	mime_type;
    S32	mime_subtype;
    S32 action;
    U32	filesize;
    PS8	url;
    PS8	mime_type_string;
    U32	content_len;
    PS8	content;
    srv_da_setting_struct *setting;
} srv_da_setting_java_file_struct;
#endif

#ifdef __CERTMAN_SUPPORT__
typedef struct 
{
    MMI_EVT_PARAM_HEADER
	S32 session_id;
    S32 mime_type;
    S32 mime_subtype;
    S32 action_type;
    PU16 filename;
    PS8 download_url;
    PS8 mime_type_str_string;
}srv_da_certman_install_file;
#endif

#endif /* DOWNLOAD_AGENT_GPROT_H */

