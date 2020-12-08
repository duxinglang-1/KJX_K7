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
 * Vfilere.h
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
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
#ifndef		_VM_FILE_REMAP_
#define		_VM_FILE_REMAP_

#include "vmsys.h"
#include "vmio.h"

#define REMAP_FILENAME_MAX_LEN 260
//#define REMAP_FILENAME_MAX_LEN 48


#define VM_PERMISSION_SYS_DRV  1
#define VM_PERMISSION_USR_DRV  2

/*****************************************************************************
* FUNCTION
 *    vm_file_open_remap
 * DESCRIPTION
 *  open remapped local file 
 * PARAMETERS
 *  filename : [IN]  file full path encoding with UCS2
 *  mode : [IN] file open mode:
 *                MODE_READ: Read-Only
 *                MODE_WRITE : Read-Write
 *                MODE_CREATE_ALWAYS_WRITE : Read-Write mode, create if the file not exist.
 *  binary : [IN] TRUE means open with binary format, FALSE means open with ASCII format.
 * RETURNS
 *  non-negative file handle if successfully, and error code if failed to open. 
 *
*****************************************************************************/
VMFILE vm_file_open_remap(const VMWSTR filename, VMUINT mode, VMUINT binary);


/*****************************************************************************
* FUNCTION
 *    vm_file_delete_remap
 * DESCRIPTION
 *  delete remapped local file 
 * PARAMETERS
 *  handle : [IN]  file handle to be closed.
 * RETURNS
 *  zero if successfully, and error code if failed to delete. 
 *
*****************************************************************************/
VMINT vm_file_delete_remap(const VMWSTR filename);


/*****************************************************************************
* FUNCTION
 *    vm_file_rename_remap
 * DESCRIPTION
 *  rename remapped local file.
 * PARAMETERS
 *  filename : [IN]  old file name full path encoding with UCS2 format.
 *  newname : [IN]  new file name full path encoding with UCS2 format.
 * RETURNS
 *  rename file successfully or failed
 * RETURN VALUES                                      
 *  0 : rename file successfully.
 *  non-zero : failed to rename file.
 * 
*****************************************************************************/
VMINT vm_file_rename_remap(const VMWSTR filename, const VMWSTR newname);


/*****************************************************************************
* FUNCTION
 *    vm_find_first_remap
 * DESCRIPTION
 *  find files from specified path, support wild character finding.
 * PARAMETERS
 *  pathname : [IN]  path name encoding with UCS2 format.
 *  info : [OUT] result of finding
 * RETURNS
 *  find handle or error code
 * RETURN VALUES                                      
 *  non-negative number : find handle.
 *  negative number : error code.
 *
*****************************************************************************/
VMINT vm_find_first_remap(VMWSTR pathname, struct vm_fileinfo_t* info);


/*****************************************************************************
* FUNCTION
 *    vm_file_mkdir_remap
 * DESCRIPTION
 *  create new directory with specified path name.
 * PARAMETERS
 *  dirname : [IN]  path name encoding with UCS2 format.
 * RETURNS
 *  create directory successfully or failed
 * RETURN VALUES                                      
 *  0 : create directory successfully.
 *  non-zero : failed to create directory.
 *
*****************************************************************************/
VMINT vm_file_mkdir_remap(const VMWSTR dirname);


/*****************************************************************************
* FUNCTION
 *    vm_file_rmdir_remap
 * DESCRIPTION
 *  remove directory with specified path name.
 * PARAMETERS
 *  dirname : [IN]  path name encoding with UCS2 format.
 * RETURNS
 *  remove directory successfully or failed
 * RETURN VALUES                                      
 *  0 : remove directory successfully.
 *  non-zero : failed to remove directory.
 *
*****************************************************************************/
VMINT vm_file_rmdir_remap(const VMWSTR dirname);

/*****************************************************************************
* FUNCTION
 *    vm_find_first_remap_ext
 * DESCRIPTION
 *  continue to find next file.
 * PARAMETERS
 *  handle : [IN]  find handle.
 *  info : [OUT] result of finding
 * RETURNS
 *  find handle or error code
 * RETURN VALUES                                      
 *  0 : find next file successfully.
 *  negative number : end of finding.
 *
*****************************************************************************/
VMINT vm_find_first_remap_ext(VMWSTR pathname,  vm_fileinfo_ext * direntry);

/*****************************************************************************
* FUNCTION
 *    vm_file_set_attributes_remap
 * DESCRIPTION
 *  set attributes of specified full path file name encoding with UCS2 format. The attributes
 *  can not include VM_FS_ATTR_VOLUME, VM_FS_ATTR_DIR, or VM_FS_LONGNAME_ATTR.
 *  The value of attributes is the result of OR operator.
 * PARAMETERS
 *  filename : [IN]  file name encoding with UCS2 format.
 *  attributes : [IN]  file attributes.
 * RETURNS
 *  set attributes successfully or failed
 * RETURN VALUES                                      
 *  0 : set attributes successfully.
 *  non-zero : failed to set attributes.
 *
*****************************************************************************/
VMINT vm_file_set_attributes_remap(const VMWSTR filename, VMBYTE attributes);

/*****************************************************************************
* FUNCTION
 *    vm_file_get_attributes_remap
 * DESCRIPTION
 *  set attributes of specified full path file name encoding with UCS2 format. 
 *  The value of attributes is the result of OR operator.
 * PARAMETERS
 *  filename : [IN]  file name encoding with UCS2 format.
 * RETURNS
 *  get attributes successfully or failed
 * RETURN VALUES                                      
 *  0 : get attributes successfully.
 *  non-zero : failed to get attributes.
 *
*****************************************************************************/
VMINT vm_file_get_attributes_remap(const VMWSTR filename);

#endif
