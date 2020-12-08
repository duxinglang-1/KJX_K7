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
 *   w32_keys.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of keypad driver simulation for WIN32 environment
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef WIN32_KEYS_H
#define WIN32_KEYS_H

#include "task_config.h"
#include "kbd_table.h"
#include "device.h"
#include "drvsignals.h"
#include <assert.h>
#include "w32_keypad_sw.h"

typedef enum win32_ext_key_enum_
{
    WIN32_EXT_KEY_1,
    WIN32_EXT_KEY_2,
    WIN32_EXT_KEY_3,
    WIN32_EXT_KEY_4,
    WIN32_EXT_KEY_5,
    WIN32_EXT_KEY_6,
    WIN32_EXT_KEY_7,
    WIN32_EXT_KEY_8,
    WIN32_EXT_KEY_9,
    WIN32_EXT_KEY_0,
    WIN32_EXT_KEY_STAR,
    WIN32_EXT_KEY_HASH,
    WIN32_EXT_KEY_SK_LEFT,
    WIN32_EXT_KEY_SK_RIGHT,
    WIN32_EXT_KEY_SEND,
    WIN32_EXT_KEY_END,
    WIN32_EXT_KEY_UP,
    WIN32_EXT_KEY_DOWN,
    WIN32_EXT_KEY_LEFT,
    WIN32_EXT_KEY_RIGHT,
    WIN32_EXT_KEY_MENU,
    WIN32_EXT_KEY_FUNCTION,
    WIN32_EXT_KEY_VOL_UP,
    WIN32_EXT_KEY_VOL_DOWN,
    WIN32_EXT_KEY_POWER,
    WIN32_EXT_KEY_CLEAR,
    WIN32_EXT_KEY_MP3_FWD,
    WIN32_EXT_KEY_MP3_PLAY_STOP,
    WIN32_EXT_KEY_MP3_BACK,
#ifdef __SENDKEY2_SUPPORT__
    WIN32_EXT_KEY_SEND2,
#endif /* __SENDKEY2_SUPPORT__ */

    WIN32_EXT_KEY_COUNT
} win32_ext_key_enum;

// MoDIS code use kbd_event_enum as kbd_event
typedef kbd_event kbd_event_enum;
// keypad mapping table used in MAUI
extern const keypad_struct  keypad_custom_def;
/* use KAL service for timer */
#define KBD_TIMER_USE_KAL_SERVICE
/* turn on it for debugging */
//#define KBD_UNIT_DEBUG
#undef KBD_UNIT_DEBUG

#define  DRV_KBD_BUFFER_SIZE            1024  
#define KBD_TIMER_LONGPRESS_MIILLISECONDS  (1500)
#define KBD_TIMER_REPEAT_MIILLISECONDS     (1000)
#if defined(KBD_TIMER_USE_KAL_SERVICE)
#define KBD_TIMER_LONGPRESS_TICKS   (KBD_TIMER_LONGPRESS_MIILLISECONDS * KAL_TICKS_500_MSEC / 500)
#define KBD_TIMER_REPEAT_TICKS      (KBD_TIMER_REPEAT_MIILLISECONDS * KAL_TICKS_500_MSEC / 500)
#else
#endif

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef struct
{
	LOCAL_PARA_HDR
		keypad_status_enum keypad_status;
	keypad_code_enum keypad_code;
} uemdrv_keypad_ind_struct;

typedef struct 
{
	kal_uint8 logical_key;
} key_hw2sw_struct;

typedef struct
{
	kbd_event_enum    Keyevent;
	kal_uint8         Keydata[1];
} kbd_data_struct;

typedef struct
{
	kbd_data_struct   kbd_data_buffer[DRV_KBD_BUFFER_SIZE];
	kal_uint8         kbd_data_buffer_rindex;
	kal_uint8         kbd_data_buffer_windex;
	int			      sum;
} kbd_buffer_struct_modis;

#define MAX_KEY_SUPPORT_NUM 127
#define DRV_KEY_DOWN 0
#define DRV_KEY_UP   1
#define DRV_NORMAL_KEY 0
#define DRV_SPECIAL_KEY 1 
//Normal Key or Special

extern int gReady_To_Change_Key_Mode;
extern void w32_key_detect_ind(unsigned char key_status, unsigned char key_code);
extern kal_bool kbd_two_key_detection_switch(kal_bool enable);
extern kal_bool w32_key_det_mode_switch( unsigned char keymode_num_to_switch );
// This function is defined in keypad_sw.h, no more need to declare here
//extern kal_bool kbd_key_det_mode_switch(kal_uint32 mode);
extern kal_bool _Kbd_GetKeyData(kbd_data_struct *keydata);
extern kal_bool _Kbd_PeekBuffer(kbd_data *keydata, kal_bool specify_read, 
							   kal_uint32 read_pointer,kal_uint32* current_read_pointer);

#endif /* WIN32_KEYS_H */ 

