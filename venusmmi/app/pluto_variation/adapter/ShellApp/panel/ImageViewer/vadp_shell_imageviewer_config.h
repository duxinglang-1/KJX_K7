/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
 *  vadp_shell_imageviewer_config.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file provides the adaptation functions from the Venus MMI to the Pluto
 *  MMI.
 *
 *      Pluto APP <---> adaptor <---> Venus APP
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VADP_SEHLL_IMAGEVIEWER_CONFIG_H__
#define __VADP_SEHLL_IMAGEVIEWER_CONFIG_H__

#include "MMI_features.h"
#ifdef __MMI_VUI_SHELL_IMAGE_VIEWER__
#include "MediaCacheSrvMem.h"
#include "gdi_include.h"
#include "FileMgrSrvGProt.h"

#if defined(__MMI_MAINLCD_320X480__)
    #define VADP_SHELLIV_CELL_WIDTH     (278)
    #define VADP_SHELLIV_CELL_HEIGHT    (240)
#elif defined(__MMI_MAINLCD_240X400__)
    #define VADP_SHELLIV_CELL_WIDTH     (206)
    #define VADP_SHELLIV_CELL_HEIGHT    (194)
#else 
    #define VADP_SHELLIV_CELL_WIDTH     (176)
    #define VADP_SHELLIV_CELL_HEIGHT    (162)
#endif

#define VADP_SHELLIV_CELL_SIZE (((VADP_SHELLIV_CELL_WIDTH * VADP_SHELLIV_CELL_HEIGHT * GDI_MAINLCD_BIT_PER_PIXEL)>>3))

#if defined(__SQLITE3_SUPPORT__)
#define VADP_SHELLIV_SQLITE_BUFFER_SIZE SRV_MEDIACACHE_CALC_SQLITE_DB_BUF_SIZE_BY_W_H(VADP_SHELLIV_CELL_WIDTH,VADP_SHELLIV_CELL_HEIGHT)
#else
#define VADP_SHELLIV_SQLITE_BUFFER_SIZE (0)
#endif

#if defined(__MMI_VUI_SHELL_IMAGE_VIEWER_SLIM__)
#define VADP_SHELLIV_CACHE_CELL_COUNT   (10)
#else
#define VADP_SHELLIV_CACHE_CELL_COUNT   (15)
#endif

#define VADP_SHELLIV_CACHE_RUN_BUFFER_SIZE (SRV_MEDIACACHE_RUN_BUF_SIZE(VADP_SHELLIV_CACHE_CELL_COUNT))
#define VADP_SHELLIV_CACHE_BUFFER_SIZE (VADP_SHELLIV_CELL_SIZE * VADP_SHELLIV_CACHE_CELL_COUNT)

#define VADP_SHELLIV_FILECOUNT_LIMIT    (5000)
#if (VADP_SHELLIV_FILECOUNT_LIMIT > FS_SORT_MAX_ENTRY)
#define VADP_SHELLIV_FILECOUNT_MAX (FS_SORT_MAX_ENTRY)
#else
#define VADP_SHELLIV_FILECOUNT_MAX (VADP_SHELLIV_FILECOUNT_LIMIT)
#endif

#define VADP_SHELLIV_MED_MEM_SIZE   (VADP_SHELLIV_CACHE_BUFFER_SIZE + VADP_SHELLIV_CACHE_RUN_BUFFER_SIZE + VADP_SHELLIV_SQLITE_BUFFER_SIZE)

#define VADP_SHELLIV_FILELIST_MEM_SIZE SRV_FMGR_FOLDER_FILELIST_MEM_SIZE_FOR(VADP_SHELLIV_FILECOUNT_MAX)

#endif /* __MMI_VUI_SHELL_IMAGE_VIEWER__ */
#endif /* __VADP_SEHLL_IMAGEVIEWER_CONFIG_H__ */
