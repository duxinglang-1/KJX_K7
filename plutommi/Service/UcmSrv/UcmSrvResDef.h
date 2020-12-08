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
 *  UcmSrvResDef.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  UCM service resource
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef SRV_UCM_RES_DEF_H
#define SRV_UCM_RES_DEF_H

#include "MMIDatatype.h"

typedef enum
{
    STR_ID_SRV_UCM_RESULT_USER_ABORT = (SRV_UCM_BASE + 1),
    STR_ID_SRV_UCM_RESULT_EMPTY_NUMBER,
    STR_ID_SRV_UCM_RESULT_CALLED_PARTY_BUSY,
    STR_ID_SRV_UCM_RESULT_NETWORK_NOT_AVAILABLE,
    STR_ID_SRV_UCM_RESULT_CALLED_PARTY_NOT_ANSWERED,
    STR_ID_SRV_UCM_RESULT_UCM_BUSY,
    STR_ID_SRV_UCM_RESULT_CANCEL,
    STR_ID_SRV_UCM_RESULT_FLIGHT_MODE_PROHIBIT,
    STR_ID_SRV_UCM_RESULT_PREFERRED_MODE_PROHIBIT,
    STR_ID_SRV_UCM_RESULT_SOS_CALL_EXISTS,
    STR_ID_SRV_UCM_RESULT_SOS_NUMBER_ONLY,
    STR_ID_SRV_UCM_RESULT_LOW_BATTERY,
    STR_ID_SRV_UCM_RESULT_NOT_ALLOWED_TO_DIAL,
    STR_ID_SRV_UCM_RESULT_NOT_ALLOWED_TO_ACCEPT,
    STR_ID_SRV_UCM_RESULT_ACTION_NOT_ALLOWED,
    STR_ID_SRV_UCM_RESULT_NO_ACTIVE_CALL,
    STR_ID_SRV_UCM_TOTAL
} srv_ucm_string_enum;

#endif /* SRV_UCM_RES_DEF_H */ 


