/*
 * Copyright (C) Teleca AB, 2002-2007.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */
/*
 * msf_file.h
 *
 * Created by Ingmar Persson
 *
 * Revision  history:
 *   021014, IPN: Added MSF_FILE_CLOSE_ALL
 *
 */

#ifndef _msf_file_h
#define _msf_file_h

#ifndef _msf_int_h
#include "msf_int.h"
#endif




/****************************************
 * File
 ****************************************/

#define MSF_IS_MEM_CARD_PRESNT        gmms_HDIa_IsMemCardPresent

#define MSF_FILE_OPEN                 gmms_HDIa_fileOpen

#define MSF_FILE_OPEN_EXT             gmms_HDIa_fileOpen_ext

#define MSF_FILE_CLOSE                gmms_HDIa_fileClose

#define MSF_FILE_WRITE                gmms_HDIa_fileWrite

#define MSF_FILE_READ                 gmms_HDIa_fileRead

#define MSF_FILE_FLUSH                gmms_HDIa_fileFlush

#define MSF_FILE_SEEK                 gmms_HDIa_fileSeek

#define MSF_FILE_REMOVE               gmms_HDIa_fileRemove

#define MSF_FILE_REMOVE_EXT           gmms_HDIa_fileRemove_ext

#define MSF_FILE_RENAME               gmms_HDIa_fileRename

#define MSF_FILE_RENAME_EXT           gmms_HDIa_fileRename_ext

#define MSF_FILE_MKDIR                gmms_HDIa_fileMkDir

#define MSF_FILE_MKDIR_EXT            gmms_HDIa_fileMkDir_ext

#define MSF_FILE_RMDIR_EXT            gmms_HDIa_fileRmDir_ext

#define MSF_FILE_RMDIR                gmms_HDIa_fileRmDir

#define MSF_FILE_DELDIR_EXT           gmms_HDIa_fileDelDir_ext

#define MSF_FILE_DELDIR               gmms_HDIa_fileDelDir

#define MSF_FILE_GETSIZE_DIR_EXT      gmms_HDIa_fileGetSizeDir_ext

#define MSF_FILE_GETSIZE_DIR          gmms_HDIa_fileGetSizeDir

#define MSF_FILE_READ_DIR_EXT         gmms_HDIa_fileReadDir_ext

#define MSF_FILE_READ_DIR             gmms_HDIa_fileReadDir

#define MSF_FILE_READ_DIR_LONG_EXT    gmms_HDIa_fileReadDirLong_ext

#define MSF_FILE_READ_DIR_LONG        gmms_HDIa_fileReadDirLong

#ifdef MSF_USE_FILE_READ_DIR_SEQ
#define MSF_FILE_READ_DIR_SEQ_EXT     gmms_HDIa_fileReadDirSeq_ext

#define MSF_FILE_READ_DIR_SEQ         gmms_HDIa_fileReadDirSeq

#define MSF_FILE_READ_DIR_SEQ_CLOSE   gmms_HDIa_fileReadDirSeqClose
#endif /* MSF_USE_FILE_READ_DIR_SEQ */

#define MSF_FILE_SETSIZE              gmms_HDIa_fileSetSize

#define MSF_FILE_GETSIZE_EXT          gmms_HDIa_fileGetSize_ext

#define MSF_FILE_GETSIZE              gmms_HDIa_fileGetSize

#define MSF_FILE_SELECT               gmms_HDIa_fileSelect

#define MSF_FILE_CLOSE_ALL            gmms_HDIa_fileCloseAll

#define MSF_FILE_GEN_VIRTUAL_FILENAME gmms_HDIa_fileGenVirtualFileName

#define MSF_FILE_GET_EXTERNAL_FILENAME_EXT  gmms_HDIa_fileGetExternalFileName_ext

#define MSF_FILE_GET_EXTERNAL_FILENAME  gmms_HDIa_fileGetExternalFileName

#define MSF_FILE_GET_LAST_MODIFIED_DATE_EXT  gmms_HDIa_fileLastModifiedDate_ext

#define MSF_FILE_GET_LAST_MODIFIED_DATE  gmms_HDIa_fileLastModifiedDate

#ifdef __NON_BLOCKING_FILE_MOVE_SUPPORT__
#define MSF_FILE_MOVE                  gmms_HDIa_fileMove
#define MSF_FILE_MOVE_EXT2                  gmms_HDIa_fileMove_ext2
#endif

#ifndef __NON_BLOCKING_FILE_MOVE_SUPPORT__
#define MSF_FILE_MOVE_EXT1               gmms_HDIa_filemove_ext1
#endif

#ifdef __USB_IN_NORMAL_MODE__
#define is_mms_storage_exported_to_pc gmms_is_mms_storage_exported_to_pc
#endif

#define MSF_FILE_SET_RDONLY    HDI_FILE_SET_RDONLY

#define MSF_FILE_SET_WRONLY    HDI_FILE_SET_WRONLY

#define MSF_FILE_SET_RDWR      HDI_FILE_SET_RDWR     

#define MSF_FILE_SET_APPEND    HDI_FILE_SET_APPEND

#define MSF_FILE_SET_CREATE    HDI_FILE_SET_CREATE

#define MSF_FILE_SET_CREATE_ALWAYS    HDI_FILE_SET_CREATE_ALWAYS

#define MSF_FILE_SET_EXCL      HDI_FILE_SET_EXCL

#define MSF_FILE_SET_BUFFERED  HDI_FILE_SET_BUFFERED


#define MSF_FILE_SEEK_SET    HDI_FILE_SEEK_SET

#define MSF_FILE_SEEK_CUR    HDI_FILE_SEEK_CUR

#define MSF_FILE_SEEK_END    HDI_FILE_SEEK_END


#define MSF_FILE_DIRTYPE     HDI_FILE_DIRTYPE 

#define MSF_FILE_FILETYPE    HDI_FILE_FILETYPE


#define MSF_FILE_EVENT_READ  HDI_FILE_EVENT_READ

#define MSF_FILE_EVENT_WRITE HDI_FILE_EVENT_WRITE


#define MSF_FILE_READ_READY  HDI_FILE_READ_READY

#define MSF_FILE_WRITE_READY HDI_FILE_WRITE_READY


#define MSF_FILE_OK             HDI_FILE_OK

#define MSF_FILE_ERROR_ACCESS   HDI_FILE_ERROR_ACCESS

#define MSF_FILE_ERROR_DELAYED  HDI_FILE_ERROR_DELAYED

#define MSF_FILE_ERROR_PATH     HDI_FILE_ERROR_PATH

#define MSF_FILE_ERROR_INVALID  HDI_FILE_ERROR_INVALID

#define MSF_FILE_ERROR_SIZE     HDI_FILE_ERROR_SIZE

#define MSF_FILE_ERROR_CARD_ACCESS  HDI_FILE_ERROR_CARD_ACCESS

#define MSF_FILE_ERROR_FULL     HDI_FILE_ERROR_FULL

#define MSF_FILE_ERROR_EOF      HDI_FILE_ERROR_EOF

#define MSF_FILE_ERROR_EXIST    HDI_FILE_ERROR_EXIST

#define MSF_FILE_ERROR_ROOT_DIR_FULL    HDI_FILE_ERROR_ROOT_DIR_FULL

#define HDI_FILE_MOVE_RETAIN_SOURCE  0x01

#define HDI_FILE_MOVE_DO_NOT_OVERWRITE_DEST  0x02

void
gmms_HDI_handle_file_move(void *p);

#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#define MSF_FILE_EXIST                  msf_file_exist
void HDI_FileNameFree(kal_uint8 *fname);
kal_uint8 *HDI_FileNameTranslate(const char *filename);
kal_uint8 *HDI_FileNameTranslate_ext(const char *filename);
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/

#endif
