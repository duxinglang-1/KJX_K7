/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  CbmSrvWlanPrefer.h
 *
 * Project:
 * --------
 *  CBM Service WLAN Prefer
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _CBM_SRV_WLAN_PREFER_H
#define _CBM_SRV_WLAN_PREFER_H

#include "MMI_include.h"
#include "MMIDataType.h"

#ifdef __MMI_WLAN_FEATURES__

#include "DtcntSrvIprot.h"

#include "CbmSrvFeature.h"
#include "CbmSrvIntProt.h"
#include "CbmSrvGprot.h"
#include "CbmSrvIprot.h"

extern void srv_cbm_proc_app_startup(
                srv_cbm_app_cntx_struct *app_p,
                srv_cbm_wlan_query_type_enum query_type,
                U32 bearer_type);
extern void srv_cbm_proc_app_disconnected(
                srv_cbm_app_cntx_struct *app_p,
                srv_cbm_wlan_query_type_enum query_type,
                U32 bearer_type);
extern void srv_cbm_send_wlan_query_event(srv_cbm_wlan_query_type_enum query_type);
extern void srv_cbm_set_wlan_query_type(srv_cbm_wlan_query_type_enum query_type);
extern srv_cbm_wlan_query_type_enum srv_cbm_get_wlan_query_type(
                                        MMI_BOOL get_ori_type,
                                        srv_cbm_wlan_query_type_enum new_query_type);
extern srv_cbm_wlan_query_type_enum srv_cbm_get_wlan_query_type(
                                        MMI_BOOL get_ori_type,
                                        srv_cbm_wlan_query_type_enum new_query_type);
extern MMI_BOOL srv_cbm_is_wlan_query_type_valid(srv_cbm_wlan_query_type_enum query_type);
extern srv_cbm_wlan_query_type_enum srv_cbm_get_next_wlan_query_type(void);
extern void srv_cbm_start_wlan_auto_search_timer(void);
extern void srv_cbm_stop_wlan_auto_search_timer(void);
extern void srv_cbm_start_wlan_prefer_timer(void);
extern MMI_BOOL srv_cbm_is_wlan_prefer_timer_running(void);
extern void srv_cbm_set_wlan_prefer_delay_timeout(U32 sec);

extern MMI_BOOL srv_cbm_is_wlan_sleep(void);

#endif /* __MMI_WLAN_FEATURES__ */

#endif /* _CBM_SRV_WLAN_PREFER_H */

