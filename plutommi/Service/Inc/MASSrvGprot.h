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
*  MFreeSrv.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  MRE download service layer
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef __SRV_MFREE_H__
#define __SRV_MFREE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "mmi_features.h"
#include "MMIDataType.h"



#ifndef SRV_AS_MAX_STRING
#define SRV_AS_MAX_STRING 32
#endif

#define IS_SUPPORT_TOUCH            0X1
#define IS_SUPPORT_FINGTOUCH        0X2
#define IS_SUPPORT_CAMERA           0X4
#define IS_SUPPORT_SENSOR           0X8
#define IS_SUPPORT_REDUCE           0X10
#define IS_SUPPORT_NORMAL           0X20     
#define IS_SUPPORT_QUERTY           0X40     
#define IS_NEED_EXT                 0X80    

#define CHG_FORMAT

#ifndef CHG_FORMAT
#define LIS_HEADER_SIZE 3
#else
#define LIS_HEADER_SIZE 7
#endif


typedef struct
{
    U32 appid;
    U32 app_size;   
    WCHAR name[SRV_AS_MAX_STRING];
#ifdef CHG_FORMAT
    WCHAR dis_name[SRV_AS_MAX_STRING];
#else
    CHAR lang[SRV_AS_MAX_STRING]; // new item Get_Current_Lang_CountryCode "en-US" "zh-CN" "zh-TW"
#endif
    WCHAR provider[SRV_AS_MAX_STRING];
    WCHAR des[SRV_AS_MAX_STRING*4];
    U32 ver; // "1.0.2" => 0x02000100
    U32 year;
    U32 month;
    U32 day;
    U32 flag;
    U32 icon_size;
    U32 icon_offset;
    U8 * icon;
    U32 ram_size;
}srv_as_app_node_t;


typedef enum
{
    E_SRV_AS_QUERYING, // query
    E_SRV_AS_AVAILABLE_UPDATE, // query
    E_SRV_AS_NO_UPDATE, // query
    E_SRV_AS_CONNECTING,
    E_SRV_AS_CONNECTED,
    E_SRV_AS_DOWNLOADING, // download
    E_SRV_AS_DOWNLOADED, // download
    E_SRV_AS_HOST_NOT_FOUND,
    E_SRV_AS_PIPE_CLOSED,
    E_SRV_AS_PIPE_BROKEN,
    E_SRV_AS_FAILURE,
    E_SRV_AS_ERR_PATH,
    E_SRV_AS_ERR_ABORT,
    E_SRV_AS_INSTALL_SUCC = 20,
    E_SRV_AS_INSTALL_FAIL,
    E_SRV_AS_MAX
}srv_as_cb_app_state_e;

typedef enum
{
    E_SRV_AS_APP_QUERY_LIS,
    E_SRV_AS_APP_QUERY_APP,
    E_SRV_AS_APP_QUERY_END
}srv_as_data_query_e;

typedef void (*dl_callback)(S32 hdl, void * para);

typedef struct
{
    srv_as_data_query_e qry;
    U32 app_id;
    CHAR * app_ver;
    CHAR * app_info;
}srv_as_data_query_t;

/* Callback structures START */
#define SRV_AS_CB_COMMON \
    srv_as_cb_app_state_e state; \
    void * user_data

typedef struct
{
    SRV_AS_CB_COMMON;
}srv_as_cb_app_query_t;

typedef struct
{
    SRV_AS_CB_COMMON;
    S32 index;
    S32 received;
    S32 total;
}srv_as_cb_app_download_t;

typedef struct
{
    SRV_AS_CB_COMMON;
    S32 index;
}srv_as_cb_app_install_t;


#define SRV_AS_APP_STATUS_AVAIL_UPDATE              1// installed & avail update
#define SRV_AS_APP_STATUS_NO_AVAIL_UPDATE        2// installed & no avail update
#define SRV_AS_APP_STATUS_GONE                              4// installed & dose not exist
#define SRV_AS_APP_STATUS_NEW                                   8// have not installled

typedef struct 
{
    U32 status;
}srv_as_app_info_t;

/* Callback structures END */



S32 srv_as_data_query(const srv_as_data_query_t * query, dl_callback cb, void * user_data);
S32 srv_as_data_download(S32 hdl, const WCHAR * path, dl_callback cb, void * user_data);
S32 srv_as_app_download(U32 index, dl_callback cb, void * user_data);
S32 srv_as_data_cancel(S32 hdl);


S32 srv_as_list_init();

S32 srv_as_list_get_record_num();
S32 srv_as_list_get_info(U32 index, U32 num, srv_as_app_node_t * node, srv_as_app_info_t * info);
S32 srv_as_list_get_icon(U32 index, void * data, U32 size);

S32 srv_as_list_deinit();


#ifdef __cplusplus
}
#endif

#endif /* __SRV_MFREE_H__ */
