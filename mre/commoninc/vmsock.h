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
 *  vmsock.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  socket
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef VM_SOCK_H
#define VM_SOCK_H

#include "vmswitch.h"

#ifdef __MRE_SAL_SOCKET__

#include "vmsock_sdk.h"

#else /* __MRE_SAL_SOCKET__ */

#define vm_tcp_connect (void*)NULL
#define vm_wifi_is_connected (void*)NULL
#define vm_tcp_close (void*)NULL
#define vm_is_support_wifi (void*)NULL
#define vm_tcp_read (void*)NULL
#define vm_tcp_write (void*)NULL
#define vm_get_apn_info (void*)NULL
#define vm_soc_get_host_by_name (void*)NULL
#define vm_get_encoded_dtacct_id (void*)NULL
#define vm_wlan_loc_search (void*)NULL
#define vm_wlan_loc_search_abort (void*)NULL
#define vm_wlan_loc_get_connected_info (void*)NULL
#define vm_udp_create (void*)NULL
#define vm_udp_sendto (void*)NULL
#define vm_udp_recvfrom (void*)NULL
#define vm_udp_close (void*)NULL
#define vm_srv_nw_info_get_protocol (void*)NULL
#define vm_get_default_apn_info (void*)NULL
#define vm_dtacct_set (void*)NULL
#define vm_dtacct_select (void*)NULL
#define vm_cbm_hold_bearer (void*)NULL
#define vm_cbm_release_bearer (void*)NULL
#define vm_set_cust_apn_info (void*)NULL
#define vm_get_cust_apn_info (void*)NULL
#define vm_srv_nw_info_channel_supports (void*)NULL
#define vm_wlan_perfer (void*)NULL

#endif /* __MRE_SAL_SOCKET__ */


#endif /* VM_SOCK_H */

