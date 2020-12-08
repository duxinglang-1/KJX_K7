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
 *   ImageViewCui.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Image Viewer Common UI header file.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef CUI_IMGVIEWCUI_H
#define CUI_IMGVIEWCUI_H
/*******************************************************************************
* Include Header File
*******************************************************************************/
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "FileMgrSrvGProt.h"
#include "ImageViewCuiGprot.h"

/*******************************************************************************
* Enum Define
*******************************************************************************/
typedef enum
{
    CUI_IMGVIEW_VIEWMODE_FILENAME,
    CUI_IMGVIEW_VIEWMODE_FILELIST,
    CUI_IMGVIEW_VIEWMODE_FILENAME_ARRAY,
    CUI_IMGVIEW_VIEWMODE_PREFETCH,
    CUI_IMGVIEW_VIEWMODE_IMAGEID_ARRAY,
    CUI_IMGVIEW_VIEWMODE_FOLDER,
    CUI_IMGVIEW_VIEWMODE_END
}cui_imgview_viewmode_enum;

/* 
 * imageview sort type
 */
typedef enum
{
    /* None */
    CUI_IMGVIEW_SORT_NONE = 0,

    /* By name */
    CUI_IMGVIEW_SORT_NAME,

    /* By size */
    CUI_IMGVIEW_SORT_SIZE,

    /* By time */
    CUI_IMGVIEW_SORT_TIME,

    /* By type */
    CUI_IMGVIEW_SORT_TYPE,
    
    /* DOM-NOT_FOR_SDK-BEGIN */
    CUI_IMGVIEW_SORT_END
    /* DOM-NOT_FOR_SDK-END */
} cui_imgview_sort_enum;

/*******************************************************************************
* Structure Define
*******************************************************************************/
/* CUI view screen title customize structure */
typedef struct
{
    CHAR* title_string;
    U16 title_icon;
    MMI_BOOL is_customized;
} cui_imgview_title_custom_struct;

/* CUI view screen lsk customize structure */
typedef struct
{
    U16 stringid;
    U16 imageid;
    MMI_BOOL is_customized;
    MMI_BOOL is_force_enable;
} cui_imgview_lsk_custom_struct;

/* CUI view screen view mode customize structure */
typedef struct
{
    CHAR* buff_ptr;         /* 
                            filename:       store file name
                            filename array: name array pointer
                            prefetch fun:   user data
                            id array:       array pointer
                            folder:         folder path
                            filelist:       not use
                           */
    U32 total_count;
    U32 start_index;
    void *filelist_buffer;
    S32 filelist_buffer_size;
    SRV_FMGR_FILELIST_HANDLE filelist;
    cui_imgview_sort_enum sort_by;
    cui_imgview_viewmode_enum viewmode;
} cui_imgview_mode_struct;

/* CUI image view context struct */
typedef struct
{
    mmi_id imgview_cui_gid;           /* Image view CUI group id */
    U16 parent_app_id;
    void *g_app_cntx_ptr;             /* Reserve for multi-instance */
    U16 storage;
    cui_imgview_title_custom_struct title_confing;
    cui_imgview_mode_struct view_mode;
    cui_imgview_lsk_custom_struct lsk_setting;
    MMI_BOOL cap_enable[CUI_IMGVIEW_CAP_ALL];
    MMI_BOOL storage_select_enable;
} cui_imgview_context_struct;

/* CUI media view context struct */
typedef struct
{
    mmi_id mediaview_cui_gid;           /* Media view CUI group id */
    U16 parent_app_id;
    CHAR* folder_path;
    void *g_app_cntx_ptr;               /* Reserve for multi-instance */
    cui_mediaview_style_enum view_style;
} cui_mediaview_context_struct;
/*******************************************************************************
* Internal API 
*******************************************************************************/
static void cui_imgview_filelist_free(void);
extern void cui_mediaview_set_folder_path(mmi_id media_viewer_id, CHAR* path);
extern mmi_id cui_mediaview_create(mmi_id parent_gid);
extern void cui_mediaview_set_app_id(mmi_id media_viewer_id, U16 app_id);
extern void cui_mediaview_set_browse_style(mmi_id media_viewer_id, cui_mediaview_style_enum browse_style);
extern void cui_mediaview_run(mmi_id media_viewer_id);

#endif /* CUI_IMGVIEWCUI_H */ 

