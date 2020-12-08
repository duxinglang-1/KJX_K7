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
 *  vapp_clog_config.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_CALL_LOG_CONFIG_H
#define VAPP_CALL_LOG_CONFIG_H

/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "MMI_features.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "mmi_include.h" //temp
#include "mmi_common_app_trc.h"

#include "CallLogSrvGprot.h" // temp
#include "CallLogSrvIprot.h"
#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* Trace                                                                      */
/*----------------------------------------------------------------------------*/
/* Trace group, easy to change it */
#define VAPP_CLOG_TRC_INFO                               MMI_COMMON_TRC_G4_CLOG
#define VAPP_CLOG_TRC_WARNING                            MMI_COMMON_TRC_G4_CLOG
#define VAPP_CLOG_TRC_ERROR                              MMI_COMMON_TRC_G4_CLOG

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Constants                                                                  */
/*----------------------------------------------------------------------------*/

/*
 * For customer: 
 * Only the following style combinations have passed the SQC and reach MP quality,
 * it's strongly recommended not to modify it, or we'll not ensure the quality 
 * as we not SQC it due to so many small combinations and some style such as SRV_CLOG_STYLE_MERGE_THREAD
 * may be supported in the future.
 * If really need, please let us know and schedule SQC for it or make sure to apply
 * enough test to qulity it.
 * thanks
 */

/* The limitation style of log number */
#define VAPP_CLOG_STYLE_NUM                                                                       \
                                                (SRV_CLOG_STYLE_NUM_TOTAL_LIMITED |              \
                                                 SRV_CLOG_STYLE_NUM_TYPE_LIMITED)
/* The Merge style of log data */
#if defined(__OP02__)
// don't merger any calllog
#define VAPP_CLOG_STYLE_MERGE                   (0)
#else
#define VAPP_CLOG_STYLE_MERGE                                                                     \
                                                (SRV_CLOG_STYLE_MERGE_IN_SIM_ID |                \
                                                 SRV_CLOG_STYLE_MERGE_IN_LOG_TYPE |              \
                                                 SRV_CLOG_STYLE_MERGE_IN_SUB_TYPE |              \
                                                 SRV_CLOG_STYLE_MERGE_BY_PHB_ID)
#endif

/* The PHB sync style of PHB sync feature */
#define VAPP_CLOG_STYLE_PHB_SYNC                                                                  \
                                                (SRV_CLOG_STYLE_PHB_SYNC_ADD |                   \
                                                 SRV_CLOG_STYLE_PHB_SYNC_DELETE |                \
                                                 SRV_CLOG_STYLE_PHB_SYNC_UPDATE)

#ifdef __MMI_CLOG_SIM_SYNC_SUPPORT__
/* The SIM sync style of SIM sync feature */
#define VAPP_CLOG_STYLE_SIM_SYNC                                                                  \
                                                (SRV_CLOG_STYLE_SIM_SYNC_READ |                  \
                                                 SRV_CLOG_STYLE_SIM_SYNC_WRITE |                 \
                                                 SRV_CLOG_STYLE_SIM_SYNC_SAT_REFRESH |           \
                                                 SRV_CLOG_STYLE_SIM_SYNC_CLEAR_OLD)

#else /* __MMI_CLOG_SIM_SYNC_SUPPORT__ */ 

/* The SIM sync style of SIM sync feature */
#define VAPP_CLOG_STYLE_SIM_SYNC                      (0)

#endif /* __MMI_CLOG_SIM_SYNC_SUPPORT__ */ 



/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* typedef in structure                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Extern Function                                                            */
/*----------------------------------------------------------------------------*/

#endif /* VAPP_CALL_LOG_CONFIG_H */ 


