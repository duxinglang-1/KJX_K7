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
 *  FileMgrSrvTypes.c
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
#define _FMGR_GPROT_H_

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
// by RHR //#include "MMI_include.h"

#include "FileMgrSrvGProt.h"
#include "FileMgrSrvIProt.h"
#include "FileMgrSrvProt.h"

#ifdef __DRM_SUPPORT__
#include "drm_def.h"
#include "drm_errcode.h"
// by RHR //#include "drm_gprot.h"
#include "..\\..\\MtkApp\\RightsMgr\\RightsMgrInc\\RightsMgrGProt.h"   /* for mmi_rmgr_query_icon() */
#endif

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"

#include "fs_errcode.h"

#include "fmt_trc.h"

#include "MMIDataType.h"
#include "mmi_rp_file_type_def.h"
#include "wgui_categories_list.h"
#include "Unicodexdcl.h"
#include "CustMenuRes.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalConstants.h"
#include "gui_typedef.h"
#include "wgui_categories_util.h"

/****************************************************************************
* Define
*****************************************************************************/

/* ==== Copy from "mmi_rp_file_type_table.c" Begin ==== */
typedef struct {
    U16            file_type;
    const char     *extension;
    const WCHAR    *extension_ucs2;
} filetypes_extension_struct;

typedef struct {
    U16            file_type;
    mmi_img_id     small_icon;
    mmi_img_id     large_icon;
} filetypes_icons_struct;

typedef struct {
    U16            file_type;
    mmi_menu_id    option;
    mmi_menu_id    send_option;
    mmi_menu_id    use_option;
} filetypes_option_struct;

typedef struct {
    U16            group_type;
    U16            begin_id;
    U16            end_id;
} filetypes_group_range_struct;

typedef void (*filetypes_option_enabler_func_ptr)(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo);
typedef void (*filetypes_option_handler_func_ptr)(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo);
typedef void (*filetypes_option_hint_func_ptr)(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo, WCHAR* hint_buffer, S32 hint_buffer_size);

typedef struct {
    mmi_menu_id    option;
    filetypes_option_handler_func_ptr handler;
    filetypes_option_enabler_func_ptr enabler;
} filetypes_opt_hdlr_struct;

typedef struct {
    mmi_menu_id    option;
    filetypes_option_hint_func_ptr hint_hdlr;
} filetypes_opt_hint_struct;

/* ==== Copy from "mmi_rp_file_type_table.c" End ==== */

enum {
    SRV_FMGRI_OPTION_RES_NORMAL,
    SRV_FMGRI_OPTION_RES_SEND,
    SRV_FMGRI_OPTION_RES_USE
};

typedef struct {
    const WCHAR *current_filepath;
    const srv_fmgr_fileinfo_struct *current_fileinfo;
} srv_fmgr_types_context_struct;

/****************************************************************************
* Global Variable
*****************************************************************************/

extern const filetypes_extension_struct     g_filetypes_extension_table[];
extern const filetypes_icons_struct         g_filetypes_icons_table[];
extern const filetypes_option_struct        g_filetypes_option_table[];
extern const filetypes_group_range_struct   g_filetypes_group_range_table[];
extern const filetypes_opt_hdlr_struct      g_filetypes_opt_hdlr_table[];
extern const filetypes_opt_hint_struct      g_filetypes_opt_hint_table[];

extern const S32    g_filetypes_extension_table_size;
extern const S32    g_filetypes_icons_table_size;
extern const S32    g_filetypes_option_table_size;
extern const S32    g_filetypes_group_range_table_size;
extern const S32    g_filetypes_opt_hdlr_table_size;
extern const S32    g_filetypes_opt_hint_table_size;

/****************************************************************************
* Static Variable
*****************************************************************************/

static srv_fmgr_types_context_struct g_srv_fmgr_types_context;

static srv_fmgr_option_handler_funcptr g_srv_fmgr_option_handler = NULL;
static srv_fmgr_option_handler_funcptr g_srv_fmgr_option_enabler = NULL;

/****************************************************************************
* Function Forward Declaration
*****************************************************************************/

static const filetypes_option_struct *srv_fmgri_types_get_option_ptr(filetypes_file_type_enum type);
static S32 srv_fmgri_types_get_option_menu(filetypes_file_type_enum type, const WCHAR* path, S8 type_of_menu);

static mmi_img_id srv_fmgri_types_get_drm_icon(const WCHAR* path, srv_fmgr_types_icon_enum icon_type);

static filetypes_option_handler_func_ptr srv_fmgri_types_option_get_handler(mmi_menu_id opt_id);
static filetypes_option_enabler_func_ptr srv_fmgri_types_option_get_enabler(mmi_menu_id opt_id);

static void srv_fmgri_types_option_reset(mmi_menu_id parent_menu_id);
static S32  srv_fmgri_types_option_prepare(mmi_menu_id parent_opt_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo);

static void srv_fmgri_types_set_current_file(const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo);
static void srv_fmgri_types_reset_current_file(void);

static U32  srv_fmgri_types_menu_to_bitmask(S32 menu_id);

#define END_OF_FUNCTION_DECLARATION
/****************************************************************************
* Function Body
*****************************************************************************/

void srv_fmgr_set_option_handler(srv_fmgr_option_handler_funcptr handler, srv_fmgr_option_handler_funcptr enabler)
{
    g_srv_fmgr_option_handler = handler;
    g_srv_fmgr_option_enabler = enabler;
}

filetypes_file_type_enum srv_fmgr_types_find_type_by_filename_str(const WCHAR* filename_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_fmgr_types_find_type_by_extension_str(srv_fmgr_path_get_extension_const_ptr(filename_str));
}

filetypes_file_type_enum srv_fmgr_types_find_type_by_extension_str(const WCHAR* extension_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!extension_str)
        return FMGR_TYPE_UNKNOWN;
    
    for(i=0;i<g_filetypes_extension_table_size;i++)
    {
        if(mmi_wcsicmp(extension_str, g_filetypes_extension_table[i].extension_ucs2) == 0)
            return (filetypes_file_type_enum)(g_filetypes_extension_table[i].file_type);
    }
    return FMGR_TYPE_UNKNOWN;
}

S32 srv_fmgr_types_find_type_by_filepath(const WCHAR* filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: check DRM 2.0
    return srv_fmgr_types_find_type_by_filename_str(filepath);
}

filetypes_group_type_enum srv_fmgr_types_find_group_by_type(filetypes_file_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(type == FMGR_TYPE_UNKNOWN)
        return FMGR_GROUP_UNKNOWN;
    
    for(i=0;i<g_filetypes_group_range_table_size;i++)
    {
        if(type >= g_filetypes_group_range_table[i].begin_id && type <= g_filetypes_group_range_table[i].end_id)
            return (filetypes_group_type_enum)(g_filetypes_group_range_table[i].group_type);
    }
    return FMGR_GROUP_UNKNOWN;
}

filetypes_group_type_enum srv_fmgr_types_find_group_by_filename_str(const WCHAR* filename_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_fmgr_types_find_group_by_type(srv_fmgr_types_find_type_by_filename_str(filename_str));
}

filetypes_file_type_enum srv_fmgr_types_get_main_type(const FMGR_FILTER *filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    filetypes_file_type_enum type;
    S32                     type_count, i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* search from head, Treat DRM_ODF a special case */
    type = FMGR_TYPE_UNKNOWN;
    type_count = 0;
    for(i=FMGR_TYPE_UNKNOWN+1; i<FMGR_TYPE_COUNT; i++)
    {
        if(FMGR_FILTER_IS_SET(filter, i))
        {
#ifdef __DRM_V02__
            if(i != FMGR_TYPE_ODF)
#endif
                type = (filetypes_file_type_enum)i;
            type_count++;
        }
    }

#ifdef __DRM_V02__
    FMGR_ASSERT(type_count <= 2);
    if(type == FMGR_TYPE_UNKNOWN && type_count > 0)
        type = FMGR_TYPE_ODF;
#else
    FMGR_ASSERT(type_count <= 1);
#endif
    
    return type;
}

const CHAR* srv_fmgr_types_get_extension(filetypes_file_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, low, high;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    low = 0;
    high = g_filetypes_extension_table_size;

    do {
        i = (low+high)/2;

        if(type == g_filetypes_extension_table[i].file_type)
        {
            return g_filetypes_extension_table[i].extension;
        }
        else if(type > g_filetypes_extension_table[i].file_type)
        {
            low = i+1;
        }
        else
        {
            high = i;
        }
    } while(low != high);

    return "";
}

const WCHAR* srv_fmgr_types_get_extension_ucs2(filetypes_file_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: binary search is possible
    for(i=0;i<g_filetypes_extension_table_size;i++)
    {
        if(type == g_filetypes_extension_table[i].file_type)
            return g_filetypes_extension_table[i].extension_ucs2;
    }
    return L"";
}

mmi_img_id srv_fmgr_types_get_icon(filetypes_file_type_enum type, const WCHAR* path, srv_fmgr_types_icon_enum icon_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_fileinfo_struct fileinfo;
    S32 i;
    mmi_img_id ret_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ret_id = 0;
    do {
        ret_id = srv_fmgri_types_get_drm_icon(path, icon_type);
        if(ret_id)
            break;

        if(path)
        {
            if(srv_fmgr_fs_path_get_fileinfo(path, &fileinfo) >= 0)
            {
                if(fileinfo.type != FMGR_TYPE_UNKNOWN)
                    type = (filetypes_file_type_enum)fileinfo.type;
            }
        }

        for(i=0;i<g_filetypes_icons_table_size;i++)
        {
            if(type == g_filetypes_icons_table[i].file_type)
            {
                if(icon_type == SRV_FMGR_TYPES_ICON_SMALL)
                    ret_id = g_filetypes_icons_table[i].small_icon;
                else if(icon_type == SRV_FMGR_TYPES_ICON_LARGE)
                    ret_id = g_filetypes_icons_table[i].large_icon;
                break;
            }
        }

        if(!ret_id && type < FMGR_TYPE_COUNT)
        {
            /* Use group */
            ret_id = srv_fmgr_types_get_icon((filetypes_file_type_enum)srv_fmgr_types_find_group_by_type(type), NULL, icon_type);
        }

        if(!ret_id)
            ret_id = srv_fmgr_types_get_icon(FMGR_TYPE_UNKNOWN, NULL, icon_type);

    } while(0);   
    return ret_id;
}

S32 srv_fmgr_types_get_option_menu(filetypes_file_type_enum type, const WCHAR* path, S32 option_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* prepare option accoring to option_flag */

    FMGR_TRACE1(TGL1, TRC_SRV_FMGR_8DF584A55D2C48F9B589E3B697514A64, "[SRV_FMGR] > Types > get_option(%d)", type);

    // TODO: check option_flag
    ret = srv_fmgri_types_get_option_menu(type, path, SRV_FMGRI_OPTION_RES_NORMAL);
    FMGR_TRACE2(TGL1, TRC_SRV_FMGR_EB5188B26D824BC3A2E32CE4059AA73D, "[SRV_FMGR] > Types > return: %d, %x", ret, srv_fmgri_types_menu_to_bitmask(ret));
    return ret;
}

S32 srv_fmgr_types_get_send_option_menu(filetypes_file_type_enum type, const WCHAR* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_TRACE1(TGL1, TRC_SRV_FMGR_088D970CFF6742F5B60E0281C4CB6918, "[SRV_FMGR] > Types > get_send_option(%d)", type);
    
    ret = srv_fmgri_types_get_option_menu(type, path, SRV_FMGRI_OPTION_RES_SEND);
    FMGR_TRACE2(TGL1, TRC_SRV_FMGR_EB5188B26D824BC3A2E32CE4059AA73D, "[SRV_FMGR] > Types > return: %d, %x", ret, srv_fmgri_types_menu_to_bitmask(ret));
    return ret;
}

S32 srv_fmgr_types_get_use_option_menu(filetypes_file_type_enum type, const WCHAR* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_TRACE1(TGL1, TRC_SRV_FMGR_F40D5469C80440BEA54376C58C0EA507, "[SRV_FMGR] > Types > get_use_option(%d)", type);
    
    ret = srv_fmgri_types_get_option_menu(type, path, SRV_FMGRI_OPTION_RES_USE);
    FMGR_TRACE2(TGL1, TRC_SRV_FMGR_EB5188B26D824BC3A2E32CE4059AA73D, "[SRV_FMGR] > Types > return: %d, %x", ret, srv_fmgri_types_menu_to_bitmask(ret));
    return ret;
}

S32 srv_fmgr_types_launch_option(const WCHAR* path, mmi_menu_id option)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    filetypes_option_handler_func_ptr   handler;
    srv_fmgr_fileinfo_struct            fileinfo;
    S32                                 fs_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do {
        if(!path)
        {
            fs_ret = FS_PARAM_ERROR;
            break;
        }

        fs_ret = srv_fmgr_fs_path_get_fileinfo(path, &fileinfo);
        if(fs_ret < 0)
            break;

        fs_ret = 0;
        handler = srv_fmgri_types_option_get_handler(option);
        if(handler)
        {
            handler(option, path, &fileinfo);
            fs_ret = 1;
        }
        else if(g_srv_fmgr_option_handler)
        {
            srv_fmgri_types_set_current_file(path, &fileinfo);
            g_srv_fmgr_option_handler(option, path, &fileinfo);
            srv_fmgri_types_reset_current_file();
            fs_ret = 1;
        }
    } while(0);

    FMGR_TRACE2(TGL1, TRC_SRV_FMGR_0C062C5CA5C9470694752C5F77240F91, "[SRV_FMGR] > Types > launch(%d): %x", option, fs_ret);
    
    return fs_ret;
}

void srv_fmgr_types_filter_set_group(FMGR_FILTER *filter, filetypes_group_type_enum group)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i=0;i<g_filetypes_group_range_table_size;i++)
    {
        if(g_filetypes_group_range_table[i].group_type == group)
        {
            for(j = g_filetypes_group_range_table[i].begin_id;
                j <= g_filetypes_group_range_table[i].end_id;
                j++)
            {
                FMGR_FILTER_SET(filter, j);
            }
            break;
        }
    }
    
}

MMI_BOOL srv_fmgr_types_filter_is_in_group(const FMGR_FILTER *filter, filetypes_group_type_enum group)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i=0;i<g_filetypes_group_range_table_size;i++)
    {
        if(g_filetypes_group_range_table[i].group_type == group)
        {
            for(j = g_filetypes_group_range_table[i].begin_id;
                j <= g_filetypes_group_range_table[i].end_id;
                j++)
            {
                if(FMGR_FILTER_IS_SET(filter, j))
                    return MMI_TRUE;
            }
            break;
        }
    }
    return MMI_FALSE;
}

const WCHAR* srv_fmgr_types_query_fileinfo(srv_fmgr_fileinfo_struct* info)
{
    if(info && g_srv_fmgr_types_context.current_fileinfo)
        *info = *g_srv_fmgr_types_context.current_fileinfo;

    return g_srv_fmgr_types_context.current_filepath;
}

void srv_fmgr_prepare_option_menu(mmi_menu_id option_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo)
{
    srv_fmgri_types_option_prepare(option_id, filepath, fileinfo);
}

#define LOCAL_FUNCTION

static const filetypes_option_struct *srv_fmgri_types_get_option_ptr(filetypes_file_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i=0;i<g_filetypes_option_table_size;i++)
    {
        if(type == g_filetypes_option_table[i].file_type)
        {
            return &g_filetypes_option_table[i];
        }
    }
    return NULL;

}

static mmi_img_id srv_fmgri_types_get_drm_icon(const WCHAR* path, srv_fmgr_types_icon_enum icon_type)
{
#ifdef __DRM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    filetypes_file_type_enum    type;
    filetypes_group_type_enum   group;
    mmi_img_id                  image_id;
    U8                          perm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(!path || icon_type != SRV_FMGR_TYPES_ICON_SMALL)
        return 0;

    perm = 0;
    image_id = 0;

    type = srv_fmgr_types_find_type_by_filename_str(path);
    group = srv_fmgr_types_find_group_by_type(type);
    
    if (group == FMGR_GROUP_VIDEO || group == FMGR_GROUP_AUDIO)
    {
        perm = DRM_PERMISSION_PLAY;
    }
    else if (group == FMGR_GROUP_IMAGE)
    {
        perm = DRM_PERMISSION_DISPLAY;
    }
#ifdef __J2ME__
    else if (type == FMGR_TYPE_JAD ||
             type == FMGR_TYPE_JAR)
    {
        perm = DRM_PERMISSION_EXECUTE;
    }
#endif

    mmi_rmgr_query_icon((WCHAR*)path, perm, &image_id);

    return image_id;
#else
    return 0;
#endif /* __DRM_SUPPORT__ */
}

static void srv_fmgri_types_option_reset(mmi_menu_id parent_menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 num_of_child;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* unhide all menu under the parent */
    num_of_child = GetNumOfChild(parent_menu_id);
    if(!num_of_child)
        return;

    while(num_of_child)
    {
        mmi_frm_unhide_menu_item(GetSeqItemId(parent_menu_id, (U16)(num_of_child-1)));
        num_of_child--;
    }
}

static filetypes_option_enabler_func_ptr srv_fmgri_types_option_get_enabler(mmi_menu_id opt_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i=0;i<g_filetypes_opt_hdlr_table_size;i++)
    {
        if(g_filetypes_opt_hdlr_table[i].option == opt_id)
            return g_filetypes_opt_hdlr_table[i].enabler;
    }
    return NULL;
}

static filetypes_option_handler_func_ptr srv_fmgri_types_option_get_handler(mmi_menu_id opt_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i=0;i<g_filetypes_opt_hdlr_table_size;i++)
    {
        if(g_filetypes_opt_hdlr_table[i].option == opt_id)
            return g_filetypes_opt_hdlr_table[i].handler;
    }
    return NULL;
}

static S32 srv_fmgri_types_option_prepare(mmi_menu_id parent_opt_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32         num_of_child;
    mmi_menu_id child_opt_id;
    filetypes_option_enabler_func_ptr   enabler;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* unhide all menuitem */
    srv_fmgri_types_option_reset(parent_opt_id);
    
    /* check enabler of parent*/
    enabler = srv_fmgri_types_option_get_enabler(parent_opt_id);
    if(enabler)
        enabler(parent_opt_id, filepath, fileinfo);
    else if(g_srv_fmgr_option_enabler)
        g_srv_fmgr_option_enabler(parent_opt_id, filepath, fileinfo);

    FMGR_TRACE3(TGL2, TRC_SRV_FMGR_9FB5453EC67E48AEB74843AEF21945AB, 
        "[SRV_FMGR] > Types > enabler(%d): %x,%x", parent_opt_id, enabler, srv_fmgri_types_menu_to_bitmask(parent_opt_id));

    /* check enabler of all child */
    num_of_child = GetNumOfChild(parent_opt_id);
    while(num_of_child)
    {
        child_opt_id = GetSeqItemId(parent_opt_id, (U16)(num_of_child-1));
        if(!mmi_frm_test_menu_item_hide(child_opt_id))
        {
            enabler = srv_fmgri_types_option_get_enabler(child_opt_id);
            if(enabler)
                enabler(child_opt_id, filepath, fileinfo);
            else if(g_srv_fmgr_option_enabler)
                g_srv_fmgr_option_enabler(child_opt_id, filepath, fileinfo);

            FMGR_TRACE3(TGL2, TRC_SRV_FMGR_9FB5453EC67E48AEB74843AEF21945AB, 
                "[SRV_FMGR] > Types > enabler(%d): %x,%x", child_opt_id, enabler, srv_fmgri_types_menu_to_bitmask(parent_opt_id));
        }
        num_of_child--;
    }

    /* if there is still any available */        
    return GetNumOfChild_Ext(parent_opt_id);
}

static S32 srv_fmgri_types_get_option_menu(filetypes_file_type_enum type, const WCHAR* path, S8 type_of_menu)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32                             fs_ret;
    const filetypes_option_struct   *opt_ptr;
    srv_fmgr_fileinfo_struct        fileinfo;
    mmi_menu_id                     menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(path)
    {
        fs_ret = srv_fmgr_fs_path_get_fileinfo(path, &fileinfo);
        if(fs_ret < 0)
            return fs_ret;
        
        if(fileinfo.type != FMGR_TYPE_UNKNOWN)
            type = (filetypes_file_type_enum)fileinfo.type;
    }
    
    opt_ptr = srv_fmgri_types_get_option_ptr(type);
    if(!opt_ptr)
        opt_ptr = srv_fmgri_types_get_option_ptr((filetypes_file_type_enum)srv_fmgr_types_find_group_by_type(type));
    if(!opt_ptr)
        opt_ptr = srv_fmgri_types_get_option_ptr(FMGR_TYPE_UNKNOWN);
    if(!opt_ptr)
        return FS_PARAM_ERROR;

    switch(type_of_menu)
    {
    case SRV_FMGRI_OPTION_RES_NORMAL:
        menu_id = opt_ptr->option;
        if(!menu_id)
        {
            opt_ptr = srv_fmgri_types_get_option_ptr((filetypes_file_type_enum)srv_fmgr_types_find_group_by_type(type));
            if(!opt_ptr || !opt_ptr->option)
                opt_ptr = srv_fmgri_types_get_option_ptr(FMGR_TYPE_UNKNOWN);
            if(!opt_ptr)
                return FS_PARAM_ERROR;
            menu_id = opt_ptr->option;
        }
        break;

    case SRV_FMGRI_OPTION_RES_SEND:
#ifdef __DRM_SUPPORT__
        if(path)
        {
            fs_ret = mmi_rmgr_check_forward((WCHAR*)path);
            if(fs_ret < 0)
                return fs_ret;
            if(!(fs_ret & MMI_RMGR_USAGE_SEND))
                return DRM_RESULT_NO_PERMISSION;
        }
#endif        
        menu_id = opt_ptr->send_option;
        if(!menu_id)
        {
            opt_ptr = srv_fmgri_types_get_option_ptr(FMGR_TYPE_UNKNOWN);
            if(!opt_ptr)
                return FS_PARAM_ERROR;
            menu_id = opt_ptr->send_option;
        }
        break;

    case SRV_FMGRI_OPTION_RES_USE:
#ifdef __DRM_SUPPORT__
        if(path)
        {
            fs_ret = mmi_rmgr_check_forward((WCHAR*)path);
            if(fs_ret < 0)
                return fs_ret;
            if(!(fs_ret & MMI_RMGR_USAGE_SET))
                return DRM_RESULT_NO_PERMISSION;
        }
#endif        
        menu_id = opt_ptr->use_option;
        break;

    default:
        return FS_PARAM_ERROR;
    }

    if(path)
    {
        if(!srv_fmgri_types_option_prepare(menu_id, path, &fileinfo))
            return 0;
    }
    else
    {
        srv_fmgri_types_option_reset(menu_id);
    }
    
    return menu_id;
}

static void srv_fmgri_types_set_current_file(const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo)
{
    g_srv_fmgr_types_context.current_filepath = filepath;
    g_srv_fmgr_types_context.current_fileinfo = fileinfo;
}

static void srv_fmgri_types_reset_current_file(void)
{
    g_srv_fmgr_types_context.current_fileinfo = NULL;
    g_srv_fmgr_types_context.current_filepath = NULL;
}

static U32  srv_fmgri_types_menu_to_bitmask(S32 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 bitmask;
    U16 count, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(menu_id <= 0)
        return 0;

    bitmask = 0;
    count = GetNumOfChild((U16)menu_id);
    if(count > 32)
        count = 32;
    for(i=0;i<count;i++)
    {
        if(!mmi_frm_test_menu_item_hide(GetSeqItemId((U16)menu_id, i)))
            bitmask |= (1<<i);
    }
    return bitmask;
}
