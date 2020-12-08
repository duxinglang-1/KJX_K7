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
 *   PnSrvProt.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements Push notification service.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef __SRV_PNS_PROT_H__
#define __SRV_PNS_PROT_H__
/*****************************************************************************
 * Include
 *****************************************************************************/
#include "mmi_features.h"

#ifdef __MMI_PNS__
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_trace.h"

#include "MMIDataType.h"
#include "mmi_cb_mgr_gprot.h"
#include "PnSrvGprot.h"

/*****************************************************************************
 * Define
 *****************************************************************************/

#define SRV_PNS_TRACE0(tr)                  kal_trace(TRACE_GROUP_7, tr)
#define SRV_PNS_TRACE1(tr, a1)              kal_trace(TRACE_GROUP_7, tr, a1)
#define SRV_PNS_TRACE2(tr, a1, a2)          kal_trace(TRACE_GROUP_7, tr, a1, a2)
#define SRV_PNS_TRACE3(tr, a1, a2, a3)      kal_trace(TRACE_GROUP_7, tr, a1, a2, a3)
#define SRV_PNS_TRACE4(tr, a1, a2, a3, a4)  kal_trace(TRACE_GROUP_7, tr, a1, a2, a3, a4)
#define SRV_PNS_TRACE6(tr, a1, a2, a3, a4, a5, a6)  kal_trace(TRACE_GROUP_7, tr, a1, a2, a3, a4, a5, a6)

typedef struct 
{
    U32 appId;
    mmi_proc_func cb;
    void *user_data;
    char senderId[SRV_PNS_SENDERID_LEN];
} srv_pns_reg_req_struct;

typedef struct 
{
    U32 appId;
    mmi_proc_func cb;
    void *user_data;
} srv_pns_dereg_req_struct;

typedef struct _srv_pns_request_element_struct
{
    MMI_BOOL reg;
    union{
        srv_pns_reg_req_struct reg;
        srv_pns_dereg_req_struct dereg;
    } request;

    struct _srv_pns_request_element_struct* pre;
    struct _srv_pns_request_element_struct* next;
} srv_pns_request_element_struct;

typedef struct _srv_pns_msg_cb_struct
{
    U32 appId;
    mmi_proc_func cb;
    S32 payloadLen;
    char* payload;
    void* user_data;

    struct _srv_pns_msg_cb_struct* pre;
    struct _srv_pns_msg_cb_struct* next;
} srv_pns_msg_cb_struct;

/* Should be the same as NVRAM_EF_SRV_PNS_MAX_BUNDLE_APP_ID*/
#define SRV_PNS_MAX_BUNDLE_APP 20  /* Should be the same as NVRAM_EF_SRV_PNS_MAX_BUNDLE_APP_ID*/

/* Should be the same as nvram_ef_srv_pns_app_statistics_struct*/
typedef struct{
	U32 appId;
	U32 numOfCTViaNC;
	U32 numOfCTViaPop;
	U32 numOfCTViaIconWithPara;
	U32 numOfCTViaIconNoPara;
	U32 numOfCTViaOthers;
	U32 durationOfLaunchApp;
} srv_pns_statistic_struct;

typedef struct _srv_pns_statistic_duration_struct
{
	U32 appId;
	U32 start;

    struct _srv_pns_statistic_duration_struct* pre;
    struct _srv_pns_statistic_duration_struct* next;
} srv_pns_statistic_duration_struct;


/******************************************************************************
 * FUNCTION
 *    srv_pns_json_alloc
 * DESCRIPTION
 *    allocator for jason parser
 * PARAMETERS
 *    void
 * RETURNS
 *    void
 ******************************************************************************/
void* srv_pns_json_alloc(size_t);

/******************************************************************************
 * FUNCTION
 *    srv_pns_json_free
 * DESCRIPTION
 *    allocator for jason parser
 * PARAMETERS
 *    void
 * RETURNS
 *    void
 ******************************************************************************/
void srv_pns_json_free(void *);

mmi_ret srv_pns_cbm_event_receiver(mmi_event_struct *param);
void srv_pns_send_dereg_req(U32 appId);
void srv_pns_send_msg_rsp(U32 appId);

#endif /* __MMI_PNS__ */
#endif /* __SRV_PNS_PROT_H__ */
