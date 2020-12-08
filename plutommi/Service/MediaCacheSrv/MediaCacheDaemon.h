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
 *  MediaCacheDaemon.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  ImageViewer Ex daemon head file
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

#ifndef _MEDIACACHE_DAEMON_H_
#define _MEDIACACHE_DAEMON_H_

#include "MMI_features.h"
#if defined(__SQLITE3_SUPPORT__)
#include "MMIDataType.h"
#include "MediaCacheDaemonGprot.h"
#include "kal_public_defs.h"

#ifdef __COSMOS_MMI_PACKAGE__
#include "FileMgrSrvGProt.h"
#endif

#define IVD_IV_DATABASE_STOP    (1<<0)
#define IVD_IV_DATABASE_GET     (1<<1)
#define IVD_IV_DATABASE_NB_GET_DONE     (1<<2)
#define IVD_IV_DATABASE_GET_META_DONE     (1<<3)
#define IVD_IV_DATABASE_NB_GET_META_DONE     (1<<4)

typedef struct
{
    S32 height;
    S32 width;
    S32 o_height;
    S32 o_width;
    U32 file_time;
    U32 file_date;
    U32 file_size;
    U32 update_time;
    U32 update_date;
    U32 crc;
    S32 err_group;
    S32 err_code;
    U8 *data;
} ivd_iv_file_info_struct;

typedef struct
{
    ivd_db_handle_struct *g_ivd_db_handle_p;
    kal_eventgrpid g_ivd_iv_event;
} ivd_iv_cntx_struct;


#ifdef __COSMOS_MMI_PACKAGE__

typedef struct ivd_db_video_msg_base* ivd_db_video_msg_ptr;

typedef MMI_BOOL (*ivd_db_video_msg_handler_func)(ivd_db_video_msg_ptr msg_ptr);

#define IVD_DB_VIDEO_MSG_BASE_HDR U32   type_id;\
                                  U32   msg_size;\
                                  MMI_BOOL blocking_call;\
                                  ivd_db_handle_struct *db_handle;\
                                  ivd_db_video_result_base *result;\
                                  ivd_db_video_msg_handler_func handler_func;
                                        
typedef struct ivd_db_video_msg_base
{
    LOCAL_PARA_HDR
    IVD_DB_VIDEO_MSG_BASE_HDR
} ivd_db_video_msg_base;

typedef struct ivd_db_video_msg_put_info
{
    LOCAL_PARA_HDR
    IVD_DB_VIDEO_MSG_BASE_HDR
    S32 duration_sec;
    S32 bookmark_sec;
    S32 thumb_width;
    S32 thumb_height;
    S32 thumb_buf_len;
    U8* thumb_buf_ptr;  // implicit RGB565 format
    kal_wchar file_name[SRV_FMGR_PATH_BUFFER_SIZE];
} ivd_db_video_msg_put_info;

typedef struct ivd_db_video_msg_get_info
{
    LOCAL_PARA_HDR
    IVD_DB_VIDEO_MSG_BASE_HDR
    kal_wchar file_name[SRV_FMGR_PATH_BUFFER_SIZE];
} ivd_db_video_msg_get_info;

typedef ivd_db_video_msg_get_info ivd_db_video_msg_get_bookmark;
typedef ivd_db_video_msg_get_info ivd_db_video_msg_has_info;

typedef struct ivd_db_video_msg_put_bookmark
{
    LOCAL_PARA_HDR
    IVD_DB_VIDEO_MSG_BASE_HDR
    U32 bookmark_sec;
    double access_time;
    kal_wchar file_name[SRV_FMGR_PATH_BUFFER_SIZE];
} ivd_db_video_msg_put_bookmark;

typedef struct ivd_db_video_msg_update_total_duration
{
    LOCAL_PARA_HDR
    IVD_DB_VIDEO_MSG_BASE_HDR
    U32 total_duration;
    kal_wchar file_name[SRV_FMGR_PATH_BUFFER_SIZE];
} ivd_db_video_msg_update_total_duration;


typedef struct ivd_db_video_msg_get_video_collection_thumb
{
    LOCAL_PARA_HDR
    IVD_DB_VIDEO_MSG_BASE_HDR
    S32 thumb_index;      // index of the thumbnail in the collection
} ivd_db_video_msg_get_video_collection_thumb;

void ivd_ivsrv_db_send_video_msg(ivd_db_video_msg_base *msg);
void ivd_iv_db_handle_video_msg(ilm_struct *ilm_ptr);
#endif







#endif /* defined(__SQLITE3_SUPPORT__) */
#endif /* _MEDIACACHE_DAEMON_H_ */ 


