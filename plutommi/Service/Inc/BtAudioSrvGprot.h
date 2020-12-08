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
 * BtAudioSrvGprot.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is the header file for external module of Bluetooth audio.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef BT_AUDIO_SRV_GPROT_H
#define BT_AUDIO_SRV_GPROT_H

#include "mmi_features.h"

#include "MmiDataType.h"
#include "BtcmSrvGprot.h"

typedef srv_bt_cm_bt_addr BtAudDevAddr;
typedef U32 BtAudChannel;
enum {
    BTAUD_CHNL_ANY =    0x00, /* Any available audio channel */
    BTAUD_CHNL_MONO =   0x01, /* Only Mono audio channel(HFP or HSP) */
    BTAUD_CHNL_STEREO = 0x02, /* Only Stereo audio channel(A2DP) */
    BTAUD_CHNL_ALL =    0x03
};

typedef U32 BtAudEvent;
enum {
    BTAUD_EV_ATTACH_IND    = 0x01, /* Device has been attached which means at least one audio channel is connected.
                                     all service user can receive this notification */
    BTAUD_EV_ATTACH_FAIL   = 0x02, /* Attach failed, only who start attach
                                    operation can receive this notification */
    BTAUD_EV_DETACH_IND    = 0x04, /* Device has been detached which means all audio channel has been disconnected.
                                    all service user can receive this notification */
    BTAUD_EV_SWITCH_IND    = 0x08, /* Audio path switched.
                                    all service user can receive this notification */
    BTAUD_EV_SWITCH_FAIL   = 0x10, /* Audio path switch fail.
                                    only who start switch operation can receive this notification */
    BTAUD_EV_CHNL_UPDATE   = 0x20, /* Audio channel status updated */
    BTAUD_EV_ATTACH_REQ    = 0x40,
    BTAUD_EV_VOLUME_IND    = 0x80, /* Volume changed by remote device */
    BTAUD_EV_STEREO_CONFIG_IND = 0x100,
    BTAUD_EV_ATTACH_ABORT = 0x200,
    BTAUD_EV_MAX_COUNT
};

typedef U32 BtAudAccessLevel;
enum {
    BTAUD_LEVEL_ADMIN,  /* Has priviledge to attach or detach devices, 
                            only one administrator is allowed in a time */
    BTAUD_LEVEL_NORMAL, /* Has priviledge to switch audio path */
    BTAUD_MODE_NUM
};

typedef U32 BtAudStatus;
enum {
    BTAUD_IDLE,      /* No device connected */
    BTAUD_ACTIVE,    /* Device connected but audio path in local */
    BTAUD_SWITCH_ON  /* Audio path switched to remote device */
};

typedef U32 BtAudDevClass;
enum {
    BTAUD_HEADSET = 1,
    BTAUD_CARKIT,
    BTAUD_UNKNOWN_DEVICE
};

typedef U32 BtAudOption;

typedef void (*BtAudNotify)(BtAudEvent event, U32 arg, void *user_data);

typedef struct {
    BtAudDevAddr addr;
    U32 chnls;
} btaud_device_info;

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __MMI_BT_SUPPORT__
void     srv_btaud_init(void);
void     srv_btaud_deinit(void);
U32      srv_btaud_open(BtAudAccessLevel level, BtAudChannel chnl);
void     srv_btaud_set_notify(U32 srv_hd, U32 events, BtAudNotify notify, void *user_data);
void     srv_btaud_close(U32 srv_hd);

void     srv_btaud_set_option(U32 srv_hd, BtAudOption item, U32 value);
U32      srv_btaud_get_option(U32 srv_hd, BtAudOption option);

MMI_BOOL srv_btaud_attach(U32 srv_hd, const BtAudDevAddr *device);
void     srv_btaud_detach(U32 srv_hd);
MMI_BOOL srv_btaud_switch(U32 srv_hd, MMI_BOOL on);
void     srv_btaud_set_volume(U32 volume);
void     srv_btaud_abort(U32 srv_hd);
void     srv_btaud_accept(U32 srv_hd);
void     srv_btaud_reject(U32 srv_hd);
MMI_BOOL srv_btaud_get_device_info(BtAudChannel chnl, btaud_device_info *info);
MMI_BOOL srv_btaud_is_audio_device(const BtAudDevAddr *dev_addr);
#endif /* __MMI_BT_SUPPORT__ */

BtAudStatus srv_btaud_get_status(BtAudChannel chnl);
MMI_BOOL srv_btaud_get_active_device(BtAudChannel chnl, btaud_device_info *info);
MMI_BOOL srv_btaud_stereo_notify(const BtAudDevAddr *addr);
MMI_BOOL srv_btaud_switchable(BtAudChannel chnl);
BtAudDevClass srv_btaud_get_device_class(void);


#ifdef __cplusplus
}
#endif

#endif /* BT_AUDIO_SRV_GPROT_H */

