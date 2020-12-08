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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_v2p_hs_widget_bookmark.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file provides the adaptation functions of bookmark widget from 
 *  Venus MMI to PlutoMMI.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VADP_V2P_HS_WIDGET_BOOKMARK_H__
#define __VADP_V2P_HS_WIDGET_BOOKMARK_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_BOOKMARK__

#ifdef __cplusplus
extern "C"
{
#endif

/* Pluto headers: */
#include "stdlib.h"

/* Opera bookmark APIs */
#include "OpDevBookmark.h"

#include "MMIDataType.h"
#include "kal_general_types.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VADP_HS_WIDGET_BOOKMARK_MAX_TITLE_LEN                           (35)
#define VADP_HS_WIDGET_BOOKMARK_MAX_URL_LEN                             (1024)
#define VADP_HS_WIDGET_BOOKMARK_CACHED_THUMBNAIL_RESOURCE_NUM           (12)
#define VADP_HS_WIDGET_BOOKMARK_CACHED_THUMBNAIL_RESOURCE_SIZE          (10*1024)
#define VADP_HS_WIDGET_BOOKMARK_CACHED_THUMBNAIL_RESOURCE_HEADER_SIZE   (8)
#define VADP_HS_WIDGET_BOOKMARK_SCR_ASM_POOL_SIZE                       (VADP_HS_WIDGET_BOOKMARK_CACHED_THUMBNAIL_RESOURCE_NUM * (VADP_HS_WIDGET_BOOKMARK_CACHED_THUMBNAIL_RESOURCE_HEADER_SIZE + VADP_HS_WIDGET_BOOKMARK_CACHED_THUMBNAIL_RESOURCE_SIZE))

/***************************************************************************** 
 * Type Definition
 *****************************************************************************/

/***************************************************************************** 
 * Global Function
 *****************************************************************************/
/* Adaptor function */
extern void vadp_v2p_hs_bkm_init_cntx(void);
extern S32 vadp_v2p_hs_bkm_init_bookmark(void);
extern S32 vadp_v2p_hs_bkm_get_bookmark(Opera_BookmarkSortingMethod sorting_method);
extern void vadp_v2p_hs_bkm_get_bookmark_title_by_index(S32 index, U8 *title);
extern void vadp_v2p_hs_bkm_get_bookmark_thumbnail_by_index(S32 index, U8 **rawDataMemory);
extern void vadp_v2p_hs_bkm_tap_bookmark_thumbnail(S32 index);
extern MMI_BOOL vadp_v2p_hs_bkm_get_bookmark_index_by_id(S32 id, S32 *index);
extern MMI_BOOL vadp_v2p_hs_bkm_get_bookmark_id_by_index(S32 index, S32 *id);
extern void vadp_v2p_hs_bkm_exit_bookmark(void);
extern void vadp_v2p_hs_bkm_deinit_cntx(void);

/* Utility function */
extern S32 vadp_v2p_hs_bkm_get_bookmark_num(void);
#ifdef __USB_IN_NORMAL_MODE__
extern MMI_BOOL vadp_v2p_hs_bkm_usb_is_in_mass_storage_mode(void);
extern MMI_STR_ID vadp_v2p_hs_bkm_usb_get_error_info(void);
#endif /* __USB_IN_NORMAL_MODE__ */

#ifdef __cplusplus
}   /* extern "C" */
#endif

#endif /* __MMI_VUI_HOMESCREEN_BOOKMARK__ */

#endif /* __VADP_V2P_HS_WIDGET_BOOKMARK_H__ */

