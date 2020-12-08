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
 * custom_provbox.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for MMI PrvBox configurable values.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _CUSTOM_PROVBOX_H
#define _CUSTOM_PROVBOX_H

#include "mmi_features.h"

#ifdef __MMI_PROV_MESSAGE_SUPPORT__

/*----------------------Max message number------------------------------------*/

/* It means the message num supported is unlimited unless no enougth resource. */
#define CUSTOM_PROVBOX_UNLIMITED_NUM               (0xFFFFFFFF)

/* Max message number in inbox, MMI_PROVBOX_UNLIMITED_NUM means unlimited */
#if defined(__LOW_COST_SUPPORT_COMMON__)
#define CUSTOM_PROVBOX_MAX_INBOX_MSG_NUM           (5)    /* Or MMI_PROVBOX_UNLIMITED_NUM */
#else
#define CUSTOM_PROVBOX_MAX_INBOX_MSG_NUM           (15)    /* Or MMI_PROVBOX_UNLIMITED_NUM */
#endif


/* Common messages such as wap & DM message saved extrally if inbox is full, design to support several ones. */
#define CUSTOM_PROVBOX_MAX_CMN_EXT_MSG_NUM         (1)

/* MMI_SPAMax SIM message read from SIM card, 1 currently, please refer to 
   SIMProvAgent(SPA) application */
#ifdef __SPA_SUPPORT__

#if (MMI_MAX_SIM_NUM == 1)
#define CUSTOM_PROVBOX_MAX_SIM_MSG_NUM             (1)     /* MMI_SPA_MAX_MSG_NUM */
#endif
#if (MMI_MAX_SIM_NUM == 2)
#define CUSTOM_PROVBOX_MAX_SIM_MSG_NUM             (2)     /* MMI_SPA_MAX_MSG_NUM */
#endif 
#if (MMI_MAX_SIM_NUM == 3)
#define CUSTOM_PROVBOX_MAX_SIM_MSG_NUM             (3)     /* MMI_SPA_MAX_MSG_NUM */
#endif
#if (MMI_MAX_SIM_NUM == 4)
#define CUSTOM_PROVBOX_MAX_SIM_MSG_NUM             (4)     /* MMI_SPA_MAX_MSG_NUM */
#endif

#else /* __SPA_SUPPORT__ */ 

#define CUSTOM_PROVBOX_MAX_SIM_MSG_NUM             (0)

#endif /* __SPA_SUPPORT__ */ 

/* Dependency : No change */
#define CUSTOM_PROVBOX_MAX_EXT_MSG_NUM             (CUSTOM_PROVBOX_MAX_CMN_EXT_MSG_NUM + CUSTOM_PROVBOX_MAX_SIM_MSG_NUM)

/* MMI_PROVBOX_UNLIMITED_NUM means unlimited */
#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__

#if defined(__LOW_COST_SUPPORT_COMMON__)
#define CUSTOM_PROVBOX_MAX_ARCHIVE_MSG_NUM         (5)    /* Or MMI_PROVBOX_UNLIMITED_NUM */
#else
#define CUSTOM_PROVBOX_MAX_ARCHIVE_MSG_NUM         (15)    /* Or MMI_PROVBOX_UNLIMITED_NUM */
#endif

#else /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */

#define CUSTOM_PROVBOX_MAX_ARCHIVE_MSG_NUM         (0)

#endif  /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */

/* Dependency : No change, if the MMI_PROVBOX_TOTAL_MSG_NUM is changed,please remember to change the quota value in fs_quota.c */
#if (CUSTOM_PROVBOX_MAX_INBOX_MSG_NUM == CUSTOM_PROVBOX_UNLIMITED_NUM || CUSTOM_PROVBOX_MAX_ARCHIVE_MSG_NUM == CUSTOM_PROVBOX_UNLIMITED_NUM)

#ifdef __MMI_PROV_IN_UM__
#error "The value of MMI_PROVBOX_MAX_INBOX_MSG_NUM or MMI_PROVBOX_MAX_ARCHIVE_MSG_NUM should not be unlimited when save in UMBox" 
#endif

#define CUSTOM_PROVBOX_BOX_MAX_MSG_NUM             CUSTOM_PROVBOX_UNLIMITED_NUM 
#define CUSTOM_PROVBOX_MAX_MSG_NUM                 CUSTOM_PROVBOX_UNLIMITED_NUM
#define CUSTOM_PROVBOX_TOTAL_MSG_NUM               CUSTOM_PROVBOX_UNLIMITED_NUM

#else /* (MMI_PROVBOX_MAX_INBOX_MSG_NUM == MMI_PROVBOX_UNLIMITED_NUM || MMI_PROVBOX_MAX_ARCHIVE_MSG_NUM == MMI_PROVBOX_UNLIMITED_NUM) */ 

/* The max message number of one box */
#define CUSTOM_PROVBOX_MAX_MSG_NUM_PER_BOX         (CUSTOM_PROVBOX_MAX_INBOX_MSG_NUM > CUSTOM_PROVBOX_MAX_ARCHIVE_MSG_NUM ? CUSTOM_PROVBOX_MAX_INBOX_MSG_NUM : CUSTOM_PROVBOX_MAX_ARCHIVE_MSG_NUM) 
/* The max message number of all boxes which user can see. */
#define CUSTOM_PROVBOX_MAX_MSG_NUM                 (CUSTOM_PROVBOX_MAX_INBOX_MSG_NUM + CUSTOM_PROVBOX_MAX_ARCHIVE_MSG_NUM)
/* The total message number of all boxes including extra box. */
#define CUSTOM_PROVBOX_TOTAL_MSG_NUM               (CUSTOM_PROVBOX_MAX_MSG_NUM + CUSTOM_PROVBOX_MAX_EXT_MSG_NUM)

#endif /* (MMI_PROVBOX_MAX_INBOX_MSG_NUM == MMI_PROVBOX_UNLIMITED_NUM || MMI_PROVBOX_MAX_ARCHIVE_MSG_NUM == MMI_PROVBOX_UNLIMITED_NUM) */ 


#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */


#endif /* _CUSTOM_PROVBOX_H */ 

