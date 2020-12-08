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
 * jcc_internal.h
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
 * removed!
 * removed!
 * removed!
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
#ifndef _JCC_INTERNAL_H
#define _JCC_INTERNAL_H
	 
#include "kal_public_defs.h"
#include "jpush_interface.h"

/**
 * @enum JSR257_result
 * @brief JSR257 error results
 */
typedef enum {
   /** Generic success */
   JCC_NFC_OK = 0,
   /** Generic failure */
   JCC_NFC_FAIL = -1,
   /** Not implemented */
   JCC_NFC_NOT_IMPLEMENTED = -2,
   /** Out of memory */
   JCC_NFC_OUT_OF_MEMORY = -3,
   /** Invalid argument */
   JCC_NFC_INVALID_ARGUMENT = -4,
   /** Would block */
   JCC_NFC_BLOCK = -5,
   /** Connection not found */
   JCC_NFC_CONNECTION_NOT_FOUND = -6,
   /** Operation is interrupted */
   JCC_NFC_INTERRUPTED = -7,
   /** Return by JSR257 read on
       SoS connections or socket in
       Non-Delay mode. Caller should
       reinvoke the read function
       to retry reading data */
   JCC_NFC_NO_DATA_AVAILABLE = -8,
   /** File not found in the given path */
   JCC_NFC_FILE_NOT_FOUND = -9,
   /** bad file name */
   JCC_NFC_BAD_FILE_NAME = -10,
   /** End of file */
   JCC_NFC_END_OF_FILE = -11,
   /** I/O error occured */
   JCC_NFC_IO_ERROR = -12,
   /** bad properties in jad file,
    * either a missing required property or
    * incorrectly formatted property */
   JCC_NFC_BAD_JAD_PROPERTIES = -13,
    /** JSR257 properties db value not found */
   JCC_NFC_VALUE_NOT_FOUND = -14,
    /** Invalid state */
   JCC_NFC_INVALID_STATE = -15,
   /** Timeout elapsed */
   JCC_NFC_TIMEOUT = -16,
   /**
     * No audio device found. Please return this code only in case you want to
     * reject playback, i.e. when the content is audio only. If some playback
     * is still possible (e.g. mute video), please return JCC_NFC_OK instead
     */
   JCC_NFC_NO_AUDIO_DEVICE = -17
} jcc_nfc_result_enum;

/**
 * @enum jcc_nfc_target_type_enum
 * @brief
 */
typedef enum {
   JCC_NFC_TARGET_SECURE_ELEMENT_ID = 0,
   JCC_NFC_TARGET_ISO14443_CARD_ID = 1,
   JCC_NFC_TARGET_NDEF_TAG_ID = 2,
   JCC_NFC_TARGET_RFID_TAG_ID = 3,
   JCC_NFC_TARGET_VISUAL_TAG_ID = 4,
   JCC_NFC_TARGET_TYPES_NUM
} jcc_nfc_target_type_enum;
	 
#ifdef SUPPORT_JSR_257

typedef enum{
    JCC_NFC_CMD_ISO14443_EXCHANGE_DATA,
    JCC_NFC_CMD_MIFARE_READ_16,
    JCC_NFC_CMD_MIFARE_WRITE_16,
    JCC_NFC_CMD_MIFARE_WRITE_4,
    JCC_NFC_CMD_MIFARE_AUTH_A,
    JCC_NFC_CMD_MIFARE_AUTH_B,
    JCC_NFC_CMD_ISO15693_READ,
    JCC_NFC_CMD_ISO15693_WRITE
}jcc_nfc_cmd_enum;

typedef enum{
    JCC_NFC_TYPE_NULL                = 0x0,
    JCC_NFC_TYPE_REGISTER_TARGET     = 0x1,
    JCC_NFC_TYPE_UNREGISTER_TARGET   = 0x2,
    JCC_NFC_TYPE_TAG_READ            = 0x3,
    JCC_NFC_TYPE_TAG_WRITE           = 0x4,
    JCC_NFC_TYPE_TAG_TRANCEIVE       = 0x5,
    JCC_NFC_TYPE_CONNECT_TARGET      = 0x6,
    JCC_NFC_TYPE_DISCONNECT_TARGET   = 0x7,
    JCC_NFC_TYPE_CHECK_NDEF          = 0x8,
    JCC_NFC_TYPE_CLEANUP_TARGET      = 0x9,
    JCC_NFC_TYPE_RELEASE_TARGET      = 0x10,
    JCC_NFC_TYPE_RESET_TARGET        = 0x11,
    JCC_NFC_TYPE_CHECK_PRESENCE      = 0x12
}jcc_nfc_operation_type_enum;

typedef enum {
    JCC_NFC_STATE_CONNECT_ONLY               = 0x0,
    JCC_NFC_STATE_CONNECT_WITH_CHECKING_NDEF = 0x1,
    JCC_NFC_STATE_DISCONNECT                 = 0x2,
    JCC_NFC_STATE_CHECK_PRESENCE_BY_PUSH     = 0x4,
    JCC_NFC_STATE_CLEAN_UP                   = 0x1000,
    JCC_NFC_STATE_RESET                      = 0x2000,
    JCC_NFC_STATE_REINIT                     = 0x4000
} jcc_nfc_state_enum;

typedef enum {
    JCC_NFC_DEVICE_INIT,
    JCC_NFC_DEVICE_DETECT_TARGET,
    JCC_NFC_DEVICE_CONNECT,
    JCC_NFC_DEVICE_INVALID
} jcc_nfc_device_state_enum;

typedef struct {
    int virtualConnected;
    int realConnected;
    int virtualRegistered;
    int realRegistered;
} jcc_nfc_device_status_struct;

extern jcc_nfc_result_enum jcc_nfc_push_register(jcc_nfc_target_type_enum target);
extern jcc_nfc_result_enum jcc_nfc_push_unregister(jcc_nfc_target_type_enum target);

extern void jcc_nfc_driver_init_callback(ilm_struct *pData);
extern void jcc_nfc_driver_deinit_callback(ilm_struct *pData);
extern void jcc_nfc_se_register_rsp_handle(ilm_struct *pData);
extern void jcc_nfc_register_rsp_handle(ilm_struct *pData);
extern void jcc_nfc_register_cb_ind_handle(ilm_struct *pData);
extern void jcc_nfc_unregister_rsp_handle(ilm_struct *pData);
extern void jcc_nfc_connect_rsp_handle(ilm_struct *pData);
extern void jcc_nfc_connect_cb_ind_handle(ilm_struct *pData);
extern void jcc_nfc_close_rsp_handle(ilm_struct *pData);
extern void jcc_nfc_close_cb_ind_handle(ilm_struct *pData);
extern void jcc_nfc_write_ndef_rsp_handle(ilm_struct *pData);
extern void jcc_nfc_write_ndef_cb_ind_handle(ilm_struct *pData);
extern void jcc_nfc_read_ndef_rsp_handle(ilm_struct *pData);
extern void jcc_nfc_read_ndef_cb_ind_handle(ilm_struct *pData);
extern void jcc_nfc_transceive_rsp_handle(ilm_struct *pData);
extern void jcc_nfc_transceive_cb_ind_handle(ilm_struct *pData);
extern void jcc_nfc_check_ndef_rsp_handle(ilm_struct *pData);
extern void jcc_nfc_check_ndef_cb_ind_handle(ilm_struct *pData);
extern void jcc_nfc_check_configure_discover_rsp_handler(ilm_struct *pData);
extern void jcc_nfc_check_configure_discover_cb_ind(ilm_struct *pData);
extern void jcc_nfc_check_presence_rsp_handler(ilm_struct *pData);
extern void jcc_nfc_check_presence_cb_ind_handler(ilm_struct *pData);
extern void jcc_nfc_se_get_secure_element_rsp_handler(ilm_struct *pData);
extern void jcc_nfc_se_set_mode_rsp_handler(ilm_struct *pData);
extern void jcc_nfc_se_set_mode_cb_ind_handler(ilm_struct *pData);
extern void jcc_nfc_se_register_cb_ind_handler(ilm_struct *pData);
extern void jcc_nfc_se_unregister_rsp_handle(ilm_struct *pData);

extern void jcc_nfc_push_execution_callback(kal_bool execute, pushentry_struct *entry);

extern kal_int32 jcc_nfc_mvm_initialize(void);
extern kal_int32 jcc_nfc_mvm_finalize(void);
#endif /* SUPPORT_JSR_257 */
	 
#endif /* _CC_INTERNAL_H */ 

