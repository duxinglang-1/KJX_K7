/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   sqlite3kal.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  This file is the header file of the helper macro/function for SQLite3.
 *  The purpose of this file is to provide some helper macro/function to 
 *   help user to programming SQLite in KAL environment.
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
 
#ifndef SQLITE3_KAL_H
#define SQLITE3_KAL_H

/*
**  Macro for binding kal types 
*/

#define sqlite3_bind_kal_str(stmt, idx, str)\
    sqlite3_bind_text(stmt, idx, str, strlen(str), SQLITE_STATIC)

#define sqlite3_bind_kal_wstr(stmt, idx, wstr)\
    sqlite3_bind_text16(stmt, idx, wstr, kal_wstrlen(wstr) * sizeof(kal_wchar), SQLITE_STATIC)

#define sqlite3_bind_kal_uint8(stmt, idx, value)\
    sqlite3_bind_int(stmt, idx, (int)value)

#define sqlite3_bind_kal_int8(stmt, idx, value)\
    sqlite3_bind_int(stmt, idx, (int)value)

#define sqlite3_bind_kal_uint16(stmt, idx, value)\
    sqlite3_bind_int(stmt, idx, (int)value)

#define sqlite3_bind_kal_int16(stmt, idx, value)\
    sqlite3_bind_int(stmt, idx, (int)value)

#define sqlite3_bind_kal_int32(stmt, idx, value)\
    sqlite3_bind_int(stmt, idx, (int)value)

#define sqlite3_bind_kal_uint32(stmt, idx, value)\
    sqlite3_bind_int64(stmt, idx, (sqlite_int64)value)

#define sqlite3_bind_kal_uint64(stmt, idx, value)\
    sqlite3_bind_int64(stmt, idx, (sqlite_int64)value)

#define sqlite3_bind_kal_int64(stmt, idx, value)\
    sqlite3_bind_int64(stmt, idx, value)

/*
**  Macro for getting column value by kal types 
*/

#define sqlite3_column_kal_str(stmt, idx)\
    (const kal_char*)sqlite3_column_text(stmt, idx)

#define sqlite3_column_kal_wstr(stmt, idx)\
    (const kal_wchar*)sqlite3_column_text16(stmt, idx)

#define sqlite3_column_kal_uint8(stmt, idx)\
    (kal_uint8)sqlite3_column_int(stmt, idx)

#define sqlite3_column_kal_int8(stmt, idx)\
    (kal_int8)sqlite3_column_int(stmt, idx)

#define sqlite3_column_kal_uint16(stmt, idx)\
    (kal_uint16)sqlite3_column_int(stmt, idx)

#define sqlite3_column_kal_int16(stmt, idx)\
    (kal_int16)sqlite3_column_int(stmt, idx)

#define sqlite3_column_kal_uint32(stmt, idx)\
    (kal_uint32)sqlite3_column_int64(stmt, idx)

#define sqlite3_column_kal_int32(stmt, idx)\
    (kal_int32)sqlite3_column_int(stmt, idx)

#define sqlite3_column_kal_uint64(stmt, idx)\
    (kal_uint64)sqlite3_column_int64(stmt, idx)

#define sqlite3_column_kal_int64(stmt, idx)\
    (kal_int64)sqlite3_column_int64(stmt, idx)


#endif

