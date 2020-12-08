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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
  ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#ifndef DOWNLOAD_AGENT_OMA_H
#define DOWNLOAD_AGENT_OMA_H
//#ifdef __COSMOS_MMI_PACKAGE__
#if defined (__MMI_OMA_DD_DOWNLOAD__)

#ifndef _FILE_MGR_H_
#include "FileMgr.h"
#endif

#ifndef DOWNLOAD_AGENT_DEF_H
#include "DLAgentSrvDef.h"
#endif

#ifndef DOWNLOAD_AGENT_GPROT_H
#include "DLAgentSrvGProt.h"
#endif

#ifndef DOWNLOAD_AGENT_WPS_H
#include "DLAgentSrvWPS.h"
#endif

#ifdef __DRM_SUPPORT__
#ifndef DRM_DEF_H
#include "drm_def.h"
#endif
#endif






    #include "FileMgrGProt.h"
    #include "DLAgentSrvDef.h"
    #include "DLAgentSrvGProt.h"
    #include "DLAgentSrvWPS.h"
    #include "drm_def.h"
    #include "MMIDataType.h"
    #include "app_mine.h"
    #include "DLAgentSrvIProt.h"
    #include "kal_general_types.h"

/****************************************************************************
 * Constants
 ****************************************************************************/

#define DD_VERSION              10
#ifdef __MMI_OMA_DD2_DOWNLOAD__
#define DD2_VERSION             20
#endif


#ifndef SRV_DA_OMA_MAX_ICON_SIZE
#define SRV_DA_OMA_MAX_ICON_SIZE ( 20 * 1024 ) /* Only supports <20k icons */
#endif


#define SRV_DA_OMA_SEND_REPORT_DEFAULT_NUM_TO_TRY  3


/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef enum
{
    /* Standard OMA error types */
    SRV_DA_OMA_SUCCESS                      = 0,
    SRV_DA_OMA_INSUFFICIENT_MEMORY          = -1,
    SRV_DA_OMA_USER_CANCELLED               = -2,
    SRV_DA_OMA_LOSS_OF_SERVICE              = -3,
    SRV_DA_OMA_ATTRIBUTE_MISMATCH           = -4,
    SRV_DA_OMA_INVALID_DESCRIPTOR           = -5,
    SRV_DA_OMA_INVALID_DDVSERSION           = -6,
    SRV_DA_OMA_DEVICE_ABORTED               = -7,
    SRV_DA_OMA_NON_ACCEPTABLE_CONTENT       = -8,
    SRV_DA_OMA_LOADER_ERROR                 = -9,

    /* Extended error types */
    SRV_DA_OMA_UNAUTHORIZED                 = -50,
    SRV_DA_OMA_FILE_ACCESS_ERROR            = -51,

    SRV_DA_OMA_ERROR_END_OF_ENUM
} srv_da_oma_error_enum;


typedef enum
{
    DD_ELEM_TYPE,
    DD_ELEM_OBJECT_URI,
    DD_ELEM_NOTIFY_URI,
    DD_ELEM_NEXT_URL,
    DD_ELEM_VERSION,
    DD_ELEM_NAME,
    DD_ELEM_DESCRIPTION,
    DD_ELEM_VENDOR,
    DD_ELEM_INFO_URL,
    DD_ELEM_ICON_URI,
    DD_ELEM_INSTALL_PARAM,
    DD_ELEM_SIZE,
    DD_ELEM_PROGRESSIVE_DOWNLOAD_FLAG,
    
    DD_ELEM_END_OF_ENUM
} srv_da_oma_dd_elem_enum;


typedef enum {
    SRV_DA_OMA_STATE_PREPROCESSING,
    SRV_DA_OMA_STATE_DOWNLOADING,
    SRV_DA_OMA_STATE_DOWNLOADING_ICON,
    SRV_DA_OMA_STATE_SENDING_INSTALL_NOTIFICATION,
    SRV_DA_OMA_STATE_POSTPROCESSING,
    
    SRV_DA_OMA_STATE_END_OF_ENUM
} srv_da_oma_state_enum;


typedef enum
{
    SRV_DA_OMA_ICON_STATE_NONE,
    SRV_DA_OMA_ICON_STATE_DOWNLOADING,
    SRV_DA_OMA_ICON_STATE_SUCCEED,
    SRV_DA_OMA_ICON_STATE_FAILED,
    SRV_DA_OMA_ICON_STATE_CANCELLED,
    
    SRV_DA_OMA_ICON_STATE_END_OF_ENUM
} srv_da_oma_icon_state_enum;



/* The structure to download icon */
typedef struct
{
    srv_da_wps_session_handle session;
    U16                *filepath; /* the full path of downloaded icon */
    srv_da_oma_icon_state_enum  state;
    const applib_mime_type_struct *mime_type;
    srv_da_job_struct  *job;
} srv_da_oma_icon_struct;



typedef struct
{
    /* dd info */
	srv_da_oma_dd_struct dd_info;

    U16 unique_id;
	srv_da_oma_state_enum oma_state;

    S8          *dd_url;
    U16         *dd_filepath;
    S8          *dd_content_string;

    /* run-time variable */
    U16			*filepath;  /* mo full pathname */
    U32         size;
    U32         curr_size;
    U32         dl_start_tick;
    U32         dl_latest_tick;

    S8          *etag;
    srv_da_wps_session_handle  session;

    /* session to download iconURI */
    srv_da_oma_icon_struct *icon;

    U32 install_noti_session;
    
    /* authentication */
    U16         *auth_username;
    U16         *auth_password;
    MMI_BOOL    auth_is_info_valid;    

    /* DRM */
#ifdef __DRM_SUPPORT__
    drm_method_enum drm_method;
#endif
    S32 time_to_wait_for_rights;
    srv_da_drm_status_enum  drm_status;
    void *drm_process_session;
    void *drm_wait_for_rights_session;

    srv_da_wps_channel_handle channel;

    /* other */
    srv_da_abort_callback_type          abort_callback;
} srv_da_omadl_job_struct;

typedef struct
{
    srv_da_wps_session_handle  session;
    S32                 error;
    S8                  *installNotifyURI;
    srv_da_job_struct   *job;

} srv_da_oma_report_struct;

#ifdef __MMI_OMA_DD2_DOWNLOAD__
typedef struct
{
    S8  *name;
    S8  *description;
    /* text x N */
    S8  *infoURL;
    S8  *iconURI;
    S8  *installParam;
    S8  *installNotifyURI;
    S8  *environment;
    S8  *downloadNotifyURI;
    S8  *deleteNotifyURI;
    S8  *mediaURI;
    S32 suppressUserConfirmation;

#if 0   // not implemented yet
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    
} srv_da_oma_dd2_meta_struct;

typedef struct _srv_da_oma_dd2_mo
{
    struct _srv_da_oma_dd2_mo   *next;
    
    U32     size;
    S8      *type[4];                   /* only support 4 type */
    U32     installSize;
    S8      *objectId;
    S32     progressiveDownloadflag;
    S8      *objectVersion;
    S8      *objectURI;
    S8      *more_objectURI;            /* not used */
    void    *parent_ptr;                /* pointer to parent product */
    
    srv_da_oma_dd2_meta_struct *meta_info;
    
} srv_da_oma_dd2_mo_struct;

typedef struct
{
    S8  *timestamp;
    S8  *downloadTime;
    S8  *timeInterval;
    S8  *timeIntervalExpire;
    S8  *reservationNotifyURI;

} srv_da_oma_dd2_reserve_struct;

typedef struct _srv_da_oma_dd2_product
{
    struct _srv_da_oma_dd2_product  *next;
    
    srv_da_oma_dd2_meta_struct      *meta_info;

    srv_da_oma_dd2_mo_struct        *mo_list;
    U32                             mo_num;

    MMI_BOOL                            is_compund;

} srv_da_oma_dd2_product_struct;


typedef struct
{
    U32 DDVersion;
    
    S8  *vendorName;     /* NULL if not present */
    S8  *vendorHome;
    S8  *vendorLogo;
    S8  *vendorSupport;

    S8  *nextURL;
    S8  *updatedDDURI;
    U32 encoding;       /* this may be UCS2, depend on encoding, pay more attention */
    
    srv_da_oma_dd2_product_struct   *product_list;
    U32                             product_num;

    srv_da_oma_dd2_reserve_struct   *reserve;
    
} srv_da_oma_dd2_struct;
#endif


typedef MMI_BOOL (*srv_da_oma_install_check_hdlr) (srv_da_oma_dd_struct * item);
typedef struct
{
    applib_mime_type_enum mime_type;
    applib_mime_subtype_enum mime_subtype;
    srv_da_oma_install_check_hdlr handler;
} srv_da_oma_install_check_tbl_struct;


typedef enum
{
    SRV_DA_OMA_SEND_REPORT_RESULT_OK,
    SRV_DA_OMA_SEND_REPORT_RESULT_TIMEOUT,
    SRV_DA_OMA_SEND_REPORT_RESULT_FAILED,

    SRV_DA_OMA_SEND_REPORT_RESULT_END_OF_ENUM
} srv_da_oma_send_report_result_enum;


/****************************************************************************
 * [OMA Download Service (internal use)]
 ****************************************************************************/

extern U32 srv_da_oma_send_report(
    const S8 *uri_to_post,
    const S8 *content,
    U32 num_to_try,
    srv_da_wps_channel_handle channel,
    void *arg,
    void (*result_callback)(void *arg, srv_da_oma_send_report_result_enum result, U32 status_code));
    
extern void srv_da_oma_send_report_cancel(U32 session_id);
extern U32 srv_da_oma_send_report_get_number_of_sessions(void);

/****************************************************************************
 * Global Function
 ****************************************************************************/
extern MMI_BOOL srv_da_oma_parse_dd(U16 * filename, srv_da_job_struct *job, srv_da_oma_dd_struct *dd_info, S8* urlbase);
#ifdef __MMI_OMA_DD2_DOWNLOAD__
extern MMI_BOOL srv_da_oma_parse_dd2(U16 * filename, srv_da_job_struct *job, srv_da_oma_dd2_struct *dd_info, S8* urlbase);
#endif
extern MMI_BOOL srv_da_oma_extract_dd_content_string (srv_da_job_struct *job);
extern void srv_da_oma_report_map_string(S32 error, U16 *strId_p, S8** str_pp);

extern const srv_da_oma_install_check_tbl_struct *srv_da_oma_search_install_check_handler(const applib_mime_type_struct* type);

extern void srv_da_oma_http_auth_ind_callback(U32 arg);
extern void srv_da_oma_do_next_procedure(srv_da_job_struct *job);

#endif /* __MMI_OMA_DD_DOWNLOAD__ */

//#endif /* __COSMOS_MMI_PACKAGE__ */
#endif /* DOWNLOAD_AGENT_OMA_H */

