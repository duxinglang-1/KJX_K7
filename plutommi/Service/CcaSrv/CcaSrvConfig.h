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
 *  CcaSrvConfig.h
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
 * -------
 *                      
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
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


#ifndef SRV_CCA_CONFIG_H
#define SRV_CCA_CONFIG_H

/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "MMI_features.h"
#include "MMI_inet_app_trc.h"
#include "DebugInitDef_Int.h"



#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 


/*----------------------------------------------------------------------------*/
/* Internal Compile Option                                                    */
/*----------------------------------------------------------------------------*/
#ifdef SYNCML_DM_SUPPORT
#define __SRV_CCA_PROF_OPER__  /* Profile Get/Update Operation */
#endif


#ifdef __SRV_CCA_PROF_OPER__
//#define __SRV_CCA_DM_SESSION__   /* Unused feature */
#endif

#ifdef __SPA_SUPPORT__
#define __SRV_CCA_SPA__
#endif

/* Can only dump on Modis now */
#ifndef __MTK_TARGET__
#define __SRV_CCA_DUMP__
#endif


#ifndef __SRV_CCA_DEBUG__
//#define __SRV_CCA_DEBUG__
#endif


#ifdef __SRV_CCA_DEBUG__
#define __SRV_CCA_PRINT_MEM_INFO__
#endif


#if defined(__LOW_COST_SUPPORT_COMMON__)
#ifndef __SRV_CCA_SLIM__
#define __SRV_CCA_SLIM__
#endif
#endif

//CCA SUPPORT AUTH
#define __SRV_CCA_SUPPORT_AUTH__

/*----------------------------------------------------------------------------*/
/* TRACE                                                                      */
/*----------------------------------------------------------------------------*/
/* Please note:
 * keep MMI_TRACE_G7_MISC on 07A, and chage it to MMI_CONN_TRC_G9_CCA from 07B
 */

#define SRV_CCA_TRC_INFO                        MMI_INET_TRC_G9_CCA
#define SRV_CCA_TRC_WARNING                     MMI_INET_TRC_G9_CCA
#define SRV_CCA_TRC_ERROR                       MMI_INET_TRC_G9_CCA

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/
#define SRV_CCA_ASSERT                          MMI_ASSERT


/*----------------------------------------------------------------------------*/
/* Constants                                                                  */
/*----------------------------------------------------------------------------*/

#if defined(__LOW_COST_SUPPORT_COMMON__)

#define SRV_CCA_MAX_MEM_SIZE                    (1024 * 6) /* not support Push yet. */

#elif defined(__MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__)

#define SRV_CCA_MAX_MEM_SIZE                    (1024 * 20)

#else 

#define SRV_CCA_MAX_MEM_SIZE                    (1024 * 10)

#endif /* __LOW_COST_SUPPORT_COMMON__ */


/* Max instance, only support 1 now */
#define SRV_CCA_INST_MAX_NUM                    (1)

/* The max element of each element in CCA doc such as node, data, nodelist.. */
#define SRV_CCA_ELM_MAX_NUM                     (255)

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* typedef in structure                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Extern Function                                                            */
/*----------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif 



#endif /* SRV_CCA_CONFIG_H */



