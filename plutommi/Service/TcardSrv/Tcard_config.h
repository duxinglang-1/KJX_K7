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
 *  TcardUtilSrv.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  T Card service config file
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
*****************************************************************************/
#ifndef TCARD_CONFIG_H
#define TCARD_CONFIG_H

#include "MMI_features.h"

#ifdef __SRV_TCARD_DATA_STORE__

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "custom_mmi_default_value.h"


/*This must sync with tcard_file_mgr_common_table[] in Tcard_config.c*/
#define SRV_TCARD_MAX_FILE_SUPPORT 8


#define TCARD_SMS_MAX_ADDR_LEN 21


/**************************************************************
* Global Variables Declaration
**************************************************************/ 
typedef enum
{
    SRV_TCARD_ATTR_DEFAULT = 0x0000,
    SRV_TCARD_ATTR_NEED_BACKUP = 0x0001,
    SRV_TCARD_ATTR_NEED_FAST_ACCE = 0x0002,

    SRV_TCARD_ATTR_TOTAL = 0xFFFF
} srv_tcard_attr_enum;


typedef enum
{
    SRV_TCARD_APP_INDEX_NONE = 0, /* none */
    SRV_TCARD_APP_INDEX_SMS, 
    SRV_TCARD_APP_INDEX_PHB,

    /*Add the app index in the end*/
    SRV_TCARD_APP_INDEX_TOTAL
    
} srv_tcard_app_index_enum;


typedef enum
{
    SRV_TCARD_FILE_INDEX_NONE = 0, /* none */
    SRV_TCARD_FILE_INDEX_SMS_INFO, /*sms base info for msg list*/
    SRV_TCARD_FILE_INDEX_SMS_PDU_INDEX,/*pdu list*/
    SRV_TCARD_FILE_INDEX_SMS_ADDR_INFO,/*addr list*/
    SRV_TCARD_FILE_INDEX_SMS_PDU,/*sms pdu*/
    SRV_PHB_TCARD_DATA_FIELD,
    SRV_PHB_TCARD_INFO_FIELD,
    SRV_PHB_TCARD_RES_PATH_FIELD,
    SRV_PHB_TCARD_GROUP_INFO_FIELD,
    /*Add the file name in the end */
    SRV_TCARD_FILE_INDEX_TOTAL 
} srv_tcard_file_index_enum;

typedef struct
{
    srv_tcard_app_index_enum  app_index;                          
    U32 file_index;                  
    U32  record_size;                           
    U32  record_number;              
    kal_uint8 const*  default_value;                  
    srv_tcard_attr_enum   file_attr;                                                                 
} srv_tcard_file_entry_struct;

typedef struct
{
    U8 status;
	U8 dcs;
	U8 ext_status;
    U8 resend_count;
    U8 storage_type;
    U8 mti;
	U8 pid;
    U8 total_seg;
    U8 start_seg;
    U16 ref_num;
	U16 sim_id;
    U16 ext_addr_num;
    U16 start_addr_id;
    U16 port_num;
    U16 start_pdu_id;
    S8 number[TCARD_SMS_MAX_ADDR_LEN + 1];
    U16 content[41];
    U32 timestamp;
} tcard_sms_msg_node_struct;

#endif/*__SRV_TCARD_DATA_STORE__*/
#endif

