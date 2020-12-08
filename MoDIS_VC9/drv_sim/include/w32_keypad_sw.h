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
 *    keypad_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for keypad driver and adaption.
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _W32_KEYPAD_SW_H
#define _W32_KEYPAD_SW_H

#include "drv_features.h"
#include    "kal_release.h"
#include "intrCtrl.h"
#include "kal_non_specific_general_types.h"
#include "drv_comm.h"
#if !defined(__WISDOM__) || defined(L4_NOT_PRESENT)
#define KBD_PUSH_ONEKEY_TO_KBDBUFFER kbd_push_onekey_to_kbdbuffer
#define KBD_GPTI_STARTITEM(a,b,c,d) GPTI_StartItem(a,b,c,d)
#define KBD_GPTI_GETHANDLE(a) GPTI_GetHandle(a)
#define KBD_GPTI_STOPITEM(a) GPTI_StopItem(a)
#define KBD_GPTI_RELEASEHANDLE(a) GPTI_ReleaseHandle(a)
#else
#define DRV_KBD_ONLY_UP_DOWN_KEY
#define KBD_PUSH_ONEKEY_TO_KBDBUFFER kbd_push_onekey_to_kbdbuffer_ilm
#define KBD_GPTI_STARTITEM(a,b,c,d) 0
#define KBD_GPTI_GETHANDLE(a)       0
#define KBD_GPTI_STOPITEM(a)        ;
#define KBD_GPTI_RELEASEHANDLE(a) ;
#endif  //#if !defined(WISDOM_MMI) || defined(L4_NOT_PRESENT)

#if defined(__EXTEND_QWERTY_KEYPAD__)
// Not unmask KBD IRQ under extend key, unless all key are released.

//#define KBD_IRQUnmask(a) ;

#define KBD_MASKIRQ          SetINTMask(IRQ_KPAD_CODE)
#define KBD_UNMASKIRQ      RestoreINTMask(IRQ_KPAD_CODE)
#else

#define KBD_MASKIRQ          IRQMask(IRQ_KPAD_CODE)
#define KBD_UNMASKIRQ      IRQUnmask(IRQ_KPAD_CODE)

//#define KBD_IRQUnmask(a)      IRQUnmask(a)
#endif //#if defined(__EXTEND_QWERTY_KEYPAD__)

/* #define TWO_KEY_ENABLE */
/*#define KBD_DBGMODE */    /*to check buffer full when MMI is too slow */
#if defined(__TWO_KEY_DETECTION_SWITCHABLE__)
   #define KBD_KEY_DETECTION_CNT 2

   #ifdef __EXTRA_A_B_KEY_SUPPORT__
      #define KBD_GPT_HDL_CNT    4
   #else /*__EXTRA_A_B_KEY_SUPPORT__*/
      #define KBD_GPT_HDL_CNT    2
   #endif/*__EXTRA_A_B_KEY_SUPPORT__*/

#elif defined(__THREE_KEY_DETECTION_SWITCHABLE__)
   #define KBD_KEY_DETECTION_CNT 3

   #ifdef __EXTRA_A_B_KEY_SUPPORT__
      #define KBD_GPT_HDL_CNT    5
   #else /*__EXTRA_A_B_KEY_SUPPORT__*/
      #define KBD_GPT_HDL_CNT    3
   #endif/*__EXTRA_A_B_KEY_SUPPORT__*/


#else
    #define KBD_KEY_DETECTION_CNT 1
    #define KBD_GPT_HDL_CNT    1
//   #define KBD_DETECT_ONLY_ONE_KEY
#endif /* __TWO_KEY_DETECTION_SWITCHABLE__ */

typedef enum {
   kbd_1_key_det_mode = 0,
   kbd_2_keys_det_mode,
   kbd_3_keys_det_mode
} kbd_key_det_mode;

#if defined(TWO_KEY_ENABLE)
   #if defined(__TWO_KEY_DETECTION_SWITCHABLE__) || defined(__THREE_KEY_DETECTION_SWITCHABLE__)
   #error " kbd config conflicts!!"
   #endif
#endif

#if defined(DRV_KBD_25_KEYS) || defined(FPGA)
   #define  kbd_allkeys          25
   #define  KBD_ROW              5
   #define  KBD_COLUMN_MASK      0x1F //5 bits mask
   #define  KBD_COLUMN           5
#elif defined(DRV_KBD_36_KEYS)
   #define  kbd_allkeys          36
   #define  KBD_ROW              6
   #define  KBD_COLUMN_MASK      0x3F //6 bits mask
   #define  KBD_COLUMN           6
#elif defined(DRV_KBD_42_KEYS)
   #define  kbd_allkeys          42   
   #define  KBD_ROW              6
   #define  KBD_COLUMN_MASK      0x3F //6 bits mask
   #define  KBD_COLUMN           7
#elif defined(DRV_KBD_35_KEYS)
   #define  kbd_allkeys          35
   #define  KBD_ROW              5
   #define  KBD_COLUMN_MASK      0x1F //5 bits mask
   #define  KBD_COLUMN           7
#elif defined(DRV_KBD_54_KEYS)
   #define  kbd_allkeys          54
   #define  KBD_ROW              6
   #define  KBD_COLUMN_MASK      0x3F //6 bits mask
   #define  KBD_COLUMN           9
#elif defined(DRV_KBD_72_KEYS)
   #define  kbd_allkeys          72
   #define  KBD_ROW              8
   #define  KBD_COLUMN_MASK      0xFF //8 bits mask
   #define  KBD_COLUMN           9
#elif defined(DRV_KBD_55_KEYS)
   #define  kbd_allkeys          55
   #define  KBD_ROW              5
   #define  KBD_COLUMN_MASK      0xFF //8 bits mask
   #define  KBD_COLUMN           11  //simulate 5*11,while the real col and row is 5*5 
#elif defined(DRV_KBD_NOT_EXIST)
   #define  kbd_allkeys          1
   #define  KBD_ROW              1
   #define  KBD_COLUMN_MASK      0x1 //1 bits mask
   #define  KBD_COLUMN           1
#endif   /*DRV_KBD_25_KEYS,FPGA*/

#define  kbd_buffer_size         32

#define EVENT_REQUESTED  (KBD_STATUS_CHANGE_EVENT|KBD_SWITCH_DETCTION_MODE_EVENT |KEY_UP_EVENT| KEY_DOWN_EVENT| KEY_RIGHT_EVENT | KEY_LEFT_EVENT)

/*keypad*/
typedef enum {
      low_key=0,
#if defined(DRV_KBD_32KEYS_ABOVE)
      medium_key,
#elif defined(DRV_KBD_48KEYS_ABOVE)
      medium_key,
      medium_key1,
#elif defined(DRV_KBD_64KEYS_ABOVE)
      medium_key,
      medium_key1,
      medium_key2,
#endif      
      high_key

} kbd_type;
/*keypad*/
typedef enum {
      kbd_onekey_press=0,
      kbd_onekey_release,
#ifdef TWO_KEY_ENABLE
      kbd_twokey_press,
      kbd_twokey_release,
#endif   /*TWO_KEY_ENABLE*/
      kbd_onekey_longpress,
      kbd_onekey_repeated,
      kbd_onekey_fullpress,
      kbd_twokey_detection_enable,
      kbd_threekey_detection_enable,
      kbd_multikey_detection_disable
} kbd_event;

typedef struct
{
   kbd_event   Keyevent;
#ifdef TWO_KEY_ENABLE
   kal_uint8   Keydata[2];
#else /*!TWO_KEY_ENABLE*/
   kal_uint8   Keydata[1];
#endif   /*TWO_KEY_ENABLE*/
#if defined(__TC01__)
/* under construction !*/
#endif
} kbd_data;
typedef struct
{
    kal_uint32  kbdmap_reg;
#if defined(DRV_KBD_32KEYS_ABOVE) || defined(DRV_KBD_48KEYS_ABOVE) || defined(DRV_KBD_64KEYS_ABOVE)
    kal_uint32   kbdmap_reg1;
 #endif   /*DRV_KBD_32KEYS_ABOVE*/
   #if defined(DRV_KBD_64KEYS_ABOVE)
   kal_uint32    kbdmap_reg2;
   #endif
}kbd_map_reg_struct;

typedef enum
{
    KEY_DIRECTION_EVENT_NUll,
    KBD_STATUS_CHANGE_EVENT = 0x01, /*keypad status changes event id */
    KBD_SWITCH_DETCTION_MODE_EVENT = 0x02, /*keypad switch detection mode event id*/
    
    KEY_UP_EVENT = 0x10,
    KEY_DOWN_EVENT = 0x20,
    KEY_LEFT_EVENT = 0x40,
    KEY_RIGHT_EVENT = 0x80,
    KEY_DIRECTION_EVENT_ALL = 0xF0
}kbd_task_event;

typedef struct
{
   kal_hisrid        hisr;
   kal_eventgrpid    event;
#if defined(__KBD_JOYSTICK_SUPPORT__)
   kal_uint8         gpthandle;
#else
   #ifdef __EXTRA_A_B_KEY_SUPPORT__
      kal_uint8      gpthandle[KBD_GPT_HDL_CNT];
      kal_bool       ext_status[2];
      #else /*__EXTRA_A_B_KEY_SUPPORT__*/
      kal_uint8         gpthandle[KBD_GPT_HDL_CNT];
      #endif/*__EXTRA_A_B_KEY_SUPPORT__*/
#endif

   #ifdef __KBD_2STEP_KEY_SUPPORT__
   kal_uint8         kbd_2key_handle;   
   #endif
#if defined(__EXTEND_QWERTY_KEYPAD__)
   kal_uint8         kbd_extend_gpthandle;
   kal_uint32        polling_timeout;
#endif //#if defined(__EXTEND_QWERTY_KEYPAD__)
   kal_uint32        longpress_timeout;
   kal_uint32        repeat_time;

#if defined(__KBD_JOYSTICK_SUPPORT__)
   kal_uint32        kbdmap_reg;
   #if defined(DRV_KBD_32KEYS_ABOVE) || defined(DRV_KBD_48KEYS_ABOVE) || defined(DRV_KBD_64KEYS_ABOVE)
      kal_uint32        kbdmap_reg1;
   #endif   /*DRV_KBD_32KEYS_ABOVE*/
   #if defined(DRV_KBD_64KEYS_ABOVE)
      kal_uint32        kbdmap_reg2;
   #endif   /*DRV_KBD_64KEYS_ABOVE*/
#endif
} kbd_struct;

typedef struct
{
   kbd_data       kbd_data_buffer[kbd_buffer_size];
   kal_uint8      kbd_data_buffer_rindex;
   kal_uint8      kbd_data_buffer_windex;
} kbd_buffer_struct;

/*Customizae Keypad*/
typedef struct {
	/*keypad mapping*/
#if defined(DRV_KBD_DRVTOOL_EXTEND_72_KEYS)
   kal_uint8 keypad[72];//kbd_allkeys+KBD_COLUMN*2]; //reserve one GND row and GPO row.   
#else
   kal_uint8 keypad[kbd_allkeys];
#endif//#if defined(DRV_KBD_DRVTOOL_EXTEND_72_KEYS)
#if defined(__EXTEND_QWERTY_KEYPAD__)
   kal_uint16 kbd_extend_row_GPO;  //extend row use which GPO
#endif //#if defined(__EXTEND_QWERTY_KEYPAD__)
	/*power on period*/
   kal_uint32 Custom_Keypress_Period;
   /*power key  position*/
   kal_uint8 powerkey_position;   
} keypad_struct;

typedef struct {  
   const keypad_struct * (*keypad_Get_Data)(void);
   #ifdef __KBD_2STEP_KEY_SUPPORT__   
   kal_bool (*keypad_is_fullpress)(kal_uint8 key);
   kal_bool (*keypad_check_fullpress)(void);   
   #endif 
}keypad_customize_function_struct;  

#if defined(__EXTEND_QWERTY_KEYPAD__)

typedef struct
{
    kal_bool    key_column_all_low_GND[KBD_COLUMN]; //column all low cause by GND_ROW
    kal_bool    key_column_all_low_GPO[KBD_COLUMN]; //column all low cause by GPO_ROW
}keypad_Ext_QwertyKey_Status;
 typedef struct
 {
    kal_bool    key_column_all_low_GND[KBD_COLUMN]; //column all low cause by GND_ROW
    kal_bool    key_column_all_low_GPO[KBD_COLUMN]; //column all low cause by GPO_ROW
    
    kal_uint8   kbd_press_GND_column[KBD_KEY_DETECTION_CNT]; // which column pressed
    kal_uint8   kbd_press_GPO_column[KBD_KEY_DETECTION_CNT]; // which column pressed
 }keypad_Ext_QwertyKey_detect_info_struct;
 
#endif

 /*keypad detect keys result during one key event*/
 typedef struct 
 {
 #if defined(__EXTEND_QWERTY_KEYPAD__)
        keypad_Ext_QwertyKey_detect_info_struct  kbd_Ext_Qwerty_key_info;
#endif
    kal_uint8   key_presscount;
    kal_uint8   key_releasecount;
    kal_uint8   key_total_count;

    kal_uint8   kbd_press_key[KBD_KEY_DETECTION_CNT];
    kal_uint8   kbd_release_key[KBD_KEY_DETECTION_CNT];

 } keypad_detect_info_struct;

typedef enum
{
    Normal_ROW = 0,
    Ext_GPO_ROW,
    Ext_GND_ROW
}Keypad_ROW_Type;

/*every key information*/
 typedef struct
 {
    kal_bool bKeyStatus;                /*0: press; 1: release */
    kal_uint16 key_index;               /*key index defined during customization*/

#if defined(__EXTEND_QWERTY_KEYPAD__)
    kal_uint8 key_column;             /*extend keys in which column*/  
    Keypad_ROW_Type Row_Type;
#endif
 }keypad_key_info;

typedef struct
{
    kbd_map_reg_struct kbd_map_reg;    
#if defined(__EXTEND_QWERTY_KEYPAD__)
    kal_bool    key_column_all_low_GND[KBD_COLUMN]; //column all low cause by GND_ROW
    kal_bool    key_column_all_low_GPO[KBD_COLUMN]; //column all low cause by GPO_ROW
#endif

}keypad_status_struct;

#if !defined(KBD_DETECT_ONLY_ONE_KEY) && defined(__EXTRA_A_B_KEY_SUPPORT__)
      extern const kal_uint8    EXTRA_A_KEY_EINT_NO;
      extern const kal_uint8    EXTRA_B_KEY_EINT_NO;
      #define  EINT_A_KEY     EXTRA_A_KEY_EINT_NO
      #define  EINT_B_KEY     EXTRA_B_KEY_EINT_NO
#endif

#if defined(__TC01__)
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
#else
#define kbd_push_time_stamp() ;
#define kbd_pop_time_stamp(_key_data) ;
#endif


#define kbd_push_onekey_to_kbdbuffer(_event,_key)   \
{\
   ASSERT(kbd_push_assert == KAL_FALSE);\
   kbd_push_assert = KAL_TRUE;\
   kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_windex].Keyevent = (_event);\
   kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_windex].Keydata[0] = (_key);\
   kbd_push_time_stamp();\
   kbd_buffer.kbd_data_buffer_windex++;\
   kbd_buffer.kbd_data_buffer_windex &= (kbd_buffer_size-1);\
   kbd_push_assert = KAL_FALSE;\
}

#define kbd_push_onekey_to_kbdbuffer_ilm(_event,_key)   \
{\
   kbd_push_onekey_to_kbdbuffer((_event),(_key));\
   DRV_BuildPrimitive(Kp_ilm, MOD_DRVKBD, MOD_UEM, MSG_ID_DRVUEM_KEYPAD_IND, NULL);\
   msg_send_ext_queue(Kp_ilm);\
}

#define kbd_push_twokey_to_kbdbuffer(_event,_key1,_key2)   \
{\
   ASSERT(kbd_push_assert == KAL_FALSE);\
   kbd_push_assert = KAL_TRUE;\
   kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_windex].Keyevent = (_event);\
   kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_windex].Keydata[0] = (_key1);\
   kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_windex].Keydata[1] = (_key2);\
    kbd_push_time_stamp();\
   kbd_buffer.kbd_data_buffer_windex++;\
   kbd_buffer.kbd_data_buffer_windex &= (kbd_buffer_size-1);\
   kbd_push_assert = KAL_FALSE;\
}

#define kbdbuffer_get_roomleft(_left)   \
{\
   if ( kbd_buffer.kbd_data_buffer_rindex <= kbd_buffer.kbd_data_buffer_windex ) \
	{\
      _left = kbd_buffer_size - kbd_buffer.kbd_data_buffer_windex + kbd_buffer.kbd_data_buffer_rindex - 1;\
	}\
	else\
	{\
		_left = kbd_buffer.kbd_data_buffer_rindex - kbd_buffer.kbd_data_buffer_windex - 1;\
	}\
}

#ifdef TWO_KEY_ENABLE
   #define kbd_pop_twokey_from_kbdbuffer(_key_data)   \
   {\
     kbd_data* key_data = (kbd_data*)(_key_data);\
      ASSERT(kbd_pop_assert == KAL_FALSE);\
      kbd_pop_assert = KAL_TRUE;\
      key_data->Keyevent = kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_rindex].Keyevent;\
      key_data->Keydata[0] = kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_rindex].Keydata[0];\
      key_data->Keydata[1] = kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_rindex].Keydata[1];\
       kbd_pop_time_stamp(_key_data);\
      kbd_buffer.kbd_data_buffer_rindex++;\
      kbd_buffer.kbd_data_buffer_rindex &= (kbd_buffer_size-1);\
      kbd_pop_assert = KAL_FALSE;\
   }
#else /*!TWO_KEY_ENABLE*/
   #define kbd_pop_onekey_from_kbdbuffer(_key_data)   \
   {\
          kbd_data* key_data = (kbd_data*)(_key_data);\
      ASSERT(kbd_pop_assert == KAL_FALSE);\
      kbd_pop_assert = KAL_TRUE;\
      key_data->Keyevent = kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_rindex].Keyevent;\
      key_data->Keydata[0] = kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_rindex].Keydata[0];\
     kbd_pop_time_stamp(_key_data);\
      kbd_buffer.kbd_data_buffer_rindex++;\
      kbd_buffer.kbd_data_buffer_rindex &= (kbd_buffer_size-1);\
      kbd_pop_assert = KAL_FALSE;\
   }
#endif   /*TWO_KEY_ENABLE*/


#ifdef TWO_KEY_ENABLE
   #define kbd_peek_twokey_from_kbdbuffer_index(_key_data, _index)   \
   {\
      kbd_data* key_data = (kbd_data*)(_key_data);\
      kal_uint8 index = (kal_uint8)(_index);\
      ASSERT(index != kbd_buffer_size);\
      key_data->Keyevent = kbd_buffer.kbd_data_buffer[index].Keyevent;\
      key_data->Keydata[0] = kbd_buffer.kbd_data_buffer[index].Keydata[0];\
      key_data->Keydata[1] = kbd_buffer.kbd_data_buffer[index].Keydata[1];\
   }
#else /*!TWO_KEY_ENABLE*/
   #define kbd_peek_onekey_from_kbdbuffer_index(_key_data, _index)   \
   {\
    kbd_data* key_data = (kbd_data*)(_key_data);\
      kal_uint8 index = (kal_uint8)(_index);\
      ASSERT(index != kbd_buffer_size);\
      key_data->Keyevent = kbd_buffer.kbd_data_buffer[index].Keyevent;\
      key_data->Keydata[0] = kbd_buffer.kbd_data_buffer[index].Keydata[0];\
   }
#endif   /*TWO_KEY_ENABLE*/

// MoDIS parser skip start
// The following are private APIs
extern void keypad_customize_init(void);
// MoDIS parser skip end

// MoDIS parser skip start
// The following APIs are implemented in other dummy API files
extern kal_bool kbd_key_det_mode_switch(kbd_key_det_mode mode);
extern kal_bool kbd_IsKeyButtonSupported(kal_uint8 key);
// MoDIS parser skip end

extern kal_bool PowerKey_Pressed(void);
extern kal_bool kbd_is_mutiple_key(kal_uint8 key);
extern kal_bool kbd_IsKeyPressed(kal_uint8 key);

extern kal_uint32 Kbd_GetKeyEventCount(void);

extern kal_uint32 kbd_PutKeyData(kal_uint8 key);

#if defined(JOGBALL_SUPPORT)
extern void Jogball_Init(void);
extern void Jogball_Reset(void);
#endif //#if defined(JOGBALL_SUPPORT)


#include "us_timer.h"
extern kal_uint32 L1I_GetTimeStamp(void);
#define KBD_GetTimeStamp L1I_GetTimeStamp
#if defined(__MTK_INTERNAL__) && !defined(LOW_COST_SUPPORT) && !defined(__MAUI_BASIC__) && defined(__DRV_DBG_MEMORY_TRACE_SUPPORT__) && defined(__EXTEND_QWERTY_KEYPAD__)
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
#else //#if defined(__MTK_INTERNAL__) && !defined(LOW_COST_SUPPORT)
#define KBD_DBG(a,b,c,d) ;
#endif //#if defined(__MTK_INTERNAL__) && !defined(LOW_COST_SUPPORT)


#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_KBD_REG_DBG__)
#define DRV_KBD_WriteReg(addr,data)              DRV_DBG_WriteReg(addr,data)
#define DRV_KBD_Reg(addr)                        DRV_DBG_Reg(addr)                      
#define DRV_KBD_WriteReg32(addr,data)            DRV_DBG_WriteReg32(addr,data)          
#define DRV_KBD_Reg32(addr)                      DRV_DBG_Reg32(addr)                    
#define DRV_KBD_WriteReg8(addr,data)             DRV_DBG_WriteReg8(addr,data)           
#define DRV_KBD_Reg8(addr)                       DRV_DBG_Reg8(addr)                     
#define DRV_KBD_ClearBits(addr,data)             DRV_DBG_ClearBits(addr,data)           
#define DRV_KBD_SetBits(addr,data)               DRV_DBG_SetBits(addr,data)             
#define DRV_KBD_SetData(addr, bitmask, value)    DRV_DBG_SetData(addr, bitmask, value)  
#define DRV_KBD_ClearBits32(addr,data)           DRV_DBG_ClearBits32(addr,data)         
#define DRV_KBD_SetBits32(addr,data)             DRV_DBG_SetBits32(addr,data)           
#define DRV_KBD_SetData32(addr, bitmask, value)  DRV_DBG_SetData32(addr, bitmask, value)
#define DRV_KBD_ClearBits8(addr,data)            DRV_DBG_ClearBits8(addr,data)          
#define DRV_KBD_SetBits8(addr,data)              DRV_DBG_SetBits8(addr,data)            
#define DRV_KBD_SetData8(addr, bitmask, value)   DRV_DBG_SetData8(addr, bitmask, value) 
#else
#define DRV_KBD_WriteReg(addr,data)              DRV_WriteReg(addr,data)
#define DRV_KBD_Reg(addr)                        DRV_Reg(addr)                      
#define DRV_KBD_WriteReg32(addr,data)            DRV_WriteReg32(addr,data)          
#define DRV_KBD_Reg32(addr)                      DRV_Reg32(addr)                    
#define DRV_KBD_WriteReg8(addr,data)             DRV_WriteReg8(addr,data)           
#define DRV_KBD_Reg8(addr)                       DRV_Reg8(addr)                     
#define DRV_KBD_ClearBits(addr,data)             DRV_ClearBits(addr,data)           
#define DRV_KBD_SetBits(addr,data)               DRV_SetBits(addr,data)             
#define DRV_KBD_SetData(addr, bitmask, value)    DRV_SetData(addr, bitmask, value)  
#define DRV_KBD_ClearBits32(addr,data)           DRV_ClearBits32(addr,data)         
#define DRV_KBD_SetBits32(addr,data)             DRV_SetBits32(addr,data)           
#define DRV_KBD_SetData32(addr, bitmask, value)  DRV_SetData32(addr, bitmask, value)
#define DRV_KBD_ClearBits8(addr,data)            DRV_ClearBits8(addr,data)          
#define DRV_KBD_SetBits8(addr,data)              DRV_SetBits8(addr,data)            
#define DRV_KBD_SetData8(addr, bitmask, value)   DRV_SetData8(addr, bitmask, value) 
#endif //#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_KBD_REG_DBG__)

#endif


