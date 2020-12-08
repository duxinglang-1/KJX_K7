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
 * widget_image.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Widget image loading and caching in filesystem
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

#include "widget.h"
#include "widget_struct.h"
#include "widget_linklist.h"
#include "msf_mem.h"
#include "msf_pipe.h"
#include "msf_file.h"
#include "msf_cmmn.h"   /* for msf_cmmn_strcmp_nc() */
#include "filemgrtype.h"


#include "mmi_include.h"
#include "WapResDef.h"

#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"

#include "lcd_sw_rnd.h"
#include "gdi_image_bmp.h"
#include "gdi_image_wbmp.h"
#include "gdi_image_gif.h"
#include "gdi_image_jpeg.h"
#include "gdi_image_png.h"

#include "FileManagerGprot.h"
#include "filemgrgprot.h"

#include "med_api.h"



#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "mdi_camera.h"
#include "mdi_video.h"

#include "lcd_sw_rnd.h"

#ifdef __DRM_SUPPORT__
#include "drm_gprot.h"
#endif 

#ifndef __MTK_TARGET__
#include "stdio.h"
#endif 
#if defined(__MMI_FTE_SUPPORT__)
#include "wgui_categories_util.h"
#endif
/*
 * NOTE: 
 * * 1. CHANGES SHOULD BE SYNCHRONIZED WITH widget_sound.c 
 * * 2. Be sure to check if widget_image_struct->raw == NULL
 * * 3. On resource creation - we can return 0 if the image creation failed (Confirmed by Teleca)
 */
/* to check the image resolution if exceed MSF_INT16 */
#define WIDGET_IMAGE_TOO_LARGE_WIDTH        (0x7FFF)
#define WIDGET_IMAGE_TOO_LARGE_HEIGHT       (0x7FFF)

static void widget_send_notification_load_resource(widget_image_struct *img, /* kal_bool */ int state);
/*Dinesh Memory reduction*/
//static widget_virtual_file_info_struct widget_virtual_file_info_table[WIDGET_VIRTUAL_FILE_INFO_TABLE_SIZE];
//static widget_pre_image_struct widget_predefined_image_table[WAP_IMAGE_ID_END - WAP_IMAGE_ID_BEGIN];

extern widget_virtual_file_info_struct *widget_virtual_file_info_table;
extern widget_pre_image_struct *widget_predefined_image_table;
/*Dinesh end*/
static kal_int32 widget_initialize_image_dimension(MsfImageHandle image);
#ifdef WIDGET_CHECK_IMAGE_IN_DETAIL
static kal_bool widget_check_image_in_detail(MsfImageHandle img);
#endif

#ifdef __MMI_VIDEO_PLAYER__
extern BOOL mmi_vdoply_is_in_app(void);
#endif

/****************************************************************
 * Image format and filename extension conversion
 ***************************************************************/
typedef struct
{
    MsfImageFormat format;
    char fn_ext[6]; /* filename extension */
    const char *mime_type;
    U8 MMI_type;
} widget_image_typeinfo_struct;

/* Reference: mea_cfg.h, sma_cfg.h, sls_cfg.h, msf_mime.c */
const widget_image_typeinfo_struct widget_image_typeinfo_table[] = 
{
    {MsfBmp, ".bmp", "image/bmp", IMAGE_TYPE_BMP},
    {MsfPictogram, ".pic", NULL, IMAGE_TYPE_INVALID},
    {MsfGif, ".gif", "image/gif", IMAGE_TYPE_GIF},
    /* We will use jpg instead of .jpeg by default */
    {MsfJpeg, ".jpg", "image/jpeg", IMAGE_TYPE_JPG},
    {MsfJpeg, ".jpeg", "image/jpeg", IMAGE_TYPE_JPG},
    {MsfPng, ".png", "image/png", IMAGE_TYPE_INVALID},
    {MsfWbmp, ".wbmp", "image/vnd.wap.wbmp", IMAGE_TYPE_WBMP},
    {MsfWbmp, ".wbm", "image/vnd.wap.wbmp", IMAGE_TYPE_WBMP},
    {Msf3gp, ".3gp", "video/3gpp", IMAGE_TYPE_3GP},   /* autumn */
    {Msf3gp, ".3g2", "video/3gpp2",IMAGE_TYPE_3GP},   /* autumn */
    {MsfMp4, ".mp4", "video/mp4", IMAGE_TYPE_MP4},
    {MsfMp4, ".mpeg", "video/mpeg", IMAGE_TYPE_MP4},
    {MsfAvi, ".avi", "video/x-msvideo", IMAGE_TYPE_AVI},
    /* Actually we should not download a proprietary pbm file from WAP web site */
    {(MsfImageFormat) MsfPbmPI, ".pbm", NULL, IMAGE_TYPE_DEVICE_BITMAP}
};

#define WIDGET_IMAGE_TYPEINFO_NUM   (sizeof(widget_image_typeinfo_table)/sizeof(widget_image_typeinfo_struct))

/****************************************************************
 * Widget Pictogram Support
 ***************************************************************/
#ifdef  __MMI_WAP_CORE_PICTOGRAM_SUPPORT__
typedef struct
{
    const char *pictoURL;
    U16 picto_img_id;
} widget_picto_image_struct;

const widget_picto_image_struct widget_pictogram_image_table[] = 
{
    {"core/arrow/up", WAP_IMG_PICT_CORE_ARROW_UP},
    {"core/arrow/down", WAP_IMG_PICT_CORE_ARROW_DOWN},
    {"core/arrow/right", WAP_IMG_PICT_CORE_ARROW_RIGHT},
    {"core/arrow/left", WAP_IMG_PICT_CORE_ARROW_LEFT},

    {"core/arrow/upperRight", WAP_IMG_PICT_CORE_ARROW_UPPERRIGHT},
    {"core/arrow/upperLeft", WAP_IMG_PICT_CORE_ARROW_UPPERLEFT},
    {"core/arrow/lowerRight", WAP_IMG_PICT_CORE_ARROW_LOWERRIGHT},
    {"core/arrow/lowerLeft", WAP_IMG_PICT_CORE_ARROW_LOWERLEFT},
    {"core/arrow/fingerUp", WAP_IMG_PICT_CORE_ARROW_FINGERUP},
    {"core/arrow/fingerDown", WAP_IMG_PICT_CORE_ARROW_FINGERDOWN},
    {"core/arrow/fingerRight", WAP_IMG_PICT_CORE_ARROW_FINGERRIGHT},
    {"core/arrow/fingerLeft", WAP_IMG_PICT_CORE_ARROW_FINGERLEFT},

    {"core/button/1", WAP_IMG_PICT_CORE_BUTTON_1},
    {"core/button/2", WAP_IMG_PICT_CORE_BUTTON_2},
    {"core/button/3", WAP_IMG_PICT_CORE_BUTTON_3},
    {"core/button/4", WAP_IMG_PICT_CORE_BUTTON_4},
    {"core/button/5", WAP_IMG_PICT_CORE_BUTTON_5},
    {"core/button/6", WAP_IMG_PICT_CORE_BUTTON_6},
    {"core/button/7", WAP_IMG_PICT_CORE_BUTTON_7},
    {"core/button/8", WAP_IMG_PICT_CORE_BUTTON_8},
    {"core/button/9", WAP_IMG_PICT_CORE_BUTTON_9},
    {"core/button/0", WAP_IMG_PICT_CORE_BUTTON_0},

    {"core/action/makePhoneCall", WAP_IMG_PICT_CORE_ACTION_MAKEPHONECALL},
    {"core/action/find", WAP_IMG_PICT_CORE_ACTION_FIND},
    {"core/action/userAuthentication", WAP_IMG_PICT_CORE_ACTION_USERAUTHENTICATION},
    {"core/action/password", WAP_IMG_PICT_CORE_ACTION_PASSWORD},
    {"core/action/nextItem", WAP_IMG_PICT_CORE_ACTION_NEXTITEM},
    {"core/action/clear", WAP_IMG_PICT_CORE_ACTION_CLEAR},
    {"core/action/stop", WAP_IMG_PICT_CORE_ACTION_STOP},
    {"core/action/top", WAP_IMG_PICT_CORE_ACTION_TOP},
    {"core/action/next", WAP_IMG_PICT_CORE_ACTION_NEXT},
    {"core/action/back", WAP_IMG_PICT_CORE_ACTION_BACK},

    {"core/message/receive", WAP_IMG_PICT_CORE_MESSAGE_RECEIVE},
    {"core/message/send", WAP_IMG_PICT_CORE_MESSAGE_SEND},
    {"core/message/message", WAP_IMG_PICT_CORE_MESSAGE_MESSAGE},
    {"core/message/document", WAP_IMG_PICT_CORE_MESSAGE_DOCUMENT},
    {"core/message/attachment", WAP_IMG_PICT_CORE_MESSAGE_ATTACHMENT},
    {"core/message/folder", WAP_IMG_PICT_CORE_MESSAGE_FOLDER},
    {"core/message/inbox", WAP_IMG_PICT_CORE_MESSAGE_INBOX},
    {"core/message/outbox", WAP_IMG_PICT_CORE_MESSAGE_OUTBOX},

    
    {"core/state/secure", WAP_IMG_PICT_CORE_STATE_SECURE},
    {"core/state/insecure", WAP_IMG_PICT_CORE_STATE_INSECURE},
    {"core/state/copyright", WAP_IMG_PICT_CORE_STATE_COPYRIGHT},
    {"core/state/trademark", WAP_IMG_PICT_CORE_STATE_TRADEMARK},
    {"core/state/underConstruction", WAP_IMG_PICT_CORE_STATE_UNDERCONSTRUCTION},
    {"core/state/beginner", WAP_IMG_PICT_CORE_STATE_BEGINNER},

    {"core/media/book", WAP_IMG_PICT_CORE_MEDIA_BOOK},
    {"core/media/video", WAP_IMG_PICT_CORE_MEDIA_VIDEO},
    {"core/media/cd", WAP_IMG_PICT_CORE_MEDIA_CD},
    {"core/media/dvd", WAP_IMG_PICT_CORE_MEDIA_DVD},
    {"core/media/game", WAP_IMG_PICT_CORE_MEDIA_GAME},
    {"core/media/radio", WAP_IMG_PICT_CORE_MEDIA_RADIO},
    {"core/media/tv", WAP_IMG_PICT_CORE_MEDIA_TV},

    {"core/info/notice", WAP_IMG_PICT_CORE_INFO_NOTICE},
    {"core/info/charged", WAP_IMG_PICT_CORE_INFO_CHARGED},
    {"core/info/freeofcharge", WAP_IMG_PICT_CORE_INFO_FREEOFCHARGE},
    {"core/info/new", WAP_IMG_PICT_CORE_INFO_NEW},
    {"core/info/position", WAP_IMG_PICT_CORE_INFO_POSITION},
    {"core/info/tollfree", WAP_IMG_PICT_CORE_INFO_TOLLFREE},
    {"core/info/sharpdial", WAP_IMG_PICT_CORE_INFO_SHARPDIAL},
    {"core/info/reserved", WAP_IMG_PICT_CORE_INFO_RESERVED},
    {"core/info/speechinfo", WAP_IMG_PICT_CORE_INFO_SPEECHINFO},
    {NULL, 0}
};
#endif /*  __MMI_WAP_CORE_PICTOGRAM_SUPPORT__ */
/****************************************************************
 * Slow down create the image resource at the background (widget_read_image_from_file_to_raw_file)
 ***************************************************************/
typedef struct
{
    int f;
    int size;
    widget_image_struct *img;
    kal_bool need_add_select;
    kal_bool is_DRM;
}widget_read_from_file_to_raw_file_item;

static widget_read_from_file_to_raw_file_item widget_image_raw_file_list = {0};
static void widget_image_raw_file_check_time_hdlr(void *arg);

#ifdef  __MMI_WAP_CORE_PICTOGRAM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  widget_image_get_pictogram_handle
 * DESCRIPTION
 *  This function checks the specified Pictogram is supported or not.
 * PARAMETERS
 *  pictUri        [IN]        This specify the URL of the specified Pictogram
 * RETURNS
 *  U32  - It returns the corresponding Image ID
 *****************************************************************************/
U32 widget_image_get_pictogram_handle(const char *pictUri)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count = 0;
    char *pictUrilocation = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, WIDGET_IMAGE_GET_PICTOGRAM_HANDLE);
    while (widget_pictogram_image_table[count].pictoURL != NULL && widget_pictogram_image_table[count].picto_img_id != 0)
    {
        pictUrilocation = strstr(pictUri, widget_pictogram_image_table[count].pictoURL);
        if ((pictUrilocation != NULL) &&
            (msf_cmmn_strcmp_nc(pictUrilocation, widget_pictogram_image_table[count].pictoURL) == 0))
        {
            return widget_pictogram_image_table[count].picto_img_id;
        }
        count++;
    }
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
    return 0;
}
#endif /*  __MMI_WAP_CORE_PICTOGRAM_SUPPORT__ */
/*****************************************************************************
 * FUNCTION
 *  widget_image_format_to_extension
 * DESCRIPTION
 *  
 * PARAMETERS
 *  format      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static const char *widget_image_format_to_extension(MsfImageFormat format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    const widget_image_typeinfo_struct *item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < WIDGET_IMAGE_TYPEINFO_NUM; i++)
    {
        item = &widget_image_typeinfo_table[i];
        if (item->format == format)
        {
            return item->fn_ext;
        }
    }
    /* WAP_DBG_ASSERT(0); */
    return ".gif";  /* It should not return NULL. Whatever! */
}


/****************************************************************
 * Rawfile manager
 ***************************************************************/

#define RAWFILE_FILE_IS_CREATED(item)  ((item)->size > 0)
#define RAWFILE_FILE_IS_EMPTY(item)    ((item)->size == 0)
#define RAWFILE_FILE_IS_BROKEN(item)   ((item)->size < 0)
#define RAWFILE_FILE_SIZE(item)        (((item)->size > 0) ? (item)->size : 0)
#define RAWFILE_FILENAME_IS_VALID(item) (strlen((item)->filename) > 0)

#define RAWFILE_GET_SLOT(file_id)   (WRAW_CTX->ptrs[(file_id)-1])
#define RAWFILE_VALID_FILE_ID(file_id) ((file_id) >= 1 && (file_id) <= MAX_WIDGET_CREATED_RAWFILE_SUM && \
                           (RAWFILE_GET_SLOT(file_id) != NULL) && RAWFILE_GET_SLOT(file_id)->handle != 0)

#define RAWFILE_FAILSAFE         (1)


/*****************************************************************************
 * FUNCTION
 *  widget_init_rawfile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_init_rawfile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, WIDGET_INIT_RAWFILE);
    WRAW_CTX->enabled = KAL_FALSE;

    /* Reset global data */
    memset(WRAW_CTX->ptrs, 0, sizeof(WRAW_CTX->ptrs));

    WRAW_CTX->total_size = 0;
#ifdef WAP_USE_ASM
    WRAW_CTX->working_buffer = widget_internal_mem_alloc(MSF_MODID_WIDGET, WIDGET_LOAD_BUFFER_SIZE);
#else
    WRAW_CTX->working_buffer = MSF_MEM_ALLOC(MSF_MODID_WIDGET, WIDGET_LOAD_BUFFER_SIZE);
#endif

    /* Always try to create the directory because SweepDrive() may delete the folder */
    MSF_FILE_MKDIR(WIDGET_RAWFILE_DIRECTORY );
#ifndef MMS_IN_LARGE_STORAGE
    MSF_FILE_MKDIR(WIDGET_RAWFILE_MMS_DIRECTORY );
#endif 

    /* Remove old files */
    msm_remove_files_under_dir(WIDGET_RAWFILE_DIRECTORY);
#ifndef MMS_IN_LARGE_STORAGE
    msm_remove_files_under_dir(WIDGET_RAWFILE_MMS_DIRECTORY);
#endif 

    WRAW_CTX->enabled = KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_deinit_rawfile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_deinit_rawfile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, WIDGET_DEINIT_RAWFILE);
#ifdef WAP_USE_ASM
    widget_internal_mem_free(MSF_MODID_WIDGET, WRAW_CTX->working_buffer);
#else
    MSF_MEM_FREE(MSF_MODID_WIDGET, WRAW_CTX->working_buffer);
#endif
    WRAW_CTX->working_buffer = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  widget_rawfile_allow_to_create_image
 * DESCRIPTION
 *  Do we need to use rawfile cache
 * PARAMETERS
 *  image_format        [IN]        (deprecated parameter)
 *  size                [IN]        (deprecated parameter)
 * RETURNS
 *  Whether we can cache image data in filesystem
 *****************************************************************************/
kal_bool widget_rawfile_allow_to_create_image(MsfImageFormat image_format, int size)
{
#if defined(__FS_QM_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Because the disk support Quota management, assume that disk full is allowed */
    int free_space;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, WIDGET_RAWFILE_ALLOW_TO_CREATE_IMAGE);
    free_space = FS_QmGetFree((BYTE*) "Z:\\@wcache\\");
    if (WRAW_CTX->enabled &&
        (free_space < 0 /* quota not configured */  || free_space >= WIDGET_RAWFILE_RESERVE_SPACE_MIN))
#else /* defined(__FS_QM_SUPPORT__) */ 
    /* No protection at all. Deprecated */
    if (WRAW_CTX->enabled && msm_get_disk_free_space(0) > WIDGET_RAWFILE_FREE_SPACE_WATERMARK)
#endif /* defined(__FS_QM_SUPPORT__) */ 
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_1);
        return KAL_TRUE;
    }
    else
    {
        /* System has troubles */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_rawfile_allow_to_create_sound
 * DESCRIPTION
 *  Do we need to use rawfile cache
 * PARAMETERS
 *  void
 * RETURNS
 *  Whether we can cache sound data in filesystem
 *****************************************************************************/
kal_bool widget_rawfile_allow_to_create_sound(void)
{
#if defined(__FS_QM_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Because the disk support Quota management, assume that disk full is allowed */
    int free_space;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, WIDGET_RAWFILE_ALLOW_TO_CREATE_SOUND);
    free_space = FS_QmGetFree((BYTE*) "Z:\\@wcache\\");
    if (WRAW_CTX->enabled &&
        (free_space < 0 /* quota not configured */  || free_space >= WIDGET_RAWFILE_RESERVE_SPACE_MIN))
#else /* defined(__FS_QM_SUPPORT__) */ 
    /* No protection at all. Deprecated */
    if (WRAW_CTX->enabled && msm_get_disk_free_space(0) > WIDGET_RAWFILE_FREE_SPACE_WATERMARK)
#endif /* defined(__FS_QM_SUPPORT__) */ 
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_1);
        return KAL_TRUE;
    }
    else
    {
        /* System has troubles */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
        return KAL_FALSE;
    }
}


#if 0 /* not in use */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef Q03C_IND_MOD_ARCH_SUPPORT
/* under construction !*/
#else
/* under construction !*/
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */

/*****************************************************************************
 * FUNCTION
 *  widget_is_rawfile_full
 * DESCRIPTION
 *  Check if there is enough resource for rawfile mechanism
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool widget_is_rawfile_full()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_WIDGET_CREATED_RAWFILE_SUM; i++)
    {
        if (!WRAW_CTX->ptrs[i])
        {
            return KAL_FALSE;
        }
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_rawfile_register
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int16 widget_rawfile_register(MSF_UINT32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 i = 0;
    widget_rawfile_item_struct *item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(IS_IMAGE_TYPE(handle) || IS_SOUND_TYPE(handle));
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_RAWFILE_REGISTER);
    for (i = 0; i < MAX_WIDGET_CREATED_RAWFILE_SUM; i++)
    {
        if (!WRAW_CTX->ptrs[i])
        {
            item = WRAW_CTX->ptrs[i] = (widget_rawfile_item_struct*)
#ifdef WAP_USE_ASM
                widget_internal_mem_alloc(MSF_MODID_BRS, sizeof(widget_rawfile_item_struct));
#else
                MSF_MEM_ALLOC(MSF_MODID_WIDGET, sizeof(widget_rawfile_item_struct));
#endif

            memset(item, 0, sizeof(widget_rawfile_item_struct));
            item->handle = handle;
            item->size = 0;
            item->format = MsfUnsupportedMediaType;
            {
                /* common case for browser */
                sprintf(item->filename, "%s%02d", WIDGET_RAWFILE_DIRECTORY, i + 1);
            }
        #ifdef RAWFILE_FAILSAFE
            WAP_DBG_ASSERT(MSF_FILE_GETSIZE(item->filename) < 0);       /* File not existed */
            MSF_FILE_REMOVE(item->filename );    /* failsafe */
        #endif /* RAWFILE_FAILSAFE */ 
            return i + 1;
        }
    }

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
    /* No empty slots. Restart mobile suite. */
    return 0;   /* UNREACHED */
}


/*****************************************************************************
 * FUNCTION
 *  widget_rawfile_deregister
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_id     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_rawfile_deregister(kal_int16 file_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_rawfile_item_struct *item = RAWFILE_GET_SLOT(file_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(RAWFILE_VALID_FILE_ID(file_id));
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_RAWFILE_DEREGISTER);
    if (RAWFILE_FILE_IS_CREATED(item))
    {
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */
        {
            /* remove the wcache file */
            MSF_FILE_REMOVE(item->filename );
            WRAW_CTX->total_size -= item->size;
        }
    }

#ifdef WAP_USE_ASM
    widget_internal_mem_free(MSF_MODID_BRS, item);
#else
    MSF_MEM_FREE(MSF_MODID_WIDGET, item);
#endif
    RAWFILE_GET_SLOT(file_id) = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  widget_rawfile_getname
 * DESCRIPTION
 *  Return a name only if the file is created and not empty
 * PARAMETERS
 *  file_id     [IN]        
 * RETURNS
 *  ASCII filename
 *  It might return NULL.
 *****************************************************************************/
char *widget_rawfile_getname(kal_int16 file_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_rawfile_item_struct *item = RAWFILE_GET_SLOT(file_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_RAWFILE_GETNAME);
    if (!RAWFILE_VALID_FILE_ID(file_id))
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_ERROR_INVALID_FILE);
        return NULL;
    }

    if (!RAWFILE_FILENAME_IS_VALID(item))
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_ERROR_INVALID_FILE);
        return NULL;
    }

    if (!RAWFILE_FILE_IS_CREATED(item))
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
        return NULL;    /* Invalid/Empty image */
    }

    return item->filename;
}


/*****************************************************************************
 * FUNCTION
 *  widget_rawfile_getsize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_id     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int widget_rawfile_getsize(kal_int16 file_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_rawfile_item_struct *item = RAWFILE_GET_SLOT(file_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_RAWFILE_GETSIZE);
    if (RAWFILE_VALID_FILE_ID(file_id))
    {
        return RAWFILE_FILE_SIZE(item);
    }
    else
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_rawfile_write_failed
 * DESCRIPTION
 *  write the rawfile failed. The reason should be the space is not enough
 * PARAMETERS
 *  file_id     [IN]        
 * RETURNS
 *  return KAL_TRUE if the rawfile is broken
 *****************************************************************************/
kal_bool widget_rawfile_write_failed(kal_int16 file_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_rawfile_item_struct *item = RAWFILE_GET_SLOT(file_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, WIDGET_RAWFILE_WRITE_FAILED);
    if (RAWFILE_VALID_FILE_ID(file_id))
    {
        if (RAWFILE_FILE_IS_BROKEN(item))
        {
            return KAL_TRUE;
        }
        else
        {
            return KAL_FALSE;
        }
    }
    else
    {
        return KAL_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_rawfile_write
 * DESCRIPTION
 *  
 *  NOTE: It is blocking I/O, and it may let the system less responsive
 * PARAMETERS
 *  file_id     [IN]        
 *  data        [IN]        
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
// TODO: Maybe we can cache the open file handle to improve performance?

void widget_rawfile_write(kal_int16 file_id, const char *data, int size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int fd;
    int tmpsize = 0;    /* for debug */
    widget_rawfile_item_struct *item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, WIDGET_RAWFILE_WRITE);
    if (file_id == 0)   /* When rawfile table is full. */
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_FULL);
        return;
    }

    item = RAWFILE_GET_SLOT(file_id);
    ASSERT(RAWFILE_VALID_FILE_ID(file_id));

    if (RAWFILE_FILE_IS_BROKEN(item))
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_BROKEN);
        return;
    }
    if (size <= 0)
    {
        /* It is possible that size == 0 */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_SIZE);
        return;
    }

    WAP_DBG_ASSERT(RAWFILE_FILENAME_IS_VALID(item));

    fd = MSF_FILE_OPEN(
            MSF_MODID_WIDGET,
            item->filename,
            HDI_FILE_SET_WRONLY | HDI_FILE_SET_CREATE | HDI_FILE_SET_APPEND | HDI_FILE_SET_CUSTOM_BLOCKING,
            0);
    if (fd < 0 || (tmpsize = MSF_FILE_WRITE(fd, (void*)data, size)) < size)
    {
        /* We should not allow this to happen */
        WIDGET_UNUSED(tmpsize);
        if (fd >= 0)
        {
            MSF_FILE_CLOSE(fd);
        }
        MSF_FILE_REMOVE(item->filename );
        WRAW_CTX->total_size -= item->size;

        if (tmpsize < 0)
        {
            item->size = tmpsize;   /* Mark the image as invalid */
        }
        else
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_FULL);
            item->size = HDI_FILE_ERROR_FULL;   /* -6 : Mark the image as invalid */
        }
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN);
        return;
    }

    MSF_FILE_CLOSE(fd);
    item->size += size;
    WRAW_CTX->total_size += size;

}


/*****************************************************************************
 * FUNCTION
 *  widget_rawfile_configure_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_id         [IN]        
 *  format          [IN]        
 *  file_ext        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_rawfile_configure_format(kal_int16 file_id, int format, const char *file_ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_rawfile_item_struct *item;
    char old_filename[WIDGET_RAWFILE_NAMELEN + 1];
    char *c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_RAWFILE_CONFIGURE_FORMAT);
    if (!RAWFILE_VALID_FILE_ID(file_id))
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_ERROR_INVALID_FILE);
        return;
    }

    item = RAWFILE_GET_SLOT(file_id);

    item->format = (kal_int16) format;

    strcpy(old_filename, item->filename);
    if ((c = strrchr(item->filename, '.')) == NULL)
    {
        c = strrchr(item->filename, '\0');
    }
    ASSERT(c);
    strcpy(c, file_ext);

    ASSERT(strlen(item->filename) <= WIDGET_RAWFILE_NAMELEN);

#if 0
/* under construction !*/
#else
    if (RAWFILE_FILE_IS_CREATED(item))
#endif
    {
        /* If it's already created and isn't the virtual file. Rename it. */
    #ifdef RAWFILE_FAILSAFE
        MSF_FILE_REMOVE(item->filename);    /* failsafe */
    #endif 
        MSF_FILE_RENAME(old_filename, item->filename );
    }
}

/****************************************************************
 * Stub functions to adapt IMAGE_TYPE (in memory/file) & PRE_IMAGE_TYPE (in flash)
 ***************************************************************/

#ifdef WIDGET_COMPACT_PRE_IMAGE


/*****************************************************************************
 * FUNCTION
 *  widget_get_pre_image_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pimg        [IN]     
 *  data        [OUT]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool widget_get_pre_image_data(widget_pre_image_struct *pimg, widget_pre_image_result_data *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_image_id resId;
    S32 width, height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GET_PREIMAGE_DATA);
    if (!pimg || pimg < widget_predefined_image_table)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
        return KAL_FALSE;
    }

    resId = (pimg - widget_predefined_image_table) + WAP_IMAGE_ID_BEGIN;

    if (resId >= WAP_IMAGE_ID_END)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_FULL);
        return KAL_FALSE;
    }

#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
    /* In ENFB case, because we may reload image resource dynamically, We need to re-get image data again. */
    if (resId == WIMG_CTX->pre_image_cache_id)
    {
        memcpy(data, &WIMG_CTX->pre_image_cache_data, sizeof(widget_pre_image_result_data));
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_1);
        return KAL_TRUE;
    }
#endif

    data->src = (kal_uint8*)get_image(resId);
    data->length = gdi_image_get_buf_len_from_id(resId); /* doesn't include the header size */
    /* detect image format */
    switch (gdi_image_get_type_from_id(resId))
    {
        case IMAGE_TYPE_BMP:
        case IMAGE_TYPE_AB2:
            /* FALLTHROUGH no break */
        case IMAGE_TYPE_BMP_SEQUENCE:   /* BMP */
            data->image_format = MsfBmpPI;
            break;
        case IMAGE_TYPE_GIF:            /* GIF */
            data->image_format = MsfGifPI;
            break;
        case IMAGE_TYPE_DEVICE_BITMAP:
            /* FALLTHROUGH no break */
        case IMAGE_TYPE_DEVICE_BITMAP_SEQUENCE:
            data->image_format = (MsfImageFormat) MsfPbmPI;
            break;
        case IMAGE_TYPE_JPG:
            data->image_format = MsfJpegPI;
            break;
        case IMAGE_TYPE_PNG:
            data->image_format = MsfPngPI;
            break;
        case GDI_IMAGE_TYPE_ABM:
        case GDI_IMAGE_TYPE_ABM_SEQUENCE:
            data->image_format = (MsfImageFormat) MsfAbmPI;
            break;
        default:
            data->image_format = (MsfImageFormat) MsfUnsupportedMediaType;
            break;
    }
    gdi_image_get_dimension_id(resId, &width, &height);

    data->size.width = width;
    data->size.height = height;

    /* Cache result */
    WIMG_CTX->pre_image_cache_id = resId;
    memcpy(&WIMG_CTX->pre_image_cache_data, data, sizeof(widget_pre_image_result_data));
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_1);
    return KAL_TRUE;
}

#endif /* WIDGET_COMPACT_PRE_IMAGE */ 


/*****************************************************************************
 * FUNCTION
 *  widget_image_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfImageFormat widget_image_format(MsfImageHandle image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_IMAGE_FORMAT);
    if (IS_IMAGE_TYPE(image))
    {
        return _IMG(image)->image_format;
    }
    else if (IS_PRE_IMAGE_TYPE(image))
    {
    #ifdef WIDGET_COMPACT_PRE_IMAGE
        widget_pre_image_result_data res;

        if (widget_get_pre_image_data(_PIMG(image), &res))
        {
            return res.image_format;
        }
        else
        {
            return (MsfImageFormat) MsfUnsupportedMediaType;
        }
    #else /* WIDGET_COMPACT_PRE_IMAGE */ 
        return _PIMG(image)->image_format;
    #endif /* WIDGET_COMPACT_PRE_IMAGE */ 
    }
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_ERROR);
    return (MsfImageFormat) MsfUnsupportedMediaType;
}

/* Used internally to determine if we can display this image */


/*****************************************************************************
 * FUNCTION
 *  widget_image_is_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool widget_image_is_ready(MsfImageHandle image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_IS_IMAGE_READY);
    if (IS_IMAGE_TYPE(image))
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN);
        return _IMG(image)->is_done ? KAL_TRUE : KAL_FALSE;
    }
    else if (IS_PRE_IMAGE_TYPE(image))
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_1);
        return KAL_TRUE;
    }
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  widget_image_resid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int widget_image_resid(MsfImageHandle image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_IMAGE_RESID);
    if (!image)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
        return 0;
    }
    else if (IS_PRE_IMAGE_TYPE(image))
    {
    #ifdef WIDGET_COMPACT_PRE_IMAGE
        MSF_UINT32 resId;
        widget_pre_image_struct *pimg = _PIMG(image);

        if (pimg < widget_predefined_image_table)
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
            return 0;
        }
        resId = (pimg - widget_predefined_image_table) + WAP_IMAGE_ID_BEGIN;
        if (resId >= WAP_IMAGE_ID_END)
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
            return 0;
        }
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_1);
        return resId;
    #else /* WIDGET_COMPACT_PRE_IMAGE */ 
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_1);
        return _PIMG(image)->resource_id;
    #endif /* WIDGET_COMPACT_PRE_IMAGE */ 
    }
    else
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_image_width
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int widget_image_width(MsfImageHandle image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_IMAGE_WIDTH);
    if (IS_IMAGE_TYPE(image))
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_VALUE, (int)_IMG(image)->size.width);
        return _IMG(image)->size.width;
    }
    else if (IS_PRE_IMAGE_TYPE(image))
    {
    #ifdef WIDGET_COMPACT_PRE_IMAGE
        widget_pre_image_result_data res;

        if (widget_get_pre_image_data(_PIMG(image), &res))
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_VALUE, (int)res.size.width);
            return res.size.width;
        }
        else
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
            return 0;
        }
    #else /* WIDGET_COMPACT_PRE_IMAGE */ 
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_VALUE, (int)_PIMG(image)->size.width);
        return _PIMG(image)->size.width;
    #endif /* WIDGET_COMPACT_PRE_IMAGE */ 
    }
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  widget_image_height
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int widget_image_height(MsfImageHandle image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_IMAGE_HEIGHT);
    if (IS_IMAGE_TYPE(image))
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_VALUE, (int)_IMG(image)->size.height);
        return _IMG(image)->size.height;
    }
    else if (IS_PRE_IMAGE_TYPE(image))
    {
    #ifdef WIDGET_COMPACT_PRE_IMAGE
        widget_pre_image_result_data res;

        if (widget_get_pre_image_data(_PIMG(image), &res))
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_VALUE, (int)res.size.height);
            return res.size.height;
        }
        else
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
            return 0;
        }
    #else /* WIDGET_COMPACT_PRE_IMAGE */ 
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_VALUE, (int)_PIMG(image)->size.height);
        return _PIMG(image)->size.height;
    #endif /* WIDGET_COMPACT_PRE_IMAGE */ 
    }
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  widget_image_content
 * DESCRIPTION
 *  Return the image content in memory (typically used with widget_image_content_file)
 * PARAMETERS
 *  image       [IN]        The image handle
 * RETURNS
 *  The image content stored in memory
 *  NOTE: It might return NULL if
 *  1. The image does not have content
 *  2. Its content is stored in file.
 *****************************************************************************/
kal_uint8 *widget_image_content(MsfImageHandle image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_IMAGE_CONTENT);
    if (IS_IMAGE_TYPE(image))
    {
        if (_IMG(image)->raw)
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN);
            return _IMG(image)->raw->data;
        }
        else
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
            return NULL;
        }
    }
    else if (IS_PRE_IMAGE_TYPE(image))
    {
    #ifdef WIDGET_COMPACT_PRE_IMAGE
        widget_pre_image_result_data res;

        if (widget_get_pre_image_data(_PIMG(image), &res))
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN);
            return res.src;
        }
        else
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
            return NULL;
        }
    #else /* WIDGET_COMPACT_PRE_IMAGE */ 
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN);
        return _PIMG(image)->src;
    #endif /* WIDGET_COMPACT_PRE_IMAGE */ 
    }
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  widget_image_dimension
 * DESCRIPTION
 *  Return the image dimension
 *  (Initialized after widget_initialize_image_dimension
 * PARAMETERS
 *  image       [IN]        The image handle
 * RETURNS
 *  
 *****************************************************************************/
MsfSize *widget_image_dimension(MsfImageHandle image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Note: Non-reentrant */
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_IMAGE_DIMENSION);
    if (IS_IMAGE_TYPE(image))
    {
        return &(_IMG(image)->size);
    }
    else if (IS_PRE_IMAGE_TYPE(image))
    {
    #ifdef WIDGET_COMPACT_PRE_IMAGE
        /* Static data in case caller might modify returned structure unexpectedly */
        static MsfSize dummy_size;
        widget_pre_image_result_data res;

        if (widget_get_pre_image_data(_PIMG(image), &res))
        {
            dummy_size = res.size;
        }
        else
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_ERROR);
            dummy_size.height = 0;
            dummy_size.width = 0;
        }
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN);
        return &dummy_size;
    #else /* WIDGET_COMPACT_PRE_IMAGE */ 
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN);
        return &(_PIMG(image)->size);
    #endif /* WIDGET_COMPACT_PRE_IMAGE */ 
    }
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  widget_image_content_file
 * DESCRIPTION
 *  Return the filename that contain the content of an image
 * PARAMETERS
 *  image       [IN]        The image handle
 * RETURNS
 *  A file name or NULL
 *****************************************************************************/
char *widget_image_content_file(MsfImageHandle image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_IMAGE_CONTENT_FILE);
    if (IS_IMAGE_TYPE(image))
    {
        if (_IMG(image)->rawfile_id)
        {
            /* It might still return NULL */
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN);
            return widget_rawfile_getname(_IMG(image)->rawfile_id);
        }
        else
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
            return NULL;
        }
    }
    else if (IS_PRE_IMAGE_TYPE(image))
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
        return NULL;
    }
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtGetImageContentFile
 * DESCRIPTION
 *  Return the filename that contain the content of an MsfImageHandle
 *  export the API to other MSF modules
 * PARAMETERS
 *  image       [IN]        The image handle
 * RETURNS
 *  A file name or NULL
 *****************************************************************************/
const char* HDIa_widgetExtGetImageContentFile(MsfImageHandle image)
{
    return widget_image_content_file(image);
}


/*****************************************************************************
 * FUNCTION
 *  widget_image_length
 * DESCRIPTION
 *  Return the length of image content
 *  The user should make sure widget_image_is_ready() == TRUE
 * PARAMETERS
 *  image       [IN]        The image handle
 * RETURNS
 *  length
 *****************************************************************************/
int widget_image_length(MsfImageHandle image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_IMAGE_LENGTH);
    if (IS_IMAGE_TYPE(image))
    {
        if (_IMG(image)->raw)
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN);
            return _IMG(image)->raw->size;
        }
        else if (_IMG(image)->rawfile_id)
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN);
            return widget_rawfile_getsize(_IMG(image)->rawfile_id);
        }
        else
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
            return 0;
        }
    }
    else if (IS_PRE_IMAGE_TYPE(image))
    {
    #ifdef WIDGET_COMPACT_PRE_IMAGE
        widget_pre_image_result_data res;

        if (widget_get_pre_image_data(_PIMG(image), &res))
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN);
            return res.length;
        }
        else
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
            return 0;
        }
    #else /* WIDGET_COMPACT_PRE_IMAGE */ 
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN);
        return _PIMG(image)->length;
    #endif /* WIDGET_COMPACT_PRE_IMAGE */ 
    }
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  widget_image_frame_count
 * DESCRIPTION
 *  Return the frame count of GIF image or 0 for other image types
 *  The user should make sure widget_image_is_ready() == TRUE
 * PARAMETERS
 *  image       [IN]        The image handle
 * RETURNS
 *  
 *****************************************************************************/
int widget_image_frame_count(MsfImageHandle image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_IMAGE_FRAME_COUNT);
    if (IS_IMAGE_TYPE(image))
    {
        WAP_DBG_ASSERT(_IMG(image)->GIF_frames_initialized);
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN);
        return _IMG(image)->GIF_frames;
    }
    else if (IS_PRE_IMAGE_TYPE(image))
    {
        /* We neither use nor support it, although it should be supported for consistency */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
        return 0;
    }

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
    return 0;

}


/*****************************************************************************
 * FUNCTION
 *  widget_image_check_format
 * DESCRIPTION
 *  check the image format. Used inside widget_image_set_done().
 * PARAMETERS
 *  img     [IN]        Img->image_format is modified
 * RETURNS
 *  kal_bool
 *****************************************************************************/
static kal_bool widget_image_check_format(widget_image_struct *img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 gdi_type = GDI_IMAGE_TYPE_INVALID;
    int image_format = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_IMAGE_CHECK_FORMAT);
    if (img->rawfile_id)
    {
        S8 *full_name;
        char *rawfile_name = widget_image_content_file((MsfImageHandle) img);

        if (!rawfile_name)
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
            return KAL_FALSE;
        }

        full_name = (S8*) HDI_FileNameTranslate(rawfile_name);

        gdi_type = gdi_image_get_type_from_file(full_name);

        HDI_FileNameFree((kal_uint8*) full_name);
    }
    else
    {
        /* Currently, we do not use img->raw in normal case */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
        return KAL_FALSE;
    }

    switch (gdi_type)
    {
        case GDI_IMAGE_TYPE_BMP:
        case GDI_IMAGE_TYPE_BMP_FILE:
            image_format = MsfBmp;
            break;

        case GDI_IMAGE_TYPE_GIF:
        case GDI_IMAGE_TYPE_GIF_FILE:
            image_format = MsfGif;
            break;

        case GDI_IMAGE_TYPE_WBMP:
        case GDI_IMAGE_TYPE_WBMP_FILE:
            image_format = MsfWbmp;
            break;

        case GDI_IMAGE_TYPE_JPG:
        case GDI_IMAGE_TYPE_JPG_FILE:
            image_format = MsfJpeg;
            break;

        case GDI_IMAGE_TYPE_PNG:
        case GDI_IMAGE_TYPE_PNG_FILE:
            image_format = MsfPng;
            break;

        default:
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_DEFAULT_CASE);
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
            return KAL_FALSE;
    }

    if (img->image_format == image_format)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_1);
        return KAL_TRUE;
    }
    else
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_image_auto_detect_format
 * DESCRIPTION
 *  Auto-decide the image format. Used inside widget_image_set_done().
 * PARAMETERS
 *  img     [IN]        Img->image_format is modified
 * RETURNS
 *  kal_bool
 *****************************************************************************/
static kal_bool widget_image_auto_detect_format(widget_image_struct *img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 gdi_type = GDI_IMAGE_TYPE_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_IMAGE_AUTO_DETECT_FORMAT);
    if (img->rawfile_id)
    {
        S8 *full_name;
        char *rawfile_name = widget_image_content_file((MsfImageHandle) img);

        if (!rawfile_name)
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
            return KAL_FALSE;
        }

        full_name = (S8*) HDI_FileNameTranslate(rawfile_name);

        gdi_type = gdi_image_get_type_from_file(full_name);

        HDI_FileNameFree((kal_uint8*) full_name);
    }
    else
    {
        /* Currently, we do not use img->raw in normal case */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
        return KAL_FALSE;
    }

    switch (gdi_type)
    {
        case GDI_IMAGE_TYPE_BMP:
        case GDI_IMAGE_TYPE_BMP_FILE:
            img->image_format = MsfBmp;
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_1);
            return KAL_TRUE;

        case GDI_IMAGE_TYPE_GIF:
        case GDI_IMAGE_TYPE_GIF_FILE:
            img->image_format = MsfGif;
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_1);
            return KAL_TRUE;

        case GDI_IMAGE_TYPE_WBMP:
        case GDI_IMAGE_TYPE_WBMP_FILE:
            img->image_format = MsfWbmp;
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_1);
            return KAL_TRUE;

        case GDI_IMAGE_TYPE_JPG:
        case GDI_IMAGE_TYPE_JPG_FILE:
            img->image_format = MsfJpeg;
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_1);
            return KAL_TRUE;

        case GDI_IMAGE_TYPE_PNG:
        case GDI_IMAGE_TYPE_PNG_FILE:
            img->image_format = MsfPng;
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_1);
            return KAL_TRUE;

        default:
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_DEFAULT_CASE);
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
            return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_image_set_done
 * DESCRIPTION
 *  Set the image ready (all data is read). Then we can draw it
 * PARAMETERS
 *  img     [IN]        
 * RETURNS
 *  1 - the image is valid
 *  0 - the image is invalid (can't get the image resolution)
 *  -1 - The image is larger the limitation (WIDGET_IMAGE_MAX_WIDTH, WIDGET_IMAGE_MAX_HEIGHT)
 *  -2 - gdi draw image failed (resource is not enough)
 *****************************************************************************/
static int widget_image_set_done(widget_image_struct *img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* [is_valid_dimension]
     * 1: get dimension succeed
     * 0: can't get dimension;
     * -1: dimension is too large;
     * -2: file is corrupted;
     */
    kal_int32 is_valid_dimension = 0;

    char *rawfile_name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_IMAGE_SET_DONE);
    if (img->rawfile_id)
    {
        widget_rawfile_configure_format(
            img->rawfile_id,
            img->image_format,
            widget_image_format_to_extension(img->image_format));
    }
    is_valid_dimension = widget_initialize_image_dimension((MsfImageHandle) img);
    if (!widget_image_check_format(img))
    {
        MsfImageFormat old_format;

        old_format = img->image_format;
        if (widget_image_auto_detect_format(img) && img->image_format != old_format)
        {
            if (img->rawfile_id)
            {
                widget_rawfile_configure_format(
                    img->rawfile_id,
                    img->image_format,
                    widget_image_format_to_extension(img->image_format));
            }
            is_valid_dimension = widget_initialize_image_dimension((MsfImageHandle) img);
        }
    }
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_IMAGE_IS_VALID_DIMENSION, (int)is_valid_dimension);
    if (is_valid_dimension > 0)
    {
        /* The image dimension should be larger than zero */
        rawfile_name = widget_image_content_file((MsfImageHandle) img);
        if (rawfile_name)
        {
            /* image file */
            S8 *error_str_ptr = NULL;
            S8 *full_name = (S8*) HDI_FileNameTranslate(rawfile_name);

            /* We don't use FMGR_LIMIT_IMAGE_VIEWER to check the image limitation 
             * because unified composer has its config "FMGR_LIMIT_MMS_CATEGORY".
             */
			#ifndef __COSMOS_MMI_PACKAGE__
            if( mmi_fmgr_util_file_limit_check(FMGR_LIMIT_MMS_CATEGORY, (S8*)full_name, &error_str_ptr) == FALSE)
            {
                /* -1: dimension is too large; */
                is_valid_dimension = -1;
                img->size.width = img->size.height = 0;
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_IMAGE_FMGR_CHECK);
            }
			#endif
            HDI_FileNameFree((kal_uint8*) full_name);
        }
    }

    /* reset gdi cache */
    gdi_image_gif_reset();

    img->GIF_frames = 0;    /* Delay initialization until execution in MMI task */
    img->GIF_frames_initialized = 0;
    img->is_done = KAL_TRUE;

    if (is_valid_dimension > 0)
    {
    #ifdef WIDGET_CHECK_IMAGE_IN_DETAIL
        kal_bool ret = KAL_FALSE;
        
        ret = widget_check_image_in_detail((MsfImageHandle) img);
        /* reset gdi cache */
        gdi_image_gif_reset();
        
        if (ret == KAL_FALSE)
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_IMAGE_SET_DONE_RETURNS, -2);
            return -2;   /* gdi draw image failed (no resource) */
        }
        else
    #endif
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_IMAGE_SET_DONE_RETURNS, 1);
            return 1;   /* The image is vaild */
        }

    }
    else
    {
        /* [is_valid_dimension]
         * 0: can't get dimension;
         * -1: dimension is too large;
         * -2: file is corrupted;
         */
        if (is_valid_dimension == -1)
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_IMAGE_SET_DONE_RETURNS, -1);
            return -1;  /* The image is larger the limitation */
        }
        else
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_IMAGE_SET_DONE_RETURNS, 0);
            return 0;   /* The image is invalid */
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_image_release
 * DESCRIPTION
 *  Release image-specific data.
 * PARAMETERS
 *  img     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_image_release(widget_image_struct *img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Prevent race condition: animation timer expire after data is deallocated */
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_IMAGE_RELEASE, (U32)img);

#ifdef WIDGET_ANIMATED_GIF_SUPPORT
    widget_stop_animate_by_image((MsfImageHandle) img);
#endif /* WIDGET_ANIMATED_GIF_SUPPORT */

    if (img == widget_image_raw_file_list.img)
    {
        
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_IN_CHECK1);
        widget_stop_timer(WIDGET_RAW_FILE_IMAGE_CHECK_TIMER);
        if (widget_image_raw_file_list.f)
        {
           MSF_FILE_CLOSE(widget_image_raw_file_list.f);
        }
        memset(&widget_image_raw_file_list, 0, sizeof(widget_read_from_file_to_raw_file_item));
    }

    /* 
     * Release raw file and data after all decoding/animation are stopped
     * Raw data is released in other place
     */
    if (img->rawfile_id)
    {
            /* image */
            widget_rawfile_deregister(img->rawfile_id);
            img->rawfile_id = 0;
    }

    if (img->draw_op_head)
    {
#ifdef WAP_USE_ASM
        widget_draw_op_release(img->draw_op_head, img->module_id);
#else
        widget_draw_op_release(img->draw_op_head);
#endif
        img->draw_op_head = img->draw_op_tail = NULL;
    }

#ifdef WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
    widget_stop_image_nb_draw(img);
#endif

#ifdef WIDGET_PRECACHE_IMAGE
    widget_reset_precached_image_by_image(img);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  widget_output_image_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  img     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __MTK_TARGET__
/* 
 * for debug: it works with msf_file_w32.c, but not msf_file.c
 */
static void widget_output_image_file(widget_image_struct *img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_OUTPUT_IMAGE_FILE);
    if (img->is_done)
    {
        static int cnt = 0;
        char filename[128];

        switch (img->image_format)
        {
            case MsfBmp:
                sprintf(filename, "wap_%03d.bmp", cnt);
                break;
            case MsfPictogram:
                sprintf(filename, "wap_%03d.pic", cnt);
                break;
            case MsfGif:
                sprintf(filename, "wap_%03d.gif", cnt);
                break;
            case MsfJpeg:
                sprintf(filename, "wap_%03d.jpg", cnt);
                break;
            case MsfPng:
                sprintf(filename, "wap_%03d.png", cnt);
                break;
            case MsfWbmp:
                sprintf(filename, "wap_%03d.wbmp", cnt);
                break;
            case MsfPbmPI:
                sprintf(filename, "wap_%03d.pbm", cnt);
                break;
            default:
                ASSERT(0);
        }
        cnt++;
        {
            FILE *f = fopen(filename, "wb");

            if (widget_image_content((MsfImageHandle) img))     // TODO: handle widget_image_content_file
            {
                fwrite(widget_image_content((MsfImageHandle) img), widget_image_length((MsfImageHandle) img), 1, f);
            }
            fclose(f);
        }
    }
}
#endif /* __MTK_TARGET__ */ 

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetImageCreate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId               [IN]        
 *  imageData           [IN]        
 *  imageDataSize       [IN]        
 *  imageFormat         [IN]        
 *  moreData            [IN]        
 *  defaultStyle        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfImageHandle HDIa_widgetImageCreate(
                MSF_UINT8 modId,
                const char *imageData,
                int imageDataSize,
                MsfImageFormat imageFormat,
                int moreData,
                MsfStyleHandle defaultStyle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_image_struct *img = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* setting the image widget */
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_HDIA_WIDGET_IMAGECREATE);
    img = widget_create_image(modId);
    img->module_id = modId;
    img->image_format = imageFormat;
    widget_set_attrib(img, style, defaultStyle);

    HDIa_widgetImageNextPart((MsfImageHandle) img, (char*)imageData, imageDataSize, moreData);

    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_HDIA_WIDGET_IMAGECREATE_END);
    return (MsfImageHandle) img;
}

/* Either img->raw or img->rawfile_id must not be 0 */


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetImageNextPart
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image               [IN]        
 *  imageData           [OUT]         
 *  imageDataSize       [IN]        
 *  moreData            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetImageNextPart(MsfImageHandle image, char *imageData, int imageDataSize, int moreData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_image_struct *img;
    MSF_UINT8 modId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_HDIA_WIDGET_IMAGE_NEXT_PART);
    if (image == 0)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
        return 0;
    }

    WAP_DBG_ASSERT(IS_IMAGE_TYPE(image));
    img = _IMG(image);
    modId = img->module_id;

    if (img->raw == NULL && img->rawfile_id == 0)   /* Create new image */
    {
        if (!widget_rawfile_allow_to_create_image(_IMG(image)->image_format, imageDataSize))
        {
            /* Write image content in memory  */
            widget_raw_data_struct *raw;

            raw = widget_create_raw_data_ext(modId, imageDataSize);
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WRITE_CONTENT_IN_MEMORY);
            widget_set_raw_data(raw, imageData, imageDataSize);
            widget_set_attrib_ptr(img, raw, raw);
        }
        else
        {
            /* Write image content in file */
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WRITE_CONTENT_IN_FILE);
            img->rawfile_id = widget_rawfile_register((MsfImageHandle) img);
            if (img->rawfile_id)
            {
                widget_rawfile_write(img->rawfile_id, imageData, imageDataSize);
                if (widget_rawfile_write_failed(img->rawfile_id))
                {
                    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WRITE_CONTENT_IN_FILE_FAILED);
                    widget_send_notification_load_resource(img, MsfNotifyFailedFSFull);
                    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_ERROR);
                    return -1;
                }
            }
        }
    }
    else if (img->raw == NULL)  /*  Append rawfile_id */
    {
        /* img->rawfile_id must not be 0 */
        widget_rawfile_write(img->rawfile_id, imageData, imageDataSize);
        if (widget_rawfile_write_failed(img->rawfile_id))
        {
            widget_send_notification_load_resource(img, MsfNotifyFailedFSFull);
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_ERROR);
            return -1;
        }
    }
    else if (widget_rawfile_allow_to_create_image(_IMG(image)->image_format, _IMG(image)->raw->size + imageDataSize))
    {
        /* Free the original raw data, and append to file */
        WAP_DBG_ASSERT(img->rawfile_id == 0);
        img->rawfile_id = widget_rawfile_register((MsfImageHandle) img);
        if (img->rawfile_id)
        {
            widget_rawfile_write(img->rawfile_id, (char*)img->raw->data, img->raw->size);
            widget_rawfile_write(img->rawfile_id, imageData, imageDataSize);
            widget_set_attrib_ptr(img, raw, NULL);  /* delete orignal raw data */
            if (widget_rawfile_write_failed(img->rawfile_id))
            {
                widget_send_notification_load_resource(img, MsfNotifyFailedFSFull);
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_ERROR);
                return -1;
            }
        }
    }
    else
    {
        /* Append raw data */
        widget_raw_data_struct *raw;

        raw = widget_create_raw_data_ext(img->module_id, img->raw->size + imageDataSize);
        memcpy(raw->data, img->raw->data, img->raw->size);
        memcpy(raw->data + img->raw->size, imageData, imageDataSize);
        widget_set_attrib_ptr(img, raw, raw);
    }

    if (!moreData)
    {
        int ret = widget_image_set_done(img);

        if (ret > 0)
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_1);
            return 1;
        }
        else
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_MINUS1);
            return -1;
        }
    }
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_1);
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_HDIA_WIDGET_IMAGE_NEXT_PART_END);
    return 1;
}

#if 0   /* NOT FULLY IMPLEMENTED */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  widget_send_notification_load_resource
 * DESCRIPTION
 *  It is only for MsfImage widgets that are created using a resource
 * PARAMETERS
 *  img         [IN]        The image
 *  state       [IN]        Success or failure
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_send_notification_load_resource(widget_image_struct *img, /* kal_bool */ int state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_SEND_NOTIFICATION_LOAD_RESOURCE, state);
    {
        if (state == MsfNotifyResourceReady)
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_SEND_NOTIFICATION_LOAD_RESOURCE_LOADED);
            HDIc_widgetNotify(img->module_id, (MSF_UINT32) img, MsfNotifyResourceLoaded);
        }
        else
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_SEND_NOTIFICATION_LOAD_RESOURCE_FAILED);
            HDIc_widgetNotify(img->module_id, (MSF_UINT32) img, MsfNotifyResourceFailed);
        }
    }

    widget_send_update_event_to_wap();
}


/*****************************************************************************
 * FUNCTION
 *  widget_create_image_resource
 * DESCRIPTION
 *  Check and create the image resource (WAP task)
 *  Whether the image resource is created ready or not, we will send notification
 *  to MSF Module.
 * PARAMETERS
 *  img     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void widget_create_image_resource(widget_image_struct *img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_CREATE_IMAGE_RESOURCE);
    flag = widget_image_set_done(img);
    /*
     * the return value of widget_image_set_done():
     *  1 - the image is valid
     *  0 - the image is invalid (can't get the image resolution)
     *  -1 - The image is larger the limitation (WIDGET_IMAGE_MAX_WIDTH, WIDGET_IMAGE_MAX_HEIGHT)
     *  -2 - gdi draw image failed (resource is not enough)
     */
    switch (flag)
    {
    case 1: /* 1 - the image is valid */
        widget_send_notification_load_resource(img, MsfNotifyResourceReady);
        break;
    case 0: /* 0 - the image is invalid (can't get the image resolution) */
        widget_send_notification_load_resource(img, MsfNotifyFailedCorrupt);
        break;
    case -1: /* -1 - The image is larger the limitation */
        widget_send_notification_load_resource(img, MsfNotifyFailedResolution);
        break;
    case -2: /* -2 - gdi draw image failed (resource is not enough) */
        widget_send_notification_load_resource(img, MsfNotifyFailedNoResource);
        break;
    default:
        widget_send_notification_load_resource(img, MsfNotifyResourceError);
    }
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_CREATE_IMAGE_RESOURCE_END);
}


/*****************************************************************************
 * FUNCTION
 *  widget_read_image_from_file_to_raw_data
 * DESCRIPTION
 *  Callback function of reading image data from file
 *  
 *  It will do these after the image is loaded: (but it doesn't close file)
 *  1. set "done" flag
 *  2. Recompute the dimension of the image
 *  3. Send MsfNotifyResourceLoaded, etc.
 *  
 *  Note: Modify widget_read_sound_from_file also if this function is changed.
 * PARAMETERS
 *  f                   [IN]            File handle
 *  size                [IN]            Expected file size ( > 0)
 *  img                 [IN/OUT]        The image
 *  need_add_select     [IN]            Whether to add into the map "widget_fn_*"
 *  is_DRM              [IN]            
 * RETURNS
 *  WIDGET_READ_ERROR
 *  WIDGET_WAIT_SELECT
 *  WIDGET_READ_FINISH
 *****************************************************************************/
static int widget_read_image_from_file_to_raw_data(
            int f,
            int size,
            widget_image_struct *img,
            kal_bool need_add_select,
            kal_bool is_DRM)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    long ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(img->raw != NULL);
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_READ_IMAGE_FROM_FILE_TO_RAW_DATA);
    while (img->raw->used_size < size)
    {
        /* read image data */
    #ifdef __DRM_SUPPORT__
        if (is_DRM)
        {
            kal_uint32 length;
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_INFO_SOURCE_IS_DRM);
            if (DRM_read_file(f, img->raw->data + img->raw->used_size, size - img->raw->used_size, &length) <
                FS_NO_ERROR)
            {
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_ERROR_READ_FILE);
                ret = HDI_FILE_ERROR_INVALID;
            }
            else
            {
                if (length)
                {
                    ret = length;
                }
                else
                { /* If read length is 0, we should return HDI_FILE_ERROR_EOF */
                    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_ERROR_END_OF_FILE);
                    ret = HDI_FILE_ERROR_EOF;
                }
            }
        }
        else
    #endif /* __DRM_SUPPORT__ */ 
        {
            ret = MSF_FILE_READ(f, img->raw->data + img->raw->used_size, size - img->raw->used_size);
        }
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_HDIA_FILE_READ, ret);
        if (ret < 0)
        {
            if (ret == HDI_FILE_ERROR_DELAYED)
            {
                /* In current implementation, DRM files are opened in blocking mode */
                WAP_DBG_ASSERT(!is_DRM);
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_HDIA_FILE_READ_ERROR_DELAYED);
                /* Wait for notification */
                if (need_add_select)
                {
                    widget_add_file_poll(f, _H(img), size);
                }
                MSF_FILE_SELECT(f, HDI_FILE_EVENT_READ);
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_RETURN_WIDGET_WAIT_SELECT);
                return WIDGET_WAIT_SELECT;
            }

            /* Something wrong happened */

            /* Even if "ret == HDI_FILE_ERROR_EOF", it is still incorrect. */
            WAP_DBG_ASSERT(img->raw->used_size < size);

            widget_send_notification_load_resource(img, MsfNotifyFailedCorrupt);
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_RETURN_WIDGET_READ_ERROR);
            return WIDGET_READ_ERROR;
        }
        else
        {
            img->raw->used_size += ret;

            if (img->raw->used_size == size)
            {
                if ((MsfVideoFormat) (img->image_format) >= MsfVideoFormatStart)
                {
                    /* 
                     * Should not reach here. 
                     * we don't support video resource in raw data style
                     */
                    /* video */
                }
                else
                {
                    /* image */
                    widget_create_image_resource(img);
                }
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_RETURN_WIDGET_READ_FINISH);
                return WIDGET_READ_FINISH;
            }
        }
    }

    /* Should not reach here */
    widget_send_notification_load_resource(img, MsfNotifyResourceError);
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_ERROR);
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_READ_IMAGE_FROM_FILE_TO_RAW_DATA_END);
    return WIDGET_READ_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  widget_read_image_from_file_to_raw_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f                   [IN]        
 *  size                [IN]        
 *  img                 [IN]         
 *  need_add_select     [IN]        
 *  is_DRM              [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static int widget_read_image_from_file_to_raw_file(
            int f,
            int size,
            widget_image_struct *img,
            kal_bool need_add_select,
            kal_bool is_DRM)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *buffer = WRAW_CTX->working_buffer;
    long ret;
    int rawfile_size;
    int data_to_read;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(img->rawfile_id != 0 && buffer);
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_READ_IMAGE_FROM_FILE_TO_RAW_FILE);
    while (((rawfile_size = widget_rawfile_getsize(img->rawfile_id)) < size) && (rawfile_size >= 0))
    {
        /* read image data */
        data_to_read = size - rawfile_size;

    #ifdef __DRM_SUPPORT__
        if (is_DRM)
        {
            kal_uint32 length;
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_INFO_SOURCE_IS_DRM);
            if (DRM_read_file
                (f, buffer, (data_to_read < WIDGET_LOAD_BUFFER_SIZE) ? data_to_read : WIDGET_LOAD_BUFFER_SIZE,
                 &length) < FS_NO_ERROR)
            {
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_ERROR_READ_FILE);
                ret = HDI_FILE_ERROR_INVALID;
            }
            else
            {
                if (length)
                {
                    ret = length;
                }
                else
                { /* If read length is 0, we should return HDI_FILE_ERROR_EOF */
                    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_ERROR_END_OF_FILE);
                    ret = HDI_FILE_ERROR_EOF;
                }
            }
        }
        else
    #endif /* __DRM_SUPPORT__ */ 
        {
            ret = MSF_FILE_READ(
                    f,
                    buffer,
                    (data_to_read < WIDGET_LOAD_BUFFER_SIZE) ? data_to_read : WIDGET_LOAD_BUFFER_SIZE);
        }
        /* we want to stop resource here when transition screen is deleted form history */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_HDIA_FILE_READ, ret);

        if (ret < 0)
        {
            if (ret == HDI_FILE_ERROR_DELAYED)
            {
                /* In current implementation, DRM files are opened in blocking mode */
                WAP_DBG_ASSERT(!is_DRM);
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_HDIA_FILE_READ_ERROR_DELAYED);
                /* Wait for notification */
                if (need_add_select)
                {
                    widget_add_file_poll(f, _H(img), size);
                }
                MSF_FILE_SELECT(f, HDI_FILE_EVENT_READ);
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_RETURN_WIDGET_WAIT_SELECT);
                return WIDGET_WAIT_SELECT;
            }

            /* Something wrong happened */

            /* Even if "ret == HDI_FILE_ERROR_EOF", it is still incorrect. */
            WAP_DBG_ASSERT(rawfile_size < size);

            widget_send_notification_load_resource(img, MsfNotifyFailedCorrupt);
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_RETURN_WIDGET_READ_ERROR);
            return WIDGET_READ_ERROR;
        }
        else
        {
            widget_rawfile_write(img->rawfile_id, buffer, ret);

            if (widget_rawfile_getsize(img->rawfile_id) == size)
            {
                if ((MsfVideoFormat) (img->image_format) >= MsfVideoFormatStart)
                {
                    /* video */
                }
                else
                {
                    /* image */
                    widget_create_image_resource(img);
                }
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_RETURN_WIDGET_READ_FINISH);
                return WIDGET_READ_FINISH;
            }
            else if (widget_rawfile_write_failed(img->rawfile_id))
            {
                widget_send_notification_load_resource(img, MsfNotifyFailedFSFull);
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_RETURN_WIDGET_READ_ERROR);
                return WIDGET_READ_ERROR;
            }
        }
        /* Otherwise,  keep reading */

        /*
         * We want to reduce accessing the file system when MT call is incoming.
         * Because incoming call may associate with the video and cause low response at incoming call screen.
         */
        if (widget_check_is_incoming_call() && widget_image_raw_file_list.f == 0)
        {
            widget_image_raw_file_list.f = f;
            widget_image_raw_file_list.size = size;
            widget_image_raw_file_list.img = img;
            widget_image_raw_file_list.need_add_select= need_add_select;
            widget_image_raw_file_list.is_DRM = is_DRM;
            widget_start_timer(WIDGET_RAW_FILE_IMAGE_CHECK_TIMER, widget_image_raw_file_check_time_hdlr, (void*)NULL, WIDGET_RAW_FILE_CHECK_TIME);
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WAIT_IF_INCOMING_CALL);
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_RETURN_WIDGET_WAIT_SELECT);
            return WIDGET_WAIT_SELECT;
        }
    }

    /* Should not reach here */
    widget_send_notification_load_resource(img, MsfNotifyResourceError);
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_RETURN_WIDGET_READ_ERROR);
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_READ_IMAGE_FROM_FILE_TO_RAW_FILE_END);
    return WIDGET_READ_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  widget_image_raw_file_check_time_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  arg             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void widget_image_raw_file_check_time_hdlr(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f = widget_image_raw_file_list.f;
    int size = widget_image_raw_file_list.size;
    int ret =  WIDGET_READ_FINISH;
    widget_image_struct *img = widget_image_raw_file_list.img;
    kal_bool need_add_select = widget_image_raw_file_list.need_add_select;
    kal_bool is_DRM = widget_image_raw_file_list.is_DRM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_IMAGE_RAW_FILE_CHECK_TIME_HDLR);
    memset(&widget_image_raw_file_list, 0, sizeof(widget_read_from_file_to_raw_file_item));
    ret = widget_read_image_from_file_to_raw_file(f, size, img, need_add_select, is_DRM);
    if (ret != WIDGET_WAIT_SELECT)
    {
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_HDIA_FILE_CLOSE);
        MSF_FILE_CLOSE(f);
    }
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_IMAGE_RAW_FILE_CHECK_TIME_HDLR_END);
}


/*****************************************************************************
 * FUNCTION
 *  widget_read_image_from_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f                   [IN]        
 *  size                [IN]        
 *  img                 [IN]         
 *  need_add_select     [IN]        
 *  is_DRM              [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int widget_read_image_from_file(int f, int size, widget_image_struct *img, kal_bool need_add_select, kal_bool is_DRM)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* We already know the image size. This is different from widget_read_image_from_pipe */
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_READ_IMAGE_FROM_FILE);
    if (img->raw)
    {
        return widget_read_image_from_file_to_raw_data(f, size, img, need_add_select, is_DRM);
    }
    else
    {
        return widget_read_image_from_file_to_raw_file(f, size, img, need_add_select, is_DRM);
    }
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_READ_IMAGE_FROM_FILE_END);
}


/*****************************************************************************
 * FUNCTION
 *  widget_read_image_from_pipe
 * DESCRIPTION
 *  Callback function of reading image data from pipe
 *  
 *  It will do these after the image is loaded: (but it doesn't close pipe)
 *  1. set "done" flag
 *  2. Recompute the dimension of the image
 *  3. Send MsfNotifyResourceLoaded, etc.
 *  
 *  Note: Modify widget_read_sound_from_pipe also if this function is changed.
 * PARAMETERS
 *  f                   [IN]            File handle
 *  img                 [IN/OUT]        The image
 *  need_add_select     [IN]            Whether to add into the map "widget_pn_*"
 * RETURNS
 *  WIDGET_READ_ERROR
 *  WIDGET_WAIT_SELECT
 *  WIDGET_READ_FINISH
 *****************************************************************************/
int widget_read_image_from_pipe(int f, widget_image_struct *img, kal_bool need_add_select)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    long ret;
    long size;
    int is_open;
    char *buffer = WRAW_CTX->working_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(buffer);
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_READ_IMAGE_FROM_PIPE);
    while (KAL_TRUE)
    {
        /* detect current data size */
        if (MSF_PIPE_STATUS(f, &is_open, &size) < 0)
        {
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_RETURN_WIDGET_READ_ERROR);
            return WIDGET_READ_ERROR;
        }

        if (size == 0)
        {
            /* nothing left to read */
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_NOTHING_LEFT_TO_READ);
            if (!is_open)
            {
                /* The peer writer has closed the pipe */
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_PEER_HAS_CLOSED_THE_PIPE);
                if (widget_image_length((MsfImageHandle) img) > 0)      /* We do read something */
                {
                    int flag;

                    flag = widget_image_set_done(img);
                    /*
                     * the return value of widget_image_set_done():
                     *  1 - the image is valid
                     *  0 - the image is invalid (can't get the image resolution)
                     *  -1 - The image is larger the limitation (WIDGET_IMAGE_MAX_WIDTH, WIDGET_IMAGE_MAX_HEIGHT)
                     *  -2 - gdi draw image failed (resource is not enough)
                     */
                    switch (flag)
                    {
                    case 1: /* 1 - the image is valid */
                        widget_send_notification_load_resource(img, MsfNotifyResourceReady);
                        break;
                    case 0: /* 0 - the image is invalid (can't get the image resolution) */
                        widget_send_notification_load_resource(img, MsfNotifyFailedCorrupt);
                        break;
                    case -1: /* -1 - The image is larger the limitation */
                        widget_send_notification_load_resource(img, MsfNotifyFailedResolution);
                        break;
                    case -2: /* -2 - gdi draw image failed (resource is not enough) */
                        widget_send_notification_load_resource(img, MsfNotifyFailedNoResource);
                        break;
                    default:
                        widget_send_notification_load_resource(img, MsfNotifyResourceError);
                    }
                    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_RETURN_WIDGET_READ_FINISH);
                    return WIDGET_READ_FINISH;
                }

                /* Note the case img->is_done = KAL_FALSE */
                widget_send_notification_load_resource(img, MsfNotifyResourceError);
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_RETURN_WIDGET_READ_ERROR);
                return WIDGET_READ_ERROR;
            }
            else
            {
                /* Wait for notification */

                if (need_add_select)
                {
                    widget_add_pipe_poll(f, _H(img));
                }

                MSF_PIPE_POLL(f);
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_RETURN_WIDGET_WAIT_SELECT);
                return WIDGET_WAIT_SELECT;
            }
        }

        if (size > WIDGET_LOAD_BUFFER_SIZE)
        {
            size = WIDGET_LOAD_BUFFER_SIZE;
        }
        ret = MSF_PIPE_READ(f, buffer, size);
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_HDIA_PIPE_READ, ret);
        if (ret < 0)
        {
            if (ret == HDI_PIPE_ERROR_DELAYED)
            {
                if (need_add_select)
                {
                    widget_add_pipe_poll(f, _H(img));
                }

                MSF_PIPE_POLL(f);
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_RETURN_WIDGET_WAIT_SELECT);
                return WIDGET_WAIT_SELECT;
            }
            else    /* if(ret == HDI_PIPE_ERROR_CLOSED) */
            {
                /* Should not happen, but no error */
                widget_send_notification_load_resource(img, MsfNotifyResourceError);
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_RETURN_WIDGET_READ_ERROR);
                return WIDGET_READ_ERROR;
            }
        }
        WAP_DBG_ASSERT(ret == size);
        if (HDIa_widgetImageNextPart((MsfImageHandle) img, buffer, ret, KAL_TRUE) == -1)
        {
		      /* If write the data failed, we delete the pipe */
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_WRITE_CONTENT_IN_PIPE_FAILED);  
		    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_HDIA_DELETE_PIPE_BY_HANDLE);  
		      HDIa_pipeDeleteByHandle(f);
              
        }

    }
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_READ_IMAGE_FROM_PIPE_END);
}

/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetImageCreateResource
 * DESCRIPTION
 *  
 *  Note: According to Teleca's reply, files should only be closed, but pipes should be both closed and deleted.
 * PARAMETERS
 *  modId               [IN]        
 *  resource            [IN]         
 *  resourceType        [IN]        
 *  imageFormat         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfImageHandle HDIa_widgetImageCreateResource(
                MSF_UINT8 modId,
                char *resource,
                MsfResourceType resourceType,
                MsfImageFormat imageFormat)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
     * User applications SHOULD use the return value to find out if the image is created successfully
     *
     * We will compute the size of the image after image/file is loaded
     *
     * Note that we do set default style in this API.
     */

    widget_raw_data_struct *raw = NULL;
    widget_image_struct *img = NULL;
    int return_value = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_HDIA_WIDGET_IMAGE_CREATE_RESOURCE);
#ifndef __MMI_VIDEO_PLAY_SUPPORT__    
    if ((MsfVideoFormat) imageFormat >= MsfVideoFormatStart)
    {
        /* If don't support video, return NULL directly when imageFormat is video */
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_RETURN_NO_SUPPORT);
        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_RETURN_0);
        return NULL;
    }
#endif /* #ifndef __MMI_VIDEO_PLAY_SUPPORT__ */
    
    switch (resourceType)
    {
        case MsfResourceFile:
        {
            long size;
            int f;
           
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_INFO_SOURCE_IS_FILE);

            f = MSF_FILE_OPEN(MSF_MODID_WIDGET, resource, HDI_FILE_SET_RDONLY, 0);
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_CALLS_HDIA_FILE_OPEN, (int)f);
            if (f < 0)
            {
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_ERROR_OPEN_FILE);
                /* do nothing */ ;
            }
            else if ((size = MSF_FILE_GETSIZE(resource )) <= 0 ||
                     (widget_is_rawfile_full() && widget_rawfile_allow_to_create_image(0, 0)))
            {
                return_value = MSF_FILE_CLOSE(f);
                WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_CALLS_HDIA_FILE_CLOSE, return_value);
            }
            else
            {
                /* allocate the raw data */
                img = widget_create_image(modId);
                img->module_id = modId;
                img->image_format = imageFormat;

                if ((MsfVideoFormat) imageFormat >= MsfVideoFormatStart)
                {
                    /* video */
                    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_INFO_SOURCE_IS_VIDEO);
                    if (widget_rawfile_allow_to_create_image(imageFormat, size))
                    {
                        img->rawfile_id = widget_rawfile_register((MsfImageHandle) img);
                    }
                }
                else
                {
                    /* image */
                    /* preallocate the data because we already know the size */
                    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_INFO_SOURCE_IS_IMAGE);
                    if (widget_rawfile_allow_to_create_image(imageFormat, size))
                    {
                        img->rawfile_id = widget_rawfile_register((MsfImageHandle) img);
                    }
                    else
                    {
                        raw = widget_create_raw_data_ext(modId, size);
                        widget_set_attrib_ptr(img, raw, raw);
                    }

                }

                switch (widget_read_image_from_file(f, size, img, KAL_TRUE, KAL_FALSE))
                {
                    case WIDGET_READ_FINISH:
                        return_value = MSF_FILE_CLOSE(f);
                        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_CALLS_HDIA_FILE_CLOSE, return_value);
                        break;
                    case WIDGET_WAIT_SELECT:
                        break;
                    case WIDGET_READ_ERROR:
                        MSF_FILE_CLOSE(f);
                        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_CALLS_HDIA_FILE_CLOSE, return_value);
                        break;
                }
            }

        }
            break;

        case MsfResourcePipe:
        {
            /* No support video resource */
            int f;

            f = MSF_PIPE_OPEN(MSF_MODID_WIDGET, resource);
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_INFO_SOURCE_IS_PIPE);
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_CALLS_HDIA_PIPE_OPEN, f);
            if (f >= 0)
            {
                img = widget_create_image(modId);
                img->module_id = modId;
                img->image_format = imageFormat;

                switch (widget_read_image_from_pipe(f, img, KAL_TRUE))
                {
                    case WIDGET_READ_FINISH:
                        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_HDIA_DELETE_PIPE_BY_HANDLE);
                        HDIa_pipeDeleteByHandle(f);
                        break;
                    case WIDGET_WAIT_SELECT:
                        /*
                         * We remove the follow code. (2005/09/27)
                         * In other situation, the upper application may create the 
                         * pipe and calls HDIa_widgetImageCreateResource() to create 
                         * the image. Sometimes the handset didn't receive the image 
                         * data from the network yet, and the function 
                         * widget_image_check_header will judge the file is invalid
                         * and delete the pipe. The image won't be showed on the screen. 
                         * Please refer MAUI_00126073              *
                         *
                         *
                         *
                         * VSWAP test case. 
                         * If we receive the invalid WBMP image, we should show the
                         * string not the empty image.
                         * We need to close the connection immediately after 
                         
                         if(!widget_image_check_header((MsfImageHandle)img))
                         HDIa_pipeDeleteByHandle(f);
                         // TODO: remove pipe map, send notification, test VSWAP
                         */
                        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_INFO_DO_NOTHING);
                        break;
                    case WIDGET_READ_ERROR:
                        WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_HDIA_DELETE_PIPE_BY_HANDLE);
                        HDIa_pipeDeleteByHandle(f);
                        break;
                }
            }
        }
            break;

#if 0 /* Not supported items */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __DRM_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __DRM_SUPPORT__ */ 
/* under construction !*/
#endif /* 0 */
        default:
            WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_GENERAL_DEFAULT_CASE);
            break;
    }
    WIDGET_LOG(WIDGET_LOG_GROUP, MMI_WIDGET_HDIA_WIDGET_IMAGE_CREATE_RESOURCE_END);
    return (MsfImageHandle) img;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetImageCreateEmpty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId               [IN]        
 *  size                [IN]         
 *  defaultStyle        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfImageHandle HDIa_widgetImageCreateEmpty(MSF_UINT8 modId, MsfSize *size, MsfStyleHandle defaultStyle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfStyleHandle copy_style;

    widget_image_struct *img = widget_create_image(modId);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    img->module_id = modId;
    img->is_drawn_image = 1;

    if (size)
    {
        img->size = *size;
    }

    if (defaultStyle)
    {
        /*
         * Duplicte the style object because we will draw one the image.
         * * 
         * * FIXME. COPY-ON-WRITE of style object is a better solution. 
         * * However, the implementation will be much more complex.
         */
        copy_style = widget_style_copy(modId, defaultStyle);
        widget_set_attrib(img, style, copy_style);
        DEC_REF(copy_style);
    }
    else
    {
        widget_set_attrib(img, style, 0);
    }
    return (MsfImageHandle) img;
}

#ifdef WIDGET_BROWSER_AUTORESIZE_JPEG


/*****************************************************************************
 * FUNCTION
 *  widget_image_auto_resize_JPEG
 * DESCRIPTION
 *  In platform MT6205B, MT6218, MT6218B and MT6217, HW has limitation of
 *  encoding JPEG image, and we need to resize the JPEG in this situation.
 * PARAMETERS
 *  image           [IN]        
 *  max_size        [IN]        
 *  size            [IN]         
 * RETURNS
 *  if need to resize the JPEG
 *****************************************************************************/
kal_bool widget_image_auto_resize_JPEG(MsfImageHandle image, const MsfSize *max_size, MsfSize *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ret = KAL_FALSE;
    widget_image_struct *img;
    S32 width, height;              /* image width/height */
    S32 zoom_width, zoom_height;
    S32 width_round, height_round;  /* round to muliply of 16 */
    S32 tmp_width, tmp_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!image || !IS_IMAGE_TYPE(image))
    {
        return ret;
    }

    img = _IMG(image);

    if (img->image_format != MsfJpeg)
    {
        return ret;
    }

    width = img->size.width;
    height = img->size.height;

    /* 
     * Reference: widget_form_sliding_SMIL_fit_image() 
     * It is tricky due to hardware limitation on MT6217/MT6218.
     */
    /* NUM_JPEG_BUFFER_PIXELS_16: The number of 16x16 blocks available in JPEG frame buffer. */
#define NUM_JPEG_BUFFER_PIXELS_16   ((GDI_LCD_WIDTH/16+1)*((GDI_LCD_HEIGHT/16+1)))

    if (max_size)
    {
        S32 dummy_x, dummy_y;

        gdi_image_util_fit_bbox(
            max_size->width,
            max_size->height,
            width,
            height,
            &dummy_x,
            &dummy_y,
            &zoom_width,
            &zoom_height);
    }
    else
    {
        zoom_width = width;
        zoom_height = height;
    }

    width_round = (zoom_width + 15) >> 4;
    height_round = (zoom_height + 15) >> 4;

    if (width_round * height_round > NUM_JPEG_BUFFER_PIXELS_16)
    {
#ifdef BROWSER_SUPPORT     
        if (img->module_id != MSF_MODID_BRS)
        {
            /* MMS also resize image in SMIL editor. Only browser has such a large image */
            MMI_DBG_ASSERT(0);
        }
        else
#endif
        {
            do
            {
                if (width > height)
                {
                    width_round--;
                    tmp_width = width_round << 4;
                    tmp_height = tmp_width * height / width;
                    height_round = (tmp_height + 15) >> 4;
                }
                else
                {
                    height_round--;
                    tmp_height = height_round << 4;
                    tmp_width = tmp_height * width / height;
                    width_round = (tmp_width + 15) >> 4;
                }
            } while (width_round * height_round > NUM_JPEG_BUFFER_PIXELS_16);

            if (tmp_width == 0 || tmp_width == 0)
            {
                /* Very strange image size (width/height ratio is abnormal, e.g. width =  5, height = 2000) 
                   We can not fit the image into JPEG buffer. */
            }
            else
            {
                /* Return */
                size->width = tmp_width;
                size->height = tmp_height;
                ret = KAL_TRUE;
            }
        }
    }

    return ret;
}

#endif /* WIDGET_BROWSER_AUTORESIZE_JPEG */ 


/*****************************************************************************
 * FUNCTION
 *  widget_initialize_image_dimension
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image       [IN]        
 * RETURNS
 *  Whether the image dimension is set successfully
 *     1: get dimension succeed
 *     0: can't get dimension;
 *     -1: dimension is too large;
 *     -2: file is corrupted;
 *****************************************************************************/
/*
 * NOTE: We read image header from file at the beginning, whcih prevent the 
 * * re-entrance of GDI dimension API. (WAP and MMI have the same priority, 
 * * and context switch only happens between reading files)
 */
static kal_int32 widget_initialize_image_dimension(MsfImageHandle image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* [ret]
     * 1: get dimension succeed
     * 0: can't get dimension;
     * -1: dimension is too large;
     * -2: file is corrupted;
     */
    kal_int32 ret = 0;
    GDI_RESULT gdi_ret;
    char *content, *fname;
    U32 len;
    S32 width = 0, height = 0;
    MsfSize *size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if supporting the image format */

    if (widget_image_format(image) >= MsfPI_Start && 
        widget_image_format(image) <= MsfPI_End)
    {
        /* Actually we only support predefined image with Pbm */
        /* get the dimension succeed */
        return 1;
    }

    if (widget_image_format(image) == MsfJpeg)
    {
    #ifndef WIDGET_JPEG_SUPPORT
        /* can't get the dimension */
        return 0;
    #endif 
    }

    if (widget_image_format(image) == MsfPng)
    {
    #ifndef GDI_USING_PNG
        /* can't get the dimension */
        return 0;
    #endif 
    }

    size = widget_image_dimension(image);
    
    ASSERT(size != NULL);

    size->width = 0;
    size->height = 0;
    content = widget_image_content_file(image);
    if (content != NULL)
    {
        fname = (char*)HDI_FileNameTranslate(content);
        gdi_ret = gdi_image_get_dimension_file((PS8) fname, &width, &height);
        HDI_FileNameFree((kal_uint8*) fname);
    }
    else
    {
        ret = KAL_FALSE;
        size->width = 0;
        size->height = 0;

        content = (char*)widget_image_content(image);
        if (content == NULL)
        {
            /* if content is NULL, it means MsfImageHandle is invalid */
            /* can't get the dimension */
            return 0;
        }

        len = (U32) widget_image_length(image);

        switch (widget_image_format(image))
        {
            case MsfBmp:
                gdi_ret = gdi_image_bmp_get_dimension((U8*) content, &width, &height);
                break;
            case MsfGif:
                gdi_ret = gdi_image_gif_get_dimension((U8*) content, &width, &height);
                break;
            case MsfWbmp:
                gdi_ret = gdi_image_wbmp_get_dimension((U8*) content, &width, &height);
                break;
            case MsfJpeg:
                gdi_ret = gdi_image_jpeg_get_dimension((U8*) content, len, &width, &height);
                break;
            case MsfPng:
            #ifdef GDI_USING_PNG
                gdi_ret = gdi_image_png_get_dimension((U8*) content, len, &width, &height);
                break;
            #endif /* GDI_USING_PNG */ 
            default:
                /* can't get the dimension */
                gdi_ret = 0;
                break;
        }
        /* 
         * After GDI supports the common API for get image dimension by the raw data,
         * we can modify the code like below.
         
         gdi_ret = gdi_image_get_dimension((U8*)content, &width, &height);
         */
    }

    if (gdi_ret >= 0)
    {
        if (width == 0 || height == 0)
        {
            /* If get the image resolution is 0, we assume the file is corrupted */
            size->width = (MSF_INT16) width;
            size->height = (MSF_INT16) height;
            /* -2: file is corrupted; */
            ret = -2;
        }
        else if (width >> 15 || height >> 15)
        {
            /* image resolution is larger than MSF_INT16 limitation */
            size->width = WIDGET_IMAGE_TOO_LARGE_WIDTH;
            size->height = WIDGET_IMAGE_TOO_LARGE_HEIGHT;
            ret = 1;
        }
        else
        {
            size->width = (MSF_INT16) width;
            size->height = (MSF_INT16) height;
            ret = 1;
        }
    }

#ifdef WIDGET_BROWSER_AUTORESIZE_JPEG
    /* 
     * In platform MT6205B, MT6218, MT6218B and MT6217, HW has limitation of
     * encoding JPEG image, and we need to resize the JPEG in this situation.
     */
    if (ret)
    {
        kal_bool jpg_resize_ret;
        MsfSize jpg_resize_size;

#ifdef BROWSER_SUPPORT
        if ((widget_image_format(image) == MsfJpeg) && (_IMG(image)->module_id == MSF_MODID_BRS))
        {
            jpg_resize_ret = widget_image_auto_resize_JPEG(image, NULL, &jpg_resize_size);
            if (jpg_resize_ret)
            {
                size->width = jpg_resize_size.width;
                size->height = jpg_resize_size.height;
                _IMG(image)->is_jpeg_auto_resize = 1;
            }
        }
#endif
    }
#endif /* WIDGET_BROWSER_AUTORESIZE_JPEG */ 

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  widget_MMI_initialize_image_frame_count
 * DESCRIPTION
 *  For non-GIF images, frame count is set as 0
 * PARAMETERS
 *  image       [IN]        
 * RETURNS
 *  Whether the image frame count is set successfully
 *****************************************************************************/
kal_bool widget_MMI_initialize_image_frame_count(MsfImageHandle image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *content;
    S32 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Compared to widget_initialize_image_dimension(), this function must be executed 
       in MMI task */
    WAP_DBG_ASSERT(WIDGET_IS_MMI_TASK());

    if (!IS_IMAGE_TYPE(image))
    {
        /* predefined images are not supported */
        return KAL_FALSE;
    }

    if (widget_image_format(image) != MsfGif)
    {
        _IMG(image)->GIF_frames = 0;
        return KAL_TRUE;
    }

    count = 0;
    content = (U8*) widget_image_content(image);
    if (content)
    {
        int size = widget_image_length(image);

        /* If the GIF image is truncated, gdi_image_gif_get_frame_count might return failure, 
           but count might be greater than 0 */
        gdi_image_gif_get_frame_count(content, size, &count);

        WAP_DBG_ASSERT(count >= 0);
        _IMG(image)->GIF_frames = count;

        return KAL_TRUE;
    }
    else if ((content = (U8*) widget_image_content_file(image)) != NULL)
    {
        char *full_name;

        full_name = (char*)HDI_FileNameTranslate((char*)content);

        gdi_image_gif_get_frame_count_file(full_name, &count);

        HDI_FileNameFree((kal_uint8*) full_name);

        WAP_DBG_ASSERT(count >= 0);
        _IMG(image)->GIF_frames = count;

        return KAL_TRUE;
    }
    else
    {
        _IMG(image)->GIF_frames = 0;
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetImageCreateFormat
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId               [IN]        
 *  imageData           [IN]         
 *  imageFormat         [IN]        
 *  resourceType        [IN]        
 *  defaultStyle        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfImageHandle HDIa_widgetImageCreateFormat(
                MSF_UINT8 modId,
                MsfCreateData *imageData,
                const char *imageFormat,
                MsfResourceType resourceType,
                MsfStyleHandle defaultStyle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int image_format = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* We may add custom features like Video. (c.f. MEA) */
    if (msf_cmmn_strcmp_nc(imageFormat, "image/bmp") == 0)
    {
        image_format = MsfBmp;
    }   /* pictogram not supported */
    else if (msf_cmmn_strcmp_nc(imageFormat, "image/gif") == 0)
    {
        image_format = MsfGif;
    }
    else if (msf_cmmn_strcmp_nc(imageFormat, "image/jpeg") == 0)
    {
        image_format = MsfJpeg;
    }
    else if (msf_cmmn_strcmp_nc(imageFormat, "image/png") == 0)
    {
        image_format = MsfPng;
    }
    else if (msf_cmmn_strcmp_nc(imageFormat, "image/vnd.wap.wbmp") == 0)
    {
        image_format = MsfWbmp;
    }
    /* image/x-portable-bitmap is different from our proprietary Pbm */

    if (image_format < 0)
    {
        return (MsfImageHandle) 0;
    }

    if (resourceType == MsfResourcePipe || resourceType == MsfResourceFile)
    {
        return (MsfImageHandle) HDIa_widgetImageCreateResource(
                                    modId,
                                    (char*)imageData->resource,
                                    resourceType,
                                    (MsfImageFormat) image_format);
    }
    else
    {
        return (MsfImageHandle) HDIa_widgetImageCreate(
                                    modId,
                                    imageData->directData->data,
                                    imageData->directData->dataSize,
                                    (MsfImageFormat) image_format,
                                    imageData->directData->moreData,
                                    defaultStyle);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetImageGetPredefined
 * DESCRIPTION
 *  
 * PARAMETERS
 *  resId           [IN]        
 *  resString       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfImageHandle HDIa_widgetImageGetPredefined(MSF_UINT32 resId, const char *resString)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_pre_image_struct *w = NULL;
    kal_uint32 index;

#ifndef WIDGET_COMPACT_PRE_IMAGE
    kal_uint8 *src;
    int width, height;
#endif /* WIDGET_COMPACT_PRE_IMAGE */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* This is mandatory because we do not have any predefined images of resource string. 
       If we do not return 0, some images will displayed in wrong way. */
    if (resString != NULL)
    {
#ifdef  __MMI_WAP_CORE_PICTOGRAM_SUPPORT__
        ASSERT(resId == 0);
        resId = widget_image_get_pictogram_handle(resString);
        if (resId == 0)
#endif /*  __MMI_WAP_CORE_PICTOGRAM_SUPPORT__ */
        {
        return 0;
    }
    }

    /* use a dummy image */
    if (resId < WAP_IMAGE_ID_BEGIN || resId >= WAP_IMAGE_ID_END)
    {
        /* Enable this assert to check the range of image ID */
        resId = WAP_IMG_ICON_BROKEN_IMAGE;
    }

    index = resId - WAP_IMAGE_ID_BEGIN;

    /* get a preallocated slot */
    w = &widget_predefined_image_table[index];

#ifdef WIDGET_COMPACT_PRE_IMAGE
    w->data_type = WIDGET_PRE_IMAGE_TYPE;
    w->flag = WIDGET_FLAG_STATIC;
#else /* WIDGET_COMPACT_PRE_IMAGE */ 
    src = (kal_uint8*) get_image((kal_uint16) (resId));

    /*
     * Use a dummy image if the image does not exist.
     * * Otherwise it might produce 'access violation'
     */
    if (src == NULL)
    {
        src = (kal_uint8*) get_image(WAP_IMG_ICON_BROKEN_IMAGE);
        ASSERT(src);
    }

    w->data_type = WIDGET_PRE_IMAGE_TYPE;
    w->flag = WIDGET_FLAG_STATIC;
    w->src = gdi_image_get_buf_ptr_from_id((kal_uint16)resId);
    w->length = gdi_image_get_buf_len_from_id((kal_uint16)resId);

    /* detect image format */
    switch (gdi_image_get_type_from_id((kal_uint16)resId))
    {
        case IMAGE_TYPE_BMP:
            /* FALLTHROUGH no break */
        case IMAGE_TYPE_BMP_SEQUENCE:   /* BMP */
            w->image_format = MsfBmpPI;
            break;
        case IMAGE_TYPE_GIF:            /* GIF */
            w->image_format = MsfGifPI;
            break;
        case IMAGE_TYPE_DEVICE_BITMAP:
            /* FALLTHROUGH no break */
        case IMAGE_TYPE_DEVICE_BITMAP_SEQUENCE:
            w->image_format = MsfPbmPI;
            break;
        case IMAGE_TYPE_JPG:
            w->image_format = MsfJpegPI;
            break;
        case IMAGE_TYPE_PNG:
            w->image_format = MsfPngPI;
            break;
        default:
            w->image_format = MsfUnsupportedMediaType;
            break;
    }
    gui_measure_image((kal_uint8*) src, (S32*) & width, (S32*) & height);

    w->size.width = width;
    w->size.height = height;
    w->resource_id = resId;
#endif /* WIDGET_COMPACT_PRE_IMAGE */ 

    return (MsfImageHandle) w;
}

/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtImageGadgetGetSourceFile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  return NULL if there is not rawfile cache or something wrong happened.
 *****************************************************************************/
const char *HDIa_widgetExtImageGadgetGetSourceFile(MsfGadgetHandle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IS_GADGET_IMAGE_TYPE(handle))
    {
        return NULL;
    }
    return widget_image_content_file(_GIMG(handle)->image);
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtEnablePreCacheImage
 * DESCRIPTION
 *  Try to cache the image in memory if possible
 * PARAMETERS
 *  img     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HDIa_widgetExtEnablePreCacheImage(MsfImageHandle img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(WIDGET_PRECACHE_IMAGE) && !defined WIDGET_SUPPORT_DRAW_IMAGE_IN_NONBLOCKING
    if (!IS_IMAGE_TYPE(img))
    {
        WAP_DBG_ASSERT(IS_PRE_IMAGE_TYPE(img));
        return;
    }
    /* WAP_DBG_ASSERT(_IMG(img)->precache_state == WIDGET_PRECACHE_IMAGE_NONE); */
    _IMG(img)->precache_state = WIDGET_PRECACHE_IMAGE_ACCEPT;
#endif /* WIDGET_PRECACHE_IMAGE */ 
}


/*****************************************************************************
 * FUNCTION
 *  widget_init_image
 * DESCRIPTION
 *  Initialization of image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_init_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef WIDGET_COMPACT_PRE_IMAGE
    WIMG_CTX->pre_image_cache_id = 0;
#endif 
    WIMG_CTX->gif_head = NULL;
    WIMG_CTX->busy_indication_icon = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  widget_deinit_image
 * DESCRIPTION
 *  De-initialization of image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_deinit_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_gif_animation_struct *node = WIMG_CTX->gif_head, *next;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (node)
    {
        next = node->next;
#ifdef WAP_USE_ASM
        widget_internal_mem_free(MSF_MODID_WIDGET, node);
#else
        MSF_MEM_FREE(MSF_MODID_WIDGET, node);
#endif
        node = next;
    }
    WIMG_CTX->gif_head = NULL;
}


/****************************************************************
 * Video
 ***************************************************************/

#ifdef WIDGET_CHECK_IMAGE_IN_DETAIL
/*****************************************************************************
 * FUNCTION
 *  widget_check_image_in_detail
 * DESCRIPTION
 *  Check the MsfImage is valid in detail
 * PARAMETERS
 *  image       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool widget_check_image_in_detail(MsfImageHandle image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT gdi_ret = GDI_FAILED;
    char *content, *fname;
    kal_int32  w = UI_device_width >> 2;
    kal_int32  h = UI_device_height >> 2;
    kal_uint8  *buffer_ptr = NULL;
    gdi_handle fake_layer;
	kal_bool ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Limitation at MDI end, If video is playing, don't send image decoding request to GDI */
#ifdef __MMI_VIDEO_PLAYER__
    if(mmi_vdoply_is_in_app())
    {
        return MMI_FALSE;
    }
#endif
    /* Check if supporting the image format */
    if (widget_image_format(image) >= MsfPI_Start && 
        widget_image_format(image) <= MsfPI_End)
    {
        /* Actually we only support predefined image with Pbm */
        return KAL_TRUE;
    }

    if (widget_image_format(image) == MsfJpeg)
    {
    #ifndef WIDGET_JPEG_SUPPORT
        return KAL_FALSE;
    #endif 
    }

    if (widget_image_format(image) == MsfPng)
    {
    #ifndef GDI_USING_PNG
        return KAL_FALSE;
    #endif 
    }



    content = widget_image_content_file(image);
    if (content != NULL)
    {   /* image file */
        fname = (char*)HDI_FileNameTranslate(content);
        //gdi_ret = gdi_image_draw_resized_file(0, 0, w, h, (S8 *)fname);
		ret = gdi_image_check_image_file_valid((S8 *)fname);
        HDI_FileNameFree((kal_uint8*) fname);
		return ret;
    }
    else
    {   /* image data */

#ifdef WAP_USE_ASM
    buffer_ptr = widget_internal_mem_alloc(MSF_MODID_WIDGET, (w*h*GDI_MAINLCD_BIT_PER_PIXEL)>>3);
#else
    buffer_ptr = MSF_MEM_ALLOC(MSF_MODID_WIDGET, (w*h*GDI_MAINLCD_BIT_PER_PIXEL)>>3);
#endif
    if (buffer_ptr == NULL)
    {
        /*
         * Because we need allocated non D-cachable buffer for GDI layer,
         * we can't declare the local variable (stack is cacheable memory).
         */
        w = 12;
        h = 12;
        buffer_ptr = MSF_MEM_ALLOC(MSF_MODID_WIDGET, (w*h*GDI_MAINLCD_BIT_PER_PIXEL)>>3);
        MMI_DBG_ASSERT(buffer_ptr == NULL);
    }

    gdi_layer_create_using_outside_memory(
        0,
        0,
        w,
        h,
        &fake_layer,
        (PU8) buffer_ptr,
        (S32) (w*h*GDI_MAINLCD_BIT_PER_PIXEL)>>3);
    gdi_layer_push_and_set_active(fake_layer);

        content = (char*)widget_image_content(image);
        if (content != NULL)
        {
            gdi_ret = gdi_image_draw_resized_frames(0, 0, w, h, (U8*) content, 0);
        }
    
    gdi_layer_pop_and_restore_active();
    gdi_layer_free(fake_layer);
    if (w != 12 && h != 12)
    {
        MSF_MEM_FREE(MSF_MODID_WIDGET, buffer_ptr);
    }
    else
    {
        media_free_ext_buffer(MOD_MMI, (void **)&buffer_ptr);
    }
    }
    

    if (gdi_ret == GDI_SUCCEED)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}
#endif /* WIDGET_CHECK_IMAGE_IN_DETAIL */


