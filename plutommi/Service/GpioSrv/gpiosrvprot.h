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
 * Gpiosrvprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Header file for GPIO Utility Functions
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef GPIO_SRV_PROT_H
#define GPIO_SRV_PROT_H

#include "MMI_features.h"
#include "MMIDataType.h"
#include "gpiosrvgprot.h"
#include "kal_general_types.h"
#include "custom_equipment.h"
#include "device.h"

//#if defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_VUI_SCREEN_LOCK_KEY__)
#define SRV_GPIO_BACKLIGHT_BRIGHT_TIME   (55000) // spend 15 sec from full bright to halfbright
#define SRV_GPIO_BACKLIGHT_DIMMING_TIME  (GPIO_BRIGHTNESS_DIMMING_TIME) // spend 5 sec from halfbright to full dark
/*#else
#define SRV_GPIO_BACKLIGHT_BRIGHT_TIME   (15000) // spend 15 sec from full bright to halfbright
#define SRV_GPIO_BACKLIGHT_DIMMING_TIME  (20000) // spend 20 sec from halfbright to full dark
#endif *//* __COSMOS_MMI_PACKAGE__ */


extern srv_gpio_property_info_struct g_srv_gpio_property_info;

typedef struct
{
    MMI_BOOL is_ready; // MMI_TRUE: GPIO is ready
    SRV_GPIO_PWRON_READY_NOTIFIER ready_callback;
    void * user_data;
} srv_gpio_pwron_ready_struct;

extern MMI_BOOL srv_gpio_emit_event(U16 event_id);
extern void srv_gpio_post_event(U16 event_id);

extern void srv_gpio_send_message(int src_mod_id, U16 msg_id, void *local_param_ptr, void *peer_buf_ptr);

extern void srv_earphone_connect_hdlr(MMI_BOOL is_in);

extern void srv_backlight_set_mode(void *info);
extern void srv_backlight_ctrl_req_hdlr(void *msg, int mod_id , void *peer_buf);
extern U8 srv_backlight_get_real_level(srv_backlight_device_type_enum lcd_type);

extern void srv_backlight_at_set_level_hdlr(void *msg, int source, void *data);
extern void srv_backlight_at_query_level_hdlr(void *msg, int source, void *data);

/* AT handler */
extern void srv_speech_at_set_mute(void *msg);
extern void srv_speech_at_query_mute(void *msg, int mod_id);
extern void srv_speech_at_set_hand_free(void *msg, int source, void *data);
extern void srv_speech_at_query_hand_free(void *msg, int source, void *data);

#endif
