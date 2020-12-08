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
 *  vapp_imgedt_cui_gprot.h
 *
 * Project:
 * --------
 *  Cosmos
 *
 * Description:
 * ------------
 *  
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
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __CUI_IMGOEDT_PROT_H__
#define __CUI_IMGOEDT_PROT_H__
#ifdef __cplusplus
extern "C"
{
#endif

#include "MMI_features.h"
#ifdef __MMI_COSMOS_IMAGECLIPPER__
#include "MMIDataType.h"


/*****************************************************************************  
*   define
*****************************************************************************/
#define CUI_IMGCLIP_DEFAULT_RATIO_WIDTH     (1)
#define CUI_IMGCLIP_DEFAULT_RATIO_HEIGHT    (1)

#define CUI_IMGCLIP_DEFAULT_DEST_WIDTH      (-1)
#define CUI_IMGCLIP_DEFAULT_DEST_HEIGHT     (-1)

/*****************************************************************************  
*   enum
*****************************************************************************/
    
typedef enum
{
    CUI_IMGEDT_OK,
       
    CUI_IMGEDT_E_BASE = -4000,        
    CUI_IMGEDT_E_UNEXPECTED,
    CUI_IMGEDT_E_INVALID_ARGS,
    CUI_IMGEDT_E_NOT_ENOUGH_BUFFER,
    CUI_IMGEDT_E_FILE_SIZE_TOO_LARGE,
    CUI_IMGEDT_E_FILE_ACCESS_DENIED,
    //CUI_IMGEDT_E_RESOLUTION_TOO_SMALL,
    //CUI_IMGEDT_E_RESOLUTION_TOO_LARGE,
    CUI_IMGEDT_E_UNSUPPORTED_RESOLUTION,
    CUI_IMGEDT_E_UNSUPPORTED_FORMAT,
    CUI_IMGEDT_E_NOT_IMPLEMENTED,

}cui_imgclip_result;

/* Image clipper layout */
typedef enum
{
    CUI_IMGCLIP_ROTATE_0,
    CUI_IMGCLIP_ROTATE_270,
    CUI_IMGCLIP_ROTATE_90,
    
    CUI_IMGCLIP_LAYOUT_TOTAL,

    
    CUI_IMGCLIP_LAYOUT_VERT = CUI_IMGCLIP_ROTATE_0,  /* Always show vertical layout */
    CUI_IMGCLIP_LAYOUT_HORIZ = CUI_IMGCLIP_ROTATE_270 /* Always show horizantal layout */

}cui_imgclip_layout_enum;

/* Image resolution */
typedef enum
{
    CUI_IMGCLIP_RESOLUTION_FULL,    /* support full image reslution clip, user can zoom in/out the preview by side bar */
    CUI_IMGCLIP_RESOLUTION_FIT_SCR, /* auto zoom the image to fit in screen, user can't zoom in/out the preview */
    
    CUI_IMGCLIP_RESOLUTION_TOTAL
}cui_imgclip_resolution_enum;

typedef enum
{
    EVT_ID_CUI_IMGCLIP_BASE= VCUI_IMGCLIP,

    EVT_ID_CUI_IMGCLIP_SAVE_REQUEST,   /* send before save new file */
    EVT_ID_CUI_IMGCLIP_SAVE_NEW,       /* save the file with new file name */
    EVT_ID_CUI_IMGCLIP_SAVE_OVERWRITE, /* save file replace old one */
    EVT_ID_CUI_IMGCLIP_CLOSE_REQUEST,  /* request to close image clipper cui*/
    EVT_ID_CUI_IMGCLIP_ALL
}cui_imgclip_evet_enum;


/*****************************************************************************  
*   structure
*****************************************************************************/
typedef struct
{
    U8* scr_file_path;       /* source file path */
    U32 user_data;           /* user data */
}cui_imgclip_launch_struct;

typedef struct
{
    U8* scr_file_path;        /* source file path */
    U8* des_file_path;        /* dest file path */

    U32 parent_data;          /* user data */

    cui_imgclip_layout_enum     layout;       /* image clipper layout type */
    cui_imgclip_resolution_enum resolution;   /* image clipper edit image with full resolution or 
                                               * always resize preview to fit screen size
                                               */

    S32 ratio_w;         /* clip window ratio: w */
    S32 ratio_h;         /* clip window ratio: h */
    MMI_BOOL is_fixed;   /* if clip window ratio is fixed or free */

    S32 dest_width;      /* out put image width*/
    S32 dest_height;     /* out put image height */
    
}cui_imgclip_launch_struct_ex;

typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER
    S32 result;
}cui_imgclip_event_struct;


/*****************************************************************************  
*   Extern Functions for Apps
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  cui_vapp_imgclip_util_check_file_support
 * DESCRIPTION
 *  Query if file is support
 * PARAMETERS 
 *  path            : [IN] Image path
 * RETURNS
 *  onwer id
 *****************************************************************************/
extern S32 cui_vapp_imgclip_is_file_support(const WCHAR *path);

/*****************************************************************************
 * FUNCTION
 *  cui_imgclip_create
 * DESCRIPTION
 *  Create Image clipper CUI instance
 * PARAMETERS
 *  parent_gid      : [IN] parent gid  
 *  arg             : [IN] Image path
 * RETURNS
 *  onwer id
 *****************************************************************************/
extern mmi_id cui_vapp_imgclip_create(mmi_id parent_gid, const cui_imgclip_launch_struct* arg);


/*****************************************************************************
 * FUNCTION
 *  cui_imgclip_run
 * DESCRIPTION
 *  Run image clipper CUI function.
 * PARAMETERS
 *  owner_gid      : [IN] parent gid           
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 cui_vapp_imgclip_run(mmi_id owner_gid);


/*****************************************************************************
 * FUNCTION
 *  cui_imgclip_close
 * DESCRIPTION
 *  close image clipper cui instance.
 * PARAMETERS
 *  owner_gid       : [IN] owner gid          
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 cui_vapp_imgclip_close(mmi_id owner_gid);


/*****************************************************************************
 * FUNCTION
 *  cui_vapp_imgclip_get_user_data
 * DESCRIPTION
 *  get user data
 * PARAMETERS
 *  owner_gid        : [IN]  owner gid          
 *  user_data         : [OUT] user_data       
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 cui_vapp_imgclip_get_user_data(mmi_id owner_gid, U32 *user_data);


/*****************************************************************************
 * FUNCTION
 *  cui_imgclip_set_layout
 * DESCRIPTION
 *  set iamge clipper layout
 * PARAMETERS
 *  owner_gid       : [IN] owner gid          
 *  layout          : [IN] image clipper layout   
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 cui_vapp_imgclip_set_layout(mmi_id owner_gid, cui_imgclip_layout_enum layout);

/*****************************************************************************
 * FUNCTION
 *  cui_imgclip_set_resolution
 * DESCRIPTION
 *  set set image resolution.
 * PARAMETERS
 *  owner_gid       : [IN] owner gid          
 *  type            : [IN] full resolution or resized to fit in screen to edit.  
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 cui_vapp_imgclip_set_resolution(mmi_id owner_gid, cui_imgclip_resolution_enum resolution);


/*****************************************************************************
 * FUNCTION
 *  cui_imgclip_set_ratio_fixed
 * DESCRIPTION
 *  set clip widow resize ratio is fixed or free.
 * PARAMETERS
 *  owner_gid       : [IN] owner gid          
 *  is_fixed        : [IN] Fixed clip window or free adujst.  
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 cui_vapp_imgclip_set_ratio_fixed(mmi_id owner_gid, MMI_BOOL is_fixed);

/*****************************************************************************
 * FUNCTION
 *  cui_imgclip_set_ratio
 * DESCRIPTION
 *  set clip window init ratio. 
 *  if don't care about clip window's ratio, no need to call this interface.
 * PARAMETERS
 *  owner_gid       : [IN] owner gid          
 *  ratio_w         : [IN] ratio width   
 *  ratio_h         : [IN] ratio height    
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 cui_vapp_imgclip_set_ratio(mmi_id owner_gid, S32 ratio_w, S32 ratio_h);

/*****************************************************************************
 * FUNCTION
 *  cui_imgclipr_set_save_size
 * DESCRIPTION
 *  set dest image size, and image clipper will resize the image after clip end.
 *  if you want original size, no need to call this interface
 *  Notice: width & height can't larger then LCD_HEIGHT from cosmos v1.1 revise !!!!!!
 * PARAMETERS
 *  owner_gid       : [IN] owner gid         
 *  width           : [IN] dest image width   
 *  key             : [IN] key type        
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 cui_vapp_imgclip_set_dest_size(mmi_id owner_gid, S32 width, S32 height);

/*****************************************************************************
 * FUNCTION
 *  cui_vapp_imgclip_set_size_limit
 * DESCRIPTION
 *  set dest image width/height limitation, 
 *  ensure save image width/height not larger than input value
 *  Notice: width & height can't larger then LCD_HEIGHT from cosmos v1.1 revise !!!!!!
 * PARAMETERS
 *  owner_gid       : [IN] owner gid         
 *  width           : [IN] width limitation   
 *  key             : [IN] height limitation        
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 cui_vapp_imgclip_set_size_limit(mmi_id owner_gid, S32 width, S32 height);


/*****************************************************************************
 * FUNCTION
 *  cui_imgclip_set_save_path
 * DESCRIPTION
 *  set new clip image destination path.
 *  If don't care save path, no need to call this interface 
 *  and image clipper will save it to the same folder of original image.
 * PARAMETERS
 *  owner_gid       : [IN] owner gid          
 *  path            : [IN] dest path   
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 cui_vapp_imgclip_set_dest_path(mmi_id owner_gid, const U8* path);


/*****************************************************************************
 * FUNCTION
 *  cui_imgclip_get_dest_path
 * DESCRIPTION
 *  get dest image size, call this interface only after clip done.
 * PARAMETERS
 *  owner_gid       : [IN]  owner gid          
 *  path            : [OUT] get dest image patch. 
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 cui_vapp_imgclip_get_dest_path(mmi_id owner_gid, CHAR* path);


/*****************************************************************************
 * FUNCTION
 *  cui_imgclip_get_dest_size
 * DESCRIPTION
 *  get dest image size, call this interface only after clip done.
 *  other wise it will return error.
 * PARAMETERS
 *  owner_gid       : [IN]  owner gid          
 *  width           : [OUT] dest image width   
 *  height          : [OUT] dest image height    
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 cui_vapp_imgclip_get_dest_size(mmi_id owner_gid, S32* width, S32* height);


/*****************************************************************************
 * FUNCTION
 *  cui_imgclip_get_src_size
 * DESCRIPTION
 *  get original image size
 * PARAMETERS
 *  owner_gid        : [IN]  owner gid          
 *  width            : [OUT] original image width   
 *  height           : [OUT] original image height    
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 cui_vapp_imgclip_get_src_size(mmi_id owner_gid, S32* width, S32* height);

/*****************************************************************************
 * FUNCTION
 *  cui_imgclip_get_src_size
 * DESCRIPTION
 *  get original image size
 * PARAMETERS
 *  owner_gid        : [IN]  owner gid          
 *  error_id         : [OUT] error_id       
 * RETURNS
 *  void
 *****************************************************************************/
extern mmi_id cui_vapp_imgclip_get_error_string(mmi_id owner_gid, S32 error_id);

/*****************************************************************************
 * FUNCTION
 *  cui_vapp_imgclip_save_pbm_flie
 * DESCRIPTION
 *  save a pbm image
 * PARAMETERS
 *  cui_id        : [IN]  owner gid     
 *  savePbmFile: [IN]  save a PBM file or not
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 cui_vapp_imgclip_save_pbm_file(mmi_id cui_id,MMI_BOOL savePbmFile);

#endif /* __MMI_COSMOS_PHOTOEDITOR__ */

#ifdef __cplusplus
}
#endif

#endif /* __CUI_IMGEDT_PROT_H__ */

