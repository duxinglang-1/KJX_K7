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
 *  BookmarkCuiOpera.h
 *
 * Project:
 * -------- 
 *  Bookmark CUI
 *
 * Description:
 * ------------
 *  This file contains bookmark CUI for Opera browser solution.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _BOOKMARK_CUI_OPERA_H_
#define _BOOKMARK_CUI_OPERA_H_

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifdef OPERA_BROWSER

/* Bookmark CUI */
#include "BookmarkCuiGprot.h"

/* Opera bookmark APIs */
#include "OpDevBookmark.h"

#include "MMIDataType.h"
#include "kal_general_types.h"

/***************************************************************************** 
 * Constant
 *****************************************************************************/
#define CUI_BKM_INVALID_ID                          (-1)
#define CUI_BKM_MAX_TITLE_LEN                       (35)
#define CUI_BKM_MAX_FOLDER_LEN                      (35)
#define CUI_BKM_CACHED_FAVICON_RESOURCE_NUM         (20)
#define CUI_BKM_CACHED_FAVICON_RESOURCE_SIZE        (5 * 1024)
#define CUI_BKM_CACHED_FAVICON_RESOURCE_HEADER_SIZE (8)
#define CUI_BKM_SCR_ASM_POOL_SIZE                   (CUI_BKM_CACHED_FAVICON_RESOURCE_NUM * (CUI_BKM_CACHED_FAVICON_RESOURCE_HEADER_SIZE + CUI_BKM_CACHED_FAVICON_RESOURCE_SIZE))

/***************************************************************************** 
 * Macro
 *****************************************************************************/

/***************************************************************************** 
 * Enum
 *****************************************************************************/

/***************************************************************************** 
 * Structure
 *****************************************************************************/
typedef struct
{
    S32                     select_item_index;
    S32                     select_item_id;
    S32                     parent_id_to_go_back;
    MMI_BOOL                is_first_enter;
    MMI_BOOL                is_bkm_data_changed;
    U8                      *select_title;
    U8                      *select_url;
    U8                      cached_favicon_resource_idx;
    U8                      *cached_favicon_resource[CUI_BKM_CACHED_FAVICON_RESOURCE_NUM];
    opera_bookmark_list_t   select_bookmark_list;
} cui_bkm_sel_bkm_cntx_struct;

typedef struct
{
    S32                     select_folder_index;
    S32                     select_folder_id;
    S32                     parent_id_to_go_back;
    S32                     add_folder_id;
    S32                     add_bookmark_result;
    MMI_BOOL                is_first_enter;
    MMI_BOOL                is_bkm_data_changed;
    mmi_id                  add_bkm_inline_gid;
    mmi_id                  address_fseditor_gid;
    mmi_id                  folder_option_menu_gid;
    U8                      title[(CUI_BKM_MAX_TITLE_LEN+1) * ENCODING_LENGTH];
    U8                      url[(CUI_BKM_MAX_URL_LEN+1) * ENCODING_LENGTH];
    U8                      temp_url[(CUI_BKM_MAX_URL_LEN+1) * ENCODING_LENGTH];
    U8                      folder[(CUI_BKM_MAX_FOLDER_LEN+1) * ENCODING_LENGTH];
    opera_bookmark_list_t   select_folder_list;
} cui_bkm_add_bkm_cntx_struct;

/***************************************************************************** 
 * Type Definition
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

#endif /* OPERA_BROWSER */

#endif /* _BOOKMARK_CUI_OPERA_H_ */

