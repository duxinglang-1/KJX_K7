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
 *  PlstSrvMsgStruct.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  player list service message structure
 *
 * Author:
 * -------
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __PLAY_LIST_SERVICE_MSG_STRUCT_H__
#define __PLAY_LIST_SERVICE_MSG_STRUCT_H__
#ifdef __PLST_SERVICE_DB_SUPPORT__

#include "MMIDataType.h"
#include "PlstSrvDef.h"
#include "FileMgrSrvGProt.h"

/* 
   Service structure
*/


/* 
   Message SAP structure 
*/

typedef struct
{
    LOCAL_PARA_HDR
    void *db_handle; /* srv_plst_db_context_struct */
    U16 path[(SRV_FMGR_PATH_MAX_LEN+1)];
    U8  drv_letter;
} pls_library_open_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    void *db_handle; /* srv_plst_db_context_struct */
    S32 index;
    U32 id;
    MMI_BOOL is_nblock;
    srv_plst_get_data_enum get_type;
    U32 *ret_value;
} pls_list_get_data_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    void *db_handle; /* srv_plst_db_context_struct */
    srv_plst_get_data_enum get_type;
} pls_list_get_data_stop_struct;

typedef struct
{
    LOCAL_PARA_HDR
    void *db_handle; /* srv_plst_db_context_struct */
    U32 id;
    srv_plst_get_data_enum get_type;
    U16 *path;
} pls_list_item_get_play_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    void *db_handle; /* srv_plst_db_context_struct */
} pls_entry_list_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    void *db_handle; /* srv_plst_db_context_struct */
} pls_exit_list_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    void *db_handle; /* srv_plst_db_context_struct */
    U32 index;
    MMI_BOOL update_db;     /* set active and update DB */
    MMI_BOOL use_current;   /* use current playing info to update DB */
} pls_list_set_active_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    void *db_handle; /* srv_plst_db_context_struct */
    MMI_BOOL is_create;
} pls_create_mark_tbl_req_struct;


#endif  /* __PLST_SERVICE_DB_SUPPORT__ */
#endif /* __PLAY_LIST_SERVICE_MSG_STRUCT_H__ */

