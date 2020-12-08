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

/*******************************************************************************
 * Filename:
 * ---------
 * mmi_frm_input.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for MMI keypad config function.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/


#ifndef MMI_FRM_INPUT_H
#define MMI_FRM_INPUT_H

#include "MMI_features.h"
#include "app_ltlcom.h"    
#include "kal_general_types.h"	 
#include "MMIDataType.h"
/***************************************************************************** 
* Define
*****************************************************************************/
/*----------------------------------------------------------------*
  Key
 *----------------------------------------------------------------*/
/* driver key event which is used for key & touch events */
#define DRV_WM_KEYPRESS                     (kbd_onekey_press)
#define DRV_WM_KEYRELEASE                   (kbd_onekey_release)
#define DRV_WM_KEYLONGPRESS                 (kbd_onekey_longpress)
#define DRV_WM_KEYREPEATED                  (kbd_onekey_repeated)
#define DRV_WM_KEYFULLPRESS                 (kbd_onekey_fullpress)
#define DRV_WM_ENABLE_TWOKEY_DETECTION      (kbd_twokey_detection_enable)
#define DRV_WM_ENABLE_THREEKEY_DETECTION    (kbd_threekey_detection_enable)
#define DRV_WM_DISABLE_MULTIKEY_DETECTION   (kbd_multikey_detection_disable)

/***************************************************************************** 
* Typedef 
*****************************************************************************/

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
typedef enum
{
    MMI_FRM_QWERTY_MODE_NONE,
    MMI_FRM_QWERTY_MODE_STANDARD,
    MMI_FRM_QWERTY_MODE_NUMBER
}mmi_frm_qwerty_keypad_mode_enum;
#endif /* __MMI_QWERTY_KEYPAD_SUPPORT__ */

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 action;
    kal_uint16 x;
    kal_uint16 y;
}mmi_frm_screen_touch_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8 result;
}mmi_frm_screen_touch_rsp_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 mode;
    kal_uint8 orient;
}mmi_frm_screen_touch_orient_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8 result;
    kal_uint8 mode;
}mmi_frm_screen_touch_orient_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 action;
    kal_uint16 x;
    kal_uint16 y;
}mmi_frm_screen_touch_report_rsp_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 mode;
}mmi_frm_screen_touch_report_req_struct;

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
/*----------------------------------------------------------------*
  Key
 *----------------------------------------------------------------*/
extern MMI_BOOL g_keypad_flag;

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
extern void mmi_frm_init_key_event(void);
extern void mmi_frm_key_event_screen_switch_action(void);
extern MMI_BOOL mmi_frm_dispatch_key_event(S16 mmi_key_code, S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag);
extern void mmi_frm_init_kpd_bf_pwon(void);
extern void mmi_frm_process_key_in_nvarm(void * para_buff);
#ifdef __MMI_SUBLCD_MASTER_MODE__
extern void mmi_frm_switch_key_func_ptr(void);
#endif /* __MMI_SUBLCD_MASTER_MODE__ */
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
extern void mmi_frm_qwerty_init(void);
extern MMI_BOOL mmi_frm_qwerty_is_special_key(S16 mmi_key_code);
extern S16 mmi_frm_qwerty_get_opposite_key_code(S16 mmi_key_code);
extern S16 mmi_frm_qwerty_convert_key_code(S16 mmi_key_code);
extern void mmi_frm_qwerty_get_translated_code_and_special_key_flag(S16 mmi_key_code, U16 *ucs2_value, U32 *special_key_flag);
extern void mmi_frm_qwerty_set_keypad_mode(mmi_frm_qwerty_keypad_mode_enum key_mode);
#endif /* __MMI_QWERTY_KEYPAD_SUPPORT__ */
#ifdef __MMI_HANDWRITING_PAD__
extern void mmi_frm_convert_pen_event_to_key_event(S16 mmi_key_type, U8 device_key_code);
#endif /* __MMI_HANDWRITING_PAD__ */
extern void set_scrn_layer_id(MMI_ID group_id, MMI_ID scrn_id);
extern void get_scrn_layer_id(MMI_ID *group_id, MMI_ID *scrn_id);
extern void clear_scrn_layer_key_proc(void);
#endif /* MMI_FRM_INPUT_H */ 


