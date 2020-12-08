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
 *   jvm_file.h
 *
 * Project:
 * --------
 *   Maui_Software
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __JVM_FILE_H__
#define __JVM_FILE_H__

//#define JVM_FILE_DEBUG_SUPPORT

//#define __JVM_FILE_CACHE_SUPPORT__  //James modified start1

#define MAX_WCHAR_FILENAME_LEN         (260)


#define JVM_FILE_TYPE_VRITUAL                       (0x01)
#define JVM_FILE_TYPE_NORMAL                        (0x02)
#define JVM_FILE_TYPE_DRM                           (0x04)
#define JVM_FILE_TYPE_ENCRYPTED_JAR				    (0x08)
#define JVM_FILE_TYPE_CACHED_ENCRYPTED_JAR          (0x10)

typedef struct _jvm_file_struct
{
    kal_uint32 type;
    kal_int32 handle;
    kal_int32 position;
    kal_int32 size;
    kal_int32 encrypt_code;
    kal_uint8 * data;

#ifdef JVM_FILE_DEBUG_SUPPORT
    kal_uint8 filename[10];
#endif /* JVM_FILE_DEBUG_SUPPORT */

} jvm_file_struct;

typedef struct _jvm_file_cache_data_struct
{
    kal_uint8 * data;
    kal_int32 data_size;
    kal_int32 start_index;
    kal_int32 end_index;
    kal_int32 file_handle;
    kal_int32 file_size;
    kal_int32 encrypt_code;
    kal_int32 ref_count;
    kal_char file_name[MAX_WCHAR_FILENAME_LEN];
    struct _jvm_file_cache_data_struct * next;
    struct _jvm_file_cache_data_struct * pre;
    
}jvm_file_cache_data_struct;

/* All APIs is operation in Java database directory, for example, C:/Java/ */


#define O_BINARY                 (0)
#define O_RDONLY                 (FS_READ_ONLY|FS_OPEN_SHARED)
#define O_TRUNC                     (FS_CREATE_ALWAYS|FS_OPEN_SHARED)   /* Not Supported */
#define O_CREAT                     (FS_CREATE)
#define O_WRONLY                 (FS_READ_WRITE|FS_OPEN_SHARED) /* Not Fully Supported */
#define O_RDWR                   (FS_READ_WRITE|FS_OPEN_SHARED)
#define O_COMMIT                 (FS_COMMITTED)

#define Kfread(ptr, size, n, stream)   (Kread((stream), (ptr), (size)*(n))/(size))
#define Kfwrite(ptr, size, n, stream)  (Kwrite((stream), (ptr), (size)*(n))/(size))
#define Kfseek(stream, offset, whence) ((Klseek((stream), (offset), (whence)) == -1) ? (-1) : (0))
#define Kftell(stream)              Klseek((stream), 0, SEEK_CUR)
#define COMMIT(x)                FS_Commit((x))


extern kal_bool jvm_mvm_file_initialize(void);
extern kal_int32 jvm_mvm_file_open(const kal_char * file_path ,int flags);
extern kal_int32 jvm_mvm_file_delete(const kal_char *file_path);
extern kal_int32 jvm_mvm_file_rename(const char *old_file_path, const char *new_file_path);
extern kal_int32 jvm_mvm_file_findfirst(const kal_char * name_pattern,kal_char * firstFileName,kal_int32 name_buffer_length, kal_int32 vm_id); // 20101229: [MAUI_02731591] Changed
extern kal_int32 jvm_mvm_file_findnext(kal_char * file_name,kal_int32 name_length, kal_int32 vm_id); // 20101229: [MAUI_02731591] Changed
extern kal_int32 jvm_mvm_file_close(kal_int32 handle);
extern kal_int32 jvm_mvm_file_commit(kal_int32 handle);
extern kal_int32 jvm_mvm_file_read(kal_int32 handle, void *buf, kal_int32 count);
extern kal_int32 jvm_mvm_file_write(kal_int32 handle, const void *buf, kal_int32 count);
extern kal_int32 jvm_mvm_file_getc(kal_int32 handle);
extern kal_int32 jvm_mvm_file_lseek(kal_int32 handle, kal_int32 offset, kal_int32 whence);
extern kal_int32 jvm_mvm_file_truncate(kal_int32 handle, kal_int32 length);
extern kal_int32 jvm_mvm_file_getsize(kal_int32 handle, kal_uint32 *sz_ptr);
extern kal_bool  jvm_mvm_file_isexist(const kal_char * file_path);
extern kal_char *jvm_mvm_file_get_file_name(const kal_char * file_path);


extern int jvm_file_initialize(void);
extern void jvm_file_finalize(void);
extern int jvm_file_open(const char *filename, int flags);
extern int jvm_file_close(int handle);
extern kal_int32 jvm_file_commit(int handle);
extern int jvm_file_read(int handle, void *buf, int count);
extern int jvm_file_write(int handle, const void *buf, int count);
extern int jvm_file_delete(const char *filename);
extern int jvm_file_delete_ucs(unsigned short *filename);
extern int jvm_file_rename(const char *oldfilename, const char *newfilename);
extern int jvm_file_lseek(int handle, int offset, int whence);
extern int jvm_file_getc(int handle);
extern int jvm_file_truncate(int handle, int length);
extern int jvm_file_getsize(int handle, kal_uint32 *sz_ptr);
extern char *jvm_file_findfirst(char *string);
extern char *jvm_file_findnext(void);
extern int jvm_file_isexist(char *filename);
extern int jvm_file_isexist_ucs(unsigned short *filename);
extern kal_char* getAliasDrive(kal_int32 idx);
extern kal_int32 getAliasDriveType(kal_int32 idx);
extern kal_int32 getRealDrive(kal_int32 type);
extern kal_bool is_system_file(char *filename);
extern kal_bool is_system_file_ucs(unsigned short *filename);
extern kal_int32 check_and_create_hidden_folder(kal_wchar *folder);
extern kal_int32 encrypt_file(kal_int32 handle);
extern kal_int32 jvm_initDrvTable(void);
extern kal_wchar* jvm_getAliasDrive(kal_int32 index);
extern kal_int32 jvm_getRealDrive(kal_int32 index);
extern kal_int64 jvm_file_get_free_space(kal_char drv_letter);
extern kal_int32 jvm_file_get_cluster_size(void);
extern int jvm_file_open_with_path(unsigned short *filename, int flags);
extern int jvm_file_open_as_normal_file(unsigned short *filename, int flags);
extern void jvm_file_register_disk_changed_callback(void (*callback_ptr)(void));
extern void jvm_file_deregister_disk_changed_callback(void);
extern kal_bool jvm_get_imei_value_with_default(kal_uint8 *imei_buf);
extern kal_bool jvm_get_imei_value(kal_uint8 length, kal_uint8 *imei_buf, kal_uint16 rec_index);
extern kal_int32 jvm_convert_fs_handle(kal_int32 fsHandle);
extern kal_int32 jvm_file_need_backup_AliasTable(void);

/* Back-ward compatiable */
#define Kunlink                              jvm_file_delete
#define Krename                              jvm_file_rename
#define Kopen                             jvm_file_open
#define Kclose                            jvm_file_close
#define Kread                             jvm_file_read
#define Kwrite                            jvm_file_write
#define Klseek                            jvm_file_lseek
#define Kgetc                             jvm_file_getc
#define Ktruncate(file, size, filename)               jvm_file_truncate(file, size)
#define Kgetfilesize                      jvm_file_getsize
#define Kfindfirst                           jvm_file_findfirst
#define Kfindnext                         jvm_file_findnext
#define KfileExists                          jvm_file_isexist
#define Kcommit                             jvm_file_commit

//James modified start1
#ifdef __JVM_FILE_CACHE_SUPPORT__
void jvm_mvm_file_set_cache_enabled(kal_bool enabled);
kal_bool jvm_mvm_file_is_cached_enabled();
jvm_file_struct * jvm_mvm_file_get_cached_file(const kal_char * file_name);
jvm_file_struct * jvm_mvm_file_cached_open(const kal_char * file_path,kal_int32 file_handle);
jvm_file_cache_data_struct * jvm_mvm_file_cached_data_create();
kal_int32 jvm_mvm_file_cached_close_callback(kal_int32 handle);
#endif /* __JVM_FILE_CACHE_SUPPORT__ */
//James modified end1
#endif /* __JVM_FILE_H__ */
