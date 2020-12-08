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
 * BrowserSrvProts.h
 *
 * Project:
 * --------
 *   MAUI
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
*------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifndef MMI_BROWSERSRVPROTS_H
#define MMI_BROWSERSRVPROTS_H

#ifdef __MMI_BROWSER_2__

/*********************************************HEADERS START********************************************/

#include "app_ltlcom.h"
#include "Bam_struct.h"         /* for bam related APIs and structures in both Q05A and Q03C */
#include "BrowserSrvConfig.h"
#include "custom_nvram_editor_data_item.h"  /* for nvram related macros enums and structures */

#include "common_nvram_editor_data_item.h"
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
#include "DLAgentSrvDef.h"         /* for the DLAGENTS structures  */
#endif /* __MMI_DOWNLOAD_AGENT_MULTI_DL__ */

#include "BrowserSrvBookmarks.h"    /* for various bookmark related structures and macros etc */
#include "BrowserSrvConfig.h"       /* for the memory macros and the feature compile options */
#include "nvram_common_defs.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "WAPProfileSrvType.h"
#include "app_datetime.h"
#include "kal_public_defs.h"
#include "FileMgrSrvGProt.h"
#include "wap_adp.h"
/*********************************************HEADERS END********************************************/


/*********************************************MACROS START********************************************/
#define SRV_BRW_MAX_URL_LENGTH                255
#define SRV_BRW_MAX_TITLE_LENGTH              WAP_BAM_MAX_TITLE_LABEL_LENGTH
#define SRV_BRW_ADDRESS_LIST_MAX_ITEMS        NVRAM_BRW_MAX_ADDRESS_HISTORY
#define SRV_BRW_ADDRESS_LIST_TITLE_LENGTH     NVRAM_BRW_ADDRESS_HISTORY_MAX_TITLE_LENGTH
#define SRV_BRW_ADDRESS_LIST_URL_LENGTH       NVRAM_BRW_ADDRESS_HISTORY_MAX_URL_LENGTH

#ifdef __GOOGLE_SEARCH_SUPPORT__
    #define SRV_BRW_GOOGLE_SEARCH_BEGINING_STRING        "http://www.google.com/m/search?client=ms-mtk&q="
#else
    #ifdef __MMI_SEARCH_WEB_BAIDU__
        #define SRV_BRW_GOOGLE_SEARCH_BEGINING_STRING        "http://www.google.com/m/search?client=ms-mtk-free&q="
    #else
        #define SRV_BRW_GOOGLE_SEARCH_BEGINING_STRING        "http://www.google.com/m/search?client=ms-mtk&q="
    #endif
#endif

#if defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)
    #define SRV_BRW_SEARCH_ITEM_LENGTH            (NVRAM_BRW_SEARCH_ITEM_MAX_LENGTH - 1)
    #define SRV_BRW_SEARCH_LIST_MAX_ITEMS      CUSTOM_WAP_CFG_SEARCH_ITEMS_COUNT
#else
    #define SRV_BRW_SEARCH_ITEM_LENGTH            150
#endif

#ifdef __COSMOS_MMI_PACKAGE__
#define SRV_BRW_GLOBAL_SHORTCUT_MULTIPLIER      0.8
#define SRV_BRW_GLOBAL_SHORTCUTS_LIST_MAX_ITEMS    CUSTOM_WAP_CFG_N_NBR_GLOBAL_SHORTCUTS
#ifndef __MMI_BRW_SLIM__
#define SRV_BRW_LOCAL_SHORTCUTS_LIST_MAX_ITEMS    CUSTOM_WAP_CFG_N_NBR_LOCAL_SHORTCUTS
#endif

#define SRV_BRW_BAIDU_SEARCH_BEGINING_STRING        "http://m.baidu.com/ssid=0/from=844b/bd_page_type=0/uid=wiaui_1290146670_8061/s?tn=webmain&pu=&word="
#define SRV_BRW_BAIDU_SEARCH_ENDING_STRING          "&st=111041"

#define SRV_BRW_YAHOO_SEARCH_BEGINING_STRING        "http://m.yahoo.com/w/search%3B_ylt=A2KIP6t2EeZMSBAAIADI5dw4?p="
#define SRV_BRW_YAHOO_SEARCH_ENDING_STRING          "&submit=oneSearch&.tsrc=yahoo&.ysid=UIGvwMrDVq1psKXanswsrCu4&.intl=in$.lang=en-in&.sep=fp"

#define SRV_BRW_BING_SEARCH_BEGINING_STRING        "http://mindia.bing.com/search/CommonPage.aspx?q="
#define SRV_BRW_BING_SEARCH_ENDING_STRING          "&d=allloc&dl=&a=results&MID=10006"
#endif /* __COSMOS_MMI_PACKAGE__ */

#ifdef BRW_MEM_LEAK_DEBUG_MODE
extern void *srv_brw_malloc_ex(U32 mem_size, S8 *filename, U32 line_num);
#define srv_brw_malloc(size)				  srv_brw_malloc_ex(size, __FILE__, __LINE__)
#else
extern void *srv_brw_malloc_ex(U32 mem_size);
#define srv_brw_malloc(size)				  srv_brw_malloc_ex(size)
#endif /* BRW_MEM_LEAK_DEBUG_MODE */
#define SRV_BRW_LAST_WEB_ADDR_LENGTH		  NVRAM_EF_BRW_LAST_WEB_ADDR_SIZE
#define SRV_BRW_MAX_TITLE_LENGTH			  WAP_BAM_MAX_TITLE_LABEL_LENGTH   /* NVRAM_BRW_ADDRESS_HISTORY_MAX_TITLE_LENGTH */
#define SRV_BRW_APPLICATION_ID				  30
#define SRV_BRW_DCS_ASCII					  0x00
#define SRV_BRW_DCS_UCS						  0x01
#define SRV_BRW_PROXY_GATEWAY_STR_LEN		  50
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
#define SRV_BRW_RECENT_PAGES_COUNT			  30
#endif
#define SRV_BRW_PEER_BUFF_TITLE_LEN_BYTES_COUNT  4
#define SRV_BRW_PEER_BUFF_OBJ_TYPE_LEN_BYTES_COUNT  4
#ifdef WAP_SEC_SUPPORT
#define SRV_BRW_MAX_TRUSTED_CERTIFICATES	  255
#endif
#define SRV_BRW_DEFAULT_URI_SCHEME            "http://" 
#define SRV_BRW_OPERATOR_DEFAULT_PROF_INDEX    0
#define SRV_BRW_BKM_DRIVE_NAME_LENGTH          5
#ifdef OBIGO_Q05A
#define SRV_BRW_WTAI_MAKE_CALL_PREFIX         "wtai://wp/mc;"
#define SRV_BRW_WTAI_SEND_DTMF_PREFIX         "wtai://wp/sd;"
#define SRV_BRW_WTAI_ADD_TO_PHONEBOOK_PREFIX  "wtai://wp/ap;"
#endif /* OBIGO_Q05A */

#define SRV_BRW_MAX_CONTROL_BUFFER_SIZE       2048
#ifdef __MMI_OP12_BRW_CLEAR_DATA_ON_SIM_CHANGE__
#define SRV_BRW_RSP_CALLBACK_COUNT            6
#else
#define SRV_BRW_RSP_CALLBACK_COUNT            5
#endif
#ifdef __MMI_Q05A_LAUNCH_SCREEN__
#define SRV_BRW_MAX_SHORTCUTS_COUNT CUSTOM_WAP_CFG_N_NBR_SHORTCUTS
#endif
/*********************************************MACROS END********************************************/

/*********************************************ENUMS START********************************************/

extern void	*g_srv_brw_memory_pool;

typedef enum
{
    SRV_BRW_SEARCH_ENGINE_BAIDU = 0,
    SRV_BRW_SEARCH_ENGINE_GOOGLE,
    SRV_BRW_SEARCH_ENGINE_YAHOO,
    SRV_BRW_SEARCH_ENGINE_BING,
    SRV_BRW_SEARCH_ENGINE_TOTAL
} srv_brw_search_engines_enum;

#ifdef __COSMOS_MMI_PACKAGE__
typedef enum
{
    SRV_BRW_RECENT_PAGES_DAY_TODAY = 0,
    SRV_BRW_RECENT_PAGES_DAY_YESTERDAY,
    SRV_BRW_RECENT_PAGES_DAY_BEFORE_YESTERDAY,
    SRV_BRW_RECENT_PAGES_DAY_ALL
} srv_brw_recent_pages_day_enum;

typedef enum
{
    SRV_BRW_RECENT_PAGES_DELETE_TODAYS = 0,
    SRV_BRW_RECENT_PAGES_DELETE_LAST_TWO_DAYS,
    SRV_BRW_RECENT_PAGES_DELETE_END
} srv_brw_recent_pages_delete_enum;

#endif /* __COSMOS_MMI_PACKAGE__ */

#ifdef OBIGO_Q05A
typedef enum
{
    SRV_BRW_PAGE_OBJECT_TYPE_IMAGE = 0,
    SRV_BRW_PAGE_OBJECT_TYPE_BG_IMAGE,
    SRV_BRW_PAGE_OBJECT_TYPE_SOUNDS,
    SRV_BRW_PAGE_OBJECT_TYPE_OTHERS,
    SRV_BRW_PAGE_OBJECT_TYPES_COUNT
} srv_brw_page_object_types_enum;
#endif /* OBIGO_Q05A */

typedef enum
{
    SRV_BRW_ACTIVE_SIM_SETTING_SIM1 = 1,
    SRV_BRW_ACTIVE_SIM_SETTING_SIM2,
#if (MMI_MAX_SIM_NUM >= 2)
    SRV_BRW_ACTIVE_SIM_SETTING_SIM3,
#endif
#if (MMI_MAX_SIM_NUM >= 2)
    SRV_BRW_ACTIVE_SIM_SETTING_SIM4,
#endif
#ifdef __MMI_WLAN_FEATURES__
    SRV_BRW_ACTIVE_SIM_SETTING_WLAN,
#endif /* __MMI_WLAN_FEATURES__ */
    SRV_BRW_ACTIVE_SIM_SETTING_TOTAL
} srv_brw_active_sim_setting_enum;


#define    SRV_BRW_IND_ALL_RECEIVED  (MMI_MAX_SIM_NUM + 1)

#ifdef __SAT__
typedef enum
{
    SRV_BRW_SAT_LAUNCH_SUCCESS,
    SRV_BRW_SAT_BROWSER_BUSY,
    SRV_BRW_SAT_BEARER_UNAVAIL,
    SRV_BRW_SAT_PARAM_GATEWAY_ERR,
    SRV_BRW_SAT_PARAM_URL_ERR,
    SRV_BRW_SAT_PROV_DATA_ERR,
    SRV_BRW_SAT_UNKNOWN_ERR,

    SRV_BRW_SAT_TOTAL_ERR
} brw_sat_launch_browser_res_enum;

typedef enum
{
    SRV_BRW_SAT_USER_TERMINATION,
    SRV_BRW_SAT_ERROR_TERMINATION
} brw_sat_browser_termination_mode_enum;
#endif /* __SAT__ */ 

typedef enum
{
    SRV_BRW_LIST_ACTION_UPDATE_ENTIRE_LIST = 0,
    SRV_BRW_LIST_ACTION_UPDATE_TITLE_ONLY,

    SRV_BRW_LIST_ACTION_TOTAL
} srv_brw_list_action_enum;

typedef enum
{
    SRV_BRW_PROFILE_TYPE_NONE = 0,
#ifdef __SAT__
    SRV_BRW_PROFILE_TYPE_SAT,
#endif 
    SRV_BRW_PROFILE_TYPE_OPERATOR,

    SRV_BRW_PROFILE_TYPE_END
} srv_brw_profile_type_enum;


typedef enum
{
    SRV_BRW_LIST_TYPE_ADDRESS_LIST = 0,
    SRV_BRW_LIST_TYPE_DYNAMIC_LIST,
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
	SRV_BRW_LIST_TYPE_RECENT_PAGES_LIST,
#endif
#ifdef OBIGO_Q05A
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
	SRV_BRW_LIST_TYPE_RECENT_PAGES_HOST_LIST,
#endif
	SRV_BRW_LIST_TYPE_PAGE_OBJECTS_LIST,
#endif /* OBIGO_Q05A */
#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
    SRV_BRW_LIST_TYPE_SAVED_PAGES_LIST,
#endif
#if defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)
    SRV_BRW_LIST_TYPE_SEARCH_LIST,
#endif
#ifdef __COSMOS_MMI_PACKAGE__
    SRV_BRW_LIST_TYPE_GLOBAL_SHORTCUTS,
#ifndef __MMI_BRW_SLIM__
    SRV_BRW_LIST_TYPE_LOCAL_SHORTCUTS,
#endif
#endif /* __COSMOS_MMI_PACKAGE__ */
#ifdef __MMI_Q05A_LAUNCH_SCREEN__
    SRV_BRW_LIST_TYPE_SHORTCUT_LIST,
#endif
    SRV_BRW_LIST_TYPE_END
} srv_brw_list_type_enum;

typedef enum
{
    SRV_BRW_NVRAM_SETTINGS_RENDER_MODE = 0,
	SRV_BRW_NVRAM_SETTINGS_NAVIGATE_MODE,
	SRV_BRW_NVRAM_SETTINGS_THUMBNAIL,
	SRV_BRW_NVRAM_SETTINGS_SCREEN_SIZE,
#ifdef __MMI_VECTOR_FONT_SUPPORT__
	SRV_BRW_NVRAM_SETTINGS_FONT_SIZE,
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */
	SRV_BRW_NVRAM_SETTINGS_ENCODE_METHOD_INDEX,
#ifdef OBIGO_Q05A
	SRV_BRW_NVRAM_SETTINGS_SHOW_VIDEO,
	SRV_BRW_NVRAM_SETTINGS_PLAY_SOUND,
	SRV_BRW_NVRAM_SETTINGS_LOAD_UNKOWN_MEDIA,
	SRV_BRW_NVRAM_SETTINGS_CSS,
	SRV_BRW_NVRAM_SETTINGS_SCRIPTS,
#endif /* OBIGO_Q05A */
	SRV_BRW_NVRAM_SETTINGS_CACHE,
	SRV_BRW_NVRAM_SETTINGS_COOKIE,
	SRV_BRW_NVRAM_TIMEOUT_VALUE,
	SRV_BRW_NVRAM_SHOW_IMAGE_MODE,
#ifdef BRW_KEYPAD_SHORTCUTS_SUPPORT
	SRV_BRW_NVRAM_SETTINGS_SHORTCUTS,
#endif /* BRW_KEYPAD_SHORTCUTS_SUPPORT */
#ifdef BRW_SECURITY_WARNINGS_SUPPORT
	SRV_BRW_NVRAM_SETTINGS_SECURITY_WARNINGS,
#endif /* BRW_SECURITY_WARNINGS_SUPPORT */
#ifdef BRW_SEND_DEVICE_ID_SUPPORT
	SRV_BRW_NVRAM_SETTINGS_SEND_DEVICE_ID,
#endif /* BRW_SEND_DEVICE_ID_SUPPORT */
	/* __MMI_BRW_POST_SESSION_INFO__ */ 
#ifdef __MMI_BRW_POST_SESSION_INFO__
	SRV_BRW_NVRAM_SETTINGS_POST_SESSION_INFO,
#endif /* __MMI_BRW_POST_SESSION_INFO__ */
	/* __MMI_BRW_POST_SESSION_INFO__ */
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
#ifdef OBIGO_Q05A
	SRV_BRW_NVRAM_RECENT_PAGES_SORTING_METHOD,
#endif /* #ifdef OBIGO_Q05A */
#endif
    SRV_BRW_NVRAM_SETTINGS_HOMEPAGE,
	SRV_BRW_NVRAM_SETTINGS_SEARCH_ENGINE,
	SRV_BRW_NVRAM_SETTINGS_HISTORY,
	SRV_BRW_NVRAM_SETTINGS_PRIVATE_MODE,
#if 0
/* under construction !*/
#endif //0
#ifdef __BAIDU_TRANSCODING_SUPPORT__
    SRV_BRW_NVRAM_SETTINGS_BAIDU_PROXY,
#endif // #ifdef __BAIDU_TRANSCODING_SUPPORT__
	SRV_BRW_NVRAM_ITEM_TOTAL
} srv_brw_nvram_item_enum;

typedef enum
{
    SRV_BRW_HOMEPAGE_SETTING_DEFAULT = 0,
    SRV_BRW_HOMEPAGE_SETTING_USER_DEFINED,

    SRV_BRW_HOMEPAGE_SETTING_TOTAL
} srv_brw_homepage_setting_enum;

#ifdef __COSMOS_MMI_PACKAGE__
typedef enum
{
    SRV_BRW_REQ_INITIALIZE_ASM_POOL = 1,
    SRV_BRW_REQ_END
} srv_brw_req_enum;
#endif

#ifdef MMI_BRW_BEARER_SWITCH_SUPPORT
typedef enum
{
    SRV_BRW_LAUNCH_URL = 0,
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
    SRV_BRW_LAUNCH_RECENT_PAGE,
#endif
    SRV_BRW_LAUNCH_STORED_PAGE,
    SRV_BRW_LAUNCH_OPEN_FILE,
    SRV_BRW_LAUNCH_REFRESH,
#ifdef __COSMOS_MMI_PACKAGE__
    SRV_BRW_LAUNCH_SHORTCUT,
#endif
    SRV_BRW_LAUNCH_NONE,
    SRV_BRW_LAUNCH_END
} srv_brw_launch_type_enum;
#endif

#if (defined(__SAT__) && defined(__MMI_WLAN_FEATURES__))
typedef enum
{
    SRV_BRW_APPTYPE_NONE = 0, /* No change*/
    SRV_BRW_APPTYPE_WIFI, /* allow wlan prefer on browser*/
    SRV_BRW_APPTYPE_NO_WIFI, /* do not allow wlan prefer on browser*/
    SRV_BRW_APPTYPE_TOTAL
} srv_brw_apptype_enum;
#endif

/*********************************************ENUMS END********************************************/


/*********************************************STRUCT START********************************************/

typedef struct {
	kal_int32	document_bytes_read;/* Number of bytes received of the documents downloaded during the transaction. */
	kal_int16	document_number_of_requested;     /* Number or requested documents. */
    kal_int16	document_number_of_downloaded;    /* Number of downloaded documents. */
    kal_int16	document_number_of_failed;        /* Number of failed document downloads. */
    kal_int32	resources_bytes;                  /* Number of bytes received from downloaded resources during the transaction. */
    kal_int16	resources_number_of_requested;    /* Number of requested resources. */
}srv_brw_rendering_status_struct;


typedef struct {
    MMI_EVT_PARAM_HEADER
    void* url_string; /* Rendering status */
} srv_brw_uri_req_event_struct;

typedef struct {
	MMI_EVT_PARAM_HEADER
	U8 browserMode;
    srv_brw_active_sim_setting_enum sim_setting;
	S8* url;
} srv_brw_sat_launch_req_struct;

typedef struct {
	MMI_EVT_PARAM_HEADER
	U8 error_code;
} srv_brw_show_popup_event_struct;

typedef struct {
    MMI_EVT_PARAM_HEADER
    U8 req_type;
    void* url_ucs2; /* Rendering status */
} srv_brw_startup_req_event_struct;

typedef struct {
    MMI_EVT_PARAM_HEADER
    U16 status; /* Rendering status */
    void *ptr; /* Data pointer */
} srv_brw_rendering_status_event_struct;

typedef struct {
    MMI_EVT_PARAM_HEADER
    void *data_ptr; /* Data pointer */
} srv_brw_confirm_action_event_struct;

typedef struct {
    MMI_EVT_PARAM_HEADER
    U16 error_code; /* Data pointer */
} srv_brw_rendering_error_event_struct;

typedef void (*srv_brw_rsp_funcptr_type)(S32 user_data, U32 result, void *rsp_data);
typedef struct
{
    U32							user_data;
    srv_brw_rsp_funcptr_type	rsp_callback;
    void*						req_data;
} srv_brw_act_req_struct;

typedef struct
{
    U16 msg_id;
    srv_brw_act_req_struct srv_brw_rsp_cntx_p;
} srv_brw_rsp_callback_struct;

typedef struct {
    U32 index;
} srv_brw_list_element_req_struct;

typedef struct {
	U32 index;
    U8* page_label;
} srv_brw_stored_page_operation_req_struct;

typedef struct {
    GDI_HANDLE title_layer;
    GDI_HANDLE bottom_layer;
    U32 x;
    U32 y;
    U32 w;
    U32 h;
} srv_brw_screen_info_struct;

typedef struct
{
	/* Number of bytes uploaded to the server during the transaction. */
	kal_int32	upload_bytes_sent;
	/* Total number of bytes to be uploaded to the server during the
	   transaction. */
	kal_int32	upload_bytes_total;
	/* Expected total number of bytes to be received of the documents
	   downloaded during the transaction. */
	kal_int32	document_bytes_total;
    /* Number of downloaded resources. */
    kal_int16	resources_number_of_downloaded;   
    /* Number of failed resource downloads. */
    kal_int16	resources_number_of_failed;
     
} srv_brw_status_ind_struct;

#ifdef OBIGO_Q05A
typedef struct
{
	kal_int32	size;
	char	    title[WAP_BAM_MAX_TITLE_LABEL_LENGTH + 1];
	char	    cache_file[WAP_BAM_MAX_FILE_PATH_LEN + 1];
} srv_brw_resource_item_struct;
#endif /* OBIGO_Q05A */

typedef struct
{
    U8 *name;
    U8 *host;
    U32 type;
} srv_brw_dynamic_list_struct;

typedef struct
{
    U8 *name;
} srv_brw_saved_page_list_struct;

typedef struct
{
    srv_wap_prof_profile_content_struct *currprof;
    U16 setting_id;
    wap_bam_set_profile_option_enum type;
} srv_brw_set_profile_req_struct;

#ifndef SLIM_WAP_MMS
typedef struct
{
	/* Unique ID, used in MSG_ID_WAP_BAM_ACTIVATE_DO_ELEMENT_REQ */
	kal_int32   element_id;
	/* Event type, "accept", "prev", etc. */
    char        event_type[WAP_BAM_MAX_TITLE_LABEL_LENGTH + 1];

	/* Label, an attribute in the DO-element */
	char        label[WAP_BAM_MAX_TITLE_LABEL_LENGTH + 1];
} srv_brw_do_element_struct;
#endif

typedef struct
{
	kal_int32	instance_id;
	/* Indicates the history navigation possibilities for this document; see
	   Section 5.6 Info Flags. */
	kal_int16	flags;
	/* The protocol used for loading the document, see Section 5.8 Protocols. */
	kal_int16	protocol;
	/* Size in bytes for this document. */
	kal_int32	size;
    /* The Security Id for the secure connection, if any. */
    kal_int32	security_id;                              
	/* The url of the document. */
	char 	url[WAP_BAM_MAX_URL_LEN + 1];
	/* The document title. */
	char 	title[WAP_BAM_MAX_TITLE_LABEL_LENGTH + 1];
    
} srv_brw_document_info_ind_struct;

typedef struct
{
	kal_int32	instance_id;
	/* One of the WAP_BAM_FOCUSED_ELEMENT_ types. See Section 5.7 Focusable
       Elements. */
	kal_int16	type;
	/* The size in bytes of the object. */
	kal_int32	size;
	/* The title attribute of the element, if any. */
	char 	title[WAP_BAM_MAX_TITLE_LABEL_LENGTH + 1];
	/* The URL of the href attribute for links (<a> and <anchor> elements). */
	char 	url[WAP_BAM_MAX_URL_LEN + 1];
	/* The cache file of the embedded object, if any. */
	char 	object_filePath[WAP_BAM_MAX_FILE_PATH_LEN + 1];
} srv_brw_element_focused_ind_struct;


#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
typedef struct
{
    U16 actual_index;
} srv_brw_recent_page_list_struct;
#endif

#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
typedef struct
{
	kal_uint32	date;		/* The created date of the saved page. */
	kal_uint32	data_size;	/* The total data size of the saved page. */

	/* The label of the saved page. */
	char	label[WAP_BAM_MAX_TITLE_LABEL_LENGTH + 1];
	char	url[WAP_BAM_MAX_URL_LEN + 1];	/* The URL of the saved page. */
} srv_brw_saved_page_struct;
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */

#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
typedef struct
{
	char	title[WAP_BAM_MAX_TITLE_LABEL_LENGTH + 1];
	char	url[WAP_BAM_MAX_URL_LEN + 1];
} srv_brw_recent_page_struct;
#endif

typedef struct
{
	U16 num_count;
} srv_brw_list_rsp_struct;
/* Structure for both the current certificate and trusted certificate */

typedef struct
{
   kal_uint8 total;
   kal_uint32 cert_ids[256];
} srv_brw_get_cert_ids_rsp_struct;

#ifdef OBIGO_Q05A
typedef struct
{
    U32 res_list_index;
} srv_brw_page_object_struct;
#endif /* OBIGO_Q05A */

typedef struct
{
	kal_int32	instance_id;
	/* Identifier to map request/response. */
	kal_int32	request_id;
	/* Authorization Type: server or proxy. 
	   Please refer to "Authorization Type Constants". */
	kal_int32	auth_type; 
	char 	username[WAP_BAM_MAX_USER_PASSWD_LENGTH + 1];
	char 	password[WAP_BAM_MAX_USER_PASSWD_LENGTH + 1];
} srv_brw_show_auth_dialog_ind_struct;


#ifdef MMI_BRW_BEARER_SWITCH_SUPPORT
typedef struct
{
    srv_brw_launch_type_enum	launch_type;
    kal_int32	page_id; /* recent page, stored page or global shortcut ID */
    U8 *data; /* URL or file path*/
    MMI_BOOL is_switching_bearer; /* to check if bearer switch is happening or not */
} srv_brw_relaunch_struct;
#endif


/* Browser DynamicContext Structure */
typedef struct
{
	MMI_BOOL isBrowserFetching;
    MMI_BOOL isDeleteInsReqPending;//srv
    MMI_BOOL is_holding_bearer;//srv
    MMI_BOOL ext_obj_trans_status;//srv
    MMI_BOOL is_bearer_active;//srv
#ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__
	MMI_BOOL address_list_flag;
	U8 total_address_list_items; //srv
#endif /* __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__ */
	MMI_BOOL view_cert_flag;
	MMI_BOOL need_bearer_release;
#ifdef OBIGO_Q05A
    MMI_BOOL brw_page_object_type[SRV_BRW_PAGE_OBJECT_TYPES_COUNT];//srv
#endif /* OBIGO_Q05A */
    
    U8 selected_page_object_type;//srv
#ifndef SLIM_WAP_MMS
    U16 do_element_count; //srv
#endif
    U16 page_objs_images_count; //srv
    U16 page_objs_bg_images_count;//srv
    U16 page_objs_sounds_count;//srv
    U16 page_objs_others_count;//srv
    U16 sap_request_id;//srv
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
    U16 recent_page_count;//srv
    U16 recent_page_host_count;//srv
    S16 recent_page_host_delete_count;//srv
#endif
    U32 dynamic_list_count;//srv
/* saving the last certificate ID before sending the MSG_ID_WPS_SEC_GET_CERT_REQ
   b'cos in case of corrupted certificate MSG_ID_WPS_SEC_GET_CERT_RSP returns NULL 
   certificate ID which is Telica's bug */
#ifdef WAP_SEC_SUPPORT
    U32 req_cert_id;//srv
#endif 

#ifdef __MMI_BRW_POST_SESSION_INFO__
    U64 total_bytes_downloaded; //srv
    U64 total_bytes_uploaded; //srv
#endif /* __MMI_BRW_POST_SESSION_INFO__ */ 
#ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__
    nvram_brw_hist_title_struct *address_list_title_p; //srv  /* it is saved as Ascii or Unicode in NVRAM depending on its content */
    nvram_brw_hist_url_struct *address_list_url_p;//srv      /* it is saved as Ascii in NVRAM */
#endif /* __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__ */
    srv_brw_status_ind_struct *brw_status_info_p;//srv

#if defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)
    U8 total_search_list_items; //srv
    nvram_brw_search_item_struct *search_items_list_p;
    U8 *matched_search_items_list; // srv
    U8 total_matched_search_items; //srv
#endif /* #if defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__) */
#ifdef __COSMOS_MMI_PACKAGE__
    U8 *matched_bookmark_items_list; // srv
    U8 total_matched_bookmark_items; //srv
    U8 total_global_list_items; //srv
#ifndef __MMI_BRW_SLIM__
    U8 total_local_list_items; //srv
#endif
    nvram_brw_global_shortcuts_item_struct *global_shortcuts_p;
#ifndef __MMI_BRW_SLIM__
    nvram_brw_local_shortcuts_item_struct *local_shortcuts_p;
#endif
    U8 launched_global_shortcut_index;
    MMI_BOOL global_shortcut_item_flag;
#ifndef __MMI_BRW_SLIM__
    MMI_BOOL local_shortcut_item_flag;
#endif
#endif /* __COSMOS_MMI_PACKAGE__ */
#ifdef OBIGO_Q05A
    srv_brw_resource_item_struct *brw_res_item_info_p; //srv
#endif /*#ifdef OBIGO_Q05A */
    srv_brw_dynamic_list_struct *dynamic_list;//srv
#ifndef SLIM_WAP_MMS
    srv_brw_do_element_struct *do_element_list;//srv
#endif
	/******************* srv begin ***********/
    srv_brw_document_info_ind_struct *document_info_p;
    srv_brw_element_focused_ind_struct *focused_element_info_p;
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
#ifdef OBIGO_Q05A
    U8 **recent_page_host_list;
#endif /* OBIGO_Q05A */
    srv_brw_recent_page_list_struct *recent_page_list;
#endif
#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
    U8 saved_page_list_item_count;
    srv_brw_saved_page_list_struct *saved_pages_list_p;
    srv_brw_saved_page_struct *saved_page_properties_p;
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
    srv_brw_recent_page_struct *recent_page_info_p;
#endif
#ifdef WAP_SEC_SUPPORT
    srv_brw_get_cert_ids_rsp_struct trusted_cert_ids;
#endif /* WAP_SEC_SUPPORT */ 
#ifdef OBIGO_Q05A
    U16 wtai_tel_operation;
#endif /* OBIGO_Q05A */
	/******************* srv end ***********/
#ifdef __MMI_BRW_URL_AUTO_COMPLETION__
    U8 *matched_items_list; // srv
    U8 total_matched_items; //srv
#endif /* __MMI_BRW_URL_AUTO_COMPLETION__ */ 
#ifdef OBIGO_Q05A
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
    srv_brw_rsp_funcptr_type recent_page_host_delete_callback;
#endif
#endif /* OBIGO_Q05A */
#ifdef __MMI_BRW_POST_SESSION_INFO__
    applib_time_struct *start_session_data_time; //srv
#endif
#ifdef OBIGO_Q05A
    srv_brw_page_object_struct *brw_page_objs_image_list; //srv
    srv_brw_page_object_struct *brw_page_objs_bg_image_list;//srv
    srv_brw_page_object_struct *brw_page_objs_sound_list;//srv
    srv_brw_page_object_struct *brw_page_objs_others_list;//srv
#endif /* OBIGO_Q05A */
	/* Venus changes */
#ifdef __COSMOS_MMI_PACKAGE__
    MMI_BOOL select_mode_flag;
    MMI_BOOL stopped_by_asm;
#endif /* __COSMOS_MMI_PACKAGE__ */
#ifdef MMI_BRW_BEARER_SWITCH_SUPPORT
    srv_brw_relaunch_struct relaunch_info;
    MMI_BOOL is_closing_sockets;
#endif
    MMI_BOOL is_activating_wifi;
#ifdef __GOOGLE_SEARCH_SUPPORT__
    MMI_BOOL is_scripts_warning_disabled;
#endif
#ifdef __MMI_Q05A_LAUNCH_SCREEN__
    nvram_brw_shortcuts_item_struct *shortcuts_p;
#endif
} srv_brw_dynamic_context_struct;

typedef struct
{
    MMI_BOOL isWapReady; //srv
    MMI_BOOL is_resend_profile_required; //srv
    U8 screen_size_status;
    U8 show_images_status;
    U8 cache_status;
    U8 cookie_status;
    srv_brw_active_sim_setting_enum session_sim_id; //srv
    srv_brw_show_auth_dialog_ind_struct *http_auth_info_p; //srv
    srv_brw_dynamic_context_struct *srv_brw_dynamic_cntx_p;
	srv_brw_profile_type_enum srv_brw_profile_type; 
    KAL_ADM_ID brw_adm_id; //srv
    U16 timeout_value; //srv
    U16 sap_msg_id; //srv
    srv_wap_prof_response_funcptr_type actv_prof_changed_cb; //srv
#ifdef OBIGO_Q05A
    U8 rendering_mode; //srv
    U8 navigation_mode; //srv
    U8 show_videos_status;
    U8 play_sounds_status;
    U8 load_unknown_media_status;
    U8 css_status;
    U8 script_status;
    U8 encoding_method_index; //srv
#endif /* OBIGO_Q05A */
#ifdef __SAT__
    U8 *sat_gateway_ascii; //srv
#endif 
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    mmi_da_download_info_ind_struct *download_info_p; //srv
#endif 
#if (MMI_MAX_SIM_NUM >= 2)
    MMI_BOOL is_profile_req_received; //srv
#endif /* MMI_DUAL_SIM */
    U16 brw_instance_id;
	/******************* srv begin ***********/
#ifdef __MMI_VBOOKMARK__
    U8 default_folder_path[(SRV_BRW_BKM_MAX_PATH_LEN + 1) *ENCODING_LENGTH];
#endif /* __MMI_VBOOKMARK__ */
#ifdef OBIGO_Q05A
    U8 sorting_method; //srv
    U8 thumbnail_status; //srv
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    U8 font_size; //srv
#endif 
#endif /* OBIGO_Q05A */
#ifdef BRW_KEYPAD_SHORTCUTS_SUPPORT
    U8 shortcuts_status;
#endif 
#ifdef BRW_SECURITY_WARNINGS_SUPPORT
    U8 security_warnings_status;
#endif 
#ifdef BRW_SEND_DEVICE_ID_SUPPORT
    U8 send_device_id_status;
#endif 
/**************** srv end ****************/
#ifdef __MMI_BRW_POST_SESSION_INFO__
    MMI_BOOL post_session_info_status; //srv
#endif 
#ifdef __MMI_OP12_BRW_CLEAR_DATA_ON_SIM_CHANGE__
    MMI_BOOL clear_brw_data_flag; //srv
#endif 
    U8 homepage_setting;
    srv_brw_rsp_callback_struct rsp_callback[SRV_BRW_RSP_CALLBACK_COUNT];
#ifdef __COSMOS_MMI_PACKAGE__
	srv_brw_search_engines_enum sel_search_engine;
	U8 history_setting;
	U8 private_mode_setting;
#if 0
/* under construction !*/
#endif //0
	U8 url[(WAP_MAX_SEARCH_URL_LENGTH + 1) * ENCODING_LENGTH];
	U8 option;
#endif
    srv_brw_bkm_bookmark_context_struct *bkm_cntx_p;
    U8 bookmark_count;
#ifdef __BAIDU_TRANSCODING_SUPPORT__
    U8 baidu_proxy_status;
    U8 is_http_conn;
#endif // #ifdef __BAIDU_TRANSCODING_SUPPORT__
    MMI_BOOL is_create_instance_processing;
#if (defined(__SAT__) && defined(__MMI_WLAN_FEATURES__))
    srv_brw_apptype_enum app_type; 
#endif
} srv_brw_context_struct;


/*********************************************STRUCT END********************************************/

/* TODO */
extern MMI_BOOL g_brw_bkm_sel_bkm_pool;

extern srv_brw_context_struct g_srv_brw_cntx;

#ifdef OBIGO_Q03C_BROWSER
extern void wapadp_set_wap_app_mem(void *, kal_bool );
#endif /* OBIGO_Q03C_BROWSER */

#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERSRVPROTS_H */
