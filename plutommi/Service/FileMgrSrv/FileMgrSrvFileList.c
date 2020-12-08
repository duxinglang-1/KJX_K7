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
 *  FileMgrSrvFileList.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  File list part of Filemgr service
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

#include "FileMgrSrvProt.h"

#include "string.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"

#include "fs_errcode.h"

#include "fmt_trc.h"

#include "MMIDataType.h"
#include "mmi_rp_file_type_def.h"
#include "FileMgrSrvGProt.h"

/****************************************************************************
* Define
*****************************************************************************/


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

void srv_fmgr_filelist_destroy(SRV_FMGR_FILELIST_HANDLE hdl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_filelist_base_struct* obj = (srv_fmgr_filelist_base_struct*)hdl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!obj)
        return;
    FMGR_TRACE1(TGL1, TRC_SRV_FMGR_ED0E3490C6C9460A9DE51D848F881ADB, 
        "[SRV_FMGR] > FileList > destroy(%x)", obj->fl_if);
    obj->fl_if->release(obj);
}

srv_fmgr_filelist_state_enum srv_fmgr_filelist_get_state(SRV_FMGR_FILELIST_HANDLE hdl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_filelist_base_struct* obj = (srv_fmgr_filelist_base_struct*)hdl;
    srv_fmgr_filelist_state_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!obj)
        ret = SRV_FMGR_FILELIST_STATE_INIT;
    else
        ret = obj->fl_if->get_state(obj);
    FMGR_TRACE2(TGL1, TRC_SRV_FMGR_138C7AAE840040929B7F8360B9A29341, 
        "[SRV_FMGR] > FileList > get state(%x): %d", obj ? obj->fl_if : 0, ret);
    return ret;
}

S32 srv_fmgr_filelist_get_capability(SRV_FMGR_FILELIST_HANDLE hdl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_filelist_base_struct* obj = (srv_fmgr_filelist_base_struct*)hdl;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!obj)
        ret = 0;
    else
        ret = obj->fl_if->get_capability(obj);
    FMGR_TRACE2(TGL1, TRC_SRV_FMGR_1D505DC921DC42C4AF96CD44A2EF4DA2, 
        "[SRV_FMGR] > FileList > get cap(%x): %d", obj ? obj->fl_if : 0, ret);
    return ret;
}

U32 srv_fmgr_filelist_count(SRV_FMGR_FILELIST_HANDLE hdl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_filelist_base_struct* obj = (srv_fmgr_filelist_base_struct*)hdl;
    U32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!obj)
        ret = 0;
    else
        ret = obj->fl_if->count(obj);
    FMGR_TRACE2(TGL1, TRC_SRV_FMGR_0036FB40DE1B43D98280E13BB509B2EE, 
        "[SRV_FMGR] > FileList > count(%x): %d", obj ? obj->fl_if : 0, ret);
    return ret;
}

MMI_BOOL srv_fmgr_filelist_is_empty(SRV_FMGR_FILELIST_HANDLE hdl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_filelist_base_struct* obj = (srv_fmgr_filelist_base_struct*)hdl;
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!obj)
        ret = MMI_TRUE;
    else
        ret = obj->fl_if->is_empty(obj);
    FMGR_TRACE2(TGL1, TRC_SRV_FMGR_2CF93198C69645F7B7D6A5F32B09DEC3, 
        "[SRV_FMGR] > FileList > empty(%x): %d", obj ? obj->fl_if : 0, ret);
    return ret;
}

MMI_BOOL srv_fmgr_filelist_is_dirty(SRV_FMGR_FILELIST_HANDLE hdl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_filelist_base_struct* obj = (srv_fmgr_filelist_base_struct*)hdl;
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!obj)
        ret = MMI_FALSE;
    else
        ret = obj->fl_if->is_dirty(obj);
    FMGR_TRACE2(TGL1, TRC_SRV_FMGR_A25E5BBD0CA14ADCA2F09C2BE4CFF91C, 
        "[SRV_FMGR] > FileList > dirty(%x): %d", obj ? obj->fl_if : 0, ret);
    return ret;
}

S32 srv_fmgr_filelist_get_filepath(SRV_FMGR_FILELIST_HANDLE hdl, S32 index, WCHAR* buffer, S32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_filelist_base_struct* obj = (srv_fmgr_filelist_base_struct*)hdl;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!obj)
        ret = FS_PARAM_ERROR;
    else
        ret = obj->fl_if->get_filepath(obj, index, buffer, buffer_size);    
    if(ret < 0)
    {
        FMGR_TRACE3(TGL1, TRC_SRV_FMGR_F7B111608D684AB19CE3F5E0D0222306, 
            "[SRV_FMGR] > FileList > get path(%x,%d): %d", obj ? obj->fl_if : 0, index, ret);
    }
    FMGR_TRACE3(TGL2, TRC_SRV_FMGR_F7B111608D684AB19CE3F5E0D0222306, 
        "[SRV_FMGR] > FileList > get path(%x,%d): %d", obj ? obj->fl_if : 0, index, ret);
    return ret;
}

S32 srv_fmgr_filelist_get_filename(SRV_FMGR_FILELIST_HANDLE hdl, S32 index, WCHAR* buffer, S32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_filelist_base_struct* obj = (srv_fmgr_filelist_base_struct*)hdl;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!obj)
        ret = FS_PARAM_ERROR;
    else
        ret = obj->fl_if->get_filename(obj, index, buffer, buffer_size);
    if(ret < 0)
    {
        FMGR_TRACE3(TGL1, TRC_SRV_FMGR_E0A533DF9B824458A5FDF7E427748FA7, 
            "[SRV_FMGR] > FileList > get name(%x,%d): %d", obj ? obj->fl_if : 0, index, ret);
    }
    FMGR_TRACE3(TGL2, TRC_SRV_FMGR_E0A533DF9B824458A5FDF7E427748FA7, 
        "[SRV_FMGR] > FileList > get name(%x,%d): %d", obj ? obj->fl_if : 0, index, ret);
    return ret;
}

S32 srv_fmgr_filelist_get_fileinfo(SRV_FMGR_FILELIST_HANDLE hdl, S32 index, srv_fmgr_fileinfo_struct* fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_filelist_base_struct* obj = (srv_fmgr_filelist_base_struct*)hdl;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!obj)
        ret = FS_PARAM_ERROR;
    else
        ret = obj->fl_if->get_fileinfo(obj, index, fileinfo);
    if(ret < 0)
    {
        FMGR_TRACE3(TGL1, TRC_SRV_FMGR_40D537B1B89245FEACB0B9B4A74C00D0, 
            "[SRV_FMGR] > FileList > get info(%x,%d): %d", obj ? obj->fl_if : 0, index, ret);
    }
    FMGR_TRACE3(TGL2, TRC_SRV_FMGR_40D537B1B89245FEACB0B9B4A74C00D0, 
        "[SRV_FMGR] > FileList > get info(%x,%d): %d", obj ? obj->fl_if : 0, index, ret);
    return ret;
}

S32 srv_fmgr_filelist_load_file(SRV_FMGR_FILELIST_HANDLE hdl, S32 index,
                             mmi_proc_func user_proc, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_filelist_base_struct* obj = (srv_fmgr_filelist_base_struct*)hdl;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!obj)
        ret = FS_PARAM_ERROR;
    else
        ret = obj->fl_if->load_file(obj, index, user_proc, user_data);
    FMGR_TRACE3(TGL1, TRC_SRV_FMGR_2706B71300344777AE70627970B1796C, 
        "[SRV_FMGR] > FileList > load(%x,%d): %d", obj ? obj->fl_if : 0, index, ret);
    return ret;
}

S32 srv_fmgr_filelist_refresh(SRV_FMGR_FILELIST_HANDLE hdl, const WCHAR* pattern, S32 start_index, 
                              S32 flag, mmi_proc_func user_proc, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_filelist_base_struct* obj = (srv_fmgr_filelist_base_struct*)hdl;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!obj)
        ret = FS_PARAM_ERROR;
    else
        ret = obj->fl_if->refresh(obj, pattern, start_index, flag, user_proc, user_data);
    FMGR_TRACE2(TGL1, TRC_SRV_FMGR_B8E4A371EBFC4D28949CBF39F2BFDD68, 
        "[SRV_FMGR] > FileList > refresh(%x): %d", obj ? obj->fl_if : 0, ret);
    return ret;
}

S32 srv_fmgr_filelist_abort(SRV_FMGR_FILELIST_HANDLE hdl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_filelist_base_struct* obj = (srv_fmgr_filelist_base_struct*)hdl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!obj)
        return FS_PARAM_ERROR;
    return obj->fl_if->abort(obj);
    
    //FMGR_TRACE1(TGL1, TRC_SRV_FMGR_8714BFA125714EB68DDCFA512DC5451C, 
    //    "[SRV_FMGR] > FileList > get set(%x)", obj->fl_if);
}

void srv_fmgr_filelist_get_setting(SRV_FMGR_FILELIST_HANDLE hdl, FMGR_FILTER* filter, U32* sort_option)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_filelist_base_struct* obj = (srv_fmgr_filelist_base_struct*)hdl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!obj)
        return;
    obj->fl_if->get_setting(obj, filter, sort_option);
    FMGR_TRACE1(TGL1, TRC_SRV_FMGR_8714BFA125714EB68DDCFA512DC5451C, 
        "[SRV_FMGR] > FileList > get set(%x)", obj->fl_if);
}

void srv_fmgr_filelist_set_setting(SRV_FMGR_FILELIST_HANDLE hdl, const FMGR_FILTER* filter, U32 sort_option)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_filelist_base_struct* obj = (srv_fmgr_filelist_base_struct*)hdl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!obj)
        return;
    obj->fl_if->set_setting(obj, filter, sort_option);
    FMGR_TRACE1(TGL1, TRC_SRV_FMGR_5CEE23E9B95C4623A5C6F044048D1DA3, 
        "[SRV_FMGR] > FileList > set set(%x)", obj->fl_if);
}

#define EMPTY_LIST_IMPL

static void        srv_fmgri_efl_release(srv_fmgr_filelist_base_struct* obj);
static srv_fmgr_filelist_state_enum srv_fmgri_efl_get_state(srv_fmgr_filelist_base_struct* obj);
static S32          srv_fmgri_efl_get_capability(srv_fmgr_filelist_base_struct* obj);
static U32         srv_fmgri_efl_count(srv_fmgr_filelist_base_struct* obj);
static MMI_BOOL    srv_fmgri_efl_is_empty(srv_fmgr_filelist_base_struct* obj);
static MMI_BOOL    srv_fmgri_efl_is_dirty(srv_fmgr_filelist_base_struct* obj);
static S32         srv_fmgri_efl_get_filepath(srv_fmgr_filelist_base_struct* obj, S32 index, WCHAR* buffer, S32 buffer_size);
static S32         srv_fmgri_efl_get_filename(srv_fmgr_filelist_base_struct* obj, S32 index, WCHAR* buffer, S32 buffer_size);
static S32         srv_fmgri_efl_get_fileinfo(srv_fmgr_filelist_base_struct* obj, S32 index, srv_fmgr_fileinfo_struct* fileinfo);
static S32         srv_fmgri_efl_load_file(srv_fmgr_filelist_base_struct* obj, S32 index,
                             mmi_proc_func user_proc, void* user_data);
static S32         srv_fmgri_efl_refresh(srv_fmgr_filelist_base_struct* obj, const WCHAR* pattern, S32 start_index, 
                                         S32 flag, mmi_proc_func user_proc, void* user_data);
static S32         srv_fmgri_efl_abort(srv_fmgr_filelist_base_struct* obj);
static void        srv_fmgri_efl_get_setting(srv_fmgr_filelist_base_struct* obj, FMGR_FILTER* filter, U32* sort_option);
static void        srv_fmgri_efl_set_setting(srv_fmgr_filelist_base_struct* obj, const FMGR_FILTER* filter, U32 sort_option);

const static srv_fmgr_filelist_interface_struct g_srv_fmgri_efl_impl_table = 
{
    srv_fmgri_efl_release,
    srv_fmgri_efl_get_state,
    srv_fmgri_efl_get_capability,
    srv_fmgri_efl_count,
    srv_fmgri_efl_is_empty,
    srv_fmgri_efl_is_dirty,
    srv_fmgri_efl_get_filepath,
    srv_fmgri_efl_get_filename,
    srv_fmgri_efl_get_fileinfo,
    srv_fmgri_efl_load_file,
    srv_fmgri_efl_refresh,
    srv_fmgri_efl_abort,
    srv_fmgri_efl_get_setting,
    srv_fmgri_efl_set_setting
};

static srv_fmgr_filelist_base_struct g_frm_fmgri_efl_singleton;

S32 srv_fmgr_empty_filelist_create(SRV_FMGR_FILELIST_HANDLE* list_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!list_handle)
        return FS_PARAM_ERROR;
    g_frm_fmgri_efl_singleton.fl_if = &g_srv_fmgri_efl_impl_table;
    *list_handle = (SRV_FMGR_FILELIST_HANDLE)(&g_frm_fmgri_efl_singleton);
    return 0;
}

static void        srv_fmgri_efl_release(srv_fmgr_filelist_base_struct* obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_ASSERT(&g_frm_fmgri_efl_singleton == obj);
    // do nothing
}

static srv_fmgr_filelist_state_enum srv_fmgri_efl_get_state(srv_fmgr_filelist_base_struct* obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return SRV_FMGR_FILELIST_STATE_READY;
}

static S32          srv_fmgri_efl_get_capability(srv_fmgr_filelist_base_struct* obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return SRV_FMGR_FILELIST_CAP_RANDOM_ACCESS;
}

static U32         srv_fmgri_efl_count(srv_fmgr_filelist_base_struct* obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}

static MMI_BOOL    srv_fmgri_efl_is_empty(srv_fmgr_filelist_base_struct* obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
}

static MMI_BOOL    srv_fmgri_efl_is_dirty(srv_fmgr_filelist_base_struct* obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_FALSE;
}

static S32         srv_fmgri_efl_get_filepath(srv_fmgr_filelist_base_struct* obj, S32 index, WCHAR* buffer, S32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return FS_PARAM_ERROR;
}

static S32         srv_fmgri_efl_get_filename(srv_fmgr_filelist_base_struct* obj, S32 index, WCHAR* buffer, S32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return FS_PARAM_ERROR;
}

static S32         srv_fmgri_efl_get_fileinfo(srv_fmgr_filelist_base_struct* obj, S32 index, srv_fmgr_fileinfo_struct* fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return FS_PARAM_ERROR;
}

static S32         srv_fmgri_efl_load_file(srv_fmgr_filelist_base_struct* obj, S32 index,
                             mmi_proc_func user_proc, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return FS_PARAM_ERROR;
}

static S32         srv_fmgri_efl_refresh(srv_fmgr_filelist_base_struct* obj, const WCHAR* pattern, S32 start_index, 
                                         S32 flag, mmi_proc_func user_proc, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return FS_PARAM_ERROR;
}

static S32         srv_fmgri_efl_abort(srv_fmgr_filelist_base_struct* obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return FS_PARAM_ERROR;
}

static void        srv_fmgri_efl_get_setting(srv_fmgr_filelist_base_struct* obj, FMGR_FILTER* filter, U32* sort_option)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(filter)
        FMGR_FILTER_INIT(filter);
    if(sort_option)
        *sort_option = 0;
}

static void        srv_fmgri_efl_set_setting(srv_fmgr_filelist_base_struct* obj, const FMGR_FILTER* filter, U32 sort_option)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


