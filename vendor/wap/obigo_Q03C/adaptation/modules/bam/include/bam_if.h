/*****************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2006
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
 *   bam_if.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   BAM interfaces
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _bam_if_h

#define _bam_if_h

#ifndef _msf_def_h
#include "msf_def.h"

#endif /* _msf_def_h */

#ifndef _msf_dcvt_h
#include "msf_dcvt.h"

#endif /* _msf_dcvt_h */

#ifndef _msf_int_h
#include "msf_int.h"

#endif /* _msf_int_h */

#ifndef _bam_cfg_h
#include "bam_cfg.h"

#endif /* _bam_cfg_h */

#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
extern void BAMif_deleteOfflinePageResponse(MSF_UINT8 src, MSF_INT16 instanceId, char* url, MSF_INT16 result);
#endif
extern void BAMif_handleChannelConfigNotify(void);

#ifdef OBIGO_Q03C_BROWSER

#define BAM_SIG_CREATE_INSTANCE_REQ                     ((MSF_MODID_BAM << 8) + 0x01)
#define BAM_SIG_CREATE_INSTANCE_CNF                     ((MSF_MODID_BAM << 8) + 0x02)
#define BAM_SIG_DELETE_INSTANCE_REQ                     ((MSF_MODID_BAM << 8) + 0x03)
#define BAM_SIG_DELETE_INSTANCE_CNF                     ((MSF_MODID_BAM << 8) + 0x04)
#if 0
/* under construction !*/
#endif
#define BAM_SIG_LOAD_URL_REQ                            ((MSF_MODID_BAM << 8) + 0x06)
#define BAM_SIG_LOAD_DATA_REQ                           ((MSF_MODID_BAM << 8) + 0x07)
#ifndef BAM_CFG_BRW_DISPLAY_INLINE_DO
#define BAM_SIG_ACTIVATE_DO_ELEMENT_REQ                 ((MSF_MODID_BAM << 8) + 0x08)
#endif
#define BAM_SIG_MOVE_REQ                                ((MSF_MODID_BAM << 8) + 0x09)
#define BAM_SIG_RELOAD_REQ                              ((MSF_MODID_BAM << 8) + 0x0a)
#define BAM_SIG_STOP_REQ                                ((MSF_MODID_BAM << 8) + 0x0b)
#define BAM_SIG_NAVIGATION_CHANGE_REQ                   ((MSF_MODID_BAM << 8) + 0x0c)
#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
#define BAM_SIG_SAVE_PAGE_REQ                           ((MSF_MODID_BAM << 8) + 0x0d)
#define BAM_SIG_SAVE_PAGE_CNF                           ((MSF_MODID_BAM << 8) + 0x0e)
#define BAM_SIG_GET_SAVED_PAGE_REQ                      ((MSF_MODID_BAM << 8) + 0x0f)
#define BAM_SIG_LOAD_SAVED_PAGE_REQ                     ((MSF_MODID_BAM << 8) + 0x10)
#define BAM_SIG_DELETE_SAVED_PAGE_REQ                   ((MSF_MODID_BAM << 8) + 0x11)
#define BAM_SIG_DELETE_ALL_SAVED_PAGES_REQ              ((MSF_MODID_BAM << 8) + 0x12)
#if 0
/* under construction !*/
#endif
#define BAM_SIG_GET_SAVED_PAGES_LIST_START_REQ          ((MSF_MODID_BAM << 8) + 0x14)
#define BAM_SIG_GET_SAVED_PAGES_LIST_START_CNF          ((MSF_MODID_BAM << 8) + 0x15)
#define BAM_SIG_GET_SAVED_PAGES_LIST_CONTINUE_REQ       ((MSF_MODID_BAM << 8) + 0x16)
#define BAM_SIG_GET_SAVED_PAGES_LIST_CONTINUE_CNF       ((MSF_MODID_BAM << 8) + 0x17)
#define BAM_SIG_GET_SAVED_PAGES_LIST_END_REQ            ((MSF_MODID_BAM << 8) + 0x18)
#endif
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#define BAM_SIG_STATUS_IND                              ((MSF_MODID_BAM << 8) + 0x22)
#define BAM_SIG_ERROR_IND                               ((MSF_MODID_BAM << 8) + 0x23)
#define BAM_SIG_DOCUMENT_INFO_IND                       ((MSF_MODID_BAM << 8) + 0x24)
#ifndef BAM_CFG_BRW_DISPLAY_INLINE_DO
#define BAM_SIG_DO_ELEMENTS_IND                         ((MSF_MODID_BAM << 8) + 0x25)
#endif
#define BAM_SIG_ELEMENT_FOCUSED_IND                     ((MSF_MODID_BAM << 8) + 0x26)
#define BAM_SIG_SET_SEC_CLASS_IND                       ((MSF_MODID_BAM << 8) + 0x27)
//#ifdef MSF_CFG_9W_MODE_KBRD_SIMULATION
#define BAM_SIG_CHANGE_SETTING_VALUE_REQ                ((MSF_MODID_BAM << 8) + 0x28)
//#endif
#define BAM_SIG_SET_PROFILE_REQ                         ((MSF_MODID_BAM << 8) + 0x29)
#define BAM_SIG_SET_PROFILE_CNF                         ((MSF_MODID_BAM << 8) + 0x2a)
#define BAM_SIG_GET_RECENT_PAGES_LIST_START_REQ         ((MSF_MODID_BAM << 8) + 0x2b)
#define BAM_SIG_GET_RECENT_PAGES_LIST_START_CNF         ((MSF_MODID_BAM << 8) + 0x2c)
#define BAM_SIG_GET_RECENT_PAGES_LIST_CONTINUE_REQ      ((MSF_MODID_BAM << 8) + 0x2d)
#define BAM_SIG_GET_RECENT_PAGES_LIST_CONTINUE_CNF      ((MSF_MODID_BAM << 8) + 0x2e)
#define BAM_SIG_GET_RECENT_PAGES_LIST_END_REQ           ((MSF_MODID_BAM << 8) + 0x2f)
#define BAM_SIG_GET_RECENT_PAGE_REQ                     ((MSF_MODID_BAM << 8) + 0x30)
#define BAM_SIG_LOAD_RECENT_PAGE_REQ                    ((MSF_MODID_BAM << 8) + 0x31)
#define BAM_SIG_DELETE_RECENT_PAGE_REQ                  ((MSF_MODID_BAM << 8) + 0x32)
#define BAM_SIG_DELETE_ALL_RECENT_PAGES_REQ             ((MSF_MODID_BAM << 8) + 0x33)
#define BAM_SIG_RECENT_PAGE_CNF                         ((MSF_MODID_BAM << 8) + 0x34)
#ifdef BAM_CFG_RECENT_PAGES_SUPPORT
#define BAM_SIG_WTAI_TEL_IND                            ((MSF_MODID_BAM << 8) + 0x35)
#define BAM_SIG_WTAI_TEL_RSP                            ((MSF_MODID_BAM << 8) + 0x36)
#define BAM_SIG_WTAI_PB_IND                             ((MSF_MODID_BAM << 8) + 0x37)
#define BAM_SIG_WTAI_PB_RSP                             ((MSF_MODID_BAM << 8) + 0x38)
#endif
#define BAM_SIG_URI_REQUEST_IND                         ((MSF_MODID_BAM << 8) + 0x39)
#define BAM_SIG_URI_REQUEST_RSP                         ((MSF_MODID_BAM << 8) + 0x3a)
#define BAM_SIG_BEARER_INFO_IND                         ((MSF_MODID_BAM << 8) + 0x3b)
#define BAM_SIG_REGISTER_KEYPAD_HANDLER_REQ             ((MSF_MODID_BAM << 8) + 0x3c)
#ifdef __MMI_TOUCH_SCREEN__
#if 0
/* under construction !*/
#endif
#endif
#if 0
/* under construction !*/
/* under construction !*/
#endif
#define BAM_SIG_NOTIFY_SCREEN_INFO_REQ                  ((MSF_MODID_BAM << 8) + 0x40)
#define BAM_SIG_WAIT_USER_ACTION_IND                    ((MSF_MODID_BAM << 8) + 0x41)
#define BAM_SIG_WAIT_USER_ACTION_RSP                    ((MSF_MODID_BAM << 8) + 0x42)
#define BAM_SIG_OBJECT_ACTION_REQ                       ((MSF_MODID_BAM << 8) + 0x43)
#define BAM_SIG_SHOW_AUTH_DIALOG_RSP					((MSF_MODID_BAM << 8) + 0x44)
#ifdef MSF_CFG_FILE_UPLOAD_SUPPORT
#define BAM_SIG_SELECT_FILE_RSP                         ((MSF_MODID_BAM << 8) + 0x45)
#endif
#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
#define BAM_SIG_DELETE_OFFLINE_PAGE_RESPONSE            ((MSF_MODID_BAM << 8) + 0x46)
#endif
#define BAM_SIG_EM_SETTING_CHANGED_IND                  ((MSF_MODID_BAM << 8) + 0x47)
#define BAM_SIG_CHANNEL_CONFIG_NOTIFY_IND               ((MSF_MODID_BAM << 8) + 0x48)
#define BAM_SIG_CLOSE_CONNECTION_BY_NETID               ((MSF_MODID_BAM << 8) + 0x49)
#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
#define BAM_SIG_DELETE_N_SAVED_PAGE_REQ                 ((MSF_MODID_BAM << 8) + 0x4a)
#endif
#ifdef BAM_CFG_RECENT_PAGES_SUPPORT
#define BAM_SIG_DELETE_N_RECENT_PAGE_REQ                ((MSF_MODID_BAM << 8) + 0x4b)
#endif 
#ifdef MSF_CFG_BRW_WMLS_NON_WIDGET_DLG_SUPPORT
#define BAM_SIG_WMLS_CREATE_DIALOGUE_RSP                ((MSF_MODID_BAM << 8) + 0x4c)
#endif
#define BAM_SIG_BEARER_OPEN_RSP                         ((MSF_MODID_BAM << 8) + 0x4d)

/**********************************************************************
 * Constants
 **********************************************************************/

#define BAM_BRINFO_CSD_TIMEOUT  0
#define BAM_BRINFO_CSD_DISC     1

#define BAM_MAX_PEER_BUFFER_SIZE      1024

#ifdef MSF_CFG_BRW_WMLS_NON_WIDGET_DLG_SUPPORT
#define BAM_MAX_WMLS_MSG_LEN  40
#endif

#define BAM_MAX_TITLE_LABEL_LEN  40     /* Max number of characters allowed
                                           for a title or label. */
#define BAM_MAX_SCHEME_LEN   40 /* Max number of characters allowed
                                   for a scheme. */
#ifndef BAM_CFG_BRW_DISPLAY_INLINE_DO
#define BAM_MAX_DO_ELEMENTS_NUM 20      /* Max number of DO elements in a WML
                                           page. */
#endif

#define BAM_MAX_USER_PASSWD_LEN  127    /* Max number of characters allowed
                                           for a username or password. */
#define BAM_MAX_PHONE_NUMBER_LEN 127
#define BAM_MAX_REALM_LEN    255        /* Max number of characters allowed
                                           for a realm. */
#define BAM_MAX_URL_LEN 512
#define BAM_MAX_MIME_TYPE_LEN   255
#define BAM_MAX_FILE_PATH_LEN   255
#define BAM_MAX_SETTING_STR_VALUE_LEN   300

#define BAM_DOCTYPE_WML 1
#define BAM_DOCTYPE_XHTML   2
#define BAM_DOCTYPE_HTML    3
#define BAM_DOCTYPE_HTML_Q1 4
#define BAM_DOCTYPE_HTML_Q2 5
#define BAM_DOCTYPE_PUSH_SI 8
#define BAM_DOCTYPE_PUSH_SL 9
#define BAM_DOCTYPE_PUSH_CO 10
#define BAM_DOCTYPE_UNKNOWN 11

/*
 * Navigation Constants
 * Sent in message MSG_ID_WAP_BAM_MOVE_REQ to indicate the direction to take
 * in the history of visited pages.
 */
#define BAM_MOVE_BACKWARD   1
#define BAM_MOVE_FORWARD    2
#define BAM_MOVE_RELOAD 3

/* Recent-Page sorting-option constants
   Used in the message MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_START_REQ. */
#define BAM_RECENT_PAGE_SORT_OPTION_DATE    0
#define BAM_RECENT_PAGE_SORT_OPTION_HOST    1
#define BAM_RECENT_PAGE_SORT_OPTION_LAST    2
#define BAM_RECENT_PAGE_SORT_OPTION_FREQ    3

/* WTAI Telephony Operation Constants
   Sent in message MSG_ID_WAP_BAM_WTAI_TEL_IND to indicate the requested
   telephony operation. */
#define BAM_WTAI_TEL_MAKE_CALL  0
#define BAM_WTAI_TEL_SEND_DTMF  1

/*
 * Load URL Flags
 * Sent in function BRSif_loadUrl.
 */
/* Do not use the cached version of the reloaded page, if there is any. */
#define BAM_OPTION_NO_CACHE 0x01
/* If the page is not stored in cache when navigating in history, ask for
   user confirmation whether to reload page or not. */
#define BAM_OPTION_CACHE_NOTIFICATION   0x02
/* Primary purpose for this option is usage from script. (ESMP)
   When script execution causes navigation this option is used to
   prevent triggering of unwanted load events if the navigation
   turns out to be within the same page.
   Not to be used other than by the script engine. */
#define BAM_OPTION_FROM_SCRIPT  0x04
/* The loaded page will replace the current history element. */
#define BAM_OPTION_REPLACE  0x08
/* Usually, the loading of a URL via MSG_ID_WAP_BAM_LOAD_URL_REQ entails
   creating a new WML context. This means resetting all WML variables, and
   possibly removing the current history (if BRS_CFG_CLEAR_HISTORY_ON_NEWCONTEXT
   is defined).
   To prevent this from happening, this option may be set in the call
   to MSG_ID_WAP_BAM_LOAD_URL_REQ. */
#define BAM_OPTION_KEEP_WML_CONTEXT 0x10
/* Setting this option will cause the BRS to remove all earlier entries
   in the navigation history, regardless of how BRS_CFG_CLEAR_HISTORY_ON_NEWCONTEXT
   is defined. This option can also be combined with BAM_OPTION_KEEP_WML_CONTEXT,
   to get the effect of clearing the history while keeping the WML context. */
#define BAM_OPTION_CLEAR_HISTORY    0x20

/* Info Flags
   Flag values used in the response signal MSG_ID_WAP_BAM_DOCUMENT_INFO_IND. */

/* Indicates that back-navigation is possible. */
#define BAM_INFO_FLAG_ENABLE_BACK   0x01
/* Indicates that forward-navigation is possible. */
#define BAM_INFO_FLAG_ENABLE_FORWARD    0x02
/* Indicates that the document is loaded from cache and new,
   that is, not previously in the history. */
#define BAM_INFO_FLAG_NEW_PAGE  0x04
/* Indicates that the document has just been added to the history. */
#define BAM_INFO_FLAG_NEW_PAGE_IN_HISTORY   0x08
/* The document was loaded from the offline store. */
#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
#define BAM_INFO_FLAG_SAVED_PAGE    0x10
#endif
/* The document was loaded in the main window (and not in a subframe, for example). */
#define BAM_INFO_FLAG_MAIN_WINDOW   0x20
/* The navigation is local (within the current page). */
#define BAM_INFO_FLAG_LOCAL_NAVIGATION  0x40

/*
 * Selectable Element Types
 * When the user is viewing a page, some elements of that page may be selected.
 * A typical example of a selectable element is an anchor for navigating to another page. The
 * constants used in this signalling between Browser Engine and the application is defined in this section.
 * When viewing a page Browser Engine will send the message MSG_ID_WAP_BAM_ELEMENT_FOCUSED_IND with the type
 * of element currently focused using one of the flags in "Info Flags". The application can use the constants
 * in (Focusable Elements) in the message MSG_ID_WAP_BAM_NAVIGATION_CHANGE_REQ to tell Browser Engin which
 * elements that are focusable by combining them in an or-operation. If no such mesage is sent there is a
 * default setting, BAM_FOCUSABLE_ELEMENTS_NORMAL_MODE, that is used and which means that all types except
 * simple objects are focusable.
 * The application will typically use the information from MSG_ID_WAP_BAM_ELEMENT_FOCUSED_IND to know which
 * menus to display when the user focuses the various element-types. E.g. a focused image might
 * depending on configurations made cause menus for tasks like "send as MMS" or
 * "save in my pictures" or both.
 */

/** No element in focus. */
#define BAM_FOCUSED_ELEMENT_NONE                  0
/** <a> and <anchor> */
#define BAM_FOCUSED_ELEMENT_LINK                  1
/** <do>, do elements (WML access key), if rendered in content */
#define BAM_FOCUSED_ELEMENT_DO                    2
/** <textarea> and <input type="text"> */
#define BAM_FOCUSED_ELEMENT_TEXTINPUT             3
/** <select>, WML and HTML selectable options (in select list) */
#define BAM_FOCUSED_ELEMENT_SELECT                4
/** <img>, <object> and <bgsound>. */
#define BAM_FOCUSED_ELEMENT_IMAGE                 5
/** <input type="image"> */
#define BAM_FOCUSED_ELEMENT_INPUT                 6
/** <button> and <input type="button" */
#define BAM_FOCUSED_ELEMENT_BUTTON                7
/** <input type=?submit? */
#define BAM_FOCUSED_ELEMENT_SUBMIT                8
/** <input type=?reset? */
#define BAM_FOCUSED_ELEMENT_RESET                 9
/** <input type=?file? */
#define BAM_FOCUSED_ELEMENT_FILE_INPUT            10
/** <input type="checkbox", "radio"> depening on whether they are checked or not. */
#define BAM_FOCUSED_ELEMENT_INPUT_SELECTED        11
/** <input type="checkbox", "radio"> unchecked. */
#define BAM_FOCUSED_ELEMENT_INPUT_UNSELECTED      12
/** <area>, HTML image map area definition. */
#define BAM_FOCUSED_ELEMENT_AREA                  13
/** A frame or iframe element. */
#define BAM_FOCUSED_ELEMENT_FRAME                 14
/** <label>, HTML label used for some kinds of controls.
 * Both the label and its target will have :focus set at
 * the same time, but the label is the one considered as focused. */
#define BAM_FOCUSED_ELEMENT_LABEL                 15

/* Focusable Elements
   These constants are used in MSG_ID_WAP_BAM_NAVIGATION_CHANGE_REQ. */

/* This class typically includes elements a, anchor and inlined-do. */
#define BAM_FOCUSABLE_ELEMENTS_LINKS    0x0001
/* This typically includes elements such as input, label, select, textarea and option. */
#define BAM_FOCUSABLE_ELEMENTS_FORM_ELEMENTS    0x0002
/* The label element. */
#define BAM_FOCUSABLE_ELEMENTS_LABEL_ELEMENTS   0x0004
/* Simple resources are those that are handled by the browser, such as a gif image or
   a sound that plays using direct HDIa_ calls. This is typically the element img and
   possibly object. */
#define BAM_FOCUSABLE_ELEMENTS_SIMPLE_OBJECT    0x0008
/* An external resource is sent on content routing and may have its own menue system
   in the recieving module, and should thus sometimes be focusable in "normal navigation mode".
   This is also the img and object elements. */
#define BAM_FOCUSABLE_ELEMENTS_EXTERNAL_RESOURCE    0x0010
/* Image maps hold area elements that can be applied on top of images. */
#define BAM_FOCUSABLE_ELEMENTS_AREA 0x0020
/* Frames are a high level type of that each hold a document. */
#define BAM_FOCUSABLE_ELEMENTS_FRAME    0x0040
/* A selection of the above typically used for the normal navigation mode. */
#define BAM_FOCUSABLE_ELEMENTS_NORMAL_MODE (BAM_FOCUSABLE_ELEMENTS_LINKS              | \
    BAM_FOCUSABLE_ELEMENTS_FORM_ELEMENTS      |                                         \
    BAM_FOCUSABLE_ELEMENTS_EXTERNAL_RESOURCE  |                                         \
    BAM_FOCUSABLE_ELEMENTS_AREA               |                                         \
    BAM_FOCUSABLE_ELEMENTS_FRAME)
/* A selection of the above typically used for the object(image) navigation mode. */
#define BAM_FOCUSABLE_ELEMENTS_OBJECT_MODE (BAM_FOCUSABLE_ELEMENTS_SIMPLE_OBJECT | \
    BAM_FOCUSABLE_ELEMENTS_FRAME)
#define BAM_FOCUSABLE_ELEMENTS_ALL_MODE    (BAM_FOCUSABLE_ELEMENTS_LINKS              | \
    BAM_FOCUSABLE_ELEMENTS_FORM_ELEMENTS      |                                         \
    BAM_FOCUSABLE_ELEMENTS_EXTERNAL_RESOURCE  |                                         \
    BAM_FOCUSABLE_ELEMENTS_AREA               |                                         \
    BAM_FOCUSABLE_ELEMENTS_FRAME              |                                         \
    BAM_FOCUSABLE_ELEMENTS_SIMPLE_OBJECT)

/* Protocol types */
#define BAM_PROTOCOL_WSP_CL 1
#define BAM_PROTOCOL_WSP_CL_WTLS    2
#define BAM_PROTOCOL_WSP_CO 3
#define BAM_PROTOCOL_WSP_CO_WTLS    4
#define BAM_PROTOCOL_HTTP   5
#define BAM_PROTOCOL_HTTP_TLS   6
#define BAM_PROTOCOL_HTTP_SSL   7
#define BAM_PROTOCOL_CACHE  8
#define BAM_PROTOCOL_MULTIPART  9
#define BAM_PROTOCOL_FILE   10
#define BAM_PROTOCOL_OTHER  11

/* Transaction Status Codes
   Transaction status codes used for status signalling during transactions. */

/* Sent when a transaction starts. That is, when a user selects a link, when the
   application sends LOAD_URL, LOAD_DATA, MOVE or RELOAD, or when a timer expires and starts
   a new transaction. */
#define BAM_STATUS_START_TRANSACTION    1
/* Sent when the transaction is finished, either normally or for instance when
   the application sent STOP. */
#define BAM_STATUS_END_TRANSACTION  2
/* Status update signal. The status update interval is configurable by the
   trastatus_sig setting key. */
#define BAM_STATUS_TRANSACTION_STATUS   3
/* Sent when a transaction starts for external object. That is, when a user selects a RTSP link, 
   it will establihs RTSP connection and trigger a new transaction. */
#define BAM_STATUS_EXTERNAL_OBJECT_START_TRANSACTION	4
/* Sent when the transaction for external object is finished. */
#define BAM_STATUS_EXTERNAL_OBJECT_END_TRANSACTION		5

/* Authorization Type Constants */
#define BAM_AUTH_TYPE_SERVER    1
#define BAM_AUTH_TYPE_PROXY 2

/* Authorization Option Constants */
#define BAM_AUTH_OPTIONS_CANCEL     0x00
#define BAM_AUTH_OPTIONS_SAVE_NOTHING   0x01
#define BAM_AUTH_OPTIONS_SAVE_USERNAME_AND_PASSWORD 0x02
#define BAM_AUTH_OPTIONS_SAVE_USERNAME  0x03

/* General Error Codes */

/* Successful opeartion or result */
#define BAM_ERROR_OK    0

/* Create Instance Error Codes
   Error codes used for instance creation. */

/* Browser Engine is terminating */
#define BAM_ERROR_TERMINATING   1

/* Input Error Codes
   Error codes used for input errors. */

/* Some input parameter in a connector function call has an invalid value.  */
#define BAM_ERROR_INVALID_INPUT 14
/* Malformed URL was encountered. */
#define BAM_ERROR_INVALID_URL   15
/* An input URL contained a scheme not supported by BRS or any registered plug-in. */
#define BAM_ERROR_INVALID_SCHEME    16

/* Parser Error Codes
   Parser error codes. For more information, see msf_prsr.h. */

/* The document uses an unsupported character set or encoding. */
#define BAM_ERROR_UNKNOWN_CHARSET   21
/* The content contains a syntax error or violates
   another rule in an underlying content specification,
   such as WBXML or XML. (For example WML is an application of XML)
   Can also be sent when the application rejects the document,
   for instance on a validation error. */
#define BAM_ERROR_SYNTAX    22
/* A document type was specified but unknown and no content
   type associated with a known document type was given. */
#define BAM_ERROR_UNKNOWN_DOCTYPE   23
/* The document uses an unsupported version of WBXML. */
#define BAM_ERROR_UNSUPPORTED_WBXML 24
/* Document is not valid; for example contains an element used in the wrong context. */
#define BAM_ERROR_VALIDATION    25
/* The Parser or one of its resources is not initialised or not available. */
#define BAM_ERROR_ABORTED   26
/* HTML warning: This is a frameset document without a noframes element as alternative content. */
#define BAM_ERROR_REQUIRE_FRAMES    27

/* WMLScript Error Codes
   'WMLS' errors, i.e., error in WMLScript */

/* Error while interpreting a WML Script file. */
#define BAM_ERROR_WMLS      30
/* The verification of a WMLScript file failed. */
#define BAM_ERROR_WMLS_VERIFICATION 31
/* Error when executing a WMLScript library function. */
#define BAM_ERROR_WMLS_LIB  32
/* A WMLScript function was called with the wrong number of arguments. */
#define BAM_ERROR_WMLS_FUNC_ARGS    33
/* A WMLScript function called an unknown (external) function. */
#define BAM_ERROR_WMLS_EXTERNAL 34
/* Error in specification of an external WMLScript function, loading failed. */
#define BAM_ERROR_WMLS_LOAD 35
/* Incorrect WMLS byte code, interpreter failed. */
#define BAM_ERROR_WMLS_INTERPRETING 36
/* A WMLScript function has been aborted. */
#define BAM_ERROR_WMLS_ABORT    37
/* A WMLScript function has exited. */
#define BAM_ERROR_WMLS_EXIT 38

/* WML Access Restrictions Error Codes
   Access restrictions on WML or WMLScript */

/* WML access violation. */
#define BAM_ERROR_ACCESS_RESTRICTIONS_WML   40
/* WMLScript access violation. */
#define BAM_ERROR_ACCESS_RESTRICTIONS_WMLS  41

/* Communication Error Codes
   Communication errors. */

/* There was an error in the communication; for example,
   a host could not be found or a connection timed out.
   The request is aborted. */
#define BAM_ERROR_COMMUNICATION 50
/* No address could be found during the DNS lookup. The request is aborted. */
#define BAM_ERROR_HOST_NOT_FOUND    51
/* A timer expired before a response arrived. The request is aborted. */
#define BAM_ERROR_REQUEST_TIMED_OUT 52
/* A connection was closed or socket setup failed. The request is aborted. */
#define BAM_ERROR_CONNECTION_FAILED 53
/* A secure connection failed. The request is aborted. */
#define BAM_ERROR_SECURE_CONNECTION_FAILED  54
/* Authentication failed. The request is aborted. */
#define BAM_ERROR_AUTHENTICATION    55
/* A secure connection was cancelled. The request is aborted. */
#define BAM_ERROR_SECURE_CONNECTION_CANCELLED   56
/** No start part available in Multipart/Mixed message */
#define BAM_ERROR_PAGE_NOT_FOUND                57
/** Authentication cancelled. The request is aborted. */
#define BAM_ERROR_AUTHENTICATION_CANCELLED      58
/** Total file size is too large and could not be sent throught WSP connection. The request is aborted. */
#define WAP_BAM_ERROR_FILE_SIZE_TOO_LARGE       59

/* JavaScript Error Codes
   JavaScript errors.
   NB must be consecutive and correlate with corresponding MSF errors. */

/* No actual error code, used as start value for all JavaScript errors */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* Miscellaneous Error Codes
   Misc. */

/* An internal error in the BRS, usually due to a programming error or
   because some internal limit has been reached. */
#define BAM_ERROR_INTERNAL                        70
/* The user has moved to a page in the history that was originally
   fetched using a POST request (from a non-WML page), and the page is
   no longer in the cache.
   However, resending the POST request might have undesired side effects.
   Hence, the browser will show an empty page, and issue this error code.
   An explicit reload is needed to resend the POST request. */
#define BAM_ERROR_RESEND_POST_WARNING             71
/* The BRS module has run out of memory, for details see BRS_CFG_MEMORY_LIMIT */
#define BAM_ERROR_LOW_MEMORY                      72
/* The page was too big and could not be loaded. The request is aborted. */
#define BAM_ERROR_CONTENT_TOO_LARGE               73
/* An internal error occurs while setting the profile to Obigo framework. */
#define BAM_ERROR_SET_PROFILE                     74
/* The whole BrowserEngine has run out of memory */
#define BAM_ERROR_OUT_OF_MEMORY                   75
/* The CSD bearer is disconnected due to long idle timeout */
#define BAM_ERROR_LONG_IDLE_TIMEOUT               76

#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
/* Saved Pages Error Codes
   Error messages used in response to the requests of Saved Pages functionality. */

/* A request on a saved page (load, delete, rename) could not be completed,
   because a page with the specified label could not be found. */
#define BAM_ERROR_SAVED_PAGES_NOT_FOUND           80
/* A request to save the current page failed, because a page with the same
   label is stored already, and the parameter 'overwrite' was FALSE. */
#define BAM_ERROR_SAVED_PAGES_EXISTS              81
/* A request to the saved pages facilities failed, for some unspecified reason. */
#define BAM_ERROR_SAVED_PAGES_FAILED              82
/* A request to save the current page succeeded, but not all the resource
   files (images, for example) could be stored. */
#define BAM_ERROR_SAVED_PAGES_PARTIAL             83
/* A request to save the current page failed, because some predefined resource
   limit was exceeded (for example, the maximum number of saved pages). */
#define BAM_ERROR_SAVED_PAGES_LIMIT_EXCEEDED      84

#endif
/* Recent Pages Error Codes
   Error messages used in response to the requests of Recent Pages
   functionality. */

/* A request on a recent page (load, delete) could not be completed,
   because a page with the specified index could not be found. */
#define BAM_ERROR_RECENT_PAGES_NOT_FOUND    90
/* A request to the recent pages facilities failed, for some unspecified
   reason. */
#define BAM_ERROR_RECENT_PAGES_FAILED   91

/* Plug-in Error Codes
   Error messages used in response to the requests of WTAI and URI Scheme
   functionality. */

/* A successful operation. */
#define BAM_WTAI_RESULT_OK              0x0
/*
 * For a WTAI Telephony operation:
 * (1) BAM_WTAI_TEL_MAKE_CALL:
 * The number parameter is not a phone-number.
 * (2) BAM_WTAI_TEL_SEND_DTMF:
 * The dtmf parameter is not a DTMF sequence.
 * For a WTAI Phone Book operation:
 * The number parameter is not a phone-number.
 */
#define BAM_WTAI_RESULT_INVALID     0x01
/* The called party is busy. */
#define BAM_WTAI_RESULT_TEL_CALLED_PARTY_IS_BUSY    0x11
/* The network is not available. */
#define BAM_WTAI_RESULT_TEL_NETWORK_NOT_AVAILABLE   0x12
/* The called party did not answer. */
#define BAM_WTAI_RESULT_TEL_CALLED_PARTY_NO_ANSWER  0x13
/* No active voice connection. */
#define BAM_WTAI_RESULT_TEL_NO_ACTIVE_CONNECTION    0x14
/* The name parameter is unacceptable or too long. */
#define BAM_WTAI_RESULT_PB_IN_NAME  0x21
/* The number parameter is too long. */
#define BAM_WTAI_RESULT_PB_NUMBER_TO_LONG   0x22
/* The phonebook entry could not be written. */
#define BAM_WTAI_RESULT_PB_PHONE_BOOK_ENTRY 0x23
/* The phonebook is full. */
#define BAM_WTAI_RESULT_PB_PHONE_BOOK_IS_FULL   0x24
/* Unspecified error. */
#define BAM_WTAI_RESULT_UNSPECIFIED 0xFF

/***************************************
 * Browser-related Setting IDs
 ***************************************/

typedef enum
{
    BAM_SETTING_VALUE_TYPE_INT,
    BAM_SETTING_VALUE_TYPE_STR
} bam_setting_value_type_enum;

typedef enum
{
	BAM_SET_PROFILE_TO_BRS,
    BAM_DO_NOT_SETPROFILE_TO_BRS
}bam_set_profile_option_enum;

typedef enum
{
    /* APP */
    BAM_SETTING_ID_IMAGES,      /* BAM_SETTING_VALUE_TYPE_INT */
    BAM_SETTING_ID_MOVIES,      /* BAM_SETTING_VALUE_TYPE_INT */
    BAM_SETTING_ID_SOUNDS,      /* BAM_SETTING_VALUE_TYPE_INT */
    BAM_SETTING_ID_HISTORY,     /* BAM_SETTING_VALUE_TYPE_INT */
    BAM_SETTING_ID_HOMEPAGE,    /* BAM_SETTING_VALUE_TYPE_STR */
    BAM_SETTING_ID_SHORTCUTS,   /* BAM_SETTING_VALUE_TYPE_INT */

    /* BRS */
    BAM_SETTING_ID_RENDERING,       /* BAM_SETTING_VALUE_TYPE_INT */
    BAM_SETTING_ID_THUMBNAIL,       /* BAM_SETTING_VALUE_TYPE_INT */
    BAM_SETTING_ID_REFRESH,         /* BAM_SETTING_VALUE_TYPE_INT */
    BAM_SETTING_ID_CSS,             /* BAM_SETTING_VALUE_TYPE_INT */
    BAM_SETTING_ID_SCRIPT,          /* BAM_SETTING_VALUE_TYPE_INT */
    BAM_SETTING_ID_CACHE,           /* BAM_SETTING_VALUE_TYPE_INT */
    BAM_SETTING_ID_SEC_WARNING,     /* BAM_SETTING_VALUE_TYPE_INT */
    BAM_SETTING_ID_IMEI,            /* BAM_SETTING_VALUE_TYPE_INT */
    BAM_SETTING_ID_NO_MIME,         /* BAM_SETTING_VALUE_TYPE_INT */
    BAM_SETTING_ID_ZOOM,            /* BAM_SETTING_VALUE_TYPE_INT */
/* #ifdef MTK_TMP_PATCH of CR36621 */
    BAM_SETTING_ID_FONT_SIZE,            /* BAM_SETTING_VALUE_TYPE_INT */
/* #endif */
    BAM_SETTING_ID_NAVIGATION,      /* BAM_SETTING_VALUE_TYPE_INT */
    BAM_SETTING_ID_FRAME_LAYOUT,    /* BAM_SETTING_VALUE_TYPE_INT */
    BAM_SETTING_ID_BRS_HOMEPAGE,    /* BAM_SETTING_VALUE_TYPE_STR */

    /* STK */
    BAM_SETTING_ID_COOKIES, /* BAM_SETTING_VALUE_TYPE_INT */

    /* Connection, if no CPS */
    BAM_SETTING_ID_CON_ACCOUNT,     /* BAM_SETTING_VALUE_TYPE_INT */
    BAM_SETTING_ID_CON_TYPE,        /* BAM_SETTING_VALUE_TYPE_INT */
    BAM_SETTING_ID_CON_ADDR_TYPE,   /* BAM_SETTING_VALUE_TYPE_INT */
    BAM_SETTING_ID_CON_ADDR,        /* BAM_SETTING_VALUE_TYPE_STR */
    BAM_SETTING_ID_CON_PWD,         /* BAM_SETTING_VALUE_TYPE_STR */
    BAM_SETTING_ID_CON_PORT,        /* BAM_SETTING_VALUE_TYPE_INT */
    BAM_SETTING_ID_CON_REALM,       /* BAM_SETTING_VALUE_TYPE_STR */
    BAM_SETTING_ID_CON_SEC_PORT,    /* BAM_SETTING_VALUE_TYPE_INT */
    BAM_SETTING_ID_CON_USER,        /* BAM_SETTING_VALUE_TYPE_STR */
    BAM_SETTING_ID_CON_TIMEOUT,     /* BAM_SETTING_VALUE_TYPE_INT */
    BAM_SETTING_ID_9WAY,            /* BAM_SETTING_VALUE_TYPE_INT */
    BAM_SETTING_ID_ADD_HISTORY,     /* BAM_SETTING_VALUE_TYPE_INT */
	BAM_SETTING_ID_TRANSCODE_PROXY,      /* BAM_SETTING_VALUE_TYPE_INT */


    /* End of setting id */
    BAM_SETTING_ID_TOTAL
} bam_setting_id_enum;

/***************************************
 * Browser-related Setting Values
 ***************************************/
#define BAM_SETTING_INT_INIT_VAL    (-1)
#define BAM_SETTING_STR_INIT_VAL    (NULL)

/* BAM_SETTING_ID_IMAGES */

enum
{
    bam_setting_val_always,
    bam_setting_val_ask,
    bam_setting_val_never
};


/* BAM_SETTING_ID_HISTORY */
enum
{
    bam_setting_val_history_no = 0
};

/* BAM_SETTING_ID_HOMEPAGE */

/* BAM_SETTING_ID_RENDERING */
/* Sync with Rendering preference in Browser Engine */
enum
{
    bam_setting_val_rend_normal,
    bam_setting_val_rend_narrow,
    bam_setting_val_rend_wrap,
    bam_setting_val_rend_text
};

/* BAM_SETTING_ID_THUMBNAIL */
enum
{
    bam_setting_val_disable,
    bam_setting_val_enable
};


/* BAM_SETTING_ID_SEC_WARNING */
/* Sync with Scheme transition preferences in Browser Engine */
enum
{
    bam_setting_val_sec_warning_disable = 0,

    /* BRS_PREFERENCE_VALUE_HTTP_TO_HTTPS_TRANSITION_ASK | BRS_PREFERENCE_VALUE_HTTPS_TO_HTTP_TRANSITION_ASK */
    bam_setting_val_sec_warning_enable = 0x03
};

/* BAM_SETTING_ID_IMEI */
enum
{
    bam_setting_val_imei_disable,
    bam_setting_val_imei_enable
};


/* BAM_SETTING_ID_ZOOM */

/* BAM_SETTING_ID_NAVIGATION */
enum
{
    /* Sync with Navigation preference in Browser Engine */
    bam_setting_val_nav_scroll = 0x01,
    bam_setting_val_nav_2_way = 0x02,
    bam_setting_val_nav_4_way = 0x04,
    bam_setting_val_nav_textspot = 0x08
};

/* BAM_SETTING_ID_FRAME_LAYOUT */
/* BAM_SETTING_ID_BRS_HOMEPAGE */

/* BAM_SETTING_ID_COOKIES */
enum
{
    bam_setting_val_cookies_disable,
    bam_setting_val_cookies_enable
};

/* BAM_SETTING_ID_CON_TYPE */
enum
{
    bam_setting_val_conn_type_http = 1,                     /* BRW_PROF_CONN_TYPE_HTTP */
    bam_setting_val_conn_type_connection_oreinted,          /* BRW_PROF_CONN_TYPE_CONNECTION_OREINTED */
    bam_setting_val_conn_type_connection_oreinted_secure    /* BRW_PROF_CONN_TYPE_CONNECTION_OREINTED_SECURE */
};

/* BAM_SETTING_ID_CON_ADDR_TYPE */
enum
{
    bam_setting_val_conn_addr_type_ipv4 = 0,
    bam_setting_val_conn_addr_type_alpha
};

/* BAM_SETTING_ID_CON_ACCOUNT */
/* BAM_SETTING_ID_CON_ADDR */
/* BAM_SETTING_ID_CON_PWD */
/* BAM_SETTING_ID_CON_PORT */
/* BAM_SETTING_ID_CON_REALM */
/* BAM_SETTING_ID_CON_SEC_PORT */
/* BAM_SETTING_ID_CON_USER */
/* BAM_SETTING_ID_CON_TIMEOUT */

/* Resource types */
#define BAM_RSRC_TYPE_IMAGE        0x01
#define BAM_RSRC_TYPE_BACKGROUND   0x02
#define BAM_RSRC_TYPE_SOUND        0x04
#define BAM_RSRC_TYPE_OTHER        0x08

/**********************************************************************
 * Signal parameters
 **********************************************************************/

/* BAM_SIG_CREATE_INSTANCE_REQ */

typedef struct
{
    MSF_BOOL is_full_screen;
    MSF_INT32 window_position_x;
    MSF_INT32 window_position_y;
    MSF_INT32 window_size_height;
    MSF_INT32 window_size_width;
    MSF_INT32 category_lyr_a_hndl;
    MSF_INT32 category_lyr_b_hndl;
} bam_create_instance_req_struct;

/* BAM_SIG_CREATE_INSTANCE_CNF */
typedef struct
{
    MSF_UINT16 instance_id;
    MSF_UINT16 error_code;
} bam_create_instance_cnf_struct;

/* BAM_SIG_DELETE_INSTANCE_REQ */
typedef struct
{
    MSF_INT32 instance_id;
} bam_delete_instance_req_struct;

/* BAM_SIG_DELETE_INSTANCE_CNF */
typedef struct
{
    MSF_INT32 instance_id;
} bam_delete_instance_cnf_struct;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/* BAM_SIG_LOAD_URL_REQ */
typedef struct
{
    MSF_INT32 instance_id;
    MSF_INT32 options;  /* Options to use for loading the URL, see Section
                           5.5 Load URL Flags. */
    MSF_INT32 charset;
    char *url;
} bam_load_url_req_struct;

/* BAM_SIG_LOAD_DATA_REQ */
typedef struct
{
    MSF_INT32 instance_id;
    MSF_INT32 options;  /* Options to use for loading the URL, see Section
                           5.5 Load URL Flags. */
    MSF_INT32 charset;
    /* The local file pah of the data content that should be loaded. */
    char *content_path;
} bam_load_data_req_struct;


#ifndef BAM_CFG_BRW_DISPLAY_INLINE_DO
/* BAM_SIG_ACTIVATE_DO_ELEMENT_REQ */
typedef struct
{
    MSF_INT32 instance_id;

    /* The id of the DO-element to activate. The same element_id as used in
       BAM_SIG_DO_ELEMENTS_IND. */
    MSF_INT32 element_id;
} bam_activate_do_element_req_struct;
#endif /* BAM_CFG_BRW_DISPLAY_INLINE_DO */


/* BAM_SIG_MOVE_REQ */
typedef struct
{
    MSF_INT32 instance_id;
    MSF_UINT8 direction;        /* The direction to move. Possible values are
                                   described in Section 5.2 Navigation Constants. */
    MSF_UINT8 steps;    /* The number of steps to move in the history. */
} bam_move_req_struct;

/* BAM_SIG_RELOAD_REQ */
typedef struct
{
    MSF_INT32 instance_id;
} bam_reload_req_struct;

/* BAM_SIG_STOP_REQ */
typedef struct
{
    MSF_INT32 instance_id;
} bam_stop_req_struct;

/* BAM_SIG_NAVIGATION_CHANGE_REQ */
typedef struct
{
    MSF_INT32 instance_id;
    MSF_INT16 elements; /* The element combination from Section 5.7
                           Focusable Elements. */
} bam_navigation_change_req_struct;

#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
/* BAM_SIG_SAVE_PAGE_REQ */
typedef struct
{
    MSF_INT32 instance_id;
    MSF_INT32 overwrite;        /* If TRUE this flag overwrites any existing page
                                   with the same label. */
    /* The label to use for the page being saved. */
    char *label;
    char *url;
} bam_save_page_req_struct;

/* BAM_SIG_SAVE_PAGE_CNF */
typedef struct
{
    MSF_UINT16 instance_id;
    MSF_UINT16 error_code;      /* The result of the save-page request. See Section
                                   5.17 Saved Pages Error Codes. */
} bam_save_page_cnf_struct;

/* Peer Buffer */
typedef struct
{
    MSF_UINT32 date;        /* The created date of the saved page. */
    MSF_UINT32 doc_size;    /* The document size of the saved page. */
    MSF_UINT32 data_size;   /* The total data size of the saved page. */

    /* The label of the saved page. */
    char label[BAM_MAX_TITLE_LABEL_LEN + 1];
    char url[BAM_MAX_URL_LEN + 1];  /* The URL of the saved page. */
} bam_saved_page_struct;

/* BAM_SIG_GET_SAVED_PAGE_REQ */
typedef struct
{
    MSF_INT32 instance_id;
    MSF_UINT32 index;   /* The index of the specified saved page. */
} bam_get_saved_page_req_struct;

/* BAM_SIG_LOAD_SAVED_PAGE_REQ */
typedef struct
{
    MSF_INT32 instance_id;
    MSF_UINT32 index;   /* The index of the save page to load. */
} bam_load_saved_page_req_struct;

/* BAM_SIG_DELETE_SAVED_PAGE_REQ */
typedef struct
{
    MSF_INT32 instance_id;
    MSF_UINT32 index;   /* The index of the save page to delete. */
} bam_delete_saved_page_req_struct;

/* BAM_SIG_DELETE_N_SAVED_PAGE_REQ */
typedef struct
{
    MSF_INT32 instance_id;
    MSF_UINT32 *index_array;   /* The index of the save page to delete. */
    MSF_UINT32 count;
} bam_delete_n_saved_page_req_struct;

/* BAM_SIG_DELETE_ALL_SAVED_PAGES_REQ */
typedef struct
{
    MSF_INT32 instance_id;
} bam_delete_all_saved_pages_req_struct;






#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/* BAM_SIG_GET_SAVED_PAGES_LIST_START_REQ */
typedef struct
{
    MSF_INT32 instance_id;
} bam_get_saved_pages_list_start_req_struct;

/* BAM_SIG_GET_SAVED_PAGES_LIST_START_CNF */
typedef struct
{
    MSF_UINT16 instance_id;
    MSF_UINT16 error_code;      /* The result of the save-page request. See Section
                                   5.17 Saved Pages Error Codes. */
    MSF_UINT32 num_items;   /* The number of the saved pages. */
} bam_get_saved_pages_list_start_cnf_struct;

/* BAM_SIG_GET_SAVED_PAGES_LIST_CONTINUE_REQ */
typedef struct
{
    MSF_INT32 instance_id;
    MSF_UINT32 start_index; /* The index of the save page. */
} bam_get_saved_pages_list_continue_req_struct;

/* BAM_SIG_GET_SAVED_PAGES_LIST_CONTINUE_CNF */
typedef struct
{
    MSF_UINT16 instance_id;
    MSF_UINT16 error_code;
    MSF_UINT32 start_index;
    MSF_UINT32 num_items;
} bam_get_saved_pages_list_continue_cnf_struct;

/* BAM_SIG_GET_SAVED_PAGES_LIST_END_REQ */
typedef struct
{
    MSF_INT32 instance_id;
} bam_get_saved_pages_list_end_req_struct;
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/* BAM_SIG_STATUS_IND */
typedef struct
{
    MSF_INT16 instance_id;
    /* Current status as defined by status codes in Section 5.9 Transaction
       Status Codes. */
    MSF_INT16 status;
    /* The id of the current transaction. */
    MSF_INT16 transaction_id;
    /* Number of bytes uploaded to the server during the transaction. */
    MSF_INT32 upload_bytes_sent;
    /* Total number of bytes to be uploaded to the server during the
       transaction. */
    MSF_INT32 upload_bytes_total;
    /* Number of bytes received of the documents downloaded during the
       transaction. */
    MSF_INT32 document_bytes_read;
    /* Expected total number of bytes to be received of the documents
       downloaded during the transaction. */
    MSF_INT32 document_bytes_total;
    /* Number or requested documents. */
    MSF_INT16 document_number_of_requested;
    /* Number of downloaded documents. */
    MSF_INT16 document_number_of_downloaded;
    /* Number of failed document downloads. */
    MSF_INT16 document_number_of_failed;
    /* Number of bytes received from downloaded resources during the
       transaction. */
    MSF_INT32 resources_bytes;
    /* Number of requested resources. */
    MSF_INT16 resources_number_of_requested;
    /* Number of downloaded resources. */
    MSF_INT16 resources_number_of_downloaded;
    /* Number of failed resource downloads. */
    MSF_INT16 resources_number_of_failed;
} bam_status_ind_struct;

/* BAM_SIG_ERROR_IND */
typedef struct
{
    MSF_UINT16 instance_id;
    MSF_UINT16 error_code;      /* Error as indicated by codes defined in Section
                                   5.10 to 5.16. */
} bam_error_ind_struct;

/* BAM_SIG_DOCUMENT_INFO_IND */
typedef struct
{
    MSF_INT16 instance_id;
    /* Identifies this document. */
    MSF_INT16 document_id;
    /* Indicates the history navigation possibilities for this document; see
       Section 5.6 Info Flags. */
    MSF_INT16 flags;
    /* The document type, see Section 5.1 Document Type Constants. */
    MSF_INT16 doc_type;
    /* The protocol used for loading the document, see Section 5.8 Protocols. */
    MSF_INT16 protocol;
    /* Size in bytes for this document. */
    MSF_INT32 size;
    /* The socket id used when fetching the document. */
    MSF_INT32 socket_id;
    /* The Security Id for the secure connection, if any. */
    MSF_INT32 security_id;
    /* Value used if provided in response headers. */
    MSF_UINT32 last_modified;
    /* The url of the document. */
    char url[BAM_MAX_URL_LEN + 1];
    /* The document title. */
    char title[BAM_MAX_TITLE_LABEL_LEN + 1];
} bam_document_info_ind_struct;


#ifndef BAM_CFG_BRW_DISPLAY_INLINE_DO
/* BAM_SIG_DO_ELEMENTS_IND */
typedef struct
{
    MSF_INT16 instance_id;
    MSF_INT16 num_elements; /* The number of DO elements sent. */
} bam_do_elements_ind_struct;

typedef struct
{
    /* Unique ID, used in BAM_SIG_ACTIVATE_DO_ELEMENT_REQ */
    MSF_INT32 element_id;
    MSF_BOOL is_optional;   /* TRUE if this DO element is optional */

    /* Event type, "accept", "prev", etc. */
    char event_type[BAM_MAX_TITLE_LABEL_LEN + 1];

    /* Label, an attribute in the DO-element */
    char label[BAM_MAX_TITLE_LABEL_LEN + 1];
} bam_do_element_struct;

/* Peer Buffer */
typedef struct
{
    MSF_INT16 num_elements;

    /* An array of type bam_do_element_struct. */
    bam_do_element_struct elements[BAM_MAX_DO_ELEMENTS_NUM];
} bam_do_elements_struct;

#endif /* BAM_CFG_BRW_DISPLAY_INLINE_DO */

/* BAM_SIG_ELEMENT_FOCUSED_IND */
typedef struct
{
    MSF_INT16 instance_id;
    /* One or more of the BAM_RSRC_TYPE_ types. */
    MSF_INT16 resource_type;
    /* One of the BAM_FOCUSED_ELEMENT_ types. See Section 5.7 Focusable
       Elements. */
    MSF_INT16 type;
    /* One or more of the BAM_FOCUSED_ELEM_DRM_RESTRICTION_ types. */
    MSF_INT16 drm_restriction;
    /* The size in bytes of the object. */
    MSF_INT32 size;
    /* Uniquely identifies a resource. */
    char resource_id[BAM_MAX_TITLE_LABEL_LEN + 1];
    /* The title attribute of the element, if any. */
    char title[BAM_MAX_TITLE_LABEL_LEN + 1];
    /* The URL of the href attribute for links (<a> and <anchor> elements). */
    char url[BAM_MAX_URL_LEN + 1];
    /* The URL of the object embedded in the element, if any. */
    char object_url[BAM_MAX_URL_LEN + 1];
    /* The mime type of the embedded object, if any. */
    char object_mime[BAM_MAX_MIME_TYPE_LEN + 1];
    /* The cache file of the embedded object, if any. */
    char object_filePath[BAM_MAX_FILE_PATH_LEN + 1];
} bam_element_focused_ind_struct;

/* BAM_SIG_SET_SEC_CLASS_IND */
typedef struct
{
    MSF_INT16 instance_id;
    MSF_INT16 sec_class;    /* The currently used security class. */
} bam_set_sec_class_ind_struct;

//#ifdef MSF_CFG_9W_MODE_KBRD_SIMULATION
/* BAM_SIG_CHANGE_SETTING_VALUE_REQ */
typedef struct
{
    MSF_INT32 instance_id;
    /* The data type of the setting value. */
    MSF_UINT8 type;
    /* The id of the setting to be changed. */
    MSF_INT32 setting_id;
    /*
     * If the type of value is integer, the parameter "value_i" is the integer
     * value of the setting.
     * If the type of value is string, the parameter "value_i" is the length of
     * the string value.
     */
    MSF_INT32 value_i;
    /* If the type of value is string, the parameter "value_bv" is the string
       value of the setting; otherwise, the parameter "value_bv" must be
       ignored. */
    char *value_bv;
} bam_change_setting_value_req_struct;
//#endif

/* BAM_SIG_SET_PROFILE_REQ */

typedef struct
{
    /* The profile-setting structure that contains the whole browser
       settings. */
    MSF_INT32 int_value_table[BAM_SETTING_ID_TOTAL];
    char *str_value_table[BAM_SETTING_ID_TOTAL];
} bam_profile_setting_struct;

typedef struct
{
    MSF_INT32 instance_id;
    MSF_UINT8 request_id;
    MSF_UINT8 setting_id;
	bam_set_profile_option_enum type;
    /* The profile-setting structure that contains the whole browser
       settings.
       Note: This structure will be deallocated by BAM. */
    MSF_INT32 *int_value_table;
    char **str_value_table;
} bam_set_profile_req_struct;

/* BAM_SIG_SET_PROFILE_CNF */
#ifdef BAM_CFG_RECENT_PAGES_SUPPORT
typedef struct
{
    MSF_UINT16 instance_id;
    MSF_UINT8 request_id;
    /* The result of the request to apply the whole settings to Browser
       Engine. */
    MSF_UINT16 error_code;
} bam_set_profile_cnf_struct;

/* BAM_SIG_GET_RECENT_PAGES_LIST_START_REQ */
typedef struct
{
    MSF_INT32 instance_id;
    /* One of the BAM_HIST_SORT_OPTION_TYPE option. See Section 5.3 History
       Sorting-Option Constants. */
    MSF_INT32 sort_option;
} bam_get_recent_pages_list_start_req_struct;

/* BAM_SIG_GET_RECENT_PAGES_LIST_START_CNF */
typedef struct
{
    MSF_INT16 instance_id;
    /* Error as indicated by codes defined in Section 5.10 to 5.16. */
    MSF_UINT16 error_code;
    MSF_INT32 num_item; /* The number of history items. */
} bam_get_recent_pages_list_start_cnf_struct;

/* BAM_SIG_GET_RECENT_PAGES_LIST_CONTINUE_REQ */
typedef struct
{
    MSF_INT32 instance_id;
    MSF_INT32 start_index;  /* The index of the recent-page item. */
} bam_get_recent_pages_list_continue_req_struct;

/* BAM_SIG_GET_RECENT_PAGES_LIST_CONTINUE_CNF */
typedef struct
{
    MSF_INT16 instance_id;
    /* Error as indicated by codes defined in Section 5.10 to 5.16. */
    MSF_UINT16 error_code;
    MSF_UINT32 start_index;
    MSF_UINT32 num_items;       /* The number of the titles of recent pages in the
                                   peer buffer. */
} bam_get_recent_pages_list_continue_cnf_struct;

/* BAM_SIG_GET_RECENT_PAGES_LIST_END_REQ */
typedef struct
{
    MSF_INT32 instance_id;
} bam_get_recent_pages_list_end_req_struct;

/* BAM_SIG_GET_RECENT_PAGE_REQ */
typedef struct
{
    MSF_INT32 instance_id;
    MSF_UINT32 index;   /* The index of the recent page to get. */
} bam_get_recent_page_req_struct;

/* BAM_SIG_LOAD_RECENT_PAGE_REQ */
typedef struct
{
    MSF_INT32 instance_id;
    MSF_INT32 charset;
    MSF_UINT32 index;   /* The index of the recent page to load. */
} bam_load_recent_page_req_struct;

/* BAM_SIG_DELETE_RECENT_PAGE_REQ */
typedef struct
{
    MSF_INT32 instance_id;
    MSF_UINT32 index;   /* The index of the recent page to delete. */
} bam_delete_recent_page_req_struct;

/* BAM_SIG_DELETE_N_RECENT_PAGE_REQ */
typedef struct
{
    MSF_INT32 instance_id;
    MSF_UINT32 count;
    MSF_UINT32 *index_array;   /* The index of the recent page to delete. */
} bam_delete_n_recent_page_req_struct;

/* BAM_SIG_DELETE_ALL_RECENT_PAGES_REQ */
typedef struct
{
    MSF_INT32 instance_id;
} bam_delete_all_recent_pages_req_struct;

/* BAM_SIG_RECENT_PAGE_CNF */
typedef struct
{
    MSF_UINT16 instance_id;
    MSF_UINT16 error_code;
} bam_recent_page_cnf_struct;

/* Peer Buffer in BAM_SIG_RECENT_PAGE_CNF */
typedef struct
{
    MSF_UINT32 timestamp;
    MSF_UINT16 hits;
    MSF_UINT32 url_hash;
    char title[BAM_MAX_TITLE_LABEL_LEN + 1];
    char url[BAM_MAX_URL_LEN + 1];
} bam_recent_page_struct;
#endif /*recent pages */
/* BAM_SIG_WTAI_TEL_IND */
typedef struct
{
    MSF_INT32 instance_id;
    /* A unique ID for BAM to keep track of the requests. */
    MSF_UINT16 request_id;
    /* The requested operation, see Section 5.4 WTAI Telephony Operation
       Constants. */
    MSF_UINT16 operation;

    /* The input parameter for the requested operation.
       If the requested operation is MAKE_CALL, the "param" must be a
       phone-number as defined in [FORMAT];
       If the requested operation is SEND_DTMF, the "param" must be a
       tone_sequence as defined in [FORMAT]. */
    char param[BAM_MAX_PHONE_NUMBER_LEN + 1];
} bam_wtai_tel_ind_struct;

#ifdef MSF_CFG_FILE_UPLOAD_SUPPORT
/* BAM_SIG_SELECT_FILE_RSP */
typedef struct
{
    MSF_INT16 instance_id;
    MSF_INT32 request_id;
    MSF_INT16 error_code;
    char *filename;	
} bam_select_file_rsp_struct;
#endif

/* BAM_SIG_WTAI_TEL_RSP */
typedef struct
{
    MSF_UINT16 request_id;
    /* The result of the requested telephony operation. See Section 5.18
       Plug-in Error Codes. */
    MSF_UINT16 operation;
    MSF_UINT16 error_code;
} bam_wtai_tel_rsp_struct;

/* BAM_SIG_WTAI_PB_IND */
typedef struct
{
    MSF_INT32 instance_id;
    MSF_UINT16 request_id;
    /* The name to associate with the entry and may be an empty string. */
    char name[BAM_MAX_USER_PASSWD_LEN + 1];
    /* The phone number to associate with the entry. */
    char number[BAM_MAX_PHONE_NUMBER_LEN + 1];
} bam_wtai_pb_ind_struct;

/* BAM_SIG_WTAI_PB_RSP */
typedef struct
{
    MSF_UINT16 request_id;
    /* The result of adding the new phone-book entry. See Section 5.18 Plug-in
       Error Codes. */
    MSF_UINT16 error_code;
} bam_wtai_pb_rsp_struct;

/* BAM_SIG_URI_REQUEST_IND */
typedef struct
{
    MSF_INT32 instance_id;
    MSF_UINT16 request_id;
    char scheme[BAM_MAX_SCHEME_LEN + 1];    /* The scheme of the URI request. */
    /* The input parameter along with the URI request. */
    char param[BAM_MAX_URL_LEN + 1];
} bam_uri_request_ind_struct;

/* BAM_SIG_URI_REQUEST_RSP */
typedef struct
{
    MSF_UINT16 request_id;
    /* The result of handling the URI request. See Section 5.18 Plug-in Error
       Codes. */
    MSF_UINT16 error_code;
} bam_uri_request_rsp_struct;

/* BAM_SIG_BEARER_INFO_IND */
typedef struct
{
    MSF_INT16 instance_id;
    /* This indicates the bearer type is GPRS or CSD. */
    MSF_UINT16 bearer_type;
    /* This indicates the bearer status, e.g. connected or un-available. */
    MSF_UINT16 bearer_state;
} bam_bearer_info_ind_struct;

/* BAM_SIG_REGISTER_KEYPAD_HANDLER_REQ */
typedef struct
{
    MSF_INT32 instance_id;
} bam_register_keypad_handler_req_struct;

#ifdef __MMI_TOUCH_SCREEN__
/* BAM_SIG_HANDLE_PEN_EVENT_REQ */
typedef struct
{
    MSF_INT32 instance_id;
    MSF_INT16 pos_x;    /* mmi_pen_point_struct.x */
    MSF_INT16 pos_y;    /* mmi_pen_point_struct.y */
    MSF_INT32 type;     /* Defined in mmi_pen_event_type_enum */
} bam_handle_pen_event_req_struct;
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/* BAM_SIG_NOTIFY_SCREEN_INFO_REQ */
typedef struct
{
    MSF_INT32 instance_id;
    MSF_UINT32 x;
    MSF_UINT32 y;
    MSF_UINT32 w;
    MSF_UINT32 h;
    MSF_INT32 category_lyr_a_hndl;
    MSF_INT32 category_lyr_b_hndl;
} bam_notify_screen_info_req_struct;

/* MSG_ID_WAP_BAM_WAIT_USER_ACTION_RSP */
typedef struct
{
    MSF_INT32	instance_id;
    
    MSF_BOOL	enable_positive_sk;	/* Enable positive softkey or not. */
    MSF_BOOL	enable_negative_sk;	/* Enable negative softkey or not. */
    
    MSF_INT32	positive_label_len;
    MSF_INT32	negative_label_len;
    
    /* The label of positive softkey. If "enable_positive_sk" is FALSE,
     * this label must be ignored.
     */
    char        *positive_label;
    
    /* The label of negative softkey. If "enable_negative_sk" is FALSE,
     * this label must be ignored.
     */
    char        *negative_label;
} bam_wait_user_action_ind_struct;

/* MSG_ID_WAP_BAM_WAIT_USER_ACTION_RSP */
typedef struct
{
    MSF_INT32 instance_id;

    /* User presses the positive softkey or not. */
    MSF_BOOL press_positive_sk;
} bam_wait_user_action_rsp_struct;

/* MSG_ID_WAP_BAM_OBJECT_ACTION_REQ */
typedef struct
{
    MSF_INT32 instance_id;

    /*
     * The type of the focused page object sent in MSG_ID_WAP_BAM_ELEMENT_FOCUSED_IND.
     * * One of the BAM_FOCUSED_ELEMENT_ types. See "Selectable Elements Type Constants".
     */
    MSF_INT16 type;
} bam_object_action_req_struct;

/* MSG_ID_WAP_BAM_SHOW_AUTH_DIALOG_IND */
typedef struct
{
    MSF_INT32 instance_id;
    /* Identifier to map request/response. */
    MSF_INT32 request_id;
    /* Authorization Type: server or proxy.
       Please refer to "Authorization Type Constants". */
    MSF_INT32 auth_type;
    char *realm;
    char *username;
    char *password;
} bam_show_auth_dialog_ind_struct;

/* MSG_ID_WAP_BAM_SHOW_AUTH_DIALOG_RSP */
typedef struct
{
    MSF_INT32 instance_id;
    MSF_INT32 request_id;
    /* Authorization Options.
       Please refer to "Authorization Option Constants". */
    MSF_UINT16 options;
    char *username;
    char *password;
} bam_show_auth_dialog_rsp_struct;

#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
typedef struct  
{
    MSF_INT16  instanceId;
    char       *url;
    MSF_INT16  result;
}bam_delete_offline_page_rsp_struct;
#endif

typedef struct  
{
    MSF_UINT8 opt;
    MSF_UINT32 value_int;
    char* value_str;
}bam_em_setting_changed_ind_struct;

typedef struct
{
    MSF_UINT32 net_id;
}bam_close_connection_by_netid_struct;

#ifdef MSF_CFG_BRW_WMLS_NON_WIDGET_DLG_SUPPORT
typedef struct
{
	MSF_INT32 source_id;
    MSF_INT32 instance_id;
    MSF_INT32 dialup_type;
	MSF_BOOL result;
    const char *msg;   
} bam_wmls_create_dialogue_rsp_struct;
#endif

typedef struct
{
    MSF_UINT32 instance_id;
    MSF_UINT16 error_code;      
                                   
} bam_bearer_open_rsp_struct;

/**********************************************************************
 * Signal-sending API
 * These functions should be used by any other module that wants to
 * send a signal to the BAM module.
 **********************************************************************/

extern void *bam_convert(MSF_UINT8 module, MSF_UINT16 signal, void *buffer);

extern void bam_destruct(MSF_UINT8 module, MSF_UINT16 signal, void *p);

#define BAM_SEND_SIGNAL(cvtFunc, signalName, srcmod, destmod) do {                          \
        msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);                         \
        cvtFunc (&cvt_obj, &param);                                                         \
        length = (MSF_UINT16)cvt_obj.pos;                                                   \
        signal_buffer = MSF_SIGNAL_CREATE (signalName, srcmod, destmod, length);            \
        if (signal_buffer != NULL) {                                                        \
            user_data = MSF_SIGNAL_GET_USER_DATA (signal_buffer, &length);                  \
            msf_dcvt_init (&cvt_obj, MSF_DCVT_ENCODE, user_data, length, MSF_MODID_BAM);    \
            cvtFunc (&cvt_obj, &param);                                                     \
            MSF_SIGNAL_SEND (signal_buffer);                                                \
        }                                                                                   \
    } while (0)

/** Called by any other module that wants to use the BAM module.
 */

extern void BAMif_startInterface(void);

extern void
BAMif_createInstance(
    MSF_UINT8 source_id,
    MSF_BOOL is_full_screen,
    MSF_INT32 window_position_x,
    MSF_INT32 window_position_y,
    MSF_INT32 window_size_height,
    MSF_INT32 window_size_width,
    MSF_INT32 category_lyr_a_hndl,
    MSF_INT32 category_lyr_b_hndl);

extern void BAMif_deleteInstance(MSF_INT32 instance_id);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

extern void BAMif_loadUrl(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_INT32 options, MSF_INT32 charset, char *url);

extern void
BAMif_loadData(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_INT32 options, MSF_INT32 charset, char *content_path);

#ifndef BAM_CFG_BRW_DISPLAY_INLINE_DO
extern void BAMif_activateDoElement(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_INT32 element_id);
#endif

extern void BAMif_move(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_UINT8 direction, MSF_UINT8 steps);

extern void BAMif_reload(MSF_UINT8 source_id, MSF_INT32 instance_id);

extern void BAMif_stop(MSF_UINT8 source_id, MSF_INT32 instance_id);

extern void BAMif_navigationChange(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_INT16 elements);

#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
extern void BAMif_savePage(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_INT32 overwrite, char *label, char *url);

extern void BAMif_getSavedPage(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_UINT32 index);

extern void BAMif_loadSavedPage(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_UINT32 index);

extern void BAMif_deleteSavedPage(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_UINT32 index);

extern void BAMif_deleteNSavedPage(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_UINT32 *index_array, MSF_UINT32 count);

extern void BAMif_deleteAllSavedPage(MSF_UINT8 source_id, MSF_INT32 instance_id);

#if 0
/* under construction !*/
#endif

extern void BAMif_getSavedPagesListStart(MSF_UINT8 source_id, MSF_INT32 instance_id);

extern void BAMif_getSavedPagesListContinue(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_UINT32 start_index);

extern void BAMif_getSavedPagesListEnd(MSF_UINT8 source_id, MSF_INT32 instance_id);
#endif
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*
 * void
 * BAMif_navigateToHotspot (MSF_UINT8   source_id, MSF_INT32 instance_id, MSF_INT32     direction);
 */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

extern void
BAMif_setProfile(
    MSF_UINT8 source_id,
    MSF_INT32 instance_id,
    MSF_UINT8 request_id,
    MSF_UINT8 setting_id,
    bam_set_profile_option_enum type,
    bam_profile_setting_struct *profile);

extern void BAMif_wmls_create_dialogue_req(MSF_INT32 instance_id, MSF_INT32 dialup_type,const char *msg,const char *prompt_msg,const char *lsk,const char *rsk);
#ifdef MSF_CFG_BRW_WMLS_NON_WIDGET_DLG_SUPPORT
extern void BAMif_wmls_create_dialogue_rsp(MSF_INT32 source_id, MSF_INT32 instance_id, MSF_INT32 dialup_type, MSF_BOOL result,const char *msg );
#endif
#ifdef BAM_CFG_RECENT_PAGES_SUPPORT
extern void BAMif_getRecentPagesListStart(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_INT32 sort_option);

extern void BAMif_getRecentPagesListContinue(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_INT32 start_index);

extern void BAMif_getRecentPagesListEnd(MSF_UINT8 source_id, MSF_INT32 instance_id);

extern void BAMif_getRecentPage(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_UINT32 index);

extern void BAMif_loadRecentPage(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_INT32 charset, MSF_UINT32 index);

extern void BAMif_deleteRecentPage(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_UINT32 index);

extern void BAMif_deleteNRecentPage(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_UINT32 *index_array , MSF_UINT32 count ); 

extern void BAMif_deleteAllRecentPage(MSF_UINT8 source_id, MSF_INT32 instance_id);
#endif 
extern void BAMif_registerKeypadHandler(MSF_UINT8 source_id, MSF_INT32 instance_id);

#ifdef __MMI_TOUCH_SCREEN__
#if 0
/* under construction !*/
/* under construction !*/
#endif
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

extern void
BAMif_notifyScreenInfo(
    MSF_UINT8 source_id,
    MSF_INT32 instance_id,
    MSF_UINT32 x,
    MSF_UINT32 y,
    MSF_UINT32 w,
    MSF_UINT32 h,
    MSF_INT32 category_lyr_a_hndl,
    MSF_INT32 category_lyr_b_hndl);

#ifdef MSF_CFG_FILE_UPLOAD_SUPPORT
extern void BAMif_selectFileRsp(MSF_UINT8 source_id, MSF_INT16 instance_id, MSF_INT32 request_id, MSF_INT16 error_code, char * filename);
#endif

extern void BAMif_wtaiTelRsp(MSF_UINT8 source_id, MSF_UINT16 request_id, MSF_UINT16 operation, MSF_UINT16 error_code);

extern void BAMif_wtaiPbRsp(MSF_UINT8 source_id, MSF_UINT16 request_id, MSF_UINT16 error_code);

extern void BAMif_uriRequestRsp(MSF_UINT8 source_id, MSF_UINT16 request_id, MSF_UINT16 error_code);

extern void BAMif_waitUserActionRsp(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_BOOL press_positive_sk);

extern void BAMif_objectAction(MSF_UINT8 source_id, MSF_INT32 instance_id, MSF_INT16 type);

extern void
BAMif_showAuthDialogRsp(
    MSF_UINT8 source_id,
    MSF_INT32 instance_id,
    MSF_INT32 request_id,
    MSF_UINT16 options,
    char *username,
    char *password);

/*****************************************************************************
 * FUNCTION
 *  BAMif_showAuthDialog
 * DESCRIPTION
 *  This function is used to send an indication to Browser Application to show the authentication dialog.
 * PARAMETERS
 *  request_id:     [IN]    Identifier to map request/response.
 *  auth_type:      [IN]    Authorization Type: server or proxy.
 *  realm:          [IN]    The realm value of the protection space.
 *  username:       [IN]    The initial username if any.
 *  password:       [IN]    The initial password if any.
 * RETURNS
 *  void
 *****************************************************************************/
extern void
BAMif_showAuthDialog(
    MSF_INT32 request_id,
    MSF_INT32 auth_type,
    const char *realm,
    const char *username,
    const char *password);

/*****************************************************************************
 * FUNCTION
 *  BAMif_sendErrorInd
 * DESCRIPTION
 *  This function is used to send an indication to Browser Application of an error.
 * PARAMETERS
 *  error_code:     [IN]    Error code.
 * RETURNS
 *  void
 *****************************************************************************/
extern void BAMif_sendErrorInd(MSF_INT16 error_code);

#ifdef MSF_CFG_FILE_UPLOAD_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  BAMif_selectFileInd
 * DESCRIPTION
 *  This function is used to request Browser Application via primitive for file selection.
 * PARAMETERS
 *  instance_id:    [IN]    The instance id sent in the message MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created.
 *  request_id:     [IN]    Identifier to map request/response.
 * RETURNS
 *  void
 *****************************************************************************/
extern void BAMif_selectFileInd(MSF_INT16 instance_id, MSF_INT32 request_id);
#endif

/*****************************************************************************
 * FUNCTION
 *  BAMif_sendWtaiTelInd
 * DESCRIPTION
 *  This function is used to send an indication to Browser Application to request the application to make a phone call or send DTMF.
 * PARAMETERS
 *  request_id:     [IN]    A unique ID for BAM to keep track of the requests.
 *  operation:      [IN]    The requested operation, see WTAI Telephony Operation Constants.
 *  param:          [IN]    The input parameter for the requested operation. If the requested operation is MAKE_CALL, the ¡§param¡¨ must be a phone-number; If the requested operation is SEND_DTMF, the ¡§param¡¨ must be a tone_sequence.
 * RETURNS
 *  void
 *****************************************************************************/
extern void BAMif_sendWtaiTelInd(MSF_UINT16 request_id, MSF_UINT16 operation, const char* param);

/*****************************************************************************
 * FUNCTION
 *  BAMif_sendWtaiPbInd
 * DESCRIPTION
 *  This function is used to send an indication that is used to request the application to add a new phone-book entry.
 * PARAMETERS
 *  request_id:     [IN]    A unique ID for BAM to keep track of the requests.
 *  name:           [IN]    The name to associate with the entry and may be an empty string.
 *  param:          [IN]    The phone number to associate with the entry.
 * RETURNS
 *  void
 *****************************************************************************/
extern void BAMif_sendWtaiPbInd(MSF_UINT16 request_id, const char* name, const char* number);

/*****************************************************************************
 * FUNCTION
 *  BAMif_sendURIreq
 * DESCRIPTION
 *  This function is used to send an indication to request Browser Application to handle any URI request that is not one of the three Browser Engine supported built-in types, which including ¡§http¡¨, ¡§https¡¨, and ¡§file¡¨.
 * PARAMETERS
 *  request_id:     [IN]    A unique ID for BAM to keep track of the requests.
 *  scheme:         [IN]    The scheme of the URI request.
 *  param:          [IN]    The input parameter for the requested operation. If the requested operation is MAKE_CALL, the ¡§param¡¨ must be a phone-number; If the requested operation is SEND_DTMF, the ¡§param¡¨ must be a tone_sequence.
 * RETURNS
 *  void
 *****************************************************************************/
extern void BAMif_sendURIreq(MSF_UINT16 request_id, const char* scheme, const char* param);

/*****************************************************************************
 * FUNCTION
 *  BAMif_sendExternalObjectStatusInd
 * DESCRIPTION
 *  This function is used to send a indication of external object status.
 * PARAMETERS
 *  status:             [IN]    Current status including BAM_STATUS_EXTERNAL_OBJECT_START_TRANSACTION and BAM_STATUS_EXTERNAL_OBJECT_END_TRANSACTION.
 *  transaction_id:     [IN]    The id of the current transaction.
 * RETURNS
 *  void
 *****************************************************************************/
extern void BAMif_sendExternalObjectStatusInd(MSF_INT16 status, MSF_INT16 transaction_id);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

extern void BAMif_EmSettingChangedInd(MSF_UINT8 opt, MSF_UINT32 value_int, char* value_str);

extern void
BAMif_closeConnectionByNetId(MSF_UINT32 net_id);

extern void BAMif_BearerOpenRsp(MSF_UINT8 source_id, MSF_INT16 error_code, MSF_INT32 instance_id);

extern void BAMif_bearerOpenInd(MSF_INT32 instance_id);

/**********************************************************************
 * Conversion routines for all signals owned by this module.
 * None of these functions should be called directly by another module.
 **********************************************************************/

extern int bam_cvt_create_instance(msf_dcvt_t *obj, bam_create_instance_req_struct *p);

extern int bam_cvt_delete_instance(msf_dcvt_t *obj, bam_delete_instance_req_struct *p);

#if 0
/* under construction !*/
#endif
#ifdef BAM_CFG_RECENT_PAGES_SUPPORT
extern int bam_cvt_load_url(msf_dcvt_t *obj, bam_load_url_req_struct *p);

extern int bam_cvt_load_data(msf_dcvt_t *obj, bam_load_data_req_struct *p);

#ifndef BAM_CFG_BRW_DISPLAY_INLINE_DO
extern int bam_cvt_activate_do_element(msf_dcvt_t *obj, bam_activate_do_element_req_struct *p);
#endif

extern int bam_cvt_move(msf_dcvt_t *obj, bam_move_req_struct *p);

extern int bam_cvt_reload(msf_dcvt_t *obj, bam_reload_req_struct *p);

extern int bam_cvt_stop(msf_dcvt_t *obj, bam_stop_req_struct *p);

extern int bam_cvt_navigation_change(msf_dcvt_t *obj, bam_navigation_change_req_struct *p);

#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
extern int bam_cvt_save_page(msf_dcvt_t *obj, bam_save_page_req_struct *p);

extern int bam_cvt_get_saved_page(msf_dcvt_t *obj, bam_get_saved_page_req_struct *p);

extern int bam_cvt_load_saved_page(msf_dcvt_t *obj, bam_load_saved_page_req_struct *p);

extern int bam_cvt_delete_saved_page(msf_dcvt_t *obj, bam_delete_saved_page_req_struct *p);

extern int bam_cvt_delete_n_saved_page(msf_dcvt_t *obj, bam_delete_n_saved_page_req_struct *p);

extern int bam_cvt_delete_all_saved_pages(msf_dcvt_t *obj, bam_delete_all_saved_pages_req_struct *p);
#if 0
/* under construction !*/
#endif

extern int bam_cvt_get_saved_pages_list_start(msf_dcvt_t *obj, bam_get_saved_pages_list_start_req_struct *p);

extern int bam_cvt_get_saved_pages_list_continue(msf_dcvt_t *obj, bam_get_saved_pages_list_continue_req_struct *p);

extern int bam_cvt_get_saved_pages_list_end(msf_dcvt_t *obj, bam_get_saved_pages_list_end_req_struct *p);
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*
 * int
 * bam_cvt_navigate_to_hotspot (msf_dcvt_t *obj, bam_navigate_to_hotspot_req_struct *p);
 */
//#ifdef MSF_CFG_9W_MODE_KBRD_SIMULATION
extern int bam_cvt_change_setting_value(msf_dcvt_t *obj, bam_change_setting_value_req_struct *p);
//#endif

extern int bam_cvt_set_profile(msf_dcvt_t *obj, bam_set_profile_req_struct *p);

extern int bam_cvt_get_recent_pages_list_start(msf_dcvt_t *obj, bam_get_recent_pages_list_start_req_struct *p);

extern int bam_cvt_get_recent_pages_list_continue(msf_dcvt_t *obj, bam_get_recent_pages_list_continue_req_struct *p);

extern int bam_cvt_get_recent_pages_list_end(msf_dcvt_t *obj, bam_get_recent_pages_list_end_req_struct *p);

extern int bam_cvt_get_recent_page(msf_dcvt_t *obj, bam_get_recent_page_req_struct *p);

extern int bam_cvt_load_recent_page(msf_dcvt_t *obj, bam_load_recent_page_req_struct *p);

extern int bam_cvt_delete_recent_page(msf_dcvt_t *obj, bam_delete_recent_page_req_struct *p);

extern int bam_cvt_delete_n_recent_page(msf_dcvt_t *obj, bam_delete_n_recent_page_req_struct *p);

extern int bam_cvt_delete_all_recent_pages(msf_dcvt_t *obj, bam_delete_all_recent_pages_req_struct *p);

extern int bam_cvt_register_keypad_handler(msf_dcvt_t *obj, bam_register_keypad_handler_req_struct *p);

#ifdef __MMI_TOUCH_SCREEN__
#if 0
/* under construction !*/
#endif
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

extern int bam_cvt_notify_screen_info(msf_dcvt_t *obj, bam_notify_screen_info_req_struct *p);

#ifdef MSF_CFG_FILE_UPLOAD_SUPPORT
extern int bam_cvt_select_file_rsp(msf_dcvt_t * obj, bam_select_file_rsp_struct * p);
#endif

extern int bam_cvt_wtai_tel_rsp(msf_dcvt_t *obj, bam_wtai_tel_rsp_struct *p);

extern int bam_cvt_wtai_pb_rsp(msf_dcvt_t *obj, bam_wtai_pb_rsp_struct *p);

extern int bam_cvt_uri_request_rsp(msf_dcvt_t *obj, bam_uri_request_rsp_struct *p);

extern int bam_cvt_user_action_ind(msf_dcvt_t *obj, bam_wait_user_action_ind_struct *p);

extern int bam_cvt_user_action_rsp(msf_dcvt_t *obj, bam_wait_user_action_rsp_struct *p);

extern int bam_cvt_object_action(msf_dcvt_t *obj, bam_object_action_req_struct *p);

extern int bam_cvt_show_auth_dialog_rsp(msf_dcvt_t *obj, bam_show_auth_dialog_rsp_struct *p);

#ifdef MSF_CFG_OFFLINE_PAGES_SUPPORT
extern int bam_cvt_delete_offline_page_rsp(msf_dcvt_t *cvt_obj, bam_delete_offline_page_rsp_struct *p);
#endif

extern int bam_cvt_em_setting_changed_ind(msf_dcvt_t *cvt_obj, bam_em_setting_changed_ind_struct *p);

extern int bam_cvt_close_connection_by_netid(msf_dcvt_t *cvt_obj, bam_close_connection_by_netid_struct *p);

#endif /*recent pages*/

#endif /* _bam_if_h */ 


#endif /*OBIGO_Q03C_BROWSER*/
