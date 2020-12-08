
#ifndef _BAM_STRUCT_H
#define _BAM_STRUCT_H

#define BAM_DLG_WMLS_ALERT                        1
#define BAM_DLG_WMLS_CONFIRM                      2
#define BAM_DLG_WMLS_PROMPT                       3


/* WAP BAM SAP Begin */
//#ifdef __OBIGO_Q05A__

/* Max number of characters allowed for a WMLS msg. */
#define WAP_BAM_MAX_WMLS_MSG_LENGTH	40
/* Max number of characters allowed for a title or label. */
#define WAP_BAM_MAX_TITLE_LABEL_LENGTH	40
/* Max number of characters allowed for a scheme. */
#define WAP_BAM_MAX_SCHEME_LENGTH		40
/* Max number of DO elements in a WML page. */
#define WAP_BAM_MAX_NUM_DO_ELEMENTS		20
/* Max number of characters allowed for a username or password. */
/* (WAP_BAM_MAX_USER_PASSWD_LENGTH + 1) * ENCODING_LENGTH should be less than 124 because of the limitation from inline full screen */
#define WAP_BAM_MAX_USER_PASSWD_LENGTH	60
/* Max number of characters allowed for a phone number. */
#define WAP_BAM_MAX_PHONE_NUMBER_LENGTH	127
/* Max number of characters allowed for a realm. */
#define WAP_BAM_MAX_REALM_LENGTH		255
/* Max number of characters allowed for a URL. */
#define WAP_BAM_MAX_URL_LEN				512
/* Max number of characters allowed for a MIME type. */
#define WAP_BAM_MAX_MIME_TYPE_LEN		255
/* Max number of characters allowed for a file path. */
#define WAP_BAM_MAX_FILE_PATH_LEN		255
/* Max number of characters allowed for a full filename. */
/* FMGR_MAX_PATH_LEN * 3 (Convert character to UTF-8) */
#define WAP_BAM_MAX_FULL_FILENAME_LEN	780
/* Max number of characters allowed for a string setting value. */
#define WAP_BAM_MAX_SETTING_STR_VALUE_LEN	300
/* Unknown charset */
#define WAP_BAM_UNKNOWN_CHARSET		0

/* WML documents */
#define WAP_BAM_DOCTYPE_WML			1
/* XHTML documents */
#define WAP_BAM_DOCTYPE_XHTML		2
/* HTML documents */
#define WAP_BAM_DOCTYPE_HTML		3
#define WAP_BAM_DOCTYPE_HTML_Q1		4
#define WAP_BAM_DOCTYPE_HTML_Q2		5
#define WAP_BAM_DOCTYPE_PUSH_SI		8
#define WAP_BAM_DOCTYPE_PUSH_SL		9
#define WAP_BAM_DOCTYPE_PUSH_CO		10
/* Unknown type documents */
#define WAP_BAM_DOCTYPE_UNKNOWN		11

/* Navigation Constants
   Sent in message MSG_ID_WAP_BAM_MOVE_REQ to indicate the direction to take
   in the history of visited pages.
 */

/* Defines direction back for the move operation. */
#define WAP_BAM_MOVE_BACKWARD	1
/* Defines direction forward for the move operation. */
#define WAP_BAM_MOVE_FORWARD	2
/* Defines reload the same page for the move operation. */
#define WAP_BAM_MOVE_RELOAD		3

/* Recent-Page sorting-option constants
   Used in the message MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_START_REQ. */

/* Sort by title. */
#define WAP_BAM_RECENT_PAGE_SORT_OPTION_DATE	0
/* Sort by host.  */
#define WAP_BAM_RECENT_PAGE_SORT_OPTION_HOST	1
/* Sort by last visited. */
#define WAP_BAM_RECENT_PAGE_SORT_OPTION_LAST	2
/* Sort by most visited. */
#define WAP_BAM_RECENT_PAGE_SORT_OPTION_FREQ	3

/* WTAI Telephony Operation Constants
   Sent in message MSG_ID_WAP_BAM_WTAI_TEL_IND to indicate the requested
   telephony operation. */

/* To initiate a mobile-originated voice call. */
#define WAP_BAM_WTAI_TEL_MAKE_CALL	0
/* To send a DTMF sequence through the voice call most recently created. */
#define WAP_BAM_WTAI_TEL_SEND_DTMF	1

/* Load URL Flags
   Sent in function BRSif_loadUrl.
 */

/* Do not use the cached version of the reloaded page, if there is any. */
#define WAP_BAM_OPTION_NO_CACHE					0x01
/* If the page is not stored in cache when navigating in history, ask for
   user confirmation whether to reload page or not. */
#define WAP_BAM_OPTION_CACHE_NOTIFICATION		0x02
/* Primary purpose for this option is usage from script. (ESMP)
   When script execution causes navigation this option is used to
   prevent triggering of unwanted load events if the navigation
   turns out to be within the same page.
   Not to be used other than by the script engine. */
#define WAP_BAM_OPTION_FROM_SCRIPT				0x04
/* The loaded page will replace the current history element. */
#define WAP_BAM_OPTION_REPLACE					0x08
/* Usually, the loading of a URL via MSG_ID_WAP_BAM_LOAD_URL_REQ entails
   creating a new WML context. This means resetting all WML variables, and
   possibly removing the current history (if BRS_CFG_CLEAR_HISTORY_ON_NEWCONTEXT
   is defined).
   To prevent this from happening, this option may be set in the call
   to MSG_ID_WAP_BAM_LOAD_URL_REQ. */
#define WAP_BAM_OPTION_KEEP_WML_CONTEXT			0x10
/* Setting this option will cause the BRS to remove all earlier entries
   in the navigation history, regardless of how BRS_CFG_CLEAR_HISTORY_ON_NEWCONTEXT
   is defined. This option can also be combined with BAM_OPTION_KEEP_WML_CONTEXT,
   to get the effect of clearing the history while keeping the WML context. */
#define WAP_BAM_OPTION_CLEAR_HISTORY			0x20


/* Info Flags
   Flag values used in the response signal MSG_ID_WAP_BAM_DOCUMENT_INFO_IND. */

/* Indicates that back-navigation is possible. */
#define WAP_BAM_INFO_FLAG_ENABLE_BACK			0x01
/* Indicates that forward-navigation is possible. */
#define WAP_BAM_INFO_FLAG_ENABLE_FORWARD		0x02
/* Indicates that the document is loaded from cache and new,
   that is, not previously in the history. */
#define WAP_BAM_INFO_FLAG_NEW_PAGE				0x04
/* Indicates that the document has just been added to the history. */
#define WAP_BAM_INFO_FLAG_NEW_PAGE_IN_HISTORY	0x08
/* The document was loaded from the offline store. */
#define WAP_BAM_INFO_FLAG_SAVED_PAGE			0x10
/* The document was loaded in the main window (and not in a subframe, for example). */
#define WAP_BAM_INFO_FLAG_MAIN_WINDOW			0x20
/* The navigation is local (within the current page). */
#define WAP_BAM_INFO_FLAG_LOCAL_NAVIGATION		0x40


/* Selectable Element Types
   When the user is viewing a page, some elements of that page may be selected.
   A typical example of a selectable element is an anchor for navigating to another page. The
   constants used in this signalling between Browser Engine and the application is defined in this section.
   When viewing a page Browser Engine will send the message MSG_ID_WAP_BAM_ELEMENT_FOCUSED_IND with the type
   of element currently focused using one of the flags in "Info Flags". The application can use the constants
   in (Focusable Elements) in the message MSG_ID_WAP_BAM_NAVIGATION_CHANGE_REQ to tell Browser Engin which
   elements that are focusable by combining them in an or-operation. If no such mesage is sent there is a
   default setting, BAM_FOCUSABLE_ELEMENTS_NORMAL_MODE, that is used and which means that all types except
   simple objects are focusable.
   The application will typically use the information from MSG_ID_WAP_BAM_ELEMENT_FOCUSED_IND to know which
   menus to display when the user focuses the various element-types. E.g. a focused image might
   depending on configurations made cause menus for tasks like "send as MMS" or
   "save in my pictures" or both.
 */

/* No element in focus. */
#define WAP_BAM_FOCUSED_ELEMENT_NONE                  0
/* < a > and < anchor >*/
#define WAP_BAM_FOCUSED_ELEMENT_LINK                  1
/* < do >, do elements (WML access key), if rendered in content*/
#define WAP_BAM_FOCUSED_ELEMENT_DO                    2
/* < textarea > and < input type="text" > */
#define WAP_BAM_FOCUSED_ELEMENT_TEXTINPUT             3
/* < select >, WML and HTML selectable options (in select list) */
#define WAP_BAM_FOCUSED_ELEMENT_SELECT                4
/* < img >, < object > and < bgsound >. */
#define WAP_BAM_FOCUSED_ELEMENT_IMAGE                 5
/* < input type="image" > */
#define WAP_BAM_FOCUSED_ELEMENT_INPUT                 6
/* < button > and < input type="button" > */
#define WAP_BAM_FOCUSED_ELEMENT_BUTTON                7
/* < input type="submit" > */
#define WAP_BAM_FOCUSED_ELEMENT_SUBMIT                8
/* < input type="reset" > */
#define WAP_BAM_FOCUSED_ELEMENT_RESET                 9
/* < input type="file" > */
#define WAP_BAM_FOCUSED_ELEMENT_FILE_INPUT            10
/* < input type="checkbox", "radio" > depening on whether they are checked or not.*/
#define WAP_BAM_FOCUSED_ELEMENT_INPUT_SELECTED        11
/* < input type="checkbox", "radio" > unchecked. */
#define WAP_BAM_FOCUSED_ELEMENT_INPUT_UNSELECTED      12
/* < area >, HTML image map area definition. */
#define WAP_BAM_FOCUSED_ELEMENT_AREA                  13
/* A frame or iframe element. */
#define WAP_BAM_FOCUSED_ELEMENT_FRAME                 14
/* < label >, HTML label used for some kinds of controls.
 * Both the label and its target will have :focus set at
 * the same time, but the label is the one considered as focused. */
#define WAP_BAM_FOCUSED_ELEMENT_LABEL                 15

#define WAP_BAM_FOCUSED_ELEMENT_IMAGE_LONG_TAP      16

/* Focusable Elements
   These constants are used in MSG_ID_WAP_BAM_NAVIGATION_CHANGE_REQ. */

/* This class typically includes elements a, anchor and inlined-do.*/
#define WAP_BAM_FOCUSABLE_ELEMENTS_LINKS				0x0001
/* This typically includes elements such as input, label, select, textarea and option.*/
#define WAP_BAM_FOCUSABLE_ELEMENTS_FORM_ELEMENTS		0x0002
/* The label element.*/
#define WAP_BAM_FOCUSABLE_ELEMENTS_LABEL_ELEMENTS		0x0004
/* Simple resources are those that are handled by the browser, such as a gif image or
   a sound that plays using direct HDIa_ calls. This is typically the element img and
   possibly object.*/
#define WAP_BAM_FOCUSABLE_ELEMENTS_SIMPLE_OBJECT		0x0008
/* An external resource is sent on content routing and may have its own menue system
   in the recieving module, and should thus sometimes be focusable in "normal navigation mode".
   This is also the img and object elements. */
#define WAP_BAM_FOCUSABLE_ELEMENTS_EXTERNAL_RESOURCE	0x0010
/* Image maps hold area elements that can be applied on top of images.*/
#define WAP_BAM_FOCUSABLE_ELEMENTS_AREA					0x0020
/* Frames are a high level type of that each hold a document.*/
#define WAP_BAM_FOCUSABLE_ELEMENTS_FRAME				0x0040
/* A selection of the above typically used for the normal navigation mode. */
#define WAP_BAM_FOCUSABLE_ELEMENTS_NORMAL_MODE (WAP_BAM_FOCUSABLE_ELEMENTS_LINKS              | \
                                            WAP_BAM_FOCUSABLE_ELEMENTS_FORM_ELEMENTS      | \
                                            WAP_BAM_FOCUSABLE_ELEMENTS_EXTERNAL_RESOURCE  | \
                                            WAP_BAM_FOCUSABLE_ELEMENTS_AREA               | \
                                            WAP_BAM_FOCUSABLE_ELEMENTS_FRAME)
/* A selection of the above typically used for the object(image) navigation mode. */
#define WAP_BAM_FOCUSABLE_ELEMENTS_OBJECT_MODE (WAP_BAM_FOCUSABLE_ELEMENTS_SIMPLE_OBJECT  | \
                                            WAP_BAM_FOCUSABLE_ELEMENTS_FRAME)
/* A selection of all elements type */
#define WAP_BAM_FOCUSABLE_ELEMENTS_ALL_MODE    (WAP_BAM_FOCUSABLE_ELEMENTS_LINKS              | \
                                            WAP_BAM_FOCUSABLE_ELEMENTS_FORM_ELEMENTS      | \
                                            WAP_BAM_FOCUSABLE_ELEMENTS_EXTERNAL_RESOURCE  | \
                                            WAP_BAM_FOCUSABLE_ELEMENTS_AREA               | \
                                            WAP_BAM_FOCUSABLE_ELEMENTS_FRAME              | \
                                            WAP_BAM_FOCUSABLE_ELEMENTS_SIMPLE_OBJECT)

/* Protocol types */

/* Connectionless WSP */
#define WAP_BAM_PROTOCOL_WSP_CL			1
/* Connectionless WSP over WTLS */
#define WAP_BAM_PROTOCOL_WSP_CL_WTLS	2
/* Connection-oriented WSP */
#define WAP_BAM_PROTOCOL_WSP_CO			3
/* Connection-oriented WSP over WTLS */
#define WAP_BAM_PROTOCOL_WSP_CO_WTLS	4
/* HTTP */
#define WAP_BAM_PROTOCOL_HTTP			5
/* HTTP over TLS 1.0 */
#define WAP_BAM_PROTOCOL_HTTP_TLS		6
/* HTTP over SSL 3.0 */
#define WAP_BAM_PROTOCOL_HTTP_SSL		7
/* Document was retrieved from the cache */
#define WAP_BAM_PROTOCOL_CACHE			8
/* Document was retrieved from multipart content. */
#define WAP_BAM_PROTOCOL_MULTIPART		9
/* Document was retrieved from file */
#define WAP_BAM_PROTOCOL_FILE			10
/* Unspecified protocol */
#define WAP_BAM_PROTOCOL_OTHER			11


/* Private Data Type Constants
 * Used in the message MSG_ID_WAP_BAM_CLEAR_PRIVATE_DATA_REQ.
 */

/* Remove all records currently stored in the cache. */
#define BAM_PRIVATE_DATA_TYPE_CACHE     0x01
/* Remove all proxy and host authentication data. */
#define BAM_PRIVATE_DATA_TYPE_AUTH      0x02
/* Removes all cookies. */
#define BAM_PRIVATE_DATA_TYPE_COOKIE	0x04


/* Transaction Status Codes
   Transaction status codes used for status signalling during transactions. */

/* Sent when a transaction starts. That is, when a user selects a link, when the
   application sends LOAD_URL, LOAD_DATA, MOVE or RELOAD, or when a timer expires and starts
   a new transaction. */
#define WAP_BAM_STATUS_START_TRANSACTION		1
/* Sent when the transaction is finished, either normally or for instance when
   the application sent STOP. */
#define WAP_BAM_STATUS_END_TRANSACTION			2
/* Status update signal. The status update interval is configurable by the
   trastatus_sig setting key. */
#define WAP_BAM_STATUS_TRANSACTION_STATUS		3
/* Sent when a transaction starts for external object. That is, when a user selects a RTSP link, 
   it will establihs RTSP connection and trigger a new transaction. */
#define WAP_BAM_STATUS_EXTERNAL_OBJECT_START_TRANSACTION	4
/* Sent when the transaction for external object is finished. */
#define WAP_BAM_STATUS_EXTERNAL_OBJECT_END_TRANSACTION		5


/* Authorization Type Constants */

/* Server Authentication. */
#define WAP_BAM_AUTH_TYPE_SERVER	1
/* Proxy Authentication. */
#define WAP_BAM_AUTH_TYPE_PROXY		2

/* Authorization Option Constants */

/* User cancels the authentication. */
#define WAP_BAM_AUTH_OPTIONS_CANCEL								0x00
/* Do not save username or password. */
#define WAP_BAM_AUTH_OPTIONS_SAVE_NOTHING						0x01
/* Save both username and password. */
#define WAP_BAM_AUTH_OPTIONS_SAVE_USERNAME_AND_PASSWORD	0x02
/* Save username only. */
#define WAP_BAM_AUTH_OPTIONS_SAVE_USERNAME					0x03


/* General Error Codes */

/* Successful opeartion or result */
#define WAP_BAM_ERROR_OK	0

/* Create Instance Error Codes
   Error codes used for instance creation. */

/* Browser Engine is terminating */
#define WAP_BAM_ERROR_TERMINATING	1


/* Input Error Codes
   Error codes used for input errors. */

/* Some input parameter in a connector function call has an invalid value.  */
#define WAP_BAM_ERROR_INVALID_INPUT		14
/* Malformed URL was encountered. */
#define WAP_BAM_ERROR_INVALID_URL		15
/* An input URL contained a scheme not supported by BRS or any registered plug-in. */
#define WAP_BAM_ERROR_INVALID_SCHEME	16


/* Parser Error Codes
   Parser error codes. For more information, see msf_prsr.h. */

/* The document uses an unsupported character set or encoding. */
#define WAP_BAM_ERROR_UNKNOWN_CHARSET		21
/* The content contains a syntax error or violates
   another rule in an underlying content specification,
   such as WBXML or XML. (For example WML is an application of XML)
   Can also be sent when the application rejects the document,
   for instance on a validation error. */
#define WAP_BAM_ERROR_SYNTAX				22
/* A document type was specified but unknown and no content
   type associated with a known document type was given. */
#define WAP_BAM_ERROR_UNKNOWN_DOCTYPE		23
/* The document uses an unsupported version of WBXML. */
#define WAP_BAM_ERROR_UNSUPPORTED_WBXML		24
/* Document is not valid; for example contains an element used in the wrong context. */
#define WAP_BAM_ERROR_VALIDATION			25
/* The Parser or one of its resources is not initialised or not available. */
#define WAP_BAM_ERROR_ABORTED				26
/* HTML warning: This is a frameset document without a noframes element as alternative content. */
#define WAP_BAM_ERROR_REQUIRE_FRAMES		27


/* WMLScript Error Codes
   'WMLS' errors, i.e., error in WMLScript */

/* Error while interpreting a WML Script file. */
#define WAP_BAM_ERROR_WMLS					30
/* The verification of a WMLScript file failed. */
#define WAP_BAM_ERROR_WMLS_VERIFICATION		31
/* Error when executing a WMLScript library function. */
#define WAP_BAM_ERROR_WMLS_LIB				32
/* A WMLScript function was called with the wrong number of arguments. */
#define WAP_BAM_ERROR_WMLS_FUNC_ARGS		33
/* A WMLScript function called an unknown (external) function. */
#define WAP_BAM_ERROR_WMLS_EXTERNAL			34
/* Error in specification of an external WMLScript function, loading failed. */
#define WAP_BAM_ERROR_WMLS_LOAD				35
/* Incorrect WMLS byte code, interpreter failed. */
#define WAP_BAM_ERROR_WMLS_INTERPRETING		36
/* A WMLScript function has been aborted. */
#define WAP_BAM_ERROR_WMLS_ABORT			37
/* A WMLScript function has exited. */
#define WAP_BAM_ERROR_WMLS_EXIT				38


/* WML Access Restrictions Error Codes
   Access restrictions on WML or WMLScript */

/* WML access violation. */
#define WAP_BAM_ERROR_ACCESS_RESTRICTIONS_WML		40
/* WMLScript access violation. */
#define WAP_BAM_ERROR_ACCESS_RESTRICTIONS_WMLS		41


/* Communication Error Codes
   Communication errors. */

/* There was an error in the communication; for example,
   a host could not be found or a connection timed out.
   The request is aborted. */
#define WAP_BAM_ERROR_COMMUNICATION					50
/* No address could be found during the DNS lookup. The request is aborted. */
#define WAP_BAM_ERROR_HOST_NOT_FOUND				51
/* A timer expired before a response arrived. The request is aborted. */
#define WAP_BAM_ERROR_REQUEST_TIMED_OUT				52
/* A connection was closed or socket setup failed. The request is aborted. */
#define WAP_BAM_ERROR_CONNECTION_FAILED				53
/* A secure connection failed. The request is aborted. */
#define WAP_BAM_ERROR_SECURE_CONNECTION_FAILED		54
/* Authentication failed. The request is aborted. */
#define WAP_BAM_ERROR_AUTHENTICATION				55
/* A secure connection was cancelled. The request is aborted. */
#define WAP_BAM_ERROR_SECURE_CONNECTION_CANCELLED	56
/** No start part available in Multipart/Mixed message */
#define WAP_BAM_ERROR_PAGE_NOT_FOUND                57
/** Authentication cancelled. The request is aborted. */
#define WAP_BAM_ERROR_AUTHENTICATION_CANCELLED      58
/** Total file size is too large and could not be sent throught WSP connection. The request is aborted. */
#define WAP_BAM_ERROR_FILE_SIZE_TOO_LARGE           59


/* JavaScript Error Codes
   JavaScript errors.
   NB must be consecutive and correlate with corresponding MSF errors. */

/* No actual error code, used as start value for all JavaScript errors */
#define WAP_BAM_ERR_JSCRIPT                           60
/* No error has occured */
#define WAP_BAM_ERR_JSCRIPT_NONE                      (WAP_BAM_ERR_JSCRIPT + 1)
/* Unspecified error */
#define WAP_BAM_ERR_JSCRIPT_ERR                       (WAP_BAM_ERR_JSCRIPT + 2)
/* Internal Error */
#define WAP_BAM_ERR_JSCRIPT_INTERNALERR               (WAP_BAM_ERR_JSCRIPT + 3)
/* The eval method was called illegally */
#define WAP_BAM_ERR_JSCRIPT_EVALERR                   (WAP_BAM_ERR_JSCRIPT + 4)
/* A numeric value is not in its legal range */
#define WAP_BAM_ERR_JSCRIPT_RANGEERR                  (WAP_BAM_ERR_JSCRIPT + 5)
/* An attempt to read a variable that does not exist has been made */
#define WAP_BAM_ERR_JSCRIPT_REFERENCEERR              (WAP_BAM_ERR_JSCRIPT + 6)
/* The code does not contain legal JavaScript */
#define WAP_BAM_ERR_JSCRIPT_SYNTAXERR                 (WAP_BAM_ERR_JSCRIPT + 7)
/* A value is of the wrong type */
#define WAP_BAM_ERR_JSCRIPT_TYPEERR                   (WAP_BAM_ERR_JSCRIPT + 8)
/* String with illegal hexadecimal escapes was sent to decodeURI or decodeURIComponent methods */
#define WAP_BAM_ERR_JSCRIPT_URIERR                    (WAP_BAM_ERR_JSCRIPT + 9)


/* Miscellaneous Error Codes
   Misc. */

/* An internal error in the BRS, usually due to a programming error or
   because some internal limit has been reached. */
#define WAP_BAM_ERROR_INTERNAL                        70
/* The user has moved to a page in the history that was originally
   fetched using a POST request (from a non-WML page), and the page is
   no longer in the cache.
   However, resending the POST request might have undesired side effects.
   Hence, the browser will show an empty page, and issue this error code.
   An explicit reload is needed to resend the POST request. */
#define WAP_BAM_ERROR_RESEND_POST_WARNING             71
/* BrowserEngine is going to exceed the memory limitation, and some page content may not be displayed completely. */
#define WAP_BAM_ERROR_LOW_MEMORY                      72
/* The page was too big and could not be loaded. The request is aborted. */
#define WAP_BAM_ERROR_CONTENT_TOO_LARGE               73
/* An internal error occurs while setting the profile to Browser Engine. */
#define WAP_BAM_ERROR_SET_PROFILE					  74
/* The whole BrowserEngine has run out of memory */
#define WAP_BAM_ERROR_OUT_OF_MEMORY                   75
/* The CSD bearer is disconnected due to long idle timeout */
#define WAP_BAM_ERROR_LONG_IDLE_TIMEOUT               76


/* Saved Pages Error Codes
   Error messages used in response to the requests of Saved Pages functionality. */

/* A request on a saved page (load, delete, rename) could not be completed,
   because a page with the specified label could not be found. */
#define WAP_BAM_ERROR_SAVED_PAGES_NOT_FOUND           80
/* A request to save the current page failed, because a page with the same
   label is stored already, and the parameter 'overwrite' was FALSE. */
#define WAP_BAM_ERROR_SAVED_PAGES_EXISTS              81
/* A request to the saved pages facilities failed, for some unspecified reason. */
#define WAP_BAM_ERROR_SAVED_PAGES_FAILED              82
/* A request to save the current page succeeded, but not all the resource
   files (images, for example) could be stored. */
#define WAP_BAM_ERROR_SAVED_PAGES_PARTIAL             83
/* A request to save the current page failed, because some predefined resource
   limit was exceeded (for example, the maximum number of saved pages). */
#define WAP_BAM_ERROR_SAVED_PAGES_LIMIT_EXCEEDED      84


/* Recent Pages Error Codes
   Error messages used in response to the requests of Recent Pages
   functionality. */

/* A request on a recent page (load, delete) could not be completed,
   because a page with the specified index could not be found. */
#define WAP_BAM_ERROR_RECENT_PAGES_NOT_FOUND	90
/* A request to the recent pages facilities failed, for some unspecified
   reason. */
#define WAP_BAM_ERROR_RECENT_PAGES_FAILED		91


/* Inline Video Playing Error Codes */

/* Inline video objects exceed maximum limitation */
#define WAP_BAM_ERROR_EXCEED_MAX_NUM_OF_INLINE_VDO	101
/* Inline video can not be played in call */
#define WAP_BAM_ERROR_CANNOT_PLAY_INLINE_VDO_IN_CALL	102

/* Communication External Error Codes */

/* APN error */
#define WAP_BAM_ERROR_GPRS_UNKNOWN_APN				110
/* GPRS authentication error */
#define WAP_BAM_ERROR_GPRS_AUTHENTICATION_FAILURE	111
/* GPRS not support */
#define WAP_BAM_ERROR_GPRS_UNSUPPORTED				112
/* GPRS not subscribed */
#define WAP_BAM_ERROR_GPRS_NOT_SUBSCRIBED           113
/* CSD authentication error */
#define WAP_BAM_ERROR_CSD_AUTHENTICATION_FAILURE	114
/* CSD connection fail */
#define WAP_BAM_ERROR_CSD_REACTIVATE				115
/* CSD connection fail */
#define WAP_BAM_ERROR_CSD_PPP_NEGOTIATED_FAILED		116
/* CSD connection fail */
#define WAP_BAM_ERROR_CSD_ACT_FAILED				117
/* CSD connection fail */
#define WAP_BAM_ERROR_CSD_CALL_SETUP_FAILED			118

/* Generic ABM error */
#define WAP_BAM_ERROR_ABM_REJECTED					119

/* File Selection Error Codes
   Error messages used in response to the requests of file selection functionality. */

/* A successful operation. */
#define WAP_BAM_ERROR_FILE_SELECTION_OK				130
/* Failed to select file due to any reason, such as file system is empty, user cancels to select file, the selected file path is too long, etc. */
#define WAP_BAM_ERROR_FILE_SELECTION_FAILED 		131

#define WAP_BAM_ERROR_UNSUPPORTED_SCRIPT_WARNING    132

#define WAP_BAM_ERROR_OUT_OF_MEM_WAP_RESET          133

#define WAP_BAM_ERROR_NO_DISPLAY_CONTENT            134


/* Plug-in Error Codes
   Error messages used in response to the requests of WTAI and URI Scheme
   functionality. */

/* A successful operation. */
#define WAP_BAM_WTAI_RESULT_OK								0x0
/* For a WTAI Telephony operation:
   (1) WAP_BAM_WTAI_TEL_MAKE_CALL:
      The number parameter is not a phone-number.
   (2) WAP_BAM_WTAI_TEL_SEND_DTMF:
      The dtmf parameter is not a DTMF sequence.
   For a WTAI Phone Book operation:
      The number parameter is not a phone-number.
 */
#define WAP_BAM_WTAI_RESULT_INVALID							0x01
/* The called party is busy. */
#define WAP_BAM_WTAI_RESULT_TEL_CALLED_PARTY_IS_BUSY		0x11
/* The network is not available. */
#define WAP_BAM_WTAI_RESULT_TEL_NETWORK_NOT_AVAILABLE		0x12
/* The called party did not answer. */
#define WAP_BAM_WTAI_RESULT_TEL_CALLED_PARTY_NO_ANSWER		0x13
/* No active voice connection. */
#define WAP_BAM_WTAI_RESULT_TEL_NO_ACTIVE_CONNECTION		0x14
/* The name parameter is unacceptable or too long. */
#define WAP_BAM_WTAI_RESULT_PB_IN_NAME						0x21
/* The number parameter is too long. */
#define WAP_BAM_WTAI_RESULT_PB_NUMBER_TO_LONG				0x22
/* The phonebook entry could not be written. */
#define WAP_BAM_WTAI_RESULT_PB_PHONE_BOOK_ENTRY				0x23
/* The phonebook is full. */
#define WAP_BAM_WTAI_RESULT_PB_PHONE_BOOK_IS_FULL			0x24
/* Unspecified error. */
#define WAP_BAM_WTAI_RESULT_UNSPECIFIED						0xFF


/* malloc func function pointer type. */
typedef void* (*wap_bam_alloc_func) (kal_uint32 size);

/***************************************
 * Browser-related Setting IDs
 ***************************************/
typedef enum
{
	wap_bam_setting_value_type_int,
	wap_bam_setting_value_type_str
} wap_bam_setting_value_type_t;

typedef enum
{
	wap_bam_set_profile_to_brs,
    wap_bam_do_not_set_profile_to_brs
} wap_bam_set_profile_option_enum;

typedef enum
{
	/* APP */
	wap_bam_setting_id_images,		/* wap_bam_setting_value_type_int */
	wap_bam_setting_id_movies,		/* wap_bam_setting_value_type_int */
	wap_bam_setting_id_sounds,		/* wap_bam_setting_value_type_int */
	wap_bam_setting_id_history,		/* wap_bam_setting_value_type_int */
	wap_bam_setting_id_homepage,	/* wap_bam_setting_value_type_str */
	wap_bam_setting_id_shortcuts,	/* wap_bam_setting_value_type_int */

	/* BRS */
	wap_bam_setting_id_rendering,		/* wap_bam_setting_value_type_int */
	wap_bam_setting_id_thumbnail,		/* wap_bam_setting_value_type_int */
	wap_bam_setting_id_refresh,			/* wap_bam_setting_value_type_int */
	wap_bam_setting_id_css,				/* wap_bam_setting_value_type_int */
	wap_bam_setting_id_script,			/* wap_bam_setting_value_type_int */
	wap_bam_setting_id_cache,			/* wap_bam_setting_value_type_int */
	wap_bam_setting_id_sec_warning,		/* wap_bam_setting_value_type_int */
	wap_bam_setting_id_imei,			/* wap_bam_setting_value_type_int */
	wap_bam_setting_id_no_mime,			/* wap_bam_setting_value_type_int */
	wap_bam_setting_id_zoom,			/* wap_bam_setting_value_type_int */
/* #if defined(__MMI_VECTOR_FONT_SUPPORT__) && defined MTK_TMP_PATCH of CR36621 */
	wap_bam_setting_id_font_size,			/* wap_bam_setting_value_type_int */
/* #endif */
	wap_bam_setting_id_navigation,		/* wap_bam_setting_value_type_int */
	wap_bam_setting_id_frame_layout,	/* wap_bam_setting_value_type_int */
	wap_bam_setting_id_brs_homepage,	/* wap_bam_setting_value_type_str */

	/* STK */
	wap_bam_setting_id_cookies,	/* wap_bam_setting_value_type_int */

	/* Connection, if no CPS */
	wap_bam_setting_id_con_account,		/* wap_bam_setting_value_type_int */
	wap_bam_setting_id_con_type,		/* wap_bam_setting_value_type_int */
	wap_bam_setting_id_con_addr_type,	/* wap_bam_setting_value_type_int */
	wap_bam_setting_id_con_addr,		/* wap_bam_setting_value_type_str */
	wap_bam_setting_id_con_pwd,			/* wap_bam_setting_value_type_str */
	wap_bam_setting_id_con_port,		/* wap_bam_setting_value_type_int */
	wap_bam_setting_id_con_realm,		/* wap_bam_setting_value_type_str */
	wap_bam_setting_id_con_sec_port,	/* wap_bam_setting_value_type_int */
	wap_bam_setting_id_con_user,		/* wap_bam_setting_value_type_str */
	wap_bam_setting_id_con_timeout,		/* wap_bam_setting_value_type_int */
    wap_bam_setting_id_9way,            /* wap_bam_setting_value_type_int */
	wap_bam_setting_id_add_history,         /* wap_bam_setting_value_type_int */
	wap_bam_setting_id_transcode_proxy,     /* wap_bam_setting_value_type_int */

	/* End of setting id */
	wap_bam_setting_id_total
} wap_bam_setting_id_t;

/* For Q03C only. */
typedef enum
{
	wap_bam_setting_type_settings,
	wap_bam_setting_type_profile,
	wap_bam_setting_type_both
} wap_bam_setting_type_t;

/***************************************
 * Browser-related Setting Values
 ***************************************/
#define WAP_BAM_SETTING_INT_INIT_VAL	(-1)
#define WAP_BAM_SETTING_STR_INIT_VAL	(NULL)

/* wap_bam_setting_id_images */
enum {
  wap_bam_setting_val_images_always,
  wap_bam_setting_val_images_ask,
  wap_bam_setting_val_images_never
};

/* wap_bam_setting_id_movies */
enum {
  wap_bam_setting_val_movies_always,
  wap_bam_setting_val_movies_ask,
  wap_bam_setting_val_movies_never
};

/* wap_bam_setting_id_sounds */
enum {
  wap_bam_setting_val_sounds_always,
  wap_bam_setting_val_sounds_ask,
  wap_bam_setting_val_sounds_never
};

/* wap_bam_setting_id_history */
enum {
  wap_bam_setting_val_history_no = 0
};

/* wap_bam_setting_id_homepage */

/* wap_bam_setting_id_rendering */
/* Sync with Rendering preference in Browser Engine */
enum
{
	wap_bam_setting_val_rend_normal,
	wap_bam_setting_val_rend_narrow,
	wap_bam_setting_val_rend_wrap,
	wap_bam_setting_val_rend_text
};

/* wap_bam_setting_id_thumbnail */
enum
{
	wap_bam_setting_val_thumb_disable,
	wap_bam_setting_val_thumb_enable
};

/* wap_bam_setting_id_refresh */
enum
{
	wap_bam_setting_val_refresh_disable,
	wap_bam_setting_val_refresh_enable
};

/* wap_bam_setting_id_css */
enum
{
	wap_bam_setting_val_css_disable,
	wap_bam_setting_val_css_enable
};

/* wap_bam_setting_id_script */
enum
{
	wap_bam_setting_val_script_disable,
	wap_bam_setting_val_script_enable
};

/* wap_bam_setting_id_cache */
enum
{
	wap_bam_setting_val_cache_disable,
	wap_bam_setting_val_cache_enable
};

/* wap_bam_setting_id_shortcuts */
enum
{
	wap_bam_setting_val_shortcuts_disable,
	wap_bam_setting_val_shortcuts_enable
};

/* wap_bam_setting_id_sec_warning */
/* Sync with Scheme transition preferences in Browser Engine */
enum
{
	wap_bam_setting_val_sec_warning_disable = 0,

	/* BRS_PREFERENCE_VALUE_HTTP_TO_HTTPS_TRANSITION_ASK | BRS_PREFERENCE_VALUE_HTTPS_TO_HTTP_TRANSITION_ASK */
	wap_bam_setting_val_sec_warning_enable = 0x03
};

/* wap_bam_setting_id_imei */
enum
{
	wap_bam_setting_val_imei_disable,
	wap_bam_setting_val_imei_enable
};

/* wap_bam_setting_id_no_mime */
enum
{
    wap_bam_setting_val_no_mime_always,
    wap_bam_setting_val_no_mime_ask,
    wap_bam_setting_val_no_mime_never
};

/* wap_bam_setting_id_zoom */

/* wap_bam_setting_id_navigation */
enum
{
	/* Sync with Navigation preference in Browser Engine */
	wap_bam_setting_val_nav_scroll = 0x01,
	wap_bam_setting_val_nav_2_way = 0x02,
	wap_bam_setting_val_nav_4_way = 0x04,
	wap_bam_setting_val_nav_textspot = 0x08
};

/* wap_bam_setting_id_frame_layout */
/* wap_bam_setting_id_brs_homepage */

/* wap_bam_setting_id_cookies */
enum
{
	wap_bam_setting_val_cookies_disable,
	wap_bam_setting_val_cookies_enable
};

/* wap_bam_setting_id_con_type */
enum
{
    wap_bam_setting_val_conn_type_http = 1,	/*************************
                                           	  * BRW_PROF_CONN_TYPE_HTT
                                           	  *************************/
    wap_bam_setting_val_conn_type_connection_oreinted,	/* BRW_PROF_CONN_TYPE_CONNECTION_OREINTED */
    wap_bam_setting_val_conn_type_connection_oreinted_secure /* BRW_PROF_CONN_TYPE_CONNECTION_OREINTED_SECURE */
};

/* wap_bam_setting_id_con_addr_type */
enum
{
    wap_bam_setting_val_conn_addr_type_ipv4 = 0,
    wap_bam_setting_val_conn_addr_type_alpha
};

/* wap_bam_setting_id_con_account */
/* wap_bam_setting_id_con_addr */
/* wap_bam_setting_id_con_pwd */
/* wap_bam_setting_id_con_port */
/* wap_bam_setting_id_con_realm */
/* wap_bam_setting_id_con_sec_port */
/* wap_bam_setting_id_con_user */
/* wap_bam_setting_id_con_timeout */


/* Resource types */

/* Image resource */
#define WAP_BAM_RSRC_TYPE_IMAGE        0x01
/* Background Image resource */
#define WAP_BAM_RSRC_TYPE_BACKGROUND   0x02
/* Audio resource */
#define WAP_BAM_RSRC_TYPE_SOUND        0x04
/* Other resource */
#define WAP_BAM_RSRC_TYPE_OTHER        0x08

/* Type in MSG_ID_WAP_BAM_NOTIFY_APP_IND */
typedef enum
{
    wap_bam_notify_app_set_title_string
} wap_bam_notify_app_enum;

/* Local parameter of MSG_ID_WAP_BAM_READY_IND */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
} wap_bam_ready_ind_struct;

/* Local parameter of MSG_ID_WAP_BAM_CREATE_INSTANCE_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	src;                  /* Module id of creating module, to which the response message MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF will be sent. */
    kal_bool    is_full_screen;       /* Setting of screen size (full screen or normal screen). */
    kal_int32	window_position_x;    /* The x-wise position where the paint box that is to hold rendered content should be placed. */
    kal_int32	window_position_y;    /* The y-wise position where the paint box that is to hold rendered content should be placed. */
    kal_int32	window_size_height;   /* The height to which the paint box should be set. */
    kal_int32	window_size_width;    /* The width to which the paint box for content should be set. */
    kal_int32	category_lyr_a_hndl;  /* GDI Layer A (like, for top area) using by category screen. */
    kal_int32	category_lyr_b_hndl;  /* GDI Layer B (like, for bottom area) using by category screen. */
} wap_bam_create_instance_req_struct;

typedef struct
{
    kal_int32 instance_id;
    kal_int32 dialup_type;
    char msg[WAP_BAM_MAX_WMLS_MSG_LENGTH + 1];   
	char prompt_msg[WAP_BAM_MAX_WMLS_MSG_LENGTH + 1];
	char lsk[WAP_BAM_MAX_WMLS_MSG_LENGTH + 1];
	char rsk[WAP_BAM_MAX_WMLS_MSG_LENGTH + 1];
} wap_bam_wmls_create_dialogue_req_struct;

typedef struct
{
    kal_int32 instance_id;
    kal_int32 dialup_type;
	kal_bool result;
    char msg[WAP_BAM_MAX_WMLS_MSG_LENGTH + 1];   
} wap_bam_wmls_create_dialogue_rsp_struct;


/* Local parameter of MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32 	instance_id;    /* The id to be used when referring to this instance in future signals and function calls. */
    kal_uint16	error_code;     /* The result of instance creation request. */
} wap_bam_create_instance_cnf_struct;

/* Local parameter of MSG_ID_WAP_BAM_DELETE_INSTANCE_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32	instance_id;  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
} wap_bam_delete_instance_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_DELETE_INSTANCE_CNF */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32	instance_id;  /* The id of the deleted BAM instance. */
} wap_bam_delete_instance_cnf_struct;

/* Local parameter of MSG_ID_WAP_BAM_RESIZE_WINDOW_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;            /* The calling module id. */
    kal_bool is_full_screen;        /* Setting of screen size (full screen or normal screen). */
    kal_int32	instance_id;          /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when the Browser Engine instance was created. */
    kal_int32	window_position_x;    /* The x-position of the upper left corner of the content holding paint box. */
    kal_int32	window_position_y;    /* The y-position of the upper left corner of the content holding paint box. */
    kal_int32	window_size_height;   /* The height of the content holding paint box. */
    kal_int32	window_size_width;    /* The width of the content holding paint box. */
    kal_int32	category_lyr_a_hndl;  /* GDI Layer A (like, for top area) using by category screen. */
    kal_int32	category_lyr_b_hndl;  /* GDI Layer B (like, for bottom area) using by category screen. */
} wap_bam_resize_window_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_LOAD_URL_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;                /* The calling module id. */
    kal_int32	instance_id;              /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_int32	options;                  /* Options to use for loading the URL, see Load URL Flags. */
    kal_int32	charset;                  /* The character set to use for interpreting the content referred to by the loaded URL. */
    char	url[WAP_BAM_MAX_URL_LEN + 1]; /* The document URL to load. */
} wap_bam_load_url_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_LOAD_DATA_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;                                /* The calling module id. */
    kal_int32	instance_id;                              /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_int32	options;                                  /* Options to use for loading the URL, see Load URL Flags. */
    kal_int32	charset;                                  /* The character set to use for interpreting the content referred to by the loaded URL. */
    char	content_path[WAP_BAM_MAX_FILE_PATH_LEN + 1];  /* The local file path of the data content that should be loaded. */
} wap_bam_load_data_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_ACTIVATE_DO_ELEMENT_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;    /* The calling module id. */
    kal_int32	instance_id;  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_int32	element_id;   /* The id of the DO-element to activate. The same element_id as used in MSG_ID_WAP_BAM_DO_ELEMENTS_IND. */
} wap_bam_activate_do_element_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_MOVE_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32	instance_id;  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
	kal_uint8	source_id;    /* The calling module id. */
    kal_uint8	direction;    /* The direction to move. Possible values are described in Navigation Constants. */
    kal_uint8	steps;        /* The number of steps to move in the history. */
} wap_bam_move_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_RELOAD_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;    /* The calling module id. */
    kal_int32	instance_id;  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
} wap_bam_reload_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_STOP_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;    /* The calling module id. */
    kal_int32	instance_id;  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
} wap_bam_stop_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_NAVIGATION_CHANGE_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32	instance_id;  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_uint8	source_id;    /* The calling module id. */
    kal_int16	elements;     /* The element combination from Focusable Elements. */
} wap_bam_navigation_change_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_SAVE_PAGE_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;                                /* The calling module id. */
    kal_int32	instance_id;                              /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_int32	overwrite;                                /* If TRUE this flag overwrites any existing page with the same label. */
    char	label[WAP_BAM_MAX_TITLE_LABEL_LENGTH + 1];    /* The label to use for the page being saved. */
    char	url[WAP_BAM_MAX_URL_LEN + 1];                 /* The URL of the saved page. For Q03C only.*/
} wap_bam_save_page_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_SAVE_PAGE_CNF */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32 	instance_id;    /* The id to be used when referring to this instance in future signals and function calls. */
    kal_uint16	error_code;     /* The result of the save-page request. See Saved Pages Error Codes. */
} wap_bam_save_page_cnf_struct;

/* Peer Buffer of MSG_ID_WAP_BAM_SAVE_PAGE_CNF */
typedef struct
{
    kal_uint32	date;                                   /* The created date of the saved page. */
    kal_uint32	doc_size;                               /* The document size of the saved page. */
    kal_uint32	data_size;                              /* The total data size of the saved page. */
    char	label[WAP_BAM_MAX_TITLE_LABEL_LENGTH + 1];    /* The label of the saved page. */
    char	url[WAP_BAM_MAX_URL_LEN + 1];                 /* The URL of the saved page. */
} wap_bam_saved_page_struct;

/* Local parameter of MSG_ID_WAP_BAM_GET_SAVED_PAGE_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;    /* The calling module id. */
    kal_int32	instance_id;  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_uint32	index;      /* The index of the specified saved page. */
} wap_bam_get_saved_page_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_LOAD_SAVED_PAGE_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;    /* The calling module id. */
    kal_int32	instance_id;  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_uint32	index;      /* The index of the save page to load. */
} wap_bam_load_saved_page_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_DELETE_SAVED_PAGE_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;    /* The calling module id. */
    kal_int32	instance_id;  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_uint32	index;      /* The index of the save page to delete. */
} wap_bam_delete_saved_page_req_struct;


typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;    /* The calling module id. */
    kal_int32	instance_id;  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_uint32	*index_array;      /* The index of the save page to delete. */
	kal_uint32  count;
} wap_bam_delete_n_saved_page_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_DELETE_ALL_SAVED_PAGES_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;    /* The calling module id. */
    kal_int32	instance_id;  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
} wap_bam_delete_all_saved_pages_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_RENAME_SAVED_PAGE_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;                                    /* The calling module id. */
    kal_int32	instance_id;                                  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_uint32	index;                                      /* The index of the save page. */
    char	new_label[WAP_BAM_MAX_TITLE_LABEL_LENGTH + 1];    /* The new label to apply to the page. */
} wap_bam_rename_saved_page_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_START_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;    /* The calling module id. */
    kal_int32	instance_id;  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
} wap_bam_get_saved_pages_list_start_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_START_CNF */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32 	instance_id;    /* The id to be used when referring to this instance in future signals and function calls. */
    kal_uint16	error_code;     /* The result of the save-page request. See Saved Pages Error Codes. */
    kal_uint32	num_items;      /* The number of the page items. */
} wap_bam_get_saved_pages_list_start_cnf_struct;

/* Local parameter of MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_CONTINUE_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;        /* The calling module id. */
    kal_int32	instance_id;      /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_uint32	start_index;	  /* The index of the save page. */
} wap_bam_get_saved_pages_list_continue_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_CONTINUE_CNF */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32 	instance_id;    /* The id to be used when referring to this instance in future signals and function calls. */
    kal_uint16	error_code;     /* The result of the save-page request. See Saved Pages Error Codes. */
    kal_uint32	start_index;    /* The start index of the save page in the peer buffer. */
    kal_uint32	num_items;      /* The number of the titles of saved pages in the peer buffer. */
} wap_bam_get_saved_pages_list_continue_cnf_struct;

/* Local parameter of MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_END_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;    /* The calling module id. */
    kal_int32	instance_id;  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
} wap_bam_get_saved_pages_list_end_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_GET_RESOURCES_LIST_START_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;    /* The calling module id. */
    kal_int32	instance_id;  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
} wap_bam_get_resources_list_start_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_GET_RESOURCES_LIST_START_CNF */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32	instance_id;  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_uint16	error_code; /* Error code. */
    kal_uint32	num_res;    /* The number of resources that Browser Engine is currently using */
} wap_bam_get_resources_list_start_cnf_struct;

/* Local parameter of MSG_ID_WAP_BAM_GET_RESOURCES_LIST_CONTINUE_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;        /* The calling module id. */
    kal_int32	instance_id;      /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_uint32	start_index;    /* The index of the resource. */
} wap_bam_get_resources_list_continue_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_GET_RESOURCES_LIST_CONTINUE_CNF */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32	instance_id;      /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_uint16	error_code;     /* Error code. */
    kal_uint32	start_index;    /* The start index of the resources in the peer buffer. */
    kal_uint32	num_res;        /* The number of the types and titles of resources in the peer buffer. */
} wap_bam_get_resources_list_continue_cnf_struct;

/* Local parameter of MSG_ID_WAP_BAM_GET_RESOURCES_LIST_END_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;    /* The calling module id. */
    kal_int32	instance_id;  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
} wap_bam_get_resources_list_end_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_GET_RESOURCE_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;    /* The calling module id. */
    kal_int32	instance_id;  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_uint32	index;      /* The index of the specified resource. */
} wap_bam_get_resource_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_GET_RESOURCE_CNF */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32 	instance_id;    /* The id to be used when referring to this instance in future signals and function calls. */
    kal_uint16	error_code;     /* Error code. */
} wap_bam_get_resource_cnf_struct;

/* Peer Buffer of MSG_ID_WAP_BAM_GET_RESOURCE_CNF */
typedef struct
{
    kal_int16	type;                                         /* One of the BAM_FOCUSED_ELEMENT_ types. See Resource Type Constants. */
    kal_int16	drm_restriction;                              /* One or more of the BRS_FOCUSED_ELEM_DRM_RESTRICTION_ types. */
    kal_int32	size;                                         /* The size in bytes of the object. */
    char	    title[WAP_BAM_MAX_TITLE_LABEL_LENGTH + 1];    /* The title attribute of the element, if any. */
    char	    url[WAP_BAM_MAX_URL_LEN + 1];                 /* The URL of the object. */
    char	    mime_type[WAP_BAM_MAX_MIME_TYPE_LEN + 1];     /* The mime type of the object, if any. */
    char	    cache_file[WAP_BAM_MAX_FILE_PATH_LEN + 1];    /* The cache file of the object, if any. */
} wap_bam_resource_item_struct;

/* Local parameter of MSG_ID_WAP_BAM_ACTIVATE_RESOURCE_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;    /* The calling module id. */
    kal_int32	instance_id;  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_uint32	index;      /* The index of the specified resource. */
} wap_bam_activate_resource_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_NAVIGATE_TO_HOTSPOT_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;    /* The calling module id. */
    kal_int32	instance_id;  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_int32	direction;    /* The direction to navigate. */
} wap_bam_navigate_to_hotspot_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_STATUS_IND */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32	instance_id;                      /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_int16	status;                           /* Current status as defined by status codes in Transaction Status Codes. */
    kal_int16	transaction_id;                   /* The id of the current transaction. */
    kal_int32	upload_bytes_sent;                /* Number of bytes uploaded to the server during the transaction. */
    kal_int32	upload_bytes_total;               /* Total number of bytes to be uploaded to the server during the transaction. */
    kal_int32	document_bytes_read;              /* Number of bytes received of the documents downloaded during the transaction. */
    kal_int32	document_bytes_total;             /* Expected total number of bytes to be received of the documents downloaded during the transaction. */
    kal_int16	document_number_of_requested;     /* Number or requested documents. */
    kal_int16	document_number_of_downloaded;    /* Number of downloaded documents. */
    kal_int32	resources_bytes;                  /* Number of bytes received from downloaded resources during the transaction. */
    kal_int16	document_number_of_failed;        /* Number of failed document downloads. */
    kal_int16	resources_number_of_requested;    /* Number of requested resources. */
    kal_int16	resources_number_of_downloaded;   /* Number of downloaded resources. */
    kal_int16	resources_number_of_failed;       /* Number of failed resource downloads. */
} wap_bam_status_ind_struct;

/* Local parameter of MSG_ID_WAP_BAM_ERROR_IND */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32 	instance_id;    /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_uint16	error_code;     /* Error code. */
} wap_bam_error_ind_struct;

/* Local parameter of MSG_ID_WAP_BAM_SELECT_FILE_IND */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int16 	instance_id;    /* The instance id sent in the message MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_int32	request_id;       /* A unique ID for BAM to keep track of the requests. */
} wap_bam_select_file_ind_struct;

/* Local parameter of MSG_ID_WAP_BAM_SELECT_FILE_RSP */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32	request_id;                               /* Identifier to map request/response, this id is returned in the response message MSG_ID_WAP_BAM_SELECT_FILE_RSP. */
    kal_int16 	instance_id;                            /* The instance id sent in the message MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_int16	error_code;                               /* The result of the file selection operation. See File Selection Error Codes. */
    char 	filename[WAP_BAM_MAX_FULL_FILENAME_LEN + 1];  /* Full file path of the slected filename. It should be UTF-8 string with null-terminated. */
} wap_bam_select_file_rsp_struct;

/* Local parameter of MSG_ID_WAP_BAM_DOCUMENT_INFO_IND */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32	instance_id;                              /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_int16	document_id;                              /* Identifies this document. */
    kal_int16	flags;                                    /* Indicates the recent-page navigation possibilities for this document; see Info Flags. */
    kal_int16	doc_type;                                 /* The document type, see Document Type Constants. */
    kal_int16	protocol;                                 /* The protocol used for loading the document, see Protocols. */
    kal_int32	size;                                     /* Size in bytes for this document. */
    kal_int32	socket_id;                                /* The socket id used when fetching the document. */
    kal_int32	security_id;                              /* The Security Id for the secure connection, if any. */
    kal_uint32	last_modified;                          /* Value used if provided in response headers. */
    char 	url[WAP_BAM_MAX_URL_LEN + 1];                 /* The url of the document. */
    char 	title[WAP_BAM_MAX_TITLE_LABEL_LENGTH + 1];    /* The document title. */
} wap_bam_document_info_ind_struct;

/* Local parameter of MSG_ID_WAP_BAM_DO_ELEMENTS_IND */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32	instance_id;      /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_int16	num_elements;     /* The number of DO elements sent. */
} wap_bam_do_elements_ind_struct;

/* Structure of DO element */
typedef struct
{
    kal_int32   element_id;                                         /* Unique ID, used in MSG_ID_WAP_BAM_ACTIVATE_DO_ELEMENT_REQ */
    kal_bool    is_optional;                                        /* TRUE if this DO element is optional */
    char        event_type[WAP_BAM_MAX_TITLE_LABEL_LENGTH + 1];     /* Event type, "accept", "prev", etc. */
    char        label[WAP_BAM_MAX_TITLE_LABEL_LENGTH + 1];          /* Label, an attribute in the DO-element */
} wap_bam_do_element_t;

/* Peer Buffer of MSG_ID_WAP_BAM_DO_ELEMENTS_IND */
typedef struct
{
    kal_int16	num_elements;                                         /* The number of DO elements sent. */
    wap_bam_do_element_t	elements[WAP_BAM_MAX_NUM_DO_ELEMENTS];    /* An array of type wap_bam_do_element_t. */
} wap_bam_do_elements_struct;

/* Local parameter of MSG_ID_WAP_BAM_ELEMENT_FOCUSED_IND */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32	instance_id;                                  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_int16	resource_type;                                /* One or more of the WAP_BAM_RSRC_TYPE_ types. See Resource Type Constants. */
    kal_int16	type;                                         /* One of the WAP_BAM_FOCUSED_ELEMENT_ types. See Section 5.24 Selectable Elements Type Constants. */
    kal_int16	drm_restriction;                              /* One or more of the BRS_FOCUSED_ELEM_DRM_RESTRICTION_ types. */
    kal_int32	size;                                         /* The size in bytes of the object. */
    char 	resource_id[WAP_BAM_MAX_TITLE_LABEL_LENGTH + 1];  /* Uniquely identifies a resource. */ 
    char 	title[WAP_BAM_MAX_TITLE_LABEL_LENGTH + 1];        /* The title attribute of the element, if any. */
    char 	url[WAP_BAM_MAX_URL_LEN + 1];                     /* The URL of the href attribute for links (<a> and <anchor> elements). */
    char 	object_url[WAP_BAM_MAX_URL_LEN + 1];              /* The URL of the object embedded in the element, if any. */
    char 	object_mime[WAP_BAM_MAX_MIME_TYPE_LEN + 1];       /* The mime type of the embedded object, if any. */
    char 	object_filePath[WAP_BAM_MAX_FILE_PATH_LEN + 1];   /* The cache file of the embedded object, if any. */
} wap_bam_element_focused_ind_struct;

/* Local parameter of MSG_ID_WAP_BAM_SET_SEC_CLASS_IND */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32	instance_id;  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_int16	sec_class;    /* The currently used security class. */
} wap_bam_set_sec_class_ind_struct;

/* Local parameter of MSG_ID_WAP_BAM_CHANGE_SETTING_VALUE_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;                                        /* The calling module id. */
    kal_int32	instance_id;                                      /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_uint8	type;                                             /* The data type of the setting value.
                                                                     wap_bam_setting_value_type_int or wap_bam_setting_value_type_str */
    kal_int32	setting_id;                                       /* The id of the setting to be changed. */
    kal_int32	value_i;                                          /* If the type of value is integer, the parameter ¡§value_i¡¨ is the integer value of the setting. If the type of value is string, the parameter ¡§value_i¡¨ is the length of the string value. */
    kal_uint8	value_bv[WAP_BAM_MAX_SETTING_STR_VALUE_LEN + 1];  /* If the type of value is string, the parameter ¡§value_bv¡¨ is the string value of the setting; otherwise, the parameter ¡§value_bv¡¨ is NULL. */
} wap_bam_change_setting_value_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_CHANGE_SETTING_VALUE_IND */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32	instance_id;                                      /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_uint8	type;                                             /* The data type of the setting value.
                                                                     wap_bam_setting_value_type_int or wap_bam_setting_value_type_str */
    kal_int32	setting_id;                                       /* The id of the setting to be changed. */
    kal_int32	value_i;                                          /* If the type of value is integer, the parameter ¡§value_i¡¨ is the integer value of the setting. If the type of value is string, the parameter ¡§value_i¡¨ is the length of the string value. */
    kal_uint8	value_bv[WAP_BAM_MAX_SETTING_STR_VALUE_LEN + 1];  /* If the type of value is string, the parameter ¡§value_bv¡¨ is the string value of the setting; otherwise, the parameter ¡§value_bv¡¨ is NULL. */
} wap_bam_change_setting_value_ind_struct;

/* Structure of profile setting */
typedef struct
{
    kal_int32 int_value_table[wap_bam_setting_id_total];    /* The profile setting table that records integer value type */
    char* str_value_table[wap_bam_setting_id_total];        /* The profile setting table that records string value type */
} wap_bam_profile_setting_t;

/* Local parameter of MSG_ID_WAP_BAM_SET_PROFILE_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32	instance_id;                /* The instance id sent in the message MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_uint8	source_id;                  /* The calling module id. */
    kal_uint8	request_id;                 /* Identifier to map request/response, this id is the same as the request_id in the response message MSG_ID_WAP_BAM_SET_PROFILE _CNF. */
    kal_uint8   setting_id;                 /* For Q03C only. */
	wap_bam_set_profile_option_enum type;
    wap_bam_profile_setting_t *	profile;    /* The profile-setting structure that contains the whole browser settings. Note: This structure will be deallocated by BAM. */
} wap_bam_set_profile_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_SET_PROFILE_CNF */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32 	instance_id;    /* The instance id sent in the message MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_uint8	request_id;       /* Identifier to map request/response, this id is the same as the request_id in the request message MSG_ID_WAP_BAM_SET_PROFILE_REQ. */
    kal_uint16	error_code;     /* The result of the request to apply the whole settings to the browser core engine. */
} wap_bam_set_profile_cnf_struct;

/* Local parameter of MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_START_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;    /* The calling module id. */
    kal_int32	instance_id;  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_int32	sort_option;  /* One of the recent page sorting option. See Recent-Page Sorting-Option Constants. */
} wap_bam_get_recent_pages_list_start_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_START_CNF */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32	instance_id;      /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_uint16	error_code;     /* Error code. */
    kal_int32	num_item;         /* The number of recent-page items. */
} wap_bam_get_recent_pages_list_start_cnf_struct;

/* Local parameter of MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_CONTINUE_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;    /* The calling module id. */
    kal_int32	instance_id;  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_int32	start_index;  /* The start index of the recent-page item. */
} wap_bam_get_recent_pages_list_continue_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_CONTINUE_CNF */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32	instance_id;      /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_uint16	error_code;     /* Error code */
    kal_uint32	start_index;    /* The start index of the recent pages in the peer buffer. */
    kal_uint32	num_items;      /* The number of the titles of recent pages in the peer buffer. */
} wap_bam_get_recent_pages_list_continue_cnf_struct;

/* Local parameter of MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_END_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;    /* The calling module id. */
    kal_int32	instance_id;  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
} wap_bam_get_recent_pages_list_end_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_GET_RECENT_PAGE_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;    /* The calling module id. */
    kal_int32	instance_id;  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_uint32	index;      /* The index of the recent page to get. */
} wap_bam_get_recent_page_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_LOAD_RECENT_PAGE_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;    /* The calling module id. */
    kal_int32	instance_id;  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_int32	charset;      /* The character set to use for interpreting the content referred to by the loaded URL. */
    kal_uint32	index;      /* The index of the recent page to load. */
} wap_bam_load_recent_page_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_DELETE_RECENT_PAGE_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;    /* The calling module id. */
    kal_int32	instance_id;  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_uint32	index;      /* The index of the recent page to delete. */
} wap_bam_delete_recent_page_req_struct;

typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;    /* The calling module id. */
    kal_int32	instance_id;  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_uint32	*index_array;      /* The indexes of the recent page to delete. */
	kal_uint32  count;
} wap_bam_delete_n_recent_page_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_DELETE_ALL_RECENT_PAGES_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;    /* The calling module id. */
    kal_int32	instance_id;  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
} wap_bam_delete_all_recent_pages_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_RECENT_PAGE_CNF */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32 	instance_id;    /* The id to be used when referring to this instance in future signals and function calls. */
    kal_uint16	error_code;     /* The result of the save-page request. See Recent Pages Error Codes. */
} wap_bam_recent_page_cnf_struct;

/* Peer Buffer of MSG_ID_WAP_BAM_RECENT_PAGE_CNF */
typedef struct
{
    kal_uint32	timestamp;                              /* The latest access time of the recent page item. */
    kal_uint16	hits;                                   /* The hit count of the recent page item. */
    kal_uint32	url_hash;                               /* The hash value of the URL of the recent page item. */
    char	title[WAP_BAM_MAX_TITLE_LABEL_LENGTH + 1];    /* The title of the recent page item. */
    char	url[WAP_BAM_MAX_URL_LEN + 1];                 /* The URL of the recent page item. */
} wap_bam_recent_page_struct;

/* Local parameter of MSG_ID_WAP_BAM_WTAI_TEL_IND */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32	instance_id;                              /* The instance id sent in the message MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_uint16	request_id;                             /* A unique ID for BAM to keep track of the requests. */
    kal_uint16	operation;                              /* The requested operation, see WTAI Telephony Operation Constants. */
    char 	param[WAP_BAM_MAX_PHONE_NUMBER_LENGTH + 1];   /* The input parameter for the requested operation. If the requested operation is MAKE_CALL, the ¡§param¡¨ must be a phone-number; If the requested operation is SEND_DTMF, the ¡§param¡¨ must be a tone_sequence. */
} wap_bam_wtai_tel_ind_struct;

/* Local parameter of MSG_ID_WAP_BAM_WTAI_TEL_RSP */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint16	request_id;     /* Identifier to map request/response, this id is returned in the response message MSG_ID_WAP_BAM_WTAI_TEL_RSP. */
    kal_uint16	operation;      /* The requested operation, see WTAI Telephony Operation Constants. It is passed from MSG_ID_WAP_BAM_WTAI_TEL_IND. */
    kal_uint16	error_code;     /* The result of the requested telephony operation. See Plug-in Error Codes. */
} wap_bam_wtai_tel_rsp_struct;

/* Local parameter of MSG_ID_WAP_BAM_WTAI_PB_IND */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32	instance_id;                              /* The instance id sent in the message MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_uint16	request_id;                             /* A unique ID for BAM to keep track of the requests. */
    char 	name[WAP_BAM_MAX_USER_PASSWD_LENGTH + 1];     /* The name to associate with the entry and may be an empty string. */
    char 	number[WAP_BAM_MAX_PHONE_NUMBER_LENGTH + 1];  /* The phone number to associate with the entry. Must be a phone-number as defined in [FORMAT] */
} wap_bam_wtai_pb_ind_struct;

/* Local parameter of MSG_ID_WAP_BAM_WTAI_PB_RSP */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint16	request_id;     /* Identifier to map request/response, this id is returned in the response message MSG_ID_WAP_BAM_WTAI_PB_RSP. */
    kal_uint16	error_code;     /* The result of adding the new phone-book entry. See Plug-in Error Codes. */
} wap_bam_wtai_pb_rsp_struct;

/* Local parameter of MSG_ID_WAP_BAM_URI_REQUEST_IND */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32	instance_id;                          /* The instance id sent in the message MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_uint16	request_id;                         /* A unique ID for BAM to keep track of the requests. */
    char	scheme[WAP_BAM_MAX_SCHEME_LENGTH + 1];    /* The scheme of the URI request. */
    char 	param[WAP_BAM_MAX_URL_LEN + 1];           /* The input parameter along with the URI request. */
} wap_bam_uri_request_ind_struct;

/* Local parameter of MSG_ID_WAP_BAM_URI_REQUEST_RSP */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint16	request_id;     /* Identifier to map request/response, this id is returned in the response message MSG_ID_WAP_BAM_URI_REQUEST_RSP. */
    kal_uint16	error_code;     /* The result of handling the URI request. See Plug-in Error Codes. */
} wap_bam_uri_request_rsp_struct;

/* Local parameter of MSG_ID_WAP_BAM_BEARER_INFO_IND */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32	instance_id;      /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_uint16	bearer_type;    /* This indicates the bearer type is GPRS or CSD. */
    kal_uint16	bearer_state;   /* This indicates the bearer status, e.g. connected or un-available. */
} wap_bam_bearer_info_ind_struct;

/* Local parameter of MSG_ID_WAP_BAM_REGISTER_KEYPAD_HANDLER_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;    /* The calling module id. */
    kal_int32	instance_id;  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when the Browser Engine instance was created. */
} wap_bam_register_keypad_handler_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_HANDLE_PEN_EVENT_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;    /* The calling module id. */
    kal_int32	instance_id;  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when the Browser Engine instance was created. */
    kal_int16   pos_x;      /* The x position of the pen event. */
    kal_int16   pos_y;      /* The y position of the pen event. */
    kal_int32   type;       /* The type of pen event. Defined in mmi_pen_event_type_enum. */
} wap_bam_handle_pen_event_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_SUSPEND_OWL_RENDERING_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;    /* The calling module id. */
    kal_int32	instance_id;  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when the Browser Engine instance was created. */
} wap_bam_suspend_owl_rendering_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_RESUME_OWL_RENDERING_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;    /* The calling module id. */
    kal_int32	instance_id;  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when the Browser Engine instance was created. */
} wap_bam_resume_owl_rendering_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_NOTIFY_SCREEN_INFO_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_uint8	source_id;            /* The calling module id. */
    kal_int32	instance_id;          /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when the Browser Engine instance was created. */
    kal_uint32	x;                  /* The x-position of the upper left corner of the rendered page area. */
    kal_uint32	y;                  /* The y-position of the upper left corner of the rendered page area. */
    kal_uint32	w;                  /* The width of the rendered page area. */
    kal_uint32	h;                  /* The height of the rendered page area. */
    kal_int32	category_lyr_a_hndl;  /* GDI Layer A (like, for top area) using by category screen. */
    kal_int32	category_lyr_b_hndl;  /* GDI Layer B (like, for bottom area) using by category screen. */
} wap_bam_notify_screen_info_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_WAIT_USER_ACTION_IND */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32	instance_id;                                      /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when the Browser Engine instance was created. */
    kal_bool	enable_positive_sk;                               /* Enable positive softkey or not. */
    kal_bool	enable_negative_sk;                               /* Enable negative softkey or not. */
    kal_int32	positive_label_len;                               /* The label length of positive softkey. */
    kal_int32	negative_label_len;                               /* The label length of negative softkey. */
    char        positive_label[WAP_BAM_MAX_TITLE_LABEL_LENGTH + 1]; /* The label of positive softkey. If ¡§enable_positive_sk¡¨ is FALSE, this label must be ignored. */
    char        negative_label[WAP_BAM_MAX_TITLE_LABEL_LENGTH + 1]; /* The label of negative softkey. If ¡§enable_negative_sk¡¨ is FALSE, this label must be ignored. */
} wap_bam_wait_user_action_ind_struct;

/* Local parameter of MSG_ID_WAP_BAM_WAIT_USER_ACTION_RSP */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32	instance_id;          /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when the Browser Engine instance was created. */
    kal_bool	press_positive_sk;    /* User presses the positive softkey or not. */
} wap_bam_wait_user_action_rsp_struct;

/* Local parameter of MSG_ID_WAP_BAM_OBJECT_ACTION_REQ */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32	instance_id;  /* The instance id sent in the signal MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when the Browser Engine instance was created. */
    kal_uint8	source_id;    /* The calling module id. */
    kal_int16	type;         /* The type of the focused page object sent in MSG_ID_WAP_BAM_ELEMENT_FOCUSED_IND. One of the selectable elements type. See Selectable Elements Type Constants. */
} wap_bam_object_action_req_struct;

/* Local parameter of MSG_ID_WAP_BAM_SHOW_AUTH_DIALOG_IND */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32	instance_id;                                  /* The instance id sent in the message MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_int32	request_id;                                   /* Identifier to map request/response, this id is returned in the response message MSG_ID_WAP_BAM_SHOW_AUTH_DIALOG_RSP. */
    kal_int32	auth_type;                                    /* Authorization Type: server or proxy. Please refer to Authorization Type Constants. */
    char 	realm[WAP_BAM_MAX_REALM_LENGTH + 1];              /* The realm value of the protection space. */
    char 	username[WAP_BAM_MAX_USER_PASSWD_LENGTH + 1];     /* The initial username if any. */
    char 	password[WAP_BAM_MAX_USER_PASSWD_LENGTH + 1];     /* The initial password if any. */
} wap_bam_show_auth_dialog_ind_struct;

/* Local parameter of MSG_ID_WAP_BAM_SHOW_AUTH_DIALOG_RSP */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32	instance_id;                                  /* The instance id sent in the message MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_int32	request_id;                                   /* Identifier to map request/response, this id is sent in the message MSG_ID_WAP_BAM_SHOW_AUTH_DIALOG_REQ. */
    kal_uint16	options;                                    /* Authorization Options. Please refer to Authorization Option Constants. */
    char 	username[WAP_BAM_MAX_USER_PASSWD_LENGTH + 1];     /* The username that the user inputs. */
    char 	password[WAP_BAM_MAX_USER_PASSWD_LENGTH + 1];     /* The pssword that the user inputs. */
} wap_bam_show_auth_dialog_rsp_struct;

typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32	instance_id;                                  /* The instance id sent in the message MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
} wap_bam_conn_closed_by_net_acc_id_req_struct;

typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32	instance_id;                                  /* The instance id sent in the message MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
} wap_bam_conn_closed_by_net_acc_id_rsp_struct;

/* Local parameter of MSG_ID_WAP_BAM_NOTIFY_APP_IND */
typedef struct
{
	LOCAL_PARA_HDR
    wap_bam_notify_app_enum type;
    char title[WAP_BAM_MAX_TITLE_LABEL_LENGTH + 1];
} wap_bam_notify_app_ind_struct;


typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32	instance_id;                                  /* The instance id sent in the message MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
} wap_bam_bearer_open_ind_struct;


typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    LOCAL_PARA_HDR
    /* DOM-NOT_FOR_SDK-END */
    kal_int32	instance_id;                                  /* The instance id sent in the message MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF when this BAM instance was created. */
    kal_uint16	error_code;
} wap_bam_bearer_open_response_rsp_struct;


//#endif	/* End of __OBIGO_Q05A__ */
/* WAP BAM SAP End */

#endif	/* End of _BAM_STRUCT_H */
