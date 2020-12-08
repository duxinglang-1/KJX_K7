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
 *  FileMgrSrvProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  File Manager service internal prototype header.
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
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef SRV_FMGR_PROT_H
#define SRV_FMGR_PROT_H

#ifndef _FMGR_INTERNAL_SOURCE_C_
#error "This header is only for FileManager source!"
#endif

#include "FileMgrSrvGProt.h"
// by RHR //#include "FileMgrSrvIProt.h"
// by RHR //#include "fmt_trc.h"

#include "kal_general_types.h"
#include "kal_public_api.h"

#include "fs_type.h"

#include "MMIDataType.h"
#include "mmi_rp_file_type_def.h"

/****************************************************************************
* FMGR Internal testing option
*****************************************************************************/
#undef SRV_FMGR_TESTBED_ENABLE

/****************************************************************************
* Include Files                                                                
*****************************************************************************/

/****************************************************************************
* Define
*****************************************************************************/

/********************************** Macro **********************************/

#if defined(DEBUG_KAL)
#define FMGR_ASSERT(expr)  {if(!(expr)) { ASSERT(0); } else {}}
#else
#define FMGR_ASSERT(expr)  ASSERT(expr)
#endif

/* 
 * L1: common trace for normal log
 * L2: verbose trace for detail debugging
 */
#define TGL1   TRACE_GROUP_2
#define TGL2   TRACE_GROUP_3

#if !defined(__MTK_TARGET__)
#define FMGR_TRACE0(g, tr, f)              srv_fmgri_write_trace(g, f)
#define FMGR_TRACE1(g, tr, f, a1)          srv_fmgri_write_trace(g, f, a1)
#define FMGR_TRACE2(g, tr, f, a1, a2)      srv_fmgri_write_trace(g, f, a1, a2)
#define FMGR_TRACE3(g, tr, f, a1, a2, a3)  srv_fmgri_write_trace(g, f, a1, a2, a3)
#elif defined(SRV_FMGR_TESTBED_ENABLE)
#define FMGR_TRACE0(g, tr, f)              do { kal_trace(g, tr); srv_fmgri_write_trace(g, f); } while(0)
#define FMGR_TRACE1(g, tr, f, a1)          do { kal_trace(g, tr, a1); srv_fmgri_write_trace(g, f, a1); } while(0)
#define FMGR_TRACE2(g, tr, f, a1, a2)      do { kal_trace(g, tr, a1, a2); srv_fmgri_write_trace(g, f, a1, a2); } while(0)
#define FMGR_TRACE3(g, tr, f, a1, a2, a3)  do { kal_trace(g, tr, a1, a2, a3); srv_fmgri_write_trace(g, f, a1, a2, a3); } while(0)
#else
#define FMGR_TRACE0(g, tr, f)              kal_trace(g, tr)
#define FMGR_TRACE1(g, tr, f, a1)          kal_trace(g, tr, a1)
#define FMGR_TRACE2(g, tr, f, a1, a2)      kal_trace(g, tr, a1, a2)
#define FMGR_TRACE3(g, tr, f, a1, a2, a3)  kal_trace(g, tr, a1, a2, a3)
#endif

/********************************** Enum  **********************************/
typedef enum
{
    SRV_FMGRI_PLUG_IN = 0,
    
    SRV_FMGRI_PLUG_OUT,
    SRV_FMGRI_PLUG_DISPLAY_MOUNTING,

    SRV_FMGRI_PLUG_END
} srv_fmgri_plug_status_enum;


/********************************* Typedef ********************************/

/****************************************************************************
* Global variable
*****************************************************************************/

/****************************************************************************
* Global Function
*****************************************************************************/

#define srv_fmgri_alloc_path_buffer()   srv_fmgri_alloc_path_buffer_internal(__LINE__)
WCHAR*  srv_fmgri_alloc_path_buffer_internal(S32 line);
void    srv_fmgri_free_path_buffer(WCHAR* buffer);

S32     srv_fmgri_path_check_folderpath(const WCHAR* folderpath);

#if defined(SRV_FMGR_TESTBED_ENABLE) || !defined(__MTK_TARGET__)
void    srv_fmgri_write_trace(S32 g, char* format, ...);
#endif
#if defined(SRV_FMGR_TESTBED_ENABLE)
void    srv_fmgri_set_trace_level(S32 lvl);
#endif

/* 
 * DESCRIPTION
 *  convert Native encoding to UCS2 encoding. If dest_buf is NULL,
 *  this API return required length (in character)
 * PARAMETERS
 *  dest_buf                : [OUT] buffer to store converted result
 *  dest_size               : [IN]  size of buffer
 *  src_buf                 : [IN]  buffer to be converted.
 * RETURNS
 *  > 0 if dest_buf is NULL,
 *  0 if succeed, 
 *  < 0 if FS error (see fs_errcode.h)
 */
S32     srv_fmgri_convert_string(WCHAR* dest_buf, S32 dest_size, const WCHAR* src_buf);

void    srv_fmgri_convert_direntry(srv_fmgr_fileinfo_struct* fileinfo, 
                                   const FS_DOSDirEntry* direntry, 
                                   const WCHAR* filename);

/* 
 * DESCRIPTION
 *  Wrapper of FS_FindFirst, find interested files in a folder.
 *  Maximum length of filename is SRV_FMGR_PATH_MAX_FILE_NAME_LEN
 * PARAMETERS
 *  folderpath              : [IN]  target folder
 *  filter                  : [IN]  intereted file type
 *  start_index             : [IN]  skip first N matched files
 *  name_buf                : [OUT] buffer to store filename of first matched file,
 *                                  cannot be NULL.
 *  name_buf_size           : [IN]  size of buffer
 *  fileinfo                : [OUT] buffer to store fileinfo, can be NULL.
 *  fh                      : [OUT] handle of FindFirst
 * RETURNS
 *  0 if succeed, < 0 if FS error (see fs_errcode.h)
 */
S32     srv_fmgri_find_first(const WCHAR* folderpath, const FMGR_FILTER *filter, S32 start_index,
                             WCHAR* name_buf, S32 name_buf_size, srv_fmgr_fileinfo_struct *fileinfo,
                             FS_HANDLE *fh);
/* 
 * DESCRIPTION
 *  Wrapper of FS_FindNext, find interested files in a folder.
 *  Maximum length of filename is SRV_FMGR_PATH_MAX_FILE_NAME_LEN
 * PARAMETERS
 *  fh                      : [IN]  handle of FindFirst
 *  filter                  : [IN]  intereted file type
 *  name_buf                : [OUT] buffer to store filename of first matched file
 *                                  cannot be NULL.
 *  name_buf_size           : [IN]  size of buffer
 *  fileinfo                : [OUT] buffer to store fileinfo, can be NULL.
 * RETURNS
 *  0 if succeed, < 0 if FS error (see fs_errcode.h)
 */
S32     srv_fmgri_find_next (FS_HANDLE fh, const FMGR_FILTER *filter,
                             WCHAR* name_buf, S32 name_buf_size, srv_fmgr_fileinfo_struct *fileinfo);
/* 
 * DESCRIPTION
 *  Wrapper of FS_FindClose, find interested files in a folder.
 * PARAMETERS
 *  fh                      : [IN]  handle of FindFirst
 * RETURNS
 *  0 if succeed, < 0 if FS error (see fs_errcode.h)
 */
S32     srv_fmgri_find_close(FS_HANDLE fh);

/* 
 * DESCRIPTION
 *  Convert filter struct to pattern array (in FS Format).
 * PARAMETERS
 *  filter_type             : [IN]  filter
 *  buffer                  : [OUT] pattern array, can be NULL to query required size
 *  buffer_count            : [IN]  count of buffer
 * RETURNS
 *  count of pattern converted.
 */
S32     srv_fmgri_construct_filter_pattern(const FMGR_FILTER *filter_type, FS_Pattern_Struct* buffer, U32 buffer_count);

void    srv_fmgri_drv_update_status(U8* drv_table, S32 drv_count, S32 cause, MMI_BOOL in);


#endif /* SRV_FMGR_PROT_H */
