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
 * BthfSrvGprot.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is the header file for external module to use BT CM related apis
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef BTHF_SERVICE_GPROT_H
#define BTHF_SERVICE_GPROT_H

#include "BTCMSrvGprot.h"

/* RHR ADD */
#include "MMI_features.h"
/* RHR ADD end */
#ifdef __MMI_HFP_SUPPORT__
/* RHR ADD */
#include "MMIDataType.h"
#include "kal_general_types.h"
/* RHR ADD end */

/* DOM-NOT_FOR_SDK-BEGIN */
typedef srv_bt_cm_bt_addr BTHFAddr;
/* DOM-NOT_FOR_SDK-END */

typedef U32 BTHFHandle;
typedef U32 BTHFResult;

/* Operation result */
enum BthfResult{
    BTHF_RESULT_SUCC,   /* Operation success */
    BTHF_RESULT_FAIL,   /* Operation failed */
    BTHF_RESULT_END
};

typedef U32 BTHFEvent;
/* Event class */
enum BthfEvent {
    BTHF_EV_ENABLE      = 0x01,     /* Service enabled, after that remote device could be attached. 
                                        Parameter is reserved */
    BTHF_EV_DISABLE     = 0x02,     /* Service disabled, after that remote device could never be attached.
                                        Parameter is reserved */
    BTHF_EV_REQ_ATTACH  = 0x04,     /* Remote device request to attach.
                                        Parameter indicate device ID */
    BTHF_EV_REQ_ABORT   = 0x08,     /* Remote device abort attach request.
                                        Parameter indicate device ID */
    BTHF_EV_ATTACH      = 0x10,     /* Device has been attached.
                                        Parameter indicate device ID */
    BTHF_EV_DETACH      = 0x20,     /* Device has been detached.
                                        Parameter indicate device ID */
    BTHF_EV_AUDIO_ON    = 0x40,     /* Audio connection is up for attached device.
                                        Parameter indicate device ID */
    BTHF_EV_AUDIO_OFF   = 0x80,     /* Audio connection is down for attached device.
                                        Parameter indicate device ID */
    BTHF_EV_VOL_CHANGE  = 0x100,    /* Volume changed by remote device.
                                        Parameter indicate new volume value */
    BTHF_EV_REQ_RESULT  = 0x200,    /* Operation result.
                                        Parameter Hi-Word indicate error code, see also BthfErrCode
                                        Parameter Lo-Word indicate operation class, see also BthfRequest */
    BTHF_EV_END
};

typedef U32 BTHFRequest;
/* Operation class */
enum BthfRequest {
    BTHF_REQ_ENABLE,    /* Enable service */
    BTHF_REQ_DISABLE,   /* Disable service */
    BTHF_REQ_ATTACH,    /* Attach to device */
    BTHF_REQ_DETACH,    /* Detach from device */
    BTHF_REQ_AUDIO_ON,  /* Audio turn on */
    BTHF_REQ_AUDIO_OFF, /* Audio turn off */
    BTHF_REQ_ACCEPT,    /* Accept request */
    BTHF_REQ_REJECT,    /* Reject request */
    BTHF_REQ_CHG_VOLUME
};

typedef U32 BTHFErrCode;
/* Async operation error code */
enum BthfErrCode{
    BTHF_E_NONE,            /* No error */
    BTHF_E_BUSY,            /* Busy since previous operation still ongoing */
    BTHF_E_PENDING,         /* Async operation, relevant event will be triggered when done */
    BTHF_E_NOT_AUTHORIZE,   /* Current instance not the owner of the device/connection */
    BTHF_E_NOT_ALLOW,       /* Not allowed */
    BTHF_E_NOT_SUPPORT,     /* Not supported by current version */
    BTHF_E_BEARER_BROKEN,   /* Bluetooth link broken */
    BTHF_E_UNKNOWN,         /* Unknown error */
    BTHF_E_USER_ABORT,      /* User abort operation */
    BTHF_E_END
};

typedef U32 BTHFStatus;
/* Device status */
enum BthfStatus {
	BTHF_STATUS_DETACH,     /* Detached, no HFP connection established */
	BTHF_STATUS_ATTACH,     /* Attached, SLC connection has been established */
	BTHF_STATUS_AUDIO_ON,   /* SCO link has been established */
	BTHF_STATUS_END
};


typedef U32 BTHFMaskOp;
/* Notify event mask operation */
enum BthfMaskOp {
	BTHF_MOP_NEW,           /* Reset receiving event */
	BTHF_MOP_ADD,           /* Add specific event */
	BTHF_MOP_DEL            /* Delte specific event */
};

/* Service config item */
enum BthfCfg {
    BTHF_CFG_AUDIO_PATH = 1,    /* Specify audio routing path. 
                                    Corresponding value: BthfAudMode */
    BTHF_CFG_DEF_DEVICE,        /* Specify default audio device.
                                    Corresonding value: address of default device */
/* DOM-NOT_FOR_SDK-BEGIN */                                    
    BTHF_CFG_PROFILE,
/* DOM-NOT_FOR_SDK-END */    
    BTHF_CFG_END
};

typedef U32 BTHFDevClass;
/* Audio device class */
enum BthfDevClass {
    BTHF_DEV_HEADSET = 1,       /* Headset */
    BTHF_DEV_CARKIT,            /* Carkit */
    BTHF_DEV_END
};

/* Bluetooth profile */
enum BthfProf {
    BTHF_PROF_HF = 1,       /* Handsfree profile */
    BTHF_PROF_HS,           /* Headset profile */
/* DOM-NOT_FOR_SDK-BEGIN */                                    
    BTHF_PROF_AUTO,
/* DOM-NOT_FOR_SDK-END */    
    BTHF_PROF_END
};

typedef U32 BTHFVolClass;
/* Volume gain class */
enum BthfVolClass {
    BTHF_VOL_SPEAKER = 1,   /* Speaker gain */
    BTHF_VOL_MIC,           /* Microphone gain */
    BTHF_VOL_END
};

typedef U32 BTHFAudioMode;
/* Audio path setting */
enum BthfAudMode {
    BTHF_AUD_REMOTE = 1,    /* Route audio to remote device */
    BTHF_AUD_LOCAL,         /* Keep audio in local device */
    BTHF_AUD_END
};

#define BTHF_DEV_NAME_LEN   32

/* Device information */
typedef struct {
    U32 id;                 /* Device ID */
    U32 conn_id;            /* Connection ID, used for bearer management */
    BTHFDevClass dev_class;     /* Device class */
    BTHFStatus status;      /* Device status */
    U32 prof;               /* Connected profile, See also BthfProf */
    BTHFAddr addr;          /* Device address */
    WCHAR name[BTHF_DEV_NAME_LEN+1];    /* Device name */
} bthf_dev_info_struct;

#define BTHF_INVALID_DEV_HANDLE    (0xfffffff0)

/* <GROUP CallbackFunctions>
 *
 * FUNCTION
 *  BTHFSrvNotify
 * DESCRIPTION
 *  BTHF service event notification.
 * PARAMETERS
 *  srv_hd: [IN]    Instance handle of BTHF service.
 *  evt:    [IN]    Event type, See also BthfEvent.
 *  param:  [IN]    Event parameter. See also BppEvent.
 * RETURNS
 *  S32: reserved for future usage.
 */
typedef S32 (*BTHFSrvNotify)(BTHFHandle srv_hd, U32 evt, U32 param);
typedef void (*BTHFAttachCallback)(MMI_BOOL result);


#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_bthf_init
 * DESCRIPTION
 *  Initialize BTHF service, should be invoked before any BTHF operation.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bthf_init(void);

/*****************************************************************************
 * FUNCTION
 *  srv_bthf_deinit
 * DESCRIPTION
 *  Deinit BTHF service, after this been invoked, all HF related resource will
 *  be released.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bthf_deinit(void);

/*****************************************************************************
 * FUNCTION
 *  srv_bthf_open
 * DESCRIPTION
 *  Open one instance for BTHF service.
 * PARAMETERS
 *  void
 * RETURNS
 *  BTHFHandle: service instance handle. 0 indicate fail.
 *****************************************************************************/
BTHFHandle srv_bthf_open(void);

/*****************************************************************************
 * FUNCTION
 *  srv_bthf_close
 * DESCRIPTION
 *  Close one instance for BTHF service.
 * PARAMETERS
 *  srv_hd:  [IN]    Previously opened service, returned by srv_bthf_open.
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bthf_close(BTHFHandle srv_hd);

/*****************************************************************************
 * FUNCTION
 *  srv_bthf_set_notify
 * DESCRIPTION
 *  Config BTHF service notification.
 * PARAMETERS
 *  srv_hd: [IN]     Previously opened service, returned by srv_bthf_open.
 *  notify: [IN]     Notification callback function.
 *  mask:   [IN]     Bitmask of register notify events. See also BthfEvent.
 *  op:     [IN]     See also BthfMaskOp.
 * RETURNS
 *  BTHFResult: operation result. See also BthfResult.
 *****************************************************************************/
BTHFResult srv_bthf_set_notify(BTHFHandle srv_hd, BTHFSrvNotify notify, U32 mask, U8 op);

/*****************************************************************************
 * FUNCTION
 *  srv_bthf_config
 * DESCRIPTION
 *  Config BTHF service for specific instance.
 * PARAMETERS
 *  srv_hd: [IN]    Previously opened service, returned by srv_bthf_open.
 *  item:   [IN]    Setting item class. See also BthfCfg.
 *  value:  [IN]    Setting item value. See also BthfCfg.
 * RETURNS
 *  BTHFResult: operation result. See also BthfResult.
 *****************************************************************************/
BTHFResult srv_bthf_config(BTHFHandle srv_hd, U32 item, void *value);

/*****************************************************************************
 * FUNCTION
 *  srv_bthf_attach
 * DESCRIPTION
 *  Attach to remote device. 
 *  This might cause event BTHF_EV_ATTACH generated.
 * PARAMETERS
 *  srv_hd: [IN]    Previously opened service, returned by srv_bthf_open.
 *  addr:   [IN]    Address of remote device. if NULL, will try to attach with default device.
 * RETURNS
 *  BTHFResult: operation result. See also BthfResult.
 *****************************************************************************/
BTHFResult srv_bthf_attach(BTHFHandle srv_hd, BTHFAddr *addr);

/*****************************************************************************
 * FUNCTION
 *  srv_bthf_detach
 * DESCRIPTION
 *  Detach from remote device. Audio link will be automatically shutdown before detach performed. 
 *  This might cause event BTHF_EV_DETACH generated.
 * PARAMETERS
 *  srv_hd: [IN]    Previously opened service, returned by srv_bthf_open.
 *  dev_id: [IN]    ID of remote device to be detached.
 * RETURNS
 *  BTHFResult: operation result. See also BthfResult.
 *****************************************************************************/
BTHFResult srv_bthf_detach(BTHFHandle srv_hd, U32 dev_id);

/*****************************************************************************
 * FUNCTION
 *  srv_bthf_audio_on
 * DESCRIPTION
 *  Switch audio link on for specific attached device.
 *  This might cause event BTHF_EV_AUDIO_ON generated.
 * PARAMETERS
 *  srv_hd: [IN]    Previously opened service, returned by srv_bthf_open.
 *  dev_id: [IN]    ID of remote device to be turn audio on.
 * RETURNS
 *  BTHFResult: operation result. See also BthfResult.
 *****************************************************************************/
BTHFResult srv_bthf_audio_on(BTHFHandle srv_hd, U32 dev_id);

/*****************************************************************************
 * FUNCTION
 *  srv_bthf_audio_on
 * DESCRIPTION
 *  Switch audio link on for specific attached device.
 *  This might cause BTHF_EV_AUDIO_OFF generated.
 * PARAMETERS
 *  srv_hd: [IN]    Previously opened service, returned by srv_bthf_open.
 *  dev_id: [IN]    ID of remote device to be turn audio off.
 * RETURNS
 *  BTHFResult: operation result. See also BthfResult.
 *****************************************************************************/
BTHFResult srv_bthf_audio_off(BTHFHandle srv_hd, U32 dev_id);

/*****************************************************************************
 * FUNCTION
 *  srv_bthf_change_volume
 * DESCRIPTION
 *  Sync volume to remote device.
 *  This might cause BTHF_EV_VOLUME_CHANGE generated.
 * PARAMETERS
 *  srv_hd: [IN]    Previously opened service, returned by srv_bthf_open.
 *  dev_id: [IN]    Specify which device to be changed volume, 0 means all attached device
 *                  will be synced to this volume.
 *  volume: [IN]    Volume value to changed, should in range 0-15.
 * RETURNS
 *  BTHFResult: operation result. See also BthfResult.
 *****************************************************************************/
BTHFResult srv_bthf_change_volume(BTHFHandle srv_hd, U32 dev_id, U8 volume);

/*****************************************************************************
 * FUNCTION
 *  srv_bthf_accept
 * DESCRIPTION
 *  Accept remote device attach request.
 * PARAMETERS
 *  srv_hd: [IN]    Previously opened service, returned by srv_bthf_open.
 *  dev_id: [IN]    ID of remote device to be accepted.
 * RETURNS
 *  BTHFResult: operation result. See also BthfResult.
 *****************************************************************************/
BTHFResult srv_bthf_accept(BTHFHandle srv_hd, U32 dev_id);

/*****************************************************************************
 * FUNCTION
 *  srv_bthf_reject
 * DESCRIPTION
 *  Reject remote device detach request.
 * PARAMETERS
 *  srv_hd: [IN]    Previously opened service, returned by srv_bthf_open.
 *  dev_id: [IN]    ID of remote device to be rejected.
 * RETURNS
 *  BTHFResult: operation result. See also BthfResult.
 *****************************************************************************/
BTHFResult srv_bthf_reject(BTHFHandle srv_hd, U32 dev_id);

/*****************************************************************************
 * FUNCTION
 *  srv_bthf_abort
 * DESCRIPTION
 *  Abort current ongoing operation, abort might has chance failed depending on the timing.
 * PARAMETERS
 *  srv_hd: [IN]    Previously opened service, returned by srv_bthf_open.
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bthf_abort(BTHFHandle srv_hd);

/*****************************************************************************
 * FUNCTION
 *  srv_bthf_abort_all
 * DESCRIPTION
 *  Abort all current ongoing operation, abort might has chance failed depending on the timing.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bthf_abort_all(void);

/*****************************************************************************
 * FUNCTION
 *  srv_bthf_list_device
 * DESCRIPTION
 *  Get current attached device info. If info is NULL, only count of attached device returned.
 * PARAMETERS
 *  dev_list:   [OUT]   Buffer provided by invoker. Will filled with device IDs when success.
 *  count:      [IN]    Count of devices need to be retrieved.
 * RETURNS
 *  U32: Acctual count of devices retrieved.
 *****************************************************************************/
U32 srv_bthf_list_device(U32 *dev_list, U32 count);
    

/*****************************************************************************
 * FUNCTION
 *  srv_bthf_get_device_info
 * DESCRIPTION
 *  Get specific device information.
 * PARAMETERS
 *  dev_id: [IN]    ID of device need to get info.
 *  info:   [OUT]   Infomation result buffer.
 * RETURNS
 *  BTHFResult: operation result. See also BthfResult.
 *****************************************************************************/
BTHFResult srv_bthf_get_device_info(U32 dev_id, bthf_dev_info_struct *info);

/*****************************************************************************
 * FUNCTION
 *  srv_bthf_get_status
 * DESCRIPTION
 *  Get BTHF service status.
 *  if at least one device has been attached, the status will be BTHF_STATUS_ATTACH
 *  if at least one device has switch audio on, the status will be BTHF_STATUS_AUDIO_ON
 *  Otherwise, status will be BTHF_STATUS_DETACH
 * PARAMETERS
 *  void
 * RETURNS
 *  BTHFStatus: See also BthfStatus.
 *****************************************************************************/
BTHFStatus srv_bthf_get_status(void);

/*****************************************************************************
 * FUNCTION
 *  srv_bthf_save_config
 * DESCRIPTION
 *  Change current BTHF service settings.
 * PARAMETERS
 *  item:   [IN]    Setting item class. See also BthfCfg.
 *  value:  [IN]    Setting item value. See also BthfCfg.
 * RETURNS
 *  BTHFResult: operation result. See also BthfResult.
 *****************************************************************************/
BTHFResult srv_bthf_save_config(U32 item, void *value);

/*****************************************************************************
 * FUNCTION
 *  srv_bthf_read_config
 * DESCRIPTION
 *  Read current BTHF service settings.
 * PARAMETERS
 *  item:   [IN]    Setting item class. See also BthfCfg.
 * RETURNS
 *  void *: Setting item value. See also BthfCfg.
 *****************************************************************************/
void *srv_bthf_read_config(U32 item);

MMI_BOOL srv_bthf_attach_device(BTHFAddr *addr, BTHFAttachCallback notify);

#ifdef __cplusplus
}
#endif

#endif /* __MMI_HFP_SUPPORT__ */

#endif /* BTHF_SERVICE_GPROT_H */
