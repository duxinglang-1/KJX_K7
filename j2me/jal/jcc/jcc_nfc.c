/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
* permission of MediaTek Inc. (C) 2005
*
* BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
* THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
* RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
* AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
* NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
* SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
* SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
* THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
* NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
* SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
* BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
* LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
* AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
* OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
* MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
* THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
* WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
* LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
* RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
* THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * jcc_nfc.c
 *
 * Project:
 * --------
 *  MAUI
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
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef SUPPORT_JSR_257
/*************************************************************************
 * Include Statements
 *************************************************************************/
#include "kal_release.h"
#include "jvm_mem.h"
#include "jcc_internal.h"
#include "jcc_interface.h"
#include "jpush_interface.h"
#include "jam_mvm_manager.h"
#include "common_event.h"
#include "nfc_service.h"
#include "phNfcStatus.h"
#include "mtk_nfc_ext_msg.h"

#define JCC_NFC_LOCKER_FLAG_ISLOCK_TRUE	    (1)
#define JCC_NFC_LOCKER_FLAG_ISLOCK_FALSE    (0)

#define JCC_NFC_STATUS_COMMAND_IGNORE       (77774)

/* Tag TYPE */
#define		APP_NDEF_TYPE1				(1)
#define		APP_NDEF_TYPE2				(2)
#define		APP_NDEF_TYPE3				(3)
#define		APP_NDEF_TYPE4				(4)
#define		APP_NDEF_MIFARE				(5)
#define		APP_TAG_TYPE_A              (6)
#define		APP_TAG_TYPE_B  			(7)
#define		APP_TAG_FELICA				(8)
#define		APP_TAG_JEWEL				(9)
#define		APP_TAG_MIFARE_1K			(10)
#define		APP_TAG_MIFARE_UL			(11)
#define	    APP_TAG_MIFARE_DESFIRE		(12)
#define		APP_TAG_NON_NDEF			(13)
#define		APP_TAG_15693   			(14)

static char jcc_nfc_mapping_Generic[] = {"Generic"};
static char jcc_nfc_mapping_ISO14443A[] = {"ISO14443-4A"};
static char jcc_nfc_mapping_Mifare[] = {"MIFARE"};
static char jcc_nfc_mapping_Mifare_1K[] = {"MIFARE-1K"};
static char jcc_nfc_mapping_Mifare_4K[] = {"MIFARE-4K"};
static char jcc_nfc_mapping_Mifare_UL[] = {"MIFARE-UL"};
static char jcc_nfc_mapping_ISO14443B[] = {"ISO14443-4B"};
static char jcc_nfc_mapping_ISO14443BP[] = {"ISO14443-4B\'"};
static char jcc_nfc_mapping_Felica[] = {"Felica"};
static char jcc_nfc_mapping_Jewel[] = {"Jewel"};
static char jcc_nfc_mapping_NFCIP[] = {"NFCIP-1"};
static char jcc_nfc_mapping_RFID[] = {"RFID"};
static char jcc_nfc_mapping_ISO15693[] = {"ISO15693"};
static char jcc_nfc_mapping_Unknown[] = {"Unknown"};

static jcc_nfc_registry_counter jcc_nfc_tag_registered_number;

static kal_bool jcc_nfc_notify_flag = KAL_FALSE;
static kal_bool jcc_nfc_used_flag = KAL_FALSE;

static kal_int32 jcc_nfc_device_state = JCC_NFC_DEVICE_INIT;
static jcc_nfc_device_status_struct jcc_nfc_status = {0, 0 , 0 , 0};
static kal_bool jcc_nfc_is_target_detected = KAL_FALSE;
static kal_bool jcc_nfc_is_vm_connected = KAL_FALSE;

kal_int32 jcc_nfc_check_presence_count;

kal_uint8 *jcc_nfc_transceive_write_buffer;
kal_uint8 *jcc_nfc_transceive_read_buffer;
kal_uint32 jcc_nfc_transceive_read_buffer_length = 0;

jcc_nfc_target_context jcc_nfc_current_target_context;
extern kal_mutexid g_jam_nfc_mutex;
extern kal_semid g_jam_nfc_sem;

static jcc_nfc_task_management jcc_nfc_task_manager;

static phLibNfc_Registry_Info_t *jcc_nfc_register_info;

static uint8_t jcc_nfc_se_count = PHLIBNFC_MAXNO_OF_SE;
static phLibNfc_SE_List_t jcc_nfc_se_list[PHLIBNFC_MAXNO_OF_SE];

static kal_bool jcc_nfc_terminate_vm = KAL_FALSE;

static kal_bool jcc_nfc_is_open_se_mode = KAL_FALSE;

static kal_bool jcc_nfc_is_reinit_driver = KAL_FALSE;

static kal_bool jcc_nfc_is_initialized = KAL_FALSE;

static kal_bool jcc_nfc_is_processing = KAL_FALSE;

static void *jcc_nfc_push_tm_context = NULL;

void jcc_nfc_tag_register(jcc_nfc_task_message_context *tmContext);
void jcc_nfc_se_register(int lockHandler);
void jcc_nfc_se_unregister_internal(void);

#ifdef SUPPORT_JSR_257_PUSH
extern void *push_process_recvd_nfc_ind(char *url);
#endif

/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_task_manager_init
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void jcc_nfc_task_manager_init()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jcc_nfc_task_manager.next = 0;
    jcc_nfc_task_manager.last = 0;
    jcc_nfc_task_manager.size = 0;
    jcc_nfc_task_manager.task_mutex = kal_create_mutex("TaskManager");

    memset((void *)(jcc_nfc_task_manager.items), 0, sizeof(jcc_nfc_task_management_item) * MAX_MANAGE_ITEM_SIZE);
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_task_manager_deinit
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void jcc_nfc_task_manager_deinit()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jcc_nfc_task_manager.next = 0;
    jcc_nfc_task_manager.last = 0;
    jcc_nfc_task_manager.size = 0;
    // kal_destory_mutex("TaskManager",jcc_nfc_task_manager.task_mutex);

    memset((void *)(jcc_nfc_task_manager.items), 0, sizeof(jcc_nfc_task_management_item) * MAX_MANAGE_ITEM_SIZE);
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_task_manager_set_unlock
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void jcc_nfc_task_manager_set_unlock(int type, int handle, int status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int cursor = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jcc_nfc_terminate_vm && type == JCC_NFC_TYPE_CLEANUP_TARGET)
    {
        jcc_nfc_deinit();
        jcc_nfc_terminate_vm = KAL_FALSE;
    }

    if (handle > MAX_MANAGE_ITEM_SIZE || handle < 1)
    {
        jvm_trace_debug("[JSR257]jcc_nfc_task_manager_set_unlock: %d,handle is invalid,handle = %d,type= %d\n", __LINE__, handle, type);
        return;
    }

    cursor = handle - 1;
    if (jcc_nfc_task_manager.items[cursor].functionType != type)
    {
        jvm_trace_debug("[JSR257]jcc_nfc_task_manager_set_unlock: %d,type is invalid,handle = %d,type= %d\n", __LINE__, handle, type);
        return;
    }

    jcc_nfc_task_manager.items[cursor].isLock = JCC_NFC_LOCKER_FLAG_ISLOCK_FALSE;
    jcc_nfc_task_manager.items[cursor].status = status;
    jvm_trace_debug("[JSR257]jcc_nfc_task_manager_set_unlock: %d,lock is OFF,handle = %d,type = %d\n,status = %d", __LINE__, handle, type, status);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_task_manager_get_lock
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static int jcc_nfc_task_manager_get_lock(int type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int counter = 0;
    int tempID = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_task_manager_get_lock: %d,type = %d\n", __LINE__, type);

    if (type == 0)
    {
        return 0;
    }

    kal_take_mutex(jcc_nfc_task_manager.task_mutex);

    // Search available manager ID
    for (counter = 0;counter < MAX_MANAGE_ITEM_SIZE;counter++)
    {
        tempID = jcc_nfc_task_manager.next;
        if (jcc_nfc_task_manager.items[tempID].functionType == 0)
        {
            jcc_nfc_task_manager.items[tempID].functionType = type;
            jcc_nfc_task_manager.items[tempID].isLock = JCC_NFC_LOCKER_FLAG_ISLOCK_TRUE;
            jcc_nfc_task_manager.next = (jcc_nfc_task_manager.next + 1) % MAX_MANAGE_ITEM_SIZE;
            kal_give_mutex(jcc_nfc_task_manager.task_mutex);

            jvm_trace_debug("[JSR257]jcc_nfc_task_manager_get_lock: %d,type = %d,handle = %d\n", __LINE__, type, tempID + 1);
            return tempID + 1;
        }

        jcc_nfc_task_manager.next = (jcc_nfc_task_manager.next + 1) % MAX_MANAGE_ITEM_SIZE;
    }

    kal_give_mutex(jcc_nfc_task_manager.task_mutex);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_task_manager_check_lock
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static int jcc_nfc_task_manager_check_lock(int type, int handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int cursor = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle > MAX_MANAGE_ITEM_SIZE || handle < 1)
    {
        jvm_trace_debug("[JSR257]jcc_nfc_task_manager_check_lock: %d,handle is invalid,handle = %d,type= %d\n", __LINE__, handle, type);
        return TASK_MANAGER_CHECK_ERROR;
    }

    cursor = handle - 1;
    if (jcc_nfc_task_manager.items[cursor].functionType != type)
    {
        jvm_trace_debug("[JSR257]jcc_nfc_task_manager_check_lock: %d,type is invalid,handle = %d,type= %d\n", __LINE__, handle, type);
        return TASK_MANAGER_CHECK_ERROR;
    }

    if (jcc_nfc_task_manager.items[cursor].isLock == JCC_NFC_LOCKER_FLAG_ISLOCK_TRUE)
    {
        jvm_trace_debug("[JSR257]jcc_nfc_task_manager_check_lock: %d,lock is ON,handle = %d,type = %d\n", __LINE__, handle, type);
        return TASK_MANAGER_CHECK_LOCK;
    }

    return TASK_MANAGER_CHECK_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_task_manager_get_status
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static int jcc_nfc_task_manager_get_status(int type, int handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int cursor = 0;
    int status = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle > MAX_MANAGE_ITEM_SIZE || handle < 1)
    {
        jvm_trace_debug("[JSR257]jcc_nfc_task_manager_get_status: %d,handle is invalid,handle = %d,type= %d\n", __LINE__, handle, type);
        return TASK_MANAGER_CHECK_ERROR;
    }

    cursor = handle - 1;
    if (jcc_nfc_task_manager.items[cursor].functionType != type)
    {
        jvm_trace_debug("[JSR257]jcc_nfc_task_manager_get_status: %d,type is invalid,handle = %d,type= %d\n", __LINE__, handle, type);
        return TASK_MANAGER_CHECK_ERROR;
    }

    if (jcc_nfc_task_manager.items[cursor].isLock == 1)
    {
        jvm_trace_debug("[JSR257]jcc_nfc_task_manager_get_status: %d,lock is ON,handle = %d,type = %d\n", __LINE__, handle, type);
        return TASK_MANAGER_CHECK_ERROR;
    }

    // get status
    status = jcc_nfc_task_manager.items[cursor].status;

    // empty the block
    memset((void *)(&(jcc_nfc_task_manager.items[cursor])), 0, sizeof(jcc_nfc_task_management_item));
    jvm_trace_debug("[JSR257]jcc_nfc_task_manager_get_status: %d,lock is OFF,handle = %d,type = %d,status = %d\n", __LINE__, handle, type, status);

    return status;
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_sync_lock
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void jcc_nfc_sync_lock()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(g_jam_nfc_mutex);
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_sync_unlock
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void jcc_nfc_sync_unlock()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_give_mutex(g_jam_nfc_mutex);
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_async_lock
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void jcc_nfc_async_lock()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_sem(g_jam_nfc_sem, KAL_INFINITE_WAIT);
    jcc_nfc_is_processing = KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_async_unlock
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void jcc_nfc_async_unlock()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_give_sem(g_jam_nfc_sem);
    jcc_nfc_is_processing = KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_dummy_callback_handler
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static NFCSTATUS jcc_nfc_dummy_callback_handler(void *context, NFCSTATUS status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_dummy_callback_handler() MUST NOT BE CALLED, %d, ", __LINE__);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_get_discovery_config
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void jcc_nfc_get_discovery_config(phLibNfc_sADD_Cfg_t *p, kal_bool SERegistered,
        kal_uint32 PlainRegistered, kal_uint32 ISORegistered, kal_uint32 NDEFRegistered)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phLibNfc_sADD_Cfg_t *sADDConfig = p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* TODO: Discovery Optimization */
    sADDConfig->PollDevInfo.PollEnabled = 1;
    sADDConfig->PollDevInfo.PollCfgInfo.EnableIso14443A = TRUE;
    sADDConfig->PollDevInfo.PollCfgInfo.EnableIso14443B = TRUE;
    sADDConfig->PollDevInfo.PollCfgInfo.EnableFelica212 = TRUE;
    sADDConfig->PollDevInfo.PollCfgInfo.EnableFelica424 = TRUE;
    sADDConfig->PollDevInfo.PollCfgInfo.EnableIso15693 = TRUE;
    sADDConfig->PollDevInfo.PollCfgInfo.EnableNfcActive = FALSE;
    sADDConfig->PollDevInfo.PollCfgInfo.DisableCardEmulation = FALSE;
    sADDConfig->Duration = 0x7A120;
    sADDConfig->NfcIP_Mode = phNfc_eInvalidP2PMode;
    sADDConfig->NfcIP_Tgt_Disable = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_get_registry_info
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void jcc_nfc_get_registry_info(phLibNfc_Registry_Info_t *p, kal_uint32 PlainRegistered,
                                      kal_uint32 ISORegistered, kal_uint32 NDEFRegistered)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phLibNfc_Registry_Info_t *reginfo = p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    reginfo->MifareUL = TRUE;
    reginfo->MifareStd = TRUE;
    reginfo->ISO14443_4A = TRUE;
    reginfo->ISO14443_4B = TRUE;
    reginfo->ISO15693 = TRUE;
    reginfo->Jewel = TRUE;
    reginfo->NFC = FALSE;
    reginfo->Felica = TRUE;


    if (NDEFRegistered == 0)
    {
        if (PlainRegistered == 0)
        {
            reginfo->MifareUL = FALSE;
            reginfo->MifareStd = FALSE;
            reginfo->ISO15693 = FALSE;
            reginfo->Jewel = FALSE;
            reginfo->Felica = FALSE;
        }
        if (ISORegistered == 0)
        {
            reginfo->ISO14443_4A = FALSE;
            reginfo->ISO14443_4B = FALSE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_send_message
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_send_message(kal_uint16 msg_id, module_type dest_mod_id, sap_type sap_id, void *p_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type self_mod_id;

    ilm_struct *ilm_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    self_mod_id = kal_get_active_module_id();

    if (self_mod_id == MOD_JAM)
    {
        self_mod_id = MOD_JASYN_D;
    }

    ilm_ptr = (ilm_struct *) allocate_ilm(self_mod_id);

    ASSERT(ilm_ptr);

    ilm_ptr->msg_id = msg_id;

    ilm_ptr->dest_mod_id = dest_mod_id;

    ilm_ptr->src_mod_id = self_mod_id;

    ilm_ptr->sap_id = sap_id;

    ilm_ptr->local_para_ptr = p_msg;

    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_send_message_with_mod_id
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_send_message_with_mod_id(module_type mod_id, kal_uint16 msg_id, module_type dest_mod_id, sap_type sap_id, void *p_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = (ilm_struct *) allocate_ilm(mod_id);

    ASSERT(ilm_ptr);


    ilm_ptr->msg_id = msg_id;

    ilm_ptr->dest_mod_id = dest_mod_id;

    ilm_ptr->src_mod_id = mod_id;

    ilm_ptr->sap_id = sap_id;

    ilm_ptr->local_para_ptr = p_msg;

    ilm_ptr->peer_buff_ptr = NULL;

    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_clear
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
void jcc_nfc_clear(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jcc_nfc_device_state != JCC_NFC_DEVICE_INIT)
    {
        jcc_nfc_tag_registered_number.SERegistered = jcc_nfc_tag_registered_number.PushSERegistered;
        jcc_nfc_tag_registered_number.PlainRegistered = 0;
        jcc_nfc_tag_registered_number.ISORegistered = 0;
        jcc_nfc_tag_registered_number.NDEFRegistered = jcc_nfc_tag_registered_number.PushNDEFRegistered;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_mvm_initialize
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
kal_int32 jcc_nfc_mvm_initialize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jcc_nfc_terminate_vm = KAL_FALSE;
    return J2ME_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_mvm_finalize
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
kal_int32 jcc_nfc_mvm_finalize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jcc_nfc_device_state != JCC_NFC_DEVICE_INIT)
    {
        jcc_nfc_terminate_vm = KAL_TRUE;
        jcc_nfc_tag_registered_number.SERegistered = jcc_nfc_tag_registered_number.PushSERegistered;
        jcc_nfc_tag_registered_number.PlainRegistered = 0;
        jcc_nfc_tag_registered_number.ISORegistered = 0;
        jcc_nfc_tag_registered_number.NDEFRegistered = jcc_nfc_tag_registered_number.PushNDEFRegistered;
        jcc_nfc_reset(0);
    }
    return J2ME_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_init
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
jcc_nfc_result_enum jcc_nfc_init()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //jcc_nfc_result_enum status;
    //nfcfri_params_t *pParams;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_init: %d, Initial the locker pool.\n", __LINE__);
    jcc_nfc_task_manager_init();

    /*if(jcc_nfc_tag_registered_number != NULL)
    {
         // return JCC_NFC_OK;
         jvm_trace_debug("[JSR257]jcc_nfc_init: %d, RENEW AGAIN \n", __LINE__);
    }*/

    jvm_trace_debug("[JSR257]jcc_nfc_init: %d, Initial the driver,begin:\n", __LINE__);
    //jcc_nfc_tag_registered_number = jvm_malloc(sizeof(jcc_nfc_registry_counter));
    jcc_nfc_tag_registered_number.SERegistered = 0;
    jcc_nfc_tag_registered_number.PushSERegistered = 0;
    jcc_nfc_tag_registered_number.PlainRegistered = 0;
    jcc_nfc_tag_registered_number.ISORegistered = 0;
    jcc_nfc_tag_registered_number.NDEFRegistered = 0;
    jcc_nfc_tag_registered_number.PushNDEFRegistered = 0;
    jvm_trace_debug("[JSR257]jcc_nfc_init: %d, Initial the driver,end:\n", __LINE__);

    //jcc_nfc_current_target_context =(jcc_nfc_target_context *)jvm_malloc(sizeof(jcc_nfc_target_context));

    jvm_trace_debug("[JSR257]jcc_nfc_init: %d, Initial the jcc_nfc_tag_registered_number counter.\n", __LINE__);

    //jcc_nfc_send_message(MSG_ID_NFC_LIB_INIT, MOD_NFC, INVALID_SAP, NULL);

    jcc_nfc_current_target_context.ndef_message = NULL;

    return JCC_NFC_BLOCK;
}



/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_deinit
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
jcc_nfc_result_enum jcc_nfc_deinit()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jcc_nfc_result_enum status;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return JCC_NFC_BLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_driver_init_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_driver_init_callback(ilm_struct *pData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_init_deinit_rsp_struct *nfc_ind_ptr = (nfc_init_deinit_rsp_struct*) pData->local_para_ptr;
    jcc_nfc_task_message_context *tmContext = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_driver_init_callback, result=%d\n", nfc_ind_ptr->action_result);
    if (nfc_ind_ptr->action_result == 1/* && jcc_nfc_tag_registered_number*/)
    {
        jcc_nfc_is_initialized = KAL_TRUE;

        if (jcc_nfc_tag_registered_number.NDEFRegistered > 0 ||
                jcc_nfc_tag_registered_number.PlainRegistered > 0 ||
                jcc_nfc_tag_registered_number.ISORegistered > 0)
        {
            jvm_trace_debug("[JSR257]jcc_nfc_driver_init_callback, register tag\n");
            tmContext = get_ctrl_buffer(sizeof(jcc_nfc_task_message_context));
            tmContext->context = &jcc_nfc_tag_registered_number;
            tmContext->handle = 0;
            tmContext->cmd = JCC_NFC_STATE_REINIT;
            jcc_nfc_async_lock();
            jcc_nfc_tag_register(tmContext);
        }
        else if (jcc_nfc_tag_registered_number.SERegistered > 0)
        {
            jvm_trace_debug("[JSR257]jcc_nfc_driver_init_callback, register se\n");
            jcc_nfc_se_register(0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_driver_deinit_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_driver_deinit_callback(ilm_struct *pData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jcc_nfc_device_state = JCC_NFC_DEVICE_INVALID;
    jcc_nfc_is_initialized = KAL_FALSE;

    jcc_nfc_sync_lock();
    jcc_nfc_status.realConnected = 0;
    jcc_nfc_status.realRegistered = 0;
    jcc_nfc_sync_unlock();

    if (jcc_nfc_is_reinit_driver)
    {
        jcc_nfc_is_reinit_driver = KAL_FALSE;
        jcc_nfc_send_message_with_mod_id(MOD_J2ME_D, MSG_ID_NFC_LIB_INIT_REQ, MOD_NFC, INVALID_SAP, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_driver_reinit
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_driver_reinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jcc_nfc_is_reinit_driver = KAL_TRUE;
    jcc_nfc_send_message_with_mod_id(MOD_J2ME_D, MSG_ID_NFC_LIB_DEINIT_REQ, MOD_NFC, INVALID_SAP, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_check_presence_internal
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_check_presence_internal(jcc_nfc_task_message_context *tmContext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_remote_dev_check_presence_req_struct *p_msg = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_msg = (nfc_remote_dev_check_presence_req_struct *) construct_local_para(sizeof(nfc_remote_dev_check_presence_req_struct), TD_CTRL);

    p_msg->REQhRemoteDevice = jcc_nfc_current_target_context.Target_Handle;
    p_msg->REQpPresenceChk_RspCb = (pphLibNfc_RspCb_t)jcc_nfc_dummy_callback_handler;
    p_msg->REQpContext = (void *)tmContext;

    jvm_trace_debug("[JSR257]jcc_nfc_check_presence_internal: %d, jcc_nfc_send_message(MSG_ID_NFC_REMOTE_DEV_CHECK_PRESENCE_REQ, MOD_NFC, INVALID_SAP, NULL)\n", __LINE__);
    if (kal_get_active_module_id() != MOD_JAM)
    {
        jcc_nfc_send_message(MSG_ID_NFC_REMOTE_DEV_CHECK_PRESENCE_REQ, MOD_NFC, INVALID_SAP, (void *)p_msg);
    }
    else
    {
        jcc_nfc_send_message_with_mod_id(MOD_JASYN_D, MSG_ID_NFC_REMOTE_DEV_CHECK_PRESENCE_REQ, MOD_NFC, INVALID_SAP, (void *)p_msg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_check_presence
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jcc_nfc_check_presence(int lockHandler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jcc_nfc_task_message_context *tmContext = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_check_presence: %d, lockHandler = %d, status = %d\n", __LINE__, lockHandler, (int)jcc_nfc_current_target_context.Status);

    if (jcc_nfc_current_target_context.Status == 13 || jcc_nfc_is_processing)
    {
        return KAL_FALSE;
    }

    if (jcc_nfc_is_reinit_driver)
    {
        jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_CHECK_PRESENCE, lockHandler, JCC_NFC_STATUS_COMMAND_IGNORE);
    }
    else
    {
        tmContext = (jcc_nfc_task_message_context *)get_ctrl_buffer(sizeof(jcc_nfc_task_message_context));
        tmContext->handle = lockHandler;
        tmContext->cmd = 0;

        jcc_nfc_async_lock();
        jcc_nfc_check_presence_internal(tmContext);
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_release
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_release(kal_int32 lockHandler)
{

}

/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_clean_up
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jcc_nfc_clean_up(kal_int32 lockHandler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int enableToCleanup = 0;
    jcc_nfc_task_message_context *tmContext = NULL;
    nfc_remote_dev_check_presence_req_struct *rc_msg = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_clean_up: %d, lockHandler = %d\n", __LINE__, lockHandler);

    if (jcc_nfc_is_processing)
    {
        return KAL_FALSE;
    }

    jcc_nfc_sync_lock();

    if (jcc_nfc_status.realRegistered = 1)
    {
        enableToCleanup = 1;
    }

    jcc_nfc_sync_unlock();
    if (enableToCleanup == 1)
    {
        tmContext = (jcc_nfc_task_message_context *)get_ctrl_buffer(sizeof(jcc_nfc_task_message_context));
        tmContext->handle = lockHandler;
        tmContext->cmd = JCC_NFC_STATE_CLEAN_UP;

        jcc_nfc_async_lock();
        jcc_nfc_check_presence_internal(tmContext);
    }
    else
    {
        jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_CLEANUP_TARGET, lockHandler, JCC_NFC_STATUS_COMMAND_IGNORE);
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_reset_internal
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_reset_internal(void *context)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_remote_dev_check_presence_req_struct *p_msg = NULL;
    jcc_nfc_task_message_context *tmContext = (jcc_nfc_task_message_context *)context;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_msg = (nfc_remote_dev_check_presence_req_struct *) construct_local_para(sizeof(nfc_remote_dev_check_presence_req_struct), TD_CTRL);

    p_msg->REQhRemoteDevice = jcc_nfc_current_target_context.Target_Handle;
    p_msg->REQpPresenceChk_RspCb = (pphLibNfc_RspCb_t)jcc_nfc_dummy_callback_handler;
    p_msg->REQpContext = (void *)tmContext;;

    jvm_trace_debug("[JSR257]jcc_nfc_reset_internal: %d, jcc_nfc_send_message(MSG_ID_NFC_REMOTE_DEV_CHECK_PRESENCE_REQ, MOD_NFC, INVALID_SAP, NULL)\n", __LINE__);
    jcc_nfc_send_message(MSG_ID_NFC_REMOTE_DEV_CHECK_PRESENCE_REQ, MOD_NFC, INVALID_SAP, (void *)p_msg);
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_reset
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jcc_nfc_reset(int lockHandler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int enableToReset = 0;
    jcc_nfc_task_message_context *tmContext = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_reset, %d\n", __LINE__);

    if (jcc_nfc_is_processing)
    {
        return KAL_FALSE;
    }

    if (jcc_nfc_status.realRegistered = 1)
    {
        enableToReset = 1;
    }

    //jcc_nfc_sync_unlock();
    if (enableToReset == 1)
    {
        jvm_trace_debug("[JSR257]jcc_nfc_reset, %d, enableToReset == 1\n", __LINE__);
        jcc_nfc_async_lock();
        tmContext = (jcc_nfc_task_message_context *)get_ctrl_buffer(sizeof(jcc_nfc_task_message_context));
        tmContext->handle = lockHandler;
        tmContext->cmd = JCC_NFC_STATE_RESET;

        jcc_nfc_device_state = JCC_NFC_DEVICE_DETECT_TARGET;
        jcc_nfc_reset_internal(tmContext);
    }
    else
    {
        jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_RESET_TARGET, lockHandler, JCC_NFC_STATUS_COMMAND_IGNORE);
        if (jcc_nfc_terminate_vm)
        {
            if (jcc_nfc_tag_registered_number.SERegistered == 0)
            {
                jcc_nfc_se_unregister_internal();
            }
            jcc_nfc_terminate_vm = KAL_FALSE;
        }
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_se_register
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_se_register(int lockHandler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_se_get_secure_element_list_req_struct *p_msg; // send GetSucureElementList
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_se_register, %d\n", __LINE__);

    p_msg = (nfc_se_get_secure_element_list_req_struct *) construct_local_para(sizeof(nfc_se_get_secure_element_list_req_struct), TD_CTRL);
    ASSERT(p_msg);// judge whether MALLOC is success

    p_msg->uSE_count = &jcc_nfc_se_count;
    p_msg->pSE_List = jcc_nfc_se_list;

    if (p_msg->uSE_count != 0)
    {
        int i;
        int len = *(p_msg->uSE_count);
        jvm_trace_debug("[JSR257]jcc_nfc_se_register, %d, p_msg->REQuSE_count = %d \n", __LINE__, *(p_msg->uSE_count));
        for (i = 0; i < len; i++)
        {
            jvm_trace_debug("[JSR257]jcc_nfc_se_register, %d, p_msg->REQpSE_List[%d] = 0x%08X \n", __LINE__, i, p_msg->pSE_List[i]);
            jvm_trace_debug("[JSR257]jcc_nfc_se_register, %d, p_msg->REQpSE_List[%d].hSecureElement = 0x%08X \n", __LINE__, i, p_msg->pSE_List[i].hSecureElement);
        }
    }

    jvm_trace_debug("[JSR257]jcc_nfc_se_register, %d, lockHandler = %d.\n", __LINE__, lockHandler);
    jvm_trace_debug("[JSR257]jcc_nfc_se_register, %d, jcc_nfc_send_message(MSG_ID_NFC_SE_GET_SECURE_ELEMENT_LIST_REQ)\n", __LINE__);
    jcc_nfc_async_lock();
    jcc_nfc_send_message(MSG_ID_NFC_SE_GET_SECURE_ELEMENT_LIST_REQ, MOD_NFC, INVALID_SAP, (void *)p_msg);

    jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_REGISTER_TARGET, lockHandler, JCC_NFC_STATUS_COMMAND_IGNORE);
    jvm_trace_debug("[JSR257]jcc_nfc_se_register: %d,[UNBLOCK] = %d\n", __LINE__, lockHandler);
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_tag_register
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_tag_register(jcc_nfc_task_message_context *tmContext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_remote_dev_ntf_register_req_struct *p_msg; // send registry MSG
    phLibNfc_Registry_Info_t *ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_tag_register: %d,prepare to sending the message of register to normal target\n", __LINE__);

    if (jcc_nfc_tag_registered_number.PlainRegistered == 0 &&
            jcc_nfc_tag_registered_number.ISORegistered == 0 &&
            jcc_nfc_tag_registered_number.NDEFRegistered == 0)
    {
        if (tmContext->cmd == JCC_NFC_STATE_RESET || tmContext->cmd == JCC_NFC_STATE_CONNECT_WITH_CHECKING_NDEF)
        {
            jcc_nfc_async_unlock();
            jcc_nfc_sync_lock();
            jcc_nfc_status.realRegistered = 0;
            jcc_nfc_sync_unlock();
            if (tmContext->cmd == JCC_NFC_STATE_RESET)
            {
                jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_RESET_TARGET, tmContext->handle, JCC_NFC_STATUS_COMMAND_IGNORE);
                if (jcc_nfc_terminate_vm)
                {
                    if (jcc_nfc_tag_registered_number.SERegistered == 0)
                    {
                        jcc_nfc_se_unregister_internal();
                    }
                    jcc_nfc_terminate_vm = KAL_FALSE;
                }
            }
            else if (tmContext->cmd == JCC_NFC_STATE_CONNECT_WITH_CHECKING_NDEF)
            {
                jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_CONNECT_TARGET, tmContext->handle, JCC_NFC_STATUS_COMMAND_IGNORE);
            }
            if (tmContext)
            {
                free_ctrl_buffer(tmContext);
            }
            return;
        }
    }

    p_msg = (nfc_remote_dev_ntf_register_req_struct *) construct_local_para(sizeof(nfc_remote_dev_ntf_register_req_struct), TD_CTRL);
    ASSERT(p_msg);

    jcc_nfc_register_info = (phLibNfc_Registry_Info_t*)get_ctrl_buffer(sizeof(phLibNfc_Registry_Info_t));

    p_msg->REQpRegistryInfo = jcc_nfc_register_info;
    ptr = (phLibNfc_Registry_Info_t*) p_msg->REQpRegistryInfo;
    jcc_nfc_get_registry_info(ptr,
                              jcc_nfc_tag_registered_number.PlainRegistered,
                              jcc_nfc_tag_registered_number.ISORegistered,
                              jcc_nfc_tag_registered_number.NDEFRegistered);

    // Configure flag MifareUL/MifareStd/ISO14443_4A/ISO14443_4B/ISO15693/Felica/NFC/Jewel

    jvm_trace_debug("[JSR257]jcc_nfc_tag_register: %d, (UL,M1,4A,4B,15693,Felica,NFC,Jewel) = (%d,%d,%d,%d,%d,%d,%d,%d) \n", __LINE__
                    , ptr->MifareUL
                    , ptr->MifareStd
                    , ptr->ISO14443_4A
                    , ptr->ISO14443_4B
                    , ptr->ISO15693
                    , ptr->Felica
                    , ptr->NFC
                    , ptr->Jewel);

    p_msg->REQpContext = tmContext;

    jvm_trace_debug("[JSR257]jcc_nfc_tag_register: %d, p_msg->REQpNotificationHandler = Register_RspCb_NotificationHandler\n", __LINE__);
    p_msg->REQpNotificationHandler = (phLibNfc_NtfRegister_RspCb_t )jcc_nfc_dummy_callback_handler;

    jcc_nfc_device_state = JCC_NFC_DEVICE_DETECT_TARGET;
    jcc_nfc_is_target_detected = KAL_FALSE;

    jvm_trace_debug("[JSR257]jcc_nfc_tag_register: %d, jcc_nfc_send_message(MSG_ID_NFC_REMOTE_DEV_NTF_REGISTER_REQ(%d))\n", __LINE__, MSG_ID_NFC_REMOTE_DEV_NTF_REGISTER_REQ);
    jcc_nfc_send_message(MSG_ID_NFC_REMOTE_DEV_NTF_REGISTER_REQ, MOD_NFC, INVALID_SAP, (void *)p_msg);

}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_register
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
jcc_nfc_result_enum jcc_nfc_register(
    jcc_nfc_target_type_enum target,
    void **context,
    kal_int32 lockerHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 mustRegistered = 0;
    jcc_nfc_task_message_context *tmContext = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_register: %d\n", __LINE__);

    /*if (jcc_nfc_tag_registered_number == NULL)
    {
    	return JCC_NFC_FAIL;
    }*/

    jvm_trace_debug("[JSR257]jcc_nfc_register: %d, lockerHandle = %d,target = %d\n", __LINE__, lockerHandle, target);
    //jvm_trace_debug("[JSR257]jcc_nfc_register: %d, jcc_nfc_tag_registered_number addr = 0x%08X \n",__LINE__,jcc_nfc_tag_registered_number);
    jvm_trace_debug("[JSR257]jcc_nfc_register: %d, jcc_nfc_tag_registered_number(SE,ISO,NDEF,Plain) = [%d,%d,%d,%d]\n", __LINE__
                    , jcc_nfc_tag_registered_number.SERegistered
                    , jcc_nfc_tag_registered_number.ISORegistered
                    , jcc_nfc_tag_registered_number.NDEFRegistered
                    , jcc_nfc_tag_registered_number.PlainRegistered);

    jcc_nfc_sync_lock();
    switch (target)
    {
        case JCC_NFC_TARGET_SECURE_ELEMENT_ID:

            jcc_nfc_status.virtualRegistered ++;
            jcc_nfc_tag_registered_number.SERegistered ++;
            jvm_trace_debug("[JSR257]jcc_nfc_register: %d, SERegistered = %d \n", __LINE__, jcc_nfc_tag_registered_number.SERegistered);

            if (jcc_nfc_tag_registered_number.SERegistered > 1)
            {
                jcc_nfc_sync_unlock();
                jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_REGISTER_TARGET, lockerHandle, JCC_NFC_STATUS_COMMAND_IGNORE);
                jvm_trace_debug("[JSR257]jcc_nfc_register: %d,[UNBLOCK] = %d\n", __LINE__, lockerHandle);

                return JCC_NFC_OK;
            }
            break;

        case JCC_NFC_TARGET_ISO14443_CARD_ID:

            jcc_nfc_status.virtualRegistered ++;
            jcc_nfc_tag_registered_number.ISORegistered ++;
            jvm_trace_debug("[JSR257]jcc_nfc_register: %d, ISORegistered = %d \n", __LINE__, jcc_nfc_tag_registered_number.ISORegistered);

            if (jcc_nfc_tag_registered_number.ISORegistered > 1 && jcc_nfc_status.realRegistered > 0)
            {
                jcc_nfc_sync_unlock();
                jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_REGISTER_TARGET, lockerHandle, JCC_NFC_STATUS_COMMAND_IGNORE);
                jvm_trace_debug("[JSR257]jcc_nfc_register: %d,[UNBLOCK] = %d\n", __LINE__, lockerHandle);

                return JCC_NFC_OK;
            }
            break;

        case JCC_NFC_TARGET_NDEF_TAG_ID:

            jcc_nfc_status.virtualRegistered ++;
            jcc_nfc_tag_registered_number.NDEFRegistered ++;
            jvm_trace_debug("[JSR257]jcc_nfc_register: %d, NDEFRegistered = %d \n", __LINE__, jcc_nfc_tag_registered_number.NDEFRegistered);

            if (jcc_nfc_tag_registered_number.NDEFRegistered > 1 && jcc_nfc_status.realRegistered > 0)
            {
                jcc_nfc_sync_unlock();
                jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_REGISTER_TARGET, lockerHandle, JCC_NFC_STATUS_COMMAND_IGNORE);
                jvm_trace_debug("[JSR257]jcc_nfc_register: %d,[UNBLOCK] = %d\n", __LINE__, lockerHandle);

                return JCC_NFC_OK;
            }
            break;

        case JCC_NFC_TARGET_RFID_TAG_ID:

            jcc_nfc_status.virtualRegistered ++;
            jcc_nfc_tag_registered_number.PlainRegistered ++;
            jvm_trace_debug("[JSR257]jcc_nfc_register: %d, PlainRegistered = %d \n", __LINE__, jcc_nfc_tag_registered_number.PlainRegistered);

            if (jcc_nfc_tag_registered_number.PlainRegistered > 1 && jcc_nfc_status.realRegistered > 0)
            {
                jcc_nfc_sync_unlock();
                jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_REGISTER_TARGET, lockerHandle, JCC_NFC_STATUS_COMMAND_IGNORE);
                jvm_trace_debug("[JSR257]jcc_nfc_register: %d,[UNBLOCK] = %d\n", __LINE__, lockerHandle);

                return JCC_NFC_OK;
            }
            break;

        default:
            ASSERT(0);
    }

    if (!jcc_nfc_is_initialized)
    {
        jvm_trace_debug("[JSR257]jcc_nfc_register: %d, driver is not initialized!\n", __LINE__);
        jcc_nfc_sync_unlock();
        if (target != JCC_NFC_TARGET_SECURE_ELEMENT_ID)
        {
            jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_REGISTER_TARGET, lockerHandle, JCC_NFC_STATUS_COMMAND_IGNORE);
        }
    }
    else
    {
        if (target == JCC_NFC_TARGET_SECURE_ELEMENT_ID) // SE
        {
            jcc_nfc_sync_unlock();
            jvm_trace_debug("[JSR257]jcc_nfc_register: %d,before ==C== entering native SE register \n");
            jcc_nfc_se_register(lockerHandle);
            jvm_trace_debug("[JSR257]jcc_nfc_register: %d,after ==C== entering native SE register \n");
        }
        else
        {
            if (jcc_nfc_status.realRegistered == 0)
            {
                mustRegistered = 1;
                jcc_nfc_status.realRegistered = 1;
            }

            jcc_nfc_sync_unlock();
            if (mustRegistered == 1)
            {
                tmContext = get_ctrl_buffer(sizeof(jcc_nfc_task_message_context));
                tmContext->context = &jcc_nfc_tag_registered_number;
                tmContext->handle = lockerHandle;
                tmContext->cmd = 0;
                jcc_nfc_async_lock();
                jcc_nfc_tag_register(tmContext);
                return JCC_NFC_BLOCK;
            }
            else
            {
                jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_REGISTER_TARGET, lockerHandle, JCC_NFC_STATUS_COMMAND_IGNORE);
                jvm_trace_debug("[JSR257]jcc_nfc_register: %d,[UNBLOCK] = %d\n", __LINE__, lockerHandle);
            }
        }
    }

    jvm_trace_debug("[JSR257]jcc_nfc_register:%d\n", __LINE__);

    return JCC_NFC_OK;
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_push_register
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
jcc_nfc_result_enum jcc_nfc_push_register(jcc_nfc_target_type_enum target)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 mustRegistered = 0;
    void *context = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_push_register: %d, target = %d\n", __LINE__, target);
    jvm_trace_debug("[JSR257]jcc_nfc_push_register: %d, jcc_nfc_tag_registered_number(SE,NDEF) = [%d,%d]\n", __LINE__
                    , jcc_nfc_tag_registered_number.PushSERegistered
                    , jcc_nfc_tag_registered_number.PushNDEFRegistered);

    jcc_nfc_sync_lock();

    if (jcc_nfc_status.realRegistered == 0)
    {
        mustRegistered = 1;
    }

    switch (target)
    {
        case JCC_NFC_TARGET_SECURE_ELEMENT_ID:

            jcc_nfc_tag_registered_number.PushSERegistered ++;
            jvm_trace_debug("[JSR257]jcc_nfc_push_register: %d, PushSERegistered = %d \n", __LINE__, jcc_nfc_tag_registered_number.PushSERegistered);

            if (jcc_nfc_tag_registered_number.PushSERegistered > 1 || jcc_nfc_tag_registered_number.SERegistered > 0)
            {
                jcc_nfc_status.virtualRegistered ++;
                jcc_nfc_tag_registered_number.SERegistered ++;
                jcc_nfc_sync_unlock();
                return JCC_NFC_OK;
            }

            mustRegistered = 1;
            break;

        case JCC_NFC_TARGET_NDEF_TAG_ID:

            jcc_nfc_tag_registered_number.PushNDEFRegistered ++;
            jvm_trace_debug("[JSR257]jcc_nfc_push_register: %d, PushNDEFRegistered = %d \n", __LINE__, jcc_nfc_tag_registered_number.PushNDEFRegistered);

            if (jcc_nfc_tag_registered_number.PushNDEFRegistered > 1 || jcc_nfc_tag_registered_number.NDEFRegistered > 0)
            {
                jcc_nfc_status.virtualRegistered ++;
                jcc_nfc_tag_registered_number.NDEFRegistered ++;
                jcc_nfc_sync_unlock();
                return JCC_NFC_OK;
            }

            if (mustRegistered == 0)
            {
                jcc_nfc_status.virtualRegistered ++;
                jcc_nfc_tag_registered_number.NDEFRegistered ++;
            }
            break;

        default:
            ASSERT(0);
    }

    jcc_nfc_sync_unlock();

    if (mustRegistered == 0)
    {
        jcc_nfc_reset(0);
    }
    else
    {
        jcc_nfc_register(target, &context, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_se_unregister_internal
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_se_unregister_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_se_unregister_internal: %d", __LINE__);
    jcc_nfc_send_message(MSG_ID_NFC_SE_NTF_UNREGISTER_REQ, MOD_NFC, INVALID_SAP, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_tag_unregister_internal
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_tag_unregister_internal(jcc_nfc_task_message_context *tmContext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_remote_dev_ntf_unregister_req_struct *p_msg = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_msg = (nfc_remote_dev_ntf_unregister_req_struct *) construct_local_para(sizeof(nfc_remote_dev_ntf_unregister_req_struct), TD_CTRL);
    tmContext->context = NULL;
    p_msg->REQpContext = (void *)tmContext;

    jvm_trace_debug("[JSR257]jcc_nfc_tag_unregister_internal: REQpContext=0x%08X", p_msg->REQpContext);
    jvm_trace_debug("[JSR257]jcc_nfc_tag_unregister_internal: %d, jcc_nfc_send_message(MSG_ID_NFC_REMOTE_DEV_NTF_UNREGISTER_REQ, MOD_NFC, INVALID_SAP, NULL)\n", __LINE__);
    jcc_nfc_send_message(MSG_ID_NFC_REMOTE_DEV_NTF_UNREGISTER_REQ, MOD_NFC, INVALID_SAP, (void *)p_msg);

}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_unregister
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
jcc_nfc_result_enum jcc_nfc_unregister(
    jcc_nfc_target_type_enum target,
    void **context,
    int lockerHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jcc_nfc_task_message_context *tmContext = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*if (jcc_nfc_tag_registered_number == NULL)
    {
     jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_UNREGISTER_TARGET,lockerHandle,JCC_NFC_STATUS_COMMAND_IGNORE);
     jvm_trace_debug("[JSR257]jcc_nfc_unregister: %d,[UNBLOCK] = %d\n",__LINE__,lockerHandle);

       return JCC_NFC_FAIL;
    }*/

    jvm_trace_debug("[JSR257]jcc_nfc_unregister: %d,lockHandler = %d,target = %d.\n", __LINE__
                    , lockerHandle
                    , target);

    jcc_nfc_sync_lock();
    switch (target)
    {
        case JCC_NFC_TARGET_SECURE_ELEMENT_ID:
            if (jcc_nfc_tag_registered_number.SERegistered == 0)
            {
                jvm_trace_debug("[JSR257]jcc_nfc_unregister: %d, SERegistered(%d) == 0,unregister = no.\n", __LINE__, jcc_nfc_tag_registered_number.SERegistered);

                jcc_nfc_sync_unlock();
                jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_UNREGISTER_TARGET, lockerHandle, JCC_NFC_STATUS_COMMAND_IGNORE);
                jvm_trace_debug("[JSR257]jcc_nfc_unregister: %d,[UNBLOCK] = %d\n", __LINE__, lockerHandle);

                return JCC_NFC_OK;
            }
            else if (jcc_nfc_tag_registered_number.SERegistered == 1)
            {
                jvm_trace_debug("[JSR257]jcc_nfc_unregister: %d, SERegistered(%d) == 1,unregister = yes.\n", __LINE__, jcc_nfc_tag_registered_number.SERegistered);

                jcc_nfc_status.virtualRegistered--;
                jcc_nfc_tag_registered_number.SERegistered--;
                break;
            }
            else // jcc_nfc_tag_registered_number->SERegistered>1
            {
                jvm_trace_debug("[JSR257]jcc_nfc_unregister: %d, SERegistered(%d) > 1,counter --\n", __LINE__, jcc_nfc_tag_registered_number.SERegistered);

                jcc_nfc_status.virtualRegistered--;
                jcc_nfc_tag_registered_number.SERegistered--;

                jcc_nfc_sync_unlock();
                jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_UNREGISTER_TARGET, lockerHandle, JCC_NFC_STATUS_COMMAND_IGNORE);
                jvm_trace_debug("[JSR257]jcc_nfc_unregister: %d,[UNBLOCK] = %d\n", __LINE__, lockerHandle);

                return JCC_NFC_OK;
            }

        case JCC_NFC_TARGET_ISO14443_CARD_ID:

            if (jcc_nfc_tag_registered_number.ISORegistered == 0)
            {
                jvm_trace_debug("[JSR257]jcc_nfc_unregister: %d, ISORegistered(%d) == 0,unregister = no.\n", __LINE__, jcc_nfc_tag_registered_number.ISORegistered);

                jcc_nfc_sync_unlock();
                jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_UNREGISTER_TARGET, lockerHandle, JCC_NFC_STATUS_COMMAND_IGNORE);
                jvm_trace_debug("[JSR257]jcc_nfc_unregister: %d,[UNBLOCK] = %d\n", __LINE__, lockerHandle);

                return JCC_NFC_OK;
            }
            else if (jcc_nfc_tag_registered_number.ISORegistered == 1)
            {
                jvm_trace_debug("[JSR257]jcc_nfc_unregister: %d, ISORegistered(%d) == 1,unregister = yes.\n", __LINE__, jcc_nfc_tag_registered_number.ISORegistered);

                jcc_nfc_status.virtualRegistered--;
                jcc_nfc_tag_registered_number.ISORegistered --;
                break;
            }
            else // jcc_nfc_tag_registered_number->ISORegistered>1
            {
                jvm_trace_debug("[JSR257]jcc_nfc_unregister: %d, ISORegistered(%d) > 1,counter -- \n", __LINE__, jcc_nfc_tag_registered_number.ISORegistered);

                jcc_nfc_status.virtualRegistered--;
                jcc_nfc_tag_registered_number.ISORegistered--;

                jcc_nfc_sync_unlock();
                jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_UNREGISTER_TARGET, lockerHandle, JCC_NFC_STATUS_COMMAND_IGNORE);
                jvm_trace_debug("[JSR257]jcc_nfc_unregister: %d,[UNBLOCK] = %d\n", __LINE__, lockerHandle);

                return JCC_NFC_OK;
            }

        case JCC_NFC_TARGET_NDEF_TAG_ID:

            if (jcc_nfc_tag_registered_number.NDEFRegistered == 0)
            {
                jvm_trace_debug("[JSR257]jcc_nfc_unregister: %d, NDEFRegistered(%d) == 0,unregister = no \n", __LINE__, jcc_nfc_tag_registered_number.NDEFRegistered);

                jcc_nfc_sync_unlock();
                jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_UNREGISTER_TARGET, lockerHandle, JCC_NFC_STATUS_COMMAND_IGNORE);
                jvm_trace_debug("[JSR257]jcc_nfc_unregister: %d,[UNBLOCK] = %d\n", __LINE__, lockerHandle);

                return JCC_NFC_OK;
            }
            else if (jcc_nfc_tag_registered_number.NDEFRegistered == 1)
            {
                jvm_trace_debug("[JSR257]jcc_nfc_unregister: %d, NDEFRegistered(%d) == 1,unregister = yes \n", __LINE__, jcc_nfc_tag_registered_number.NDEFRegistered);

                jcc_nfc_status.virtualRegistered--;
                jcc_nfc_tag_registered_number.NDEFRegistered--;
                break;
            }
            else // jcc_nfc_tag_registered_number->NDEFRegistered>1
            {
                jvm_trace_debug("[JSR257]jcc_nfc_unregister: %d, NDEFRegistered(%d) > 1,counter -- \n", __LINE__, jcc_nfc_tag_registered_number.NDEFRegistered);

                jcc_nfc_status.virtualRegistered--;
                jcc_nfc_tag_registered_number.NDEFRegistered--;

                jcc_nfc_sync_unlock();
                jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_UNREGISTER_TARGET, lockerHandle, JCC_NFC_STATUS_COMMAND_IGNORE);
                jvm_trace_debug("[JSR257]jcc_nfc_unregister: %d,[UNBLOCK] = %d\n", __LINE__, lockerHandle);

                return JCC_NFC_OK;
            }

        case JCC_NFC_TARGET_RFID_TAG_ID:
            if (jcc_nfc_tag_registered_number.PlainRegistered == 0)
            {
                jvm_trace_debug("[JSR257]jcc_nfc_unregister: %d, PlainRegistered(%d) == 0,unregister = no \n", __LINE__, jcc_nfc_tag_registered_number.PlainRegistered);

                jcc_nfc_sync_unlock();
                jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_UNREGISTER_TARGET, lockerHandle, JCC_NFC_STATUS_COMMAND_IGNORE);
                jvm_trace_debug("[JSR257]jcc_nfc_unregister: %d,[UNBLOCK] = %d\n", __LINE__, lockerHandle);

                return JCC_NFC_OK;
            }
            else if (jcc_nfc_tag_registered_number.PlainRegistered == 1)
            {
                jvm_trace_debug("[JSR257]jcc_nfc_unregister: %d, PlainRegistered(%d) == 1,unregister = yes\n", __LINE__, jcc_nfc_tag_registered_number.PlainRegistered);

                jcc_nfc_status.virtualRegistered--;
                jcc_nfc_tag_registered_number.PlainRegistered--;
                break;
            }
            else // jcc_nfc_tag_registered_number->PlainRegistered>1
            {
                jvm_trace_debug("[JSR257]jcc_nfc_unregister: %d, PlainRegistered(%d) > 1,counter -- \n", __LINE__, jcc_nfc_tag_registered_number.PlainRegistered);

                jcc_nfc_status.virtualRegistered--;
                jcc_nfc_tag_registered_number.PlainRegistered--;

                jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_UNREGISTER_TARGET, lockerHandle, JCC_NFC_STATUS_COMMAND_IGNORE);
                jvm_trace_debug("[JSR257]jcc_nfc_unregister: %d,[UNBLOCK] = %d\n", __LINE__, lockerHandle);
                return JCC_NFC_OK;
            }

        default:
            ASSERT(0);
    }

    jcc_nfc_sync_unlock();
    jvm_trace_debug("[JSR257]jcc_nfc_unregister:%d\n", __LINE__);

    jvm_trace_debug("[JSR257]jcc_nfc_unregister: %d, jcc_nfc_tag_registered_number = (%d %d %d %d)\n", __LINE__
                    , jcc_nfc_tag_registered_number.SERegistered
                    , jcc_nfc_tag_registered_number.ISORegistered
                    , jcc_nfc_tag_registered_number.NDEFRegistered
                    , jcc_nfc_tag_registered_number.PlainRegistered);

    if (target == JCC_NFC_TARGET_SECURE_ELEMENT_ID) // SE
    {
        jcc_nfc_se_unregister_internal();
    }
    else
    {
        if (jcc_nfc_tag_registered_number.PlainRegistered == 0 &&
                jcc_nfc_tag_registered_number.ISORegistered == 0 &&
                jcc_nfc_tag_registered_number.NDEFRegistered == 0 &&
                jcc_nfc_device_state == JCC_NFC_DEVICE_DETECT_TARGET)
        {
            tmContext = (jcc_nfc_task_message_context *)get_ctrl_buffer(sizeof(jcc_nfc_task_message_context));
            tmContext->handle = lockerHandle;
            tmContext->context = (void *) & jcc_nfc_current_target_context;
            tmContext->cmd = 0;
            jcc_nfc_tag_unregister_internal(tmContext);
        }
        else
        {
            jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_UNREGISTER_TARGET, lockerHandle, JCC_NFC_STATUS_COMMAND_IGNORE);
        }
    }

    return JCC_NFC_BLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_push_unregister
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
jcc_nfc_result_enum jcc_nfc_push_unregister(jcc_nfc_target_type_enum target)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *context = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_push_unregister: %d, target = %d.\n", __LINE__, target);

    jcc_nfc_sync_lock();
    switch (target)
    {
        case JCC_NFC_TARGET_SECURE_ELEMENT_ID:
            if (jcc_nfc_tag_registered_number.PushSERegistered == 0)
            {
                jvm_trace_debug("[JSR257]jcc_nfc_push_unregister: %d, PushSERegistered(%d) == 0,unregister = no.\n", __LINE__, jcc_nfc_tag_registered_number.PushSERegistered);
                jcc_nfc_sync_unlock();
                return JCC_NFC_OK;
            }
            else if (jcc_nfc_tag_registered_number.PushSERegistered == 1)
            {
                jvm_trace_debug("[JSR257]jcc_nfc_unregister: %d, PushSERegistered(%d) == 1,unregister = yes.\n", __LINE__, jcc_nfc_tag_registered_number.PushSERegistered);
                jcc_nfc_tag_registered_number.PushSERegistered--;
                if (jcc_nfc_tag_registered_number.SERegistered > 1)
                {
                    jcc_nfc_status.virtualRegistered--;
                    jcc_nfc_tag_registered_number.SERegistered--;
                    jcc_nfc_sync_unlock();
                    return JCC_NFC_OK;
                }
                break;
            }
            else // jcc_nfc_tag_registered_number->PushSERegistered>1
            {
                jvm_trace_debug("[JSR257]jcc_nfc_unregister: %d, PushSERegistered(%d) > 1,counter --\n", __LINE__, jcc_nfc_tag_registered_number.PushSERegistered);
                jcc_nfc_tag_registered_number.PushSERegistered--;
                jcc_nfc_status.virtualRegistered--;
                jcc_nfc_tag_registered_number.SERegistered--;
                jcc_nfc_sync_unlock();
                return JCC_NFC_OK;
            }

        case JCC_NFC_TARGET_NDEF_TAG_ID:

            if (jcc_nfc_tag_registered_number.PushNDEFRegistered == 0)
            {
                jvm_trace_debug("[JSR257]jcc_nfc_unregister: %d, PushNDEFRegistered(%d) == 0,unregister = no \n", __LINE__, jcc_nfc_tag_registered_number.PushNDEFRegistered);
                jcc_nfc_sync_unlock();
                return JCC_NFC_OK;
            }
            else if (jcc_nfc_tag_registered_number.PushNDEFRegistered == 1)
            {
                jvm_trace_debug("[JSR257]jcc_nfc_unregister: %d, NDEFRegistered(%d) == 1,unregister = yes \n", __LINE__, jcc_nfc_tag_registered_number.PushNDEFRegistered);
                jcc_nfc_tag_registered_number.PushNDEFRegistered--;
                if (jcc_nfc_tag_registered_number.NDEFRegistered > 1)
                {
                    jcc_nfc_status.virtualRegistered--;
                    jcc_nfc_tag_registered_number.NDEFRegistered--;
                    jcc_nfc_sync_unlock();
                    return JCC_NFC_OK;
                }
                break;
            }
            else // jcc_nfc_tag_registered_number->PushNDEFRegistered>1
            {
                jvm_trace_debug("[JSR257]jcc_nfc_unregister: %d, NDEFRegistered(%d) > 1,counter -- \n", __LINE__, jcc_nfc_tag_registered_number.PushNDEFRegistered);
                jcc_nfc_tag_registered_number.PushNDEFRegistered--;
                jcc_nfc_status.virtualRegistered--;
                jcc_nfc_tag_registered_number.NDEFRegistered--;
                jcc_nfc_sync_unlock();
                return JCC_NFC_OK;
            }

        default:
            ASSERT(0);
    }

    jcc_nfc_sync_unlock();

    jcc_nfc_unregister(target, &context, 0);
}


/*****************************************************************************
 * FUNCTION
 *  j2me_process_recvd_nfc_ind
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool j2me_process_recvd_nfc_ind(kal_uint8 tnf, kal_uint8 *type, kal_uint8 type_length)
{
#ifdef SUPPORT_JSR_257_PUSH
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pushentry_struct *p = NULL;
    kal_uint8 appid[256] = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]j2me_process_recvd_nfc_ind: %d, tnf=%d, type=%s, length=%d\n ", __LINE__, tnf, type, type_length);

    if (tnf == 0xFF)
    {
        strcat((char *)appid, "secure-element:?aid=");
        strncat((char *)appid, type, type_length);
    }
    else if (tnf == 1)
    {
        strcat((char *)appid, "ndef:rtd?name=urn:nfc:wkt:");
        strncat((char *)appid, type, type_length);
    }
    else if (tnf == 4)
    {
        strcat((char *)appid, "ndef:external_rtd?name=urn:nfc:ext:");
        strncat((char *)appid, type, type_length);
    }
    else
    {
        strcat((char *)appid, "ndef:rtd?name=");
        strncat((char *)appid, type, type_length);
    }

    jvm_trace_debug("j2me_process_recvd_nfc_ind(), %d, appid='%s' \n", __LINE__, appid);

    p = (pushentry_struct *)push_process_recvd_nfc_ind((char*)appid);

    if (p != NULL)
    {
        jam_timealarm_push_ind_handler(
            PUSHTYPE_NFC_PUSH,
            (void*)p,
            p->midlet,
            p->midletid,
            p->storagename,
            KAL_FALSE);
        return KAL_TRUE;
    }
    else
    {
        jvm_trace_debug("j2me_process_recvd_nfc_ind(), NO MATCHING PUSH TO LAUNCH, %d \n", __LINE__);
        return KAL_FALSE;
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_get_uid
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
jcc_nfc_result_enum jcc_nfc_get_uid(
    kal_int32 target_handle,
    char *uid,
    kal_int32 *uid_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *target_uid;
    kal_int32 target_uid_length;
    int i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_get_uid: %d, target_handle=0x%08X \n", __LINE__, target_handle);
    //jvm_trace_debug("[JSR257]jcc_nfc_get_uid: %d, jcc_nfc_current_target_context=0x%08X \n", __LINE__, jcc_nfc_current_target_context);
    jvm_trace_debug("[JSR257]jcc_nfc_get_uid: %d, jcc_nfc_current_target_context.Target_Handle=0x%08X \n", __LINE__, jcc_nfc_current_target_context.Target_Handle);

    if (target_handle == jcc_nfc_current_target_context.Target_Handle)
    {
        switch (jcc_nfc_current_target_context.RemoteDev.psRemoteDevInfo->RemDevType)
        {
            case phNfc_eISO14443_A_PICC:
            case phNfc_eMifare_PICC:
                target_uid_length = (kal_int32) jcc_nfc_current_target_context.RemoteDev.psRemoteDevInfo->RemoteDevInfo.Iso14443A_Info.UidLength;
                target_uid = (kal_uint8*)jcc_nfc_current_target_context.RemoteDev.psRemoteDevInfo->RemoteDevInfo.Iso14443A_Info.Uid;
                break;

            case phNfc_eISO14443_B_PICC:
                target_uid_length = PHHAL_PUPI_LENGTH;
                target_uid = (kal_uint8*)jcc_nfc_current_target_context.RemoteDev.psRemoteDevInfo->RemoteDevInfo.Iso14443B_Info.AtqB.AtqResInfo.Pupi;
                break;

            case phNfc_eISO14443_BPrime_PICC:
                target_uid_length = 0;
                target_uid = NULL;
                break;

            case phNfc_eNfcIP1_Target:
            case phNfc_eNfcIP1_Initiator:
                target_uid_length = (kal_int32) jcc_nfc_current_target_context.RemoteDev.psRemoteDevInfo->RemoteDevInfo.NfcIP_Info.NFCID_Length;
                target_uid = (kal_uint8*)jcc_nfc_current_target_context.RemoteDev.psRemoteDevInfo->RemoteDevInfo.NfcIP_Info.NFCID;
                break;

            case phNfc_eFelica_PICC:
                target_uid_length = (kal_int32) sizeof(jcc_nfc_current_target_context.RemoteDev.psRemoteDevInfo->RemoteDevInfo.Felica_Info.IDm);
                target_uid = (kal_uint8*)jcc_nfc_current_target_context.RemoteDev.psRemoteDevInfo->RemoteDevInfo.Felica_Info.IDm;
                break;

            case phNfc_eJewel_PICC:
                target_uid_length = (kal_int32) sizeof(jcc_nfc_current_target_context.RemoteDev.psRemoteDevInfo->RemoteDevInfo.Jewel_Info.Uid);
                target_uid = (kal_uint8*)jcc_nfc_current_target_context.RemoteDev.psRemoteDevInfo->RemoteDevInfo.Jewel_Info.Uid;
                break;

            case phNfc_eISO15693_PICC:
                target_uid_length = (kal_int32) jcc_nfc_current_target_context.RemoteDev.psRemoteDevInfo->RemoteDevInfo.Iso15693_Info.UidLength;
                target_uid = (kal_uint8*)jcc_nfc_current_target_context.RemoteDev.psRemoteDevInfo->RemoteDevInfo.Iso15693_Info.Uid;
                break;

            default:
                target_uid_length = 0;
                target_uid = NULL;
                break;
        }

        memcpy(uid, target_uid, target_uid_length);
        *uid_length = target_uid_length;

        return JCC_NFC_OK;
    }

    return JCC_NFC_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_get_mapping
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
jcc_nfc_result_enum jcc_nfc_get_mapping(
    kal_int32 target_handle,
    char *mapping,
    kal_int32 *mapping_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *ptr;
    kal_uint32 length;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_get_mapping: %d, target_handle=0x%08X \n", __LINE__, target_handle);
    //jvm_trace_debug("[JSR257]jcc_nfc_get_mapping: %d, jcc_nfc_current_target_context=0x%08X \n", __LINE__, jcc_nfc_current_target_context);
    jvm_trace_debug("[JSR257]jcc_nfc_get_mapping: %d, jcc_nfc_current_target_context.Target_Handle=0x%08X \n", __LINE__, jcc_nfc_current_target_context.Target_Handle);

    if (target_handle == jcc_nfc_current_target_context.Target_Handle && mapping)
    {
        switch (jcc_nfc_current_target_context.RemoteDev.psRemoteDevInfo->RemDevType)
        {

            case phNfc_ePICC_DevType:
                ptr = jcc_nfc_mapping_Generic;
                length = sizeof(jcc_nfc_mapping_Generic);
                break;

            case phNfc_eISO14443_A_PICC:
                ptr = jcc_nfc_mapping_ISO14443A;
                length = sizeof(jcc_nfc_mapping_ISO14443A);
                break;

            case phNfc_eMifare_PICC:
                if (jcc_nfc_current_target_context.Transceive_TagType == APP_TAG_MIFARE_1K)
                {
                    ptr = jcc_nfc_mapping_Mifare_1K;
                    length = sizeof(jcc_nfc_mapping_Mifare_1K);
                }
                else if (jcc_nfc_current_target_context.Transceive_TagType == APP_TAG_MIFARE_4K)
                {
                    ptr = jcc_nfc_mapping_Mifare_4K;
                    length = sizeof(jcc_nfc_mapping_Mifare_4K);
                }
                else if (jcc_nfc_current_target_context.Transceive_TagType == APP_TAG_MIFARE_UL)
                {
                    ptr = jcc_nfc_mapping_Mifare_UL;
                    length = sizeof(jcc_nfc_mapping_Mifare_UL);
                }
                else
                {
                    ptr = jcc_nfc_mapping_Mifare;
                    length = sizeof(jcc_nfc_mapping_Mifare);
                }
                break;

            case phNfc_eISO14443_B_PICC:
                ptr = jcc_nfc_mapping_ISO14443B;
                length = sizeof(jcc_nfc_mapping_ISO14443B);
                break;

            case phNfc_eISO14443_BPrime_PICC:
                ptr = jcc_nfc_mapping_ISO14443BP;
                length = sizeof(jcc_nfc_mapping_ISO14443BP);
                break;

            case phNfc_eFelica_PICC:
                ptr = jcc_nfc_mapping_Felica;
                length = sizeof(jcc_nfc_mapping_Felica);
                break;

            case phNfc_eJewel_PICC:
                ptr = jcc_nfc_mapping_Jewel;
                length = sizeof(jcc_nfc_mapping_Jewel);
                break;

            case phNfc_eNfcIP1_Target:
            case phNfc_eNfcIP1_Initiator:
                ptr = jcc_nfc_mapping_NFCIP;
                length = sizeof(jcc_nfc_mapping_NFCIP);
                break;

            case phNfc_eISO15693_PICC:
                ptr = jcc_nfc_mapping_ISO15693;
                length = sizeof(jcc_nfc_mapping_ISO15693);
                break;

            default:
                ptr = jcc_nfc_mapping_Unknown;
                length = sizeof(jcc_nfc_mapping_Unknown);
                break;
        }

        memcpy(mapping, ptr, length);
        *mapping_length = length;

        return JCC_NFC_OK;
    }

    return JCC_NFC_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_get_property
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
jcc_nfc_result_enum jcc_nfc_get_property(
    kal_int32 target_handle,
    kal_int32 index,
    char *value,
    kal_int32 *value_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_get_property, %d \n", __LINE__);
    return JCC_NFC_NOT_IMPLEMENTED;
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_is_supported_type
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
jcc_nfc_result_enum jcc_nfc_is_supported_type(
    kal_int32 target_handle,
    jcc_nfc_target_type_enum target_type,
    kal_bool *supported)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 nTypes;
    jcc_nfc_target_type_enum *pTypes;
    kal_int32 pTypes2[2] = { -1, -1};
    kal_uint32 type;
    int i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_is_supported_type: %d, target_handle=0x%08X \n", __LINE__, target_handle);
    //jvm_trace_debug("[JSR257]jcc_nfc_is_supported_type: %d, jcc_nfc_current_target_context=0x%08X \n", __LINE__, jcc_nfc_current_target_context);
    jvm_trace_debug("[JSR257]jcc_nfc_is_supported_type: %d, jcc_nfc_current_target_context.Target_Handle=0x%08X \n", __LINE__, jcc_nfc_current_target_context.Target_Handle);


    //RESET

    *supported = KAL_FALSE;

    if (target_handle == jcc_nfc_current_target_context.Target_Handle)
    {
        if (jcc_nfc_current_target_context.NDEFDetected == TRUE)
        {
            nTypes = 2;
            pTypes2[1] = JCC_NFC_TARGET_NDEF_TAG_ID;
        }
        else
        {
            nTypes = 1;
        }

        jvm_trace_debug("[JSR257]jcc_nfc_is_supported_type: %d, nTypes=%d \n", __LINE__, nTypes);

        switch (jcc_nfc_current_target_context.RemoteDev.psRemoteDevInfo->RemDevType)
        {
            case phNfc_eISO14443_A_PICC:
            case phNfc_eISO14443_B_PICC:
            case phNfc_eISO14443_BPrime_PICC:
                pTypes2[0] = JCC_NFC_TARGET_ISO14443_CARD_ID;
                break;

            case phNfc_ePICC_DevType:
            case phNfc_eMifare_PICC:
            case phNfc_eFelica_PICC:
            case phNfc_eJewel_PICC:
            case phNfc_eNfcIP1_Target:
            case phNfc_eNfcIP1_Initiator:
            case phNfc_eISO15693_PICC:
                pTypes2[0] = JCC_NFC_TARGET_RFID_TAG_ID;
                break;

            default:
                return JCC_NFC_INVALID_ARGUMENT;
        }
    }
    else
    {
        return JCC_NFC_FAIL;
    }

    if (1)
    {
        int i;
        for (i = 0; i < nTypes; i++)
            jvm_trace_debug("[JSR257]jcc_nfc_is_supported_type: %d, pTypes2[%d]=%d \n", __LINE__, i, pTypes2[i]);
    }

    for (type = 0; type < nTypes; type++)
    {
        jvm_trace_debug("[JSR257]jcc_nfc_is_supported_type: %d, src_target_type=%d  pTypes[%d]=%d \n", __LINE__, target_type, nTypes, type, pTypes2[type]);

        if (pTypes2[type] == target_type)
        {
            *supported = KAL_TRUE;
            break;
        }
    }

    return JCC_NFC_OK;
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_is_tag_detected
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jcc_nfc_is_tag_detected(void)
{
    return jcc_nfc_is_target_detected;
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_get_device_state
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 jcc_nfc_get_device_state(void)
{
    return jcc_nfc_device_state;
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_notify
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jcc_nfc_notify(kal_int32 target_handle, kal_bool target_used)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_notify:%d\n", __LINE__);
    jvm_trace_debug("[JSR257] $$: before Set notify flag \n");
    jvm_trace_debug("[JSR257]      jcc_nfc_notify_flag = %d \n", jcc_nfc_notify_flag);
    jvm_trace_debug("[JSR257]      jcc_nfc_used_flag = %d \n", jcc_nfc_used_flag);
    /* Set notify flag */
    jcc_nfc_notify_flag = KAL_TRUE;
    jcc_nfc_used_flag = target_used;
    jvm_trace_debug("[JSR257] $$: after Set notify flag \n");
    jvm_trace_debug("[JSR257]      jcc_nfc_notify_flag = %d \n", jcc_nfc_notify_flag);
    jvm_trace_debug("[JSR257]      jcc_nfc_used_flag = %d \n", jcc_nfc_used_flag);

    /* IF session count is null */
    /* THEN disconnect target */
    if (jcc_nfc_status.realConnected > 0)
    {
        jvm_trace_debug("[JSR257] return KAL_TRUE \n");
        return KAL_TRUE;
    }
    else
    {
        jvm_trace_debug("[JSR257] return KAL_FALSE \n");
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_open
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
jcc_nfc_result_enum jcc_nfc_open(kal_int32 target_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_open: %d\n", __LINE__);

    /* Increase session count */
    jcc_nfc_sync_lock();
    if (jcc_nfc_status.virtualConnected < 0)
    {
        jcc_nfc_status.virtualConnected = 0;
    }

    jcc_nfc_status.virtualConnected ++;
    jcc_nfc_sync_unlock();

    return JCC_NFC_OK;
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_close
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
jcc_nfc_result_enum jcc_nfc_close(kal_int32 target_handle, void **context)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_close: %d\n", __LINE__);
    /*if (jcc_nfc_tag_registered_number == NULL)
    {
     jvm_trace_debug("[JSR257] jcc_nfc_close: %d, jcc_nfc_tag_registered_number == NULL \n",__LINE__);
       return JCC_NFC_FAIL;
    }*/

    jcc_nfc_sync_lock();

    if (jcc_nfc_status.virtualConnected > 0)
    {
        /* Decrease session count */
        jcc_nfc_status.virtualConnected --;
    }

    /* IF session count is null AND notify flag is set */
    /* THEN disconnect target */
    if (jcc_nfc_notify_flag == KAL_FALSE)
    {
        jcc_nfc_sync_unlock();
        return JCC_NFC_OK;
    }

    if (jcc_nfc_status.virtualConnected > 0)
    {
        jcc_nfc_sync_unlock();
        return JCC_NFC_OK;
    }

    jcc_nfc_sync_unlock();

    return JCC_NFC_BLOCK;
}



/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_write
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
jcc_nfc_result_enum jcc_nfc_write(
    kal_int32 target_handle,
    char *tx_data,
    kal_int32 tx_data_length,
    void **context,
    kal_int32 lockerHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_ndef_write_req_struct *p_msg; // send writeNDEF MSG
    jcc_nfc_task_message_context *tmContext = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jcc_nfc_current_target_context.ndef_message && jcc_nfc_current_target_context.ndef_message->buffer)
    {
        free_ctrl_buffer(jcc_nfc_current_target_context.ndef_message->buffer);
    }
    if (jcc_nfc_current_target_context.ndef_message)
    {
        free_ctrl_buffer(jcc_nfc_current_target_context.ndef_message);
    }
    jcc_nfc_current_target_context.ndef_message = NULL;

    p_msg = (nfc_ndef_write_req_struct *) construct_local_para(sizeof(nfc_ndef_write_req_struct), TD_CTRL);
    ASSERT(p_msg); // judge whether MALLOC is success

    jvm_trace_debug("[JSR257]jcc_nfc_write: %d\n,begin:", __LINE__);

    p_msg->REQpsWr = get_ctrl_buffer(sizeof(phNfc_sData_t)); // when free it ?
    p_msg->REQpsWr->buffer = get_ctrl_buffer(tx_data_length);

    p_msg->REQhRemoteDevice = jcc_nfc_current_target_context.Target_Handle;
    memcpy(p_msg->REQpsWr->buffer, tx_data, tx_data_length);
    p_msg->REQpsWr->length = tx_data_length;
    p_msg->REQpNdefWrite_RspCb = (pphLibNfc_RspCb_t)jcc_nfc_dummy_callback_handler;

    jcc_nfc_current_target_context.ndef_message = p_msg->REQpsWr;
    jcc_nfc_current_target_context.ndef_message->buffer = p_msg->REQpsWr->buffer;
    jcc_nfc_current_target_context.ndef_message->length = p_msg->REQpsWr->length;

    // lock mechanism
    jvm_trace_debug("[JSR257]jcc_nfc_write: %d ,lockHandler = %d", __LINE__, lockerHandle);
    tmContext = (jcc_nfc_task_message_context *)get_ctrl_buffer(sizeof(jcc_nfc_task_message_context));
    tmContext->handle = lockerHandle;
    tmContext->context = (void *) & jcc_nfc_current_target_context;
    p_msg->REQpContext = (void *)tmContext;

    jvm_trace_debug("[JSR257]jcc_nfc_write: %d ,Write buffer addr = %x", __LINE__, p_msg->REQpsWr->buffer);
    jvm_trace_debug("[JSR257]jcc_nfc_write: %d ,Write buffer length = %d", __LINE__, p_msg->REQpsWr->length);

    jcc_nfc_async_lock();
    jvm_trace_debug("[JSR257]jcc_nfc_write: %d ,jcc_nfc_send_message(MSG_ID_NFC_NDEF_WRITE_REQ)", __LINE__);

    jcc_nfc_send_message(MSG_ID_NFC_NDEF_WRITE_REQ, MOD_NFC, INVALID_SAP, (void *)p_msg);

    jvm_trace_debug("[JSR257]jcc_nfc_write: %d\n,end:", __LINE__);
    return JCC_NFC_BLOCK;
}



/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_read
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
jcc_nfc_result_enum jcc_nfc_read(kal_int32 target_handle,
                                 char *rx_data,
                                 kal_int32 *rx_data_length,
                                 void **context,
                                 kal_int32 lockHandler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_ndef_read_req_struct *p_msg; // send readNDEF MSG
    jcc_nfc_task_message_context *tmContext = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jcc_nfc_current_target_context.ndef_message && jcc_nfc_current_target_context.ndef_message->buffer)
    {
        jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_TAG_READ, lockHandler, NFCSTATUS_SUCCESS);
        jvm_trace_debug("[JSR257]jcc_nfc_read: %d, lockerHandler = %d, NDEF data exist!\n", __LINE__, lockHandler);
        return JCC_NFC_OK;
    }

    p_msg = (nfc_ndef_read_req_struct *) construct_local_para(sizeof(nfc_ndef_read_req_struct), TD_CTRL);
    jvm_trace_debug("[JSR257]jcc_nfc_read: %d, lockerHandler = %d\n", __LINE__, lockHandler);

    ASSERT(p_msg);// judge whether MALLOC is success
    jcc_nfc_current_target_context.ndef_info.ActualNdefMsgLength = 200;

    p_msg->REQhRemoteDevice = jcc_nfc_current_target_context.Target_Handle;
    p_msg->REQpsRd = (phNfc_sData_t*)get_ctrl_buffer(sizeof(phNfc_sData_t));
    p_msg->REQpsRd->buffer = (uint8_t*)get_ctrl_buffer(jcc_nfc_current_target_context.ndef_info.ActualNdefMsgLength);
    p_msg->REQpsRd->length = jcc_nfc_current_target_context.ndef_info.ActualNdefMsgLength;

    jcc_nfc_current_target_context.ndef_message = p_msg->REQpsRd;
    jcc_nfc_current_target_context.ndef_message->buffer = p_msg->REQpsRd->buffer;
    jcc_nfc_current_target_context.ndef_message->length = jcc_nfc_current_target_context.ndef_info.ActualNdefMsgLength;

    memset(jcc_nfc_current_target_context.ndef_message->buffer, 0, jcc_nfc_current_target_context.ndef_message->length);

    jvm_trace_debug("[JSR257]jcc_nfc_read: %d,NDEF_READ_REQ:jcc_nfc_current_target_context->ndef_message addr:%x\n", __LINE__, jcc_nfc_current_target_context.ndef_message);
    jvm_trace_debug("[JSR257]jcc_nfc_read: %d,NDEF_READ_REQ:jcc_nfc_current_target_context->ndef_message->buffer addr:%x\n", __LINE__, jcc_nfc_current_target_context.ndef_message->buffer);
    jvm_trace_debug("[JSR257]jcc_nfc_read: %d,NDEF_READ_REQ:jcc_nfc_current_target_context->ndef_message->length:%d\n", __LINE__, jcc_nfc_current_target_context.ndef_message->length);

    p_msg->REQOffset = phLibNfc_Ndef_EBegin;
    p_msg->REQpNdefRead_RspCb = (pphLibNfc_RspCb_t)jcc_nfc_dummy_callback_handler;

    tmContext = (jcc_nfc_task_message_context *)get_ctrl_buffer(sizeof(jcc_nfc_task_message_context));
    tmContext->handle = lockHandler;
    tmContext->cmd = 0;
    tmContext->context = &jcc_nfc_current_target_context;
    p_msg->REQpContext = (void *)tmContext;

    jcc_nfc_async_lock();
    jvm_trace_debug("[JSR257]jcc_nfc_read: %d,jcc_nfc_send_message(MSG_ID_NFC_NDEF_READ_REQ)\n", __LINE__);
    jcc_nfc_send_message(MSG_ID_NFC_NDEF_READ_REQ, MOD_NFC, INVALID_SAP, (void *)p_msg);

    return JCC_NFC_OK;
}



/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_read_internal
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_read_internal(jcc_nfc_task_message_context *tmContext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_ndef_read_req_struct *p_msg; // send readNDEF MSG
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_msg = (nfc_ndef_read_req_struct *) construct_local_para(sizeof(nfc_ndef_read_req_struct), TD_CTRL);
    jvm_trace_debug("[JSR257]jcc_nfc_read_internal: %d, lockerHandler = %d\n", __LINE__, tmContext->handle);

    ASSERT(p_msg);// judge whether MALLOC is success
    jcc_nfc_current_target_context.ndef_info.ActualNdefMsgLength = 200;

    p_msg->REQhRemoteDevice = jcc_nfc_current_target_context.Target_Handle;
    p_msg->REQpsRd = (phNfc_sData_t*)get_ctrl_buffer(sizeof(phNfc_sData_t));
    p_msg->REQpsRd->buffer = (uint8_t*)get_ctrl_buffer(jcc_nfc_current_target_context.ndef_info.ActualNdefMsgLength);
    p_msg->REQpsRd->length = jcc_nfc_current_target_context.ndef_info.ActualNdefMsgLength;

    jcc_nfc_current_target_context.ndef_message = p_msg->REQpsRd;
    jcc_nfc_current_target_context.ndef_message->buffer = p_msg->REQpsRd->buffer;
    jcc_nfc_current_target_context.ndef_message->length = jcc_nfc_current_target_context.ndef_info.ActualNdefMsgLength;

    memset(jcc_nfc_current_target_context.ndef_message->buffer, 0, jcc_nfc_current_target_context.ndef_message->length);

    jvm_trace_debug("[JSR257]jcc_nfc_read_internal: %d,NDEF_READ_REQ:jcc_nfc_current_target_context->ndef_message addr:%x\n", __LINE__, jcc_nfc_current_target_context.ndef_message);
    jvm_trace_debug("[JSR257]jcc_nfc_read_internal: %d,NDEF_READ_REQ:jcc_nfc_current_target_context->ndef_message->buffer addr:%x\n", __LINE__, jcc_nfc_current_target_context.ndef_message->buffer);
    jvm_trace_debug("[JSR257]jcc_nfc_read_internal: %d,NDEF_READ_REQ:jcc_nfc_current_target_context->ndef_message->length:%d\n", __LINE__, jcc_nfc_current_target_context.ndef_message->length);

    p_msg->REQOffset = phLibNfc_Ndef_EBegin;
    p_msg->REQpNdefRead_RspCb = (pphLibNfc_RspCb_t)jcc_nfc_dummy_callback_handler;

    tmContext->context = &jcc_nfc_current_target_context;
    p_msg->REQpContext = (void *)tmContext;

    jvm_trace_debug("[JSR257]jcc_nfc_read_internal: %d,jcc_nfc_send_message(MSG_ID_NFC_NDEF_READ_REQ)\n", __LINE__);
    jcc_nfc_send_message(MSG_ID_NFC_NDEF_READ_REQ, MOD_NFC, INVALID_SAP, (void *)p_msg);
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_transceive_config
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint32 jcc_nfc_transceive_config(kal_int32 cmd, uint8_t nb_block, char *tx_data, kal_int32 tx_data_length, nfc_remote_dev_transceive_req_struct *p_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 ret = 0;
    kal_int32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_transceive_config: %d,begin:\n", __LINE__);
    jvm_trace_debug("[JSR257]jcc_nfc_transceive_config: %d, cmd = %d, addr = %d, tx_length = %d:\n", __LINE__, cmd, nb_block, tx_data_length);

    switch (jcc_nfc_current_target_context.Target_Type)
    {
        case phNfc_eMifare_PICC:

            switch (cmd)
            {
                case JCC_NFC_CMD_MIFARE_READ_16:

                    jvm_trace_debug("[JSR257]jcc_nfc_transceive_config: %d,cmd = [JCC_NFC_CMD_MIFARE_READ_16]\n", __LINE__);
                    p_msg->REQpsTransceiveInfo->cmd.MfCmd = phNfc_eMifareRead;
                    p_msg->REQpsTransceiveInfo->addr = nb_block;

                    ret = 0;
                    break;

                case JCC_NFC_CMD_MIFARE_WRITE_16:

                    jvm_trace_debug("[JSR257]jcc_nfc_transceive_config: %d,cmd = [JCC_NFC_CMD_MIFARE_WRITE_16]\n", __LINE__);
                    if ((jcc_nfc_current_target_context.Transceive_TagType == APP_TAG_MIFARE_1K) || (jcc_nfc_current_target_context.Transceive_TagType == APP_TAG_MIFARE_4K))
                    {
                        jvm_trace_debug("[JSR257]jcc_nfc_transceive_config: %d,card type = MIFARE Classic 1K or 4K.\n", __LINE__);

                        p_msg->REQpsTransceiveInfo->cmd.MfCmd = phNfc_eMifareWrite16;
                        p_msg->REQpsTransceiveInfo->addr = nb_block;

                        ret = 0;
                        for (i = 0;i < tx_data_length;i++)
                        {
                            jcc_nfc_transceive_write_buffer[ret++] = tx_data[i];
                        }
                    }
                    else if (jcc_nfc_current_target_context.Transceive_TagType == APP_TAG_MIFARE_UL)
                    {
                        jvm_trace_debug("[JSR257]jcc_nfc_transceive_config: %d,card type = MIFARE Ultralight.\n", __LINE__);
                        p_msg->REQpsTransceiveInfo->cmd.MfCmd = phNfc_eMifareWrite4;
                        p_msg->REQpsTransceiveInfo->addr = nb_block;

                        ret = 0;
                        for (i = 0;i < tx_data_length;i++)
                        {
                            jcc_nfc_transceive_write_buffer[ret++] = tx_data[i];
                        }
                    }
                    break;

                case JCC_NFC_CMD_MIFARE_AUTH_A:

                    jvm_trace_debug("[JSR257]jcc_nfc_transceive_config: %d,cmd = [JCC_NFC_CMD_MIFARE_AUTH_A]\n", __LINE__);
                    jvm_trace_debug("[JSR257]jcc_nfc_transceive_config: %d,address = %d\n", __LINE__, nb_block);

                    p_msg->REQpsTransceiveInfo->cmd.MfCmd = phNfc_eMifareAuthentA;
                    p_msg->REQpsTransceiveInfo->addr = nb_block;

                    // Send Data = |UID|KEY_A|
                    ret = 0;
                    for (i = 0;i < jcc_nfc_current_target_context.Tag_Info.Target_UidLength;i++)
                    {
                        jcc_nfc_transceive_write_buffer[ret++] = jcc_nfc_current_target_context.Tag_Info.Target_Uid[i];
                    }

                    for (i = 0;i < tx_data_length;i++)
                    {
                        jcc_nfc_transceive_write_buffer[ret++] = tx_data[i];
                    }

                    break;

                case JCC_NFC_CMD_MIFARE_AUTH_B:

                    jvm_trace_debug("[JSR257]jcc_nfc_transceive_config: %d,cmd = [JCC_NFC_CMD_MIFARE_AUTH_B]\n", __LINE__);
                    jvm_trace_debug("[JSR257]jcc_nfc_transceive_config: %d,address = %d\n", __LINE__, nb_block);

                    p_msg->REQpsTransceiveInfo->cmd.MfCmd = phNfc_eMifareAuthentB;
                    p_msg->REQpsTransceiveInfo->addr = nb_block;

                    // Send Data = |UID|KEY_B|
                    ret = 0;
                    for (i = 0;i < jcc_nfc_current_target_context.Tag_Info.Target_UidLength;i++)
                    {
                        jcc_nfc_transceive_write_buffer[ret++] = jcc_nfc_current_target_context.Tag_Info.Target_Uid[i];
                    }

                    for (i = 0;i < tx_data_length;i++)
                    {
                        jcc_nfc_transceive_write_buffer[ret++] = tx_data[i];
                    }

                    break;

                default:
                    break;
            }

        case phNfc_eISO14443_A_PICC:

            switch (cmd)
            {
                case JCC_NFC_CMD_ISO14443_EXCHANGE_DATA:

                    jvm_trace_debug("[JSR257]jcc_nfc_transceive_config: %d,cmd = [JCC_NFC_CMD_ISO14443_EXCHANGE_DATA]\n", __LINE__);
                    p_msg->REQpsTransceiveInfo->cmd.MfCmd = phNfc_eIso14443_4_Raw;
                    p_msg->REQpsTransceiveInfo->addr = 0;

                    ret = 0;
                    for (i = 0;i < tx_data_length;i++)
                    {
                        jcc_nfc_transceive_write_buffer[ret++] = tx_data[i];
                    }

                    break;
            }

            break;

        case phNfc_eISO15693_PICC:

            switch (cmd)
            {
                case JCC_NFC_CMD_ISO15693_READ:

                    jvm_trace_debug("[JSR257]jcc_nfc_transceive_config: %d,cmd = [JCC_NFC_CMD_ISO15693_READ]\n", __LINE__);
                    jvm_trace_debug("[JSR257]jcc_nfc_transceive_config: %d,address = %d\n", __LINE__, nb_block);

                    p_msg->REQpsTransceiveInfo->cmd.MfCmd = phNfc_eIso15693_Cmd;
                    p_msg->REQpsTransceiveInfo->addr = nb_block;

                    ret = 0;
                    jcc_nfc_transceive_write_buffer[ret++] = 0x20;
                    jcc_nfc_transceive_write_buffer[ret++] = 0x20;
                    for (i = 0;i < jcc_nfc_current_target_context.Tag_Info.Target_UidLength;i++)
                    {
                        jcc_nfc_transceive_write_buffer[ret++] = jcc_nfc_current_target_context.Tag_Info.Target_Uid[i];
                    }
                    jcc_nfc_transceive_write_buffer[ret++] = nb_block;

                    break;

                case JCC_NFC_CMD_ISO15693_WRITE:

                    jvm_trace_debug("[JSR257]jcc_nfc_transceive_config: %d,cmd = [JCC_NFC_CMD_ISO15693_WRITE]\n", __LINE__);
                    jvm_trace_debug("[JSR257]jcc_nfc_transceive_config: %d,address = %d\n", __LINE__, nb_block);

                    p_msg->REQpsTransceiveInfo->cmd.MfCmd = phNfc_eIso15693_Cmd;
                    p_msg->REQpsTransceiveInfo->addr = nb_block;

                    ret = 0;
                    jcc_nfc_transceive_write_buffer[ret++] = 0x20;
                    jcc_nfc_transceive_write_buffer[ret++] = 0x21;
                    for (i = 0;i < jcc_nfc_current_target_context.Tag_Info.Target_UidLength;i++)
                    {
                        jcc_nfc_transceive_write_buffer[ret++] = jcc_nfc_current_target_context.Tag_Info.Target_Uid[i];
                    }
                    jcc_nfc_transceive_write_buffer[ret++] = nb_block;
                    for (i = 0;i < tx_data_length;i++)
                    {
                        jcc_nfc_transceive_write_buffer[ret++] = tx_data[i];
                    }

                    break;
            }

            break;
    }

    jvm_trace_debug("[JSR257]jcc_nfc_transceive_config: %d,end:\n", __LINE__);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_transceive
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
jcc_nfc_result_enum jcc_nfc_transceive(
    kal_int32 target_handle,
    kal_int32 cmd,
    kal_int32 addr,
    char *tx_data,
    kal_int32 tx_data_length,
    char *rx_data,
    kal_int32 *rx_data_length,
    void **context,
    kal_int32 lockHandler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_remote_dev_transceive_req_struct *p_msg; //send _Transceive MSG
    jcc_nfc_task_message_context *tmContext = NULL;
    int i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jcc_nfc_current_target_context.ndef_message && jcc_nfc_current_target_context.ndef_message->buffer)
    {
        free_ctrl_buffer(jcc_nfc_current_target_context.ndef_message->buffer);
    }
    if (jcc_nfc_current_target_context.ndef_message)
    {
        free_ctrl_buffer(jcc_nfc_current_target_context.ndef_message);
    }
    jcc_nfc_current_target_context.ndef_message = NULL;

    p_msg = (nfc_remote_dev_transceive_req_struct *) construct_local_para(sizeof(nfc_remote_dev_transceive_req_struct), TD_CTRL);
    ASSERT(p_msg); // judge whether MALLOC is success

    jvm_trace_debug("[JSR257]jcc_nfc_transceive: %d,begin:\n", __LINE__);
    jvm_trace_debug("[JSR257]jcc_nfc_transceive: %d, lockHandler = %d, cmd = %d, addr = %d ,tx_data_length = %d\n", __LINE__ , lockHandler, cmd, addr, tx_data_length);

    tmContext = (jcc_nfc_task_message_context *)get_ctrl_buffer(sizeof(jcc_nfc_task_message_context));
    tmContext->handle = lockHandler;

    p_msg->REQhRemoteDevice = jcc_nfc_current_target_context.Target_Handle;
    p_msg->REQpsTransceiveInfo = (phLibNfc_sTransceiveInfo_t*)get_ctrl_buffer(sizeof(phLibNfc_sTransceiveInfo_t));
    jcc_nfc_current_target_context.transceive_info = p_msg->REQpsTransceiveInfo;
    jcc_nfc_transceive_write_buffer = (kal_uint8*)get_ctrl_buffer(tx_data_length + jcc_nfc_current_target_context.Tag_Info.Target_UidLength + 3);
    jcc_nfc_transceive_read_buffer = (kal_uint8*)get_ctrl_buffer(256);
    p_msg->REQpsTransceiveInfo->sSendData.length = jcc_nfc_transceive_config(cmd, addr, tx_data, tx_data_length, p_msg);
    p_msg->REQpsTransceiveInfo->sSendData.buffer = jcc_nfc_transceive_write_buffer;
    p_msg->REQpsTransceiveInfo->sRecvData.buffer = jcc_nfc_transceive_read_buffer;
    p_msg->REQpsTransceiveInfo->sRecvData.length = 256;
    jvm_trace_debug("[JSR257]jcc_nfc_transceive: %d,send_length = %d:\n", __LINE__ , p_msg->REQpsTransceiveInfo->sSendData.length);
    for (i = 0;i < p_msg->REQpsTransceiveInfo->sSendData.length;i++)
    {
        jvm_trace_debug("[JSR257]jcc_nfc_transceive: %d,send[%d] = %x.", __LINE__, i, p_msg->REQpsTransceiveInfo->sSendData.buffer[i]);
    }

    p_msg->REQpTransceive_RspCb = (pphLibNfc_TransceiveCallback_t) jcc_nfc_dummy_callback_handler;

    tmContext->context = &jcc_nfc_current_target_context;
    p_msg->REQpContext = (void *)tmContext;

    jcc_nfc_async_lock();
    jvm_trace_debug("[JSR257]jcc_nfc_transceive: %d,jcc_nfc_send_message(MSG_ID_NFC_REMOTE_DEV_TRANSCEIVE_REQ):\n", __LINE__);
    jcc_nfc_send_message(MSG_ID_NFC_REMOTE_DEV_TRANSCEIVE_REQ, MOD_NFC, INVALID_SAP, (void *)p_msg);

    jvm_trace_debug("[JSR257]jcc_nfc_transceive: %d,end:\n", __LINE__);
    return JCC_NFC_OK;
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_connect
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_connect(kal_int32 lockHandler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_remote_dev_connect_req_struct *p_msg; // send register MSG
    jcc_nfc_task_message_context *tmContext = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_connect: %d\n", __LINE__);

    jcc_nfc_is_target_detected = KAL_FALSE;

    if (lockHandler > 0)
    {
        jcc_nfc_is_vm_connected = KAL_TRUE;
    }

    if (jcc_nfc_current_target_context.ndef_message && jcc_nfc_current_target_context.ndef_message->buffer)
    {
        free_ctrl_buffer(jcc_nfc_current_target_context.ndef_message->buffer);
    }
    if (jcc_nfc_current_target_context.ndef_message)
    {
        free_ctrl_buffer(jcc_nfc_current_target_context.ndef_message);
    }
    jcc_nfc_current_target_context.ndef_message = NULL;

    if (jcc_nfc_status.realConnected == 1)
    {
        jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_CONNECT_TARGET, lockHandler, 0);
        return;
    }

    p_msg = (nfc_remote_dev_connect_req_struct *) construct_local_para(sizeof(nfc_remote_dev_connect_req_struct), TD_CTRL);

    ASSERT(p_msg); // judge whether MALLOC is success
    p_msg->REQhRemoteDevice = jcc_nfc_current_target_context.Target_Handle;
    p_msg->REQpNotifyConnect_RspCb = (pphLibNfc_ConnectCallback_t)jcc_nfc_dummy_callback_handler;

    tmContext = (jcc_nfc_task_message_context *)get_ctrl_buffer(sizeof(jcc_nfc_task_message_context));
    tmContext->handle = lockHandler;
    tmContext->context = &jcc_nfc_current_target_context;
    tmContext->cmd = JCC_NFC_STATE_CONNECT_WITH_CHECKING_NDEF;
    p_msg->REQpContext = (void *)tmContext;

    jcc_nfc_async_lock();

    jvm_trace_debug("[JSR257]jcc_nfc_connect: %d,p_msg->REQhRemoteDevice->Target_Handle = %x\n", __LINE__, p_msg->REQhRemoteDevice);
    jvm_trace_debug("[JSR257]jcc_nfc_connect: %d,jcc_nfc_send_message(MSG_ID_NFC_REMOTE_DEV_CONNECT_REQ)\n", __LINE__);
    jcc_nfc_send_message(MSG_ID_NFC_REMOTE_DEV_CONNECT_REQ, MOD_NFC, INVALID_SAP, (void *)p_msg);
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_disconnect_internal
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_disconnect_internal(jcc_nfc_task_message_context *tmContext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_remote_dev_disconnect_req_struct *p_msg; // send register MSG
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_disconnect_internal: %d\n", __LINE__);
    jcc_nfc_is_vm_connected = KAL_FALSE;
    if (jcc_nfc_status.realConnected == 0)
    {
        if (tmContext->cmd == JCC_NFC_STATE_CLEAN_UP || tmContext->cmd == JCC_NFC_STATE_RESET || tmContext->cmd == JCC_NFC_STATE_CONNECT_WITH_CHECKING_NDEF)
        {
            jcc_nfc_tag_unregister_internal(tmContext);
        }
        else
        {
            jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_DISCONNECT_TARGET, tmContext->handle, 0);
            if (tmContext)
            {
                free_ctrl_buffer(tmContext);
            }
        }
        return;
    }

    p_msg = (nfc_remote_dev_disconnect_req_struct *) construct_local_para(sizeof(nfc_remote_dev_disconnect_req_struct), TD_CTRL);

    ASSERT(p_msg); // judge whether MALLOC is success
    p_msg->REQhRemoteDevice = jcc_nfc_current_target_context.Target_Handle;
    p_msg->REQpDscntCallback = (pphLibNfc_DisconnectCallback_t)jcc_nfc_dummy_callback_handler;
    p_msg->REQReleaseType = NFC_DISCOVERY_CONTINUE;

    jvm_trace_debug("[JSR257]jcc_nfc_send_message: %d,lockHandler = %d,disconnect target = %x\n", __LINE__
                    , tmContext->handle
                    , p_msg->REQhRemoteDevice);

    tmContext->context = &jcc_nfc_current_target_context;
    p_msg->REQpContext = (void *)tmContext;

    jvm_trace_debug("[JSR257]jcc_nfc_send_message: %d,jcc_nfc_send_message(MSG_ID_NFC_REMOTE_DEV_DISCONNECT_REQ)\n", __LINE__);
    jcc_nfc_send_message(MSG_ID_NFC_REMOTE_DEV_DISCONNECT_REQ, MOD_NFC, INVALID_SAP, (void *)p_msg);
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_disconnect
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_disconnect(kal_int32 lockHandler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jcc_nfc_task_message_context *tmContext = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_disconnect: %d\n", __LINE__);
    tmContext = (jcc_nfc_task_message_context *)get_ctrl_buffer(sizeof(jcc_nfc_task_message_context));
    tmContext->handle = lockHandler;
    tmContext->cmd = JCC_NFC_STATE_DISCONNECT;
    jcc_nfc_disconnect_internal(tmContext);
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_check_ndef
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_check_ndef(jcc_nfc_task_message_context *tmContext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_ndef_check_ndef_req_struct *p_msg; // send check NDEF REQ MSG
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_msg = (nfc_ndef_check_ndef_req_struct *)construct_local_para(sizeof(nfc_ndef_check_ndef_req_struct), TD_CTRL);
    ASSERT(p_msg); // msg_struct_nfc_req_Ndef_CheckNdef

    p_msg->REQhRemoteDevice	= jcc_nfc_current_target_context.Target_Handle;
    p_msg->REQpCheckNdef_RspCb = (pphLibNfc_ChkNdefRspCb_t)jcc_nfc_dummy_callback_handler;
    tmContext->context = &jcc_nfc_current_target_context;
    p_msg->REQpContext = tmContext;

    jvm_trace_debug("[JSR257]jcc_nfc_connect_cb_ind_handle: %d,p_msg->REQhRemoteDevice->Target_Handle:%x\n", __LINE__, p_msg->REQhRemoteDevice);
    jvm_trace_debug("[JSR257]jcc_nfc_connect_cb_ind_handle: %d,jcc_nfc_send_message(MSG_ID_NFC_NDEF_CHECK_NDEF_REQ)\n", __LINE__);
    jcc_nfc_send_message(MSG_ID_NFC_NDEF_CHECK_NDEF_REQ, MOD_NFC, INVALID_SAP, (void *)p_msg);
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_configure_discovery
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
jcc_nfc_result_enum jcc_nfc_configure_discovery(jcc_nfc_task_message_context *tmContext, kal_bool first_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_mgt_configure_discovery_req_struct *cfg_msg;//send configure discovery
    phLibNfc_sADD_Cfg_t	*cfg_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_configure_discovery: %d\n", __LINE__);

    cfg_msg = (nfc_mgt_configure_discovery_req_struct *) construct_local_para(sizeof(nfc_mgt_configure_discovery_req_struct), TD_CTRL);
    if (first_time)
    {
        cfg_msg->REQDiscoveryMode = NFC_DISCOVERY_CONFIG;
    }
    else
    {
        cfg_msg->REQDiscoveryMode = NFC_DISCOVERY_START;
    }
    cfg_ptr = (phLibNfc_sADD_Cfg_t *) & cfg_msg->REQsADDSetup;
    jcc_nfc_get_discovery_config(cfg_ptr,
                                 jcc_nfc_tag_registered_number.SERegistered,
                                 jcc_nfc_tag_registered_number.PlainRegistered,
                                 jcc_nfc_tag_registered_number.ISORegistered,
                                 jcc_nfc_tag_registered_number.NDEFRegistered);

    tmContext->context = (void *) & jcc_nfc_tag_registered_number;
    cfg_msg->REQpContext = (void *)tmContext;

    cfg_msg->REQpConfigDiscovery_RspCb = (pphLibNfc_RspCb_t)jcc_nfc_dummy_callback_handler;

    jvm_trace_debug("[JSR257]jcc_nfc_configure_discovery: %d,jcc_nfc_send_message(MSG_ID_NFC_MGT_CONFIGURE_DISCOVERY_REQ)\n", __LINE__);
    jcc_nfc_send_message(MSG_ID_NFC_MGT_CONFIGURE_DISCOVERY_REQ, MOD_NFC, INVALID_SAP, (void *)cfg_msg);
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_se_set_mode
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
jcc_nfc_result_enum jcc_nfc_se_set_mode(phLibNfc_Handle hSecureElement)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_se_set_mode_req_struct *p_msg;
    p_msg = (nfc_se_set_mode_req_struct *) construct_local_para(sizeof(nfc_se_set_mode_req_struct), TD_CTRL);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_se_set_mode %d, hSecureElement=%d \n", __LINE__, hSecureElement);

    p_msg->eActivation_mode = phLibNfc_SE_ActModeVirtual;
    p_msg->hSE_Handle = hSecureElement;
    p_msg->pSE_SetMode_Rsp_cb = (pphLibNfc_SE_SetModeRspCb_t) jcc_nfc_dummy_callback_handler;
    p_msg->REQpContext = &jcc_nfc_tag_registered_number;

    jcc_nfc_current_target_context.hSecureElement = hSecureElement;

    jcc_nfc_is_open_se_mode = KAL_TRUE;

    jvm_trace_debug("[JSR257]jcc_nfc_se_set_mode: %d, NOW SET SE MODE \n", __LINE__);
    jvm_trace_debug("[JSR257]jcc_nfc_se_set_mode: %d, p_msg->REQeActivation_mode = 0x%08X \n", __LINE__, p_msg->eActivation_mode);
    jvm_trace_debug("[JSR257]jcc_nfc_se_set_mode: %d, p_msg->REQhSE_Handle = 0x%08X \n", __LINE__, p_msg->hSE_Handle);
    jvm_trace_debug("[JSR257]jcc_nfc_se_set_mode: %d, p_msg->REQpSE_SetMode_Rsp_cb = 0x%08X \n", __LINE__, p_msg->pSE_SetMode_Rsp_cb);
    jvm_trace_debug("[JSR257]jcc_nfc_se_set_mode: %d, p_msg->REQpContext = 0x%08X \n", __LINE__, p_msg->REQpContext);

    jvm_trace_debug("[JSR257]jcc_nfc_se_set_mode: %d, jcc_nfc_send_message(MSG_ID_NFC_SE_SET_MODE_REQ)\n", __LINE__);
    jcc_nfc_send_message(MSG_ID_NFC_SE_SET_MODE_REQ, MOD_NFC, INVALID_SAP, (void *)p_msg);

    return JCC_NFC_OK;
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_se_register_rsp_handle
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_se_register_rsp_handle(ilm_struct *pData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_rsp_struct	*nfc_ind_ptr = (nfc_rsp_struct*) pData->local_para_ptr;
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jcc_nfc_current_target_context.Status = nfc_ind_ptr->RSPstatus; //NFCStatus
    jvm_trace_debug("[JSR257]jcc_nfc_se_register_rsp_handle: %d,status = %d\n", __LINE__, nfc_ind_ptr->RSPstatus);
    if (jcc_nfc_current_target_context.Status == NFCSTATUS_SUCCESS && jcc_nfc_tag_registered_number.SERegistered != 0)
    {
        jvm_trace_debug("[JSR257]jcc_nfc_se_register_rsp_handle: %d, jcc_nfc_se_count = %d\n", __LINE__, i, jcc_nfc_se_count);
        for (i = 0;i < jcc_nfc_se_count;i++)
        {
            jvm_trace_debug("[JSR257]jcc_nfc_se_register_rsp_handle: %d, jcc_nfc_se_list[%d].hSecureElement = %x\n", __LINE__, i, jcc_nfc_se_list[i].hSecureElement);
        }

        if (jcc_nfc_se_count >= 2) // temp solution
        {
            jcc_nfc_se_set_mode(jcc_nfc_se_list[1].hSecureElement);
        }
        else
        {
            jcc_nfc_se_set_mode(jcc_nfc_se_list[0].hSecureElement); // Must use jcc_nfc_se_list[0]
        }
    }
    else
    {
        jcc_nfc_async_unlock();
    }
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_register_rsp_handle
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_register_rsp_handle(ilm_struct *pData) //MSG_ID_NFC_REMOTE_DEV_NTF_REGISTER_RSP
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_rsp_struct  *nfc_ind_ptr = (nfc_rsp_struct*) pData->local_para_ptr;
    int lockerHandle = 0;
    jcc_nfc_task_message_context *tmContext = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tmContext = (jcc_nfc_task_message_context *)nfc_ind_ptr->REQpContext;
    lockerHandle = tmContext->handle;

    if (jcc_nfc_register_info)
    {
        free_ctrl_buffer(jcc_nfc_register_info);
    }

    jcc_nfc_current_target_context.Status = nfc_ind_ptr->RSPstatus; //NFCStatus

    jvm_trace_debug("[JSR257]jcc_nfc_register_rsp_handle: %d,jcc_nfc_current_target_context.Status:%d\n", __LINE__, jcc_nfc_current_target_context.Status);

    // If status is not equal to 0
    if (nfc_ind_ptr->RSPstatus != 0)
    {
        jcc_nfc_async_unlock();

        jcc_nfc_sync_lock();
        jcc_nfc_status.realRegistered = 0;
        jcc_nfc_device_state = JCC_NFC_DEVICE_INIT;
        jcc_nfc_sync_unlock();

        if (tmContext->cmd == JCC_NFC_STATE_RESET)
        {
            jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_RESET_TARGET, lockerHandle, nfc_ind_ptr->RSPstatus);
            if (jcc_nfc_terminate_vm)
            {
                if (jcc_nfc_tag_registered_number.SERegistered == 0)
                {
                    jcc_nfc_se_unregister_internal();
                }
                jcc_nfc_terminate_vm = KAL_FALSE;
            }
        }
        else if (tmContext->cmd == JCC_NFC_STATE_CONNECT_WITH_CHECKING_NDEF)
        {
            jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_CONNECT_TARGET, lockerHandle, nfc_ind_ptr->RSPstatus);
        }
        else
        {
            jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_REGISTER_TARGET, lockerHandle, nfc_ind_ptr->RSPstatus);
        }
        jvm_trace_debug("[JSR257]jcc_nfc_register_rsp_handle: %d,[UNBLOCK],because the register response is not equal to 0.\n", __LINE__);

        if (tmContext)
        {
            free_ctrl_buffer(tmContext);
        }
        return;
    }

    jvm_trace_debug("[JSR257]jcc_nfc_register_rsp_handle: %d\n", __LINE__);

    //tmContext->cmd = 0;
    jcc_nfc_configure_discovery(tmContext, KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_register_cb_ind_handle
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_register_cb_ind_handle(ilm_struct *pData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_remote_dev_ntf_register_cb_ind_struct *nfc_ind_ptr = (nfc_remote_dev_ntf_register_cb_ind_struct*) pData->local_para_ptr;
    int i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_register_cb_ind_handle: %d, the initiator has found the target now.\n", __LINE__);

    jcc_nfc_device_state = JCC_NFC_DEVICE_CONNECT;
    jcc_nfc_current_target_context.Status = nfc_ind_ptr->CBIStatus; //NFCStatus
    jvm_trace_debug("[JSR257]jcc_nfc_register_cb_ind_handle: %d, jcc_nfc_current_target_context.Status:%d\n", __LINE__, jcc_nfc_current_target_context.Status);

    if (jcc_nfc_current_target_context.Status == NFCSTATUS_SUCCESS ||
            jcc_nfc_current_target_context.Status == NFCSTATUS_MULTIPLE_PROTOCOLS ||
            jcc_nfc_current_target_context.Status == NFCSTATUS_MULTIPLE_TAGS)
    {
        if (jcc_nfc_current_target_context.Status == NFCSTATUS_MULTIPLE_PROTOCOLS)
        {
            jvm_trace_debug("[JSR257]jcc_nfc_register_cb_ind_handle: %d,Tag with Multiple protocols (e.g. SMX)\n", __LINE__);
            jvm_trace_debug("[JSR257]jcc_nfc_register_cb_ind_handle: %d,length = %d\n", __LINE__, nfc_ind_ptr->CBIuNofRemoteDev);

            jcc_nfc_sync_lock();
            if (jcc_nfc_tag_registered_number.ISORegistered > 0)
            {
                jcc_nfc_sync_unlock();
                jvm_trace_debug("[JSR257]jcc_nfc_register_cb_ind_handle: %d, search target ISO14443.", __LINE__);
                for (i = 0;i < nfc_ind_ptr->CBIuNofRemoteDev;i++)
                {
                    jvm_trace_debug("[JSR257]jcc_nfc_register_cb_ind_handle: %d, target type[%d] = %d\n", __LINE__, i, nfc_ind_ptr->CBIpsRemoteDevList[i].psRemoteDevInfo->RemDevType);
                    if (nfc_ind_ptr->CBIpsRemoteDevList[i].psRemoteDevInfo->RemDevType == 9)
                    {
                        jvm_trace_debug("[JSR257]jcc_nfc_register_cb_ind_handle: %d, select target type = %d", __LINE__, nfc_ind_ptr->CBIpsRemoteDevList[i].psRemoteDevInfo->RemDevType);
                        jcc_nfc_current_target_context.Target_Handle = nfc_ind_ptr->CBIpsRemoteDevList[i].hTargetDev;
                        jcc_nfc_current_target_context.Target_Type = nfc_ind_ptr->CBIpsRemoteDevList[i].psRemoteDevInfo->RemDevType;
                        jcc_nfc_current_target_context.RemoteDev = nfc_ind_ptr->CBIpsRemoteDevList[i];
                        break;
                    }
                }
            }
            else
            {
                jcc_nfc_sync_unlock();
                jvm_trace_debug("[JSR257]jcc_nfc_register_cb_ind_handle: %d, search target non-ISO14443.", __LINE__);
                jcc_nfc_current_target_context.Target_Handle = nfc_ind_ptr->CBIpsRemoteDevList[0].hTargetDev;
                jcc_nfc_current_target_context.Target_Type = nfc_ind_ptr->CBIpsRemoteDevList[0].psRemoteDevInfo->RemDevType;
                jcc_nfc_current_target_context.RemoteDev = nfc_ind_ptr->CBIpsRemoteDevList[0];

                for (i = 0;i < nfc_ind_ptr->CBIuNofRemoteDev;i++)
                {
                    jvm_trace_debug("[JSR257]jcc_nfc_register_cb_ind_handle: %d, target type[%d] = %d\n", __LINE__, i, nfc_ind_ptr->CBIpsRemoteDevList[i].psRemoteDevInfo->RemDevType);
                    if (nfc_ind_ptr->CBIpsRemoteDevList[i].psRemoteDevInfo->RemDevType != 9)
                    {
                        jvm_trace_debug("[JSR257]jcc_nfc_register_cb_ind_handle: %d, select target type = %d", __LINE__, nfc_ind_ptr->CBIpsRemoteDevList[i].psRemoteDevInfo->RemDevType);
                        jcc_nfc_current_target_context.Target_Handle = nfc_ind_ptr->CBIpsRemoteDevList[i].hTargetDev;
                        jcc_nfc_current_target_context.Target_Type = nfc_ind_ptr->CBIpsRemoteDevList[i].psRemoteDevInfo->RemDevType;
                        jcc_nfc_current_target_context.RemoteDev = nfc_ind_ptr->CBIpsRemoteDevList[i];
                        break;
                    }
                }
            }
        }
        else
        {
            jvm_trace_debug("[JSR257]jcc_nfc_register_cb_ind_handle: %d, save index 0\n", __LINE__);
            jcc_nfc_current_target_context.Target_Handle = nfc_ind_ptr->CBIpsRemoteDevList[0].hTargetDev;
            jcc_nfc_current_target_context.Target_Type = nfc_ind_ptr->CBIpsRemoteDevList[0].psRemoteDevInfo->RemDevType;
            jcc_nfc_current_target_context.RemoteDev = nfc_ind_ptr->CBIpsRemoteDevList[0];
        }

        jvm_trace_debug("[JSR257]jcc_nfc_register_cb_ind_handle: %d,Target_Handle = %x\n", __LINE__, jcc_nfc_current_target_context.Target_Handle);
        jvm_trace_debug("[JSR257]jcc_nfc_register_cb_ind_handle: %d,Target_Type = %d\n", __LINE__, jcc_nfc_current_target_context.Target_Type);

        //////////////////////////////////////////////////////////////////////////////////////////
        // Add for transceive used
        switch (jcc_nfc_current_target_context.RemoteDev.psRemoteDevInfo->RemDevType)
        {
            case phNfc_eISO15693_PICC:

                jcc_nfc_current_target_context.Tag_Info.Target_UidLength = nfc_ind_ptr->CBIpsRemoteDevList[0].psRemoteDevInfo->RemoteDevInfo.Iso15693_Info.UidLength;
                jvm_trace_debug("[JSR257]jcc_nfc_register_cb_ind_handle: %d,jcc_nfc_current_target_context.Tag_Info.Target_SAK = 0x%x \n", __LINE__, jcc_nfc_current_target_context.Tag_Info.Target_SAK);
                jvm_trace_debug("[JSR257]jcc_nfc_register_cb_ind_handle: %d,jcc_nfc_current_target_context.Tag_Info.Target_UidLength = %d \n", __LINE__, jcc_nfc_current_target_context.Tag_Info.Target_UidLength);
                for (i = 0;i < jcc_nfc_current_target_context.Tag_Info.Target_UidLength;i++)
                {
                    jcc_nfc_current_target_context.Tag_Info.Target_Uid[i] = nfc_ind_ptr->CBIpsRemoteDevList[0].psRemoteDevInfo->RemoteDevInfo.Iso15693_Info.Uid[i];
                    jvm_trace_debug("[JSR257]jcc_nfc_register_cb_ind_handle: %d,jcc_nfc_current_target_context.Tag_Info.Target_Uid[%d] = 0x%x \n", __LINE__, i, jcc_nfc_current_target_context.Tag_Info.Target_Uid[i]);
                }

                break;

            default:

                jcc_nfc_current_target_context.Tag_Info.Target_SAK = nfc_ind_ptr->CBIpsRemoteDevList[0].psRemoteDevInfo->RemoteDevInfo.Iso14443A_Info.Sak;
                jcc_nfc_current_target_context.Tag_Info.Target_UidLength = nfc_ind_ptr->CBIpsRemoteDevList[0].psRemoteDevInfo->RemoteDevInfo.Iso14443A_Info.UidLength;
                jvm_trace_debug("[JSR257]jcc_nfc_register_cb_ind_handle: %d,jcc_nfc_current_target_context.Tag_Info.Target_SAK = 0x%x \n", __LINE__, jcc_nfc_current_target_context.Tag_Info.Target_SAK);
                jvm_trace_debug("[JSR257]jcc_nfc_register_cb_ind_handle: %d,jcc_nfc_current_target_context.Tag_Info.Target_UidLength = %d \n", __LINE__, jcc_nfc_current_target_context.Tag_Info.Target_UidLength);
                for (i = 0;i < jcc_nfc_current_target_context.Tag_Info.Target_UidLength;i++)
                {
                    jcc_nfc_current_target_context.Tag_Info.Target_Uid[i] = nfc_ind_ptr->CBIpsRemoteDevList[0].psRemoteDevInfo->RemoteDevInfo.Iso14443A_Info.Uid[i];
                    jvm_trace_debug("[JSR257]jcc_nfc_register_cb_ind_handle: %d,jcc_nfc_current_target_context.Tag_Info.Target_Uid[%d] = 0x%x \n", __LINE__, i, jcc_nfc_current_target_context.Tag_Info.Target_Uid[i]);
                }

                jvm_trace_debug("[JSR257]jcc_nfc_register_cb_ind_handle: %d,jcc_nfc_current_target_context.Tag_Info.Target_SAK:%x\n", __LINE__, jcc_nfc_current_target_context.Tag_Info.Target_SAK);
                if (jcc_nfc_current_target_context.Tag_Info.Target_SAK  == 0x08)
                {
                    jcc_nfc_current_target_context.Transceive_TagType = APP_TAG_MIFARE_1K;
                    jvm_trace_debug("[JSR257]jcc_nfc_register_cb_ind_handle: %d,>>>>>>>>>>>>TYPE MIFARE 1K<<<<<<<<<<<\n", __LINE__);
                }
                else if (jcc_nfc_current_target_context.Tag_Info.Target_SAK  == 0x18)
                {
                    jcc_nfc_current_target_context.Transceive_TagType = APP_TAG_MIFARE_4K;
                    jvm_trace_debug("[JSR257]jcc_nfc_register_cb_ind_handle: %d,>>>>>>>>>>>>TYPE MIFARE 4K<<<<<<<<<<<\n", __LINE__);
                }
                else if (jcc_nfc_current_target_context.Tag_Info.Target_SAK  == 0x00)
                {
                    jcc_nfc_current_target_context.Transceive_TagType  = APP_TAG_MIFARE_UL;
                    jvm_trace_debug("[JSR257]jcc_nfc_register_cb_ind_handle: %d,>>>>>>>>>>>>TYPE MIFARE UL<<<<<<<<<<<\n", __LINE__);
                }
                else if (jcc_nfc_current_target_context.Tag_Info.Target_SAK == 0x28)
                {
                    jvm_trace_debug("[JSR257]jcc_nfc_register_cb_ind_handle: %d,>>>>>>>>>>>>TYPE JCOP/ISO14443A-4<<<<<<<<<<<\n", __LINE__);
                }
                else if (jcc_nfc_current_target_context.Tag_Info.Target_SAK == 0x20)
                {
                    jcc_nfc_current_target_context.Transceive_TagType  = APP_TAG_MIFARE_DESFIRE;
                    jvm_trace_debug("[JSR257]jcc_nfc_register_cb_ind_handle: %d,>>>>>>>>>>>>TYPE DESFire/ISO14443A-4<<<<<<<<<<<\n", __LINE__);
                }

                break;
        }

        ///////////////////////////////////////////////////////////////////////////////////////////
        jcc_nfc_is_vm_connected = KAL_FALSE;
        if (jcc_nfc_tag_registered_number.NDEFRegistered == 0 ||
                jcc_nfc_tag_registered_number.NDEFRegistered > jcc_nfc_tag_registered_number.PushNDEFRegistered)
        {
            jcc_nfc_is_target_detected = KAL_TRUE;
        }
        else
        {
            jcc_nfc_connect(0);
        }
    }
    else if (jcc_nfc_current_target_context.Status == NFCSTATUS_DESELECTED)
    {
        jvm_trace_debug("[JSR257]>>>>>Put a TAG CLOSE TO PN544 & USE EXTERNAL Reader for the UICC\n");
    }
    else
    {
        jvm_trace_debug("[JSR257]Tag detection ERROR\n");
    }
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_unregister_rsp_handle
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_unregister_rsp_handle(ilm_struct *pData) //MSG_ID_NFC_REMOTE_DEV_NTF_UNREGISTER_RSP
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int lockerHandle = 0;
    jcc_nfc_task_message_context *tmContext = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nfc_rsp_struct *nfc_ind_ptr = (nfc_rsp_struct*) pData->local_para_ptr;
    jvm_trace_debug("[JSR257]jcc_nfc_unregister_rsp_handle: %d,nfc_ind_ptr->REQpContext = %p\n", __LINE__, nfc_ind_ptr->REQpContext);

    tmContext = (jcc_nfc_task_message_context *)nfc_ind_ptr->REQpContext;
    lockerHandle = tmContext->handle;
    jvm_trace_debug("[JSR257]jcc_nfc_unregister_rsp_handle: %d,status = %d,lockHandler = %d\n" , __LINE__, nfc_ind_ptr->RSPstatus, lockerHandle);

    jcc_nfc_current_target_context.Status = nfc_ind_ptr->RSPstatus; // NFCStatus

    // register again
    if (tmContext->cmd == JCC_NFC_STATE_RESET ||
            tmContext->cmd == JCC_NFC_STATE_CONNECT_WITH_CHECKING_NDEF ||
            tmContext->cmd == JCC_NFC_STATE_CHECK_PRESENCE_BY_PUSH)
    {
        jcc_nfc_tag_register(tmContext);
        return;
    }
    else if (tmContext->cmd == JCC_NFC_STATE_CLEAN_UP)
    {
        jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_CLEANUP_TARGET, lockerHandle, nfc_ind_ptr->RSPstatus);
    }

    jcc_nfc_async_unlock();

    jcc_nfc_sync_lock();
    jcc_nfc_status.realRegistered = 0;
    jcc_nfc_sync_unlock();

    if (tmContext)
    {
        free_ctrl_buffer(tmContext);
        jvm_trace_debug("[JSR257]jcc_nfc_unregister_rsp_handle: %d,free memory.\n" , __LINE__);
    }

    jcc_nfc_device_state = JCC_NFC_DEVICE_INIT;

    jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_UNREGISTER_TARGET, lockerHandle, nfc_ind_ptr->RSPstatus);
    jvm_trace_debug("[JSR257]jcc_nfc_unregister_rsp_handle: %d,[UNBLOCK] = %d\n" , __LINE__, lockerHandle);
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_connect_rsp_handle
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_connect_rsp_handle(ilm_struct *pData)  //MSG_ID_NFC_REMOTE_DEV_CONNECT_RSP
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_rsp_struct *nfc_ind_ptr = (nfc_rsp_struct*) pData->local_para_ptr;
    int lockerHandle = 0;
    jcc_nfc_task_message_context *tmContext = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jcc_nfc_current_target_context.Status = nfc_ind_ptr->RSPstatus; // NFCStatus

    tmContext = (jcc_nfc_task_message_context *)nfc_ind_ptr->REQpContext;
    lockerHandle = tmContext->handle;

    jvm_trace_debug("[JSR257]jcc_nfc_connect_rsp_handle: %d,status = %d,lockerHandle = %d\n", __LINE__, nfc_ind_ptr->RSPstatus, lockerHandle);

    if (nfc_ind_ptr->RSPstatus != 0 && nfc_ind_ptr->RSPstatus != 13)
    {
        jcc_nfc_reset_internal(tmContext);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_connect_cb_ind_handle
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_connect_cb_ind_handle(ilm_struct *pData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_remote_dev_connect_cb_ind_struct *nfc_ind_ptr = (nfc_remote_dev_connect_cb_ind_struct*) pData->local_para_ptr;
    int lockerHandle = 0;
    jcc_nfc_task_message_context *tmContext = NULL;
    int cmd = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_connect_cb_ind_handle: %d,status = %d.\n", __LINE__, nfc_ind_ptr->CBIStatus);

    tmContext = (jcc_nfc_task_message_context *)nfc_ind_ptr->CBIpContext;
    lockerHandle = tmContext->handle;
    jcc_nfc_current_target_context.CBIpContext = tmContext->context; // void*
    jvm_trace_debug("[JSR257]jcc_nfc_connect_cb_ind_handle: %d,CBIpContext:%s\n", __LINE__, jcc_nfc_current_target_context.CBIpContext);

    jcc_nfc_current_target_context.RemoteDev.hTargetDev = nfc_ind_ptr->CBIhRemoteDev; // int phLibNfc_Handle

    jvm_trace_debug("[JSR257]jcc_nfc_connect_cb_ind_handle: %d,nfc_ind_ptr->CBhRemoteDev:%x\n", __LINE__, nfc_ind_ptr->CBIhRemoteDev);
    jvm_trace_debug("[JSR257]jcc_nfc_connect_cb_ind_handle: %d,jcc_nfc_current_target_context.RemoteDev.hTargetDev:%x\n", __LINE__, jcc_nfc_current_target_context.RemoteDev.hTargetDev);
    jvm_trace_debug("[JSR257]jcc_nfc_connect_cb_ind_handle: %d,jcc_nfc_current_target_context.Target_Handle:%x\n", __LINE__, jcc_nfc_current_target_context.Target_Handle);

    jcc_nfc_current_target_context.Status = nfc_ind_ptr->CBIStatus; //NFCStatus

    jcc_nfc_sync_lock();
    jcc_nfc_status.realConnected = 1;
    jcc_nfc_sync_unlock();

    if (nfc_ind_ptr->CBIStatus != 0)
    {
        //jcc_nfc_reset_internal(tmContext);
        jcc_nfc_configure_discovery(tmContext, KAL_FALSE);
        return;
    }

    jcc_nfc_check_ndef(tmContext);
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_close_rsp_handle
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_close_rsp_handle(ilm_struct *pData) //MSG_ID_NFC_REMOTE_DEV_DISCONNECT_RSP
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_rsp_struct *nfc_ind_ptr = (nfc_rsp_struct*) pData->local_para_ptr;
    jcc_nfc_task_message_context *tmContext = NULL;
    int lockerHandle = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    tmContext = (jcc_nfc_task_message_context *)nfc_ind_ptr->REQpContext;
    lockerHandle = tmContext->handle;
    jvm_trace_debug("[JSR257]jcc_nfc_close_rsp_handle: %d,status = %d,lockHandler = %d\n" , __LINE__
                    , nfc_ind_ptr->RSPstatus
                    , lockerHandle);

    if (jcc_nfc_current_target_context.ndef_message && jcc_nfc_current_target_context.ndef_message->buffer)
    {
        free_ctrl_buffer(jcc_nfc_current_target_context.ndef_message->buffer);
    }
    if (jcc_nfc_current_target_context.ndef_message)
    {
        free_ctrl_buffer(jcc_nfc_current_target_context.ndef_message);
    }
    jcc_nfc_current_target_context.ndef_message = NULL;

    jcc_nfc_current_target_context.Status = nfc_ind_ptr->RSPstatus; // NFCStatus
    if (nfc_ind_ptr->RSPstatus != 13)
    {
        jcc_nfc_configure_discovery(tmContext, KAL_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_close_cb_ind_handle
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_close_cb_ind_handle(ilm_struct *pData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_remote_dev_disconnect_cb_ind_struct *nfc_ind_ptr = (nfc_remote_dev_disconnect_cb_ind_struct*) pData->local_para_ptr;
    jcc_nfc_task_message_context *tmContext = NULL;
    int lockerHandle = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tmContext = (jcc_nfc_task_message_context *)nfc_ind_ptr->CBIpContext;
    lockerHandle = tmContext->handle;
    jvm_trace_debug("[JSR257]jcc_nfc_close_cb_ind_handle: %d,status = %d,lockHandler = %d\n" , __LINE__
                    , nfc_ind_ptr->CBIStatus
                    , lockerHandle);

    jcc_nfc_current_target_context.CBIpContext = tmContext->context; // void*
    (jcc_nfc_current_target_context.RemoteDev).hTargetDev = nfc_ind_ptr->CBIhRemoteDev; // int phLibNfc_Handle
    jcc_nfc_current_target_context.Status = nfc_ind_ptr->CBIStatus; // NFCStatus


    jcc_nfc_sync_lock();
    jcc_nfc_status.realConnected = 0;
    jcc_nfc_sync_unlock();

    if (tmContext->cmd == JCC_NFC_STATE_CLEAN_UP ||
            tmContext->cmd == JCC_NFC_STATE_RESET ||
            tmContext->cmd == JCC_NFC_STATE_CONNECT_WITH_CHECKING_NDEF ||
            tmContext->cmd == JCC_NFC_STATE_CHECK_PRESENCE_BY_PUSH)
    {
        jcc_nfc_tag_unregister_internal(tmContext);
    }
    else
    {
        jcc_nfc_device_state = JCC_NFC_DEVICE_DETECT_TARGET;
        jcc_nfc_async_unlock();
        jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_DISCONNECT_TARGET, lockerHandle, nfc_ind_ptr->CBIStatus);

        if (tmContext != NULL)
        {
            free_ctrl_buffer(tmContext);
            tmContext = NULL;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_write_ndef_rsp_handle
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_write_ndef_rsp_handle(ilm_struct *pData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int lockerHandle = 0;
    jcc_nfc_task_message_context *tmContext = NULL;
    nfc_rsp_struct *nfc_ind_ptr = (nfc_rsp_struct*) pData->local_para_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_write_ndef_rsp_handle: %d\n", __LINE__);
    tmContext = (jcc_nfc_task_message_context *)nfc_ind_ptr->REQpContext;
    lockerHandle = tmContext->handle;

    jcc_nfc_current_target_context.Status = nfc_ind_ptr->RSPstatus; // NFCStatus
    jvm_trace_debug("[JSR257]jcc_nfc_write_ndef_rsp_handle: %d, status = %d, lockHandler = \n", __LINE__, nfc_ind_ptr->RSPstatus , lockerHandle);

    // error occurred
    if (nfc_ind_ptr->RSPstatus != 13/* && nfc_ind_ptr->RSPstatus != 0*/)
    {
        jcc_nfc_async_unlock();

        if (jcc_nfc_current_target_context.ndef_message && jcc_nfc_current_target_context.ndef_message->buffer)
        {
            free_ctrl_buffer(jcc_nfc_current_target_context.ndef_message->buffer);
        }
        if (jcc_nfc_current_target_context.ndef_message)
        {
            free_ctrl_buffer(jcc_nfc_current_target_context.ndef_message);
        }
        jcc_nfc_current_target_context.ndef_message = NULL;

        if (nfc_ind_ptr->RSPstatus == 0)
        {
            jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_TAG_WRITE, lockerHandle, NFCSTATUS_FAILED);
        }
        else
        {
            jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_TAG_WRITE, lockerHandle, nfc_ind_ptr->RSPstatus);
        }
        jvm_trace_debug("[JSR257]jcc_nfc_write_ndef_rsp_handle: %d,[UNBLOCK] = %d\n", __LINE__, lockerHandle);

        if (tmContext)
        {
            free_ctrl_buffer(tmContext);
        }
        jvm_trace_debug("[JSR257]jcc_nfc_write_ndef_rsp_handle: %d, free tmContext.\n", __LINE__);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_write_ndef_cb_ind_handle
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_write_ndef_cb_ind_handle(ilm_struct *pData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jcc_nfc_task_message_context *tmContext = NULL;
    int lockHandler = 0;
    nfc_ndef_write_cb_ind_struct *nfc_ind_ptr = (nfc_ndef_write_cb_ind_struct*) pData->local_para_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_write_ndef_cb_ind_handle %d \n ", __LINE__);

    jcc_nfc_current_target_context.Status = nfc_ind_ptr->CBIStatus; // NFCStatus

    tmContext = (jcc_nfc_task_message_context *)nfc_ind_ptr->CBIpContext;
    jcc_nfc_current_target_context.CBIpContext = tmContext->context;
    lockHandler = tmContext->handle;

    jcc_nfc_async_unlock();

    if (jcc_nfc_current_target_context.ndef_message && jcc_nfc_current_target_context.ndef_message->buffer)
    {
        free_ctrl_buffer(jcc_nfc_current_target_context.ndef_message->buffer);
    }
    if (jcc_nfc_current_target_context.ndef_message)
    {
        free_ctrl_buffer(jcc_nfc_current_target_context.ndef_message);
    }
    jcc_nfc_current_target_context.ndef_message = NULL;

    if (tmContext)
    {
        free_ctrl_buffer(tmContext);
    }
    jvm_trace_debug("[JSR257]jcc_nfc_write_ndef_cb_ind_handle: %d,free tmContext.\n", __LINE__);
    jvm_trace_debug("[JSR257]jcc_nfc_write_ndef_cb_ind_handle: %d,status = %d, locker handler = %d\n", __LINE__, nfc_ind_ptr->CBIStatus, lockHandler);

    jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_TAG_WRITE, lockHandler, jcc_nfc_current_target_context.Status);
    jvm_trace_debug("[JSR257]jcc_nfc_write_ndef_cb_ind_handle %d,[UNBLOCK] = %d\n", __LINE__, lockHandler);
}



/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_read_ndef_rsp_handle
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_read_ndef_rsp_handle(ilm_struct *pData) //MSG_ID_NFC_NDEF_READ_RSP
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int lockerHandle = 0;
    jcc_nfc_task_message_context *tmContext = NULL;
    nfc_rsp_struct *nfc_ind_ptr = (nfc_rsp_struct*) pData->local_para_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_read_ndef_rsp_handle: %d\n", __LINE__);
    tmContext = (jcc_nfc_task_message_context *)nfc_ind_ptr->REQpContext;
    lockerHandle = tmContext->handle;

    jcc_nfc_current_target_context.Status = nfc_ind_ptr->RSPstatus; // NFCStatus
    jvm_trace_debug("[JSR257]jcc_nfc_read_ndef_rsp_handle: %d,nfc_ind_ptr->RSPstatus = %d,lockHandler = %d\n", __LINE__, nfc_ind_ptr->RSPstatus, lockerHandle);

    // If error has been found
    if (nfc_ind_ptr->RSPstatus != 13/* && nfc_ind_ptr->RSPstatus != 0*/)
    {
        jcc_nfc_async_unlock();

        if (jcc_nfc_current_target_context.ndef_message && jcc_nfc_current_target_context.ndef_message->buffer)
        {
            free_ctrl_buffer(jcc_nfc_current_target_context.ndef_message->buffer);
        }
        if (jcc_nfc_current_target_context.ndef_message)
        {
            free_ctrl_buffer(jcc_nfc_current_target_context.ndef_message);
        }
        jcc_nfc_current_target_context.ndef_message = NULL;

        if (nfc_ind_ptr->RSPstatus == 0)
        {
            jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_TAG_READ, lockerHandle, NFCSTATUS_FAILED);
        }
        else
        {
            jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_TAG_READ, lockerHandle, nfc_ind_ptr->RSPstatus);
        }
        jvm_trace_debug("[JSR257]jcc_nfc_read_ndef_rsp_handle: %d,[UNBLOCK] = %d.", __LINE__, lockerHandle);

        if (tmContext->cmd == JCC_NFC_STATE_CONNECT_WITH_CHECKING_NDEF)
        {
            if (jcc_nfc_current_target_context.ndef_message && jcc_nfc_current_target_context.ndef_message->buffer)
            {
                free_ctrl_buffer(jcc_nfc_current_target_context.ndef_message->buffer);
            }
            if (jcc_nfc_current_target_context.ndef_message)
            {
                free_ctrl_buffer(jcc_nfc_current_target_context.ndef_message);
            }
            jcc_nfc_current_target_context.ndef_message = NULL;

            if (jcc_nfc_tag_registered_number.NDEFRegistered == jcc_nfc_tag_registered_number.PushNDEFRegistered)
            {
                jvm_trace_debug("[JSR257]jcc_nfc_read_ndef_rsp_handle: %d, disconnect \n", __LINE__);
                jcc_nfc_disconnect_internal(tmContext);
                return;
            }
            else
            {
                jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_CONNECT_TARGET, lockerHandle, NFCSTATUS_FAILED);
                jvm_trace_debug("[JSR257]jcc_nfc_read_ndef_rsp_handle: %d,[UNBLOCK] = %d.\n", __LINE__, lockerHandle);
            }
        }

        if (tmContext)
        {
            free_ctrl_buffer(tmContext);
        }
        jvm_trace_debug("[JSR257]jcc_nfc_read_ndef_rsp_handle: %d,free the tmContext.", __LINE__);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_read_ndef_cb_ind_handle
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_read_ndef_cb_ind_handle(ilm_struct *pData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_ndef_read_cb_ind_struct *nfc_ind_ptr = (nfc_ndef_read_cb_ind_struct*) pData->local_para_ptr;
    int i;
    int lockerHandle = 0;
    jcc_nfc_task_message_context *tmContext = NULL;
    kal_bool pushed = KAL_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_read_ndef_cb_ind_handle: %d \n ", __LINE__);

    tmContext = (jcc_nfc_task_message_context *)nfc_ind_ptr->CBIpContext;
    lockerHandle = tmContext->handle;

    jcc_nfc_async_unlock();

    jvm_trace_debug("[JSR257]jcc_nfc_read_ndef_cb_ind_handle: %d,free the tmContext.\n ", __LINE__);

    jvm_trace_debug("[JSR257]jcc_nfc_read_ndef_cb_ind_handle: %d,status = %d,lockHandler = %d.\n", __LINE__, nfc_ind_ptr->CBIStatus, lockerHandle);
    jvm_trace_debug("[JSR257]jcc_nfc_read_ndef_cb_ind_handle: %d,jcc_nfc_current_target_context.ndef_message:%x\n", __LINE__, jcc_nfc_current_target_context.ndef_message);
    jvm_trace_debug("[JSR257]jcc_nfc_read_ndef_cb_ind_handle: %d,jcc_nfc_current_target_context.ndef_message->length:%d\n", __LINE__, jcc_nfc_current_target_context.ndef_message->length);
    jvm_trace_debug("[JSR257]jcc_nfc_read_ndef_cb_ind_handle: %d,jcc_nfc_current_target_context.ndef_message->buffer:%x\n", __LINE__, jcc_nfc_current_target_context.ndef_message->buffer);

    jcc_nfc_current_target_context.Status = nfc_ind_ptr->CBIStatus; // NFCStatus

    if (nfc_ind_ptr->CBIStatus == 0 && tmContext->cmd == JCC_NFC_STATE_CONNECT_WITH_CHECKING_NDEF)
    {
        pushed = j2me_process_recvd_nfc_ind(nfc_ind_ptr->Tnf, nfc_ind_ptr->Type, nfc_ind_ptr->TypeLength);

        if (jcc_nfc_current_target_context.ndef_message && jcc_nfc_current_target_context.ndef_message->buffer)
        {
            free_ctrl_buffer(jcc_nfc_current_target_context.ndef_message->buffer);
        }
        if (jcc_nfc_current_target_context.ndef_message)
        {
            free_ctrl_buffer(jcc_nfc_current_target_context.ndef_message);
        }
        jcc_nfc_current_target_context.ndef_message = NULL;

        if (jam_mvm_get_running_count() > 0 &&
                (jcc_nfc_tag_registered_number.NDEFRegistered > jcc_nfc_tag_registered_number.PushNDEFRegistered ||
                 jcc_nfc_tag_registered_number.PlainRegistered > 0 ||
                 jcc_nfc_tag_registered_number.ISORegistered > 0))
        {
            if (lockerHandle == 0)
            {
                jcc_nfc_is_target_detected = KAL_TRUE;
            }
            jvm_post_nfc_target_detected_event(CONTACTLESS_TYPE_TARGET_DETECTED, (int)jcc_nfc_current_target_context.Target_Handle);
            jvm_trace_debug("[JSR257]jcc_nfc_read_ndef_cb_ind_handle: %d, postUserEventMessage() DONE!!! \n", __LINE__);
            jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_CONNECT_TARGET, lockerHandle, nfc_ind_ptr->CBIStatus);
        }

        if (pushed)
        {
            //Avoid the case that jcc_nfc_push_tm_context get muliple ctrl buffer but jcc_nfc_push_execution_callback is not executed.
            if ( jcc_nfc_push_tm_context )
            {
                free_ctrl_buffer(jcc_nfc_push_tm_context);
                jcc_nfc_push_tm_context = NULL;
            }
            jcc_nfc_push_tm_context = tmContext;
            return;
        }
        else if (jcc_nfc_tag_registered_number.NDEFRegistered == jcc_nfc_tag_registered_number.PushNDEFRegistered)
        {
            jvm_trace_debug("[JSR257]jcc_nfc_read_ndef_cb_ind_handle: %d, disconnect \n", __LINE__);
            jcc_nfc_disconnect_internal(tmContext);
            return;
        }
    }
    else
    {
        if (nfc_ind_ptr->CBIStatus != 0)
        {
            if (jcc_nfc_current_target_context.ndef_message && jcc_nfc_current_target_context.ndef_message->buffer)
            {
                free_ctrl_buffer(jcc_nfc_current_target_context.ndef_message->buffer);
            }
            if (jcc_nfc_current_target_context.ndef_message)
            {
                free_ctrl_buffer(jcc_nfc_current_target_context.ndef_message);
            }
            jcc_nfc_current_target_context.ndef_message = NULL;
        }

        if (tmContext->cmd == JCC_NFC_STATE_CONNECT_WITH_CHECKING_NDEF)
        {
            if (jcc_nfc_tag_registered_number.NDEFRegistered == jcc_nfc_tag_registered_number.PushNDEFRegistered)
            {
                jvm_trace_debug("[JSR257]jcc_nfc_read_ndef_cb_ind_handle: %d, disconnect \n", __LINE__);
                jcc_nfc_disconnect_internal(tmContext);
                return;
            }
            else
            {
                jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_CONNECT_TARGET, lockerHandle, nfc_ind_ptr->CBIStatus);
                jvm_trace_debug("[JSR257]jcc_nfc_read_ndef_cb_ind_handle: %d,[UNBLOCK] = %d.\n", __LINE__, lockerHandle);
            }
        }
        else
        {
            jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_TAG_READ, lockerHandle, nfc_ind_ptr->CBIStatus);
            jvm_trace_debug("[JSR257]jcc_nfc_read_ndef_cb_ind_handle: %d,[UNBLOCK] = %d.\n", __LINE__, lockerHandle);
        }
    }

    if (tmContext)
    {
        free_ctrl_buffer(tmContext);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_get_read_ndef_data
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8* jcc_nfc_get_read_ndef_data(kal_uint32 *length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8* ret = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jcc_nfc_current_target_context.ndef_message && jcc_nfc_current_target_context.ndef_message->buffer)
    {
        ret = jcc_nfc_current_target_context.ndef_message->buffer;
        *length = jcc_nfc_current_target_context.ndef_message->length;
    }

    /*if (jcc_nfc_current_target_context.ndef_message)
    {
        free_ctrl_buffer(jcc_nfc_current_target_context.ndef_message);
    }
    jcc_nfc_current_target_context.ndef_message = NULL;*/

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_transceive_rsp_handle
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_transceive_rsp_handle(ilm_struct *pData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int lockerHandle = 0;
    jcc_nfc_task_message_context *tmContext = NULL;
    nfc_rsp_struct *nfc_ind_ptr = (nfc_rsp_struct*) pData->local_para_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tmContext = (jcc_nfc_task_message_context *)nfc_ind_ptr->REQpContext;
    lockerHandle = tmContext->handle;

    jvm_trace_debug("[JSR257]jcc_nfc_transceive_rsp_handle: %d,status = %d,lockHandler = %d.\n", __LINE__, nfc_ind_ptr->RSPstatus, lockerHandle);
    jcc_nfc_current_target_context.Status = nfc_ind_ptr->RSPstatus; // NFCStatus

    if (nfc_ind_ptr->RSPstatus != 13/* && nfc_ind_ptr->RSPstatus != 0*/)
    {
        jcc_nfc_async_unlock();

        if (jcc_nfc_current_target_context.transceive_info)
        {
            free_ctrl_buffer(jcc_nfc_current_target_context.transceive_info);
        }
        jcc_nfc_current_target_context.transceive_info = NULL;
        if (jcc_nfc_transceive_write_buffer)
        {
            free_ctrl_buffer(jcc_nfc_transceive_write_buffer);
        }
        jcc_nfc_transceive_write_buffer = NULL;
        if (jcc_nfc_transceive_read_buffer)
        {
            free_ctrl_buffer(jcc_nfc_transceive_read_buffer);
        }
        jcc_nfc_transceive_read_buffer = NULL;

        if (nfc_ind_ptr->RSPstatus == 0)
        {
            jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_TAG_TRANCEIVE, lockerHandle, NFCSTATUS_FAILED);
        }
        else
        {
            jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_TAG_TRANCEIVE, lockerHandle, nfc_ind_ptr->RSPstatus);
        }
        jvm_trace_debug("[JSR257]jcc_nfc_transceive_rsp_handle: %d,[UNBLOCK] = %d.", __LINE__, lockerHandle);

        free_ctrl_buffer(tmContext);
        jvm_trace_debug("[JSR257]jcc_nfc_transceive_rsp_handle: %d,free the tmContext.", __LINE__);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_transceive_cb_ind_handle
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_transceive_cb_ind_handle(ilm_struct *pData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_remote_dev_transceive_cb_ind_struct *nfc_ind_ptr = (nfc_remote_dev_transceive_cb_ind_struct*) pData->local_para_ptr;
    int i;
    int lockerHandle = 0;
    jcc_nfc_task_message_context *tmContext = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_transceive_cb_ind_handle: %d,status = %d\n ", __LINE__, nfc_ind_ptr->CBIStatus);

    jvm_trace_debug("[JSR257]jcc_nfc_transceive_cb_ind_handle: %d,jcc_nfc_current_target_context.CBIpResBuffer.length:%d\n", __LINE__, nfc_ind_ptr->CBIpResBuffer->length);

    tmContext = (jcc_nfc_task_message_context *)nfc_ind_ptr->CBIpContext;
    lockerHandle = tmContext->handle;

    jcc_nfc_async_unlock();

    if (tmContext)
    {
        free_ctrl_buffer(tmContext);
    }
    jvm_trace_debug("[JSR257]jcc_nfc_transceive_cb_ind_handle: %d,free the tmContext.\n ", __LINE__);

    jcc_nfc_transceive_read_buffer_length = nfc_ind_ptr->CBIpResBuffer->length;
    jcc_nfc_current_target_context.Status = nfc_ind_ptr->CBIStatus; // NFCStatus
    jvm_trace_debug("[JSR257]jcc_nfc_transceive_cb_ind_handle: %d,save the status.\n ", __LINE__);
    if (jcc_nfc_transceive_write_buffer)
    {
        free_ctrl_buffer(jcc_nfc_transceive_write_buffer);
    }
    jcc_nfc_transceive_write_buffer = NULL;
    jvm_trace_debug("[JSR257]jcc_nfc_transceive_cb_ind_handle: %d,free the jcc_nfc_transceive_write_buffer.\n ", __LINE__);

    if (nfc_ind_ptr->CBIStatus != 0 && jcc_nfc_transceive_read_buffer)
    {
        free_ctrl_buffer(jcc_nfc_transceive_read_buffer);
        jcc_nfc_transceive_read_buffer = NULL;
        jvm_trace_debug("[JSR257]jcc_nfc_transceive_cb_ind_handle: %d,free the jcc_nfc_transceive_read_buffer.\n ", __LINE__);
    }

    if (jcc_nfc_current_target_context.transceive_info)
    {
        free_ctrl_buffer(jcc_nfc_current_target_context.transceive_info);
    }
    jcc_nfc_current_target_context.transceive_info = NULL;
    jvm_trace_debug("[JSR257]jcc_nfc_transceive_cb_ind_handle: %d,free the transceive_info.\n ", __LINE__);
    // unlock
    jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_TAG_TRANCEIVE, lockerHandle, nfc_ind_ptr->CBIStatus);
    jvm_trace_debug("[JSR257]jcc_nfc_transceive_cb_ind_handle %d,[unlock] \n ", __LINE__);
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_get_transceive_rsp_data
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8* jcc_nfc_get_transceive_rsp_data(kal_uint32 *length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8* ret = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jcc_nfc_transceive_read_buffer_length > 0)
    {
        ret = jcc_nfc_transceive_read_buffer;
        *length = jcc_nfc_transceive_read_buffer_length;
    }

    jcc_nfc_transceive_read_buffer = NULL;
    jcc_nfc_transceive_read_buffer_length = 0;

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_check_ndef_rsp_handle
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_check_ndef_rsp_handle(ilm_struct *pData) //MSG_ID_NFC_NDEF_CHECK_NDEF_RSP
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_rsp_struct *nfc_ind_ptr = (nfc_rsp_struct*) pData->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_check_ndef_rsp_handle: %d,status = %d\n" , __LINE__, nfc_ind_ptr->RSPstatus);

    jcc_nfc_current_target_context.Status = nfc_ind_ptr->RSPstatus; // NFCStatus
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_check_ndef_cb_ind_handle
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_check_ndef_cb_ind_handle(ilm_struct *pData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int lockerHandle = 0;
    jcc_nfc_task_message_context *tmContext = NULL;
    nfc_ndef_check_ndef_cb_ind_struct *nfc_ind_ptr = (nfc_ndef_check_ndef_cb_ind_struct*) pData->local_para_ptr;
    int i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tmContext = (jcc_nfc_task_message_context *)nfc_ind_ptr->CBIpContext;;
    lockerHandle = tmContext->handle;

    jvm_trace_debug("[JSR257]jcc_nfc_check_ndef_cb_ind_handle %d, status=%x\n ", __LINE__, nfc_ind_ptr->CBIStatus);

    jcc_nfc_current_target_context.Status = nfc_ind_ptr->CBIStatus;

    if (nfc_ind_ptr->CBIStatus == NFCSTATUS_SUCCESS)
    {
        jcc_nfc_current_target_context.ndef_info.ActualNdefMsgLength = nfc_ind_ptr->CBINdef_Info.ActualNdefMsgLength;
        jcc_nfc_current_target_context.ndef_info.MaxNdefMsgLength = nfc_ind_ptr->CBINdef_Info.MaxNdefMsgLength;
        jcc_nfc_current_target_context.NDEFDetected = TRUE;

        if (jcc_nfc_tag_registered_number.PushNDEFRegistered > 0)
        {
            jcc_nfc_read_internal(tmContext);
            return;
        }
        else if (jam_mvm_get_running_count() > 0)
        {
            if (lockerHandle == 0)
            {
                jcc_nfc_is_target_detected = KAL_TRUE;
            }
            jvm_post_nfc_target_detected_event(CONTACTLESS_TYPE_TARGET_DETECTED, (int)jcc_nfc_current_target_context.Target_Handle);
            jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_CONNECT_TARGET, lockerHandle, nfc_ind_ptr->CBIStatus);
        }
    }
    else if (nfc_ind_ptr->CBIStatus == NFCSTATUS_TARGET_LOST)
    {
        jvm_trace_debug("[JSR257]jcc_nfc_check_ndef_cb_ind_handle: %d, target lost !!! \n", __LINE__);
        jcc_nfc_reset_internal(tmContext);
        return;
    }
    else
    {
        jvm_trace_debug("[JSR257]jcc_nfc_check_ndef_cb_ind_handle: %d, Tag is non NDEF !\n", __LINE__);
        jcc_nfc_current_target_context.NDEFDetected = FALSE;
        if (jam_mvm_get_running_count() > 0 &&
                (jcc_nfc_tag_registered_number.PlainRegistered > 0 ||
                 jcc_nfc_tag_registered_number.ISORegistered > 0 ||
                 jcc_nfc_tag_registered_number.NDEFRegistered > jcc_nfc_tag_registered_number.PushNDEFRegistered))
        {
            if (lockerHandle == 0)
            {
                jcc_nfc_is_target_detected = KAL_TRUE;
            }
            jvm_post_nfc_target_detected_event(CONTACTLESS_TYPE_TARGET_DETECTED, (int)jcc_nfc_current_target_context.Target_Handle);
            jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_CONNECT_TARGET, lockerHandle, NFCSTATUS_SUCCESS);
        }
        else
        {
            jcc_nfc_disconnect_internal(tmContext);
            //jcc_nfc_push_tm_context = tmContext;
            return;
        }
    }

    jcc_nfc_async_unlock();
    if (tmContext)
    {
        free_ctrl_buffer(tmContext);
        tmContext = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_check_configure_discover_rsp_handler
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_check_configure_discover_rsp_handler(ilm_struct *pData) //MSG_ID_NFC_MGT_CONFIGURE_DISCOVERY_RSP
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int lockerHandle = 0;
    jcc_nfc_task_message_context *tmContext = NULL;
    nfc_rsp_struct *nfc_ind_ptr = (nfc_rsp_struct*) pData->local_para_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tmContext = (jcc_nfc_task_message_context *)nfc_ind_ptr->REQpContext;;
    lockerHandle = tmContext->handle;
    jvm_trace_debug("[JSR257]jcc_nfc_check_configure_discover_rsp_handler: %d, lockerHandle = %d.\n", __LINE__, lockerHandle);

    jvm_trace_debug("[JSR257]jcc_nfc_check_configure_discover_rsp_handler: %d\n", __LINE__);

    jcc_nfc_current_target_context.Status = nfc_ind_ptr->RSPstatus; // NFCStatus
    jvm_trace_debug("[JSR257]jcc_nfc_check_configure_discover_rsp_handler:%d, status = %d \n", __LINE__, nfc_ind_ptr->RSPstatus);

    // If status = OK
    if (nfc_ind_ptr->RSPstatus != 13 && nfc_ind_ptr->RSPstatus != 0)
    {
        jcc_nfc_async_unlock();
        if (tmContext->cmd == JCC_NFC_STATE_RESET)
        {
            jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_RESET_TARGET, lockerHandle, nfc_ind_ptr->RSPstatus);
            if (jcc_nfc_terminate_vm)
            {
                if (jcc_nfc_tag_registered_number.SERegistered == 0)
                {
                    jcc_nfc_se_unregister_internal();
                }
                jcc_nfc_terminate_vm = KAL_FALSE;
            }
        }
        else if (tmContext->cmd == JCC_NFC_STATE_CLEAN_UP)
        {
            jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_CLEANUP_TARGET, lockerHandle, nfc_ind_ptr->RSPstatus);
        }
        else if (tmContext->cmd == JCC_NFC_STATE_CONNECT_WITH_CHECKING_NDEF)
        {
            jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_CONNECT_TARGET, lockerHandle, nfc_ind_ptr->RSPstatus);
        }
        else if (tmContext->cmd == JCC_NFC_STATE_DISCONNECT)
        {
            jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_DISCONNECT_TARGET, lockerHandle, nfc_ind_ptr->RSPstatus);
        }
        else
        {
            jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_REGISTER_TARGET, lockerHandle, nfc_ind_ptr->RSPstatus);
        }
        jvm_trace_debug("[JSR257]jcc_nfc_check_configure_discover_rsp_handler: %d, [UNBLOCK].\n ", __LINE__);
        free_ctrl_buffer(tmContext);

        jcc_nfc_driver_reinit();
    }
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_check_configure_discover_cb_ind
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_check_configure_discover_cb_ind(ilm_struct *pData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_mgt_configure_discovery_cb_ind_struct *nfc_ind_ptr = (nfc_mgt_configure_discovery_cb_ind_struct*) pData->local_para_ptr;
    int lockerHandle = 0;
    jcc_nfc_task_message_context *tmContext = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tmContext = (jcc_nfc_task_message_context *)nfc_ind_ptr->CBIpContext;
    lockerHandle = tmContext->handle;

    jcc_nfc_current_target_context.Status = nfc_ind_ptr->CBIStatus; // NFCStatus
    jvm_trace_debug("[JSR257]jcc_nfc_check_configure_discover_cb_ind: %d, status = %d \n ", __LINE__, nfc_ind_ptr->CBIStatus);

    // If command is cleanup or reset,then call unregister process
    /*if(tmContext->cmd == JCC_NFC_STATE_CLEAN_UP || tmContext->cmd == JCC_NFC_STATE_RESET)
    {
    	jcc_nfc_tag_unregister_internal(tmContext);
    	return;
    }*/

    jcc_nfc_async_unlock();

    if (tmContext)
    {
        free_ctrl_buffer(tmContext);
    }

    if (tmContext->cmd == JCC_NFC_STATE_CLEAN_UP)
    {
        jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_CLEANUP_TARGET, lockerHandle, nfc_ind_ptr->CBIStatus);
    }
    else if (tmContext->cmd == JCC_NFC_STATE_RESET)
    {
        jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_RESET_TARGET, lockerHandle, nfc_ind_ptr->CBIStatus);
        if (jcc_nfc_terminate_vm)
        {
            if (jcc_nfc_tag_registered_number.SERegistered == 0)
            {
                jcc_nfc_se_unregister_internal();
            }
            jcc_nfc_terminate_vm = KAL_FALSE;
        }
    }
    else if (tmContext->cmd == JCC_NFC_STATE_CONNECT_WITH_CHECKING_NDEF)
    {
        jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_CONNECT_TARGET, lockerHandle, nfc_ind_ptr->CBIStatus);
    }
    else if (tmContext->cmd == JCC_NFC_STATE_DISCONNECT)
    {
        jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_DISCONNECT_TARGET, lockerHandle, nfc_ind_ptr->CBIStatus);
    }
    else if (tmContext->cmd == JCC_NFC_STATE_REINIT)
    {
        if (jcc_nfc_tag_registered_number.SERegistered > 0)
        {
            jvm_trace_debug("[JSR257]jcc_nfc_driver_init_callback, register se\n");
            jcc_nfc_se_register(0);
        }
    }
    else
    {
        jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_REGISTER_TARGET, lockerHandle, nfc_ind_ptr->CBIStatus);
    }
    jvm_trace_debug("[JSR257]jcc_nfc_check_configure_discover_cb_ind: %d, [UNBLOCK].\n ", __LINE__);
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_check_presence_rsp_handler
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_check_presence_rsp_handler(ilm_struct *pData) //MSG_ID_NFC_REMOTE_DEV_CHECK_PRESENCE_RSP
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int lockerHandle = 0;
    jcc_nfc_task_message_context *tmContext = NULL;
    nfc_rsp_struct *nfc_ind_ptr = (nfc_rsp_struct*) pData->local_para_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tmContext = (jcc_nfc_task_message_context *)nfc_ind_ptr->REQpContext;
    lockerHandle = tmContext->handle;

    jvm_trace_debug("[JSR257]jcc_nfc_check_presence_rsp_handler: %d,status = %d,lockHandler = %d\n", __LINE__
                    , nfc_ind_ptr->RSPstatus
                    , lockerHandle);

    if (nfc_ind_ptr->RSPstatus != 13) // 13 is PASS
    {
        if (tmContext->cmd == JCC_NFC_STATE_CLEAN_UP ||
                tmContext->cmd == JCC_NFC_STATE_RESET ||
                tmContext->cmd == JCC_NFC_STATE_CONNECT_WITH_CHECKING_NDEF ||
                tmContext->cmd == JCC_NFC_STATE_CHECK_PRESENCE_BY_PUSH)
        {
            if (jcc_nfc_check_presence_count < 5 && nfc_ind_ptr->RSPstatus != 4153)
            {
                jcc_nfc_check_presence_count ++;
                jcc_nfc_check_presence_internal(tmContext);
                return;
            }
            else
            {
                jcc_nfc_check_presence_count = 0;
                jcc_nfc_disconnect_internal(tmContext);
                return;
            }
        }
        else
        {
            jcc_nfc_async_unlock();
            if (tmContext)
            {
                free_ctrl_buffer(tmContext);
            }
            jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_CHECK_PRESENCE, lockerHandle, nfc_ind_ptr->RSPstatus);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_check_presence_cb_ind_handler
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_check_presence_cb_ind_handler(ilm_struct *pData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int lockerHandle = 0;
    jcc_nfc_task_message_context *tmContext = NULL;
    nfc_remote_dev_check_presence_cb_ind_struct *nfc_ind_ptr = (nfc_remote_dev_check_presence_cb_ind_struct*) pData->local_para_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tmContext = (jcc_nfc_task_message_context *)nfc_ind_ptr->CBIpContext;
    lockerHandle = tmContext->handle;

    jvm_trace_debug("[JSR257]jcc_nfc_check_presence_cb_ind_handler: %d,status = %d,lockerHandle = %d\n ", __LINE__, nfc_ind_ptr->CBIStatus, lockerHandle);
    if (tmContext->cmd == JCC_NFC_STATE_CLEAN_UP || tmContext->cmd == JCC_NFC_STATE_RESET || tmContext->cmd == JCC_NFC_STATE_CONNECT_WITH_CHECKING_NDEF)
    {
        jcc_nfc_disconnect_internal(tmContext);
    }
    else if (tmContext->cmd == JCC_NFC_STATE_CHECK_PRESENCE_BY_PUSH)
    {
        if (nfc_ind_ptr->CBIStatus == NFCSTATUS_SUCCESS)
        {
            jcc_nfc_check_presence_internal(tmContext);
        }
        else
        {
            jcc_nfc_disconnect_internal(tmContext);
        }
    }
    else
    {
        jcc_nfc_async_unlock();
        if (tmContext)
        {
            free_ctrl_buffer(tmContext);
        }
        jcc_nfc_task_manager_set_unlock(JCC_NFC_TYPE_CHECK_PRESENCE, lockerHandle, nfc_ind_ptr->CBIStatus);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_se_get_secure_element_rsp_handler
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_se_get_secure_element_rsp_handler(ilm_struct *pData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_rsp_struct *nfc_ind_ptr = (nfc_rsp_struct*) pData->local_para_ptr;
    nfc_se_ntf_register_req_struct *p_msg = NULL; // send check NDEF REQ MSG
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_se_get_secure_element_rsp_handler %d\n ", __LINE__);

    jcc_nfc_current_target_context.Status = nfc_ind_ptr->RSPstatus; // NFCStatus
    jvm_trace_debug("[JSR257]jcc_nfc_se_get_secure_element_rsp_handler %d, jcc_nfc_current_target_context.Status= %d \n ", __LINE__, jcc_nfc_current_target_context.Status);

#if 1 // my debug message
    if (jcc_nfc_se_count != 0)
    {
        int i;
        jvm_trace_debug("[JSR257]jcc_nfc_se_get_secure_element_rsp_handler, %d, AFTER GET SE SECURE ELEMENT RSP \n", __LINE__);
        jvm_trace_debug("[JSR257]jcc_nfc_se_get_secure_element_rsp_handler, %d, jcc_nfc_se_count = %d \n", __LINE__, jcc_nfc_se_count);
        for (i = 0; i < jcc_nfc_se_count; i++)
        {
            jvm_trace_debug("[JSR257]jcc_nfc_se_get_secure_element_rsp_handler, %d, jcc_nfc_se_list[%d] = 0x%08X \n", __LINE__, i, jcc_nfc_se_list[i]);
            jvm_trace_debug("[JSR257]jcc_nfc_se_get_secure_element_rsp_handler, %d, jcc_nfc_se_list[%d].hSecureElement = 0x%08X \n", __LINE__, i, jcc_nfc_se_list[i].hSecureElement);
            jvm_trace_debug("[JSR257]jcc_nfc_se_get_secure_element_rsp_handler, %d, jcc_nfc_se_list[%d].eSE_Type = 0x%08X \n", __LINE__, i, jcc_nfc_se_list[i].eSE_Type);
            jvm_trace_debug("[JSR257]jcc_nfc_se_get_secure_element_rsp_handler, %d, jcc_nfc_se_list[%d].eSE_CurrentState = 0x%08X \n", __LINE__, i, jcc_nfc_se_list[i].eSE_CurrentState);
        }
    }
#endif

    jvm_trace_debug("[JSR257]jcc_nfc_se_get_secure_element_rsp_handler %d, data will be kept in 'jcc_nfc_se_list[]' \n ", __LINE__, jcc_nfc_current_target_context.Status);
    if (jcc_nfc_current_target_context.Status == 0 && jcc_nfc_se_count > 0)
    {
        p_msg = (nfc_se_ntf_register_req_struct *)	construct_local_para(sizeof(nfc_se_ntf_register_req_struct), TD_CTRL);
        ASSERT(p_msg); // judge whether MALLOC is success

        p_msg->pSE_NotificationCb = (pphLibNfc_SE_NotificationCb_t)jcc_nfc_dummy_callback_handler;
        p_msg->REQpContext = &jcc_nfc_tag_registered_number;
        jcc_nfc_send_message(MSG_ID_NFC_SE_NTF_REGISTER_REQ, MOD_NFC, INVALID_SAP, (void *)p_msg);

        jvm_trace_debug("[JSR257]jcc_nfc_se_get_secure_element_rsp_handler, %d, jcc_nfc_send_message(MSG_ID_NFC_SE_NTF_REGISTER_REQ)\n", __LINE__);
    }
    else
    {
        jcc_nfc_async_unlock();
    }
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_se_set_mode_rsp_handler
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_se_set_mode_rsp_handler(ilm_struct *pData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_rsp_struct *nfc_ind_ptr = (nfc_rsp_struct*) pData->local_para_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_se_set_mode_rsp_handler %d, status = %d \n ", __LINE__, nfc_ind_ptr->RSPstatus);
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_se_set_mode_cb_ind_handler
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_se_set_mode_cb_ind_handler(ilm_struct *pData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_mgt_configure_discovery_req_struct *cfg_msg = NULL; //send configure discovery
    phLibNfc_sADD_Cfg_t *cfg_ptr = NULL;
    jcc_nfc_task_message_context *tmContext = NULL;
    int lockerHandle = 0;
    nfc_se_set_mode_cb_ind_struct *nfc_ind_ptr = (nfc_se_set_mode_cb_ind_struct*) pData->local_para_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_se_set_mode_cb_ind_handler %d, nfc_ind_ptr->CBIpContext = %d \n ", __LINE__, nfc_ind_ptr->CBIpContext);
    jvm_trace_debug("[JSR257]jcc_nfc_se_set_mode_cb_ind_handler %d, nfc_ind_ptr->CBIStatus = %d \n ", __LINE__, nfc_ind_ptr->CBIStatus);
    jvm_trace_debug("[JSR257]jcc_nfc_se_set_mode_cb_ind_handler %d, nfc_ind_ptr->CBhSecureElement =%d \n ", __LINE__, nfc_ind_ptr->hSecureElement);

    if (!jcc_nfc_is_open_se_mode)
    {
        return;
    }

    tmContext = get_ctrl_buffer(sizeof(jcc_nfc_task_message_context));
    tmContext->context = &jcc_nfc_tag_registered_number;
    tmContext->handle = 0;

    cfg_msg = (nfc_mgt_configure_discovery_req_struct *)	construct_local_para(sizeof(nfc_mgt_configure_discovery_req_struct), TD_CTRL);
    cfg_msg->REQDiscoveryMode = NFC_DISCOVERY_CONFIG;
    cfg_ptr = (phLibNfc_sADD_Cfg_t *) & cfg_msg->REQsADDSetup;
    jcc_nfc_get_discovery_config(cfg_ptr,
                                 jcc_nfc_tag_registered_number.SERegistered,
                                 jcc_nfc_tag_registered_number.PlainRegistered,
                                 jcc_nfc_tag_registered_number.ISORegistered,
                                 jcc_nfc_tag_registered_number.NDEFRegistered);
    cfg_ptr->PollDevInfo.PollCfgInfo.DisableCardEmulation = FALSE;

    cfg_msg->REQpContext = (void*)tmContext;
    cfg_msg->REQpConfigDiscovery_RspCb = (pphLibNfc_RspCb_t)jcc_nfc_dummy_callback_handler;

    jvm_trace_debug("jcc_nfc_se_set_mode_cb_ind_handler: %d,jcc_nfc_send_message(MSG_ID_NFC_MGT_CONFIGURE_DISCOVERY_REQ)\n", __LINE__);
    jcc_nfc_send_message(MSG_ID_NFC_MGT_CONFIGURE_DISCOVERY_REQ, MOD_NFC, INVALID_SAP, (void *)cfg_msg);
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_convert_ascii_code
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
unsigned char jcc_nfc_convert_ascii_code(unsigned char value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (value >= 0 && value <= 9)
    {
        return '0' + value;
    }
    else if (value >= 0x0A && value <= 0x0F)
    {
        return 'A' + (value - 0x0A);
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_se_register_cb_ind_handler
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_se_register_cb_ind_handler(ilm_struct *pData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int slotIndex = -1;
    nfc_se_ntf_register_cb_ind_struct *nfc_ind_ptr = (nfc_se_ntf_register_cb_ind_struct*) pData->local_para_ptr;
    //char tmpBuf[256]={0};
    //int tmpLen = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("jcc_nfc_se_register_cb_ind_handler %d, nfc_ind_ptr->CBIStatus=0x%08X \n ", __LINE__, nfc_ind_ptr->CBIStatus);
    jvm_trace_debug("jcc_nfc_se_register_cb_ind_handler %d, nfc_ind_ptr->CBIpContext=%d \n ", __LINE__, nfc_ind_ptr->CBIpContext);
    jvm_trace_debug("jcc_nfc_se_register_cb_ind_handler %d, nfc_ind_ptr->CBEventType=%d \n ", __LINE__, nfc_ind_ptr->EventType);
    jvm_trace_debug("jcc_nfc_se_register_cb_ind_handler %d, nfc_ind_ptr->CBhSecureElement=0x%08X \n ", __LINE__, nfc_ind_ptr->hSecureElement);

    if (nfc_ind_ptr->CBIStatus == 0 && nfc_ind_ptr->EventType != phLibNfc_eSE_EvtFieldOff)
    {
        if (nfc_ind_ptr->EventType != phLibNfc_eSE_EvtFieldOn)
        {
            if (jcc_nfc_se_count != 0)
            {
                int i;
                for (i = 0; i < jcc_nfc_se_count; i++)
                {
                    jvm_trace_debug("jcc_nfc_se_register_cb_ind_handler, %d, jcc_nfc_se_list[%d] = 0x%08X \n", __LINE__, i, jcc_nfc_se_list[i]);
                    jvm_trace_debug("jcc_nfc_se_register_cb_ind_handler, %d, jcc_nfc_se_list[%d].hSecureElement = 0x%08X \n", __LINE__, i, jcc_nfc_se_list[i].hSecureElement);

                    if (jcc_nfc_se_list[i].hSecureElement == nfc_ind_ptr->hSecureElement)
                    {
                        jvm_trace_debug("jcc_nfc_se_register_cb_ind_handler, %d, on slot %d \n", __LINE__, i);
                        slotIndex = i;
                    }
                }
            }


            /*if (nfc_ind_ptr->pSeEvtInfo!=NULL)
            {
                int j;
                phNfc_sData_t *Aid = (phNfc_sData_t *) &(nfc_ind_ptr->pSeEvtInfo->UiccEvtInfo.aid);
                //phNfc_sData_t *Para = (phNfc_sData_t *) &(nfc_ind_ptr->pSeEvtInfo->UiccEvtInfo.param);

                jvm_trace_debug("jcc_nfc_se_register_cb_ind_handler %d, Aid->length=%d \n ", __LINE__, Aid->length);
                for (j=0; j<Aid->length; j++)
                {
                    unsigned char aByte = (unsigned char)Aid->buffer[j];
                    unsigned char aChar0;
                    unsigned char aChar1;

                    jvm_trace_debug("jcc_nfc_se_register_cb_ind_handler %d, Aid->buffer[%d]=0x%08X ('%c') \n ", __LINE__, j, Aid->buffer[j], Aid->buffer[j]);

                    tmpBuf[tmpLen++] = jcc_nfc_convert_ascii_code((aByte & 0xF0)>>4);
                    tmpBuf[tmpLen++] = jcc_nfc_convert_ascii_code((aByte & 0x0F));

                }

                j2me_process_recvd_nfc_ind(0xFF, tmpBuf, tmpLen);
            }*/
        }
        else /* Teng: temp solution*/
        {
            slotIndex = 0;
        }

        jvm_post_nfc_target_detected_event(CONTACTLESS_TYPE_TRANSACTION_DETECTED, slotIndex);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_se_unregister_rsp_handle
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_se_unregister_rsp_handle(ilm_struct *pData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nfc_se_set_mode_req_struct *p_msg;
    p_msg = (nfc_se_set_mode_req_struct *) construct_local_para(sizeof(nfc_se_set_mode_req_struct), TD_CTRL);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_se_unregister_rsp_handle %d, hSecureElement=%d \n", __LINE__, jcc_nfc_current_target_context.hSecureElement);

    p_msg->eActivation_mode = phLibNfc_SE_ActModeOff;
    p_msg->hSE_Handle = jcc_nfc_current_target_context.hSecureElement;
    p_msg->pSE_SetMode_Rsp_cb = (pphLibNfc_SE_SetModeRspCb_t) jcc_nfc_dummy_callback_handler;
    p_msg->REQpContext = &jcc_nfc_tag_registered_number;

    jcc_nfc_current_target_context.hSecureElement = 0;

    jcc_nfc_is_open_se_mode = KAL_FALSE;

    jvm_trace_debug("[JSR257]jcc_nfc_se_unregister_rsp_handle: %d, NOW SET SE MODE \n", __LINE__);
    jvm_trace_debug("[JSR257]jcc_nfc_se_unregister_rsp_handle: %d, p_msg->REQeActivation_mode = 0x%08X \n", __LINE__, p_msg->eActivation_mode);
    jvm_trace_debug("[JSR257]jcc_nfc_se_unregister_rsp_handle: %d, p_msg->REQhSE_Handle = 0x%08X \n", __LINE__, p_msg->hSE_Handle);
    jvm_trace_debug("[JSR257]jcc_nfc_se_unregister_rsp_handle: %d, p_msg->REQpSE_SetMode_Rsp_cb = 0x%08X \n", __LINE__, p_msg->pSE_SetMode_Rsp_cb);
    jvm_trace_debug("[JSR257]jcc_nfc_se_unregister_rsp_handle: %d, p_msg->REQpContext = 0x%08X \n", __LINE__, p_msg->REQpContext);

    jvm_trace_debug("[JSR257]jcc_nfc_se_unregister_rsp_handle: %d, jcc_nfc_send_message(MSG_ID_NFC_SE_SET_MODE_REQ)\n", __LINE__);
    jcc_nfc_send_message(MSG_ID_NFC_SE_SET_MODE_REQ, MOD_NFC, INVALID_SAP, (void *)p_msg);
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_trigger_post_user_event
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_trigger_post_user_event()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_post_nfc_target_detected_event(CONTACTLESS_TYPE_TARGET_DETECTED, 1234);
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_push_execution_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_push_execution_callback(kal_bool execute, pushentry_struct *entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_push_execution_callback: %d, tm_context=%d\n", __LINE__, jcc_nfc_push_tm_context);
    if (jcc_nfc_push_tm_context)
    {
        if (!jcc_nfc_is_processing &&
                jcc_nfc_is_initialized &&
                !jcc_nfc_is_reinit_driver &&
                (!jcc_nfc_is_vm_connected ||
                 !(jcc_nfc_tag_registered_number.NDEFRegistered > jcc_nfc_tag_registered_number.PushNDEFRegistered ||
                   jcc_nfc_tag_registered_number.PlainRegistered > 0 ||
                   jcc_nfc_tag_registered_number.ISORegistered > 0)))
        {
            //jcc_nfc_disconnect_internal((jcc_nfc_task_message_context *)jcc_nfc_push_tm_context);
            ((jcc_nfc_task_message_context *)jcc_nfc_push_tm_context)->cmd = JCC_NFC_STATE_CHECK_PRESENCE_BY_PUSH;
            jcc_nfc_check_presence_internal((jcc_nfc_task_message_context *)jcc_nfc_push_tm_context);
        }
        else
        {
            free_ctrl_buffer(jcc_nfc_push_tm_context);
        }
        jcc_nfc_push_tm_context = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_get_locker
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 jcc_nfc_get_locker(kal_int32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return jcc_nfc_task_manager_get_lock(type);
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_check_locker
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 jcc_nfc_check_locker(kal_int32 type, kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return jcc_nfc_task_manager_check_lock(type, handle);
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_release_locker
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jcc_nfc_release_locker(kal_int32 type, kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jvm_trace_debug("[JSR257]jcc_nfc_release_locker, %d, begin:\n", __LINE__);
    jcc_nfc_task_manager_set_unlock(type, handle, 0);
    jcc_nfc_task_manager_get_status(type, handle);
    jvm_trace_debug("[JSR257]jcc_nfc_release_locker, %d, end:\n", __LINE__);
}


/*****************************************************************************
 * FUNCTION
 *  jcc_nfc_get_status
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 jcc_nfc_get_status(kal_int32 type, kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_int32)jcc_nfc_task_manager_get_status(type, handle);
}
#endif
