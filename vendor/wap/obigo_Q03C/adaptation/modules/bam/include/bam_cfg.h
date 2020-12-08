/*****************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2006
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
 *   bam_cfg.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Configuration file of BAM
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _bam_cfg_h

#define _bam_cfg_h

#include "msf_cfg.h"
#include "brs_cfg.h"
#ifdef SLIM_WAP_MMS
#define BAM_CFG_BRW_DISPLAY_INLINE_DO
#endif

extern const char* bam_sif_get_https_pgdl_support();
extern const char* sif_get_hw_release_version();
extern const char* bam_sif_get_release_version();
extern const char* bam_sif_get_build_date_and_time();
extern const char* bam_sif_get_j2me_midp_version();
extern const char* bam_sif_get_j2me_cldc_version();
extern const char* bam_sbam_sif_get_language();

#define OBIGO_DEFAULT_PART_CONFIG_UA_STRING
#define BAM_CFG_DEFAULT_HW_RELEASE_VER
#define BAM_CFG_DEFAULT_RELEASE_VERSION
#define BAM_CFG_DEFAULT_BUILD_DATE_TIME
#define BAM_CFG_DEFAULT_J2ME_MIDP_VERSION
#define BAM_CFG_DEFAULT_J2ME_CLDC_VERSION
#define BAM_CFG_DEFAULT_LANGUAGE_CODE
#define BAM_CFG_DEFAULT_HTTPS_PGDL_SUPPORT

#define OBIGO_DEFAULT_PART_CONFIG_UA_STRING
#define BAM_CFG_HW_RELEASE_VER (const char*)bam_sif_get_hw_release_version()
#define BAM_CFG_RELEASE_VERSION (const char*)bam_sif_get_release_version()
#define BAM_CFG_BUILD_DATE_TIME (const char*)bam_sif_get_build_date_and_time()
#define BAM_CFG_J2ME_MIDP_VERSION (const char*)bam_sif_get_j2me_midp_version()
#define BAM_CFG_J2ME_CLDC_VERSION (const char*)bam_sif_get_j2me_cldc_version()
#define BAM_CFG_LANGUAGE_CODE (const char*)bam_sif_get_language()
#define BAM_CFG_HTTPS_PGDL_SUPPORT (const char*)bam_sif_get_https_pgdl_support()



#ifdef BAM_CFG_DEFAULT_HTTPS_PGDL_SUPPORT
#if defined (PGDL_SUPPORT) && defined(WAP_SEC_SUPPORT)
#define BAM_SIF_HTTPS_PGDL_SUPPORT "(HTTP PGDL; HTTPS) "
#endif
#if defined (PGDL_SUPPORT) && !defined(WAP_SEC_SUPPORT)
#define BAM_SIF_HTTPS_PGDL_SUPPORT "(HTTP PGDL) "
#endif
#if defined (WAP_SEC_SUPPORT) && !defined(PGDL_SUPPORT)
#define BAM_SIF_HTTPS_PGDL_SUPPORT "(HTTPS) "
#endif
#if !defined (WAP_SEC_SUPPORT) && !defined(PGDL_SUPPORT)
#define BAM_SIF_HTTPS_PGDL_SUPPORT ""
#endif
#else 
#define BAM_SIF_HTTPS_PGDL_SUPPORT ""
#endif


#ifdef BAM_CFG_DEFAULT_HW_RELEASE_VER
#define BAM_SIF_HW_RELEASE_VER (const char*)release_hw_ver()
#else
#define BAM_SIF_HW_RELEASE_VER ""
#endif

#ifdef BAM_CFG_DEFAULT_RELEASE_VERSION
#define BAM_SIF_RELEASE_VERSION (const char*)release_verno()
#else
#define BAM_SIF_RELEASE_VERSION ""
#endif

#ifdef BAM_CFG_DEFAULT_BUILD_DATE_TIME
#define BAM_SIF_BUILD_DATE_TIME (const char*)build_date_time()
#else
#define BAM_SIF_BUILD_DATE_TIME ""
#endif

#ifdef __J2ME__
#ifdef BAM_CFG_DEFAULT_J2ME_MIDP_VERSION
#define BAM_SIF_J2ME_MIDP_VERSION (const char*)j2me_get_midp_version()
#else
#define BAM_SIF_J2ME_MIDP_VERSION ""
#endif
#ifdef BAM_CFG_DEFAULT_J2ME_CLDC_VERSION
#define BAM_SIF_J2ME_CLDC_VERSION (const char*)j2me_get_cldc_version()
#else
#define BAM_SIF_J2ME_CLDC_VERSION ""
#endif
#else
#define BAM_SIF_J2ME_MIDP_VERSION ""
#define BAM_SIF_J2ME_CLDC_VERSION ""
#endif

#ifdef BAM_CFG_DEFAULT_LANGUAGE_CODE
#define BAM_SIF_LANGUAGE_CODE (const char*)Get_Current_Lang_CountryCode()
#else 
#define BAM_SIF_LANGUAGE_CODE ""
#endif


#ifdef OBIGO_Q03C_BROWSER

#ifndef _CUSTOM_WAP_CONFIG_H
#include "custom_wap_config.h"
#endif

#define BAM_CFG_EXTERNAL_DRIVE  "D:"

#if 0
/* under construction !*/
/* under construction !*/
#endif



/* Enable/Disable select mode. */
#define BAM_CFG_SELECT_MODE

/* Maximum number of links in the history list. */
#define BAM_CFG_HISTORY_LIST_SIZE         30

/* The location and filename of the history list file. */
#define BAM_CFG_HISTORY_LIST_FILE_PATH    "/bam/histlist.dat"

/* The location and filename of the temporary history list file. */
#define BAM_CFG_HISTORY_LIST_FILE_TEMP    "/bam/histlist.tmp"

/* Max number of characters allowed for a history item title. */
/* Should be sync with BAM_MAX_TITLE_LABEL_LEN. */
#define BAM_CFG_HISTORY_MAX_TITLE_LENGTH 40

/* Max memory limit of history items. In bytes. */
#define BAM_CFG_HISTORY_LIST_MAX_MEM (30 * 1024)

#define BAM_CFG_HISTORY_INITIAL_SIZE          6000

#if 0
/* under construction !*/
/* under construction !*/
#endif

/* Enable/Disable the offline pages functionality.
   NOTE: BRS_CFG_OFFLINE_PAGES in brs_cfg.h must be defined. */
//#define BAM_CFG_OFFLINE_PAGES

/* Mime types of handled image object. Define as NULL if not used. */
//#define BAM_CFG_OBJ_LOAD_IMAGE            "image/*,audio/amr,audio/imelody,audio/mid,audio/wav"

/* Mime types of handled audio object. Define as NULL if not used. */
//#define BAM_CFG_OBJ_LOAD_AUDIO            "audio/*"

/* Mime types of handled video object. Define as NULL if not used. */
//#define BAM_CFG_OBJ_LOAD_VIDEO            "video/*"

#define BAM_CFG_DEFAULT_OBJ_ASK             NULL
#define BAM_CFG_DEFAULT_OBJ_LOAD          "image/*,audio/amr,audio/imelody,audio/mid,audio/wav" /* Cannot contain space character */
#define BAM_CFG_DEFAULT_BRS_TIMEOUT       90
#define BAM_CFG_DEFAULT_TIMEOUT           (MSF_INT32)(wap_custom_get_default_browse_timeout())
#define BAM_CFG_MAX_CACHE_SIZE            (MSF_INT32)(wap_custom_get_max_cache_size())
#define BAM_CFG_REGISTRY_DEFAULT_CACHESIZE    BAM_CFG_MAX_CACHE_SIZE
#define BAM_CFG_REGISTRY_DEFAULT_COOKIES      1
#define BAM_CFG_REGISTRY_DEFAULT_UA_HEADER    ((char*)wap_custom_get_ua_header())
#define BAM_CFG_REGISTRY_DEFAULT_UA_PROF      ((char*)wap_custom_get_ua_prof_url())
#define BAM_CFG_REGISTRY_DEFAULT_HISTSIZE     10
#define BAM_CFG_REGISTRY_DEFAULT_PRX_RLM      NULL
#define BAM_CFG_REGISTRY_DEFAULT_LDNOMIME     1
#define BAM_CFG_REGISTRY_DEFAULT_REFRESH      1
#define BAM_CFG_REGISTRY_DEFAULT_USE_CACHE    1
#define BAM_CFG_REGISTRY_DEFAULT_USE_CSS      1
#if defined(__COSMOS_MMI_PACKAGE__) || defined (BAM_CFG_BRW_DISPLAY_INLINE_DO)
#define BAM_CFG_REGISTRY_DEFAULT_INLINE_DO    1
#else
#define BAM_CFG_REGISTRY_DEFAULT_INLINE_DO    0
#endif
#define BAM_CFG_SHOW_COOKIE_DISABLED_POPUP    FALSE
#define BAM_CFG_SHOW_COOKIE_POPUP_FOR_ALL_REQ FALSE
#define BAM_CFG_ACCEPT_LANGUAGE_PREFERENCE    ((char*)wap_custom_get_accept_language_preference())

/*
 * SUI Zoom
 */
 
#if 0
#if defined(__MMI_VECTOR_FONT_SUPPORT__) && defined(BRS_CFG_SUI_ZOOM_ENABLED)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#ifdef BAM_CFG_SUI_ZOOM_ENABLED
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* BAM_CFG_SUI_ZOOM_ENABLED */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef BRS_CFG_SUI_THUMBNAIL_ENABLED
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef BRS_CFG_SUI_HOTSPOT_ENABLED
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef BRS_CONFIG_USE_SHORTCUTS
/* under construction !*/
/* under construction !*/
#endif
#ifdef BAM_CFG_SHORTCUTS_ENABLED
/* under construction !*/
#ifdef BAM_CFG_SUI_THUMBNAIL_ENABLED
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* BAM_CFG_SUI_THUMBNAIL_ENABLED */
/* under construction !*/
#ifdef BAM_CFG_SUI_HOTSPOT_ENABLED
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* BAM_CFG_SUI_HOTSPOT_ENABLED */
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
#endif /* BAM_CFG_SHORTCUTS_ENABLED */
#endif

/* Max total message size over WAP connection.
   The value should not exceed 300K (based on STK_CFG_WTP_SAR_MAX_PDU_SIZE) */
#define BAM_MAX_WAP_CONN_MSG_SIZE (250 * 1024)

#ifdef __MMI_BRW_PAGE_FETCHING_STATUS__
#define BAM_CFG_PAGE_FETCHING_STATUS_SUPPORT
#endif

#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
#define BAM_CFG_RECENT_PAGES_SUPPORT
#endif

#endif /* _bam_cfg_h */


#endif /*OBIGO_Q03C_BROWSER*/
