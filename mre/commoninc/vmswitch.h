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
 * 
 *
 * Project:
 * --------
 * MAUI
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
 * removed!
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MRE_SWITCH_H
#define _MRE_SWITCH_H

#include "mmi_features.h"
#include "vmswitch_cfg.h"



/**************************************MRE feature define**************************************/
#if defined(CFG_MRE_CORE_BASE) && (CFG_MRE_CORE_BASE == __ON__)
	#ifndef __MRE_CORE_BASE__
	#define __MRE_CORE_BASE__
	#endif
#endif

#if defined(CFG_MRE_CORE_SANDBOX) && (CFG_MRE_CORE_SANDBOX == __ON__)
	#ifndef __MRE_CORE_SANDBOX__
	#define __MRE_CORE_SANDBOX__
	#endif
#endif

#if defined(CFG_MRE_CORE_RESOURCE_MANAGE) && (CFG_MRE_CORE_RESOURCE_MANAGE == __ON__)
	#ifndef __MRE_CORE_RESOURCE_MANAGE__
	#define __MRE_CORE_RESOURCE_MANAGE__
	#endif
#endif

#if defined(CFG_MRE_CORE_SAFETY) && (CFG_MRE_CORE_SAFETY == __ON__)
	#ifndef __MRE_CORE_SAFETY__
	#define __MRE_CORE_SAFETY__
	#endif
#endif


#if defined(CFG_MRE_CORE_APP_COMMUNICATION) && (CFG_MRE_CORE_APP_COMMUNICATION == __ON__)
	#ifndef __MRE_CORE_APP_COMMUNICATION__
	#define __MRE_CORE_APP_COMMUNICATION__
	#endif
#endif

#if defined(CFG_MRE_CORE_SM) && (CFG_MRE_CORE_SM == __ON__)
	#ifndef __MRE_CORE_SM__
	#define __MRE_CORE_SM__
	#endif
#endif

#if defined(CFG_MRE_CORE_SO) && (CFG_MRE_CORE_SO == __ON__)
	#ifndef __MRE_CORE_SO__
	#define __MRE_CORE_SO__
	#endif
#endif

#if defined(CFG_MRE_LIB_APPRES) && (CFG_MRE_LIB_APPRES == __ON__)
	#ifndef __MRE_LIB_APPRES__
	#define __MRE_LIB_APPRES__
	#endif
#endif

#if defined(CFG_MRE_LIB_C) && (CFG_MRE_LIB_C == __ON__)
	#ifndef __MRE_LIB_C__
	#define __MRE_LIB_C__
	#endif
#endif

#if defined(CFG_MRE_LIB_CHSET) && (CFG_MRE_LIB_CHSET == __ON__)
	#ifndef __MRE_LIB_CHSET__
	#define __MRE_LIB_CHSET__
	#endif
#endif

#if defined(CFG_MRE_LIB_DEF_GAME) && (CFG_MRE_LIB_DEF_GAME == __ON__)
	#ifndef __MRE_LIB_DEF_GAME__
	#define __MRE_LIB_DEF_GAME__
	#endif
#endif

#if defined(CFG_MRE_LIB_GRAPIC_DDRAW) && (CFG_MRE_LIB_GRAPIC_DDRAW == __ON__)
	#ifndef __MRE_LIB_GRAPIC_DDRAW__
	#define __MRE_LIB_GRAPIC_DDRAW__
	#endif
#endif

#if defined(CFG_MRE_LIB_GRAPIC_GFXOLD) && (CFG_MRE_LIB_GRAPIC_GFXOLD == __ON__)
	#ifndef __MRE_LIB_GRAPIC_GFXOLD__
	#define __MRE_LIB_GRAPIC_GFXOLD__
	#endif
#endif

#if defined(CFG_MRE_LIB_GRAPIC_IMAGE) && (CFG_MRE_LIB_GRAPIC_IMAGE == __ON__)
	#ifndef __MRE_LIB_GRAPIC_IMAGE__
	#define __MRE_LIB_GRAPIC_IMAGE__
	#endif
#endif

#if defined(CFG_MRE_LIB_HTTP) && (CFG_MRE_LIB_HTTP == __ON__) && \
    defined(__TCPIP__)
	#ifndef __MRE_LIB_HTTP__
	#define __MRE_LIB_HTTP__
	#endif
#endif

#if defined(CFG_MRE_LIB_IME) && (CFG_MRE_LIB_IME == __ON__)
	#ifndef __MRE_LIB_IME__
	#define __MRE_LIB_IME__
	#endif
#endif

#if defined(CFG_MRE_LIB_INI) && (CFG_MRE_LIB_INI == __ON__)
	#ifndef __MRE_LIB_INI__
	#define __MRE_LIB_INI__
	#endif
#endif

#if defined(CFG_MRE_LIB_LOG) && (CFG_MRE_LIB_LOG == __ON__)  && \
    defined(__MTK_INTERNAL__)
	#ifndef __MRE_LIB_LOG__
/* under construction !*/
	#endif
#endif

#if defined(CFG_MRE_LIB_MULTI_LANG) && (CFG_MRE_LIB_MULTI_LANG == __ON__)
	#ifndef __MRE_LIB_MULTI_LANG__
	#define __MRE_LIB_MULTI_LANG__
	#endif
#endif

#if defined(CFG_MRE_LIB_XML) && (CFG_MRE_LIB_XML == __ON__) && \
	defined(__XML_SUPPORT__)
	#ifndef __MRE_LIB_XML__
	#define __MRE_LIB_XML__
	#endif
#endif





#if defined(CFG_MRE_SAL_AUDIO) && (CFG_MRE_SAL_AUDIO == __ON__)
	#ifndef __MRE_SAL_AUDIO__
	#define __MRE_SAL_AUDIO__
	#endif
#endif

#if defined(CFG_MRE_SAL_BITSTREAM) && (CFG_MRE_SAL_BITSTREAM == __ON__) && \
	defined(__BITSTREAM_API_SUPPORT__)
	#ifndef __MRE_SAL_BITSTREAM__
	#define __MRE_SAL_BITSTREAM__
	#endif
#endif

#if defined(CFG_MRE_SAL_CAMERA) && (CFG_MRE_SAL_CAMERA == __ON__)
	#ifndef __MRE_SAL_CAMERA__
	#define __MRE_SAL_CAMERA__
	#endif
#endif

#if defined(CFG_MRE_SAL_CELL) && (CFG_MRE_SAL_CELL == __ON__)
	#ifndef __MRE_SAL_CELL__
	#define __MRE_SAL_CELL__
	#endif
#endif

#if defined(CFG_MRE_SAL_CHE_DES) && (CFG_MRE_SAL_CHE_DES == __ON__)
	#ifndef __MRE_SAL_CHE_DES__
	#define __MRE_SAL_CHE_DES__
	#endif
#endif

#if defined(CFG_MRE_SAL_CHE_MD5) && (CFG_MRE_SAL_CHE_MD5 == __ON__)
	#ifndef __MRE_SAL_CHE_MD5__
	#define __MRE_SAL_CHE_MD5__
	#endif
#endif

#if defined(CFG_MRE_SAL_CHE_SHA1) && (CFG_MRE_SAL_CHE_SHA1 == __ON__)
	#ifndef __MRE_SAL_CHE_SHA1__
	#define __MRE_SAL_CHE_SHA1__
	#endif
#endif

#if defined(CFG_MRE_SAL_CHE) && (CFG_MRE_SAL_CHE == __ON__)
	#ifndef __MRE_SAL_CHE__
	#define __MRE_SAL_CHE__
	#endif
#endif

#if defined(CFG_MRE_SAL_GPS) && (CFG_MRE_SAL_GPS == __ON__) && \
	defined(__GPS_SUPPORT__)
	#ifndef __MRE_SAL_GPS__
	#define __MRE_SAL_GPS__
	#endif
#endif

#if defined(CFG_MRE_SAL_MMS) && (CFG_MRE_SAL_MMS == __ON__)
	#ifndef __MRE_SAL_MMS__
	#define __MRE_SAL_MMS__
	#endif
#endif

#if defined(CFG_MRE_SAL_PHONEBOOK) && (CFG_MRE_SAL_PHONEBOOK == __ON__)
	#ifndef __MRE_SAL_PHONEBOOK__
	#define __MRE_SAL_PHONEBOOK__
	#endif
#endif

#if defined(CFG_MRE_SAL_SENSOR) && (CFG_MRE_SAL_SENSOR == __ON__) && \
    defined(MOTION_SENSOR_SUPPORT)
	#ifndef __MRE_SAL_SENSOR__
	#define __MRE_SAL_SENSOR__
	#endif
#endif

#if defined(CFG_MRE_SAL_SIM) && (CFG_MRE_SAL_SIM == __ON__)
	#ifndef __MRE_SAL_SIM__
	#define __MRE_SAL_SIM__
	#endif
#endif

#if defined(CFG_MRE_SAL_SMS) && (CFG_MRE_SAL_SMS == __ON__)
	#ifndef __MRE_SAL_SMS__
	#define __MRE_SAL_SMS__
	#endif
#endif

#if defined(CFG_MRE_SAL_SOCKET) && (CFG_MRE_SAL_SOCKET == __ON__) && \
    defined(__TCPIP__)
	#ifndef __MRE_SAL_SOCKET__
	#define __MRE_SAL_SOCKET__
	#endif
#endif

#if defined(CFG_MRE_SAL_STATUS) && (CFG_MRE_SAL_STATUS == __ON__)
	#ifndef __MRE_SAL_STATUS__
	#define __MRE_SAL_STATUS__
	#endif
#endif

#if defined(CFG_MRE_SAL_TELE) && (CFG_MRE_SAL_TELE == __ON__)
	#ifndef __MRE_SAL_TELE__
	#define __MRE_SAL_TELE__
	#endif
#endif

#if defined(CFG_MRE_SAL_TIMER) && (CFG_MRE_SAL_TIMER == __ON__)
	#ifndef __MRE_SAL_TIMER__
	#define __MRE_SAL_TIMER__
	#endif
#endif

#if defined(CFG_MRE_SAL_VIDEO) && (CFG_MRE_SAL_VIDEO == __ON__) && \
	defined(__MMI_VIDEO_PLAY_SUPPORT__)
	#ifndef __MRE_SAL_VIDEO__
	#define __MRE_SAL_VIDEO__
	#endif
#endif

#if defined(CFG_MRE_SAL_WALLPAPER) && (CFG_MRE_SAL_WALLPAPER == __ON__)
	#ifndef __MRE_SAL_WALLPAPER__
	#define __MRE_SAL_WALLPAPER__
	#endif
#endif

#if defined(CFG_MRE_SAL_WPS) && (CFG_MRE_SAL_WPS == __ON__) && \
    defined(__HTTP_INTERFACE__)
	#ifndef __MRE_SAL_WPS__
	#define __MRE_SAL_WPS__
	#endif
#endif


#if defined(CFG_MRE_APP_LAUNCH) && (CFG_MRE_APP_LAUNCH == __ON__)
	#ifndef __MRE_APP_LAUNCH__
	#define __MRE_APP_LAUNCH__
	#endif
#endif

#if defined(CFG_MRE_SAL_PAYMENT) && (CFG_MRE_SAL_PAYMENT == __ON__) && \
    defined(__ALIPAY_SUPPORT__)
    #ifndef __MRE_SAL_PAYMENT__
    #define __MRE_SAL_PAYMENT__
    #endif
#endif

#if defined(CFG_MRE_SAL_SETTINGS) && (CFG_MRE_SAL_SETTINGS == __ON__)
    #ifndef __MRE_SAL_SETTINGS__
    #define __MRE_SAL_SETTINGS__
    #endif
#endif

#if defined(CFG_MRE_SAL_BTCM) && (CFG_MRE_SAL_BTCM == __ON__) && \
    defined(__MMI_BT_SUPPORT__)
    #ifndef __MRE_SAL_BTCM__
    #define __MRE_SAL_BTCM__
    #endif
#endif

#if defined(CFG_MRE_SAL_BTSPP) && (CFG_MRE_SAL_BTSPP == __ON__) && \
    defined(__MRE_SAL_BTCM__) && defined(__MMI_SPP_SUPPORT__)
    #ifndef __MRE_SAL_BTSPP__
    #define __MRE_SAL_BTSPP__
    #endif
#endif

#if defined(CFG_MRE_LIB_EDITOR) && (CFG_MRE_LIB_EDITOR == __ON__)
	#ifndef __MRE_LIB_EDITOR__
	#define __MRE_LIB_EDITOR__
	#endif
#endif


#if defined(CFG_MRE_SAL_DA) && (CFG_MRE_SAL_DA == __ON__) && \
    defined(MMI_DA_HTTP_DOWNLOAD_SUPPORT)
    #ifndef __MRE_SAL_DA__
    #define __MRE_SAL_DA__
    #endif
#endif
#if defined(CFG_MRE_SAL_PN) && (CFG_MRE_SAL_PN == __ON__) && \
    defined(__MMI_PNS__)
    #ifndef __MRE_SAL_PN__
    #define __MRE_SAL_PN__
    #endif
#endif

#if defined(__MTK_INTERNAL__)
	#if defined(__MRE_DISABLE_SECURITY__) 
		#if defined(__MRE_CORE_SANDBOX__)
/* under construction !*/
		#endif
		#if defined(__MRE_CORE_SAFETY__)
/* under construction !*/
		#endif
	#endif
#endif

#if defined(__MMI_MRE_DISABLE_FMGR__)
		#if defined(__MRE_CORE_SANDBOX__)
		#undef __MRE_CORE_SANDBOX__
		#endif
		#if defined(__MRE_CORE_SAFETY__)
		#undef __MRE_CORE_SAFETY__
		#endif
#endif

#if defined(CFG_MRE_SAL_SSO) && (CFG_MRE_SAL_SSO == __ON__) && \
    defined(__MMI_SSO__)
    #ifndef __MRE_SAL_SSO__
    #define __MRE_SAL_SSO__
    #endif
#endif

#if defined(CFG_MRE_SAL_TLS) && (CFG_MRE_SAL_TLS == __ON__) && \
    defined(__SSL_SUPPORT__)
    #ifndef __MRE_SAL_TLS__
    #define __MRE_SAL_TLS__
    #endif
#endif

#endif /*_MRE_SWITCH_H*/
