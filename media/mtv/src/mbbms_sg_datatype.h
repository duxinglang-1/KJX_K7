/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   mbbms_sg_datatype.h
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
 *============================================================================
 ****************************************************************************/

#ifndef _MBBMS_SG_DATATYPE_H
#define _MBBMS_SG_DATATYPE_H

#define MBBMS_SG_ID_LEN    30
#define MBBMS_SG_CURRENCY_LEN   3
#define MBBMS_SG_URI_LEN 128
#define MBBMS_SG_PATH_LEN 128
#define MBBMS_SG_STRING_LEN 50
#define MBBMS_SG_NAME_LEN 20
#define MBBMS_SG_TIME_LEN 20
#define MBBMS_SG_LANG_LEN 10
#define MBBMS_SG_MIME_TYPE_LEN 20
#define MBBMS_SG_CITY_VER_LEN   30
#define MBBMS_SG_CITY_NAME_LEN  20

#define MBBMS_SG_ACCESS_SALT_LEN 13
#define MBBMS_SG_ACCESS_KEY_ID_LEN 13

/* SGDU Fragment */
typedef struct mbbms_sg_fragment_struct_t
{
    kal_char id[MBBMS_SG_ID_LEN + 1];
    kal_uint32 version;
    kal_uint32 encoding;
    kal_uint32 type;
} mbbms_sg_fragment_struct;

/* SGDD */
typedef struct
{
    kal_char id[MBBMS_SG_ID_LEN + 1];
    kal_uint32 version;
    kal_uint16 bsm_id;
    kal_wchar welcome_info[MBBMS_SG_STRING_LEN + 1];
    kal_wchar area_name[MBBMS_SG_NAME_LEN + 1];
} mbbms_sg_sgdd_struct;

/* preview data reference */
typedef struct mbbms_sg_preview_ref_struct_t
{
    kal_char id[MBBMS_SG_ID_LEN + 1];
    kal_uint8 usage;
    struct mbbms_sg_preview_ref_struct_t *next_p;
} mbbms_sg_preview_ref_struct;

/* Service */
typedef struct
{
    kal_char id[MBBMS_SG_ID_LEN + 1];
    kal_uint32 version;
    kal_char gid[MBBMS_SG_ID_LEN + 1];
    kal_uint16 weight;
    kal_bool for_free;
    kal_uint8 type;
    kal_wchar name[MBBMS_SG_NAME_LEN + 1];
    kal_wchar description[MBBMS_SG_STRING_LEN + 1];
    kal_wchar genre[MBBMS_SG_NAME_LEN + 1];
    kal_wchar provider[MBBMS_SG_NAME_LEN + 1];
    mbbms_sg_preview_ref_struct *ref;
} mbbms_sg_service_struct;

/* Content */
typedef struct
{
    kal_char id[MBBMS_SG_ID_LEN + 1];
    kal_uint32 version;
    kal_char gid[MBBMS_SG_ID_LEN + 1];
    kal_bool for_free;
    kal_bool live;
    kal_bool repeat;
    kal_wchar keyword[MBBMS_SG_STRING_LEN + 1];
    kal_wchar class[MBBMS_SG_NAME_LEN + 1];
    kal_char ref_service_id[MBBMS_SG_ID_LEN + 1];
    kal_wchar name[MBBMS_SG_NAME_LEN + 1];
    kal_wchar description[MBBMS_SG_STRING_LEN + 1];
    kal_wchar start_time[MBBMS_SG_TIME_LEN + 1];
    kal_wchar end_time[MBBMS_SG_TIME_LEN + 1];
    kal_wchar aud_lang[MBBMS_SG_LANG_LEN + 1];
    kal_wchar text_lang[MBBMS_SG_LANG_LEN + 1];
    kal_wchar genre[MBBMS_SG_NAME_LEN + 1];
    mbbms_sg_preview_ref_struct *ref;
} mbbms_sg_content_struct;

/* Preview Data */
typedef struct
{
    kal_char id[MBBMS_SG_ID_LEN + 1];
    kal_uint32 version;
    kal_char pic_uri[MBBMS_SG_URI_LEN + 1];
    kal_wchar text[MBBMS_SG_STRING_LEN + 1];
    kal_wchar pic_path[MBBMS_SG_PATH_LEN + 1];
    kal_char mime_type[MBBMS_SG_MIME_TYPE_LEN + 1];
    kal_bool dl_completed;
} mbbms_sg_preview_data_struct;

/* Purchase Item: ref */
typedef struct mbbms_sg_ref_struct_t
{
    kal_char id[MBBMS_SG_ID_LEN + 1];
    struct mbbms_sg_ref_struct_t *next_p;
} mbbms_sg_ref_struct;


/* Purchase Item */
typedef struct
{
    kal_char id[MBBMS_SG_ID_LEN + 1];
    kal_uint32 version;
    kal_char gid[MBBMS_SG_ID_LEN + 1];
    mbbms_sg_ref_struct *service;
    mbbms_sg_ref_struct *content;
    kal_wchar name[MBBMS_SG_NAME_LEN + 1];
    kal_wchar description[MBBMS_SG_STRING_LEN + 1];
} mbbms_sg_purchase_item_struct;

/* Purchase Data */
typedef struct
{
    kal_char id[MBBMS_SG_ID_LEN + 1];
    kal_uint32 version;
    kal_wchar description[MBBMS_SG_STRING_LEN + 1];
    kal_uint8 type;
    kal_uint8 period;
    float price;
    kal_wchar currency[MBBMS_SG_CURRENCY_LEN + 1];
    kal_char purchase_item_id[MBBMS_SG_ID_LEN + 1];
    mbbms_sg_ref_struct *purchase_channel;
    mbbms_sg_preview_ref_struct *ref;
} mbbms_sg_purchase_data_struct;

/* Purchase Channel */
typedef struct
{
    kal_char id[MBBMS_SG_ID_LEN + 1];
    kal_uint32 version;
    kal_wchar name[MBBMS_SG_NAME_LEN + 1];
    kal_wchar description[MBBMS_SG_STRING_LEN + 1];
    kal_char url[MBBMS_SG_URI_LEN + 1];
} mbbms_sg_purchase_channel_struct;

/* Access */
typedef struct
{
    kal_char id[MBBMS_SG_ID_LEN + 1];
    kal_uint32 version;
    kal_char uri[MBBMS_SG_URI_LEN + 1];
    kal_char key_id[MBBMS_SG_ACCESS_KEY_ID_LEN];
    kal_bool encrypted;
    mbbms_sg_ref_struct *service;
    mbbms_sg_ref_struct *schedule;
    kal_uint16 sid;
    kal_uint16 freq;
    kal_uint32 seq_id;

    kal_uint32 aud_iv_len;
    kal_uint32 aud_ki_len;
    kal_char aud_salt[MBBMS_SG_ACCESS_SALT_LEN];

    kal_uint32 vid_iv_len;
    kal_uint32 vid_ki_len;
    kal_char vid_salt[MBBMS_SG_ACCESS_SALT_LEN];

} mbbms_sg_access_struct;


/* Schedule */
typedef struct
{
    kal_char id[MBBMS_SG_ID_LEN + 1];
    kal_uint32 version;
    mbbms_sg_ref_struct *inter_data;
} mbbms_sg_schedule_struct;

/* Interactivity Data */
typedef struct
{
    kal_char id[MBBMS_SG_ID_LEN + 1];
    kal_uint32 version;
    mbbms_sg_ref_struct *service;
    mbbms_sg_ref_struct *content;
    kal_char url[MBBMS_SG_URI_LEN + 1];
    kal_char doc_ptr[MBBMS_SG_URI_LEN + 1];
} mbbms_sg_inter_data_struct;

/* City Version */
typedef struct
{
    kal_char city_ver[MBBMS_SG_CITY_VER_LEN + 1];
} mbbms_sg_city_version_struct;

/* City Data */
typedef struct
{
    kal_uint32 level;
    kal_wchar city_name[MBBMS_SG_CITY_NAME_LEN + 1];
    kal_wchar parent_name[MBBMS_SG_CITY_NAME_LEN + 1];
} mbbms_sg_city_data_struct;

typedef struct mbbms_sg_query_sgdd_struct_t
{
    struct mbbms_sg_query_sgdd_struct_t *next_p;

    kal_char id[MBBMS_SG_ID_LEN + 1];
    kal_uint32 version;
    kal_uint16 bsm_id;
    kal_wchar welcome_info[MBBMS_SG_STRING_LEN + 1];
    kal_wchar area_name[MBBMS_SG_NAME_LEN + 1];

} mbbms_sg_query_sgdd_struct;

typedef struct mbbms_sg_query_preview_data_struct_t
{
    struct mbbms_sg_query_preview_data_struct_t *next_p;

    kal_char pic_uri[MBBMS_SG_URI_LEN + 1];
    kal_wchar pic_path[MBBMS_SG_PATH_LEN + 1];
    kal_wchar text[MBBMS_SG_STRING_LEN + 1];
    kal_uint8 usage;
    kal_bool dl_completed;
} mbbms_sg_query_preview_data_struct;

typedef struct mbbms_sg_query_service_struct_t
{
    struct mbbms_sg_query_service_struct_t *next_p;

    kal_uint16 sid;
    kal_uint16 freq;
    kal_uint32 seq_id;
    kal_uint16 weight;
    kal_uint8 type;
    kal_bool for_free;
    kal_wchar name[MBBMS_SG_NAME_LEN + 1];
    kal_wchar description[MBBMS_SG_STRING_LEN + 1];
    kal_wchar genre[MBBMS_SG_NAME_LEN + 1];
    kal_wchar provider[MBBMS_SG_NAME_LEN + 1];
    //mbbms_sg_query_preview_data_struct preview_data;

} mbbms_sg_query_service_struct;

typedef struct mbbms_sg_query_purchase_channel_struct_t
{
    struct mbbms_sg_query_purchase_channel_struct_t *next_p;

    kal_char url[MBBMS_SG_URI_LEN + 1];
} mbbms_sg_query_purchase_channel_struct;

typedef struct mbbms_sg_query_access_all_struct_t
{
    struct mbbms_sg_query_access_all_struct_t *next_p;

    /* access */
    kal_uint16 sid;
    kal_uint16 freq;
    kal_uint32 seq_id;
    kal_bool encrypted;
    kal_char uri[MBBMS_SG_URI_LEN + 1];

    /* service */
    kal_uint8 type;
    kal_uint16 weight;

} mbbms_sg_query_access_all_struct;

typedef struct mbbms_sg_query_access_encrypt_struct_t
{
    struct mbbms_sg_query_access_encrypt_struct_t *next_p;

    kal_bool encrypted;

    //kal_uint32 aud_iv_len;
    kal_uint32 aud_ki_len;
    kal_char aud_salt[MBBMS_SG_ACCESS_SALT_LEN];

    //kal_uint32 vid_iv_len;
    kal_uint32 vid_ki_len;
    kal_char vid_salt[MBBMS_SG_ACCESS_SALT_LEN];

} mbbms_sg_query_access_encrypt_struct;

typedef struct mbbms_sg_query_access_key_id_struct_t
{
    struct mbbms_sg_query_access_key_id_struct_t *next_p;

    kal_char key_id[MBBMS_SG_ACCESS_KEY_ID_LEN];

} mbbms_sg_query_access_key_id_struct;

typedef struct mbbms_sg_query_purchase_item_struct_t
{
    struct mbbms_sg_query_purchase_item_struct_t *next_p;

    kal_char id[MBBMS_SG_ID_LEN + 1];
    kal_char gid[MBBMS_SG_ID_LEN + 1];
    kal_wchar name[MBBMS_SG_NAME_LEN + 1];

    /* from purchase_data */
    kal_uint8 type;
    kal_uint8 period;
    float price;
    //kal_wchar currency[MBBMS_SG_CURRENCY_LEN + 1];
    kal_wchar description[MBBMS_SG_STRING_LEN + 1];
    kal_wchar service_name[MBBMS_SG_NAME_LEN + 1];

    /* access */
    kal_uint16 sid;
    kal_uint16 freq;
    kal_uint32 seq_id;

} mbbms_sg_query_purchase_item_struct;

typedef struct mbbms_sg_query_purchase_data_struct_t
{
    struct mbbms_sg_query_purchase_data_struct_t *next_p;

    kal_char id[MBBMS_SG_ID_LEN + 1];

} mbbms_sg_query_purchase_data_struct;

typedef struct mbbms_sg_query_content_struct_t
{
    struct mbbms_sg_query_content_struct_t *next_p;

    kal_uint16 sid;
    kal_uint16 freq;
    kal_uint32 seq_id;
    kal_bool live;
    kal_bool repeat;
    kal_char id[MBBMS_SG_ID_LEN + 1];
    kal_wchar class[MBBMS_SG_NAME_LEN + 1];
    kal_wchar name[MBBMS_SG_NAME_LEN + 1];
    kal_wchar description[MBBMS_SG_STRING_LEN + 1];
    kal_wchar start_time[MBBMS_SG_TIME_LEN + 1];
    kal_wchar end_time[MBBMS_SG_TIME_LEN + 1];
    kal_wchar aud_lang[MBBMS_SG_LANG_LEN + 1];
    kal_wchar text_lang[MBBMS_SG_LANG_LEN + 1];
    kal_wchar genre[MBBMS_SG_NAME_LEN + 1];

    /* if in reminder? */
    kal_bool in_reminder;
    kal_bool has_inter_data;

} mbbms_sg_query_content_struct;

typedef struct mbbms_sg_query_city_version_struct_t
{
    struct mbbms_sg_query_city_version_struct_t *next_p;

    kal_char city_ver[MBBMS_SG_CITY_VER_LEN + 1];

} mbbms_sg_query_city_version_struct;

typedef struct mbbms_sg_query_city_list_struct_t
{
    struct mbbms_sg_query_city_list_struct_t *next_p;

    kal_uint32 city_id;
    kal_wchar city_name[MBBMS_SG_CITY_NAME_LEN + 1];

} mbbms_sg_query_city_list_struct;

typedef struct mbbms_sg_query_interact_struct_t
{
    struct mbbms_sg_query_interact_struct_t *next_p;

    kal_uint32 version;
    kal_char url[MBBMS_SG_URI_LEN + 1];
    kal_char doc_ptr[MBBMS_SG_URI_LEN + 1];

} mbbms_sg_query_interact_struct;


#endif /* _MBBMS_SG_DATATYPE_H */
