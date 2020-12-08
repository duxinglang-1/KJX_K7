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
 *  MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#define _FMGR_INTERNAL_SOURCE_C_
/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "FileMgrGProt.h"
#include "FileMgrCuiGProt.h"
#if defined (__MMI_FILE_MANAGER__)
#include "FileMgrProt.h"

#include "MMIDataType.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "GlobalResDef.h"
#include "mmi_frm_mem_gprot.h"
#include "string.h"
#include "mmi_rp_app_filemanager_def.h"
#include "mmi_rp_file_type_def.h"
#include "wgui_categories_list.h"
#include "mmi_res_range_def.h"
/****************************************************************************
* Define
*****************************************************************************/
#if !defined(__MMI_ULTRA_SLIM_FILE_MANAGER__) && defined(__MMI_FRM_HISTORY__)

#define FMGR_ADP_MAX_INSTANCE   5

typedef enum _fmgr_adp_type_enum
{
    FMGR_ADP_TYPE_NONE,
    FMGR_ADP_TYPE_SEL_DRV,
    FMGR_ADP_TYPE_SEL_PATH,
    FMGR_ADP_TYPE_BROWSE,

    FMGR_ADP_TYPE_MAX
} fmgr_adp_type_enum;

typedef struct _fmgr_adp_base_struct
{
    fmgr_adp_type_enum type;
    mmi_id adp_grp;
    mmi_id cui_grp;

} fmgr_adp_base_struct;

typedef struct _fmgr_adp_select_drive_struct
{
    fmgr_adp_type_enum type;
    mmi_id adp_grp;
    mmi_id cui_grp;

    mmi_fmgr_select_drv_callback callback;
    
} fmgr_adp_select_drive_struct;

typedef struct _fmgr_adp_select_path_struct
{
    fmgr_adp_type_enum type;
    mmi_id adp_grp;
    mmi_id cui_grp;

    U16    app_id;
    U32    flag;
    PsExtFuncPtr callback;
    
} fmgr_adp_select_path_struct;

typedef struct _fmgr_adp_browse_path_struct
{
    fmgr_adp_type_enum type;
    mmi_id adp_grp;
    mmi_id cui_grp;

    U16    app_id;
    U32    flag;
    mmi_fmgr_browse_setting_struct setting;
    
} fmgr_adp_browse_path_struct;


/****************************************************************************
* Global Variable
*****************************************************************************/

/****************************************************************************
* Static Variable
*****************************************************************************/

/****************************************************************************
* Function Forward Declaration
*****************************************************************************/

#define END_OF_FUNCTION_DECLARATION

/****************************************************************************
* Function Body
*****************************************************************************/

#define LOCAL_FUNCTION

static mmi_id g_fmgr_adp_table[FMGR_ADP_MAX_INSTANCE] = {0};

static void fmgr_add_adp(mmi_id grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i=0;i<FMGR_ADP_MAX_INSTANCE;i++)
    {
        if(g_fmgr_adp_table[i])
            continue;
        
        g_fmgr_adp_table[i] = grp_id;
        return;
    }

    ASSERT(0);
}

static void fmgr_remove_adp(mmi_id grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(grp_id);
    for(i=0;i<FMGR_ADP_MAX_INSTANCE;i++)
    {
        if(g_fmgr_adp_table[i] != grp_id)
            continue;
        
        g_fmgr_adp_table[i] = 0;
    }
}

static fmgr_adp_type_enum fmgr_check_adp(mmi_id grp_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmgr_adp_base_struct *base;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(grp_id);
    for(i=0;i<FMGR_ADP_MAX_INSTANCE;i++)
    {
        if(g_fmgr_adp_table[i] != grp_id)
            continue;

        base = mmi_frm_group_get_user_data(grp_id);
        if(base)
            return base->type;
    }
    return FMGR_ADP_TYPE_NONE;
}

static mmi_id fmgr_find_first_adp(fmgr_adp_type_enum t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scr_id = GetActiveScreenId();
    if(t == fmgr_check_adp(scr_id))
        return scr_id;
    
    scr_id = GetExitScrnID();
    if(t == fmgr_check_adp(scr_id))
        return scr_id;

    scr_id = GetCurrScrnId();
    while(1)
    {
        if(t == fmgr_check_adp(scr_id))
            return scr_id;
        if(!GetPreviousScrnIdOf(scr_id, &scr_id))
            break;
    }
    return 0;
}

#define ADP_COMMON

BOOL mmi_fmgr_close_service(U32 fmgr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(MMI_RET_OK == mmi_frm_group_close((mmi_id)fmgr_id))
        return TRUE;

    return FALSE;
}

#define ADP_SELECT_DRV

static mmi_ret fmgr_adp_select_drive_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmgr_adp_select_drive_struct *adp_ctxt;
    mmi_id                       adp_grp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    adp_ctxt = (fmgr_adp_select_drive_struct*)evt->user_data;
    
    switch(evt->evt_id)
    {
    case EVT_ID_GROUP_DEINIT:
        fmgr_remove_adp(adp_ctxt->adp_grp);
        OslMfree(adp_ctxt);
        break;

    case EVT_ID_CUI_STORAGE_SELECTOR_RESULT:
        {
            cui_storage_selector_result_event_struct* param = (cui_storage_selector_result_event_struct*)evt;
            adp_grp = adp_ctxt->adp_grp;

            if(param->result < 0)
                adp_ctxt->callback(0);
            else
                adp_ctxt->callback((S8)param->result);

            /* auto exit */
            mmi_frm_group_close(adp_grp);
        }
        break;
    }
    return MMI_RET_OK;
}

U32  mmi_fmgr_select_drive(U16                          app_id, 
                           mmi_fmgr_select_drv_callback callback, 
                           S8                           default_highlight_storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmgr_adp_select_drive_struct *adp_ctxt;
    mmi_id cui_grp, adp_grp;
    U16 icon_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* create a adapter group */
    adp_ctxt = OslMalloc(sizeof(fmgr_adp_select_drive_struct));
    memset(adp_ctxt, 0, sizeof(*adp_ctxt));
    adp_ctxt->callback = callback;
    adp_ctxt->type = FMGR_ADP_TYPE_SEL_DRV;
    adp_grp = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, fmgr_adp_select_drive_proc, (void*)adp_ctxt);
    mmi_frm_group_enter(adp_grp, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    fmgr_add_adp(adp_grp);
    adp_ctxt->adp_grp = adp_grp;

    cui_grp = cui_storage_selector_create(adp_grp, (U8)default_highlight_storage, 0);
    if(!cui_grp)
    {
        FMGR_DisplayPopup(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE);
        mmi_frm_group_close(adp_grp);
        return 0;
    }
    adp_ctxt->cui_grp = cui_grp;

    mmi_fmgr_get_app_title_info(app_id, NULL, &icon_id, NULL);
#if defined (__MMI_FILE_MANAGER__)
    cui_storage_selector_set_title(cui_grp, STR_FMGR_TITLE, icon_id);
#else
    cui_storage_selector_set_title(cui_grp, NULL, icon_id);
#endif

    cui_storage_selector_run(cui_grp);
    
    return adp_grp;

}

#define ADP_SELECT_PATH

fmgr_adp_select_path_struct* g_adp_select_path = NULL;

static mmi_ret fmgr_adp_select_path_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmgr_adp_select_path_struct *adp_ctxt;
    S8* buffer;
    FMGR_FILE_INFO_STRUCT       info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    adp_ctxt = (fmgr_adp_select_path_struct*)evt->user_data;
    
    switch(evt->evt_id)
    {
    case EVT_ID_GROUP_DEINIT:
        if(g_adp_select_path == adp_ctxt)
            g_adp_select_path = NULL;
        fmgr_remove_adp(adp_ctxt->adp_grp);
        OslMfree(adp_ctxt);
        break;
#if !defined(__COSMOS_MMI__)
    case EVT_ID_CUI_FILE_SELECTOR_RESULT:
        {
            cui_file_selector_result_event_struct* param = (cui_file_selector_result_event_struct*)evt;
            if(param->result <= 0)
            {
                if(param->result == 0)
                {
                    g_adp_select_path = adp_ctxt;
                    mmi_fmgri_query_result_clear();
                    adp_ctxt->callback(NULL, 0);
                    if(!g_adp_select_path)
                        break;
                    g_adp_select_path = NULL;
                }

                /* auto exit */
                mmi_frm_group_close(adp_ctxt->adp_grp);
            }
            else
            {
                buffer = OslMalloc(FMGR_MAX_PATH_LEN*ENCODING_LENGTH);
                cui_file_selector_get_selected_filepath_old(adp_ctxt->cui_grp, &info, (WCHAR*)buffer, FMGR_MAX_PATH_LEN*ENCODING_LENGTH);

                g_adp_select_path = adp_ctxt;

                mmi_fmgri_query_result_setup(buffer, &info, adp_ctxt->app_id);
                adp_ctxt->callback(buffer, info.is_short);
                OslMfree(buffer);
                mmi_fmgri_query_result_clear();

                if(!g_adp_select_path)
                    break;
                g_adp_select_path = NULL;

                if(!(adp_ctxt->flag & FMGR_SELECT_REPEAT))
                    mmi_frm_group_close(adp_ctxt->adp_grp);
            }
        }
        break;
        
    case EVT_ID_CUI_FOLDER_SELECTOR_RESULT:
        {
            cui_folder_selector_result_event_struct* param = (cui_folder_selector_result_event_struct*)evt;
            if(param->result <= 0)
            {
                if(param->result == 0)
                {
                    g_adp_select_path = adp_ctxt;
                    mmi_fmgri_query_result_clear();
                    adp_ctxt->callback(NULL, 0);
                    if(!g_adp_select_path)
                        break;
                    g_adp_select_path = NULL;
                }

                /* auto exit */
                mmi_frm_group_close(adp_ctxt->adp_grp);
            }
            else
            {
                buffer = OslMalloc(FMGR_MAX_PATH_LEN*ENCODING_LENGTH);
                cui_folder_selector_get_selected_filepath_old(adp_ctxt->cui_grp, &info, (WCHAR*)buffer, FMGR_MAX_PATH_LEN*ENCODING_LENGTH);

                g_adp_select_path = adp_ctxt;

                mmi_fmgri_query_result_setup(buffer, &info, adp_ctxt->app_id);
                adp_ctxt->callback(buffer, info.is_short);
                OslMfree(buffer);
                mmi_fmgri_query_result_clear();

                if(!g_adp_select_path)
                    break;
                g_adp_select_path = NULL;


                if(!(adp_ctxt->flag & FMGR_SELECT_REPEAT))
                    mmi_frm_group_close(adp_ctxt->adp_grp);
            }
        }
        break;
#endif /* __COSMOS_MMI__ */
    }
    return MMI_RET_OK;
}

U32 mmi_fmgr_select_path(U16 app_id, 
                          U32 sel_type,
                          FMGR_FILTER filter, 
                          S8* base_path, 
                          PsExtFuncPtr callback)
{
#if !defined(__COSMOS_MMI__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmgr_adp_select_path_struct *adp_ctxt;
    mmi_id cui_grp, adp_grp;
    U16 icon_id;
    U32 option_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    adp_ctxt = OslMalloc(sizeof(fmgr_adp_select_path_struct));
    memset(adp_ctxt, 0, sizeof(*adp_ctxt));
    adp_ctxt->callback = callback;
    adp_ctxt->app_id = app_id;
    adp_ctxt->flag = sel_type;
    adp_ctxt->type = FMGR_ADP_TYPE_SEL_PATH;
    adp_grp = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, fmgr_adp_select_path_proc, (void*)adp_ctxt);
    mmi_frm_group_enter(adp_grp, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    fmgr_add_adp(adp_grp);
    adp_ctxt->adp_grp = adp_grp;
        
    if((sel_type & FMGR_SELECT_FOLDER) && !(sel_type & FMGR_SELECT_FILE))
    {
        option_flag = 0;
        if(sel_type & FMGR_FLAG_FIXED_PATH)
            option_flag |= CUI_FOLDER_SELECTOR_OPT_FIXED_PATH_ON;
        
        cui_grp = cui_folder_selector_create(adp_grp, (WCHAR*)base_path, CUI_FOLDER_SELECTOR_STYLE_WRITE, option_flag);
        if(!cui_grp)
        {
            FMGR_DisplayPopup(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE);
            mmi_frm_group_close(adp_grp);
            return 0;
        }
        adp_ctxt->cui_grp = cui_grp;
        
        mmi_fmgr_get_app_title_info(app_id, NULL, &icon_id, base_path);
        cui_folder_selector_set_title(cui_grp, 0, icon_id);

        cui_folder_selector_run(cui_grp);
    }
    else
    {
        cui_file_selector_style_enum style;
    
        if(sel_type & FMGR_SELECT_FOLDER)
            style = CUI_FILE_SELECTOR_STYLE_FILE_AND_PATH;
        else
            style = CUI_FILE_SELECTOR_STYLE_FILE_ONLY;

        option_flag = 0;
        /* Audio preview */
        if(sel_type & FMGR_FLAG_PREVIEW_AUDIO)
            option_flag |= CUI_FILE_SELECTOR_OPT_AUDIO_PREVIEW_ON;

        /* DRM check */
        if(sel_type & FMGR_FLAG_CHECK_SENDABLE)
            option_flag |= CUI_FILE_SELECTOR_OPT_DRM_CHECK_SEND_ON;
        if(sel_type & FMGR_FLAG_CHECK_USABLE)
            option_flag |= CUI_FILE_SELECTOR_OPT_DRM_CHECK_SET_ON;

        /* Archive / DRM2 multipart */
        if(sel_type & FMGR_SELECT_ARCHIVE)
            option_flag |= CUI_FILE_SELECTOR_OPT_ARCHIVE_AS_FILE;
        else if(sel_type & FMGR_SELECT_ARCHIVE_WITH_SINGLE_OBJECT)
            option_flag |= CUI_FILE_SELECTOR_OPT_ARCHIVE_AS_UNKNOWN;
        else
            option_flag |= CUI_FILE_SELECTOR_OPT_ARCHIVE_AS_FOLDER;

        /* fixed path */
        if(sel_type & FMGR_FLAG_FIXED_PATH)
            option_flag |= CUI_FILE_SELECTOR_OPT_FIXED_PATH_ON;
        
        cui_grp = cui_file_selector_create(adp_grp, (WCHAR*)base_path, &filter, style, option_flag);
        if(!cui_grp)
        {
            FMGR_DisplayPopup(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE);
            mmi_frm_group_close(adp_grp);
            return 0;
        }
        adp_ctxt->cui_grp = cui_grp;
        
        mmi_fmgr_get_app_title_info(app_id, NULL, &icon_id, base_path);
        cui_file_selector_set_title(cui_grp, 0, icon_id);

        cui_file_selector_run(cui_grp);
    }
    
    if(mmi_frm_group_get_active_id() == cui_grp &&
        mmi_frm_scrn_get_active_id() != cui_grp)
    {
        /* there is error */
        return 0;
    }
	return adp_grp;
#else
	return GRP_ID_INVALID;
#endif /* __COSMOS_MMI__ */
    
}

void mmi_fmgr_close_select_path(void)
{
#if !defined(__COSMOS_MMI__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id grp_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_adp_select_path)
    {
        g_adp_select_path->flag &= ~FMGR_SELECT_REPEAT;
    }
    else
    {
        grp_id = fmgr_find_first_adp(FMGR_ADP_TYPE_SEL_PATH);
        if(grp_id)
            mmi_frm_group_close(grp_id);
    }
#endif    
}

#define ADP_BROWSE_PATH

static fmgr_adp_browse_path_struct *g_adp_cui_browser;

static mmi_ret fmgr_adp_browse_path_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fmgr_adp_browse_path_struct *adp_ctxt;
    FuncPtr quit_cb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    adp_ctxt = (fmgr_adp_browse_path_struct*)evt->user_data;
    
    switch(evt->evt_id)
    {
    case EVT_ID_GROUP_DEINIT:
        fmgr_remove_adp(adp_ctxt->adp_grp);
        ASSERT(g_adp_cui_browser == adp_ctxt);
        OslMfree(adp_ctxt);
        g_adp_cui_browser = NULL;
        break;

    case EVT_ID_CUI_FOLDER_BROWSER_ON_ENTRY:
        if(adp_ctxt->setting.entry_callback)
            adp_ctxt->setting.entry_callback();
        break;

    case EVT_ID_CUI_FOLDER_BROWSER_ON_EXIT:
        break;

    case EVT_ID_CUI_FOLDER_BROWSER_ON_QUIT:
        /* following tricky code is for backward compatible */
        if(!(mmi_frm_group_get_state(adp_ctxt->adp_grp) & MMI_SCENARIO_STATE_ACTIVE))
        {
            mmi_frm_group_close(adp_ctxt->adp_grp);
            break;
        }
        
        quit_cb = adp_ctxt->setting.quit_callback;       

        mmi_frm_group_close(adp_ctxt->adp_grp);
        
        if(quit_cb)
            quit_cb();
        
        if(GetActiveScreenId() == SCR_ID_DUMMY)
            GoBackHistory();
        break;

    case EVT_ID_CUI_FOLDER_BROWSER_ON_EMPTY:
        if(adp_ctxt->setting.empty_lsk_string_id &&
            adp_ctxt->setting.empty_lsk_hdlr)
        {
            adp_ctxt->setting.empty_lsk_hdlr();
        }
        break;

    case EVT_ID_CUI_FOLDER_BROWSER_ON_MENU:
        break;
    }
    return MMI_RET_OK;
}

static cui_fmgr_ui_style_enum fmgr_adp_style_convert(fmgr_display_type_enum type)
{
    switch(type)
    {
    default:
    case FMGR_DISPLAY_TYPE_ICON_LIST:       return CUI_FMGR_UI_STYLE_ICON_LIST;
    case FMGR_DISPLAY_TYPE_BANNER_LIST:     return CUI_FMGR_UI_STYLE_BANNER_LIST;
    case FMGR_DISPLAY_TYPE_MATRIX:          return CUI_FMGR_UI_STYLE_MATRIX;
    case FMGR_DISPLAY_TYPE_SIMPLE_LIST:     return CUI_FMGR_UI_STYLE_SIMPLE_LIST;
    }
}

U32 mmi_fmgr_browse_path(U16 app_id, 
                          U32 browse_flag, 
                          FMGR_FILTER filter, 
                          S8 *base_path, 
                          mmi_fmgr_browse_setting_struct* set_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmgr_browse_setting_struct def_setting;
    fmgr_adp_browse_path_struct *adp_ctxt;
    mmi_id cui_grp, adp_grp;
    U16 icon_id, string_id;
    U32 option_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(g_adp_cui_browser)
    {
        ASSERT(0);
        return 0;
    }

    if(!set_data)
    {
        mmi_fmgr_browse_init_setting(&def_setting);
        set_data = &def_setting;
    }

    adp_ctxt = OslMalloc(sizeof(fmgr_adp_browse_path_struct));
    memset(adp_ctxt, 0, sizeof(*adp_ctxt));
    g_adp_cui_browser = adp_ctxt;
    
    adp_ctxt->app_id = app_id;
    adp_ctxt->flag = browse_flag;
    adp_ctxt->setting = *set_data;
    adp_ctxt->type = FMGR_ADP_TYPE_BROWSE;
    
    adp_grp = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, fmgr_adp_browse_path_proc, (void*)adp_ctxt);
    mmi_frm_group_enter(adp_grp, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    fmgr_add_adp(adp_grp);
    adp_ctxt->adp_grp = adp_grp;
        
    option_flag = 0;
#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if defined(__FMGR_CSK_FORWARD__)
    if(browse_flag & FMGR_FLAG_FAST_FORWARD_CSK)
        option_flag |= CUI_FOLDER_BROWSER_OPT_FAST_FORWARD_ON;
#endif

    cui_grp = cui_folder_browser_create(adp_grp, (WCHAR*)base_path, &filter, option_flag, 
                set_data->option_menu_id, set_data->empty_opt_menu_id);
    if(!cui_grp)
    {
        FMGR_DisplayPopup(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE);
        mmi_frm_group_close(adp_grp);
        return 0;
    }
    adp_ctxt->cui_grp = cui_grp;
    
    mmi_fmgr_get_app_title_info(app_id, &string_id, &icon_id, base_path);
    cui_folder_browser_set_title(cui_grp, string_id, icon_id);

    if(set_data->empty_lsk_string_id)
        cui_folder_browser_set_empty_lsk(cui_grp, set_data->empty_lsk_string_id, 0);

    cui_folder_browser_set_ui_style(cui_grp, fmgr_adp_style_convert((fmgr_display_type_enum)set_data->display_type));

#ifdef __FMGR_FTE_TOOLBAR_SUPPORT__
    cui_folder_browser_set_toolbar(cui_grp, set_data->tb_btn_menus, set_data->tb_btn_res, set_data->tb_btn_count);
#endif

    cui_folder_browser_run(cui_grp);
    
    return adp_grp;
}
#endif

void mmi_fmgr_browse_init_setting(mmi_fmgr_browse_setting_struct* setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(setting, 0, sizeof(mmi_fmgr_browse_setting_struct));
    setting->display_type = FMGR_DISPLAY_TYPE_BANNER_LIST;
}

#if !defined(__MMI_ULTRA_SLIM_FILE_MANAGER__) && defined(__MMI_FRM_HISTORY__)
void mmi_fmgr_browse_change_display_type(U16 app_id, fmgr_display_type_enum new_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_adp_cui_browser)
        cui_folder_browser_set_ui_style(g_adp_cui_browser->cui_grp, fmgr_adp_style_convert(new_type));
}

void mmi_fmgr_browse_change_filepath(U16 app_id, S8 *base_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_adp_cui_browser)
        cui_folder_browser_set_folder_path(g_adp_cui_browser->cui_grp, (WCHAR*)base_path);
}

S32 mmi_fmgr_browse_get_current_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_adp_cui_browser)
        return cui_folder_browser_get_highlight_index(g_adp_cui_browser->cui_grp);
    return -1;
}

void mmi_fmgr_browse_set_current_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_adp_cui_browser)
        cui_folder_browser_set_highlight_index(g_adp_cui_browser->cui_grp, index);
}

#if 0
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif /* __MMI_ULTRA_SLIM_FILE_MANAGER__ */

#ifdef __FMGR_FILE_OPTION_CUI__
#define ADP_DA_OPTION

static mmi_id g_adp_cui_da_id = 0;

static mmi_ret fmgr_adp_da_file_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    switch(evt->evt_id)
    {
    case EVT_ID_CUI_FILE_OPTION_ON_QUIT:
        mmi_frm_group_close(((cui_file_option_on_quit_event_struct*)evt)->sender_id);
        g_adp_cui_da_id = 0;
        break;
    }
    return MMI_RET_OK;
}

void mmi_fmgr_receive_da_file(S32 session_id, 
                              S32 mime_type, 
                              S32 mime_subtype, 
                              S32 action, 
                              U16 *file_path, 
                              S8  *url, 
                              S8  *mime_type_string)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id cui_grp;
    U16 icon_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(g_adp_cui_da_id)
    {
        mmi_frm_group_close(g_adp_cui_da_id);
        g_adp_cui_da_id = 0;
    }

    /* create a adapter group */
    g_adp_cui_da_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, fmgr_adp_da_file_proc, NULL);
    mmi_frm_group_enter(g_adp_cui_da_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_grp = cui_file_option_create(g_adp_cui_da_id, file_path, 
        CUI_FILE_OPTION_OPT_FUNC_MAIN | CUI_FILE_OPTION_OPT_FUNC_SEND | CUI_FILE_OPTION_OPT_FUNC_SET);
    if(!cui_grp)
    {
        FMGR_DisplayPopup(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE);
        mmi_frm_group_close(g_adp_cui_da_id);
    }

    mmi_fmgr_get_app_title_info(APP_DOWNLOADAGENT, NULL, &icon_id, NULL);
    cui_file_option_set_title(cui_grp, 0, icon_id);
    cui_file_option_set_app(cui_grp, APP_DOWNLOADAGENT);

    cui_file_option_run(cui_grp);
    
}

void mmi_fmgr_close_da_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_adp_cui_da_id)
    {
        mmi_frm_group_close(g_adp_cui_da_id);
        g_adp_cui_da_id = 0;
    }
}
#endif
#endif  /*  (__MMI_FILE_MANAGER__) */

