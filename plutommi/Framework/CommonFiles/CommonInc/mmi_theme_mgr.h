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
 * mmi_theme_mgr.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is the header file for Theme Manager
 *
 * Author:
 * -------
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
#ifndef MMI_THEME_MGR_H
#define MMI_THEME_MGR_H

/* DOM-NOT_FOR_SDK-BEGIN */
#include "MMI_features.h"
#include "CustThemesRes.h"
#include "kal_general_types.h"
#include "custom_mmi_default_value.h"
#include "CustDataRes.h"

/***************************************************************************** 
* Define
*****************************************************************************/

/* the following features are disabled under slim DLT
 * 1. image-id dirty bit  (the imgId - index map is not unique, since there're two img packs) */
#define     __MMI_SLIM_DOWNLOADABLE_THEME__

#define THEME_IMAGE_INFO_HEADER         (8)
#define THEME_IMAGE_OFFSET              (4)
#define THEME_FILE_HANDLE               (4)

#ifndef __MMI_SLIM_DOWNLOADABLE_THEME__
#define MAX_MMI_IMAGEID_IMAGES        (2560)    /* refer to mtk_CurrMaxImageNum */
#endif /* __MMI_SLIM_DOWNLOADABLE_THEME__ */

#define MAX_THEME_IMAGE_HEADER_LENGTH   (THEME_IMAGE_INFO_HEADER+THEME_IMAGE_OFFSET+THEME_FILE_HANDLE)
#define MAX_THEME_IMAGEID_IMAGES        (150)
#define MAX_THEME_NON_IMAGEID_IMAGES    (50)

#define THEME_AUDIO_FILE           "ThemeAud.wav"
#define THEME_AUDIO_MID_FILE       "ThemeAud.mid"
#define THEME_AUDIO_MP3_FILE       "ThemeAud.mp3"
#define THEME_AUDIO_RA_FILE         "ThemeAud.ra"

#define THEME_CHECKSUM_HEADER_SIZE      (4)
#define THEME_FILE_SIZE_HEADER          (4)
#define THEME_NO_OF_BYTE_TO_CHECK_FOR_CRC (512000)      /* 0x80000 Bytes => 512 * 1024 = 524288 Bytes */
#define THEME_AUDIO_FOLDER_PATH       "c:\\Audio"

#define THEME_AUDIO                     0
#define THEME_MIDI                      1
#define THEME_MP3                       2
#define THEME_RA                        3

#define MAX_SUPPORTED_VERSION_NUM       1

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
#define MAXIMUM_THEMES_TONES            1
#endif 

/***************************************************************************** 
* Typedef 
*****************************************************************************/

typedef enum
{
    THEME_TYPE_SYSTEM = 1,
    THEME_TYPE_DOWNLOADED_PHONE,
    THEME_TYPE_DOWNLOADED_CARD
} tm_theme_type_enum;

typedef enum
{
    THEME_ERROR_SUCCESS,
    THEME_ERROR_SPACE_NOT_AVAILABLE,
    THEME_ERROR_THEME_NOT_AVAILABLE,
    THEME_ERROR_FILE_FORMAT_BAD,
    THEME_ERROR_DELETE_FAILURE,
    THEME_ERROR_FAILURE,
    THEME_ERROR_ALREADY_ACTIVATED,
    THEME_ERROR_MAX_COUNT_REACHED,
    THEME_ERROR_INCOMING_CALL,
    THEME_ERROR_PROCESS_QUEUE_SUCESS,
    THEME_ERROR_VERSION_FAILURE,
    THEME_ERROR_LCD_SIZE_MISMATCH,
    THEME_ERROR_FILENAME_INCORRECT,
    THEME_ERROR_USB_MODE_ON,
    THEME_ERROR_PHONE_MODEL_MISMATCH
} tm_theme_error_enum;

/* theme resource type */
typedef enum
{
    THEME_RES_ALTERNATE_IMG,
    THEME_RES_WALLPAPER,
    THEME_RES_SCREENSAVER,
    THEME_RES_RINGTONE,
    THEME_RES_END
} tm_resource_type_enum;

typedef enum
{
    THEME_IMG_LOAD_NEVER,
    THEME_IMG_LOAD_ALWAYS,
    THEME_IMG_LOAD_ONDEMAND,
    THEME_IMG_LOAD_END
} tm_image_load_type_enum;


#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
typedef enum
{
    CURRENT_THEME_TONE_BASE = FUN_GAMES_BASE,
    CURRENT_THEME_INCOMING_CALL_TONE,
    CURRENT_THEME_ALARM_EXPIRY_TONE,
    CURRENT_THEME_TONE_END
} tm_theme_tone_enum;
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 


typedef struct
{
    U8 *mempool_p;
    U32 current_offset;
    U32 total_pool_size;
    U16 unit_size;
} tm_theme_image_header_struct;

typedef struct
{
    S16 nOffset;
} tm_theme_image_cache_struct;

typedef struct 
{
    S32 theme_file_handle;
    U8 imageid_images_headers_pool[MAX_THEME_IMAGE_HEADER_LENGTH *MAX_THEME_IMAGEID_IMAGES];
    U8 non_imageid_images_headers_pool[MAX_THEME_IMAGE_HEADER_LENGTH *MAX_THEME_NON_IMAGEID_IMAGES];
    U8 theme_imageid_image_count;
    MMI_BOOL theme_res_status[THEME_RES_END];
    tm_theme_image_header_struct imageid_images_headers;
    tm_theme_image_header_struct non_imageid_images_headers;
    theme_image_detail_struct theme_image_list[MAX_THEME_IMAGEID_IMAGES];       /* theme_image_detail defined in custThemeRes.c */
    tm_theme_image_cache_struct image_cache[MAX_THEME_IMAGEID_IMAGES];
    U8 theme_type;
} tm_context_struct;
/* DOM-NOT_FOR_SDK-END */

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  GetImageTheme
 * DESCRIPTION
 *  This function is to get the specific images stores in system or downloadable
 *  theme structure. It differs from GetImageFromTheme(), which is only for
 *  downloadable theme. This allows images varying by themes.
 * PARAMETERS
 *  ImageId:     [IN]  Image ID
 * RETURNS
 *  Pointer to the image
 *****************************************************************************/
extern S8 *GetImageTheme(U16 ImageId);


/*****************************************************************************
 * FUNCTION
 *  SetThemes
 * DESCRIPTION
 *  Set the theme
 * PARAMETERS
 *  index:       [IN]        To  the global theme structure
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetThemes(U8 index);


/*****************************************************************************
 * FUNCTION
 *  GetThemesNames
 * DESCRIPTION
 *  Retrieves the existing themes, and no. of themes
 * PARAMETERS
 *  dest:            [OUT] The existing themes.
 * RETURNS
 *  Number of themes
 *****************************************************************************/
extern S32 GetThemesNames(U8 **dest[]);


#ifdef __MMI_THEMES_V2_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  GetImageFromTheme
 * DESCRIPTION
 *  get image from theme file
 * PARAMETERS
 *  ImgID:           [IN] image id
 *  ImgIndex:        [IN] consecutive image index
 *  ImgIDMap:        [IN] (unused)
 *  ImgIDSearchMap:  [IN] (unused)
 *  ImgNames:        [IN] (unused)
 * RETURNS
 *  pointer to image data
 *****************************************************************************/
extern S8 *GetImageFromTheme(U16 ImgID,
                             U16 ImgIndex,
                             const CUSTOM_IMAGE_MAP *ImgIDMap,
                             const CUSTOM_IMAGE_SEARCH_MAP *ImgIDSearchMap,
                             const CUSTOM_IMAGE *ImgNames);
#endif /* __MMI_THEMES_V2_SUPPORT__ */

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__

#ifdef __MMI_DLT_CACHE_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_tm_clear_ondemand_cache
 * DESCRIPTION
 *  clears the ondemand cache by clearing pointer and making offset as zero
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_tm_clear_ondemand_cache(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_get_image_load_type
 * DESCRIPTION
 *  To determine the load type of an image
 * PARAMETERS
 *  img_list_index:      [IN] index of theme image
 * RETURNS
 *  image load type
 *****************************************************************************/
extern tm_image_load_type_enum mmi_tm_get_image_load_type(U32 img_list_index);


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_find_img_in_cache
 * DESCRIPTION
 *  returns image pointer
 * PARAMETERS
 *  img_list_index:      [IN] index of theme image
 *  type:                [IN] image load type
 * RETURNS
 *  pointer to image in cache
 *****************************************************************************/
extern PU8 mmi_tm_find_img_in_cache(U32 img_list_index, tm_image_load_type_enum type);


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_add_img_id_to_cache
 * DESCRIPTION
 *  add image to cache by index of theme image
 * PARAMETERS
 *  img_list_index:      [IN] index of theme image
 *  image_offset:        [IN] offset of image in theme file
 *  type:                [IN] image load type       
 * RETURNS
 *  pointer to image in cache
 *****************************************************************************/
extern PU8 mmi_tm_add_img_id_to_cache(U32 img_list_index, U32 image_offset, tm_image_load_type_enum type);


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_add_to_DLT_img_cache
 * DESCRIPTION
 *  add an image to image cache
 * PARAMETERS
 *  image_offset:        [IN] image offset in theme file
 *  img_load_type:       [IN] image load type
 * RETURNS
 *  pointer to image in cache
 *****************************************************************************/
extern PU8 mmi_tm_add_to_DLT_img_cache(U32 image_offset, tm_image_load_type_enum type);
#endif /* __MMI_DLT_CACHE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_set_imageid
 * DESCRIPTION
 *  this function sets the image id and image offset of the image
 * PARAMETERS
 *  image_id:            [IN] image id
 *  image_offset:        [IN] image offset
 *  type:                [IN] image load type
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_tm_set_imageid(U16 image_id, U32 image_offset, tm_image_load_type_enum type);


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_create_non_imageid_image
 * DESCRIPTION
 *  this function creates non id image buffer and add it to pool
 * PARAMETERS
 *  image_offset:        [IN] image offset in theme file
 *  type:                [IN] image load type
 * RETURNS
 *  current image pointer in image pool buffer
 *****************************************************************************/
extern PU8 mmi_tm_create_non_imageid_image(U32 image_offset, tm_image_load_type_enum type);


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_reset_imageid_image_header_pool
 * DESCRIPTION
 *  this function resets the image header pool buffer for images with IDs
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_tm_reset_imageid_image_header_pool(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_reset_non_imageid_image_header_pool
 * DESCRIPTION
 *  this function resets the image header pool buffer for images without IDs
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_tm_reset_non_imageid_image_header_pool(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_is_theme_dirty_bit_set
 * DESCRIPTION
 *  This function checks whether dirty bit is set for the image or not
 * PARAMETERS
 *  image_index:     [IN] consecutive index of image
 * RETURNS
 *  true if dirty bit set otherwise false
 *****************************************************************************/
extern U8 mmi_tm_is_theme_dirty_bit_set(U16 image_index);


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_get_current_theme_ringtone
 * DESCRIPTION
 *  This function gets the current theme ringtone
 *  (better to use new API: mmi_tm_does_theme_res_exist(THEME_RES_RINGTONE))
 * PARAMETERS
 *  void
 * RETURNS
 *  current theme ringtone exists or not
 *****************************************************************************/
extern pBOOL mmi_tm_get_current_theme_ringtone(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_get_current_theme_screensaver
 * DESCRIPTION
 *  This function gets the current theme screensaver
 *  (better to use new API: mmi_tm_does_theme_res_exist(THEME_RES_SCREENSAVER))
 * PARAMETERS
 *  void
 * RETURNS
 *  current theme screensaver exists or not
 *****************************************************************************/
extern pBOOL mmi_tm_get_current_theme_screensaver(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_theme_version_and_deviceinfo_check
 * DESCRIPTION
 *  It checks theme version and deviceinfo in DLT file(.med)
 * PARAMETERS
 *  theme_file_name:      [IN] theme filename
 * RETURNS
 *  true  : if successfully checks,
 *  false : if unable to check
 *****************************************************************************/
extern MMI_BOOL mmi_tm_theme_version_and_deviceinfo_check(U16 *theme_file_name);


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_handle_audio
 * DESCRIPTION
 *  this function handles downloadable theme audio files
 * PARAMETERS
 *  audio_offset:        [IN] audio data offset in theme file
 *  audio_size:          [IN] audio data size
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_tm_handle_audio(U32 audio_offset, U32 audio_size);


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_get_curr_theme_type
 * DESCRIPTION
 *  This function returns the current activated theme type
 * PARAMETERS
 *  void
 * RETURNS
 *  numeric value of the theme type
 *****************************************************************************/
extern U8 mmi_tm_get_curr_theme_type(void);


/*****************************************************************************
* FUNCTION
*  GetAudioNameWithPathInFileSystem
* DESCRIPTION
*   To Provide Name of Audio With Full Path In File System( Download/Factory)
* PARAMETERS
*	AudioId:		[IN]		index of audio file
*	AudioData:	    [IN/OUT]	buffer to store file path+name
* RETURNS
*	pointer to the filename
* GLOBALS AFFECTED
*   none
*****************************************************************************/
extern CHAR* GetAudioNameWithPathInFileSystem(U16 AudioId, CHAR* AudioData);


/*****************************************************************************
* FUNCTION
*  GetThemeV2TonesInfo
* DESCRIPTION
*   get theme tone info
* PARAMETERS
*	downloadThemeTones:	[IN/OUT]    pointer to tone info array
* RETURNS
*	max. number of theme tones
* GLOBALS AFFECTED
*   none
*****************************************************************************/
extern U8 GetThemeV2TonesInfo(DYNAUDIOINFO  **downloadThemeTones);

#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_theme_manager_init
 * DESCRIPTION
 *  It initilizes the global theme structure 'g_tm_cntx'
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_theme_manager_init(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_verify_theme_checksum
 * DESCRIPTION
 *  This function checks the theme file checksum
 * PARAMETERS
 *  file_name_p:     [IN] theme filename
 * RETURNS
 *  theme error code
 *****************************************************************************/
extern S32 mmi_tm_verify_theme_checksum(U8 *file_name_p);


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_does_theme_res_exist
 * DESCRIPTION
 *  check if specified theme resource exists or not
 * PARAMETERS
 *  void
 * RETURNS
 *  specified theme resource exists or not
 *****************************************************************************/
extern MMI_BOOL mmi_tm_does_theme_res_exist(tm_resource_type_enum res_type);


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_does_theme_have_alt_image
 * DESCRIPTION
 *  This function checks whether downloadable theme has alternative image or not
 * (better to use new API: mmi_tm_does_theme_res_exist(THEME_RES_ALTERNATE_IMG))
 * PARAMETERS
 *  void
 * RETURNS
 *  true if alternate image present otherwise false
 *****************************************************************************/
extern U8 mmi_tm_does_theme_have_alt_image(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_tm_activate
 * DESCRIPTION
 *  activate theme
 * PARAMETERS
 *  theme_id:        [IN] theme id
 *  theme_type:      [IN] theme type
 *  theme_file_name: [IN] theme file pathname
 * RETURNS
 *  error code
 *****************************************************************************/
extern S32 mmi_tm_activate(U32 theme_id, U8 theme_type, U16* theme_file_name);

#endif /* MMI_THEME_MGR_H */ 


