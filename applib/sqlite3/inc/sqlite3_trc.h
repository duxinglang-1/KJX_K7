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
 *  sqlite3_trc.h
 *
 * Project:
 * --------
 *  SQLite3 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef __SQLITE3_TRC_H__
#define __SQLITE3_TRC_H__
#include "kal_trace.h"
#include "stack_config.h"

/* For MOD_SQLITE3 */
#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "sqlite3_trc_gen.h"
#endif /* TST Trace Defintion */
#endif
BEGIN_TRACE_MAP(MOD_SQLITE3)

    // Error code
    TRC_MSG(SQL_SQLITE_ROW_MSG, "[SQLITE3] SQLITE_ROW not an error")
    TRC_MSG(SQL_SQLITE_DONE_MSG, "[SQLITE3] SQLITE_DONE not an error")
    TRC_MSG(SQL_SQLITE_OK_MSG, "[SQLITE3] SQLITE_OK not an error")
    TRC_MSG(SQL_SQLITE_ERROR_MSG, "[SQLITE3] SQL logic error or missing database")
    TRC_MSG(SQL_SQLITE_PERM_MSG, "[SQLITE3] access permission denied")
    TRC_MSG(SQL_SQLITE_ABORT_MSG, "[SQLITE3] callback requested query abort")
    TRC_MSG(SQL_SQLITE_BUSY_MSG, "[SQLITE3] database is locked")
    TRC_MSG(SQL_SQLITE_LOCKED_MSG, "[SQLITE3] database table is locked")
    TRC_MSG(SQL_SQLITE_NOMEM_MSG, "[SQLITE3] out of memory")
    TRC_MSG(SQL_SQLITE_READONLY_MSG, "[SQLITE3] attempt to write a readonly database")
    TRC_MSG(SQL_SQLITE_INTERRUPT_MSG, "[SQLITE3] interrupted")
    TRC_MSG(SQL_SQLITE_IOERR_MSG, "[SQLITE3] disk I/O error")
    TRC_MSG(SQL_SQLITE_CORRUPT_MSG, "[SQLITE3] database disk image is malformed")
    TRC_MSG(SQL_SQLITE_FULL_MSG, "[SQLITE3] database or disk is full")
    TRC_MSG(SQL_SQLITE_CANTOPEN_MSG, "[SQLITE3] unable to open database file")
    TRC_MSG(SQL_SQLITE_EMPTY_MSG, "[SQLITE3] table contains no data")
    TRC_MSG(SQL_SQLITE_SCHEMA_MSG, "[SQLITE3] database schema has changed")
    TRC_MSG(SQL_SQLITE_TOOBIG_MSG, "[SQLITE3] String or BLOB exceeded size limit")
    TRC_MSG(SQL_SQLITE_CONSTRAINT_MSG, "[SQLITE3] constraint failed")
    TRC_MSG(SQL_SQLITE_MISMATCH_MSG, "[SQLITE3] datatype mismatch")
    TRC_MSG(SQL_SQLITE_MISUSE_MSG, "[SQLITE3] library routine called out of sequence")
    TRC_MSG(SQL_SQLITE_NOLFS_MSG, "[SQLITE3] large file support is disabled")
    TRC_MSG(SQL_SQLITE_AUTH_MSG, "[SQLITE3] authorization denied")
    TRC_MSG(SQL_SQLITE_FORMAT_MSG, "[SQLITE3] auxiliary database format error")
    TRC_MSG(SQL_SQLITE_RANGE_MSG, "[SQLITE3] bind or column index out of range")
    TRC_MSG(SQL_SQLITE_NOTADB_MSG, "[SQLITE3] file is encrypted or is not a database")
    TRC_MSG(SQL_UNKNOW_ERROR_MSG, "[SQLITE3] unknown error")

    // Memory Info
    TRC_MSG(SQL_MEMINFO_PREPARE_MSG, "[SQLITE3] MEM=%d/%d/%d OBJ=%d/%d [sqlite3_prepare]")
    TRC_MSG(SQL_MEMINFO_PREPAREV2_MSG, "[SQLITE3] MEM=%d/%d/%d OBJ=%d/%d [sqlite3_prepare_v2]")
    TRC_MSG(SQL_MEMINFO_PREPARE16_MSG, "[SQLITE3] MEM=%d/%d/%d OBJ=%d/%d [sqlite3_prepare16]")
    TRC_MSG(SQL_MEMINFO_PREPARE16V2_MSG, "[SQLITE3] MEM=%d/%d/%d OBJ=%d/%d [sqlite3_prepare16_v2]")

    TRC_MSG(SQL_MEMINFO_FINALIZE_MSG, "[SQLITE3] MEM=%d/%d/%d OBJ=%d/%d [sqlite3_finalize]")
    TRC_MSG(SQL_MEMINFO_RESET_MSG, "[SQLITE3] MEM=%d/%d/%d OBJ=%d/%d [sqlite3_reset]")
    TRC_MSG(SQL_MEMINFO_CLEAR_BINDINGS_MSG, "[SQLITE3] MEM=%d/%d/%d OBJ=%d/%d [sqlite3_clear_bindings]")
    TRC_MSG(SQL_MEMINFO_ERRMSG_MSG, "[SQLITE3] MEM=%d/%d/%d OBJ=%d/%d [sqlite3_errmsg]")
    TRC_MSG(SQL_MEMINFO_STEP_MSG, "[SQLITE3] MEM=%d/%d/%d OBJ=%d/%d [sqlite3_step]")

    TRC_MSG(SQL_MEMINFO_OPEN_MSG, "[SQLITE3] MEM=%d/%d/%d OBJ=%d/%d [sqlite3_open]")
    TRC_MSG(SQL_MEMINFO_OPENV2_MSG, "[SQLITE3] MEM=%d/%d/%d OBJ=%d/%d [sqlite3_open_v2]")
    TRC_MSG(SQL_MEMINFO_OPEN16_MSG, "[SQLITE3] MEM=%d/%d/%d OBJ=%d/%d [sqlite3_open16]")

    TRC_MSG(SQL_MEMINFO_CLOSE_MSG, "[SQLITE3] MEM=%d/%d/%d OBJ=%d/%d [sqlite3_close]")


    // Log message
    TRC_MSG(SQL_OUTOFMEM_MSG, "[SQLITE3] Out of memory! req=%d free=%d peak=%d/%d")
    TRC_MSG(SQL_GETSHAREFILE_OUTOFMEM_MSG, "[SQLITE3] GetShareFile fail, out of memory")
    TRC_MSG(SQL_GETSHAREFILE_OPENFILE_MSG, "[SQLITE3] GetShareFile fail, cannot open this file, error code = %d")
    TRC_MSG(SQL_DUMPERRORCODE_MSG, "[SQLITE3] ErrorCode(%d)")

    TRC_MSG(SQL_NOMUTEX_MSG, "[SQLITE3] there is no free mutex object")
    TRC_MSG(SQL_WRONG_ENTER_INSTANCE_MSG, "[SQLITE3] in-correct enter/leave instance")
    TRC_MSG(SQL_DBLEAK_MSG, "[SQLITE3] DB leak: %d")
    TRC_MSG(SQL_STATEMENTLEAK_MSG, "[SQLITE3] Statement leak: %d")
    TRC_MSG(SQL_MEMLEAK_MSG, "[SQLITE3] Memory leak: %d")

    // KAL OS
    TRC_MSG(SQL_NOSHARESPACE_MSG, "[SQLITE3] GetShareFile fail due to no free space to place share object")
    TRC_MSG(SQL_CANNOTSHARE_MSG, "[SQLITE3] GetShareFile fail, this db has been opened without share flag")
    TRC_MSG(SQL_DBRDONLY_MSG, "[SQLITE3] GetShareFile fail, this db only can been read only")
    TRC_MSG(SQL_SHAREOOM_MSG, "[SQLITE3] GetShareFile fail, out of memory")
    TRC_MSG(SQL_OPENFILE_MSG, "[SQLITE3] GetShareFile fail, cannot open file: %d")
    TRC_MSG(SQL_SEEKHINT_MSG, "[SQLITE3] GetShareFile fail, set seek hint: %d")

    TRC_MSG(SQL_SEEKERROR_MSG, "[SQLITE3] in kalRead, FS_Seek get error: %d")
    TRC_MSG(SQL_READERROR_MSG, "[SQLITE3] in kalRead, FS_Read get error: %d")
    TRC_MSG(SQL_WRITEERROR_MSG, "[SQLITE3] in kalWrite, FS_Write get error: %d")
    TRC_MSG(SQL_TRUNCATEERROR_MSG, "[SQLITE3] FS_Truncate get error: %d")
    TRC_MSG(SQL_COMMITERROR_MSG, "[SQLITE3] FS_Commit get error: %d")
    TRC_MSG(SQL_GETFILESIZEERROR_MSG, "[SQLITE3] FS_GetFileSize get error: %d")
    TRC_MSG(SQL_LOCKERROR_MSG, "[SQLITE3] LOCK FAILED %d trying for %d but got %d")

END_TRACE_MAP(MOD_SQLITE3)

#endif /* __SQLITE3_TRC_H__ */

