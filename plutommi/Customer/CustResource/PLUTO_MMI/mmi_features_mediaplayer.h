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
 *   MMI_features_mediaplayer.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *   Feature Customization
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MEDPLY_FEATURES_H
#define MEDPLY_FEATURES_H

#include "MMI_features.h"
#include "custom_EMI_release.h"
#if defined(__MMI_MEDIA_PLAYER__) 

#ifdef __OP01__
    #define MMI_MEDPLY_FTE_STOP_SUPPORT_ICON
    
    #ifdef __MMI_MEDIA_PLAYER_STREAM__
        #define MMI_MEDPLY_FTE_SUPPORT_INPUT_URL
    #endif
#endif

#if (!defined(__MMI_MAINLCD_176X220__) && !defined(__MMI_MAINLCD_320X240__)&& !defined(__MMI_MAINLCD_128X160__) && !defined(__MMI_FTE_SUPPORT__)) 
	#ifndef __MMI_MEDPLY_VIDEO_SHADOW_SUPPORT__
	#define __MMI_MEDPLY_VIDEO_SHADOW_SUPPORT__
	#endif
#endif

#if defined(__MMI_KURO_SUPPORT__)
 #ifndef __MMI_KURO_DOWNLOAD_SUPPORT__
 #define __MMI_KURO_DOWNLOAD_SUPPORT__
 #endif
#endif

#if	(defined(__MMI_MEDIA_PLAYER_AUDIO__) && (defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__)))
	#ifndef __MMI_MEDPLY_AUDIO_SPECTRUM_DISPLAY__
	#define __MMI_MEDPLY_AUDIO_SPECTRUM_DISPLAY__
	#endif
#endif

#if (defined(__MMI_MEDIA_PLAYER_AUDIO__) && (defined(__BTMTK__) && defined(__MMI_MEDPLY_AUDIO_SPECTRUM_DISPLAY__) && (defined(__A2DP_BLOCK_SPECTRUM__) )))
	#ifndef __MMI_MEDIA_PLAYER_A2DP_BLOCK_SPECTRUM__
	#define __MMI_MEDIA_PLAYER_A2DP_BLOCK_SPECTRUM__
	#endif
#endif

#ifdef __MMI_CAMCORDER__
    #ifndef __MMI_MEDIA_PLAYER_VDOREC__
    #define __MMI_MEDIA_PLAYER_VDOREC__
    #endif
#endif

#if defined(__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__)
    #ifndef __MMI_MEDIA_PLAYER_VDOREC__
    #define __MMI_MEDIA_PLAYER_VDOREC__
    #endif
#endif

#if (defined(__MMI_VIDEO_PLY_SNAPSHOT_SUPPORT__) && (defined(__MMI_MEDIA_PLAYER_VIDEO__) || defined(__MMI_MEDIA_PLAYER_STREAM__)) && defined(__MMI_IMAGE_VIEWER__))
    #define __MMI_MEDIA_PLAYER_SNAPSHOT__
#endif

#if defined(__MMI_MEDIA_PLAYER_STREAM__)
    #define __MMI_MEIDA_PLAYER_EXTENDED_URL__
#endif

/*
** landscapte + gdi_blt_without_
*/
#if defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__) && (defined(__LANDSCAPE_UI_ON_PORTRAIT_LCM__) || defined(__LANDSCAPE_UI_ON_PORTRAIT_LCM_SLIM_VERSION__))
#define MMI_MEDPLY_LANDSCAPE_WITH_GDI_DBBUF_SUPPORT
#endif

#if defined(__MDI_VIDEO_PROCESSING_SUPPORT__) 
    #define __MMI_MEDIA_PLAYER_VIDEO_PROCESSING_SUPPORT__
#endif



#if defined(MP4_DECODE) 

#if (!defined (__MP4_DEC_SW_SUPPORT__) && !defined (__H264_DEC_SW_SUPPORT__) && !defined (__RV_DEC_SW_SUPPORT__))
/* do not support video speed play by the request of video driver team */
//    #define __MMI_MEDIA_PLAYER_VIDEO_SPEED__ 
#endif     

#if 0 //defined(MT6228) || defined(MT6229) || defined(MT6230) 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* defined(MT6228) || defined(MT6229) || defined(MT6230) */
    #define MEDPLY_FEATURE_VIDEO_SPEED_COUNT  (5)     
    #define MEDPLY_DEFAULT_VIDEO_SPEED        (1)  /* index - start from 0 */

    #define MEDPLY_FEATURE_VIDEO_SPEED_0      (50)
    #define MEDPLY_FEATURE_VIDEO_SPEED_1      (100)
    #define MEDPLY_FEATURE_VIDEO_SPEED_2      (200)
    #define MEDPLY_FEATURE_VIDEO_SPEED_3      (400)
    #define MEDPLY_FEATURE_VIDEO_SPEED_4      (800)
    #define MEDPLY_FEATURE_VIDEO_SPEED_5      (0)
    #define MEDPLY_FEATURE_VIDEO_SPEED_6      (0)
    #define MEDPLY_FEATURE_VIDEO_SPEED_7      (0)
    #define MEDPLY_FEATURE_VIDEO_SPEED_8      (0)
#endif /* defined(MT6228) || defined(MT6229) || defined(MT6230) */



#else /* other cases, shall not happen but use default */

#if (!defined (__MP4_DEC_SW_SUPPORT__) && !defined (__H264_DEC_SW_SUPPORT__) && !defined (__RV_DEC_SW_SUPPORT__))
   #define __MMI_MEDIA_PLAYER_VIDEO_SPEED__ 
#endif     
    
   #define MEDPLY_FEATURE_VIDEO_SPEED_COUNT  (5)     
   #define MEDPLY_DEFAULT_VIDEO_SPEED        (1)  /* index - start from 0 */

   #define MEDPLY_FEATURE_VIDEO_SPEED_0      (50)
   #define MEDPLY_FEATURE_VIDEO_SPEED_1      (100)
   #define MEDPLY_FEATURE_VIDEO_SPEED_2      (200)
   #define MEDPLY_FEATURE_VIDEO_SPEED_3      (400)
   #define MEDPLY_FEATURE_VIDEO_SPEED_4      (800)
   #define MEDPLY_FEATURE_VIDEO_SPEED_5      (0)
   #define MEDPLY_FEATURE_VIDEO_SPEED_6      (0)
   #define MEDPLY_FEATURE_VIDEO_SPEED_7      (0)
   #define MEDPLY_FEATURE_VIDEO_SPEED_8      (0)

#endif /* defined(MP4_CODEC) */

#endif /* __MMI_MEDIA_PLAYER__ */
#endif /* _MEDPLY_FEATURES_H_ */


