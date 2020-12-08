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
 *  SmsUtilSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service Utility
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MOD_SMSAL__
/**************************************************************
* Header Files Include
**************************************************************/
#include "MMIDataType.h"
#include "GlobalConstants.h"
#include "app_ltlcom.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "Unicodexdcl.h"
#include "mmi_frm_mem_gprot.h"
#include "string.h"
#include "custom_mmi_default_value.h"
#include "MMI_common_app_trc.h"
#include "mmi_frm_queue_gprot.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "stack_config.h"
#include "mmi_frm_nvram_gprot.h"
#include "app_datetime.h"
#include "DateTimeType.h"
#include "mmi_cb_mgr_gprot.h"
#include "kal_trace.h"

#include "ps_public_struct.h"
#include "l4c2abm_struct.h"
#include "ps_public_enum.h"
#include "mmi_msg_context.h"
#include "sim_common_enums.h"
#include "smu_common_enums.h"
#include "Csmcc_enums.h"
#include "nvram_common_defs.h"
#include "ProtocolEvents.h"
#include "SmsSrvGProt.h"
#include "SmsProtSrv.h"
#include "SmsUtilSrv.h"
#include "SmsSettingSrv.h"
#include "SmsEmsSrv.h"
#include "SmsStorageSrv.h"
#include "SmsStorageCoreSrv.h"
#include "ems.h"
#include "gui_data_types.h"
#include "Gsm7BitNationalLang.h"

#include "ps_public_enum.h"

#include "common_nvram_editor_data_item.h"

#if defined(__MMI_WLAN_FEATURES__)
#include "NetworkSetupDefs.h"
#endif
#include "SimCtrlSrvGProt.h"
#include "App_usedetails.h"
#include "ModeSwitchSrvGprot.h"
#ifdef __SRV_SMS_MULTI_SIM__
#include "NwUsabSrvGprot.h"
#endif
#ifdef __MMI_WLAN_FEATURES__
#include "NetSetSrvGprot.h"
#endif /* __MMI_WLAN_FEATURES__ */

#ifdef __SMS_R8_NATION_LANGUAGE__
#include "SSCStringHandle.h"
#include "Lang_interface.h"
#endif
#include "PhbSrvGprot.h"
#ifdef __DM_LAWMO_SUPPORT__
#include "dmuigprot.h"
#include "TimerEvents.h"
#include "SmsGuiInterfaceType.h"
#include "MessagesMiscell.h"

#endif /* __DM_LAWMO_SUPPORT__ */

/**************************************************************
* MARCO
**************************************************************/
#define SRV_SMS_MAX_INT_EVENT_NUM       15

#define SRV_SMS_MAX_HANDLE              20

#define SRV_SMS_SPDU_BLOCK_NUM          (2 * SRV_SMS_MAX_SEG)
#define SRV_SMS_BLOCK_OFFSET            (((sms_spdu_block_struct*)0)->buffer)
#define MAX_CTRL_BUFF_SPDU_BLOCK_NUM    20

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__

#define SRV_SMS_TCARD_SPDU_BLOCK_NUM          (2 * SRV_SMS_MAX_SEG)
#define SRV_SMS_TCARD_BLOCK_OFFSET            (((sms_tcard_spdu_block_struct*)0)->buffer)
#define MAX_CTRL_BUFF_TCARD_SPDU_BLOCK_NUM    20

#endif

#define ONE_DIGIT(value)                  ((value) % 10)


#ifdef __SRV_SMS_RECENT_EVENT__
#define SRV_SMS_RECENT_EVENT_BITMAP_SISE    NVRAM_EF_SRV_SMS_RECENT_EVENT_BITMAP_SIZE
#endif /* __SRV_SMS_RECENT_EVENT__ */ 

/**************************************************************
* Structure Declaration
**************************************************************/
typedef struct
{
    LOCAL_PARA_HDR
    SrvSmsCallbackFunc callback_func;
    srv_sms_callback_struct callback_data;
} srv_sms_callback_ind_struct;

typedef struct
{
    U16 event_id;
    SrvSmsEventFunc int_event_func;
    void *user_data;
} srv_sms_int_event_struct;

typedef struct
{
    U16 sms_num[SRV_SMS_COUNT_TOTAL];
}srv_sms_counter_struct;

typedef struct spdu_block_struct
{
    MMI_BOOL is_ctrl_buff;
    struct spdu_block_struct *next;
    U8 buffer[SRV_SMS_MAX_SPDU_SIZE];
} sms_spdu_block_struct;

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
typedef struct tcard_spdu_block_struct
{
    MMI_BOOL is_ctrl_buff;
    struct tcard_spdu_block_struct *next;
    U8 buffer[SRV_SMS_MAX_TCARD_SPDU_SIZE];
} sms_tcard_spdu_block_struct;
#endif

typedef struct
{
    void *cntx;
} sms_handle_node_struct;


/**************************************************************
* Global Variables Declaration
**************************************************************/ 
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
srv_sms_tcard_action_cntx_struct action_cntx;
#endif

/**************************************************************
* Extern Function Declaration
**************************************************************/
#ifdef __SMS_R8_NATION_LANGUAGE__
extern sLanguageDetails *gLanguageArray;
extern U16 gCurrLangIndex;
#endif /* __SMS_R8_NATION_LANGUAGE__ */
extern EMSTATUS EMSCalculateSegEx(kal_uint8   dcs,
                                  EMSNationalLanguage *lang,
                                  kal_uint16  num_byte,
                                  kal_uint8   *usedSegment);
extern EMSTATUS EMSCalculateLastSegRemainingChar(kal_uint8   dcs,
                                                 EMSNationalLanguage *lang,
                                                 kal_uint16  num_byte,
                                                 kal_uint8   *last_seg_remaining);
extern kal_uint16 EMSUsableTextLenEx(kal_uint8 dcs, EMSNationalLanguage *lang);


/**************************************************************
* Static Variables Defination
**************************************************************/
static srv_sms_int_event_struct srv_sms_int_event_list[SRV_SMS_MAX_INT_EVENT_NUM];
static U8 curr_int_event_num; 

#ifdef __SRV_SMS_RECENT_EVENT__
static U8 srv_sms_recent_event_bitmap[SRV_SMS_RECENT_EVENT_BITMAP_SISE];
#endif /* __SRV_SMS_RECENT_EVENT__ */ 

#if (MMI_MAX_SIM_NUM >= 2)
static srv_sms_counter_struct srv_sms_counter[MMI_SIM_TOTAL];
#else
static srv_sms_counter_struct srv_sms_counter[1];
#endif

static sms_handle_node_struct handle_node_list[SRV_SMS_MAX_HANDLE];

static sms_spdu_block_struct spdu_block_list[SRV_SMS_SPDU_BLOCK_NUM];
static sms_spdu_block_struct *free_block_head;
static sms_spdu_block_struct *used_block_head;
static U8 ctrl_buff_block_count;

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
static sms_tcard_spdu_block_struct tcard_spdu_block_list[SRV_SMS_SPDU_BLOCK_NUM];
static sms_tcard_spdu_block_struct *tcard_free_block_head;
static sms_tcard_spdu_block_struct *tcard_used_block_head;
static U8 tcard_ctrl_buff_block_count;

#endif
#ifdef __DM_LAWMO_SUPPORT__
srv_dm_lawmo_wipe_report_cb_func_type wipe_cb;
#endif

MMI_BOOL copy_move_list;
/**************************************************************
* Static Function Declaration
**************************************************************/
#ifdef __SRV_SMS_RECENT_EVENT__
static void srv_sms_write_pdu_recent_event_bitmap(void);
#endif /* __SRV_SMS_RECENT_EVENT__ */ 

static void srv_sms_write_sms_counter(srv_sms_sim_enum sim_id, srv_sms_count_type_enum sms_count_type, U16 count); 
static sms_handle_node_struct* srv_sms_get_unused_cntx_node(void);
static sms_handle_node_struct* srv_sms_find_cntx_node(void* cntx);

#ifdef __DM_LAWMO_SUPPORT__
static void srv_msg_lawmo_delete_sms_data_cbk(srv_sms_callback_struct* callback_data);
#endif


/**************************************************************
* Function Defination
**************************************************************/
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_msg_node
 * DESCRIPTION
 *  check if the number is valid
 * PARAMETERS
 *  ucs2_num         [IN]       number (UCS2 Format)
 * RETURNS
 *  return true if number is valid, else return false
 *****************************************************************************/
void srv_sms_set_msg_node(srv_sms_tcard_msg_node_struct *tcard_msg_node,srv_sms_msg_node_struct *msg_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_node->status = tcard_msg_node->status;
#ifdef __SRV_SMS_MSG_INFO_DCS__ 
	msg_node->dcs = tcard_msg_node->dcs;
#endif /* __SRV_SMS_MSG_INFO_DCS__ */

#ifdef __SRV_SMS_MSG_EXT_STATUS__ 
	msg_node->ext_status = tcard_msg_node->ext_status;

#endif /* __SRV_SMS_MSG_EXT_STATUS__ */

#ifdef __SRV_SMS_RESEND_COUNT__
    msg_node->resend_count = tcard_msg_node->resend_count;
#endif /* __SRV_SMS_RESEND_COUNT__ */

    /* <<-- msg node compare range start */
    msg_node->storage_type = tcard_msg_node->storage_type;
    msg_node->mti = tcard_msg_node->mti;
	msg_node->pid = tcard_msg_node->pid;

    /* Concatenated inforamtion */
    msg_node->total_seg = tcard_msg_node->total_seg;
    msg_node->start_seg = tcard_msg_node->start_seg;
    msg_node->ref_num = tcard_msg_node->ref_num;

#ifdef __SRV_SMS_MULTI_SIM__ 
	msg_node->sim_id = tcard_msg_node->sim_id;
#endif /* __SRV_SMS_MULTI_SIM__ */

#ifdef __SRV_SMS_MULTI_ADDR__
    /* Extension address number */
    msg_node->ext_addr_num = tcard_msg_node->ext_addr_num;
    /* Start Externsion Address ID */
    msg_node->start_addr_id = tcard_msg_node->start_addr_id;
#endif /* __SRV_SMS_MULTI_ADDR__ */

#ifdef __SRV_SMS_MSG_INFO_PORT__
    msg_node->port_num = tcard_msg_node->port_num;
#endif /* __SRV_SMS_MSG_INFO_PORT__ */
    /* msg node compare range End -->> */

    msg_node->start_pdu_id = tcard_msg_node->start_pdu_id ;
    memcpy(msg_node->number,tcard_msg_node->number,SRV_SMS_MAX_ADDR_LEN + 1);
#ifdef __SRV_SMS_MSG_INFO_CONTENT__
    memcpy(msg_node->content,tcard_msg_node->content,(SRV_SMS_MSG_INFO_CONTENT_LEN + 1)*2);
#endif /* __SRV_SMS_MSG_INFO_CONTENT__ */

    msg_node->timestamp = tcard_msg_node->timestamp;
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_tcard_msg_node
 * DESCRIPTION
 *  check if the number is valid
 * PARAMETERS
 *  ucs2_num         [IN]       number (UCS2 Format)
 * RETURNS
 *  return true if number is valid, else return false
 *****************************************************************************/
void srv_sms_set_tcard_msg_node(srv_sms_msg_node_struct *msg_node,srv_sms_tcard_msg_node_struct *tcard_msg_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tcard_msg_node->status = msg_node->status;
#ifdef __SRV_SMS_MSG_INFO_DCS__ 
	tcard_msg_node->dcs = msg_node->dcs;
#else
    tcard_msg_node->dcs = 0;
#endif /* __SRV_SMS_MSG_INFO_DCS__ */

#ifdef __SRV_SMS_MSG_EXT_STATUS__ 
	tcard_msg_node->ext_status = msg_node->ext_status;
#else
    tcard_msg_node->ext_status = 0;
#endif /* __SRV_SMS_MSG_EXT_STATUS__ */

#ifdef __SRV_SMS_RESEND_COUNT__
    tcard_msg_node->resend_count = msg_node->resend_count;
#else
    tcard_msg_node->resend_count = 0;
#endif /* __SRV_SMS_RESEND_COUNT__ */

    /* <<-- msg node compare range start */
    tcard_msg_node->storage_type = SRV_SMS_STORAGE_TCARD;
    tcard_msg_node->mti = msg_node->mti;
	tcard_msg_node->pid = msg_node->pid;

    /* Concatenated inforamtion */
    tcard_msg_node->total_seg = msg_node->total_seg;
    tcard_msg_node->start_seg = msg_node->start_seg;
    tcard_msg_node->ref_num = msg_node->ref_num;

#ifdef __SRV_SMS_MULTI_SIM__ 
	tcard_msg_node->sim_id = msg_node->sim_id;
#else
    tcard_msg_node->sim_id = 0;
#endif /* __SRV_SMS_MULTI_SIM__ */

#ifdef __SRV_SMS_MULTI_ADDR__
    /* Extension address number */
    tcard_msg_node->ext_addr_num = msg_node->ext_addr_num;
    /* Start Externsion Address ID */
    tcard_msg_node->start_addr_id = msg_node->start_addr_id;
#else
    tcard_msg_node->ext_addr_num = 0;
    /* Start Externsion Address ID */
    tcard_msg_node->start_addr_id = 0XFFFF;
#endif /* __SRV_SMS_MULTI_ADDR__ */

#ifdef __SRV_SMS_MSG_INFO_PORT__
    tcard_msg_node->port_num = msg_node->port_num;
#else
    tcard_msg_node->port_num = 0;
#endif /* __SRV_SMS_MSG_INFO_PORT__ */
    /* msg node compare range End -->> */

    tcard_msg_node->start_pdu_id = msg_node->start_pdu_id ;
    memcpy(tcard_msg_node->number,msg_node->number,SRV_SMS_MAX_ADDR_LEN + 1);
#ifdef __SRV_SMS_MSG_INFO_CONTENT__
    memcpy(tcard_msg_node->content,msg_node->content,SRV_SMS_TCARD_MSG_INFO_CONTENT_LEN*2 + 2);
#else
    memset(tcard_msg_node->content, 0,SRV_SMS_TCARD_MSG_INFO_CONTENT_LEN *2 + 2);
#endif /* __SRV_SMS_MSG_INFO_CONTENT__ */

    tcard_msg_node->timestamp = msg_node->timestamp;
}

#endif
/*****************************************************************************
 * FUNCTION
 *  srv_sms_check_ucs2_number
 * DESCRIPTION
 *  check if the number is valid
 * PARAMETERS
 *  ucs2_num         [IN]       number (UCS2 Format)
 * RETURNS
 *  return true if number is valid, else return false
 *****************************************************************************/
MMI_BOOL srv_sms_check_ucs2_number(char* ucs2_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *asc_num;
    U32 len = 0;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = mmi_ucs2strlen((const CHAR *)ucs2_num);
    asc_num = OslMalloc(len + 1);
    mmi_ucs2_to_asc((CHAR *)asc_num, (CHAR *)ucs2_num);
    result = srv_sms_check_dst_number((U8 *)asc_num, (U8)len);
    OslMfree(asc_num);
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_msg_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_read_msg_deinit(srv_sms_read_cntx_struct *read_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_MSG_DEINIT);
    for (i = 0; i < SRV_SMS_MAX_SEG; i++)
    {
        if (read_cntx->spdu_list[i] != NULL)
        {
            srv_sms_free_pdu_block(read_cntx->spdu_list[i]);
        }
    #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
        if(read_cntx->msg_id >= SRV_SMS_MAX_MSG_NUM)
        {
            if (read_cntx->tcard_spdu_list[i] != NULL)
            {
                srv_sms_free_tcard_pdu_block(read_cntx->tcard_spdu_list[i]);
            }
        }
        
    #endif
    }
}




/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_msg_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_read_msg_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_read_cntx_struct *read_cntx;
    srv_sms_cause_enum error_cause;

    MMI_BOOL result = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    read_cntx = (srv_sms_read_cntx_struct*)callback_data->user_data;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_MSG_CALLBACK, callback_data->result, read_cntx->curr_index);

    if (CNTX_IS_ABORT(read_cntx))
    {
        result = MMI_FALSE;
        error_cause = SRV_SMS_CAUSE_ABORT;
    }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif/*skyfyx*/
    if (result)
    {
        U16 pdu_id = SRV_SMS_INVALID_PDU_ID;
#if 0
/* under construction !*/
/* under construction !*/
#endif/*skyfyx*/


        /* Skip the invalid PDU, for the incompleted case */
        while (read_cntx->curr_index < read_cntx->total_pdu)
        {
            pdu_id = read_cntx->pdu_id_list[read_cntx->curr_index];

            if (pdu_id != SRV_SMS_INVALID_PDU_ID)
            {
                break;
            }

            read_cntx->curr_index++;
        }

        /* Check whether all of the PDU is read */
        if (read_cntx->curr_index < read_cntx->total_pdu)
        {
            /* Read Next SPDU Data */
            srv_sms_read_pdu(
                pdu_id,
                srv_sms_read_msg_callback,
                read_cntx);
        }
        else
        {
            if (read_cntx->change_status)
            {
                srv_sms_clear_set_pdu_array_flag(
                    read_cntx->pdu_id_list,
                    read_cntx->total_pdu,
                    SRV_SMS_NODE_READING,
                    MMI_TRUE);

                srv_sms_clear_set_pdu_array_flag(
                    read_cntx->pdu_id_list,
                    read_cntx->total_pdu,
                    SRV_SMS_NODE_UPDATING,
                    MMI_FALSE);

                /* Reset the count for Update Msg Status */
                read_cntx->curr_index = 0;

                srv_sms_read_msg_change_status(read_cntx);
            }
            else
            {
                srv_sms_clear_set_pdu_array_flag(
                    read_cntx->pdu_id_list,
                    read_cntx->total_pdu,
                    SRV_SMS_NODE_READING,
                    MMI_TRUE);

                srv_sms_read_msg_succ_hdlr(read_cntx);
            }
        }
    }
    else
    {
        srv_sms_clear_set_pdu_array_flag(
            read_cntx->pdu_id_list,
            read_cntx->total_pdu,
            SRV_SMS_NODE_READING,
            MMI_TRUE);

        srv_sms_read_msg_error_hdlr(read_cntx, error_cause);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_msg_succ_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_read_msg_succ_hdlr(srv_sms_read_cntx_struct* read_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    srv_sms_cause_enum error_cause;
    srv_sms_read_msg_cb_struct read_msg_cb_data;
    U16 msg_id = read_cntx->msg_id;
    MMI_BOOL is_update_succ = read_cntx->change_status;
    MMI_BOOL int_result = MMI_FALSE;
    srv_sms_event_update_struct *event_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_MSG_SUCC_HDLR);

    /* Convert the Read SPDU Data to the Message Data which the caller concerned */
    result = srv_sms_convert_spdu_to_msg_data(
                read_cntx->msg_data,
                read_cntx->spdu_list,
                read_cntx->total_pdu);

    read_cntx->msg_data->status = srv_sms_get_msg_status(msg_id);
    read_cntx->msg_data->folder_id = SRV_SMS_FOLDER_DEFAULT;

    read_msg_cb_data.msg_data = read_cntx->msg_data;    

    if (result)
    {
        error_cause = SRV_SMS_CAUSE_NO_ERROR;

        if (is_update_succ == MMI_TRUE)
        {
            srv_sms_msg_node_struct *msg_node;
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            srv_sms_tcard_msg_node_struct *tcard_msg_node;
        #endif
            event_data = OslMalloc(sizeof(srv_sms_event_update_struct));

            /* Get Old Msg Info */
            srv_sms_get_msg_info(&event_data->old_msg_info, msg_id);
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            if(msg_id < SRV_SMS_MAX_SMS_ENTRY)
            {
                msg_node = srv_sms_get_msg_node(msg_id);
                /* Change Msg Status to READ */
                msg_node->status = (msg_node->status & SRV_SMS_STATUS_UNSUPPORTED) | SRV_SMS_STATUS_READ;
            }
            else
            {
                srv_tcard_op_struct write_cntx;
                
                msg_id -= SRV_SMS_MAX_MSG_NUM;
                tcard_msg_node = srv_sms_get_tcard_msg_node(msg_id);
                /* Change Msg Status to READ */
                tcard_msg_node->status = (tcard_msg_node->status & SRV_SMS_STATUS_UNSUPPORTED) | SRV_SMS_STATUS_READ;
                msg_id += SRV_SMS_MAX_MSG_NUM;

                write_cntx.app_index = SRV_TCARD_APP_INDEX_SMS;
                write_cntx.file_index = SRV_TCARD_FILE_INDEX_SMS_INFO;
                write_cntx.start_record_id = msg_id - SRV_SMS_MAX_MSG_NUM;
                srv_tcard_sync_write_record(&write_cntx, (char*)tcard_msg_node);
            }

        #else
            msg_node = srv_sms_get_msg_node(msg_id);
            /* Change Msg Status to READ */
            msg_node->status = (msg_node->status & SRV_SMS_STATUS_UNSUPPORTED) | SRV_SMS_STATUS_READ;
        #endif
            

            event_data->msg_id = msg_id;
            event_data->change_para_flag = SRV_SMS_PARA_STATUS;
            srv_sms_get_msg_info(&event_data->new_msg_info, msg_id);

           /* Execute Message Delete Interrupt Event */
            int_result = srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_UPDATE_MSG, event_data);
        }
    }
    else
    {
        is_update_succ = MMI_FALSE;
        error_cause = SRV_SMS_CAUSE_DATA_INVALID;
    }

    /* Free Buffer Before Exec Callback Function, for avoiding to cause nesting */
    srv_sms_read_msg_deinit(read_cntx);

    /* Exec Caller's Callback Function with TRUE result */
    STORAGE_INVOKE_CALLBACK(
        read_cntx,
        result,
        error_cause,
        &read_msg_cb_data);

    if ((is_update_succ == MMI_TRUE) && (int_result == MMI_FALSE))
    {
        srv_sms_emit_event(EVT_ID_SRV_SMS_UPDATE_MSG, event_data);
    }

    if (event_data != NULL)
    {
        OslMfree(event_data);
    }
}



/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_msg_error_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_read_msg_error_hdlr(
                srv_sms_read_cntx_struct* read_cntx,
                srv_sms_cause_enum error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_read_msg_cb_struct read_msg_cb_data;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_MSG_ERROR_HDLR);

    read_msg_cb_data.msg_data = read_cntx->msg_data;    
#if 0
/* under construction !*/
#endif/*skyfyx*/
    if (CNTX_IS_ABORT(read_cntx))
    {
        result = MMI_TRUE;
    }
	
    srv_sms_read_msg_deinit(read_cntx);


    STORAGE_INVOKE_CALLBACK(
        read_cntx,
        result,
        error_cause,
        &read_msg_cb_data);
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_msg_change_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_read_msg_change_status(srv_sms_read_cntx_struct* read_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 pdu_id = SRV_SMS_INVALID_PDU_ID;
    srv_sms_spdu_struct *spdu_data = NULL;
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    srv_sms_tcard_spdu_struct *tcard_spdu_data = NULL;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_MSG_CHANGE_STATUS, read_cntx->curr_index);

    while (read_cntx->curr_index < read_cntx->total_pdu)
    {
        pdu_id = read_cntx->pdu_id_list[read_cntx->curr_index];

        if (pdu_id != SRV_SMS_INVALID_PDU_ID)
        {
            spdu_data = read_cntx->spdu_list[read_cntx->curr_index];
    #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            if(pdu_id >= SRV_SMS_MAX_MSG_NUM)
            {
                tcard_spdu_data = srv_sms_alloc_tcard_pdu_block();
            }            
    #endif
            /* If a Concatenated SMS cantains one or more UNREAD status segment,
             * it will consider as UNREAD, it also means the status of some segment 
             * may be not UNREAD. */
            if (spdu_data->status == SRV_SMS_STATUS_UNREAD)
            {
                break;
            }
        }

        read_cntx->curr_index++;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_MSG_CHANGE_STATUS_1, read_cntx->curr_index);

    if (read_cntx->curr_index < read_cntx->total_pdu)
    {
        srv_sms_update_pdu_struct update_data;

        spdu_data->status = SRV_SMS_STATUS_READ;
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
        if(pdu_id >= SRV_SMS_MAX_MSG_NUM)
        {
            srv_tcard_op_struct temp_read_cntx;
            
            temp_read_cntx.app_index = SRV_TCARD_APP_INDEX_SMS;
            temp_read_cntx.file_index = SRV_TCARD_FILE_INDEX_SMS_PDU;
            temp_read_cntx.record_num = 1;
            temp_read_cntx.start_record_id = pdu_id - SRV_SMS_MAX_MSG_NUM;
            srv_tcard_sync_read_record(&temp_read_cntx,(CHAR*)tcard_spdu_data);
            tcard_spdu_data->status = SRV_SMS_STATUS_READ;

            update_data.tcard_spdu_data = tcard_spdu_data;
        }
        
#endif
        update_data.spdu_data = spdu_data;

        update_data.update_flag = SRV_SMS_PARA_STATUS;

        srv_sms_update_pdu(
            pdu_id,
            &update_data,
            srv_sms_read_msg_update_callback,
            read_cntx);
    }
    else
    {
        srv_sms_clear_set_pdu_array_flag(
            read_cntx->pdu_id_list,
            read_cntx->total_pdu,
            SRV_SMS_NODE_UPDATING,
            MMI_TRUE);

        srv_sms_read_msg_succ_hdlr(read_cntx);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_msg_update_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_read_msg_update_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_read_cntx_struct *read_cntx;
    MMI_BOOL result;
    srv_sms_cause_enum error_cause;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_MSG_UPDATE_CALLBACK, callback_data->result);

    read_cntx = (srv_sms_read_cntx_struct*)callback_data->user_data;

    if (CNTX_IS_ABORT(read_cntx))
    {
        result = MMI_FALSE;
        error_cause = SRV_SMS_CAUSE_ABORT;
    }
    else
    {
        result = callback_data->result;
        error_cause = callback_data->cause;
    }

    read_cntx->curr_index++;

    if (result)
    {
        /* Change next segment's status */
        srv_sms_read_msg_change_status(read_cntx);
    }
    else
    {
        /* Clear UPDATING Flag */
        srv_sms_clear_set_pdu_array_flag(
            read_cntx->pdu_id_list,
            read_cntx->total_pdu,
            SRV_SMS_NODE_UPDATING,
            MMI_TRUE);

        srv_sms_read_msg_error_hdlr(read_cntx, error_cause);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_pdu_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_read_pdu_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_read_pdu_cntx_struct *read_pdu_cntx;
    srv_sms_read_pdu_cb_struct read_pdu_cb_data;
    srv_sms_spdu_struct *spdu_data;
//#ifdef __SRV_SMS_TCARD_SUPPORT__
//    srv_sms_tcard_spdu_struct *tmp_spdu_data;
//#endif
    MMI_BOOL result = callback_data->result;
    srv_sms_cause_enum cause = callback_data->cause;
    void *user_data;
    SrvSmsCallbackFunc callback_func;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_PDU_CALLBACK, callback_data->result, callback_data->cause);

    read_pdu_cntx = (srv_sms_read_pdu_cntx_struct*)callback_data->user_data;
    read_pdu_cntx->storage_type = read_pdu_cntx->storage_type;
    spdu_data = (srv_sms_spdu_struct*)callback_data->action_data;
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    if(read_pdu_cntx->storage_type == SRV_SMS_STORAGE_TCARD && (!storage_cntx.is_tsms_ready))
    {
        result = MMI_FALSE;   
    }
#endif
    if (result)
    {
        spdu_data->status = (U8)srv_sms_spdu_status_to_msg_status(
                                    spdu_data->status,
                                    read_pdu_cntx->storage_type);

    }
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    if(read_pdu_cntx->storage_type == SRV_SMS_STORAGE_TCARD)
    {
        read_pdu_cb_data.spdu_data = spdu_data;
        //read_pdu_cb_data.tcard_spdu_data = tmp_spdu_data;
    }
    else
    {
        read_pdu_cb_data.spdu_data = spdu_data;
        read_pdu_cb_data.tcard_spdu_data = NULL;
    }    
#else
    read_pdu_cb_data.spdu_data = spdu_data;
#endif /*__SRV_SMS_TCARD_STORAGE_SUPPORT__*/
    user_data = read_pdu_cntx->user_data;
    callback_func = read_pdu_cntx->callback_func;

    OslMfree(read_pdu_cntx);

    srv_sms_callback(
        SRV_SMS_ACTION_READ,
        result,
        cause,
        &read_pdu_cb_data,
        user_data,
        callback_func);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sms_check_sms_handle(SMS_HANDLE sms_handle, srv_sms_action_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_handle_struct *handle = (srv_sms_handle_struct*)sms_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle->action == action)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_alloc_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void* srv_sms_alloc_cntx(
        U32 size,
        srv_sms_action_enum action,
        SrvSmsCallbackFunc callback_func,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sms_handle_node_struct *cntx_node;
    srv_sms_handle_struct *cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ALLOC_CNTX, size, action, callback_func, user_data);

    MMI_ASSERT(size >= sizeof(srv_sms_handle_struct));

    cntx_node = srv_sms_get_unused_cntx_node();

    if (cntx_node != NULL)
    {
        cntx = (srv_sms_handle_struct*)OslMalloc(size);

        cntx->action = action;
        cntx->is_abort = MMI_FALSE;
        cntx->hd_data = NULL;
        cntx->abort_func = NULL;
        cntx->abort_user_data = NULL;
        cntx->callback_func = callback_func;
        cntx->user_data = user_data;
        cntx->sub_handle = NULL;
        cntx->sub_abort_func = NULL;
        cntx->sub_user_data = NULL;

        cntx_node->cntx = cntx;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ALLOC_CNTX_1, cntx);

    return cntx;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_free_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_free_cntx(void* cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sms_handle_node_struct *cntx_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_FREE_CNTX, cntx);

    cntx_node = srv_sms_find_cntx_node(cntx);

    if (cntx_node != NULL)
    {
        cntx_node->cntx = NULL;
        OslMfree(cntx);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_unused_cntx_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static sms_handle_node_struct* srv_sms_get_unused_cntx_node(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_sms_find_cntx_node(NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_find_cntx_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static sms_handle_node_struct* srv_sms_find_cntx_node(void* cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sms_handle_node_struct *node = NULL;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_SMS_MAX_HANDLE; i++)
    {
        if (handle_node_list[i].cntx == cntx)
        {
            node = &handle_node_list[i];
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_FIND_CNTX_NODE, node);

    return node;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_abort
 * DESCRIPTION
 *  1. Abort an action (Read/Send/Save, etc); 
 *     In current version, it is only can abort a read action.
 *  2. The abort is a async operation, and it may be failed. The result is returned
 *     in the callback function of the aborted action(ex. Read).
 *     If the result is FALSE, and the cause is SRV_SMS_CAUSE_ABORT. it means the
 *     abort is success. Otherwise, the abort is failed.
 *  3. The callback function of the aborted action (Read/Send/Save, etc) will be called even if abort it.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_abort(
        SMS_HANDLE handle,
        SrvSmsCallbackFunc callback_func,
        void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ABORT, handle, callback_func, user_data);

    if ((handle != SRV_SMS_INVALID_HANDLE) && 
        (handle != SRV_SMS_RESERVED_HANDLE))
    {
        sms_handle_node_struct *cntx_node;
        srv_sms_handle_struct *cntx = (srv_sms_handle_struct*)handle;

        cntx_node = srv_sms_find_cntx_node(cntx);

        if (cntx_node != NULL)
        {
            cntx->is_abort = MMI_TRUE;
            cntx->abort_func = callback_func;
            cntx->abort_user_data = user_data;
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
            if (cntx->sub_handle != SRV_SMS_INVALID_HANDLE)
            {
                srv_sms_abort(
                    cntx->sub_handle,
                    cntx->sub_abort_func,
                    cntx->sub_user_data);
            }
        }
    }
    else
    {
        srv_sms_async_callback(
            SRV_SMS_ACTION_NONE,
            MMI_TRUE,
            SRV_SMS_CAUSE_NO_ERROR,
            NULL,
            0,
            user_data,
            callback_func);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_user_data
 * DESCRIPTION
 *  Get a Handle's user data of an action
 * PARAMETERS
 *  handle      [IN]        SMS_HANDLE
 * RETURNS
 *  void*
 *****************************************************************************/
void* srv_sms_get_user_data(SMS_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *user_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((handle != SRV_SMS_INVALID_HANDLE) && 
        (handle != SRV_SMS_RESERVED_HANDLE))
    {
        srv_sms_handle_struct *cntx = (srv_sms_handle_struct*)handle;

        user_data = cntx->user_data;
    }

    return user_data;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_cntx_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_cntx_callback(
        void *cntx,
        MMI_BOOL result,
        srv_sms_cause_enum cause,
        void *action_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_handle_struct *sms_cntx = (srv_sms_handle_struct*)cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CNTX_CALLBACK, cntx, result, cause);

    if (sms_cntx)
    {
        SrvSmsCallbackFunc callback_func;
        srv_sms_action_enum action = sms_cntx->action;
        void *user_data;

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CNTX_CALLBACK_1, sms_cntx->is_abort);

        if (sms_cntx->is_abort)
        {
            callback_func = sms_cntx->abort_func;
            user_data = sms_cntx->abort_user_data;
        }
        else
        {
            callback_func = sms_cntx->callback_func;
            user_data = sms_cntx->user_data;
        }

        srv_sms_free_cntx(sms_cntx);

        if (callback_func)
        {
            srv_sms_callback_struct cb_data;

            cb_data.result = result;
            cb_data.cause = cause;
            cb_data.action_data = action_data;
            cb_data.action = action;
            cb_data.user_data = user_data;

            callback_func(&cb_data);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_int_msg_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
srv_sms_int_msg_data_struct* srv_sms_get_int_msg_data(SMS_HANDLE sms_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*)sms_handle;
    srv_sms_int_msg_data_struct *int_msg_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sms_hd->action)
    {
        case SRV_SMS_ACTION_SEND:
        {
            srv_sms_send_handle_struct *send_hd = (srv_sms_send_handle_struct*)sms_hd->hd_data;

            int_msg_data = &send_hd->msg_data;
            break;
        }

        case SRV_SMS_ACTION_UPDATE:
        case SRV_SMS_ACTION_SAVE:
        {
            int_msg_data = (srv_sms_int_msg_data_struct*)CNTX_GET_HD_DATA(sms_hd);
            break;
        }

        default:
            break;
    }

    return int_msg_data;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_alloc_int_msg_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
srv_sms_int_msg_data_struct* srv_sms_alloc_int_msg_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_int_msg_data_struct *msg_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_data = OslMalloc(sizeof(srv_sms_int_msg_data_struct));

    memset(msg_data, 0, sizeof(srv_sms_int_msg_data_struct));

    msg_data->sim_id = SRV_SMS_SIM_1;
    msg_data->status = SRV_SMS_STATUS_DRAFT;
    msg_data->storage_type = SRV_SMS_STORAGE_UNSPECIFIC;
    msg_data->is_allow_num_emtpy = MMI_TRUE;
    msg_data->is_allow_sc_emtpy = MMI_TRUE;

    return msg_data;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_free_int_msg_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_free_int_msg_data(srv_sms_int_msg_data_struct *msg_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_MULTI_ADDR__
    srv_sms_addr_struct *curr_addr = msg_data->ext_addr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (curr_addr)
    {
        srv_sms_addr_struct *free_addr = curr_addr;

        curr_addr = curr_addr->next;

        OslMfree(free_addr);
    }
#endif /* __SRV_SMS_MULTI_ADDR__ */

    OslMfree(msg_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sms_handle       [IN]               
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_set_status(SMS_HANDLE sms_handle, srv_sms_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*)sms_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((sms_hd->action == SRV_SMS_ACTION_SAVE) ||
        (sms_hd->action == SRV_SMS_ACTION_UPDATE))
    {
        srv_sms_int_msg_data_struct *msg_data;

        msg_data = (srv_sms_int_msg_data_struct*)CNTX_GET_HD_DATA(sms_hd);

        msg_data->status = status;
        msg_data->para_flag |= SRV_SMS_PARA_STATUS;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sms_set_address(SMS_HANDLE sms_handle, char *ucs2_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_int_msg_data_struct *int_msg_data = NULL;
    S32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int_msg_data = srv_sms_get_int_msg_data(sms_handle);

    if (int_msg_data != NULL)
    {
        int_msg_data->para_flag |= SRV_SMS_PARA_NUM;

        mmi_ucs2ncpy(int_msg_data->number, ucs2_addr, SRV_SMS_MAX_ADDR_LEN);
    #ifdef __SRV_SMS_MULTI_ADDR__
        int_msg_data->addr_num++;
    #endif /* __SRV_SMS_MULTI_ADDR__ */
    }

    len = mmi_ucs2strlen(ucs2_addr);

    if ((len == 0) || (len > SRV_SMS_MAX_ADDR_LEN))
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_append_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_append_address(
        SMS_HANDLE sms_handle,
        WCHAR* ucs2_addr,
        srv_sms_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_MULTI_ADDR__
    srv_sms_int_msg_data_struct *int_msg_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int_msg_data = srv_sms_get_int_msg_data(sms_handle);

    if (int_msg_data != NULL)
    {
        int_msg_data->para_flag |= SRV_SMS_PARA_NUM;

        if (int_msg_data->addr_num > 0)
        {
            srv_sms_addr_struct *last_addr = int_msg_data->ext_addr;
            srv_sms_addr_struct *new_addr;

            new_addr = OslMalloc(sizeof(srv_sms_addr_struct));
            new_addr->next = NULL;
            new_addr->status = status;
            mmi_wcsncpy(new_addr->address, ucs2_addr, SRV_SMS_MAX_ADDR_LEN);

            if (last_addr)
            {
                while (last_addr->next)
                {
                    last_addr = last_addr->next;
                }

                last_addr->next = new_addr;
            }
            else
            {
                int_msg_data->ext_addr = new_addr;
            }
        }
        else
        {
            mmi_ucs2ncpy((CHAR*)int_msg_data->number, (CHAR*)ucs2_addr, SRV_SMS_MAX_ADDR_LEN);
            int_msg_data->status = status;
        }

        int_msg_data->addr_num++;
    }
#else /* __SRV_SMS_MULTI_ADDR__ */
    srv_sms_set_address(sms_handle, (S8*)ucs2_addr);
#endif /* __SRV_SMS_MULTI_ADDR__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_content
 * DESCRIPTION
 *  set content.
 *  The default content will consider as unicode text; 
 *  And its default DCS is GSM Default 7Bit.
 *  If you want the specify the DCS, you need to call API srv_sms_set_content_dcs()
 *  to set the DCS. 
 *  For the 8Bit DCS (SRV_SMS_DCS_8BIT), the content will consider as binary Data.
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_set_content(SMS_HANDLE sms_handle, char *content_buff, U16 content_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_int_msg_data_struct *int_msg_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int_msg_data = srv_sms_get_int_msg_data(sms_handle);

    if (int_msg_data != NULL)
    {
        int_msg_data->para_flag |= SRV_SMS_PARA_CONTENT_BUFF;
        int_msg_data->content_buff = content_buff;
        int_msg_data->content_buff_size = content_size;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_content_dcs
 * DESCRIPTION
 *  IF send content is UCS2 or 8BIT character, need set DCS. 7BIT character content no need set.
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_set_content_dcs(SMS_HANDLE sms_handle, srv_sms_dcs_enum dcs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_int_msg_data_struct *int_msg_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int_msg_data = srv_sms_get_int_msg_data(sms_handle);

    if (int_msg_data != NULL)
    {
        int_msg_data->para_flag |= SRV_SMS_PARA_DCS;
        int_msg_data->dcs = dcs;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_content_file
 * DESCRIPTION
 *  set content file path,file path dcs is UCS2, but file content default is 7BIT characters. 
 *  If content is UCS2 or 8BIT characters, must use srv_sms_set_content_dcs() set DCS, 
 *  otherwise no need set DCS.
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_set_content_file(SMS_HANDLE sms_handle, char *content_file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_int_msg_data_struct *int_msg_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int_msg_data = srv_sms_get_int_msg_data(sms_handle);

    if (int_msg_data != NULL)
    {
        int_msg_data->para_flag |= SRV_SMS_PARA_CONTENT_FILE;
        int_msg_data->content_file_path = content_file_path;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_content_ems
 * DESCRIPTION
 *  Only for SMS internal use to send SMS
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_set_content_ems(SMS_HANDLE sms_handle, void *content_ems)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_int_msg_data_struct *int_msg_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int_msg_data = srv_sms_get_int_msg_data(sms_handle);

    if (int_msg_data != NULL)
    {
        int_msg_data->para_flag |= SRV_SMS_PARA_CONTENT_EMS;
        int_msg_data->content_ems = (EMSData*)content_ems;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_data_port
 * DESCRIPTION
 *  Set port number
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_set_data_port(SMS_HANDLE sms_handle, U16 src_port, U16 dest_port)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_int_msg_data_struct *int_msg_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int_msg_data = srv_sms_get_int_msg_data(sms_handle);

    if (int_msg_data != NULL)
    {
        int_msg_data->src_port = src_port;
        int_msg_data->dest_port = dest_port;
        int_msg_data->para_flag |= SRV_SMS_PARA_PORT;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_sim_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_set_sim_id(SMS_HANDLE sms_handle, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*)sms_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sms_hd->action)
    {
        case SRV_SMS_ACTION_SEND:
        {
            srv_sms_send_handle_struct *send_hd = (srv_sms_send_handle_struct*)sms_hd->hd_data;

            send_hd->sim_id = sim_id;
            break;
        }

        case SRV_SMS_ACTION_SAVE:
        case SRV_SMS_ACTION_UPDATE:
        {
            srv_sms_int_msg_data_struct *msg_data;

            msg_data = (srv_sms_int_msg_data_struct*)CNTX_GET_HD_DATA(sms_hd);
            msg_data->sim_id = sim_id;
            break;
        }

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_status_report
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_set_status_report(SMS_HANDLE sms_handle, MMI_BOOL is_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_int_msg_data_struct *int_msg_data = NULL;
    srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*)sms_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int_msg_data = srv_sms_get_int_msg_data(sms_handle);

    if (sms_hd->action == SRV_SMS_ACTION_SEND)
    {
        srv_sms_send_handle_struct *send_hd = (srv_sms_send_handle_struct*)sms_hd->hd_data;
        send_hd->spec_para |= SRV_SMS_SPEC_SEND_STATUS_REPORT;
    }

    if (int_msg_data != NULL)
    {
        int_msg_data->para_flag |= SRV_SMS_PARA_STATUS_REPORT;
        int_msg_data->status_report = is_set;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_sc_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sms_set_sc_address(SMS_HANDLE sms_handle, char* sc_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_int_msg_data_struct *int_msg_data = NULL;
    srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*)sms_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int_msg_data = srv_sms_get_int_msg_data(sms_handle);

    if (sms_hd->action == SRV_SMS_ACTION_SEND)
    {
        srv_sms_send_handle_struct *send_hd = (srv_sms_send_handle_struct*)sms_hd->hd_data;
        send_hd->spec_para |= SRV_SMS_SPEC_SEND_SCA;
    }

    if (int_msg_data != NULL)
    {
        int_msg_data->para_flag |= SRV_SMS_PARA_SCA;

        mmi_ucs2ncpy(int_msg_data->sc_address, sc_addr, SRV_SMS_MAX_ADDR_LEN);
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_pid
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_set_pid(SMS_HANDLE sms_handle, srv_sms_pid_enum pid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_int_msg_data_struct *int_msg_data = NULL;
    srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*)sms_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int_msg_data = srv_sms_get_int_msg_data(sms_handle);

    if (sms_hd->action == SRV_SMS_ACTION_SEND)
    {
        srv_sms_send_handle_struct *send_hd = (srv_sms_send_handle_struct*)sms_hd->hd_data;
        send_hd->spec_para |= SRV_SMS_SPEC_SEND_PID;
    }

    if (int_msg_data != NULL)
    {
        int_msg_data->para_flag |= SRV_SMS_PARA_PID;
        int_msg_data->pid = pid;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_vp
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_set_vp(SMS_HANDLE sms_handle, srv_sms_vp_enum vp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_int_msg_data_struct *int_msg_data = NULL;
    srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*)sms_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int_msg_data = srv_sms_get_int_msg_data(sms_handle);

    if (sms_hd->action == SRV_SMS_ACTION_SEND)
    {
        srv_sms_send_handle_struct *send_hd = (srv_sms_send_handle_struct*)sms_hd->hd_data;
        send_hd->spec_para |= SRV_SMS_SPEC_SEND_VP;
    }

    if (int_msg_data != NULL)
    {
        int_msg_data->para_flag |= SRV_SMS_PARA_VP;
        int_msg_data->vp = vp;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_class_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_set_class_type(SMS_HANDLE sms_handle, srv_sms_class_enum class_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_int_msg_data_struct *int_msg_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int_msg_data = srv_sms_get_int_msg_data(sms_handle);

    if (int_msg_data != NULL)
    {
        int_msg_data->para_flag |= SRV_SMS_PARA_CLASS;
        int_msg_data->class = class_type;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_mms
 * DESCRIPTION
 *  Set more message to send para
 * PARAMETERS
 *  is_set          [IN]        
 *  sms_handle     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_set_mms(SMS_HANDLE sms_handle, MMI_BOOL is_mms)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*)sms_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sms_hd->action == SRV_SMS_ACTION_SEND)
    {
        srv_sms_send_handle_struct *send_hd = (srv_sms_send_handle_struct*)sms_hd->hd_data;
        send_hd->is_mms = is_mms;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_reply_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_set          [IN]        
 *  sms_handle     [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_set_reply_path(SMS_HANDLE sms_handle, MMI_BOOL is_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_int_msg_data_struct *int_msg_data = NULL;
    srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*)sms_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int_msg_data = srv_sms_get_int_msg_data(sms_handle);

    if (sms_hd->action == SRV_SMS_ACTION_SEND)
    {
        srv_sms_send_handle_struct *send_hd = (srv_sms_send_handle_struct*)sms_hd->hd_data;
        send_hd->spec_para |= SRV_SMS_SPEC_SEND_REPLY_PATH;
    }

    if (int_msg_data != NULL)
    {
        int_msg_data->para_flag |= SRV_SMS_PARA_REPLY_PATH;
        int_msg_data->status_report = is_set;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_reply_msg_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_set_reply_msg_id(SMS_HANDLE sms_handle, U16 reply_msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*)sms_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sms_hd->action == SRV_SMS_ACTION_SEND)
    {
        srv_sms_send_handle_struct *send_hd = (srv_sms_send_handle_struct*)sms_hd->hd_data;
        send_hd->reply_msg_id = reply_msg_id;
    }
}


/*****************************************************************************
 * FUNCTION
 * srv_sms_set_send_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_set_send_type(SMS_HANDLE sms_handle, srv_sms_send_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*)sms_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sms_hd->action == SRV_SMS_ACTION_SEND)
    {
        srv_sms_send_handle_struct *send_hd = (srv_sms_send_handle_struct*)sms_hd->hd_data;
        send_hd->send_type = type;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_save_timestamp
 * DESCRIPTION
 *  Only for Save message
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_set_save_timestamp(SMS_HANDLE sms_handle, MYTIME* timestamp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_int_msg_data_struct *int_msg_data = srv_sms_get_int_msg_data(sms_handle);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (int_msg_data != NULL)
    {
        memcpy(&(int_msg_data->timestamp), timestamp, sizeof(MYTIME));
        
        int_msg_data->para_flag |= SRV_SMS_PARA_TIMESTAMP;
    }
}


/*****************************************************************************
 * FUNCTION
 * srv_sms_set_msg_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_set_msg_data(SMS_HANDLE sms_handle, srv_sms_int_msg_data_struct *msg_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_int_msg_data_struct *int_msg_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    int_msg_data = srv_sms_get_int_msg_data(sms_handle);

    if (int_msg_data != NULL)
    {
        memcpy(int_msg_data, msg_data, sizeof(srv_sms_int_msg_data_struct));
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_storage_type
 * DESCRIPTION
 *  Set Storage Type, only for Save or Update Message
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_set_storage_type(SMS_HANDLE sms_handle, srv_sms_storage_enum storage_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_handle_struct *sms_hd = (srv_sms_handle_struct*)sms_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sms_hd->action)
    {
        case SRV_SMS_ACTION_SAVE:
        {
            srv_sms_int_msg_data_struct *msg_data;

            msg_data = (srv_sms_int_msg_data_struct*)CNTX_GET_HD_DATA(sms_hd);
            msg_data->storage_type = storage_type;
            break;
        }

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_msg_ref
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_set_msg_ref(SMS_HANDLE sms_handle, U8 msg_ref[], U8 total)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_int_msg_data_struct *msg_data;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_data = srv_sms_get_int_msg_data(sms_handle);

    if (msg_data)
    {
        for (i = 0; i < total; i++)
        {
            msg_data->msg_ref[i] = msg_ref[i];
        }

        msg_data->total_seg = total;
        msg_data->para_flag |= SRV_SMS_PARA_MSG_REF;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_delivery_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_set_delivery_status(SMS_HANDLE sms_handle, U16 report_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_int_msg_data_struct *msg_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_data = srv_sms_get_int_msg_data(sms_handle);

    if (msg_data)
    {
        msg_data->report_id = report_id;
        msg_data->para_flag |= SRV_SMS_PARA_DELIVERY_STATUS;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_msg_data_num_empty
 * DESCRIPTION
 *
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_set_number_empty_flag(MMI_BOOL is_allow_emtpy, srv_sms_int_msg_data_struct *int_msg_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (int_msg_data != NULL)
    {
        int_msg_data->is_allow_num_emtpy = is_allow_emtpy;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_sc_addr_empty_flag
 * DESCRIPTION
 *
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_set_sc_addr_empty_flag(MMI_BOOL is_allow_emtpy, srv_sms_int_msg_data_struct *int_msg_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (int_msg_data != NULL)
    {
        int_msg_data->is_allow_sc_emtpy = is_allow_emtpy;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_content_asc
 * DESCRIPTION
 *
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_set_content_asc(MMI_BOOL is_asc_content, srv_sms_int_msg_data_struct *int_msg_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (int_msg_data != NULL)
    {
        int_msg_data->is_asc_content = is_asc_content;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_callback(
        srv_sms_action_enum action,
        MMI_BOOL result,
        srv_sms_cause_enum cause,
        void *action_data,
        void *user_data,
        SrvSmsCallbackFunc callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CALLBACK, action, result, cause, callback_func);

    if (callback_func != NULL)
    {
        srv_sms_callback_struct callback_data;

        callback_data.result = result;
        callback_data.cause = cause;
        callback_data.action = action;
        callback_data.action_data = action_data;
        callback_data.user_data = user_data;

        callback_func(&callback_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_succ_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_succ_callback(
        srv_sms_action_enum action,
        void *action_data,
        void *user_data,
        SrvSmsCallbackFunc callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_callback_struct callback_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SUCC_CALLBACK, action, callback_func);

    callback_data.result = MMI_TRUE;
    callback_data.cause = SRV_SMS_CAUSE_NO_ERROR;
    callback_data.action = action;
    callback_data.action_data = action_data;
    callback_data.user_data = user_data;

    if (callback_func != NULL)
    {
        callback_func(&callback_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_error_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_error_callback(
        srv_sms_action_enum action,
        srv_sms_cause_enum cause,
        void *user_data,
        SrvSmsCallbackFunc callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_callback_struct callback_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ERROR_CALLBACK, action, cause, callback_func);

    callback_data.result = MMI_FALSE;
    callback_data.cause = cause;
    callback_data.action = action;
    callback_data.action_data = NULL;
    callback_data.user_data = user_data;

    if (callback_func != NULL)
    {
        callback_func(&callback_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_async_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_async_callback(
        srv_sms_action_enum action,
        MMI_BOOL result,
        srv_sms_cause_enum cause,
        void *action_data,
        U32 action_data_size,
        void *user_data,
        SrvSmsCallbackFunc callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ASYNC_CALLBACK, action_data_size, callback_func);

    if (callback_func != NULL)
    {
        void *temp_data = NULL;

        if ((action_data != NULL) & (action_data_size > 0))
        {
            temp_data = OslMalloc(action_data_size);
            memcpy(temp_data, action_data, action_data_size);
        }

        SRV_SMS_POST_CALLBACK(
            action,
            result,
            cause,
            temp_data,
            user_data,
            callback_func);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_async_callback_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret srv_sms_async_callback_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_evt_callback_struct *event_data = (srv_sms_evt_callback_struct*)param;
    srv_sms_callback_struct *callback_data = &event_data->callback_data;
    srv_sms_read_pdu_cntx_struct *read_pdu_cntx;
    SrvSmsCallbackFunc temp_callback_func = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ASYNC_CALLBACK_PROC);
    if(event_data->callback_func == srv_sms_read_pdu_callback)
    {
        read_pdu_cntx = (srv_sms_read_pdu_cntx_struct*)callback_data->user_data;
        temp_callback_func = read_pdu_cntx->callback_func;
    }
    event_data->callback_func(callback_data);

    if (callback_data->action_data != NULL)
    {
        if(event_data->callback_func == srv_sms_read_pdu_callback)
        {
            if(temp_callback_func != srv_sms_read_msg_callback)
            {
                if (event_data->free_func)
	            {
	                event_data->free_func(callback_data->action_data);
	            }
	            else
	            {
	                srv_sms_free_pdu_block(callback_data->action_data);
	            }
            }
        }
        else
        {
            if (event_data->free_func)
            {
                event_data->free_func(callback_data->action_data);
            }
            else
            {
                OslMfree(callback_data->action_data);
            }
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_interrupt_event_handler
 * DESCRIPTION
 *  Set Interrupt Event Handler of the Event
 * PARAMETERS
 *  event_id        [IN]        Event ID
 *  event_func      [IN]        Event Handler Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_set_interrupt_event_handler(
        U16 event_id,
        SrvSmsEventFunc event_func,
        void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SET_INTERRUPT_EVENT_HANDLER, event_id, event_func, curr_int_event_num);

    MMI_ASSERT(curr_int_event_num < SRV_SMS_MAX_INT_EVENT_NUM);

    srv_sms_int_event_list[curr_int_event_num].event_id = event_id;
    srv_sms_int_event_list[curr_int_event_num].int_event_func = event_func;
    srv_sms_int_event_list[curr_int_event_num].user_data = user_data;
    curr_int_event_num++;
}
                    

/*****************************************************************************
 * FUNCTION
 *  srv_sms_clear_interrupt_event_handler
 * DESCRIPTION
 *  Clear Interrupt Event Handler of the Event
 * PARAMETERS
 *  event_id        [IN]        Event ID
 *  event_func      [IN]        Event Handler Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_clear_interrupt_event_handler(
        U16 event_id,
        SrvSmsEventFunc event_func,
        void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CLEAR_INTERRUPT_EVENT_HANDLER, event_id, event_func, curr_int_event_num);

    for (i = 0; i < curr_int_event_num; i++)
    {
        srv_sms_int_event_struct *event_node = &srv_sms_int_event_list[i];
    
        if ((event_node->event_id == event_id) &&
            (event_node->int_event_func == event_func) &&
            (event_node->user_data == user_data))
        {
            U8 j;

            for (j = (i + 1); j < curr_int_event_num; j++)
            {
                memcpy(
                    &srv_sms_int_event_list[j - 1],
                    &srv_sms_int_event_list[j],
                    sizeof(srv_sms_int_event_struct));
            }

            memset(
                &srv_sms_int_event_list[curr_int_event_num - 1],
                0,
                sizeof(srv_sms_int_event_struct));

            curr_int_event_num--;

            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_exec_interrupt_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sms_exec_interrupt_event(
            U16 event_id,
            void* event_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_EXEC_INTERRUPT_EVENT, event_id, curr_int_event_num);

    for (i = 0; i < curr_int_event_num; i++)
    {
        srv_sms_int_event_struct *event_node = &srv_sms_int_event_list[i];
    
        if (event_node->event_id == event_id)
        {
            srv_sms_event_struct event_data;

            event_data.evt_id = event_id;
            event_data.size = sizeof(srv_sms_event_struct);
            event_data.user_data = event_node->user_data;
            event_data.event_info = event_info;

            if (event_node->int_event_func != NULL)
            {
                result = event_node->int_event_func(&event_data);

                if (result == MMI_TRUE)
                {
                    break;
                }
            }
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_check_dst_number
 * DESCRIPTION
 *  check if the number is valid
 * PARAMETERS
 *  num         [IN]        Dst number
 *  numLen      [IN]        Number length
 * RETURNS
 *  return true if number is valid, else return false
 *****************************************************************************/
MMI_BOOL srv_sms_check_dst_number(U8 *num, U8 numLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *number = num;
    U8 numberlen;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((numLen == 0) || (numLen > (SRV_SMS_MAX_ADDR_LEN)))
    {
        return MMI_FALSE;
    }

    if((applib_is_valid_number((kal_uint8 *)num) != APPLIB_INVALID_NUMBER))
    {
        if (number[0] == '+')
        {
            numberlen = numLen - 1;
            number++;
        }
        else
        {
            numberlen = numLen;
        }
        if ((numberlen == 0) || (numberlen > (SRV_SMS_MAX_ADDR_LEN - 1)))
        {
            return MMI_FALSE;
        }
        for (i = 0; i < numberlen; i++)
        {
            U8 digit = number[i];
        
            if ((digit < '0' || digit > '9') && digit != '*' && digit != '#')
            {
                return MMI_FALSE;
            }
        }

        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_check_sc_number
 * DESCRIPTION
 *  check if the SMS SC is valid
 * PARAMETERS
 *  num         [IN]        SC number
 *  numLen      [IN]        SC number length
 * RETURNS
 *  return true if number is valid, else return false
 *****************************************************************************/
BOOL srv_sms_check_sc_number(U8 *num, U8 numLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (numLen == 1 && num[0] == '+')
    {
        return KAL_FALSE;
    }
    return srv_sms_check_dst_number(num, numLen);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_convert_l4_num_to_ascii_num
 * DESCRIPTION
 *  Convert the L4 Number to ASCII String Number 
 * PARAMETERS
 *  ascii_number        [OUT]       ASCII String Number
 *  dest_number         [IN]        L4 Number
 *  max_ascii_num_len   [IN]        ASCII String Number Length
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_convert_l4_num_to_ascii_num(U8 *ascii_number, l4c_number_struct *l4_number, U8 max_ascii_num_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *digit_str = ascii_number;
    U8 digit_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((l4_number->type == CSMCC_INTERNATIONAL_ADDR) ||
        ((l4_number->type & 0xf0) == 0x90))
    {
        ascii_number[0] = '+';
        digit_str++;
    }

    if (l4_number->length > (max_ascii_num_len - 1))
    {
        digit_len = max_ascii_num_len - 1;
    }
    else
    {
        digit_len = l4_number->length;
    }

    memcpy(digit_str, l4_number->number, digit_len);
    *(digit_str + digit_len) = '\0';
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_convert_ascii_num_to_l4_num
 * DESCRIPTION
 *  Convert the ASCII String Number to L4 Number 
 * PARAMETERS
 *  l4_number           [OUT]     L4 Number
 *  ascii_number        [IN]      ASCII String Number
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_convert_ascii_num_to_l4_num(l4c_number_struct *l4_number, U8 *ascii_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *digit_str = (S8*)ascii_number;
    U8 digit_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ascii_number[0] == '+')
    {
        l4_number->type = CSMCC_INTERNATIONAL_ADDR;
        digit_str++;
    }
    else
    {
        l4_number->type = CSMCC_DEFAULT_ADDR_TYPE;
    }

    digit_len = strlen(digit_str);

    if (digit_len > (MAX_CC_ADDR_LEN - 1))
    {
        digit_len = MAX_CC_ADDR_LEN - 1;
    }

    l4_number->length = digit_len;

    memcpy((S8*)l4_number->number, digit_str, digit_len);
    l4_number->number[digit_len] = '\0';
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_is_hide_send_sms_menu_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
MMI_BOOL srv_sms_is_hide_send_sms_menu_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL)(!srv_sms_is_sms_valid());
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_is_sms_valid
 * DESCRIPTION
 *  whether enter sms for other module
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
MMI_BOOL srv_sms_is_sms_valid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_mode_switch_is_network_service_available())
    {
        return MMI_FALSE;
    }

#ifdef __SRV_SMS_MULTI_SIM__
    if (srv_nw_usab_is_usable(MMI_SIM1) 
		|| srv_nw_usab_is_usable(MMI_SIM2)
		#if (MMI_MAX_SIM_NUM >= 3)
		|| srv_nw_usab_is_usable(MMI_SIM3)
		#endif
		#if (MMI_MAX_SIM_NUM >= 4)
		|| srv_nw_usab_is_usable(MMI_SIM4)
		#endif
	    )
    {
        return MMI_TRUE;
    }
#else /* __SRV_SMS_MULTI_SIM__ */ 
    if (srv_sim_ctrl_is_available(MMI_SIM1))
    {
        return MMI_TRUE;
    }
#endif /* __SRV_SMS_MULTI_SIM__ */ 

    return MMI_FALSE;
}


#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_OP12_TOOLBAR__)
/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_voicemail_time
 * DESCRIPTION
 *  Get the clear recent event flag
 *  if the return MMI_TRUE, it means that the event of message is cleared
 * PARAMETERS
 *  line_no     [IN]        
 *  time        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_set_voicemail_time(U8 line_no, MYTIME *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 record_no = line_no + 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_FRM_SMS_SET_VOICEMAIL_TIME, line_no);

    if (WriteRecord(NVRAM_EF_SMS_VOICEMAIL_TIME_LID, record_no, time, NVRAM_EF_SMS_VOICEMAIL_TIME_SIZE, &error) < 0)
    {
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_voicemail_time
 * DESCRIPTION
 *  Get the clear recent event flag
 *  if the return MMI_TRUE, it means that the event of message is cleared
 * PARAMETERS
 *  line_no     [IN]        
 *  time        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_get_voicemail_time(U8 line_no, MYTIME *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 record_no = line_no + 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_FRM_SMS_GET_VOICEMAIL_TIME, line_no);

    if (ReadRecord(NVRAM_EF_SMS_VOICEMAIL_TIME_LID, record_no, time, NVRAM_EF_SMS_VOICEMAIL_TIME_SIZE, &error) < 0)
    {
        MMI_ASSERT(0);
    }
    if(mmi_dt_is_valid(time) == MMI_FALSE)
    {
        DTGetRTCTime(time);
        srv_sms_set_voicemail_time(line_no, time);
    }
}
#endif /* defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_OP12_TOOLBAR__) */ 


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_cur_segment
 * DESCRIPTION
 *  set the current used segment
 * PARAMETERS
 *  emsData     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_sms_set_cur_segment(void *ems_data, srv_sms_sim_enum sim_id)
{
    U16 result = EMS_OK;
#ifdef __EMS_DYNAMIC_SEG_NUM__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSData *data= (EMSData*)ems_data;
    U8 seg = MMI_SMS_MAX_MSG_SEG;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data->dcs == SMSAL_UCS2_DCS)
    {
        if (srv_sms_check_ucs2((S8*)data->textBuffer, (U16)(data->textLength >> 1)) == MMI_FALSE)
        {
            result = EMSSetDCS(data, SMSAL_DEFAULT_DCS);
        }
    }
    if (srv_sms_is_long_sms_dynamic_seg_setting(sim_id) == MMI_FALSE)
    {
        seg = 1;
    }
    result = EMSSetEditSegs(data, seg);

#endif /* __EMS_DYNAMIC_SEG_NUM__ */

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_recent_event_flag
 * DESCRIPTION
 *  Get Message's recent event flag
 * PARAMETERS
 *  msg_id      [IN]        Message ID
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_sms_get_msg_recent_event_flag(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_RECENT_EVENT__
    MMI_BOOL result = MMI_FALSE;
    U16 pdu_id_list[SRV_SMS_MAX_SEG];
    U8 total_num;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MSG_RECENT_EVENT_FLAG, msg_id);

    total_num = srv_sms_get_msg_pdu_id(pdu_id_list, msg_id);

    for (i = 0; i < total_num; i++)
    {
        U16 pdu_id = pdu_id_list[i];

        if (srv_sms_get_pdu_recent_event_flag(pdu_id) == MMI_TRUE)
        {
            result = MMI_TRUE;
            break;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MSG_RECENT_EVENT_FLAG, result);

    return result;
#else /* __SRV_SMS_RECENT_EVENT__ */
    return MMI_FALSE;
#endif /* __SRV_SMS_RECENT_EVENT__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_clear_msg_recent_event_flag
 * DESCRIPTION
 *  Clear Message Recent Event Flag
 * PARAMETERS
 *  msg_id      [IN]        Message ID
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_clear_msg_recent_event_flag(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_RECENT_EVENT__
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CLEAR_MSG_RECENT_EVENT_FLAG, msg_id);

    srv_sms_set_msg_recent_event_flag(msg_id, MMI_FALSE);
#endif /* __SRV_SMS_RECENT_EVENT__ */
}


#ifdef __SRV_SMS_RECENT_EVENT__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_msg_recent_event_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_set_msg_recent_event_flag(U16 msg_id, MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 pdu_id_list[SRV_SMS_MAX_SEG];
    U8 total_num;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SET_MSG_RECENT_EVENT_FLAG, msg_id, flag);

    total_num = srv_sms_get_msg_pdu_id(pdu_id_list, msg_id);

    for (i = 0; i < total_num; i++)
    {
        U16 pdu_id = pdu_id_list[i];

        srv_sms_set_pdu_recent_event_flag(pdu_id, flag);
    }

    srv_sms_write_pdu_recent_event_bitmap();
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_sms_recent_event_flag
 * DESCRIPTION
 *  set the recent event flag in the bitmap
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_set_pdu_recent_event_flag(U16 index, MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 byte_index;
    U8 bit_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(index < SRV_SMS_MAX_SMS_ENTRY);

    byte_index = (index >> 3);
    bit_index = (index & 0x7);

    /*
     * if the set 1, it means this recent event is cleared;
     * And the orignal state of each sms related the recent event is 0 
     * (every sms need to show it in the recent event list except it is
     * cleared by the user);
     * If remove a sms, need to set it to be the orignal state.
     */
    if (flag == MMI_FALSE)
    {
        srv_sms_recent_event_bitmap[byte_index] |= (0x01 << bit_index);
    }
    else
    {
        srv_sms_recent_event_bitmap[byte_index] &= (~(0x01 << bit_index));
    }

    srv_sms_write_pdu_recent_event_bitmap();
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_pdu_recent_event_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        L4 index of the msg
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sms_get_pdu_recent_event_flag(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 byte_index;
    U8 bit_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    byte_index = (index >> 3);
    bit_index = (index & 0x7);

    if ((srv_sms_recent_event_bitmap[byte_index] & (0x01 << bit_index)) == 0)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_write_pdu_recent_event_bitmap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_write_pdu_recent_event_bitmap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_WRITE_PDU_RECENT_EVENT_BITMAP);

    if (WriteRecord(
            NVRAM_EF_SRV_SMS_RECENT_EVENT_BITMAP_LID,
            1,
            srv_sms_recent_event_bitmap,
            NVRAM_EF_SRV_SMS_RECENT_EVENT_BITMAP_SIZE,
            &error) < 0)
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_WRITE_PDU_RECENT_EVENT_BITMAP_1, error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_read_pdu_recent_event_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_read_sms_recent_event_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_SMS_RECENT_EVENT_SETTING);

#if (MMI_MAX_SIM_NUM >= 2)
    if (SMU_SIM_REPLACED == check_sim_status(SIM1) || SMU_SIM_REPLACED == check_sim_status(SIM2))
#else
    if (SMU_SIM_REPLACED == check_sim_status())
#endif /* (MMI_MAX_SIM_NUM >= 2)*/
    {
        memset((S8*) srv_sms_recent_event_bitmap, 0, SRV_SMS_RECENT_EVENT_BITMAP_SISE);

        if (WriteRecord(
                NVRAM_EF_SRV_SMS_RECENT_EVENT_BITMAP_LID,
                1,
                srv_sms_recent_event_bitmap,
                NVRAM_EF_SRV_SMS_RECENT_EVENT_BITMAP_SIZE,
                &error) < 0)
        {
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_SMS_RECENT_EVENT_SETTING_1, error);
        }
    }
    else
    {
        if (ReadRecord(
                NVRAM_EF_SRV_SMS_RECENT_EVENT_BITMAP_LID,
                1,
                srv_sms_recent_event_bitmap,
                NVRAM_EF_SRV_SMS_RECENT_EVENT_BITMAP_SIZE,
                &error) < 0)
        {
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_READ_SMS_RECENT_EVENT_SETTING_2, error);
        }
    }
}
#endif /* __SRV_SMS_RECENT_EVENT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sms_sms_get_bitmap_index
 * DESCRIPTION
 *  get sms index from bitmap
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_sms_get_bitmap_index(U16 start_index, U8 *bitmap, U16 bitmap_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 start_byte_idx;
    U8 start_bit_idx;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    start_byte_idx = (start_index >> 3);
    start_bit_idx = (start_index & 0x7);

    for (i = start_byte_idx; i < bitmap_size; i++)
    {
        U8 mapping_byte;
        U8 j;

        mapping_byte = bitmap[i];

        for (j = start_bit_idx; j < 8; j++)
        {
            if (((mapping_byte >> j) & 0x01) == 0x01)
            {
                return (i * 8 + j);
            }
        }

        start_bit_idx = 0;
    }

    return SRV_SMS_INVALID_BITMAP_INDEX;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_bitmap_index
 * DESCRIPTION
 *  set bitmap from index
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_set_bitmap_index(U16 index, U8 *bitmap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 byte_index;
    U8 bit_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    byte_index = (index >> 3);
    bit_index = (index & 0x7);
    bitmap[byte_index] |= (0x01 << bit_index);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_clear_bitmap_index
 * DESCRIPTION
 *  set bitmap from index
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_clear_bitmap_index(U16 index, U8 *bitmap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 byte_index;
    U8 bit_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    byte_index = (index >> 3);
    bit_index = (index & 0x7);
    bitmap[byte_index] &= (~(0x01 << bit_index));
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_check_bitmap_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sms_check_bitmap_index(U16 index, U8 *bitmap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 byte_idx;
    U8 bit_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    byte_idx = (index >> 3);
    bit_idx = (index & 0x7);

    if (bitmap[byte_idx] & (0x01 << bit_idx))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_emit_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_emit_event(U32 event_id, void* event_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_struct event_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_EMIT_EVENT, event_id);

    MMI_FRM_INIT_EVENT(&event_data, event_id);
    event_data.event_info = event_info;

    MMI_FRM_CB_EMIT_EVENT(&event_data);
}



/*****************************************************************************
 * FUNCTION
 *  srv_sm_get_counter_access_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static U16 srv_sm_get_counter_access_id(srv_sms_sim_enum sim_id, srv_sms_count_type_enum sms_count_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    const U16 access_id[][2] = 
    {
        {NVRAM_SMSCOUNTERS_SENT_SHORT, NVRAM_SMSCOUNTERS_RECD_SHORT}
    #if (MMI_MAX_SIM_NUM >= 2)
        ,{NVRAM_SIM2_SMSCOUNTERS_SENT, NVRAM_SIM2_SMSCOUNTERS_RECV}
    #endif
    #if (MMI_MAX_SIM_NUM >= 3)
        ,{NVRAM_SIM3_SMSCOUNTERS_SENT, NVRAM_SIM3_SMSCOUNTERS_RECV}
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        ,{NVRAM_SIM4_SMSCOUNTERS_SENT, NVRAM_SIM4_SMSCOUNTERS_RECV}
    #endif
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = srv_sms_sim_id_to_sim_index(sim_id);

    return access_id[index][sms_count_type];
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_init_sms_counter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_init_sms_counter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U16 access_id;
    U32 type_index;
    U32 index;
    srv_sms_sim_enum sim_id;
    U16 *sms_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < MMI_SIM_TOTAL; index++)
    {
        sim_id = srv_sms_sim_index_to_sim_id(index);

        for (type_index = 0; type_index < SRV_SMS_COUNT_TOTAL; type_index++)
        {
            access_id = srv_sm_get_counter_access_id(sim_id, (srv_sms_count_type_enum)type_index);

            sms_num = &srv_sms_counter[index].sms_num[type_index];

            ReadValue(access_id, sms_num, DS_SHORT, &error);

            if ((*sms_num) == 0xffff)
            {
                srv_sms_write_sms_counter(sim_id, (srv_sms_count_type_enum)type_index, 0);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_reset_sms_counter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_write_sms_counter(srv_sms_sim_enum sim_id, srv_sms_count_type_enum sms_count_type, U16 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U16 access_id;
    srv_sms_event_msg_waitting_struct *event_data;
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = srv_sms_sim_id_to_sim_index(sim_id);

    access_id = srv_sm_get_counter_access_id(sim_id, sms_count_type);

    srv_sms_counter[index].sms_num[sms_count_type] = count; 

    access_id = srv_sm_get_counter_access_id(sim_id, sms_count_type);

    WriteValue(access_id, &count, DS_SHORT, &error);

    event_data = OslMalloc(sizeof(srv_sms_event_msg_counter_update_struct));
    event_data->sim_id = sim_id;
    srv_sms_emit_event(EVT_ID_SRV_SMS_UPDATE_COUNTER, event_data);
    OslMfree(event_data);    
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_update_sms_counter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_update_sms_counter(srv_sms_sim_enum sim_id, srv_sms_count_type_enum sms_count_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 counter;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    counter = srv_sms_get_sms_counter(sim_id, sms_count_type);
    srv_sms_write_sms_counter(sim_id, sms_count_type, (counter + 1));
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_reset_sms_counter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_reset_sms_counter(srv_sms_sim_enum sim_id, srv_sms_count_type_enum sms_count_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_write_sms_counter(sim_id, sms_count_type, 0);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_slave_sms_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_sms_get_sms_counter(srv_sms_sim_enum sim_id, srv_sms_count_type_enum sms_count_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = srv_sms_sim_id_to_sim_index(sim_id);

    return srv_sms_counter[index].sms_num[sms_count_type];
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_sms_segment_number
 * DESCRIPTION
 *  This function is used to get number of segments of SMS message.
 * PARAMETERS
 *  UCS2_count                  [IN]        UCS2 character number
 *  char_count                  [IN]        Character (GSM-7Bit and UCS2) total number
 *  extension_char_count        [IN]        GSM-7Bit extension character number      
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_sms_get_sms_segment_number(U16 UCS2_count, U16 char_count, U16 extension_char_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSNationalLanguage sys_lang;
    U8 segment = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SMS_R8_NATION_LANGUAGE__
    EMSNationalLanguageType curr_lang_type;                
    EMSNationalLanguageType sys_lang_type;

    curr_lang_type = mmi_7bit_get_national_lang();

    sys_lang_type = srv_sms_get_system_ems_lang_type();

    if (curr_lang_type != sys_lang_type)
    {
        mmi_7bit_set_national_lang(sys_lang_type);
    }

    mmi_7bit_get_national_lang_table(&sys_lang);
    
    if (curr_lang_type != sys_lang_type)
    {
        mmi_7bit_set_national_lang(curr_lang_type);
    } 
#else /* __SMS_R8_NATION_LANGUAGE__ */
    sys_lang.locking_shift = EMS_NL_DEFAULT;
    sys_lang.single_shift = EMS_NL_DEFAULT;
#endif /* __SMS_R8_NATION_LANGUAGE__ */

    if (UCS2_count)
    {
        if (EMSCalculateSegEx(SMSAL_UCS2_DCS, &sys_lang, (U16) (char_count * 2), &segment) == EMS_OK)
        {
            return segment;
        }
    }
    else
    {
        if (EMSCalculateSegEx(SMSAL_DEFAULT_DCS, &sys_lang, (U16) ((char_count + extension_char_count) * 2), &segment)
            == EMS_OK)
        {
            return segment;
        }
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_last_segment_remaining
 * DESCRIPTION
 *  This function is used to get number of remaining characters of last segment.
 * PARAMETERS
 *  UCS2_count                  [IN]        UCS2 character number
 *  char_count                  [IN]        Character (GSM-7Bit and UCS2) total number
 *  extension_char_count        [IN]        GSM-7Bit extension character number
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_sms_get_last_segment_remaining(U16 UCS2_count, U16 char_count, U16 extension_char_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSNationalLanguage sys_lang;
    U8 remain_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SMS_R8_NATION_LANGUAGE__
    EMSNationalLanguageType curr_lang_type;                
    EMSNationalLanguageType sys_lang_type;

    curr_lang_type = mmi_7bit_get_national_lang();

    sys_lang_type = srv_sms_get_system_ems_lang_type();

    if (curr_lang_type != sys_lang_type)
    {
        mmi_7bit_set_national_lang(sys_lang_type);
    }

    mmi_7bit_get_national_lang_table(&sys_lang);
    
    if (curr_lang_type != sys_lang_type)
    {
        mmi_7bit_set_national_lang(curr_lang_type);
    }  
#else /* __SMS_R8_NATION_LANGUAGE__ */
    sys_lang.locking_shift = EMS_NL_DEFAULT;
    sys_lang.single_shift = EMS_NL_DEFAULT;
#endif /* __SMS_R8_NATION_LANGUAGE__ */

    if (UCS2_count)
    {
        if (EMSCalculateLastSegRemainingChar(SMSAL_UCS2_DCS, &sys_lang, (U16) (char_count * 2), &remain_count)
            == EMS_OK)
        {
            return ((U8) (remain_count / 2));
        }
    }
    else
    {
        if (EMSCalculateLastSegRemainingChar
            (SMSAL_DEFAULT_DCS, &sys_lang, (U16) ((char_count + extension_char_count) * 2), &remain_count) == EMS_OK)
        {
            return remain_count;
        }
    }

    return 0;
}


/*****************************************************************************
* FUNCTION
*  srv_sms_get_usable_text_len
* DESCRIPTION
*  This function is used to get number of max characters of SMS message.
* PARAMETERS
*  dcs            [IN]
* RETURNS
*  number of max characters
*****************************************************************************/
U16 srv_sms_get_usable_text_len(U8 dcs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSNationalLanguage sys_lang;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SMS_R8_NATION_LANGUAGE__
    EMSNationalLanguageType curr_lang_type;                
    EMSNationalLanguageType sys_lang_type;
    
    curr_lang_type = mmi_7bit_get_national_lang();
    
    sys_lang_type = srv_sms_get_system_ems_lang_type();
    
    if (curr_lang_type != sys_lang_type)
    {
        mmi_7bit_set_national_lang(sys_lang_type);
    }
    
    mmi_7bit_get_national_lang_table(&sys_lang);

    if (curr_lang_type != sys_lang_type)
    {
        mmi_7bit_set_national_lang(curr_lang_type);
    }  
#else /* __SMS_R8_NATION_LANGUAGE__ */
    sys_lang.locking_shift = EMS_NL_DEFAULT;
    sys_lang.single_shift = EMS_NL_DEFAULT;
#endif /* __SMS_R8_NATION_LANGUAGE__ */

    return ((U16) EMSUsableTextLenEx(dcs, &sys_lang));
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_sim_index_to_sim_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_sms_sim_enum srv_sms_sim_index_to_sim_id(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 2)              
    srv_sms_sim_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (index)
    {
        case SMS_SIM1:
            sim_id = SRV_SMS_SIM_1;
            break;

        case SMS_SIM2:
            sim_id = SRV_SMS_SIM_2;
            break;
	#if (MMI_MAX_SIM_NUM >= 3)
        case SMS_SIM3:
            sim_id = SRV_SMS_SIM_3;
            break;
	#endif
	#if (MMI_MAX_SIM_NUM >= 4)
        case SMS_SIM4:
            sim_id = SRV_SMS_SIM_4;
            break;
	#endif

        default:
            sim_id = SRV_SMS_SIM_1;
            break;
    }

    return sim_id;
#else /*  (MMI_MAX_SIM_NUM >= 2)*/
    return SRV_SMS_SIM_1;
#endif /*  (MMI_MAX_SIM_NUM >= 2) */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_sim_id_to_sim_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_sms_sim_id_to_sim_index(srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if  (MMI_MAX_SIM_NUM >= 2)
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (sim_id)
    {
        case SRV_SMS_SIM_1:
            index = SMS_SIM1;
            break;

        case SRV_SMS_SIM_2:
            index = SMS_SIM2;
            break;
    #if (MMI_MAX_SIM_NUM >= 3)
        case SRV_SMS_SIM_3:
            index = SMS_SIM3;
            break;
	#endif
	#if (MMI_MAX_SIM_NUM >= 4)
        case SRV_SMS_SIM_4:
            index = SMS_SIM4;
            break;
	#endif
        default:
            index = SMS_SIM1;
            break;
    }

    return index;
#else /*   (MMI_MAX_SIM_NUM >= 2) */
    return SMS_SIM1;
#endif /*   (MMI_MAX_SIM_NUM >= 2) */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_local_sec
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_sms_get_local_sec(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME local_time;
    U32 local_sec;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DTGetRTCTime(&local_time);

    local_sec =  mmi_dt_mytime_2_utc_sec(&local_time, MMI_FALSE);

    return local_sec;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_pdu_block_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_pdu_block_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < (SRV_SMS_SPDU_BLOCK_NUM - 1); i++)
    {
        spdu_block_list[i].next = &spdu_block_list[i + 1];
    }

    spdu_block_list[SRV_SMS_SPDU_BLOCK_NUM - 1].next = NULL;

    free_block_head = &spdu_block_list[0];
    used_block_head = NULL;
}


#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_pdu_block_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_tcard_pdu_block_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < (SRV_SMS_SPDU_BLOCK_NUM - 1); i++)
    {
        tcard_spdu_block_list[i].next = &tcard_spdu_block_list[i + 1];
    }

    tcard_spdu_block_list[SRV_SMS_SPDU_BLOCK_NUM - 1].next = NULL;

    tcard_free_block_head = &tcard_spdu_block_list[0];
    tcard_used_block_head = NULL;
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_alloc_pdu_block
 * DESCRIPTION
 *  Alloc a PDU/SPDU buffer, only for allocate PDU or SPDU buffer 
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void* srv_sms_alloc_tcard_pdu_block(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sms_tcard_spdu_block_struct *new_node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tcard_free_block_head)
    {
        /* Allocate the node in the head of free block list */
        new_node = tcard_free_block_head;
        tcard_free_block_head = tcard_free_block_head->next;

        new_node->is_ctrl_buff = MMI_FALSE;
        new_node->next = NULL;

        /* Add the allocated node in the last of used block list */
        if (tcard_used_block_head)
        {
            sms_tcard_spdu_block_struct *last_node = tcard_used_block_head;

            while (last_node->next)
            {
                last_node = last_node->next;
            }

            last_node->next = new_node;
        }
        else
        {
            tcard_used_block_head = new_node;
        }
    }
    else
    {
        if (tcard_ctrl_buff_block_count < MAX_CTRL_BUFF_SPDU_BLOCK_NUM)
        {
            tcard_ctrl_buff_block_count++;
            new_node = OslMalloc(sizeof(sms_tcard_spdu_block_struct));
            new_node->is_ctrl_buff = MMI_TRUE;
        }
    }

    if (new_node)
    {
        return (void*)new_node->buffer;
    }
    else
    {
        return NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_free_pdu_block
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_free_tcard_pdu_block(void* buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sms_tcard_spdu_block_struct *free_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer == NULL)
    {
        return;
    }

    free_node = (sms_tcard_spdu_block_struct*)((U8*)buffer - SRV_SMS_TCARD_BLOCK_OFFSET);

    if (free_node->is_ctrl_buff)
    {
        MMI_ASSERT(tcard_ctrl_buff_block_count > 0);

        tcard_ctrl_buff_block_count--;

        OslMfree(free_node);
    }
    else
    {
        sms_tcard_spdu_block_struct *curr_node = tcard_used_block_head;
        sms_tcard_spdu_block_struct *prev_node = NULL;

        /* Before free the node, need to check it is in the used block list */
        while (curr_node)
        {
            if (curr_node == free_node)
            {
                if (prev_node)
                {
                    prev_node->next = curr_node->next;
                }
                else
                {
                    /* The free node is the first node in the used block list */
                    tcard_used_block_head = curr_node->next;
                }

                /* Add free node in the head of free block list */
                if (tcard_free_block_head)
                {
                    free_node->next = tcard_free_block_head;
                }
                else
                {
                    free_node->next = NULL;
                }

                tcard_free_block_head = free_node;
                break;
            }

            prev_node = curr_node;
            curr_node = curr_node->next;
        }
    }
}



#endif


/*****************************************************************************
 * FUNCTION
 *  srv_sms_alloc_pdu_block
 * DESCRIPTION
 *  Alloc a PDU/SPDU buffer, only for allocate PDU or SPDU buffer 
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void* srv_sms_alloc_pdu_block(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sms_spdu_block_struct *new_node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (free_block_head)
    {
        /* Allocate the node in the head of free block list */
        new_node = free_block_head;
        free_block_head = free_block_head->next;

        new_node->is_ctrl_buff = MMI_FALSE;
        new_node->next = NULL;

        /* Add the allocated node in the last of used block list */
        if (used_block_head)
        {
            sms_spdu_block_struct *last_node = used_block_head;

            while (last_node->next)
            {
                last_node = last_node->next;
            }

            last_node->next = new_node;
        }
        else
        {
            used_block_head = new_node;
        }
    }
    else
    {
        if (ctrl_buff_block_count < MAX_CTRL_BUFF_SPDU_BLOCK_NUM)
        {
            ctrl_buff_block_count++;
            new_node = OslMalloc(sizeof(sms_spdu_block_struct));
            new_node->is_ctrl_buff = MMI_TRUE;
        }
    }

    if (new_node)
    {
        return (void*)new_node->buffer;
    }
    else
    {
        return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_free_pdu_block
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_free_pdu_block(void* buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sms_spdu_block_struct *free_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer == NULL)
    {
        return;
    }

    free_node = (sms_spdu_block_struct*)((U8*)buffer - SRV_SMS_BLOCK_OFFSET);

    if (free_node->is_ctrl_buff)
    {
        MMI_ASSERT(ctrl_buff_block_count > 0);

        ctrl_buff_block_count--;

        OslMfree(free_node);
    }
    else
    {
        sms_spdu_block_struct *curr_node = used_block_head;
        sms_spdu_block_struct *prev_node = NULL;

        /* Before free the node, need to check it is in the used block list */
        while (curr_node)
        {
            if (curr_node == free_node)
            {
                if (prev_node)
                {
                    prev_node->next = curr_node->next;
                }
                else
                {
                    /* The free node is the first node in the used block list */
                    used_block_head = curr_node->next;
                }

                /* Add free node in the head of free block list */
                if (free_block_head)
                {
                    free_node->next = free_block_head;
                }
                else
                {
                    free_node->next = NULL;
                }

                free_block_head = free_node;
                break;
            }

            prev_node = curr_node;
            curr_node = curr_node->next;
        }
    }
}


#ifdef __SMS_R8_NATION_LANGUAGE__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_system_ems_lang_type
 * DESCRIPTION
 *  Get System EMS Language Type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
EMSNationalLanguageType srv_sms_get_system_ems_lang_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMSNationalLanguageType lang;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strcmp((PS8)gLanguageArray[gCurrLangIndex].aLangSSC, SSC_TURKISH) == 0)
    {
        lang = EMS_NL_TURKISH;
    }
    else if (strcmp((PS8)gLanguageArray[gCurrLangIndex].aLangSSC, SSC_SPANISH) == 0)
    {
        lang = EMS_NL_SPANISH;
    }
    else if (strcmp((PS8)gLanguageArray[gCurrLangIndex].aLangSSC, SSC_PORTUGUESE) == 0)
    {
        lang = EMS_NL_PORTUGUESE;
    }
    else
    {
        lang = EMS_NL_DEFAULT;
    }

    return lang;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  srv_sms_cmp_asc_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_cmp_asc_num(char* dest, char* src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR src_addr[SRV_SMS_MAX_ADDR_LEN + 1];
    WCHAR dest_addr[SRV_SMS_MAX_ADDR_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_n_to_wcs(src_addr, (CHAR*)src, SRV_SMS_MAX_ADDR_LEN);
    mmi_asc_n_to_wcs(dest_addr, (CHAR*)dest, SRV_SMS_MAX_ADDR_LEN);

    return srv_phb_compare_number(src_addr, dest_addr);
}


/***************************************************************************** 
 * Class 
 *****************************************************************************/
#ifdef __SRV_SMS_TEMPLATE__
#include "mmi_rp_srv_sms_def.h"
#include "FontRes.h"
#include "SSCStringHandle.h"
#include "FontDCl.h"
#include "Nvram_common_defs.h"
#include "CustDataRes.h"
#include "GeneralSettingSrvGprot.h"

#ifdef _MUTILANG_TEMPLATE_
#include "Lang_interface.h"


extern sLanguageDetails *gLanguageArray;
extern U16 gCurrLangIndex;

#define SRV_SMS_TEMPLATE_LANGUAGE_DEFAULT    SSC_ENGLISH
#define SRV_SMS_TEMPLATE_LANGUAGE_SECOND     SSC_SCHINESE
#define SRV_SMS_TEMPLATE_LANGUAGE_THIRD      SSC_TCHINESE

typedef enum
{
    SRV_SMS_TEMPLATE_LANGUAGE_DEFAULT_TYPE,
    SRV_SMS_TEMPLATE_LANGUAGE_SECOND_TYPE,
    SRV_SMS_TEMPLATE_LANGUAGE_THIRD_TYPE,
    SRV_SMS_TEMPLATE_LANGUAGE_TOTAL
} srv_sms_template_language_base_enum;
#endif /* _MUTILANG_TEMPLATE_ */

#ifdef __SRV_SMS_PREDEFINED_TEMPLATE__
static const U16 srv_sms_template_str[] = 
{
    STR_ID_SRV_SMS_TEMPLATE_1,
    STR_ID_SRV_SMS_TEMPLATE_2,
    STR_ID_SRV_SMS_TEMPLATE_3,
    STR_ID_SRV_SMS_TEMPLATE_4,
    STR_ID_SRV_SMS_TEMPLATE_5,
    STR_ID_SRV_SMS_TEMPLATE_6,
    STR_ID_SRV_SMS_TEMPLATE_7,
    STR_ID_SRV_SMS_TEMPLATE_8,
    STR_ID_SRV_SMS_TEMPLATE_9,
    STR_ID_SRV_SMS_TEMPLATE_10
};
#endif

typedef struct
{
    WCHAR content[NVRAM_SMS_TEMPLATE_UCS2_CONTENT_RECORD_SIZE];
    U32 time;
} srv_sms_template_data_struct;

static U16 srv_sms_template_list[SRV_SMS_TEMPLATE_TOTAL_NUM];
static U32 srv_sms_template_time_list[SRV_SMS_TEMPLATE_TOTAL_NUM];
static U16 srv_sms_template_size;
static MMI_BOOL srv_sms_template_init_done = MMI_FALSE;
#ifdef __SRV_SMS_PREDEFINED_TEMPLATE__
static U16 srv_sms_template_pd_size;
static U16 srv_sms_template_pd_exist_flag;
#endif /* __SRV_SMS_PREDEFINED_TEMPLATE__ */
#ifdef __SRV_SMS_USERDEFINED_TEMPLATE__
static U16 srv_sms_template_ud_size;
static U32 srv_sms_template_ud_exist_flag;
#endif /* __SRV_SMS_USERDEFINED_TEMPLATE__ */
static void srv_sms_template_delete_from_list(U16 template_id);
static U16 srv_sms_template_cal_base(srv_sms_template_type_enum templ_type);


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_sms_template_get_list_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(srv_sms_template_size <= SRV_SMS_TEMPLATE_TOTAL_NUM);

    return srv_sms_template_size;
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_template_is_full(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((srv_sms_template_size == SRV_SMS_TEMPLATE_TOTAL_NUM)
        || (srv_sms_template_ud_size == SRV_SMS_TEMPLATE_USERDEFINED_NUM))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_sms_template_get_id(U16 list_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list_index < srv_sms_template_size)
    {
        return srv_sms_template_list[list_index];
    }
    else
    {
        return SRV_SMS_TEMPLATE_INVALIDE_ID;
    }
}

U16 srv_sms_template_get_list_index(U16 template_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < srv_sms_template_size; index++)
    {
        if (srv_sms_template_list[index] == template_id)
        {
            return index;
        }
    }

    return SRV_SMS_INVALID_LIST_INDEX;
}

srv_sms_template_type_enum srv_sms_template_get_type(U16 template_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_template_type_enum template_type = SRV_SMS_TEMPLATE_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_PREDEFINED_TEMPLATE__
    if (template_id < SRV_SMS_TEMPLATE_PREDEFINED_NUM)
    {
        template_type = SRV_SMS_TEMPLATE_PRE_DEFINED;
    }
    else
#endif
    {
    #ifdef __SRV_SMS_USERDEFINED_TEMPLATE__
        template_type = SRV_SMS_TEMPLATE_USER_DEFINED;
    #endif
    }

    return template_type;
}

#ifdef __SRV_SMS_PREDEFINED_TEMPLATE__
/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_sms_template_write_pd_to_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
    S16 error;
    srv_sms_template_data_struct *data = OslMalloc(SRV_SMS_TEMPLATE_RECORD_SIZE);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_SMS_TEMPLATE_PREDEFINED_NUM; i++)
    {
        U32 str_len;
        U16 base = i + srv_sms_template_cal_base(SRV_SMS_TEMPLATE_PRE_DEFINED);
        S8 *tmpl_str;

        tmpl_str = (S8*)GetString(srv_sms_template_str[i]);

        if (tmpl_str != NULL)
        {
            str_len = mmi_ucs2strlen(tmpl_str);

            if (SRV_SMS_TEMPLATE_MAX_CHAR_NUM > str_len)
            {
                memcpy(data->content, tmpl_str, (str_len + 1) * ENCODING_LENGTH);
            }
            else
            {
                memcpy(data->content, tmpl_str, SRV_SMS_TEMPLATE_MAX_CHAR_NUM * ENCODING_LENGTH);
                data->content[SRV_SMS_TEMPLATE_MAX_CHAR_NUM] = '\0';
            }
        }
        else
        {
            memset(&data, 0, SRV_SMS_TEMPLATE_RECORD_SIZE);
        }

        data->time = SRV_SMS_TEMPLATE_PREDEFINED_NUM - i; /* predefiend template's time set from 0 to (SRV_SMS_TEMPLATE_PREDEFINED_NUM-1) */

        if (i < NVRAM_SMS_PD_TEMPLATE_RECORD_TOTAL)
        {
            /*  1. The first record index of the LID is 1;
             *  2. And the first record is used to as a mark to 
             *     indicate the intialization status;
             *  So, the record index of the first template is 2;
             */
            if (WriteRecord(NVRAM_EF_SMS_PD_TEMPLATE_LID, (U16)(base + 2), data,
                    SRV_SMS_TEMPLATE_RECORD_SIZE, &error) != SRV_SMS_TEMPLATE_RECORD_SIZE)
            {
                OslMfree(data);
                return MMI_FALSE;
            }
        }
        else
        {
            OslMfree(data);
            return MMI_FALSE;
        }
    }

    OslMfree(data);
    return MMI_TRUE;
}


#ifdef _MUTILANG_TEMPLATE_
/*****************************************************************************
 * FUNCTION
 *  srv_sms_template_language_changed_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret srv_sms_template_language_changed_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SETTING_LANGUAGE_CHANGED:
        {
            if (srv_sms_template_init_done)
            {
                U16 i;
                U16 max = SRV_SMS_TEMPLATE_PREDEFINED_NUM + SRV_SMS_TEMPLATE_USERDEFINED_NUM;

                for (i = 0; i < max; i++)
                {
                    srv_sms_template_delete_from_list(i);
                }

                srv_sms_template_init_done = MMI_FALSE;

                srv_sms_template_init_proc();
            }
            break;
        }

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_template_set_language(U8 langtype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i = 0;
    U8 tempLang[SSC_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(tempLang, 0, SSC_SIZE);

    switch (langtype)
    {
        case SRV_SMS_TEMPLATE_LANGUAGE_DEFAULT_TYPE:
            memcpy(tempLang, SRV_SMS_TEMPLATE_LANGUAGE_DEFAULT, SSC_SIZE);
            break;
        case SRV_SMS_TEMPLATE_LANGUAGE_SECOND_TYPE:
            memcpy(tempLang, SRV_SMS_TEMPLATE_LANGUAGE_SECOND, SSC_SIZE);
            break;
        case SRV_SMS_TEMPLATE_LANGUAGE_THIRD_TYPE:
            memcpy(tempLang, SRV_SMS_TEMPLATE_LANGUAGE_THIRD, SSC_SIZE);
            break;
    }
    i = mmi_lang_support(tempLang);
    if (i >= 0)
    {
    #ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
        srv_setting_set_language_ext((U8*)tempLang);
            
    #else
        srv_setting_set_language_ext((U8)i);
    #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_template_unset_language(CHAR* curr_lang)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = mmi_lang_support((U8*)curr_lang);
    if (i >= 0)
    {
    #ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__       
        srv_setting_set_language_ext((U8*)curr_lang);            
    #else
        srv_setting_set_language_ext((U8)i);
    #endif
    }
}
#endif /* _MUTILANG_TEMPLATE_ */



/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_template_init_pd_to_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
    srv_sms_template_data_struct data;
    S16 error;
    U16 i;
#ifdef _MUTILANG_TEMPLATE_
    U8 curr_lang[SSC_SIZE];
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef _MUTILANG_TEMPLATE_
    memcpy(curr_lang, (PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_SIZE);
    for (i = 0; i < SRV_SMS_TEMPLATE_LANGUAGE_TOTAL; i++)
    {
        srv_sms_template_set_language((U8) i);

        if (srv_sms_template_write_pd_to_nvram() == MMI_FALSE)
        {
            result = MMI_FALSE;
        }
    }
    srv_sms_template_unset_language((CHAR*)curr_lang);
#else /* _MUTILANG_TEMPLATE_ */ 
    if (srv_sms_template_write_pd_to_nvram() == MMI_FALSE)
    {
        result = MMI_FALSE;
    }
#endif /* _MUTILANG_TEMPLATE_ */ 

    data.content[0] = 'A';
    data.content[1] = '\0';

    if (WriteRecord(NVRAM_EF_SMS_PD_TEMPLATE_LID, 1, &data,
            SRV_SMS_TEMPLATE_RECORD_SIZE, &error) < SRV_SMS_TEMPLATE_RECORD_SIZE)
    {
        result = MMI_FALSE;
    }

    return result;
}
#endif /* __SRV_SMS_PREDEFINED_TEMPLATE__ */


#ifdef __SRV_SMS_USERDEFINED_TEMPLATE__
/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_template_init_ud_to_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
    srv_sms_template_data_struct data;
    S16 error;
    //U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    data.content[0] = 'B';
    data.content[1] = '\0';

    if (WriteRecord(NVRAM_EF_SMS_UD_TMEPLATE_LID, 1, &data,
        SRV_SMS_TEMPLATE_RECORD_SIZE, &error) < SRV_SMS_TEMPLATE_RECORD_SIZE)
    {
        result = MMI_FALSE;
    }

    return result;
}
#endif /* __SRV_SMS_USERDEFINED_TEMPLATE__ */ 


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_template_add_to_list(U16 template_id, U32 time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    srv_sms_event_add_template_struct event_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(template_id < SRV_SMS_TEMPLATE_TOTAL_NUM);

    if (srv_sms_template_size > 0)
    {
        for (i = srv_sms_template_size - 1; i >= 0; i--)
        {
            U16 temp_id = srv_sms_template_list[i];

            if (time >= srv_sms_template_time_list[temp_id])
            {
                srv_sms_template_list[i + 1] = srv_sms_template_list[i];
            }
            else
            {
                srv_sms_template_list[i + 1] = template_id;
                break;
            }

            if (i == 0)
            {
                srv_sms_template_list[i] = template_id;
                break;
            }
        }
    }
    else
    {
        srv_sms_template_list[0] = template_id;
    }

    srv_sms_template_time_list[template_id] = time;
    srv_sms_template_size++;

#ifdef __SRV_SMS_PREDEFINED_TEMPLATE__
    if (template_id < SRV_SMS_TEMPLATE_PREDEFINED_NUM)
    {
        srv_sms_template_pd_exist_flag |= (1<<template_id);
        srv_sms_template_pd_size++;
    }
    else
#endif
    {
    #ifdef __SRV_SMS_USERDEFINED_TEMPLATE__
        srv_sms_template_ud_exist_flag |= (1<<(template_id - SRV_SMS_TEMPLATE_PREDEFINED_NUM));
        srv_sms_template_ud_size++;
    #endif
    }

    event_data.list_index = srv_sms_template_get_list_index(template_id);
    event_data.template_id = template_id;
    srv_sms_emit_event(EVT_ID_SRV_SMS_ADD_TEMPLATE, &event_data);
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_template_delete_from_list(U16 template_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 j;
    srv_sms_event_del_template_struct event_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    event_data.template_id = template_id;
    event_data.list_index = srv_sms_template_get_list_index(template_id);

    for (i = 0; i < srv_sms_template_size; i++)
    {
        if (srv_sms_template_list[i] == template_id)
        break;
    }

    if (i < srv_sms_template_size)
    {
        for (j = i; j < srv_sms_template_size; j++)
        {
            srv_sms_template_list[j] = srv_sms_template_list[j + 1];
        }

        srv_sms_template_size--;
    #ifdef __SRV_SMS_PREDEFINED_TEMPLATE__
        if (template_id < SRV_SMS_TEMPLATE_PREDEFINED_NUM)
        {
            srv_sms_template_pd_exist_flag ^= (1<<template_id);
            srv_sms_template_pd_size--;
        }
        else
    #endif
        {
        #ifdef __SRV_SMS_USERDEFINED_TEMPLATE__
            srv_sms_template_ud_exist_flag ^= (1<<(template_id - SRV_SMS_TEMPLATE_PREDEFINED_NUM));
            srv_sms_template_ud_size--;
        #endif
        }
    
        srv_sms_emit_event(EVT_ID_SRV_SMS_DEL_TEMPLATE, &event_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_template_init_proc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
    srv_sms_template_data_struct data;
    S16 error;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_template_init_done)
    {
        return result;
    }

    memset(srv_sms_template_list, 0xFF, sizeof(U16) * SRV_SMS_TEMPLATE_TOTAL_NUM);
    memset(srv_sms_template_time_list, 0xFF, sizeof(U32) * SRV_SMS_TEMPLATE_TOTAL_NUM);
    srv_sms_template_size = 0;
#ifdef __SRV_SMS_PREDEFINED_TEMPLATE__
    srv_sms_template_pd_size = 0;
    srv_sms_template_pd_exist_flag = 0;
#endif /*__SRV_SMS_PREDEFINED_TEMPLATE__*/
#ifdef __SRV_SMS_USERDEFINED_TEMPLATE__
    srv_sms_template_ud_size = 0;
    srv_sms_template_ud_exist_flag = 0;
#endif /* __SRV_SMS_USERDEFINED_TEMPLATE__ */

#ifdef __SRV_SMS_PREDEFINED_TEMPLATE__
    if (ReadRecord(NVRAM_EF_SMS_PD_TEMPLATE_LID, 1, &data, SRV_SMS_TEMPLATE_RECORD_SIZE, &error) < 0)
    {
        data.content[0] = '\0';
    }
    if (data.content[0] != 'A')
    {
        if (!srv_sms_template_init_pd_to_nvram())
        {
            result = MMI_FALSE;
        }

        for (i = 0; i < SRV_SMS_TEMPLATE_PREDEFINED_NUM; i++)
        {
            srv_sms_template_add_to_list(i, SRV_SMS_TEMPLATE_PREDEFINED_NUM - i);/* predefiend template's time set (SRV_SMS_TEMPLATE_PREDEFINED_NUM-i) */
        }
    }
    else
    {
        U16 base = srv_sms_template_cal_base(SRV_SMS_TEMPLATE_PRE_DEFINED) + 2;

        for (i = 0; i < SRV_SMS_TEMPLATE_PREDEFINED_NUM; i++)
        {
            if (ReadRecord(NVRAM_EF_SMS_PD_TEMPLATE_LID, (base + i), &data, SRV_SMS_TEMPLATE_RECORD_SIZE, &error) < 0)
            {
                data.content[0] = '\0';
            }
            else if (data.content[0] != '\0')
            {
                srv_sms_template_add_to_list(i, data.time);
            }
        }
    }
#endif /* __SRV_SMS_PREDEFINED_TEMPLATE__ */ 

#ifdef __SRV_SMS_USERDEFINED_TEMPLATE__
    if (ReadRecord(NVRAM_EF_SMS_UD_TMEPLATE_LID, 1, &data, SRV_SMS_TEMPLATE_RECORD_SIZE, &error) < 0)
    {
        data.content[0] = '\0';
    }
    if (data.content[0] != 'B')
    {
        if (!srv_sms_template_init_ud_to_nvram())
        {
            result = MMI_FALSE;
        }
    }
    else
    {
        U16 base = srv_sms_template_cal_base(SRV_SMS_TEMPLATE_USER_DEFINED) + 2;
    
        for (i = 0; i < SRV_SMS_TEMPLATE_USERDEFINED_NUM; i++)
        {
            if (ReadRecord(NVRAM_EF_SMS_UD_TMEPLATE_LID, (base + i), &data, SRV_SMS_TEMPLATE_RECORD_SIZE, &error) < 0)
            {
                data.content[0] = '\0';
            }
            else if (data.content[0] != '\0')
            {
                srv_sms_template_add_to_list(i+SRV_SMS_TEMPLATE_PREDEFINED_NUM, data.time);
            }
        }
    }
#endif /* __SRV_SMS_USERDEFINED_TEMPLATE__ */ 

    srv_sms_template_init_done = MMI_TRUE;

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static U16 srv_sms_template_cal_base(srv_sms_template_type_enum templ_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef _MUTILANG_TEMPLATE_
    U8 lang_offset = 0;
    U16 temp_base = 0;
#endif /* _MUTILANG_TEMPLATE_ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef _MUTILANG_TEMPLATE_
    if (strcmp((PS8)gLanguageArray[gCurrLangIndex].aLangSSC, SRV_SMS_TEMPLATE_LANGUAGE_SECOND) == 0)
    {
        lang_offset = (U8)SRV_SMS_TEMPLATE_LANGUAGE_SECOND_TYPE;
    }
    else if (strcmp((PS8)gLanguageArray[gCurrLangIndex].aLangSSC, SRV_SMS_TEMPLATE_LANGUAGE_THIRD) == 0)
    {
        lang_offset = (U8)SRV_SMS_TEMPLATE_LANGUAGE_THIRD_TYPE;
    }
    else
    {
        lang_offset = (U8)SRV_SMS_TEMPLATE_LANGUAGE_DEFAULT_TYPE;
    }

#ifdef __SRV_SMS_USERDEFINED_TEMPLATE__
    if (templ_type == SRV_SMS_TEMPLATE_USER_DEFINED)
    {
        temp_base = 0; //lang_offset * SRV_SMS_TEMPLATE_USERDEFINED_NUM;
    }
    else
#endif
    {
    #ifdef __SRV_SMS_PREDEFINED_TEMPLATE__
        temp_base = lang_offset * SRV_SMS_TEMPLATE_PREDEFINED_NUM;
    #endif
    }

    return temp_base;
#else /* _MUTILANG_TEMPLATE_ */ 
    return 0;
#endif /* _MUTILANG_TEMPLATE_ */ 
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_template_get_storge_location(U16 template_id, nvram_lid_enum *lid, U16 *record_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_PREDEFINED_TEMPLATE__
    if (template_id < SRV_SMS_TEMPLATE_PREDEFINED_NUM)
    {
        *lid = NVRAM_EF_SMS_PD_TEMPLATE_LID;
        *record_id = template_id + 
            2 + srv_sms_template_cal_base(SRV_SMS_TEMPLATE_PRE_DEFINED);
    }
    else
#endif
    {
    #ifdef __SRV_SMS_USERDEFINED_TEMPLATE__
        *lid = NVRAM_EF_SMS_UD_TMEPLATE_LID;
        *record_id = (template_id - SRV_SMS_TEMPLATE_PREDEFINED_NUM) +
            2 + srv_sms_template_cal_base(SRV_SMS_TEMPLATE_USER_DEFINED);
    #endif
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_template_get_unused_location(U16 *template_id, nvram_lid_enum *lid, U16 *record_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_USERDEFINED_TEMPLATE__
    if (srv_sms_template_ud_size  < SRV_SMS_TEMPLATE_USERDEFINED_NUM)
    {
        *lid = NVRAM_EF_SMS_UD_TMEPLATE_LID;

        for (i = 0; i< SRV_SMS_TEMPLATE_USERDEFINED_NUM; i++)
        {
            if (!((srv_sms_template_ud_exist_flag>>i)&0x01))
            {
                /*  1. The first record index of the LID is 1;
                 *  2. And the first record is used to as a mark to 
                 *     indicate the intialization status;
                 *  So, the record index of the first template is 2;
                 */
                *record_id = i + 1 + srv_sms_template_cal_base(SRV_SMS_TEMPLATE_USER_DEFINED) + 1;
                *template_id = i + SRV_SMS_TEMPLATE_PREDEFINED_NUM;
                result = MMI_TRUE;
                break;
            }
        }
    }
    else
#endif
    {
    #ifdef __SRV_SMS_PREDEFINED_TEMPLATE__
        if (srv_sms_template_pd_size < SRV_SMS_TEMPLATE_PREDEFINED_NUM)
        {
            *lid = NVRAM_EF_SMS_PD_TEMPLATE_LID;

            for (i = 0; i < SRV_SMS_TEMPLATE_PREDEFINED_NUM; i++)
            {
                if (!((srv_sms_template_pd_exist_flag>>i)&0x01))
                {
                    /*  1. The first record index of the LID is 1;
                     *  2. And the first record is used to as a mark to 
                     *     indicate the intialization status;
                     *  So, the record index of the first template is 2;
                     */
                    *record_id = i + 1 + srv_sms_template_cal_base(SRV_SMS_TEMPLATE_PRE_DEFINED) + 1;
                     *template_id = i;
                    result = MMI_TRUE;
                    break;
                }
            }
        }
    #endif
    }

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_sms_template_get_max_content_char_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return SRV_SMS_TEMPLATE_MAX_CHAR_NUM;
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_template_read(U16 template_id, WCHAR *content_buff, U16 content_buff_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    srv_sms_template_data_struct *data = OslMalloc(sizeof(srv_sms_template_data_struct));
    MMI_BOOL result = MMI_FALSE;
    nvram_lid_enum lid;
    U16 record_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(template_id < SRV_SMS_TEMPLATE_TOTAL_NUM);

    srv_sms_template_get_storge_location(template_id, &lid, &record_id);

    if (ReadRecord(lid, record_id, data, SRV_SMS_TEMPLATE_RECORD_SIZE, &error) < 0)
    {
        content_buff[0] = 0;
    }
    else
    {
        if (content_buff_size > SRV_SMS_TEMPLATE_RECORD_SIZE - sizeof(U32))
        {
            memcpy(content_buff, data->content, SRV_SMS_TEMPLATE_RECORD_SIZE- sizeof(U32));
        }
        else
        {
            memcpy(content_buff, data->content, content_buff_size);
            content_buff[content_buff_size/ENCODING_LENGTH -1] = '\0';
        }
        result = MMI_TRUE;
    }

    OslMfree(data);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
srv_sms_template_result srv_sms_template_save(const WCHAR *content, U16 content_buff_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    srv_sms_template_result result = SRV_SMS_TEMPLATE_RESULT_OK;
    srv_sms_template_data_struct data;
    nvram_lid_enum lid;
    U16 record_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((srv_sms_template_size == SRV_SMS_TEMPLATE_TOTAL_NUM)
        || (srv_sms_template_ud_size == SRV_SMS_TEMPLATE_USERDEFINED_NUM))
    {
        result = SRV_SMS_TEMPLATE_REACH_MAX_NUM;
    }
    else if (content[0] == '\0')
    {
        result = SRV_SMS_TEMPLATE_CONTENT_EMPTY;
    }
    else if (wcslen(content)> SRV_SMS_TEMPLATE_MAX_CHAR_NUM)
    {
        result = SRV_SMS_TEMPLATE_CONTENT_EXCEED;
    }
    else
    {   
        MYTIME local_time;
        U16 template_id;
        memset(&data, 0, SRV_SMS_TEMPLATE_RECORD_SIZE);
        wcscpy(data.content, content);

        DTGetRTCTime(&local_time);
        data.time = mmi_dt_mytime_2_utc_sec(&local_time, MMI_FALSE);

        srv_sms_template_get_unused_location(&template_id, &lid, &record_id);

        if (WriteRecord(lid, record_id, &data,
                SRV_SMS_TEMPLATE_RECORD_SIZE, &error) != SRV_SMS_TEMPLATE_RECORD_SIZE)
        {
            result = SRV_SMS_TEMPLATE_FAIL_UNKNOW;
        }

        if (result == SRV_SMS_TEMPLATE_RESULT_OK)
        {
            srv_sms_template_add_to_list(template_id, data.time);
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_delete_template
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_template_delete(U16 template_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (template_id >= SRV_SMS_TEMPLATE_TOTAL_NUM)
    {
        result = MMI_FALSE;
    }
    else
    {
        nvram_lid_enum lid;
        U16 record_id;
        srv_sms_template_data_struct data;

        memset(&data, 0, SRV_SMS_TEMPLATE_RECORD_SIZE);
        data.time = 0xFFFF;

        srv_sms_template_get_storge_location(template_id, &lid, &record_id);

        if (WriteRecord(lid, record_id, &data,
            SRV_SMS_TEMPLATE_RECORD_SIZE, &error) != SRV_SMS_TEMPLATE_RECORD_SIZE)
        {
            result = MMI_FALSE;
        }

        if (result)
        {
            srv_sms_template_delete_from_list(template_id);
        }
    }

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
srv_sms_template_result srv_sms_template_replace(U16 template_id, const WCHAR *content, U16 content_buff_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    srv_sms_template_result result = SRV_SMS_TEMPLATE_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (content[0] == '\0')
    {
        result = SRV_SMS_TEMPLATE_CONTENT_EMPTY;
    }
    else if (wcslen(content)> SRV_SMS_TEMPLATE_MAX_CHAR_NUM)
    {
        result = SRV_SMS_TEMPLATE_CONTENT_EXCEED;
    }
    else
    {
        srv_sms_template_data_struct data;
        MYTIME local_time;
        nvram_lid_enum lid;
        U16 record_id;

        memset(&data, 0, SRV_SMS_TEMPLATE_RECORD_SIZE);
        wcscpy(data.content, content);

        DTGetRTCTime(&local_time);
        data.time = mmi_dt_mytime_2_utc_sec(&local_time, MMI_FALSE);

        srv_sms_template_get_storge_location(template_id, &lid, &record_id);

        if (WriteRecord(lid, record_id, &data,
            SRV_SMS_TEMPLATE_RECORD_SIZE, &error) != SRV_SMS_TEMPLATE_RECORD_SIZE)
        {
            result = SRV_SMS_TEMPLATE_FAIL_UNKNOW;
        }

        if (result == SRV_SMS_TEMPLATE_RESULT_OK)
        {
            srv_sms_template_delete_from_list(template_id);

            srv_sms_template_add_to_list(template_id, data.time);
        }
    }

    return result;
}

#endif /* __SRV_SMS_TEMPLATE__ */
/*****************************************************************************
 * FUNCTION
 *  srv_sms_storage_type_to_protocol_mem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_sms_storage_type_to_protocol_mem(srv_sms_storage_enum storage_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 at_mem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (storage_type)
    {
        case SRV_SMS_STORAGE_ME:
            at_mem = SMSAL_ME;
            break;

        case SRV_SMS_STORAGE_SIM:
            at_mem = SMSAL_SM;
            break;

        case SRV_SMS_STORAGE_UNSPECIFIC:
        default:
            at_mem = SMSAL_MT;
            break;
    }

    return at_mem;
}


#ifdef __DM_LAWMO_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_delete_all_sms
 * DESCRIPTION
 *  Delete all sms 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_msg_delete_all_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_sms_is_sms_busy())
    {
        U16 type;
         srv_sms_sim_enum sim_id = SRV_SMS_SIM_1 | SRV_SMS_SIM_2;
       
        StopTimer(MESSAGES_SMS_BOOTUP_TIMER_ID); 
        type = SRV_SMS_BOX_INBOX | SRV_SMS_BOX_OUTBOX | SRV_SMS_BOX_DRAFTS | SRV_SMS_BOX_UNSENT;
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        type |= SRV_SMS_BOX_SIM;
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        type |= SRV_SMS_BOX_ARCHIVE;
#endif        
        srv_sms_delete_msg_list(
            type,
            sim_id,
            srv_msg_lawmo_delete_sms_data_cbk,
            NULL);
    }
    else
    {
        StartTimer(MESSAGES_SMS_BOOTUP_TIMER_ID, MESSAGES_SUBLCD_TIME_OUT, srv_msg_delete_all_sms);
    }
}
/*****************************************************************************
* FUNCTION
*  mmi_msg_lawmo_delete_sms_data_cbk
* DESCRIPTION
*  callback the result back to LAWMO
* PARAMETERS
*  callback_data
* RETURNS
*  void
*****************************************************************************/
static void srv_msg_lawmo_delete_sms_data_cbk(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wipe_cb(MMI_TRUE, "SMS");
}


/*****************************************************************************
* FUNCTION
*  mmi_msg_lawmo_delete_sms_data
* DESCRIPTION
*  called by LAWMO, will execute delete all sms data operation
* PARAMETERS
*  app_id, cmd
* RETURNS
*  void
*****************************************************************************/
mmi_ret srv_msg_lawmo_delete_sms_data(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dm_lawmo_wipe_ind_evt_struct* lawmo_lock_ind = (srv_dm_lawmo_wipe_ind_evt_struct*)evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wipe_cb = lawmo_lock_ind->cb;
    if (srv_sms_is_sms_busy())
    {
        StartTimer(MESSAGES_SMS_BOOTUP_TIMER_ID, MESSAGES_SUBLCD_TIME_OUT, srv_msg_delete_all_sms);
    }
    else
    {
       srv_msg_delete_all_sms();
    }
    return MMI_RET_OK;
}


#ifdef __SRV_SMS_BACKGROUND_SEND_SUPPORT__
/*****************************************************************************
* FUNCTION
*  mmi_msg_lawmo_cancel_bg_send
* DESCRIPTION
*  called by LAWMO, will execute cancel backgroud send
* PARAMETERS
*  app_id, cmd
* RETURNS
*  void
*****************************************************************************/
mmi_ret srv_msg_lawmo_cancel_bg_send(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_list_size;
    U16 index;
    U16 msg_id;
    srv_dm_lawmo_lock_ind_evt_struct* lawmo_lock_ind = (srv_dm_lawmo_lock_ind_evt_struct*)evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_is_sms_ready() && srv_sms_is_sms_valid())
    {
        srv_sms_send_status_enum send_status;

        msg_list_size = srv_sms_get_list_size(SRV_SMS_BOX_UNSENT);
                
        for (index = 0; index < msg_list_size; index++)
        {
            msg_id = srv_sms_get_msg_id(SRV_SMS_BOX_UNSENT, index);
            send_status = srv_sms_get_unsent_msg_status(msg_id);

            if ((send_status == SRV_SMS_SEND_SENDING) || (send_status == SRV_SMS_SEND_WAITING))
            {
                srv_sms_set_unsent_msg_status(msg_id, SRV_SMS_SEND_FAIL);
            }
        }
    }

    (*lawmo_lock_ind->cb)(MMI_TRUE, "SMS");
    return MMI_RET_OK;
}
#endif /* __SRV_SMS_BACKGROUND_SEND_SUPPORT__ */

#endif /* __DM_LAWMO_SUPPORT__ */

#endif /* __MOD_SMSAL__ */

