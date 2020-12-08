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
 * jcc_interface.h
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
#ifndef JCC_INTERFACE_H_
#define JCC_INTERFACE_H_

#ifdef SUPPORT_JSR_257
#include "kal_release.h"
#include "jcc_internal.h"
#include "phLibNfc.h"
#include "phNfcTypes.h"


//RecordTypeDescription
#define SECLEM			'9'
#define RTD_EMPTY		'0'
#define RTD_NFC_FORUM	'1'
#define RTD_MIME		'2'
#define RTD_URI			'3'
#define RTD_EXTERNAL	'4'
#define RTD_UNKNOWN	    '5'
	 
#define MAX_MANAGE_ITEM_SIZE 			(20)
#define TASK_MANAGER_CHECK_UNLOCK		1
#define TASK_MANAGER_CHECK_LOCK			0
#define TASK_MANAGER_CHECK_ERROR		-1

/**
* Task manager object item
*/
typedef struct
{
    int isLock;
    int functionType;
    int status;
	 
} jcc_nfc_task_management_item;
	 
/**
* Task manager object
*/
typedef struct
{
    jcc_nfc_task_management_item items[MAX_MANAGE_ITEM_SIZE];
	 
    int next;
    int last;
    int size;
	 
    kal_mutexid task_mutex;
	 
} jcc_nfc_task_management;
	 
/**
* Task Message context
*/
typedef struct
{
    void *context;
    int handle;
    int cmd;
} jcc_nfc_task_message_context;

typedef struct
{
	phLibNfc_Handle Target_Handle;
	phLibNfc_Handle Multi_Target_Handle[5];
	phNfc_eRemDevType_t Target_Type;
	phNfc_eRemDevType_t Multi_Target_Type[5];
	kal_uint8 Target_UidLength;
	kal_uint8 Target_Uid[PHHAL_MAX_UID_LENGTH];
	kal_uint8 Target_SAK;
	kal_uint8 NofTarget;
	kal_uint32 Ndef_Msg_Length;
} jcc_nfc_tag_info;

/** Configuration */
/*typedef struct nfcfri_config_t {
    // 0223 wm mark
    phLibNfc_sConfig_t Driver_Config;
    kal_bool RF_Type_ISO14443A;
    kal_bool RF_Type_ISO14443B;
    kal_bool RF_Type_FELICA;
    kal_bool RF_Type_NFCIP1;
    kal_bool RF_Type_ISO15693;
} nfcfri_config_t;*/
	 
typedef struct
{
    kal_uint32 SERegistered;
    kal_uint32 PushSERegistered;
    kal_uint32 PlainRegistered;
    kal_uint32 ISORegistered;
    kal_uint32 NDEFRegistered;
    kal_uint32 PushNDEFRegistered;
} jcc_nfc_registry_counter;
	 
/** Target */
typedef struct
{
    unsigned long ThreadNfcId;
	 
    char **ppRxData;
    kal_int32 *pnRxDataLength;
    jcc_nfc_result_enum *pResult;
	 
    phLibNfc_Handle Target_Handle;
    phLibNfc_Handle Multi_Target_Handle[5];
    phNfc_eRFDevType_t Target_Type;
    phNfc_eRFDevType_t Multi_Target_Type[5];	
	 
    //mark 20110604
    jcc_nfc_tag_info Tag_Info;
    kal_uint8 Transceive_TagType;
	 
    NFCSTATUS Status;
    phLibNfc_RemoteDevList_t RemoteDev;
	 //   BOOL	   MifareULDetected;
	 //   BOOL	   ISO14443ADetected;
	 //   BOOL	   ISO14443BDetected;
    kal_bool NDEFDetected;
    kal_bool disconnected;
	 
    phLibNfc_sTransceiveInfo_t *transceive_info;
    phLibNfc_ChkNdef_Info_t    ndef_info;
    phNfc_sData_t		 *ndef_message;
	 //   uint32_t					 timerID;
    kal_bool SE_Actived; // convenience
	 
	  //NFC
    void* CBIpContext;
    kal_uint8 CBuNofRemoteDev;
	 // phLibNfc_Handle 	 CBhRemoteDev;
    phNfc_sData_t* CBpResBuffer;
	 
    phLibNfc_Handle hSecureElement;
	 // phLibNfc_sRemoteDevInformation_t* CBpsRemoteDevInfo;
}jcc_nfc_target_context;
	 
	 
	 // const
	 
	 // functions
/*#define driver_init        nfcfri_init
#define driver_terminate   nfcfri_terminate
#define driver_register    nfcfri_register
#define driver_unregister  nfcfri_unregister
#define driver_get_types   nfcfri_get_types
#define driver_get_uid     nfcfri_get_uid
#define driver_get_mapping nfcfri_get_mapping
#define driver_close       nfcfri_close
#define driver_write       nfcfri_write
#define driver_read        nfcfri_read
#define driver_transceive  nfcfri_transceive*/
	 
extern kal_int32 jcc_nfc_get_locker(kal_int32 type);
	 
extern kal_int32 jcc_nfc_check_locker(kal_int32 type,kal_int32 handle);
	 
extern void jcc_nfc_release_locker(kal_int32 type,kal_int32 handle);
	 
extern kal_int32 jcc_nfc_get_status(kal_int32 type,kal_int32 handle);
	 
extern jcc_nfc_result_enum jcc_nfc_init(void);
	 
extern jcc_nfc_result_enum jcc_nfc_deinit(void);
	 
extern jcc_nfc_result_enum jcc_nfc_register(jcc_nfc_target_type_enum target,
													 void **context,
													 kal_int32 lockerHandle);
	 
extern jcc_nfc_result_enum jcc_nfc_unregister(jcc_nfc_target_type_enum target,
													   void **context,
													   kal_int32 lockHandler);
	 
extern jcc_nfc_result_enum jcc_nfc_get_uid(
		   kal_int32 target_handle,
		   char *uid,
		   kal_int32 *uid_length);
	 
extern jcc_nfc_result_enum jcc_nfc_get_mapping(
		   kal_int32 target_handle,
		   char *mapping,
		   kal_int32 *mapping_length);
	 
extern jcc_nfc_result_enum jcc_nfc_get_property(
		   kal_int32 target_handle,
		   kal_int32 index,
		   char *value,
		   kal_int32 *value_length);
	 
extern jcc_nfc_result_enum jcc_nfc_is_supported_type(
		   kal_int32 target_handle,
           jcc_nfc_target_type_enum target_type,
           kal_bool *supported);
	 
extern kal_bool jcc_nfc_notify(
		   kal_int32 target_handle,
		   kal_bool target_used);
	 
extern jcc_nfc_result_enum jcc_nfc_open(
		   kal_int32 target_handle);
	 
extern jcc_nfc_result_enum jcc_nfc_close(
		   kal_int32 target_handle,
		   void **context);
	 
extern jcc_nfc_result_enum jcc_nfc_write(
		   kal_int32 target_handle,
		   char *tx_data,
		   kal_int32 tx_data_length,
		   void **context,
		   kal_int32 lockerHandle);
	 
extern jcc_nfc_result_enum jcc_nfc_read(
		   kal_int32 target_handle,
		   char *rx_data,
		   kal_int32 *rx_data_length,
		   void **context,
		   kal_int32 lockHandler);
	 
extern jcc_nfc_result_enum jcc_nfc_transceive(
		   kal_int32 target_handle,
		   kal_int32 cmd,
		   kal_int32 addr,
		   char *tx_data,
		   kal_int32 tx_data_length,
		   char *rx_data,
		   kal_int32 *rx_data_length,
		   void **context,
		   kal_int32 lockHandler);

extern void jcc_nfc_connect(kal_int32 lockHandler);
extern void jcc_nfc_disconnect(kal_int32 lockHandler);

extern kal_uint8* jcc_nfc_get_read_ndef_data(kal_uint32 *length);

extern kal_uint8* jcc_nfc_get_transceive_rsp_data(kal_uint32 *length);
	 
extern void jcc_nfc_trigger_post_user_event(void);

extern kal_bool jcc_nfc_clean_up(kal_int32 lockHandler);
extern void jcc_nfc_release(kal_int32 lockHandler);
extern kal_bool jcc_nfc_reset(int lockHandler);
extern void jcc_nfc_clear(void);
extern kal_bool jcc_nfc_check_presence(int lockHandler);

extern kal_bool jcc_nfc_is_tag_detected(void);
extern kal_int32 jcc_nfc_get_device_state(void);
	 
extern void jsr257_process_recvd_nfc_push_info_add(char *type, char *name);
extern void jsr257_process_recvd_nfc_push_info_register_req(void);

extern void jvm_post_nfc_target_detected_event(int arg1, int arg2);
#endif /* SUPPORT_JSR_257 */	 
	 
#endif //JCC_INTERFACE_H_
