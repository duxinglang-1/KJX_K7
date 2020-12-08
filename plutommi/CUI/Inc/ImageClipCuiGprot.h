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
 *  ImageClipCuiGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Image Clip Cui Gprot head file
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
  ****************************************************************************/
#ifndef IMAGE_CLIP_GPROT_H
#define IMAGE_CLIP_GPROT_H

/*******************************************************************************
* Include Header File
*******************************************************************************/
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_res_range_def.h"

/*******************************************************************************
* Macro Define
*******************************************************************************/

/*******************************************************************************
* type Define
*******************************************************************************/
typedef enum
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_CUI_IMAGE_CLIP_BEGIN = CUI_IMAGE_CLIP_BASE,
    /* DOM-NOT_FOR_SDK-END */

    /* clip and save file sucessful, caller will receive EVT_ID_CUI_IMAGE_CLIP_RESULT_SUCCESS with
      event structure cui_image_clip_evt_struct, caller can get saved file path from the structure, 
      and then EVT_ID_CUI_IMAGE_CLIP_CLOSE_REQUEST */
    EVT_ID_CUI_IMAGE_CLIP_RESULT_SUCCESS,

    /* decode image or clip, save fail, caller will receive EVT_ID_CUI_IMAGE_CLIP_RESULT_FAILED,
      and then EVT_ID_CUI_IMAGE_CLIP_CLOSE_REQUEST */
    EVT_ID_CUI_IMAGE_CLIP_RESULT_FAILED,

    /* clip is sucessful or pressed back to cancel clip on cui screen,
      caller should call cui_image_clip_close() to close clip cui */
    EVT_ID_CUI_IMAGE_CLIP_CLOSE_REQUEST,

    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_CUI_IMAGE_CLIP_MAX
    /* DOM-NOT_FOR_SDK-END */
} cui_image_clip_evt_enum;


typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */

    WCHAR* save_file_path; /* path and name of saved file */
} cui_image_clip_evt_struct;

/*******************************************************************************
* External APIs
*******************************************************************************/
/*****************************************************************************
* FUNCTION
*  cui_image_clip_create
* DESCRIPTION
*  create image clip cui
* PARAMETERS
*  parent_id    :   [IN] parent group id for image clip cui
*  setting       :   [IN] basic setting for image clip cui
*  user_data   :   [IN] data address that needed save by image clip cui
* RETURNS
*  image clip cui group id
* EXAMPLE
*  <code>
*  void mmi_clip_example_launch_clip_cui(void)
*  {
*      MMI_ID parent_id;
*      MMI_ID   cui_gid;
*      WCHAR source_file[CUI_IMAGE_CLIP_FILE_LEN];
*      WCHAR dest_file[CUI_IMAGE_CLIP_FILE_LEN];
*      MMI_BOOL file_supported;
*
*      mmi_wcscpy(source_file, L"D:\photos\wallpaper.jpg");
*
*      file_supported = cui_image_clip_is_file_format_supported((WCHAR *)source_file);
*      if(MMI_FALSE != file_supported)
*      {
*          return;
*      }
*      parent_id = mmi_frm_group_create_ex(GRP_ID_ROOT,
*                                     GRP_ID_AUTO_GEN,
*                                     NULL,
*                                     NULL,
*                                     MMI_FRM_NODE_SMART_CLOSE_FLAG);
*
*      cui_gid = cui_image_clip_create(parent_id, (WCHAR *)source_file, NULL);
*
*      mmi_wcscpy(dest_file, L"D:\photos\wallpaper_new.jpg");
*      cui_image_clip_set_dest_file_path(cui_gid, dest_file);
*
*      cui_image_clip_set_dest_size(cui_gid, g_clip_example.width, g_clip_example.height);
*
*      cui_image_clip_need_preview(cui_gid, MMI_TRUE);
*
*      cui_image_clip_run(cui_gid);
*  }
*  </code>
*****************************************************************************/
extern mmi_id cui_image_clip_create(mmi_id parent_id, WCHAR *source_file, void *user_data);

/*****************************************************************************
* FUNCTION
*   cui_image_clip_set_dest_file_path
* DESCRIPTION
*   set expected file path to save file, should be called before cui_image_cip_run(); if this function
*   was not called, image clip cui will generate a file for caller and return with event
* PARAMETERS
*   cui_gid      :   [IN] group id of image clip cui
*   filepath     :    [IN] file path
* RETURNS
*  void
*****************************************************************************/
extern void cui_image_clip_set_dest_file_path(mmi_id cui_id, WCHAR* filepath);

/*****************************************************************************
* FUNCTION
*   cui_image_clip_set_dest_size
* DESCRIPTION
*   set expected saved file size, should be called before cui_image_clip_run(); this function must
*   be called
* PARAMETERS
*   cui_gid      :   [IN] group id of image clip cui
*   width        :   [IN] expected file width
*   height       :   [IN] expected file height
* RETURNS
*  void
*****************************************************************************/
extern void cui_image_clip_set_dest_size(mmi_id cui_id, U16 width, U16 height);

/*****************************************************************************
* FUNCTION
*  cui_image_clip_run
* DESCRIPTION
*  start to run image clip cui
* PARAMETERS
*  cui_gid      :   [IN] group id of image clip cui
* RETURNS
*  void
*****************************************************************************/
extern void cui_image_clip_run(mmi_id cui_gid);

/*****************************************************************************
* FUNCTION
*  cui_image_clip_close
* DESCRIPTION
*  caller can close cui when received EVT_ID_CUI_IMAGE_CLIP_CLOSE_REQUEST
* PARAMETERS
*  cui_gid      :   [IN] group id of image clip cui
* RETURNS
*  void
*****************************************************************************/
extern void cui_image_clip_close(mmi_id cui_gid);

/*****************************************************************************
* FUNCTION
*  cui_image_clip_is_file_format_supported
* DESCRIPTION
*  check if support the image format
* PARAMETERS
*  filepath         [IN]
* RETURNS
*  support or not
*****************************************************************************/
extern MMI_BOOL cui_image_clip_is_file_format_supported(WCHAR *filepath);
#endif /* IMAGE_CLIP_GPROT_H */
