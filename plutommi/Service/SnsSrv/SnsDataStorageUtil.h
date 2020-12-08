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
 *  SnsDataStorageTask.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  utility functions for sns data storage service
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __SRV_SNS_DS_UTIL_H__
#define __SRV_SNS_DS_UTIL_H__

#include "math.h" 

#define SNS_DS_FILE_OPEN_NEW                0x0001
#define SNS_DS_FILE_OPEN_NEW_CONTINUE       0x0002
#define SNS_DS_FILE_OPEN_UPDATE             0x0004
#define SNS_DS_FILE_OPEN_READ_ONLY          0x0008

#define SNS_DS_FILE_BACKUP_FRIENDS          0x0001
#define SNS_DS_FILE_BACKUP_GROUPS           0x0002
#define SNS_DS_FILE_BACKUP_MEMBERS          0x0004
#define SNS_DS_FILE_BACKUP_CONTACK_LINKS    0x0008

#ifdef __MMI_SNS_CALENDAR__
#define SNS_DS_FILE_BACKUP_EVENTS           0x0010
#define SNS_DS_FILE_BACKUP_BIRTHDAY         0x0020
#define SNS_DS_FILE_BACKUP_BIRTHDAY_ALARM   0x0040
#endif

#define MAX_CONTACT_ID                  (2000)

#define INDEX_BUFFER_COUNT              (30)
#define CACHE_BLOCK_NUM                 (15)
#define CACHE_DETAIL_NUM                (30)

#define LINK_HEADER_SIZE                (2 * sizeof(U32) + MAX_CONTACT_ID * sizeof(U32))  // |total linked| max_index, first_empty| friends linked in contacts |
#define GENERAL_FILE_HEADER_SIZE        (10 * 1024)
#define FRIEND_FILE_HEADER_SIZE         (261124)
#define GENERAL_DETAIL_SIZE             (80)
#define FRIEND_DETAIL_SIZE              (512)
#define GENERAL_BLOCK_SIZE              (2048)
#define ACTIVITY_BLOCK_SIZE             (3072)

#define FRIEND_BLOCK_INDEX(n)           ((n)%1000)
#define FRIEND_DETAIL_INDEX(n)          ((n)/1000)
#define FRIEND_COMPOSED_INDEX(m, n)     ((m) * 1000 + n)

#define RC4_KEY "snsencryptionkeyfacebookaaaaaaaa"

/*****************************************************************************
 * FUNCTION
 *  snst_util_ceil
 * DESCRIPTION
 *  get an integer that is no less than m / n
 * PARAMETERS
 *  m      [IN]    
 *  n      [IN]    
 * RETURNS
 *  ceil(m/n)
 *****************************************************************************/
U32 snst_util_ceil(U32 m, U32 n);

/*****************************************************************************
 * FUNCTION
 *  snst_util_is_file_encrypted
 * DESCRIPTION
 *  utility function for checking if a file is encrypted
 * PARAMETERS
 *  provider      [IN]    provider
 * RETURNS
 *  MMI_TRUE if the file is encrypted
 *****************************************************************************/
MMI_BOOL snst_util_is_file_encrypted(U32 provider);

/*****************************************************************************
 * FUNCTION
 *  snst_util_flag_to_enum
 * DESCRIPTION
 *  utility function for transfer flag to enum value
 * PARAMETERS
 *  flag    [IN]    flag
 * RETURNS
 *  number value
 *****************************************************************************/
U32 snst_util_flag_to_enum(U32 flag);

/*****************************************************************************
 * FUNCTION
 *  snst_util_enum_to_flag
 * DESCRIPTION
 *  utility function for transfer number to flag value
 * PARAMETERS
 *  number    [IN]    number
 * RETURNS
 *  flag value
 *****************************************************************************/
U32 snst_util_enum_to_flag(U32 flag);

// folder operations
/*****************************************************************************
 * FUNCTION
 *  snst_util_delete_folder
 * DESCRIPTION
 *  utility function for deleting folder
 * PARAMETERS
 *  *dir_name        [IN]    folder name
 *  remove_folder    [IN]    remove the folder or not
 *  recursive        [IN]    recursivly delete children folder   
 * RETURNS
 *  return error code
 *****************************************************************************/
S32 snst_util_delete_folder(WCHAR *dir_name, MMI_BOOL remove_folder, MMI_BOOL recursive);

/*****************************************************************************
 * FUNCTION
 *  snst_util_delete_temp_friend_file
 * DESCRIPTION
 *  utility function for deleting temp friend file
 * PARAMETERS
 *  provider    [IN]    provider
 * RETURNS
 *  void
 *****************************************************************************/
void snst_util_delete_temp_friend_file(U32 provider);

/*****************************************************************************
 * FUNCTION
 *  snst_util_delete_table_files
 * DESCRIPTION
 *  utility function for deleting table related files
 * PARAMETERS
 *  table [IN]    table
 * RETURNS
 *  return error code
 *****************************************************************************/
S32 snst_util_delete_table_files(WCHAR *table);

/*****************************************************************************
 * FUNCTION
 *  snst_util_delete_provider_files
 * DESCRIPTION
 *  utility function for deleting provider related files
 * PARAMETERS
 *  provider [IN]    provider
 * RETURNS
 *  return error code
 *****************************************************************************/
S32 snst_util_delete_provider_files(U32 provider);

/*****************************************************************************
 * FUNCTION
 *  snst_util_backup_files
 * DESCRIPTION
 *  utility function for backup files
 * PARAMETERS
 *  failed          [IN]    failed or not 
 *  providers       [IN]    providers involved
 *  group           [IN]    groups involved
 *  flag            [IN]    the kind of files involved
 * RETURNS
 *  void
 *****************************************************************************/
void snst_util_backup_files(MMI_BOOL rollback, U32 providers[SRV_SNS_MAX_NUM_PROVIDERS], U32 groups, U32 flag);

/*****************************************************************************
 * FUNCTION
 *  snst_util_file_update_finished
 * DESCRIPTION
 *  utility function for indicating update process is finished
 * PARAMETERS
 *  *tab          [IN]    file prefix
 *  index         [IN]    provider or group index
 *  *id           [IN]    id of a thread
 *  failed        [IN]    is failed or not
 * RETURNS
 *  void
 *****************************************************************************/
void snst_util_file_update_finished(const WCHAR *tab, U32 index, CHAR* id, MMI_BOOL failed);

/*****************************************************************************
 * FUNCTION
 *  snst_util_get_file_prefix_from_table
 * DESCRIPTION
 *  utility function for getting file prefix by table name
 * PARAMETERS
 *  table          [IN]    table name
 * RETURNS
 *  file prefix for the table
 *****************************************************************************/
const WCHAR *snst_util_get_file_prefix_from_table(U8 table);

/*****************************************************************************
 * FUNCTION
 *  snst_util_get_last_modified_time
 * DESCRIPTION
 *  utility function for getting last modified time of a path
 * PARAMETERS
 *  *path          [IN]    path
 * RETURNS
 *  last modified time of the path
 *****************************************************************************/
kal_uint64 snst_util_get_last_modified_time(WCHAR *path);

/*****************************************************************************
 * FUNCTION
 *  snst_util_log_last_modified_time
 * DESCRIPTION
 *  utility function for logging last modified time
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void snst_util_log_last_modified_time(void);

/*****************************************************************************
 * FUNCTION
 *  snst_util_check_folder_integrity
 * DESCRIPTION
 *  utility function for checking integrity of sns folder
 * PARAMETERS
 *
 * RETURNS
 *  return error code
 *****************************************************************************/
S32 snst_util_check_folder_integrity(void);

/*****************************************************************************
 * FUNCTION
 *  snst_util_restore_backup_files
 * DESCRIPTION
 *  utility function for restoring backup files
 * PARAMETERS
 *
 * RETURNS
 *  return error code
 *****************************************************************************/
S32 snst_util_restore_backup_files(void);

/*****************************************************************************
 * FUNCTION
 *  snst_util_create_necessary_paths
 * DESCRIPTION
 *  utility function for creating necessary paths 
 * PARAMETERS
 *   
 * RETURNS
 *  return error code
 *****************************************************************************/
S32 snst_util_create_necessary_paths(void);

// file operations
/*****************************************************************************
 * FUNCTION
 *  snst_util_get_file_handle
 * DESCRIPTION
 *  utility function for getting file handle
 * PARAMETERS
 *  *tab          [IN]    file prefix
 *  index         [IN]    provider or group index
 *  *id           [IN]    id of a thread
 *  open_flag     [IN]    open flag
 *  *dir          [IN]    file directory 
 * RETURNS
 *  file handle
 *****************************************************************************/
FS_HANDLE snst_util_get_file_handle(const WCHAR *tab, U32 index, CHAR* id, U32 open_flag, WCHAR* folder);

/*****************************************************************************
 * FUNCTION
 *  snst_util_close_file_handle
 * DESCRIPTION
 *  utility function for closing file handle
 * PARAMETERS
 *  handle        [IN]    file handle
 *  do_commit     [IN]    commit the file or not
 * RETURNS
 *  void
 *****************************************************************************/
void snst_util_close_file_handle(FS_HANDLE hdlr, MMI_BOOL do_commit);

/*****************************************************************************
 * FUNCTION
 *  snst_util_delete_file
 * DESCRIPTION
 *  utility function for deleting file
 * PARAMETERS
 *  *tab          [IN]    file prefix
 *  index         [IN]    provider or group index
 *  *id           [IN]    id of a thread
 *  temp_file     [IN]    is temp file or not
 * RETURNS
 *  void
 *****************************************************************************/
void snst_util_delete_file(const WCHAR *tab, U32 index, CHAR* id, MMI_BOOL finish_update);

// string operations
/******************************************************************
 * FUNCTION
 *  snst_util_compare_names
 * DESCRIPTION
 *  utility function for comparing two names
 * PARAMETERS
 *  *name1      [IN]    name1
 *  *name2      [IN]    name2
 * RETURNS
 *  comparing result
 ******************************************************************/
S32 snst_util_compare_names(WCHAR* name1, WCHAR* name2);

/*****************************************************************************
 * FUNCTION
 *  snst_util_compare_ucs2_string
 * DESCRIPTION
 *  utility function for comparing two ucs2 strings.
 * PARAMETERS
 *  string1:            [IN]        First string
 *  string2:            [IN]        Second string
 * RETURNS
 *  >0:                 First is greater than second
 *  =0:                 First is identical to second
 *  <0:                 First is less than second
 *****************************************************************************/
S32 snst_util_compare_ucs2_string(U16 *string1, U16 *string2);

/*****************************************************************************
 * FUNCTION
 *  snst_util_compare_name_with_key_word
 * DESCRIPTION
 *  utility function for finding occurence of a string
 * PARAMETERS
 *  *a          [IN]    target string
 *  *p          [IN]    string to find
 * RETURNS
 *  first occurence of the string
 *****************************************************************************/
WCHAR *snst_util_compare_name_with_key_word(WCHAR *a, WCHAR *p);

#ifdef __MMI_SNS_CALENDAR__
// get birthday number
/******************************************************************
 * FUNCTION
 *  snst_util_get_birthday_in_number
 * DESCRIPTION
 *  utility function for getting number value of birthday string
 * PARAMETERS
 *  *birthday      [IN]    birthday string
 * RETURNS
 *  value of the number
 ******************************************************************/
U32 snst_util_get_birthday_in_number(WCHAR* birthday);

/******************************************************************
 * FUNCTION
 *  snst_util_is_event_in_range
 * DESCRIPTION
 *  utility function for checking a date is in specified range
 * PARAMETERS
 *  tdl_filter      [IN]    specified range
 *  start           [IN]    start time
 *  end             [IN]    end time 
 * RETURNS
 *  comparing result
 ******************************************************************/
S32 snst_util_is_event_in_range(srv_sns_event_search_filter_struct tdl_filter, srv_sns_time_struct start, srv_sns_time_struct end);

/******************************************************************
 * FUNCTION
 *  snst_util_compare_date
 * DESCRIPTION
 *  utility function for comparing two days
 * PARAMETERS
 *  date1      [IN]    first date
 *  date2      [IN]    second date 
 * RETURNS
 *  comparing result
 ******************************************************************/
S32 snst_util_compare_date(srv_sns_time_struct date1, srv_sns_time_struct date2);
#endif
#endif
