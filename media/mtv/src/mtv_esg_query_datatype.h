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
 *   mtv_esg_query_datatype.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MTV_ESG_QUERY_DATATYPE_H_
#define _MTV_ESG_QUERY_DATATYPE_H_

#include "kal_general_types.h"
#include "mtv_esg_define.h"
#include "mbbms_sg_datatype.h"

typedef struct esg_query_service_struct_t
{
    struct esg_query_service_struct_t *next_p;
    kal_uint16 ref_id;
    kal_uint8  class;
    kal_uint8  genre;
    kal_wchar  name[ESG_MAX_NAME_LEN + 1];
    kal_wchar  description[ESG_MAX_TEXT_LEN + 1];
    kal_wchar  provider[ESG_MAX_NAME_LEN + 1];
    kal_wchar  language[ESG_MAX_NAME_LEN + 1];
    kal_bool   for_free;
    kal_bool   is_favorite;
    kal_uint16 ch_number;
    kal_uint32 fpid;
} esg_query_service_struct;

typedef struct esg_query_schedule_struct_t
{
    struct esg_query_schedule_struct_t *next_p;
    kal_uint16 ref_id;
    kal_uint16 service_ref_id;
    kal_uint16 content_ref_id;
    kal_wchar  start_date_time[ESG_MAX_STRING_LEN + 1];     /* yyyy-mm-dd hh:mm:ss */
    kal_wchar  end_date_time[ESG_MAX_STRING_LEN + 1];       /* yyyy-mm-dd hh:mm:ss */
    kal_bool   for_free;
    kal_bool   live;
    kal_bool   repeat;
    kal_wchar  title[ESG_MAX_NAME_LEN + 1];    
    kal_wchar  service_name[ESG_MAX_NAME_LEN + 1];
    kal_uint32 fpid;
} esg_query_schedule_struct;

typedef struct esg_query_content_struct_t
{
    struct esg_query_content_struct_t *next_p;
    kal_uint16 ref_id;
    kal_wchar  class[ESG_MAX_STRING_LEN + 1];
    kal_uint8  genre;
    kal_uint16 duration;
    kal_wchar  title[ESG_MAX_NAME_LEN + 1];
    kal_wchar  keyword[ESG_MAX_TEXT_LEN + 1];
    kal_wchar  description[ESG_MAX_TEXT_LEN + 1];
} esg_query_content_struct;

typedef struct mtv_esg_query_program_struct_t
{
    struct mtv_esg_query_program_struct_t *next_p;

    kal_uint16 ref_id;
    kal_char id[ESG_MAX_ID_LEN + 1];
    kal_wchar name[ESG_MAX_NAME_LEN + 1];
    kal_wchar start_time[ESG_MAX_TIME_LEN + 1];
    kal_wchar end_time[ESG_MAX_TIME_LEN + 1];

    kal_bool in_reminder;
    kal_bool has_inter_data;
} mtv_esg_query_program_struct;

typedef struct mtv_eb_msg_current_network_struct_t
{
    struct mtv_eb_msg_current_network_struct_t *next_p;

    kal_uint32 id;
    
    kal_uint8 msg_level;
    kal_bool is_new;
    kal_wchar receive_time[ESG_MAX_STRING_LEN + 1];
    kal_wchar text[ESG_MAX_TEXT_LEN + 1];

} mtv_eb_msg_current_network_struct;

typedef struct mtv_esg_query_record_count_t
{
    struct mtv_esg_query_record_count_t * next_p;

    kal_uint32 number;
    kal_uint32 index;
} mtv_esg_query_record_count;

#endif /* _MTV_ESG_QUERY_DATATYPE_H_ */
