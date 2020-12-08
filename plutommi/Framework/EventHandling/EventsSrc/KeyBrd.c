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
 * Keybrd.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for keypad processing
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
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
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
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
* Include                                                                     
*****************************************************************************/

#include "MMI_features.h"
//#include "GlobalDefs.h"
//#include "mmi_frm_gprot.h"
#include "mmi_frm_prot.h"

#include "kbd_table.h"
#include "dcl.h"
#include "ps_public_utility.h"     /* for l4c_kbd_getkeydata */

#ifdef __TC01__
/* under construction !*/
#endif

#include "VolumeHandler.h"               /* For SetDefaultVolumeKeyHandlers */
//#include "IdleAppDef.h"
//#include "IdleAppProt.h"
//#include "SimDetectionResDef.h"
//#include "SettingDefs.h"
//#include "SettingsGdcl.h"
#ifdef __MMI_EMAIL__
#include "EmailAppGProt.h"
#endif /* __MMI_EMAIL__ */

#include "UCMGProt.h"
#include "UcmSrvGprot.h"

//#include "gpioInc.h"
#include "ScreenRotationGprot.h"
#if defined(__MMI_AVRCP_SUPPORT__)
//#include "BtcmSrvGprot.h"
#include "BTMMIAVRCPGProt.h"
#include "AvrcpSrvGprot.h"
#endif /* defined(__MMI_AVRCP_SUPPORT__) */


#ifdef __MMI_DUAL_SIM_MASTER__
//#include "MTPNP_AD_resdef.h"
//#include "MTPNP_AD_master_if.h"
#endif /* __MMI_DUAL_SIM_MASTER__ */

#include "ShutdownSrvGprot.h"
#include "BootupSrvGprot.h"
#include "IdleGprot.h"
#include "custom_equipment.h"


//RHR Add
#include "MMIDataType.h"
#include "wgui_categories_list.h"
#include "l4a.h"
#include "mmi_frm_input_gprot.h"
#include "GlobalConstants.h"
#include "mmi_frm_input.h"
#include "string.h"
#include "kal_general_types.h"
#include "mmi_msg_struct.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "pluto_fw_trc.h"
#include "kal_trace.h"
#include "MMI_fw_trc.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "stack_ltlcom.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_at_util_gprot.h"
#include "mmi_cb_mgr_gprot.h"
#ifdef __KJX_FUN__
#include "CommonScreensResDef.h"
#if defined(__KJX_MULTI_LANGUAGE__)
#include "Kjx_main.h"
#endif
#if defined(__KJX_LOG_OUTPUT__)
#include "kjx_prin.h"
#endif
#endif

#define KJX_KEYBRD_DEBUG

/***************************************************************************** 
* Define
*****************************************************************************/

/* Please enable this macro to do key events related unit test */
//#define __MMI_FRM_KEY_EVENT_UT__

/* 
 * Element number of g_key_cntx.buffer[], which depends on the max key detection mode supported by driver.
 * Note: if __THREE_KEY_DETECTION_SWITCHABLE__ is defined, 
 * __TWO_KEY_DETECTION_SWITCHABLE__ will also be defined.
 * So the sequence of the following define is important
 */
#if defined(__THREE_KEY_DETECTION_SWITCHABLE__)
#define MAX_DECT_KEY_NUM            (3) /* driver support 1 & 2 & 3 key detection mode */
#elif defined( __TWO_KEY_DETECTION_SWITCHABLE__)
#define MAX_DECT_KEY_NUM            (2) /* driver support 1 & 2 key detection mode */
#else
#ifndef __MMI_FRM_KEY_EVENT_UT__
#define MAX_DECT_KEY_NUM            (1) /* driver only support 1 key detection */
#else
#define MAX_DECT_KEY_NUM            (2) /* in ut mode, support 2 key detection in SW */
#endif
#endif

/*
 * Element number of g_key_cntx.look_ahead[]
 * 
 * When __MMI_FRM_KEY_EVENT_UT__ is enabled, we make 10 entries of the look ahead buffer to test 
 * the whole mechanism without the support of driver or modis.
 *
 * When __MMI_FRM_KEY_EVENT_UT__ is disable, the look ahead buffer's size
 * depends on the mechanism of mmi_frm_clear_key_events.
 * 
 * If MAX_DECT_KEY_NUM == 2, thinking the following scenraio:
 * KEY_1 is being pressed and power(KEY_END or KEY_POWER) key is being pressed
 * KEY_1's up/ power key's long press, repeat and up in driver key buffer
 * then invoke mmi_frm_clear_key_events, we will put key1's up, power key's longpress
 * and power key's up into the look ahead buffer. This case is the max value of the
 * look ahead buffer, so it's length is MAX_DECT_KEY_NUM + 1
 *
 * We will also need to put the detection event back to look ahead buffer
 * But we don't know how many detection event may be cleard.
 * So we set it as 9
 */
#ifdef __MMI_FRM_KEY_EVENT_UT__
#define LOOK_AHEAD_BUF_LEN          (20)
#else
#define LOOK_AHEAD_BUF_LEN          (MAX_DECT_KEY_NUM + 1 + 9)
#endif



/* 
 * Key code number of mmi key code
 *
 * We have three kinds of keypad which are defined in $proj.mak
 * NORMAL_KEYPAD
 * REDUCED_KEYPAD
 * QWERTY_KEYPAD
 *
 * The key code number supported by these three kinds of keypad
 * are different.
 *
 * Note: in reduced keypad project, support the same key code number as the
 *  number key pad project because touch screen may need key module to do something
 */
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
#define MAX_KEY_NUM  MAX_QWERTY_KEYS    /* qwerty keypad */
#else
#define MAX_KEY_NUM  MAX_KEYS           /* number keypad or reduced keypad */
#endif

/* 
 * Function to get key event from key buffer
 *
 * There are 2 source of key events, hardware keypad driver and AT command.
 * Both of them can send a same msg but with different local parameter to MMI
 * In the protocol event handler of this msg, framework will get either of the following
 * function pointer from the local parameter.
 */
//#define KBD_ATCMD_GET_KEY_FUNC   (l4c_kbd_getkeydata) /* AT Command key buffer */
//#define KBD_DRVIER_GET_KEY_FUNC  (get_driver_key_data)     /* hard key buffer */
static MMI_BOOL get_driver_key_data(kbd_data *keydata);


typedef MMI_BOOL (*drv_get_key_evt_func)(kbd_data *);

const static  drv_get_key_evt_func get_key_evt_func[] = 
{
	get_driver_key_data,
	l4c_kbd_getkeydata,

};

/* Macro to judge whether in call or not. */
#define IS_IN_CALL() (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)

/* 
 * Internal error code of the key event handling 
 */
#define KEY_EVENT_DECT          (MAX_KEY_TYPE)         /* detection event */
#define ERR_KEY_EVT_TRANS       (MAX_KEY_TYPE + 1)     /* wrong event flow */
#define ERR_KEY_EVENT           (MAX_KEY_TYPE + 2)     /* wrong event */
#define ERR_KEY_CODE            (MAX_KEY_TYPE + 3)     /* wrong key code */
#define INSERT_SAME_KEY_CODE    (-1000)                /* Insert a key code that is in g_key_cntx.buffer[] */
#define INSERT_CODE_BEYOND_DECT (-1001)                /* Insert a key code that beyond driver detection mode */
#define REMOVE_BUT_NOT_FOUND    (-1002)                /* remove a key code but not found */
#define LOOK_AHEAD_BUF_FULL     (-1003)                /* look ahead buffer full */

/********************************************************************************************************************
 * Content:  keypad state
 * Variable: g_key_cntx.keypad_status (8bit)
 *===============================================================
 * Init state:
 *   qwerty 
 *     0b 01 0 0 0 000  = 0x40
 *   non-qwery
 *     0b 00 0 0 0 000  = 0x00
 *                        
 * State after screen switch:
 *     0b 01 0 x 0 000
 *             
 *     x - Don't change
 *===============================================================
 * Bit0-Bit2: keypad mode
 *            000 - KEYPAD_1KEY_NUMBER
 *            001 - KEYPAD_2KEY_NUMBER
 *            010 - KEYPAD_3KEY_NUMBER
 *            011 - KEYPAD_1KEY_QWERTY
 *            100 - KEYPAD_2KEY_QWERTY
 *            101 - KEYPAD_3KEY_QWERTY
 *            110 - reserved
 *            111 - reserved
 * -----------------------------------------
 * Bit3: reserved
 *
 * -----------------------------------------
 * Bit4: flag of suspend key events handle
 *            0 - not suspend key processing
 *            1 - suspend key processing
 * -----------------------------------------
 * Bit5: reserved
 *
 * -----------------------------------------
 * Bit6-7: key detection mode of driver
 *            00 - DCL_kbd_1_key_det_mode
 *            01 - DCL_kbd_2_keys_det_mode
 *            10 - DCL_kbd_3_keys_det_mode
 *            11 - reserved
 * 
 ********************************************************************************************************************/
#define SET_KPD_MODE(word, mode)            ((word) = ((((U8)(word)) & ~0x07) | ((U8)(mode) & 0x7)))
#define GET_KPD_MODE(word)                  (((word)) & 0x07)
#define KPD_SUSPEND_FLAG                    (4)
#define SET_KEY_DET_MODE(word, mode)        ((word) = ((((U8)(word)) & ~0xC0) | (((U8)((mode) << 6) & 0xC0))))
#define GET_KEY_DET_MODE(word)              (((((word)) & 0xC0) >> 6))

/* keypad state initial value */
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
#define KPD_STATE_PREDEFINE_VAL             (0x40) /* see upper comment */
#else
#define KPD_STATE_PREDEFINE_VAL             (0x00)
#endif

/*********************************************************************************************************************
 * The following value is used to construct key type mapping and key type transform table
 * ---------------------------------
 * g_key_type_map[] 
 *     bit7-5 device key type
 *     bit4-2 mmi key type, 
 *     bit1-0  01-2step key
 *             10-non 2step key
 *             11-both
 *             00-reserved
 * ---------------------------------
 * g_key_type_trans[]
 *     Bit7-5  previous key type
 *     Bit4-2  current key type
 *     Bit1-0  01-2step key
 *             10-non 2step key
 *             11-both
 *             00-reserved
 *********************************************************************************************************************/
#define SET_DEV_KEY_TYPE(type)                   (((type) << 5) & 0xE0)
#define SET_MMI_KEY_TYPE(type)                   (((type) << 2) & 0x1C)
#define SET_PRE_KEY_TYPE(type)                   (((type) << 5) & 0xE0)
#define SET_CUR_KEY_TYPE(type)                   (((type) << 2) & 0x1C)
#define GET_DEV_KEY_TYPE(val)                    (((val) & 0xE0) >> 5)
#define GET_MMI_KEY_TYPE(val)                    (((val) & 0x1C) >> 2)
#define GET_PRE_KEY_TYPE(val)                    (((val) & 0xE0) >> 5)
#define GET_CUR_KEY_TYPE(val)                    (((val) & 0x1C) >> 2)
#define SET_CAT(cat)                             ((cat) & 0x03)
#define GET_CAT(val)                             ((val) & 0x03)
#define KEY_TYPE_MAP(dev_type, mmi_type, cat)    SET_DEV_KEY_TYPE(dev_type) | SET_MMI_KEY_TYPE(mmi_type) | SET_CAT(cat)
#define KEY_TYPE_TRANS(pre_type, cur_type, cat)  SET_PRE_KEY_TYPE(pre_type) | SET_CUR_KEY_TYPE(cur_type) | SET_CAT(cat)

/* 
 * Get key category(key_type_cat_enum) by mmi key code.
 *
 * This key category means 2step or non-2step key when
 * __KBD_2STEP_KEY_SUPPORT__ is enable.
 * or This macro will alway get non-2step key.
 */
#ifdef __KBD_2STEP_KEY_SUPPORT__
#define GET_KEY_CAT(key_code)  (U8)((is_2step_key(key_code) == MMI_TRUE) ? TWO_STEP_KEY : NON_TWO_STEP_KEY)
#else
#define GET_KEY_CAT(key_code)  NON_TWO_STEP_KEY
#endif

#ifdef __MMI_SCREEN_ROTATE__
/* 
 * 4 direction key: UP, DOWN, LEFT, RIGHT
 * When screen rotate is enabled, direction's function may be rotated when screen
 * is rotated
 */
#define DIR_KEY_NUM          (4)
#endif 

/*
 * The following macro is new key event routing related
 */
 
/* get key proc function from table */
#define GET_KEY_PROC(layer)  (g_key_cntx.routing_layer[LAYER_INVOKE_SPACE][layer].key_proc)

/* get user data from table */
#define GET_USER_DATA(layer) (g_key_cntx.routing_layer[LAYER_INVOKE_SPACE][layer].user_data)

/* set event id */
#define MMI_SET_EVENT_ID(evt, id) \
    do                            \
    {                             \
        (evt)->evt_id    = id;    \
    } while(0)

/* construct key event */
#define MMI_CONSTRUCT_KEY_EVENT(evt, mmi_key_code, mmi_key_type, character, flag) \
    do                                                                            \
    {                                                                             \
        (evt)->key_code         = (U8)(mmi_key_code);                             \
        (evt)->key_type         = (U8)(mmi_key_type);                             \
        (evt)->ucs2_value       = (character);                                    \
        (evt)->special_key_flag = (flag);                                         \
    } while(0)


/* key event report mode */
#define  KEY_EVT_REPORT_NONE        (0)
#define  KEY_EVT_REPORT_HW_ONLY     (1)
#define  KEY_EVT_REPORT_HW_AT       (2)

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef enum
{
	L4_KEYPAD_HARDWARE,
	L4_KEYPAD_AT_COMMAND
} L4_keypad_mode_enum;



/*
 * key routing layer space
 * SET_SPACE and INVOKE_SPACE
 * SET_SPACE is for registering key proc
 * INVOKE_SPACE is used to keep the key proc that will recevie event during routing.
 * Before starting routing procedure, copy the SET_SPACE to the INVOKE_SPACE
 * make sure the key proc that will receive events during the routing will not be changed.
 * The set space's key proc will take effect when next key event period start
 */
typedef enum
{
    LAYER_SET_SPACE,
    LAYER_INVOKE_SPACE,
    LAYER_SPACE_TOTAL
} key_layer_space_enum;

/* 
 * 2step key state, this state is used to judge if we need to send half press up only or 
 * we need to send both half press up and full press up. when we are receiving
 * kbd_onekey_release from driver.
 */
typedef enum
{
    HALF_DOWN,
    FULL_DOWN,
    FULL_UP,
    STATE_END
} _2step_state_enum;

/*
 * 2 step key and non-2step have different key type flow
 * we use these enum to distinguish
 */

typedef enum
{
    TWO_STEP_KEY     = 0x1,
    NON_TWO_STEP_KEY = 0x2,
    ALL_TYPE         = 0x3
} key_type_cat_enum;

/* 
 * key code convert function pointer type
 * we group all key code converted functions as a table
 */
typedef S16 (*key_code_cvt_func_ptr)(S16 mmi_key_code);


/*
 * get key handler function pointer type
 * we design a table to manage all functions that get key handler.
 */
typedef FuncPtr (* get_func_ptr)(S16 mmi_key_code, S16 mmi_key_type);


#ifdef __MMI_SCREEN_ROTATE__
/* keypad rotate struct */
typedef struct
{
    U8 rot_degree;           /* rotate degree enum [mmi_frm_screen_rotate_enum] */
    S8 step;                 /* jump step for dir key table */ 
} kpd_rot_struct;
#endif

/* device key code and mmi key code mapping table */
typedef struct
{
    U8 device_key_code;     /* Device key code, see kbd_table.h */
    U8 mmi_key_code;        /* mmi key code, see GlobalConstants.h mmi_keypads_enum */
} key_code_map_struct;


/* device key event */
typedef struct
{
    U8 device_key_code;    /* device key code, see kbd_table.h */
    U8 device_key_type;    /* device key type, see keypad_sw.h */
    MMI_BOOL is_clear;
} dev_key_evt_struct;

/* mmi key event */
typedef struct
{
    S16 mmi_key_code;     /* mmi key code, see GlobalConstants.h mmi_keypads_enum */
    S16 mmi_key_type;     /* mmi key type, see GlobalConstants,h mmi_key_types_enum */
    S16 cvt_code;
    MMI_BOOL is_clear;
} mmi_key_evt_struct;


/* 2step key cntx */
typedef struct
{
    U8 mmi_key_code;
    U8 state;
} _2step_key_struct;

/* key date */
typedef struct
{
    U8 mmi_key_code;       /* mmi key code */
    U8 mmi_key_type;       /* mmi key type */
    U8 cvt_code;           /* converted key code according to current cntx */
    MMI_BOOL is_clear;     /* This flag is used to record if ClearKeyEvent happen when this key code is in active */
    MMI_BOOL is_combo;     /* like SHIFT FN */
    MMI_BOOL is_2step;     /* like CAMERA */
} key_data_struct;


/* 
 * key event routing layer struct 
 * [proc function + user data]
 */
typedef struct
{
    mmi_proc_func key_proc;     /*  proc function */
    void *user_data;            /* user data */
} mmi_key_routing_layer_struct;

/* key cntx */
typedef struct
{
    /* keypad pointer: hardware key or AT command */
    //drv_get_key_func keypad_ptr;
    L4_keypad_mode_enum l4_keypad_mode;
    /* key event report mode */
    U8  key_event_report_mode;  /* 0 no report, 1, report hardware key only, 2 report hareware + AT */

    /* State of keypad, please see comment in Define section for detail */
    U8 keypad_status;  
    /* 
     * bit0-2    keypad mode
     * bit3      reserved
     * bit4      flag of suspend key events handle
     * bit5      reserved
     * bit6-7    key detection mode of driver
     */

    /* key data buffer related */
    key_data_struct buffer[MAX_DECT_KEY_NUM];       /* key data buffer */
    U8 buf_len;                                     /* valid element number in key data buffer */

    /* 2step key related */
#ifdef __KBD_2STEP_KEY_SUPPORT__    
    _2step_key_struct _2step_key;               /* 2step key cntx */
#endif /* __KBD_2STEP_KEY_SUPPORT__ */

    MMI_BOOL is_key_event;                      /* execute current key handler is invoke by key procedure */
    MMI_BOOL is_screen_switch;                  /* is screen switch happen when key is under pressing */
    MMI_BOOL is_send_to_new_scrn;               /* after enter a new screen, if send a key event that not start from key down*/
	MMI_BOOL is_in_end_call_proc;
    
	/* pre post key handler, these will be phase out in the feature */
    PsKeyProcessCBPtr kbd_pre_func;             /* function to be executed before general keypad handler */
    PsKeyProcessCBPtr kbd_post_func;            /* function to be executed after general keypad handler */

    /* key info related */
    U8 curr_key_code;                           /* Keep the current key code */
    U8 curr_key_type;                           /* Keep the current key type */

    /* look ahead buffer related */
    dev_key_evt_struct look_ahead[LOOK_AHEAD_BUF_LEN];  /* buffer */
    U8 num_look_ahead;                                  /* element number */
	U8 r_look_ahead;                                    /* read index */
	U8 w_look_ahead;                                    /* write index */

    /* key proc related */
    U8 wgui_layer_num[LAYER_SPACE_TOTAL];
    mmi_key_routing_layer_struct routing_layer[LAYER_SPACE_TOTAL][MMI_KEY_ROUTING_TOTAL];
    MMI_ID group_id[LAYER_SPACE_TOTAL];
    MMI_ID scrn_id[LAYER_SPACE_TOTAL];
} key_cntx_struct;
/*****************************************************************************
* Local Function                                                              
*****************************************************************************/


/*
 * Major key event handling flow related
 */
static void dev_key_handle(dev_key_evt_struct *dev_evt_p);
static void mmi_key_handle(mmi_key_evt_struct *mmi_evt_p);
static void process_key_event_routing(mmi_frm_key_evt_struct *key_evt_p);
static void exec_key_handler(mmi_key_evt_struct *evt_p);
static void pre_process_dev_evt(dev_key_evt_struct *in, dev_key_evt_struct *out, U8 *out_len);
/*
 * key data buffer related
 */
static void init_key_data_buf(void);
static mmi_ret insert_key_data(key_data_struct * data_p);
static S32 search_key_data(S16 mmi_key_code);
static MMI_BOOL update_key_data(key_data_struct *data_ptr);
static mmi_ret remove_key_data(S16 mmi_key_code);
static S16 get_key_state(S16 mmi_key_code);
static void get_key_data(key_data_struct *data_p, U8 index);
static void pre_update_key_data_buf(key_data_struct *data_p);
static void post_update_key_data_buf(void);
static void gen_key_data(mmi_key_evt_struct *evt, key_data_struct *data_p);
static void set_all_key_data_clear(void);
static void update_clear_state(mmi_key_evt_struct *evt);

/*
 * 2step key related
 */
static MMI_BOOL is_2step_key(S16 mmi_key_code);
#ifdef __KBD_2STEP_KEY_SUPPORT__
static U8 get_2step_key_state(S16 mmi_key_code);
static void pre_update_2step_key_state(S16 mmi_key_code, S16 mmi_key_type);
static void post_update_2step_key_state(S16 mmi_key_code, S16 mmi_key_type);
#endif /* __KBD_2STEP_KEY_SUPPORT__ */

/*
 *  key code/key type related
 */
static MMI_BOOL is_combo_key(S16 mmi_key_code); 
static S16 get_mmi_key_type(U8 device_key_type, U8 cat);
static MMI_BOOL is_legal_key_type(S16 curr_mmi_key_type, S16 pre_mmi_key_type, U8 cat);
static S16 get_mmi_key_code(U8 device_key_code);
static U8 get_device_key_code(U8 mmi_key_code);
static MMI_BOOL get_dev_key_evt(dev_key_evt_struct *dev_evt_p);
static void get_mmi_key_events(dev_key_evt_struct *dev_evt_p, mmi_key_evt_struct *mmi_evt_p);
static void get_exec_key_evt(key_data_struct *data_p, mmi_key_evt_struct *exec_evt_p, U32 *evt_num_p);
static MMI_BOOL is_power_off_key_evt(U8 dev_key_code, U8 dev_key_type);
static MMI_BOOL is_mmi_power_off_key_evt(U8 mmi_key_code, U8 mmi_key_type);
static MMI_BOOL is_valid_mmi_key_event(S16 mmi_key_code, S16 mmi_key_type);
static MMI_BOOL is_detection_evt(U8 device_key_type);
/*
 * key code convert related
 */
#ifdef __MMI_SCREEN_ROTATE__ 
static S16 get_rotated_mmi_key_code(S16 mmi_key_code);
#endif
static S16 mmi_key_code_convert(S16 mmi_key_code, U8 dev_key_type);

/* pre-post key handler related */
static void exec_dynamic_post_key_handler(mmi_key_evt_struct *evt_p);
static MMI_BOOL exec_dynamic_pre_key_handler(mmi_key_evt_struct *evt_p);

/*
 * get key handler related
 */
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__ 
static FuncPtr get_any_key_handler(S16 mmi_key_code, S16 mmi_key_type);
#endif
static FuncPtr get_default_key_handler(S16 mmi_key_code, S16 mmi_key_type);
static FuncPtr get_key_handler(S16 mmi_key_code, S16 mmi_key_type);


/*
 * look ahead buffer related
 */
static MMI_BOOL is_need_write_back(dev_key_evt_struct *dev_p, dev_key_evt_struct *buf, U8 len);
static MMI_BOOL write_look_ahead_buffer(dev_key_evt_struct *dev_evt_p);
static MMI_BOOL read_look_ahead_buffer(dev_key_evt_struct *dev_evt_p);
static MMI_BOOL is_need_merge_detection_evt(dev_key_evt_struct *pre, dev_key_evt_struct *curr);
/*
 * key event unit test related
 */
#ifdef __MMI_FRM_KEY_EVENT_UT__
static S16 key_code_convert_test1(S16 mmi_key_code);
static S16 key_code_convert_test2(S16 mmi_key_code);
static FuncPtr test_key_handler(S16 key_code, S16 key_type);
#endif

/*
 * Misc
 */
static void process_key_ptr_change(void * para_buff);
static void update_key_proc_data(S16 key_type, MMI_BOOL force_update);
static void report_key_evt(U8 dev_key_code, U8 dev_key_type, U32 time_stamp);
static MMI_BOOL is_need_report_to_l4(U8 dev_key_type);
static mmi_ret mmi_sys_key_proc(mmi_frm_key_evt_struct *evt);
static mmi_ret mmi_key_hdlr_proc(mmi_frm_key_evt_struct *evt);
void power_off(void);
static void pre_update_end_call_state(key_data_struct *data);
static void post_update_end_call_state(key_data_struct *data);
static MMI_BOOL is_in_end_call_procedure(void);

/* input mutex related */
static MMI_BOOL mmi_frm_is_input_engine_free(mmi_frm_input_device_type_emun input_device);
static void mmi_frm_get_input_mutex(U8 mmi_key_type);
static void mmi_frm_release_input_mutex(U8 mmi_key_type);
static MMI_BOOL is_driver_key_button_support(kal_uint8 key);

static MMI_BOOL get_driver_key_data(kbd_data *keydata);


/*****************************************************************************
* static Global Variable
*****************************************************************************/

/* key event context */
static key_cntx_struct g_key_cntx;

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
/* 
 * In qwerty project, there are no key handlers for KEY_A.., So in order that
 * application do not need to modify more codes, Any key handler is implemented
 * for the case that application wants handle all keys in one key handler like
 * the following 
 *       SetGroupKeyHandler(XXX, PresentAllKeys, TOTAL_KEYS, XXX)
 * please see SetGroupKeyHandler for more information.
 * The any key handler will also record the dial key for P & W in qwerty project
 * The usage is SetGroupKeyHandler(XXX, PresentAllDialerKeys, TOTAL_DIALER_KEYS, XXX)
 * 
 */
static FuncPtr anyKeyFuncPtrs[MAX_KEY_TYPE] = {0};
#endif

/*****************************************************************************
* Global Variable
*****************************************************************************/

/*
 * Key Event Handler Table
 */
 
#ifdef __MMI_SUBLCD_MASTER_MODE__

/* available slave mode key func ptrs to current screen  */
static FuncPtr currKeyFuncPtrs_slave[MAX_KEYS][MAX_NON_2STEP_KEY_TYPE];
/* available master mode key func ptrs to current screen  */
static FuncPtr currKeyFuncPtrs_master[MAX_KEYS][MAX_NON_2STEP_KEY_TYPE];
/* available key func ptrs to current screen  */
static FuncPtr currKeyFuncPtrs[MAX_KEYS][MAX_NON_2STEP_KEY_TYPE];

#ifdef __KBD_2STEP_KEY_SUPPORT__
static FuncPtr _2step_key_extra_hdlr_slave[MAX_KEY_TYPE - MAX_NON_2STEP_KEY_TYPE];
static FuncPtr _2step_key_extra_hdlr_master[MAX_KEY_TYPE - MAX_NON_2STEP_KEY_TYPE];
static FuncPtr _2step_key_extra_hdlr[MAX_KEY_TYPE - MAX_NON_2STEP_KEY_TYPE];
#endif /* __KBD_2STEP_KEY_SUPPORT__ */

#else

/* available key func ptrs to current screen  */
static FuncPtr currKeyFuncPtrs[MAX_KEYS][MAX_NON_2STEP_KEY_TYPE];

#ifdef __KBD_2STEP_KEY_SUPPORT__
static FuncPtr _2step_key_extra_hdlr[MAX_KEY_TYPE - MAX_NON_2STEP_KEY_TYPE];
#endif /* __KBD_2STEP_KEY_SUPPORT__ */

#endif /* __MMI_SUBLCD_MASTER_MODE__ */

/***************************************************************************** 
* Const Global Variable
*****************************************************************************/

/* 
 * This table is designed to distinguish the app's codes and framework's tricky codes
 * that change the key handler before key handlr is invoked directly.
 * 1. any key handler
 *    In qwerty project, more key code like A, B, C is invoked in our system, 
 *    However, the key handler table is not enlarged because we design translate key 
 *    handler that will receive all key codes and we believe the translate key handler
 *    will be the further way to handle key events. In order to
 *    let application suffer little, we design the any key handler to handle the 
 *    case - applications invoke SetGroupKeyHandler(XXX, PresentAllKeys, TOTAL_KEYS, XXX)
 *    and he wants to handle all keys in one key handler, such as keypad lock in ilde
 *
 */
const static get_func_ptr g_key_handler[] = 
{
#ifdef __MMI_FRM_KEY_EVENT_UT__
    test_key_handler,
#endif
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)    
    get_any_key_handler,
#endif
    get_default_key_handler
};


#ifdef __MMI_SCREEN_ROTATE__
/*
 * we design this 2 table to handle direction key change
 * when screen rotation.
 * 1. direction key is managed in clockwise sequency in table
 *  g_dir_key[]
 * 2. the element of the rotation table has 2 member.
 *    rotation degree, step in g_dir_key[]
 *    For example, 270, -1
 *    if right is recevied, we find it in g_dir_key[]
 *    it's index is 1, so 1 + (-1), we will get UP,
 *    it is the key code we will get
 *    if we support 90 , 180, we will add them to rotation
 *    table.
 *    MMI_FRM_SCREEN_ROTATE_90,  1
 *    MMI_FRM_SCREEN_ROTATE_180, 2
 */
/* keypad rotate data table */
const static kpd_rot_struct g_kpd_rot_data[] =
{
    {MMI_FRM_SCREEN_ROTATE_90, (S8)1},
    {MMI_FRM_SCREEN_ROTATE_90, (S8)2},
    {MMI_FRM_SCREEN_ROTATE_270, (S8)-1}
};

/* direction key table clockwise */
const U8 g_dir_key[] = {KEY_UP_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_LEFT_ARROW};
#endif

/* 
 * key code convert function table 
 *
 *  In our platform, we get device key event from driver and
 *  change it to MMI key event. This change has 2 category
 *  static and dynamic.
 *  static is: getting from mapping table
 *  dynamic is: getting by the following function
 *  1. In QWERTY project, KEY_1 and KEY_E may corresponse to
 *     the same device key code, DEVICE_KEY_1 or DEVICE_KEY_E
 *     if the driver map the DEVICE_KEY_E to the hard key
 *     we will get KEY_E from the mapping table, however whether to
 *     send KEY_1 or KEY_E to application that dependency on the current
 *     keypad mode, mmi_frm_qwerty_convert_key_code will do this convert
 *  2. when screen rotation, the direction key will be rotated also
 *
 */
const static key_code_cvt_func_ptr g_key_code_cvt_tbl[] =
{
#ifdef __MMI_FRM_KEY_EVENT_UT__
    key_code_convert_test1,
    key_code_convert_test2,
#endif
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    mmi_frm_qwerty_convert_key_code,
#endif
#ifdef __MMI_SCREEN_ROTATE__
    get_rotated_mmi_key_code,
#endif
    NULL
};

/*
 * device key event to MMI key event mapping table
 * 
 *   Bit7-5(3bit) device key type
 *   Bit4-2(3bit) mmi key type
 *   Bit1-0(2bit) if normal event, 2 step key's mapping or non-step key's mapping or both
 *                if detection event, detection mode
 * 
 *   we design this table to reduce the switch case and if statement in codes
 */
const static U8 g_key_type_map[] = 
{
#ifdef __KBD_2STEP_KEY_SUPPORT__
    KEY_TYPE_MAP(DRV_WM_KEYPRESS,                   KEY_HALF_PRESS_DOWN, TWO_STEP_KEY),
    KEY_TYPE_MAP(DRV_WM_KEYFULLPRESS,               KEY_FULL_PRESS_DOWN, TWO_STEP_KEY),
#endif /* __KBD_2STEP_KEY_SUPPORT__ */    
    KEY_TYPE_MAP(DRV_WM_KEYPRESS,                   KEY_EVENT_DOWN,      NON_TWO_STEP_KEY), 
    KEY_TYPE_MAP(DRV_WM_KEYRELEASE,                 KEY_EVENT_UP,        ALL_TYPE),
    KEY_TYPE_MAP(DRV_WM_KEYLONGPRESS,               KEY_LONG_PRESS,      ALL_TYPE),
    KEY_TYPE_MAP(DRV_WM_KEYREPEATED,                KEY_REPEAT,          ALL_TYPE),
#if  defined(__TWO_KEY_DETECTION_SWITCHABLE__) || defined(__THREE_KEY_DETECTION_SWITCHABLE__)    
    KEY_TYPE_MAP(DRV_WM_ENABLE_TWOKEY_DETECTION,    MAX_KEY_TYPE,        DCL_kbd_2_keys_det_mode),
#ifdef __THREE_KEY_DETECTION_SWITCHABLE__    
    KEY_TYPE_MAP(DRV_WM_ENABLE_THREEKEY_DETECTION,  MAX_KEY_TYPE,        DCL_kbd_3_keys_det_mode),
#endif /* __THREE_KEY_DETECTION_SWITCHABLE__ */
#endif /*__TWO_KEY_DETECTION_SWITCHABLE__ */
    KEY_TYPE_MAP(DRV_WM_DISABLE_MULTIKEY_DETECTION, MAX_KEY_TYPE,        DCL_kbd_1_key_det_mode)
};

/*
 * MMI key event transition table
 *
 *   Bit7-5(3bit) previous MMI key event
 *   Bit4-2(3Bit) possible current key event
 *   Bit1-0(2bit) 2step, non-2step or both
 *
 *   we design this table to reduce the switch case and if statement in codes
 */
const static U8 g_key_type_trans[] =
{
#ifdef __KBD_2STEP_KEY_SUPPORT__
    KEY_TYPE_TRANS(KEY_EVENT_UP,        KEY_HALF_PRESS_DOWN, TWO_STEP_KEY),
#endif /* __KBD_2STEP_KEY_SUPPORT__ */    
    KEY_TYPE_TRANS(KEY_HALF_PRESS_DOWN, KEY_EVENT_DOWN,      TWO_STEP_KEY),
    KEY_TYPE_TRANS(KEY_HALF_PRESS_DOWN, KEY_EVENT_UP,        TWO_STEP_KEY),   
    KEY_TYPE_TRANS(KEY_EVENT_UP,        KEY_EVENT_DOWN,      NON_TWO_STEP_KEY),
    KEY_TYPE_TRANS(KEY_EVENT_DOWN,      KEY_LONG_PRESS,      ALL_TYPE),
    KEY_TYPE_TRANS(KEY_LONG_PRESS,      KEY_REPEAT,          ALL_TYPE),
    KEY_TYPE_TRANS(KEY_REPEAT,          KEY_REPEAT,          ALL_TYPE),
    KEY_TYPE_TRANS(KEY_REPEAT,          KEY_EVENT_UP,        ALL_TYPE),
    KEY_TYPE_TRANS(KEY_LONG_PRESS,      KEY_EVENT_UP,        ALL_TYPE),
    KEY_TYPE_TRANS(KEY_EVENT_DOWN,      KEY_EVENT_UP,        ALL_TYPE),
};

/*
 * All mmi keys except KEY_CSK & QWERTY keys like KEY_A...
 * are listed in this table. However, in QWERTY project,
 * the array has special means when use it at SetGroupKeyHandler:
 * even though it does not contain qwerty keys, but it means all keys in the keypad.
 * So any key handler is implemented for this. Please see SetGroupKeyHandler for
 * details.
 * This array is mainly used for SetGroupKeyhandler
 */
 
const U16 PresentAllKeys[] =
{
    KEY_0,
    KEY_1,
    KEY_2,
    KEY_3,
    KEY_4,
    KEY_5,
    KEY_6,
    KEY_7,
    KEY_8,
    KEY_9,
    KEY_STAR,
    KEY_POUND,
    KEY_LSK,
    KEY_RSK,
    KEY_UP_ARROW,
    KEY_DOWN_ARROW,
    KEY_LEFT_ARROW,
    KEY_RIGHT_ARROW,
    KEY_SEND,
    KEY_POWER,
    KEY_END,
    KEY_CLEAR,
    KEY_VOL_UP,
    KEY_VOL_DOWN,
    KEY_CAMERA,
    KEY_ENTER,
    KEY_EXTRA_1,
    KEY_EXTRA_2,
#ifdef __SUBLCD_DEDICATED_KEYS_SUPPORT__
    KEY_PLAY_STOP,
    KEY_FWD,
    KEY_BACK,
#endif
#ifdef __EXTRA_A_B_KEY_SUPPORT__
    KEY_EXTRA_A,
    KEY_EXTRA_B,
#endif
#ifdef __SENDKEY2_SUPPORT__
    KEY_SEND1,
    KEY_SEND2,
#endif  /* __SENDKEY2_SUPPORT__ */
};

/*
 *  We add this array for UCM and video call
 *  They will handle key 0~9 8#  in number key pad
 *  handle 0~9 *# PW in QWERTY project
 *  They using SetGroupKeyHandler(XXX, PresentAllDialerKeys, TOTAL_DIALER_KEYS, XXX)
 *  in qwert project, we will record P and W' handler in any key handler
 *  The application should skip other keys.
 *  Please see SetGroupKeyHandler for detail
 *  Don't change the sequence of the table
 *  g_key_tone will be mapped to this table
 *
 */
const U16 PresentAllDialerKeys[] =
{
    KEY_0,
    KEY_1,
    KEY_2,
    KEY_3,
    KEY_4,
    KEY_5,
    KEY_6,
    KEY_7,
    KEY_8,
    KEY_9,
    KEY_STAR,
    KEY_POUND
};

/* 
 * Driver key code to MMI key code mapping table
 * We will list all device key code here.
 * accurate device key code for specific project, please
 * look at the table keypad_custom_def in keypad_def.c and keypad_drv.h
 * Moreover, in this table one device key code is mapped to
 * one mmi key code but one device key code may correspond to 
 * two mmi key code in qwerty project.
 * eg. character E & number 1 may appear in one hard key.
 *     The device key code will be DEVICE_KEY_E (character first when mapping device key code in qwerty project)
 *     The mmi key code will be KEY_E or KEY_1 depends on the keypad mode
 *     (see GlobalConstants.h mmi_frm_keypad_mode_enum)
 */
 
const static key_code_map_struct g_key_code_map[] =
{
    {DEVICE_KEY_0             , KEY_0},
    {DEVICE_KEY_1             , KEY_1},
    {DEVICE_KEY_2             , KEY_2},
    {DEVICE_KEY_3             , KEY_3},
    {DEVICE_KEY_4             , KEY_4},
    {DEVICE_KEY_5             , KEY_5},
    {DEVICE_KEY_6             , KEY_6},
    {DEVICE_KEY_7             , KEY_7},
    {DEVICE_KEY_8             , KEY_8},
    {DEVICE_KEY_9             , KEY_9},
    {DEVICE_KEY_STAR          , KEY_STAR},
    {DEVICE_KEY_HASH          , KEY_POUND},
    {DEVICE_KEY_VOL_UP        , KEY_VOL_UP},
    {DEVICE_KEY_VOL_DOWN      , KEY_VOL_DOWN},
    {DEVICE_KEY_UP            , KEY_UP_ARROW},
    {DEVICE_KEY_DOWN          , KEY_DOWN_ARROW},
    {DEVICE_KEY_LEFT          , KEY_LEFT_ARROW},
    {DEVICE_KEY_RIGHT         , KEY_RIGHT_ARROW},
    {DEVICE_KEY_MENU          , KEY_ENTER},
    {DEVICE_KEY_FUNCTION      , KEY_CAMERA},
    {DEVICE_KEY_SK_LEFT       , KEY_LSK},
    {DEVICE_KEY_SK_RIGHT      , KEY_RSK},
    {DEVICE_KEY_SEND          , KEY_SEND},
    {DEVICE_KEY_END           , KEY_END},
    {DEVICE_KEY_POWER         , KEY_POWER},
    {DEVICE_KEY_CLEAR         , KEY_CLEAR},
#ifdef __COSMOS_MMI_PACKAGE__
    {DEVICE_KEY_BACK          , KEY_BACK},
    {DEVICE_KEY_HOME          , KEY_HOME},
#endif
#ifdef __MMI_ATV_SUPPORT__
    {DEVICE_KEY_EXT_FUNC1     , KEY_EXTRA_1},
    {DEVICE_KEY_EXT_FUNC2     , KEY_EXTRA_2},
#endif
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    {DEVICE_KEY_F1,             KEY_F1},
    {DEVICE_KEY_F2,             KEY_F2},
    {DEVICE_KEY_F3,             KEY_F3},
    {DEVICE_KEY_F4,             KEY_F4},
    {DEVICE_KEY_F5,             KEY_F5},
    {DEVICE_KEY_F6,             KEY_F6},
    {DEVICE_KEY_F7,             KEY_F7},
    {DEVICE_KEY_F8,             KEY_F8},
    {DEVICE_KEY_F9,             KEY_F9},
    {DEVICE_KEY_F10,            KEY_F10},
    {DEVICE_KEY_F11,            KEY_F11},
    {DEVICE_KEY_F12,            KEY_F12},
    {DEVICE_KEY_MESSAGE,        KEY_MESSAGE},
#endif
#ifdef __SUBLCD_DEDICATED_KEYS_SUPPORT__
    {DEVICE_KEY_MP3_PLAY_STOP , KEY_PLAY_STOP},
    {DEVICE_KEY_MP3_FWD       , KEY_FWD},
    {DEVICE_KEY_MP3_BACK      , KEY_BACK},
#endif
#ifdef __EXTRA_A_B_KEY_SUPPORT__
    {DEVICE_KEY_EXT_A         , KEY_EXTRA_A},
    {DEVICE_KEY_EXT_B         , KEY_EXTRA_B},
#endif    
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    {DEVICE_KEY_A             , KEY_A},
    {DEVICE_KEY_B             , KEY_B},
    {DEVICE_KEY_C             , KEY_C},
    {DEVICE_KEY_D             , KEY_D},
    {DEVICE_KEY_E             , KEY_E},
    {DEVICE_KEY_F             , KEY_F},
    {DEVICE_KEY_G             , KEY_G},
    {DEVICE_KEY_H             , KEY_H},
    {DEVICE_KEY_I             , KEY_I},
    {DEVICE_KEY_J             , KEY_J},
    {DEVICE_KEY_K             , KEY_K},
    {DEVICE_KEY_L             , KEY_L},
    {DEVICE_KEY_M             , KEY_M},
    {DEVICE_KEY_N             , KEY_N},
    {DEVICE_KEY_O             , KEY_O},
    {DEVICE_KEY_P             , KEY_P},
    {DEVICE_KEY_Q             , KEY_Q},
    {DEVICE_KEY_R             , KEY_R},
    {DEVICE_KEY_S             , KEY_S},
    {DEVICE_KEY_T             , KEY_T},
    {DEVICE_KEY_U             , KEY_U},
    {DEVICE_KEY_V             , KEY_V},
    {DEVICE_KEY_W             , KEY_W},
    {DEVICE_KEY_X             , KEY_X},
    {DEVICE_KEY_Y             , KEY_Y},
    {DEVICE_KEY_Z             , KEY_Z},
    {DEVICE_KEY_SPACE         , KEY_SPACE},
    {DEVICE_KEY_TAB           , KEY_TAB},
    {DEVICE_KEY_DEL           , KEY_DEL},
    {DEVICE_KEY_ALT           , KEY_ALT},
    {DEVICE_KEY_CTRL          , KEY_CTRL},
    {DEVICE_KEY_WIN           , KEY_WIN},
    {DEVICE_KEY_SHIFT         , KEY_SHIFT},
    {DEVICE_KEY_QUESTION      , KEY_QUESTION},
    {DEVICE_KEY_PERIOD        , KEY_PERIOD},
    {DEVICE_KEY_COMMA         , KEY_COMMA},
    {DEVICE_KEY_EXCLAMATION   , KEY_EXCLAMATION},
    {DEVICE_KEY_APOSTROPHE    , KEY_APOSTROPHE},
    {DEVICE_KEY_AT            , KEY_AT},
    {DEVICE_KEY_BACKSPACE     , KEY_BACKSPACE},
    {DEVICE_KEY_ENTER         , KEY_QWERTY_ENTER},
    {DEVICE_KEY_FN            , KEY_FN},
    {DEVICE_KEY_SYMBOL        , KEY_SYMBOL},
    {DEVICE_KEY_NUM_LOCK      , KEY_NUM_LOCK},
    {DEVICE_KEY_QWERTY_MENU   , KEY_QWERTY_MENU},
    {DEVICE_KEY_OK            , KEY_OK},
	{DEVICE_KEY_DOLLAR        , KEY_DOLLAR},
#endif /* __MMI_QWERTY_KEYPAD_SUPPORT__ */

#ifdef __SENDKEY2_SUPPORT__
    {DEVICE_KEY_SEND2         , KEY_SEND2},
#endif /* __SENDKEY2_SUPPORT__ */
};


/*****************************************************************************
* Extern Global Function
*****************************************************************************/
extern void kbd_find_2step(kal_uint32 *number, kal_uint8 *two_step);

#if defined(__GGT_TASK__)
#if defined(__OLED_BW_MMI__)
extern MMI_BOOL mmi_idle_is_active(void);
extern U8 sos_call_count;
extern U8 mmi_get_sos_status(void);
extern void mmi_idle_make_sos_call(void);
#endif /* __OLED_BW_MMI__ */
#if defined(__CITY_EASY_MODEL_W__)
extern void cityeasy_led_ctrl_set_status(U8 s);
extern U8 cityeasy_led_ctrl_get_status(void);
extern void cityeasy_alarm_status_set_and_send(U8 state);
extern void city_easy_send_by_sos(void);
extern void city_easy_send_by_key1(void);
extern void city_easy_send_by_key2(void);
extern void city_easy_send_by_key3(void);
#endif /* __CITY_EASY_MODEL_W__ */
#if defined(__CITY_EASY_WEB_DOG__)
extern void city_edog_set_vol_up(void);
extern void city_edog_set_vol_down(void);
extern void mmi_edog_back_to_first_screen(void);
extern void gps_turn_off(void);
extern void city_dog_infrared_up_set(void);
extern kal_bool left_status;// = KAL_FALSE;
extern kal_bool right_status;// = KAL_FALSE;
extern void city_edog_infrared_switch(void);

extern U8 g_is_shut_down;
#endif /* __CITY_EASY_WEB_DOG__ */
#endif

static MMI_BOOL get_driver_key_data(kbd_data *keydata)
{
	 DCL_STATUS STA;
	 DCL_CTRL_DATA_T data;
	 DCL_HANDLE handle1;
	  kbd_data *keydata1 = keydata;
	  handle1 = DclSKBD_Open(DCL_KBD, 0);
	  
	 STA = DclSKBD_Control(handle1,KBD_CMD_GET_KEY_DATA , (DCL_CTRL_DATA_T*)&data);
	
	 keydata1->Keydata[0] =data.rKBDCtrGetData.Keydata[0];
	 keydata1->Keyevent =  (kbd_event)data.rKBDCtrGetData.Keyevent;
	 
	if(STATUS_BUFFER_EMPTY == STA)
		return MMI_FALSE;
	else 
		return MMI_TRUE;


}


extern kal_bool w32_key_det_mode_switch( unsigned char keymode_num_to_switch);


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + Framework Internal Functions
 +
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void set_scrn_layer_id(MMI_ID group_id, MMI_ID scrn_id)
{
    g_key_cntx.group_id[LAYER_SET_SPACE] = group_id;
    g_key_cntx.scrn_id[LAYER_SET_SPACE]  = scrn_id;
}

void get_scrn_layer_id(MMI_ID *group_id, MMI_ID *scrn_id)
{
    *group_id = g_key_cntx.group_id[LAYER_INVOKE_SPACE];
    *scrn_id = g_key_cntx.scrn_id[LAYER_INVOKE_SPACE];
}

void clear_scrn_layer_key_proc(void)
{
    MMI_TRACE(PLUTO_FW_TRC_KEY, TRC_MMI_FRM_KEY_CLARE_APP_INVOKE_SPACE_PROC);
    g_key_cntx.routing_layer[LAYER_INVOKE_SPACE][MMI_KEY_ROUTING_SCR].key_proc = NULL;
    g_key_cntx.routing_layer[LAYER_INVOKE_SPACE][MMI_KEY_ROUTING_SCR].user_data = NULL;
}

void key_dummy_function(void)
{

}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_init_key_event
 * DESCRIPTION
 *  This function is used to init key event cntx, which is only used in
 *  MMITask.c task init function
 *  [UT_function] ut_mmi_frm_init_key_event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_init_key_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __KBD_2STEP_KEY_SUPPORT__
    kal_uint8 _2step_key = KEY_INVALID;
    kal_uint32 _2step_key_num = 0;
#endif /* __KBD_2STEP_KEY_SUPPORT__ */
    S32 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_key_cntx, 0, sizeof(g_key_cntx));
    g_key_cntx.keypad_status = KPD_STATE_PREDEFINE_VAL;
    for (j = 0; j < MAX_DECT_KEY_NUM; j++)
    {
        g_key_cntx.buffer[j].mmi_key_code = KEY_INVALID;
        g_key_cntx.buffer[j].cvt_code = KEY_INVALID;
        g_key_cntx.buffer[j].mmi_key_type = KEY_EVENT_UP;
    }
#ifdef __KBD_2STEP_KEY_SUPPORT__
    g_key_cntx._2step_key.state = FULL_UP;
    kbd_find_2step(&_2step_key_num, &_2step_key);
    g_key_cntx._2step_key.mmi_key_code = (U8)get_mmi_key_code(_2step_key);
    MMI_ASSERT(_2step_key_num < 2);
#endif /* __KBD_2STEP_KEY_SUPPORT__ */
    g_key_cntx.curr_key_code = KEY_INVALID;
    g_key_cntx.curr_key_type = KEY_EVENT_UP;
    g_key_cntx.is_key_event = MMI_TRUE;
    mmi_frm_set_keypad_mode(KEYPAD_1KEY_NUMBER);
    MMI_SYS_SET_KEY_PROC(mmi_sys_key_proc, NULL);
    mmi_frm_set_key_proc(MMI_KEY_ROUTING_KEY_HDLR, (mmi_proc_func)mmi_key_hdlr_proc,NULL);
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
	/* Init framework qwerty module */
    mmi_frm_qwerty_init();
#endif /* __MMI_QWERTY_KEYPAD_SUPPORT__ */
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_EQ_KEYPAD_DETECT_IND, (PsIntFuncPtr)mmi_frm_key_handle, KAL_FALSE);
}
   

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_key_event_screen_switch_action
 * DESCRIPTION
 *  The things need to be done by key event handle when screen switch
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_key_event_screen_switch_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_keypad_mode(KEYPAD_1KEY_NUMBER);
    mmi_frm_set_dial_key_tone_type(MMI_DIALER_KEY_TONE_NORMAL);
    g_key_cntx.is_screen_switch = MMI_TRUE;
    g_key_cntx.wgui_layer_num[LAYER_SET_SPACE] = 0;
    /* Clear the key proc for SCR/CAT/WGUI */
    for (layer = MMI_KEY_ROUTING_SCR; layer < MMI_KEY_ROUTING_TOTAL-1; layer++)
    {
        g_key_cntx.routing_layer[LAYER_SET_SPACE][layer].key_proc = NULL;
        g_key_cntx.routing_layer[LAYER_SET_SPACE][layer].user_data = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_key_evt_report_ind
 * DESCRIPTION
 *  protocol event handler of MSG_ID_MMI_AT_KEYPAD_EVENT_ACT_IND
 *
 * PARAMETERS
 *  para       : [IN] local parameter of MSG_ID_MMI_AT_KEYPAD_EVENT_ACT_IND
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_key_evt_report_ind(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_at_keypad_event_act_ind_struct *p = (mmi_at_keypad_event_act_ind_struct *)para;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p != NULL)
    {
        g_key_cntx.key_event_report_mode = p->mode;
    }
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + External API
 +
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_kbd_is_key_supported
 * DESCRIPTION
 *  query if specified mmi key code is supported
 * PARAMETERS
 *  mmi_key_code    :[IN]    mmi key code (mmi_keypads_enum) to query
 * RETURNS
 *  key is supported or not
 *****************************************************************************/
MMI_BOOL mmi_frm_kbd_is_key_supported(S16 mmi_key_code)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	MMI_BOOL ret;
	MMI_BOOL ret1;
	MMI_BOOL ret2;
	S16 op_code = mmi_key_code;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	MMI_ASSERT((mmi_key_code >= 0) && (mmi_key_code < MAX_KEY_NUM));
	
#ifndef __MTK_TARGET__
	/* No power key on Modis */
	if (mmi_key_code == KEY_POWER)
	{
		ret = MMI_FALSE;
		MMI_TRACE(PLUTO_FW_TRC_KEY, TRC_MMI_FRM_KEY_MMI_KEY_CODE_SUPPORTED, mmi_key_code, ret);    
		return ret; 	
	}
#endif
    /* 
    * 1 driver key code may mapped to 2 mmi key code in qwerty project.
    * eg. DEVICE_KEY_E  => KEY_E & KEY_1, or DEVICE_KEY_1 => KEY_E & KEY_1
    * in this case if mmi_key_code = KEY_E, the opposite_mmi_key_code = KEY_1
    * if mmi_key_code = KEY_1, the opposite_mmi_key_code = KEY_E
    *
    * However, in key mapping table, DEVICE_KEY_E => KEY_E, DEVICE_KEY_1 => KEY_1
    * Whether KEY_E is supported or not is determinded by either DEVICE_KEY_E or DEVICE_KEY_1
    * is supported. Pay attention: they cannot be both valid or both invalid, if this happen, Please check 
    * key layout in keypad_def.c
    */	
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__	
	op_code = mmi_frm_qwerty_get_opposite_key_code(mmi_key_code);
#endif /* __MMI_QWERTY_KEYPAD_SUPPORT__ */
	if (op_code == mmi_key_code)
	{
		ret = is_driver_key_button_support(get_device_key_code((U8)mmi_key_code));
	}
	else
	{
		ret1 = is_driver_key_button_support(get_device_key_code((U8)mmi_key_code));
		ret2 = is_driver_key_button_support(get_device_key_code((U8)op_code));
		MMI_ASSERT((!ret1 && ret2) || (ret1 && (!ret2)));
		ret = (MMI_BOOL)(ret1 || ret2); 	
	}
	MMI_TRACE(PLUTO_FW_TRC_KEY, TRC_MMI_FRM_KEY_MMI_KEY_CODE_SUPPORTED, mmi_key_code, ret);   
	return ret;
}


static MMI_BOOL is_driver_key_button_support(kal_uint8 key)
{

/*----------------------------------------------------------------*/
/* Local Variables												  */
/*----------------------------------------------------------------*/

/*----------------------------------------------------------------*/
/* Code Body													  */
/*----------------------------------------------------------------*/
	SKBD_CTRL_KEYSUPPORT_T sta; 
	DCL_HANDLE handle;
	sta.uKey = key;
	handle = DclSKBD_Open(DCL_KBD,0);
	DclSKBD_Control(handle,KBD_CMD_CTRL_KEY_SUPPORT , (DCL_CTRL_DATA_T*)&sta);

	return (MMI_BOOL)sta.fgIKBS;


}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_key_info
 * DESCRIPTION
 *  This function is used for querying key code & key type of last key event.
 *  This function is mainly used with group key handler.
 *  Because the application cannot get the key code and key type in his group
 *  key handler, so it needs this interface to get the key code and key type.
 *  
 *  Typically,
 *    mmi_frm_set_group_key_handler(xxx_hdr, xxx_array, xxx_num, xxx_type);
 *    in xxx_hdlr
 *    void xxx_hdlr()
 *    {
 *        mmi_frm_get_key_info(&key_code, &key_type);
 *        switch(key_code)
 *        {
 *           case KEY_0:
 *               // do the thing you want
 *               break;
 *               ...
 *        }
 *    }
 *  Notes: 
 *      1. The key info is update before invoke translate key handler and key handler.
 *      2. It's safe to use it in translate key handler and key handler
 *      3. Don't use this in pre and post key handler.
 *      4. Don't use this in some timer's callback
 *      5. It's safe to use it in translate key handler and key handler.
 *      6. Don't this API to judge if the key handle is finished or no key is pressed.
 *      
 * PARAMETERS
 *  mmi_key_code     :[OUT]  The pointer to the Key Code.
 *  mmi_key_type     :[OUT]  The pointer to the Key type.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_get_key_info(PU16 keyCode, PU16 keyType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((keyCode != NULL) && (keyType != NULL));
    *keyCode = g_key_cntx.curr_key_code;
    *keyType = g_key_cntx.curr_key_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_key_info
 * DESCRIPTION
 *  This function is used to set the key info.
 *  some applications may simulate the key process but don't use mmi_frm_exec_key_handler
 *  he may use the following case:
 *   FuncPtr key_handler = mmi_frm_get_key_handler(KEY_0, KEY_EVENT_DOWN);
 *   mmi_frm_set_key_info(KEY_0, KEY_EVENT_DOWN);
 *   if (key_handler)
 *   {
 *      key_handler();
 *   }
 *   here to set key info because the key_handler may be the group key handler it may use
 *   get key info to get corrent key code. Because it simulates key, framework doesn't know this
 *   it needs the application to set key info by himself.
 *  
 * PARAMETERS
 *  mmi_key_code     :[IN]  Key to which this event is associated
 *  mmi_key_type     :[IN]  KEY_EVENT_UP, KEY_EVENT_DOWN, event occurs when the key 
 *                    is pressed or released      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_set_key_info(U16 keyCode, U16 keyType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_key_cntx.curr_key_code = (U8)keyCode;
    g_key_cntx.curr_key_type = (U8)keyType;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_key_handler
 * DESCRIPTION
 *  This function is used for gets the key event handler for key handler table
 *  
 *  Note:
 *    1. App may use this interface to get the key handler and then invoke the key handler
 *    2. App may use this interface to save some key handler and then to restore them
 *    3. App may use this interface to get the key handler to judge something.
 *    4. In QWERTY project, key code >= MAX_KEYES do not have key handler
 *       eg, mmi_frm_get_key_handler(KEY_A, KEY_EVENT_DOWN) will always return NULL
 * PARAMETERS
 *  mmi_key_code     :[IN]  Key to which this event is associated.
 *  mmi_key_type     :[IN]  What key type is wanted to query.
 * RETURNS
 *  void
 *****************************************************************************/
FuncPtr mmi_frm_get_key_handler(U16 keyCode, U16 keyType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(keyType < MAX_KEY_TYPE);
    MMI_ASSERT(keyCode < MAX_KEY_NUM);
    if (keyCode >= MAX_KEYS)
    {
        /* There are no key handlers for qwerty keys, so NULL is returned */
        ptr = NULL;
    }
    else
    {
#ifdef __KBD_2STEP_KEY_SUPPORT__
        if ((is_2step_key(keyCode) == MMI_TRUE) && (keyType == KEY_HALF_PRESS_DOWN || keyType == KEY_HALF_PRESS_UP))
        {
            ptr = _2step_key_extra_hdlr[keyType - MAX_NON_2STEP_KEY_TYPE];
        }
        else
#endif /* __KBD_2STEP_KEY_SUPPORT__ */
        {
            if (keyType < MAX_NON_2STEP_KEY_TYPE)
            {
                ptr = (currKeyFuncPtrs[keyCode][keyType]);
            }
            else
            {
                ptr = NULL;
            }
        }
    }
    if (keyCode == KEY_END && keyType == KEY_EVENT_DOWN)
    {
        if (ptr == key_dummy_function)
        {
            ptr = NULL;
        }
    }
    return ptr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_key_proc
 * DESCRIPTION
 *  This function is used to set key proc function for all key event routing layer.
 *
 *  [UT function] ut_mmi_frm_set_key_proc
 * PARAMETERS
 *  layer      :[IN]   key event routing layer, see mmi_key_routing_layer_enum
 *  key_proc   :[IN]   proc function that will process key event
 *  user_data  :[IN]   user data that the user will use
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_set_key_proc(mmi_key_routing_layer_enum layer, mmi_proc_func key_proc, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_ASSERT(layer <= MMI_KEY_ROUTING_WGUI);
    if (layer == MMI_KEY_ROUTING_WGUI)
    {
        for (i = 0; i < g_key_cntx.wgui_layer_num[LAYER_SET_SPACE]; i++)
        {
            if ((key_proc == g_key_cntx.routing_layer[LAYER_SET_SPACE][layer + i].key_proc)
                && (user_data == g_key_cntx.routing_layer[LAYER_SET_SPACE][layer + i].user_data))
            {
                return;
            }
        }
        //wgui layer key proc execeed maximum value permited, value MMI_FRM_WGUI_ROUTING_LAYER_NUM should be increaced
        MMI_ASSERT(g_key_cntx.wgui_layer_num[LAYER_SET_SPACE] < MMI_FRM_WGUI_ROUTING_LAYER_NUM);
        layer += g_key_cntx.wgui_layer_num[LAYER_SET_SPACE]++;
    }
    g_key_cntx.routing_layer[LAYER_SET_SPACE][layer].key_proc = key_proc;
    g_key_cntx.routing_layer[LAYER_SET_SPACE][layer].user_data = user_data;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_key_handler
 * DESCRIPTION
 *  This is used to sets the key event handler that corresponse to one [key_code, key_type].
 *  
 *  Notes:
 *       1. The life cycle of the key handler is within a screen. When screen switch,
 *          END/VOL_UP/VOL_DOWN will be reset to their's default key handler
 *       2. There is only one entry for a [key_code, key_type] pair, overwriten may happen.
 *          
 * PARAMETERS
 *  funcPtr     :[IN] Function to be executed on occurrence of the event.
 *  keyCode     :[IN] Key to which this event is associated.
 *  keyType     :[IN] KEY_EVENT_UP, KEY_EVENT_DOWN, event occurs when the key
 *                   is pressed or released
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_set_key_handler(FuncPtr funcPtr,U16 keyCode,U16 keyType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(PLUTO_FW_TRC_KEY, TRC_MMI_FRM_KEY_SET_KEY_HDLR, keyCode, keyType, funcPtr);

    MMI_ASSERT((keyCode < MAX_KEYS) && (keyType < MAX_KEY_TYPE));

    if (keyCode == KEY_END && keyType == KEY_EVENT_DOWN && funcPtr == NULL)
    {
        funcPtr = key_dummy_function;
    }
    if (is_2step_key(keyCode) == MMI_TRUE)
    {
#ifdef __KBD_2STEP_KEY_SUPPORT__        
        if (keyType == KEY_HALF_PRESS_DOWN || keyType == KEY_HALF_PRESS_UP)
        {
            _2step_key_extra_hdlr[keyType - MAX_NON_2STEP_KEY_TYPE] = funcPtr;
            return;
        }
#endif
    }
    else
    {
        if (keyType == KEY_HALF_PRESS_DOWN || keyType == KEY_HALF_PRESS_UP)
        {
            return;
        }
    }

#ifndef __SENDKEY2_SUPPORT__
    currKeyFuncPtrs[keyCode][keyType] = funcPtr;
#else
    /*
     * KEY_SEND means KEY_SEND1 and KEY_SEND2
     * But the application could set the individual key handler in using KEY_SEND1 and KEY_SEND2
     */
    if (keyCode == KEY_SEND1)
    {
        currKeyFuncPtrs[KEY_SEND][keyType] = funcPtr;
        currKeyFuncPtrs[KEY_SEND1][keyType] = funcPtr;
    }
    else if (keyCode == KEY_SEND2)
    {
        currKeyFuncPtrs[KEY_SEND2][keyType] = funcPtr;
    }
    else if (keyCode == KEY_SEND)
    {
        currKeyFuncPtrs[KEY_SEND][keyType] = funcPtr;
        currKeyFuncPtrs[KEY_SEND1][keyType] = funcPtr;
        currKeyFuncPtrs[KEY_SEND2][keyType] = funcPtr;
    }
    else
    {
        currKeyFuncPtrs[keyCode][keyType] = funcPtr;
    }
#endif /* __SENDKEY2_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_group_key_handler
 * DESCRIPTION
 *  This is used to sets the same key handler for a group of keycodes.
 *  For example
 *      1. U16 keys[4] = {KEY_1, KEY_2, KEY_3, KEY_4};
 *         mmi_frm_set_group_key_handler(xxx_hdlr, keys, 4, KEY_EVENT_DOWN);
 *      2. using PresentAllKeys as the array
 *         If applications needs all keys have the same key handler, he may use
 *         mmi_frm_set_group_key_handler(xxx_hdlr, PresentAllKeys, KEY_EVENT_DOWN);
 *         It is needed to pay attention in QWERTY project, in order to make the 
 *         modification of application as little as possible when implement qwerty key pad
 *         framework cover the case if application wants to handle all keys in one key handler
 *         in qwerty project even though keys like KEY_A has not the key handler in fact.
 *         Application uses this mmi_frm_set_group_key_handler(xxx_hdlr, PresentAllKeys, KEY_EVENT_DOWN);
 *         he will receive KEY_A's down in xxx_hdlr.
 *    
 *      3. using PresentAllDialerKeys as array
 *         This is the special implementation for UCM/video call in QWERTY project.
 *         Because in QWERTY project, there is KEY_W. So the UCM/Video call needs to
 *         handle KEY_W, but the app owner don't want to use translate key handler
 *         So we implement this.
 *         app uses this interface as the following,
 *         mmi_frm_set_group_key_handler(xxx_hdlr, PresentAllDialerKeys, TOTAL_DIALER_KEYS, KEY_EVENT_DOWN);
 *         In xxx_hdlr, app should filter the key he doesn't interest Because we will give all the keys
 *         that doesn't has key handler.
 *     
 * PARAMETERS
 *  funcPtr         :[IN] Function to be executed on occurrence of the event.
 *  keyCodes        :[IN] Key array to which these events are associated.
 *  len             :[IN] The keyCodes array size.
 *  keyType         :[IN] KEY_EVENT_UP, KEY_EVENT_DOWN, event occurs when the 
 *                       key is pressed or released.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_set_group_key_handler(FuncPtr funcPtr, PU16 keyCodes, U8 len, U16 keyType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((len <= MAX_KEYS) && (keyType < MAX_KEY_TYPE));
    
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    if (keyCodes == PresentAllKeys || keyCodes == PresentAllDialerKeys)
    {
        if (funcPtr == NULL)
        {
            funcPtr = MMI_dummy_function;
        }    
        anyKeyFuncPtrs[keyType] = funcPtr;
    }
#endif
    for (count = 0; count < len; count++)
    {
        mmi_frm_set_key_handler(funcPtr, keyCodes[count], keyType);
    }
  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_key_handler
 * DESCRIPTION
 *  This function is used to set the key handler as NULL.
 * PARAMETERS
 *  keyCode     :[IN] Key to which this event is associated.
 *  keyType     :[IN] KEY_EVENT_UP, KEY_EVENT_DOWN, free the event associated
 *                   with press or released state.       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_clear_key_handler(U16 keyCode, U16 keyType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_key_handler(NULL, keyCode, keyType);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_all_key_hdlr_null
 * DESCRIPTION
 *  This function is used to set all key handler as NULL.
 *  This function is mainly used when entry a dummy screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_set_all_key_hdlr_null()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_clear_all_translate_key_handler();
    memset(currKeyFuncPtrs, 0, sizeof(currKeyFuncPtrs));
#ifdef __KBD_2STEP_KEY_SUPPORT__
    memset(_2step_key_extra_hdlr, 0, sizeof(_2step_key_extra_hdlr));
#endif
}


void mmi_frm_send_incomplete_key_event_to_new_screen(MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_key_cntx.is_send_to_new_scrn = enable;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_all_slave_master_key_hdlr_null
 * DESCRIPTION
 *  This function is used to set all key handler as NULL.
 *  This function is mainly used when entry a dummy screen
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD_MASTER_MODE__
void mmi_frm_set_all_slave_master_key_hdlr_null()
{
    memset(currKeyFuncPtrs_master, 0, sizeof(currKeyFuncPtrs_slave));
    memset(currKeyFuncPtrs_slave, 0, sizeof(currKeyFuncPtrs_slave));
#ifdef __KBD_2STEP_KEY_SUPPORT__
    memset(_2step_key_extra_hdlr_master, 0, sizeof(_2step_key_extra_hdlr_master));
    memset(_2step_key_extra_hdlr_slave, 0, sizeof(_2step_key_extra_hdlr_slave));
#endif
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_all_key_handler
 * DESCRIPTION
 *  This function is used for clears all the key handlers associated with
 *  current screen.
 *  
 * Note: 1.This API will set END/VOL_UP/VOL_DOWN to their's default key handler
 *       set all other key handler as NULL, clear any key handler and translate key handler.
 *       2.This API is always be invoked when screen switch.
 *       3.This API is different with mmi_frm_clear_key_events. invoke this events can also
 *         be received but do nothing.
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_clear_all_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(PLUTO_FW_TRC_KEY, TRC_MMI_FRM_KEY_CLRALLKEY_HDLR);

    mmi_frm_set_all_key_hdlr_null();

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__

    /* clear any key handler */
    memset(anyKeyFuncPtrs, 0, sizeof(anyKeyFuncPtrs));
#endif

    /* clear translate key handler */
    mmi_frm_clear_all_translate_key_handler();
    mmi_frm_set_power_end_key_handler();

#ifdef __MMI_SUBLCD_MASTER_MODE__
    SetSubLCDMasterKeyHandler();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_query_mmi_key_state
 * DESCRIPTION
 *  This API is used to query mmi key state in MMI level
 *  only for dial to query mmi key state now.
 * PARAMETERS
 *  mmi_key_code :[IN] mmi key code
 * RETURNS
 *  mmi key type
 *****************************************************************************/
U8 mmi_frm_query_mmi_key_state(S16 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U8)get_key_state(mmi_key_code);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_is_key_event
 * DESCRIPTION
 *  This function is used to judge if key handler is triggered by key or touch
 *  
 *  Notes:
 *    1. provide this API because dialer need to judge if the key handler is triggered
 *       by pen or by key. If trigger by pen, the PW+ is input by multi-tap of *
 *       If triggered by key, the PW+ is input by KEY_W/shift + W/KEY_p.
 *    2. If the key handler is not invoked by mmi_frm_exec_key_handler, please don't use 
 *       this interface.
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_frm_is_key_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return   g_key_cntx.is_key_event;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_exec_key_handler
 * DESCRIPTION
 *  Because of history reason, applications may call this function directly to
 *  invoke current key handler.
 *  There are mainly 2 kinds of using cases.
 *    1. Call this function in Pen down and pen up handler
 *    2. press key, then in key handler entry new screen, show category and record the key code
 *       then use this key code to call this function.
 * 
 *  If you use it, pay attention that 
 *      This interface will update key info 
 *      will call translate key handler and key handler
 *  If the translate key handler and key handler are changed by someone else,
 *  applications should cover this case.
 *
 *  This interface will happen to filter some key event, for example
 *  mmi_frm_exec_key_handler(XXX_CODE, KEY_EVENT_UP);
 *  mmi_frm_exec_key_handler(XXX_CODE, KEY_REPEAT);
 *  KEY_REPEAT will be filtered. It is for MAUI_01882849
 *
 *  However: mmi_frm_exec_key_handler(XXX_CODE, KEY_EVENT_DOWN);
 *           mmi_frm_exec_key_handler(XXX_CODE, KEY_EVENT_DOWN);
 *           The second down should not be filtered for the using case 2 above.
 *
 *
 *  If we design multiple key handler in the future, this function should be considered
 *  because in one of the multiple key handler, application may call this function,
 *  it will make the code hard to maintain.
 *
 *  It is hard to remove this interface.
 * 
 * PARAMETERS
 *  mmi_key_code    :[IN]  mmi key code such as KEY_0, KEY_1...
 *  mmi_key_type    :[IN]  mmi key type such as KEY_EVENT_UP, KEY_EVENT_DOWN... 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_exec_key_handler(S16 mmi_key_code, S16 mmi_key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_key_evt_struct evt;
    static MMI_BOOL is_key_down = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* 
     * For MAUI_01882849 
     * This interface is invoked directly by other module.
     * For example, some soft button is triggered by pen down, but it has the same action
     * as key down, so the soft button may call this interface directly.
     * The issue is in dialer screen, touch 0, then move out 0 than move back to 0
     * the 0 soft button has no pressed effect but can in put 0;
     * So framework help to filter some key events.
     * But these method is temp.
     */
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_SIMULATE_KEY_EVENT, mmi_key_code, mmi_key_type, 0);
    switch (mmi_key_type)
    {
        case KEY_EVENT_DOWN:
            is_key_down = MMI_TRUE;
            break;
        
        case KEY_LONG_PRESS:
        case KEY_REPEAT:
        {
            if (is_key_down == MMI_FALSE)
            {
                return;
            }
            break;
        }

        case KEY_EVENT_UP:
        {
            if (is_key_down == MMI_TRUE)
            {
                is_key_down = MMI_FALSE;
            }
            else
            {
                return;
            }
            break;
        }

        default:
            break;
    }
    evt.cvt_code = mmi_key_code;
    evt.mmi_key_type = mmi_key_type;
    g_key_cntx.is_key_event = MMI_FALSE; 
    exec_key_handler(&evt);
    g_key_cntx.is_key_event = MMI_TRUE;     
}


#ifdef __MMI_SUBLCD_MASTER_MODE__
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_switch_key_func_ptr
 * DESCRIPTION
 *  This function is used for switch KeyFuncPtrs for sublcd master mode.
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_switch_key_func_ptr(void) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_sublcd_master_cntx.state == SUBLCD_MODE_S2M)
    {
        for (i = 0; i < MAX_KEYS; i++)
        {
            for (j = 0; j < MAX_NON_2STEP_KEY_TYPE; j++)
            {
                currKeyFuncPtrs_slave[i][j] = currKeyFuncPtrs[i][j];
                currKeyFuncPtrs[i][j] = currKeyFuncPtrs_master[i][j];
            }			
        }
		_2step_key_extra_hdlr_slave[0] = _2step_key_extra_hdlr[0];
		_2step_key_extra_hdlr_slave[1] = _2step_key_extra_hdlr[1];
		_2step_key_extra_hdlr[0] = _2step_key_extra_hdlr_master[0];
		_2step_key_extra_hdlr[1] = _2step_key_extra_hdlr_master[1];
    }
    else if (g_sublcd_master_cntx.state == SUBLCD_MODE_M2S)
    {
        for (i = 0; i < MAX_KEYS; i++)
        {
            for (j = 0; j < MAX_NON_2STEP_KEY_TYPE; j++)
            {
                currKeyFuncPtrs_master[i][j] = currKeyFuncPtrs[i][j];
                currKeyFuncPtrs[i][j] = currKeyFuncPtrs_slave[i][j];
            }
        }
		_2step_key_extra_hdlr_master[0] = _2step_key_extra_hdlr[0];
		_2step_key_extra_hdlr_master[1] = _2step_key_extra_hdlr[1];
		_2step_key_extra_hdlr[0] = _2step_key_extra_hdlr_slave[0];
		_2step_key_extra_hdlr[1] = _2step_key_extra_hdlr_slave[1];		
    }
    else
    {
        ASSERT(0);
    }
}
#endif /* __MMI_SUBLCD_MASTER_MODE__ */







#ifdef __MMI_HANDWRITING_PAD__
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_convert_pen_event_to_key_event
 * DESCRIPTION
 *  This function is only used in mmi_general_pen_handler in touchscreen.c.
 * PARAMETERS
 *  is_enable       :[IN]   Is enable high frequency mode or not.      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_convert_pen_event_to_key_event(S16 mmi_key_type, U8 device_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_key_evt_struct evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt.mmi_key_code= get_mmi_key_code(device_key_code);
    evt.mmi_key_type = mmi_key_type;
    evt.is_clear = MMI_FALSE;
    if (exec_dynamic_pre_key_handler(&evt) == MMI_TRUE)
    {
        update_clear_state(&evt);
        if (evt.is_clear == MMI_FALSE)
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_KEY_EVENT_INFO, evt.cvt_code, evt.mmi_key_type);
            mmi_frm_exec_key_handler(evt.mmi_key_code, evt.mmi_key_type);
        }else
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_DISABLE_KEY_ACTION_BY_PRE_KEY_HDLR, evt.cvt_code, evt.mmi_key_type);
        }
    }
    else
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_DISABLE_KEY_ACTION_BY_PRE_KEY_HDLR, evt.cvt_code, evt.mmi_key_type);
    }

}
#endif /* __MMI_HANDWRITING_PAD__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_process_key_in_nvarm
 * DESCRIPTION
 *  This function is used to process key message in NVRAM procedure
 * PARAMETERS
 *  paraBuff        :[IN]  The pointer to the parameter buffer.        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_process_key_in_nvarm(void * para_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*if (func == NULL)
    {
        mmi_eq_keypad_detect_ind_struct *p = (mmi_eq_keypad_detect_ind_struct*) para_buff;
        drv_get_key_func new_key_ptr = (drv_get_key_func) (p->func);
        while(((drv_get_key_func)new_key_ptr)(&k) == MMI_TRUE);
        return;

    }*/
    process_key_ptr_change(para_buff);
    g_keypad_flag = MMI_TRUE;
    SetBit(g_input_msg_in_queue, MMI_DEVICE_KEY); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_key_handle
 * DESCRIPTION
 *  This function is used for process the keypad handler.
 * PARAMETERS
 *  paraBuff        :[IN]  The pointer to the parameter buffer.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_key_handle(void *paraBuff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_count;
    dev_key_evt_struct dev_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_HANDLE_BEGIN);
    process_key_ptr_change(paraBuff);
    while (1)
    {
        if ((IsBitReset(g_key_cntx.keypad_status, KPD_SUSPEND_FLAG)) &&
            (get_dev_key_evt(&dev_evt) == MMI_TRUE))
        {
            dev_key_handle(&dev_evt);

			/* Stop sound or vibrator of notified event when key pressed. */
            msg_get_ext_queue_info(mmi_ext_qid, &msg_count);
            if (msg_count > 0 || OslNumOfCircularQMsgs() > 0)
            {
                g_keypad_flag = MMI_TRUE;
                SetBit(g_input_msg_in_queue, MMI_DEVICE_KEY);
                break;
            }
        }
        else
        {
            if (IsBitSet(g_key_cntx.keypad_status, KPD_SUSPEND_FLAG))
            {
                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_HANDLE_SUSPEND);
            }
            g_keypad_flag = MMI_FALSE;
            ResetBit(g_input_msg_in_queue, MMI_DEVICE_KEY);
            break;
        }
    }   /* while(1) */
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_HANDLE_END);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_suspend_handle_key_process
 * DESCRIPTION
 *  This function is used to suspend key process.
 * PARAMETERS
 *  enable     :[IN] MMI_TRUE enable, MMI_FALSE disable
 *
 * RETURNS
 *  Always return MMI_TRUE now 
 *****************************************************************************/
MMI_BOOL mmi_frm_suspend_handle_key_process(MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (enable == MMI_TRUE)
    {
        SetBit(g_key_cntx.keypad_status, KPD_SUSPEND_FLAG);
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_SUSPEND_KEY_FLOW);
    }
    else
    {
        ResetBit(g_key_cntx.keypad_status, KPD_SUSPEND_FLAG);
        mmi_frm_send_ilm(MOD_MMI, MSG_ID_MMI_EQ_KEYPAD_DETECT_IND, NULL, NULL);
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_RESUME_KEY_FLOW);
    }
    return MMI_TRUE;
}


static U32 get_driver_event_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	DCL_CTRL_DATA_T sta;
	DCL_HANDLE handle1;
	handle1 = DclSKBD_Open(DCL_KBD, MOD_MMI);
	DclSKBD_Control(handle1,KBD_CMD_GET_KEY_EVENT_CNT , (DCL_CTRL_DATA_T*)&sta);
	
	return sta.rKBDCtrkeyCnt.keycnt;



}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_key_event_count
 * DESCRIPTION
 *  This function is used to get the pending key events' number
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  pending key events number
 *****************************************************************************/
U32 mmi_frm_get_key_event_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return get_driver_event_count();    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_key_events
 * DESCRIPTION
 *  This function is used to clear key events buffer including look ahead buffer and
 *  driver's buffer
 *   
 *  1. If END Key's DOWN/LONGPRESS/UP is received in this API, we will make sure 1
 *     END key's DOWN/LONGPRESS/UP is written back to look ahead buffer make sure the handset 
 *     can be shut down properly.
 *  2. When mmi_frm_clear_key_events is invoked, all keys that is in pressing is changed to 
 *     clear state.
 *     That means
 *         Example, Invoking this API in KEY1's DOWN handler we will not send KEY1's long press repeat and KEY1' UP.
 *         Even though KEY1's UP is not in the keyboard buffer now. We will drop it when it is received in
 *         future.
 *  3. If application use this interface in KEY down' handler, it will not receive this key's up. 
 *  4. Framework will not invoke this interface when screen switch because the delay action effect of key needed by
 *     BD team.
 *
 *   [UT_function]: ut_mmi_frm_clear_key_events
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_clear_key_events(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dev_key_evt_struct dev_evt;
    dev_key_evt_struct temp[LOOK_AHEAD_BUF_LEN];
    U8 len = 0;
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_CLEAR_KEY_EVENTS_BEGIN);
    set_all_key_data_clear();
    while (get_dev_key_evt(&dev_evt) == MMI_TRUE)
    {
        if (is_need_write_back(&dev_evt, temp, len) == MMI_TRUE)
        {
            if (len > 0 && is_need_merge_detection_evt(&temp[len - 1], &dev_evt))
            {
                temp[len - 1] = dev_evt;
            }
            else
            {
                MMI_ASSERT(len < LOOK_AHEAD_BUF_LEN);
                temp[len] = dev_evt;
                len++;
            }
        }  
    };
    for (i = 0; i < len; i++)
    {
        write_look_ahead_buffer(&temp[i]);
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_WRITE_TO_LOOK_AHEAD, temp[i].device_key_code, temp[i].device_key_type);
    }
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_CLEAR_KEY_EVENTS_END);
}





/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_dev_key_code
 * DESCRIPTION
 *  This function is used for reversly get the driver key code.
 * PARAMETERS
 *  mmi_key_code        :[IN]        Key code of MMI
 * RETURNS
 *  driver key code
 *****************************************************************************/
S16 mmi_frm_get_dev_key_code(S16 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_QWERTY_KEYPAD_SUPPORT__

    /* check mmi key code */
    MMI_ASSERT((mmi_key_code >= 0) && (mmi_key_code < MAX_KEYS));
    
    if (mmi_key_code == KEY_CSK)
    {
        /* no device key is mapped to CSK */
        ret = DEVICE_KEY_NONE;
    }
    else
    {
        U8 device_key_code;

        /* get device key code from mapping table */
        device_key_code = get_device_key_code((U8)mmi_key_code);
        
        ret = (is_driver_key_button_support(device_key_code)) ? device_key_code : DEVICE_KEY_NONE;
    }
    MMI_TRACE(PLUTO_FW_TRC_KEY, TRC_MMI_FRM_KEY_REVERSE_CODE, mmi_key_code, ret);
    return ret;
#else /* __MMI_QWERTY_KEYPAD_SUPPORT__ */
    /* check mmi key code */
    MMI_ASSERT((mmi_key_code >= 0) && (mmi_key_code < MAX_QWERTY_KEYS));
    if (mmi_key_code == KEY_CSK)
    {
        /* no device key is mapped to CSK */
        return DEVICE_KEY_NONE;
    }
    else
    {
        S16 opposite_mmi_key_code;
        U8 device_key_code1;
        U8 device_key_code2;
        kal_bool ret1;
        kal_bool ret2;
        /* 
         * 1 driver key code may mapped to 2 mmi key code in qwerty project.
         * eg. DEVICE_KEY_E  => KEY_E & KEY_1, or DEVICE_KEY_1 => KEY_E & KEY_1
         * in this case if mmi_key_code = KEY_E, the opposite_mmi_key_code = KEY_1
         * if mmi_key_code = KEY_1, the opposite_mmi_key_code = KEY_E
         *
         * However, in key mapping table, DEVICE_KEY_E => KEY_E, DEVICE_KEY_1 => KEY_1
         * Whether KEY_E is supported or not is determinded by either DEVICE_KEY_E or DEVICE_KEY_1
         * is supported. Pay attention: they cannot be both valid, if this happen, Please check 
         * key layout in keypad_def.c
         */
        opposite_mmi_key_code = mmi_frm_qwerty_get_opposite_key_code(mmi_key_code);

        if (opposite_mmi_key_code == mmi_key_code) /* not 0~ 9 *# key */
        {
            device_key_code1 = get_device_key_code((U8)mmi_key_code);
            ret = (is_driver_key_button_support(device_key_code1)) ? device_key_code1 : DEVICE_KEY_NONE;
        }
        else /* may 0~ 9 * # key */
        {
            device_key_code1 = get_device_key_code((U8)mmi_key_code);
            device_key_code2 = get_device_key_code((U8)opposite_mmi_key_code);
            ret1 = is_driver_key_button_support(device_key_code1);
            ret2 = is_driver_key_button_support(device_key_code2);
            MMI_ASSERT((ret1 && !ret2) || (!ret1 && ret2));
            ret = ret1 ? device_key_code1 : device_key_code2; 
        }
    }
    MMI_TRACE(PLUTO_FW_TRC_KEY, TRC_MMI_FRM_KEY_REVERSE_CODE, mmi_key_code, ret);
    return ret;
#endif /* __MMI_QWERTY_KEYPAD_SUPPORT__ */  
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + pre and post key handler related API
 +      1. mmi_frm_kbd_get_pre_key_hdlr
 +      2. mmi_frm_kbd_reg_pre_key_hdlr
 +      3. mmi_frm_kbd_reg_post_key_hdlr
 +      4. mmi_frm_kbd_reg_post_key_hdlr
 +  
 +   TODO: know application how to use pre key handler and post key handler
 +         the limitation to use pre and post key handler
 +
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_kbd_get_pre_key_hdlr
 * DESCRIPTION
 *  This function is used for get framework pre-key handler
 *  keypad handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  PsKeyProcessCBPtr
 *****************************************************************************/
PsKeyProcessCBPtr mmi_frm_kbd_get_pre_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_key_cntx.kbd_pre_func;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_kbd_reg_pre_key_hdlr
 * DESCRIPTION
 *  This function is used for regiester function to execute before general 
 *  keypad handler.
 * PARAMETERS
 *  func        :[IN]  Pre-Key handler      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_kbd_reg_pre_key_hdlr(PsKeyProcessCBPtr func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_key_cntx.kbd_pre_func = func;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_kbd_reg_post_key_hdlr
 * DESCRIPTION
 *  This function is used for register function to execute after general 
 *  keypad handler.
 * PARAMETERS
 *  func        :[IN]  Post-Key handler     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_kbd_reg_post_key_hdlr(PsKeyProcessCBPtr func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_key_cntx.kbd_post_func = func;
}



static MMI_BOOL set_driver_detection_mode (DCL_kbd_key_det_mode mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	SKBD_CTRL_MODE_T mode_new;
	DCL_HANDLE handler;
	mode_new.Det_Mode = mode;
	handler  = DclSKBD_Open(DCL_KBD, MOD_MMI);
	DclSKBD_Control(handler,KBD_CMD_SET_DETECTION_MODE , (DCL_CTRL_DATA_T*)&mode_new);
	return (MMI_BOOL)mode_new.bFlag;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + Keypad mode related API
 +      1. mmi_frm_set_keypad_mode
 +      2. mmi_frm_get_keypad_mode
 +
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_keypad_mode
 * DESCRIPTION
 *  This function is used to set keypad mode
 * PARAMETERS
 *  mode        :[IN]   see mmi_frm_keypad_mode_enum
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_set_keypad_mode(U8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DCL_kbd_key_det_mode det_mode = DCL_kbd_1_key_det_mode;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch(mode)
    {
        case KEYPAD_1KEY_NUMBER:
            {
            #ifndef __MMI_QWERTY_KEYPAD_SUPPORT__
                det_mode = DCL_kbd_1_key_det_mode;
            #else
                det_mode = DCL_kbd_2_keys_det_mode;
                mmi_frm_qwerty_set_keypad_mode(MMI_FRM_QWERTY_MODE_NUMBER);
            #endif
            }
            break;
            
		#if defined(__THREE_KEY_DETECTION_SWITCHABLE__)	|| defined(__TWO_KEY_DETECTION_SWITCHABLE__)
        case KEYPAD_2KEY_NUMBER:
            {
                det_mode = DCL_kbd_2_keys_det_mode;
            #ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
                mmi_frm_qwerty_set_keypad_mode(MMI_FRM_QWERTY_MODE_NUMBER);
            #endif
            }
            break;
		#endif
            
		#if defined(__THREE_KEY_DETECTION_SWITCHABLE__)
        case KEYPAD_3KEY_NUMBER:
            {
                det_mode = DCL_kbd_3_keys_det_mode;
            #ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
                mmi_frm_qwerty_set_keypad_mode(MMI_FRM_QWERTY_MODE_NUMBER);
            #endif
            }
            break;
		#endif
            
        case KEYPAD_1KEY_QWERTY:
            {
                det_mode = DCL_kbd_2_keys_det_mode;
            #ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
                mmi_frm_qwerty_set_keypad_mode(MMI_FRM_QWERTY_MODE_STANDARD);
            #endif
            }
            break;
            
		#if defined(__THREE_KEY_DETECTION_SWITCHABLE__) || defined(__TWO_KEY_DETECTION_SWITCHABLE__)	
        case KEYPAD_2KEY_QWERTY:
            {
                det_mode = DCL_kbd_2_keys_det_mode;
            #ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
                mmi_frm_qwerty_set_keypad_mode(MMI_FRM_QWERTY_MODE_STANDARD);
            #endif
            }
            break;
		#endif
            
		#if defined(__THREE_KEY_DETECTION_SWITCHABLE__)
        case KEYPAD_3KEY_QWERTY:
            {
                det_mode = DCL_kbd_3_keys_det_mode;
            #ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
                mmi_frm_qwerty_set_keypad_mode(MMI_FRM_QWERTY_MODE_STANDARD);
            #endif
            }
            break;
		#endif 
            
        default:
			return;
    }
    
    /* updated keypad mode */
    SET_KPD_MODE(g_key_cntx.keypad_status, mode);
    MMI_TRACE(PLUTO_FW_TRC_KEY, TRC_MMI_FRM_KEY_KEYPAD_MODE, mode);
    /* updated key detection mode of driver */

#ifdef __MTK_TARGET__
    set_driver_detection_mode(det_mode);
#else
    SET_KEY_DET_MODE(g_key_cntx.keypad_status, det_mode);
    w32_key_det_mode_switch((U8)(det_mode + 1));
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_keypad_mode
 * DESCRIPTION
 *  This function is used to get keypad mode
 * PARAMETERS
 *  mode        :[IN]   see mmi_frm_keypad_mode_enum
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_frm_get_keypad_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GET_KPD_MODE(g_key_cntx.keypad_status);
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + Set Power Key and End key Handler
 +      1. mmi_frm_set_default_power_onoff_key
 +      2. mmi_frm_set_power_end_key_handler
 +
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_default_power_onoff_key
 * DESCRIPTION
 *  This function is used for set power on/off key to default handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_set_default_power_onoff_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__KJX_FUN__)	//xb add 2017-04-10 在按键消息处理那里直接处理
#if defined(CUSTOMER_NAME_TOUR)
	#include "NwInfoSrvGprot.h"
	if((mmi_bootup_is_sim_valid())&&(srv_nw_info_get_service_availability(MMI_SIM1) == SRV_NW_INFO_SA_FULL_SERVICE))
	{
		if (mmi_frm_kbd_is_key_supported(KEY_POWER) == MMI_TRUE)
		{
		    mmi_frm_set_key_handler(NULL, KEY_END, KEY_LONG_PRESS);
		    mmi_frm_set_key_handler(key_dummy_function, KEY_POWER, KEY_LONG_PRESS);
		}
		else
		{
		    mmi_frm_set_key_handler(key_dummy_function, KEY_END, KEY_LONG_PRESS);
		}
		return;
	}
#endif

    if (mmi_frm_kbd_is_key_supported(KEY_POWER) == MMI_TRUE)
    {
        mmi_frm_set_key_handler(NULL, KEY_END, KEY_LONG_PRESS);
        mmi_frm_set_key_handler(power_off, KEY_POWER, KEY_LONG_PRESS);
    }
    else
    {
        mmi_frm_set_key_handler(power_off, KEY_END, KEY_LONG_PRESS);
    }
#endif	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_power_end_key_handler
 * DESCRIPTION
 *  This function is used for sets power key & end key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_set_power_end_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_default_power_onoff_key();
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 +   Misc.
 +      1.mmi_frm_get_present_all_key_num
 +      2.mmi_frm_get_all_dial_key_num
 +     
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_present_all_key_num
 * DESCRIPTION
 *  This function is used to get the elment number of PresentAllKeys
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_frm_get_present_all_key_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return sizeof(PresentAllKeys)/sizeof(PresentAllKeys[0]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_present_all_key_num
 * DESCRIPTION
 *  This function is used to get the element number of PresentAllDialerKeys
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_frm_get_all_dial_key_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return sizeof(PresentAllDialerKeys)/sizeof(PresentAllDialerKeys[0]);
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + Internal function of key event handler
 +
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void power_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
               
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef KJX_KEYBRD_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

	if (is_in_end_call_procedure() == MMI_FALSE)
	{
	#if defined(__CITY_EASY_WEB_DOG__)
		g_is_shut_down = 1;
	#endif /* __CITY_EASY_WEB_DOG__ */
		srv_shutdown_normal_start(0);
	}
}

static mmi_ret mmi_sys_key_proc(mmi_frm_key_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;
    mmi_frm_key_evt_struct key_event;
               
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CLAMSHELL__
    if (evt->evt_id == EVT_ID_POST_KEY)
    {
        if (evt->key_code == KEY_END && evt->key_type == KEY_EVENT_DOWN)
        {
            if (IS_IN_CALL() && !mmi_frm_is_key_event())
            {
                mmi_idle_display();
            }
        }
    }
#endif /* __MMI_CLAMSHELL__ */

    if (evt->evt_id == EVT_ID_ON_KEY)
    {
        if (evt->key_code == KEY_END && evt->key_type == KEY_EVENT_DOWN)
        {
            if (IS_IN_CALL())
            {
                mmi_ucm_end_key();
                ret = MMI_RET_KEY_HANDLED;       
            }
        #if !defined (__COSMOS_MMI_PACKAGE__)
            else if(srv_bootup_is_completed() == MMI_TRUE)
            {
            #ifdef __MMI_EMAIL__
                if (mmi_email_util_get_stop_cause() == EMAIL_MODULE_ACTIVE_NOW)
                {
                    mmi_email_main_goto_idle();
                    ret = MMI_RET_KEY_HANDLED;
                }
                else
            #endif /* __MMI_EMAIL__ */
                {
                    mmi_idle_display();
                    ret = MMI_RET_KEY_HANDLED;
                }
            }
            else
            {
                mmi_frm_display_desktop();
                ret = MMI_RET_KEY_HANDLED;
            }    
        #endif
        }
    #if defined (__COSMOS_MMI_PACKAGE__)
        if( evt->key_code == KEY_HOME && evt->key_type == KEY_EVENT_DOWN)
        {
            if(srv_bootup_is_completed() == MMI_TRUE)
            {

                mmi_idle_display();
                ret = MMI_RET_KEY_HANDLED;
        }
            else
            {
                mmi_frm_display_desktop();
                ret = MMI_RET_KEY_HANDLED;
        }
        }
    #endif
        
	#if !defined(__32_32_SEG__) || defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_FTE_SUPPORT_SLIM__)
        if (mmi_frm_is_in_tab_screen() == MMI_TRUE)
        {
            if ((evt->key_code == KEY_LEFT_ARROW) && 
                ((evt->key_type == KEY_EVENT_DOWN) || (evt->key_type == KEY_REPEAT)))
            {
                mmi_frm_general_tab_l_arrow_key_hdlr();
                ret = MMI_RET_KEY_HANDLED;
            }
            else if ((evt->key_code == KEY_RIGHT_ARROW) && 
                ((evt->key_type == KEY_EVENT_DOWN) || (evt->key_type == KEY_REPEAT)))
            {
                mmi_frm_general_tab_r_arrow_key_hdlr();
                ret = MMI_RET_KEY_HANDLED;
            }            
        }
	#endif
	#if defined(MARS53_DEMO_BB) || defined(MARS53_6432_BB)     
		if (evt->key_code == KEY_EXTRA_2)
		{
			if (evt->key_type == KEY_EVENT_DOWN)
			{  
				turn_on_torch();
		     
				return MMI_RET_KEY_HANDLED;
			}
			else if (evt->key_type== KEY_EVENT_UP)
			{
				turn_off_torch();
				return MMI_RET_KEY_HANDLED;
			}            
		}
	#endif

        MMI_FRM_INIT_EVENT(&key_event, EVT_ID_KEY_DEFAULT_HANDLER);
        MMI_CONSTRUCT_KEY_EVENT(
            &key_event,
            evt->key_code,
            evt->key_type,
            evt->ucs2_value,
            evt->special_key_flag);
        ret = MMI_FRM_CB_EMIT_EVENT(&key_event);  

    }
    return ret;
}
extern void MakeCall(CHAR* ucs2_strNumber);
void mmi_makecall_112(void)
{
	U8 ucs_str[32];

	memset(ucs_str,0,sizeof(ucs_str));
	mmi_asc_to_ucs2((S8*)ucs_str,"112");
	MakeCall((S8*)ucs_str);
}

U8 dj_key_flag = 0;

void kjx_dj_key_check_timerout(void)
{
	dj_key_flag = 0;
}

#ifdef __KJX_FAST_KEY_HANDLER__
#include "TimerEvents.h"
#include "gpiosrvgprot.h"

#define FAST_KEY_HANDLER_TOTAL	5

U8 key_down_reg = 0;
U8 key_index = 0;
int g_key_press = 0;

extern nvram_ef_kjx_nvram_struct g_kjx_nvram_struct;

typedef void (*kjxPsVoidFunc) (void);

void kjx_fast_key_start_vibrator(void);
void kjx_fast_key_stop_vibrator(void);
#ifdef __BLE_MODULE_SUPPORT__
void kjx_fast_key_ble_on_off(void);
#endif
#ifdef __KJX_RFID__
void kjx_fast_key_rfid_on_off(void);
#endif

extern void kjx_factory_test_start(void);
extern void kjx_factory_auto_test_start(void);

typedef struct
{
	U8 checkflag;
	U8 key_code;
	U8 key_type_begin;
	U8 key_type_end;
}fast_key_struct;

typedef struct
{
	fast_key_struct fast_key[4];
	kjxPsVoidFunc func;
}fast_key_handler_struct;

fast_key_struct tmp_key[20] = {0};

fast_key_struct fast_key_to_test[] = 
{
	{0, KEY_UP_ARROW, KEY_EVENT_DOWN, KEY_EVENT_UP},
	{0, KEY_CAMERA, KEY_EVENT_DOWN, KEY_EVENT_UP},
	{0, KEY_RSK, KEY_EVENT_DOWN, KEY_EVENT_UP},
	{0, KEY_DOWN_ARROW, KEY_EVENT_DOWN, KEY_EVENT_UP},
};

fast_key_struct fast_key_to_auto_test[] = 
{
	{0, KEY_UP_ARROW, KEY_EVENT_DOWN, KEY_EVENT_UP},
	{0, KEY_CSK, KEY_EVENT_DOWN, KEY_EVENT_UP},
	{0, KEY_DOWN_ARROW, KEY_EVENT_DOWN, KEY_EVENT_UP},
	{0, KEY_RSK, KEY_EVENT_DOWN, KEY_EVENT_UP},
};

fast_key_struct fast_key_start_vibrator[] = 
{
	{0, KEY_VOL_UP, KEY_EVENT_DOWN, KEY_EVENT_UP},
	{0, KEY_CAMERA, KEY_EVENT_DOWN, KEY_EVENT_UP},
	{0, KEY_VOL_DOWN, KEY_EVENT_DOWN, KEY_EVENT_UP},
	{0, KEY_CAMERA, KEY_EVENT_DOWN, KEY_EVENT_UP},
};

fast_key_struct fast_key_stop_vibrator[] = 
{
	{0, KEY_VOL_DOWN, KEY_EVENT_DOWN, KEY_EVENT_UP},
	{0, KEY_CAMERA, KEY_EVENT_DOWN, KEY_EVENT_UP},
	{0, KEY_VOL_UP, KEY_EVENT_DOWN, KEY_EVENT_UP},
	{0, KEY_CAMERA, KEY_EVENT_DOWN, KEY_EVENT_UP},
};

#ifdef __BLE_MODULE_SUPPORT__
fast_key_struct fast_key_ble_on_off[] = 
{
	{0, KEY_UP_ARROW, KEY_EVENT_DOWN, KEY_EVENT_UP},
	{0, KEY_LSK, KEY_EVENT_DOWN, KEY_EVENT_UP},
	{0, KEY_LSK, KEY_EVENT_DOWN, KEY_EVENT_UP},
	{0, KEY_DOWN_ARROW, KEY_EVENT_DOWN, KEY_EVENT_UP},
};
#endif

fast_key_struct fast_key_rfid_on_off[] = 
{
	{0, KEY_CSK, KEY_EVENT_DOWN, KEY_EVENT_UP},
	{0, KEY_LSK, KEY_EVENT_DOWN, KEY_EVENT_UP},
	{0, KEY_LSK, KEY_EVENT_DOWN, KEY_EVENT_UP},
	{0, KEY_RSK, KEY_EVENT_DOWN, KEY_EVENT_UP},
};

fast_key_struct *fast_key_sum[] = {
									fast_key_to_test,
									fast_key_start_vibrator,
									fast_key_stop_vibrator,
								#ifdef __BLE_MODULE_SUPPORT__
									fast_key_ble_on_off,
								#endif
								#ifdef __KJX_RFID__
									fast_key_rfid_on_off
								#endif
								};

kjxPsVoidFunc fast_key_fun_sum[] = {
									kjx_factory_test_start,
									kjx_fast_key_start_vibrator,
									kjx_fast_key_stop_vibrator,
								#ifdef __BLE_MODULE_SUPPORT__
									kjx_fast_key_ble_on_off,
								#endif
								#ifdef __KJX_RFID__
									kjx_fast_key_rfid_on_off
								#endif
								};

fast_key_handler_struct fast_key_handler[FAST_KEY_HANDLER_TOTAL] = {0};

void kjx_fast_key_handler_init(void)
{
	U8 i,total;

	for(i=0;i<FAST_KEY_HANDLER_TOTAL;i++)
	{
		memcpy(fast_key_handler[i].fast_key, fast_key_sum[i], 4*sizeof(fast_key_struct));
		fast_key_handler[i].func = fast_key_fun_sum[i];
	}
}

void kjx_fast_key_start_vibrator(void)
{
	//马达测试开始
	char playString[]={0x6c,0x9a,0xbe,0x8f,0x4b,0x6d,0xd5,0x8b,0x0,0x5f,0xcb,0x59,0x0,0x0};

#if defined(__NPR_TTS__)
	if(mmi_ucs2strlen((const CHAR *)playString)>0)
	{
		Npr_Tts_play_stop();
		Npr_Ttsplayer_playtextw(playString,NULL);  
	}
#endif

	srv_vibrator_on();
}

void kjx_fast_key_stop_vibrator(void)
{
	//马达测试结束
	char playString[]={0x6C,0x9A,0xBE,0x8F,0x4B,0x6D,0xD5,0x8B,0xD3,0x7E,0x5F,0x67,0x0,0x0};

#if defined(__NPR_TTS__)
	if(mmi_ucs2strlen((const CHAR *)playString)>0)
	{
		Npr_Tts_play_stop();
		Npr_Ttsplayer_playtextw(playString,NULL);  
	}
#endif

	srv_vibrator_off();
}

#ifdef __BLE_MODULE_SUPPORT__
void kjx_fast_key_ble_on_off(void)
{
	char bleonString[]={0xDD,0x84,0x59,0x72,0xF2,0x5D,0xCF,0x7E,0x53,0x62,0x00,0x5F,0x0,0x0};
	char bleoffString[]={0xDD,0x84,0x59,0x72,0xF2,0x5D,0xCF,0x7E,0x73,0x51,0xED,0x95,0x0,0x0};
	
	if(g_kjx_nvram_struct.btflag == 0)
	{
		g_kjx_nvram_struct.btflag = 1;
		kjx_bt_ibeacon_init();
		kjx_nvram_write();
		
	#if 0	//defined(__NPR_TTS__)
		if(mmi_ucs2strlen((const CHAR *)bleonString)>0)
		{
			Npr_Tts_play_stop();
			Npr_Ttsplayer_playtextw(bleonString,NULL);	
		}
	#endif	
	}
	else
	{
		g_kjx_nvram_struct.btflag = 0;
		kjx_bt_ibeacon_off();
		kjx_nvram_write();
		
	#if 0	//defined(__NPR_TTS__)
		if(mmi_ucs2strlen((const CHAR *)bleoffString)>0)
		{
			Npr_Tts_play_stop();
			Npr_Ttsplayer_playtextw(bleoffString,NULL);  
		}
	#endif	
	}
}
#endif

#ifdef __KJX_RFID__
void kjx_fast_key_rfid_on_off(void)
{
	char rfidonString[]={0x52,0x00,0x46,0x00,0x49,0x00,0x44,0x00,0xF2,0x5D,0xCF,0x7E,0x53,0x62,0x00,0x5F,0x0,0x0};
	char rfidoffString[]={0x52,0x00,0x46,0x00,0x49,0x00,0x44,0x00,0xF2,0x5D,0xCF,0x7E,0x73,0x51,0xED,0x95,0x0,0x0};
	
	if(g_kjx_nvram_struct.rfidflag == 0)
	{
		g_kjx_nvram_struct.rfidflag = 1;
		kjx_rfid_init();
		kjx_nvram_write();

	#if 0	//defined(__NPR_TTS__)
		if(mmi_ucs2strlen((const CHAR *)rfidonString)>0)
		{
			Npr_Tts_play_stop();
			Npr_Ttsplayer_playtextw(rfidonString,NULL);  
		}
	#endif	
	}
	else
	{
		g_kjx_nvram_struct.rfidflag = 0;
		kjx_rfid_off();
		kjx_nvram_write();

	#if 0	//defined(__NPR_TTS__)
		if(mmi_ucs2strlen((const CHAR *)rfidoffString)>0)
		{
			Npr_Tts_play_stop();
			Npr_Ttsplayer_playtextw(rfidoffString,NULL);  
		}
	#endif	
	}
}
#endif

void kjx_check_fast_key_timeout(void)
{
	U8 i;
	U8 total = sizeof(tmp_key)/sizeof(fast_key_struct);

#ifdef KJX_KEYBRD_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif

	StopTimer(KJX_TIMER_ID_KEY_ENTRY_TEST);

	for(i=0;i<total;i++)
	{
		tmp_key[i].checkflag = 0;
		tmp_key[i].key_code = 0;
		tmp_key[i].key_type_begin = 0;
		tmp_key[i].key_type_end == 0;
	}

	key_index = 0;
}

BOOL kjx_check_fast_key_handler(U8 keycode, U8 keytype)
{
	U8 i,j,k;
	static U8 total = sizeof(tmp_key)/sizeof(fast_key_struct);

	if(tmp_key[key_index].checkflag == 0)
	{
		if(key_index == 0)
		{
		#ifdef KJX_KEYBRD_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("001 begin");
		#endif
		#endif
			
			tmp_key[key_index].checkflag = 1;
			tmp_key[key_index].key_code = keycode;
			tmp_key[key_index].key_type_begin = keytype;
			
			if(!IsMyTimerExist(KJX_TIMER_ID_KEY_ENTRY_TEST))
				StartTimer(KJX_TIMER_ID_KEY_ENTRY_TEST, 3000, kjx_check_fast_key_timeout);

			return FALSE;
		}
		else if(IsMyTimerExist(KJX_TIMER_ID_KEY_ENTRY_TEST))
		{
		#ifdef KJX_KEYBRD_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("001 continue");
		#endif
		#endif
		
			tmp_key[key_index].checkflag = 1;
			tmp_key[key_index].key_code = keycode;
			tmp_key[key_index].key_type_begin = keytype;

			return FALSE;
		}
		else
		{
		#ifdef KJX_KEYBRD_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("001 timeout");
		#endif
		#endif
			
			kjx_check_fast_key_timeout();
			return FALSE;
		}
	}
	else if(tmp_key[key_index].checkflag == 1)
	{
		if(IsMyTimerExist(KJX_TIMER_ID_KEY_ENTRY_TEST))
		{
			tmp_key[key_index].checkflag = 2;
			tmp_key[key_index].key_code = keycode;
			tmp_key[key_index].key_type_end = keytype;
			key_index++;

			for(j=0;j<FAST_KEY_HANDLER_TOTAL;j++)
			{
				U8 total_key = sizeof(fast_key_handler[j].fast_key)/sizeof(fast_key_struct);

				if(key_index == total_key)
				{
					for(k=0;k<total_key;k++)
					{
						if((fast_key_handler[j].fast_key[k].key_code != tmp_key[k].key_code)
							|| (fast_key_handler[j].fast_key[k].key_type_begin != tmp_key[k].key_type_begin)
							|| (fast_key_handler[j].fast_key[k].key_type_end != tmp_key[k].key_type_end)
							)
						{
							break;
						}
					}

					if(k == total_key)
					{//check ok
					#ifdef KJX_KEYBRD_DEBUG
					#if defined(__KJX_LOG_OUTPUT__)
						LOGD("002 check ok!total_key:%d, j:%d", total_key, j);
					#endif
					#endif
						fast_key_handler[j].func();

						kjx_check_fast_key_timeout();
						return TRUE;
					}
				}
			}
			
			if(key_index == total)
			{
			#ifdef KJX_KEYBRD_DEBUG
			#if defined(__KJX_LOG_OUTPUT__)
				LOGD("002 check key full");
			#endif
			#endif
				kjx_check_fast_key_timeout();
				return FALSE;	
			}
			else
			{
			#ifdef KJX_KEYBRD_DEBUG
			#if defined(__KJX_LOG_OUTPUT__)
				LOGD("002 continue");
			#endif
			#endif
				return FALSE;
			}	
		}
		else
		{
		#ifdef KJX_KEYBRD_DEBUG
		#if defined(__KJX_LOG_OUTPUT__)
			LOGD("002 timeout");
		#endif
		#endif
			kjx_check_fast_key_timeout();
			return FALSE;		
		}
	}
}
#endif

void kjx_endkey_proc_timeout(void)
{
#ifdef KJX_KEYBRD_DEBUG
#if defined(__KJX_LOG_OUTPUT__)
	LOGD("begin");
#endif
#endif
	power_off();
}

#if defined(__KJX_DJ_SUPPORT__)
extern void kjx_dj_main_show_tour_image(void);
#endif

static mmi_ret mmi_key_hdlr_proc(mmi_frm_key_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;
    FuncPtr curr_func_ptr;
    mmi_key_evt_struct key_evt;               
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    key_evt.cvt_code = evt->key_code;
    key_evt.mmi_key_type = evt->key_type;

    switch (evt->evt_id)
    {
        case EVT_ID_PRE_KEY:
        {
            if (MMI_FALSE == exec_dynamic_pre_key_handler(&key_evt))
            {
                ret = MMI_RET_KEY_HANDLED;
            }
            break;            
        }
        
        case EVT_ID_ON_KEY:
        {
		#if defined(__KJX_FUN__)	//xb add 2016-09-02 按键拦截处理统一接口
			{
			#if defined(__KJX_AGAINST_THEFT__)
				extern kal_bool g_rfid_against_theft;
			#endif
				extern int g_kjx_find_device;
				extern int g_kjx_enter_factory_test;
				extern int g_enter_key_test;
				extern nvram_ef_kjx_nvram_struct g_kjx_nvram_struct;
				
				extern void kjx_tour_key_sos1(void);
				extern void kjx_tour_key_sos2(void);
				extern void kjx_tour_key_sos(void);
				extern void kjx_key_handler_vol_up(void);
				extern void kjx_key_handler_vol_down(void);
				extern U16 kjx_is_in_call(void);
				extern BOOL kjx_is_in_confirm_display(void);
			#ifdef KJX_KEYBRD_DEBUG
			#if defined(__KJX_LOG_OUTPUT__)
				LOGD("key_code:%d, key_type:%d", evt->key_code, evt->key_type);
			#endif
			#endif

			#ifdef __KJX_AGAINST_THEFT__
				if(g_rfid_against_theft)
				{
				#ifdef KJX_KEYBRD_DEBUG
				#if defined(__KJX_LOG_OUTPUT__)
					LOGD("防丢报警状态，不响应按键操作");
				#endif
				#endif
					return MMI_RET_KEY_HANDLED;
				}
			#endif
			
				if((g_kjx_find_device == 1)&&(evt->key_type == KEY_EVENT_UP))
		    	{
		        	kjx_stop_ring_tone();
					return MMI_RET_KEY_HANDLED;
		    	}

			#ifdef __KJX_FAST_KEY_HANDLER__
				if(kjx_check_fast_key_handler(evt->key_code, evt->key_type))
				{
					return MMI_RET_KEY_HANDLED;
				}
			#endif
			
				if((g_kjx_enter_factory_test == 1) && (g_enter_key_test == 1)&&(evt->key_type == KEY_EVENT_UP))
				{
					kjx_factory_key_test(evt->key_code, evt->key_type);
					return MMI_RET_KEY_HANDLED;
				}

				switch(evt->key_code)
				{
				case KEY_VOL_UP:
					switch(evt->key_type)
					{
					case KEY_EVENT_DOWN:
						break;
						
					case KEY_EVENT_UP:
						break;
						
					case KEY_LONG_PRESS:	//xb add 2016-09-02 取消上下音量键SOS拨号的功能
						break;
					}
					break;

				case KEY_VOL_DOWN:
					switch(evt->key_type)
					{
					case KEY_EVENT_DOWN:
						break;

					case KEY_EVENT_UP:
						break;

					case KEY_LONG_PRESS:	//xb add 2016-09-02 取消上下音量键SOS拨号的功能
						break;
					}
					break;

				case KEY_CAMERA:
					switch(evt->key_type)
					{
					case KEY_EVENT_DOWN:
						break;

					case KEY_EVENT_UP:
						dj_key_flag = 1;
						if(IsMyTimerExist(KJX_TIMER_ID_DJ_KEY_CHECK))
							StopTimer(KJX_TIMER_ID_DJ_KEY_CHECK);
						StartTimer(KJX_TIMER_ID_DJ_KEY_CHECK, 500, kjx_dj_key_check_timerout);
						ret = MMI_RET_KEY_HANDLED;
						break;

					case KEY_LONG_PRESS:
						mmi_idle_display();
						kjx_tour_key_sos();
						ret = MMI_RET_KEY_HANDLED;
						break;
					}						
					break;

				case KEY_STAR:
					if(kjx_is_in_call())	//xb add 2017-08-08 通话界面不要显示出星号键
					{
						evt->key_code = KEY_EXTRA_A;
						break;
					}

					switch(evt->key_type)
					{
					case KEY_EVENT_DOWN:
						ret = MMI_RET_KEY_HANDLED;
						break;

					case KEY_EVENT_UP:
					#ifdef __KJX_MULTI_LANGUAGE__
						if(!kjx_is_in_call() && mmi_idle_is_active() && (kjx_get_foctory_test_mode() == 0))
						{
							kjx_system_language_alternate();
						}
					#endif
						ret = MMI_RET_KEY_HANDLED;
						break;

					case KEY_LONG_PRESS:
						ret = MMI_RET_KEY_HANDLED;
						break;
					}						
					break;						

				case KEY_UP_ARROW:
					switch(evt->key_type)
					{
					case KEY_EVENT_DOWN:
						break;

					case KEY_EVENT_UP:
						break;

					case KEY_LONG_PRESS:
						break;
					}	
					break;

				case KEY_DOWN_ARROW:
					switch(evt->key_type)
					{
					case KEY_EVENT_DOWN:
						break;

					case KEY_EVENT_UP:
						break;

					case KEY_LONG_PRESS:
						break;
					}		
					break;

				case KEY_LSK:
					switch(evt->key_type)
					{
					case KEY_EVENT_DOWN:
						break;

					case KEY_EVENT_UP:
					#if defined(__KJX_DJ_SUPPORT__)	
						if(dj_key_flag == 1)
						{
							dj_key_flag = 0;
							StopTimer(KJX_TIMER_ID_DJ_KEY_CHECK);
							kjx_dj_main_show_tour_image();
							ret = MMI_RET_KEY_HANDLED;
						}
					#endif
						break;

					case KEY_LONG_PRESS:
						break;
					}	
					break;

				case KEY_RSK:
					switch(evt->key_type)
					{
					case KEY_EVENT_DOWN:
						break;

					case KEY_EVENT_UP:
						break;

					case KEY_LONG_PRESS:
						break;
					}	
					break;

				case KEY_CSK:
					switch(evt->key_type)
					{
					case KEY_EVENT_DOWN:
						break;

					case KEY_EVENT_UP:
						if(!kjx_is_in_call() && (kjx_get_foctory_test_mode() == 0))
						{
							kjx_rfid_play_key_handler();
							ret = MMI_RET_KEY_HANDLED;
						}
						break;

					case KEY_LONG_PRESS:
						break;
					}	
					break;
					
				case KEY_END:
					switch(evt->key_type)
					{
					case KEY_EVENT_DOWN:
						if(IsMyTimerExist(KJX_TIMER_ID_END_KEY_DELAY))
							StopTimer(KJX_TIMER_ID_END_KEY_DELAY);
						break;

					case KEY_EVENT_UP:
						if(IsMyTimerExist(KJX_TIMER_ID_END_KEY_DELAY))
							StopTimer(KJX_TIMER_ID_END_KEY_DELAY);
						break;

					case KEY_LONG_PRESS:
					#if 1	//!defined(__KJX_RESET_USED_COUNT__)&&!defined(__KJX_AGAINST_THEFT__)
						if(!IsMyTimerExist(KJX_TIMER_ID_END_KEY_DELAY))
							StartTimer(KJX_TIMER_ID_END_KEY_DELAY, 2*1000, kjx_endkey_proc_timeout);
					#endif
						ret = MMI_RET_KEY_HANDLED;
						break;
					}
					break;
				}
			}
		#endif/*__KJX_FUN__*/
		
            if (g_key_cntx.is_screen_switch == MMI_FALSE ||
                g_key_cntx.is_send_to_new_scrn == MMI_TRUE ||
				g_key_cntx.is_key_event == MMI_FALSE ||
				is_mmi_power_off_key_evt(evt->key_code, evt->key_type) == MMI_TRUE)
            {

                if (mmi_frm_dispatch_key_event(
                    evt->key_code,
                    evt->key_type,
                    evt->ucs2_value,
                    evt->special_key_flag) == MMI_FALSE)
                {
               	#if defined(__GGT_TASK__)
				  #if defined(__OLED_BW_MMI__)
					// baiwenlin 20130904  左软键只能长按拨号有效
					if (evt->key_code == KEY_LSK && evt->key_type != KEY_EVENT_LONG_PRESS ||IS_IN_CALL())
					{
						return;
					}
					if(evt->key_code == KEY_LSK && evt->key_type == KEY_EVENT_LONG_PRESS)
					{
						if(mmi_get_sos_status() == 0)
						{
							sos_call_count = 0;
							mmi_idle_make_sos_call();
							return;
						}
					}
				  #endif /* __OLED_BW_MMI__ */
				  #if defined(__CITY_EASY_MODEL_W__)
				   #if defined(__CITY_EASY_WEB_DOG__)
					if (evt->key_code == KEY_LEFT_ARROW && evt->key_type == KEY_EVENT_LONG_PRESS &&!IS_IN_CALL())
					{
						key_down_reg = 0;
						//mmi_makecall_112();
					}
					else if (evt->key_code == KEY_RIGHT_ARROW && evt->key_type == KEY_EVENT_LONG_PRESS &&!IS_IN_CALL())
					{
						key_down_reg = 0;
					}

					if (evt->key_code == KEY_LEFT_ARROW && evt->key_type == KEY_EVENT_DOWN)
					{
						key_down_reg = 1;
					}
					else if (evt->key_code == KEY_RIGHT_ARROW && evt->key_type == KEY_EVENT_DOWN)
					{
						key_down_reg = 1;
					}
					else if((evt->key_code == KEY_POWER||evt->key_code == KEY_END)&& evt->key_type == KEY_EVENT_DOWN)
					{
						key_down_reg = 1;
						//mmi_edog_back_to_first_screen();
					}

					if (evt->key_code == KEY_LEFT_ARROW && evt->key_type == KEY_EVENT_UP)
					{
						if(key_down_reg == 1)
						{
							key_down_reg = 0;
							//city_edog_set_vol_up();
							right_status = KAL_TRUE;
							city_edog_infrared_switch();
						}
					}
					else if (evt->key_code == KEY_RIGHT_ARROW && evt->key_type == KEY_EVENT_UP)
					{
						if(key_down_reg == 1)
						{
							key_down_reg = 0;
							//city_edog_set_vol_down();
							left_status = KAL_TRUE;
							city_edog_infrared_switch();
						}
					}
					else if ((evt->key_code == KEY_POWER||evt->key_code == KEY_END) && evt->key_type == KEY_EVENT_UP)
					{
						if(key_down_reg == 1)
						{
							key_down_reg = 0;
							city_dog_infrared_up_set();
						}
					}
					if((evt->key_code == KEY_POWER||evt->key_code == KEY_END)&& evt->key_type == KEY_EVENT_LONG_PRESS)
					{
						gps_turn_off();
						key_down_reg = 0;

						curr_func_ptr = get_key_handler(evt->key_code, evt->key_type);
						if (curr_func_ptr)
						{
							(*curr_func_ptr)();
						}
					}
					ret = MMI_RET_KEY_HANDLED;
					break;
				   #else /*__CITY_EASY_WEB_DOG__*/
					if (evt->key_code == KEY_LEFT_ARROW && evt->key_type == KEY_EVENT_LONG_PRESS &&!IS_IN_CALL())
					{
						key_down_reg = 0;
						city_easy_send_by_sos();
					}
					else if (evt->key_code == KEY_LEFT_ARROW && evt->key_type == KEY_EVENT_DOWN)
					{
						key_down_reg = 1;
					}
					else if (evt->key_code == KEY_LEFT_ARROW && evt->key_type == KEY_EVENT_UP)
					{
						if(key_down_reg == 1)
						{
							key_down_reg = 0;
							if(cityeasy_led_ctrl_get_status() == 1)
							{
								cityeasy_led_ctrl_set_status(0);
							}
							else
							{
								cityeasy_led_ctrl_set_status(1);
							}
						}
					}
					else if (evt->key_code == KEY_RIGHT_ARROW && evt->key_type == KEY_EVENT_LONG_PRESS &&!IS_IN_CALL())
					{
						city_easy_send_by_key2();
					}
					else if (evt->key_code == KEY_UP_ARROW && evt->key_type == KEY_EVENT_LONG_PRESS &&!IS_IN_CALL())
					{
						city_easy_send_by_key1();
					}
					else if (evt->key_code == KEY_DOWN_ARROW && evt->key_type == KEY_EVENT_LONG_PRESS &&!IS_IN_CALL())
					{
						city_easy_send_by_key3();
					}
					if (evt->key_code == KEY_LEFT_ARROW && evt->key_type == KEY_EVENT_UP)
					{
						//cityeasy_alarm_status_set_and_send(0x31);
					}
					else if (evt->key_code == KEY_RIGHT_ARROW && evt->key_type == KEY_EVENT_UP)
					{
						cityeasy_alarm_status_set_and_send(0x34);
					}
					else if (evt->key_code == KEY_UP_ARROW && evt->key_type == KEY_EVENT_UP)
					{
						cityeasy_alarm_status_set_and_send(0x33);
					}
					else if (evt->key_code == KEY_DOWN_ARROW && evt->key_type == KEY_EVENT_UP)
					{
						cityeasy_alarm_status_set_and_send(0x32);
					}
					else if ((evt->key_code == KEY_POWER||evt->key_code == KEY_END) && evt->key_type == KEY_EVENT_DOWN)
					{
						if (IS_IN_CALL())
						{
							mmi_ucm_end_key();
						}
					}			
					if((evt->key_code == KEY_POWER||evt->key_code == KEY_END)&& evt->key_type == KEY_EVENT_LONG_PRESS ||evt->key_code == KEY_ENTER)
					{
						curr_func_ptr = get_key_handler(evt->key_code, evt->key_type);
						if (curr_func_ptr)
						{
							(*curr_func_ptr)();
						}
					}
					ret = MMI_RET_KEY_HANDLED;
					break;
				   #endif /* __CITY_EASY_WEB_DOG__ */
				  #endif /* __CITY_EASY_MODEL_W__ */
				#endif
                    /* get the key handler */
                    curr_func_ptr = get_key_handler(evt->key_code, evt->key_type);
                    MMI_TRACE(
                        MMI_FW_TRC_G1_FRM,
                        TRC_MMI_FRM_KEY_EXECUTE_KEY_HANDLER,
                        evt->key_code,
                        evt->key_type,
                        curr_func_ptr);            
                    /* invoke the key handler */
                    if (curr_func_ptr)
                    {
                        (*curr_func_ptr)();
                        ret = MMI_RET_KEY_HANDLED;
                    }
                }
                else
                {
                    ret = MMI_RET_KEY_HANDLED;
                }
            }
            break;     
        }
        
        case EVT_ID_POST_KEY:
        {
            exec_dynamic_post_key_handler(&key_evt);
            break;
        }
    }
    return ret;
}

void mmi_frm_release_input_mutex(U8 mmi_key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
               
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((mmi_key_type == KEY_EVENT_UP) || (mmi_key_type == KEY_HALF_PRESS_UP)) && g_key_cntx.buf_len == 1)
    {
    #if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
        mmi_pen_enable();
    #endif
    #if defined(__MMI_AVRCP_SUPPORT__) 
        srv_avrcp_frm_sync_calllback(MMI_FALSE);
    #endif
    }
}


static MMI_BOOL mmi_frm_is_input_engine_free(mmi_frm_input_device_type_emun input_device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
               
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (input_device == MMI_DEVICE_KEY)
    {
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
        kal_bool is_pen_enabled, is_pen_down;
        mmi_pen_get_state(&is_pen_enabled, &is_pen_down);
        return  (is_pen_down == KAL_TRUE) ? MMI_FALSE : MMI_TRUE;
#endif        
    }
    else
    {
        MMI_ASSERT(0);
    }
    return MMI_TRUE;
}

static void mmi_frm_get_input_mutex(U8 mmi_key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
               
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((mmi_key_type == KEY_EVENT_DOWN) || (mmi_key_type == KEY_HALF_PRESS_DOWN)) && g_key_cntx.buf_len == 1)
    {    
    #if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
        mmi_pen_disable();
    #endif

    #if defined(__MMI_AVRCP_SUPPORT__) 
        srv_avrcp_frm_sync_calllback(MMI_TRUE);
    #endif
    }
}




/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + Static pre handler and post key handler.
 *   static pre key handler and post key handler will be always invoked before and after key handler
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + Misc
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


/*****************************************************************************
 * FUNCTION
 *  process_key_ptr_change
 * DESCRIPTION
 *  Process the action of changing key function pointer.
 *  Make sure the final processed key event is event up for each key func pointer, 
 *  otherwise we clear all key events in the buffer belong to new key func pointer.
 *    [UT_functions]: ut_process_key_ptr_change
 * PARAMETERS
 *  paraBuff        :[IN]  The pointer to the parameter buffer.        
 * RETURNS
 *  void
 *****************************************************************************/
static void process_key_ptr_change(void * para_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_keypad_detect_ind_struct *p = (mmi_eq_keypad_detect_ind_struct*) para_buff;
    kbd_data k;
    //drv_get_key_func new_key_ptr;
    L4_keypad_mode_enum new_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p != NULL)
    {
        //new_key_ptr = (drv_get_key_func) (p->func);
        //MMI_ASSERT(new_key_ptr != NULL);
        new_type = (L4_keypad_mode_enum)p->func_type;
    #ifndef __MMI_FRM_KEY_EVENT_UT__
        //MMI_ASSERT(new_key_ptr == KBD_ATCMD_GET_KEY_FUNC || new_key_ptr == KBD_DRVIER_GET_KEY_FUNC);    
        MMI_ASSERT((new_type == L4_KEYPAD_HARDWARE) || (new_type == L4_KEYPAD_AT_COMMAND));
    #endif
        if (g_key_cntx.l4_keypad_mode != new_type)
        {/* g_key_cntx.keypad_ptr == NULL or g_key_cntx.keypad_ptr != new_key_ptr */
            if (g_key_cntx.buf_len !=0 )
            {/* 
              * Make sure the key data buffer is empty, 
              * otherwise we clear all key events in the buffer belong to new key func pointer.
              */
                while((get_key_evt_func[new_type])(&k) == MMI_TRUE);
            }
            else
            {/* g_key_cntx.keypad_ptr == NULL or processed final key event is event up. */
                
                /* clear the previous key buffer, make sure it can send primitive to replace the new one */
                if (get_key_evt_func[g_key_cntx.l4_keypad_mode] != NULL)
                {
                    while((get_key_evt_func[g_key_cntx.l4_keypad_mode])(&k) == MMI_TRUE);
                }                
    		    g_key_cntx.l4_keypad_mode = new_type;
                MMI_TRACE(PLUTO_FW_TRC_KEY, TRC_MMI_FRM_KEY_PTR_CHANGE_SUCCESS, g_key_cntx.l4_keypad_mode);  		    
    		}
		}
    }
}


#ifdef __MMI_VENUS_RT__
/*****************************************************************************
 * FUNCTION
 *  mmi_is_keypad_in_at_mode
 * DESCRIPTION
 *  Since, VFX RT is the only user of this currently, 
 *  we are not supporting it for others.
 *  In future, it may be enabled for other requirements.
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_TRUE if AT commands are running.
 *****************************************************************************/
MMI_BOOL mmi_is_keypad_in_at_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL)(g_key_cntx.l4_keypad_mode == L4_KEYPAD_AT_COMMAND);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  is_combo_key
 * DESCRIPTION
 *  This function is used to judge the mmi key code is combo key or not,
 *  like SHIFT FN..., The combo key means for example shift + A.
 *  Pay attention that there is no combo key in non-qwerty project.
 *    [UT_function:] ut_is_combo_key
 * PARAMETERS
 *  mmi_key_code  :[IN] mmi_key_code
 * RETURNS
 *  MMI_TRUE if combo key like SHIFT or not combo key
 *****************************************************************************/
static MMI_BOOL is_combo_key(S16 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    return mmi_frm_qwerty_is_special_key(mmi_key_code);
#else
    return MMI_FALSE;
#endif
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + The following function is key event handle flow
 +    1. dev_key_handle
 +    2. mmi_key_handle
 +    3. process_key_event_routing
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*****************************************************************************
 * FUNCTION
 *  dev_key_handle
 * DESCRIPTION
 *  This function is used to handle device key event.
 *
 * PARAMETERS
 *  dev_evt_p        :[IN]   device key event see dev_key_evt
 * RETURNS
 *  void
 *****************************************************************************/
static void dev_key_handle(dev_key_evt_struct *dev_evt_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_key_evt_struct  mmi_key_event_frm;
    dev_key_evt_struct  dev_evt[4];
    U8 len = 0;
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(PLUTO_FW_TRC_KEY, TRC_MMI_FRM_KEY_DEVICE_KEY_INFO, dev_evt_p->device_key_code, dev_evt_p->device_key_type);
    pre_process_dev_evt(dev_evt_p, dev_evt, &len);
    for (i = 0; i < len; i++)
    {
        /* Init the local data */
        mmi_key_event_frm.mmi_key_code = KEY_INVALID;
        mmi_key_event_frm.mmi_key_type = MAX_KEY_TYPE;
        mmi_key_event_frm.cvt_code     = KEY_INVALID;
        mmi_key_event_frm.is_clear     = MMI_FALSE;        
        
        /* get framework level mmi key events */
        get_mmi_key_events(&dev_evt[i], &mmi_key_event_frm);
        if( MMI_TRUE == is_valid_mmi_key_event(
            mmi_key_event_frm.mmi_key_code,
            mmi_key_event_frm.mmi_key_type))
        {
            mmi_key_handle(&mmi_key_event_frm);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  is_volume_key
 * DESCRIPTION
 *  This function is used to judge if the key code is volume key.
 *
 * PARAMETERS
 *  mmi_key_code        :[IN]   mmi key code
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL is_volume_key(U8 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if((mmi_key_code == KEY_VOL_UP) || (mmi_key_code == KEY_VOL_DOWN))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
    
}
/*****************************************************************************
 * FUNCTION
 *  mmi_key_handle
 * DESCRIPTION
 *  This function is used to handle framework level key event.
 *  The basic logic is:
 *      [1]pre update framework level key cntx
 *      [2]get application level key event
 *      [3]do application level key handle
 *      [4]post update framework level key cntx
 *  
 * PARAMETERS
 *  mmi_evt_p     :[IN] frm level key events pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_key_handle(mmi_key_evt_struct *mmi_evt_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    key_data_struct key_data;
    mmi_key_evt_struct exec_evt[2];
    mmi_frm_key_evt_struct key_event;
    U32 evt_num;
    U8 i;
    U16 ucs2_value = 0;
    U32 special_key_flag = 0;
    mmi_ret ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gen_key_data(mmi_evt_p, &key_data);
    pre_update_key_data_buf(&key_data);
    pre_update_end_call_state(&key_data);
#ifdef __KBD_2STEP_KEY_SUPPORT__
    pre_update_2step_key_state(mmi_evt_p->cvt_code, mmi_evt_p->mmi_key_type);
#endif /* __KBD_2STEP_KEY_SUPPORT__ */
    get_exec_key_evt(&key_data, exec_evt, &evt_num);
    for (i = 0; i < evt_num; i++)
    {
		update_key_proc_data(exec_evt[i].mmi_key_type ,MMI_FALSE);
        if (MMI_TRUE == mmi_frm_is_input_engine_free(MMI_DEVICE_KEY))
        {
            mmi_frm_get_input_mutex((U8)exec_evt[i].mmi_key_type);
            update_clear_state(&exec_evt[i]);
            mmi_frm_dss_defer_dump_string(MMI_FALSE);           
        #ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
            mmi_frm_qwerty_get_translated_code_and_special_key_flag(exec_evt[i].cvt_code, &ucs2_value, &special_key_flag);
        #endif            
                        /* Set key Info */
            mmi_frm_set_key_info(exec_evt[i].cvt_code, exec_evt[i].mmi_key_type);  
            MMI_TRACE(
                MMI_FW_TRC_G1_FRM,
                TRC_MMI_FRM_KEY_KEY_EVENT_INFO,
                exec_evt[i].cvt_code,
                exec_evt[i].mmi_key_type);
            MMI_FRM_INIT_EVENT(&key_event, EVT_ID_PRE_KEY_EVT_ROUTING);
            MMI_CONSTRUCT_KEY_EVENT(
                &key_event,
                exec_evt[i].cvt_code,
                exec_evt[i].mmi_key_type,
                ucs2_value,
                special_key_flag);
            ret = MMI_FRM_CB_EMIT_EVENT(&key_event);                
            /* Add volume key code to the condition, volume key in cosmos is a default handler key
               it needs to do jobs in both down event and up event. So if application calls clear key
               events, we should send the up event to volume dialog also.
            */
            if ((exec_evt[i].is_clear == MMI_FALSE) || 
                is_mmi_power_off_key_evt(exec_evt[i].cvt_code, exec_evt[i].mmi_key_type) || 
                is_volume_key(exec_evt[i].cvt_code))
            {    
                if (ret != MMI_RET_STOP_KEY_HANDLE)
                {
                    process_key_event_routing(&key_event);
                }
            }
            MMI_SET_EVENT_ID(&key_event, EVT_ID_POST_KEY_EVT_ROUTING);
            MMI_FRM_CB_EMIT_EVENT(&key_event);            
            /* If finish the key up handler, we reset the current key info. */
            if (exec_evt[i].mmi_key_type == KEY_EVENT_UP)
            {
                mmi_frm_set_key_info(exec_evt[i].cvt_code, MAX_KEY_TYPE);
            } 
            mmi_frm_release_input_mutex((U8)exec_evt[i].mmi_key_type);            
        }
        else
        {
            init_key_data_buf();
        }
		mmi_frm_invoke_post_event();
    }
#ifdef __KBD_2STEP_KEY_SUPPORT__
    post_update_2step_key_state(mmi_evt_p->cvt_code, mmi_evt_p->mmi_key_type);
#endif /* __KBD_2STEP_KEY_SUPPORT__ */    
    post_update_key_data_buf();
    post_update_end_call_state(&key_data);
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_construct_key_event
* DESCRIPTION
*  This function is used to initialize the key event structure.
*  If a module want to send/post a key event to another module
* 
* PARAMETERS
*  key_code     : [IN]  mmi key code
*  key_type     : [IN]  mmi key type
*  key_evt_p    : [IN]  the key event struct that need to be initialized 
*    
* RETURNS
*  void
* EXAMPLE
* <code>
*   //send a key event to xxx module's key proc function
*   mmi_frm_key_evt_struct key_evt;
*   mmi_frm_construct_key_event(KEY_1, KEY_EVENT_DOWN, &key_evt);
*   user_data = mmi_xxx_get_user_data();
*   mmi_frm_send_event(&key_evt, mmi_xxx_key_proc, user_data);
*
*   //post a key event to xxx module's key proc function
*   mmi_frm_key_evt_struct key_evt;
*   mmi_frm_construct_key_event(KEY_1, KEY_EVENT_DOWN, &key_evt);
*   user_data = mmi_xxx_get_user_data();
*   mmi_frm_post_event(&key_evt, mmi_xxx_key_proc, user_data);  
* </code>
*****************************************************************************/
void mmi_frm_construct_key_event(U8 key_code, U8 key_type, mmi_frm_key_evt_struct *key_evt_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ucs2_value = 0;
    U32 special_key_flag = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    key_code = (U8)mmi_frm_qwerty_convert_key_code((S16)key_code);
    mmi_frm_qwerty_get_translated_code_and_special_key_flag(key_code, &ucs2_value, &special_key_flag);
#endif /* __MMI_QWERTY_KEYPAD_SUPPORT__ */
    MMI_FRM_INIT_EVENT(key_evt_p, EVT_ID_ON_KEY);
    key_evt_p->key_code         = key_code;
    key_evt_p->key_type         = key_type;
    key_evt_p->ucs2_value       = ucs2_value;
    key_evt_p->special_key_flag = special_key_flag;
    key_evt_p->result           = MMI_RET_OK;    
}


/*****************************************************************************
* FUNCTION
*  mmi_frm_send_key_event
* DESCRIPTION
*  This function is used to initialize the key event structure.
*  If a module want to send/post a key event to another module
* 
* PARAMETERS
*  key_code     : [IN]  mmi key code
*  key_type     : [IN]  mmi key type
*    
* RETURNS
*  void
* EXAMPLE
* <code>
* </code>
*****************************************************************************/
void mmi_frm_send_key_event(U8 key_code, U8 key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct key_evt;
    //key_data_struct data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* only support */
    //MMI_ASSERT(g_key_cntx.buf_len == 0);
    mmi_frm_construct_key_event(key_code, key_type, &key_evt);

    /* Set key Info */
    mmi_frm_set_key_info(key_evt.key_code, key_evt.key_type);

    g_key_cntx.is_key_event = MMI_FALSE;
    update_key_proc_data((S16)key_code, MMI_TRUE);
    process_key_event_routing(&key_evt);

    g_key_cntx.is_key_event = MMI_TRUE;
    /* If finish the key up handler, we reset the current key info. */
    if (key_type == KEY_EVENT_UP)
    {    
        mmi_frm_set_key_info(key_type, MAX_KEY_TYPE);
    }
}


/*****************************************************************************
* FUNCTION
*  exec_key_handler
* DESCRIPTION
*  This function is used for executes current key function handler only. 
*  This function won't execute pre key handler and post key handler.
* PARAMETERS
*  keyCode     :[IN]    Key to which this event is associated.     
*  keyType     :[IN]    KEY_EVENT_UP, KEY_EVENT_DOWN, event occurs when the 
*                      key is pressed or released.      
* RETURNS
*  void
*****************************************************************************/
static void exec_key_handler(mmi_key_evt_struct *evt_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ucs2_value = 0;
    U32 special_key_flag = 0;
    FuncPtr curr_func_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    evt_p->cvt_code = mmi_frm_qwerty_convert_key_code(evt_p->cvt_code);
#endif
    
    /* Set key Info */
    mmi_frm_set_key_info(evt_p->cvt_code, evt_p->mmi_key_type);
    
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    mmi_frm_qwerty_get_translated_code_and_special_key_flag(evt_p->cvt_code, &ucs2_value, &special_key_flag);
#endif
    if (mmi_frm_dispatch_key_event(evt_p->cvt_code, evt_p->mmi_key_type, ucs2_value, special_key_flag) == MMI_FALSE)
    {                
        /* get the key handler */
        curr_func_ptr = get_key_handler(evt_p->cvt_code, evt_p->mmi_key_type);
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_EXECUTE_KEY_HANDLER, evt_p->cvt_code, evt_p->mmi_key_type, curr_func_ptr);
        
        /* invoke the key handler */
        if (curr_func_ptr)
        {
            mmi_frm_dss_defer_dump_string(MMI_FALSE);    
            (*curr_func_ptr)();    
        }
    }
    
    /* If finish the key up handler, we reset the current key info. */
    if (evt_p->mmi_key_type == KEY_EVENT_UP)
    {    
        mmi_frm_set_key_info(evt_p->cvt_code, MAX_KEY_TYPE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  process_key_event_routing
 * DESCRIPTION
 *  This function is used for executes current key function handler only. 
 *  This function won't execute pre key handler and post key handler.
 * PARAMETERS
 *  key_evt_p     :[IN] key event   
 *     
 * RETURNS
 *  void
 *****************************************************************************/
static void process_key_event_routing(mmi_frm_key_evt_struct *key_evt_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer;
    MMI_BOOL pre_stop    = MMI_FALSE;
    S32 bwd_start_layer  = MMI_KEY_ROUTING_TOTAL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (layer = 0; layer < MMI_KEY_ROUTING_TOTAL; layer++)
    {
        if (GET_KEY_PROC(layer) != NULL)
        {
            MMI_SET_EVENT_ID(key_evt_p, EVT_ID_PRE_KEY); 
            if (MMI_FRM_SEND_EVENT(key_evt_p, GET_KEY_PROC(layer), GET_USER_DATA(layer)) != MMI_RET_OK)
            {
                pre_stop = MMI_TRUE;
                bwd_start_layer = layer - 1;
                break;
            }
        }
    }

    if (pre_stop == MMI_FALSE)
    {
        bwd_start_layer = MMI_KEY_ROUTING_KEY_HDLR;

        for (layer = bwd_start_layer; layer >= MMI_KEY_ROUTING_SYS; layer--)
        {
            if (GET_KEY_PROC(layer) != NULL)
            {
                MMI_SET_EVENT_ID(key_evt_p, EVT_ID_ON_KEY);
                if (MMI_FRM_SEND_EVENT(key_evt_p, GET_KEY_PROC(layer), GET_USER_DATA(layer)) != MMI_RET_OK)
                {
                    bwd_start_layer = layer;
                    break;
                }
                MMI_SET_EVENT_ID(key_evt_p, EVT_ID_POST_KEY);
                if (GET_KEY_PROC(layer) != NULL)
                {
                    MMI_FRM_SEND_EVENT(key_evt_p, GET_KEY_PROC(layer), GET_USER_DATA(layer));
                }
                bwd_start_layer = layer - 1;
            }
        }
    }
    
    for (layer = bwd_start_layer; layer >= MMI_KEY_ROUTING_SYS; layer--)
    {
        if (GET_KEY_PROC(layer) != NULL)
        {
            MMI_SET_EVENT_ID(key_evt_p, EVT_ID_POST_KEY);
            MMI_FRM_SEND_EVENT(key_evt_p, GET_KEY_PROC(layer), GET_USER_DATA(layer));
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  exec_dynamic_post_key_handler
 * DESCRIPTION
 *  This function is used to get any key handler.
 * PARAMETERS
 *  evt_p       :[IN] mmi key event
 *
 * RETURNS
 *  void
 *****************************************************************************/ 
static void exec_dynamic_post_key_handler(mmi_key_evt_struct *evt_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    KEYBRD_MESSAGE key_msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    //MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_EXECUTE_POST_KEY_HANDLER, g_key_cntx.kbd_post_func);
    key_msg.nMsgType = evt_p->mmi_key_type;
    key_msg.nKeyCode = evt_p->cvt_code;        
    if (g_key_cntx.kbd_post_func)
    {
        g_key_cntx.kbd_post_func(&key_msg);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  exec_dynamic_pre_key_handler
 * DESCRIPTION
 *  This function is used to execute dynamic pre key handler
 * PARAMETERS
 *  evt_p       :[IN] mmi key event
 *
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/ 
static MMI_BOOL exec_dynamic_pre_key_handler(mmi_key_evt_struct *evt_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    KEYBRD_MESSAGE key_msg;
    MMI_BOOL ret = MMI_TRUE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    //MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_EXECUTE_PRE_KEY_HANDLER, g_key_cntx.kbd_pre_func);    
    key_msg.nMsgType = evt_p->mmi_key_type;
    key_msg.nKeyCode = evt_p->cvt_code;       

    if (g_key_cntx.kbd_pre_func)
    {
        ret = (MMI_BOOL)g_key_cntx.kbd_pre_func(&key_msg);
    } 
    return ret; 
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + The following function is key event generation
 +    1. get_mmi_key_events
 +    2. get_exec_key_evt
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*****************************************************************************
 * FUNCTION
 *  get_mmi_key_events
 * DESCRIPTION
 *  get mmi key event from device key event
 *  [UT function]: ut_get_mmi_key_events
 * PARAMETERS
 *  dev_evt_p      :[IN]   pointer to 1 device key event
 *  mmi_evt_p      :[OUT]  pointer to 1 mmi key event 
 * RETURNS
 *  void
 *****************************************************************************/
static void get_mmi_key_events(dev_key_evt_struct *dev_evt_p, mmi_key_evt_struct *mmi_evt_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 mmi_key_code;
    S16 mmi_key_type;
    S16 prev_mmi_key_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_key_code = get_mmi_key_code(dev_evt_p->device_key_code);
    mmi_evt_p->cvt_code = mmi_key_code_convert(mmi_key_code, dev_evt_p->device_key_type);

    if ((mmi_key_code == KEY_INVALID) && !is_detection_evt(dev_evt_p->device_key_type))
    {
        mmi_evt_p->mmi_key_code = KEY_INVALID;
        mmi_evt_p->mmi_key_type = ERR_KEY_CODE;
        return;
    }
    mmi_key_type = get_mmi_key_type(dev_evt_p->device_key_type, GET_KEY_CAT(mmi_key_code));
    if ((mmi_key_type < MAX_KEY_TYPE) && (mmi_key_type >=0))
    {
        prev_mmi_key_type = get_key_state(mmi_key_code);
        if (is_legal_key_type(mmi_key_type, prev_mmi_key_type, GET_KEY_CAT(mmi_key_code)) == MMI_FALSE)
        {
            mmi_key_type =  ERR_KEY_EVT_TRANS;
        }
    }
    mmi_evt_p->mmi_key_code = mmi_key_code;
    mmi_evt_p->mmi_key_type = mmi_key_type;
    mmi_evt_p->is_clear = dev_evt_p->is_clear;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  get_exec_key_evt
 * DESCRIPTION
 *  This function is used to get executable key event
 *  [UT function]: ut_get_exec_key_evt
 * PARAMETERS
 *  data_p        :[IN]  key data 
 *  exec_evt_p    :[OUT] executable key events buffer
 *  evt_num_p     :[OUT] executable key events number
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void get_exec_key_evt(key_data_struct *data_p, mmi_key_evt_struct *exec_evt_p, U32 *evt_num_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __KBD_2STEP_KEY_SUPPORT__
    U8 state;
#endif /* __KBD_2STEP_KEY_SUPPORT__ */
    U8 mode;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    exec_evt_p[0].mmi_key_code = data_p->mmi_key_code;
    exec_evt_p[0].mmi_key_type = data_p->mmi_key_type;
    exec_evt_p[0].cvt_code = data_p->cvt_code;
    exec_evt_p[0].is_clear = data_p->is_clear;
    *evt_num_p = 1;
 #ifdef __KBD_2STEP_KEY_SUPPORT__
    if (data_p->is_2step == MMI_TRUE)
    {
        if (data_p->mmi_key_type == KEY_EVENT_UP)
        {
            state = get_2step_key_state(data_p->mmi_key_code);
            if (state == FULL_DOWN)
            {
                exec_evt_p[0].mmi_key_type = KEY_HALF_PRESS_UP;
                exec_evt_p[1].mmi_key_code = data_p->mmi_key_code;
                exec_evt_p[1].cvt_code = data_p->cvt_code;
                exec_evt_p[1].is_clear = data_p->is_clear;
                exec_evt_p[1].mmi_key_type = KEY_EVENT_UP;
                *evt_num_p = 2;
            }
            else if (state == HALF_DOWN)
            {
                exec_evt_p[0].mmi_key_type = KEY_HALF_PRESS_UP;
            }
            else
            {
                MMI_ASSERT(0);
            } 
        }
    }
    else
#endif /* __KBD_2STEP_KEY_SUPPORT__ */
    {
    	#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
        mode = GET_KPD_MODE(g_key_cntx.keypad_status);
        if (mode == KEYPAD_1KEY_NUMBER || mode == KEYPAD_1KEY_QWERTY)
        {
            if (g_key_cntx.buf_len == 2)
            {
                key_data_struct data1;
                key_data_struct data2;
                get_key_data(&data1, 0);
                get_key_data(&data2, 1);
                if (data2.mmi_key_code == data_p->mmi_key_code)
                {
                    if (!is_combo_key(data1.mmi_key_code) && !is_combo_key(data2.mmi_key_code))
                    {
                        if (data1.mmi_key_type != KEY_EVENT_UP && data2.mmi_key_type == KEY_EVENT_DOWN)
                        {
                            MMI_ASSERT(data_p->mmi_key_type == KEY_EVENT_DOWN);
                            data1.mmi_key_type = KEY_EVENT_UP;
                            update_key_data(&data1);
                            exec_evt_p[0].mmi_key_code = data1.mmi_key_code;
                            exec_evt_p[0].mmi_key_type = data1.mmi_key_type;
                            exec_evt_p[0].cvt_code = data1.cvt_code;
                            exec_evt_p[0].is_clear = data1.is_clear;
                            exec_evt_p[1].mmi_key_code = data_p->mmi_key_code;
                            exec_evt_p[1].mmi_key_type = data_p->mmi_key_type;
                            exec_evt_p[1].cvt_code = data_p->cvt_code;
                            exec_evt_p[1].is_clear = data_p->is_clear;
                            *evt_num_p = 2;
                        }
                    }
                }
            }
        }
		#endif
    }
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + The following function is key context related functions:
 +    1. init_key_data_buf
 +    2. insert_key_data
 +    3. search_key_data
 +    4. update_key_data
 +    5. remove_key_data
 +    6. mmi_frm_get_mmi_key_state
 + description:
 +    1. structure - array 
 +     ###############################
 +     # entry 0 # entry 1 # entry2  #
 +     ###############################
 +    2.Operation
 +       Init, Insert, Search, Update, Remove, Get
 +    
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
 /*****************************************************************************
 * FUNCTION
 *  init_key_data_buf
 * DESCRIPTION
 *  This function is used to init key data buffer.
 *  After init for each entry like the following:
 *     ++++++++++++++++
 *     + KEY_INVALID  + (mmi_key_code)
 *     ++++++++++++++++
 *     + KEY_EVENT_UP + (mmi key type)
 *     ++++++++++++++++
 *     +     00       + (other field)
 *     ++++++++++++++++
 *  [UT function:] ut_init_key_data_buf
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void init_key_data_buf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_key_cntx.buffer, 0x00, sizeof(g_key_cntx.buffer));
    g_key_cntx.buf_len = 0;
    for (j = 0; j < MAX_DECT_KEY_NUM; j++)
    {
        g_key_cntx.buffer[j].mmi_key_code = KEY_INVALID;
        g_key_cntx.buffer[j].cvt_code     = KEY_INVALID;
        g_key_cntx.buffer[j].mmi_key_type = KEY_EVENT_UP;
    }
} 


/*****************************************************************************
 * FUNCTION
 *  insert_key_data
 * DESCRIPTION
 *  This function is used to insert mmi key code to key data buffer
 *  The basic logic is insert the data to the first KEY_INVALID in the table
 *  e.g. Entry number is 2
 *  insert KEY0 
 *                +++++++++++++++++++++++++++++               +++++++++++++++++++++++++++++
 *  before insert + KEY_INVALID + KEY_INVALID + after insert  +   KEY_0     + KEY_INVALID +
 *                +++++++++++++++++++++++++++++               +++++++++++++++++++++++++++++
 *  insert KEY0
 *                +++++++++++++++++++++++++++++               
 *  before insert + KEY_0       + KEY_INVALID + after insert  Assert happen
 *                +++++++++++++++++++++++++++++
 *  insert KEY1
 *                +++++++++++++++++++++++++++++               +++++++++++++++++++++++++++++
 *  before insert + KEY_0       + KEY_INVALID + after insert  +   KEY_0     + KEY_1       +
 *                +++++++++++++++++++++++++++++               +++++++++++++++++++++++++++++
 *  insert KEY3
 *                +++++++++++++++++++++++++++++               
 *  before insert + KEY_0       + KEY_1       + after insert assert happen
 *                +++++++++++++++++++++++++++++               
 *  insert KEY0(This case is not implement, should make sure this case not happen when remove)
 *                +++++++++++++++++++++++++++++               
 *  before insert + KEY_INVALID + KEY_1       +
 *                +++++++++++++++++++++++++++++
 *  [UT function]:ut_insert_key_data
 *
 * PARAMETERS
 *  data_p     :[IN]   key data see key_data_struct
 *
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret insert_key_data(key_data_struct * data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 det_num;
    key_data_struct *buffer_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    det_num = GET_KEY_DET_MODE(g_key_cntx.keypad_status) + 1;
    buffer_p = g_key_cntx.buffer;
    for(i = 0; i < det_num; i++)
    {
        /*
         * if we find mmi_key_code already exists in key data buffer,
         * we assert here because we should not get down, down for same key
         */

        if (buffer_p[i].mmi_key_code == data_p->mmi_key_code)
        {
		#ifndef __MMI_FRM_KEY_EVENT_UT__	
            MMI_ASSERT(0);
		#endif /* __MMI_FRM_KEY_EVENT_UT__ */
            return INSERT_SAME_KEY_CODE;
        }

        /*
         * we will find the first empty entry for the new pressing mmi key code
         */
        if (buffer_p[i].mmi_key_code == KEY_INVALID)
        {
            buffer_p[i].mmi_key_code = data_p->mmi_key_code;
            buffer_p[i].cvt_code = data_p->cvt_code;
            buffer_p[i].mmi_key_type = data_p->mmi_key_type;
            buffer_p[i].cvt_code    = data_p->cvt_code;
            buffer_p[i].is_combo   = data_p->is_combo;
            buffer_p[i].is_2step     = data_p->is_2step;
            buffer_p[i].is_clear     = data_p->is_clear;
            g_key_cntx.buf_len++;
            return MMI_RET_OK;
        }
    }
    /*
     * Multi-key behavior is wrong
     * So we assert here and ask driver to check.
     */
#ifndef  __MMI_FRM_KEY_EVENT_UT__    
    MMI_ASSERT(0);
#endif /* __MMI_FRM_KEY_EVENT_UT__ */
    return INSERT_CODE_BEYOND_DECT;
}


/*****************************************************************************
 * FUNCTION
 *  search_key_data
 * DESCRIPTION
 *  This function is used to find the key context index for mmi_key_code
 *  [UT function]: ut_search_key_data
 * PARAMETERS
 *  mmi_key_code     :[IN]   mmi key code
 *
 * RETURNS
 *  index if found, or -1
 *****************************************************************************/
static S32 search_key_data(S16 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = -1;
    S32 i;
    S32 det_num;
    key_data_struct *buffer_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    det_num = GET_KEY_DET_MODE(g_key_cntx.keypad_status) + 1;
    buffer_p = g_key_cntx.buffer;

    for(i = 0; i < det_num; i++)
    {
        if ((S16)buffer_p[i].mmi_key_code == mmi_key_code)
        {
            index = i;
            break;
        }
    }
    return index;
}


/*****************************************************************************
 * FUNCTION
 *  update_key_data
 * DESCRIPTION
 *  This function is used to update key data buffer(Only update key type)
 *  [UT function:]ut_update_key_data
 * PARAMETERS 
 *  data_ptr     :[IN]   key data  
 *
 * RETURNS
 *  MMI_TRUE if changed, or MMI_FALSE
 *****************************************************************************/
static MMI_BOOL update_key_data(key_data_struct *data_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    key_data_struct *buffer_p;
    S32 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    buffer_p = g_key_cntx.buffer;
    if ((index = search_key_data((S16)data_ptr->mmi_key_code)) != -1)
    {
        buffer_p[index].mmi_key_type = data_ptr->mmi_key_type;
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  remove_key_data
 * DESCRIPTION
 *  This function is used to delete mmi key code from key data buffer
 *  remove KEY0
 *                +++++++++++++++++++++++++++++               +++++++++++++++++++++++++++++
 *  before remove + KEY_0       + KEY_INVALID + after remove  + KEY_INVALID + KEY_INVALID +
 *                +++++++++++++++++++++++++++++               +++++++++++++++++++++++++++++
 *
 *  remove KEY0
 *                +++++++++++++++++++++++++++++               +++++++++++++++++++++++++++++
 *  before remove + KEY_0       + KEY_1       + after remove  + KEY_1       + KEY_INVALID +
 *                +++++++++++++++++++++++++++++               +++++++++++++++++++++++++++++
 *
 *  remove KEY1
 *                +++++++++++++++++++++++++++++               +++++++++++++++++++++++++++++
 *  before remove + KEY_0       + KEY_1       + after remove  + KEY_0       + KEY_INVALID +
 *                +++++++++++++++++++++++++++++               +++++++++++++++++++++++++++++
 *  [UT Function]: ut_remove_key_data
 * PARAMETERS
 *  mmi_key_code     :[IN]   mmi key code
 *
 *
 * RETURNS
 *  void 
 *****************************************************************************/
static mmi_ret remove_key_data(S16 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32             index;
    S32             i;
    key_data_struct *buffer_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    buffer_p = g_key_cntx.buffer;
    if ((index = search_key_data(mmi_key_code)) != -1)
    {
        for (i = index; i < MAX_DECT_KEY_NUM - 1; i++)
        {
            buffer_p[i] = buffer_p[i + 1];
        }
        buffer_p[MAX_DECT_KEY_NUM - 1].mmi_key_code = KEY_INVALID;
        buffer_p[MAX_DECT_KEY_NUM - 1].cvt_code = KEY_INVALID;
        MMI_ASSERT(g_key_cntx.buf_len > 0);
        g_key_cntx.buf_len--;
		return MMI_RET_OK;
    }
	return REMOVE_BUT_NOT_FOUND;
}


/*****************************************************************************
 * FUNCTION
 *  get_key_state
 * DESCRIPTION
 *  This function is used to get mmi key state.
 *  [UT function]:ut_get_key_state
 *
 * PARAMETERS
 *  mmi_key_code     :[IN] mmi_key code
 *
 * RETURNS
 *  mmi key type see mmi_key_types_enum
 *****************************************************************************/
static S16 get_key_state(S16 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((index = search_key_data(mmi_key_code)) != -1)
    {
        return (S16)g_key_cntx.buffer[index].mmi_key_type;
    }
    else
    {       
        /* 
         * If we cannot find the mmi_key_code in key data buffer, the key should be in up
         * status for both normal key and 2step key. 
         */
        return (S16)KEY_EVENT_UP;
    }
}


/*****************************************************************************
 * FUNCTION
 *  get_key_data
 * DESCRIPTION
 *  This function is used to get key data from data buffer by index
 *  [UT function]: ut_get_key_data
 * PARAMETERS
 *  index     :[IN] data buffer index
 *  data_p    :[OUT] key data 
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void get_key_data(key_data_struct *data_p, U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(index < MAX_DECT_KEY_NUM);
    memcpy(data_p, &g_key_cntx.buffer[index], sizeof(key_data_struct));
}


/*****************************************************************************
 * FUNCTION
 *  set_all_key_data_clear
 * DESCRIPTION
 *  This function is used to all key data in data buffer as clear state
 *  [UT function:]ut_set_all_key_data_clear
 * PARAMETERS 
 *  void 
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void set_all_key_data_clear(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_key_cntx.buf_len; i++)
    {
        g_key_cntx.buffer[i].is_clear = MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  update_clear_state
 * DESCRIPTION
 *  This function is used to update clear state of a execute event
 *  [UT function:]ut_update_clear_state
 * PARAMETERS 
 *  void 
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void update_clear_state(mmi_key_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((index = search_key_data(evt->mmi_key_code)) != -1)
    {
        evt->is_clear = g_key_cntx.buffer[index].is_clear;
    }
}


/*****************************************************************************
 * FUNCTION
 *  pre_update_key_data_buf
 * DESCRIPTION
 *  This function is used to update key data buffer before key handler
 *  [UT function]: ut_pre_update_key_data_buf
 *
 * PARAMETERS
 *  data_p     :[IN] key data pointer
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void pre_update_key_data_buf(key_data_struct *data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data_p->mmi_key_type == KEY_EVENT_DOWN && (MMI_FALSE == is_2step_key(data_p->mmi_key_code)) ||
    data_p->mmi_key_type == KEY_HALF_PRESS_DOWN && (MMI_TRUE == is_2step_key(data_p->mmi_key_code)))
    {
        insert_key_data(data_p);
    }
    else
    {
        MMI_ASSERT(data_p->mmi_key_type != KEY_HALF_PRESS_UP);
        update_key_data(data_p);
    }
}


/*****************************************************************************
 * FUNCTION
 *  post_update_key_data_buf
 * DESCRIPTION
 *  This function is used to update key data buffer after key handler
 *  remove all key data that is in UP state
 *  [UT function]: ut_post_update_key_data_buf
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void post_update_key_data_buf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8  rm_code[MAX_DECT_KEY_NUM];
    U8  rm_count = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    for (i = 0; i < g_key_cntx.buf_len; i++)
    {
        if (g_key_cntx.buffer[i].mmi_key_type == KEY_EVENT_UP)
        {
            rm_code[rm_count] = g_key_cntx.buffer[i].mmi_key_code;
            rm_count++;
        }
    }
    for (i = 0; i < rm_count; i++)
    {
        remove_key_data(rm_code[i]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gen_key_data
 * DESCRIPTION
 *  This function is used to generate key data for one key event from driver
 *  [UT function]: ut_gen_key_data
 *
 * PARAMETERS
 *  mmi_key_evt_struct  :[IN] mmi key event
 *  data_p              :[OUT] key data pointer
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void gen_key_data(mmi_key_evt_struct *evt, key_data_struct *data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_p->mmi_key_code = (U8)evt->mmi_key_code;
    data_p->mmi_key_type = (U8)evt->mmi_key_type;
    data_p->cvt_code     = (U8)evt->cvt_code;
#ifdef __KBD_2STEP_KEY_SUPPORT__    
    data_p->is_2step = is_2step_key(evt->mmi_key_code);
#else /* __KBD_2STEP_KEY_SUPPORT__ */
    data_p->is_2step = MMI_FALSE;
#endif
    data_p->is_clear = evt->is_clear;
    data_p->is_combo = is_combo_key(evt->mmi_key_code);
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + The following function is 2 step key related function:
 +    1. is_2step_key
 +    2. get_2step_key_state
 +    remark: what is 2step key, the 2step means key down has 2step, half down and full down
 +    like camera key, half down to focus, full down to take a picture
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

 /*****************************************************************************
 * FUNCTION
 *  is_2step_key
 * DESCRIPTION
 *  This function is used to judge if the key is 2step key or not
 *  [UT function]:ut_is_2step_key
 * PARAMETERS
 *  mmi_key_code   :[IN]  mmi_key_code
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL is_2step_key(S16 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __KBD_2STEP_KEY_SUPPORT__
    return ((S16)g_key_cntx._2step_key.mmi_key_code == mmi_key_code);
#else
    return MMI_FALSE;
#endif
}

#ifdef __KBD_2STEP_KEY_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  get_2step_key_state
 * DESCRIPTION
 *  This function is used to get 2step key state, make sure the mmi key code 
 *  is 2step key or assert will happen.
 *  [UT function]:ut_get_2step_key_state
 *
 * PARAMETERS
 *  mmi_key_code   :[IN]  mmi_key_code
 * RETURNS
 *  _2step_state_enum
 *****************************************************************************/
static U8 get_2step_key_state(S16 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(is_2step_key(mmi_key_code) == MMI_TRUE)
    {
        return g_key_cntx._2step_key.state;
    }
    else
    {
        return (U8)STATE_END;
    }
}


/*****************************************************************************
 * FUNCTION
 *  pre_update_2step_key_state
 * DESCRIPTION
 *  This function is used to update 2step key state before key handler
 *
 *  [UT function]:ut_pre_update_2step_key_state
 *
 * PARAMETERS
 *  mmi_key_code   :[IN]  mmi_key_code
 *  mmi_key_type   :[IN]  mmi_key_type
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void pre_update_2step_key_state(S16 mmi_key_code, S16 mmi_key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == is_2step_key(mmi_key_code))
    {
        if (mmi_key_type == KEY_HALF_PRESS_DOWN)
        {
            g_key_cntx._2step_key.state = HALF_DOWN;
        }
        else if (mmi_key_type == KEY_FULL_PRESS_DOWN)
        {
            g_key_cntx._2step_key.state = FULL_DOWN;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  post_update_2step_key_state
 * DESCRIPTION
 *  This function is used to update 2step key state after key handler
 *
 *  [UT function]:ut_post_update_2step_key_state
 *
 * PARAMETERS
 *  mmi_key_code   :[IN]  mmi_key_code
 * RETURNS
 *  void
 *****************************************************************************/
static void post_update_2step_key_state(S16 mmi_key_code, S16 mmi_key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == is_2step_key(mmi_key_code))
    {
        if (mmi_key_type == KEY_EVENT_UP)
        {
            g_key_cntx._2step_key.state = FULL_UP;
        }
    }
}
#endif /* __KBD_2STEP_KEY_SUPPORT__ */

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + The following function is the operation for key type transformation and check:
 +    1.get_mmi_key_type
 +    2.is_legal_key_type  
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

 /*****************************************************************************
 * FUNCTION
 *  get_mmi_key_type
 * DESCRIPTION
 *  This function is used to get mmi key type from device level to framework level
 *    1. Detection event   
 *      DRV_WM_ENABLE_TWOKEY_DETECTION
 *      DRV_WM_ENABLE_THREEKEY_DETECTION
 *      DRV_WM_DISABLE_MULTIKEY_DETECTION
 *   all mapping to KEY_EVENT_DECT
 *   when we get detection event from driver, it means the key detection mode has been changed by driver.
 *   so we update key detection mode when receive these kinds of event
 *    2. Non-2step key type mapping
 *       DRV_WM_KEYPRESS     -> KEY_EVENT_DOWN
 *       DRV_WM_KEYRELEASE   -> KEY_EVENT_UP
 *       DRV_WM_KEYLONGPRESS -> KEY_LONG_PRESS
 *       DRV_WM_KEYREPEATED  -> KEY_REPEAT
 *    3. 2tep key type mapping
 *       DRV_WM_KEYPRESS     -> KEY_HALF_PRESS_DOWN
 *       DRV_WM_KEYRELEASE   -> KEY_EVENT_UP
 *       DRV_WM_KEYLONGPRESS -> KEY_LONG_PRESS
 *       DRV_WM_KEYREPEATED  -> KEY_REPEAT
 *       DRV_WM_KEYFULLPRESS -> KEY_FULL_PRESS_DOWN
 *  [Attention Point]:
 *    1. invalid device key type, assert.
 *    2. DRV_WM_KEYFULLPRESS for non-2step key, assert.
 *  [UT function]:ut_get_mmi_key_type
 * PARAMETERS
 *  device_key_type   :[IN]  device key type
 *  cat               :[IN]  TWO_STEP_KEY or NON_TWO_STEP_KEY
 * RETURNS
 *  mmi_key_type
 *****************************************************************************/
static S16 get_mmi_key_type(U8 device_key_type, U8 cat)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < ARRAYSIZE(g_key_type_map); i++)
    {
        if (GET_DEV_KEY_TYPE(g_key_type_map[i]) == device_key_type)
        {
            if (GET_MMI_KEY_TYPE(g_key_type_map[i]) == MAX_KEY_TYPE)
            {
                SET_KEY_DET_MODE(g_key_cntx.keypad_status, GET_CAT(g_key_type_map[i]));
                return (S16)KEY_EVENT_DECT;
            }
            if (GET_CAT(g_key_type_map[i]) & cat)
            {
                return (S16)GET_MMI_KEY_TYPE(g_key_type_map[i]);
            }
        }
    }
#ifndef __MMI_FRM_KEY_EVENT_UT__
    MMI_ASSERT(0);
#endif
    return ERR_KEY_EVENT;
}


/*****************************************************************************
* FUNCTION
*  pre_process_dev_evt
* DESCRIPTION
*  This function is used to supplement a END/Power key's down event and up event
*  when receive END/Power key's longpress event and end key's down event is cleared
*  by clearkyEvents
*
*  [UT function]:ut_is_pre_process_dev_evt
* PARAMETERS
*  in          : [IN]   input dev event
*  out         : [OUT]  output dev event
*  out_len     : [OUT]  dev event length  
* RETURNS
*  MMI_TRUE if valid mmi key event
*****************************************************************************/
static void pre_process_dev_evt(dev_key_evt_struct *in, dev_key_evt_struct *out, U8 *out_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 type[4]       = {DRV_WM_KEYPRESS, DRV_WM_KEYLONGPRESS, DRV_WM_KEYREPEATED, DRV_WM_KEYRELEASE};
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((is_power_off_key_evt(in->device_key_code, in->device_key_type) == MMI_TRUE) &&
        (search_key_data(get_mmi_key_code(in->device_key_code)) == -1))
    {
        for (i = 0; i < 4; i++)
        {
            out[i].device_key_code = in->device_key_code;
            out[i].device_key_type = type[i];
            if (type[i] == in->device_key_type)
            {
                out[i].is_clear = MMI_FALSE;
            }
            else
            { 
                out[i].is_clear = MMI_TRUE;
            }    
        }
        *out_len = 4;
    }
    else
    {
        out[0] = *in;
        *out_len = 1;
    }    
}


/*****************************************************************************
* FUNCTION
*  is_valid_mmi_key_event
* DESCRIPTION
*  This function is used to judge if the MMI key event is valid key event
*  It is only used to check the return value of get_mmi_key_events
*
*  [UT function]:ut_is_valid_mmi_key_event
* PARAMETERS
*  key_code    : [IN]  mmi key code
*  key_type    : [IN]  mmi key type
* RETURNS
*  MMI_TRUE if valid mmi key event
*****************************************************************************/
static MMI_BOOL is_valid_mmi_key_event(S16 mmi_key_code, S16 mmi_key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_key_code != KEY_INVALID) && 
        (mmi_key_type >= KEY_EVENT_DOWN && mmi_key_type < MAX_KEY_TYPE))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  is_legal_key_type
 * DESCRIPTION
 *  This function is used to check if the current mmi key type of the specific key
 *  is legal or not, according to its previous mmi key type in framework key event level
 *  or application key event level. If the check is ok we will update active key cntx
 *  The basic checking logic is:
 *  Framework level - 2step key
 *        [current key type]        [possible pre key type]
 *        KEY_HALF_PRESS_DOWN       KEY_EVENT_UP
 *        KEY_FULL_PRESS_DOWN       KEY_HALF_PRESS_DOWN
 *        KEY_LONG_PRESS            KEY_FULL_PRESS_DOWN
 *        KEY_REPEAT                KEY_REPEAT or KEY_LONG_PRESS
 *        KEY_EVENT_UP              KEY_HALF_PRESS_DOWN, KEY_FULL_PRESS_DOWN, KEY_LONG_PRESS, KEY_REPEAT
 *
 *  Framework level - non - 2step key
 *        [current key type]        [possible pre key type]
 *        KEY_EVENT_DOWN            KEY_EVENT_UP
 *        KEY_LONG_PRESS            KEY_EVENT_DOWN
 *        KEY_REPEAT                KEY_REPEAT or KEY_LONG_PRESS
 *        KEY_EVENT_UP              KEY_EVENT_DOWN KEY_LONG_PRESS, KEY_REPEAT
 *  [UT function]:ut_is_legal_key_type
 *
 * PARAMETERS
 *  curr_mmi_key_type     :[IN]  curr_mmi_key_type
 *  pre_mmi_key_type      :[IN]  pre_mmi_key_type
 *  cat                   :[IN]  TWO_STEP_KEY or NON_TWO_STEP_KEY
 * RETURNS
 *  MMI_TRUE if legal mmi key type input or MMI_FALSE
 *****************************************************************************/
static MMI_BOOL is_legal_key_type(S16 curr_mmi_key_type, S16 pre_mmi_key_type, U8 cat)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < ARRAYSIZE(g_key_type_trans); i++)
    {
        if (GET_CAT(g_key_type_trans[i]) & cat)
        {
            if (curr_mmi_key_type == GET_CUR_KEY_TYPE(g_key_type_trans[i]) &&
                pre_mmi_key_type == GET_PRE_KEY_TYPE(g_key_type_trans[i]))
            {
                return MMI_TRUE;
            }
        }
    }
    return MMI_FALSE;
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + The following function is the operation for key code mapping table:
 +    1.get_mmi_key_code
 +    2.get_device_key_code
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

 /*****************************************************************************
 * FUNCTION
 *  get_mmi_key_code
 * DESCRIPTION
 *  This function is used to get the mmi key code that correspond to device_key_code 
 *  in g_mmi_frm_key_mapp_table.
 *  [Attention point]:
 *      1. if device_key_code is not in mapping table, KEY_INVALID will be got.
 *  [UT function]: ut_get_mmi_key_code
 *
 * PARAMETERS
 *  device_key_code     :[IN] device key code
 * RETURNS
 *  mmi key code
 *****************************************************************************/
static S16 get_mmi_key_code(U8 device_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < ARRAYSIZE(g_key_code_map); i++)
    {
        if (device_key_code == g_key_code_map[i].device_key_code)
        {
            return g_key_code_map[i].mmi_key_code;
        }
    }
    return KEY_INVALID;
}


/*****************************************************************************
 * FUNCTION
 *  get_device_key_code
 * DESCRIPTION
 *  This function is used to get device key code by mmi key code from key map table
 *  [Attention point]:
 *     1. if the mmi key code is not in the mapping table, DEVICE_KEY_NONE will be got
 *
 *  [UT function]: ut_get_device_key_code
 * PARAMETERS
 *  mmi_key_code       :[IN]  mmi key code
 *
 * RETURNS
 *  device key code
 *****************************************************************************/
static U8 get_device_key_code(U8 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < ARRAYSIZE(g_key_code_map); i++)
    {
        if (mmi_key_code == g_key_code_map[i].mmi_key_code)
        {
            return g_key_code_map[i].device_key_code;
        }
    }
    return DEVICE_KEY_NONE;
}


/*****************************************************************************
* FUNCTION
*  write_look_ahead_buffer
* DESCRIPTION
*  This function is used to write device key events to look ahead buffer
*  
*
*  [UT function]: ut_write_look_ahead_buffer
* PARAMETERS
*  dev_evt_p       :[IN] device key event 
*
* RETURNS
*  MMI_TRUE if write a device key event to look ahead buffer successfully
*****************************************************************************/
static MMI_BOOL write_look_ahead_buffer(dev_key_evt_struct *dev_evt_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_key_cntx.num_look_ahead == LOOK_AHEAD_BUF_LEN)
    {
#ifndef __MMI_FRM_KEY_EVENT_UT__
        MMI_ASSERT(0);
#endif
        return MMI_FALSE;
    }
    memcpy(&g_key_cntx.look_ahead[g_key_cntx.w_look_ahead],
        dev_evt_p,
        sizeof(dev_key_evt_struct));
    ++g_key_cntx.w_look_ahead;
    g_key_cntx.w_look_ahead %= LOOK_AHEAD_BUF_LEN;
    g_key_cntx.num_look_ahead++;
    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  read_look_ahead_buffer
* DESCRIPTION
*  This function is used to get device key events from look ahead buffer
*  
*
*  [UT function]: ut_read_look_ahead_buffer
* PARAMETERS
*  dev_evt_p       :[OUT] device key event 
*
* RETURNS
*  MMI_TRUE if get a device key event
*****************************************************************************/
static MMI_BOOL read_look_ahead_buffer(dev_key_evt_struct *dev_evt_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_key_cntx.num_look_ahead == 0)
    {
        return MMI_FALSE;
    }
    memcpy(dev_evt_p, 
        &g_key_cntx.look_ahead[g_key_cntx.r_look_ahead],
        sizeof(dev_key_evt_struct));
    ++g_key_cntx.r_look_ahead;
    g_key_cntx.r_look_ahead %= LOOK_AHEAD_BUF_LEN;
    g_key_cntx.num_look_ahead--;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  is_power_off_key_evt
 * DESCRIPTION
 *  This function is used to judge the key event is used to power off or not
 *
 *
 * PARAMETERS
 *  dev_key_code       : [IN] device key event
 *  dev_key_type       : [IN] device key type
 *   [UT function]: ut_is_power_off_evt
 * RETURNS
 *  MMI_TRUE if this event is used to power off the handset
 *****************************************************************************/
static MMI_BOOL is_power_off_key_evt(U8 dev_key_code, U8 dev_key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL r = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dev_key_type == DRV_WM_KEYLONGPRESS)
    {
        if (dev_key_code == DEVICE_KEY_END)
        {
            if( MMI_FALSE == mmi_frm_kbd_is_key_supported(KEY_POWER))  
            {    
                r = MMI_TRUE;
            }
        }
        else if (dev_key_code == DEVICE_KEY_POWER)
        {
            r = MMI_TRUE;
        }   
    }
    return r;
}



/*****************************************************************************
 * FUNCTION
 *  is_mmi_power_off_key_evt
 * DESCRIPTION
 *  This function is used to judge the key event is used to power off or not
 *  from MMI's view
 *
 * PARAMETERS
 *  mmi_key_code       : [IN] mmi key code
 *  mmi_key_type       : [IN] mmi key type
 *  
 * RETURNS
 *  MMI_TRUE if this event is used to power off the handset
 *****************************************************************************/
static MMI_BOOL is_mmi_power_off_key_evt(U8 mmi_key_code, U8 mmi_key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL r = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_key_type == KEY_LONG_PRESS)
    {
        if (mmi_key_code == KEY_END)
        {
            if( MMI_FALSE == mmi_frm_kbd_is_key_supported(KEY_POWER))  
            {    
                r = MMI_TRUE;
            }
        }
        else if (mmi_key_code  == KEY_POWER)
        {
            r = MMI_TRUE;
        }   
    }
    return r;
}


/*****************************************************************************
 * FUNCTION
 *  is_detection_evt
 * DESCRIPTION
 *  This function is used to check if the device key event is detection event
 *  or not
 * PARAMETERS
 *  device_key_type     : [IN] device key type
 *
 * RETURNS
 *  MMI_TRUE if detection key event comming
 *****************************************************************************/
static MMI_BOOL is_detection_evt(U8 device_key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (device_key_type == DRV_WM_ENABLE_TWOKEY_DETECTION ||
        device_key_type == DRV_WM_ENABLE_THREEKEY_DETECTION ||
        device_key_type == DRV_WM_DISABLE_MULTIKEY_DETECTION)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  is_need_write_back
 * DESCRIPTION
 *  This function is used to check if the device key event should be write
 *  back to look ahead buffer when clear key events
 *  
 *  Events need to be write back
 *     1. UP event if the key is exist in key data buffer
 *     2. END key's longpress
 *  Only on instance can be exist in the write back event set.
 *
 *  [UT function]: ut_is_need_write_back
 * PARAMETERS
 *  dev_p       :[IN] device key event
 *  buf         :[IN] temp buffer which store write back events
 *  len         :[IN] temp buffer len
 *
 * RETURNS
 *  MMI_TRUE if this event should be write back to look ahead buffer
 *****************************************************************************/
static MMI_BOOL is_need_write_back(dev_key_evt_struct *dev_p, dev_key_evt_struct *buf, U8 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL r = MMI_FALSE;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_detection_evt(dev_p->device_key_type) == MMI_TRUE)
    {
        return MMI_TRUE;
    }
    if ((dev_p->device_key_type == DRV_WM_KEYRELEASE) &&
        ((search_key_data(get_mmi_key_code(dev_p->device_key_code)) != -1) 
          && (get_key_state(get_mmi_key_code(dev_p->device_key_code)) != KEY_EVENT_UP)))
    {
        r = MMI_TRUE;
    }
    else if (is_power_off_key_evt(dev_p->device_key_code, dev_p->device_key_type) == MMI_TRUE)
    {
        r = MMI_TRUE;    
    }

    if (r == MMI_TRUE)
    {
        for (i = 0; i < len; i++)
        {
            if ((dev_p->device_key_code == buf[i].device_key_code) &&
                (dev_p->device_key_type == buf[i].device_key_type))
            {
                r = MMI_FALSE;
                break;
            }
        }
    }
    return r;
}


/*****************************************************************************
 * FUNCTION
 *  is_need_merge_detection_evt
 * DESCRIPTION
 *  This function is used to merge detection event when clear key events
 *  Remark:
 *    When mmi_frm_clear_key_events
 *    we will merge detection event
 *    eg. 1key_detect 2 key detect will be merge to 2 key detect
 *  
 * PARAMETERS
 *  pre       : [IN]  previours dev key event that will be write to look ahead buffer
 *  curr      : [IN]  current dev key event that will be write to look ahead buffer
 *
 * RETURNS
 *  MMI_TRUE if need merge detection event
 *****************************************************************************/
static MMI_BOOL is_need_merge_detection_evt(dev_key_evt_struct *pre, dev_key_evt_struct *curr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((pre == NULL) ||
		(is_detection_evt(pre->device_key_type) == MMI_FALSE) ||
		(is_power_off_key_evt(curr->device_key_code, curr->device_key_type)) ||
	/* 
	 *  driver will not send power key's release when receive detection event
	 *  because it need make sure the power key's long press can be received by MMI
	 */
		(((curr->device_key_code == DEVICE_KEY_END) || (curr->device_key_code == DEVICE_KEY_POWER)) && curr->device_key_type == DRV_WM_KEYRELEASE))
    {
        return MMI_FALSE;
    }
    else
    {
        MMI_ASSERT(curr != NULL);
		MMI_ASSERT(is_detection_evt(curr->device_key_type));
        return MMI_TRUE;
    }    
}



/*****************************************************************************
 * FUNCTION
 *  get_dev_key_evt
 * DESCRIPTION
 *  This function is used to get device key events from look ahead buffer or key buffer.
 *  
 *
 *  [UT function]: ut_get_dev_key_evt
 * PARAMETERS
 *  dev_evt_p       :[IN]  mmi key code
 *
 * RETURNS
 *  MMI_TRUE if get a device key event
 *****************************************************************************/
static MMI_BOOL get_dev_key_evt(dev_key_evt_struct *dev_evt_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_FRM_KEY_EVENT_UT__
    kbd_data k;
#endif
    U32 time_stamp = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (read_look_ahead_buffer(dev_evt_p) == MMI_TRUE)
    {
        return MMI_TRUE;
    }
#ifndef __MMI_FRM_KEY_EVENT_UT__
    else if (get_key_evt_func[g_key_cntx.l4_keypad_mode]&& ((*get_key_evt_func[g_key_cntx.l4_keypad_mode])(&k) == MMI_TRUE))
    {
        dev_evt_p->device_key_code = k.Keydata[0];
        dev_evt_p->device_key_type = k.Keyevent;
        dev_evt_p->is_clear = MMI_FALSE;
    #ifdef __TC01__
/* under construction !*/
    #endif
        report_key_evt(k.Keydata[0], (U8)k.Keyevent, time_stamp);
        return MMI_TRUE;
    }
#endif    
    return MMI_FALSE;
}



/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + key code convert functions:
 +  1.get_rotated_mmi_key_code
 +
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*****************************************************************************
 * FUNCTION
 *  get_rotated_mmi_key_code
 * DESCRIPTION
 *  This function is used to get rotated mmi key code
 *  [UT function]: ut_get_rotated_mmi_key_code
 * PARAMETERS
 *  mmi_key_code  :[IN] mmi key code
 *
 * RETURNS
 *  rotate mmi key code
 *****************************************************************************/
#ifdef __MMI_SCREEN_ROTATE__ 
static S16 get_rotated_mmi_key_code(S16 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 j;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < ARRAYSIZE(g_kpd_rot_data); i++)
    {
        if (g_kpd_rot_data[i].rot_degree == mmi_frm_get_screen_rotate())
        {
            for (j = 0; j < DIR_KEY_NUM; j++)
            {
                if (g_dir_key[j] == mmi_key_code)
                {
                    return (S16)g_dir_key[(j + g_kpd_rot_data[i].step + DIR_KEY_NUM) % DIR_KEY_NUM];
                }
            }
        }
    }
    return mmi_key_code;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_key_code_convert
 * DESCRIPTION
 *  This function is used to do mmi key code conversion
 *
 * PARAMETERS
 *  mmi_key_code     :[IN] mmi key code
 *
 * RETURNS
 *  mmi key code
 *****************************************************************************/
static S16 mmi_key_code_convert(S16 mmi_key_code, U8 dev_key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 convert_key_code = mmi_key_code;
    S32 i;
    S32 index;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dev_key_type == DRV_WM_KEYPRESS)
    {
        for (i = 0; i < ARRAYSIZE(g_key_code_cvt_tbl); i++)
        {
            if (g_key_code_cvt_tbl[i] != NULL)
            { 
                convert_key_code = (* g_key_code_cvt_tbl[i])(mmi_key_code);
                if (convert_key_code != mmi_key_code)
                {
                    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_CONVERT_KEY_CODE, mmi_key_code, convert_key_code);
                    break;
                }
            }    
        }
    }
    else
    {
        if ((index = search_key_data(mmi_key_code)) != -1)
        {
            key_data_struct data;
            get_key_data(&data, (U8)index);
            convert_key_code = data.cvt_code;
        }
    }
    return  convert_key_code;
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + get key handler functions
 +
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


/*****************************************************************************
 * FUNCTION
 *  get_any_key_handler
 * DESCRIPTION
 *  This function is used to get any key handler.
 *    [UT]: ut_get_any_key_handler
 * PARAMETERS
 *  mmi_key_code  :[IN] mmi key code
 *  mmi_key_type  :[IN] mmi key type
 *
 * RETURNS
 *  key handler pointer
 *****************************************************************************/
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__ 
static FuncPtr get_any_key_handler(S16 mmi_key_code, S16 mmi_key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr currFuncPtr = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_key_code >= MAX_KEYS)
    {
        currFuncPtr = anyKeyFuncPtrs[mmi_key_type];
        MMI_TRACE(PLUTO_FW_TRC_KEY, TRC_MMI_FRM_KEY_GET_ANY_KEY_HDLR, mmi_key_code, mmi_key_type, currFuncPtr);
    }
    return currFuncPtr;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  get_default_key_handler
 * DESCRIPTION
 *  This function is used to default key handler
 *   [UT_function]: ut_get_default_key_handler
 * PARAMETERS
 *  mmi_key_code  :[IN] mmi key code
 *  mmi_key_type  :[IN] mmi key type
 *
 * RETURNS
 *  key handler pointer
 *****************************************************************************/
static FuncPtr get_default_key_handler(S16 mmi_key_code, S16 mmi_key_type) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (mmi_key_code < MAX_KEYS)
    {
    #ifdef __KBD_2STEP_KEY_SUPPORT__
        if (is_2step_key(mmi_key_code) && (mmi_key_type == KEY_HALF_PRESS_DOWN || mmi_key_type == KEY_HALF_PRESS_UP))
        {
            return _2step_key_extra_hdlr[mmi_key_type - MAX_NON_2STEP_KEY_TYPE];
        }
        else
    #endif
        {
            
            return currKeyFuncPtrs[mmi_key_code][mmi_key_type];
        }
    }
    else
    {
        return NULL;
    }
}




/*****************************************************************************
 * FUNCTION
 *  get_key_handler
 * DESCRIPTION
 *  This function is used to get the final key handler
 * PARAMETERS
 *  mmi_key_code  :[IN] mmi key code
 *  mmi_key_type  :[IN] mmi key type
 *    [UT_function]: ut_get_key_handler
 * RETURNS
 *  key handler pointer
 *****************************************************************************/ 
static FuncPtr get_key_handler(S16 mmi_key_code, S16 mmi_key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr currFuncPtr = NULL;
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < ARRAYSIZE(g_key_handler); i++)
    {
        if (g_key_handler[i] && ((currFuncPtr = (* g_key_handler[i])(mmi_key_code, mmi_key_type)) != NULL))
        {
            break;
        }
    }
    return currFuncPtr;
}


/*****************************************************************************
 * FUNCTION
 *  update_key_proc_data
 * DESCRIPTION
 *  This function is used to copy the SET_SPACE to the INVOKE_SPACE of key proc
 *  when keypad from free to busy.
 *
 *  when send key event in touch procedure, we need force update to update key proc
 *  
 *  [UT_function] ut_update_key_proc_data
 * PARAMETERS
 *  key_data_p      : [IN] key data
 *  force_update    : [IN] force copy or not
 * RETURNS
 *  void
 *****************************************************************************/
static void update_key_proc_data(S16 mmi_key_type, MMI_BOOL force_update)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_key_type == KEY_EVENT_DOWN || mmi_key_type == KEY_HALF_PRESS_DOWN || force_update == MMI_TRUE)
    {
        memcpy(g_key_cntx.routing_layer[LAYER_INVOKE_SPACE], 
            g_key_cntx.routing_layer[LAYER_SET_SPACE], 
            sizeof(mmi_key_routing_layer_struct) * MMI_KEY_ROUTING_TOTAL);
        g_key_cntx.wgui_layer_num[LAYER_INVOKE_SPACE] = g_key_cntx.wgui_layer_num[LAYER_SET_SPACE];
        g_key_cntx.group_id[LAYER_INVOKE_SPACE] = g_key_cntx.group_id[LAYER_SET_SPACE];
        g_key_cntx.scrn_id[LAYER_INVOKE_SPACE] = g_key_cntx.scrn_id[LAYER_SET_SPACE];
        if (force_update == MMI_FALSE)
        {
            g_key_cntx.is_screen_switch = MMI_FALSE;
            g_key_cntx.is_send_to_new_scrn = MMI_FALSE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  pre_update_end_call_state
 * DESCRIPTION
 *  This function is used to set the state of end call procedure
 * 
 * PARAMETERS
 *  data   : [IN] key data
 * RETURNS
 *  void
 *****************************************************************************/
static void pre_update_end_call_state(key_data_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (data->cvt_code == KEY_END &&
		data->mmi_key_type == KEY_EVENT_DOWN &&
		IS_IN_CALL())
	{
		g_key_cntx.is_in_end_call_proc = MMI_TRUE;
	}
}


/*****************************************************************************
 * FUNCTION
 *  post_update_end_call_state
 * DESCRIPTION
 *  This function is used to reset the state of end call procedure
 * 
 * PARAMETERS
 *  data   : [IN] key data
 * RETURNS
 *  void
 *****************************************************************************/
static void post_update_end_call_state(key_data_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (data->cvt_code == KEY_END && data->mmi_key_type == KEY_EVENT_UP)
	{
		g_key_cntx.is_in_end_call_proc = MMI_FALSE;
	}
}


/*****************************************************************************
 * FUNCTION
 *  is_in_end_call_procedure
 * DESCRIPTION
 *  This function is used to check if in end call procedure
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if in end call procedure
 *****************************************************************************/
static MMI_BOOL is_in_end_call_procedure(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return g_key_cntx.is_in_end_call_proc;
}




/*****************************************************************************
 * FUNCTION
 *  is_need_report_to_l4
 * DESCRIPTION
 *  This function is used to judge if we need to report key event to L4.
 *
 * PARAMETERS
 *  dev_key_type       : [IN] device key type
 * RETURNS
 *  MMI_TRUE if need to report
 *****************************************************************************/
static MMI_BOOL is_need_report_to_l4(U8 dev_key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dev_key_type == DRV_WM_KEYPRESS || dev_key_type == DRV_WM_KEYRELEASE)
    {
        if ((g_key_cntx.key_event_report_mode == KEY_EVT_REPORT_HW_AT) || 
            (g_key_cntx.key_event_report_mode == KEY_EVT_REPORT_HW_ONLY) && (g_key_cntx.l4_keypad_mode == L4_KEYPAD_HARDWARE))
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  report_key_evt
 * DESCRIPTION
 *  This function is used to report key event to L4C
 *
 * PARAMETERS
 *  dev_key_code       : [IN] device key code
 *  dev_key_type       : [IN] device key type
 * RETURNS
 *  void
 *****************************************************************************/
static void report_key_evt(U8 dev_key_code, U8 dev_key_type, U32 time_stamp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_at_keypad_event_output_req_struct *local_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == is_need_report_to_l4(dev_key_type))
    {
        local_data = (mmi_at_keypad_event_output_req_struct*) OslConstructDataPtr(sizeof(mmi_at_keypad_event_output_req_struct));
        local_data->keypad_status = dev_key_type;
        local_data->keypad_code = dev_key_code;
        mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_AT_KEYPAD_EVENT_OUTPUT_REQ, (oslParaType*) local_data, NULL);     
    }
#ifdef __TC01__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif              
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + The following part is the deprecated API, in order to keep the old API work for Vendor
 +
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void ExecuteCurrKeyHandler(S16 keyCode, S16 keyType)
{
    mmi_frm_exec_key_handler(keyCode, keyType);
}
void GetkeyInfo(U16 *keyCode, U16 *keyType)
{
    mmi_frm_get_key_info(keyCode, keyType);
}
FuncPtr GetKeyHandler(U16 keyCode, U16 keyType)
{
    return mmi_frm_get_key_handler(keyCode, keyType);
}
 
void SetGroupKeyHandler(FuncPtr funcPtr, PU16 keyCodes, U8 len, U16 keyType)
{
    mmi_frm_set_group_key_handler(funcPtr, keyCodes, len, keyType);
}
void ClearKeyHandler(U16 keyCode, U16 keyType)
{
    mmi_frm_clear_key_handler(keyCode, keyType);
}
void PowerAndEndKeyHandler(void)
{
    mmi_frm_set_power_end_key_handler();
}
void ClearKeyEvents(void)
{
    mmi_frm_clear_key_events();
}
void SetKeyHandler(FuncPtr funcPtr, U16 keyCode, U16 keyType)
{
    mmi_frm_set_key_handler(funcPtr, keyCode, keyType);
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + The following part is the unit test of key event handler
 +
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#ifdef __MMI_FRM_KEY_EVENT_UT__

static MMI_BOOL key_data_cmp(key_data_struct *p, key_data_struct *q);
static void save_key_data(key_data_struct *buf_p, U8 *len_p);
static void restore_key_data(key_data_struct *buf_p, U8 *len_p);
static void set_key_data(key_data_struct *data,
				  	U8 code,
                    U8 cvt_code,
				  	U8 type, 
				  	MMI_BOOL is_2step,
				  	MMI_BOOL is_combo,
				  	MMI_BOOL is_clear);

/*****************************************************************************
 * TEST ITEM
 *  MMI key code convert
 * TEST POINT
 *  1. Keep effect:  KEY_A => KEY_B when KEY_DOWN, KEY_A => KEY_B until keypad
 *   is released
 *  2. Stop condition: convertion function return different key code
 *
 *****************************************************************************/


/* This variable is used to enable key code convert */
MMI_BOOL g_convert = MMI_FALSE;

/* key code convert test function 1*/
static S16 key_code_convert_test1(S16 mmi_key_code)
{
    if (g_convert == MMI_TRUE)
    {
        if (mmi_key_code == KEY_UP_ARROW)    return KEY_LEFT_ARROW;
        if (mmi_key_code == KEY_DOWN_ARROW)  return KEY_RIGHT_ARROW;
        if (mmi_key_code == KEY_LEFT_ARROW)  return KEY_DOWN_ARROW;
        if (mmi_key_code == KEY_RIGHT_ARROW) return KEY_UP_ARROW;
    }
    return mmi_key_code;
}

/* key code convert test function 2*/
static S16 key_code_convert_test2(S16 mmi_key_code)
{
    return KEY_INVALID;
}

/* test key code convert */
mmi_ret ut_mmi_key_code_convert(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    key_data_struct buf[MAX_DECT_KEY_NUM];
    U8 len;
    key_data_struct data;
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    save_key_data(buf, &len);
    init_key_data_buf();
    MMI_ASSERT(mmi_key_code_convert(KEY_UP_ARROW, DRV_WM_KEYPRESS) == KEY_INVALID);
    g_convert = MMI_TRUE;
    MMI_ASSERT(mmi_key_code_convert(KEY_UP_ARROW, DRV_WM_KEYPRESS) == KEY_LEFT_ARROW);
    data.mmi_key_code = KEY_UP_ARROW;
    data.cvt_code = KEY_LEFT_ARROW;
    insert_key_data(&data);
    g_convert = MMI_FALSE;
    MMI_ASSERT(mmi_key_code_convert(KEY_UP_ARROW, DRV_WM_KEYLONGPRESS) == KEY_LEFT_ARROW);
    MMI_ASSERT(mmi_key_code_convert(KEY_UP_ARROW, DRV_WM_KEYREPEATED) == KEY_LEFT_ARROW);
    MMI_ASSERT(mmi_key_code_convert(KEY_UP_ARROW, DRV_WM_KEYRELEASE) == KEY_LEFT_ARROW);
    remove_key_data(KEY_UP_ARROW);
    MMI_ASSERT(mmi_key_code_convert(KEY_UP_ARROW, DRV_WM_KEYPRESS) == KEY_INVALID);
    restore_key_data(buf, &len);
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test mmi_key_code_convert PASS");
    return MMI_RET_OK;
}

void test_handler(void)
{
}
MMI_BOOL g_test_function = MMI_FALSE;
static FuncPtr test_key_handler(S16 key_code, S16 key_type)
{
    
    if (g_test_function && key_code == KEY_1)
    {
        FuncPtr f = test_handler;
        return f;
    }
    return NULL;
}


mmi_ret ut_get_key_handler(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_test_function = MMI_TRUE;
    mmi_frm_set_key_handler((FuncPtr)0x123456, KEY_1, KEY_EVENT_DOWN);
    mmi_frm_set_key_handler((FuncPtr)0x789456, KEY_0, KEY_EVENT_DOWN);
    MMI_ASSERT(get_key_handler(KEY_1, KEY_EVENT_DOWN) == (FuncPtr)test_handler);
    MMI_ASSERT(get_key_handler(KEY_0, KEY_EVENT_DOWN) == (FuncPtr)0x789456);
    g_test_function = MMI_FALSE;
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test get_key_handler PASS");
    return MMI_RET_OK;
}






mmi_ret ut_get_default_key_handler(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 key_code;
    U8 key_type;
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    for (key_code = MAX_KEYS; key_code < MAX_QWERTY_KEYS; key_code++)
    {
        for (key_type = KEY_EVENT_DOWN; key_type < MAX_NON_2STEP_KEY_TYPE; key_type++)
        {
            MMI_ASSERT(get_default_key_handler(key_code, key_type) == NULL);
        }
    }
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test get_default_key_handler PASS");
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ut_mmi_frm_init_key_event
 * DESCRIPTION
 * <test case description> test init state of key cntx
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    
 * <Test Case Content> init state of key cntx
 * <Test Case Number>
 * <Scenario>
 *    case1:
 * <Expected Result>
 *    case1:
 *
 * </test case description>

 *
 * PARAMETERS
 *  pare         :[IN] reserved
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret ut_mmi_frm_init_key_event(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    key_cntx_struct key_cntx;
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    key_cntx = g_key_cntx;
    mmi_frm_init_key_event();

    /* keypad pointer init state check */
    //MMI_ASSERT(get_key_evt_func[g_key_cntx.l4_keypad_mode] == NULL);

    /* keypad status init state check */
    MMI_ASSERT(GET_KPD_MODE(g_key_cntx.keypad_status) == KEYPAD_1KEY_NUMBER);
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__   
    MMI_ASSERT(GET_KEY_DET_MODE(g_key_cntx.keypad_status) == DCL_kbd_2_keys_det_mode);
#else
    MMI_ASSERT(GET_KEY_DET_MODE(g_key_cntx.keypad_status) == DCL_kbd_1_key_det_mode);
#endif
    MMI_ASSERT(IsBitReset(g_key_cntx.keypad_status, KPD_SUSPEND_FLAG));

    /* key data buffer init state check */
    for (i = 0; i < MAX_DECT_KEY_NUM; i++)
    {
        MMI_ASSERT(g_key_cntx.buffer[i].mmi_key_code == KEY_INVALID);
        MMI_ASSERT(g_key_cntx.buffer[i].cvt_code == KEY_INVALID);
        MMI_ASSERT(g_key_cntx.buffer[i].mmi_key_type == KEY_EVENT_UP);
        MMI_ASSERT(g_key_cntx.buffer[i].is_clear == MMI_FALSE);
        MMI_ASSERT(g_key_cntx.buffer[i].is_combo == MMI_FALSE);
        MMI_ASSERT(g_key_cntx.buffer[i].is_2step == MMI_FALSE);
    }
    MMI_ASSERT(g_key_cntx.buf_len == 0);

    /* 2 step key init state check */
#ifdef __KBD_2STEP_KEY_SUPPORT__
#ifdef __MTK_TARGET__
    MMI_ASSERT(g_key_cntx._2step_key.mmi_key_code == KEY_CAMERA);
#endif
    MMI_ASSERT(g_key_cntx._2step_key.state == FULL_UP);
#endif /* __KBD_2STEP_KEY_SUPPORT__ */

    /* pre/post handler related check */
    MMI_ASSERT(g_key_cntx.kbd_pre_func == NULL);
    MMI_ASSERT(g_key_cntx.kbd_post_func == NULL);

    /* key info related variable check */
    MMI_ASSERT(g_key_cntx.curr_key_code == KEY_INVALID);
    MMI_ASSERT(g_key_cntx.curr_key_type == KEY_EVENT_UP);

    /* look ahead buffer related check */    
    MMI_ASSERT(g_key_cntx.r_look_ahead == 0);
	MMI_ASSERT(g_key_cntx.w_look_ahead == 0);
    MMI_ASSERT(g_key_cntx.num_look_ahead == 0);

    /* key proc related check */
    MMI_ASSERT(g_key_cntx.wgui_layer_num[LAYER_SET_SPACE] == 0);
    MMI_ASSERT(g_key_cntx.wgui_layer_num[LAYER_INVOKE_SPACE] == 0);
    for (i = 0; i < MMI_KEY_ROUTING_TOTAL; i++)
    {
        if (i == MMI_FRM_TRANS_KEY_SYS)
		{
			MMI_ASSERT(g_key_cntx.routing_layer[0][i].key_proc == mmi_sys_key_proc);
			MMI_ASSERT(g_key_cntx.routing_layer[0][i].user_data == NULL);
		}
		else if(i == MMI_KEY_ROUTING_KEY_HDLR)
		{
			MMI_ASSERT(g_key_cntx.routing_layer[0][i].key_proc == mmi_key_hdlr_proc);
			MMI_ASSERT(g_key_cntx.routing_layer[0][i].user_data == NULL);
		}
		else
		{
			for (j = 0; j < LAYER_SPACE_TOTAL; j++)
			{
				MMI_ASSERT(g_key_cntx.routing_layer[j][i].key_proc == NULL);
				MMI_ASSERT(g_key_cntx.routing_layer[j][i].user_data == NULL);
			}
		}
    }

    /* Misc */
    MMI_ASSERT(g_key_cntx.is_key_event == MMI_TRUE);
    MMI_ASSERT(g_key_cntx.is_screen_switch == MMI_FALSE);
	MMI_ASSERT(g_key_cntx.is_send_to_new_scrn == MMI_FALSE);
    g_key_cntx = key_cntx;
	kal_prompt_trace(MOD_MMI, "[UT_KEY] Init state of key event test PASS");
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ut_mmi_frm_key_event_screen_switch_action
 * DESCRIPTION
 * <test case description> test state change of key cntx when screen switch
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    
 * <Test Case Content> state change of key cntx when screen switch
 * <Test Case Number>
 * <Scenario>
 *    case1:
 * <Expected Result>
 *    case1:
 *
 * </test case description>

 *
 * PARAMETERS
 *  pare         :[IN] reserved
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret ut_mmi_frm_key_event_screen_switch_action(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    key_cntx_struct key_cntx;
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    key_cntx = g_key_cntx;
    mmi_frm_key_event_screen_switch_action();

    /* key pad mode should be 1key number */
    MMI_ASSERT(GET_KPD_MODE(g_key_cntx.keypad_status) == KEYPAD_1KEY_NUMBER);

    /* screen switch flag should updated */
    MMI_ASSERT(g_key_cntx.is_screen_switch == MMI_TRUE);

    /* key proc of set space should be cleard */
    MMI_ASSERT(g_key_cntx.wgui_layer_num[LAYER_SET_SPACE] == 0);
    for (i = MMI_KEY_ROUTING_SCR; i < MMI_KEY_ROUTING_TOTAL; i++)
    {
        if (i != MMI_KEY_ROUTING_SYS && i != MMI_KEY_ROUTING_KEY_HDLR)
		{
			MMI_ASSERT(g_key_cntx.routing_layer[LAYER_SET_SPACE][i].key_proc == NULL);
			MMI_ASSERT(g_key_cntx.routing_layer[LAYER_SET_SPACE][i].user_data == NULL);
		}
    }    
    g_key_cntx = key_cntx;
	kal_prompt_trace(MOD_MMI, "[UT_KEY] key screen switch action test PASS");
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ut_mmi_frm_kbd_is_key_supported
 * DESCRIPTION
 * <test case description> test the API mmi_frm_kbd_is_key_supported
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    
 * <Test Case Content> mmi_frm_kbd_is_key_supported
 * <Test Case Number>
 * <Scenario>
 *    case1:
 * <Expected Result>
 *    case1:
 *
 * </test case description>

 *
 * PARAMETERS
 *  pare         :[IN] reserved
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret ut_mmi_frm_kbd_is_key_supported(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if !defined(__MTK_TARGET__)
    MMI_ASSERT(mmi_frm_kbd_is_key_supported(KEY_POWER) == MMI_FALSE);
#endif /* __MTK_TARGET__ */

#if defined(AMBER38_DEMO_BB)
    MMI_ASSERT(mmi_frm_kbd_is_key_supported(KEY_CAMERA) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_kbd_is_key_supported(KEY_VOL_DOWN) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_kbd_is_key_supported(KEY_VOL_UP) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_kbd_is_key_supported(KEY_DOWN_ARROW) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_kbd_is_key_supported(KEY_UP_ARROW) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_kbd_is_key_supported(KEY_RSK) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_kbd_is_key_supported(KEY_LSK) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_kbd_is_key_supported(KEY_CSK) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_kbd_is_key_supported(KEY_END) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_kbd_is_key_supported(KEY_SEND) == MMI_TRUE);
#endif
#if defined(TECHFAITH68V3_DEMO_BB)
    #if defined(__MTK_TARGET__)
    MMI_ASSERT(mmi_frm_kbd_is_key_supported(KEY_POWER) == MMI_TRUE);
	#endif /* __MTK_TARGET__ */
    MMI_ASSERT(mmi_frm_kbd_is_key_supported(KEY_E) == MMI_TRUE);
    MMI_ASSERT(mmi_frm_kbd_is_key_supported(KEY_1) == MMI_TRUE);
#endif

#if defined(LIBRA35_DEMO_BB)
	MMI_ASSERT(mmi_frm_kbd_is_key_supported(KEY_1) == MMI_FALSE);
#endif
	kal_prompt_trace(MOD_MMI, "[UT_KEY] is key supported test PASS");
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ut_mmi_frm_get_key_info
 * DESCRIPTION
 * <test case description> test the API mmi_frm_get_key_info
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    
 * <Test Case Content> mmi_frm_get_key_info
 * <Test Case Number>
 * <Scenario>
 *    case1:
 * <Expected Result>
 *    case1:
 *
 * </test case description>

 *
 * PARAMETERS
 *  pare         :[IN] reserved
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret ut_mmi_frm_get_key_info(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 key_code = 0;
    U16 key_type = 0;
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    g_key_cntx.curr_key_code = 250;
    g_key_cntx.curr_key_type = 125;
    mmi_frm_get_key_info(&key_code, &key_type);
    MMI_ASSERT(key_code == 250);
    MMI_ASSERT(key_type == 125);
	kal_prompt_trace(MOD_MMI, "[UT_KEY] get key info test PASS");
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ut_mmi_frm_set_key_info
 * DESCRIPTION
 * <test case description> test the API mmi_frm_set_key_info
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    
 * <Test Case Content> mmi_frm_set_key_info
 * <Test Case Number>
 * <Scenario>
 *    case1:
 * <Expected Result>
 *    case1:
 *
 * </test case description>

 *
 * PARAMETERS
 *  pare         :[IN] reserved
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret ut_mmi_frm_set_key_info(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    g_key_cntx.curr_key_code = 0;
    g_key_cntx.curr_key_type = 0;
    mmi_frm_set_key_info(250, 250);
    MMI_ASSERT(g_key_cntx.curr_key_code == 250);
    MMI_ASSERT(g_key_cntx.curr_key_type == 250);
	kal_prompt_trace(MOD_MMI, "[UT_KEY] Set key info test Pass");
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ut_mmi_frm_get_key_handler
 * DESCRIPTION
 * <test case description> test the API mmi_frm_get_key_handler
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    
 * <Test Case Content> mmi_frm_get_key_handler
 * <Test Case Number>
 * <Scenario>
 *    case1:
 * <Expected Result>
 *    case1:
 *
 * </test case description>

 *
 * PARAMETERS
 *  pare         :[IN] reserved
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret ut_mmi_frm_get_key_handler(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 key_code;
    U8 key_type;
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    memset(currKeyFuncPtrs, 0xFA, sizeof(currKeyFuncPtrs));
#if defined(__KBD_2STEP_KEY_SUPPORT__) && defined(__MTK_TARGET__)
    _2step_key_extra_hdlr[0] = (FuncPtr)5050;
    _2step_key_extra_hdlr[1] = (FuncPtr)6060;
    MMI_ASSERT((void *)mmi_frm_get_key_handler(KEY_CAMERA, KEY_FULL_PRESS_DOWN) == (void *)5050);
    MMI_ASSERT((void *)mmi_frm_get_key_handler(KEY_CAMERA, KEY_HALF_PRESS_UP) == (void *)6060);
#endif /* __KBD_2STEP_KEY_SUPPORT__ */
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    for (key_code = KEY_A; key_code < MAX_QWERTY_KEYS; key_code++)
    {
        for (key_type = KEY_EVENT_DOWN; key_type < MAX_KEY_TYPE; key_type++)
        {
            MMI_ASSERT(mmi_frm_get_key_handler(key_code, key_type) == NULL);
        }
    }
#endif /* __MMI_QWERTY_KEYPAD_SUPPORT__ */
    for (key_code = KEY_0; key_code < MAX_KEYS; key_code++)
    {
        for (key_type = KEY_EVENT_DOWN; key_type < MAX_NON_2STEP_KEY_TYPE; key_type++)
        {
            MMI_ASSERT(mmi_frm_get_key_handler(key_code, key_type) == (void *)0xFAFAFAFA);
        }
    }
	kal_prompt_trace(MOD_MMI, "[UT_KEY] get key handler test Pass");
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ut_mmi_frm_set_key_handler
 * DESCRIPTION
 * <test case description> test the API mmi_frm_set_key_handler
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    
 * <Test Case Content> mmi_frm_set_key_handler
 * <Test Case Number>
 * <Scenario>
 *    case1:
 * <Expected Result>
 *    case1:
 *
 * </test case description>

 *
 * PARAMETERS
 *  pare         :[IN] reserved
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret ut_mmi_frm_set_key_handler(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 key_code;
    U8 key_type;
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    memset(currKeyFuncPtrs, 250, sizeof(currKeyFuncPtrs) / sizeof(currKeyFuncPtrs[0][0]));
#if defined(__KBD_2STEP_KEY_SUPPORT__) && defined(__MTK_TARGET__)
    _2step_key_extra_hdlr[0] = 0;
    _2step_key_extra_hdlr[1] = 0;
    mmi_frm_set_key_handler((FuncPtr)5050, KEY_CAMERA, KEY_FULL_PRESS_DOWN);
    mmi_frm_set_key_handler((FuncPtr)5050, KEY_CAMERA, KEY_HALF_PRESS_UP);
    MMI_ASSERT((void *)_2step_key_extra_hdlr[0] == (void *)5050);
    MMI_ASSERT((void *)_2step_key_extra_hdlr[1] == (void *)5050);
#endif /* __KBD_2STEP_KEY_SUPPORT__ */
    for (key_code = 0; key_code < MAX_KEYS; key_code++)
    {
        for (key_type = 0; key_type < MAX_NON_2STEP_KEY_TYPE; key_type++)
        {
            mmi_frm_set_key_handler((FuncPtr)250, key_code, key_type);
            MMI_ASSERT(currKeyFuncPtrs[key_code][key_type] == (FuncPtr)250);
        }
    }
#if defined(__SENDKEY2_SUPPORT__)
    currKeyFuncPtrs[KEY_SEND1][KEY_EVENT_DOWN] = 0;
    currKeyFuncPtrs[KEY_SEND2][KEY_EVENT_DOWN] = 0;
    currKeyFuncPtrs[KEY_SEND][KEY_EVENT_DOWN] = 0;
    mmi_frm_set_key_handler((FuncPtr)6543, KEY_SEND, KEY_EVENT_DOWN);
    MMI_ASSERT(currKeyFuncPtrs[KEY_SEND1][KEY_EVENT_DOWN] == (FuncPtr)6543);
    MMI_ASSERT(currKeyFuncPtrs[KEY_SEND2][KEY_EVENT_DOWN] == (FuncPtr)6543);
    MMI_ASSERT(currKeyFuncPtrs[KEY_SEND][KEY_EVENT_DOWN] == (FuncPtr)6543);
    currKeyFuncPtrs[KEY_SEND1][KEY_EVENT_DOWN] = 0;
    currKeyFuncPtrs[KEY_SEND2][KEY_EVENT_DOWN] = 0;
    currKeyFuncPtrs[KEY_SEND][KEY_EVENT_DOWN] = 0;
    mmi_frm_set_key_handler((FuncPtr)6543, KEY_SEND1, KEY_EVENT_DOWN);
    MMI_ASSERT(currKeyFuncPtrs[KEY_SEND1][KEY_EVENT_DOWN] == (FuncPtr)6543);
    MMI_ASSERT(currKeyFuncPtrs[KEY_SEND2][KEY_EVENT_DOWN] == NULL);
    MMI_ASSERT(currKeyFuncPtrs[KEY_SEND][KEY_EVENT_DOWN] == (FuncPtr)6543);    
#endif
	kal_prompt_trace(MOD_MMI, "[UT_KEY] set key handler test PASS");
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ut_mmi_frm_set_group_key_handler
 * DESCRIPTION
 * <test case description> test the API mmi_frm_set_group_key_handler
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    
 * <Test Case Content> mmi_frm_set_group_key_handler
 * <Test Case Number>
 * <Scenario>
 *    case1:
 * <Expected Result>
 *    case1:
 *
 * </test case description>

 *
 * PARAMETERS
 *  pare         :[IN] reserved
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
void group_key_hdlr1(void){}
void group_key_hdlr2(void){}
void group_key_hdlr3(void){}
mmi_ret ut_mmi_frm_set_group_key_handler(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 key_codes[4] = {KEY_UP_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW, KEY_LEFT_ARROW};
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    mmi_frm_set_group_key_handler(group_key_hdlr1, (PU16)PresentAllDialerKeys, TOTAL_DIALER_KEYS, KEY_EVENT_DOWN);
    MMI_ASSERT(anyKeyFuncPtrs[KEY_EVENT_DOWN] == group_key_hdlr1);
    mmi_frm_set_group_key_handler(group_key_hdlr2, (PU16)PresentAllKeys, TOTAL_KEYS, KEY_EVENT_DOWN);
    MMI_ASSERT(anyKeyFuncPtrs[KEY_EVENT_DOWN] == group_key_hdlr2);
#endif
    mmi_frm_set_group_key_handler(group_key_hdlr3, key_codes, 4, KEY_EVENT_DOWN);
    MMI_ASSERT(currKeyFuncPtrs[KEY_UP_ARROW][KEY_EVENT_DOWN] == group_key_hdlr3);
    MMI_ASSERT(currKeyFuncPtrs[KEY_DOWN_ARROW][KEY_EVENT_DOWN] == group_key_hdlr3);
    MMI_ASSERT(currKeyFuncPtrs[KEY_RIGHT_ARROW][KEY_EVENT_DOWN] == group_key_hdlr3);
    MMI_ASSERT(currKeyFuncPtrs[KEY_LEFT_ARROW][KEY_EVENT_DOWN] == group_key_hdlr3);
	kal_prompt_trace(MOD_MMI, "[UT_KEY] set group key handler test PASS");
    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  ut_mmi_frm_clear_key_handler
 * DESCRIPTION
 * <test case description> test the API mmi_frm_clear_key_handler
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    
 * <Test Case Content> mmi_frm_clear_key_handler
 * <Test Case Number>
 * <Scenario>
 *    case1:
 * <Expected Result>
 *    case1:
 *
 * </test case description>

 *
 * PARAMETERS
 *  pare         :[IN] reserved
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret ut_mmi_frm_clear_key_handler(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 key_code;
	U8 key_type;
	
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	for (key_code = KEY_0; key_code < MAX_KEYS; key_code++)
	{
		for (key_type = KEY_EVENT_DOWN; key_type < MAX_NON_2STEP_KEY_TYPE; key_type++)
		{
			mmi_frm_clear_key_handler(key_code, key_type);
			MMI_ASSERT(mmi_frm_get_key_handler(key_code, key_type) == NULL);
		}
	}
#if defined(__KBD_2STEP_KEY_SUPPORT__) && defined(__MTK_TARGET__)
	for (key_type = KEY_EVENT_DOWN; key_type < MAX_KEY_TYPE; key_type++)
	{
		mmi_frm_clear_key_handler(KEY_CAMERA, key_type);
		MMI_ASSERT(mmi_frm_get_key_handler(KEY_CAMERA, key_type) == NULL);
	}
#endif /* __KBD_2STEP_KEY_SUPPORT__ */
	kal_prompt_trace(MOD_MMI, "[UT_KEY] clear key handler test PASS");
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ut_mmi_frm_query_mmi_key_state
 * DESCRIPTION
 * <test case description> test the API mmi_frm_query_mmi_key_state
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    
 * <Test Case Content> mmi_frm_query_mmi_key_state
 * <Test Case Number>
 * <Scenario>
 *    case1:
 * <Expected Result>
 *    case1:
 *
 * </test case description>

 *
 * PARAMETERS
 *  pare         :[IN] reserved
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret ut_mmi_frm_query_mmi_key_state(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    key_data_struct data1;
    key_data_struct data2;
    U8 key_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SET_KEY_DET_MODE(g_key_cntx.keypad_status, (U8)DCL_kbd_2_keys_det_mode);
    init_key_data_buf();
    data1.mmi_key_code = KEY_0;
    data2.mmi_key_code = KEY_1;

    insert_key_data(&data1);
    insert_key_data(&data2);
    for (key_type = KEY_EVENT_DOWN;  key_type < MAX_KEY_TYPE; key_type++)
    {
        data1.mmi_key_type = key_type;
        data2.mmi_key_type = key_type;
        update_key_data(&data1);
        update_key_data(&data2);
        MMI_ASSERT((U8)mmi_frm_query_mmi_key_state(KEY_0) == key_type);
        MMI_ASSERT((U8)mmi_frm_query_mmi_key_state(KEY_1) == key_type);
    }
	init_key_data_buf();
	kal_prompt_trace(MOD_MMI, "[UT_KEY] query mmi key state test PASS");
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ut_mmi_frm_clear_all_key_handler
 * DESCRIPTION
 * <test case description> test the API mmi_frm_clear_all_key_handler
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    
 * <Test Case Content> mmi_frm_clear_all_key_handler
 * <Test Case Number>
 * <Scenario>
 *    case1:
 * <Expected Result>
 *    case1:
 *
 * </test case description>

 *
 * PARAMETERS
 *  pare         :[IN] reserved
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret ut_mmi_frm_clear_all_key_handler(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 key_code;
	U8 key_type;

	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_frm_clear_all_key_handler();
	for (key_code = KEY_0; key_code < MAX_KEYS; key_code++)
	{
		for (key_type = KEY_EVENT_DOWN; key_type < MAX_NON_2STEP_KEY_TYPE; key_type++)
		{
			if ((key_code != KEY_END) &&
				(key_code != KEY_VOL_DOWN) &&
				(key_code != KEY_VOL_UP) &&
				(key_code != KEY_POWER))
			{
				MMI_ASSERT(mmi_frm_get_key_handler(key_code, key_type) == NULL);
			}
		}
	}
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
	for (key_type = KEY_EVENT_DOWN; key_type < MAX_KEY_TYPE; key_type++)
	{
		MMI_ASSERT(anyKeyFuncPtrs[key_type] == NULL);
	}
#endif
	kal_prompt_trace(MOD_MMI, "[UT_KEY] clear all key handler test PASS");
    return MMI_RET_OK;
}

static void test_is_key_event(void)
{
	MMI_ASSERT(mmi_frm_is_key_event() == MMI_FALSE);
}
static void test_is_key_event2(void)
{
	MMI_ASSERT(mmi_frm_is_key_event() == MMI_TRUE);
}
/*****************************************************************************
 * FUNCTION
 *  ut_mmi_frm_is_key_event
 * DESCRIPTION
 * <test case description> test the API mmi_frm_is_key_event
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    
 * <Test Case Content> mmi_frm_is_key_event
 * <Test Case Number>
 * <Scenario>
 *    case1:
 * <Expected Result>
 *    case1:
 *
 * </test case description>

 *
 * PARAMETERS
 *  pare         :[IN] reserved
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret ut_mmi_frm_is_key_event(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_key_evt_struct evt;
	
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	g_key_cntx.is_key_event = MMI_TRUE;
	MMI_ASSERT(mmi_frm_is_key_event() == MMI_TRUE);
	g_key_cntx.is_key_event = MMI_FALSE;
	MMI_ASSERT(mmi_frm_is_key_event() == MMI_FALSE);
	mmi_frm_set_key_handler(test_is_key_event, KEY_1, KEY_EVENT_DOWN);
	mmi_frm_exec_key_handler(KEY_1, KEY_EVENT_DOWN);
	mmi_frm_set_key_handler(test_is_key_event2, KEY_0, KEY_EVENT_DOWN);
	evt.cvt_code = KEY_0;
	evt.is_clear = MMI_FALSE;
	evt.mmi_key_code = KEY_0;
	evt.mmi_key_type = KEY_EVENT_DOWN;
	mmi_key_handle(&evt);
	evt.mmi_key_type = KEY_EVENT_UP;
	mmi_key_handle(&evt);
	kal_prompt_trace(MOD_MMI, "[UT_KEY] test mmi is key event PASS");
	return MMI_RET_OK;
}
U8 exec_test;
void test_exec_key_handler1(void)
{
    exec_test++;        
}

/*****************************************************************************
 * FUNCTION
 *  ut_mmi_frm_exec_key_handler
 * DESCRIPTION
 * <test case description> test the API mmi_frm_exec_key_handler
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    
 * <Test Case Content> mmi_frm_exec_key_handler
 * <Test Case Number>
 * <Scenario>
 *    case1:
 * <Expected Result>
 *    case1:
 *
 * </test case description>

 *
 * PARAMETERS
 *  pare         :[IN] reserved
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret ut_mmi_frm_exec_key_handler(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	mmi_frm_set_key_handler(test_exec_key_handler1, KEY_0, KEY_EVENT_DOWN);
    exec_test = 0;
	mmi_frm_exec_key_handler(KEY_0, KEY_EVENT_DOWN);
    MMI_ASSERT(exec_test == 1);
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ut_mmi_frm_set_key_proc
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    
 * <Test Case Content> set key proc function
 * <Test Case Number> 31
 * <Scenario>
 *    case1: set
 * <Expected Result>
 *    case1: get KEY_EVENT_DECT
 *
 * </test case description>

 *
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret ut_mmi_frm_set_key_proc(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 real_layer;
    U8 concept_layer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* 
     * Normal set
     * Set key proc for SYS, SCR, CAT, WGUIs...
     *
     */
    g_key_cntx.wgui_layer_num[LAYER_SET_SPACE] = 0;
    for (real_layer = MMI_KEY_ROUTING_SYS; real_layer < MMI_KEY_ROUTING_TOTAL; real_layer++)
    {
        concept_layer = (real_layer > MMI_KEY_ROUTING_WGUI) ? MMI_KEY_ROUTING_WGUI : real_layer;
        mmi_frm_set_key_proc(concept_layer, (mmi_proc_func)real_layer, (void *)real_layer);
        MMI_ASSERT(g_key_cntx.routing_layer[LAYER_SET_SPACE][real_layer].key_proc == (mmi_proc_func)real_layer);
        MMI_ASSERT(g_key_cntx.routing_layer[LAYER_SET_SPACE][real_layer].user_data == (void *)real_layer);
    }

    /*
     * For WGUI if Set the same proc/user_data twice, we will not do any changes
     */
    g_key_cntx.wgui_layer_num[LAYER_SET_SPACE] = 0;
    for (real_layer = MMI_KEY_ROUTING_WGUI; real_layer < MMI_KEY_ROUTING_WGUI; real_layer++)
    {
        mmi_frm_set_key_proc(MMI_KEY_ROUTING_WGUI, (mmi_proc_func)real_layer, (void *)real_layer);
        mmi_frm_set_key_proc(MMI_KEY_ROUTING_WGUI, (mmi_proc_func)real_layer, (void *)real_layer);
        MMI_ASSERT(g_key_cntx.wgui_layer_num[LAYER_SET_SPACE] == (real_layer - MMI_KEY_ROUTING_WGUI + 1));
    }
    kal_prompt_trace(MOD_MMI, "[UT_KEY] set key proc test pass!");
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  ut_get_mmi_key_events
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0017
 * <Test Case Content> get frm level key event
 * <Test Case Number> 31
 * <Scenario>
 *    case1: detection event input
 *    case2: key code no mapping
 *    case3: 2step key, press -> release
 *    case4: 2step key, press -> full press
 *    case5: 2step key, full press->longpress
 *    case6: 2step key, longpress->repeat
 *    case7: 2step key, repeat-> repeat
 *    case8: 2step key, repeat->release
 *    case9: 2step key, longpress->release
 *    case10:2step key, full press -> release
 *    case11:2step key, release -> release
 *    case12:2step key, full press->half press
 *    case13:2step key, half press->half press
 *    case14:2step key, release -> longpress
 *    case15:2step key, release -> repeat
 *    case16:2step key, release -> full press
 *    case17:2step key, release->press
 *    case18:non-2step, release->press
 *    case19:non-2step, press->release
 *    case20:non-2step, press->longpress
 *    case21:non-2step, longpress -> repeat
 *    case22:non-2step, repeat->repeat
 *    case23:non-2step, longpress->release
 *    case24:non-2step, repeat->release
 *    case25:non-2step, release->release
 *    case26:non-2step, release->longpress
 *    case27:non-2step, release->repeat
 *    case28:non-2step, press-> press
 *    case29:non-2step, repeat->longpress
 *    case30:non-2step, press->repeat
 *    case31:non-2step, full press
 * <Expected Result>
 *    case1: get KEY_EVENT_DECT
 *    case2: get KEY_INVALID, ERR_KEY_CODE  
 *    case3: get up
 *    case4: get full down
 *    case5: get long press
 *    case6: get repeat
 *    case7: get repeat
 *    case8: get release
 *    case9: get release
 *    case10:get release
 *    case11:get ERR_KEY_EVT_TRANS
 *    case12:get ERR_KEY_EVT_TRANS
 *    case13:get ERR_KEY_EVT_TRANS
 *    case14:get ERR_KEY_EVT_TRANS
 *    case15:get ERR_KEY_EVT_TRANS
 *    case16:get ERR_KEY_EVT_TRANS
 *    case17:get half down
 *    case18:get down
 *    case19:get up
 *    case20:get long press
 *    case21:get repeat
 *    case22:get repeat
 *    case23:get up
 *    case24:get up
 *    case25:get up
 *    case26:get ERR_KEY_EVT_TRANS
 *    case27:get ERR_KEY_EVT_TRANS
 *    case28:get ERR_KEY_EVT_TRANS
 *    case29:get ERR_KEY_EVT_TRANS
 *    case30:get ERR_KEY_EVT_TRANS
 *    case31:get ERR_KEY_EVENT
 *
 * </test case description>
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret  ut_get_mmi_key_events(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dev_key_evt_struct  device_key;
    mmi_key_evt_struct     mmi_key;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* case 1 */
#if defined(__TWO_KEY_DETECTION_SWITCHABLE__) || defined(__THREE_KEY_DETECTION_SWITCHABLE__)
    device_key.device_key_type = DRV_WM_ENABLE_TWOKEY_DETECTION;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_EVENT_DECT);
#endif

#if defined(__THREE_KEY_DETECTION_SWITCHABLE__)
    device_key.device_key_type = DRV_WM_ENABLE_THREEKEY_DETECTION;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_EVENT_DECT);
#endif
    device_key.device_key_type = DRV_WM_DISABLE_MULTIKEY_DETECTION;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_EVENT_DECT);

    /* case 2 */
    device_key.device_key_code = DEVICE_KEY_EMAIL;
    device_key.device_key_type = DRV_WM_KEYPRESS;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_type == ERR_KEY_CODE);

    /* case 3 */
#ifdef __KBD_2STEP_KEY_SUPPORT__
    g_key_cntx._2step_key.mmi_key_code = KEY_CAMERA;
    g_key_cntx.buffer[0].mmi_key_code = KEY_CAMERA;
    g_key_cntx.buffer[0].mmi_key_type = KEY_HALF_PRESS_DOWN;
    device_key.device_key_code = DEVICE_KEY_FUNCTION;
    device_key.device_key_type = DRV_WM_KEYRELEASE;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_code == KEY_CAMERA);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_EVENT_UP);

    /* case 4 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_CAMERA;
    g_key_cntx.buffer[0].mmi_key_type = KEY_HALF_PRESS_DOWN;    
    device_key.device_key_code = DEVICE_KEY_FUNCTION;
    device_key.device_key_type = DRV_WM_KEYFULLPRESS;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_code == KEY_CAMERA);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_FULL_PRESS_DOWN);

    /* case 5 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_CAMERA;
    g_key_cntx.buffer[0].mmi_key_type = KEY_FULL_PRESS_DOWN; 
    device_key.device_key_code = DEVICE_KEY_FUNCTION;
    device_key.device_key_type = DRV_WM_KEYLONGPRESS;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_code == KEY_CAMERA);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_LONG_PRESS);

    /* case 6 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_CAMERA;
    g_key_cntx.buffer[0].mmi_key_type = KEY_LONG_PRESS;     
    device_key.device_key_code = DEVICE_KEY_FUNCTION;
    device_key.device_key_type = DRV_WM_KEYREPEATED;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_code == KEY_CAMERA);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_REPEAT);

    /* case 7 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_CAMERA;
    g_key_cntx.buffer[0].mmi_key_type = KEY_REPEAT;     
    device_key.device_key_code = DEVICE_KEY_FUNCTION;
    device_key.device_key_type = DRV_WM_KEYREPEATED;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_code == KEY_CAMERA);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_REPEAT);    

    /* case 8 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_CAMERA;
    g_key_cntx.buffer[0].mmi_key_type = KEY_REPEAT;     
    device_key.device_key_code = DEVICE_KEY_FUNCTION;
    device_key.device_key_type = DRV_WM_KEYRELEASE;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_code == KEY_CAMERA);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_EVENT_UP);

    /* case 9 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_CAMERA;
    g_key_cntx.buffer[0].mmi_key_type = KEY_LONG_PRESS;     
    device_key.device_key_code = DEVICE_KEY_FUNCTION;
    device_key.device_key_type = DRV_WM_KEYRELEASE;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_code == KEY_CAMERA);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_EVENT_UP);

    /* case 10 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_CAMERA;
    g_key_cntx.buffer[0].mmi_key_type = KEY_FULL_PRESS_DOWN;     
    device_key.device_key_code = DEVICE_KEY_FUNCTION;
    device_key.device_key_type = DRV_WM_KEYRELEASE;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_code == KEY_CAMERA);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_EVENT_UP);

    /* case 11 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_CAMERA;
    g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_UP;     
    device_key.device_key_code = DEVICE_KEY_FUNCTION;
    device_key.device_key_type = DRV_WM_KEYRELEASE;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_type == ERR_KEY_EVT_TRANS);

    /* case 12 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_CAMERA;
    g_key_cntx.buffer[0].mmi_key_type = KEY_FULL_PRESS_DOWN;     
    device_key.device_key_code = DEVICE_KEY_FUNCTION;
    device_key.device_key_type = DRV_WM_KEYPRESS;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_type == ERR_KEY_EVT_TRANS);

    /* case 13 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_CAMERA;
    g_key_cntx.buffer[0].mmi_key_type = KEY_HALF_PRESS_DOWN;     
    device_key.device_key_code = DEVICE_KEY_FUNCTION;
    device_key.device_key_type = DRV_WM_KEYPRESS;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_type == ERR_KEY_EVT_TRANS);

    /* case 14 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_CAMERA;
    g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_UP;     
    device_key.device_key_code = DEVICE_KEY_FUNCTION;
    device_key.device_key_type = DRV_WM_KEYLONGPRESS;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_type == ERR_KEY_EVT_TRANS);

    /* case 15 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_CAMERA;
    g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_UP;     
    device_key.device_key_code = DEVICE_KEY_FUNCTION;
    device_key.device_key_type = DRV_WM_KEYREPEATED;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_type == ERR_KEY_EVT_TRANS);

    /* case 16 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_CAMERA;
    g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_UP;     
    device_key.device_key_code = DEVICE_KEY_FUNCTION;
    device_key.device_key_type = DRV_WM_KEYFULLPRESS;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_type == ERR_KEY_EVT_TRANS);

    /* case 17 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_CAMERA;
    g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_UP;     
    device_key.device_key_code = DEVICE_KEY_FUNCTION;
    device_key.device_key_type = DRV_WM_KEYPRESS;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_code == KEY_CAMERA);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_HALF_PRESS_DOWN);
#endif
    /* case 18 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_0;
    g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_UP;     
    device_key.device_key_code = DEVICE_KEY_0;
    device_key.device_key_type = DRV_WM_KEYPRESS;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_code == KEY_0);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_EVENT_DOWN);

    /* case 19 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_0;
    g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_DOWN;     
    device_key.device_key_code = DEVICE_KEY_0;
    device_key.device_key_type = DRV_WM_KEYRELEASE;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_code == KEY_0);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_EVENT_UP);

    /* case 20 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_0;
    g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_DOWN;     
    device_key.device_key_code = DEVICE_KEY_0;
    device_key.device_key_type = DRV_WM_KEYLONGPRESS;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_code == KEY_0);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_LONG_PRESS);

    /* case 21 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_0;
    g_key_cntx.buffer[0].mmi_key_type = KEY_LONG_PRESS;     
    device_key.device_key_code = DEVICE_KEY_0;
    device_key.device_key_type = DRV_WM_KEYREPEATED;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_code == KEY_0);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_REPEAT); 

    /* case 22 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_0;
    g_key_cntx.buffer[0].mmi_key_type = KEY_REPEAT;     
    device_key.device_key_code = DEVICE_KEY_0;
    device_key.device_key_type = DRV_WM_KEYREPEATED;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_code == KEY_0);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_REPEAT);

    /* case 23 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_0;
    g_key_cntx.buffer[0].mmi_key_type = KEY_LONG_PRESS;     
    device_key.device_key_code = DEVICE_KEY_0;
    device_key.device_key_type = DRV_WM_KEYRELEASE;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_code == KEY_0);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_EVENT_UP);

    /* case 24 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_0;
    g_key_cntx.buffer[0].mmi_key_type = KEY_REPEAT;     
    device_key.device_key_code = DEVICE_KEY_0;
    device_key.device_key_type = DRV_WM_KEYRELEASE;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_code == KEY_0);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_EVENT_UP);

    /* case 25 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_0;
    g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_UP;     
    device_key.device_key_code = DEVICE_KEY_0;
    device_key.device_key_type = DRV_WM_KEYRELEASE;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_type == ERR_KEY_EVT_TRANS);


    /* case 26 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_0;
    g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_UP;     
    device_key.device_key_code = DEVICE_KEY_0;
    device_key.device_key_type = DRV_WM_KEYLONGPRESS;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_type == ERR_KEY_EVT_TRANS);

    /* case 27 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_0;
    g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_UP;     
    device_key.device_key_code = DEVICE_KEY_0;
    device_key.device_key_type = DRV_WM_KEYREPEATED;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_type == ERR_KEY_EVT_TRANS);

    /* case 28 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_0;
    g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_DOWN;     
    device_key.device_key_code = DEVICE_KEY_0;
    device_key.device_key_type = DRV_WM_KEYPRESS;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_type == ERR_KEY_EVT_TRANS);

    /* case 29 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_0;
    g_key_cntx.buffer[0].mmi_key_type = KEY_REPEAT;     
    device_key.device_key_code = DEVICE_KEY_0;
    device_key.device_key_type = DRV_WM_KEYLONGPRESS;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_type == ERR_KEY_EVT_TRANS);

    /* case 30 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_0;
    g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_DOWN;     
    device_key.device_key_code = DEVICE_KEY_0;
    device_key.device_key_type = DRV_WM_KEYREPEATED;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_type == ERR_KEY_EVT_TRANS);

    /* case 31 */
    device_key.device_key_code = DEVICE_KEY_0;
    device_key.device_key_type = DRV_WM_KEYFULLPRESS;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_type == ERR_KEY_EVENT);
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test get_mmi_key_events PASS");
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ut_post_update_key_data_buf
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0016
 * <Test Case Content> post update key cntx
 * <Test Case Number> 6
 * <Scenario>
 *    case1: 2 key in buffer, receive 2 up
 *    case2: 2 key in buffer, receive 1 up
 *    case3: 1 key in buffer, receive 1 up
 *    case4: 2 key in buffer, receive, other event
 *    case5: 1 key in buffer, receive, other event
 *    case6: no key in buffer, receive some key code up
 *    case7: no key in buffer, receive some key other event 
 *
 * <Expected Result>
 *    case1: 2 remove
 *    case2: 1 remove 
 *    case3: 1 remove
 *    case4: no change
 *    case5: no change
 *    case6: no change
 *    case7: no change
 *
 * </test case description>
 *
 * PARAMETERS
 *  para
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret ut_post_update_key_data_buf(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 	key_data_struct data[MAX_DECT_KEY_NUM];
	U8 len;
	U8 keypad_status;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	keypad_status = g_key_cntx.keypad_status;
	save_key_data(data, &len);
	
    init_key_data_buf();
    SET_KEY_DET_MODE(g_key_cntx.keypad_status, (U8)DCL_kbd_2_keys_det_mode);
    g_key_cntx.buffer[0].mmi_key_code = KEY_1;
    g_key_cntx.buffer[1].mmi_key_code = KEY_2;
	g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_UP;
	g_key_cntx.buffer[1].mmi_key_type = KEY_EVENT_UP;
    g_key_cntx.buf_len = 2;
    post_update_key_data_buf();
    MMI_ASSERT(g_key_cntx.buffer[0].mmi_key_code == KEY_INVALID);
    MMI_ASSERT(g_key_cntx.buffer[1].mmi_key_code == KEY_INVALID);

    g_key_cntx.buffer[0].mmi_key_code = KEY_1;
    g_key_cntx.buffer[1].mmi_key_code = KEY_2;
	g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_UP;
    g_key_cntx.buffer[1].mmi_key_type = KEY_EVENT_DOWN;
    g_key_cntx.buf_len = 2;
    post_update_key_data_buf();
    MMI_ASSERT(g_key_cntx.buffer[0].mmi_key_code == KEY_2);
    MMI_ASSERT(g_key_cntx.buffer[1].mmi_key_code == KEY_INVALID);

    g_key_cntx.buffer[0].mmi_key_code = KEY_1;
    g_key_cntx.buffer[1].mmi_key_code = KEY_2;
    g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_DOWN;
    g_key_cntx.buffer[1].mmi_key_type = KEY_EVENT_UP;
    g_key_cntx.buf_len = 2;
    post_update_key_data_buf();
    MMI_ASSERT(g_key_cntx.buffer[0].mmi_key_code == KEY_1);
    MMI_ASSERT(g_key_cntx.buffer[1].mmi_key_code == KEY_INVALID);  


    g_key_cntx.buffer[0].mmi_key_code = KEY_1;
    g_key_cntx.buffer[1].mmi_key_code = KEY_INVALID;
    g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_UP;
    g_key_cntx.buf_len = 1;
    post_update_key_data_buf();
    MMI_ASSERT(g_key_cntx.buffer[0].mmi_key_code == KEY_INVALID);
    MMI_ASSERT(g_key_cntx.buffer[1].mmi_key_code == KEY_INVALID);

    g_key_cntx.buffer[0].mmi_key_code = KEY_1;
    g_key_cntx.buffer[1].mmi_key_code = KEY_2;
	g_key_cntx.buffer[0].mmi_key_type = KEY_REPEAT;
	g_key_cntx.buffer[1].mmi_key_type = KEY_REPEAT;
    g_key_cntx.buf_len = 2;
    post_update_key_data_buf();
    MMI_ASSERT(g_key_cntx.buffer[0].mmi_key_code == KEY_1);
    MMI_ASSERT(g_key_cntx.buffer[1].mmi_key_code == KEY_2);

	restore_key_data(data, &len);
	g_key_cntx.keypad_status = keypad_status;
	kal_prompt_trace(MOD_MMI, "[UT_KEY] test post_update_key_data_buf PASS");
	return MMI_RET_OK;	
}


/*****************************************************************************
 * FUNCTION
 *  ut_pre_update_key_data_buf
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0015
 * <Test Case Content> pre update key cntx
 * <Test Case Number> 5
 * <Scenario>
 *    case1: 2step key, half down, full down, long press, repeat, up
 *    case2: 2step key, special key
 *    case3: non-2step key, down, long press, repeat, up
 *    case4: non-2step key, half up, half down
 * <Expected Result>
 *    case1: update key code data
 *    case2: assert
 *    case3: update key code data
 *    case4: assert
 *
 * </test case description>
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret ut_pre_update_key_data_buf(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    key_data_struct data1;
    key_data_struct data2;
    S32 i;
    S16 key_type1[5] = {KEY_HALF_PRESS_DOWN, KEY_FULL_PRESS_DOWN, KEY_LONG_PRESS, KEY_REPEAT, KEY_EVENT_UP}; 
    S16 key_type2[4] = {KEY_EVENT_DOWN, KEY_LONG_PRESS, KEY_REPEAT, KEY_EVENT_UP};
 	key_data_struct data[MAX_DECT_KEY_NUM];
	U8 len;
	U8 keypad_status;	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	keypad_status = g_key_cntx.keypad_status;
	save_key_data(data, &len);
	
    init_key_data_buf();
    SET_KEY_DET_MODE(g_key_cntx.keypad_status, (U8)DCL_kbd_2_keys_det_mode);
#ifdef __KBD_2STEP_KEY_SUPPORT__
	data1.mmi_key_code = KEY_CAMERA;
    data1.is_2step = MMI_TRUE;
    data1.is_combo = MMI_FALSE;
    for (i = 0; i < 5; i++)
    {
        data1.mmi_key_type = (U8)key_type1[i];
        pre_update_key_data_buf(&data1);
        MMI_ASSERT(key_data_cmp(&data1, &g_key_cntx.buffer[0]));
        MMI_ASSERT(g_key_cntx.buffer[1].mmi_key_code == KEY_INVALID);
    }
#else
    data1.mmi_key_code = KEY_1;
    data1.is_2step = MMI_FALSE;
    data1.is_combo = MMI_FALSE;
    for (i = 0; i < 4; i++)
    {
        data1.mmi_key_type = (U8)key_type2[i];
        pre_update_key_data_buf(&data1);
        MMI_ASSERT(key_data_cmp(&data1, &g_key_cntx.buffer[0]));
        MMI_ASSERT(g_key_cntx.buffer[1].mmi_key_code == KEY_INVALID);
    }
#endif
    data2.mmi_key_code  = KEY_0;
    for (i = 0; i < 4; i++)
    {
        data2.mmi_key_type = (U8)key_type2[i];
        pre_update_key_data_buf(&data2);
        MMI_ASSERT(key_data_cmp(&data2, &g_key_cntx.buffer[1]));
        MMI_ASSERT(key_data_cmp(&data1, &g_key_cntx.buffer[0]));    
    }

	restore_key_data(data, &len);
	g_key_cntx.keypad_status = keypad_status;
	kal_prompt_trace(MOD_MMI, "[UT_KEY] test pre_update_key_data_buf PASS");
	return MMI_RET_OK;		
}


 /*****************************************************************************
 * FUNCTION
 *  ut_get_2step_key_state
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0013
 * <Test Case Content> get 2step key state
 * <Test Case Number> 6
 * <Scenario>
 *    case1: set KEY_CAMERA as 2 step key, FULL_DOWN
 *    case2: set KEY_CAMERA as 2 step key, HALF DOWN
 *    case3: set KEY_CAMERA as 2 step key, FULL UP
 *    case4: non-2step eky
 * 
 * <Expected Result>
 *    case1: FULL_DOWN
 *    case2: HALF DOWN 
 *    case3: FULL UP
 *    case4: STATE_END
 *
 * </test case description>
 *
 * PARAMETERS
 *  para
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret ut_get_2step_key_state(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __KBD_2STEP_KEY_SUPPORT__
	U8 key_code;
    U8 state;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	key_code = g_key_cntx._2step_key.mmi_key_code;
	state = g_key_cntx._2step_key.state;
    g_key_cntx._2step_key.mmi_key_code = KEY_CAMERA;
    g_key_cntx._2step_key.state = FULL_DOWN;
    MMI_ASSERT(get_2step_key_state(KEY_CAMERA) == FULL_DOWN);

    g_key_cntx._2step_key.state = HALF_DOWN;
    MMI_ASSERT(get_2step_key_state(KEY_CAMERA) == HALF_DOWN);

    g_key_cntx._2step_key.state= FULL_UP;
    MMI_ASSERT(get_2step_key_state(KEY_CAMERA) == FULL_UP);

    MMI_ASSERT(get_2step_key_state(KEY_1) == STATE_END);
	g_key_cntx._2step_key.mmi_key_code = key_code;
	g_key_cntx._2step_key.state = state;
	kal_prompt_trace(MOD_MMI, "[UT_KEY] teset ut_get_2step_key_state PASS");
#endif
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ut_get_key_state
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0012
 * <Test Case Content> get key state
 * <Test Case Number> 4
 * <Scenario>
 *    case1: not active key
 *    case2: active key down,
 *    case3: active key up
 *    case4: active key half up
 * 
 * <Expected Result>
 *    case1: up
 *    case2: down 
 *    case3: up 
 *    case4: half up
 *
 * </test case description>
 *
 * PARAMETERS
 *  para
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret ut_get_key_state(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    key_data_struct data1;
    key_data_struct data2;
    U8 key_type;
 	key_data_struct data[MAX_DECT_KEY_NUM];
	U8 len;
	U8 keypad_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	keypad_status = g_key_cntx.keypad_status;
	save_key_data(data, &len);
	
    SET_KEY_DET_MODE(g_key_cntx.keypad_status, (U8)DCL_kbd_2_keys_det_mode);
    init_key_data_buf();
    data1.mmi_key_code = KEY_0;
    data2.mmi_key_code = KEY_1;

    insert_key_data(&data1);
    insert_key_data(&data2);
    for (key_type = KEY_EVENT_DOWN;  key_type < MAX_KEY_TYPE; key_type++)
    {
        data1.mmi_key_type = key_type;
        data2.mmi_key_type = key_type;
        update_key_data(&data1);
        update_key_data(&data2);
        MMI_ASSERT((U8)get_key_state(KEY_0) == key_type);
        MMI_ASSERT((U8)get_key_state(KEY_1) == key_type);
    }
	restore_key_data(data, &len);
	g_key_cntx.keypad_status = keypad_status;
	kal_prompt_trace(MOD_MMI, "[UT_KEY] test get key state PASS");
	return MMI_RET_OK;	
}


/*****************************************************************************
 * FUNCTION
 *  ut_remove_key_data
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0011
 * <Test Case Content> remove multi-key data
 * <Test Case Number> 2
 * <Scenario>
 *    case1: 2 key detection mode, code1, code2 in table, remove code1
 *    case2: 2 key detection mode, code1, code2 in table, remove code2
 *    case3: 2 key detection mode, code1, code2 in table, remove code3
 *    case4: 2 key detection mode, code1, in table, remove code1
 * 
 * <Expected Result>
 *    case1: success, [code2, invalid]
 *    case2: success, [code1, invalid] 
 *    case3: fail 
 *    case4: success, [invalid, invalid]
 * </test case description>
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret ut_remove_key_data(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    key_data_struct data1;
    key_data_struct data2;
 	key_data_struct data[MAX_DECT_KEY_NUM];
	U8 len;
	U8 keypad_status;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	keypad_status = g_key_cntx.keypad_status;
	save_key_data(data, &len);	
    SET_KEY_DET_MODE(g_key_cntx.keypad_status, (U8)DCL_kbd_2_keys_det_mode);
    init_key_data_buf();
    data1.mmi_key_code = KEY_0;
    data2.mmi_key_code = KEY_1;
    insert_key_data(&data1);
    insert_key_data(&data2); 

    MMI_ASSERT(remove_key_data(KEY_0) == MMI_RET_OK);
    MMI_ASSERT(g_key_cntx.buf_len == 1);
    MMI_ASSERT(g_key_cntx.buffer[0].mmi_key_code == KEY_1);
    MMI_ASSERT(g_key_cntx.buffer[1].mmi_key_code == KEY_INVALID);

    MMI_ASSERT(remove_key_data(KEY_1) == MMI_RET_OK);
    MMI_ASSERT(g_key_cntx.buffer[0].mmi_key_code == KEY_INVALID);
    MMI_ASSERT(g_key_cntx.buffer[1].mmi_key_code == KEY_INVALID);
    MMI_ASSERT(g_key_cntx.buf_len == 0);

    init_key_data_buf();
    data1.mmi_key_code = KEY_0;
    data2.mmi_key_code = KEY_1;
    insert_key_data(&data1);
    insert_key_data(&data2); 

    MMI_ASSERT(remove_key_data(KEY_1) == MMI_RET_OK);
    MMI_ASSERT(g_key_cntx.buffer[0].mmi_key_code == KEY_0);
    MMI_ASSERT(g_key_cntx.buffer[1].mmi_key_code == KEY_INVALID);

    init_key_data_buf();
    data1.mmi_key_code = KEY_0;
    data2.mmi_key_code = KEY_1;
    insert_key_data(&data1);
    insert_key_data(&data2);
    MMI_ASSERT(remove_key_data(KEY_3) == REMOVE_BUT_NOT_FOUND);

	restore_key_data(data, &len);
	g_key_cntx.keypad_status = keypad_status;
	kal_prompt_trace(MOD_MMI, "[UT_KEY] test remove key data PASS");
	return MMI_RET_OK;		
}


/*****************************************************************************
 * FUNCTION
 *  ut_update_key_data
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0010
 * <Test Case Content> change multi-key data
 * <Test Case Number> 3
 * <Scenario>
 *    case1: 2 key detection mode, code1, code2 in table, change code1 state
 *    case2: 2 key detection mode, code1, code2 in table, change code2 state
 *    case3: 2 key detection mode, code1, code2 in table, change code3 state 
 * 
 * <Expected Result>
 *    case1: success
 *    case2: success
 *    case3: fail 
 * </test case description>
 *
 * PARAMETERS
 *  para
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret ut_update_key_data(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    key_data_struct data1;
    key_data_struct data2;
    key_data_struct data3;
	key_data_struct data[MAX_DECT_KEY_NUM];
	U8 len;
	U8 keypad_status;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	keypad_status = g_key_cntx.keypad_status;
	save_key_data(data, &len);
	
    SET_KEY_DET_MODE(g_key_cntx.keypad_status, (U8)DCL_kbd_2_keys_det_mode);
    init_key_data_buf();
    data1.mmi_key_code = KEY_0;
    data2.mmi_key_code = KEY_1;
    insert_key_data(&data1);
    insert_key_data(&data2);

    data3.mmi_key_code = KEY_0;
    data3.mmi_key_type = KEY_REPEAT;
    MMI_ASSERT(update_key_data(&data3) == MMI_TRUE);
    MMI_ASSERT(key_data_cmp(&data3, &g_key_cntx.buffer[0]) == MMI_TRUE);
    
    data3.mmi_key_code = KEY_1;
    data3.mmi_key_type = KEY_REPEAT;
    MMI_ASSERT(update_key_data(&data3) == MMI_TRUE);
    MMI_ASSERT(key_data_cmp(&data3, &g_key_cntx.buffer[1]) == MMI_TRUE);

    data3.mmi_key_code = KEY_3;
    MMI_ASSERT(update_key_data(&data3) == MMI_FALSE);

	restore_key_data(data, &len);
	g_key_cntx.keypad_status = keypad_status;
	kal_prompt_trace(MOD_MMI, "[UT_KEY] test update key data PASS");
	return MMI_RET_OK;	
}


/*****************************************************************************
 * FUNCTION
 *  ut_search_key_data
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0009
 * <Test Case Content> get index of specific mmi key code in key cntx
 * <Test Case Number> 3
 * <Scenario>
 *    case1: 2 key detection mode, code1, code2 in table, find code1
 *    case2: 2 key detection mode, code1, code2 in table, find code2
 *    case3: 2 key detection mode, code1, code2 in table, find code3
 * 
 * <Expected Result>
 *    case1: find
 *    case2: find
 *    case3: not find
 * </test case description>
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret ut_search_key_data(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    key_data_struct data1;
    key_data_struct data2;
	key_data_struct data[MAX_DECT_KEY_NUM];
	U8 len;
	U8 keypad_status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	keypad_status = g_key_cntx.keypad_status;
	save_key_data(data, &len);
    SET_KEY_DET_MODE(g_key_cntx.keypad_status, (U8)DCL_kbd_2_keys_det_mode);
    init_key_data_buf();
    data1.mmi_key_code = KEY_0;
    data2.mmi_key_code = KEY_1;
    insert_key_data(&data1);
    insert_key_data(&data2);    
    MMI_ASSERT(search_key_data(KEY_0) == 0);    
    MMI_ASSERT(search_key_data(KEY_1) == 1);
    MMI_ASSERT(search_key_data(KEY_3) == -1);
	restore_key_data(data, &len);
	g_key_cntx.keypad_status = keypad_status;
	kal_prompt_trace(MOD_MMI, "[UT_KEY] test search key data PASS");
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  key_data_cmp
 * DESCRIPTION
 *  This function is used to cmp tow key_data_struct
 *
 * PARAMETERS
 *  p    :[IN] key_data structure 1
 *  q    :[IN] key_data structure 2
 * RETURNS
 *  equal return MMI_TRUE or return MMI_FALSE
 *****************************************************************************/
MMI_BOOL key_data_cmp(key_data_struct *p, key_data_struct *q)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (p->mmi_key_code == q->mmi_key_code) &&
           (p->cvt_code == q->cvt_code) &&
           (p->mmi_key_type == q->mmi_key_type) &&
           (p->is_2step == q->is_2step) &&
           (p->is_clear == q->is_clear) &&
           (p->is_combo == q->is_combo);
}


/*****************************************************************************
 * FUNCTION
 *  save_key_data
 * DESCRIPTION
 *  This function is used to save the key data buffer to another place
 *
 * PARAMETERS
 *  buf_p    :[IN] memory to store key data
 *  len_p    :[IN] memory to store buffer length
 * RETURNS
 *  void
 *****************************************************************************/
void save_key_data(key_data_struct *buf_p, U8 *len_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 j;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	*len_p = g_key_cntx.buf_len;
	for (j = 0; j < MAX_DECT_KEY_NUM; j++)
	{
		buf_p[j] = g_key_cntx.buffer[j];
	}
}


/*****************************************************************************
 * FUNCTION
 *  restore_key_data
 * DESCRIPTION
 *  This function is used to restore the key data buffer
 *
 * PARAMETERS
 *  buf_p    :[IN] memory to store key data
 *  len_p    :[IN] memory to store buffer length
 * RETURNS
 *  void
 *****************************************************************************/
void restore_key_data(key_data_struct *buf_p, U8 *len_p)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	S32 j;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	g_key_cntx.buf_len = *len_p;
	for (j = 0; j < MAX_DECT_KEY_NUM; j++)
	{
		g_key_cntx.buffer[j] = buf_p[j];
	}
}

void set_key_data(key_data_struct *data,
				  	U8 code,
				  	U8 cvt_code,
				  	U8 type, 
				  	MMI_BOOL is_2step,
				  	MMI_BOOL is_combo,
				  	MMI_BOOL is_clear)
{
	data->mmi_key_code = code;
    data->cvt_code = cvt_code;
	data->mmi_key_type = type;
	data->is_2step = is_2step;
	data->is_combo = is_combo;
	data->is_clear = is_clear;
}
/*****************************************************************************
 * FUNCTION
 *  write_key_data
 * DESCRIPTION
 *  This function is used to write data to key data buffer
 *
 * PARAMETERS
 *  indx    :[IN] key data buffer index
 *  data_p  :[IN] data that will be writen to key data buffer.
 * RETURNS
 *  void
 *****************************************************************************/
void write_key_data(S32 index, key_data_struct *data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_FRM_UT_ASSERT(index < MAX_DECT_KEY_NUM, MMI_FALSE, GET_RES_MEM());
    g_key_cntx.buffer[index].mmi_key_code = data_p->mmi_key_code;
    g_key_cntx.buffer[index].cvt_code = data_p->cvt_code;
    g_key_cntx.buffer[index].mmi_key_type = data_p->mmi_key_type;
    g_key_cntx.buffer[index].is_2step     = data_p->is_2step;
    g_key_cntx.buffer[index].is_clear     = data_p->is_clear;
    g_key_cntx.buffer[index].is_combo   = data_p->is_combo;

}

/*****************************************************************************
 * FUNCTION
 *  ut_insert_key_data
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0008
 * <Test Case Content> add multi key date to key cntx
 * <Test Case Number> 5
 * <Scenario>
 *    case1: detection mode is 2key, add code1 to [INVALID, INVALID]
 *    case2: detection mode is 2key, add code2 to [code1,   INVALID]
 *    case3: detection mode is 2key, add code1 to [code1,   INVALID]
 *    case4: detection mode is 2key, add code1 to [code1,   code2]
 *    case5: detection mode is 2key, add code2 to [code1,   code2]
 *    case6: detection mode is 2key, add code3 to [code1,   code2]
 * <Expected Result>
 *    case1: [code1, INVALID]
 *    case2: [code1, code2]
 *    case3: assert
 *    case4: assert
 *    case5: assert
 * </test case description>
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret ut_insert_key_data(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    key_data_struct data1;
    key_data_struct data2;
	key_data_struct data3;
	key_data_struct data[MAX_DECT_KEY_NUM];
	U8 len;
	U8 key_pad_status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	save_key_data(data, &len);
	key_pad_status = g_key_cntx.keypad_status;
    init_key_data_buf();
    SET_KEY_DET_MODE(g_key_cntx.keypad_status, (U8)DCL_kbd_2_keys_det_mode);
	set_key_data(&data1, KEY_0, KEY_0, KEY_EVENT_DOWN, MMI_FALSE, MMI_TRUE, MMI_FALSE);
    insert_key_data(&data1);
    MMI_ASSERT(g_key_cntx.buf_len == 1);
    MMI_ASSERT(key_data_cmp(&data1, &g_key_cntx.buffer[0]) == MMI_TRUE);
    MMI_ASSERT(g_key_cntx.buffer[1].mmi_key_code == KEY_INVALID);
	set_key_data(&data2, KEY_1, KEY_1, KEY_EVENT_DOWN, MMI_FALSE, MMI_TRUE, MMI_FALSE);

    insert_key_data(&data2);    
    MMI_ASSERT(key_data_cmp(&data1, &g_key_cntx.buffer[0]) == MMI_TRUE);
    MMI_ASSERT(key_data_cmp(&data2, &g_key_cntx.buffer[1]) == MMI_TRUE);
    MMI_ASSERT(g_key_cntx.buf_len == 2);

	//MMI_ASSERT(insert_key_data(&data1) == INSERT_SAME_KEY_CODE);
	//MMI_ASSERT(insert_key_data(&data2) == INSERT_SAME_KEY_CODE);
	set_key_data(&data3, KEY_3, KEY_3, KEY_EVENT_DOWN, MMI_FALSE, MMI_TRUE, MMI_FALSE);
	MMI_ASSERT(insert_key_data(&data3) == INSERT_CODE_BEYOND_DECT);
	g_key_cntx.keypad_status = key_pad_status;
	restore_key_data(data, &len);
	kal_prompt_trace(MOD_MMI, "[UT_KEY] test insert_key_data PASS");
	return MMI_RET_OK;  
}


/*****************************************************************************
 * FUNCTION
 *  ut_init_key_data_buf
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0007
 * <Test Case Content> init state of key data buffer
 * <Test Case Number> 1
 * <Scenario>
 *    case1: call init key data
 * <Expected Result>
 *    case1: key code should be KEY_INVALID, key type should be KEY_EVENT_UP, others should be 0
 *           The length of the buffer should be 0
 * </test case description>
 *
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret ut_init_key_data_buf(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 j;
	key_data_struct data[MAX_DECT_KEY_NUM];
	U8 len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    save_key_data(data, &len);
	init_key_data_buf();
    MMI_ASSERT(g_key_cntx.buf_len == 0);
    for (j = 0; j < MAX_DECT_KEY_NUM; j++)
    {
        MMI_ASSERT(g_key_cntx.buffer[j].mmi_key_code == KEY_INVALID);
        MMI_ASSERT(g_key_cntx.buffer[j].mmi_key_type == KEY_EVENT_UP);
        MMI_ASSERT(g_key_cntx.buffer[j].cvt_code == KEY_INVALID);
        MMI_ASSERT(g_key_cntx.buffer[j].is_clear == 0);
        MMI_ASSERT(g_key_cntx.buffer[j].is_2step== 0);
        MMI_ASSERT(g_key_cntx.buffer[j].is_combo== 0);
    }
	restore_key_data(data, &len);
	kal_prompt_trace(MOD_MMI, "[UT_KEY] test init_key_data_buf PASS!");
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ut_is_2step_key
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0006
 * <Test Case Content> judge a key is 2step key or not
 * <Test Case Number> 2
 * <Scenario>
 *    case1: set KEY CAMERA as 2step key, judge KEY_CAMERA
 *    case2: set KEY_CAMERA as 2step key, judge other keys
 * <Expected Result>
 *    case1: MMI_TRUE
 *    case2: MMI_FALSE
 * </test case description>
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret ut_is_2step_key(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __KBD_2STEP_KEY_SUPPORT__
    MMI_BOOL ret = MMI_FALSE;
    S16 i;
	U8 key_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	key_code = g_key_cntx._2step_key.mmi_key_code;
    g_key_cntx._2step_key.mmi_key_code = KEY_CAMERA;
    MMI_ASSERT(is_2step_key(KEY_CAMERA) == MMI_TRUE);
    for (i = KEY_0; i < MAX_KEY_NUM; i++)
    {
        if (i != KEY_CAMERA)
        {
            MMI_ASSERT(is_2step_key(i) == MMI_FALSE);
        }
    }
	g_key_cntx._2step_key.mmi_key_code = key_code;
	kal_prompt_trace(MOD_MMI, "[UT_KEY] test is_2step_key PASS");
#endif
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ut_is_legal_key_type
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0005
 * <Test Case Content> mmi key type transform flow
 * <Test Case Number> 26
 * <Scenario>
 *    case1: Non-2step key, framework or app level, curr key type = down, pre key type = up
 *    case2: Non-2step key, framework or app level, curr key type = down, pre key type = all but up
 *    case3: Non-2step key, framework or app level, curr key type = longpress, pre key type = down
 *    case4: Non-2step key, framework or app level, curr key type = longpress, pre key type = all but down
 *    case5: Non-2step key, framework or app level, curr key type = repeat, pre key type = repeat or longpress
 *    case6: Non-2step key, framework or app level, curr key type = repeat, pre key type = all but repeat and longpress
 *    case7: Non-2step key, framework or app level, curr key type = up, pre key type = down or repeat or longpress
 *    case8: Non-2step key, framework or app level, curr key type = up, pre key type = all but down ,repeat and longpress
 *    case9: 2step key, framework level, curr key type = half down, pre key type = up
 *    case10:2step key, framework level, curr key type = half down, pre key type = all but up
 *    case11:2step key, app level, curr key type = half down, pre key type = up or half up
 *    case12:2step key, app level, curr key type = half down, pre key type = all but up and half up
 *    case13:2step key, frm or app level, curr key type = full down, pre key type = half press down
 *    case14:2step key, frm or app level, curr key type = full down, pre key type = all but half press down
 *    case15:2step key, frm or app level, curr key type = longpress, pre key type = full down
 *    case16:2step key, frm or app level, curr key type = longpress, pre key type = all but full down
 *    case17:2step key, frm or app level, curr key type = repeat, pre key type = repeat or long press
 *    case18:2step key, frm or app level, curr key type = repeat, pre key type = all but repeat and long press
 *    case19:2step key, frm level, curr key type = half down
 *    case20:2step key, app level, curr key type = half up, pre key type = half down, full down, long press, repeat
 *    case21:2step key, app level, curr key type = half up, pre key type = all but half down, full down, long press, repeat
 *    case22:2step key, frm level, curr key type = up, pre key type = half down, full down, long press repeat
 *    case24:2step key, app level, curr key type = up, pre key type = half up, 2step key state = full down
 *    case25:2step key, app level, curr key type = up, pre key type = all but half up
 *    case26:2step key, app level, curr key type = up, pre key type = half up, 2step key state = half down
 * <Expected Result>
 *    case1: legal key type
 *    case2: illegal key type
 *    case3: legal key type
 *    case4: illegal key type
 *    case5: legal key type
 *    case6: illegal key type
 *    case7: legal key type
 *    case8: illegal key type
 *    case9: legal type
 *    case10:illegal key type
 *    case11:legal key type
 *    case12:illegal key type
 *    case13:legal key type
 *    case14:illegal key type
 *    case15:legal key type
 *    case16:illegal key type
 *    case17:legal key type
 *    case18:illegal key type
 *    case19:illegal key type
 *    case20:legal key type
 *    case21:illegal key type
 *    case22:legal key type
 *    case24:legal key type
 *    case25:illegal key type
 *    case26:illegal key type
 * </test case description>
 *
 * PARAMETERS
 *  para
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret ut_is_legal_key_type(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(is_legal_key_type(KEY_EVENT_DOWN, KEY_EVENT_DOWN, NON_TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_EVENT_DOWN, KEY_LONG_PRESS, NON_TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_EVENT_DOWN, KEY_REPEAT, NON_TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_EVENT_DOWN, KEY_EVENT_UP, NON_TWO_STEP_KEY) == MMI_TRUE);

    MMI_ASSERT(is_legal_key_type(KEY_LONG_PRESS, KEY_EVENT_DOWN, NON_TWO_STEP_KEY) == MMI_TRUE);
    MMI_ASSERT(is_legal_key_type(KEY_LONG_PRESS, KEY_LONG_PRESS, NON_TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_LONG_PRESS, KEY_REPEAT, NON_TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_LONG_PRESS, KEY_EVENT_UP, NON_TWO_STEP_KEY) == MMI_FALSE);    

    MMI_ASSERT(is_legal_key_type(KEY_REPEAT, KEY_EVENT_DOWN, NON_TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_REPEAT, KEY_LONG_PRESS, NON_TWO_STEP_KEY) == MMI_TRUE);
    MMI_ASSERT(is_legal_key_type(KEY_REPEAT, KEY_REPEAT, NON_TWO_STEP_KEY) == MMI_TRUE);
    MMI_ASSERT(is_legal_key_type(KEY_REPEAT, KEY_EVENT_UP, NON_TWO_STEP_KEY) == MMI_FALSE);

    MMI_ASSERT(is_legal_key_type(KEY_REPEAT, KEY_EVENT_DOWN, NON_TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_REPEAT, KEY_LONG_PRESS, NON_TWO_STEP_KEY) == MMI_TRUE);
    MMI_ASSERT(is_legal_key_type(KEY_REPEAT, KEY_REPEAT, NON_TWO_STEP_KEY) == MMI_TRUE);
    MMI_ASSERT(is_legal_key_type(KEY_REPEAT, KEY_EVENT_UP, NON_TWO_STEP_KEY) == MMI_FALSE); 

    MMI_ASSERT(is_legal_key_type(KEY_EVENT_UP, KEY_EVENT_DOWN, NON_TWO_STEP_KEY) == MMI_TRUE);
    MMI_ASSERT(is_legal_key_type(KEY_EVENT_UP, KEY_LONG_PRESS, NON_TWO_STEP_KEY) == MMI_TRUE);
    MMI_ASSERT(is_legal_key_type(KEY_EVENT_UP, KEY_REPEAT, NON_TWO_STEP_KEY) == MMI_TRUE);
    MMI_ASSERT(is_legal_key_type(KEY_EVENT_UP, KEY_EVENT_UP, NON_TWO_STEP_KEY) == MMI_FALSE);

#ifdef __KBD_2STEP_KEY_SUPPORT__
    MMI_ASSERT(is_legal_key_type(KEY_FULL_PRESS_DOWN, KEY_HALF_PRESS_DOWN, TWO_STEP_KEY) == MMI_TRUE);
    MMI_ASSERT(is_legal_key_type(KEY_FULL_PRESS_DOWN, KEY_FULL_PRESS_DOWN, TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_FULL_PRESS_DOWN, KEY_LONG_PRESS, TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_FULL_PRESS_DOWN, KEY_REPEAT, TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_FULL_PRESS_DOWN, KEY_EVENT_UP, TWO_STEP_KEY) == MMI_FALSE);

    MMI_ASSERT(is_legal_key_type(KEY_HALF_PRESS_DOWN, KEY_HALF_PRESS_DOWN, TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_HALF_PRESS_DOWN, KEY_FULL_PRESS_DOWN, TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_HALF_PRESS_DOWN, KEY_LONG_PRESS, TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_HALF_PRESS_DOWN, KEY_REPEAT, TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_HALF_PRESS_DOWN, KEY_EVENT_UP, TWO_STEP_KEY) == MMI_TRUE); 

    MMI_ASSERT(is_legal_key_type(KEY_LONG_PRESS, KEY_HALF_PRESS_DOWN, TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_LONG_PRESS, KEY_FULL_PRESS_DOWN, TWO_STEP_KEY) == MMI_TRUE);
    MMI_ASSERT(is_legal_key_type(KEY_LONG_PRESS, KEY_LONG_PRESS, TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_LONG_PRESS, KEY_REPEAT, TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_LONG_PRESS, KEY_EVENT_UP, TWO_STEP_KEY) == MMI_FALSE); 

    MMI_ASSERT(is_legal_key_type(KEY_REPEAT, KEY_HALF_PRESS_DOWN, TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_REPEAT, KEY_FULL_PRESS_DOWN, TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_REPEAT, KEY_LONG_PRESS, TWO_STEP_KEY) == MMI_TRUE);
    MMI_ASSERT(is_legal_key_type(KEY_REPEAT, KEY_REPEAT, TWO_STEP_KEY) == MMI_TRUE);
    MMI_ASSERT(is_legal_key_type(KEY_REPEAT, KEY_EVENT_UP, TWO_STEP_KEY) == MMI_FALSE); 

    MMI_ASSERT(is_legal_key_type(KEY_EVENT_UP, KEY_HALF_PRESS_DOWN, TWO_STEP_KEY) == MMI_TRUE);
    MMI_ASSERT(is_legal_key_type(KEY_EVENT_UP, KEY_FULL_PRESS_DOWN, TWO_STEP_KEY) == MMI_TRUE);
    MMI_ASSERT(is_legal_key_type(KEY_EVENT_UP, KEY_LONG_PRESS, TWO_STEP_KEY) == MMI_TRUE);
    MMI_ASSERT(is_legal_key_type(KEY_EVENT_UP, KEY_REPEAT, TWO_STEP_KEY) == MMI_TRUE);
    MMI_ASSERT(is_legal_key_type(KEY_EVENT_UP, KEY_EVENT_UP, TWO_STEP_KEY) == MMI_FALSE);
#endif
	kal_prompt_trace(MOD_MMI, "[UT_KEY] test is_legal_key_type PASS");
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ut_get_mmi_key_code
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0001
 * <Test Case Content> get mmi key code by device key code from key mapping table
 * <Test Case Number> 2
 * <Scenario>
 *    case1: Input normal device key code
 *    case2: Input device key code that is not in the mapping table
 * <Expected Result>
 *    case1: get the normal mmi key code
 *    case2: get KEY_INVALID
 * </test case description>
 *
 * PARAMETERS
 *  para
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret ut_get_mmi_key_code(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(get_mmi_key_code(DEVICE_KEY_0) == KEY_0);
    MMI_ASSERT(get_mmi_key_code(DEVICE_KEY_1) == KEY_1);
    MMI_ASSERT(get_mmi_key_code(DEVICE_KEY_FUNCTION) == KEY_CAMERA);
    MMI_ASSERT(get_mmi_key_code(DEVICE_KEY_MENU) == KEY_ENTER);
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    MMI_ASSERT(get_mmi_key_code(DEVICE_KEY_A) == KEY_A);
#endif
    MMI_ASSERT(get_mmi_key_code(DEVICE_KEY_EMAIL) == KEY_INVALID);
    MMI_ASSERT(get_mmi_key_code(MAX_DEVICE_KEYS) == KEY_INVALID);
    MMI_ASSERT(get_mmi_key_code(MAX_DEVICE_KEYS + 1) == KEY_INVALID);
#ifdef __SENDKEY2_SUPPORT__
    MMI_ASSERT(get_mmi_key_code(DEVICE_KEY_SEND2) == KEY_SEND);
#endif /* __SENDKEY2_SUPPORT__ */
	kal_prompt_trace(MOD_MMI, "[UT_KEY] test get_mmi_key_code PASS");
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ut_get_device_key_code
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0003
 * <Test Case Content> get device key code by mmi key code from key mapping table
 * <Test Case Number> 3
 * <Scenario>
 *    case1: Input normal mmi key code
 *    case2: Input mmi key code that is not in the mapping table(KEY_CSK)
 *    case3: Input illegal mmi key code
 *
 * <Expected Result>
 *    case1: get normal device key code
 *    case2: get DEVICE_KEY_NONE
 *    case3: get DEVICE_KEY_NONE
 *
 * </test case description>
 *
 * PARAMETERS
 *  para
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret ut_get_device_key_code(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(get_device_key_code(KEY_0) == DEVICE_KEY_0);
	MMI_ASSERT(get_device_key_code(KEY_ENTER) == DEVICE_KEY_MENU);
	MMI_ASSERT(get_device_key_code(KEY_SEND) == DEVICE_KEY_SEND);
    MMI_ASSERT(get_device_key_code(KEY_CSK) == DEVICE_KEY_MENU);
	MMI_ASSERT(get_device_key_code(KEY_LSK) == DEVICE_KEY_SK_LEFT);
    MMI_ASSERT(get_device_key_code(KEY_INVALID) == DEVICE_KEY_NONE);
	kal_prompt_trace(MOD_MMI, "[UT_KEY] test get_device_key_code PASS");
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ut_get_mmi_key_type
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0004
 * <Test Case Content> mapping device key event to framework level mmi key event
 * <Test Case Number> 5
 * <Scenario>
 *    case1: Input detection event
 *    case2: 2 step key, input: press, full press, longpress, repeat, release
 *    case3: non-2step key, input: press, longpress, repeat, release
 *    case4: input invalid key event
 *    case5: non-2step key, input full press
 *
 * <Expected Result>
 *    case1: get detection event type and key detection mode updated
 *    case2: get half down, full down, longpress, repeat, up
 *    case3: get down, longpress, repeat, up
 *    case4: assert
 *    case5: assert
 *
 * </test case description>
 *
 * PARAMETERS
 *  para
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret ut_get_mmi_key_type(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 keypad_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	keypad_status = g_key_cntx.keypad_status;
#if defined(__TWO_KEY_DETECTION_SWITCHABLE__) || defined(__THREE_KEY_DETECTION_SWITCHABLE__)	
    MMI_ASSERT(get_mmi_key_type(DRV_WM_ENABLE_TWOKEY_DETECTION, 0) == KEY_EVENT_DECT);
    MMI_ASSERT(GET_KEY_DET_MODE(g_key_cntx.keypad_status) == DCL_kbd_2_keys_det_mode);
#endif

#if defined(__THREE_KEY_DETECTION_SWITCHABLE__)
    MMI_ASSERT(get_mmi_key_type(DRV_WM_ENABLE_THREEKEY_DETECTION, 0) == KEY_EVENT_DECT);
    MMI_ASSERT(GET_KEY_DET_MODE(g_key_cntx.keypad_status) == DCL_kbd_3_keys_det_mode);
#endif	
    MMI_ASSERT(get_mmi_key_type(DRV_WM_DISABLE_MULTIKEY_DETECTION, MMI_FALSE) == KEY_EVENT_DECT);
    MMI_ASSERT(GET_KEY_DET_MODE(g_key_cntx.keypad_status) == DCL_kbd_1_key_det_mode);
#ifdef __KBD_2STEP_KEY_SUPPORT__
    MMI_ASSERT(get_mmi_key_type(DRV_WM_KEYPRESS, TWO_STEP_KEY) == KEY_HALF_PRESS_DOWN);
    MMI_ASSERT(get_mmi_key_type(DRV_WM_KEYRELEASE, TWO_STEP_KEY) == KEY_EVENT_UP);
    MMI_ASSERT(get_mmi_key_type(DRV_WM_KEYLONGPRESS, TWO_STEP_KEY) == KEY_LONG_PRESS);
    MMI_ASSERT(get_mmi_key_type(DRV_WM_KEYREPEATED, TWO_STEP_KEY) == KEY_REPEAT);
    MMI_ASSERT(get_mmi_key_type(DRV_WM_KEYFULLPRESS, TWO_STEP_KEY) == KEY_FULL_PRESS_DOWN);
#endif
    MMI_ASSERT(get_mmi_key_type(DRV_WM_KEYPRESS, NON_TWO_STEP_KEY) == KEY_EVENT_DOWN);
    MMI_ASSERT(get_mmi_key_type(DRV_WM_KEYRELEASE, NON_TWO_STEP_KEY) == KEY_EVENT_UP);
    MMI_ASSERT(get_mmi_key_type(DRV_WM_KEYLONGPRESS, NON_TWO_STEP_KEY) == KEY_LONG_PRESS);
    MMI_ASSERT(get_mmi_key_type(DRV_WM_KEYREPEATED, NON_TWO_STEP_KEY) == KEY_REPEAT);

    MMI_ASSERT(get_mmi_key_type(DRV_WM_KEYFULLPRESS, NON_TWO_STEP_KEY) == ERR_KEY_EVENT);
    MMI_ASSERT(get_mmi_key_type(50, NON_TWO_STEP_KEY) == ERR_KEY_EVENT);
	g_key_cntx.keypad_status = keypad_status;
	kal_prompt_trace(MOD_MMI, "[UT_KEY] test get_mmi_key_type PASS");
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ut_get_rotated_mmi_key_code
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0004
 * <Test Case Content> judge is full ctrl key
 * <Test Case Number> 5
 * <Scenario>
 *    case 1: input KEY_UP_ARROW
 *    case 2: input KEY_DOWN_ARROW
 *    case 3: input KEY_LEFT_ARROW
 *    case 4: input KEY_RIGHT_ARROW
 *    case 5: input KEY_0
 * <Expected Result>
 *    case 1: output KEY_LEFT_ARROW
 *    case 2: output KEY_RIGHT_ARROW
 *    case 3: output KEY_DOWN_ARROW
 *    case 4: output KEY_UP_ARROW
 *    case 5: output KEY_0
 * </test case description>
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret ut_get_rotated_mmi_key_code(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 rotate;;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SCREEN_ROTATE__
    rotate = mmi_frm_get_screen_rotate();
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
    MMI_ASSERT(get_rotated_mmi_key_code(KEY_UP_ARROW) == KEY_LEFT_ARROW);
    MMI_ASSERT(get_rotated_mmi_key_code(KEY_DOWN_ARROW) == KEY_RIGHT_ARROW);
    MMI_ASSERT(get_rotated_mmi_key_code(KEY_LEFT_ARROW) == KEY_DOWN_ARROW);
    MMI_ASSERT(get_rotated_mmi_key_code(KEY_RIGHT_ARROW) == KEY_UP_ARROW);
    MMI_ASSERT(get_rotated_mmi_key_code(KEY_0) == KEY_0);
    mmi_frm_screen_rotate(rotate);
#endif /* __MMI_SCREEN_ROTATE__ */
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test get_rotated_mmi_key_code PASS");
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  ut_get_key_data
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0004
 * <Test Case Content> judge is full ctrl key
 * <Test Case Number> 5
 * <Scenario>
 *
 * <Expected Result>
 *
 *
 * </test case description>
 *
 * PARAMETERS
 *  para
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret ut_get_key_data(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    key_data_struct data;
	key_data_struct buffer[MAX_DECT_KEY_NUM];
	U8 len;
	U8 keypad_status;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	save_key_data(buffer, &len);
	keypad_status = g_key_cntx.keypad_status;
	SET_KEY_DET_MODE(g_key_cntx.keypad_status, (U8)DCL_kbd_2_keys_det_mode);
    g_key_cntx.buffer[0].mmi_key_code = 1;
    g_key_cntx.buffer[0].mmi_key_type = 15;
    g_key_cntx.buffer[0].is_2step     = 0;
    g_key_cntx.buffer[0].is_clear     = 1;
    g_key_cntx.buffer[0].is_combo     = 0;
    g_key_cntx.buffer[1].mmi_key_code = 18;
    g_key_cntx.buffer[1].mmi_key_type = 25;
    g_key_cntx.buffer[1].is_2step     = 0;
    g_key_cntx.buffer[1].is_clear     = 1;
    g_key_cntx.buffer[1].is_combo     = 0;
    get_key_data(&data, 0);
    MMI_ASSERT(key_data_cmp(&data, &g_key_cntx.buffer[0]));
    get_key_data(&data, 1);
    MMI_ASSERT(key_data_cmp(&data, &g_key_cntx.buffer[1]));

	restore_key_data(buffer, &len);
	g_key_cntx.keypad_status = keypad_status;
	kal_prompt_trace(MOD_MMI, "[UT_KEY] test get key data PASS");
	return MMI_RET_OK;	
}


/*****************************************************************************
 * FUNCTION
 *  ut_set_all_key_data_clear
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0004
 * <Test Case Content> judge is full ctrl key
 * <Test Case Number> 5
 * <Scenario>
 *     1. 2step key, up
 * <Expected Result>
 *     1. FULL_UP
 * </test case description>
 *
 * PARAMETERS
 *  para
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret ut_set_all_key_data_clear(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	key_data_struct buffer[MAX_DECT_KEY_NUM];
	U8 len;
	U8 keypad_status;
	key_data_struct data1;
	key_data_struct data2;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	save_key_data(buffer, &len);
	keypad_status = g_key_cntx.keypad_status;
	SET_KEY_DET_MODE(g_key_cntx.keypad_status, (U8)DCL_kbd_2_keys_det_mode);
	init_key_data_buf();
	set_key_data(&data1, KEY_0, KEY_0, 0, 0, 0, 0);
	set_key_data(&data2, KEY_1, KEY_1, 0, 0, 0, 0);
	insert_key_data(&data1);
	insert_key_data(&data2);
	set_all_key_data_clear();
	MMI_ASSERT(g_key_cntx.buffer[0].is_clear == MMI_TRUE);
	MMI_ASSERT(g_key_cntx.buffer[1].is_clear == MMI_TRUE);
	restore_key_data(buffer, &len);
	g_key_cntx.keypad_status = keypad_status;
	kal_prompt_trace(MOD_MMI, "[UT_KEY] test set_all_key_data_clear PASS");
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ut_update_clear_state
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0004
 * <Test Case Content>
 * <Test Case Number>
 * <Scenario>
 *     1. 2step key, up
 * <Expected Result>
 *     1. FULL_UP
 * </test case description>
 *
 * PARAMETERS
 *  para
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret ut_update_clear_state(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	key_data_struct buffer[MAX_DECT_KEY_NUM];
	U8 len;
	U8 keypad_status;
	key_data_struct data1;
	key_data_struct data2;
	mmi_key_evt_struct evt;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	save_key_data(buffer, &len);
	keypad_status = g_key_cntx.keypad_status;
	SET_KEY_DET_MODE(g_key_cntx.keypad_status, (U8)DCL_kbd_2_keys_det_mode);
	init_key_data_buf();
	set_key_data(&data1, KEY_0, KEY_0, 0, 0, 0, 0);
	set_key_data(&data2, KEY_1, KEY_1, 0, 0, 0, 0);
	insert_key_data(&data1);
	insert_key_data(&data2);
    evt.mmi_key_code = KEY_0;
	evt.is_clear = MMI_FALSE;
	g_key_cntx.buffer[0].is_clear = MMI_TRUE;
	update_clear_state(&evt);
	MMI_ASSERT(evt.is_clear == MMI_TRUE);
	g_key_cntx.buffer[1].is_clear = MMI_TRUE;
	evt.is_clear= MMI_FALSE;
	update_clear_state(&evt);
	MMI_ASSERT(&evt);
	restore_key_data(buffer, &len);
	g_key_cntx.keypad_status = keypad_status;
	kal_prompt_trace(MOD_MMI, "[UT_KEY] test update_clear_state PASS");
	return MMI_RET_OK;

}

/*****************************************************************************
 * FUNCTION
 *  ut_post_update_2step_key_state
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0004
 * <Test Case Content> judge is full ctrl key
 * <Test Case Number> 5
 * <Scenario>
 *     1. 2step key, up
 *     2. 2step key, other key event
 *     3. non-2step key
 * <Expected Result>
 *     1. FULL_UP
 *     2. no change
 *     3. no change
 * </test case description>
 *
 * PARAMETERS
 *  para
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret ut_post_update_2step_key_state(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __KBD_2STEP_KEY_SUPPORT__
    S32 i;
	U8 key_code;
	U8 state;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	key_code = g_key_cntx._2step_key.mmi_key_code;
	state = g_key_cntx._2step_key.state;	
    g_key_cntx._2step_key.mmi_key_code = KEY_CAMERA;
    g_key_cntx._2step_key.state = 255;
    for (i = 0; i < MAX_KEY_TYPE; i++)
    {
        if (i != KEY_EVENT_UP)
        {
            post_update_2step_key_state(KEY_CAMERA, (U8)i);
            MMI_ASSERT(g_key_cntx._2step_key.state == 255);
        }
        post_update_2step_key_state(KEY_0, (U8)i);
        MMI_ASSERT(g_key_cntx._2step_key.state == 255);
    }
    post_update_2step_key_state(KEY_CAMERA, KEY_EVENT_UP);
    MMI_ASSERT(g_key_cntx._2step_key.state == FULL_UP);
	g_key_cntx._2step_key.mmi_key_code = key_code;
	g_key_cntx._2step_key.state = state;
	kal_prompt_trace(MOD_MMI, "[UT_KEY] test post_update_2step_key_state PASS");
#endif
	return MMI_RET_OK;	
}


/*****************************************************************************
 * FUNCTION
 *  ut_pre_update_2step_key_state
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0004
 * <Test Case Content> judge is full ctrl key
 * <Test Case Number> 5
 * <Scenario>
 *     1. 2step key, half down
 *     2. 2step key, full down
 *     3. 2step key, other key event
 *     4. non-2step key
 * <Expected Result>
 *     1. HALF_DOWN
 *     2. FULL_DOWN
 *     3. no change
 *     4. no change
 * </test case description>
 *
 * PARAMETERS
 *  para
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret ut_pre_update_2step_key_state(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __KBD_2STEP_KEY_SUPPORT__
    U8 i;
	U8 key_code;
	U8 state;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	key_code = g_key_cntx._2step_key.mmi_key_code;
	state = g_key_cntx._2step_key.state;
    g_key_cntx._2step_key.mmi_key_code = KEY_CAMERA;
    g_key_cntx._2step_key.state = 255;
    for (i = 0; i < MAX_KEY_TYPE; i++)
    {
        if (i != KEY_HALF_PRESS_DOWN && i != KEY_FULL_PRESS_DOWN)
        {
            pre_update_2step_key_state(KEY_CAMERA, i);
            MMI_ASSERT(g_key_cntx._2step_key.state == 255);
        }
        pre_update_2step_key_state(KEY_0, i);
        MMI_ASSERT(g_key_cntx._2step_key.state == 255);        
    }
    pre_update_2step_key_state(KEY_CAMERA, KEY_HALF_PRESS_DOWN);
    MMI_ASSERT(g_key_cntx._2step_key.state == HALF_DOWN);

    pre_update_2step_key_state(KEY_CAMERA, KEY_FULL_PRESS_DOWN);
    MMI_ASSERT(g_key_cntx._2step_key.state == FULL_DOWN);
	g_key_cntx._2step_key.mmi_key_code = key_code;
	g_key_cntx._2step_key.state = state;
	kal_prompt_trace(MOD_MMI, "[UT_KEY] test pre_update_2step_key_state PASS");
#endif
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ut_pre_update_2step_key_state
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0004
 * <Test Case Content> 
 * <Test Case Number> 0
 * <Scenario>
 *     1. 2step key, half down
 *     2. 2step key, full down
 *     3. 2step key, other key event
 *     4. non-2step key
 * <Expected Result>
 *     1. HALF_DOWN
 *     2. FULL_DOWN
 *     3. no change
 *     4. no change
 * </test case description>
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret ut_gen_key_data(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_key_evt_struct evt;
	key_data_struct data;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	evt.mmi_key_code = KEY_0;
    evt.cvt_code = KEY_0;
	evt.mmi_key_type = KEY_EVENT_DOWN;
	evt.is_clear = MMI_FALSE;
	gen_key_data(&evt, &data);
	MMI_ASSERT(data.mmi_key_code == KEY_0);
    MMI_ASSERT(data.cvt_code == KEY_0);
	MMI_ASSERT(data.mmi_key_type == KEY_EVENT_DOWN);
	MMI_ASSERT(data.is_clear == MMI_FALSE);
	kal_prompt_trace(MOD_MMI, "[UT_KEY] test gen_key_data PASS");
	return MMI_RET_OK;
}

mmi_ret ut_get_any_key_handler(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__    
    S16 key_code;
    S16 key_type;
#endif    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    for (key_type = KEY_EVENT_DOWN; key_type < MAX_KEY_TYPE; key_type++)
    {
        anyKeyFuncPtrs[key_type] = (FuncPtr)key_type;
    }
    for (key_code = KEY_A; key_code < MAX_QWERTY_KEYS; key_code++)
    {
        for (key_type = KEY_EVENT_DOWN; key_type < MAX_KEY_TYPE; key_type++)
        {
            MMI_ASSERT(get_any_key_handler(key_code, key_type) == (FuncPtr)key_type);
        }
    }
#endif
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test get any key handler PASS");
    return MMI_RET_OK;
}

void save_look_ahead_buffer(dev_key_evt_struct *p, U8* r, U8* w, U8 *n)
{
    memcpy(p, g_key_cntx.look_ahead, sizeof(g_key_cntx.look_ahead));
    *r = g_key_cntx.r_look_ahead;
    *w = g_key_cntx.w_look_ahead;
    *n = g_key_cntx.num_look_ahead;
}
void restore_look_ahead_buffer(dev_key_evt_struct *p, U8 *r, U8* w, U8 *n)
{
    memcpy(g_key_cntx.look_ahead, p, sizeof(g_key_cntx.look_ahead));
    g_key_cntx.r_look_ahead = *r;
    g_key_cntx.w_look_ahead = *w;
    g_key_cntx.num_look_ahead = *n;
}
mmi_ret ut_read_look_ahead_buffer(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dev_key_evt_struct buf[LOOK_AHEAD_BUF_LEN];
    U8 r;
    U8 w;
    U8 n;
    S32 i;
    U8 *rp = &g_key_cntx.r_look_ahead;
    U8 *wp = &g_key_cntx.w_look_ahead;
    U8 *np = &g_key_cntx.num_look_ahead;
    dev_key_evt_struct dev;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    save_look_ahead_buffer(buf, &r, &w, &n);
    for (i = 0; i < LOOK_AHEAD_BUF_LEN; i++)
    {
        g_key_cntx.look_ahead[i].device_key_code = i;
    }
    for (*rp = 0; *rp < LOOK_AHEAD_BUF_LEN; (*rp)++)
    {
        for (*wp = 0; *wp < LOOK_AHEAD_BUF_LEN; (*wp)++)
        {
            U8 temp_r = *rp;
            if (*wp > *rp)
            {
                *np = *wp - *rp;

                MMI_ASSERT(read_look_ahead_buffer(&dev) == MMI_TRUE);
                MMI_ASSERT(dev.device_key_code == temp_r);
                MMI_ASSERT(g_key_cntx.r_look_ahead == ((++temp_r) % LOOK_AHEAD_BUF_LEN));
            }
            else if (*wp < *rp)
            {
                *np = LOOK_AHEAD_BUF_LEN - (*rp - *wp);

                MMI_ASSERT(read_look_ahead_buffer(&dev) == MMI_TRUE);
                MMI_ASSERT(dev.device_key_code == temp_r);
                MMI_ASSERT(g_key_cntx.r_look_ahead == ((++temp_r) % LOOK_AHEAD_BUF_LEN));
            }
            else
            {
                *np = 0;

                MMI_ASSERT(read_look_ahead_buffer(&dev) == MMI_FALSE);
                MMI_ASSERT(g_key_cntx.r_look_ahead == temp_r);
                *np = LOOK_AHEAD_BUF_LEN;
                MMI_ASSERT(read_look_ahead_buffer(&dev) == MMI_TRUE);
                MMI_ASSERT(dev.device_key_code == temp_r);
                MMI_ASSERT(g_key_cntx.r_look_ahead == ((++temp_r) % LOOK_AHEAD_BUF_LEN));
            }
             *rp = temp_r;
        }
    }
    restore_look_ahead_buffer(buf, &r, &w, &n);
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test read_look_ahead_buffer PASS");
    return MMI_RET_OK;
}

mmi_ret ut_write_look_ahead_buffer(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dev_key_evt_struct buf[LOOK_AHEAD_BUF_LEN];
    U8 r;
    U8 w;
    U8 n;
    U8 *rp = &g_key_cntx.r_look_ahead;
    U8 *wp = &g_key_cntx.w_look_ahead;
    U8 *np = &g_key_cntx.num_look_ahead;
    dev_key_evt_struct dev;    
    
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    save_look_ahead_buffer(buf, &r, &w, &n);
    
    for (*rp = 0; *rp < LOOK_AHEAD_BUF_LEN; (*rp)++)
    {
        for (*wp = 0; *wp < LOOK_AHEAD_BUF_LEN; (*wp)++)
        {
            U8 temp_w = *wp;
            if (*wp > *rp)
            {
                *np = *wp - *rp;
                dev.device_key_code = *wp;
                MMI_ASSERT(write_look_ahead_buffer(&dev) == MMI_TRUE);
                MMI_ASSERT(g_key_cntx.look_ahead[temp_w].device_key_code == temp_w);
                MMI_ASSERT(g_key_cntx.w_look_ahead == (++temp_w) % LOOK_AHEAD_BUF_LEN);       
            } 
            else if (*wp < *rp)
            {
                *np = LOOK_AHEAD_BUF_LEN - (*rp - *wp);
                dev.device_key_code = *wp;
                MMI_ASSERT(write_look_ahead_buffer(&dev) == MMI_TRUE);
                MMI_ASSERT(g_key_cntx.look_ahead[temp_w].device_key_code == temp_w);
                MMI_ASSERT(g_key_cntx.w_look_ahead == (++temp_w) % LOOK_AHEAD_BUF_LEN);
            }
            else
            {
                *np = LOOK_AHEAD_BUF_LEN;
                MMI_ASSERT(write_look_ahead_buffer(&dev) == MMI_FALSE);
                *np = 0;
                dev.device_key_code = *wp;
                MMI_ASSERT(write_look_ahead_buffer(&dev) == MMI_TRUE);
                MMI_ASSERT(g_key_cntx.look_ahead[temp_w].device_key_code == temp_w);
                MMI_ASSERT(g_key_cntx.w_look_ahead == (++temp_w) % LOOK_AHEAD_BUF_LEN);

            }    
            *wp = temp_w;
        }
    }
    restore_look_ahead_buffer(buf, &r, &w, &n);
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test write_look_ahead_buffer PASS");
    return MMI_RET_OK;    
}

mmi_ret ut_is_combo_key(void *para)
{
    U32 i;
#ifndef __MMI_QWERTY_KEYPAD_SUPPORT__
    for (i = 0; i < MAX_KEY_NUM; i++)
    {
        MMI_ASSERT(is_combo_key(i) == MMI_FALSE);
    }
#else
    for (i = 0; i < MAX_KEY_NUM; i++)
    {
        if (i == KEY_FN || i == KEY_SHIFT || i == KEY_CTRL || i == KEY_ALT)
        {
            MMI_ASSERT(is_combo_key((S16)i) == MMI_TRUE);
        }
        else
        {
            MMI_ASSERT(is_combo_key((S16)i) == MMI_FALSE);
        }
    }
#endif
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test is_combo_key PASS");
    return MMI_RET_OK;
}

/************************************************************************/
/* Test for keypad pointer change                                       */
/************************************************************************/
typedef struct
{
    drv_get_key_func old_ptr;
    drv_get_key_func new_ptr;
    MMI_BOOL is_keypad_busy;
} key_ptr_change;
U8 buffer1_data_num;
kal_bool drv_buffer1(kbd_data *p)
{
    buffer1_data_num = 0;
    return KAL_FALSE;
}
U8 buffer2_data_num; 
kal_bool drv_buffer2(kbd_data *p)
{
    buffer2_data_num = 0;
    return KAL_FALSE;
}
const key_ptr_change ptr_change_data[] = 
{
    {NULL, drv_buffer1, MMI_FALSE},
    {drv_buffer1, drv_buffer1, MMI_TRUE},
    {drv_buffer1, drv_buffer1, MMI_FALSE},
    {drv_buffer1, drv_buffer2, MMI_TRUE},
    {drv_buffer1, drv_buffer2, MMI_FALSE},
};

mmi_ret ut_process_key_ptr_change(void *para)
{
    U32 i;
    mmi_eq_keypad_detect_ind_struct k;
    process_key_ptr_change(NULL);
    for (i = 0; i < sizeof(ptr_change_data) / sizeof(ptr_change_data[0]); i++)
    {        
        k.func = ptr_change_data[i].new_ptr;
        get_key_evt_func[g_key_cntx.l4_keypad_mode] = ptr_change_data[i].old_ptr;
        if (ptr_change_data[i].is_keypad_busy == MMI_TRUE)
        {
            g_key_cntx.buf_len = 1;
            buffer2_data_num = 15;
        }
        else
        {
            buffer1_data_num = 15;
            g_key_cntx.buf_len = 0;
        }    
        process_key_ptr_change(&k);
        if (get_key_evt_func[g_key_cntx.l4_keypad_mode] != ptr_change_data[i].old_ptr &&
            ptr_change_data[i].is_keypad_busy == MMI_FALSE)
        {
            MMI_ASSERT(get_key_evt_func[g_key_cntx.l4_keypad_mode]  == ptr_change_data[i].new_ptr);
            if (ptr_change_data[i].old_ptr != NULL)
                MMI_ASSERT(buffer1_data_num == 0);
        }
        else
        {
            MMI_ASSERT( get_key_evt_func[g_key_cntx.l4_keypad_mode] == ptr_change_data[i].old_ptr);
            if (ptr_change_data[i].old_ptr != ptr_change_data[i].new_ptr)
            {
                MMI_ASSERT(buffer2_data_num == 0);
            }
        }
    }
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test process_key_ptr_change PASS");
    return MMI_RET_OK;
}

/*************************************************************************************
 * Unit test for mmi_frm_clear_key_events
 *************************************************************************************/
const dev_key_evt_struct  clear_event_in_data1[] =
{
    {DEVICE_KEY_END, DRV_WM_KEYPRESS,     MMI_FALSE},
    {DEVICE_KEY_END, DRV_WM_KEYLONGPRESS, MMI_FALSE},
    {DEVICE_KEY_END, DRV_WM_KEYRELEASE,   MMI_FALSE},
    {DEVICE_KEY_END, DRV_WM_KEYPRESS,     MMI_FALSE},
    {DEVICE_KEY_END, DRV_WM_KEYLONGPRESS, MMI_FALSE},
    {DEVICE_KEY_END, DRV_WM_KEYRELEASE,   MMI_FALSE},
    {DEVICE_KEY_END, DRV_WM_KEYPRESS,     MMI_FALSE},
    {DEVICE_KEY_END, DRV_WM_KEYLONGPRESS, MMI_FALSE},
    {DEVICE_KEY_END, DRV_WM_KEYRELEASE,   MMI_FALSE},
    {DEVICE_KEY_NONE, 0, 0}
};

const dev_key_evt_struct clear_event_out_data1[] =
{
    {DEVICE_KEY_END, DRV_WM_KEYLONGPRESS, MMI_FALSE},
    {DEVICE_KEY_NONE, 0, 0}
};

const U8 active_key_codes1[] = {KEY_1, KEY_INVALID};

const dev_key_evt_struct  clear_event_in_data2[] =
{
    {DEVICE_KEY_1, DRV_WM_KEYRELEASE,     MMI_FALSE},
    {DEVICE_KEY_2, DRV_WM_KEYRELEASE,     MMI_FALSE},   
    {DEVICE_KEY_NONE, 0, 0}
};

const dev_key_evt_struct clear_event_out_data2[] =
{
    {DEVICE_KEY_1, DRV_WM_KEYRELEASE,     MMI_FALSE},
    {DEVICE_KEY_2, DRV_WM_KEYRELEASE,     MMI_FALSE},      
    {DEVICE_KEY_NONE, 0, 0}
};

const U8 active_key_codes2[] = {KEY_1, KEY_2, KEY_INVALID};

const dev_key_evt_struct  clear_event_in_data3[] =
{
    {DEVICE_KEY_1, DRV_WM_KEYRELEASE,     MMI_FALSE},
    {DEVICE_KEY_NONE, 0, 0}
};

const dev_key_evt_struct clear_event_out_data3[] =
{
    {DEVICE_KEY_1, DRV_WM_KEYRELEASE,     MMI_FALSE},
    {DEVICE_KEY_NONE, 0, 0}
};

const U8 active_key_codes3[] = {KEY_1, KEY_INVALID, KEY_INVALID};
const dev_key_evt_struct  clear_event_in_data4[] =
{
    {DEVICE_KEY_NONE, 0, 0}
};

const dev_key_evt_struct clear_event_out_data4[] =
{
    {DEVICE_KEY_NONE, 0, 0}
};

const U8 active_key_codes4[] = {KEY_1, KEY_INVALID};

const dev_key_evt_struct  clear_event_in_data5[] =
{
    {DEVICE_KEY_1, DRV_WM_KEYPRESS,     MMI_FALSE},    
    {DEVICE_KEY_1, DRV_WM_KEYRELEASE,     MMI_FALSE}, 
    {DEVICE_KEY_2, DRV_WM_KEYPRESS,     MMI_FALSE},    
    {DEVICE_KEY_2, DRV_WM_KEYRELEASE,     MMI_FALSE},     
    {DEVICE_KEY_NONE, 0, 0}
};

const dev_key_evt_struct clear_event_out_data5[] =
{
    {DEVICE_KEY_NONE, 0, 0}
};

const U8 active_key_codes5[] = {KEY_INVALID};


const dev_key_evt_struct  clear_event_in_data6[] =
{
    {DEVICE_KEY_1,  DRV_WM_KEYRELEASE,     MMI_FALSE},    
    {DEVICE_KEY_END, DRV_WM_KEYPRESS,     MMI_FALSE}, 
    {DEVICE_KEY_END, DRV_WM_KEYLONGPRESS,     MMI_FALSE},    
    {DEVICE_KEY_END, DRV_WM_KEYREPEATED,     MMI_FALSE},     
    {DEVICE_KEY_NONE, 0, 0}
};

const dev_key_evt_struct clear_event_out_data6[] =
{
    {DEVICE_KEY_1,   DRV_WM_KEYRELEASE,     MMI_FALSE},
    {DEVICE_KEY_END, DRV_WM_KEYLONGPRESS,     MMI_FALSE},
    {DEVICE_KEY_NONE, 0, 0}
};

const U8 active_key_codes6[] = {KEY_1, KEY_INVALID};


const dev_key_evt_struct  clear_event_in_data7[] =
{
    {DEVICE_KEY_END,  DRV_WM_KEYRELEASE,     MMI_FALSE},    
    {DEVICE_KEY_END, DRV_WM_KEYPRESS,     MMI_FALSE}, 
    {DEVICE_KEY_END, DRV_WM_KEYLONGPRESS,     MMI_FALSE},    
    {DEVICE_KEY_END, DRV_WM_KEYRELEASE,     MMI_FALSE},
    {DEVICE_KEY_END, DRV_WM_KEYPRESS,     MMI_FALSE}, 
    {DEVICE_KEY_END, DRV_WM_KEYLONGPRESS,     MMI_FALSE},    
    {DEVICE_KEY_END, DRV_WM_KEYRELEASE,     MMI_FALSE},   
    {DEVICE_KEY_NONE, 0, 0}
};

const dev_key_evt_struct clear_event_out_data7[] =
{
    {DEVICE_KEY_END, DRV_WM_KEYRELEASE,     MMI_FALSE},
    {DEVICE_KEY_END, DRV_WM_KEYLONGPRESS,     MMI_FALSE},
    {DEVICE_KEY_NONE, 0, 0}
};

const U8 active_key_codes7[] = {KEY_END, KEY_INVALID};


const dev_key_evt_struct  clear_event_in_data8[] =
{
    {DEVICE_KEY_1,   DRV_WM_KEYRELEASE,     MMI_FALSE},    
    {DEVICE_KEY_2,   DRV_WM_KEYRELEASE,     MMI_FALSE}, 
    {0, DRV_WM_DISABLE_MULTIKEY_DETECTION,     MMI_FALSE},    
    {DEVICE_KEY_3,   DRV_WM_KEYPRESS,       MMI_FALSE},
    {DEVICE_KEY_3,   DRV_WM_KEYRELEASE,     MMI_FALSE}, 
    {0, DRV_WM_ENABLE_TWOKEY_DETECTION,     MMI_FALSE},    
    {DEVICE_KEY_1,   DRV_WM_KEYRELEASE,     MMI_FALSE},    
    {DEVICE_KEY_2,   DRV_WM_KEYRELEASE,     MMI_FALSE}, 
    {0, DRV_WM_DISABLE_MULTIKEY_DETECTION,     MMI_FALSE},    
    {DEVICE_KEY_3,   DRV_WM_KEYPRESS,       MMI_FALSE},
    {DEVICE_KEY_3,   DRV_WM_KEYRELEASE,     MMI_FALSE}, 
    {0, DRV_WM_ENABLE_TWOKEY_DETECTION,     MMI_FALSE},
    {DEVICE_KEY_NONE, 0, 0}
};

const dev_key_evt_struct clear_event_out_data8[] =
{
    {DEVICE_KEY_1,   DRV_WM_KEYRELEASE,     MMI_FALSE},    
    {DEVICE_KEY_2,   DRV_WM_KEYRELEASE,     MMI_FALSE}, 
    {0, DRV_WM_ENABLE_TWOKEY_DETECTION,     MMI_FALSE}, 
    {DEVICE_KEY_NONE, 0, 0}
};

const U8 active_key_codes8[] = {KEY_1, KEY_2, KEY_INVALID};


const dev_key_evt_struct  clear_event_in_data9[] =
{
    {0, DRV_WM_ENABLE_TWOKEY_DETECTION,     MMI_FALSE},
	{DEVICE_KEY_END, DRV_WM_KEYPRESS,     MMI_FALSE}, 
    {DEVICE_KEY_END, DRV_WM_KEYLONGPRESS,     MMI_FALSE},    
    {DEVICE_KEY_END, DRV_WM_KEYRELEASE,     MMI_FALSE},   
    {DEVICE_KEY_NONE, 0, 0}
};

const dev_key_evt_struct clear_event_out_data9[] =
{
    {0, DRV_WM_ENABLE_TWOKEY_DETECTION,     MMI_FALSE},
    {DEVICE_KEY_END, DRV_WM_KEYLONGPRESS,     MMI_FALSE},   
    {DEVICE_KEY_NONE, 0, 0}
};
const U8 active_key_codes9[] = {KEY_INVALID};


const dev_key_evt_struct  clear_event_in_data10[] =
{
	{DEVICE_KEY_END, DRV_WM_KEYPRESS,     MMI_FALSE}, 
    {0, DRV_WM_ENABLE_TWOKEY_DETECTION,     MMI_FALSE},
    {DEVICE_KEY_END, DRV_WM_KEYRELEASE,     MMI_FALSE},   
    {DEVICE_KEY_NONE, 0, 0}
};

const dev_key_evt_struct clear_event_out_data10[] =
{
    {0, DRV_WM_ENABLE_TWOKEY_DETECTION,     MMI_FALSE},
    {DEVICE_KEY_END, DRV_WM_KEYRELEASE,     MMI_FALSE},  
    {DEVICE_KEY_NONE, 0, 0}
};


const U8 active_key_codes10[] = {KEY_END, KEY_INVALID};

typedef struct
{
    const dev_key_evt_struct *in;
    const dev_key_evt_struct *out;
    const U8* active_key_code;
} test_clear_event_data;

const test_clear_event_data clear_evt_data[] =
{
    {clear_event_in_data1, clear_event_out_data1, active_key_codes1},
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__    
    {clear_event_in_data2, clear_event_out_data2, active_key_codes2},
#endif   
    {clear_event_in_data3, clear_event_out_data3, active_key_codes3},
    {clear_event_in_data4, clear_event_out_data4, active_key_codes4},
    {clear_event_in_data5, clear_event_out_data5, active_key_codes5},
    {clear_event_in_data6, clear_event_out_data6, active_key_codes6},
    {clear_event_in_data7, clear_event_out_data7, active_key_codes7},
    {clear_event_in_data8, clear_event_out_data8, active_key_codes8},
    {clear_event_in_data9, clear_event_out_data9, active_key_codes9},
    {clear_event_in_data10, clear_event_out_data10, active_key_codes10}
};

#define CLEAR_KEY_EVENT_TEST_CASE_NUM sizeof(clear_evt_data) / sizeof(clear_evt_data[0])
mmi_ret ut_mmi_frm_clear_key_events(void *para)
{
    U32 i;
    U32 j;
    dev_key_evt_struct dev;
    key_data_struct data;
	SET_KEY_DET_MODE(g_key_cntx.keypad_status, DCL_kbd_2_keys_det_mode);
    for (i = 0; i < CLEAR_KEY_EVENT_TEST_CASE_NUM; i++)
    {
        init_key_data_buf();
        j = 0;
        while(clear_evt_data[i].in[j].device_key_code != DEVICE_KEY_NONE)
        {
            write_look_ahead_buffer((dev_key_evt_struct *)&(clear_evt_data[i].in[j]));
            j++;
        }
        j = 0;
        while (clear_evt_data[i].active_key_code && clear_evt_data[i].active_key_code [j] != KEY_INVALID)
        {
            data.mmi_key_code = clear_evt_data[i].active_key_code[j];
            data.is_clear = MMI_FALSE;
            insert_key_data(&data);
            j++;
        }
        MMI_ASSERT(g_key_cntx.buf_len == j);
        mmi_frm_clear_key_events();
        j = 0;
        while(clear_evt_data[i].out[j].device_key_code != DEVICE_KEY_NONE)
        {
            MMI_ASSERT(read_look_ahead_buffer(&dev) == MMI_TRUE);
            MMI_ASSERT(dev.device_key_code == clear_evt_data[i].out[j].device_key_code);
            MMI_ASSERT(dev.device_key_type == clear_evt_data[i].out[j].device_key_type);
            MMI_ASSERT(dev.is_clear == clear_evt_data[i].out[j].is_clear);
            j++;
        }
        MMI_ASSERT(read_look_ahead_buffer(&dev) == MMI_FALSE);
        for (j = 0; j < g_key_cntx.buf_len;j++)
        {
            MMI_ASSERT(g_key_cntx.buffer[j].is_clear == MMI_TRUE);
        }
   
    }    
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test mmi_frm_clear_key_events PASS");
    return MMI_RET_OK;
}

/****************************************************************
 *  Unit test for is_need_write_back
 ****************************************************************/
typedef struct
{
    dev_key_evt_struct  test_evt;
    MMI_BOOL is_active;
    U8 len;
    dev_key_evt_struct  temp_buffer[2];
    MMI_BOOL res;
} test_write_back_data;

test_write_back_data _wb_data[] =
{
    /************************************************************************/
    /*    Normal key up write back case                                     */
    /************************************************************************/
    {
        /* key1 is under pressing, receiving key1's up
         * key1's up is not in temp buffer
         * should write back
         */
        {DEVICE_KEY_1, DRV_WM_KEYRELEASE, MMI_FALSE},
        MMI_TRUE,  
        0,
        {
            {0,0,MMI_FALSE}, 
            {0,0, MMI_FALSE}
        },
        MMI_TRUE
    },
    {
        /* key1 is released, receiving key1's up
         * NOT write back
         */        
        {DEVICE_KEY_1, DRV_WM_KEYRELEASE, MMI_FALSE},
        MMI_FALSE,  
        0,
        {
            {0,0,MMI_FALSE}, 
            {0,0, MMI_FALSE}
        },
        MMI_FALSE
    },    
    {
        /* key1 is under pressing, receiving key1's up
         * key1's up is in temp buffer
         * NOT write back
         */        
        {DEVICE_KEY_1, DRV_WM_KEYRELEASE, MMI_FALSE},
        MMI_TRUE,    
        1,
        {
            {DEVICE_KEY_1, DRV_WM_KEYRELEASE, MMI_FALSE},
            {0,0, MMI_FALSE}
        },    
        MMI_FALSE
    },
    {
        /* receiving key1's down
         * NOT write back
         */        
        {DEVICE_KEY_1, DRV_WM_KEYPRESS, MMI_FALSE},
        MMI_FALSE,    
        1,
        {
            {DEVICE_KEY_1, DRV_WM_KEYRELEASE, MMI_FALSE}, 
            {0,0, MMI_FALSE}
        },    
        MMI_FALSE
    },
    {
        /* receiving key1's repeat
         * NOT write back
         */        
        {DEVICE_KEY_1, DRV_WM_KEYREPEATED, MMI_FALSE},
        MMI_FALSE,    
        1,
        {
            {DEVICE_KEY_1, DRV_WM_KEYRELEASE, MMI_FALSE}, 
            {0,0, MMI_FALSE}
        },    
        MMI_FALSE
    },
    {
        /* receiving key1's longpress
         * NOT write back
         */        
        {DEVICE_KEY_1, DRV_WM_KEYLONGPRESS, MMI_FALSE},
        MMI_FALSE,    
        1,
        {
            {DEVICE_KEY_1, DRV_WM_KEYRELEASE, MMI_FALSE}, 
            {0,0, MMI_FALSE}
        },    
        MMI_FALSE
    },
    /************************************************************************/
    /*    power off key long press write back                               */
    /*    we put END key in table, we will change it if power key support   */
    /************************************************************************/
        {
        /*
        * receive power/end key long press
        * not in temp buffer
        * power/end key is not active(key down is cleared)
        * write back
            */
            {DEVICE_KEY_END, DRV_WM_KEYLONGPRESS, MMI_FALSE},
                MMI_FALSE,    
                0,
            {
                {0,0,MMI_FALSE}, 
                {0,0, MMI_FALSE}
            },    
                MMI_TRUE
        },
        {
        /*
        * receive power/end key longpress
        * not in temp buffer
        * power/end key is active.
        * write back
                */
            {DEVICE_KEY_END, DRV_WM_KEYLONGPRESS, MMI_FALSE},
                MMI_TRUE,    
                2,
            {
                {DEVICE_KEY_END, DRV_WM_KEYRELEASE, MMI_FALSE},
                {DEVICE_KEY_2, DRV_WM_KEYRELEASE, MMI_FALSE}
            },    
                MMI_TRUE
            },
            /*
            * receive power/end key longpress
            * in temp buffer
            * power/end key is active.
            * NOT write back
            */
            {
                {DEVICE_KEY_END, DRV_WM_KEYLONGPRESS, MMI_FALSE},
                    MMI_FALSE,    
                    2,
                {
                    {DEVICE_KEY_1, DRV_WM_KEYRELEASE, MMI_FALSE},
                    {DEVICE_KEY_END, DRV_WM_KEYLONGPRESS, MMI_FALSE}
                },    
                    MMI_FALSE
            }   
};   
mmi_ret ut_is_need_write_back(void *para)
{
    S32 i;
    key_data_struct data;

    for (i = 0; i < sizeof (_wb_data)/sizeof(_wb_data[0]); i++)
    {
        init_key_data_buf();
        if (mmi_frm_kbd_is_key_supported(KEY_POWER) == MMI_TRUE)
        {
            if (_wb_data[i].test_evt.device_key_code == DEVICE_KEY_END)
            {
                _wb_data[i].test_evt.device_key_code = DEVICE_KEY_POWER;
            }    
        }
        if (_wb_data[i].is_active == MMI_TRUE)
        {
            data.mmi_key_code = (U8)get_mmi_key_code(_wb_data[i].test_evt.device_key_code);
            insert_key_data(&data);
        }    
        MMI_ASSERT(is_need_write_back(&_wb_data[i].test_evt,
            _wb_data[i].temp_buffer, _wb_data[i].len) == _wb_data[i].res);
    }
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test is_need_write_back PASS");
    return MMI_RET_OK;
}

mmi_ret ut_get_dev_key_evt(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dev_key_evt_struct t_case[10];
    S32 i;
    dev_key_evt_struct dev_evt;
	dev_key_evt_struct buf[LOOK_AHEAD_BUF_LEN];
	U8 r;
	U8 w;
    U8 n;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    save_look_ahead_buffer(buf, &r, &w, &n);
    g_key_cntx.w_look_ahead = g_key_cntx.r_look_ahead = 0;
    for (i = 0; i < 10; i++)
    {
        t_case[i].device_key_code = i;
        write_look_ahead_buffer(&t_case[i]);
        MMI_ASSERT(get_dev_key_evt(&dev_evt) == MMI_TRUE);
        MMI_ASSERT(dev_evt.device_key_code == i);
    }
    MMI_ASSERT(g_key_cntx.w_look_ahead == g_key_cntx.r_look_ahead);

    for (i = 0; i < 10; i +=2)
    {
        t_case[i].device_key_type = i;
        t_case[i+1].device_key_type = i + 1;
        write_look_ahead_buffer(&t_case[i]);
        write_look_ahead_buffer(&t_case[i+1]);
        MMI_ASSERT(get_dev_key_evt(&dev_evt) == MMI_TRUE);
        MMI_ASSERT(dev_evt.device_key_type == i);
        MMI_ASSERT(get_dev_key_evt(&dev_evt) == MMI_TRUE);
        MMI_ASSERT(dev_evt.device_key_type == i + 1);
    }
    MMI_ASSERT(get_dev_key_evt(&dev_evt) == MMI_FALSE);
    restore_look_ahead_buffer(buf, &r, &w, &n);
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test get_dev_key_evt PASS");
    return MMI_RET_OK;     
}


/*****************************************************************************
 * FUNCTION
 *  ut_get_exec_key_evt
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0004
 * <Test Case Content> judge is full ctrl key
 * <Test Case Number> 5
 * <Scenario>
 *     1. 2step key, half down
 *     2. 2step key, full down
 *     3. 2step key, other key event
 *     4. non-2step key
 * <Expected Result>
 *     1. HALF_DOWN
 *     2. FULL_DOWN
 *     3. no change
 *     4. no change
 * </test case description>
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret ut_get_exec_key_evt(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_key_evt_struct exec_evt[2];
    key_data_struct    data;
    U32 evt_num = 255;
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data.is_2step = MMI_TRUE;
    data.is_combo = MMI_FALSE;
#ifdef __KBD_2STEP_KEY_SUPPORT__
    data.mmi_key_code = KEY_CAMERA;
    g_key_cntx._2step_key.mmi_key_code = KEY_CAMERA;
    g_key_cntx._2step_key.state = HALF_DOWN;
    data.mmi_key_type = KEY_EVENT_UP;
    get_exec_key_evt(&data, exec_evt, &evt_num);
    MMI_ASSERT(exec_evt[0].mmi_key_code == KEY_CAMERA);
    MMI_ASSERT(exec_evt[0].mmi_key_type == KEY_HALF_PRESS_UP);
    MMI_ASSERT(evt_num == 1);

    g_key_cntx._2step_key.state = FULL_DOWN;
    get_exec_key_evt(&data, exec_evt, &evt_num);
    MMI_ASSERT(exec_evt[0].mmi_key_code == KEY_CAMERA);
    MMI_ASSERT(exec_evt[0].mmi_key_type == KEY_HALF_PRESS_UP);
    MMI_ASSERT(exec_evt[1].mmi_key_code == KEY_CAMERA);
    MMI_ASSERT(exec_evt[1].mmi_key_type == KEY_EVENT_UP);    
    MMI_ASSERT(evt_num == 2); 

    for (i = 0; i < MAX_KEY_TYPE; i++)
    {
        if (i != KEY_EVENT_UP)
        {
            data.mmi_key_type = i;
            get_exec_key_evt(&data, exec_evt, &evt_num);
            MMI_ASSERT(exec_evt[0].mmi_key_code == KEY_CAMERA);
            MMI_ASSERT(exec_evt[0].mmi_key_type == i);
            MMI_ASSERT(evt_num == 1);           
        }
    }
#endif
    data.is_2step = MMI_FALSE;
    data.mmi_key_code = KEY_0;
    SET_KPD_MODE(g_key_cntx.keypad_status, KEYPAD_2KEY_NUMBER);

    for (i = 0; i < MAX_KEY_TYPE; i++)
    {
        data.mmi_key_type = i;
        get_exec_key_evt(&data, exec_evt, &evt_num);
        MMI_ASSERT(exec_evt[0].mmi_key_code == KEY_0);
        MMI_ASSERT(exec_evt[0].mmi_key_type == i);
        MMI_ASSERT(evt_num == 1);      

    }
    SET_KPD_MODE(g_key_cntx.keypad_status, KEYPAD_2KEY_QWERTY);

    for (i = 0; i < MAX_KEY_TYPE; i++)
    {
        data.mmi_key_type = i;
        get_exec_key_evt(&data, exec_evt, &evt_num);
        MMI_ASSERT(exec_evt[0].mmi_key_code == KEY_0);
        MMI_ASSERT(exec_evt[0].mmi_key_type == i);
        MMI_ASSERT(evt_num == 1);      

    }

    SET_KPD_MODE(g_key_cntx.keypad_status, KEYPAD_3KEY_QWERTY);

    for (i = 0; i < MAX_KEY_TYPE; i++)
    {
        data.mmi_key_type = i;
        get_exec_key_evt(&data, exec_evt, &evt_num);
        MMI_ASSERT(exec_evt[0].mmi_key_code == KEY_0);
        MMI_ASSERT(exec_evt[0].mmi_key_type == i);
        MMI_ASSERT(evt_num == 1);      

    }

    SET_KPD_MODE(g_key_cntx.keypad_status, KEYPAD_3KEY_NUMBER);

    for (i = 0; i < MAX_KEY_TYPE; i++)
    {
        data.mmi_key_type = i;
        get_exec_key_evt(&data, exec_evt, &evt_num);
        MMI_ASSERT(exec_evt[0].mmi_key_code == KEY_0);
        MMI_ASSERT(exec_evt[0].mmi_key_type == i);
        MMI_ASSERT(evt_num == 1);      

    }
    SET_KPD_MODE(g_key_cntx.keypad_status, KEYPAD_1KEY_NUMBER);
    g_key_cntx.buf_len = 2;
    g_key_cntx.buffer[0].mmi_key_code = KEY_SHIFT;
    g_key_cntx.buffer[1].mmi_key_code = KEY_FN;

    data.is_2step = MMI_FALSE;
    data.mmi_key_code = KEY_FN;

    for (data.mmi_key_type = 0; data.mmi_key_type < MAX_KEY_TYPE; data.mmi_key_type++)
    {
        get_exec_key_evt(&data, exec_evt, &evt_num);
        MMI_ASSERT(evt_num == 1);
        MMI_ASSERT(exec_evt[0].mmi_key_code == KEY_FN);
        MMI_ASSERT(exec_evt[0].mmi_key_type == data.mmi_key_type);        
    }
    data.mmi_key_code = KEY_SHIFT;

    for (data.mmi_key_type = 0; data.mmi_key_type < MAX_KEY_TYPE; data.mmi_key_type++)
    {
        get_exec_key_evt(&data, exec_evt, &evt_num);
        MMI_ASSERT(evt_num == 1);
        MMI_ASSERT(exec_evt[0].mmi_key_code == KEY_SHIFT);
        MMI_ASSERT(exec_evt[0].mmi_key_type == data.mmi_key_type);        
    }

    g_key_cntx.buffer[0].mmi_key_code = KEY_1;
    g_key_cntx.buffer[1].mmi_key_code = KEY_FN; 

    data.mmi_key_code = KEY_FN;

    for (data.mmi_key_type = 0; data.mmi_key_type < MAX_KEY_TYPE; data.mmi_key_type++)
    {
        get_exec_key_evt(&data, exec_evt, &evt_num);
        MMI_ASSERT(evt_num == 1);
        MMI_ASSERT(exec_evt[0].mmi_key_code == KEY_FN);
        MMI_ASSERT(exec_evt[0].mmi_key_type == data.mmi_key_type);        
    }
    data.mmi_key_code = KEY_1;

    for (data.mmi_key_type = 0; data.mmi_key_type < MAX_KEY_TYPE; data.mmi_key_type++)
    {
        get_exec_key_evt(&data, exec_evt, &evt_num);
        MMI_ASSERT(evt_num == 1);
        MMI_ASSERT(exec_evt[0].mmi_key_code == KEY_1);
        MMI_ASSERT(exec_evt[0].mmi_key_type == data.mmi_key_type);        
    }  

    g_key_cntx.buffer[0].mmi_key_code = KEY_FN;
    g_key_cntx.buffer[1].mmi_key_code = KEY_1; 

    data.mmi_key_code = KEY_1;

    for (data.mmi_key_type = 0; data.mmi_key_type < MAX_KEY_TYPE; data.mmi_key_type++)
    {
        get_exec_key_evt(&data, exec_evt, &evt_num);
        MMI_ASSERT(evt_num == 1);
        MMI_ASSERT(exec_evt[0].mmi_key_code == KEY_1);
        MMI_ASSERT(exec_evt[0].mmi_key_type == data.mmi_key_type);        
    }  

    data.mmi_key_code = KEY_FN;

    for (data.mmi_key_type = 0; data.mmi_key_type < MAX_KEY_TYPE; data.mmi_key_type++)
    {
        get_exec_key_evt(&data, exec_evt, &evt_num);
        MMI_ASSERT(evt_num == 1);
        MMI_ASSERT(exec_evt[0].mmi_key_code == KEY_FN);
        MMI_ASSERT(exec_evt[0].mmi_key_type == data.mmi_key_type);        
    }   

    g_key_cntx.buffer[0].mmi_key_code = KEY_0;
    g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_DOWN;
    g_key_cntx.buffer[1].mmi_key_code = KEY_1; 
    g_key_cntx.buffer[1].mmi_key_type = KEY_EVENT_DOWN;
    data.mmi_key_code = KEY_1;
    data.mmi_key_type = KEY_EVENT_DOWN;
    get_exec_key_evt(&data, exec_evt, &evt_num);
    MMI_ASSERT(evt_num == 1);
    MMI_ASSERT(exec_evt[0].mmi_key_code == KEY_0);
    MMI_ASSERT(exec_evt[0].mmi_key_type == KEY_EVENT_UP);
    MMI_ASSERT(exec_evt[1].mmi_key_code == KEY_1);
    MMI_ASSERT(exec_evt[1].mmi_key_type == KEY_EVENT_DOWN);
    MMI_ASSERT(g_key_cntx.buffer[0].mmi_key_type == KEY_EVENT_UP);
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test get_exec_key_evt PASS");
    return MMI_RET_OK;
}


/*****************************************************************************
 * DESCRIPTION
 *  In a screen, show a category.  In the category, create a list.
 *  and in the list create a editor.
 *  we will define a variable to record the sequence of event sending.
 *  In the key proc, we will check this variable to make sure the sequence is right.
 *  we use user data to distinguish the test case
 * ========================================================================
 * TEST CASE1 - mmi_key_ut_evt_routing_full_path_test
 *  This test case is used to test the full path routing(No one stops the key routing).
 *
 *  The events sent sequence
 *  should be
 *       EVT_ID_PRE_KEY  SYS
 *       EVT_ID_PRE_KEY  SCR
 *       EVT_ID_PRE_KEY  CAT
 *       EVT_ID_PRE_KEY  LIST
 *       EVT_ID_PRE_KEY  EDITOR
 *       EVT_ID_ON_KEY   EDITOR
 *       EVT_ID_POST_KEY EDITOR
 *       EVT_ID_ON_KEY   LIST
 *       EVT_ID_POST_KEY LIST
 *       EVT_ID_ON_KEY   CAT
 *       EVT_ID_POST_KEY CAT
 *       EVT_ID_ON_KEY   SCR
 *       EVT_ID_POST_KEY SCR
 *       EVT_ID_ON_KEY   SYS
 *       EVT_ID_POST_KEY SYS
 * ========================================================================
 * TEST CASE2 - mmi_key_ut_evt_cat_routing_pre_stop_test
 *  This test case is used to test stop the key event routing when key proc
 *  receives EVT_ID_PRE_KEY events, take cat_key_proc as an example.
 * 
 *  The events sent sequence
 *  should be
 *       EVT_ID_PRE_KEY  SYS
 *       EVT_ID_PRE_KEY  SCR
 *       EVT_ID_PRE_KEY  CAT
 *       EVT_ID_POST_KEY SCR
 *       EVT_ID_POST_KEY SYS
 * ========================================================================
 * TEST CASE3 - mmi_key_ut_evt_routing_list_pre_stop_test
 *  This test case is used to test stop the key event routing when key proc
 *  receivs EVT_ID_PRE_KEY events, take list_key_proc as an example
 *
 *  The events sent sequence
 *  should be
 *       EVT_ID_PRE_KEY   SYS
 *       EVT_ID_PRE_KEY   SCR
 *       EVT_ID_PRE_KEY   CAT
 *       EVT_ID_PRE_KEY   LIST
 *       EVT_ID_POST_KEY  CAT
 *       EVT_ID_POST_KEY  SCR
 *       EVT_ID_POST_KEY  SYS
 * =======================================================================
 * TEST CASE 4 - mmi_key_ut_evt_routing_on_stop_scr_test
 *  This test case is used to test stop the key event routing when key proc
 *  receives EVT_ID_ON_KEY events, take scr_key_proc as an example
 *  
 *  The events sent sequence
 *  should be
 *       EVT_ID_PRE_KEY   SYS
 *       EVT_ID_PRE_KEY   SCR
 *       EVT_ID_PRE_KEY   CAT
 *       EVT_ID_PRE_KEY   LIST
 *       EVT_ID_PRE_KEY   EDITOR
 *       EVT_ID_ON_KEY    EDITOR
 *       EVT_ID_POST_KEY  EDITOR
 *       EVT_ID_ON_KEY    LIST
 *       EVT_ID_POST_KEY  LIST
 *       EVT_ID_ON_KEY    CAT
 *       EVT_ID_POST_KEY  CAT
 *       EVT_ID_ON_KEY    SCR
 *       EVT_ID_POST_KEY  SCR
 *       EVT_ID_POST_KEY  SYS
 * =======================================================================
 * TEST CASE 5 - mmi_key_ut_evt_routing_on_stop_editor_test
 *  This test case is used to test stop the key event routing when key proc
 *  receives EVT_ID_ON_KEY events, take editor_key_proc as an exmaple
 *  
 *  The events sent sequence
 *  should be
 *       EVT_ID_PRE_KEY   SYS
 *       EVT_ID_PRE_KEY   SCR
 *       EVT_ID_PRE_KEY   CAT
 *       EVT_ID_PRE_KEY   LIST
 *       EVT_ID_PRE_KEY   EDITOR   MMI_RET_OK
 *       EVT_ID_ON_KEY    EDITOR   MMI_RET_KEY_HANDLED
 *       EVT_ID_POST_KEY  EDITOR
 *       EVT_ID_POST_KEY  LIST
 *       EVT_ID_POST_KEY  CAT
 *       EVT_ID_POST_KEY  SCR
 *       EVT_ID_POST_KEY  SYS
 * ======================================================================
 * TEST CASE 6 - mmi_key_ut_evt_routing_stop_at_key_handler
 *  This test case is used to test stop the key event routing when the key
 *  handler is registered by some one.
 *
 *  The events sent sequence
 *  should be
 *       EVT_ID_PRE_KEY   SYS
 *       EVT_ID_PRE_KEY   SCR
 *       EVT_ID_PRE_KEY   CAT
 *       EVT_ID_PRE_KEY   LIST
 *       EVT_ID_PRE_KEY   EDITOR
 *       EVT_ID_POST_KEY  EDITOR
 *       EVT_ID_POST_KEY  LIST
 *       EVT_ID_POST_KEY  CAT
 *       EVT_ID_POST_KEY  SCR
 *       EVT_ID_POST_KEY  SYS
 * =======================================================================
 * TEST CASE 7 - mmi_key_ut_evt_routing_scr_no_proc_check
 *  This test case is used to test screen does not set the key proc function.
 *
 *  The events sent sequence
 *  should be
 *       EVT_ID_PRE_KEY    SYS
 *       EVT_ID_PRE_KEY    CAT
 *       EVT_ID_PRE_KEY    LIST
 *       EVT_ID_PRE_KEY    EDITOR
 *       EVT_ID_ON_KEY     EDITOR
 *       EVT_ID_POST_KEY   EDITOR
 *       EVT_ID_ON_KEY     LIST
 *       EVT_ID_POST_KEY   LIST
 *       EVT_ID_ON_KEY     CAT
 *       EVT_ID_POST_KEY   CAT
 *       EVT_ID_ON_KEY     SYS
 *       EVT_ID_POST_KEY   SYS
 *****************************************************************************/
 
/* user data */
static U8 sys_user_data;
static U8 scr_user_data;
static U8 cat_user_data;
static U8 list_user_data;
static U8 editor_user_data;
static U8 sequence = 1;

typedef enum
{
    FULL_PATH_ROUTING,           /* TEST CASE1 */
    STOP_AT_CAT_PRE_KEY,         /* TEST CASE2 */
    STOP_AT_LIST_PRE_KEY,        /* TEST CASE3 */
    STOP_AT_SCR_ON_KEY,          /* TEST CASE4 */
    STOP_AT_EDITOR_ON_KEY,       /* TEST CASE5 */
    STOP_AT_KEY_HANDLER,         /* TEST CASE6 */
    SCR_NO_REG_PROC              /* TEST CASE7 */
} test_case_of_routing_seq;


void set_test_case(test_case_of_routing_seq test_case)
{
    sys_user_data    = (U8)test_case;
    scr_user_data    = (U8)test_case;
    cat_user_data    = (U8)test_case;
    list_user_data   = (U8)test_case;
    editor_user_data = (U8)test_case;
    sequence = 1;
}

/* system key proc function */
mmi_ret sys_key_proc(mmi_frm_key_evt_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_PRE_KEY:
        {
            kal_prompt_trace(MOD_MMI, "[UT_KEY] sys pre key handle");
            switch (*((char*)evt->user_data))
            {
                case FULL_PATH_ROUTING:
                case STOP_AT_CAT_PRE_KEY:
                case STOP_AT_LIST_PRE_KEY:
                case STOP_AT_SCR_ON_KEY:
                case STOP_AT_EDITOR_ON_KEY:
                case STOP_AT_KEY_HANDLER:
                case SCR_NO_REG_PROC:
                {
                    MMI_ASSERT(sequence == 1);
                    sequence++;
                    break;
                }

            }
            break;
        }

        case EVT_ID_ON_KEY:
        {
            kal_prompt_trace(MOD_MMI, "[UT_KEY] sys on key handle");
            switch (*((char*)evt->user_data))
            {
                case FULL_PATH_ROUTING:
                {
                    MMI_ASSERT(sequence == 14);
                    sequence++;
                    break;
                }

                case STOP_AT_CAT_PRE_KEY:
                case STOP_AT_LIST_PRE_KEY:
                case STOP_AT_SCR_ON_KEY:
                case STOP_AT_EDITOR_ON_KEY:
                case STOP_AT_KEY_HANDLER:
                {
                    MMI_ASSERT(0);
                    break;
                }
                case SCR_NO_REG_PROC:
                {
                    MMI_ASSERT(sequence == 11);
                    sequence++;
                    break;
                }

            }
            break;
        }

        case EVT_ID_POST_KEY:
        {
            kal_prompt_trace(MOD_MMI, "[UT_KEY] sys post key handle");
            switch (*((char*)evt->user_data))
            {
                case FULL_PATH_ROUTING:
                {
                    MMI_ASSERT(sequence == 15);
                    sequence++;
                    break;
                }

                case STOP_AT_CAT_PRE_KEY:
                {
                    MMI_ASSERT(sequence == 5);
                    sequence++;
                    break;
                }

                case STOP_AT_LIST_PRE_KEY:
                {
                    MMI_ASSERT(sequence == 7);
                    sequence++;
                    break;
                }

                case STOP_AT_SCR_ON_KEY:
                {
                    MMI_ASSERT(sequence == 14);
                    sequence++;
                    break;
                }

                case STOP_AT_EDITOR_ON_KEY:
                {
                    MMI_ASSERT(sequence == 11);
                    sequence++;
                    break;
                }

                case STOP_AT_KEY_HANDLER:
                {
                    MMI_ASSERT(sequence == 10);
                    sequence++;
                    break;
                }
                case SCR_NO_REG_PROC:
                {
                    MMI_ASSERT(sequence == 12);
                    sequence++;
                    break;
                }

            }
            break;
        }
    }
    return MMI_RET_OK;
}

/* screen key proc function */
mmi_ret scr_key_proc(mmi_frm_key_evt_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_PRE_KEY:
        {
            kal_prompt_trace(MOD_MMI, "[UT_KEY] scr pre key handle");
            switch (*((char*)evt->user_data))
            {
                case FULL_PATH_ROUTING:
                case STOP_AT_CAT_PRE_KEY:
                case STOP_AT_LIST_PRE_KEY:
                case STOP_AT_SCR_ON_KEY:
                case STOP_AT_EDITOR_ON_KEY:
                case STOP_AT_KEY_HANDLER:
                {    
                    MMI_ASSERT(sequence == 2);
                    sequence++;
                    break;
                }
                case SCR_NO_REG_PROC:
                {
                    MMI_ASSERT(0);
                    break;
                }
            }
            break;
        }

        case EVT_ID_ON_KEY:
        {
            kal_prompt_trace(MOD_MMI, "[UT_KEY] scr on key handle");
            switch (*((char*)evt->user_data))
            {
                case FULL_PATH_ROUTING:
                {    
                    MMI_ASSERT(sequence == 12);
                    sequence++;
                    break;
                }
                case STOP_AT_CAT_PRE_KEY:
                case STOP_AT_LIST_PRE_KEY:
                case STOP_AT_EDITOR_ON_KEY:
                case STOP_AT_KEY_HANDLER:
                case SCR_NO_REG_PROC:
                {
                    MMI_ASSERT(0);
                    break;
                }
                case STOP_AT_SCR_ON_KEY:
                {
                    MMI_ASSERT(sequence == 12);
                    sequence++;
                    return MMI_RET_KEY_HANDLED;
                }
            }
            break;
        }
        
        case EVT_ID_POST_KEY:
        {
            kal_prompt_trace(MOD_MMI, "[UT_KEY] scr post key handle");
            switch (*((char*)evt->user_data))
            {
                case FULL_PATH_ROUTING:
                case STOP_AT_SCR_ON_KEY:
                {
                    MMI_ASSERT(sequence == 13);
                    sequence++;
                    break;
                }
                case STOP_AT_CAT_PRE_KEY:
                {
                    MMI_ASSERT(sequence == 4);
                    sequence++;
                    break;
                }
                case STOP_AT_LIST_PRE_KEY:
                {
                    MMI_ASSERT(sequence == 6);
                    sequence++;
                    break;
                }
                case STOP_AT_EDITOR_ON_KEY:
                {
                    MMI_ASSERT(sequence == 10);
                    sequence++;
                    break;
                }
                case STOP_AT_KEY_HANDLER:
                {
                    MMI_ASSERT(sequence == 9);
                    sequence++;
                    break;
                }
                case SCR_NO_REG_PROC:
                {
                    MMI_ASSERT(0);
                    break;
                }
            }
            break;
        }
    }
    return MMI_RET_OK;
}

/* category key proc function */
mmi_ret cat_key_proc(mmi_frm_key_evt_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_PRE_KEY:
        {
            kal_prompt_trace(MOD_MMI, "[UT_KEY] cat pre key handle");
            switch (*((char*)evt->user_data))
            {
                case FULL_PATH_ROUTING:
                case STOP_AT_LIST_PRE_KEY:
                case STOP_AT_SCR_ON_KEY:
                case STOP_AT_EDITOR_ON_KEY:
                case STOP_AT_KEY_HANDLER:
                {
                    MMI_ASSERT(sequence == 3);
                    sequence++;
                    break;
                }
                case STOP_AT_CAT_PRE_KEY:
                {
                    MMI_ASSERT(sequence == 3);
                    sequence++;
                    return MMI_RET_KEY_HANDLED;
                }
                case SCR_NO_REG_PROC:
                {
                    MMI_ASSERT(sequence == 2);
                    sequence++;
                }
            }
            break;
        }
        
        case EVT_ID_ON_KEY:
        {
            kal_prompt_trace(MOD_MMI, "[UT_KEY] cat on key handle");
            switch (*((char*)evt->user_data))
            {
                case FULL_PATH_ROUTING:
                case STOP_AT_SCR_ON_KEY:
                {
                    MMI_ASSERT(sequence == 10);
                    sequence++;
                    break;
                }
                case STOP_AT_CAT_PRE_KEY:
                case STOP_AT_LIST_PRE_KEY:
                case STOP_AT_EDITOR_ON_KEY:
                case STOP_AT_KEY_HANDLER:
                {
                    MMI_ASSERT(0);
                    break;
                }
                case SCR_NO_REG_PROC:
                {
                    MMI_ASSERT(sequence == 9);
                    sequence++;
                    break;
                }
            }   
            break;
        }
        
        case EVT_ID_POST_KEY:
        {
            kal_prompt_trace(MOD_MMI, "[UT_KEY] cat post key handle");
            switch (*((char*)evt->user_data))
            {
                case FULL_PATH_ROUTING:
                case STOP_AT_SCR_ON_KEY:
                {
                    MMI_ASSERT(sequence == 11);
                    sequence++;
                    break;
                }
                case STOP_AT_CAT_PRE_KEY:
                {
                    MMI_ASSERT(0);
                    break;
                }
                case STOP_AT_LIST_PRE_KEY:
                {
                    MMI_ASSERT(sequence == 5);
                    sequence++;
                    break;
                }
                case STOP_AT_EDITOR_ON_KEY:
                {
                    MMI_ASSERT(sequence == 9);
                    sequence++;
                    break;
                }
                case STOP_AT_KEY_HANDLER:
                {
                    MMI_ASSERT(sequence == 8);
                    sequence++;
                    break;
                }
                case SCR_NO_REG_PROC:
                {
                    MMI_ASSERT(sequence == 10);
                    sequence++;
                    break;
                }
            }
            break;
        }
    }
    return MMI_RET_OK;
}

/* list proc function */
mmi_ret list_key_proc(mmi_frm_key_evt_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_PRE_KEY:
        {
            kal_prompt_trace(MOD_MMI, "[UT_KEY] list pre key handle");
            switch (*((char*)evt->user_data))
            {
                case FULL_PATH_ROUTING:
                case STOP_AT_SCR_ON_KEY:
                case STOP_AT_EDITOR_ON_KEY:
                case STOP_AT_KEY_HANDLER:
                {
                    MMI_ASSERT(sequence == 4);
                    sequence++;
                    break;
                }
                case STOP_AT_CAT_PRE_KEY:
                {
                    MMI_ASSERT(0);
                    break;
                }
                case STOP_AT_LIST_PRE_KEY:
                {
                    MMI_ASSERT(sequence == 4);
                    sequence++;
                    return MMI_RET_KEY_HANDLED;
                }
                case SCR_NO_REG_PROC:
                {
                    MMI_ASSERT(sequence == 3);
                    sequence++;
                    break;
                }
            }   
            break;
        }
        
        case EVT_ID_ON_KEY:
        {
            kal_prompt_trace(MOD_MMI, "[UT_KEY] list on key handle");
            switch (*((char*)evt->user_data))
            {
                case FULL_PATH_ROUTING:
                case STOP_AT_SCR_ON_KEY:
                {
                    MMI_ASSERT(sequence == 8);
                    sequence++;
                    break;
                }
                case STOP_AT_CAT_PRE_KEY:
                case STOP_AT_LIST_PRE_KEY:
                case STOP_AT_EDITOR_ON_KEY:
                case STOP_AT_KEY_HANDLER:
                {
                    MMI_ASSERT(0);
                    break;
                }
                case SCR_NO_REG_PROC:
                {
                    MMI_ASSERT(sequence == 7);
                    sequence++;
                    break;
                }
            }
            break;
        }
        
        case EVT_ID_POST_KEY:
        {
            kal_prompt_trace(MOD_MMI, "[UT_KEY] list post key handle");
            switch (*((char*)evt->user_data))
            {
                case FULL_PATH_ROUTING:
                case STOP_AT_SCR_ON_KEY:
                {
                    MMI_ASSERT(sequence == 9);
                    sequence++;
                    break;
                }
                case STOP_AT_CAT_PRE_KEY:
                case STOP_AT_LIST_PRE_KEY:
                {
                    MMI_ASSERT(0);
                    break;
                }
                case STOP_AT_EDITOR_ON_KEY:
                {
                    MMI_ASSERT(sequence == 8);
                    sequence++;
                    break;
                }
                case STOP_AT_KEY_HANDLER:
                {
                    MMI_ASSERT(sequence == 7);
                    sequence++;
                    break;
                }
                case SCR_NO_REG_PROC:
                {
                    MMI_ASSERT(sequence == 8);
                    sequence++;
                    break;
                }
            }   
            break;
        }          
    }
    return MMI_RET_OK;
}


/* editor proc function */
mmi_ret editor_key_proc(mmi_frm_key_evt_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_PRE_KEY:
        {
            kal_prompt_trace(MOD_MMI, "[UT_KEY] editor pre key handle");
            switch (*((char*)evt->user_data))
            {
                case FULL_PATH_ROUTING:
                case STOP_AT_SCR_ON_KEY:
                case STOP_AT_EDITOR_ON_KEY:
                case STOP_AT_KEY_HANDLER:
                {
                    MMI_ASSERT(sequence == 5);
                    sequence++;
                    break;
                }
                case STOP_AT_CAT_PRE_KEY:
                case STOP_AT_LIST_PRE_KEY:
                {
                    MMI_ASSERT(0);
                    break;
                }
                case SCR_NO_REG_PROC:
                {
                    MMI_ASSERT(sequence == 4);
                    sequence++;
                    break;
                }
            }   
            break;
        }
        
        case EVT_ID_ON_KEY:
        {
            kal_prompt_trace(MOD_MMI, "[UT_KEY] editor on key handle");
            switch (*((char*)evt->user_data))
            {
                case FULL_PATH_ROUTING:
                case STOP_AT_SCR_ON_KEY:
                {
                    MMI_ASSERT(sequence == 6);
                    sequence++;
                    break;
                }
                case STOP_AT_CAT_PRE_KEY:
                case STOP_AT_LIST_PRE_KEY:
                case STOP_AT_KEY_HANDLER:
                {
                    MMI_ASSERT(0);
                    break;
                }
                case STOP_AT_EDITOR_ON_KEY:
                {
                    MMI_ASSERT(sequence == 6);
                    sequence++;
                    return MMI_RET_KEY_HANDLED;
                }
                case SCR_NO_REG_PROC:
                {
                    MMI_ASSERT(sequence == 5);
                    sequence++;
                    break;
                }
            }   
            break;
        }
        
        case EVT_ID_POST_KEY:
        {
            kal_prompt_trace(MOD_MMI, "[UT_KEY] editor post key handle");
            switch (*((char*)evt->user_data))
            {
                case FULL_PATH_ROUTING:
                case STOP_AT_SCR_ON_KEY:
                case STOP_AT_EDITOR_ON_KEY:
                {
                    MMI_ASSERT(sequence == 7);
                    sequence++;
                    break;
                }
                case STOP_AT_CAT_PRE_KEY:
                case STOP_AT_LIST_PRE_KEY:
                {
                    MMI_ASSERT(0);
                    break;
                }
                case STOP_AT_KEY_HANDLER:
                {
                    MMI_ASSERT(sequence == 6);
                    sequence++;
                    break;
                }
                case SCR_NO_REG_PROC:
                {
                    MMI_ASSERT(sequence == 6);
                    sequence++;
                    break;
                }
            }
            break;
        }            
    }
    return MMI_RET_OK;    
}

/* editor's create function */
void create_editor(void)
{
    MMI_WGUI_SET_KEY_PROC(editor_key_proc, &editor_user_data);
}

/* list's create function */
void create_list(void)
{
    MMI_WGUI_SET_KEY_PROC(list_key_proc, &list_user_data);
    create_editor();
}

/* show category function */
void show_category(void)
{
    MMI_CAT_SET_KEY_PROC(cat_key_proc, &cat_user_data);
    create_list();        
}

/* screen create function */
void entry_function()
{
    MMI_SCR_SET_KEY_PROC(scr_key_proc, &scr_user_data);
    show_category();    
}


/* test case 1 */
mmi_ret ut_evt_routing_full_path_test(void *para)
{
    mmi_frm_key_evt_struct key_evt;   
    mmi_frm_clear_all_translate_key_handler();
    mmi_frm_clear_key_handler(KEY_0, KEY_EVENT_DOWN);
    memset(g_key_cntx.routing_layer, 0, sizeof(g_key_cntx.routing_layer));
    memset(g_key_cntx.wgui_layer_num, 0, sizeof(g_key_cntx.wgui_layer_num));
    set_test_case(FULL_PATH_ROUTING);
    MMI_SYS_SET_KEY_PROC(sys_key_proc, &sys_user_data);
    mmi_frm_set_key_proc(MMI_KEY_ROUTING_KEY_HDLR, (mmi_proc_func)mmi_key_hdlr_proc,NULL);
	g_key_cntx.is_screen_switch = MMI_FALSE;
    entry_function();
    memcpy(g_key_cntx.routing_layer[LAYER_INVOKE_SPACE], 
        g_key_cntx.routing_layer[LAYER_SET_SPACE], 
        sizeof(mmi_key_routing_layer_struct) * MMI_KEY_ROUTING_TOTAL);
    g_key_cntx.wgui_layer_num[LAYER_INVOKE_SPACE] = g_key_cntx.wgui_layer_num[LAYER_SET_SPACE];
    MMI_FRM_INIT_EVENT(&key_evt, EVT_ID_PRE_KEY_EVT_ROUTING);
    MMI_CONSTRUCT_KEY_EVENT(
        &key_evt,
        KEY_0,
        KEY_EVENT_DOWN,
        0,
        0);

    process_key_event_routing(&key_evt);
    kal_prompt_trace(MOD_MMI, "[UT_KEY] key event routing full path test pass");
    return MMI_RET_OK;
}


/* test case 2 */
mmi_ret ut_evt_routing_cat_pre_stop_test(void *para)
{
    mmi_frm_key_evt_struct key_evt;
    memset(g_key_cntx.routing_layer, 0, sizeof(g_key_cntx.routing_layer));
    memset(g_key_cntx.wgui_layer_num, 0, sizeof(g_key_cntx.wgui_layer_num));
    MMI_SYS_SET_KEY_PROC(sys_key_proc, &sys_user_data);
    mmi_frm_set_key_proc(MMI_KEY_ROUTING_KEY_HDLR, (mmi_proc_func)mmi_key_hdlr_proc,NULL);
	g_key_cntx.is_screen_switch = MMI_FALSE;
    mmi_frm_clear_all_translate_key_handler();
    mmi_frm_clear_key_handler(KEY_0, KEY_EVENT_DOWN);
    set_test_case(STOP_AT_CAT_PRE_KEY);
    entry_function();
    memcpy(g_key_cntx.routing_layer[LAYER_INVOKE_SPACE], 
        g_key_cntx.routing_layer[LAYER_SET_SPACE], 
        sizeof(mmi_key_routing_layer_struct) * MMI_KEY_ROUTING_TOTAL);
    g_key_cntx.wgui_layer_num[LAYER_INVOKE_SPACE] = g_key_cntx.wgui_layer_num[LAYER_SET_SPACE];

    MMI_FRM_INIT_EVENT(&key_evt, EVT_ID_PRE_KEY_EVT_ROUTING);
    MMI_CONSTRUCT_KEY_EVENT(
        &key_evt,
        KEY_0,
        KEY_EVENT_DOWN,
        0,
        0);

    process_key_event_routing(&key_evt);
    kal_prompt_trace(MOD_MMI, "[UT_KEY] key event routing cat pre stop test pass");
    return MMI_RET_OK;
} 

/* test case 3 */
mmi_ret ut_evt_routing_list_pre_stop_test(void *para)
{
    mmi_frm_key_evt_struct key_evt;
    memset(g_key_cntx.routing_layer, 0, sizeof(g_key_cntx.routing_layer));
    memset(g_key_cntx.wgui_layer_num, 0, sizeof(g_key_cntx.wgui_layer_num));
    MMI_SYS_SET_KEY_PROC(sys_key_proc, &sys_user_data);
    mmi_frm_set_key_proc(MMI_KEY_ROUTING_KEY_HDLR, (mmi_proc_func)mmi_key_hdlr_proc,NULL);
	g_key_cntx.is_screen_switch = MMI_FALSE;
    mmi_frm_clear_all_translate_key_handler();
    mmi_frm_clear_key_handler(KEY_0, KEY_EVENT_DOWN);
    set_test_case(STOP_AT_LIST_PRE_KEY);
    entry_function();
    memcpy(g_key_cntx.routing_layer[LAYER_INVOKE_SPACE], 
        g_key_cntx.routing_layer[LAYER_SET_SPACE], 
        sizeof(mmi_key_routing_layer_struct) * MMI_KEY_ROUTING_TOTAL);
    g_key_cntx.wgui_layer_num[LAYER_INVOKE_SPACE] = g_key_cntx.wgui_layer_num[LAYER_SET_SPACE];

    MMI_FRM_INIT_EVENT(&key_evt, EVT_ID_PRE_KEY_EVT_ROUTING);
    MMI_CONSTRUCT_KEY_EVENT(
        &key_evt,
        KEY_0,
        KEY_EVENT_DOWN,
        0,
        0);

    process_key_event_routing(&key_evt);

    kal_prompt_trace(MOD_MMI, "[UT_KEY] key event routing list pre stop test pass");
    return MMI_RET_OK;
}

/* test case 4 */
mmi_ret ut_evt_routing_on_stop_scr_test(void *para)
{
    mmi_frm_key_evt_struct key_evt;
    memset(g_key_cntx.routing_layer, 0, sizeof(g_key_cntx.routing_layer));
    memset(g_key_cntx.wgui_layer_num, 0, sizeof(g_key_cntx.wgui_layer_num));
    MMI_SYS_SET_KEY_PROC(sys_key_proc, &sys_user_data);
    mmi_frm_set_key_proc(MMI_KEY_ROUTING_KEY_HDLR, (mmi_proc_func)mmi_key_hdlr_proc,NULL);
	g_key_cntx.is_screen_switch = MMI_FALSE;
    mmi_frm_clear_all_translate_key_handler();
    mmi_frm_clear_key_handler(KEY_0, KEY_EVENT_DOWN);
    set_test_case(STOP_AT_SCR_ON_KEY);
    entry_function();
    memcpy(g_key_cntx.routing_layer[LAYER_INVOKE_SPACE], 
        g_key_cntx.routing_layer[LAYER_SET_SPACE], 
        sizeof(mmi_key_routing_layer_struct) * MMI_KEY_ROUTING_TOTAL);
    g_key_cntx.wgui_layer_num[LAYER_INVOKE_SPACE] = g_key_cntx.wgui_layer_num[LAYER_SET_SPACE];

    MMI_FRM_INIT_EVENT(&key_evt, EVT_ID_PRE_KEY_EVT_ROUTING);
    MMI_CONSTRUCT_KEY_EVENT(
        &key_evt,
        KEY_0,
        KEY_EVENT_DOWN,
        0,
        0);

    process_key_event_routing(&key_evt);

    kal_prompt_trace(MOD_MMI, "[UT_KEY] key event routing scr on key stop pass");
    return MMI_RET_OK;
}

/* test case 5 */
mmi_ret ut_evt_routing_on_stop_editor_test(void *para)
{
    mmi_frm_key_evt_struct key_evt;
    memset(g_key_cntx.routing_layer, 0, sizeof(g_key_cntx.routing_layer));
    memset(g_key_cntx.wgui_layer_num, 0, sizeof(g_key_cntx.wgui_layer_num));
    MMI_SYS_SET_KEY_PROC(sys_key_proc, &sys_user_data);
    mmi_frm_set_key_proc(MMI_KEY_ROUTING_KEY_HDLR, (mmi_proc_func)mmi_key_hdlr_proc,NULL);
	g_key_cntx.is_screen_switch = MMI_FALSE;
    mmi_frm_clear_all_translate_key_handler();
    mmi_frm_clear_key_handler(KEY_0, KEY_EVENT_DOWN);
    set_test_case(STOP_AT_EDITOR_ON_KEY);
    entry_function();
    memcpy(g_key_cntx.routing_layer[LAYER_INVOKE_SPACE], 
        g_key_cntx.routing_layer[LAYER_SET_SPACE], 
        sizeof(mmi_key_routing_layer_struct) * MMI_KEY_ROUTING_TOTAL);
    g_key_cntx.wgui_layer_num[LAYER_INVOKE_SPACE] = g_key_cntx.wgui_layer_num[LAYER_SET_SPACE];

    MMI_FRM_INIT_EVENT(&key_evt, EVT_ID_PRE_KEY_EVT_ROUTING);
    MMI_CONSTRUCT_KEY_EVENT(
        &key_evt,
        KEY_0,
        KEY_EVENT_DOWN,
        0,
        0);

    process_key_event_routing(&key_evt);

    kal_prompt_trace(MOD_MMI, "[UT_KEY] key event routing editor on key stop pass");
    return MMI_RET_OK;
}


/* test case 6 */
void my_key_handler(void)
{

}
mmi_ret ut_evt_routing_stop_at_key_handler(void *para)
{
    mmi_frm_key_evt_struct key_evt;
    memset(g_key_cntx.routing_layer, 0, sizeof(g_key_cntx.routing_layer));
    memset(g_key_cntx.wgui_layer_num, 0, sizeof(g_key_cntx.wgui_layer_num));
    MMI_SYS_SET_KEY_PROC(sys_key_proc, &sys_user_data);
	mmi_frm_set_key_proc(MMI_KEY_ROUTING_KEY_HDLR, (mmi_proc_func)mmi_key_hdlr_proc,NULL);
	g_key_cntx.is_screen_switch = MMI_FALSE;
    mmi_frm_clear_all_translate_key_handler();
    mmi_frm_set_key_handler(my_key_handler,KEY_0, KEY_EVENT_DOWN);
    set_test_case(STOP_AT_KEY_HANDLER);
    entry_function();
    memcpy(g_key_cntx.routing_layer[LAYER_INVOKE_SPACE], 
        g_key_cntx.routing_layer[LAYER_SET_SPACE], 
        sizeof(mmi_key_routing_layer_struct) * MMI_KEY_ROUTING_TOTAL);
    g_key_cntx.wgui_layer_num[LAYER_INVOKE_SPACE] = g_key_cntx.wgui_layer_num[LAYER_SET_SPACE];

    MMI_FRM_INIT_EVENT(&key_evt, EVT_ID_PRE_KEY_EVT_ROUTING);
    MMI_CONSTRUCT_KEY_EVENT(
        &key_evt,
        KEY_0,
        KEY_EVENT_DOWN,
        0,
        0);

    process_key_event_routing(&key_evt);

    kal_prompt_trace(MOD_MMI, "[UT_KEY] key event routing stop key handler test pass");
    return MMI_RET_OK;
}

/* test case 7 */
mmi_ret ut_evt_routing_scr_no_proc_check(void *para)
{
    mmi_frm_key_evt_struct key_evt;
    memset(g_key_cntx.routing_layer, 0, sizeof(g_key_cntx.routing_layer));
    memset(g_key_cntx.wgui_layer_num, 0, sizeof(g_key_cntx.wgui_layer_num));
    MMI_SYS_SET_KEY_PROC(sys_key_proc, &sys_user_data);
    mmi_frm_set_key_proc(MMI_KEY_ROUTING_KEY_HDLR, (mmi_proc_func)mmi_key_hdlr_proc,NULL);
	g_key_cntx.is_screen_switch = MMI_FALSE;
    mmi_frm_clear_all_translate_key_handler();
    mmi_frm_clear_key_handler(KEY_0, KEY_EVENT_DOWN);
    set_test_case(SCR_NO_REG_PROC);
    show_category();
    memcpy(g_key_cntx.routing_layer[LAYER_INVOKE_SPACE], 
        g_key_cntx.routing_layer[LAYER_SET_SPACE], 
        sizeof(mmi_key_routing_layer_struct) * MMI_KEY_ROUTING_TOTAL);
    g_key_cntx.wgui_layer_num[LAYER_INVOKE_SPACE] = g_key_cntx.wgui_layer_num[LAYER_SET_SPACE];
    MMI_CONSTRUCT_KEY_EVENT(
        &key_evt,
        KEY_0,
        KEY_EVENT_DOWN,
        0,
        0);

    process_key_event_routing(&key_evt);

    kal_prompt_trace(MOD_MMI, "[UT_KEY] key event routing editor screen no reg proc pass");
    return MMI_RET_OK;
}

void scr_common_entry(void)
{
    EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, scr_common_entry, NULL);
}

void scr_common_entry_ex(void)
{
    EntryNewScreen_Ext(GLOBAL_SCR_DUMMY, NULL, scr_common_entry_ex, NULL);
}
mmi_ret ut_evt_routing_proc_life_check(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer;
    S32 i;
    FuncPtr f[] = {scr_common_entry, scr_common_entry_ex};
    key_data_struct key_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < sizeof(f) / sizeof(f[0]); i++)
    {
        /* set key proc */
        g_key_cntx.wgui_layer_num[LAYER_SET_SPACE] = 0;
        MMI_SYS_SET_KEY_PROC(sys_key_proc, &sys_user_data);
        MMI_SCR_SET_KEY_PROC(sys_key_proc, &sys_user_data);
        MMI_CAT_SET_KEY_PROC(sys_key_proc, &sys_user_data);
        MMI_WGUI_SET_KEY_PROC(sys_key_proc, &sys_user_data);

        /* update key proc */
        key_data.is_2step = MMI_FALSE;
        key_data.mmi_key_type = KEY_EVENT_DOWN;
        g_key_cntx.buf_len = 0;
        update_key_proc_data((S16)key_data.mmi_key_type, MMI_FALSE);

        /* screen switch */
        (* (f[i]))();

        /* check */
        MMI_ASSERT(g_key_cntx.wgui_layer_num[LAYER_SET_SPACE] == 0);
        MMI_ASSERT(g_key_cntx.wgui_layer_num[LAYER_INVOKE_SPACE] == 1);
        
        for (layer = MMI_KEY_ROUTING_SCR; layer < MMI_KEY_ROUTING_WGUI + 1; layer++)
        {
            MMI_ASSERT(g_key_cntx.routing_layer[LAYER_SET_SPACE][layer].key_proc == NULL);
            MMI_ASSERT(g_key_cntx.routing_layer[LAYER_SET_SPACE][layer].user_data == NULL);
            MMI_ASSERT(g_key_cntx.routing_layer[LAYER_INVOKE_SPACE][layer].key_proc == (mmi_proc_func)sys_key_proc);
            MMI_ASSERT(g_key_cntx.routing_layer[LAYER_INVOKE_SPACE][layer].user_data == (void *)&sys_user_data);
        }

        GoBackHistory();
    }
    kal_prompt_trace(MOD_MMI, "[UT_KEY]key proc life check pass");
    memset(g_key_cntx.routing_layer, 0, sizeof(g_key_cntx.routing_layer)/sizeof(g_key_cntx.routing_layer[0][0]));
    return MMI_RET_OK;
}


mmi_ret event_flow_check_sub_screen_key_proc(mmi_frm_key_evt_struct *evt)
{
    static U8 key_life = 0;
    sequence = 55;
    if (evt->evt_id == EVT_ID_ON_KEY)
    {
        if (key_life == 0)
        {
            MMI_ASSERT(evt->key_type == KEY_EVENT_DOWN);
        }
        key_life++;
        if (evt->key_type == KEY_EVENT_UP)
        {
            key_life = 0;
        }
    }
    return MMI_RET_OK;
}
void event_flow_check_sub_screen_entry(void)
{
    EntryNewScreen(GLOBAL_SCR_DUMMY + 1, NULL, event_flow_check_sub_screen_entry, NULL);
    
    MMI_SCR_SET_KEY_PROC(event_flow_check_sub_screen_key_proc, NULL);
}
mmi_ret event_flow_check_main_screen_key_proc(mmi_frm_key_evt_struct *evt)
{
    static U8 flow_check = 0;
    if (evt->evt_id == EVT_ID_ON_KEY)
    {
        if ((*(U8 *)(evt->user_data)) == 1)
        {
            if (evt->key_code == KEY_5)
            {
                switch (evt->key_type)
                {
                    case KEY_EVENT_DOWN:
                    {
                        event_flow_check_sub_screen_entry();
                        flow_check++;
                        return MMI_RET_KEY_HANDLED;
                    }
                    
                    case KEY_LONG_PRESS:
                    {
                        MMI_ASSERT(flow_check == 1);
                        flow_check++;
                        break;
                    }

                    case KEY_REPEAT:
                    {
                        MMI_ASSERT(flow_check == 2);
                        flow_check++;
                        break;
                    }

                    case KEY_EVENT_UP:
                    {
                        MMI_ASSERT(flow_check == 3);
                        flow_check = 0;
                        break;
                    }
                }
            }
        }
        else if ((*(U8 *)(evt->user_data)) == 2)
        {
            if (evt->key_code == KEY_5)
            {
                if (evt->key_type == KEY_EVENT_DOWN)
                {
                    MMI_ASSERT(flow_check == 0);
                    flow_check++;
                }
                else if (evt->key_type == KEY_EVENT_UP)
                {
                    MMI_ASSERT(flow_check == 3);
                    flow_check = 0;
                }
                
            }
            if (evt->key_code == KEY_2)
            {
                if (evt->key_type == KEY_EVENT_DOWN)
                {
                    MMI_ASSERT(flow_check == 1);
                    flow_check++;
                }
                else if (evt->key_type == KEY_EVENT_UP)
                {
                    MMI_ASSERT(flow_check == 2);
                    flow_check++;
                }            
            }
        }
    }
    return MMI_RET_OK;
}
void event_flow_check_main_screen_entry(void)
{
    mmi_key_evt_struct mmi_key_event;
    sequence = 0;
    memset(g_key_cntx.routing_layer, 0, sizeof(g_key_cntx.routing_layer)/sizeof(g_key_cntx.routing_layer[0][0]));
    memset(g_key_cntx.wgui_layer_num, 0, sizeof(g_key_cntx.wgui_layer_num));
    mmi_frm_set_all_key_hdlr_null();

    EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, event_flow_check_main_screen_entry, NULL);
    scr_user_data = 1;
    MMI_SCR_SET_KEY_PROC(event_flow_check_main_screen_key_proc, &scr_user_data);
    mmi_key_event.cvt_code = KEY_5;
    mmi_key_event.mmi_key_code = KEY_5;
    mmi_key_event.is_clear = MMI_FALSE;
    mmi_key_event.mmi_key_type = KEY_EVENT_DOWN;
    mmi_key_handle(&mmi_key_event);
    mmi_key_event.mmi_key_type = KEY_LONG_PRESS;
    mmi_key_handle(&mmi_key_event);
    mmi_key_event.mmi_key_type = KEY_REPEAT;
    mmi_key_handle(&mmi_key_event);
    mmi_key_event.mmi_key_type = KEY_EVENT_UP;
    mmi_key_handle(&mmi_key_event);
    MMI_ASSERT(sequence == 0);
    mmi_key_event.cvt_code = KEY_2;
    mmi_key_event.mmi_key_code = KEY_2;
    mmi_key_event.mmi_key_type = KEY_EVENT_DOWN;
    mmi_key_handle(&mmi_key_event);
    mmi_key_event.mmi_key_type = KEY_EVENT_UP;
    mmi_key_handle(&mmi_key_event);
    MMI_ASSERT(sequence == 55);
    ExecuteRootMainHistoryScreen(NULL);

    EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, event_flow_check_main_screen_entry, NULL);
    scr_user_data = 2;
    MMI_SCR_SET_KEY_PROC(event_flow_check_main_screen_key_proc, &scr_user_data);
    mmi_frm_set_keypad_mode(KEYPAD_2KEY_NUMBER);
    mmi_key_event.cvt_code = KEY_5;
    mmi_key_event.mmi_key_code = KEY_5;
    mmi_key_event.is_clear = MMI_FALSE;
    mmi_key_event.mmi_key_type = KEY_EVENT_DOWN;
    mmi_key_handle(&mmi_key_event);
    mmi_key_event.cvt_code = KEY_2;
    mmi_key_event.mmi_key_code = KEY_2;
    mmi_key_event.is_clear = MMI_FALSE;
    mmi_key_event.mmi_key_type = KEY_EVENT_DOWN;
    mmi_key_handle(&mmi_key_event);
    mmi_key_event.cvt_code = KEY_2;
    mmi_key_event.mmi_key_code = KEY_2;
    mmi_key_event.is_clear = MMI_FALSE;
    mmi_key_event.mmi_key_type = KEY_EVENT_UP;
    mmi_key_handle(&mmi_key_event);
    mmi_key_event.cvt_code = KEY_5;
    mmi_key_event.mmi_key_code = KEY_5;
    mmi_key_event.is_clear = MMI_FALSE;
    mmi_key_event.mmi_key_type = KEY_EVENT_UP;
    mmi_key_handle(&mmi_key_event);
    mmi_frm_set_keypad_mode(KEYPAD_1KEY_NUMBER);
    memset(g_key_cntx.routing_layer, 0, sizeof(g_key_cntx.routing_layer)/sizeof(g_key_cntx.routing_layer[0][0]));    
    ExecuteRootMainHistoryScreen(NULL);
}

mmi_ret ut_evt_routing_event_flow_check(void *para)
{
    event_flow_check_main_screen_entry();
    
       
    kal_prompt_trace(MOD_MMI, "[UT_KEY] key event flow within screen check pass");
    return MMI_RET_OK;
}

mmi_ret ut_update_key_proc_data(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    key_data_struct data;
    key_data_struct buf[MAX_DECT_KEY_NUM];
    U8 len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    save_key_data(buf, &len);
    init_key_data_buf();
    data.mmi_key_type = KEY_EVENT_DOWN;
    g_key_cntx.buf_len = 0;
    MMI_SYS_SET_KEY_PROC(sys_key_proc, NULL);
    MMI_SCR_SET_KEY_PROC(scr_key_proc, NULL);
    MMI_CAT_SET_KEY_PROC(cat_key_proc, NULL);
    MMI_WGUI_SET_KEY_PROC(list_key_proc, NULL);
    update_key_proc_data((S16)data.mmi_key_type, MMI_FALSE);
    //MMI_ASSERT(g_key_cntx.is_screen_switch == MMI_FALSE);
    MMI_ASSERT(g_key_cntx.routing_layer[LAYER_INVOKE_SPACE][MMI_KEY_ROUTING_SYS].key_proc == (mmi_proc_func)sys_key_proc);
    MMI_ASSERT(g_key_cntx.routing_layer[LAYER_INVOKE_SPACE][MMI_KEY_ROUTING_SCR].key_proc == (mmi_proc_func)scr_key_proc);
    MMI_ASSERT(g_key_cntx.routing_layer[LAYER_INVOKE_SPACE][MMI_KEY_ROUTING_CAT].key_proc == (mmi_proc_func)cat_key_proc);
    MMI_ASSERT(g_key_cntx.routing_layer[LAYER_INVOKE_SPACE][MMI_KEY_ROUTING_WGUI].key_proc == (mmi_proc_func)list_key_proc);
    MMI_SCR_SET_KEY_PROC((mmi_proc_func)0x1234567, NULL);
    MMI_ASSERT(g_key_cntx.routing_layer[LAYER_INVOKE_SPACE][MMI_KEY_ROUTING_SCR].key_proc == (mmi_proc_func)scr_key_proc);
    MMI_ASSERT(g_key_cntx.routing_layer[LAYER_SET_SPACE][MMI_KEY_ROUTING_SCR].key_proc == (mmi_proc_func)0x1234567);
    data.mmi_key_type = KEY_REPEAT;
    update_key_proc_data((S16)data.mmi_key_type, MMI_FALSE);
    MMI_ASSERT(g_key_cntx.routing_layer[LAYER_INVOKE_SPACE][MMI_KEY_ROUTING_SCR].key_proc == (mmi_proc_func)scr_key_proc);
    MMI_ASSERT(g_key_cntx.routing_layer[LAYER_SET_SPACE][MMI_KEY_ROUTING_SCR].key_proc == (mmi_proc_func)0x1234567);
    data.mmi_key_type = KEY_EVENT_DOWN;
    g_key_cntx.buf_len = 1;
    //g_key_cntx.is_screen_switch = MMI_TRUE;
    update_key_proc_data((S16)data.mmi_key_type, MMI_FALSE);
    MMI_ASSERT(g_key_cntx.routing_layer[LAYER_INVOKE_SPACE][MMI_KEY_ROUTING_SCR].key_proc == (mmi_proc_func)0x1234567);
    MMI_ASSERT(g_key_cntx.routing_layer[LAYER_SET_SPACE][MMI_KEY_ROUTING_SCR].key_proc == (mmi_proc_func)0x1234567);
    //MMI_ASSERT(g_key_cntx.is_screen_switch == MMI_TRUE);
    
    restore_key_data(buf, &len);
    memset(g_key_cntx.routing_layer, 0, sizeof(g_key_cntx.routing_layer)/sizeof(g_key_cntx.routing_layer[0][0]));    
    ExecuteRootMainHistoryScreen(NULL);
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test update_key_proc_data PASS");
    return MMI_RET_OK;
}


mmi_ret ut_is_power_off_evt(void *para)
{
    MMI_ASSERT(is_power_off_key_evt(DEVICE_KEY_END, DRV_WM_KEYREPEATED)  == MMI_FALSE);
    MMI_ASSERT(is_power_off_key_evt(DEVICE_KEY_END, DRV_WM_KEYPRESS)     == MMI_FALSE);
    MMI_ASSERT(is_power_off_key_evt(DEVICE_KEY_END, DRV_WM_KEYRELEASE)   == MMI_FALSE);
    MMI_ASSERT(is_power_off_key_evt(DEVICE_KEY_1,   DRV_WM_KEYLONGPRESS) == MMI_FALSE);
    if (mmi_frm_kbd_is_key_supported(KEY_POWER) == MMI_TRUE)
    {
        MMI_ASSERT(is_power_off_key_evt(DEVICE_KEY_POWER, DRV_WM_KEYLONGPRESS) == MMI_TRUE);
        MMI_ASSERT(is_power_off_key_evt(DEVICE_KEY_END, DRV_WM_KEYLONGPRESS) == MMI_FALSE);
    }
    else
    {
        MMI_ASSERT(is_power_off_key_evt(DEVICE_KEY_END, DRV_WM_KEYLONGPRESS) == MMI_TRUE);
        //MMI_ASSERT(is_power_off_key_evt(KEY_POWER, KEY_LONG_PRESS) == MMI_FALSE);
    }
    
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test is_power off evt PASS");
    return MMI_RET_OK;
}


/************************************************************************/
/* Unit Test for is_valid_mmi_key_event                                 */
/************************************************************************/
typedef struct 
{
    S16 key_code;
    S16 key_type;
    MMI_BOOL res;
} key_evt_struct;

const key_evt_struct key_evt[] = 
{
    {KEY_INVALID, KEY_EVENT_DOWN,      MMI_FALSE},
    {KEY_INVALID, KEY_EVENT_UP,        MMI_FALSE},
    {KEY_INVALID, KEY_LONG_PRESS,      MMI_FALSE},
    {KEY_INVALID, KEY_REPEAT,          MMI_FALSE},
    {KEY_INVALID, KEY_FULL_PRESS_DOWN, MMI_FALSE},
    {KEY_1,       KEY_EVENT_DOWN,      MMI_TRUE},
    {KEY_1,       KEY_EVENT_UP,        MMI_TRUE},
    {KEY_1,       KEY_LONG_PRESS,      MMI_TRUE},
    {KEY_1,       KEY_REPEAT,          MMI_TRUE},
    {KEY_1,       KEY_FULL_PRESS_DOWN, MMI_TRUE},
    {KEY_1,       ERR_KEY_EVENT,       MMI_FALSE},
    {KEY_1,       ERR_KEY_EVT_TRANS,   MMI_FALSE},
    {KEY_1,       ERR_KEY_CODE,        MMI_FALSE},
    {KEY_1,       KEY_EVENT_DECT,      MMI_FALSE},

};
mmi_ret ut_is_valid_mmi_key_event(void *para)
{
    U32 i;
    for (i = 0; i < sizeof(key_evt) / sizeof(key_evt[0]); i++)
    {
        MMI_ASSERT(key_evt[i].res == is_valid_mmi_key_event(key_evt[i].key_code, key_evt[i].key_type));
    }
    kal_prompt_trace(MOD_MMI, "[UT_KEY] ut_is_valid_mmi_key_event PASS!!");
    return MMI_RET_OK;
}


mmi_ret ut_is_pre_process_dev_evt(void *para)
{
    
    key_data_struct data;
    dev_key_evt_struct in;
    dev_key_evt_struct out[4];
    U8 len;
    U32 i;
    U8 type[4] = {DRV_WM_KEYPRESS, DRV_WM_KEYLONGPRESS, DRV_WM_KEYREPEATED, DRV_WM_KEYRELEASE};
    init_key_data_buf();

    if (mmi_frm_kbd_is_key_supported(KEY_POWER) == MMI_TRUE)
    {
        in.device_key_code = DEVICE_KEY_POWER;
        in.device_key_type = DRV_WM_KEYLONGPRESS;
        in.is_clear = MMI_TRUE;
        pre_process_dev_evt(&in, out, &len);
        MMI_ASSERT(len == 4);
        for (i = 0; i < 4; i++)
        {
            MMI_ASSERT(out[i].device_key_code == DEVICE_KEY_POWER);
            MMI_ASSERT(out[i].device_key_type == type[i]);
            if (type[i] == in.device_key_type)
            { 
                MMI_ASSERT(out[i].is_clear == MMI_FALSE);
            }
            else
            {
                MMI_ASSERT(out[i].is_clear == MMI_TRUE);
            }
            
        }
        data.mmi_key_code = KEY_POWER;
        data.mmi_key_type = KEY_EVENT_DOWN;
        insert_key_data(&data);
        pre_process_dev_evt(&in, out, &len);
        MMI_ASSERT(len == 1);
        MMI_ASSERT(out[0].device_key_code == DEVICE_KEY_POWER);
        MMI_ASSERT(out[0].device_key_type == DRV_WM_KEYLONGPRESS);
        MMI_ASSERT(in.is_clear == MMI_TRUE);


        in.device_key_code = DEVICE_KEY_END;
        in.device_key_type = DRV_WM_KEYLONGPRESS;
        in.is_clear = MMI_TRUE;
        pre_process_dev_evt(&in, out, &len);
        MMI_ASSERT(len == 1);
        MMI_ASSERT(out[0].device_key_code == DEVICE_KEY_END);
        MMI_ASSERT(out[0].device_key_type == DRV_WM_KEYLONGPRESS);
        MMI_ASSERT(in.is_clear == MMI_TRUE);
    }
    else
    {
        in.device_key_code = DEVICE_KEY_END;
        in.device_key_type = DRV_WM_KEYLONGPRESS;
        in.is_clear = MMI_TRUE;
        pre_process_dev_evt(&in, out, &len);
        MMI_ASSERT(len == 4);
        for (i = 0; i < 4; i++)
        {
            MMI_ASSERT(out[i].device_key_code == DEVICE_KEY_END);
            MMI_ASSERT(out[i].device_key_type == type[i]);
            if (type[i] == in.device_key_type)
            { 
                MMI_ASSERT(out[i].is_clear == MMI_FALSE);
            }
            else
            {
                MMI_ASSERT(out[i].is_clear == MMI_TRUE);
            }
            
        }
        data.mmi_key_code = KEY_END;
        data.mmi_key_type = KEY_EVENT_DOWN;
        insert_key_data(&data);
        pre_process_dev_evt(&in, out, &len);
        MMI_ASSERT(len == 1);
        MMI_ASSERT(out[0].device_key_code == DEVICE_KEY_END);
        MMI_ASSERT(out[0].device_key_type == DRV_WM_KEYLONGPRESS);
        MMI_ASSERT(in.is_clear == MMI_TRUE);
        init_key_data_buf();
    }    

    for (i = 0; i < MAX_DEVICE_KEYS; i++)
    {
        in.device_key_code = i;
        in.device_key_type = 100;
        in.is_clear = MMI_FALSE;
        pre_process_dev_evt(&in, out, &len);
        if (!((((in.device_key_code == DEVICE_KEY_END) && 
            (MMI_FALSE == mmi_frm_kbd_is_key_supported(KEY_POWER))) || 
            ((in.device_key_code == DEVICE_KEY_POWER) && 
            (MMI_TRUE == mmi_frm_kbd_is_key_supported(KEY_POWER)))) && 
            (in.device_key_type == DRV_WM_KEYLONGPRESS)))
        { 
            MMI_ASSERT(len == 1);
            MMI_ASSERT(out[0].device_key_code == i);
            MMI_ASSERT(out[0].device_key_type == 100);
            MMI_ASSERT(out[0].is_clear == MMI_FALSE);
        }
    }
    kal_prompt_trace(MOD_MMI, "[UT_KEY] ut_is_pre_process_dev_evt PASS!!");
    return MMI_RET_OK;
}
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + key event unit test framework
 +
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/* key unit test table size */
#define KEY_UT_TABLE_ENTRY  sizeof(g_key_ut_table) / sizeof(g_key_ut_table[0])

/* unit test function */
typedef mmi_ret (*unit_test_func)(void *para);

/* unit test struct */
typedef struct
{
    U8 index;
    unit_test_func test;
} mmi_unit_test_struct;

/* key event unit test table */
const static mmi_unit_test_struct g_key_ut_table[] = 
{
    {1, ut_mmi_frm_init_key_event},
    {2, ut_mmi_frm_key_event_screen_switch_action},
    {3, ut_mmi_frm_kbd_is_key_supported},
    {4, ut_mmi_frm_get_key_info},
    {5, ut_mmi_frm_set_key_info},
    {6, ut_mmi_frm_get_key_handler},
    {7, ut_mmi_frm_set_key_handler},
    {8, ut_mmi_frm_set_group_key_handler},
    {9, ut_mmi_frm_clear_key_handler},
    {10, ut_mmi_frm_clear_all_key_handler},
    {11, ut_mmi_frm_query_mmi_key_state},
    {12, ut_mmi_frm_is_key_event},
    {13, ut_mmi_frm_exec_key_handler},
    {14, ut_init_key_data_buf},
    {15, ut_insert_key_data},
	{16, ut_search_key_data},
    {17, ut_update_key_data},
    {18, ut_remove_key_data},
    {19, ut_get_key_state},
    {20, ut_get_key_data},
    {22, ut_set_all_key_data_clear},
    {23, ut_update_clear_state},
    {24, ut_pre_update_key_data_buf},
    {25, ut_post_update_key_data_buf},
    {26, ut_gen_key_data},
    {27, ut_is_2step_key},
    {28, ut_get_2step_key_state},
    {29, ut_pre_update_2step_key_state},
    {30, ut_post_update_2step_key_state},
    {31, ut_get_mmi_key_type},
    {32, ut_is_legal_key_type},
    {33, ut_get_mmi_key_code},
    {34, ut_get_device_key_code},
    {35, ut_read_look_ahead_buffer},
    {36, ut_write_look_ahead_buffer},
    {37, ut_get_dev_key_evt},
    {38, ut_get_rotated_mmi_key_code},
    {39, ut_mmi_key_code_convert},
    {40, ut_get_any_key_handler},
    {41, ut_get_default_key_handler},
    {42, ut_get_key_handler},
    {43, ut_update_key_proc_data},
    {44, ut_get_exec_key_evt},
    {45, ut_get_mmi_key_events},		
	{46, ut_mmi_frm_set_key_proc},
    {47, ut_evt_routing_full_path_test},
    {48, ut_evt_routing_cat_pre_stop_test},
    {49, ut_evt_routing_list_pre_stop_test},
    {50, ut_evt_routing_on_stop_scr_test},
    {51, ut_evt_routing_on_stop_editor_test}, 
    {52, ut_evt_routing_stop_at_key_handler},
    {53, ut_evt_routing_scr_no_proc_check},
    {54, ut_evt_routing_proc_life_check},
    {55, ut_evt_routing_event_flow_check},
    {56, ut_is_need_write_back},
    {57, ut_mmi_frm_clear_key_events},
    {58, ut_is_combo_key},
    {59, ut_process_key_ptr_change},
    {60, ut_is_power_off_evt},
    {61, ut_is_pre_process_dev_evt}
};

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_key_event_ut
 * DESCRIPTION
 *  This function is key event unit test external interface.
 *  It is invoked in events.c (mmi_proc_inject_string)
 * 
 * PARAMETERS
 *  index         :[IN]  test item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_key_event_ut(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_frm_key_evt_struct a;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_CONSTRUCT_KEY_EVENT(&a, 1, 2, 3, 0);
    MMI_ASSERT(a.key_code == 1);
    MMI_ASSERT(a.key_type == 2);
    MMI_ASSERT(a.ucs2_value == 3);
    MMI_ASSERT(a.special_key_flag == 0);
    if (index == 0)
    {
        for (i = 0; i < KEY_UT_TABLE_ENTRY; i++)
        {
            g_key_ut_table[i].test(NULL);
        }
    }
    else
    {
        for (i = 0; i < KEY_UT_TABLE_ENTRY; i++)
        {
            if (g_key_ut_table[i].index == index)
            {
                g_key_ut_table[i].test(NULL);
            }
        }
    }
}
#endif /* MMI_FRM_KEY_EVENT_UT */

