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
 *  mmi_clipboard_gprot.h
 *
 * Project:
 * --------
 *  MAUI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef MMI_CLIPBOARD_GPROT_H
#define MMI_CLIPBOARD_GPROT_H
#include "MMI_features.h"
#include "app_mem.h"
#include "MMIDataType.h"
#include "fs_type.h"
#include "kal_general_types.h"

/*****************************************************************************
 * Define                                                                     
 *****************************************************************************/
#ifdef __MMI_CLIPBOARD__
    #if 0
/* under construction !*/
    #else
    	/* Support 2k unicode string provisionally */
    	#define MMI_CLIPBOARD_MAX_SIZE       (4096)
    #endif
#else /* __MMI_CLIPBOARD__ */
	#define MMI_CLIPBOARD_MAX_SIZE       (0)
#endif /* __MMI_CLIPBOARD__ */
/* Added 50 bytes means extra space for header&footer&format struct overhead */
#define MMI_CLIPBOARD_CONTENT_SIZE       (MMI_CLIPBOARD_MAX_SIZE + 50)
#define MMI_CLIPBOARD_BUFF_SIZE (MMI_CLIPBOARD_CONTENT_SIZE + APPLIB_MEM_POOL_EXTRA_SIZE)

#define MMI_CLIPBOARD_GUARDPAT_LEN  (1)

/*****************************************************************************
 * Typedef                                                                     
 *****************************************************************************/
typedef enum
{
    MMI_CLIPBOARD_FORMAT_ERROR = -1,
    MMI_CLIPBOARD_FORMAT_BEGIN,
    /* Defaule format */
    MMI_CLIPBOARD_FORMAT_UNICODETEXT = MMI_CLIPBOARD_FORMAT_BEGIN,
    MMI_CLIPBOARD_FORMAT_FILE,
    /*
     * Please add new clipboard format below this comment and before MMI_CLIPBOARD_FORMAT_COUNT
     * How to register new clipboard format 
     *  1. User should add new format in mmi_clipboard_content_format_enum in mmi_clipboard_gprot.h
     *  2. Design new format data structure in mmi_clipboard_gprot.h
     *  3. Register callback function by mmi_clipboard_register_new_content for new type
     *  4. Copy raw data to memory in callback function, please refer mmi_clipboard_unit_test_set_cb
     */
#ifdef MMI_CLIPBOARD_UNIT_TEST
    MMI_CLIPBOARD_FORMAT_IMAGE,
#endif
    MMI_CLIPBOARD_FORMAT_COUNT
} mmi_clipboard_content_format_enum;

typedef enum
{
    MMI_CLIPBOARD_STATUS_BEGIN,
    MMI_CLIPBOARD_STATUS_COPY,
    MMI_CLIPBOARD_STATUS_PAST,
    MMI_CLIPBOARD_STATUS_COUNT
} mmi_clipboard_entry_status_enum;

typedef struct
{
    U32 guard_pattern[MMI_CLIPBOARD_GUARDPAT_LEN];
    mmi_clipboard_content_format_enum entry_format;
    mmi_clipboard_entry_status_enum entry_status;
    U32 entry_size;
} mmi_clipboard_head_struct;

typedef struct
{
    U32 guard_pattern[MMI_CLIPBOARD_GUARDPAT_LEN];
} mmi_clipboard_foot_struct;

/* Type define of clipboard format structure */
typedef struct
{
    S32 len;
    S8 *data;
} mmi_clipboard_unicodetext_data_struct;

typedef struct
{
    S8 file_path[FS_MAX_PATH];
}mmi_clipboard_file_format_data_struct;


typedef void *mmi_clipboard_handle;
typedef void *(*mmi_clipboard_cb_func)(void *);

/*****************************************************************************
 * Extern Global Function                                                      
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_clipboard_init
 * DESCRIPTION
 *  Initialize clipboard context.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_clipboard_init(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_clipboard_set_data
 * DESCRIPTION
 *  Fill the content data into clipboard
 *  This API will invoke callback function if app registered new clipboard type
 *  Please remember call mmi_clipboard_register_new_content(...) firstly. 
 *  But you Should not use GDI mutex in register handler, or else MMI Task may hang.
 * PARAMETERS
 *  type    [IN]    content format type
 *  data    [OUT]   content struct pointer
 * RETURNS
 *  Clipboard content handler
 *  Null pointer    1. memory is not enough
 *                  2. memory overlap happens found in mmi_clipboard_check_guard_pattern
 *                  3. type is invalid
 *                  4. data pointer is NULL
 *                  5. fail to empty data
 *****************************************************************************/
extern mmi_clipboard_handle mmi_clipboard_set_data(mmi_clipboard_content_format_enum type, void *data);

/*****************************************************************************
 * FUNCTION
 *  mmi_clipboard_get_data_by_type
 * DESCRIPTION
 *  Get the content data from clipboard by type
 *  
 * PARAMETERS
 *  type    [IN]    content format type
 * RETURNS
 *  Clipboard handler
 *  NULL pointer 1. this type of clipboard has not been set
 *               2. fail to check guard pattern
 *               3. invalid type
 *****************************************************************************/
extern void *mmi_clipboard_get_data_by_type(mmi_clipboard_content_format_enum type);

/*****************************************************************************
 * FUNCTION
 *  mmi_clipboard_get_data_by_handle
 * DESCRIPTION
 *  Get the content data from clipboard by handler
 *  But you Should not use GDI mutex in register handler, or else MMI Task may hang.
 * PARAMETERS
 *  handle    [IN]  clipboard content handler
 * RETURNS
 *  Clipboard handler
 *  NULL pointer meanse fail to check guard pattern
 *****************************************************************************/
extern void *mmi_clipboard_get_data_by_handle(mmi_clipboard_handle handle);

/*****************************************************************************
 * FUNCTION
 *  mmi_clipboard_empty_data_by_type
 * DESCRIPTION
 *  Empty clipboard data by type
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE    empty successfully
 *  MMI_FALSE   1. NULL handle
 *              2. invalid type 
 *              3. fail to check guard pattern
 *****************************************************************************/
extern MMI_BOOL mmi_clipboard_empty_data_by_type(mmi_clipboard_content_format_enum type);

/*****************************************************************************
 * FUNCTION
 *  mmi_clipboard_empty_data_by_handle
 * DESCRIPTION
 *  Empty clipboard data by handle
 *  But you Should not use GDI mutex in register handler, or else MMI Task may hang.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE    empty successfully
 *  MMI_FALSE   NULL handle, ERROR format
 *****************************************************************************/
extern MMI_BOOL mmi_clipboard_empty_data_by_handle(mmi_clipboard_handle handle);

/*****************************************************************************
 * FUNCTION
 *  mmi_clipboard_get_type_by_handle
 * DESCRIPTION
 *  Get clipboard format type by handle
 *  But you Should not use GDI mutex in register handler, or else MMI Task may hang.
 * PARAMETERS
 *  void
 * RETURNS
 *  Clipboard format type
 *  MMI_CLIPBOARD_FORMAT_ERROR  1. NULL handle
 *                              2. can't find type 
 *                              3. invalid type
 *****************************************************************************/
extern mmi_clipboard_content_format_enum mmi_clipboard_get_type_by_handle(mmi_clipboard_handle handle);

/*****************************************************************************
 * FUNCTION
 *  mmi_clipboard_query_free_space
 * DESCRIPTION
 *  Query left memory in clipboard
 * PARAMETERS
 *  void
 * RETURNS
 *  Free space
 *****************************************************************************/
extern U32 mmi_clipboard_query_free_space(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_clipboard_register_new_content
 * DESCRIPTION
 *  Register callback function for new clipboard format type
 *
 * How to register new clipboard format 
 * 1. User should add new format in mmi_clipboard_content_format_enum in mmi_clipboard_gprot.h
 * 2. Design new format data structure in mmi_clipboard_gprot.h
 * 3. Register callback function by mmi_clipboard_register_new_content for new type
 * 4. Copy raw data to memory in callback function, please refer mmi_clipboard_unit_test_set_cb
 *
 ******But you Should not use GDI mutex in register handler, or else MMI Task may hang**********
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE    register successfully
 *  MMI_FALSE   1. callback function is NULL 
 *              2. type is invalid
 *****************************************************************************/
extern MMI_BOOL mmi_clipboard_register_new_content(mmi_clipboard_content_format_enum type, mmi_clipboard_cb_func set_cb);

/*****************************************************************************
 * FUNCTION
 *  mmi_clipboard_get_memory
 * DESCRIPTION
 *  Get memory from clipboard pool
 * PARAMETERS
 *  mem_size    [IN]    memory size
 *  type        [IN]    format type
 * RETURNS
 *  Clipboard memory pointer
 *  NULL pointer    1. memory size is zero or negtive
 *                  2. type is invalid
 *****************************************************************************/
extern void *mmi_clipboard_get_memory(U32 mem_size, mmi_clipboard_content_format_enum type);

#endif /* MMI_CLIPBOARD_GPROT_H */ 



