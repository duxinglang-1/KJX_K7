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
*  MREPushSrvProt.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  MRE Push Service implement file.
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
#ifndef __MRE_PUSH_SRV_PROT_H__
#define __MRE_PUSH_SRV_PROT_H__
#include "MMI_features.h"
#include "vmswitch.h" 
#ifdef __MRE_SAL_PN__
#include "MMIDataType.h"
#include "mmi_cb_mgr_gprot.h"
#include "PnSrvGprot.h"
#include "MREAppMgrSrvGprot.h"
#include "vmpn.h"

#ifdef __COSMOS_MMI_PACKAGE__
#include "mmi_rp_vapp_app_manager_def.h"
#define STR_ID_LAUNCH_FAIL STR_ID_VAPP_AM_POPUP_LAUNCH_FAIL
#else
#include "mmi_rp_app_am_def.h"
#define STR_ID_LAUNCH_FAIL STR_ID_AM_FAIL_TO_START
#endif

#define PUSH_AUDIO_ID_BEGIN 100000
#define PUSH_VIDEO_ID_BEGIN 101000
#define PUSH_BINARY_ID_BEGIN 102000
#define PUSH_IMAGE_ID_BEGIN 103000
#define PUSH_STRING_ID_BEGIN 104000
#define PUSH_LAYOUT_ID_BEGIN 110000

#define MPR_TRACE0(tr)                  MMI_TRACE(TRACE_GROUP_6, tr)
#define MPR_TRACE1(tr, a1)              MMI_TRACE(TRACE_GROUP_6, tr, a1)
#define MPR_TRACE2(tr, a1, a2)          MMI_TRACE(TRACE_GROUP_6, tr, a1, a2)
#define MPR_TRACE3(tr, a1, a2, a3)      MMI_TRACE(TRACE_GROUP_6, tr, a1, a2, a3)
#define MPR_TRACE4(tr, a1, a2, a3, a4)  MMI_TRACE(TRACE_GROUP_6, tr, a1, a2, a3, a4)
#define MPR_TRACE6(tr, a1, a2, a3, a4, a5, a6)  MMI_TRACE(TRACE_GROUP_6, tr, a1, a2, a3, a4, a5, a6)

#ifndef VM_PNS_NOTIFY_SWITCH_MASK
#define VM_PNS_NOTIFY_SWITCH_MASK 0x10000000
#endif

#ifndef VM_PNS_NOTIFY_STYLE_MASK
#define VM_PNS_NOTIFY_STYLE_MASK  0x11111111
#endif


//typedef struct srv_pns_msg_mps_struct vm_pns_msg_mps_struct;
typedef struct vm_push_receiver_context_t
{
    int app_id;
    int app_handle;
    mmi_proc_func call_back;
}vm_push_receiver_context_t;
typedef struct mmi_mpr_popup_message_struct
{
    srv_pns_msg_mps_struct pns_msg_mps;
    WCHAR* app_path;	
    U32 app_id;
}mmi_mpr_popup_message_struct;

// MPR- MRE PUSH RECEIVER
typedef enum
{
    SRV_MRE_MPR_APP_HANDLE_REG = 0,
    SRV_MRE_MPR_APP_HANDLE_DEREG,

    SRV_MRE_MPR_APP_HANDLE_END,
} srv_mre_mpr_app_handle_event;

typedef enum
{
    SRV_MRE_MPR_NATIVE_HANDLE_REG = 0,
    SRV_MRE_MPR_NATIVE_HANDLE_DEREG,

    SRV_MRE_MPR_NATIVE_HANDLE_END,
} srv_mre_mpr_native_handle_event;


typedef enum
{
    SRV_MRE_MPR_QUERY_APP_ID = 0,
    SRV_MRE_MPR_QUERY_SENDER_ID,		
    SRV_MRE_MPR_QUERY_REGISTER_ID,
    SRV_MRE_MPR_QUERY_SETTING_STATUS,
    SRV_MRE_MPR_QUERY_BADGE,
    SRV_MRE_MPR_QUERY_PAYLOAD,
    SRV_MRE_MPR_QUERY_PAYLOAD_COUNT,
    SRV_MRE_MPR_QUERY_PAYLOAD_BY_INDEX,
    SRV_MRE_MPR_QUERY_MULTIPLE_PAYLOAD,
    SRV_MRE_MPR_QUERY_END,
} srv_mre_mpr_query_event;

#define MAX_PENDING_POPUP_COUNT 10
#define MAX_PUSH_REGISTER_ID_LENGTH 48
#define MAX_PUSH_SENDER_ID_LENGTH 48
#define MAX_PUSH_APP_ITOA_NAME_LENGTH 16

typedef struct
{
    U32 index;
    U8 * app_payload;
}one_payload_by_index;

typedef      U8 	char_one_payload_struct[MMI_PNS_MAX_MSGBODY_SIZE];
typedef struct
{
    U32 * payload_count;
    char_one_payload_struct * app_payload;
}multiple_payload_by_count;

typedef struct 
{
    U32 app_id;
    S32 popup_id;
} srv_mre_mpr_pending_popup;

typedef struct 
{
    U32 app_id;
    int icon_id;
} srv_mre_mpr_status_icon;
typedef struct
{
    U8  *img_buffer;
    U32 app_id;
} srv_mre_nmgr_data_struct;

extern S32 srv_mre_push_receiver_show_popup(mmi_mpr_popup_message_struct* para);
extern void srv_mre_push_receiver_hide_status_icon(U32 app_id);
extern void srv_mre_push_receiver_show_status_icon_only(U32 app_id, WCHAR* app_path, WCHAR* app_name, U32 icon_res);
extern void srv_mre_push_receiver_show_popup_wrapper(U32 ori_app_id, U32 app_id, WCHAR *app_path, WCHAR* app_name,char *msg_body,MMI_BOOL prefer_popup);
#endif//__MRE_SAL_PN__
#endif//__MRE_PUSH_SRV_PROT_H__
