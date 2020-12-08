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
 *  Customized icon database
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  used by OMA DL, A downloaded file can have a special customized icon.
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

#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"

#include "fmt_trc.h"

#include "MMI_features.h"
#include "MMIDataType.h"
#include "FileMgrSrvGProt.h"
#include "mmi_rp_file_type_def.h"
#include "Unicodexdcl.h"
#include "app_datetime.h"


#if defined(SRV_FMGR_TESTBED_ENABLE)
#ifndef __MMI_FMGR_CUSTICON_SUPPORT__
#define __MMI_FMGR_CUSTICON_SUPPORT__
#endif
#endif

#if defined(__MMI_FMGR_CUSTICON_SUPPORT__)

/****************************************************************************
* Define
*****************************************************************************/

#define FMGR_CIDB_MAX_COUNT  20
#define FMGR_CIDB_DIR  L"@cidb"
#define FMGR_CIDB_FILE L"cidb"

typedef struct _srv_fmgr_cidb_entry_struct
{
    U32 object_hash;
    U32 time;

} srv_fmgr_cidb_entry_struct;

typedef struct _srv_fmgr_cidb_file_entry_struct
{
    WCHAR   object_path[SRV_FMGR_PATH_MAX_LEN+1];
    U32     time;

} srv_fmgr_cidb_file_entry_struct;

typedef struct
{
    U8                          cidb_drive;
    S8                          cidb_ready;
    S8                          cidb_count;
    
    srv_fmgr_cidb_entry_struct  cidb[FMGR_CIDB_MAX_COUNT];

} srv_fmgr_cidb_context_struct;

typedef S32 (*srv_fmgr_cidb_action_func)(S32 idx, const WCHAR* object_path, U32 data);

/****************************************************************************
* Global Variable
*****************************************************************************/


/****************************************************************************
* Static Variable
*****************************************************************************/
static srv_fmgr_cidb_context_struct g_srv_fmgr_cidb_ctxt;

/****************************************************************************
* Function Forward Declaration
*****************************************************************************/

static S32 srv_fmgr_cidb_find_empty_entry(const WCHAR* path);
static S32 srv_fmgr_cidb_find_entry(const WCHAR* object_path);
static S32 srv_fmgr_cidb_write_entry(S32 idx, const WCHAR* object_path, const WCHAR* icon_path);
static S32 srv_fmgr_cidb_clear_entry(S32 idx);
static S32 srv_fmgr_cidb_get_icon(S32 idx, WCHAR* icon_path, S32 path_len);
static S32 srv_fmgr_cidb_for_each_entry(WCHAR drive, srv_fmgr_cidb_action_func action, U32 data);

#define END_OF_FUNCTION_DECLARATION
/****************************************************************************
* Function Body
*****************************************************************************/

S32 srv_fmgr_custicon_do(srv_fmgr_custicon_op_enum op, const WCHAR* object_path, const WCHAR* para)
{
#ifdef __MMI_FMGR_CUSTICON_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    filetypes_file_type_enum ftype;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(op)
    {
    case SRV_FMGR_CUSTICON_OP_REGISTER:
        /* register a NULL icon equal to de-register */
        if(!para)
            goto de_register;

        /* check para */
        ftype = srv_fmgr_types_find_type_by_filename_str(para);
        if(!srv_fmgr_custicon_is_type_support(ftype))
        {
            result = SRV_FMGR_CUSTICON_RESULT_TYPE_NOT_SUPPORTED;
            break;
        }        

        /* find a empty slot / check if entry exist */
        result = srv_fmgr_cidb_find_entry(object_path);
        if(result == 0)
            result = srv_fmgr_cidb_find_empty_entry(object_path);
        if(result < 0)
            break;

        /* write data */
        result = srv_fmgr_cidb_write_entry(result, object_path, (WCHAR*)para);
        break;

    case SRV_FMGR_CUSTICON_OP_MOVE_OBJECT:
        if(!para)
        {
            result = SRV_FMGR_CUSTICON_RESULT_INVALID_PARAM;
            break;
        }        
        
        /* check if entry exist */
        result = srv_fmgr_cidb_find_entry(object_path);
        if(result < 0)
            break;

        if(result == 0)
        {
            result = SRV_FMGR_CUSTICON_RESULT_NO_ICON;
            break;
        }
        
        if(object_path[0] == para[0])
        {
            /* update the path in database / hash in memory */
            result = srv_fmgr_cidb_write_entry(result, (WCHAR*)para, NULL);
        }
        else
        {
            WCHAR* icon_path;
            /* different drive, we have to add the new_path first, then erase the old one */

            /* get icon */
            icon_path = srv_fmgri_alloc_path_buffer();
            srv_fmgr_cidb_get_icon(result, icon_path, SRV_FMGR_PATH_BUFFER_SIZE);

            /* add new entry */
            result = srv_fmgr_cidb_find_entry(para);
            if(result == 0)
                result = srv_fmgr_cidb_find_empty_entry(para);
            if(result < 0)
            {
                srv_fmgri_free_path_buffer(icon_path);
                break;
            }
            result = srv_fmgr_cidb_write_entry(result, (WCHAR*)para, icon_path);

            /* remove old one */
            result = srv_fmgr_cidb_find_entry(object_path);
            result = srv_fmgr_cidb_clear_entry(result);
        }        
        break;

de_register:
    case SRV_FMGR_CUSTICON_OP_DEREGISTER:
        /* check if entry exist */
        result = srv_fmgr_cidb_find_entry(object_path);
        if(result < 0)
            break;
        
        if(result == 0)
        {
            result = SRV_FMGR_CUSTICON_RESULT_NO_ICON;
            break;
        }
        
        /* remove entry */
        result = srv_fmgr_cidb_clear_entry(result);
        break;

    default:
        result = SRV_FMGR_CUSTICON_RESULT_OP_NOT_SUPPORTED;
        break;
    }

    FMGR_TRACE2(TGL1, TRC_SRV_FMGR_3979005438C7471FAE5C6681CF0970D8, 
        "[SRV_FMGR] > CustIcon > do(op=%d): %d", op, result);

    return result;
#else
    return -1;
#endif
}

MMI_BOOL srv_fmgr_custicon_is_type_support(filetypes_file_type_enum type)
{
#ifdef __MMI_FMGR_CUSTICON_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(type == FMGR_TYPE_JPEG || type == FMGR_TYPE_JPG)
        return MMI_TRUE;
    
    return MMI_FALSE;
#else
    return MMI_FALSE;
#endif
}

S32  srv_fmgr_custicon_query(const WCHAR* object_path, WCHAR* icon_path, S32 icon_path_size)
{
#ifdef __MMI_FMGR_CUSTICON_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    do {
        /* check if entry exist */
        result = srv_fmgr_cidb_find_entry(object_path);
        if(result < 0)
            break;
        
        if(result == 0)
        {
            result = SRV_FMGR_CUSTICON_RESULT_NO_ICON;
            break;
        }

        if(icon_path)
            result = srv_fmgr_cidb_get_icon(result, icon_path, icon_path_size);
        else
            result = 0;
        
    } while(0);
    
    FMGR_TRACE1(TGL1, TRC_SRV_FMGR_8B9F34B0CF544DB1B8610D9D405DE726, "[SRV_FMGR] > CustIcon > query(): %d", result);
    
    return result;
#else
    return -1;
#endif
}

#define LOCAL_FUNCTION

static U32 srv_fmgri_cidb_hash_func(const WCHAR* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const WCHAR* ptr;
    U32 key, value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = path;
    key = 5381;
    while (*ptr)
    {
        value = (*ptr);
        key = ((key << 5) + key) ^ value; 
        ptr++;
    }

    return key;
}


static S32 srv_fmgr_cidb_init(U8 drv)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result, i;
    U32 read;
    WCHAR* buffer = NULL;
    FS_HANDLE fh = -1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    do {
        if(g_srv_fmgr_cidb_ctxt.cidb_ready && g_srv_fmgr_cidb_ctxt.cidb_drive == drv)
        {
            result = 0;
            break;
        }
        g_srv_fmgr_cidb_ctxt.cidb_drive = drv;
        g_srv_fmgr_cidb_ctxt.cidb_ready = 0;
        g_srv_fmgr_cidb_ctxt.cidb_count = 0;

        /* reload db, create if necessary */
        buffer = srv_fmgri_alloc_path_buffer();

        kal_wsprintf((WCHAR*)buffer, "%c:\\%w\\%w", drv, FMGR_CIDB_DIR, FMGR_CIDB_FILE);
        fh = FS_Open((WCHAR*)buffer, FS_READ_ONLY);
        if(fh == FS_FILE_NOT_FOUND || fh == FS_PATH_NOT_FOUND)
        {
            /* create dir */
            kal_wsprintf((WCHAR*)buffer, "%c:\\%w", drv, FMGR_CIDB_DIR);
            result = FS_CreateDir((WCHAR*)buffer);
            if(result < 0 && result != FS_FILE_EXISTS)
                break;

            /* make it hidden */
            FS_SetAttributes((WCHAR*)buffer, FS_ATTR_DIR | FS_ATTR_HIDDEN);

            /* create a empty file */
            kal_wsprintf((WCHAR*)buffer, "%c:\\%w\\%w", drv, FMGR_CIDB_DIR, FMGR_CIDB_FILE);
            fh = FS_Open((WCHAR*)buffer, FS_READ_WRITE | FS_CREATE);
            if(fh < 0)
            {
                result = fh;
                break;
            }

            memset(buffer, 0, SRV_FMGR_PATH_BUFFER_SIZE);
            for(i=0;i<FMGR_CIDB_MAX_COUNT;i++)
            {
                result = FS_Write(fh, buffer, SRV_FMGR_PATH_BUFFER_SIZE, &read);
                if(result < 0)
                    break;
                result = FS_Write(fh, buffer, sizeof(U32), &read);
                if(result < 0)
                    break;
            }
            if(result < 0)
                break;

            memset(g_srv_fmgr_cidb_ctxt.cidb, 0, sizeof(g_srv_fmgr_cidb_ctxt.cidb));
            g_srv_fmgr_cidb_ctxt.cidb_ready = 1;
            break;

        }
        else if(fh < 0)
        {
            result = fh;
            break;
        }

        for(i=0;i<FMGR_CIDB_MAX_COUNT;i++)
        {
            result = FS_Read(fh, buffer, SRV_FMGR_PATH_BUFFER_SIZE, &read);
            if(result < 0)
                break;
            if(buffer[0])
            {
                g_srv_fmgr_cidb_ctxt.cidb[i].object_hash = srv_fmgri_cidb_hash_func(buffer);
                g_srv_fmgr_cidb_ctxt.cidb_count++;
            }

            result = FS_Read(fh, buffer, sizeof(U32), &read);
            if(result < 0)
                break;
            g_srv_fmgr_cidb_ctxt.cidb[i].time = *((U32*)buffer);            
        }
        if(result < 0)
            break;

        g_srv_fmgr_cidb_ctxt.cidb_ready = 1;

    } while(0);

    if(fh > 0)
        FS_Close(fh);

    if(buffer)
        srv_fmgri_free_path_buffer(buffer);

    FMGR_TRACE2(TGL1, TRC_SRV_FMGR_A57F0CAA984A4396844DE04818E87D0A, 
        "[SRV_FMGR] > CustIcon > init(drv=%d): %d", drv, result);

    return result;
}

static S8 srv_fmgr_cidb_is_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_fmgr_cidb_ctxt.cidb_ready;
}

static S32 srv_fmgr_cidb_find_empty_entry(const WCHAR* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result, i, min_idx;
    U32 min_time;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_fmgr_cidb_init((U8)path[0]);
    if(result < 0)
        return result;
    
    result = 0;
    min_time = 0xFFFFFFFF;
    min_idx = 0;
    for(i=0; i<FMGR_CIDB_MAX_COUNT; i++)
    {
        if(g_srv_fmgr_cidb_ctxt.cidb[i].object_hash == 0)
        {
            result = i+1;
            break;
        }
        if(min_time > g_srv_fmgr_cidb_ctxt.cidb[i].time)
        {
            min_time = g_srv_fmgr_cidb_ctxt.cidb[i].time;
            min_idx = i;
        }
    }
    if(result == 0)
    {
        result = min_idx+1;
    }
    
    FMGR_TRACE2(TGL1, TRC_SRV_FMGR_411D8DB176E2415D8B937EF6F71C8A34, 
        "[SRV_FMGR] > CustIcon > find_empty_entry(drv=%d): %d",
        path[0], result);

    return result;
}

static S32 srv_fmgr_cidb_find_entry(const WCHAR* object_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result, i;
    U32 hash;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do {
        result = srv_fmgr_cidb_init((U8)object_path[0]);
        if(result < 0)
            break;

        /* speed up, if no entry, no need to query */
        if(!g_srv_fmgr_cidb_ctxt.cidb_count)
        {
            result = 0;
            break;
        }

        hash = srv_fmgri_cidb_hash_func(object_path);
        result = 0;
        for(i=0; i<FMGR_CIDB_MAX_COUNT; i++)
        {
            if(g_srv_fmgr_cidb_ctxt.cidb[i].object_hash == hash)
            {
                result = i+1;
                break;
            }
        }
    }while(0);

    FMGR_TRACE2(TGL1, TRC_SRV_FMGR_029CAFD0861C4AA197F5789358B0F063, 
        "[SRV_FMGR] > CustIcon > find_entry(drv=%d): %d",
        object_path[0], result);

    return result;
}

static S32 srv_fmgr_cidb_write_entry(S32 idx, const WCHAR* object_path, const WCHAR* icon_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result, len;
    U32 write, cur_time;
    WCHAR* buffer = NULL;
    FS_HANDLE fh = -1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_ASSERT(srv_fmgr_cidb_is_init() && idx > 0);

    do {
        /* check object length */
        len = mmi_wcslen(object_path);
        if(len > SRV_FMGR_PATH_MAX_LEN)
        {
            result = FS_PATH_OVER_LEN_ERROR;
            break;
        }
        
        buffer = srv_fmgri_alloc_path_buffer();
        
        if(icon_path)
        {
            /* move the icon to folder */
            kal_wsprintf((WCHAR*)buffer, "%c:\\%w\\i%02d.jpg", g_srv_fmgr_cidb_ctxt.cidb_drive, FMGR_CIDB_DIR, idx);
            FS_Delete((WCHAR*)buffer);
            result = FS_Move((WCHAR*)icon_path, (WCHAR*)buffer, FS_MOVE_COPY, NULL, NULL, 0);
            if(result < 0)
                break;
        }

        /* open db */
        kal_wsprintf((WCHAR*)buffer, "%c:\\%w\\%w", g_srv_fmgr_cidb_ctxt.cidb_drive, FMGR_CIDB_DIR, FMGR_CIDB_FILE);
        fh = FS_Open((WCHAR*)buffer, FS_READ_WRITE | FS_OPEN_SHARED);
        if(fh < 0)
        {
            result = fh;
            break;
        }

        /* seek to position */
        result = FS_Seek(fh, (idx-1)*sizeof(srv_fmgr_cidb_file_entry_struct), FS_FILE_BEGIN);
        if(result < 0)
            break;

        /* update db */
        result = FS_Write(fh, (void*)object_path, (len+1)*ENCODING_LENGTH, &write);
        if(result < 0)
            break;

        cur_time = app_getcurrtime();
        result = FS_Seek(fh, SRV_FMGR_PATH_BUFFER_SIZE - write, FS_FILE_CURRENT);
        if(result < 0)
            break;

        result = FS_Write(fh, (void*)&cur_time, sizeof(U32), &write);
        if(result < 0)
            break;

        /* update memory */
        if(g_srv_fmgr_cidb_ctxt.cidb[idx-1].object_hash == 0)
            g_srv_fmgr_cidb_ctxt.cidb_count ++;
        g_srv_fmgr_cidb_ctxt.cidb[idx-1].object_hash = srv_fmgri_cidb_hash_func(object_path);
        g_srv_fmgr_cidb_ctxt.cidb[idx-1].time = cur_time;
        
    } while(0);

    if(fh > 0)
        FS_Close(fh);

    if(buffer)
        srv_fmgri_free_path_buffer(buffer);

    FMGR_TRACE2(TGL1, TRC_SRV_FMGR_842D047EFC694052963BE10EAE614EA3, 
        "[SRV_FMGR] > CustIcon > write_entry(idx=%d): %d",
        idx, result);

    return result;
}

static S32 srv_fmgr_cidb_clear_entry(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    U32 write;
    WCHAR* buffer = NULL;
    FS_HANDLE fh = -1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_ASSERT(srv_fmgr_cidb_is_init() && idx > 0);
    
    do {
        buffer = srv_fmgri_alloc_path_buffer();
        
        /* delete associate icon */
        kal_wsprintf((WCHAR*)buffer, "%c:\\%w\\i%02d.jpg", g_srv_fmgr_cidb_ctxt.cidb_drive, FMGR_CIDB_DIR, idx);
        FS_Delete((WCHAR*)buffer);

        /* open db */
        kal_wsprintf((WCHAR*)buffer, "%c:\\%w\\%w", g_srv_fmgr_cidb_ctxt.cidb_drive, FMGR_CIDB_DIR, FMGR_CIDB_FILE);
        fh = FS_Open((WCHAR*)buffer, FS_READ_WRITE | FS_OPEN_SHARED);
        if(fh < 0)
        {
            result = fh;
            break;
        }

        /* seek to position */
        result = FS_Seek(fh, (idx-1)*SRV_FMGR_PATH_BUFFER_SIZE, FS_FILE_BEGIN);
        if(result < 0)
            break;

        /* update db */
        memset(buffer, 0, SRV_FMGR_PATH_BUFFER_SIZE);
        result = FS_Write(fh, buffer, SRV_FMGR_PATH_BUFFER_SIZE, &write);
        if(result < 0)
            break;

        g_srv_fmgr_cidb_ctxt.cidb[idx-1].object_hash = 0;
        g_srv_fmgr_cidb_ctxt.cidb[idx-1].time = 0;
        g_srv_fmgr_cidb_ctxt.cidb_count --;
    } while(0);

    if(fh > 0)
        FS_Close(fh);

    if(buffer)
        srv_fmgri_free_path_buffer(buffer);

    FMGR_TRACE2(TGL1, TRC_SRV_FMGR_A3F61EA3A0E14EB88A5341EF95DAFA5F, 
        "[SRV_FMGR] > CustIcon > clear_entry(idx=%d): %d",
        idx, result);
    
    return result;
}

static S32 srv_fmgr_cidb_get_icon(S32 idx, WCHAR* icon_path, S32 path_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result, len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_ASSERT(srv_fmgr_cidb_is_init() && idx > 0);

    do {
        /* check if path length enough or not */
        len = mmi_wcslen(FMGR_CIDB_DIR) + 11;
        if(path_size < len * ENCODING_LENGTH)
        {
            result = SRV_FMGR_CUSTICON_RESULT_BUFFER_NOT_ENOUGH;
            break;
        }

        /* delete associate icon */
        kal_wsprintf((WCHAR*)icon_path, "%c:\\%w\\i%02d.jpg", g_srv_fmgr_cidb_ctxt.cidb_drive, FMGR_CIDB_DIR, idx);
        result = 0;        
    } while(0);

    FMGR_TRACE2(TGL1, TRC_SRV_FMGR_68B46D8A734F4C47B0D565CCE36AF70E, 
        "[SRV_FMGR] > CustIcon > get_icon(idx=%d): %d",
        idx, result);
    return result;
}

static S32 srv_fmgr_cidb_for_each_entry(WCHAR drv, srv_fmgr_cidb_action_func action, U32 data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result, i;
    U32 read, timestamp;
    WCHAR* buffer;
    FS_HANDLE fh = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    do {
        g_srv_fmgr_cidb_ctxt.cidb_drive = (U8)drv;
        g_srv_fmgr_cidb_ctxt.cidb_ready = 1;

        /* reload db, create if necessary */
        buffer = srv_fmgri_alloc_path_buffer();

        kal_wsprintf((WCHAR*)buffer, "%c:\\%w\\%w", drv, FMGR_CIDB_DIR, FMGR_CIDB_FILE);
        fh = FS_Open((WCHAR*)buffer, FS_READ_ONLY | FS_OPEN_SHARED);
        if(fh == FS_FILE_NOT_FOUND || fh == FS_PATH_NOT_FOUND)
        {
            result = 0;
            break;
        }
        else if(fh < 0)
        {
            result = fh;
            break;
        }

        for(i=0;i<FMGR_CIDB_MAX_COUNT;i++)
        {
            result = FS_Read(fh, buffer, SRV_FMGR_PATH_BUFFER_SIZE, &read);
            if(result < 0)
                break;
            if(buffer[0])
                g_srv_fmgr_cidb_ctxt.cidb[i].object_hash = srv_fmgri_cidb_hash_func(buffer);

            result = FS_Read(fh, (void*)&timestamp, sizeof(U32), &read);
            if(result < 0)
                break;

            g_srv_fmgr_cidb_ctxt.cidb[i].time = timestamp;

            if(buffer[0])
            {
                result = action(i+1, buffer, data);
                if(result < 0)
                    break;
            }
            FMGR_TRACE3(TGL1, TRC_SRV_FMGR_4A34F19FC6F940CBB34F4B9F9ECFB424, 
                "[SRV_FMGR] > CustIcon > for_each_entry(drv=%d, idx=%d): %d",
                drv, i+1, result);
        }

        if(result < 0)
        {
            FMGR_TRACE3(TGL1, TRC_SRV_FMGR_4A34F19FC6F940CBB34F4B9F9ECFB424, 
                "[SRV_FMGR] > CustIcon > for_each_entry(drv=%d, idx=%d): %d",
                drv, i+1, result);
            break;
        }

    } while(0);

    if(fh > 0)
        FS_Close(fh);

    if(buffer)
        srv_fmgri_free_path_buffer(buffer);

    return result;
}

static S32 srv_fmgr_cidb_action_rename_folder(S32 idx, const WCHAR* object_path, U32 data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_notification_adv_action_event_struct *async_event;
    S32 folder_len, result;
    WCHAR* buffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    async_event = (srv_fmgr_notification_adv_action_event_struct*)data;

    folder_len = mmi_wcslen(async_event->src_filepath);
    /* check if object is in this folder */
    if(mmi_wcsncmp(async_event->src_filepath, object_path, folder_len) == 0)
    {
        /* rename the object_path, and write it */
        buffer = srv_fmgri_alloc_path_buffer();
        mmi_wcscpy(buffer, async_event->dest_filepath);
        mmi_wcscat(buffer, object_path + folder_len);
        result = srv_fmgr_cidb_write_entry(idx, buffer, NULL);
        srv_fmgri_free_path_buffer(buffer);
        return result;
    }
    return 0;
}

static S32 srv_fmgr_cidb_action_delete_folder(S32 idx, const WCHAR* object_path, U32 data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *folder;
    S32 folder_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder = (WCHAR*)data;

    folder_len = mmi_wcslen(folder);
    
    /* check if object is in this folder */
    if(mmi_wcsncmp(folder, object_path, folder_len) == 0)
    {
        /* delete this entry */
        return srv_fmgr_cidb_clear_entry(idx);
    }
    return 0;
}

static S32 srv_fmgr_cidb_action_delete_folder_by_filter(S32 idx, const WCHAR* object_path, U32 data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *folder;
    S32 folder_len, fs_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    folder = (WCHAR*)data;

    folder_len = mmi_wcslen(folder);
    
    /* check if object is in this folder */
    if(mmi_wcsncmp(folder, object_path, folder_len) == 0)
    {
        /* check if file still exist then delete this entry */
        fs_ret = FS_GetAttributes((WCHAR*)object_path);
        if(fs_ret == FS_FILE_NOT_FOUND || fs_ret == FS_PATH_NOT_FOUND)
        {
            return srv_fmgr_cidb_clear_entry(idx);
        }
    }
    return 0;
}


mmi_ret srv_fmgr_cidb_notify_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_notification_format_event_struct *format_evt;
    srv_fmgr_notification_adv_action_event_struct *action_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(param->evt_id)
    {
    case EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT:
        format_evt = (srv_fmgr_notification_format_event_struct*)param;
        if(format_evt->state != SRV_FMGR_NOTIFICATION_STATE_AFTER)
            break;
        if(format_evt->drv_letter == g_srv_fmgr_cidb_ctxt.cidb_drive)
            g_srv_fmgr_cidb_ctxt.cidb_drive = 0;
        break;

    case EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION:
        action_evt = (srv_fmgr_notification_adv_action_event_struct*)param;
        if(action_evt->state != SRV_FMGR_NOTIFICATION_STATE_AFTER)
            break;

        switch(action_evt->action)
        {
        case SRV_FMGR_NOTIFICATION_ACTION_MOVE:
        case SRV_FMGR_NOTIFICATION_ACTION_RENAME:
            if(action_evt->src_fileinfo.attribute & FS_ATTR_DIR)
                srv_fmgr_cidb_for_each_entry(action_evt->src_filepath[0], srv_fmgr_cidb_action_rename_folder, (U32)action_evt);
            else
                srv_fmgr_custicon_do(SRV_FMGR_CUSTICON_OP_MOVE_OBJECT, action_evt->src_filepath, action_evt->dest_filepath);
            break;
        case SRV_FMGR_NOTIFICATION_ACTION_DELETE:
            if(action_evt->src_fileinfo.attribute & FS_ATTR_DIR)
                srv_fmgr_cidb_for_each_entry(action_evt->src_filepath[0], srv_fmgr_cidb_action_delete_folder, (U32)action_evt->src_filepath);
            else
                srv_fmgr_custicon_do(SRV_FMGR_CUSTICON_OP_DEREGISTER, action_evt->src_filepath, NULL);
            break;

        case SRV_FMGR_NOTIFICATION_ACTION_DELETE_ALL:
            srv_fmgr_cidb_for_each_entry(action_evt->src_filepath[0], srv_fmgr_cidb_action_delete_folder_by_filter, (U32)action_evt->src_filepath);
            break;

        }
        break;
    }

    return MMI_RET_OK;
}

#endif
