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
 * DHCP2ABM_STRUCT.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file describes the common struct of DHCP and ABM.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _DHCP2ABM_STRUCT_H_
#define _DHCP2ABM_STRUCT_H_

#include "dhcp_consts.h"
//#include "soc_api.h"
#include "dhcp_abm_enums.h"
//#include "kal_non_specific_general_types.h"
#include "kal_general_types.h"

#include "soc_consts.h"
/***************************************************************************
 * <GROUP Structures>
 *
 * Local parameter of MSG_ID_ABM_DHCP_GET_IP_REQ
***************************************************************************/
typedef struct {
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_uint8       account_id; /* Network account ID */    
    kal_bool        readfile;   /* load saved parameters of previous session */
    kal_uint8       mac_addr[ETHER_ADDR_LEN]; /* MAC address of the interface */
    kal_uint8       parameters[DHCP_MAX_MSG_SIZE]; /* Additional requested
                                                      parameters.  Contains a
                                                      list of the option code.
                                                      The code must be ended
                                                      with 0x00. */
} abm_dhcp_get_ip_req_struct;


/***************************************************************************
 * <GROUP Structures>
 *
 * Local parameter of MSG_ID_ABM_DHCP_GET_IP_CNF
 ***************************************************************************/
typedef struct {
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_uint8       account_id; /* Network account ID */    
    kal_bool        result;     /* Result of the operation */
    kal_uint8       message[DHCP_MAX_MSG_SIZE]; /* Message from DHCP server */
    kal_uint8       your_ip[IP_ADDR_LEN]; /* Local IP address assigned by
                                             DHCP server */
    kal_uint8       netmask[IP_ADDR_LEN]; /* Netmask */
    kal_uint8       gateway[IP_ADDR_LEN]; /* Gateway of the LAN */
    kal_uint8       dns1[IP_ADDR_LEN]; /* Primary DNS server's IP address */
    kal_uint8       dns2[IP_ADDR_LEN]; /* Secondary DNS server's IP address */
    kal_uint16      mtu;               /* MTU of the interface */
} abm_dhcp_get_ip_cnf_struct;


/***************************************************************************
 * <GROUP Structures>
 *
 * Local parameter of MSG_ID_ABM_DHCP_RELEASE_REQ
 ***************************************************************************/
typedef struct {
    kal_uint8       ref_count;
    kal_uint16      msg_len;
    kal_uint8       account_id; /* Network account ID */
} abm_dhcp_release_req_struct;


/***************************************************************************
 * <GROUP Structures>
 *
 * Local parameter of MSG_ID_ABM_DHCP_RELEASE_CNF
 ***************************************************************************/
typedef struct {
    kal_uint8     ref_count;
    kal_uint16    msg_len;
    kal_uint8     account_id; /* Network account ID */    
} abm_dhcp_release_cnf_struct;


/***************************************************************************
 * <GROUP Structures>
 *
 * Local parameter of MSG_ID_ABM_DHCP_NOTIFY_IND
 ***************************************************************************/
typedef struct {
    kal_uint8     ref_count;
    kal_uint16    msg_len;
    kal_uint8     account_id;   /* Network account ID */    
    dhcp_abm_notify_cause_enum    cause; /* status code of the reported event */
    kal_uint8     message[DHCP_MAX_MSG_SIZE]; /* Message from DHCP server */
    kal_uint8     your_ip[IP_ADDR_LEN]; /* Local IP address assigned by
                                           DHCP server */
    kal_uint8     netmask[IP_ADDR_LEN]; /* Netmask */
    kal_uint8     gateway[IP_ADDR_LEN]; /* Gateway of the LAN */
    kal_uint8     dns1[IP_ADDR_LEN]; /* Primary DNS server's IP address */
    kal_uint8     dns2[IP_ADDR_LEN]; /* Secondary DNS server's IP address */
    kal_uint16    mtu;               /* MTU of the interface */
} abm_dhcp_notify_ind_struct;

/***************************************************************************
 * <GROUP Structures>
 *
 * Local parameter of MSG_ID_ABM_DHCP_WIFI_AP_STATE_IND
 ***************************************************************************/
typedef struct {
    kal_uint8     ref_count;
    kal_uint16    msg_len;
    kal_uint8     ap_state; /* WIFI AP state */    
} abm_dhcp_wifi_ap_state_ind_struct;

#endif /* !_DHCP2ABM_STRUCT_H_ */


