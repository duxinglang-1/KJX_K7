/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  vapp_widget_key_image_viewer_mem_cfg.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_WIDGET_KEY_IMAGE_VIEWER_MEM_CFG_H
#define VAPP_WIDGET_KEY_IMAGE_VIEWER_MEM_CFG_H

#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_KEY_IMAGE_VIEWER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

#include "lcd_sw_inc.h"
#include "MMIDataType.h"
#include "FileMgrSrvGProt.h"
#include "gdi_include.h"
#include "MediaCacheSrvMem.h"

#ifdef __cplusplus
}
#endif

/*****************************************************************************
 * Memory config
 *****************************************************************************/

/*----------------------------------------------------------------*/
/* File List                                                      */
/*----------------------------------------------------------------*/

#define VAPP_WIDGET_KEY_IMAGE_VIEWER_FILECOUNT_LIMIT    (5000)

#if defined(__FS_SORT_SUPPORT__)
#if (VAPP_WIDGET_KEY_IMAGE_VIEWER_FILECOUNT_LIMIT > FS_SORT_MAX_ENTRY)
#define VAPP_WIDGET_KEY_IMAGE_VIEWER_FILECOUNT_MAX      (FS_SORT_MAX_ENTRY)
#else
#define VAPP_WIDGET_KEY_IMAGE_VIEWER_FILECOUNT_MAX      (VAPP_WIDGET_KEY_IMAGE_VIEWER_FILECOUNT_LIMIT)
#endif
#else
#define VAPP_WIDGET_KEY_IMAGE_VIEWER_FILECOUNT_MAX      (0)
#endif

#define VAPP_WIDGET_KEY_IMAGE_VIEWER_FILELIST_MEM_SIZE  SRV_FMGR_FOLDER_FILELIST_MEM_SIZE_FOR(VAPP_WIDGET_KEY_IMAGE_VIEWER_FILECOUNT_MAX)

/*----------------------------------------------------------------*/
/* Media Cache                                                    */
/*----------------------------------------------------------------*/

#define VAPP_WIDGET_KEY_IMAGE_VIEWER_CACHE_SIZE     (((CELL_WIDTH * CELL_HEIGHT * GDI_MAINLCD_BIT_PER_PIXEL)>>3))
#define VAPP_WIDGET_KEY_IMAGE_VIEWER_CACHE_COUNT    (3)
#define VAPP_WIDGET_KEY_IMAGE_VIEWER_CACHE_BUFFER_SIZE (VAPP_WIDGET_KEY_IMAGE_VIEWER_CACHE_SIZE * VAPP_WIDGET_KEY_IMAGE_VIEWER_CACHE_COUNT)

#define VAPP_WIDGET_KEY_IMAGE_VIEWER_CACHE_RUN_BUFFER_SIZE  (SRV_MEDIACACHE_RUN_BUF_SIZE(VAPP_WIDGET_KEY_IMAGE_VIEWER_CACHE_COUNT))

#if defined(__SQLITE3_SUPPORT__)
#define VAPP_WIDGET_KEY_IMAGE_VIEWER_SQLITE_BUFFER_SIZE SRV_MEDIACACHE_CALC_SQLITE_DB_BUF_SIZE_BY_W_H(CELL_WIDTH, CELL_HEIGHT)
#else
#define VAPP_WIDGET_KEY_IMAGE_VIEWER_SQLITE_BUFFER_SIZE (0)
#endif

#define VAPP_WIDGET_KEY_IMAGE_VIEWER_MED_MEM_SIZE   (VAPP_WIDGET_KEY_IMAGE_VIEWER_CACHE_RUN_BUFFER_SIZE + VAPP_WIDGET_KEY_IMAGE_VIEWER_SQLITE_BUFFER_SIZE + VAPP_WIDGET_KEY_IMAGE_VIEWER_CACHE_BUFFER_SIZE)


#endif

#endif


