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
 *   browser_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for local parameter declaration about Browser SAP
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *                              HISTORY
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
 *==============================================================================
 *******************************************************************************/
#ifndef _BROWSER_STRUCT_H
#define _BROWSER_STRUCT_H 

#include "kal_general_types.h"

typedef enum
{
    WAP_SIM_ID_DEFAULT,
    WAP_SIM_ID_SIM1,
    WAP_SIM_ID_SIM2,
    WAP_SIM_ID_SIM3,
    WAP_SIM_ID_SIM4,
    WAP_SIM_ID_DUAL_SIM,
    WAP_SIM_ID_NO_SIM,
    WAP_SIM_ID_FLIGHT_MODE,
    WAP_SIM_ID_MAX_ITEM
} wap_sim_id_enum;

typedef enum
{
    WAP_SIM_TYPE_VALID_SIM = 0,
    WAP_SIM_TYPE_INVALID_SIM,
    WAP_SIM_TYPE_BLOCKED_SIM,
    WAP_SIM_TYPE_UNKNOWN,
    WAP_SIM_TYPE_MAX_ITEM
} wap_sim_type_enum;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 browserMode;
    kal_uint8 browserIdentity;
    kal_uint8 sim_id;
    kal_uint8 *url;
    kal_uint8 *bearer;
    kal_uint8 *gateway;
    kal_uint16 noUrl;
    kal_uint16 noBearer;
    kal_uint16 noGateway;
} wap_mmi_lauch_browser_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 res;
    kal_uint8 additionalInfo;
    kal_uint8 sim_id;
} wap_mmi_lauch_browser_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 type;
    kal_uint8 url[768];
} wap_browser_startup_req_struct;

typedef enum
{
    WAP_BEARER_STATUS_GPRS,
    WAP_BEARER_STATUS_WIFI
} wap_bearer_status_type_enum;

typedef enum
{
    WAP_GPRS_NONE,
    WAP_GPRS_COVERAGE,
    WAP_GPRS_ATTACHED,
    WAP_GPRS_DETACHED
} wap_gprs_state_enum;

#endif /* _BROWSER_STRUCT_H */
