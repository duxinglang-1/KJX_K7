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
 *   profile_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for local parameter declaration about WAP profile SAP
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *                              HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _PROFILE_STRUCT_H
#define _PROFILE_STRUCT_H 

/**************************
 *  WAP profile access SAP enum and definition
 **************************/
#define WAP_PROF_MAX_NAME_SIZE 41 /* max number of characters for profile name */
#define WAP_PROF_MAX_UID_SIZE 33
#define WAP_PROF_MAX_PWD_SIZE 33

typedef enum
{
    WAP_PROF_SUCCESS,
    WAP_PROF_NOT_READY,
    WAP_PROF_BUSY,
    WAP_PROF_INVALID_ID
} wap_prof_error_eumm;

typedef enum
{
    WAP_PROF_CONN_TYPE_HTTP,
    WAP_PROF_CONN_TYPE_WSP_CO,
    WAP_PROF_CONN_TYPE_WSP_CL
} wap_prof_conn_type_enum;

typedef enum
{
    WAP_PROF_EWIL, /* WAP Image Load */
    WAP_PROF_EWHP, /* WAP Homepage */
    WAP_PROF_EWPR, /* WAP Profiles */
    WAP_PROF_EWPN, /* WAP Profile Name */
    WAP_PROF_EWDT, /* WAP Download Timeout */
    WAP_PROF_EWLI, /* WAP Login */
    WAP_PROF_EWPB, /* WAP Preferred Bearer, non-support */
    WAP_PROF_EWCG, /* WAP CSD Gateway, non-support */
    WAP_PROF_EWBA, /* WAP Bookmark Add */
    WAP_PROF_EWBR, /* WAP Bookmark Read */
    WAP_PROF_EWCT, /* WAP Connection Timeout, non-support */
    WAP_PROF_EWNI  /* WAP Current Network Account Id */
} wap_prof_access_enum;

typedef enum
{
    WAP_PROF_SET,
    WAP_PROF_READ,
    WAP_PROF_TEST
} wap_prof_cmd_enum;

typedef struct wap_prof_access_req_struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 query;
    kal_uint8 cmd;
    kal_uint8 param[5][16];
}wap_prof_access_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 sim_id;
}wap_get_prof_list_req_struct;

typedef struct
{
    kal_uint8 len;
    kal_uint8 dcs;
    kal_uint8 value[WAP_PROF_MAX_NAME_SIZE * 2];
} wap_prof_name_struct;

typedef struct
{
    kal_uint8 id;
    wap_prof_name_struct name;
    kal_uint8 conn_type;
} wap_prof_entry_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;   
    kal_uint8 result;
    kal_uint8 sim_id;
    kal_uint8 number;
    wap_prof_entry_struct *prof_list;
} wap_get_prof_list_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 sim_id;   
    kal_uint8 id;
} wap_get_prof_content_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 result; 
    kal_uint8 sim_id;  
    kal_uint8 id;
    kal_uint8 conn_type;
    kal_uint8 prx_ip[4];
    kal_uint16 prx_port;
    kal_uint8 username[30];
    kal_uint8 password[30];
    kal_uint32 net_id;
    kal_uint32 net_id2;
} wap_get_prof_content_rsp_struct;

typedef struct
{
    kal_uint8  ref_count;
    kal_uint16 msg_len;
    kal_uint8  sim_id;   
}wap_get_bra_prof_id_req_struct;

typedef struct
{
    kal_uint8  ref_count;
    kal_uint16 msg_len;
    kal_uint8  sim_id;   
    kal_int32  prof_id;
    kal_uint32 net_id;
    kal_uint32 net_id2;
} wap_get_bra_prof_id_rsp_struct;

#endif /* _PROFILE_STRUCT_H */
