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

/*******************************************************************************
 * Filename:
 * ---------
 * WgtMgrSrvMain.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/************************************************************************/
/* Include Header                                                       */
/************************************************************************/
//#include "MMI_include.h"

#ifdef __GADGET_SUPPORT__
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "nvram_common_defs.h"
#include "USBSrvGprot.h"
#include "mmi_rp_srv_wgtmgr_def.h"
#include "mmi_frm_nvram_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "widget_adp_struct.h"
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "Unicodexdcl.h"
#include "WgtMgrSrvGprot.h"
#include "WgtMgrSrvIprot.h"
#include "WgtMgrSrv.h"

/************************************************************************/
/* Structure and Definition                                             */
/************************************************************************/

/* make sure size of nvram_wgtmgr_lid_struct is smaller than NVRAM_EF_WGTMGR_DATA_SIZE */
#ifndef COMPILE_ASSERT
#define COMPILE_ASSERT(exp, name) typedef int dummy##name [(exp) ? 1 : -1];
#endif

#ifdef __WGTMGR_SAVE_ICON_FILE__
extern WCHAR g_srv_wgtmgr_icon_folder[];
#endif
COMPILE_ASSERT(NVRAM_EF_WGTMGR_DATA_SIZE >= sizeof(nvram_wgtmgr_lid_struct), lid_size_check);

/************************************************************************/
/* Function Definition                                                  */
/************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_read_lid
 * DESCRIPTION
 *  this function is used to read data from lid
 * PARAMETERS
 *  lid_p : [OUT] the data buffer to store data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_read_lid(nvram_wgtmgr_lid_struct *lid_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
    S16 error = 0;	
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* read widget info from NVRAM LID */
    ReadRecord(NVRAM_EF_WGTMGR_DATA_LID, 1, lid_p, sizeof(nvram_wgtmgr_lid_struct), &error);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_write_lid
 * DESCRIPTION
 *  this function is used to write data to lid
 * PARAMETERS
 *  lid_p : [IN] the data buffer to write
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_write_lid(nvram_wgtmgr_lid_struct *lid_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
    S16 error = 0;	
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* write widget info to NVRAM LID */
    WriteRecord(NVRAM_EF_WGTMGR_DATA_LID, 1, lid_p, NVRAM_EF_WGTMGR_DATA_SIZE, &error);
}



/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_read_wgt_info_from_nvram
 * DESCRIPTION
 *  This function reads widget information from NVRAM LID
 * PARAMETERS
 *  info: [OUT] the buffer to store the widget info
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_read_wgt_info_from_nvram(srv_wgtmgr_wgt_item_struct* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_wgtmgr_lid_struct *lid_p = NULL;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Allocate control buffer for LID */
    lid_p = (nvram_wgtmgr_lid_struct*) OslMalloc(sizeof(nvram_wgtmgr_lid_struct));
    MMI_ASSERT(lid_p);

    /* Read widget info from NVRAM LID */
    srv_wgtmgr_read_lid(lid_p);

    kal_mem_cpy(info, lid_p->dwgt, sizeof(srv_wgtmgr_wgt_item_struct) * SRV_WGTMGR_MAX_DOWNLOADED_WGT_NUM);

    /* Free control buffer */
    OslMfree(lid_p);

}



/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_read_wgt_info_from_nvram_by_id
 * DESCRIPTION
 *  This function reads widget information from NVRAM LID
 * PARAMETERS
 *  id  : [IN]  widget id
 *  info: [OUT] the buffer to store the widget info
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_read_wgt_info_from_nvram_by_id(S32 id, srv_wgtmgr_wgt_item_struct* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_wgtmgr_lid_struct *lid_p = NULL;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Allocate control buffer for LID */
    lid_p = (nvram_wgtmgr_lid_struct*) OslMalloc(sizeof(nvram_wgtmgr_lid_struct));
    MMI_ASSERT(lid_p);

    /* Read widget info from NVRAM LID */
    srv_wgtmgr_read_lid(lid_p);

    kal_mem_cpy(info, &(lid_p->dwgt[id]), sizeof(srv_wgtmgr_wgt_item_struct));

    /* Free control buffer */
    OslMfree(lid_p);

}



/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_read_name_or_version_from_file
 * DESCRIPTION
 *  This function reads widget name or file from file
 * PARAMETERS
 *  type : [IN]
           SRV_WGTMGR_UPDATE_VERSION : to read version
           SRV_WGTMGR_UPDATE_NAME: to read name
 * RETURNS
 *  MMI_TRUE: success, MMI_FALSE: fail
 *****************************************************************************/
MMI_BOOL srv_wgtmgr_read_name_or_version_from_file(int type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const WCHAR* file;
    U32 data_size;
    void *dest;
    FS_HANDLE fd = 0; 
    S32 ret = -1;
    srv_wgtmgr_wgt_asm_data_struct *asm_data_p = g_srv_wgtmgr_cntx_p->asm_data;
    U32 read_size;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Read version data form file */
    if (type == SRV_WGTMGR_UPDATE_VERSION)
    {
        file = g_srv_wgtmgr_version_data;    
        data_size = sizeof(asm_data_p->version);
        dest = (void*)asm_data_p->version;
    }
    else
    {
        file = g_srv_wgtmgr_name_data;    
        data_size = sizeof(asm_data_p->dwgt_name);
        dest = (void*)asm_data_p->dwgt_name;
    }

    fd = FS_Open(file, FS_READ_ONLY);
    if (fd >= 0)
    {
        ret = FS_Read(fd, dest, data_size, &read_size);
        FS_Close(fd);
    }

    if (fd < 0 || ret != FS_NO_ERROR)
   	{
        return MMI_FALSE;
    }
    return MMI_TRUE;    
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_save_nvram_lid
 * DESCRIPTION
 *  This function saves widget info to lid
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_save_nvram_lid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_wgtmgr_lid_struct *lid_p;
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    
    /* Allocate control buffer for LID */
    lid_p = (nvram_wgtmgr_lid_struct*) OslMalloc(sizeof(nvram_wgtmgr_lid_struct));
    MMI_ASSERT(lid_p);

#ifdef __WGTMGR_MGR_PHONE_WIDGET__
    kal_mem_cpy(lid_p->pwgt_status, cntx_p->pwgt_status, sizeof(U8) * SRV_WGTMGR_MAX_PHONE_WGT_NUM);
#endif
    kal_mem_cpy(lid_p->dwgt_status, cntx_p->dwgt_status, sizeof(U8) * SRV_WGTMGR_MAX_DOWNLOADED_WGT_NUM);
    kal_mem_cpy(lid_p->dwgt, cntx_p->asm_data->dwgt, sizeof(srv_wgtmgr_wgt_item_struct) * SRV_WGTMGR_MAX_DOWNLOADED_WGT_NUM);

    /* Write widget info to NVRAM LID */
    srv_wgtmgr_write_lid(lid_p);    

    /* Free control buffer */
    OslMfree(lid_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_path
 * DESCRIPTION
 *  This function is used to get path of a widget
 * PARAMETERS
 *  id     : [IN] the widget id
 *  type   : [IN] type of path
 *  path   : [OUT] the path in query
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_get_path(
       S32 id, 
       srv_wgtmgr_path_enum type, 
       WCHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char drive_letter;
    U8 drive = g_srv_wgtmgr_cntx_p->dwgt_drive[id];
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   	
    drive_letter = srv_wgtmgr_get_drive_letter((srv_wgtmgr_wgt_drive_enum)drive);

#ifdef __WGTMGR_SAVE_ICON_FILE__
    if (type == SRV_WGTMGR_PATH_ICON_DISPLAY)
    {
        kal_wsprintf(path, "Z:\\@wgtmgr\\icon\\%03d.png", id);
        if (FS_GetAttributes(path) >= 0)
        {
            return;
        }
    }
#endif

    kal_wsprintf(path, "%c:\\@gadget\\%03d\\", drive_letter, id);
    if (type == SRV_WGTMGR_PATH_FOLDER)
    {
        return;
    }
    else if (type == SRV_WGTMGR_PATH_ICON_DISPLAY)
    {
        mmi_wcscat(path, L"@icon.png");
        if (FS_GetAttributes(path) >= 0)
        {
            return;
        }
        else
        {
            mmi_wcscpy(path, g_srv_wgtmgr_memcard_wgt_icon);
        }
    }
    else if (type == SRV_WGTMGR_PATH_ICON_FILE)
    {
        mmi_wcscat(path, L"@icon.png");           
    }	
	else if (type == SRV_WGTMGR_PATH_OPTIONS_FILE)
    {
        mmi_wcscat(path, L"options.xml");
    }
    else if (type == SRV_WGTMGR_PATH_MAIN_VIEW)
    {
        mmi_wcscat(path, L"main.xml");
    }
    else if (type == SRV_WGTMGR_PATH_MANIFEST)
    {
        mmi_wcscat(path, L"gadget.gmanifest");        
    }
		
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_save_wgt_status_to_nvram
 * DESCRIPTION
 *  Save widget status to nvram
 *  This is used when widget manager does not have lid data in hand
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_save_wgt_status_to_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
    nvram_wgtmgr_lid_struct *lid_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Allocate control buffer for LID */
    lid_p = (nvram_wgtmgr_lid_struct*) OslMalloc(sizeof(nvram_wgtmgr_lid_struct));
    MMI_ASSERT(lid_p);

    /* Read widget info from NVRAM LID */
    srv_wgtmgr_read_lid(lid_p);

    kal_mem_cpy(lid_p->dwgt_status, g_srv_wgtmgr_cntx_p->dwgt_status, sizeof(U8) * SRV_WGTMGR_MAX_DOWNLOADED_WGT_NUM);
#ifdef __WGTMGR_MGR_PHONE_WIDGET__
    kal_mem_cpy(lid_p->pwgt_status, g_srv_wgtmgr_cntx_p->pwgt_status, sizeof(U8) * SRV_WGTMGR_MAX_PHONE_WGT_NUM);
#endif

    srv_wgtmgr_write_lid(lid_p); 

    /* Free control buffer */
    OslMfree(lid_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_save_wgt_name_and_version_to_file
 * DESCRIPTION
 *  Save the name and version of a widget to file 
 * PARAMETERS
 *  id      : [IN] the widget id
 *  name    : [IN] the widget name
 *  version : [IN] the widget version
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_save_wgt_name_and_version_to_file(U16 id, WCHAR *name, WCHAR *version)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
    S32 offset = 0;
    FS_HANDLE fd;
    U32 written;	
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    fd = FS_Open(g_srv_wgtmgr_name_guard, FS_CREATE);
    FS_Close(fd);
	
    fd = FS_Open(g_srv_wgtmgr_name_data, FS_READ_WRITE);
    if (fd >= 0)
    {
        offset = sizeof(WCHAR) * id * (SRV_WGTMGR_MAX_WGT_NAME_LEN + 1);
        FS_Seek(fd, offset, FS_FILE_BEGIN);
        FS_Write(fd, name, sizeof(WCHAR) * (SRV_WGTMGR_MAX_WGT_NAME_LEN + 1), &written);
        MMI_ASSERT(written == sizeof(WCHAR) * (SRV_WGTMGR_MAX_WGT_NAME_LEN + 1));
        FS_Close(fd);
    }
    FS_Delete(g_srv_wgtmgr_name_guard);


    fd = FS_Open(g_srv_wgtmgr_version_guard, FS_CREATE);
    FS_Close(fd);
	
    fd = FS_Open(g_srv_wgtmgr_version_data, FS_READ_WRITE);
    if (fd >= 0)
    {
        offset = sizeof(WCHAR) * id * (SRV_WGTMGR_MAX_WGT_VERSION_LEN + 1);
        FS_Seek(fd, offset, FS_FILE_BEGIN);
        FS_Write(fd, version, sizeof(WCHAR) * (SRV_WGTMGR_MAX_WGT_VERSION_LEN + 1), &written);
        MMI_ASSERT(written == sizeof(WCHAR) * (SRV_WGTMGR_MAX_WGT_VERSION_LEN + 1));		
        FS_Close(fd);		
    }
    FS_Delete(g_srv_wgtmgr_version_guard);	
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_save_wgt_info_to_nvram
 * DESCRIPTION
 *  Save the info of a widget to nvram
 * PARAMETERS
 *  id  : [IN] the widget id
 *  wgt : [IN] the info of the widget
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_save_wgt_info_to_nvram(U16 id, srv_wgtmgr_wgt_item_struct *wgt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
    nvram_wgtmgr_lid_struct *lid_p = NULL;  

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* allocate control buffer for LID */
    lid_p = (nvram_wgtmgr_lid_struct*) OslMalloc(sizeof(nvram_wgtmgr_lid_struct));
    MMI_ASSERT(lid_p);

    /* read widget info from NVRAM LID */
    srv_wgtmgr_read_lid(lid_p);

    kal_mem_cpy(&(lid_p->dwgt[id]), wgt, sizeof(srv_wgtmgr_wgt_item_struct));

    srv_wgtmgr_write_lid(lid_p); 

    /* Free control buffer */
    OslMfree(lid_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_set_data_need_update
 * DESCRIPTION
 *  Set need_update_name to TRUE
 * PARAMETERS
 *  mode : [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_set_data_need_update(int mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx_p->need_update_data |= mode;
    WriteValue(NVRAM_WGTMGR_WGT_NEED_UPDATE_NAME, &(cntx_p->need_update_data), DS_BYTE, &error);
}

#endif /* __GADGET_SUPPORT__ */

