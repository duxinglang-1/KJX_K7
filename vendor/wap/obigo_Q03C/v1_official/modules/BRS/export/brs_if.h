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

/*
 * Copyright (C) Obigo AB, 2002-2007.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Obigo AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Obigo AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */
/*
 * brs_if.h
 *
 * Created by Petter Wallin, Aug 07 2002.
 *
 * Revision  history:
 *   020903, AED: Updated
 *   021108, STMA: added focus constants.
 */

/*******************************************************************************
 *
 * Filename:
 * ---------
 * brs_if.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * BRS interface.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/ 
 
#ifndef _brs_if_h
#define _brs_if_h

#include "msf_cfg.h"

#ifndef  _msf_def_h
#include "msf_def.h"
#endif

#ifndef  _msf_dcvt_h
#include "msf_dcvt.h"
#endif

#ifndef  _msf_int_h
#include "msf_int.h"
#endif

#ifndef _brs_cfg_h
#include "brs_cfg.h"
#endif

/**********************************************************************
 * Signals 
 **********************************************************************/

/* Signals sent to the BRS */
#define BRS_SIG_CREATE_INSTANCE          ((MSF_MODID_BRS << 8) + 0x01)
#define BRS_SIG_DELETE_INSTANCE          ((MSF_MODID_BRS << 8) + 0x02)
#define BRS_SIG_RESIZE_WINDOW            ((MSF_MODID_BRS << 8) + 0x03)
#define BRS_SIG_LOAD_URL                 ((MSF_MODID_BRS << 8) + 0x04)
#define BRS_SIG_ACTIVATE_DO_ELEMENT      ((MSF_MODID_BRS << 8) + 0x05)
#define BRS_SIG_MOVE                     ((MSF_MODID_BRS << 8) + 0x06)
#define BRS_SIG_RELOAD                   ((MSF_MODID_BRS << 8) + 0x07)
#define BRS_SIG_STOP                     ((MSF_MODID_BRS << 8) + 0x08)
#define BRS_SIG_NAVIGATION_CHANGE        ((MSF_MODID_BRS << 8) + 0x09)
#define BRS_SIG_SAVE_PAGE_OFFLINE        ((MSF_MODID_BRS << 8) + 0x0a)
#define BRS_SIG_SET_OFFLINE_MODE         ((MSF_MODID_BRS << 8) + 0x0b)
#define BRS_SIG_DELETE_OFFLINE_PAGE      ((MSF_MODID_BRS << 8) + 0x0c)

/* Signals sent from the BRS */
#define BRS_SIG_CREATED                  ((MSF_MODID_BRS << 8) + 0x0d)
#define BRS_SIG_STATUS                   ((MSF_MODID_BRS << 8) + 0x0e)
#define BRS_SIG_ERROR                    ((MSF_MODID_BRS << 8) + 0x0f)
#define BRS_SIG_DOCUMENT_INFO            ((MSF_MODID_BRS << 8) + 0x10)
#ifndef BRS_CFG_DISPLAY_INLINE_DO
#define BRS_SIG_DO_ELEMENTS              ((MSF_MODID_BRS << 8) + 0x11)
#endif
#define BRS_SIG_ELEMENT_FOCUSED          ((MSF_MODID_BRS << 8) + 0x12)
#define BRS_SIG_PAGE_NOT_FOUND_OFFLINE   ((MSF_MODID_BRS << 8) + 0x13)
#define BRS_SIG_HANDLE_SCHEME_RSP        ((MSF_MODID_BRS << 8) + 0x14)

/* BRS_CFG_9W_NAV_SUPPORT */
#ifdef MSF_CFG_9W_MODE_KBRD_SIMULATION
#define BRS_SIG_CHANGE_9W_MODE           ((MSF_MODID_BRS << 8) + 0x15)
#endif

#define BRS_SIG_HTTP_REQUEST_ABORTED     ((MSF_MODID_BRS << 8) + 0x16)
#ifdef MSF_CFG_BRW_WMLS_NON_WIDGET_DLG_SUPPORT
#define BRS_SIG_WMLS_DLG_RESPONSE        ((MSF_MODID_BRS << 8) + 0x17)
#endif


#ifndef MSF_REGISTRY_SUPPORT
#define BRS_SIG_APP_PREF_CHANGED         ((MSF_MODID_BRS << 8) + 0x18)
#endif  /* MSF_REGISTRY_SUPPORT */

/* BEARER_SWITCH starts */
#define BRS_SIG_BEARER_OPEN_RESPONSE     ((MSF_MODID_BRS << 8) + 0x19)
/* BEARER_SWITCH ends */

/**********************************************************************
 * Registry keys:
 **********************************************************************/

/*
 * All of the keys below should be set under a path, "/BRS/xyz",
 * where "xyz" is the value of the parameter 'applicationName'
 * in BRSif_createInstance.
 */

/* Registry keys having an integer value: */
#define BRS_REGISTRY_KEY_HISTORY_SIZE             "histsize"
#define BRS_REGISTRY_KEY_REFRESH_ENABLED          "refresh"
#define BRS_REGISTRY_KEY_CSS_ENABLED              "use_css"
#define BRS_REGISTRY_KEY_CONNECTION_TYPE          "con_type"
#define BRS_REGISTRY_KEY_NETWORK_ACCOUNT_ID       "acc_id"
#define BRS_REGISTRY_KEY_PROXY_PORT               "prx_port"
#define BRS_REGISTRY_KEY_PROXY_SECURE_PORT        "prx_secp"
#define BRS_REGISTRY_KEY_WML_INLINE_DO            "inlinedo"
#define BRS_REGISTRY_KEY_OBJECT_LOAD_NULL_MIME    "ldnomime"
#define BRS_REGISTRY_KEY_REQUEST_TIMEOUT          "timeout"
#define BRS_REGISTRY_KEY_SEND_REFERRER            "sndrefrr"
#define BRS_REGISTRY_KEY_NARROW_RENDERING_ENABLED "nrrwrnd"
#define BRS_REGISTRY_KEY_CACHE_ON                 "cacheon"


/* Registry keys having a string value: */
#define BRS_REGISTRY_KEY_ACCEPT_HEADER            "accept"
#define BRS_REGISTRY_KEY_ACCEPT_OBJECT_HEADER     "accptobj"
#define BRS_REGISTRY_KEY_ACCEPT_CHARSET_HEADER    "acc_chrs"
#define BRS_REGISTRY_KEY_ACCEPT_LANGUAGE_HEADER   "acc_lang"
#define BRS_REGISTRY_KEY_USER_AGENT_HEADER        "user_agt"
#define BRS_REGISTRY_KEY_IMODE_USER_AGENT_HEADER  "imode_ua"
#define BRS_REGISTRY_KEY_PROXY_ADDRESS            "prx_addr"
#define BRS_REGISTRY_KEY_PROXY_USERNAME           "prx_uid"
#define BRS_REGISTRY_KEY_PROXY_PASSWORD           "prx_pwd"
#define BRS_REGISTRY_KEY_PROXY_REALM              "prx_rlm"
#define BRS_REGISTRY_KEY_OBJECT_LOAD              "obj_load"
#define BRS_REGISTRY_KEY_OBJECT_ASK               "obj_ask"
#define BRS_REGISTRY_KEY_USER_STYLE_SHEET         "cssprefs"



/**********************************************************************
 * Other constants:
 **********************************************************************/

#define BRS_MOVE_BACKWARD                         1
#define BRS_MOVE_FORWARD                          2
#define BRS_MOVE_RELOAD                           3

#define BRS_INFO_FLAG_ENABLE_BACK                 0x01
#define BRS_INFO_FLAG_ENABLE_FORWARD              0x02
#define BRS_INFO_FLAG_NEW_PAGE                    0x04
#define BRS_INFO_FLAG_NEW_PAGE_IN_HISTORY         0x08
#define BRS_INFO_FLAG_SAVED_PAGE                  0x10
#define BRS_INFO_FLAG_MAIN_WINDOW                 0x20
#define BRS_INFO_FLAG_LOCAL_NAVIGATION            0x40

#define BRS_OPTION_NO_CACHE                       0x01

#define BRS_FOCUSED_ELEMENT_NONE                  0
/* a and anchor*/
#define BRS_FOCUSED_ELEMENT_LINK                  1
/* do elements, if rendered in content*/
#define BRS_FOCUSED_ELEMENT_DO                    2
/* textarea and input type="text"*/
#define BRS_FOCUSED_ELEMENT_TEXTINPUT             3
#define BRS_FOCUSED_ELEMENT_SELECT                4
/* img and object*/
#define BRS_FOCUSED_ELEMENT_IMAGE                 5
#define BRS_FOCUSED_ELEMENT_IMG_NO_SAVE           6
/* input type="image"*/
#define BRS_FOCUSED_ELEMENT_INPUT                 7
/* input type="button" or element button*/
#define BRS_FOCUSED_ELEMENT_BUTTON                8
#define BRS_FOCUSED_ELEMENT_SUBMIT                9
#define BRS_FOCUSED_ELEMENT_RESET                 10
#define BRS_FOCUSED_ELEMENT_FILE_INPUT            11
/* input type="checkbox", "radio" depening on whether they are checked or not.*/
/* MAUI_01593927 starts */
/*
#define BRS_FOCUSED_ELEMENT_INPUT_SELECTED        12
#define BRS_FOCUSED_ELEMENT_INPUT_UNSELECTED      13
*/
#define BRS_FOCUSED_ELEMENT_CHKBOX_SELECTED        12
#define BRS_FOCUSED_ELEMENT_CHKBOX_UNSELECTED      13
/* MAUI_01593927 ends */
/* Area element in imagemaps */
#define BRS_FOCUSED_ELEMENT_AREA                  14
/* Input element with type image */
#define BRS_FOCUSED_ELEMENT_INPUT_IMAGE           15

/* MAUI_01593927 starts */
#define BRS_FOCUSED_ELEMENT_RADIO_SELECTED        16
#define BRS_FOCUSED_ELEMENT_RADIO_UNSELECTED      17
/* MAUI_01593927 ends */

#define BRS_FOCUSED_ELEMENT_IMAGE_LONG_TAP      18

/************************************************************
 * DRM information for focused element.
 ************************************************************/
#define BRS_FOCUSED_ELEM_DRM_RESTRICTION_NONE         0
#define BRS_FOCUSED_ELEM_DRM_RESTRICTION_FWD_LOCK     1

/************************************************************
 * Status Codes
 ************************************************************/

#define BRS_STATUS_START_TRANSACTION              1
#define BRS_STATUS_END_TRANSACTION                2
#define BRS_STATUS_LOADING_DOCUMENT               3
#define BRS_STATUS_LOADING_DOCUMENT_DONE          4
#define BRS_STATUS_LOADING_DOCUMENT_FAILED        5
#define BRS_STATUS_LOADING_OBJECT                 6
#define BRS_STATUS_LOADING_OBJECT_DONE            7
#define BRS_STATUS_LOADING_OBJECT_FAILED          8
#define BRS_STATUS_OBJECT_NOT_IN_CACHE            9
#define BRS_STATUS_OFFLINE_MODE_ON               10
#define BRS_STATUS_OFFLINE_MODE_OFF              11
#define BRS_STATUS_OFFLINE_PAGE_SAVE_OK          12
#define BRS_STATUS_OFFLINE_PAGE_SAVE_FAILED      13
#define BRS_STATUS_UPLOAD_FILE      14
#define BRS_STATUS_OFFLINE_PAGE_EXISTS           15     /* MAUI_02454764 */




/************************************************************
 * Error Codes
 ************************************************************/

/* Invalid input */
#define BRS_ERROR_INVALID_INPUT                   14
#define BRS_ERROR_INVALID_URL                     15
#define BRS_ERROR_INVALID_SCHEME                  16

/* Parser error codes. For more information, see msf_prsr.h. */
#define BRS_ERROR_UNKNOWN_CHARSET                 21
#define BRS_ERROR_SYNTAX                          22
#define BRS_ERROR_UNKNOWN_DOCTYPE                 23
#define BRS_ERROR_UNSUPPORTED_WBXML               24
#define BRS_ERROR_UNEXPECTED_END_OF_DOC           25
#define BRS_ERROR_VALIDATION                      26
#define BRS_ERROR_ABORTED                         27
#define BRS_ERROR_REQUIRE_FRAMES                  28
#define BRS_ERROR_ABORTED_BY_UA                   29
#define BRS_ERROR_NO_DISPLAY_CONTENT              65    /* MAUI_02439070 */

/* 'WMLS' errors, i.e., error in WMLScript */
#define BRS_ERROR_WMLS                            30
#define BRS_ERROR_WMLS_VERIFICATION               31
#define BRS_ERROR_WMLS_LIB                        32
#define BRS_ERROR_WMLS_FUNC_ARGS                  33
#define BRS_ERROR_WMLS_EXTERNAL                   34
#define BRS_ERROR_WMLS_LOAD                       35
#define BRS_ERROR_WMLS_INTERPRETING               36
#define BRS_ERROR_WMLS_ABORT                      37
#define BRS_ERROR_WMLS_EXIT                       38

/* Access restrictions on WML or WMLScript */
#define BRS_ERROR_ACCESS_RESTRICTIONS_WML         40
#define BRS_ERROR_ACCESS_RESTRICTIONS_WMLS        41

/* Communication errors. */
#define BRS_ERROR_COMMUNICATION                   50
#define BRS_ERROR_HOST_NOT_FOUND                  51
#define BRS_ERROR_REQUEST_TIMED_OUT               52
#define BRS_ERROR_CONNECTION_FAILED               53
#define BRS_ERROR_SECURE_CONNECTION_FAILED        54
#define BRS_ERROR_AUTHENTICATION                  55
#define BRS_ERROR_FILE_SIZE_TOO_LARGE             59
/* Misc. */
#define BRS_ERROR_INTERNAL                        60
#define BRS_ERROR_RESEND_POST_WARNING             61
#define BRS_ERROR_OUT_OF_MEMORY                   62
#define BRS_ERROR_CONTENT_TOO_LARGE               63
#define BRS_ERROR_UNSUPPORTED_SCRIPT_WARNING      64
#ifdef BRS_CFG_TRANSCODE_PROXY_REQUEST
#define BRS_ERROR_TRANSCODE_PROXY_FAIL            66
#endif
/**********************************************************************
 * Markable elements
 **********************************************************************/
#define BRS_MARKABLE_ELEMENT_A           0x0001
#define BRS_MARKABLE_ELEMENT_ANCHOR      0x0002
#define BRS_MARKABLE_ELEMENT_AREA        0x0004
#define BRS_MARKABLE_ELEMENT_DO          0x0008
#define BRS_MARKABLE_ELEMENT_IMG         0x0010
#define BRS_MARKABLE_ELEMENT_INPUT       0x0020
#define BRS_MARKABLE_ELEMENT_LABEL       0x0040
#define BRS_MARKABLE_ELEMENT_OBJECT      0x0080
#define BRS_MARKABLE_ELEMENT_OPTION      0x0100
#define BRS_MARKABLE_ELEMENT_SELECT      0x0200
#define BRS_MARKABLE_ELEMENT_TEXTAREA    0x0400
#define BRS_MARKABLE_ELEMENT_INPUT_IMAGE 0x0800



#define BRS_MARKABLE_ELEMENT_DEFAULT  (BRS_MARKABLE_ELEMENT_A | BRS_MARKABLE_ELEMENT_ANCHOR | \
                                       BRS_MARKABLE_ELEMENT_AREA | \
                                       BRS_MARKABLE_ELEMENT_DO | BRS_MARKABLE_ELEMENT_INPUT | \
                                       BRS_MARKABLE_ELEMENT_OPTION| \
                                       BRS_MARKABLE_ELEMENT_SELECT | BRS_MARKABLE_ELEMENT_TEXTAREA)


#ifndef BRS_CFG_DISPLAY_INLINE_DO
/**********************************************************************
 * Type definitions
 **********************************************************************/


typedef struct {
  MSF_INT16  elementId;     /* Unique ID, used in BRS_SIG_ACTIVATE_DO_ELEMENT */
  char      *eventType;     /* Event type, "accept", "prev", etc. */
  char      *label;         /* Label, an attribute in the DO-element */
  MSF_BOOL   isOptional;    /* TRUE if this DO element is optional */
} brs_do_element_t;
#endif /* BRS_CFG_DISPLAY_INLINE_DO */


/* BEARER_SWITCH starts */
typedef struct
{
  MSF_INT16 instanceId;
  int status;
} brs_bearer_open_response_t;
/* BEARER_SWITCH ends */


/**********************************************************************
 * Signal parameters 
 **********************************************************************/

/* For the signal BRS_SIG_CREATE_INSTANCE */ 
typedef struct { 
  MsfScreenHandle  screenHandle;
  MSF_INT16        windowPositionX;
  MSF_INT16        windowPositionY;
  MSF_INT16        windowSizeHeight;
  MSF_INT16        windowSizeWidth;
  char            *applicationName;
} brs_create_instance_t;

/* For the signal BRS_SIG_CREATED */ 
typedef struct { 
  MsfWindowHandle paintBox;
  MSF_INT16 instanceId;
  MSF_INT16 errorCode;
} brs_created_t;

/* For the signal BRS_SIG_DELETE_INSTANCE */ 
typedef struct { 
  MSF_INT16 instanceId;
} brs_delete_instance_t;

/* For the signal BRS_SIG_RESIZE_WINDOW */ 
typedef struct { 
  MSF_INT16 instanceId;
  MSF_INT16 windowPositionX;
  MSF_INT16 windowPositionY;
  MSF_INT16 windowSizeHeight;
  MSF_INT16 windowSizeWidth;
} brs_resize_window_t;

/* For the signal BRS_SIG_LOAD_URL */ 
typedef struct { 
  MSF_INT16  instanceId;
  MSF_INT16  options; 
  char      *url;
} brs_load_url_t;

#ifndef BRS_CFG_DISPLAY_INLINE_DO
/* For the signal BRS_SIG_ACTIVATE_DO_ELEMENT */
typedef struct {
  MSF_INT16 instanceId;
  MSF_INT16 elementId;
} brs_activate_do_element_t;
#endif /* BRS_CFG_DISPLAY_INLINE_DO */

/* For the signal BRS_SIG_MOVE */ 
typedef struct { 
  MSF_INT16 instanceId; 
  MSF_INT16 direction; 
  MSF_INT16 steps;
} brs_move_t;

/* For the signal BRS_SIG_RELOAD */ 
typedef struct { 
  MSF_INT16 instanceId; 
} brs_reload_t;

/* For the signal BRS_SIG_STOP */ 
typedef struct { 
  MSF_INT16 instanceId;
} brs_stop_t;


/* For the signal BRS_SIG_STATUS */
typedef struct {
  MSF_INT16  instanceId;
  MSF_INT16  status;
  MSF_INT16  transactionId;
  char      *url;
  MSF_INT32  size;
  MSF_INT32 upload_bytes_sent;               /**< Number of bytes uploaded to the server during the transaction. */
  MSF_INT32 upload_bytes_total;              /**< Total number of bytes to be uploaded to the server during the transaction. */
  MSF_INT32 document_bytes_read;             /**< Number of bytes received of the documents downloaded during the transaction. */
  MSF_INT32 document_bytes_total;            /**< Expected total number of bytes to be received of the documents 
                                              *   downloaded during the transaction. */
  MSF_INT16 document_number_of_requested;    /**< Number or requested documents. */
  MSF_INT16 document_number_of_downloaded;   /**< Number of downloaded documents. */
  MSF_INT16 document_number_of_failed;       /**< Number of failed document downloads.*/
  MSF_INT32 resources_bytes;                 /**< Number of bytes received from downloaded resources during the transaction. */
  MSF_INT16 resources_number_of_requested;   /**< Number of downloaded resources. */
  MSF_INT16 resources_number_of_downloaded;  /**< Number of downloaded resources.*/
  MSF_INT16 resources_number_of_failed;      /**< Number of failed resource downloads.*/

} brs_status_t;

/* For the signal BRS_SIG_ERROR */
typedef struct {
  MSF_INT16 instanceId;
  MSF_INT16 errorCode;
  MSF_INT16 stkError; /**< If errorCode is one of the Communication errors,
                        *   then this field may hold further information in
                        *   the form of an error code from STK, or one of
                        *   the STK HTTP status codes. Otherwise it is 0. */
} brs_error_t;

/* For the signal BRS_SIG_DOCUMENT_INFO */
typedef struct {
  MSF_INT16   instanceId; 
  MSF_INT16   documentId; 
  MSF_INT16   flags; 
  char       *url; 
  char       *title;
  MSF_INT32   size; 
  MSF_UINT32  lastModified;
  MSF_INT16   docType;
  MSF_INT32   socketId;
  MSF_INT32   securityId;
  MSF_INT16   protocol;
} brs_document_info_t;

#ifndef BRS_CFG_DISPLAY_INLINE_DO
/* For the signal BRS_SIG_DO_ELEMENTS */
typedef struct {
  MSF_INT16         instanceId;
  MSF_INT16         numElements;
  brs_do_element_t *elements;
} brs_do_elements_t;
#endif /* BRS_CFG_DISPLAY_INLINE_DO */

/* For the signal BRS_SIG_ELEMENT_FOCUSED */
typedef struct {
  MSF_INT16  instanceId;
  MSF_INT16  type;
  MSF_INT16  drm_restriction;
  char*      title;
  char*      url;
  char*      object_url;
  char*      object_mime;
  char*      object_filePath;
} brs_element_focused_t;

/* For the signal BRS_SIG_NAVIGATION_CHANGE */
typedef struct {
  MSF_INT16 instanceId;
  MSF_INT16 elements;
} brs_navigation_change_t;


/* Offline browsing */

/* For the signal BRS_SIG_SAVE_PAGE_OFFLINE */
typedef struct {
  MSF_INT16  instanceId;
  char      *url;
  char      *restrictions;
} brs_save_page_offline_t;

/* For the signal BRS_SIG_SET_OFFLINE_MODE */
typedef struct {
  MSF_INT16  instanceId;
  MSF_INT16  mode;
} brs_set_offline_mode_t;

/* For the signal BRS_SIG_DELETE_OFFLINE_PAGE */
typedef struct {
  #ifdef MTK_TMP_PATCH
  MSF_INT16  instanceId;
  #endif
  char       *url;
} brs_delete_offline_page_t;

/* For the signal BRS_SIG_PAGE_NOT_FOUND_OFFLINE */
typedef struct {
  MSF_INT16  instance_id;
  char      *url;
} brs_page_not_found_offline_t;

typedef struct  
{
  MSF_UINT16   req_id;
  MSF_INT32  result;
}brs_handle_scheme_rsp_struct_t;


#ifdef MSF_CFG_9W_MODE_KBRD_SIMULATION
typedef struct {
  MSF_INT16  instance_id;
} brs_change_9w_mode_t;
#endif /* MSF_CFG_9W_MODE_KBRD_SIMULATION */

//ashutosh
typedef struct {
  MSF_INT16 requestId;
  MSF_INT16 errorCode;
} brs_http_request_aborted_t;
//ashutosh

#ifdef MSF_CFG_BRW_WMLS_NON_WIDGET_DLG_SUPPORT
/* For the signal BRS_SIG_WMLS_DLG_RESPONSE */ 
typedef struct { 
  MSF_INT16  instanceId;
  MSF_INT16  dialog_type;
  MSF_INT16  result;
  char      *prompt_msg;
} brs_wmls_dlg_response_t;
#endif
/*
 * Called by any other module that wants to use the BRS module.
 */
void
BRSif_startInterface (void);


/**********************************************************************
 * Signal-sending API
 * These functions should be used by any other module that wants to
 * send a signal to the BRS module.
 **********************************************************************/

/*  */
void
BRSif_createInstance (MSF_UINT8 src,
                      MsfScreenHandle screenHandle,
                      int windowPositionX, int windowPositionY,
                      int windowSizeHeight, int windowSizeWidth,
                      char *applicationName);

/* */
void
BRSif_deleteInstance (MSF_UINT8 src, int instanceId);

/* */
void
BRSif_resizeWindow (MSF_UINT8 src, int instanceId,
                    int windowPositionX, int windowPositionY,
                    int windowSizeHeight, int windowSizeWidth);

/* */
void
BRSif_loadUrl (MSF_UINT8 src, int instanceId, int options, const char *url);


#ifndef BRS_CFG_DISPLAY_INLINE_DO
/* */
void
BRSif_activateDoElement (MSF_UINT8 src, int instanceId, int elementId);
#endif /* BRS_CFG_DISPLAY_INLINE_DO */


/* */
void
BRSif_move (MSF_UINT8 src, int instanceId, int direction, int steps);

/* */
void
BRSif_reload (MSF_UINT8 src, int instanceId);

/* */
void
BRSif_stop (MSF_UINT8 src, int instanceId);

/* */
void
BRSif_navigationChange (MSF_UINT8 src, int instanceId, MSF_UINT16 elements);


#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
/* */
void
BRSif_savePageOffline (MSF_UINT8 src, int instanceId, 
                       const char* url, const char *restrictions);

/* */
void
BRSif_setOfflineMode (MSF_UINT8 src, int instanceId, int mode);

/* */
#ifdef MTK_TMP_PATCH
void
BRSif_deleteOfflinePage (MSF_UINT8 src, int instanceId, const char* url);
#else
void
BRSif_deleteOfflinePage (MSF_UINT8 src, const char* url);
#endif
#endif

void BRSif_sendUriResponse(MSF_UINT8 src, MSF_UINT16 req_id, MSF_INT32 result);

#ifdef MSF_CFG_BRW_WMLS_NON_WIDGET_DLG_SUPPORT
void BRSif_wmlsDlgResponse(MSF_UINT8 src, MSF_UINT16 instanceId, MSF_UINT16 dialog_type, MSF_UINT16 result, const char *prompt_msg);
#endif

#ifndef MSF_REGISTRY_SUPPORT
void BRSif_appReadyToStart(MSF_UINT8 src, MSF_UINT16 instanceId);
void BRSif_appPrefChanged(MSF_UINT8 src, MSF_UINT16 instanceId);
#endif /* MSF_REGISTRY_SUPPORT */
/**********************************************************************
 * Conversion routines for all signals owned by this module.
 * None of these functions should be called directly by another module.
 **********************************************************************/


#ifdef MSF_CFG_9W_MODE_KBRD_SIMULATION
void BRSif_change9wmode (MSF_UINT8 src, int instanceId);
#endif

extern char* BRSif_getVrsnNo(void);

#ifndef MSF_REGISTRY_SUPPORT
void BRSif_set_preference_values(int index, int i_value, char *s_value);
void BRSif_appPrefChanged(MSF_UINT8 src, MSF_UINT16 instanceId);
#endif /* MSF_REGISTRY_SUPPORT */

#endif
