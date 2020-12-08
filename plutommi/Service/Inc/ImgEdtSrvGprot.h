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
 * ImgEdtSrvGprot.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Image Edit Service global interface header file
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
 * removed!
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __IMG_EDT_SRV_GPROT_H__
#define __IMG_EDT_SRV_GPROT_H__

#ifdef __cplusplus
extern "C" {
#endif

/* get app id & string id */
#include "mmidatatype.h"

/*****************************************************************************
 * 
 *  Object handle types used in Image Editing Service
 *
 *****************************************************************************/
typedef struct srv_ies_app_session  *srv_ies_app_session_handle;
typedef struct srv_ies_image        *srv_ies_image_handle;
typedef struct srv_ies_meta         *srv_ies_meta_handle;
typedef struct srv_ies_preview      *srv_ies_preview_handle;
typedef struct srv_ies_job          *srv_ies_job_handle;
typedef struct srv_ies_doodle_info  *srv_ies_doodle_info_handle;

/*****************************************************************************
 * 
 *  Data Types & Constants
 *
 *****************************************************************************/ 
typedef enum
{
    SRV_IES_OK                      =  0,
    SRV_IES_E_INVALID_ARGS          = -1,
    SRV_IES_E_NOT_ENOUGH_BUFFER     = -2,
    SRV_IES_E_FILE_SIZE_TOO_LARGE   = -3,
    SRV_IES_E_FILE_WRITE_FAILED     = -4,
    SRV_IES_E_FILE_ACCESS_DENIED    = -5,
    SRV_IES_E_RESOLUTION_TOO_SMALL  = -6,
    SRV_IES_E_RESOLUTION_TOO_LARGE  = -7,
    SRV_IES_E_UNSUPPORTED_FORMAT    = -8,
    SRV_IES_E_NOT_IMPLEMENTED       = -10,
    SRV_IES_E_UNEXPECTED            = -11
} srv_ies_result;

typedef enum
{
    SRV_IES_FEATURE_ALL,
    SRV_IES_FEATURE_VIEW,
    SRV_IES_FEATURE_EDIT
} srv_ies_feature_enum;

typedef enum
{
    SRV_IES_COLORFORMAT_RGB565,
    SRV_IES_COLORFORMAT_RGB888,
    SRV_IES_COLORFORMAT_RGBA8888,
    SRV_IES_COLORFORMAT_RGBX8888
} srv_ies_colorformat_enum;

typedef enum
{
    SRV_IES_EFFECT_COLOR_ADJUST,

    SRV_IES_EFFECT_NEGATIVE,
    SRV_IES_EFFECT_GRAYSCALE,
    SRV_IES_EFFECT_MIRROR,

    SRV_IES_EFFECT_BRIGHTNESS,
    SRV_IES_EFFECT_CONTRAST,
    SRV_IES_EFFECT_SEPIA,
    SRV_IES_EFFECT_SHARPNESS,
    SRV_IES_EFFECT_OILPAINT,

    SRV_IES_EFFECT_END_OF_ITEM,
} srv_ies_effect_enum;

typedef enum
{   
    SRV_IES_EFFECT_PARAM_INVALID = 0,

    SRV_IES_EFFECT_PARAM_BRIGHTNESS_STRENGTH = 1,      
    SRV_IES_EFFECT_PARAM_CONTRAST_STRENGTH,            
    SRV_IES_EFFECT_PARAM_SHARPNESS_STRENGTH,           
    
    SRV_IES_EFFECT_PARAM_HUE_ADJUST,                   
    SRV_IES_EFFECT_PARAM_SATURATION_STRENGTH,          

    SRV_IES_EFFECT_PARAM_END_OF_ITEM,
} srv_ies_effect_param_enum;

typedef enum
{
    SRV_IES_ROT_0,
    SRV_IES_ROT_90,
    SRV_IES_ROT_180,
    SRV_IES_ROT_270
} srv_ies_rot_enum;

typedef enum
{
    SRV_IES_RENDER_KEEP_AR,
    SRV_IES_RENDER_STRETCH
} srv_ies_render_enum;

typedef void (*srv_ies_async_callback_func_ptr)(srv_ies_result result, void *pUserData);

#define SRV_IES_JOB_PROGRESS_MAX (100)

/*****************************************************************************
 * FUNCTION
 *  srv_ies_util_error_get_string
 *
 * DESCRIPTION
 *  Get string ID of error message from a failed error code.
 *  
 * PARAMETER
 *  error   [IN]  The specified error code excpt SRV_IES_OK
 *
 * RETURN
 *  Error string ID
 *****************************************************************************/
mmi_str_id srv_ies_util_error_get_string(srv_ies_result error);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_util_is_suffix_supported
 *
 * DESCRIPTION
 *  Quickly check if the filename suffix is in the support list of
 *  service. This is for fastly checking purpose only, since this is 
 *  only a name check.
 *  
 * PARAMETER
 *  pPath   [IN]  Path to file containting suffix, e.g. "D:\somefile.png"
 *
 * RETURN
 *  MMI_TRUE if the suffix is in supported list; else MMI_FALSE is returned
 *****************************************************************************/
MMI_BOOL srv_ies_util_is_suffix_supported(const WCHAR *pPath);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_util_is_file_supported
 *
 * DESCRIPTION
 *  Actually open and scans header of a file, to see if it is supported by 
 *  service.
 * 
 * PARAMETER
 *  pPath   [IN]  Absolute file path for checking if it is supported
 * 
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_util_is_file_supported(const WCHAR *pPath);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_util_fit_bbox
 *
 * DESCRIPTION
 *  Fit the bounding box with the specified box width and height.
 *
 * PARAMETER
 *  bboxWidth  [IN]  The desired bounding box width for fitting
 *  bboxHeight [IN]  The desired bounding box height for fitting
 *  srcWidth   [IN]  The specified source image width to fit
 *  srcHeight  [IN]  The specified source image height to fit
 *  pOutputX   [OUT] Output X relative to left and top bounding box
 *  pOutputY   [OUT] Output Y relative to left and top bounding box
 *  pOutputW   [OUT] The calculated output width for the bounding box
 *  pOutputH   [OUT] The calculate output height for the bounding box
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_util_fit_bbox(S32  bboxWidth,
                                     S32  bboxHeight,
                                     S32  srcWidth,
                                     S32  srcHeight,
                                     S32  *pOutputX,
                                     S32  *pOutputY,
                                     S32  *pOutputW,
                                     S32  *pOutputH);

/*****************************************************************************
 * FUNCTION
 *  srv_ies_app_session_get_required_mem_size
 *
 * DESCRIPTION
 *  Query the memory size required for an application session with a given 
 *  feature set.
 *  
 * PARAMETER
 *  featureSet [IN]  Client specifies what feature set will be used during
 *                   the session. e.g. VIEW feature may use less memory than
 *                   ALL               
 * RETURN
 *  Size in bytes, required to create an Application Session.
 *****************************************************************************/
U32 srv_ies_app_session_get_required_mem_size(srv_ies_feature_enum featureSet);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_app_session_create
 *
 * DESCRIPTION
 *  Create an application session for decoding and manipulating the images.
 *  
 * PARAMETER
 *  appID   [IN]  Application ID used to identify the session, e.g. APPLIB_MEM_AP_ID_PHOEDT
 *  feature [IN]  Client specifies what feature set will be used during the session.
 *                e.g. VIEW feature may use less memory than ALL
 *  pBuf    [IN]  Pointer to the application allocated buffer.
 *  bufSize [IN]  Size of the working buffer. If the size is less than the required
 *                buffer size, the operation may be limited due to insufficient memory
 *  pHApp   [OUT] The created application session for manipulating images
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_app_session_create(MMI_ID                        appID, 
                                          srv_ies_feature_enum          feature,
                                          void                          *pBuf, 
                                          U32                           bufSize, 
                                          srv_ies_app_session_handle    *pHApp);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_app_session_destroy
 *
 * DESCRIPTION
 *  Destory the specified application session.
 *  
 * PARAMETER
 *  hApp [IN]  Application session created by srv_ies_app_session_create
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_app_session_destroy(srv_ies_app_session_handle hApp);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_app_session_get_buf_ptr
 * 
 * DESCRIPTION
 *  This helper function is used to query the buffer pointer used to create
 *  current running session. 
 *
 * PARAMETER
 *  hApp    [IN]  The specified application session
 *  ppBuf   [IN]  Pointer to retrieve the buffer base address
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_app_session_get_buf_ptr(srv_ies_app_session_handle   hApp,
                                               void                         **ppBuf);


/*****************************************************************************
     Image APIs
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_ies_image_create_from_file
 * 
 * DESCRIPTION
 *  Create an IES image object from the specified file path.
 *
 * PARAMETER
 *  hApp    [IN]  Application session, used to allocate the image handle
 *  path    [IN]  File path to the specified image file for editing
 *  hMeta   [IN]  Meta info for accelerating the decoding process
 *  phImage [OUT] Pointer to retrieve the handle representing the image
 *  
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_image_create_from_file(srv_ies_app_session_handle    hApp,
                                              const WCHAR                   *pPath,
                                              srv_ies_meta_handle           hMeta,
                                              srv_ies_image_handle          *pHandle);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_is_image_handle_has_meta
 *
 * DESCRIPTION
 *  Check if the image handle has the meta info.
 *
 * PARAMETER
 *  hImage  [IN]  The specified image handle for checking
 *  
 * RETURN
 *  MMI_TRUE if the operation is succeeded; else MMI_FALSE is returned
 *****************************************************************************/
MMI_BOOL srv_ies_is_image_handle_has_meta(srv_ies_image_handle hImage);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_image_set_meta_info
 * 
 * DESCRIPTION
 *  Set meta info for the specified image.
 * 
 * PARAMETER
 *  hImage  [IN]  The specified image handle for adding meta info
 *  hMeta   [IN]  Meta handle for adding to the specified image
 *  
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_image_set_meta_info(srv_ies_image_handle  hImage,
                                           srv_ies_meta_handle   hMeta);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_image_destroy
 *
 * DESCRIPTION
 *  Destroys the specified image handle.
 *
 * PARAMETER
 *  hImage  [IN] The specified image to be destroyed
 * 
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_image_destroy(srv_ies_image_handle hImage);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_image_get_parent_app_session
 * 
 * DESCRIPTION
 *  Return the app session used to create the image object.
 *
 * PARAMETER
 *  hImage  [IN]  The image handle for querying the session
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_app_session_handle srv_ies_image_get_parent_app_session(srv_ies_image_handle hImage);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_image_get_user_counter
 * 
 * DESCRIPTION
 *  Increases the user counter of the image object. There is no value checking.
 *  user counter is not a true reference count mechanism, but only for client's
 *  booking or debugging. Client can use this user counter to implement their
 *  own reference-counting mechanism.
 *  
 * PARAMETER
 *  hImage  [IN]  The specified image handle
 *
 * RETURN
 *  The user count of the image handle
 *****************************************************************************/
S32 srv_ies_image_get_user_counter(srv_ies_image_handle hImage);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_image_increase_user_counter
 * 
 * DESCRIPTION
 *  Increases the user counter of the image object. There is no value checking.
 *  
 * PARAMETER
 *  hImage  [IN]  The specified image handle
 *
 * RETURN
 *  The resulting user count after increasing
 *****************************************************************************/
S32 srv_ies_image_increase_user_counter(srv_ies_image_handle hImage);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_image_decrease_user_counter
 *
 * DESCRIPTION
 *  Decreases the user counter of the image object. There is no value checking.
 *  
 * PARAMETER
 *  hImage  [IN]  The specified image handle
 *
 * RETURN
 *  The resulting user count after decreasing
 *****************************************************************************/
S32 srv_ies_image_decrease_user_counter(srv_ies_image_handle hImage);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_image_get_source_size
 * 
 * DESCRIPTION
 *  Return source dimension of the specified image.
 *
 * PARAMETER
 *  hImage  [IN]  The image handle for querying the source dimension
 *  pWidth  [OUT] Pointer to retrieve the source image width
 *  pHeight [OUT] Pointer to retrieve the source image height
 *  
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_image_get_source_size(srv_ies_image_handle   hImage,
                                             S32                    *pWidth,
                                             S32                    *pHeight);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_image_crop
 *
 * DESCRIPTION
 *  Crop an image. The input the the "current coordinate", 
 *  ie. upper-left corner of previously cropped result will be (0, 0)
 *  Note: after crop, srv_ies_image_get_source_size() is uneffected,
 *  but the result of srv_ies_image_get_current_size() is changed.
 *
 * PARAMETER
 *  hImage  [IN]  The image handle for cropping
 *  left    [IN]  Left coordinate of the crop window
 *  top     [IN]  top coordinate of the crop window
 *  width   [IN]  The desired crop window width
 *  height  [IN]  The desired crop window height
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_image_crop(srv_ies_image_handle  hImage,
                                  S32                   left,
                                  S32                   top,
                                  S32                   width,
                                  S32                   height);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_image_get_current_size
 * 
 * DESCRIPTION
 *  Return cropped size of the image.
 *
 * PARAMETER
 *  hImage  [IN]  The specified image for querying
 *  pWidth  [OUT] Pointer to retrieve current image width
 *  pHeight [OUT] Pointer to retrieve current image height
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_image_get_current_size(srv_ies_image_handle  hImage,
                                              S32                   *pWidth,
                                              S32                   *pHeight);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_image_undo
 *
 * DESCRIPTION
 *  Undo modifications to an image. Note this is one-step only.
 *
 * PARAMETER
 *  hImage  [IN] The specified image handle for undoing the last oepration.
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_image_undo(srv_ies_image_handle hImage);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_image_render_buffer_async
 *
 * DESCRIPTION
 *  Render the specified image to the output buffer asynchronously.
 *
 * PARAMETER
 *  hImage     [IN]  The specified image handle for rendering operation
 *  pBuf       [IN]  The target canvas buffer base address
 *  bufSize    [IN]  The target canvas buffer size in bytes
 *  width      [IN]  Desired output width for rendering the image
 *  height     [IN]  Desired output height for rendering the image
 *  pitch      [IN]  Line pitch value of the specified canvas buffer
 *  format     [IN]  Color format of the specified canvas buffer
 *  callback   [IN]  Callback for notifying the operation is finished
 *  pUserData  [IN]  Extra user parameters to the callback function
 *  pHJob      [OUT] Job handle represents the render operation
 *  
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_image_render_buffer_async(srv_ies_image_handle               hImage,
                                                 void                               *pBuf,
                                                 U32                                bufSize,
                                                 U32                                width,
                                                 U32                                height,
                                                 U32                                pitch,
                                                 srv_ies_colorformat_enum           format,
                                                 srv_ies_async_callback_func_ptr    callback,
                                                 void                               *pUserData,
                                                 srv_ies_job_handle                 *pHJob);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_image_render_file_async
 *
 * DESCRIPTION
 *  Re-encode the specified image to the output file asynchronously.
 * 
 * PARAMETER
 *  hImage     [IN]  The image handle for rendering operation
 *  pPath      [IN]  The output file path for the rendering
 *  width      [IN]  Desired output width for rendering the image
 *  height     [IN]  Desired output height for rendering the image
 *  option     [IN]  Output mode for the rendering operation
 *                   (i.e SRV_IES_RENDER_KEEP_AR: try fitting the
 *                        buffer and keep the aspect ratio.
 *                        SRV_IES_RENDER_STRETCH: stretch the image
 *                        to the output width and height)
 *  callback   [IN]  Callback for notifying the operation is finished
 *  pUserData  [IN]  Extra user parameters to the callback function
 *  pHJob      [IN]  Job handle represents the render operation
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_image_render_file_async(srv_ies_image_handle             hImage,
                                               const WCHAR                      *pPath,
                                               U32                              width,
                                               U32                              height,
                                               srv_ies_render_enum              option,
                                               srv_ies_async_callback_func_ptr  callback, 
                                               void                             *pUserData,
                                               srv_ies_job_handle               *pHJob);


/*****************************************************************************
     Preview APIs
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_ies_preview_create
 *
 * DESCRIPTION
 *  Create the preview for the specified image.
 *
 * PARAMETER
 *  hImage     [IN]  The specified image handle
 *  pHPreview  [OUT] The output preview handle
 *  pBuf       [IN]  Preview buffer base address
 *  bufSize    [IN]  Preview buffer size in bytes
 *  width      [IN]  The preview image width
 *  height     [IN]  The preview image height
 *  pitch      [IN]  Preview buffer pitch
 *  format     [IN]  Preview buffer color format
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_preview_create(srv_ies_image_handle      hImage,
                                      srv_ies_preview_handle    *pHPreview,
                                      U8                        *pBuf, 
                                      U32                       bufSize,
                                      U32                       width, 
                                      U32                       height, 
                                      U32                       pitch,
                                      srv_ies_colorformat_enum  format);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_preview_destroy
 *
 * DESCRIPTION
 *  Destroy the specified preview. The underlying preview buffer should be
 *  released by the user.
 *
 * PARAMETER
 *  hPreview   [IN]  The specified preview handle
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_preview_destroy(srv_ies_preview_handle hPreview);                                                       


/*****************************************************************************
 * FUNCTION
 *  srv_ies_preview_set_zoom_level
 *
 * DESCRIPTION
 *  Set current zoom level for the spcified preview.
 *
 * PARAMETER
 *  hPreview   [IN] The specified preview handle
 *  level      [IN] The desired zoom level
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_preview_set_zoom_level(srv_ies_preview_handle    hPreview,
                                              float                     level);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_preview_set_zoom_rect
 *
 * DESCRIPTION
 *  Set zoom and pan for the preview, defined by rectangle relatve to the
 *  coordinate image coordinates.
 *
 * PARAMETER
 *  hPreview   [IN]  The specified preview handle for setting the zoom rect
 *  left       [IN]  Left source coordinate relative to current image dimesnion
 *  top        [IN]  Top source coordinate relative to current image dimension
 *  width      [IN]  Source rectangle width relative to current image dimension
 *  height     [IN]  Source rectangle height relative to current image dimension
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_preview_set_zoom_rect(srv_ies_preview_handle  hPreview, 
                                             S32                     left, 
                                             S32                     top,
                                             S32                     width, 
                                             S32                     height);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_preview_get_screen_rect
 *
 * DESCRIPTION
 *  Converts a coordinate from preview to current coordinate system.
 * 
 * PARAMETER
 *  hPreview   [IN] The specified preview handle
 *  pLeft      [OUT] Pointer to retrieve the left coordinate
 *  pTop       [OUT] Pointer to retrieve the top coordinate
 *  pWidth     [OUT] Pointer to retrieve the rectangle width
 *  pHeight    [OUT] Pointer to retrieve the rectangle height
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_preview_get_screen_rect(srv_ies_preview_handle  hPreview, 
                                               S32                     *pLeft, 
                                               S32                     *pTop,
                                               S32                     *pWidth, 
                                               S32                     *pHeight);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_preview_set_pan_delta
 *
 * DESCRIPTION
 *  Set current pan point for the spcified preview.
 *
 * PARAMETER
 *  hPreview   [IN]  The specified preview handle
 *  deltaX     [IN]  X coordinate delta relative to current pan point
 *  deltaY     [IN]  Y coordinate delta relative to current pan point
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_preview_set_pan_delta(srv_ies_preview_handle hPreview,
                                             S32                    deltaX,
                                             S32                    deltaY);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_preview_set_zoom_and_pan
 *
 * DESCRIPTION
 *  Set relative pan(-1.0~1.0) and zoom(1.0 ~ N) to the preview.
 *
 * PARAMETER
 *  hPreview   [IN] The specified preview handle
 *  zoom       [IN] The specified zoom level
 *  panX       [IN] Y coordinate for the pan point
 *  panY       [IN] X coordinate for the pan point
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_preview_set_zoom_and_pan(srv_ies_preview_handle  hPreview,
                                                float                   zoom,
                                                float                   panX,
                                                float                   panY);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_preview_get_zoom_and_pan
 *
 * DESCRIPTION
 *  Set relative pan(-1.0~1.0) and zoom(1.0 ~ N) to the preview.
 *
 * PARAMETER
 *  hPreview   [IN]  The specified preview handle
 *  pLevel     [OUT] Pointer to retrieve the zoom level
 *  pPanX      [OUT] Pointer to retrieve the pan X coordinate
 *  pPanY      [OUT] Pointer to retrieve the pan Y coordinate
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_preview_get_zoom_and_pan(srv_ies_preview_handle  hPreview,
                                                float                   *pLevel,
                                                float                   *pPanX,
                                                float                   *pPanY);

/*****************************************************************************
 * FUNCTION
 *  srv_ies_preview_get_canvas_rect
 * 
 * DESCRIPTION
 *  Retrieves the top left corner and size of the canvas in the given preview.
 * 
 * PARAMETER
 *  hPreview   [IN]  The specified preview handle
 *  pLeft      [OUT] Pointer to retrieve the left coordinate
 *  pTop       [OUT] Pointer to retrieve to top coordinate
 *  pWidth     [OUT] Pointer to retrieve the canvas width
 *  pHeight    [OUT] Pointer to retrieve the canvas height
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_preview_get_canvas_rect(srv_ies_preview_handle   hPreview, 
                                               S32                      *pLeft, 
                                               S32                      *pTop,
                                               S32                      *pWidth, 
                                               S32                      *pHeight);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_preview_get_current_size
 *
 * DESCRIPTION
 *  Get current image size of the specified preview.
 *
 * PARAMETER
 *  hPreview   [IN]  The specified preview handle for querying
 *  pWidth     [OUT] Pointer to retrieve current image width
 *  pHeight    [OUT] Pointer to retrieve current image height
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_preview_get_current_size(srv_ies_preview_handle  hPreview,
                                                S32                     *pWidth,
                                                S32                     *pHeight);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_preview_get_current_rect
 *
 * DESCRIPTION
 *  Get current image ROI for the specified preview
 *
 * PARAMETER
 *  hPreview   [IN]  The specified preview handle for querying
 *  pLeft      [OUT] Pointer to retrieve current ROI left
 *  pTop       [OUT] Pointer to retrieve current ROI top
 *  pWidth     [OUT] Pointer to retrieve current ROI width
 *  pHeight    [OUT] Pointer to retrieve current ROI height
 * 
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_preview_get_current_rect(srv_ies_preview_handle  hPreview, 
                                                S32                     *pLeft, 
                                                S32                     *pTop,
                                                S32                     *pWidth, 
                                                S32                     *pHeight);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_preview_render
 *
 * DESCRIPTION
 *  Render the preview into the canvas buffer synchronously.
 *
 * PARAMETER
 *  hPreview   [IN]  The specified preview handle
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_preview_render(srv_ies_preview_handle hPreview);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_preview_render_async
 *
 * DESCRIPTION
 *  Render the preview into the canvas buffer asynchronously.
 *
 * PARAMETER
 *  hPreview   [IN]  The specified preview handle for rendering
 *  callback   [IN]  User specified callback function for notification
 *  pUserData  [IN]  User specified data for passing into the callback
 *  pHJob      [OUT] The job handle for querying and manipulation
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_preview_render_async(srv_ies_preview_handle          hPreview,
                                            srv_ies_async_callback_func_ptr callback, 
                                            void                            *pUserData,
                                            srv_ies_job_handle              *pHJob);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_preview_render_animated
 *
 * DESCRIPTION
 *  Legacy method for the znimation progress
 *
 * PARAMETER
 *  hPreview   [IN]  The specified preview handle for animation
 *  animDst    [IN]  Target zoom level for animation progress
 *  progress   [IN]  User specified the desired zoom progress
 *  endAnim    [IN]  MMI_TRUE for ending the animation progress
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_preview_render_animated(srv_ies_preview_handle   hPreview, 
                                               float                    animDst,
                                               float                    progress,
                                               MMI_BOOL                 endAnim);

/*****************************************************************************
 * FUNCTION
 *  srv_ies_animation_begin
 *
 * DESCRIPTION
 *  Begin the animation progress with specified frame count
 *
 * PARAMETER
 *  hPreview   [IN]  The specified preview handle for animation
 *  animDst    [IN]  Target zoom level for animation progress
 *  frameCount [IN]  Desired frame count for the animation
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_animation_begin(srv_ies_preview_handle   hPreview, 
                                       float                    animDst,
                                       U32                      frameCount);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_animation_adjust
 *
 * DESCRIPTION
 *  Adjust the animation zoom level
 *
 * PARAMETER
 *  hPreview   [IN]  The specified preview handle for animation
 *  animDst    [IN]  The new target animation level for setting
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_animation_adjust(srv_ies_preview_handle hPreview,
                                        float                  animDst);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_animation_render
 *
 * DESCRIPTION
 *  Render the specified animation frame
 *
 * PARAMETER
 *  hPreview   [IN]  The specified preview handle for animation
 *  frameIndex [IN]  Specified frame index for rendering
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_animation_render(srv_ies_preview_handle  hPreview,
                                        U32                     frameIndex);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_animation_cancel
 *
 * DESCRIPTION
 *  Cancel the animation rendering progress
 *
 * PARAMETER
 *  hPreview   [IN]  The specified preview handle for animation
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_animation_cancel(srv_ies_preview_handle hPreview);

/*****************************************************************************
 * FUNCTION
 *  srv_ies_animation_end
 *
 * DESCRIPTION
 *  Render the last animation frame
 *
 * PARAMETER
 *  hPreview   [IN]  The specified preview handle for animation
 *
 * RETURN
 *  
 *****************************************************************************/
srv_ies_result srv_ies_animation_end(srv_ies_preview_handle hPreview);


/*****************************************************************************
     Job APIs
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_ies_job_get_meta
 *
 * DESCRIPTION
 *  Get the created meta object
 *
 * PARAMETER
 *  hJob    [IN]  The specified job handle for querying
 *  pHMeta  [OUT] Pointer to retrive the meta handle
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_job_get_meta(srv_ies_job_handle  hJob,
                                    srv_ies_meta_handle *pHMeta);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_job_query_progress
 *
 * DESCRIPTION
 *  Query the specified job progress
 *
 * PARAMETER
 *  hJob    [IN]  The specified job handle for querying
 *  pProg   [OUT] Pointer to retrieve current progress
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_job_query_progress(srv_ies_job_handle    hJob,
                                          U32                   *pProg);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_job_cancel
 *
 * DESCRIPTION
 *  Cancel the specified job
 *
 * PARAMETER
 *  hJob [IN]  The specified job handle for canceling
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned. 
 *****************************************************************************/
srv_ies_result srv_ies_job_cancel(srv_ies_job_handle hJob);


/*****************************************************************************
     META APIs
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_ies_meta_create_from_file
 *
 * DESCRIPTION
 *  Create the meta image synchronously
 *
 * PARAMETER
 *  hApp    [IN]  The specified application session handle
 *  pPath   [IN]  User specified source image path
 *  width   [IN]  Desired target meta image width
 *  height  [IN]  Desired target meta image height
 *  pHandle [OUT] Pointer to retrieve the output meta handle
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_meta_create_from_file(srv_ies_app_session_handle    hApp,
                                             const WCHAR                   *pPath,
                                             U32                           width,
                                             U32                           height,
                                             srv_ies_meta_handle           *pHandle);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_meta_create_from_file_async
 *
 * DESCRIPTION
 *  Create the meta image asynchronously
 *
 * PARAMETER
 *  hApp       [IN]  The specified application session handle
 *  pPath      [IN]  The user specified source image path
 *  width      [IN]  The desired target meta image width
 *  height     [IN]  The desired target meta image height
 *  callback   [IN]  Callback for notifying the operation is finished
 *  pUserData  [IN]  Extra user parameters to the callback function
 *  pHJob      [OUT] Job handle represents the creating operation
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_meta_create_from_file_async(srv_ies_app_session_handle       hApp,
                                                   const WCHAR                      *pPath,
                                                   U32                              width,
                                                   U32                              height,
                                                   srv_ies_async_callback_func_ptr  callback,
                                                   void                             *pUserData,
                                                   srv_ies_job_handle               *pHJob);


/*****************************************************************************
 *  srv_ies_meta_create_from_buffer
 *
 * DESCRIPTION
 *  Create meta handle from the data provided in the buffer.
 *  The raw buffer should contain the raw data for the SPMO.
 *
 * PARAMETER
 *  hApp    [IN]  The specified application session handle
 *  pRaw    [IN]  Buffer contains the raw meta information
 *  size    [IN]  Buffer size for checking the boundary
 *  pHandle [OUT] Poiner to retrieve the meta image handle
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_meta_create_from_buffer(srv_ies_app_session_handle   hApp,
                                               U8                           *pRaw,
                                               U32                          size,
                                               srv_ies_meta_handle          *pHandle);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_meta_query_meta_data
 *
 * DESCRIPTION
 *  Query or get meta data from the specified meta handle
 *
 * PARAMETER
 *  hMeta   [IN]  The specified meta image handle
 *  bufSize [IN]  Maximum buffer size for querying
 *  pRaw    [OUT] Buffer for getting the raw meta data
 *  pSize   [OUT] Pointer to retrieve the actual meta size
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_meta_query_data(srv_ies_meta_handle hMeta,
                                       U32                 bufSize,
                                       void                *pRaw,
                                       U32                 *pSize);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_meta_destroy
 *
 * DESCRIPTION
 *  Destroy the specified meta handle
 *
 * PARAMETER
 *  hMeta   [IN]  The specified meta image handle
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_meta_destroy(srv_ies_meta_handle hMeta);


/*****************************************************************************
     ROTATE & FLIP APIs
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_ies_image_rotate_begin
 *
 * DESCRIPTION
 *  Notify the underlying engine for beginning the rotation
 *
 * PARAMETER
 *  hImage  [IN]  The specified image handle
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned. 
 *****************************************************************************/
srv_ies_result srv_ies_image_rotate_begin(srv_ies_image_handle hImage);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_image_rotate_adjust
 *
 * DESCRIPTION
 *  Function to set the rotation angle
 *
 * PARAMETER
 *  hImage  [IN]  The specified image handle
 *  rotType [IN]  User specified rotation type
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_image_rotate_adjust(srv_ies_image_handle hImage,
                                           srv_ies_rot_enum     rotType);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_image_rotate_cancel
 *
 * DESCRIPTION
 *  Cancel the rotation operation
 *
 * PARAMETER
 *  hImage  [IN]  The specified image handle
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_image_rotate_cancel(srv_ies_image_handle hImage);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_image_rotate_end
 *
 * DESCRIPTION
 *  Commit the rotation operation
 *
 * PARAMETER
 *  hImage  [IN]  The specified image handle
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_image_rotate_end(srv_ies_image_handle hImage);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_image_flip_begin
 *
 * DESCRIPTION
 *  Notify the underlying engine for beginning the rotation
 *
 * PARAMETER
 *  hImage  [IN]  The specified image handle
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_image_flip_begin(srv_ies_image_handle hImage);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_image_flip_adjust
 *
 * DESCRIPTION
 *  Function to set the flip direction
 *
 * PARAMETER
 *  hImage     [IN]  The specified image handle
 *  bHorzFlip  [IN]  MMI_TRUE for horizontal flip
 *  bVertFlip  [IN]  MMI_TRUE for vertical flip
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_image_flip_adjust(srv_ies_image_handle   hImage,
                                         MMI_BOOL               bHorzFlip,
                                         MMI_BOOL               bVertFlip);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_image_flip_cancel
 *
 * DESCRIPTION
 *  Function to cancel flip operation
 *
 * PARAMETER
 *  hImage  [IN]  The specified image handle
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_image_flip_cancel(srv_ies_image_handle hImage);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_image_flip_end
 *
 * DESCRIPTION
 *  Commit the flip operation
 *
 * PARAMETER
 *  hImage  [IN]  The specified image handle
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_image_flip_end(srv_ies_image_handle hImage);


/*****************************************************************************
     ICON APIs
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_ies_icon_begin_from_file
 *
 * DESCRIPTION
 *  Add an image file as an icon. It only supports PNG, JPEG, BMP
 *  based image resources. It supports alpha but not colorkey.
 *
 * PARAMETER
 *  hImage  [IN]  Image handle of the specified image
 *  pPath   [IN]  Pointer to the specified image path
 *
 * RETURNS
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_icon_begin_from_file(srv_ies_image_handle    hImage,
                                            const WCHAR             *pPath);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_icon_begin_from_raw_buffer
 *
 * DESCRIPTION
 *  Add an RAW buffer as icon. Note that this buffer will be used by IES
 *  until hImage is destroyed. Therefore, this buffer must be valid even
 *  after calling srv_ies_icon_end.
 *
 * PARAMETER
 *  hImage  [IN]  The specified image handle
 *  pBuf    [IN]  Pointer to input RAW pixel buffer
 *  bufSize [IN]  Source buffer size, in bytes.
 *  width   [IN]  Width of the input image, in pixel
 *  height  [IN]  Height of the input image, in pixel
 *  pitch   [IN]  Bytes between each scan line
 *  format  [IN]  Color format of the pixel buffer
 * 
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_icon_begin_from_raw_buffer(srv_ies_image_handle      hImage,
                                                  void                      *pBuf,
                                                  U32                       bufSize,
                                                  U32                       width,
                                                  U32                       height,
                                                  U32                       pitch,
                                                  srv_ies_colorformat_enum  format);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_icon_begin_from_id
 *
 * DESCRIPTION
 *  Add an image resource as an icon. It only supports PNG(ABM) 
 *  based image resources. It supports alpha but not colorkey.
 *
 * PARAMETER
 *  hImage  [IN]  The specified image handle
 *  imgID   [IN]  Image ID of the image resource
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_icon_begin_from_id(srv_ies_image_handle hImage,
                                          MMI_IMG_ID           imgID);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_icon_get_current_size
 *
 * DESCRIPTION
 *  Retrieves current size of the icon added.
 *
 * PARAMETER
 *  hImage  [IN]  The specified image handle
 *  pWidth  [Out] Pointer to retrieve the icon width
 *  pHeight [Out] Pointer to retrieve the icon height
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_icon_get_current_size(srv_ies_image_handle   hImage,
                                             S32                    *pWidth,
                                             S32                    *pHeight);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_icon_get_min_max_adjustable_size
 *
 * DESCRIPTION
 *  Retrieves minimum and maximum size of the icon
 *
 * PARAMETER
 *  hImage  [IN]  The specified image handle
 *  pMin    [Out] Pointer to retrieve the minimum size
 *  pMax    [Out] Pointer to retrieve the maximum size
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_icon_get_min_max_adjustable_size(srv_ies_image_handle    hImage,
                                                        S32                     *pMin,
                                                        S32                     *pMax);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_icon_adjust_pos
 *
 * DESCRIPTION
 *  Adjust the center of the icon
 *
 * PARAMETER
 *  hImage  [IN]  The specified image handle
 *  centerX [IN]  X coordinate of the center
 *  centerY [IN]  Y coordinate of the center
 * 
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_icon_adjust_pos(srv_ies_image_handle hImage,
                                       S32                  centerX,
                                       S32                  centerY);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_icon_adjust_rotation
 *
 * DESCRIPTION
 *  Adjust the rotation angle of the icon
 *
 * PARAMETER
 *  hImage     [IN]  The specified image handle
 *  rotation   [IN]  Rotation angle of the icon
 * 
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_icon_adjust_rotation(srv_ies_image_handle    hImage,
                                            srv_ies_rot_enum        rotation);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_icon_adjust
 *
 * DESCRIPTION
 *  Adjust the center, size and rotation angle of the icon
 *
 * PARAMETER
 *  hImage     [IN]  The specified image handle
 *  centerX    [IN]  X coordinate of the center
 *  centerY    [IN]  Y coordinate of the center
 *  width      [IN]  Width of the icon
 *  height     [IN]  Height of the icon
 *  rotation   [IN]  Rotation angle of the icon
 * 
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_icon_adjust(srv_ies_image_handle hImage,
                                   S32                  centerX,
                                   S32                  centerY,
                                   S32                  width,
                                   S32                  height,
                                   srv_ies_rot_enum     rotation);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_icon_cancel
 *
 * DESCRIPTION
 *  Cancel the icon operation
 *
 * PARAMETER
 *  hImage  [IN]  The specified image handle
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_icon_cancel(srv_ies_image_handle hImage);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_icon_end
 *
 * DESCRIPTION
 *  Commit the icon operation
 *
 * PARAMETER
 *  hImage  [IN]  The specified image handle
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_icon_end(srv_ies_image_handle hImage);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_frame_begin_from_id
 *
 * DESCRIPTION
 *  Create a frame for compositing with current image
 *
 * PARAMETER
 *  hImage  [IN]  The specified image handle
 *  frameID [IN]  The specified frame ID
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_frame_begin_from_id(srv_ies_image_handle hImage,
                                           MMI_ID               frameID);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_frame_cancel
 *
 * DESCRIPTION
 *  Cancel the frame operation
 *
 * PARAMETER
 *  hImage  [IN]  The specified image handle
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_frame_cancel(srv_ies_image_handle hImage);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_frame_end
 *
 * DESCRIPTION
 *  Commit the frame operation
 *
 * PARAMETER
 *  hImage  [IN]  The specified image handle
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_frame_end(srv_ies_image_handle hImage);

/*****************************************************************************
 * FUNCTION
 *  srv_ies_doodle_create
 *
 * DESCRIPTION
 *  Start a doodle operation. It requires a valid preview object. The preview
 *  cannot change its zoom/pan nor viewing rect after srv_ies_doodle_create(),
 *  until srv_ies_doodle_commit_and_destroy() or srv_ies_doodle_cancel_and_destroy()
 *  is called.
 *
 * PARAMETER
 *  hPreview   [IN]  The specified preview handle for doodle operation
 *  phDoodle   [OUT] Pointer to retrieve the created doodle handle
 *
 * RETURNS
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_doodle_create(srv_ies_preview_handle     hPreview,
                                     srv_ies_doodle_info_handle *pHDoodle);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_doodle_set_color
 *
 * DESCRIPTION
 *  Functin to set pen color
 *
 * PARAMETER
 *  hDoodle [IN]  The specified doodle handle
 *  red     [IN]  User specified red color
 *  green   [IN]  User specified green color
 *  blue    [IN]  User specified blue color
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_doodle_set_color(srv_ies_doodle_info_handle  hDoodle,
                                        U8                          red,
                                        U8                          green,
                                        U8                          blue);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_doodle_set_line_width
 *
 * DESCRIPTION
 *  Function to set doodle line width
 *
 * PARAMETER
 *  hDoodle    [IN]  The specified doodle handle
 *  lineWidth  [IN]  User specified line width
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_doodle_set_line_width(srv_ies_doodle_info_handle hDoodle,
                                             U32                        linwWidth);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_doodle_add_line
 *
 * DESCRIPTION
 *   Function to add doodle line
 *
 * PARAMETER
 *  hDoodle [IN]  The specified doodle handle
 *  srcX    [IN]  Line start X coordinate
 *  srcY    [IN]  Line start Y coordinate
 *  destX   [IN]  Line end X coordinate
 *  destY   [IN]  Line end Y coordinate
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_doodle_add_line(srv_ies_doodle_info_handle   hDoodle,
                                       S32                          srcX,
                                       S32                          srcY,
                                       S32                          dstX,
                                       S32                          dstY);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_doodle_erase_line
 *
 * DESCRIPTION
 *  Function to erase doodle line
 *
 * PARAMETER
 *  hDoodle [IN]  The specified doodle handle
 *  srcX    [IN]  Line start X coordinate
 *  srcY    [IN]  Line start Y coordinate
 *  dstX    [IN]  Line end X coordinate
 *  dstY    [IN]  Line end Y coordinate
 *  radius  [IN]  The doodle line radius
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_doodle_erase_line(srv_ies_doodle_info_handle hDoodle, 
                                         S32                        srcX,
                                         S32                        srcY, 
                                         S32                        dstX,
                                         S32                        dstY, 
                                         S32                        radius);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_doodle_cancel_and_destroy
 *
 * DESCRIPTION
 *  Cancel the doodle operation
 *
 * PARAMETER
 *  hDoodle [IN]  The specified doodle handle
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_doodle_cancel_and_destroy(srv_ies_doodle_info_handle hDoodle);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_doodle_commit_and_destroy
 *
 * DESCRIPTION
 *  Commit the doodle operation
 *
 * PARAMETER
 *  hDoodle [IN]  The specified doodle handle
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_doodle_commit_and_destroy(srv_ies_doodle_info_handle hDoodle);


/********************************************************
     EFFECT APIs
 *********************************************************/
/*****************************************************************************
 * FUNCTION
 *  srv_ies_effect_get_available_count
 *
 * DESCRIPTION
 *  Query how many effect are available
 *
 * PARAMETER
 *  NA
 *
 * RETURN
 *  Number of available effects
 *****************************************************************************/
U32 srv_ies_effect_get_available_count(void);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_effect_get_available_id
 *
 * DESCRIPTION
 *  Query the effect id in available list
 *
 * PARAMETER
 *  index   [IN]  Index of the available effect. 
 *                Ranges from 0 ~ srv_ies_effect_get_available_count()
 *
 * RETURN
 *  Corresponding effect id
 *****************************************************************************/
srv_ies_effect_enum srv_ies_effect_get_available_id(U32 index);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_effect_is_available
 *
 * DESCRIPTION
 *  Query if a specific effect is available
 *
 * PARAMETER
 *  effectID   [IN]  The effect to check
 *
 * RETURN
 *  MMI_TRUE if the effect is available
 *****************************************************************************/
MMI_BOOL srv_ies_effect_is_available(srv_ies_effect_enum effectID);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_effect_begin_adjust
 *
 * DESCRIPTION
 *  Begin adjusting a effect on the specific image
 *
 * PARAMETER
 *  hImage     [IN]  The specified image handle
 *  effectID   [IN]  User specified effect to adjust
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_effect_begin_adjust(srv_ies_image_handle   hImage,
                                           srv_ies_effect_enum    effectID);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_effect_set_param_int
 *
 * DESCRIPTION
 *  Set the parameter of the adjusting effect
 *
 * PARAMETER
 *  hImage  [IN]  The image to apply effect onto.
 *  index   [IN]  Parameter index of the effect
 *  value   [IN]  Integer value of the parameter
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_effect_set_param_int(srv_ies_image_handle    hImage,
                                            U32                     index,
                                            S32                     value);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_effect_cancel_adjust
 *
 * DESCRIPTION
 *  Cancel adjusting the effect on the specific image
 *
 * PARAMETER
 *  hImage  [IN]  The image to apply effect onto
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_effect_cancel_adjust(srv_ies_image_handle hImage);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_effect_end_adjust
 *
 * DESCRIPTION
 *  End adjusting the effect on the specific image
 *
 * PARAMETER
 *  hImage  [IN]  The image to apply effect onto
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_effect_end_adjust(srv_ies_image_handle hImage);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_effect_get_effect_name
 *
 * DESCRIPTION
 *  Get the name of the specific effect
 *
 * PARAMETER
 *  effectID   [IN]  The user specified effect ID
 *  pStrID     [OUT] String ID for describing the name
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_effect_get_effect_name(srv_ies_effect_enum   effectID,
                                              MMI_STR_ID            *pStrID);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_effect_get_param_count
 *
 * DESCRIPTION
 *  Query how many input parameters are available for an effect
 *
 * PARAMETER
 *  effectID   [IN]  The user specified effect ID
 *  pCount     [OUT] The required parameter count
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_effect_get_param_count(srv_ies_effect_enum   effectID,
                                              U32                   *pCount);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_effect_get_param_id
 *
 * DESCRIPTION
 *  Retrieve the unique parameter id of a parameter. This can be used
 *  to associate UI information to the parameter.
 *
 * PARAMETER
 *  effectID   [IN]  The specific effect ID to query
 *  index      [IN]  Parameter index of the effect
 *  pParamID   [OUT] A unique id representing the parameter.
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_effect_get_param_id(srv_ies_effect_enum          effectID,
                                           U32                          index,
                                           srv_ies_effect_param_enum    *pParamID);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_effect_get_param_name
 *
 * DESCRIPTION
 *  Retrieve the GUI descriptive name of the parameter
 *
 * PARAMETER
 *  effectID   [IN]  The specific effect ID to query
 *  index      [IN]  Index of the required parameter
 *  pStrID     [OUT] UI display name of the parameter
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_effect_get_param_name(srv_ies_effect_enum    effectID,
                                             U32                    index,
                                             MMI_STR_ID             *pStrID);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_effect_get_param_default
 *
 * DESCRIPTION
 *  Retrieve the suggested default value of a paramemter.
 *
 * PARAMETER
 *  effectID   [IN]  The specific effect ID to query
 *  index      [IN]  Index of the required parameter
 *  pDefault   [OUT] Suggested default parameter value
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_effect_get_param_default(srv_ies_effect_enum effectID,
                                                U32                 index,
                                                S32                 *pDefault);


/*****************************************************************************
 * FUNCTION
 *  srv_ies_effect_get_param_range
 *
 * DESCRIPTION
 *  Retrieve the valid value range of a paramemter.
 *
 * PARAMETER
 *  effectID   [IN]  The specific effect ID to query
 *  index      [IN]  Index of the required parameter
 *  pMinVal    [OUT] The minimum value of the parameter
 *  pMaxVal    [OUT] The maximal value of the parameter
 *
 * RETURN
 *  SRV_IES_OK if the file is supported by service; else the specified error
 *  code is returned.
 *****************************************************************************/
srv_ies_result srv_ies_effect_get_param_range(srv_ies_effect_enum effectID,
                                              U32                 index,
                                              S32                 *pMinVal,
                                              S32                 *pMaxVal);

#ifdef __cplusplus
}
#endif

#endif /* __IMG_EDT_SRV_GPROT_H__ */
