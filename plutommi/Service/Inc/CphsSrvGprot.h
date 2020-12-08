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
 *  CphsSrvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contains prototypes for CPHS service layer.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef CPHSSRVGPROT_H
#define CPHSSRVGPROT_H

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "ps_public_struct.h"

#ifdef __cplusplus
extern "C"
{
#endif

/* CPHS Group */
typedef enum
{
    SRV_CPHS_GROUP_CALL_OFFERING,                   /* Call offering */
    SRV_CPHS_GROUP_CALL_RESTRICTION,                /* Call Restriction */
    SRV_CPHS_GROUP_OTHER_SUPP_SERVICES,             /* Other Supp Services */
    SRV_CPHS_GROUP_CALL_COMPLETION,                 /* Call Completion */
    SRV_CPHS_GROUP_TELESERVICES,                    /* Teleservices */
    SRV_CPHS_GROUP_CPHS_TELESERVICES,               /* CPHS Teleservices */
    SRV_CPHS_GROUP_CPHS_FEATURES,                   /* CPHS Features */
    SRV_CPHS_GROUP_NUMBER_IDENTIFI,                 /* Number Identif. */
    SRV_CPHS_GROUP_PHASE_2_PLUS_SERVICES,           /* Phase 2+ services */
    SRV_CPHS_GROUP_VALUE_ADDED_SERVICES,            /* ValueAdded Services */
    SRV_CPHS_GROUP_INFORMATION_NUMBERS,             /* Information Numbers */
    SRV_CPHS_GROUP_TOTAL                            /* Total count of CPHS Group */
} srv_cphs_group_enum;


/* CPHS Service */
typedef enum
{
    /* Call offering */
    SRV_CPHS_SERVICE_CT = 3,                        /* Call Transfer */
    SRV_CPHS_SERVICE_CFNRC,                         /* Call Forwarding On User Not Reachable */
    SRV_CPHS_SERVICE_CFNRY,                         /* Call Forwarding on No Reply */
    SRV_CPHS_SERVICE_CFB,                           /* Call Forwarding On User Busy */
    SRV_CPHS_SERVICE_CFU,                           /* Call Forwarding Unconditional */
    /* Call Restriction */
    SRV_CPHS_SERVICE_BIC_ROAM = 3,                  /* Barring of Incoming Calls when Roaming Outside the Home PLMN country */
    SRV_CPHS_SERVICE_BAIC,                          /* Barring of All Incoming Calls */
    SRV_CPHS_SERVICE_BOIC_EXHC,                     /* Barring of Outgoing International Calls except those directed to the Home PLMN country */
    SRV_CPHS_SERVICE_BOIC,                          /* Barring of Outgoing International Calls */
    SRV_CPHS_SERVICE_BOAC,                          /* Barring of All Outgoing Calls */
    /* Other Supp Services */
    SRV_CPHS_SERVICE_CUG_OA = 3,                    /* CUG Outgoing Access */
    SRV_CPHS_SERVICE_PREF_CUG,                      /* Preferential CUG */
    SRV_CPHS_SERVICE_AOC,                           /* Advice Of Charge */
    SRV_CPHS_SERVICE_CUG,                           /* Closed User Group */
    SRV_CPHS_SERVICE_MPTY,                          /* Multi-Party Service */
    /* Call Completion */
    SRV_CPHS_SERVICE_USER_USER_SIGNALLING = 4,      /* Restriction of menus allowing use of user to user signalling */
    SRV_CPHS_SERVICE_CCBS,                          /* Completion of Call to Busy Subscriber */
    SRV_CPHS_SERVICE_CW,                            /* Call Waiting */
    SRV_CPHS_SERVICE_HOLD,                          /* Call Hold */
    /* Teleservices */
    SRV_CPHS_SERVICE_VALIDITY_PERIOD = 1,           /* Restriction of menus for SMS Validity period options */
    SRV_CPHS_SERVICE_PROTOLCOL_ID,                  /* Restriction of menus for SMS Protocol ID options */
    SRV_CPHS_SERVICE_DEL_CONF,                      /* SMS Delivery Confirmation */
    SRV_CPHS_SERVICE_REPLY_PATH,                    /* Restricts menu options for the ability to set reply path active on outgoing Short Messages */
    SRV_CPHS_SERVICE_SM_CB,                         /* Short Message - Cell Broadcast */
    SRV_CPHS_SERVICE_SM_MO,                         /* Short Message - Mobile Originated */
    SRV_CPHS_SERVICE_SM_MT,                         /* Short Message - Mobile Terminated */
    /* CPHS Teleservices */
    SRV_CPHS_SERVICE_ALS = 7,                       /* Alternate Line Service */
    /* Number Identif. */
    SRV_CPHS_SERVICE_CLI_BLOCK = 0,                 /* CLI per call mode - default send CLI - menu to block CLI */
    SRV_CPHS_SERVICE_CLI_SEND,                      /* CLI per call mode - default block CLI - menu to send CLI */
    SRV_CPHS_SERVICE_MCI = 3,                       /* Malicious Call Indicator */
    SRV_CPHS_SERVICE_COLP,                          /* Connected Line Identification Presentation */
    SRV_CPHS_SERVICE_COLR,                          /* Connected Line Identification Restriction */
    SRV_CPHS_SERVICE_CLIP = 7,                      /* Calling Line Identification Presentation */
    /* Phase 2+ services */
    SRV_CPHS_SERVICE_MULTIPLE_BAND = 2,             /* Restriction of menus allowing user to select a particular GSM 900/ 1800 or 1900 band */
    SRV_CPHS_SERVICE_MULTIPLE_SUBSCRIBER_PROFILE,   /* Phase 2+ multiple subscriber profile menus */
    SRV_CPHS_SERVICE_VOICE_BROADCAST_SERVICE,       /* ASCI Voice broadcast service menus */
    SRV_CPHS_SERVICE_VOICE_GROUP_CALL,              /* ASCI Voice Group call menus */
    SRV_CPHS_SERVICE_HSCSD,                         /* Menus concerned with High Speed Circuit Switched Data functionality */
    SRV_CPHS_SERVICE_GPRS,                          /* Menus concerned with GPRS functionality */
    /* Value Added Services */
    SRV_CPHS_SERVICE_LANGUAGE = 0,                  /* Restriction of menus allowing the user to change language */
    SRV_CPHS_SERVICE_DATA = 2,                      /* Restriction of menu options for Data calls */
    SRV_CPHS_SERVICE_FAX,                           /* Restriction of menu options for Fax calls */
    SRV_CPHS_SERVICE_SM_MO_EMAIL,                   /* Restriction of menu options for the ability to send Short messages with type Email */
    SRV_CPHS_SERVICE_SM_MO_PAGING,                  /* Restriction of menu options for the ability to send Short messages with type Paging */
    SRV_CPHS_SERVICE_VPS,                           /* Restriction of menu options for Voice Mail or other similar menus */
    SRV_CPHS_SERVICE_PLMN_MODE                      /* Restriction of menu options for manual PLMN selection */
} srv_cphs_service_enum;


/* MSISDN Type */
typedef enum
{
    SRV_CPHS_MSISDN_TYPE_LINE1,                     /* LINE 1 */
    SRV_CPHS_MSISDN_TYPE_LINE2,                     /* LINE 2 */
    SRV_CPHS_MSISDN_TYPE_TOTAL                      /* Total count of MSISDN Type */
} srv_cphs_msisdn_type_enum;

/* DOM-NOT_FOR_SDK-BEGIN */

/* EVT_ID_SRV_CPHS_CSP_REFRESH */
typedef enum
{
    EVT_ID_SRV_CPHS_CSP_REFRESH = CPHS_BASE + 1,
} srv_cphs_event_enum;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    mmi_sim_enum sim_id;
} srv_cphs_csp_refresh_struct;

/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  srv_cphs_init
 * DESCRIPTION
 *  This function is used to register CPHS INFO indication.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_cphs_init(void);


/*****************************************************************************
 * FUNCTION
 *  srv_cphs_parse_csp_info
 * DESCRIPTION
 *  This function is used to parse CSP information when SIM refresh happens (File Change: EFcsp).
 * PARAMETERS
 *  csp_data:   [IN]        CSP data (22 bytes)
 *  sim:        [IN]        MMI_SIM1/MMI_SIM2
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_cphs_parse_csp_info(U8 *csp_data, mmi_sim_enum sim);

/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  srv_cphs_is_valid_csp
 * DESCRIPTION
 *  This function is used to check if there is a valid CSP present on the SIM.
 * PARAMETERS
 *  sim:        [IN]        MMI_SIM1/MMI_SIM2
 * RETURNS
 *  MMI_TRUE if has, otherwise MMI_FALSE
 *****************************************************************************/
extern MMI_BOOL srv_cphs_is_valid_csp(mmi_sim_enum sim);


/*****************************************************************************
 * FUNCTION
 *  srv_cphs_is_service_available
 * DESCRIPTION
 *  This function is used to check if the menu item(s) relevant to that service can be presented
 *  to the user.
 *  If it is not a valid CSP, we will treat all the services as available!!!
 *  If the menu item(s) relevant to that service do(es) not want to be displayed in this case,
 *  then you MUST use the check API "srv_cphs_is_valid_csp" for additional check.
 * PARAMETERS
 *  group:      [IN]        CPHS Group
 *  service:    [IN]        CPHS Service
 *  sim:        [IN]        MMI_SIM1/MMI_SIM2
 * RETURNS
 *  MMI_TRUE if available, otherwise MMI_FALSE
 *****************************************************************************/
extern MMI_BOOL srv_cphs_is_service_available(srv_cphs_group_enum group, srv_cphs_service_enum service, mmi_sim_enum sim);


/* DOM-NOT_FOR_SDK-BEGIN */

/*****************************************************************************
 * FUNCTION
 *  srv_cphs_parse_msisdn_info
 * DESCRIPTION
 *  This function is used to parse MSISDN information when SIM refresh happens (File Change: EFmsisdn).
 * PARAMETERS
 *  no_msisdn:      [IN]        No. of MSISDN
 *  msisdn:         [IN]        MSISDN data
 *  sim:            [IN]        MMI_SIM1/MMI_SIM2
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_cphs_parse_msisdn_info(U8 no_msisdn, l4csmu_addr_struct *msisdn, mmi_sim_enum sim);

/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  srv_cphs_get_msisdn_name
 * DESCRIPTION
 *  This function is used to get MSISDN name by type.
 * PARAMETERS
 *  msisdn_type:    [IN]        MSISDN Type
 *  sim:            [IN]        MMI_SIM1/MMI_SIM2
 * RETURNS
 *  MSISDN name
 *****************************************************************************/
extern const WCHAR* srv_cphs_get_msisdn_name(srv_cphs_msisdn_type_enum msisdn_type, mmi_sim_enum sim);


/*****************************************************************************
 * FUNCTION
 *  srv_cphs_get_msisdn_number
 * DESCRIPTION
 *  This function is used to get MSISDN number by type.
 * PARAMETERS
 *  msisdn_type:    [IN]        MSISDN Type
 *  sim:            [IN]        MMI_SIM1/MMI_SIM2
 * RETURNS
 *  MSISDN number
 *****************************************************************************/
extern const WCHAR* srv_cphs_get_msisdn_number(srv_cphs_msisdn_type_enum msisdn_type, mmi_sim_enum sim);

#ifdef __cplusplus
}
#endif

#endif /* CPHSSRVGPROT_H */

