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
 *  ImgViewCui.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Internal header of image view CUI.
 *
 * Author:
 * -------
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
 ****************************************************************************/

#ifndef _IMG_VIEW_CUI_H_
#define _IMG_VIEW_CUI_H_

#include "gdi_const.h"
#include "gdi_datatype.h"
#include "SensorSrvGport.h"             /* motion sensor */
#include "MediaAppPanel.h"
#include "MediaAppFrame.h"
#include "ImgViewerConfig.h"
#include "ImageviewCuiGprot.h"
#include "ImgViewerCacheGProt.h"
//Image Viewer DCM header file
#if defined (__DCM_WITH_COMPRESSION_MMI_AP__) && defined(__MTK_TARGET__)
#include "MMI_ap_dcm_config.h"
#endif

#define IV_API              extern      /* imageviewer CUI API functions */
#define IV_SYS_CALLBACK     extern      /* external functions used as system callback */
#define IV_MOD_API          extern      /* functions internal the imageview module */

#define CUI_IV_INIT_DISP_CAP    (CUI_IMGVIEW_DISP_LSK_DEF)
/****************************************************************************
 *  KEY MAP TABLE
 ****************************************************************************/
#define  CUI_IV_KEY_ZOOMIN     KEY_6
#define  CUI_IV_KEY_ZOOMOUT    KEY_4
#define  CUI_IV_KEY_CWR        KEY_3
#define  CUI_IV_KEY_CCWR       KEY_1
#define  CUI_IV_KEY_FZOOM      KEY_5

/* Repeat key interval */
#define MMI_IV_RKEY_START_INTERVAL  500
#define MMI_IV_RKEY_INTERVAL        250

/****************************************************************************
 *  Data structure and API of module internal
 ****************************************************************************/
typedef enum
{
    IV_SCRN_STAT_INIT = 0,
    IV_SCRN_PRE_ACTIVE, /* Popup before active(enter main screen) */
    IV_SCRN_STAT_ACTIVE,
    IV_SCRN_STAT_PLAY,
    IV_SCRN_STAT_SWITCHING,
    IV_SCRN_STAT_INACTIVE
} cui_iv_scrn_stat;

#define __MMI_IVF_IMGADP__
#ifdef __MMI_IVF_IMGADP__
#define CUI_IV_IMGADP_IMG_COUNT          (2)

#define CUI_IV_IMGADP_FLAG                  (0x000F)
#define CUI_IV_IMGADP_FLAG_ANIM             (0x0001)
#ifdef __MMI_IVF_ANIM_SUPPORT__
#define CUI_IV_IMGADP_FLAG_IS_ANIM(pImg)    ((pImg)->flag & CUI_IV_IMGADP_FLAG_ANIM)
#else
#define CUI_IV_IMGADP_FLAG_IS_ANIM(pImg)    (0)
#endif

#define CUI_IV_IMGADP_EVENT                 (0x00FF)
#define CUI_IV_IMGADP_EVENT_GET(s)          ((s) & CUI_IV_IMGADP_EVENT)
#define CUI_IV_IMGADP_EVENT_NONE            (0x0000)
#define CUI_IV_IMGADP_EVENT_DECODING        (0x0001)
#define CUI_IV_IMGADP_EVENT_OK              (0x0001 << 1)
#define CUI_IV_IMGADP_EVENT_ERR             (0x0001 << 2)
#define CUI_IV_IMGADP_EVENT_FINISH          (0x0001 << 3)

#define CUI_IV_IMGADP_IMG_VALID(pImg)       ((pImg) && (CUI_IV_IMGADP_IMG_STATE_EXIT != (pImg)->state))

typedef enum
{
    CUI_IV_IMGADP_IMG_STATE_EXIT            =(0x0000),
    CUI_IV_IMGADP_IMG_STATE_DECODING        =((0x0100 << 0) | CUI_IV_IMGADP_EVENT_DECODING),
    CUI_IV_IMGADP_IMG_STATE_PREVIEW         =((0x0100 << 1) | CUI_IV_IMGADP_EVENT_OK),
    CUI_IV_IMGADP_IMG_STATE_PLAY            =((0x0100 << 2) | CUI_IV_IMGADP_EVENT_OK),
    CUI_IV_IMGADP_IMG_STATE_ERR             =((0x0100 << 3) | CUI_IV_IMGADP_EVENT_ERR),
    CUI_IV_IMGADP_IMG_STATE_PAUSE           =((0x0100 << 4) | CUI_IV_IMGADP_EVENT_NONE),
    CUI_IV_IMGADP_IMG_STATE_FINISH          =((0x0100 << 5) | CUI_IV_IMGADP_EVENT_FINISH)
}cui_iv_imgadp_img_state_enum;

struct cui_iv_imgadp_img_struct_tag;
typedef void (*cui_iv_imgadp_callback)(struct cui_iv_imgadp_img_struct_tag *pImg, U32 evt, void *userdata);

typedef struct cui_iv_imgadp_img_struct_tag
{
    cui_iv_imgadp_img_state_enum    state;
    U16                             flag;
    GDI_HANDLE                      gdiHdl;
#ifdef __MMI_IVF_ANIM_SUPPORT__
    GDI_HANDLE                      animHdl;
#endif
    GDI_HANDLE                      lyr;
    GDI_HANDLE                      tempLyr;
    U32                             index;
    S32                             x, y, w, h;

    cui_iv_imgadp_callback          callback;
    void                            *userData;
}cui_iv_imgadp_img_struct;

typedef struct
{
    cui_iv_imgadp_img_struct    imgList[CUI_IV_IMGADP_IMG_COUNT];
}cui_iv_imgadp_struct;

#endif /* __MMI_IVF_IMGADP__ */

typedef enum
{
    IV_IMG_STAT_INIT = 0,
    IV_IMG_STAT_ERR,
    IV_IMG_STAT_LOADING,
    IV_IMG_STAT_DECODING,
    IV_IMG_STAT_OK
} cui_iv_img_stat;

typedef enum
{
    IV_CACHE_STAT_INIT = 0,
    IV_CACHE_DECODING,
    IV_CACHE_OK
} cui_iv_cache_stat;

typedef struct
{
    U16 x;
    U16 y;
#ifdef __MMI_FTE_SUPPORT__
    U16 w;
    U16 h;
#endif
    U16 id;
} iv_icon_t;

typedef struct
{
    U16 h;
    U32 icon_count;
    const iv_icon_t *picons;
} iv_panel_t;

/*
 * image information which will be computed based base info.
 * these info need not reserved after screen exit.
 */
typedef enum
{
    IV_RESIZER_LOW = 0,
    IV_RESIZER_HIGH,
}cui_iv_resizer_mode;

typedef struct
{
    cui_iv_img_stat             stat;
    U16                         is_anim;
    U16                         type;
    cui_iv_imgadp_img_struct    *pImg;
    S32                         cur_h, cur_w;   /* fit screen size */
    S32                         org_h, org_w;   /* origin size */
    S32                         draw_x, draw_y; /* position of image on layer */
#ifdef __DRM_SUPPORT__
    S32                         err_code;
#endif

#ifdef __MMI_IVF_ZOOM__
    U16                         max_zoom_factor;
    S32                         cur_img_w, cur_img_h;
    S32                         fit_w, fit_h;
    S32                         max_img_w, max_img_h;
    cui_iv_resizer_mode         resizer_mode;
#endif /* __MMI_IVF_ZOOM__ */

} cui_iv_img_extinfo;

/*
 * image info which will be reserved after screen exit.
 */
typedef struct
{
#ifdef __MMI_IVF_ZOOM__
    S32 wnd_x, wnd_y;   /* positions visible area in enlarged image */
    U16 zoom_factor;    /* zoom_factor = current_size / fit_lcd_size * 10 */
#endif /* __MMI_IVF_ZOOM__ */ 
    U8 img_orient;      /* image rotate angle, GDI_LAYER_ROTATE_x */

} cui_iv_img_baseinfo;

#ifdef __MMI_IVF_SLIDE__

typedef struct
{
    S32                         flag;
    gdi_handle                  h_layer[2];  /* 0: current, 1: decode */
    S32                         cur_index;          /* index of current show image, for recoverring from interrupt of stop */
    cui_iv_imgadp_img_struct    *pCurrImg;
} cui_iv_slide_data_t;

#endif /* __MMI_IVF_SLIDE__ */ 

typedef void (*async_cb_t) (void *usrdata, S32 result);

#ifdef __MMI_IVF_SWITCH_EFFECT__
typedef void (*cui_iv_se_complete_cb)(void *usrdata, U32 index, U32 newDispCap);
typedef struct
{
    GDI_HANDLE displayLyr;
    GDI_HANDLE switchLyr;

    S32 currFrameIdx;
    U32 imgIdx;
    S32 effectIdx;
    S32 flag;
    S32 seParam;

    cui_iv_se_complete_cb   completeFunc;
    void                    *completeUserData;
} cui_iv_se_data;
#endif /* __MMI_IVF_SWITCH_EFFECT__ */ 

/* Values of cui_iv_scrndata.flag */
#define IV_FLAG_KEY_DOWN            0x1
#define IV_IS_KEY_DOWN(flag)        ((flag)&IV_FLAG_KEY_DOWN)

#define IV_FLAG_ZOOMIN              (0x1<<1)
#define IV_FLAG_ZOOMOUT             (0x1<<2)

#define IV_FLAG_NOT_SWITCH_NEXT     (0x1<<3)    /* the two flag are set at pen down and referenced at move end. */
#define IV_FLAG_NOT_SWITCH_PREV     (0x1<<4)

#define GET_SCRNDATA_FROM_SLIDE(pslide) (cui_iv_scrndata*)(((U32)pslide)- (U32)(&((cui_iv_scrndata*)0)->slide_data))
#define GET_CUI_FROM_SCRNDATA(pscrn)    (cui_iv_cntx*)(((U32)pscrn)- (U32)(&((cui_iv_cntx*)0)->scrn_data))

typedef enum
{
#if (IV_CACHE_COUNT_IN_MED != 0)
    IV_CACHE_SRC_TYPE_MED,
#endif 
#if (IV_CACHE_COUNT_IN_SCR != 0)
    IV_CACHE_SRC_TYPE_SCR,
#endif 
    IV_CACHE_SRC_TYPE_COUNT
} cui_iv_small_location_enum;

typedef enum
{
    IV_PEN_STAT_INIT = 0,
    IV_PEN_STAT_DOWN1,
    IV_PEN_STAT_DOWN2,
    IV_PEN_STAT_WAIT_DOUBLE,
    IV_PEN_STAT_MOVE
} cui_iv_pen_stat_t;

/*
 * Data Which valid when screen is active.
 * The data will be initialized when enter screen.
 */
typedef struct
{
    U32 flag;

    gdi_handle h_disp_layer;
    gdi_handle h_cache_layer;   /* for animation and other transfer effect */

    /* load file data */
    void *load_file_usrdata;
    async_cb_t load_file_complete_cb;

    U16 repeat_key; /* Record the key code when emulate repeat key */

    cui_iv_img_extinfo cur_img_info;

    cui_iv_imgadp_struct imgAdp;

#ifdef __MMI_IVF_SLIDE__
    cui_iv_slide_data_t slide_data;
#endif 

#ifdef __MMI_IVF_SWITCH_EFFECT__
    cui_iv_se_data seData;
#endif 

#ifdef __MMI_IVF_OSD__
    med_panel_handle h_title_panel;
    med_panel_handle h_op_panel;
    mapp_frame_t *pframe;
    const iv_panel_t *p_act_skin;
    med_panel_item_t *p_items;

    U8 *p_scrn_mem;
    U32 alloc_scrn_mem_size;    /*size of screen memory has been allocated */

    S32 title_w;
    gdi_handle h_panel_layer;
    gdi_handle h_panel_bg_layer;
    gdi_handle h_title_layer;
#endif /* __MMI_IVF_OSD__ */ 

#ifdef __MMI_TOUCH_SCREEN__
    cui_iv_pen_stat_t pen_stat;
#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __MMI_IVF_ZOOM__
    gdi_handle h_large_cache_layer;
    U8 *p_large_cache_mem;
    S32                         cache_w, cache_h;
    gdi_handle                  h_large_dec;
    cui_iv_cache_stat           cache_stat;
    S32                         cache_index;
    cui_iv_resizer_mode         resizer_mode;
#endif /* __MMI_IVF_ZOOM__ */ 

    PU8 scrMemPtr;
    PU8 medMemPtr;

#ifdef __MMI_IVF_CACHE__
    MMI_IVC_HANDLE decHdl;
    PU8 cacheBufPtr[IV_CACHE_SRC_TYPE_COUNT];
    S32 cacheBufSize[IV_CACHE_SRC_TYPE_COUNT];
#endif /* __MMI_IVF_CACHE__ */ 

#ifdef __MMI_IVF_MOTION__
    SRV_SENSOR_HANDLE motionHld;
#endif
} cui_iv_scrndata;

/*
 * All the data of the structure will reserved after screen exit.
 */
typedef struct
{
    mmi_id cui_gid; /* cui group id */
    mmi_id wait_scrn_id; /* cui group id */
    U16 app_id;
    U32 disp_cap;
    cui_imgview_src_mode src_mode;
    SRV_FMGR_FILELIST_HANDLE h_list;
    U32 count;

    cui_iv_scrn_stat scrn_stat;

    WCHAR file_name[SRV_FMGR_PATH_BUFFER_SIZE >> 1];    /* buffer for file name. */
    const WCHAR *ptitle;
    U32 index;
    cui_iv_img_baseinfo img_base_info;
    cui_iv_scrndata scrn_data;
} cui_iv_cntx;

/*****************************************************************************
 * FUNCTION
 *  cui_imageview_create_mscrn
 * DESCRIPTION
 *  Create main screen. First Entry.
 * PARAMETERS
 *  pcui:    [IN]  context of CUI.
 * RETURNS
 *  void
 *****************************************************************************/
IV_MOD_API void cui_iv_create_mscrn(cui_iv_cntx *pcui);

/*****************************************************************************
 * FUNCTION
 *  cui_iv_get_filename
 * DESCRIPTION
 *  Get filename of index.
 * PARAMETERS
 *  pcui:    [IN]  context of CUI.
 *  index:   [IN]  index of the file.
 *  pbuf:    [IN]  context of CUI.
 *  size:    [IN]  size of buffer.
 * RETURNS
 *  0 -- success
 *  see srv_fmgr_filelist_error_enum
 *****************************************************************************/
IV_MOD_API S32 cui_iv_get_filename(
                cui_iv_cntx *pcui,
                U32 index,
                WCHAR *filepath,
                mmi_proc_func loadProc,
                void *userData);
IV_MOD_API void cui_iv_load_filename(cui_iv_cntx *pcui, U32 index, void *usrdata, async_cb_t complete);
IV_MOD_API void cui_iv_cancel_load_file(void);

#if defined(__MMI_IVF_CACHE_DB__)
IV_MOD_API S32 cui_iv_get_folder_path(cui_iv_cntx *pcui, WCHAR *folderPath);
#endif 
IV_MOD_API S32 cui_iv_close(cui_iv_cntx *pcui);
IV_MOD_API void cui_iv_restore_file_list(cui_iv_cntx *pcui);
IV_MOD_API S32 cui_iv_init_file_list(cui_iv_cntx *pcui);

#ifdef __MMI_IVF_OPTION__

IV_MOD_API mmi_ret cui_iv_menu_proc(mmi_event_struct *evt);

#endif /* __MMI_IVF_OPTION__ */ 

/****************************************************************************
 *  Media Common APIs
 ****************************************************************************/

/****************************************************************************
 *  Memory config
 ****************************************************************************/
#define MMI_IMGVIEW_CUI_BASE_MEM_SIZE   (sizeof(cui_iv_cntx))



extern const iv_panel_t iv_panel_0;
extern const iv_panel_t iv_panel_270;


#endif /* _IMG_VIEW_CUI_H_ */ 

