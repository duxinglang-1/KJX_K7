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
#ifndef _MRE_SWITCH_CFG_H
#define _MRE_SWITCH_CFG_H


#define __ON__          (-1)
#define __OFF__         (-2)

#if defined(__MRE_PACKAGE_FULL__)

/********************Full Package Config*********************/

#define CFG_MRE_CORE_BASE                   (__ON__)
#define CFG_MRE_CORE_SANDBOX                (__ON__)
#define CFG_MRE_CORE_RESOURCE_MANAGE        (__ON__)
#define CFG_MRE_CORE_SAFETY                 (__ON__)
#define CFG_MRE_CORE_APP_COMMUNICATION      (__ON__)
#define CFG_MRE_CORE_SM                     (__ON__)
#define CFG_MRE_CORE_SO                     (__ON__)

#define CFG_MRE_LIB_APPRES                  (__ON__)
#define CFG_MRE_LIB_C                       (__ON__)
#define CFG_MRE_LIB_CHSET                   (__ON__)
#define CFG_MRE_LIB_DEF_GAME                (__ON__)
#define CFG_MRE_LIB_GRAPIC_DDRAW            (__ON__)
#define CFG_MRE_LIB_GRAPIC_GFXOLD           (__ON__)
#define CFG_MRE_LIB_GRAPIC_IMAGE            (__ON__)
#define CFG_MRE_LIB_HTTP                    (__ON__)
#define CFG_MRE_LIB_IME                     (__ON__)
#define CFG_MRE_LIB_INI                     (__ON__)
#define CFG_MRE_LIB_LOG                     (__ON__)
#define CFG_MRE_LIB_MULTI_LANG              (__ON__)
#define CFG_MRE_LIB_XML                     (__ON__)

#define CFG_MRE_SAL_AUDIO                   (__ON__)
#define CFG_MRE_SAL_BITSTREAM               (__ON__)
#define CFG_MRE_SAL_CAMERA                  (__ON__)
#define CFG_MRE_SAL_CELL                    (__ON__)
#define CFG_MRE_SAL_CHE_DES                 (__ON__)
#define CFG_MRE_SAL_CHE_MD5                 (__ON__)
#define CFG_MRE_SAL_CHE_SHA1                (__OFF__)
#define CFG_MRE_SAL_GPS                     (__ON__)
#define CFG_MRE_SAL_MMS                     (__ON__)
#define CFG_MRE_SAL_PHONEBOOK               (__ON__)
#define CFG_MRE_SAL_SENSOR                  (__ON__)
#define CFG_MRE_SAL_SIM                     (__ON__)
#define CFG_MRE_SAL_SMS                     (__ON__)
#define CFG_MRE_SAL_SOCKET                  (__ON__)
#define CFG_MRE_SAL_STATUS                  (__ON__)
#define CFG_MRE_SAL_TELE                    (__ON__)
#define CFG_MRE_SAL_TIMER                   (__ON__)
#define CFG_MRE_SAL_VIDEO                   (__ON__)
#define CFG_MRE_SAL_WALLPAPER               (__ON__)
#define CFG_MRE_SAL_WPS                     (__ON__)
#define CFG_MRE_APP_LAUNCH                  (__ON__)
#define CFG_MRE_SAL_PAYMENT 				(__ON__)
#define CFG_MRE_SAL_CHE                     (__ON__)
#define CFG_MRE_SAL_SETTINGS                (__ON__)
#define CFG_MRE_SAL_BTCM                    (__ON__)
#define CFG_MRE_SAL_BTSPP                   (__ON__) // depend on CFG_MRE_SAL_BTCM
#define CFG_MRE_LIB_EDITOR                  (__ON__)
#define CFG_MRE_SAL_DA                    (__ON__)
#define CFG_MRE_SAL_PN                     (__ON__)
#define CFG_MRE_SAL_SSO                     (__ON__)
#define CFG_MRE_SAL_TLS                     (__ON__)

#elif defined(__MRE_PACKAGE_NORMAL__)
/**********************NORMAL Package Config***********************/
#define CFG_MRE_CORE_BASE                   (__ON__)
#define CFG_MRE_CORE_SANDBOX                (__ON__)
#define CFG_MRE_CORE_RESOURCE_MANAGE        (__ON__)
#define CFG_MRE_CORE_SAFETY                 (__ON__)
#define CFG_MRE_CORE_APP_COMMUNICATION      (__ON__)
#define CFG_MRE_CORE_SM                     (__ON__)
#define CFG_MRE_CORE_SO                     (__OFF__)

#define CFG_MRE_LIB_APPRES                  (__ON__)
#define CFG_MRE_LIB_C                       (__ON__)
#define CFG_MRE_LIB_CHSET                   (__ON__)
#define CFG_MRE_LIB_DEF_GAME                (__OFF__)
#define CFG_MRE_LIB_GRAPIC_DDRAW            (__ON__)
#define CFG_MRE_LIB_GRAPIC_GFXOLD           (__ON__)
#define CFG_MRE_LIB_GRAPIC_IMAGE            (__ON__)
#define CFG_MRE_LIB_HTTP                    (__ON__)
#define CFG_MRE_LIB_IME                     (__ON__)
#define CFG_MRE_LIB_INI                     (__ON__)
#define CFG_MRE_LIB_LOG                     (__ON__)
#define CFG_MRE_LIB_MULTI_LANG              (__ON__)
#define CFG_MRE_LIB_XML                     (__ON__)

#define CFG_MRE_SAL_AUDIO                   (__ON__)
#define CFG_MRE_SAL_BITSTREAM               (__ON__)
#define CFG_MRE_SAL_CAMERA                  (__OFF__)
#define CFG_MRE_SAL_CELL                    (__ON__)
#define CFG_MRE_SAL_CHE_DES                 (__ON__)
#define CFG_MRE_SAL_CHE_MD5                 (__ON__)
#define CFG_MRE_SAL_CHE_SHA1                (__OFF__)
#define CFG_MRE_SAL_GPS                     (__OFF__)
#define CFG_MRE_SAL_MMS                     (__ON__)
#define CFG_MRE_SAL_PHONEBOOK               (__ON__)
#define CFG_MRE_SAL_SENSOR                  (__OFF__)
#define CFG_MRE_SAL_SIM                     (__ON__)
#define CFG_MRE_SAL_SMS                     (__ON__)
#define CFG_MRE_SAL_SOCKET                  (__ON__)
#define CFG_MRE_SAL_STATUS                  (__ON__)
#define CFG_MRE_SAL_TELE                    (__ON__)
#define CFG_MRE_SAL_TIMER                   (__ON__)
#define CFG_MRE_SAL_VIDEO                   (__OFF__)
#define CFG_MRE_SAL_WALLPAPER               (__ON__)
#define CFG_MRE_SAL_WPS                     (__ON__)
#define CFG_MRE_APP_LAUNCH                  (__ON__)
#define CFG_MRE_SAL_PAYMENT 				(__ON__)
#define CFG_MRE_SAL_CHE                     (__OFF__)
#define CFG_MRE_SAL_SETTINGS                (__ON__)
#define CFG_MRE_SAL_BTCM                    (__ON__)
#define CFG_MRE_SAL_BTSPP                   (__ON__)// depend on CFG_MRE_SAL_BTCM
#define CFG_MRE_LIB_EDITOR                  (__ON__)
#define CFG_MRE_SAL_DA                    (__ON__)
#define CFG_MRE_SAL_PN                     (__ON__)
#define CFG_MRE_SAL_SSO                     (__ON__)
#define CFG_MRE_SAL_TLS                     (__ON__)

#elif defined(__MRE_PACKAGE_SLIM__)
/**********************SLIM Package Config***********************/
#define CFG_MRE_CORE_BASE                   (__ON__)
#define CFG_MRE_CORE_SANDBOX                (__OFF__)
#define CFG_MRE_CORE_RESOURCE_MANAGE        (__ON__)
#define CFG_MRE_CORE_SAFETY                 (__OFF__)
#define CFG_MRE_CORE_APP_COMMUNICATION      (__ON__)
#define CFG_MRE_CORE_SM                     (__ON__)
#define CFG_MRE_CORE_SO                     (__OFF__)

#define CFG_MRE_LIB_APPRES                  (__ON__)
#define CFG_MRE_LIB_C                       (__ON__)
#define CFG_MRE_LIB_CHSET                   (__ON__)
#define CFG_MRE_LIB_DEF_GAME                (__OFF__)
#define CFG_MRE_LIB_GRAPIC_DDRAW            (__ON__)
#define CFG_MRE_LIB_GRAPIC_GFXOLD           (__ON__)
#define CFG_MRE_LIB_GRAPIC_IMAGE            (__ON__)
#define CFG_MRE_LIB_HTTP                    (__ON__)
#define CFG_MRE_LIB_IME                     (__ON__)
#define CFG_MRE_LIB_INI                     (__ON__)
#define CFG_MRE_LIB_LOG                     (__ON__)
#define CFG_MRE_LIB_MULTI_LANG              (__ON__)
#define CFG_MRE_LIB_XML                     (__ON__)

#define CFG_MRE_SAL_AUDIO                   (__ON__)
#define CFG_MRE_SAL_BITSTREAM               (__OFF__)
#define CFG_MRE_SAL_CAMERA                  (__ON__)
#define CFG_MRE_SAL_CELL                    (__ON__)
#define CFG_MRE_SAL_CHE_DES                 (__OFF__)
#define CFG_MRE_SAL_CHE_MD5                 (__OFF__)
#define CFG_MRE_SAL_CHE_SHA1                (__OFF__)
#define CFG_MRE_SAL_GPS                     (__OFF__)
#define CFG_MRE_SAL_MMS                     (__OFF__)
#define CFG_MRE_SAL_PHONEBOOK               (__ON__)
#define CFG_MRE_SAL_SENSOR                  (__OFF__)
#define CFG_MRE_SAL_SIM                     (__ON__)
#define CFG_MRE_SAL_SMS                     (__ON__)
#define CFG_MRE_SAL_SOCKET                  (__ON__)
#define CFG_MRE_SAL_STATUS                  (__ON__)
#define CFG_MRE_SAL_TELE                    (__ON__)
#define CFG_MRE_SAL_TIMER                   (__ON__)
#define CFG_MRE_SAL_VIDEO                   (__OFF__)
#define CFG_MRE_SAL_WALLPAPER               (__ON__)
#define CFG_MRE_SAL_WPS                     (__ON__)
#define CFG_MRE_APP_LAUNCH                  (__ON__)
#define CFG_MRE_SAL_PAYMENT 				        (__ON__)
#define CFG_MRE_SAL_CHE                     (__OFF__)
#define CFG_MRE_SAL_SETTINGS                (__ON__)
#define CFG_MRE_SAL_BTCM                    (__ON__)
#define CFG_MRE_SAL_BTSPP                   (__ON__)// depend on CFG_MRE_SAL_BTCM
#define CFG_MRE_LIB_EDITOR                  (__OFF__)
#define CFG_MRE_SAL_DA                      (__ON__)
#define CFG_MRE_SAL_PN                      (__OFF__)
#define CFG_MRE_SAL_SSO                     (__OFF__)
#define CFG_MRE_SAL_TLS                     (__OFF__)

#endif  /* MRE_PACKAGE */

#endif /*_MRE_SWITCH_CFG_H*/
