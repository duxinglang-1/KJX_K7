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
 *   cmmb_eb.h
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
#ifndef _CMMB_EB_H
#define _CMMB_EB_H

#include "kal_general_types.h"

#define CMMB_EB_MAX_LANG_DESC_NUM 16
#define CMMB_EB_MAX_AUX_INFO_NUM 16
#define CMMB_EB_NO_AUX_INFO 15
#define CMMB_EB_LANG_LEN 3

#define CMMB_EB_MAX_TEXT_LEN 128
#define CMMB_EB_MAX_TEXT_BUF_SIZE ((CMMB_EB_MAX_TEXT_LEN + 1) * sizeof(kal_wchar))
#define CMMB_EB_MAX_NAME_LEN 128
#define CMMB_EB_MAX_NAME_BUF_SIZE ((CMMB_EB_MAX_NAME_LEN + 1) * sizeof(kal_wchar))
#define CMMB_EB_MAX_DATA_LEN (2 * 8192)
#define CMMB_EB_MAX_TIME_LEN 20

#define CMMB_EB_BUFFER_SIZE (4 * 8192)

/*****************************************************************************
* Enumeration
*****************************************************************************/
typedef enum
{
    CMMB_EB_SIGNAL_TYPE_CURRENT_NETWORK = 0,
    CMMB_EB_SIGNAL_TYPE_OTHER_NETWORK ,
    CMMB_EB_SIGNAL_TYPE_NUM
} cmmb_eb_signal_type_enum;

/*****************************************************************************
* Structure
*****************************************************************************/
typedef struct
{
    kal_uint8 data_type;
    kal_uint16 data_len;
    kal_uint8 *data;
} cmmb_eb_aux_info_struct;

typedef struct
{
    kal_wchar lang[CMMB_EB_LANG_LEN + 1];
    kal_uint16 text_len;
    kal_wchar *text;
    kal_uint8 provider_name_len;
    kal_wchar *provider_name;
    kal_uint16 service_ref_id;
    kal_uint8 aux_info_idx;
    cmmb_eb_aux_info_struct *aux_info;
} cmmb_eb_lang_desc_struct;

typedef struct cmmb_eb_msg_current_network_t
{
    struct cmmb_eb_msg_current_network_t *next_p;
    kal_int32 is_new;

    cmmb_eb_signal_type_enum signal_type;

    kal_uint16 id_msg_id;
    kal_uint16 id_net_id;
    kal_uint8  id_net_level;

    kal_uint8 msg_type;
    kal_uint8 msg_level;
    kal_uint8 char_set;
    kal_uint32 start_date;
    kal_uint32 start_time;
    kal_uint32 duration;
    kal_uint8 lang_desc_count;
    cmmb_eb_lang_desc_struct *lang_desc[CMMB_EB_MAX_LANG_DESC_NUM];
    kal_uint8 aux_info_count;
    cmmb_eb_aux_info_struct *aux_info[CMMB_EB_MAX_AUX_INFO_NUM];
} cmmb_eb_msg_current_network_struct;

typedef struct cmmb_eb_msg_other_network_t
{
    struct cmmb_eb_msg_other_network_t *next_p;
    kal_int32 is_new;

    cmmb_eb_signal_type_enum signal_type;

    kal_uint16 id_msg_id;
    kal_uint16 id_net_id;
    kal_uint8  id_net_level;

    kal_uint8 msg_type;
    kal_uint8 msg_level;
    kal_uint8 net_level;
    kal_uint16 net_id;
    kal_uint8 freq;
    kal_uint32 center_freq;
    kal_uint8 bandwidth;
} cmmb_eb_msg_other_network_struct;


/*****************************************************************************
* Function Type
*****************************************************************************/
typedef void (*cmmb_eb_callback)(void* callback_param, cmmb_eb_signal_type_enum type, kal_uint8 *ptr);

/*****************************************************************************
* External Global Function
*****************************************************************************/
extern void* cmmb_eb_open(cmmb_eb_callback result_cb_hdlr, void* result_cb_param, kal_uint8* buf_p, kal_uint32 buf_size);
extern kal_int32 cmmb_eb_write(void* context, kal_uint8* data_part, kal_uint32 size);
extern kal_int32 cmmb_eb_reset(void* context);
extern kal_int32 cmmb_eb_close(void* context);
extern kal_int32 cmmb_eb_write_from_xml(void* context, kal_wchar *file_path, cmmb_eb_signal_type_enum type);


#endif /* _CMMB_EB_H */
