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

/*
 * Copyright (C) Obigo AB, 2002-2005.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Obigo AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Obigo AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */
 
/*! \file mms_a.c
 * \brief  In this file is the adapter functions in protyped in mms_int.h 
 *         implemented as reference code (example code). This functions
 *         needs to integrated in the target device envrionment. 
 */

/*--- Include files ---*/


/*******************************************************************************
 *
 * Filename:
 * ---------
 * mms_a.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * 
 *
 * Author:
 * -------
 * 
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
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "MMI_features.h"
#include "msf_cfg.h"
#include "msf_log.h"    /* MSF: Signal logging */ 
#include "mms_def.h"    /* MMS: Exported types in adapter/connector functions */
#include "mms_int.h"    /* MMS: MMS Exported Adapter functions */ 
#include "msf_log.h"    /* MSF: Signal logging */ 
#include "msf_core.h" /* MSF: Signal encapsulation */
#include "msf_mem.h"
#include "msm.h"

#include "mms_aApp.h"		
#include "WapDef.h"
#include "mconfig.h"
#include "mms_cfg.h"  //for MMS_MAX_NO_OF_MSG
#include "mms_if.h"
#include "msig.h"  /* for fldmgr.h */
#include "fldmgr.h" /* for MmsMessageFolderInfo */
#include "app_usedetails.h"

extern void HDIa_socketDiscBearerById(MSF_INT32 networkAccountID);

#ifdef __MMI_MMS_BGSR_SUPPORT__
extern void setBGSRdownloadWithProgressing(MSF_UINT8 value);
#endif /*__MMI_MMS_BGSR_SUPPORT__*/


/*--- Definitions/Declarations ---*/

/*--- Types ---*/

/*--- Constants ---*/

/*--- Forwards ---*/

/*--- Externs ---*/

/*--- Macros ---*/

/*--- Global variables ---*/

/*--- Static variables ---*/

/*--- Prototypes ---*/







MSF_BOOL MMSa_isFeatureSupported(MmsMMIFeature feature)
{
    switch(feature)
    {
    case MMS_MMI_FEATUER_NO_REJECT_NOTIFICATION_BY_SIZE:
#ifdef __MMI_WAP_MMS_NO_REJECT_NOTIFICATION_BY_SIZE__
        return TRUE;
#else
        return FALSE;
#endif

    case MMS_MMI_FEATUER_NO_DEFAULT_VALUE_IN_PDU_SUPPORT:
#ifdef __MMI_OP12_MMS_SUPPORT_NO_DEFAULT_VALUE_IN_PDU__
        return TRUE;
#else
        return FALSE;
#endif

    case MMS_MMI_FEATUER_SLIM_MMS:
#ifdef __MMI_SLIM_MMS_2__
        return TRUE;
#else
        return FALSE;
#endif


    default:
        return FALSE;
    }
}


MSF_BOOL MMSa_isValidNumber(char *addr)
{
    if(applib_is_valid_number((MSF_UINT8 *)addr) == APPLIB_INVALID_NUMBER)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}


MSF_BOOL MMSa_isValidEmailAddress(char *addr)
{
    return (MSF_BOOL)applib_is_valid_email_address((const char *)addr);
}


int MMSa_convertTimeToString(MSF_UINT32 date, char *s)
{
    return msf_cmmn_time2str_ext(date, s);
}


#ifdef MSF_LOG_FC  
/*
MSF_LOG_FC_DISPATCH_MAP_ENTRY_BEGIN(MMSa_messageStatus)
MMSa_messageStatus( 1, 1);
MSF_LOG_FC_DISPATCH_MAP_ENTRY_END
*/
#endif /* MSF_LOG_FC */










