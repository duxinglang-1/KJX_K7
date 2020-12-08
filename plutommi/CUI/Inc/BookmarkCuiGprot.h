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
 *  BookmarkCuiGprot.h
 *
 * Project:
 * -------- 
 *  Bookmark CUI
 *
 * Description:
 * ------------
 *  This file contains exported APIs of bookmark CUI.
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
#ifndef _BOOKMARK_CUI_GPROT_H_
#define _BOOKMARK_CUI_GPROT_H_

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "mmi_res_range_def.h"
#include "MMIDataType.h"
/***************************************************************************** 
 * Constant
 *****************************************************************************/
/* This length does not consider the null character */
#if defined (OPERA_BROWSER)
#define CUI_BKM_MAX_URL_LEN                         (1024)
#elif (defined (OBIGO_Q05A) || defined (OBIGO_Q03C_BROWSER))
#define CUI_BKM_MAX_URL_LEN                         (255)
#else
#define CUI_BKM_MAX_URL_LEN                         (0)     /* Dummy for BROWSER_SUPPORT = NONE */
#endif

/***************************************************************************** 
 * Macro
 *****************************************************************************/

/***************************************************************************** 
 * Enum
 *****************************************************************************/

#ifdef __COSMOS_MMI_PACKAGE__
#include "vapp_package_res.h"
#if defined(VCUI_BKM)
#define CUI_BKM_BASE VCUI_BKM
#elif defined(VAPP_BOOKMARK_CUI)
#define CUI_BKM_BASE VAPP_BOOKMARK_CUI
#else
#define CUI_BKM_BASE 65500
#endif
#endif

/* CUI event ID. After common UI process end, CUI will use these event to notify caller */
typedef enum
{
    /* cui_bkm_sel_bkm_result_evt_struct */
    EVT_ID_CUI_BKM_SEL_BKM_RESULT = (CUI_BKM_BASE + 1),

    /* cui_bkm_add_bkm_result_evt_struct */
    EVT_ID_CUI_BKM_ADD_BKM_CLOSE
} cui_bkm_evt_enum;

/***************************************************************************** 
 * Structure
 *****************************************************************************/

/* Result structure of selecting bookmark */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */
    
    /* Bookmark CUI need to allocate memory for *selected_utf8_title. 
       Caller application need to copy another one for future use. 
       Bookmark CUI need to free memory after caller application invoke 
       cui_bookmark_select_bookmark_close(). If user do not select bookmark or 
       bookmark is empty or out of memory occurs, set *selected_utf8_title as NULL.
       Note: There is no limitation for title length. */
    U8 *selected_utf8_title;
    
    /* Bookmark CUI need to allocate memory for *selected_utf8_url. 
       Caller application need to copy another one for future use. 
       Bookmark CUI need to free memory after caller application invoke 
       cui_bookmark_select_bookmark_close(). If user do not select bookmark or 
       bookmark is empty or out of memory occurs, set *selected_utf8_url as NULL.
       Note: There is no limitation for URL length. */
    U8 *selected_utf8_url;
} cui_bkm_sel_bkm_result_evt_struct;

/* Result structure of adding bookmark */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */
} cui_bkm_add_bkm_result_evt_struct;

/***************************************************************************** 
 * Type Definition
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Global Function
 *****************************************************************************/
 
/*****************************************************************************
 * FUNCTION
 *  cui_bkm_sel_bkm_create
 * DESCRIPTION
 *  This function is used to create selecting bookmark common UI.
 *  If the common UI cannot be entered, it will return GRP_ID_INVALID.
 *  Caller need to check the returned group id to see if the common UI can be entered.
 * PARAMETERS
 *  parent_gid: [IN]    Group ID of parent
 * RETURNS
 *  Return group id of CUI if CUI can be entered or return GRP_ID_INVALID if CUI can not be entered.
 *****************************************************************************/
mmi_id cui_bkm_sel_bkm_create(mmi_id parent_gid);

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_sel_bkm_run
 * DESCRIPTION
 *  This function is used to run selecting bookmark common UI.
 *  It will entry a screen group and entry selecting bookmark screen.
 * PARAMETERS
 *  cui_gid:    [IN]    Group ID of CUI
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bkm_sel_bkm_run(mmi_id cui_gid);

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_sel_bkm_close
 * DESCRIPTION
 *  This function is used to close selecting bookmark common UI
 * PARAMETERS
 *  cui_gid:    [IN]    Group ID of CUI
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bkm_sel_bkm_close(mmi_id cui_gid);

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_create
 * DESCRIPTION
 *  This function is used to create adding bookmark common UI.
 *  If the common UI cannot be entered, it will return GRP_ID_INVALID.
 *  Caller need to check the returned group id to see if the common UI can be entered.
 * PARAMETERS
 *  parent_gid: [IN]    Group ID of parent
 * RETURNS
 *  Return group id of CUI if CUI can be entered or return GRP_ID_INVALID if CUI can not be entered.
 *****************************************************************************/
mmi_id cui_bkm_add_bkm_create(mmi_id parent_gid);

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_run
 * DESCRIPTION
 *  This function is used to run adding bookmark common UI.
 *  It will entry a screen group and entry adding bookmark screen.
 * PARAMETERS
 *  cui_gid:        [IN]    Group ID of CUI
 *  added_utf8_url: [IN]    URL of bookmark which will be added to bookmarks
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bkm_add_bkm_run(mmi_id cui_gid, const U8 *added_utf8_url);

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_close
 * DESCRIPTION
 *  This function is used to close adding bookmark common UI
 * PARAMETERS
 *  cui_gid:    [IN]    Group ID of CUI
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bkm_add_bkm_close(mmi_id cui_gid);

#endif /* _BOOKMARK_CUI_GPROT_H */

