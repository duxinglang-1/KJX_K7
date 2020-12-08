/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_fmgr_table.h
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_FMGR_TABLE_H__
#define __VAPP_FMGR_TABLE_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"

//#include "mmi_rp_app_venus_filemanager_def.h"
#include "mmi_rp_all_defs.h"
/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
    #include "mmi_features.h"
    #include "custom_mmi_folders_config.h"
#ifdef __cplusplus
}
#endif
/***************************************************************************** 
 * Define
 *****************************************************************************/
#if defined(__COSMOS_NO_USER_DRIVE__)
#define __COSMOS_SLIM_NO_PUBLIC_DRIVE__
#endif //#if defined(__COSMOS_NO_USER_DRIVE__)

#if defined(__MMI_ULTRA_SLIM_FILE_MANAGER__)
#define __COSMOS_SLIM_FMGR_MT6260__
#endif //__MMI_ULTRA_SLIM_FILE_MANAGER__
/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/

/* Aidan test file manager begin */

#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#define VAPP_FMGR_DEFAULT_FOLDER_EBOOKS      VFX_WSTR("Ebook\\")
#define VAPP_FMGR_DEFAULT_FOLDER_PHOTOS      VFX_WSTR("Photos\\")
#define VAPP_FMGR_DEFAULT_FOLDER_RECEIVED    VFX_WSTR("Received\\")
#endif 

#define VAPP_FMGR_DEFAULT_FOLDER_PHBIMAGES   VFX_WSTR("Phbimage")
#define VAPP_FMGR_DEFAULT_FILE_PHBVIDEO      VFX_WSTR("phb_video.dat")

/* default path */

typedef struct _vapp_fmgr_def_link_folder_struct
{
    VfxU16 str_id;
    VfxU16 icon_id;    
    const VfxWChar *path;
} vapp_fmgr_def_link_folder_struct;

const vapp_fmgr_def_link_folder_struct g_def_folder_table[] =
{
    {STR_ID_VAPP_FMGR_MYPICTURE, IMG_ID_VAPP_FMGR_TYPE_DEF_FOLDER, (VfxWChar*)IMAGE_DOWNLOAD_FOLDER_NAME}    
    ,{STR_ID_VAPP_FMGR_MYVIDEO, IMG_ID_VAPP_FMGR_TYPE_DEF_FOLDER, (VfxWChar*)VIDEO_DOWNLOAD_FOLDER_NAME}
    ,{STR_ID_VAPP_FMGR_MYSHOOTING, IMG_ID_VAPP_FMGR_TYPE_DEF_FOLDER, (VfxWChar*)SHOOTING_DOWNLOAD_FOLDER_NAME}
    ,{STR_ID_VAPP_FMGR_MYMUSIC, IMG_ID_VAPP_FMGR_TYPE_DEF_FOLDER, (VfxWChar*)AUDIO_DOWNLOAD_FOLDER_NAME}
    ,{STR_ID_VAPP_FMGR_MYAPPLICATION, IMG_ID_VAPP_FMGR_TYPE_DEF_FOLDER, (VfxWChar*)APPLICATION_DOWNLOAD_FOLDER_NAME}
    ,{STR_ID_VAPP_FMGR_MYRECEIVED, IMG_ID_VAPP_FMGR_TYPE_DEF_FOLDER, (VfxWChar*)RECEIVED_DOWNLOAD_FOLDER_NAME}
    ,{STR_ID_VAPP_FMGR_MYRECORD, IMG_ID_VAPP_FMGR_TYPE_DEF_FOLDER, (VfxWChar*)RECORD_DOWNLOAD_FOLDER_NAME}
    ,{STR_ID_VAPP_FMGR_MYRINGTONE, IMG_ID_VAPP_FMGR_TYPE_DEF_FOLDER, (VfxWChar*)RINGTONE_DOWNLOAD_FOLDER_NAME}
    ,{STR_ID_VAPP_FMGR_MYDOCUMENT, IMG_ID_VAPP_FMGR_TYPE_DEF_FOLDER, (VfxWChar*)DOCUMENT_DOWNLOAD_FOLDER_NAME}
    ,{STR_ID_VAPP_FMGR_MYEBOOK, IMG_ID_VAPP_FMGR_TYPE_DEF_FOLDER, (VfxWChar*)EBOOK_DOWNLOAD_FOLDER_NAME}
};

const S32 g_def_folder_table_size = sizeof(g_def_folder_table) / sizeof(vapp_fmgr_def_link_folder_struct);

typedef struct
    {
        VfxS8 titlebar;
        VfxS8 titlecell;    
        VfxS8 body;
        VfxS8 toolbar;
    } vapp_fmgr_page_component_struct;

const vapp_fmgr_page_component_struct m_page_cp_table[] =
{
    {0, 0, 1, 1}                       /* VAPP_FMGR_DRAW_DRV_PHONE_PAGE */
#ifndef __COSMOS_SLIM_NO_PUBLIC_DRIVE__
    ,{0, 0, 1, 1}                      /* VAPP_FMGR_DRAW_DRV_MEM_PAGE */
#else
    ,{1, 0, 1, 1}                      /* VAPP_FMGR_DRAW_DRV_MEM_PAGE */
#endif

    ,{1, 1, 1, 1}                      /* VAPP_FMGR_DRAW_MARK_SEVERAL_PAGE */    
    ,{1, 1, 1, 1}                      /* VAPP_FMGR_DRAW_NORMAL_LIST_PAGE */
    ,{1, 1, 1, 1}                      /* VAPP_FMGR_DRAW_SINGLE_FILE_SELECT_PAGE */
    ,{1, 1, 1, 1}                      /* VAPP_FMGR_DRAW_MULTI_FILE_SELECT_PAGE */
    ,{1, 1, 1, 1}                      /* VAPP_FMGR_DRAW_FOLDER_SELECT_PAGE */
    ,{1, 1, 1, 1}		       /* VAPP_FMGR_DRAW_MEDIA_PICKER_PAGE */ /* For media picker*/
    ,{1, 1, 1, 0}                      /* VAPP_FMGR_DRAW_FOLDER_BROWSER_LAUNCH_PAGE */    
#ifndef __MMI_SLIM_FILE_MANAGER__
    ,{1, 0, 1, 1}                      /* VAPP_FMGR_DRAW_FILE_DETAIL_PAGE */
#else
    ,{1, 0, 1, 0}                      /* VAPP_FMGR_DRAW_FILE_DETAIL_PAGE */
#endif
    ,{0, 0, 1, 1}                      /* VAPP_FMGR_DRAW_FILE_DETAIL_TAB_PAGE */
#ifndef __COSMOS_SLIM_NO_PUBLIC_DRIVE__
    ,{0, 0, 1, 1}                      /* VAPP_FMGR_DRAW_STORAGE_DETAIL_PHONE_PAGE */
    ,{0, 0, 1, 1}                      /* VAPP_FMGR_DRAW_STORAGE_DETAIL_MEM_PAGE */
#else
    ,{1, 0, 1, 1}                      /* VAPP_FMGR_DRAW_STORAGE_DETAIL_MEM_PAGE */
#endif
};  

const S32 m_page_cp_table_size = sizeof(m_page_cp_table) / sizeof(vapp_fmgr_page_component_struct);

const VfxS32 a_known_fs[] = 
{
        FS_INVALID_FILENAME,
        FS_FILE_NOT_FOUND,
        FS_ACCESS_DENIED,
        FS_PATH_NOT_FOUND,
        FS_ROOT_DIR_FULL,
        FS_DISK_FULL,
        FS_MEDIA_CHANGED,
        FS_DRIVE_NOT_READY,
        FS_FILE_EXISTS,
        FS_DEVICE_BUSY,
        FS_ABORTED_ERROR,
        FS_PATH_OVER_LEN_ERROR
};

const VfxS8 a_known_fs_size = sizeof(a_known_fs)/sizeof(S32);

#endif /* __VAPP_FMGR_TABLE_H__ */
