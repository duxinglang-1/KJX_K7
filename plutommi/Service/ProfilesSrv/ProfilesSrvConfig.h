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
 * ProfilesSrvConfig.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   User profiles service configuration file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef PROFILES_SRV_CONFIG_H
#define PROFILES_SRV_CONFIG_H

#include "MMI_include.h"
#include "MMIDataType.h"

#ifndef __COSMOS_MMI_PACKAGE__

/*****************************************************************************
 * Enumeration and definitions
 *****************************************************************************/

/*
  Description: 
  The number of profiles.
  If the number changed, needs to modify NVRAM default values
  This value shall be identical to NVRAM_SRV_PROF_PROFILES_TOTAL_NUM defined Common_nvram_editor_data_item.h
*/
#ifndef __MMI_PROF_ADD_DEL_PROF_SUPPORT__
#define SRV_PROF_PROFILES_TOTAL_NUM   (5)
#else
#define SRV_PROF_PROFILES_TOTAL_NUM   (14)
#endif

/*
  Description: 
  Defines if current service suports meeting mode
  Value : 1 means True | 0 means False
*/
#define SRV_PROF_SUPPORT_MEETING_MODE  (TRUE)

/*
  Description: 
  Defines the profile no. of meeting mode 
  This only works when SRV_PROF_SUPPORT_MEEINTING_MODE is defined as TRUE
  Value : 1~n, n depends on the total profile number
*/
#define SRV_PROF_MEETING_MODE_NUM  (3)

/*
  Description: 
  Defines if current service suports silent mode
  Value : 1 means True | 0 means False
*/
#define SRV_PROF_SUPPORT_SILENT_MODE  (TRUE)

/*
  Description: 
  Defines the profile no. of silent mode 
  This only works when SRV_PROF_SUPPORT_SILENT_MODE is defined as TRUE
  Value : 1~n, n depends on the total profile number
*/
#define SRV_PROF_SILENT_MODE_NUM  (2)

/*
  Description: 
  When one tone type is being requested to play while the same tone is currently playing,
  Ignore the sceond play request.
  When project is OP11 based, it will be set ot MMI_TRUE by default
  Value : 1 means True | 0 means False
*/
#define SRV_PROF_IGNORE_DUPLICATE_TONE  (FALSE)

/*
  Description: 
  Define the prefer amount of incoming voice call tone settings. Ex: Sim1/Sim2/...
  The final amount might be adjusted by mmi feature options.

  Value : 1...n
*/
#define SRV_PROF_MT_CALL_TONE_PREFER_AMOUNT  (1)

/*
  Description: 
  Define the prefer amount of incoming video call tone settings. (__MMI_VIDEO_TELEPHONY__)
  Since video call tone is not a necessary tone type, it might be merged into incoming call 
  tone setting to be a general call tone setting, the value starts from 0. Ex: Sim1/Sim2/...
  The final amount might be adjusted by mmi feature options.
  Currently only one VT call tone can be supported, so it will be adjusted to either 0 or 1

  Value : 0...n
*/
#define SRV_PROF_VT_CALL_TONE_PREFER_AMOUNT  (1)

/*
  Description: 
  Define the prefer amount of SMS tone settings. Ex: Sim1/Sim2/...
  The final amount might be adjusted by mmi feature options.

  Value : 1...n
*/
#define SRV_PROF_SMS_TONE_PREFER_AMOUNT  (1)

/*
  Description: 
  Define the prefer amount of MMS tone settings. (MMS_SUPPORT)
  Since MMS is not a necessary tone type, it might be merged into sms tone setting to be a
  general message tone setting, the value starts from 0.
  Ex: Sim1/Sim2/....
  The final amount might be adjusted by mmi feature options.  

  Value : 0...n
*/
#define SRV_PROF_MMS_TONE_PREFER_AMOUNT  (0)

/*
  Description: 
  Define the prefer amount of EMAIL tone settings. (__MMI_EMAIL__)
  Since EMAIL is not a necessary tone type, it might be merged into sms tone setting to be a
  general message tone setting, the value starts from 0.
  Ex: Sim1/Sim2/....
  The final amount might be adjusted by mmi feature options.

  Value : 0...n
*/
#define SRV_PROF_EMAIL_TONE_PREFER_AMOUNT  (0)

/*
  Description: 
  Define the amount of voice tone settings. (__MMI_OP11_MMS_SUPPORT_AUDIO_MSG__)
  Since EMAIL is not a necessary tone type, it might be merged into sms tone setting to be a
  general message tone setting, the value starts from 0.
  Ex: Sim1/Sim2/....
  The final amount might be adjusted by mmi feature options.

  Value : 0...n
*/
#define SRV_PROF_VOICE_TONE_PREFER_AMOUNT  (0)

/*
    Check Configuration
*/

#if ( SRV_PROF_SUPPORT_MEETING_MODE == TRUE) && (SRV_PROF_MEETING_MODE_NUM > SRV_PROF_PROFILES_TOTAL_NUM)
    #error "[SRV Prof]Meeting mode profile number is larger than total profiles defined"
#endif

#if ( SRV_PROF_SUPPORT_SILENT_MODE == TRUE) && (SRV_PROF_SILENT_MODE_NUM > SRV_PROF_PROFILES_TOTAL_NUM)
    #error "[SRV Prof]Silent mode profile number is larger than total profiles defined"
#endif

#if ( SRV_PROF_SUPPORT_MEETING_MODE == TRUE) && (SRV_PROF_SUPPORT_SILENT_MODE == TRUE) && (SRV_PROF_MEETING_MODE_NUM == SRV_PROF_SILENT_MODE_NUM)
    #error "[SRV Prof]Silent mode and meeting mode profile number are identical, plz set to different num"
#endif

/*
    Internal Define
*/

#if defined(__MMI_OP11_PROF_SOUND__) || (SRV_PROF_IGNORE_DUPLICATE_TONE == TRUE)
    #ifndef __SRV_PROF_IGNORE_DUPLICTE_TONE_PLAY__
    #define __SRV_PROF_IGNORE_DUPLICTE_TONE_PLAY__
    #endif
#endif

/* Reconfig tone amount by mmi features */
/*********************************************************************/
/* Dual Profile pre-defined setting */
#if !defined(__LOW_COST_SUPPORT_COMMON__) && (MMI_MAX_SIM_NUM == 2)
    #define SRV_PROF_MT_CALL_TONE_AMOUNT 2
    #define SRV_PROF_SMS_TONE_AMOUNT 2
    #define SRV_PROF_MMS_TONE_AMOUNT 0
    #define SRV_PROF_EMAIL_TONE_AMOUNT 0
    #define SRV_PROF_VOICE_TONE_AMOUNT 0
#endif

/***********************/
/* Multi Profile with sim total>2 pre-defined setting */
#if !defined(__LOW_COST_SUPPORT_COMMON__) && (MMI_MAX_SIM_NUM > 2)
  #ifdef SRV_PROF_MT_CALL_TONE_AMOUNT
    #undef SRV_PROF_MT_CALL_TONE_AMOUNT
  #endif
    #define SRV_PROF_MT_CALL_TONE_AMOUNT MMI_MAX_SIM_NUM

  #ifdef SRV_PROF_SMS_TONE_AMOUNT
    #undef SRV_PROF_SMS_TONE_AMOUNT
  #endif
    #define SRV_PROF_SMS_TONE_AMOUNT 1

  #ifdef SRV_PROF_MMS_TONE_AMOUNT
    #undef SRV_PROF_MMS_TONE_AMOUNT
  #endif
    #define SRV_PROF_MMS_TONE_AMOUNT 0

  #ifdef SRV_PROF_EMAIL_TONE_AMOUNT
    #undef SRV_PROF_EMAIL_TONE_AMOUNT
  #endif
    #define SRV_PROF_EMAIL_TONE_AMOUNT 0

  #ifdef SRV_PROF_VOICE_TONE_AMOUNT
    #undef SRV_PROF_VOICE_TONE_AMOUNT
  #endif
    #define SRV_PROF_VOICE_TONE_AMOUNT 0
#endif

/***********************/
#if defined(__MMI_PROF_SPLIT_MSG_TONES__)
  #ifdef SRV_PROF_SMS_TONE_AMOUNT
    #undef SRV_PROF_SMS_TONE_AMOUNT
  #endif
    #define SRV_PROF_SMS_TONE_AMOUNT 1

  #ifdef SRV_PROF_MMS_TONE_AMOUNT
    #undef SRV_PROF_MMS_TONE_AMOUNT
  #endif
    #define SRV_PROF_MMS_TONE_AMOUNT 1

  #ifdef SRV_PROF_EMAIL_TONE_AMOUNT
    #undef SRV_PROF_EMAIL_TONE_AMOUNT
  #endif
    #define SRV_PROF_EMAIL_TONE_AMOUNT 1

  #ifdef SRV_PROF_VOICE_TONE_AMOUNT
    #undef SRV_PROF_VOICE_TONE_AMOUNT
  #endif
    #define SRV_PROF_VOICE_TONE_AMOUNT 1
#endif

/***********************/
#ifndef SRV_PROF_MT_CALL_TONE_AMOUNT
    #define SRV_PROF_MT_CALL_TONE_AMOUNT SRV_PROF_MT_CALL_TONE_PREFER_AMOUNT
#endif

#ifndef SRV_PROF_SMS_TONE_AMOUNT
    #define SRV_PROF_SMS_TONE_AMOUNT SRV_PROF_SMS_TONE_PREFER_AMOUNT
#endif

#ifndef SRV_PROF_MMS_TONE_AMOUNT
    #define SRV_PROF_MMS_TONE_AMOUNT SRV_PROF_MMS_TONE_PREFER_AMOUNT
#endif

#ifndef SRV_PROF_EMAIL_TONE_AMOUNT
    #define SRV_PROF_EMAIL_TONE_AMOUNT SRV_PROF_EMAIL_TONE_PREFER_AMOUNT
#endif

#ifndef SRV_PROF_VOICE_TONE_AMOUNT
    #define SRV_PROF_VOICE_TONE_AMOUNT SRV_PROF_VOICE_TONE_PREFER_AMOUNT
#endif

#define SRV_PROF_VT_CALL_TONE_AMOUNT SRV_PROF_VT_CALL_TONE_PREFER_AMOUNT

/*********************************************************************/


/* Error Handling */
/* MT call amount must be larget then 0 */
#if (SRV_PROF_MT_CALL_TONE_AMOUNT <= 0 )
    #undef SRV_PROF_MT_CALL_TONE_AMOUNT
    #define SRV_PROF_MT_CALL_TONE_AMOUNT 1
#endif

/* VT call amount must be larget then 0 or 1 */
#if (SRV_PROF_VT_CALL_TONE_AMOUNT > 1 )
    #undef SRV_PROF_VT_CALL_TONE_AMOUNT
    #define SRV_PROF_VT_CALL_TONE_AMOUNT 1
#endif

/* SMS amount must be larget then 0 */
#if (SRV_PROF_SMS_TONE_AMOUNT <= 0 )
    #undef SRV_PROF_SMS_TONE_AMOUNT
    #define SRV_PROF_SMS_TONE_AMOUNT 1
#endif

#ifndef MMS_SUPPORT
  #ifdef SRV_PROF_MMS_TONE_AMOUNT
    #undef SRV_PROF_MMS_TONE_AMOUNT
  #endif
    #define SRV_PROF_MMS_TONE_AMOUNT 0
#endif

#ifndef __MMI_EMAIL__
  #ifdef SRV_PROF_EMAIL_TONE_AMOUNT
    #undef SRV_PROF_EMAIL_TONE_AMOUNT
  #endif
    #define SRV_PROF_EMAIL_TONE_AMOUNT 0
#endif

#ifndef __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__
  #ifdef SRV_PROF_VOICE_TONE_AMOUNT
    #undef SRV_PROF_VOICE_TONE_AMOUNT
  #endif
    #define SRV_PROF_VOICE_TONE_AMOUNT 0
#endif

#ifndef __MMI_VIDEO_TELEPHONY__
  #ifdef SRV_PROF_VT_CALL_TONE_AMOUNT
    #undef SRV_PROF_VT_CALL_TONE_AMOUNT
  #endif
    #define SRV_PROF_VT_CALL_TONE_AMOUNT 0
#endif

/*
  Description: 
  1. The number of external melody slots service shall provide. It shall depend on the design of user profiles application.
  2. Service will reserve the number of external melody slots in NVRAM.
  3. Currently we only defined the resource id to 20, if the number is larger than 20,
     plz enlarge the AUD_ID_PROF_EXT_BEGIN section in ProfilesSrv.res to the number you need.
  This value shall be identical to NVRAM_SRV_PROF_EXT_MELODY_NUM defined Nvram_common_defs.h
*/
/*currently the max value of SRV_PROF_EXT_MELODY_NUM is 20: (4+1)*4       */

#ifdef __MMI_PROFILES_EXT_FILE_SUPPORT__
  #if (SRV_PROF_SUPPORT_SILENT_MODE)
  #define SRV_PROF_EXT_MELODY_NUM  ((SRV_PROF_MT_CALL_TONE_AMOUNT + SRV_PROF_VT_CALL_TONE_AMOUNT) * (SRV_PROF_PROFILES_TOTAL_NUM - 1))
  #else
  #define SRV_PROF_EXT_MELODY_NUM  ((SRV_PROF_MT_CALL_TONE_AMOUNT + SRV_PROF_VT_CALL_TONE_AMOUNT) * SRV_PROF_PROFILES_TOTAL_NUM)
  #endif
#else
  #define SRV_PROF_EXT_MELODY_NUM 1
#endif

//===================================================//
#else

/*Cosmos*/
/*****************************************************************************
 * Enumeration and definitions
 *****************************************************************************/

/*
  Description: 
  The number of profiles.
  If the number changed, needs to modify NVRAM default values
  This value shall be identical to NVRAM_SRV_PROF_PROFILES_TOTAL_NUM defined Common_nvram_editor_data_item.h
*/
#define SRV_PROF_PROFILES_TOTAL_NUM   (2)

/*
  Description: 
  Defines if current service suports meeting mode
  Value : 1 means True | 0 means False
*/
#define SRV_PROF_SUPPORT_MEETING_MODE  (FALSE)

/*
  Description: 
  Defines the profile no. of meeting mode 
  This only works when SRV_PROF_SUPPORT_MEEINTING_MODE is defined as TRUE
  Value : 1~n, n depends on the total profile number
*/
#define SRV_PROF_MEETING_MODE_NUM  (3)

/*
  Description: 
  Defines if current service suports silent mode
  Value : 1 means True | 0 means False
*/
#define SRV_PROF_SUPPORT_SILENT_MODE  (TRUE)

/*
  Description: 
  Defines the profile no. of silent mode 
  This only works when SRV_PROF_SUPPORT_SILENT_MODE is defined as TRUE
  Value : 1~n, n depends on the total profile number
*/
#define SRV_PROF_SILENT_MODE_NUM  (2)

/*
  Description: 
  When one tone type is being requested to play while the same tone is currently playing,
  Ignore the sceond play request.
  When project is OP11 based, it will be set ot MMI_TRUE by default
  Value : 1 means True | 0 means False
*/
#define SRV_PROF_IGNORE_DUPLICATE_TONE  (FALSE)

/*
  Description: 
  Define the prefer amount of incoming voice call tone settings. Ex: Sim1/Sim2/...
  The final amount might be adjusted by mmi feature options.

  Value : 1...n
*/
#define SRV_PROF_MT_CALL_TONE_PREFER_AMOUNT  (1)

/*
  Description: 
  Define the prefer amount of incoming video call tone settings. (__MMI_VIDEO_TELEPHONY__)
  Since video call tone is not a necessary tone type, it might be merged into incoming call 
  tone setting to be a general call tone setting, the value starts from 0. Ex: Sim1/Sim2/...
  The final amount might be adjusted by mmi feature options.
  Currently only one VT call tone can be supported, so it will be adjusted to either 0 or 1

  Value : 0...n
*/
#define SRV_PROF_VT_CALL_TONE_PREFER_AMOUNT  (1)

/*
  Description: 
  Define the prefer amount of SMS tone settings. Ex: Sim1/Sim2/...
  The final amount might be adjusted by mmi feature options.

  Value : 1...n
*/
#define SRV_PROF_SMS_TONE_PREFER_AMOUNT  (1)

/*
  Description: 
  Define the prefer amount of MMS tone settings. (MMS_SUPPORT)
  Since MMS is not a necessary tone type, it might be merged into sms tone setting to be a
  general message tone setting, the value starts from 0.
  Ex: Sim1/Sim2/....
  The final amount might be adjusted by mmi feature options.  

  Value : 0...n
*/
#define SRV_PROF_MMS_TONE_PREFER_AMOUNT  (0)

/*
  Description: 
  Define the prefer amount of EMAIL tone settings. (__MMI_EMAIL__)
  Since EMAIL is not a necessary tone type, it might be merged into sms tone setting to be a
  general message tone setting, the value starts from 0.
  Ex: Sim1/Sim2/....
  The final amount might be adjusted by mmi feature options.

  Value : 0...n
*/
#define SRV_PROF_EMAIL_TONE_PREFER_AMOUNT  (1)

/*
  Description: 
  Define the amount of voice tone settings. (__MMI_OP11_MMS_SUPPORT_AUDIO_MSG__)
  Since EMAIL is not a necessary tone type, it might be merged into sms tone setting to be a
  general message tone setting, the value starts from 0.
  Ex: Sim1/Sim2/....
  The final amount might be adjusted by mmi feature options.

  Value : 0...n
*/
#define SRV_PROF_VOICE_TONE_PREFER_AMOUNT  (0)

/*
    Check Configuration
*/

#if ( SRV_PROF_SUPPORT_MEETING_MODE == TRUE) && (SRV_PROF_MEETING_MODE_NUM > SRV_PROF_PROFILES_TOTAL_NUM)
    #error "[SRV Prof]Meeting mode profile number is larger than total profiles defined"
#endif

#if ( SRV_PROF_SUPPORT_SILENT_MODE == TRUE) && (SRV_PROF_SILENT_MODE_NUM > SRV_PROF_PROFILES_TOTAL_NUM)
    #error "[SRV Prof]Silent mode profile number is larger than total profiles defined"
#endif

#if ( SRV_PROF_SUPPORT_MEETING_MODE == TRUE) && (SRV_PROF_SUPPORT_SILENT_MODE == TRUE) && (SRV_PROF_MEETING_MODE_NUM == SRV_PROF_SILENT_MODE_NUM)
    #error "[SRV Prof]Silent mode and meeting mode profile number are identical, plz set to different num"
#endif

/*
    Internal Define
*/

#if defined(__MMI_OP11_PROF_SOUND__) || (SRV_PROF_IGNORE_DUPLICATE_TONE == TRUE)
    #ifndef __SRV_PROF_IGNORE_DUPLICTE_TONE_PLAY__
    #define __SRV_PROF_IGNORE_DUPLICTE_TONE_PLAY__
    #endif
#endif


/*
Cosmos always define __MMI_PROFILES_EXT_FILE_SUPPORT__
*/

#ifndef __MMI_PROFILES_EXT_FILE_SUPPORT__
#define __MMI_PROFILES_EXT_FILE_SUPPORT__
#endif


/* Reconfig tone amount by mmi features */
/*********************************************************************/
/* Dual Profile pre-defined setting */
#if !defined(__LOW_COST_SUPPORT_COMMON__) && (MMI_MAX_SIM_NUM == 2)
    #define SRV_PROF_MT_CALL_TONE_AMOUNT 2
    #define SRV_PROF_SMS_TONE_AMOUNT 2
    #define SRV_PROF_MMS_TONE_AMOUNT 0
    #define SRV_PROF_EMAIL_TONE_AMOUNT 2
    #define SRV_PROF_VOICE_TONE_AMOUNT 0
#endif

/***********************/
/* Multi Profile with sim total>2 pre-defined setting */
#if !defined(__LOW_COST_SUPPORT_COMMON__) && (MMI_MAX_SIM_NUM > 2)
  #ifdef SRV_PROF_MT_CALL_TONE_AMOUNT
    #undef SRV_PROF_MT_CALL_TONE_AMOUNT
  #endif
    #define SRV_PROF_MT_CALL_TONE_AMOUNT MMI_MAX_SIM_NUM

  #ifdef SRV_PROF_SMS_TONE_AMOUNT
    #undef SRV_PROF_SMS_TONE_AMOUNT
  #endif
    #define SRV_PROF_SMS_TONE_AMOUNT 1

  #ifdef SRV_PROF_MMS_TONE_AMOUNT
    #undef SRV_PROF_MMS_TONE_AMOUNT
  #endif
    #define SRV_PROF_MMS_TONE_AMOUNT 0

  #ifdef SRV_PROF_EMAIL_TONE_AMOUNT
    #undef SRV_PROF_EMAIL_TONE_AMOUNT
  #endif
    #define SRV_PROF_EMAIL_TONE_AMOUNT 0

  #ifdef SRV_PROF_VOICE_TONE_AMOUNT
    #undef SRV_PROF_VOICE_TONE_AMOUNT
  #endif
    #define SRV_PROF_VOICE_TONE_AMOUNT 0
#endif

/***********************/
#if defined(__MMI_PROF_SPLIT_MSG_TONES__)
  #ifdef SRV_PROF_SMS_TONE_AMOUNT
    #undef SRV_PROF_SMS_TONE_AMOUNT
  #endif
    #define SRV_PROF_SMS_TONE_AMOUNT 1

  #ifdef SRV_PROF_MMS_TONE_AMOUNT
    #undef SRV_PROF_MMS_TONE_AMOUNT
  #endif
    #define SRV_PROF_MMS_TONE_AMOUNT 1

  #ifdef SRV_PROF_EMAIL_TONE_AMOUNT
    #undef SRV_PROF_EMAIL_TONE_AMOUNT
  #endif
    #define SRV_PROF_EMAIL_TONE_AMOUNT 1

  #ifdef SRV_PROF_VOICE_TONE_AMOUNT
    #undef SRV_PROF_VOICE_TONE_AMOUNT
  #endif
    #define SRV_PROF_VOICE_TONE_AMOUNT 1
#endif

/***********************/
#ifndef SRV_PROF_MT_CALL_TONE_AMOUNT
    #define SRV_PROF_MT_CALL_TONE_AMOUNT SRV_PROF_MT_CALL_TONE_PREFER_AMOUNT
#endif

#ifndef SRV_PROF_SMS_TONE_AMOUNT
    #define SRV_PROF_SMS_TONE_AMOUNT SRV_PROF_SMS_TONE_PREFER_AMOUNT
#endif

#ifndef SRV_PROF_MMS_TONE_AMOUNT
    #define SRV_PROF_MMS_TONE_AMOUNT SRV_PROF_MMS_TONE_PREFER_AMOUNT
#endif

#ifndef SRV_PROF_EMAIL_TONE_AMOUNT
    #define SRV_PROF_EMAIL_TONE_AMOUNT SRV_PROF_EMAIL_TONE_PREFER_AMOUNT
#endif

#ifndef SRV_PROF_VOICE_TONE_AMOUNT
    #define SRV_PROF_VOICE_TONE_AMOUNT SRV_PROF_VOICE_TONE_PREFER_AMOUNT
#endif

#define SRV_PROF_VT_CALL_TONE_AMOUNT SRV_PROF_VT_CALL_TONE_PREFER_AMOUNT

/*********************************************************************/


/* Error Handling */
/* MT call amount must be larget then 0 */
#if (SRV_PROF_MT_CALL_TONE_AMOUNT <= 0 )
    #undef SRV_PROF_MT_CALL_TONE_AMOUNT
    #define SRV_PROF_MT_CALL_TONE_AMOUNT 1
#endif

/* VT call amount must be larget then 0 or 1 */
#if (SRV_PROF_VT_CALL_TONE_AMOUNT > 1 )
    #undef SRV_PROF_VT_CALL_TONE_AMOUNT
    #define SRV_PROF_VT_CALL_TONE_AMOUNT 1
#endif

/* SMS amount must be larget then 0 */
#if (SRV_PROF_SMS_TONE_AMOUNT <= 0 )
    #undef SRV_PROF_SMS_TONE_AMOUNT
    #define SRV_PROF_SMS_TONE_AMOUNT 1
#endif

#ifndef MMS_SUPPORT
  #ifdef SRV_PROF_MMS_TONE_AMOUNT
    #undef SRV_PROF_MMS_TONE_AMOUNT
  #endif
    #define SRV_PROF_MMS_TONE_AMOUNT 0
#endif

#ifndef __MMI_EMAIL__
  #ifdef SRV_PROF_EMAIL_TONE_AMOUNT
    #undef SRV_PROF_EMAIL_TONE_AMOUNT
  #endif
    #define SRV_PROF_EMAIL_TONE_AMOUNT 0
#endif

#ifndef __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__
  #ifdef SRV_PROF_VOICE_TONE_AMOUNT
    #undef SRV_PROF_VOICE_TONE_AMOUNT
  #endif
    #define SRV_PROF_VOICE_TONE_AMOUNT 0
#endif

#ifndef __MMI_VIDEO_TELEPHONY__
  #ifdef SRV_PROF_VT_CALL_TONE_AMOUNT
    #undef SRV_PROF_VT_CALL_TONE_AMOUNT
  #endif
    #define SRV_PROF_VT_CALL_TONE_AMOUNT 0
#endif


/*
  Description: 
  1. The number of external melody slots service shall provide. It shall depend on the design of user profiles application.
  2. Service will reserve the number of external melody slots in NVRAM.
  3. Currently we only defined the resource id to 20, if the number is larger than 20,
     plz enlarge the AUD_ID_PROF_EXT_BEGIN section in ProfilesSrv.res to the number you need.
  This value shall be identical to NVRAM_SRV_PROF_EXT_MELODY_NUM defined Nvram_common_defs.h
*/

#define SRV_PROF_EXT_MELODY_NUM  (SRV_PROF_MT_CALL_TONE_AMOUNT + SRV_PROF_SMS_TONE_AMOUNT + SRV_PROF_EMAIL_TONE_AMOUNT)

#endif


#endif /* PROFILES_SRV_CONFIG_H */

