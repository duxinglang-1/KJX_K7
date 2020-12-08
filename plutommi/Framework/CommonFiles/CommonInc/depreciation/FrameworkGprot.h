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
 *  FrameworkGprot.h
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef FRAMEWORK_GPROT_H
#define FRAMEWORK_GPROT_H

#if	defined(UNICODE) && defined(_WINDOWS_)
#error "Please don't include windows.h and FrameworkGprot.h together when defined UNICODE, because they have redefinition problem!"
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
#include "stack_msgs.h"         /* Message ID */
#include "app_ltlcom.h"         /* Task message communiction */
#include "app_buff_alloc.h"     /* Control buffer */
#include "stack_timer.h"        /* stack_timer_struct */
#include "l4a.h"                /* L4 data type */
#include "MMIDataType.h"
#include "GlobalConstants.h"
#include "FrameworkStruct_Int.h"

/* Trace & debug related service */
#include "MMI_trc_int.h"
#include "MMI_fw_trc.h"
#include "MMI_inet_app_trc.h"
#include "MMI_media_app_trc.h"
#include "MMI_common_app_trc.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"

/* Memory related service */
#include "mmu.h"    /* for kal_adm_alloc_noncacheable() */
#include "OslMemory_Int.h"
#include "app_mem.h"
#include "AppMemMgrGprot_Int.h"
#include "ScrMemMgrGprot_Int.h"
#include "mmi_frm_mem_gprot.h"

/* OSL related service */
#include "QueueGprot_Int.h" 
#include "KeyBrd_Int.h"
#include "TimerEvents.h"
#include "MMITimer_Int.h"
#include "taskInit.h"
#include "MMItaskGprot.h"

/* NVRAM related service */
#include "NVRAMGprot.h"

/* History related service */
#include "HistoryGprot_Int.h"
#include "SubLCDHistoryGprot_Int.h"

/* EventHandling related service */
#include "EventsDcl.h"
#include "EventsDef_Int.h"
#include "EventsGprot_Int.h"
#include "TouchScreenGprot_Int.h"
#include "mmi_frm_gestures_gprot.h"

/* ThemeManager related service */
#include "ThemeManager.h"

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

/* String related service */
#include "Unicodexdcl.h"

/* File system related service */
#include "fs_type.h"
#include "fs_func.h" 
#include "fs_errcode.h"

/* Clipboard related service */
#include "mmi_clipboard_gprot.h"
#endif /* FRAMEWORK_GPROT_H*/ 

