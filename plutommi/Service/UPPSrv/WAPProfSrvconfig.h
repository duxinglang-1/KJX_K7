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
 * WAPProfconfig.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is the header file for configuration items of WAP_PROF.
 *
 * Author: Ramneek Kalra
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
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
 *==============================================================================
 *******************************************************************************/
#ifndef WAPPROFCONFIG_H
#define WAPPROFCONFIG_H

#include "MMI_features.h"

#ifdef WAP_SUPPORT


/* CBM mms fallback support. */
#ifdef __MMI_MMS_FALLBACK__
#define __MMI_WAP_PROF_CBM_MMS_FALLBACK_SUPPORT__
#ifndef __MMI_WAP_PROF_FALLBACK_ON__
#define __MMI_WAP_PROF_FALLBACK_ON__
#endif 
#endif /* __MMI_MMS_FALLBACK__ */ 

/* Q03c style fallback support macro. */
#if (! (MMI_MAX_SIM_NUM>=2))

#if 0 //Old style fallback turned off for V2 Browser
#if !defined(__MMI_WAP_PROF_CBM_WAP_FALLBACK_SUPPORT__) && !defined(OBIGO_Q05A) &&  defined(__TCPIP_OVER_CSD__)
/* under construction !*/
#ifndef __MMI_WAP_PROF_FALLBACK_ON__
/* under construction !*/
#endif 
#endif /* !defined(__MMI_WAP_PROF_CBM_WAP_FALLBACK_SUPPORT__) && !defined(OBIGO_Q05A) */ 
/* under construction !*/
#if !defined(__MMI_WAP_PROF_CBM_MMS_FALLBACK_SUPPORT__) && !defined(OBIGO_Q05A) &&  defined(__TCPIP_OVER_CSD__)
/* under construction !*/
#ifndef __MMI_WAP_PROF_FALLBACK_ON__
/* under construction !*/
#endif 
#endif /* !defined(__MMI_WAP_PROF_CBM_MMS_FALLBACK_SUPPORT__) && !defined(OBIGO_Q05A) */ 
/* under construction !*/
#endif //OLd style fallback turned off for V2 Browser
#endif /* __MMI_WAP_DUAL_SIM__ */ 

/* As MMS fallback needs to be turned off currently */
#ifdef __MMI_WAP_PROF_OLD_STYLE_MMS_FALLBACK_SUPPORT__
#undef __MMI_WAP_PROF_OLD_STYLE_MMS_FALLBACK_SUPPORT__
#endif 

#ifdef __MMI_MMS_2__
#define __MMI_WAP_PROF_UMMS_SUPPORT__
#endif 

#ifndef __MMI_WAP_PROF_PORT_PRIORITY__
#define __MMI_WAP_PROF_PORT_PRIORITY__
#endif 

#ifndef __MMI_WAP_PROF_MMS_SETTING_OTA_SUPPORT__
#define __MMI_WAP_PROF_MMS_SETTING_OTA_SUPPORT__

#ifndef __MMI_WAP_PROF_MMS_1_3_SETTING_OTA_SUPPORT__
#define __MMI_WAP_PROF_MMS_1_3_SETTING_OTA_SUPPORT__
#endif

/* Remove the following line if MMS 1.3 settings are to be supported through OTA */
#undef __MMI_WAP_PROF_MMS_1_3_SETTING_OTA_SUPPORT__

#endif /* __MMI_WAP_PROF_MMS_SETTING_OTA_SUPPORT__ */

/* MMS setting OTA are not supported for Q03c V01 currently */
#if !defined(__MMI_MMS_2__)
#undef __MMI_WAP_PROF_MMS_SETTING_OTA_SUPPORT__
#endif 

#ifndef __MMI_WAP_PROF_DYNAMIC_DTCNT_SUPPORT__
#define __MMI_WAP_PROF_DYNAMIC_DTCNT_SUPPORT__
#endif

#endif /* WAP_SUPPORT */ 
#endif /* WAPPROFCONFIG_H */ 
