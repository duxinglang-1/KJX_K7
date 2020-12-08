/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * vmio.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 * 
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
#include "vmswitch.h"
#ifdef __MRE_CORE_BASE__

#include "kal_general_types.h"
#include "MMIDataType.h"
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "string.h"
#include "stdio.h"
#include "DevConfigGprot.h"

#include "vmio.h"
#include "vmchset.h"
#include "vmlog.h"
#include "vmstdlib.h"
#include "vmopt.h"
#include "vmdl.h"
#include "vmfilere.h"
#include "vmsys.h"
#include "vmpromng.h"
#include "vmresmng.h"
#include "vmmod.h"
#include "vmmacrostub.h"
/* ------------------------------------------------------------------------ */
/* 系统函数声明。                                                       */
/* ------------------------------------------------------------------------ */
extern VMINT _vm_get_disk_permission(void);
extern kal_bool srv_usb_is_in_mass_storage_mode(void);
extern VMWSTR vm_get_self_filename(void);
/* ------------------------------------------------------------------------ */
/* 模块内部变量声明。                                                       */
/* ------------------------------------------------------------------------ */
/*
#ifdef MRE_SYS_DRIVER_REMAPPING
static char *white_list[] = {
	"bill.dat",
	"mre.cfg",
	"mre.log",
	"channel.dat",
	"timestamp.dat",
	"user.dat",
	"vipuser.dat",
	"mre.conf",
	"vmsim.conf",
	"dsm.ini",
	"update.ini"
};
#define WHITE_LIST_NUM	9
#endif
*/
/*
#define FILE_POOL_SIZE 	MRE_SUPPORT_FILE_HANDLE_MAX_NUM

struct file_handle_t 
{
	int used;
	int file;
	int sys_state;
};
*/


extern VMINT	cur_file_sys_per;

VMINT _vm_remap_usr_disk(VMWSTR dest_filename, VMWSTR source_filename);

VMINT vm_file_count(void)
{
	VM_P_HANDLE phandle = -1;
	VMINT count = 0;

	phandle = vm_pmng_get_current_handle();
	count = vm_res_get_data_list_count_by_proecss(phandle, VM_RES_TYPE_FILE);
	return count;
}


static VMFILE _vm_file_open_internal(const VMWSTR filename, VMUINT mode, VMUINT binary, VMINT is_remap)
{
	VM_P_HANDLE phandle;
	VMINT mtk_file_id;
	VMINT handle;
	VMUINT flag = 0;
	//VMCHAR fn[60];
	VMINT len;
	VMWSTR fn_open;
	
	if (filename == NULL)
	{
		return VM_FILE_NAME_ERROR;
	}
	
	len = vm_wstrlen(filename);
	if (len == 0 || len > MAX_APP_NAME_LEN)
	{
		return VM_FILE_NAME_ERROR;
	}
	
	//vm_ucs2_to_gb2312(fn, 60, filename);
	
	phandle = vm_pmng_get_current_handle();
	handle = vm_res_save_data(VM_RES_TYPE_FILE, NULL, 0, NULL, phandle);
	
	//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_246 , mode, phandle, fn);

	if (handle >= 0) 
	{
		if (mode & MODE_READ)
			flag = FS_READ_ONLY;
		else if (mode & MODE_WRITE)
			flag = FS_READ_WRITE;
		else if (mode & MODE_APPEND)
			flag = FS_READ_WRITE;
		else if (mode & MODE_CREATE_ALWAYS_WRITE)
			flag = FS_CREATE_ALWAYS | FS_READ_WRITE;

		if (!is_remap)
			fn_open= (VMWSTR)filename;
		else
		{
			fn_open = vm_malloc(REMAP_FILENAME_MAX_LEN * sizeof(VMWCHAR));
			if (fn_open == NULL)
			{
				//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1160 );
				vm_res_release_data(VM_RES_TYPE_FILE, handle);
				return VM_FILE_NAME_ERROR;
			}
			
			if (_vm_remap_usr_disk((VMWSTR)fn_open, (VMWSTR)filename) == FALSE)
			{
				//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1167 );
				vm_free(fn_open);
				vm_res_release_data(VM_RES_TYPE_FILE, handle);
				return VM_FILE_NAME_ERROR;
			}
		}

		mtk_file_id = FS_Open((WCHAR*)fn_open, flag);
		if (mtk_file_id >= 0)
		{			
			if (vm_res_set_mtk_reshandle(VM_RES_TYPE_FILE, handle, mtk_file_id) == VM_RES_OK)
			{
				if (mode & MODE_APPEND)
				{
					FS_Seek(mtk_file_id, 0, FS_FILE_END);
				}
			}
			else
			{
				MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_272 , mtk_file_id);
				FS_Close(mtk_file_id);
				vm_res_release_data(VM_RES_TYPE_FILE, handle);
				handle = VM_FILE_OPEN_ERROR;
			}
		}
		else 
		{
			MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_280 , mtk_file_id);
			vm_res_release_data(VM_RES_TYPE_FILE, handle);
			handle = VM_FILE_OPEN_ERROR;
		}

		if (is_remap)
			vm_free(fn_open);
	}
	else 
	{
		MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_287 , handle);
		handle = VM_FILE_OPEN_ERROR;
	}

	MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_291 , mode, phandle, handle);
	return handle;
}


VMFILE vm_file_open(const VMWSTR filename, VMUINT mode, VMUINT binary) 
{
	return _vm_file_open_internal(filename, mode, binary, 0);
}

void vm_file_close_in_user_state(void)
{
	/**
	VMINT i = 0;
	for (i = 0; i < FILE_POOL_SIZE; i++) 
	{
		if ((file_pool[i].used == TRUE) && (file_pool[i].sys_state == SYS_STATE_USER)) 
		{
	    		FS_Close(file_pool[i].file);
			file_pool[i].used = FALSE;	
			file_pool[i].sys_state = SYS_STATE_KERNEL;
	  	}
	}**/
}

void vm_file_close_all(void)
{
	VM_P_HANDLE phandle;
	VMINT file_id;
	VMINT mtk_file_id = -1;
	
	phandle = vm_pmng_get_current_handle();
	
	while((file_id = vm_res_findfirst(phandle, VM_RES_TYPE_FILE)) != VM_RES_NOT_FIND)
	{
		if (vm_res_get_mtk_reshandle(VM_RES_TYPE_FILE, file_id, &mtk_file_id) == VM_RES_OK)
		{		
			FS_Close(mtk_file_id);
			vm_res_release_data(VM_RES_TYPE_FILE, file_id);
		}
		vm_res_findclose(VM_RES_TYPE_FILE);
	}
	
}

void vm_file_close(VMFILE handle) 
{
	VMINT mtk_file_id = -1;

	MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_335 , handle);
	
	if (vm_res_get_mtk_reshandle(VM_RES_TYPE_FILE, handle, &mtk_file_id) == VM_RES_OK)
	{
		MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_339 , handle, mtk_file_id);
		FS_Close(mtk_file_id);	
		vm_res_release_data(VM_RES_TYPE_FILE, handle);
	}
	
	MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_344 , handle);
}

VMINT vm_file_read(VMFILE handle, void * data, VMUINT length, VMUINT *nread) 
{
	VMINT mtk_file_id = -1;
	
	if (nread == NULL)
		return 0;

	*nread = 0;
	if (data != NULL)
	{
		if (vm_res_get_mtk_reshandle(VM_RES_TYPE_FILE, handle, &mtk_file_id) == VM_RES_OK)
		{
			if (FS_Read(mtk_file_id, data, length, (UINT *)nread) < FS_NO_ERROR)
			{
				*nread = 0;
			}
		}
	}
	return *nread;
}

VMINT vm_file_write(VMFILE handle, void * data, VMUINT length, VMUINT * written) 
{
	VMINT mtk_file_id = -1;
	
	if(written == NULL)
	{
		return 0;
	}
	
	*written = 0;

	if (data != NULL)
	{
		if (vm_res_get_mtk_reshandle(VM_RES_TYPE_FILE, handle, &mtk_file_id) == VM_RES_OK)
		{
			if (FS_Write(mtk_file_id, data, length, (UINT *)written) < FS_NO_ERROR)
			{
				*written = 0;
			}
		}
	}

	return *written;
}

VMINT vm_file_commit(VMFILE handle) 
{
	VMINT mtk_file_id = -1;

	if (vm_res_get_mtk_reshandle(VM_RES_TYPE_FILE, handle, &mtk_file_id) == VM_RES_OK)
	{
		if (FS_Commit(mtk_file_id) == FS_NO_ERROR)
		{
			return VM_FILE_OK;
		}

	}

	return VM_FILE_COMMIT_ERROR;
}

VMINT vm_file_is_eof(VMFILE handle)
{
	VMUINT filesize = 0;
	VMINT pos;
	VMINT mtk_file_id = -1;
	if (vm_res_get_mtk_reshandle(VM_RES_TYPE_FILE, handle, &mtk_file_id) == VM_RES_OK)
	{
		pos = FS_Seek(mtk_file_id, 0, FS_FILE_CURRENT);
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_418 , pos);
		FS_GetFileSize(mtk_file_id, &filesize);
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_420 , filesize);
		if ((VMUINT)pos == (VMUINT)filesize)
			return TRUE;
	}
	return FALSE;
}

VMINT vm_file_tell(VMFILE handle)
{
	VMINT ret = -1;
	VMINT mtk_file_id = -1;
	if (vm_res_get_mtk_reshandle(VM_RES_TYPE_FILE, handle, &mtk_file_id) == VM_RES_OK)
	{
		ret = FS_Seek(mtk_file_id, 0, FS_FILE_CURRENT);
	}
	return ret;
}

VMINT vm_file_seek(VMFILE handle, VMINT offset, VMINT base) 
{
	VMINT origin;
	VMINT retval = -1;
	VMUINT filesize = 0;
	VMINT current;

	VMINT mtk_file_id = -1;


	if (vm_res_get_mtk_reshandle(VM_RES_TYPE_FILE, handle, &mtk_file_id) == VM_RES_OK)
	{

		FS_GetFileSize(mtk_file_id, (UINT *) &filesize);

		if (base == BASE_BEGIN)
		{
			if ((offset > (VMINT)filesize) || (offset < 0) )
				return -1;
		}
		else if (base == BASE_END)
		{
			if ((offset > 0) || ((offset < 0) && (filesize < (VMUINT)(-offset))))
				return -1;
		}
		else if (base == BASE_CURR)
		{
			current = FS_Seek(mtk_file_id, 0, FS_FILE_CURRENT);
			if (((current+offset) > (VMINT)filesize) || ((current+offset) < 0) )
				return -1;
		}

		switch (base) 
		{
		case BASE_BEGIN:
			origin = FS_FILE_BEGIN;
			break;
		case BASE_CURR:
			origin = FS_FILE_CURRENT;
			break;
		case BASE_END:
			origin = FS_FILE_END;
			break;
		default :
			origin = FS_FILE_BEGIN;
			break;
		}
		 
		retval =  FS_Seek(mtk_file_id, offset, origin) < 0 ? -1 : 0;
	}

	return retval;
}

VMINT vm_file_getfilesize(VMFILE handle, VMUINT *file_size) 
{
	VMINT retval = -1;
	VMINT mtk_file_id = -1;
	if (file_size == NULL)
	{
		return -1;
	}
	
	if (vm_res_get_mtk_reshandle(VM_RES_TYPE_FILE, handle, &mtk_file_id) == VM_RES_OK)
	{
		retval =  FS_GetFileSize(mtk_file_id, (UINT *)file_size);
	}
	return retval;
}

VMINT vm_file_delete(const VMWSTR filename) 
{
	S32  attr;
	VMINT retval;
	VMINT len;
	if (filename == NULL)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_518 );
		return -1;
	}
	len = vm_wstrlen(filename);
	if (len == 0 || len > MAX_APP_NAME_LEN)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_523 );
		return -1;
	}
	attr = FS_GetAttributes((WCHAR *)filename);
    	if ((attr & FS_ATTR_READ_ONLY))
		FS_SetAttributes((WCHAR *)filename, (U8) (attr & ~(FS_ATTR_READ_ONLY)));

	retval =  FS_Delete((WCHAR *)filename) != FS_NO_ERROR ? -1: 0;
	if (retval != 0)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_533 , retval);
	}
	return retval;
}

VMINT vm_file_rename(const VMWSTR filename, const VMWSTR newname) 
{
	VMINT retval = -1;
	VMINT len1, len2;
	if (filename == NULL || newname == NULL)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_543 );
		return -1;
	}
	len1 = vm_wstrlen(filename);
	len2 = vm_wstrlen(newname);
	if (len1 == 0 
		|| len1 > MAX_APP_NAME_LEN
		|| len2 == 0 
		|| len2 > MAX_APP_NAME_LEN
	)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_552 );
		return -1;
	}
	
	retval =  FS_Rename((WCHAR *)filename, (WCHAR *)newname) != FS_NO_ERROR ? -1: 0;
	if (retval != 0)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_559 , retval);
	}
	return retval;
}


VMINT vm_file_mkdir(const VMWSTR dirname) 
{
	VMINT retval;
        VMINT len;
	//char fn[128];
	if (dirname == NULL)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_571 );
		return -1;
	}
	len = vm_wstrlen(dirname);
	if (len == 0 || len > MAX_APP_NAME_LEN)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_576 );
		return -1;
	}

	//memset(fn, 0x00, 128);
	//vm_ucs2_to_gb2312(fn, 128, dirname);
	//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_582 , fn);
	
	retval =  FS_CreateDir((WCHAR *)dirname) != FS_NO_ERROR ? -1: 0;
	if (retval != 0)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_587 , retval);
	}
	return retval;
}

VMINT vm_file_rmdir(const VMWSTR dirname) 
{
	VMINT retval;
        VMINT len;
	if (dirname == NULL)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_597 );
		return -1;
	}
	len = vm_wstrlen(dirname);
	if (len == 0 || len > MAX_APP_NAME_LEN)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_602 );
		return -1;
	}
	
	//retval =  FS_RemoveDir((WCHAR *)dirname) != FS_NO_ERROR ? -1: 0;
	retval= FS_XDelete(
                (const WCHAR *)dirname,
                FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE,
                NULL,
                0) < 0 ? -1:0;
	
	if (retval < 0)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_615 , retval);
	}
	return retval;
}

VMINT vm_file_set_attributes(const VMWSTR filename, VMBYTE attributes)
{
	VMINT res;
	if (filename == NULL)
		return -1;
	
	res = FS_SetAttributes((WCHAR *)filename, attributes);
	if (res != FS_NO_ERROR)
		return -1;

	return 0;
}

VMINT vm_file_get_attributes(const VMWSTR filename)
{
	VMINT res;
	if (filename == NULL)
		return -1;

	res = FS_GetAttributes((WCHAR *)filename);
	if (res < 0 )
		return -1;
	return res;
}

static void _vm_convert_time(vm_time_t *datetime_dst, const FS_DOSDateTime *datetime_src)
{
	datetime_dst->year = 1980 + datetime_src->Year1980;
	datetime_dst->mon = datetime_src->Month;
	datetime_dst->day = datetime_src->Day;
	datetime_dst->hour = datetime_src->Hour;
	datetime_dst->min = datetime_src->Minute;
	datetime_dst->sec = datetime_src->Second2 * 2;
}

static void _vm_fill_dir_entry(vm_fileinfo_ext * direntry, FS_DOSDirEntry *file_info)
{
	memcpy((VMCHAR *)(direntry->filename), (VMCHAR *)(file_info->FileName), 8);
	memcpy((VMCHAR *)(direntry->extension), (VMCHAR *)(file_info->Extension), 3);
	direntry->attributes = file_info->Attributes;
	direntry->drive = file_info->Drive;
	direntry->filesize = file_info->FileSize;
	direntry->stamp = file_info->Stamp;
	
	_vm_convert_time(&(direntry->create_datetime), &(file_info->CreateDateTime));
	_vm_convert_time(&(direntry->modify_datetime), &(file_info->DateTime));
}

static VMWSTR _vm_alloc_remap_name(VMWSTR fn)
{
	VMWSTR remap_name;
	
	remap_name = vm_malloc(REMAP_FILENAME_MAX_LEN * sizeof(VMWCHAR));
	if (remap_name)
	{
		if (_vm_remap_usr_disk((VMWSTR)remap_name, fn) == FALSE)
		{
			//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1542 );
			vm_free(remap_name);
			return NULL;
		}
	}
	
	return remap_name;
}

static VMINT _vm_find_first_internal(VMWSTR pathname, void *info, VMINT is_ext, VMINT is_remap)
{
	VMINT handle;
	VMINT mtk_handle;
	FS_DOSDirEntry	file_info;
	VM_P_HANDLE phandle;
	WCHAR *filename;
	VMINT len;
	VMWSTR pn;

	if (pathname == NULL)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_659 );
		return -1;
	}

	len = vm_wstrlen(pathname);
	if (len == 0 || len > MAX_APP_NAME_LEN)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_664 );
		return -1;
	}	
	
	if (!is_remap)
		pn = pathname;
	else
	{
		pn = _vm_alloc_remap_name((VMWSTR)pathname);
		if (pn == NULL)
		{
			//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1328 );
			return -1;
		}
	}

	phandle = vm_pmng_get_current_handle();
	handle = vm_res_save_data(VM_RES_TYPE_FILE_FIND, NULL, 0, NULL,  phandle);
	if (handle < 0)
	{
		if (is_remap)
			vm_free(pn);

		return -1;
	}

	if (is_ext)
		filename = (WCHAR *)(((vm_fileinfo_ext *)info)->filefullname);
	else
		filename = (WCHAR *)(((struct vm_fileinfo_t *)info)->filename);
	mtk_handle = FS_FindFirst((WCHAR *)pn, 0, 0, &file_info, filename, MAX_APP_NAME_LEN * 2);
	if (mtk_handle >= 0) 
	{
		////MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_680 , handle, fn);
		if (vm_res_set_mtk_reshandle(VM_RES_TYPE_FILE_FIND, handle, mtk_handle) == VM_RES_OK)
		{
			if (is_ext)
				_vm_fill_dir_entry((vm_fileinfo_ext *)info, &file_info);
			else
				((struct vm_fileinfo_t *)info)->size = file_info.FileSize;
		}
		else
		{
			FS_FindClose(mtk_handle);
			vm_res_release_data(VM_RES_TYPE_FILE_FIND, handle);
			handle = -1;
		}
	}
	else
	{
		vm_res_release_data(VM_RES_TYPE_FILE_FIND, handle);
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_719 , handle);
		handle = -1;
	}

	if (is_remap)
		vm_free(pn);

	return handle;
}
VMINT vm_find_first_ext(VMWSTR pathname, vm_fileinfo_ext * direntry)  
{
	if (direntry == NULL)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_659 );
		return -1;
	}

	memset(direntry, 0x00, sizeof(vm_fileinfo_ext));
	return _vm_find_first_internal(pathname, direntry, 1, 0);
}

VMINT vm_find_next_ext(VMINT handle, vm_fileinfo_ext * direntry)
{
	VMINT retval;
	FS_DOSDirEntry file_info;
	VMINT mtk_handle;
	//VMCHAR fn[128];

	if ( direntry == NULL)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_733 );
		return -1;
	}

	if (vm_res_get_mtk_reshandle(VM_RES_TYPE_FILE_FIND, handle, &mtk_handle) == VM_RES_OK)
	{
		memset(direntry, 0x00, sizeof(vm_fileinfo_ext));
		if ((retval = FS_FindNext(mtk_handle, &file_info, (WCHAR*)(direntry->filefullname), MAX_APP_NAME_LEN * 2)) == FS_NO_ERROR) 
		{
			//vm_ucs2_to_gb2312((VMSTR)fn, 100, (VMWCHAR *)(direntry->filefullname));
			////MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_743 , handle, fn);	
			_vm_fill_dir_entry(direntry, &file_info);
		}
		else
		{
			//info->size = 0;
			//memset(direntry, 0x00, sizeof(vm_fileinfo_ext));
			//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_771 , retval, handle);
			return -1;
		}	
	}
	else 
	{
		return -1;
	}
	return retval;
}

void vm_find_close_ext(VMINT handle)
{
	vm_find_close(handle);
}

VMINT vm_find_first(VMWSTR pathname, struct vm_fileinfo_t* info) 
{
	//MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMIO_793 );
	if (info == NULL)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_796 );
		return -1;
	}

	return _vm_find_first_internal(pathname, info, 0, 0);
}


VMINT vm_find_next(VMINT handle, struct vm_fileinfo_t* info) 
{
	VMINT retval;
	FS_DOSDirEntry file_info;
	VMINT mtk_handle = -1;
	//MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMIO_844 );
	if (vm_res_get_mtk_reshandle(VM_RES_TYPE_FILE_FIND, handle, &mtk_handle) == VM_RES_OK)
	{
		if ((retval = FS_FindNext(mtk_handle, &file_info, (WCHAR*)info->filename, MAX_APP_NAME_LEN * 2)) == FS_NO_ERROR) 
		{
			info->size = file_info.FileSize;
		}
		else
		{
			//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_853 , retval);
		}	
	}
	else
	{
		return -1;
	}
	return retval;
}

void vm_find_close(VMINT handle) 
{
	VMINT mtk_handle = -1;
    //VMINT retval = -1;
	if (vm_res_get_mtk_reshandle(VM_RES_TYPE_FILE_FIND, handle, &mtk_handle) == VM_RES_OK)
	{
		
		FS_FindClose(mtk_handle);
		vm_res_release_data(VM_RES_TYPE_FILE_FIND, handle);
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
		#endif
	}
	//return retval;
}

VMINT vm_get_removeable_driver(void) 
{
	if (FS_GetDevStatus((unsigned int)FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, 	FS_NO_ALT_DRIVE), FS_MOUNT_STATE_ENUM) == FS_NO_ERROR)	
		return FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
	return -1;
}

VMINT vm_get_system_driver(void) 
{
	return FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL);
}

VMINT vm_get_nvram_driver(void)
{
	return FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, 
		FS_DRIVE_I_SYSTEM | FS_DRIVE_V_NORMAL);
}

/*
#ifdef MRE_SYS_DRIVER_REMAPPING
VMINT in_white_list(VMWSTR filename) {
	int i;
	VMWCHAR filepart[128];

	for (i = 0; i < WHITE_LIST_NUM; i++)
	{
		vm_get_filename(filename, filepart);
		if (vm_wstrcmp(filepart, vm_ucs2_string(white_list[i])) == 0)
		{
			return 1;
		}
	}

	return 0;
}


VMWSTR file_remap(VMWSTR filename) {
	static VMWCHAR fn[128];

	vm_safe_wstrcpy(fn, 128, filename);
	if (fn[0] == vm_get_system_driver() && !in_white_list(fn))
	{
		fn[0] = vm_get_removeable_driver();
		////MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_931 , vm_gb2312_string(filename));
		////MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_932 , vm_gb2312_string(fn));
	}

	return fn;
}
#endif
*/

VMUINT vm_get_disk_free_space(VMWSTR drv_name)
{
	VMUINT free_space = 0;
	VMINT fs_handle;
	FS_DiskInfo	disk_info;
	VMCHAR temp[4];
	VMCHAR drv_asc[10];
	VMWCHAR drv_ucs[10];

	if (drv_name == NULL)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_951 );
		return 0;
	}

	if (vm_wstrlen(drv_name) != 1)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_957 );
		return 0;
	}

	//vm_ucs2_to_gb2312(temp, 4, drv_name);	
	vm_ucs2_to_ascii(temp, 4, drv_name);
	
	////MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_964 , temp);
	sprintf(drv_asc, "%s:\\", temp);
	if ((drv_asc[0] > 'a' && drv_asc[0] < 'z') ||(drv_asc[0] > 'A' && drv_asc[0] < 'Z'))
	{
		////MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_968 , drv_asc);
		//vm_gb2312_to_ucs2(drv_ucs, 10, drv_asc);
		vm_ascii_to_ucs2(drv_ucs, 10, drv_asc);

		fs_handle = FS_GetDiskInfo((WCHAR *)drv_ucs, &disk_info, FS_DI_BASIC_INFO|FS_DI_FREE_SPACE);
			
		if(fs_handle >= 0)
		{
			//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_976 , disk_info.FreeClusters, disk_info.SectorsPerCluster, disk_info.BytesPerSector);
			//free_space = disk_info.FreeClusters*disk_info.SectorsPerCluster*disk_info.BytesPerSector;
                    VMUINT64 temp = disk_info.FreeClusters*disk_info.SectorsPerCluster*disk_info.BytesPerSector;
                    
                    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_980 , (VMUINT32)((temp >> 32) & 0xFFFFFFFF), ((VMUINT32)temp & 0xFFFFFFFF));

                    free_space = (VMUINT32)(temp >> 32);
                    if (free_space)
                    {
                        MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_985 );
                        return 0xFFFFFFFF;
                    }
                    free_space = disk_info.FreeClusters*disk_info.SectorsPerCluster*disk_info.BytesPerSector;
                    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_989 );
		}
		else
		{
			//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_993 );
		}
	}
	else
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_998 );
		return 0;
	}

	return free_space;
}

VMINT vm_get_disk_info(const VMCHAR * drv_name, vm_fs_disk_info * fs_disk, vm_fs_di_enum e_di)
{
    return (VMINT)FS_GetDiskInfo((WCHAR *)drv_name, (FS_DiskInfo *)fs_disk, (int)e_di);
}

#include "DevConfigDef.h"
VMINT vm_is_support_pen_touch(void)
{
/*
#ifdef MRE_SUPPORT_SCREEN_TOUCH
	return TRUE;
#else
	return FALSE;
#endif
*/
	if(sysconf.input_device.touch_screen)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

VMINT vm_is_support_keyborad(void)
{
/*
#ifdef MRE_SUPPORT_TOTAL_KEYPAD
	return TRUE;
#else
	return FALSE;
#endif
*/
	if(sysconf.input_device.keypad_type == MMI_DEVCONFIG_KEYPAD_TYPE_NORMAL 
		|| sysconf.input_device.keypad_type == MMI_DEVCONFIG_KEYPAD_TYPE_QWERTY)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

VMINT vm_is_finger_touch_version(void)
{
	return sysconf.input_device.figner_touch_support;
}

VMINT vm_is_support_gsensor(void)
{
	return sysconf.remote_sensing.motion_sensor;
}

VMINT vm_file_get_modify_time(const VMWSTR filename, vm_time_t * modify_time)
{
	char full_name[MAX_APP_NAME_LEN];
	FS_DOSDirEntry entry;
	FS_FileInfo finfo;
	FS_HANDLE fshandle;
	//char fn[128];
	VMINT len;

	VMINT retval = -1;
	
	//MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMIO_1070 );
	if (filename == NULL || modify_time == NULL)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1073 );
		return -1;
	}
        len = vm_wstrlen(filename);
	if (len == 0 || len > MAX_APP_NAME_LEN)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1079 );
		return -1;
	}
	
	//vm_ucs2_to_gb2312(fn, 128, filename);
	//MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMIO_1084 , fn);
	
	
	fshandle = FS_Open((WCHAR *)filename, FS_READ_ONLY);
	if (fshandle > 0)
	{
		//MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMIO_1090 );
		finfo.DirEntry = &entry;
		finfo.FullName = full_name;
		if (FS_GetFileInfo(fshandle, &finfo) == FS_NO_ERROR)
		{
			//MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMIO_1095 );
			//memset(modify_time, 0x00, sizeof(vm_time_t)); // useless memset
			_vm_convert_time(modify_time, &(finfo.DirEntry->DateTime));
			retval = 0;
			//MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMIO_1104 ); 
		}
		else
		{
			retval = -1;
			//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1109 ); 
		}
		FS_Close(fshandle);
	}
	else
	{
		retval = -1;
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1116 ); 
	}
	//MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMIO_1118 );
	return retval;
}



VMFILE vm_file_open_remap(const VMWSTR filename, VMUINT mode, VMUINT binary) 
{
	return _vm_file_open_internal(filename, mode, binary, 1);
}


VMINT vm_file_delete_remap(const VMWSTR filename) 
{
	VMINT retval = -1;	
	VMWCHAR *remap_filename;
	S32 attr;
        VMINT len;
	if (filename == NULL)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1208 );
		return -1;
	}
        len = vm_wstrlen(filename);
	if (len == 0 || len > MAX_APP_NAME_LEN)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1213 );
		return -1;
	}
	
	remap_filename = _vm_alloc_remap_name((VMWSTR)filename);
	
	if (remap_filename == NULL)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1221 );
		return -1;
	}

	attr = FS_GetAttributes((WCHAR *)remap_filename);
    	if ((attr & FS_ATTR_READ_ONLY))
		FS_SetAttributes((WCHAR *)remap_filename, (U8) (attr & ~(FS_ATTR_READ_ONLY)));
		
	retval =  FS_Delete((WCHAR *)remap_filename) != FS_NO_ERROR ? -1:0;	
	if (retval != 0)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1238 , retval);
	}
	
	vm_free(remap_filename);
	return retval;
}

VMINT vm_file_rename_remap(const VMWSTR filename, const VMWSTR newname) 
{
	VMINT retval = -1;
	VMWCHAR *remap_filename;
	VMWCHAR *remap_newname;
	VMINT len1, len2;
	if (filename == NULL || newname == NULL)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1253 );
		return -1;
	}
	len1 = vm_wstrlen(filename);
	len2 = vm_wstrlen(newname);
	if (len1 == 0 
		|| len1 > MAX_APP_NAME_LEN
		|| len2 == 0 
		|| len2 > MAX_APP_NAME_LEN
	)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1262 );
		return -1;
	}

	remap_filename = _vm_alloc_remap_name((VMWSTR)filename);
	if (remap_filename == NULL)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1269 );
		return -1;
	}
	
	remap_newname = _vm_alloc_remap_name((VMWSTR)newname);
	if (remap_newname == NULL)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1276 );
		vm_free(remap_filename);
		return -1;
	}

	retval = (FS_Rename((WCHAR *)remap_filename, (WCHAR *)remap_newname)) != FS_NO_ERROR ? -1:0;

	if (retval != 0)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1295 , retval);
	}
	
	vm_free(remap_filename);
	vm_free(remap_newname);
	return retval;
}


VMINT vm_find_first_remap_ext(VMWSTR pathname, vm_fileinfo_ext * direntry) 
{
	return _vm_find_first_internal(pathname, direntry, 1, 1);
}


VMINT vm_find_first_remap(VMWSTR pathname, struct vm_fileinfo_t* info) 
{
	return _vm_find_first_internal(pathname, info, 0, 1);
}


VMINT vm_file_mkdir_remap(const VMWSTR dirname) 
{
	VMINT retval = -1;
	VMWCHAR *remap_dirname;
	//char fn[128];
        VMINT len;
	//memset(fn, 0x00, 128);
	//vm_ucs2_to_gb2312(fn, 128, dirname);
	//MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMIO_1479 , fn);

	if (dirname == NULL)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1483 );
		return -1;
	}
	len = vm_wstrlen(dirname);
	if (len == 0 || len > MAX_APP_NAME_LEN)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1488 );
		return -1;
	}
	
	remap_dirname = _vm_alloc_remap_name((VMWSTR)dirname);
	if (remap_dirname == NULL)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1495 );
		return -1;
	}
	
	retval =  FS_CreateDir((WCHAR *)remap_dirname) != FS_NO_ERROR ? -1:0;

	if (retval != 0)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1510 , retval);
	}
	
	vm_free(remap_dirname);
	return retval;
}

VMINT vm_file_rmdir_remap(const VMWSTR dirname) 
{
	VMINT retval = -1;
	VMWCHAR *remap_dirname;
        VMINT len;
	if (dirname == NULL)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1524 );
		return -1;
	}
	len = vm_wstrlen(dirname);
	if (len == 0 || len > MAX_APP_NAME_LEN)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1529 );
		return -1;
	}
	
	remap_dirname = _vm_alloc_remap_name((VMWSTR)dirname);
	if (remap_dirname == NULL)
	{
		return -1;
	}
	
	//retval =  FS_RemoveDir((WCHAR *)remap_dirname) != FS_NO_ERROR ? -1:0;

	retval = FS_XDelete(
                (const WCHAR *)remap_dirname,
                FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE,
                NULL,
                0) < 0 ? -1:0;

	if (retval < 0)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1557 , retval);
	}
	
	vm_free(remap_dirname);
	return retval;
}

VMINT vm_file_set_attributes_remap(const VMWSTR filename, VMBYTE attributes)
{
	VMINT retval = -1;
	VMWCHAR *remap_dirname;

	if (filename == NULL)
		return -1;

	remap_dirname = _vm_alloc_remap_name((VMWSTR)filename);
	if (remap_dirname == NULL)
	{
		return -1;
	}
	
	retval = FS_SetAttributes((WCHAR *)remap_dirname, attributes);
	if (remap_dirname)
		vm_free(remap_dirname);

	if (retval != FS_NO_ERROR)
		retval = -1;
	else
		retval = 0;
	
	return retval;
	
}

VMINT vm_file_get_attributes_remap(const VMWSTR filename)
{
	VMINT retval = -1;
	VMWCHAR *remap_dirname;

	if (filename == NULL)
		return -1;

	remap_dirname = _vm_alloc_remap_name((VMWSTR)filename);
	if (remap_dirname == NULL)
	{
		return -1;
	}

	retval = FS_GetAttributes((WCHAR *)remap_dirname);
	
        if (remap_dirname)
            vm_free(remap_dirname);
	if (retval < 0 )
		return -1;
	return retval;
	
}


static VMINT _vm_create_current_app_drv(VMSTR app_path_str, VMCHAR app_drv)
{
	VMINT retval = FALSE;
	VMUINT i;
	VMWCHAR *app_wpath;
	VMCHAR *temp_fn;
	VMCHAR *temp_dir;
	
	app_wpath = vm_malloc(REMAP_FILENAME_MAX_LEN * sizeof(VMWCHAR));
	if (app_wpath == NULL)
		return FALSE;
	temp_fn = vm_malloc(REMAP_FILENAME_MAX_LEN * sizeof(VMCHAR));
	if (temp_fn == NULL)
	{
		vm_free(app_wpath);
		return FALSE;
	}
	temp_dir = vm_malloc(REMAP_FILENAME_MAX_LEN * sizeof(VMCHAR));
	if (temp_dir == NULL)
	{
		vm_free(app_wpath);
		vm_free(temp_fn);
		return FALSE;
	}

	
	if (vm_get_exec_filename((VMWSTR)app_wpath) != 0)
	{
		vm_free(app_wpath);
		vm_free(temp_fn);
		vm_free(temp_dir);
		/*means current context in engine*/
		retval = FALSE;
	}
	else
	{
        VMINT tmp_len = 0;
		//vm_ucs2_to_gb2312((VMSTR)temp_fn, REMAP_FILENAME_MAX_LEN, (VMWSTR)app_wpath);
		vm_ucs2_to_ascii((VMSTR)temp_fn, REMAP_FILENAME_MAX_LEN, (VMWSTR)app_wpath);
		/*create folder of same name as application*/		
		memset(temp_dir, 0x00, REMAP_FILENAME_MAX_LEN);

        tmp_len = strlen(temp_fn);
		for(i = tmp_len; i > 0; i--)
		{
			if(temp_fn[i] == '.')
			{
				break;
			}
			//temp_dir[i] = temp_fn[i];
		}
		//temp_dir[i] = '\0';
        memcpy(temp_dir, temp_fn, i);
		//vm_gb2312_to_ucs2((VMWSTR)app_wpath, REMAP_FILENAME_MAX_LEN * 2, (VMSTR)temp_dir);
		vm_ascii_to_ucs2((VMWSTR)app_wpath, REMAP_FILENAME_MAX_LEN * 2, (VMSTR)temp_dir);
		vm_file_mkdir((VMWSTR)app_wpath);
		/*create disk folder*/
		memset(temp_fn, 0x00, REMAP_FILENAME_MAX_LEN);
		if ((strlen(temp_dir) + 1) >= REMAP_FILENAME_MAX_LEN)
		{
			retval = FALSE;
		}
		else
		{
			sprintf(temp_fn, "%s\\%c", temp_dir, app_drv);
			//vm_gb2312_to_ucs2((VMWSTR)app_wpath, REMAP_FILENAME_MAX_LEN * 2, (VMSTR)temp_fn);
			vm_ascii_to_ucs2((VMWSTR)app_wpath, REMAP_FILENAME_MAX_LEN * 2, (VMSTR)temp_fn);
			vm_file_mkdir((VMWSTR)app_wpath);
			strcpy(app_path_str, temp_fn);	
			retval = TRUE;
		}
	}
	vm_free(app_wpath);
	vm_free(temp_fn);
	vm_free(temp_dir);
	return retval;
}


VMINT _vm_remap_usr_disk(VMWSTR dest_filename, VMWSTR source_filename)
{
	VMINT retval = FALSE;
	VMUINT i;
	VMUINT j;

	VMCHAR *temp_fn;
//	VMCHAR *temp_fn1; // unnecessary to use it
	VMCHAR drv;
	VMINT  has_drv = TRUE;

	VMCHAR temp_ch;
	VMCHAR *temp_str;

	VMCHAR *remap_app_path;
	VMINT len;

	
	//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1722 );
	
	if (dest_filename == NULL || source_filename == NULL)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1726 );
		return FALSE;
	}

	len = vm_wstrlen(source_filename);
	if ((len > REMAP_FILENAME_MAX_LEN) || (len == 0))
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1732 );
		return FALSE;
	}

	/*check access right*/
	if (_vm_get_disk_permission() == VM_PERMISSION_SYS_DRV)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1739 );
		vm_wstrcpy(dest_filename, source_filename);
		return TRUE;	
	}	
	else if (_vm_get_disk_permission() == VM_PERMISSION_USR_DRV)
	{		
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1745 );

		temp_fn = vm_malloc(REMAP_FILENAME_MAX_LEN * sizeof(VMCHAR));
		if (temp_fn == NULL)
			return FALSE;
/*		temp_fn1 = vm_malloc(REMAP_FILENAME_MAX_LEN * sizeof(VMCHAR));
		if (temp_fn1 == NULL)
		{
			vm_free(temp_fn);
			return FALSE;
		}*/
		temp_str = vm_malloc(REMAP_FILENAME_MAX_LEN * sizeof(VMCHAR));
		if (temp_str == NULL)
		{
//			vm_free(temp_fn1);
			vm_free(temp_fn);
			return FALSE;
		}
		remap_app_path = vm_malloc(REMAP_FILENAME_MAX_LEN * sizeof(VMCHAR));
		if (remap_app_path == NULL)
		{
			vm_free(temp_str);
//			vm_free(temp_fn1);
			vm_free(temp_fn);
			return FALSE;
		}
		
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1772 );

		//vm_ucs2_to_gb2312(temp_fn, REMAP_FILENAME_MAX_LEN, source_filename);
		vm_ucs2_to_ascii(temp_fn, REMAP_FILENAME_MAX_LEN, source_filename);
		temp_ch = temp_fn[1];
		if (temp_ch != ':')
		{
			drv = 'c';
			has_drv = FALSE;
		}
		else
		{
			drv = temp_fn[0];
			has_drv = TRUE;
		}
	
		if (_vm_create_current_app_drv((VMSTR)remap_app_path, drv) == TRUE)
		{
			//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1790 );
//			memset(temp_fn1, 0x00, REMAP_FILENAME_MAX_LEN);
			if (has_drv)
			{
				/*read from 3rd charater if there is disk character*/
				i = 3;
			}
			else
			{
				/*read from the first character from \ if without disk character*/
				i = 0;
				for(j = 0;  j < strlen(temp_fn); j++)
				{
					if (temp_fn[j] == '\\')
					{
						continue;
					}
					else
					{
						i = j;
						break;
					}
				}				
			}
/*			j = 0;
			for (; i < strlen(temp_fn); i++)
			{
				temp_fn1[j] = temp_fn[i];
				j++;
			}*/
			if ((strlen(remap_app_path) + strlen(&temp_fn[i]))< REMAP_FILENAME_MAX_LEN)
			{
				sprintf(temp_str, "%s\\%s", remap_app_path, (VMSTR)(&temp_fn[i]));
				//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1823 , temp_str);
				//vm_gb2312_to_ucs2(dest_filename, REMAP_FILENAME_MAX_LEN * 2, temp_str);
				vm_ascii_to_ucs2(dest_filename, REMAP_FILENAME_MAX_LEN * 2, temp_str);
				retval = TRUE;
			}
			else
			{
				retval = FALSE;
			}
		}
		vm_free(remap_app_path);
		vm_free(temp_str);
//		vm_free(temp_fn1);
		vm_free(temp_fn);
	}	
	//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1838 );
	return retval ;
}

VMINT _vm_get_disk_permission(void)
{
	return cur_file_sys_per;
}


static void vm_findfirst_process_state_pro(VM_P_HANDLE phandle, VMINT pro_state)
{
	VMINT i;
	
	switch(pro_state)
	{
		case VM_PMNG_UNLOAD:
			while ( (i = vm_res_findfirst(phandle, VM_RES_TYPE_FILE_FIND)) != VM_RES_NOT_FIND)
			{
				vm_find_close(i);
				//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1858 , i);
				vm_res_findclose(VM_RES_TYPE_FILE_FIND);
			}
			break;

	}
}

static void vm_file_process_state_pro(VM_P_HANDLE phandle, VMINT pro_state)
{
	VMINT i;
	
	switch(pro_state)
	{
		case VM_PMNG_UNLOAD:
			while ( (i = vm_res_findfirst(phandle, VM_RES_TYPE_FILE)) != VM_RES_NOT_FIND)
			{
				vm_file_close(i);
				//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1881 , i);
				vm_res_findclose(VM_RES_TYPE_FILE);
			}
			break;

	}
}

static void vm_io_initial(void)
{
	vm_res_type_set_notify_callback(VM_RES_TYPE_FILE, vm_file_process_state_pro);
	vm_res_type_set_notify_callback(VM_RES_TYPE_FILE_FIND, vm_findfirst_process_state_pro);
}

static void vm_io_finialize(void)
{
	VMINT i;

	while ( (i = vm_res_findfirst(-1, VM_RES_TYPE_FILE)) != VM_RES_NOT_FIND)
	{
		vm_file_close(i);
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1907 , i);
		vm_res_findclose(VM_RES_TYPE_FILE);
	}
	

	while ( (i = vm_res_findfirst(-1, VM_RES_TYPE_FILE_FIND)) != VM_RES_NOT_FIND)
	{
		vm_find_close(i);
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1915 , i);
		vm_res_findclose(VM_RES_TYPE_FILE_FIND);
	}
	
			
	vm_res_type_set_notify_callback(VM_RES_TYPE_FILE, NULL);
	vm_res_type_set_notify_callback(VM_RES_TYPE_FILE_FIND, NULL);
}

static VMINT vm_io_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
	switch(event)
	{
		case EVT_MOD_INIT:
			vm_io_initial();
			break;
 		case EVT_MOD_RELEASE:
			vm_io_finialize();
			break;
	}
	return 0;
}

VMINT _vm_reg_io_module(void)
{
	int res;

	if ((res = _vm_reg_module("IO MODULE", (MOD_EVT_PROCESS)vm_io_mod_evt_proc)) 
		!= REG_MRE_MODULE_SUCCESS)
	{
		//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1945 , res);
	}
	return res;
}

#include "vmpromnginner.h"
#include "FileMgrSrvGProt.h"
#define VM_STORAGE_MAX_SIZE (10240)
#define VM_STORAGE_SYSTEM_PATH L":\\@mrestorage\\"

VMINT vm_storage_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT drv;
    VMWCHAR * pathname;
    FS_HANDLE folder_hdl;
    FS_HANDLE file_hdl;
    VM_P_HANDLE proc_hdl;
    VMINT res_hdl;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1970 );
    drv = SRV_FMGR_SYSTEM_DRV; //FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL);
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1972 , drv);
    //drv = (VMINT)'Z';
    pathname = vm_malloc(REMAP_FILENAME_MAX_LEN * sizeof(VMWCHAR));
    pathname[0] = (VMWCHAR)drv;
    //mmi_wcscpy(&pathname[1], VM_STORAGE_SYSTEM_PATH);
    kal_wstrcpy((WCHAR *)&pathname[1], VM_STORAGE_SYSTEM_PATH);
    
    // allocating the res.
    proc_hdl = vm_pmng_get_current_handle();
    res_hdl = vm_res_save_data(VM_RES_TYPE_FILE, NULL, 0, NULL, proc_hdl);
    if (res_hdl < 0)
    {
        vm_free(pathname);
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1985 );
        return VM_STORAGE_ERR_RES;
    }

    // create if the path is not exist
    folder_hdl = FS_Open((const WCHAR *)pathname, FS_OPEN_DIR | FS_READ_ONLY);

    // the folder dose not exist!
    if (FS_NO_ERROR > folder_hdl)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_1995 );
        folder_hdl = FS_CreateDir((const WCHAR *)pathname);
        // create folder failure!
        if (FS_NO_ERROR > folder_hdl)
        {
            vm_res_release_data(VM_RES_TYPE_FILE, res_hdl);
            vm_free(pathname);
            MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_2002 );
            return VM_STORAGE_ERR_FILE_CREATE;
        }
        else
        {
            FS_Close(folder_hdl);
        }
    }
    else
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_2012 );
        FS_Close(folder_hdl);
    }
    

    //kal_wstrcat(pathname, name);
    
    kal_wsprintf((WCHAR *)&pathname[vm_wstrlen(pathname)], "%d", vm_pmng_current_app_id());

    // open if the file already existed, otherwise to create.
    file_hdl = FS_Open((const WCHAR *)pathname, FS_READ_WRITE);
    if (FS_NO_ERROR > file_hdl)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_2025 );
        file_hdl = FS_Open((const WCHAR *)pathname, FS_READ_WRITE | FS_CREATE);
    }

    // create file failure or the opening already failured.
    if (FS_NO_ERROR > file_hdl)
    {        
        vm_res_release_data(VM_RES_TYPE_FILE, res_hdl);
        vm_free(pathname);
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_2034 );
        return VM_STORAGE_ERR_FILE_CREATE;
    }

    // success.
    vm_free(pathname);
    if (VM_RES_OK != vm_res_set_mtk_reshandle(VM_RES_TYPE_FILE, res_hdl, file_hdl))
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_2042 );
        
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_2046 );

    return res_hdl;
    
}

void vm_storage_close(VMINT h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
    FS_HANDLE fs_hdl = -1;
    VMINT res_hdl = -1;
    VMINT res_ret = -1;
    VMINT ret = -1;
    */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 /*   ASSERT(h);

    res_hdl = h;

    res_ret = vm_res_get_mtk_reshandle(VM_RES_TYPE_FILE, res_hdl, (VMINT*)(&fs_hdl));
    ASSERT(VM_RES_OK == ret);
    
    ret = FS_Close(fs_hdl);

    res_ret = vm_res_release_data(VM_RES_TYPE_FILE, res_hdl);

    ASSERT(VM_RES_OK == ret);

    return ret;
*/
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_2081 );
    vm_file_close(h);
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_2083 );

}

VMINT vm_storage_read(VMINT h, void * data, VMUINT offset, VMUINT size, VMUINT * read)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_2095 );
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_2096 , h, data, offset, size, read);
    
    if (!data || (0 == size) || (0 == offset) || !read)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_2100 );
        return VM_STORAGE_ERR_PARAM;
    }
       
    if (VM_STORAGE_MAX_SIZE < (offset + size))
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_2106 );
        return VM_STORAGE_ERR_FILE_READ;
    }
    
    if (0 > vm_file_seek(h, offset, BASE_BEGIN))
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_2112 );
        return VM_STORAGE_ERR_FILE_SEEK;
    }

    if (0 >= vm_file_read(h, data, size, read))
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_2118 );
        return VM_STORAGE_ERR_FILE_READ;
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_2122 );
    return VM_STORAGE_ERR_NONE;
}

VMINT vm_storage_write(VMINT h, const void * data, VMUINT offset, VMUINT size, VMUINT * written)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_2135 );
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_2136 , h, data, offset, size, written);
    
    if (!data || (0 == size) || (0 == offset) || !written)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_2140 );
        return VM_STORAGE_ERR_PARAM;
    }
    if (VM_STORAGE_MAX_SIZE < (offset + size))
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_2145 );
        return VM_STORAGE_ERR_FILE_WRITE;
    }    

    if (0 > vm_file_seek(h, offset, BASE_BEGIN))
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_2151 );
        return VM_STORAGE_ERR_FILE_SEEK;
    }
    
    if (0 >= vm_file_write(h, (void*)data, size, written))
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_2157 );
        return VM_STORAGE_ERR_FILE_WRITE;
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_2161 );
    return VM_STORAGE_ERR_NONE;
}



#include "vmcert.h"
#include "vmgettag.h"

#if defined(__MRE_PACKAGE_SLIM__)
    #define MRE_SYS_FILE_APP_MAX_SIZE 10*2*1024 // default size.
#elif defined(__MRE_PACKAGE_NORMAL__)
    #define MRE_SYS_FILE_APP_MAX_SIZE 14*2*1024// default size.
#elif defined(__MRE_PACKAGE_FULL__)
    #define MRE_SYS_FILE_APP_MAX_SIZE 18*2*1024 // default size.
#endif

#define VM_SYS_FILE_SYSTEM_PATH L":\\@mresysfile\\"

extern const FS_QuotaStruct gFS_ExtQuotaSet[];

static VMINT g_pre_proc_b = MMI_FALSE;
static VMINT g_total_sys_file_size = MRE_SYS_FILE_APP_MAX_SIZE;

static VMINT vm_sys_file_internal_get_size(void);
static VMUINT vm_sys_file_internal_set_size(VMINT size);
static VMUINT vm_sys_file_internal_get_curr_file_size(void);
static VMINT vm_sys_file_internal_pre_process(void);
static VMINT vm_sys_file_internal_get_tag_size(void);

static VMWCHAR *_vm_alloc_and_constuct_sys_path(void)
{
    VMINT drv;
    VMWCHAR * pathname;

    drv = SRV_FMGR_SYSTEM_DRV; //FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL);
    pathname = vm_malloc(REMAP_FILENAME_MAX_LEN * sizeof(VMWCHAR));
    pathname[0] = (VMWCHAR)drv;
    kal_wstrcpy((WCHAR *)&pathname[1], VM_SYS_FILE_SYSTEM_PATH);
    kal_wsprintf((WCHAR *)&pathname[vm_wstrlen(pathname)], "%d", vm_pmng_current_app_id());

	return pathname;
}

VMFILE vm_sys_file_open(VMUINT mode, VMUINT binary)
{
    VMINT drv = 0;
    VMWCHAR * pathname = NULL;
    VMFILE file = -1;
    
    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2197 );
    
    if (0 > vm_sys_file_internal_pre_process())
    {
        return VM_SYS_FILE_ERR_AUTHORIZATION;
    }

    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2204 );
    /*
    if (0 >= vm_sys_file_internal_get_size())
    {
        return VM_SYS_FILE_ERR_DISK_FULL;
    }
    */
    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2211 );
    
    pathname = _vm_alloc_and_constuct_sys_path();
    
    if (0 > (file = vm_file_open(pathname, mode, binary)))
    {
        vm_free(pathname);
        return VM_SYS_FILE_ERR_FILE_OPEN;
    }

    
    vm_free(pathname);
    
    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2230 );

    return file;
}

VMINT vm_sys_file_seek(VMFILE handle, VMINT offset, VMINT base)
{
    VMINT ret = 0;
    
    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2239 );

    if (0 > handle)
        return VM_STORAGE_ERR_PARAM;
    
    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2244 , offset, base);
    
    ret = vm_file_seek(handle, offset, base);
    if (0 != (ret = vm_file_seek(handle, offset, base)))
    {
        return VM_SYS_FILE_ERR_FILE_SEEK;
    }
    
    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2252 );

    return ret;
}

VMINT vm_sys_file_read(VMFILE handle, void * data, VMUINT length, VMUINT *nread)
{
    VMINT ret = 0;
    
    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2261 );
    
    if ((0 > handle) || !data || (0 >= length ) || !nread)
    {
        return VM_STORAGE_ERR_PARAM;
    }
    
    if (0 >= (ret = vm_file_read(handle, data, length, nread)))
    {
        return VM_SYS_FILE_ERR_FILE_READ;
    }
    
    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2273 );
    
    return ret;
}

VMINT vm_sys_file_write(VMFILE handle, void * data, VMUINT length, VMUINT * written)
{
    VMINT size1, size2 = 0;
    VMINT ret = 0;
    VMINT pos;
    VMINT curr_size;

    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2286 );

    if ((0 > handle) || !data || (0 == length) || !written)
    {
        return VM_STORAGE_ERR_PARAM;
    }
    
    pos = vm_file_tell(handle);
    size1 = pos + length;
    curr_size = vm_sys_file_internal_get_curr_file_size();
    
    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2297 , pos, size1, curr_size);

    // the current write must enlarge the file size.
    if (size1 > curr_size)
    {
        // writable judgement.
        if (0 >= vm_sys_file_internal_get_size())
        {
            return VM_SYS_FILE_ERR_DISK_FULL;
        }

        // append part size
        size1 -= curr_size;

        size2 = vm_sys_file_internal_set_size(size1);
        MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2312 , size1, size2);
        if (0 > size2)
        {
            MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2315 , size2);
            return VM_SYS_FILE_ERR_AUTHORIZATION;
        }
        
        // partly write
        if (size2 < size1)
        {
            length -= (size1 - size2);
            ret = VM_SYS_FILE_ERR_FILE_WRITE_PARTLY;
        }

    }


    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2329 , length, size2);

    if (0 >= vm_file_write(handle, data, length, written))
    {
        return VM_SYS_FILE_ERR_FILE_WRITE;
    }

    
    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2337 );

    return ret;
}

void vm_sys_file_close(VMFILE h)
{
    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2344 );
    vm_file_close(h);
    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2346 );
}

VMINT vm_sys_file_delete(void)
{
    VMINT size;
    VMINT ret = 0;
    VMINT drv;
    VMWCHAR * pathname;

    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2356 );

    if (0 > vm_sys_file_internal_pre_process())
    {
        return VM_SYS_FILE_ERR_AUTHORIZATION;
    }
    
    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2363 );
    
    size = vm_sys_file_internal_get_curr_file_size();

    pathname = _vm_alloc_and_constuct_sys_path();

    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2373 , size);
    vm_sys_file_internal_set_size(-size);  

    ret = vm_file_delete(pathname);

    if (ret < 0)
    {
        vm_sys_file_internal_set_size(size);
        vm_free(pathname);
        return VM_SYS_FILE_ERR_FILE_DELETE;
    }

    vm_free(pathname);



    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2389 );
    
    return ret;
}

VMINT vm_sys_file_get_space(void)
{
    VMINT tag_buf = 0;
    VMINT tag_size = 4;
    VMINT rest_size = 0;
    VMINT curr_size = 0;
    
    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2401 );

    if (0 > vm_sys_file_internal_pre_process())
    {
        return VM_SYS_FILE_ERR_AUTHORIZATION;
    }

    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2408 );
    
    curr_size = vm_sys_file_internal_get_curr_file_size();
    
    tag_buf = vm_sys_file_internal_get_tag_size();
    if (0 > tag_buf)
    {
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMIO_2415 , tag_buf);
        return VM_SYS_FILE_ERR_AUTHORIZATION;
    }
    tag_buf *= 1024;
      
    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2420 , tag_buf, curr_size);

    // total rest is not enough
    if ((tag_buf - curr_size) > vm_sys_file_internal_get_size())
    {
        rest_size = vm_sys_file_internal_get_size();
    }
    else
    {
        rest_size = tag_buf - curr_size;
    }
    
    return rest_size;
}

static VMUINT vm_sys_file_internal_get_curr_file_size(void)
{
    VMWCHAR * pathname;
    VMINT finder;
    VMINT drv;
    struct vm_fileinfo_t info;
    
    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2443 );

    pathname = _vm_alloc_and_constuct_sys_path();

    finder = vm_find_first(pathname, &info);
    if (finder < 0)
    {
        vm_free(pathname);
        //vm_find_close(finder); // useless
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMIO_2455 );
        return 0;
    }

    vm_free(pathname);
    vm_find_close(finder);
    
    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2462 );

    return info.size;
}

static VMINT vm_sys_file_internal_get_size(void)
{
    return (VMINT)g_total_sys_file_size;
}

static VMUINT vm_sys_file_internal_set_size(VMINT size)
{
    VMINT tag_size;
    VMINT curr_size;

    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2481 , size); 
    
    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2483 , g_total_sys_file_size); 
    
    if (0 >= g_total_sys_file_size)
    {
        MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2487 , g_total_sys_file_size); 
        return 0;
    }

    curr_size = vm_sys_file_internal_get_curr_file_size();

    tag_size = vm_sys_file_internal_get_tag_size();
    if (0 >= tag_size)
    {
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMIO_2496 , tag_size);
        return 0;
    }
    tag_size *= 1024;

    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2501 , tag_size, curr_size); 

    // exceed tag size bound.
    if (size > (tag_size - curr_size))
    {
        size = tag_size - curr_size;
    }
    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2508 , size); 


    
    // quota bound.
    if (size > g_total_sys_file_size)
    {
        VMUINT tmp = MRE_SYS_FILE_APP_MAX_SIZE - g_total_sys_file_size;
        g_total_sys_file_size = 0;
        return tmp;
    }

    g_total_sys_file_size -= size;

    
    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2523 , g_total_sys_file_size); 

    
    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2526 ); 
    
    return (VMUINT)size;
}

static VMINT vm_sys_file_internal_pre_process(void)
{
    struct vm_fileinfo_t info;
    VMINT finder;
    VMINT drv;
    VMWSTR pathname;
    FS_HANDLE folder_hdl;

    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2541 );

    if (g_pre_proc_b)
        return VM_SYS_FILE_ERR_NONE;
        
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
    #endif
    


    drv = SRV_FMGR_SYSTEM_DRV; //FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL);
    pathname = vm_malloc(REMAP_FILENAME_MAX_LEN * sizeof(VMWCHAR));
    pathname[0] = (VMWCHAR)drv;
    kal_wstrcpy((WCHAR *)&pathname[1], VM_SYS_FILE_SYSTEM_PATH);


    // create if the path is not exist
    folder_hdl = FS_Open((const WCHAR *)pathname, FS_OPEN_DIR | FS_READ_ONLY);

    // the folder dose not exist!
    if (FS_NO_ERROR > folder_hdl)
    {
        MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2582 );
        folder_hdl = FS_CreateDir((const WCHAR *)pathname);
        // create folder failure!
        if (FS_NO_ERROR > folder_hdl)
        {
            MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2587 );
            vm_free(pathname);
            return VM_SYS_FILE_ERR_AUTHORIZATION;
        }
        else
        {
            FS_Close(folder_hdl);
        }
    }
    else
    {
        MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2598 );
        FS_Close(folder_hdl);
    }

    kal_wsprintf((WCHAR *)&pathname[vm_wstrlen(pathname)], "%c", '*');

    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2604 , g_total_sys_file_size);

    // load size.
    finder = vm_find_first(pathname, &info);
    if (finder >= 0)
        g_total_sys_file_size -= info.size;
    
    while (0 <= vm_find_next(finder, &info))
    {
        g_total_sys_file_size -= info.size;
        
    }
    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2616 , g_total_sys_file_size);
    if (0 > g_total_sys_file_size)
    {
        g_total_sys_file_size = 0;
    }
        
    vm_find_close(finder);
    vm_free(pathname);

    g_pre_proc_b = MMI_TRUE;

    
    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2628 );

    return VM_SYS_FILE_ERR_NONE;
}

static VMINT vm_sys_file_internal_get_tag_size(void)
{
    VMWCHAR * pathname;
    VMINT tag_buf = 0;
    VMINT tag_size = 4;
    //VM_P_HANDLE p;
    VMWSTR tmp;
    
    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2642 );
    
    pathname = vm_malloc(REMAP_FILENAME_MAX_LEN * sizeof(VMWCHAR));

    //p = vm_pmng_get_current_handle();
    //vm_pmng_file_name(p, pathname, REMAP_FILENAME_MAX_LEN);
    tmp = vm_get_self_filename();
    vm_wstrcpy(pathname, tmp);
    if (GET_TAG_TRUE != vm_get_vm_tag(pathname, VM_CE_INFO_SYS_FILE_SIZE, (void*)&tag_buf, &tag_size))
    {
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMIO_2652 );
        vm_free(pathname);
        return VM_SYS_FILE_ERR_AUTHORIZATION;
    }

    vm_free(pathname);
    
    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2659 , tag_buf, tag_size);

    MMI_TRACE(MMI_MRE_TRC_INFO, TRC_MRE_VMIO_2661 );
    return tag_buf;
}
#include "vmmem.h"
#include "GlobalResDef.h"
#include "AlertScreen.h"
#include "FileMgrType.h"
#include "FileMgrCuiGprot.h"
#include "mmi_rp_app_mre_def.h"
#ifdef __MMI_EBOOK_READER__
#include "mmi_rp_app_ebook_def.h"
#endif
#if defined(__COSMOS_MMI_PACKAGE__)
#include "mmi_rp_app_usbsrv_def.h"
#include "mmi_rp_vapp_vol_dialog_def.h"
#include "vapp_vol_dialog_gprot.h"
#include "vapp_fmgr_cui_gprot.h"
#include "vfx_datatype.h"
#endif


typedef struct _vm_selector_ctx_t
{
    VMINT m_phdl;
    VMINT (*m_cb)(VMWCHAR * path, VMINT wlen);
    VMWCHAR * m_path;
    VMINT res_handle;
	VMUINT cui_id;
}vm_selector_ctx_t;

//static vm_selector_ctx_t g_sel_ctx;

extern vm_selector_ctx_t * vm_selector_malloc_context(void);
extern void vm_selector_free_context(vm_selector_ctx_t *);
extern vm_selector_ctx_t * vm_selector_get_context(void);

#ifdef __MMI_FILE_MANAGER__    
static mmi_ret vm_selector_file_run_gproc(mmi_event_struct *evt);
static mmi_ret vm_selector_image_run_gproc(mmi_event_struct *evt);

#endif

/*****************************************************************************
 * FUNCTION
 *  vm_selector_process_staus_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  process_handle      [IN]        
 *  sys_state           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void vm_selector_process_status_callback(VM_P_HANDLE process_handle, VMINT sys_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT resHandle = 0, bufSize = 0;
	vm_selector_ctx_t *ctx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sys_state)
    {
        case VM_PMNG_UNLOAD:
        {
            while ((resHandle = vm_res_findfirst(process_handle, VM_RES_TYPE_SELECTOR)) 
            != VM_RES_NOT_FIND)
            {
                if (vm_res_get_data(VM_RES_TYPE_SELECTOR, 
                resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
                {
#if defined(__COSMOS_MMI_PACKAGE__)
                    vcui_file_selector_close(ctx_p->cui_id);
#else
                    cui_file_selector_close(ctx_p->cui_id);
#endif
                    //vm_selector_free_context(ctx_p);
                    //_vm_kernel_free(ctx_p);
                }
                vm_res_release_data(VM_RES_TYPE_SELECTOR, resHandle);
                vm_res_findclose(VM_RES_TYPE_SELECTOR);
            }
        }break;
#if 0
/* under construction !*/
/* under construction !*/
#endif
    }
}

/*****************************************************************************
 * FUNCTION
 *  vm_initialize_selector
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vm_initialize_selector(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (vm_res_type_set_notify_callback(
			VM_RES_TYPE_SELECTOR, 
			vm_selector_process_status_callback)
		!= 0)
	{
        return -1;
	}

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vm_finalize_selector
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vm_finalize_selector(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT rHandle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	while ((rHandle = vm_res_findfirst(-1, VM_RES_TYPE_SELECTOR)) 
			!= VM_RES_NOT_FIND)
    {
        vm_res_findclose(VM_RES_TYPE_SELECTOR);
        vm_res_release_data(VM_RES_TYPE_SELECTOR, rHandle);
    }
    vm_res_type_set_notify_callback(VM_RES_TYPE_SELECTOR, NULL);

    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  vm_selector_mod_evt_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vm_selector_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event)
    {
        case EVT_MOD_INIT:
            vm_initialize_selector();
            break;

        case EVT_MOD_RELEASE:
            vm_finalize_selector();
            break;
    }
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  _vm_reg_selector_module
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VMINT _vm_reg_selector_module(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int res_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ((res_code = _vm_reg_module(
						"SELECTOR MODULE", 
						(MOD_EVT_PROCESS) vm_selector_mod_evt_proc)) 
		!= REG_MRE_MODULE_SUCCESS)
    {
		/* trace what ??? */
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMIME_494 , res_code);
    }

    return res_code;
}

VMINT vm_selector_run(VMINT type, const VMWCHAR * folder_path, VMINT (*callback)(VMWCHAR * file_path, VMINT wlen))
{
        
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //VMWCHAR root_list[5];
    MMI_ID cui_gid;
    FMGR_FILTER filter;
    const VMWCHAR * path_type;
    vm_selector_ctx_t * ctx_p;
    mmi_id temp_parent_gid;
	VMBOOL select_files_only = FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FILE_MANAGER__    

    ctx_p = vm_selector_malloc_context();
    if (!ctx_p)
    {
        return VM_SELECTOR_ERR_NO_RES;
    }

    if ((VM_SELECTOR_TYPE_ALL > type || VM_SELECTOR_TYPE_TXT < type) ||
    NULL == callback)
    {
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMIO_2727 );
        return VM_SELECTOR_ERR_PARAM;
    }

    
    FMGR_FILTER_INIT(&filter);

    if (VM_SELECTOR_TYPE_ALL == type)
    {
        FMGR_FILTER_SET(&filter, FMGR_TYPE_ALL);
    }
    else if (VM_SELECTOR_TYPE_IMAGE == type)
    {
        FMGR_FILTER_SET_IMAGE(&filter);
		select_files_only = TRUE;
    }
    else if (VM_SELECTOR_TYPE_TXT == type)
    {
#ifdef __MMI_EBOOK_READER__
        srv_fmgr_types_filter_set_group(&filter, FMGR_TYPE_EBOOK_TXT);
#else
        srv_fmgr_types_filter_set_group(&filter, FMGR_GROUP_MRE_TXT);
#endif
		select_files_only = TRUE;
    }
    else
    {
        return VM_SELECTOR_ERR_NOT_SUPPORT;
    }
    
	/* 
	 * if user want to select files only, we should do 2 steps:
	 *	step1:	add FMGR_TYPE_FOLDER to filter, in order to shown folders in 
	 *			file selector screen. If not, only files can be seen, but all
	 *			folders can NOT be shown.
	 *	step2:	change some parameters when calling cui_file_selector_create,
	 *			and this can be seen in the code below.
	 */
    if (select_files_only == TRUE)
	{
		FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
	}
    
    ctx_p->m_phdl = vm_pmng_get_current_handle();
    ctx_p->m_cb = callback;
    
    if (folder_path)
    {
        path_type = folder_path;
    }
    else
    {
        path_type = (const VMWCHAR *)L"root";
    }

#if defined(__COSMOS_MMI_PACKAGE__)

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
#else
    {
        extern MMI_ID vapp_cui_file_selector_run(const VMWCHAR * path_type, const FMGR_FILTER * filter);
        if (GRP_ID_INVALID >= vapp_cui_file_selector_run(path_type, &filter))
        {
            return VM_SELECTOR_ERR_EXCEPTION;
        }
    }
#endif

#else

    temp_parent_gid = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, vm_selector_file_run_gproc, (void*)NULL); 
    mmi_frm_group_enter(temp_parent_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

	/* 
	 * if user want to select files only, we should do 2 steps:
	 *	step1:	add FMGR_TYPE_FOLDER to filter, in order to shown folders in 
	 *			file selector screen. If not, only files can be seen, but all
	 *			folders can NOT be shown. This can be seen in the code above.
	 *	step2:	change some parameters when calling cui_file_selector_create.
	 */
	if (select_files_only == TRUE)
	{
		cui_gid = cui_file_selector_create(
						temp_parent_gid,
                        (WCHAR*)path_type,
                        &filter,
                        CUI_FILE_SELECTOR_STYLE_FILE_ONLY,
						CUI_FILE_SELECTOR_OPT_ARCHIVE_AS_FILE
							| CUI_FILE_SELECTOR_OPT_FIXED_PATH_ON
                            | CUI_FILE_SELECTOR_OPT_FOLDER_TRAVERSE_ALL);
	}
	else
	{
		cui_gid = cui_file_selector_create(
						temp_parent_gid,
						(WCHAR*)path_type,
						&filter,
						CUI_FILE_SELECTOR_STYLE_FILE_AND_PATH,
						CUI_FILE_SELECTOR_OPT_ARCHIVE_AS_FILE
							| CUI_FILE_SELECTOR_OPT_FIXED_PATH_ON);
	}
        
        
    if (cui_gid > GRP_ID_INVALID)
    {
		ctx_p->cui_id = (VMUINT) cui_gid;
        cui_file_selector_run(cui_gid);
    }
    else
    {   
        return VM_SELECTOR_ERR_EXCEPTION;
    }	

    
#endif
    
    return VM_SELECTOR_ERR_SUCCESS;
    
#else
    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMIO_2825 );
    return VM_SELECTOR_ERR_NOT_SUPPORT;
#endif

}


#ifdef __MMI_FILE_MANAGER__    
static mmi_ret vm_selector_file_run_gproc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    vm_selector_ctx_t * ctx_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
#if defined(__COSMOS_MMI_PACKAGE__)
        case EVT_ID_VCUI_FILE_SELECTOR_RESULT:
        {
            vcui_file_selector_result_event_struct * evt_fs = NULL;
            ctx_p = vm_selector_get_context();
            if (!ctx_p)
            {
                MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMIO_2853 );
                return MMI_RET_OK;
            }
            
            evt_fs = (vcui_file_selector_result_event_struct *)evt;

            if (evt_fs->result > 0)
            {
                srv_fmgr_fileinfo_struct fileinfo;
                VfxChar filepath[SRV_FMGR_PATH_BUFFER_SIZE] = {0};
                if (0 == vcui_file_selector_get_selected_filepath(evt_fs->sender_id, 
                                                                                    &fileinfo, 
                                                                                    (WCHAR*)&filepath, 
                                                                                    SRV_FMGR_PATH_BUFFER_SIZE))
                {
                    ctx_p->m_path = (VMWCHAR *)filepath;
                    if ((NULL != ctx_p->m_cb) && 
                        (NULL != ctx_p->m_phdl) && 
                        (VM_PMNG_OP_OK != vm_pmng_set_ctx(ctx_p->m_phdl)))
                    {
                        ctx_p->m_path = NULL;
                        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMIO_2874 , ctx_p->m_cb, ctx_p->m_phdl);
                        vm_selector_free_context(ctx_p);
                        break;
                    }
                    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_2878 , ctx_p->m_cb, ctx_p->m_phdl);
                        
                    ctx_p->m_cb(ctx_p->m_path, vm_wstrlen(ctx_p->m_path));
                    
                    vm_pmng_reset_ctx();
                }
                
            }
            vm_selector_free_context(ctx_p);
            vcui_file_selector_close(evt_fs->sender_id);
            break;
        }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        case EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE:
        {
            vapp_vol_dialog_evt_struct *volEvent = (vapp_vol_dialog_evt_struct*) evt;

            if (volEvent->type == VAPP_VOL_DIALOG_IS_MEDIA)
            {
                return !MMI_RET_OK;
            }
            break;
        }

        default:
            break;

#else

        case EVT_ID_CUI_FILE_SELECTOR_RESULT:
        {
            cui_file_selector_result_event_struct *sel_evt = NULL;
			VMWCHAR filepath[SRV_FMGR_PATH_MAX_LEN + 1] = {0};
            ctx_p = vm_selector_get_context();
            if (!ctx_p)
            {
                MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMIO_2919 );
                return MMI_RET_OK;
            }
            
            sel_evt = (cui_file_selector_result_event_struct*)evt;

            
            if (sel_evt->result > 0)
            {
                MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_2928 );
                if (NULL == ctx_p->m_path)
                {
                    ctx_p->m_path = filepath;
                    if (NULL == ctx_p->m_path)
                    {
                        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMIO_2934 );
                        vm_selector_free_context(ctx_p);
                        break;
                    }
                }
                
                cui_file_selector_get_selected_filepath(
                                        sel_evt->sender_id,
                                        NULL,
                                        (WCHAR *)ctx_p->m_path,
                                        (SRV_FMGR_PATH_MAX_FILE_NAME_LEN) * ENCODING_LENGTH);
                                        
                
                if ((NULL != ctx_p->m_cb) && 
                    (NULL != ctx_p->m_phdl) && 
                    (VM_PMNG_OP_OK != vm_pmng_set_ctx(ctx_p->m_phdl)))
                {
                    ctx_p->m_path = NULL;
                    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMIO_2952 , ctx_p->m_cb, ctx_p->m_phdl);
                    vm_selector_free_context(ctx_p);
                    break;
                }
                MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_2956 , ctx_p->m_cb, ctx_p->m_phdl);

                ctx_p->m_cb(ctx_p->m_path, vm_wstrlen(ctx_p->m_path));
                
                vm_pmng_reset_ctx();
            }
            else if (0 == sel_evt->result)
            {
            }
            else
            {
                mmi_popup_display((WCHAR*)((U16*)GetString(srv_fmgr_fs_error_get_string(sel_evt->result))), 
                    srv_fmgr_fs_error_get_popup_type(sel_evt->result), NULL);
            }
            vm_selector_free_context(ctx_p);
            cui_file_selector_close(sel_evt->sender_id);
            break;
        }
        case EVT_ID_GROUP_EXIT:
        {
            ctx_p = vm_selector_get_context();
            if (ctx_p)
            vm_selector_free_context(ctx_p);
            break;
        }
        default:
            break;
    
#endif
    
    }
    return MMI_RET_OK;

   
}

static mmi_ret vm_selector_image_run_gproc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_folder_browser_on_quit_event_struct *quit_evt;
    mmi_id cui_id = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    switch(evt->evt_id)
    {
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
    #endif
    case EVT_ID_CUI_FOLDER_BROWSER_ON_QUIT:
        quit_evt = (cui_folder_browser_on_quit_event_struct*)evt;

        cui_id = quit_evt->sender_id;
        
        cui_folder_browser_close(cui_id);
        break;
    }
    return MMI_RET_OK;
}
#endif /* __MMI_FILE_MANAGER__ */
vm_selector_ctx_t * vm_selector_malloc_context(void)
{
    vm_selector_ctx_t* ctx_p = NULL;

    if ((ctx_p = _vm_kernel_calloc(sizeof(vm_selector_ctx_t))) != NULL)
    {
        if ((ctx_p->res_handle = vm_res_save_data(VM_RES_TYPE_SELECTOR, 
            (void*)ctx_p, sizeof(ctx_p), NULL, vm_pmng_get_current_handle())) >= 0)
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_3034 , 
                ctx_p->res_handle);
            return ctx_p;
        }
        else
        {
            _vm_kernel_free(ctx_p);
        }
    }

    return NULL;
}

void vm_selector_free_context(vm_selector_ctx_t * ctx_p)
{
    if (ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_3051 , 
            ctx_p->res_handle);
        vm_res_release_data(VM_RES_TYPE_SELECTOR, ctx_p->res_handle);
        _vm_kernel_free(ctx_p);
    }
}

vm_selector_ctx_t * vm_selector_get_context(void)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_selector_ctx_t * ctx_p = NULL;
    
    if ((resHandle = vm_res_findfirst(-1, VM_RES_TYPE_SELECTOR)) != VM_RES_NOT_FIND)
    {
        if (vm_res_get_data(VM_RES_TYPE_SELECTOR, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
        {
                vm_res_findclose(VM_RES_TYPE_SELECTOR);
                return ctx_p;
        }
    }   
    return NULL;
}
#include "mmi_frm_input_gprot.h"
VMINT vm_pen_configure_sampling_period(VMUINT sp)
{    
    
#ifdef __MMI_TOUCH_SCREEN__
    //mmi_pen_config_timeout_period(MMI_PEN_LONGTAP_TIME, MMI_PEN_REPEAT_TIME, MMI_PEN_STROKE_LONGTAP_TIME);
    //mmi_pen_config_timeout_period(MMI_PEN_LONGTAP_TIME, MMI_PEN_REPEAT_TIME, longtap);
    mmi_pen_config_sampling_period(sp, MMI_PEN_SAMPLING_PERIOD_2);
    return 0;
#else
    return -2;
#endif
}
/*
VMUINT8 vm_kbd_get_mode(void)
{
    return mmi_frm_get_keypad_mode();
}
*/
VMINT vm_kbd_set_mode(VMUINT8 mode)
{
    if (VM_KEYPAD_MODE_END <= mode/* || VM_KEYPAD_1KEY_NUMBER > mode*/)
    {
        return (VMINT)VM_KBD_MODE_ERR_PARAM;
    }
    mmi_frm_set_keypad_mode(mode);
    return (VMINT)VM_KBD_MODE_ERR_SUCCESS;
}

#if defined(__MMI_CAMCORDER__)

#if defined(__COSMOS_MMI_PACKAGE__)
extern mmi_id vapp_camco_launch_app(void);
#else
#include "CameraCuiGprot.h"
#endif

#endif

VMINT vm_camera_startup(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CAMCORDER__)

    #ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        return VM_CAM_ERR_BUSY;
    }
    #endif


    #if defined(__COSMOS_MMI_PACKAGE__)

    vapp_camco_launch_app();

    #else
    
    mmi_camco_launch();
    
    #endif

#else

    return VM_CAM_ERR_NOT_SUPPORT;

#endif

    return VM_CAM_ERR_SUCCESS;
}

VMINT vm_get_keypad_type(void)
{
    return (VMINT)sysconf.input_device.keypad_type;
}

#include "EmailAppGprot.h"
#include "EmailSrvGprot.h"
VMINT vm_startup_email(const VMWSTR to_addr)
{
    U32 acct_num = 0;
    VMINT ret = 0;
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_STARTUP_EMAIL1);
    #ifdef __MMI_EMAIL__
    
    ret = srv_email_acct_get_num(&acct_num);
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_STARTUP_EMAIL2, ret, acct_num);
    
    if (0 != ret)
    {
        return ret;
    }
    else
    {
        if (0 == acct_num)
        {
            return -3;
        }
    }
    mmi_email_app_send_to((S8*)to_addr);
    return 0;
    
    #else
    return -2;
    #endif
}

#include "FileMgrType.h"
const VMWCHAR * vm_get_default_folder_path(vm_fmgr_default_folder_enum type)
{

    const static VMWCHAR * path_tbl[] = {
        (const VMWCHAR *)FMGR_DEFAULT_FOLDER_EBOOKS,
        (const VMWCHAR *)FMGR_DEFAULT_FOLDER_IMAGES,
        (const VMWCHAR *)FMGR_DEFAULT_FOLDER_AUDIO,
        (const VMWCHAR *)FMGR_DEFAULT_FOLDER_VIDEO,
        (const VMWCHAR *)FMGR_DEFAULT_FOLDER_SWFLASH,
        (const VMWCHAR *)FMGR_DEFAULT_FOLDER_LANGLN,
        (const VMWCHAR *)FMGR_DEFAULT_FOLDER_TEMP,
        (const VMWCHAR *)FMGR_DEFAULT_FOLDER_THEMES,
        (const VMWCHAR *)FMGR_DEFAULT_FOLDER_BARCODE,
        (const VMWCHAR *)FMGR_DEFAULT_FOLDER_MMSBOX,
        (const VMWCHAR *)FMGR_DEFAULT_FOLDER_ROOT
    };
    if (0 > (VMINT)type || type >= VM_FMGR_DEFAULT_FOLDER_TOTAL)
        return NULL;

    
    return path_tbl[type];
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
    
}

typedef struct _vm_fs_copy
{
    vm_file_copy_cb cb;
    VM_P_HANDLE p_hdl;
    VMINT busy;
}vm_fs_copy;

static vm_fs_copy g_fs_copy_ctx;

static int vm_file_copy_int_cb(int Action, kal_uint32 Total, kal_uint32 Completed, kal_uint32 Info)
{

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMIO_FILE_COPY_S, 3, __LINE__);
    if (NULL == g_fs_copy_ctx.cb)
    {
        return 0;
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMIO_FILE_COPY_LOG, 
        Action,
        Total,
        Completed,
        Info,
        0,
        0,
        3, __LINE__);

    PMNG_WRAP_CALLBACK(g_fs_copy_ctx.p_hdl, 
        g_fs_copy_ctx.cb((VMINT)Action, (VMUINT32)Total, (VMUINT32)Completed, (VMINT)Info));
    #if 1    
    if (Action == FS_MOVE_PGS_FAIL)
    {
        g_fs_copy_ctx.busy = 0;
        return 0;
    }
    else if (Action == FS_MOVE_PGS_DONE)
    {
        g_fs_copy_ctx.busy = 0;
        return 0;
    }
    #endif

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMIO_FILE_COPY_E, 3, __LINE__);
    return 0;
}


VMINT vm_file_copy(const VMWSTR dst, const VMWSTR src, vm_file_copy_cb cb)
{
    VMINT ret = 0;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMIO_FILE_COPY_S, 1, __LINE__);
    if (NULL == dst || NULL == src)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMIO_FILE_COPY_E, 1, __LINE__);
        return -2;
    }
    
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    
    g_fs_copy_ctx.cb = cb;
    g_fs_copy_ctx.p_hdl = vm_pmng_get_current_handle();
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMIO_FILE_COPY_LOG, 
    cb,
    g_fs_copy_ctx.p_hdl,
    0,
    0,
    0,
    0,
    1, __LINE__);

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
#endif
        
    if (0 == (ret = FS_Move((const WCHAR *)src, (const WCHAR *)dst, FS_MOVE_COPY, vm_file_copy_int_cb, NULL, 0)))
    {
        g_fs_copy_ctx.busy = 1;

    }

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMIO_FILE_COPY_LOG, 
        ret,
        g_fs_copy_ctx.p_hdl,
        0,
        0,
        0,
        0,
        1, __LINE__);
        
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMIO_FILE_COPY_E, 1, __LINE__);

    return ret;


}

VMINT vm_file_copy_abort(VMINT hdl)
{
    VMINT ret = 0;
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMIO_FILE_COPY_S, 2, __LINE__);
    
    if (0 == (ret = FS_Abort((UINT)hdl)))
    {
        g_fs_copy_ctx.busy = 0;
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMIO_FILE_COPY_LOG, 
        ret,
        hdl,
        0,
        0,
        0,
        0,
        2, __LINE__);
        
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_VMIO_FILE_COPY_E, 2, __LINE__);
    return ret;
}





typedef struct _vm_multi_touch_ctx_t
{
    VM_P_HANDLE phdl;
    VMINT (*cb)(vm_multi_touch_event_struct * evt_info, void * user_data);
    VMINT res_handle;
    void * user_data;
}vm_multi_touch_ctx_t;

extern vm_multi_touch_ctx_t * vm_multi_touch_malloc_context(void);
extern void vm_multi_touch_free_context(vm_multi_touch_ctx_t *);
extern vm_multi_touch_ctx_t * vm_multi_touch_get_context(VM_P_HANDLE phdl);
static VMINT vm_multi_touch_get_mapped_evt(mmi_pen_event_type_enum evt);


VMINT vm_multi_touch_get_mode(void)
{
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_MTOUCH_S, 1, __LINE__);

#ifdef __MMI_TOUCH_SCREEN__
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_MTOUCH_E, 1, __LINE__);
    return (VMINT)mmi_frm_touch_get_mode();
#else
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_MTOUCH_E1, 1, __LINE__);
    return VM_MULTI_TOUCH_ERR_NOT_SUPPORT;
#endif
}

VMINT vm_multi_touch_set_mode(vm_touch_mode mode)
{

    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_MTOUCH_S, 2, __LINE__);
    if (mode != VM_SINGLE_TOUCH && mode != VM_MULTI_TOUCH)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_MTOUCH_E1, 2, __LINE__);
        return VM_MULTI_TOUCH_ERR_PARAM;
    }

#ifdef __MMI_TOUCH_SCREEN__

#if ( (!defined(__TOUCH_PANEL_CAPACITY__) && !defined(__TOUCH_PANEL_MULTITOUCH__)) || (!defined(__MTK_TARGET__)))
    if (VM_MULTI_TOUCH == mode)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_MTOUCH_E2, 2, __LINE__);
        return VM_MULTI_TOUCH_ERR_NOT_SUPPORT;
    }
#endif
    mmi_frm_touch_set_mode((mmi_frm_touch_mode)mode);
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_MTOUCH_E, 2, __LINE__);
    return VM_MULTI_TOUCH_ERR_SUCCESS;
#else
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_MTOUCH_E3, 2, __LINE__);
    return VM_MULTI_TOUCH_ERR_NOT_SUPPORT;
#endif
}

static mmi_ret vm_multi_touch_cb(mmi_event_struct *evt);
VMINT vm_multi_touch_register_proc(vm_multi_touch_proc_t proc, void *user_data)
{
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_MTOUCH_S, 3, __LINE__);
#ifdef __MMI_TOUCH_SCREEN__
    {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //VMWCHAR root_list[5];
    vm_multi_touch_ctx_t * ctx_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
    if (NULL == proc)
    {
        return VM_MULTI_TOUCH_ERR_PARAM;
    }
    */
    ctx_p = vm_multi_touch_get_context(vm_pmng_get_current_handle());
    if (NULL == ctx_p)
    {
        ctx_p = vm_multi_touch_malloc_context();
        if (!ctx_p)
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_MTOUCH_E1, 3, __LINE__);
            return VM_MULTI_TOUCH_ERR_NO_RES;
        }
    }
    /*
    ctx_p = vm_multi_touch_malloc_context();
    if (!ctx_p)
    {
        return VM_MULTI_TOUCH_ERR_NO_RES;
    }
    */
    ctx_p->cb = proc;
    ctx_p->user_data = user_data;
    
    mmi_frm_touch_register_proc((mmi_proc_func)vm_multi_touch_cb, (void *)ctx_p);

    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_MTOUCH_LOG, 
        proc,
        user_data,
        ctx_p->phdl,
        ctx_p->res_handle,
        0,
        0,
        3, __LINE__);

    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_MTOUCH_E, 3, __LINE__);
    return VM_MULTI_TOUCH_ERR_SUCCESS;
    }
#else

    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_MTOUCH_E2, 3, __LINE__);
    return VM_MULTI_TOUCH_ERR_NOT_SUPPORT;

#endif
}

#ifdef __MMI_TOUCH_SCREEN__
static mmi_ret vm_multi_touch_cb(mmi_event_struct *evt)
{
    vm_multi_touch_event_struct info; // useless to initialize as 0
    mmi_ret ret = MMI_RET_OK;
    vm_multi_touch_data_struct *vm_touch_data;
    mmi_touch_data_struct *mmi_touch_data;
    vm_touch_pos_struct *vm_curr_pos, *vm_pre_pos, *vm_down_pos;
    mmi_touch_pos_struct *mmi_curr_pos, *mmi_pre_pos, *mmi_down_pos;
    //vm_multi_touch_data_struct t_data[MMI_FRM_MULTI_multi_touch_MAX_FINGER] = {0}; 
    //info.multi_touch_data = t_data;
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_MTOUCH_S, 4, __LINE__);
    if (EVT_ID_ON_TOUCH == evt->evt_id)
    {
        VMINT i = 0;
        vm_multi_touch_ctx_t * ctx_p = NULL;
        mmi_multi_touch_event_struct *penEvt = (mmi_multi_touch_event_struct*) evt;
        info.touch_num = (VMUINT16)penEvt->touch_num;
        ctx_p = (vm_multi_touch_ctx_t *)penEvt->user_data;
        
        ASSERT(ctx_p);
        if (info.touch_num > 0)
        {
            info.touch_data = (vm_multi_touch_data_struct *)vm_calloc(sizeof(vm_multi_touch_data_struct) * info.touch_num);
            
            MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_MTOUCH_LOG, 
                info.touch_num,
                info.touch_data,
                0,
                0,
                0,
                0,
                41, __LINE__);
                
            for (i = 0; i < info.touch_num; i++)
            {
                vm_touch_data = &(info.touch_data[i]);
                vm_curr_pos = &(vm_touch_data->currpos);
                vm_pre_pos = &(vm_touch_data->pre_pos);
                vm_down_pos = &(vm_touch_data->down_pos);
                mmi_touch_data = &(penEvt->touch_data[i]);
                mmi_curr_pos = &(mmi_touch_data->currpos);
                mmi_pre_pos = &(mmi_touch_data->pre_pos);
                mmi_down_pos = &(mmi_touch_data->down_pos);

                vm_touch_data->id = (VMUINT16)mmi_touch_data->id;
                vm_touch_data->event = vm_multi_touch_get_mapped_evt(mmi_touch_data->event);
                vm_curr_pos->pos.x = (VMINT16)mmi_curr_pos->pos.x;
                vm_curr_pos->pos.y = (VMINT16)mmi_curr_pos->pos.y;
                vm_curr_pos->timestamp = (VMUINT32)mmi_curr_pos->timestamp;
                vm_touch_data->area = (VMUINT16)mmi_touch_data->area;
                vm_touch_data->pre_event = vm_multi_touch_get_mapped_evt(mmi_touch_data->pre_event);
                vm_pre_pos->pos.x = (VMINT16)mmi_pre_pos->pos.x;
                vm_pre_pos->pos.y = (VMINT16)mmi_pre_pos->pos.y;
                vm_pre_pos->timestamp = (VMUINT32)mmi_pre_pos->timestamp;
                vm_down_pos->pos.x = (VMINT16)mmi_down_pos->pos.x;
                vm_down_pos->pos.y = (VMINT16)mmi_down_pos->pos.y;
                vm_down_pos->timestamp = (VMUINT32)mmi_down_pos->timestamp;
                vm_touch_data->merge_num = (VMUINT16)mmi_touch_data->merge_num;
                
                MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_MTOUCH_LOG, 
                    vm_touch_data->id,
                    vm_touch_data->event,
                    vm_touch_data->pre_event,
                    vm_curr_pos->pos.x,
                    vm_curr_pos->pos.y,
                    vm_touch_data->merge_num,
                    42, __LINE__);
                    
                if (vm_touch_data->merge_num > 0)
                {
                    VMINT j = 0;
                    vm_touch_pos_struct *vm_merge_points;
                    mmi_touch_pos_struct *mmi_merge_points;
                    vm_touch_data->merge_points = (vm_touch_pos_struct *)vm_calloc(sizeof(vm_touch_pos_struct) * vm_touch_data->merge_num);

                    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_MTOUCH_LOG, 
                        vm_touch_data->merge_points,
                        vm_touch_data->merge_num,
                        0,
                        0,
                        0,
                        0,
                        43, __LINE__);
                    for (j = 0; j < vm_touch_data->merge_num; j++)
                    {
                        vm_merge_points = &(vm_touch_data->merge_points[j]);
                        mmi_merge_points = &(mmi_touch_data->merge_points[j]);

                        vm_merge_points->pos.x = (VMINT16)mmi_merge_points->pos.x;
                        vm_merge_points->pos.y = (VMINT16)mmi_merge_points->pos.y;
                        vm_merge_points->timestamp = (VMUINT32)mmi_merge_points->timestamp;
                        
                        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_MTOUCH_LOG, 
                            info.touch_num,
                            vm_merge_points->pos.x,
                            vm_merge_points->pos.y,
                            vm_merge_points->timestamp,
                            0,
                            0,
                            44, __LINE__);
                    }
                }
                vm_touch_data->merge_area = (U16*)mmi_touch_data->merge_area;
            }
        }


        if (vm_pmng_set_ctx(ctx_p->phdl) == VM_PMNG_OP_OK)
        {
            if (ctx_p->cb)
            {
                VMINT ret = 0;
                ret = ctx_p->cb(&info, ctx_p->user_data);
                MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_MTOUCH_LOG, 
                    ret,
                    ctx_p->user_data,
                    info.touch_num,
                    info.touch_data,
                    0,
                    0,
                    45, __LINE__);
            }
            vm_pmng_reset_ctx();
        }
            
        for (i = 0; i < info.touch_num; i++)
        {
            if (info.touch_data[i].merge_points)
            {
                vm_free(info.touch_data[i].merge_points);
            }
        }
        
        if (info.touch_data)
        {
            vm_free(info.touch_data);
        }

        

            
        
    }
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_MTOUCH_E, 4, __LINE__);
    
    return ret;
}
#endif /* __MMI_TOUCH_SCREEN__ */

static VMINT vm_multi_touch_get_mapped_evt(mmi_pen_event_type_enum evt)
{
    VMINT mapped_evt = 0;
    switch (evt)
    {
        case MMI_PEN_EVENT_DOWN:
            {
                mapped_evt = VM_PEN_EVENT_TAP;
            }
            break;
        case MMI_PEN_EVENT_UP:
            {
                mapped_evt = VM_PEN_EVENT_RELEASE;
            }
            break;
        case MMI_PEN_EVENT_LONG_TAP:
            {
                mapped_evt = VM_PEN_EVENT_LONG_TAP;
            }
            break;
        case MMI_PEN_EVENT_REPEAT:
            {
                mapped_evt = VM_PEN_EVENT_REPEAT;
            }
            break;
        case MMI_PEN_EVENT_MOVE:
            {
                mapped_evt = VM_PEN_EVENT_MOVE;
            }
            break;
        case MMI_PEN_EVENT_ABORT:
            {
                mapped_evt = VM_PEN_EVENT_ABORT;
            }
            break;
        case MMI_PEN_EVENT_DOUBLE_CLICK:
            {
                mapped_evt = VM_PEN_EVENT_DOUBLE_CLICK;                        
            }break;
        default:
            //ASSERT(0);
            break;
    }
    return mapped_evt;

}

vm_multi_touch_ctx_t * vm_multi_touch_malloc_context(void)
{
    vm_multi_touch_ctx_t* ctx_p = NULL;

    if ((ctx_p = _vm_kernel_calloc(sizeof(vm_multi_touch_ctx_t))) != NULL)
    {
        if ((ctx_p->res_handle = vm_res_save_data(VM_RES_TYPE_MULTI_TOUCH, 
            (void*)ctx_p, sizeof(ctx_p), NULL, vm_pmng_get_current_handle())) >= 0)
        {
            ctx_p->phdl = vm_pmng_get_current_handle();
            return ctx_p;
        }
        else
        {
            _vm_kernel_free(ctx_p);
        }
    }

    return NULL;
}

void vm_multi_touch_free_context(vm_multi_touch_ctx_t * ctx_p)
{
    if (ctx_p)
    {
        vm_res_release_data(VM_RES_TYPE_MULTI_TOUCH, ctx_p->res_handle);
        _vm_kernel_free(ctx_p);
    }
}

vm_multi_touch_ctx_t* vm_multi_touch_get_context(VM_P_HANDLE phdl)
{
    VMINT resHandle, bufSize = 0;
    vm_multi_touch_ctx_t* ctx_p = NULL;
    
    if ((resHandle = vm_res_findfirst(-1, VM_RES_TYPE_MULTI_TOUCH)) != VM_RES_NOT_FIND)
    {
        if (vm_res_get_data(VM_RES_TYPE_MULTI_TOUCH, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
        {
            if (ctx_p->phdl == phdl)
            {
                vm_res_findclose(VM_RES_TYPE_MULTI_TOUCH);
                return ctx_p;
            }
        }

        while ((resHandle = vm_res_findnext(-1, VM_RES_TYPE_MULTI_TOUCH)) != VM_RES_NOT_FIND)
        {
            if (vm_res_get_data(VM_RES_TYPE_MULTI_TOUCH, 
                resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
            {
                if (ctx_p->phdl == phdl)
                {
                    vm_res_findclose(VM_RES_TYPE_MULTI_TOUCH);
                    return ctx_p;
                }
            }
        }
        vm_res_findclose(VM_RES_TYPE_MULTI_TOUCH);
    }	
    return NULL;
}
static void vm_multi_touch_free_resource(VM_P_HANDLE phdl)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_multi_touch_ctx_t * ctx_p = NULL;
    while ((resHandle = vm_res_findfirst(phdl, VM_RES_TYPE_MULTI_TOUCH)) 
        != VM_RES_NOT_FIND)
    {
        if (vm_res_get_data(VM_RES_TYPE_MULTI_TOUCH, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
        {
            // TODO: release
            if (ctx_p)
                vm_multi_touch_free_context(ctx_p);
        }

        vm_res_release_data(VM_RES_TYPE_MULTI_TOUCH, resHandle);
        vm_res_findclose(VM_RES_TYPE_MULTI_TOUCH);
    }

}
static void vm_multi_touch_notify_process_status(VM_P_HANDLE process_handle, 
    VMINT sys_state)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_multi_touch_ctx_t * ctx_p = NULL;

    switch (sys_state)
    {
    case VM_PMNG_UNLOAD:
        vm_multi_touch_free_resource(process_handle);
        break;
    }
}

static VMINT vm_multi_touch_initialize_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U16 mre_path_w[20];
    //FS_HANDLE fd = -1;
    //VMINT file_drv;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ///* Firstly, search mre folder in remove driver */
    //file_drv = vm_get_removable_driver();
    //if (file_drv != 0)
    //{
    //    memset(mre_path_w, 0, sizeof(mre_path_w));
    //    kal_wsprintf((WCHAR*) mre_path_w, "%c:\\%s", file_drv, "mre");

    //    /* search mre folder, if it exists, hold it. */
    //    if ((fd = FS_Open(mre_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) >= FS_NO_ERROR)   /* mre is not folder */
    //    {
    //        FS_Close(fd);
    //    }
    //    else if ((fd = FS_Open(mre_path_w, FS_OPEN_DIR | FS_READ_ONLY)) >= FS_NO_ERROR)
    //    {

    //    }

    //}

    if (vm_res_type_set_notify_callback(VM_RES_TYPE_MULTI_TOUCH, 
        vm_multi_touch_notify_process_status) != 0)
    {
        return -1;
    }

    ///TODO: other init.


    return 0;
}

static VMINT vm_multi_touch_finialize_resource(void)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_multi_touch_ctx_t * ctx_p = NULL;

    
    vm_multi_touch_free_resource(-1);
    
    
    vm_res_type_set_notify_callback(VM_RES_TYPE_MULTI_TOUCH, NULL);

    ///TODO: Deregister WPS relate functions

    return 0;
}

static VMINT vm_multi_touch_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
    switch(event)
    {
    case EVT_MOD_INIT:
        if (vm_multi_touch_initialize_resource() != 0)
            return -1;
        break;
    case EVT_MOD_RELEASE:
        vm_multi_touch_finialize_resource();
        break;
    default:
        return -2;
    }

    return 0;
}

VMINT _vm_reg_multi_touch_module(void)
{
    int res_code;
    
    if ((res_code = _vm_reg_module("MULTI TOUCH MODULE", (MOD_EVT_PROCESS)vm_multi_touch_mod_evt_proc)) != REG_MRE_MODULE_SUCCESS)
    {
    }

    return res_code;
}

extern void fs_async_msg_handler(local_para_struct *local_para);


typedef struct 
{
    VMINT res_handle;
    VM_P_HANDLE phdl;
    FS_HANDLE fs_hdl;
    fs_job_id jid;
    //fs_overlapped_struct ol;
    void * ol_buf;
    vm_fs_async_callback app_cb;
} vm_fs_async_ctx_t;


vm_fs_async_ctx_t * vm_fs_async_malloc_context(void)
{
    vm_fs_async_ctx_t* ctx_p = NULL;

    if ((ctx_p = _vm_kernel_calloc(sizeof(vm_fs_async_ctx_t))) != NULL)
    {
        if ((ctx_p->res_handle = vm_res_save_data(VM_RES_TYPE_FS_ASYNC, 
            (void*)ctx_p, sizeof(ctx_p), NULL, vm_pmng_get_current_handle())) >= 0)
        {
            ctx_p->phdl = vm_pmng_get_current_handle();
            ctx_p->fs_hdl = -1;
            return ctx_p;
        }
        else
        {
            _vm_kernel_free(ctx_p);
        }
    }

    return NULL;
}

VMINT vm_fs_async_free_context(vm_fs_async_ctx_t * ctx_p)
{
    VMINT ret = FS_PARAM_ERROR;
    if (ctx_p)
    {
    
        //fs_async_abort(ctx_p->jid); // TODO: close handle of file
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
        vm_res_release_data(VM_RES_TYPE_FS_ASYNC, ctx_p->res_handle);
        if (ctx_p->ol_buf)
        {
            _vm_kernel_free(ctx_p->ol_buf);
            ctx_p->ol_buf = NULL;
        }
        _vm_kernel_free(ctx_p);
    }

    return ret;
}

static vm_fs_async_ctx_t* vm_fs_async_get_ctx(VMINT id)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_fs_async_ctx_t* ctx_p = NULL;
    
    if ((resHandle = vm_res_findfirst(-1, VM_RES_TYPE_FS_ASYNC)) != VM_RES_NOT_FIND)
    {
        if (vm_res_get_data(VM_RES_TYPE_FS_ASYNC, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
        {
            if (ctx_p->jid == id)
            {
                vm_res_findclose(VM_RES_TYPE_FS_ASYNC);
                return ctx_p;
            }
        }

        while ((resHandle = vm_res_findnext(-1, VM_RES_TYPE_FS_ASYNC)) != VM_RES_NOT_FIND)
        {
            if (vm_res_get_data(VM_RES_TYPE_FS_ASYNC, 
                resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
            {
                if (ctx_p->jid == id)
                {
                    vm_res_findclose(VM_RES_TYPE_FS_ASYNC);
                    return ctx_p;
                }
            }
        }
        vm_res_findclose(VM_RES_TYPE_FS_ASYNC);
    }	
    return NULL;    
}

static void vm_fs_async_free_resource(VM_P_HANDLE phdl)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_fs_async_ctx_t * ctx_p = NULL;

    while ((resHandle = vm_res_findfirst(phdl, VM_RES_TYPE_FS_ASYNC)) 
        != VM_RES_NOT_FIND)
    {
        if (vm_res_get_data(VM_RES_TYPE_FS_ASYNC, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
        {
            if (ctx_p)
            {
                
                if (0 < ctx_p->fs_hdl)
                {
                    FS_Close(ctx_p->fs_hdl);
                    ctx_p->fs_hdl = -1;
                }                  
                vm_fs_async_free_context(ctx_p);
            }
        }
        else
        {
        }
        vm_res_release_data(VM_RES_TYPE_FS_ASYNC, resHandle);
        vm_res_findclose(VM_RES_TYPE_FS_ASYNC); 
    }

}

static void vm_fs_async_notify_process_status(VM_P_HANDLE process_handle, 
    VMINT sys_state)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_fs_async_ctx_t * ctx_p = NULL;

    switch (sys_state)
    {
    case VM_PMNG_UNLOAD:
        vm_fs_async_free_resource(process_handle);
        break;
    }
}

static VMINT vm_fs_async_initialize_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U16 mre_path_w[20];
    //FS_HANDLE fd = -1;
    //VMINT file_drv;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ///* Firstly, search mre folder in remove driver */
    //file_drv = vm_get_removable_driver();
    //if (file_drv != 0)
    //{
    //    memset(mre_path_w, 0, sizeof(mre_path_w));
    //    kal_wsprintf((WCHAR*) mre_path_w, "%c:\\%s", file_drv, "mre");

    //    /* search mre folder, if it exists, hold it. */
    //    if ((fd = FS_Open(mre_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) >= FS_NO_ERROR)   /* mre is not folder */
    //    {
    //        FS_Close(fd);
    //    }
    //    else if ((fd = FS_Open(mre_path_w, FS_OPEN_DIR | FS_READ_ONLY)) >= FS_NO_ERROR)
    //    {

    //    }

    //}

    if (vm_res_type_set_notify_callback(VM_RES_TYPE_FS_ASYNC, 
        vm_fs_async_notify_process_status) != 0)
    {
        return -1;
    }

    ///TODO: other init.

    SetProtocolEventHandler(fs_async_msg_handler, MSG_ID_FS_OPEN_RSP);
    SetProtocolEventHandler(fs_async_msg_handler, MSG_ID_FS_WRITE_RSP);
    SetProtocolEventHandler(fs_async_msg_handler, MSG_ID_FS_READ_RSP);
    SetProtocolEventHandler(fs_async_msg_handler, MSG_ID_FS_DELETE_RSP);
    SetProtocolEventHandler(fs_async_msg_handler, MSG_ID_FS_SEEK_RSP);
    //SetProtocolEventHandler(fs_async_msg_handler, MSG_ID_FS_ABORT_RSP);
    return 0;
}

static VMINT vm_fs_async_finialize_resource(void)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_fs_async_ctx_t * ctx_p = NULL;


    vm_fs_async_free_resource(-1);
    
    vm_res_type_set_notify_callback(VM_RES_TYPE_FS_ASYNC, NULL);

    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    
    ///TODO: Deregister WPS relate functions

    return 0;
}

static VMINT vm_fs_async_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
    switch(event)
    {
    case EVT_MOD_INIT:
        if (vm_fs_async_initialize_resource() != 0)
            return -1;
        break;
    case EVT_MOD_RELEASE:
        vm_fs_async_finialize_resource();
        break;
    default:
        return -2;
    }

    return 0;
}

VMINT _vm_reg_fs_async_module(void)
{
    int res_code = REG_MRE_MODULE_SUCCESS;
    
    if ((res_code = _vm_reg_module("FS ASYNC", (MOD_EVT_PROCESS)vm_fs_async_mod_evt_proc)) != REG_MRE_MODULE_SUCCESS)
    {
    }

    return res_code;
}



static kal_int32 vm_fs_async_cb(fs_job_id job_id, kal_int64 result, fs_async_callback_data_struct * data)
{
    vm_fs_async_ctx_t * ctx_p = NULL;
    vm_fs_async_callback_data_struct head = {0};
    vm_fs_async_callback_data_struct * app_data = NULL;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_S, 8, __LINE__);
    
    ASSERT(data);

    ctx_p = vm_fs_async_get_ctx(job_id);
    if (NULL == ctx_p)
    {
        return 0;
    }

    head.api = (vm_fs_api_enum)data->api;
    head.reserved1 = (vm_fs_job_state_enum)data->reserved1;
    head.reserved2 = (VMUINT8)data->reserved2;
    head.jid = ctx_p->res_handle;//(vm_fs_job_id)data->jid;
    head.reserved3 = (vm_module_type)data->reserved3;
    head.result = (VMINT64)data->result;
    head.callback = (vm_fs_async_callback)data->callback;
    head.param = data->param;
    head.reserved4 = 0; // MRE engine reserved.

    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_LOG, 
        head.api,
        data->id,
        head.jid,
        (VMINT)result,
        data,
        head.param,       
        8, __LINE__); 
    
    switch (data->api)
    {
        case FS_API_OPEN:
        {
            static vm_fs_job_open_struct obj;
            fs_job_open_struct * native_data = (fs_job_open_struct *)data;
            vm_fs_async_callback_data_struct * head_p = &(obj.head);

            //memcpy(&obj, &head, sizeof(head));
            head_p->api = head.api;
            head_p->reserved1 = head.reserved1;
            head_p->reserved2 = head.reserved2;
            head_p->jid = head.jid;
            head_p->reserved3 = head.reserved3;
            head_p->result = head.result;
            head_p->callback = head.callback;
            head_p->param = head.param;
            head_p->reserved4 = head.reserved4;
            
            obj.filename = (VMWCHAR*)native_data->filename;
            obj.flag = (VMUINT)native_data->flag;
            
            MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_LOG, 
                0,
                0,
                0,
                0,
                native_data->flag,
                &obj,       
                8, __LINE__);
            
            app_data = (vm_fs_async_callback_data_struct*)&obj;
            if (result > 0)
            {
                ctx_p->fs_hdl = (FS_HANDLE)result;
            }
        }break;
        case FS_API_WRITE:
        {
            static vm_fs_job_write_struct obj;
            fs_job_write_struct * native_data = (fs_job_write_struct *)data;

            memcpy(&obj, &head, sizeof(head));
            obj.fs_hdl = (VM_FS_HANDLE)native_data->handle;
            obj.data = (void *)native_data->data;
            obj.length = (VMUINT)native_data->length;
            obj.written = (VMUINT *)native_data->written;
            
            MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_LOG, 
                obj.fs_hdl,
                obj.length,
                0,
                0,
                obj.data,
                obj.written,       
                8, __LINE__);
                
            app_data = (vm_fs_async_callback_data_struct*)&obj;
        }break;
        case FS_API_READ:
        {
            static vm_fs_job_read_struct obj = {0};
            fs_job_read_struct * native_data = (fs_job_read_struct *)data;

            memcpy(&obj, &head, sizeof(head));
            obj.fs_hdl = (VM_FS_HANDLE)native_data->handle;
            obj.data = (void *)native_data->data;
            obj.length = (VMUINT)native_data->length;
            obj.read = (VMUINT *)native_data->read;
            
            MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_LOG, 
                obj.fs_hdl,
                obj.length,
                0,
                0,
                obj.data,
                obj.read,       
                8, __LINE__);
                
            app_data = (vm_fs_async_callback_data_struct*)&obj;
        }break;
        case FS_API_SEEK:
        {
            static vm_fs_job_seek_struct obj = {0};
            fs_job_seek_struct * native_data = (fs_job_seek_struct *)data;

            memcpy(&obj, &head, sizeof(head));
            obj.fs_hdl = (VM_FS_HANDLE)native_data->handle;
            obj.offset = (VMINT64)native_data->offset;       
            obj.whence = (VMINT)native_data->whence;
            
            MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_LOG, 
                obj.fs_hdl,
                obj.offset,
                obj.whence,
                0,
                0,
                0,
                8, __LINE__);
                
            app_data = (vm_fs_async_callback_data_struct*)&obj;
        }break;
        case FS_API_DELETE:
        {
            static vm_fs_job_delete_struct obj = {0};
            fs_job_delete_struct * native_data = (fs_job_delete_struct *)data;

            memcpy(&obj, &head, sizeof(head));
            obj.filename = (const VMWCHAR *)native_data->filename;
            
            MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_LOG, 
                0,
                0,
                0,
                0,
                0,
                obj.filename,
                8, __LINE__);

            app_data = (vm_fs_async_callback_data_struct*)&obj;
        }break;
        case FS_API_ABORT:
        {
            static vm_fs_job_abort_struct obj = {0};
            fs_job_abort_struct * native_data = (fs_job_abort_struct *)data;

            memcpy(&obj, &head, sizeof(head));
            obj.job_id = (VMINT)native_data->job_id;
            obj.aborted = (VMINT)native_data->aborted;
            
            MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_LOG, 
                obj.job_id,
                obj.aborted,
                0,
                0,
                0,
                0,
                8, __LINE__);

            app_data = (vm_fs_async_callback_data_struct*)&obj;
        }break;
    }

    if (NULL != ctx_p->app_cb)
    {
        PMNG_WRAP_CALLBACK(ctx_p->phdl, 
            (ctx_p->app_cb)(ctx_p->res_handle, (VMINT64 *)&result, app_data));
    }

    _vm_kernel_free(data);   
    ctx_p->ol_buf = NULL;
    vm_fs_async_free_context(ctx_p);

    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_E, 8, __LINE__);
    return 0;
}

static void _vm_fs_fill_overlapped_struct(fs_overlapped_struct *ol, vm_fs_overlapped_struct *overlapped)
{
    ol->callback = (fs_async_callback)vm_fs_async_cb;
    ol->param = overlapped->param;
    ol->priority = (fs_prioity_enum)(overlapped->priority);
    ol->buf = _vm_kernel_calloc(FS_ASYNC_WORKING_BUFFER_SIZE);
    ol->buf_size = FS_ASYNC_WORKING_BUFFER_SIZE;

    ol->priority_value = 0; // add this to replace struct initialization as 0
    ol->response_flag = 0;
}

VMINT vm_fs_async_open(const VMWSTR file_name, VMINT flag, vm_fs_overlapped_struct *overlapped)
{
    vm_fs_async_ctx_t* ctx_p;
    fs_overlapped_struct ol; // will manually set members in _vm_fs_fill_overlapped_struct
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_S, 1, __LINE__);
    
    ctx_p = vm_fs_async_malloc_context();
    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_E1, 1, __LINE__);
        return FS_DEVICE_RESOURCE_ERROR;
    }
    
    _vm_fs_fill_overlapped_struct(&ol, overlapped);
    ctx_p->app_cb = overlapped->callback;

    if (NULL == ol.buf)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_E3, 1, __LINE__);
        vm_fs_async_free_context(ctx_p);
        //_vm_kernel_free(ol.buf);    
        return FS_OUT_OF_BUFFERS;
    }

    ctx_p->ol_buf = ol.buf;
    
    if (FS_NO_ERROR >= (ctx_p->jid = fs_async_open((const kal_wchar *)file_name, (kal_int32)flag, &ol)))
    {
        fs_job_id jid_tmp = ctx_p->jid;
        _vm_kernel_free(ctx_p->ol_buf); 
        ctx_p->ol_buf = NULL;
        vm_fs_async_free_context(ctx_p);
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_E2, 1, __LINE__);
        return jid_tmp;
    }

    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_LOG, 
        ol.callback,
        ol.param,
        ol.priority,
        ol.buf_size,
        ol.buf,
        overlapped->param,       
        1, __LINE__);

    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_E, 1, __LINE__);
    
    return ctx_p->res_handle;
}

VMINT vm_fs_async_write(VM_FS_HANDLE fs_hdl, void *data, VMUINT length, VMUINT *written, vm_fs_overlapped_struct *overlapped)
{
    fs_overlapped_struct ol;
    vm_fs_async_ctx_t * ctx_p;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_S, 2, __LINE__);
    ctx_p = vm_fs_async_malloc_context();
    if (NULL == ctx_p)
    {
        return FS_DEVICE_RESOURCE_ERROR;
    }
    
    _vm_fs_fill_overlapped_struct(&ol, overlapped);
    ctx_p->app_cb = overlapped->callback;
    
    if (NULL == ol.buf)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_E2, 2, __LINE__);
        vm_fs_async_free_context(ctx_p);
        //_vm_kernel_free(ol.buf);    
        return FS_OUT_OF_BUFFERS;
    }

    ctx_p->ol_buf = ol.buf;
    
    if (FS_NO_ERROR >= (ctx_p->jid = fs_async_write((FS_HANDLE)fs_hdl, data, (kal_uint32)length, (kal_uint32 *)written, (fs_overlapped_struct *)&ol)))
    {
        fs_job_id jid_tmp = ctx_p->jid;
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_E1, ctx_p->jid, __LINE__);
        _vm_kernel_free(ctx_p->ol_buf); 
        ctx_p->ol_buf = NULL;
        vm_fs_async_free_context(ctx_p);
        return jid_tmp;
    }

    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_LOG, 
        ol.param,
        ol.priority,
        ctx_p->jid,
        ol.buf_size,
        ol.buf,
        0,
        2, __LINE__);

    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_E, 2, __LINE__);
    return ctx_p->res_handle;
}

VMINT vm_fs_async_read(VM_FS_HANDLE fs_hdl, void *data, VMUINT length, VMUINT *read, vm_fs_overlapped_struct *overlapped)
{
    fs_overlapped_struct ol;
    vm_fs_async_ctx_t * ctx_p;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_S, 3, __LINE__);
    ctx_p = vm_fs_async_malloc_context();
    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_E1, 3, __LINE__);
        return FS_DEVICE_RESOURCE_ERROR;
    }
    
    _vm_fs_fill_overlapped_struct(&ol, overlapped);
    ctx_p->app_cb = overlapped->callback;
    
    if (NULL == ol.buf)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_E3, 3, __LINE__);
        vm_fs_async_free_context(ctx_p);
        //_vm_kernel_free(ol.buf);    
        return FS_OUT_OF_BUFFERS;
    }

    ctx_p->ol_buf = ol.buf;
    
    if (FS_NO_ERROR >= (ctx_p->jid = fs_async_read((FS_HANDLE)fs_hdl, data, (kal_uint32)length, (kal_uint32 *)read, (fs_overlapped_struct *)&ol)))
    {
        fs_job_id jid_tmp = ctx_p->jid;
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_E2, ctx_p->jid, __LINE__);
        _vm_kernel_free(ctx_p->ol_buf); 
        ctx_p->ol_buf = NULL;
        vm_fs_async_free_context(ctx_p);
        return jid_tmp;
    }

        
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_LOG, 
        ol.param,
        ol.priority,
        ctx_p->jid,
        ol.buf_size,
        ol.buf,
        0,
        3, __LINE__);

    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_E, 3, __LINE__);
    return ctx_p->res_handle;
}

VMINT vm_fs_async_seek(VM_FS_HANDLE fs_hdl, VMINT64 * offset, VMINT whence, vm_fs_overlapped_struct *overlapped)
{
    fs_overlapped_struct ol;
    vm_fs_async_ctx_t * ctx_p;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_S, 4, __LINE__);
    ctx_p = vm_fs_async_malloc_context();
    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_E1, 4, __LINE__);
        return FS_DEVICE_RESOURCE_ERROR;
    }
    
    _vm_fs_fill_overlapped_struct(&ol, overlapped);
    ctx_p->app_cb = overlapped->callback;
    
    if (NULL == ol.buf)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_E3, 4, __LINE__);
        vm_fs_async_free_context(ctx_p);
        //_vm_kernel_free(ol.buf);    
        return FS_OUT_OF_BUFFERS;
    }
    
    ctx_p->ol_buf = ol.buf;

    if (FS_NO_ERROR >= (ctx_p->jid = fs_async_seek((FS_HANDLE)fs_hdl, *(kal_int64*)offset, (kal_int32)whence, (fs_overlapped_struct *)&ol)))
    {
        fs_job_id jid_tmp = ctx_p->jid;
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_E2, ctx_p->jid, __LINE__);
        _vm_kernel_free(ctx_p->ol_buf); 
        ctx_p->ol_buf = NULL;
        vm_fs_async_free_context(ctx_p);
        return jid_tmp;
    }

    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_LOG, 
        ol.param,
        ol.priority,
        ctx_p->jid,
        ol.buf_size,
        ol.buf,
        0,
        4, __LINE__);

    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_E, 4, __LINE__);
    return ctx_p->res_handle;
}

VMINT vm_fs_async_delete(const VMWSTR filename, vm_fs_overlapped_struct *overlapped)
{
    fs_overlapped_struct ol;
    vm_fs_async_ctx_t * ctx_p;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_S, 5, __LINE__);
    ctx_p = vm_fs_async_malloc_context();
    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_E1, 5, __LINE__);
        return FS_DEVICE_RESOURCE_ERROR;
    }
    
    _vm_fs_fill_overlapped_struct(&ol, overlapped);
    ctx_p->app_cb = overlapped->callback;
    
    if (NULL == ol.buf)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_E3, 5, __LINE__);
        vm_fs_async_free_context(ctx_p);
        //_vm_kernel_free(ol.buf);    
        return FS_OUT_OF_BUFFERS;
    }
    
    ctx_p->ol_buf = ol.buf;

    if (FS_NO_ERROR >= (ctx_p->jid = fs_async_delete((const kal_wchar*)filename, (fs_overlapped_struct *)&ol)))
    {
        fs_job_id jid_tmp = ctx_p->jid;
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_E2, ctx_p->jid, __LINE__);
        _vm_kernel_free(ctx_p->ol_buf); 
        ctx_p->ol_buf = NULL;
        vm_fs_async_free_context(ctx_p);
        return jid_tmp;
    }
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_LOG, 
        ol.param,
        ol.priority,
        ctx_p->jid,
        ol.buf_size,
        ol.buf,
        0,
        5, __LINE__);

    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_E, 5, __LINE__);
    return ctx_p->res_handle;
}

VMINT vm_fs_async_abort(VMINT hdl)
{
    vm_fs_async_ctx_t * ctx_p = NULL;
    VMINT size = 0;
    kal_int32 ret;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_S, 6, __LINE__);
    if (vm_res_get_data(VM_RES_TYPE_FS_ASYNC, 
        hdl, (void**)&ctx_p, &size) < 0 || NULL != ctx_p)
    {
        if (NULL == ctx_p)
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_E1, 6, __LINE__);
            return -2;
        }
    }
    
    ret = fs_async_abort(ctx_p->jid);
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_LOG, 
        ret,
        0,
        ctx_p->jid,
        ctx_p->fs_hdl,
        0,
        0,
        6, __LINE__);
        
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_S, 6, __LINE__);
    return ret;
}

VMINT vm_fs_async_commit(VM_FS_HANDLE fs_hdl)
{
    int ret;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_S, 7, __LINE__);
    ret = FS_Commit((FS_HANDLE)fs_hdl);
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_LOG, 
        0,
        0,
        fs_hdl,
        ret,
        0,
        0,
        7, __LINE__);
        
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_E, 7, __LINE__);
    return (VMINT)ret;
}

VMINT vm_fs_async_close(VM_FS_HANDLE fs_hdl)
{
    int ret;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_S, 8, __LINE__);
    ret = FS_Close(fs_hdl);
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_LOG, 
        ret,
        0,
        fs_hdl,
        0,
        0,
        0,
        8, __LINE__);
        
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_E, 8, __LINE__);
    return (VMINT)ret;

}

VMINT vm_fs_async_get_working_buf_size(void)
{
    return FS_ASYNC_WORKING_BUFFER_SIZE;
}

VMINT vm_get_trans_key(VMINT16 vm_key_code);
VMINT vm_kbd_is_key_supported(VMINT keycode)
{
    VMINT mtk_keycode;
    MMI_BOOL ret;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_KEYCODE_S, keycode, 0, 1, __LINE__);
    mtk_keycode = vm_get_trans_key((VMINT16)keycode);
    if (((VMINT)0X7FFFFFFF) == mtk_keycode)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_KEYCODE_E1, 0, 0, 1, __LINE__);
        return 0;
    }
    
    ret = mmi_frm_kbd_is_key_supported((S16)mtk_keycode);    
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_KEYCODE_S, mtk_keycode, ret, 1, __LINE__);
    return ret;
}

#include "UriAgentSrvGprot.h"

VMINT vm_uriagent_uri_request(const VMCHAR * str, VMINT confirm)
{

MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_OPERA_S, 1, __LINE__);
#ifdef __MMI_URI_AGENT__
    {
    srv_uriagent_err_enum err;

    if (srv_uriagent_has_registered_hdlr((char *)str))
    {
        err = srv_uriagent_dispatch_uri_request(
                SRV_URIAGENT_APPID_BRW,
                (char *)str,
                confirm ? 
                SRV_URIAGENT_OPTION_NEED_CONFIRM_POPUP : 
                SRV_URIAGENT_OPTION_UNSPECIFIED,
                0);
                MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_OPERA_E1, err, __LINE__);
        return err;
    }
    else
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_OPERA_E2, 1, __LINE__);
        return VM_SRV_URIAGENT_ERR_UNSUPPORTED;
    }
    }

#else

    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_OPERA_E3, 1, __LINE__);
    return -2;

#endif
//MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_OPERA_E, 1, __LINE__);
}


VMINT vm_start_native_browser(const VMWSTR url)
{
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_OPERA_S, 2, __LINE__);
    
#if defined(BROWSER_SUPPORT) && (BROWSER_SUPPORT == NONE)
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_OPERA_E1, 2, __LINE__);
    return -2;
#else
    {
        VMINT ret = 0;
        ret = vm_open_wap_url((VMWSTR)url);
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_OPERA_E2, ret, __LINE__);
        return ret;
    }
#endif
    //MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_OPERA_E, 2, __LINE__);
}

/* folder browser begin */

typedef struct _vm_folder_browser_ctx_t
{
    VMINT m_phdl;		/* process handle */
    VMINT res_handle;	/* resource handle */
	VMUINT cui_id;		/* the ID of folder browser CUI */
} vm_folder_browser_ctx_t;

extern vm_folder_browser_ctx_t* vm_folder_browser_malloc_context(void);
extern void vm_folder_browser_free_context(vm_folder_browser_ctx_t *);
extern vm_folder_browser_ctx_t* vm_folder_browser_get_context(void);

#ifdef __COSMOS_MMI_PACKAGE__
extern MMI_ID vapp_cui_folder_browser_run(const VMWCHAR *path_type, const FMGR_FILTER * filter);
#endif

#ifdef __MMI_FILE_MANAGER__
static mmi_ret vm_folder_browser_run_gproc(mmi_event_struct *evt);
#endif

/*******************************************************************************
 * FUNCTION
 *	vm_folder_browser_process_status_callback
 * DESCRIPTION
 *	manage folder browser resource when process status changed.
 * PARAMETER
 *	process_handle	:	[IN]	handle of process whose status changed.
 *	sys_state		:	[IN]	the new status of process.
 * RETURNS
 *	void
 ******************************************************************************/
static void vm_folder_browser_process_status_callback(
				VM_P_HANDLE process_handle, 
				VMINT sys_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT resHandle = 0, bufSize = 0;
	vm_folder_browser_ctx_t *ctx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sys_state)
    {
        case VM_PMNG_UNLOAD:
		{
			while ((resHandle = vm_res_findfirst(
									process_handle, 
									VM_RES_TYPE_FOLDER_BROWSER)) 
					!= VM_RES_NOT_FIND)
            {
				if (vm_res_get_data(VM_RES_TYPE_FOLDER_BROWSER, 
					resHandle, (void**) &ctx_p, &bufSize) == 0 && ctx_p != NULL)
				{
						vm_res_findclose(VM_RES_TYPE_FOLDER_BROWSER);
						
						#if defined(__COSMOS_MMI_PACKAGE__)
							vcui_folder_browser_close(ctx_p->cui_id);
						#else
							cui_folder_browser_close(ctx_p->cui_id);
						#endif

						vm_folder_browser_free_context(ctx_p);
				}

                vm_res_release_data(VM_RES_TYPE_FOLDER_BROWSER, resHandle);
            }
		}
		break;
    }
}

/*******************************************************************************
 * FUNCTION
 *	vm_initialize_folder_browser
 * DESCRIPTION
 *	handle EVT_MOD_INIT of folder browser module.
 * PARAMETER
 *	void
 * RETURNS
 *	if success, return 0; 
 *	otherwise, return -1.
 ******************************************************************************/
static VMINT vm_initialize_folder_browser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (vm_res_type_set_notify_callback(
			VM_RES_TYPE_FOLDER_BROWSER, 
			vm_folder_browser_process_status_callback)
		!= 0)
	{
        return -1;
	}

    return 0;
}

/*******************************************************************************
 * FUNCTION
 *	vm_finalize_folder_browser
 * DESCRIPTION
 *	handle EVT_MOD_RELEASE of folder browser module.
 * PARAMETER
 *	void
 * RETURNS
 *	0.
 *******************************************************************************/
static VMINT vm_finalize_folder_browser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT rHandle = VM_RES_NOT_FIND;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	while ((rHandle = vm_res_findfirst(-1, VM_RES_TYPE_FOLDER_BROWSER)) 
			!= VM_RES_NOT_FIND)
    {
        vm_res_findclose(VM_RES_TYPE_FOLDER_BROWSER);
        vm_res_release_data(VM_RES_TYPE_FOLDER_BROWSER, rHandle);
    }

    vm_res_type_set_notify_callback(VM_RES_TYPE_FOLDER_BROWSER, NULL);

    return 0;
}

/*******************************************************************************
 * FUNCTION
 *	vm_folder_browser_mod_evt_proc
 * DESCRIPTION
 *	handle MOD EVENTS of folder browser module.
 * PARAMETER
 *	event	:	[IN]	module event
 * RETURNS
 *	0.
 ******************************************************************************/
static VMINT vm_folder_browser_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event)
    {
        case EVT_MOD_INIT:
            vm_initialize_folder_browser();
            break;

        case EVT_MOD_RELEASE:
            vm_finalize_folder_browser();
            break;
    }

    return 0;
}

/*******************************************************************************
 * FUNCTION
 *	_vm_reg_folder_browser_module
 * DESCRIPTION
 *	register folder browser module.
 * PARAMETER
 *	void
 * RETURNS
 *	if success, return REG_MRE_MODULE_SUCCESS.
 *	other return value means NOT success.
 ******************************************************************************/
VMINT _vm_reg_folder_browser_module(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int res_code = REG_MRE_MODULE_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ((res_code = _vm_reg_module(
						"FOLDER BROWSER MODULE", 
						(MOD_EVT_PROCESS) vm_folder_browser_mod_evt_proc)) 
		!= REG_MRE_MODULE_SUCCESS)
    {
		/* trace what ??? */
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMIME_494 , res_code);
    }

    return res_code;
}

/*******************************************************************************
 * FUNCTION
 *	vm_folder_browser_run
 * DESCRIPTION
 *	launch folder browser CUI.
 * PARAMETER
 *	type		:	[IN]	which type of file should be shown in folder browser.
 *							the optional values are :
 *								VM_FOLDER_BROWSER_TYPE_ALL
 *								VM_FOLDER_BROWSER_TYPE_IMAGE
 *								VM_FOLDER_BROWSER_TYPE_TXT
 *	folder_path	:	[IN]	the folder that you want to enter.
 *							NOTE:	it can NOT be L"root" or only a Driver name 
 *									such as L"D:\\".
 * RETURNS
 *	if success, return VM_FOLDER_BROWSER_ERR_SUCCESS.
 *	otherwise, a value in type of vm_folder_browser_type_t will be returned.
 ******************************************************************************/
VMINT vm_folder_browser_run(VMINT type, const VMWCHAR *folder_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_gid = GRP_ID_INVALID;
    FMGR_FILTER filter;
    mmi_id temp_parent_gid;
    const VMWCHAR *path_type = NULL;
    vm_folder_browser_ctx_t *ctx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FILE_MANAGER__    

	/* 
	 * if there is already an instance of folder browser CUI, close it and free
	 * its context and resources. 
	 */
	ctx_p = vm_folder_browser_get_context();
	if (ctx_p != NULL)
	{
		#ifdef __COSMOS_MMI_PACKAGE__
			vcui_folder_browser_close(ctx_p->cui_id);
		#else
			cui_folder_browser_close(ctx_p->cui_id);
		#endif /* __COSMOS_MMI_PACKAGE__ */

		vm_folder_browser_free_context(ctx_p);
	}

	/*
	 * create an instance of folder browser CUI, and allocate context and 
	 * resources for it. 
	 */
    ctx_p = vm_folder_browser_malloc_context();
    if (!ctx_p)
    {
        return VM_FOLDER_BROWSER_ERR_NO_RES;
    }

	/*
	 * set the filter of file type (only the selected file type can be shown in folder browser.
	 */
    FMGR_FILTER_INIT(&filter);
    if (VM_FOLDER_BROWSER_TYPE_ALL == type)
    {
        FMGR_FILTER_SET(&filter, FMGR_TYPE_ALL);
    }
    else if (VM_FOLDER_BROWSER_TYPE_IMAGE == type)
    {
        FMGR_FILTER_SET_IMAGE(&filter);
    }
    else if (VM_FOLDER_BROWSER_TYPE_TXT == type)
    {
		#ifdef __MMI_EBOOK_READER__
			srv_fmgr_types_filter_set_group(&filter, FMGR_TYPE_EBOOK_TXT);
		#else
			srv_fmgr_types_filter_set_group(&filter, FMGR_GROUP_MRE_TXT);
		#endif
    }
    else
    {
		vm_folder_browser_free_context(ctx_p);
        return VM_FOLDER_BROWSER_ERR_NOT_SUPPORT;
    }
    
    ctx_p->m_phdl = vm_pmng_get_current_handle();

	/* 
	 * check folder path. 
	 * if it is NULL or L"root" or only a driver name such as L"D:\\", return error.
	 */
    if (folder_path == NULL 
		|| vm_wstrlen((VMWSTR) folder_path) <= 3 
		|| vm_wstrcmp((VMWSTR) folder_path, (VMWSTR) L"root") == 0)
    {
		vm_folder_browser_free_context(ctx_p);
        return VM_FOLDER_BROWSER_ERR_PARAM;
    }
    else
    {
		path_type = folder_path;
    }

#if defined(__COSMOS_MMI_PACKAGE__)
    if (GRP_ID_INVALID >= vapp_cui_folder_browser_run(path_type, &filter))
    {
        return VM_FOLDER_BROWSER_ERR_EXCEPTION;
    }
#else
    temp_parent_gid = mmi_frm_group_create(
							GRP_ID_ROOT, 
							GRP_ID_AUTO_GEN, 
							vm_folder_browser_run_gproc, 
							(void*)NULL); 
    mmi_frm_group_enter(temp_parent_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

	cui_gid = cui_folder_browser_create(
					temp_parent_gid,
					(WCHAR *) path_type,
					&filter,
					0,
					0,
					0);
        
    if (cui_gid > GRP_ID_INVALID)
    {
		ctx_p->cui_id = (VMUINT) cui_gid;
        cui_folder_browser_run(cui_gid);
    }
    else
    {
		vm_folder_browser_free_context(ctx_p);
        return VM_FOLDER_BROWSER_ERR_EXCEPTION;
    }
    
#endif
    return VM_FOLDER_BROWSER_ERR_SUCCESS;

#else /* __MMI_FILE_MANAGER__ */
    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMIO_2825 );
    return VM_FOLDER_BROWSER_ERR_NOT_SUPPORT;
#endif
}

/*******************************************************************************
 * FUNCTION
 *	vm_folder_browser_run_gproc
 * DESCRIPTION
 *	handle events of folder browser CUI.
 * PARAMETER
 *	evt	:	[IN]	the event of folder browser CUI.
 * RETURNS
 *	MMI_RET_OK.
 ******************************************************************************/
#ifdef __MMI_FILE_MANAGER__    
static mmi_ret vm_folder_browser_run_gproc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    vm_folder_browser_ctx_t *ctx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
	#ifdef __COSMOS_MMI_PACKAGE__
		/* 
		 * folder browser CUI will handle messages in its OnProc function in
		 * vmcuifdb.cpp
		 */
	#else
		case EVT_ID_CUI_FOLDER_BROWSER_ON_QUIT:
		{
			ctx_p = vm_folder_browser_get_context();
			if (!ctx_p)
			{
				MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMIO_2919 );
				return MMI_RET_OK;
			}

			cui_folder_browser_close(ctx_p->cui_id);
			vm_folder_browser_free_context(ctx_p);
			break;
		}
#endif /* __MMI_COSMOS_PACKAGE__ */
    }

    return MMI_RET_OK; 
}
#endif /* __MMI_FILE_MANAGER__ */

/*******************************************************************************
 * FUNCTION
 *	vm_folder_browser_malloc_context
 * DESCRIPTION
 *	malloc context for folder browser CUI.
 * PARAMETER
 *	void
 * RETURNS
 *	if success, return a pointer to the context.
 *	otherwise, return NULL.
 ******************************************************************************/
vm_folder_browser_ctx_t* vm_folder_browser_malloc_context(void)
{
    vm_folder_browser_ctx_t *ctx_p = NULL;

    if ((ctx_p = _vm_kernel_calloc(sizeof(vm_folder_browser_ctx_t))) != NULL)
    {
        if ((ctx_p->res_handle = 
				vm_res_save_data(
					VM_RES_TYPE_FOLDER_BROWSER, 
					(void*)ctx_p, 
					sizeof(ctx_p), 
					NULL, 
					vm_pmng_get_current_handle()))
			>= 0)
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_3034 , ctx_p->res_handle);
            return ctx_p;
        }
        else
        {
            _vm_kernel_free(ctx_p);
        }
    }

    return NULL;
}

/*******************************************************************************
 * FUNCTION
 *	vm_folder_browser_free_context
 * DESCRIPTION
 *	free context of folder browser CUI.
 * PARAMETER
 *	ctx_p	:	a pointer to the context which should be free.
 * RETURNS
 *	void.
 ******************************************************************************/
void vm_folder_browser_free_context(vm_folder_browser_ctx_t *ctx_p)
{
    if (ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_3051 , 
            ctx_p->res_handle);
        vm_res_release_data(VM_RES_TYPE_FOLDER_BROWSER, ctx_p->res_handle);
        _vm_kernel_free(ctx_p);
    }
}

/*******************************************************************************
 * FUNCTION
 *	vm_folder_browser_get_context
 * DESCRIPTION
 *	get context of folder browser CUI.
 * PARAMETER
 *	void
 * RETURNS
 *	if success, return a pointer to the context.
 *	otherwise, return NULL.
 *******************************************************************************/
vm_folder_browser_ctx_t * vm_folder_browser_get_context(void)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_folder_browser_ctx_t * ctx_p = NULL;
    
    if ((resHandle = vm_res_findfirst(-1, VM_RES_TYPE_FOLDER_BROWSER)) != VM_RES_NOT_FIND)
    {
        if (vm_res_get_data(VM_RES_TYPE_FOLDER_BROWSER, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
        {
                vm_res_findclose(VM_RES_TYPE_FOLDER_BROWSER);
                return ctx_p;
        }
    }   

    return NULL;
}

/******************************************************************************
 * folder selector implementation begins
 *****************************************************************************/
typedef struct _vm_folder_selector_ctx_t
{
    VMINT   m_phdl;  /* process handle who opens folder selector now. */
    VMINT   (*m_cb)(VMWCHAR *path, VMINT wlen); /* user callback function to 
                                                 * handle the result of folder 
                                                 * selection. */
    VMWCHAR *m_path;  /* it will points to selected folder's path. */
    VMINT   res_handle;
    VMUINT  cui_id;  /* we will use it to close CUI when we need to. */
} vm_folder_selector_ctx_t;

/* APIs to manage folder selector's context. */
extern vm_folder_selector_ctx_t* vm_folder_selector_malloc_context(void);
extern vm_folder_selector_ctx_t* vm_folder_selector_get_context(void);
extern void vm_folder_selector_free_context(vm_folder_selector_ctx_t*);

#ifdef __COSMOS_MMI_PACKAGE__
/* 
 * this is the entry function of folder selector CUI on COSMOS. 
 * please refer to mre/engine/sal/vmcuifdst.cpp for detailed information.
 */
extern MMI_ID vapp_cui_folder_selector_run(
    const VMWCHAR   *start_folder_path, 
    VMINT			folder_selector_style);
#endif

#if defined(__MMI_FILE_MANAGER__) && !defined(__COSMOS_MMI_PACKAGE__)
/* handle events while CUI is running, it's available only on FTE/PLUTO. */
static mmi_ret vm_folder_selector_run_gproc(mmi_event_struct *evt);
#endif

/******************************************************************************
 * FUNCTION
 *     vm_folder_selector_process_status_callback
 * DESCRIPTION
 *     if app changes its status while CUI is running, we will receive 
 *     corresponding events. This function will handle these events.
 * PARAMETERS
 *     process_handle : [IN] the handle of process who changed its status.        
 *     sys_state      : [IN] new status of the process.
 * RETURNS
 *     void
 *****************************************************************************/
static void vm_folder_selector_process_status_callback(
    VM_P_HANDLE process_handle, 
    VMINT       sys_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT                       resHandle   = 0;
    VMINT                       bufSize     = 0;
    vm_folder_selector_ctx_t    *ctx_p      = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /*
     * if app exits, we will do 3 things:
     *     (1) close folder selector CUI.
     *     (2) free context (memory).
     *     (3) release resource.
     */
    if (sys_state == VM_PMNG_UNLOAD)
    {
        while ((resHandle = vm_res_findfirst(
                    process_handle, 
                    VM_RES_TYPE_FOLDER_SELECTOR)) != VM_RES_NOT_FIND)
        {
            if (vm_res_get_data(
                    VM_RES_TYPE_FOLDER_SELECTOR, 
                    resHandle, 
                    (void**) &ctx_p, 
                    &bufSize) == 0 
                && ctx_p != NULL)
            {
                vm_res_findclose(VM_RES_TYPE_FOLDER_SELECTOR);
                    
                #if defined(__COSMOS_MMI_PACKAGE__) /* on COSMOS. */
                    vcui_folder_selector_close(ctx_p->cui_id);
                #else /* on FTE/PLUTO. */
                    cui_folder_selector_close(ctx_p->cui_id);
                #endif

                vm_folder_selector_free_context(ctx_p);
            }
            
            vm_res_release_data(VM_RES_TYPE_FOLDER_SELECTOR, resHandle);
        }
    }
}

/******************************************************************************
 * FUNCTION
 *     vm_folder_selector_initialize
 * DESCRIPTION
 *     handle EVT_MOD_INIT of folder selector. And we will register a callback
 *     function (vm_folder_selector_process_status_callback) to handle process 
 *     status change.
 * PARAMETERS
 *     void
 * RETURNS
 *     0  : success to register callback function.
 *     -1 : fail to register it.
 *****************************************************************************/
static VMINT vm_folder_selector_initialize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vm_res_type_set_notify_callback(
            VM_RES_TYPE_FOLDER_SELECTOR, 
            vm_folder_selector_process_status_callback) != 0)
    {
        return -1;
    }

    return 0;
}

/******************************************************************************
 * FUNCTION
 *     vm_folder_selector_finalize
 * DESCRIPTION
 *     handle EVT_MOD_RELEASE of folder selector. We will release resource 
 *     and unregister the callback function (handle process status change).
 * PARAMETERS
 *     void
 * RETURNS
 *     0.
 *****************************************************************************/
static VMINT vm_folder_selector_finalize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT rHandle = VM_RES_NOT_FIND;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((rHandle = vm_res_findfirst(-1, VM_RES_TYPE_FOLDER_SELECTOR)) 
           != VM_RES_NOT_FIND)
    {
        vm_res_findclose(VM_RES_TYPE_FOLDER_SELECTOR);
        vm_res_release_data(VM_RES_TYPE_FOLDER_SELECTOR, rHandle);
    }
    
    vm_res_type_set_notify_callback(VM_RES_TYPE_FOLDER_SELECTOR, NULL);

    return 0;
}

/******************************************************************************
 * FUNCTION
 *     vm_folder_selector_mod_evt_proc
 * DESCRIPTION
 *     handle module events of folder selector. We will dispatch each event to
 *     its corresponding handler.
 * PARAMETERS
 *     event : [IN] an event of file selector module.       
 * RETURNS
 *     0.
 *****************************************************************************/
static VMINT vm_folder_selector_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event)
    {
        case EVT_MOD_INIT:
            vm_folder_selector_initialize();
            break;

        case EVT_MOD_RELEASE:
            vm_folder_selector_finalize();
            break;
    }
    
    return 0;
}

/******************************************************************************
 * FUNCTION
 *     _vm_reg_folder_selector_module
 * DESCRIPTION
 *     register folder selector module into MRE environment.
 * PARAMETERS
 *     void
 * RETURNS
 *     REG_MRE_MODULE_SUCCESS means success to register this module.
 *     other values means fail to register it.
 *****************************************************************************/
VMINT _vm_reg_folder_selector_module(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return _vm_reg_module(
               "FOLDER SELECTOR MODULE", 
               (MOD_EVT_PROCESS) vm_folder_selector_mod_evt_proc);
}

/******************************************************************************
 * FUNCTION
 *     vm_folder_selector_run
 * DESCRIPTION
 *     Start a file manager to select a folder.
 * PARAMETERS
 *     start_folder_path     : [IN] the path of start folder. when file manager
 *                                  is opened, it will enter this folder 
 *                                  directly.
 *     folder_selector_style : [IN] if it's VM_FOLDER_SELECTOR_STYLE_READ, that
 *                                      means you can NOT create a folder, 
 *                                      rename it or delete it.
 *                                  if it's VM_FOLDER_SELECTOR_STYLE_WRITE, that
 *                                      means you can create a folder, rename it
 *                                      , or delete it. 
 *     callback              : [IN] user provided callback function. when a 
 *                                  folder is selected, this function will be
 *                                  called to handle the selection. 
 *                                  selected_folder_path indicates which folder
 *                                      is selected. if it's NULL, that means 
 *                                      an error occurs.
 *                                  wlen is the length of selected folder's path
 *                                      in words.
 * RETURNS
 *     VM_FOLDER_SELECTOR_ERR_SUCCESS : the CUI runs successfully.
 *     other values means an error occurs, please refer to 
 *     vm_folder_selector_error_t for detailed information.
******************************************************************************/
VMINT vm_folder_selector_run(
    const VMWCHAR   *start_folder_path,
    VMINT           folder_selector_style,
    VMINT           (*callback)(VMWCHAR *selected_folder_path, VMINT wlen))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID                      cui_gid             = GRP_ID_INVALID;
    mmi_id                      temp_parent_gid;
    vm_folder_selector_ctx_t    *ctx_p              = NULL;
    const VMWCHAR               *start_folder       = NULL;
    VMINT						selector_style;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

/* 
 * this function is available only when __MMI_FILE_MANAGER__ is defined.
 * otherwise, return VM_FOLDER_SELECTOR_ERR_NOT_SUPPORT directly.
 */
#ifdef __MMI_FILE_MANAGER__    

	/* 
     * if there is already an instance of folder selector CUI, close it and free
     * its context and resources. 
     */
    ctx_p = vm_folder_selector_get_context();
    if (ctx_p != NULL)
    {
        #ifdef __COSMOS_MMI_PACKAGE__
            vcui_folder_selector_close(ctx_p->cui_id);
        #else
            cui_folder_selector_close(ctx_p->cui_id);
        #endif /* __COSMOS_MMI_PACKAGE__ */

        vm_folder_selector_free_context(ctx_p);
    }

    /*
     * if user gives a valid folder path, we will use it directly.
     * otherwise, we will use "root" as the start folder.
     */
    start_folder 
    	= (start_folder_path == NULL) ? (const VMWCHAR *)SRV_FMGR_PATH_ROOT : (const VMWCHAR *)start_folder_path;
    
    /*
     * we provide 2 style now : read or write.
     * if the styles are modified in the future, you may need to modify the code
     * below.
     */
    if (folder_selector_style == VM_FOLDER_SELECTOR_STYLE_READ)
    {
    	selector_style = CUI_FOLDER_SELECTOR_STYLE_READ;
    }
    else if (folder_selector_style == VM_FOLDER_SELECTOR_STYLE_WRITE)
    {
    	selector_style = CUI_FOLDER_SELECTOR_STYLE_WRITE;
    }
    else
    {
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMIO_2727);
        return VM_FOLDER_SELECTOR_ERR_PARAM;
    }
    
    if (callback == NULL)
    {
    	MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMIO_2727);
    	return VM_FOLDER_SELECTOR_ERR_PARAM;
    }
    
    /* allocate memory and resource for context. */
    ctx_p = vm_folder_selector_malloc_context();
    if (!ctx_p)
    {
        return VM_FOLDER_SELECTOR_ERR_NO_RES;
    }
    
    /* fill the value of file selector context. */
    ctx_p->m_phdl = vm_pmng_get_current_handle();
    ctx_p->m_cb = callback;

    /* run file selector CUI. */
    #if defined(__COSMOS_MMI_PACKAGE__) /* on COSMOS. */
        if (vapp_cui_folder_selector_run(start_folder, selector_style) 
        	<= GRP_ID_INVALID)
        {
            vm_folder_selector_free_context(ctx_p);
            return VM_FOLDER_SELECTOR_ERR_EXCEPTION;
        }
    #else /* on FTE/PLUTO. */
        temp_parent_gid = mmi_frm_group_create(
            GRP_ID_ROOT, 
            GRP_ID_AUTO_GEN, 
            vm_folder_selector_run_gproc, 
            (void*) NULL); 
        mmi_frm_group_enter(temp_parent_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

        cui_gid = cui_folder_selector_create(
            temp_parent_gid,
            (WCHAR*) start_folder,
            selector_style,
            CUI_FOLDER_SELECTOR_OPT_FIXED_PATH_ON
            | CUI_FOLDER_SELECTOR_OPT_FOLDER_TRAVERSE_SUB);
               
        if (cui_gid > GRP_ID_INVALID)
        {
            ctx_p->cui_id = (VMUINT) cui_gid;
            cui_folder_selector_run(cui_gid);
        }
        else
        {   
            vm_folder_selector_free_context(ctx_p);
            return VM_FOLDER_SELECTOR_ERR_EXCEPTION;
        }  
    #endif /* __COSMOS_MMI_PACKAGE__ */
    
    /* CUI runs successfully. */
    return VM_FOLDER_SELECTOR_ERR_SUCCESS;
    
#else /* __MMI_FILE_MANAGER__ not defined. */

    MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMIO_2825 );
    return VM_FOLDER_SELECTOR_ERR_NOT_SUPPORT;
    
#endif /* __MMI_FILE_MANAGER__ */
}

/******************************************************************************
 * FUNCTION
 *     vm_folder_selector_run_gproc
 * DESCRIPTION
 *     handle events of folder selector CUI while it is running.
 * PARAMETERS
 *     evt : [IN] which event happened.
 * RETURNS
 *     MMI_RET_OK : 
 *****************************************************************************/
#if defined(__MMI_FILE_MANAGER__) && !defined(__COSMOS_MMI_PACKAGE__)
static mmi_ret vm_folder_selector_run_gproc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_folder_selector_ctx_t *ctx_p 					 = NULL;
    mmi_ret					 success_to_handle_selection = MMI_RET_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
    	case EVT_ID_CUI_FOLDER_SELECTOR_RESULT:
        {
            cui_folder_selector_result_event_struct *sel_evt = NULL;
                        
            ctx_p = vm_folder_selector_get_context();
            if (!ctx_p)
            {
                return !MMI_RET_OK;
            }
            
            sel_evt = (cui_folder_selector_result_event_struct*) evt;
            if (sel_evt->result > 0) /* we got a selection here. */
            {
            	VMWCHAR folder_path[SRV_FMGR_PATH_MAX_LEN + 1] = {0};
            	
            	if (cui_folder_selector_get_selected_filepath(
                    	sel_evt->sender_id,
                    	NULL,
                    	(WCHAR*) folder_path,
                    	sizeof(folder_path)) == 0) /* got the folder path. */
                {
                    ctx_p->m_path = (VMWCHAR*) folder_path;
                
	                /* call user's callback function to handle the selection. */
	                if (ctx_p->m_cb != NULL 
	                    && ctx_p->m_phdl != NULL
	                    && vm_pmng_set_ctx(ctx_p->m_phdl) == VM_PMNG_OP_OK)
	                {
	                    ctx_p->m_cb(ctx_p->m_path, vm_wstrlen(ctx_p->m_path));
	                    vm_pmng_reset_ctx();
	                    success_to_handle_selection = MMI_RET_OK;
	                }
	                else
	                {
	                    ctx_p->m_path = NULL;
	                    success_to_handle_selection = !MMI_RET_OK;
	                }
	            }
	            else /* can NOT get the selected folder's path. */
	            {
	            	success_to_handle_selection = !MMI_RET_OK;
	        	}
            }
            else /* no folder is selected. */
            {
                mmi_popup_display(
                    (WCHAR*) ((U16*) GetString(
                        srv_fmgr_fs_error_get_string(sel_evt->result))), 
                    srv_fmgr_fs_error_get_popup_type(sel_evt->result), 
                    NULL);
                success_to_handle_selection = !MMI_RET_OK;
            }
			
			/* close CUI and free all memory and resource. */
            cui_folder_selector_close(sel_evt->sender_id);
            vm_folder_selector_free_context(ctx_p);
            
            /* 
             * if we got the selected folder's path and success to call user's
             * callback function to handle the selection, return MMI_RET_OK.
             * else, return !MMI_RET_OK.
             */
            return success_to_handle_selection;
        }
        break;
    }

    return MMI_RET_OK;
}
#endif /* __MMI_FILE_MANAGER__ */

/******************************************************************************
 * FUNCTION
 *     vm_folder_selector_malloc_context
 * DESCRIPTION
 *     allocate memory for folder selector context. we use the context to store
 *     associated app handle, CUI id, selected folder's path, associated 
 *     callback function, and so on.
 * PARAMETERS
 *     void
 * RETURNS
 *     if success, return a pointer to the context memory.
 *     otherwise, return NULL.
 *****************************************************************************/
vm_folder_selector_ctx_t* vm_folder_selector_malloc_context(void)
{
    vm_folder_selector_ctx_t* ctx_p = NULL;

    if ((ctx_p = _vm_kernel_calloc(sizeof(vm_folder_selector_ctx_t))) != NULL)
    {
        if ((ctx_p->res_handle = vm_res_save_data(
                VM_RES_TYPE_FOLDER_SELECTOR, 
                (void*) ctx_p, 
                sizeof(ctx_p), 
                NULL, 
                vm_pmng_get_current_handle())) >= 0)
        {            
            return ctx_p;
        }
        else
        {
            _vm_kernel_free(ctx_p);
        }
    }

    /* failed to allocate memory for context. */
    return NULL;
}

/******************************************************************************
 * FUNCTION
 *     vm_folder_selector_free_context
 * DESCRIPTION
 *     free the memory for folder selector context.
 * PARAMETERS
 *     ctx_p : [IN] pointer to memory to be released.
 * RETURNS
 *     void.
 *****************************************************************************/
void vm_folder_selector_free_context(vm_folder_selector_ctx_t *ctx_p)
{
    if (ctx_p)
    {
        vm_res_release_data(VM_RES_TYPE_FOLDER_SELECTOR, ctx_p->res_handle);
        _vm_kernel_free(ctx_p);
    }
}

/******************************************************************************
 * FUNCTION
 *     vm_folder_selector_get_context
 * DESCRIPTION
 *     get memory for folder selector context.
 * PARAMETERS
 *     void.
 * RETURNS
 *     if success, return a pointer to the context memory.
 *     otherwise, return NULL.
 *****************************************************************************/
vm_folder_selector_ctx_t* vm_folder_selector_get_context(void)
{
    VMINT                       resHandle   = 0;
    VMINT                       bufSize     = 0;
    vm_folder_selector_ctx_t    *ctx_p      = NULL;
    
    if ((resHandle = vm_res_findfirst(-1, VM_RES_TYPE_FOLDER_SELECTOR)) 
        != VM_RES_NOT_FIND)
    {
        if (vm_res_get_data(
                VM_RES_TYPE_FOLDER_SELECTOR, 
                resHandle, 
                (void**) &ctx_p, 
                &bufSize) == 0 
            && ctx_p != NULL)
        {
            vm_res_findclose(VM_RES_TYPE_FOLDER_SELECTOR);
            return ctx_p;
        }
    }

    /* if can't get context, return NULL. */
    return NULL;
}

/******************************************************************************
 * folder selector implementation ends
 *****************************************************************************/

#include "app_zlib.h"

static void * (*g_app_malloc)(VMUINT items, VMUINT size);
static void (*g_app_free)(void * address);
static VM_P_HANDLE g_zphdl;
extern vm_app_mem_struct g_app_mem_info[];
//#define NATIVE_TST
static void *vm_io_unzip_malloc(void *opaque, unsigned int items, unsigned int size)
{
    unsigned int total_bytes;
    void *buffer_ptr = NULL;
#ifdef NATIVE_TST
 
    VMINT mem_idx;
#endif
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_ZLIB_S, 2, __LINE__);
    if (opaque)
    {
        items += size - size;   /// make compiler happy
    }
    total_bytes = items * size;
    
    #ifdef NATIVE_TST
    for (mem_idx=0; mem_idx<MRE_SUPPORT_MAX_VSM_NUM; mem_idx++)
    {
        if (g_app_mem_info[mem_idx].p_handle == g_zphdl)
        {
            break;
        }
    }
    buffer_ptr = kal_adm_alloc(g_app_mem_info[mem_idx].adm_id, total_bytes);
    #else
    if (VM_PMNG_OP_OK == vm_pmng_set_ctx(g_zphdl))
    {
        buffer_ptr = g_app_malloc((VMUINT)items, (VMUINT)size);
        vm_pmng_reset_ctx();
    }
    #endif

    ASSERT(buffer_ptr != NULL);

    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_ZLIB_E, 2, buffer_ptr);
    return buffer_ptr;

}


static void vm_io_unzip_free(void *opaque, void *address)
{

#ifdef NATIVE_TST
    VMINT mem_idx;

    for (mem_idx=0; mem_idx<MRE_SUPPORT_MAX_VSM_NUM; mem_idx++)
    {
        if (g_app_mem_info[mem_idx].p_handle == g_zphdl)
        {
            break;
        }
    }

    kal_adm_free(g_app_mem_info[mem_idx].adm_id, address);

#else
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_ZLIB_S, 3, __LINE__);


    if (VM_PMNG_OP_OK == vm_pmng_set_ctx(g_zphdl))
    {
        g_app_free((void *)address);
        
        vm_pmng_reset_ctx();
    }

    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_ZLIB_E, 3, address);
#endif
}



VMINT vm_uncompress(const vm_zip_t * info, void * (*app_malloc)(VMUINT items, VMUINT size), void (*app_free)(void * address))
{
    VMINT ret;
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_ZLIB_S, 1, __LINE__);
    if (!info->dst || !info->src || !info->dst_size ||
        !app_malloc || !app_free)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_ZLIB_E1, 1, __LINE__);
        return -2;
    }

    g_zphdl = vm_pmng_get_current_handle();
    
    g_app_malloc = app_malloc;
    g_app_free = app_free;

    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_VMIO_ASYNC_FS_LOG, 
        g_zphdl,
        0,
        0,
        0,
        g_app_malloc,
        g_app_free,
        1, __LINE__);
    
    ret = uncompress_mtk((Bytef * )info->dst, (uLongf *)&(info->dst_size), (const Bytef *)info->src, (uLong)info->src_size, vm_io_unzip_malloc, vm_io_unzip_free);
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMIO, TRC_MRE_ZLIB_E, 1, ret);
    return ret;

    
}

#endif /* __MRE_CORE_BASE__ */
