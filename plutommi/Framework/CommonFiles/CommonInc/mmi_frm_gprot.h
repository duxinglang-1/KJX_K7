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
 *  mmi_frm_gprot.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Framework export function declaration
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *============================================================================
 ****************************************************************************/
#ifndef MMI_FRM_GPROT_H
#define MMI_FRM_GPROT_H

#ifdef __cplusplus
extern "C"
{
#endif

#if	defined(UNICODE) && defined(_WINDOWS_)
#error "Please don't include windows.h and mmi_frm_gprot.h together when defined UNICODE, because they have redefinition problem!"
#endif 

#ifndef FRAMEWORK_GPROT_H
/* after including "mmi_frm_gprot.h", we don't need to include "FrameworkGprot.h" anymore */
#define FRAMEWORK_GPROT_H
#define _FRAMEWORKSTRUCT_H
#define _TASKINIT_H
#define _MMITASKGPROT_H
#endif

/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Include header file
*****************************************************************************/

#include "MMI_features.h"
#include "kal_release.h"        /* Basic data type */
#include "stack_common.h"       /* Message ID range and SAP */

#include "stack_msgs.h"

#include "app_ltlcom.h"         /* Task message communiction */
#include "kal_public_api.h"     /* Control buffer */
#include "stack_timer.h"        /* stack_timer_struct */
#include "l4a.h"                /* L4 data type */
#include "MMIDataType.h"
#include "GlobalConstants.h"

#ifndef __RESOURCE_GEN_
#ifndef __VENDOR_SDK_EDITION__  /* these header files won't be released in SDK load */
/* Trace & debug related service */
#include "MMI_trc_int.h"
#include "MMI_fw_trc.h"
#include "pluto_fw_trc.h"
#include "MMI_inet_app_trc.h"
#include "MMI_media_app_trc.h"
#include "MMI_common_app_trc.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "MMI_mre_trc.h"
#endif /* __VENDOR_SDK_EDITION__ */
#endif
/* framework related service */
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_queue_gprot.h" 
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_nvram_gprot.h"
#include "mmi_frm_remutex_gprot.h"

#ifndef __VENDOR_SDK_EDITION__  /* these header files won't be released in SDK load */

#include "mmi_clipboard_gprot.h"
#include "mmi_frm_gestures_gprot.h"
#include "mmi_theme_mgr.h"

/* Utility related service */
#include "Unicodexdcl.h"
#include "mmi_cb_mgr_gprot.h"
#include "NotificationGprot.h"
#include "mmi_frm_utility_gprot.h"
#include "mmi_frm_at_util_gprot.h"
#include "mmi_frm_event_flag_gprot.h"

#endif /* __VENDOR_SDK_EDITION__ */

/* File system related service */
#include "fs_type.h"
#include "fs_func.h" 
#include "fs_errcode.h"

#ifndef __VENDOR_SDK_EDITION__  /* these header files won't be released in SDK load */
/* Backward compatible related service */
/* For dictionary binary without source code */
#if defined(__MMI_DICT_TRILOGY__)
	#define __MMI_FRAMEWORK_BACKWARD_COMPATIBLE_SPEC__
#endif
/* <hExpand noExpand> DO NOT REMOVE THIS LINE */
#if defined (__MMI_FRAMEWORK_BACKWARD_COMPATIBLE__) || defined (__MMI_FRAMEWORK_BACKWARD_COMPATIBLE_SPEC__)
#include "FrameworkBackwardCompatible_Int.h"
#endif /* __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__ */
/* </hExpand> DO NOT REMOVE THIS LINE */
#endif /* __VENDOR_SDK_EDITION__ */


/***************************************************************************** 
* Define
*****************************************************************************/


/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef task_entry_struct oslEntryType;

typedef enum _mmi_status_enum
{
    MMI_STATUS_NONE_WANT_TO_RUN,
    MMI_STATUS_INPUT_EVENTS_WANT_TO_RUN,
    MMI_STATUS_ONE_WANT_TO_RUN,
    MMI_STATUS_FEW_WANT_TO_RUN,
    MMI_STATUS_MEDIUM_WANT_TO_RUN,
    MMI_STATUS_MANY_WANT_TO_RUN,

    MMI_STATUS_MAX_WANT_TO_RUN
}mmi_status_enum;


/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/


/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

extern MMI_BOOL mmi_frm_is_mmi_task_started(void);
extern mmi_status_enum mmi_frm_check_wait_to_run(void);


#ifdef __cplusplus
}   /* extern "C" */
#endif

#endif /* MMI_FRM_GPROT_H */ 



