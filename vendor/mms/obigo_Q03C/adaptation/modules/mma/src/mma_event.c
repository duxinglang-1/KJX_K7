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
 * mma_event.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains MMA application registration functions.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MMA_EVENT_C
#define _MMA_EVENT_C
#if defined(MMS_SUPPORT)
#include "kal_public_defs.h" 
#include "stack_ltlcom.h"
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "mmsadp.h"
#include "mma_api.h"
#include "mma_struct.h"
#include "mmc_struct.h"
#include "mms_adp_struct.h"
#include "mms_sap_struct.h"

/* FS service */
#include "fs_type.h"
#include "fs_func.h"

/* Unified Message */
#include "MMI_features.h"
#include "MMIDataType.h"
//#include "UMGProt.h"
#include "UmSrvGprot.h"
#include "MmsSrvGprot.h"
#include "msf_def.h"    /* MSF: Global definitions */

/* MMA Service */
#include "mma_event.h"

mma_notify_event_struct g_mma_app_event_table[MMA_NUM_OF_EVENT_APP_REGISTER] = 
{
#ifdef __MMI_MMS_BGSR_SUPPORT__
    {MOD_MMI, MMA_EVENT_DELETE_FOLDER, MMA_APP_ID_BGSR}
    ,
#else /* __MMI_MMS_BGSR_SUPPORT__ */ 
    {MOD_MMI, MMA_EVENT_TOTAL, 0}
    ,
#endif /* __MMI_MMS_BGSR_SUPPORT__ */ 
    {MOD_MMI, MMA_EVENT_NEW_MSG, MMA_APP_ID_MMS_APP}
    ,
    {MOD_MMI, MMA_EVENT_UM_DELETE_FOLDER_DONE, MMA_APP_ID_MMS_APP}
    ,
};

#endif /* defined(MMS_SUPPORT) */ 
#endif /* _MMA_EVENT_C */ 

