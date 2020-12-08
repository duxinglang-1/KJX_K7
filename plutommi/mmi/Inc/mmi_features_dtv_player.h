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
 *	 mmi_features_dtv_player.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Mobile TV Player Applications v0.1
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files
*****************************************************************************/
#ifndef _DTV_PLAYER_FEATURES_H_
#define _DTV_PLAYER_FEATURES_H_

#include "MMI_features.h"

#ifdef __MMI_MOBILE_TV_CMMB_SUPPORT__
/*********************************************************************
 * DTVPlayer Compile Options Dependency Process
 ********************************************************************/
#ifdef __MBBMS_V30__
	#define __MBBMS_CITY_LIST__
	#define __MBBMS_UPGRADE__
	#define __MBBMS_INTER__
#endif /* __MBBMS_V30__ */

#ifdef __MBBMS_INTER__
	#define __MBBMS_V30_OPERA__
#endif /* __MBBMS_INTER__ */

#if (MMI_MAX_SIM_NUM >= 2)
	#define __MBBMS_DUAL_SIM_SUPPORT__
#endif /* __MMI_DUAL_SIM__ */

#if defined(__MMI_BT_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__) && !defined(__COSMOS_MMI_PACKAGE__)
#define __MMI_DTV_A2DP_SUPPORT__
#endif

#if(defined (CMMB_CAS_2GPP_V10))
#ifndef __MMI_CMMB_CAS_2GPP_SUPPORT__
#define __MMI_CMMB_CAS_2GPP_SUPPORT__
#endif
#endif

/* Snapshot */
#define __MMI_DTV_SNAPSHOT_SUPPORT__

/* Record */
//#define __MMI_DTV_RECORD_SUPPORT__


#define __MMI_MBBMS_MTS_SUPPORT__

#if (((LCD_WIDTH == 240) && (LCD_HEIGHT == 320)) || ((LCD_WIDTH == 240) && (LCD_HEIGHT == 400))) && defined(__MMI_VECTOR_FONT_SUPPORT__)
#define __MMI_DTV_SMALL_HINT__
#endif
#endif /* __MMI_MOBILE_TV_CMMB_SUPPORT__ */
#endif /* _DTV_PLAYER_FEATURES_H_ */
