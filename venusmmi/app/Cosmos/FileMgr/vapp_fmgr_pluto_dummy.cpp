/*  Copyright Statement:
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
 *  vapp_fmgr_pluto_dummy.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "mmi_features.h"
#if defined(__COSMOS_MMI__)
/***************************************************************************** 
 * Include
 *****************************************************************************/
/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
#include "MMI_include.h"

#define _FMGR_INTERNAL_SOURCE_C_

#include "FileMgrSrvGProt.h"	

#include "FileMgrGProt.h"
#include "FileMgrProt.h"
#include "FileMgrInstance.h"
#include "FileMgrFSData.h"
#include "FileMgrMain.h"
#include "FileMgrGUI.h"
#include "FileMgrService.h"
#include "FS_type.h"
#include "FileMgrCuiGProt.h"

mmi_id cui_storage_selector_create(mmi_id caller, U8 default_drive_letter, U32 flag)
{    
    return GRP_ID_INVALID;    
}

void   cui_storage_selector_run(mmi_id cui_id)
{    
}

void   cui_storage_selector_close(mmi_id cui_id)
{    
}

void   cui_storage_selector_set_title(mmi_id cui_id, U16 string, U16 icon)
{    
}

void   cui_storage_selector_set_ui_style(mmi_id cui_id, cui_fmgr_ui_style_enum style)
{    
}

void   cui_storage_selector_set_userdata(mmi_id cui_id, U32 userdata)
{
}
    
U32    cui_storage_selector_get_userdata(mmi_id cui_id)
{
	return 0;
}

WCHAR  cui_storage_selector_get_selected_drive_letter(mmi_id cui_id)
{
    return 0;
}

mmi_id cui_file_selector_create(mmi_id caller, const WCHAR* start_path, const FMGR_FILTER* filter, 
                                cui_file_selector_style_enum style, U32 option_flag)
{
    return GRP_ID_INVALID;
}    

void   cui_file_selector_run(mmi_id cui_id)
{
}

void   cui_file_selector_close(mmi_id cui_id)
{
}

void   cui_file_selector_set_title(mmi_id cui_id, U16 string, U16 icon)
{
}

void   cui_file_selector_set_option(mmi_id cui_id, U32 option_mask, U32 option_value)
{
}

void   cui_file_selector_set_ui_style(mmi_id cui_id, cui_fmgr_ui_style_enum style)
{
}

void   cui_file_selector_set_userdata(mmi_id cui_id, U32 userdata)
{    
}

U32    cui_file_selector_get_userdata(mmi_id cui_id)
{
    return 0;
}

const WCHAR* cui_file_selector_get_folder(mmi_id cui_id)
{
    return NULL;
}

S32    cui_file_selector_get_selected_filepath_old(mmi_id cui_id, FMGR_FILE_INFO_STRUCT* info, WCHAR* path_buffer, S32 path_size)
{
    return 0;
}

S32    cui_file_selector_get_selected_filepath(mmi_id cui_id, srv_fmgr_fileinfo_struct* info, WCHAR* path_buffer, S32 path_size)
{
    return 0;
}

MMI_BOOL   cui_file_option_is_any_option(const WCHAR* file_path)
{
    return MMI_FALSE;
}

#if defined (__MMI_FILE_MANAGER__)
void mmi_fmgr_init(void)
{      
}

void mmi_fmgr_close_option_screen(void)
{    
}

void mmi_fmgr_close_select_path(void)
{ 
}

void mmi_fmgr_init_mmi(void)
{     
}

#endif

#ifdef __cplusplus
}
#endif

#endif /* __COSMOS_MMI__ */
