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
 *    Ime_lib_config.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   common header file for configuring vendor lib storage
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 * 			HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#include "MMI_features_lang_memory_card_config.h"
#include "ImeGprot.h"
#include "MMIDataType.h"
#ifdef __MMI_GUOBI__
#include "Gbtype.h"
#endif

#ifndef __IME_LIB_CONFIG_H__
#define __IME_LIB_CONFIG_H__

/*****************************************************************************
 * Typedef
 *****************************************************************************/
#ifdef __MMI_HANDWRITING_MEMORY_CARD_SUPPORT__
#define HANDWRITING_DATA_FILE_PATH ":\\@IME"
#define MAX_HANDWRITING_DATA_FILE_PATH      256
#endif

#if defined(__MMI_IME_MEMORY_CARD_SUPPORT__)
typedef enum
{
	MMI_IME_LDB_STORAGE_NONE = 0x0,
	MMI_IME_LDB_STORAGE_IN_CARD = 0x01,
	MMI_IME_LDB_STORAGE_IN_ROM = 0x10,
	MMI_IME_LDB_STORAGE_MAX = 0x20
}mmi_ime_ldb_storage_mode_enum;

typedef struct
{
	mmi_imm_support_writing_lang_enum lang_id;	
	MMI_BOOL is_vendor_support; 
}mmi_ime_ldb_infor;

typedef struct
{
	mmi_imm_support_writing_lang_enum lang_id;
#ifdef __MMI_GUOBI__
	GBLANG GBlang;
#endif
	U8 *lang_string;
	U8 *ime_file_name;
	//UI_string_type hw_file_name;
	U16 ime_storage_mode;
	//U16 hw_storage_mode;
	//MMI_BOOL ime_lang_enable;
	//MMI_BOOL hw_lang_enable;
}mmi_ime_memory_card_language_info_struct;


/*****************************************************************************
 * Define
 *****************************************************************************/
#define MAX_LDB_PATH_LENGTH 256
#define MAX_LDB_DATA_BUFFER_SIZE 250*1024
#define MMI_IME_LDB_MEMORY_CARD_PATH "@ime\\ldb\\"

/*****************************************************************************
 * Global  variables
 *****************************************************************************/
extern const mmi_ime_memory_card_language_info_struct g_ime_ldb_storage_infor_tbl[];
#endif

#endif /* !defined(__IME_LIB_CONFIG_H__) */ 

