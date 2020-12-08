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
 *  FileMgrSrvGProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  File Manager Service exported APIs.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef SRV_FMGR_GPROT_H
#define SRV_FMGR_GPROT_H

#include "kal_general_types.h"

#include "MMI_features.h"
// by RHR //#include "mmi_platform.h"
#include "MMIDataType.h"

#include "fs_errcode.h"
#include "fs_type.h"
// by RHR //#include "fs_func.h"

#include "fmt_def.h"        /* for FMT_MAX_DRIVE */

#include "mmi_rp_file_type_def.h"
#include "custom_mmi_default_value.h"
#include "mmi_res_range_def.h"

#ifdef __cplusplus 
extern "C" {
#endif


/* DOM-NOT_FOR_SDK-BEGIN */
/* temporary - begin */
/*
#ifndef __FMGR_SRV_WORK_BUF_FROM_ASM__
#define __FMGR_SRV_WORK_BUF_FROM_ASM__
#endif
*/
/* temporary - end */
/* DOM-NOT_FOR_SDK-END */

#define SRV_FMGR_COMMON
/*****************************************************************************
 *                    Common
 */

/* <GROUP Common>
 * error that fmgr service may return
 * for error code not listed here, see also FS error (in fs_errcode.h) */
typedef enum
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    SRV_FMGR_ERROR_BASE = FS_MINIMUM_ERROR_CODE + 10,
    /* DOM-NOT_FOR_SDK-END */
        
    SRV_FMGR_ERROR_OUT_OF_MEMORY,   /* when caller does not provide memory allocator
                                     * service will use internal memory, this error
                                     * is return when run out of internal memory */

    /* DOM-NOT_FOR_SDK-BEGIN */
    SRV_FMGR_ERROR_END
    /* DOM-NOT_FOR_SDK-END */
} srv_fmgr_error_enum;

/* DOM-NOT_FOR_SDK-BEGIN */
/*
 * DESCRIPTION
 *  service init, only call by bootup
 */
void        srv_fmgr_init(void);
/* DOM-NOT_FOR_SDK-END */

/* <GROUP Common>
 * DESCRIPTION
 *  Set the global sort option, the values can be FS_SORT_NAME, 
 *  FS_SORT_SIZE, FS_SORT_ATTR, etc...
 * PARAMETERS
 *  sort_option             : [IN]  sort option, see FS_SORT_NAME in
 *                                  FS_type.h
 * RETURNS
 *  > 0, means success, and value is changed.
 *  = 0, means success, and value is the same so there is no change.
 *  < 0, means fail, new value is invalid.
 */
S32 srv_fmgr_sort_set(U32 sort_option);

/* <GROUP Common>
 * DESCRIPTION
 *  Get the global sort option, the values can be FS_SORT_NAME, 
 *  FS_SORT_SIZE, FS_SORT_ATTR, etc...
 *  The default value (after 1st bootup) is sort by name.
 * RETURNS
 *  sort_option, see see FS_SORT_NAME in FS_type.h
 */
U32  srv_fmgr_sort_get(void);

/* <GROUP Common>
 * DESCRIPTION
 *  Map file system return error cause to displayable error string id.
 * PARAMETERS
 *  fs_error                : [IN]  fs error code, see fs_errcode.h
 * RETURNS
 *  string id of error
 */
mmi_str_id  srv_fmgr_fs_error_get_string(S32 fs_error);

/* <GROUP Common>
 * DESCRIPTION
 *  Popup rule related API. Query popup type of an fs error, it is used in mmi_display_popup
 * PARAMETERS
 *  fs_error                : [IN]  fs error code, see fs_errcode.h
 * RETURNS
 *  mmi_event_notify_enum
 */
S32         srv_fmgr_fs_error_get_popup_type(S32 fs_error);

/* <GROUP Common>
 * DESCRIPTION
 *  Popup rule related API. Query popup type / string of an fs error
 * PARAMETERS
 *  fs_error                : [IN]  fs error code, see fs_errcode.h
 *  popup_type              : [OUT] popup type, see mmi_event_notify_enum
 * RETURNS
 *  string id of error
 */
mmi_str_id  srv_fmgr_fs_error_get_string_and_popup_type(S32 fs_error, S32* popup_type);

#define SRV_FMGR_STORAGE
/*****************************************************************************
 *                    Drive/storage related service 
 *
 *  drive letter: C, D, E, F, G, etc..
 *  drive type: SRV_FMGR_DRV_PHONE_TYPE, SRV_FMGR_DRV_CARD_TYPE, SRV_FMGR_DRV_OTG_TYPE, ...
 *  drive name: "Phone", "Memory card", "OTG storage", etc...
 */

/* <GROUP Storage service macro>
 * The maximum length of a drive's name, NOT including null character */
#define SRV_FMGR_DRV_MAX_NAME_LEN       (16)

/* <GROUP Storage service macro>
 * The maximum size of a drive's volume, can be 5 UCS2 or 11 Ascii characters */
#define SRV_FMGR_DRV_MAX_VOLUME_SIZE    (12)

/* <GROUP Storage service macro>
 * Invisble in USB mode, NOR flash, fast but (possibly) smaller.
 * Typically used to store important system internal data */
#define SRV_FMGR_SYSTEM_DRV         FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_NO_ALT_DRIVE)

/* <GROUP Storage service macro>
 * Invisible in USB mode.
 * NAND flash or NOR flash.
 * Large size if it is on NAND flash.
 * Typically used to store data that should be invisible in USB mode. 
 * (e.g. DRM files, thumbnail image cache) */
#define SRV_FMGR_PRIVATE_DRV        FS_GetDrive(FS_DRIVE_I_SYSTEM, 2, FS_ONLY_ALT_SERIAL )

/* <GROUP Storage service macro>
 * Visible in USB mode if the phone has visible partitions.
 * NAND flash or NOR flash.
 * Large size if it is on NAND flash.
 * Typically used to store large data such as Camera pictures, voice memo, ... */
#define SRV_FMGR_PUBLIC_DRV         FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_V_REMOVABLE)

/* <GROUP Storage service macro>
 * Visible in USB mode if the phone has visible partitions.
 * NAND flash or NOR flash.
 * Large size if it is on NAND flash.
 * Typically used to store large data such as Camera pictures, voice memo, ... */
#define SRV_FMGR_PHONE_DRV          FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL)

/* <GROUP Storage service macro>
 * Memory Card. 
 * Visible in USB mode.
 * NAND flash.
 * < 0 if the configuration does not contain any memory card. */
#define SRV_FMGR_CARD_DRV           FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE)

/* <GROUP Storage service macro>
 * 2nd Memory Card. 
 * Visible in USB mode.
 * NAND flash.
 * < 0 if the configuration does not contain 2nd memory card. */
#define SRV_FMGR_CARD2_DRV          FS_GetDrive(FS_DRIVE_V_REMOVABLE, 2, FS_NO_ALT_DRIVE)

/* <GROUP Storage service macro>
 * type of fmgr supported drive, including Phone, Card, OTG, SIM+ */
typedef enum
{
    SRV_FMGR_DRV_PHONE_TYPE,    /* Phone drive */
    SRV_FMGR_DRV_PHONE_2_TYPE,  /* 2nd Phone drive */

    SRV_FMGR_DRV_CARD_TYPE,     /* Memory card drive */
    SRV_FMGR_DRV_CARD_2_TYPE,   /* 2nd Memory card drive */

    SRV_FMGR_DRV_OTG_TYPE,      /* OTG drive */
    SRV_FMGR_DRV_OTG_2_TYPE,    /* OTG drive 2 */
    SRV_FMGR_DRV_OTG_3_TYPE,    /* OTG drive 3 */
    SRV_FMGR_DRV_OTG_4_TYPE,    /* OTG drive 4 */
    SRV_FMGR_DRV_OTG_5_TYPE,    /* OTG drive 5 */
    SRV_FMGR_DRV_OTG_6_TYPE,    /* OTG drive 6 */
    SRV_FMGR_DRV_OTG_7_TYPE,    /* OTG drive 7 */
    SRV_FMGR_DRV_OTG_8_TYPE,    /* OTG drive 8 */

    SRV_FMGR_DRV_SIMPLUS_TYPE,  /* SIM+ drive */
    SRV_FMGR_DRV_SIMPLUS_2_TYPE,/* SIM+ drive 2 */
    SRV_FMGR_DRV_SIMPLUS_3_TYPE,/* SIM+ drive 3 */
    SRV_FMGR_DRV_SIMPLUS_4_TYPE,/* SIM+ drive 4 */

    /* DOM-NOT_FOR_SDK-BEGIN */
    SRV_FMGR_DRV_TOTAL
    /* DOM-NOT_FOR_SDK-END */
} srv_fmgr_drv_type_enum;

/* <GROUP Storage service>
 * DESCRIPTION
 *  Init drv/storage service
 */
void        srv_fmgr_drv_init(void);

/* <GROUP Storage service>
 * DESCRIPTION
 *  Query name of a drive. For memory card, volume name is returned.
 *  Maximum length is SRV_FMGR_DRV_MAX_NAME_LEN.
 * PARAMETERS
 *  drv_letter              : [IN]  drive letter
 *  name_buf                : [OUT] buffer to store drive name, can be NULL to 
 *                                  query required length and prepare buffer.
 *  name_buf_size           : [IN]  size of buffer (in bytes, including null chracters)
 * RETURNS
 *  if name_buf is NULL, return actual length (in characters)
 *  if not, return 0 if succeeded, < 0 if there is FS error (see fs_errcode.h)
 */
S32         srv_fmgr_drv_get_name(U8 drv_letter, WCHAR* name_buf, S32 name_buf_size);

/* <GROUP Storage service>
 * DESCRIPTION
 *  Query string id of a drive.
 * PARAMETERS
 *  drv_letter              : [IN]  drive letter
 * RETURNS
 *  string id of drive name
 */
mmi_str_id  srv_fmgr_drv_get_string(U8 drv_letter);

/* <GROUP Storage service>
 * DESCRIPTION
 *  Query type of a drive. see srv_fmgr_drv_type_enum for more detail.
 *  if drv_letter is not support, -1 is returned.
 * PARAMETERS
 *  drv_letter              : [IN]  drive letter
 * RETURNS
 *  >= 0: drive type. see also srv_fmgr_drv_type_enum
 *  -1 if drive not support.
 */
S32 srv_fmgr_drv_get_type(U8 drv_letter);

/* <GROUP Path service>
 * DESCRIPTION
 *  return a string contain invalid characters, including:
 *  /, \\, :, *, ?, ", <, >, |, +, ,, ., ;, =, [], \\n, \\r
 * RETURNS
 *  pointer to invalid characters
 */
const WCHAR*    srv_fmgr_drv_get_invalid_chars(void);

/* <GROUP Storage service>
 * DESCRIPTION
 *  Query size information of a drive
 * PARAMETERS
 *  drv_letter              : [IN]  drive letter
 *  total_size              : [OUT] return total_size, can be NULL
 *  free_size               : [OUT] return free_size, can be NULL
 * RETURNS
 *  0 if size successfully queried
 *  < 0 if there is FS error (see fs_errcode.h)
 */
S32         srv_fmgr_drv_get_size(U8 drv_letter, U64* total_size, U64* free_size);

/* <GROUP Storage service>
 * DESCRIPTION
 *  check if a drive still have give space, if space is not enough,
 *  FS_DISK_FULL is returned.
 * PARAMETERS
 *  drv_letter              : [IN]  drive letter
 *  size_required           : [IN]  size required
 * RETURNS
 *  0 if there is still enough free space
 *  < 0 if there is FS error (see fs_errcode.h)
 */
S32         srv_fmgr_drv_check_free_size(U8 drv_letter, U64 size_required);

/* <GROUP Storage service>
 * DESCRIPTION
 *  Check if a drive is accessible (successfully mounted)
 *  It is a wrapper of FS_GetDevStatus(drv, FS_MOUNT_STATE_ENUM) == FS_NO_ERROR 
 * PARAMETERS
 *  drv_letter              : [IN]  drive letter
 * RETURNS
 *  MMI_TRUE if accessible, MMI_FALSE if not
 */
MMI_BOOL    srv_fmgr_drv_is_accessible(U8 drv_letter);

/* <GROUP Storage service>
 * DESCRIPTION
 *  Check if a drive is in busy state. 
 *  It is a wrapper of FS_GetDevStatus(drv, FS_FEATURE_STATE_ENUM) == FS_DEVICE_BUSY 
 * PARAMETERS
 *  drv_letter              : [IN]  drive letter
 * RETURNS
 *  MMI_TRUE if busy, MMI_FALSE if not
 */
MMI_BOOL    srv_fmgr_drv_is_busy(U8 drv_letter);

/* <GROUP Storage service>
 * DESCRIPTION
 *  Check if a drive is supported. 
 *  For project that has memory card slot but card not inserted, card drive is valid
 *  but not accessible.
 * PARAMETERS
 *  drv_letter              : [IN]  drive letter
 * RETURNS
 *  MMI_TRUE if valid, MMI_FALSE if not
 */
MMI_BOOL    srv_fmgr_drv_is_valid(U8 drv_letter);

/* <GROUP Storage service>
 * DESCRIPTION
 *  Check if a drive is a removable device, including Memory card, OTG. 
 * PARAMETERS
 *  drv_letter              : [IN]  drive letter
 * RETURNS
 *  MMI_TRUE if it is removable, MMI_FALSE if it is not
 */
MMI_BOOL    srv_fmgr_drv_is_removable(U8 drv_letter);

/* <GROUP Storage service>
 * DESCRIPTION
 *  Check if there is any accessible removable drive, including Memory card, OTG. 
 * RETURNS
 *  MMI_TRUE if there is, MMI_FALSE if there is not
 */
MMI_BOOL    srv_fmgr_drv_has_accessible_removable_drv(void);

/* <GROUP Storage service>
 * DESCRIPTION
 *  Query drive letter by type
 * PARAMETERS
 *  type                    : [IN]  drive type
 * RETURNS
 *  drive letter
 */
U8          srv_fmgr_drv_get_letter_by_type(srv_fmgr_drv_type_enum type);

/* <GROUP Storage service>
 * DESCRIPTION
 *  Query drive path (ex. "D:\\") by type
 * PARAMETERS
 *  type                    : [IN]  drive type
 * RETURNS
 *  pointer to drive path
 */
const WCHAR* srv_fmgr_drv_get_path_by_type(srv_fmgr_drv_type_enum type);

/* List of Storage, dynamic service */

/* <GROUP Storage service macro>
 * Handle of drive list, by srv_fmgr_drivelist_create a drive list is created,
 * App can use drivelist related API to query detail info of each drive.
 * Useful when App need to display a list of drive
 * Note. Memory card rule specified that even memory card 
 * is removed, it should still be display for set storage.
 * Therefore, there is an option to list removed memory card.
 * It is caller's job to check if memory card is available
 * or not */
typedef U32 SRV_FMGR_DRVLIST_HANDLE;

/* <GROUP Storage service macro>
 * Type of drive list */
typedef enum
{
    SRV_FMGR_DRIVELIST_TYPE_ALL,        /* all supported drive (accessible or not) will be listed */
    SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE, /* only ready drive will be listed. 
                                         * Removed memory card "is" included */
    SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE_ONLY, /* only ready drive will be listed. 
                                         * Removed memory card "is not" included */

    /* DOM-NOT_FOR_SDK-BEGIN */
    SRV_FMGR_DRIVELIST_TYPE_TOTAL
    /* DOM-NOT_FOR_SDK-END */
} srv_fmgr_drivelist_type_enum;

/* <GROUP Storage service>
 * DESCRIPTION
 *  Create a drive list. The type can be all or only accessible.
 * PARAMETERS
 *  type                    : [IN]  all or only accessible, see srv_fmgr_drivelist_type_enum
 * RETURNS
 *  handle
 */
SRV_FMGR_DRVLIST_HANDLE srv_fmgr_drivelist_create(srv_fmgr_drivelist_type_enum type);

/* <GROUP Storage service>
 * DESCRIPTION
 *  Destroty a drive list.
 * PARAMETERS
 *  hdrvlist                : [IN]  handle to be free
 */
void        srv_fmgr_drivelist_destroy(SRV_FMGR_DRVLIST_HANDLE hdrvlist);

/* <GROUP Storage service>
 * DESCRIPTION
 *  Query drive count in a drive list
 * PARAMETERS
 *  hdrvlist                : [IN]  handle of drive list
 * RETURNS
 *  count of drive in list
 */
S32         srv_fmgr_drivelist_count(SRV_FMGR_DRVLIST_HANDLE hdrvlist);

/* <GROUP Storage service>
 * DESCRIPTION
 *  Query drive letter of N-th item in a drive list
 * PARAMETERS
 *  hdrvlist                : [IN]  handle of drive list
 *  index                   : [IN]  index of item to be queried
 * RETURNS
 *  drive letter, 0 if index out of range.
 */
U8          srv_fmgr_drivelist_get_drv_letter(SRV_FMGR_DRVLIST_HANDLE hdrvlist, S32 index);

/* <GROUP Storage service>
 * DESCRIPTION
 *  Query index of a drive letter from a drive list
 * PARAMETERS
 *  hdrvlist                : [IN]  handle of drive list
 *  drv_letter              : [IN]  drive letter to be queried
 * RETURNS
 *  index, -1 if not found in list
 */
S32         srv_fmgr_drivelist_get_index_by_drv_letter(SRV_FMGR_DRVLIST_HANDLE hdrvlist, U8 drv_letter);

/* <GROUP Storage service>
 * DESCRIPTION
 *  Query index of a drive type from a drive list
 * PARAMETERS
 *  hdrvlist                : [IN]  handle of drive list
 *  drv_type                : [IN]  drive type to be queried
 * RETURNS
 *  index, -1 if not found in list
 */
S32         srv_fmgr_drivelist_get_index_by_drv_type(SRV_FMGR_DRVLIST_HANDLE hdrvlist, srv_fmgr_drv_type_enum drv_type);

#define SRV_FMGR_PATH
/*****************************************************************************
 *                    Path related service 
 */

/* <GROUP Path service macro>
 * The maximum length of a file's fullname (Ex. "test.jpg"), NOT including null character */
#define SRV_FMGR_PATH_MAX_FILE_NAME_LEN   (255)

/* <GROUP Path service macro>
 * The maximum length of a file's extension (Ex. "jpg"), NOT including null character */
#define SRV_FMGR_PATH_MAX_FILE_EXT_LEN    (5)

/* <GROUP Path service macro>
 * The maximum length of a file's basename (Ex. "test"), NOT including null character */
#define SRV_FMGR_PATH_MAX_FILE_BASENAME_LEN (249)

/* <GROUP Path service macro>
 * The maximum length of a file's fullpath, NOT including null character */
#define SRV_FMGR_PATH_MAX_LEN            (259)

/* <GROUP Path service macro>
 * The maximum length of a file's fullpath in bytes, including null character */
#define SRV_FMGR_PATH_BUFFER_SIZE        (520)

/* <GROUP Path service macro>
 * Root of FMGR, contain all storages (Phone, Memory card, etc...) */
#define SRV_FMGR_PATH_ROOT               L"root"

/* File name, string manipulation, global service */

/* <GROUP Path service>
 * DESCRIPTION
 *  Get pointer of filename in the path
 *  see also srv_fmgr_path_get_filename_pos.
 *  Ex. "test.jpg" will be returned for "D:\\Photos\\test.jpg"
 * PARAMETERS
 *  path                    : [IN]  fullpath, Ex. "D:\\Photos\\test.jpg"
 * RETURNS
 *  pointer to filename, or NULL if there is no slash in the path.
 */
WCHAR*          srv_fmgr_path_get_filename_ptr(WCHAR* path);

/* <GROUP Path service>
 * DESCRIPTION
 *  Get pointer of filename in the path (const version)
 *  see also srv_fmgr_path_get_filename_pos.
 *  Ex. "test.jpg" will be returned for "D:\\Photos\\test.jpg"
 * PARAMETERS
 *  path                    : [IN]  fullpath, Ex. "D:\\Photos\\test.jpg"
 * RETURNS
 *  const pointer to filename, or NULL if there is no slash in the path.
 */
const WCHAR*    srv_fmgr_path_get_filename_const_ptr(const WCHAR* path);

/* <GROUP Path service>
 * DESCRIPTION
 *  Get index of filename in the path. The index is by characters. 
 *  Space characters will be skipped.
 *  Ex. "D:\\Photos\\test.jpg" -> 10
 *  Ex. "D:\\Photos\\ABC\\" -> 10
 *  Ex. "Photos\\ABC\\" -> 7
 *  Ex. "test.jpg" -> 0
 *  Ex. "  test.jpg" -> 2
 *  Ex. "" -> -1
 * PARAMETERS
 *  path                    : [IN]  fullpath, Ex. "D:\\Photos\\test.jpg"
 * RETURNS
 *  index of filename, or -1 if path is empty.
 */
S32             srv_fmgr_path_get_filename_pos(const WCHAR* path);

/* <GROUP Path service>
 * DESCRIPTION
 *  Get pointer of extension in the path
 *  see also srv_fmgr_path_get_extension_pos.
 *  Ex. "jpg" will be returned for "D:\\Photos\\test.jpg"
 * PARAMETERS
 *  path                    : [IN]  fullpath, Ex. "D:\\Photos\\test.jpg"
 * RETURNS
 *  pointer to extension, or NULL if there is no dot in the path.
 */
WCHAR*          srv_fmgr_path_get_extension_ptr(WCHAR* path);

/* <GROUP Path service>
 * DESCRIPTION
 *  Get pointer of extension in the path (const version)
 *  see also srv_fmgr_path_get_extension_pos.
 *  Ex. "jpg" will be returned for "D:\\Photos\\test.jpg"
 * PARAMETERS
 *  path                    : [IN]  fullpath, Ex. "D:\\Photos\\test.jpg"
 * RETURNS
 *  const pointer to extension, or NULL if there is no dot in the path.
 */
const WCHAR*    srv_fmgr_path_get_extension_const_ptr(const WCHAR* path);

/* <GROUP Path service>
 * DESCRIPTION
 *  Get index of extension in the path. The index is by characters.
 *  Ex. "D:\\Photos\\test.jpg"   -> 15
 *  Ex. "D:\\Photos\\test"       -> -1
 *  Ex. "D:\\Photos\\.jpg"       -> 11
 *  Ex. "D:\\Photos\\test.jpg\\" -> -1 (treat as folder)
 *  Ex. "" -> -1
 * PARAMETERS
 *  path                    : [IN]  fullpath, Ex. "D:\\Photos\\test.jpg"
 * RETURNS
 *  index of extension, or -1 if there is no dot in the path.
 */
S32             srv_fmgr_path_get_extension_pos(const WCHAR* path);

/* <GROUP Path service>
 * DESCRIPTION
 *  Check if a filename is valid. A filename is valid if:
 *  1. there is no invalid characters (/, \\, :, *, ?, ", <, >, |, \\n, \\r)
 *  2. not empty
 *  Note. This API will not check if file exists or not.
 * PARAMETERS
 *  filename                : [IN]  filename, Ex. "test.jpg"
 * RETURNS
 *  MMI_TRUE if the filename is valid, MMI_FALSE if not
 */
MMI_BOOL        srv_fmgr_path_is_filename_valid(const WCHAR* filename);

/* <GROUP Path service>
 * DESCRIPTION
 *  return a string contain invalid characters, including:
 *  /, \\, :, *, ?, ", <, >, |, \\n, \\r
 * RETURNS
 *  pointer to invalid characters
 */
const WCHAR*    srv_fmgr_path_get_invalid_chars(void);

/* <GROUP Path service>
 * DESCRIPTION
 *  Work exactly the same as mmi_wcsncat, except this API will add check for SRV_FMGR_PATH_BUFFER_SIZE.
 *  it will fail if the final result exceed dest_path_size or SRV_FMGR_PATH_BUFFER_SIZE.
 *  Note.if dest_path does not end with "\\", this API will insert it automatically.
 *  Ex. append("D:\\123",  "456") -> "D:\\123\\456"
 *  Ex. append("D:\\123\\", "456") -> "D:\\123\\456"
 * PARAMETERS
 *  dest_path               : [IN/OUT]  path to be appended
 *  dest_path_size          : [IN]  size of dest_path
 *  filename                : [IN]  filename that will append on dest_path
 * RETURNS
 *  MMI_TRUE if successfully append, MMI_FALSE if not
 */
MMI_BOOL        srv_fmgr_path_append(WCHAR* dest_path, S32 dest_path_size, const WCHAR* filename);

/* <GROUP Path service>
 * DESCRIPTION
 *  Work exactly the same as mmi_wcsncat, except this API will add check for SRV_FMGR_PATH_BUFFER_SIZE.
 *  it will fail if the final result exceed dest_path_size or SRV_FMGR_PATH_BUFFER_SIZE.
 *  Note.if dest_path does not end with "\\", this API will insert it automatically.
 *  Note.if filename already has tail "\\", it will not add slash even add_slash is MMI_TRUE.
 *  Ex. append("D:\\123",  "456", MMI_TRUE) -> "D:\\123\\456\\"
 *  Ex. append("D:\\123\\", "456", MMI_FALSE) -> "D:\123\456"
 *  Ex. append("D:\\123",  "456\\", MMI_TRUE) -> "D:\\123\\456\\"
 * PARAMETERS
 *  dest_path               : [IN/OUT]  path to be appended
 *  dest_path_size          : [IN]  size of dest_path
 *  filename                : [IN]  filename that will append on dest_path
 *  add_slash               : [IN]  if need to add a tail slash
 * RETURNS
 *  MMI_TRUE if successfully append, MMI_FALSE if not
 */
MMI_BOOL        srv_fmgr_path_append_ex(WCHAR* dest_path, S32 dest_path_size, const WCHAR* filename, MMI_BOOL add_slash);

/* <GROUP Path service>
 * DESCRIPTION
 *  Skip starting space characters, return the pointer to first non-space, include null character.
 *  Ex. "123" -> "123"
 *  Ex. "   123" -> "123"
 *  Ex. "   " -> ""
 * PARAMETERS
 *  path                    : [IN]  path
 * RETURNS
 *  pointer to first non-space character
 */
WCHAR*          srv_fmgr_path_skip_leading_space(WCHAR* path);

/* <GROUP Path service>
 * DESCRIPTION
 *  Skip starting space characters, return the pointer to first non-space, include null character.
 *  Ex. "123" -> "123"
 *  Ex. "   123" -> "123"
 *  Ex. "   " -> ""
 * PARAMETERS
 *  path                    : [IN]  path
 * RETURNS
 *  const pointer to first non-space character
 */
const WCHAR*    srv_fmgr_path_skip_leading_space_const(const WCHAR* path);

/* <GROUP Path service>
 * DESCRIPTION
 *  Remove filename from a path. 
 *  Ex. "D:\\Photos\\test.jpg\\" -> "D:\\Photos\\"
 *  Ex. "D:\\Photos\\test.jpg"   -> "D:\\Photos\\"
 *  Ex. "D:\\Photos\\"           -> "D:\\"
 *  Ex. "D:\\Photos"             -> "D:\\"
 * PARAMETERS
 *  path                    : [IN/OUT]  path
 * RETURNS
 *  pointer to path
 */
WCHAR*          srv_fmgr_path_remove_filename(WCHAR* path);

/* <GROUP Path service>
 * DESCRIPTION
 *  Remove tail slash (if there is) from a path. 
 *  Ex. "D:\\Photos\\test.jpg\\" -> "D:\\Photos\\test.jpg"
 *  Ex. "D:\\Photos\\test.jpg"   -> "D:\\Photos\\test.jpg"
 * PARAMETERS
 *  path                    : [IN/OUT]  path
 * RETURNS
 *  pointer to path
 */
WCHAR*          srv_fmgr_path_remove_slash(WCHAR* path);

/* <GROUP Path service>
 * DESCRIPTION
 *  For some project, extension should be hidden from UI display (User)
 *  This API will hide extension if necessary, So App has no need 
 *  to know too much detail.
 * PARAMETERS
 *  path                    : [IN/OUT]  path
 * RETURNS
 *  MMI_TRUE if path is modified, MMI_FALSE if not
 */
MMI_BOOL        srv_fmgr_path_hide_extension(WCHAR* path);

/* File system operation, global service */

/* <GROUP Path service>
 * DESCRIPTION
 *  check if the path exists
 * PARAMETERS
 *  path                    : [IN]  path
 * RETURNS
 *  0 if path exists, < 0 if there is FS error (see fs_errcode.h)
 */
S32             srv_fmgr_fs_path_exist(const WCHAR* path);

/* <GROUP Path service>
 * DESCRIPTION
 *  recursively create folder. A enhanced version of FS_CreateDir.
 * PARAMETERS
 *  path                    : [IN]  path
 * RETURNS
 *  0 if succeeded, < 0 if there is FS error (see fs_errcode.h)
 */
S32             srv_fmgr_fs_create_folder(const WCHAR* path);

/* <GROUP Path service>
 * DESCRIPTION
 *  check if given folder has any files that match given filter
 * PARAMETERS
 *  path                    : [IN]  folder path
 *  filter                  : [IN]  filter
 * RETURNS
 *  1 if there are matched files
 *  0 if there is no matched file
 *  < 0 if there is FS error (see fs_errcode.h)
 */
S32             srv_fmgr_fs_path_is_not_empty(const WCHAR* path, const FMGR_FILTER* filter);

/* Path nvram service, global service
 *  ? need app side's compile option, which is strange.
 *  ? implementation can be enhanced (NVRAM is powerful now)
S32         srv_fmgr_path_read_from_nvram(enum id, WCHAR* path, S32 path_size);
S32         srv_fmgr_path_write_to_nvram(enum id, const WCHAR* path);
*/

#define SRV_FMGR_FILEINFO
/*****************************************************************************
 *                    File information related service
 */

/* <GROUP Fileinfo service>
 * handle of file info object, see srv_fmgr_fileinfo_create for more detail */
typedef FS_HANDLE SRV_FMGR_FILEINFO_HANDLE;

/* <GROUP Fileinfo service>
 * detail infos of file info object, this structure contain type, attribute, size, 
 * datetime, also see srv_fmgr_fileinfo_get_info */
typedef struct
{
    U16     type;       /* type, see filetypes_file_type_enum */
    U16     attribute;  /* attribute, refer to FS_ATTR_XXX */
    U32     size;       /* size */
    MYTIME  datetime;   /* last modified date */
    MYTIME  created_datetime;   /* creation date */
} srv_fmgr_fileinfo_struct;

/* <GROUP Fileinfo service>
 * DESCRIPTION
 *  Create a handle of file info, it contains detail information of the given filepath.
 *  This API will keep the file opened (occupy a file handle in FS), please call
 *  srv_fmgr_fileinfo_destroy ASAP when it is not used.
 *  Note. you can use srv_fmgr_fs_path_get_display_name or srv_fmgr_fs_path_get_fileinfo
 *  for faster query, these API take a path and return result directly.
 * PARAMETERS
 *  path                    : [IN]  path of file/folder
 *  handle                  : [OUT] return the handle
 * RETURNS
 *  0 if handle successfully created
 *  < 0 if there is FS error (see fs_errcode.h)
 */
S32             srv_fmgr_fileinfo_create(const WCHAR* path, 
                                         SRV_FMGR_FILEINFO_HANDLE* handle);

/* <GROUP Fileinfo service>
 * DESCRIPTION
 *  Destroy a file info handle
 * PARAMETERS
 *  handle                  : [IN]  handle to be destroy.
 */
void            srv_fmgr_fileinfo_destroy(SRV_FMGR_FILEINFO_HANDLE handle);

/* <GROUP Fileinfo service>
 * DESCRIPTION
 *  Query filename of a file info handle.
 *  The maximum required length is SRV_FMGR_PATH_MAX_FILE_NAME_LEN.
 *  If buffer is NULL, required length will be returned.
 *  If buffer is not NULL and buffer_size is not enough, FS_STRING_BUFFER_TOO_SMALL
 *  will be returned.
 * PARAMETERS
 *  handle                  : [IN]  handle to query.
 *  buffer                  : [OUT] buffer to store filename, can be NULL to 
 *                                  query required length and prepare buffer
 *  buffer_size             : [IN]  size of buffer (in bytes, include null characters)
 * RETURNS
 *  1. > 0 if buffer is NULL, return required length
 *  2. 0   if buffer is enough, filename returned.
 *  3. < 0 if there is FS error.
 */
S32             srv_fmgr_fileinfo_get_name(SRV_FMGR_FILEINFO_HANDLE handle, WCHAR* buffer, S32 buffer_size);

/* <GROUP Fileinfo service>
 * DESCRIPTION
 *  Query file extension of a file info handle.
 *  The maximum required length is SRV_FMGR_PATH_MAX_FILE_EXT_LEN.
 *  If buffer is NULL, required length will be returned.
 *  If buffer is not NULL and buffer_size is not enough, FS_STRING_BUFFER_TOO_SMALL
 *  will be returned.
 * PARAMETERS
 *  handle                  : [IN]  handle to query.
 *  buffer                  : [OUT] buffer to store filename, can be NULL to 
 *                                  query required length and prepare buffer
 *  buffer_size             : [IN]  size of buffer (in bytes, include null characters)
 * RETURNS
 *  1. > 0 if buffer is NULL, return required length
 *  2. 0   if buffer is enough, filename returned.
 *  3. < 0 if there is FS error.
 */
S32             srv_fmgr_fileinfo_get_extension(SRV_FMGR_FILEINFO_HANDLE handle, WCHAR* buffer, S32 buffer_size);

/* <GROUP Fileinfo service>
 * DESCRIPTION
 *  Query detail info (stored in a struct) of a file info handle.
 *  Detail info includes: type, size, datetime, attribute
 * PARAMETERS
 *  handle                  : [IN]  handle to query.
 *  fileinfo                : [OUT] buffer to store detail info
 */
void            srv_fmgr_fileinfo_get_info(SRV_FMGR_FILEINFO_HANDLE handle, srv_fmgr_fileinfo_struct* fileinfo);

/* <GROUP Fileinfo service>
 * DESCRIPTION
 *  Query file type of a file info handle.
 * PARAMETERS
 *  handle                  : [IN]  handle to query.
 * RETURNS
 *  see filetypes_file_type_enum
 */
filetypes_file_type_enum srv_fmgr_fileinfo_get_type(SRV_FMGR_FILEINFO_HANDLE handle);

/* <GROUP Fileinfo service>
 * DESCRIPTION
 *  Query file size of a file info handle.
 *  For folder, this API will return 0.
 * PARAMETERS
 *  handle                  : [IN]  handle to query.
 * RETURNS
 *  size of file, 0 if the file is a folder.
 */
U32             srv_fmgr_fileinfo_get_size(SRV_FMGR_FILEINFO_HANDLE handle);

/* <GROUP Fileinfo service>
 * DESCRIPTION
 *  Query creation datetime of a file.
 * PARAMETERS
 *  handle                  : [IN]  handle to query.
 *  datetime                : [OUT] creation time of file
 */
void            srv_fmgr_fileinfo_get_datetime(SRV_FMGR_FILEINFO_HANDLE handle, MYTIME* datetime);

/* <GROUP Fileinfo service>
 * DESCRIPTION
 *  Query file attribute of a file. see FS_ATTR_DIR, FS_ATTR_HIDDEN, etc... in FS_type.h
 * PARAMETERS
 *  handle                  : [IN]  handle to query.
 * RETURNS
 *  file attribute
 */
U32             srv_fmgr_fileinfo_get_attribute(SRV_FMGR_FILEINFO_HANDLE handle);

/* <GROUP Fileinfo service>
 * DESCRIPTION
 *  Query if the file handle is a file or a folder
 * PARAMETERS
 *  handle                  : [IN]  handle to query.
 * RETURNS
 *  MMI_TRUE if it is a folder, MMI_FALSE if not
 */
MMI_BOOL        srv_fmgr_fileinfo_is_folder(SRV_FMGR_FILEINFO_HANDLE handle);

/* <GROUP Fileinfo service>
 * DESCRIPTION
 *  Query if the file handle is a archive
 * PARAMETERS
 *  handle                  : [IN]  handle to query.
 * RETURNS
 *  MMI_TRUE if it is in a archive, MMI_FALSE if not
 */
MMI_BOOL        srv_fmgr_fileinfo_is_in_archive(SRV_FMGR_FILEINFO_HANDLE handle);

/* <GROUP Fileinfo service>
 * DESCRIPTION
 *  Like srv_fmgr_fileinfo_get_name, this API also return filename.
 *  But if the buffer is not enough, "..." will be filled at tail.
 * PARAMETERS
 *  handle                  : [IN]  handle to query.
 *  buffer                  : [OUT] buffer to store the displayable string
 *                                  "..." will be used if size is not enough
 *  buffer_size             : [IN]  size of buffer.
 * RETURNS
 *  1. > 0 if buffer is NULL, return required length
 *  2. = 0 if buffer is filled with filename.
 *  3. < 0 if there is FS error. (see fs_errcode.h)
 */
S32             srv_fmgr_fileinfo_get_display_name(SRV_FMGR_FILEINFO_HANDLE handle, WCHAR* buffer, S32 buffer_size);

/* <GROUP Path service>
 * DESCRIPTION
 *  Query display name directly from a path.
 *  If the path does not exist, it will fail.
 *  This is a wrapper of srv_fmgr_fileinfo_get_display_name
 *  Note. if the buffer is not big enough, "..." will be filled
 * PARAMETERS
 *  path                    : [IN]  path
 *  buffer                  : [OUT] buffer to store the displayable string
 *                                  "..." will be used if size is not enough
 *  buffer_size             : [IN]  size of string buffer (in bytes)
 * RETURNS
 *  > 0, if buffer is NULL, return required length
 *  = 0, succeed, buffer is filled with filename.
 *  < 0, if there is FS error (see fs_errcode.h)
 */
S32             srv_fmgr_fs_path_get_display_name(const WCHAR* path, WCHAR* buffer, S32 buffer_size);

/* <GROUP Path service>
 * DESCRIPTION
 *  Query detail file info directly from a path.
 *  If the path does not exist, it will fail.
 *  This is a wrapper of srv_fmgr_fileinfo_get_info
 * PARAMETERS
 *  path                    : [IN]  path
 *  fileinfo                : [OUT] buffer to store detail info
 * RETURNS
 *  = 0, succeed
 *  < 0, if there is FS error (see fs_errcode.h)
 */
S32             srv_fmgr_fs_path_get_fileinfo(const WCHAR* path, srv_fmgr_fileinfo_struct* fileinfo);

#define SRV_FMGR_ASYNC_FS
/*****************************************************************************
 *                    Async FS operation service
 *  Function
 *      Copy / Move
 *      Delete
 *      Format
 *      Check drive?
 *
 *  Requirement
 *      1. Allow multi request at the same time.
 *      2. Has priority (FG / BG)
 *      3. Can be aborted
 */

/* <GROUP AsyncFS service macro>
 * flags of async operation, these flags can be ORed to indicate multiple setting */
typedef enum
{
    SRV_FMGR_ASYNC_FLAG_PRIORITY_BG   = 0x00, /* background, As long as it will be 
                                               * handled, time spent doesnt matter */
    SRV_FMGR_ASYNC_FLAG_PRIORITY_FG   = 0x01, /* foreground, it means MMI will display 
                                               * UI (ex. please wait) to user, and user
                                               * expect operation should end in a 
                                               * reasonable time */

    SRV_FMGR_ASYNC_FLAG_NO_PROGRESS   = 0x00, /* There is no progress indication during
                                               * operation. That is, there will be only 
                                               * EVT_ID_SRV_FMGR_ASYNC_DONE event */
    SRV_FMGR_ASYNC_FLAG_NEED_PROGRESS = 0x02, /* There will be progress indication during
                                               * operation. That is, there will be 
                                               * EVT_ID_SRV_FMGR_ASYNC_PROGRESSING before 
                                               * DONE event */

    /* DOM-NOT_FOR_SDK-BEGIN */
    SRV_FMGR_ASYNC_FLAG_END
    /* DOM-NOT_FOR_SDK-END */
} srv_fmgr_async_flag_enum;

/* <GROUP AsyncFS service macro>
 * state of an async job, see also srv_fmgr_async_get_state */
typedef enum
{
    SRV_FMGR_ASYNC_STATE_INVALID,       /* job id is invalid (not in use) */
    SRV_FMGR_ASYNC_STATE_DONE,          /* job is completed, "done" event already sent to callback */
    SRV_FMGR_ASYNC_STATE_IN_PROGRESS,   /* job is in progressing state */
    SRV_FMGR_ASYNC_STATE_ABORTING,      /* job is in aborting state */

    /* DOM-NOT_FOR_SDK-BEGIN */
    SRV_FMGR_ASYNC_STATE_TOTAL
    /* DOM-NOT_FOR_SDK-END */
} srv_fmgr_async_state_enum;

/* <GROUP AsyncFS service event>
 * events that will be sent to user_proc of srv_fmgr_async_copy, 
 * srv_fmgr_async_move, srv_fmgr_async_delete, 
 * srv_fmgr_async_delete_all APIs */
typedef enum
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_SRV_FMGR_ASYNC_BASE = SRV_FILEMANAGER,
    /* DOM-NOT_FOR_SDK-END */

    EVT_ID_SRV_FMGR_ASYNC_PROGRESSING,  /* if SRV_FMGR_ASYNC_FLAG_NEED_PROGRESS is set, this
                                         * event will be sent to user_proc to let caller update
                                         * status (ex. percentage).
                                         * struct = srv_fmgr_async_progress_event_struct */
    EVT_ID_SRV_FMGR_ASYNC_ABORTING,     /* When job state change to ABORTING, user_proc will 
                                         * receive this event.
                                         * struct = srv_fmgr_async_abort_event_struct */
    EVT_ID_SRV_FMGR_ASYNC_DONE,         /* When job is done (succeeded or not), user proce will
                                         * receive this event.
                                         * with struct = srv_fmgr_async_done_event_struct */


    EVT_ID_SRV_FMGR_ASYNC_FOLDER_SIZE_PROGRESSING,  /* if SRV_FMGR_ASYNC_FLAG_NEED_PROGRESS is set, this
                                                     * event will be sent to user_proc to let caller update
                                                     * status (ex. percentage).
                                                     * struct = srv_fmgr_async_progress_event_struct */
    EVT_ID_SRV_FMGR_ASYNC_FOLDER_SIZE_RESULT,       /* When job is done (succeeded or not), user proc will
                                                     * receive this event.
                                                     * with struct = srv_fmgr_async_done_event_struct */

    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_SRV_FMGR_ASYNC_END
    /* DOM-NOT_FOR_SDK-END */
} srv_fmgr_async_event_enum;

/* <GROUP AsyncFS service macro>
 * struct of event EVT_ID_SRV_FMGR_ASYNC_PROGRESSING */
typedef struct 
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */

    S32 job_id;                 /* id of async job */

    U32 total_file_count;       /* total file count */
    U32 completed_file_count;   /* completed file count */
    U32 total_length;           /* total size of current file */
    U32 completed_length;       /* completed size of current file */
    const WCHAR* filename;      /* name of current file */

} srv_fmgr_async_progress_event_struct;

/* <GROUP AsyncFS service macro>
 * struct of event EVT_ID_SRV_FMGR_ASYNC_ABORTING and EVT_ID_SRV_FMGR_ASYNC_DONE */
typedef struct 
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */

    S32 job_id;                 /* id of async job */

    S32 result;                 /* result of job, 
                                 * for ABORTING this is always 0,
                                 * for DONE event, 0 means success, < 0 means error */
        
} srv_fmgr_async_abort_event_struct, srv_fmgr_async_done_event_struct;

/* <GROUP AsyncFS service macro>
 * struct of event EVT_ID_SRV_FMGR_ASYNC_FOLDER_SIZE_PROGRESSING */
typedef struct 
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */

    S32 job_id;                 /* id of async job */

    U64 folder_size;                   /* current size */
        
} srv_fmgr_async_folder_size_progress_event_struct;

/* <GROUP AsyncFS service macro>
 * struct of event EVT_ID_SRV_FMGR_ASYNC_FOLDER_SIZE_RESULT */
typedef struct 
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */

    S32 job_id;                 /* id of async job */

    S32 result;
    U64 folder_size;                   /* folder size, 0 if result < 0 */  
        
} srv_fmgr_async_folder_size_result_event_struct;

/* <GROUP AsyncFS service>
 * DESCRIPTION
 *  Copy a single file or folder to another location
 *  Wrapper of FS_Move(..., FS_MOVE_COPY, ...) in another task, with notification adv_action
 * PARAMETERS
 *  src_path                : [IN]  file/folder to be copied
 *  dest_path               : [IN]  destination folder
 *  flag                    : [IN]  setting of this operation, see srv_fmgr_async_flag_enum
 *  user_proc               : [IN]  proc handler to receive event, 
 *                                  see srv_fmgr_async_event_enum.
 *  user_data               : [IN]  user_data of event that sent to user_proc
 * RETURNS
 *  > 0, async job is successfully created. the value is job id.
 *  < 0 if FS error (see fs_errcode.h)
 */
S32         srv_fmgr_async_copy(const WCHAR* src_path, const WCHAR* dest_path, S32 flag, 
                                mmi_proc_func user_proc, void* user_data);
/* <GROUP AsyncFS service>
 * DESCRIPTION
 *  Move a single file or folder to another location
 *  Wrapper of FS_Move(..., FS_MOVE_KILL, ...) in another task, with notification adv_action
 * PARAMETERS
 *  src_path                : [IN]  file/folder to be moved
 *  dest_path               : [IN]  destination folder
 *  flag                    : [IN]  setting of this operation, see srv_fmgr_async_flag_enum
 *  user_proc               : [IN]  proc handler to receive event, 
 *                                  see srv_fmgr_async_event_enum.
 *  user_data               : [IN]  user_data of event that sent to user_proc
 * RETURNS
 *  > 0, async job is successfully created. the value is job id.
 *  < 0 if FS error (see fs_errcode.h)
 */
S32         srv_fmgr_async_move(const WCHAR* src_path, const WCHAR* dest_path, S32 flag, 
                                mmi_proc_func user_proc, void* user_data);

/* <GROUP AsyncFS service>
 * DESCRIPTION
 *  Delete a single file or folder.
 *  Wrapper of FS_Delete(...) or FS_XDelete(...) in another task, with notification adv_action
 * PARAMETERS
 *  src_path                : [IN]  file/folder to be deleted
 *  flag                    : [IN]  setting of this operation, see srv_fmgr_async_flag_enum
 *  user_proc               : [IN]  proc handler to receive event, 
 *                                  see srv_fmgr_async_event_enum.
 *  user_data               : [IN]  user_data of event that sent to user_proc
 * RETURNS
 *  > 0, async job is successfully created. the value is job id.
 *  < 0 if FS error (see fs_errcode.h)
 */
S32         srv_fmgr_async_delete(const WCHAR* src_path, S32 flag, 
                                mmi_proc_func user_proc, void* user_data);

/* <GROUP AsyncFS service>
 * DESCRIPTION
 *  Delete matched files in a folder.
 *  Wrapper of FS_XDelete(..., FS_FILE_TYPE, ...) in another task, with notification adv_action
 * PARAMETERS
 *  src_path                : [IN]  folder of deleting files
 *  filter                  : [IN]  only files that matched this filter will be deleted
 *  flag                    : [IN]  setting of this operation, see srv_fmgr_async_flag_enum
 *  user_proc               : [IN]  proc handler to receive event, 
 *                                  see srv_fmgr_async_event_enum.
 *  user_data               : [IN]  user_data of event that sent to user_proc
 * RETURNS
 *  > 0, async job is successfully created. the value is job id.
 *  < 0 if FS error (see fs_errcode.h)
 */
S32         srv_fmgr_async_delete_all(const WCHAR* src_path, const FMGR_FILTER *filter, S32 flag, 
                                mmi_proc_func user_proc, void* user_data);

/* <GROUP AsyncFS service>
 * DESCRIPTION
 *  Create a path, it will recursively create each level folder if not exist.
 * PARAMETERS
 *  folder_path             : [IN]  folder to be create
 *  flag                    : [IN]  setting of this operation, see srv_fmgr_async_flag_enum
 *  user_proc               : [IN]  proc handler to receive event, 
 *                                  see srv_fmgr_async_event_enum.
 *  user_data               : [IN]  user_data of event that sent to user_proc
 * RETURNS
 *  > 0, async job is successfully created. the value is job id.
 *  < 0 if FS error (see fs_errcode.h)
 */
S32 srv_fmgr_async_create_folder(const WCHAR* folder_path, S32 flag, 
                                   mmi_proc_func user_proc, void* user_data);

/* <GROUP AsyncFS service>
 * DESCRIPTION
 *  Calculate size of a folder recursively
 * PARAMETERS
 *  folder_path             : [IN]  folder to be calculated
 *  flag                    : [IN]  setting of this operation, see srv_fmgr_async_flag_enum
 *  user_proc               : [IN]  proc handler to receive event, 
 *                                  see srv_fmgr_async_event_enum.
 *  user_data               : [IN]  user_data of event that sent to user_proc
 * RETURNS
 *  > 0, async job is successfully created. the value is job id.
 *  < 0 if FS error (see fs_errcode.h)
 */
S32 srv_fmgr_async_get_folder_size(const WCHAR* folder_path, S32 flag, 
                                   mmi_proc_func user_proc, void* user_data);

/* <GROUP AsyncFS service>
 * DESCRIPTION
 *  Abort the job. 
 *  If succeed, the job will first enter aborting state and be aborted later, user_proc
 *  will first receive ABORTING, then DONE event (result = FS_ABORTED_ERROR). If 
 *  cancel_event is MMI_TRUE, user_proc will not receive any events even succeed.
 *  If failed, it will act like never called.
 * PARAMETERS
 *  job_id                  : [IN]  id of async job
 *  cancel_event            : [IN]  if MMI_TRUE, all following events are cancelled,
 *                                  there will be no ABORTING / DONE event.
 * RETURNS
 *  MMI_TRUE if the job enter aborting state
 *  MMI_FALSE if the job is not in progressing state or cannot be aborted.
 */
MMI_BOOL    srv_fmgr_async_abort(S32 job_id, MMI_BOOL cancel_event); 

/* <GROUP AsyncFS service>
 * DESCRIPTION
 *  Query state of an async job. When a job is created via srv_fmgr_async_copy
 *  ..., it will enter progressing state. If srv_fmgr_async_abort is called, 
 *  it will enter aborting state. And finally it will switch to done state when
 *  operation complete. After user_proc handle DONE event, the state become 
 *  invalid.
 * PARAMETERS
 *  job_id                  : [IN]  id of async job
 * RETURNS
 *  see srv_fmgr_async_state_enum.
 */
srv_fmgr_async_state_enum srv_fmgr_async_get_state(S32 job_id); 

/* <GROUP AsyncFS service>
 * DESCRIPTION
 *  Query if there is any ongoing async job
 * RETURNS
 *  MMI_TRUE if there is async job ongoing,
 *  MMI_FALSE if not
 */
MMI_BOOL srv_fmgr_async_is_busy(void); 

#define SRV_FMGR_FILELIST

#define SRV_FILELIST    (SRV_FILEMANAGER + 50)

/* <GROUP Filelist interface macro>
 * filelist handle */
typedef U32 SRV_FMGR_FILELIST_HANDLE;

/* <GROUP Filelist interface macro>
 * capability of filelist handle */
typedef enum
{
    SRV_FMGR_FILELIST_CAP_RANDOM_ACCESS  = 0x00, /* All files in the list are ready, file in list can 
                                                  * be accessed randomly. query file by index API such
                                                  * as srv_fmgr_filelist_get_file_path will always work 
                                                  */
    SRV_FMGR_FILELIST_CAP_LOAD_ON_DEMAND = 0x01, /* Not all files are ready, file in list may require 
                                                  * async loading. query file by index API may fail and 
                                                  * return SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY error. 
                                                  * srv_fmgr_filelist_load_file is then used to "load" it
                                                  */

    /* DOM-NOT_FOR_SDK-BEGIN */
    SRV_FMGR_FILELIST_CAP_END
    /* DOM-NOT_FOR_SDK-END */
} srv_fmgr_filelist_capability_enum;

/* <GROUP Filelist interface macro>
 * error that filelist handle may return, 
 * for error not listed here, see also FS error (in fs_errcode.h) */
typedef enum
{
    /* Start from last fs error code to provide unique */
    SRV_FMGR_FILELIST_ERROR_BASE = FS_MINIMUM_ERROR_CODE,
    
    SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY,  /* file is not ready,
                                              * srv_fmgr_filelist_get_filepath, srv_fmgr_filelist_get_filename
                                              * and srv_fmgr_filelist_get_fileinfo may return this error to 
                                              * indicate requested file is not ready, user should call 
                                              * srv_fmgr_filelist_load_file to prepare the data */

    SRV_FMGR_FILELIST_ERROR_FILE_READY,      /* file is already ready,
                                              * srv_fmgr_filelist_load_file may return this error to indicate
                                              * requested file is ready, loading is not required */

    SRV_FMGR_FILELIST_ERROR_BUSY,            /* list are busy handling another async operation, including
                                              * srv_fmgr_filelist_refresh, srv_fmgr_filelist_load_file */

    /* DOM-NOT_FOR_SDK-BEGIN */
    SRV_FMGR_FILELIST_ERROR_END
    /* DOM-NOT_FOR_SDK-END */
} srv_fmgr_filelist_error_enum;

/* <GROUP Filelist interface macro>
 * flags of filelist handle */
typedef enum
{
    SRV_FMGR_FILELIST_REFRESH_PROGRESS_OFF = 0x00,  /* no progress event during refresh*/
    SRV_FMGR_FILELIST_REFRESH_PROGRESS_ON  = 0x01,  /* has progress event during refresh*/

    /* DOM-NOT_FOR_SDK-BEGIN */
    SRV_FMGR_FILELIST_REFRESH_FLAG_TOTAL
    /* DOM-NOT_FOR_SDK-END */
} srv_fmgr_filelist_refresh_flag_enum;

/* <GROUP Filelist interface macro>
 * struct of event EVT_ID_SRV_FMGR_FILELIST_REFRESH_RESULT */
typedef struct {
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */

    SRV_FMGR_FILELIST_HANDLE handle;
    
    S32 result;         /* 0 if ok, < 0 if FS error (see fs_errcode.h) */
    S32 total_count;    /* total file count */
    S32 search_index;   /* index of searched file, -1 if not found */

    S32 number_of_folder;   /* number of folder */
    
} srv_fmgr_filelist_refresh_result_event_struct;

/* <GROUP Filelist interface macro>
 * struct of event EVT_ID_SRV_FMGR_FILELIST_REFRESH_PROGRESS */
typedef struct {
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */

    SRV_FMGR_FILELIST_HANDLE handle;
   
    S32 total_count;    /* total file count */
    S32 completed_count;/* completed file count */
    
} srv_fmgr_filelist_refresh_progress_event_struct;

/* <GROUP Filelist interface macro>
 * struct of event EVT_ID_SRV_FMGR_FILELIST_LOAD_RESULT 
 * files with index from start to (end-1) become ready.
 */
typedef struct {
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */

    SRV_FMGR_FILELIST_HANDLE handle;

    S32 result;             /* 0 if ok, < 0 if FS error (see fs_errcode.h) */
    S32 ready_index_start;  /* start index of file range that become ready, use
                             * srv_fmgr_filelist_get_file_path to query detail */
    S32 ready_index_end;    /* end index (not included) of file range that become 
                             * ready, use srv_fmgr_filelist_get_file_path to query 
                             * detail */
    
} srv_fmgr_filelist_load_result_event_struct;

/* <GROUP Filelist interface event>
 * events of filelist handle may send */
typedef enum
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_SRV_FMGR_FILELIST_BASE = SRV_FILELIST,
    /* DOM-NOT_FOR_SDK-END */
    
    EVT_ID_SRV_FMGR_FILELIST_REFRESH_RESULT,    /* result event of srv_fmgr_filelist_refresh,
                                                 * see also srv_fmgr_filelist_refresh_result_event_struct */
    EVT_ID_SRV_FMGR_FILELIST_REFRESH_PROGRESS,  /* progress event of srv_fmgr_filelist_refresh,
                                                 * see also srv_fmgr_filelist_refresh_progress_event_struct */
    EVT_ID_SRV_FMGR_FILELIST_LOAD_RESULT,       /* result of srv_fmgr_filelist_load_file,
                                                 * see also srv_fmgr_filelist_load_result_event_struct */

    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_SRV_FMGR_FILELIST_END
    /* DOM-NOT_FOR_SDK-END */
} srv_fmgr_filelist_event_enum;

/* <GROUP Filelist interface macro>
 * state of filelist handle */
typedef enum
{
    SRV_FMGR_FILELIST_STATE_INIT,           /* Initial state, use srv_fmgr_filelist_refresh to make list
                                             * ready */
    SRV_FMGR_FILELIST_STATE_READY,          /* Ready for operation. Note. a list can be ready and dirty
                                             * at the same time */
    SRV_FMGR_FILELIST_STATE_REFRESHING,     /* Busy on srv_fmgr_filelist_refresh */
    SRV_FMGR_FILELIST_STATE_LOADING,        /* Busy on srv_fmgr_filelist_load_file */

    /* DOM-NOT_FOR_SDK-BEGIN */
    SRV_FMGR_FILELIST_STATE_TOTAL
    /* DOM-NOT_FOR_SDK-END */
} srv_fmgr_filelist_state_enum;

/* <GROUP Filelist interface>
 * DESCRIPTION
 *  destroy and free this list
 * PARAMETERS
 *  hdl             : [IN]  list
 */
void srv_fmgr_filelist_destroy(SRV_FMGR_FILELIST_HANDLE hdl);

/* <GROUP Filelist interface>
 * DESCRIPTION
 *  return the state of this list
 * PARAMETERS
 *  hdl             : [IN]  list
 * RETURNS
 *  state, see srv_fmgr_filelist_state_enum.
 */
srv_fmgr_filelist_state_enum srv_fmgr_filelist_get_state(SRV_FMGR_FILELIST_HANDLE hdl);

/* <GROUP Filelist interface>
 * DESCRIPTION
 *  return the capability of this list
 * PARAMETERS
 *  hdl             : [IN]  list
 * RETURNS
 *  capability, see srv_fmgr_filelist_capability_enum.
 */
S32 srv_fmgr_filelist_get_capability(SRV_FMGR_FILELIST_HANDLE hdl);

/* <GROUP Filelist interface>
 * DESCRIPTION
 *  return the total file count of this list. If the list is not ready, it will return 0.
 * PARAMETERS
 *  hdl             : [IN]  list
 * RETURNS
 *  total file count or 0 if list is not ready.
 */
U32 srv_fmgr_filelist_count(SRV_FMGR_FILELIST_HANDLE hdl);

/* <GROUP Filelist interface>
 * DESCRIPTION
 *  check if the list is empty. If the list is not ready, MMI_TRUE is returned.
 * PARAMETERS
 *  hdl             : [IN]  list
 * RETURNS
 *  MMI_TRUE if list is empty or not ready
 *  MMI_FALSE if not.
 */
MMI_BOOL srv_fmgr_filelist_is_empty(SRV_FMGR_FILELIST_HANDLE hdl);

/* <GROUP Filelist interface>
 * DESCRIPTION
 *  check if the list is dirty and require refresh.
 * PARAMETERS
 *  hdl             : [IN]  list
 * RETURNS
 *  MMI_TRUE if list content is dirty
 *  MMI_FALSE if not.
 */
MMI_BOOL srv_fmgr_filelist_is_dirty(SRV_FMGR_FILELIST_HANDLE hdl);

/* <GROUP Filelist interface>
 * DESCRIPTION
 *  Query fullpath of a file
 *  Note. For list with cap = SRV_FMGR_FILELIST_CAP_LOAD_ON_DEMAND, this API 
 *        may return SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY
 *  Note. Maximum path length is SRV_FMGR_PATH_MAX_LEN.
 *  Note. If file's path is too long, FS_PATH_OVER_LEN_ERROR is returned.
 * PARAMETERS
 *  hdl             : [IN]  list
 *  index           : [IN]  index of item to be queried
 *  buffer          : [OUT] buffer to store filepath, can be NULL to 
 *                          query filepath length and prepare buffer
 *  buffer_size     : [IN]  size of buffer (in bytes, include null characters)
 * RETURNS
 *  if buffer is NULL, this API return length of filepath (in characters)
 *  if not, this API return:
 *  1. 0 if succeed
 *  2. < 0 if fail, see srv_fmgr_filelist_error_enum and FS error
 */
S32 srv_fmgr_filelist_get_filepath(SRV_FMGR_FILELIST_HANDLE hdl, S32 index, WCHAR* buffer, S32 buffer_size);

/* <GROUP Filelist interface>
 * DESCRIPTION
 *  Query filename of a file. If a file's path is too long, 
 *  srv_fmgr_filelist_get_file_path will fail, but srv_fmgr_filelist_get_file_name
 *  will still succeed.
 *  Note. For such kind of file. It should be listed but not able to do any operation
 *  Note. For list with cap = SRV_FMGR_FILELIST_CAP_LOAD_ON_DEMAND, this API 
 *  may return SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY
 *  Note. Maximum path length is SRV_FMGR_PATH_MAX_FILE_NAME_LEN
 * PARAMETERS
 *  hdl             : [IN]  list
 *  index           : [IN]  index of item to be queried
 *  buffer          : [OUT] buffer to store filename, can be NULL to 
 *                          query required length and prepare buffer
 *  buffer_size     : [IN]  size of buffer (in bytes, include null characters)
 * RETURNS
 *  if buffer is NULL, this API return length required (in characters)
 *  if not, this API return:
 *  1. 0 if succeed
 *  2. < 0 if fail, see srv_fmgr_filelist_error_enum and FS error
 */
S32 srv_fmgr_filelist_get_filename(SRV_FMGR_FILELIST_HANDLE hdl, S32 index, WCHAR* buffer, S32 buffer_size);

/* <GROUP Filelist interface>
 * DESCRIPTION
 *  Query info of a file. 
 *  Note. For list with cap = SRV_FMGR_FILELIST_CAP_LOAD_ON_DEMAND, this API 
 *  may return SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY
 * PARAMETERS
 *  hdl             : [IN]  list
 *  index           : [IN]  index of item to be queried
 *  fileinfo        : [OUT] buffer to store file info
 * RETURNS
 *  0 if succeed
 *  < 0 if fail, see srv_fmgr_filelist_error_enum and FS error
 */
S32 srv_fmgr_filelist_get_fileinfo(SRV_FMGR_FILELIST_HANDLE hdl, S32 index, srv_fmgr_fileinfo_struct* fileinfo);

/* <GROUP Filelist interface>
 * DESCRIPTION
 *  If the capability of list is SRV_FMGR_FILELIST_CAP_LOAD_ON_DEMAND. 
 *  srv_fmgr_filelist_get_file may return SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY
 *  error. This API is used load content of N-th item. 
 *  The result will be sent back later through user_proc.
 *  Note. SRV_FMGR_FILELIST_ERROR_FILE_READY is returned if the file is 
 *  already ready.
 * PARAMETERS
 *  hdl             : [IN]  list
 *  index           : [IN]  index of item to be queried
 *  user_proc       : [IN]  proc handler to receive event, 
 *                          see EVT_ID_SRV_FMGR_FILELIST_LOAD_RESULT.
 *  user_data       : [IN]  user_data of event that sent to user_proc
 * RETURNS
 *  0 if successfuly submit load request, result will be back through user_proc.
 *  < 0 if fail, see srv_fmgr_filelist_error_enum
 */
S32 srv_fmgr_filelist_load_file(SRV_FMGR_FILELIST_HANDLE hdl, S32 index,
                             mmi_proc_func user_proc, void* user_data);

/* <GROUP Filelist interface>
 * DESCRIPTION
 *  This API is used to refresh content of dirty list.
 * PARAMETERS
 *  hdl             : [IN]  list
 *  pattern         : [IN]  pointer to pattern to search, 
 *                          NULL if no need to search
 *  start_index     : [IN]  search starting index, not use if pattern is NULL. 
 *  flag            : [IN]  option flag, see srv_fmgr_filelist_refresh_flag_enum.
 *  user_proc       : [IN]  proc handler to receive refresh result event, 
 *                          see EVT_ID_SRV_FMGR_FILELIST_REFRESH_RESULT.
 *  user_data       : [IN]  user_data of event that sent to user_proc
 * RETURNS
 *  0 if succeed
 *  < 0 if fail, see srv_fmgr_filelist_error_enum
 */
S32 srv_fmgr_filelist_refresh(SRV_FMGR_FILELIST_HANDLE hdl, const WCHAR* pattern, S32 start_index, 
                              S32 flag, mmi_proc_func user_proc, void* user_data);

/* <GROUP Filelist interface>
 * DESCRIPTION
 *  Abort(cancel) the refreshing / loading
 *  Fail if filelist is not in refresh / load state.
 * PARAMETERS
 *  hdl             : [IN]  list
 * RETURNS
 *  0 if succeed aborted
 *  < 0 if fail, see srv_fmgr_filelist_error_enum and FS error
 */
S32 srv_fmgr_filelist_abort(SRV_FMGR_FILELIST_HANDLE hdl);


/* <GROUP Filelist interface>
 * DESCRIPTION
 *  Query filter & sort setting of a list.
 * PARAMETERS
 *  hdl             : [IN]  list
 *  filter          : [OUT] current type filter
 *  sort_option     : [OUT] current sort option
 */
void srv_fmgr_filelist_get_setting(SRV_FMGR_FILELIST_HANDLE hdl, FMGR_FILTER* filter, U32* sort_option);

/* <GROUP Filelist interface>
 * DESCRIPTION
 *  Update filter & sort setting of a list.
 *  List will become dirty after this API is called.
 * PARAMETERS
 *  hdl             : [IN]  list
 *  filter          : [IN]  new filter
 *  sort_option     : [IN]  new sort option
 */
void srv_fmgr_filelist_set_setting(SRV_FMGR_FILELIST_HANDLE hdl, const FMGR_FILTER* filter, U32 sort_option);

/* <GROUP Filelist interface macro>
 * Base class of filelist interface, filelist provider should put this struct as
 * first member of own structure. 
 */
typedef struct 
{
    const struct filelist_if_struct_* fl_if;    /* virtual function table */

} srv_fmgr_filelist_base_struct;

/* <GROUP Filelist interface macro>
 * filelist interface, filelist provider should implmenet all below functions */
typedef struct filelist_if_struct_
{
    /* release virtual function, see srv_fmgr_filelist_destroy */
    void        (*release)      (srv_fmgr_filelist_base_struct* self);
    /* state virtual function, see srv_fmgr_filelist_state */
    srv_fmgr_filelist_state_enum (*get_state)(srv_fmgr_filelist_base_struct* self);
    /* capability virtual function, see srv_fmgr_filelist_capability */
    S32         (*get_capability)(srv_fmgr_filelist_base_struct* self);
    /* count virtual function, see srv_fmgr_filelist_count */
    U32         (*count)        (srv_fmgr_filelist_base_struct* self);
    /* empty virtual function, see srv_fmgr_filelist_empty */
    MMI_BOOL    (*is_empty)     (srv_fmgr_filelist_base_struct* self);
    /* dirty virtual function, see srv_fmgr_filelist_dirty */
    MMI_BOOL    (*is_dirty)     (srv_fmgr_filelist_base_struct* self);
    /* get file path virtual function, see srv_fmgr_filelist_get_file_path */
    S32         (*get_filepath) (srv_fmgr_filelist_base_struct* self, S32 index, WCHAR* buffer, S32 buffer_size);
    /* get file name virtual function, see srv_fmgr_filelist_get_file_name */
    S32         (*get_filename) (srv_fmgr_filelist_base_struct* self, S32 index, WCHAR* buffer, S32 buffer_size);
    /* get file info virtual function, see srv_fmgr_filelist_get_file_info */
    S32         (*get_fileinfo) (srv_fmgr_filelist_base_struct* self, S32 index, srv_fmgr_fileinfo_struct* fileinfo);
    /* load_file virtual function, see srv_fmgr_filelist_load_file */
    S32         (*load_file)    (srv_fmgr_filelist_base_struct* self, S32 index,
                                 mmi_proc_func user_proc, void* user_data);
    /* refresh virtual function, see srv_fmgr_filelist_refresh */
    S32         (*refresh)      (srv_fmgr_filelist_base_struct* self, const WCHAR* pattern, S32 start_index, 
                                 S32 flag, mmi_proc_func user_proc, void* user_data);
    /* abort virtual function, see srv_fmgr_filelist_abort */
    S32         (*abort)        (srv_fmgr_filelist_base_struct* self);
    /* get setting virtual function, see srv_fmgr_filelist_get_setting */
    void        (*get_setting)  (srv_fmgr_filelist_base_struct* self, FMGR_FILTER* filter, U32* sort_option);
    /* set setting virtual function, see srv_fmgr_filelist_set_setting */
    void        (*set_setting)  (srv_fmgr_filelist_base_struct* self, const FMGR_FILTER* filter, U32 sort_option);
    
} srv_fmgr_filelist_interface_struct;

#if defined(__FS_SORT_SUPPORT__)
/* <GROUP Filelist service>
 * Memory size required for folder filelist, N is the max file number allowed */
#ifdef __FMGR_SRV_WORK_BUF_FROM_ASM__
#define SRV_FMGR_FOLDER_FILELIST_MEM_SIZE_FOR(_N)   (FS_SORT_SORTING_BUFFER_SIZE_FOR_FILES(_N) + 1024 + (FS_SORT_WORKING_BUFFER_SIZE_FOR_FILES(_N)))
#else
#define SRV_FMGR_FOLDER_FILELIST_MEM_SIZE_FOR(_N)   (FS_SORT_SORTING_BUFFER_SIZE_FOR_FILES(_N) + 1024)
#endif
#else
/* <GROUP Filelist service>
 * Memory size required for folder filelist, N is the max file number allowed */
#define SRV_FMGR_FOLDER_FILELIST_MEM_SIZE_FOR(_N)   (1024 + 1024)
#endif
/* <GROUP Filelist service>
 * Memory size for folder filelist, N = FS_SORT_MAX_ENTRY, see SRV_FMGR_FOLDER_FILELIST_MEM_SIZE_FOR */
#define SRV_FMGR_FOLDER_FILELIST_MEM_SIZE   SRV_FMGR_FOLDER_FILELIST_MEM_SIZE_FOR(FS_SORT_MAX_ENTRY)

/* <GROUP Filelist service>
 * DESCRIPTION
 *  Create a filelist handle containing matched files in a single folder.
 *  Note. if the 2 memory funcptr are NULL, service internal buffer is used 
 *  and the creation may fail due to out of memory.
 * PARAMETERS
 *  folderpath              : [IN]  folder of interested
 *  filter                  : [IN]  filter of interested types
 *  sort                    : [IN]  sort flag, see srv_fmgr_sort_get
 *  buffer                  : [IN]  buffer
 *  buffer_size             : [IN]  buffer_size, use SRV_FMGR_FOLDER_FILELIST_MEM_SIZE_FOR
 *                                  or SRV_FMGR_FOLDER_FILELIST_MEM_SIZE to calculate 
 *                                  necessary size.
 *  list_handle             : [OUT] return the list handle
 * RETURNS
 *  0 if succeed, < 0 if if there is error,see srv_fmgr_error_enum
 */
S32 srv_fmgr_folder_filelist_create(const WCHAR* folderpath, const FMGR_FILTER* filter, U32 sort, 
                                    void* buffer, S32 buffer_size, 
                                    SRV_FMGR_FILELIST_HANDLE* list_handle);

/* <GROUP Filelist service>
 * DESCRIPTION
 *  Create a empty list, it is handy if you dont want to do empty check 
 *  (ex. if(handle==NULL)) all the time.
 * PARAMETERS
 *  list_handle             : [OUT] return the list handle
 * RETURNS
 *  0, this API will not failed.
 */
S32 srv_fmgr_empty_filelist_create(SRV_FMGR_FILELIST_HANDLE* list_handle);

#define SRV_FMGR_NOTIFICATION
/*****************************************************************************
 *                     Notification
 */

/* <GROUP Notification service macro>
 * State of notification event. Receiver may receive the same notification event 
 * with different state. For example, when user try to format memory card,
 * format notification with "query" state is broadcasted to all receiver to make 
 * sure all receiver accept the formation, if anyone disagree, the formation is fail.
 * If all receiver agree, format with "before" state is broadcasted so that receiver
 * can reset status. Memory card is then formatted. After formation (success or not),
 * format with "after" state is broadcasted. */
typedef enum 
{
    SRV_FMGR_NOTIFICATION_STATE_QUERY,  /* Query state, all receiver have chance to stop 
                                         * what going to happen (format, delete, etc) by 
                                         * returning MMI_RET_ERR */
    SRV_FMGR_NOTIFICATION_STATE_BEFORE, /* Before state, after the query succeed, receiver
                                         * can do some pre-processing */
    SRV_FMGR_NOTIFICATION_STATE_AFTER,  /* After state, after operation is done, receiver
                                         * can do some post-processing */

    /* DOM-NOT_FOR_SDK-BEGIN */
    SRV_FMGR_NOTIFICATION_STATE_END
    /* DOM-NOT_FOR_SDK-END */    
} srv_fmgr_notification_state_enum;

/* <GROUP Notification service macro>
 * EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION contains Copy, Move, Rename, Delete, Delete all.
 * This enum is used to indicate the real action */
typedef enum 
{
    SRV_FMGR_NOTIFICATION_ACTION_COPY,  /* Copy a single file or folder 
                                         * src:  a file or folder 
                                         * dest: a folder
                                         * Ex. Copy("D:\\A\\C.jpg", "D:\\B\\") = "D:\\B\\C.jpg" */
    SRV_FMGR_NOTIFICATION_ACTION_MOVE,  /* Move a single file or folder
                                         * src:  a file or folder 
                                         * dest: a folder
                                         * Ex. Move("D:\\A\\C.jpg", "D:\\B\\") = "D:\\B\\C.jpg" */
    SRV_FMGR_NOTIFICATION_ACTION_RENAME,/* Rename a single file or folder 
                                         * src:  a file or folder
                                         * dest: a file or folder
                                         * Ex. Move("D:\\A\\C.jpg", "D:\\A\\D.jpg") = "D:\\A\\D.jpg" */
    SRV_FMGR_NOTIFICATION_ACTION_DELETE,/* Delete a single file or folder 
                                         * src:  a file or folder */
    SRV_FMGR_NOTIFICATION_ACTION_DELETE_ALL, /* Delete all files in a folder 
                                         * src:  a folder
                                         * filter: only matched files will be deleted */
    SRV_FMGR_NOTIFICATION_ACTION_CREATE_FOLDER, /* A folder is being created 
                                         * src:  a folder */

    /* DOM-NOT_FOR_SDK-BEGIN */
    SRV_FMGR_NOTIFICATION_ACTION_END
    /* DOM-NOT_FOR_SDK-END */
} srv_fmgr_notification_action_enum;

/* <GROUP Notification service macro>
 * event structure of EVT_ID_SRV_FMGR_NOTIFICATION_DEV_READY */
typedef struct {
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */   
} srv_fmgr_notification_dev_ready_event_struct;


/* <GROUP Notification service macro>
 * event structure of EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN and 
 * EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT */
typedef struct {
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */

    U8 count;                                           /* count of drive */
    U8 drv_letters[FMT_MAX_DRIVE];                      /* table of drive */
    
} srv_fmgr_notification_dev_plug_event_struct;

/* <GROUP Notification service macro>
 * event structure of EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT */
typedef struct {
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */

    U8 drv_letter;                                      /* drive lettter */
    MMI_BOOL mount;                                     /* mount or unmount */
    
} srv_fmgr_notification_dev_soft_mount_event_struct;

/* <GROUP Notification service macro>
 * event structure of EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT */
typedef struct {
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */

    srv_fmgr_notification_state_enum    state;          /* query, before, after */
    U8                                  drv_letter;     /* drive to be formatted */
    S32                                 result;         /* format result */
    
} srv_fmgr_notification_format_event_struct;

/* <GROUP Notification service macro>
 * event structure of EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE */
typedef struct {
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */

    srv_fmgr_notification_state_enum    state;          /* Query, After */
    U8                                  drv_letter;     /* drive of default storage */
    
} srv_fmgr_notification_set_def_storage_event_struct;

/* <GROUP Notification service macro>
 * event structure of EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION */
typedef struct {
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */

    srv_fmgr_notification_state_enum    state;          /* query, before, after */
    srv_fmgr_notification_action_enum   action;         /* copy, move, rename, delete */

    const WCHAR*                        src_filepath;   /* fullpath of source */
    srv_fmgr_fileinfo_struct            src_fileinfo;
    const WCHAR*                        dest_filepath;  /* fullpath of destination */
    srv_fmgr_fileinfo_struct            dest_fileinfo;
    const FMGR_FILTER*                  filter;
    S32                                 result;         /* action result, valid when state = AFTER */
    
} srv_fmgr_notification_adv_action_event_struct;

/* <GROUP Notification service event>
 * Event of FMGR notification.
 * For static registration, please refer to mmi_cb_mgr_cfg.h.
 * For dynamic registration, please refer to mmi_frm_cb_reg_event / mmi_frm_cb_dereg_event.
 * To broadcast the notification, please use srv_fmgr_fs_copy, srv_fmgr_fs_move, etc... API. */
typedef enum
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_SRV_FMGR_NOTIFICATION_BASE = EVT_ID_SRV_FMGR_ASYNC_END,
    /* DOM-NOT_FOR_SDK-END */
    
    EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN,     /* When removable devices are plugged in, 
                                                     see also srv_fmgr_notification_dev_plug_event_struct */
    EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT,    /* When removeable devices are plugged out,
                                                     see also srv_fmgr_notification_dev_plug_event_struct */

    EVT_ID_SRV_FMGR_NOTIFICATION_DEV_READY,       /* When all devices are ready after bootup,
                                                     see also srv_fmgr_notification_dev_ready_event_struct*/

    EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT,  /* When a removable device is removed, 
                                                     see also srv_fmgr_notification_dev_soft_mount_event_struct */
    
    EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT,          /* When a storage is being formatted and after formatted,
                                                     see also srv_fmgr_notification_format_event_struct */
    
    EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE, /* When set default storage,
                                                     see also srv_fmgr_notification_set_def_storage_event_struct */

    EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION,      /* When advanced action happen, including copy, move, rename, delete,
                                                     see also srv_fmgr_notification_adv_action_event_struct */


    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_SRV_FMGR_NOTIFICATION_END
    /* DOM-NOT_FOR_SDK-END */
} srv_fmgr_notification_event_enum;

/* <GROUP Notification service>
 * DESCRIPTION
 *  Copy a single file or folder to another location.
 *  Wrapper of FS_Move(..., FS_MOVE_COPY, ...), with notification adv_action
 *  If the destination end with "\\", it will be treated as folder, see below example
 *  Ex. copy("D:\\Photos\\test.jpg", "D:\\Images\\") --> "D:\\Images\\test.jpg
 *  Ex. copy("D:\\Photos\\test.jpg", "D:\\Images\\b.jpg") --> "D:\\Images\\b.jpb
 *  Note. This is a blocking API that may take a long time depend on file size.
 * PARAMETERS
 *  src_path                : [IN]  file/folder to be copied
 *  dest_path               : [IN]  destination folder or filepath
 * RETURNS
 *  0 if succeed, < 0 if FS error (see fs_errcode.h)
 */
S32 srv_fmgr_fs_copy(const WCHAR* src_path, const WCHAR* dest_path);

/* <GROUP Notification service>
 * DESCRIPTION
 *  Move a single file or folder to another location.
 *  Wrapper of FS_Move(..., FS_MOVE_KILL, ...), with notification adv_action
 *  If the destination end with "\\", it will be treated as folder, see below example
 *  Ex. move("D:\\Photos\\test.jpg", "D:\\Images\\") --> "D:\\Images\\test.jpg
 *  Ex. move("D:\\Photos\\test.jpg", "D:\\Images\\b.jpg") --> "D:\\Images\\b.jpb
 *  Note. This is a blocking API that may take a long time depend on file size.
 * PARAMETERS
 *  src_path                : [IN]  file/folder to be moved
 *  dest_path               : [IN]  destination folder
 * RETURNS
 *  0 if succeed, < 0 if FS error (see fs_errcode.h)
 */
S32 srv_fmgr_fs_move(const WCHAR* src_path, const WCHAR* dest_path);

/* <GROUP Notification service>
 * DESCRIPTION
 *  Rename a single file or folder
 *  Wrapper of FS_Rename(...), with notification adv_action
 * PARAMETERS
 *  src_path                : [IN]  file/folder to be renamed
 *  dest_path               : [IN]  new name
 * RETURNS
 *  0 if succeed, < 0 if FS error (see fs_errcode.h)
 */
S32 srv_fmgr_fs_rename(const WCHAR* src_path, const WCHAR* dest_path);

/* <GROUP Notification service>
 * DESCRIPTION
 *  Delete a single file or folder.
 *  Wrapper of FS_Delete(...) or FS_XDelete(...), with notification adv_action
 *  Note. This is a blocking API that may take a long time depend on file size.
 * PARAMETERS
 *  path                    : [IN]  file/folder to be deleted
 * RETURNS
 *  0 if succeed, < 0 if FS error (see fs_errcode.h)
 */
S32 srv_fmgr_fs_delete(const WCHAR* path);

/* <GROUP Notification service>
 * DESCRIPTION
 *  Delete matched files in a folder.
 *  Wrapper of FS_XDelete(..., FS_FILE_TYPE, ...), with notification adv_action
 *  Note. This is a blocking API that may take a long time depend on file size.
 *  Note. This API cannot delete sub-folder in the folder.
 * PARAMETERS
 *  folderpath              : [IN]  folder of deleting files
 *  filter                  : [IN]  only files that matched this filter will be deleted
 *                                  if NULL, means all files will be deleted
 * RETURNS
 *  0 if succeed, < 0 if FS error (see fs_errcode.h)
 */
S32 srv_fmgr_fs_delete_all(const WCHAR* folderpath, const FMGR_FILTER* filter);

#define SRV_FMGR_TYPES
/*****************************************************************************
 *                     Types
 */

/* <GROUP Types service macro>
 * Icons of a file type, used at different place */
typedef enum
{
    SRV_FMGR_TYPES_ICON_SMALL,   /* Small icon */
    SRV_FMGR_TYPES_ICON_LARGE,   /* Large icon */

    /* DOM-NOT_FOR_SDK-BEGIN */
    SRV_FMGR_TYPES_ICON_TOTAL
    /* DOM-NOT_FOR_SDK-END */
} srv_fmgr_types_icon_enum;

/* <GROUP Types service macro>
 * Option bit flag, let user to query interesting options */
typedef enum
{
    SRV_FMGR_TYPES_OPTIONS_FLAG_APP_DEF     = 0x0001,   /* default cmd. Ex. View/Play/Install */
    SRV_FMGR_TYPES_OPTIONS_FLAG_APP_OTHER   = 0x0002,   /* other app cmd. Such as Print/Edit 
                                                         * for Image */
    SRV_FMGR_TYPES_OPTIONS_FLAG_USE         = 0x0004,   /* Use sub-option */
    SRV_FMGR_TYPES_OPTIONS_FLAG_SEND        = 0x0008,   /* Send sub-option */
    SRV_FMGR_TYPES_OPTIONS_FLAG_OTHER       = 0x0010,   /* Other general option. Like Delete /
                                                         * Rename */
    SRV_FMGR_TYPES_OPTIONS_FLAG_ENV         = 0x8000,   /* environmental option. Like Delete 
                                                         * All / Sort by */

    SRV_FMGR_TYPES_OPTIONS_FLAG_ALL         = 0x00FF    /* not include env option */
} srv_fmgr_types_options_flag_enum;

/* <GROUP Types service>
 * DESCRIPTION
 *  Find type by a filename string.
 *  This API only check the extension, it will not check the file content.
 * PARAMETERS
 *  filename_str            : [IN]  filename string, Ex. "test.jpg"
 * RETURNS
 *  see filetypes_file_type_enum, FMGR_TYPE_UNKNOWN if not found.
 */
filetypes_file_type_enum  srv_fmgr_types_find_type_by_filename_str(const WCHAR* filename_str);

/* <GROUP Types service>
 * DESCRIPTION
 *  Find type by a extension string.
 *  This API only check the extension, it will not check the content.
 * PARAMETERS
 *  extension_str           : [IN]  extension string, Ex. "jpg"
 * RETURNS
 *  see filetypes_file_type_enum, FMGR_TYPE_UNKNOWN if not found.
 */
filetypes_file_type_enum  srv_fmgr_types_find_type_by_extension_str(const WCHAR* extension_str);

/* <GROUP Types service>
 * DESCRIPTION
 *  Find type by a filepath.
 *  This API will first check the filename. For "ODF" (DRM 2.0 single part), it will 
 *  open and check its real type. If DRM 2.0 is not enabled, this API acts exactly 
 *  the same as srv_fmgr_types_find_type_by_filename_str
 * PARAMETERS
 *  filepath                : [IN]  fullpath, Ex. "D:\\A\\B.jpg"
 * RETURNS
 *  if >= 0, see filetypes_file_type_enum, if < 0, means FS error (see fs_errcode.h)
 */
S32                     srv_fmgr_types_find_type_by_filepath(const WCHAR* filepath);

/* <GROUP Types service>
 * DESCRIPTION
 *  Find group by a file type.
 * PARAMETERS
 *  type                    : [IN]  file type
 * RETURNS
 *  see filetypes_group_type_enum
 */
filetypes_group_type_enum srv_fmgr_types_find_group_by_type(filetypes_file_type_enum type);

/* <GROUP Types service>
 * DESCRIPTION
 *  Find group by a filename string. This API is a wrapper of  
 *  srv_fmgr_types_find_type_by_filename_str then srv_fmgr_types_find_group_by_type
 * PARAMETERS
 *  filename_str            : [IN]  filename string, Ex. "test.jpg"
 * RETURNS
 *  see filetypes_group_type_enum
 */
filetypes_group_type_enum srv_fmgr_types_find_group_by_filename_str(const WCHAR* filename_str);

/* <GROUP Types service>
 * DESCRIPTION
 *  A FMGR_FILTER is set of file types, this API find a major one from a filter
 * PARAMETERS
 *  filter                  : [IN]  set of file types
 * RETURNS
 *  see filetypes_file_type_enum
 */
filetypes_file_type_enum  srv_fmgr_types_get_main_type(const FMGR_FILTER *filter);

/*  query detail information of a file or a type.
 */

/* <GROUP Types service>
 * DESCRIPTION
 *  query extension string of a file type
 * PARAMETERS
 *  type                    : [IN]  file type
 * RETURNS
 *  pointer to extension (ascii)
 */
const CHAR*     srv_fmgr_types_get_extension(filetypes_file_type_enum type);

/* <GROUP Types service>
 * DESCRIPTION
 *  query extension string of a file type
 * PARAMETERS
 *  type                    : [IN]  file type
 * RETURNS
 *  pointer to extension (ucs2)
 */
const WCHAR*    srv_fmgr_types_get_extension_ucs2(filetypes_file_type_enum type);

/* <GROUP Types service>
 * DESCRIPTION
 *  query icon of a file type
 *  If type is not 0, query icon of this "type".
 *  If path is not NULL, query icon of this "file".
 *  If both type / path are given, path is used.
 * PARAMETERS
 *  type                    : [IN]  file type
 *  path                    : [IN]  icon of some file may be dynamic and require path 
 *  icon_type               : [IN]  type of icon, see srv_fmgr_types_icon_enum
 * RETURNS
 *  resource id of icon
 */
mmi_img_id  srv_fmgr_types_get_icon(filetypes_file_type_enum type, const WCHAR* path, srv_fmgr_types_icon_enum icon_type);

/* <GROUP Types service>
 * DESCRIPTION
 *  query option of a file type or a real file.
 *  If type is not 0, query option of this type and all option is available
 *  If path is not NULL, query option of this file, some option may be disabled 
 *  depend on file attribue. Ex. DRM protected file may not have send/use option.
 *  If both type / path are given, path is used.
 * PARAMETERS
 *  type                    : [IN]  file type
 *  path                    : [IN]  file path
 *  option_flag             : [IN]  user can query only interesting part of option,
 *                                  see srv_fmgr_types_options_flag_enum
 * RETURNS
 *  if > 0, it is a option menu id
 *  if = 0, means there is no available option
 *  if < 0, means FS error (see fs_errcode.h)
 */
S32         srv_fmgr_types_get_option_menu(filetypes_file_type_enum type, const WCHAR* path, S32 option_flag);

/* <GROUP Types service>
 * DESCRIPTION
 *  query "send" option of a file type or a real file.
 *  If type is not 0, query option of this type and all option is available
 *  If path is not NULL, query option of this file, some option may be disabled 
 *  depend on file attribue. 
 *  If both type / path are given, path is used.
 * PARAMETERS
 *  type                    : [IN]  file type
 *  path                    : [IN]  file path
 * RETURNS
 *  if > 0, it is a option menu id
 *  if = 0, means there is no available option
 *  if < 0, means FS error (see fs_errcode.h)
 */
S32         srv_fmgr_types_get_send_option_menu(filetypes_file_type_enum type, const WCHAR* path);

/* <GROUP Types service>
 * DESCRIPTION
 *  query "use as" option of a file type or a real file.
 *  If type is not 0, query option of this type and all option is available
 *  If path is not NULL, query option of this file, some option may be disabled 
 *  depend on file attribue. 
 *  If both type / path are given, path is used.
 * PARAMETERS
 *  type                    : [IN]  file type
 *  path                    : [IN]  file path
 * RETURNS
 *  if > 0, it is a option menu id
 *  if = 0, means there is no available option
 *  if < 0, means FS error (see fs_errcode.h)
 */
S32         srv_fmgr_types_get_use_option_menu(filetypes_file_type_enum type, const WCHAR* path);

/* <GROUP Types service>
 * DESCRIPTION
 *  launch given option's handler and use path as parameter.
 *  This API is normally used when user selects any option item.
 * PARAMETERS
 *  path                    : [IN]  file path
 *  option                  : [IN]  menu id of option item
 * RETURNS
 *  if > 0, means handler is successfully triggered.
 *  if = 0, means there is no handler for this option, and the API do nothing
 *  if < 0, means FS error (see fs_errcode.h)
 */
S32         srv_fmgr_types_launch_option(const WCHAR* path, mmi_menu_id option);

/* <GROUP Types service>
 * DESCRIPTION
 *  Set a group of type into filter
 *  Ex. FMGR_TYPE_GRP_AUDIO, then all audio types are set.
 * PARAMETERS
 *  filter                  : [OUT] filter, remember to do FMGR_FILTER_INIT before first use
 *  group                   : [IN]  file group, refer to filetypes_group_type_enum
 */
void        srv_fmgr_types_filter_set_group(FMGR_FILTER *filter, filetypes_group_type_enum group);

/* <GROUP Types service>
 * DESCRIPTION
 *  check if filter has any type match the group
 * PARAMETERS
 *  filter                  : [IN] filter to check
 *  group                   : [IN] file group, refer to filetypes_group_type_enum
 * RETURNS
 *  MMI_TRUE if has any match
 */
MMI_BOOL    srv_fmgr_types_filter_is_in_group(const FMGR_FILTER *filter, filetypes_group_type_enum group);

/* <GROUP Types service>
 * DESCRIPTION
 *  Due to our Framework limitation, application's menu handler can not retrieve 
 *  information of current file. For example, highlight an image file, option -> 
 *  View. How do "View" handler know which file to display?
 *  This API is to help application handler to get this infomation
 *  Information of current file will be setuped before menu handler is called
 *  and be cleared after the handler return.
 *  Call this API can obtain information of current file.
 *  At other scenario, this API return NULL
 * PARAMETERS
 *  info                    : [OUT] info of current file, can be NULL
 * RETURNS
 *  const WCHAR*, fullpath of current file
 */
const WCHAR* srv_fmgr_types_query_fileinfo(srv_fmgr_fileinfo_struct* info);

#define SRV_FMGR_CUSTICON

/* <GROUP Custicon service>
 * Customized icon support, operation type. Only valid when __MMI_FMGR_CUSTICON_SUPPORT__ is on */
typedef enum
{
    SRV_FMGR_CUSTICON_OP_REGISTER,     /* Register a icon to a object(file), this icon will be used when FMGR later
                                        * need to display this file */
    SRV_FMGR_CUSTICON_OP_MOVE_OBJECT,  /* Move a registered object, update object path in icon database. */
    SRV_FMGR_CUSTICON_OP_DEREGISTER,   /* De-register a object from data base */

    SRV_FMGR_CUSTICON_OP_TOTAL
} srv_fmgr_custicon_op_enum;

/* <GROUP Custicon service>
 * Result code for customized icon support. Only valid when __MMI_FMGR_CUSTICON_SUPPORT__ is on */
typedef enum
{
    SRV_FMGR_CUSTICON_RESULT_OK = 0,             /* No error */
    SRV_FMGR_CUSTICON_RESULT_INVALID_PARAM,      /* Invalid parameter */
    SRV_FMGR_CUSTICON_RESULT_OP_NOT_SUPPORTED,   /* Operation not support */
    SRV_FMGR_CUSTICON_RESULT_TYPE_NOT_SUPPORTED, /* Icon type is not support */
    SRV_FMGR_CUSTICON_RESULT_NO_ICON,            /* No customized icon for this file (not found in database) */
    SRV_FMGR_CUSTICON_RESULT_BUFFER_NOT_ENOUGH,  /* Buffer not enought */
    SRV_FMGR_CUSTICON_RESULT_CORRUPT_DB,         /* database is corrupted */

    SRV_FMGR_CUSTICON_RESULT_MAX
} srv_fmgr_custicon_result_enum;

/* <GROUP Custicon service>
 * DESCRIPTION
 *  customized icon entry API, depend on op, caller can do query / add / delete
 * PARAMETERS
 *  op                      : [IN]  operator type, refer to srv_fmgr_custicon_op_enum
 *  object_path             : [IN]  object filepath
 *  para                    : [IN]  icon filepath
 * RETURN VALUES
 *  < 0 : FS error
 *  = 0 : No error
 *  > 0 : result, refer to srv_fmgr_custicon_result_enum
 */
extern S32 srv_fmgr_custicon_do(srv_fmgr_custicon_op_enum op, const WCHAR* object_path, const WCHAR* para);

/* <GROUP Custicon service>
 * DESCRIPTION
 *  Check if customized icon database support a filetype
 * PARAMETERS
 *  type                    : [IN] file type
 * RETURNS
 *  MMI_BOOL: TRUE if support, FALSE if not
 */
extern MMI_BOOL srv_fmgr_custicon_is_type_support(filetypes_file_type_enum type);

/* <GROUP Custicon service>
 * DESCRIPTION
 *  Check if a file has cutomized icon
 * PARAMETERS
 *  object_path             : [IN]  object name
 *  icon_path               : [OUT] icon path buffer
 *  icon_path_size          : [IN]  length of buffer (in bytes), 
 *                                  should be SRV_FMGR_PATH_BUFFER_SIZE
 * RETURN VALUES
 *  < 0 : FS error
 *  0   : No error
 *  > 0 : result, refer to srv_fmgr_custicon_result_enum
 */
extern S32 srv_fmgr_custicon_query(const WCHAR* object_path, WCHAR* icon_path, S32 icon_path_size);

/* DOM-NOT_FOR_SDK-BEGIN */
extern mmi_ret srv_fmgr_ms_handler(mmi_event_struct *evt);
/* DOM-NOT_FOR_SDK-END */

#ifdef __cplusplus 
}
#endif

#endif /* SRV_FMGR_GPROT_H */
