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
 * NVRAMINTERFACE.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for nvram read write data interface.
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

/*****************************************************************************
* Include
*****************************************************************************/
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "nvram_common_defs.h"
#include "custom_nvram_config.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "mmi_msg_struct.h"
#include "pluto_fw_trc.h"
#include "kal_trace.h"
#include "string.h"
#include "stack_common.h"
#include "kal_debug.h"
#include "mmi_frm_nvram_gprot.h"
#include "mmi_frm_event_flag_gprot.h"
#include "mmi_frm_event_flag_prot.h"
#include "MMI_fw_trc.h"
#include "stack_ltlcom.h"
#include "mmi_frm_input.h"
#include "mmi_frm_timer_gprot.h"
#include "ps_public_struct.h"
#include "mmi_frm_prot.h"
#include "nvram_struct.h"
#include "nvram_interface.h"
#include "nvram_enums.h"
#include "BootupSrvGprot.h"
#include "mmi_cache_table.h"
#include "app_mem_med.h"


#undef MMI_FRM_NVRAM_UT
//#define MMI_FRM_NVRAM_UT

#ifdef MMI_FRM_NVRAM_UT
#include "TimerEvents.h"
#include "mmi_rp_srv_sms_def.h"
#include "mmi_rp_srv_wap_prof_def.h"
#endif 


/*****************************************************************************
* Typedef Internal
*****************************************************************************/
typedef enum
{
    circularQ_check_never_check,
    circularQ_check_not_found,
    circularQ_check_found
} circularQ_check_enum;

typedef enum
{
    MMI_FW_NVRAM_BYTE,
    MMI_FW_NVRAM_SHORT,
    MMI_FW_NVRAM_DOUBLE,
    MMI_FW_NVRAM_TYPE_TOTAL
} mmi_fw_nvram_cache_type;

typedef enum
{
    WRITE_NVRAM_SYNC,
    WRITE_NVRAM_ASYNC,
} write_nvram_type;



typedef U16* (*get_cache_table)(void);
typedef U16  (*get_cache_max_num)(void);
typedef U8* (*get_cache_default_table)(void);

/*****************************************************************************
* Global Variable
*****************************************************************************/
static U8 in_nvram_procedure = 0;
static U8 cache_buf[MMI_FW_NVRAM_TYPE_TOTAL][NVRAM_CACHE_SIZE] = {0};
static MMI_BOOL dataReadFlag[MMI_FW_NVRAM_TYPE_TOTAL] = {MMI_FALSE};
static MMI_BOOL dataWriteFlashFlag[MMI_FW_NVRAM_TYPE_TOTAL] = {MMI_FALSE};
static MMI_BOOL is_cache_rearrange = MMI_FALSE;
static U16* nvram_get_byte_cache_table(void);
static U16* nvram_get_short_cache_table(void);
static U16* nvram_get_double_cache_table(void);


const static nvram_lid_enum cache_lid[MMI_FW_NVRAM_TYPE_TOTAL] =
{
    NVRAM_EF_CACHE_BYTE_LID,
    NVRAM_EF_CACHE_SHORT_LID,
    NVRAM_EF_CACHE_DOUBLE_LID
};



const static get_cache_max_num cache_max_id[MMI_FW_NVRAM_TYPE_TOTAL] =
{
    mmi_rp_mmi_cache_get_byte_number,
    mmi_rp_mmi_cache_get_short_number,
    mmi_rp_mmi_cache_get_double_number
};


const static U8 cache_data_size[MMI_FW_NVRAM_TYPE_TOTAL] =
{
    1, /* Byte */
    2, /* Short */
    8  /* Double */
};


const static get_cache_table g_rp_cache_id[MMI_FW_NVRAM_TYPE_TOTAL] = 
{
    nvram_get_byte_cache_table,
    nvram_get_short_cache_table,
    nvram_get_double_cache_table
};


typedef  void ( *restore_func_ptr )(nvram_reset_category_enum category, nvram_app_id_enum app_id, kal_uint8 *buffer);

static const restore_func_ptr restore_func_table[] = 
{
    nvram_restore_byte_cache,
    nvram_restore_short_cache,
    nvram_restore_double_cache
};


static const U16 cache_key_record[] =
{
    NVRAM_MMI_CACHE_BYTE_KEY_TOTAL,
    NVRAM_MMI_CACHE_SHORT_KEY_TOTAL,
    NVRAM_MMI_CACHE_DOUBLE_KEY_TOTAL
};

static const U16 cache_key_lid[] =
{
 NVRAM_EF_MMI_CACHE_BYTE_KEY_LID,
 NVRAM_EF_MMI_CACHE_SHORT_KEY_LID,
 NVRAM_EF_MMI_CACHE_DOUBLE_KEY_LID
};

static const U16 cache_key_size[] =
{
 NVRAM_MMI_CACHE_BYTE_KEY_SIZE,
 NVRAM_MMI_CACHE_SHORT_KEY_SIZE,
 NVRAM_MMI_CACHE_DOUBLE_KEY_SIZE
};


static const U32 *const cache_key_table[] =
{
    NVRAM_EF_MMI_CACHE_BYTE_KEY_DEFAULT,
    NVRAM_EF_MMI_CACHE_SHORT_KEY_DEFAULT,
    NVRAM_EF_MMI_CACHE_DOUBLE_KEY_DEFAULT
};


#ifdef MMI_FRM_NVRAM_UT
static U8 nvram_req_count_ut = 0;
#endif 
/*****************************************************************************
* Define
*****************************************************************************/
/* only for internal read/write value */

#define WriteRecordInCache(nLID,nRecordId,pBuffer,nBufferSize)\
    AccessRecordInt(nLID,nRecordId,pBuffer,nBufferSize, 1, 1, MMI_TRUE, MMI_TRUE, MMI_FALSE)

#define ReadRecordInCache(nLID,nRecordId,pBuffer,nBufferSize)\
    AccessRecordInt(nLID,nRecordId,pBuffer,nBufferSize, 1, 1, MMI_FALSE, MMI_TRUE, MMI_FALSE)

/* only for internal reset */
#define ResetRecordInt(reset_category, app_id, nLID, nRecordId, nRecordAmount)\
    AccessRecordInt(nLID,nRecordId,NULL,1, nRecordAmount, reset_category, MMI_FALSE, MMI_FALSE, MMI_TRUE)

#define NVRAM_CACHE_VALIDATE_TEMP_BUF_SIZE (10 * 1024)

/*****************************************************************************
* Static Function Declaration
*****************************************************************************/

static void SendNVRAMReadReq(nvram_lid_enum nLID, U16 nRecordId, U16 nRecordAmount);
static void SendNVRAMWriteReq(nvram_lid_enum nLID, U16 nRecordId, void *pBuffer, U16 nBufferSize, U8 accessId);
static void send_nvram_reset_req(U8 reset_category, U16 app_id, nvram_lid_enum lid, U16 rec_index, U16 record_amount);
static circularQ_check_enum NVRAMCheckCircularQ(void *msgPtr, nvram_lid_enum nFileId);
static S32 AccessRecordInt
    (nvram_lid_enum nLID,
     U16 nRecordId,
     void *pBuffer,
     U16 nBufferSize,
     U16 nRecordAmount,
     U8 reset_category,
     pBOOL isWrite,
     pBOOL isValue,
     pBOOL isReset);
static U8 CacheSizeToIndex(U8 nDataType);
static MMI_BOOL mmi_frm_nvram_cache_file_commpare(U32* resgen_pool, U32* key_pool, U16 cache_type, U16 num, U8* cache_buffer);
extern void mmi_frm_nvram_cache_validate(void);

static U16* nvram_get_byte_cache_table(void)
{
    return (U16*)MMI_CACHE_BYTE_ENUM_TABLE;

}

static U16* nvram_get_short_cache_table(void)
{
    return (U16*)MMI_CACHE_SHORT_ENUM_TABLE;
}
static U16* nvram_get_double_cache_table(void)
{
    return (U16*)MMI_CACHE_DOUBLE_ENUM_TABLE;
}

/*****************************************************************************
 * FUNCTION
 *  send_nvram_reset_req
 * DESCRIPTION
 *  Send Reset NVRAM request to L4
 * PARAMETERS
 *  nLID                [IN]        NVRAM Data Item LID
 *  nRecordId           [IN]        Record Index
 *  nRecordAmount       [IN]        Record Amount
 * RETURNS
 *  void
 *****************************************************************************/
static void send_nvram_reset_req(U8 reset_category, U16 app_id, nvram_lid_enum lid, U16 rec_index, U16 record_amount)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_reset_req_struct *local_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_data = (nvram_reset_req_struct*) OslConstructDataPtr(sizeof(nvram_reset_req_struct));
    local_data->access_id = 0;
    local_data->reset_category = (nvram_reset_category_enum)reset_category;
    local_data->app_id = app_id;
    local_data->LID = lid;
    local_data->rec_index = rec_index;
    local_data->rec_amount = record_amount;
    mmi_frm_send_ilm(MOD_NVRAM, MSG_ID_NVRAM_RESET_REQ, (oslParaType*) local_data, NULL);
    //MMI_TRACE(PLUTO_FW_TRC_NVRAM, TRC_SEND_NVRAM_RESET_REQ);    

}


/*****************************************************************************
 * FUNCTION
 *  SendNVRAMReadReq
 * DESCRIPTION
 *  Send Read NVRAM request to L4
 * PARAMETERS
 *  nLID                [IN]        NVRAM Data Item LID
 *  nRecordId           [IN]        Record Index
 *  nRecordAmount       [IN]        Record Amount
 * RETURNS
 *  void
 *****************************************************************************/
static void SendNVRAMReadReq(nvram_lid_enum nLID, U16 nRecordId, U16 nRecordAmount)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_read_req_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_data = (nvram_read_req_struct*) OslConstructDataPtr(sizeof(nvram_read_req_struct));
    local_data->access_id = 0;
    local_data->file_idx = nLID;
    local_data->para = nRecordId;
    local_data->rec_amount = nRecordAmount;
    if (local_data->rec_amount == 0)
    {
        local_data->rec_amount = 1;
    }
    mmi_frm_send_ilm(MOD_NVRAM, MSG_ID_NVRAM_READ_REQ, (oslParaType *)local_data, NULL);
    MMI_TRACE(PLUTO_FW_TRC_NVRAM, TRC_MMI_FRM_NVRAM_SEND_READ_REQ);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_write_async_record
 * DESCRIPTION
 *  Send Write NVRAM request to NVRAM, this is async case, just send message,
 *  not wait for writing result. Applications should register protocol event
 *  handler for MSG_ID_NVRAM_WRITE_CNF.
 * PARAMETERS
 *  nLID            [IN]        NVRAM Data Item ID
 *  nRecordId       [IN]        Record Index
 *  pBuffer         [IN]        Data to be writen
 *  nBufferSize     [IN]        Size of data to be writen
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_write_async_record(nvram_lid_enum nLID, U16 nRecordId, void *pBuffer, U16 nBufferSize)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((nBufferSize < 2048) && (nBufferSize > 0));
    //MMI_ASSERT((nLID != NVRAM_EF_CACHE_DOUBLE_LID) && (nLID != NVRAM_EF_CACHE_DOUBLE_LID) && (nLID != NVRAM_EF_CACHE_SHORT_LID));
   
    MMI_TRACE(PLUTO_FW_TRC_NVRAM, TRC_MMI_FRM_NVRAM_ASYNC_WRITE_RECORD_BEGIN, nLID, nRecordId);

    SendNVRAMWriteReq(nLID, nRecordId, pBuffer, nBufferSize, WRITE_NVRAM_ASYNC);

}


/*****************************************************************************
 * FUNCTION
 *  SendNVRAMWriteReq
 * DESCRIPTION
 *  Send Write NVRAM request to L4
 *  
 *  Size should be an even number
 * PARAMETERS
 *  nLID            [IN]        NVRAM Data Item ID
 *  nRecordId       [IN]        Record Index
 *  pBuffer         [IN]        Data to be writen
 *  nBufferSize     [IN]        Size of data to be writen
 * RETURNS
 *  void
 *****************************************************************************/
static void SendNVRAMWriteReq(nvram_lid_enum nLID, U16 nRecordId, void *pBuffer, U16 nBufferSize, U8 accessId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_write_req_struct *local_data;
    peer_buff_struct *pdu_ptr;
    kal_uint8 *pdu_stream_ptr;
    kal_uint16 len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_data = (nvram_write_req_struct*)mmi_construct_msg_local_para(sizeof(nvram_write_req_struct));
    local_data->file_idx = nLID;
    local_data->para = nRecordId;
    local_data->access_id = accessId;
    /* put the content in peer buffer */
    pdu_ptr = (peer_buff_struct*) construct_peer_buff(
                                      nBufferSize,
                                      0,  /* no header */
                                      0,  /* no tail */
                                      TD_RESET);

    pdu_stream_ptr = (kal_uint8*) get_pdu_ptr(pdu_ptr, &len);
    memcpy(pdu_stream_ptr, pBuffer, nBufferSize);
    mmi_frm_send_ilm(MOD_NVRAM, MSG_ID_NVRAM_WRITE_REQ, (oslParaType *)local_data, pdu_ptr);
    MMI_TRACE(PLUTO_FW_TRC_NVRAM, TRC_MMI_FRM_NVRAM_SEND_WRITE_REQ);
}


/*****************************************************************************
 * FUNCTION
 *  NVRAMCheckCircularQ
 * DESCRIPTION
 *  check if there is nvram access response
 *  in the circular queue; if there is,
 *  retrieve it and put a dummy one in the
 *  same position
 * PARAMETERS
 *  msgPtr          [OUT]       The NVRAM Read/Write RSP message
 *  nLID            [IN]        The LID currently waiting
 * RETURNS
 *  circularQ_check_enum
 *****************************************************************************/
static circularQ_check_enum NVRAMCheckCircularQ(void *msgPtr, nvram_lid_enum nLID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    extern MYQUEUE circq_array[];
    MYQUEUE *tempQueueNode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    for (i = 0; i < CIRCQ_NO_OF_NODES; i++)
    {
        tempQueueNode = (MYQUEUE*)(circq_array + i);
        switch (tempQueueNode->msg_id)
        {
            case MSG_ID_NVRAM_READ_CNF:
            case MSG_ID_NVRAM_WRITE_CNF:
            {
                MYQUEUE message; /* DUMMY message */
                if (((nvram_read_cnf_struct*) (tempQueueNode->local_para_ptr))->file_idx == nLID
                    || ((nvram_write_cnf_struct*) (tempQueueNode->local_para_ptr))->file_idx == nLID)
                {
                    memcpy(msgPtr, circq_array + i, sizeof(MYQUEUE));

                    message.src_mod_id = MOD_NIL;
                    message.dest_mod_id = MOD_NIL;
                    message.msg_id = MSG_ID_MMI_INVALID_IND;
                    message.sap_id = INVALID_SAP;
                    message.local_para_ptr = NULL;
                    message.peer_buff_ptr = NULL;
                    memcpy(circq_array + i, &message, sizeof(MYQUEUE));
                    return circularQ_check_found;
                }
                break;
            }
            
            default:
                break;
        }
    }
    return circularQ_check_not_found;
}


/*****************************************************************************
 * FUNCTION
 *  CacheSizeToIndex
 * DESCRIPTION
 *  Get cache buffer index
 * PARAMETERS
 *  nDataType          [In]       DS_BYTE, DS_SHORT, DS_DOUBLE
 * RETURNS
 *  cache buffer index
 *****************************************************************************/
static U8 CacheSizeToIndex(U8 nDataType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (nDataType)
    {
        case DS_BYTE:
            nDataType = MMI_FW_NVRAM_BYTE;
            break;

        case DS_SHORT:
            nDataType = MMI_FW_NVRAM_SHORT;
            break;

        case DS_DOUBLE:
            nDataType = MMI_FW_NVRAM_DOUBLE;
            break;
            
        default:
            MMI_ASSERT(0);
            break;
    }
    return nDataType;
}


/*****************************************************************************
 * FUNCTION
 *  AccessRecordInt
 * DESCRIPTION
 *  Internal used API to access NVRAM
 * PARAMETERS
 *  nLID                [IN]        NVRAM data item LID
 *  nRecordId           [IN]        Record index in a data item
 *  pBuffer             [OUT]       Buffer in which data need to
 *  nBufferSize         [IN]        Size of record
 *  nRecordAmount       [IN]        read record amount
 *  reset_category        [IN]        reset type
 *  isWrite             [IN]        MMI_TRUE = write, MMI_FALSE = read
 *  isValue             [IN]        MMI_TRUE = from read/write Value
 *                                  MMI_FALSE = from read/write Record
 *  isReset             [IN]        MMI_TRUE = reset, MMI_FALSE = not reset
 * RETURNS
 *  0  - FS SanityCheck in processing / reset fail
 *  1  - reset success
 *  -1 - Access failed
 *  data len to write or read - Access succeed
 *****************************************************************************/
static S32 AccessRecordInt
    (nvram_lid_enum nLID,
     U16 nRecordId,
     void *pBuffer, 
     U16 nBufferSize, 
     U16 nRecordAmount,
     U8 reset_category,
     pBOOL isWrite, 
     pBOOL isValue,
     pBOOL isReset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE queueNode;
    S32 status = -1;
    circularQ_check_enum circularQ_check_result = circularQ_check_never_check;
    static U8 nvram_req_count = 0;
    MMI_BOOL toPush;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* do not do this in bootup procedure */ 
    if (srv_bootup_is_completed() == MMI_TRUE)
    {
        /* priority inheritence */
        kal_change_priority_by_index(INDX_NVRAM, TASK_PRIORITY_MMI);
    }

    if (isReset)
    {
        /* send reset req msg*/
        send_nvram_reset_req(reset_category, NVRAM_APP_RESERVED, nLID, nRecordId, nRecordAmount);
        dataReadFlag[0] = MMI_FALSE;
        dataReadFlag[1] = MMI_FALSE;
        dataReadFlag[2] = MMI_FALSE;
    }
    else
    {
        if (isWrite)
        {
            SendNVRAMWriteReq(nLID, nRecordId, pBuffer, nBufferSize, WRITE_NVRAM_SYNC);

            if (!isValue)   /* call from read/write Record */
            {
                /* reset BYTE/SHORT/DOUBLE cache */
                /*   since others may access these LIDs directly */
                if (nLID == NVRAM_EF_CACHE_BYTE_LID)
                {
                    MMI_TRACE(PLUTO_FW_TRC_NVRAM, TRC_MMI_FRM_NVRAM_WRITE_CACHE_BY_LID, nLID);
                    dataReadFlag[MMI_FW_NVRAM_BYTE] = MMI_FALSE;
                }
                else if (nLID == NVRAM_EF_CACHE_SHORT_LID)
                {
                    MMI_TRACE(PLUTO_FW_TRC_NVRAM, TRC_MMI_FRM_NVRAM_WRITE_CACHE_BY_LID, nLID);
                    dataReadFlag[MMI_FW_NVRAM_SHORT] = MMI_FALSE;
                }
                else if (nLID == NVRAM_EF_CACHE_DOUBLE_LID)
                {
                    MMI_TRACE(PLUTO_FW_TRC_NVRAM, TRC_MMI_FRM_NVRAM_WRITE_CACHE_BY_LID, nLID);
                    dataReadFlag[MMI_FW_NVRAM_DOUBLE] = MMI_FALSE;
                }
            }    
        }
        else
        {
            SendNVRAMReadReq(nLID, nRecordId, nRecordAmount);
        }
    }


    in_nvram_procedure++;
    mmi_frm_clear_event_flag(MMI_EVT_F_NOT_IN_NVRAM);
    MMI_TRACE(PLUTO_FW_TRC_NVRAM, TRC_MMI_FRM_TASK_IN_NVRAM_PROCEDURE, in_nvram_procedure);
    while (1)
    {
        /* if more than 1 access request exist, go through the circular Q */
        if ((nvram_req_count > 0) && (circularQ_check_result == circularQ_check_never_check))
        {
            circularQ_check_result = NVRAMCheckCircularQ(&queueNode, nLID);
            MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_NVRAM_CHECK_CQ, circularQ_check_result);
        }

        if (circularQ_check_result != circularQ_check_found)
        {
            msg_receive_extq(&queueNode);
            kal_set_active_module_id(MOD_MMI);            
        }

        toPush = MMI_FALSE;
        switch (queueNode.msg_id)
        {
            case MSG_ID_MMI_EQ_PLAY_AUDIO_RSP:
            case MSG_ID_MMI_EQ_STOP_AUDIO_RSP:
            case MSG_ID_MMI_EQ_EXE_GPIO_LEVEL_RSP:
            case MSG_ID_MMI_EQ_SET_VOLUME_RSP:
            case MSG_ID_MMI_SMS_ATCMD_CMGL_RES_RSP:
                OslFreeInterTaskMsg(&queueNode);
                break;

            case MSG_ID_MMI_EQ_KEYPAD_DETECT_IND:
            {
                mmi_frm_process_key_in_nvarm((void *)queueNode.oslDataPtr);
                OslFreeInterTaskMsg(&queueNode);
                break;
            }

            /* We don't need to handle MSG_ID_MMI_EQ_GET_RTC_TIME_RSP in special condition */
            case MSG_ID_TIMER_EXPIRY:
            {
                /* only process non-alignment timer during power-up */
                if ( (srv_bootup_is_completed() == MMI_FALSE) &&
                     !mmi_frm_is_align_base_timer(&queueNode))
                {
                    MMI_TRACE(PLUTO_FW_TRC_NVRAM, TRC_MMI_FRM_TASK_IN_NVRAM_PROCEDURE_HANDLE_TIMER_MSG);

                    //EvshedMMITimerHandler(get_local_para_ptr(queueNode.oslDataPtr, &msg_len));
                    EvshedMMITimerHandler(&queueNode);
                    OslFreeInterTaskMsg(&queueNode);
                    /* reset circularQ check result to ensure that circularQ can be checked
                       when recursive situation */
                    circularQ_check_result = circularQ_check_never_check;
                    break;
                }
                else
                {
                    stack_timer_struct *stack_timer_ptr;

                    stack_timer_ptr = (stack_timer_struct*) queueNode.oslDataPtr;
                    if (!stack_is_time_out_valid(stack_timer_ptr))
                    {
 
                        OslFreeInterTaskMsg(&queueNode);
                        break;
                    }
                }
                toPush = MMI_TRUE;
                break;
            }

            case MSG_ID_NVRAM_READ_CNF:
            {
                nvram_read_cnf_struct *readMessage;
                peer_buff_struct *peer_buff_ptr;
                kal_uint16 length = 0;
                kal_uint8 *pdu_ptr = NULL; 
                readMessage = (nvram_read_cnf_struct *)queueNode.oslDataPtr;
                peer_buff_ptr = queueNode.oslPeerBuffPtr;
                pdu_ptr = (kal_uint8*) get_pdu_ptr(peer_buff_ptr, &length);
                if (readMessage->file_idx != nLID)
                {
                    nvram_req_count++;
                #ifdef MMI_FRM_NVRAM_UT
                    nvram_req_count_ut++;
                #endif
                }
                else
                {
                    ASSERT(readMessage->result == NVRAM_ERRNO_SUCCESS);
                    memcpy(pBuffer, pdu_ptr, readMessage->length > nBufferSize ? nBufferSize : readMessage->length);
                    status = readMessage->length;  
                    goto end;
                }
                toPush = MMI_TRUE;
                break;
            }

            case MSG_ID_NVRAM_WRITE_CNF:
            {

                nvram_write_cnf_struct *writeMessage;

                writeMessage = (nvram_write_cnf_struct*) queueNode.oslDataPtr;

                if(writeMessage->access_id == WRITE_NVRAM_SYNC)
                {
                    if (writeMessage->file_idx != nLID)
                    {

                    	nvram_req_count++;
                	#ifdef MMI_FRM_NVRAM_UT
                    	nvram_req_count_ut++;
                	#endif         

                	}
                    else
                    {
                        ASSERT(writeMessage->result == NVRAM_ERRNO_SUCCESS);
                        status = nBufferSize;                  	  
                        goto end;
                    }
                }
                toPush = MMI_TRUE;
                break;
            }

            case MSG_ID_NVRAM_RESET_CNF:
            {
                nvram_reset_cnf_struct *rsp_msg;
                
                status = 1;
                rsp_msg = (nvram_reset_cnf_struct *)queueNode.oslDataPtr;
                ASSERT(rsp_msg->result == MMI_OK);
                OslFreeInterTaskMsg(&queueNode);
                
                kal_change_priority_by_index(INDX_NVRAM, TASK_PRIORITY_NVRAM);
                mmi_frm_set_event_flag(MMI_EVT_F_NOT_IN_NVRAM);
                in_nvram_procedure--;
                return status;
            }

            default:
            {
                toPush = MMI_TRUE;
                break;
            }
        }

        if (toPush == MMI_TRUE)
        {
            OslWriteCircularQ(&queueNode);
			     if ((queueNode.src_mod_id != MOD_TIMER) )
                {
                    hold_local_para(queueNode.local_para_ptr);
                    hold_peer_buff(queueNode.peer_buff_ptr);
                }
                OslFreeInterTaskMsg(&queueNode);
        }
    }


end:
    OslFreeInterTaskMsg(&queueNode);
    if (nvram_req_count && circularQ_check_result == circularQ_check_found)
    {
        nvram_req_count--;
        #ifdef MMI_FRM_NVRAM_UT
            nvram_req_count_ut--;
        #endif                        
    }

    in_nvram_procedure--;
    if (in_nvram_procedure == 0)
    {
        mmi_frm_set_event_flag(MMI_EVT_F_NOT_IN_NVRAM);
        kal_change_priority_by_index(INDX_NVRAM, TASK_PRIORITY_NVRAM);
    }
    return status;       
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cache_search_index
 * DESCRIPTION
 *  search data item id in resgen table(mmi_rp_mmi_cache_table.c), return the index.
 * PARAMETERS
 *  nDataItemId     :[IN]        Data Item ID of Byte, Short or Double
 *  nDataType       :[IN]        DS_BYTE, DS_SHORT, DS_DOUBLE
 * RETURNS
 * return the index in resgen table(mmi_rp_mmi_cache_table.c).
 *****************************************************************************/
 S16 mmi_cache_search_index(U16 nDataItemId, U8 nDataType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 index;
    U16* cache_enum_table;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nDataType = CacheSizeToIndex(nDataType);
	cache_enum_table = g_rp_cache_id[nDataType]();
    for(index=0; index<cache_max_id[nDataType](); index++)
    {
        if (cache_enum_table[index] == nDataItemId)
        {
            return index;
        }
    }
	return -1;
}


/*****************************************************************************
 * FUNCTION
 *  ReadValue
 * DESCRIPTION
 *  Internal used function for read 1, 2 or 8 bytes from cache or NVRAM
 *  
 * PARAMETERS
 *  nDataItemId     :[IN]        Data Item ID of Byte, Short or Double
 *  pBuffer         :[OUT]        buffer for read data, 1, 2 or 8 Bytes according to the nDataType
 *  nDataType       :[IN]        DS_BYTE, DS_SHORT, DS_DOUBLE
 *  pError          :[OUT]       Success: NVRAM_READ_SUCCESS
 *                                 Fail: -1
 *                                Other: NVRAM_ERROR_ACTUAL_READ_GREATER_THAN_REQUESTED_READ
 *                                       NVRAM_ERROR_ACTUAL_READ_LESS_THAN_REQUESTED_READ
 * RETURNS
 *  Success return datasize 1, 2 or 8 by the nDataType
 *  Failure return -1;
 *****************************************************************************/
S32 ReadValue(U16 nDataItemId, void *pBuffer, U8 nDataType, S16 *pError)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 status = -1;
    S16  id_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    MMI_ASSERT(is_cache_rearrange);
    id_index = mmi_cache_search_index(nDataItemId, nDataType);
    MMI_ASSERT(id_index >= 0);
    nDataType = CacheSizeToIndex(nDataType);
    if (dataReadFlag[nDataType] == MMI_FALSE)
    {
        status = ReadRecordInCache(
                    cache_lid[nDataType],
                    1,
                    cache_buf[nDataType],
                    NVRAM_CACHE_SIZE);

        dataReadFlag[nDataType] = MMI_TRUE;
    }
    
    memcpy(pBuffer, &cache_buf[nDataType][id_index * cache_data_size[nDataType]], cache_data_size[nDataType]);
    status = cache_data_size[nDataType];
    *pError = NVRAM_READ_SUCCESS;
    return status;
}


/*****************************************************************************
 * FUNCTION
 *  WriteValue
 * DESCRIPTION
 *  Internal used function for write 1, 2 or 8 bytes to cache or NVRAM
 * PARAMETERS
 *  nDataItemId     :[IN]        Data Item ID of Byte, Short or Double
 *  pBuffer         :[IN]        Data to be written, 1, 2 or 8 Bytes according to the nDataType
 *  nDataType       :[IN]        DS_BYTE, DS_SHORT, DS_DOUBLE
 *  pError          :[OUT]       Success: NVRAM_WRITE_SUCCESS  Fail: -1
 * RETURNS
 *  Success return datasize 1, 2 or 8 by the nDataType
 *  Failure return -1;
 *****************************************************************************/
S32 WriteValue(U16 nDataItemId, void *pBuffer, U8 nDataType, S16 *pError)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 status = -1;
    S16  id_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_ASSERT(is_cache_rearrange);
    id_index = mmi_cache_search_index(nDataItemId, nDataType);
    MMI_ASSERT(id_index >= 0);
    nDataType = CacheSizeToIndex(nDataType);
    MMI_ASSERT(id_index < cache_max_id[nDataType]());
    if (dataReadFlag[nDataType] == MMI_FALSE)
    {
        status = ReadRecordInCache(
                     cache_lid[nDataType],
                     1,
                     cache_buf[nDataType],
                     NVRAM_CACHE_SIZE);
        
        dataReadFlag[nDataType] = MMI_TRUE;
    }
    /* Write to cache */
    memcpy(&cache_buf[nDataType][id_index * cache_data_size[nDataType]], pBuffer, cache_data_size[nDataType]);
    /* write into NVRAM module, if not wait for falshing directly */
    if (dataWriteFlashFlag[nDataType] == MMI_FALSE)
    {
        status = WriteRecordInCache(
                    cache_lid[nDataType],
                    1,
                    cache_buf[nDataType],
                    NVRAM_CACHE_SIZE);
    }
    
    status = cache_data_size[nDataType];
	*pError = NVRAM_WRITE_SUCCESS;
    return status;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_default_cache_value
 * DESCRIPTION
 *  get nvram cache default value
 *  
 *  
 * PARAMETERS
 *  cache_type            :[IN]  DS_BYTE, DS_SHORT, DS_DOUBLE
 *  data_item_id          :[IN]  Record Index
 *  buffer_p              :[IN]  Data to be writen
 * 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_get_default_cache_value(U8 cache_type, U16 data_item_id, U8 * buffer_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 * cache_buffer_p;
    U8  res;
    S16 id_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    id_index = mmi_cache_search_index(data_item_id, cache_type);
    MMI_ASSERT(id_index >= 0);
    cache_type = CacheSizeToIndex(cache_type);
    res = nvram_get_default_value(cache_lid[cache_type], 1, &cache_buffer_p);
    switch(res)
    {
        case NVRAM_DEFAULT_VALUE_POINT:
            memcpy(buffer_p, &cache_buffer_p[id_index * cache_data_size[cache_type]], cache_data_size[cache_type]); 
            break;
            
        case NVRAM_DEFAULT_VALUE_ZERO:
            memset(buffer_p, 0x00, cache_data_size[cache_type]);
            break;
            
        case NVRAM_DEFAULT_VALUE_FF:
            memset(buffer_p, 0xFF, cache_data_size[cache_type]);
            break;
            
        default:
            MMI_ASSERT(0);
            break;
    }
       
} 


/*****************************************************************************
 * FUNCTION
 *  ReadRecord
 * DESCRIPTION
 *  This function is to read record from NVRAM.
 * PARAMETERS
 *  nLID            :[IN]        NVRAM Data Item LID
 *  nRecordId       :[IN]        Record Index
 *  pBuffer         :[OUT]       read data buffer
 *  nBufferSize     :[IN]        buffer size
 *                              Fail:   NVRAM_READ_FAIL
 *                              Other:  NVRAM_ERROR_ACTUAL_READ_GREATER_THAN_REQUESTED_READ
 *                                      NVRAM_ERROR_ACTUAL_READ_LESS_THAN_REQUESTED_READ
 * RETURNS
 *  Data read success return data read number, fail return -1, FS Check 0
 *****************************************************************************/
S32 ReadRecord(nvram_lid_enum nLID, U16 nRecordId, void *pBuffer, U16 nBufferSize, S16 *pError)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(PLUTO_FW_TRC_NVRAM, TRC_MMI_FRM_NVRAM_READ_RECORD_BEGIN, nLID, nRecordId);
    
    res =  AccessRecordInt(nLID,nRecordId,pBuffer,nBufferSize, 1, 1, MMI_FALSE, MMI_FALSE,MMI_FALSE);
	*pError = NVRAM_READ_SUCCESS;
    return res;
}


/*****************************************************************************
 * FUNCTION
 *  ReadMultiRecord
 * DESCRIPTION
 *  This function is to read multi-record from NVRAM.
 * PARAMETERS
 *  nLID            :[IN]        NVRAM Data Item LID
 *  nRecordId       :[IN]        Record Index
 *  pBuffer         :[OUT]       read data buffer
 *  nBufferSize     :[IN]        buffer size
 *  nRecordAmount   :[IN]        Record amount
 *  pError          :[OUT]       Success:NVRAM_READ_SUCCESS
 *                              Fail:   NVRAM_READ_FAIL
 *                              Other:  NVRAM_ERROR_ACTUAL_READ_GREATER_THAN_REQUESTED_READ
 *                                      NVRAM_ERROR_ACTUAL_READ_LESS_THAN_REQUESTED_READ
 * RETURNS
 *  Data read success return data read number, fail return -1, FS Check return 0
 *****************************************************************************/
S32 ReadMultiRecord(nvram_lid_enum nLID, U16 nRecordId, void *pBuffer, U16 nBufferSize, U16 nRecordAmount, S16 *pError)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 res;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  
    MMI_TRACE(PLUTO_FW_TRC_NVRAM, TRC_MMI_FRM_NVRAM_READ_MULTI_RECORD_BEGIN, nLID, nRecordId, nRecordAmount);
   

    res = AccessRecordInt(nLID, nRecordId, pBuffer, nBufferSize, nRecordAmount, 1, MMI_FALSE, MMI_FALSE, MMI_FALSE);
	 *pError = NVRAM_READ_SUCCESS;
    return res;
}


/*****************************************************************************
 * FUNCTION
 *  WriteRecord
 * DESCRIPTION
 *  This function is to write record to NVRAM.
 * PARAMETERS
 *  nLID            :[IN]       NVRAM Data Item LID 
 *  nRecordId       :[IN]       Record Index
 *  pBuffer         :[IN]       Data to be written
 *  nBufferSize     :[IN]       Data Size
 * RETURNS
 *  Data write success return nBuffersize, fail return -1
 *****************************************************************************/
S32 WriteRecord(nvram_lid_enum nLID, U16 nRecordId, void *pBuffer, U16 nBufferSize, S16 *pError)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
    MMI_TRACE(PLUTO_FW_TRC_NVRAM, TRC_MMI_FRM_NVRAM_WRITE_RECORD_BEGIN, nLID, nRecordId);
   
    res = AccessRecordInt(nLID, nRecordId, pBuffer, nBufferSize, 1, 1, MMI_TRUE, MMI_FALSE, MMI_FALSE);
	 *pError = NVRAM_WRITE_SUCCESS;
    return res;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_reset_record
 * DESCRIPTION
 *  This function is used to reset nvram record to default value
 *  Usage:
 *     mmi_frm_reset_record(NVRAM_RESET_CERTAIN, app_id, 0, 0, 0);
 * PARAMETERS
 *  reset_category            :[IN]  NVRAM Data Item ID
 *  app_id                    :[IN]  app id see enum nvram_restore_app_enum
 *  lid                       :[IN]  Record Index
 *  rec_index                 :[IN]  Data to be writen
 *  record_amount             :[IN]  Size of data to be writen
 * RETURNS
 *  1 - success full, 0 - fail
 *****************************************************************************/
S32 mmi_frm_reset_record(U8 reset_category, U16 app_id, nvram_lid_enum lid, U16 rec_index, U16 record_amount)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 res;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((srv_bootup_is_completed() == MMI_TRUE) || (is_cache_rearrange == MMI_FALSE));

    res = ResetRecordInt(reset_category, app_id, lid, rec_index, record_amount);

    return res;
}


/*****************************************************************************
 * FUNCTION
 *  SetFlashNVRAMCatchData
 * DESCRIPTION
 *  This function is to set one write back flag if want to flash the BYTE,
 *  SHORT, or DOUBLE of catch datas into NVRAM.
 * PARAMETERS
 *  nDataType                   :[IN]     Cache Size type DS_BYTE, DS_SHORT or DS_DOUBLE
 *  l_DataWriteFlashFlag        :[IN]     Flag value MMI_TRUE or MMI_FALSE
 * RETURNS
 *  void
 *****************************************************************************/
void SetFlashNVRAMCatchData(U8 nDataType, MMI_BOOL l_DataWriteFlashFlag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(PLUTO_FW_TRC_NVRAM, TRC_MMI_FRM_NVRAM_SET_FLUSH_CACHE_FLAG, nDataType, l_DataWriteFlashFlag);
    nDataType = CacheSizeToIndex(nDataType);
    dataWriteFlashFlag[nDataType] = l_DataWriteFlashFlag;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  SetFlashAllNVRAMCatchData
 * DESCRIPTION
 *  This function is to set the all write back flag if want to flash all the BYTE,
 *  SHORT, and DOUBLE of catch datas into NVRAM.
 * PARAMETERS
 *  l_DataWriteFlashFlag        :[IN]  Flag value MMI_TRUE or MMI_FALSE
 * RETURNS
 *  void
 *****************************************************************************/
void SetFlashAllNVRAMCatchData(MMI_BOOL l_DataWriteFlashFlag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = MMI_FW_NVRAM_BYTE; i < MMI_FW_NVRAM_TYPE_TOTAL; i++)
    {
        MMI_TRACE(PLUTO_FW_TRC_NVRAM, TRC_MMI_FRM_NVRAM_SET_FLUSH_CACHE_FLAG, cache_data_size[i], l_DataWriteFlashFlag);
        dataWriteFlashFlag[i] = l_DataWriteFlashFlag;
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  WriteFlashNVRAMCatchData
 * DESCRIPTION
 *  This function is to write nDataType catch datas into NVRAM if its write back
 *  flag is on.
 * PARAMETERS
 *  nDataType       :[IN]      Cache Size type DS_BYTE, DS_SHORT or DS_DOUBLE
 * RETURNS
 *  -1                 Write Back Failed
 *   0                 no need write back
 *   NVRAM_CACHE_SIZE  Write Back Succeed
 *****************************************************************************/
S32 WriteFlashNVRAMCatchData(U8 nDataType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 status = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nDataType = CacheSizeToIndex(nDataType);
    MMI_TRACE(PLUTO_FW_TRC_NVRAM, TRC_MMI_FRM_NVRAM_FLUSH_CACHE_DATA, nDataType, dataWriteFlashFlag[nDataType]);
    if (dataWriteFlashFlag[nDataType] == MMI_TRUE)
    {
        dataWriteFlashFlag[nDataType] = MMI_FALSE;
        status = WriteRecordInCache(
                    cache_lid[nDataType],
                    1,
                    cache_buf[nDataType],
                    NVRAM_CACHE_SIZE);     
    }
    return status;
}


/*****************************************************************************
 * FUNCTION
 *  WriteFlashAllNVRAMCatchData
 * DESCRIPTION
 *  This function is to write all three type catch data into NVRAM if the 
 *  corresponding write back is on.
 * PARAMETERS
 *  void
 * RETURNS
 *  -1                 Write Back Failed
 *   0                 no need write back
 *   NVRAM_CACHE_SIZE  Write Back Succeed
 *****************************************************************************/
S32 WriteFlashAllNVRAMCatchData(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 status = 0;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = MMI_FW_NVRAM_BYTE; i < MMI_FW_NVRAM_TYPE_TOTAL; i++)
    {
        MMI_TRACE(PLUTO_FW_TRC_NVRAM, TRC_MMI_FRM_NVRAM_FLUSH_CACHE_DATA, cache_data_size[i], dataWriteFlashFlag[i]);
        if (dataWriteFlashFlag[i] == MMI_TRUE)
        {
            dataWriteFlashFlag[i] = MMI_FALSE;
            status = WriteRecordInCache(
                        cache_lid[i],
                        1, 
                        cache_buf[i],
                        NVRAM_CACHE_SIZE);
        }
    }
    return status;
}


/*****************************************************************************
 * FUNCTION
 *  IsInNVRAMProcedure
 * DESCRIPTION
 *  This function is to check if in NVRAM procedure while loop
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE - in NVRAM procedure
 *  MMI_FALSE - not in NVRAM procedure
 *****************************************************************************/
MMI_BOOL IsInNVRAMProcedure(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(PLUTO_FW_TRC_NVRAM, TRC_MMI_FRM_NVRAM_JUDGE_IS_PROCEDURE, in_nvram_procedure);
    return (in_nvram_procedure > 0) ? MMI_TRUE : MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nvram_cache_restore_factory_mode
 * DESCRIPTION
 *  MMI Cache restore factory mode, add this API for HAL
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_nvram_cache_restore_factory_mode(void)
{
#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //nvram_ltable_entry_struct *ldi;
    kal_uint8 *buffer = NULL;
    U32 i;
    
    kal_bool status = KAL_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!nvram_check_restore_factory_flag())
        return;

    buffer = (kal_uint8*) get_ctrl_buffer(NVRAM_CACHE_SIZE);

    for (i = 0; i < sizeof(cache_lid) / sizeof(cache_lid[0]); i++)
    {
        status = nvram_external_read_data(cache_lid[i], 1, buffer, NVRAM_CACHE_SIZE);
        EXT_ASSERT(status == KAL_TRUE, status, cache_lid[i], __LINE__);
        //nvram_restore_byte_cache(NVRAM_RESET_FACTORY, 0, buffer);
        ( *restore_func_table[i])(NVRAM_RESET_FACTORY, 0, buffer);
        status = nvram_external_write_data(cache_lid[i], 1, buffer, NVRAM_CACHE_SIZE);
        EXT_ASSERT(status == KAL_TRUE, status, cache_lid[i], __LINE__);      
    }
    
    free_ctrl_buffer(buffer);
    
    nvram_set_restore_factory_flag(NVRAM_RESTORE_FALSE);

#endif

}


/*************The following extern variable is from NVRAM tag resgen******************
    mmi_rp_mmi_cache_table.h
*************************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nvram_cache_validate
 * DESCRIPTION
 *  This function is called in power on procedure. Each power on  mode will call this function
 *  to check if user has modified mmi cache. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_nvram_cache_validate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U32* key_pool;
    U32 i;
    MMI_BOOL result;
    U32 j;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* it the last power off comes from restore factory mode need to reset mmi cache at this boot up */
    mmi_frm_nvram_cache_restore_factory_mode();
    
    if (!is_cache_rearrange)
    {
        SetFlashAllNVRAMCatchData(MMI_TRUE); 
        key_pool = (U32*)applib_asm_alloc_anonymous(NVRAM_CACHE_VALIDATE_TEMP_BUF_SIZE);
        /*read mmi application cache nvram data and mmi cache key value */

        for(i = 0; i < sizeof(cache_lid) / sizeof(cache_lid[0]); i++)
        {
            ReadRecord(cache_lid[i], 1, cache_buf[i], NVRAM_CACHE_SIZE, &error);
            
            /*  cache key value */
            for (j = 0; j < cache_key_record[i]; j++)
            {
                ReadRecord(cache_key_lid[i], j + 1, ((U8*)key_pool) + j * cache_key_size[i], cache_key_size[i], &error);
            }
            // we need to test the boundary value !!!!
            result = mmi_frm_nvram_cache_file_commpare((U32*)cache_key_table[i], 
                                                        key_pool,
                                                        i, 
                                                        cache_key_size[i] * cache_key_record[i] / sizeof(kal_uint32), 
                                                        cache_buf[i]);
            // Read other two cache  
            // write cache record back to nvram.
            if (result)
            {
                WriteRecord(cache_lid[i], 1, cache_buf[i], NVRAM_CACHE_SIZE, &error);
    
                mmi_frm_reset_record(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, cache_key_lid[i], 1, cache_key_record[i]);
            }

            dataReadFlag[i] = MMI_TRUE;
            
        }

        is_cache_rearrange = MMI_TRUE;
        applib_asm_free_anonymous(key_pool);
    }
    

}

mmi_ret mmi_frm_nvram_bootup_write_request(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    SetFlashAllNVRAMCatchData(MMI_FALSE);

    for (i = 0; i < sizeof(cache_lid) / sizeof(cache_lid[0]); i++) 
    {
        mmi_frm_write_async_record(cache_lid[i], 1, cache_buf[i], NVRAM_CACHE_SIZE);
    }
     
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cache_move_buffer
 * DESCRIPTION
 *  move mmi cache buffer according to the 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_cache_move_buffer(U16 cache_type, U8* cache_buffer, U32 need_move_num,  U32* need_move, U8 move_size, U16 cache_size)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    U32 move;
    U16 del_num = 0, add_num  = 0;
    U16 resgen_index;
    U16 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* first delete cache id buffer and then add new cache id to avoid the not enough cache for add */
    for(index=0; index< need_move_num; index++)
    {
        move = need_move[index] & 0xFFFF0000;
        if (0xFFFF0000 == move) // delete item
        {
            move = (need_move[index] & 0x0000FFFF) - del_num;
            memmove(&cache_buffer[move * move_size], &cache_buffer[(move + 1) * move_size],
                    cache_size - (move+1) * move_size);
            memset(&cache_buffer[cache_size-1*move_size], 0x00, move_size);
            del_num++;
            
        }
        else // add item
        {
            move = need_move[index] & 0x0000FFFF; // Lower 16 bits
            move = move - del_num;
            need_move[index] = (need_move[index] & 0xFFFF0000) | move;

        }
    }
    for(index=0; index< need_move_num; index++)
    {
        move = need_move[index] & 0xFFFF0000;

        if (0xFFFF0000 != move)// add case
        {
			move = (need_move[index] & 0x0000FFFF) + add_num;
            resgen_index = (need_move[index] & 0xFFFF0000) >> 16;
            memmove(&cache_buffer[(move+1) * move_size], &cache_buffer[move * move_size],
                    cache_size - move * move_size - move_size);
            
            for (i=0; i< move_size; i++)
            {
                U8* cache_buffer_p;
                U8  res;
                #ifndef MMI_FRM_NVRAM_UT
                    #ifndef __NVRAM_COMPRESS_SUPPORT__
                    //memset(&cache_buffer[move*move_size + i], (g_rp_cache_default[cache_type]())[move_size*resgen_index+i], 1); // if needs to set default value    
                    res = nvram_get_default_value(cache_lid[cache_type], 1, &cache_buffer_p);
                    if (res == NVRAM_DEFAULT_VALUE_POINT)
                    {
                        memset(&cache_buffer[move*move_size + i], cache_buffer_p[move_size*resgen_index+i], 1);
                    }
                    else
                    {
                        memset(&cache_buffer[move*move_size + i], 0xFF, 1);
                    }       

                    #endif
                    #ifdef __NVRAM_COMPRESS_SUPPORT__
                    memset(&cache_buffer[move*move_size + i], 0xFF, 1); // if needs to set default value    
                    #endif

                #else
                memset(&cache_buffer[move*move_size + i], 0xFF, 1);
                #endif
            }

            add_num++;
        }
    
    }




}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nvram_cache_file_commpare
 * DESCRIPTION
 *  compare the FAT and resgen result. 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_frm_nvram_cache_file_commpare(U32* resgen_pool, U32* key_pool, U16 cache_type, U16 num, U8* cache_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0, j = 0;
    /*when the key value is not equal to the resgen result. we will put the add or delete index
      in the array. And do memory move in the last. if the high 16 bits is 0xFFFF, it will be the 
      delete element*/
    U32* need_move;
    U32 need_move_num = 0;
    //U32 output[20]; //for UT
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //need_move= output; // for UT
    need_move = &key_pool[520];//start from 520, need to config screen based asm.
    while((i < num) && (j < num))
    {

        /* find the FAT key value is not equal to resgen result. */    
        if(resgen_pool[i] != key_pool[j])
        {
            if (resgen_pool[i] > key_pool[j]) // resgen delete a item.
            {   
                MMI_TRACE(PLUTO_FW_TRC_NVRAM, TRC_MMI_FRM_NVRAM_CACHE_DEL, cache_type, j);
                need_move[need_move_num] = j | 0xFFFF0000; // we will move according to FAT key value              
                need_move_num++;
                j++;//j will not change.
                continue;
                                        
            }       
            if (resgen_pool[i] < key_pool[j])// add or delete, both of them are possible
            {
                // first we will judge if j is delete
                U32 index;
                for(index = 1; i+index < num; index++)
                {
                    if (resgen_pool[i+index] == key_pool[j])
                    {
                        break; //j will not delete
                    
                    }
                    else if (resgen_pool[i+index] > key_pool[j])
                    {
                        MMI_TRACE(PLUTO_FW_TRC_NVRAM, TRC_MMI_FRM_NVRAM_CACHE_DEL, cache_type, j);
                        //j will be delelte
                        need_move[need_move_num] = j | 0xFFFF0000; // we will move according to FAT key value              
                        need_move_num++;
                        j++;//j will not change.
                        break;
                    }            
                }
                //put the new id index in higher 16 bits, put the original key buffer index in lower 16 bits
               MMI_TRACE(PLUTO_FW_TRC_NVRAM, TRC_MMI_FRM_NVRAM_CACHE_ADD, cache_type, j);
               need_move[need_move_num] = i;
               need_move[need_move_num] = (need_move[need_move_num] << 16) & 0xFFFF0000;
  
               need_move[need_move_num] = need_move[need_move_num] | j; // we will move according to FAT key value
               
            
               
               need_move_num++;
               i++;
            
            }
            

        }
        else
        {
            i++;
            j++;
        }
    }
    if (need_move_num > 0)
    {
        MMI_TRACE(PLUTO_FW_TRC_NVRAM, TRC_MMI_FRM_NVRAM_REARRANGE_CACHE_BUFFER, cache_type, need_move_num);
        #ifndef MMI_FRM_NVRAM_UT
        mmi_cache_move_buffer(cache_type, cache_buffer, need_move_num, need_move, cache_data_size[cache_type], NVRAM_CACHE_SIZE);
        #else
                
        mmi_cache_move_buffer(cache_type, cache_buffer, need_move_num, need_move, cache_data_size[cache_type], 20);
        #endif
        return MMI_TRUE;                   
     }
     return MMI_FALSE;

}




/*****************************************************************************
 * Unit Test Case
 *****************************************************************************/
#ifdef MMI_FRM_NVRAM_UT
/* Function Declaration for UT */ 
static void mmi_frm_nvram_ut_IsInNVRAMProcedure(void);
static void mmi_frm_nvram_ut_SetFlashNVRAMCatchData(void);
static void mmi_frm_nvram_ut_SetFlashAllNVRAMCatchData(void);
static void mmi_frm_nvram_ut_WriteFlashNVRAMCatchData(void);
static void mmi_frm_nvram_ut_WriteFlashAllNVRAMCatchData(void);
static void mmi_frm_nvram_ut_WriteValue(void);
static void mmi_frm_nvram_ut_ReadValue(void);
static void mmi_frm_nvram_ut_WriteReadValue(void);
static void mmi_frm_nvram_ut_WriteRecord(void);
static void mmi_frm_nvram_ut_ReadRecord(void);
static void mmi_frm_nvram_ut_ReadMultiRecord(void);
static void mmi_frm_nvram_ut_WhileLoopRecursiveTest(void);
static void mmi_frm_nvram_ut_mmi_frm_reset_record(void);
typedef void (*mmi_frm_auto_ut_funPtr)(void);
static void mmi_frm_nvram_write_async_case_ut(void);
static void mmi_frm_nvram_new_mmi_cache(void);
static U8 g_back_buf[NVRAM_CACHE_SIZE];

/* Global table for UT */
static mmi_frm_auto_ut_funPtr g_mmi_frm_nvram_ut_table[] = 
{
    mmi_frm_nvram_new_mmi_cache,
    mmi_frm_nvram_write_async_case_ut,
    mmi_frm_nvram_ut_ReadRecord,
    mmi_frm_nvram_ut_ReadMultiRecord, 
    mmi_frm_nvram_ut_WriteRecord,
    mmi_frm_nvram_ut_ReadValue,
    mmi_frm_nvram_ut_WriteValue,
    mmi_frm_nvram_ut_WriteReadValue,
    mmi_frm_nvram_ut_IsInNVRAMProcedure,
    mmi_frm_nvram_ut_SetFlashNVRAMCatchData,
    mmi_frm_nvram_ut_SetFlashAllNVRAMCatchData,
    mmi_frm_nvram_ut_WriteFlashNVRAMCatchData,
    mmi_frm_nvram_ut_WriteFlashAllNVRAMCatchData,
    mmi_frm_nvram_ut_WhileLoopRecursiveTest,
    mmi_frm_nvram_ut_mmi_frm_reset_record,

};

#define MMI_FRM_NVRAM_UT_SIZE (sizeof(g_mmi_frm_nvram_ut_table) / sizeof(g_mmi_frm_nvram_ut_table[0]))


static	U32 resgen_pool[16] = {1,3,5,7,9,11,13,15, 16, 17,19,21,23,25,27};
static	U8 buffer[32] =       {1,1, 3, 3,4,4,4,4,7,7,9,9,10,10, 10,10, 11,11,13,13,17,17,19,19,21,21,23,23,25,25,27,27};
static	U32 key_pool[16] =    {1,3,4,4,7,9,10, 10, 11,13,17,19,21,23,25,27};

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_file_compare_ut
 * DESCRIPTION
 *  For new mmi cache mechanism, different cache verson
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_file_compare_ut(void)
{

    
    mmi_frm_nvram_cache_file_commpare(resgen_pool, key_pool, MMI_FW_NVRAM_SHORT, 16,  buffer);
	
}


void mmi_frm_nvram_new_mmi_cache(void)
{
 	S16 error;
    U8 value;
    U8 value1[DS_SHORT];
    U8 value2[DS_DOUBLE];
    U8 output[DS_DOUBLE] = {0xEE, 0xEE, 0xEE,0xEE, 0xEE, 0xEE, 0xEE, 0xEE};
 /*   ReadValue(NVRAM_Frameowork_BYTE, &value, DS_BYTE, &error);
    MMI_ASSERT(memcmp(&value, &output, DS_BYTE) == 0);
    ReadValue(NVRAM_FRAMWORK_SHORT1, &value1, DS_SHORT, &error);
    MMI_ASSERT(memcmp(&value1, &output, DS_SHORT) == 0);
    ReadValue(NVRAM_FRAMWORK_SHORT2, &value1, DS_SHORT, &error);
    MMI_ASSERT(memcmp(&value1, &output, DS_SHORT) == 0);
    ReadValue(NVRAM_FRAMWORK_SHORT3, &value1, DS_SHORT, &error);
    MMI_ASSERT(memcmp(&value1, &output, DS_SHORT) == 0);
    ReadValue(NVRAM_FRAMEWORK_DOUBLE, &value2, DS_DOUBLE, &error);
    MMI_ASSERT(memcmp(&value2, &output, DS_DOUBLE) == 0);*/
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nvram_async_case_event_handler
 * DESCRIPTION
 *  protocol event handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_frm_nvram_async_case_event_handler(void * msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_write_cnf_struct *nvram_write_cnf;
    U8 back_buf[NVRAM_CACHE_SIZE];
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_print("This is the async case of write record!!!");
    nvram_write_cnf = (nvram_write_cnf_struct *)msg;
    if (nvram_write_cnf->file_idx == NVRAM_EF_CACHE_SHORT_LID)
    { 
        mmi_frm_clear_protocol_event_handler(MSG_ID_NVRAM_WRITE_CNF, mmi_frm_nvram_async_case_event_handler);
        MMI_ASSERT(nvram_write_cnf->result == NVRAM_IO_ERRNO_OK);
        ReadRecord(NVRAM_EF_CACHE_SHORT_LID, 1, back_buf, NVRAM_CACHE_SIZE, &error);
        MMI_ASSERT(memcmp(back_buf, back_buf, NVRAM_CACHE_SIZE) == 0);
		kal_print("This is the async case of write record done!!!");
        return 1;
    }
    MMI_ASSERT(0);
    return 0;    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nvram_write_async_case_ut
 * DESCRIPTION
 *  Test write record async case.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_nvram_write_async_case_ut(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_protocol_event_handler(MSG_ID_NVRAM_WRITE_CNF, mmi_frm_nvram_async_case_event_handler, MMI_TRUE);
    ReadRecord(NVRAM_EF_CACHE_SHORT_LID, 1, g_back_buf, NVRAM_CACHE_SIZE, &error);    
    mmi_frm_write_async_record(NVRAM_EF_CACHE_SHORT_LID, 1, g_back_buf, NVRAM_CACHE_SIZE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nvram_ut_mmi_frm_reset_record
 * DESCRIPTION
 *  mmi_frm_reset_record unit test
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_nvram_ut_mmi_frm_reset_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  //  S32 status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  //  status = mmi_frm_reset_record(NVRAM_RESET_FACTORY, NVRAM_APP_PHNSET, 0, 0, 0);
  //   status = mmi_frm_reset_record(NVRAM_RESET_FACTORY, 0, 0, 0, 0);
  //  MMI_ASSERT(status == 1);


    S16 error;
    S32 ret, i;
    kal_uint8 *dft_ptr;
    U8 buff[NVRAM_MMI_CACHE_BYTE_KEY_SIZE];
    U8 buff_backup[NVRAM_MMI_CACHE_BYTE_KEY_SIZE];
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = ReadRecord(NVRAM_EF_MMI_CACHE_BYTE_KEY_LID, 1, buff_backup, NVRAM_MMI_CACHE_BYTE_KEY_SIZE, &error);
    MMI_ASSERT(ret == NVRAM_MMI_CACHE_BYTE_KEY_SIZE && error == NVRAM_READ_SUCCESS);
    
    ret = mmi_frm_reset_record(NVRAM_RESET_CERTAIN, NVRAM_APP_RESERVED, NVRAM_EF_MMI_CACHE_BYTE_KEY_LID, 1, 1);
    MMI_ASSERT(ret > 0);

    /* check reset operation correctness */
    MMI_ASSERT(nvram_get_default_value(NVRAM_EF_MMI_CACHE_BYTE_KEY_LID, 1, &dft_ptr) == NVRAM_DEFAULT_VALUE_POINT);
    ret = ReadRecord(NVRAM_EF_MMI_CACHE_BYTE_KEY_LID, 1, buff, NVRAM_MMI_CACHE_BYTE_KEY_SIZE, &error);
    MMI_ASSERT(ret == NVRAM_MMI_CACHE_BYTE_KEY_SIZE && error == NVRAM_READ_SUCCESS);
    for (i = 0; i < NVRAM_MMI_CACHE_BYTE_KEY_SIZE; i++)
    {
        MMI_ASSERT(buff[i] == dft_ptr[i]);
    }

    /* restore original data */
    ret = WriteRecord(NVRAM_EF_MMI_CACHE_BYTE_KEY_LID, 1, buff_backup, NVRAM_MMI_CACHE_BYTE_KEY_SIZE, &error);
    MMI_ASSERT(ret == NVRAM_MMI_CACHE_BYTE_KEY_SIZE && error == NVRAM_WRITE_SUCCESS);
    
}


/*****************************************************************************
 * FUNCTION
 *  SetInNVRAMProcedure
 * DESCRIPTION
 *  Set the value of in_nvram_procedure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void SetInNVRAMProcedure(U8 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    in_nvram_procedure = value;
}


/*****************************************************************************
 * FUNCTION
 *  GetInNVRAMProcedure
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 GetInNVRAMProcedure(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return in_nvram_procedure;
}


/*****************************************************************************
 * FUNCTION
 *  SetCacheBuffer
 * DESCRIPTION
 *  This function is to set cache buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void SetCacheBuffer(U8 nDataType, U8 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nDataType = CacheSizeToIndex(nDataType);
    memset(cache_buf[nDataType], value, NVRAM_CACHE_SIZE);
}


/*****************************************************************************
 * FUNCTION
 *  WhileLoopRecursiveTest2
 * DESCRIPTION
 *  Check NVRAM while loop nested
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void WhileLoopRecursiveTest2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp[NVRAM_CACHE_SIZE];
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (in_nvram_procedure == 2 && nvram_req_count_ut == 1)
    {
        ReadRecord(NVRAM_EF_CACHE_DOUBLE_LID, 1, temp, NVRAM_CACHE_SIZE, &error);
    }
    else
    {
        StartNonAlignTimer(AT_TEST_TIMER, 1, WhileLoopRecursiveTest2);
    }
}


/*****************************************************************************
 * FUNCTION
 *  WhileLoopRecursiveTest1
 * DESCRIPTION
 *  Check NVRAM while loop nested
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void WhileLoopRecursiveTest1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp[NVRAM_CACHE_SIZE];
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StartNonAlignTimer(AT_TEST_TIMER, 1, WhileLoopRecursiveTest2);
    ReadRecord(NVRAM_EF_CACHE_BYTE_LID, 1, temp, NVRAM_CACHE_SIZE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  WhileLoopRecursiveTest
 * DESCRIPTION
 *  Check NVRAM while loop nested
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_nvram_ut_WhileLoopRecursiveTest(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 settingBuffer[NVRAM_SETTING_SIZE] = {0};
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    StartNonAlignTimer(AT_TEST_TIMER, 1, WhileLoopRecursiveTest1);
//    ReadRecord(NVRAM_EF_SETTING_LID, 1, settingBuffer, NVRAM_SETTING_SIZE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nvram_ut_IsInNVRAMProcedure
 * DESCRIPTION
 *  Unit test of function IsInNVRAMProcedure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_nvram_ut_IsInNVRAMProcedure(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    temp = GetInNVRAMProcedure();
    SetInNVRAMProcedure(2);
    MMI_ASSERT(IsInNVRAMProcedure() == MMI_TRUE);
    SetInNVRAMProcedure(0);
    MMI_ASSERT(IsInNVRAMProcedure() == MMI_FALSE);
    SetInNVRAMProcedure(temp);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nvram_ut_SetFlashNVRAMCatchData
 * DESCRIPTION
 *  Unit test of function SetFlashNVRAMCatchData
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_nvram_ut_SetFlashNVRAMCatchData(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetFlashNVRAMCatchData(DS_BYTE, MMI_TRUE);
    SetFlashNVRAMCatchData(DS_SHORT, MMI_TRUE);
    SetFlashNVRAMCatchData(DS_DOUBLE, MMI_TRUE);
    MMI_ASSERT(dataWriteFlashFlag[MMI_FW_NVRAM_BYTE] == MMI_TRUE
               && dataWriteFlashFlag[MMI_FW_NVRAM_SHORT] == MMI_TRUE
               && dataWriteFlashFlag[MMI_FW_NVRAM_DOUBLE] == MMI_TRUE);
    SetFlashNVRAMCatchData(DS_BYTE, MMI_FALSE);
    SetFlashNVRAMCatchData(DS_SHORT, MMI_FALSE);
    SetFlashNVRAMCatchData(DS_DOUBLE, MMI_FALSE);
    MMI_ASSERT(dataWriteFlashFlag[MMI_FW_NVRAM_BYTE] == MMI_FALSE
               && dataWriteFlashFlag[MMI_FW_NVRAM_SHORT] == MMI_FALSE
               && dataWriteFlashFlag[MMI_FW_NVRAM_DOUBLE] == MMI_FALSE);
    SetFlashNVRAMCatchData(DS_BYTE, MMI_FALSE);
    SetFlashNVRAMCatchData(DS_SHORT, MMI_TRUE);
    SetFlashNVRAMCatchData(DS_DOUBLE, MMI_FALSE);
    MMI_ASSERT(dataWriteFlashFlag[MMI_FW_NVRAM_BYTE] == MMI_FALSE
           && dataWriteFlashFlag[MMI_FW_NVRAM_SHORT] == MMI_TRUE
           && dataWriteFlashFlag[MMI_FW_NVRAM_DOUBLE] == MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nvram_ut_SetFlashAllNVRAMCatchData
 * DESCRIPTION
 *  Unit test of function SetFlashAllNVRAMCatchData
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_nvram_ut_SetFlashAllNVRAMCatchData(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetFlashAllNVRAMCatchData(MMI_TRUE);
    MMI_ASSERT(dataWriteFlashFlag[MMI_FW_NVRAM_BYTE] == MMI_TRUE
               && dataWriteFlashFlag[MMI_FW_NVRAM_DOUBLE] == MMI_TRUE
               && dataWriteFlashFlag[MMI_FW_NVRAM_SHORT] == MMI_TRUE);

    SetFlashAllNVRAMCatchData(MMI_FALSE);
    MMI_ASSERT(dataWriteFlashFlag[MMI_FW_NVRAM_BYTE] == MMI_FALSE
               && dataWriteFlashFlag[MMI_FW_NVRAM_SHORT] == MMI_FALSE
               && dataWriteFlashFlag[MMI_FW_NVRAM_DOUBLE] == MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nvram_ut_WriteFlashNVRAMCatchData
 * DESCRIPTION
 *  Unit test of function WriteFlashNVRAMCatchData
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_nvram_ut_WriteFlashNVRAMCatchData(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 temp_int;
    U8 back_buf[NVRAM_CACHE_SIZE];
    U8 temp_buf[NVRAM_CACHE_SIZE];
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetFlashNVRAMCatchData(DS_BYTE, MMI_FALSE);
    temp_int = WriteFlashNVRAMCatchData(DS_BYTE);
    MMI_ASSERT(temp_int == 0);
    SetFlashNVRAMCatchData(DS_SHORT, MMI_TRUE);
    ReadRecord(NVRAM_EF_CACHE_SHORT_LID, 1, back_buf, NVRAM_CACHE_SIZE, &error);
    SetCacheBuffer(DS_SHORT, 55);
    temp_int = WriteFlashNVRAMCatchData(DS_SHORT);
    MMI_ASSERT(temp_int == NVRAM_CACHE_SIZE);
    ReadRecord(NVRAM_EF_CACHE_SHORT_LID, 1, temp_buf, NVRAM_CACHE_SIZE, &error);
    MMI_ASSERT(memcmp(temp_buf, cache_buf[MMI_FW_NVRAM_SHORT], NVRAM_CACHE_SIZE) == 0);
    WriteRecord(NVRAM_EF_CACHE_SHORT_LID, 1, back_buf, NVRAM_CACHE_SIZE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nvram_ut_WriteFlashAllNVRAMCatchData
 * DESCRIPTION
 *  Unit test of function WriteFlashAllNVRAMCatchData
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_nvram_ut_WriteFlashAllNVRAMCatchData(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 temp_int;
    U8  temp_buf[NVRAM_CACHE_SIZE];
    U8  byte_back_buf[NVRAM_CACHE_SIZE];
    U8  short_back_buf[NVRAM_CACHE_SIZE];
    U8  double_back_buf[NVRAM_CACHE_SIZE];
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetFlashAllNVRAMCatchData(MMI_FALSE);
    temp_int = WriteFlashAllNVRAMCatchData();
    MMI_ASSERT(temp_int == 0);
    SetFlashAllNVRAMCatchData(MMI_TRUE);
    ReadRecord(NVRAM_EF_CACHE_BYTE_LID, 1, byte_back_buf, NVRAM_CACHE_SIZE, &error);
    ReadRecord(NVRAM_EF_CACHE_SHORT_LID, 1, short_back_buf, NVRAM_CACHE_SIZE, &error);
    ReadRecord(NVRAM_EF_CACHE_DOUBLE_LID, 1, double_back_buf, NVRAM_CACHE_SIZE, &error);
    SetCacheBuffer(DS_BYTE, 66);
    SetCacheBuffer(DS_SHORT, 77);
    SetCacheBuffer(DS_DOUBLE, 88);
    temp_int = WriteFlashAllNVRAMCatchData();
    MMI_ASSERT(temp_int == NVRAM_CACHE_SIZE);
    ReadRecord(NVRAM_EF_CACHE_BYTE_LID, 1, temp_buf, NVRAM_CACHE_SIZE, &error);
    MMI_ASSERT(memcmp(temp_buf, cache_buf[MMI_FW_NVRAM_BYTE], NVRAM_CACHE_SIZE) == 0);
    ReadRecord(NVRAM_EF_CACHE_SHORT_LID, 1, temp_buf, NVRAM_CACHE_SIZE, &error);
    MMI_ASSERT(memcmp(temp_buf, cache_buf[MMI_FW_NVRAM_SHORT], NVRAM_CACHE_SIZE) == 0);    
    ReadRecord(NVRAM_EF_CACHE_DOUBLE_LID, 1, temp_buf, NVRAM_CACHE_SIZE, &error);
    MMI_ASSERT(memcmp(temp_buf, cache_buf[MMI_FW_NVRAM_DOUBLE], NVRAM_CACHE_SIZE) == 0);         
    WriteRecord(NVRAM_EF_CACHE_BYTE_LID, 1, byte_back_buf, NVRAM_CACHE_SIZE, &error);
    WriteRecord(NVRAM_EF_CACHE_SHORT_LID, 1, short_back_buf, NVRAM_CACHE_SIZE, &error);
    WriteRecord(NVRAM_EF_CACHE_DOUBLE_LID, 1, double_back_buf, NVRAM_CACHE_SIZE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nvram_ut_WriteValue
 * DESCRIPTION
 *  Unit test of function WriteValue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_nvram_ut_WriteValue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 temp_int;
    U8 bytebuf;
    U8 shortbuf[2];
    U8 doublebuf[8];
    U8  back_buf[NVRAM_CACHE_SIZE];
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_CACHE_BYTE_LID, 1, &back_buf, NVRAM_CACHE_SIZE, &error);
    bytebuf = 23;
    temp_int = WriteValue(NVRAM_SMS_MISCELL_SETTING, &bytebuf, DS_BYTE, &error);
    MMI_ASSERT((temp_int == 1) && (error == NVRAM_WRITE_SUCCESS));
    WriteRecord(NVRAM_EF_CACHE_BYTE_LID, 1, back_buf, NVRAM_CACHE_SIZE, &error);
    ReadRecord(NVRAM_EF_CACHE_SHORT_LID, 1, back_buf, NVRAM_CACHE_SIZE, &error);
//    temp_int = WriteValue(NVRAM_WAP_PROF_ACTIVE_MMS_PROFILE_INDEX, shortbuf, DS_SHORT, &error);
  //  MMI_ASSERT((temp_int == 2) && (error == NVRAM_WRITE_SUCCESS));
  //  WriteRecord(NVRAM_EF_CACHE_SHORT_LID, 1, back_buf, NVRAM_CACHE_SIZE, &error);
    ReadRecord(NVRAM_EF_CACHE_DOUBLE_LID, 1, back_buf, NVRAM_CACHE_SIZE, &error);
   // temp_int = WriteValue(NVRAM_CCONV_EXCHANGE_RATE9, doublebuf, DS_DOUBLE, &error);
   // MMI_ASSERT((temp_int == 8) && (error == NVRAM_WRITE_SUCCESS));
    WriteRecord(NVRAM_EF_CACHE_DOUBLE_LID, 1, back_buf, NVRAM_CACHE_SIZE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nvram_ut_ReadValue
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  isTrace trace on/of
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_nvram_ut_ReadValue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 temp_int;
    U8 bytebuf[1];
    U8 shortbuf[2];
    U8 doublebuf[8];
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_int = ReadValue(NVRAM_SMS_MISCELL_SETTING, bytebuf, DS_BYTE, &error);
    MMI_ASSERT((temp_int == 1) && (error == NVRAM_READ_SUCCESS));
    
//    temp_int = ReadValue(NVRAM_WAP_PROF_ACTIVE_MMS_PROFILE_INDEX, shortbuf, DS_SHORT, &error);
 //   MMI_ASSERT((temp_int == 2)&& (error == NVRAM_READ_SUCCESS));
    
  //  temp_int = ReadValue(NVRAM_CCONV_EXCHANGE_RATE9, doublebuf, DS_DOUBLE, &error);
   // MMI_ASSERT((temp_int == 8) && (error == NVRAM_READ_SUCCESS));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nvram_ut_WriteReadValue
 * DESCRIPTION
 *  Unit test Write and then ReadValue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_nvram_ut_WriteReadValue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 temp_int;
    U8 bytebuf[1];
    U8 shortbuf[2];
    U8 doublebuf[8];
    U8 back_buf[NVRAM_CACHE_SIZE];
    U8 temp_buf[NVRAM_CACHE_SIZE];
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetFlashAllNVRAMCatchData(MMI_FALSE);
    ReadRecord(NVRAM_EF_CACHE_BYTE_LID, 1, back_buf, NVRAM_CACHE_SIZE, &error);
    bytebuf[0] = 34;
    temp_int = WriteValue(NVRAM_SMS_MISCELL_SETTING,  bytebuf, DS_BYTE, &error);
    MMI_ASSERT((temp_int == 1)&& (error == NVRAM_WRITE_SUCCESS));
    ReadRecord(NVRAM_EF_CACHE_BYTE_LID, 1, temp_buf, NVRAM_CACHE_SIZE, &error);
    MMI_ASSERT(memcmp(temp_buf, cache_buf[MMI_FW_NVRAM_BYTE], NVRAM_CACHE_SIZE) == 0);
    WriteRecord(NVRAM_EF_CACHE_BYTE_LID, 1, back_buf, NVRAM_CACHE_SIZE, &error);     
    
    ReadRecord(NVRAM_EF_CACHE_SHORT_LID, 1, back_buf, NVRAM_CACHE_SIZE, &error);
    shortbuf[0] = 45;
    shortbuf[1] = 54;
//    temp_int = WriteValue(NVRAM_WAP_PROF_ACTIVE_MMS_PROFILE_INDEX, shortbuf, DS_SHORT, &error);
 //   MMI_ASSERT((temp_int == 2)&& (error == NVRAM_WRITE_SUCCESS));
 //   ReadRecord(NVRAM_EF_CACHE_SHORT_LID, 1, temp_buf, NVRAM_CACHE_SIZE, &error);
 //   MMI_ASSERT(memcmp(temp_buf, cache_buf[MMI_FW_NVRAM_SHORT], NVRAM_CACHE_SIZE) == 0);
 //   WriteRecord(NVRAM_EF_CACHE_SHORT_LID, 1, back_buf, NVRAM_CACHE_SIZE, &error);
    
    ReadRecord(NVRAM_EF_CACHE_DOUBLE_LID, 1, back_buf, NVRAM_CACHE_SIZE, &error);
    memset(doublebuf, 33, 8);
  //  temp_int = WriteValue(NVRAM_CCONV_EXCHANGE_RATE9, doublebuf, DS_DOUBLE, &error);
  //  MMI_ASSERT((temp_int == 8) && (error == NVRAM_WRITE_SUCCESS));
   // ReadRecord(NVRAM_EF_CACHE_DOUBLE_LID, 1, temp_buf, NVRAM_CACHE_SIZE, &error);
   // MMI_ASSERT(memcmp(temp_buf, cache_buf[MMI_FW_NVRAM_DOUBLE], NVRAM_CACHE_SIZE) == 0);
    WriteRecord(NVRAM_EF_CACHE_DOUBLE_LID, 1, back_buf, NVRAM_CACHE_SIZE, &error); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nvram_ut_WriteRecord
 * DESCRIPTION
 *  Unit test of function WriteRecord
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_nvram_ut_WriteRecord(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 temp_int;
    U8 back_buf[NVRAM_CACHE_SIZE];
    U8 temp_buf[NVRAM_CACHE_SIZE];
    U8 temp_buf_r[NVRAM_CACHE_SIZE];
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_CACHE_DOUBLE_LID, 1, back_buf, NVRAM_CACHE_SIZE, &error);
    memset(temp_buf, 58, NVRAM_CACHE_SIZE);
    temp_int = WriteRecord(NVRAM_EF_CACHE_DOUBLE_LID, 1, temp_buf, NVRAM_CACHE_SIZE, &error);
    MMI_ASSERT((temp_int == NVRAM_CACHE_SIZE)&& (error == NVRAM_WRITE_SUCCESS));
    ReadRecord(NVRAM_EF_CACHE_DOUBLE_LID, 1, temp_buf_r, NVRAM_CACHE_SIZE, &error);
    MMI_ASSERT(memcmp(temp_buf, temp_buf_r, NVRAM_CACHE_SIZE) == 0);
    WriteRecord(NVRAM_EF_CACHE_DOUBLE_LID, 1, back_buf, NVRAM_CACHE_SIZE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nvram_ut_ReadRecord
 * DESCRIPTION
 *  Unit test of function ReadRecord
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_nvram_ut_ReadRecord(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 temp_int;
    U8 temp_buf[NVRAM_CACHE_SIZE];
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_int = ReadRecord(NVRAM_EF_CACHE_DOUBLE_LID, 1, temp_buf, NVRAM_CACHE_SIZE, &error);
    MMI_ASSERT((temp_int == NVRAM_CACHE_SIZE) && (error == NVRAM_READ_SUCCESS)); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nvram_ut_ReadMultiRecord
 * DESCRIPTION
 *  Unit test of function ReadMultiRecord
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_nvram_ut_ReadMultiRecord(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 temp_int;
    U8 temp_buf[NVRAM_EF_PHB_SIZE * 2];
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_int = ReadMultiRecord(NVRAM_EF_PHB_LID, 1, temp_buf, NVRAM_EF_PHB_SIZE * 2, 2, &error);
    MMI_ASSERT((temp_int == NVRAM_EF_PHB_SIZE * 2)&& (error == NVRAM_READ_SUCCESS));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nvram_ut
 * DESCRIPTION
 *  unit test function of framework nvram called in mmi_task while loop begin
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_nvram_ut(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     kal_printf("Framework NVRAM Unit Test start!");
    for (i = 0; i < MMI_FRM_NVRAM_UT_SIZE; i++)
        (*g_mmi_frm_nvram_ut_table[i])();
    
    kal_printf("Framework NVRAM Unit Test Done!");
}



#endif /* MMI_FRM_NVRAM_UT */


