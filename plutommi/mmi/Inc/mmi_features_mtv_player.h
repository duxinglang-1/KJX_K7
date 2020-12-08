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
 *	 mmi_features_mtv_player.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#ifndef _MOBILE_TV_PLAYER_FEATURES_H_
#define _MOBILE_TV_PLAYER_FEATURES_H_

#include "MMI_features.h"

#ifdef __MMI_ATV_SUPPORT__

/***************************************
* External Features
***************************************/
#if defined(__MMI_BT_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__) && !defined(__COSMOS_MMI_PACKAGE__)
#define __MMI_MTV_A2DP_SUPPORT__
#endif

/* Snapshot */
#define __MMI_MTV_SNAPSHOT_SUPPORT__

/* Record */
#if defined(__ATV_RECORD_SUPPORT__)
#define __MMI_MTV_RECORD_SUPPORT__
#endif

#if !((defined(__DIRECT_SENSOR_SUPPORT__) || defined (__DIRECT_SENSOR_V2_SUPPORT__) || defined(__ATV_SLIM_VERSION__)) && defined(__MMI_ATV_SUPPORT__))
#define __MMI_ATV_OSD_SUPPORT__
#endif

#if !(defined(__DIRECT_SENSOR_SUPPORT__) && defined(__MMI_ATV_SUPPORT__))
#define __MMI_MTV_PREVIEW_SUPPORT__
#endif

#if ((LCD_WIDTH == 320) && (LCD_HEIGHT == 240)) && defined(__MMI_ATV_SUPPORT__) 
#define __MMI_MTV_LANDSCAPE_SUPPORT__
#endif

#ifdef __MMI_MATV_SLIM__
#ifdef __ATV_SLIM_VERSION__
#define __ATV_NO_SNAPSHOT__
#endif
#define __ATV_NO_PHONE_STORAGE__
#endif

#if !defined(__ATV_SLIM_VERSION__)
	#if !defined(__ATV_RECORD_SUPPORT__)
		#define __ATV_RECORD_SUPPORT__
	#endif

	#if defined(__ATV_RECORD_SUPPORT__)
		#define __MMI_ATV_RECORD__
		
		#if defined(__MMI_ATV_RECORD__)
			#define __MMI_ATV_RECORD_SIZE_SELECT__
		#endif
	#endif
	
	#define __MMI_ATV_STORAGE_SELECT__

	#if defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__)
		#define __MMI_ATV_PLAYER_SETTING__
	#endif
	
	#define __MMI_ATV_THUMBNAIL__

#endif /* __ATV_SLIM_VERSION__ */

#endif /* __MMI_ATV_SUPPORT__ */
#endif /* _MOBILE_TV_PLAYER_FEATURES_H_ */
