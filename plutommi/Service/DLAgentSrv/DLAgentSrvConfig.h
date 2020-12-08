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
 * DLAgentSrvConfig.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
  ****************************************************************************/

/****************************************************************************
 * Include Files                                                                
 ****************************************************************************/
#include "MMI_features.h"
#include "MMI_include.h"

/****************************************************************************
 * Include Files                                                                
 ****************************************************************************/

#ifdef __MRE_LIB_NETWORK__
#define MMI_DLA_MRE_SUPPORT
#endif /* __MRE_LIB_NETWORK__ */

/****************************************************************************
 * Configurations
 ****************************************************************************/

/*
 * If MMI_DA_CFG_SELECT_STORAGE_BEFORE_DOWNLOAD is defined, it will let
 * user to select storage before download a file. Otherwise, the storage
 * will be decided automatically.
 */
#define MMI_DA_CFG_SELECT_STORAGE_BEFORE_DOWNLOAD

/*
 * If MMI_DA_CFG_INPUT_FILENAME_BEFORE_DOWNLOAD is defined, it will let
 * user to decide the filename to save before download a file. Otherwise, the filename
 * will be decided automatically.
 */
#define MMI_DA_CFG_INPUT_FILENAME_BEFORE_DOWNLOAD

/*
 * If MMI_DA_CFG_OMA_EXPOSE_DD_TO_USER is defined, after user confirmed an OMA download
 * and before the download is really started, an option to view DD will be provided to user.
 */
#define MMI_DA_CFG_OMA_EXPOSE_DD_TO_USER


#ifdef __MMI_DA_DOWNLOAD_FLOW__

#if __MMI_DA_DOWNLOAD_FLOW__ == __DA_FLOW_1__

/* Turn on all, do nothing here. */

#elif __MMI_DA_DOWNLOAD_FLOW__ == __DA_FLOW_2__

#undef MMI_DA_CFG_INPUT_FILENAME_BEFORE_DOWNLOAD
#undef MMI_DA_CFG_OMA_EXPOSE_DD_TO_USER

#elif __MMI_DA_DOWNLOAD_FLOW__ == __DA_FLOW_3__

#undef MMI_DA_CFG_INPUT_FILENAME_BEFORE_DOWNLOAD

#endif

#endif /* defined(__MMI_DA_DOWNLOAD_FLOW__) */
//#ifdef __PLUTO_MMI_PACKAGE__
#ifdef __MMI_DA_CONF_PAGE_SLIM__
#ifndef __MMI_DOWNLOAD_AGENT_MULTI_DL__
#define MMI_DA_PLUTO_SLIM
#endif
#endif

#if defined(__MMI_DOWNLOAD_AGENT_MULTI_DL__) && defined(__MMI_DA_RESUME__) && defined(BROWSER_SUPPORT)
#define __MMI_DA_DOWNLOAD_AUTO_RESUME_WHEN_BROWSER_EXIT__
#endif /* __MMI_DA_RESUME__ */

#ifdef __CBM_BEARER_SWITCH__
#define MMI_DA_WLAN_PREFER_SUPPORT
#endif

#ifdef __OP01__
#ifndef __MMI_DA_USER_SELECT_DOWNLOAD_LOCATION__
#define __MMI_DA_USER_SELECT_DOWNLOAD_LOCATION__
#endif
#endif



