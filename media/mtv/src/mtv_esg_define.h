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
 *   mtv_esg_define.h
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
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MTV_ESG_DEFINES_H_
#define _MTV_ESG_DEFINES_H_

#define ESG_MAX_NAME_LEN     32
#define ESG_MAX_TEXT_LEN    256
#define ESG_MAX_DATA_LEN    32768   /* max binary size = 204800 */
#define ESG_MAX_URI_LEN     128
#define ESG_MAX_STRING_LEN   20
#define ESG_MAX_TIME_LEN     20
#define ESG_MAX_ID_LEN       30
#define ESG_MAX_LANGUAGE_LEN  3

#define ESG_MAX_GET_RESULTS_SIZE  10

#define MTV_ESG_INVALID_SID 0xFFFF
#define MTV_ESG_INVALID_QUERY_NUM 0xFFFFFFFF

typedef enum
{
    ESG_QUERY_NONE = 0,

    // IN:  NULL
    // OUT: cmmb_esg_query_service_struct / mbbms_sg_query_service_struct
    ESG_QUERY_SERVICES_ALL,             /* 1 */

    ESG_QUERY_SCHEDULES_NOW,            /* 2 */

    // IN:  mtv_esg_query_param
    // OUT: mtv_esg_query_program_struct
    ESG_QUERY_PROGRAM_OF_DAY,           /* 3 */

    // IN:  mtv_esg_query_param
    // OUT: cmmb_esg_query_service_struct   / mbbms_sg_query_service_struct
    ESG_QUERY_SERVICE,                  /* 4 */

    // IN:  mtv_esg_query_param
    // OUT: cmmb_esg_query_content_struct   / mbbms_sg_query_content_struct
    ESG_QUERY_CONTENT,                  /* 5 */

    ESG_QUERY_FAVORITE_LIST,            /* 6 */

    EB_QUERY_MSG_CURRENT_NETWORK_LIST,  /* 7 */
    EB_QUERY_MSG_CURRENT_NETWORK_DETAIL,/* 8 */
    EB_QUERY_MSG_OTHER_NETWORK,         /* 9 */

    // IN:  NULL
    // OUT: mbbms_sg_query_sgdd_struct
    ESG_QUERY_SGDD,                     /* 10 */      //BG: MED only

    // IN:  NULL
    // OUT: mbbms_sg_query_purchase_channel_struct
    ESG_QUERY_PURCHASE_CHANNEL_ALL,     /* 11 */      //BG: MED only

    // IN:  NULL
    // OUT: mbbms_sg_query_access_all_struct
    ESG_QUERY_ACCESS_URL,               /* 12 */      //BG: MED only

    // IN:  NULL
    // OUT: mbbms_sg_query_access_all_struct
    ESG_QUERY_ACCESS_ALL,               /* 13 */

    // IN:  mtv_esg_query_param
    // OUT: mbbms_sg_query_access_encrypt_struct
    ESG_QUERY_ACCESS_ENCRYPT,           /* 14 */      //BG: MED only

    // IN:  mtv_esg_query_param
    // OUT: mbbms_sg_query_access_key_id_struct
    ESG_QUERY_ACCESS_KEY_ID,            /* 15 */      //BG: MED only

    // IN:  mtv_esg_query_param
    // OUT: mbbms_sg_query_access_key_id_struct
    ESG_QUERY_ACCESS_KEY_ID_BY_SID,     /* 16 */      //BG: MED only

    // IN:  NULL
    // OUT: mbbms_sg_query_purchase_item_struct
    ESG_QUERY_PURCHASE_ITEM_ALL,        /* 17 */

    // IN:  mtv_esg_query_param
    // OUT: mbbms_sg_query_purchase_item_struct
    ESG_QUERY_PURCHASE_ITEM_BY_SID,     /* 18 */

    // IN:  mtv_esg_query_param
    // OUT: mbbms_sg_query_purchase_item_struct
    ESG_QUERY_PURCHASE_ITEM_BY_RID,     /* 19 */

    // IN:  mtv_esg_query_param
    // OUT: mbbms_sg_query_purchase_data_struct
    ESG_QUERY_PURCHASE_DATA,            /* 20 */

    // IN:  mtv_esg_query_param
    // OUT: mbbms_sg_query_content_struct
    ESG_QUERY_CONTENT_NOW,              /* 21 */

    // IN:  mtv_esg_query_param
    // OUT: mtv_esg_query_record_count
    ESG_QUERY_PROGRAM_OF_DAY_COUNT,      /* 22 */

    // IN:  mtv_esg_query_param
    // OUT: cmmb_esg_query_shedule_struct mbbms_sg_query_content_struct
    ESG_QUERY_CONTENT_BY_KEYWORD,       /* 23 */

    // IN:  mtv_esg_query_param
    // OUT: mbbms_sg_query_content_struct
    ESG_QUERY_REMINDER_LIST,            /* 24 */

    // IN:  NULL
    // OUT: mbbms_sg_query_purchase_item_struct
    ESG_QUERY_PURCHASE_ITEM_ALL_CURRENT_PLACE,  /* 25 */

    // IN:  mtv_esg_query_param
    // OUT: mbbms_sg_query_preview_data_struct
    ESG_QUERY_PREVIEW_DATA_BY_SID,      /* 26 */

    // IN:  mtv_esg_query_param
    // OUT: mbbms_sg_query_preview_data_struct
    ESG_QUERY_PREVIEW_DATA_BY_CONTENT,  /* 27 */

    // IN:  mtv_esg_query_param
    // OUT: mbbms_sg_query_preview_data_struct
    ESG_QUERY_PREVIEW_DATA_ALL,         /* 28 */

    // IN:  NULL
    // OUT: mbbms_sg_query_access_key_id_struct
    ESG_QUERY_ACCESS_KEY_ID_FOR_FREE,   /* 29 */      //BG: MED only

    // IN:  mtv_esg_query_param
    // OUT: mbbms_sg_query_purchase_item_struct
    ESG_QUERY_PURCHASE_ITEM_BY_RID_CURRENT_PLACE,  /* 30 */

    // IN:  mtv_esg_query_param
    // OUT: mtv_esg_query_record_count
    ESG_QUERY_CONTENT_BY_KEYWORD_COUNT, /* 31 */

    // IN:  NULL
    // OUT: mbbms_sg_query_city_version_struct
    ESG_QUERY_CITY_VERSION,             /* 32 */

    // IN:  mtv_esg_query_param
    // OUT: mbbms_sg_query_city_list_struct
    ESG_QUERY_CITY_LIST,                /* 33 */

    // IN:  mtv_esg_query_param
    // OUT: mbbms_sg_query_interact_struct
    ESG_QUERY_INTERACTIVITY_BY_CONTENT,    /* 34 */

    // IN:  mtv_esg_query_param
    // OUT: mbbms_sg_query_interact_struct
    ESG_QUERY_INTERACTIVITY_BY_SERVICE,    /* 35 */

    // IN:  mtv_esg_query_param
    // OUT: mbbms_sg_query_access_all_struct
    ESG_QUERY_ACCESS_BY_SCHEDULE_ACCESS,    /* 36 */

    // IN:  mtv_esg_query_param
    // OUT: mtv_esg_query_record_count
    ESG_QUERY_CITY_LIST_COUNT               /* 37 */

} esg_query_type_enum;

typedef enum
{
    ESG_QUERY_LANG_DEFAULT = 0,
    ESG_QUERY_LANG_ZHO,
    ESG_QUERY_LANG_ENG
} esg_query_language_type_enum;


#endif /* _MTV_ESG_DEFINES_H_ */
