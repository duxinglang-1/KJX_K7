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
 *  UpgradeSrvUtil.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Upgrade service utility function implementation
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined __MMI_VPP_UPGRADE__

#include "InetSrvGprot.h"
#include "string.h"
#include "stdio.h"
#include "mmi_frm_gprot.h"
#include "app_str.h"
#include "vmenv.h"
#include "vmcert_sdk.h"
#include "vmgettag_sdk.h"
#include "che_api.h"
#include "FileMgrSrvGprot.h"
#include "UpgradeSrvUtil.h"
#include "MMI_inet_app_trc.h"

typedef struct upgrade_mem_header_t
{
    const char *filename;                                     /* the file which allcated the chunk */
    kal_uint16 line;                      /* file line */

    struct upgrade_mem_header_t *prev;                         /* previous allocated chunk */
    struct upgrade_mem_header_t *next;                         /* next allocated chunk */
    kal_uint32 chunk_size;                                   /* allocated size round to 4 */
} upgrade_mem_header_struct;

typedef struct
{
    kal_uint32 allocated_bytes;
    kal_uint32 max_allocated_bytes;
    kal_int32 total_bytes;    
    kal_int32 free_space;
    void* mem_addr;    
    upgrade_mem_header_struct *head; 
} upgrade_memory_module_struct;

static upgrade_memory_module_struct g_upgrade_mem_mod = {0,};

#define SRV_UPGRADE_MEMORY_SIZE  (10 * 1024)

#define SRV_UPGRADE_MINMUM_DISK_SIZE  (1024 * 1024)

U32 g_upgrade_memory[SRV_UPGRADE_MEMORY_SIZE / 4];
KAL_ADM_ID g_upgrade_adm_id;

/*****************************************************************************
 * FUNCTION
 *  upgrade_util_init_mem
 * DESCRIPTION
 *  Init memory allocator
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void upgrade_util_init_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_upgrade_adm_id = kal_adm_create(g_upgrade_memory, SRV_UPGRADE_MEMORY_SIZE, NULL, KAL_FALSE);

    g_upgrade_mem_mod.total_bytes = SRV_UPGRADE_MEMORY_SIZE;
    g_upgrade_mem_mod.free_space = g_upgrade_mem_mod.total_bytes;
}

/*****************************************************************************
 * FUNCTION
 *  upgrade_util_alloc_int
 * DESCRIPTION
 *  Memory allocator
 * PARAMETERS
 *  size                 [IN]    memory size
 *  filename             [IN]    filename
 *  lineno               [IN]    line number
 * RETURNS
 *  memory pointer
 *****************************************************************************/
#ifdef UPGRADE_DEBUG_MEM
void *upgrade_util_alloc_int(U32 size, const char *filename, int lineno)
#else
void *upgrade_util_alloc_int(U32 size)
#endif
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    void *mem;
#ifdef UPGRADE_DEBUG_MEM
    kal_uint32 chunk_size;
    upgrade_memory_module_struct *mod;
    upgrade_mem_header_struct *header;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef UPGRADE_DEBUG_MEM
    
    mod = &g_upgrade_mem_mod;

    /* round to multiple of 4 */
    chunk_size = ((((kal_uint32)size + 3) >> 2) << 2);	

    if (chunk_size == 0)
    {
        chunk_size = 4;
   	}

    mem = kal_adm_alloc(g_upgrade_adm_id, chunk_size + sizeof(upgrade_mem_header_struct));

    if(mem)
    {
        header = (upgrade_mem_header_struct*) mem;
        mem = header + 1;

        header->chunk_size = (kal_uint32)chunk_size;  

        /* update module information */
        mod->allocated_bytes += chunk_size;
 
        if (mod->allocated_bytes > mod->max_allocated_bytes)
        {
            mod->max_allocated_bytes = mod->allocated_bytes;
        }
        mod->free_space -= chunk_size;

        /* header */
        header->filename = filename;
        header->line = lineno;
        header->prev = NULL;
	
        /* update linked list */
        if(mod->head == NULL)
        {
            header->next = NULL;
            mod->head = header;
        }
        else
        {
            header->next = mod->head;
            mod->head->prev = header;
            mod->head = header;
        }
    }
#else    
    mem = kal_adm_alloc_align(g_upgrade_adm_id, size, 4);
#endif 
    return mem;
}

/*****************************************************************************
 * FUNCTION
 *  upgrade_util_free_int
 * DESCRIPTION
 *  Memory deallocator
 * PARAMETERS
 *  mem                  [IN]    memory pointer
 *  filename             [IN]    filename
 *  lineno               [IN]    line number
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef UPGRADE_DEBUG_MEM
void upgrade_util_free_int(void *mem, const char *filename, int lineno)
#else
void upgrade_util_free_int(void *mem)
#endif
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
#ifdef UPGRADE_DEBUG_MEM    
    upgrade_mem_header_struct *header;
    upgrade_mem_header_struct *prev_node;
    upgrade_memory_module_struct *mod;
#endif    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef UPGRADE_DEBUG_MEM
    mod = &g_upgrade_mem_mod;
    header = ((upgrade_mem_header_struct*) mem) - 1; 

    prev_node = header->prev;
    if(prev_node == NULL)
    {
        ASSERT(header == mod->head);
        mod->head = header->next;
        if(mod->head)
        {
            mod->head->prev = NULL;
        }
    }
    else
    {
        prev_node->next = header->next;
        if(header->next)
        {
            header->next->prev = prev_node;
        }
    }

    header->filename = filename;
    header->line = lineno;

	mod->free_space += header->chunk_size; 
    mod->allocated_bytes -= header->chunk_size;

    kal_adm_free(g_upgrade_adm_id, header);

#else
    kal_adm_free(g_upgrade_adm_id, mem);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  upgrade_util_get_filename
 * DESCRIPTION
 *  Get filename part from a url
 * PARAMETERS
 *  url                  [IN]    URL
 * RETURNS
 *  Start position of a filename
 *****************************************************************************/
WCHAR *upgrade_util_get_filename(WCHAR* url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    S32 i = 0, len = app_ucs2_strlen((const kal_int8 *) url);
    WCHAR *name = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < len; i++)
    {
        if (url[i] == L'/')
        {
            name = url + (i + 1);
        }
    }

    return name;
}

/*****************************************************************************
 * FUNCTION
 *  upgrade_util_check_compile_option
 * DESCRIPTION
 *  Check upgrade for the originator is opened
 * PARAMETERS
 *  originator    [IN] the originator
 * RETURNS
 *  MMI_TRUE if allow to check upgrade
 *****************************************************************************/
MMI_BOOL upgrade_util_check_compile_option(srv_upgrage_originator_enum originator)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    MMI_BOOL ret = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(originator)
    {
    case SRV_UPGRADE_ORIGINATOR_SNS:
#if defined __MMI_SNS_VPP_UPGRADE__
        ret = MMI_TRUE;
#endif
        break;
    case SRV_UPGRADE_ORIGINATOR_CLOUD_SSO:
    case SRV_UPGRADE_ORIGINATOR_CLOUD_BACKUP_RESTORE:
    case SRV_UPGRADE_ORIGINATOR_CLOUD_EMAIL:
#if defined __MMI_SSO_VPP_UPGRADE__
        ret = MMI_TRUE;
#endif
        break;
    default:
        ret = MMI_TRUE;
        break;
    }
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  upgrade_util_create_default_folder
 * DESCRIPTION
 *  Create default folder of upgrade service if not exist
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if exists or created
 *****************************************************************************/
MMI_BOOL upgrade_util_create_default_folder(U8 drive)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    S32 ret = 0, disk_free_space = 0;
    WCHAR path[SRV_UPGRADE_MAX_PATH_LEN + 1];
    MMI_BOOL success = MMI_TRUE, create_folder = MMI_FALSE;
    FS_HANDLE hdlr = -1;
    FS_DiskInfo disk_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (drive == SRV_FMGR_CARD_DRV && FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        return MMI_FALSE;
    }

    kal_wsprintf((U16*)path, "%c:\\%w", drive, DEFAULT_FOLDER);

    ret = FS_GetDiskInfo((kal_uint16*)path, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

    if (ret < 0)
    {
        return MMI_FALSE;
    }

    disk_free_space = disk_info.FreeClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;

    if (disk_free_space < SRV_UPGRADE_MINMUM_DISK_SIZE + disk_info.BytesPerSector)    /* more a sector free space to keep file system other operation normal. */
    {
        return MMI_FALSE;
    }

    // check if sns folder path is a file
    ret = FS_GetAttributes(path);
    if (ret >= 0 && !(ret & FS_ATTR_DIR))
    {
        FS_Delete(path);
        create_folder = MMI_TRUE;
    }
    else if (ret < 0)
    {
        create_folder = MMI_TRUE;
    }
    
    if (create_folder == MMI_TRUE)
    {
        hdlr = FS_CreateDir((U16*)path);
        if(hdlr < FS_NO_ERROR)
        {  
            success = MMI_FALSE;
        }
        else
        {
            FS_SetAttributes((WCHAR*)path, FS_ATTR_DIR | FS_ATTR_HIDDEN); 
            success = MMI_TRUE;
        }
    }

    return success;
}

/*****************************************************************************
 * FUNCTION
 *  upgrade_util_prepare_url
 * DESCRIPTION
 *  Generate the url to check new version
 * PARAMETERS
 *  vpp_info             [IN]    vpp information
 * RETURNS
 *  Generated URL
 *****************************************************************************/
CHAR *upgrade_util_prepare_url(srv_upgrade_vpp_info_struct *vpp_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *url = (CHAR *) upgrade_util_alloc(SRV_UPGRADE_MAX_PATH_LEN + 1);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (url)
    {
        CHAR *v = (CHAR *) &vpp_info->version;
        CHAR buf[50] = {0};
        S32 buf_size = SRV_UPGRADE_MAX_PATH_LEN + 1;

        if (vm_get_vm_tag((short *) vpp_info->path, VM_CE_INFO_URL, url, &buf_size) == GET_TAG_TRUE)
        {
            kal_snprintf(buf, sizeof(buf),"?app_id=%d&ver=%d.%d.%d", vpp_info->app_id, *(v + 1), *(v + 2), *(v + 3));
            strcat(url, buf);
        }
        else
        {
            vpp_info->status = SRV_UPGRADE_STATUS_NOT_SUPPORT;
            upgrade_util_free(url);
            url = NULL;
        }
    }
    return url;
}

/*****************************************************************************
 * FUNCTION
 *  upgrade_util_free_da_info
 * DESCRIPTION
 *  Free download agent's information pointer
 * PARAMETERS
 *  da_info              [IN]    Download agent info pointer
 * RETURNS
 *  void
 *****************************************************************************/
void upgrade_util_free_da_info(srv_da_start_download_struct *da_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (da_info->filepath)
    {
        upgrade_util_free(da_info->filepath);
    }
    if (da_info->url)
    {
        upgrade_util_free(da_info->url);
    }
    upgrade_util_free(da_info);
}

/*****************************************************************************
 * FUNCTION
 *  upgrade_util_free_results
 * DESCRIPTION
 *  Free result list
 * PARAMETERS
 *  results              [IN]    result list pointer
 * RETURNS
 *  void
 *****************************************************************************/
void upgrade_util_free_results(srv_upgrade_result_struct *results)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    srv_upgrade_result_struct *temp = results;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(results)
    {
        if (results->path)
        {
            upgrade_util_free(results->path);
        }
        temp = results->next;
        upgrade_util_free(results);
        results = temp;
    }
}

/*****************************************************************************
 * FUNCTION
 *  upgrade_util_free_vpp_info
 * DESCRIPTION
 *  Free vpp info
 * PARAMETERS
 *  request              [IN]    request pointer
 * RETURNS
 *  void
 *****************************************************************************/
void upgrade_util_free_vpp_info(srv_upgrade_vpp_info_struct *vpp_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    if (vpp_info->download_url)
    {
        upgrade_util_free(vpp_info->download_url);
    }
    if (vpp_info->path)
    {
        upgrade_util_free(vpp_info->path);
    }
    if (vpp_info->app_name)
    {
        upgrade_util_free(vpp_info->app_name);
    }

    upgrade_util_free(vpp_info);
}

/*****************************************************************************
 * FUNCTION
 *  upgrade_util_free_vpp_info_list
 * DESCRIPTION
 *  Free list of vpp info
 * PARAMETERS
 *  head             [IN]    vpp info list head
 * RETURNS
 *  void
 *****************************************************************************/
void upgrade_util_remove_vpp_info_list(srv_upgrade_vpp_info_struct *head)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    srv_upgrade_vpp_info_struct *temp = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    while(head)
    {
        temp = head;
        head = head->next;
        upgrade_util_free_vpp_info(temp);
    }
}

/*****************************************************************************
 * FUNCTION
 *  upgrade_util_free_req_info
 * DESCRIPTION
 *  Free request info
 * PARAMETERS
 *  request              [IN]    request pointer
 * RETURNS
 *  void
 *****************************************************************************/
void upgrade_util_free_req_info(srv_upgrade_req_info_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    srv_upgrade_vpp_info_struct *vpp_info = req->vpp_info, *temp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    upgrade_util_remove_vpp_info_list(req->vpp_info);
    upgrade_util_free(req);
}

/*****************************************************************************
 * FUNCTION
 *  upgrade_util_find_downloaded_vpps
 * DESCRIPTION
 *  Get downloaded vpps' information
 * PARAMETERS
 *  void
 * RETURNS
 *  VPP info list if found
 *****************************************************************************/
srv_upgrade_vpp_info_struct *upgrade_util_find_downloaded_vpps(U8 drive)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    S32 buf_size = 4, len = 0;
    WCHAR temp_path[SRV_UPGRADE_MAX_PATH_LEN] = {0}, file_path[SRV_UPGRADE_MAX_PATH_LEN] = {0};
    WCHAR *filename = NULL;
    srv_upgrade_vpp_info_struct *head = NULL, *temp = NULL;
    FS_HANDLE hdlr;
    FS_DOSDirEntry info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    kal_wsprintf((U16*) temp_path, "%c:\\%w", drive, DEFAULT_FOLDER);

    /* if the directory does not exist, return directly */
    if (FS_GetAttributes(temp_path) < 0)
    {
        return NULL;
    }

    /* allocate a buffer for FS_FindXXX operation */
    filename = (WCHAR*) upgrade_util_alloc((SRV_FMGR_PATH_MAX_LEN + 1) * 2);

    /* if fail to allocate memory, return fail */
    if (filename == NULL)
    {
        return NULL;
    }

    len = app_ucs2_strlen((const kal_int8 *) temp_path);
    kal_wstrcat(temp_path, (const WCHAR *)L"\\*");

    hdlr = FS_FindFirst((WCHAR*) temp_path, 0, 0, &info, (WCHAR*) filename, SRV_FMGR_PATH_MAX_LEN * 2);
    temp_path[len] = 0;

    if (hdlr < 0)
    {
        upgrade_util_free(filename);	
        return NULL;
    }

    do
    {
        MMI_BOOL is_valid = MMI_TRUE;
        temp = (srv_upgrade_vpp_info_struct *) upgrade_util_alloc(sizeof(srv_upgrade_vpp_info_struct));
        memset(temp, 0, sizeof(srv_upgrade_vpp_info_struct));

        memset(file_path, 0, SRV_UPGRADE_MAX_PATH_LEN * sizeof(WCHAR));              
        kal_wsprintf((U16*)file_path, "%w\\%w", temp_path, filename);
        
        if (GET_TAG_TRUE != vm_get_vm_tag((short *) file_path, VM_CE_INFO_VER, &temp->version, &buf_size))
        {
            is_valid = MMI_FALSE;
        }
        else
        {            
            if (GET_TAG_TRUE != vm_get_vm_tag((short *) file_path, VM_CE_INFO_APP_ID, &temp->app_id, &buf_size))
            {
                is_valid = MMI_FALSE;
            }       
        }

        if (is_valid == MMI_FALSE)
        {
            FS_Delete(file_path);
            upgrade_util_free(temp);
        }
        else
        {
            temp->status = SRV_UPGRADE_STATUS_DOWNLOADED;
            temp->path = (WCHAR *) upgrade_util_alloc(app_ucs2_strlen((const kal_int8 *) file_path) * 2 + 1);

            if (temp->path)
            {
				memset(temp->path, 0, app_ucs2_strlen((const kal_int8 *) file_path) * 2 + 1);
                app_ucs2_strcpy((kal_int8 *) temp->path, (const kal_int8 *) file_path);
                if (head == NULL)
                {
                    head = temp;
                }
                else
                {
                    temp->next = head;
                    head = temp;
                }
            }
            else
            {
                upgrade_util_free(temp);
            }           
        }
    } while (FS_FindNext(hdlr, &info, (WCHAR*) filename, SRV_FMGR_PATH_MAX_LEN * 2) == FS_NO_ERROR);

    FS_FindClose(hdlr);
    upgrade_util_free(filename);

    return head;
}

/*****************************************************************************
 * FUNCTION
 *  upgrade_util_check_vpp_existence
 * DESCRIPTION
 *  Check downloaded vpps existence
 * PARAMETERS
 *  head             [IN]    vpp info list head
 * RETURNS
 *  void
 *****************************************************************************/
void upgrade_util_check_vpp_existence(srv_upgrade_vpp_info_struct *head)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    while(head)
    {
        if (head->status == SRV_UPGRADE_STATUS_DOWNLOADED && (head->path == NULL || FS_GetAttributes(head->path) < 0))
        {
            head->status = SRV_UPGRADE_STATUS_FAILED;

            if (head->path)
            {
                upgrade_util_free(head->path);
                head->path = NULL;
            }
        }
        head = head->next;
    }
}
#endif
