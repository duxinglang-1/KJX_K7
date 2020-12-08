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
 *   ImageViewCuiGprot.h
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
#ifndef CUI_IMAGEVIEWCUI_GPROT_H
#define CUI_IMAGEVIEWCUI_GPROT_H

#include "MMI_features.h"
/*******************************************************************************
* Include Header File
*******************************************************************************/
#include "kal_general_types.h"
#include "mmi_res_range_def.h"
#include "MMIDataType.h"
#ifndef __RESOURCE_GEN_
#include "FileMgrSrvGProt.h"
#endif

#ifdef __MMI_IMAGE_VIEWER__

/****************************************************************************
 * Events of imgview CUI
 ***************************************************************************/
typedef enum
{
    /* Get file name, see IMGVIEW_SRC_GET_FILE */
    EVT_ID_IMGVIEW_GET_FILENAME = (IMAGE_VIEWER_BASE + 1),
    
    /* Ask user to close the CUI */
    EVT_ID_IMGVIEW_CLOSE,
    
    /* LSK release when not set CUI_IMGVIEW_DISP_LSK_DEF */
    EVT_ID_IMGVIEW_ON_OK,

    /* User select other storage from menu, the dummy ID only for imageivew widgets*/
    EVT_ID_IMGVIEW_STORAGE_CHANGE, 
    
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_IMGVIEW_END
    /* DOM-NOT_FOR_SDK-END */
}cui_imgview_event_enum;

/****************************************************************************
 * Param of events
****************************************************************************/
/*  
 *  event structure of EVT_ID_IMGVIEW_GET_FILENAME
 */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER 
    /* DOM-NOT_FOR_SDK-END */
    
    /* File index */
    S32 index;
    
    /* Buf ptr of filename */
    WCHAR* path_buffer;
    
    /* Filename buffer size */
    U32 path_buffer_size;
} cui_imgview_get_filename_event_struct;

typedef enum
{
    IMGVIEW_SRC_INVALID = 0,
    IMGVIEW_SRC_FILE,
    IMGVIEW_SRC_GET_FILE,   //CUI will request file from user by EVT_ID_IMGVIEW_GET_FILE 
    IMGVIEW_SRC_FILELIST
}cui_imgview_src_mode;

typedef union
{
    struct{
        WCHAR *pname;
    }file;
    struct{
        SRV_FMGR_FILELIST_HANDLE h_list;
        U32 cur_index;
    }file_list;
    struct{
        U32 count;
        U32 cur_index;
    }get_file;

}cui_imgview_src_data;

/*****************************************************************************
 * FUNCTION
 *  cui_imgview_create_ex
 * DESCRIPTION
 *  Create imageview CUI.
 * PARAMETERS
 *  app_id:      [IN]  app for memory allocation.
 *  parent_gid:  [IN]  group id of the CUI's parent.
 * RETURNS
 *  id of the CUI created.
 *****************************************************************************/
extern mmi_id cui_imgview_create_ex(U16 app_id, mmi_id parent_gid);

/*****************************************************************************
 * FUNCTION
 *  cui_imgview_run
 * DESCRIPTION
 *  Run image view cui.
 * PARAMETERS
 *  image_viewer_id   :  [IN]  Image view group id.
 * RETURNS
 *  None.
 *****************************************************************************/
extern void cui_imgview_run(mmi_id image_viewer_id);


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_close
 * DESCRIPTION
 *  Close image view cui.
 * PARAMETERS
 *  image_viewer_id   :  [IN]  Image view group id.
 * RETURNS
 *  None.
 *****************************************************************************/
extern void cui_imgview_close(mmi_id image_viewer_id);

/*
 * Available display capbility values
 */
#define CUI_IMGVIEW_DISP_LSK_DEF    (0x1<<0)    //Use default LSK. LSK display 'OK' and emit EVT_ID_IMGVIEW_ON_OK if not set this bit
#define CUI_IMGVIEW_DISP_ROT        (0x1<<1)    /* if UI rotate */

/*****************************************************************************
 * FUNCTION
 *  cui_imgview_init_display
 * DESCRIPTION
 *  Set the display capbility of the CUI. 
 *  Must call it after cui_imgview_create()and before cui_imgview_run(). 
 *  CUI will have the default display screen if user don't call this function.
 * PARAMETERS
 *  image_viewer_id   :  [IN]  Image view group id.
 *  cap           :  [IN]  Can be or by the available values. See display capbility values.
 * RETURNS
 *  MMI_TRUE : success.
 *  MMI_TRUE : failed.
 *****************************************************************************/
extern MMI_BOOL  cui_imgview_init_display(mmi_id cui_id, U32 cap);

/*****************************************************************************
 * FUNCTION
 *  cui_imgview_get_dispcap
 * DESCRIPTION
 *  Get display capbility. 
 *  User can use the result of this function to cui_imgview_init_display by set  
 *  or clear specified bits.
 * PARAMETERS
 *  image_viewer_id   :  [IN]  Image view group id.
 * RETURNS
 *  Display capbility
 *****************************************************************************/
extern U32 cui_imgview_get_dispcap(mmi_id cui_id);

/*****************************************************************************
 * FUNCTION
 *  cui_imgview_is_rotate
 * DESCRIPTION
 *  If the UI is roate.
 * PARAMETERS
 *  image_viewer_id   :  [IN]  Image view group id.
 * RETURNS
 *  
 *****************************************************************************/
extern MMI_BOOL cui_imgview_is_rotate(mmi_id cui_id);


/*****************************************************************************
 * FUNCTION
 *  cui_imgview_init_source
 * DESCRIPTION
 *  Init source for CUI. 
 * PARAMETERS
 *  image_viewer_id   :  [IN]  Image view group id.
 *  mode              :  [IN]  source mode.
 *  pdata             :  [IN]  data of source. See cui_imgview_src_data.
 * RETURNS
 *  Default ability
 *****************************************************************************/
extern MMI_BOOL cui_imgview_init_source(mmi_id cui_id, cui_imgview_src_mode mode, const cui_imgview_src_data *pdata);

/*****************************************************************************
 * FUNCTION
 *  cui_imgview_get_cur_index
 * DESCRIPTION
 *  Get index of the image currently view. 
 * PARAMETERS
 *  image_viewer_id   :  [IN]  Image view group id.
 * RETURNS
 *  Image index
 *****************************************************************************/
extern S32 cui_imgview_get_cur_index(mmi_id cui_id);
extern const WCHAR *cui_imgview_get_cur_filename(mmi_id cui_id);

/*****************************************************************************
 * FUNCTION
 *  cui_imgview_set_title
 * DESCRIPTION
 *  Set title of the image cui. 
 * PARAMETERS
 *  image_viewer_id   :  [IN]  Image view group id.
 *  ptitle            :  [IN]  Title string. Imageview CUI will not allocate space to store the title.
 *  icon              :  [IN]  No use. Just for compatible with the old API.
 * RETURNS
 *  
 *****************************************************************************/
extern void cui_imgview_set_title(mmi_id cui_id, const WCHAR *ptitle, U16 icon);

/*
 * Compatibel API with old version, need remove at last 
 */

/* 
 * imageview view mode 
 */
typedef enum
{
    /* Horizontal view mode */
    CUI_IMGVIEW_UI_DIRECTION_HORIZONTAL = 0,

    /* Vertical view mode */
    CUI_IMGVIEW_UI_DIRECTION_VERTICAL,
    
    /* DOM-NOT_FOR_SDK-BEGIN */
    CUI_IMGVIEW_UI_DIRECTION_END
    /* DOM-NOT_FOR_SDK-END */
} cui_imgview_ui_direction_enum;


#define EVT_ID_IMGVIEW_CLOSE_GID    EVT_ID_IMGVIEW_CLOSE

#ifdef __MMI_IMAGE_VIEWER_EX__

#define EVT_ID_IMGVIEW_FILE_SELECT  EVT_ID_IMGVIEW_ON_OK
#define EVT_ID_IMGVIEW_GET_LSK_ICON EVT_ID_IMGVIEW_END
typedef enum
{
    IMGVIEW_ICON_NORMAL = 0,
    IMGVIEW_ICON_PRESS,
    IMGVIEW_ICON_DISABLE
}cui_imgview_icon_type;

typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER 
    /* DOM-NOT_FOR_SDK-END */
    
    /* File (id) index of list */
    cui_imgview_icon_type type;
    U8  ui_rotate;  //angle of UI rotate
    U16 icon_id;
} cui_imgview_lskicon_event_struct;

/*
 * mediaview view style
 */
typedef enum
{
    /* Wallview is a special matrix view */
    CUI_MEDIAVIEW_STYLE_WALLVIEW = 0,

    /* List view */
    CUI_MEDIAVIEW_STYLE_LIST,

    /* Matrix view */
    CUI_MEDIAVIEW_STYLE_MATRIX,
    
    /* DOM-NOT_FOR_SDK-BEGIN */
    CUI_MEDIAVIEW_STYLE_END
    /* DOM-NOT_FOR_SDK-END */
} cui_mediaview_style_enum;

/* 
 * mediaview events
 */
typedef enum
{
    /* Please close mediaview cui */
    EVT_ID_MEDIAVIEW_CLOSE_GID = (IMAGE_VIEWER_BASE + 100),
    
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_MEDIAVIEW_END
    /* DOM-NOT_FOR_SDK-END */
}cui_mediaview_event_enum;

/* 
 * imageview function set
 */
typedef enum
{
    /* Zoom function */
    CUI_IMGVIEW_CAP_ZOOM,

    /* ADV and older, IMG_ROTATE == UI_ROTATE */
    CUI_IMGVIEW_CAP_IMG_ROTATE,

    /* UI rotate funciton */
    CUI_IMGVIEW_CAP_UI_ROTATE,

    /* Counter, filename, title are true at the same time, counter first, filename second, title third */
    CUI_IMGVIEW_CAP_FILENAME,

    /* Counter, filename, title are true at the same time, counter first, filename second, title third */
    CUI_IMGVIEW_CAP_COUNTER,

    /* IVEX default option, ADV and older default is print or nothing */
    CUI_IMGVIEW_CAP_OPTION,

    /* Slideshow */
    CUI_IMGVIEW_CAP_SLIDESHOW,

    /* Caller pass the string */
    CUI_IMGVIEW_CAP_TITLE,

    /* Use database */
    CUI_IMGVIEW_CAP_DB,

    /* All */
    CUI_IMGVIEW_CAP_ALL,
    
    /* DOM-NOT_FOR_SDK-BEGIN */
    CUI_IMGVIEW_CAP_END
    /* DOM-NOT_FOR_SDK-END */
} cui_imgview_cap_enum;

extern void cui_imgview_set_app_id(mmi_id image_viewer_id, U16 app_id);
extern void cui_imgview_set_ui_direction(
                    mmi_id image_viewer_id, 
                    cui_imgview_ui_direction_enum direction);
extern void cui_imgview_set_display_cap(
                    mmi_id image_viewer_id, 
                    cui_imgview_cap_enum item_id, 
                    MMI_BOOL is_enable);
extern mmi_id cui_imgview_create(mmi_id parent_gid);
extern void cui_mediaview_close(mmi_id media_viewer_id);
extern void cui_imgview_set_mode_filename(mmi_id cui_id, CHAR* filepath);
extern void cui_imgview_set_mode_filelist(
                    mmi_id image_viewer_id, 
                    SRV_FMGR_FILELIST_HANDLE filelist, 
                    U32 start_index);

/*
 * Enable storage select menu item. Default is Disabled.
 * A dummy API.
 * Only enabled for EX and only can be called by Imageivew widgets.
 */
extern void cui_imgiew_set_storage_enable(mmi_id cui_id);
#else

#define cui_imgiew_set_storage_enable(imgview_gid) 
#define cui_imgview_set_app_id(imgview_gid, app_id)
#define cui_imgview_set_display_cap(imgview_gid, cap, enable)

#define cui_imgview_set_ui_direction(image_viewer_id, direction)    \
        do{                                                         \
            S32 flag = cui_imgview_get_dispcap(image_viewer_id);    \
            if(direction == CUI_IMGVIEW_UI_DIRECTION_HORIZONTAL){   \
                flag |= CUI_IMGVIEW_DISP_ROT;                       \
                cui_imgview_init_display(image_viewer_id, flag);    \
            }                                                       \
        }while(0);                                                  

#define cui_imgview_create(parent_gid) cui_imgview_create_ex(0, parent_gid)

#define cui_imgview_set_mode_filename(cui_id, filepath)             \
        do{                                                         \
            cui_imgview_src_data src_data;                          \
            src_data.file.pname = (WCHAR*)filepath;                 \
            cui_imgview_init_source(cui_id, IMGVIEW_SRC_FILE, &src_data);   \
        }while(0);

#define cui_imgview_set_mode_filelist(cui_id, filelist, start_index)    \
        do{                                                                     \
            cui_imgview_src_data src_data;                                      \
            src_data.file_list.h_list = filelist;                               \
            src_data.file_list.cur_index = start_index;                         \
            cui_imgview_init_source(cui_id, IMGVIEW_SRC_FILELIST, &src_data);   \
        }while(0);
        
#endif  /*__MMI_IMAGE_VIEWER_EX__*/

#endif  /* __MMI_IMAGE_VIEWER__ */

#endif /* CUI_IMAGEVIEWCUI_GPROT_H */ 
