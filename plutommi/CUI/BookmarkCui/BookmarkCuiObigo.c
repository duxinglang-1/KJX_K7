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
 *  BookmarkCuiObigo.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h"
#ifndef MMI_BOOKMARKCUIOBIGO_C
#define MMI_BOOKMARKCUIOBIGO_C

#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "BrowserSrvProts.h"
#include "BrowserSrvBookmarks.h"
#include "BrowserSrvConfig.h"
#include "app_mem.h"
#include "mmi_frm_events_gprot.h"
#include "DebugInitDef_Int.h"


#ifdef __MMI_BROWSER_2__
#include "BookmarkCuiGprot.h"
#include "BrowserAppInterface.h"
#include "BrowserAppTypes.h"
/* for RHR */
#include "CustDataRes.h"
#include "gui_data_types.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "mmi_frm_scenario_gprot.h"
#include "FileMgrSrvGProt.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "Conversions.h"
#include "BrowserResDef.h"
/* for RHR */

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_sel_bkm_create
 * DESCRIPTION
 *  To create select bookmark group
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_id  : Returns Group Id
 *****************************************************************************/
mmi_id cui_bkm_sel_bkm_create(mmi_id parent_gid)
{
    S32 error_code = 0;
    if(parent_gid != GRP_ID_INVALID)
    {
        if(g_brw_app_cntx.sel_bkm_cid != GRP_ID_INVALID)
        {
            mmi_brw_app_ui_draw_display_popup_ext(STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_FAILURE);
            return GRP_ID_INVALID;
        }
        if (!g_srv_brw_cntx.brw_adm_id)
        {
            g_brw_app_memory_pool = applib_mem_ap_alloc(APP_BROWSER, SRV_BRW_APP_POOL_SIZE);
            if (!g_brw_app_memory_pool)
            {
                mmi_brw_app_ui_draw_display_popup_ext(STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_FAILURE);
                return GRP_ID_INVALID;
            }
            else
            {
                g_brw_bkm_sel_bkm_pool = MMI_TRUE;
            }

            g_srv_brw_cntx.brw_adm_id = kal_adm_create(
                                        (char*)g_brw_app_memory_pool,
                                        SRV_BRW_APP_POOL_SIZE,
                                        NULL,
                                        KAL_FALSE);
            MMI_ASSERT(g_srv_brw_cntx.brw_adm_id);
        }
        error_code = srv_brw_bkm_initialize_bookmark_context();
        if(error_code == 0)
        {
            if(g_srv_brw_cntx.bookmark_count == 0)
            {
                mmi_brw_app_ui_draw_display_popup_ext(STR_GLOBAL_EMPTY, MMI_EVENT_FAILURE);
                error_code = 1;
            }
        }
        if(error_code != 0)
        {
            if(error_code < 0)
            {
                mmi_brw_app_file_system_error_handler(error_code);
            }
            if(g_brw_bkm_sel_bkm_pool)
            {
                mmi_brw_app_deinit();
            }
            return GRP_ID_INVALID;
        }
        g_brw_app_cntx.sel_bkm_cid = mmi_frm_group_create(parent_gid, GRP_ID_AUTO_GEN, mmi_brw_bkm_sel_bookmark_proc, NULL);
        return  g_brw_app_cntx.sel_bkm_cid;
    }
    else
    {
        return GRP_ID_INVALID;
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_sel_bkm_run
 * DESCRIPTION
 *  To enter into select bookmark group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bkm_sel_bkm_run(mmi_id cui_gid)
{
    mmi_frm_group_enter(cui_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    g_brw_bkm_sel_bkm_cntx.sel_file_index = 0;
    if(g_brw_bkm_sel_bkm_cntx.sel_folder_name)
    {
        MMI_ASSERT(!g_brw_bkm_sel_bkm_cntx.sel_folder_name);
    }
    g_brw_bkm_sel_bkm_cntx.sel_folder_name = (U8*)srv_brw_malloc((SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1) *ENCODING_LENGTH);
    memset(g_brw_bkm_sel_bkm_cntx.sel_folder_name, 0, (SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1) *ENCODING_LENGTH);
    /* Call select bookmark screen */
    mmi_brw_app_create_select_bookmark_list();
    mmi_brw_app_if_show_select_bookmark_screen();	
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_sel_bkm_close
 * DESCRIPTION
 *  To close select bookmark group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bkm_sel_bkm_close(mmi_id cui_gid)
{
    mmi_frm_group_close(cui_gid);
    g_brw_app_cntx.sel_bkm_cid = GRP_ID_INVALID;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_create
 * DESCRIPTION
 *  To create select bookmark group
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_id  : Returns Group Id
 *****************************************************************************/
mmi_id cui_bkm_add_bkm_create(mmi_id parent_gid)
{
    S32 error_code;
    if(parent_gid != GRP_ID_INVALID)
    {
        if(g_brw_app_cntx.add_bkm_cid != GRP_ID_INVALID)
        {
            mmi_brw_app_ui_draw_display_popup_ext(STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_FAILURE);
            return GRP_ID_INVALID;
        }
        if (!g_srv_brw_cntx.brw_adm_id)
        {
            g_brw_app_memory_pool = applib_mem_ap_alloc(APP_BROWSER, SRV_BRW_APP_POOL_SIZE);
            if (!g_brw_app_memory_pool)
            {
                mmi_brw_app_ui_draw_display_popup_ext(STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_FAILURE);
                return GRP_ID_INVALID;
            }
            else
            {
                g_brw_bkm_sel_bkm_pool = MMI_TRUE;
            }

            g_srv_brw_cntx.brw_adm_id = kal_adm_create(
                                        (char*)g_brw_app_memory_pool,
                                        SRV_BRW_APP_POOL_SIZE,
                                        NULL,
                                        KAL_FALSE);
            MMI_ASSERT(g_srv_brw_cntx.brw_adm_id);
        }
        error_code = srv_brw_bkm_initialize_bookmark_context();
        if(error_code == 0)
        {
            if (!mmi_brw_app_check_available_bookmark_memory())
            {
                error_code = 1;
            }
        }
        if(error_code != 0)
        {
            if(error_code < 0)
            {
                mmi_brw_app_file_system_error_handler(error_code);
            }
            if(g_brw_bkm_sel_bkm_pool)
            {
                mmi_brw_app_deinit();
            }
            return GRP_ID_INVALID;
        }
        g_brw_app_cntx.add_bkm_cid = mmi_frm_group_create(parent_gid, GRP_ID_AUTO_GEN, mmi_brw_bkm_add_bookmark_proc, NULL);
        return  g_brw_app_cntx.add_bkm_cid ;
    }
    else
    {
        return GRP_ID_INVALID;
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_run
 * DESCRIPTION
 *  To enter into select bookmark group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bkm_add_bkm_run(mmi_id cui_gid, const U8 * added_utf8_url)
{
    mmi_frm_group_enter(cui_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_chset_utf8_to_ucs2_string(
        (U8*) g_brw_current_url,
        (SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH,
        (U8*) added_utf8_url);

    g_brw_bkm_add_type = BRW_BKM_ADD_TO_BOOKMARK;
    mmi_asc_to_ucs2((S8*) g_brw_current_title, (S8*) "");
    mmi_frm_group_close(BRW_ADD_BOOKMARK_GRP_ID);
    mmi_brw_app_if_show_add_to_bookmark_screen();
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_close
 * DESCRIPTION
 *  To close select bookmark group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bkm_add_bkm_close(mmi_id cui_gid)
{
    if(g_brw_bkm_sel_bkm_pool)
    {
        mmi_brw_app_deinit();
    }
    mmi_frm_group_close(cui_gid);
    g_brw_app_cntx.add_bkm_cid = GRP_ID_INVALID;
}

#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BOOKMARKCUIOBIGO_C */
