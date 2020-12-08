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
 *  CbsProtSrv.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  CBS(Cell Broadcast Service) Service Internal Header File
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#ifndef __SRV_CBS_PROT_SRV_H__
#define __SRV_CBS_PROT_SRV_H__

#include "MMI_features.h"
#ifdef __SRV_CBS_SUPPORT__

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "ps_public_enum.h"
#include "nvram_common_defs.h"
#include "SmsSrvGprot.h"
#include "CbsSrvGprot.h"

#define SRV_CBS_UNUSED_CBMI             SMSAL_CB_UNUSED_CBMI
#define SRV_CBS_UNUSED_DCS              SMSAL_CB_UNUSED_DCS

#ifndef SRV_CBS_MAX_MSG_NUM
#define SRV_CBS_MAX_MSG_NUM             NVRAM_EF_SRV_CBS_MSG_NODE_NUM
#endif

#define SRV_CBS_MAX_PAGE_NUM            NVRAM_EF_SRV_CBS_PAGE_NUM

#define SRV_CBS_DCS_UNSUPPORT           0x10               

#define CHNL_FLAG_BITMAP_SIZE           (((SRV_CBS_MAX_CHNL_NUM * CHNL_FLAG_TOTAL) + 7) / 8)

typedef enum
{
    CHNL_FLAG_NAME_USED = 0,
    CHNL_FLAG_MID_USED,
    CHNL_FLAG_MID_OPERATING,

    CHNL_FLAG_TOTAL
} cbs_chnl_flag_enum;

typedef struct
{
    MMI_BOOL mask;
    U8 mid_index;
    U8 name_index;
    U16 mid;
    WCHAR name[SRV_CBS_CHNL_NAME_LEN + 1];
} cbs_chnl_entry_struct;

typedef struct
{
    U8 total;
    U8 max_entry;
    U8 flag[CHNL_FLAG_BITMAP_SIZE];
    cbs_chnl_entry_struct entry[SRV_CBS_MAX_CHNL_NUM];
} cbs_chnl_cntx_struct;

typedef struct
{
    srv_cbs_lang_enum type;
    MMI_BOOL mask;
    U8 dcs_index;
    U16 dcs;
} cbs_lang_entry_struct;

typedef struct
{
    MMI_BOOL is_all_on;
    U16 total;
    cbs_lang_entry_struct entry[SRV_CBS_MAX_LANG_NUM];
} cbs_lang_cntx_struct;

typedef struct
{
    U8 page_num;
    U8 msg_dcs;
    U8 lang_type;
    U8 mode;
    U16 mi;
    U16 start_page_id;
    U32 timestamp;
} srv_cbs_msg_node_struct;

typedef struct
{
    U8 used_flag;
    U16 next_page_id;
} srv_cbs_page_node_struct;

typedef enum
{
    SRV_CBS_FLAG_NONE           = 0x00,
    SRV_CBS_FLAG_STARTUP_IND    = 0x01,
    SRV_CBS_FLAG_SIM_INSERTED   = 0x02,
    SRV_CBS_FLAG_REFRESH        = 0x04,
    SRV_CBS_FLAG_REFRESH_REPEAT = 0x08,

    SRV_CBS_FLAG_STORAGE_DONE   = 0x10,
    SRV_CBS_FLAG_SETTING_DONE   = 0x20,
    SRV_CBS_FLAG_INIT_DONE      = 0x40,

    SRV_CBS_FLAG_RESERVED       = 0xFF
} srv_cbs_flag_enum;

typedef struct
{
    MMI_BOOL is_ready;
    srv_cbs_flag_enum flag;

    U8 mode;

    cbs_lang_cntx_struct lang_cntx;
    cbs_chnl_cntx_struct chnl_cntx;

    U16 msg_list_size;
    U16 msg_list[SRV_CBS_MAX_MSG_NUM];

    U16 used_page_num;
    srv_cbs_page_node_struct page_node[SRV_CBS_MAX_PAGE_NUM];

    srv_cbs_msg_node_struct msg_node[SRV_CBS_MAX_MSG_NUM];
} srv_cbs_cntx_struct;

extern U16 srv_cbs_add_msg(
            srv_cbs_msg_node_struct *msg_node,
            U8 *msg_content,
            U32 msg_len,
            srv_sms_sim_enum sim_id);

extern void srv_cbs_convert_content_for_display(
                WCHAR *out_data,
                U32*real_out_len,
                U32 out_data_len,
                U8 *in_data,
                U32 in_data_size,
                srv_sms_dcs_enum msg_dcs);

extern U32 srv_cbs_decode_dcs(
                U8 dcs,
                U8* msg_content,
                U32 msg_len,
                srv_cbs_lang_enum* lang_type,
                srv_sms_dcs_enum* msg_dcs,
                srv_sms_class_enum *msg_class,
                MMI_BOOL* is_compress,
                MMI_BOOL* is_reserved);

extern srv_cbs_lang_enum srv_cbs_decode_lang(U8 char1, U8 char2);

extern srv_cbs_cntx_struct* srv_cbs_get_cntx(srv_sms_sim_enum sim_id);

extern void srv_cbs_storage_init(
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
extern void srv_cbs_setting_init(
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data);

#endif /* __SRV_CBS_PROT_SRV_H__ */
#endif /*__SRV_CBS_SUPPORT__*/

